// Decompiled by Ghidra 12.2
// Program: qti_battery_charger.ko
// Image base: 00100000

//------------------------------------------------------------
// register_hboost_event_notifier @ 00100d54 size=40
// signature: undefined register_hboost_event_notifier(void)
// callers: []
//------------------------------------------------------------

void register_hboost_event_notifier(undefined8 param_1)

{
  raw_notifier_chain_register(&hboost_notifier,param_1);
  return;
}



//------------------------------------------------------------
// unregister_hboost_event_notifier @ 00100d80 size=40
// signature: undefined unregister_hboost_event_notifier(void)
// callers: []
//------------------------------------------------------------

void unregister_hboost_event_notifier(undefined8 param_1)

{
  raw_notifier_chain_unregister(&hboost_notifier,param_1);
  return;
}



//------------------------------------------------------------
// qti_battery_charger_get_prop @ 00100dac size=312
// signature: undefined qti_battery_charger_get_prop(void)
// callers: []
//------------------------------------------------------------

void qti_battery_charger_get_prop(char *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if ((param_2 == 0) &&
     ((((iVar1 = strcmp(param_1,"battery"), iVar1 == 0 ||
        (iVar1 = strcmp(param_1,"usb"), iVar1 == 0)) ||
       (iVar1 = strcmp(param_1,"usb-2"), iVar1 == 0)) ||
      (iVar1 = strcmp(param_1,"wireless"), iVar1 == 0)))) {
    lVar3 = power_supply_get_by_name(param_1);
    if ((lVar3 == 0) || (lVar4 = power_supply_get_drvdata(), lVar4 == 0)) {
      uVar2 = 0xffffffed;
    }
    else {
      power_supply_put(lVar3);
      if (wls_fw_udating == '\x01') {
        uVar2 = 0xffffff92;
      }
      else {
        local_48 = *(undefined4 *)(lVar4 + 0x19c);
        local_3c = 0;
        local_44 = 0x1500000000;
        local_50 = 0x10000800a;
        uVar2 = battery_chg_write(lVar4,&local_50,0x18);
        if ((int)uVar2 == 0) {
          *param_3 = *(undefined4 *)(*(long *)(lVar4 + 400) + 0x54);
        }
      }
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// battery_chg_write @ 00100ee4 size=236
// signature: undefined battery_chg_write(void)
// callers: [soh_show, moisture_detection_usb_2_en_store, wireless_type_show, battery_chg_ship_mode, usb_psy_get_prop, wireless_boost_en_store, wireless_fw_check_for_update, wireless_boost_en_show, battery_psy_get_prop, resistance_show, usb_2_real_type_show, battery_psy_set_charge_current, restrict_chg_store, restrict_cur_store, wls_psy_get_prop, moisture_detection_en_store, charge_control_en_show, moisture_detection_usb_2_status_show, panel_event_notifier_callback, wireless_fw_update, usb_typec_compliant_show, charge_control_en_store, qti_battery_charger_get_prop, battery_chg_update_usb_type_work, usb_num_ports_show, battery_psy_set_prop, moisture_detection_status_show, usb_psy_set_icl, battery_chg_subsys_up_work, wireless_fw_version_show, usb_2_typec_compliant_show, moisture_detection_usb_2_en_show, moisture_detection_en_show, battery_chg_check_status_work, usb_real_type_show, battery_chg_probe]
//------------------------------------------------------------

int battery_chg_write(long param_1,undefined8 param_2,undefined4 param_3)

{
  int iVar1;
  
  down_read(param_1 + 0xd8);
  iVar1 = *(int *)(param_1 + 0x288);
  up_read(param_1 + 0xd8);
  if ((iVar1 == 0) || ((*(char *)(param_1 + 0x326) != '\0' && (*(char *)(param_1 + 0x324) != '\0')))
     ) {
    iVar1 = 0;
  }
  else {
    mutex_lock(param_1 + 0xa8);
    *(undefined4 *)(param_1 + 0x118) = 0;
    *(undefined1 *)(param_1 + 0x378) = 0;
    iVar1 = pmic_glink_write(*(undefined8 *)(param_1 + 0xa0),param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = wait_for_completion_timeout(param_1 + 0x118,500);
      if (iVar1 == 0) {
        _printk(&DAT_00105dc5,"battery_chg_write");
        iVar1 = -0x6e;
      }
      else if (*(char *)(param_1 + 0x378) == '\0') {
        iVar1 = 0;
      }
      else {
        iVar1 = -0x3d;
        *(undefined1 *)(param_1 + 0x378) = 0;
      }
    }
    mutex_unlock(param_1 + 0xa8);
  }
  return iVar1;
}



//------------------------------------------------------------
// battery_chg_probe @ 00100fd4 size=3372
// signature: undefined battery_chg_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong battery_chg_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  undefined **ppuVar6;
  undefined1 *puVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  long *plVar13;
  long lVar14;
  char *pcVar15;
  undefined4 *puVar16;
  undefined *puVar17;
  long lVar18;
  undefined4 uVar19;
  undefined8 uVar20;
  long *plVar21;
  int iVar22;
  ulong uVar23;
  char *local_100;
  undefined8 local_f8;
  long *local_f0;
  code *local_e8;
  code *local_e0;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined8 local_cc;
  undefined4 local_c4;
  long local_c0;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar14 = sp_el0;
  lVar18 = param_1 + 0x10;
  local_70 = *(long *)(lVar14 + 0x638);
  local_e8 = (code *)0x0;
  local_e0 = (code *)0x0;
  local_f8 = 0;
  local_f0 = (long *)0x0;
  local_100 = (char *)0x0;
  plVar13 = (long *)devm_kmalloc(lVar18,0x390,0xdc0);
  if (plVar13 != (long *)0x0) {
    plVar13[0x31] = (long)battery_prop_map;
    *(undefined4 *)(plVar13 + 0x34) = 0x31;
    plVar13[0x33] = 0x300000001c;
    plVar13[0x39] = 0x3200000011;
    *(undefined4 *)(plVar13 + 0x3a) = 0x33;
    plVar13[0x37] = (long)usb_prop_map;
    plVar13[0x45] = 0x340000000b;
    plVar13[0x43] = (long)wls_prop_map;
    plVar13[0x3d] = (long)usb_prop_map;
    *(undefined1 *)((long)plVar13 + 0x374) = 1;
    *(undefined4 *)(plVar13 + 0x46) = 0x35;
    plVar13[0x3f] = 0x1003200000011;
    *(undefined4 *)(plVar13 + 0x40) = 0x10033;
    lVar14 = devm_kmalloc(lVar18,0x70,0xdc0);
    plVar13[0x32] = lVar14;
    if (lVar14 != 0) {
      lVar14 = devm_kmalloc(lVar18,(ulong)*(uint *)(plVar13 + 0x39) << 2,0xdc0);
      plVar13[0x38] = lVar14;
      if (lVar14 != 0) {
        lVar14 = devm_kmalloc(lVar18,(ulong)*(uint *)(plVar13 + 0x3f) << 2,0xdc0);
        plVar13[0x3e] = lVar14;
        if (lVar14 != 0) {
          lVar14 = devm_kmalloc(lVar18,(ulong)*(uint *)(plVar13 + 0x45) << 2,0xdc0);
          plVar13[0x44] = lVar14;
          if (lVar14 != 0) {
            lVar14 = devm_kmalloc(lVar18,0x80,0xdc0);
            plVar13[0x30] = lVar14;
            if (lVar14 != 0) {
              __mutex_init(plVar13 + 0x15,"&bcdev->rw_lock",&battery_chg_probe___key);
              plVar1 = plVar13 + 0x1b;
              __init_rwsem(plVar1,"&bcdev->state_sem",&battery_chg_probe___key_7);
              *(undefined4 *)(plVar13 + 0x23) = 0;
              __init_swait_queue_head(plVar13 + 0x24,"&x->wait",&init_completion___key);
              *(undefined4 *)(plVar13 + 0x27) = 0;
              __init_swait_queue_head(plVar13 + 0x28,"&x->wait",&init_completion___key);
              *(undefined4 *)(plVar13 + 0x2b) = 0;
              __init_swait_queue_head(plVar13 + 0x2c,"&x->wait",&init_completion___key);
              plVar13[0x52] = 0xfffffffe0;
              plVar13[0x53] = (long)(plVar13 + 0x53);
              plVar13[0x54] = (long)(plVar13 + 0x53);
              plVar13[0x55] = (long)battery_chg_subsys_up_work;
              plVar13[0x58] = 0xfffffffe0;
              plVar13[0x59] = (long)(plVar13 + 0x59);
              plVar13[0x5a] = (long)(plVar13 + 0x59);
              plVar13[0x5b] = (long)battery_chg_update_usb_type_work;
              plVar13[0x5e] = 0xfffffffe0;
              plVar13[0x5f] = (long)(plVar13 + 0x5f);
              plVar13[0x60] = (long)(plVar13 + 0x5f);
              uVar20 = *(undefined8 *)(param_1 + 0x2f8);
              *plVar13 = lVar18;
              plVar13[0x61] = (long)battery_chg_check_status_work;
              iVar9 = of_count_phandle_with_args(uVar20,"qcom,display-panels",0);
              if (0 < iVar9) {
                iVar22 = 0;
                do {
                  local_80 = 0;
                  uStack_78 = 0;
                  local_90 = 0;
                  uStack_88 = 0;
                  local_a0 = 0;
                  local_98 = 0;
                  local_b0 = 0;
                  uStack_ac = 0;
                  local_a8 = 0;
                  uStack_a4 = 0;
                  local_c0 = 0;
                  local_b8 = 0;
                  uStack_b4 = 0;
                  iVar10 = __of_parse_phandle_with_args
                                     (uVar20,"qcom,display-panels",0,0,iVar22,&local_c0);
                  uVar23 = 0xffffffed;
                  if ((iVar10 != 0) || (local_c0 == 0)) goto LAB_001012bc;
                  uVar23 = of_drm_find_panel();
                  if (uVar23 < 0xfffffffffffff001) {
                    if (uVar23 == 0) goto LAB_0010156c;
                    uVar23 = panel_event_notifier_register
                                       (1,3,uVar23,panel_event_notifier_callback,plVar13);
                    if (uVar23 < 0xfffffffffffff001) {
                      plVar13[0x48] = uVar23;
                      goto LAB_00101328;
                    }
                    _dev_err(*plVar13,"Failed to register panel event notifier, rc=%d\n",
                             uVar23 & 0xffffffff);
                    goto LAB_00101598;
                  }
                  iVar22 = iVar22 + 1;
                } while (iVar9 != iVar22);
                if ((int)uVar23 == -0x205) {
                  uVar23 = 0xfffffdfb;
                  goto LAB_001012bc;
                }
LAB_0010156c:
                _dev_err(*plVar13,"Failed to find active panel, rc=%d\n",uVar23 & 0xffffffff);
LAB_00101598:
                if ((int)uVar23 < 0) goto LAB_001012bc;
              }
LAB_00101328:
              local_f8 = CONCAT44(local_f8._4_4_,0x800a);
              local_100 = "battery_charger";
              local_e0 = battery_chg_state_cb;
              local_e8 = battery_chg_callback;
              local_f0 = plVar13;
              uVar23 = pmic_glink_register_client(lVar18,&local_100);
              plVar13[0x14] = uVar23;
              if (uVar23 < 0xfffffffffffff001) {
                down_write(plVar1);
                *(undefined4 *)(plVar13 + 0x51) = 1;
                *(undefined1 *)((long)plVar13 + 0x376) = 1;
                up_write(plVar1);
                *(undefined4 *)(plVar13 + 0x6a) = 0xff;
                plVar13[0x68] = (long)battery_chg_ship_mode;
                register_reboot_notifier();
                local_d8 = (ulong)local_d8._4_4_ << 0x20;
                uVar20 = *(undefined8 *)(*plVar13 + 0x2e8);
                lVar14 = of_find_property(uVar20,"qcom,wireless-charging-not-supported",0);
                plVar21 = plVar13 + 0x4a;
                *(bool *)((long)plVar13 + 0x327) = lVar14 != 0;
                of_property_read_string(uVar20,"qcom,wireless-fw-name",plVar21);
                of_property_read_variable_u32_array
                          (uVar20,"qcom,shutdown-voltage",(long)plVar13 + 0x284,1,0);
                lVar14 = of_find_property(*(undefined8 *)(*plVar13 + 0x2e8),"qcom,multiport-usb",0);
                uVar19 = 1;
                if (lVar14 != 0) {
                  uVar19 = 2;
                }
                *(undefined4 *)((long)plVar13 + 0x37c) = uVar19;
                if (((char *)plVar13[0x4a] != (char *)0x0) &&
                   (pcVar15 = strstr((char *)plVar13[0x4a],"cps"), pcVar15 != (char *)0x0)) {
                  *(undefined4 *)(plVar13 + 0x66) = 1;
                }
                lVar14 = of_find_property(*(undefined8 *)(*plVar13 + 0x2e8),"mmi,wls-2nd-fw-enabled"
                                          ,0);
                *(bool *)(plVar13 + 0x4f) = lVar14 != 0;
                if (lVar14 != 0) {
                  plVar2 = plVar13 + 0x4d;
                  iVar9 = of_property_read_string(uVar20,"qcom,wireless-coil-id",plVar2);
                  if (iVar9 != 0) {
                    *plVar2 = 0;
                  }
                  plVar3 = plVar13 + 0x4b;
                  iVar9 = of_property_read_string(uVar20,"qcom,wireless-fw-name-2nd",plVar3);
                  if (iVar9 != 0) {
                    *plVar3 = 0;
                  }
                  plVar4 = plVar13 + 0x4e;
                  iVar9 = of_property_read_string(uVar20,"qcom,wireless-coil-id-2nd",plVar4);
                  if (iVar9 != 0) {
                    *plVar4 = 0;
                  }
                  plVar5 = plVar13 + 0x4c;
                  lVar14 = of_find_node_opts_by_path("/chosen",0);
                  plVar13[0x4c] = 0;
                  if (lVar14 != 0) {
                    iVar9 = of_property_read_string(lVar14,"mmi,wireless_coil_id",plVar5);
                    if ((iVar9 == -0x16) || (*plVar5 == 0)) {
                      _printk(&DAT_00105e47,"mmi_get_wls_coil_id");
                    }
                    else {
                      _printk(&DAT_00106206,"mmi_get_wls_coil_id");
                    }
                  }
                  if ((((*plVar2 != 0) && (*plVar3 != 0)) && (*plVar4 != 0)) && (*plVar5 != 0)) {
                    _printk(&DAT_0010607d,"battery_chg_parse_dt");
                    iVar9 = strcmp((char *)*plVar4,(char *)*plVar5);
                    if (iVar9 == 0) {
                      of_property_read_string(uVar20,"qcom,wireless-fw-name-2nd",plVar21);
                    }
                  }
                }
                _printk(&DAT_00106d81,"battery_chg_parse_dt",*plVar21);
                if (wls_fw_udating == '\x01') {
                  uVar23 = 0xffffff92;
LAB_00101890:
                  puVar17 = &DAT_001065c8;
LAB_00101898:
                  _printk(puVar17,"battery_chg_parse_dt",uVar23);
LAB_001018a8:
                  pcVar15 = "Failed to parse dt rc=%d\n";
LAB_001018b0:
                  _dev_err(lVar18,pcVar15,uVar23);
                }
                else {
                  local_b8 = *(undefined4 *)((long)plVar13 + 0x19c);
                  uStack_ac = 0;
                  uStack_b4 = 0;
                  local_b0 = 0xb;
                  local_c0 = 0x10000800a;
                  uVar11 = battery_chg_write(plVar13,&local_c0,0x18);
                  if ((int)uVar11 < 0) {
                    uVar23 = (ulong)uVar11;
                    goto LAB_00101890;
                  }
                  iVar9 = of_property_count_elems_of_size(uVar20,"qcom,thermal-mitigation",4);
                  if (0 < iVar9) {
                    *(undefined4 *)((long)plVar13 + 0x36c) = 0;
                    iVar22 = 0;
                    uVar11 = *(uint *)(plVar13[0x32] + 0x2c);
                    do {
                      uVar12 = of_property_read_u32_index
                                         (uVar20,"qcom,thermal-mitigation",iVar22,&local_d8);
                      if ((int)uVar12 < 0) {
                        uVar23 = (ulong)uVar12;
                        goto LAB_001018a8;
                      }
                      if (uVar11 < (uint)local_d8) {
                        _printk(&DAT_00106ef4,"battery_chg_parse_dt");
                        *(undefined4 *)(plVar13 + 0x50) = 0xffffffea;
                        goto LAB_00101798;
                      }
                      iVar22 = iVar22 + 1;
                      uVar11 = (uint)local_d8;
                    } while (iVar9 != iVar22);
                    if (-1 < (int)(iVar9 + 1U)) {
                      puVar16 = (undefined4 *)devm_kmalloc(*plVar13,(ulong)(iVar9 + 1U) << 2,0xdc0);
                      plVar13[0x49] = (long)puVar16;
                      if (puVar16 == (undefined4 *)0x0) {
                        uVar23 = 0xfffffff4;
                        goto LAB_001018a8;
                      }
                      *puVar16 = *(undefined4 *)(plVar13[0x32] + 0x2c);
                      uVar11 = of_property_read_variable_u32_array
                                         (uVar20,"qcom,thermal-mitigation",puVar16 + 1,iVar9,0);
                      if (-1 < (int)uVar11) {
                        lVar14 = plVar13[0x32];
                        goto LAB_0010178c;
                      }
                      uVar23 = (ulong)uVar11;
                      puVar17 = &DAT_00105f99;
                      goto LAB_00101898;
                    }
                    uVar23 = 0xfffffff4;
                    plVar13[0x49] = 0;
                    goto LAB_001018a8;
                  }
                  iVar9 = of_property_read_variable_u32_array
                                    (uVar20,"qcom,thermal-mitigation-step",&local_d8,1,0);
                  if (-1 < iVar9) {
                    if (((uint)local_d8 < 500000) ||
                       (lVar14 = plVar13[0x32], *(uint *)(lVar14 + 0x2c) <= (uint)local_d8)) {
                      _printk(&DAT_00106321,"battery_chg_parse_dt");
                      uVar23 = 0xffffffea;
                      goto LAB_001018a8;
                    }
                    *(uint *)((long)plVar13 + 0x36c) = (uint)local_d8;
                    uVar11 = 0;
                    if ((uint)local_d8 != 0) {
                      uVar11 = *(uint *)(lVar14 + 0x2c) / (uint)local_d8;
                    }
                    iVar9 = uVar11 - (*(uint *)(lVar14 + 0x2c) - uVar11 * (uint)local_d8 < 500000);
LAB_0010178c:
                    *(int *)(plVar13 + 0x50) = iVar9;
                    *(undefined4 *)(plVar13 + 0x6b) = *(undefined4 *)(lVar14 + 0x2c);
                  }
LAB_00101798:
                  lVar14 = *plVar13;
                  *(long **)(param_1 + 0xa8) = plVar13;
                  *(undefined4 *)(plVar13 + 100) = 0xffffffea;
                  *(undefined4 *)((long)plVar13 + 0x35c) = 1000000;
                  local_c0 = *(long *)(lVar14 + 0x2e8);
                  local_98 = 0;
                  local_90 = 0;
                  local_a8 = 0;
                  uStack_a4 = 0;
                  local_a0 = 0;
                  local_b8 = 0;
                  uStack_b4 = 0;
                  local_b0 = SUB84(plVar13,0);
                  uStack_ac = (undefined4)((ulong)plVar13 >> 0x20);
                  uVar23 = devm_power_supply_register(lVar14,&usb_psy_desc,&local_c0);
                  plVar13[0x35] = uVar23;
                  if (0xfffffffffffff000 < uVar23) {
                    puVar17 = &DAT_00106949;
                    plVar13[0x35] = 0;
LAB_00101cd8:
                    _printk(puVar17,"battery_chg_init_psy",uVar23 & 0xffffffff);
LAB_00101ce8:
                    if ((int)uVar23 < 0) goto LAB_001018bc;
LAB_00101a68:
                    plVar21 = plVar13 + 1;
                    *plVar21 = (long)"qcom-battery";
                    bVar8 = *(char *)((long)plVar13 + 0x327) != '\0';
                    ppuVar6 = &battery_class_usb_2_groups;
                    if (bVar8) {
                      ppuVar6 = &battery_class_usb_2_no_wls_groups;
                    }
                    puVar7 = battery_class_groups;
                    if (bVar8) {
                      puVar7 = (undefined1 *)&battery_class_no_wls_groups;
                    }
                    if (*(int *)((long)plVar13 + 0x37c) != 2) {
                      ppuVar6 = (undefined **)puVar7;
                    }
                    plVar13[3] = (long)ppuVar6;
                    uVar11 = __class_register(plVar21,&battery_chg_probe___key_13);
                    if (-1 < (int)uVar11) {
                      uVar23 = devm_thermal_of_cooling_device_register
                                         (lVar18,*(undefined8 *)(param_1 + 0x2f8),
                                          **(undefined8 **)plVar13[0x2f],plVar13,&battery_tcd_ops);
                      if ((uVar23 != 0) && (uVar23 < 0xfffffffffffff001)) {
                        *(undefined4 *)(plVar13 + 0x67) = 1000;
                        uVar23 = debugfs_create_dir("battery_charger",0);
                        if (uVar23 < 0xfffffffffffff001) {
                          plVar13[0x47] = uVar23;
                          debugfs_create_bool("block_tx",0x180,uVar23,(long)plVar13 + 0x324);
                        }
                        else {
                          _printk(&DAT_00106b21,"battery_chg_add_debugfs");
                        }
                        *(undefined1 *)((long)plVar13 + 0x377) = 0;
                        uStack_ac = 0;
                        local_a8 = 0;
                        uStack_b4 = 0;
                        local_b0 = 0;
                        local_c0 = 0x20000800a;
                        local_b8 = 4;
                        iVar9 = battery_chg_write(plVar13,&local_c0,0x1c);
                        if (iVar9 < 0) {
                          _printk(&DAT_00106b67,"battery_chg_notify_enable",iVar9);
                        }
                        else {
                          *(undefined1 *)((long)plVar13 + 0x377) = 1;
                        }
                        lVar18 = *plVar13;
                        device_set_wakeup_capable(lVar18,1);
                        device_wakeup_enable(lVar18);
                        queue_work_on(0x20,_system_wq,plVar13 + 0x58);
                        if (wls_fw_udating == '\x01') {
                          iVar9 = -0x6e;
                        }
                        else {
                          local_b8 = *(undefined4 *)((long)plVar13 + 0x19c);
                          uStack_ac = 0;
                          uStack_b4 = 0;
                          local_b0 = 0x18;
                          local_c0 = 0x10000800a;
                          iVar9 = battery_chg_write(plVar13,&local_c0,0x18);
                          if (-1 < iVar9) {
                            uVar23 = 0;
                            *(bool *)((long)plVar13 + 0x373) = *(int *)(plVar13[0x32] + 0x60) != 0;
                            goto LAB_001012bc;
                          }
                        }
                        _printk(&DAT_001060d8,"get_charge_control_en",iVar9);
                        uVar23 = 0;
                        goto LAB_001012bc;
                      }
                      uVar11 = (uint)uVar23;
                      if (uVar23 < 0xfffffffffffff001) {
                        uVar11 = 0;
                      }
                      uVar23 = (ulong)uVar11;
                      _dev_err(lVar18,"Failed to register thermal cooling device rc=%d\n",uVar23);
                      class_unregister(plVar21);
                      goto LAB_001018bc;
                    }
                    uVar23 = (ulong)uVar11;
                    pcVar15 = "Failed to create battery_class rc=%d\n";
                    goto LAB_001018b0;
                  }
                  if (wls_fw_udating == '\x01') {
LAB_001019b8:
                    *(undefined4 *)((long)plVar13 + 0x37c) = 1;
LAB_001019c0:
                    if (*(char *)((long)plVar13 + 0x327) == '\0') {
                      uVar23 = devm_power_supply_register(*plVar13,&wls_psy_desc,&local_c0);
                      plVar13[0x41] = uVar23;
                      if (0xfffffffffffff000 < uVar23) {
                        plVar13[0x41] = 0;
                        puVar17 = &DAT_00106a07;
                        goto LAB_00101cd8;
                      }
                    }
                    uVar23 = devm_power_supply_register(*plVar13,&batt_psy_desc,&local_c0);
                    plVar13[0x2f] = uVar23;
                    if (0xfffffffffffff000 < uVar23) {
                      plVar13[0x2f] = 0;
                      puVar17 = &DAT_00106dbf;
                      goto LAB_00101cd8;
                    }
                    lVar14 = of_find_property(*(undefined8 *)(*plVar13 + 0x2e8),"mmi,combo-batt-psy"
                                              ,0);
                    if (lVar14 != 0) {
                      uVar23 = devm_power_supply_get_by_phandle(*plVar13,"mmi,combo-batt-psy");
                      plVar13[0x71] = uVar23;
                      if ((uVar23 == 0) || (0xfffffffffffff000 < uVar23)) {
                        _printk(&DAT_001074aa,"battery_chg_init_psy");
                        uVar23 = plVar13[0x71];
                        if (uVar23 == 0) {
                          uVar23 = 0xffffffed;
                          goto LAB_001018bc;
                        }
                        goto LAB_00101ce8;
                      }
                      lVar14 = of_find_property(*(undefined8 *)(*plVar13 + 0x2e8),
                                                "mmi,aura-combo-policy",0);
                      *(bool *)(plVar13 + 0x70) = lVar14 != 0;
                    }
                    goto LAB_00101a68;
                  }
                  local_d0 = *(undefined4 *)((long)plVar13 + 0x1cc);
                  local_c4 = 0;
                  local_cc = 0x1000000000;
                  local_d8 = 0x10000800a;
                  iVar9 = battery_chg_write(plVar13,&local_d8,0x18);
                  if (iVar9 < 0) goto LAB_001019b8;
                  uVar11 = *(uint *)(plVar13[0x38] + 0x40);
                  if (uVar11 < 3) {
                    if (uVar11 != *(uint *)((long)plVar13 + 0x37c)) {
                      _printk(&DAT_00107452,"battery_chg_init_psy");
                      goto LAB_001019b8;
                    }
                    if (uVar11 == 2) {
                      *(undefined1 *)((long)plVar13 + 0x375) = 1;
                      uVar23 = devm_power_supply_register(*plVar13,&PTR_s_usb_2_001078d8,&local_c0);
                      plVar13[0x3b] = uVar23;
                      if (0xfffffffffffff000 < uVar23) {
                        plVar13[0x3b] = 0;
                        puVar17 = &DAT_00106c2a;
                        goto LAB_00101cd8;
                      }
                    }
                    goto LAB_001019c0;
                  }
                  _printk(&DAT_00106c92,"battery_chg_init_psy");
                  uVar23 = 0xffffffea;
                }
LAB_001018bc:
                down_write(plVar1);
                *(undefined4 *)(plVar13 + 0x51) = 0;
                *(undefined1 *)((long)plVar13 + 0x376) = 0;
                up_write(plVar1);
                pmic_glink_unregister_client(plVar13[0x14]);
                cancel_work_sync(plVar13 + 0x58);
                cancel_work_sync(plVar13 + 0x52);
                cancel_work_sync(plVar13 + 0x5e);
                complete(plVar13 + 0x23);
                unregister_reboot_notifier(plVar13 + 0x68);
              }
              else if ((int)uVar23 == -0x205) {
                uVar23 = 0xfffffdfb;
              }
              else {
                uVar23 = uVar23 & 0xffffffff;
                _dev_err(lVar18,"Error in registering with pmic_glink %d\n",uVar23);
              }
              if (plVar13[0x48] != 0) {
                panel_event_notifier_unregister();
              }
              goto LAB_001012bc;
            }
          }
        }
      }
    }
  }
  uVar23 = 0xfffffff4;
LAB_001012bc:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar23 & 0xffffffff;
}



//------------------------------------------------------------
// battery_chg_remove @ 00101d04 size=160
// signature: undefined battery_chg_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_chg_remove(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(param_1 + 0xa8);
  down_write(puVar2 + 0x1b);
  *(undefined4 *)(puVar2 + 0x51) = 0;
  *(undefined1 *)((long)puVar2 + 0x376) = 0;
  up_write(puVar2 + 0x1b);
  if (puVar2[0x48] != 0) {
    panel_event_notifier_unregister();
  }
  uVar1 = *puVar2;
  device_wakeup_disable(uVar1);
  device_set_wakeup_capable(uVar1,0);
  debugfs_remove(puVar2[0x47]);
  class_unregister(puVar2 + 1);
  pmic_glink_unregister_client(puVar2[0x14]);
  cancel_work_sync(puVar2 + 0x52);
  cancel_work_sync(puVar2 + 0x58);
  cancel_work_sync(puVar2 + 0x5e);
  unregister_reboot_notifier(puVar2 + 0x68);
  return 0;
}



//------------------------------------------------------------
// battery_chg_subsys_up_work @ 00101da8 size=512
// signature: undefined battery_chg_subsys_up_work(void)
// callers: []
//------------------------------------------------------------

void battery_chg_subsys_up_work(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint uVar4;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = param_1 + -0x290;
  local_44 = 0;
  local_4c = 0;
  if (*(char *)(param_1 + 0xe7) == '\0') {
    local_50 = 4;
    local_58 = 0x20000800a;
    iVar2 = battery_chg_write(lVar3,&local_58,0x1c);
    if (iVar2 < 0) {
      _printk(&DAT_00106b67,"battery_chg_notify_enable",iVar2);
    }
    else {
      *(undefined1 *)(param_1 + 0xe7) = 1;
    }
  }
  msleep(200);
  uVar4 = *(uint *)(param_1 + 0xd0);
  if (uVar4 == 0) {
LAB_00101e88:
    iVar2 = *(int *)(param_1 + 0xd4);
  }
  else {
    if (*(char *)(param_1 + 0xe0) != '\0') {
      uVar1 = *(uint *)(param_1 + 0xcc);
      if (uVar4 <= *(uint *)(param_1 + 0xcc)) {
        uVar1 = uVar4;
      }
      uVar4 = uVar1;
      if (*(uint *)(param_1 + 200) <= uVar1) {
        uVar4 = *(uint *)(param_1 + 200);
      }
    }
    if (wls_fw_udating == '\x01') {
      iVar2 = -0x6e;
    }
    else {
      local_50 = *(undefined4 *)(param_1 + -0xf0);
      local_44 = CONCAT44(local_44._4_4_,uVar4);
      local_4c = 0xa00000000;
      local_58 = 0x10000800a;
      iVar2 = battery_chg_write(lVar3,&local_58,0x18);
      if (-1 < iVar2) {
        *(uint *)(param_1 + 0xd0) = uVar4;
        goto LAB_00101e88;
      }
    }
    _printk(&DAT_001073bd,"__battery_psy_set_charge_current",uVar4,iVar2);
    _printk(&DAT_00105dfa,"battery_chg_subsys_up_work",*(undefined4 *)(param_1 + 0xd0),iVar2);
    iVar2 = *(int *)(param_1 + 0xd4);
  }
  if ((iVar2 != 0) && (iVar2 = usb_psy_set_icl(lVar3,param_1 + -0xe8,5), iVar2 < 0)) {
    _printk(&DAT_001075af,"battery_chg_subsys_up_work",*(undefined4 *)(param_1 + 0xd4),iVar2);
  }
  if (((*(int *)(param_1 + 0xec) == 2) && (*(int *)(param_1 + 0xd8) != 0)) &&
     (iVar2 = usb_psy_set_icl(lVar3,param_1 + -0xb8,5), iVar2 < 0)) {
    _printk(&DAT_00106404,"battery_chg_subsys_up_work",*(undefined4 *)(param_1 + 0xd8),iVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// battery_chg_update_usb_type_work @ 00101fac size=608
// signature: undefined battery_chg_update_usb_type_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void battery_chg_update_usb_type_work(long param_1)

{
  char cVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (*(char *)(param_1 + 0xb4) == '\0') goto LAB_001020b0;
  local_38 = *(undefined4 *)(param_1 + -0xf4);
  *(undefined1 *)(param_1 + 0xb4) = 0;
  local_2c = 0;
  local_34 = 0x700000000;
  local_40 = 0x10000800a;
  iVar3 = battery_chg_write(param_1 + -0x2c0,&local_40,0x18);
  if (iVar3 < 0) {
    _printk(&DAT_001066d2,"battery_chg_update_usb_type_work",iVar3);
    cVar1 = *(char *)(param_1 + 0xb5);
  }
  else {
    iVar3 = *(int *)(*(long *)(param_1 + -0x100) + 0x1c);
    if ((iVar3 != 1) && (iVar3 != 6)) {
      *(undefined4 *)(param_1 + 0xa4) = 0;
      iVar3 = *(int *)(*(long *)(param_1 + -0x100) + 0x1c);
    }
    switch(iVar3) {
    case 2:
    case 9:
switchD_00102058_caseD_2:
      _DAT_00107878 = 5;
      break;
    case 3:
      _DAT_00107878 = 6;
      break;
    case 4:
      _DAT_00107878 = 7;
      break;
    case 5:
      _DAT_00107878 = 8;
      break;
    case 6:
    case 7:
    case 8:
      _DAT_00107878 = 9;
      break;
    default:
      if (iVar3 - 0x80U < 3) goto switchD_00102058_caseD_2;
    case 1:
      _DAT_00107878 = 4;
    }
LAB_001020b0:
    cVar1 = *(char *)(param_1 + 0xb5);
  }
  if (cVar1 == '\0') goto LAB_001021e0;
  local_38 = *(undefined4 *)(param_1 + -0xc4);
  *(undefined1 *)(param_1 + 0xb5) = 0;
  local_2c = 0;
  local_34 = 0x700000000;
  local_40 = 0x10000800a;
  iVar3 = battery_chg_write(param_1 + -0x2c0,&local_40,0x18);
  if (iVar3 < 0) {
    _printk(&DAT_001066d2,"battery_chg_update_usb_type_work",iVar3);
    goto LAB_001021e0;
  }
  iVar3 = *(int *)(*(long *)(param_1 + -0xd0) + 0x1c);
  if ((iVar3 != 1) && (iVar3 != 6)) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
    iVar3 = *(int *)(*(long *)(param_1 + -0xd0) + 0x1c);
  }
  switch(iVar3) {
  case 2:
  case 9:
switchD_00102134_caseD_2:
    _DAT_001078e0 = 5;
    break;
  case 3:
    _DAT_001078e0 = 6;
    break;
  case 4:
    _DAT_001078e0 = 7;
    break;
  case 5:
    _DAT_001078e0 = 8;
    break;
  case 6:
  case 7:
  case 8:
    _DAT_001078e0 = 9;
    break;
  default:
    if (iVar3 - 0x80U < 3) goto switchD_00102134_caseD_2;
  case 1:
    _DAT_001078e0 = 4;
  }
LAB_001021e0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// battery_chg_check_status_work @ 00102210 size=488
// signature: undefined battery_chg_check_status_work(void)
// callers: []
//------------------------------------------------------------

void battery_chg_check_status_work(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  undefined4 *puVar4;
  long *plVar5;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  undefined4 local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar1 = -0x6e;
LAB_00102388:
    puVar2 = &DAT_00106d0a;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + -0x154);
    lVar3 = param_1 + -0x2f0;
    local_58 = *puVar4;
    local_54 = 0;
    local_4c = 0;
    local_60 = 0x10000800a;
    iVar1 = battery_chg_write(lVar3,&local_60,0x18);
    if (iVar1 < 0) goto LAB_00102388;
    plVar5 = (long *)(param_1 + -0x160);
    if (*(int *)*plVar5 == 1) goto LAB_001023b4;
    if (wls_fw_udating == '\x01') {
      iVar1 = -0x6e;
LAB_001023a0:
      puVar2 = &DAT_0010717c;
    }
    else {
      local_58 = *puVar4;
      local_4c = 0;
      local_54 = 0x400000000;
      local_60 = 0x10000800a;
      iVar1 = battery_chg_write(lVar3,&local_60,0x18);
      if (iVar1 < 0) goto LAB_001023a0;
      if (99 < *(int *)(*plVar5 + 0x10) + 0x32U) goto LAB_001023b4;
      local_58 = *puVar4;
      local_4c = 0;
      local_54 = 0x700000000;
      local_60 = 0x10000800a;
      iVar1 = battery_chg_write(lVar3,&local_60,0x18);
      if (-1 < iVar1) {
        if (*(uint *)(*plVar5 + 0x1c) / 1000 <= *(uint *)(param_1 + -0x6c)) {
          _printk(&DAT_001070ae,"battery_chg_check_status_work");
          msleep(100);
          _printk(&DAT_00105f54,"battery_chg_check_status_work");
          kernel_power_off();
        }
        goto LAB_001023b4;
      }
      puVar2 = &DAT_001075e3;
    }
  }
  _printk(puVar2,"battery_chg_check_status_work",iVar1);
LAB_001023b4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// battery_chg_callback @ 001023fc size=1316
// signature: undefined battery_chg_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 battery_chg_callback(undefined8 *param_1,long param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  uint uVar3;
  char cVar4;
  long lVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined8 *puVar9;
  long *plVar10;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  down_read(param_1 + 0x1b);
  cVar4 = *(char *)((long)param_1 + 0x376);
  up_read(param_1 + 0x1b);
  uVar8 = _system_wq;
  if (cVar4 == '\0') goto LAB_001026ac;
  iVar6 = *(int *)(param_2 + 8);
  switch(iVar6) {
  case 4:
  case 5:
  case 0x36:
  case 0x47:
  case 0x48:
    goto switchD_00102470_caseD_4;
  case 6:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
  case 0x2b:
  case 0x2c:
  case 0x2d:
  case 0x2e:
  case 0x2f:
  case 0x37:
  case 0x38:
  case 0x39:
  case 0x3a:
  case 0x3b:
  case 0x3c:
  case 0x3d:
  case 0x3e:
  case 0x3f:
  case 0x41:
  case 0x45:
  case 0x46:
switchD_00102470_caseD_6:
    puVar7 = &DAT_00106056;
LAB_001028d0:
    _printk(puVar7,"handle_message",iVar6);
    break;
  case 7:
    if (param_3 != 0x10) {
      _printk(&DAT_00107258,"handle_notification",param_3);
      goto LAB_001026ac;
    }
    uVar3 = *(uint *)(param_2 + 0xc);
    if ((uVar3 & 0xffff) == 0x79) {
      local_4c = uVar3 >> 0x10;
      raw_notifier_call_chain(&hboost_notifier,0,&local_4c);
      goto LAB_001026ac;
    }
    if ((int)uVar3 < 0x34) {
      if (uVar3 == 0x30) {
LAB_00102794:
        plVar10 = param_1 + 0x2f;
        if (*(int *)((long)param_1 + 0x284) < 1) goto LAB_00102800;
        puVar9 = param_1 + 0x5e;
      }
      else {
        if (uVar3 != 0x32) goto LAB_001026ac;
        plVar10 = param_1 + 0x35;
        puVar9 = param_1 + 0x58;
        *(undefined1 *)((long)param_1 + 0x374) = 1;
      }
LAB_001027f8:
      queue_work_on(0x20,uVar8,puVar9);
    }
    else {
      if (uVar3 != 0x34) {
        if (uVar3 != 0x10032) {
          if (uVar3 != 0x80) goto LAB_001026ac;
          goto LAB_00102794;
        }
        if (*(uint *)((long)param_1 + 0x37c) < 2) goto LAB_001026ac;
        plVar10 = param_1 + 0x3b;
        puVar9 = param_1 + 0x58;
        *(undefined1 *)((long)param_1 + 0x375) = 1;
        uVar8 = _system_wq;
        goto LAB_001027f8;
      }
      plVar10 = param_1 + 0x41;
    }
LAB_00102800:
    if ((plVar10 != (long *)0x0) && (*plVar10 != 0)) {
      power_supply_changed();
      pm_wakeup_dev_event(*param_1,0x32,1);
    }
    goto LAB_001026ac;
  case 0x30:
    if ((param_3 != 0x90) || (puVar9 = (undefined8 *)param_1[0x30], puVar9 == (undefined8 *)0x0)) {
      if (param_3 == 0x18) {
        if (*(int *)(param_2 + 0x14) != 0) goto LAB_0010267c;
        if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0x33)) {
          *(undefined4 *)(param_1[0x32] + (ulong)*(uint *)(param_2 + 0xc) * 4) =
               *(undefined4 *)(param_2 + 0x10);
          goto switchD_00102470_caseD_4;
        }
      }
      else {
        _printk(&DAT_001067c3,"validate_message",param_3,0x30);
      }
      break;
    }
    uVar1 = *(undefined8 *)(param_2 + 0x28);
    uVar8 = *(undefined8 *)(param_2 + 0x10);
    uVar2 = *(undefined8 *)(param_2 + 0x18);
    puVar9[2] = *(undefined8 *)(param_2 + 0x20);
    puVar9[3] = uVar1;
    *puVar9 = uVar8;
    puVar9[1] = uVar2;
    uVar1 = *(undefined8 *)(param_2 + 0x48);
    uVar8 = *(undefined8 *)(param_2 + 0x30);
    uVar2 = *(undefined8 *)(param_2 + 0x38);
    puVar9[6] = *(undefined8 *)(param_2 + 0x40);
    puVar9[7] = uVar1;
    puVar9[4] = uVar8;
    puVar9[5] = uVar2;
    uVar1 = *(undefined8 *)(param_2 + 0x68);
    uVar8 = *(undefined8 *)(param_2 + 0x50);
    uVar2 = *(undefined8 *)(param_2 + 0x58);
    puVar9[10] = *(undefined8 *)(param_2 + 0x60);
    puVar9[0xb] = uVar1;
    puVar9[8] = uVar8;
    puVar9[9] = uVar2;
    uVar1 = *(undefined8 *)(param_2 + 0x88);
    uVar8 = *(undefined8 *)(param_2 + 0x70);
    uVar2 = *(undefined8 *)(param_2 + 0x78);
    puVar9[0xe] = *(undefined8 *)(param_2 + 0x80);
    puVar9[0xf] = uVar1;
    puVar9[0xc] = uVar8;
    puVar9[0xd] = uVar2;
    iVar6 = strcmp((char *)param_1[0x30],"Debug_Board");
    *(bool *)((long)param_1 + 0x326) = iVar6 == 0;
    goto switchD_00102470_caseD_4;
  case 0x31:
  case 0x33:
  case 0x35:
switchD_00102470_caseD_31:
    if (param_3 == 0x18) {
      if (*(int *)(param_2 + 0x14) == 0) goto switchD_00102470_caseD_4;
LAB_0010267c:
      iVar6 = ___ratelimit(validate_message__rs,"validate_message");
      if (iVar6 != 0) {
        _printk(&DAT_0010624d,"validate_message",*(undefined4 *)(param_2 + 8),
                *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x14));
      }
      *(undefined1 *)(param_1 + 0x6f) = 1;
    }
    else {
      _printk(&DAT_001067c3,"validate_message",param_3);
    }
    break;
  case 0x32:
    if (param_3 == 0x18) {
      if (*(int *)(param_2 + 0x14) != 0) goto LAB_0010267c;
      if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0x39)) {
        *(undefined4 *)(param_1[0x38] + (ulong)*(uint *)(param_2 + 0xc) * 4) =
             *(undefined4 *)(param_2 + 0x10);
        goto switchD_00102470_caseD_4;
      }
    }
    else {
      _printk(&DAT_001067c3,"validate_message",param_3,0x32);
    }
    break;
  case 0x34:
    if (param_3 == 0x18) {
      if (*(int *)(param_2 + 0x14) != 0) goto LAB_0010267c;
      if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0x45)) {
        *(undefined4 *)(param_1[0x44] + (ulong)*(uint *)(param_2 + 0xc) * 4) =
             *(undefined4 *)(param_2 + 0x10);
        goto switchD_00102470_caseD_4;
      }
    }
    else {
      _printk(&DAT_001067c3,"validate_message",param_3,0x34);
    }
    break;
  case 0x40:
    if (param_3 != 0x10) {
      puVar7 = &DAT_00107029;
LAB_001028ac:
      _printk(puVar7,"handle_message",param_3);
      break;
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      *(undefined1 *)(param_1 + 0x65) = 1;
    }
    goto switchD_00102470_caseD_4;
  case 0x42:
    if (param_3 != 0x10) {
      puVar7 = &DAT_00106184;
      goto LAB_001028ac;
    }
    iVar6 = *(int *)(param_2 + 0xc);
    if (iVar6 != 1) {
      puVar7 = &DAT_001069ba;
      goto LAB_001028d0;
    }
    complete(param_1 + 0x2b);
    break;
  case 0x43:
    if (param_3 != 0x10) {
      puVar7 = &DAT_0010728a;
      goto LAB_001028ac;
    }
    if (*(int *)(param_2 + 0xc) == 1) {
      complete(param_1 + 0x27);
    }
    break;
  case 0x44:
    if (param_3 != 0x10) {
      puVar7 = &DAT_001070e2;
      goto LAB_001028ac;
    }
    *(undefined4 *)((long)param_1 + 0x32c) = *(undefined4 *)(param_2 + 0xc);
    goto switchD_00102470_caseD_4;
  default:
    if (iVar6 == 0x10032) {
      if (1 < *(uint *)((long)param_1 + 0x37c)) {
        if (param_3 == 0x18) {
          if (*(int *)(param_2 + 0x14) != 0) goto LAB_0010267c;
          if (*(uint *)(param_2 + 0xc) < *(uint *)(param_1 + 0x3f)) {
            *(undefined4 *)(param_1[0x3e] + (ulong)*(uint *)(param_2 + 0xc) * 4) =
                 *(undefined4 *)(param_2 + 0x10);
            goto switchD_00102470_caseD_4;
          }
        }
        else {
          _printk(&DAT_001067c3,"validate_message",param_3,0x10032);
        }
      }
    }
    else {
      if (iVar6 != 0x10033) goto switchD_00102470_caseD_6;
      if (1 < *(uint *)((long)param_1 + 0x37c)) goto switchD_00102470_caseD_31;
    }
  }
  if (*(char *)(param_1 + 0x6f) != '\0') {
switchD_00102470_caseD_4:
    complete(param_1 + 0x23);
  }
LAB_001026ac:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// battery_chg_state_cb @ 00102924 size=156
// signature: undefined battery_chg_state_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void battery_chg_state_cb(long param_1,int param_2)

{
  long lVar1;
  
  lVar1 = param_1 + 0xd8;
  down_write(lVar1);
  if (*(char *)(param_1 + 0x376) == '\0') {
    _printk(&DAT_00106e78,"battery_chg_state_cb",param_2);
    up_write(lVar1);
  }
  else {
    *(int *)(param_1 + 0x288) = param_2;
    up_write(lVar1);
    if (param_2 == 0) {
      *(undefined1 *)(param_1 + 0x377) = 0;
    }
    else if (param_2 == 1) {
      queue_work_on(0x20,_system_wq,param_1 + 0x290);
    }
  }
  return;
}



//------------------------------------------------------------
// battery_chg_ship_mode @ 001029c4 size=252
// signature: undefined battery_chg_ship_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_chg_ship_mode(long param_1,long param_2)

{
  char cVar1;
  long lVar2;
  int iVar3;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0x20000800a;
  uStack_40 = 0x47;
  iVar3 = battery_chg_write(param_1 + -0x340,&local_48,0x10);
  if (iVar3 < 0) {
    _printk(&DAT_001073f9,"battery_chg_ship_mode",iVar3);
    cVar1 = *(char *)(param_1 + -0x1b);
  }
  else {
    cVar1 = *(char *)(param_1 + -0x1b);
  }
  if (cVar1 != '\0') {
    local_58 = 0x10000800a;
    uStack_50 = 0x36;
    if ((param_2 == 3) && (iVar3 = battery_chg_write(param_1 + -0x340,&local_58,0x10), iVar3 < 0)) {
      _printk(&DAT_001061d4,"battery_chg_ship_mode",iVar3);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// usb_psy_set_icl @ 00102ac0 size=396
// signature: undefined usb_psy_set_icl(void)
// callers: [battery_chg_subsys_up_work, usb_psy_set_prop]
//------------------------------------------------------------

int usb_psy_set_icl(long param_1,long *param_2,uint param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 local_60;
  undefined4 local_58;
  long local_54;
  int local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (*param_2 == 0) {
    iVar2 = -0x13;
  }
  else {
    local_58 = *(undefined4 *)((long)param_2 + 0x24);
    local_4c = 0;
    local_54 = 0x700000000;
    local_60 = 0x10000800a;
    iVar2 = battery_chg_write(param_1,&local_60,0x18);
    if (iVar2 < 0) {
      _printk(&DAT_00105f17,"usb_psy_set_icl",iVar2);
    }
    else {
      iVar2 = -0x16;
      if ((*(uint *)(param_2[3] + 0x1c) < 7) &&
         ((1 << (ulong)(*(uint *)(param_2[3] + 0x1c) & 0x1f) & 0x4aU) != 0)) {
        if (param_4 < 0) {
          param_4 = -1;
        }
        if (wls_fw_udating == '\x01') {
          iVar2 = -0x6e;
        }
        else {
          local_58 = (undefined4)param_2[5];
          local_60 = 0x10000800a;
          local_54 = (ulong)param_3 << 0x20;
          local_4c = param_4;
          iVar2 = battery_chg_write(param_1,&local_60,0x18);
          if (-1 < iVar2) {
            iVar3 = strcmp((char *)**(undefined8 **)*param_2,"usb-2");
            if (iVar3 == 0) {
              *(int *)(param_1 + 0x368) = param_4;
            }
            else {
              *(int *)(param_1 + 0x364) = param_4;
            }
            goto LAB_00102c14;
          }
        }
        _printk(&DAT_0010678f,"usb_psy_set_icl",param_4,iVar2);
      }
    }
  }
LAB_00102c14:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// usb_psy_get_prop @ 00102c50 size=496
// signature: undefined usb_psy_get_prop(void)
// callers: []
//------------------------------------------------------------

ulong usb_psy_get_prop(undefined8 *param_1,int param_2,int *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar4 = power_supply_get_drvdata();
  iVar3 = strcmp(*(char **)*param_1,"usb-2");
  lVar2 = lVar4 + 0x1d8;
  if (iVar3 != 0) {
    lVar2 = lVar4 + 0x1a8;
  }
  *param_3 = -0x3d;
  lVar1 = 0x1d8;
  if (iVar3 != 0) {
    lVar1 = 0x1a8;
  }
  if (*(uint *)(lVar2 + 0x20) != 0) {
    uVar7 = 0;
    do {
      if (*(int *)(*(long *)(lVar2 + 0x10) + uVar7 * 4) == param_2) {
        iVar3 = (int)uVar7;
        if (iVar3 < 0) {
          uVar8 = uVar7 & 0xffffffff;
          goto LAB_00102cf8;
        }
        if ((iVar3 == 7) || (wls_fw_udating == '\0')) {
          local_58 = *(undefined4 *)(lVar2 + 0x24);
          uStack_4c = 0;
          local_60 = 0x10000800a;
          uStack_54 = 0;
          local_50 = iVar3;
          uVar5 = battery_chg_write(lVar4,&local_60,0x18);
          iVar3 = (int)uVar5;
          if ((iVar3 == -0x68) || (uVar8 = uVar5 & 0xffffffff, iVar3 == -0x6e)) goto LAB_00102e00;
          if (iVar3 < 0) {
            _printk(&DAT_0010714d,"usb_psy_get_prop",uVar7 & 0xffffffff,uVar5 & 0xffffffff);
            goto LAB_00102cf8;
          }
        }
        else {
LAB_00102e00:
          _printk(&DAT_001062e4,"usb_psy_get_prop",uVar7 & 0xffffffff);
        }
        iVar3 = *(int *)(*(long *)(lVar2 + 0x18) + uVar7 * 4);
        *param_3 = iVar3;
        if (param_2 == 0x34) {
          iVar6 = -5;
          if (0 < iVar3) {
            iVar6 = 5;
          }
          uVar8 = 0;
          *param_3 = (iVar6 + iVar3) / 10;
        }
        else {
          uVar8 = 0;
        }
        goto LAB_00102cf8;
      }
      uVar7 = uVar7 + 1;
    } while (*(uint *)(lVar2 + 0x20) != uVar7);
  }
  if (*(undefined8 **)(lVar4 + lVar1) != (undefined8 *)0x0) {
    _printk(&DAT_00106817,"get_property_id",param_2,*(undefined8 *)**(undefined8 **)(lVar4 + lVar1))
    ;
  }
  uVar8 = 0xfffffffe;
LAB_00102cf8:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// usb_psy_set_prop @ 00102e44 size=240
// signature: undefined usb_psy_set_prop(void)
// callers: []
//------------------------------------------------------------

ulong usb_psy_set_prop(undefined8 *param_1,int param_2,undefined4 *param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = power_supply_get_drvdata();
  iVar3 = strcmp(*(char **)*param_1,"usb-2");
  lVar1 = lVar4 + 0x1d8;
  if (iVar3 != 0) {
    lVar1 = lVar4 + 0x1a8;
  }
  lVar2 = 0x1d8;
  if (iVar3 != 0) {
    lVar2 = 0x1a8;
  }
  if (*(uint *)(lVar1 + 0x20) != 0) {
    uVar5 = 0;
    do {
      if (*(int *)(*(long *)(lVar1 + 0x10) + uVar5 * 4) == param_2) {
        if (-1 < (int)uVar5) {
          if (param_2 == 0x26) {
            uVar5 = usb_psy_set_icl(lVar4,lVar1,uVar5,*param_3);
            uVar5 = uVar5 & 0xffffffff;
          }
          else {
            uVar5 = 0;
          }
        }
        goto LAB_00102ed0;
      }
      uVar5 = uVar5 + 1;
    } while (*(uint *)(lVar1 + 0x20) != uVar5);
  }
  if (*(undefined8 **)(lVar4 + lVar2) != (undefined8 *)0x0) {
    _printk(&DAT_00106817,"get_property_id",param_2,*(undefined8 *)**(undefined8 **)(lVar4 + lVar2))
    ;
  }
  uVar5 = 0xfffffffe;
LAB_00102ed0:
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// usb_psy_prop_is_writeable @ 00102f38 size=12
// signature: undefined usb_psy_prop_is_writeable(void)
// callers: []
//------------------------------------------------------------

bool usb_psy_prop_is_writeable(undefined8 param_1,int param_2)

{
  return param_2 == 0x26;
}



//------------------------------------------------------------
// panel_event_notifier_callback @ 00102f48 size=288
// signature: undefined panel_event_notifier_callback(void)
// callers: []
//------------------------------------------------------------

void panel_event_notifier_callback(undefined8 param_1,int *param_2,long param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_3c;
  undefined8 local_34;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_2 != (int *)0x0) {
    if (*param_2 == 2) {
      local_34 = 0;
      local_3c = 0;
      if (*(char *)(param_3 + 0x377) == '\0') {
        local_40 = 4;
        local_48 = 0x20000800a;
        iVar2 = battery_chg_write(param_3,&local_48,0x1c);
        if (iVar2 < 0) {
          _printk(&DAT_00106b67,"battery_chg_notify_enable",iVar2);
        }
        else {
          *(undefined1 *)(param_3 + 0x377) = 1;
        }
      }
    }
    else if (*param_2 == 1) {
      local_34 = 0;
      local_3c = 0;
      if (*(char *)(param_3 + 0x377) != '\0') {
        local_40 = 5;
        local_48 = 0x20000800a;
        iVar2 = battery_chg_write(param_3,&local_48,0x1c);
        if (iVar2 < 0) {
          _printk(&DAT_00106be9,"battery_chg_notify_disable",iVar2);
        }
        else {
          *(undefined1 *)(param_3 + 0x377) = 0;
        }
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wls_psy_get_prop @ 0010306c size=380
// signature: undefined wls_psy_get_prop(void)
// callers: []
//------------------------------------------------------------

ulong wls_psy_get_prop(undefined8 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  int iStack_40;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = power_supply_get_drvdata();
  *param_3 = 0xffffffc3;
  if (*(uint *)(lVar2 + 0x228) != 0) {
    uVar4 = 0;
    do {
      if (*(int *)(*(long *)(lVar2 + 0x218) + uVar4 * 4) == param_2) {
        iVar1 = (int)uVar4;
        if (iVar1 < 0) {
          uVar5 = uVar4 & 0xffffffff;
          goto LAB_00103154;
        }
        if ((iVar1 == 7) || (wls_fw_udating == '\0')) {
          local_44 = 0;
          local_3c = 0;
          local_50 = 0x10000800a;
          local_48 = *(undefined4 *)(lVar2 + 0x22c);
          iStack_40 = iVar1;
          uVar3 = battery_chg_write(lVar2,&local_50,0x18);
          iVar1 = (int)uVar3;
          if ((iVar1 == -0x68) || (uVar5 = uVar3 & 0xffffffff, iVar1 == -0x6e)) goto LAB_001031a8;
          if (iVar1 < 0) {
            _printk(&DAT_0010714d,"wls_psy_get_prop",uVar4 & 0xffffffff,uVar3 & 0xffffffff);
            goto LAB_00103154;
          }
        }
        else {
LAB_001031a8:
          _printk(&DAT_001062e4,"wls_psy_get_prop",uVar4 & 0xffffffff);
        }
        uVar5 = 0;
        *param_3 = *(undefined4 *)(*(long *)(lVar2 + 0x220) + uVar4 * 4);
        goto LAB_00103154;
      }
      uVar4 = uVar4 + 1;
    } while (*(uint *)(lVar2 + 0x228) != uVar4);
  }
  if (*(undefined8 **)(lVar2 + 0x208) != (undefined8 *)0x0) {
    _printk(&DAT_00106817,"get_property_id",param_2,*(undefined8 *)**(undefined8 **)(lVar2 + 0x208))
    ;
  }
  uVar5 = 0xfffffffe;
LAB_00103154:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// wls_psy_set_prop @ 001031ec size=8
// signature: undefined wls_psy_set_prop(void)
// callers: []
//------------------------------------------------------------

undefined8 wls_psy_set_prop(void)

{
  return 0;
}



//------------------------------------------------------------
// wls_psy_prop_is_writeable @ 001031f8 size=8
// signature: undefined wls_psy_prop_is_writeable(void)
// callers: []
//------------------------------------------------------------

undefined8 wls_psy_prop_is_writeable(void)

{
  return 0;
}



//------------------------------------------------------------
// battery_psy_get_prop @ 00103204 size=648
// signature: undefined battery_psy_get_prop(void)
// callers: []
//------------------------------------------------------------

ulong battery_psy_get_prop(undefined8 param_1,uint param_2,uint *param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  undefined8 local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  int local_50;
  undefined4 uStack_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = power_supply_get_drvdata();
  uVar6 = 0x3f;
  if (param_2 != 0x3e) {
    uVar6 = param_2;
  }
  uVar9 = (ulong)uVar6;
  *param_3 = 0xffffffc3;
  if (*(uint *)(lVar3 + 0x198) == 0) {
LAB_00103278:
    if (*(undefined8 **)(lVar3 + 0x178) != (undefined8 *)0x0) {
      _printk(&DAT_00106817,"get_property_id",uVar9,*(undefined8 *)**(undefined8 **)(lVar3 + 0x178))
      ;
    }
    uVar7 = 0xfffffffe;
LAB_00103284:
    lVar3 = sp_el0;
    if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return uVar7;
  }
  uVar8 = 0;
LAB_00103260:
  if (*(uint *)(*(long *)(lVar3 + 0x188) + uVar8 * 4) != uVar6) goto code_r0x0010326c;
  iVar2 = (int)uVar8;
  if (iVar2 < 0) {
    uVar7 = uVar8 & 0xffffffff;
    goto LAB_00103284;
  }
  if ((iVar2 == 7) || (wls_fw_udating == '\0')) {
    local_58 = *(undefined4 *)(lVar3 + 0x19c);
    uStack_4c = 0;
    local_60 = 0x10000800a;
    uStack_54 = 0;
    local_50 = iVar2;
    uVar4 = battery_chg_write(lVar3,&local_60,0x18);
    iVar2 = (int)uVar4;
    if ((iVar2 == -0x68) || (uVar7 = uVar4 & 0xffffffff, iVar2 == -0x6e)) goto LAB_00103384;
    if (-1 < iVar2) {
      if (uVar6 < 0x4a) goto LAB_00103318;
switchD_0010332c_caseD_1033a8:
      uVar6 = *(uint *)(*(long *)(lVar3 + 400) + uVar8 * 4);
      goto LAB_00103454;
    }
    _printk(&DAT_0010714d,"battery_psy_get_prop",uVar8 & 0xffffffff,uVar4 & 0xffffffff);
    goto LAB_00103284;
  }
LAB_00103384:
  _printk(&DAT_0010652a,"battery_psy_get_prop",uVar8 & 0xffffffff);
  uVar7 = 0;
  if (0x49 < uVar6) goto switchD_0010332c_caseD_1033a8;
LAB_00103318:
  switch((ulong)(&switchD_0010332c::switchdataD_001058af)[uVar9] * 4 + 0x103330) {
  case 0x103330:
    if (*(long *)(lVar3 + 0x388) == 0) goto switchD_0010332c_caseD_1033a8;
    lVar5 = *(long *)(lVar3 + 400);
    goto LAB_00103340;
  default:
    goto switchD_0010332c_caseD_1033a8;
  case 0x1033b4:
    *param_3 = *(uint *)(*(long *)(lVar3 + 400) + uVar8 * 4);
    if ((*(long *)(lVar3 + 0x388) != 0) && (*(char *)(lVar3 + 0x380) == '\0')) {
      lVar5 = *(long *)(lVar3 + 400);
      uVar9 = 7;
LAB_00103340:
      *param_3 = *(uint *)(lVar5 + uVar8 * 4);
      lVar5 = *(long *)(lVar3 + 0x388);
LAB_0010334c:
      power_supply_get_property(lVar5,uVar9,param_3);
    }
    goto LAB_00103284;
  case 0x1033dc:
    uVar6 = *(uint *)(lVar3 + 0x27c);
    break;
  case 0x1033e4:
    uVar6 = *(uint *)(lVar3 + 0x280);
    break;
  case 0x1033ec:
    *param_3 = (*(int *)(*(long *)(lVar3 + 400) + uVar8 * 4) + 0x32U) / 100;
    lVar5 = *(long *)(lVar3 + 0x388);
    if ((lVar5 != 0) && (*(char *)(lVar3 + 0x380) == '\0')) {
      uVar9 = 0x2f;
      goto LAB_0010334c;
    }
    goto LAB_00103284;
  case 0x103424:
    iVar1 = *(int *)(*(long *)(lVar3 + 400) + uVar8 * 4);
    iVar2 = -5;
    if (0 < iVar1) {
      iVar2 = 5;
    }
    uVar6 = (iVar2 + iVar1) / 10;
    break;
  case 0x10345c:
    *(undefined8 *)param_3 = *(undefined8 *)(lVar3 + 0x180);
    goto LAB_00103284;
  }
LAB_00103454:
  *param_3 = uVar6;
  goto LAB_00103284;
code_r0x0010326c:
  uVar8 = uVar8 + 1;
  if (*(uint *)(lVar3 + 0x198) == uVar8) goto LAB_00103278;
  goto LAB_00103260;
}



//------------------------------------------------------------
// battery_psy_set_prop @ 00103490 size=716
// signature: undefined battery_psy_set_prop(void)
// callers: []
//------------------------------------------------------------

int battery_psy_set_prop(undefined8 param_1,undefined4 param_2,uint *param_3)

{
  byte bVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  undefined8 local_50;
  undefined4 local_48;
  undefined4 local_44;
  uint uStack_40;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = power_supply_get_drvdata();
  iVar2 = -0x16;
  switch(param_2) {
  case 7:
    if ((*(long *)(lVar3 + 0x388) != 0) && (*(char *)(lVar3 + 0x380) == '\0')) {
      iVar2 = power_supply_set_property(*(long *)(lVar3 + 0x388),7,param_3);
      break;
    }
    uVar7 = *param_3;
    if (wls_fw_udating == '\x01') {
      iVar2 = -0x6e;
    }
    else {
      local_48 = *(undefined4 *)(lVar3 + 0x1a0);
      local_44 = 0;
      uStack_40 = 0xf;
      local_50 = 0x10000800a;
      local_3c = uVar7;
      iVar2 = battery_chg_write(lVar3,&local_50,0x18);
      if (-1 < iVar2) {
        _printk(&DAT_00106709,"battery_psy_set_cycle_count",uVar7);
        break;
      }
    }
    puVar4 = &DAT_00107540;
    pcVar5 = "battery_psy_set_cycle_count";
LAB_0010372c:
    _printk(puVar4,pcVar5,uVar7,iVar2);
    break;
  case 0x21:
    iVar2 = battery_psy_set_charge_current(lVar3,*param_3);
    break;
  case 0x23:
    uVar7 = *param_3;
    if (uVar7 - 0x60 < 0xffffffd2) {
      _printk(&DAT_00106a4b,"battery_psy_set_charge_start_threshold",0x32,0x5f);
      break;
    }
    if (*(char *)(lVar3 + 0x373) == '\0') {
      iVar2 = 0;
    }
    else {
      bVar1 = *(byte *)(lVar3 + 0x372);
      uStack_40 = uVar7 + 5;
      uVar6 = (uint)bVar1;
      if (uVar7 <= uVar6) {
        uStack_40 = (uint)bVar1;
      }
      local_3c = 5;
      if (uVar7 <= uVar6) {
        local_3c = uVar6 - uVar7;
      }
      if (99 < uStack_40) {
        uStack_40 = 100;
      }
      local_50 = 0x10000800a;
      local_48 = 0x48;
      local_44 = 1;
      iVar2 = battery_chg_write(lVar3,&local_50,0x18);
      if (iVar2 < 0) {
        _printk(&DAT_00106354,"battery_psy_set_charge_threshold",iVar2);
        puVar4 = &DAT_0010663e;
        pcVar5 = "battery_psy_set_charge_start_threshold";
        goto LAB_0010372c;
      }
    }
    *(char *)(lVar3 + 0x371) = (char)uVar7;
    break;
  case 0x24:
    uVar7 = *param_3;
    if (uVar7 - 0x65 < 0xffffffd2) {
      _printk(&DAT_001071e8,"battery_psy_set_charge_end_threshold",0x37,100);
      break;
    }
    if (*(char *)(lVar3 + 0x373) == '\0') {
      iVar2 = 0;
    }
    else {
      uVar6 = (uint)*(byte *)(lVar3 + 0x371);
      local_3c = uVar7 - uVar6;
      if ((uVar7 < uVar6 || local_3c == 0) || uVar6 == 0) {
        local_3c = 5;
      }
      local_50 = 0x10000800a;
      local_48 = 0x48;
      local_44 = 1;
      uStack_40 = uVar7;
      iVar2 = battery_chg_write(lVar3,&local_50,0x18);
      if (iVar2 < 0) {
        _printk(&DAT_00106354,"battery_psy_set_charge_threshold",iVar2);
        puVar4 = &DAT_00106ad8;
        pcVar5 = "battery_psy_set_charge_end_threshold";
        goto LAB_0010372c;
      }
    }
    *(char *)(lVar3 + 0x372) = (char)uVar7;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// battery_psy_prop_is_writeable @ 00103760 size=52
// signature: undefined battery_psy_prop_is_writeable(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_psy_prop_is_writeable(undefined8 param_1,uint param_2)

{
  if ((param_2 < 0x25) && ((1L << ((ulong)param_2 & 0x3f) & 0x1a00000080U) != 0)) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// battery_psy_set_charge_current @ 00103794 size=364
// signature: undefined battery_psy_set_charge_current(void)
// callers: [battery_chg_set_cur_charge_cntl_limit, battery_psy_set_prop]
//------------------------------------------------------------

int battery_psy_set_charge_current(long param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  iVar1 = *(int *)(param_1 + 0x280);
  if (iVar1 == 0) {
LAB_00103810:
    iVar4 = 0;
    goto LAB_00103814;
  }
  if (iVar1 < 0) {
    _printk(&DAT_0010660d,"battery_psy_set_charge_current");
    iVar4 = -0x16;
    goto LAB_00103814;
  }
  iVar4 = -0x16;
  if (((int)param_2 < 0) || (iVar1 < (int)param_2)) goto LAB_00103814;
  if (*(int *)(param_1 + 0x36c) == 0) {
    uVar5 = *(uint *)(*(long *)(param_1 + 0x248) + (ulong)param_2 * 4);
  }
  else {
    uVar5 = *(int *)(*(long *)(param_1 + 400) + 0x2c) - *(int *)(param_1 + 0x36c) * param_2;
  }
  uVar2 = *(uint *)(param_1 + 0x358);
  *(uint *)(param_1 + 0x358) = uVar5;
  if (uVar2 == uVar5) goto LAB_00103810;
  uVar6 = uVar5;
  if ((*(char *)(param_1 + 0x370) != '\0') &&
     (uVar6 = *(uint *)(param_1 + 0x35c), uVar5 <= *(uint *)(param_1 + 0x35c))) {
    uVar6 = uVar5;
  }
  if (wls_fw_udating == '\x01') {
    iVar4 = -0x6e;
LAB_001038dc:
    _printk(&DAT_001073bd,"__battery_psy_set_charge_current",uVar6,iVar4);
  }
  else {
    local_58 = *(undefined4 *)(param_1 + 0x1a0);
    local_54 = 0xa00000000;
    local_60 = 0x10000800a;
    local_4c = uVar6;
    iVar4 = battery_chg_write(param_1,&local_60,0x18);
    if (iVar4 < 0) goto LAB_001038dc;
    *(uint *)(param_1 + 0x360) = uVar6;
    if (iVar4 == 0) {
      *(uint *)(param_1 + 0x27c) = param_2;
      goto LAB_00103814;
    }
  }
  *(uint *)(param_1 + 0x358) = uVar2;
LAB_00103814:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// soh_show @ 00103904 size=192
// signature: undefined soh_show(void)
// callers: []
//------------------------------------------------------------

long soh_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x194);
    local_2c = 0;
    local_34 = 0x500000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x188) + 0x14));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// resistance_show @ 001039c8 size=192
// signature: undefined resistance_show(void)
// callers: []
//------------------------------------------------------------

long resistance_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x194);
    local_2c = 0;
    local_34 = 0x1500000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x188) + 0x54));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// moisture_detection_status_show @ 00103a8c size=192
// signature: undefined moisture_detection_status_show(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x1c4);
    local_2c = 0;
    local_34 = 0x900000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1b8) + 0x24));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// moisture_detection_usb_2_status_show @ 00103b50 size=192
// signature: undefined moisture_detection_usb_2_status_show(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_usb_2_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 500);
    local_2c = 0;
    local_34 = 0x900000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1e8) + 0x24));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// moisture_detection_en_show @ 00103c14 size=192
// signature: undefined moisture_detection_en_show(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x1c4);
    local_2c = 0;
    local_34 = 0x800000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1b8) + 0x20));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// moisture_detection_en_store @ 00103cd8 size=200
// signature: undefined moisture_detection_en_store(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_en_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  byte local_44 [4];
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_44[0] = 0;
  iVar2 = kstrtobool(param_3,local_44);
  if (iVar2 == 0) {
    if (wls_fw_udating == '\x01') {
      param_4 = -0x6e;
    }
    else {
      local_38 = *(undefined4 *)(param_1 + 0x1c8);
      local_34 = 0x800000000;
      local_2c = (uint)local_44[0];
      local_40 = 0x10000800a;
      iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
      if (iVar2 < 0) {
        param_4 = (long)iVar2;
      }
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// moisture_detection_usb_2_en_show @ 00103da4 size=192
// signature: undefined moisture_detection_usb_2_en_show(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_usb_2_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 500);
    local_2c = 0;
    local_34 = 0x800000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1e8) + 0x20));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// moisture_detection_usb_2_en_store @ 00103e68 size=200
// signature: undefined moisture_detection_usb_2_en_store(void)
// callers: []
//------------------------------------------------------------

long moisture_detection_usb_2_en_store
               (long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  byte local_44 [4];
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_44[0] = 0;
  iVar2 = kstrtobool(param_3,local_44);
  if (iVar2 == 0) {
    if (wls_fw_udating == '\x01') {
      param_4 = -0x6e;
    }
    else {
      local_38 = *(undefined4 *)(param_1 + 0x1f8);
      local_34 = 0x800000000;
      local_2c = (uint)local_44[0];
      local_40 = 0x10000800a;
      iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
      if (iVar2 < 0) {
        param_4 = (long)iVar2;
      }
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// fake_soc_show @ 00103f34 size=56
// signature: undefined fake_soc_show(void)
// callers: []
//------------------------------------------------------------

long fake_soc_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106452,*(undefined4 *)(param_1 + 0x318));
  return (long)iVar1;
}



//------------------------------------------------------------
// fake_soc_store @ 00103f70 size=132
// signature: undefined fake_soc_store(void)
// callers: []
//------------------------------------------------------------

undefined8 fake_soc_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x318) = local_2c;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ship_mode_en_show @ 00103ff8 size=56
// signature: undefined ship_mode_en_show(void)
// callers: []
//------------------------------------------------------------

long ship_mode_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106452,*(undefined1 *)(param_1 + 0x31d));
  return (long)iVar1;
}



//------------------------------------------------------------
// ship_mode_en_store @ 00104034 size=60
// signature: undefined ship_mode_en_store(void)
// callers: []
//------------------------------------------------------------

undefined8 ship_mode_en_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = kstrtobool(param_3,param_1 + 0x31d);
  if (iVar1 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// restrict_chg_show @ 00104074 size=56
// signature: undefined restrict_chg_show(void)
// callers: []
//------------------------------------------------------------

long restrict_chg_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106452,*(undefined1 *)(param_1 + 0x368));
  return (long)iVar1;
}



//------------------------------------------------------------
// restrict_chg_store @ 001040b0 size=300
// signature: undefined restrict_chg_store(void)
// callers: []
//------------------------------------------------------------

void restrict_chg_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  char local_54 [4];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  uint local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_54[0] = '\0';
  iVar3 = kstrtobool(param_3,local_54);
  if (iVar3 != 0) {
    lVar4 = -0x16;
    goto LAB_00104188;
  }
  *(char *)(param_1 + 0x368) = local_54[0];
  lVar4 = 0x350;
  if (local_54[0] != '\0') {
    lVar4 = 0x354;
  }
  uVar5 = *(uint *)(param_1 + lVar4);
  if (local_54[0] != '\0') {
    uVar1 = *(uint *)(param_1 + 0x354);
    if (uVar5 <= *(uint *)(param_1 + 0x354)) {
      uVar1 = uVar5;
    }
    uVar5 = uVar1;
    if (*(uint *)(param_1 + 0x350) <= uVar1) {
      uVar5 = *(uint *)(param_1 + 0x350);
    }
  }
  if (wls_fw_udating == '\x01') {
    iVar3 = -0x6e;
LAB_001041b8:
    _printk(&DAT_001073bd,"__battery_psy_set_charge_current",uVar5,iVar3);
  }
  else {
    local_48 = *(undefined4 *)(param_1 + 0x198);
    local_44 = 0xa00000000;
    local_50 = 0x10000800a;
    local_3c = uVar5;
    iVar3 = battery_chg_write(param_1 + -8,&local_50,0x18);
    if (iVar3 < 0) goto LAB_001041b8;
    *(uint *)(param_1 + 0x358) = uVar5;
  }
  lVar4 = (long)iVar3;
  if (-1 < iVar3) {
    lVar4 = param_4;
  }
LAB_00104188:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// restrict_cur_show @ 001041e0 size=56
// signature: undefined restrict_cur_show(void)
// callers: []
//------------------------------------------------------------

long restrict_cur_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106452,*(undefined4 *)(param_1 + 0x354));
  return (long)iVar1;
}



//------------------------------------------------------------
// restrict_cur_store @ 0010421c size=304
// signature: undefined restrict_cur_store(void)
// callers: []
//------------------------------------------------------------

long restrict_cur_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  uint local_64;
  undefined8 local_60;
  undefined4 local_58;
  undefined8 local_54;
  uint local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_64 = 0;
  iVar5 = kstrtouint(param_3,0,&local_64);
  if ((iVar5 == 0) && (uVar2 = *(uint *)(param_1 + 0x350), local_64 <= uVar2)) {
    uVar3 = *(undefined4 *)(param_1 + 0x354);
    *(uint *)(param_1 + 0x354) = local_64;
    if (*(char *)(param_1 + 0x368) != '\0') {
      uVar1 = local_64;
      if (uVar2 <= local_64) {
        uVar1 = uVar2;
      }
      if (wls_fw_udating == '\x01') {
        iVar5 = -0x6e;
      }
      else {
        local_58 = *(undefined4 *)(param_1 + 0x198);
        local_54 = 0xa00000000;
        local_60 = 0x10000800a;
        local_4c = uVar1;
        iVar5 = battery_chg_write(param_1 + -8,&local_60,0x18);
        if (-1 < iVar5) {
          *(uint *)(param_1 + 0x358) = uVar1;
          goto LAB_0010427c;
        }
      }
      _printk(&DAT_001073bd,"__battery_psy_set_charge_current",uVar1,iVar5);
      param_4 = (long)iVar5;
      *(undefined4 *)(param_1 + 0x354) = uVar3;
    }
  }
  else {
    param_4 = -0x16;
  }
LAB_0010427c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// usb_real_type_show @ 00104350 size=284
// signature: undefined usb_real_type_show(void)
// callers: []
//------------------------------------------------------------

long usb_real_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  ulong uVar6;
  undefined **ppuVar7;
  ulong uVar8;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar4 = -0x6e;
    goto LAB_0010443c;
  }
  local_38 = *(undefined4 *)(param_1 + 0x1c4);
  local_2c = 0;
  local_34 = 0xb00000000;
  local_40 = 0x10000800a;
  iVar4 = battery_chg_write(param_1 + -8,&local_40,0x18);
  if (iVar4 < 0) goto LAB_0010443c;
  uVar1 = *(uint *)(*(long *)(param_1 + 0x1b8) + 0x2c);
  uVar6 = (ulong)uVar1;
  uVar8 = (ulong)(uVar1 - 0x80);
  if (uVar1 - 0x80 < 3) {
    ppuVar7 = &qc_power_supply_usb_type_text + uVar8;
    if (0x18 < uVar8 * 8 || uVar8 * -8 == -0x18) {
LAB_0010441c:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x104420);
      (*pcVar3)();
    }
LAB_001043f4:
    pcVar5 = *ppuVar7;
  }
  else {
    if (uVar1 < 10) {
      ppuVar7 = &power_supply_usb_type_text + uVar6;
      if (0x50 < uVar6 * 8 || uVar6 * -8 == -0x50) goto LAB_0010441c;
      goto LAB_001043f4;
    }
    pcVar5 = "Unknown";
  }
  iVar4 = scnprintf(param_3,0x1000,&DAT_00106f48,pcVar5);
LAB_0010443c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar4;
}



//------------------------------------------------------------
// usb_2_real_type_show @ 00104470 size=284
// signature: undefined usb_2_real_type_show(void)
// callers: []
//------------------------------------------------------------

long usb_2_real_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  ulong uVar6;
  undefined **ppuVar7;
  ulong uVar8;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar4 = -0x6e;
    goto LAB_0010455c;
  }
  local_38 = *(undefined4 *)(param_1 + 500);
  local_2c = 0;
  local_34 = 0xb00000000;
  local_40 = 0x10000800a;
  iVar4 = battery_chg_write(param_1 + -8,&local_40,0x18);
  if (iVar4 < 0) goto LAB_0010455c;
  uVar1 = *(uint *)(*(long *)(param_1 + 0x1e8) + 0x2c);
  uVar6 = (ulong)uVar1;
  uVar8 = (ulong)(uVar1 - 0x80);
  if (uVar1 - 0x80 < 3) {
    ppuVar7 = &qc_power_supply_usb_type_text + uVar8;
    if (0x18 < uVar8 * 8 || uVar8 * -8 == -0x18) {
LAB_0010453c:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x104540);
      (*pcVar3)();
    }
LAB_00104514:
    pcVar5 = *ppuVar7;
  }
  else {
    if (uVar1 < 10) {
      ppuVar7 = &power_supply_usb_type_text + uVar6;
      if (0x50 < uVar6 * 8 || uVar6 * -8 == -0x50) goto LAB_0010453c;
      goto LAB_00104514;
    }
    pcVar5 = "Unknown";
  }
  iVar4 = scnprintf(param_3,0x1000,&DAT_00106f48,pcVar5);
LAB_0010455c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar4;
}



//------------------------------------------------------------
// usb_typec_compliant_show @ 00104590 size=192
// signature: undefined usb_typec_compliant_show(void)
// callers: []
//------------------------------------------------------------

long usb_typec_compliant_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x1c4);
    local_2c = 0;
    local_34 = 0xc00000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1b8) + 0x30));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// usb_num_ports_show @ 00104654 size=192
// signature: undefined usb_num_ports_show(void)
// callers: []
//------------------------------------------------------------

long usb_num_ports_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x1c4);
    local_2c = 0;
    local_34 = 0x1000000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1b8) + 0x40));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// usb_2_typec_compliant_show @ 00104718 size=192
// signature: undefined usb_2_typec_compliant_show(void)
// callers: []
//------------------------------------------------------------

long usb_2_typec_compliant_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 500);
    local_2c = 0;
    local_34 = 0xc00000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x1e8) + 0x30));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// charge_control_en_show @ 001047dc size=248
// signature: undefined charge_control_en_show(void)
// callers: []
//------------------------------------------------------------

long charge_control_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_48 = *(undefined4 *)(param_1 + 0x194);
    local_3c = 0;
    local_44 = 0x1800000000;
    local_50 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_50,0x18);
    if (-1 < iVar2) {
      *(bool *)(param_1 + 0x36b) = *(int *)(*(long *)(param_1 + 0x188) + 0x60) != 0;
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452);
      goto LAB_00104878;
    }
  }
  _printk(&DAT_001060d8,"get_charge_control_en",iVar2);
LAB_00104878:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// charge_control_en_store @ 001048d8 size=260
// signature: undefined charge_control_en_store(void)
// callers: []
//------------------------------------------------------------

long charge_control_en_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  byte local_54 [4];
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_54[0] = 0;
  iVar2 = kstrtobool(param_3,local_54);
  if (iVar2 == 0) {
    if ((uint)local_54[0] != (uint)*(byte *)(param_1 + 0x36b)) {
      if (wls_fw_udating == '\x01') {
        iVar2 = -0x6e;
      }
      else {
        local_48 = *(undefined4 *)(param_1 + 0x198);
        local_44 = 0x1800000000;
        local_50 = 0x10000800a;
        local_3c = (uint)local_54[0];
        iVar2 = battery_chg_write(param_1 + -8,&local_50,0x18);
        if (-1 < iVar2) {
          *(byte *)(param_1 + 0x36b) = local_54[0];
          goto LAB_0010497c;
        }
      }
      _printk(&DAT_00105e69,"charge_control_en_store",iVar2);
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
LAB_0010497c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// fake_batt_temp_store @ 001049e0 size=112
// signature: undefined fake_batt_temp_store(void)
// callers: []
//------------------------------------------------------------

void fake_batt_temp_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  lVar1 = sp_el0;
  if (iVar2 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wireless_boost_en_show @ 00104a54 size=192
// signature: undefined wireless_boost_en_show(void)
// callers: []
//------------------------------------------------------------

long wireless_boost_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar2 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x224);
    local_2c = 0;
    local_34 = 0x600000000;
    local_40 = 0x10000800a;
    iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar2) {
      iVar2 = scnprintf(param_3,0x1000,&DAT_00106452,
                        *(undefined4 *)(*(long *)(param_1 + 0x218) + 0x18));
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// wireless_boost_en_store @ 00104b18 size=200
// signature: undefined wireless_boost_en_store(void)
// callers: []
//------------------------------------------------------------

long wireless_boost_en_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  byte local_44 [4];
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_44[0] = 0;
  iVar2 = kstrtobool(param_3,local_44);
  if (iVar2 == 0) {
    if (wls_fw_udating == '\x01') {
      param_4 = -0x6e;
    }
    else {
      local_38 = *(undefined4 *)(param_1 + 0x228);
      local_34 = 0x600000000;
      local_2c = (uint)local_44[0];
      local_40 = 0x10000800a;
      iVar2 = battery_chg_write(param_1 + -8,&local_40,0x18);
      if (iVar2 < 0) {
        param_4 = (long)iVar2;
      }
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wireless_fw_update_store @ 00104be4 size=224
// signature: undefined wireless_fw_update_store(void)
// callers: []
//------------------------------------------------------------

void wireless_fw_update_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  char local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_2c);
  lVar3 = -0x16;
  if ((iVar2 == 0) && (local_2c[0] != '\0')) {
    if ((wls_fw_udating & 1) == 0) {
      param_1 = param_1 + -8;
      iVar2 = wireless_fw_update(param_1,0);
      if (((iVar2 == -0x68) || (iVar2 == -0x6e)) &&
         ((iVar2 = wireless_fw_update(param_1,0), iVar2 == -0x68 || (iVar2 == -0x6e)))) {
        iVar2 = wireless_fw_update(param_1,0);
      }
      lVar3 = (long)iVar2;
      if (-1 < iVar2) {
        lVar3 = param_4;
      }
    }
    else {
      lVar3 = -0x10;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wireless_fw_update @ 00104cc4 size=1088
// signature: undefined wireless_fw_update(void)
// callers: [wireless_fw_update_store, wireless_fw_force_update_store]
//------------------------------------------------------------

int wireless_fw_update(undefined8 *param_1,ulong param_2)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  ulong *local_58;
  undefined8 local_50;
  undefined4 local_48;
  undefined8 local_44;
  undefined4 local_3c;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  local_58 = (ulong *)0x0;
  if (param_1[0x4a] == 0) {
    _printk(&DAT_001074de,"wireless_fw_update");
    iVar5 = -0x16;
    goto LAB_00104ee8;
  }
  pm_stay_awake(*param_1);
  if (wls_fw_udating == '\x01') goto LAB_00104d14;
  local_48 = *(undefined4 *)((long)param_1 + 0x1cc);
  local_44 = 0;
  local_3c = 0;
  local_50 = 0x10000800a;
  iVar5 = battery_chg_write(param_1,&local_50,0x18);
  if (-1 < iVar5) {
    if ((*(int *)((long)param_1 + 0x37c) == 2) && (*(int *)param_1[0x38] == 0)) {
      if (wls_fw_udating == '\x01') goto LAB_00104d14;
      local_48 = *(undefined4 *)((long)param_1 + 0x1fc);
      local_44 = 0;
      local_3c = 0;
      local_50 = 0x10000800a;
      iVar5 = battery_chg_write(param_1,&local_50,0x18);
      if (iVar5 < 0) goto LAB_00104edc;
      lVar9 = 2;
    }
    else {
      lVar9 = 1;
    }
    if (*(int *)param_1[lVar9 * 6 + 0x32] == 0) {
      if (wls_fw_udating == '\x01') goto LAB_00104d14;
      local_48 = *(undefined4 *)((long)param_1 + 0x19c);
      local_3c = 0;
      local_44 = 0x400000000;
      local_50 = 0x10000800a;
      iVar5 = battery_chg_write(param_1,&local_50,0x18);
      if (-1 < iVar5) {
        if (1999 < *(uint *)(param_1[0x32] + 0x10)) goto LAB_00104d7c;
        puVar7 = &DAT_0010687d;
LAB_00104f20:
        _printk(puVar7,"wireless_fw_update");
        iVar5 = -0x16;
      }
    }
    else {
LAB_00104d7c:
      if (wls_fw_udating == '\x01') {
LAB_00104d14:
        iVar5 = -0x6e;
      }
      else {
        local_48 = *(undefined4 *)((long)param_1 + 0x22c);
        local_44 = 0;
        local_3c = 0;
        local_50 = 0x10000800a;
        iVar5 = battery_chg_write(param_1,&local_50,0x18);
        if (iVar5 < 0) goto LAB_00104edc;
        if (*(int *)param_1[0x44] != 0) {
          puVar7 = &DAT_001068c8;
          goto LAB_00104f20;
        }
        iVar5 = firmware_request_nowarn(&local_58,param_1[0x4a],*param_1);
        if (iVar5 != 0) {
          _printk(&DAT_00105ea4,"wireless_fw_update",iVar5);
          goto LAB_00104edc;
        }
        if (((local_58 == (ulong *)0x0) || (uVar10 = local_58[1], uVar10 == 0)) ||
           (uVar11 = *local_58, uVar11 == 0)) {
          _printk(&DAT_00106f4f,"wireless_fw_update");
LAB_00104e08:
          iVar5 = -0x16;
        }
        else {
          if (uVar11 >> 0xe == 0) {
            _printk(&DAT_00106690,"wireless_fw_update",uVar11);
            goto LAB_00104e08;
          }
          if (*(int *)(param_1 + 0x66) == 1) {
            bVar2 = *(byte *)(uVar10 + 0xc4);
            bVar3 = *(byte *)(uVar10 + 0xc5);
            _printk(&DAT_00106463,"wireless_fw_update",bVar2,bVar3);
            uVar4 = (uint)bVar3 | (uint)bVar2 << 0x10;
            uVar11 = *local_58;
          }
          else {
            pcVar6 = strstr((char *)param_1[0x4a],"9412");
            lVar9 = 0x86;
            if (pcVar6 != (char *)0x0) {
              lVar9 = 0x96;
            }
            lVar1 = 0x84;
            if (pcVar6 != (char *)0x0) {
              lVar1 = 0x94;
            }
            uVar4 = CONCAT22(*(undefined2 *)(uVar10 + lVar1),*(undefined2 *)(uVar10 + lVar9));
          }
          if ((param_2 & 1) != 0) {
            uVar4 = 0xffffffff;
          }
          _printk(&DAT_00106f74,"wireless_fw_update",uVar11,uVar4);
          iVar5 = wireless_fw_check_for_update(param_1,uVar4,*local_58);
          if (iVar5 < 0) {
            puVar7 = &DAT_00106fa2;
LAB_0010503c:
            _printk(puVar7,"wireless_fw_update",iVar5);
          }
          else if (*(char *)(param_1 + 0x65) == '\0') {
            _printk(&DAT_0010734d,"wireless_fw_update");
          }
          else {
            msleep(2000);
            *(undefined4 *)(param_1 + 0x2b) = 0;
            wls_fw_udating = '\x01';
            iVar5 = wireless_fw_send_firmware(param_1,local_58);
            if (iVar5 < 0) {
              puVar7 = &DAT_00105ed4;
              goto LAB_0010503c;
            }
            uVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x67));
            iVar5 = wait_for_completion_timeout(param_1 + 0x2b,uVar8);
            if (iVar5 == 0) {
              _printk(&DAT_00106748,"wireless_fw_update");
              iVar5 = -0x6e;
            }
            else {
              _printk(&DAT_00106397,"wireless_fw_update");
              iVar5 = 0;
            }
          }
        }
        *(undefined2 *)((long)param_1 + 0x334) = 0;
        release_firmware(local_58);
      }
    }
  }
LAB_00104edc:
  pm_relax(*param_1);
  wls_fw_udating = '\0';
LAB_00104ee8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// wireless_fw_check_for_update @ 00105104 size=112
// signature: undefined wireless_fw_check_for_update(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

void wireless_fw_check_for_update(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  undefined8 local_30;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  uint uStack_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = 0x40;
  *(undefined1 *)(param_1 + 0x328) = 0;
  local_30 = 0x10000800a;
  uStack_1c = (uint)*(ushort *)(param_1 + 0x334);
  uStack_24 = param_2;
  local_20 = param_3;
  battery_chg_write(param_1,&local_30,0x18);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wireless_fw_send_firmware @ 00105174 size=440
// signature: undefined wireless_fw_send_firmware(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

void wireless_fw_send_firmware(undefined8 param_1,ulong *param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 *__src;
  int iVar3;
  ulong uVar4;
  int iVar5;
  undefined8 local_e8;
  undefined4 local_e0;
  undefined8 local_dc;
  undefined8 local_d4;
  undefined8 local_cc;
  undefined8 local_c4;
  undefined8 local_bc;
  undefined8 local_b4;
  undefined8 local_ac;
  undefined8 local_a4;
  undefined8 local_9c;
  undefined8 local_94;
  undefined8 local_8c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  int local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  uVar4 = *param_2;
  local_64 = 0;
  local_6c = 0;
  local_74 = 0;
  local_7c = 0;
  local_84 = 0;
  local_8c = 0;
  local_94 = 0;
  local_9c = 0;
  local_a4 = 0;
  local_ac = 0;
  local_b4 = 0;
  local_bc = 0;
  local_c4 = 0;
  local_cc = 0;
  local_d4 = 0;
  local_dc = 0;
  iVar3 = (int)(uVar4 >> 7);
  if (iVar3 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    iVar5 = 0;
    __src = (undefined8 *)param_2[1];
    local_e8 = 0x10000800a;
    local_e0 = 0x41;
    do {
      iVar5 = iVar5 + 1;
      local_cc = __src[2];
      local_c4 = __src[3];
      local_dc = *__src;
      local_d4 = __src[1];
      local_ac = __src[6];
      local_a4 = __src[7];
      local_bc = __src[4];
      local_b4 = __src[5];
      local_8c = __src[10];
      local_84 = __src[0xb];
      local_9c = __src[8];
      local_94 = __src[9];
      local_6c = __src[0xe];
      local_64 = __src[0xf];
      local_7c = __src[0xc];
      local_74 = __src[0xd];
      local_5c = iVar5;
      uVar2 = battery_chg_fw_write(param_1,&local_e8);
      if ((int)uVar2 < 0) goto LAB_001052f4;
      __src = __src + 0x10;
    } while (iVar3 != iVar5);
    uVar4 = uVar4 & 0x7f;
    if (uVar4 != 0) {
      local_5c = iVar3 + 1;
      local_dc = 0;
      local_d4 = 0;
      local_cc = 0;
      local_c4 = 0;
      local_bc = 0;
      local_b4 = 0;
      local_ac = 0;
      local_a4 = 0;
      local_9c = 0;
      local_94 = 0;
      local_8c = 0;
      local_84 = 0;
      local_7c = 0;
      local_74 = 0;
      local_6c = 0;
      local_64 = 0;
      memcpy(&local_dc,__src,uVar4);
      uVar2 = battery_chg_fw_write(param_1,&local_e8);
      if ((int)uVar2 < 0) goto LAB_001052f4;
    }
    uVar2 = 0;
  }
LAB_001052f4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// battery_chg_fw_write @ 0010532c size=188
// signature: undefined battery_chg_fw_write(void)
// callers: [wireless_fw_send_firmware]
//------------------------------------------------------------

undefined8 battery_chg_fw_write(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  lVar1 = param_1 + 0xd8;
  down_read(lVar1);
  if (*(int *)(param_1 + 0x288) == 0) {
    _printk(&DAT_001063c3,"battery_chg_fw_write");
    up_read(lVar1);
    uVar3 = 0xffffff95;
  }
  else {
    up_read(lVar1);
    *(undefined4 *)(param_1 + 0x138) = 0;
    uVar3 = pmic_glink_write(*(undefined8 *)(param_1 + 0xa0),param_2,0x90);
    if ((int)uVar3 == 0) {
      iVar2 = wait_for_completion_timeout(param_1 + 0x138,0x4e2);
      if (iVar2 == 0) {
        _printk(&DAT_00106e23,"battery_chg_fw_write",5000);
        uVar3 = 0xffffff92;
      }
      else {
        uVar3 = 0;
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// wireless_fw_force_update_store @ 001053ec size=164
// signature: undefined wireless_fw_force_update_store(void)
// callers: []
//------------------------------------------------------------

void wireless_fw_force_update_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  char local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_3,local_2c);
  lVar3 = -0x16;
  if ((iVar2 == 0) && (local_2c[0] != '\0')) {
    if ((wls_fw_udating & 1) == 0) {
      iVar2 = wireless_fw_update(param_1 + -8,1);
      lVar3 = (long)iVar2;
      if (-1 < iVar2) {
        lVar3 = param_4;
      }
    }
    else {
      lVar3 = -0x10;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wireless_fw_version_show @ 00105494 size=196
// signature: undefined wireless_fw_version_show(void)
// callers: []
//------------------------------------------------------------

long wireless_fw_version_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0x10000800a;
  local_40 = 0x44;
  iVar2 = battery_chg_write(param_1 + -8,&local_48,0xc);
  if (iVar2 < 0) {
    _printk(&DAT_00106490,"wireless_fw_version_show",iVar2);
  }
  else {
    iVar2 = scnprintf(param_3,0x1000,&DAT_00107020,*(undefined4 *)(param_1 + 0x324));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// wireless_fw_crc_store @ 0010555c size=136
// signature: undefined wireless_fw_crc_store(void)
// callers: []
//------------------------------------------------------------

void wireless_fw_crc_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  short local_2c [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = kstrtou16(param_3,0,local_2c);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_2c[0] != 0)) {
    *(short *)(param_1 + 0x32c) = local_2c[0];
    uVar3 = param_4;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// wireless_fw_update_time_ms_show @ 001055e8 size=56
// signature: undefined wireless_fw_update_time_ms_show(void)
// callers: []
//------------------------------------------------------------

long wireless_fw_update_time_ms_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00106452,*(undefined4 *)(param_1 + 0x330));
  return (long)iVar1;
}



//------------------------------------------------------------
// wireless_fw_update_time_ms_store @ 00105624 size=68
// signature: undefined wireless_fw_update_time_ms_store(void)
// callers: []
//------------------------------------------------------------

undefined8
wireless_fw_update_time_ms_store
          (long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  
  iVar1 = kstrtouint(param_3,0,param_1 + 0x330);
  if (iVar1 != 0) {
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// wireless_type_show @ 0010566c size=224
// signature: undefined wireless_type_show(void)
// callers: []
//------------------------------------------------------------

long wireless_type_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (wls_fw_udating == '\x01') {
    iVar3 = -0x6e;
  }
  else {
    local_38 = *(undefined4 *)(param_1 + 0x224);
    local_2c = 0;
    local_34 = 0x900000000;
    local_40 = 0x10000800a;
    iVar3 = battery_chg_write(param_1 + -8,&local_40,0x18);
    if (-1 < iVar3) {
      uVar1 = *(uint *)(*(long *)(param_1 + 0x218) + 0x24);
      if (uVar1 < 4) {
        pcVar4 = (&qc_power_supply_wls_type_text)[uVar1];
      }
      else {
        pcVar4 = "Unknown";
      }
      iVar3 = scnprintf(param_3,0x1000,&DAT_00106f48,pcVar4);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar3;
}



//------------------------------------------------------------
// battery_chg_get_max_charge_cntl_limit @ 00105750 size=20
// signature: undefined battery_chg_get_max_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_chg_get_max_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x280);
  return 0;
}



//------------------------------------------------------------
// battery_chg_get_cur_charge_cntl_limit @ 00105768 size=20
// signature: undefined battery_chg_get_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_chg_get_cur_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x27c);
  return 0;
}



//------------------------------------------------------------
// battery_chg_set_cur_charge_cntl_limit @ 00105780 size=32
// signature: undefined battery_chg_set_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

void battery_chg_set_cur_charge_cntl_limit(long param_1)

{
  battery_psy_set_charge_current(*(undefined8 *)(param_1 + 0x3b0));
  return;
}



//------------------------------------------------------------
// init_module @ 00105804 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&battery_chg_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00105834 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&battery_chg_driver);
  return;
}



//------------------------------------------------------------
// raw_notifier_chain_register @ 0010a000 size=1
// signature: undefined raw_notifier_chain_register(void)
// callers: [register_hboost_event_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_chain_unregister @ 0010a008 size=1
// signature: undefined raw_notifier_chain_unregister(void)
// callers: [unregister_hboost_event_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010a010 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [usb_psy_set_icl, usb_psy_set_prop, battery_chg_callback, usb_psy_get_prop, qti_battery_charger_get_prop, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 0010a018 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [qti_battery_charger_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_drvdata @ 0010a020 size=1
// signature: undefined power_supply_get_drvdata(void)
// callers: [wls_psy_get_prop, battery_psy_get_prop, usb_psy_set_prop, usb_psy_get_prop, qti_battery_charger_get_prop, battery_psy_set_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 0010a028 size=1
// signature: undefined power_supply_put(void)
// callers: [qti_battery_charger_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [soh_show, wireless_fw_update_store, moisture_detection_usb_2_en_store, wireless_type_show, battery_chg_ship_mode, battery_chg_callback, usb_psy_get_prop, wireless_boost_en_store, wireless_fw_check_for_update, wireless_boost_en_show, battery_psy_get_prop, resistance_show, wireless_fw_crc_store, fake_soc_store, fake_batt_temp_store, usb_2_real_type_show, battery_psy_set_charge_current, restrict_chg_store, restrict_cur_store, wls_psy_get_prop, moisture_detection_en_store, charge_control_en_show, moisture_detection_usb_2_status_show, panel_event_notifier_callback, wireless_fw_update, usb_typec_compliant_show, charge_control_en_store, qti_battery_charger_get_prop, battery_chg_update_usb_type_work, usb_num_ports_show, wireless_fw_force_update_store, battery_psy_set_prop, moisture_detection_status_show, usb_psy_set_icl, wireless_fw_send_firmware, battery_chg_subsys_up_work, wireless_fw_version_show, usb_2_typec_compliant_show, moisture_detection_usb_2_en_show, moisture_detection_en_show, battery_chg_check_status_work, usb_real_type_show, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a038 size=1
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
// platform_driver_unregister @ 0010a040 size=1
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
// down_read @ 0010a048 size=1
// signature: undefined down_read(void)
// callers: [battery_chg_callback, battery_chg_write, battery_chg_fw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 0010a050 size=1
// signature: undefined up_read(void)
// callers: [battery_chg_callback, battery_chg_write, battery_chg_fw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a058 size=1
// signature: undefined mutex_lock(void)
// callers: [battery_chg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 0010a060 size=1
// signature: undefined pmic_glink_write(void)
// callers: [battery_chg_write, battery_chg_fw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010a068 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [wireless_fw_update, battery_chg_write, battery_chg_fw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a070 size=1
// signature: undefined mutex_unlock(void)
// callers: [battery_chg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a078 size=1
// signature: undefined _printk(void)
// callers: [wls_psy_get_prop, charge_control_en_show, usb_psy_set_prop, panel_event_notifier_callback, wireless_fw_update, charge_control_en_store, battery_chg_ship_mode, battery_chg_callback, battery_chg_write, usb_psy_get_prop, battery_chg_update_usb_type_work, battery_psy_set_prop, usb_psy_set_icl, battery_chg_subsys_up_work, battery_psy_get_prop, wireless_fw_version_show, battery_chg_state_cb, battery_psy_set_charge_current, battery_chg_check_status_work, restrict_chg_store, battery_chg_probe, restrict_cur_store, battery_chg_fw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010a080 size=1
// signature: undefined devm_kmalloc(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010a088 size=1
// signature: undefined __mutex_init(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 0010a090 size=1
// signature: undefined __init_rwsem(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010a098 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 0010a0a0 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010a0a8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_drm_find_panel @ 0010a0b0 size=1
// signature: undefined of_drm_find_panel(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_drm_find_panel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_register @ 0010a0b8 size=1
// signature: undefined panel_event_notifier_register(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 0010a0c0 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_unregister @ 0010a0c8 size=1
// signature: undefined panel_event_notifier_unregister(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 0010a0d0 size=1
// signature: undefined down_write(void)
// callers: [battery_chg_state_cb, battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0010a0d8 size=1
// signature: undefined up_write(void)
// callers: [battery_chg_state_cb, battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_reboot_notifier @ 0010a0e0 size=1
// signature: undefined register_reboot_notifier(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010a0e8 size=1
// signature: undefined of_find_property(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010a0f0 size=1
// signature: undefined of_property_read_string(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a0f8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 0010a100 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [wireless_fw_update, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0010a108 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a110 size=1
// signature: undefined _dev_err(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010a118 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0010a120 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_power_supply_register @ 0010a128 size=1
// signature: undefined devm_power_supply_register(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_power_supply_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 0010a130 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0010a138 size=1
// signature: undefined cancel_work_sync(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a140 size=1
// signature: undefined complete(void)
// callers: [battery_chg_callback, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_reboot_notifier @ 0010a148 size=1
// signature: undefined unregister_reboot_notifier(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_reboot_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_power_supply_get_by_phandle @ 0010a150 size=1
// signature: undefined devm_power_supply_get_by_phandle(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_power_supply_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 0010a158 size=1
// signature: undefined __class_register(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 0010a160 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010a168 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 0010a170 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 0010a178 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 0010a180 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010a190 size=1
// signature: undefined queue_work_on(void)
// callers: [battery_chg_state_cb, battery_chg_callback, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 0010a198 size=1
// signature: undefined class_unregister(void)
// callers: [battery_chg_remove, battery_chg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 0010a1a0 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [battery_chg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0010a1a8 size=1
// signature: undefined debugfs_remove(void)
// callers: [battery_chg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010a1b0 size=1
// signature: undefined msleep(void)
// callers: [battery_chg_subsys_up_work, wireless_fw_update, battery_chg_check_status_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_power_off @ 0010a1b8 size=1
// signature: undefined kernel_power_off(void)
// callers: [battery_chg_check_status_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_power_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_call_chain @ 0010a1c0 size=1
// signature: undefined raw_notifier_call_chain(void)
// callers: [battery_chg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010a1c8 size=1
// signature: undefined ___ratelimit(void)
// callers: [battery_chg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_changed @ 0010a1d0 size=1
// signature: undefined power_supply_changed(void)
// callers: [battery_chg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_changed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 0010a1d8 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [battery_chg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 0010a1e0 size=1
// signature: undefined power_supply_get_property(void)
// callers: [battery_psy_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_set_property @ 0010a1e8 size=1
// signature: undefined power_supply_set_property(void)
// callers: [battery_psy_set_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_set_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a1f0 size=1
// signature: undefined scnprintf(void)
// callers: [soh_show, charge_control_en_show, moisture_detection_usb_2_status_show, wireless_type_show, usb_typec_compliant_show, ship_mode_en_show, usb_num_ports_show, moisture_detection_status_show, wireless_boost_en_show, resistance_show, wireless_fw_version_show, restrict_cur_show, usb_2_typec_compliant_show, moisture_detection_usb_2_en_show, wireless_fw_update_time_ms_show, moisture_detection_en_show, usb_2_real_type_show, restrict_chg_show, usb_real_type_show, fake_soc_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0010a1f8 size=1
// signature: undefined kstrtobool(void)
// callers: [wireless_fw_update_store, moisture_detection_en_store, ship_mode_en_store, moisture_detection_usb_2_en_store, charge_control_en_store, wireless_boost_en_store, wireless_fw_force_update_store, restrict_chg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0010a200 size=1
// signature: undefined kstrtoint(void)
// callers: [fake_soc_store, fake_batt_temp_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 0010a208 size=1
// signature: undefined kstrtouint(void)
// callers: [wireless_fw_update_time_ms_store, restrict_cur_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 0010a210 size=1
// signature: undefined pm_stay_awake(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// firmware_request_nowarn @ 0010a218 size=1
// signature: undefined firmware_request_nowarn(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void firmware_request_nowarn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0010a220 size=1
// signature: undefined release_firmware(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 0010a228 size=1
// signature: undefined pm_relax(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0010a230 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [wireless_fw_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a238 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [wireless_fw_send_firmware]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 0010a240 size=1
// signature: undefined kstrtou16(void)
// callers: [wireless_fw_crc_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



