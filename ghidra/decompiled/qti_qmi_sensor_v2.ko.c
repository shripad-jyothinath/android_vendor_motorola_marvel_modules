// Decompiled by Ghidra 12.2
// Program: qti_qmi_sensor_v2.ko
// Image base: 00100000

//------------------------------------------------------------
// qmi_ts_ind_cb_v02 @ 001003ac size=240
// signature: undefined qmi_ts_ind_cb_v02(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_ts_ind_cb_v02(long param_1,undefined8 param_2,long param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  long *plVar4;
  bool bVar5;
  
  if (param_3 == 0) {
    puVar3 = &DAT_00102aaf;
  }
  else {
    if ((*(int *)(param_4 + 0x24) == 0) && (param_4[0x30] == '\0')) {
      bVar5 = true;
      cVar1 = param_4[0x28];
    }
    else {
      bVar5 = false;
      cVar1 = param_4[0x28];
    }
    if (cVar1 != '\0') {
      plVar4 = (long *)(param_1 + 0x180);
      do {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(param_1 + 0x180)) {
          return;
        }
        iVar2 = strncasecmp((char *)(plVar4 + -6),param_4,0x20);
      } while (iVar2 != 0);
      iVar2 = *(int *)(param_4 + 0x2c);
      if (plVar4[2] == 0) {
        bVar5 = true;
      }
      *(int *)(plVar4 + 3) = iVar2;
      if (bVar5) {
        return;
      }
      if ((iVar2 < *(int *)((long)plVar4 + 0x1c)) && (*(int *)(plVar4 + 4) < iVar2)) {
        return;
      }
      queue_work_on(0x20,_system_highpri_wq,plVar4 + 7);
      return;
    }
    puVar3 = &DAT_00102a85;
  }
  _printk(puVar3,"qti_qmi_sensor_v2","qmi_ts_ind_cb_v02");
  return;
}



//------------------------------------------------------------
// qmi_sens_device_probe @ 001004a0 size=1196
// signature: undefined qmi_sens_device_probe(void)
// callers: []
//------------------------------------------------------------

int qmi_sens_device_probe(long param_1)

{
  uint uVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  undefined1 auVar5 [16];
  int iVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  undefined8 uVar13;
  uint uVar14;
  long lVar15;
  int iVar16;
  long *plVar17;
  char *pcVar18;
  char *local_70;
  long local_68;
  
  lVar8 = sp_el0;
  lVar2 = param_1 + 0x10;
  local_68 = *(long *)(lVar8 + 0x638);
  uVar13 = *(undefined8 *)(param_1 + 0x2f8);
  lVar8 = of_get_next_available_child(uVar13,0);
  if (lVar8 == 0) {
LAB_00100858:
    _dev_err(lVar2,"No child node to process\n");
    iVar6 = -0xe;
  }
  else {
    uVar1 = 0;
    do {
      uVar14 = uVar1;
      uVar1 = uVar14 + 1;
      lVar8 = of_get_next_available_child(uVar13,lVar8);
    } while (lVar8 != 0);
    if (uVar1 == 0) goto LAB_00100858;
    auVar5._8_8_ = 0;
    auVar5._0_8_ = (long)(int)uVar1;
    if ((SUB168(auVar5 * ZEXT816(0x1c8),8) == 0) &&
       (lVar8 = devm_kmalloc(lVar2,(long)(int)uVar1 * 0x1c8,0xdc0), lVar8 != 0)) {
      lVar9 = of_get_next_available_child(uVar13,0);
      if ((lVar9 != 0) && (uVar14 < 0x7fffffff)) {
        lVar12 = 0;
        do {
          plVar17 = (long *)(lVar8 + lVar12 * 0x1c8);
          iVar6 = of_property_read_variable_u32_array(lVar9,"qcom,instance-id",plVar17 + 0x30,1,0);
          if (iVar6 < 0) {
            _dev_err(lVar2,"error reading qcom,insance-id. ret:%d\n",iVar6);
            goto LAB_00100874;
          }
          lVar15 = lVar8 + lVar12 * 0x1c8;
          *plVar17 = lVar2;
          __mutex_init(lVar15 + 0x150,"&ts[idx].mutex",&of_get_qmi_ts_platform_data___key);
          plVar3 = (long *)(lVar15 + 0x188);
          *(long **)(lVar15 + 0x188) = plVar3;
          *(long **)(lVar15 + 400) = plVar3;
          *(undefined8 *)(lVar15 + 0x198) = 0xfffffffe0;
          *(long *)(lVar15 + 0x1a0) = lVar15 + 0x1a0;
          *(long *)(lVar15 + 0x1a8) = lVar15 + 0x1a0;
          *(code **)(lVar15 + 0x1b0) = qmi_ts_svc_arrive;
          iVar6 = of_property_read_string_helper(lVar9,"qcom,qmi-sensor-names",0,0,0);
          if (iVar6 < 1) {
            _dev_err(lVar2,"Invalid or no sensor. err:%d\n",iVar6);
LAB_00100850:
            iVar6 = -0x16;
            goto LAB_00100874;
          }
          iVar16 = 0;
          do {
            local_70 = (char *)0x0;
            plVar10 = (long *)devm_kmalloc(lVar2,0xa0,0xdc0);
            if (plVar10 == (long *)0x0) goto LAB_00100834;
            of_property_read_string_helper(lVar9,"qcom,qmi-sensor-names",&local_70,1,iVar16);
            pcVar18 = local_70;
            uVar11 = strnlen(local_70,0x28);
            if (uVar11 == 0xffffffffffffffff) {
              fortify_panic("strnlen");
LAB_0010093c:
              fortify_panic("strscpy");
              goto LAB_00100948;
            }
            if (uVar11 != 0x28) {
              uVar11 = uVar11 + 1;
            }
            if (0x28 < uVar11) goto LAB_0010093c;
            plVar4 = plVar10 + 1;
            strscpy(plVar4,pcVar18);
            lVar15 = 0;
            pcVar18 = &sensor_clients;
            while (iVar7 = strcmp(pcVar18,(char *)plVar4), iVar7 != 0) {
              lVar15 = lVar15 + 1;
              pcVar18 = pcVar18 + 0x28;
              if (lVar15 == 0x56) {
                _dev_err(lVar2,"Unknown sensor:%s\n",plVar4);
                goto LAB_00100850;
              }
            }
            *(int *)(plVar10 + 0xd) = (int)lVar15;
            plVar4 = plVar10 + 7;
            plVar10[0xc] = (long)plVar17;
            *(undefined4 *)(plVar10 + 0xb) = 0x80000001;
            *plVar10 = lVar2;
            plVar10[10] = 0x7fffffff00000000;
            plVar10[0xe] = 0xfffffffe0;
            plVar10[0xf] = (long)(plVar10 + 0xf);
            plVar10[0x10] = (long)(plVar10 + 0xf);
            lVar15 = *plVar3;
            plVar10[0x11] = (long)qmi_ts_thresh_notify;
            uVar11 = __list_add_valid(plVar4,plVar3,lVar15);
            if ((uVar11 & 1) != 0) {
              *(long **)(lVar15 + 8) = plVar4;
              plVar10[7] = lVar15;
              plVar10[8] = (long)plVar3;
              *plVar3 = (long)plVar4;
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 != iVar6);
          lVar9 = of_get_next_available_child(uVar13,lVar9);
        } while ((lVar9 != 0) && (lVar12 = lVar12 + 1, lVar12 < (int)uVar1));
      }
      ts_instances = lVar8;
      ts_inst_cnt = uVar1;
      if (uVar14 < 0x7fffffff) {
        lVar8 = 0;
        lVar9 = 0x188;
        do {
          lVar12 = ts_instances;
          plVar17 = (long *)(ts_instances + lVar9);
          if (plVar17 == (long *)*plVar17) {
            iVar6 = -0x13;
            goto LAB_00100874;
          }
          iVar6 = qmi_handle_init(plVar17 + -0x30,0xc6b,&thermal_qmi_event_ops,handlers);
          if (iVar6 < 0) {
            _dev_err(lVar2,"QMI[0x%x] handle init failed. err:%d\n",
                     *(undefined4 *)(lVar12 + lVar9 + -8),iVar6);
            iVar6 = -0x205;
            ts_inst_cnt = (uint)lVar8;
            goto LAB_00100874;
          }
          lVar12 = lVar12 + lVar9;
          iVar6 = qmi_add_lookup(plVar17 + -0x30,0x17,2,*(undefined4 *)(lVar12 + -8));
          if (iVar6 < 0) {
            _dev_err(lVar2,"QMI register failed for 0x%x, ret:%d\n",*(undefined4 *)(lVar12 + -8),
                     iVar6);
            iVar6 = -0x205;
            goto LAB_00100874;
          }
          lVar8 = lVar8 + 1;
          lVar9 = lVar9 + 0x1c8;
        } while (lVar8 < (int)ts_inst_cnt);
      }
      in_suspend = 0;
      register_pm_notifier(&qmi_sensor_pm_nb);
      iVar6 = 0;
      goto LAB_00100878;
    }
LAB_00100834:
    iVar6 = -0xc;
  }
LAB_00100874:
  qmi_ts_cleanup();
LAB_00100878:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) == local_68) {
    return iVar6;
  }
LAB_00100948:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// qmi_sens_device_remove @ 00100950 size=44
// signature: undefined qmi_sens_device_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_sens_device_remove(void)

{
  qmi_ts_cleanup();
  unregister_pm_notifier(&qmi_sensor_pm_nb);
  return 0;
}



//------------------------------------------------------------
// qmi_ts_cleanup @ 0010097c size=296
// signature: undefined qmi_ts_cleanup(void)
// callers: [qmi_sens_device_probe, qmi_sens_device_remove]
//------------------------------------------------------------

void qmi_ts_cleanup(void)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  
  if (0 < ts_inst_cnt) {
    lVar7 = 0;
    do {
      lVar3 = ts_instances;
      lVar5 = ts_instances + lVar7 * 0x1c8;
      mutex_lock(lVar5 + 0x150);
      plVar2 = *(long **)(lVar5 + 0x188);
      while (plVar2 != (long *)(lVar5 + 0x188)) {
        lVar6 = plVar2[2];
        *(undefined1 *)(plVar2 + -1) = 0;
        plVar8 = (long *)*plVar2;
        if (lVar6 != 0) {
          if (*(long *)(lVar6 + 0x440) != 0) {
            mutex_lock(lVar6 + 0x480);
            *(undefined8 *)(*(long *)(lVar6 + 0x440) + 0x20) = 0;
            mutex_unlock(lVar6 + 0x480);
          }
          plVar2[2] = 0;
        }
        uVar4 = __list_del_entry_valid(plVar2);
        if ((uVar4 & 1) != 0) {
          lVar6 = *plVar2;
          plVar1 = (long *)plVar2[1];
          *(long **)(lVar6 + 8) = plVar1;
          *plVar1 = lVar6;
        }
        *plVar2 = -0x2152ffffffffff00;
        plVar2[1] = -0x2152fffffffffede;
        plVar2 = plVar8;
      }
      qmi_handle_release(lVar3 + lVar7 * 0x1c8 + 8);
      mutex_unlock(lVar5 + 0x150);
      lVar7 = lVar7 + 1;
    } while (lVar7 < ts_inst_cnt);
  }
  ts_inst_cnt = 0;
  return;
}



//------------------------------------------------------------
// qmi_ts_svc_arrive @ 00100aa8 size=792
// signature: undefined qmi_ts_svc_arrive(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_ts_svc_arrive(long param_1)

{
  int iVar1;
  void *__s;
  ulong uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  long lVar6;
  long *plVar7;
  undefined8 local_80;
  undefined1 local_78 [8];
  uint local_70 [2];
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70[0] = 0;
  local_80 = 0;
  local_78[0] = 0;
  __s = (void *)kmalloc_trace(_DAT_00104138,0xdc0,0xc6c);
  if (__s != (void *)0x0) {
    iVar1 = qmi_ts_send_request(param_1 + -0x198,0x30,0,&ts_get_total_num_of_sensors_req_msg_v02_ei,
                                &ts_get_total_num_of_sensors_resp_msg_v02_ei,local_78,&local_80,
                                &local_80);
    if (iVar1 < 0) {
      _printk(&DAT_00102824,"qti_qmi_sensor_v2","verify_sensor_and_register",
              *(undefined4 *)(param_1 + -0x18),iVar1);
    }
    else {
      uVar3 = local_80._4_4_ / 0x60;
      if (local_80._4_4_ % 0x60 != 0) {
        uVar3 = local_80._4_4_ / 0x60 + 1;
      }
      if (uVar3 != 0) {
        uVar4 = 0;
        do {
          memset(__s,0,0xc6c);
          local_70[0] = uVar4;
          iVar1 = qmi_ts_send_request(param_1 + -0x198,0x31,7,ts_get_sensor_list_req_msg_v02_ei,
                                      ts_get_sensor_list_resp_msg_v02_ei,local_70,__s,__s);
          if (iVar1 < 0) {
            _printk(&DAT_00102b12,"qti_qmi_sensor_v2","verify_sensor_and_register",
                    *(undefined4 *)(param_1 + -0x18),uVar4,iVar1);
            break;
          }
          if (*(int *)((long)__s + 8) != 0) {
            uVar5 = 0;
            do {
              plVar7 = (long *)(param_1 + -0x10);
              do {
                plVar7 = (long *)*plVar7;
                if (plVar7 == (long *)(param_1 + -0x10)) goto LAB_00100bf0;
                iVar1 = strncasecmp((char *)(plVar7 + -6),
                                    (char *)((long)__s + (long)(int)uVar5 * 0x21 + 0xc),0x20);
              } while (iVar1 != 0);
              lVar6 = (long)(plVar7 + -7);
              *(undefined1 *)(plVar7 + -1) = 1;
              qmi_ts_request(lVar6,1);
              if (plVar7[2] == 0) {
                uVar2 = devm_thermal_of_zone_register
                                  (plVar7[-7],*(int *)(plVar7[5] + 0x180) + *(int *)(plVar7 + 6),
                                   lVar6,qmi_sensor_ops);
                plVar7[2] = uVar2;
                if (uVar2 < 0xfffffffffffff001) {
                  if ((uVar2 != 0) && (*(long *)(uVar2 + 0x440) != 0)) {
                    mutex_lock(uVar2 + 0x480);
                    if (*(long *)(*(long *)(uVar2 + 0x440) + 0x20) == 0) {
                      *(code **)(*(long *)(uVar2 + 0x440) + 0x20) = qti_tz_change_mode;
                    }
                    mutex_unlock(uVar2 + 0x480);
                  }
                }
                else {
                  if ((int)uVar2 != -0x13) {
                    _printk(&DAT_00102a56,"qti_qmi_sensor_v2","qmi_register_sensor_device",
                            plVar7 + -6,uVar2 & 0xffffffff);
                  }
                  plVar7[2] = 0;
                }
              }
              else {
                iVar1 = qmi_ts_request(lVar6,0);
                if (iVar1 != 0) {
                  _printk(&DAT_001028b9,"qti_qmi_sensor_v2","verify_sensor_and_register",
                          plVar7[2] + 4,*(undefined4 *)((long)plVar7 + 0x1c),
                          *(undefined4 *)(plVar7 + 4),iVar1);
                }
              }
LAB_00100bf0:
              uVar5 = uVar5 + 1;
            } while (uVar5 < *(uint *)((long)__s + 8));
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 != uVar3);
      }
    }
    kfree(__s);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_ts_thresh_notify @ 00100dc4 size=36
// signature: undefined qmi_ts_thresh_notify(void)
// callers: []
//------------------------------------------------------------

void qmi_ts_thresh_notify(long param_1)

{
  thermal_zone_device_update(*(undefined8 *)(param_1 + -0x28),2);
  return;
}



//------------------------------------------------------------
// qmi_ts_send_request @ 00100de8 size=396
// signature: undefined qmi_ts_send_request(void)
// callers: [qmi_ts_request, qmi_ts_svc_arrive]
//------------------------------------------------------------

uint qmi_ts_send_request(long param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4,
                        undefined8 param_5,undefined8 param_6,undefined8 param_7,ushort *param_8)

{
  long lVar1;
  uint uVar2;
  undefined *puVar3;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  mutex_lock(param_1 + 0x150);
  uVar2 = qmi_txn_init(param_1 + 8,&local_b0,param_5,param_7);
  if ((int)uVar2 < 0) {
    puVar3 = &DAT_001028f8;
  }
  else {
    uVar2 = qmi_send_request(param_1 + 8,0,&local_b0,param_2,param_3,param_4,param_6);
    if ((int)uVar2 < 0) {
      _printk(&DAT_001029a1,"qti_qmi_sensor_v2","qmi_ts_send_request",param_2,uVar2);
      qmi_txn_cancel(&local_b0);
      goto LAB_00100eb4;
    }
    uVar2 = qmi_txn_wait(&local_b0,0x19);
    if ((int)uVar2 < 0) {
      puVar3 = &DAT_00102acc;
    }
    else {
      uVar2 = (uint)*param_8;
      if (*param_8 == 0) goto LAB_00100eb4;
      puVar3 = &DAT_00102852;
    }
  }
  _printk(puVar3,"qti_qmi_sensor_v2","qmi_ts_send_request",param_2,uVar2);
LAB_00100eb4:
  mutex_unlock(param_1 + 0x150);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// qmi_ts_request @ 00100f74 size=360
// signature: undefined qmi_ts_request(void)
// callers: [qmi_sensor_read, thermal_qmi_net_reset, qmi_ts_svc_arrive, qmi_sensor_set_trips]
//------------------------------------------------------------

int qmi_ts_request(long param_1,ulong param_2)

{
  char *__string;
  bool bVar1;
  long lVar2;
  undefined8 uVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  undefined4 local_78 [2];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  __string = (char *)(param_1 + 8);
  local_38 = *(long *)(lVar2 + 0x638);
  uVar6 = *(undefined8 *)(param_1 + 0x60);
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_48 = 0;
  local_40 = 0;
  local_78[0] = 0;
  uVar5 = strnlen(__string,0x20);
  if (uVar5 < 0x28) {
    if (uVar5 != 0x20) {
      uVar5 = uVar5 + 1;
    }
    if (uVar5 < 0x22) {
      strscpy(&local_70,__string);
      uVar3 = local_50;
      bVar1 = (param_2 & 1) == 0;
      if (bVar1) {
        local_50 = CONCAT44(*(int *)(param_1 + 0x54),(undefined4)local_50);
        local_48 = CONCAT44(*(int *)(param_1 + 0x58),(undefined4)local_48);
        local_50._0_2_ = (undefined2)uVar3;
        local_50._0_3_ = CONCAT12(*(int *)(param_1 + 0x54) != 0x7fffffff,(undefined2)local_50);
        local_48 = CONCAT71(local_48._1_7_,*(int *)(param_1 + 0x58) != -0x7fffffff);
      }
      else {
        local_50._0_2_ = CONCAT11(1,(undefined1)local_50);
      }
      local_40 = CONCAT71((int7)(local_40 >> 8),!bVar1) & 0xffffffff;
      iVar4 = qmi_ts_send_request(uVar6,0x32,0x3d,ts_register_notification_temp_req_msg_v02_ei,
                                  ts_register_notification_temp_resp_msg_v02_ei,&local_70,local_78,
                                  local_78);
      if (iVar4 < 0) {
        _printk(&DAT_001027e0,"qti_qmi_sensor_v2","qmi_ts_request",__string,iVar4);
      }
      lVar2 = sp_el0;
      if (*(long *)(lVar2 + 0x638) == local_38) {
        return iVar4;
      }
      goto LAB_001010d8;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("strscpy");
LAB_001010d8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// qmi_sensor_read @ 001010e0 size=84
// signature: undefined qmi_sensor_read(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_sensor_read(long param_1,undefined4 *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x3f0);
  if ((*(char *)(lVar1 + 0x30) != '\0') && (in_suspend == 0)) {
    qmi_ts_request(lVar1,1);
  }
  *param_2 = *(undefined4 *)(lVar1 + 0x50);
  return 0;
}



//------------------------------------------------------------
// qmi_sensor_set_trips @ 00101138 size=144
// signature: undefined qmi_sensor_set_trips(void)
// callers: []
//------------------------------------------------------------

int qmi_sensor_set_trips(long param_1,int param_2,int param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x3f0);
  if ((*(int *)(lVar2 + 0x54) != param_3) || (*(int *)(lVar2 + 0x58) != param_2)) {
    *(int *)(lVar2 + 0x54) = param_3;
    *(int *)(lVar2 + 0x58) = param_2;
    if (*(char *)(lVar2 + 0x30) != '\0') {
      iVar1 = qmi_ts_request(lVar2,0);
      if (iVar1 < 0) {
        _printk(&DAT_00102bca,"qti_qmi_sensor_v2","qmi_sensor_set_trips",lVar2 + 8,
                *(undefined4 *)(lVar2 + 0x54),*(undefined4 *)(lVar2 + 0x58),iVar1);
        return iVar1;
      }
      return iVar1;
    }
  }
  return 0;
}



//------------------------------------------------------------
// qti_tz_change_mode @ 001011cc size=156
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
// thermal_qmi_new_server @ 0010126c size=164
// signature: undefined thermal_qmi_new_server(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 thermal_qmi_new_server(undefined8 *param_1,long param_2)

{
  long lVar1;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_34 = *(undefined4 *)(param_2 + 0xc);
  local_30 = *(undefined4 *)(param_2 + 0x10);
  local_38 = 0x2a;
  mutex_lock(param_1 + 0x29);
  kernel_connect(*param_1,&local_38,0xc,0);
  mutex_unlock(param_1 + 0x29);
  queue_work_on(0x20,_system_highpri_wq,param_1 + 0x32);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// thermal_qmi_del_server @ 00101314 size=36
// signature: undefined thermal_qmi_del_server(void)
// callers: []
//------------------------------------------------------------

void thermal_qmi_del_server(long param_1)

{
  long *plVar1;
  
  for (plVar1 = *(long **)(param_1 + 0x180); plVar1 != (long *)(param_1 + 0x180);
      plVar1 = (long *)*plVar1) {
    *(undefined1 *)(plVar1 + -1) = 0;
  }
  return;
}



//------------------------------------------------------------
// thermal_qmi_net_reset @ 0010133c size=180
// signature: undefined thermal_qmi_net_reset(void)
// callers: []
//------------------------------------------------------------

void thermal_qmi_net_reset(long param_1)

{
  int iVar1;
  long *plVar2;
  
  for (plVar2 = *(long **)(param_1 + 0x180); plVar2 != (long *)(param_1 + 0x180);
      plVar2 = (long *)*plVar2) {
    if (*(char *)(plVar2 + -1) != '\0') {
      qmi_ts_request(plVar2 + -7,1);
      iVar1 = qmi_ts_request(plVar2 + -7,0);
      if (iVar1 != 0) {
        _printk(&DAT_00102b94,"qti_qmi_sensor_v2","thermal_qmi_net_reset",plVar2[2] + 4,
                *(undefined4 *)((long)plVar2 + 0x1c),*(undefined4 *)(plVar2 + 4),iVar1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_sensor_pm_notify @ 001013f4 size=40
// signature: undefined qmi_sensor_pm_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_sensor_pm_notify(undefined8 param_1,long param_2)

{
  if (param_2 - 1U < 6) {
    in_suspend = *(undefined4 *)(&DAT_00102e40 + (param_2 - 1U) * 4);
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010278c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qmi_sens_device_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001027bc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qmi_sens_device_driver);
  return;
}



//------------------------------------------------------------
// strncasecmp @ 00104008 size=1
// signature: int strncasecmp(char * __s1, char * __s2, size_t __n)
// callers: [qmi_ts_svc_arrive, qmi_ts_ind_cb_v02]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104018 size=1
// signature: undefined queue_work_on(void)
// callers: [thermal_qmi_new_server, qmi_ts_ind_cb_v02]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104020 size=1
// signature: undefined _printk(void)
// callers: [qmi_ts_send_request, qmi_ts_request, thermal_qmi_net_reset, qmi_ts_svc_arrive, qmi_sensor_set_trips, qmi_ts_ind_cb_v02]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104028 size=1
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
// platform_driver_unregister @ 00104030 size=1
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
// of_get_next_available_child @ 00104038 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104040 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104048 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104050 size=1
// signature: undefined __mutex_init(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00104058 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104060 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [qmi_sens_device_probe, qmi_ts_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104068 size=1
// signature: undefined strscpy(void)
// callers: [qmi_sens_device_probe, qmi_ts_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104070 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104078 size=1
// signature: undefined __list_add_valid(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 00104080 size=1
// signature: undefined qmi_handle_init(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 00104088 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00104090 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104098 size=1
// signature: undefined _dev_err(void)
// callers: [qmi_sens_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001040a0 size=1
// signature: undefined fortify_panic(void)
// callers: [qmi_sens_device_probe, qmi_ts_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040a8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qmi_ts_send_request, thermal_qmi_new_server, qmi_sens_device_probe, qmi_ts_request, qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 001040b0 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [qmi_sens_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 001040b8 size=1
// signature: undefined qmi_handle_release(void)
// callers: [qmi_ts_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001040c0 size=1
// signature: undefined mutex_unlock(void)
// callers: [qmi_ts_send_request, thermal_qmi_new_server, qmi_ts_cleanup, qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001040c8 size=1
// signature: undefined mutex_lock(void)
// callers: [qmi_ts_send_request, thermal_qmi_new_server, qmi_ts_cleanup, qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040d0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qmi_ts_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001040e0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001040e8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_zone_register @ 001040f0 size=1
// signature: undefined devm_thermal_of_zone_register(void)
// callers: [qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_zone_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040f8 size=1
// signature: undefined kfree(void)
// callers: [qmi_ts_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_update @ 00104100 size=1
// signature: undefined thermal_zone_device_update(void)
// callers: [qmi_ts_thresh_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_update(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 00104108 size=1
// signature: undefined qmi_txn_init(void)
// callers: [qmi_ts_send_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 00104110 size=1
// signature: undefined qmi_send_request(void)
// callers: [qmi_ts_send_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 00104118 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [qmi_ts_send_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 00104120 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [qmi_ts_send_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cdev_update @ 00104128 size=1
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
// kernel_connect @ 00104130 size=1
// signature: undefined kernel_connect(void)
// callers: [thermal_qmi_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



