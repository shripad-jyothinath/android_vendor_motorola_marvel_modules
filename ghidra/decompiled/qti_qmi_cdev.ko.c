// Decompiled by Ghidra 12.2
// Program: qti_qmi_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// qmi_device_probe @ 001002a4 size=1100
// signature: undefined qmi_device_probe(void)
// callers: []
//------------------------------------------------------------

int qmi_device_probe(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  undefined1 auVar4 [16];
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  long *plVar9;
  ulong uVar10;
  long *plVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  char *local_70;
  long local_68;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar6 + 0x638);
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  lVar6 = of_get_next_available_child(uVar12,0);
  if (lVar6 == 0) {
LAB_00100658:
    _dev_err(lVar1,"No child node to process\n");
    iVar5 = -0xe;
  }
  else {
    uVar17 = 0;
    do {
      uVar16 = uVar17;
      uVar17 = uVar16 + 1;
      lVar6 = of_get_next_available_child(uVar12,lVar6);
    } while (lVar6 != 0);
    if (uVar17 == 0) goto LAB_00100658;
    auVar4._8_8_ = 0;
    auVar4._0_8_ = (long)(int)uVar17;
    if ((SUB168(auVar4 * ZEXT816(0x1c8),8) == 0) &&
       (lVar6 = devm_kmalloc(lVar1,(long)(int)uVar17 * 0x1c8,0xdc0), lVar6 != 0)) {
      lVar7 = of_get_next_available_child(uVar12,0);
      if ((lVar7 != 0) && (uVar16 < 0x7fffffff)) {
        lVar14 = 0;
        do {
          plVar11 = (long *)(lVar6 + lVar14 * 0x1c8);
          iVar5 = of_property_read_variable_u32_array(lVar7,"qcom,instance-id",plVar11 + 0x30,1,0);
          if (iVar5 < 0) {
            _dev_err(lVar1,"error reading qcom,insance-id. ret:%d\n",iVar5);
            goto LAB_00100578;
          }
          lVar13 = lVar6 + lVar14 * 0x1c8;
          *plVar11 = lVar1;
          __mutex_init(lVar13 + 0x150,"&tmd[idx].mutex",&of_get_qmi_tmd_platform_data___key);
          plVar2 = (long *)(lVar13 + 0x188);
          *(long **)(lVar13 + 0x188) = plVar2;
          *(long **)(lVar13 + 400) = plVar2;
          *(undefined8 *)(lVar13 + 0x198) = 0xfffffffe0;
          *(long *)(lVar13 + 0x1a0) = lVar13 + 0x1a0;
          *(long *)(lVar13 + 0x1a8) = lVar13 + 0x1a0;
          *(code **)(lVar13 + 0x1b0) = qmi_tmd_svc_arrive;
          puVar8 = (undefined8 *)of_get_next_available_child(lVar7,0);
          if (puVar8 != (undefined8 *)0x0) {
            do {
              local_70 = (char *)0x0;
              plVar9 = (long *)devm_kmalloc(lVar1,0x78,0xdc0);
              if (plVar9 == (long *)0x0) goto LAB_00100574;
              pcVar15 = (char *)*puVar8;
              uVar10 = strnlen(pcVar15,0x20);
              if (uVar10 == 0xffffffffffffffff) {
LAB_001006d4:
                fortify_panic("strnlen");
LAB_001006e0:
                fortify_panic("strscpy");
                goto LAB_001006ec;
              }
              if (uVar10 != 0x20) {
                uVar10 = uVar10 + 1;
              }
              if (0x20 < uVar10) goto LAB_001006e0;
              strscpy(plVar9 + 1,pcVar15);
              iVar5 = of_property_read_string(puVar8,"qcom,qmi-dev-name",&local_70);
              pcVar15 = local_70;
              if (iVar5 != 0) {
                pcVar15 = "Fail to parse dev name for %s\n";
LAB_00100528:
                _dev_err(lVar1,pcVar15,*puVar8);
                break;
              }
              uVar10 = strnlen(local_70,0x20);
              if (uVar10 == 0xffffffffffffffff) goto LAB_001006d4;
              if (uVar10 != 0x20) {
                uVar10 = uVar10 + 1;
              }
              if (0x20 < uVar10) goto LAB_001006e0;
              strscpy(plVar9 + 5,pcVar15);
              lVar13 = 0;
              while (iVar5 = strcmp(&device_clients + lVar13,(char *)(plVar9 + 5)), iVar5 != 0) {
                lVar13 = lVar13 + 0x20;
                if (lVar13 == 0x960) {
                  pcVar15 = "Not supported dev name for %s\n";
                  goto LAB_00100528;
                }
              }
              lVar13 = *plVar2;
              plVar3 = plVar9 + 10;
              plVar9[0xe] = (long)plVar11;
              *plVar9 = (long)puVar8;
              *(undefined4 *)(plVar9 + 0xd) = 0;
              uVar10 = __list_add_valid(plVar3,plVar2,lVar13);
              if ((uVar10 & 1) != 0) {
                *(long **)(lVar13 + 8) = plVar3;
                plVar9[10] = lVar13;
                plVar9[0xb] = (long)plVar2;
                *plVar2 = (long)plVar3;
              }
              puVar8 = (undefined8 *)of_get_next_available_child(lVar7,puVar8);
            } while (puVar8 != (undefined8 *)0x0);
          }
          lVar7 = of_get_next_available_child(uVar12,lVar7);
        } while ((lVar7 != 0) && (lVar14 = lVar14 + 1, lVar14 < (int)uVar17));
      }
      tmd_instances = lVar6;
      tmd_inst_cnt = uVar17;
      if (uVar16 < 0x7fffffff) {
        lVar7 = 0;
        lVar14 = 0x188;
        do {
          plVar11 = (long *)(lVar6 + lVar14);
          if (plVar11 != (long *)*plVar11) {
            iVar5 = qmi_handle_init(plVar11 + -0x30,0xccf,&thermal_qmi_event_ops,0);
            if (iVar5 < 0) {
              _dev_err(lVar1,"QMI[0x%x] handle init failed. err:%d\n",
                       *(undefined4 *)(lVar6 + lVar14 + -8),iVar5);
              tmd_inst_cnt = (uint)lVar7;
              goto LAB_00100578;
            }
            iVar5 = qmi_add_lookup(plVar11 + -0x30,0x18,1,*(undefined4 *)(lVar6 + lVar14 + -8));
            if (iVar5 < 0) {
              _dev_err(lVar1,"QMI register failed for 0x%x, ret:%d\n",
                       *(undefined4 *)(lVar6 + lVar14 + -8),iVar5);
              goto LAB_00100578;
            }
            lVar6 = tmd_instances;
            uVar17 = tmd_inst_cnt;
          }
          lVar7 = lVar7 + 1;
          lVar14 = lVar14 + 0x1c8;
        } while (lVar7 < (int)uVar17);
      }
      iVar5 = 0;
      goto LAB_0010061c;
    }
LAB_00100574:
    iVar5 = -0xc;
  }
LAB_00100578:
  qmi_tmd_cleanup();
LAB_0010061c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) == local_68) {
    return iVar5;
  }
LAB_001006ec:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// qmi_device_remove @ 001006f4 size=32
// signature: undefined qmi_device_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_device_remove(void)

{
  qmi_tmd_cleanup();
  return 0;
}



//------------------------------------------------------------
// qmi_tmd_cleanup @ 00100714 size=248
// signature: undefined qmi_tmd_cleanup(void)
// callers: [qmi_device_probe, qmi_device_remove]
//------------------------------------------------------------

void qmi_tmd_cleanup(void)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  
  lVar4 = tmd_instances;
  if (0 < tmd_inst_cnt) {
    lVar6 = 0;
    do {
      lVar7 = lVar4 + lVar6 * 0x1c8;
      mutex_lock(lVar7 + 0x150);
      plVar3 = *(long **)(lVar7 + 0x188);
      while (plVar3 != (long *)(lVar7 + 0x188)) {
        *(undefined1 *)(plVar3 + -1) = 0;
        plVar8 = (long *)*plVar3;
        if (plVar3[2] != 0) {
          thermal_cooling_device_unregister();
        }
        uVar5 = __list_del_entry_valid(plVar3);
        if ((uVar5 & 1) != 0) {
          lVar1 = *plVar3;
          plVar2 = (long *)plVar3[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        *plVar3 = -0x2152ffffffffff00;
        plVar3[1] = -0x2152fffffffffede;
        plVar3 = plVar8;
      }
      qmi_handle_release(lVar4 + lVar6 * 0x1c8 + 8);
      mutex_unlock(lVar7 + 0x150);
      lVar6 = lVar6 + 1;
    } while (lVar6 < tmd_inst_cnt);
  }
  return;
}



//------------------------------------------------------------
// qmi_tmd_svc_arrive @ 00100810 size=884
// signature: undefined qmi_tmd_svc_arrive(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_tmd_svc_arrive(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ushort *puVar4;
  ulong uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  long lVar8;
  ulong uVar9;
  long *plVar10;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 local_70 [8];
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_70[0] = 0;
  puVar4 = (ushort *)kmalloc_trace(_queue_work_on,0xdc0,0xcd4);
  if (puVar4 == (ushort *)0x0) goto LAB_00100af4;
  lVar8 = param_1 + -0x48;
  mutex_lock(lVar8);
  uVar2 = qmi_txn_init(param_1 + -400,&local_b8,tmd_get_mitigation_device_list_resp_msg_v01_ei,
                       puVar4);
  if ((int)uVar2 < 0) {
    uVar7 = *(undefined4 *)(param_1 + -0x18);
    puVar6 = &DAT_00102091;
    goto LAB_00100b60;
  }
  iVar3 = qmi_send_request(param_1 + -400,0,&local_b8,0x20,0,
                           &tmd_get_mitigation_device_list_req_msg_v01_ei,local_70);
  if (iVar3 < 0) {
    qmi_txn_cancel(&local_b8);
LAB_001009dc:
    mutex_unlock(lVar8);
  }
  else {
    uVar2 = qmi_txn_wait(&local_b8,0x19);
    if ((int)uVar2 < 0) {
      uVar7 = *(undefined4 *)(param_1 + -0x18);
      puVar6 = &DAT_001020c9;
LAB_00100b60:
      _printk(puVar6,"qti_qmi_cdev","verify_devices_and_register",uVar7,uVar2);
      goto LAB_001009dc;
    }
    uVar2 = (uint)*puVar4;
    if (*puVar4 != 0) {
      uVar7 = *(undefined4 *)(param_1 + -0x18);
      puVar6 = &DAT_00102101;
      goto LAB_00100b60;
    }
    mutex_unlock(lVar8);
    if (*(int *)(puVar4 + 4) != 0) {
      uVar9 = 0;
      do {
        plVar10 = (long *)(param_1 + -0x10);
        do {
          plVar10 = (long *)*plVar10;
          if (plVar10 == (long *)(param_1 + -0x10)) goto LAB_0010090c;
          if (0x20 < uVar9) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100b7c);
            (*pcVar1)();
          }
          iVar3 = strncasecmp((char *)(plVar10 + -5),(char *)(puVar4 + uVar9 * 0x11 + 6),0x20);
        } while (iVar3 != 0);
        *(undefined1 *)(plVar10 + -1) = 1;
        if (uVar9 * 0x22 - 0xca8 < 0xfffffffffffff32b) goto LAB_00100b7c;
        *(uint *)((long)plVar10 + 0x1c) = (uint)*(byte *)((long)puVar4 + uVar9 * 0x22 + 0x2d);
        qmi_tmd_send_state_request(plVar10 + -10,*(undefined4 *)(plVar10 + 3));
        if (plVar10[2] == 0) {
          uVar5 = thermal_of_cooling_device_register
                            (plVar10[-10],plVar10 + -9,plVar10 + -10,&qmi_device_ops);
          plVar10[2] = uVar5;
          if (0xfffffffffffff000 < uVar5) {
            _printk(&DAT_001021e0,"qti_qmi_cdev","qmi_register_cooling_device",plVar10 + -9,uVar5);
          }
        }
LAB_0010090c:
        uVar9 = uVar9 + 1;
      } while (uVar9 < *(uint *)(puVar4 + 4));
    }
    if ((char)puVar4[0x226] != '\0') {
      uVar2 = 0;
      do {
        if (*(uint *)(puVar4 + 0x228) <= uVar2) break;
        plVar10 = (long *)(param_1 + -0x10);
        do {
          plVar10 = (long *)*plVar10;
          if (plVar10 == (long *)(param_1 + -0x10)) goto LAB_00100a14;
          iVar3 = strncasecmp((char *)(plVar10 + -5),
                              (char *)(puVar4 + (long)(int)uVar2 * 0x11 + 0x22a),0x20);
        } while (iVar3 != 0);
        *(undefined1 *)(plVar10 + -1) = 1;
        if (((long)(int)uVar2 * 0x22 - 0x860U < 0xfffffffffffff32b) ||
           ((long)(int)uVar2 * 0x22 - 0x860U < 0xfffffffffffff32b)) {
LAB_00100b7c:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x100b80);
          (*pcVar1)();
        }
        *(uint *)((long)plVar10 + 0x1c) =
             (uint)*(byte *)((long)puVar4 + (long)(int)uVar2 * 0x22 + 0x475);
        qmi_tmd_send_state_request(plVar10 + -10,*(undefined4 *)(plVar10 + 3));
        if (plVar10[2] == 0) {
          uVar9 = thermal_of_cooling_device_register
                            (plVar10[-10],plVar10 + -9,plVar10 + -10,&qmi_device_ops);
          plVar10[2] = uVar9;
          if (0xfffffffffffff000 < uVar9) {
            _printk(&DAT_001021e0,"qti_qmi_cdev","qmi_register_cooling_device",plVar10 + -9,uVar9);
          }
        }
LAB_00100a14:
        uVar2 = uVar2 + 1;
      } while ((char)puVar4[0x226] != '\0');
    }
  }
  kfree(puVar4);
LAB_00100af4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_tmd_send_state_request @ 00100b84 size=488
// signature: undefined qmi_tmd_send_state_request(void)
// callers: [qmi_tmd_svc_arrive, qmi_set_cur_state, thermal_qmi_net_reset]
//------------------------------------------------------------

uint qmi_tmd_send_state_request(long param_1,undefined1 param_2)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  undefined *puVar4;
  long lVar5;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  uint local_78 [2];
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined2 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x70);
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c0 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_78[0] = 0;
  uVar3 = strnlen((char *)(param_1 + 0x28),0x20);
  if (uVar3 < 0x21) {
    if (uVar3 != 0x20) {
      uVar3 = uVar3 + 1;
    }
    if (uVar3 < 0x22) {
      strscpy(&local_70,(char *)(param_1 + 0x28));
      lVar1 = lVar5 + 0x150;
      local_50 = CONCAT11(param_2,(undefined1)local_50);
      mutex_lock(lVar1);
      lVar5 = lVar5 + 8;
      uVar2 = qmi_txn_init(lVar5,&local_c0,tmd_set_mitigation_level_resp_msg_v01_ei,local_78);
      if ((int)uVar2 < 0) {
        puVar4 = &DAT_001022cb;
LAB_00100d34:
        _printk(puVar4,"qti_qmi_cdev","qmi_tmd_send_state_request",param_2,param_1 + 8,uVar2);
      }
      else {
        uVar2 = qmi_send_request(lVar5,0,&local_c0,0x21,0x28,tmd_set_mitigation_level_req_msg_v01_ei
                                 ,&local_70);
        if (-1 < (int)uVar2) {
          uVar2 = qmi_txn_wait(&local_c0,0x19);
          if ((int)uVar2 < 0) {
            puVar4 = &DAT_0010225f;
          }
          else {
            uVar2 = local_78[0] & 0xffff;
            if ((short)local_78[0] == 0) goto LAB_00100c84;
            puVar4 = &DAT_00102297;
          }
          goto LAB_00100d34;
        }
        _printk(&DAT_0010202f,"qti_qmi_cdev","qmi_tmd_send_state_request",param_2,param_1 + 8,uVar2)
        ;
        qmi_txn_cancel(&local_c0);
      }
LAB_00100c84:
      mutex_unlock(lVar1);
      lVar5 = sp_el0;
      if (*(long *)(lVar5 + 0x638) == local_48) {
        return uVar2;
      }
      goto LAB_00100d68;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("strscpy");
LAB_00100d68:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// qmi_get_max_state @ 00100d70 size=32
// signature: undefined qmi_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_get_max_state(long param_1,ulong *param_2)

{
  if (*(long *)(param_1 + 0x3b0) == 0) {
    return 0xffffffea;
  }
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x6c);
  return 0;
}



//------------------------------------------------------------
// qmi_get_cur_state @ 00100d94 size=32
// signature: undefined qmi_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_get_cur_state(long param_1,ulong *param_2)

{
  if (*(long *)(param_1 + 0x3b0) == 0) {
    return 0xffffffea;
  }
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x68);
  return 0;
}



//------------------------------------------------------------
// qmi_set_cur_state @ 00100db8 size=116
// signature: undefined qmi_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_set_cur_state(long param_1,ulong param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x3b0);
  if ((lVar2 == 0) || (*(uint *)(lVar2 + 0x6c) < param_2)) {
    uVar1 = 0xffffffea;
  }
  else if (*(uint *)(lVar2 + 0x68) == param_2) {
    uVar1 = 0;
  }
  else {
    if (*(char *)(lVar2 + 0x48) == '\0') {
      uVar1 = 0;
    }
    else {
      uVar1 = qmi_tmd_send_state_request(lVar2,param_2 & 0xffffffff);
    }
    *(int *)(lVar2 + 0x68) = (int)param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// thermal_qmi_new_server @ 00100e30 size=164
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
// thermal_qmi_del_server @ 00100ed8 size=36
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
// thermal_qmi_net_reset @ 00100f00 size=80
// signature: undefined thermal_qmi_net_reset(void)
// callers: []
//------------------------------------------------------------

void thermal_qmi_net_reset(long param_1)

{
  undefined8 *puVar1;
  
  for (puVar1 = *(undefined8 **)(param_1 + 0x180); puVar1 != (undefined8 *)(param_1 + 0x180);
      puVar1 = (undefined8 *)*puVar1) {
    if (*(char *)(puVar1 + -1) != '\0') {
      qmi_tmd_send_state_request(puVar1 + -10,*(undefined4 *)(puVar1 + 3));
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101ee4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qmi_device_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101f14 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qmi_device_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00104008 size=1
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
// platform_driver_unregister @ 00104010 size=1
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
// of_get_next_available_child @ 00104018 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00104028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104030 size=1
// signature: undefined __mutex_init(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104038 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [qmi_device_probe, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104040 size=1
// signature: undefined strscpy(void)
// callers: [qmi_device_probe, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104048 size=1
// signature: undefined of_property_read_string(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104050 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104058 size=1
// signature: undefined __list_add_valid(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104060 size=1
// signature: undefined _dev_err(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 00104068 size=1
// signature: undefined qmi_handle_init(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 00104070 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [qmi_device_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104078 size=1
// signature: undefined fortify_panic(void)
// callers: [qmi_device_probe, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qmi_device_probe, qmi_tmd_svc_arrive, qmi_tmd_send_state_request, thermal_qmi_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 00104088 size=1
// signature: undefined qmi_handle_release(void)
// callers: [qmi_tmd_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104090 size=1
// signature: undefined mutex_unlock(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request, thermal_qmi_new_server, qmi_tmd_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104098 size=1
// signature: undefined mutex_lock(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request, thermal_qmi_new_server, qmi_tmd_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 001040a0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [qmi_tmd_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040a8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qmi_tmd_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001040b8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qmi_tmd_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 001040c0 size=1
// signature: undefined qmi_txn_init(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 001040c8 size=1
// signature: undefined qmi_send_request(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 001040d0 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncasecmp @ 001040d8 size=1
// signature: int strncasecmp(char * __s1, char * __s2, size_t __n)
// callers: [qmi_tmd_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 001040e0 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [qmi_tmd_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040e8 size=1
// signature: undefined _printk(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 001040f0 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [qmi_tmd_svc_arrive, qmi_tmd_send_state_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001040f8 size=1
// signature: undefined kfree(void)
// callers: [qmi_tmd_svc_arrive]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_connect @ 00104100 size=1
// signature: undefined kernel_connect(void)
// callers: [thermal_qmi_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104110 size=1
// signature: undefined queue_work_on(void)
// callers: [thermal_qmi_new_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



