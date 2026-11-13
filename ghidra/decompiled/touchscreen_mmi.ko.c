// Decompiled by Ghidra 12.2
// Program: touchscreen_mmi.ko
// Image base: 00100000

//------------------------------------------------------------
// ts_mmi_dev_register @ 00101254 size=1416
// signature: undefined ts_mmi_dev_register(void)
// callers: []
//------------------------------------------------------------

ulong ts_mmi_dev_register(long param_1,long param_2)

{
  undefined *puVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  code *pcVar6;
  long *plVar7;
  ulong uVar8;
  char *pcVar9;
  
  uVar8 = 0xffffffed;
  if ((param_1 == 0) || (touchscreens_class == 0)) goto LAB_0010129c;
  plVar3 = (long *)devm_kmalloc(param_1,0x3d8,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar8 = 0xfffffff4;
    goto LAB_0010129c;
  }
  _dev_info(param_1,"%s: new device\n","ts_mmi_dev_register");
  *plVar3 = param_1;
  plVar3[0x7a] = param_2;
  __mutex_init(plVar3 + 0xf,"&touch_cdev->extif_mutex",&ts_mmi_dev_register___key);
  __mutex_init(plVar3 + 0x15,"&touch_cdev->method_mutex",&ts_mmi_dev_register___key_3);
  uVar4 = ts_mmi_parse_dt(plVar3,*(undefined8 *)(*plVar3 + 0x2e8));
  uVar8 = uVar4 & 0xffffffff;
  if ((int)uVar4 < 0) {
    _dev_err(*plVar3,"%s: init panel failed. %d\n","ts_mmi_dev_register",uVar4 & 0xffffffff);
  }
  else {
    uVar8 = devm_pinctrl_get(*plVar3);
    plVar3[0x1b] = uVar8;
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
      _dev_info(*plVar3,"%s: No pinctrl defined\n","ts_mmi_dev_register");
    }
    else if (*(long *)(plVar3[0x7a] + 0xc0) == 0) {
      lVar5 = pinctrl_lookup_state(uVar8,"ts_mmi_on_state");
      plVar3[0x1c] = lVar5;
      uVar8 = pinctrl_lookup_state(plVar3[0x1b],"ts_mmi_off_state");
      plVar3[0x1d] = uVar8;
      if (((plVar3[0x1c] != 0) && ((ulong)plVar3[0x1c] < 0xfffffffffffff001)) ||
         ((uVar8 != 0 && (uVar8 < 0xfffffffffffff001)))) {
        _dev_info(*plVar3,"%s: No pinctrl method add default\n","ts_mmi_dev_register");
        *(code **)(plVar3[0x7a] + 0xc0) = ts_mmi_default_pinctrl;
        if ((plVar3[0x1c] != 0) && ((ulong)plVar3[0x1c] < 0xfffffffffffff001)) {
          pinctrl_select_state(plVar3[0x1b]);
        }
      }
    }
    ts_mmi_get_vendor_info(plVar3);
    uVar2 = alloc_chrdev_region(plVar3 + 2,0,1,"primary");
    if ((int)uVar2 < 0) {
      uVar8 = (ulong)uVar2;
      _dev_info(*plVar3,"%s: get device number failed. %d\n","ts_mmi_dev_register",uVar8);
    }
    else {
      pcVar9 = (char *)plVar3[10];
      if ((long *)pcVar9 == (long *)0x0) {
        pcVar6 = *(code **)(plVar3[0x7a] + 0x28);
        if (pcVar6 == (code *)0x0) {
          pcVar9 = "primary";
        }
        else {
          pcVar9 = (char *)(plVar3 + 100);
          if (*(int *)(pcVar6 + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101490);
            (*pcVar6)();
          }
          (*pcVar6)(*plVar3,pcVar9);
        }
      }
      _dev_info(*plVar3,"class entry name %s\n",pcVar9);
      uVar8 = device_create(touchscreens_class,0,(int)plVar3[2],plVar3,&DAT_0010922d,pcVar9);
      plVar3[1] = uVar8;
      if (uVar8 < 0xfffffffffffff001) {
        *(code **)(plVar3[0x7a] + 0x1b0) = get_class_fname_handler;
        *(code **)(plVar3[0x7a] + 0x1b8) = get_supplier_handler;
        *(code **)(plVar3[0x7a] + 0x1a0) = get_gesture_type_handler;
        *(code **)(plVar3[0x7a] + 0x1d0) = report_liquid_detection_status_handler;
        *(long *)(plVar3[0x7a] + 0x1d8) = plVar3[1];
        down_write(&touchscreens_list_lock);
        puVar1 = PTR_touchscreens_list_001086b0;
        plVar7 = plVar3 + 0x75;
        uVar8 = __list_add_valid(plVar7,PTR_touchscreens_list_001086b0,&touchscreens_list);
        if ((uVar8 & 1) != 0) {
          PTR_touchscreens_list_001086b0 = (undefined *)plVar7;
          plVar3[0x75] = (long)&touchscreens_list;
          plVar3[0x76] = (long)puVar1;
          *(long **)puVar1 = plVar7;
        }
        up_write(&touchscreens_list_lock);
        uVar4 = sysfs_create_group(plVar3[1],sysfs_class_group);
        uVar8 = uVar4 & 0xffffffff;
        if ((int)uVar4 == 0) {
          pcVar6 = *(code **)(plVar3[0x7a] + 0x158);
          if (pcVar6 == (code *)0x0) {
LAB_00101660:
            uVar2 = ts_mmi_sysfs_create_edge_entries(plVar3,1);
            if ((int)uVar2 < 0) {
              uVar8 = (ulong)uVar2;
              _dev_err(*plVar3,"%s: Create edge sys entries failed. %d\n","ts_mmi_dev_register",
                       uVar8);
            }
            else {
              uVar2 = ts_mmi_panel_register(plVar3);
              if ((int)uVar2 < 0) {
                uVar8 = (ulong)uVar2;
                _dev_err(*plVar3,"%s: Register panel failed. %d\n","ts_mmi_dev_register",uVar8);
              }
              else {
                uVar2 = ts_mmi_notifiers_register(plVar3);
                if ((int)uVar2 < 0) {
                  uVar8 = (ulong)uVar2;
                  _dev_err(*plVar3,"%s: Register notifiers failed. %d\n","ts_mmi_dev_register",uVar8
                          );
                }
                else {
                  if ((*(char *)((long)plVar3 + 0x25) == '\0') ||
                     (uVar2 = ts_mmi_gesture_init(plVar3), -1 < (int)uVar2)) {
                    if ((*(char *)((long)plVar3 + 0x26) == '\0') ||
                       (uVar2 = ts_mmi_cli_gesture_init(plVar3), -1 < (int)uVar2)) {
                      if ((*(char *)((long)plVar3 + 0x27) == '\0') ||
                         (uVar2 = ts_mmi_palm_init(plVar3), -1 < (int)uVar2)) {
                        if (*(char *)((long)plVar3 + 0x31) != '\0') {
                          *(code **)(plVar3[0x7a] + 0x1c8) = ts_mmi_clip_event_handler;
                        }
                        _dev_info(*plVar3,"Registered touchscreen device: %s.\n",pcVar9);
                        uVar8 = 0;
                        goto LAB_0010129c;
                      }
                      uVar8 = (ulong)uVar2;
                      lVar5 = *plVar3;
                      pcVar9 = "%s: Register plam failed. %d\n";
                    }
                    else {
                      uVar8 = (ulong)uVar2;
                      lVar5 = *plVar3;
                      pcVar9 = "%s: Register CLI gesture failed. %d\n";
                    }
                  }
                  else {
                    uVar8 = (ulong)uVar2;
                    lVar5 = *plVar3;
                    pcVar9 = "%s: Register gesture failed. %d\n";
                  }
                  _dev_err(lVar5,pcVar9,"ts_mmi_dev_register",uVar8);
                  ts_mmi_notifiers_unregister(plVar3);
                }
                ts_mmi_panel_unregister(plVar3);
              }
              ts_mmi_sysfs_create_edge_entries(plVar3,0);
            }
            if (plVar3[0x74] != 0) {
              sysfs_remove_group(plVar3[1]);
            }
          }
          else {
            if (*(int *)(pcVar6 + -4) != -0x572e0ab4) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1015b8);
              (*pcVar6)();
            }
            (*pcVar6)(*plVar3,plVar3 + 0x74);
            if (plVar3[0x74] == 0) goto LAB_00101660;
            uVar4 = sysfs_create_group(plVar3[1]);
            uVar8 = uVar4 & 0xffffffff;
            if ((int)uVar4 == 0) goto LAB_00101660;
          }
          sysfs_remove_group(plVar3[1],sysfs_class_group);
        }
        down_write(&touchscreens_list_lock);
        uVar4 = __list_del_entry_valid(plVar7);
        if ((uVar4 & 1) != 0) {
          plVar7 = (long *)plVar3[0x76];
          lVar5 = plVar3[0x75];
          *(long **)(lVar5 + 8) = plVar7;
          *plVar7 = lVar5;
        }
        plVar3[0x75] = -0x2152ffffffffff00;
        plVar3[0x76] = -0x2152fffffffffede;
        up_write(&touchscreens_list_lock);
        device_unregister(plVar3[1]);
      }
      plVar3[1] = 0;
      unregister_chrdev_region((int)plVar3[2],1);
    }
    ts_mmi_panel_unregister(plVar3);
  }
  devm_kfree(param_1,plVar3);
LAB_0010129c:
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// ts_mmi_default_pinctrl @ 001017e0 size=224
// signature: undefined ts_mmi_default_pinctrl(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_default_pinctrl(undefined *param_1,int param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  down_write(&touchscreens_list_lock);
  ppuVar4 = &touchscreens_list;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    ppuVar3 = ppuVar4 + -0x75;
    if (ppuVar4 == &touchscreens_list) break;
  } while (*ppuVar3 != param_1);
  up_write(&touchscreens_list_lock);
  if (ppuVar3 == (undefined **)0x0) {
    uVar2 = 0xffffffed;
  }
  else {
    pcVar1 = "SUSPEND";
    if (param_2 != 0) {
      pcVar1 = "ACTIVE";
    }
    _dev_info(*ppuVar3,"%s: %s\n","ts_mmi_default_pinctrl",pcVar1);
    if (param_2 == 0) {
      ppuVar3 = ppuVar4 + -0x58;
    }
    else {
      ppuVar3 = ppuVar4 + -0x59;
    }
    uVar2 = 0;
    if ((*ppuVar3 != (undefined *)0x0) && (*ppuVar3 < (undefined *)0xfffffffffffff001)) {
      pinctrl_select_state(ppuVar4[-0x5a]);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// ts_mmi_get_vendor_info @ 001018c0 size=264
// signature: undefined ts_mmi_get_vendor_info(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

void ts_mmi_get_vendor_info(undefined8 *param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = param_1[0x7a];
  if (*(long *)(lVar2 + 0x10) != 0) {
    mutex_lock(param_1 + 0x15);
    if (*(int *)(*(code **)(param_1[0x7a] + 0x10) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101914);
      (*pcVar1)();
    }
    (**(code **)(param_1[0x7a] + 0x10))(*param_1,param_1 + 0x5e);
    mutex_unlock(param_1 + 0x15);
    lVar2 = param_1[0x7a];
  }
  if (*(long *)(lVar2 + 8) != 0) {
    mutex_lock(param_1 + 0x15);
    if (*(int *)(*(code **)(param_1[0x7a] + 8) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101960);
      (*pcVar1)();
    }
    (**(code **)(param_1[0x7a] + 8))(*param_1,param_1 + 0x5c);
    mutex_unlock(param_1 + 0x15);
    lVar2 = param_1[0x7a];
  }
  if (*(long *)(lVar2 + 0x30) != 0) {
    mutex_lock(param_1 + 0x15);
    if (*(int *)(*(code **)(param_1[0x7a] + 0x30) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1019ac);
      (*pcVar1)();
    }
    (**(code **)(param_1[0x7a] + 0x30))(*param_1,param_1 + 0x68);
    mutex_unlock(param_1 + 0x15);
  }
  return;
}



//------------------------------------------------------------
// get_class_fname_handler @ 001019cc size=152
// signature: undefined get_class_fname_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 get_class_fname_handler(undefined *param_1,long *param_2)

{
  undefined8 uVar1;
  long lVar2;
  undefined **ppuVar3;
  
  down_write(&touchscreens_list_lock);
  ppuVar3 = &touchscreens_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &touchscreens_list) break;
  } while (ppuVar3[-0x75] != param_1);
  up_write(&touchscreens_list_lock);
  if (ppuVar3 + -0x75 == (undefined **)0x0) {
    uVar1 = 0xffffffed;
  }
  else {
    lVar2 = *(long *)((long)ppuVar3[-0x74] + 0x70);
    if (lVar2 == 0) {
      lVar2 = *(long *)ppuVar3[-0x74];
    }
    uVar1 = 0;
    *param_2 = lVar2;
  }
  return uVar1;
}



//------------------------------------------------------------
// get_supplier_handler @ 00101a68 size=136
// signature: undefined get_supplier_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 get_supplier_handler(undefined *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  
  down_write(&touchscreens_list_lock);
  ppuVar2 = &touchscreens_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &touchscreens_list) break;
  } while (ppuVar2[-0x75] != param_1);
  up_write(&touchscreens_list_lock);
  if (ppuVar2 + -0x75 == (undefined **)0x0) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = 0;
    *param_2 = ppuVar2 + -0xf;
  }
  return uVar1;
}



//------------------------------------------------------------
// get_gesture_type_handler @ 00101af4 size=140
// signature: undefined get_gesture_type_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 get_gesture_type_handler(undefined *param_1,undefined1 *param_2)

{
  undefined8 uVar1;
  undefined **ppuVar2;
  
  down_write(&touchscreens_list_lock);
  ppuVar2 = &touchscreens_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &touchscreens_list) break;
  } while (ppuVar2[-0x75] != param_1);
  up_write(&touchscreens_list_lock);
  if (ppuVar2 + -0x75 == (undefined **)0x0) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = 0;
    *param_2 = *(undefined1 *)(ppuVar2 + -0x72);
  }
  return uVar1;
}



//------------------------------------------------------------
// report_liquid_detection_status_handler @ 00101b84 size=264
// signature: undefined report_liquid_detection_status_handler(void)
// callers: []
//------------------------------------------------------------

void report_liquid_detection_status_handler(undefined *param_1,undefined4 param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = param_2;
  down_write(&touchscreens_list_lock);
  ppuVar3 = &touchscreens_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    ppuVar4 = ppuVar3 + -0x75;
    if (ppuVar3 == &touchscreens_list) break;
  } while (*ppuVar4 != param_1);
  up_write(&touchscreens_list_lock);
  if (ppuVar4 == (undefined **)0x0) {
    uVar2 = 0xffffffed;
  }
  else {
    _dev_info(*ppuVar4,"%s: notify liquid detection status: %d\n",
              "report_liquid_detection_status_handler",param_2);
    *(undefined4 *)((long)ppuVar3 + -0xcc) = param_2;
    if (*(char *)(ppuVar3 + -0x1a) == '\0') {
      _dev_err(*ppuVar4,"%s: lpd_notifier does not register\n",
               "report_liquid_detection_status_handler");
    }
    else {
      relay_notifier_fire(1,3,2,&local_3c);
    }
    uVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_sysfs_create_edge_entries @ 00101c8c size=1316
// signature: undefined ts_mmi_sysfs_create_edge_entries(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

int ts_mmi_sysfs_create_edge_entries(undefined8 *param_1,ulong param_2)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if ((param_2 & 1) == 0) {
    if (*(char *)((long)param_1 + 0x2d) != '\0') {
      sysfs_remove_file_ns(param_1[1],&dev_attr_hold_grip,0);
    }
    iVar3 = 0;
    cVar1 = *(char *)((long)param_1 + 0x2c);
joined_r0x00101f8c:
    if (cVar1 != '\0') {
      sysfs_remove_file_ns(param_1[1],&dev_attr_gs_distance,0);
    }
LAB_00101fa4:
    if (*(char *)((long)param_1 + 0x2b) != '\0') {
      sysfs_remove_file_ns(param_1[1],&dev_attr_hold_distance,0);
    }
    cVar1 = *(char *)((long)param_1 + 0x2a);
  }
  else {
    if (*(char *)((long)param_1 + 0x2f) != '\0') {
      if (*(long *)(param_1[0x7a] + 0xa0) != 0) {
        mutex_lock(param_1 + 0x15);
        if (*(int *)(*(code **)(param_1[0x7a] + 0xa0) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101cf0);
          (*pcVar2)();
        }
        iVar3 = (**(code **)(param_1[0x7a] + 0xa0))(*param_1,(long)param_1 + 0x364);
        mutex_unlock(param_1 + 0x15);
        if (iVar3 < 0) {
          _dev_err(*param_1,"%s: failed to read active_region info (%d)\n",
                   "ts_mmi_sysfs_create_edge_entries",iVar3);
        }
      }
      iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_active_region,0);
      if (iVar3 < 0) {
        uVar4 = *param_1;
        pcVar5 = "%s: failed to create active_region entry (%d)\n";
        goto LAB_00102034;
      }
    }
    if (*(char *)((long)param_1 + 0x29) != '\0') {
      if (*(long *)(param_1[0x7a] + 0x58) != 0) {
        mutex_lock(param_1 + 0x15);
        if (*(int *)(*(code **)(param_1[0x7a] + 0x58) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101d64);
          (*pcVar2)();
        }
        iVar3 = (**(code **)(param_1[0x7a] + 0x58))(*param_1,(long)param_1 + 0x354);
        mutex_unlock(param_1 + 0x15);
        if (iVar3 < 0) {
          _dev_err(*param_1,"%s: failed to read suppression info (%d)\n",
                   "ts_mmi_sysfs_create_edge_entries",iVar3);
        }
      }
      iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_suppression,0);
      if (iVar3 < 0) {
        uVar4 = *param_1;
        pcVar5 = "%s: failed to create suppression entry (%d)\n";
LAB_00102034:
        _dev_err(uVar4,pcVar5,"ts_mmi_sysfs_create_edge_entries",iVar3);
        return iVar3;
      }
    }
    if (*(char *)((long)param_1 + 0x2a) != '\0') {
      if (*(long *)(param_1[0x7a] + 0x70) != 0) {
        mutex_lock(param_1 + 0x15);
        if (*(int *)(*(code **)(param_1[0x7a] + 0x70) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101dd8);
          (*pcVar2)();
        }
        iVar3 = (**(code **)(param_1[0x7a] + 0x70))(*param_1,param_1 + 0x6b);
        mutex_unlock(param_1 + 0x15);
        if (iVar3 < 0) {
          _dev_err(*param_1,"%s: failed to read pill_region info (%d)\n",
                   "ts_mmi_sysfs_create_edge_entries",iVar3);
        }
      }
      iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_pill_region,0);
      if (iVar3 < 0) {
        _dev_err(*param_1,"%s: failed to create pill_region entry (%d)\n",
                 "ts_mmi_sysfs_create_edge_entries",iVar3);
        goto LAB_00101fdc;
      }
    }
    if (*(char *)((long)param_1 + 0x2b) == '\0') {
LAB_00101e78:
      if (*(char *)((long)param_1 + 0x2c) == '\0') {
LAB_00101eec:
        if (*(char *)((long)param_1 + 0x2d) == '\0') {
          return 0;
        }
        if (*(long *)(param_1[0x7a] + 0x60) != 0) {
          mutex_lock(param_1 + 0x15);
          if (*(int *)(*(code **)(param_1[0x7a] + 0x60) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101f34);
            (*pcVar2)();
          }
          iVar3 = (**(code **)(param_1[0x7a] + 0x60))(*param_1,(long)param_1 + 0x37c);
          mutex_unlock(param_1 + 0x15);
          if (iVar3 < 0) {
            _dev_err(*param_1,"%s: failed to read hold_grip info (%d)\n",
                     "ts_mmi_sysfs_create_edge_entries",iVar3);
          }
        }
        iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_hold_grip,0);
        if (-1 < iVar3) {
          return 0;
        }
        _dev_err(*param_1,"%s: failed to create hold_grip entry (%d)\n",
                 "ts_mmi_sysfs_create_edge_entries",iVar3);
        cVar1 = *(char *)((long)param_1 + 0x2c);
        goto joined_r0x00101f8c;
      }
      if (*(long *)(param_1[0x7a] + 0x80) != 0) {
        mutex_lock(param_1 + 0x15);
        if (*(int *)(*(code **)(param_1[0x7a] + 0x80) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101ec0);
          (*pcVar2)();
        }
        iVar3 = (**(code **)(param_1[0x7a] + 0x80))(*param_1,param_1 + 0x6f);
        mutex_unlock(param_1 + 0x15);
        if (iVar3 < 0) {
          _dev_err(*param_1,"%s: failed to read gs_distance info (%d)\n",
                   "ts_mmi_sysfs_create_edge_entries",iVar3);
          *(undefined4 *)(param_1 + 0x6f) = 0x1e;
        }
      }
      iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_gs_distance,0);
      if (-1 < iVar3) goto LAB_00101eec;
      _dev_err(*param_1,"%s: failed to create gs_distance entry (%d)\n",
               "ts_mmi_sysfs_create_edge_entries",iVar3);
      goto LAB_00101fa4;
    }
    if (*(long *)(param_1[0x7a] + 0x78) != 0) {
      mutex_lock(param_1 + 0x15);
      if (*(int *)(*(code **)(param_1[0x7a] + 0x78) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101e4c);
        (*pcVar2)();
      }
      iVar3 = (**(code **)(param_1[0x7a] + 0x78))(*param_1,(long)param_1 + 0x374);
      mutex_unlock(param_1 + 0x15);
      if (iVar3 < 0) {
        _dev_err(*param_1,"%s: failed to read hold_distance info (%d)\n",
                 "ts_mmi_sysfs_create_edge_entries",iVar3);
      }
    }
    iVar3 = sysfs_create_file_ns(param_1[1],&dev_attr_hold_distance,0);
    if (-1 < iVar3) goto LAB_00101e78;
    _dev_err(*param_1,"%s: failed to create hold_distance entry (%d)\n",
             "ts_mmi_sysfs_create_edge_entries",iVar3);
    cVar1 = *(char *)((long)param_1 + 0x2a);
  }
  if (cVar1 != '\0') {
    sysfs_remove_file_ns(param_1[1],&dev_attr_pill_region,0);
  }
LAB_00101fdc:
  if (*(char *)((long)param_1 + 0x29) != '\0') {
    sysfs_remove_file_ns(param_1[1],&dev_attr_suppression,0);
  }
  return iVar3;
}



//------------------------------------------------------------
// ts_mmi_clip_event_handler @ 001021b4 size=260
// signature: undefined ts_mmi_clip_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_clip_event_handler(undefined *param_1,undefined1 *param_2,undefined8 param_3)

{
  bool bVar1;
  undefined **ppuVar2;
  
  down_write(&touchscreens_list_lock);
  ppuVar2 = &touchscreens_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &touchscreens_list) break;
  } while (ppuVar2[-0x75] != param_1);
  up_write(&touchscreens_list_lock);
  if (((*(uint *)(param_2 + 0xc) < *(uint *)(ppuVar2 + 2)) ||
      (*(uint *)(ppuVar2 + 3) < *(uint *)(param_2 + 0xc))) ||
     (*(uint *)(param_2 + 0x10) < *(uint *)((long)ppuVar2 + 0x14))) {
    bVar1 = false;
  }
  else {
    bVar1 = *(uint *)(param_2 + 0x10) <= *(uint *)((long)ppuVar2 + 0x1c);
  }
  if (bVar1 == (bool)*(char *)(ppuVar2 + 4)) {
    if (*(int *)(param_2 + 4) == 3) {
      input_event(param_3,3,0x2f,*(undefined4 *)(param_2 + 8));
      input_mt_report_slot_state(param_3,0,0);
      *(undefined4 *)(param_2 + 4) = 4;
    }
    *param_2 = 1;
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_dev_unregister @ 001022bc size=408
// signature: undefined ts_mmi_dev_unregister(void)
// callers: []
//------------------------------------------------------------

void ts_mmi_dev_unregister(undefined *param_1)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  if (touchscreens_class != 0) {
    down_write(&touchscreens_list_lock);
    ppuVar5 = &touchscreens_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      ppuVar4 = ppuVar5 + -0x75;
      if (ppuVar5 == &touchscreens_list) goto LAB_00102354;
    } while (*ppuVar4 != param_1);
    uVar3 = __list_del_entry_valid(ppuVar5);
    if ((uVar3 & 1) != 0) {
      puVar1 = *ppuVar5;
      plVar2 = (long *)ppuVar5[1];
      *(long **)(puVar1 + 8) = plVar2;
      *plVar2 = (long)puVar1;
    }
    *ppuVar5 = (undefined *)0xdead000000000100;
    ppuVar5[1] = (undefined *)0xdead000000000122;
LAB_00102354:
    up_write(&touchscreens_list_lock);
    if (*ppuVar4 == param_1) {
      if (*(char *)((long)ppuVar5 + -899) != '\0') {
        ts_mmi_gesture_remove(ppuVar4);
      }
      if (*(char *)((long)ppuVar5 + -0x382) != '\0') {
        ts_mmi_cli_gesture_remove(ppuVar4);
      }
      if (*(char *)((long)ppuVar5 + -0x381) != '\0') {
        ts_mmi_palm_remove(ppuVar4);
      }
      ts_mmi_notifiers_unregister(ppuVar4);
      ts_mmi_panel_unregister(ppuVar4);
      _dev_info(*ppuVar4,"%s: delete device\n","ts_mmi_dev_unregister");
      *(undefined8 *)(*ppuVar4 + 0x98) = 0;
      ts_mmi_sysfs_create_edge_entries(ppuVar4,0);
      if (ppuVar5[-1] != (undefined *)0x0) {
        sysfs_remove_group(ppuVar5[-0x74]);
      }
      ppuVar6 = ppuVar5 + -0x74;
      sysfs_remove_group(*ppuVar6,sysfs_class_group);
      device_unregister(*ppuVar6);
      *ppuVar6 = (undefined *)0x0;
      unregister_chrdev_region(*(undefined4 *)(ppuVar5 + -0x73),1);
      devm_kfree(param_1,ppuVar4);
    }
    else {
      _dev_err(param_1,"%s: device not registered before.\n","ts_mmi_dev_unregister");
    }
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_is_panel_match @ 00102458 size=196
// signature: undefined ts_mmi_is_panel_match(void)
// callers: []
//------------------------------------------------------------

void ts_mmi_is_panel_match(undefined8 param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  char *local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar3 != 0) || (lVar3 = of_find_node_opts_by_path("/chosen@0",0), bVar1 = false, lVar3 != 0))
  {
    iVar2 = of_property_read_string(lVar3,param_1,&local_30);
    if (iVar2 == 0) {
      pcVar4 = strstr(local_30,param_2);
      bVar1 = pcVar4 != (char *)0x0;
    }
    else {
      _printk(&DAT_00109d29,"ts_mmi_is_panel_match",param_1);
      bVar1 = false;
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// path_show @ 00102520 size=284
// signature: undefined path_show(void)
// callers: []
//------------------------------------------------------------

long path_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  code *pcVar2;
  int iVar3;
  size_t sVar4;
  undefined *puVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long lVar8;
  int iVar9;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _dev_err(param_1,"touchscreen device pointer is NULL\n");
    lVar8 = 0;
  }
  else {
    puVar7 = *(undefined8 **)(*(long *)(param_1 + 0x98) + 8);
    lVar8 = 1;
    puVar6 = puVar7;
    do {
      if ((char *)*puVar6 == (char *)0x0) goto LAB_001025d4;
      sVar4 = strlen((char *)*puVar6);
      puVar6 = (undefined8 *)puVar6[3];
      lVar8 = sVar4 + (long)(int)lVar8 + 1;
    } while (puVar6 != (undefined8 *)0x0);
    iVar3 = (int)lVar8;
    if (iVar3 == 0) {
LAB_001025d4:
      puVar5 = (undefined *)0x0;
    }
    else {
      puVar5 = (undefined *)__kmalloc((long)iVar3,0xdc0);
      if ((puVar5 != (undefined *)0x0) && (puVar7 != (undefined8 *)0x0)) {
        iVar9 = iVar3 + -1;
        do {
          sVar4 = strlen((char *)*puVar7);
          iVar9 = iVar9 - (int)sVar4;
          memcpy(puVar5 + iVar9,(void *)*puVar7,(long)(int)sVar4);
          iVar9 = iVar9 + -1;
          if ((iVar9 < 0) || ((ulong)(long)iVar3 <= (ulong)(long)iVar9)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x10263c);
            (*pcVar2)();
          }
          puVar5[iVar9] = 0x2f;
          puVar7 = (undefined8 *)puVar7[3];
        } while (puVar7 != (undefined8 *)0x0);
      }
    }
    puVar1 = &DAT_0010a2b4;
    if (puVar5 != (undefined *)0x0) {
      puVar1 = puVar5;
    }
    iVar3 = scnprintf(param_3,0x1000,&DAT_0010922d,puVar1);
    lVar8 = (long)iVar3;
    kfree(puVar5);
  }
  return lVar8;
}



//------------------------------------------------------------
// vendor_show @ 00102640 size=268
// signature: undefined vendor_show(void)
// callers: []
//------------------------------------------------------------

long vendor_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","vendor");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 8) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 8) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1026b4);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 8))(*puVar4,puVar4 + 0x5c);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","vendor",iVar2);
      lVar3 = 0;
      goto LAB_001026e4;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010922d,puVar4 + 0x5c);
  lVar3 = (long)iVar2;
LAB_001026e4:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// productinfo_show @ 00102750 size=268
// signature: undefined productinfo_show(void)
// callers: [ts_mmi_ic_ver_show]
//------------------------------------------------------------

long productinfo_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","productinfo");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x10) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x10) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1027c4);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x10))(*puVar4,puVar4 + 0x5e);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","productinfo",iVar2);
      lVar3 = 0;
      goto LAB_001027f4;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010922d,puVar4 + 0x5e);
  lVar3 = (long)iVar2;
LAB_001027f4:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// ts_mmi_buildid_show @ 00102860 size=100
// signature: undefined ts_mmi_buildid_show(void)
// callers: []
//------------------------------------------------------------

long ts_mmi_buildid_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 extraout_x1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  build_id_show();
  config_id_show(param_1,extraout_x1,param_3);
  iVar1 = scnprintf(param_3,0x1000,"%s-%s\n",lVar2 + 0x300,lVar2 + 0x310);
  return (long)iVar1;
}



//------------------------------------------------------------
// build_id_show @ 001028c8 size=268
// signature: undefined build_id_show(void)
// callers: [ts_mmi_buildid_show, ts_mmi_ic_ver_show]
//------------------------------------------------------------

long build_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","build_id");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x18) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x18) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10293c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x18))(*puVar4,puVar4 + 0x60);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","build_id",iVar2);
      lVar3 = 0;
      goto LAB_0010296c;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010922d,puVar4 + 0x60);
  lVar3 = (long)iVar2;
LAB_0010296c:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// config_id_show @ 001029d8 size=268
// signature: undefined config_id_show(void)
// callers: [ts_mmi_buildid_show, ts_mmi_ic_ver_show]
//------------------------------------------------------------

long config_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","config_id");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x20) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x20) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102a4c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x20))(*puVar4,puVar4 + 0x62);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","config_id",iVar2);
      lVar3 = 0;
      goto LAB_00102a7c;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010922d,puVar4 + 0x62);
  lVar3 = (long)iVar2;
LAB_00102a7c:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// poweron_show @ 00102ae8 size=268
// signature: undefined poweron_show(void)
// callers: []
//------------------------------------------------------------

long poweron_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","poweron");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x48) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x48) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102b5c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x48))(*puVar4,(long)puVar4 + 0x34c);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","poweron",iVar2);
      lVar3 = 0;
      goto LAB_00102b8c;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010a507,*(undefined4 *)((long)puVar4 + 0x34c));
  lVar3 = (long)iVar2;
LAB_00102b8c:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// flashprog_show @ 00102bf8 size=268
// signature: undefined flashprog_show(void)
// callers: []
//------------------------------------------------------------

long flashprog_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","flashprog");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x50) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x50) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c6c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x50))(*puVar4,puVar4 + 0x6a);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","flashprog",iVar2);
      lVar3 = 0;
      goto LAB_00102c9c;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010a507,*(undefined4 *)(puVar4 + 0x6a));
  lVar3 = (long)iVar2;
LAB_00102c9c:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// irq_status_show @ 00102d08 size=268
// signature: undefined irq_status_show(void)
// callers: [ts_mmi_hw_irqstat_show]
//------------------------------------------------------------

long irq_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","irq_status");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if (*(long *)(puVar4[0x7a] + 0x38) != 0) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x38) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102d7c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x38))(*puVar4,(long)puVar4 + 0x344);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","irq_status",iVar2);
      lVar3 = 0;
      goto LAB_00102dac;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010a507,*(undefined4 *)((long)puVar4 + 0x344));
  lVar3 = (long)iVar2;
LAB_00102dac:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// ts_mmi_hw_irqstat_show @ 00102e18 size=132
// signature: undefined ts_mmi_hw_irqstat_show(void)
// callers: []
//------------------------------------------------------------

long ts_mmi_hw_irqstat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  char *pcVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  irq_status_show();
  iVar1 = *(int *)((long)puVar3 + 0x344);
  if (iVar1 == 0) {
    pcVar2 = "Low\n";
  }
  else if (iVar1 == 1) {
    pcVar2 = "High\n";
  }
  else {
    _dev_err(*puVar3,"%s: Failed to get irq state\n","ts_mmi_hw_irqstat_show");
    pcVar2 = "Unknown\n";
  }
  iVar1 = scnprintf(param_3,0x1000,pcVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// ts_mmi_ic_ver_show @ 00102ea0 size=152
// signature: undefined ts_mmi_ic_ver_show(void)
// callers: []
//------------------------------------------------------------

long ts_mmi_ic_ver_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 extraout_x1;
  undefined8 extraout_x1_00;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  productinfo_show();
  build_id_show(param_1,extraout_x1,param_3);
  config_id_show(param_1,extraout_x1_00,param_3);
  iVar1 = scnprintf(param_3,0x1000,"%s%s\n%s%s\n%s%s\n","Product ID: ",lVar2 + 0x2f0,"Build ID: ",
                    lVar2 + 0x300,"Config ID: ",lVar2 + 0x310);
  return (long)iVar1;
}



//------------------------------------------------------------
// drv_irq_show @ 00102f3c size=280
// signature: undefined drv_irq_show(void)
// callers: []
//------------------------------------------------------------

long drv_irq_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","drv_irq");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x40) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x40) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102fbc);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x40))(*puVar4,puVar4 + 0x69);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","drv_irq",iVar2);
      lVar3 = 0;
      goto LAB_00102fec;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,&DAT_0010a507,*(undefined4 *)(puVar4 + 0x69));
  lVar3 = (long)iVar2;
LAB_00102fec:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// drv_irq_store @ 00103058 size=324
// signature: undefined drv_irq_store(void)
// callers: []
//------------------------------------------------------------

undefined8 drv_irq_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)(puVar5 + 0x69) = (undefined4)local_50;
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0xb0), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103100);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","drv_irq",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00103118;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"drv_irq");
  param_4 = 0xffffffffffffffea;
LAB_00103118:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// reset_store @ 001031a0 size=312
// signature: undefined reset_store(void)
// callers: []
//------------------------------------------------------------

undefined8 reset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)((long)puVar5 + 0x394) = (undefined4)local_50;
      pcVar4 = *(code **)(puVar5[0x7a] + 0xa8);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10323c);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","reset",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00103254;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"reset");
  param_4 = 0xffffffffffffffea;
LAB_00103254:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ts_mmi_forcereflash_store @ 001032dc size=160
// signature: undefined ts_mmi_forcereflash_store(void)
// callers: []
//------------------------------------------------------------

undefined8
ts_mmi_forcereflash_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 < 0) {
    _dev_err(param_1,"forcereflash: Failed to convert value\n");
    param_4 = 0xffffffffffffffea;
  }
  else {
    *(int *)(lVar2 + 0x14) = (int)local_40;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ts_mmi_doreflash_store @ 00103380 size=764
// signature: undefined ts_mmi_doreflash_store(void)
// callers: []
//------------------------------------------------------------

ulong ts_mmi_doreflash_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  ulong __n;
  size_t sVar4;
  long lVar5;
  char *__string;
  undefined8 *puVar6;
  char local_d8 [64];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  puVar6 = *(undefined8 **)(param_1 + 0x98);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_d8[0x30] = '\0';
  local_d8[0x31] = '\0';
  local_d8[0x32] = '\0';
  local_d8[0x33] = '\0';
  local_d8[0x34] = '\0';
  local_d8[0x35] = '\0';
  local_d8[0x36] = '\0';
  local_d8[0x37] = '\0';
  local_d8[0x38] = '\0';
  local_d8[0x39] = '\0';
  local_d8[0x3a] = '\0';
  local_d8[0x3b] = '\0';
  local_d8[0x3c] = '\0';
  local_d8[0x3d] = '\0';
  local_d8[0x3e] = '\0';
  local_d8[0x3f] = '\0';
  local_d8[0x20] = '\0';
  local_d8[0x21] = '\0';
  local_d8[0x22] = '\0';
  local_d8[0x23] = '\0';
  local_d8[0x24] = '\0';
  local_d8[0x25] = '\0';
  local_d8[0x26] = '\0';
  local_d8[0x27] = '\0';
  local_d8[0x28] = '\0';
  local_d8[0x29] = '\0';
  local_d8[0x2a] = '\0';
  local_d8[0x2b] = '\0';
  local_d8[0x2c] = '\0';
  local_d8[0x2d] = '\0';
  local_d8[0x2e] = '\0';
  local_d8[0x2f] = '\0';
  local_d8[0x10] = '\0';
  local_d8[0x11] = '\0';
  local_d8[0x12] = '\0';
  local_d8[0x13] = '\0';
  local_d8[0x14] = '\0';
  local_d8[0x15] = '\0';
  local_d8[0x16] = '\0';
  local_d8[0x17] = '\0';
  local_d8[0x18] = '\0';
  local_d8[0x19] = '\0';
  local_d8[0x1a] = '\0';
  local_d8[0x1b] = '\0';
  local_d8[0x1c] = '\0';
  local_d8[0x1d] = '\0';
  local_d8[0x1e] = '\0';
  local_d8[0x1f] = '\0';
  local_d8[0] = '\0';
  local_d8[1] = '\0';
  local_d8[2] = '\0';
  local_d8[3] = '\0';
  local_d8[4] = '\0';
  local_d8[5] = '\0';
  local_d8[6] = '\0';
  local_d8[7] = '\0';
  local_d8[8] = '\0';
  local_d8[9] = '\0';
  local_d8[10] = '\0';
  local_d8[0xb] = '\0';
  local_d8[0xc] = '\0';
  local_d8[0xd] = '\0';
  local_d8[0xe] = '\0';
  local_d8[0xf] = '\0';
  if (param_4 < 0x41) {
    if (*(int *)((long)puVar6 + 0x14) == 0) {
      if (*(long *)(puVar6[0x7a] + 8) == 0) {
        iVar3 = 0;
      }
      else {
        mutex_lock(puVar6 + 0x15);
        if (*(int *)(*(code **)(puVar6[0x7a] + 8) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10351c);
          (*pcVar1)();
        }
        iVar3 = (**(code **)(puVar6[0x7a] + 8))(*puVar6,puVar6 + 0x5c);
        mutex_unlock(puVar6 + 0x15);
      }
      __string = (char *)(puVar6 + 0x5c);
      sVar4 = strnlen(__string,0x10);
      if (0x10 < sVar4) {
LAB_00103660:
        fortify_panic("strnlen");
LAB_0010366c:
        fortify_panic("strlcpy");
        goto LAB_00103678;
      }
      iVar2 = strncmp(param_3,__string,sVar4);
      if (iVar2 == 0) {
        if (*(long *)(puVar6[0x7a] + 0x10) != 0) {
          mutex_lock(puVar6 + 0x15);
          if (*(int *)(*(code **)(puVar6[0x7a] + 0x10) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103598);
            (*pcVar1)();
          }
          iVar3 = (**(code **)(puVar6[0x7a] + 0x10))(*puVar6,puVar6 + 0x5e);
          mutex_unlock(puVar6 + 0x15);
        }
        snprintf(local_d8,0x40,"-%s-",puVar6 + 0x5e);
        sVar4 = strnlen(__string,0x10);
        if (0x10 < sVar4) goto LAB_00103660;
        lVar5 = strnstr(param_3 + sVar4,local_d8,param_4);
        if (lVar5 != 0) goto LAB_00103420;
        __string = (char *)(puVar6 + 0x5e);
      }
      _dev_err(param_1,"%s: FW does not belong to %s\n","ts_mmi_doreflash_store",__string);
      goto LAB_00103624;
    }
    iVar3 = 0;
LAB_00103420:
    __n = strlen(param_3);
    if (param_4 <= __n) {
      __n = param_4 - 1;
    }
    if (param_4 != 0) {
      if (0x3f < __n) goto LAB_0010366c;
      memcpy(&local_98,param_3,__n);
      local_d8[__n + 0x40] = '\0';
    }
    mutex_lock(puVar6 + 0x15);
    pcVar1 = *(code **)(puVar6[0x7a] + 0x148);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != -0x765de347) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103490);
        (*pcVar1)();
      }
      iVar3 = (*pcVar1)(*puVar6,&local_98);
    }
    mutex_unlock(puVar6 + 0x15);
    if (iVar3 < 0) {
      _dev_err(param_1,"%s: firmware_update failed %d.\n","ts_mmi_doreflash_store",iVar3);
      goto LAB_00103624;
    }
    _dev_info(param_1,"%s: update fw from %s, return %d\n","ts_mmi_doreflash_store",&local_98,iVar3)
    ;
  }
  else {
    _dev_err(param_1,"%s: FW filename is too long\n","ts_mmi_doreflash_store");
LAB_00103624:
    param_4 = 0xffffffffffffffea;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) == local_58) {
    return param_4;
  }
LAB_00103678:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// pwr_store @ 00103680 size=244
// signature: undefined pwr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 pwr_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_40 = 0;
  iVar2 = kstrtoull(param_3,10,&local_40);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0x15);
      pcVar4 = *(code **)(puVar5[0x7a] + 0xb8);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103708);
          (*pcVar4)();
        }
        (*pcVar4)(*puVar5,local_40 & 0xffffffff);
      }
      mutex_unlock(puVar5 + 0x15);
      goto LAB_00103714;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"pwr_store");
  param_4 = 0xffffffffffffffea;
LAB_00103714:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// pinctrl_store @ 00103778 size=312
// signature: undefined pinctrl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 pinctrl_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)(puVar5 + 0x73) = (undefined4)local_50;
      pcVar4 = *(code **)(puVar5[0x7a] + 0xc0);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103814);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","pinctrl",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_0010382c;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"pinctrl");
  param_4 = 0xffffffffffffffea;
LAB_0010382c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// refresh_rate_store @ 001038b4 size=316
// signature: undefined refresh_rate_store(void)
// callers: []
//------------------------------------------------------------

undefined8 refresh_rate_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(char *)(puVar5 + 0x48) = (char)local_50;
      pcVar4 = *(code **)(puVar5[0x7a] + 200);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x103954);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5,(uint)local_50 & 0xff);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","refresh_rate",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_0010396c;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"refresh_rate");
  param_4 = 0xffffffffffffffea;
LAB_0010396c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// charger_mode_store @ 001039f4 size=312
// signature: undefined charger_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8 charger_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)(puVar5 + 0x72) = (undefined4)local_50;
      pcVar4 = *(code **)(puVar5[0x7a] + 0xd0);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103a90);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","charger_mode",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00103aa8;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"charger_mode");
  param_4 = 0xffffffffffffffea;
LAB_00103aa8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// update_baseline_store @ 00103b30 size=312
// signature: undefined update_baseline_store(void)
// callers: []
//------------------------------------------------------------

undefined8
update_baseline_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)((long)puVar5 + 0x39c) = (undefined4)local_50;
      pcVar4 = *(code **)(puVar5[0x7a] + 0x128);
      if (pcVar4 != (code *)0x0) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103bcc);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","update_baseline",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00103be4;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"update_baseline");
  param_4 = 0xffffffffffffffea;
LAB_00103be4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gesture_show @ 00103c6c size=60
// signature: undefined gesture_show(void)
// callers: []
//------------------------------------------------------------

long gesture_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%02x\n",*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x60));
  return (long)iVar1;
}



//------------------------------------------------------------
// gesture_store @ 00103cac size=504
// signature: undefined gesture_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gesture_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  byte bVar3;
  long lVar4;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_4c = 0;
  lVar1 = lVar4 + 0x78;
  mutex_lock(lVar1);
  iVar2 = sscanf(param_3,"%d",&local_4c);
  if (iVar2 < 0) {
    _dev_err(param_1,"forcereflash: Failed to convert value\n");
    mutex_unlock(lVar1);
    param_4 = 0xffffffffffffffea;
    goto LAB_00103e6c;
  }
  switch(local_4c) {
  case 0x10:
    _dev_info(param_1,"%s: zero tap disable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) & 0xfe;
    break;
  case 0x11:
    _dev_info(param_1,"%s: zero tap enable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) | 1;
    break;
  default:
    _dev_info(param_1,"%s: unsupport gesture mode type\n","gesture_store");
    goto LAB_00103e48;
  case 0x20:
    _dev_info(param_1,"%s: single tap disable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) & 0xfd;
    break;
  case 0x21:
    _dev_info(param_1,"%s: single tap enable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) | 2;
    break;
  case 0x30:
    _dev_info(param_1,"%s: double tap disable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) & 0xfb;
    break;
  case 0x31:
    _dev_info(param_1,"%s: double tap enable\n","gesture_store");
    bVar3 = *(byte *)(lVar4 + 0x18) | 4;
  }
  *(byte *)(lVar4 + 0x18) = bVar3;
LAB_00103e48:
  mutex_unlock(lVar1);
  _dev_info(param_1,"%s: gesture_mode_type = 0x%02x \n","gesture_store",
            *(undefined1 *)(lVar4 + 0x18));
LAB_00103e6c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// liquid_detection_ctl_show @ 00103ea8 size=64
// signature: undefined liquid_detection_ctl_show(void)
// callers: []
//------------------------------------------------------------

long liquid_detection_ctl_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"function status: %02x, detection result: %02x\n",
                    *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x2d9),
                    *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x2dc));
  return (long)iVar1;
}



//------------------------------------------------------------
// liquid_detection_ctl_store @ 00103eec size=388
// signature: undefined liquid_detection_ctl_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
liquid_detection_ctl_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = sscanf(param_3,"%d",&local_3c);
  if (iVar1 < 0) {
    _dev_err(param_1,"liquid_detection_ctl: Failed to convert value\n");
    param_4 = 0xffffffffffffffea;
  }
  else if (local_3c == 3) {
    _dev_info(param_1,"liquid_detection_ctl: Support liquid detecion\n");
    *(undefined1 *)(lVar2 + 0x30) = 1;
  }
  else if (local_3c == 2) {
    _dev_info(param_1,"liquid_detection_ctl: Not support liquid detecion\n");
    *(undefined1 *)(lVar2 + 0x30) = 0;
  }
  else {
    mutex_lock(lVar2 + 0x78);
    if (local_3c != *(byte *)(lVar2 + 0x2d9)) {
      *(bool *)(lVar2 + 0x2d9) = local_3c != 0;
      if (*(uint *)(lVar2 + 0x210) - *(int *)(lVar2 + 0x214) <= *(uint *)(lVar2 + 0x218)) {
        *(undefined1 *)
         (*(long *)(lVar2 + 0x220) + (ulong)(*(uint *)(lVar2 + 0x218) & *(uint *)(lVar2 + 0x210))) =
             5;
        DataMemoryBarrier(2,2);
        *(int *)(lVar2 + 0x210) = *(int *)(lVar2 + 0x210) + 1;
      }
      queue_delayed_work_on(0x20,_system_wq,lVar2 + 0x100,0);
      _dev_info(*(undefined8 *)(lVar2 + 8),"%s: LPD state is %d\n","liquid_detection_ctl_store",
                *(undefined1 *)(lVar2 + 0x2d9));
    }
    mutex_unlock(lVar2 + 0x78);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// active_region_show @ 00104074 size=276
// signature: undefined active_region_show(void)
// callers: []
//------------------------------------------------------------

long active_region_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_active_region: invalid pointer\n");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0xa0) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0xa0) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1040f4);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0xa0))(*puVar4,(long)puVar4 + 0x364);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_active_region: return error %d\n",iVar2);
      lVar3 = 0;
      goto LAB_00104130;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"%u %u %u %u",*(undefined4 *)((long)puVar4 + 0x364),
                    *(undefined4 *)(puVar4 + 0x6d),*(undefined4 *)((long)puVar4 + 0x36c),
                    *(undefined4 *)(puVar4 + 0x6e));
  lVar3 = (long)iVar2;
LAB_00104130:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// active_region_store @ 0010418c size=324
// signature: undefined active_region_store(void)
// callers: []
//------------------------------------------------------------

undefined8 active_region_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  uint local_48 [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  iVar2 = sscanf(param_3,"%u %u %u %u",local_48,(uint *)((ulong)local_48 | 4),local_48 + 2,
                 local_48 + 3);
  if (iVar2 < 4) {
    pcVar3 = "active_region: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(uint *)(puVar5 + 0x6e) = local_48[3];
      *(uint *)((long)puVar5 + 0x36c) = local_48[2];
      *(uint *)(puVar5 + 0x6d) = local_48[1];
      *(uint *)((long)puVar5 + 0x364) = local_48[0];
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0x138), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != -0x5c473463) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104264);
          (*pcVar4)();
        }
        (*pcVar4)(*puVar5,(long)puVar5 + 0x364);
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00104278;
    }
    pcVar3 = "active_region: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3);
  param_4 = 0xffffffffffffffea;
LAB_00104278:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// suppression_show @ 001042d4 size=280
// signature: undefined suppression_show(void)
// callers: []
//------------------------------------------------------------

long suppression_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","suppression");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x58) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x58) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104354);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x58))(*puVar4,(long)puVar4 + 0x354);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","suppression",iVar2);
      lVar3 = 0;
      goto LAB_00104384;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)((long)puVar4 + 0x354));
  lVar3 = (long)iVar2;
LAB_00104384:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// suppression_store @ 001043f0 size=324
// signature: undefined suppression_store(void)
// callers: []
//------------------------------------------------------------

undefined8 suppression_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)((long)puVar5 + 0x354) = (undefined4)local_50;
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0xe0), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104498);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","suppression",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_001044b0;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"suppression");
  param_4 = 0xffffffffffffffea;
LAB_001044b0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// pill_region_show @ 00104538 size=272
// signature: undefined pill_region_show(void)
// callers: []
//------------------------------------------------------------

long pill_region_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_pill_region: invalid pointer\n");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x70) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x70) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1045b8);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x70))(*puVar4,puVar4 + 0x6b);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_pill_region: return error %d\n",iVar2);
      lVar3 = 0;
      goto LAB_001045f0;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"0x%02x 0x%x 0x%x",*(undefined4 *)(puVar4 + 0x6b),
                    *(undefined4 *)((long)puVar4 + 0x35c),*(undefined4 *)(puVar4 + 0x6c));
  lVar3 = (long)iVar2;
LAB_001045f0:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// pill_region_store @ 0010464c size=316
// signature: undefined pill_region_store(void)
// callers: []
//------------------------------------------------------------

undefined8 pill_region_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  uint local_48 [4];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_48[2] = 0;
  local_48[0] = 0;
  local_48[1] = 0;
  iVar2 = sscanf(param_3,"0x%x 0x%x 0x%x",local_48,(uint *)((ulong)local_48 | 4),local_48 + 2);
  if (iVar2 < 3) {
    pcVar3 = "pill_region: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(uint *)(puVar5 + 0x6c) = local_48[2];
      *(uint *)((long)puVar5 + 0x35c) = local_48[1];
      *(uint *)(puVar5 + 0x6b) = local_48[0];
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0xf8), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != -0x5c473463) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10471c);
          (*pcVar4)();
        }
        (*pcVar4)(*puVar5,puVar5 + 0x6b);
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00104730;
    }
    pcVar3 = "pill_region: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3);
  param_4 = 0xffffffffffffffea;
LAB_00104730:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hold_distance_show @ 0010478c size=280
// signature: undefined hold_distance_show(void)
// callers: []
//------------------------------------------------------------

long hold_distance_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","hold_distance");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x78) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x78) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10480c);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x78))(*puVar4,(long)puVar4 + 0x374);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","hold_distance",iVar2);
      lVar3 = 0;
      goto LAB_0010483c;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)((long)puVar4 + 0x374));
  lVar3 = (long)iVar2;
LAB_0010483c:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// hold_distance_store @ 001048a8 size=324
// signature: undefined hold_distance_store(void)
// callers: []
//------------------------------------------------------------

undefined8
hold_distance_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)((long)puVar5 + 0x374) = (undefined4)local_50;
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0x100), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104950);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","hold_distance",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00104968;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"hold_distance");
  param_4 = 0xffffffffffffffea;
LAB_00104968:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gs_distance_show @ 001049f0 size=280
// signature: undefined gs_distance_show(void)
// callers: []
//------------------------------------------------------------

long gs_distance_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","gs_distance");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x80) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x80) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104a70);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x80))(*puVar4,puVar4 + 0x6f);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","gs_distance",iVar2);
      lVar3 = 0;
      goto LAB_00104aa0;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)(puVar4 + 0x6f));
  lVar3 = (long)iVar2;
LAB_00104aa0:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// gs_distance_store @ 00104b0c size=324
// signature: undefined gs_distance_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gs_distance_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)(puVar5 + 0x6f) = (undefined4)local_50;
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0x108), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104bb4);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","gs_distance",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00104bcc;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"gs_distance");
  param_4 = 0xffffffffffffffea;
LAB_00104bcc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// hold_grip_show @ 00104c54 size=280
// signature: undefined hold_grip_show(void)
// callers: []
//------------------------------------------------------------

long hold_grip_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(param_1,"get_%s: invalid pointer\n","hold_grip");
    return 0;
  }
  mutex_lock(puVar4 + 0xf);
  if ((*(int *)((long)puVar4 + 0xf4) == 2) && (*(long *)(puVar4[0x7a] + 0x60) != 0)) {
    mutex_lock(puVar4 + 0x15);
    if (*(int *)(*(code **)(puVar4[0x7a] + 0x60) + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104cd4);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(puVar4[0x7a] + 0x60))(*puVar4,(long)puVar4 + 0x37c);
    mutex_unlock(puVar4 + 0x15);
    if (iVar2 < 0) {
      _dev_err(param_1,"get_%s: return error %d\n","hold_grip",iVar2);
      lVar3 = 0;
      goto LAB_00104d04;
    }
  }
  iVar2 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)((long)puVar4 + 0x37c));
  lVar3 = (long)iVar2;
LAB_00104d04:
  mutex_unlock(puVar4 + 0xf);
  return lVar3;
}



//------------------------------------------------------------
// hold_grip_store @ 00104d70 size=324
// signature: undefined hold_grip_store(void)
// callers: []
//------------------------------------------------------------

undefined8 hold_grip_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar5 = *(undefined8 **)(param_1 + 0x98);
  local_50 = 0;
  iVar2 = kstrtoull(param_3,0,&local_50);
  if (iVar2 < 0) {
    pcVar3 = "%s: Failed to convert value\n";
  }
  else {
    if (puVar5 != (undefined8 *)0x0) {
      mutex_lock(puVar5 + 0xf);
      mutex_lock(puVar5 + 0x15);
      *(undefined4 *)((long)puVar5 + 0x37c) = (undefined4)local_50;
      if ((*(int *)((long)puVar5 + 0xf4) == 2) &&
         (pcVar4 = *(code **)(puVar5[0x7a] + 0xe8), pcVar4 != (code *)0x0)) {
        if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104e18);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(*puVar5);
        if (iVar2 < 0) {
          _dev_err(param_1,"%s: return error %d\n","hold_grip",iVar2);
        }
      }
      mutex_unlock(puVar5 + 0x15);
      mutex_unlock(puVar5 + 0xf);
      goto LAB_00104e30;
    }
    pcVar3 = "%s: invalid pointer\n";
  }
  _dev_err(param_1,pcVar3,"hold_grip");
  param_4 = 0xffffffffffffffea;
LAB_00104e30:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// ts_mmi_parse_dt @ 00104eb8 size=2728
// signature: undefined ts_mmi_parse_dt(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

undefined8 ts_mmi_parse_dt(undefined8 *param_1,undefined8 param_2)

{
  char *pcVar1;
  long lVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  long lVar9;
  size_t sVar10;
  undefined8 *puVar11;
  ulong uVar12;
  undefined8 uVar13;
  char *pcVar14;
  long lVar15;
  undefined *puVar16;
  char cVar17;
  char acVar18 [8];
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  ulong uVar22;
  undefined1 auVar23 [16];
  undefined8 uStack_128;
  undefined8 uStack_120;
  undefined8 uStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  undefined8 uStack_100;
  undefined8 uStack_f8;
  undefined8 uStack_f0;
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  long lStack_d8;
  long lStack_d0;
  undefined1 *puStack_c8;
  char *pcStack_c0;
  char *pcStack_b8;
  long lStack_b0;
  char *pcStack_a8;
  undefined8 uStack_a0;
  undefined8 *puStack_98;
  long local_90;
  long local_88;
  long local_80;
  long local_78;
  char *local_70;
  int local_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined8 local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_68 = 0;
  iStack_64 = 0;
  uStack_60 = 0;
  local_5c = 0;
  _dev_info(*param_1,"%s: Start parse touchscreen mmi device tree.\n","ts_mmi_parse_dt");
  iVar5 = of_property_read_string(param_2,"mmi,class-entry-name",param_1 + 10);
  if (iVar5 == 0) {
    _dev_info(*param_1,"%s: class-entry-name property %s\n","ts_mmi_parse_dt",param_1[10]);
  }
  iVar5 = of_property_read_string(param_2,"mmi,bound-display",param_1 + 0xb);
  if (iVar5 == 0) {
    _dev_info(*param_1,"%s: bound-display property %s\n","ts_mmi_parse_dt",param_1[0xb]);
  }
  iVar5 = of_property_read_variable_u32_array
                    (param_2,"mmi,control-dsi",(int *)((long)param_1 + 0x44),1,0);
  if (-1 < iVar5) {
    _dev_info(*param_1,"%s: ctrl-dsi property %d\n","ts_mmi_parse_dt",
              *(undefined4 *)((long)param_1 + 0x44));
  }
  lVar9 = of_find_property(param_2,"mmi,usb-charger-detection",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using usb detection\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x23) = 1;
  }
  iVar5 = of_property_read_variable_u32_array(param_2,"mmi,reset-on-resume",param_1 + 9,1,0);
  if (-1 < iVar5) {
    _dev_info(*param_1,"%s: using %u reset on resume\n","ts_mmi_parse_dt",
              *(undefined4 *)(param_1 + 9));
  }
  lVar9 = of_find_property(param_2,"mmi,fw-load-on-resume",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: load firmware on resume\n","ts_mmi_parse_dt");
    *(undefined1 *)(param_1 + 5) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,power-off-suspend",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using power off in suspend\n","ts_mmi_parse_dt");
    *(undefined1 *)(param_1 + 4) = 1;
    if (*(int *)(param_1 + 9) != 0) {
      *(undefined4 *)(param_1 + 9) = 0;
      _dev_info(*param_1,"%s: unset reset on resume!!!\n","ts_mmi_parse_dt");
    }
  }
  lVar9 = of_find_property(param_2,"mmi,enable-gestures",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using enable gestures\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x25) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,cli-enable-gestures",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using enable cli gestures\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x26) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,enable-palm",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using enable palm\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x27) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,refresh-rate-update",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using refresh rate update\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x24) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,suppression-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using suppression\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x29) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,pill-region-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using pill region\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2a) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,active-region-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using active region\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2f) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,hold-distance-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using hold distance\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2b) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,gs-distance-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using gs distance\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2c) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,hold-grip-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using hold grip\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2d) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,poison-slot-control",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using poison slot\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x2e) = 1;
  }
  lVar9 = of_find_property(param_2,"mmi,fps_detection",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using fps detection\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x21) = 1;
  }
  iVar5 = of_property_read_variable_u32_array(param_2,"mmi,max_coords",&local_68,2,0);
  if (-1 < iVar5) {
    _dev_info(*param_1,"%s: get max_coords property\n","ts_mmi_parse_dt");
    *(int *)((long)param_1 + 0x34) = local_68 + -1;
    *(int *)(param_1 + 7) = iStack_64 + -1;
  }
  lVar9 = of_find_property(param_2,"mmi,fod_detection",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: using fod detection\n","ts_mmi_parse_dt");
    *(undefined1 *)((long)param_1 + 0x22) = 1;
  }
  iVar5 = of_property_read_variable_u32_array(param_2,"mmi,fod_coords",&local_68,2,0);
  if (-1 < iVar5) {
    *(int *)((long)param_1 + 0x3c) = local_68;
    *(int *)(param_1 + 8) = iStack_64;
    _dev_info(*param_1,"%s: get fod_coords property x:%d y:%d\n","ts_mmi_parse_dt");
  }
  iVar5 = of_property_read_variable_u32_array
                    (param_2,"mmi,supported_gesture_type",param_1 + 0xc,1,0);
  if (-1 < iVar5) {
    _dev_info(*param_1,"%s: supported_gesture_type property %02x\n","ts_mmi_parse_dt",
              *(undefined4 *)(param_1 + 0xc));
  }
  lVar9 = of_find_property(param_2,"mmi,support-liquid-detection",0);
  if (lVar9 != 0) {
    _dev_info(*param_1,"%s: support liquid detection\n","ts_mmi_parse_dt");
    *(undefined1 *)(param_1 + 6) = 1;
  }
  iVar5 = of_property_read_variable_u32_array(param_2,"mmi,clip-area",&local_68,4,0);
  if (-1 < iVar5) {
    *(undefined1 *)((long)param_1 + 0x31) = 1;
    *(int *)(param_1 + 0x77) = local_68;
    *(ulong *)((long)param_1 + 0x3bc) = CONCAT44(uStack_60,iStack_64);
    *(undefined4 *)((long)param_1 + 0x3c4) = local_5c;
    lVar9 = of_find_property(param_2,"mmi,clip-inversion",0);
    if (lVar9 == 0) {
      puVar16 = &UNK_00108dd5;
      if (*(char *)(param_1 + 0x79) != '\0') {
        puVar16 = &DAT_0010a541;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x79) = 1;
      puVar16 = &DAT_0010a541;
    }
    _dev_info(*param_1,"%s: clip %sarea: (%u,%u) (%u,%u)\n","ts_mmi_parse_dt",puVar16,
              *(undefined4 *)(param_1 + 0x77),*(undefined4 *)((long)param_1 + 0x3bc),
              *(undefined4 *)(param_1 + 0x78),*(undefined4 *)((long)param_1 + 0x3c4));
  }
  iVar5 = of_property_read_variable_u32_array
                    (param_2,"mmi,resolution_boost",(long)param_1 + 100,1,0);
  if (-1 < iVar5) {
    _dev_info(*param_1,"%s: resolution_boost = %d\n","ts_mmi_parse_dt",
              *(undefined4 *)((long)param_1 + 100));
  }
  lVar9 = of_find_node_by_name(0,"chosen");
  if (lVar9 == 0) {
LAB_001051cc:
    lVar9 = sp_el0;
    if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return 0;
  }
  bVar4 = *(int *)((long)param_1 + 0x44) != 0;
  pcVar14 = "mmi,panel_name";
  if (bVar4) {
    pcVar14 = "mmi,panel_name_s";
  }
  local_78 = 0;
  local_70 = (char *)0x0;
  pcVar21 = "mmi,panel_ver";
  if (bVar4) {
    pcVar21 = "mmi,panel_ver_s";
  }
  pcVar1 = "mmi,panel_id";
  if (bVar4) {
    pcVar1 = "mmi,panel_id_s";
  }
  local_80 = 0;
  iVar5 = of_property_read_string(lVar9,pcVar14,&local_70);
  pcVar19 = local_70;
  if ((iVar5 == 0) && (iVar6 = strncmp(local_70,"none",4), iVar6 != 0)) {
    _dev_info(*param_1,"%s: %s %s\n","ts_mmi_parse_dt",pcVar14,pcVar19);
    pcVar19 = local_70;
    iVar5 = strncmp(local_70,"dsi_",4);
    pcVar14 = (char *)(param_1 + 0x66);
    lVar2 = (ulong)(iVar5 == 0) * 4;
    cVar17 = pcVar19[lVar2];
    if (cVar17 != '_') {
      pcVar19 = pcVar19 + lVar2;
      pcVar20 = pcVar14;
      do {
        pcVar19 = pcVar19 + 1;
        *pcVar20 = cVar17;
        cVar17 = *pcVar19;
        pcVar20 = pcVar20 + 1;
      } while (cVar17 != '_');
    }
    iVar5 = of_property_read_u64(lVar9,pcVar1,&local_80);
    if (iVar5 == 0) {
      iVar5 = of_property_read_u64(lVar9,pcVar21,&local_78);
      if (iVar5 == 0) {
        lVar9 = of_find_node_by_name(param_2,"mmi,panel-mappings");
        if (lVar9 == 0) {
          _dev_info(*param_1,"%s: no panel mappings\n","ts_mmi_parse_dt");
        }
        else {
          puVar11 = (undefined8 *)of_get_next_child(lVar9,0);
          if (puVar11 != (undefined8 *)0x0) {
            do {
              local_90 = 0;
              local_88 = 0;
              iVar5 = of_property_read_u64(puVar11,"panel-id",&local_88);
              if (iVar5 != 0) {
                uVar13 = *param_1;
                pcVar14 = "%s: cannot read panel-id %d\n";
LAB_00105934:
                _dev_err(uVar13,pcVar14,"ts_mmi_parse_dt",iVar5);
                goto LAB_001051cc;
              }
              iVar5 = of_property_read_u64(puVar11,"panel-ver",&local_90);
              if (iVar5 != 0) {
                uVar13 = *param_1;
                pcVar14 = "%s: cannot read panel-ver %d\n";
                goto LAB_00105934;
              }
              if ((local_88 == local_80) && (local_90 == local_78)) {
                pcVar21 = (char *)*puVar11;
                sVar10 = strlen(pcVar21);
                if (0xe < sVar10) {
                  sVar10 = 0xf;
                }
                memcpy(pcVar14,pcVar21,sVar10);
                pcVar14[sVar10] = '\0';
                break;
              }
              puVar11 = (undefined8 *)of_get_next_child(lVar9,puVar11);
            } while (puVar11 != (undefined8 *)0x0);
          }
          _dev_info(*param_1,"%s: panel-supplier %s\n","ts_mmi_parse_dt",pcVar14);
        }
      }
      else {
        _dev_err(*param_1,"%s: cannot read %s %d\n","ts_mmi_parse_dt",pcVar21,iVar5);
      }
    }
    else {
      _dev_err(*param_1,"%s: cannot read %s %d\n","ts_mmi_parse_dt",pcVar1,iVar5);
    }
    goto LAB_001051cc;
  }
  _dev_err(*param_1,"%s: cannot read %s %d\n","ts_mmi_parse_dt",pcVar14,iVar5);
  sVar10 = strnlen(pcVar14,0x11);
  if (sVar10 < 0x12) {
    if (sVar10 != 0x11) {
      iVar5 = strncmp(pcVar14,"mmi,panel_name",sVar10);
      if (iVar5 == 0) {
        acVar18[0] = 'd';
        acVar18[1] = 'u';
        acVar18[2] = 'm';
        acVar18[3] = 'm';
        acVar18[4] = 'y';
        acVar18[5] = '\0';
        acVar18[6] = '\0';
        acVar18[7] = '\0';
      }
      else {
        acVar18 = s_dummy_s_00108380;
      }
      *(char (*) [8])(param_1 + 0x66) = acVar18;
      param_1[0x67] = 0;
      goto LAB_001051cc;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  auVar23 = fortify_panic("__fortify_strlen");
  lVar15 = auVar23._8_8_;
  puStack_c8 = &UNK_00105960;
  lVar2 = sp_el0;
  lStack_d8 = *(long *)(lVar2 + 0x638);
  lStack_d0 = (long)register0x00000008 + -0x50;
  pcStack_c0 = pcVar1;
  pcStack_b8 = pcVar21;
  lStack_b0 = lVar9;
  pcStack_a8 = pcVar14;
  uStack_a0 = param_2;
  puStack_98 = param_1;
  iVar5 = of_count_phandle_with_args(lVar15,"panel",0);
  if (0 < iVar5) {
    iVar6 = 0;
    do {
      uStack_e8 = 0;
      uStack_e0 = 0;
      uStack_f8 = 0;
      uStack_f0 = 0;
      uStack_108 = 0;
      uStack_100 = 0;
      uStack_118 = 0;
      uStack_110 = 0;
      uStack_128 = 0;
      uStack_120 = 0;
      iVar7 = __of_parse_phandle_with_args(lVar15,"panel",0,0,iVar6,&uStack_128);
      uVar13 = uStack_128;
      if (iVar7 != 0) {
        uVar13 = 0;
      }
      uVar12 = of_drm_find_panel(uVar13);
      if (uVar12 < 0xfffffffffffff001) {
        _dev_info(*auVar23._0_8_,"%s: find drm_panel successfully","ts_mmi_check_dt");
        uVar13 = 0;
        auVar23._0_8_[0xd] = uVar12;
        goto LAB_00105b50;
      }
      iVar6 = iVar6 + 1;
    } while (iVar5 != iVar6);
  }
  uVar8 = of_property_read_string_helper
                    (*(undefined8 *)(lVar15 + 0x70),"qcom,mmi-touch-active",0,0,0);
  if (0 < (int)uVar8) {
    uVar12 = (ulong)uVar8 * 8;
    lVar9 = __kmalloc(uVar12,0xdc0);
    if (lVar9 == 0) {
      _printk(&DAT_001094a5,"ts_mmi_check_default_tp");
    }
    else {
      iVar5 = of_property_read_string_helper
                        (*(undefined8 *)(lVar15 + 0x70),"qcom,mmi-touch-active",lVar9,(ulong)uVar8,0
                        );
      if (iVar5 < 0) {
        _printk(&DAT_00109978,"ts_mmi_check_default_tp","qcom,mmi-touch-active",iVar5);
      }
      else {
        uVar22 = 0;
        iVar5 = 0;
        do {
          if ((uVar12 == uVar22) || (uVar12 <= uVar22)) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x105b84);
            (*pcVar3)();
          }
          if ((*(long *)(lVar9 + uVar22) != 0) &&
             (iVar6 = of_device_is_compatible(lVar15), 0 < iVar6)) {
            iVar5 = iVar5 + 1;
          }
          uVar22 = uVar22 + 8;
        } while (uVar12 != uVar22);
        if (0 < iVar5) {
          kfree(lVar9);
          uVar13 = 0xfffffdfb;
          goto LAB_00105b50;
        }
        _printk(&DAT_00108dfa,"ts_mmi_check_default_tp");
      }
      kfree(lVar9);
    }
  }
  uVar13 = 0xffffffed;
LAB_00105b50:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != lStack_d8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return uVar13;
}



//------------------------------------------------------------
// ts_mmi_check_drm_panel @ 00105964 size=548
// signature: undefined ts_mmi_check_drm_panel(void)
// callers: [ts_mmi_worker_func]
//------------------------------------------------------------

void ts_mmi_check_drm_panel(undefined8 *param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
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
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  iVar2 = of_count_phandle_with_args(param_2,"panel",0);
  if (0 < iVar2) {
    iVar5 = 0;
    do {
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
      iVar3 = __of_parse_phandle_with_args(param_2,"panel",0,0,iVar5,&local_98);
      uVar8 = local_98;
      if (iVar3 != 0) {
        uVar8 = 0;
      }
      uVar6 = of_drm_find_panel(uVar8);
      if (uVar6 < 0xfffffffffffff001) {
        _dev_info(*param_1,"%s: find drm_panel successfully","ts_mmi_check_dt");
        uVar8 = 0;
        param_1[0xd] = uVar6;
        goto LAB_00105b50;
      }
      iVar5 = iVar5 + 1;
    } while (iVar2 != iVar5);
  }
  uVar4 = of_property_read_string_helper
                    (*(undefined8 *)(param_2 + 0x70),"qcom,mmi-touch-active",0,0,0);
  if (0 < (int)uVar4) {
    uVar6 = (ulong)uVar4 * 8;
    lVar7 = __kmalloc(uVar6,0xdc0);
    if (lVar7 == 0) {
      _printk(&DAT_001094a5,"ts_mmi_check_default_tp");
    }
    else {
      iVar2 = of_property_read_string_helper
                        (*(undefined8 *)(param_2 + 0x70),"qcom,mmi-touch-active",lVar7,(ulong)uVar4,
                         0);
      if (iVar2 < 0) {
        _printk(&DAT_00109978,"ts_mmi_check_default_tp","qcom,mmi-touch-active",iVar2);
      }
      else {
        uVar9 = 0;
        iVar2 = 0;
        do {
          if ((uVar6 == uVar9) || (uVar6 <= uVar9)) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(1,0x105b84);
            (*pcVar1)();
          }
          if ((*(long *)(lVar7 + uVar9) != 0) &&
             (iVar5 = of_device_is_compatible(param_2), 0 < iVar5)) {
            iVar2 = iVar2 + 1;
          }
          uVar9 = uVar9 + 8;
        } while (uVar6 != uVar9);
        if (0 < iVar2) {
          kfree(lVar7);
          uVar8 = 0xfffffdfb;
          goto LAB_00105b50;
        }
        _printk(&DAT_00108dfa,"ts_mmi_check_default_tp");
      }
      kfree(lVar7);
    }
  }
  uVar8 = 0xffffffed;
LAB_00105b50:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_panel_register @ 00105b8c size=124
// signature: undefined ts_mmi_panel_register(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

undefined8 ts_mmi_panel_register(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = 0xffffffed;
  }
  else {
    _dev_info(*param_1,"%s: Start panel init.\n","ts_mmi_panel_register");
    uVar1 = sysfs_create_group(param_1[1],&sysfs_panel_group);
    if ((int)uVar1 == 0) {
      _dev_info(*param_1,"%s: Panel init OK.\n","ts_mmi_panel_register");
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// ts_mmi_panel_unregister @ 00105c0c size=104
// signature: undefined ts_mmi_panel_unregister(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

void ts_mmi_panel_unregister(long param_1)

{
  if (*(long *)(param_1 + 8) == 0) {
    _dev_err(0,"%s:touch_cdev->class_dev == NULL","ts_mmi_panel_unregister");
  }
  else {
    sysfs_remove_group(*(long *)(param_1 + 8),&sysfs_panel_group);
    _dev_info(*(undefined8 *)(param_1 + 8),"%s:panel_unregister finish","ts_mmi_panel_unregister");
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_panel_supplier_show @ 00105c78 size=60
// signature: undefined ts_mmi_panel_supplier_show(void)
// callers: []
//------------------------------------------------------------

long ts_mmi_panel_supplier_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00109e55,*(long *)(param_1 + 0x98) + 0x330);
  return (long)iVar1;
}



//------------------------------------------------------------
// ts_mmi_notifiers_register @ 00105cb8 size=848
// signature: undefined ts_mmi_notifiers_register(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ts_mmi_notifiers_register(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  byte local_4c [4];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  if (param_1[1] == 0) {
    iVar2 = -0x13;
    goto LAB_00105cec;
  }
  _dev_info(*param_1,"%s: Start notifiers init.\n","ts_mmi_notifiers_register");
  param_1[0x20] = 0xfffffffe0;
  param_1[0x21] = param_1 + 0x21;
  param_1[0x22] = param_1 + 0x21;
  param_1[0x23] = ts_mmi_worker_func;
  init_timer_key(param_1 + 0x26,&delayed_work_timer_fn,0x200000,0,0);
  param_1[0x31] = 0xfffffffe0;
  param_1[0x32] = param_1 + 0x32;
  param_1[0x33] = param_1 + 0x32;
  param_1[0x34] = ts_mmi_ps_worker_func;
  init_timer_key(param_1 + 0x37,&delayed_work_timer_fn,0x200000,0,0);
  iVar2 = __kfifo_alloc(param_1 + 0x42,0x28,1,0xcc0);
  if (iVar2 != 0) goto LAB_00105cec;
  puVar1 = param_1 + 0x20;
  if (*(char *)((long)param_1 + 0x23) == '\0') {
    iVar2 = 0;
LAB_00105e04:
    *(undefined4 *)((long)param_1 + 0xf4) = 2;
    if (*(uint *)(param_1 + 0x42) - *(int *)((long)param_1 + 0x214) <= *(uint *)(param_1 + 0x43)) {
      *(undefined1 *)
       (param_1[0x44] + (ulong)(*(uint *)(param_1 + 0x43) & *(uint *)(param_1 + 0x42))) = 4;
      DataMemoryBarrier(2,2);
      *(int *)(param_1 + 0x42) = *(int *)(param_1 + 0x42) + 1;
    }
    queue_delayed_work_on(0x20,_system_wq,puVar1,0);
    if ((*(char *)((long)param_1 + 0x24) == '\0') ||
       (param_1[0x45] = ts_mmi_refresh_rate_cb, iVar2 == 0)) {
      if (((*(char *)((long)param_1 + 0x21) != '\0') || (*(char *)((long)param_1 + 0x22) != '\0'))
         && (iVar2 = ts_mmi_fps_notifier_register(param_1,1), iVar2 < 0)) {
        _dev_err(*param_1,"Failed to register fps_notifier: %d\n",iVar2);
      }
      if ((*(char *)(param_1 + 6) != '\0') &&
         (iVar2 = ts_mmi_lpd_notifier_register(param_1,1), iVar2 < 0)) {
        _dev_err(*param_1,"Failed to register lpd_notifier: %d\n",iVar2);
      }
      _dev_info(*param_1,"%s: Notifiers init OK.\n","ts_mmi_notifiers_register");
      iVar2 = 0;
      goto LAB_00105cec;
    }
    cancel_delayed_work(puVar1);
    cancel_delayed_work(param_1 + 0x31);
  }
  else {
    local_4c[0] = 0;
    param_1[0x4f] = ts_mmi_charger_cb;
    iVar2 = power_supply_reg_notifier(param_1 + 0x4f);
    if (iVar2 == 0) {
      lVar3 = power_supply_get_by_name(&DAT_0010a043);
      if (lVar3 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = ts_mmi_ps_get_state(lVar3,local_4c);
        if (iVar2 == 0) {
          *(byte *)(param_1 + 0x52) = *(byte *)(param_1 + 0x52) | local_4c[0];
        }
        power_supply_put(lVar3);
      }
      lVar3 = power_supply_get_by_name("wireless");
      if (lVar3 != 0) {
        iVar2 = ts_mmi_ps_get_state(lVar3,local_4c);
        if (iVar2 == 0) {
          *(byte *)(param_1 + 0x52) = *(byte *)(param_1 + 0x52) | local_4c[0];
        }
        power_supply_put(lVar3);
      }
      if (*(uint *)(param_1 + 0x42) - *(int *)((long)param_1 + 0x214) <= *(uint *)(param_1 + 0x43))
      {
        *(undefined1 *)
         (param_1[0x44] + (ulong)(*(uint *)(param_1 + 0x43) & *(uint *)(param_1 + 0x42))) = 1;
        DataMemoryBarrier(2,2);
        *(int *)(param_1 + 0x42) = *(int *)(param_1 + 0x42) + 1;
      }
      queue_delayed_work_on(0x20,_system_wq,puVar1,0);
      _dev_info(param_1[1],"%s: USB initial status=%d\n","ts_mmi_notifiers_register",
                *(undefined1 *)(param_1 + 0x52));
      goto LAB_00105e04;
    }
  }
  __kfifo_free(param_1 + 0x42);
LAB_00105cec:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// ts_mmi_worker_func @ 0010600c size=2144
// signature: undefined ts_mmi_worker_func(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ts_mmi_worker_func(long param_1)

{
  long *plVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  char *pcVar7;
  char cVar8;
  uint uVar9;
  code *pcVar10;
  uint uVar11;
  long *plVar12;
  long lVar13;
  int *piVar14;
  undefined1 uVar15;
  
  uVar11 = *(uint *)(param_1 + 0x110);
  uVar9 = *(uint *)(param_1 + 0x114);
  if (uVar11 != uVar9) {
    plVar12 = (long *)(param_1 + -0x100);
    lVar13 = param_1 + -0x58;
    plVar1 = (long *)(param_1 + 0x2d0);
    piVar14 = (int *)(param_1 + -0x10);
    do {
      uVar15 = *(undefined1 *)
                (*(long *)(param_1 + 0x120) + (ulong)(*(uint *)(param_1 + 0x118) & uVar9));
      DataMemoryBarrier(2,2);
      *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + 1;
      switch(uVar15) {
      case 0:
        if (*(int *)(param_1 + -8) == 0) {
          Hint_Prefetch(piVar14,2,0,1);
          do {
            iVar3 = *piVar14;
            if (iVar3 != 1) goto LAB_00106880;
            cVar8 = '\x01';
            bVar2 = (bool)ExclusiveMonitorPass(piVar14,0x10);
            if (bVar2) {
              *piVar14 = 0;
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          DataMemoryBarrier(2,3);
LAB_00106880:
          if (iVar3 == 0) break;
          mutex_lock(lVar13);
          pcVar10 = *(code **)(*plVar1 + 0x170);
          if (pcVar10 != (code *)0x0) {
            if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1061c0);
              (*pcVar10)();
            }
            (*pcVar10)(*plVar12);
          }
          mutex_unlock(lVar13);
          if (*(char *)(param_1 + -0xdf) != '\0') {
            if (*(char *)(param_1 + 0x1b9) != '\0') {
              mutex_lock(lVar13);
              pcVar10 = *(code **)(*plVar1 + 0x128);
              if (pcVar10 != (code *)0x0) {
                if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106210);
                  (*pcVar10)();
                }
                (*pcVar10)(*plVar12,0);
              }
              mutex_unlock(lVar13);
              *(undefined1 *)(param_1 + 0x1ba) = 1;
              if (*(char *)(param_1 + 0x1b9) != '\0') goto LAB_00106270;
            }
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x128);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106260);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,1);
            }
            mutex_unlock(lVar13);
            *(undefined1 *)(param_1 + 0x1ba) = 0;
          }
LAB_00106270:
          if (*(char *)(param_1 + -0xde) != '\0') {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x130);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1062ac);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined1 *)(param_1 + 0x1b9));
            }
            mutex_unlock(lVar13);
          }
          cVar8 = *(char *)(param_1 + -0xe0);
          if (((cVar8 == '\0') || (*(long *)(*plVar1 + 0xb8) == 0)) ||
             (*(int *)(param_1 + -0xc) != 0)) {
            if (*(int *)(param_1 + -0xb8) != 0) goto LAB_00106500;
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x160);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x685b3cd3) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1064f8);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined4 *)(param_1 + -0xc),2);
            }
LAB_0010653c:
            mutex_unlock(lVar13);
          }
          else {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x168);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106304);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12);
            }
            mutex_unlock(lVar13);
            cVar8 = *(char *)(param_1 + -0xe0);
LAB_00106500:
            if (cVar8 != '\0') {
              mutex_lock(lVar13);
              pcVar10 = *(code **)(*plVar1 + 0xb0);
              if (pcVar10 != (code *)0x0) {
                if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                  pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106538);
                  (*pcVar10)();
                }
                (*pcVar10)(*plVar12,1);
              }
              goto LAB_0010653c;
            }
          }
          if (*(int *)(param_1 + -0xc) == 0) {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0xb0);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106580);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,1);
            }
            mutex_unlock(lVar13);
          }
          mutex_lock(lVar13);
          pcVar10 = *(code **)(*plVar1 + 0x178);
          if (pcVar10 != (code *)0x0) {
            if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1065bc);
              (*pcVar10)();
            }
            (*pcVar10)(*plVar12);
          }
          mutex_unlock(lVar13);
          mutex_lock(param_1 + -0x88);
          if (*(char *)(param_1 + -0xdd) == '\0') {
            if (*(char *)(param_1 + -0xdc) == '\0') goto LAB_001065e0;
LAB_0010668c:
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 200);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1066c0);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined1 *)(param_1 + 0x140));
            }
            mutex_unlock(lVar13);
            if (*(char *)(param_1 + -0xd7) != '\0') goto LAB_001066d4;
LAB_001065e8:
            if (*(char *)(param_1 + -0xd6) == '\0') goto LAB_001065f0;
LAB_0010671c:
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0xf8);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x5c473463) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106750);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,param_1 + 600);
            }
            mutex_unlock(lVar13);
            if (*(char *)(param_1 + -0xd5) != '\0') goto LAB_00106764;
LAB_001065f8:
            if (*(char *)(param_1 + -0xd4) == '\0') goto LAB_00106600;
LAB_001067ac:
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x108);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1067e0);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined4 *)(param_1 + 0x278));
            }
            mutex_unlock(lVar13);
            cVar8 = *(char *)(param_1 + -0xd1);
          }
          else {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0xd0);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106678);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined1 *)(param_1 + 400));
            }
            mutex_unlock(lVar13);
            if (*(char *)(param_1 + -0xdc) != '\0') goto LAB_0010668c;
LAB_001065e0:
            if (*(char *)(param_1 + -0xd7) == '\0') goto LAB_001065e8;
LAB_001066d4:
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0xe0);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106708);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined4 *)(param_1 + 0x254));
            }
            mutex_unlock(lVar13);
            if (*(char *)(param_1 + -0xd6) != '\0') goto LAB_0010671c;
LAB_001065f0:
            if (*(char *)(param_1 + -0xd5) == '\0') goto LAB_001065f8;
LAB_00106764:
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x100);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106798);
                (*pcVar10)();
              }
              (*pcVar10)(*(undefined8 *)(param_1 + -0x100),*(undefined4 *)(param_1 + 0x274));
            }
            mutex_unlock(lVar13);
            if (*(char *)(param_1 + -0xd4) != '\0') goto LAB_001067ac;
LAB_00106600:
            cVar8 = *(char *)(param_1 + -0xd1);
          }
          if (cVar8 != '\0') {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x138);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x5c473463) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106828);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,param_1 + 0x264);
            }
            mutex_unlock(lVar13);
          }
          *(undefined4 *)(param_1 + -0xc) = 2;
          mutex_unlock(param_1 + -0x88);
          _dev_info(*(undefined8 *)(param_1 + -0xf8),"%s: done\n","ts_mmi_queued_resume");
        }
        else {
          uVar5 = *(undefined8 *)(param_1 + -0xf8);
          pcVar7 = "%s: resume cancelled\n";
LAB_00106638:
          _dev_info(uVar5,pcVar7,"ts_mmi_worker_func");
        }
        break;
      case 1:
        mutex_lock(lVar13);
        pcVar10 = *(code **)(*plVar1 + 0xd0);
        if (pcVar10 != (code *)0x0) {
          uVar5 = *(undefined8 *)(param_1 + -0x100);
          uVar15 = *(undefined1 *)(param_1 + 400);
LAB_001060f8:
          if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106110);
            (*pcVar10)();
          }
          (*pcVar10)(uVar5,uVar15);
        }
        goto LAB_00106114;
      case 2:
        mutex_lock(lVar13);
        pcVar10 = *(code **)(*plVar1 + 200);
        if (pcVar10 != (code *)0x0) {
          uVar5 = *(undefined8 *)(param_1 + -0x100);
          uVar15 = *(undefined1 *)(param_1 + 0x140);
          goto LAB_001060f8;
        }
        goto LAB_00106114;
      case 3:
        if (*(char *)(param_1 + -0xdf) != '\0') {
          if (*(char *)(param_1 + 0x1b9) == '\0') {
            if (*(char *)(param_1 + 0x1ba) == '\0') goto LAB_00106448;
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x128);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x106434);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,1);
            }
            uVar15 = 0;
          }
          else {
            mutex_lock(lVar13);
            pcVar10 = *(code **)(*plVar1 + 0x128);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1063ac);
                (*pcVar10)();
              }
              (*pcVar10)(*plVar12,0);
            }
            uVar15 = 1;
          }
          mutex_unlock(lVar13);
          *(undefined1 *)(param_1 + 0x1ba) = uVar15;
        }
LAB_00106448:
        if (*(char *)(param_1 + -0xde) != '\0') {
          mutex_lock(lVar13);
          pcVar10 = *(code **)(*plVar1 + 0x130);
          if (pcVar10 != (code *)0x0) {
            uVar5 = *(undefined8 *)(param_1 + -0x100);
            uVar15 = *(undefined1 *)(param_1 + 0x1b9);
            goto LAB_001060f8;
          }
          goto LAB_00106114;
        }
        break;
      case 4:
        iVar3 = ts_mmi_check_drm_panel(plVar12,*(undefined8 *)(*plVar12 + 0x2e8));
        if (-1 < iVar3) {
          *(undefined4 *)(param_1 + -0xe4) = 0;
          bVar2 = *(int *)(param_1 + -0xbc) != 0;
          if (bVar2) {
            uVar5 = 2;
          }
          else {
            uVar5 = 1;
          }
          lVar6 = panel_event_notifier_register
                            (uVar5,bVar2,*(undefined8 *)(param_1 + -0x98),ts_mmi_panel_cb,plVar12);
          if (lVar6 != 0) {
            *(long *)(param_1 + -0x90) = lVar6;
          }
          uVar5 = *(undefined8 *)(param_1 + -0xf8);
          pcVar7 = "%s: register panel notifier\n";
          goto LAB_00106638;
        }
        iVar4 = ___ratelimit(&ts_mmi_worker_func_register_panel,"ts_mmi_worker_func");
        if (iVar4 != 0) {
          _dev_err(*plVar12,"%s: check drm panel failed. %d\n","ts_mmi_worker_func",iVar3);
        }
        *(undefined4 *)(param_1 + -0xe4) = 0xffffffff;
        break;
      case 5:
        mutex_lock(lVar13);
        pcVar10 = *(code **)(*plVar1 + 0x140);
        if (pcVar10 != (code *)0x0) {
          uVar5 = *(undefined8 *)(param_1 + -0x100);
          uVar15 = *(undefined1 *)(param_1 + 0x1d9);
          goto LAB_001060f8;
        }
LAB_00106114:
        mutex_unlock(lVar13);
      }
      uVar11 = *(uint *)(param_1 + 0x110);
      uVar9 = *(uint *)(param_1 + 0x114);
    } while (uVar11 != uVar9);
  }
  if (*(int *)(param_1 + -0xe4) == -1) {
    *(undefined1 *)(*(long *)(param_1 + 0x120) + (ulong)(*(uint *)(param_1 + 0x118) & uVar11)) = 4;
    DataMemoryBarrier(2,2);
    *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + 1;
    queue_delayed_work_on(0x20,_system_wq,param_1,0x19);
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_ps_worker_func @ 0010688c size=368
// signature: undefined ts_mmi_ps_worker_func(void)
// callers: []
//------------------------------------------------------------

void ts_mmi_ps_worker_func(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  code *pcVar4;
  ulong uVar5;
  char *__s1;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar5 = *(ulong *)(param_1 + 0x110);
  if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
    local_40 = 0;
    iVar3 = power_supply_get_property(uVar5,3,&local_40);
    if ((iVar3 == 0) || (iVar3 = power_supply_get_property(uVar5,4,&local_40), iVar3 == 0)) {
      bVar2 = (int)local_40 != 0;
      *(bool *)(param_1 + 0x109) = bVar2;
      if ((*(undefined8 **)(param_1 + 0x110) != (undefined8 *)0x0) &&
         (__s1 = *(char **)**(undefined8 **)(param_1 + 0x110), __s1 != (char *)0x0)) {
        iVar3 = strncmp(__s1,"usb",4);
        if (iVar3 != 0) {
          iVar3 = strncmp(__s1,"wireless",9);
          if (iVar3 != 0) goto LAB_001069cc;
        }
        if ((bool)*(char *)(param_1 + 0x108) != bVar2) {
          *(bool *)(param_1 + 0x108) = bVar2;
          if (*(int *)(param_1 + -0x94) == 2) {
            mutex_lock(param_1 + -0xe0);
            pcVar4 = *(code **)(*(long *)(param_1 + 0x248) + 0xd0);
            if (pcVar4 != (code *)0x0) {
              if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10699c);
                (*pcVar4)();
              }
              (*pcVar4)(*(undefined8 *)(param_1 + -0x188),*(undefined1 *)(param_1 + 0x108));
            }
            mutex_unlock(param_1 + -0xe0);
          }
        }
      }
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + -0x180),"%s: failed to get power supply status: %d\n",
               "ts_mmi_ps_worker_func",iVar3);
    }
  }
LAB_001069cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_charger_cb @ 00106a00 size=144
// signature: undefined ts_mmi_charger_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ts_mmi_charger_cb(long param_1,long param_2,long *param_3)

{
  int iVar1;
  char *__s1;
  
  *(long **)(param_1 + 0x20) = param_3;
  if ((((param_2 == 0) && (param_3 != (long *)0x0)) && (((undefined8 *)*param_3)[6] != 0)) &&
     ((__s1 = *(char **)*param_3, __s1 != (char *)0x0 &&
      ((iVar1 = strncmp(__s1,"usb",4), iVar1 == 0 ||
       (iVar1 = strncmp(__s1,"wireless",9), iVar1 == 0)))))) {
    queue_delayed_work_on(0x20,_system_wq,param_1 + -0xf0,0);
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_ps_get_state @ 00106a90 size=144
// signature: undefined ts_mmi_ps_get_state(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

void ts_mmi_ps_get_state(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = power_supply_get_property(param_1,3,&local_30);
  if ((iVar2 == 0) || (uVar3 = power_supply_get_property(param_1,4,&local_30), (int)uVar3 == 0)) {
    uVar3 = 0;
    *(bool *)param_2 = (int)local_30 != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// ts_mmi_refresh_rate_cb @ 00106b24 size=152
// signature: undefined ts_mmi_refresh_rate_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ts_mmi_refresh_rate_cb(long param_1,char param_2)

{
  if (param_1 != 0x228) {
    if (((*(char *)(param_1 + 0x18) == '\0') || (*(char *)(param_1 + 0x18) != param_2)) &&
       (*(char *)(param_1 + 0x18) = param_2, *(int *)(param_1 + -0x134) == 2)) {
      if (*(uint *)(param_1 + -0x18) - *(int *)(param_1 + -0x14) <= *(uint *)(param_1 + -0x10)) {
        *(undefined1 *)
         (*(long *)(param_1 + -8) + (ulong)(*(uint *)(param_1 + -0x10) & *(uint *)(param_1 + -0x18))
         ) = 2;
        DataMemoryBarrier(2,2);
        *(int *)(param_1 + -0x18) = *(int *)(param_1 + -0x18) + 1;
      }
      queue_delayed_work_on(0x20,_system_wq,param_1 + -0x128,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_fps_notifier_register @ 00106bbc size=212
// signature: undefined ts_mmi_fps_notifier_register(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

int ts_mmi_fps_notifier_register(undefined8 *param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if ((param_2 & 1) == 0) {
    if (*(char *)(param_1 + 0x57) == '\0') {
      return 0;
    }
    iVar1 = relay_unregister_action(1,1,param_1 + 0x54);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Failed to unregister fps_notifier: %d\n",iVar1);
    }
    uVar2 = *param_1;
    pcVar3 = "Unregister fps_notifier OK\n";
    *(undefined1 *)(param_1 + 0x57) = 0;
  }
  else {
    param_1[0x54] = ts_mmi_fps_cb;
    iVar1 = relay_register_action(1,1,param_1 + 0x54);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Failed to register fps_notifier: %d\n",iVar1);
      return iVar1;
    }
    uVar2 = *param_1;
    *(undefined1 *)(param_1 + 0x57) = 1;
    pcVar3 = "Register fps_notifier OK\n";
  }
  _dev_info(uVar2,pcVar3);
  return 0;
}



//------------------------------------------------------------
// ts_mmi_lpd_notifier_register @ 00106c90 size=212
// signature: undefined ts_mmi_lpd_notifier_register(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

int ts_mmi_lpd_notifier_register(undefined8 *param_1,ulong param_2)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if ((param_2 & 1) == 0) {
    if (*(char *)(param_1 + 0x5b) == '\0') {
      return 0;
    }
    iVar1 = relay_unregister_action(1,3,param_1 + 0x58);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Failed to unregister lpd_notifier: %d\n",iVar1);
    }
    uVar2 = *param_1;
    pcVar3 = "Unregister lpd_notifier OK\n";
    *(undefined1 *)(param_1 + 0x5b) = 0;
  }
  else {
    param_1[0x58] = ts_mmi_lpd_cb;
    iVar1 = relay_register_action(1,3,param_1 + 0x58);
    if (iVar1 < 0) {
      _dev_err(*param_1,"Failed to register lpd_notifier: %d\n",iVar1);
      return iVar1;
    }
    uVar2 = *param_1;
    *(undefined1 *)(param_1 + 0x5b) = 1;
    pcVar3 = "Register lpd_notifier OK\n";
  }
  _dev_info(uVar2,pcVar3);
  return 0;
}



//------------------------------------------------------------
// ts_mmi_notifiers_unregister @ 00106d68 size=332
// signature: undefined ts_mmi_notifiers_unregister(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

void ts_mmi_notifiers_unregister(undefined8 *param_1)

{
  char cVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    _dev_err(0,"%s:touch_cdev->class_dev == NULL","ts_mmi_notifiers_unregister");
    return;
  }
  if (((*(char *)((long)param_1 + 0x21) != '\0') || (*(char *)((long)param_1 + 0x22) != '\0')) &&
     (*(char *)(param_1 + 0x57) != '\0')) {
    iVar2 = relay_unregister_action(1,1,param_1 + 0x54);
    if (iVar2 < 0) {
      _dev_err(*param_1,"Failed to unregister fps_notifier: %d\n",iVar2);
    }
    *(undefined1 *)(param_1 + 0x57) = 0;
    _dev_info(*param_1,"Unregister fps_notifier OK\n");
  }
  if (*(char *)((long)param_1 + 0x23) == '\0') {
    iVar2 = *(int *)((long)param_1 + 0x1c);
  }
  else {
    power_supply_unreg_notifier(param_1 + 0x4f);
    iVar2 = *(int *)((long)param_1 + 0x1c);
  }
  if (iVar2 == 0) {
    panel_event_notifier_unregister(param_1[0xe]);
    cVar1 = *(char *)(param_1 + 6);
  }
  else {
    cVar1 = *(char *)(param_1 + 6);
  }
  if ((cVar1 != '\0') && (*(char *)(param_1 + 0x5b) != '\0')) {
    iVar2 = relay_unregister_action(1,3,param_1 + 0x58);
    if (iVar2 < 0) {
      _dev_err(*param_1,"Failed to unregister lpd_notifier: %d\n",iVar2);
    }
    *(undefined1 *)(param_1 + 0x5b) = 0;
    _dev_info(*param_1,"Unregister lpd_notifier OK\n");
  }
  cancel_delayed_work(param_1 + 0x20);
  cancel_delayed_work(param_1 + 0x31);
  __kfifo_free(param_1 + 0x42);
  _dev_info(param_1[1],"%s:notifiers_unregister finish","ts_mmi_notifiers_unregister");
  return;
}



//------------------------------------------------------------
// ts_mmi_panel_cb @ 00106eb8 size=1140
// signature: undefined ts_mmi_panel_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ts_mmi_panel_cb(undefined8 param_1,uint *param_2,undefined8 *param_3)

{
  int *piVar1;
  undefined8 *puVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  uint uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  code *pcVar10;
  
  if ((param_2 == (uint *)0x0) || (param_3 == (undefined8 *)0x0)) {
    _dev_err(param_3[1],"%s: invalid evdata\n","ts_mmi_panel_cb");
    return;
  }
  uVar3 = *param_2;
  uVar7 = param_2[3];
  if (((uVar3 & 0xfffffffd) == 1) && ((uVar7 & 1) != 0)) {
    cancel_delayed_work_sync(param_3 + 0x20);
    cancel_delayed_work_sync(param_3 + 0x31);
    piVar1 = (int *)(param_3 + 0x1e);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      if (iVar4 != 0) goto LAB_0010715c;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010715c:
    if (iVar4 == 1) {
      cVar5 = *(char *)(param_3 + 4);
    }
    else {
      puVar2 = param_3 + 0x15;
      *(undefined4 *)(param_3 + 0x1f) = 1;
      mutex_lock(puVar2);
      pcVar10 = *(code **)(param_3[0x7a] + 0x180);
      if (pcVar10 != (code *)0x0) {
        if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1071a0);
          (*pcVar10)();
        }
        (*pcVar10)(*param_3);
      }
      mutex_unlock(puVar2);
      if ((((*(char *)((long)param_3 + 0x25) != '\0') || (*(char *)((long)param_3 + 0x26) != '\0'))
          || ((*(char *)(param_3 + 6) != '\0' || (*(char *)((long)param_3 + 0x27) != '\0')))) &&
         ((*(char *)(param_3 + 3) != '\0' || (*(char *)(param_3 + 6) != '\0')))) {
        _dev_info(param_3[1],"%s: try to enter Gesture mode\n","ts_mmi_panel_off");
        mutex_lock(puVar2);
        pcVar10 = *(code **)(param_3[0x7a] + 0x160);
        if (pcVar10 != (code *)0x0) {
          if (*(int *)(pcVar10 + -4) != -0x685b3cd3) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10722c);
            (*pcVar10)();
          }
          (*pcVar10)(*param_3,*(undefined4 *)((long)param_3 + 0xf4),1);
        }
        mutex_unlock(puVar2);
        *(undefined4 *)((long)param_3 + 0xf4) = 1;
      }
      if (*(int *)((long)param_3 + 0xf4) == 2) {
        _dev_info(param_3[1],"%s: try to enter Deepsleep mode\n","ts_mmi_panel_off");
        mutex_lock(puVar2);
        pcVar10 = *(code **)(param_3[0x7a] + 0x160);
        if (pcVar10 != (code *)0x0) {
          if (*(int *)(pcVar10 + -4) != -0x685b3cd3) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10729c);
            (*pcVar10)();
          }
          (*pcVar10)(*param_3,*(undefined4 *)((long)param_3 + 0xf4),0);
        }
        mutex_unlock(puVar2);
        mutex_lock(puVar2);
        pcVar10 = *(code **)(param_3[0x7a] + 0xb0);
        if (pcVar10 != (code *)0x0) {
          if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1072dc);
            (*pcVar10)();
          }
          (*pcVar10)(*param_3,0);
        }
        mutex_unlock(puVar2);
        *(undefined4 *)((long)param_3 + 0xf4) = 0;
      }
      mutex_lock(puVar2);
      pcVar10 = *(code **)(param_3[0x7a] + 0x188);
      if (pcVar10 != (code *)0x0) {
        if (*(int *)(pcVar10 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10731c);
          (*pcVar10)();
        }
        (*pcVar10)(*param_3);
      }
      mutex_unlock(puVar2);
      _dev_info(param_3[1],"%s: done\n","ts_mmi_panel_off");
      cVar5 = *(char *)(param_3 + 4);
    }
    if (cVar5 == '\0') {
      return;
    }
    if (*(long *)(param_3[0x7a] + 0xc0) == 0) {
      return;
    }
    if (*(int *)((long)param_3 + 0xf4) != 0) {
      return;
    }
    mutex_lock(param_3 + 0x15);
    pcVar10 = *(code **)(param_3[0x7a] + 0xc0);
joined_r0x00106f9c:
    if (pcVar10 == (code *)0x0) goto LAB_00107120;
    uVar8 = *param_3;
    uVar9 = 0;
  }
  else {
    if (((uVar3 & 0xfffffffd) == 1) && ((uVar7 & 1) == 0)) {
      if (*(char *)(param_3 + 4) == '\0') {
        return;
      }
      if (*(long *)(param_3[0x7a] + 0xb8) == 0) {
        return;
      }
      if (*(int *)((long)param_3 + 0xf4) != 0) {
        return;
      }
      mutex_lock(param_3 + 0x15);
      pcVar10 = *(code **)(param_3[0x7a] + 0xb8);
      goto joined_r0x00106f9c;
    }
    if ((uVar3 != 2) || ((uVar7 & 1) == 0)) {
      if (uVar3 != 2) {
        return;
      }
      if ((uVar7 & 1) != 0) {
        return;
      }
      if (((*(char *)(param_3 + 4) != '\0') && (*(long *)(param_3[0x7a] + 0xc0) != 0)) &&
         (*(int *)((long)param_3 + 0xf4) == 0)) {
        mutex_lock(param_3 + 0x15);
        pcVar10 = *(code **)(param_3[0x7a] + 0xc0);
        if (pcVar10 != (code *)0x0) {
          if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
            pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x107068);
            (*pcVar10)();
          }
          (*pcVar10)(*param_3,1);
        }
        mutex_unlock(param_3 + 0x15);
      }
      *(undefined4 *)(param_3 + 0x1f) = 0;
      if (*(uint *)(param_3 + 0x42) - *(int *)((long)param_3 + 0x214) <= *(uint *)(param_3 + 0x43))
      {
        *(undefined1 *)
         (param_3[0x44] + (ulong)(*(uint *)(param_3 + 0x43) & *(uint *)(param_3 + 0x42))) = 0;
        DataMemoryBarrier(2,2);
        *(int *)(param_3 + 0x42) = *(int *)(param_3 + 0x42) + 1;
      }
      queue_delayed_work_on(0x20,_system_wq,param_3 + 0x20,0);
      return;
    }
    if (((*(char *)(param_3 + 4) == '\0') || (*(long *)(param_3[0x7a] + 0xb8) == 0)) ||
       (*(int *)((long)param_3 + 0xf4) != 0)) {
      if (*(int *)(param_3 + 9) == 0) {
        return;
      }
      if (*(long *)(param_3[0x7a] + 0xa8) == 0) {
        return;
      }
      mutex_lock(param_3 + 0x15);
      pcVar10 = *(code **)(param_3[0x7a] + 0xa8);
    }
    else {
      mutex_lock(param_3 + 0x15);
      pcVar10 = *(code **)(param_3[0x7a] + 0xb8);
    }
    if (pcVar10 == (code *)0x0) goto LAB_00107120;
    uVar8 = *param_3;
    uVar9 = 1;
  }
  if (*(int *)(pcVar10 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10711c);
    (*pcVar10)();
  }
  (*pcVar10)(uVar8,uVar9);
LAB_00107120:
  mutex_unlock(param_3 + 0x15);
  return;
}



//------------------------------------------------------------
// ts_mmi_fps_cb @ 00107350 size=224
// signature: undefined ts_mmi_fps_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ts_mmi_fps_cb(long param_1,long param_2,uint *param_3)

{
  undefined *puVar1;
  uint uVar2;
  
  if (((param_1 != 0x2a0) && (param_2 == 0xbeef)) &&
     (uVar2 = *param_3, uVar2 != *(byte *)(param_1 + 0x19))) {
    puVar1 = &DAT_0010931e;
    if (uVar2 == 0) {
      puVar1 = &DAT_00108eac;
    }
    *(bool *)(param_1 + 0x19) = uVar2 != 0;
    _dev_info(*(undefined8 *)(param_1 + -0x298),"FPS: state is %s\n",puVar1);
    if (*(int *)(param_1 + -0x1ac) == 2) {
      if (*(uint *)(param_1 + -0x90) - *(int *)(param_1 + -0x8c) <= *(uint *)(param_1 + -0x88)) {
        *(undefined1 *)
         (*(long *)(param_1 + -0x80) +
         (ulong)(*(uint *)(param_1 + -0x88) & *(uint *)(param_1 + -0x90))) = 3;
        DataMemoryBarrier(2,2);
        *(int *)(param_1 + -0x90) = *(int *)(param_1 + -0x90) + 1;
      }
      queue_delayed_work_on(0x20,_system_wq,param_1 + -0x1a0,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_lpd_cb @ 00107434 size=188
// signature: undefined ts_mmi_lpd_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ts_mmi_lpd_cb(long param_1,long param_2,uint *param_3)

{
  if (((param_1 != 0x2c0) && (param_2 == 1)) && (*param_3 != (uint)*(byte *)(param_1 + 0x19))) {
    *(bool *)(param_1 + 0x19) = *param_3 != 0;
    if (*(uint *)(param_1 + -0xb0) - *(int *)(param_1 + -0xac) <= *(uint *)(param_1 + -0xa8)) {
      *(undefined1 *)
       (*(long *)(param_1 + -0xa0) +
       (ulong)(*(uint *)(param_1 + -0xa8) & *(uint *)(param_1 + -0xb0))) = 5;
      DataMemoryBarrier(2,2);
      *(int *)(param_1 + -0xb0) = *(int *)(param_1 + -0xb0) + 1;
    }
    queue_delayed_work_on(0x20,_system_wq,param_1 + -0x1c0,0);
    _dev_info(*(undefined8 *)(param_1 + -0x2b8),"LPD state is %d\n",*(undefined1 *)(param_1 + 0x19))
    ;
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_is_sensor_enable @ 001074f4 size=36
// signature: undefined ts_mmi_is_sensor_enable(void)
// callers: []
//------------------------------------------------------------

bool ts_mmi_is_sensor_enable(void)

{
  if (sensor_pdata == 0) {
    return false;
  }
  return *(int *)(sensor_pdata + 0xe8) != 0;
}



//------------------------------------------------------------
// ts_mmi_gesture_init @ 0010751c size=524
// signature: undefined ts_mmi_gesture_init(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

undefined8 ts_mmi_gesture_init(undefined8 *param_1)

{
  undefined8 *__dest;
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = (undefined8 *)input_allocate_device();
  if (puVar3 == (undefined8 *)0x0) {
    _dev_err(*param_1,"%s: Failed to allocate device","ts_mmi_gesture_init");
  }
  else {
    sensor_pdata = (undefined8 *)devm_kmalloc(*param_1,0xf8,0xdc0);
    if (sensor_pdata == (undefined8 *)0x0) {
      _dev_err(*param_1,"%s: Failed to allocate memory","ts_mmi_gesture_init");
    }
    else {
      events_data = (long *)devm_kmalloc(*param_1,8,0xdc0);
      if (events_data == (long *)0x0) {
        _dev_err(*param_1,"%s: Failed to allocate memory","ts_mmi_gesture_init");
      }
      else {
        *events_data = (long)param_1;
        puVar3[0x11] = puVar3[0x11] | 0x3c;
        puVar3[5] = puVar3[5] | 0xb;
        input_set_abs_params(puVar3,0,0,0x1000,0,0);
        input_set_abs_params(puVar3,1,0,0x1000,0,0);
        *puVar3 = "double-tap";
        *sensor_pdata = puVar3;
        iVar2 = input_register_device(puVar3);
        puVar1 = sensor_pdata;
        if (iVar2 == 0) {
          __dest = sensor_pdata + 1;
          memcpy(__dest,&sensors_touch_cdev,0xe0);
          puVar1[0x1e] = param_1;
          puVar1[0x15] = ts_mmi_sensor_set_enable;
          uVar4 = sensors_classdev_register(puVar3 + 0x48,__dest);
          if ((int)uVar4 == 0) {
            *(code **)(param_1[0x7a] + 0x198) = ts_mmi_gesture_handler;
            *(code **)(param_1[0x7a] + 0x1c0) = ts_mmi_touch_event_handler;
            return uVar4;
          }
          input_unregister_device(puVar3);
          puVar3 = (undefined8 *)0x0;
        }
        else {
          _dev_err(*param_1,"%s: Unable to register device, err=%d","ts_mmi_gesture_init",iVar2);
        }
        if (events_data != (long *)0x0) {
          devm_kfree(*param_1);
        }
      }
      if ((puVar3 == (undefined8 *)0x0) || (sensor_pdata == (undefined8 *)0x0)) {
        if (puVar3 == (undefined8 *)0x0) {
          return 1;
        }
      }
      else {
        devm_kfree(*param_1);
      }
    }
    input_free_device(puVar3);
  }
  return 1;
}



//------------------------------------------------------------
// ts_mmi_sensor_set_enable @ 0010772c size=8
// signature: undefined ts_mmi_sensor_set_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_sensor_set_enable(void)

{
  return 0;
}



//------------------------------------------------------------
// ts_mmi_gesture_handler @ 00107738 size=528
// signature: undefined ts_mmi_gesture_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_gesture_handler(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  
  puVar3 = sensor_pdata;
  lVar4 = sensor_pdata[0x1e];
  iVar1 = *(int *)(lVar4 + 100);
  if (iVar1 != 0) {
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (int)param_1[3] / iVar1;
    }
    param_1[3] = iVar2;
    iVar1 = 0;
    if (*(int *)(lVar4 + 100) != 0) {
      iVar1 = (int)param_1[4] / *(int *)(lVar4 + 100);
    }
    param_1[4] = iVar1;
  }
  switch(*param_1) {
  case 1:
    input_event(*puVar3,3,0,param_1[3]);
    input_event(*sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010a576,"ts_mmi_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c2;
    break;
  case 2:
    if (param_1[3] == 0) {
      param_1[3] = *(undefined4 *)(lVar4 + 0x3c);
    }
    if (param_1[4] == 0) {
      param_1[4] = *(undefined4 *)(lVar4 + 0x40);
    }
    input_event(*puVar3,3,0);
    input_event(*sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010985f,"ts_mmi_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c3;
    break;
  case 3:
    _printk(&DAT_00108f67,"ts_mmi_gesture_handler");
    uVar5 = 0x2c4;
    break;
  case 4:
    input_event(*puVar3,3,0,param_1[3]);
    input_event(*sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010a063,"ts_mmi_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c5;
    break;
  default:
    _printk(&DAT_00108eb0,"ts_mmi_gesture_handler");
    return 1;
  }
  input_event(*sensor_pdata,1,uVar5,1);
  input_event(*sensor_pdata,0,0,0);
  input_event(*sensor_pdata,1,uVar5,0);
  input_event(*sensor_pdata,0,0,0);
  return 0;
}



//------------------------------------------------------------
// ts_mmi_touch_event_handler @ 0010794c size=192
// signature: undefined ts_mmi_touch_event_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_touch_event_handler(long param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 *puVar4;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((1 < uVar1) && (uVar1 != 3)) {
    if (uVar1 == 2) {
      puVar4 = (undefined8 *)*events_data;
      if ((*(char *)((long)puVar4 + 0x21) != '\0') && (*(char *)((long)puVar4 + 0x2ba) != '\0')) {
        iVar2 = mutex_trylock(puVar4 + 0x15);
        if (iVar2 != 0) {
          pcVar3 = *(code **)(puVar4[0x7a] + 0x128);
          if (pcVar3 != (code *)0x0) {
            if (*(int *)(pcVar3 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1079d0);
              (*pcVar3)();
            }
            (*pcVar3)(*puVar4,1);
          }
          *(undefined1 *)((long)puVar4 + 0x2ba) = 0;
          mutex_unlock(puVar4 + 0x15);
        }
      }
    }
    else {
      _printk(&DAT_00108e1d,"ts_mmi_touch_event_handler");
    }
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_gesture_remove @ 00107a10 size=132
// signature: undefined ts_mmi_gesture_remove(void)
// callers: [ts_mmi_dev_unregister]
//------------------------------------------------------------

undefined8 ts_mmi_gesture_remove(undefined8 *param_1)

{
  long *plVar1;
  
  sensors_classdev_unregister(sensor_pdata + 1);
  plVar1 = sensor_pdata;
  if (*sensor_pdata != 0) {
    input_unregister_device();
    input_free_device(*sensor_pdata);
    plVar1 = sensor_pdata;
    *sensor_pdata = 0;
  }
  if (plVar1 != (long *)0x0) {
    devm_kfree(*param_1);
    sensor_pdata = (long *)0x0;
  }
  if (events_data != 0) {
    devm_kfree(*param_1);
    events_data = 0;
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_cli_gesture_init @ 00107a98 size=400
// signature: undefined ts_mmi_cli_gesture_init(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

undefined8 ts_mmi_cli_gesture_init(undefined8 *param_1)

{
  undefined8 *__dest;
  undefined8 *puVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar3 = (undefined8 *)input_allocate_device();
  if (puVar3 == (undefined8 *)0x0) {
    _dev_err(*param_1,"%s: Failed to allocate input device","ts_mmi_cli_gesture_init");
  }
  else {
    cli_sensor_pdata = (undefined8 *)devm_kmalloc(*param_1,0xf8,0xdc0);
    if (cli_sensor_pdata == (undefined8 *)0x0) {
      _dev_err(*param_1,"%s: Failed to allocate memory","ts_mmi_cli_gesture_init");
    }
    else {
      puVar3[0x11] = puVar3[0x11] | 0x3c;
      puVar3[5] = puVar3[5] | 0xb;
      input_set_abs_params(puVar3,0,0,0x1000,0,0);
      input_set_abs_params(puVar3,1,0,0x1000,0,0);
      *puVar3 = "s-double-tap";
      *cli_sensor_pdata = puVar3;
      iVar2 = input_register_device(puVar3);
      puVar1 = cli_sensor_pdata;
      if (iVar2 == 0) {
        __dest = cli_sensor_pdata + 1;
        memcpy(__dest,cli_sensors_touch_cdev,0xe0);
        puVar1[0x1e] = param_1;
        puVar1[0x15] = ts_mmi_sensor_set_enable;
        uVar4 = sensors_classdev_register(puVar3 + 0x48,__dest);
        if ((int)uVar4 == 0) {
          *(code **)(param_1[0x7a] + 0x198) = ts_mmi_cli_gesture_handler;
          return uVar4;
        }
        input_unregister_device(puVar3);
        return 1;
      }
      _dev_err(*param_1,"%s: Unable to register device, err=%d","ts_mmi_cli_gesture_init",iVar2);
      if (cli_sensor_pdata != (undefined8 *)0x0) {
        devm_kfree(*param_1);
      }
    }
    input_free_device(puVar3);
  }
  return 1;
}



//------------------------------------------------------------
// ts_mmi_cli_gesture_handler @ 00107c2c size=528
// signature: undefined ts_mmi_cli_gesture_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_cli_gesture_handler(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  undefined8 uVar5;
  
  puVar3 = cli_sensor_pdata;
  lVar4 = cli_sensor_pdata[0x1e];
  iVar1 = *(int *)(lVar4 + 100);
  if (iVar1 != 0) {
    iVar2 = 0;
    if (iVar1 != 0) {
      iVar2 = (int)param_1[3] / iVar1;
    }
    param_1[3] = iVar2;
    iVar1 = 0;
    if (*(int *)(lVar4 + 100) != 0) {
      iVar1 = (int)param_1[4] / *(int *)(lVar4 + 100);
    }
    param_1[4] = iVar1;
  }
  switch(*param_1) {
  case 1:
    input_event(*puVar3,3,0,param_1[3]);
    input_event(*cli_sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010a576,"ts_mmi_cli_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c2;
    break;
  case 2:
    if (param_1[3] == 0) {
      param_1[3] = *(undefined4 *)(lVar4 + 0x3c);
    }
    if (param_1[4] == 0) {
      param_1[4] = *(undefined4 *)(lVar4 + 0x40);
    }
    input_event(*puVar3,3,0);
    input_event(*cli_sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010985f,"ts_mmi_cli_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c3;
    break;
  case 3:
    _printk(&DAT_00108f67,"ts_mmi_cli_gesture_handler");
    uVar5 = 0x2c4;
    break;
  case 4:
    input_event(*puVar3,3,0,param_1[3]);
    input_event(*cli_sensor_pdata,3,1,param_1[4]);
    _printk(&DAT_0010a063,"ts_mmi_cli_gesture_handler",param_1[3],param_1[4]);
    uVar5 = 0x2c5;
    break;
  default:
    _printk(&DAT_00108eb0,"ts_mmi_cli_gesture_handler");
    return 1;
  }
  input_event(*cli_sensor_pdata,1,uVar5,1);
  input_event(*cli_sensor_pdata,0,0,0);
  input_event(*cli_sensor_pdata,1,uVar5,0);
  input_event(*cli_sensor_pdata,0,0,0);
  return 0;
}



//------------------------------------------------------------
// ts_mmi_cli_gesture_remove @ 00107e40 size=108
// signature: undefined ts_mmi_cli_gesture_remove(void)
// callers: [ts_mmi_dev_unregister]
//------------------------------------------------------------

undefined8 ts_mmi_cli_gesture_remove(undefined8 *param_1)

{
  long *plVar1;
  
  sensors_classdev_unregister(cli_sensor_pdata + 1);
  plVar1 = cli_sensor_pdata;
  if (*cli_sensor_pdata != 0) {
    input_unregister_device();
    input_free_device(*cli_sensor_pdata);
    plVar1 = cli_sensor_pdata;
    *cli_sensor_pdata = 0;
  }
  if (plVar1 != (long *)0x0) {
    devm_kfree(*param_1);
    cli_sensor_pdata = (long *)0x0;
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_palm_init @ 00107eb0 size=372
// signature: undefined ts_mmi_palm_init(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

undefined8 ts_mmi_palm_init(undefined8 *param_1)

{
  undefined8 *puVar1;
  undefined8 *__dest;
  undefined8 *puVar2;
  int iVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  
  puVar4 = (undefined8 *)input_allocate_device();
  if (puVar4 == (undefined8 *)0x0) {
    _dev_err(*param_1,"%s: Failed to allocate device","ts_mmi_palm_init");
  }
  else {
    puVar1 = puVar4 + 0x48;
    palm_sensor_pdata = (undefined8 *)devm_kmalloc(puVar1,0xf8,0xdc0);
    if (palm_sensor_pdata == (undefined8 *)0x0) {
      _dev_err(*param_1,"%s: Failed to allocate memory","ts_mmi_palm_init");
    }
    else {
      puVar4[5] = puVar4[5] | 9;
      input_set_abs_params(puVar4,0x19,0,5,0,0);
      *puVar4 = "palm_detect";
      *palm_sensor_pdata = puVar4;
      iVar3 = input_register_device(puVar4);
      puVar2 = palm_sensor_pdata;
      if (iVar3 == 0) {
        __dest = palm_sensor_pdata + 1;
        memcpy(__dest,palm_sensors_touch_cdev,0xe0);
        puVar2[0x1e] = param_1;
        puVar2[0x15] = ts_mmi_palm_set_enable;
        uVar5 = sensors_classdev_register(puVar1,__dest);
        if ((int)uVar5 == 0) {
          *(code **)(param_1[0x7a] + 0x1a8) = ts_mmi_palm_handler;
          return uVar5;
        }
        input_unregister_device(puVar4);
      }
      else {
        _dev_err(*param_1,"Unable to register device, err=%d",iVar3);
      }
      input_free_device(puVar4);
    }
    devm_kfree(puVar1,palm_sensor_pdata);
    palm_sensor_pdata = (undefined8 *)0x0;
  }
  return 1;
}



//------------------------------------------------------------
// ts_mmi_palm_set_enable @ 00108028 size=240
// signature: undefined ts_mmi_palm_set_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_palm_set_enable(long param_1,int param_2)

{
  byte bVar1;
  undefined8 uVar2;
  char *pcVar3;
  code *pcVar4;
  undefined8 *puVar5;
  
  puVar5 = *(undefined8 **)(param_1 + 0xe8);
  mutex_lock(puVar5 + 0xf);
  mutex_lock(puVar5 + 0x15);
  pcVar4 = *(code **)(puVar5[0x7a] + 0xd8);
  if (pcVar4 != (code *)0x0) {
    if (*(int *)(pcVar4 + -4) != 0x9da156b) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x108088);
      (*pcVar4)();
    }
    (*pcVar4)(*puVar5,param_2);
  }
  mutex_unlock(puVar5 + 0x15);
  if (param_2 == 0) {
    pcVar3 = "%s: sensor DISABLE\n";
    uVar2 = *puVar5;
    bVar1 = *(byte *)(puVar5 + 3) & 0xf7;
  }
  else {
    if (param_2 != 1) {
      _dev_err(*puVar5,"%s: unknown enable symbol\n","ts_mmi_palm_set_enable");
      goto LAB_001080f8;
    }
    pcVar3 = "%s: sensor ENABLE\n";
    uVar2 = *puVar5;
    bVar1 = *(byte *)(puVar5 + 3) | 8;
  }
  *(byte *)(puVar5 + 3) = bVar1;
  _dev_info(uVar2,pcVar3,"ts_mmi_palm_set_enable");
LAB_001080f8:
  mutex_unlock(puVar5 + 0xf);
  return 0;
}



//------------------------------------------------------------
// ts_mmi_palm_handler @ 0010811c size=136
// signature: undefined ts_mmi_palm_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 ts_mmi_palm_handler(uint param_1)

{
  undefined *puVar1;
  
  if (*palm_sensor_pdata != 0) {
    puVar1 = &UNK_0010a4cb;
    if ((param_1 & 1) == 0) {
      puVar1 = &DAT_0010a47a;
    }
    input_event(*palm_sensor_pdata,3,0x19,param_1 & 1);
    _printk(puVar1,"ts_mmi_palm_handler");
    input_event(*palm_sensor_pdata,0,0,0);
  }
  return 0;
}



//------------------------------------------------------------
// ts_mmi_palm_remove @ 001081a8 size=84
// signature: undefined ts_mmi_palm_remove(void)
// callers: [ts_mmi_dev_unregister]
//------------------------------------------------------------

undefined8 ts_mmi_palm_remove(void)

{
  sensors_classdev_unregister(palm_sensor_pdata + 1);
  input_unregister_device(*palm_sensor_pdata);
  devm_kfree(*palm_sensor_pdata + 0x240);
  palm_sensor_pdata = (long *)0x0;
  return 0;
}



//------------------------------------------------------------
// init_module @ 00108244 size=152
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  ulong uVar1;
  undefined *puVar2;
  ulong uVar3;
  
  _printk(&DAT_00109726);
  if (touchscreens_class == 0) {
    uVar1 = __class_create(&__this_module,"touchscreen",&touchscreens_init___key);
    if (uVar1 < 0xfffffffffffff001) {
      uVar3 = 0;
      puVar2 = &DAT_00109409;
      touchscreens_class = uVar1;
    }
    else {
      puVar2 = &DAT_001093d6;
      touchscreens_class = 0;
      uVar3 = uVar1;
    }
  }
  else {
    uVar3 = 0;
    puVar2 = &DAT_00109dd9;
  }
  _printk(puVar2);
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// cleanup_module @ 001082e0 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  if (touchscreens_class != 0) {
    class_destroy();
  }
  return;
}



//------------------------------------------------------------
// devm_kmalloc @ 0010d000 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ts_mmi_dev_register, ts_mmi_gesture_init, ts_mmi_cli_gesture_init, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010d008 size=1
// signature: undefined _dev_info(void)
// callers: [ts_mmi_dev_register, ts_mmi_panel_unregister, ts_mmi_panel_register, ts_mmi_default_pinctrl, ts_mmi_parse_dt, ts_mmi_palm_set_enable, ts_mmi_lpd_notifier_register, gesture_store, report_liquid_detection_status_handler, ts_mmi_doreflash_store, liquid_detection_ctl_store, ts_mmi_fps_cb, ts_mmi_check_drm_panel, ts_mmi_notifiers_register, ts_mmi_fps_notifier_register, ts_mmi_notifiers_unregister, ts_mmi_lpd_cb, ts_mmi_worker_func, ts_mmi_panel_cb, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010d010 size=1
// signature: undefined __mutex_init(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010d018 size=1
// signature: undefined _dev_err(void)
// callers: [flashprog_show, active_region_store, hold_distance_show, productinfo_show, ts_mmi_cli_gesture_init, liquid_detection_ctl_store, suppression_store, active_region_show, pwr_store, ts_mmi_forcereflash_store, drv_irq_show, gs_distance_show, build_id_show, suppression_show, hold_grip_store, ts_mmi_lpd_notifier_register, update_baseline_store, vendor_show, refresh_rate_store, pinctrl_store, reset_store, gs_distance_store, irq_status_show, ts_mmi_gesture_init, ts_mmi_sysfs_create_edge_entries, ts_mmi_worker_func, ts_mmi_panel_cb, ts_mmi_dev_unregister, ts_mmi_ps_worker_func, ts_mmi_hw_irqstat_show, gesture_store, report_liquid_detection_status_handler, hold_distance_store, poweron_show, ts_mmi_notifiers_register, ts_mmi_fps_notifier_register, charger_mode_store, pill_region_show, ts_mmi_dev_register, ts_mmi_panel_unregister, drv_irq_store, path_show, ts_mmi_parse_dt, pill_region_store, ts_mmi_palm_set_enable, config_id_show, ts_mmi_doreflash_store, hold_grip_show, ts_mmi_notifiers_unregister, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 0010d020 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 0010d028 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 0010d030 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [ts_mmi_dev_register, ts_mmi_default_pinctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0010d038 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0010d040 size=1
// signature: undefined device_create(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 0010d048 size=1
// signature: undefined down_write(void)
// callers: [ts_mmi_dev_register, get_class_fname_handler, ts_mmi_clip_event_handler, get_gesture_type_handler, ts_mmi_default_pinctrl, get_supplier_handler, report_liquid_detection_status_handler, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010d050 size=1
// signature: undefined __list_add_valid(void)
// callers: [ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0010d058 size=1
// signature: undefined up_write(void)
// callers: [ts_mmi_dev_register, get_class_fname_handler, ts_mmi_clip_event_handler, get_gesture_type_handler, ts_mmi_default_pinctrl, get_supplier_handler, report_liquid_detection_status_handler, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010d060 size=1
// signature: undefined sysfs_create_group(void)
// callers: [ts_mmi_dev_register, ts_mmi_panel_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 0010d068 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [ts_mmi_dev_register, ts_mmi_panel_unregister, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010d070 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 0010d078 size=1
// signature: undefined device_unregister(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0010d080 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [ts_mmi_dev_register, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010d088 size=1
// signature: undefined devm_kfree(void)
// callers: [ts_mmi_dev_register, ts_mmi_palm_remove, ts_mmi_gesture_init, ts_mmi_gesture_remove, ts_mmi_cli_gesture_init, ts_mmi_palm_init, ts_mmi_cli_gesture_remove, ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010d090 size=1
// signature: undefined mutex_lock(void)
// callers: [flashprog_show, active_region_store, hold_distance_show, ts_mmi_ps_worker_func, productinfo_show, gesture_store, ts_mmi_get_vendor_info, liquid_detection_ctl_store, hold_distance_store, poweron_show, suppression_store, active_region_show, pwr_store, charger_mode_store, pill_region_show, drv_irq_show, drv_irq_store, gs_distance_show, build_id_show, suppression_show, hold_grip_store, pill_region_store, ts_mmi_palm_set_enable, update_baseline_store, vendor_show, config_id_show, refresh_rate_store, pinctrl_store, reset_store, gs_distance_store, ts_mmi_doreflash_store, irq_status_show, ts_mmi_sysfs_create_edge_entries, hold_grip_show, ts_mmi_worker_func, ts_mmi_panel_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010d098 size=1
// signature: undefined mutex_unlock(void)
// callers: [flashprog_show, active_region_store, hold_distance_show, ts_mmi_ps_worker_func, productinfo_show, ts_mmi_touch_event_handler, gesture_store, ts_mmi_get_vendor_info, liquid_detection_ctl_store, hold_distance_store, poweron_show, suppression_store, active_region_show, pwr_store, charger_mode_store, pill_region_show, drv_irq_show, drv_irq_store, gs_distance_show, build_id_show, suppression_show, hold_grip_store, pill_region_store, ts_mmi_palm_set_enable, update_baseline_store, vendor_show, config_id_show, refresh_rate_store, pinctrl_store, reset_store, gs_distance_store, ts_mmi_doreflash_store, irq_status_show, ts_mmi_sysfs_create_edge_entries, hold_grip_show, ts_mmi_worker_func, ts_mmi_panel_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_notifier_fire @ 0010d0a0 size=1
// signature: undefined relay_notifier_fire(void)
// callers: [report_liquid_detection_status_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_notifier_fire(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010d0a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [drv_irq_store, active_region_store, ts_mmi_ps_worker_func, hold_grip_store, ts_mmi_parse_dt, pill_region_store, update_baseline_store, refresh_rate_store, pinctrl_store, gesture_store, ts_mmi_ps_get_state, reset_store, gs_distance_store, report_liquid_detection_status_handler, ts_mmi_doreflash_store, liquid_detection_ctl_store, hold_distance_store, ts_mmi_check_drm_panel, suppression_store, ts_mmi_notifiers_register, pwr_store, ts_mmi_forcereflash_store, charger_mode_store, ts_mmi_is_panel_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0010d0b0 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [ts_mmi_sysfs_create_edge_entries]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 0010d0b8 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [ts_mmi_sysfs_create_edge_entries]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 0010d0c0 size=1
// signature: undefined input_event(void)
// callers: [ts_mmi_clip_event_handler, ts_mmi_gesture_handler, ts_mmi_palm_handler, ts_mmi_cli_gesture_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_mt_report_slot_state @ 0010d0c8 size=1
// signature: undefined input_mt_report_slot_state(void)
// callers: [ts_mmi_clip_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_mt_report_slot_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0010d0d0 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [ts_mmi_is_panel_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010d0d8 size=1
// signature: undefined of_property_read_string(void)
// callers: [ts_mmi_parse_dt, ts_mmi_is_panel_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 0010d0e0 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [ts_mmi_is_panel_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010d0e8 size=1
// signature: undefined _printk(void)
// callers: [ts_mmi_gesture_handler, ts_mmi_touch_event_handler, ts_mmi_is_panel_match, init_module, ts_mmi_palm_handler, ts_mmi_cli_gesture_handler, ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0010d0f0 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0010d0f8 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010d100 size=1
// signature: size_t strlen(char * __s)
// callers: [path_show, ts_mmi_parse_dt, ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010d108 size=1
// signature: undefined __kmalloc(void)
// callers: [path_show, ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010d110 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [ts_mmi_gesture_init, path_show, ts_mmi_parse_dt, ts_mmi_cli_gesture_init, ts_mmi_doreflash_store, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010d118 size=1
// signature: undefined scnprintf(void)
// callers: [flashprog_show, hold_distance_show, gs_distance_show, build_id_show, gesture_show, productinfo_show, suppression_show, path_show, liquid_detection_ctl_show, vendor_show, config_id_show, ts_mmi_hw_irqstat_show, irq_status_show, poweron_show, ts_mmi_buildid_show, ts_mmi_panel_supplier_show, hold_grip_show, active_region_show, ts_mmi_ic_ver_show, pill_region_show, drv_irq_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010d120 size=1
// signature: undefined kfree(void)
// callers: [path_show, ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010d128 size=1
// signature: undefined kstrtoull(void)
// callers: [drv_irq_store, suppression_store, hold_grip_store, update_baseline_store, pwr_store, refresh_rate_store, ts_mmi_forcereflash_store, pinctrl_store, reset_store, charger_mode_store, gs_distance_store, hold_distance_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010d130 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [ts_mmi_parse_dt, ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 0010d138 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [ts_mmi_ps_worker_func, ts_mmi_parse_dt, ts_mmi_charger_cb, ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010d140 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0010d148 size=1
// signature: undefined strnstr(void)
// callers: [ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010d150 size=1
// signature: undefined fortify_panic(void)
// callers: [ts_mmi_parse_dt, ts_mmi_doreflash_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0010d158 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [active_region_store, pill_region_store, gesture_store, liquid_detection_ctl_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0010d168 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [ts_mmi_notifiers_register, ts_mmi_charger_cb, ts_mmi_lpd_cb, ts_mmi_refresh_rate_cb, ts_mmi_worker_func, liquid_detection_ctl_store, ts_mmi_panel_cb, ts_mmi_fps_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010d170 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [ts_mmi_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010d178 size=1
// signature: undefined of_find_property(void)
// callers: [ts_mmi_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_by_name @ 0010d180 size=1
// signature: undefined of_find_node_by_name(void)
// callers: [ts_mmi_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u64 @ 0010d188 size=1
// signature: undefined of_property_read_u64(void)
// callers: [ts_mmi_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 0010d190 size=1
// signature: undefined of_get_next_child(void)
// callers: [ts_mmi_parse_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_count_phandle_with_args @ 0010d198 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010d1a0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_drm_find_panel @ 0010d1a8 size=1
// signature: undefined of_drm_find_panel(void)
// callers: [ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_drm_find_panel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010d1b0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 0010d1b8 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [ts_mmi_check_drm_panel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0010d1c8 size=1
// signature: undefined init_timer_key(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kfifo_alloc @ 0010d1d0 size=1
// signature: undefined __kfifo_alloc(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 0010d1d8 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 0010d1e0 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [ts_mmi_notifiers_register, ts_mmi_notifiers_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kfifo_free @ 0010d1e8 size=1
// signature: undefined __kfifo_free(void)
// callers: [ts_mmi_notifiers_register, ts_mmi_notifiers_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 0010d1f0 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 0010d1f8 size=1
// signature: undefined power_supply_put(void)
// callers: [ts_mmi_notifiers_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010d208 size=1
// signature: undefined ___ratelimit(void)
// callers: [ts_mmi_worker_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_register @ 0010d210 size=1
// signature: undefined panel_event_notifier_register(void)
// callers: [ts_mmi_worker_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 0010d218 size=1
// signature: undefined power_supply_get_property(void)
// callers: [ts_mmi_ps_worker_func, ts_mmi_ps_get_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_register_action @ 0010d220 size=1
// signature: undefined relay_register_action(void)
// callers: [ts_mmi_fps_notifier_register, ts_mmi_lpd_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_register_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// relay_unregister_action @ 0010d228 size=1
// signature: undefined relay_unregister_action(void)
// callers: [ts_mmi_fps_notifier_register, ts_mmi_notifiers_unregister, ts_mmi_lpd_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void relay_unregister_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 0010d230 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [ts_mmi_notifiers_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panel_event_notifier_unregister @ 0010d238 size=1
// signature: undefined panel_event_notifier_unregister(void)
// callers: [ts_mmi_notifiers_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panel_event_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0010d240 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [ts_mmi_panel_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 0010d248 size=1
// signature: undefined input_allocate_device(void)
// callers: [ts_mmi_gesture_init, ts_mmi_cli_gesture_init, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_abs_params @ 0010d250 size=1
// signature: undefined input_set_abs_params(void)
// callers: [ts_mmi_gesture_init, ts_mmi_cli_gesture_init, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_abs_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 0010d258 size=1
// signature: undefined input_register_device(void)
// callers: [ts_mmi_gesture_init, ts_mmi_cli_gesture_init, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_register @ 0010d260 size=1
// signature: undefined sensors_classdev_register(void)
// callers: [ts_mmi_gesture_init, ts_mmi_cli_gesture_init, ts_mmi_palm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 0010d268 size=1
// signature: undefined input_unregister_device(void)
// callers: [ts_mmi_palm_remove, ts_mmi_gesture_init, ts_mmi_gesture_remove, ts_mmi_cli_gesture_init, ts_mmi_palm_init, ts_mmi_cli_gesture_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_free_device @ 0010d270 size=1
// signature: undefined input_free_device(void)
// callers: [ts_mmi_gesture_init, ts_mmi_gesture_remove, ts_mmi_cli_gesture_init, ts_mmi_palm_init, ts_mmi_cli_gesture_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_free_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_trylock @ 0010d278 size=1
// signature: undefined mutex_trylock(void)
// callers: [ts_mmi_touch_event_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_unregister @ 0010d280 size=1
// signature: undefined sensors_classdev_unregister(void)
// callers: [ts_mmi_palm_remove, ts_mmi_gesture_remove, ts_mmi_cli_gesture_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



