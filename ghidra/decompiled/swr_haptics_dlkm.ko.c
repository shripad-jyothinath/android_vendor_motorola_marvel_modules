// Decompiled by Ghidra 12.2
// Program: swr_haptics_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// swr_hap_writeable_register @ 001002fc size=60
// signature: undefined swr_hap_writeable_register(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_hap_writeable_register(undefined8 param_1,uint param_2)

{
  if (param_2 < 0x3001) {
    return 0;
  }
  if ((param_2 - 0x3008 < 6) || (param_2 == 0x3080)) {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// swr_hap_readable_register @ 0010033c size=12
// signature: undefined swr_hap_readable_register(void)
// callers: []
//------------------------------------------------------------

bool swr_hap_readable_register(undefined8 param_1,uint param_2)

{
  return 0x3000 < param_2;
}



//------------------------------------------------------------
// swr_hap_volatile_register @ 0010034c size=20
// signature: undefined swr_hap_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool swr_hap_volatile_register(undefined8 param_1,int param_2)

{
  return param_2 - 0x3080U < 3;
}



//------------------------------------------------------------
// swr_haptics_probe @ 00100364 size=1196
// signature: undefined swr_haptics_probe(void)
// callers: []
//------------------------------------------------------------

ulong swr_haptics_probe(long param_1)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  ulong uVar10;
  undefined8 uVar11;
  undefined1 local_64 [4];
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar8 = sp_el0;
  lVar7 = param_1 + 0x48;
  local_48 = *(long *)(lVar8 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x330);
  local_64[0] = 0;
  plVar5 = (long *)devm_kmalloc(lVar7,0x68,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar6 = 0xfffffff4;
    goto LAB_001007b8;
  }
  *plVar5 = lVar7;
  plVar5[1] = param_1;
  *(undefined1 *)((long)plVar5 + 0x5f) = 100;
  iVar2 = of_device_get_match_data(lVar7);
  if (iVar2 == 1) {
    *(byte *)((long)plVar5 + 0x61) = *(byte *)((long)plVar5 + 0x61) | 1;
  }
  *(long **)(param_1 + 0xe0) = plVar5;
  if (param_1 == 0) {
    _dev_err(0x48,"%s: get swr_haptics_dev failed\n","swr_haptics_parse_port_mapping");
LAB_00100674:
    lVar7 = *plVar5;
    pcVar9 = "%s: failed to parse swr port mapping, rc=%d\n";
    uVar10 = 0xffffffea;
    uVar6 = 0xffffffea;
LAB_001007b0:
    _dev_err(lVar7,pcVar9,"swr_haptics_probe",uVar10);
  }
  else {
    local_50 = 0;
    local_60 = 0;
    local_58 = 0;
    iVar2 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x330),"qcom,rx_swr_ch_map",&local_60,5,0);
    if (iVar2 < 0) {
      _dev_err(*plVar5,"%s: Get qcom,rx_swr_ch_map failed, rc=%d\n","swr_haptics_parse_port_mapping"
               ,iVar2);
      goto LAB_00100674;
    }
    *(char *)(plVar5 + 4) = (char)local_60;
    *(char *)(plVar5 + 5) = (char)((ulong)local_60 >> 0x20);
    *(char *)((long)plVar5 + 0x21) = (char)local_58;
    *(undefined4 *)((long)plVar5 + 0x24) = local_58._4_4_;
    *(char *)((long)plVar5 + 0x29) = (char)local_50;
    uVar6 = devm_regulator_get(*plVar5,"swr-slave");
    plVar5[6] = uVar6;
    if (uVar6 < 0xfffffffffffff001) {
      lVar8 = of_find_property(uVar11,"qcom,hpwr-supply",0);
      if (lVar8 == 0) {
LAB_001004d0:
        if (*(char *)((long)plVar5 + 0x5c) == '\0') {
          uVar3 = regulator_enable(plVar5[6]);
          if ((int)uVar3 < 0) {
            uVar6 = (ulong)uVar3;
            iVar2 = ___ratelimit(swr_haptics_slave_enable__rs,"swr_haptics_slave_enable");
            if (iVar2 != 0) {
              _dev_err(*plVar5,"%s: enable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_enable"
                       ,uVar6);
            }
            lVar7 = *plVar5;
            pcVar9 = "%s: enable swr-slave-vdd failed, rc=%d\n";
            goto LAB_001007a4;
          }
          *(undefined1 *)((long)plVar5 + 0x5c) = 1;
        }
        usleep_range_state(500,0x1fe,2);
        iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_64);
        bVar1 = iVar2 == 0;
        if (iVar2 == 0) {
LAB_001005cc:
          iVar2 = 0;
        }
        else {
          usleep_range_state(500,0x1fe,2);
          iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_64);
          bVar1 = iVar2 == 0;
          if (iVar2 == 0) goto LAB_001005cc;
          usleep_range_state(500,0x1fe,2);
          iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_64);
          bVar1 = iVar2 == 0;
          if (iVar2 == 0) goto LAB_001005cc;
          usleep_range_state(500,0x1fe,2);
          iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_64);
          bVar1 = iVar2 == 0;
          if (iVar2 == 0) goto LAB_001005cc;
          usleep_range_state(500,0x1fe,2);
          iVar2 = swr_get_logical_dev_num(param_1,*(undefined8 *)(param_1 + 0x3d8),local_64);
          bVar1 = iVar2 == 0;
        }
        if (bVar1) {
          *(undefined1 *)(param_1 + 0x40) = local_64[0];
          uVar6 = __devm_regmap_init_swr(param_1,swr_hap_regmap_config,0,0);
          plVar5[3] = uVar6;
          if (uVar6 < 0xfffffffffffff001) {
            uVar10 = snd_soc_register_component(lVar7,&swr_haptics_component,&haptics_dai,1);
            uVar6 = uVar10 & 0xffffffff;
            if ((int)uVar10 == 0) {
              plVar5[8] = (long)hboost_notifier;
              register_hboost_event_notifier(plVar5 + 8);
              goto LAB_001007b8;
            }
            _dev_err(*plVar5,"%s: register swr_haptics component failed, rc=%d\n",
                     "swr_haptics_probe",uVar6);
          }
          else {
            _dev_err(*plVar5,"%s: init regmap failed, rc=%d\n","swr_haptics_probe",
                     uVar6 & 0xffffffff);
          }
        }
        else {
          _dev_err(*plVar5,"%s: failed to get devnum for swr-haptics, rc=%d\n","swr_haptics_probe",
                   iVar2);
          uVar6 = 0xfffffdfb;
        }
        if (*(char *)((long)plVar5 + 0x5c) != '\0') {
          iVar2 = regulator_disable(plVar5[6]);
          if (iVar2 < 0) {
            iVar4 = ___ratelimit(swr_haptics_slave_disable__rs,"swr_haptics_slave_disable");
            if (iVar4 != 0) {
              _dev_err(*plVar5,"%s: disable swr-slave-vdd failed, rc=%d\n",
                       "swr_haptics_slave_disable",iVar2);
            }
          }
          else {
            *(undefined1 *)((long)plVar5 + 0x5c) = 0;
          }
        }
        swr_remove_device(param_1);
        goto LAB_001007b4;
      }
      uVar6 = devm_regulator_get(*plVar5,"qcom,hpwr");
      plVar5[7] = uVar6;
      if (uVar6 < 0xfffffffffffff001) {
        uVar3 = of_property_read_variable_u32_array(uVar11,"qcom,hpwr-voltage-mv",plVar5 + 0xb,1,0);
        if (-1 < (int)uVar3) goto LAB_001004d0;
        uVar6 = (ulong)uVar3;
        lVar7 = *plVar5;
        pcVar9 = "%s: Failed to read qcom,hpwr-voltage-mv, rc=%d\n";
      }
      else {
        if ((int)uVar6 == -0x205) goto LAB_001004a8;
        uVar6 = uVar6 & 0xffffffff;
        lVar7 = *plVar5;
        pcVar9 = "%s: Get qcom,hpwr-supply failed, rc=%d\n";
      }
LAB_001007a4:
      uVar10 = uVar6 & 0xffffffff;
      goto LAB_001007b0;
    }
    if ((int)uVar6 != -0x205) {
      lVar7 = *plVar5;
      pcVar9 = "%s: get swr-slave-supply failed, rc=%d\n";
      goto LAB_001007a4;
    }
LAB_001004a8:
    uVar6 = 0xfffffdfb;
  }
LAB_001007b4:
  *(undefined8 *)(param_1 + 0xe0) = 0;
LAB_001007b8:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// swr_haptics_remove @ 00100814 size=236
// signature: undefined swr_haptics_remove(void)
// callers: []
//------------------------------------------------------------

int swr_haptics_remove(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if ((param_1 == 0) || (puVar3 = *(undefined8 **)(param_1 + 0xe0), puVar3 == (undefined8 *)0x0)) {
    _dev_err(param_1 + 0x48,"%s: no data for swr_hap\n","swr_haptics_remove");
    iVar1 = -0x13;
  }
  else {
    unregister_hboost_event_notifier(puVar3 + 8);
    if (*(char *)((long)puVar3 + 0x5c) == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = regulator_disable(puVar3[6]);
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(swr_haptics_slave_disable__rs,"swr_haptics_slave_disable");
        if (iVar2 != 0) {
          _dev_err(*puVar3,"%s: disable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_disable",
                   iVar1);
        }
        _dev_err(*puVar3,"%s: disable swr-slave failed, rc=%d\n","swr_haptics_remove",iVar1);
      }
      else {
        iVar1 = 0;
        *(undefined1 *)((long)puVar3 + 0x5c) = 0;
      }
    }
  }
  snd_soc_unregister_component(param_1 + 0x48);
  *(undefined8 *)(param_1 + 0xe0) = 0;
  return iVar1;
}



//------------------------------------------------------------
// swr_haptics_device_up @ 00100904 size=228
// signature: undefined swr_haptics_device_up(void)
// callers: []
//------------------------------------------------------------

int swr_haptics_device_up(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if ((param_1 == 0) || (puVar3 = *(undefined8 **)(param_1 + 0xe0), puVar3 == (undefined8 *)0x0)) {
    iVar1 = ___ratelimit(swr_haptics_device_up__rs,"swr_haptics_device_up");
    if (iVar1 != 0) {
      _dev_err(param_1 + 0x48,"%s: no data for swr_hap\n","swr_haptics_device_up");
    }
    iVar1 = -0x13;
  }
  else {
    if ((*(byte *)((long)puVar3 + 0x61) & 1) != 0) {
      *(undefined1 *)((long)puVar3 + 0x5e) = 1;
    }
    if (*(char *)((long)puVar3 + 0x5c) == '\0') {
      iVar1 = regulator_enable(puVar3[6]);
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(swr_haptics_slave_enable__rs,"swr_haptics_slave_enable");
        if (iVar2 != 0) {
          _dev_err(*puVar3,"%s: enable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_enable",
                   iVar1);
        }
      }
      else {
        iVar1 = 0;
        *(undefined1 *)((long)puVar3 + 0x5c) = 1;
      }
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// swr_haptics_device_down @ 001009ec size=272
// signature: undefined swr_haptics_device_down(void)
// callers: []
//------------------------------------------------------------

int swr_haptics_device_down(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  
  if ((param_1 == 0) || (puVar3 = *(undefined8 **)(param_1 + 0xe0), puVar3 == (undefined8 *)0x0)) {
    iVar1 = ___ratelimit(swr_haptics_device_down__rs,"swr_haptics_device_down");
    if (iVar1 != 0) {
      _dev_err(param_1 + 0x48,"%s: no data for swr_hap\n","swr_haptics_device_down");
    }
    iVar1 = -0x13;
  }
  else {
    iVar1 = swr_hap_disable_hpwr_vreg(puVar3);
    if (iVar1 < 0) {
      iVar2 = ___ratelimit(swr_haptics_device_down__rs_44,"swr_haptics_device_down");
      if (iVar2 != 0) {
        _dev_err(*puVar3,"Disable hpwr_vreg failed, rc=%d\n",iVar1);
      }
    }
    else if (*(char *)((long)puVar3 + 0x5c) == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = regulator_disable(puVar3[6]);
      if (iVar1 < 0) {
        iVar2 = ___ratelimit(swr_haptics_slave_disable__rs,"swr_haptics_slave_disable");
        if (iVar2 != 0) {
          _dev_err(*puVar3,"%s: disable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_disable",
                   iVar1);
        }
      }
      else {
        iVar1 = 0;
        *(undefined1 *)((long)puVar3 + 0x5c) = 0;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// hboost_notifier @ 00100b00 size=160
// signature: undefined hboost_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 hboost_notifier(long param_1,long param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_2 == 0) {
    uVar1 = *param_3;
    if (uVar1 < 0x2711) {
      uVar3 = 0;
      *(char *)(param_1 + 0x20) = (char)((uVar1 >> 1 & 0x7fff) / 0x19);
    }
    else {
      iVar2 = ___ratelimit(hboost_notifier__rs,"hboost_notifier");
      if (iVar2 == 0) {
        uVar3 = 0xffffffea;
      }
      else {
        _dev_err(*(undefined8 *)(param_1 + -0x40),
                 "%s: voted Vmax (%u mv) is higher than maximum (%u mv)\n","hboost_notifier",uVar1,
                 10000);
        uVar3 = 0xffffffea;
      }
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// haptics_comp_probe @ 00100ba4 size=136
// signature: undefined haptics_comp_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_comp_probe(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x18) + 0x98);
  if (lVar2 == 0) {
    _printk(&DAT_00102b55,"haptics_comp_probe");
    uVar1 = 0xffffffea;
  }
  else {
    snd_soc_component_init_regmap(param_1,*(undefined8 *)(lVar2 + 0x18));
    lVar2 = param_1 + 0xd0;
    if ((lVar2 != 0) && (*(long *)(param_1 + 0xe0) != 0)) {
      snd_soc_dapm_ignore_suspend(lVar2,"HAP_IN");
      snd_soc_dapm_ignore_suspend(lVar2,"HAP_OUT");
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// haptics_comp_remove @ 00100c30 size=4
// signature: undefined haptics_comp_remove(void)
// callers: []
//------------------------------------------------------------

void haptics_comp_remove(void)

{
  return;
}



//------------------------------------------------------------
// haptics_vmax_get @ 00100c38 size=28
// signature: undefined haptics_vmax_get(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_vmax_get(long param_1,long param_2)

{
  *(ulong *)(param_2 + 0x48) =
       (ulong)*(byte *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x5f);
  return 0;
}



//------------------------------------------------------------
// haptics_vmax_put @ 00100c58 size=28
// signature: undefined haptics_vmax_put(void)
// callers: []
//------------------------------------------------------------

undefined8 haptics_vmax_put(long param_1,long param_2)

{
  *(char *)(*(long *)(*(long *)(*(long *)(param_1 + 0x80) + 0x18) + 0x98) + 0x5f) =
       (char)*(undefined8 *)(param_2 + 0x48);
  return 0;
}



//------------------------------------------------------------
// hap_enable_swr_dac_port @ 00100c78 size=1204
// signature: undefined hap_enable_swr_dac_port(void)
// callers: []
//------------------------------------------------------------

int hap_enable_swr_dac_port(long param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined8 *puVar8;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  undefined1 local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = 0;
  local_30[0] = 0;
  local_38[0] = 0;
  local_40 = 0;
  if (*(long *)(param_1 + 0x28) == 0xd0) {
    _printk(&DAT_0010299c,"hap_enable_swr_dac_port");
    iVar4 = -0x16;
    goto switchD_00100d0c_caseD_3;
  }
  puVar8 = *(undefined8 **)(*(long *)(*(long *)(param_1 + 0x28) + -0xb8) + 0x98);
  if (puVar8 == (undefined8 *)0x0) {
    _printk(&DAT_00102b55,"hap_enable_swr_dac_port");
    iVar4 = -0x13;
    goto switchD_00100d0c_caseD_3;
  }
  local_2c[0] = *(undefined1 *)(puVar8 + 4);
  iVar4 = 0;
  local_30[0] = *(undefined1 *)((long)puVar8 + 0x21);
  local_3c = *(undefined4 *)((long)puVar8 + 0x24);
  local_34[0] = *(undefined1 *)(puVar8 + 5);
  local_38[0] = *(undefined1 *)((long)puVar8 + 0x29);
  switch(param_3) {
  case 1:
    if (((*(byte *)((long)puVar8 + 0x61) & 1) != 0) && (*(char *)((long)puVar8 + 0x5e) != '\0')) {
      if (*(char *)((long)puVar8 + 0x5c) == '\0') {
LAB_00100d38:
        iVar4 = regulator_enable(puVar8[6]);
        if (iVar4 < 0) {
          iVar5 = ___ratelimit(swr_haptics_slave_enable__rs,"swr_haptics_slave_enable");
          if (iVar5 != 0) {
            _dev_err(*puVar8,"%s: enable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_enable",
                     iVar4);
          }
        }
        else {
          *(undefined1 *)((long)puVar8 + 0x5c) = 1;
        }
      }
      else {
        iVar4 = regulator_disable(puVar8[6]);
        if (-1 < iVar4) {
          *(undefined1 *)((long)puVar8 + 0x5c) = 0;
          goto LAB_00100d38;
        }
        iVar5 = ___ratelimit(swr_haptics_slave_disable__rs,"swr_haptics_slave_disable");
        if (iVar5 == 0) {
          cVar1 = *(char *)((long)puVar8 + 0x5c);
        }
        else {
          _dev_err(*puVar8,"%s: disable swr-slave-vdd failed, rc=%d\n","swr_haptics_slave_disable",
                   iVar4);
          cVar1 = *(char *)((long)puVar8 + 0x5c);
        }
        if (cVar1 == '\0') goto LAB_00100d38;
      }
      *(undefined1 *)((long)puVar8 + 0x5e) = 0;
    }
    bVar2 = *(byte *)(puVar8 + 0xc);
    if (*(byte *)((long)puVar8 + 0x5f) <= bVar2 || bVar2 == 0) {
      bVar2 = *(byte *)((long)puVar8 + 0x5f);
    }
    iVar4 = regmap_write(puVar8[3],0x3082,bVar2);
    if (iVar4 == 0) {
      regmap_read(puVar8[3],0x3082,&local_40);
      regmap_read(puVar8[3],0x3080,&local_40);
      swr_device_wakeup_vote(puVar8[1]);
      swr_connect_port(puVar8[1],local_2c,1,local_30,&local_3c,local_34,local_38);
    }
    else {
      iVar5 = ___ratelimit(hap_enable_swr_dac_port__rs,"hap_enable_swr_dac_port");
      if (iVar5 != 0) {
        _dev_err(*puVar8,"%s: SWR_VMAX update failed, rc=%d\n","hap_enable_swr_dac_port",iVar4);
      }
    }
    goto switchD_00100d0c_caseD_3;
  case 2:
    if ((puVar8[7] == 0) || (*(char *)((long)puVar8 + 0x5d) != '\0')) {
LAB_00100d60:
      swr_slvdev_datapath_control(puVar8[1],*(undefined1 *)(puVar8[1] + 0x40),1);
      iVar4 = regmap_write(puVar8[3],0x3081,0x84);
      if (iVar4 != 0) {
        iVar5 = ___ratelimit(hap_enable_swr_dac_port__rs_26,"hap_enable_swr_dac_port");
        if (iVar5 != 0) {
          _dev_err(*puVar8,"%s: Enable SWR_PLAY failed, rc=%d\n","hap_enable_swr_dac_port",iVar4);
        }
        swr_slvdev_datapath_control(puVar8[1],*(undefined1 *)(puVar8[1] + 0x40),0);
        swr_hap_disable_hpwr_vreg(puVar8);
      }
    }
    else {
      iVar4 = regulator_set_voltage(puVar8[7],*(int *)(puVar8 + 0xb) * 1000,0x7fffffff);
      if (iVar4 < 0) {
        iVar5 = ___ratelimit(swr_hap_enable_hpwr_vreg__rs,"swr_hap_enable_hpwr_vreg");
        if (iVar5 != 0) {
          _dev_err(*puVar8,"%s: Set hpwr voltage failed, rc=%d\n","swr_hap_enable_hpwr_vreg",iVar4);
        }
      }
      else {
        iVar4 = regulator_enable(puVar8[7]);
        if (-1 < iVar4) {
          *(undefined1 *)((long)puVar8 + 0x5d) = 1;
          goto LAB_00100d60;
        }
        iVar5 = ___ratelimit(swr_hap_enable_hpwr_vreg__rs_32,"swr_hap_enable_hpwr_vreg");
        if (iVar5 != 0) {
          _dev_err(*puVar8,"%s: Enable hpwr failed, rc=%d\n","swr_hap_enable_hpwr_vreg",iVar4);
        }
        regulator_set_voltage(puVar8[7],0,0x7fffffff);
      }
      iVar5 = ___ratelimit(hap_enable_swr_dac_port__rs_24,"hap_enable_swr_dac_port");
      if (iVar5 != 0) {
        uVar6 = *puVar8;
        pcVar7 = "%s: Enable hpwr_vreg failed, rc=%d\n";
LAB_001010ac:
        _dev_err(uVar6,pcVar7,"hap_enable_swr_dac_port",iVar4);
      }
    }
    break;
  default:
    goto switchD_00100d0c_caseD_3;
  case 4:
    swr_device_wakeup_vote(puVar8[1]);
    iVar4 = regmap_write(puVar8[3],0x3081,4);
    if (iVar4 == 0) {
      iVar4 = swr_hap_disable_hpwr_vreg(puVar8);
      if (-1 < iVar4) goto LAB_00100e30;
      iVar5 = ___ratelimit(hap_enable_swr_dac_port__rs_29,"hap_enable_swr_dac_port");
      if (iVar5 != 0) {
        uVar6 = *puVar8;
        pcVar7 = "%s: Disable hpwr_vreg failed, rc=%d\n";
        goto LAB_001010ac;
      }
    }
    else {
      iVar5 = ___ratelimit(hap_enable_swr_dac_port__rs_28,"hap_enable_swr_dac_port");
      if (iVar5 != 0) {
        uVar6 = *puVar8;
        pcVar7 = "%s: Enable SWR_PLAY failed, rc=%d\n";
        goto LAB_001010ac;
      }
    }
    break;
  case 8:
    swr_disconnect_port(puVar8[1],local_2c,1,local_30,local_38);
    swr_slvdev_datapath_control(puVar8[1],*(undefined1 *)(puVar8[1] + 0x40),0);
    swr_device_wakeup_unvote(puVar8[1]);
LAB_00100e30:
    iVar4 = 0;
    goto switchD_00100d0c_caseD_3;
  }
  swr_device_wakeup_unvote(puVar8[1]);
switchD_00100d0c_caseD_3:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// swr_hap_disable_hpwr_vreg @ 0010112c size=204
// signature: undefined swr_hap_disable_hpwr_vreg(void)
// callers: [swr_haptics_device_down, hap_enable_swr_dac_port]
//------------------------------------------------------------

int swr_hap_disable_hpwr_vreg(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  if ((param_1[7] == 0) || (*(char *)((long)param_1 + 0x5d) == '\0')) {
    return 0;
  }
  iVar1 = regulator_disable();
  if (iVar1 < 0) {
    iVar2 = ___ratelimit(swr_hap_disable_hpwr_vreg__rs,"swr_hap_disable_hpwr_vreg");
    if (iVar2 == 0) {
      return iVar1;
    }
    uVar3 = *param_1;
    pcVar4 = "%s: Disable hpwr failed, rc=%d\n";
  }
  else {
    iVar1 = regulator_set_voltage(param_1[7],0,0x7fffffff);
    if (-1 < iVar1) {
      *(undefined1 *)((long)param_1 + 0x5d) = 0;
      return 0;
    }
    iVar2 = ___ratelimit(swr_hap_disable_hpwr_vreg__rs_35,"swr_hap_disable_hpwr_vreg");
    if (iVar2 == 0) {
      return iVar1;
    }
    uVar3 = *param_1;
    pcVar4 = "%s: Set hpwr voltage failed, rc=%d\n";
  }
  _dev_err(uVar3,pcVar4,"swr_hap_disable_hpwr_vreg",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// swr_haptics_suspend @ 001011fc size=120
// signature: undefined swr_haptics_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_haptics_suspend(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (*(long *)(param_1 + 0x98) == 0)) {
    iVar1 = ___ratelimit(swr_haptics_suspend__rs,"swr_haptics_suspend");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: no data for swr_hap\n","swr_haptics_suspend");
    }
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// swr_haptics_resume @ 00101278 size=120
// signature: undefined swr_haptics_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 swr_haptics_resume(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((param_1 == 0) || (param_1 == 0x48)) || (*(long *)(param_1 + 0x98) == 0)) {
    iVar1 = ___ratelimit(swr_haptics_resume__rs,"swr_haptics_resume");
    if (iVar1 != 0) {
      _dev_err(param_1,"%s: no data for swr_hap\n","swr_haptics_resume");
    }
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 001012f4 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  swr_driver_register(&swr_haptics_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010131c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  swr_driver_unregister(&swr_haptics_driver);
  return;
}



//------------------------------------------------------------
// swr_driver_register @ 00104000 size=1
// signature: undefined swr_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_driver_unregister @ 00104008 size=1
// signature: undefined swr_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00104018 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104020 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 00104028 size=1
// signature: undefined devm_regulator_get(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00104030 size=1
// signature: undefined of_find_property(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00104038 size=1
// signature: undefined regulator_enable(void)
// callers: [hap_enable_swr_dac_port, swr_haptics_probe, swr_haptics_device_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00104040 size=1
// signature: undefined usleep_range_state(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_get_logical_dev_num @ 00104048 size=1
// signature: undefined swr_get_logical_dev_num(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_get_logical_dev_num(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_regmap_init_swr @ 00104050 size=1
// signature: undefined __devm_regmap_init_swr(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init_swr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_register_component @ 00104058 size=1
// signature: undefined snd_soc_register_component(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_register_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_hboost_event_notifier @ 00104060 size=1
// signature: undefined register_hboost_event_notifier(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_hboost_event_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104068 size=1
// signature: undefined _dev_err(void)
// callers: [swr_haptics_resume, swr_haptics_remove, swr_haptics_device_down, hap_enable_swr_dac_port, swr_haptics_probe, swr_haptics_suspend, swr_haptics_device_up, swr_hap_disable_hpwr_vreg, hboost_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00104070 size=1
// signature: undefined regulator_disable(void)
// callers: [swr_haptics_remove, swr_haptics_device_down, hap_enable_swr_dac_port, swr_haptics_probe, swr_hap_disable_hpwr_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104078 size=1
// signature: undefined ___ratelimit(void)
// callers: [swr_haptics_resume, swr_haptics_remove, swr_haptics_device_down, hap_enable_swr_dac_port, swr_haptics_probe, swr_haptics_suspend, swr_haptics_device_up, swr_hap_disable_hpwr_vreg, hboost_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_remove_device @ 00104080 size=1
// signature: undefined swr_remove_device(void)
// callers: [swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_remove_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hap_enable_swr_dac_port, swr_haptics_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_hboost_event_notifier @ 00104090 size=1
// signature: undefined unregister_hboost_event_notifier(void)
// callers: [swr_haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_hboost_event_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_unregister_component @ 00104098 size=1
// signature: undefined snd_soc_unregister_component(void)
// callers: [swr_haptics_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_unregister_component(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_component_init_regmap @ 001040a0 size=1
// signature: undefined snd_soc_component_init_regmap(void)
// callers: [haptics_comp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_component_init_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_soc_dapm_ignore_suspend @ 001040a8 size=1
// signature: undefined snd_soc_dapm_ignore_suspend(void)
// callers: [haptics_comp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_soc_dapm_ignore_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040b0 size=1
// signature: undefined _printk(void)
// callers: [hap_enable_swr_dac_port, haptics_comp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_slvdev_datapath_control @ 001040b8 size=1
// signature: undefined swr_slvdev_datapath_control(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_slvdev_datapath_control(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 001040c0 size=1
// signature: undefined regmap_write(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_vote @ 001040c8 size=1
// signature: undefined swr_device_wakeup_vote(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_vote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_device_wakeup_unvote @ 001040d0 size=1
// signature: undefined swr_device_wakeup_unvote(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_device_wakeup_unvote(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_disconnect_port @ 001040d8 size=1
// signature: undefined swr_disconnect_port(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_disconnect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 001040e0 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [hap_enable_swr_dac_port, swr_hap_disable_hpwr_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001040e8 size=1
// signature: undefined regmap_read(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// swr_connect_port @ 001040f0 size=1
// signature: undefined swr_connect_port(void)
// callers: [hap_enable_swr_dac_port]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void swr_connect_port(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



