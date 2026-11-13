// Decompiled by Ghidra 12.2
// Program: aw882xx_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// aw882xx_hw_reset @ 0010436c size=180
// signature: undefined aw882xx_hw_reset(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

undefined8 aw882xx_hw_reset(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = (*(long **)(param_1 + 0x48))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x48);
  }
  _printk(&DAT_00120075,lVar2,"aw882xx_hw_reset");
  if (*(uint *)(param_1 + 0x20) < 0x200) {
    uVar1 = gpio_to_desc();
    gpiod_set_raw_value_cansleep(uVar1,0);
    __const_udelay(0x418958);
    uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x20));
    gpiod_set_raw_value_cansleep(uVar1,1);
    __const_udelay(0x8312b0);
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x48))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x48);
    }
    _printk(&DAT_001236e0,lVar2,"aw882xx_hw_reset");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_i2c_probe @ 00104424 size=2340
// signature: undefined aw882xx_i2c_probe(void)
// callers: []
//------------------------------------------------------------

int aw882xx_i2c_probe(long param_1)

{
  long *plVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined1 uVar8;
  code *pcVar9;
  long *plVar10;
  undefined4 uVar11;
  long lVar12;
  undefined8 local_58;
  undefined4 local_50;
  undefined4 local_4c;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  plVar1 = (long *)(param_1 + 0x20);
  lVar12 = *(long *)(param_1 + 0x308);
  _printk(&DAT_0011ed49,"aw882xx_i2c_probe",*(undefined2 *)(param_1 + 2));
  pcVar9 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar9 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104494);
    (*pcVar9)();
  }
  uVar3 = (*pcVar9)();
  if ((uVar3 & 1) == 0) {
    lVar12 = *(long *)(param_1 + 0x90);
    if (lVar12 == 0) {
      lVar12 = *plVar1;
    }
    _printk(&DAT_00121e6e,lVar12,"aw882xx_i2c_probe");
    iVar2 = -5;
    goto LAB_0010455c;
  }
  lVar4 = devm_kmalloc(plVar1,0x2c8,0xdc0);
  if (lVar4 != 0) {
    *(long *)(lVar4 + 0x40) = param_1;
    *(long **)(lVar4 + 0x48) = plVar1;
    *(undefined2 *)(lVar4 + 0x28) = 0;
    *(undefined8 *)(lVar4 + 0x30) = 0;
    *(undefined ***)(lVar4 + 0x38) = &aw_componet_codec_ops;
    *(undefined2 *)(lVar4 + 0x13) = 0x101;
    *(undefined8 *)(lVar4 + 0x70) = 0;
    __mutex_init(lVar4 + 0x298,"&aw882xx->lock",&aw882xx_malloc_init___key);
    lVar5 = devm_kmalloc(plVar1,0x518,0xdc0);
    *(long *)(lVar4 + 0x68) = lVar5;
    if (lVar5 != 0) {
      *(long **)(lVar5 + 0x78) = plVar1;
      *(long *)(lVar5 + 0x80) = param_1;
      *(long *)(param_1 + 0xb8) = lVar4;
      *(code **)(lVar5 + 0x4b0) = aw882xx_get_version;
      local_50 = 0;
      local_58 = 0;
      *(code **)(lVar5 + 0x4b8) = aw882xx_get_dev_num;
      *(code **)(lVar5 + 0x4c8) = aw882xx_i2c_read;
      *(code **)(lVar5 + 0x4c0) = aw882xx_i2c_write;
      *(code **)(lVar5 + 0x4d0) = aw882xx_i2c_write_bits;
      if (lVar12 == 0) {
        lVar12 = *(long *)(param_1 + 0x90);
        *(undefined8 *)(lVar4 + 0x20) = 0xffffffffffffffff;
        if (lVar12 == 0) {
          lVar12 = *plVar1;
        }
        _printk(&DAT_001203f4,lVar12,"aw882xx_i2c_probe");
        iVar2 = -0x16;
        goto LAB_0010455c;
      }
      iVar2 = of_get_named_gpio_flags(lVar12,"reset-gpio",0,0);
      plVar10 = *(long **)(lVar4 + 0x48);
      *(int *)(lVar4 + 0x20) = iVar2;
      lVar5 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        puVar6 = &DAT_00122c90;
      }
      else {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        puVar6 = &DAT_00121bc2;
      }
      _printk(puVar6,lVar5,"aw882xx_parse_gpio_dt");
      iVar2 = of_get_named_gpio_flags(lVar12,"irq-gpio",0,0);
      plVar10 = *(long **)(lVar4 + 0x48);
      *(int *)(lVar4 + 0x24) = iVar2;
      lVar5 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        puVar6 = &DAT_00121228;
      }
      else {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        puVar6 = &DAT_0011d9c3;
      }
      _printk(puVar6,lVar5,"aw882xx_parse_gpio_dt");
      iVar2 = of_property_read_variable_u32_array(lVar12,"dc-flag",&local_50,1,0);
      if (iVar2 < 0) {
        local_50 = 0;
        lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
        if (lVar5 == 0) {
          lVar5 = **(long **)(lVar4 + 0x48);
        }
        _printk(&DAT_001217c3,lVar5,"aw882xx_parse_dt");
      }
      else {
        lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
        if (lVar5 == 0) {
          lVar5 = **(long **)(lVar4 + 0x48);
        }
        _printk(&DAT_001211e5,lVar5,"aw882xx_parse_dt",local_50);
      }
      *(char *)(lVar4 + 0x12) = (char)local_50;
      iVar2 = of_property_read_variable_u32_array(lVar12,"sync-flag",(long)&local_58 + 4,1,0);
      plVar10 = *(long **)(lVar4 + 0x48);
      lVar5 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        _printk(&DAT_00121b6c,lVar5,"aw882xx_parse_dt");
        local_58 = local_58 & 0xffffffff;
        uVar8 = 0;
      }
      else {
        if (lVar5 == 0) {
          lVar5 = *plVar10;
        }
        _printk(&DAT_0011dd2e,lVar5,"aw882xx_parse_dt",local_58._4_4_);
        uVar8 = local_58._4_1_;
      }
      *(undefined1 *)(lVar4 + 0x10) = uVar8;
      iVar2 = of_property_read_variable_u32_array(lVar12,"mute-sync",&local_58,1,0);
      plVar10 = *(long **)(lVar4 + 0x48);
      lVar12 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_001205ec,lVar12,"aw882xx_parse_dt");
        uVar8 = 0;
        local_58 = local_58 & 0xffffffff00000000;
      }
      else {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_00121205,lVar12,"aw882xx_parse_dt",local_58 & 0xffffffff);
        uVar8 = (undefined1)local_58;
      }
      *(undefined1 *)(lVar4 + 0x11) = uVar8;
      local_4c = 0;
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*(long *)(lVar4 + 0x48) + 0x2e8),"rename-flag",&local_4c,1,
                         0);
      plVar10 = *(long **)(lVar4 + 0x48);
      lVar12 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_00120d6e,lVar12,"aw882xx_parse_rename_flag_dt");
      }
      else {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_0011fda5,lVar12,"aw882xx_parse_rename_flag_dt",local_4c);
      }
      *(undefined4 *)(lVar4 + 0x18) = local_4c;
      local_4c = 0;
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*(long *)(lVar4 + 0x48) + 0x2e8),"sync-load",&local_4c,1,0)
      ;
      plVar10 = *(long **)(lVar4 + 0x48);
      lVar12 = plVar10[0xe];
      if (iVar2 < 0) {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_0011f473,lVar12,"aw882xx_parse_sync_load_dt");
        uVar11 = 0;
      }
      else {
        if (lVar12 == 0) {
          lVar12 = *plVar10;
        }
        _printk(&DAT_00121251,lVar12,"aw882xx_parse_sync_load_dt",local_4c);
        uVar11 = local_4c;
      }
      *(char *)(lVar4 + 0x1c) = (char)uVar11;
      if ((*(uint *)(lVar4 + 0x20) < 0x200) &&
         (iVar2 = devm_gpio_request_one
                            (*(undefined8 *)(lVar4 + 0x48),*(uint *)(lVar4 + 0x20),0,"aw882xx_rst"),
         iVar2 != 0)) {
        lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
        if (lVar12 == 0) {
          lVar12 = **(long **)(lVar4 + 0x48);
        }
        puVar6 = &DAT_0011ed68;
LAB_00104b78:
        pcVar7 = "aw882xx_gpio_request";
LAB_00104b80:
        _printk(puVar6,lVar12,pcVar7);
LAB_00104bd8:
        if (-1 < iVar2) goto LAB_0010455c;
      }
      else {
        if ((*(uint *)(lVar4 + 0x24) < 0x200) &&
           (iVar2 = devm_gpio_request_one
                              (*(undefined8 *)(lVar4 + 0x48),*(uint *)(lVar4 + 0x24),1,"aw882xx_int"
                              ), iVar2 != 0)) {
          lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
          if (lVar12 == 0) {
            lVar12 = **(long **)(lVar4 + 0x48);
          }
          puVar6 = &DAT_0011d2ae;
          goto LAB_00104b78;
        }
        aw882xx_hw_reset(lVar4);
        local_4c = 0;
        iVar2 = aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),0,&local_4c);
        uVar11 = local_4c;
        if (-1 < iVar2) {
          iVar2 = aw882xx_chipid_auth(local_4c);
          if (iVar2 != 0) {
            lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(lVar4 + 0x48);
            }
            _printk(&DAT_001228ff,lVar12,"aw882xx_read_chipid",uVar11);
            msleep(5);
            iVar2 = aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),0,&local_4c);
            uVar11 = local_4c;
            if (iVar2 < 0) goto LAB_00104aec;
            iVar2 = aw882xx_chipid_auth(local_4c);
            if (iVar2 == 0) goto LAB_00104b98;
            lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(lVar4 + 0x48);
            }
            _printk(&DAT_001228ff,lVar12,"aw882xx_read_chipid",uVar11);
            msleep(5);
            iVar2 = aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),0,&local_4c);
            uVar11 = local_4c;
            if (iVar2 < 0) goto LAB_00104aec;
            iVar2 = aw882xx_chipid_auth(local_4c);
            if (iVar2 == 0) goto LAB_00104b98;
            lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(lVar4 + 0x48);
            }
            _printk(&DAT_001228ff,lVar12,"aw882xx_read_chipid",uVar11);
            msleep(5);
            iVar2 = aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),0,&local_4c);
            uVar11 = local_4c;
            if (iVar2 < 0) goto LAB_00104aec;
            iVar2 = aw882xx_chipid_auth(local_4c);
            if (iVar2 == 0) goto LAB_00104b98;
            lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(lVar4 + 0x48);
            }
            _printk(&DAT_001228ff,lVar12,"aw882xx_read_chipid",uVar11);
            msleep(5);
            iVar2 = aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),0,&local_4c);
            uVar11 = local_4c;
            if (iVar2 < 0) goto LAB_00104aec;
            iVar2 = aw882xx_chipid_auth(local_4c);
            if (iVar2 == 0) goto LAB_00104b98;
            lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(lVar4 + 0x48);
            }
            _printk(&DAT_001228ff,lVar12,"aw882xx_read_chipid",uVar11);
            msleep(5);
            iVar2 = -0x16;
            lVar12 = *(long *)(param_1 + 0x90);
            goto joined_r0x00104d3c;
          }
LAB_00104b98:
          lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
          if (lVar12 == 0) {
            lVar12 = **(long **)(lVar4 + 0x48);
          }
          _printk(&DAT_001228d6,lVar12,"aw882xx_read_chipid",uVar11);
          *(undefined4 *)(*(long *)(lVar4 + 0x68) + 4) = uVar11;
          iVar2 = aw882xx_init(*(undefined8 *)(lVar4 + 0x68));
          if (iVar2 == 0) {
            aw882xx_interrupt_init(lVar4);
            iVar2 = aw_componet_codec_register(lVar4);
            if (iVar2 == 0) {
              iVar2 = sysfs_create_group(plVar1,aw882xx_attribute_group);
              if (-1 < iVar2) {
                *(long *)(param_1 + 0xb8) = lVar4;
                *(undefined1 *)(lVar4 + 0x50) = 0;
                *(undefined8 *)(lVar4 + 0x60) = 0;
                *(undefined8 *)(lVar4 + 0x54) = 0xff00000000;
                mutex_lock(g_aw882xx_lock);
                g_aw882xx_dev_cnt = g_aw882xx_dev_cnt + 1;
                mutex_unlock(g_aw882xx_lock);
                lVar12 = *(long *)(param_1 + 0x90);
                if (lVar12 == 0) {
                  lVar12 = *plVar1;
                }
                _printk(&DAT_00120d45,lVar12,"aw882xx_i2c_probe",g_aw882xx_dev_cnt);
                goto LAB_0010455c;
              }
              lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
              if (lVar12 == 0) {
                lVar12 = **(long **)(lVar4 + 0x48);
              }
              _printk(&DAT_0012215c,lVar12,"aw882xx_i2c_probe");
              if (*(int *)(PTR_snd_soc_unregister_component_00124770 + -4) != -0x6b11820d) {
                    /* WARNING: Does not return */
                pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104c74);
                (*pcVar9)();
              }
              (*(code *)PTR_snd_soc_unregister_component_00124770)(plVar1);
              goto LAB_00104bdc;
            }
            lVar12 = *(long *)(param_1 + 0x90);
            if (lVar12 == 0) {
              lVar12 = *plVar1;
            }
            puVar6 = &DAT_0011fb1a;
            pcVar7 = "aw882xx_i2c_probe";
            goto LAB_00104b80;
          }
          goto LAB_00104bd8;
        }
LAB_00104aec:
        lVar12 = (*(long **)(lVar4 + 0x48))[0xe];
        if (lVar12 == 0) {
          lVar12 = **(long **)(lVar4 + 0x48);
        }
        _printk(&DAT_0011e91c,lVar12,"aw882xx_read_chipid");
        iVar2 = -5;
        lVar12 = *(long *)(param_1 + 0x90);
joined_r0x00104d3c:
        if (lVar12 == 0) {
          lVar12 = *plVar1;
        }
        _printk(&DAT_0011dcf1,lVar12,"aw882xx_i2c_probe",iVar2);
      }
LAB_00104bdc:
      if (*(uint *)(lVar4 + 0x20) < 0x200) {
        gpio_free();
      }
      if (*(uint *)(lVar4 + 0x24) < 0x200) {
        gpio_free();
      }
      goto LAB_0010455c;
    }
    devm_kfree(plVar1,lVar4);
  }
  lVar12 = *(long *)(param_1 + 0x90);
  if (lVar12 == 0) {
    lVar12 = *plVar1;
  }
  _printk(&DAT_0011ce54,lVar12,"aw882xx_i2c_probe");
  iVar2 = -0xc;
LAB_0010455c:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_i2c_remove @ 00104d4c size=272
// signature: undefined aw882xx_i2c_remove(void)
// callers: []
//------------------------------------------------------------

void aw882xx_i2c_remove(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xb8);
  if (lVar5 != 0) {
    lVar3 = (*(long **)(lVar5 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(lVar5 + 0x48);
    }
    _printk(&DAT_00120075,lVar3,"aw882xx_i2c_remove");
    gpio_to_desc(*(undefined4 *)(lVar5 + 0x24));
    iVar1 = gpiod_to_irq();
    if (iVar1 != 0) {
      gpio_to_desc(*(undefined4 *)(lVar5 + 0x24));
      uVar2 = gpiod_to_irq();
      devm_free_irq(param_1 + 0x20,uVar2,lVar5);
    }
    sysfs_remove_group(param_1 + 0x20,aw882xx_attribute_group);
    aw882xx_dev_remove(*(undefined8 *)(lVar5 + 0x68));
    pcVar4 = *(code **)(*(long *)(lVar5 + 0x38) + 0x18);
    if (*(int *)(pcVar4 + -4) != -0x6b11820d) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104e14);
      (*pcVar4)();
    }
    (*pcVar4)(param_1 + 0x20);
    mutex_lock(g_aw882xx_lock);
    g_aw882xx_dev_cnt = g_aw882xx_dev_cnt + -1;
    if ((g_aw882xx_dev_cnt == 0) && (g_awinic_cfg != 0)) {
      vfree();
      g_awinic_cfg = 0;
    }
    mutex_unlock(g_aw882xx_lock);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_i2c_shutdown @ 00104e60 size=128
// signature: undefined aw882xx_i2c_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw882xx_i2c_shutdown(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0xb8);
  if (lVar2 == 0) {
    _printk(&DAT_0011e949,"aw882xx_i2c_shutdown");
  }
  else {
    lVar1 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(lVar2 + 0x48);
    }
    _printk(&DAT_00120075,lVar1,"aw882xx_i2c_shutdown");
    mutex_lock(lVar2 + 0x298);
    aw882xx_device_stop(*(undefined8 *)(lVar2 + 0x68));
    mutex_unlock(lVar2 + 0x298);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_interrupt_init @ 00104ee0 size=216
// signature: undefined aw882xx_interrupt_init(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

void aw882xx_interrupt_init(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  
  plVar3 = *(long **)(param_1 + 0x48);
  if (*(uint *)(param_1 + 0x24) < 0x200) {
    gpio_to_desc();
    uVar1 = gpiod_to_irq();
    iVar2 = devm_request_threaded_irq(plVar3,uVar1,0,aw882xx_irq,0x2002,"aw882xx",param_1);
    if (iVar2 != 0) {
      lVar4 = (*(long **)(param_1 + 0x48))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x48);
      }
      gpio_to_desc(*(undefined4 *)(param_1 + 0x24));
      uVar1 = gpiod_to_irq();
      _printk(&DAT_00122cdc,lVar4,"aw882xx_interrupt_init",uVar1,iVar2);
    }
  }
  else {
    lVar4 = plVar3[0xe];
    if (lVar4 == 0) {
      lVar4 = *plVar3;
    }
    _printk(&DAT_00121ec5,lVar4,"aw882xx_interrupt_init");
  }
  return;
}



//------------------------------------------------------------
// aw_componet_codec_register @ 00104fb8 size=636
// signature: undefined aw_componet_codec_register(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

undefined8 aw_componet_codec_register(long param_1)

{
  int iVar1;
  undefined8 *__dest;
  undefined8 uVar2;
  long lVar3;
  code *pcVar4;
  
  __dest = (undefined8 *)devm_kmalloc(*(undefined8 *)(param_1 + 0x48),0xe0,0xdc0);
  if (__dest == (undefined8 *)0x0) {
    return 0xfffffff4;
  }
  memcpy(__dest,&aw882xx_dai,0xe0);
  if (*(int *)(param_1 + 0x18) == 1) {
    iVar1 = aw882xx_append_channel_suffix("%s-%d",__dest,param_1);
    if (((iVar1 < 0) ||
        (iVar1 = aw882xx_append_channel_suffix("%s_%d",__dest + 0x15,param_1), iVar1 < 0)) ||
       (iVar1 = aw882xx_append_channel_suffix("%s_%d",__dest + 0x10,param_1), iVar1 < 0))
    goto LAB_001050e4;
    dev_set_name(*(undefined8 *)(param_1 + 0x48),"%s_%d","aw882xx_smartpa",
                 *(undefined4 *)(*(long *)(param_1 + 0x68) + 0x3c));
    lVar3 = (*(long **)(param_1 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x48);
    }
    _printk(&DAT_0011e968,lVar3,"aw882xx_dai_drv_append_suffix",lVar3);
  }
  else {
    iVar1 = aw882xx_append_i2c_suffix("%s-%d-%x",__dest,param_1);
    if (((iVar1 < 0) ||
        (iVar1 = aw882xx_append_i2c_suffix("%s_%d_%x",__dest + 0x15,param_1), iVar1 < 0)) ||
       (iVar1 = aw882xx_append_i2c_suffix("%s_%d_%x",__dest + 0x10,param_1), iVar1 < 0))
    goto LAB_001050e4;
  }
  lVar3 = (*(long **)(param_1 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x48);
  }
  _printk(&DAT_0011cee6,lVar3,"aw882xx_dai_drv_append_suffix",*__dest);
  lVar3 = (*(long **)(param_1 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x48);
  }
  _printk(&DAT_001221b9,lVar3,"aw882xx_dai_drv_append_suffix",__dest[0x15]);
  lVar3 = (*(long **)(param_1 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x48);
  }
  _printk(&DAT_0011d63a,lVar3,"aw882xx_dai_drv_append_suffix",__dest[0x10]);
LAB_001050e4:
  pcVar4 = *(code **)(*(long *)(param_1 + 0x38) + 0x20);
  if (*(int *)(pcVar4 + -4) != -0x7a787615) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x105118);
    (*pcVar4)();
  }
  iVar1 = (*pcVar4)(*(undefined8 *)(param_1 + 0x48),soc_codec_dev_aw882xx,__dest,1);
  if (iVar1 < 0) {
    lVar3 = (*(long **)(param_1 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x48);
    }
    _printk(&DAT_00122510,lVar3,"aw_componet_codec_register",iVar1);
    uVar2 = 0xffffffea;
  }
  else {
    if (*(int *)(param_1 + 0x18) == 1) {
      dev_set_name(*(undefined8 *)(param_1 + 0x48),"%d-00%x",
                   *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x40) + 0x18) + 0x408),
                   *(undefined2 *)(*(long *)(param_1 + 0x40) + 2));
      lVar3 = (*(long **)(param_1 + 0x48))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(param_1 + 0x48);
      }
      _printk(&DAT_0011e1e9,lVar3,"aw_componet_codec_register",lVar3);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw882xx_get_version @ 00105238 size=48
// signature: undefined aw882xx_get_version(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_version(undefined8 *param_1,uint param_2)

{
  if (param_2 < 9) {
    return 0xfffffff4;
  }
  *param_1 = 0x312e322e302e3276;
  return 8;
}



//------------------------------------------------------------
// aw882xx_get_dev_num @ 0010526c size=12
// signature: undefined aw882xx_get_dev_num(void)
// callers: []
//------------------------------------------------------------

undefined4 aw882xx_get_dev_num(void)

{
  return g_aw882xx_dev_cnt;
}



//------------------------------------------------------------
// aw882xx_i2c_read @ 0010527c size=428
// signature: undefined aw882xx_i2c_read(void)
// callers: [aw882xx_i2c_probe, aw882xx_interrupt_work, rw_show, aw882xx_i2c_write_bits, reg_show]
//------------------------------------------------------------

int aw882xx_i2c_read(long param_1,undefined1 param_2,uint *param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined1 local_90 [4];
  ushort local_8c [2];
  undefined8 local_88;
  undefined1 *puStack_80;
  undefined8 local_78;
  ushort *puStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  iVar3 = 0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_8c[0] = 0;
  do {
    local_88 = CONCAT62(0x10000,*(undefined2 *)(param_1 + 2));
    local_78 = (ulong)CONCAT42(0x20001,*(undefined2 *)(param_1 + 2));
    local_90[0] = param_2;
    puStack_80 = local_90;
    puStack_70 = local_8c;
    iVar1 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_88,2);
    if (iVar1 < 0) {
      lVar2 = *(long *)(param_1 + 0x90);
      if (lVar2 == 0) {
        lVar2 = *(long *)(param_1 + 0x20);
      }
      _printk(&DAT_0011f822,lVar2,"aw882xx_i2c_reads");
      lVar2 = *(long *)(param_1 + 0x90);
    }
    else {
      if (iVar1 == 2) {
        *param_3 = (uint)(local_8c[0] >> 8) | (local_8c[0] & 0xff00ff) << 8;
        if (g_print_dbg != 0) {
          lVar2 = *(long *)(param_1 + 0x90);
          if (lVar2 == 0) {
            lVar2 = *(long *)(param_1 + 0x20);
          }
          _printk(&DAT_001205b6,lVar2,"aw882xx_i2c_read",param_2);
        }
        iVar1 = 0;
        break;
      }
      lVar2 = *(long *)(param_1 + 0x90);
      if (lVar2 == 0) {
        lVar2 = *(long *)(param_1 + 0x20);
      }
      _printk(&DAT_001211b5,lVar2,"aw882xx_i2c_reads");
      iVar1 = -6;
      lVar2 = *(long *)(param_1 + 0x90);
    }
    if (lVar2 == 0) {
      lVar2 = *(long *)(param_1 + 0x20);
    }
    _printk(&DAT_0011fd79,lVar2,"aw882xx_i2c_read",iVar3,iVar1);
    iVar3 = iVar3 + 1;
  } while (iVar3 != 5);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_i2c_write @ 0010542c size=344
// signature: undefined aw882xx_i2c_write(void)
// callers: [rw_store, reg_store, aw882xx_i2c_write_bits]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aw882xx_i2c_write(long param_1,undefined1 param_2,uint param_3)

{
  int iVar1;
  undefined1 *puVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    puVar2 = (undefined1 *)kmalloc_trace(_snd_pcm_format_width,0xcc0,3);
    if (puVar2 == (undefined1 *)0x0) {
      iVar1 = -0xc;
      lVar3 = *(long *)(param_1 + 0x90);
    }
    else {
      *puVar2 = param_2;
      *(ushort *)(puVar2 + 1) = (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
      iVar1 = i2c_transfer_buffer_flags(param_1,puVar2,3,0);
      if (-1 < iVar1) {
        kfree(puVar2);
        if (g_print_dbg == 0) {
          return iVar1;
        }
        lVar3 = *(long *)(param_1 + 0x90);
        if (lVar3 == 0) {
          lVar3 = *(long *)(param_1 + 0x20);
        }
        _printk(&DAT_001205b6,lVar3,"aw882xx_i2c_write",param_2,param_3 & 0xffff);
        return iVar1;
      }
      lVar3 = *(long *)(param_1 + 0x90);
      if (lVar3 == 0) {
        lVar3 = *(long *)(param_1 + 0x20);
      }
      _printk(&DAT_0011f44a,lVar3,"aw882xx_i2c_writes");
      kfree(puVar2);
      lVar3 = *(long *)(param_1 + 0x90);
    }
    if (lVar3 == 0) {
      lVar3 = *(long *)(param_1 + 0x20);
    }
    _printk(&DAT_0011f41d,lVar3,"aw882xx_i2c_write",iVar4,iVar1);
    iVar4 = iVar4 + 1;
  } while (iVar4 != 5);
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_i2c_write_bits @ 00105588 size=208
// signature: undefined aw882xx_i2c_write_bits(void)
// callers: []
//------------------------------------------------------------

int aw882xx_i2c_write_bits(long param_1,ulong param_2,uint param_3,uint param_4)

{
  int iVar1;
  long lVar2;
  uint local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  iVar1 = aw882xx_i2c_read(param_1,param_2,&local_4c);
  if ((iVar1 < 0) ||
     (iVar1 = aw882xx_i2c_write(param_1,param_2 & 0xffffffff,
                                local_4c & param_3 | param_4 & (param_3 ^ 0xffffffff)), iVar1 < 0))
  {
    lVar2 = *(long *)(param_1 + 0x90);
    if (lVar2 == 0) {
      lVar2 = *(long *)(param_1 + 0x20);
    }
    _printk(&DAT_00122f5c,lVar2,"aw882xx_i2c_write_bits",iVar1);
  }
  else {
    iVar1 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_irq @ 0010565c size=144
// signature: undefined aw882xx_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_irq(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_2 == 0) {
    _printk(&DAT_0011e949,"aw882xx_irq");
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = (*(long **)(param_2 + 0x48))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_2 + 0x48);
    }
    _printk(&DAT_00120075,lVar2,"aw882xx_irq");
    aw882xx_dev_set_intmask(*(undefined8 *)(param_2 + 0x68),0);
    if (*(long *)(param_2 + 0x70) != 0) {
      queue_delayed_work_on(0x20,*(long *)(param_2 + 0x70),param_2 + 0x100,0);
    }
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_set_dai_sysclk @ 001056f0 size=128
// signature: undefined aw882xx_set_dai_sysclk(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_dai_sysclk(long param_1,undefined8 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  long lVar3;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105728);
    (*pcVar1)();
  }
  puVar2 = (undefined4 *)
           (*(code *)PTR_snd_soc_component_get_drvdata_00124760)(*(undefined8 *)(param_1 + 0x58));
  lVar3 = (*(long **)(puVar2 + 0x12))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(puVar2 + 0x12);
  }
  _printk(&DAT_00122935,lVar3,"aw882xx_set_dai_sysclk",param_3);
  *puVar2 = param_3;
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_fmt @ 00105774 size=76
// signature: undefined aw882xx_set_fmt(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_fmt(long param_1,undefined4 param_2)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(*(long *)(param_1 + 0x58) + 0x18);
  lVar1 = plVar2[0xe];
  if (lVar1 == 0) {
    lVar1 = *plVar2;
  }
  _printk(&DAT_0011e4e7,lVar1,"aw882xx_set_fmt",param_2);
  return 0;
}



//------------------------------------------------------------
// aw882xx_mute @ 001057c4 size=432
// signature: undefined aw882xx_mute(void)
// callers: []
//------------------------------------------------------------

int aw882xx_mute(long param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  long lVar5;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105804);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)(*(undefined8 *)(param_1 + 0x58));
  lVar5 = (*(long **)(lVar3 + 0x48))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(lVar3 + 0x48);
  }
  _printk(&DAT_0011dd51,lVar5,"aw882xx_mute",param_2);
  if (param_3 == 0) {
    if (param_2 != 0) {
      *(undefined4 *)(lVar3 + 8) = 0;
      cancel_delayed_work_sync(lVar3 + 0x188);
      cancel_delayed_work_sync(lVar3 + 0x78);
      mutex_lock(lVar3 + 0x298);
      g_algo_auth_st = 0;
      aw882xx_device_stop(*(undefined8 *)(lVar3 + 0x68));
      mutex_unlock(lVar3 + 0x298);
      return 0;
    }
    if (*(char *)(lVar3 + 0x28) != '\0') {
      *(undefined4 *)(lVar3 + 8) = 1;
      mutex_lock(lVar3 + 0x298);
      if (*(char *)(lVar3 + 0x11) == '\0') {
        queue_delayed_work_on(0x20,*(undefined8 *)(lVar3 + 0x70),lVar3 + 0x78,0);
      }
      else {
        aw882xx_start_pa(lVar3);
      }
      if (*(int *)(*(long *)(lVar3 + 0x68) + 0x3c) == 0) {
        iVar2 = aw882xx_spin_set_record_val();
        if (iVar2 != 0) {
          lVar5 = (*(long **)(lVar3 + 0x48))[0xe];
          if (lVar5 == 0) {
            lVar5 = **(long **)(lVar3 + 0x48);
          }
          _printk(&DAT_0012218f,lVar5,"aw882xx_mute",iVar2);
        }
      }
      else {
        iVar2 = 0;
      }
      mutex_unlock(lVar3 + 0x298);
      return iVar2;
    }
    lVar5 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar3 + 0x48);
    }
    puVar4 = &DAT_00120637;
  }
  else {
    lVar5 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar3 + 0x48);
    }
    puVar4 = &DAT_0011e20e;
  }
  _printk(puVar4,lVar5,"aw882xx_mute");
  return 0;
}



//------------------------------------------------------------
// aw882xx_startup @ 00105978 size=168
// signature: undefined aw882xx_startup(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_startup(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1059b0);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)(*(undefined8 *)(param_2 + 0x58));
  plVar4 = *(long **)(lVar2 + 0x48);
  lVar3 = plVar4[0xe];
  if (*(int *)(param_1 + 0x3c) == 0) {
    if (lVar3 == 0) {
      lVar3 = *plVar4;
    }
    _printk(&DAT_0012129c,lVar3,"aw882xx_startup");
    aw882xx_dev_init_cali_re(*(undefined8 *)(lVar2 + 0x68));
  }
  else {
    if (lVar3 == 0) {
      lVar3 = *plVar4;
    }
    _printk(&DAT_001231cd,lVar3,"aw882xx_startup");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_shutdown @ 00105a24 size=152
// signature: undefined aw882xx_shutdown(void)
// callers: []
//------------------------------------------------------------

void aw882xx_shutdown(long param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  undefined *puVar3;
  long lVar4;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105a5c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)(*(undefined8 *)(param_2 + 0x58));
  if (*(int *)(param_1 + 0x3c) == 0) {
    *(undefined4 *)(lVar2 + 4) = 0;
    lVar4 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar2 + 0x48);
    }
    puVar3 = &DAT_0011e229;
  }
  else {
    lVar4 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar2 + 0x48);
    }
    puVar3 = &DAT_0011e540;
  }
  _printk(puVar3,lVar4,"aw882xx_shutdown");
  return;
}



//------------------------------------------------------------
// aw882xx_hw_params @ 00105ac0 size=340
// signature: undefined aw882xx_hw_params(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hw_params(long param_1,long param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  long lVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105b04);
    (*pcVar3)();
  }
  lVar5 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)(*(undefined8 *)(param_3 + 0x58));
  iVar1 = *(int *)(param_1 + 0x3c);
  if (iVar1 == 1) {
    lVar8 = (*(long **)(lVar5 + 0x48))[0xe];
    if (lVar8 == 0) {
      lVar8 = **(long **)(lVar5 + 0x48);
    }
    uVar6 = *(uint *)(param_2 + 0x24);
    uVar2 = *(undefined4 *)(param_2 + 0x128);
    if (uVar6 == 0) {
      uVar6 = *(uint *)(param_2 + 0x28);
      if (uVar6 != 0) {
        uVar7 = 0x20;
        goto LAB_00105b70;
      }
      uVar7 = 0;
    }
    else {
      uVar7 = 0;
LAB_00105b70:
      uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
      uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
      uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
      uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
      uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
    }
    uVar4 = snd_pcm_format_width(uVar7);
    _printk(&DAT_0011cea0,lVar8,"aw882xx_hw_params",uVar2,uVar4);
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  if (iVar1 != 0) {
    return 0;
  }
  lVar8 = (*(long **)(lVar5 + 0x48))[0xe];
  if (lVar8 == 0) {
    lVar8 = **(long **)(lVar5 + 0x48);
  }
  uVar6 = *(uint *)(param_2 + 0x24);
  uVar2 = *(undefined4 *)(param_2 + 0x128);
  if (uVar6 == 0) {
    uVar6 = *(uint *)(param_2 + 0x28);
    if (uVar6 == 0) {
      uVar7 = 0;
      goto LAB_00105bec;
    }
    uVar7 = 0x20;
  }
  else {
    uVar7 = 0;
  }
  uVar6 = (uVar6 & 0xaaaaaaaa) >> 1 | (uVar6 & 0x55555555) << 1;
  uVar6 = (uVar6 & 0xcccccccc) >> 2 | (uVar6 & 0x33333333) << 2;
  uVar6 = (uVar6 & 0xf0f0f0f0) >> 4 | (uVar6 & 0xf0f0f0f) << 4;
  uVar6 = (uVar6 & 0xff00ff00) >> 8 | (uVar6 & 0xff00ff) << 8;
  uVar7 = (uint)LZCOUNT(uVar6 >> 0x10 | uVar6 << 0x10) | uVar7;
LAB_00105bec:
  uVar4 = snd_pcm_format_width(uVar7);
  _printk(&DAT_0012370f,lVar8,"aw882xx_hw_params",uVar2,uVar4);
  return 0;
}



//------------------------------------------------------------
// aw882xx_start_pa @ 00105c14 size=436
// signature: undefined aw882xx_start_pa(void)
// callers: [aw882xx_startup_work, aw882xx_mute, aw882xx_profile_set, aw882xx_switch_set]
//------------------------------------------------------------

void aw882xx_start_pa(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = (*(long **)(param_1 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x48);
  }
  _printk(&DAT_00120075,lVar3,"aw882xx_start_pa");
  if (*(char *)(param_1 + 0x28) == '\x01') {
    if (*(char *)(param_1 + 0x14) != '\0') {
      iVar4 = 0;
      do {
        if (**(int **)(param_1 + 0x68) != 0) {
          lVar3 = (*(long **)(param_1 + 0x48))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x48);
          }
          puVar2 = &DAT_00120dc9;
          goto LAB_00105da4;
        }
        if (*(int *)(param_1 + 8) == 0) {
          lVar3 = (*(long **)(param_1 + 0x48))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x48);
          }
          puVar2 = &DAT_00121f11;
          goto LAB_00105da4;
        }
        iVar1 = aw882xx_dev_reg_update(*(int **)(param_1 + 0x68),*(char *)(param_1 + 0x10) != '\0');
        if (iVar1 == 0) {
          iVar1 = aw882xx_device_start(*(undefined8 *)(param_1 + 0x68));
          if (iVar1 == 0) {
            if (*(char *)(param_1 + 0x12) != '\0') {
              queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + 0x70),param_1 + 0x188,0xfa);
            }
            lVar3 = (*(long **)(param_1 + 0x48))[0xe];
            if (lVar3 == 0) {
              lVar3 = **(long **)(param_1 + 0x48);
            }
            puVar2 = &DAT_00122950;
            goto LAB_00105da4;
          }
          lVar3 = (*(long **)(param_1 + 0x48))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x48);
          }
          puVar2 = &DAT_00121274;
        }
        else {
          lVar3 = (*(long **)(param_1 + 0x48))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x48);
          }
          puVar2 = &DAT_0011e503;
        }
        _printk(puVar2,lVar3,"aw882xx_start_pa",iVar4);
        iVar4 = iVar4 + 1;
        if (iVar4 == 5) {
          return;
        }
      } while( true );
    }
    lVar3 = (*(long **)(param_1 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x48);
    }
    puVar2 = &DAT_00121ee5;
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x48);
    }
    puVar2 = &DAT_0012345a;
  }
LAB_00105da4:
  _printk(puVar2,lVar3,"aw882xx_start_pa");
  return;
}



//------------------------------------------------------------
// aw882xx_append_channel_suffix @ 00105dc8 size=320
// signature: undefined aw882xx_append_channel_suffix(void)
// callers: [aw_componet_codec_register]
//------------------------------------------------------------

void aw882xx_append_channel_suffix(char *param_1,undefined8 *param_2,long param_3)

{
  size_t sVar1;
  void *__dest;
  long lVar2;
  undefined8 uVar3;
  char local_78 [64];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,param_1,*param_2,(ulong)*(uint *)(*(long *)(param_3 + 0x68) + 0x3c));
  uVar3 = *(undefined8 *)(param_3 + 0x48);
  sVar1 = strnlen(local_78,0x40);
  if (0x40 < sVar1) {
LAB_00105eec:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar1 == 0x40) {
LAB_00105ef8:
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  __dest = (void *)devm_kmalloc(uVar3,sVar1 + 1,0xdc0);
  if (__dest == (void *)0x0) {
    uVar3 = 0xfffffff4;
    *param_2 = 0;
  }
  else {
    sVar1 = strnlen(local_78,0x40);
    if (0x40 < sVar1) goto LAB_00105eec;
    if (sVar1 == 0x40) goto LAB_00105ef8;
    memcpy(__dest,local_78,sVar1);
    *param_2 = __dest;
    lVar2 = (*(long **)(param_3 + 0x48))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_3 + 0x48);
    }
    _printk(&DAT_00121c34,lVar2,"aw882xx_append_channel_suffix",__dest);
    uVar3 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_append_i2c_suffix @ 00105f08 size=328
// signature: undefined aw882xx_append_i2c_suffix(void)
// callers: [aw_componet_codec_register]
//------------------------------------------------------------

void aw882xx_append_i2c_suffix(char *param_1,undefined8 *param_2,long param_3)

{
  size_t sVar1;
  void *__dest;
  long lVar2;
  undefined8 uVar3;
  char local_78 [64];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_78[0x30] = '\0';
  local_78[0x31] = '\0';
  local_78[0x32] = '\0';
  local_78[0x33] = '\0';
  local_78[0x34] = '\0';
  local_78[0x35] = '\0';
  local_78[0x36] = '\0';
  local_78[0x37] = '\0';
  local_78[0x38] = '\0';
  local_78[0x39] = '\0';
  local_78[0x3a] = '\0';
  local_78[0x3b] = '\0';
  local_78[0x3c] = '\0';
  local_78[0x3d] = '\0';
  local_78[0x3e] = '\0';
  local_78[0x3f] = '\0';
  local_78[0x20] = '\0';
  local_78[0x21] = '\0';
  local_78[0x22] = '\0';
  local_78[0x23] = '\0';
  local_78[0x24] = '\0';
  local_78[0x25] = '\0';
  local_78[0x26] = '\0';
  local_78[0x27] = '\0';
  local_78[0x28] = '\0';
  local_78[0x29] = '\0';
  local_78[0x2a] = '\0';
  local_78[0x2b] = '\0';
  local_78[0x2c] = '\0';
  local_78[0x2d] = '\0';
  local_78[0x2e] = '\0';
  local_78[0x2f] = '\0';
  local_78[0x10] = '\0';
  local_78[0x11] = '\0';
  local_78[0x12] = '\0';
  local_78[0x13] = '\0';
  local_78[0x14] = '\0';
  local_78[0x15] = '\0';
  local_78[0x16] = '\0';
  local_78[0x17] = '\0';
  local_78[0x18] = '\0';
  local_78[0x19] = '\0';
  local_78[0x1a] = '\0';
  local_78[0x1b] = '\0';
  local_78[0x1c] = '\0';
  local_78[0x1d] = '\0';
  local_78[0x1e] = '\0';
  local_78[0x1f] = '\0';
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_78[8] = '\0';
  local_78[9] = '\0';
  local_78[10] = '\0';
  local_78[0xb] = '\0';
  local_78[0xc] = '\0';
  local_78[0xd] = '\0';
  local_78[0xe] = '\0';
  local_78[0xf] = '\0';
  snprintf(local_78,0x40,param_1,*param_2,
           (ulong)*(uint *)(*(long *)(*(long *)(param_3 + 0x40) + 0x18) + 0x408),
           (ulong)*(ushort *)(*(long *)(param_3 + 0x40) + 2));
  uVar3 = *(undefined8 *)(param_3 + 0x48);
  sVar1 = strnlen(local_78,0x40);
  if (0x40 < sVar1) {
LAB_00106034:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar1 == 0x40) {
LAB_00106040:
                    /* WARNING: Subroutine does not return */
    fortify_panic("__fortify_strlen");
  }
  __dest = (void *)devm_kmalloc(uVar3,sVar1 + 1,0xdc0);
  if (__dest == (void *)0x0) {
    uVar3 = 0xfffffff4;
    *param_2 = 0;
  }
  else {
    sVar1 = strnlen(local_78,0x40);
    if (0x40 < sVar1) goto LAB_00106034;
    if (sVar1 == 0x40) goto LAB_00106040;
    memcpy(__dest,local_78,sVar1);
    *param_2 = __dest;
    lVar2 = (*(long **)(param_3 + 0x48))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_3 + 0x48);
    }
    _printk(&DAT_00121c34,lVar2,"aw882xx_append_i2c_suffix",__dest);
    uVar3 = 0;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_codec_probe @ 00106054 size=836
// signature: undefined aw882xx_codec_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_codec_probe(undefined8 param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined8 *puVar5;
  long lVar6;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106090);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar6 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar6 == 0) {
    lVar6 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_00120075,lVar6,"aw882xx_codec_probe");
  lVar6 = alloc_workqueue(&DAT_0011e98e,0xe000a,1,"aw882xx");
  *(long *)(lVar2 + 0x70) = lVar6;
  if (lVar6 == 0) {
    lVar6 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar2 + 0x48);
    }
    _printk(&DAT_0011d9fd,lVar6,"aw882xx_codec_probe");
    uVar3 = 0xffffffea;
  }
  else {
    *(long *)(*(long *)(lVar2 + 0x68) + 0xc0) = lVar6;
    *(undefined8 *)(lVar2 + 0x78) = 0xfffffffe0;
    *(long *)(lVar2 + 0x80) = lVar2 + 0x80;
    *(long *)(lVar2 + 0x88) = lVar2 + 0x80;
    *(code **)(lVar2 + 0x90) = aw882xx_startup_work;
    init_timer_key(lVar2 + 0xa8,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined8 *)(lVar2 + 0x100) = 0xfffffffe0;
    *(long *)(lVar2 + 0x108) = lVar2 + 0x108;
    *(long *)(lVar2 + 0x110) = lVar2 + 0x108;
    *(code **)(lVar2 + 0x118) = aw882xx_interrupt_work;
    init_timer_key(lVar2 + 0x130,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined8 *)(lVar2 + 0x188) = 0xfffffffe0;
    *(long *)(lVar2 + 400) = lVar2 + 400;
    *(long *)(lVar2 + 0x198) = lVar2 + 400;
    *(code **)(lVar2 + 0x1a0) = aw882xx_dc_prot_work;
    init_timer_key(lVar2 + 0x1b8,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined8 *)(lVar2 + 0x210) = 0xfffffffe0;
    *(long *)(lVar2 + 0x218) = lVar2 + 0x218;
    *(long *)(lVar2 + 0x220) = lVar2 + 0x218;
    *(code **)(lVar2 + 0x228) = aw882xx_request_firmware;
    init_timer_key(lVar2 + 0x240,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined8 *)(lVar2 + 0x30) = param_1;
    if (*(int *)(*(long *)(lVar2 + 0x68) + 0x3c) == 0) {
      lVar6 = (*(long **)(lVar2 + 0x48))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar2 + 0x48);
      }
      _printk(&DAT_00120075,lVar6,"aw882xx_add_codec_controls");
      puVar4 = (undefined4 *)
               devm_kmalloc(*(undefined8 *)(*(long *)(lVar2 + 0x30) + 0x18),0x50,0xdc0);
      if ((puVar4 != (undefined4 *)0x0) &&
         (puVar5 = (undefined8 *)
                   devm_kmalloc(*(undefined8 *)(*(long *)(lVar2 + 0x30) + 0x18),0x32,0xdc0),
         puVar5 != (undefined8 *)0x0)) {
        *(undefined8 **)(puVar4 + 4) = puVar5;
        uVar3 = CONCAT53(s_aw_algo_auth_0011da5e._8_5_,s_aw_algo_auth_0011da5e._5_3_);
        *puVar5 = CONCAT35(s_aw_algo_auth_0011da5e._5_3_,s_aw_algo_auth_0011da5e._0_5_);
        *(undefined8 *)((long)puVar5 + 5) = uVar3;
        *puVar4 = 2;
        puVar4[7] = 0x10000030;
        *(code **)(puVar4 + 10) = aw882xx_algo_auth_info;
        *(code **)(puVar4 + 0x10) = aw882xx_algo_auth_tlv_rw;
        if (*(int *)(PTR_snd_soc_add_component_controls_00124768 + -4) != -0x8932f47) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106320);
          (*pcVar1)();
        }
        (*(code *)PTR_snd_soc_add_component_controls_00124768)
                  (*(undefined8 *)(lVar2 + 0x30),puVar4,1);
        if (*(int *)(PTR_snd_soc_add_component_controls_00124768 + -4) != -0x8932f47) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106350);
          (*pcVar1)();
        }
        (*(code *)PTR_snd_soc_add_component_controls_00124768)
                  (*(undefined8 *)(lVar2 + 0x30),aw882xx_controls,6);
        if (*(int *)(*(long *)(lVar2 + 0x68) + 0x3d0) == 1) {
          if (*(int *)(PTR_snd_soc_add_component_controls_00124768 + -4) != -0x8932f47) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106390);
            (*pcVar1)();
          }
          (*(code *)PTR_snd_soc_add_component_controls_00124768)
                    (*(undefined8 *)(lVar2 + 0x30),aw882xx_spin_control,1);
        }
      }
    }
    if (*(char *)(lVar2 + 0x1c) == '\0') {
      queue_delayed_work_on(0x20,*(undefined8 *)(lVar2 + 0x70),lVar2 + 0x210,0);
    }
    else {
      aw882xx_request_firmware(lVar2 + 0x210);
    }
    aw882xx_dev_init_cali_re(*(undefined8 *)(lVar2 + 0x68));
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// aw882xx_codec_remove @ 0010639c size=128
// signature: undefined aw882xx_codec_remove(void)
// callers: []
//------------------------------------------------------------

void aw882xx_codec_remove(void)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1063cc);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_00120075,lVar3,"aw882xx_codec_remove");
  aw882xx_dev_deinit(*(undefined8 *)(lVar2 + 0x68));
  destroy_workqueue(*(undefined8 *)(lVar2 + 0x70));
  *(undefined8 *)(lVar2 + 0x70) = 0;
  return;
}



//------------------------------------------------------------
// aw882xx_startup_work @ 00106420 size=104
// signature: undefined aw882xx_startup_work(void)
// callers: []
//------------------------------------------------------------

void aw882xx_startup_work(long param_1)

{
  long lVar1;
  
  lVar1 = (*(long **)(param_1 + -0x30))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1 + -0x30);
  }
  _printk(&DAT_00120075,lVar1,"aw882xx_startup_work");
  mutex_lock(param_1 + 0x220);
  aw882xx_start_pa(param_1 + -0x78);
  mutex_unlock(param_1 + 0x220);
  return;
}



//------------------------------------------------------------
// aw882xx_interrupt_work @ 0010648c size=212
// signature: undefined aw882xx_interrupt_work(void)
// callers: []
//------------------------------------------------------------

void aw882xx_interrupt_work(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  lVar2 = *(long *)(param_1 + -0x98);
  local_2c = 0;
  aw882xx_i2c_read(*(undefined8 *)(param_1 + -0xc0),*(undefined4 *)(lVar2 + 0x218),&local_2c);
  lVar1 = (*(long **)(param_1 + -0xb8))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1 + -0xb8);
  }
  _printk(&DAT_0011d664,lVar1,"aw882xx_interrupt_work",(undefined2)local_2c);
  aw882xx_i2c_read(*(undefined8 *)(param_1 + -0xc0),*(undefined4 *)(lVar2 + 0x134),&local_2c);
  lVar1 = (*(long **)(param_1 + -0xb8))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1 + -0xb8);
  }
  _printk(&DAT_001212c4,lVar1,"aw882xx_interrupt_work",(undefined2)local_2c);
  aw882xx_dev_set_intmask(*(undefined8 *)(param_1 + -0x98),1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dc_prot_work @ 00106564 size=148
// signature: undefined aw882xx_dc_prot_work(void)
// callers: []
//------------------------------------------------------------

void aw882xx_dc_prot_work(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + -0x120);
  iVar1 = aw882xx_dev_status(*puVar2);
  if (*(char *)(param_1 + -0x176) != '\0' && iVar1 != 0) {
    iVar1 = aw882xx_dev_dc_status(*puVar2);
    if (iVar1 < 1) {
      queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + -0x118),param_1,0xfa);
    }
    else {
      cancel_delayed_work_sync(param_1 + -0x110);
      mutex_lock(param_1 + 0x110);
      aw882xx_device_stop(*puVar2);
      mutex_unlock(param_1 + 0x110);
    }
  }
  return;
}



//------------------------------------------------------------
// aw882xx_request_firmware @ 001065fc size=1816
// signature: undefined aw882xx_request_firmware(void)
// callers: [aw882xx_codec_probe, aw882xx_request_firmware]
//------------------------------------------------------------

void aw882xx_request_firmware(long param_1)

{
  undefined *puVar1;
  size_t *psVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined1 *puVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long *plVar12;
  size_t *local_60;
  long local_58;
  
  lVar8 = sp_el0;
  puVar11 = (undefined8 *)(param_1 + -0x1c8);
  local_58 = *(long *)(lVar8 + 0x638);
  local_60 = (size_t *)0x0;
  *(undefined1 *)(param_1 + -0x1e8) = 0;
  iVar4 = request_firmware(&local_60,"aw882xx_acf.bin",*puVar11);
  plVar9 = (long *)*puVar11;
  lVar8 = plVar9[0xe];
  if ((iVar4 != 0) || (local_60 == (size_t *)0x0)) {
    if (lVar8 == 0) {
      lVar8 = *plVar9;
    }
    _printk(&DAT_0011dd83,lVar8,"aw882xx_request_firmware","aw882xx_acf.bin");
    pcVar6 = (char *)(param_1 + -0x1e7);
    if (*pcVar6 == '\x05') {
      *pcVar6 = '\0';
    }
    else {
      *pcVar6 = *pcVar6 + '\x01';
      msleep(1000);
      lVar8 = ((long *)*puVar11)[0xe];
      if (lVar8 == 0) {
        lVar8 = *(long *)*puVar11;
      }
      _printk(&DAT_00122542,lVar8,"aw882xx_request_firmware","aw882xx_acf.bin",*pcVar6);
      aw882xx_request_firmware(param_1);
    }
    goto LAB_00106bc4;
  }
  if (lVar8 == 0) {
    lVar8 = *plVar9;
  }
  _printk(&DAT_001212e8,lVar8,"aw882xx_request_firmware","aw882xx_acf.bin",*local_60);
  mutex_lock(g_aw882xx_lock);
  puVar5 = g_awinic_cfg;
  if (g_awinic_cfg == (undefined4 *)0x0) {
    uVar10 = *local_60;
    puVar5 = (undefined4 *)vzalloc(uVar10 + 4);
    psVar2 = local_60;
    if (puVar5 == (undefined4 *)0x0) {
      release_firmware();
      lVar8 = ((long *)*puVar11)[0xe];
      if (lVar8 == 0) {
        lVar8 = *(long *)*puVar11;
      }
      _printk(&DAT_0011f1aa,lVar8,"aw882xx_request_firmware");
    }
    else {
      if (0xfffffffffffffffb < uVar10) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x106d14);
        (*pcVar3)();
      }
      *puVar5 = (int)*local_60;
      memcpy(puVar5 + 1,(void *)local_60[1],*local_60);
      release_firmware(psVar2);
      iVar4 = aw882xx_dev_parse_check_acf(puVar5);
      if (iVar4 == 0) {
        g_awinic_cfg = puVar5;
        goto LAB_00106700;
      }
      lVar8 = ((long *)*puVar11)[0xe];
      if (lVar8 == 0) {
        lVar8 = *(long *)*puVar11;
      }
      _printk(&DAT_0011dda8,lVar8,"aw882xx_request_firmware","aw882xx_acf.bin");
      vfree(puVar5);
    }
    puVar7 = g_aw882xx_lock;
  }
  else {
    release_firmware();
    lVar8 = ((long *)*puVar11)[0xe];
    if (lVar8 == 0) {
      lVar8 = *(long *)*puVar11;
    }
    _printk(&DAT_00122569,lVar8,"aw882xx_request_firmware","aw882xx_acf.bin");
LAB_00106700:
    mutex_unlock(g_aw882xx_lock);
    puVar7 = (undefined1 *)(param_1 + 0x88);
    mutex_lock(puVar7);
    plVar9 = (long *)(param_1 + -0x1a8);
    iVar4 = aw882xx_dev_init(*plVar9,puVar5);
    if (iVar4 < 0) {
      lVar8 = ((long *)*puVar11)[0xe];
      if (lVar8 == 0) {
        lVar8 = *(long *)*puVar11;
      }
      _printk(&DAT_00123756,lVar8,"aw882xx_request_firmware");
    }
    else {
      plVar12 = (long *)(param_1 + -0x1e0);
      puVar5 = (undefined4 *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x370,0xdc0);
      if ((puVar5 != (undefined4 *)0x0) &&
         (pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x32,0xdc0),
         pcVar6 != (char *)0x0)) {
        snprintf(pcVar6,0x32,"aw_dev_%d_prof",*(int *)(*plVar9 + 0x3c));
        *(char **)(puVar5 + 4) = pcVar6;
        *(code **)(puVar5 + 10) = aw882xx_profile_info;
        *(code **)(puVar5 + 0xc) = aw882xx_profile_get;
        lVar8 = *plVar12;
        *puVar5 = 2;
        *(code **)(puVar5 + 0xe) = aw882xx_profile_set;
        pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
        if (pcVar6 != (char *)0x0) {
          snprintf(pcVar6,0x32,"aw_dev_%d_switch",*(int *)(*plVar9 + 0x3c));
          *(char **)(puVar5 + 0x18) = pcVar6;
          puVar5[0x14] = 2;
          *(code **)(puVar5 + 0x1e) = aw882xx_switch_info;
          *(code **)(puVar5 + 0x20) = aw882xx_switch_get;
          lVar8 = *plVar12;
          *(code **)(puVar5 + 0x22) = aw882xx_switch_set;
          pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
          if (pcVar6 != (char *)0x0) {
            snprintf(pcVar6,0x32,"aw_dev_%d_monitor",*(int *)(*plVar9 + 0x3c));
            *(char **)(puVar5 + 0x2c) = pcVar6;
            puVar5[0x28] = 2;
            *(code **)(puVar5 + 0x32) = aw882xx_monitor_info;
            *(code **)(puVar5 + 0x34) = aw882xx_monitor_get;
            lVar8 = *plVar12;
            *(code **)(puVar5 + 0x36) = aw882xx_monitor_set;
            pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
            if (pcVar6 != (char *)0x0) {
              snprintf(pcVar6,0x32,"aw_dev_%d_volume",*(int *)(*plVar9 + 0x3c));
              *(char **)(puVar5 + 0x40) = pcVar6;
              puVar5[0x3c] = 2;
              *(code **)(puVar5 + 0x46) = aw882xx_volume_info;
              *(code **)(puVar5 + 0x48) = aw882xx_volume_get;
              lVar8 = *plVar12;
              *(code **)(puVar5 + 0x4a) = aw882xx_volume_put;
              pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
              if (pcVar6 != (char *)0x0) {
                snprintf(pcVar6,0x32,"aw_dev_%d_hal_mon_work",*(int *)(*plVar9 + 0x3c));
                *(char **)(puVar5 + 0x54) = pcVar6;
                puVar5[0x57] = 1;
                lVar8 = *plVar12;
                puVar5[0x50] = 2;
                *(code **)(puVar5 + 0x5a) = aw882xx_hal_monitor_work_info;
                *(code **)(puVar5 + 0x5c) = aw882xx_hal_monitor_work_get;
                pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
                if (pcVar6 != (char *)0x0) {
                  snprintf(pcVar6,0x32,"aw_dev_%d_offset",*(int *)(*plVar9 + 0x3c));
                  lVar8 = *plVar12;
                  *(char **)(puVar5 + 0x68) = pcVar6;
                  puVar5[100] = 2;
                  *(code **)(puVar5 + 0x6e) = aw882xx_voltage_offset_info;
                  *(code **)(puVar5 + 0x70) = aw882xx_voltage_offset_get;
                  pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(lVar8 + 0x18),0x32,0xdc0);
                  if (pcVar6 != (char *)0x0) {
                    snprintf(pcVar6,0x32,"aw_dev_%d_iv_output",*(int *)(*plVar9 + 0x3c));
                    *(char **)(puVar5 + 0x7c) = pcVar6;
                    *(code **)(puVar5 + 0x82) = aw882xx_iv_output_info;
                    puVar5[0x78] = 2;
                    *(code **)(puVar5 + 0x84) = aw882xx_iv_output_get;
                    *(code **)(puVar5 + 0x86) = aw882xx_iv_output_set;
                    pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x32,0xdc0);
                    if (pcVar6 != (char *)0x0) {
                      snprintf(pcVar6,0x32,"aw_dev_%d_algo_volume",*(int *)(*plVar9 + 0x3c));
                      *(char **)(puVar5 + 0x90) = pcVar6;
                      *(code **)(puVar5 + 0x96) = aw882xx_algo_volume_info;
                      puVar5[0x8c] = 2;
                      *(code **)(puVar5 + 0x98) = aw882xx_algo_volume_get;
                      *(code **)(puVar5 + 0x9a) = aw882xx_algo_volume_put;
                      pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x32,0xdc0);
                      if (pcVar6 != (char *)0x0) {
                        snprintf(pcVar6,0x32,"aw_dev_%d_ramp_switch",*(int *)(*plVar9 + 0x3c));
                        *(char **)(puVar5 + 0xa4) = pcVar6;
                        *(code **)(puVar5 + 0xaa) = aw882xx_ramp_switch_info;
                        puVar5[0xa0] = 2;
                        *(code **)(puVar5 + 0xae) = aw882xx_ramp_switch_set;
                        *(code **)(puVar5 + 0xac) = aw882xx_ramp_switch_get;
                        pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x32,0xdc0);
                        if (pcVar6 != (char *)0x0) {
                          snprintf(pcVar6,0x32,"aw_dev_%d_ramp_params",*(int *)(*plVar9 + 0x3c));
                          *(char **)(puVar5 + 0xb8) = pcVar6;
                          *(code **)(puVar5 + 0xbe) = aw882xx_ramp_params_info;
                          puVar5[0xb4] = 2;
                          *(code **)(puVar5 + 0xc0) = aw882xx_ramp_params_get;
                          *(code **)(puVar5 + 0xc2) = aw882xx_ramp_params_put;
                          pcVar6 = (char *)devm_kmalloc(*(undefined8 *)(*plVar12 + 0x18),0x32,0xdc0)
                          ;
                          if (pcVar6 != (char *)0x0) {
                            snprintf(pcVar6,0x32,"smartpa_%d_status",*(int *)(*plVar9 + 0x3c));
                            lVar8 = *plVar12;
                            puVar5[200] = 2;
                            puVar1 = PTR_snd_soc_add_component_controls_00124768;
                            *(char **)(puVar5 + 0xcc) = pcVar6;
                            *(code **)(puVar5 + 0xd2) = aw882xx_hw_status_info;
                            *(code **)(puVar5 + 0xd4) = aw882xx_hw_status_get;
                            if (*(int *)(puVar1 + -4) != -0x8932f47) {
                    /* WARNING: Does not return */
                              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106b6c);
                              (*pcVar3)();
                            }
                            (*(code *)puVar1)(lVar8,puVar5,0xb);
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
      *(undefined1 *)(param_1 + -0x1e8) = 1;
      *(undefined1 *)(param_1 + -0x1e7) = 0;
    }
  }
  mutex_unlock(puVar7);
LAB_00106bc4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_profile_info @ 00106d18 size=304
// signature: undefined aw882xx_profile_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_profile_info(undefined8 param_1,long param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106d50);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106d70);
    (*pcVar1)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(undefined4 *)(param_2 + 0x40) = 3;
  *(undefined4 *)(param_2 + 0x48) = 1;
  uVar2 = aw882xx_dev_get_profile_count(*(undefined8 *)(lVar4 + 0x68));
  if ((int)uVar2 < 1) {
    *(undefined4 *)(param_2 + 0x50) = 0;
    lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar4 + 0x48);
    }
    _printk(&DAT_0011e562,lVar5,"aw882xx_profile_info");
  }
  else {
    *(uint *)(param_2 + 0x50) = uVar2;
    if (uVar2 <= *(uint *)(param_2 + 0x54)) {
      *(uint *)(param_2 + 0x54) = uVar2 - 1;
    }
    iVar3 = aw88xx_dev_get_profile_name(*(undefined8 *)(lVar4 + 0x68),param_2 + 0x58);
    if ((iVar3 != 0) && (iVar3 = strscpy(param_2 + 0x58,&DAT_0011f846,5), iVar3 < 0)) {
      lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(lVar4 + 0x48);
      }
      _printk(&DAT_0011fdec,lVar5,"aw882xx_profile_info");
    }
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_profile_get @ 00106e4c size=132
// signature: undefined aw882xx_profile_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_profile_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106e84);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106ea4);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  iVar2 = aw882xx_dev_get_profile_index(*(undefined8 *)(lVar3 + 0x68));
  *(long *)(param_2 + 0x48) = (long)iVar2;
  return 0;
}



//------------------------------------------------------------
// aw882xx_profile_set @ 00106ed4 size=396
// signature: undefined aw882xx_profile_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_profile_set(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined *puVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106f10);
    (*pcVar1)();
  }
  lVar3 = (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106f34);
    (*pcVar1)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  if (*(char *)(lVar4 + 0x13) == '\0') {
    lVar4 = (*(long **)(lVar3 + 0x18))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x18);
    }
    puVar5 = &DAT_00122d0c;
  }
  else {
    iVar2 = aw882xx_dev_check_profile_index
                      (*(undefined8 *)(lVar4 + 0x68),*(undefined4 *)(param_2 + 0x48));
    if (iVar2 != 0) {
      lVar4 = (*(long **)(lVar3 + 0x18))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(lVar3 + 0x18);
      }
      _printk(&DAT_0011e9aa,lVar4,"aw882xx_profile_set",*(undefined4 *)(param_2 + 0x48));
      return 0xffffffea;
    }
    iVar2 = aw882xx_dev_get_profile_index(*(undefined8 *)(lVar4 + 0x68));
    if (*(long *)(param_2 + 0x48) != (long)iVar2) {
      mutex_lock(lVar4 + 0x298);
      aw882xx_dev_set_profile_index(*(undefined8 *)(lVar4 + 0x68),*(undefined4 *)(param_2 + 0x48));
      if ((*(int *)(lVar4 + 8) != 0) && (*(char *)(lVar4 + 0x14) != '\0')) {
        aw882xx_device_stop(*(undefined8 *)(lVar4 + 0x68));
        aw882xx_start_pa(lVar4);
      }
      mutex_unlock(lVar4 + 0x298);
      lVar4 = (*(long **)(lVar3 + 0x18))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(lVar3 + 0x18);
      }
      _printk(&DAT_0011e58b,lVar4,"aw882xx_profile_set",*(undefined4 *)(param_2 + 0x48));
      return 1;
    }
    lVar4 = (*(long **)(lVar3 + 0x18))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x18);
    }
    puVar5 = &DAT_0011edb9;
  }
  _printk(puVar5,lVar4,"aw882xx_profile_set");
  return 0;
}



//------------------------------------------------------------
// aw882xx_switch_info @ 00107064 size=220
// signature: undefined aw882xx_switch_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_switch_info(undefined8 param_1,long param_2)

{
  size_t __maxlen;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  char *__s;
  
  uVar4 = *(uint *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0x40) = 3;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined4 *)(param_2 + 0x50) = 2;
  if (1 < uVar4) {
    uVar4 = 1;
    *(undefined4 *)(param_2 + 0x54) = 1;
  }
  __s = (&aw882xx_switch)[uVar4];
  sVar2 = strlen(__s);
  __maxlen = sVar2 + 1;
  sVar3 = strnlen(__s,__maxlen);
  if (sVar3 == 0xffffffffffffffff && sVar2 != 0xfffffffffffffffe) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar3 != __maxlen) {
    __maxlen = sVar3 + 1;
  }
  if (0x40 < __maxlen) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
  iVar1 = strscpy(param_2 + 0x58,__s);
  if (iVar1 < 0) {
    _printk(&DAT_0011f4d4,"aw882xx_switch_info");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_switch_get @ 00107144 size=124
// signature: undefined aw882xx_switch_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_switch_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10717c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10719c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(ulong *)(param_2 + 0x48) = (ulong)*(byte *)(lVar2 + 0x14);
  return 0;
}



//------------------------------------------------------------
// aw882xx_switch_set @ 001071c4 size=364
// signature: undefined aw882xx_switch_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_switch_set(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107200);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107220);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  if (*(int *)(lVar2 + 8) == 0) {
    mutex_lock(lVar2 + 0x298);
    *(bool *)(lVar2 + 0x14) = *(long *)(param_2 + 0x48) != 0;
  }
  else {
    if (*(long *)(param_2 + 0x48) == 0) {
      cancel_delayed_work_sync(lVar2 + 0x188);
      cancel_delayed_work_sync(lVar2 + 0x78);
      mutex_lock(lVar2 + 0x298);
      aw882xx_device_stop(*(undefined8 *)(lVar2 + 0x68));
      *(undefined1 *)(lVar2 + 0x14) = 0;
      mutex_unlock(lVar2 + 0x298);
      lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(lVar2 + 0x48);
      }
      _printk(&DAT_0011e5b1,lVar3,"aw882xx_switch_set");
      return 0;
    }
    cancel_delayed_work_sync(lVar2 + 0x78);
    mutex_lock(lVar2 + 0x298);
    *(undefined1 *)(lVar2 + 0x14) = 1;
    if (*(char *)(lVar2 + 0x28) == '\x01') {
      aw882xx_start_pa(lVar2);
    }
    else {
      lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(lVar2 + 0x48);
      }
      _printk(&DAT_00120637,lVar3,"aw882xx_switch_set");
    }
  }
  mutex_unlock(lVar2 + 0x298);
  return 0;
}



//------------------------------------------------------------
// aw882xx_monitor_info @ 00107334 size=220
// signature: undefined aw882xx_monitor_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_monitor_info(undefined8 param_1,long param_2)

{
  size_t __maxlen;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  char *__s;
  
  uVar4 = *(uint *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0x40) = 3;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined4 *)(param_2 + 0x50) = 2;
  if (1 < uVar4) {
    uVar4 = 1;
    *(undefined4 *)(param_2 + 0x54) = 1;
  }
  __s = (&aw882xx_switch)[uVar4];
  sVar2 = strlen(__s);
  __maxlen = sVar2 + 1;
  sVar3 = strnlen(__s,__maxlen);
  if (sVar3 == 0xffffffffffffffff && sVar2 != 0xfffffffffffffffe) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar3 != __maxlen) {
    __maxlen = sVar3 + 1;
  }
  if (0x40 < __maxlen) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
  iVar1 = strscpy(param_2 + 0x58,__s);
  if (iVar1 < 0) {
    _printk(&DAT_0011f4d4,"aw882xx_monitor_info");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_monitor_get @ 00107414 size=160
// signature: undefined aw882xx_monitor_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_monitor_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10744c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10746c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(*(long *)(lVar2 + 0x68) + 0x334);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011e9d2,lVar3,"aw882xx_monitor_get");
  return 0;
}



//------------------------------------------------------------
// aw882xx_monitor_set @ 001074b8 size=196
// signature: undefined aw882xx_monitor_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_monitor_set(undefined8 param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1074f0);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107510);
    (*pcVar2)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar5 = *(long *)(lVar3 + 0x68);
  iVar1 = *(int *)(param_2 + 0x48);
  lVar3 = (*(long **)(lVar5 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar5 + 0x78);
  }
  _printk(&DAT_001221f9,lVar3,"aw882xx_monitor_set",iVar1);
  if (*(int *)(lVar5 + 0x334) == iVar1) {
    uVar4 = 0;
  }
  else {
    *(int *)(lVar5 + 0x334) = iVar1;
    if (iVar1 != 0) {
      aw882xx_monitor_start(lVar5 + 0x2a8);
    }
    uVar4 = 1;
  }
  return uVar4;
}



//------------------------------------------------------------
// aw882xx_volume_info @ 00107580 size=144
// signature: undefined aw882xx_volume_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_volume_info(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1075b8);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1075d8);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar2 = *(long *)(lVar2 + 0x68);
  *(undefined8 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(long *)(param_2 + 0x58) = (long)*(int *)(lVar2 + 0x26c);
  return 0;
}



//------------------------------------------------------------
// aw882xx_volume_get @ 00107614 size=164
// signature: undefined aw882xx_volume_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_volume_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10764c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10766c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar4 = *(long *)(lVar2 + 0x68);
  *(long *)(param_2 + 0x48) = (long)*(int *)(lVar4 + 0x270);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011e27a,lVar3,"aw882xx_volume_get",*(undefined4 *)(lVar4 + 0x270));
  return 0;
}



//------------------------------------------------------------
// aw882xx_volume_put @ 001076bc size=268
// signature: undefined aw882xx_volume_put(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_volume_put(undefined8 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1076f8);
    (*pcVar3)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x107718);
    (*pcVar3)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar8 = *(long *)(lVar4 + 0x68);
  plVar7 = *(long **)(lVar4 + 0x48);
  iVar2 = *(int *)(param_2 + 0x48);
  lVar6 = plVar7[0xe];
  if ((*(int *)(lVar8 + 0x26c) < iVar2) || (iVar2 < 0)) {
    if (lVar6 == 0) {
      lVar6 = *plVar7;
    }
    _printk(&DAT_00121807,lVar6,"aw882xx_volume_put");
    uVar5 = 0xffffffea;
  }
  else {
    if (lVar6 == 0) {
      lVar6 = *plVar7;
    }
    _printk(&DAT_0011e27a,lVar6,"aw882xx_volume_put",iVar2);
    if (*(int *)(lVar8 + 0x270) == iVar2) {
      uVar5 = 0;
    }
    else {
      *(int *)(lVar8 + 0x270) = iVar2;
      iVar1 = *(int *)(lVar8 + 0x274);
      if (*(int *)(lVar8 + 0x274) <= iVar2) {
        iVar1 = iVar2;
      }
      aw882xx_dev_set_volume(*(undefined8 *)(lVar4 + 0x68),iVar1);
      uVar5 = 1;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// aw882xx_hal_monitor_work_info @ 001077cc size=32
// signature: undefined aw882xx_hal_monitor_work_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hal_monitor_work_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined8 *)(param_2 + 0x50) = 0xffffffff80000000;
  *(undefined8 *)(param_2 + 0x58) = 0;
  return 0;
}



//------------------------------------------------------------
// aw882xx_hal_monitor_work_get @ 001077f0 size=212
// signature: undefined aw882xx_hal_monitor_work_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hal_monitor_work_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10783c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10785c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  uVar3 = *(undefined8 *)(lVar2 + 0x68);
  local_3c = 0;
  mutex_lock(lVar2 + 0x298);
  aw882xx_dev_monitor_hal_work(uVar3,&local_3c);
  *(ulong *)(param_2 + 0x48) = (ulong)local_3c;
  mutex_unlock(lVar2 + 0x298);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_voltage_offset_info @ 001078c8 size=36
// signature: undefined aw882xx_voltage_offset_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_voltage_offset_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined8 *)(param_2 + 0x50) = 0xffffffffffffff01;
  *(undefined8 *)(param_2 + 0x58) = 0xffff;
  return 0;
}



//------------------------------------------------------------
// aw882xx_voltage_offset_get @ 001078f0 size=344
// signature: undefined aw882xx_voltage_offset_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_voltage_offset_get(undefined8 param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c = -1;
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107944);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107964);
    (*pcVar2)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar5 = *(long *)(lVar3 + 0x68);
  pcVar2 = *(code **)(lVar5 + 0x500);
  if (pcVar2 == (code *)0x0) {
    lVar4 = (*(long **)(lVar5 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar5 + 0x78);
    }
    _printk(&DAT_0012133f,lVar4,"aw882xx_voltage_offset_get");
    local_3c = 0xffff;
    iVar1 = *(int *)(lVar5 + 0x4c);
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x697ce87c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1079d8);
      (*pcVar2)();
    }
    (*pcVar2)(lVar5,&local_3c);
    iVar1 = *(int *)(lVar5 + 0x4c);
  }
  if (iVar1 != 0) {
    local_3c = *(int *)(lVar5 + 0x50);
  }
  *(long *)(param_2 + 0x48) = (long)local_3c;
  lVar5 = (*(long **)(lVar3 + 0x48))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(lVar3 + 0x48);
  }
  _printk(&DAT_0011e27a,lVar5,"aw882xx_voltage_offset_get");
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_iv_output_info @ 00107a4c size=220
// signature: undefined aw882xx_iv_output_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_iv_output_info(undefined8 param_1,long param_2)

{
  size_t __maxlen;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  char *__s;
  
  uVar4 = *(uint *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0x40) = 3;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined4 *)(param_2 + 0x50) = 2;
  if (1 < uVar4) {
    uVar4 = 1;
    *(undefined4 *)(param_2 + 0x54) = 1;
  }
  __s = (&aw882xx_switch)[uVar4];
  sVar2 = strlen(__s);
  __maxlen = sVar2 + 1;
  sVar3 = strnlen(__s,__maxlen);
  if (sVar3 == 0xffffffffffffffff && sVar2 != 0xfffffffffffffffe) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar3 != __maxlen) {
    __maxlen = sVar3 + 1;
  }
  if (0x40 < __maxlen) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
  iVar1 = strscpy(param_2 + 0x58,__s);
  if (iVar1 < 0) {
    _printk(&DAT_0011f4d4,"aw882xx_iv_output_info");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_iv_output_set @ 00107b2c size=140
// signature: undefined aw882xx_iv_output_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_iv_output_set(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107b64);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107b84);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  g_iv_output = *(long *)(param_2 + 0x48) == 0;
  aw882xx_dev_iv_forbidden_output(*(undefined8 *)(lVar2 + 0x68));
  return 0;
}



//------------------------------------------------------------
// aw882xx_iv_output_get @ 00107bbc size=20
// signature: undefined aw882xx_iv_output_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_iv_output_get(undefined8 param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) = (ulong)g_iv_output;
  return 0;
}



//------------------------------------------------------------
// aw882xx_algo_volume_info @ 00107bd4 size=20
// signature: undefined aw882xx_algo_volume_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_algo_volume_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 2;
  return 0;
}



//------------------------------------------------------------
// aw882xx_algo_volume_put @ 00107bec size=304
// signature: undefined aw882xx_algo_volume_put(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_algo_volume_put(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107c24);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107c44);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011d31c,lVar3,"aw882xx_algo_volume_put",*(undefined8 *)(param_2 + 0x48),
          *(undefined8 *)(param_2 + 0x50));
  lVar3 = *(long *)(lVar2 + 0x68);
  iVar4 = *(int *)(lVar3 + 0x54);
  if (iVar4 == 0) {
    *(int *)(lVar3 + 0x58) = *(int *)(param_2 + 0x48) + -0x80;
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar4 = *(int *)(lVar3 + 0x54);
  }
  if (iVar4 == 1) {
    *(int *)(lVar3 + 0x5c) = (int)*(undefined8 *)(param_2 + 0x50);
    lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(lVar2 + 0x48);
    }
    _printk(&DAT_0011f1cb,lVar3,"aw882xx_algo_volume_put",
            *(undefined4 *)(*(long *)(lVar2 + 0x68) + 0x58),
            *(undefined4 *)(*(long *)(lVar2 + 0x68) + 0x5c));
    aw882xx_dsp_write_volume(*(long *)(lVar2 + 0x68),*(long *)(lVar2 + 0x68) + 0x58,8);
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar4 = *(int *)(lVar3 + 0x54);
  }
  *(int *)(lVar3 + 0x54) = iVar4 + 1;
  if (*(int *)(*(long *)(lVar2 + 0x68) + 0x54) == 2) {
    *(undefined4 *)(*(long *)(lVar2 + 0x68) + 0x54) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_algo_volume_get @ 00107d20 size=172
// signature: undefined aw882xx_algo_volume_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_algo_volume_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107d58);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107d78);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(long *)(param_2 + 0x48) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x58);
  *(long *)(param_2 + 0x50) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x5c);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011d31c,lVar3,"aw882xx_algo_volume_get");
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_switch_info @ 00107dd0 size=220
// signature: undefined aw882xx_ramp_switch_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_switch_info(undefined8 param_1,long param_2)

{
  size_t __maxlen;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  uint uVar4;
  char *__s;
  
  uVar4 = *(uint *)(param_2 + 0x54);
  *(undefined4 *)(param_2 + 0x40) = 3;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined4 *)(param_2 + 0x50) = 2;
  if (1 < uVar4) {
    uVar4 = 1;
    *(undefined4 *)(param_2 + 0x54) = 1;
  }
  __s = (&aw882xx_switch)[uVar4];
  sVar2 = strlen(__s);
  __maxlen = sVar2 + 1;
  sVar3 = strnlen(__s,__maxlen);
  if (sVar3 == 0xffffffffffffffff && sVar2 != 0xfffffffffffffffe) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar3 != __maxlen) {
    __maxlen = sVar3 + 1;
  }
  if (0x40 < __maxlen) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strscpy");
  }
  iVar1 = strscpy(param_2 + 0x58,__s);
  if (iVar1 < 0) {
    _printk(&DAT_0011f4d4,"aw882xx_ramp_switch_info");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_switch_get @ 00107eb0 size=128
// signature: undefined aw882xx_ramp_switch_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_switch_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107ee8);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107f08);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(long *)(param_2 + 0x48) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x60);
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_switch_set @ 00107f34 size=184
// signature: undefined aw882xx_ramp_switch_set(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_switch_set(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107f6c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x107f8c);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  aw882xx_dsp_write_ramp_enable(*(undefined8 *)(lVar2 + 0x68),*(undefined4 *)(param_2 + 0x48));
  *(int *)(*(long *)(lVar2 + 0x68) + 0x60) = (int)*(undefined8 *)(param_2 + 0x48);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011ddd2,lVar3,"aw882xx_ramp_switch_set",
          *(undefined4 *)(*(long *)(lVar2 + 0x68) + 0x60));
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_params_info @ 00107ff0 size=24
// signature: undefined aw882xx_ramp_params_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_params_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 4;
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_params_put @ 0010800c size=392
// signature: undefined aw882xx_ramp_params_put(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_params_put(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108044);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108064);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011f4fb,lVar3,"aw882xx_ramp_params_put",*(undefined8 *)(param_2 + 0x48),
          *(undefined8 *)(param_2 + 0x50),*(undefined8 *)(param_2 + 0x58),
          *(undefined8 *)(param_2 + 0x60));
  lVar3 = *(long *)(lVar2 + 0x68);
  iVar5 = *(int *)(lVar3 + 100);
  if (iVar5 == 0) {
    *(int *)(lVar3 + 0x68) = *(int *)(param_2 + 0x48) + -0x5a0;
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar5 = *(int *)(lVar3 + 100);
  }
  if (iVar5 == 1) {
    *(int *)(lVar3 + 0x6c) = (int)*(undefined8 *)(param_2 + 0x50);
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar5 = *(int *)(lVar3 + 100);
  }
  if (iVar5 == 2) {
    *(int *)(lVar3 + 0x70) = *(int *)(param_2 + 0x58) + -0x5a0;
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar5 = *(int *)(lVar3 + 100);
  }
  if (iVar5 == 3) {
    *(int *)(lVar3 + 0x74) = (int)*(undefined8 *)(param_2 + 0x60);
    lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(lVar2 + 0x48);
    }
    lVar4 = *(long *)(lVar2 + 0x68);
    _printk(&DAT_001225da,lVar3,"aw882xx_ramp_params_put",*(undefined4 *)(lVar4 + 0x68),
            *(undefined4 *)(lVar4 + 0x6c),*(undefined4 *)(lVar4 + 0x70),
            *(undefined4 *)(lVar4 + 0x74));
    aw882xx_dsp_write_ramp_params(*(long *)(lVar2 + 0x68),*(long *)(lVar2 + 0x68) + 0x68,0x10);
    lVar3 = *(long *)(lVar2 + 0x68);
    iVar5 = *(int *)(lVar3 + 100);
  }
  *(int *)(lVar3 + 100) = iVar5 + 1;
  if (*(int *)(*(long *)(lVar2 + 0x68) + 100) == 4) {
    *(undefined4 *)(*(long *)(lVar2 + 0x68) + 100) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_ramp_params_get @ 00108198 size=196
// signature: undefined aw882xx_ramp_params_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_ramp_params_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1081d0);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1081f0);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(long *)(param_2 + 0x48) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x68);
  *(long *)(param_2 + 0x50) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x6c);
  *(long *)(param_2 + 0x58) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x70);
  *(long *)(param_2 + 0x60) = (long)*(int *)(*(long *)(lVar2 + 0x68) + 0x74);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011f4fb,lVar3,"aw882xx_ramp_params_get");
  return 0;
}



//------------------------------------------------------------
// aw882xx_hw_status_info @ 00108260 size=32
// signature: undefined aw882xx_hw_status_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hw_status_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 2;
  *(undefined4 *)(param_2 + 0x48) = 1;
  *(undefined8 *)(param_2 + 0x50) = 0;
  *(undefined8 *)(param_2 + 0x58) = 0x80;
  return 0;
}



//------------------------------------------------------------
// aw882xx_hw_status_get @ 00108284 size=164
// signature: undefined aw882xx_hw_status_get(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hw_status_get(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1082bc);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1082dc);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  lVar4 = *(long *)(lVar2 + 0x68);
  *(ulong *)(param_2 + 0x48) = (ulong)*(uint *)(lVar4 + 0x34);
  lVar3 = (*(long **)(lVar2 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar2 + 0x48);
  }
  _printk(&DAT_0011e27a,lVar3,"aw882xx_hw_status_get",*(undefined4 *)(lVar4 + 0x34));
  return 0;
}



//------------------------------------------------------------
// aw882xx_algo_auth_info @ 0010832c size=24
// signature: undefined aw882xx_algo_auth_info(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_algo_auth_info(undefined8 param_1,long param_2)

{
  *(undefined4 *)(param_2 + 0x40) = 4;
  *(undefined4 *)(param_2 + 0x48) = 0x14;
  return 0;
}



//------------------------------------------------------------
// aw882xx_algo_auth_tlv_rw @ 00108348 size=832
// signature: undefined aw882xx_algo_auth_tlv_rw(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 aw882xx_algo_auth_tlv_rw(undefined8 param_1,int param_2,uint param_3,ulong param_4)

{
  ulong uVar1;
  code *pcVar2;
  long lVar3;
  size_t __n;
  long lVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10839c);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1083bc);
    (*pcVar2)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  if (param_4 == 0) {
    lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x48);
    }
    _printk(&DAT_0011f84b,lVar4,"aw882xx_algo_auth_tlv_rw");
  }
  else if (param_3 < 0x14) {
    lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x48);
    }
    _printk(&DAT_00120df3,lVar4,"aw882xx_algo_auth_tlv_rw",param_3,0x14);
  }
  else {
    if (param_2 == 1) {
      puVar6 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
         (uVar7 = param_4, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
        uVar7 = param_4 & (long)(param_4 << 8) >> 8;
      }
      if (uVar7 < 0x7fffffffed) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar7 = daif;
          if ((uVar7 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          puVar6 = (undefined8 *)puVar6[1];
          uVar1 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar6;
          InstructionSynchronizationBarrier();
          daif = uVar7;
        }
        __n = __arch_copy_from_user(puVar6,&local_50,param_4 & 0xff7fffffffffffff,0x14);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar7 = daif;
          if ((uVar7 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          uVar1 = ttbr1_el1;
          ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar7;
        }
        if (__n != 0) goto LAB_00108638;
        uVar5 = 0;
      }
      else {
        __n = 0x14;
LAB_00108638:
        memset(auStack_3c + -__n,0,__n);
        uVar5 = 0xfffffff2;
      }
      aw882xx_dev_algo_auth_set(*(undefined8 *)(lVar3 + 0x68),&local_50);
      goto LAB_00108604;
    }
    if (param_2 == 0) {
      aw882xx_dev_algo_auth_get(*(undefined8 *)(lVar3 + 0x68),&local_50);
      puVar6 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
         (uVar7 = param_4, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
        uVar7 = param_4 & (long)(param_4 << 8) >> 8;
      }
      if (uVar7 < 0x7fffffffed) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar7 = daif;
          if ((uVar7 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          puVar6 = (undefined8 *)puVar6[1];
          uVar1 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar6;
          InstructionSynchronizationBarrier();
          daif = uVar7;
        }
        lVar3 = __arch_copy_to_user(puVar6,param_4 & 0xff7fffffffffffff,&local_50,0x14);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar7 = daif;
          if ((uVar7 & 0x80) == 0) {
            uVar1 = daif;
            daif = uVar1 | 0xc0;
          }
          uVar1 = ttbr1_el1;
          ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar1 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar7;
        }
        uVar5 = 0;
        if (lVar3 != 0) {
          uVar5 = 0xfffffff2;
        }
      }
      else {
        uVar5 = 0xfffffff2;
      }
      goto LAB_00108604;
    }
  }
  uVar5 = 0xffffffea;
LAB_00108604:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// aw882xx_get_rx_en @ 001086bc size=292
// signature: undefined aw882xx_get_rx_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_rx_en(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108708);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108728);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  if (*(int *)(lVar3 + 8) == 0) {
    *(ulong *)(param_2 + 0x48) = (ulong)g_algo_rx_en;
    lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x48);
    }
    _printk(&DAT_0011f87e,lVar4,"aw882xx_get_rx_en");
  }
  else {
    iVar2 = aw882xx_dsp_get_afe_module_en(0,&local_2c);
    if (iVar2 != 0) {
      lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(lVar3 + 0x48);
      }
      _printk(&DAT_0012137a,lVar4,"aw882xx_get_rx_en",iVar2);
    }
    *(ulong *)(param_2 + 0x48) = (ulong)local_2c;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_rx_en @ 001087e4 size=272
// signature: undefined aw882xx_set_rx_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_rx_en(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10881c);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10883c);
    (*pcVar2)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  if (*(int *)(lVar4 + 8) == 0) {
    lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar4 + 0x48);
    }
    _printk(&DAT_0012182c,lVar5,"aw882xx_set_rx_en");
  }
  else {
    iVar3 = aw882xx_dsp_set_afe_module_en(0,uVar1);
    if (iVar3 != 0) {
      lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(lVar4 + 0x48);
      }
      _printk(&DAT_0012137a,lVar5,"aw882xx_set_rx_en",iVar3);
    }
  }
  lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(lVar4 + 0x48);
  }
  g_algo_rx_en = uVar1;
  _printk(&DAT_0011d355,lVar5,"aw882xx_set_rx_en",uVar1);
  return 0;
}



//------------------------------------------------------------
// aw882xx_get_tx_en @ 001088f8 size=296
// signature: undefined aw882xx_get_tx_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_tx_en(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108944);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108964);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  if (*(int *)(lVar3 + 8) == 0) {
    *(ulong *)(param_2 + 0x48) = (ulong)g_algo_tx_en;
    lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x48);
    }
    _printk(&DAT_0011f87e,lVar4,"aw882xx_get_tx_en");
  }
  else {
    iVar2 = aw882xx_dsp_get_afe_module_en(1,&local_2c);
    if (iVar2 == 0) {
      *(ulong *)(param_2 + 0x48) = (ulong)local_2c;
    }
    else {
      lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(lVar3 + 0x48);
      }
      _printk(&DAT_0012137a,lVar4,"aw882xx_get_tx_en",iVar2);
      *(undefined8 *)(param_2 + 0x48) = 0;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_tx_en @ 00108a24 size=272
// signature: undefined aw882xx_set_tx_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_tx_en(undefined8 param_1,long param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108a5c);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108a7c);
    (*pcVar2)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  uVar1 = *(undefined4 *)(param_2 + 0x48);
  if (*(int *)(lVar4 + 8) == 0) {
    lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar4 + 0x48);
    }
    _printk(&DAT_0012182c,lVar5,"aw882xx_set_tx_en");
  }
  else {
    iVar3 = aw882xx_dsp_set_afe_module_en(1,uVar1);
    if (iVar3 != 0) {
      lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(lVar4 + 0x48);
      }
      _printk(&DAT_0012137a,lVar5,"aw882xx_set_tx_en",iVar3);
    }
  }
  lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(lVar4 + 0x48);
  }
  g_algo_tx_en = uVar1;
  _printk(&DAT_0011d355,lVar5,"aw882xx_set_tx_en",uVar1);
  return 0;
}



//------------------------------------------------------------
// aw882xx_get_copp_en @ 00108b38 size=124
// signature: undefined aw882xx_get_copp_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_copp_en(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108b70);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108b90);
    (*pcVar1)();
  }
  (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  *(ulong *)(param_2 + 0x48) = (ulong)g_algo_copp_en;
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_copp_en @ 00108bb8 size=272
// signature: undefined aw882xx_set_copp_en(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_copp_en(undefined8 param_1,long param_2)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108bf0);
    (*pcVar2)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x108c10);
    (*pcVar2)();
  }
  lVar4 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  iVar1 = *(int *)(param_2 + 0x48);
  if (*(int *)(lVar4 + 8) == 0) {
    lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(lVar4 + 0x48);
    }
    _printk(&DAT_0012182c,lVar5,"aw882xx_set_copp_en");
  }
  else {
    iVar3 = aw882xx_dsp_set_copp_module_en(iVar1 != 0);
    if (iVar3 != 0) {
      lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(lVar4 + 0x48);
      }
      _printk(&DAT_0012137a,lVar5,"aw882xx_set_copp_en",iVar3);
    }
  }
  lVar5 = (*(long **)(lVar4 + 0x48))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(lVar4 + 0x48);
  }
  g_algo_copp_en = iVar1;
  _printk(&DAT_0011d355,lVar5,"aw882xx_set_copp_en",iVar1);
  return 0;
}



//------------------------------------------------------------
// aw882xx_get_fade_in_time @ 00108ccc size=108
// signature: undefined aw882xx_get_fade_in_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_fade_in_time(undefined8 param_1,long param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  aw882xx_dev_get_fade_time(&local_2c,1);
  *(ulong *)(param_2 + 0x48) = (ulong)local_2c;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_fade_in_time @ 00108d3c size=56
// signature: undefined aw882xx_set_fade_in_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_fade_in_time(long param_1,long param_2)

{
  if (*(long *)(param_2 + 0x48) <= (long)*(int *)(*(long *)(param_1 + 0x78) + 4)) {
    aw882xx_dev_set_fade_time(*(long *)(param_2 + 0x48),1);
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_get_fade_out_time @ 00108d78 size=108
// signature: undefined aw882xx_get_fade_out_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_fade_out_time(undefined8 param_1,long param_2)

{
  long lVar1;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  aw882xx_dev_get_fade_time(&local_2c,0);
  *(ulong *)(param_2 + 0x48) = (ulong)local_2c;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_fade_out_time @ 00108de8 size=56
// signature: undefined aw882xx_set_fade_out_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_set_fade_out_time(long param_1,long param_2)

{
  if (*(long *)(param_2 + 0x48) <= (long)*(int *)(*(long *)(param_1 + 0x78) + 4)) {
    aw882xx_dev_set_fade_time(*(long *)(param_2 + 0x48),0);
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_hal_get_monitor_time @ 00108e24 size=180
// signature: undefined aw882xx_hal_get_monitor_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hal_get_monitor_time(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108e70);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108e90);
    (*pcVar1)();
  }
  lVar2 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  aw882xx_dev_monitor_hal_get_time(*(undefined8 *)(lVar2 + 0x68),&local_2c);
  *(ulong *)(param_2 + 0x48) = (ulong)local_2c;
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_hal_set_monitor_time @ 00108edc size=8
// signature: undefined aw882xx_hal_set_monitor_time(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_hal_set_monitor_time(void)

{
  return 0;
}



//------------------------------------------------------------
// aw882xx_get_spin @ 00108ee8 size=248
// signature: undefined aw882xx_get_spin(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_get_spin(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108f30);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108f50);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  local_2c = 0;
  iVar2 = aw882xx_spin_value_get(*(undefined8 *)(lVar3 + 0x68),&local_2c,*(int *)(lVar3 + 8) != 0);
  if (iVar2 == 0) {
    uVar5 = (ulong)local_2c;
  }
  else {
    lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(lVar3 + 0x48);
    }
    _printk(&DAT_001200d2,lVar4,"aw882xx_get_spin",iVar2);
    uVar5 = 0;
  }
  *(ulong *)(param_2 + 0x48) = uVar5;
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_set_spin @ 00108fe4 size=248
// signature: undefined aw882xx_set_spin(void)
// callers: []
//------------------------------------------------------------

int aw882xx_set_spin(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  
  if (*(int *)(aw_componet_codec_ops + -4) != 0x2bd14eff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10901c);
    (*pcVar1)();
  }
  (*(code *)aw_componet_codec_ops)();
  if (*(int *)(PTR_snd_soc_component_get_drvdata_00124760 + -4) != 0x252f39fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10903c);
    (*pcVar1)();
  }
  lVar3 = (*(code *)PTR_snd_soc_component_get_drvdata_00124760)();
  if ((*(ulong *)(param_2 + 0x48) & 0xfffffffc) == 0) {
    iVar2 = aw882xx_spin_value_set
                      (*(long *)(lVar3 + 0x68),*(ulong *)(param_2 + 0x48) & 0xffffffff,
                       *(int *)(lVar3 + 8) != 0);
    if (iVar2 != 0) {
      lVar4 = (*(long **)(lVar3 + 0x48))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(lVar3 + 0x48);
      }
      _printk(&DAT_00120e2a,lVar4,"aw882xx_set_spin",iVar2);
    }
  }
  else {
    plVar5 = *(long **)(*(long *)(lVar3 + 0x68) + 0x78);
    lVar3 = plVar5[0xe];
    if (lVar3 == 0) {
      lVar3 = *plVar5;
    }
    _printk(&DAT_001234aa,lVar3,"aw882xx_set_spin");
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// reg_show @ 001090e0 size=220
// signature: undefined reg_show(void)
// callers: []
//------------------------------------------------------------

long reg_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  uint param3;
  long lVar4;
  uint local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_5c = 0;
  iVar1 = *(int *)(*(long *)(lVar4 + 0x68) + 0x1c);
  if (iVar1 < 1) {
    lVar3 = 0;
  }
  else {
    param3 = 0;
    lVar3 = 0;
    do {
      aw882xx_i2c_read(*(undefined8 *)(lVar4 + 0x40),param3,&local_5c);
      iVar2 = snprintf((char *)(param_3 + lVar3),0x1000 - lVar3,"reg:0x%02x=0x%04x\n",param3,
                       local_5c);
      lVar3 = lVar3 + iVar2;
      param3 = param3 + 1 & 0xff;
    } while ((int)param3 < iVar1);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar3;
}



//------------------------------------------------------------
// reg_store @ 001091c0 size=144
// signature: undefined reg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_30,(uint *)((ulong)&local_30 | 4));
  if (iVar1 == 2) {
    aw882xx_i2c_write(*(undefined8 *)(lVar2 + 0x40),local_30 & 0xffffffff,local_30._4_4_);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// rw_show @ 00109254 size=136
// signature: undefined rw_show(void)
// callers: []
//------------------------------------------------------------

long rw_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  aw882xx_i2c_read(*(undefined8 *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x2a),&local_2c);
  iVar1 = snprintf(param_3,0x1000,"reg:0x%02x=0x%04x\n",(uint)*(byte *)(lVar2 + 0x2a),local_2c);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// rw_store @ 001092e0 size=188
// signature: undefined rw_store(void)
// callers: []
//------------------------------------------------------------

undefined8 rw_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = sscanf(param_3,"%x %x",(uint *)&local_40,(uint *)((ulong)&local_40 | 4));
  if (iVar1 == 2) {
    *(char *)(lVar2 + 0x2a) = (char)local_40;
    aw882xx_i2c_write(*(undefined8 *)(lVar2 + 0x40),local_40 & 0xffffffff,local_40._4_4_);
  }
  else {
    iVar1 = kstrtouint(param_3,0x10,&local_40);
    if (iVar1 == 0) {
      *(char *)(lVar2 + 0x2a) = (char)local_40;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// awrw_show @ 001093a0 size=484
// signature: undefined awrw_show(void)
// callers: []
//------------------------------------------------------------

long awrw_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  undefined *puVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  byte *pbVar10;
  undefined1 local_7c [4];
  undefined2 local_78;
  undefined6 uStack_76;
  undefined1 *local_70;
  undefined8 local_68;
  byte *local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar8 + 0x50) != '\x01') {
    lVar7 = (*(long **)(lVar8 + 0x48))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(lVar8 + 0x48);
    }
    _printk(&DAT_0011de10,lVar7,"awrw_show");
    lVar7 = -0x16;
    goto LAB_001093fc;
  }
  uVar1 = *(int *)(lVar8 + 0x54) * 2;
  uVar9 = (ulong)uVar1;
  pbVar4 = (byte *)__kmalloc((long)(int)uVar1,0xcc0);
  if (pbVar4 == (byte *)0x0) {
    lVar7 = -0xc;
    goto LAB_001093fc;
  }
  lVar7 = *(long *)(lVar8 + 0x40);
  local_70 = local_7c;
  local_7c[0] = (undefined1)*(undefined4 *)(lVar8 + 0x58);
  _local_78 = CONCAT62(0x10000,*(undefined2 *)(lVar7 + 2));
  local_68 = (ulong)CONCAT24((short)uVar1,CONCAT22(1,*(undefined2 *)(lVar7 + 2)));
  local_60 = pbVar4;
  iVar2 = i2c_transfer(*(undefined8 *)(lVar7 + 0x18),&local_78,2);
  if (iVar2 < 0) {
    lVar6 = *(long *)(lVar7 + 0x90);
    if (lVar6 == 0) {
      lVar6 = *(long *)(lVar7 + 0x20);
    }
    puVar5 = &DAT_0011f822;
LAB_00109558:
    _printk(puVar5,lVar6,"aw882xx_i2c_reads");
    lVar7 = -0xe;
  }
  else {
    if (iVar2 != 2) {
      lVar6 = *(long *)(lVar7 + 0x90);
      if (lVar6 == 0) {
        lVar6 = *(long *)(lVar7 + 0x20);
      }
      puVar5 = &DAT_001211b5;
      goto LAB_00109558;
    }
    lVar7 = (*(long **)(lVar8 + 0x48))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(lVar8 + 0x48);
    }
    _printk(&DAT_001206ab,lVar7,"awrw_show",*(undefined4 *)(lVar8 + 0x58),
            *(undefined4 *)(lVar8 + 0x54));
    if ((int)uVar1 < 1) {
      lVar7 = 0;
    }
    else {
      iVar2 = 0;
      pbVar10 = pbVar4;
      do {
        iVar3 = snprintf((char *)(param_3 + iVar2),0x1000 - (long)iVar2,"0x%02x,",(uint)*pbVar10);
        uVar9 = uVar9 - 1;
        iVar2 = iVar3 + iVar2;
        pbVar10 = pbVar10 + 1;
      } while (uVar9 != 0);
      lVar7 = (long)iVar2;
    }
  }
  kfree(pbVar4);
  *(undefined1 *)(lVar8 + 0x50) = 0;
LAB_001093fc:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar7;
}



//------------------------------------------------------------
// awrw_store @ 00109588 size=924
// signature: undefined awrw_store(void)
// callers: []
//------------------------------------------------------------

ulong awrw_store(long *param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined *puVar7;
  long lVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  undefined4 local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  int local_70 [2];
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  if (param_4 < 0x18) {
    lVar8 = param_1[0xe];
    if (lVar8 == 0) {
      lVar8 = *param_1;
    }
    _printk(&DAT_001234d8,lVar8,"awrw_store");
    lVar8 = param_1[0xe];
    if (lVar8 == 0) {
      lVar8 = *param_1;
    }
    _printk(&DAT_0011f8ad,lVar8,"awrw_store",param_3);
  }
  else {
    lVar8 = param_1[0x13];
    local_70[0] = 0;
    local_80 = 0;
    uStack_78 = 0;
    iVar5 = sscanf(param_3,"0x%02x 0x%02x 0x%02x 0x%02x 0x%02x",&local_80,(ulong)&local_80 | 4,
                   &uStack_78,(long)&uStack_78 + 4,local_70);
    if (iVar5 == 5) {
      if ((local_80._4_4_ == 1) && ((int)uStack_78 == 2)) {
        if (*(int *)(*(long *)(lVar8 + 0x68) + 0x1c) <= local_70[0]) {
          lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
          if (lVar9 == 0) {
            lVar9 = **(long **)(lVar8 + 0x48);
          }
          puVar7 = &DAT_0011e2d5;
          goto LAB_00109820;
        }
        *(undefined4 *)(lVar8 + 0x54) = uStack_78._4_4_;
        *(int *)(lVar8 + 0x58) = local_70[0];
        if ((int)local_80 == 1) {
          *(undefined1 *)(lVar8 + 0x50) = 1;
          lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
          if (lVar9 == 0) {
            lVar9 = **(long **)(lVar8 + 0x48);
          }
          _printk(&DAT_00122fe3,lVar9,"aw882xx_awrw_parse_buf");
          goto LAB_00109830;
        }
        if ((int)local_80 != 0) {
          lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
          if (lVar9 == 0) {
            lVar9 = **(long **)(lVar8 + 0x48);
          }
          _printk(&DAT_0011f54f,lVar9,"aw882xx_awrw_parse_buf",local_80 & 0xffffffff);
          goto LAB_0010982c;
        }
        local_84 = 0;
        lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
        if (lVar9 == 0) {
          lVar9 = **(long **)(lVar8 + 0x48);
        }
        _printk(&DAT_0011f8ca,lVar9,"aw882xx_awrw_write");
        if (*(int *)(lVar8 + 0x54) * 10 + -1 <= (int)param_4 + -0x19) {
          uVar2 = *(int *)(lVar8 + 0x54) * 2;
          uVar3 = uVar2 | 1;
          puVar6 = (undefined1 *)__kmalloc((long)(int)uVar3,0xcc0);
          if (puVar6 != (undefined1 *)0x0) {
            *puVar6 = (char)*(undefined4 *)(lVar8 + 0x58);
            if (0 < (int)uVar2) {
              lVar9 = 0;
              uVar11 = 0;
              do {
                iVar5 = sscanf(param_3 + (lVar9 >> 0x20) + 0x19,"0x%02x",&local_84);
                if (iVar5 != 1) goto LAB_0010982c;
                if ((((uVar2 == uVar11) || ((long)(uVar11 + 1) < 0)) ||
                    ((ulong)(long)(int)uVar3 <= uVar11)) || ((long)(int)uVar2 == uVar11)) {
                    /* WARNING: Does not return */
                  pcVar4 = (code *)SoftwareBreakpoint(1,0x109924);
                  (*pcVar4)();
                }
                uVar1 = uVar11 + 1;
                puVar6[uVar11 + 1] = (char)local_84;
                lVar9 = lVar9 + 0x500000000;
                uVar11 = uVar1;
              } while (uVar2 != uVar1);
            }
            iVar5 = i2c_transfer_buffer_flags(*(undefined8 *)(lVar8 + 0x40),puVar6,uVar3,0);
            if (-1 < iVar5) {
              kfree(puVar6);
              lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
              if (lVar9 == 0) {
                lVar9 = **(long **)(lVar8 + 0x48);
              }
              _printk(&DAT_0011e5cc,lVar9,"aw882xx_awrw_write");
              goto LAB_00109830;
            }
            lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
            if (lVar9 == 0) {
              lVar9 = **(long **)(lVar8 + 0x48);
            }
            _printk(&DAT_0011d6dd,lVar9,"aw882xx_awrw_write");
            kfree(puVar6);
          }
          goto LAB_0010982c;
        }
        lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
        if (lVar9 == 0) {
          lVar9 = **(long **)(lVar8 + 0x48);
        }
        puVar7 = &DAT_0011ea23;
        pcVar10 = "aw882xx_awrw_write";
      }
      else {
        lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
        if (lVar9 == 0) {
          lVar9 = **(long **)(lVar8 + 0x48);
        }
        puVar7 = &DAT_00120e6b;
LAB_00109820:
        pcVar10 = "aw882xx_awrw_data_check";
      }
      _printk(puVar7,lVar9,pcVar10);
    }
    else {
      lVar9 = (*(long **)(lVar8 + 0x48))[0xe];
      if (lVar9 == 0) {
        lVar9 = **(long **)(lVar8 + 0x48);
      }
      _printk(&DAT_0012187e,lVar9,"aw882xx_awrw_parse_buf");
    }
  }
LAB_0010982c:
  param_4 = 0xffffffffffffffea;
LAB_00109830:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// drv_ver_show @ 00109928 size=56
// signature: undefined drv_ver_show(void)
// callers: []
//------------------------------------------------------------

long drv_ver_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"driver_ver: %s\n","v2.0.2.1");
  return (long)iVar1;
}



//------------------------------------------------------------
// fade_step_show @ 00109964 size=76
// signature: undefined fade_step_show(void)
// callers: []
//------------------------------------------------------------

long fade_step_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = aw882xx_dev_get_fade_vol_step(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68));
  iVar1 = snprintf(param_3,0x1000,"step: %d\n",iVar1);
  return (long)iVar1;
}



//------------------------------------------------------------
// fade_step_store @ 001099b4 size=212
// signature: undefined fade_step_store(void)
// callers: []
//------------------------------------------------------------

undefined8 fade_step_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  ulong local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtouint(param_3,10,&local_30);
  if (iVar1 == 0) {
    uVar4 = local_30 & 0xffffffff;
    if (*(uint *)(*(long *)(lVar5 + 0x68) + 0x26c) < (uint)local_30) {
      lVar3 = (*(long **)(lVar5 + 0x48))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(lVar5 + 0x48);
      }
      puVar2 = &DAT_0011ea63;
      goto LAB_00109a4c;
    }
    aw882xx_dev_set_fade_vol_step(*(long *)(lVar5 + 0x68),uVar4);
  }
  lVar3 = (*(long **)(lVar5 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar5 + 0x48);
  }
  uVar4 = local_30 & 0xffffffff;
  puVar2 = &DAT_00120eab;
LAB_00109a4c:
  _printk(puVar2,lVar3,"fade_step_store",uVar4);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dbg_prof_show @ 00109a8c size=60
// signature: undefined dbg_prof_show(void)
// callers: []
//------------------------------------------------------------

long dbg_prof_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000," %d\n",(ulong)*(byte *)(*(long *)(param_1 + 0x98) + 0x13));
  return (long)iVar1;
}



//------------------------------------------------------------
// dbg_prof_store @ 00109acc size=172
// signature: undefined dbg_prof_store(void)
// callers: []
//------------------------------------------------------------

undefined8 dbg_prof_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  iVar1 = kstrtouint(param_3,10,&local_30);
  if (iVar1 == 0) {
    *(bool *)(lVar3 + 0x13) = (int)local_30 != 0;
  }
  plVar2 = *(long **)(lVar3 + 0x48);
  lVar3 = plVar2[0xe];
  if (lVar3 == 0) {
    lVar3 = *plVar2;
  }
  _printk(&DAT_001218a6,lVar3,"dbg_prof_store",local_30 & 0xffffffff);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// dsp_re_show @ 00109b7c size=164
// signature: undefined dsp_re_show(void)
// callers: []
//------------------------------------------------------------

void dsp_re_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  long lVar5;
  uint local_2c;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  local_2c = 0;
  iVar4 = aw882xx_dev_get_cali_re(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68),&local_2c);
  if (iVar4 == 0) {
    iVar4 = snprintf(param_3,0x1000,"%d\n",(ulong)local_2c);
    lVar5 = (long)iVar4;
  }
  else {
    lVar5 = 0x14;
    uVar2 = CONCAT35(s_read_dsp_re_failed__00120123._13_3_,s_read_dsp_re_failed__00120123._8_5_);
    uVar3 = CONCAT53(s_read_dsp_re_failed__00120123._16_5_,s_read_dsp_re_failed__00120123._13_3_);
    *(undefined8 *)param_3 = s_read_dsp_re_failed__00120123._0_8_;
    *(undefined8 *)(param_3 + 8) = uVar2;
    *(undefined8 *)(param_3 + 0xd) = uVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// phase_sync_show @ 00109c24 size=60
// signature: undefined phase_sync_show(void)
// callers: []
//------------------------------------------------------------

long phase_sync_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"sync flag : %d\n",
                   (uint)*(byte *)(*(long *)(param_1 + 0x98) + 0x10));
  return (long)iVar1;
}



//------------------------------------------------------------
// phase_sync_store @ 00109c64 size=184
// signature: undefined phase_sync_store(void)
// callers: []
//------------------------------------------------------------

long phase_sync_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,10,&local_2c);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    plVar3 = *(long **)(lVar4 + 0x48);
    lVar2 = plVar3[0xe];
    local_2c = (uint)(local_2c != 0);
    if (lVar2 == 0) {
      lVar2 = *plVar3;
    }
    _printk(&DAT_00121f52,lVar2,"phase_sync_store");
    *(char *)(lVar4 + 0x10) = (char)local_2c;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// print_dbg_show @ 00109d20 size=56
// signature: undefined print_dbg_show(void)
// callers: []
//------------------------------------------------------------

long print_dbg_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"g_print_dbg : %d\n",g_print_dbg);
  return (long)iVar1;
}



//------------------------------------------------------------
// print_dbg_store @ 00109d5c size=136
// signature: undefined print_dbg_store(void)
// callers: []
//------------------------------------------------------------

long print_dbg_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  iVar1 = kstrtouint(param_3,0,&g_print_dbg);
  if (iVar1 < 0) {
    param_4 = (long)iVar1;
  }
  else {
    plVar2 = *(long **)(lVar3 + 0x48);
    lVar3 = plVar2[0xe];
    g_print_dbg = (uint)(g_print_dbg != 0);
    if (lVar3 == 0) {
      lVar3 = *plVar2;
    }
    _printk(&DAT_0011eaad,lVar3,"print_dbg_store");
  }
  return param_4;
}



//------------------------------------------------------------
// algo_ver_show @ 00109de8 size=192
// signature: undefined algo_ver_show(void)
// callers: []
//------------------------------------------------------------

void algo_ver_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar6 = sp_el0;
  local_28 = *(long *)(lVar6 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  iVar5 = aw882xx_dsp_algo_ver(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68),&local_78);
  uVar4 = s_read_algo_version_failed__00121f80._16_8_;
  uVar3 = s_read_algo_version_failed__00121f80._8_8_;
  uVar2 = s_read_algo_version_failed__00121f80._0_8_;
  if (iVar5 < 0) {
    lVar6 = 0x1a;
    param_3[0x17] = 'd';
    param_3[0x18] = '!';
    param_3[0x19] = '\n';
    param_3[0x1a] = '\0';
    *(undefined8 *)param_3 = uVar2;
    *(undefined8 *)(param_3 + 8) = uVar3;
    *(undefined8 *)(param_3 + 0x10) = uVar4;
  }
  else {
    iVar5 = snprintf(param_3,0x1000,"%s\n",&local_78);
    lVar6 = (long)iVar5;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// vol_offset_show @ 00109eac size=128
// signature: undefined vol_offset_show(void)
// callers: []
//------------------------------------------------------------

long vol_offset_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  aw882xx_dsp_read_vol_offset(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68),&local_2c);
  iVar2 = snprintf(param_3,0x1000,"voltage offset: %d\n",local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// vol_offset_store @ 00109f30 size=240
// signature: undefined vol_offset_store(void)
// callers: []
//------------------------------------------------------------

undefined8 vol_offset_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int local_30 [2];
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_30[0] = 0;
  local_30[1] = 0;
  iVar2 = sscanf(param_3,"%d %d",local_30,(int *)((ulong)local_30 | 4));
  if (iVar2 == 2) {
    iVar2 = 0;
    if (local_30[0] != 0) {
      aw882xx_dsp_write_vol_offset(*(undefined8 *)(lVar4 + 0x68),local_30[1]);
      iVar2 = local_30[0];
    }
    *(int *)(*(long *)(lVar4 + 0x68) + 0x4c) = iVar2;
    *(int *)(*(long *)(lVar4 + 0x68) + 0x50) = local_30[1];
  }
  lVar3 = (*(long **)(lVar4 + 0x48))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(lVar4 + 0x48);
  }
  pcVar1 = "disable";
  if (local_30[0] != 0) {
    pcVar1 = "enable";
  }
  _printk(&DAT_0011ee18,lVar3,"vol_offset_store",pcVar1,local_30[1]);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// algo_state_show @ 0010a024 size=204
// signature: undefined algo_state_show(void)
// callers: []
//------------------------------------------------------------

void algo_state_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  int iVar5;
  long lVar6;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar6 = sp_el0;
  local_28 = *(long *)(lVar6 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  iVar5 = aw882xx_dsp_read_run_state_avg
                    (*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68),&local_a0,0x78);
  uVar4 = s_read_algo_run_state_failed__0011ead7._8_8_;
  if (iVar5 < 0) {
    lVar6 = 0x1c;
    uVar2 = CONCAT35(s_read_algo_run_state_failed__0011ead7._21_3_,
                     s_read_algo_run_state_failed__0011ead7._16_5_);
    uVar3 = CONCAT53(s_read_algo_run_state_failed__0011ead7._24_5_,
                     s_read_algo_run_state_failed__0011ead7._21_3_);
    *(undefined8 *)param_3 = s_read_algo_run_state_failed__0011ead7._0_8_;
    *(undefined8 *)(param_3 + 8) = uVar4;
    *(undefined8 *)(param_3 + 0x10) = uVar2;
    *(undefined8 *)(param_3 + 0x15) = uVar3;
  }
  else {
    iVar5 = snprintf(param_3,0x1000,"%s\n",&local_a0);
    lVar6 = (long)iVar5;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// snd_soc_kcontrol_component @ 0010a0f4 size=8
// signature: undefined snd_soc_kcontrol_component(void)
// callers: [aw882xx_volume_get, aw882xx_get_tx_en, aw882xx_ramp_params_get, aw882xx_algo_auth_tlv_rw, aw882xx_voltage_offset_get, aw882xx_ramp_switch_get, aw882xx_algo_volume_get, aw882xx_ramp_switch_set, aw882xx_get_rx_en, aw882xx_set_spin, aw882xx_get_copp_en, aw882xx_get_spin, aw882xx_ramp_params_put, aw882xx_volume_put, aw882xx_hal_monitor_work_get, aw882xx_monitor_set, aw882xx_set_tx_en, aw882xx_hw_status_get, aw882xx_profile_set, aw882xx_hal_get_monitor_time, aw882xx_iv_output_set, aw882xx_set_copp_en, aw882xx_algo_volume_put, aw882xx_set_rx_en, aw882xx_profile_get, aw882xx_volume_info, aw882xx_switch_set, aw882xx_monitor_get, aw882xx_switch_get, aw882xx_profile_info]
//------------------------------------------------------------

undefined8 snd_soc_kcontrol_component(long param_1)

{
  return *(undefined8 *)(param_1 + 0x80);
}



//------------------------------------------------------------
// snd_soc_component_get_drvdata @ 0010a100 size=12
// signature: undefined snd_soc_component_get_drvdata(void)
// callers: [aw882xx_volume_get, aw882xx_get_tx_en, aw882xx_ramp_params_get, aw882xx_startup, aw882xx_algo_auth_tlv_rw, aw882xx_voltage_offset_get, aw882xx_ramp_switch_get, aw882xx_algo_volume_get, aw882xx_ramp_switch_set, aw882xx_get_rx_en, aw882xx_hw_params, aw882xx_set_spin, aw882xx_get_copp_en, aw882xx_get_spin, aw882xx_mute, aw882xx_ramp_params_put, aw882xx_codec_probe, aw882xx_volume_put, aw882xx_hal_monitor_work_get, aw882xx_monitor_set, aw882xx_set_tx_en, aw882xx_hw_status_get, aw882xx_profile_set, aw882xx_hal_get_monitor_time, aw882xx_iv_output_set, aw882xx_set_copp_en, aw882xx_algo_volume_put, aw882xx_set_rx_en, aw882xx_profile_get, aw882xx_volume_info, aw882xx_switch_set, aw882xx_monitor_get, aw882xx_codec_remove, aw882xx_shutdown, aw882xx_switch_get, aw882xx_profile_info, aw882xx_set_dai_sysclk]
//------------------------------------------------------------

undefined8 snd_soc_component_get_drvdata(long param_1)

{
  return *(undefined8 *)(*(long *)(param_1 + 0x18) + 0x98);
}



//------------------------------------------------------------
// aw_check_sum @ 0010a160 size=316
// signature: undefined aw_check_sum(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_check_sum(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  byte *pbVar8;
  ulong uVar9;
  ulong uVar10;
  int iVar11;
  int iVar12;
  ulong uVar13;
  
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10a29c);
    (*pcVar3)();
  }
  lVar5 = param_1 + (ulong)param_2 * 0x48;
  uVar7 = (ulong)(uint)(*(int *)(lVar5 + 0x48) - *(int *)(lVar5 + 0x14));
  uVar1 = *(int *)(lVar5 + 0x28) + *(int *)(lVar5 + 0x14);
  iVar2 = *(int *)(param_1 + uVar7 + 0x1c38);
  if (uVar1 < 5) {
    iVar12 = 0;
  }
  else {
    uVar9 = (ulong)uVar1 - 4;
    if (uVar9 < 2) {
      iVar12 = 0;
      lVar5 = 4;
    }
    else {
      uVar10 = uVar9 & 0xfffffffffffffffe;
      iVar11 = 0;
      iVar12 = 0;
      lVar5 = uVar10 + 4;
      pbVar8 = (byte *)(uVar7 + param_1 + 0x1c3d);
      uVar13 = uVar10;
      do {
        uVar13 = uVar13 - 2;
        iVar11 = iVar11 + (uint)pbVar8[-1];
        iVar12 = iVar12 + (uint)*pbVar8;
        pbVar8 = pbVar8 + 2;
      } while (uVar13 != 0);
      iVar12 = iVar12 + iVar11;
      if (uVar9 == uVar10) goto LAB_0010a234;
    }
    lVar6 = (ulong)uVar1 - lVar5;
    pbVar8 = (byte *)(lVar5 + uVar7 + param_1 + 0x1c38);
    do {
      lVar6 = lVar6 + -1;
      iVar12 = iVar12 + (uint)*pbVar8;
      pbVar8 = pbVar8 + 1;
    } while (lVar6 != 0);
  }
LAB_0010a234:
  if (iVar12 == iVar2) {
    uVar4 = 0;
  }
  else {
    _printk(&DAT_0011eaf4,"aw_check_sum",0x5c);
    _printk(&DAT_00121c6d,"aw_check_sum",0x5d,param_2,iVar2,iVar12);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// aw_check_data_version @ 0010a2a0 size=92
// signature: undefined aw_check_data_version(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_check_data_version(long param_1,uint param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10a2fc);
    (*pcVar1)();
  }
  if (*(int *)(param_1 + (ulong)param_2 * 0x48 + 0x24) == 1) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_001213c9,"aw_check_data_version",0x70);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_check_register_num_v1 @ 0010a300 size=208
// signature: undefined aw_check_register_num_v1(void)
// callers: [aw_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_register_num_v1(long param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  undefined8 uVar6;
  long lVar7;
  
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10a3d0);
    (*pcVar5)();
  }
  lVar7 = param_1 + (ulong)param_2 * 0x48;
  uVar2 = *(uint *)(lVar7 + 0x48);
  uVar3 = *(int *)(lVar7 + 0x28) - 4;
  uVar1 = *(int *)(lVar7 + 0x3c) + *(int *)(lVar7 + 0x38);
  uVar4 = 0;
  if (uVar1 != 0) {
    uVar4 = uVar3 / uVar1;
  }
  uVar1 = *(uint *)(param_1 + (ulong)uVar2 + 0x1c38);
  if (uVar1 == uVar4) {
    uVar6 = 0;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    *(uint *)(lVar7 + 0x48) = uVar2 + 4;
    *(uint *)(param_1 + 0x4c) = uVar1;
    *(uint *)(param_1 + 0x44) = uVar3;
  }
  else {
    _printk(&DAT_0011e60b,"aw_check_register_num_v1",0x88);
    _printk(&DAT_00123221,"aw_check_register_num_v1",0x89,(ulong)param_2,uVar1,uVar4);
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// aw_check_dsp_reg_num_v1 @ 0010a3d4 size=224
// signature: undefined aw_check_dsp_reg_num_v1(void)
// callers: [aw_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_dsp_reg_num_v1(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  code *pcVar8;
  undefined8 uVar9;
  long lVar10;
  
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10a4b4);
    (*pcVar8)();
  }
  lVar10 = param_1 + (ulong)param_2 * 0x48;
  uVar5 = *(uint *)(lVar10 + 0x48);
  lVar1 = param_1 + (ulong)uVar5;
  uVar6 = *(int *)(lVar10 + 0x28) - 0xc;
  uVar2 = *(uint *)(lVar1 + 0x1c40);
  uVar3 = *(uint *)(lVar1 + 0x1c3c);
  uVar7 = 0;
  if (uVar2 != 0) {
    uVar7 = uVar6 / uVar2;
  }
  *(uint *)(lVar10 + 0x50) = uVar2;
  if (uVar3 == uVar7) {
    uVar9 = 0;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    uVar4 = *(undefined4 *)(lVar1 + 0x1c38);
    *(uint *)(lVar10 + 0x48) = uVar5 + 0xc;
    *(uint *)(param_1 + 0x4c) = uVar3;
    *(uint *)(param_1 + 0x44) = uVar6;
    *(undefined4 *)(param_1 + 0x54) = uVar4;
  }
  else {
    _printk(&DAT_0011f211,"aw_check_dsp_reg_num_v1",0xac);
    _printk(&DAT_0011de3f,"aw_check_dsp_reg_num_v1",0xad,(ulong)param_2,uVar3,uVar7);
    uVar9 = 0xffffffea;
  }
  return uVar9;
}



//------------------------------------------------------------
// aw_check_soc_app_num_v1 @ 0010a4b8 size=220
// signature: undefined aw_check_soc_app_num_v1(void)
// callers: [aw_parsing_bin_file]
//------------------------------------------------------------

undefined8 aw_check_soc_app_num_v1(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  code *pcVar6;
  undefined8 uVar7;
  long lVar8;
  
  if (99 < param_2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x10a594);
    (*pcVar6)();
  }
  lVar8 = param_1 + (ulong)param_2 * 0x48;
  uVar4 = *(uint *)(lVar8 + 0x48);
  lVar1 = param_1 + (ulong)uVar4;
  iVar5 = *(int *)(lVar8 + 0x28) + -0xc;
  *(undefined4 *)(lVar8 + 0x58) = *(undefined4 *)(lVar1 + 0x1c38);
  iVar2 = *(int *)(lVar1 + 0x1c40);
  if (iVar2 == iVar5) {
    uVar7 = 0;
    param_1 = param_1 + (ulong)param_2 * 0x48;
    *(int *)(param_1 + 0x4c) = iVar2;
    uVar3 = *(undefined4 *)(lVar1 + 0x1c3c);
    *(int *)(param_1 + 0x44) = iVar2;
    *(uint *)(lVar8 + 0x48) = uVar4 + 0xc;
    *(undefined4 *)(param_1 + 0x54) = uVar3;
  }
  else {
    _printk(&DAT_0011d6fd,"aw_check_soc_app_num_v1",0xd4);
    _printk(&DAT_0012142d,"aw_check_soc_app_num_v1",0xd5,(ulong)param_2,iVar2,iVar5);
    uVar7 = 0xffffffea;
  }
  return uVar7;
}



//------------------------------------------------------------
// aw_get_single_bin_header_1_0_0 @ 0010a598 size=220
// signature: undefined aw_get_single_bin_header_1_0_0(void)
// callers: [aw_parse_bin_header_1_0_0, aw_get_multi_bin_header_1_0_0]
//------------------------------------------------------------

void aw_get_single_bin_header_1_0_0(long *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  code *pcVar4;
  long lVar5;
  undefined4 *puVar6;
  
  uVar1 = *(uint *)(param_1 + 1);
  if (uVar1 < 100) {
    puVar6 = (undefined4 *)*param_1;
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x14) = 0x3c;
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 3) = *puVar6;
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x1c) = puVar6[1];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 4) = puVar6[2];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x24) = puVar6[3];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 5) = puVar6[4];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x2c) = puVar6[5];
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 7) = puVar6[8];
    *(undefined4 *)((long)param_1 + (ulong)uVar1 * 0x48 + 0x3c) = puVar6[9];
    uVar2 = *(uint *)(param_1 + 1);
    *(undefined4 *)(param_1 + (ulong)uVar1 * 9 + 8) = puVar6[10];
    if (uVar2 < 100) {
      lVar5 = *param_1;
      *(undefined1 *)(param_1 + (ulong)uVar2 * 9 + 6) = *(undefined1 *)(lVar5 + 0x18);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x31) = *(undefined1 *)(lVar5 + 0x19);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x32) = *(undefined1 *)(lVar5 + 0x1a);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x33) = *(undefined1 *)(lVar5 + 0x1b);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x34) = *(undefined1 *)(lVar5 + 0x1c);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x35) = *(undefined1 *)(lVar5 + 0x1d);
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x36) = *(undefined1 *)(lVar5 + 0x1e);
      uVar3 = *(undefined1 *)(lVar5 + 0x1f);
      *(undefined4 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x44) = 0;
      *(undefined8 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x54) = 0;
      *(undefined8 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x4c) = 0;
      *(undefined1 *)((long)param_1 + (ulong)uVar2 * 0x48 + 0x37) = uVar3;
      *(uint *)(param_1 + 1) = uVar2 + 1;
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10a674);
  (*pcVar4)();
}



//------------------------------------------------------------
// aw_parse_each_of_multi_bins_1_0_0 @ 0010a678 size=184
// signature: undefined aw_parse_each_of_multi_bins_1_0_0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_parse_each_of_multi_bins_1_0_0(int param_1,int param_2,long *param_3)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  
  if (param_2 == 0) {
    uVar4 = *(uint *)(param_3 + 1);
    *param_3 = *param_3 + (ulong)(*(int *)(*param_3 + 0x40) + 0x3c);
    if (uVar4 - 1 < 99) {
      iVar5 = (int)param_3[(ulong)(uVar4 - 1) * 9 + 9] + param_1 * 8 + 0x40;
LAB_0010a708:
      *(int *)(param_3 + (ulong)uVar4 * 9 + 9) = iVar5;
      aw_parse_bin_header_1_0_0(param_3);
      return 0;
    }
  }
  else {
    uVar4 = *(uint *)(param_3 + 1);
    uVar2 = uVar4 - 1;
    if (uVar2 < 100) {
      uVar1 = (int)param_3[(ulong)uVar2 * 9 + 5] + 0x3c;
      *param_3 = *param_3 + (ulong)uVar1;
      if (uVar4 < 100) {
        iVar5 = uVar1 + (int)param_3[(ulong)uVar2 * 9 + 9];
        goto LAB_0010a708;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10a730);
  (*pcVar3)();
}



//------------------------------------------------------------
// aw_parse_bin_header_1_0_0 @ 0010a730 size=488
// signature: undefined aw_parse_bin_header_1_0_0(void)
// callers: [aw_parsing_bin_file, aw_parse_each_of_multi_bins_1_0_0, aw_parse_bin_header_1_0_0, aw_get_multi_bin_header_1_0_0]
//------------------------------------------------------------

void aw_parse_bin_header_1_0_0(long *param_1)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  code *pcVar9;
  long lVar10;
  int iVar11;
  
  lVar10 = *param_1;
  uVar1 = *(uint *)(lVar10 + 8);
  if (uVar1 < 0x22 && (1L << ((ulong)uVar1 & 0x3f) & 0x200010001U) != 0) {
    *(int *)(param_1 + 2) = (int)param_1[2] + 1;
    if (*(int *)((long)param_1 + 0xc) == 0) {
      if (99 < *(uint *)(param_1 + 1)) {
LAB_0010a914:
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x10a918);
        (*pcVar9)();
      }
      *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) = 0x3c;
    }
    aw_get_single_bin_header_1_0_0(param_1);
  }
  else if (uVar1 == 0x2000) {
    iVar11 = *(int *)((long)param_1 + 0xc);
    *(int *)((long)param_1 + 0xc) = iVar11 + 1;
    bVar2 = *(byte *)(lVar10 + 0x3f);
    bVar3 = *(byte *)(lVar10 + 0x3e);
    bVar4 = *(byte *)(lVar10 + 0x3d);
    bVar5 = *(byte *)(lVar10 + 0x3c);
    uVar8 = *(ushort *)(lVar10 + 0x3c);
    if (iVar11 == 0) {
      if (99 < *(uint *)(param_1 + 1)) goto LAB_0010a914;
      *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) = 0x3c;
    }
    uVar1 = (uint)bVar2 * 0x1000000;
    uVar6 = uVar1 | (uint)bVar3 << 0x10 | (uint)bVar4 << 8 | (uint)bVar5;
    aw_get_single_bin_header_1_0_0(param_1);
    if (uVar6 != 0) {
      uVar7 = *(uint *)(param_1 + 1) - 1;
      *param_1 = *param_1 + (ulong)(*(int *)(*param_1 + 0x40) + 0x3c);
      if (0x62 < uVar7) goto LAB_0010a914;
      *(uint *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) =
           (int)param_1[(ulong)uVar7 * 9 + 9] + uVar6 * 8 + 0x40;
      aw_parse_bin_header_1_0_0(param_1);
      if (uVar6 != 1) {
        iVar11 = uVar1 + (uint)bVar3 * 0x10000 + (uint)uVar8 + -1;
        do {
          uVar1 = *(uint *)(param_1 + 1);
          uVar6 = uVar1 - 1;
          if (99 < uVar6) goto LAB_0010a914;
          uVar7 = (int)param_1[(ulong)uVar6 * 9 + 5] + 0x3c;
          *param_1 = *param_1 + (ulong)uVar7;
          if (99 < uVar1) goto LAB_0010a914;
          *(uint *)(param_1 + (ulong)uVar1 * 9 + 9) = (int)param_1[(ulong)uVar6 * 9 + 9] + uVar7;
          aw_parse_bin_header_1_0_0(param_1);
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
      }
    }
  }
  else {
    _printk(&DAT_00121f9b,"aw_parse_bin_header_1_0_0",0x180);
  }
  return;
}



//------------------------------------------------------------
// aw_get_multi_bin_header_1_0_0 @ 0010a91c size=356
// signature: undefined aw_get_multi_bin_header_1_0_0(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_get_multi_bin_header_1_0_0(long *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ushort uVar8;
  code *pcVar9;
  long lVar10;
  int iVar11;
  
  lVar10 = *param_1;
  bVar1 = *(byte *)(lVar10 + 0x3f);
  bVar2 = *(byte *)(lVar10 + 0x3e);
  bVar3 = *(byte *)(lVar10 + 0x3d);
  bVar4 = *(byte *)(lVar10 + 0x3c);
  uVar8 = *(ushort *)(lVar10 + 0x3c);
  if (*(int *)((long)param_1 + 0xc) == 1) {
    if (99 < *(uint *)(param_1 + 1)) goto LAB_0010aa7c;
    *(undefined4 *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) = 0x3c;
  }
  uVar5 = (uint)bVar1 * 0x1000000;
  uVar6 = uVar5 | (uint)bVar2 << 0x10 | (uint)bVar3 << 8 | (uint)bVar4;
  aw_get_single_bin_header_1_0_0(param_1);
  if (uVar6 != 0) {
    uVar7 = *(uint *)(param_1 + 1) - 1;
    *param_1 = *param_1 + (ulong)(*(int *)(*param_1 + 0x40) + 0x3c);
    if (0x62 < uVar7) {
LAB_0010aa7c:
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x10aa80);
      (*pcVar9)();
    }
    *(uint *)(param_1 + (ulong)*(uint *)(param_1 + 1) * 9 + 9) =
         (int)param_1[(ulong)uVar7 * 9 + 9] + uVar6 * 8 + 0x40;
    aw_parse_bin_header_1_0_0(param_1);
    if (uVar6 != 1) {
      iVar11 = uVar5 + (uint)bVar2 * 0x10000 + (uint)uVar8 + -1;
      do {
        uVar5 = *(uint *)(param_1 + 1);
        uVar6 = uVar5 - 1;
        if (99 < uVar6) goto LAB_0010aa7c;
        uVar7 = (int)param_1[(ulong)uVar6 * 9 + 5] + 0x3c;
        *param_1 = *param_1 + (ulong)uVar7;
        if (99 < uVar5) goto LAB_0010aa7c;
        *(uint *)(param_1 + (ulong)uVar5 * 9 + 9) = (int)param_1[(ulong)uVar6 * 9 + 9] + uVar7;
        aw_parse_bin_header_1_0_0(param_1);
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_parse_check_acf @ 0010aa84 size=1068
// signature: undefined aw882xx_dev_parse_check_acf(void)
// callers: [aw882xx_request_firmware]
//------------------------------------------------------------

undefined8 aw882xx_dev_parse_check_acf(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  char *pcVar5;
  ulong uVar6;
  uint uVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  uint *puVar13;
  
  if (param_1 == (uint *)0x0) {
    _printk(&DAT_0011f251,"aw882xx_dev_parse_check_acf");
    return 0xfffffff4;
  }
  uVar7 = *param_1;
  if (uVar7 < 0x50) {
    puVar4 = &DAT_00121497;
    pcVar5 = "aw882xx_dev_parse_check_acf";
    uVar6 = (ulong)uVar7;
    uVar7 = 0x50;
    goto LAB_0010ad70;
  }
  if (param_1[0x11] == 0x1000000) {
    puVar13 = param_1 + 1;
    if (*puVar13 != 0xa15f908) {
      _printk(&DAT_0011cc83,"aw_dev_parse_check_acf_by_hdr_v_1_0_0_0");
      return 0xffffffea;
    }
    uVar8 = (ulong)param_1[0x10];
    uVar12 = param_1[0xe] + param_1[0x10];
    uVar6 = (ulong)uVar12;
    if (uVar12 <= uVar7) {
      uVar2 = param_1[0xf];
      if (uVar2 == 0) {
        if (uVar12 != uVar7) goto LAB_0010aca0;
      }
      else {
        if ((uVar2 == 1) || ((int)(uVar2 - 1) < 0)) {
          uVar3 = 0;
          goto LAB_0010ac10;
        }
        uVar11 = 0;
        iVar9 = 0;
        uVar3 = uVar2 & 0xfffffffe;
        do {
          iVar1 = uVar11 + 1;
          lVar10 = (long)(int)uVar11;
          uVar11 = uVar11 + 2;
          uVar12 = *(int *)((long)puVar13 + lVar10 * 0x60 + uVar8 + 0x20) + (int)uVar6;
          uVar6 = (ulong)uVar12;
          iVar9 = *(int *)((long)puVar13 + (long)iVar1 * 0x60 + uVar8 + 0x20) + iVar9;
        } while (uVar3 != uVar11);
        uVar12 = iVar9 + uVar12;
        for (; uVar6 = (ulong)uVar12, uVar2 != uVar3; uVar3 = uVar3 + 1) {
LAB_0010ac10:
          uVar12 = *(int *)((long)puVar13 + (long)(int)uVar3 * 0x60 + uVar8 + 0x20) + uVar12;
        }
        if (uVar12 != uVar7) {
LAB_0010aca0:
          puVar4 = &DAT_0012351d;
          pcVar5 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
          goto LAB_0010ad70;
        }
        uVar12 = 0;
        do {
          lVar10 = (long)(int)uVar12 * 0x60 + uVar8;
          uVar11 = *(uint *)((long)puVar13 + lVar10 + 0x24);
          uVar3 = *(int *)((long)puVar13 + lVar10 + 0x20) + uVar11;
          if (uVar7 < uVar3) {
            pcVar5 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
            goto LAB_0010ae8c;
          }
          uVar3 = aw_dev_parse_crc8_check((long)puVar13 + (ulong)uVar11);
          uVar11 = *(uint *)((long)puVar13 + lVar10 + 0x28);
          uVar3 = uVar3 & 0xff;
          if (uVar11 != uVar3) {
            puVar4 = &DAT_001218eb;
            pcVar5 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
            goto LAB_0010aea8;
          }
          uVar12 = uVar12 + 1;
        } while (uVar2 != uVar12);
      }
      pcVar5 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
      goto LAB_0010ae0c;
    }
    pcVar5 = "aw_dev_parse_check_acf_by_hdr_v_1_0_0_0";
    uVar6 = uVar8;
  }
  else {
    if (param_1[0x11] != 1) {
      _printk(&DAT_0011d3ae,"aw882xx_dev_parse_check_acf");
      return 0xffffffea;
    }
    puVar13 = param_1 + 1;
    if (*puVar13 != 0xa15f908) {
      _printk(&DAT_0011cc83,"aw_dev_parse_check_acf_by_hdr");
      return 0xffffffea;
    }
    uVar8 = (ulong)param_1[0x10];
    uVar12 = param_1[0xe] + param_1[0x10];
    uVar6 = (ulong)uVar12;
    if (uVar12 <= uVar7) {
      uVar2 = param_1[0xf];
      if (uVar2 == 0) {
        if (uVar12 == uVar7) goto LAB_0010adf8;
      }
      else {
        if ((uVar2 != 1) && (-1 < (int)(uVar2 - 1))) {
          uVar12 = 0;
          iVar9 = 0;
          uVar3 = uVar2 & 0xfffffffe;
          do {
            iVar1 = uVar12 + 1;
            lVar10 = (long)(int)uVar12;
            uVar12 = uVar12 + 2;
            uVar11 = *(int *)((long)puVar13 + lVar10 * 0x40 + uVar8 + 0x20) + (int)uVar6;
            uVar6 = (ulong)uVar11;
            iVar9 = *(int *)((long)puVar13 + (long)iVar1 * 0x40 + uVar8 + 0x20) + iVar9;
            if (uVar3 == uVar12) goto LAB_0010ada4;
          } while( true );
        }
        uVar3 = 0;
        do {
          uVar11 = (uint)uVar6;
          lVar10 = (long)(int)uVar3;
          uVar3 = uVar3 + 1;
          iVar9 = *(int *)((long)puVar13 + lVar10 * 0x40 + uVar8 + 0x20);
LAB_0010ada4:
          uVar6 = (ulong)(iVar9 + uVar11);
        } while (uVar2 != uVar3);
        if (iVar9 + uVar11 == uVar7) {
          uVar12 = 0;
          do {
            lVar10 = (long)(int)uVar12 * 0x40 + uVar8;
            uVar11 = *(uint *)((long)puVar13 + lVar10 + 0x24);
            uVar3 = *(int *)((long)puVar13 + lVar10 + 0x20) + uVar11;
            if (uVar7 < uVar3) {
              pcVar5 = "aw_dev_parse_check_acf_by_hdr";
LAB_0010ae8c:
              puVar4 = &DAT_00120ecf;
              uVar11 = uVar7;
LAB_0010aea8:
              _printk(puVar4,pcVar5,uVar12,uVar3,uVar11);
              return 0xffffffea;
            }
            uVar3 = aw_dev_parse_crc8_check((long)puVar13 + (ulong)uVar11);
            uVar11 = *(uint *)((long)puVar13 + lVar10 + 0x28);
            uVar3 = uVar3 & 0xff;
            if (uVar11 != uVar3) {
              puVar4 = &DAT_001218eb;
              pcVar5 = "aw_dev_parse_check_acf_by_hdr";
              goto LAB_0010aea8;
            }
            uVar12 = uVar12 + 1;
          } while (uVar2 != uVar12);
LAB_0010adf8:
          pcVar5 = "aw_dev_parse_check_acf_by_hdr";
LAB_0010ae0c:
          _printk(&DAT_00122272,pcVar5,param_1 + 2);
          _printk(&DAT_0011cf3f,pcVar5,param_1 + 8);
          _printk(&DAT_001237af,pcVar5,*(undefined1 *)((long)param_1 + 0x33),
                  *(undefined1 *)((long)param_1 + 0x32),*(undefined1 *)((long)param_1 + 0x31),
                  (char)param_1[0xc]);
          _printk(&DAT_0011f5f9,pcVar5,param_1[0xd]);
          return 0;
        }
      }
      puVar4 = &DAT_0012351d;
      pcVar5 = "aw_dev_parse_check_acf_by_hdr";
      goto LAB_0010ad70;
    }
    pcVar5 = "aw_dev_parse_check_acf_by_hdr";
    uVar6 = uVar8;
  }
  puVar4 = &DAT_001214ec;
LAB_0010ad70:
  _printk(puVar4,pcVar5,uVar6,uVar7);
  return 0xffffffea;
}



//------------------------------------------------------------
// aw_dev_dsp_data_order @ 0010aeb4 size=68
// signature: undefined aw_dev_dsp_data_order(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_dev_dsp_data_order(undefined8 param_1,long param_2,uint param_3)

{
  int iVar1;
  undefined1 uVar2;
  uint uVar3;
  long lVar4;
  
  if ((param_3 & 1) != 0) {
    return 0xffffffea;
  }
  if (param_3 != 0) {
    uVar3 = 0;
    do {
      iVar1 = uVar3 + 1;
      lVar4 = (long)(int)uVar3;
      uVar3 = uVar3 + 2;
      uVar2 = *(undefined1 *)(param_2 + iVar1);
      *(undefined1 *)(param_2 + iVar1) = *(undefined1 *)(param_2 + lVar4);
      *(undefined1 *)(param_2 + lVar4) = uVar2;
    } while (uVar3 < param_3);
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_parse_acf @ 0010aefc size=4488
// signature: undefined aw882xx_dev_parse_acf(void)
// callers: [aw882xx_dev_init]
//------------------------------------------------------------

int aw882xx_dev_parse_acf(long param_1,long param_2)

{
  uint *puVar1;
  undefined8 *puVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  code *pcVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  long *plVar12;
  long lVar13;
  long lVar14;
  char *pcVar15;
  ulong uVar16;
  long lVar17;
  uint uVar18;
  ulong uVar19;
  int iVar20;
  uint uVar21;
  int *piVar22;
  ulong uVar23;
  long lVar24;
  uint uVar25;
  uint uVar26;
  long lVar27;
  long lVar28;
  undefined8 *puVar29;
  int local_5f0 [16];
  int local_5b0;
  int local_570;
  int local_530;
  int local_4f0;
  int local_4b0;
  int local_470;
  int local_430;
  int local_3f0;
  int local_3b0;
  int local_370;
  uint local_330 [10];
  long local_308 [83];
  long local_70;
  
  lVar17 = sp_el0;
  local_70 = *(long *)(lVar17 + 0x638);
  puVar29 = (undefined8 *)(param_1 + 0x78);
  lVar17 = ((long *)*puVar29)[0xe];
  if (lVar17 == 0) {
    lVar17 = *(long *)*puVar29;
  }
  _printk(&DAT_00120075,lVar17,"aw882xx_dev_parse_acf");
  lVar17 = ((long *)*puVar29)[0xe];
  if (lVar17 == 0) {
    lVar17 = *(long *)*puVar29;
  }
  _printk(&DAT_00120963,lVar17,"aw882xx_dev_parse_acf",*(undefined4 *)(param_2 + 0x44));
  if (*(int *)(param_2 + 0x44) == 0x1000000) {
    uVar18 = *(uint *)(param_2 + 0x3c);
    lVar17 = param_2 + 4;
    if (uVar18 == 0) {
      if (*(int *)(param_1 + 0x278) == 0) goto LAB_0010bd64;
LAB_0010b1d8:
      bVar7 = false;
    }
    else {
      uVar25 = 0;
      lVar13 = lVar17 + (ulong)*(uint *)(param_2 + 0x40);
      do {
        piVar22 = (int *)(lVar13 + (long)(int)uVar25 * 0x60);
        if (((((piVar22[7] | 4U) == 4) && (*piVar22 == 0)) &&
            (*(uint *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x408) ==
             (uint)*(ushort *)((long)piVar22 + 0x16))) &&
           ((*(short *)(*(long *)(param_1 + 0x80) + 2) == (short)piVar22[6] &&
            (*(int *)(param_1 + 4) == piVar22[0x13])))) {
          *(int *)(param_1 + 0x278) = *(int *)(param_1 + 0x278) + 1;
          uVar18 = *(uint *)(param_2 + 0x3c);
        }
        uVar25 = uVar25 + 1;
      } while (uVar25 < uVar18);
      if (*(int *)(param_1 + 0x278) != 0) goto LAB_0010b1d8;
      if (uVar18 == 0) {
LAB_0010bd64:
        lVar17 = ((long *)*puVar29)[0xe];
        if (lVar17 == 0) {
          lVar17 = *(long *)*puVar29;
        }
        _printk(&DAT_0011fe7b,lVar17,"aw_dev_parse_get_scene_count_v1_0_0_0");
        lVar17 = ((long *)*puVar29)[0xe];
        if (lVar17 == 0) {
          lVar17 = *(long *)*puVar29;
        }
        _printk(&DAT_001219bc,lVar17,"aw_dev_parse_acf_by_hdr_v_1_0_0_0");
        goto LAB_0010bdac;
      }
      iVar20 = 0;
      bVar7 = false;
      uVar25 = 0;
      do {
        piVar22 = (int *)(lVar13 + (long)(int)uVar25 * 0x60);
        if ((((piVar22[7] | 4U) == 4) && (*piVar22 == 2)) &&
           ((*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5) &&
            (*(int *)(param_1 + 4) == piVar22[0x13])))) {
          iVar20 = iVar20 + 1;
          bVar7 = true;
          *(int *)(param_1 + 0x278) = iVar20;
          uVar18 = *(uint *)(param_2 + 0x3c);
        }
        uVar25 = uVar25 + 1;
      } while (uVar25 < uVar18);
      if (iVar20 == 0) {
        if (uVar18 != 0) {
          iVar20 = 0;
          uVar25 = 0;
          do {
            piVar22 = (int *)(lVar13 + (long)(int)uVar25 * 0x60);
            if ((((piVar22[7] == 7) && (*piVar22 == 0)) &&
                (*(uint *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x408) ==
                 (uint)*(ushort *)((long)piVar22 + 0x16))) &&
               ((*(short *)(*(long *)(param_1 + 0x80) + 2) == (short)piVar22[6] &&
                (*(int *)(param_1 + 4) == piVar22[0x13])))) {
              iVar20 = iVar20 + 1;
              bVar7 = false;
              *(int *)(param_1 + 0x278) = iVar20;
              uVar18 = *(uint *)(param_2 + 0x3c);
            }
            uVar25 = uVar25 + 1;
          } while (uVar25 < uVar18);
          if (iVar20 != 0) goto LAB_0010b1dc;
          if (uVar18 != 0) {
            iVar20 = 0;
            uVar25 = 0;
            do {
              piVar22 = (int *)(lVar13 + (long)(int)uVar25 * 0x60);
              if (((piVar22[7] == 7) && (*piVar22 == 2)) &&
                 ((*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5) &&
                  (*(int *)(param_1 + 4) == piVar22[0x13])))) {
                iVar20 = iVar20 + 1;
                bVar7 = true;
                *(int *)(param_1 + 0x278) = iVar20;
                uVar18 = *(uint *)(param_2 + 0x3c);
              }
              uVar25 = uVar25 + 1;
            } while (uVar25 < uVar18);
            if (iVar20 != 0) goto LAB_0010b1dc;
          }
        }
        goto LAB_0010bd64;
      }
    }
LAB_0010b1dc:
    lVar13 = ((long *)*puVar29)[0xe];
    if (lVar13 == 0) {
      lVar13 = *(long *)*puVar29;
    }
    _printk(&DAT_00121cc6,lVar13,"aw_dev_parse_get_scene_count_v1_0_0_0");
    lVar13 = devm_kmalloc(*(undefined8 *)(param_1 + 0x78),(ulong)*(uint *)(param_1 + 0x278) << 6,
                          0xdc0);
    *(long *)(param_1 + 0x288) = lVar13;
    if (lVar13 != 0) {
      local_308[10] = 0;
      local_308[9] = 0;
      lVar13 = ((long *)*puVar29)[0xe];
      local_308[8] = 0;
      local_308[7] = 0;
      local_308[6] = 0;
      local_308[5] = 0;
      local_308[4] = 0;
      local_308[3] = 0;
      local_308[2] = 0;
      local_308[1] = 0;
      local_308[0] = 0;
      local_330[8] = 0;
      local_330[9] = 0;
      local_330[6] = 0;
      local_330[7] = 0;
      local_330[4] = 0;
      local_330[5] = 0;
      local_330[2] = 0;
      local_330[3] = 0;
      local_330[0] = 0;
      local_330[1] = 0;
      if (lVar13 == 0) {
        lVar13 = *(long *)*puVar29;
      }
      uVar18 = *(uint *)(param_2 + 0x40);
      _printk(&DAT_00120075,lVar13,"aw_dev_parse_scene_v_1_0_0_0");
      uVar25 = *(uint *)(param_2 + 0x3c);
      if (uVar25 != 0) {
        uVar26 = 0;
        uVar16 = 0;
        lVar13 = lVar17 + (ulong)uVar18;
LAB_0010b614:
        piVar22 = (int *)(lVar13 + (long)(int)uVar26 * 0x60);
        if (!bVar7) {
          if ((*piVar22 != 0) ||
             ((*(uint *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x408) !=
               (uint)*(ushort *)((long)piVar22 + 0x16) ||
              (*(short *)(*(long *)(param_1 + 0x80) + 2) != (short)piVar22[6])))) goto LAB_0010b608;
LAB_0010b638:
          if (*(int *)(param_1 + 4) != piVar22[0x13]) goto LAB_0010b608;
          iVar20 = (int)uVar16;
          if (iVar20 == 0) goto LAB_0010b740;
          uVar19 = 0;
          uVar23 = uVar16;
          do {
            if (uVar19 == 0x20) goto LAB_0010c07c;
            if ((uVar19 & 0x3fffffffffffffff) == 0x20) goto LAB_0010c078;
            uVar18 = (uint)uVar23;
            if (*(ushort *)((long)piVar22 + 0x1a) <=
                *(ushort *)(lVar13 + (ulong)local_330[uVar19] * 0x60 + 0x1a)) {
              if (uVar18 < 2) {
                uVar18 = 1;
              }
              uVar23 = (ulong)uVar18;
              goto LAB_0010b6d8;
            }
            uVar19 = uVar19 + 1;
            uVar23 = (ulong)(uVar18 - 1);
          } while (uVar16 != uVar19);
          uVar19 = uVar16;
          goto LAB_0010b72c;
        }
        if ((*piVar22 == 2) && (*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5)))
        goto LAB_0010b638;
        goto LAB_0010b608;
      }
      goto LAB_0010b85c;
    }
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    _printk(&DAT_0011e30c,lVar17,"aw_dev_parse_acf_by_hdr_v_1_0_0_0");
    iVar9 = -0xc;
  }
  else {
    if (*(int *)(param_2 + 0x44) != 1) {
      _printk(&DAT_0011d3ae,"aw882xx_dev_parse_acf");
      iVar9 = -0x16;
      goto LAB_0010bdd8;
    }
    lVar17 = param_2 + 4;
    memset(local_330,0,0x2c0);
    lVar13 = ((long *)*puVar29)[0xe];
    if (lVar13 == 0) {
      lVar13 = *(long *)*puVar29;
    }
    uVar18 = *(uint *)(param_2 + 0x40);
    _printk(&DAT_00120075,lVar13,"aw_dev_parse_dev_type");
    if (*(int *)(param_2 + 0x3c) == 0) {
LAB_0010b24c:
      lVar13 = ((long *)*puVar29)[0xe];
      if (lVar13 == 0) {
        lVar13 = *(long *)*puVar29;
      }
      _printk(&DAT_0012070c,lVar13,"aw_dev_parse_dev_type",0);
      lVar13 = ((long *)*puVar29)[0xe];
      if (lVar13 == 0) {
        lVar13 = *(long *)*puVar29;
      }
      _printk(&DAT_0011f270,lVar13,"aw_dev_parse_acf_by_hdr");
      lVar13 = ((long *)*puVar29)[0xe];
      if (lVar13 == 0) {
        lVar13 = *(long *)*puVar29;
      }
      uVar18 = *(uint *)(param_2 + 0x40);
      _printk(&DAT_00120075,lVar13,"aw_dev_parse_dev_default_type");
      uVar25 = *(uint *)(param_2 + 0x3c);
      if (uVar25 != 0) {
        uVar26 = 0;
        iVar20 = 0;
        do {
          piVar22 = (int *)(lVar17 + (ulong)uVar18 + (long)(int)uVar26 * 0x40);
          if ((*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5)) && (*piVar22 == 2)) {
            if (piVar22[7] == 10) {
              iVar9 = aw_dev_parse_data_by_sec_type(param_1,lVar17,piVar22,0);
              if (-1 < iVar9) {
LAB_0010b2f4:
                iVar20 = iVar20 + 1;
                uVar25 = *(uint *)(param_2 + 0x3c);
                goto LAB_0010b2fc;
              }
              lVar17 = ((long *)*puVar29)[0xe];
              if (lVar17 == 0) {
                lVar17 = *(long *)*puVar29;
              }
              puVar11 = &DAT_00122d75;
            }
            else {
              iVar9 = aw_dev_parse_data_by_sec_type
                                (param_1,lVar17,piVar22,
                                 local_330 + (ulong)*(ushort *)((long)piVar22 + 0x1a) * 0x10);
              if (-1 < iVar9) goto LAB_0010b2f4;
              lVar17 = ((long *)*puVar29)[0xe];
              if (lVar17 == 0) {
                lVar17 = *(long *)*puVar29;
              }
              puVar11 = &DAT_0011ee63;
            }
            _printk(puVar11,lVar17,"aw_dev_parse_dev_default_type");
            goto LAB_0010bdb0;
          }
LAB_0010b2fc:
          uVar26 = uVar26 + 1;
        } while (uVar26 < uVar25);
        if (iVar20 != 0) goto LAB_0010b39c;
      }
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      _printk(&DAT_0011fb98,lVar17,"aw_dev_parse_dev_default_type",0);
LAB_0010bdac:
      iVar9 = -0x16;
    }
    else {
      uVar25 = 0;
      iVar20 = 0;
      do {
        piVar22 = (int *)(lVar17 + (ulong)uVar18 + (long)(int)uVar25 * 0x40);
        if (((*(uint *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x408) ==
              (uint)*(ushort *)((long)piVar22 + 0x16)) &&
            (*(short *)(*(long *)(param_1 + 0x80) + 2) == (short)piVar22[6])) && (*piVar22 == 0)) {
          if (piVar22[7] == 10) {
            iVar9 = aw_dev_parse_data_by_sec_type(param_1,lVar17,piVar22,0);
            if (-1 < iVar9) goto LAB_0010b00c;
            lVar17 = ((long *)*puVar29)[0xe];
            if (lVar17 == 0) {
              lVar17 = *(long *)*puVar29;
            }
            puVar11 = &DAT_00122d75;
          }
          else {
            iVar9 = aw_dev_parse_data_by_sec_type
                              (param_1,lVar17,piVar22,
                               local_330 + (ulong)*(ushort *)((long)piVar22 + 0x1a) * 0x10);
            if (-1 < iVar9) {
LAB_0010b00c:
              iVar20 = iVar20 + 1;
              goto LAB_0010b010;
            }
            lVar17 = ((long *)*puVar29)[0xe];
            if (lVar17 == 0) {
              lVar17 = *(long *)*puVar29;
            }
            puVar11 = &DAT_0011ee63;
          }
          _printk(puVar11,lVar17,"aw_dev_parse_dev_type");
          goto LAB_0010bdb0;
        }
LAB_0010b010:
        uVar25 = uVar25 + 1;
      } while (uVar25 < *(uint *)(param_2 + 0x3c));
      if (iVar20 == 0) goto LAB_0010b24c;
LAB_0010b39c:
      lVar13 = ((long *)*puVar29)[0xe];
      if (lVar13 == 0) {
        lVar13 = *(long *)*puVar29;
      }
      uVar18 = *(uint *)(param_2 + 0x40);
      _printk(&DAT_00120075,lVar13,"aw_dev_parse_skt_type");
      uVar25 = *(uint *)(param_2 + 0x3c);
      if (uVar25 == 0) {
        iVar20 = 0;
      }
      else {
        uVar26 = 0;
        iVar20 = 0;
        do {
          piVar22 = (int *)(lVar17 + (ulong)uVar18 + (long)(int)uVar26 * 0x40);
          if (((*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5)) && (*piVar22 == 1)) &&
             (piVar22[7] == 1)) {
            lVar13 = ((long *)*puVar29)[0xe];
            if (lVar13 == 0) {
              lVar13 = *(long *)*puVar29;
            }
            uVar21 = piVar22[8];
            uVar25 = piVar22[9];
            uVar16 = (ulong)*(ushort *)((long)piVar22 + 0x1a);
            _printk(&DAT_00122293,lVar13,"aw_dev_parse_raw_dsp",uVar21);
            if ((0x2c0 < (uVar16 << 6 | 0x28)) || (0x2c0 < (uVar16 << 6 | 0x28))) {
LAB_0010c078:
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(1,0x10c07c);
              (*pcVar8)();
            }
            local_308[uVar16 * 8] = lVar17 + (ulong)uVar25;
            if ((0x2c0 < (uVar16 * 0x40 | 0x20)) || (0x2c0 < (uVar16 << 6 | 0x20)))
            goto LAB_0010c078;
            iVar20 = iVar20 + 1;
            uVar25 = *(uint *)(param_2 + 0x3c);
            local_330[uVar16 * 0x10 + 8] = uVar21;
          }
          uVar26 = uVar26 + 1;
        } while (uVar26 < uVar25);
      }
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      _printk(&DAT_0011d412,lVar17,"aw_dev_parse_skt_type",iVar20);
      memcpy(local_5f0,local_330,0x2c0);
      puVar1 = (uint *)(param_1 + 0x278);
      if (local_5f0[0] == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_5b0 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_570 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_530 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_4f0 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_4b0 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_470 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_430 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_3f0 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_3b0 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      if (local_370 == 1) {
        *puVar1 = *puVar1 + 1;
      }
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      _printk(&DAT_00120f2d,lVar17,"aw_dev_parse_get_vaild_prof",*puVar1);
      if (*puVar1 == 0) {
        lVar17 = ((long *)*puVar29)[0xe];
        if (lVar17 == 0) {
          lVar17 = *(long *)*puVar29;
        }
        _printk(&DAT_00120f55,lVar17,"aw_dev_parse_get_vaild_prof");
        iVar9 = -1;
      }
      else {
        lVar17 = __kmalloc((ulong)*puVar1 << 6,0xdc0);
        *(long *)(param_1 + 0x288) = lVar17;
        if (lVar17 != 0) {
          lVar17 = 0;
          uVar16 = 0;
          piVar22 = local_5f0;
          do {
            if (*piVar22 == 1) {
              if (*puVar1 <= (uint)uVar16) {
                lVar17 = ((long *)*puVar29)[0xe];
                if (lVar17 == 0) {
                  lVar17 = *(long *)*puVar29;
                }
                _printk(&DAT_0012197d,lVar17,"aw_dev_parse_get_vaild_prof");
                iVar9 = -0xc;
                goto LAB_0010bdb0;
              }
              uVar19 = -(uVar16 >> 0x1f) & 0xffffffc000000000 | uVar16 << 6;
              uVar4 = *(undefined8 *)(piVar22 + 10);
              uVar16 = (ulong)((uint)uVar16 + 1);
              uVar3 = *(undefined8 *)(piVar22 + 0xc);
              uVar5 = *(undefined8 *)(piVar22 + 0xe);
              puVar2 = (undefined8 *)(*(long *)(param_1 + 0x288) + uVar19);
              puVar2[4] = *(undefined8 *)(piVar22 + 8);
              puVar2[5] = uVar4;
              uVar4 = *(undefined8 *)piVar22;
              uVar6 = *(undefined8 *)(piVar22 + 2);
              puVar2[6] = uVar3;
              puVar2[7] = uVar5;
              uVar3 = *(undefined8 *)(piVar22 + 4);
              uVar5 = *(undefined8 *)(piVar22 + 6);
              *puVar2 = uVar4;
              puVar2[1] = uVar6;
              puVar2[2] = uVar3;
              puVar2[3] = uVar5;
              *(int *)(*(long *)(param_1 + 0x288) + uVar19 + 4) = (int)lVar17;
            }
            lVar17 = lVar17 + 1;
            piVar22 = piVar22 + 0x10;
          } while (lVar17 != 0xb);
          *(undefined ***)(param_1 + 0x280) = &profile_name;
          goto LAB_0010bb48;
        }
        iVar9 = -0xc;
      }
    }
  }
LAB_0010bdb0:
  lVar17 = ((long *)*puVar29)[0xe];
  if (lVar17 == 0) {
    lVar17 = *(long *)*puVar29;
  }
  _printk(&DAT_00122240,lVar17,"aw882xx_dev_parse_acf",*(undefined4 *)(param_2 + 0x44));
LAB_0010bdd8:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
LAB_0010b740:
  local_330[0] = uVar26;
  uVar26 = uVar26 + 1;
  uVar16 = 1;
  if (uVar26 == uVar25) goto LAB_0010b9d8;
  goto LAB_0010b614;
  while( true ) {
    if ((0x1f < uVar18) || (0x1f < uVar21)) goto LAB_0010c078;
    uVar23 = uVar23 - 1;
    local_330[uVar16] = local_330[uVar18];
    uVar16 = (ulong)uVar18;
    if (uVar23 == 0) break;
LAB_0010b6d8:
    uVar21 = (uint)uVar16;
    uVar18 = uVar21 - 1;
    if ((0x1f < uVar18) || (0x1f < uVar21)) goto LAB_0010c07c;
  }
  if (uVar19 == 0x20) goto LAB_0010c078;
  uVar16 = (ulong)(iVar20 + 1);
  local_330[uVar19] = uVar26;
  if (iVar20 + 1 == (int)uVar19) {
LAB_0010b72c:
    if (0x1f < (uint)uVar19) goto LAB_0010c07c;
    uVar16 = (ulong)((uint)uVar19 + 1);
    local_330[uVar19 & 0xffffffff] = uVar26;
  }
LAB_0010b608:
  uVar26 = uVar26 + 1;
  if (uVar26 == uVar25) {
    if ((int)uVar16 == 0) goto LAB_0010b85c;
    goto LAB_0010b9d8;
  }
  goto LAB_0010b614;
LAB_0010b9d8:
  lVar24 = 0;
  iVar20 = 0;
LAB_0010ba50:
  if (lVar24 == 0x80) {
LAB_0010c07c:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x10c080);
    (*pcVar8)();
  }
  lVar28 = lVar13 + (ulong)*(uint *)((long)local_330 + lVar24) * 0x60;
  switch(*(undefined4 *)(lVar28 + 0x1c)) {
  case 0:
    lVar14 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar14 == 0) {
      lVar14 = **(long **)(param_1 + 0x78);
    }
    uVar18 = *(uint *)(lVar28 + 0x20);
    uVar25 = *(uint *)(lVar28 + 0x24);
    lVar27 = *(long *)(param_1 + 0x288);
    _printk(&DAT_00122293,lVar14,"aw_dev_parse_raw_reg",uVar18);
    if ((uVar18 & 3) == 0) {
      lVar14 = lVar27 + (long)iVar20 * 0x40;
      *(ulong *)(lVar14 + 0x18) = lVar17 + (ulong)uVar25;
      *(uint *)(lVar14 + 0x10) = uVar18;
      *(undefined4 *)(lVar27 + (long)iVar20 * 0x40) = 1;
      goto LAB_0010ba1c;
    }
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    _printk(&DAT_0012261c,lVar17,"aw_dev_parse_raw_reg");
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &UNK_0011cfa9;
    break;
  default:
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &DAT_0012383d;
    break;
  case 4:
    iVar9 = aw_dev_parse_reg_bin_with_hdr
                      (param_1,lVar17 + (ulong)*(uint *)(lVar28 + 0x24),
                       *(undefined4 *)(lVar28 + 0x20),
                       *(long *)(param_1 + 0x288) + (long)iVar20 * 0x40);
    if (-1 < iVar9) goto LAB_0010ba1c;
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &DAT_0011d73d;
LAB_0010bd3c:
    _printk(puVar11,lVar17,"aw_dev_parse_drv_type_v_1_0_0_0");
    goto LAB_0010b888;
  case 7:
    iVar9 = aw_dev_prof_parse_multi_bin
                      (param_1,lVar17 + (ulong)*(uint *)(lVar28 + 0x24),
                       *(undefined4 *)(lVar28 + 0x20),
                       *(long *)(param_1 + 0x288) + (long)iVar20 * 0x40);
    if (iVar9 < 0) {
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      puVar11 = &DAT_0011ccd6;
      goto LAB_0010bd3c;
    }
LAB_0010ba1c:
    lVar14 = (long)iVar20;
    iVar20 = iVar20 + 1;
    *(long *)(*(long *)(param_1 + 0x288) + lVar14 * 0x40 + 8) = lVar28 + 0x2c;
    *(uint *)(*(long *)(param_1 + 0x288) + lVar14 * 0x40 + 4) = (uint)*(ushort *)(lVar28 + 0x1a);
LAB_0010ba44:
    lVar24 = lVar24 + 4;
    if (uVar16 * 4 == lVar24) goto LAB_0010bba0;
    goto LAB_0010ba50;
  case 10:
    iVar9 = aw882xx_monitor_parse_fw
                      (param_1 + 0x2a8,lVar17 + (ulong)*(uint *)(lVar28 + 0x24),
                       *(undefined4 *)(lVar28 + 0x20));
    if (iVar9 < 0) {
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      puVar11 = &DAT_0011f95d;
      goto LAB_0010bd3c;
    }
    goto LAB_0010ba44;
  }
  pcVar15 = "aw_dev_parse_drv_type_v_1_0_0_0";
  goto LAB_0010b880;
LAB_0010bba0:
  if (iVar20 == 0) {
LAB_0010b85c:
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &DAT_0012328d;
    pcVar15 = "aw_dev_parse_scene_v_1_0_0_0";
LAB_0010b880:
    _printk(puVar11,lVar17,pcVar15);
    iVar9 = -0x16;
LAB_0010b888:
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &DAT_0011e68c;
  }
  else {
    lVar13 = ((long *)*puVar29)[0xe];
    if (lVar13 == 0) {
      lVar13 = *(long *)*puVar29;
    }
    uVar18 = *(uint *)(param_2 + 0x40);
    _printk(&DAT_00120075,lVar13,"aw_dev_parse_skt_type_v_1_0_0_0");
    uVar25 = *(uint *)(param_2 + 0x3c);
    if (uVar25 != 0) {
      uVar26 = 0;
      do {
        piVar22 = (int *)(lVar17 + (ulong)uVar18 + (long)(int)uVar26 * 0x60);
        if ((((*piVar22 == 1) && (piVar22[7] == 1)) &&
            (*(uint *)(param_1 + 0x3c) == (uint)*(ushort *)(piVar22 + 5))) &&
           (*(int *)(param_1 + 4) == piVar22[0x13])) {
          iVar20 = *(int *)(param_1 + 0x278);
          if (iVar20 == 0) {
LAB_0010bf48:
            lVar17 = ((long *)*puVar29)[0xe];
            if (lVar17 == 0) {
              lVar17 = *(long *)*puVar29;
            }
            _printk(&DAT_0011d76e,lVar17,"aw_dev_parse_get_scene_id_v_1_0_0_0",piVar22 + 0xb);
LAB_0010bfa0:
            lVar17 = ((long *)*puVar29)[0xe];
            if (lVar17 == 0) {
              lVar17 = *(long *)*puVar29;
            }
            puVar11 = &DAT_001209c9;
            pcVar15 = "aw_dev_parse_skt_type_v_1_0_0_0";
            goto LAB_0010b880;
          }
          iVar9 = 0;
          lVar13 = *(long *)(param_1 + 0x288);
          while( true ) {
            pcVar15 = *(char **)(lVar13 + (long)iVar9 * 0x40 + 8);
            if (pcVar15 == (char *)0x0) {
              lVar17 = ((long *)*puVar29)[0xe];
              if (lVar17 == 0) {
                lVar17 = *(long *)*puVar29;
              }
              _printk(&DAT_001204d7,lVar17,"aw_dev_parse_get_scene_id_v_1_0_0_0");
              goto LAB_0010bfa0;
            }
            iVar10 = strcmp(pcVar15,(char *)(piVar22 + 0xb));
            if (iVar10 == 0) break;
            iVar9 = iVar9 + 1;
            if (iVar20 == iVar9) goto LAB_0010bf48;
          }
          lVar24 = ((long *)*puVar29)[0xe];
          if (lVar24 == 0) {
            lVar24 = *(long *)*puVar29;
          }
          iVar20 = piVar22[8];
          uVar25 = piVar22[9];
          _printk(&DAT_00122293,lVar24,"aw_dev_parse_raw_dsp",iVar20);
          lVar13 = lVar13 + (long)iVar9 * 0x40;
          *(ulong *)(lVar13 + 0x28) = lVar17 + (ulong)uVar25;
          *(int *)(lVar13 + 0x20) = iVar20;
          uVar25 = *(uint *)(param_2 + 0x3c);
        }
        uVar26 = uVar26 + 1;
      } while (uVar26 < uVar25);
    }
    lVar17 = *(long *)(param_1 + 0x288);
    plVar12 = *(long **)(param_1 + 0x78);
    if (lVar17 == 0) {
      lVar17 = plVar12[0xe];
      if (lVar17 == 0) {
        lVar17 = *plVar12;
      }
      _printk(&DAT_0011cfd1,lVar17,"aw_dev_parse_create_prof_name_list_v_1_0_0_0");
      iVar9 = -0x16;
    }
    else {
      lVar13 = devm_kmalloc(plVar12,*(int *)(param_1 + 0x278) << 5,0xdc0);
      *(long *)(param_1 + 0x280) = lVar13;
      if (lVar13 != 0) {
        if (*(int *)(param_1 + 0x278) != 0) {
          uVar18 = 0;
          do {
            lVar13 = lVar17 + (long)(int)uVar18 * 0x40;
            *(uint *)(lVar13 + 4) = uVar18;
            *(undefined8 *)(*(long *)(param_1 + 0x280) + (long)(int)uVar18 * 8) =
                 *(undefined8 *)(lVar13 + 8);
            lVar13 = (*(long **)(param_1 + 0x78))[0xe];
            if (lVar13 == 0) {
              lVar13 = **(long **)(param_1 + 0x78);
            }
            _printk(&DAT_0011deef,lVar13,"aw_dev_parse_create_prof_name_list_v_1_0_0_0",
                    *(undefined8 *)(*(long *)(param_1 + 0x280) + (long)(int)uVar18 * 8));
            uVar18 = uVar18 + 1;
          } while (uVar18 < *(uint *)(param_1 + 0x278));
        }
LAB_0010bb48:
        lVar17 = ((long *)*puVar29)[0xe];
        if (lVar17 == 0) {
          lVar17 = *(long *)*puVar29;
        }
        _printk(&DAT_0011fb73,lVar17,"aw882xx_dev_parse_acf");
        iVar9 = 0;
        goto LAB_0010bdd8;
      }
      lVar17 = ((long *)*puVar29)[0xe];
      if (lVar17 == 0) {
        lVar17 = *(long *)*puVar29;
      }
      _printk(&DAT_00123555,lVar17,"aw_dev_parse_create_prof_name_list_v_1_0_0_0");
      iVar9 = -0xc;
    }
    lVar17 = ((long *)*puVar29)[0xe];
    if (lVar17 == 0) {
      lVar17 = *(long *)*puVar29;
    }
    puVar11 = &DAT_00121feb;
  }
  _printk(puVar11,lVar17,"aw_dev_parse_acf_by_hdr_v_1_0_0_0");
  goto LAB_0010bdb0;
}



//------------------------------------------------------------
// aw882xx_dev_get_prof_name @ 0010c088 size=156
// signature: undefined aw882xx_dev_get_prof_name(void)
// callers: [aw_dev_reg_fw_update]
//------------------------------------------------------------

undefined8 aw882xx_dev_get_prof_name(long param_1,uint param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((int)param_2 < 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120472,lVar2,"aw882xx_dev_get_prof_name");
    uVar1 = 0;
  }
  else if (param_2 < *(uint *)(param_1 + 0x278)) {
    uVar1 = *(undefined8 *)
             (*(long *)(param_1 + 0x280) +
             (ulong)*(uint *)(*(long *)(param_1 + 0x288) + (ulong)param_2 * 0x40 + 4) * 8);
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011f911,lVar2,"aw882xx_dev_get_prof_name");
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw88xx_dev_get_profile_name @ 0010c128 size=200
// signature: undefined aw88xx_dev_get_profile_name(void)
// callers: [aw882xx_profile_info]
//------------------------------------------------------------

int aw88xx_dev_get_profile_name(long param_1,undefined8 param_2,uint param_3)

{
  int iVar1;
  size_t sVar2;
  long lVar3;
  char *__s;
  
  if ((int)param_3 < 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120472,lVar3,"aw88xx_dev_get_profile_name");
    iVar1 = -0x16;
  }
  else if (*(uint *)(param_1 + 0x278) < param_3) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120989,lVar3,"aw88xx_dev_get_profile_name");
    iVar1 = -0x16;
  }
  else {
    __s = *(char **)(*(long *)(param_1 + 0x280) +
                    (long)*(int *)(*(long *)(param_1 + 0x288) + (ulong)param_3 * 0x40 + 4) * 8);
    sVar2 = strlen(__s);
    iVar1 = strscpy(param_2,__s,sVar2 + 1);
    if (-1 < iVar1) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dev_get_prof_data @ 0010c1f4 size=164
// signature: undefined aw882xx_dev_get_prof_data(void)
// callers: [aw_dev_reg_fw_update]
//------------------------------------------------------------

long aw882xx_dev_get_prof_data(long param_1,uint param_2,int param_3)

{
  long lVar1;
  
  if (param_2 < *(uint *)(param_1 + 0x278)) {
    if (param_3 < 3) {
      lVar1 = *(long *)(param_1 + 0x288) + (long)(int)param_2 * 0x40 + (long)param_3 * 0x10 + 0x10;
    }
    else {
      lVar1 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar1 == 0) {
        lVar1 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011f5ca,lVar1,"aw882xx_dev_get_prof_data");
      lVar1 = 0;
    }
  }
  else {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011f911,lVar1,"aw882xx_dev_get_prof_data",param_2);
    lVar1 = 0;
  }
  return lVar1;
}



//------------------------------------------------------------
// aw882xx_dev_set_profile_index @ 0010c29c size=124
// signature: undefined aw882xx_dev_set_profile_index(void)
// callers: [aw882xx_profile_set]
//------------------------------------------------------------

undefined8 aw882xx_dev_set_profile_index(long param_1,uint param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  uVar1 = 0xffffffea;
  if ((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 0x278))) {
    *(char *)(param_1 + 0x39) = (char)param_2;
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011dea9,lVar2,"aw882xx_dev_set_profile_index",
            *(undefined8 *)
             (*(long *)(param_1 + 0x280) +
             (ulong)*(uint *)(*(long *)(param_1 + 0x288) + (ulong)param_2 * 0x40 + 4) * 8));
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_dev_get_profile_count @ 0010c31c size=60
// signature: undefined aw882xx_dev_get_profile_count(void)
// callers: [aw882xx_profile_info]
//------------------------------------------------------------

undefined4 aw882xx_dev_get_profile_count(long param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_001218cd,"aw882xx_dev_get_profile_count");
    uVar1 = 0xfffffff4;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x278);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_dev_check_profile_index @ 0010c35c size=24
// signature: undefined aw882xx_dev_check_profile_index(void)
// callers: [aw882xx_profile_set]
//------------------------------------------------------------

undefined4 aw882xx_dev_check_profile_index(long param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffea;
  if (param_2 < *(uint *)(param_1 + 0x278) && -1 < (int)param_2) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_dev_get_profile_index @ 0010c378 size=8
// signature: undefined aw882xx_dev_get_profile_index(void)
// callers: [aw882xx_profile_get, aw882xx_profile_set]
//------------------------------------------------------------

undefined1 aw882xx_dev_get_profile_index(long param_1)

{
  return *(undefined1 *)(param_1 + 0x39);
}



//------------------------------------------------------------
// aw_dev_parse_crc8_check @ 0010c380 size=192
// signature: undefined aw_dev_parse_crc8_check(void)
// callers: [aw882xx_dev_parse_check_acf]
//------------------------------------------------------------

uint aw_dev_parse_crc8_check(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  while (param_2 != 0) {
    pbVar4 = param_1 + 1;
    bVar3 = *param_1;
    param_2 = param_2 + -1;
    uVar2 = uVar1 >> 1;
    if (((bVar3 ^ uVar1) & 1) != 0) {
      uVar2 = uVar1 >> 1 ^ 0x8c;
    }
    uVar1 = uVar2 >> 1;
    if (((uVar2 ^ bVar3 >> 1) & 1) != 0) {
      uVar1 = uVar2 >> 1 ^ 0x8c;
    }
    uVar2 = uVar1 >> 1;
    if (((uVar1 ^ bVar3 >> 2) & 1) != 0) {
      uVar2 = uVar1 >> 1 ^ 0x8c;
    }
    uVar1 = uVar2 >> 1;
    if (((uVar2 ^ bVar3 >> 3) & 1) != 0) {
      uVar1 = uVar2 >> 1 ^ 0x8c;
    }
    uVar2 = uVar1 >> 1;
    if (((uVar1 ^ bVar3 >> 4) & 1) != 0) {
      uVar2 = uVar1 >> 1 ^ 0x8c;
    }
    uVar1 = uVar2 >> 1;
    if (((uVar2 ^ bVar3 >> 5) & 1) != 0) {
      uVar1 = uVar2 >> 1 ^ 0x8c;
    }
    uVar2 = uVar1 >> 1;
    if (((uVar1 ^ bVar3 >> 6) & 1) != 0) {
      uVar2 = uVar1 >> 1 ^ 0x8c;
    }
    param_1 = pbVar4;
    uVar1 = uVar2 >> 1;
    if ((uVar2 & 1) != (uint)(bVar3 >> 7)) {
      uVar1 = uVar2 >> 1 ^ 0x8c;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_dev_parse_data_by_sec_type @ 0010c440 size=292
// signature: undefined aw_dev_parse_data_by_sec_type(void)
// callers: [aw882xx_dev_parse_acf]
//------------------------------------------------------------

undefined8 aw_dev_parse_data_by_sec_type(long param_1,long param_2,long param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar3 = 0;
  switch(*(undefined4 *)(param_3 + 0x1c)) {
  case 0:
    uVar1 = *(uint *)(param_3 + 0x20);
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    uVar2 = *(uint *)(param_3 + 0x24);
    _printk(&DAT_00122293,lVar4,"aw_dev_parse_raw_reg",uVar1);
    if ((uVar1 & 3) == 0) {
      uVar3 = 0;
      param_4[4] = uVar1;
      *(ulong *)(param_4 + 6) = param_2 + (ulong)uVar2;
      *param_4 = 1;
    }
    else {
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0012261c,lVar4,"aw_dev_parse_raw_reg");
      uVar3 = 0xffffffea;
    }
    break;
  case 4:
    uVar3 = aw_dev_parse_reg_bin_with_hdr
                      (param_1,param_2 + (ulong)*(uint *)(param_3 + 0x24),
                       *(undefined4 *)(param_3 + 0x20),param_4);
    break;
  case 7:
    uVar3 = aw_dev_prof_parse_multi_bin
                      (param_1,param_2 + (ulong)*(uint *)(param_3 + 0x24),
                       *(undefined4 *)(param_3 + 0x20),param_4);
    break;
  case 10:
    uVar3 = aw882xx_monitor_parse_fw
                      (param_1 + 0x2a8,param_2 + (ulong)*(uint *)(param_3 + 0x24),
                       *(undefined4 *)(param_3 + 0x20));
  }
  return uVar3;
}



//------------------------------------------------------------
// aw_dev_parse_reg_bin_with_hdr @ 0010c564 size=376
// signature: undefined aw_dev_parse_reg_bin_with_hdr(void)
// callers: [aw_dev_parse_data_by_sec_type, aw882xx_dev_parse_acf]
//------------------------------------------------------------

int aw_dev_parse_reg_bin_with_hdr(long param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  long lVar5;
  
  lVar5 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00122293,lVar5,"aw_dev_parse_reg_bin_with_hdr",param_3);
  lVar5 = __kmalloc((ulong)param_3 + 0x1c38,0xdc0);
  if (lVar5 == 0) {
    iVar2 = -0xc;
  }
  else {
    *(uint *)(lVar5 + 0x1c34) = param_3;
    memcpy((void *)(lVar5 + 0x1c38),param_2,(ulong)param_3);
    iVar2 = aw_parsing_bin_file(lVar5);
    if (iVar2 < 0) {
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      puVar3 = &DAT_001237d9;
    }
    else {
      if ((*(int *)(lVar5 + 8) == 1) && (*(int *)(lVar5 + 0x20) == 0)) {
        if ((*(uint *)(lVar5 + 0x44) & 3) == 0) {
          uVar1 = *(uint *)(lVar5 + 0x48);
          param_4[4] = *(uint *)(lVar5 + 0x44);
          *param_4 = 1;
          *(ulong *)(param_4 + 6) = (long)param_2 + (ulong)uVar1;
          kfree(lVar5);
          return 0;
        }
        lVar5 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar5 == 0) {
          lVar5 = **(long **)(param_1 + 0x78);
        }
        _printk(&DAT_0012261c,lVar5,"aw_dev_parse_reg_bin_with_hdr");
        return -0x16;
      }
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      puVar3 = &DAT_00120150;
    }
    _printk(puVar3,lVar4,"aw_dev_parse_reg_bin_with_hdr");
    kfree(lVar5);
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_dev_prof_parse_multi_bin @ 0010c6dc size=488
// signature: undefined aw_dev_prof_parse_multi_bin(void)
// callers: [aw_dev_parse_data_by_sec_type, aw882xx_dev_parse_acf]
//------------------------------------------------------------

int aw_dev_prof_parse_multi_bin(long param_1,void *param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  undefined1 uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  
  lVar6 = devm_kmalloc(*(undefined8 *)(param_1 + 0x78),(ulong)param_3 + 0x1c38,0xdc0);
  if (lVar6 == 0) {
    iVar5 = -0xc;
  }
  else {
    *(uint *)(lVar6 + 0x1c34) = param_3;
    memcpy((void *)(lVar6 + 0x1c38),param_2,(ulong)param_3);
    iVar5 = aw_parsing_bin_file(lVar6);
    if (iVar5 < 0) {
      lVar8 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar8 == 0) {
        lVar8 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_001237d9,lVar8,"aw_dev_prof_parse_multi_bin");
      devm_kfree(*(undefined8 *)(param_1 + 0x78),lVar6);
    }
    else {
      uVar2 = *(uint *)(lVar6 + 8);
      if (uVar2 != 0) {
        uVar7 = 0;
        do {
          if (uVar7 == 100) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10c8c4);
            (*pcVar4)();
          }
          iVar5 = *(int *)(lVar6 + uVar7 * 0x48 + 0x20);
          if (iVar5 == 0x21) {
            lVar8 = lVar6 + uVar7 * 0x48;
            uVar1 = *(uint *)(lVar8 + 0x44);
            if ((uVar1 & 1) != 0) {
              return -0x16;
            }
            lVar8 = (long)param_2 + (ulong)*(uint *)(lVar8 + 0x48);
            if (uVar1 != 0) {
              uVar9 = 0;
              do {
                iVar5 = uVar9 + 1;
                lVar10 = (long)(int)uVar9;
                uVar9 = uVar9 + 2;
                uVar3 = *(undefined1 *)(lVar8 + iVar5);
                *(undefined1 *)(lVar8 + iVar5) = *(undefined1 *)(lVar8 + lVar10);
                *(undefined1 *)(lVar8 + lVar10) = uVar3;
              } while (uVar9 < uVar1);
            }
            param_4[0xc] = uVar1;
            *(long *)(param_4 + 0xe) = lVar8;
          }
          else if (iVar5 == 0x10) {
            lVar8 = lVar6 + uVar7 * 0x48;
            uVar1 = *(uint *)(lVar8 + 0x44);
            if ((uVar1 & 1) != 0) {
              return -0x16;
            }
            lVar8 = (long)param_2 + (ulong)*(uint *)(lVar8 + 0x48);
            if (uVar1 != 0) {
              uVar9 = 0;
              do {
                iVar5 = uVar9 + 1;
                lVar10 = (long)(int)uVar9;
                uVar9 = uVar9 + 2;
                uVar3 = *(undefined1 *)(lVar8 + iVar5);
                *(undefined1 *)(lVar8 + iVar5) = *(undefined1 *)(lVar8 + lVar10);
                *(undefined1 *)(lVar8 + lVar10) = uVar3;
              } while (uVar9 < uVar1);
            }
            param_4[8] = uVar1;
            *(long *)(param_4 + 10) = lVar8;
          }
          else if (iVar5 == 0) {
            lVar8 = lVar6 + uVar7 * 0x48;
            uVar1 = *(uint *)(lVar8 + 0x48);
            param_4[4] = *(undefined4 *)(lVar8 + 0x44);
            *(ulong *)(param_4 + 6) = (long)param_2 + (ulong)uVar1;
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 != uVar2);
      }
      devm_kfree(*(undefined8 *)(param_1 + 0x78),lVar6);
      iVar5 = 0;
      *param_4 = 1;
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// aw_parsing_bin_file @ 0010c8c4 size=728
// signature: undefined aw_parsing_bin_file(void)
// callers: [aw_dev_prof_parse_multi_bin, aw_dev_parse_reg_bin_with_hdr]
//------------------------------------------------------------

int aw_parsing_bin_file(undefined8 *param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  byte *pbVar9;
  ulong uVar10;
  ulong uVar11;
  int iVar12;
  ulong uVar13;
  ulong uVar14;
  
  *(undefined4 *)(param_1 + 2) = 0;
  *param_1 = param_1 + 0x387;
  param_1[1] = 0;
  if (*(int *)((long)param_1 + 0x1c3c) == 0x1000000) {
    aw_parse_bin_header_1_0_0();
    *param_1 = 0;
    if (*(int *)(param_1 + 1) != 0) {
      uVar14 = 0;
      do {
        if (uVar14 == 100) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10cb9c);
          (*pcVar2)();
        }
        iVar3 = *(int *)((long)param_1 + uVar14 * 0x48 + 0x14);
        uVar6 = (ulong)(uint)(*(int *)(param_1 + uVar14 * 9 + 9) - iVar3);
        uVar1 = *(int *)(param_1 + uVar14 * 9 + 5) + iVar3;
        if (uVar1 < 5) {
          iVar3 = 0;
        }
        else {
          uVar10 = (ulong)uVar1 - 4;
          if (uVar10 < 2) {
            iVar3 = 0;
            lVar8 = 4;
          }
          else {
            uVar11 = uVar10 & 0xfffffffffffffffe;
            iVar12 = 0;
            iVar3 = 0;
            lVar8 = uVar11 + 4;
            pbVar9 = (byte *)((long)param_1 + uVar6 + 0x1c3d);
            uVar13 = uVar11;
            do {
              uVar13 = uVar13 - 2;
              iVar12 = iVar12 + (uint)pbVar9[-1];
              iVar3 = iVar3 + (uint)*pbVar9;
              pbVar9 = pbVar9 + 2;
            } while (uVar13 != 0);
            iVar3 = iVar3 + iVar12;
            if (uVar10 == uVar11) goto LAB_0010c9e8;
          }
          lVar7 = (ulong)uVar1 - lVar8;
          pbVar9 = (byte *)((long)param_1 + lVar8 + uVar6 + 0x1c38);
          do {
            lVar7 = lVar7 + -1;
            iVar3 = iVar3 + (uint)*pbVar9;
            pbVar9 = pbVar9 + 1;
          } while (lVar7 != 0);
        }
LAB_0010c9e8:
        iVar12 = *(int *)((long)(param_1 + 0x387) + uVar6);
        if (iVar3 != iVar12) {
          _printk(&DAT_0011eaf4,"aw_check_sum",0x5c);
          _printk(&DAT_00121c6d,"aw_check_sum",0x5d,uVar14 & 0xffffffff,iVar12,iVar3);
          puVar4 = &DAT_001237fd;
          uVar5 = 0x1bb;
          goto LAB_0010cb4c;
        }
        if (*(int *)((long)param_1 + uVar14 * 0x48 + 0x24) != 1) {
          _printk(&DAT_001213c9,"aw_check_data_version",0x70);
          puVar4 = &DAT_0011f615;
          uVar5 = 0x1c1;
          goto LAB_0010cb4c;
        }
        iVar3 = *(int *)(param_1 + uVar14 * 9 + 4);
        if (iVar3 == 0x21) {
          iVar3 = aw_check_soc_app_num_v1(param_1,uVar14 & 0xffffffff);
          if (iVar3 < 0) {
            _printk(&DAT_0011ee97,"aw_parsing_bin_file",0x1dc);
            return iVar3;
          }
        }
        else if (iVar3 == 0x10) {
          iVar3 = aw_check_dsp_reg_num_v1(param_1,uVar14 & 0xffffffff);
          if (iVar3 < 0) {
            _printk(&DAT_0012193a,"aw_parsing_bin_file",0x1d3);
            return iVar3;
          }
        }
        else if (iVar3 == 0) {
          iVar3 = aw_check_register_num_v1(param_1,uVar14 & 0xffffffff);
          if (iVar3 < 0) {
            _printk(&DAT_0011da9c,"aw_parsing_bin_file",0x1cb);
            return iVar3;
          }
        }
        else {
          *(int *)((long)param_1 + uVar14 * 0x48 + 0x44) = *(int *)(param_1 + uVar14 * 9 + 5);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_1 + 1));
    }
    iVar3 = 0;
  }
  else {
    _printk(&DAT_0011fe26,"aw_check_bin_header_version",0x19a);
    puVar4 = &DAT_0011cf5f;
    uVar5 = 0x1b1;
LAB_0010cb4c:
    _printk(puVar4,"aw_parsing_bin_file",uVar5);
    iVar3 = -0x16;
  }
  return iVar3;
}



//------------------------------------------------------------
// aw_cali_write_re_to_nvram @ 0010cba0 size=8
// signature: undefined aw_cali_write_re_to_nvram(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_cali_write_re_to_nvram(void)

{
  return 0;
}



//------------------------------------------------------------
// aw882xx_cali_read_re_from_nvram @ 0010cbac size=8
// signature: undefined aw882xx_cali_read_re_from_nvram(void)
// callers: [aw882xx_dev_init_cali_re]
//------------------------------------------------------------

undefined8 aw882xx_cali_read_re_from_nvram(void)

{
  return 0;
}



//------------------------------------------------------------
// aw882xx_cali_check_result @ 0010cbb8 size=36
// signature: undefined aw882xx_cali_check_result(void)
// callers: [aw882xx_device_start]
//------------------------------------------------------------

undefined8 aw882xx_cali_check_result(long param_1)

{
  if ((*(char *)(param_1 + 0x11) == '\0') || (*(char *)(param_1 + 0x10) != -1)) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// aw_cali_store_cali_re @ 0010cbe0 size=280
// signature: undefined aw_cali_store_cali_re(void)
// callers: [aw_cali_svc_dev_get_re, aw_cali_misc_ops, aw_cali_svc_set_devs_re_str]
//------------------------------------------------------------

undefined8 aw_cali_store_cali_re(long param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  
  uVar1 = *(uint *)(param_1 + 0x48);
  if (((uVar1 <= param_2) && (param_2 <= *(uint *)(param_1 + 0x44))) ||
     (*(char *)(param_1 + 0x2a1) != '\0')) {
    *(uint *)(param_1 + 0x294) = param_2;
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0012201b,lVar2,"aw_cali_store_cali_re",param_2);
    uVar1 = *(uint *)(param_1 + 0x48);
  }
  if ((param_2 < uVar1) || (*(uint *)(param_1 + 0x44) < param_2)) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001229be,lVar2,"aw_cali_store_cali_re",param_2,uVar1,
            *(undefined4 *)(param_1 + 0x44));
    if (*(char *)(param_1 + 0x2a1) != '\0') {
      *(undefined1 *)(param_1 + 0x2a0) = 0xff;
      aw882xx_dev_mute(param_1,1);
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011df48,lVar2,"aw_cali_svc_run_mute");
    }
  }
  else if (*(char *)(param_1 + 0x2a1) != '\0') {
    *(undefined1 *)(param_1 + 0x2a0) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// aw_cali_svc_run_mute @ 0010ccf8 size=196
// signature: undefined aw_cali_svc_run_mute(void)
// callers: [aw_cali_misc_ops, aw_cali_svc_cali_f0, aw_cali_svc_cali_f0_q, aw_cali_svc_devs_cali_mode_enable]
//------------------------------------------------------------

void aw_cali_svc_run_mute(long param_1,char param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x2a1) == '\0') {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    puVar1 = &DAT_001201a1;
  }
  else {
    if (param_2 == '\x01') {
      aw882xx_dev_mute(param_1,0);
      goto LAB_0010cd88;
    }
    if (param_2 == -1) {
      aw882xx_dev_mute(param_1,1);
      goto LAB_0010cd88;
    }
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    puVar1 = &DAT_00122042;
  }
  _printk(puVar1,lVar2,"aw_cali_svc_run_mute");
LAB_0010cd88:
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar2,"aw_cali_svc_run_mute");
  return;
}



//------------------------------------------------------------
// aw882xx_cali_svc_get_cali_status @ 0010cdc0 size=12
// signature: undefined aw882xx_cali_svc_get_cali_status(void)
// callers: [aw_monitor_work_func]
//------------------------------------------------------------

undefined1 aw882xx_cali_svc_get_cali_status(void)

{
  return g_cali_status;
}



//------------------------------------------------------------
// aw_cali_svc_cali_cmd @ 0010cdd0 size=260
// signature: undefined aw_cali_svc_cali_cmd(void)
// callers: [aw_cali_misc_write]
//------------------------------------------------------------

undefined8 aw_cali_svc_cali_cmd(long param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  switch(param_2) {
  case 0:
    uVar1 = aw_cali_svc_cali_re(param_1,param_3 & 1,param_4);
    return uVar1;
  case 1:
    break;
  case 2:
    uVar1 = aw_cali_svc_cali_re(param_1,param_3 & 1,param_4);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
    break;
  case 3:
    goto LAB_0010ce8c;
  case 4:
    uVar1 = aw_cali_svc_cali_re(param_1,param_3 & 1,param_4);
    if ((int)uVar1 != 0) {
      return uVar1;
    }
LAB_0010ce8c:
    uVar1 = aw_cali_svc_cali_f0_q(param_1,param_3 & 1,param_4);
    return uVar1;
  default:
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d442,lVar2,"aw_cali_svc_cali_cmd");
    return 0xffffffea;
  }
  uVar1 = aw_cali_svc_cali_f0(param_1,param_3 & 1,param_4);
  return uVar1;
}



//------------------------------------------------------------
// aw_cali_svc_cali_re @ 0010ced4 size=844
// signature: undefined aw_cali_svc_cali_re(void)
// callers: [cali_re_show, aw_cali_svc_cali_cmd, aw_cali_class_cali_re_show, aw_cali_misc_write, cali_store]
//------------------------------------------------------------

int aw_cali_svc_cali_re(long param_1,ulong param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  if ((param_2 & 1) == 0) {
    local_70 = (long *)0x0;
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120075,lVar2,"aw_cali_svc_devs_cali_re");
    iVar1 = aw882xx_dev_get_list_head(&local_70);
    if (iVar1 == 0) {
      iVar1 = aw_cali_svc_devs_cali_mode_enable(local_70,0,param_3,1);
      if (-1 < iVar1) {
        msleep(g_cali_re_time);
        plVar5 = local_70;
        plVar4 = (long *)*local_70;
        if (plVar4 == local_70) {
          iVar1 = -1;
        }
        else {
          do {
            iVar1 = aw_cali_svc_dev_get_re(plVar4 + -0xa1);
            if (iVar1 < 0) {
              lVar2 = ((long *)plVar4[-0x92])[0xe];
              if (lVar2 == 0) {
                lVar2 = *(long *)plVar4[-0x92];
              }
              _printk(&DAT_0011ef32,lVar2,"aw_cali_svc_devs_get_cali_cali_data",0);
              break;
            }
            plVar4 = (long *)*plVar4;
          } while (plVar4 != plVar5);
        }
      }
      plVar4 = local_70;
      for (plVar5 = (long *)*local_70; plVar5 != plVar4; plVar5 = (long *)*plVar5) {
        lVar2 = (long)(plVar5 + -0xa1);
        aw882xx_dsp_cali_en(lVar2,0);
        if ((param_3 & 1) != 0) {
          aw882xx_dsp_hmute_en(lVar2,0);
        }
        g_cali_status = 0;
        lVar3 = ((long *)plVar5[-0x92])[0xe];
        if (lVar3 == 0) {
          lVar3 = *(long *)plVar5[-0x92];
        }
        _printk(&DAT_0011e33d,lVar3,"aw_cali_svc_set_cali_status","disable");
        aw882xx_dev_iv_forbidden_output(lVar2,1);
      }
    }
    else {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011d468,lVar2,"aw_cali_svc_devs_cali_re");
    }
    goto LAB_0010d184;
  }
  if (*(char *)(param_1 + 0x2a1) == '\0') {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001201a1,lVar2,"aw_cali_svc_run_mute");
  }
  else {
    aw882xx_dev_mute(param_1,0);
  }
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar2,"aw_cali_svc_run_mute");
  aw882xx_dev_iv_forbidden_output(param_1,0);
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  g_cali_status = 1;
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","enable");
  if (((param_3 & 1) == 0) || (iVar1 = aw882xx_dsp_hmute_en(param_1,1), -1 < iVar1)) {
    iVar1 = aw882xx_dsp_cali_en(param_1,1);
    if (-1 < iVar1) {
      msleep(g_cali_re_time);
      iVar1 = aw_cali_svc_dev_get_re(param_1);
    }
    aw882xx_dsp_cali_en(param_1,0);
    if ((param_3 & 1) != 0) goto LAB_0010d0a0;
  }
  else {
    aw882xx_dsp_cali_en(param_1,0);
LAB_0010d0a0:
    aw882xx_dsp_hmute_en(param_1,0);
  }
  g_cali_status = 0;
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","disable");
  aw882xx_dev_iv_forbidden_output(param_1,1);
LAB_0010d184:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw_cali_svc_cali_f0 @ 0010d220 size=828
// signature: undefined aw_cali_svc_cali_f0(void)
// callers: [cali_f0_show, aw_cali_class_cali_f0_store, cali_f0_store, aw_cali_class_cali_f0_show, aw_cali_svc_cali_cmd, aw_cali_misc_write, cali_store]
//------------------------------------------------------------

int aw_cali_svc_cali_f0(long param_1,ulong param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  if ((param_2 & 1) == 0) {
    local_70 = (long *)0x0;
    iVar1 = aw882xx_dev_get_list_head(&local_70);
    if (iVar1 == 0) {
      iVar1 = aw_cali_svc_devs_cali_mode_enable(local_70,1,param_3,1);
      if (-1 < iVar1) {
        msleep(5000);
        plVar5 = local_70;
        plVar4 = (long *)*local_70;
        if (plVar4 == local_70) {
          iVar1 = -1;
        }
        else {
          do {
            iVar1 = aw_cali_svc_dev_get_f0(plVar4 + -0xa1);
            if (iVar1 < 0) {
              lVar3 = ((long *)plVar4[-0x92])[0xe];
              if (lVar3 == 0) {
                lVar3 = *(long *)plVar4[-0x92];
              }
              _printk(&DAT_0011ef32,lVar3,"aw_cali_svc_devs_get_cali_cali_data",1);
              break;
            }
            plVar4 = (long *)*plVar4;
          } while (plVar4 != plVar5);
        }
      }
      plVar4 = local_70;
      for (plVar5 = (long *)*local_70; plVar5 != plVar4; plVar5 = (long *)*plVar5) {
        lVar3 = (long)(plVar5 + -0xa1);
        aw882xx_dsp_cali_en(lVar3,0);
        if ((param_3 >> 1 & 1) != 0) {
          aw882xx_dsp_noise_en(lVar3,0);
        }
        g_cali_status = 0;
        lVar2 = ((long *)plVar5[-0x92])[0xe];
        if (lVar2 == 0) {
          lVar2 = *(long *)plVar5[-0x92];
        }
        _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","disable");
        aw882xx_dev_iv_forbidden_output(lVar3,1);
        aw_cali_svc_run_mute(lVar3,*(undefined1 *)(plVar5 + -0x4d));
      }
    }
    else {
      lVar3 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011d468,lVar3,"aw_cali_svc_devs_cali_f0");
    }
    goto LAB_0010d364;
  }
  if (*(char *)(param_1 + 0x2a1) == '\0') {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001201a1,lVar3,"aw_cali_svc_run_mute");
  }
  else {
    aw882xx_dev_mute(param_1,0);
  }
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar3,"aw_cali_svc_run_mute");
  aw882xx_dev_iv_forbidden_output(param_1,0);
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  g_cali_status = 1;
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar3,"aw_cali_svc_set_cali_status","enable");
  if (((param_3 >> 1 & 1) == 0) || (iVar1 = aw882xx_dsp_noise_en(param_1,1), -1 < iVar1)) {
    iVar1 = aw882xx_dsp_cali_en(param_1,2);
    if (-1 < iVar1) {
      msleep(5000);
      iVar1 = aw_cali_svc_dev_get_f0(param_1);
    }
    aw882xx_dsp_cali_en(param_1,0);
    if ((param_3 >> 1 & 1) != 0) goto LAB_0010d4d0;
  }
  else {
    aw882xx_dsp_cali_en(param_1,0);
LAB_0010d4d0:
    aw882xx_dsp_noise_en(param_1,0);
  }
  g_cali_status = 0;
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar3,"aw_cali_svc_set_cali_status","disable");
  aw882xx_dev_iv_forbidden_output(param_1,1);
  aw_cali_svc_run_mute(param_1,*(undefined1 *)(param_1 + 0x2a0));
LAB_0010d364:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw_cali_svc_cali_f0_q @ 0010d55c size=828
// signature: undefined aw_cali_svc_cali_f0_q(void)
// callers: [aw_cali_svc_cali_cmd, aw_cali_misc_write]
//------------------------------------------------------------

int aw_cali_svc_cali_f0_q(long param_1,ulong param_2,uint param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  if ((param_2 & 1) == 0) {
    local_70 = (long *)0x0;
    iVar1 = aw882xx_dev_get_list_head(&local_70);
    if (iVar1 == 0) {
      iVar1 = aw_cali_svc_devs_cali_mode_enable(local_70,1,param_3,1);
      if (-1 < iVar1) {
        msleep(5000);
        plVar5 = local_70;
        plVar4 = (long *)*local_70;
        if (plVar4 == local_70) {
          iVar1 = -1;
        }
        else {
          do {
            iVar1 = aw_cali_svc_dev_get_f0_q(plVar4 + -0xa1);
            if (iVar1 < 0) {
              lVar3 = ((long *)plVar4[-0x92])[0xe];
              if (lVar3 == 0) {
                lVar3 = *(long *)plVar4[-0x92];
              }
              _printk(&DAT_0011ef32,lVar3,"aw_cali_svc_devs_get_cali_cali_data",2);
              break;
            }
            plVar4 = (long *)*plVar4;
          } while (plVar4 != plVar5);
        }
      }
      plVar4 = local_70;
      for (plVar5 = (long *)*local_70; plVar5 != plVar4; plVar5 = (long *)*plVar5) {
        lVar3 = (long)(plVar5 + -0xa1);
        aw882xx_dsp_cali_en(lVar3,0);
        if ((param_3 >> 1 & 1) != 0) {
          aw882xx_dsp_noise_en(lVar3,0);
        }
        g_cali_status = 0;
        lVar2 = ((long *)plVar5[-0x92])[0xe];
        if (lVar2 == 0) {
          lVar2 = *(long *)plVar5[-0x92];
        }
        _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","disable");
        aw882xx_dev_iv_forbidden_output(lVar3,1);
        aw_cali_svc_run_mute(lVar3,*(undefined1 *)(plVar5 + -0x4d));
      }
    }
    else {
      lVar3 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011ef63,lVar3,"aw_cali_svc_devs_cali_f0_q");
    }
    goto LAB_0010d6a0;
  }
  if (*(char *)(param_1 + 0x2a1) == '\0') {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001201a1,lVar3,"aw_cali_svc_run_mute");
  }
  else {
    aw882xx_dev_mute(param_1,0);
  }
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar3,"aw_cali_svc_run_mute");
  aw882xx_dev_iv_forbidden_output(param_1,0);
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  g_cali_status = 1;
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar3,"aw_cali_svc_set_cali_status","enable");
  if (((param_3 >> 1 & 1) == 0) || (iVar1 = aw882xx_dsp_noise_en(param_1,1), -1 < iVar1)) {
    iVar1 = aw882xx_dsp_cali_en(param_1,2);
    if (-1 < iVar1) {
      msleep(5000);
      iVar1 = aw_cali_svc_dev_get_f0_q(param_1);
    }
    aw882xx_dsp_cali_en(param_1,0);
    if ((param_3 >> 1 & 1) != 0) goto LAB_0010d80c;
  }
  else {
    aw882xx_dsp_cali_en(param_1,0);
LAB_0010d80c:
    aw882xx_dsp_noise_en(param_1,0);
  }
  g_cali_status = 0;
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e33d,lVar3,"aw_cali_svc_set_cali_status","disable");
  aw882xx_dev_iv_forbidden_output(param_1,1);
  aw_cali_svc_run_mute(param_1,*(undefined1 *)(param_1 + 0x2a0));
LAB_0010d6a0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_cali_re @ 0010d89c size=280
// signature: undefined aw_cali_svc_get_devs_cali_re(void)
// callers: [cali_re_show, aw_cali_class_re_show, aw_cali_misc_read, re_show_show, aw_cali_class_cali_re_show]
//------------------------------------------------------------

int aw_cali_svc_get_devs_cali_re(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_40);
  if (iVar2 == 0) {
    plVar4 = (long *)*local_40;
    if (plVar4 == local_40) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar4 + -0x4cc);
        if (param_3 <= uVar1) {
          lVar3 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar3,"aw_cali_svc_get_devs_cali_re",(ulong)uVar1,param_3);
          iVar2 = -0x16;
          break;
        }
        iVar2 = iVar2 + 1;
        *(undefined4 *)(param_2 + (ulong)uVar1 * 4) = *(undefined4 *)((long)plVar4 + -0x274);
        plVar4 = (long *)*plVar4;
      } while (plVar4 != local_40);
    }
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar3,"aw_cali_svc_get_devs_cali_re");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_r0 @ 0010d9b8 size=360
// signature: undefined aw_cali_svc_get_devs_r0(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

int aw_cali_svc_get_devs_r0(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_3) {
          iVar3 = aw882xx_dsp_read_r0(plVar5 + -0xa1,param_2 + (ulong)uVar1 * 4);
          if (iVar3 != 0) {
            lVar4 = ((long *)plVar5[-0x92])[0xe];
            if (lVar4 == 0) {
              lVar4 = *(long *)plVar5[-0x92];
            }
            _printk(&DAT_00120fb0,lVar4,"aw_cali_svc_get_devs_r0");
            iVar2 = iVar3;
            break;
          }
          iVar2 = iVar2 + 1;
        }
        else {
          lVar4 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_0012303b,lVar4,"aw_cali_svc_get_devs_r0",(ulong)uVar1,param_3);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != local_60);
    }
  }
  else {
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar4,"aw_cali_svc_get_devs_r0");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_te @ 0010db24 size=360
// signature: undefined aw_cali_svc_get_devs_te(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

int aw_cali_svc_get_devs_te(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_3) {
          iVar3 = aw882xx_dsp_read_te(plVar5 + -0xa1,param_2 + (ulong)uVar1 * 4);
          if (iVar3 != 0) {
            lVar4 = ((long *)plVar5[-0x92])[0xe];
            if (lVar4 == 0) {
              lVar4 = *(long *)plVar5[-0x92];
            }
            _printk(&DAT_00120fb0,lVar4,"aw_cali_svc_get_devs_te");
            iVar2 = iVar3;
            break;
          }
          iVar2 = iVar2 + 1;
        }
        else {
          lVar4 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar4,"aw_cali_svc_get_devs_te",(ulong)uVar1,param_3);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != local_60);
    }
  }
  else {
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar4,"aw_cali_svc_get_devs_te");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_st @ 0010dc90 size=376
// signature: undefined aw_cali_svc_get_devs_st(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

int aw_cali_svc_get_devs_st(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_3) {
          iVar3 = aw882xx_dsp_read_st(plVar5 + -0xa1,param_2 + (ulong)(uVar1 << 1) * 4,
                                      param_2 + (ulong)(uVar1 << 1 | 1) * 4);
          if (iVar3 != 0) {
            lVar4 = ((long *)plVar5[-0x92])[0xe];
            if (lVar4 == 0) {
              lVar4 = *(long *)plVar5[-0x92];
            }
            _printk(&DAT_00120fb0,lVar4,"aw_cali_svc_get_devs_st");
            iVar2 = iVar3;
            break;
          }
          iVar2 = iVar2 + 1;
        }
        else {
          lVar4 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar4,"aw_cali_svc_get_devs_st",uVar1,param_3);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != local_60);
    }
  }
  else {
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar4,"aw_cali_svc_get_devs_st");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_cali_f0 @ 0010de0c size=304
// signature: undefined aw_cali_svc_get_devs_cali_f0(void)
// callers: [aw_cali_misc_read, aw_cali_class_f0_show, f0_show_show, cali_f0_show, aw_cali_class_cali_f0_show]
//------------------------------------------------------------

int aw_cali_svc_get_devs_cali_f0(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      plVar4 = local_60;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_3) {
          iVar2 = iVar2 + 1;
          *(int *)(param_2 + (ulong)uVar1 * 4) = (int)plVar5[-0x4e];
        }
        else {
          lVar3 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar3,"aw_cali_svc_get_devs_cali_f0",(ulong)uVar1,param_3);
          plVar4 = local_60;
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != plVar4);
    }
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar3,"aw_cali_svc_get_devs_cali_f0");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_f0 @ 0010df40 size=360
// signature: undefined aw_cali_svc_get_devs_f0(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

int aw_cali_svc_get_devs_f0(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_3) {
          iVar3 = aw882xx_dsp_read_f0(plVar5 + -0xa1,param_2 + (ulong)uVar1 * 4);
          if (iVar3 != 0) {
            lVar4 = ((long *)plVar5[-0x92])[0xe];
            if (lVar4 == 0) {
              lVar4 = *(long *)plVar5[-0x92];
            }
            _printk(&DAT_00120fb0,lVar4,"aw_cali_svc_get_devs_f0");
            iVar2 = iVar3;
            break;
          }
          iVar2 = iVar2 + 1;
        }
        else {
          lVar4 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar4,"aw_cali_svc_get_devs_f0",(ulong)uVar1,param_3);
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != local_60);
    }
  }
  else {
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar4,"aw_cali_svc_get_devs_f0");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_cali_f0_q @ 0010e0ac size=324
// signature: undefined aw_cali_svc_get_devs_cali_f0_q(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

int aw_cali_svc_get_devs_cali_f0_q(long param_1,long param_2,long param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  long *local_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_60);
  if (iVar2 == 0) {
    plVar5 = (long *)*local_60;
    if (plVar5 == local_60) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      plVar4 = local_60;
      do {
        uVar1 = *(uint *)((long)plVar5 + -0x4cc);
        if (uVar1 < param_4) {
          iVar2 = iVar2 + 1;
          *(int *)(param_2 + (ulong)uVar1 * 4) = (int)plVar5[-0x4e];
          *(undefined4 *)(param_3 + (ulong)*(uint *)((long)plVar5 + -0x4cc) * 4) =
               *(undefined4 *)((long)plVar5 + -0x26c);
        }
        else {
          lVar3 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar3 == 0) {
            lVar3 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00120f78,lVar3,"aw_cali_svc_get_devs_cali_f0_q",(ulong)uVar1,param_4);
          plVar4 = local_60;
        }
        plVar5 = (long *)*plVar5;
      } while (plVar5 != plVar4);
    }
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar3,"aw_cali_svc_get_devs_cali_f0_q");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_parse_re_dt @ 0010e1f4 size=284
// signature: undefined aw_cali_parse_re_dt(void)
// callers: [aw882xx_cali_init]
//------------------------------------------------------------

undefined8 aw_cali_parse_re_dt(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-re-min",param_1 + 0x48,1
                     ,0);
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x48) = 1000;
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00123891,lVar3,"aw_cali_parse_re_dt");
  }
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-re-max",param_1 + 0x44,1
                     ,0);
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0x44) = 50000;
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eefc,lVar3,"aw_cali_parse_re_dt");
  }
  plVar4 = *(long **)(param_1 + 0x78);
  lVar3 = plVar4[0xe];
  if (*(uint *)(param_1 + 0x48) < *(uint *)(param_1 + 0x44)) {
    if (lVar3 == 0) {
      lVar3 = *plVar4;
    }
    _printk(&DAT_00122dac,lVar3,"aw_cali_parse_re_dt");
    uVar2 = 0;
  }
  else {
    if (lVar3 == 0) {
      lVar3 = *plVar4;
    }
    _printk(&DAT_0011df12,lVar3,"aw_cali_parse_re_dt");
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw882xx_cali_init @ 0010e314 size=1168
// signature: undefined aw882xx_cali_init(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

void aw882xx_cali_init(undefined1 *param_1)

{
  char *pcVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  long *plVar5;
  undefined8 uVar6;
  long *plVar7;
  undefined4 local_44;
  char *local_40;
  long local_38;
  
  lVar4 = sp_el0;
  plVar7 = (long *)(param_1 + -0x218);
  local_38 = *(long *)(lVar4 + 0x638);
  *(undefined8 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *param_1 = 0;
  uVar6 = *(undefined8 *)(*plVar7 + 0x2e8);
  local_40 = (char *)0x0;
  local_44 = 0;
  iVar2 = of_property_read_variable_u32_array(uVar6,"aw-cali-check",&local_44,1,0);
  if (iVar2 < 0) {
    lVar4 = ((long *)*plVar7)[0xe];
    if (lVar4 == 0) {
      lVar4 = *(long *)*plVar7;
    }
    _printk(&DAT_00121d17,lVar4,"aw_cali_parse_dt");
    local_44._0_1_ = '\0';
    local_44 = 0;
  }
  else {
  }
  param_1[0x11] = (char)local_44;
  lVar4 = ((long *)*plVar7)[0xe];
  if (lVar4 == 0) {
    lVar4 = *(long *)*plVar7;
  }
  pcVar1 = "disable";
  if ((char)local_44 != '\0') {
    pcVar1 = "enable";
  }
  _printk(&DAT_0011d490,lVar4,"aw_cali_parse_dt",pcVar1);
  iVar2 = of_property_read_string(uVar6,"aw-cali-mode",&local_40);
  if (iVar2 < 0) {
    param_1[1] = 1;
    lVar4 = ((long *)*plVar7)[0xe];
    if (lVar4 == 0) {
      lVar4 = *(long *)*plVar7;
    }
    _printk(&DAT_0011eb6c,lVar4,"aw_cali_parse_dt");
  }
  else {
    iVar2 = strcmp(local_40,"none");
    param_1[1] = iVar2 != 0;
    lVar4 = ((long *)*plVar7)[0xe];
    if (lVar4 == 0) {
      lVar4 = *(long *)*plVar7;
    }
    _printk(&DAT_0011fe9f,lVar4,"aw_cali_parse_dt",iVar2 != 0);
  }
  plVar5 = (long *)*plVar7;
  lVar4 = plVar5[0xe];
  if (param_1[1] == '\x01') {
    if (lVar4 == 0) {
      lVar4 = *plVar5;
    }
    _printk(&DAT_00120075,lVar4,"aw_cali_attr_init");
    iVar2 = sysfs_create_group(*plVar7,aw_cali_attr_group);
    if (iVar2 < 0) {
      lVar4 = ((long *)*plVar7)[0xe];
      if (lVar4 == 0) {
        lVar4 = *(long *)*plVar7;
      }
      _printk(&DAT_00120fd2,lVar4,"aw_cali_attr_init");
    }
    if (*(int *)(param_1 + -0x254) == 0) {
      iVar2 = __class_register(&aw_cali_class,&aw_cali_class_attr_init___key);
      if (iVar2 < 0) {
        lVar4 = ((long *)*plVar7)[0xe];
        if (lVar4 == 0) {
          lVar4 = *(long *)*plVar7;
        }
        puVar3 = &DAT_00121577;
      }
      else {
        iVar2 = class_create_file_ns(&aw_cali_class,&class_attr_re25_calib,0);
        if (iVar2 != 0) {
          lVar4 = ((long *)*plVar7)[0xe];
          if (lVar4 == 0) {
            lVar4 = *(long *)*plVar7;
          }
          _printk(&DAT_0011d7c2,lVar4,"aw_cali_class_attr_init");
        }
        iVar2 = class_create_file_ns(&aw_cali_class,&class_attr_f0_calib,0);
        if (iVar2 != 0) {
          lVar4 = ((long *)*plVar7)[0xe];
          if (lVar4 == 0) {
            lVar4 = *(long *)*plVar7;
          }
          _printk(&DAT_0011d7c2,lVar4,"aw_cali_class_attr_init");
        }
        iVar2 = class_create_file_ns(&aw_cali_class,&class_attr_cali_time,0);
        if (iVar2 != 0) {
          lVar4 = ((long *)*plVar7)[0xe];
          if (lVar4 == 0) {
            lVar4 = *(long *)*plVar7;
          }
          _printk(&DAT_0011eb94,lVar4,"aw_cali_class_attr_init");
        }
        iVar2 = class_create_file_ns(&aw_cali_class,&class_attr_re_show,0);
        if (iVar2 != 0) {
          lVar4 = ((long *)*plVar7)[0xe];
          if (lVar4 == 0) {
            lVar4 = *(long *)*plVar7;
          }
          _printk(&DAT_0011ef99,lVar4,"aw_cali_class_attr_init");
        }
        iVar2 = class_create_file_ns(&aw_cali_class,&class_attr_f0_show,0);
        if (iVar2 != 0) {
          lVar4 = ((long *)*plVar7)[0xe];
          if (lVar4 == 0) {
            lVar4 = *(long *)*plVar7;
          }
          _printk(&DAT_0011f9e7,lVar4,"aw_cali_class_attr_init");
        }
        iVar2 = class_create_file_ns(&aw_cali_class,&class_att_re_range,0);
        if (iVar2 == 0) goto LAB_0010e5c8;
        lVar4 = ((long *)*plVar7)[0xe];
        if (lVar4 == 0) {
          lVar4 = *(long *)*plVar7;
        }
        puVar3 = &DAT_001222ee;
      }
    }
    else {
      lVar4 = ((long *)*plVar7)[0xe];
      if (lVar4 == 0) {
        lVar4 = *(long *)*plVar7;
      }
      puVar3 = &DAT_0012267b;
    }
    _printk(puVar3,lVar4,"aw_cali_class_attr_init");
  }
  else {
    if (lVar4 == 0) {
      lVar4 = *plVar5;
    }
    _printk(&DAT_0011fe9f,lVar4,"aw882xx_cali_init");
  }
LAB_0010e5c8:
  mutex_lock(g_cali_lock);
  if (g_misc_dev == (undefined1 *)0x0) {
    iVar2 = misc_register(misc_cali);
    if (iVar2 == 0) {
      g_misc_dev = misc_cali;
    }
    else {
      lVar4 = ((long *)*plVar7)[0xe];
      if (lVar4 == 0) {
        lVar4 = *(long *)*plVar7;
      }
      _printk(&DAT_0011d05a,lVar4,"aw_cali_misc_init",iVar2);
    }
  }
  mutex_unlock(g_cali_lock);
  aw_cali_parse_re_dt(param_1 + -0x290);
  param_1[0x10] = 0;
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_cali_deinit @ 0010e7a8 size=320
// signature: undefined aw882xx_cali_deinit(void)
// callers: [aw882xx_dev_remove]
//------------------------------------------------------------

void aw882xx_cali_deinit(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  
  if (*(char *)(param_1 + 1) == '\x01') {
    puVar2 = (undefined8 *)(param_1 + -0x218);
    sysfs_remove_group(*puVar2,aw_cali_attr_group);
    lVar1 = ((long *)*puVar2)[0xe];
    if (lVar1 == 0) {
      lVar1 = *(long *)*puVar2;
    }
    _printk(&DAT_00123346,lVar1,"aw_cali_attr_deinit");
    class_remove_file_ns(&aw_cali_class,&class_att_re_range,0);
    class_remove_file_ns(&aw_cali_class,&class_attr_re25_calib,0);
    class_remove_file_ns(&aw_cali_class,&class_attr_f0_calib,0);
    class_remove_file_ns(&aw_cali_class,&class_attr_cali_time,0);
    class_remove_file_ns(&aw_cali_class,&class_attr_re_show,0);
    class_remove_file_ns(&aw_cali_class,&class_attr_f0_show,0);
    class_unregister(&aw_cali_class);
    lVar1 = ((long *)*puVar2)[0xe];
    if (lVar1 == 0) {
      lVar1 = *(long *)*puVar2;
    }
    _printk(&DAT_0011cd1e,lVar1,"aw_cali_class_attr_deinit");
  }
  mutex_lock(g_cali_lock);
  if (g_misc_dev != 0) {
    misc_deregister();
    g_misc_dev = 0;
  }
  mutex_unlock(g_cali_lock);
  return;
}



//------------------------------------------------------------
// aw_cali_svc_dev_cali_mode_en @ 0010e8e8 size=308
// signature: undefined aw_cali_svc_dev_cali_mode_en(void)
// callers: [aw_cali_svc_devs_cali_mode_enable]
//------------------------------------------------------------

undefined8 aw_cali_svc_dev_cali_mode_en(long param_1,int param_2,ulong param_3,uint param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  if ((param_3 & 1) == 0) {
    aw882xx_dsp_cali_en(param_1,0);
    if (param_2 == 0) {
      if ((param_4 & 1) != 0) {
        aw882xx_dsp_hmute_en(param_1,0);
      }
    }
    else if ((param_4 >> 1 & 1) != 0) {
      aw882xx_dsp_noise_en(param_1,0);
    }
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    g_cali_status = 0;
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","disable");
    aw882xx_dev_iv_forbidden_output(param_1,1);
  }
  else {
    aw882xx_dev_iv_forbidden_output();
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    g_cali_status = 1;
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011e33d,lVar2,"aw_cali_svc_set_cali_status","enable");
    if (param_2 == 0) {
      if (((param_4 & 1) != 0) && (uVar1 = aw882xx_dsp_hmute_en(param_1,1), (int)uVar1 < 0)) {
        return uVar1;
      }
      uVar1 = 1;
    }
    else {
      if (((param_4 >> 1 & 1) != 0) && (uVar1 = aw882xx_dsp_noise_en(param_1,1), (int)uVar1 < 0)) {
        return uVar1;
      }
      uVar1 = 2;
    }
    uVar1 = aw882xx_dsp_cali_en(param_1,uVar1);
    if ((int)uVar1 < 0) {
      return uVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// aw_cali_svc_dev_get_re @ 0010ea1c size=600
// signature: undefined aw_cali_svc_dev_get_re(void)
// callers: [aw_cali_svc_cali_re]
//------------------------------------------------------------

int aw_cali_svc_dev_get_re(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  iVar8 = aw882xx_dsp_read_r0(param_1,&local_88);
  if (iVar8 == 0) {
    iVar1 = (int)local_88;
    usleep_range_state(32000,0x7d0a,2);
    iVar8 = aw882xx_dsp_read_r0(param_1,(ulong)&local_88 | 4);
    if (iVar8 == 0) {
      iVar2 = local_88._4_4_;
      usleep_range_state(32000,0x7d0a,2);
      iVar8 = aw882xx_dsp_read_r0(param_1,&local_80);
      if (iVar8 == 0) {
        iVar3 = (int)local_80;
        usleep_range_state(32000,0x7d0a,2);
        iVar8 = aw882xx_dsp_read_r0(param_1,(long)&local_80 + 4);
        if (iVar8 == 0) {
          iVar4 = local_80._4_4_;
          usleep_range_state(32000,0x7d0a,2);
          iVar8 = aw882xx_dsp_read_r0(param_1,&local_78);
          if (iVar8 == 0) {
            iVar5 = (int)local_78;
            usleep_range_state(32000,0x7d0a,2);
            iVar8 = aw882xx_dsp_read_r0(param_1,(long)&local_78 + 4);
            if (iVar8 == 0) {
              iVar6 = local_78._4_4_;
              usleep_range_state(32000,0x7d0a,2);
              iVar8 = aw882xx_dsp_read_r0(param_1,&local_70);
              if (iVar8 == 0) {
                iVar7 = (int)local_70;
                usleep_range_state(32000,0x7d0a,2);
                iVar8 = aw882xx_dsp_read_r0(param_1,(long)&local_70 + 4);
                if (iVar8 == 0) {
                  iVar8 = local_70._4_4_ + iVar7 + iVar6 + iVar5 + iVar4 + iVar3 + iVar2 + iVar1;
                  usleep_range_state(32000,0x7d0a,2);
                  iVar1 = iVar8 + 7;
                  if (-1 < iVar8) {
                    iVar1 = iVar8;
                  }
                  local_88 = CONCAT44(local_88._4_4_,iVar1 >> 3);
                  *(int *)(param_1 + 0x294) = iVar1 >> 3;
                  aw_cali_store_cali_re(param_1);
                  iVar8 = 0;
                  goto LAB_0010ebf8;
                }
              }
            }
          }
        }
      }
    }
  }
  lVar9 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar9 == 0) {
    lVar9 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120fb0,lVar9,"aw_cali_svc_dev_get_re");
  if (*(char *)(param_1 + 0x2a1) != '\0') {
    *(undefined1 *)(param_1 + 0x2a0) = 0xff;
    aw882xx_dev_mute(param_1,1);
    lVar9 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar9 == 0) {
      lVar9 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011df48,lVar9,"aw_cali_svc_run_mute");
  }
LAB_0010ebf8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// aw_cali_svc_devs_cali_mode_enable @ 0010ec74 size=324
// signature: undefined aw_cali_svc_devs_cali_mode_enable(void)
// callers: [aw_cali_svc_cali_re, aw_cali_svc_cali_f0, aw_cali_svc_cali_f0_q]
//------------------------------------------------------------

undefined8
aw_cali_svc_devs_cali_mode_enable(long *param_1,int param_2,undefined4 param_3,uint param_4)

{
  undefined8 uVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  
  plVar4 = (long *)*param_1;
  if (plVar4 != param_1) {
    do {
      plVar3 = plVar4 + -0xa1;
      if ((param_4 & 1) == 0) {
        uVar1 = aw_cali_svc_dev_cali_mode_en(plVar3,param_2,param_4 & 1,param_3);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
        if (param_2 == 1 && (param_4 & 1) == 0) {
          aw_cali_svc_run_mute(plVar3,(char)plVar4[-0x4d]);
        }
      }
      else {
        if (*(char *)((long)plVar4 + -0x267) == '\0') {
          lVar2 = ((long *)plVar4[-0x92])[0xe];
          if (lVar2 == 0) {
            lVar2 = *(long *)plVar4[-0x92];
          }
          _printk(&DAT_001201a1,lVar2,"aw_cali_svc_run_mute");
        }
        else {
          aw882xx_dev_mute(plVar3,0);
        }
        lVar2 = ((long *)plVar4[-0x92])[0xe];
        if (lVar2 == 0) {
          lVar2 = *(long *)plVar4[-0x92];
        }
        _printk(&DAT_0011df48,lVar2,"aw_cali_svc_run_mute");
        uVar1 = aw_cali_svc_dev_cali_mode_en(plVar3,param_2,param_4 & 1,param_3);
        if ((int)uVar1 < 0) {
          return uVar1;
        }
      }
      plVar4 = (long *)*plVar4;
    } while (plVar4 != param_1);
  }
  return 0;
}



//------------------------------------------------------------
// aw_cali_svc_dev_get_f0 @ 0010edb8 size=436
// signature: undefined aw_cali_svc_dev_get_f0(void)
// callers: [aw_cali_svc_cali_f0]
//------------------------------------------------------------

int aw_cali_svc_dev_get_f0(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined8 local_70;
  undefined8 local_68;
  int local_60 [2];
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60[0] = 0;
  local_70 = 0;
  local_68 = 0;
  iVar5 = aw882xx_dsp_read_f0(param_1,&local_70);
  if (iVar5 == 0) {
    iVar1 = (int)local_70;
    usleep_range_state(70000,0x1117a,2);
    iVar5 = aw882xx_dsp_read_f0(param_1,(ulong)&local_70 | 4);
    if (iVar5 == 0) {
      iVar2 = local_70._4_4_;
      usleep_range_state(70000,0x1117a,2);
      iVar5 = aw882xx_dsp_read_f0(param_1,&local_68);
      if (iVar5 == 0) {
        iVar3 = (int)local_68;
        usleep_range_state(70000,0x1117a,2);
        iVar5 = aw882xx_dsp_read_f0(param_1,(long)&local_68 + 4);
        if (iVar5 == 0) {
          iVar4 = local_68._4_4_;
          usleep_range_state(70000,0x1117a,2);
          iVar5 = aw882xx_dsp_read_f0(param_1,local_60);
          if (iVar5 == 0) {
            iVar1 = local_60[0] + iVar4 + iVar3 + iVar2 + iVar1;
            usleep_range_state(70000,0x1117a,2);
            iVar5 = 0;
            *(int *)(param_1 + 0x298) = iVar1 / 5;
            goto LAB_0010ef30;
          }
        }
      }
    }
  }
  lVar6 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar6 == 0) {
    lVar6 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120786,lVar6,"aw_cali_svc_dev_get_f0");
LAB_0010ef30:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// aw_cali_svc_dev_get_f0_q @ 0010ef6c size=548
// signature: undefined aw_cali_svc_dev_get_f0_q(void)
// callers: [aw_cali_svc_cali_f0_q]
//------------------------------------------------------------

int aw_cali_svc_dev_get_f0_q(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  long lVar10;
  undefined8 local_98;
  undefined8 local_90;
  int local_88 [2];
  undefined8 local_80;
  undefined8 local_78;
  int local_70 [2];
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_70[0] = 0;
  local_80 = 0;
  local_78 = 0;
  local_88[0] = 0;
  local_98 = 0;
  local_90 = 0;
  iVar9 = aw882xx_dsp_read_f0_q(param_1,&local_80,&local_98);
  if (iVar9 == 0) {
    iVar1 = (int)local_80;
    iVar2 = (int)local_98;
    usleep_range_state(70000,0x1117a,2);
    iVar9 = aw882xx_dsp_read_f0_q(param_1,(ulong)&local_80 | 4,(ulong)&local_98 | 4);
    if (iVar9 == 0) {
      iVar6 = local_80._4_4_;
      iVar3 = local_98._4_4_;
      usleep_range_state(70000,0x1117a,2);
      iVar9 = aw882xx_dsp_read_f0_q(param_1,&local_78,&local_90);
      if (iVar9 == 0) {
        iVar7 = (int)local_78;
        iVar4 = (int)local_90;
        usleep_range_state(70000,0x1117a,2);
        iVar9 = aw882xx_dsp_read_f0_q(param_1,(long)&local_78 + 4,(long)&local_90 + 4);
        if (iVar9 == 0) {
          iVar8 = local_78._4_4_;
          iVar5 = local_90._4_4_;
          usleep_range_state(70000,0x1117a,2);
          iVar9 = aw882xx_dsp_read_f0_q(param_1,local_70,local_88);
          if (iVar9 == 0) {
            iVar1 = local_70[0] + iVar8 + iVar7 + iVar6 + iVar1;
            iVar2 = local_88[0] + iVar5 + iVar4 + iVar3 + iVar2;
            usleep_range_state(70000,0x1117a,2);
            *(int *)(param_1 + 0x298) = iVar1 / 5;
            *(int *)(param_1 + 0x29c) = iVar2 / 5;
            goto LAB_0010f150;
          }
        }
      }
    }
  }
  lVar10 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar10 == 0) {
    lVar10 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120786,lVar10,"aw_cali_svc_dev_get_f0_q");
LAB_0010f150:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// cali_time_show @ 0010f194 size=56
// signature: undefined cali_time_show(void)
// callers: []
//------------------------------------------------------------

long cali_time_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"time: %d\n",g_cali_re_time);
  return (long)iVar1;
}



//------------------------------------------------------------
// cali_time_store @ 0010f1d0 size=244
// signature: undefined cali_time_store(void)
// callers: []
//------------------------------------------------------------

long cali_time_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar1 = kstrtoint(param_3,0,&local_3c);
  if (iVar1 < 0) {
    plVar2 = *(long **)(lVar3 + 0x78);
    lVar3 = plVar2[0xe];
    if (lVar3 == 0) {
      lVar3 = *plVar2;
    }
    _printk(&DAT_0011d4b2,lVar3,"cali_time_store",param_3);
    param_4 = (long)iVar1;
  }
  else if (local_3c < 400) {
    plVar2 = *(long **)(lVar3 + 0x78);
    lVar3 = plVar2[0xe];
    if (lVar3 == 0) {
      lVar3 = *plVar2;
    }
    _printk(&DAT_001207b2,lVar3,"cali_time_store");
    param_4 = -0x16;
  }
  else {
    g_cali_re_time = local_3c;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// cali_store @ 0010f2c8 size=224
// signature: undefined cali_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cali_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar1 = aw_cali_svc_get_cmd_form_str(lVar3,param_3);
  if (-1 < iVar1) {
    if (iVar1 == 3) {
      aw_cali_svc_cali_f0(lVar3,0,2);
      return param_4;
    }
    if (iVar1 == 2) {
      aw_cali_svc_cali_re(lVar3,0,1);
      return param_4;
    }
    if (iVar1 == 1) {
      iVar1 = aw_cali_svc_cali_re(lVar3,0,3);
      if (iVar1 == 0) {
        aw_cali_svc_cali_f0(lVar3,0,3);
        return param_4;
      }
      return param_4;
    }
  }
  lVar2 = (*(long **)(lVar3 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(lVar3 + 0x78);
  }
  _printk(&DAT_001238c7,lVar2,"cali_store",param_3);
  return 0xffffffffffffffff;
}



//------------------------------------------------------------
// aw_cali_svc_get_cmd_form_str @ 0010f3a8 size=216
// signature: undefined aw_cali_svc_get_cmd_form_str(void)
// callers: [aw_cali_misc_write, cali_store]
//------------------------------------------------------------

ulong aw_cali_svc_get_cmd_form_str(long param_1,char *param_2)

{
  code *pcVar1;
  int iVar2;
  size_t __n;
  long lVar3;
  ulong uVar4;
  char *__s;
  
  uVar4 = 0;
  do {
    __s = (&cali_str)[uVar4];
    __n = strlen(__s);
    iVar2 = strncmp(__s,param_2,__n);
    if (iVar2 == 0) {
      lVar3 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar3 == 0) {
        lVar3 = **(long **)(param_1 + 0x78);
      }
      if (0x10 < (uint)uVar4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10f480);
        (*pcVar1)();
      }
      _printk(&DAT_0011fec2,lVar3,"aw_cali_svc_get_cmd_form_str",(&cali_str)[uVar4]);
      goto LAB_0010f460;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 != 0x11);
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_001238c7,lVar3,"aw_cali_svc_get_cmd_form_str",param_2);
  uVar4 = 0xffffffea;
LAB_0010f460:
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// cali_re_show @ 0010f484 size=668
// signature: undefined cali_re_show(void)
// callers: []
//------------------------------------------------------------

void cali_re_show(long param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar4 = aw_cali_svc_cali_re(lVar7,0,1);
  uVar2 = s_cali_Re_cmd_failed_0011f6c9._8_8_;
  uVar1 = s_cali_Re_cmd_failed_0011f6c9._0_8_;
  if (iVar4 < 0) {
    lVar7 = 0x13;
    param_3[0x10] = 'e';
    param_3[0x11] = 'd';
    param_3[0x12] = '\n';
    param_3[0x13] = '\0';
    *(undefined8 *)param_3 = uVar1;
    *(undefined8 *)(param_3 + 8) = uVar2;
  }
  else {
    iVar4 = aw_cali_svc_get_devs_cali_re(lVar7,&local_58,8);
    if (iVar4 < 1) {
      lVar6 = (*(long **)(lVar7 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar7 + 0x78);
      }
      _printk(&DAT_001207e2,lVar6,"cali_re_show");
      lVar7 = 0xe;
      uVar1 = CONCAT71(s_get_re_failed_0011e6d8._8_7_,s_get_re_failed_0011e6d8[7]);
      *(ulong *)param_3 = CONCAT17(s_get_re_failed_0011e6d8[7],s_get_re_failed_0011e6d8._0_7_);
      *(undefined8 *)(param_3 + 7) = uVar1;
    }
    else {
      iVar5 = snprintf(param_3,0x1000,"%s:%d mOhms ","pri_l",(int)local_58);
      lVar7 = (long)iVar5;
      if (iVar4 != 1) {
        iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","pri_r",local_58._4_4_);
        lVar7 = lVar7 + iVar5;
        if (iVar4 != 2) {
          iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","sec_l",(int)local_50);
          lVar7 = lVar7 + iVar5;
          if (iVar4 != 3) {
            iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","sec_r",local_50._4_4_);
            lVar7 = lVar7 + iVar5;
            if (iVar4 != 4) {
              iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","tert_l",(int)local_48)
              ;
              lVar7 = lVar7 + iVar5;
              if (iVar4 != 5) {
                iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","tert_r",
                                 local_48._4_4_);
                lVar7 = lVar7 + iVar5;
                if (iVar4 != 6) {
                  iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","quat_l",
                                   (int)local_40);
                  lVar7 = lVar7 + iVar5;
                  if (iVar4 != 7) {
                    iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","quat_r",
                                     local_40._4_4_);
                    if (iVar4 != 8) {
                    /* WARNING: Does not return */
                      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10f720);
                      (*pcVar3)();
                    }
                    lVar7 = lVar7 + iVar5;
                  }
                }
              }
            }
          }
        }
      }
      iVar4 = snprintf(param_3 + lVar7,0x1000 - lVar7,"\n");
      lVar7 = lVar7 + iVar4;
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// cali_re_store @ 0010f724 size=128
// signature: undefined cali_re_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cali_re_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar1 = aw_cali_svc_set_devs_re_str(lVar3,param_3);
  if (iVar1 < 1) {
    plVar2 = *(long **)(lVar3 + 0x78);
    lVar3 = plVar2[0xe];
    if (lVar3 == 0) {
      lVar3 = *plVar2;
    }
    _printk(&DAT_0011e35e,lVar3,"cali_re_store",param_3);
    param_4 = 0xffffffffffffffff;
  }
  return param_4;
}



//------------------------------------------------------------
// aw_cali_svc_set_devs_re_str @ 0010f7a4 size=360
// signature: undefined aw_cali_svc_set_devs_re_str(void)
// callers: [cali_re_store, aw_cali_class_cali_re_store, aw_cali_misc_write]
//------------------------------------------------------------

int aw_cali_svc_set_devs_re_str(long param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  long *local_60;
  int aiStack_58 [8];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_60 = (long *)0x0;
  aiStack_58[0] = 0;
  aiStack_58[1] = 0;
  aiStack_58[4] = 0;
  aiStack_58[5] = 0;
  aiStack_58[6] = 0;
  aiStack_58[7] = 0;
  aiStack_58[2] = 0;
  aiStack_58[3] = 0;
  iVar1 = aw882xx_dev_get_list_head(&local_60);
  if (iVar1 == 0) {
    iVar1 = sscanf(param_2,
                   "pri_l:%d pri_r:%d sec_l:%d sec_r:%d tert_l:%d tert_r:%d quat_l:%d quat_r:%d",
                   aiStack_58,(int *)((ulong)aiStack_58 | 4),aiStack_58 + 2,aiStack_58 + 3,
                   aiStack_58 + 4,aiStack_58 + 5,aiStack_58 + 6,aiStack_58 + 7);
    if (iVar1 < 1) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_00122a07,lVar2,"aw_cali_svc_set_devs_re_str",param_2);
    }
    else {
      plVar4 = (long *)*local_60;
      if (plVar4 == local_60) {
        iVar1 = 0;
      }
      else {
        iVar1 = 0;
        plVar3 = local_60;
        do {
          if (*(uint *)((long)plVar4 + -0x4cc) < 8) {
            aw_cali_store_cali_re(plVar4 + -0xa1,aiStack_58[*(uint *)((long)plVar4 + -0x4cc)]);
            iVar1 = iVar1 + 1;
            plVar3 = local_60;
          }
          plVar4 = (long *)*plVar4;
        } while (plVar4 != plVar3);
      }
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar2,"aw_cali_svc_set_devs_re_str");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// cali_f0_show @ 0010f910 size=668
// signature: undefined cali_f0_show(void)
// callers: []
//------------------------------------------------------------

void cali_f0_show(long param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar4 = aw_cali_svc_cali_f0(lVar7,0,2);
  uVar2 = s_cali_f0_cmd_failed_00120a0d._8_8_;
  uVar1 = s_cali_f0_cmd_failed_00120a0d._0_8_;
  if (iVar4 < 0) {
    lVar7 = 0x13;
    param_3[0x10] = 'e';
    param_3[0x11] = 'd';
    param_3[0x12] = '\n';
    param_3[0x13] = '\0';
    *(undefined8 *)param_3 = uVar1;
    *(undefined8 *)(param_3 + 8) = uVar2;
  }
  else {
    iVar4 = aw_cali_svc_get_devs_cali_f0(lVar7,&local_58,8);
    if (iVar4 < 1) {
      lVar6 = (*(long **)(lVar7 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar7 + 0x78);
      }
      _printk(&DAT_0011f6dd,lVar6,"cali_f0_show");
      lVar7 = 0xe;
      uVar1 = CONCAT71(s_get_f0_failed_0011f9c8._8_7_,s_get_f0_failed_0011f9c8[7]);
      *(ulong *)param_3 = CONCAT17(s_get_f0_failed_0011f9c8[7],s_get_f0_failed_0011f9c8._0_7_);
      *(undefined8 *)(param_3 + 7) = uVar1;
    }
    else {
      iVar5 = snprintf(param_3,0x1000,"%s:%d ","pri_l",(int)local_58);
      lVar7 = (long)iVar5;
      if (iVar4 != 1) {
        iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","pri_r",local_58._4_4_);
        lVar7 = lVar7 + iVar5;
        if (iVar4 != 2) {
          iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","sec_l",(int)local_50);
          lVar7 = lVar7 + iVar5;
          if (iVar4 != 3) {
            iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","sec_r",local_50._4_4_);
            lVar7 = lVar7 + iVar5;
            if (iVar4 != 4) {
              iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","tert_l",(int)local_48);
              lVar7 = lVar7 + iVar5;
              if (iVar4 != 5) {
                iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","tert_r",local_48._4_4_);
                lVar7 = lVar7 + iVar5;
                if (iVar4 != 6) {
                  iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","quat_l",(int)local_40);
                  lVar7 = lVar7 + iVar5;
                  if (iVar4 != 7) {
                    iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","quat_r",local_40._4_4_
                                    );
                    if (iVar4 != 8) {
                    /* WARNING: Does not return */
                      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10fbac);
                      (*pcVar3)();
                    }
                    lVar7 = lVar7 + iVar5;
                  }
                }
              }
            }
          }
        }
      }
      iVar4 = snprintf(param_3 + lVar7,0x1000 - lVar7,"\n");
      lVar7 = lVar7 + iVar4;
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// cali_f0_store @ 0010fbb0 size=60
// signature: undefined cali_f0_store(void)
// callers: []
//------------------------------------------------------------

undefined8 cali_f0_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  aw_cali_svc_cali_f0(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x68),0,2);
  return param_4;
}



//------------------------------------------------------------
// re_show_show @ 0010fbf0 size=588
// signature: undefined re_show_show(void)
// callers: []
//------------------------------------------------------------

long re_show_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar3 = aw_cali_svc_get_devs_cali_re(lVar6,&local_58,8);
  if (iVar3 < 1) {
    plVar5 = *(long **)(lVar6 + 0x78);
    lVar6 = plVar5[0xe];
    if (lVar6 == 0) {
      lVar6 = *plVar5;
    }
    _printk(&DAT_001207e2,lVar6,"re_show_show");
    lVar6 = 0;
  }
  else {
    iVar4 = snprintf(param_3,0x1000,"%s:%d mOhms ","pri_l",(int)local_58);
    lVar6 = (long)iVar4;
    if (iVar3 != 1) {
      iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","pri_r",local_58._4_4_);
      lVar6 = lVar6 + iVar4;
      if (iVar3 != 2) {
        iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","sec_l",(int)local_50);
        lVar6 = lVar6 + iVar4;
        if (iVar3 != 3) {
          iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","sec_r",local_50._4_4_);
          lVar6 = lVar6 + iVar4;
          if (iVar3 != 4) {
            iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","tert_l",(int)local_48);
            lVar6 = lVar6 + iVar4;
            if (iVar3 != 5) {
              iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","tert_r",local_48._4_4_
                              );
              lVar6 = lVar6 + iVar4;
              if (iVar3 != 6) {
                iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","quat_l",
                                 (int)local_40);
                lVar6 = lVar6 + iVar4;
                if (iVar3 != 7) {
                  iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms ","quat_r",
                                   local_40._4_4_);
                  if (iVar3 != 8) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10fe3c);
                    (*pcVar2)();
                  }
                  lVar6 = lVar6 + iVar4;
                }
              }
            }
          }
        }
      }
    }
  }
  iVar3 = snprintf(param_3 + lVar6,0x1000 - lVar6,"\n");
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar6 + iVar3;
}



//------------------------------------------------------------
// f0_show_show @ 0010fe40 size=588
// signature: undefined f0_show_show(void)
// callers: []
//------------------------------------------------------------

void f0_show_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar3 = aw_cali_svc_get_devs_cali_f0(lVar6,&local_58,8);
  if (iVar3 < 1) {
    plVar5 = *(long **)(lVar6 + 0x78);
    lVar6 = plVar5[0xe];
    if (lVar6 == 0) {
      lVar6 = *plVar5;
    }
    _printk(&DAT_0011f2e3,lVar6,"f0_show_show");
    lVar6 = 0;
  }
  else {
    iVar4 = snprintf(param_3,0x1000,"%s:%d","pri_l",(int)local_58);
    lVar6 = (long)iVar4;
    if (iVar3 != 1) {
      iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","pri_r",local_58._4_4_);
      lVar6 = lVar6 + iVar4;
      if (iVar3 != 2) {
        iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","sec_l",(int)local_50);
        lVar6 = lVar6 + iVar4;
        if (iVar3 != 3) {
          iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","sec_r",local_50._4_4_);
          lVar6 = lVar6 + iVar4;
          if (iVar3 != 4) {
            iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","tert_l",(int)local_48);
            lVar6 = lVar6 + iVar4;
            if (iVar3 != 5) {
              iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","tert_r",local_48._4_4_);
              lVar6 = lVar6 + iVar4;
              if (iVar3 != 6) {
                iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","quat_l",(int)local_40);
                lVar6 = lVar6 + iVar4;
                if (iVar3 != 7) {
                  iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","quat_r",local_40._4_4_);
                  if (iVar3 != 8) {
                    /* WARNING: Does not return */
                    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11008c);
                    (*pcVar2)();
                  }
                  lVar6 = lVar6 + iVar4;
                }
              }
            }
          }
        }
      }
    }
    iVar3 = snprintf(param_3 + lVar6,0x1000 - lVar6,"\n");
    lVar6 = lVar6 + iVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// re_range_show @ 00110090 size=112
// signature: undefined re_range_show(void)
// callers: []
//------------------------------------------------------------

long re_range_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  iVar2 = *(int *)(lVar3 + 0x44);
  iVar1 = snprintf(param_3,0x1000,"re_min value: [%d] mOhms\n",*(int *)(lVar3 + 0x48));
  lVar3 = (long)iVar1;
  iVar2 = snprintf(param_3 + lVar3,0x1000 - lVar3,"re_max value: [%d] mOhms\n",iVar2);
  return lVar3 + iVar2;
}



//------------------------------------------------------------
// aw_cali_class_cali_re_show @ 00110104 size=724
// signature: undefined aw_cali_class_cali_re_show(void)
// callers: []
//------------------------------------------------------------

void aw_cali_class_cali_re_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_60 = (long *)0x0;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar4 = aw882xx_dev_get_list_head(&local_60);
  if (iVar4 == 0) {
    lVar8 = *local_60;
    lVar7 = lVar8 + -0x508;
    iVar4 = aw_cali_svc_cali_re(lVar7,0,1);
    uVar2 = s_cali_Re_cmd_failed_0011f6c9._8_8_;
    uVar1 = s_cali_Re_cmd_failed_0011f6c9._0_8_;
    if (iVar4 < 0) {
      lVar7 = 0x13;
      param_3[0x10] = 'e';
      param_3[0x11] = 'd';
      param_3[0x12] = '\n';
      param_3[0x13] = '\0';
      *(undefined8 *)param_3 = uVar1;
      *(undefined8 *)(param_3 + 8) = uVar2;
    }
    else {
      iVar4 = aw_cali_svc_get_devs_cali_re(lVar7,&local_58,8);
      if (iVar4 < 1) {
        plVar6 = *(long **)(lVar8 + -0x490);
        lVar7 = plVar6[0xe];
        if (lVar7 == 0) {
          lVar7 = *plVar6;
        }
        _printk(&DAT_00120a2e,lVar7,"aw_cali_class_cali_re_show");
        lVar7 = 0xe;
        uVar1 = CONCAT71(s_get_re_failed_0011e6d8._8_7_,s_get_re_failed_0011e6d8[7]);
        *(ulong *)param_3 = CONCAT17(s_get_re_failed_0011e6d8[7],s_get_re_failed_0011e6d8._0_7_);
        *(undefined8 *)(param_3 + 7) = uVar1;
      }
      else {
        iVar5 = snprintf(param_3,0x1000,"%s:%d mOhms ","pri_l",(int)local_58);
        lVar7 = (long)iVar5;
        if (iVar4 != 1) {
          iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","pri_r",local_58._4_4_);
          lVar7 = lVar7 + iVar5;
          if (iVar4 != 2) {
            iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","sec_l",(int)local_50);
            lVar7 = lVar7 + iVar5;
            if (iVar4 != 3) {
              iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","sec_r",local_50._4_4_)
              ;
              lVar7 = lVar7 + iVar5;
              if (iVar4 != 4) {
                iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","tert_l",
                                 (int)local_48);
                lVar7 = lVar7 + iVar5;
                if (iVar4 != 5) {
                  iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","tert_r",
                                   local_48._4_4_);
                  lVar7 = lVar7 + iVar5;
                  if (iVar4 != 6) {
                    iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","quat_l",
                                     (int)local_40);
                    lVar7 = lVar7 + iVar5;
                    if (iVar4 != 7) {
                      iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d mOhms ","quat_r",
                                       local_40._4_4_);
                      if (iVar4 != 8) {
                    /* WARNING: Does not return */
                        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1103d8);
                        (*pcVar3)();
                      }
                      lVar7 = lVar7 + iVar5;
                    }
                  }
                }
              }
            }
          }
        }
        iVar4 = snprintf(param_3 + lVar7,0x1000 - lVar7,"\n");
        lVar7 = lVar7 + iVar4;
      }
    }
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_cali_re_show");
    lVar7 = (long)iVar4;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// aw_cali_class_cali_re_store @ 001103dc size=224
// signature: undefined aw_cali_class_cali_re_store(void)
// callers: []
//------------------------------------------------------------

long aw_cali_class_cali_re_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  long *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = (long *)0x0;
  iVar1 = aw882xx_dev_get_list_head(&local_40);
  if (iVar1 == 0) {
    lVar3 = *local_40;
    iVar1 = aw_cali_svc_set_devs_re_str(lVar3 + -0x508,param_3);
    if (iVar1 < 1) {
      plVar2 = *(long **)(lVar3 + -0x490);
      lVar3 = plVar2[0xe];
      if (lVar3 == 0) {
        lVar3 = *plVar2;
      }
      _printk(&DAT_0011e35e,lVar3,"aw_cali_class_cali_re_store",param_3);
      param_4 = -1;
    }
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_cali_re_store");
    param_4 = (long)iVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_cali_class_cali_f0_show @ 001104c0 size=724
// signature: undefined aw_cali_class_cali_f0_show(void)
// callers: []
//------------------------------------------------------------

void aw_cali_class_cali_f0_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_60 = (long *)0x0;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar4 = aw882xx_dev_get_list_head(&local_60);
  if (iVar4 == 0) {
    lVar8 = *local_60;
    lVar7 = lVar8 + -0x508;
    iVar4 = aw_cali_svc_cali_f0(lVar7,0,2);
    uVar2 = s_cali_f0_cmd_failed_00120a0d._8_8_;
    uVar1 = s_cali_f0_cmd_failed_00120a0d._0_8_;
    if (iVar4 < 0) {
      lVar7 = 0x13;
      param_3[0x10] = 'e';
      param_3[0x11] = 'd';
      param_3[0x12] = '\n';
      param_3[0x13] = '\0';
      *(undefined8 *)param_3 = uVar1;
      *(undefined8 *)(param_3 + 8) = uVar2;
    }
    else {
      iVar4 = aw_cali_svc_get_devs_cali_f0(lVar7,&local_58,8);
      if (iVar4 < 1) {
        plVar6 = *(long **)(lVar8 + -0x490);
        lVar7 = plVar6[0xe];
        if (lVar7 == 0) {
          lVar7 = *plVar6;
        }
        _printk(&DAT_0011f6dd,lVar7,"aw_cali_class_cali_f0_show");
        lVar7 = 0xe;
        uVar1 = CONCAT71(s_get_f0_failed_0011f9c8._8_7_,s_get_f0_failed_0011f9c8[7]);
        *(ulong *)param_3 = CONCAT17(s_get_f0_failed_0011f9c8[7],s_get_f0_failed_0011f9c8._0_7_);
        *(undefined8 *)(param_3 + 7) = uVar1;
      }
      else {
        iVar5 = snprintf(param_3,0x1000,"%s:%d ","pri_l",(int)local_58);
        lVar7 = (long)iVar5;
        if (iVar4 != 1) {
          iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","pri_r",local_58._4_4_);
          lVar7 = lVar7 + iVar5;
          if (iVar4 != 2) {
            iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","sec_l",(int)local_50);
            lVar7 = lVar7 + iVar5;
            if (iVar4 != 3) {
              iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","sec_r",local_50._4_4_);
              lVar7 = lVar7 + iVar5;
              if (iVar4 != 4) {
                iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","tert_l",(int)local_48);
                lVar7 = lVar7 + iVar5;
                if (iVar4 != 5) {
                  iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","tert_r",local_48._4_4_);
                  lVar7 = lVar7 + iVar5;
                  if (iVar4 != 6) {
                    iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","quat_l",(int)local_40)
                    ;
                    lVar7 = lVar7 + iVar5;
                    if (iVar4 != 7) {
                      iVar5 = snprintf(param_3 + lVar7,0x1000 - lVar7,"%s:%d ","quat_r",
                                       local_40._4_4_);
                      if (iVar4 != 8) {
                    /* WARNING: Does not return */
                        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x110794);
                        (*pcVar3)();
                      }
                      lVar7 = lVar7 + iVar5;
                    }
                  }
                }
              }
            }
          }
        }
        iVar4 = snprintf(param_3 + lVar7,0x1000 - lVar7,"\n");
        lVar7 = lVar7 + iVar4;
      }
    }
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_cali_f0_show");
    lVar7 = (long)iVar4;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar7);
  }
  return;
}



//------------------------------------------------------------
// aw_cali_class_cali_f0_store @ 00110798 size=156
// signature: undefined aw_cali_class_cali_f0_store(void)
// callers: []
//------------------------------------------------------------

long aw_cali_class_cali_f0_store(void)

{
  long lVar1;
  int iVar2;
  long in_x3;
  long *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_30);
  if (iVar2 == 0) {
    aw_cali_svc_cali_f0(*local_30 + -0x508,0,2);
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_cali_f0_store");
    in_x3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return in_x3;
}



//------------------------------------------------------------
// aw_cali_class_time_show @ 00110838 size=56
// signature: undefined aw_cali_class_time_show(void)
// callers: []
//------------------------------------------------------------

long aw_cali_class_time_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"time: %d\n",g_cali_re_time);
  return (long)iVar1;
}



//------------------------------------------------------------
// aw_cali_class_time_store @ 00110874 size=204
// signature: undefined aw_cali_class_time_store(void)
// callers: []
//------------------------------------------------------------

long aw_cali_class_time_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar2 = kstrtoint(param_3,0,&local_3c);
  if (iVar2 < 0) {
    _printk(&DAT_00122a2c,"aw_cali_class_time_store",param_3);
    param_4 = (long)iVar2;
  }
  else if (local_3c < 400) {
    _printk(&DAT_00122a4e,"aw_cali_class_time_store");
    param_4 = -0x16;
  }
  else {
    g_cali_re_time = local_3c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_cali_class_re_show @ 00110944 size=640
// signature: undefined aw_cali_class_re_show(void)
// callers: []
//------------------------------------------------------------

void aw_cali_class_re_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  long *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_60 = (long *)0x0;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar3 = aw882xx_dev_get_list_head(&local_60);
  if (iVar3 == 0) {
    lVar6 = *local_60;
    iVar3 = aw_cali_svc_get_devs_cali_re(lVar6 + -0x508,&local_58,8);
    if (iVar3 < 1) {
      plVar5 = *(long **)(lVar6 + -0x490);
      lVar6 = plVar5[0xe];
      if (lVar6 == 0) {
        lVar6 = *plVar5;
      }
      _printk(&DAT_00120a2e,lVar6,"aw_cali_class_re_show");
      lVar6 = 0;
    }
    else {
      iVar4 = snprintf(param_3,0x1000,"%s:%d mOhms","pri_l",(int)local_58);
      lVar6 = (long)iVar4;
      if (iVar3 != 1) {
        iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","pri_r",local_58._4_4_);
        lVar6 = lVar6 + iVar4;
        if (iVar3 != 2) {
          iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","sec_l",(int)local_50);
          lVar6 = lVar6 + iVar4;
          if (iVar3 != 3) {
            iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","sec_r",local_50._4_4_);
            lVar6 = lVar6 + iVar4;
            if (iVar3 != 4) {
              iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","tert_l",(int)local_48);
              lVar6 = lVar6 + iVar4;
              if (iVar3 != 5) {
                iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","tert_r",
                                 local_48._4_4_);
                lVar6 = lVar6 + iVar4;
                if (iVar3 != 6) {
                  iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","quat_l",
                                   (int)local_40);
                  lVar6 = lVar6 + iVar4;
                  if (iVar3 != 7) {
                    iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d mOhms","quat_r",
                                     local_40._4_4_);
                    if (iVar3 != 8) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x110bc4);
                      (*pcVar2)();
                    }
                    lVar6 = lVar6 + iVar4;
                  }
                }
              }
            }
          }
        }
      }
      iVar3 = snprintf(param_3 + lVar6,0x1000 - lVar6,"\n");
      lVar6 = lVar6 + iVar3;
    }
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_re_show");
    lVar6 = (long)iVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// aw_cali_class_f0_show @ 00110bc8 size=640
// signature: undefined aw_cali_class_f0_show(void)
// callers: []
//------------------------------------------------------------

void aw_cali_class_f0_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  long *local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_60 = (long *)0x0;
  local_58 = 0;
  local_48 = 0;
  local_40 = 0;
  local_50 = 0;
  iVar3 = aw882xx_dev_get_list_head(&local_60);
  if (iVar3 == 0) {
    lVar6 = *local_60;
    iVar3 = aw_cali_svc_get_devs_cali_f0(lVar6 + -0x508,&local_58,8);
    if (iVar3 < 1) {
      plVar5 = *(long **)(lVar6 + -0x490);
      lVar6 = plVar5[0xe];
      if (lVar6 == 0) {
        lVar6 = *plVar5;
      }
      _printk(&DAT_00120a2e,lVar6,"aw_cali_class_f0_show");
      lVar6 = 0;
    }
    else {
      iVar4 = snprintf(param_3,0x1000,"%s:%d","pri_l",(int)local_58);
      lVar6 = (long)iVar4;
      if (iVar3 != 1) {
        iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","pri_r",local_58._4_4_);
        lVar6 = lVar6 + iVar4;
        if (iVar3 != 2) {
          iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","sec_l",(int)local_50);
          lVar6 = lVar6 + iVar4;
          if (iVar3 != 3) {
            iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","sec_r",local_50._4_4_);
            lVar6 = lVar6 + iVar4;
            if (iVar3 != 4) {
              iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","tert_l",(int)local_48);
              lVar6 = lVar6 + iVar4;
              if (iVar3 != 5) {
                iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","tert_r",local_48._4_4_);
                lVar6 = lVar6 + iVar4;
                if (iVar3 != 6) {
                  iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","quat_l",(int)local_40);
                  lVar6 = lVar6 + iVar4;
                  if (iVar3 != 7) {
                    iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:%d","quat_r",local_40._4_4_)
                    ;
                    if (iVar3 != 8) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x110e48);
                      (*pcVar2)();
                    }
                    lVar6 = lVar6 + iVar4;
                  }
                }
              }
            }
          }
        }
      }
      iVar3 = snprintf(param_3 + lVar6,0x1000 - lVar6,"\n");
      lVar6 = lVar6 + iVar3;
    }
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_class_f0_show");
    lVar6 = (long)iVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// aw_class_re_range_show @ 00110e4c size=664
// signature: undefined aw_class_re_range_show(void)
// callers: []
//------------------------------------------------------------

void aw_class_re_range_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  long *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_80 = (long *)0x0;
  local_78 = 0;
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_70 = 0;
  _printk(&DAT_0011d4f3,"aw_class_re_range_show");
  iVar3 = aw882xx_dev_get_list_head(&local_80);
  if (iVar3 < 0) {
    _printk(&DAT_0011e6e7,"aw_class_re_range_show");
    lVar6 = (long)iVar3;
  }
  else {
    lVar6 = *local_80;
    iVar3 = aw_cali_svc_get_devs_re_range(lVar6 + -0x508,&local_78);
    if (iVar3 < 1) {
      plVar5 = *(long **)(lVar6 + -0x490);
      lVar6 = plVar5[0xe];
      if (lVar6 == 0) {
        lVar6 = *plVar5;
      }
      _printk(&DAT_0011d7f6,lVar6,"aw_class_re_range_show");
      lVar6 = -0x16;
    }
    else {
      iVar4 = snprintf(param_3,0x1000,"%s:re_min:%d mOhms re_max:%d mOhms ","pri_l",(int)local_78,
                       local_78._4_4_);
      lVar6 = (long)iVar4;
      if (iVar3 != 1) {
        iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:re_min:%d mOhms re_max:%d mOhms ",
                         "pri_r",(int)local_70,local_70._4_4_);
        lVar6 = lVar6 + iVar4;
        if (iVar3 != 2) {
          iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:re_min:%d mOhms re_max:%d mOhms ",
                           "sec_l",(int)local_68,local_68._4_4_);
          lVar6 = lVar6 + iVar4;
          if (iVar3 != 3) {
            iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:re_min:%d mOhms re_max:%d mOhms ",
                             "sec_r",(int)local_60,local_60._4_4_);
            lVar6 = lVar6 + iVar4;
            if (iVar3 != 4) {
              iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,"%s:re_min:%d mOhms re_max:%d mOhms ",
                               "tert_l",(int)local_58,local_58._4_4_);
              lVar6 = lVar6 + iVar4;
              if (iVar3 != 5) {
                iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,
                                 "%s:re_min:%d mOhms re_max:%d mOhms ","tert_r",(int)local_50,
                                 local_50._4_4_);
                lVar6 = lVar6 + iVar4;
                if (iVar3 != 6) {
                  iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,
                                   "%s:re_min:%d mOhms re_max:%d mOhms ","quat_l",(int)local_48,
                                   local_48._4_4_);
                  lVar6 = lVar6 + iVar4;
                  if (iVar3 != 7) {
                    iVar4 = snprintf(param_3 + lVar6,0x1000 - lVar6,
                                     "%s:re_min:%d mOhms re_max:%d mOhms ","quat_r",(int)local_40,
                                     local_40._4_4_);
                    if (iVar3 != 8) {
                    /* WARNING: Does not return */
                      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1110e4);
                      (*pcVar2)();
                    }
                    lVar6 = lVar6 + iVar4;
                  }
                }
              }
            }
          }
        }
      }
      iVar3 = snprintf(param_3 + lVar6,0x1000 - lVar6,"\n");
      lVar6 = lVar6 + iVar3;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar6);
  }
  return;
}



//------------------------------------------------------------
// aw_cali_svc_get_devs_re_range @ 001110e4 size=308
// signature: undefined aw_cali_svc_get_devs_re_range(void)
// callers: [aw_cali_misc_read, aw_class_re_range_show]
//------------------------------------------------------------

int aw_cali_svc_get_devs_re_range(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  long *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = (long *)0x0;
  iVar2 = aw882xx_dev_get_list_head(&local_40);
  if (iVar2 == 0) {
    plVar4 = (long *)*local_40;
    if (plVar4 == local_40) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        uVar1 = *(uint *)((long)plVar4 + -0x4cc);
        if (7 < uVar1) {
          lVar3 = ((long *)plVar4[-0x92])[0xe];
          if (lVar3 == 0) {
            lVar3 = *(long *)plVar4[-0x92];
          }
          _printk(&DAT_00120f78,lVar3,"aw_cali_svc_get_devs_re_range",(ulong)uVar1,8);
          iVar2 = -0x16;
          break;
        }
        iVar2 = iVar2 + 1;
        *(int *)(param_2 + (ulong)uVar1 * 8) = (int)plVar4[-0x98];
        *(undefined4 *)(param_2 + (ulong)(*(uint *)((long)plVar4 + -0x4cc) << 1 | 1) * 4) =
             *(undefined4 *)((long)plVar4 + -0x4c4);
        plVar4 = (long *)*plVar4;
      } while (plVar4 != local_40);
    }
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011eb45,lVar3,"aw_cali_svc_get_devs_re_range");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw_cali_misc_read @ 0011121c size=2564
// signature: undefined aw_cali_misc_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long aw_cali_misc_read(long param_1,ulong param_2,undefined8 param_3,long *param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  long lVar6;
  undefined8 *puVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 local_230;
  undefined8 uStack_228;
  undefined8 local_220;
  undefined8 uStack_218;
  undefined8 local_210;
  undefined8 uStack_208;
  undefined8 local_200;
  undefined8 uStack_1f8;
  int local_1f0 [16];
  undefined8 local_1b0;
  undefined8 uStack_1a8;
  undefined8 local_1a0;
  undefined8 uStack_198;
  undefined8 local_190;
  undefined8 uStack_188;
  undefined8 local_180;
  undefined8 uStack_178;
  int local_170 [64];
  long local_70;
  
  lVar6 = sp_el0;
  local_70 = *(long *)(lVar6 + 0x638);
  lVar8 = *(long *)(param_1 + 0xd8);
  local_170[0x3c] = 0;
  local_170[0x3d] = 0;
  local_170[0x3e] = 0;
  local_170[0x3f] = 0;
  local_170[0x38] = 0;
  local_170[0x39] = 0;
  local_170[0x3a] = 0;
  local_170[0x3b] = 0;
  local_170[0x34] = 0;
  local_170[0x35] = 0;
  local_170[0x36] = 0;
  local_170[0x37] = 0;
  local_170[0x30] = 0;
  local_170[0x31] = 0;
  local_170[0x32] = 0;
  local_170[0x33] = 0;
  local_170[0x2c] = 0;
  local_170[0x2d] = 0;
  local_170[0x2e] = 0;
  local_170[0x2f] = 0;
  local_170[0x28] = 0;
  local_170[0x29] = 0;
  local_170[0x2a] = 0;
  local_170[0x2b] = 0;
  local_170[0x24] = 0;
  local_170[0x25] = 0;
  local_170[0x26] = 0;
  local_170[0x27] = 0;
  local_170[0x20] = 0;
  local_170[0x21] = 0;
  local_170[0x22] = 0;
  local_170[0x23] = 0;
  local_170[0x1c] = 0;
  local_170[0x1d] = 0;
  local_170[0x1e] = 0;
  local_170[0x1f] = 0;
  local_170[0x18] = 0;
  local_170[0x19] = 0;
  local_170[0x1a] = 0;
  local_170[0x1b] = 0;
  local_170[0x14] = 0;
  local_170[0x15] = 0;
  local_170[0x16] = 0;
  local_170[0x17] = 0;
  local_170[0x10] = 0;
  local_170[0x11] = 0;
  local_170[0x12] = 0;
  local_170[0x13] = 0;
  lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
  local_170[0xc] = 0;
  local_170[0xd] = 0;
  local_170[0xe] = 0;
  local_170[0xf] = 0;
  local_170[8] = 0;
  local_170[9] = 0;
  local_170[10] = 0;
  local_170[0xb] = 0;
  local_170[4] = 0;
  local_170[5] = 0;
  local_170[6] = 0;
  local_170[7] = 0;
  local_170[0] = 0;
  local_170[1] = 0;
  local_170[2] = 0;
  local_170[3] = 0;
  local_180 = 0;
  uStack_178 = 0;
  local_190 = 0;
  uStack_188 = 0;
  local_1a0 = 0;
  uStack_198 = 0;
  local_1b0 = 0;
  uStack_1a8 = 0;
  local_1f0[0xc] = 0;
  local_1f0[0xd] = 0;
  local_1f0[0xe] = 0;
  local_1f0[0xf] = 0;
  local_1f0[8] = 0;
  local_1f0[9] = 0;
  local_1f0[10] = 0;
  local_1f0[0xb] = 0;
  local_1f0[4] = 0;
  local_1f0[5] = 0;
  local_1f0[6] = 0;
  local_1f0[7] = 0;
  local_1f0[0] = 0;
  local_1f0[1] = 0;
  local_1f0[2] = 0;
  local_1f0[3] = 0;
  local_200 = 0;
  uStack_1f8 = 0;
  local_210 = 0;
  uStack_208 = 0;
  local_220 = 0;
  uStack_218 = 0;
  local_230 = 0;
  uStack_228 = 0;
  if (lVar6 == 0) {
    lVar6 = **(long **)(lVar8 + 0x78);
  }
  _printk(&DAT_00120075,lVar6,"aw_cali_misc_read");
  if (*param_4 != 0) {
    lVar6 = 0;
    *param_4 = 0;
    goto LAB_001119c0;
  }
  switch(g_msic_wr_flag) {
  case 0:
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011e392;
    goto LAB_00111ba8;
  default:
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    _printk(&DAT_0012080f,lVar6,"aw_cali_misc_read");
    lVar6 = -0x16;
    g_msic_wr_flag = 0;
    goto LAB_001119c0;
  case 5:
    uVar2 = aw_cali_svc_get_devs_cali_re(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) {
LAB_00111bfc:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x111c00);
          (*pcVar1)();
        }
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:%d mOhms ",
                         (&ch_name)[uVar10],local_1f0[uVar10 + 0x10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
LAB_00111730:
      if (0x100 < (uint)uVar9) {
LAB_00111c00:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x111c04);
        (*pcVar1)();
      }
      iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"\n");
LAB_001118c0:
      uVar2 = iVar3 + (int)uVar9;
LAB_001118c8:
      lVar6 = (long)(int)uVar2;
      if (uVar2 < 0x101) {
        __check_object_size(local_170,lVar6,1);
        puVar7 = (undefined8 *)sp_el0;
        if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
           (uVar10 = param_2, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
          uVar10 = param_2 & (long)(param_2 << 8) >> 8;
        }
        lVar4 = lVar6;
        if (uVar10 <= 0x8000000000U - lVar6) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            puVar7 = (undefined8 *)puVar7[1];
            uVar9 = ttbr1_el1;
            ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar7;
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
          lVar4 = __arch_copy_to_user(puVar7,param_2 & 0xff7fffffffffffff,local_170,lVar6);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar10 = daif;
            if ((uVar10 & 0x80) == 0) {
              uVar9 = daif;
              daif = uVar9 | 0xc0;
            }
            uVar9 = ttbr1_el1;
            ttbr0_el1 = (uVar9 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar9 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar10;
          }
        }
        if (lVar4 == 0) {
          g_msic_wr_flag = 0;
          *param_4 = *param_4 + lVar6;
          goto LAB_001119c0;
        }
      }
      else {
        __copy_overflow(0x100,lVar6);
      }
      lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar8 + 0x78);
      }
      _printk(&DAT_00121026,lVar6,"aw_cali_misc_read");
      lVar6 = -0xe;
      g_msic_wr_flag = 0;
      goto LAB_001119c0;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011d841;
    break;
  case 6:
    uVar2 = aw_cali_svc_get_devs_r0(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:%d mOhms ",
                         (&ch_name)[uVar10],local_1f0[uVar10 + 0x10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
      goto LAB_00111730;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0012391d;
    break;
  case 7:
    uVar2 = aw_cali_svc_get_devs_cali_f0(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:%d ",(&ch_name)[uVar10]
                         ,local_1f0[uVar10 + 0x10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
      goto LAB_00111730;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_001238f7;
    break;
  case 8:
    uVar2 = aw_cali_svc_get_devs_f0(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:%d ",(&ch_name)[uVar10]
                         ,local_1f0[uVar10 + 0x10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
      goto LAB_00111730;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011f2e3;
    break;
  case 9:
    uVar2 = aw_cali_svc_get_devs_te(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:%d ",(&ch_name)[uVar10]
                         ,local_1f0[uVar10 + 0x10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
      goto LAB_00111730;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011df92;
    break;
  case 10:
    uVar2 = aw_cali_svc_get_devs_st(lVar8,&local_1b0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      lVar6 = -0x40;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if ((lVar6 == 0) || ((lVar6 == 0 || (0x40 < lVar6 + 0x44U)))) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:R0 %d mOhms Te %d ",
                         *(char **)((long)&aw_cali_misc_fops + lVar6),
                         *(int *)((long)local_170 + lVar6),*(int *)((long)local_170 + lVar6 + 4));
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
        lVar6 = lVar6 + 8;
      } while (uVar2 != uVar10);
LAB_00111898:
      if (0x100 < (uint)uVar9) goto LAB_00111c00;
      iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"\n");
      goto LAB_001118c0;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011e70a;
    break;
  case 0xc:
    pcVar1 = *(code **)(lVar8 + 0x4b0);
    if (pcVar1 == (code *)0x0) {
      lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar8 + 0x78);
      }
      puVar5 = &DAT_0011dfb3;
    }
    else {
      if (*(int *)(pcVar1 + -4) != 0x4d9b0091) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1113dc);
        (*pcVar1)();
      }
      uVar2 = (*pcVar1)(local_170,0x100);
      if (-1 < (int)uVar2) {
        if (0x100 < uVar2) goto LAB_00111c00;
        iVar3 = snprintf((char *)((long)local_170 + (ulong)uVar2),0x100 - (ulong)uVar2,"\n");
        uVar2 = iVar3 + uVar2;
        goto LAB_001118c8;
      }
      lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar8 + 0x78);
      }
      puVar5 = &DAT_00123302;
    }
    goto LAB_00111ba8;
  case 0xd:
    pcVar1 = *(code **)(lVar8 + 0x4b8);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x111570);
        (*pcVar1)();
      }
      iVar3 = (*pcVar1)();
      uVar2 = snprintf((char *)local_170,0x100,"dev_num:%d\n",iVar3);
      goto LAB_001118c8;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011db25;
    goto LAB_00111ba8;
  case 0xf:
    uVar2 = aw_cali_svc_get_devs_cali_f0_q(lVar8,&local_1b0,local_1f0,8);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if (uVar10 == 8) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:f0:%d q:%d",
                         (&ch_name)[uVar10],local_1f0[uVar10 + 0x10],local_1f0[uVar10]);
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
      } while (uVar2 != uVar10);
      goto LAB_00111898;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011e734;
    break;
  case 0x10:
    uVar2 = aw_cali_svc_get_devs_re_range(lVar8,&local_230);
    if (0 < (int)uVar2) {
      uVar10 = 0;
      uVar9 = 0;
      lVar6 = -0x40;
      do {
        if ((0x100 < (uint)uVar9) || (7 < uVar10)) goto LAB_00111c00;
        if ((lVar6 == 0) || ((lVar6 == 0 || (0x40 < lVar6 + 0x44U)))) goto LAB_00111bfc;
        iVar3 = snprintf((char *)((long)local_170 + uVar9),0x100 - uVar9,"%s:re_min:%d re_max:%d ",
                         *(char **)((long)&aw_cali_misc_fops + lVar6),
                         *(int *)((long)local_1f0 + lVar6),*(int *)((long)local_1f0 + lVar6 + 4));
        uVar10 = uVar10 + 1;
        uVar9 = (ulong)(iVar3 + (uint)uVar9);
        lVar6 = lVar6 + 8;
      } while (uVar2 != uVar10);
      goto LAB_00111898;
    }
    lVar6 = (*(long **)(lVar8 + 0x78))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(lVar8 + 0x78);
    }
    puVar5 = &DAT_0011d7f6;
LAB_00111ba8:
    _printk(puVar5,lVar6,"aw_cali_misc_read");
    lVar6 = -0x16;
    goto LAB_001119c0;
  }
  _printk(puVar5,lVar6,"aw_cali_misc_read");
  lVar6 = (long)(int)uVar2;
LAB_001119c0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar6;
}



//------------------------------------------------------------
// aw_cali_misc_write @ 00111c3c size=780
// signature: undefined aw_cali_misc_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong aw_cali_misc_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined *puVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  long lVar11;
  
  lVar11 = *(long *)(param_1 + 0xd8);
  lVar8 = (*(long **)(lVar11 + 0x78))[0xe];
  if (lVar8 == 0) {
    lVar8 = **(long **)(lVar11 + 0x78);
  }
  _printk(&DAT_00122aa7,lVar8,"aw_cali_misc_write",param_3 & 0xffffffff);
  lVar8 = __kmalloc(param_3 + 1,0xdc0);
  if (lVar8 == 0) {
    return 0xfffffffffffffff4;
  }
  if (param_3 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x111f14);
    (*pcVar2)();
  }
  __check_object_size(lVar8,param_3,0);
  puVar9 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
     (uVar10 = param_2, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
    uVar10 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar5 = param_3;
  if (uVar10 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar10 = daif;
      if ((uVar10 & 0x80) == 0) {
        uVar5 = daif;
        daif = uVar5 | 0xc0;
      }
      puVar9 = (undefined8 *)puVar9[1];
      uVar5 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar9;
      InstructionSynchronizationBarrier();
      daif = uVar10;
    }
    uVar5 = __arch_copy_from_user(puVar9,lVar8,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar10 = daif;
      if ((uVar10 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar10;
    }
  }
  if (uVar5 != 0) {
    memset((void *)(lVar8 + (param_3 - uVar5)),0,uVar5);
    iVar4 = -0xe;
    goto LAB_00111e18;
  }
  iVar3 = aw_cali_svc_get_cmd_form_str(lVar11,lVar8);
  if (iVar3 < 0) {
    lVar7 = (*(long **)(lVar11 + 0x78))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(lVar11 + 0x78);
    }
    puVar6 = &DAT_0011d098;
LAB_00111dd0:
    _printk(puVar6,lVar7,"aw_cali_misc_write",lVar8);
    iVar4 = -0x16;
  }
  else {
    switch(iVar3) {
    case 1:
      iVar4 = aw_cali_svc_cali_cmd(lVar11,2,0,3);
      break;
    case 2:
      iVar4 = aw_cali_svc_cali_re(lVar11,0,1);
      break;
    case 3:
      iVar4 = aw_cali_svc_cali_f0(lVar11,0,3);
      break;
    case 4:
      if ((long)param_3 < 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x111f34);
        (*pcVar2)();
      }
      *(undefined1 *)(lVar8 + param_3) = 0;
      iVar4 = aw_cali_svc_set_devs_re_str(lVar11,lVar8 + 9);
      break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xc:
    case 0xd:
    case 0xf:
    case 0x10:
      iVar4 = 0;
      g_msic_wr_flag = iVar3;
      break;
    case 0xb:
      iVar4 = aw_cali_misc_switch_dev(param_1,lVar11,lVar8);
      break;
    case 0xe:
      iVar4 = aw_cali_svc_cali_f0_q(lVar11,0,3);
      break;
    default:
      lVar7 = (*(long **)(lVar11 + 0x78))[0xe];
      if (lVar7 == 0) {
        lVar7 = **(long **)(lVar11 + 0x78);
      }
      puVar6 = &DAT_0012231f;
      goto LAB_00111dd0;
    }
  }
LAB_00111e18:
  lVar7 = (*(long **)(lVar11 + 0x78))[0xe];
  if (lVar7 == 0) {
    lVar7 = **(long **)(lVar11 + 0x78);
  }
  _printk(&DAT_00123328,lVar7,"aw_cali_misc_write",lVar8);
  kfree(lVar8);
  uVar10 = 0xffffffffffffffea;
  if (-1 < iVar4) {
    uVar10 = param_3;
  }
  return uVar10;
}



//------------------------------------------------------------
// aw_cali_misc_unlocked_ioctl @ 00111f68 size=88
// signature: undefined aw_cali_misc_unlocked_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_cali_misc_unlocked_ioctl(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 & 0xff00) == 0x6100) {
    iVar1 = aw_cali_misc_ops(*(undefined8 *)(param_1 + 0xd8));
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xffffffffffffffea;
    }
  }
  else {
    _printk(&DAT_00121d6e,"aw_cali_misc_unlocked_ioctl");
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_cali_misc_compat_ioctl @ 00111fc4 size=88
// signature: undefined aw_cali_misc_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_cali_misc_compat_ioctl(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 & 0xff00) == 0x6100) {
    iVar1 = aw_cali_misc_ops(*(undefined8 *)(param_1 + 0xd8));
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xffffffffffffffea;
    }
  }
  else {
    _printk(&DAT_00121d6e,"aw_cali_misc_compat_ioctl");
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_cali_misc_open @ 00112020 size=256
// signature: undefined aw_cali_misc_open(void)
// callers: []
//------------------------------------------------------------

void aw_cali_misc_open(undefined8 param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long *plVar6;
  long *local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30 = (long *)0x0;
  iVar3 = aw882xx_dev_get_list_head(&local_30);
  if (iVar3 == 0) {
    plVar5 = (long *)*local_30;
    if (plVar5 != local_30) {
      plVar1 = plVar5;
      do {
        plVar6 = plVar1;
        if (*(int *)((long)plVar6 + -0x4cc) == g_dev_select) break;
        plVar1 = (long *)*plVar6;
      } while ((long *)*plVar6 != local_30);
      if (plVar6 + -0xa1 != (long *)0x0) {
        uVar4 = 0;
        plVar1 = plVar6 + -0xa1;
        if (*(int *)((long)plVar6 + -0x4cc) != g_dev_select) {
          plVar1 = plVar5 + -0xa1;
        }
        *(long **)(param_2 + 0xd8) = plVar1;
        goto LAB_001120b4;
      }
    }
    _printk(&DAT_001201d0,"aw_cali_misc_open",g_dev_select);
    uVar4 = 0xffffffea;
  }
  else {
    _printk(&DAT_0011e6e7,"aw_cali_misc_open");
    uVar4 = 0xffffffea;
    *(undefined8 *)(param_2 + 0xd8) = 0;
  }
LAB_001120b4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// aw_cali_misc_release @ 00112124 size=12
// signature: undefined aw_cali_misc_release(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_cali_misc_release(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = 0;
  return 0;
}



//------------------------------------------------------------
// aw_cali_misc_switch_dev @ 00112130 size=640
// signature: undefined aw_cali_misc_switch_dev(void)
// callers: [aw_cali_misc_write]
//------------------------------------------------------------

int aw_cali_misc_switch_dev(long param_1,long param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined *puVar4;
  long *plVar5;
  long *local_78;
  char local_70 [56];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_70[0x30] = '\0';
  local_70[0x31] = '\0';
  local_70[0x20] = '\0';
  local_70[0x21] = '\0';
  local_70[0x22] = '\0';
  local_70[0x23] = '\0';
  local_70[0x24] = '\0';
  local_70[0x25] = '\0';
  local_70[0x26] = '\0';
  local_70[0x27] = '\0';
  local_70[0x28] = '\0';
  local_70[0x29] = '\0';
  local_70[0x2a] = '\0';
  local_70[0x2b] = '\0';
  local_70[0x2c] = '\0';
  local_70[0x2d] = '\0';
  local_70[0x2e] = '\0';
  local_70[0x2f] = '\0';
  local_70[0x10] = '\0';
  local_70[0x11] = '\0';
  local_70[0x12] = '\0';
  local_70[0x13] = '\0';
  local_70[0x14] = '\0';
  local_70[0x15] = '\0';
  local_70[0x16] = '\0';
  local_70[0x17] = '\0';
  local_70[0x18] = '\0';
  local_70[0x19] = '\0';
  local_70[0x1a] = '\0';
  local_70[0x1b] = '\0';
  local_70[0x1c] = '\0';
  local_70[0x1d] = '\0';
  local_70[0x1e] = '\0';
  local_70[0x1f] = '\0';
  local_70[0] = '\0';
  local_70[1] = '\0';
  local_70[2] = '\0';
  local_70[3] = '\0';
  local_70[4] = '\0';
  local_70[5] = '\0';
  local_70[6] = '\0';
  local_70[7] = '\0';
  local_70[8] = '\0';
  local_70[9] = '\0';
  local_70[10] = '\0';
  local_70[0xb] = '\0';
  local_70[0xc] = '\0';
  local_70[0xd] = '\0';
  local_70[0xe] = '\0';
  local_70[0xf] = '\0';
  local_78 = (long *)0x0;
  iVar1 = sscanf(param_3,"dev_sel:%s",local_70);
  if (iVar1 < 1) {
LAB_00112190:
    iVar1 = -0x16;
  }
  else {
    lVar2 = strnstr(local_70,"pri_l",5);
    if (lVar2 == 0) {
      lVar2 = strnstr(local_70,"pri_r",5);
      if (lVar2 == 0) {
        lVar2 = strnstr(local_70,"sec_l",5);
        if (lVar2 == 0) {
          lVar2 = strnstr(local_70,"sec_r",5);
          if (lVar2 == 0) {
            lVar2 = strnstr(local_70,"tert_l",6);
            if (lVar2 == 0) {
              lVar2 = strnstr(local_70,"tert_r",6);
              if (lVar2 == 0) {
                lVar2 = 6;
                lVar3 = strnstr(local_70,"quat_l",6);
                if (lVar3 == 0) {
                  lVar2 = strnstr(local_70,"quat_r",6);
                  if (lVar2 == 0) {
                    lVar2 = (*(long **)(param_2 + 0x78))[0xe];
                    if (lVar2 == 0) {
                      lVar2 = **(long **)(param_2 + 0x78);
                    }
                    puVar4 = &DAT_0012393e;
LAB_00112390:
                    _printk(puVar4,lVar2,"aw_cali_misc_switch_dev",local_70);
                    goto LAB_00112190;
                  }
                  lVar2 = 7;
                }
              }
              else {
                lVar2 = 5;
              }
            }
            else {
              lVar2 = 4;
            }
          }
          else {
            lVar2 = 3;
          }
        }
        else {
          lVar2 = 2;
        }
      }
      else {
        lVar2 = 1;
      }
    }
    else {
      lVar2 = 0;
    }
    iVar1 = aw882xx_dev_get_list_head(&local_78);
    if (iVar1 == 0) {
      plVar5 = local_78;
      do {
        plVar5 = (long *)*plVar5;
        if (plVar5 == local_78) {
          lVar2 = (*(long **)(param_2 + 0x78))[0xe];
          if (lVar2 == 0) {
            lVar2 = **(long **)(param_2 + 0x78);
          }
          puVar4 = &DAT_00120838;
          goto LAB_00112390;
        }
      } while (*(int *)((long)plVar5 + -0x4cc) != (int)lVar2);
      *(long **)(param_1 + 0xd8) = plVar5 + -0xa1;
      lVar3 = ((long *)plVar5[-0x92])[0xe];
      if (lVar3 == 0) {
        lVar3 = *(long *)plVar5[-0x92];
      }
      g_dev_select = (int)lVar2;
      _printk(&DAT_001230bd,lVar3,"aw_cali_misc_switch_dev",(&ch_name)[lVar2]);
      iVar1 = 0;
    }
    else {
      lVar2 = (*(long **)(param_2 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_2 + 0x78);
      }
      _printk(&DAT_0011ef63,lVar2,"aw_cali_misc_switch_dev");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw_cali_misc_ops @ 001123b0 size=2632
// signature: undefined aw_cali_misc_ops(void)
// callers: [aw_cali_misc_compat_ioctl, aw_cali_misc_unlocked_ioctl, aw_cali_misc_ops]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aw_cali_misc_ops(long param_1,uint param_2,ulong param_3)

{
  int iVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  ulong uVar6;
  size_t __n;
  undefined *puVar7;
  undefined1 uVar8;
  long lVar9;
  long lVar10;
  char *pcVar11;
  uint uVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  size_t sVar16;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  if ((int)param_2 < -0x3ff79eef) {
    if (param_2 + 0x3ffb9efc < 0xc) {
      uVar12 = 1 << (ulong)(param_2 + 0x3ffb9efc & 0x1f);
      if ((uVar12 & 0xc15) == 0) {
        if ((uVar12 & 0x2a) != 0) goto LAB_001124c4;
        goto LAB_0011242c;
      }
    }
    else {
LAB_0011242c:
      uVar12 = 0xc001610b;
LAB_00112548:
      if (param_2 != uVar12) {
LAB_00112bcc:
        lVar10 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar10 == 0) {
          lVar10 = **(long **)(param_1 + 0x78);
        }
        puVar7 = &DAT_001230e3;
        pcVar11 = "aw_cali_misc_ops";
        goto LAB_00112ce4;
      }
    }
    uVar15 = (ulong)(param_2 >> 0x10 & 0x3fff);
    piVar5 = (int *)__kmalloc(uVar15,0xdc0);
    if (piVar5 != (int *)0x0) {
      __check_object_size(piVar5,uVar15,0);
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      uVar6 = uVar15;
      if (uVar13 <= 0x8000000000 - uVar15) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar6 = daif;
            daif = uVar6 | 0xc0;
          }
          uVar6 = ttbr1_el1;
          ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        uVar6 = __arch_copy_from_user(piVar5,param_3 & 0xff7fffffffffffff,uVar15);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
      }
      if (uVar6 != 0) {
        memset((void *)((long)piVar5 + (uVar15 - uVar6)),0,uVar6);
        iVar4 = -0xe;
        goto LAB_00112b2c;
      }
      if ((int)param_2 < -0x3ff39eff) {
        switch(param_2) {
        case 0xc0046104:
          iVar4 = aw882xx_dsp_noise_en(param_1,*piVar5 != 0);
          break;
        case 0xc0046105:
        case 0xc0046107:
        case 0xc0046109:
        case 0xc004610a:
        case 0xc004610b:
        case 0xc004610c:
        case 0xc004610d:
switchD_0011267c_caseD_c0046105:
          lVar10 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar10 == 0) {
            lVar10 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_001230e3,lVar10,"aw_cali_misc_ops_write",param_2);
          iVar4 = -0x16;
          break;
        case 0xc0046106:
          aw_cali_store_cali_re(param_1,*piVar5);
          iVar4 = 0;
          break;
        case 0xc0046108:
          iVar4 = aw882xx_dsp_write_vmax(param_1,piVar5,uVar15);
          break;
        case 0xc004610e:
          iVar4 = aw882xx_dsp_hmute_en(param_1,*piVar5 != 0);
          break;
        case 0xc004610f:
          iVar4 = aw882xx_dsp_cali_en(param_1,*piVar5);
          break;
        default:
          if (param_2 != 0xc001610b) goto switchD_0011267c_caseD_c0046105;
          if (*(char *)(param_1 + 0x2a1) != '\0') {
            if ((char)*piVar5 == '\0') {
              uVar8 = *(undefined1 *)(param_1 + 0x2a0);
            }
            else {
              uVar8 = 1;
            }
            aw_cali_svc_run_mute(param_1,uVar8);
          }
          g_cali_status = (char)*piVar5 != '\0';
          lVar10 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar10 == 0) {
            lVar10 = **(long **)(param_1 + 0x78);
          }
          pcVar11 = "disable";
          if ((char)*piVar5 != '\0') {
            pcVar11 = "enable";
          }
          _printk(&DAT_0011e33d,lVar10,"aw_cali_svc_set_cali_status",pcVar11);
          iVar4 = 0;
        }
      }
      else if (param_2 == 0xc00c6101) {
        iVar4 = aw882xx_dsp_write_cali_cfg(param_1,piVar5,0xc);
      }
      else if (param_2 == 0xc010610c) {
        if ((*(long *)(piVar5 + 2) == 0) || (*piVar5 == 0)) {
          lVar10 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar10 == 0) {
            lVar10 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_00123964,lVar10,"aw_cali_misc_params_ptr");
          iVar4 = -0xe;
        }
        else {
          lVar10 = __kmalloc((long)*piVar5,0xdc0);
          if (lVar10 == 0) {
            iVar4 = -0xc;
          }
          else {
            sVar16 = (size_t)*piVar5;
            if (*piVar5 < 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x800,0x112d7c);
              (*pcVar3)();
            }
            uVar15 = *(ulong *)(piVar5 + 2);
            __check_object_size(lVar10,sVar16,0);
            if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
               (uVar13 = uVar15, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
              uVar13 = uVar15 & (long)(uVar15 << 8) >> 8;
            }
            __n = sVar16;
            if (uVar13 <= 0x8000000000 - sVar16) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar13 = daif;
                if ((uVar13 & 0x80) == 0) {
                  uVar6 = daif;
                  daif = uVar6 | 0xc0;
                }
                uVar6 = ttbr1_el1;
                ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar14[1];
                InstructionSynchronizationBarrier();
                daif = uVar13;
              }
              __n = __arch_copy_from_user(lVar10,uVar15 & 0xff7fffffffffffff,sVar16);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar13 = daif;
                  daif = uVar13 | 0xc0;
                }
                uVar13 = ttbr1_el1;
                ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar13 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
            }
            if (__n == 0) {
              iVar4 = aw882xx_dsp_write_params(param_1,lVar10,*piVar5);
              if (iVar4 < 0) {
                lVar9 = (*(long **)(param_1 + 0x78))[0xe];
                if (lVar9 == 0) {
                  lVar9 = **(long **)(param_1 + 0x78);
                }
                _printk(&DAT_0011d53f,lVar9,"aw_cali_misc_params_ptr");
                goto LAB_00112cbc;
              }
            }
            else {
              memset((void *)(lVar10 + (sVar16 - __n)),0,__n);
LAB_00112cbc:
              iVar4 = -0xe;
            }
            kfree(lVar10);
          }
        }
      }
      else {
        if (param_2 != 0xc960610a) goto switchD_0011267c_caseD_c0046105;
        iVar4 = aw882xx_dsp_write_params(param_1,piVar5,0x960);
      }
LAB_00112b2c:
      kfree(piVar5);
      goto LAB_00112b34;
    }
  }
  else {
    if (-0x3fef9ef4 < (int)param_2) {
      if ((int)param_2 < -0x3fdf9ef0) {
        if ((param_2 == 0xc010610d) || (param_2 == 0xc0186103)) goto LAB_001124c4;
        goto LAB_00112bcc;
      }
      if (param_2 != 0xc0206110) {
        uVar12 = 0xc960610a;
        goto LAB_00112548;
      }
      puVar14 = (undefined8 *)sp_el0;
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      local_70 = 0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar15 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar15 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (0x7fffffffe0 < uVar15) {
LAB_00112d6c:
        iVar4 = -0xe;
        goto LAB_00112b34;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        puVar14 = (undefined8 *)puVar14[1];
        uVar13 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar14;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      lVar10 = __arch_copy_from_user(puVar14,&local_78,param_3 & 0xff7fffffffffffff,0x20);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar15 = daif;
        if ((uVar15 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar15;
      }
      if (lVar10 != 0) goto LAB_00112d6c;
      if ((uint)local_70 == 0) {
        if ((uint)local_78 == 0) {
          iVar4 = aw_cali_misc_ops(param_1,local_78._4_4_,local_68);
          goto LAB_00112b34;
        }
        if ((uint)local_78 == 2) {
          iVar4 = aw_cali_misc_write_dsp(param_1,&local_78);
          goto LAB_00112b34;
        }
        if ((uint)local_78 == 1) {
          iVar4 = aw_cali_misc_read_dsp(param_1,&local_78);
          goto LAB_00112b34;
        }
        lVar10 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar10 == 0) {
          lVar10 = **(long **)(param_1 + 0x78);
        }
        puVar7 = &DAT_0011ebd3;
        param_2 = (uint)local_78;
      }
      else {
        lVar10 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar10 == 0) {
          lVar10 = **(long **)(param_1 + 0x78);
        }
        puVar7 = &DAT_00122acf;
        param_2 = (uint)local_70;
      }
      pcVar11 = "aw_cali_misc_ops_msg";
LAB_00112ce4:
      _printk(puVar7,lVar10,pcVar11,param_2);
      iVar4 = -0x16;
      goto LAB_00112b34;
    }
    if ((int)param_2 < -0x3ff39efe) {
      if (param_2 == 0xc0086111) goto LAB_001124c4;
      uVar12 = 0xc00c6101;
      goto LAB_00112548;
    }
    if (param_2 != 0xc00c6102) {
      uVar12 = 0xc010610c;
      goto LAB_00112548;
    }
LAB_001124c4:
    uVar15 = (ulong)(param_2 >> 0x10 & 0x3fff);
    piVar5 = (int *)__kmalloc(uVar15,0xdc0);
    if (piVar5 != (int *)0x0) {
      if ((int)param_2 < -0x3ff79eef) {
        if (param_2 == 0xc0046105) {
          iVar4 = aw882xx_dsp_read_f0(param_1,piVar5);
        }
        else if (param_2 == 0xc0046107) {
          iVar4 = aw882xx_dsp_read_cali_re(param_1,piVar5);
        }
        else {
          if (param_2 != 0xc0046109) goto LAB_00112c68;
          iVar4 = aw882xx_dsp_read_vmax(param_1,piVar5,4);
        }
      }
      else if ((int)param_2 < -0x3fef9ef3) {
        if (param_2 == 0xc0086111) {
          iVar1 = *(int *)(param_1 + 0x44);
          iVar4 = 0;
          *piVar5 = *(int *)(param_1 + 0x48);
          piVar5[1] = iVar1;
        }
        else if (param_2 == 0xc00c6102) {
          iVar4 = aw882xx_dsp_read_cali_cfg(param_1,piVar5,0xc);
        }
        else {
LAB_00112c68:
          lVar10 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar10 == 0) {
            lVar10 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_001230e3,lVar10,"aw_cali_misc_ops_read",param_2);
          iVar4 = -0x16;
        }
      }
      else if (param_2 == 0xc010610d) {
        iVar4 = aw882xx_dsp_read_f0_q(param_1,piVar5,piVar5 + 1);
      }
      else {
        if (param_2 != 0xc0186103) goto LAB_00112c68;
        iVar4 = aw882xx_dsp_read_cali_data(param_1,piVar5,0x18);
      }
      __check_object_size(piVar5,uVar15,1);
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 <= 0x8000000000 - uVar15) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar6 = daif;
            daif = uVar6 | 0xc0;
          }
          puVar14 = (undefined8 *)puVar14[1];
          uVar6 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        uVar15 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,piVar5,uVar15);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar6 = daif;
            daif = uVar6 | 0xc0;
          }
          uVar6 = ttbr1_el1;
          ttbr0_el1 = (uVar6 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar6 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
      }
      if (uVar15 != 0) {
        iVar4 = -0xe;
      }
      goto LAB_00112b2c;
    }
  }
  iVar4 = -0xc;
LAB_00112b34:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// aw_cali_misc_read_dsp @ 00112e5c size=436
// signature: undefined aw_cali_misc_read_dsp(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aw_cali_misc_read_dsp(long param_1,long param_2)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  
  iVar2 = *(int *)(param_2 + 0xc);
  lVar9 = (long)iVar2;
  uVar10 = *(ulong *)(param_2 + 0x10);
  uVar1 = *(undefined4 *)(param_2 + 4);
  lVar6 = __kmalloc(lVar9,0xdc0);
  if (lVar6 == 0) {
    iVar5 = -0xc;
  }
  else {
    iVar5 = aw882xx_dsp_read_dsp_msg(param_1,uVar1,lVar6,iVar2);
    if (iVar5 == 0) {
      if (iVar2 < 0) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x112ff8);
        (*pcVar4)();
      }
      __check_object_size(lVar6,lVar9,1);
      puVar7 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar8 = uVar10, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar8 = uVar10 & (long)(uVar10 << 8) >> 8;
      }
      if (uVar8 <= 0x8000000000U - lVar9) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar3 = daif;
            daif = uVar3 | 0xc0;
          }
          puVar7 = (undefined8 *)puVar7[1];
          uVar3 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        lVar9 = __arch_copy_to_user(puVar7,uVar10 & 0xff7fffffffffffff,lVar6,lVar9);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar8 = daif;
            daif = uVar8 | 0xc0;
          }
          uVar8 = ttbr1_el1;
          ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar8 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
      }
      iVar5 = 0;
      if (lVar9 != 0) {
        iVar5 = -0xe;
      }
    }
    else {
      lVar9 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar9 == 0) {
        lVar9 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011efd5,lVar9,"aw_cali_misc_read_dsp");
    }
    kfree(lVar6);
  }
  return iVar5;
}



//------------------------------------------------------------
// aw_cali_misc_write_dsp @ 0011302c size=488
// signature: undefined aw_cali_misc_write_dsp(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int aw_cali_misc_write_dsp(long param_1,long param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  size_t __n;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  size_t sVar9;
  ulong uVar10;
  
  iVar4 = *(int *)(param_2 + 0xc);
  sVar9 = (size_t)iVar4;
  uVar10 = *(ulong *)(param_2 + 0x10);
  uVar1 = *(undefined4 *)(param_2 + 4);
  lVar5 = __kmalloc(sVar9,0xdc0);
  if (lVar5 == 0) {
    iVar4 = -0xc;
  }
  else {
    if (iVar4 < 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1131c0);
      (*pcVar3)();
    }
    __check_object_size(lVar5,sVar9,0);
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = uVar10, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar8 = uVar10 & (long)(uVar10 << 8) >> 8;
    }
    __n = sVar9;
    if (uVar8 <= 0x8000000000 - sVar9) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar2 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      __n = __arch_copy_from_user(puVar7,lVar5,uVar10 & 0xff7fffffffffffff,sVar9);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar10 = daif;
        if ((uVar10 & 0x80) == 0) {
          uVar8 = daif;
          daif = uVar8 | 0xc0;
        }
        uVar8 = ttbr1_el1;
        ttbr0_el1 = (uVar8 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar8 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar10;
      }
    }
    if (__n == 0) {
      iVar4 = aw882xx_dsp_write_dsp_msg(param_1,uVar1,lVar5,iVar4);
      if (iVar4 != 0) {
        lVar6 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar6 == 0) {
          lVar6 = **(long **)(param_1 + 0x78);
        }
        _printk(&DAT_0011d6dd,lVar6,"aw_cali_misc_write_dsp");
      }
    }
    else {
      memset((void *)(lVar5 + (sVar9 - __n)),0,__n);
      lVar6 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011d0bf,lVar6,"aw_cali_misc_write_dsp");
      iVar4 = -0xe;
    }
    kfree(lVar5);
  }
  return iVar4;
}



//------------------------------------------------------------
// aw_dev_monitor_hw_status @ 00113374 size=412
// signature: undefined aw_dev_monitor_hw_status(void)
// callers: [aw882xx_monitor_start]
//------------------------------------------------------------

void aw_dev_monitor_hw_status(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 local_34;
  int local_30;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  local_34 = 0;
  local_30 = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1133c8);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1 + 0x4c8))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x218),&local_2c);
  if (iVar2 != 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122df3,lVar3,"aw_dev_monitor_hw_status");
    local_2c = 0;
  }
  iVar2 = aw882xx_dsp_read_st(param_1,&local_30,&local_34);
  if (iVar2 != 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00123986,lVar3,"aw_dev_monitor_hw_status");
    local_30 = 0;
  }
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0012104c,lVar3,"aw_dev_monitor_hw_status",local_2c,local_30);
  if (local_30 == 99000) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 1;
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0012235f,lVar3,"aw_dev_monitor_hw_status");
  }
  if ((local_2c >> 3 & 1) != 0) {
    *(uint *)(param_1 + 0x34) = *(uint *)(param_1 + 0x34) | 2;
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122b13,lVar3,"aw_dev_monitor_hw_status");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw_dev_i2s_enable @ 00113514 size=168
// signature: undefined aw_dev_i2s_enable(void)
// callers: []
//------------------------------------------------------------

void aw_dev_i2s_enable(long param_1,ulong param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  
  if (*(int *)(param_1 + 0x1b0) == 0xff) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011fc01,lVar1,"aw_dev_i2s_enable");
  }
  else {
    if ((param_2 & 1) == 0) {
      pcVar5 = *(code **)(param_1 + 0x4d0);
      uVar4 = *(undefined8 *)(param_1 + 0x80);
      uVar2 = *(undefined4 *)(param_1 + 0x1b4);
      uVar3 = *(undefined4 *)(param_1 + 0x1bc);
    }
    else {
      pcVar5 = *(code **)(param_1 + 0x4d0);
      uVar4 = *(undefined8 *)(param_1 + 0x80);
      uVar2 = *(undefined4 *)(param_1 + 0x1b4);
      if (*(char *)(param_1 + 0x291) == '\0') {
        uVar3 = *(undefined4 *)(param_1 + 0x1c0);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0x1b8);
      }
    }
    if (*(int *)(pcVar5 + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x113584);
      (*pcVar5)();
    }
    (*pcVar5)(uVar4,*(int *)(param_1 + 0x1b0),uVar2,uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_device_start @ 001135c0 size=2916
// signature: undefined aw882xx_device_start(void)
// callers: [aw882xx_start_pa]
//------------------------------------------------------------

int aw882xx_device_start(int *param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  long lVar6;
  long *plVar7;
  uint *puVar8;
  uint local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  if (*param_1 == 1) {
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    puVar5 = &DAT_0011fa5e;
LAB_00113ff4:
    _printk(puVar5,lVar6,"aw882xx_device_start");
    iVar3 = 0;
    goto LAB_00114004;
  }
  if ((param_1[0x43] != 0xff) && (param_1[0x47] != 0xff)) {
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113658);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x43],param_1[0x44],param_1[0x45]);
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113688);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x47],param_1[0x48],param_1[0x49]);
  }
  if (param_1[0x104] != 0xff) {
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1136c4);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x104],param_1[0x105],param_1[0x107]);
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x102),0);
  }
  if (param_1[0x128] != 0xff) {
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11372c);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x128],param_1[0x129],param_1[299]);
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x126),0);
  }
  if (param_1[0x56] != 0xff) {
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113790);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x56],param_1[0x57],param_1[0x59]);
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x54),0);
  }
  usleep_range_state(2000,0x7da,2);
  iVar3 = aw_dev_mode1_pll_check(param_1);
  if (-1 < iVar3) {
LAB_00113834:
    if (param_1[0x5c] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113868);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x5c],param_1[0x5d],param_1[0x5f]);
      lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x5a),0);
    }
    usleep_range_state(1000,0x41a,2);
    local_5c = 0;
    puVar8 = (uint *)(param_1 + 0x88);
    if (param_1[0x10a] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x132) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1138e0);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x132))(*(undefined8 *)(param_1 + 0x20),param_1[0x10a],&local_5c);
      puVar8 = (uint *)(param_1 + 0x89);
      if ((local_5c & (param_1[0x10b] ^ 0xffffffffU)) != 0) {
        puVar8 = (uint *)(param_1 + 0x88);
      }
    }
    iVar3 = 0;
    uVar4 = *puVar8;
    do {
      if (*(int *)(*(code **)(param_1 + 0x132) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113968);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x132))(*(undefined8 *)(param_1 + 0x20),param_1[0x86],&local_5c);
      plVar7 = *(long **)(param_1 + 0x1e);
      lVar6 = plVar7[0xe];
      if ((uVar4 & (param_1[0x87] ^ 0xffffffffU) & local_5c) == uVar4) {
        if (lVar6 == 0) {
          lVar6 = *plVar7;
        }
        _printk(&DAT_0011df48,lVar6,"aw_dev_sysst_check");
        if ((param_1[0x43] != 0xff) && (param_1[0x47] != 0xff)) {
          if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1139f4);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x134))
                    (*(undefined8 *)(param_1 + 0x20),param_1[0x47],param_1[0x48],param_1[0x4a]);
          usleep_range_state(5000,0x13ba,2);
          if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113a34);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x134))
                    (*(undefined8 *)(param_1 + 0x20),param_1[0x47],param_1[0x48],param_1[0x4b]);
          if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113a64);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x134))
                    (*(undefined8 *)(param_1 + 0x20),param_1[0x43],param_1[0x44],param_1[0x46]);
        }
        if (param_1[0x6c] == 0xff) {
          lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
          if (lVar6 == 0) {
            lVar6 = **(long **)(param_1 + 0x1e);
          }
          _printk(&DAT_0011fc01,lVar6,"aw_dev_i2s_enable");
          pcVar2 = *(code **)(param_1 + 0x13c);
        }
        else {
          if (*(char *)((long)param_1 + 0x291) == '\0') {
            iVar3 = param_1[0x70];
          }
          else {
            iVar3 = param_1[0x6e];
          }
          if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113dc8);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x134))
                    (*(undefined8 *)(param_1 + 0x20),param_1[0x6c],param_1[0x6d],iVar3);
          pcVar2 = *(code **)(param_1 + 0x13c);
        }
        if (pcVar2 != (code *)0x0) {
          if (*(int *)(pcVar2 + -4) != 0x75a9b632) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113df0);
            (*pcVar2)();
          }
          (*pcVar2)(param_1);
        }
        if (param_1[0x68] != 0xff) {
          if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113e28);
            (*pcVar2)();
          }
          (**(code **)(param_1 + 0x134))
                    (*(undefined8 *)(param_1 + 0x20),param_1[0x68],param_1[0x69],param_1[0x6b]);
          lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
          if (lVar6 == 0) {
            lVar6 = **(long **)(param_1 + 0x1e);
          }
          _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x66),0);
        }
        if (param_1[10] != 0) {
          aw_dev_switch(param_1,param_1 + 0x102,1);
        }
        uVar4 = aw882xx_cali_check_result(param_1 + 0xa4);
        aw882xx_dev_mute(param_1,(uVar4 ^ 0xffffffff) & 1);
        if (param_1[0xc] != 0) {
          aw_dev_switch(param_1,param_1 + 0x126,1);
        }
        aw882xx_dev_clear_int_status(param_1);
        aw882xx_monitor_start(param_1 + 0xaa);
        if ((*(char *)((long)param_1 + 0x291) != '\0') && (uVar4 = param_1[0xa5], uVar4 != 0)) {
          if ((uVar4 < (uint)param_1[0x12]) || ((uint)param_1[0x11] < uVar4)) {
            lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
            if (lVar6 == 0) {
              lVar6 = **(long **)(param_1 + 0x1e);
            }
            _printk(&DAT_001223ec,lVar6,"aw_dev_cali_re_update");
          }
          else {
            aw882xx_dsp_write_cali_re(param_1);
          }
        }
        pcVar2 = *(code **)(param_1 + 0x140);
        local_5c = 0xffffffff;
        if (pcVar2 == (code *)0x0) {
          lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
          if (lVar6 == 0) {
            lVar6 = **(long **)(param_1 + 0x1e);
          }
          _printk(&DAT_0012133f,lVar6,"aw_dev_vol_offset_update");
        }
        else {
          if (*(int *)(pcVar2 + -4) != 0x697ce87c) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113f60);
            (*pcVar2)();
          }
          (*pcVar2)(param_1,&local_5c);
          if (param_1[0x13] != 0) {
            local_5c = param_1[0x14];
          }
          aw882xx_dsp_write_vol_offset(param_1,local_5c);
        }
        *param_1 = 1;
        if (*(int *)(*(code **)(param_1 + 0x130) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113fb4);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x130))(*(undefined8 *)(param_1 + 0x20),param_1[0x4c],param_1[0x4f]);
        lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
        if (lVar6 == 0) {
          lVar6 = **(long **)(param_1 + 0x1e);
        }
        _printk(&DAT_0011df48,lVar6,"aw882xx_dev_set_intmask");
        lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
        if (lVar6 == 0) {
          lVar6 = **(long **)(param_1 + 0x1e);
        }
        puVar5 = &DAT_0011df48;
        goto LAB_00113ff4;
      }
      if (lVar6 == 0) {
        lVar6 = *plVar7;
      }
      _printk(&DAT_00121079,lVar6,"aw_dev_sysst_check",iVar3);
      usleep_range_state(2000,0x7da,2);
      iVar3 = iVar3 + 1;
    } while (iVar3 != 10);
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_001223ce,lVar6,"aw_dev_sysst_check");
    iVar3 = param_1[7];
    local_5c = 0;
    if (0 < iVar3) {
      uVar4 = 0;
      do {
        if (*(int *)(*(code **)(param_1 + 0x132) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113b14);
          (*pcVar2)();
        }
        (**(code **)(param_1 + 0x132))(*(undefined8 *)(param_1 + 0x20),uVar4,&local_5c);
        lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
        if (lVar6 == 0) {
          lVar6 = **(long **)(param_1 + 0x1e);
        }
        _printk(&DAT_0011f719,lVar6,"aw_dev_reg_dump",uVar4,local_5c);
        uVar4 = uVar4 + 1 & 0xff;
      } while ((int)uVar4 < iVar3);
    }
    if (param_1[0x6c] == 0xff) {
      lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011fc01,lVar6,"aw_dev_i2s_enable");
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113b80);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x6c],param_1[0x6d],param_1[0x6f]);
    }
    aw882xx_dev_clear_int_status(param_1);
    if (param_1[0x5c] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11408c);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x5c],param_1[0x5d],param_1[0x5e]);
      lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x5a),1);
    }
    if (param_1[0x56] == 0xff) {
      iVar3 = -0x16;
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1140e8);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x56],param_1[0x57],param_1[0x58]);
      lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x54),1);
      iVar3 = -0x16;
    }
    goto LAB_00114004;
  }
  plVar7 = *(long **)(param_1 + 0x1e);
  lVar6 = plVar7[0xe];
  if (param_1[0x8b] == 0xff) {
    if (lVar6 == 0) {
      lVar6 = *plVar7;
    }
    puVar5 = &DAT_0011f03a;
  }
  else {
    if (lVar6 == 0) {
      lVar6 = *plVar7;
    }
    _printk(&DAT_0012238a,lVar6,"aw_dev_syspll_check");
    local_5c = 0;
    if (param_1[0x8b] == 0xff) goto LAB_00113834;
    if (*(int *)(*(code **)(param_1 + 0x132) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113bec);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x132))(*(undefined8 *)(param_1 + 0x20),param_1[0x8b],&local_5c);
    local_5c = local_5c & (param_1[0x8c] ^ 0xffffffffU);
    if (local_5c == param_1[0x8d]) {
LAB_00113c98:
      iVar3 = -1;
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113c30);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))(*(undefined8 *)(param_1 + 0x20),param_1[0x8b]);
      iVar3 = aw_dev_mode1_pll_check(param_1);
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113c6c);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x8b],param_1[0x8c],param_1[0x8e]);
      if (iVar3 != 0) goto LAB_00113c98;
      usleep_range_state(2000,0x7da,2);
      iVar3 = aw_dev_mode1_pll_check(param_1);
      if (-1 < iVar3) goto LAB_00113834;
    }
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    puVar5 = &DAT_001239ba;
  }
  _printk(puVar5,lVar6,"aw_dev_syspll_check");
  iVar1 = param_1[7];
  local_5c = 0;
  if (0 < iVar1) {
    uVar4 = 0;
    do {
      if (*(int *)(*(code **)(param_1 + 0x132) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113d0c);
        (*pcVar2)();
      }
      (**(code **)(param_1 + 0x132))(*(undefined8 *)(param_1 + 0x20),uVar4,&local_5c);
      lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011f719,lVar6,"aw_dev_reg_dump",uVar4,local_5c);
      uVar4 = uVar4 + 1 & 0xff;
    } while ((int)uVar4 < iVar1);
  }
  if (param_1[0x56] != 0xff) {
    if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x113d78);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x134))
              (*(undefined8 *)(param_1 + 0x20),param_1[0x56],param_1[0x57],param_1[0x58]);
    lVar6 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar6 == 0) {
      lVar6 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011ebfe,lVar6,"aw_dev_switch",*(undefined8 *)(param_1 + 0x54),1);
  }
LAB_00114004:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// aw_dev_switch @ 00114124 size=172
// signature: undefined aw_dev_switch(void)
// callers: [aw882xx_device_start]
//------------------------------------------------------------

void aw_dev_switch(long param_1,undefined8 *param_2,uint param_3)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(param_2 + 1) != 0xff) {
    lVar2 = 0x10;
    if ((param_3 & 1) == 0) {
      lVar2 = 0x14;
    }
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x11419c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(int *)(param_2 + 1),
               *(undefined4 *)((long)param_2 + 0xc),*(undefined4 *)((long)param_2 + lVar2));
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*param_2,param_3 & 1);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_clear_int_status @ 001141d4 size=300
// signature: undefined aw882xx_dev_clear_int_status(void)
// callers: [aw882xx_device_stop, aw882xx_device_start]
//------------------------------------------------------------

void aw882xx_dev_clear_int_status(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114224);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1 + 0x4c8))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x134),&local_2c);
  if (iVar2 < 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011f319,lVar3,"aw882xx_dev_get_int_status",iVar2);
  }
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114280);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1 + 0x4c8))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x134),&local_2c);
  if (iVar2 < 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011f319,lVar3,"aw882xx_dev_get_int_status",iVar2);
  }
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar3,"aw882xx_dev_clear_int_status");
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_mute @ 00114304 size=1336
// signature: undefined aw882xx_dev_mute(void)
// callers: [aw882xx_device_stop, aw_cali_store_cali_re, aw_cali_svc_dev_get_re, aw882xx_device_start, aw_cali_svc_cali_re, aw_cali_svc_cali_f0, aw_cali_svc_run_mute, aw_cali_svc_cali_f0_q, aw_cali_svc_devs_cali_mode_enable]
//------------------------------------------------------------

void aw882xx_dev_mute(long param_1,ulong param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  int iVar6;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  if ((param_2 & 1) == 0) {
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x114458);
      (*pcVar5)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x188),
               *(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 0x194));
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar1 = *(int *)(param_1 + 0x40);
      iVar6 = *(int *)(param_1 + 0x270);
      if ((iVar1 == 0) || (g_fade_in_time == 0)) {
        uVar3 = *(int *)(param_1 + 0x268) + iVar6;
        pcVar5 = *(code **)(param_1 + 0x4e0);
        if (*(uint *)(param_1 + 0x26c) <= uVar3) {
          uVar3 = *(uint *)(param_1 + 0x26c);
        }
      }
      else {
        uVar2 = *(uint *)(param_1 + 0x26c);
        if (iVar6 <= (int)uVar2) {
          do {
            local_4c = 0;
            uVar3 = uVar2 + *(int *)(param_1 + 0x268);
            pcVar5 = *(code **)(param_1 + 0x4e0);
            if (*(uint *)(param_1 + 0x26c) <= uVar3) {
              uVar3 = *(uint *)(param_1 + 0x26c);
            }
            if (pcVar5 != (code *)0x0) {
              if (*(int *)(pcVar5 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x114550);
                (*pcVar5)();
              }
              uVar3 = (*pcVar5)(uVar3);
            }
            if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1144b4);
              (*pcVar5)();
            }
            (**(code **)(param_1 + 0x4c8))
                      (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_4c);
            if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x1144f4);
              (*pcVar5)();
            }
            (**(code **)(param_1 + 0x4c0))
                      (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
                       *(uint *)(param_1 + 0x260) & local_4c |
                       uVar3 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
            usleep_range_state(g_fade_in_time,g_fade_in_time + 10,2);
            uVar2 = uVar2 - iVar1;
          } while (iVar6 <= (int)uVar2);
          uVar2 = *(uint *)(param_1 + 0x26c);
        }
        uVar3 = *(int *)(param_1 + 0x268) + iVar6;
        pcVar5 = *(code **)(param_1 + 0x4e0);
        if (uVar2 <= uVar3) {
          uVar3 = uVar2;
        }
      }
      local_4c = 0;
      if (pcVar5 != (code *)0x0) {
        local_4c = 0;
        if (*(int *)(pcVar5 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11464c);
          (*pcVar5)();
        }
        uVar3 = (*pcVar5)(uVar3);
      }
      if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11467c);
        (*pcVar5)();
      }
      (**(code **)(param_1 + 0x4c8))
                (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_4c);
      if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x1146bc);
        (*pcVar5)();
      }
      (**(code **)(param_1 + 0x4c0))
                (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
                 *(uint *)(param_1 + 0x260) & local_4c |
                 uVar3 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
    }
  }
  else {
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar1 = *(int *)(param_1 + 0x40);
      if ((iVar1 == 0) || (g_fade_out_time == 0)) {
        uVar2 = *(uint *)(param_1 + 0x26c);
        local_4c = 0;
        uVar3 = *(int *)(param_1 + 0x268) + uVar2;
        pcVar5 = *(code **)(param_1 + 0x4e0);
        if (uVar2 <= uVar3) {
          uVar3 = uVar2;
        }
        if (pcVar5 != (code *)0x0) {
          if (*(int *)(pcVar5 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x114598);
            (*pcVar5)();
          }
          uVar3 = (*pcVar5)(uVar3);
        }
        if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1145c8);
          (*pcVar5)();
        }
        (**(code **)(param_1 + 0x4c8))
                  (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_4c);
        if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x114608);
          (*pcVar5)();
        }
        (**(code **)(param_1 + 0x4c0))
                  (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
                   *(uint *)(param_1 + 0x260) & local_4c |
                   uVar3 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
      }
      else {
        uVar3 = *(uint *)(param_1 + 0x26c);
        for (iVar6 = *(int *)(param_1 + 0x270); iVar6 <= (int)uVar3; iVar6 = iVar6 + iVar1) {
          local_4c = 0;
          uVar2 = iVar6 + *(int *)(param_1 + 0x268);
          pcVar5 = *(code **)(param_1 + 0x4e0);
          if (uVar3 <= uVar2) {
            uVar2 = uVar3;
          }
          if (pcVar5 != (code *)0x0) {
            if (*(int *)(pcVar5 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x114420);
              (*pcVar5)();
            }
            uVar2 = (*pcVar5)(uVar2);
          }
          if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x114384);
            (*pcVar5)();
          }
          (**(code **)(param_1 + 0x4c8))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_4c);
          if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x1143c4);
            (*pcVar5)();
          }
          (**(code **)(param_1 + 0x4c0))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
                     *(uint *)(param_1 + 0x260) & local_4c |
                     uVar2 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
          usleep_range_state(g_fade_out_time,g_fade_out_time + 10,2);
          uVar3 = *(uint *)(param_1 + 0x26c);
        }
        local_4c = 0;
        uVar2 = *(int *)(param_1 + 0x268) + uVar3;
        pcVar5 = *(code **)(param_1 + 0x4e0);
        if (uVar3 <= uVar2) {
          uVar2 = uVar3;
        }
        if (pcVar5 != (code *)0x0) {
          if (*(int *)(pcVar5 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x1146fc);
            (*pcVar5)();
          }
          uVar2 = (*pcVar5)(uVar2);
        }
        if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11472c);
          (*pcVar5)();
        }
        (**(code **)(param_1 + 0x4c8))
                  (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_4c);
        if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x11476c);
          (*pcVar5)();
        }
        (**(code **)(param_1 + 0x4c0))
                  (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
                   *(uint *)(param_1 + 0x260) & local_4c |
                   uVar2 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
        usleep_range_state(g_fade_out_time,g_fade_out_time + 10,2);
      }
    }
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1147ac);
      (*pcVar5)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x188),
               *(undefined4 *)(param_1 + 0x18c),*(undefined4 *)(param_1 + 400));
    usleep_range_state(5000,0x13ba,2);
  }
  lVar4 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar4 == 0) {
    lVar4 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar4,"aw882xx_dev_mute");
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_set_intmask @ 00114840 size=200
// signature: undefined aw882xx_dev_set_intmask(void)
// callers: [aw882xx_irq, aw882xx_interrupt_work]
//------------------------------------------------------------

undefined4 aw882xx_dev_set_intmask(int *param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  
  if ((*param_1 == 0) && ((param_2 & 1) != 0)) {
    lVar5 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011e3bc,lVar5,"aw882xx_dev_set_intmask");
  }
  else if ((param_2 & 1) != 0) {
    pcVar6 = *(code **)(param_1 + 0x130);
    uVar4 = *(undefined8 *)(param_1 + 0x20);
    iVar1 = param_1[0x4c];
    iVar2 = param_1[0x4f];
    goto LAB_001148b0;
  }
  pcVar6 = *(code **)(param_1 + 0x130);
  uVar4 = *(undefined8 *)(param_1 + 0x20);
  iVar1 = param_1[0x4c];
  iVar2 = param_1[0x4e];
LAB_001148b0:
  if (*(int *)(pcVar6 + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1148c8);
    (*pcVar6)();
  }
  uVar3 = (*pcVar6)(uVar4,iVar1,iVar2);
  lVar5 = (*(long **)(param_1 + 0x1e))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + 0x1e);
  }
  _printk(&DAT_0011df48,lVar5,"aw882xx_dev_set_intmask");
  return uVar3;
}



//------------------------------------------------------------
// aw882xx_device_stop @ 0011490c size=628
// signature: undefined aw882xx_device_stop(void)
// callers: [aw882xx_i2c_shutdown, aw882xx_mute, aw882xx_profile_set, aw882xx_switch_set, aw882xx_dev_init, aw882xx_dc_prot_work]
//------------------------------------------------------------

undefined8 aw882xx_device_stop(int *param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (*param_1 != 0) {
    *param_1 = 0;
    aw882xx_monitor_stop(param_1 + 0xaa);
    aw882xx_dev_clear_int_status(param_1);
    if (*(int *)(*(code **)(param_1 + 0x130) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114978);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x130))(*(undefined8 *)(param_1 + 0x20),param_1[0x4c],param_1[0x4e]);
    lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011df48,lVar2,"aw882xx_dev_set_intmask");
    if (param_1[0x68] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1149d4);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x68],param_1[0x69],param_1[0x6a]);
      lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x66),1);
    }
    aw882xx_dev_mute(param_1,1);
    usleep_range_state(5000,0x1392,2);
    if (param_1[0x6c] == 0xff) {
      lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011fc01,lVar2,"aw_dev_i2s_enable");
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114a7c);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x6c],param_1[0x6d],param_1[0x6f]);
    }
    usleep_range_state(1000,0x44c,2);
    if (param_1[0x5c] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114ac4);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x5c],param_1[0x5d],param_1[0x5e]);
      lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x5a),1);
    }
    if (param_1[0x56] != 0xff) {
      if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114b28);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x134))
                (*(undefined8 *)(param_1 + 0x20),param_1[0x56],param_1[0x57],param_1[0x58]);
      lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x54),1);
    }
    lVar2 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_0011df48,lVar2,"aw882xx_device_stop");
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_reg_update @ 00114b84 size=204
// signature: undefined aw882xx_dev_reg_update(void)
// callers: [aw882xx_start_pa]
//------------------------------------------------------------

undefined8 aw882xx_dev_reg_update(long param_1,ulong param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((param_2 & 1) == 0) {
    if (*(char *)(param_1 + 0x38) == *(char *)(param_1 + 0x39)) goto LAB_00114bc8;
  }
  else {
    if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x114c24);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4c0))
              (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x3c8),
               *(undefined4 *)(param_1 + 0x3cc));
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122090,lVar3,"aw_dev_soft_reset");
  }
  uVar2 = aw_dev_reg_fw_update(param_1);
  if ((int)uVar2 < 0) {
    return uVar2;
  }
LAB_00114bc8:
  *(undefined1 *)(param_1 + 0x38) = *(undefined1 *)(param_1 + 0x39);
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar3,"aw882xx_dev_reg_update");
  return 0;
}



//------------------------------------------------------------
// aw_dev_reg_fw_update @ 00114c50 size=1768
// signature: undefined aw_dev_reg_fw_update(void)
// callers: [aw882xx_dev_reg_update, aw882xx_dev_irq_reinit, aw882xx_dev_init]
//------------------------------------------------------------

int aw_dev_reg_fw_update(long param_1)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  code *pcVar6;
  undefined4 uVar7;
  int iVar8;
  long lVar9;
  uint *puVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  uint uVar14;
  uint uVar15;
  ulong uVar16;
  uint local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = aw882xx_dev_get_prof_name(param_1,*(undefined1 *)(param_1 + 0x39));
  if (lVar9 == 0) {
    lVar9 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar9 == 0) {
      lVar9 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011e7d0,lVar9,"aw_dev_reg_fw_update");
  }
  else {
    puVar10 = (uint *)aw882xx_dev_get_prof_data(param_1,*(undefined1 *)(param_1 + 0x39),0);
    if (puVar10 != (uint *)0x0) {
      uVar14 = *puVar10;
      if (1 < uVar14) {
        uVar16 = 0;
        lVar11 = *(long *)(puVar10 + 2);
        do {
          uVar13 = -(uVar16 >> 0x1f) & 0xfffffffe00000000 | uVar16 << 1;
          sVar3 = *(short *)(lVar11 + uVar13);
          sVar4 = *(short *)(lVar11 + (uVar13 | 2));
          uVar15 = (uint)sVar4;
          if (*(int *)(param_1 + 0x130) == (int)sVar3) {
            *(int *)(param_1 + 0x13c) = (int)sVar4;
            uVar15 = *(uint *)(param_1 + 0x138);
          }
          if (*(int *)(param_1 + 0x10c) != 0xff) {
            if (*(int *)(param_1 + 0x10c) == (int)sVar3) {
              *(uint *)(param_1 + 0x118) = uVar15 & (*(uint *)(param_1 + 0x110) ^ 0xffffffff);
            }
            if (*(int *)(param_1 + 0x11c) == (int)sVar3) {
              *(uint *)(param_1 + 300) = uVar15 & (*(uint *)(param_1 + 0x120) ^ 0xffffffff);
            }
          }
          if (*(int *)(param_1 + 0xd0) == (int)sVar3) {
            uVar15 = *(uint *)(param_1 + 0xd4) & uVar15 | *(uint *)(param_1 + 0xd8);
          }
          iVar8 = (int)sVar3;
          if (*(int *)(param_1 + 0x170) == iVar8) {
            uVar15 = *(uint *)(param_1 + 0x174) & uVar15 | *(uint *)(param_1 + 0x178);
          }
          if ((*(int *)(param_1 + 0xfc) != 0xff) && (*(int *)(param_1 + 0xfc) == iVar8)) {
            *(uint *)(param_1 + 0x14) =
                 (uint)((uVar15 & (*(uint *)(param_1 + 0x100) ^ 0xffffffff)) ==
                       *(uint *)(param_1 + 0x108));
            lVar12 = (*(long **)(param_1 + 0x78))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(param_1 + 0x78);
            }
            _printk(&DAT_0012025a,lVar12,"aw_dev_reg_value_check");
          }
          if (*(int *)(param_1 + 0x140) == iVar8) {
            *(uint *)(param_1 + 8) =
                 (uint)((uVar15 & (*(uint *)(param_1 + 0x144) ^ 0xffffffff)) !=
                       *(uint *)(param_1 + 0x14c));
          }
          if (*(int *)(param_1 + 0x158) == iVar8) {
            uVar15 = *(uint *)(param_1 + 0x15c) & uVar15 | *(uint *)(param_1 + 0x160);
          }
          if (*(int *)(param_1 + 0x188) == iVar8) {
            uVar15 = *(uint *)(param_1 + 0x18c) & uVar15 | *(uint *)(param_1 + 400);
          }
          if (*(int *)(param_1 + 0x1a0) == iVar8) {
            uVar15 = *(uint *)(param_1 + 0x1a4) & uVar15 | *(uint *)(param_1 + 0x1a8);
          }
          if (*(int *)(param_1 + 0x1b0) == iVar8) {
            *(uint *)(param_1 + 0x1c0) = uVar15 & (*(uint *)(param_1 + 0x1b4) ^ 0xffffffff);
            lVar12 = (*(long **)(param_1 + 0x78))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(param_1 + 0x78);
            }
            _printk(&DAT_001215e9,lVar12,"aw_dev_reg_value_check");
            uVar15 = *(uint *)(param_1 + 0x1b4) & uVar15 | *(uint *)(param_1 + 0x1bc);
          }
          if ((*(int *)(param_1 + 0x25c) == iVar8) &&
             (pcVar6 = *(code **)(param_1 + 0x4d8), pcVar6 != (code *)0x0)) {
            if (*(int *)(pcVar6 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x114f50);
              (*pcVar6)();
            }
            uVar7 = (*pcVar6)((uVar15 & (*(uint *)(param_1 + 0x260) ^ 0xffffffff)) >>
                              (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
            *(undefined4 *)(param_1 + 0x268) = uVar7;
          }
          iVar8 = (int)sVar3;
          if (*(int *)(param_1 + 0x410) == iVar8) {
            *(uint *)(param_1 + 0x28) = uVar15 & (*(uint *)(param_1 + 0x414) ^ 0xffffffff);
            lVar12 = (*(long **)(param_1 + 0x78))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(param_1 + 0x78);
            }
            _printk(&DAT_00122705,lVar12,"aw_dev_reg_value_check");
          }
          if (*(int *)(param_1 + 0x4a0) == iVar8) {
            *(uint *)(param_1 + 0x30) = uVar15 & (*(uint *)(param_1 + 0x4a4) ^ 0xffffffff);
            lVar12 = (*(long **)(param_1 + 0x78))[0xe];
            if (lVar12 == 0) {
              lVar12 = **(long **)(param_1 + 0x78);
            }
            _printk(&DAT_0011ff0f,lVar12,"aw_dev_reg_value_check");
          }
          if (*(int *)(param_1 + 0x20c) != iVar8) {
            if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x114fa4);
              (*pcVar6)();
            }
            iVar8 = (**(code **)(param_1 + 0x4c0))(*(undefined8 *)(param_1 + 0x80),iVar8,uVar15);
            if (iVar8 < 0) break;
          }
          uVar15 = (int)uVar16 + 2;
          uVar16 = (ulong)uVar15;
        } while ((int)uVar15 < (int)(uVar14 >> 1));
      }
      aw882xx_spin_set_record_val(param_1);
      if ((*(int *)(param_1 + 0x1c4) == 0xff) || (*(int *)(param_1 + 0x20c) == 0xff)) {
        lVar11 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar11 == 0) {
          lVar11 = **(long **)(param_1 + 0x78);
        }
        _printk(&DAT_0011e04b,lVar11,"aw_dev_set_vcalb");
        iVar8 = 0;
LAB_00114d64:
        if (*(char *)(param_1 + 0x38) != *(char *)(param_1 + 0x39)) {
          *(undefined4 *)(param_1 + 0x270) = 0;
        }
        if (*(int *)(param_1 + 0x18) != 0) {
          aw882xx_dev_set_volume(param_1,*(undefined4 *)(param_1 + 0x26c));
        }
        lVar11 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar11 == 0) {
          lVar11 = **(long **)(param_1 + 0x78);
        }
        _printk(&DAT_0011e02b,lVar11,"aw_dev_reg_fw_update",lVar9);
      }
      else {
        local_6c = 0;
        iVar1 = *(int *)(param_1 + 0x1d0);
        if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1150b0);
          (*pcVar6)();
        }
        iVar8 = (**(code **)(param_1 + 0x4c8))
                          (*(undefined8 *)(param_1 + 0x80),*(int *)(param_1 + 0x1c4),&local_6c);
        uVar14 = local_6c & 0xffff;
        if (iVar1 == 0xff) {
          uVar14 = uVar14 & (*(uint *)(param_1 + 0x1c8) ^ 0xffffffff);
        }
        else {
          uVar15 = *(uint *)(param_1 + 0x1c8);
          if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1150fc);
            (*pcVar6)();
          }
          iVar8 = (**(code **)(param_1 + 0x4c8))
                            (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x1d0),
                             &local_6c);
          uVar15 = (uVar14 & (uVar15 ^ 0xffffffff)) >> (ulong)(*(uint *)(param_1 + 0x1cc) & 0x1f);
          uVar14 = (local_6c & 0xffff & (*(ushort *)(param_1 + 0x1d4) ^ 0xffff)) >>
                   (ulong)(*(uint *)(param_1 + 0x1d8) & 0x1f);
          if (*(int *)(param_1 + 0x14) == 1) {
            uVar14 = uVar14 | uVar15;
          }
          else {
            uVar14 = uVar14 & uVar15;
          }
        }
        if ((uVar14 & (*(uint *)(param_1 + 0x1dc) ^ 0xffffffff)) != 0) {
          uVar14 = uVar14 | *(uint *)(param_1 + 0x1e0) ^ 0xffffffff;
        }
        if (-1 < iVar8) {
          local_6c = 0;
          iVar1 = *(int *)(param_1 + 500);
          if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x115188);
            (*pcVar6)();
          }
          iVar8 = (**(code **)(param_1 + 0x4c8))
                            (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x1e8),
                             &local_6c);
          uVar15 = local_6c & 0xffff;
          if (iVar1 == 0xff) {
            uVar15 = uVar15 & (*(uint *)(param_1 + 0x1ec) ^ 0xffffffff);
          }
          else {
            uVar2 = *(uint *)(param_1 + 0x1ec);
            if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1151d4);
              (*pcVar6)();
            }
            iVar8 = (**(code **)(param_1 + 0x4c8))
                              (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 500),
                               &local_6c);
            uVar2 = (uVar15 & (uVar2 ^ 0xffffffff)) >> (ulong)(*(uint *)(param_1 + 0x1f0) & 0x1f);
            uVar15 = (local_6c & 0xffff & (*(ushort *)(param_1 + 0x1f8) ^ 0xffff)) >>
                     (ulong)(*(uint *)(param_1 + 0x1fc) & 0x1f);
            if (*(int *)(param_1 + 0x14) == 1) {
              uVar15 = uVar15 | uVar2;
            }
            else {
              uVar15 = uVar15 & uVar2;
            }
          }
          if ((uVar15 & (*(uint *)(param_1 + 0x200) ^ 0xffffffff)) != 0) {
            uVar15 = uVar15 | *(uint *)(param_1 + 0x204) ^ 0xffffffff;
          }
          if (-1 < iVar8) {
            iVar8 = *(int *)(param_1 + 0x210) + *(int *)(param_1 + 0x208) * (int)(short)uVar15;
            if (iVar8 == 0) {
              lVar9 = (*(long **)(param_1 + 0x78))[0xe];
              if (lVar9 == 0) {
                lVar9 = **(long **)(param_1 + 0x78);
              }
              _printk(&DAT_0012160d,lVar9,"aw_dev_set_vcalb");
              iVar8 = -0x16;
            }
            else {
              iVar1 = *(int *)(param_1 + 0x210) + *(int *)(param_1 + 0x1e4) * (int)(short)uVar14;
              iVar5 = 0;
              if (iVar8 != 0) {
                iVar5 = (iVar1 * *(int *)(param_1 + 0x214)) / iVar8;
              }
              lVar11 = (*(long **)(param_1 + 0x78))[0xe];
              if (lVar11 == 0) {
                lVar11 = **(long **)(param_1 + 0x78);
              }
              _printk(&DAT_00122729,lVar11,"aw_dev_set_vcalb",iVar1,iVar8,iVar5,iVar5);
              if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1152dc);
                (*pcVar6)();
              }
              iVar8 = (**(code **)(param_1 + 0x4c0))
                                (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x20c),
                                 iVar5);
              lVar11 = (*(long **)(param_1 + 0x78))[0xe];
              if (lVar11 == 0) {
                lVar11 = **(long **)(param_1 + 0x78);
              }
              _printk(&DAT_0011df48,lVar11,"aw_dev_set_vcalb");
              if (-1 < iVar8) goto LAB_00114d64;
            }
          }
        }
        lVar9 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar9 == 0) {
          lVar9 = **(long **)(param_1 + 0x78);
        }
        _printk(&DAT_0011e7f8,lVar9,"aw_dev_reg_fw_update");
      }
      goto LAB_00114cac;
    }
  }
  iVar8 = -0x16;
LAB_00114cac:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// aw882xx_dev_get_list_head @ 0011533c size=40
// signature: undefined aw882xx_dev_get_list_head(void)
// callers: [aw_cali_svc_get_devs_cali_re, aw_cali_svc_get_devs_r0, aw_cali_svc_get_devs_re_range, aw_cali_misc_open, aw_reg_write_spin, aw_cali_misc_switch_dev, aw_cali_class_cali_f0_store, aw_cali_svc_cali_re, aw_cali_svc_set_devs_re_str, aw_cali_class_cali_f0_show, aw_cali_class_cali_re_store, aw_cali_class_cali_re_show, aw_cali_svc_cali_f0, aw_cali_svc_get_devs_st, aw_cali_svc_get_devs_te, aw_cali_class_re_show, aw_cali_class_f0_show, aw_class_re_range_show, aw_cali_svc_get_devs_cali_f0, aw_cali_svc_get_devs_f0, aw_cali_svc_get_devs_cali_f0_q, aw_cali_svc_cali_f0_q]
//------------------------------------------------------------

undefined8 aw882xx_dev_get_list_head(undefined8 *param_1)

{
  if ((undefined **)g_dev_list == &g_dev_list) {
    return 0xffffffea;
  }
  *param_1 = &g_dev_list;
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_set_volume @ 00115368 size=260
// signature: undefined aw882xx_dev_set_volume(void)
// callers: [aw_dev_reg_fw_update, aw882xx_volume_put, aw_monitor_work_func]
//------------------------------------------------------------

undefined8 aw882xx_dev_set_volume(long param_1,int param_2)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  uVar2 = *(int *)(param_1 + 0x268) + param_2;
  pcVar3 = *(code **)(param_1 + 0x4e0);
  if (*(uint *)(param_1 + 0x26c) <= uVar2) {
    uVar2 = *(uint *)(param_1 + 0x26c);
  }
  if (pcVar3 != (code *)0x0) {
    if (*(int *)(pcVar3 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1153c8);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(uVar2);
  }
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1153f8);
    (*pcVar3)();
  }
  (**(code **)(param_1 + 0x4c8))
            (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_2c);
  if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x115438);
    (*pcVar3)();
  }
  (**(code **)(param_1 + 0x4c0))
            (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),
             *(uint *)(param_1 + 0x260) & local_2c |
             uVar2 << (ulong)(*(uint *)(param_1 + 0x264) & 0x1f));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_get_volume @ 00115470 size=216
// signature: undefined aw882xx_dev_get_volume(void)
// callers: []
//------------------------------------------------------------

undefined8 aw882xx_dev_get_volume(long param_1,int *param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1154c4);
    (*pcVar2)();
  }
  (**(code **)(param_1 + 0x4c8))
            (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x25c),&local_2c);
  uVar3 = (local_2c & (*(uint *)(param_1 + 0x260) ^ 0xffffffff)) >>
          (ulong)(*(uint *)(param_1 + 0x264) & 0x1f);
  pcVar2 = *(code **)(param_1 + 0x4d8);
  if (*(uint *)(param_1 + 0x26c) <= uVar3) {
    uVar3 = *(uint *)(param_1 + 0x26c);
  }
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x115508);
      (*pcVar2)();
    }
    uVar3 = (*pcVar2)();
  }
  *param_2 = uVar3 - *(int *)(param_1 + 0x268);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_algo_auth_get @ 0011554c size=48
// signature: undefined aw882xx_dev_algo_auth_get(void)
// callers: [aw882xx_algo_auth_tlv_rw]
//------------------------------------------------------------

undefined8 aw882xx_dev_algo_auth_get(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x484);
  param_2[3] = *(undefined4 *)(param_1 + 0x490);
  param_2[2] = *(undefined4 *)(param_1 + 0x48c);
  param_2[1] = *(undefined4 *)(param_1 + 0x488);
  param_2[4] = *(undefined4 *)(param_1 + 0x494);
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_algo_auth_set @ 00115580 size=416
// signature: undefined aw882xx_dev_algo_auth_set(void)
// callers: [aw882xx_algo_auth_tlv_rw, aw_algo_auth_misc_ops]
//------------------------------------------------------------

int aw882xx_dev_algo_auth_set(long param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  lVar4 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar4 == 0) {
    lVar4 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011d0e3,lVar4,"aw882xx_dev_algo_auth_set",*param_2);
  *(int *)(param_1 + 0x484) = *param_2;
  iVar2 = param_2[2];
  *(undefined4 *)(param_1 + 0x490) = 0x4157;
  *(int *)(param_1 + 0x48c) = iVar2;
  *(int *)(param_1 + 0x494) = param_2[4];
  if (*param_2 == 2) {
    if ((*(char *)(param_1 + 0x480) == '\0') || (*(char *)(param_1 + 0x481) == '\0')) {
      iVar2 = -0x16;
LAB_001156c4:
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011e77c,lVar4,"aw882xx_dev_algo_auth_set");
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11564c);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(param_1 + 0x4c0))
                        (*(undefined8 *)(param_1 + 0x80),*(char *)(param_1 + 0x480),param_2[2]);
      if (iVar2 < 0) goto LAB_001156c4;
      if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11567c);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(param_1 + 0x4c8))
                        (*(undefined8 *)(param_1 + 0x80),*(undefined1 *)(param_1 + 0x481),&local_2c)
      ;
      if (iVar2 < 0) goto LAB_001156c4;
    }
    iVar3 = local_2c;
  }
  else {
    if (*param_2 != 1) {
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011f00f,lVar4,"aw882xx_dev_algo_auth_set");
      iVar2 = -0x16;
      goto LAB_001156f0;
    }
    iVar2 = 0;
    iVar3 = param_2[1];
  }
  *(int *)(param_1 + 0x488) = iVar3;
LAB_001156f0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_dev_get_cali_re @ 00115724 size=28
// signature: undefined aw882xx_dev_get_cali_re(void)
// callers: [dsp_re_show]
//------------------------------------------------------------

void aw882xx_dev_get_cali_re(void)

{
  aw882xx_dsp_read_cali_re();
  return;
}



//------------------------------------------------------------
// aw882xx_dev_init_cali_re @ 00115744 size=288
// signature: undefined aw882xx_dev_init_cali_re(void)
// callers: [aw882xx_startup, aw882xx_codec_probe]
//------------------------------------------------------------

undefined8 aw882xx_dev_init_cali_re(long param_1)

{
  int iVar1;
  long lVar2;
  
  if (*(char *)(param_1 + 0x291) == '\0') {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001226aa,lVar2,"aw882xx_dev_init_cali_re");
  }
  else if (*(int *)(param_1 + 0x294) == 0) {
    iVar1 = aw882xx_cali_read_re_from_nvram(param_1 + 0x294,*(undefined4 *)(param_1 + 0x3c));
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011dff1,lVar2,"aw882xx_dev_init_cali_re");
      *(undefined4 *)(param_1 + 0x294) = 0;
      *(undefined1 *)(param_1 + 0x2a0) = 0;
      return 0;
    }
    if ((*(uint *)(param_1 + 0x294) < *(uint *)(param_1 + 0x48)) ||
       (*(uint *)(param_1 + 0x44) < *(uint *)(param_1 + 0x294))) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_001215bf,lVar2,"aw882xx_dev_init_cali_re");
      *(undefined4 *)(param_1 + 0x294) = 0;
      if (*(char *)(param_1 + 0x2a1) == '\0') {
        return 0xffffffea;
      }
      *(undefined1 *)(param_1 + 0x2a0) = 0xff;
      return 0xffffffea;
    }
    if (*(char *)(param_1 + 0x2a1) != '\0') {
      *(undefined1 *)(param_1 + 0x2a0) = 1;
      return 0;
    }
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_dc_status @ 00115868 size=28
// signature: undefined aw882xx_dev_dc_status(void)
// callers: [aw882xx_dc_prot_work]
//------------------------------------------------------------

void aw882xx_dev_dc_status(void)

{
  aw882xx_dsp_get_dc_status();
  return;
}



//------------------------------------------------------------
// aw882xx_dev_iv_forbidden_output @ 00115888 size=404
// signature: undefined aw882xx_dev_iv_forbidden_output(void)
// callers: [aw_cali_svc_cali_re, aw882xx_iv_output_set, aw_cali_svc_cali_f0, aw_cali_svc_cali_f0_q, aw_cali_svc_dev_cali_mode_en]
//------------------------------------------------------------

void aw882xx_dev_iv_forbidden_output(long param_1,uint param_2)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0x440) != 0xff) {
    lVar2 = 0x448;
    if ((param_2 & 1) == 0) {
      lVar2 = 0x44c;
    }
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x822a,0x115910);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(int *)(param_1 + 0x440),
               *(undefined4 *)(param_1 + 0x444),*(undefined4 *)(param_1 + lVar2));
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x438),param_2 & 1);
  }
  if (*(int *)(param_1 + 0x458) != 0xff) {
    lVar2 = 0x460;
    if ((param_2 & 1) == 0) {
      lVar2 = 0x464;
    }
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x11597c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(int *)(param_1 + 0x458),
               *(undefined4 *)(param_1 + 0x45c),*(undefined4 *)(param_1 + lVar2));
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x450),param_2 & 1);
  }
  if (*(int *)(param_1 + 0x470) != 0xff) {
    lVar2 = 0x478;
    if ((param_2 & 1) == 0) {
      lVar2 = 0x47c;
    }
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x1159e8);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))
              (*(undefined8 *)(param_1 + 0x80),*(int *)(param_1 + 0x470),
               *(undefined4 *)(param_1 + 0x474),*(undefined4 *)(param_1 + lVar2));
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ebfe,lVar2,"aw_dev_switch",*(undefined8 *)(param_1 + 0x468),param_2 & 1);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_status @ 00115a20 size=8
// signature: undefined aw882xx_dev_status(void)
// callers: [aw882xx_dc_prot_work]
//------------------------------------------------------------

undefined4 aw882xx_dev_status(undefined4 *param_1)

{
  return *param_1;
}



//------------------------------------------------------------
// aw882xx_dev_get_int_status @ 00115a2c size=204
// signature: undefined aw882xx_dev_get_int_status(void)
// callers: []
//------------------------------------------------------------

int aw882xx_dev_get_int_status(long param_1,undefined2 *param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_3c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115a84);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1 + 0x4c8))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x134),&local_3c);
  if (iVar2 < 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011f319,lVar3,"aw882xx_dev_get_int_status",iVar2);
  }
  else {
    *param_2 = (short)local_3c;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_dev_irq_reinit @ 00115afc size=36
// signature: undefined aw882xx_dev_irq_reinit(void)
// callers: []
//------------------------------------------------------------

int aw882xx_dev_irq_reinit(void)

{
  int iVar1;
  
  iVar1 = aw_dev_reg_fw_update();
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dev_get_fade_vol_step @ 00115b24 size=8
// signature: undefined aw882xx_dev_get_fade_vol_step(void)
// callers: [fade_step_show]
//------------------------------------------------------------

undefined4 aw882xx_dev_get_fade_vol_step(long param_1)

{
  return *(undefined4 *)(param_1 + 0x40);
}



//------------------------------------------------------------
// aw882xx_dev_set_fade_vol_step @ 00115b30 size=8
// signature: undefined aw882xx_dev_set_fade_vol_step(void)
// callers: [fade_step_store]
//------------------------------------------------------------

void aw882xx_dev_set_fade_vol_step(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x40) = param_2;
  return;
}



//------------------------------------------------------------
// aw882xx_dev_get_fade_time @ 00115b3c size=36
// signature: undefined aw882xx_dev_get_fade_time(void)
// callers: [aw882xx_get_fade_in_time, aw882xx_get_fade_out_time]
//------------------------------------------------------------

void aw882xx_dev_get_fade_time(undefined4 *param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = &g_fade_in_time;
  if ((param_2 & 1) == 0) {
    puVar1 = &g_fade_out_time;
  }
  *param_1 = *puVar1;
  return;
}



//------------------------------------------------------------
// aw882xx_dev_set_fade_time @ 00115b64 size=32
// signature: undefined aw882xx_dev_set_fade_time(void)
// callers: [aw882xx_set_fade_in_time, aw882xx_set_fade_out_time]
//------------------------------------------------------------

void aw882xx_dev_set_fade_time(undefined4 param_1,uint param_2)

{
  undefined4 *puVar1;
  
  puVar1 = &g_fade_in_time;
  if ((param_2 & 1) == 0) {
    puVar1 = &g_fade_out_time;
  }
  *puVar1 = param_1;
  return;
}



//------------------------------------------------------------
// aw882xx_dev_monitor_hal_get_time @ 00115b88 size=32
// signature: undefined aw882xx_dev_monitor_hal_get_time(void)
// callers: [aw882xx_hal_get_monitor_time]
//------------------------------------------------------------

void aw882xx_dev_monitor_hal_get_time(long param_1)

{
  aw882xx_monitor_hal_get_time(param_1 + 0x2a8);
  return;
}



//------------------------------------------------------------
// aw882xx_dev_monitor_hal_work @ 00115bac size=32
// signature: undefined aw882xx_dev_monitor_hal_work(void)
// callers: [aw882xx_hal_monitor_work_get]
//------------------------------------------------------------

void aw882xx_dev_monitor_hal_work(long param_1)

{
  aw882xx_monitor_hal_work(param_1 + 0x2a8);
  return;
}



//------------------------------------------------------------
// aw882xx_dev_deinit @ 00115bd0 size=60
// signature: undefined aw882xx_dev_deinit(void)
// callers: [aw882xx_codec_remove]
//------------------------------------------------------------

void aw882xx_dev_deinit(long param_1)

{
  if ((param_1 != 0) && (*(long *)(param_1 + 0x288) != 0)) {
    kfree();
    *(undefined8 *)(param_1 + 0x288) = 0;
    *(undefined4 *)(param_1 + 0x278) = 0;
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_init @ 00115c10 size=468
// signature: undefined aw882xx_dev_init(void)
// callers: [aw882xx_request_firmware]
//------------------------------------------------------------

undefined8 aw882xx_dev_init(undefined4 *param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (param_2 == 0) {
    lVar4 = (*(long **)(param_1 + 0x1e))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x1e);
    }
    _printk(&DAT_001201f5,lVar4,"aw882xx_dev_init");
    uVar3 = 0xfffffff4;
  }
  else {
    iVar2 = aw882xx_dev_parse_acf(param_1);
    if (iVar2 == 0) {
      if (*(int *)(*(code **)(param_1 + 0x130) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115c88);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x130))(*(undefined8 *)(param_1 + 0x20),param_1[0xf2],param_1[0xf3]);
      lVar4 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_00122090,lVar4,"aw_dev_soft_reset");
      if (param_1[0x34] != 0xff) {
        if (*(int *)(*(code **)(param_1 + 0x134) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115db0);
          (*pcVar1)();
        }
        (**(code **)(param_1 + 0x134))
                  (*(undefined8 *)(param_1 + 0x20),param_1[0x34],param_1[0x35],param_1[0x36]);
        lVar4 = (*(long **)(param_1 + 0x1e))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + 0x1e);
        }
        _printk(&DAT_0011ebfe,lVar4,"aw_dev_switch",*(undefined8 *)(param_1 + 0x32),1);
      }
      *(undefined2 *)(param_1 + 0xe) = 0;
      uVar3 = aw_dev_reg_fw_update(param_1);
      if (-1 < (int)uVar3) {
        pcVar1 = *(code **)(param_1 + 0x13e);
        if (pcVar1 != (code *)0x0) {
          if (*(int *)(pcVar1 + -4) != -0x1fe40f29) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115cf0);
            (*pcVar1)();
          }
          uVar3 = (*pcVar1)(param_1);
          if ((int)uVar3 != 0) {
            return uVar3;
          }
        }
        *param_1 = 1;
        aw882xx_device_stop(param_1);
        param_1[0x15] = 0;
        param_1[0x19] = 0;
        lVar4 = (*(long **)(param_1 + 0x1e))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + 0x1e);
        }
        _printk(&DAT_0011e3f7,lVar4,"aw882xx_dev_init");
        uVar3 = 0;
      }
    }
    else {
      if ((param_1 != (undefined4 *)0x0) && (*(long *)(param_1 + 0xa2) != 0)) {
        kfree();
        *(undefined8 *)(param_1 + 0xa2) = 0;
        param_1[0x9e] = 0;
      }
      lVar4 = (*(long **)(param_1 + 0x1e))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x1e);
      }
      _printk(&DAT_001226db,lVar4,"aw882xx_dev_init");
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// aw_dev_parse_fade_flag_dt @ 00115de8 size=200
// signature: undefined aw_dev_parse_fade_flag_dt(void)
// callers: []
//------------------------------------------------------------

void aw_dev_parse_fade_flag_dt(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"fade-flag",&local_2c,1,0);
  if (iVar1 < 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120217,lVar2,"aw_dev_parse_fade_flag_dt");
  }
  *(undefined4 *)(param_1 + 0x18) = local_2c;
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0012336b,lVar2,"aw_dev_parse_fade_flag_dt");
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_probe @ 00115eb4 size=776
// signature: undefined aw882xx_dev_probe(void)
// callers: [aw882xx_init]
//------------------------------------------------------------

void aw882xx_dev_probe(long param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined **ppuVar8;
  uint local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  puVar1 = (undefined *)(param_1 + 0x508);
  local_38 = *(long *)(lVar7 + 0x638);
  *(undefined **)(param_1 + 0x508) = puVar1;
  *(undefined **)(param_1 + 0x510) = puVar1;
  local_3c = 0;
  iVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"sound-channel",&local_3c,1,
                     0);
  if (iVar4 < 0) {
    local_3c = 0;
    lVar7 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d13b,lVar7,"aw_dev_parse_sound_channel_dt");
  }
  lVar7 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar7 == 0) {
    lVar7 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e81b,lVar7,"aw_dev_parse_sound_channel_dt",local_3c);
  if (7 < local_3c) {
    local_3c = 0;
  }
  if (*(int *)(*(code **)(param_1 + 0x4b8) + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x115f8c);
    (*pcVar3)();
  }
  iVar4 = (**(code **)(param_1 + 0x4b8))();
  if (0 < iVar4) {
    ppuVar8 = (undefined **)g_dev_list;
    if ((undefined **)g_dev_list == &g_dev_list) {
      lVar7 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar7 == 0) {
        lVar7 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011eb45,lVar7,"aw_dev_parse_sound_channel_dt");
LAB_00116138:
      lVar7 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar7 == 0) {
        lVar7 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_001239e4,lVar7,"aw_dev_parse_dt");
      uVar6 = 0xffffffea;
      goto LAB_00116160;
    }
    do {
      if (*(uint *)((long)ppuVar8 + -0x4cc) == local_3c) {
        lVar7 = *(long *)((long)ppuVar8[-0x92] + 0x70);
        if (lVar7 == 0) {
          lVar7 = *(long *)ppuVar8[-0x92];
        }
        _printk(&DAT_0011d89d,lVar7,"aw_dev_parse_sound_channel_dt");
        goto LAB_00116138;
      }
      ppuVar8 = (undefined **)*ppuVar8;
    } while (ppuVar8 != &g_dev_list);
  }
  *(uint *)(param_1 + 0x3c) = local_3c;
  aw882xx_dsp_parse_topo_id_dt(param_1);
  aw882xx_dsp_parse_port_id_dt(param_1);
  local_3c = 0;
  iVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"fade-flag",&local_3c,1,0);
  if (iVar4 < 0) {
    lVar7 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120217,lVar7,"aw_dev_parse_fade_flag_dt");
  }
  *(uint *)(param_1 + 0x18) = local_3c;
  lVar7 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar7 == 0) {
    lVar7 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0012336b,lVar7,"aw_dev_parse_fade_flag_dt");
  if ((*(int *)(param_1 + 0x3c) == 0) && (iVar4 = misc_register(misc_algo_auth), iVar4 != 0)) {
    lVar7 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d05a,lVar7,"aw_algo_auth_misc_init",iVar4);
  }
  uVar6 = aw882xx_cali_init(param_1 + 0x290);
  if ((int)uVar6 == 0) {
    aw882xx_monitor_init(param_1 + 0x2a8);
    uVar6 = aw882xx_spin_init(param_1 + 0x3d0);
    if ((int)uVar6 == 0) {
      mutex_lock(g_dev_lock);
      puVar2 = g_dev_list;
      uVar5 = __list_add_valid(puVar1,&g_dev_list,g_dev_list);
      if ((uVar5 & 1) != 0) {
        *(undefined **)(puVar2 + 8) = puVar1;
        *(undefined **)(param_1 + 0x508) = puVar2;
        *(undefined ***)(param_1 + 0x510) = &g_dev_list;
        g_dev_list = puVar1;
      }
      mutex_unlock(g_dev_lock);
      uVar6 = 0;
    }
  }
LAB_00116160:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// aw882xx_dev_remove @ 001161c0 size=76
// signature: undefined aw882xx_dev_remove(void)
// callers: [aw882xx_i2c_remove]
//------------------------------------------------------------

undefined8 aw882xx_dev_remove(long param_1)

{
  aw882xx_monitor_deinit(param_1 + 0x2a8);
  aw882xx_cali_deinit(param_1 + 0x290);
  if (*(int *)(param_1 + 0x3c) == 0) {
    misc_deregister(misc_algo_auth);
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_dev_check_ef_lock @ 00116210 size=232
// signature: undefined aw882xx_dev_check_ef_lock(void)
// callers: [aw882xx_init]
//------------------------------------------------------------

undefined8 aw882xx_dev_check_ef_lock(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  if (*(int *)(param_1 + 0xe0) != 0) {
    uVar3 = 0;
    puVar4 = (undefined4 *)(param_1 + 0xe4);
    do {
      if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x116288);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),*puVar4,&local_4c);
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_00121a27,lVar2,"aw882xx_dev_check_ef_lock",*puVar4,local_4c);
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 3;
    } while (uVar3 < *(uint *)(param_1 + 0xe0));
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw_dev_mode1_pll_check @ 001162f8 size=264
// signature: undefined aw_dev_mode1_pll_check(void)
// callers: [aw882xx_device_start]
//------------------------------------------------------------

void aw_dev_mode1_pll_check(long param_1)

{
  code *pcVar1;
  bool bVar2;
  undefined8 uVar3;
  long lVar4;
  uint uVar5;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  uVar5 = 0;
  while( true ) {
    if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11634c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4c8))
              (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x218),&local_2c);
    if ((*(uint *)(param_1 + 0x228) & (local_2c ^ 0xffffffff)) == 0) break;
    usleep_range_state(2000,0x7da,2);
    bVar2 = 8 < uVar5;
    uVar5 = uVar5 + 1;
    if (bVar2) {
      lVar4 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011e7aa,lVar4,"aw_dev_mode1_pll_check");
      uVar3 = 0xffffffff;
LAB_001163d4:
      lVar4 = sp_el0;
      if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar3);
      }
      return;
    }
  }
  lVar4 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar4 == 0) {
    lVar4 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011df48,lVar4,"aw_dev_mode1_pll_check");
  uVar3 = 0;
  goto LAB_001163d4;
}



//------------------------------------------------------------
// aw_algo_auth_misc_unlocked_ioctl @ 00116404 size=88
// signature: undefined aw_algo_auth_misc_unlocked_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_algo_auth_misc_unlocked_ioctl(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 & 0xff00) == 0x7700) {
    iVar1 = aw_algo_auth_misc_ops(*(undefined8 *)(param_1 + 0xd8));
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xffffffffffffffea;
    }
  }
  else {
    _printk(&DAT_00121d6e,"aw_algo_auth_misc_unlocked_ioctl");
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_algo_auth_misc_compat_ioctl @ 00116460 size=88
// signature: undefined aw_algo_auth_misc_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_algo_auth_misc_compat_ioctl(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((param_2 & 0xff00) == 0x7700) {
    iVar1 = aw_algo_auth_misc_ops(*(undefined8 *)(param_1 + 0xd8));
    uVar2 = 0;
    if (iVar1 != 0) {
      uVar2 = 0xffffffffffffffea;
    }
  }
  else {
    _printk(&DAT_00121d6e,"aw_algo_auth_misc_compat_ioctl");
    uVar2 = 0xffffffffffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_algo_auth_misc_open @ 001164bc size=164
// signature: undefined aw_algo_auth_misc_open(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_algo_auth_misc_open(undefined8 param_1,long param_2)

{
  undefined **ppuVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  
  ppuVar1 = (undefined **)g_dev_list;
  if ((undefined **)g_dev_list == &g_dev_list) {
    _printk(&DAT_0011e6e7,"aw_algo_auth_misc_open");
    uVar2 = 0xffffffea;
    *(undefined8 *)(param_2 + 0xd8) = 0;
  }
  else {
    do {
      ppuVar3 = ppuVar1;
      if (*(int *)((long)ppuVar3 + -0x4cc) == 0) break;
      ppuVar1 = (undefined **)*ppuVar3;
    } while ((undefined **)*ppuVar3 != &g_dev_list);
    if (ppuVar3 + -0xa1 == (undefined **)0x0) {
      _printk(&DAT_001201d0,"aw_algo_auth_misc_open",0);
      uVar2 = 0xffffffea;
    }
    else {
      uVar2 = 0;
      *(undefined ***)(param_2 + 0xd8) = ppuVar3 + -0xa1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_algo_auth_misc_release @ 00116564 size=12
// signature: undefined aw_algo_auth_misc_release(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_algo_auth_misc_release(undefined8 param_1,long param_2)

{
  *(undefined8 *)(param_2 + 0xd8) = 0;
  return 0;
}



//------------------------------------------------------------
// aw_algo_auth_misc_ops @ 00116570 size=720
// signature: undefined aw_algo_auth_misc_ops(void)
// callers: [aw_algo_auth_misc_unlocked_ioctl, aw_algo_auth_misc_compat_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 aw_algo_auth_misc_ops(long param_1,int param_2,ulong param_3)

{
  ulong uVar1;
  size_t __n;
  long lVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 auStack_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (param_2 == -0x3feb88ff) {
    local_40 = *(undefined4 *)(param_1 + 0x484);
    puVar4 = (undefined8 *)sp_el0;
    local_34 = *(undefined4 *)(param_1 + 0x490);
    local_30 = *(undefined4 *)(param_1 + 0x494);
    uStack_3c = (undefined4)*(undefined8 *)(param_1 + 0x488);
    uStack_38 = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x488) >> 0x20);
    if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
       (uVar5 = param_3, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
      uVar5 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar5 < 0x7fffffffed) {
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
      lVar2 = __arch_copy_to_user(puVar4,param_3 & 0xff7fffffffffffff,&local_40,0x14);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar5 = daif;
        if ((uVar5 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar5;
      }
      uVar3 = 0;
      if (lVar2 != 0) {
        uVar3 = 0xfffffff2;
      }
    }
    else {
      uVar3 = 0xfffffff2;
    }
    goto LAB_00116794;
  }
  if (param_2 != -0x3feb88fe) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001230e3,lVar2,"aw_algo_auth_misc_ops",param_2);
    uVar3 = 0xffffffea;
    goto LAB_00116794;
  }
  puVar4 = (undefined8 *)sp_el0;
  local_30 = 0;
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  local_34 = 0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_3, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_3 & (long)(param_3 << 8) >> 8;
  }
  if (uVar5 < 0x7fffffffed) {
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
    __n = __arch_copy_from_user(puVar4,&local_40,param_3 & 0xff7fffffffffffff,0x14);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    if (__n != 0) goto LAB_001167f0;
    uVar3 = 0;
  }
  else {
    __n = 0x14;
LAB_001167f0:
    memset(auStack_2c + -__n,0,__n);
    uVar3 = 0xfffffff2;
  }
  aw882xx_dev_algo_auth_set(param_1,&local_40);
LAB_00116794:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// aw882xx_dsp_read_dsp_msg @ 001168c4 size=204
// signature: undefined aw882xx_dsp_read_dsp_msg(void)
// callers: [aw882xx_dsp_algo_ver, aw882xx_dsp_read_cali_re, aw882xx_dsp_read_f0, aw882xx_dsp_read_cali_cfg, aw882xx_dsp_read_st, aw882xx_dsp_read_f0_q, aw882xx_dsp_read_r0, aw882xx_dsp_read_te, aw_cali_misc_read_dsp, aw882xx_dsp_read_cali_data, aw882xx_dsp_get_dc_status, aw882xx_dsp_read_vmax]
//------------------------------------------------------------

undefined8
aw882xx_dsp_read_dsp_msg(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  undefined8 uVar1;
  
  if (*(uint *)(param_1 + 0x3c) < 4) {
    mutex_lock(g_aw_dsp_msg_lock);
    if (g_rx_topo_id != 0) {
      _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
    }
    mutex_lock(g_aw_dsp_lock);
    mutex_unlock(g_aw_dsp_lock);
    if (g_rx_topo_id != 0) {
      _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
    }
    mutex_lock(g_aw_dsp_lock);
    mutex_unlock(g_aw_dsp_lock);
    mutex_unlock(g_aw_dsp_msg_lock);
    uVar1 = 0;
  }
  else {
    uVar1 = aw_read_msg_from_dsp_v_1_0_0_0(param_3,param_4);
  }
  return uVar1;
}



//------------------------------------------------------------
// aw_read_msg_from_dsp_v_1_0_0_0 @ 00116990 size=572
// signature: undefined aw_read_msg_from_dsp_v_1_0_0_0(void)
// callers: [aw882xx_dsp_read_run_state_avg, aw882xx_dsp_read_vol_offset, aw882xx_dsp_read_dsp_msg]
//------------------------------------------------------------

undefined8 aw_read_msg_from_dsp_v_1_0_0_0(void *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  code *pcVar6;
  int *piVar7;
  uint uVar8;
  ulong uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  int iVar13;
  undefined8 uVar14;
  ulong __n;
  
  __n = (ulong)param_2;
  mutex_lock(g_aw_dsp_msg_lock);
  if (g_rx_topo_id != 0) {
    _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
  }
  mutex_lock(g_aw_dsp_lock);
  mutex_unlock(g_aw_dsp_lock);
  uVar3 = __n + 0x28;
  piVar7 = (int *)__kmalloc(uVar3,0xdc0);
  if (piVar7 == (int *)0x0) {
    uVar14 = 0xfffffff4;
    goto LAB_00116b14;
  }
  if (g_rx_topo_id != 0) {
    _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
  }
  mutex_lock(g_aw_dsp_lock);
  mutex_unlock(g_aw_dsp_lock);
  if (piVar7[2] == 2) {
    if ((uint)uVar3 < 5) {
      iVar11 = 0;
    }
    else {
      uVar9 = __n + 0x24;
      uVar12 = (ulong)(param_2 + 0x23);
      uVar5 = uVar9;
      if (uVar12 <= uVar9) {
        uVar5 = uVar12;
      }
      uVar8 = (int)uVar5 + 1;
      if (uVar8 < 3) {
LAB_00116a64:
        iVar11 = 0;
        uVar8 = 4;
      }
      else {
        if (uVar12 <= uVar9) {
          uVar9 = uVar12;
        }
        if (0x7ffffffb < (uint)uVar9) goto LAB_00116a64;
        uVar4 = 2;
        if ((uVar8 & 1) != 0) {
          uVar4 = uVar8 & 1;
        }
        iVar10 = 0;
        iVar11 = 0;
        uVar8 = (uVar8 - uVar4) + 4;
        iVar13 = -1;
        do {
          iVar1 = iVar13 + 5;
          iVar2 = iVar13 + 6;
          iVar13 = iVar13 + 2;
          iVar10 = iVar10 + (uint)*(byte *)((long)piVar7 + (long)iVar1);
          iVar11 = iVar11 + (uint)*(byte *)((long)piVar7 + (long)iVar2);
        } while ((int)uVar5 - uVar4 != iVar13);
        iVar11 = iVar11 + iVar10;
      }
      do {
        uVar9 = (ulong)(int)uVar8;
        if (uVar3 <= uVar9) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(1,0x116bcc);
          (*pcVar6)();
        }
        uVar8 = uVar8 + 1;
        iVar11 = iVar11 + (uint)*(byte *)((long)piVar7 + uVar9);
      } while ((uint)uVar3 != uVar8);
    }
    if (iVar11 == *piVar7) {
      memcpy(param_1,piVar7 + 10,__n);
      uVar14 = 0;
    }
    else {
      _printk(&DAT_00120336,"aw_read_msg_from_dsp_v_1_0_0_0");
      _printk(&DAT_0011fcdf,"aw_read_msg_from_dsp_v_1_0_0_0",*piVar7,iVar11);
      uVar14 = 0xffffffea;
    }
  }
  else {
    _printk(&DAT_0011ec54,"aw_read_msg_from_dsp_v_1_0_0_0");
    uVar14 = 0xffffffea;
  }
  kfree(piVar7);
LAB_00116b14:
  mutex_unlock(g_aw_dsp_msg_lock);
  return uVar14;
}



//------------------------------------------------------------
// aw882xx_dsp_write_dsp_msg @ 00116bd0 size=212
// signature: undefined aw882xx_dsp_write_dsp_msg(void)
// callers: [aw882xx_dsp_cali_en, aw_cali_misc_write_dsp, aw882xx_dsp_write_cali_re, aw882xx_dsp_noise_en, aw882xx_dsp_write_vmax, aw882xx_dsp_hmute_en, aw882xx_dsp_set_mixer_en, aw882xx_dsp_write_cali_cfg]
//------------------------------------------------------------

undefined8 aw882xx_dsp_write_dsp_msg(long param_1,undefined4 param_2,void *param_3,uint param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 4) {
    puVar1 = (undefined4 *)__kmalloc((ulong)param_4 + 0x18,0xdc0);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      *puVar1 = 0;
      puVar1[1] = param_2;
      puVar1[2] = 1;
      memcpy(puVar1 + 6,param_3,(ulong)param_4);
      if (g_rx_topo_id != 0) {
        _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
      }
      mutex_lock(g_aw_dsp_lock);
      mutex_unlock(g_aw_dsp_lock);
      kfree(puVar1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = aw_write_msg_to_dsp_v_1_0_0_0(param_1,param_2,param_3);
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_write_msg_to_dsp_v_1_0_0_0 @ 00116ca4 size=476
// signature: undefined aw_write_msg_to_dsp_v_1_0_0_0(void)
// callers: [aw882xx_dsp_write_ramp_enable, aw882xx_dsp_write_volume, aw882xx_dsp_write_ramp_params, aw882xx_dsp_write_vol_offset, aw882xx_dsp_write_dsp_msg]
//------------------------------------------------------------

undefined8 aw_write_msg_to_dsp_v_1_0_0_0(long param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  ulong uVar5;
  code *pcVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  ulong uVar11;
  int iVar12;
  undefined8 uVar13;
  ulong uVar14;
  
  mutex_lock(g_aw_dsp_msg_lock);
  uVar14 = (ulong)param_4;
  uVar3 = uVar14 + 0x28;
  piVar7 = (int *)__kmalloc(uVar3,0xdc0);
  if (piVar7 == (int *)0x0) {
    _printk(&DAT_0011e89f,"aw_write_msg_to_dsp_v_1_0_0_0");
    uVar13 = 0xfffffff4;
    goto LAB_00116e18;
  }
  iVar10 = *(int *)(param_1 + 0x3c);
  piVar7[3] = param_2;
  piVar7[1] = 0x10000000;
  piVar7[2] = 1;
  piVar7[4] = iVar10;
  piVar7[5] = 1;
  piVar7[6] = param_4;
  memcpy(piVar7 + 10,param_3,uVar14);
  if ((uint)uVar3 < 5) {
    iVar10 = 0;
  }
  else {
    uVar14 = uVar14 + 0x24;
    uVar11 = (ulong)(param_4 + 0x23);
    uVar5 = uVar14;
    if (uVar11 <= uVar14) {
      uVar5 = uVar11;
    }
    uVar8 = (int)uVar5 + 1;
    if (uVar8 < 3) {
LAB_00116d64:
      iVar10 = 0;
      uVar8 = 4;
    }
    else {
      if (uVar11 <= uVar14) {
        uVar14 = uVar11;
      }
      if (0x7ffffffb < (uint)uVar14) goto LAB_00116d64;
      uVar4 = 2;
      if ((uVar8 & 1) != 0) {
        uVar4 = uVar8 & 1;
      }
      iVar9 = 0;
      iVar10 = 0;
      uVar8 = (uVar8 - uVar4) + 4;
      iVar12 = -1;
      do {
        iVar1 = iVar12 + 5;
        iVar2 = iVar12 + 6;
        iVar12 = iVar12 + 2;
        iVar9 = iVar9 + (uint)*(byte *)((long)piVar7 + (long)iVar1);
        iVar10 = iVar10 + (uint)*(byte *)((long)piVar7 + (long)iVar2);
      } while ((int)uVar5 - uVar4 != iVar12);
      iVar10 = iVar10 + iVar9;
    }
    do {
      uVar14 = (ulong)(int)uVar8;
      if (uVar3 <= uVar14) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(1,0x116e80);
        (*pcVar6)();
      }
      uVar8 = uVar8 + 1;
      iVar10 = iVar10 + (uint)*(byte *)((long)piVar7 + uVar14);
    } while ((uint)uVar3 != uVar8);
  }
  *piVar7 = iVar10;
  if (g_rx_topo_id != 0) {
    _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
  }
  mutex_lock(g_aw_dsp_lock);
  mutex_unlock(g_aw_dsp_lock);
  kfree(piVar7);
  uVar13 = 0;
LAB_00116e18:
  mutex_unlock(g_aw_dsp_msg_lock);
  return uVar13;
}



//------------------------------------------------------------
// aw882xx_dsp_set_afe_module_en @ 00116e84 size=68
// signature: undefined aw882xx_dsp_set_afe_module_en(void)
// callers: [aw882xx_set_tx_en, aw882xx_set_rx_en]
//------------------------------------------------------------

undefined8 aw882xx_dsp_set_afe_module_en(uint param_1)

{
  if (param_1 < 2) {
    return 0;
  }
  _printk(&DAT_0011d174,"aw882xx_dsp_set_afe_module_en",param_1);
  return 0xffffffea;
}



//------------------------------------------------------------
// aw882xx_dsp_get_afe_module_en @ 00116ecc size=168
// signature: undefined aw882xx_dsp_get_afe_module_en(void)
// callers: [aw882xx_get_tx_en, aw882xx_get_rx_en]
//------------------------------------------------------------

undefined8 aw882xx_dsp_get_afe_module_en(int param_1)

{
  undefined *puVar1;
  
  if (param_1 == 1) {
    if (g_tx_topo_id == 0) goto LAB_00116f10;
    puVar1 = &DAT_00120314;
  }
  else {
    if (param_1 != 0) {
      _printk(&DAT_0011d174,"aw882xx_dsp_get_afe_module_en",param_1);
      return 0xffffffea;
    }
    if (g_rx_topo_id == 0) goto LAB_00116f10;
    puVar1 = &DAT_0011f7af;
  }
  _printk(puVar1,"aw_check_dsp_ready",0);
LAB_00116f10:
  mutex_lock(g_aw_dsp_lock);
  mutex_unlock(g_aw_dsp_lock);
  return 0;
}



//------------------------------------------------------------
// aw882xx_dsp_read_te @ 00116f78 size=196
// signature: undefined aw882xx_dsp_read_te(void)
// callers: [aw_cali_svc_get_devs_te]
//------------------------------------------------------------

int aw882xx_dsp_read_te(long param_1,undefined4 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  local_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  iVar2 = aw882xx_dsp_read_dsp_msg(param_1,param_2,&local_58,0x20);
  if (iVar2 == 0) {
    puVar1 = &uStack_50;
    if ((*(uint *)(param_1 + 0x3c) & 1) != 0) {
      puVar1 = &local_40;
    }
    *param_2 = *(undefined4 *)puVar1;
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001210c0,lVar3,"aw882xx_dsp_read_te");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_dsp_read_st @ 00117040 size=236
// signature: undefined aw882xx_dsp_read_st(void)
// callers: [aw_dev_monitor_hw_status, aw_cali_svc_get_devs_st]
//------------------------------------------------------------

int aw882xx_dsp_read_st(long param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  int local_68 [8];
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_68[4] = 0;
  local_68[5] = 0;
  local_68[6] = 0;
  local_68[7] = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  iVar4 = aw882xx_dsp_read_dsp_msg(param_1,param_2,local_68,0x20);
  if (iVar4 == 0) {
    bVar3 = (*(uint *)(param_1 + 0x3c) & 1) != 0;
    piVar1 = local_68;
    if (bVar3) {
      piVar1 = local_68 + 4;
    }
    lVar5 = 8;
    if (bVar3) {
      lVar5 = 0x18;
    }
    uVar2 = *(undefined4 *)((long)local_68 + lVar5);
    *param_2 = *piVar1 * 1000 >> 0xc;
    *param_3 = uVar2;
  }
  else {
    lVar5 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0012339e,lVar5,"aw882xx_dsp_read_st");
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// aw882xx_dsp_read_spin @ 00117130 size=108
// signature: undefined aw882xx_dsp_read_spin(void)
// callers: [aw882xx_spin_value_get]
//------------------------------------------------------------

undefined8 aw882xx_dsp_read_spin(undefined4 *param_1)

{
  if (g_rx_topo_id != 0) {
    _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
  }
  mutex_lock(g_aw_dsp_lock);
  mutex_unlock(g_aw_dsp_lock);
  *param_1 = 0;
  return 0;
}



//------------------------------------------------------------
// aw882xx_dsp_write_spin @ 001171a0 size=140
// signature: undefined aw882xx_dsp_write_spin(void)
// callers: [aw882xx_spin_value_set, aw882xx_spin_set_record_val]
//------------------------------------------------------------

undefined8 aw882xx_dsp_write_spin(int param_1)

{
  undefined8 uVar1;
  
  if (param_1 < 4) {
    if (g_rx_topo_id != 0) {
      _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
    }
    mutex_lock(g_aw_dsp_lock);
    mutex_unlock(g_aw_dsp_lock);
    uVar1 = 0;
  }
  else {
    _printk(&DAT_0011fc58,"aw882xx_dsp_write_spin",param_1);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_r0 @ 00117230 size=244
// signature: undefined aw882xx_dsp_read_r0(void)
// callers: [aw_cali_svc_get_devs_r0, aw_cali_svc_dev_get_re]
//------------------------------------------------------------

int aw882xx_dsp_read_r0(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,&local_50,0x18);
    if (iVar1 == 0) {
      *param_2 = (int)local_50 * 1000 >> 0xc;
    }
    else {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0012029b,lVar2,"aw882xx_dsp_read_r0");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_r0");
    iVar1 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_cali_data @ 00117328 size=160
// signature: undefined aw882xx_dsp_read_cali_data(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

int aw882xx_dsp_read_cali_data(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,param_2,param_3);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0012085b,lVar2,"aw882xx_dsp_read_cali_data");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_cali_data");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_get_dc_status @ 001173cc size=180
// signature: undefined aw882xx_dsp_get_dc_status(void)
// callers: [aw882xx_dev_dc_status]
//------------------------------------------------------------

int aw882xx_dsp_get_dc_status(long param_1,undefined8 param_2)

{
  int *piVar1;
  int iVar2;
  long lVar3;
  int local_40 [2];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40[0] = 0;
  local_40[1] = 0;
  iVar2 = aw882xx_dsp_read_dsp_msg(param_1,param_2,local_40,8);
  if (iVar2 == 0) {
    piVar1 = local_40;
    if ((*(byte *)(param_1 + 0x3c) & 1) != 0) {
      piVar1 = (int *)((ulong)local_40 | 4);
    }
    iVar2 = *piVar1;
  }
  else {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ff44,lVar3,"aw882xx_dsp_get_dc_status");
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_dsp_read_f0_q @ 00117484 size=220
// signature: undefined aw882xx_dsp_read_f0_q(void)
// callers: [aw_cali_misc_ops, aw_cali_svc_dev_get_f0_q]
//------------------------------------------------------------

int aw882xx_dsp_read_f0_q(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long lVar4;
  long local_58 [3];
  
  lVar4 = sp_el0;
  local_58[2] = *(long *)(lVar4 + 0x638);
  local_58[0] = 0;
  local_58[1] = 0;
  iVar3 = aw882xx_dsp_read_dsp_msg(param_1,param_2,local_58,0x10);
  if (iVar3 == 0) {
    lVar4 = 4;
    plVar1 = local_58;
    if ((*(uint *)(param_1 + 0x3c) & 1) != 0) {
      lVar4 = 0xc;
      plVar1 = local_58 + 1;
    }
    uVar2 = *(undefined4 *)((long)local_58 + lVar4);
    *param_2 = (int)*plVar1;
    *param_3 = uVar2;
  }
  else {
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e3d,lVar4,"aw882xx_dsp_read_f0_q");
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// aw882xx_dsp_read_f0 @ 00117564 size=160
// signature: undefined aw882xx_dsp_read_f0(void)
// callers: [aw_cali_svc_get_devs_f0, aw_cali_misc_ops, aw_cali_svc_dev_get_f0]
//------------------------------------------------------------

int aw882xx_dsp_read_f0(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,param_2,4);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_001202c3,lVar2,"aw882xx_dsp_read_f0");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_f0");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_cali_en @ 00117608 size=152
// signature: undefined aw882xx_dsp_cali_en(void)
// callers: [aw_cali_misc_ops, aw_cali_svc_cali_re, aw_cali_svc_cali_f0, aw_cali_svc_cali_f0_q, aw_cali_svc_dev_cali_mode_en]
//------------------------------------------------------------

int aw882xx_dsp_cali_en(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2;
  iVar1 = aw882xx_dsp_write_dsp_msg(param_1,1,&local_2c,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011fa9b,lVar2,"aw882xx_dsp_cali_en");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_hmute_en @ 001176a4 size=156
// signature: undefined aw882xx_dsp_hmute_en(void)
// callers: [aw_cali_misc_ops, aw_cali_svc_cali_re, aw_cali_svc_dev_cali_mode_en]
//------------------------------------------------------------

int aw882xx_dsp_hmute_en(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_2c = param_2 & 1;
  local_28 = *(long *)(lVar2 + 0x638);
  iVar1 = aw882xx_dsp_write_dsp_msg(param_1,2,&local_2c,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00121da0,lVar2,"aw882xx_dsp_hmute_en");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_cali_re @ 00117744 size=240
// signature: undefined aw882xx_dsp_read_cali_re(void)
// callers: [aw_cali_misc_ops, aw882xx_dev_get_cali_re]
//------------------------------------------------------------

int aw882xx_dsp_read_cali_re(long param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,&local_3c,4);
    if (iVar1 == 0) {
      *param_2 = local_3c * 1000 >> 0xc;
    }
    else {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_00122e63,lVar2,"aw882xx_dsp_read_cali_re");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_cali_re");
    iVar1 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_cali_re @ 00117838 size=248
// signature: undefined aw882xx_dsp_write_cali_re(void)
// callers: [aw882xx_device_start]
//------------------------------------------------------------

int aw882xx_dsp_write_cali_re(long param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = (param_2 << 0xc) / 1000;
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_write_dsp_msg
                      (param_1,*(undefined4 *)
                                (&DAT_001252bc + (long)(int)*(uint *)(param_1 + 0x3c) * 4),&local_2c
                       ,4);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011f786,lVar2,"aw882xx_dsp_write_cali_re");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_write_cali_re");
    iVar1 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_vol_offset @ 00117934 size=104
// signature: undefined aw882xx_dsp_read_vol_offset(void)
// callers: [vol_offset_show]
//------------------------------------------------------------

int aw882xx_dsp_read_vol_offset(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = aw_read_msg_from_dsp_v_1_0_0_0(param_2,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011e086,lVar2,"aw882xx_dsp_read_vol_offset",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_vol_offset @ 001179a0 size=156
// signature: undefined aw882xx_dsp_write_vol_offset(void)
// callers: [aw882xx_device_start, vol_offset_store]
//------------------------------------------------------------

int aw882xx_dsp_write_vol_offset(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2;
  iVar1 = aw_write_msg_to_dsp_v_1_0_0_0(param_1,0x1f,&local_2c,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011e0b7,lVar2,"aw882xx_dsp_write_vol_offset",iVar1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_volume @ 00117a40 size=112
// signature: undefined aw882xx_dsp_write_volume(void)
// callers: [aw882xx_algo_volume_put]
//------------------------------------------------------------

int aw882xx_dsp_write_volume(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = aw_write_msg_to_dsp_v_1_0_0_0(param_1,0x10013d54,param_2,param_3);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0012310a,lVar2,"aw882xx_dsp_write_volume",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_ramp_enable @ 00117ab4 size=160
// signature: undefined aw882xx_dsp_write_ramp_enable(void)
// callers: [aw882xx_ramp_switch_set]
//------------------------------------------------------------

int aw882xx_dsp_write_ramp_enable(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2;
  iVar1 = aw_write_msg_to_dsp_v_1_0_0_0(param_1,0x10013d56,&local_2c,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001202e5,lVar2,"aw882xx_dsp_write_ramp_enable",iVar1);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_ramp_params @ 00117b58 size=112
// signature: undefined aw882xx_dsp_write_ramp_params(void)
// callers: [aw882xx_ramp_params_put]
//------------------------------------------------------------

int aw882xx_dsp_write_ramp_params(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = aw_write_msg_to_dsp_v_1_0_0_0(param_1,0x10013d62,param_2,param_3);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122769,lVar2,"aw882xx_dsp_write_ramp_params",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_run_state_avg @ 00117bcc size=104
// signature: undefined aw882xx_dsp_read_run_state_avg(void)
// callers: [algo_state_show]
//------------------------------------------------------------

int aw882xx_dsp_read_run_state_avg(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  iVar1 = aw_read_msg_from_dsp_v_1_0_0_0(param_2,param_3);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122446,lVar2,"aw882xx_dsp_read_run_state_avg",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_params @ 00117c38 size=180
// signature: undefined aw882xx_dsp_write_params(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

undefined8 aw882xx_dsp_write_params(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    if (g_rx_topo_id != 0) {
      _printk(&DAT_0011f7af,"aw_check_dsp_ready",0);
    }
    mutex_lock(g_aw_dsp_lock);
    mutex_unlock(g_aw_dsp_lock);
    uVar1 = 0;
  }
  else {
    _printk(&DAT_00122b94,"aw_dsp_get_msg_num");
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00120885,lVar2,"aw882xx_dsp_write_params");
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_vmax @ 00117cf0 size=160
// signature: undefined aw882xx_dsp_read_vmax(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

int aw882xx_dsp_read_vmax(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,param_2,param_3);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011fcbb,lVar2,"aw882xx_dsp_read_vmax");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_vmax");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_vmax @ 00117d94 size=172
// signature: undefined aw882xx_dsp_write_vmax(void)
// callers: [aw_cali_misc_ops, aw_monitor_work_func]
//------------------------------------------------------------

int aw882xx_dsp_write_vmax(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_write_dsp_msg
                      (param_1,*(undefined4 *)
                                (&DAT_0012527c + (long)(int)*(uint *)(param_1 + 0x3c) * 4),param_2,
                       param_3);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011ff81,lVar2,"aw882xx_dsp_write_vmax");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_write_vmax");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_noise_en @ 00117e44 size=224
// signature: undefined aw882xx_dsp_noise_en(void)
// callers: [aw_cali_misc_ops, aw_cali_svc_cali_f0, aw_cali_svc_cali_f0_q, aw_cali_svc_dev_cali_mode_en]
//------------------------------------------------------------

int aw882xx_dsp_noise_en(long param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2 & 1;
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_write_dsp_msg
                      (param_1,*(undefined4 *)
                                (&DAT_001252dc + (long)(int)*(uint *)(param_1 + 0x3c) * 4),&local_2c
                       ,4);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011d1c6,lVar2,"aw882xx_dsp_noise_en");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_noise_en");
    iVar1 = -0x16;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_read_cali_cfg @ 00117f28 size=160
// signature: undefined aw882xx_dsp_read_cali_cfg(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

int aw882xx_dsp_read_cali_cfg(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_read_dsp_msg(param_1,param_2,param_2,param_3);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_00120ace,lVar2,"aw882xx_dsp_read_cali_cfg");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_read_cali_cfg");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_write_cali_cfg @ 00117fcc size=172
// signature: undefined aw882xx_dsp_write_cali_cfg(void)
// callers: [aw_cali_misc_ops]
//------------------------------------------------------------

int aw882xx_dsp_write_cali_cfg(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x3c) < 8) {
    iVar1 = aw882xx_dsp_write_dsp_msg
                      (param_1,*(undefined4 *)
                                (&DAT_0012529c + (long)(int)*(uint *)(param_1 + 0x3c) * 4),param_2,
                       param_3);
    if (iVar1 != 0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0011e428,lVar2,"aw882xx_dsp_write_cali_cfg");
    }
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122e14,lVar2,"aw882xx_dsp_write_cali_cfg");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_set_copp_module_en @ 0011807c size=72
// signature: undefined aw882xx_dsp_set_copp_module_en(void)
// callers: [aw882xx_set_copp_en]
//------------------------------------------------------------

undefined8 aw882xx_dsp_set_copp_module_en(ulong param_1)

{
  char *pcVar1;
  
  pcVar1 = "enable";
  if ((param_1 & 1) == 0) {
    pcVar1 = "disable";
  }
  _printk(&DAT_0011cd47,"aw882xx_dsp_set_copp_module_en",pcVar1);
  return 0;
}



//------------------------------------------------------------
// aw882xx_dsp_set_mixer_en @ 001180c8 size=152
// signature: undefined aw882xx_dsp_set_mixer_en(void)
// callers: [aw_reg_write_spin]
//------------------------------------------------------------

int aw882xx_dsp_set_mixer_en(long param_1,undefined4 param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = param_2;
  iVar1 = aw882xx_dsp_write_dsp_msg(param_1,0xb,&local_2c,4);
  if (iVar1 != 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00123134,lVar2,"aw882xx_dsp_set_mixer_en");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// aw882xx_dsp_algo_ver @ 00118164 size=188
// signature: undefined aw882xx_dsp_algo_ver(void)
// callers: [algo_ver_show]
//------------------------------------------------------------

ulong aw882xx_dsp_algo_ver(undefined8 param_1,char *param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined8 extraout_x1;
  ulong uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar2 = aw882xx_dsp_read_dsp_msg(param_1,param_2,&local_3c,4);
  if (((int)uVar2 < 0) || (local_3c == 0)) {
    uVar3 = aw882xx_dsp_read_dsp_msg(param_1,extraout_x1,param_2,0x50);
    uVar4 = uVar3 & 0xffffffff;
  }
  else {
    uVar4 = (ulong)uVar2;
    uVar2 = snprintf(param_2,0x50,"aw_algo_v%d.%d.%d.%d",local_3c >> 0x18,local_3c >> 0x10 & 0xff,
                     local_3c >> 8 & 0xff,local_3c & 0xff);
    uVar3 = (ulong)uVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return uVar4;
}



//------------------------------------------------------------
// aw882xx_dsp_parse_topo_id_dt @ 00118224 size=268
// signature: undefined aw882xx_dsp_parse_topo_id_dt(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

void aw882xx_dsp_parse_topo_id_dt(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-tx-topo-id",
                     &g_tx_topo_id,1,0);
  if (iVar1 < 0) {
    g_tx_topo_id = 0x1000ff00;
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011cd61,lVar2,"aw882xx_dsp_parse_topo_id_dt");
  }
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-rx-topo-id",
                     &g_rx_topo_id,1,0);
  if (iVar1 < 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    g_rx_topo_id = 0x1000ff01;
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00121df6,lVar2,"aw882xx_dsp_parse_topo_id_dt");
  }
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00121647,lVar2,"aw882xx_dsp_parse_topo_id_dt",g_tx_topo_id,g_rx_topo_id);
  return;
}



//------------------------------------------------------------
// aw882xx_dsp_parse_port_id_dt @ 00118334 size=264
// signature: undefined aw882xx_dsp_parse_port_id_dt(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

void aw882xx_dsp_parse_port_id_dt(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-tx-port-id",
                     &g_tx_port_id,1,0);
  if (iVar1 < 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    g_tx_port_id = 0x1007;
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122b5b,lVar2,"aw882xx_dsp_parse_port_id_dt");
  }
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x78) + 0x2e8),"aw-rx-port-id",
                     &g_rx_port_id,1,0);
  if (iVar1 < 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    g_rx_port_id = 0x1006;
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011cd9a,lVar2,"aw882xx_dsp_parse_port_id_dt");
  }
  lVar2 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar2 == 0) {
    lVar2 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e869,lVar2,"aw882xx_dsp_parse_port_id_dt",g_tx_port_id,g_rx_port_id);
  return;
}



//------------------------------------------------------------
// aw_dev_init_cmm @ 00118440 size=644
// signature: undefined aw_dev_init_cmm(void)
// callers: [aw882xx_init]
//------------------------------------------------------------

void aw_dev_init_cmm(long param_1)

{
  *(code **)(param_1 + 0x4d8) = aw_direct_reg_val_to_db;
  *(code **)(param_1 + 0x4e8) = aw_get_irq_type;
  *(code **)(param_1 + 0x4e0) = aw_direct_db_val_to_reg;
  *(undefined2 *)(param_1 + 0xb8) = 0;
  *(undefined8 *)(param_1 + 0x130) = 0x200000003;
  *(undefined8 *)(param_1 + 0x138) = 0xffff0000ffff;
  *(undefined8 *)(param_1 + 0x140) = 0xffffff7f00000004;
  *(undefined8 *)(param_1 + 0x148) = 0x8000000000;
  *(char **)(param_1 + 0x150) = "btn pwd";
  *(undefined8 *)(param_1 + 0x158) = 0xfffffffe00000004;
  *(undefined8 *)(param_1 + 0xa8) = 0;
  *(undefined8 *)(param_1 + 0xb0) = 0;
  *(undefined8 *)(param_1 + 0x98) = 0;
  *(undefined8 *)(param_1 + 0xa0) = 0;
  *(undefined8 *)(param_1 + 0x170) = 0xfffffffd00000004;
  *(undefined8 *)(param_1 + 0x178) = 2;
  *(undefined8 *)(param_1 + 0x160) = 1;
  *(char **)(param_1 + 0x168) = "btn amppd";
  *(undefined8 *)(param_1 + 0x3dc) = 0xfffff3ff00000006;
  *(undefined8 *)(param_1 + 0x430) = 1;
  *(char **)(param_1 + 0x180) = "btn hmute";
  *(undefined8 *)(param_1 + 0x188) = 0xfffffeff00000004;
  *(undefined8 *)(param_1 + 0x1a0) = 0xffff7fff00000004;
  *(undefined8 *)(param_1 + 0x1a8) = 0x8000;
  *(undefined8 *)(param_1 + 0x88) = 0;
  *(undefined8 *)(param_1 + 0x90) = 0;
  *(undefined8 *)(param_1 + 0x288) = 0;
  *(undefined8 *)(param_1 + 400) = 0x100;
  *(char **)(param_1 + 0x198) = "btn uls humte";
  *(undefined4 *)(param_1 + 0x264) = 0;
  *(undefined4 *)(param_1 + 0x440) = 0xff;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffdfff00000004;
  *(undefined8 *)(param_1 + 0x1b8) = 0x2000;
  *(undefined8 *)(param_1 + 0x218) = 0xffffb4c400000001;
  *(undefined4 *)(param_1 + 0x458) = 0xff;
  *(undefined8 *)(param_1 + 0x3e4) = 0x80000000400;
  *(undefined8 *)(param_1 + 0x220) = 0x31100000211;
  *(undefined4 *)(param_1 + 0x228) = 0x11;
  *(undefined4 *)(param_1 + 0x470) = 0xff;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffdfff0000001f;
  *(undefined8 *)(param_1 + 0x234) = 0x200000000000;
  *(undefined4 *)(param_1 + 0x23c) = 0x21;
  *(undefined4 *)(param_1 + 0x240) = 0x1789;
  *(undefined4 *)(param_1 + 0x410) = 0xff;
  *(undefined8 *)(param_1 + 0x254) = 0xffff0fff00000061;
  *(undefined4 *)(param_1 + 0x244) = 0x3ff;
  *(undefined4 *)(param_1 + 0x20c) = 0xff;
  *(undefined8 *)(param_1 + 0x26c) = 0x3ff;
  *(undefined8 *)(param_1 + 0x248) = 0xfffffdff00000022;
  *(undefined4 *)(param_1 + 0x1c4) = 0xff;
  *(undefined4 *)(param_1 + 0x1e8) = 0xff;
  *(undefined8 *)(param_1 + 0x3f8) = 0xffffefff00000004;
  *(undefined4 *)(param_1 + 0x250) = 0xfc00;
  *(undefined8 *)(param_1 + 0x25c) = 0xfffffc0000000005;
  *(undefined8 *)(param_1 + 0x3c8) = 0x55aa00000000;
  *(undefined4 *)(param_1 + 0x40) = 0x40;
  *(char **)(param_1 + 0x3f0) = "btn bop";
  *(char **)(param_1 + 0x420) = "btn noise gate";
  *(undefined8 *)(param_1 + 0x400) = 0x1000;
  *(char **)(param_1 + 0x438) = "btn none psm";
  *(undefined8 *)(param_1 + 0x428) = 0xfffffffe0000005e;
  *(char **)(param_1 + 0x450) = "btn none mpd";
  *(undefined4 *)(param_1 + 0x1d0) = 0xff;
  *(undefined4 *)(param_1 + 500) = 0xff;
  *(char **)(param_1 + 0x468) = "btn none dsmzth";
  *(undefined4 *)(param_1 + 0x10c) = 0xff;
  *(undefined4 *)(param_1 + 0x11c) = 0xff;
  *(undefined4 *)(param_1 + 0xd0) = 0xff;
  *(char **)(param_1 + 0x408) = "btn none dither";
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000002;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  *(undefined8 *)(param_1 + 0xf0) = 0xffff7fff0000007c;
  *(undefined4 *)(param_1 + 0xf8) = 0x8000;
  *(undefined4 *)(param_1 + 0xfc) = 0xff;
  *(undefined8 *)(param_1 + 0x4a0) = 0xff;
  *(undefined8 *)(param_1 + 0x4a8) = 0;
  *(char **)(param_1 + 0x498) = "btn none dither";
  return;
}



//------------------------------------------------------------
// aw_direct_reg_val_to_db @ 001186c8 size=4
// signature: undefined aw_direct_reg_val_to_db(void)
// callers: []
//------------------------------------------------------------

void aw_direct_reg_val_to_db(void)

{
  return;
}



//------------------------------------------------------------
// aw_direct_db_val_to_reg @ 001186d0 size=4
// signature: undefined aw_direct_db_val_to_reg(void)
// callers: []
//------------------------------------------------------------

void aw_direct_db_val_to_reg(void)

{
  return;
}



//------------------------------------------------------------
// aw_get_irq_type @ 001186d8 size=248
// signature: undefined aw_get_irq_type(void)
// callers: []
//------------------------------------------------------------

uint aw_get_irq_type(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 >> 0xe & 1) == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122798,lVar1,"aw_get_irq_type");
    uVar3 = 1;
    uVar2 = 1;
  }
  if ((param_2 >> 0xb & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00121100,lVar1,"aw_get_irq_type");
    uVar3 = uVar2 | 2;
  }
  if ((param_2 >> 3 & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122bc5,lVar1,"aw_get_irq_type");
    uVar3 = uVar3 | 4;
  }
  if ((param_2 >> 1 & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d939,lVar1,"aw_get_irq_type");
    uVar3 = uVar3 | 8;
  }
  return uVar3;
}



//------------------------------------------------------------
// aw882xx_chipid_auth @ 001187d4 size=220
// signature: undefined aw882xx_chipid_auth(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

undefined8 aw882xx_chipid_auth(int param_1)

{
  if (param_1 < 0x2116) {
    if (param_1 < 0x2032) {
      if ((param_1 != 0x1852) && (param_1 != 0x2013)) {
        return 0xffffffea;
      }
    }
    else if (((0x3f < param_1 - 0x2032U) ||
             ((1L << ((ulong)(param_1 - 0x2032U) & 0x3f) & 0x8000000800000001U) == 0)) &&
            (param_1 != 0x2113)) {
      return 0xffffffea;
    }
  }
  else if (param_1 < 0x2407) {
    if (((0x28 < param_1 - 0x2308U) ||
        ((1L << ((ulong)(param_1 - 0x2308U) & 0x3f) & 0x10200000001U) == 0)) && (param_1 != 0x2116))
    {
      return 0xffffffea;
    }
  }
  else if ((param_1 != 0x2407) && (param_1 != 0x2418)) {
    return 0xffffffea;
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_init @ 001188b4 size=424
// signature: undefined aw882xx_init(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

undefined8 aw882xx_init(long param_1)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  aw_dev_init_cmm();
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 < 0x2116) {
    if (iVar1 < 0x2055) {
      if (iVar1 == 0x1852) {
        lVar4 = 0;
      }
      else if (iVar1 == 0x2013) {
        lVar4 = 1;
      }
      else {
        if (iVar1 != 0x2032) {
LAB_00118a30:
          lVar4 = (*(long **)(param_1 + 0x78))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + 0x78);
          }
          _printk(&DAT_0011d1fd,lVar4,"aw882xx_init");
          return 0xffffffea;
        }
        lVar4 = 2;
      }
    }
    else if (iVar1 == 0x2055) {
      lVar4 = 3;
    }
    else if (iVar1 == 0x2071) {
      lVar4 = 4;
    }
    else {
      if (iVar1 != 0x2113) goto LAB_00118a30;
      lVar4 = 5;
    }
  }
  else if (iVar1 < 0x2330) {
    if (iVar1 == 0x2116) {
      lVar4 = 6;
    }
    else if (iVar1 == 0x2308) {
      lVar4 = 7;
    }
    else {
      if (iVar1 != 0x2329) goto LAB_00118a30;
      lVar4 = 8;
    }
  }
  else if (iVar1 == 0x2330) {
    lVar4 = 9;
  }
  else if (iVar1 == 0x2407) {
    lVar4 = 10;
  }
  else {
    if (iVar1 != 0x2418) goto LAB_00118a30;
    lVar4 = 0xb;
  }
  if (*(int *)((&PTR_aw_pid_1852_dev_init_00124470)[lVar4 * 2] + -4) != 0x75a9b632) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x118a0c);
    (*pcVar2)();
  }
  (*(code *)(&PTR_aw_pid_1852_dev_init_00124470)[lVar4 * 2])(param_1);
  aw882xx_dev_check_ef_lock(param_1);
  uVar3 = aw882xx_dev_probe(param_1);
  return uVar3;
}



//------------------------------------------------------------
// aw_pid_1852_dev_init @ 00118a60 size=376
// signature: undefined aw_pid_1852_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_1852_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x7d;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_1852_monitor_bin_0011d5cc._16_8_;
  uVar2 = s_aw882xx_pid_1852_monitor_bin_0011d5cc._8_8_;
  uVar1 = s_aw882xx_pid_1852_monitor_bin_0011d5cc._0_8_;
  *(undefined4 *)(param_1 + 0x40) = 0xc;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(code **)(param_1 + 0x4e0) = aw_6_0P5_db_val_to_reg;
  *(code **)(param_1 + 0x4d8) = aw_6_0P5_reg_val_to_db;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined4 *)(param_1 + 0x20c) = 0x56;
  *(undefined8 *)(param_1 + 0x188) = 0xffffffef00000005;
  *(undefined8 *)(param_1 + 400) = 0x10;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(char **)(param_1 + 0x180) = "btn 1852 hmue";
  *(undefined8 *)(param_1 + 0x1b0) = 0xfffffffe00000007;
  *(undefined8 *)(param_1 + 0x1b8) = 1;
  *(undefined8 *)(param_1 + 0x1c4) = 0xfffffc000000007a;
  *(undefined4 *)(param_1 + 0x214) = 0x2000;
  *(undefined4 *)(param_1 + 0x208) = 1;
  *(undefined8 *)(param_1 + 0x1e8) = 0xfffffc0000000078;
  *(undefined4 *)(param_1 + 0x210) = 1000;
  *(undefined8 *)(param_1 + 0x1dc) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x200) = 0xffff03fffffffdff;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(undefined4 *)(param_1 + 0x1d0) = 0xff;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffbfff00000066;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000000;
  *(undefined4 *)(param_1 + 500) = 0xff;
  *(undefined4 *)(param_1 + 0x23c) = 0x12;
  *(undefined4 *)(param_1 + 0x3f8) = 0xff;
  *(undefined8 *)(param_1 + 0x254) = 0xfffffff000000005;
  *(undefined4 *)(param_1 + 0x248) = 0x13;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(undefined4 *)(param_1 + 0x264) = 8;
  *(undefined8 *)(param_1 + 0x25c) = 0xffff00ff0000000c;
  *(undefined8 *)(param_1 + 0x410) = 0xffffff7f00000071;
  *(undefined8 *)(param_1 + 0x26c) = 0xb4;
  *(char **)(param_1 + 0x408) = "btn 1852 dither";
  *(undefined8 *)(param_1 + 0x418) = 0x80;
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000001;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  return;
}



//------------------------------------------------------------
// aw_pid_2013_dev_init @ 00118bdc size=608
// signature: undefined aw_pid_2013_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2013_dev_init(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  undefined *puVar6;
  long lVar7;
  long *plVar8;
  uint local_2c;
  long local_28;
  
  uVar3 = s_aw882xx_pid_2013_monitor_bin_0011f7d1._8_8_;
  uVar2 = s_aw882xx_pid_2013_monitor_bin_0011f7d1._0_8_;
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  *(undefined4 *)(param_1 + 0x1c) = 0x7d;
  uVar4 = s_aw882xx_pid_2013_monitor_bin_0011f7d1._16_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  *(undefined8 *)(param_1 + 0x88) = uVar2;
  *(undefined8 *)(param_1 + 0x90) = uVar3;
  *(undefined8 *)(param_1 + 0x98) = uVar4;
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(undefined8 *)(param_1 + 0x418) = 0x4000;
  *(undefined8 *)(param_1 + 0x20c) = 0x3e800000050;
  *(undefined4 *)(param_1 + 0x214) = 0x2000;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(undefined4 *)(param_1 + 0x1c8) = 0xfffffc00;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffbfff00000006;
  *(undefined8 *)(param_1 + 0x1b8) = 0x4000;
  *(undefined8 *)(param_1 + 0x10c) = 0xffffff7f00000004;
  *(undefined4 *)(param_1 + 0x1c4) = 0x78;
  *(undefined4 *)(param_1 + 0x1d0) = 0xff;
  *(undefined4 *)(param_1 + 500) = 0xff;
  *(undefined8 *)(param_1 + 0x1dc) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x200) = 0xffff03fffffffdff;
  *(undefined4 *)(param_1 + 0x208) = 1;
  *(undefined4 *)(param_1 + 0x114) = 0;
  *(undefined8 *)(param_1 + 0x1e8) = 0xfffffc0000000079;
  *(undefined4 *)(param_1 + 0x3f8) = 0xff;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(undefined8 *)(param_1 + 0x11c) = 0xffffffcf00000061;
  *(undefined8 *)(param_1 + 0x124) = 0x10;
  local_2c = 0;
  *(undefined8 *)(param_1 + 0x22c) = 0xfffffffb00000055;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000;
  *(undefined8 *)(param_1 + 0x26c) = 0x2d0;
  *(undefined8 *)(param_1 + 0x410) = 0xffffbfff00000012;
  *(char **)(param_1 + 0x408) = "btn 2013 dither";
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000001;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x118d80);
    (*pcVar5)();
  }
  (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x7a,&local_2c);
  uVar1 = (local_2c >> 0xd ^ 0xffffffff) & 7;
  if ((uVar1 == 0) || ((local_2c & 0x1c00) == 0x1c00)) {
    plVar8 = *(long **)(param_1 + 0x78);
    *(undefined4 *)(param_1 + 0x10c) = 0xff;
    *(undefined4 *)(param_1 + 0x11c) = 0xff;
    lVar7 = plVar8[0xe];
    if ((uVar1 == 0) || ((local_2c & 0x1c00) != 0x1c00)) {
      if (lVar7 == 0) {
        lVar7 = *plVar8;
      }
      puVar6 = &DAT_0011f08f;
    }
    else {
      if (lVar7 == 0) {
        lVar7 = *plVar8;
      }
      puVar6 = &DAT_00120556;
    }
  }
  else {
    lVar7 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar7 == 0) {
      lVar7 = **(long **)(param_1 + 0x78);
    }
    puVar6 = &DAT_001220ee;
  }
  _printk(puVar6,lVar7,"aw_pid_2013_efver_check");
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw_pid_2032_dev_init @ 00118e40 size=372
// signature: undefined aw_pid_2032_dev_init(void)
// callers: [aw882xx_init]
//------------------------------------------------------------

void aw_pid_2032_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x7e;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_2032_monitor_bin_00123a50._16_8_;
  uVar2 = s_aw882xx_pid_2032_monitor_bin_00123a50._8_8_;
  uVar1 = s_aw882xx_pid_2032_monitor_bin_00123a50._0_8_;
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(char **)(param_1 + 0x180) = "btn 2032 hmute";
  *(undefined8 *)(param_1 + 0x188) = 0xffffffef00000005;
  *(undefined8 *)(param_1 + 400) = 0x10;
  *(undefined8 *)(param_1 + 0x1b0) = 0xfffffffe00000007;
  *(undefined8 *)(param_1 + 0x1b8) = 1;
  *(undefined4 *)(param_1 + 0x20c) = 0x56;
  *(undefined8 *)(param_1 + 0x1c4) = 0xfffffc000000007a;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(undefined4 *)(param_1 + 0x210) = 1000;
  *(undefined8 *)(param_1 + 0x1e8) = 0xfffffc0000000078;
  *(undefined4 *)(param_1 + 0x208) = 1;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(undefined8 *)(param_1 + 0x1dc) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x200) = 0xffff03fffffffdff;
  *(undefined4 *)(param_1 + 0x214) = 0x2000;
  *(undefined4 *)(param_1 + 0x1d0) = 0xff;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffbfff00000066;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000000;
  *(undefined4 *)(param_1 + 500) = 0xff;
  *(undefined4 *)(param_1 + 0x23c) = 0x12;
  *(undefined4 *)(param_1 + 0x3f8) = 0xff;
  *(undefined8 *)(param_1 + 0x254) = 0xfffffff000000005;
  *(undefined4 *)(param_1 + 0x248) = 0x13;
  *(undefined8 *)(param_1 + 0x418) = 0x2000;
  *(undefined4 *)(param_1 + 0x264) = 6;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(undefined8 *)(param_1 + 0x25c) = 0xffff003f00000005;
  *(undefined8 *)(param_1 + 0x410) = 0xffffdfff00000020;
  *(undefined8 *)(param_1 + 0x26c) = 0x2d0;
  *(char **)(param_1 + 0x408) = "btn 2032 dither";
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000001;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  return;
}



//------------------------------------------------------------
// aw_pid_2055_dev_check @ 00118fb8 size=852
// signature: undefined aw_pid_2055_dev_check(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2055_dev_check(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  char *pcVar7;
  int local_6c;
  long local_68;
  
  uVar4 = s_aw882xx_pid_2055_monitor_bin_0011db8e._16_8_;
  uVar3 = s_aw882xx_pid_2055_monitor_bin_0011db8e._8_8_;
  uVar2 = s_aw882xx_pid_2055_monitor_bin_0011db8e._0_8_;
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  pcVar7 = (char *)(param_1 + 0x88);
  *(undefined8 *)pcVar7 = s_aw882xx_pid_2055_monitor_bin_0011db8e._0_8_;
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(undefined4 *)(param_1 + 0x1c) = 0x7d;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(undefined4 *)(param_1 + 0x26c) = 0x2d0;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(undefined8 *)(param_1 + 0x400) = 0x10;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffbfff00000006;
  *(undefined8 *)(param_1 + 0x1b8) = 0x4000;
  *(undefined8 *)(param_1 + 0x3f8) = 0xffffffef0000003c;
  *(undefined8 *)(param_1 + 0x22c) = 0xfffffffb00000052;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000;
  *(undefined8 *)(param_1 + 0x410) = 0xffffbfff00000017;
  local_6c = 0;
  *(undefined8 *)(param_1 + 0x90) = uVar3;
  *(undefined8 *)(param_1 + 0x98) = uVar4;
  *(char **)(param_1 + 0x408) = "btn 2055 dither";
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(char **)(param_1 + 0x3f0) = "btn 2055 bop";
  *(undefined8 *)(param_1 + 0x418) = 0x4000;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000002;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  *(undefined8 *)(param_1 + 0xf0) = 0xffff7fff00000079;
  *(undefined4 *)(param_1 + 0xf8) = 0x8000;
  if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11911c);
    (*pcVar6)();
  }
  (**(code **)(param_1 + 0x4c0))(*(undefined8 *)(param_1 + 0x80),0,0x55aa);
  usleep_range_state(1000,0x44c,2);
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x119158);
    (*pcVar6)();
  }
  (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x23,&local_6c);
  *(undefined8 *)pcVar7 = uVar2;
  *(undefined8 *)(param_1 + 0x90) = uVar3;
  *(undefined4 *)(param_1 + 0x1c) = 0x7d;
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000002;
  *(undefined8 *)(param_1 + 0x98) = uVar4;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(char **)(param_1 + 0x3f0) = "btn 2055 bop";
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  *(undefined8 *)(param_1 + 0x418) = 0x4000;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(undefined8 *)(param_1 + 0xf0) = 0xffff7fff00000079;
  *(undefined4 *)(param_1 + 0xf8) = 0x8000;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffbfff00000006;
  *(undefined8 *)(param_1 + 0x1b8) = 0x4000;
  *(undefined4 *)(param_1 + 0x26c) = 0x2d0;
  *(undefined8 *)(param_1 + 0x22c) = 0xfffffffb00000052;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000;
  *(undefined8 *)(param_1 + 0x3f8) = 0xffffffef0000003c;
  *(undefined8 *)(param_1 + 0x400) = 0x10;
  *(undefined8 *)(param_1 + 0x410) = 0xffffbfff00000017;
  *(char **)(param_1 + 0x408) = "btn 2055 dither";
  if (local_6c == 0x6708) {
    *(undefined4 *)(param_1 + 0x140) = 0xff;
    *(undefined4 *)(param_1 + 0x23c) = 0xff;
    uVar5 = s_aw882xx_pid_2055a_monitor_bin_00122ebc._8_8_;
    uVar4 = s_aw882xx_pid_2055a_monitor_bin_00122ebc._0_8_;
    *(undefined4 *)(param_1 + 0x248) = 0xff;
    uVar2 = CONCAT35(s_aw882xx_pid_2055a_monitor_bin_00122ebc._21_3_,
                     s_aw882xx_pid_2055a_monitor_bin_00122ebc._16_5_);
    *(undefined4 *)(param_1 + 4) = 0x2055a;
    uVar3 = CONCAT53(s_aw882xx_pid_2055a_monitor_bin_00122ebc._24_5_,
                     s_aw882xx_pid_2055a_monitor_bin_00122ebc._21_3_);
    *(undefined8 *)pcVar7 = uVar4;
    *(undefined8 *)(param_1 + 0x90) = uVar5;
    *(undefined8 *)(param_1 + 0x98) = uVar2;
    *(undefined8 *)(param_1 + 0x9d) = uVar3;
  }
  usleep_range_state(2000,0x7da,2);
  if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1192bc);
    (*pcVar6)();
  }
  (**(code **)(param_1 + 0x4c0))(*(undefined8 *)(param_1 + 0x80),0x73,0x1d40);
  usleep_range_state(3000,0xbc2,2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw_pid_2071_dev_init @ 00119310 size=396
// signature: undefined aw_pid_2071_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2071_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x7e;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_2071_monitor_bin_00120af7._16_8_;
  uVar2 = s_aw882xx_pid_2071_monitor_bin_00120af7._8_8_;
  uVar1 = s_aw882xx_pid_2071_monitor_bin_00120af7._0_8_;
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(char **)(param_1 + 0x180) = "btn 2071 hmute";
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined8 *)(param_1 + 0x188) = 0xffffffef00000005;
  *(undefined8 *)(param_1 + 400) = 0x10;
  *(undefined4 *)(param_1 + 0x210) = 1000;
  *(undefined4 *)(param_1 + 0x20c) = 0x56;
  *(undefined8 *)(param_1 + 0x200) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x1c4) = 0xffff83ff00000078;
  *(undefined8 *)(param_1 + 0x1cc) = 0x7a0000000a;
  *(undefined8 *)(param_1 + 0x1d4) = 0xaffff83ff;
  *(undefined8 *)(param_1 + 0x1dc) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x1e8) = 0xfffffc0000000078;
  *(undefined4 *)(param_1 + 0x23c) = 0x12;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffbfff00000066;
  *(undefined8 *)(param_1 + 0x234) = 0x400000000000;
  *(undefined4 *)(param_1 + 0x214) = 0x2000;
  *(undefined4 *)(param_1 + 500) = 0xff;
  *(undefined8 *)(param_1 + 0x254) = 0xfffffff000000005;
  *(undefined4 *)(param_1 + 0x248) = 0x13;
  *(undefined4 *)(param_1 + 0x3f8) = 0xff;
  *(undefined8 *)(param_1 + 0x418) = 0x2000;
  *(undefined8 *)(param_1 + 0x25c) = 0xffff003f00000005;
  *(undefined8 *)(param_1 + 0x1b0) = 0xfffffffe00000007;
  *(undefined8 *)(param_1 + 0x1b8) = 1;
  *(undefined4 *)(param_1 + 0x1e4) = 1;
  *(undefined4 *)(param_1 + 0x264) = 6;
  *(undefined4 *)(param_1 + 0x208) = 1;
  *(undefined4 *)(param_1 + 0x14) = 1;
  *(undefined8 *)(param_1 + 0x26c) = 0x2d0;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(char **)(param_1 + 0x408) = "btn 2071 dither";
  *(undefined8 *)(param_1 + 0x410) = 0xffffdfff00000020;
  *(undefined8 *)(param_1 + 0xe0) = 0x7800000001;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  return;
}



//------------------------------------------------------------
// aw_pid_2113_dev_init @ 001194a0 size=492
// signature: undefined aw_pid_2113_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2113_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  code *pcVar4;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x80;
  uVar3 = s_aw882xx_pid_2113_monitor_bin_00120b14._16_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar2 = s_aw882xx_pid_2113_monitor_bin_00120b14._8_8_;
  uVar1 = s_aw882xx_pid_2113_monitor_bin_00120b14._0_8_;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(undefined4 *)(param_1 + 0x40) = 0x30;
  *(code **)(param_1 + 0x4d8) = aw_6_0P125_reg_val_to_db;
  *(code **)(param_1 + 0x4f8) = aw_pid_2113_frcset_check;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(code **)(param_1 + 0x4e0) = aw_6_0P125_db_val_to_reg;
  *(undefined4 *)(param_1 + 0x20c) = 0x50;
  *(code **)(param_1 + 0x4f0) = aw_pid_2113_reg_force_set;
  *(char **)(param_1 + 0x198) = "btn 2113 uls hmute";
  *(undefined8 *)(param_1 + 0x1a0) = 0xffffbfff00000004;
  *(undefined4 *)(param_1 + 0x214) = 0x2000;
  *(undefined8 *)(param_1 + 0x1c4) = 0xfffffc0000000078;
  *(undefined8 *)(param_1 + 0x1cc) = 0x7c00000000;
  *(undefined8 *)(param_1 + 0x1d4) = 0xfffffc00;
  *(undefined8 *)(param_1 + 0x1dc) = 0xffff03fffffffdff;
  *(undefined8 *)(param_1 + 0x1e4) = 0x7900000001;
  *(undefined8 *)(param_1 + 0x1ec) = 0xfffffc00;
  *(undefined8 *)(param_1 + 500) = 0xfffffc000000007d;
  *(undefined8 *)(param_1 + 0x1fc) = 0xfffffdff00000000;
  *(undefined8 *)(param_1 + 0x204) = 0x1ffff03ff;
  *(undefined4 *)(param_1 + 0x210) = 1000;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffffbf00000054;
  *(undefined8 *)(param_1 + 0x234) = 0x4000000000;
  *(undefined8 *)(param_1 + 0x1a8) = 0x4000;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffffbf00000008;
  *(undefined8 *)(param_1 + 0x1b8) = 0x40;
  *(undefined4 *)(param_1 + 0x26c) = 0x2d0;
  *(undefined8 *)(param_1 + 0x3f8) = 0xffffffdf0000003c;
  *(undefined8 *)(param_1 + 0x400) = 0x20;
  *(char **)(param_1 + 0x3f0) = "btn 2113 bop";
  if (*(int *)(*(code **)(param_1 + 0x4c0) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x119620);
    (*pcVar4)();
  }
  (**(code **)(param_1 + 0x4c0))(*(undefined8 *)(param_1 + 0x80),0x73,0x1d40);
  usleep_range_state(3000,0xbc2,2);
  *(undefined8 *)(param_1 + 0xfc) = 0xfff700000014;
  *(undefined8 *)(param_1 + 0x104) = 0x800000000;
  *(undefined8 *)(param_1 + 0x418) = 0x4000;
  *(undefined8 *)(param_1 + 0x410) = 0xffffbfff00000014;
  *(char **)(param_1 + 0x408) = "btn 2113 dither";
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  return;
}



//------------------------------------------------------------
// aw_pid_2116_dev_init @ 00119690 size=264
// signature: undefined aw_pid_2116_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2116_dev_init(long param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = 0x72;
  *(code **)(param_1 + 0x4e8) = aw_get_irq_nobst_type;
  *(undefined4 *)(param_1 + 0x224) = 0x111;
  *(undefined8 *)(param_1 + 0x138) = 0x61ff000061ff;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined8 *)(param_1 + 0x21c) = 0x11ffffbec4;
  *(undefined8 *)(param_1 + 0x170) = 0xfffffffd00000004;
  *(undefined8 *)(param_1 + 0x178) = 0x200000000;
  *(char **)(param_1 + 0x168) = "btn 2116 amppd";
  *(undefined8 *)(param_1 + 0x400) = 0x4000;
  *(char **)(param_1 + 0x198) = "btn 2116 uls hmute";
  *(undefined8 *)(param_1 + 0x1a0) = 0xffffbfff00000004;
  *(undefined8 *)(param_1 + 0x1a8) = 0x4000;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffffbf00000008;
  *(undefined8 *)(param_1 + 0x1b8) = 0x40;
  *(undefined4 *)(param_1 + 0x140) = 0xff;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffdfff00000054;
  *(undefined8 *)(param_1 + 0x234) = 0x200000000000;
  *(undefined4 *)(param_1 + 0x23c) = 0xff;
  *(undefined4 *)(param_1 + 0x248) = 0xff;
  *(undefined4 *)(param_1 + 0x254) = 0xff;
  *(undefined8 *)(param_1 + 0x430) = 0x2000;
  *(undefined8 *)(param_1 + 0x3f8) = 0xffffbfff00000005;
  *(char **)(param_1 + 0x3f0) = "btn 2116 bop";
  *(undefined8 *)(param_1 + 0x428) = 0xffffdfff00000016;
  *(char **)(param_1 + 0x420) = "btn 2116 noise gate";
  return;
}



//------------------------------------------------------------
// aw_pid_2308_dev_init @ 0011979c size=200
// signature: undefined aw_pid_2308_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2308_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x80;
  uVar2 = s_aw882xx_pid_2308_monitor_bin_0012362f._8_8_;
  uVar1 = s_aw882xx_pid_2308_monitor_bin_0012362f._0_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_2308_monitor_bin_0012362f._16_8_;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(code **)(param_1 + 0x4e0) = aw_direct_db_val_to_reg;
  *(code **)(param_1 + 0x500) = aw_pid_2308_get_voltage_offset;
  *(code **)(param_1 + 0x4d8) = aw_direct_reg_val_to_db;
  *(char **)(param_1 + 0x450) = "btn 2308 mpd";
  *(undefined2 *)(param_1 + 0x480) = 0x2e38;
  *(undefined8 *)(param_1 + 0x448) = 0x4000;
  *(undefined8 *)(param_1 + 0x440) = 0xffffbfff00000005;
  *(undefined8 *)(param_1 + 0x458) = 0xffff7fff00000005;
  *(char **)(param_1 + 0x438) = "btn 2308 psm";
  *(undefined8 *)(param_1 + 0x460) = 0x8000;
  *(undefined8 *)(param_1 + 0x470) = 0xffffff0f0000005e;
  *(undefined8 *)(param_1 + 0x478) = 0x50;
  *(char **)(param_1 + 0x468) = "btn 2308 dsmzth";
  return;
}



//------------------------------------------------------------
// aw_pid_2329_dev_init @ 00119868 size=152
// signature: undefined aw_pid_2329_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2329_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x80;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar2 = s_aw882xx_pid_2329_monitor_bin_0011d5e9._8_8_;
  uVar1 = s_aw882xx_pid_2329_monitor_bin_0011d5e9._0_8_;
  *(undefined8 *)(param_1 + 0x98) = s_aw882xx_pid_2329_monitor_bin_0011d5e9._16_8_;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined2 *)(param_1 + 0x480) = 0x3938;
  *(undefined4 *)(param_1 + 0x22c) = 0xff;
  *(undefined8 *)(param_1 + 0xd0) = 0xfffff3ff00000004;
  *(undefined8 *)(param_1 + 0xd8) = 0x800;
  *(undefined8 *)(param_1 + 0x254) = 0xffff03ff00000060;
  *(undefined8 *)(param_1 + 0x4a0) = 0xffffffdf00000059;
  *(char **)(param_1 + 200) = "btn pid 2329 IIC Write EN";
  *(undefined8 *)(param_1 + 0x4a8) = 0x20;
  *(char **)(param_1 + 0x498) = "btn pid 2329 lpc";
  return;
}



//------------------------------------------------------------
// aw_pid_2330_dev_init @ 00119904 size=144
// signature: undefined aw_pid_2330_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2330_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x7b;
  uVar2 = s_aw882xx_pid_2330_monitor_bin_0011eca2._8_8_;
  uVar1 = s_aw882xx_pid_2330_monitor_bin_0011eca2._0_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_2330_monitor_bin_0011eca2._16_8_;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(undefined4 *)(param_1 + 0x428) = 0x5b;
  *(undefined4 *)(param_1 + 0x22c) = 0xff;
  *(undefined4 *)(param_1 + 0x248) = 0xff;
  *(undefined2 *)(param_1 + 0x480) = 0x3938;
  *(undefined8 *)(param_1 + 0x254) = 0xffff03ff00000062;
  *(char **)(param_1 + 200) = "btn pid 2330 IIC Write EN";
  *(undefined8 *)(param_1 + 0xd0) = 0xfffff3ff00000004;
  *(undefined8 *)(param_1 + 0xd8) = 0x800;
  *(undefined4 *)(param_1 + 0xf0) = 0x7a;
  *(undefined4 *)(param_1 + 0xe4) = 0x77;
  return;
}



//------------------------------------------------------------
// aw_pid_2407_dev_init @ 00119998 size=260
// signature: undefined aw_pid_2407_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2407_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x7e;
  uVar2 = s_aw882xx_pid_2407_monitor_bin_00122be4._8_8_;
  uVar1 = s_aw882xx_pid_2407_monitor_bin_00122be4._0_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  uVar3 = s_aw882xx_pid_2407_monitor_bin_00122be4._16_8_;
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined8 *)(param_1 + 0x98) = uVar3;
  *(code **)(param_1 + 0x4e8) = aw_get_irq_nobst_type;
  *(char **)(param_1 + 200) = "btn pid 2407 IIC Write EN";
  *(undefined8 *)(param_1 + 0xd0) = 0xffff3fff00000004;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffff7f00000004;
  *(undefined8 *)(param_1 + 0x1b8) = 0x80;
  *(undefined8 *)(param_1 + 0x220) = 0x11100000011;
  *(undefined8 *)(param_1 + 0x218) = 0xffffbec400000001;
  *(undefined4 *)(param_1 + 0x228) = 0x11;
  *(undefined8 *)(param_1 + 0x3dc) = 0xfffff3ff00000005;
  *(undefined4 *)(param_1 + 0x140) = 0xff;
  *(undefined4 *)(param_1 + 0x1a0) = 0xff;
  *(undefined2 *)(param_1 + 0x480) = 0x3938;
  *(undefined4 *)(param_1 + 0x22c) = 0xff;
  *(undefined4 *)(param_1 + 0x23c) = 0xff;
  *(undefined4 *)(param_1 + 0x248) = 0xff;
  *(undefined4 *)(param_1 + 0x254) = 0xff;
  *(undefined4 *)(param_1 + 0x3f8) = 0xff;
  *(undefined4 *)(param_1 + 0x428) = 0xff;
  *(undefined8 *)(param_1 + 0x3e4) = 0x80000000400;
  *(undefined4 *)(param_1 + 0xf8) = 0x8000;
  *(undefined8 *)(param_1 + 0xd8) = 0x8000;
  *(undefined8 *)(param_1 + 0xe0) = 0x7600000002;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  *(undefined8 *)(param_1 + 0xf0) = 0xffff7fff00000078;
  return;
}



//------------------------------------------------------------
// aw_pid_2418_dev_init @ 00119aa0 size=436
// signature: undefined aw_pid_2418_dev_init(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2418_dev_init(long param_1)

{
  undefined8 uVar1;
  undefined8 uVar2;
  
  *(undefined4 *)(param_1 + 0x1c) = 0x80;
  uVar2 = s_aw882xx_pid_2418_monitor_bin_0011f379._8_8_;
  uVar1 = s_aw882xx_pid_2418_monitor_bin_0011f379._0_8_;
  *(undefined8 *)(param_1 + 0x98) = s_aw882xx_pid_2418_monitor_bin_0011f379._16_8_;
  *(undefined4 *)(param_1 + 0xa0) = 0x6e69622e;
  *(char **)(param_1 + 0x438) = "btn 2418 psm";
  *(code **)(param_1 + 0x500) = aw_pid_2418_get_voltage_offset;
  *(char **)(param_1 + 0x450) = "btn 2418 mpd";
  *(code **)(param_1 + 0x4e0) = aw_direct_db_val_to_reg;
  *(code **)(param_1 + 0x4d8) = aw_direct_reg_val_to_db;
  *(char **)(param_1 + 0x468) = "btn 2418 dsmzth";
  *(undefined8 *)(param_1 + 0x88) = uVar1;
  *(undefined8 *)(param_1 + 0x90) = uVar2;
  *(undefined8 *)(param_1 + 0x448) = 0x4000;
  *(undefined8 *)(param_1 + 0x440) = 0xffffbfff00000005;
  *(undefined8 *)(param_1 + 0x460) = 0x8000;
  *(undefined8 *)(param_1 + 0x418) = 0x8000;
  *(undefined8 *)(param_1 + 0x458) = 0xffff7fff00000005;
  *(undefined8 *)(param_1 + 0x23c) = 0x17b100000020;
  *(undefined8 *)(param_1 + 0x470) = 0xffffff0f00000052;
  *(undefined4 *)(param_1 + 0x244) = 0x3ff;
  *(undefined8 *)(param_1 + 0x478) = 0x50;
  *(char **)(param_1 + 0x408) = "btn 2418 dither";
  *(undefined8 *)(param_1 + 0x248) = 0xfffffdff00000021;
  *(undefined8 *)(param_1 + 0x1b0) = 0xffffffdf00000008;
  *(undefined8 *)(param_1 + 0x1b8) = 0x20;
  *(undefined8 *)(param_1 + 0x4a8) = 0x100;
  *(undefined4 *)(param_1 + 0x250) = 0xfc00;
  *(undefined8 *)(param_1 + 0x410) = 0xffff7fff00000025;
  *(undefined8 *)(param_1 + 0x22c) = 0xffffdfff00000025;
  *(undefined8 *)(param_1 + 0x234) = 0x200000000000;
  *(undefined2 *)(param_1 + 0x480) = 0x2d30;
  *(undefined8 *)(param_1 + 0x254) = 0xffff07ff00000042;
  *(undefined8 *)(param_1 + 0x430) = 1;
  *(undefined8 *)(param_1 + 0x428) = 0xfffffffe00000052;
  *(char **)(param_1 + 0x420) = "btn 2418 noise gate";
  *(undefined8 *)(param_1 + 0xe0) = 0x7600000001;
  *(undefined8 *)(param_1 + 0xe8) = 0x8000ffff7fff;
  *(undefined8 *)(param_1 + 0x4a0) = 0xfffffeff0000003a;
  *(char **)(param_1 + 0x498) = "btn 2418 lpc";
  return;
}



//------------------------------------------------------------
// aw_6_0P5_reg_val_to_db @ 00119c58 size=20
// signature: undefined aw_6_0P5_reg_val_to_db(void)
// callers: []
//------------------------------------------------------------

int aw_6_0P5_reg_val_to_db(ulong param_1)

{
  return ((uint)param_1 & 0xf) + ((uint)(param_1 >> 4) & 0xfffffff) * 0xc;
}



//------------------------------------------------------------
// aw_6_0P5_db_val_to_reg @ 00119c70 size=32
// signature: undefined aw_6_0P5_db_val_to_reg(void)
// callers: []
//------------------------------------------------------------

uint aw_6_0P5_db_val_to_reg(uint param_1)

{
  return param_1 % 0xc | param_1 / 0xc << 4;
}



//------------------------------------------------------------
// aw_6_0P125_reg_val_to_db @ 00119c94 size=20
// signature: undefined aw_6_0P125_reg_val_to_db(void)
// callers: []
//------------------------------------------------------------

int aw_6_0P125_reg_val_to_db(ulong param_1)

{
  return ((uint)param_1 & 0x3f) + ((uint)(param_1 >> 6) & 0x3ffffff) * 0x30;
}



//------------------------------------------------------------
// aw_6_0P125_db_val_to_reg @ 00119cac size=32
// signature: undefined aw_6_0P125_db_val_to_reg(void)
// callers: []
//------------------------------------------------------------

uint aw_6_0P125_db_val_to_reg(uint param_1)

{
  return param_1 % 0x30 | param_1 / 0x30 << 6;
}



//------------------------------------------------------------
// aw_pid_2113_reg_force_set @ 00119cd0 size=376
// signature: undefined aw_pid_2113_reg_force_set(void)
// callers: []
//------------------------------------------------------------

void aw_pid_2113_reg_force_set(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119d1c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),0x62,0xffffefff,0x1000);
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119d4c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),100,0xfffffff8,4);
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119d7c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),0x65,0xfffffffc,2);
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119dac);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),0x66,0xffff3fff,0x8000);
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119ddc);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),0x67,0xfffffff7,0);
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119e0c);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x4d0))(*(undefined8 *)(param_1 + 0x80),0x68,0xfffffc7f,0x100);
  }
  else {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00121a8e,lVar2,"aw_pid_2113_reg_force_set");
  }
  return;
}



//------------------------------------------------------------
// aw_pid_2113_frcset_check @ 00119e4c size=260
// signature: undefined aw_pid_2113_frcset_check(void)
// callers: []
//------------------------------------------------------------

undefined8 aw_pid_2113_frcset_check(long param_1)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  uint local_2c;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x119e9c);
    (*pcVar3)();
  }
  (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x79,&local_2c);
  uVar2 = local_2c;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x119ecc);
    (*pcVar3)();
  }
  (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x7d,&local_2c);
  uVar1 = local_2c | uVar2;
  if (*(int *)(param_1 + 0x14) != 1) {
    uVar1 = uVar2 & local_2c;
  }
  *(uint *)(param_1 + 0xc) = (uint)((uVar1 & 0x7c00) == 0);
  lVar4 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar4 == 0) {
    lVar4 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_0011e461,lVar4,"aw_pid_2113_frcset_check");
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// aw_get_irq_nobst_type @ 00119f54 size=248
// signature: undefined aw_get_irq_nobst_type(void)
// callers: []
//------------------------------------------------------------

uint aw_get_irq_nobst_type(long param_1,uint param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 >> 0xe & 1) == 0) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122798,lVar1,"aw_get_irq_nobst_type");
    uVar3 = 1;
    uVar2 = 1;
  }
  if ((param_2 >> 0xb & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00121100,lVar1,"aw_get_irq_nobst_type");
    uVar3 = uVar2 | 2;
  }
  if ((param_2 >> 3 & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_00122bc5,lVar1,"aw_get_irq_nobst_type");
    uVar3 = uVar3 | 4;
  }
  if ((param_2 >> 1 & 1) != 0) {
    lVar1 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar1 == 0) {
      lVar1 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d939,lVar1,"aw_get_irq_nobst_type");
    uVar3 = uVar3 | 8;
  }
  return uVar3;
}



//------------------------------------------------------------
// aw_pid_2308_get_voltage_offset @ 0011a050 size=188
// signature: undefined aw_pid_2308_get_voltage_offset(void)
// callers: []
//------------------------------------------------------------

undefined4 aw_pid_2308_get_voltage_offset(long param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11a0a4);
    (*pcVar1)();
  }
  uVar2 = (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x7a,&local_2c);
  *param_2 = -(local_2c >> 7 & 1) & 0xfffffe00 | (local_2c & 0xff) << 1;
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120b31,lVar3,"aw_pid_2308_get_voltage_offset");
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// aw_pid_2418_get_voltage_offset @ 0011a110 size=188
// signature: undefined aw_pid_2418_get_voltage_offset(void)
// callers: []
//------------------------------------------------------------

undefined4 aw_pid_2418_get_voltage_offset(long param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  long lVar3;
  uint local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(int *)(*(code **)(param_1 + 0x4c8) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11a164);
    (*pcVar1)();
  }
  uVar2 = (**(code **)(param_1 + 0x4c8))(*(undefined8 *)(param_1 + 0x80),0x75,&local_2c);
  *param_2 = -(local_2c >> 7 & 1) & 0xfffffe00 | (local_2c & 0xff) << 1;
  lVar3 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar3 == 0) {
    lVar3 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120b31,lVar3,"aw_pid_2418_get_voltage_offset");
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// aw882xx_monitor_start @ 0011a1d0 size=348
// signature: undefined aw882xx_monitor_start(void)
// callers: [monitor_update_store, monitor_store, aw882xx_device_start, aw882xx_monitor_set]
//------------------------------------------------------------

void aw882xx_monitor_start(long param_1)

{
  code *pcVar1;
  bool bVar2;
  long lVar3;
  long *plVar4;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  plVar4 = *(long **)(param_1 + -0x230);
  lVar3 = plVar4[0xe];
  if (lVar3 == 0) {
    lVar3 = *plVar4;
  }
  _printk(&DAT_00120075,lVar3,"aw882xx_monitor_start");
  *(undefined2 *)(param_1 + 0xe9) = 0;
  *(undefined4 *)(param_1 + 0x10c) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  aw_dev_monitor_hw_status(param_1 + -0x2a8);
  local_3c = 0;
  if (*(int *)(param_1 + 0x150) == 0xff) {
    if (*(int *)(param_1 + -0x298) == 1) {
LAB_0011a300:
      plVar4 = *(long **)(param_1 + -0x230);
      lVar3 = plVar4[0xe];
      if (lVar3 == 0) {
        lVar3 = *plVar4;
      }
      _printk(&DAT_00120b5a,lVar3,"aw882xx_monitor_start");
      goto LAB_0011a280;
    }
  }
  else {
    if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x11a2d4);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x220))
              (*(undefined8 *)(param_1 + -0x228),*(int *)(param_1 + 0x150),&local_3c);
    bVar2 = (local_3c & 0xffff & (*(ushort *)(param_1 + 0x154) ^ 0xffff)) ==
            *(uint *)(param_1 + 0x158);
    *(uint *)(param_1 + -0x298) = (uint)bVar2;
    if (bVar2) goto LAB_0011a300;
  }
  *(undefined1 *)(param_1 + 0xe8) = 1;
  if (*(char *)(param_1 + 0xec) == '\0') {
    queue_delayed_work_on(0x20,*(undefined8 *)(param_1 + -0x1e8),param_1,0);
  }
LAB_0011a280:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_monitor_stop @ 0011a330 size=104
// signature: undefined aw882xx_monitor_stop(void)
// callers: [aw882xx_device_stop]
//------------------------------------------------------------

undefined8 aw882xx_monitor_stop(long param_1)

{
  long lVar1;
  
  lVar1 = (*(long **)(param_1 + -0x230))[0xe];
  if (lVar1 == 0) {
    lVar1 = **(long **)(param_1 + -0x230);
  }
  _printk(&DAT_00120075,lVar1,"aw882xx_monitor_stop");
  *(undefined4 *)(param_1 + -0x34) = 0;
  *(undefined1 *)(param_1 + 0xe8) = 0;
  if (*(char *)(param_1 + 0xec) == '\0') {
    cancel_delayed_work_sync(param_1);
  }
  return 0;
}



//------------------------------------------------------------
// aw882xx_monitor_hal_work @ 0011a39c size=68
// signature: undefined aw882xx_monitor_hal_work(void)
// callers: [aw882xx_dev_monitor_hal_work]
//------------------------------------------------------------

void aw882xx_monitor_hal_work(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0xe8) == '\0') {
    uVar1 = 0xffffffff;
  }
  else {
    aw_monitor_work_func();
    uVar1 = *(undefined4 *)(param_1 + 0xf0);
  }
  *param_2 = uVar1;
  return;
}



//------------------------------------------------------------
// aw_monitor_work_func @ 0011a3e4 size=1668
// signature: undefined aw_monitor_work_func(void)
// callers: [aw882xx_monitor_hal_work]
//------------------------------------------------------------

void aw_monitor_work_func(long param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  ushort uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  undefined *puVar9;
  long lVar10;
  ushort uVar11;
  uint uVar12;
  uint uVar13;
  long *plVar14;
  long lVar15;
  undefined8 uVar16;
  ushort uVar17;
  uint uVar18;
  undefined8 *puVar19;
  uint uVar20;
  int local_54;
  uint local_50;
  uint local_4c;
  long local_48;
  
  lVar15 = sp_el0;
  local_48 = *(long *)(lVar15 + 0x638);
  if (((*(char *)(param_1 + 0x88) != '\x01') || (*(int *)(param_1 + -0x2a0) == 0)) ||
     (*(int *)(param_1 + 0x8c) == 0)) goto LAB_0011a480;
  puVar19 = (undefined8 *)(param_1 + -0x228);
  local_4c = 0;
  if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x11a464);
    (*pcVar5)();
  }
  iVar6 = (**(code **)(param_1 + 0x220))(*puVar19,*(undefined4 *)(param_1 + -0x120),&local_4c);
  if ((iVar6 < 0) || ((local_4c & (*(uint *)(param_1 + -0x11c) ^ 0xffffffff)) != 0))
  goto LAB_0011a480;
  iVar6 = aw882xx_cali_svc_get_cali_status();
  if (iVar6 == 0) {
    lVar15 = param_1 + -0x2a8;
    local_54 = 0;
    local_50 = 0;
    if ((*(char *)(param_1 + 0xed) == '\x01') || (*(int *)(param_1 + -0x6c) == 0xff)) {
      iVar6 = aw_monitor_get_data_form_system(lVar15,&local_50,0xc);
      if (iVar6 == 0) {
        local_50 = local_50 / 1000;
        goto LAB_0011a5d0;
      }
      lVar10 = (*(long **)(param_1 + -0x230))[0xe];
      if (lVar10 == 0) {
        lVar10 = **(long **)(param_1 + -0x230);
      }
      _printk(&DAT_00121e2f,lVar10,"aw_monitor_get_voltage");
      if (iVar6 < 0) goto LAB_0011a988;
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a588);
        (*pcVar5)();
      }
      iVar6 = (**(code **)(param_1 + 0x220))(*puVar19,*(int *)(param_1 + -0x6c),&local_50);
      if (iVar6 < 0) {
        lVar15 = (*(long **)(param_1 + -0x230))[0xe];
        if (lVar15 == 0) {
          lVar15 = **(long **)(param_1 + -0x230);
        }
        _printk(&DAT_0011e8d3,lVar15,"aw_monitor_get_voltage");
        goto LAB_0011a988;
      }
      uVar12 = 0;
      if (*(uint *)(param_1 + -100) != 0) {
        uVar12 = (*(int *)(param_1 + -0x68) * local_50) / *(uint *)(param_1 + -100);
      }
      local_50 = uVar12 & 0xffff;
LAB_0011a5d0:
      lVar10 = (*(long **)(param_1 + -0x230))[0xe];
      if (lVar10 == 0) {
        lVar10 = **(long **)(param_1 + -0x230);
      }
      _printk(&DAT_0011e149,lVar10,"aw_monitor_get_voltage");
    }
    local_4c = 0;
    if ((*(char *)(param_1 + 0xed) == '\x01') || (*(int *)(param_1 + -0x60) == 0xff)) {
      iVar6 = aw_monitor_get_data_form_system(lVar15,&local_54,0x34);
      if (iVar6 == 0) {
        iVar6 = local_54 / 10;
        goto LAB_0011a718;
      }
      lVar10 = (*(long **)(param_1 + -0x230))[0xe];
      if (lVar10 == 0) {
        lVar10 = **(long **)(param_1 + -0x230);
      }
      _printk(&DAT_0011d958,lVar10,"aw_monitor_get_temperature");
      if (iVar6 < 0) goto LAB_0011a988;
      iVar6 = local_54;
    }
    else {
      if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a6a8);
        (*pcVar5)();
      }
      iVar6 = (**(code **)(param_1 + 0x220))(*puVar19,*(int *)(param_1 + -0x60),&local_4c);
      plVar14 = *(long **)(param_1 + -0x230);
      lVar10 = plVar14[0xe];
      if (iVar6 < 0) {
        if (lVar10 == 0) {
          lVar10 = *plVar14;
        }
        _printk(&DAT_0011fd4e,lVar10,"aw_monitor_get_temperature");
        goto LAB_0011a988;
      }
      if (lVar10 == 0) {
        lVar10 = *plVar14;
      }
      _printk(&DAT_00121151,lVar10,"aw_monitor_get_temperature",local_4c);
      uVar11 = (ushort)local_4c;
      if ((local_4c & 0xffff & (*(uint *)(param_1 + -0x5c) ^ 0xffffffff)) != 0) {
        uVar11 = (ushort)*(undefined4 *)(param_1 + -0x58) | (ushort)local_4c;
      }
      iVar6 = (int)(short)uVar11;
LAB_0011a718:
      lVar10 = (*(long **)(param_1 + -0x230))[0xe];
      if (lVar10 == 0) {
        lVar10 = **(long **)(param_1 + -0x230);
      }
      _printk(&DAT_001216b8,lVar10,"aw_monitor_get_temperature",iVar6);
    }
    bVar1 = *(char *)(param_1 + 0xea) + 1;
    *(uint *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + local_50;
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + iVar6;
    *(byte *)(param_1 + 0xea) = bVar1;
    if ((*(uint *)(param_1 + 0x94) <= (uint)bVar1) || (*(char *)(param_1 + 0xe9) != '\x01')) {
      if (*(int *)(param_1 + 0xa4) == 0) {
        *(undefined8 *)(param_1 + 0x114) = 0xffffffff00ff00ff;
      }
      else {
        iVar6 = aw_monitor_get_data_from_table
                          (lVar15,*(undefined8 *)(param_1 + 0xd8),*(undefined8 *)(param_1 + 0xe0),
                           param_1 + 0x108,*(undefined4 *)(param_1 + 0xa8));
        if (iVar6 < 0) goto LAB_0011a988;
      }
      if (*(int *)(param_1 + 0x9c) == 0) {
        uVar11 = *(ushort *)(param_1 + 0x114);
        *(undefined8 *)(param_1 + 0x100) = 0xffffffff00ff00ff;
        if (uVar11 != 0xff) {
LAB_0011a7f0:
          uVar13 = (uint)uVar11;
          uVar17 = *(ushort *)(param_1 + 0x116);
          uVar20 = *(uint *)(param_1 + 0x118);
          goto LAB_0011a880;
        }
LAB_0011a814:
        uVar17 = *(ushort *)(param_1 + 0x102);
        uVar20 = *(uint *)(param_1 + 0x104);
      }
      else {
        iVar6 = aw_monitor_get_data_from_table
                          (lVar15,*(undefined8 *)(param_1 + 200),*(undefined8 *)(param_1 + 0xd0),
                           param_1 + 0xf4,*(undefined4 *)(param_1 + 0xa0));
        if (iVar6 < 0) goto LAB_0011a988;
        uVar17 = *(ushort *)(param_1 + 0x100);
        uVar11 = *(ushort *)(param_1 + 0x114);
        uVar12 = (uint)uVar17;
        if (uVar12 == 0xff) {
          if (uVar11 == 0xff) goto LAB_0011a814;
          goto LAB_0011a7f0;
        }
        uVar18 = (uint)uVar11;
        uVar13 = (uint)uVar17;
        if (uVar18 == 0xff) {
          uVar17 = *(ushort *)(param_1 + 0x102);
          uVar20 = *(uint *)(param_1 + 0x104);
        }
        else {
          uVar17 = *(ushort *)(param_1 + 0x102);
          uVar4 = *(ushort *)(param_1 + 0x116);
          uVar20 = *(uint *)(param_1 + 0x104);
          uVar2 = *(uint *)(param_1 + 0x118);
          if (*(int *)(param_1 + 0x98) == 0) {
            if (uVar18 <= uVar12) {
              uVar13 = uVar18;
            }
            if (uVar17 <= uVar4) {
              uVar17 = uVar4;
            }
            if (uVar20 <= uVar2) {
              uVar20 = uVar2;
            }
          }
          else {
            if (uVar18 > uVar12 || uVar13 == uVar18) {
              uVar13 = (uint)uVar11;
            }
            if (uVar4 <= uVar17) {
              uVar17 = uVar4;
            }
            if (uVar2 <= uVar20) {
              uVar20 = uVar2;
            }
          }
        }
LAB_0011a880:
        local_4c = 0;
        if (*(int *)(param_1 + 0xac) != 0) {
          if (*(int *)(*(code **)(param_1 + 0x220) + -4) != -0x671129d3) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a8b4);
            (*pcVar5)();
          }
          iVar6 = (**(code **)(param_1 + 0x220))
                            (*puVar19,*(undefined4 *)(param_1 + -0x54),&local_4c);
          if (iVar6 < 0) {
            lVar10 = (*(long **)(param_1 + -0x230))[0xe];
            if (lVar10 == 0) {
              lVar10 = **(long **)(param_1 + -0x230);
            }
            puVar9 = &DAT_0011e493;
LAB_0011aa2c:
            _printk(puVar9,lVar10,"aw_monitor_set_ipeak");
          }
          else if ((local_4c & (*(uint *)(param_1 + -0x50) ^ 0xffffffff)) != uVar13) {
            local_4c = *(uint *)(param_1 + -0x50) & local_4c | uVar13;
            if (*(int *)(*(code **)(param_1 + 0x218) + -4) != 0x38528aca) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x11aa08);
              (*pcVar5)();
            }
            iVar6 = (**(code **)(param_1 + 0x218))(*puVar19,*(undefined4 *)(param_1 + -0x54));
            plVar14 = *(long **)(param_1 + -0x230);
            lVar10 = plVar14[0xe];
            if (iVar6 < 0) {
              if (lVar10 == 0) {
                lVar10 = *plVar14;
              }
              puVar9 = &DAT_0011ce14;
              goto LAB_0011aa2c;
            }
            if (lVar10 == 0) {
              lVar10 = *plVar14;
            }
            _printk(&DAT_0011d98f,lVar10,"aw_monitor_set_ipeak",local_4c,uVar13);
          }
        }
      }
      if ((uVar17 != 0xff) && (*(int *)(param_1 + 0xb0) != 0)) {
        if (*(int *)(*(code **)(param_1 + 0x230) + -4) != 0x673a7326) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a900);
          (*pcVar5)();
        }
        iVar7 = (**(code **)(param_1 + 0x230))(uVar17);
        *(int *)(param_1 + -0x34) = iVar7;
        iVar6 = *(int *)(param_1 + -0x38);
        if (*(int *)(param_1 + -0x38) <= iVar7) {
          iVar6 = iVar7;
        }
        aw882xx_dev_set_volume(lVar15,iVar6);
      }
      local_4c = uVar20;
      if ((((uVar20 != 0xffffffff) && (*(int *)(param_1 + 0xb4) != 0)) &&
          ((*(uint *)(param_1 + 0xf0) != uVar20 || (*(char *)(param_1 + 0xe9) == '\0')))) &&
         (*(uint *)(param_1 + 0xf0) = uVar20, *(char *)(param_1 + 0xec) == '\0')) {
        aw882xx_dsp_write_vmax(lVar15,&local_4c,4);
      }
      *(undefined1 *)(param_1 + 0xea) = 0;
      uVar3 = *(undefined4 *)(param_1 + 0x10c);
      *(undefined4 *)(param_1 + 0x10c) = 0;
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0xf8);
      *(undefined4 *)(param_1 + 0xf8) = 0;
      *(undefined4 *)(param_1 + 0x108) = uVar3;
      if (*(char *)(param_1 + 0xe9) == '\0') {
        *(undefined1 *)(param_1 + 0xe9) = 1;
      }
    }
  }
  else {
    lVar15 = (*(long **)(param_1 + -0x230))[0xe];
    if (lVar15 == 0) {
      lVar15 = **(long **)(param_1 + -0x230);
    }
    _printk(&DAT_0011dbda,lVar15,"aw_monitor_work");
  }
LAB_0011a988:
  if (*(char *)(param_1 + 0xec) == '\0') {
    uVar16 = *(undefined8 *)(param_1 + -0x1e8);
    uVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x90));
    queue_delayed_work_on(0x20,uVar16,param_1,uVar8);
  }
LAB_0011a480:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_monitor_hal_get_time @ 0011aa6c size=12
// signature: undefined aw882xx_monitor_hal_get_time(void)
// callers: [aw882xx_dev_monitor_hal_get_time]
//------------------------------------------------------------

void aw882xx_monitor_hal_get_time(long param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x90);
  return;
}



//------------------------------------------------------------
// aw882xx_monitor_parse_fw @ 0011aa7c size=3124
// signature: undefined aw882xx_monitor_parse_fw(void)
// callers: [monitor_update_store, aw_dev_parse_data_by_sec_type, aw882xx_dev_parse_acf]
//------------------------------------------------------------

undefined8 aw882xx_monitor_parse_fw(long param_1,int *param_2,uint param_3)

{
  uint uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  byte *pbVar10;
  uint uVar11;
  undefined8 *puVar12;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    _printk(&DAT_0011cde5);
LAB_0011aae8:
    uVar3 = 0xffffffea;
  }
  else {
    if (param_3 < 0x54) {
      lVar4 = (*(long **)(param_1 + -0x230))[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)(param_1 + -0x230);
      }
      puVar2 = &DAT_00120bc7;
      pcVar6 = "aw_monitor_param_check_sum";
    }
    else {
      if (param_3 + 0x7fffffff < 0x80000005) {
        iVar9 = 0;
        uVar7 = 4;
LAB_0011ab64:
        do {
          lVar4 = (long)(int)uVar7;
          uVar7 = uVar7 + 1;
          iVar9 = iVar9 + (uint)*(byte *)((long)param_2 + lVar4);
        } while (param_3 != uVar7);
      }
      else {
        iVar8 = 0;
        uVar1 = param_3 - 4 & 0xfffffffe;
        iVar9 = 0;
        uVar7 = uVar1 + 4;
        pbVar10 = (byte *)((long)param_2 + 5);
        uVar11 = uVar1;
        do {
          uVar11 = uVar11 - 2;
          iVar8 = iVar8 + (uint)pbVar10[-1];
          iVar9 = iVar9 + (uint)*pbVar10;
          pbVar10 = pbVar10 + 2;
        } while (uVar11 != 0);
        iVar9 = iVar9 + iVar8;
        if (param_3 - 4 != uVar1) goto LAB_0011ab64;
      }
      if (*param_2 != iVar9) {
        lVar4 = (*(long **)(param_1 + -0x230))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + -0x230);
        }
        _printk(&DAT_00122805,lVar4,"aw_monitor_param_check_sum");
        return 0xfffffff4;
      }
      iVar8 = param_2[1];
      lVar4 = param_1 + -0x2a8;
      if (iVar8 == 0x10200) {
        uVar7 = param_2[0xd];
        if (param_3 < uVar7) {
          lVar4 = (*(long **)(param_1 + -0x230))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + -0x230);
          }
          puVar2 = &DAT_00123674;
        }
        else {
          uVar7 = param_2[0x11];
          if (param_3 < uVar7) {
            lVar4 = (*(long **)(param_1 + -0x230))[0xe];
            if (lVar4 == 0) {
              lVar4 = **(long **)(param_1 + -0x230);
            }
            puVar2 = &DAT_0012284b;
          }
          else {
            uVar7 = param_2[0xc] * param_2[0xb];
            if (param_3 < uVar7) {
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_0011fff2;
            }
            else {
              uVar7 = param_2[0x10] * param_2[0xf];
              if (uVar7 <= param_3) {
                puVar12 = (undefined8 *)(param_1 + -0x230);
                *(uint *)(param_1 + 0x8c) = param_2[9] & 1;
                *(int *)(param_1 + 0x90) = param_2[7];
                *(int *)(param_1 + 0x94) = param_2[8];
                *(uint *)(param_1 + 0xac) = (uint)param_2[9] >> 2 & 1;
                *(uint *)(param_1 + 0x98) = (uint)param_2[9] >> 1 & 1;
                *(uint *)(param_1 + 0xb0) = (uint)param_2[9] >> 3 & 1;
                *(uint *)(param_1 + 0xb4) = (uint)param_2[9] >> 4 & 1;
                *(uint *)(param_1 + 0x9c) = (uint)param_2[9] >> 5 & 1;
                *(int *)(param_1 + 0xa0) = param_2[10];
                *(uint *)(param_1 + 0xa4) = (uint)param_2[9] >> 6 & 1;
                *(int *)(param_1 + 0xa8) = param_2[0xe];
                *(uint *)(param_1 + 0xb8) = (uint)param_2[9] >> 7 & 1;
                *(uint *)(param_1 + 0xbc) = (uint)param_2[9] >> 8 & 1;
                *(uint *)(param_1 + 0xc0) = (uint)param_2[9] >> 9 & 1;
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122493,lVar5,"aw_monitor_parse_hdr_v_0_1_2",param_2 + 2);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122f2e,lVar5,"aw_monitor_parse_hdr_v_0_1_2",param_2[6]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122c30,lVar5,"aw_monitor_parse_hdr_v_0_1_2",
                        *(undefined4 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0xbc),
                        *(undefined4 *)(param_1 + 0xb8));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_001216e1,lVar5,"aw_monitor_parse_hdr_v_0_1_2",
                        *(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90),
                        *(undefined4 *)(param_1 + 0x94));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011e16f,lVar5,"aw_monitor_parse_hdr_v_0_1_2",
                        *(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0xac),
                        *(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011dc2d,lVar5,"aw_monitor_parse_hdr_v_0_1_2",
                        *(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0),
                        *(undefined4 *)(param_1 + 0xa4),*(undefined4 *)(param_1 + 0xa8));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011f0ed,lVar5,"aw_monitor_parse_temp_data_v_0_1_2");
                if (*(long *)(param_1 + 0xd0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xd0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0xb] * 0xc,0xdc0);
                *(long *)(param_1 + 0xd0) = lVar5;
                if (lVar5 == 0) {
                  return 0xfffffff4;
                }
                *(undefined1 *)(param_1 + 200) = (char)param_2[0xb];
                aw_monitor_write_data_to_table
                          (lVar4,(undefined1 *)(param_1 + 200),
                           (long)param_2 + (ulong)(uint)param_2[0xd]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122885,lVar5,"aw_monitor_parse_temp_data_v_0_1_2");
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0012058c,lVar5,"aw_monitor_parse_vol_data_v_0_1_2");
                if (*(long *)(param_1 + 0xe0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xe0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0xf] * 0xc,0xdc0);
                *(long *)(param_1 + 0xe0) = lVar5;
                if (lVar5 != 0) {
                  *(undefined1 *)(param_1 + 0xd8) = (char)param_2[0xf];
                  aw_monitor_write_data_to_table
                            (lVar4,(undefined1 *)(param_1 + 0xd8),
                             (long)param_2 + (ulong)(uint)param_2[0x11]);
                  lVar4 = ((long *)*puVar12)[0xe];
                  if (lVar4 == 0) {
                    lVar4 = *(long *)*puVar12;
                  }
                  pcVar6 = "aw_monitor_parse_vol_data_v_0_1_2";
LAB_0011b69c:
                  _printk(&DAT_001228ae,lVar4,pcVar6);
                  *(undefined1 *)(param_1 + 0x88) = 1;
                  return 0;
                }
LAB_0011b640:
                if (*(long *)(param_1 + 0xd0) == 0) {
                  return 0xfffffff4;
                }
                devm_kfree(*(undefined8 *)(param_1 + -0x230));
                *(undefined8 *)(param_1 + 0xd0) = 0;
                *(undefined1 *)(param_1 + 200) = 0;
                return 0xfffffff4;
              }
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_00121ae7;
            }
          }
        }
        _printk(puVar2,lVar4,"aw_monitor_check_fw_v_0_1_2",uVar7,param_3);
        lVar4 = (*(long **)(param_1 + -0x230))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + -0x230);
        }
        puVar2 = &DAT_0012364c;
        pcVar6 = "aw_monitor_parse_data_v_0_1_2";
      }
      else if (iVar8 == 0x10100) {
        uVar7 = param_2[0xd];
        if (param_3 < uVar7) {
          lVar4 = (*(long **)(param_1 + -0x230))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + -0x230);
          }
          puVar2 = &DAT_00123674;
        }
        else {
          uVar7 = param_2[0x11];
          if (param_3 < uVar7) {
            lVar4 = (*(long **)(param_1 + -0x230))[0xe];
            if (lVar4 == 0) {
              lVar4 = **(long **)(param_1 + -0x230);
            }
            puVar2 = &DAT_0012284b;
          }
          else {
            uVar7 = param_2[0xc] * param_2[0xb];
            if (param_3 < uVar7) {
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_0011fff2;
            }
            else {
              uVar7 = param_2[0x10] * param_2[0xf];
              if (uVar7 <= param_3) {
                puVar12 = (undefined8 *)(param_1 + -0x230);
                *(uint *)(param_1 + 0x8c) = param_2[9] & 1;
                *(int *)(param_1 + 0x90) = param_2[7];
                *(int *)(param_1 + 0x94) = param_2[8];
                *(uint *)(param_1 + 0xac) = (uint)param_2[9] >> 2 & 1;
                *(uint *)(param_1 + 0x98) = (uint)param_2[9] >> 1 & 1;
                *(uint *)(param_1 + 0xb0) = (uint)param_2[9] >> 3 & 1;
                *(uint *)(param_1 + 0xb4) = (uint)param_2[9] >> 4 & 1;
                *(uint *)(param_1 + 0x9c) = (uint)param_2[9] >> 5 & 1;
                *(int *)(param_1 + 0xa0) = param_2[10];
                *(uint *)(param_1 + 0xa4) = (uint)param_2[9] >> 6 & 1;
                *(int *)(param_1 + 0xa8) = param_2[0xe];
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122493,lVar5,"aw_monitor_parse_hdr_v_0_1_1",param_2 + 2);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122f2e,lVar5,"aw_monitor_parse_hdr_v_0_1_1",param_2[6]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_001216e1,lVar5,"aw_monitor_parse_hdr_v_0_1_1",
                        *(undefined4 *)(param_1 + 0x8c),*(undefined4 *)(param_1 + 0x90),
                        *(undefined4 *)(param_1 + 0x94));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011e16f,lVar5,"aw_monitor_parse_hdr_v_0_1_1",
                        *(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0xac),
                        *(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011dc2d,lVar5,"aw_monitor_parse_hdr_v_0_1_1",
                        *(undefined4 *)(param_1 + 0x9c),*(undefined4 *)(param_1 + 0xa0),
                        *(undefined4 *)(param_1 + 0xa4),*(undefined4 *)(param_1 + 0xa8));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011f0ed,lVar5,"aw_monitor_parse_temp_data_v_0_1_1");
                if (*(long *)(param_1 + 0xd0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xd0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0xb] * 0xc,0xdc0);
                *(long *)(param_1 + 0xd0) = lVar5;
                if (lVar5 == 0) {
                  return 0xfffffff4;
                }
                *(undefined1 *)(param_1 + 200) = (char)param_2[0xb];
                aw_monitor_write_data_to_table
                          (lVar4,(undefined1 *)(param_1 + 200),
                           (long)param_2 + (ulong)(uint)param_2[0xd]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122885,lVar5,"aw_monitor_parse_temp_data_v_0_1_1");
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0012058c,lVar5,"aw_monitor_parse_vol_data_v_0_1_1");
                if (*(long *)(param_1 + 0xe0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xe0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0xf] * 0xc,0xdc0);
                *(long *)(param_1 + 0xe0) = lVar5;
                if (lVar5 != 0) {
                  *(undefined1 *)(param_1 + 0xd8) = (char)param_2[0xf];
                  aw_monitor_write_data_to_table
                            (lVar4,(undefined1 *)(param_1 + 0xd8),
                             (long)param_2 + (ulong)(uint)param_2[0x11]);
                  lVar4 = ((long *)*puVar12)[0xe];
                  if (lVar4 == 0) {
                    lVar4 = *(long *)*puVar12;
                  }
                  pcVar6 = "aw_monitor_parse_vol_data_v_0_1_1";
                  goto LAB_0011b69c;
                }
                goto LAB_0011b640;
              }
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_00121ae7;
            }
          }
        }
        _printk(puVar2,lVar4,"aw_monitor_check_fw_v_0_1_1",uVar7,param_3);
        lVar4 = (*(long **)(param_1 + -0x230))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + -0x230);
        }
        puVar2 = &DAT_0012364c;
        pcVar6 = "aw_monitor_parse_data_v_0_1_1";
      }
      else {
        if (iVar8 != 0x10000) {
          lVar4 = (*(long **)(param_1 + -0x230))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + -0x230);
          }
          _printk(&DAT_00120b97,lVar4,"aw882xx_monitor_parse_fw");
          goto LAB_0011aae8;
        }
        uVar7 = param_2[0xf];
        if (param_3 < uVar7) {
          lVar4 = (*(long **)(param_1 + -0x230))[0xe];
          if (lVar4 == 0) {
            lVar4 = **(long **)(param_1 + -0x230);
          }
          puVar2 = &DAT_00123674;
        }
        else {
          uVar7 = param_2[0x14];
          if (param_3 < uVar7) {
            lVar4 = (*(long **)(param_1 + -0x230))[0xe];
            if (lVar4 == 0) {
              lVar4 = **(long **)(param_1 + -0x230);
            }
            puVar2 = &DAT_0012284b;
          }
          else {
            uVar7 = param_2[0xe] * param_2[0xd];
            if (param_3 < uVar7) {
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_0011fff2;
            }
            else {
              uVar7 = param_2[0x13] * param_2[0x12];
              if (uVar7 <= param_3) {
                puVar12 = (undefined8 *)(param_1 + -0x230);
                *(int *)(param_1 + 0x8c) = param_2[5];
                *(int *)(param_1 + 0x90) = param_2[6];
                *(int *)(param_1 + 0x94) = param_2[7];
                *(int *)(param_1 + 0xac) = param_2[8];
                *(int *)(param_1 + 0xb0) = param_2[9];
                *(int *)(param_1 + 0xb4) = param_2[10];
                *(int *)(param_1 + 0x9c) = param_2[0xb];
                *(int *)(param_1 + 0xa0) = param_2[0xc];
                *(int *)(param_1 + 0xa4) = param_2[0x10];
                *(int *)(param_1 + 0xa8) = param_2[0x11];
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122493,lVar5,"aw_monitor_parse_hdr",param_2 + 2);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122f2e,lVar5,"aw_monitor_parse_hdr",param_2[4]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_001216e1,lVar5,"aw_monitor_parse_hdr",*(undefined4 *)(param_1 + 0x8c),
                        *(undefined4 *)(param_1 + 0x90),*(undefined4 *)(param_1 + 0x94));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011fad7,lVar5,"aw_monitor_parse_hdr",*(undefined4 *)(param_1 + 0xac),
                        *(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011dc2d,lVar5,"aw_monitor_parse_hdr",*(undefined4 *)(param_1 + 0x9c),
                        *(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4),
                        *(undefined4 *)(param_1 + 0xa8));
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0011f0ed,lVar5,"aw_monitor_parse_temp_data");
                if (*(long *)(param_1 + 0xd0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xd0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0xd] * 0xc,0xdc0);
                *(long *)(param_1 + 0xd0) = lVar5;
                if (lVar5 == 0) {
                  return 0xfffffff4;
                }
                *(undefined1 *)(param_1 + 200) = (char)param_2[0xd];
                aw_monitor_write_data_to_table
                          (lVar4,(undefined1 *)(param_1 + 200),
                           (long)param_2 + (ulong)(uint)param_2[0xf]);
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_00122885,lVar5,"aw_monitor_parse_temp_data");
                lVar5 = ((long *)*puVar12)[0xe];
                if (lVar5 == 0) {
                  lVar5 = *(long *)*puVar12;
                }
                _printk(&DAT_0012058c,lVar5,"aw_monitor_parse_vol_data");
                if (*(long *)(param_1 + 0xe0) != 0) {
                  devm_kfree(*puVar12);
                  *(undefined8 *)(param_1 + 0xe0) = 0;
                }
                lVar5 = devm_kmalloc(*puVar12,(ulong)(uint)param_2[0x12] * 0xc,0xdc0);
                *(long *)(param_1 + 0xe0) = lVar5;
                if (lVar5 != 0) {
                  *(undefined1 *)(param_1 + 0xd8) = (char)param_2[0x12];
                  aw_monitor_write_data_to_table
                            (lVar4,(undefined1 *)(param_1 + 0xd8),
                             (long)param_2 + (ulong)(uint)param_2[0x14]);
                  lVar4 = ((long *)*puVar12)[0xe];
                  if (lVar4 == 0) {
                    lVar4 = *(long *)*puVar12;
                  }
                  pcVar6 = "aw_monitor_parse_vol_data";
                  goto LAB_0011b69c;
                }
                goto LAB_0011b640;
              }
              lVar4 = (*(long **)(param_1 + -0x230))[0xe];
              if (lVar4 == 0) {
                lVar4 = **(long **)(param_1 + -0x230);
              }
              puVar2 = &DAT_00121ae7;
            }
          }
        }
        _printk(puVar2,lVar4,"aw_monitor_check_fw",uVar7,param_3);
        lVar4 = (*(long **)(param_1 + -0x230))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + -0x230);
        }
        puVar2 = &DAT_0012364c;
        pcVar6 = "aw_monitor_parse_data";
      }
    }
    _printk(puVar2,lVar4,pcVar6);
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// aw882xx_monitor_init @ 0011b6b4 size=564
// signature: undefined aw882xx_monitor_init(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

void aw882xx_monitor_init(undefined8 *param_1)

{
  char *__s1;
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  char *local_48;
  char *local_40;
  long local_38;
  
  lVar2 = sp_el0;
  plVar4 = param_1 + -0x46;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = ((long *)*plVar4)[0xe];
  if (lVar2 == 0) {
    lVar2 = *(long *)*plVar4;
  }
  _printk(&DAT_00120075,lVar2,"aw882xx_monitor_init");
  local_48 = (char *)0x0;
  local_40 = (char *)0x0;
  iVar1 = of_property_read_string(*(undefined8 *)(*plVar4 + 0x2e8),"monitor-source",&local_48);
  if (iVar1 < 0) {
    lVar2 = ((long *)*plVar4)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*plVar4;
    }
    _printk(&DAT_00120c7c,lVar2,"aw_monitor_parse_mode");
  }
  else {
    iVar1 = strcmp(local_48,"system");
    if (iVar1 == 0) {
      *(undefined1 *)((long)param_1 + 0xed) = 1;
    }
    else {
      *(undefined1 *)((long)param_1 + 0xed) = 0;
    }
  }
  lVar2 = ((long *)*plVar4)[0xe];
  if (lVar2 == 0) {
    lVar2 = *(long *)*plVar4;
  }
  _printk(&DAT_00120cb8,lVar2,"aw_monitor_parse_mode",*(undefined1 *)((long)param_1 + 0xed));
  iVar1 = of_property_read_string(*(undefined8 *)(*plVar4 + 0x2e8),"monitor-mode",&local_40);
  __s1 = local_40;
  if (iVar1 < 0) {
    lVar2 = ((long *)*plVar4)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*plVar4;
    }
    _printk(&DAT_00120ced,lVar2,"aw_monitor_parse_mode");
  }
  else {
    iVar1 = strcmp(local_40,"kernel_monitor");
    if ((iVar1 == 0) || (iVar1 = strcmp(__s1,"hal_monitor"), iVar1 != 0)) {
      uVar3 = 0;
      *(undefined1 *)((long)param_1 + 0xec) = 0;
    }
    else {
      uVar3 = 1;
      *(undefined1 *)((long)param_1 + 0xec) = 1;
    }
    lVar2 = ((long *)*plVar4)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*plVar4;
    }
    _printk(&DAT_0011ecee,lVar2,"aw_monitor_parse_mode",uVar3);
  }
  *param_1 = 0xfffffffe0;
  param_1[1] = param_1 + 1;
  param_1[2] = param_1 + 1;
  param_1[3] = aw_monitor_work_func;
  init_timer_key(param_1 + 6,&delayed_work_timer_fn,0x200000,0,0);
  iVar1 = sysfs_create_group(*plVar4,&aw_monitor_attr_group);
  if (iVar1 < 0) {
    lVar2 = ((long *)*plVar4)[0xe];
    if (lVar2 == 0) {
      lVar2 = *(long *)*plVar4;
    }
    _printk(&DAT_0012215c,lVar2,"aw882xx_monitor_init");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// aw882xx_monitor_deinit @ 0011b8ec size=116
// signature: undefined aw882xx_monitor_deinit(void)
// callers: [aw882xx_dev_remove]
//------------------------------------------------------------

void aw882xx_monitor_deinit(long param_1)

{
  long lVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + -0x230);
  lVar1 = plVar2[0xe];
  if (lVar1 == 0) {
    lVar1 = *plVar2;
  }
  _printk(&DAT_00120075,lVar1,"aw882xx_monitor_stop");
  *(undefined4 *)(param_1 + -0x34) = 0;
  *(undefined1 *)(param_1 + 0xe8) = 0;
  if (*(char *)(param_1 + 0xec) == '\0') {
    cancel_delayed_work_sync(param_1);
  }
  sysfs_remove_group(*(undefined8 *)(param_1 + -0x230),&aw_monitor_attr_group);
  return;
}



//------------------------------------------------------------
// aw_monitor_get_data_form_system @ 0011b960 size=244
// signature: undefined aw_monitor_get_data_form_system(void)
// callers: [aw_monitor_work_func]
//------------------------------------------------------------

void aw_monitor_get_data_form_system(long param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  uStack_40 = 0x79726574746162;
  lVar2 = power_supply_get_by_name(&uStack_40);
  if (lVar2 == 0) {
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011d606,lVar2,"aw_monitor_get_data_form_system",&uStack_40);
  }
  else {
    iVar1 = power_supply_get_property(lVar2,param_3,&local_48);
    if (-1 < iVar1) {
      uVar3 = 0;
      *param_2 = (undefined4)local_48;
      goto LAB_0011b9cc;
    }
    lVar2 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar2 == 0) {
      lVar2 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0011ffcf,lVar2,"aw_monitor_get_data_form_system");
  }
  uVar3 = 0xffffffea;
LAB_0011b9cc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// aw_monitor_get_data_from_table @ 0011ba54 size=288
// signature: undefined aw_monitor_get_data_from_table(void)
// callers: [aw_monitor_work_func]
//------------------------------------------------------------

undefined8
aw_monitor_get_data_from_table(long param_1,ulong param_2,short *param_3,int *param_4,int param_5)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  if (*(char *)(param_1 + 0x391) == '\0') {
    if (param_3 == (short *)0x0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      pcVar3 = "aw_monitor_first_get_data_form_table";
      goto LAB_0011bb68;
    }
    param_2 = param_2 & 0xff;
    if (param_2 != 0) {
      do {
        if ((int)*param_3 <= param_4[1]) goto LAB_0011bad4;
        param_2 = param_2 - 1;
        param_3 = param_3 + 6;
      } while (param_2 != 0);
    }
  }
  else {
    iVar1 = 0;
    if (*(byte *)(param_1 + 0x392) != 0) {
      iVar1 = param_4[1] / (int)(uint)*(byte *)(param_1 + 0x392);
    }
    iVar1 = (iVar1 * param_5 + *param_4 * (1000 - param_5)) / 1000;
    param_4[1] = iVar1;
    if (param_3 == (short *)0x0) {
      lVar2 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(param_1 + 0x78);
      }
      pcVar3 = "aw_monitor_trace_data_from_table";
LAB_0011bb68:
      _printk(&DAT_0011ecbf,lVar2,pcVar3);
      return 0xffffffea;
    }
    for (param_2 = param_2 & 0xff; param_2 != 0; param_2 = param_2 - 1) {
      if ((*param_3 <= iVar1) && (iVar1 <= param_3[1])) {
LAB_0011bad4:
        uVar4 = *(undefined8 *)param_3;
        param_4[4] = *(int *)(param_3 + 4);
        *(undefined8 *)(param_4 + 2) = uVar4;
        return 0;
      }
      param_3 = param_3 + 6;
    }
  }
  return 0;
}



//------------------------------------------------------------
// aw_monitor_write_data_to_table @ 0011bb74 size=476
// signature: undefined aw_monitor_write_data_to_table(void)
// callers: [aw882xx_monitor_parse_fw]
//------------------------------------------------------------

void aw_monitor_write_data_to_table(long param_1,byte *param_2,long param_3)

{
  short *psVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  if (*param_2 != 0) {
    uVar2 = 0;
    do {
      lVar4 = (uVar2 / 0xc) * 0xc;
      lVar3 = uVar2 << 0x20;
      *(ushort *)(*(long *)(param_2 + 8) + lVar4) =
           CONCAT11(*(undefined1 *)(param_3 + (uVar2 | 1)),*(undefined1 *)(param_3 + uVar2));
      *(ushort *)(*(long *)(param_2 + 8) + lVar4 + 2) =
           CONCAT11(*(undefined1 *)(param_3 + (uVar2 | 3)),*(undefined1 *)(param_3 + (uVar2 | 2)));
      *(ushort *)(*(long *)(param_2 + 8) + lVar4 + 4) =
           CONCAT11(*(undefined1 *)(param_3 + (lVar3 + 0x500000000 >> 0x20)),
                    *(undefined1 *)(param_3 + (lVar3 + 0x400000000 >> 0x20)));
      *(ushort *)(*(long *)(param_2 + 8) + lVar4 + 6) =
           CONCAT11(*(undefined1 *)(param_3 + (lVar3 + 0x700000000 >> 0x20)),
                    *(undefined1 *)(param_3 + (lVar3 + 0x600000000 >> 0x20)));
      uVar2 = lVar3 + 0xc00000000 >> 0x20;
      *(uint *)(*(long *)(param_2 + 8) + lVar4 + 8) =
           (uint)*(byte *)(param_3 + (lVar3 + 0xb00000000 >> 0x20)) << 0x18 |
           (uint)*(byte *)(param_3 + (lVar3 + 0xa00000000 >> 0x20)) << 0x10 |
           (uint)*(byte *)(param_3 + (lVar3 + 0x900000000 >> 0x20)) << 8 |
           (uint)*(byte *)(param_3 + (lVar3 + 0x800000000 >> 0x20));
    } while (uVar2 < (ulong)*param_2 * 0xc);
    if (*param_2 != 0) {
      lVar3 = 0;
      uVar2 = 0;
      do {
        lVar4 = (*(long **)(param_1 + 0x78))[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)(param_1 + 0x78);
        }
        psVar1 = (short *)(*(long *)(param_2 + 8) + lVar3);
        _printk(&DAT_00121b20,lVar4,"aw_monitor_write_data_to_table",(long)*psVar1,(long)psVar1[1],
                psVar1[2],psVar1[3],*(undefined4 *)(psVar1 + 4));
        uVar2 = uVar2 + 1;
        lVar3 = lVar3 + 0xc;
      } while (uVar2 < *param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// monitor_show @ 0011bd54 size=64
// signature: undefined monitor_show(void)
// callers: []
//------------------------------------------------------------

long monitor_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"monitor enable: %d\n",
                   *(int *)(*(long *)(*(long *)(param_1 + 0x98) + 0x68) + 0x334));
  return (long)iVar1;
}



//------------------------------------------------------------
// monitor_store @ 0011bd98 size=204
// signature: undefined monitor_store(void)
// callers: []
//------------------------------------------------------------

long monitor_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  if (param_4 != 0) {
    iVar1 = kstrtouint(param_3,0,&local_2c);
    if (iVar1 < 0) {
      param_4 = (long)iVar1;
    }
    else {
      lVar2 = (*(long **)(lVar3 + 0x78))[0xe];
      if (lVar2 == 0) {
        lVar2 = **(long **)(lVar3 + 0x78);
      }
      _printk(&DAT_0012315d,lVar2,"monitor_store",local_2c);
      if ((*(int *)(lVar3 + 0x334) != local_2c) &&
         (*(int *)(lVar3 + 0x334) = local_2c, local_2c != 0)) {
        aw882xx_monitor_start(lVar3 + 0x2a8);
      }
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// monitor_update_store @ 0011be68 size=596
// signature: undefined monitor_update_store(void)
// callers: []
//------------------------------------------------------------

long monitor_update_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  size_t *psVar1;
  int iVar2;
  long *plVar3;
  undefined4 *puVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int local_54;
  size_t *local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_54 = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0x68);
  if (param_4 != 0) {
    iVar2 = kstrtouint(param_3,0,&local_54);
    if (iVar2 < 0) {
      param_4 = (long)iVar2;
    }
    else {
      lVar5 = (*(long **)(lVar7 + 0x78))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(lVar7 + 0x78);
      }
      _printk(&DAT_0011f3b1,lVar5,"monitor_update_store",local_54);
      if (local_54 != 0) {
        lVar5 = lVar7 + 0x2a8;
        lVar6 = (*(long **)(lVar7 + 0x78))[0xe];
        if (lVar6 == 0) {
          lVar6 = **(long **)(lVar7 + 0x78);
        }
        _printk(&DAT_00120075,lVar6,"aw882xx_monitor_stop");
        *(undefined4 *)(lVar7 + 0x274) = 0;
        *(undefined1 *)(lVar7 + 0x390) = 0;
        if (*(char *)(lVar7 + 0x394) == '\0') {
          cancel_delayed_work_sync(lVar5);
        }
        *(undefined1 *)(lVar7 + 0x330) = 0;
        if (*(long *)(lVar7 + 0x378) != 0) {
          devm_kfree(*(undefined8 *)(lVar7 + 0x78));
          *(undefined8 *)(lVar7 + 0x378) = 0;
        }
        if (*(long *)(lVar7 + 0x388) != 0) {
          devm_kfree(*(undefined8 *)(lVar7 + 0x78));
          *(undefined8 *)(lVar7 + 0x388) = 0;
        }
        local_50 = (size_t *)0x0;
        *(undefined8 *)(lVar7 + 0x380) = 0;
        *(undefined8 *)(lVar7 + 0x388) = 0;
        *(undefined8 *)(lVar7 + 0x370) = 0;
        *(undefined8 *)(lVar7 + 0x378) = 0;
        *(undefined8 *)(lVar7 + 0x360) = 0;
        *(undefined8 *)(lVar7 + 0x368) = 0;
        *(undefined8 *)(lVar7 + 0x350) = 0;
        *(undefined8 *)(lVar7 + 0x358) = 0;
        *(undefined8 *)(lVar7 + 0x340) = 0;
        *(undefined8 *)(lVar7 + 0x348) = 0;
        *(undefined8 *)(lVar7 + 0x330) = 0;
        *(undefined8 *)(lVar7 + 0x338) = 0;
        iVar2 = request_firmware(&local_50,lVar7 + 0x88,*(undefined8 *)(lVar7 + 0x78));
        plVar3 = *(long **)(lVar7 + 0x78);
        if (iVar2 < 0) {
          lVar5 = plVar3[0xe];
          if (lVar5 == 0) {
            lVar5 = *plVar3;
          }
          _printk(&DAT_0012002c,lVar5,"aw_monitor_real_time_update_monitor",lVar7 + 0x88);
        }
        else {
          puVar4 = (undefined4 *)devm_kmalloc(plVar3,*local_50 + 4,0xdc0);
          psVar1 = local_50;
          if (puVar4 != (undefined4 *)0x0) {
            *puVar4 = (int)*local_50;
            memcpy(puVar4 + 1,(void *)local_50[1],*local_50);
            release_firmware(psVar1);
            iVar2 = aw882xx_monitor_parse_fw(lVar5,puVar4 + 1,*puVar4);
            plVar3 = *(long **)(lVar7 + 0x78);
            if (iVar2 < 0) {
              lVar5 = plVar3[0xe];
              if (lVar5 == 0) {
                lVar5 = *plVar3;
              }
              _printk(&DAT_001208d8,lVar5,"aw_monitor_real_time_update_monitor");
              devm_kfree(*(undefined8 *)(lVar7 + 0x78),puVar4);
              param_4 = (long)iVar2;
            }
            else {
              devm_kfree(plVar3,puVar4);
              aw882xx_monitor_start(lVar5);
            }
            goto LAB_0011bec0;
          }
          iVar2 = -0xc;
        }
        release_firmware(local_50);
        param_4 = (long)iVar2;
      }
    }
  }
LAB_0011bec0:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aw_dev_set_channal_mode @ 0011c0c0 size=160
// signature: undefined aw_dev_set_channal_mode(void)
// callers: []
//------------------------------------------------------------

int aw_dev_set_channal_mode(long param_1,long param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (3 < param_3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x11c160);
    (*pcVar1)();
  }
  if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x822b,0x11c110);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(param_1 + 0x4d0))
                    (*(undefined8 *)(param_1 + 0x80),*(undefined4 *)(param_2 + 0xc),
                     *(undefined4 *)(param_2 + 0x10),
                     *(undefined2 *)(param_2 + (ulong)param_3 * 2 + 4));
  if (iVar2 < 0) {
    lVar3 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar3 == 0) {
      lVar3 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_0012117d,lVar3,"aw_dev_set_channal_mode");
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// aw882xx_spin_set_record_val @ 0011c164 size=396
// signature: undefined aw882xx_spin_set_record_val(void)
// callers: [aw882xx_mute, aw_dev_reg_fw_update]
//------------------------------------------------------------

int aw882xx_spin_set_record_val(long param_1)

{
  undefined8 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  ulong local_38;
  undefined4 local_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  mutex_lock(&g_spin_lock);
  if (g_spin_mode == 1) {
    iVar4 = aw882xx_dsp_write_spin(g_spin_value);
    if (iVar4 != 0) {
LAB_0011c1b8:
      mutex_unlock(&g_spin_lock);
      goto LAB_0011c1c4;
    }
  }
  else if ((g_spin_mode & 0xfffffffe) == 2) {
    local_48 = *(undefined8 *)(param_1 + 0x3d0);
    uStack_40 = *(undefined8 *)(param_1 + 0x3d8);
    uVar1 = uStack_40;
    local_38 = *(ulong *)(param_1 + 0x3e0);
    local_30 = *(undefined4 *)(param_1 + 1000);
    if (3 < g_spin_value) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11c2f0);
      (*pcVar3)();
    }
    uStack_40._4_4_ = (undefined4)((ulong)*(undefined8 *)(param_1 + 0x3d8) >> 0x20);
    uVar2 = uStack_40._4_4_;
    uStack_40 = uVar1;
    if (*(int *)(*(code **)(param_1 + 0x4d0) + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822a,0x11c258);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(param_1 + 0x4d0))
                      (*(undefined8 *)(param_1 + 0x80),uVar2,
                       *(ulong *)(param_1 + 0x3e0) & 0xffffffff,
                       *(undefined2 *)((long)&local_48 + (ulong)g_spin_value * 2 + 4));
    if (iVar4 < 0) {
      lVar5 = (*(long **)(param_1 + 0x78))[0xe];
      if (lVar5 == 0) {
        lVar5 = **(long **)(param_1 + 0x78);
      }
      _printk(&DAT_0012117d,lVar5,"aw_dev_set_channal_mode");
      goto LAB_0011c1b8;
    }
  }
  else {
    lVar5 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(param_1 + 0x78);
    }
    _printk(&DAT_001224f2,lVar5,"aw882xx_spin_set_record_val");
  }
  mutex_unlock(&g_spin_lock);
  lVar5 = (*(long **)(param_1 + 0x78))[0xe];
  if (lVar5 == 0) {
    lVar5 = **(long **)(param_1 + 0x78);
  }
  _printk(&DAT_00120d19,lVar5,"aw882xx_spin_set_record_val");
  iVar4 = 0;
LAB_0011c1c4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// aw882xx_spin_value_get @ 0011c2f4 size=92
// signature: undefined aw882xx_spin_value_get(void)
// callers: [aw882xx_get_spin]
//------------------------------------------------------------

undefined8 aw882xx_spin_value_get(undefined8 param_1,undefined4 *param_2,uint param_3)

{
  undefined8 uVar1;
  
  if (((g_spin_mode & 0xfffffffe) == 2) || ((param_3 & 1) == 0)) {
    uVar1 = 0;
    *param_2 = g_spin_value;
  }
  else if (g_spin_mode == 1) {
    uVar1 = aw882xx_dsp_read_spin(param_2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// aw882xx_spin_value_set @ 0011c354 size=244
// signature: undefined aw882xx_spin_value_set(void)
// callers: [aw882xx_set_spin]
//------------------------------------------------------------

undefined4 aw882xx_spin_value_set(long param_1,undefined4 param_2,ulong param_3)

{
  bool bVar1;
  undefined4 uVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 uVar5;
  
  mutex_lock(&g_spin_lock);
  bVar1 = (g_spin_mode & 0xfffffffe) != 2;
  if ((param_3 & 1) == 0) {
    if (!bVar1) {
      uVar5 = 0;
      goto LAB_0011c3b8;
    }
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    puVar3 = &DAT_00123187;
  }
  else {
    if (!bVar1) {
      uVar5 = 1;
LAB_0011c3b8:
      uVar2 = aw_reg_write_spin(param_1,param_2,uVar5);
      goto LAB_0011c3d4;
    }
    if (g_spin_mode == 1) {
      uVar2 = aw882xx_dsp_write_spin(param_2);
      goto LAB_0011c3d4;
    }
    lVar4 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)(param_1 + 0x78);
    }
    puVar3 = &DAT_0011ed21;
  }
  _printk(puVar3,lVar4,"aw882xx_spin_value_set");
  uVar2 = 0;
LAB_0011c3d4:
  g_spin_value = param_2;
  mutex_unlock(&g_spin_lock);
  return uVar2;
}



//------------------------------------------------------------
// aw_reg_write_spin @ 0011c448 size=524
// signature: undefined aw_reg_write_spin(void)
// callers: [aw882xx_spin_value_set]
//------------------------------------------------------------

int aw_reg_write_spin(long param_1,uint param_2,ulong param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  long *local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  ulong local_68;
  undefined4 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_80 = (long *)0x0;
  iVar3 = aw882xx_dev_get_list_head(&local_80);
  if (iVar3 == 0) {
    if ((g_spin_mode == 3) && ((param_3 & 1) != 0)) {
      plVar7 = local_80;
      do {
        plVar7 = (long *)*plVar7;
        if (plVar7 == local_80) goto LAB_0011c4cc;
        iVar3 = aw882xx_dsp_set_mixer_en(plVar7 + -0xa1,1);
      } while (iVar3 == 0);
    }
    else {
LAB_0011c4cc:
      usleep_range_state(100000,0x186aa,2);
      plVar7 = (long *)*local_80;
      if (plVar7 != local_80) {
        do {
          local_78 = plVar7[-0x27];
          uStack_70 = plVar7[-0x26];
          lVar5 = uStack_70;
          local_68 = plVar7[-0x25];
          local_60 = (int)plVar7[-0x24];
          if (3 < param_2) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x11c650);
            (*pcVar2)();
          }
          uStack_70._4_4_ = (undefined4)((ulong)plVar7[-0x26] >> 0x20);
          uVar1 = uStack_70._4_4_;
          uStack_70 = lVar5;
          if (*(int *)((code *)plVar7[-7] + -4) != -0x16b29af5) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11c56c);
            (*pcVar2)();
          }
          iVar3 = (*(code *)plVar7[-7])
                            (plVar7[-0x91],uVar1,plVar7[-0x25] & 0xffffffff,
                             *(undefined2 *)((long)&local_78 + (ulong)param_2 * 2 + 4));
          if (iVar3 < 0) {
            plVar6 = (long *)plVar7[-0x92];
            lVar5 = plVar6[0xe];
            if (lVar5 == 0) {
              lVar5 = *plVar6;
            }
            _printk(&DAT_0012117d,lVar5,"aw_dev_set_channal_mode");
            plVar7 = (long *)plVar7[-0x92];
            lVar5 = plVar7[0xe];
            if (lVar5 == 0) {
              lVar5 = *plVar7;
            }
            puVar4 = &DAT_00121786;
            goto LAB_0011c63c;
          }
          if (((g_spin_mode == 3) && ((param_3 & 1) != 0)) &&
             (iVar3 = aw882xx_dsp_set_mixer_en(param_1,0), iVar3 != 0)) goto LAB_0011c5a0;
          plVar7 = (long *)*plVar7;
        } while (plVar7 != local_80);
      }
      iVar3 = 0;
    }
  }
  else {
    lVar5 = (*(long **)(param_1 + 0x78))[0xe];
    if (lVar5 == 0) {
      lVar5 = **(long **)(param_1 + 0x78);
    }
    puVar4 = &DAT_0011eb45;
LAB_0011c63c:
    _printk(puVar4,lVar5,"aw_reg_write_spin");
  }
LAB_0011c5a0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// aw882xx_spin_init @ 0011c658 size=772
// signature: undefined aw882xx_spin_init(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

int aw882xx_spin_init(uint *param_1)

{
  uint *puVar1;
  char *__s1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  char *local_50;
  char *local_48;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  puVar7 = param_1 + -0xd6;
  local_38 = *(long *)(lVar4 + 0x638);
  local_50 = (char *)0x0;
  iVar2 = of_property_read_string(*(undefined8 *)(*(long *)puVar7 + 0x2e8),"spin-mode",&local_50);
  __s1 = local_50;
  if (iVar2 < 0) {
    g_spin_mode = 0;
    lVar4 = (*(long **)puVar7)[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)puVar7;
    }
    puVar3 = &DAT_001233fc;
  }
  else {
    iVar2 = strcmp(local_50,"dsp_spin");
    if (iVar2 != 0) {
      iVar2 = strcmp(__s1,"reg_spin");
      if (iVar2 == 0) {
        g_spin_mode = 2;
      }
      else {
        iVar2 = strcmp(__s1,"reg_mixer_spin");
        if (iVar2 != 0) {
          g_spin_mode = 0;
          goto LAB_0011c8c8;
        }
        g_spin_mode = 3;
      }
      local_48 = (char *)0x0;
      local_3c = 0;
      iVar2 = of_property_read_string
                        (*(undefined8 *)(*(long *)puVar7 + 0x2e8),"spin-data",&local_48);
      if (iVar2 < 0) {
        lVar4 = (*(long **)puVar7)[0xe];
        if (lVar4 == 0) {
          lVar4 = **(long **)puVar7;
        }
        _printk(&DAT_00123a82,lVar4,"aw_parse_spin_table_dt");
        goto LAB_0011c8f4;
      }
      iVar2 = sscanf(local_48,"%c %c %c %c",(uchar *)&local_3c,(uchar *)((ulong)&local_3c | 1),
                     (uchar *)((ulong)&local_3c | 2),(uchar *)((ulong)&local_3c | 3));
      if ((iVar2 == 4) && ((local_3c & 0xff) - 0x4c < 0x27)) {
        puVar1 = param_1 + 5;
        puVar5 = param_1 + 6;
        puVar6 = puVar1;
        switch(local_3c & 0xff) {
        case 0x4c:
        case 0x6c:
          break;
        default:
          goto switchD_0011c7dc_caseD_4d;
        case 0x52:
        case 0x72:
          puVar6 = puVar5;
        }
        *(short *)(param_1 + 1) = (short)*puVar6;
        puVar6 = puVar5;
        switch(local_3c >> 8 & 0xff) {
        case 0x4c:
        case 0x6c:
          puVar6 = puVar1;
          break;
        default:
          goto switchD_0011c7dc_caseD_4d;
        case 0x52:
        case 0x72:
          break;
        }
        *(short *)((long)param_1 + 6) = (short)*puVar6;
        puVar6 = puVar5;
        switch(local_3c >> 0x10 & 0xff) {
        case 0x4c:
        case 0x6c:
          puVar6 = puVar1;
          break;
        default:
          goto switchD_0011c7dc_caseD_4d;
        case 0x52:
        case 0x72:
          break;
        }
        *(short *)(param_1 + 2) = (short)*puVar6;
        switch(local_3c >> 0x18) {
        case 0x4c:
        case 0x6c:
          puVar5 = puVar1;
        case 0x52:
        case 0x72:
          *(short *)((long)param_1 + 10) = (short)*puVar5;
          goto LAB_0011c8c8;
        }
      }
switchD_0011c7dc_caseD_4d:
      lVar4 = (*(long **)puVar7)[0xe];
      if (lVar4 == 0) {
        lVar4 = **(long **)puVar7;
      }
      _printk(&DAT_0011f160,lVar4,"aw_parse_spin_table_dt",local_48);
      iVar2 = -0x16;
      goto LAB_0011c8f4;
    }
    g_spin_mode = 1;
LAB_0011c8c8:
    lVar4 = (*(long **)puVar7)[0xe];
    if (lVar4 == 0) {
      lVar4 = **(long **)puVar7;
    }
    puVar3 = &DAT_0011f3d8;
  }
  _printk(puVar3,lVar4,"aw_parse_spin_dts",g_spin_mode);
  iVar2 = 0;
LAB_0011c8f4:
  *param_1 = (uint)(g_spin_mode != 0);
  lVar4 = (*(long **)puVar7)[0xe];
  if (lVar4 == 0) {
    lVar4 = **(long **)puVar7;
  }
  _printk(&DAT_001203ca,lVar4,"aw882xx_spin_init");
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 0011c960 size=116
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_0011dcc8,"aw882xx_i2c_init","v2.0.2.1");
  iVar1 = i2c_register_driver(&__this_module,&aw882xx_i2c_driver);
  if (iVar1 != 0) {
    _printk(&DAT_00122129,"aw882xx_i2c_init");
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0011c9d8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&aw882xx_i2c_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00127000 size=1
// signature: undefined _printk(void)
// callers: [aw_cali_misc_ops, aw882xx_algo_volume_get, aw882xx_dsp_hmute_en, aw882xx_hw_params, aw_check_dsp_reg_num_v1, aw_dev_parse_fade_flag_dt, aw882xx_i2c_read, aw_dev_parse_data_by_sec_type, aw_cali_svc_get_devs_cali_re, aw_dev_set_channal_mode, aw882xx_dev_check_ef_lock, aw882xx_set_rx_en, aw_cali_svc_get_devs_st, vol_offset_store, aw882xx_set_fmt, aw_cali_misc_write_dsp, aw_algo_auth_misc_open, aw882xx_dsp_read_vol_offset, aw_check_sum, aw882xx_device_start, aw882xx_start_pa, cali_f0_show, aw_pid_2113_frcset_check, aw882xx_dsp_read_run_state_avg, aw882xx_dsp_read_f0, aw882xx_dsp_read_te, aw_pid_2013_dev_init, aw_cali_svc_cali_f0_q, aw882xx_profile_set, init_module, aw882xx_dsp_noise_en, aw882xx_i2c_remove, aw882xx_set_copp_en, aw_pid_2113_reg_force_set, aw_cali_svc_cali_f0, aw_parsing_bin_file, aw882xx_dsp_write_volume, dbg_prof_store, aw_cali_svc_get_devs_cali_f0, aw_write_msg_to_dsp_v_1_0_0_0, aw88xx_dev_get_profile_name, aw882xx_spin_value_set, aw_cali_parse_re_dt, aw882xx_volume_get, aw882xx_ramp_params_get, aw_cali_svc_get_devs_re_range, aw882xx_dsp_read_dsp_msg, aw882xx_dsp_write_dsp_msg, aw882xx_mute, aw882xx_dev_probe, aw882xx_monitor_info, aw882xx_cali_deinit, aw882xx_volume_put, aw882xx_dev_get_int_status, aw882xx_set_tx_en, aw882xx_dsp_read_cali_data, aw882xx_append_channel_suffix, aw882xx_monitor_start, aw_cali_class_cali_f0_store, aw882xx_dsp_write_vmax, aw882xx_dsp_read_f0_q, aw_dev_mode1_pll_check, aw882xx_dev_parse_acf, aw882xx_request_firmware, aw882xx_dsp_set_mixer_en, aw_cali_svc_devs_cali_mode_enable, aw_cali_class_f0_show, re_show_show, cali_re_store, aw882xx_dev_algo_auth_set, aw882xx_hw_reset, aw882xx_dsp_set_copp_module_en, aw_cali_svc_dev_get_f0_q, aw_cali_svc_get_devs_te, aw882xx_dsp_parse_port_id_dt, aw_cali_class_re_show, aw882xx_dsp_write_ramp_params, aw882xx_ramp_params_put, aw_dev_monitor_hw_status, aw882xx_monitor_set, aw882xx_hw_status_get, aw_cali_svc_get_devs_r0, aw882xx_dsp_get_afe_module_en, aw882xx_interrupt_work, aw_dev_switch, awrw_show, aw_cali_class_cali_re_store, aw882xx_i2c_probe, aw_dev_parse_reg_bin_with_hdr, aw882xx_dev_get_profile_count, aw882xx_device_stop, phase_sync_store, aw882xx_cali_init, aw882xx_spin_init, aw882xx_codec_remove, aw882xx_shutdown, aw882xx_append_i2c_suffix, aw882xx_spin_set_record_val, aw_cali_misc_read, aw_reg_write_spin, aw882xx_interrupt_init, monitor_store, aw_dev_prof_parse_multi_bin, aw882xx_ramp_switch_set, aw882xx_get_rx_en, aw_monitor_work_func, aw_pid_2308_get_voltage_offset, aw_algo_auth_misc_unlocked_ioctl, aw882xx_i2c_shutdown, aw882xx_get_spin, aw882xx_dev_get_prof_name, aw882xx_codec_probe, aw882xx_init, aw882xx_dsp_parse_topo_id_dt, awrw_store, aw_cali_misc_switch_dev, aw_cali_svc_cali_re, aw_cali_svc_set_devs_re_str, aw_check_soc_app_num_v1, aw_check_data_version, aw882xx_dev_get_prof_data, aw_cali_svc_dev_get_f0, aw882xx_switch_info, f0_show_show, aw882xx_dsp_read_st, aw882xx_switch_set, aw_cali_misc_unlocked_ioctl, aw882xx_monitor_get, aw882xx_set_dai_sysclk, aw_cali_svc_get_cmd_form_str, aw882xx_dsp_cali_en, aw882xx_startup, aw882xx_dsp_write_cali_re, aw_cali_misc_open, aw_cali_class_cali_f0_show, aw882xx_monitor_init, aw_cali_misc_read_dsp, aw_get_irq_type, aw_get_irq_nobst_type, aw882xx_dsp_write_params, print_dbg_store, aw882xx_i2c_write, aw_check_register_num_v1, cali_store, aw882xx_dsp_write_cali_cfg, aw882xx_monitor_parse_fw, aw882xx_dev_set_intmask, aw_cali_svc_dev_get_re, aw882xx_dev_mute, aw882xx_algo_auth_tlv_rw, aw882xx_voltage_offset_get, aw_componet_codec_register, aw882xx_dsp_read_r0, aw_dev_i2s_enable, aw882xx_dsp_write_spin, aw882xx_dsp_get_dc_status, aw882xx_dsp_read_vmax, aw_algo_auth_misc_compat_ioctl, aw882xx_dev_init, aw882xx_i2c_write_bits, aw_cali_svc_get_devs_cali_f0_q, aw882xx_dev_parse_check_acf, aw_read_msg_from_dsp_v_1_0_0_0, aw_cali_svc_dev_cali_mode_en, aw882xx_dev_init_cali_re, aw_parse_bin_header_1_0_0, aw_cali_store_cali_re, aw882xx_dsp_write_vol_offset, aw_monitor_get_data_from_table, aw_cali_class_cali_re_show, aw_cali_misc_write, aw_dev_reg_fw_update, aw_cali_svc_get_devs_f0, aw882xx_dev_set_profile_index, aw_monitor_write_data_to_table, aw_cali_svc_cali_cmd, aw_cali_svc_run_mute, aw882xx_get_tx_en, aw882xx_dev_iv_forbidden_output, aw882xx_dsp_set_afe_module_en, aw882xx_dsp_read_cali_cfg, aw_cali_misc_compat_ioctl, aw882xx_dev_reg_update, aw_monitor_get_data_form_system, aw_pid_2418_get_voltage_offset, aw882xx_set_spin, cali_time_store, aw882xx_ramp_switch_info, monitor_update_store, aw_class_re_range_show, aw882xx_monitor_deinit, aw882xx_dsp_read_spin, aw_algo_auth_misc_ops, aw882xx_iv_output_info, aw882xx_dsp_write_ramp_enable, cali_re_show, aw882xx_dsp_read_cali_re, aw882xx_dev_clear_int_status, fade_step_store, aw882xx_algo_volume_put, aw882xx_startup_work, aw882xx_irq, aw882xx_monitor_stop, aw_cali_class_time_store, aw882xx_profile_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00127008 size=1
// signature: undefined gpio_to_desc(void)
// callers: [aw882xx_interrupt_init, aw882xx_i2c_remove, aw882xx_hw_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value_cansleep @ 00127010 size=1
// signature: undefined gpiod_set_raw_value_cansleep(void)
// callers: [aw882xx_hw_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value_cansleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00127018 size=1
// signature: undefined __const_udelay(void)
// callers: [aw882xx_hw_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 00127020 size=1
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
// i2c_del_driver @ 00127028 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00127030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [monitor_update_store, aw882xx_append_channel_suffix, aw882xx_codec_probe, aw_componet_codec_register, aw_dev_prof_parse_multi_bin, aw882xx_dev_parse_acf, aw882xx_i2c_probe, aw882xx_append_i2c_suffix, aw882xx_request_firmware, aw882xx_monitor_parse_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00127038 size=1
// signature: undefined __mutex_init(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00127040 size=1
// signature: undefined devm_kfree(void)
// callers: [monitor_update_store, aw_dev_prof_parse_multi_bin, aw882xx_i2c_probe, aw882xx_monitor_parse_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00127048 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00127050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [aw882xx_dsp_parse_topo_id_dt, aw882xx_dev_probe, aw882xx_dsp_parse_port_id_dt, aw882xx_cali_init, aw_dev_parse_fade_flag_dt, aw882xx_i2c_probe, aw_cali_parse_re_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 00127058 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00127060 size=1
// signature: undefined msleep(void)
// callers: [aw_cali_svc_cali_re, aw882xx_i2c_probe, aw_cali_svc_cali_f0, aw882xx_request_firmware, aw_cali_svc_cali_f0_q]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00127068 size=1
// signature: undefined gpio_free(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00127070 size=1
// signature: undefined sysfs_create_group(void)
// callers: [aw882xx_cali_init, aw882xx_monitor_init, aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00127078 size=1
// signature: undefined mutex_lock(void)
// callers: [aw882xx_profile_set, aw882xx_dsp_get_afe_module_en, aw882xx_dsp_read_dsp_msg, aw882xx_i2c_remove, aw882xx_i2c_probe, aw882xx_dc_prot_work, aw882xx_request_firmware, aw882xx_dsp_write_spin, aw882xx_dsp_write_dsp_msg, aw882xx_i2c_shutdown, aw882xx_mute, aw882xx_startup_work, aw882xx_dev_probe, aw882xx_cali_init, aw882xx_cali_deinit, aw882xx_switch_set, aw_write_msg_to_dsp_v_1_0_0_0, aw882xx_dsp_read_spin, aw882xx_hal_monitor_work_get, aw882xx_spin_value_set, aw882xx_dsp_write_params, aw882xx_spin_set_record_val, aw_read_msg_from_dsp_v_1_0_0_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00127080 size=1
// signature: undefined mutex_unlock(void)
// callers: [aw882xx_profile_set, aw882xx_dsp_get_afe_module_en, aw882xx_dsp_read_dsp_msg, aw882xx_i2c_remove, aw882xx_i2c_probe, aw882xx_dc_prot_work, aw882xx_request_firmware, aw882xx_dsp_write_spin, aw882xx_dsp_write_dsp_msg, aw882xx_i2c_shutdown, aw882xx_mute, aw882xx_startup_work, aw882xx_dev_probe, aw882xx_cali_init, aw882xx_cali_deinit, aw882xx_switch_set, aw_write_msg_to_dsp_v_1_0_0_0, aw882xx_dsp_read_spin, aw882xx_hal_monitor_work_get, aw882xx_spin_value_set, aw882xx_dsp_write_params, aw882xx_spin_set_record_val, aw_read_msg_from_dsp_v_1_0_0_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00127088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [aw_cali_misc_read, aw_reg_write_spin, monitor_store, aw_cali_misc_ops, aw882xx_get_rx_en, aw882xx_dsp_hmute_en, aw_monitor_work_func, aw_pid_2308_get_voltage_offset, aw882xx_get_spin, aw882xx_hal_monitor_work_get, aw_dev_parse_fade_flag_dt, aw882xx_i2c_read, aw882xx_dev_get_volume, aw_cali_svc_get_devs_cali_re, vol_offset_show, awrw_store, aw_cali_misc_switch_dev, aw_cali_svc_cali_re, aw_cali_svc_set_devs_re_str, aw882xx_dev_check_ef_lock, aw_cali_svc_get_devs_st, aw_cali_svc_dev_get_f0, vol_offset_store, f0_show_show, aw882xx_dsp_read_st, aw882xx_device_start, algo_ver_show, aw882xx_dsp_cali_en, aw882xx_dsp_write_cali_re, aw_cali_misc_open, cali_f0_show, aw_pid_2113_frcset_check, aw_cali_class_cali_f0_show, aw882xx_monitor_init, aw882xx_dsp_algo_ver, aw882xx_dsp_read_te, aw_pid_2013_dev_init, aw_cali_svc_cali_f0_q, aw882xx_dsp_noise_en, aw882xx_hal_get_monitor_time, aw_cali_svc_cali_f0, dbg_prof_store, aw_cali_svc_dev_get_re, aw_cali_svc_get_devs_cali_f0, aw882xx_dev_set_volume, aw882xx_dev_mute, aw_pid_2055_dev_check, aw_cali_svc_get_devs_re_range, aw882xx_algo_auth_tlv_rw, aw882xx_voltage_offset_get, aw882xx_dsp_read_r0, aw882xx_dsp_get_dc_status, aw882xx_dev_probe, aw882xx_dev_get_int_status, aw882xx_i2c_write_bits, aw_cali_svc_get_devs_cali_f0_q, algo_state_show, aw882xx_append_channel_suffix, aw882xx_dsp_write_vol_offset, aw882xx_monitor_start, aw882xx_get_fade_out_time, aw_cali_class_cali_f0_store, aw882xx_dsp_read_f0_q, aw_dev_mode1_pll_check, aw882xx_dev_parse_acf, rw_show, aw_cali_class_cali_re_show, aw882xx_request_firmware, aw882xx_dsp_set_mixer_en, rw_store, aw_dev_reg_fw_update, aw_cali_class_f0_show, reg_store, aw_cali_svc_get_devs_f0, re_show_show, aw882xx_dev_algo_auth_set, aw882xx_get_tx_en, aw_monitor_get_data_form_system, aw_pid_2418_get_voltage_offset, aw_cali_svc_dev_get_f0_q, aw_cali_svc_get_devs_te, cali_time_store, aw882xx_get_fade_in_time, aw_cali_class_re_show, monitor_update_store, aw_class_re_range_show, aw_algo_auth_misc_ops, aw_dev_monitor_hw_status, dsp_re_show, reg_show, aw882xx_dsp_write_ramp_enable, cali_re_show, aw_cali_svc_get_devs_r0, aw882xx_dsp_read_cali_re, aw882xx_dev_clear_int_status, aw882xx_interrupt_work, fade_step_store, awrw_show, aw_cali_class_cali_re_store, aw882xx_i2c_probe, phase_sync_store, aw882xx_cali_init, aw882xx_spin_init, aw882xx_append_i2c_suffix, aw882xx_spin_set_record_val, aw_cali_class_time_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 00127090 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [aw882xx_interrupt_init, aw882xx_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00127098 size=1
// signature: undefined devm_free_irq(void)
// callers: [aw882xx_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 001270a0 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [aw882xx_cali_deinit, aw882xx_monitor_deinit, aw882xx_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 001270a8 size=1
// signature: undefined vfree(void)
// callers: [aw882xx_i2c_remove, aw882xx_request_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001270b0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [aw882xx_interrupt_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001270b8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [monitor_update_store, aw882xx_append_channel_suffix, aw_write_msg_to_dsp_v_1_0_0_0, aw_componet_codec_register, aw_dev_prof_parse_multi_bin, aw882xx_dev_parse_acf, aw882xx_append_i2c_suffix, aw882xx_request_firmware, aw_dev_parse_reg_bin_with_hdr, aw_read_msg_from_dsp_v_1_0_0_0, aw882xx_dsp_write_dsp_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001270c0 size=1
// signature: undefined dev_set_name(void)
// callers: [aw_componet_codec_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 001270c8 size=1
// signature: undefined i2c_transfer(void)
// callers: [awrw_show, aw882xx_i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001270d8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [aw882xx_i2c_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer_buffer_flags @ 001270e0 size=1
// signature: undefined i2c_transfer_buffer_flags(void)
// callers: [awrw_store, aw882xx_i2c_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer_buffer_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001270e8 size=1
// signature: undefined kfree(void)
// callers: [awrw_store, aw_cali_misc_ops, awrw_show, aw882xx_i2c_write, aw_cali_misc_read_dsp, aw_cali_misc_write, aw_dev_parse_reg_bin_with_hdr, aw882xx_dsp_write_dsp_msg, aw_cali_misc_write_dsp, aw_write_msg_to_dsp_v_1_0_0_0, aw882xx_dev_init, aw882xx_dev_deinit, aw_read_msg_from_dsp_v_1_0_0_0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001270f0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [aw882xx_mute, aw882xx_irq, aw882xx_start_pa, aw882xx_monitor_start, aw882xx_codec_probe, aw882xx_dc_prot_work, aw_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 001270f8 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [aw882xx_mute, monitor_update_store, aw882xx_monitor_deinit, aw882xx_switch_set, aw882xx_monitor_stop, aw882xx_dc_prot_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_pcm_format_width @ 00127100 size=1
// signature: undefined snd_pcm_format_width(void)
// callers: [aw882xx_hw_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_pcm_format_width(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00127108 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [algo_ver_show, aw_cali_class_time_show, aw_cali_misc_read, re_range_show, dbg_prof_show, cali_f0_show, aw_cali_class_cali_f0_show, aw882xx_dsp_algo_ver, aw_cali_class_re_show, aw_class_re_range_show, print_dbg_show, fade_step_show, dsp_re_show, reg_show, cali_re_show, algo_state_show, vol_offset_show, aw882xx_append_channel_suffix, phase_sync_show, awrw_show, rw_show, drv_ver_show, aw_cali_class_cali_re_show, cali_time_show, aw882xx_request_firmware, monitor_show, aw_cali_class_f0_show, f0_show_show, re_show_show, aw882xx_append_i2c_suffix]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00127110 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [aw882xx_switch_info, aw882xx_monitor_info, aw882xx_ramp_switch_info, aw882xx_append_channel_suffix, aw882xx_iv_output_info, aw882xx_append_i2c_suffix]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00127118 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [aw882xx_switch_info, aw882xx_monitor_info, aw882xx_ramp_switch_info, aw882xx_append_channel_suffix, aw882xx_iv_output_info, aw882xx_append_i2c_suffix]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00127120 size=1
// signature: undefined alloc_workqueue(void)
// callers: [aw882xx_codec_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00127130 size=1
// signature: undefined init_timer_key(void)
// callers: [aw882xx_codec_probe, aw882xx_monitor_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00127138 size=1
// signature: undefined destroy_workqueue(void)
// callers: [aw882xx_codec_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 00127140 size=1
// signature: undefined request_firmware(void)
// callers: [monitor_update_store, aw882xx_request_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 00127148 size=1
// signature: undefined vzalloc(void)
// callers: [aw882xx_request_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 00127150 size=1
// signature: undefined release_firmware(void)
// callers: [monitor_update_store, aw882xx_request_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00127158 size=1
// signature: undefined strscpy(void)
// callers: [aw882xx_switch_info, aw882xx_monitor_info, aw882xx_ramp_switch_info, aw882xx_iv_output_info, aw88xx_dev_get_profile_name, aw882xx_profile_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00127160 size=1
// signature: size_t strlen(char * __s)
// callers: [aw_cali_svc_get_cmd_form_str, aw882xx_switch_info, aw882xx_monitor_info, aw882xx_ramp_switch_info, aw882xx_iv_output_info, aw88xx_dev_get_profile_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00127178 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [aw_cali_misc_read, aw882xx_algo_auth_tlv_rw, aw_cali_misc_ops, aw_algo_auth_misc_ops, aw_cali_misc_read_dsp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00127180 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [aw_cali_misc_write_dsp, aw882xx_algo_auth_tlv_rw, aw_cali_misc_ops, aw_algo_auth_misc_ops, aw_cali_misc_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00127188 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [aw_cali_misc_write_dsp, aw882xx_algo_auth_tlv_rw, aw_cali_misc_ops, aw_algo_auth_misc_ops, aw882xx_dev_parse_acf, aw_cali_misc_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00127198 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [rw_store, aw882xx_spin_init, awrw_store, reg_store, aw_cali_misc_switch_dev, aw_cali_svc_set_devs_re_str, vol_offset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001271a0 size=1
// signature: undefined kstrtouint(void)
// callers: [rw_store, phase_sync_store, monitor_update_store, dbg_prof_store, print_dbg_store, monitor_store, fade_step_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001271a8 size=1
// signature: undefined __kmalloc(void)
// callers: [aw_cali_misc_write_dsp, awrw_store, aw_write_msg_to_dsp_v_1_0_0_0, aw_cali_misc_ops, awrw_show, aw882xx_dev_parse_acf, aw_cali_misc_read_dsp, aw_cali_misc_write, aw_dev_parse_reg_bin_with_hdr, aw_read_msg_from_dsp_v_1_0_0_0, aw882xx_dsp_write_dsp_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_add_component_controls @ 001271b0 size=1
// signature: undefined snd_soc_add_component_controls(void)
// callers: [aw882xx_codec_probe, aw882xx_request_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_add_component_controls(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 001271b8 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [aw882xx_i2c_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001271d8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [aw882xx_cali_init, aw882xx_spin_init, aw882xx_monitor_init, aw882xx_dev_parse_acf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001271e0 size=1
// signature: undefined of_property_read_string(void)
// callers: [aw882xx_cali_init, aw882xx_spin_init, aw882xx_monitor_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 001271e8 size=1
// signature: undefined __class_register(void)
// callers: [aw882xx_cali_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_create_file_ns @ 001271f0 size=1
// signature: undefined class_create_file_ns(void)
// callers: [aw882xx_cali_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 001271f8 size=1
// signature: undefined misc_register(void)
// callers: [aw882xx_dev_probe, aw882xx_cali_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 00127200 size=1
// signature: undefined misc_deregister(void)
// callers: [aw882xx_cali_deinit, aw882xx_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_remove_file_ns @ 00127208 size=1
// signature: undefined class_remove_file_ns(void)
// callers: [aw882xx_cali_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00127210 size=1
// signature: undefined class_unregister(void)
// callers: [aw882xx_cali_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00127218 size=1
// signature: undefined usleep_range_state(void)
// callers: [aw882xx_device_stop, aw_pid_2113_dev_init, aw882xx_dev_mute, aw_pid_2055_dev_check, aw_cali_svc_dev_get_re, aw_reg_write_spin, aw882xx_device_start, aw_dev_mode1_pll_check, aw_cali_svc_dev_get_f0_q, aw_cali_svc_dev_get_f0]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00127220 size=1
// signature: undefined kstrtoint(void)
// callers: [cali_time_store, aw_cali_class_time_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 00127228 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [aw_cali_svc_get_cmd_form_str]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00127230 size=1
// signature: undefined __check_object_size(void)
// callers: [aw_cali_misc_write_dsp, aw_cali_misc_read, aw_cali_misc_ops, aw_cali_misc_read_dsp, aw_cali_misc_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __copy_overflow @ 00127238 size=1
// signature: undefined __copy_overflow(void)
// callers: [aw_cali_misc_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __copy_overflow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00127240 size=1
// signature: undefined strnstr(void)
// callers: [aw_cali_misc_switch_dev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00127248 size=1
// signature: undefined __list_add_valid(void)
// callers: [aw882xx_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00127250 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [aw_monitor_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00127258 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [aw_monitor_get_data_form_system]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00127260 size=1
// signature: undefined power_supply_get_property(void)
// callers: [aw_monitor_get_data_form_system]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



