// Decompiled by Ghidra 12.2
// Program: rmnet_core.ko
// Image base: 00100000

//------------------------------------------------------------
// rmnet_is_real_dev_registered @ 00106894 size=24
// signature: undefined rmnet_is_real_dev_registered(void)
// callers: []
//------------------------------------------------------------

bool rmnet_is_real_dev_registered(long param_1)

{
  return *(code **)(param_1 + 0x330) == rmnet_rx_handler;
}



//------------------------------------------------------------
// rmnet_rtnl_validate @ 001068b0 size=96
// signature: undefined rmnet_rtnl_validate(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_rtnl_validate(undefined8 param_1,long param_2)

{
  if (param_2 == 0) {
    return 0xffffffea;
  }
  if ((*(long *)(param_2 + 8) != 0) && (0xfe < *(ushort *)(*(long *)(param_2 + 8) + 4))) {
    return 0xffffffde;
  }
  if (*(long *)(param_2 + 0x20) != 0) {
    if (*(uint *)(*(long *)(param_2 + 0x20) + 8) < 1000000) {
      return 0xffffffea;
    }
    if ((*(long *)(param_2 + 0x28) != 0) && (1 < *(byte *)(*(long *)(param_2 + 0x28) + 4))) {
      return 0xffffffde;
    }
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_newlink @ 00106914 size=376
// signature: undefined rmnet_newlink(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int rmnet_newlink(undefined8 param_1,long param_2,long param_3,long param_4)

{
  ushort uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  
  lVar4 = __dev_get_by_index(param_1,*(undefined4 *)(*(long *)(param_3 + 0x28) + 4));
  iVar3 = -0x13;
  if ((param_2 != 0) && (lVar4 != 0)) {
    if (*(long *)(param_4 + 8) == 0) {
      iVar3 = -0x16;
    }
    else {
      lVar5 = kmalloc_trace(___stack_chk_fail,0xb20,0x20);
      if (lVar5 == 0) {
        iVar3 = -0xc;
      }
      else {
        uVar1 = *(ushort *)(*(long *)(param_4 + 8) + 4);
        iVar3 = rmnet_register_real_device(lVar4);
        if (iVar3 == 0) {
          lVar8 = *(long *)(lVar4 + 0x338);
          iVar3 = rmnet_vnd_newlink((ulong)uVar1,param_2,lVar8,lVar4,lVar5);
          if (iVar3 == 0) {
            *(undefined1 *)(lVar8 + 0xd) = 1;
            if (0xff < uVar1) {
LAB_00106a88:
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106a8c);
              (*pcVar2)();
            }
            plVar6 = (long *)(lVar8 + (ulong)uVar1 * 8 + 0x10);
            lVar4 = *plVar6;
            plVar9 = (long *)(lVar5 + 0x10);
            *plVar9 = lVar4;
            *(long **)(lVar5 + 0x18) = plVar6;
            *plVar6 = (long)plVar9;
            if (lVar4 != 0) {
              *(long **)(lVar4 + 8) = plVar9;
            }
            lVar4 = *(long *)(param_4 + 0x10);
            if (lVar4 != 0) {
              *(uint *)(lVar8 + 8) =
                   *(uint *)(lVar8 + 8) & 0x8000000 | *(uint *)(lVar4 + 8) & *(uint *)(lVar4 + 4);
            }
            lVar4 = *(long *)(param_4 + 0x20);
            if (lVar4 != 0) {
              uVar7 = 0;
              if ((*(long *)(param_4 + 0x28) != 0) &&
                 (uVar7 = (ulong)*(byte *)(*(long *)(param_4 + 0x28) + 4), 2 < uVar7))
              goto LAB_00106a88;
              rmnet_map_update_ul_agg_config
                        (lVar8 + uVar7 * 0xe0 + 0x818,*(undefined2 *)(lVar4 + 4),
                         *(undefined1 *)(lVar4 + 6),*(undefined1 *)(lVar4 + 7),
                         *(undefined4 *)(lVar4 + 8));
            }
            return 0;
          }
          rmnet_unregister_real_device(lVar4,lVar8);
        }
        kfree(lVar5);
      }
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// rmnet_changelink @ 00106a90 size=400
// signature: undefined rmnet_changelink(void)
// callers: []
//------------------------------------------------------------

undefined4 rmnet_changelink(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  code *pcVar2;
  undefined4 uVar3;
  long lVar4;
  ushort *puVar5;
  byte *pbVar6;
  ulong uVar7;
  long lVar8;
  byte *pbVar9;
  long *plVar10;
  
  lVar4 = __dev_get_by_index(*(undefined8 *)(param_1 + 0x500),
                             *(undefined4 *)(*(long *)(param_2 + 0x28) + 4));
  uVar3 = 0xffffffed;
  if (((param_1 != 0) && (lVar4 != 0)) && (*(code **)(lVar4 + 0x330) == rmnet_rx_handler)) {
    lVar4 = *(long *)(lVar4 + 0x338);
    if (*(long *)(param_3 + 8) == 0) {
LAB_00106b8c:
      lVar8 = *(long *)(param_3 + 0x10);
      if (lVar8 != 0) {
        *(uint *)(lVar4 + 8) =
             *(uint *)(lVar4 + 8) & 0x8000000 | *(uint *)(lVar8 + 8) & *(uint *)(lVar8 + 4);
      }
      puVar5 = *(ushort **)(param_3 + 0x18);
      if (puVar5 == (ushort *)0x0) {
        uVar3 = 0;
        lVar8 = *(long *)(param_3 + 0x20);
      }
      else {
        uVar3 = qmi_rmnet_change_link(param_1,lVar4,puVar5 + 2,*puVar5 - 4);
        lVar8 = *(long *)(param_3 + 0x20);
      }
      if (lVar8 != 0) {
        uVar7 = 0;
        if ((*(long *)(param_3 + 0x28) != 0) &&
           (uVar7 = (ulong)*(byte *)(*(long *)(param_3 + 0x28) + 4), 2 < uVar7)) {
LAB_00106c1c:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106c20);
          (*pcVar2)();
        }
        rmnet_map_update_ul_agg_config
                  (lVar4 + uVar7 * 0xe0 + 0x818,*(undefined2 *)(lVar8 + 4),
                   *(undefined1 *)(lVar8 + 6),*(undefined1 *)(lVar8 + 7),*(undefined4 *)(lVar8 + 8))
        ;
      }
    }
    else {
      uVar1 = *(ushort *)(*(long *)(param_3 + 8) + 4);
      lVar8 = *(long *)(lVar4 + (ulong)*(byte *)(param_1 + 0xa40) * 8 + 0x10);
      pbVar6 = (byte *)(lVar8 + -0x10);
      if (lVar8 != 0 && pbVar6 != (byte *)0x0) {
        do {
          pbVar9 = pbVar6 + 0x10;
          if (*pbVar6 == *(byte *)(param_1 + 0xa40)) {
            plVar10 = *(long **)(pbVar6 + 0x18);
            if (plVar10 != (long *)0x0) {
              lVar8 = *(long *)pbVar9;
              *plVar10 = lVar8;
              if (lVar8 != 0) {
                *(long **)(lVar8 + 8) = plVar10;
              }
              pbVar6[0x18] = 0;
              pbVar6[0x19] = 0;
              pbVar6[0x1a] = 0;
              pbVar6[0x1b] = 0;
              pbVar6[0x1c] = 0;
              pbVar6[0x1d] = 0;
              pbVar6[0x1e] = 0;
              pbVar6[0x1f] = 0;
            }
            if (0xff < uVar1) goto LAB_00106c1c;
            plVar10 = (long *)(lVar4 + (ulong)uVar1 * 8 + 0x10);
            lVar8 = *plVar10;
            *(long *)(pbVar6 + 0x10) = lVar8;
            *(long **)(pbVar6 + 0x18) = plVar10;
            *plVar10 = (long)pbVar9;
            if (lVar8 != 0) {
              *(byte **)(lVar8 + 8) = pbVar9;
            }
            *pbVar6 = (byte)uVar1;
            *(byte *)(param_1 + 0xa40) = (byte)uVar1;
            goto LAB_00106b8c;
          }
        } while ((*(long *)pbVar9 != 0) &&
                (pbVar6 = (byte *)(*(long *)pbVar9 + -0x10), pbVar6 != (byte *)0x0));
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// rmnet_dellink @ 00106c24 size=300
// signature: undefined rmnet_dellink(void)
// callers: []
//------------------------------------------------------------

void rmnet_dellink(long param_1)

{
  ulong uVar1;
  long lVar2;
  long *plVar3;
  long lVar4;
  long lVar5;
  byte *pbVar6;
  
  lVar4 = *(long *)(param_1 + 0xa48);
  if ((lVar4 != 0) && (*(code **)(lVar4 + 0x330) == rmnet_rx_handler)) {
    lVar5 = *(long *)(lVar4 + 0x338);
    uVar1 = rmnet_vnd_get_mux();
    lVar2 = *(long *)(lVar5 + (uVar1 & 0xff) * 8 + 0x10);
    pbVar6 = (byte *)(lVar2 + -0x10);
    if (lVar2 != 0 && pbVar6 != (byte *)0x0) {
      while ((uint)*pbVar6 != ((uint)uVar1 & 0xff)) {
        if ((*(long *)(pbVar6 + 0x10) == 0) ||
           (pbVar6 = (byte *)(*(long *)(pbVar6 + 0x10) + -0x10), pbVar6 == (byte *)0x0))
        goto LAB_00106d08;
      }
      plVar3 = *(long **)(pbVar6 + 0x18);
      if (plVar3 != (long *)0x0) {
        lVar2 = *(long *)(pbVar6 + 0x10);
        *plVar3 = lVar2;
        if (lVar2 != 0) {
          *(long **)(lVar2 + 8) = plVar3;
        }
        pbVar6[0x18] = 0;
        pbVar6[0x19] = 0;
        pbVar6[0x1a] = 0;
        pbVar6[0x1b] = 0;
        pbVar6[0x1c] = 0;
        pbVar6[0x1d] = 0;
        pbVar6[0x1e] = 0;
        pbVar6[0x1f] = 0;
      }
      synchronize_rcu();
      if (*(char *)(lVar5 + 0xd) == '\x02') {
        lVar2 = *(long *)(*(long *)(lVar5 + 0x808) + 0x338);
        if (*(char *)(lVar5 + 0xc) == '\0') {
          *(undefined8 *)(lVar2 + 0x808) = 0;
          *(undefined1 *)(lVar2 + 0xd) = 1;
        }
        else {
          rmnet_unregister_real_device();
        }
      }
      rmnet_vnd_dellink(uVar1 & 0xffffffff,lVar5,pbVar6);
      kfree(pbVar6);
    }
LAB_00106d08:
    if (*(char *)(lVar5 + 0xc) == '\0') {
      qmi_rmnet_qmi_exit(*(undefined8 *)(lVar5 + 0x9d8),lVar5);
    }
    unregister_netdevice_queue(param_1,0);
    qmi_rmnet_qos_exit_post();
    rmnet_unregister_real_device(lVar4,lVar5);
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_size @ 00106d54 size=8
// signature: undefined rmnet_get_size(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_get_size(void)

{
  return 0x38;
}



//------------------------------------------------------------
// rmnet_fill_info @ 00106d60 size=228
// signature: undefined rmnet_fill_info(void)
// callers: []
//------------------------------------------------------------

void rmnet_fill_info(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_2 + 0xa48);
  local_30 = CONCAT22(local_30._2_2_,(ushort)*(byte *)(param_2 + 0xa40));
  iVar1 = nla_put(param_1,1,2,&local_30);
  if (iVar1 == 0) {
    if (*(code **)(lVar3 + 0x330) == rmnet_rx_handler) {
      lVar3 = *(long *)(lVar3 + 0x338);
      local_30 = *(undefined4 *)(lVar3 + 8);
    }
    else {
      local_30 = 0;
      lVar3 = 0;
    }
    uStack_2c = 0xffffffff;
    iVar1 = nla_put(param_1,2,8,&local_30);
    if (iVar1 == 0) {
      if (lVar3 == 0) {
        uVar2 = 0;
        goto LAB_00106df0;
      }
      uVar2 = nla_put(param_1,4,8,lVar3 + 0x818);
      if ((int)uVar2 == 0) goto LAB_00106df0;
    }
  }
  uVar2 = 0xffffffa6;
LAB_00106df0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_port @ 00106e48 size=36
// signature: undefined rmnet_get_port(void)
// callers: [rmnet_map_tx_qmap_cmd, rmnet_rx_handler, rmnet_get_ethtool_stats, rmnet_stats_reset, rmnet_egress_handler]
//------------------------------------------------------------

undefined8 rmnet_get_port(long param_1)

{
  if (*(code **)(param_1 + 0x330) == rmnet_rx_handler) {
    return *(undefined8 *)(param_1 + 0x338);
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_get_endpoint @ 00106e70 size=80
// signature: undefined rmnet_get_endpoint(void)
// callers: [__rmnet_map_ingress_handler, rmnet_frag_ingress_handler, rmnet_vnd_newlink, rmnet_map_do_flow_control, rmnet_frag_command]
//------------------------------------------------------------

byte * rmnet_get_endpoint(long param_1,byte param_2)

{
  byte *pbVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + (ulong)param_2 * 8 + 0x10);
  pbVar1 = (byte *)(lVar2 + -0x10);
  if (lVar2 == 0 || pbVar1 == (byte *)0x0) {
    return (byte *)0x0;
  }
  do {
    if (*pbVar1 == param_2) {
      return pbVar1;
    }
  } while ((*(long *)(pbVar1 + 0x10) != 0) &&
          (pbVar1 = (byte *)(*(long *)(pbVar1 + 0x10) + -0x10), pbVar1 != (byte *)0x0));
  return (byte *)0x0;
}



//------------------------------------------------------------
// rmnet_add_bridge @ 00106ec4 size=180
// signature: undefined rmnet_add_bridge(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_add_bridge(long param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0xa48);
  if (*(code **)(lVar4 + 0x330) == rmnet_rx_handler) {
    lVar5 = *(long *)(lVar4 + 0x338);
  }
  else {
    lVar5 = 0;
  }
  if (*(byte *)(lVar5 + 0xc) < 2) {
    if ((*(code **)(param_2 + 0x330) == rmnet_rx_handler) ||
       (iVar1 = rmnet_register_real_device(param_2), iVar1 != 0)) {
      uVar2 = 0xfffffff0;
    }
    else {
      if (*(code **)(param_2 + 0x330) == rmnet_rx_handler) {
        lVar3 = *(long *)(param_2 + 0x338);
      }
      else {
        lVar3 = 0;
      }
      uVar2 = 0;
      *(long *)(lVar3 + 0x808) = lVar4;
      *(undefined1 *)(lVar3 + 0xd) = 2;
      *(undefined1 *)(lVar5 + 0xd) = 2;
      *(long *)(lVar5 + 0x808) = param_2;
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_register_real_device @ 00106f78 size=364
// signature: undefined rmnet_register_real_device(void)
// callers: [rmnet_newlink, rmnet_add_bridge]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int rmnet_register_real_device(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  code *pcVar6;
  int iVar7;
  long *plVar8;
  
  iVar7 = rtnl_is_locked();
  if ((iVar7 == 0) && ((rmnet_register_real_device___already_done & 1) == 0)) {
    rmnet_register_real_device___already_done = 1;
    __warn_printk("RTNL: assertion failed at %s (%d)\n",
                  "../vendor/qcom/opensource/datarmnet/core/rmnet_config.c",0x7c);
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1070dc);
    (*pcVar6)();
  }
  if (*(code **)(param_1 + 0x330) == rmnet_rx_handler) {
LAB_0010709c:
    iVar7 = 0;
  }
  else {
    plVar8 = (long *)kmalloc_trace(_netdev_rx_handler_unregister,0xb20,0xb48);
    if (plVar8 == (long *)0x0) {
      return -0xc;
    }
    *plVar8 = param_1;
    *(undefined2 *)((long)plVar8 + 0xb14) = 200;
    *(undefined4 *)(plVar8 + 0x162) = 0xff0007;
    rmnet_map_tx_aggregate_init();
    rmnet_map_cmd_init(plVar8);
    memset(plVar8 + 2,0,0x7f8);
    iVar7 = rmnet_descriptor_init(plVar8);
    if (iVar7 == 0) {
      iVar7 = netdev_rx_handler_register(param_1,rmnet_rx_handler,plVar8);
      if (iVar7 == 0) {
        if (param_1 != 0) {
          lVar5 = sp_el0;
          *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
          lVar4 = tpidr_el1;
          piVar1 = (int *)(lVar4 + *(long *)(param_1 + 0x4d8));
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar3) {
              *piVar1 = *piVar1 + 1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          lVar4 = *(long *)(lVar5 + 0x10) + -1;
          *(int *)(lVar5 + 0x10) = (int)lVar4;
          if ((lVar4 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
            preempt_schedule_notrace();
          }
        }
        goto LAB_0010709c;
      }
      iVar7 = -0x10;
    }
    rmnet_descriptor_deinit(plVar8);
    kfree(plVar8);
  }
  return iVar7;
}



//------------------------------------------------------------
// rmnet_del_bridge @ 001070ec size=108
// signature: undefined rmnet_del_bridge(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_del_bridge(long param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(code **)(*(long *)(param_1 + 0xa48) + 0x330) == rmnet_rx_handler) {
    lVar2 = *(long *)(*(long *)(param_1 + 0xa48) + 0x338);
  }
  else {
    lVar2 = 0;
  }
  *(undefined8 *)(lVar2 + 0x808) = 0;
  uVar1 = 0;
  *(undefined1 *)(lVar2 + 0xd) = 1;
  if (*(code **)(param_2 + 0x330) == rmnet_rx_handler) {
    uVar1 = *(undefined8 *)(param_2 + 0x338);
  }
  rmnet_unregister_real_device(param_2,uVar1);
  return 0;
}



//------------------------------------------------------------
// rmnet_unregister_real_device @ 00107158 size=168
// signature: undefined rmnet_unregister_real_device(void)
// callers: [rmnet_del_bridge, rmnet_newlink, rmnet_config_notify_cb, rmnet_dellink]
//------------------------------------------------------------

void rmnet_unregister_real_device(long param_1,long param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  
  if (*(char *)(param_2 + 0xc) == '\0') {
    netdev_rx_handler_unregister();
    rmnet_map_cmd_exit(param_2);
    rmnet_map_tx_aggregate_exit(param_2);
    rmnet_descriptor_deinit(param_2);
    kfree(param_2);
    if (param_1 != 0) {
      lVar5 = sp_el0;
      *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
      lVar4 = tpidr_el1;
      piVar1 = (int *)(lVar4 + *(long *)(param_1 + 0x4d8));
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar3) {
          *piVar1 = *piVar1 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar4 = *(long *)(lVar5 + 0x10) + -1;
      *(int *)(lVar5 + 0x10) = (int)lVar4;
      if ((lVar4 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_qmi_pt @ 00107204 size=12
// signature: undefined rmnet_get_qmi_pt(void)
// callers: [qmi_rmnet_change_link, qmi_rmnet_pm_notify_cb, qmi_rmnet_work_init, qmi_rmnet_work_maybe_restart, qmi_rmnet_check_stats, qmi_rmnet_set_dl_msg_active, dfc_svc_init, wda_svc_config, qmi_rmnet_check_stats_2, qmi_rmnet_set_powersave_mode, qmi_rmnet_work_exit, qmi_rmnet_ignore_grant]
//------------------------------------------------------------

undefined8 rmnet_get_qmi_pt(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0x9d8);
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_get_qos_pt @ 00107214 size=12
// signature: undefined rmnet_get_qos_pt(void)
// callers: [qmi_rmnet_change_link, qmi_rmnet_enable_all_flows, qmi_rmnet_all_flows_enabled, qmi_rmnet_prepare_ps_bearers, dfc_handle_tx_link_status_ind, ll_qmap_cmd_handler, rmnet_ll_switch, qmi_rmnet_del_flow, qmi_rmnet_get_flow_state, dfc_send_ack, qmi_rmnet_burst_fc_check, qmi_rmnet_get_queue, dfc_do_burst_flow_control, dfc_qmap_cmd_handler]
//------------------------------------------------------------

undefined8 rmnet_get_qos_pt(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined8 *)(param_1 + 0xc20);
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_get_rmnet_port @ 00107224 size=44
// signature: undefined rmnet_get_rmnet_port(void)
// callers: [rmnet_vnd_start_xmit]
//------------------------------------------------------------

undefined8 rmnet_get_rmnet_port(long param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (*(code **)(*(long *)(param_1 + 0xa48) + 0x330) != rmnet_rx_handler) {
      return 0;
    }
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0xa48) + 0x338);
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_get_rmnet_dev @ 00107254 size=84
// signature: undefined rmnet_get_rmnet_dev(void)
// callers: [dfc_handle_tx_link_status_ind, rmnet_qmap_get_dev, dfc_do_burst_flow_control, dfc_qmap_cmd_handler]
//------------------------------------------------------------

undefined8 rmnet_get_rmnet_dev(long param_1,uint param_2)

{
  byte *pbVar1;
  long lVar2;
  
  if (param_1 != 0) {
    lVar2 = *(long *)(param_1 + (ulong)(param_2 & 0xff) * 8 + 0x10);
    pbVar1 = (byte *)(lVar2 + -0x10);
    if (lVar2 == 0 || pbVar1 == (byte *)0x0) {
      return 0;
    }
    do {
      if ((uint)*pbVar1 == (param_2 & 0xff)) {
        return *(undefined8 *)(pbVar1 + 8);
      }
    } while ((*(long *)(pbVar1 + 0x10) != 0) &&
            (pbVar1 = (byte *)(*(long *)(pbVar1 + 0x10) + -0x10), pbVar1 != (byte *)0x0));
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_reset_qmi_pt @ 001072ac size=12
// signature: undefined rmnet_reset_qmi_pt(void)
// callers: [qmi_rmnet_change_link, __qmi_rmnet_delete_client]
//------------------------------------------------------------

void rmnet_reset_qmi_pt(long param_1)

{
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x9d8) = 0;
  }
  return;
}



//------------------------------------------------------------
// rmnet_init_qmi_pt @ 001072bc size=12
// signature: undefined rmnet_init_qmi_pt(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void rmnet_init_qmi_pt(long param_1,undefined8 param_2)

{
  if (param_1 != 0) {
    *(undefined8 *)(param_1 + 0x9d8) = param_2;
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_packets @ 001072cc size=296
// signature: undefined rmnet_get_packets(void)
// callers: [qmi_rmnet_work_init, qmi_rmnet_check_stats, qmi_rmnet_check_stats_2]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_get_packets(long param_1,long *param_2,long *param_3)

{
  long *plVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if (((param_2 != (long *)0x0) && (param_1 != 0)) && (param_3 != (long *)0x0)) {
    *param_3 = 0;
    *param_2 = 0;
    __rcu_read_lock();
    lVar6 = 0;
    do {
      lVar5 = *(long *)(param_1 + lVar6 * 8 + 0x10);
      lVar7 = lVar5 + -0x10;
      if (lVar5 != 0 && lVar7 != 0) {
        do {
          lVar5 = *(long *)(lVar7 + 8);
          if (lVar5 != 0) {
            iVar4 = 0;
            while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar4),
                  uVar3 < _nr_cpu_ids) {
              if (0x1f < (ulong)uVar3) {
                    /* WARNING: Does not return */
                pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1073f4);
                (*pcVar2)();
              }
              plVar1 = (long *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) +
                               *(long *)(lVar5 + 0xa50));
              *param_3 = *param_3 + plVar1[2];
              iVar4 = uVar3 + 1;
              *param_2 = *param_2 + *plVar1;
            }
          }
        } while ((*(long *)(lVar7 + 0x10) != 0) &&
                (lVar7 = *(long *)(lVar7 + 0x10) + -0x10, lVar7 != 0));
      }
      lVar6 = lVar6 + 1;
    } while (lVar6 != 0xff);
    __rcu_read_unlock();
  }
  return;
}



//------------------------------------------------------------
// rmnet_set_powersave_format @ 001073f8 size=20
// signature: undefined rmnet_set_powersave_format(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void rmnet_set_powersave_format(long param_1)

{
  if (param_1 != 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x8000000;
  }
  return;
}



//------------------------------------------------------------
// rmnet_clear_powersave_format @ 00107410 size=20
// signature: undefined rmnet_clear_powersave_format(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void rmnet_clear_powersave_format(long param_1)

{
  if (param_1 != 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xf7ffffff;
  }
  return;
}



//------------------------------------------------------------
// rmnet_enable_all_flows @ 00107428 size=128
// signature: undefined rmnet_enable_all_flows(void)
// callers: [qmi_rmnet_check_stats]
//------------------------------------------------------------

void rmnet_enable_all_flows(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if (param_1 != 0) {
    __rcu_read_lock();
    lVar2 = 0;
    do {
      lVar1 = *(long *)(param_1 + lVar2 * 8 + 0x10);
      lVar3 = lVar1 + -0x10;
      if (lVar1 != 0 && lVar3 != 0) {
        do {
          qmi_rmnet_enable_all_flows(*(undefined8 *)(lVar3 + 8));
          if (*(long *)(lVar3 + 0x10) == 0) break;
          lVar3 = *(long *)(lVar3 + 0x10) + -0x10;
        } while (lVar3 != 0);
      }
      lVar2 = lVar2 + 1;
    } while (lVar2 != 0xff);
    __rcu_read_unlock();
  }
  return;
}



//------------------------------------------------------------
// rmnet_all_flows_enabled @ 001074ac size=160
// signature: undefined rmnet_all_flows_enabled(void)
// callers: [qmi_rmnet_check_stats]
//------------------------------------------------------------

bool rmnet_all_flows_enabled(long param_1)

{
  ulong uVar1;
  long lVar2;
  bool bVar3;
  ulong uVar4;
  long lVar5;
  
  if (param_1 == 0) {
    bVar3 = true;
  }
  else {
    __rcu_read_lock();
    bVar3 = false;
    uVar4 = 0;
    do {
      lVar2 = *(long *)(param_1 + uVar4 * 8 + 0x10);
      lVar5 = lVar2 + -0x10;
      if (lVar2 != 0 && lVar5 != 0) {
        do {
          uVar1 = qmi_rmnet_all_flows_enabled(*(undefined8 *)(lVar5 + 8));
          if ((uVar1 & 1) == 0) goto LAB_00107528;
        } while ((*(long *)(lVar5 + 0x10) != 0) &&
                (lVar5 = *(long *)(lVar5 + 0x10) + -0x10, lVar5 != 0));
      }
      uVar1 = uVar4 + 1;
      bVar3 = 0xfd < uVar4;
      uVar4 = uVar1;
    } while (uVar1 != 0xff);
LAB_00107528:
    __rcu_read_unlock();
  }
  return bVar3;
}



//------------------------------------------------------------
// rmnet_prepare_ps_bearers @ 00107550 size=248
// signature: undefined rmnet_prepare_ps_bearers(void)
// callers: [qmi_rmnet_pm_notify_cb, qmi_rmnet_check_stats_2]
//------------------------------------------------------------

void rmnet_prepare_ps_bearers(long param_1,byte *param_2,long param_3)

{
  long lVar1;
  byte bVar2;
  byte bVar3;
  long lVar4;
  long lVar5;
  byte local_5c [4];
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_5c[0] = 0;
  if ((param_1 != 0) && (param_2 != (byte *)0x0)) {
    bVar2 = *param_2;
    __rcu_read_lock();
    lVar4 = 0;
    bVar3 = 0;
    do {
      lVar1 = *(long *)(param_1 + lVar4 * 8 + 0x10);
      lVar5 = lVar1 + -0x10;
      if (lVar1 != 0 && lVar5 != 0) {
        do {
          lVar1 = 0;
          if (param_3 != 0) {
            lVar1 = param_3 + (ulong)bVar3;
          }
          local_5c[0] = bVar2;
          qmi_rmnet_prepare_ps_bearers(*(undefined8 *)(lVar5 + 8),local_5c,lVar1);
          bVar3 = local_5c[0] + bVar3;
          bVar2 = bVar2 - local_5c[0];
        } while ((*(long *)(lVar5 + 0x10) != 0) &&
                (lVar5 = *(long *)(lVar5 + 0x10) + -0x10, lVar5 != 0));
      }
      lVar4 = lVar4 + 1;
    } while (lVar4 != 0xff);
    __rcu_read_unlock();
    *param_2 = bVar3;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_powersave_notif @ 0010764c size=16
// signature: undefined rmnet_get_powersave_notif(void)
// callers: [qmi_rmnet_pm_notify_cb, qmi_rmnet_check_stats, qmi_rmnet_check_stats_2]
//------------------------------------------------------------

uint rmnet_get_powersave_notif(long param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0x4000000;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_get_real_dev @ 00107660 size=12
// signature: undefined rmnet_get_real_dev(void)
// callers: [rmnet_qmap_init]
//------------------------------------------------------------

undefined8 rmnet_get_real_dev(undefined8 *param_1)

{
  undefined8 uVar1;
  
  uVar1 = 0;
  if (param_1 != (undefined8 *)0x0) {
    uVar1 = *param_1;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_get_dlmarker_info @ 00107670 size=16
// signature: undefined rmnet_get_dlmarker_info(void)
// callers: [wda_svc_config]
//------------------------------------------------------------

uint rmnet_get_dlmarker_info(long param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 8) & 0x60000000;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_config_notify_cb @ 00107684 size=640
// signature: undefined rmnet_config_notify_cb(void)
// callers: []
//------------------------------------------------------------

void rmnet_config_notify_cb(undefined8 param_1,long param_2,long *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  undefined1 *puVar10;
  long *plVar11;
  long *local_70;
  undefined8 *****local_68;
  undefined8 *****pppppuStack_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  lVar8 = *param_3;
  if (lVar8 != 0) {
    if (param_2 == 2) {
      rmnet_vnd_reset_mac_addr(lVar8);
    }
    else if (param_2 == 6) {
      if (*(undefined1 **)(lVar8 + 0x8d8) == &rmnet_link_ops) {
        netdev_rx_handler_unregister(lVar8);
      }
      else {
        local_68 = &local_68;
        local_70 = (long *)0x0;
        pppppuStack_60 = local_68;
        if (*(code **)(lVar8 + 0x330) == rmnet_rx_handler) {
          iVar2 = rtnl_is_locked();
          if ((iVar2 == 0) && ((rmnet_force_unassociate_device___already_done & 1) == 0)) {
            rmnet_force_unassociate_device___already_done = 1;
            __warn_printk("RTNL: assertion failed at %s (%d)\n",
                          "../vendor/qcom/opensource/datarmnet/core/rmnet_config.c",0x13a);
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x800,0x107900);
            (*pcVar1)();
          }
          lVar9 = *(long *)(lVar8 + 0x338);
          qmi_rmnet_qmi_exit(*(undefined8 *)(lVar9 + 0x9d8),lVar9);
          if (*(char *)(lVar9 + 0xd) == '\x02') {
            lVar4 = *(long *)(*(long *)(lVar9 + 0x808) + 0x338);
            if (*(char *)(lVar9 + 0xc) == '\0') {
              *(undefined8 *)(lVar4 + 0x808) = 0;
              *(undefined1 *)(lVar4 + 0xd) = 1;
            }
            else {
              rmnet_unregister_real_device();
            }
          }
          lVar4 = 0;
          do {
            lVar5 = *(long *)(lVar9 + lVar4 * 8 + 0x10);
            puVar10 = (undefined1 *)(lVar5 + -0x10);
            if (lVar5 != 0 && puVar10 != (undefined1 *)0x0) {
              do {
                plVar11 = (long *)(puVar10 + 0x10);
                lVar5 = *plVar11;
                unregister_netdevice_queue(*(undefined8 *)(puVar10 + 8),&local_68);
                rmnet_vnd_dellink(*puVar10,lVar9,puVar10);
                plVar6 = *(long **)(puVar10 + 0x18);
                if (plVar6 != (long *)0x0) {
                  lVar7 = *plVar11;
                  *plVar6 = lVar7;
                  if (lVar7 != 0) {
                    *(long **)(lVar7 + 8) = plVar6;
                  }
                  *(undefined8 *)(puVar10 + 0x18) = 0;
                }
                *plVar11 = (long)local_70;
                if (local_70 != (long *)0x0) {
                  local_70[1] = (long)plVar11;
                }
                *(long ***)(puVar10 + 0x18) = &local_70;
                local_70 = plVar11;
              } while ((lVar5 != 0) &&
                      (puVar10 = (undefined1 *)(lVar5 + -0x10), puVar10 != (undefined1 *)0x0));
            }
            lVar4 = lVar4 + 1;
          } while (lVar4 != 0xff);
          synchronize_rcu();
          if (local_70 != (long *)0x0) {
            plVar6 = local_70 + -2;
            while (plVar6 != (long *)0x0) {
              lVar4 = plVar6[2];
              plVar11 = (long *)plVar6[3];
              *plVar11 = lVar4;
              if (lVar4 == 0) {
                plVar6[2] = -0x2152ffffffffff00;
                plVar6[3] = -0x2152fffffffffede;
                kfree();
                break;
              }
              *(long **)(lVar4 + 8) = plVar11;
              plVar6[2] = -0x2152ffffffffff00;
              plVar6[3] = -0x2152fffffffffede;
              kfree();
              plVar6 = (long *)(lVar4 + -0x10);
            }
          }
          unregister_netdevice_many(&local_68);
          qmi_rmnet_qos_exit_post();
          rmnet_unregister_real_device(lVar8,lVar9);
        }
      }
    }
    else if (((param_2 == 5) && (*(undefined1 **)(lVar8 + 0x8d8) == &rmnet_link_ops)) &&
            (iVar2 = netdev_rx_handler_register(lVar8,rmnet_rx_priv_handler,0), iVar2 != 0)) {
      uVar3 = 0x8002;
      goto LAB_001078a8;
    }
  }
  uVar3 = 0;
LAB_001078a8:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_frag_descriptor @ 00107934 size=184
// signature: undefined rmnet_get_frag_descriptor(void)
// callers: [rmnet_frag_deaggregate, __rmnet_frag_segment_data]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * rmnet_get_frag_descriptor(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0xb28);
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0xb20);
  plVar4 = (long *)*plVar5;
  if (plVar4 == plVar5) {
    plVar4 = (long *)kmalloc_trace(_rtnl_is_locked,0xb20,0x58);
    if (plVar4 != (long *)0x0) {
      *plVar4 = (long)plVar4;
      plVar4[1] = (long)plVar4;
      plVar4[2] = (long)(plVar4 + 2);
      plVar4[3] = (long)(plVar4 + 2);
      *(int *)(plVar5 + 2) = (int)plVar5[2] + 1;
    }
  }
  else {
    uVar3 = __list_del_entry_valid(plVar4);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar4;
      plVar5 = (long *)plVar4[1];
      *(long **)(lVar1 + 8) = plVar5;
      *plVar5 = lVar1;
    }
    *plVar4 = (long)plVar4;
    plVar4[1] = (long)plVar4;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0xb20,uVar2);
  return plVar4;
}



//------------------------------------------------------------
// rmnet_recycle_frag_descriptor @ 001079f0 size=384
// signature: undefined rmnet_recycle_frag_descriptor(void)
// callers: [rmnet_frag_trim, rmnet_frag_process_next_hdr_packet, rmnet_frag_deliver, rmnet_frag_deaggregate, __rmnet_frag_segment_data, rmnet_frag_ingress_handler, rmnet_frag_pull]
//------------------------------------------------------------

void rmnet_recycle_frag_descriptor(long *param_1,long param_2)

{
  int *piVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  ulong uVar7;
  long lVar8;
  undefined8 uVar9;
  long lVar10;
  long *plVar11;
  undefined8 *puVar12;
  long *plVar13;
  
  lVar10 = *(long *)(param_2 + 0xb28);
  uVar7 = __list_del_entry_valid();
  if ((uVar7 & 1) != 0) {
    lVar8 = *param_1;
    plVar2 = (long *)param_1[1];
    *(long **)(lVar8 + 8) = plVar2;
    *plVar2 = lVar8;
  }
  plVar11 = param_1 + 2;
  *param_1 = -0x2152ffffffffff00;
  param_1[1] = -0x2152fffffffffede;
  plVar2 = (long *)*plVar11;
  while (plVar2 != plVar11) {
    lVar8 = plVar2[2];
    plVar13 = (long *)*plVar2;
    if (lVar8 != 0) {
      if ((*(ulong *)(lVar8 + 8) & 1) != 0) {
        lVar8 = *(ulong *)(lVar8 + 8) - 1;
      }
      piVar1 = (int *)(lVar8 + 0x34);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar4 = *piVar1;
        cVar5 = '\x01';
        bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar6) {
          *piVar1 = iVar4 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar4 + -1 == 0) {
        __folio_put();
      }
    }
    uVar7 = __list_del_entry_valid(plVar2);
    if ((uVar7 & 1) != 0) {
      lVar8 = *plVar2;
      plVar3 = (long *)plVar2[1];
      *(long **)(lVar8 + 8) = plVar3;
      *plVar3 = lVar8;
    }
    *plVar2 = -0x2152ffffffffff00;
    plVar2[1] = -0x2152fffffffffede;
    kfree(plVar2);
    plVar2 = plVar13;
  }
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  *param_1 = (long)param_1;
  param_1[1] = (long)param_1;
  param_1[2] = (long)(param_1 + 2);
  param_1[3] = (long)plVar11;
  uVar9 = _raw_spin_lock_irqsave(param_2 + 0xb20);
  puVar12 = *(undefined8 **)(lVar10 + 8);
  uVar7 = __list_add_valid(param_1,puVar12,lVar10);
  if ((uVar7 & 1) != 0) {
    *(long **)(lVar10 + 8) = param_1;
    *param_1 = lVar10;
    param_1[1] = (long)puVar12;
    *puVar12 = param_1;
  }
  _raw_spin_unlock_irqrestore(param_2 + 0xb20,uVar9);
  return;
}



//------------------------------------------------------------
// rmnet_frag_pull @ 00107ba4 size=412
// signature: undefined rmnet_frag_pull(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_deliver, rmnet_frag_ingress_handler]
//------------------------------------------------------------

long rmnet_frag_pull(long param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  
  if (param_3 < *(uint *)(param_1 + 0x30)) {
    plVar10 = (long *)(param_1 + 0x10);
    plVar9 = (long *)*plVar10;
    while( true ) {
      if ((plVar9 == plVar10) || (param_3 == 0)) goto LAB_00107ce4;
      uVar3 = *(uint *)(plVar9 + 3);
      if (param_3 < uVar3) break;
      lVar7 = plVar9[2];
      plVar11 = (long *)*plVar9;
      if (lVar7 != 0) {
        if ((*(ulong *)(lVar7 + 8) & 1) != 0) {
          lVar7 = *(ulong *)(lVar7 + 8) - 1;
        }
        piVar1 = (int *)(lVar7 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar4 = *piVar1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar6) {
            *piVar1 = iVar4 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar4 + -1 == 0) {
          __folio_put();
        }
      }
      uVar8 = __list_del_entry_valid(plVar9);
      if ((uVar8 & 1) != 0) {
        lVar7 = *plVar9;
        plVar2 = (long *)plVar9[1];
        *(long **)(lVar7 + 8) = plVar2;
        *plVar2 = lVar7;
      }
      *plVar9 = -0x2152ffffffffff00;
      plVar9[1] = -0x2152fffffffffede;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - uVar3;
      kfree(plVar9);
      plVar9 = plVar11;
      param_3 = param_3 - uVar3;
    }
    *(uint *)(plVar9 + 3) = uVar3 - param_3;
    *(uint *)((long)plVar9 + 0x1c) = *(int *)((long)plVar9 + 0x1c) + param_3;
    *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - param_3;
LAB_00107ce4:
    plVar9 = (long *)*plVar10;
    lVar7 = 0;
    if ((plVar9 != plVar10) && (plVar9 != (long *)0x0)) {
      lVar7 = ((plVar9[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
              (ulong)*(uint *)((long)plVar9 + 0x1c);
    }
  }
  else {
    _printk(&DAT_00120d38,"rmnet_frag_pull");
    rmnet_recycle_frag_descriptor(param_1,param_2);
    lVar7 = 0;
  }
  return lVar7;
}



//------------------------------------------------------------
// rmnet_frag_trim @ 00107d74 size=408
// signature: undefined rmnet_frag_trim(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_ingress_handler]
//------------------------------------------------------------

long rmnet_frag_trim(long param_1,undefined8 param_2,uint param_3)

{
  int *piVar1;
  long *plVar2;
  long *plVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  
  if (param_3 == 0) {
    _printk(&DAT_001211c9,"rmnet_frag_trim");
    rmnet_recycle_frag_descriptor(param_1,param_2);
    lVar10 = 0;
  }
  else {
    uVar8 = *(uint *)(param_1 + 0x30) - param_3;
    if (param_3 <= *(uint *)(param_1 + 0x30) && uVar8 != 0) {
      plVar11 = *(long **)(param_1 + 0x18);
      while( true ) {
        if ((plVar11 == (long *)(param_1 + 0x10)) || (uVar8 == 0)) goto LAB_00107eb0;
        uVar4 = *(uint *)(plVar11 + 3);
        if (uVar8 < uVar4) break;
        plVar2 = (long *)plVar11[1];
        lVar10 = plVar11[2];
        if (lVar10 != 0) {
          if ((*(ulong *)(lVar10 + 8) & 1) != 0) {
            lVar10 = *(ulong *)(lVar10 + 8) - 1;
          }
          piVar1 = (int *)(lVar10 + 0x34);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar5 = *piVar1;
            cVar6 = '\x01';
            bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar7) {
              *piVar1 = iVar5 + -1;
              cVar6 = ExclusiveMonitorsStatus();
            }
          } while (cVar6 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar5 + -1 == 0) {
            __folio_put();
          }
        }
        uVar9 = __list_del_entry_valid(plVar11);
        if ((uVar9 & 1) != 0) {
          lVar10 = *plVar11;
          plVar3 = (long *)plVar11[1];
          *(long **)(lVar10 + 8) = plVar3;
          *plVar3 = lVar10;
        }
        *plVar11 = -0x2152ffffffffff00;
        plVar11[1] = -0x2152fffffffffede;
        *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - uVar4;
        kfree(plVar11);
        uVar8 = uVar8 - uVar4;
        plVar11 = plVar2;
      }
      *(uint *)(plVar11 + 3) = uVar4 - uVar8;
      *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) - uVar8;
    }
LAB_00107eb0:
    plVar11 = *(long **)(param_1 + 0x10);
    lVar10 = 0;
    if ((plVar11 != (long *)(param_1 + 0x10)) && (plVar11 != (long *)0x0)) {
      lVar10 = ((plVar11[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)((long)plVar11 + 0x1c);
    }
  }
  return lVar10;
}



//------------------------------------------------------------
// rmnet_frag_header_ptr @ 00107f40 size=368
// signature: undefined rmnet_frag_header_ptr(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_command, rmnet_frag_ipv6_skip_exthdr, __rmnet_frag_segment_data, rmnet_frag_ingress_handler, rmnet_frag_flow_command]
//------------------------------------------------------------

long rmnet_frag_header_ptr(long param_1,uint param_2,uint param_3,long param_4)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  uint uVar4;
  long *plVar5;
  long *plVar6;
  ulong uVar7;
  
  uVar4 = *(uint *)(param_1 + 0x30);
  if ((uVar4 < param_3 + param_2 || uVar4 < param_2) || uVar4 < param_3) {
    lVar3 = 0;
  }
  else {
    plVar6 = (long *)(param_1 + 0x10);
    uVar1 = param_2;
    for (plVar5 = (long *)*plVar6; plVar5 != plVar6; plVar5 = (long *)*plVar5) {
      uVar2 = *(uint *)(plVar5 + 3);
      if (uVar1 < uVar2) {
        if (uVar1 + param_3 <= uVar2) {
          return ((plVar5[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                 (ulong)*(uint *)((long)plVar5 + 0x1c) + (ulong)uVar1;
        }
        uVar4 = *(uint *)(param_1 + 0x30);
        break;
      }
      uVar1 = uVar1 - uVar2;
    }
    lVar3 = 0;
    if (((param_3 + param_2 <= uVar4) && (param_2 <= uVar4)) && (param_3 <= uVar4)) {
      if ((param_3 != 0) && (plVar5 = (long *)*plVar6, plVar5 != plVar6)) {
        uVar7 = 0;
        do {
          uVar4 = *(uint *)(plVar5 + 3);
          if (param_2 < uVar4) {
            uVar1 = param_3;
            if (uVar4 - param_2 <= param_3) {
              uVar1 = uVar4 - param_2;
            }
            memcpy((void *)(param_4 + uVar7),
                   (void *)(((plVar5[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                            (ulong)*(uint *)((long)plVar5 + 0x1c) + (ulong)param_2),(ulong)uVar1);
            uVar7 = (ulong)(uVar1 + (int)uVar7);
            param_3 = param_3 - uVar1;
            param_2 = 0;
          }
          else {
            param_2 = param_2 - uVar4;
          }
          plVar5 = (long *)*plVar5;
        } while ((plVar5 != plVar6) && (param_3 != 0));
      }
      lVar3 = param_4;
    }
  }
  return lVar3;
}



//------------------------------------------------------------
// rmnet_frag_descriptor_add_frag @ 001080c4 size=224
// signature: undefined rmnet_frag_descriptor_add_frag(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_frag_descriptor_add_frag(long param_1,long param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long *plVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 *puVar8;
  
  plVar4 = (long *)kmalloc_trace(___stack_chk_fail,0xb20,0x20);
  if (plVar4 == (long *)0x0) {
    uVar6 = 0xfffffff4;
  }
  else {
    *plVar4 = (long)plVar4;
    plVar4[1] = (long)plVar4;
    lVar7 = param_2;
    if ((*(ulong *)(param_2 + 8) & 1) != 0) {
      lVar7 = *(ulong *)(param_2 + 8) - 1;
    }
    piVar1 = (int *)(lVar7 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    plVar4[2] = param_2;
    puVar8 = *(undefined8 **)(param_1 + 0x18);
    *(int *)(plVar4 + 3) = param_4;
    *(undefined4 *)((long)plVar4 + 0x1c) = param_3;
    uVar5 = __list_add_valid(plVar4,puVar8,param_1 + 0x10);
    if ((uVar5 & 1) != 0) {
      *(long **)(param_1 + 0x18) = plVar4;
      *plVar4 = param_1 + 0x10;
      plVar4[1] = (long)puVar8;
      *puVar8 = plVar4;
    }
    uVar6 = 0;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + param_4;
  }
  return uVar6;
}



//------------------------------------------------------------
// rmnet_frag_descriptor_add_frags_from @ 001081b4 size=360
// signature: undefined rmnet_frag_descriptor_add_frags_from(void)
// callers: [__rmnet_frag_segment_data]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_frag_descriptor_add_frags_from(long param_1,long param_2,uint param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  undefined8 uVar7;
  long *plVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  undefined8 *puVar12;
  long *plVar13;
  long lVar14;
  
  uVar3 = *(uint *)(param_2 + 0x30);
  if ((uVar3 < param_4 + param_3 || uVar3 < param_3) || uVar3 < param_4) {
    uVar7 = 0xffffffea;
  }
  else {
    uVar7 = 0;
    plVar11 = (long *)(param_2 + 0x10);
    plVar13 = (long *)*plVar11;
    if ((plVar13 != plVar11) && (param_4 != 0)) {
      do {
        uVar3 = *(uint *)(plVar13 + 3);
        if (param_3 < uVar3) {
          uVar2 = param_4;
          if (uVar3 - param_3 <= param_4) {
            uVar2 = uVar3 - param_3;
          }
          lVar14 = plVar13[2];
          iVar4 = *(int *)((long)plVar13 + 0x1c);
          plVar8 = (long *)kmalloc_trace(___stack_chk_fail,0xb20,0x20);
          if (plVar8 == (long *)0x0) {
            return 0xfffffff4;
          }
          *plVar8 = (long)plVar8;
          plVar8[1] = (long)plVar8;
          lVar10 = lVar14;
          if ((*(ulong *)(lVar14 + 8) & 1) != 0) {
            lVar10 = *(ulong *)(lVar14 + 8) - 1;
          }
          piVar1 = (int *)(lVar10 + 0x34);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            cVar5 = '\x01';
            bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar6) {
              *piVar1 = *piVar1 + 1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          puVar12 = *(undefined8 **)(param_1 + 0x18);
          plVar8[2] = lVar14;
          *(uint *)(plVar8 + 3) = uVar2;
          *(uint *)((long)plVar8 + 0x1c) = iVar4 + param_3;
          uVar9 = __list_add_valid(plVar8,puVar12,param_1 + 0x10);
          if ((uVar9 & 1) != 0) {
            *(long **)(param_1 + 0x18) = plVar8;
            *plVar8 = param_1 + 0x10;
            plVar8[1] = (long)puVar12;
            *puVar12 = plVar8;
          }
          param_4 = param_4 - uVar2;
          *(uint *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + uVar2;
          param_3 = 0;
        }
        else {
          param_3 = param_3 - uVar3;
        }
        plVar13 = (long *)*plVar13;
        if (plVar13 == plVar11) {
          return 0;
        }
      } while (param_4 != 0);
      return 0;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// rmnet_frag_ipv6_skip_exthdr @ 0010832c size=344
// signature: undefined rmnet_frag_ipv6_skip_exthdr(void)
// callers: []
//------------------------------------------------------------

int rmnet_frag_ipv6_skip_exthdr
              (undefined8 param_1,int param_2,char *param_3,ushort *param_4,undefined1 *param_5)

{
  ulong uVar1;
  char *pcVar2;
  ushort *puVar3;
  int iVar4;
  long lVar5;
  char cVar6;
  undefined2 local_64 [2];
  undefined2 local_60 [4];
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  cVar6 = *param_3;
  *param_4 = 0;
  *param_5 = 0;
  uVar1 = ipv6_ext_hdr(cVar6);
  while ((uVar1 & 1) != 0) {
    local_60[0] = 0;
    if ((cVar6 == ';') ||
       (pcVar2 = (char *)rmnet_frag_header_ptr(param_1,param_2,2,local_60), pcVar2 == (char *)0x0))
    {
LAB_00108444:
      param_2 = -0x16;
      goto LAB_00108448;
    }
    if (cVar6 == '3') {
      lVar5 = 2;
LAB_00108390:
      iVar4 = ((uint)(byte)pcVar2[1] << lVar5) + 8;
    }
    else {
      if (cVar6 != ',') {
        lVar5 = 3;
        goto LAB_00108390;
      }
      local_64[0] = 0;
      puVar3 = (ushort *)rmnet_frag_header_ptr(param_1,param_2 + 2,2,local_64);
      if (puVar3 == (ushort *)0x0) goto LAB_00108444;
      *param_4 = *puVar3;
      *param_5 = 1;
      cVar6 = ',';
      if (7 < (ushort)(*param_4 >> 8 | *param_4 << 8)) break;
      iVar4 = 8;
    }
    cVar6 = *pcVar2;
    param_2 = iVar4 + param_2;
    uVar1 = ipv6_ext_hdr(cVar6);
  }
  *param_3 = cVar6;
LAB_00108448:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_2;
}



//------------------------------------------------------------
// rmnet_frag_command @ 00108488 size=420
// signature: undefined rmnet_frag_command(void)
// callers: [rmnet_frag_ingress_handler]
//------------------------------------------------------------

void rmnet_frag_command(undefined8 param_1,long param_2,long *param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  pcVar2 = (char *)rmnet_frag_header_ptr(param_1,4,0x10,&local_38);
  if (pcVar2 != (char *)0x0) {
    if (*pcVar2 == '\x01') {
      if ((*(char *)(param_2 + 1) == -1) || (lVar3 = rmnet_get_endpoint(param_3), lVar3 == 0))
      goto LAB_00108608;
      iVar1 = rmnet_vnd_do_flow_control(*(undefined8 *)(lVar3 + 8),0);
    }
    else {
      if (((*pcVar2 != '\x02') || (*(char *)(param_2 + 1) == -1)) ||
         (lVar3 = rmnet_get_endpoint(param_3), lVar3 == 0)) goto LAB_00108608;
      iVar1 = rmnet_vnd_do_flow_control(*(undefined8 *)(lVar3 + 8),1);
    }
    if (iVar1 == 0) {
      lVar6 = *param_3;
      lVar3 = __alloc_skb((*(ushort *)(param_2 + 2) >> 8 | *(ushort *)(param_2 + 2) << 8) + 4,0xa20,
                          0,0xffffffff);
      if (lVar3 != 0) {
        *(long *)(lVar3 + 0x10) = lVar6;
        *(undefined2 *)(lVar3 + 0xb4) = 0xf900;
        if ((*(int *)(lVar3 + 0x74) == 0) || (*(int *)(lVar3 + 0x70) != *(int *)(lVar3 + 0x74))) {
          lVar4 = *(long *)(lVar3 + 0xe0);
        }
        else {
          lVar4 = *(long *)(lVar3 + 0xd8) + (ulong)*(uint *)(lVar3 + 0xd4);
          lVar4 = ((*(ulong *)(lVar4 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                  (ulong)*(uint *)(lVar4 + 0x54);
        }
        *(byte *)(lVar4 + 5) = *(byte *)(lVar4 + 5) & 0xfc | 1;
        netif_tx_lock(lVar6);
        pcVar5 = *(code **)(*(long *)(lVar6 + 0xd0) + 0x20);
        if (*(int *)(pcVar5 + -4) != 0x44e57e43) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1085fc);
          (*pcVar5)();
        }
        (*pcVar5)(lVar3,lVar6);
        netif_tx_unlock(lVar6);
      }
    }
  }
LAB_00108608:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_frag_flow_command @ 00108638 size=532
// signature: undefined rmnet_frag_flow_command(void)
// callers: [rmnet_frag_ingress_handler]
//------------------------------------------------------------

void rmnet_frag_flow_command(long param_1,long param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  undefined8 uVar5;
  uint *puVar6;
  long lVar7;
  uint uVar8;
  undefined8 local_50;
  ulong local_48 [3];
  
  lVar7 = sp_el0;
  local_48[2] = *(long *)(lVar7 + 0x638);
  local_50 = 0;
  pbVar4 = (byte *)rmnet_frag_header_ptr(param_1,4,8,&local_50);
  if (pbVar4 == (byte *)0x0) {
    uVar5 = 0xffffffff;
  }
  else {
    uVar8 = (uint)*pbVar4;
    if ((*(int *)(param_1 + 0x38) != 0xda1a) || (1 < uVar8 - 7)) {
      if (uVar8 == 0x23) {
        local_48[0] = 0;
        local_48[1] = 0;
        if (0x17 < param_3) {
          uVar8 = *(uint *)(param_2 + 8);
          lVar7 = rmnet_frag_header_ptr(param_1,0xc,0x10,local_48);
          if (lVar7 != 0) {
            *(long *)(param_2 + 0xac8) = *(long *)(param_2 + 0xac8) + 1;
            if ((uVar8 >> 0x1d & 1) != 0) {
              rmnet_map_pb_ind_notify(param_2,lVar7);
            }
          }
        }
      }
      else if (uVar8 == 8) {
        local_48[0] = local_48[0] & 0xffffffff00000000;
        if (0xb < param_3) {
          uVar8 = *(uint *)(param_2 + 8);
          puVar6 = (uint *)rmnet_frag_header_ptr(param_1,0xc,4,local_48);
          if (puVar6 != (uint *)0x0) {
            *(ulong *)(param_2 + 0xa40) = (ulong)*puVar6;
            *(long *)(param_2 + 0xa48) = *(long *)(param_2 + 0xa48) + 1;
            if ((uVar8 >> 0x1d & 1) != 0) {
              rmnet_map_dl_trl_notify_v2(param_2,puVar6,pbVar4);
            }
          }
        }
      }
      else {
        if (uVar8 != 7) {
          uVar5 = 1;
          goto LAB_001086b0;
        }
        local_48[0] = 0;
        local_48[1] = 0;
        if (0x17 < param_3) {
          uVar8 = *(uint *)(param_2 + 8);
          puVar6 = (uint *)rmnet_frag_header_ptr(param_1,0xc,0x10,local_48);
          if (puVar6 != (uint *)0x0) {
            *(ulong *)(param_2 + 0x9f8) = (ulong)*(ushort *)(pbVar4 + 2) & 0x7fff;
            *(ulong *)(param_2 + 0x9f0) = (ulong)(*(ushort *)(pbVar4 + 1) >> 2) & 0x1f;
            *(ulong *)(param_2 + 0xa00) = (ulong)*(uint *)(pbVar4 + 4);
            *(ulong *)(param_2 + 0xa08) = (ulong)*puVar6;
            uVar1 = puVar6[1];
            *(ulong *)(param_2 + 0xa10) = (ulong)uVar1;
            uVar2 = puVar6[2];
            *(ulong *)(param_2 + 0xa18) = (ulong)uVar2;
            uVar3 = puVar6[3];
            *(ulong *)(param_2 + 0xa30) = *(long *)(param_2 + 0xa30) + (ulong)uVar1;
            *(ulong *)(param_2 + 0xa38) = *(long *)(param_2 + 0xa38) + (ulong)uVar2;
            *(ulong *)(param_2 + 0xa20) = (ulong)uVar3;
            *(long *)(param_2 + 0xa28) = *(long *)(param_2 + 0xa28) + 1;
            if ((uVar8 >> 0x1d & 1) != 0) {
              rmnet_map_dl_hdr_notify_v2(param_2,puVar6,pbVar4);
            }
          }
        }
      }
    }
    uVar5 = 0;
  }
LAB_001086b0:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// rmnet_frag_deaggregate @ 00108850 size=888
// signature: undefined rmnet_frag_deaggregate(void)
// callers: [rmnet_frag_ingress_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_frag_deaggregate(long param_1,long param_2,long param_3,undefined4 param_4)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  ushort uVar8;
  char cVar9;
  bool bVar10;
  uint uVar11;
  int iVar12;
  long *plVar13;
  long *plVar14;
  ulong *puVar15;
  long lVar16;
  uint uVar17;
  char *pcVar18;
  byte *pbVar19;
  ulong uVar20;
  uint uVar21;
  uint uVar22;
  ulong uVar23;
  long lVar24;
  undefined8 *puVar25;
  uint uVar26;
  uint local_78;
  byte local_74 [4];
  char local_70 [8];
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  if (*(int *)(param_1 + 0x70) != 0) {
    local_78 = 0;
    while( true ) {
      local_70[0] = '\0';
      local_70[1] = '\0';
      local_70[2] = '\0';
      local_70[3] = '\0';
      lVar4 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      bVar7 = *(byte *)(lVar4 + 2);
      if (bVar7 == 0) {
        uVar20 = 0;
        uVar17 = 0;
        puVar15 = (ulong *)0x0;
      }
      else {
        uVar20 = 0;
        puVar15 = (ulong *)(lVar4 + 0x48);
        uVar17 = 0;
        while (uVar2 = (int)puVar15[1] + uVar17, uVar2 <= local_78) {
          uVar20 = uVar20 + 1;
          puVar15 = puVar15 + 2;
          uVar17 = uVar2;
          if (bVar7 == uVar20) goto LAB_00108ba4;
        }
      }
      if ((uint)uVar20 == (uint)bVar7) break;
      iVar6 = *(int *)((long)puVar15 + 0xc);
      uVar17 = local_78 - uVar17;
      uVar2 = (int)puVar15[1] - uVar17;
      if (uVar2 < 4) {
        pcVar18 = local_70;
        iVar12 = skb_copy_bits(param_1,local_78,local_70,4);
        if (iVar12 < 0) break;
      }
      else {
        pcVar18 = (char *)(((*puVar15 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                           (ulong)*(uint *)((long)puVar15 + 0xc) + (ulong)uVar17);
      }
      uVar8 = *(ushort *)(pcVar18 + 2);
      if ((uVar8 == 0) ||
         (plVar13 = (long *)rmnet_get_frag_descriptor(param_2), plVar13 == (long *)0x0)) break;
      *(undefined4 *)(plVar13 + 7) = param_4;
      uVar21 = (uint)(uVar8 >> 8) | (uVar8 & 0xff00ff) << 8;
      if ((*(uint *)(param_2 + 8) >> 2 & 1) == 0) {
        uVar21 = uVar21 + 4;
        if (((*(uint *)(param_2 + 8) & 0x30) != 0) && (-1 < *pcVar18)) {
          local_74[0] = 0;
          if (uVar2 < 5) {
            pbVar19 = local_74;
            iVar12 = skb_copy_bits(param_1,local_78 + 4,local_74,1);
            if (iVar12 < 0) break;
          }
          else {
            pbVar19 = (byte *)(pcVar18 + 4);
          }
          iVar12 = 0x1c;
          if (*pbVar19 >> 1 != 1) {
            iVar12 = (uint)(*pbVar19 >> 1 == 2) << 2;
          }
          uVar21 = iVar12 + uVar21;
        }
      }
      else {
        uVar21 = uVar21 + 0xc;
      }
      uVar26 = 0;
      uVar23 = uVar20 & 0xffffffff;
      do {
        uVar22 = (uint)uVar23;
        if (*(byte *)(lVar4 + 2) <= uVar22) {
LAB_00108b98:
          rmnet_recycle_frag_descriptor(plVar13,param_2);
          goto LAB_00108ba4;
        }
        lVar16 = lVar4 + uVar23 * 0x10;
        lVar24 = *(long *)(lVar16 + 0x48);
        iVar12 = iVar6 + uVar17;
        uVar11 = uVar2;
        if (uVar22 != (uint)uVar20) {
          iVar12 = *(int *)(lVar16 + 0x54);
          uVar11 = *(uint *)(lVar16 + 0x50);
        }
        uVar5 = uVar11;
        if (uVar21 <= uVar11) {
          uVar5 = uVar21;
        }
        plVar14 = (long *)kmalloc_trace(___stack_chk_fail,0xb20,0x20);
        if (plVar14 == (long *)0x0) goto LAB_00108b98;
        *plVar14 = (long)plVar14;
        plVar14[1] = (long)plVar14;
        lVar16 = lVar24;
        if ((*(ulong *)(lVar24 + 8) & 1) != 0) {
          lVar16 = *(ulong *)(lVar24 + 8) - 1;
        }
        piVar1 = (int *)(lVar16 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar9 = '\x01';
          bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar10) {
            *piVar1 = *piVar1 + 1;
            cVar9 = ExclusiveMonitorsStatus();
          }
        } while (cVar9 != '\0');
        plVar14[2] = lVar24;
        *(uint *)(plVar14 + 3) = uVar5;
        *(int *)((long)plVar14 + 0x1c) = iVar12;
        puVar25 = (undefined8 *)plVar13[3];
        uVar23 = __list_add_valid(plVar14,puVar25,plVar13 + 2);
        if ((uVar23 & 1) != 0) {
          plVar13[3] = (long)plVar14;
          *plVar14 = (long)(plVar13 + 2);
          plVar14[1] = (long)puVar25;
          *puVar25 = plVar14;
        }
        uVar3 = uVar5 + uVar26;
        uVar21 = uVar21 - uVar5;
        if (uVar11 == uVar3) {
          uVar22 = uVar22 + 1;
        }
        uVar23 = (ulong)uVar22;
        uVar26 = 0;
        if (uVar11 != uVar3) {
          uVar26 = uVar3;
        }
        *(uint *)(plVar13 + 6) = (int)plVar13[6] + uVar5;
      } while (uVar21 != 0);
      plVar14 = *(long **)(param_3 + 8);
      uVar20 = __list_add_valid(plVar13,plVar14,param_3);
      if ((uVar20 & 1) != 0) {
        *(long **)(param_3 + 8) = plVar13;
        *plVar13 = param_3;
        plVar13[1] = (long)plVar14;
        *plVar14 = (long)plVar13;
      }
      if (((int)plVar13[6] < 0) ||
         (local_78 = (int)plVar13[6] + local_78, *(uint *)(param_1 + 0x70) <= local_78)) break;
    }
  }
LAB_00108ba4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_frag_deliver @ 00108be4 size=2056
// signature: undefined rmnet_frag_deliver(void)
// callers: [rmnet_frag_ingress_handler]
//------------------------------------------------------------

void rmnet_frag_deliver(long param_1,undefined8 param_2)

{
  int *piVar1;
  uint uVar2;
  long *plVar3;
  ulong uVar4;
  uint uVar5;
  byte bVar6;
  ushort uVar7;
  short sVar8;
  char cVar9;
  bool bVar10;
  code *pcVar11;
  ushort uVar12;
  uint uVar13;
  long *plVar14;
  long *plVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  ulong uVar20;
  undefined4 uVar21;
  ulong *puVar22;
  int iVar23;
  long *plVar24;
  ushort *puVar25;
  ulong *puVar26;
  long lVar27;
  long *plVar28;
  long *plVar29;
  uint uVar30;
  long *plVar31;
  
  lVar17 = sp_el0;
  lVar17 = *(long *)(lVar17 + 0x638);
  if ((*(byte *)(param_1 + 0x51) >> 1 & 1) == 0) {
    plVar14 = (long *)__alloc_skb(0x120,0xa20,0,0xffffffff);
    if (plVar14 == (long *)0x0) goto LAB_001092e8;
    plVar14[0x1c] = plVar14[0x1c] + 0x20;
    *(int *)(plVar14 + 0x1a) = (int)plVar14[0x1a] + 0x20;
LAB_00108d00:
    plVar28 = (long *)(param_1 + 0x10);
    if ((long *)*plVar28 != plVar28) {
      lVar19 = plVar14[0x1b] + (ulong)*(uint *)((long)plVar14 + 0xd4);
      plVar29 = plVar14;
      plVar31 = (long *)*plVar28;
      do {
        plVar24 = (long *)*plVar31;
        lVar27 = plVar31[2];
        iVar23 = (int)plVar31[3];
        bVar6 = *(byte *)(lVar19 + 2);
        while (0x10 < bVar6) {
          plVar15 = (long *)__alloc_skb(0,0xa20,0,0xffffffff);
          if (plVar15 == (long *)0x0) goto LAB_00108e00;
          plVar3 = (long *)(lVar19 + 8);
          if (plVar29 != plVar14) {
            plVar3 = plVar29;
          }
          *plVar3 = (long)plVar15;
          lVar19 = plVar15[0x1b] + (ulong)*(uint *)((long)plVar15 + 0xd4);
          plVar29 = plVar15;
          bVar6 = *(byte *)(lVar19 + 2);
        }
        lVar18 = lVar27;
        if ((*(ulong *)(lVar27 + 8) & 1) != 0) {
          lVar18 = *(ulong *)(lVar27 + 8) - 1;
        }
        piVar1 = (int *)(lVar18 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar9 = '\x01';
          bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar10) {
            *piVar1 = *piVar1 + 1;
            cVar9 = ExclusiveMonitorsStatus();
          }
        } while (cVar9 != '\0');
        skb_add_rx_frag(plVar29,*(undefined1 *)(lVar19 + 2),lVar27,
                        *(undefined4 *)((long)plVar31 + 0x1c),iVar23,iVar23);
        if (plVar29 != plVar14) {
          *(int *)(plVar14 + 0xe) = (int)plVar14[0xe] + iVar23;
          *(int *)((long)plVar14 + 0x74) = *(int *)((long)plVar14 + 0x74) + iVar23;
        }
        plVar31 = plVar24;
      } while (plVar24 != plVar28);
    }
  }
  else {
    uVar13 = (uint)*(ushort *)(param_1 + 0x4c) + (uint)*(ushort *)(param_1 + 0x4a) & 0xffff;
    plVar14 = (long *)__alloc_skb(uVar13 + 0x20,0xa20,0,0xffffffff);
    if (plVar14 == (long *)0x0) goto LAB_001092e8;
    plVar14[0x1c] = plVar14[0x1c] + 0x20;
    *(int *)(plVar14 + 0x1a) = (int)plVar14[0x1a] + 0x20;
    lVar19 = skb_put(plVar14,uVar13);
    if ((uVar13 <= *(uint *)(param_1 + 0x30)) && (uVar13 != 0)) {
      plVar28 = (long *)(param_1 + 0x10);
      plVar29 = (long *)*plVar28;
      if (plVar29 != plVar28) {
        uVar16 = 0;
        uVar20 = 0;
        uVar30 = uVar13;
        do {
          uVar5 = *(uint *)(plVar29 + 3);
          if (uVar16 < uVar5) {
            uVar2 = uVar30;
            if (uVar5 - uVar16 <= uVar30) {
              uVar2 = uVar5 - uVar16;
            }
            memcpy((void *)(lVar19 + uVar20),
                   (void *)(((plVar29[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                            (ulong)*(uint *)((long)plVar29 + 0x1c) + (ulong)uVar16),(ulong)uVar2);
            uVar20 = (ulong)(uVar2 + (int)uVar20);
            uVar30 = uVar30 - uVar2;
            uVar16 = 0;
          }
          else {
            uVar16 = uVar16 - uVar5;
          }
          plVar29 = (long *)*plVar29;
        } while ((plVar29 != plVar28) && (uVar30 != 0));
      }
    }
    sVar8 = (short)plVar14[0x1c] - (short)plVar14[0x1b];
    *(short *)(plVar14 + 0x17) = sVar8;
    if (*(short *)(param_1 + 0x4c) != 0) {
      *(short *)((long)plVar14 + 0xb6) = *(short *)(param_1 + 0x4a) + sVar8;
    }
    if (*(uint *)(param_1 + 0x30) != uVar13) {
      lVar19 = rmnet_frag_pull(param_1,param_2,uVar13);
      if (lVar19 == 0) {
        kfree(plVar14);
        goto LAB_001092e8;
      }
      goto LAB_00108d00;
    }
  }
LAB_00108e00:
  plVar14[2] = *(long *)(param_1 + 0x20);
  rmnet_set_skb_proto(plVar14);
  *(undefined4 *)((long)plVar14 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(plVar14 + 6) = *(undefined4 *)(param_1 + 0x28);
  bVar6 = *(byte *)(param_1 + 0x51);
  if ((bVar6 >> 2 & 1) != 0) {
    if ((*(int *)((long)plVar14 + 0x74) == 0) ||
       ((int)plVar14[0xe] != *(int *)((long)plVar14 + 0x74))) {
      lVar19 = plVar14[0x1c];
    }
    else {
      lVar19 = plVar14[0x1b] + (ulong)*(uint *)((long)plVar14 + 0xd4);
      lVar19 = ((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)(lVar19 + 0x54);
    }
    uVar7 = *(ushort *)(param_1 + 0x40);
    uVar13 = (*(ushort *)(lVar19 + 10) ^ 0xffff) + (*(ushort *)(lVar19 + 4) ^ 0xffff);
    uVar13 = uVar13 + uVar7 + (uVar13 >> 0x10);
    uVar12 = (ushort)uVar13;
    uVar13 = uVar13 & 0xffff;
    if (uVar13 <= uVar7 && uVar7 != uVar13) {
      uVar12 = uVar12 + 1;
    }
    *(ushort *)(lVar19 + 10) = ~uVar12;
    *(undefined2 *)(lVar19 + 4) = *(undefined2 *)(param_1 + 0x40);
    bVar6 = *(byte *)(param_1 + 0x51);
  }
  if ((bVar6 >> 3 & 1) != 0) {
    if ((*(int *)((long)plVar14 + 0x74) == 0) ||
       ((int)plVar14[0xe] != *(int *)((long)plVar14 + 0x74))) {
      lVar19 = plVar14[0x1c];
    }
    else {
      lVar19 = plVar14[0x1b] + (ulong)*(uint *)((long)plVar14 + 0xd4);
      lVar19 = ((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)(lVar19 + 0x54);
    }
    *(undefined4 *)(lVar19 + (ulong)*(ushort *)(param_1 + 0x4a) + 4) =
         *(undefined4 *)(param_1 + 0x3c);
    bVar6 = *(byte *)(param_1 + 0x51);
  }
  if ((bVar6 >> 5 & 1) != 0) {
    if ((*(int *)((long)plVar14 + 0x74) == 0) ||
       ((int)plVar14[0xe] != *(int *)((long)plVar14 + 0x74))) {
      lVar19 = plVar14[0x1c];
    }
    else {
      lVar19 = plVar14[0x1b] + (ulong)*(uint *)((long)plVar14 + 0xd4);
      lVar19 = ((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)(lVar19 + 0x54);
    }
    *(undefined2 *)(lVar19 + (ulong)*(ushort *)(param_1 + 0x4a) + 0xc) =
         *(undefined2 *)(param_1 + 0x42);
    bVar6 = *(byte *)(param_1 + 0x51);
  }
  if (((bVar6 ^ 0xff) & 3) == 0) {
    uVar13 = *(uint *)(plVar14 + 0xe);
    puVar26 = (ulong *)plVar14[0x1c];
    uVar30 = uVar13 - *(ushort *)(param_1 + 0x4a);
    if (*(char *)(param_1 + 0x4e) == '\x04') {
      *(undefined2 *)((long)puVar26 + 10) = 0;
      *(ushort *)((long)puVar26 + 2) =
           (ushort)(uVar13 >> 8) & 0xff | (ushort)((uVar13 & 0xff00ff) << 8);
      uVar4 = puVar26[1];
      uVar20 = *puVar26 + uVar4 + (ulong)CARRY8(uVar4,*puVar26);
      iVar23 = ((byte)*puVar26 & 0xf) - 3;
      puVar22 = puVar26 + 2;
      do {
        iVar23 = iVar23 + -1;
        uVar20 = uVar20 + (uint)*puVar22;
        puVar22 = (ulong *)((long)puVar22 + 4);
      } while (1 < iVar23);
      uVar13 = (uint)((uVar20 >> 0x20 | uVar20 << 0x20) + uVar20 >> 0x20);
      *(ushort *)((long)puVar26 + 10) =
           (ushort)((uVar13 >> 0x10 | uVar13 << 0x10) + uVar13 >> 0x10) ^ 0xffff;
      uVar13 = csum_tcpudp_nofold(uVar4 >> 0x20,(int)puVar26[2],uVar30 & 0xffff,
                                  *(undefined1 *)(param_1 + 0x4f),0);
      uVar12 = (ushort)((uVar13 >> 0x10 | uVar13 << 0x10) + uVar13 >> 0x10);
    }
    else {
      *(ushort *)((long)puVar26 + 4) =
           (ushort)(uVar13 - 0x28 >> 8) & 0xff | (ushort)((uVar13 - 0x28 & 0xff00ff) << 8);
      uVar12 = csum_ipv6_magic(puVar26 + 1,puVar26 + 3,uVar30 & 0xffff,
                               *(undefined1 *)(param_1 + 0x4f),0);
      uVar12 = ~uVar12;
    }
    lVar19 = (long)puVar26 + (ulong)*(ushort *)(param_1 + 0x4a);
    if (*(char *)(param_1 + 0x4f) == '\x06') {
      *(ushort *)(lVar19 + 0x10) = uVar12;
      *(undefined2 *)((long)plVar14 + 0x8a) = 0x10;
      if (rmnet_perf_tether_ingress_hook != (code *)0x0) {
        if (*(int *)(rmnet_perf_tether_ingress_hook + -4) != -0x47fee3e2) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x109204);
          (*pcVar11)();
        }
        (*rmnet_perf_tether_ingress_hook)(lVar19,plVar14);
      }
    }
    else {
      *(ushort *)(lVar19 + 6) = uVar12;
      *(ushort *)(lVar19 + 4) = (ushort)(uVar30 >> 8) & 0xff | (ushort)((uVar30 & 0xff00ff) << 8);
      *(undefined2 *)((long)plVar14 + 0x8a) = 6;
    }
    *(ushort *)(plVar14 + 0x10) = *(ushort *)(plVar14 + 0x10) | 0x60;
    *(short *)(plVar14 + 0x11) =
         ((short)puVar26 + *(short *)(param_1 + 0x4a)) - (short)plVar14[0x1b];
LAB_00109254:
    iVar23 = *(int *)(param_1 + 0x34);
  }
  else {
    if ((bVar6 & 1) == 0) {
      if (((bVar6 >> 1 & 1) == 0) ||
         ((*(char *)(param_1 + 0x4f) != '\x11' && (*(char *)(param_1 + 0x4f) != '\x06'))))
      goto LAB_00109254;
      iVar23 = ((int)plVar14[0x1b] + (uint)*(ushort *)((long)plVar14 + 0xb6)) - (int)plVar14[0x1c];
      uVar13 = *(uint *)(plVar14 + 0xe);
      lVar19 = plVar14[0x1b] + (ulong)*(ushort *)(plVar14 + 0x17);
      if (*(char *)(param_1 + 0x4e) == '\x04') {
        uVar12 = *(ushort *)(lVar19 + 2);
        uVar13 = (uVar13 & 0xff00ff00) >> 8 | (uVar13 & 0xff00ff) << 8;
        uVar30 = uVar13 & 0xffff;
        *(short *)(lVar19 + 2) = (short)uVar13;
        uVar13 = (*(ushort *)(lVar19 + 10) ^ 0xffff) + (uVar12 ^ 0xffff);
        uVar13 = uVar13 + uVar30 + (uVar13 >> 0x10);
        uVar12 = (ushort)uVar13;
        if ((uVar13 & 0xffff) < uVar30) {
          uVar12 = uVar12 + 1;
        }
        *(ushort *)(lVar19 + 10) = ~uVar12;
        uVar13 = csum_tcpudp_nofold(*(undefined4 *)(lVar19 + 0xc),*(undefined4 *)(lVar19 + 0x10),
                                    (int)plVar14[0xe] - (uint)*(ushort *)(param_1 + 0x4a),
                                    *(undefined1 *)(param_1 + 0x4f),0);
        uVar12 = (ushort)((uVar13 >> 0x10 | uVar13 << 0x10) + uVar13 >> 0x10) ^ 0xffff;
      }
      else {
        *(ushort *)(lVar19 + 4) =
             (ushort)(uVar13 - 0x28 >> 8) & 0xff | (ushort)((uVar13 - 0x28 & 0xff00ff) << 8);
        uVar12 = csum_ipv6_magic(lVar19 + 8,lVar19 + 0x18,
                                 (int)plVar14[0xe] - (uint)*(ushort *)(param_1 + 0x4a),
                                 *(undefined1 *)(param_1 + 0x4f),0);
      }
      if (*(char *)(param_1 + 0x4f) == '\x06') {
        puVar25 = (ushort *)(plVar14[0x1b] + (ulong)*(ushort *)((long)plVar14 + 0xb6) + 0x10);
      }
      else {
        uVar13 = (uint)*(ushort *)(plVar14 + 0xe) - (uint)*(ushort *)(param_1 + 0x4a);
        *(ushort *)(plVar14[0x1b] + (ulong)*(ushort *)((long)plVar14 + 0xb6) + 4) =
             (ushort)(uVar13 >> 8) & 0xff | (ushort)((uVar13 & 0xff00ff) << 8);
        puVar25 = (ushort *)(plVar14[0x1b] + (ulong)*(ushort *)((long)plVar14 + 0xb6) + 6);
      }
      *puVar25 = ~uVar12;
      uVar13 = skb_checksum(plVar14,iVar23,(int)plVar14[0xe] - iVar23,0);
      iVar23 = -((uVar13 >> 0x10 | uVar13 << 0x10) + uVar13 >> 0x10);
      uVar13 = iVar23 + 0xff;
      uVar12 = (ushort)uVar13;
      if ((uVar13 & 0xffff) < 0x100) {
        uVar12 = (short)iVar23 + 0x100;
      }
      *puVar25 = uVar12;
      uVar12 = *(ushort *)(plVar14 + 0x10) & 0xff9f;
    }
    else {
      uVar12 = *(ushort *)(plVar14 + 0x10) & 0xffbf | 0x20;
    }
    *(ushort *)(plVar14 + 0x10) = uVar12;
    iVar23 = *(int *)(param_1 + 0x34);
  }
  if (iVar23 != 0) {
    *(int *)((long)plVar14 + 0x94) = iVar23;
    *(ushort *)(plVar14 + 0x10) = *(ushort *)(plVar14 + 0x10) | 0x200;
  }
  if ((*(byte *)(param_1 + 0x51) >> 4 & 1) != 0) {
    *(undefined1 *)(plVar14 + 5) = 1;
  }
  if (1 < *(ushort *)(param_1 + 0x48)) {
    if (*(char *)(param_1 + 0x4f) == '\x06') {
      uVar21 = 0x10;
      if (*(char *)(param_1 + 0x4e) == '\x04') {
        uVar21 = 1;
      }
    }
    else {
      uVar21 = 0x20000;
    }
    lVar19 = plVar14[0x1b] + (ulong)*(uint *)((long)plVar14 + 0xd4);
    *(undefined4 *)(lVar19 + 0x18) = uVar21;
    *(undefined2 *)(lVar19 + 4) = *(undefined2 *)(param_1 + 0x46);
    *(undefined2 *)(lVar19 + 6) = *(undefined2 *)(param_1 + 0x48);
  }
  *(undefined4 *)((long)plVar14 + 0x8c) = *(undefined4 *)(param_1 + 0x38);
  rmnet_deliver_skb(plVar14,param_2);
LAB_001092e8:
  rmnet_recycle_frag_descriptor(param_1,param_2);
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != lVar17) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_frag_process_next_hdr_packet @ 00109730 size=3552
// signature: undefined rmnet_frag_process_next_hdr_packet(void)
// callers: [rmnet_frag_ingress_handler]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00109c9c) */

void rmnet_frag_process_next_hdr_packet
               (long *param_1,undefined8 param_2,undefined8 *param_3,undefined2 param_4)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  undefined1 uVar9;
  short sVar10;
  code *pcVar11;
  bool bVar12;
  bool bVar13;
  uint uVar14;
  short *psVar15;
  uint *puVar16;
  ulong *puVar17;
  char *pcVar18;
  long lVar19;
  byte *pbVar20;
  ushort *puVar21;
  uint uVar22;
  long lVar23;
  undefined8 uVar24;
  ulong uVar25;
  long lVar26;
  ulong *puVar27;
  int iVar28;
  undefined8 *puVar29;
  uint uVar30;
  byte bVar31;
  ushort uVar32;
  uint uVar33;
  long *plVar34;
  ulong uVar35;
  char cVar36;
  long lVar37;
  long *plVar38;
  ulong local_f0;
  undefined4 local_e0;
  ushort local_dc [2];
  ushort local_d8 [4];
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined4 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  ulong local_a0;
  ulong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined4 local_78;
  long local_70;
  
  lVar37 = sp_el0;
  local_70 = *(long *)(lVar37 + 0x638);
  lVar37 = param_1[4];
  local_e0 = 0;
  psVar15 = (short *)rmnet_frag_header_ptr(param_1,4,4,&local_e0);
  if (psVar15 == (short *)0x0) goto LAB_00109d2c;
  uVar14 = (uint)(int)*psVar15 >> 1 & 0x7f;
  if (uVar14 == 2) {
    lVar26 = param_1[4];
    if ((*(byte *)(lVar26 + 0xed) & 1) == 0) {
      *(long *)(lVar37 + 0xaa0) = *(long *)(lVar37 + 0xaa0) + 1;
    }
    else if (*psVar15 < 0) {
LAB_00109970:
      *(long *)(lVar37 + 0xa60) = *(long *)(lVar37 + 0xa60) + 1;
      *(byte *)((long)param_1 + 0x51) = *(byte *)((long)param_1 + 0x51) | 1;
    }
    else {
      local_dc[0] = local_dc[0] & 0xff00;
      pbVar20 = (byte *)rmnet_frag_header_ptr(param_1,8,1,local_dc);
      if (pbVar20 != (byte *)0x0) {
        if ((*pbVar20 & 0xf0) == 0x60) {
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b0 = 0;
          lVar19 = rmnet_frag_header_ptr(param_1,8,0x28,&local_b0);
          if (lVar19 != 0) {
            *(undefined1 *)((long)param_1 + 0x4e) = 6;
            cVar36 = *(char *)(lVar19 + 6);
            uVar25 = ipv6_ext_hdr(cVar36);
            uVar32 = 0;
            uVar14 = 0x30;
            while ((uVar25 & 1) != 0) {
              local_d0 = local_d0 & 0xffffffffffff0000;
              if ((cVar36 == ';') ||
                 (pcVar18 = (char *)rmnet_frag_header_ptr(param_1,uVar14,2,&local_d0),
                 pcVar18 == (char *)0x0)) goto LAB_00109cac;
              if (cVar36 == '3') {
                lVar23 = 2;
LAB_00109a44:
                iVar28 = ((uint)(byte)pcVar18[1] << lVar23) + 8;
              }
              else {
                if (cVar36 != ',') {
                  lVar23 = 3;
                  goto LAB_00109a44;
                }
                local_d8[0] = 0;
                puVar21 = (ushort *)rmnet_frag_header_ptr(param_1,uVar14 + 2,2,local_d8);
                if (puVar21 == (ushort *)0x0) goto LAB_00109cac;
                uVar32 = *puVar21;
                if (7 < (ushort)(uVar32 >> 8 | uVar32 << 8)) {
                  cVar36 = ',';
                  break;
                }
                iVar28 = 8;
              }
              cVar36 = *pcVar18;
              uVar14 = iVar28 + uVar14;
              uVar25 = ipv6_ext_hdr(cVar36);
            }
            if ((-1 < (int)uVar14) && (uVar32 == 0)) {
              *(short *)((long)param_1 + 0x4a) = (short)uVar14;
              uVar30 = (uint)(*(ushort *)(lVar19 + 4) >> 8) |
                       (*(ushort *)(lVar19 + 4) & 0xff00ff) << 8;
              if (uVar30 + (uVar14 & 0xffff) <= (int)param_1[6] - 8U) {
                *(char *)((long)param_1 + 0x4f) = cVar36;
                uVar14 = csum_ipv6_magic(lVar19 + 8,lVar19 + 0x18,uVar30,cVar36,0);
                goto LAB_00109b6c;
              }
            }
          }
        }
        else if ((*pbVar20 & 0xf0) == 0x40) {
          local_78 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b0 = 0;
          sVar10 = (*pbVar20 & 0xf) << 2;
          *(short *)((long)param_1 + 0x4a) = sVar10;
          puVar17 = (ulong *)rmnet_frag_header_ptr(param_1,8,sVar10,&local_b0);
          if (((puVar17 != (ulong *)0x0) && ((*puVar17 & 0xff3f000000000000) == 0)) &&
             (uVar30 = (uint)(*(ushort *)((long)puVar17 + 2) >> 8) |
                       (*(ushort *)((long)puVar17 + 2) & 0xff00ff) << 8,
             uVar30 <= (int)param_1[6] - 8U)) {
            uVar25 = *puVar17 + puVar17[1] + (ulong)CARRY8(puVar17[1],*puVar17);
            iVar28 = ((byte)*puVar17 & 0xf) - 3;
            puVar27 = puVar17 + 2;
            do {
              iVar28 = iVar28 + -1;
              uVar25 = uVar25 + (uint)*puVar27;
              puVar27 = (ulong *)((long)puVar27 + 4);
            } while (1 < iVar28);
            uVar14 = (uint)((uVar25 >> 0x20 | uVar25 << 0x20) + uVar25 >> 0x20);
            if ((uVar14 >> 0x10 | uVar14 << 0x10) + uVar14 < 0xffff0000) {
              lVar19 = *(long *)(lVar26 + 0xaa0);
              bVar13 = false;
LAB_00109c94:
              *(long *)(lVar26 + 0xaa0) = lVar19 + 1;
              if (bVar13) goto LAB_00109970;
            }
            else {
              uVar30 = uVar30 - *(ushort *)((long)param_1 + 0x4a);
              *(undefined1 *)((long)param_1 + 0x4e) = 4;
              uVar9 = *(undefined1 *)((long)puVar17 + 9);
              *(undefined1 *)((long)param_1 + 0x4f) = uVar9;
              uVar14 = csum_tcpudp_nofold(*(undefined4 *)((long)puVar17 + 0xc),(int)puVar17[2],
                                          uVar30 & 0xffff,uVar9,0);
              uVar14 = (uVar14 >> 0x10 | uVar14 << 0x10) + uVar14 >> 0x10 ^ 0xffffffff;
LAB_00109b6c:
              cVar36 = *(char *)((long)param_1 + 0x4f);
              if ((cVar36 != '\x11') && (cVar36 != '\x06')) goto LAB_00109cac;
              uVar22 = *(ushort *)((long)param_1 + 0x4a) + 8;
              if (cVar36 == '\x11') {
                local_b0 = 0;
                lVar19 = rmnet_frag_header_ptr(param_1,uVar22,8,&local_b0);
                if (lVar19 == 0) goto LAB_00109cac;
                if (*(short *)(lVar19 + 6) == 0) {
                  lVar19 = *(long *)(lVar26 + 0xaa0);
                  bVar13 = *(char *)((long)param_1 + 0x4e) == '\x04';
                  goto LAB_00109c94;
                }
              }
              uVar14 = ~uVar14 | 0xffff0000;
              plVar34 = (long *)param_1[2];
              while ((plVar34 != param_1 + 2 && ((uVar30 & 0xffff) != 0))) {
                uVar2 = *(uint *)(plVar34 + 3);
                uVar33 = uVar22 - uVar2;
                if (uVar22 < uVar2) {
                  uVar1 = uVar2 - uVar22;
                  if ((uVar30 & 0xffff) <= uVar2 - uVar22) {
                    uVar1 = uVar30 & 0xffff;
                  }
                  uVar14 = csum_partial(((plVar34[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000)
                                        + (ulong)*(uint *)((long)plVar34 + 0x1c) + (long)(int)uVar22
                                        ,uVar1);
                  uVar33 = 0;
                  uVar30 = uVar30 - uVar1;
                }
                plVar34 = (long *)*plVar34;
                uVar22 = uVar33;
              }
              *(long *)(lVar26 + 0xaa0) = *(long *)(lVar26 + 0xaa0) + 1;
              if (0xfffeffff < (uVar14 >> 0x10 | uVar14 << 0x10) + uVar14) goto LAB_00109970;
            }
            *(long *)(lVar37 + 0xa68) = *(long *)(lVar37 + 0xa68) + 1;
            goto LAB_00109cb8;
          }
        }
      }
LAB_00109cac:
      *(long *)(lVar37 + 0xa70) = *(long *)(lVar37 + 0xa70) + 1;
    }
LAB_00109cb8:
    lVar37 = rmnet_frag_pull(param_1,param_2,8);
    if ((lVar37 == 0) || (lVar37 = rmnet_frag_trim(param_1,param_2,param_4), lVar37 == 0))
    goto LAB_00109d2c;
    uVar25 = __list_del_entry_valid(param_1);
    if ((uVar25 & 1) != 0) {
      lVar37 = *param_1;
      plVar34 = (long *)param_1[1];
      *(long **)(lVar37 + 8) = plVar34;
      *plVar34 = lVar37;
    }
    *param_1 = (long)param_1;
    param_1[1] = (long)param_1;
    puVar29 = (undefined8 *)param_3[1];
    uVar25 = __list_add_valid(param_1,puVar29,param_3);
    if ((uVar25 & 1) != 0) {
      uVar24 = 0;
      param_3[1] = param_1;
      *param_1 = (long)param_3;
      param_1[1] = (long)puVar29;
      *puVar29 = param_1;
      goto LAB_00109d30;
    }
    goto LAB_0010a1c0;
  }
  if (uVar14 != 1) {
LAB_00109d2c:
    uVar24 = 0xffffffea;
    goto LAB_00109d30;
  }
  *(long *)(lVar37 + 0xab0) = *(long *)(lVar37 + 0xab0) + 1;
  lVar37 = param_1[4];
  local_98 = local_98 & 0xffffffff00000000;
  local_a8 = 0;
  local_a0 = 0;
  local_b0 = 0;
  puVar16 = (uint *)rmnet_frag_header_ptr(param_1,4,0x1c,&local_b0);
  if (puVar16 == (uint *)0x0) goto LAB_00109d2c;
  uVar14 = *puVar16;
  lVar26 = 0xac0;
  uVar30 = uVar14 >> 0xc & 7;
  if ((uVar30 == 0) || (uVar30 == 7)) {
LAB_00109990:
    *(long *)(lVar37 + lVar26) = *(long *)(lVar37 + lVar26) + 1;
    goto LAB_00109d2c;
  }
  if (((0x30 < *(byte *)((long)puVar16 + 7)) ||
      (((bVar31 = *(char *)((long)puVar16 + 0xb) + *(byte *)((long)puVar16 + 7), 0x30 < bVar31 ||
        (bVar31 = *(char *)((long)puVar16 + 0xf) + bVar31, 0x30 < bVar31)) ||
       (bVar31 = *(char *)((long)puVar16 + 0x13) + bVar31, 0x30 < bVar31)))) ||
     ((bVar31 = *(char *)((long)puVar16 + 0x17) + bVar31, 0x30 < bVar31 ||
      (bVar31 = *(char *)((long)puVar16 + 0x1b) + bVar31, 0x30 < bVar31)))) {
    lVar26 = 0xac8;
    goto LAB_00109990;
  }
  bVar3 = *(byte *)((long)puVar16 + 0x16);
  bVar4 = *(byte *)((long)puVar16 + 0x12);
  bVar5 = *(byte *)((long)puVar16 + 0xe);
  bVar6 = *(byte *)((long)puVar16 + 10);
  bVar7 = *(byte *)((long)puVar16 + 6);
  bVar8 = *(byte *)((long)puVar16 + 0x1a);
  *(ulong *)(lVar37 + 0xab8) = *(long *)(lVar37 + 0xab8) + (ulong)bVar31;
  lVar26 = 0xaf0;
  switch(*puVar16 >> 0x10 & 0xf) {
  case 0:
    break;
  case 1:
    lVar26 = 0xaf8;
    break;
  case 2:
    lVar26 = 0xb00;
    break;
  case 3:
    uVar30 = *puVar16 >> 0x14 & 0xf;
    if (uVar30 < 5) {
      lVar26 = (ulong)(uVar30 << 3) + 0xb08;
      break;
    }
    goto switchD_001098b8_default;
  case 4:
    lVar26 = 0xb30;
    break;
  default:
    goto switchD_001098b8_default;
  }
  *(long *)(lVar37 + lVar26) = *(long *)(lVar37 + lVar26) + 1;
switchD_001098b8_default:
  lVar37 = lVar37 + 0xa40 + (ulong)(uVar14 >> 0x1c) * 8;
  *(long *)(lVar37 + 0xf8) = *(long *)(lVar37 + 0xf8) + 1;
  local_b8 = 0;
  lVar37 = param_1[4];
  local_c8 = 0;
  uStack_c0 = 0;
  local_d0 = 0;
  if (0x1f < *(uint *)(param_1 + 6)) {
    plVar38 = param_1 + 2;
    plVar34 = (long *)*plVar38;
    uVar24 = *(undefined8 *)(lVar37 + 0xe8);
    if (plVar34 != plVar38) {
      uVar35 = 0;
      uVar14 = 0x1c;
      uVar25 = 4;
      do {
        uVar30 = *(uint *)(plVar34 + 3);
        uVar22 = (uint)uVar25;
        if (uVar22 < uVar30) {
          uVar2 = uVar14;
          if (uVar30 - uVar22 <= uVar14) {
            uVar2 = uVar30 - uVar22;
          }
          memcpy((void *)((long)local_d8 + uVar35 + 8),
                 (void *)(((plVar34[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                          (ulong)*(uint *)((long)plVar34 + 0x1c) + uVar25),(ulong)uVar2);
          uVar25 = 0;
          uVar35 = (ulong)(uVar2 + (int)uVar35);
          uVar14 = uVar14 - uVar2;
        }
        else {
          uVar25 = (ulong)(uVar22 - uVar30);
        }
        plVar34 = (long *)*plVar34;
      } while ((plVar34 != plVar38) && (uVar14 != 0));
    }
    lVar26 = rmnet_frag_pull(param_1,param_2,0x20);
    if ((lVar26 != 0) &&
       ((plVar34 = (long *)*plVar38, plVar34 != plVar38 && (plVar34 != (long *)0x0)))) {
      local_f0 = (ulong)bVar3 << 0x20 | (ulong)bVar4 << 0x18 | (ulong)bVar5 << 0x10 | (ulong)bVar7 |
                 (ulong)bVar6 << 8 | (ulong)bVar8 << 0x28;
      pbVar20 = (byte *)(((plVar34[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                        (ulong)*(uint *)((long)plVar34 + 0x1c));
      if (pbVar20 != (byte *)0x0) {
        bVar31 = *pbVar20 & 0xf0;
        if (bVar31 == 0x60) {
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          local_a0 = 0;
          local_b0 = 0;
          lVar26 = rmnet_frag_header_ptr(param_1,0,0x28,&local_b0);
          if (lVar26 != 0) {
            *(undefined1 *)((long)param_1 + 0x4e) = 6;
            bVar3 = *(byte *)(lVar26 + 6);
            uVar25 = ipv6_ext_hdr(bVar3);
            bVar31 = bVar3;
            if ((uVar25 & 1) == 0) {
              uVar32 = 0;
              bVar13 = false;
              uVar14 = 0x28;
            }
            else {
              uVar32 = 0;
              uVar14 = 0x28;
              bVar13 = false;
              do {
                local_d8[0] = 0;
                if ((bVar31 == 0x3b) ||
                   (pbVar20 = (byte *)rmnet_frag_header_ptr(param_1,uVar14,2,local_d8),
                   pbVar20 == (byte *)0x0)) {
LAB_0010a194:
                  *(byte *)((long)param_1 + 0x4f) = bVar3;
                  goto LAB_0010a198;
                }
                if (bVar31 == 0x33) {
                  lVar26 = 2;
LAB_00109fd8:
                  iVar28 = ((uint)pbVar20[1] << lVar26) + 8;
                }
                else {
                  if (bVar31 != 0x2c) {
                    lVar26 = 3;
                    goto LAB_00109fd8;
                  }
                  local_dc[0] = 0;
                  puVar21 = (ushort *)rmnet_frag_header_ptr(param_1,uVar14 + 2,2,local_dc);
                  if (puVar21 == (ushort *)0x0) goto LAB_0010a194;
                  uVar32 = *puVar21;
                  if (7 < (ushort)(uVar32 >> 8 | uVar32 << 8)) {
                    bVar31 = 0x2c;
                    bVar13 = true;
                    *(undefined1 *)((long)param_1 + 0x4f) = 0x2c;
                    goto joined_r0x0010a524;
                  }
                  iVar28 = 8;
                  bVar13 = true;
                }
                bVar31 = *pbVar20;
                uVar14 = iVar28 + uVar14;
                uVar25 = ipv6_ext_hdr(bVar31);
              } while ((uVar25 & 1) != 0);
            }
            *(byte *)((long)param_1 + 0x4f) = bVar31;
joined_r0x0010a524:
            if ((-1 < (int)uVar14) && (uVar32 == 0)) {
              *(short *)((long)param_1 + 0x4a) = (short)uVar14;
              bVar12 = false;
              if ((uVar14 & 0xffff) < 0x29) {
                bVar12 = !bVar13;
              }
              goto LAB_0010a0b0;
            }
            goto LAB_0010a198;
          }
        }
        else if (bVar31 == 0x40) {
          local_a0 = local_a0 & 0xffffffff00000000;
          local_b0 = 0;
          local_a8 = 0;
          pbVar20 = (byte *)rmnet_frag_header_ptr(param_1,0,0x14,&local_b0);
          if (pbVar20 != (byte *)0x0) {
            *(undefined1 *)((long)param_1 + 0x4e) = 4;
            uVar14 = (*pbVar20 & 0xf) << 2;
            *(short *)((long)param_1 + 0x4a) = (short)uVar14;
            bVar31 = pbVar20[9];
            *(byte *)((long)param_1 + 0x4f) = bVar31;
            bVar12 = (*pbVar20 & 0xf) == 5;
LAB_0010a0b0:
            uVar30 = (uint)bVar12 & (uint)((ulong)uVar24 >> 0x37) & 0xff;
            if (bVar31 == 0x11) {
              local_b0 = 0;
              lVar26 = rmnet_frag_header_ptr(param_1,uVar14 & 0xffff,8,&local_b0);
              if (lVar26 != 0) {
                *(undefined2 *)((long)param_1 + 0x4c) = 8;
                *(long *)(lVar37 + 0xbc8) = *(long *)(lVar37 + 0xbc8) + 1;
                *(ulong *)(lVar37 + 0xbd0) =
                     *(long *)(lVar37 + 0xbd0) + (ulong)*(uint *)(param_1 + 6);
                if (*(char *)((long)param_1 + 0x4e) == '\x04') {
                  bVar13 = *(short *)(lVar26 + 6) == 0;
                }
                else {
                  bVar13 = false;
                }
LAB_0010a1cc:
                plVar34 = (long *)param_1[2];
                *(int *)((long)param_1 + 0x2c) = (int)param_1[6];
                *(byte *)((long)param_1 + 0x51) = *(byte *)((long)param_1 + 0x51) | 2;
                if (plVar34 != plVar38) {
                  iVar28 = (int)param_1[5];
                  do {
                    if (((uint)*(undefined8 *)plVar34[2] >> 0x10 & 1) == 0) {
                      uVar25 = 0;
                    }
                    else {
                      uVar25 = (ulong)*(byte *)(plVar34[2] + 0x51);
                    }
                    iVar28 = iVar28 + (int)(0x1000L << (uVar25 & 0x3f));
                    *(int *)(param_1 + 5) = iVar28;
                    plVar34 = (long *)*plVar34;
                  } while (plVar34 != plVar38);
                }
                uVar14 = rmnet_map_v5_csum_buggy(&local_d0);
                if (bVar13 || ((uVar14 ^ 0xffffffff) & 1) != 0) {
                  uVar14 = 0;
                  if (((uint)local_d0 & 0xf000) == 0x9000) {
                    uVar14 = uVar30;
                  }
                  if (uVar14 != 1) {
                    if ((local_d0 & 0x7000) != 0) {
                      uVar25 = 0;
                      iVar28 = 0;
                      do {
                        if ((uVar25 == 6) || ((uVar25 & 0x3fffffffffffffff) == 6)) {
LAB_0010a530:
                    /* WARNING: Does not return */
                          pcVar11 = (code *)SoftwareBreakpoint(1,0x10a534);
                          (*pcVar11)();
                        }
                        uVar35 = uVar25 * 4 + 7;
                        *(ushort *)((long)param_1 + 0x46) =
                             (local_d8[uVar25 * 2 + 6] >> 8 | local_d8[uVar25 * 2 + 6] << 8) -
                             (*(short *)((long)param_1 + 0x4a) + *(short *)((long)param_1 + 0x4c));
                        if (0x1c < uVar35) goto LAB_0010a530;
                        pbVar20 = (byte *)((long)local_d8 + uVar25 * 4 + 0xf);
                        if (*pbVar20 != 0) {
                          uVar14 = 0;
                          do {
                            if (uVar30 == 0) {
                              *(undefined2 *)(param_1 + 9) = 1;
                              if ((local_f0 & 1) != 0) {
                                *(long *)(lVar37 + 0xad0) = *(long *)(lVar37 + 0xad0) + 1;
                              }
                              bVar13 = (local_f0 & 1) == 0;
LAB_0010a424:
                              __rmnet_frag_segment_data(param_1,param_2,param_3,iVar28,bVar13);
                            }
                            else {
                              if ((local_f0 & 1) != 0) {
                                *(long *)(lVar37 + 0xad0) = *(long *)(lVar37 + 0xad0) + 1;
                                if ((short)param_1[9] != 0) {
                                  __rmnet_frag_segment_data(param_1,param_2,param_3,iVar28,1);
                                }
                                bVar13 = false;
                                *(undefined2 *)(param_1 + 9) = 1;
                                goto LAB_0010a424;
                              }
                              *(short *)(param_1 + 9) = (short)param_1[9] + 1;
                            }
                            if (0x1c < uVar35) goto LAB_0010a530;
                            uVar14 = uVar14 + 1;
                            iVar28 = iVar28 + 1;
                            local_f0 = local_f0 >> 1;
                          } while (uVar14 < *pbVar20);
                        }
                        if ((short)param_1[9] != 0) {
                          __rmnet_frag_segment_data(param_1,param_2,param_3,iVar28,1);
                        }
                        uVar25 = uVar25 + 1;
                      } while ((uint)uVar25 < ((uint)local_d0 >> 0xc & 7));
                    }
                    goto LAB_0010a1a8;
                  }
                  *(byte *)((long)param_1 + 0x51) = *(byte *)((long)param_1 + 0x51) | 1;
                  *(ushort *)((long)param_1 + 0x46) =
                       (local_d0._4_2_ >> 8 | local_d0._4_2_ << 8) -
                       (*(short *)((long)param_1 + 0x4a) + *(short *)((long)param_1 + 0x4c));
                  *(ushort *)(param_1 + 9) = (ushort)local_d0._7_1_;
                }
                else {
                  plVar34 = (long *)*plVar38;
                  if (((plVar34 != plVar38) && (plVar34 != (long *)0x0)) &&
                     (lVar37 = ((plVar34[2] & 0x3ffffffffffc0U) << 6 | 0xff00000000000000) +
                               (ulong)*(uint *)((long)plVar34 + 0x1c), lVar37 != 0)) {
                    iVar28 = (int)param_1[6] - (uint)*(ushort *)((long)param_1 + 0x4a);
                    if (*(char *)((long)param_1 + 0x4e) == '\x04') {
                      uVar14 = csum_tcpudp_nofold(*(undefined4 *)(lVar37 + 0xc),
                                                  *(undefined4 *)(lVar37 + 0x10),iVar28,
                                                  *(undefined1 *)((long)param_1 + 0x4f),0);
                      uVar14 = (uVar14 >> 0x10 | uVar14 << 0x10) + uVar14 >> 0x10;
                    }
                    else {
                      uVar14 = csum_ipv6_magic(lVar37 + 8,lVar37 + 0x18,iVar28,
                                               *(undefined1 *)((long)param_1 + 0x4f),0);
                      uVar14 = ~uVar14;
                    }
                    uVar14 = csum_partial(lVar37 + (ulong)*(ushort *)((long)param_1 + 0x4a),iVar28,
                                          uVar14 & 0xffff);
                    if (0xfffeffff < (uVar14 >> 0x10 | uVar14 << 0x10) + uVar14) {
                      *(byte *)((long)param_1 + 0x51) = *(byte *)((long)param_1 + 0x51) | 1;
                    }
                  }
                  *(ushort *)((long)param_1 + 0x46) =
                       (local_d0._4_2_ >> 8 | local_d0._4_2_ << 8) -
                       (*(short *)((long)param_1 + 0x4a) + *(short *)((long)param_1 + 0x4c));
                  *(ushort *)(param_1 + 9) = (ushort)local_d0._7_1_;
                }
                puVar29 = (undefined8 *)param_3[1];
                uVar25 = __list_add_valid(param_1,puVar29,param_3);
                if ((uVar25 & 1) != 0) {
                  param_3[1] = param_1;
                  *param_1 = (long)param_3;
                  param_1[1] = (long)puVar29;
                  *puVar29 = param_1;
                }
              }
            }
            else if (bVar31 == 6) {
              local_a0 = local_a0 & 0xffffffff00000000;
              local_b0 = 0;
              local_a8 = 0;
              lVar26 = rmnet_frag_header_ptr(param_1,uVar14 & 0xffff,0x14,&local_b0);
              if (lVar26 != 0) {
                bVar13 = false;
                *(ushort *)((long)param_1 + 0x4c) = *(ushort *)(lVar26 + 0xc) >> 2 & 0x3c;
                *(long *)(lVar37 + 3000) = *(long *)(lVar37 + 3000) + 1;
                *(ulong *)(lVar37 + 0xbc0) =
                     *(long *)(lVar37 + 0xbc0) + (ulong)*(uint *)(param_1 + 6);
                goto LAB_0010a1cc;
              }
            }
            else {
              *(long *)(lVar37 + 0xae8) = *(long *)(lVar37 + 0xae8) + 1;
            }
          }
        }
        else {
LAB_0010a198:
          *(long *)(lVar37 + 0xae0) = *(long *)(lVar37 + 0xae0) + 1;
        }
      }
    }
  }
LAB_0010a1a8:
  if ((long *)*param_3 != param_1) {
    rmnet_recycle_frag_descriptor(param_1,param_2);
  }
LAB_0010a1c0:
  uVar24 = 0;
LAB_00109d30:
  lVar37 = sp_el0;
  if (*(long *)(lVar37 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar24);
  }
  return;
}



//------------------------------------------------------------
// rmnet_descriptor_classify_chain_count @ 0010a538 size=48
// signature: undefined rmnet_descriptor_classify_chain_count(void)
// callers: []
//------------------------------------------------------------

void rmnet_descriptor_classify_chain_count(ulong param_1,long param_2)

{
  ulong uVar1;
  
  uVar1 = 6;
  if (param_1 < 0x3c) {
    uVar1 = (ulong)(((uint)param_1 & 0xff) / 10);
  }
  param_2 = param_2 + uVar1 * 8;
  *(ulong *)(param_2 + 0xa60) = *(long *)(param_2 + 0xa60) + param_1;
  return;
}



//------------------------------------------------------------
// rmnet_descriptor_classify_frag_count @ 0010a56c size=56
// signature: undefined rmnet_descriptor_classify_frag_count(void)
// callers: []
//------------------------------------------------------------

void rmnet_descriptor_classify_frag_count(ulong param_1,long param_2)

{
  long *plVar1;
  
  if (param_1 < 2) {
    plVar1 = (long *)(param_2 + 0xa98);
  }
  else {
    plVar1 = (long *)(param_2 + (param_1 >> 2) * 8 + 0xaa0);
    if (0xf < param_1) {
      plVar1 = (long *)(param_2 + 0xac0);
    }
  }
  *plVar1 = *plVar1 + param_1;
  return;
}



//------------------------------------------------------------
// rmnet_frag_ingress_handler @ 0010a5a8 size=1048
// signature: undefined rmnet_frag_ingress_handler(void)
// callers: [rmnet_rx_handler]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

void rmnet_frag_ingress_handler(undefined8 *param_1,long param_2)

{
  long *******ppppppplVar1;
  long ******pppppplVar2;
  long ******pppppplVar3;
  int iVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  code *pcVar8;
  int iVar9;
  ulong uVar10;
  byte *pbVar11;
  long lVar12;
  undefined8 *puVar13;
  long *plVar14;
  undefined8 *puVar15;
  undefined8 *puVar16;
  long *******ppppppplVar17;
  long *******ppppppplVar18;
  ulong uVar19;
  long *******local_90;
  long *******local_88;
  long *******local_80;
  long *******local_78;
  undefined4 local_70 [2];
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  iVar4 = *(int *)((long)param_1 + 0x8c);
  local_90 = (long *******)&local_90;
  local_88 = (long *******)&local_90;
  if (param_1 == (undefined8 *)0x0) {
    uVar19 = 0;
    uVar10 = 0;
  }
  else {
    uVar19 = 0;
    puVar16 = param_1;
    do {
      bVar6 = *(byte *)(puVar16[0x1b] + (ulong)*(uint *)((long)puVar16 + 0xd4) + 2);
      plVar14 = (long *)(param_2 + 0xa98);
      if ((1 < bVar6) && (plVar14 = (long *)(param_2 + 0xac0), bVar6 < 0x10)) {
        plVar14 = (long *)(param_2 + ((ulong)bVar6 & 0xfc) * 2 + 0xaa0);
      }
      *plVar14 = *plVar14 + (ulong)bVar6;
      rmnet_frag_deaggregate(puVar16,param_2,&local_90,*(undefined4 *)((long)puVar16 + 0x8c));
      ppppppplVar18 = local_90;
joined_r0x0010a690:
      while (ppppppplVar1 = ppppppplVar18, (long ********)ppppppplVar1 != &local_90) {
        ppppppplVar18 = (long *******)*ppppppplVar1;
        uVar10 = __list_del_entry_valid(ppppppplVar1);
        if ((uVar10 & 1) != 0) {
          pppppplVar2 = *ppppppplVar1;
          pppppplVar3 = ppppppplVar1[1];
          pppppplVar2[1] = (long *****)pppppplVar3;
          *pppppplVar3 = (long *****)pppppplVar2;
        }
        *ppppppplVar1 = (long ******)ppppppplVar1;
        ppppppplVar1[1] = (long ******)ppppppplVar1;
        iVar5 = *(int *)(ppppppplVar1 + 7);
        local_70[0] = 0;
        local_80 = (long *******)&local_80;
        local_78 = (long *******)&local_80;
        pbVar11 = (byte *)rmnet_frag_header_ptr(ppppppplVar1,0,4,local_70);
        if (pbVar11 != (byte *)0x0) {
          uVar7 = ((uint)(*(ushort *)(pbVar11 + 2) >> 8) |
                  (*(ushort *)(pbVar11 + 2) & 0xff00ff) << 8) - ((int)(char)*pbVar11 & 0x3fU);
          if ((char)*pbVar11 < 0) {
            qmi_rmnet_set_dl_msg_active(param_2);
            if ((*(uint *)(param_2 + 8) & 0x60000000) == 0) {
              if ((*(uint *)(param_2 + 8) >> 1 & 1) != 0) {
                rmnet_frag_command(ppppppplVar1,pbVar11,param_2);
              }
            }
            else {
              rmnet_frag_flow_command(ppppppplVar1,param_2,uVar7);
            }
            goto LAB_0010a6dc;
          }
          if ((pbVar11[1] == 0xff) || (lVar12 = rmnet_get_endpoint(param_2), lVar12 == 0))
          goto LAB_0010a6dc;
          ppppppplVar1[4] = *(long *******)(lVar12 + 8);
          if (((*pbVar11 >> 6 & 1) == 0) || ((*(byte *)(param_2 + 8) & 0x30) == 0))
          goto LAB_0010a7ac;
          iVar9 = rmnet_frag_process_next_hdr_packet(ppppppplVar1,param_2,&local_80,uVar7);
          if (iVar9 != 0) goto LAB_0010a6dc;
          goto LAB_0010a7f8;
        }
LAB_0010a6dc:
        rmnet_recycle_frag_descriptor(ppppppplVar1,param_2);
      }
      puVar13 = puVar16;
      if (puVar16 == param_1) {
        puVar13 = (undefined8 *)(puVar16[0x1b] + (ulong)*(uint *)((long)puVar16 + 0xd4) + 8);
      }
      puVar15 = (undefined8 *)*puVar13;
      uVar19 = uVar19 + 1;
      *puVar13 = 0;
      consume_skb(puVar16);
      puVar16 = puVar15;
    } while (puVar15 != (undefined8 *)0x0);
    uVar10 = 6;
    if (uVar19 < 0x3c) {
      uVar10 = (ulong)(((uint)uVar19 & 0xff) / 10);
    }
  }
  param_2 = param_2 + uVar10 * 8;
  *(ulong *)(param_2 + 0xa60) = *(long *)(param_2 + 0xa60) + uVar19;
  if (iVar4 != 0xda1a) {
    __rcu_read_lock();
    if (rmnet_perf_chain_end != (code *)0x0) {
      if (*(int *)(rmnet_perf_chain_end + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10a97c);
        (*pcVar8)();
      }
      (*rmnet_perf_chain_end)();
    }
    __rcu_read_unlock();
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_0010a7ac:
  lVar12 = rmnet_frag_pull(ppppppplVar1,param_2,4);
  if ((lVar12 != 0) &&
     (lVar12 = rmnet_frag_trim(ppppppplVar1,param_2,uVar7 & 0xffff), ppppppplVar17 = local_78,
     lVar12 != 0)) {
    uVar10 = __list_add_valid(ppppppplVar1,local_78,&local_80);
    if ((uVar10 & 1) != 0) {
      *ppppppplVar1 = (long ******)&local_80;
      ppppppplVar1[1] = (long ******)ppppppplVar17;
      local_78 = ppppppplVar1;
      *ppppppplVar17 = (long ******)ppppppplVar1;
    }
LAB_0010a7f8:
    if ((*(byte *)(param_2 + 0xb) >> 3 & 1) != 0) {
      ppppppplVar1 = (long *******)0x0;
      if ((long ********)local_80 != &local_80) {
        ppppppplVar1 = local_80;
      }
      qmi_rmnet_work_maybe_restart(param_2,ppppppplVar1,0);
    }
    ppppppplVar1 = local_80;
    if (iVar5 != 0xda1a) {
      __rcu_read_lock();
      pcVar8 = rmnet_perf_desc_entry;
      ppppppplVar1 = local_80;
      if (rmnet_perf_desc_entry != (code *)0x0) {
        while ((long ********)ppppppplVar1 != &local_80) {
          ppppppplVar17 = (long *******)*ppppppplVar1;
          uVar10 = __list_del_entry_valid(ppppppplVar1);
          if ((uVar10 & 1) != 0) {
            pppppplVar2 = *ppppppplVar1;
            pppppplVar3 = ppppppplVar1[1];
            pppppplVar2[1] = (long *****)pppppplVar3;
            *pppppplVar3 = (long *****)pppppplVar2;
          }
          *ppppppplVar1 = (long ******)ppppppplVar1;
          ppppppplVar1[1] = (long ******)ppppppplVar1;
          if (*(int *)(pcVar8 + -4) != 0x75a19c96) {
                    /* WARNING: Does not return */
            pcVar8 = (code *)SoftwareBreakpoint(0x8234,0x10a870);
            (*pcVar8)();
          }
          (*pcVar8)(ppppppplVar1,param_2);
          ppppppplVar1 = ppppppplVar17;
        }
        __rcu_read_unlock();
        goto joined_r0x0010a690;
      }
      __rcu_read_unlock();
      ppppppplVar1 = local_80;
    }
    while ((long ********)ppppppplVar1 != &local_80) {
      ppppppplVar17 = (long *******)*ppppppplVar1;
      uVar10 = __list_del_entry_valid(ppppppplVar1);
      if ((uVar10 & 1) != 0) {
        pppppplVar2 = *ppppppplVar1;
        pppppplVar3 = ppppppplVar1[1];
        pppppplVar2[1] = (long *****)pppppplVar3;
        *pppppplVar3 = (long *****)pppppplVar2;
      }
      *ppppppplVar1 = (long ******)ppppppplVar1;
      ppppppplVar1[1] = (long ******)ppppppplVar1;
      rmnet_frag_deliver(ppppppplVar1,param_2);
      ppppppplVar1 = ppppppplVar17;
    }
  }
  goto joined_r0x0010a690;
}



//------------------------------------------------------------
// rmnet_descriptor_deinit @ 0010a9c4 size=108
// signature: undefined rmnet_descriptor_deinit(void)
// callers: [rmnet_unregister_real_device, rmnet_register_real_device]
//------------------------------------------------------------

void rmnet_descriptor_deinit(long param_1)

{
  long *plVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0xb28);
  if (plVar2 != (long *)0x0) {
    plVar1 = (long *)*plVar2;
    while (plVar1 != plVar2) {
      plVar1 = (long *)*plVar1;
      kfree();
      *(int *)(plVar2 + 2) = (int)plVar2[2] + -1;
    }
    kfree(plVar2);
    *(undefined8 *)(param_1 + 0xb28) = 0;
  }
  return;
}



//------------------------------------------------------------
// rmnet_descriptor_init @ 0010aa34 size=220
// signature: undefined rmnet_descriptor_init(void)
// callers: [rmnet_register_real_device]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_descriptor_init(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  int iVar6;
  
  uVar4 = ___stack_chk_fail;
  *(undefined4 *)(param_1 + 0xb20) = 0;
  lVar1 = kmalloc_trace(uVar4,0xb20,0x18);
  if (lVar1 == 0) {
LAB_0010aaec:
    uVar4 = 0xfffffff4;
  }
  else {
    iVar6 = 0x40;
    *(long *)lVar1 = lVar1;
    *(long *)(lVar1 + 8) = lVar1;
    *(long *)(param_1 + 0xb28) = lVar1;
    do {
      plVar2 = (long *)kmalloc_trace(_rtnl_is_locked,0xb20,0x58);
      if (plVar2 == (long *)0x0) goto LAB_0010aaec;
      *plVar2 = (long)plVar2;
      plVar2[1] = (long)plVar2;
      plVar2[2] = (long)(plVar2 + 2);
      plVar2[3] = (long)(plVar2 + 2);
      puVar5 = *(undefined8 **)(lVar1 + 8);
      uVar3 = __list_add_valid(plVar2,puVar5,lVar1);
      if ((uVar3 & 1) != 0) {
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
        plVar2[1] = (long)puVar5;
        *puVar5 = plVar2;
      }
      iVar6 = iVar6 + -1;
      *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
    } while (iVar6 != 0);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// rmnet_descriptor_trace_pfn @ 0010ab10 size=96
// signature: undefined rmnet_descriptor_trace_pfn(void)
// callers: []
//------------------------------------------------------------

void rmnet_descriptor_trace_pfn(void)

{
  long lVar1;
  long lVar2;
  
  lVar1 = sp_el0;
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != *(long *)(lVar1 + 0x638)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __rmnet_frag_segment_data @ 0010ace8 size=708
// signature: undefined __rmnet_frag_segment_data(void)
// callers: [rmnet_frag_process_next_hdr_packet]
//------------------------------------------------------------

void __rmnet_frag_segment_data
               (long *param_1,undefined8 param_2,long param_3,char param_4,byte param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  long *plVar13;
  long lVar14;
  ulong uVar15;
  byte bVar16;
  long lVar17;
  long *plVar18;
  long lVar19;
  undefined8 *puVar20;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar17 = param_1[4];
  uVar5 = *(ushort *)((long)param_1 + 0x46);
  uVar6 = *(ushort *)(param_1 + 9);
  uVar7 = *(ushort *)((long)param_1 + 0x4a);
  uVar8 = *(ushort *)((long)param_1 + 0x4c);
  uVar9 = *(ushort *)((long)param_1 + 0x44);
  plVar13 = (long *)rmnet_get_frag_descriptor(param_2);
  if (plVar13 == (long *)0x0) goto LAB_0010af0c;
  lVar14 = param_1[1];
  iVar1 = (uint)uVar8 + (uint)uVar7;
  lVar19 = param_1[2];
  *plVar13 = *param_1;
  plVar13[1] = lVar14;
  lVar2 = param_1[6];
  lVar14 = param_1[3];
  lVar3 = param_1[4];
  plVar13[5] = param_1[5];
  plVar13[6] = lVar2;
  plVar13[3] = lVar14;
  plVar13[4] = lVar3;
  lVar14 = param_1[9];
  lVar3 = param_1[10];
  lVar2 = param_1[7];
  lVar4 = param_1[8];
  plVar18 = plVar13 + 2;
  *plVar18 = lVar19;
  plVar13[9] = lVar14;
  plVar13[10] = lVar3;
  plVar13[7] = lVar2;
  plVar13[8] = lVar4;
  *plVar13 = (long)plVar13;
  plVar13[1] = (long)plVar13;
  *plVar18 = (long)plVar18;
  plVar13[3] = (long)plVar18;
  *(undefined4 *)(plVar13 + 6) = 0;
  iVar11 = rmnet_frag_descriptor_add_frags_from(plVar13,param_1,0,iVar1);
  if (-1 < iVar11) {
    iVar11 = (uint)uVar6 * (uint)uVar5;
    iVar1 = iVar1 + (uint)uVar9;
    iVar12 = rmnet_frag_descriptor_add_frags_from(plVar13,param_1,iVar1,iVar11);
    if (-1 < iVar12) {
      if (*(char *)((long)param_1 + 0x4f) == '\x11') {
        local_80 = 0;
        lVar14 = rmnet_frag_header_ptr(param_1,*(undefined2 *)((long)param_1 + 0x4a),8,&local_80);
        if (lVar14 == 0) goto LAB_0010af00;
        if (*(char *)((long)param_1 + 0x4e) == '\x04') {
          param_5 = *(short *)(lVar14 + 6) == 0 | param_5;
        }
      }
      else if (*(char *)((long)param_1 + 0x4f) == '\x06') {
        local_70 = 0;
        local_80 = 0;
        uStack_78 = 0;
        lVar14 = rmnet_frag_header_ptr(param_1,*(undefined2 *)((long)param_1 + 0x4a),0x14,&local_80)
        ;
        if (lVar14 == 0) goto LAB_0010af00;
        bVar16 = *(byte *)((long)plVar13 + 0x51);
        *(byte *)((long)plVar13 + 0x51) = bVar16 | 8;
        uVar10 = (*(uint *)(lVar14 + 4) & 0xff00ff00) >> 8 | (*(uint *)(lVar14 + 4) & 0xff00ff) << 8
        ;
        uVar10 = (uVar10 >> 0x10 | uVar10 << 0x10) + (uint)*(ushort *)((long)param_1 + 0x44);
        uVar10 = (uVar10 & 0xff00ff00) >> 8 | (uVar10 & 0xff00ff) << 8;
        *(uint *)((long)plVar13 + 0x3c) = uVar10 >> 0x10 | uVar10 << 0x10;
        if (((*(ushort *)(lVar14 + 0xc) & 0x900) != 0) &&
           ((uint)(iVar1 + iVar11) < *(uint *)(param_1 + 6))) {
          uVar5 = *(ushort *)(lVar14 + 0xc);
          *(byte *)((long)plVar13 + 0x51) = bVar16 | 0x28;
          *(ushort *)((long)plVar13 + 0x42) = uVar5 & 0xf6ff;
        }
      }
      if (*(char *)((long)param_1 + 0x4e) == '\x04') {
        local_70 = 0;
        local_80 = 0;
        uStack_78 = 0;
        lVar14 = rmnet_frag_header_ptr(param_1,0,0x14,&local_80);
        if (lVar14 == 0) goto LAB_0010af00;
        bVar16 = *(byte *)((long)plVar13 + 0x51) | 4;
        *(byte *)((long)plVar13 + 0x51) = bVar16;
        uVar10 = (uint)*(byte *)(param_1 + 10) +
                 ((uint)(*(ushort *)(lVar14 + 4) >> 8) | (*(ushort *)(lVar14 + 4) & 0xff00ff) << 8);
        *(ushort *)(plVar13 + 8) = (ushort)(uVar10 >> 8) & 0xff | (ushort)((uVar10 & 0xff00ff) << 8)
        ;
      }
      else {
        bVar16 = *(byte *)((long)plVar13 + 0x51);
      }
      *(byte *)((long)plVar13 + 0x51) = bVar16 & 0xfe | param_5 & 1;
      *(long *)(lVar17 + 0xad8) = *(long *)(lVar17 + 0xad8) + 1;
      *(char *)(param_1 + 10) = param_4 + '\x01';
      *(undefined2 *)(param_1 + 9) = 0;
      param_1[5] = 0;
      *(short *)((long)param_1 + 0x44) = *(short *)((long)param_1 + 0x44) + (short)iVar11;
      puVar20 = *(undefined8 **)(param_3 + 8);
      uVar15 = __list_add_valid(plVar13,puVar20,param_3);
      if ((uVar15 & 1) != 0) {
        *(long **)(param_3 + 8) = plVar13;
        *plVar13 = param_3;
        plVar13[1] = (long)puVar20;
        *puVar20 = plVar13;
      }
      goto LAB_0010af0c;
    }
  }
LAB_0010af00:
  rmnet_recycle_frag_descriptor(plVar13,param_2);
LAB_0010af0c:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_update_pid_and_check_boost @ 0010afbc size=268
// signature: undefined rmnet_update_pid_and_check_boost(void)
// callers: [rmnet_vnd_select_queue]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_update_pid_and_check_boost(int param_1,ulong param_2,undefined4 *param_3,long *param_4)

{
  long *plVar1;
  undefined8 uVar2;
  long *plVar3;
  long lVar4;
  
  *param_3 = 0;
  *param_4 = 0;
  uVar2 = _raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
  plVar1 = &rmnet_pid_ht + ((uint)(param_1 * 0x61c88647) >> 0x18);
  plVar3 = plVar1;
  do {
    plVar3 = (long *)*plVar3;
    if (plVar3 == (long *)0x0) {
      plVar3 = (long *)kmalloc_trace(_rtnl_is_locked,0xb20,0x48);
      if (plVar3 != (long *)0x0) {
        lVar4 = *plVar1;
        *(int *)(plVar3 + 8) = param_1;
        plVar3[6] = 0;
        plVar3[7] = 0;
        plVar3[3] = param_2 & 0xffffffff;
        *plVar3 = lVar4;
        plVar3[1] = (long)plVar1;
        *plVar1 = (long)plVar3;
        if (lVar4 != 0) {
          *(long **)(lVar4 + 8) = plVar3;
        }
      }
      goto LAB_0010b0a0;
    }
  } while ((int)plVar3[8] != param_1);
  plVar3[3] = plVar3[3] + (param_2 & 0xffffffff);
  if (*(int *)((long)plVar3 + 0x3c) != 0) {
    *(undefined4 *)((long)plVar3 + 0x3c) = 0;
    *param_3 = 1;
    lVar4 = plVar3[6];
    *param_4 = lVar4;
    *(int *)(plVar3 + 7) = (int)lVar4;
  }
LAB_0010b0a0:
  _raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock,uVar2);
  return;
}



//------------------------------------------------------------
// rmnet_boost_for_pid @ 0010b0cc size=136
// signature: undefined rmnet_boost_for_pid(void)
// callers: []
//------------------------------------------------------------

void rmnet_boost_for_pid(int param_1,undefined4 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  uVar1 = _raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
  puVar2 = &rmnet_pid_ht + ((uint)(param_1 * 0x61c88647) >> 0x18);
  do {
    puVar2 = (undefined8 *)*puVar2;
    if (puVar2 == (undefined8 *)0x0) goto LAB_0010b134;
  } while (*(int *)(puVar2 + 8) != param_1);
  *(undefined4 *)((long)puVar2 + 0x3c) = param_2;
  puVar2[6] = param_3;
LAB_0010b134:
  _raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock,uVar1);
  return;
}



//------------------------------------------------------------
// rmnet_core_genl_send_resp @ 0010b158 size=220
// signature: undefined rmnet_core_genl_send_resp(void)
// callers: [rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

undefined8 rmnet_core_genl_send_resp(int *param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if ((((param_1 != (int *)0x0) && (param_2 != 0)) &&
      (lVar2 = __alloc_skb(0x224,0xcc0,0,0xffffffff), lVar2 != 0)) &&
     ((lVar3 = genlmsg_put(lVar2,0,*param_1 + 1,&rmnet_core_genl_family,0,1), lVar3 != 0 &&
      (iVar1 = nla_put(lVar2,3,0x210,param_2), iVar1 == 0)))) {
    *(int *)(lVar3 + -0x14) =
         (*(int *)(lVar2 + 0xd8) + *(int *)(lVar2 + 0xd0)) - ((int)lVar3 + -0x14);
    iVar1 = netlink_unicast(*(undefined8 *)(*(long *)(param_1 + 10) + 0x118),lVar2,param_1[1],0x40);
    if (-1 < iVar1) {
      return 0;
    }
  }
  rmnet_core_userspace_connected = 0;
  return 0xffffffff;
}



//------------------------------------------------------------
// rmnet_core_genl_pid_bps_req_hdlr @ 0010b238 size=592
// signature: undefined rmnet_core_genl_pid_bps_req_hdlr(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_core_genl_pid_bps_req_hdlr(undefined8 param_1,long param_2)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  long lVar9;
  undefined8 *puVar10;
  ulong uVar11;
  bool bVar12;
  ulong uVar13;
  long local_498;
  long lStack_490;
  undefined8 local_488;
  undefined8 local_480;
  long local_288;
  undefined2 local_280;
  undefined1 local_27e;
  undefined1 auStack_278 [528];
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  memset(auStack_278,0,0x210);
  if ((param_2 == 0) || (lVar9 = *(long *)(*(long *)(param_2 + 0x20) + 0x18), lVar9 == 0)) {
    bVar12 = true;
  }
  else {
    iVar5 = nla_memcpy(auStack_278,lVar9,0x210);
    bVar12 = iVar5 < 1;
  }
  if (rmnet_core_userspace_connected == 0) {
    rmnet_core_userspace_connected = 1;
  }
  memset(&local_488,0,0x210);
  if (!bVar12) {
    local_498 = 0;
    lStack_490 = 0;
    ktime_get_real_ts64(&local_498);
    local_288 = lStack_490 + local_498 * 1000000000;
    uVar6 = _raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
    lVar9 = 0;
    uVar13 = 0;
    do {
      puVar7 = (undefined8 *)(&rmnet_pid_ht)[lVar9];
      while (puVar8 = puVar7, puVar7 != (undefined8 *)0x0) {
        while( true ) {
          uVar1 = puVar8[3];
          puVar7 = (undefined8 *)*puVar8;
          lVar2 = uVar1 - puVar8[4];
          if (uVar1 < (ulong)puVar8[4] || lVar2 == 0) break;
          uVar11 = (ulong)(local_288 - puVar8[2]) / 1000000000 & 0xffffffff;
          uVar3 = 0;
          if (uVar11 != 0) {
            uVar3 = (ulong)(lVar2 * 8) / uVar11;
          }
          iVar5 = *(int *)(puVar8 + 7) + -1000;
          if (*(int *)(puVar8 + 7) < 1000) {
            iVar5 = 0;
          }
          *(int *)(puVar8 + 7) = iVar5;
          puVar8[5] = uVar3;
          if (0x1f < uVar13) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10b484);
            (*pcVar4)();
          }
          if (((0x210 < (uVar13 << 4 | 8)) ||
              (*(undefined4 *)(&local_480 + uVar13 * 2) = *(undefined4 *)(puVar8 + 8), 0x20 < uVar13
              )) || ((&local_480)[uVar13 * 2 + -1] = puVar8[5], lVar2 = local_288,
                    0x210 < (uVar13 << 4 | 0xc))) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x10b480);
            (*pcVar4)();
          }
          *(undefined4 *)((long)&local_480 + (uVar13 * 4 + 1) * 4) = *(undefined4 *)(puVar8 + 7);
          puVar8[2] = lVar2;
          puVar8[4] = uVar1;
          if (uVar13 == 0x1f) {
            uVar13 = 0x20;
            goto LAB_0010b418;
          }
          uVar13 = uVar13 + 1;
          puVar8 = puVar7;
          if (puVar7 == (undefined8 *)0x0) goto LAB_0010b31c;
        }
        puVar10 = (undefined8 *)puVar8[1];
        if (puVar10 != (undefined8 *)0x0) {
          *puVar10 = puVar7;
          if (puVar7 != (undefined8 *)0x0) {
            puVar7[1] = puVar10;
          }
          *puVar8 = 0;
          puVar8[1] = 0;
        }
        kfree();
      }
LAB_0010b31c:
      lVar9 = lVar9 + 1;
    } while (lVar9 != 0x100);
LAB_0010b418:
    _raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock,uVar6);
    local_280 = (undefined2)uVar13;
  }
  local_27e = 1;
  rmnet_core_genl_send_resp(param_2,&local_488);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_core_genl_pid_boost_req_hdlr @ 0010b48c size=348
// signature: undefined rmnet_core_genl_pid_boost_req_hdlr(void)
// callers: []
//------------------------------------------------------------

void rmnet_core_genl_pid_boost_req_hdlr(undefined8 param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  uint uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  uint local_200 [98];
  ushort local_78;
  char local_76;
  long local_70;
  
  lVar5 = sp_el0;
  local_70 = *(long *)(lVar5 + 0x638);
  memset(local_200,0,400);
  if (param_2 != 0) {
    lVar5 = *(long *)(*(long *)(param_2 + 0x20) + 0x20);
    if ((lVar5 != 0) && (iVar3 = nla_memcpy(local_200,lVar5,400), 0 < iVar3)) {
      uVar4 = 0;
      uVar6 = (uint)local_78;
      if (0x1f < uVar6) {
        uVar6 = 0x20;
      }
      if ((local_76 != '\0') && (uVar6 != 0)) {
        uVar8 = 0;
        do {
          if (local_200[uVar8 * 3] != 0) {
            uVar1 = local_200[uVar8 * 3 + 1];
            uVar2 = local_200[uVar8 * 3 + 2];
            uVar4 = _raw_spin_lock_irqsave(&rmnet_pid_ht_splock);
            puVar7 = &rmnet_pid_ht + (uVar2 * 0x61c88647 >> 0x18);
            do {
              puVar7 = (undefined8 *)*puVar7;
              if (puVar7 == (undefined8 *)0x0) goto LAB_0010b540;
            } while (*(uint *)(puVar7 + 8) != uVar2);
            *(undefined4 *)((long)puVar7 + 0x3c) = 1;
            puVar7[6] = (ulong)uVar1;
LAB_0010b540:
            _raw_spin_unlock_irqrestore(&rmnet_pid_ht_splock,uVar4);
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < uVar6);
        uVar4 = 0;
      }
      goto LAB_0010b5a4;
    }
  }
  uVar4 = 0xffffffff;
LAB_0010b5a4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// rmnet_core_genl_tether_info_req_hdlr @ 0010b5ec size=184
// signature: undefined rmnet_core_genl_tether_info_req_hdlr(void)
// callers: []
//------------------------------------------------------------

void rmnet_core_genl_tether_info_req_hdlr(undefined8 param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined2 local_20;
  long local_18;
  
  lVar4 = sp_el0;
  local_18 = *(long *)(lVar4 + 0x638);
  local_20 = 0;
  if (param_2 != 0) {
    lVar4 = *(long *)(*(long *)(param_2 + 0x20) + 0x28);
    if (lVar4 != 0) {
      iVar2 = nla_memcpy(&local_20,lVar4,2);
      uVar3 = 0xffffffff;
      if ((0 < iVar2) && (local_20._1_1_ != '\0')) {
        if (rmnet_perf_tether_cmd_hook != (code *)0x0) {
          if (*(int *)(rmnet_perf_tether_cmd_hook + -4) != 0x1f1615a4) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10b66c);
            (*pcVar1)();
          }
          (*rmnet_perf_tether_cmd_hook)(1,(undefined1)local_20);
        }
        uVar3 = 0;
      }
      goto LAB_0010b67c;
    }
  }
  uVar3 = 0xffffffff;
LAB_0010b67c:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// rmnet_core_genl_init @ 0010b6a8 size=56
// signature: undefined rmnet_core_genl_init(void)
// callers: [init_module]
//------------------------------------------------------------

undefined8 rmnet_core_genl_init(void)

{
  undefined8 uVar1;
  
  uVar1 = genl_register_family(&rmnet_core_genl_family);
  if ((int)uVar1 != 0) {
    genl_unregister_family(&rmnet_core_genl_family);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_core_genl_deinit @ 0010b6e4 size=40
// signature: undefined rmnet_core_genl_deinit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

undefined8 rmnet_core_genl_deinit(void)

{
  genl_unregister_family(&rmnet_core_genl_family);
  return 0;
}



//------------------------------------------------------------
// __traceiter_rmnet_xmit_skb @ 0010b710 size=100
// signature: undefined __traceiter_rmnet_xmit_skb(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_rmnet_xmit_skb(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00129288;
  plVar2 = DAT_00129288;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x98a786c) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10b754);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_low @ 0010b778 size=196
// signature: undefined __traceiter_rmnet_low(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_low
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001292d0;
  plVar2 = _DAT_001292d0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10b808);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_high @ 0010b840 size=196
// signature: undefined __traceiter_rmnet_high(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_high
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129318;
  plVar2 = _DAT_00129318;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10b8d0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_err @ 0010b908 size=196
// signature: undefined __traceiter_rmnet_err(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_err
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129360;
  plVar2 = _DAT_00129360;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10b998);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_skb_gso @ 0010b9d0 size=172
// signature: undefined __traceiter_print_skb_gso(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_skb_gso
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined8 param_7,undefined8 param_8)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001293a8;
  plVar2 = _DAT_001293a8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x7a360265) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10ba50);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_icmp_tx @ 0010ba80 size=164
// signature: undefined __traceiter_print_icmp_tx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_icmp_tx
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001293f0;
  plVar2 = _DAT_001293f0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x33af50aa) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10baf8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_icmp_rx @ 0010bb28 size=164
// signature: undefined __traceiter_print_icmp_rx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_icmp_rx
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129438;
  plVar2 = _DAT_00129438;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x33af50aa) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bba0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_tcp_tx @ 0010bbd0 size=140
// signature: undefined __traceiter_print_tcp_tx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_tcp_tx
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129480;
  plVar2 = _DAT_00129480;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x719b36f5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bc34);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_tcp_rx @ 0010bc60 size=140
// signature: undefined __traceiter_print_tcp_rx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_tcp_rx
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001294c8;
  plVar2 = _DAT_001294c8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x719b36f5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bcc4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_udp_tx @ 0010bcf0 size=148
// signature: undefined __traceiter_print_udp_tx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_udp_tx
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129510;
  plVar2 = _DAT_00129510;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x43314572) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bd5c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_udp_rx @ 0010bd88 size=148
// signature: undefined __traceiter_print_udp_rx(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_udp_rx
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined8 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129558;
  plVar2 = _DAT_00129558;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x43314572) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bdf4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_print_pfn @ 0010be20 size=124
// signature: undefined __traceiter_print_pfn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_print_pfn(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001295a0;
  plVar2 = _DAT_001295a0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x30391d71) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10be78);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_perf_low @ 0010bea0 size=196
// signature: undefined __traceiter_rmnet_perf_low(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_perf_low
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001295e8;
  plVar2 = _DAT_001295e8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bf30);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_perf_high @ 0010bf68 size=196
// signature: undefined __traceiter_rmnet_perf_high(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_perf_high
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129630;
  plVar2 = _DAT_00129630;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10bff8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_perf_err @ 0010c030 size=196
// signature: undefined __traceiter_rmnet_perf_err(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_perf_err
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129678;
  plVar2 = _DAT_00129678;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c0c0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_low @ 0010c0f8 size=196
// signature: undefined __traceiter_rmnet_shs_low(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_low
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001296c0;
  plVar2 = _DAT_001296c0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c188);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_high @ 0010c1c0 size=196
// signature: undefined __traceiter_rmnet_shs_high(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_high
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129708;
  plVar2 = _DAT_00129708;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c250);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_err @ 0010c288 size=196
// signature: undefined __traceiter_rmnet_shs_err(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_err
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129750;
  plVar2 = _DAT_00129750;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c318);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_wq_low @ 0010c350 size=196
// signature: undefined __traceiter_rmnet_shs_wq_low(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_wq_low
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129798;
  plVar2 = _DAT_00129798;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c3e0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_wq_high @ 0010c418 size=196
// signature: undefined __traceiter_rmnet_shs_wq_high(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_wq_high
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001297e0;
  plVar2 = _DAT_001297e0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c4a8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_shs_wq_err @ 0010c4e0 size=196
// signature: undefined __traceiter_rmnet_shs_wq_err(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_shs_wq_err
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
          undefined8 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129828;
  plVar2 = _DAT_00129828;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x631565f2) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c570);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_freq_boost @ 0010c5a8 size=116
// signature: undefined __traceiter_rmnet_freq_boost(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_rmnet_freq_boost(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129870;
  plVar2 = _DAT_00129870;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x301e17e5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c5f8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_freq_reset @ 0010c620 size=116
// signature: undefined __traceiter_rmnet_freq_reset(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_rmnet_freq_reset(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001298b8;
  plVar2 = _DAT_001298b8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x301e17e5) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c670);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_rmnet_freq_update @ 0010c698 size=124
// signature: undefined __traceiter_rmnet_freq_update(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_rmnet_freq_update
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129900;
  plVar2 = _DAT_00129900;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x15b7e076) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10c6f0);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_rmnet_xmit_skb @ 0010c718 size=244
// signature: undefined trace_event_raw_event_rmnet_xmit_skb(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rmnet_xmit_skb(long param_1,long param_2)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar5 = __trace_trigger_soft_disabled(param_1), (uVar5 & 1) == 0)) {
    pcVar2 = "(null)";
    if (*(char **)(param_2 + 0x10) != (char *)0x0) {
      pcVar2 = *(char **)(param_2 + 0x10);
    }
    sVar3 = strlen(pcVar2);
    iVar1 = (int)sVar3 + 1;
    lVar4 = trace_event_buffer_reserve(&local_68,param_1,(long)iVar1 + 0x10);
    if (lVar4 != 0) {
      *(uint *)(lVar4 + 8) = iVar1 * 0x10000 | 0x10;
      pcVar2 = "(null)";
      if (*(char **)(param_2 + 0x10) != (char *)0x0) {
        pcVar2 = *(char **)(param_2 + 0x10);
      }
      strcpy((char *)(lVar4 + 0x10),pcVar2);
      *(undefined4 *)(lVar4 + 0xc) = *(undefined4 *)(param_2 + 0x70);
      trace_event_buffer_commit(&local_68);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rmnet_xmit_skb @ 0010c810 size=340
// signature: undefined perf_trace_rmnet_xmit_skb(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rmnet_xmit_skb(long param_1,long param_2)

{
  long *plVar1;
  ulong uVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60 = 0;
  local_64 = 0;
  pcVar3 = "(null)";
  if (*(char **)(param_2 + 0x10) != (char *)0x0) {
    pcVar3 = *(char **)(param_2 + 0x10);
  }
  sVar5 = strlen(pcVar3);
  lVar6 = tpidr_el1;
  plVar1 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar4 = ((int)sVar5 + 0x1cU & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar4,&local_60,&local_64);
    if (lVar6 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(int *)(lVar6 + 8) = (int)sVar5 * 0x10000 + 0x10010;
      pcVar3 = "(null)";
      if (*(char **)(param_2 + 0x10) != (char *)0x0) {
        pcVar3 = *(char **)(param_2 + 0x10);
      }
      strcpy((char *)(lVar6 + 0x10),pcVar3);
      *(undefined4 *)(lVar6 + 0xc) = *(undefined4 *)(param_2 + 0x70);
      perf_trace_run_bpf_submit(lVar6,iVar4,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_rmnet_mod_template @ 0010c968 size=240
// signature: undefined trace_event_raw_event_rmnet_mod_template(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rmnet_mod_template
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x38), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined1 *)(lVar1 + 9) = param_3;
    *(undefined4 *)(lVar1 + 0xc) = param_4;
    *(undefined4 *)(lVar1 + 0x10) = param_5;
    *(undefined8 *)(lVar1 + 0x18) = param_6;
    *(undefined8 *)(lVar1 + 0x20) = param_7;
    *(undefined8 *)(lVar1 + 0x28) = param_8;
    *(undefined8 *)(lVar1 + 0x30) = param_9;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rmnet_mod_template @ 0010ca5c size=308
// signature: undefined perf_trace_rmnet_mod_template(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rmnet_mod_template
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined8 param_6,undefined8 param_7,undefined8 param_8,
               undefined8 param_9)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x3c,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined1 *)(lVar3 + 9) = param_3;
    *(undefined4 *)(lVar3 + 0xc) = param_4;
    *(undefined4 *)(lVar3 + 0x10) = param_5;
    *(undefined8 *)(lVar3 + 0x18) = param_6;
    *(undefined8 *)(lVar3 + 0x20) = param_7;
    *(undefined8 *)(lVar3 + 0x28) = param_8;
    *(undefined8 *)(lVar3 + 0x30) = param_9;
    perf_trace_run_bpf_submit(lVar3,0x3c,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_print_skb_gso @ 0010cb94 size=368
// signature: undefined trace_event_raw_event_print_skb_gso(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_print_skb_gso
               (long param_1,long param_2,undefined2 param_3,undefined2 param_4,undefined2 param_5,
               undefined2 param_6,char *param_7,char *param_8)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  undefined4 uVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar8 = __trace_trigger_soft_disabled(param_1), (uVar8 & 1) == 0)) {
    __s = "(null)";
    if (param_7 != (char *)0x0) {
      __s = param_7;
    }
    sVar5 = strlen(__s);
    __s_00 = "(null)";
    if (param_8 != (char *)0x0) {
      __s_00 = param_8;
    }
    iVar1 = (int)sVar5 + 1;
    sVar6 = strlen(__s_00);
    iVar2 = (int)sVar6 + 1;
    lVar7 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar2 + iVar1) + 0x28);
    if (lVar7 != 0) {
      uVar3 = (int)sVar5 + 0x29;
      *(long *)(lVar7 + 8) = param_2;
      *(uint *)(lVar7 + 0x20) = iVar1 * 0x10000 | 0x28;
      *(uint *)(lVar7 + 0x24) = uVar3 | iVar2 * 0x10000;
      *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      uVar4 = *(undefined4 *)(param_2 + 0x74);
      *(undefined2 *)(lVar7 + 0x18) = param_3;
      *(undefined2 *)(lVar7 + 0x1a) = param_4;
      *(undefined2 *)(lVar7 + 0x1c) = param_5;
      *(undefined4 *)(lVar7 + 0x14) = uVar4;
      *(undefined2 *)(lVar7 + 0x1e) = param_6;
      strcpy((char *)(lVar7 + 0x28),__s);
      strcpy((char *)(lVar7 + (ulong)(uVar3 & 0xffff)),__s_00);
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_print_skb_gso @ 0010cd08 size=444
// signature: undefined perf_trace_print_skb_gso(void)
// callers: []
//------------------------------------------------------------

void perf_trace_print_skb_gso
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,char *param_7,char *param_8)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  long lVar8;
  int iVar9;
  ulong unaff_x30;
  undefined1 auStack_90 [12];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  __s = "(null)";
  if (param_7 != (char *)0x0) {
    __s = param_7;
  }
  local_70 = 0;
  local_74 = 0;
  local_84 = param_3;
  local_80 = param_4;
  local_7c = param_5;
  local_78 = param_6;
  sVar6 = strlen(__s);
  __s_00 = "(null)";
  if (param_8 != (char *)0x0) {
    __s_00 = param_8;
  }
  sVar7 = strlen(__s_00);
  lVar8 = tpidr_el1;
  plVar2 = (long *)(lVar8 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar7 + 1;
    iVar9 = (int)sVar6;
    iVar5 = (iVar9 + iVar1 + 0x34U & 0xfffffff8) - 4;
    lVar8 = perf_trace_buf_alloc(iVar5,&local_70,&local_74);
    if (lVar8 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(long *)(lVar8 + 8) = param_2;
      *(int *)(lVar8 + 0x20) = iVar9 * 0x10000 + 0x10028;
      *(uint *)(lVar8 + 0x24) = iVar9 + 0x29U | iVar1 * 0x10000;
      *(undefined4 *)(lVar8 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      uVar4 = *(undefined4 *)(param_2 + 0x74);
      *(short *)(lVar8 + 0x18) = (short)local_84;
      *(undefined4 *)(lVar8 + 0x14) = uVar4;
      *(short *)(lVar8 + 0x1a) = (short)local_80;
      *(short *)(lVar8 + 0x1e) = (short)local_78;
      *(short *)(lVar8 + 0x1c) = (short)local_7c;
      strcpy((char *)(lVar8 + 0x28),__s);
      strcpy((char *)(lVar8 + (ulong)(iVar9 + 0x29U & 0xffff)),__s_00);
      perf_trace_run_bpf_submit(lVar8,iVar5,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_print_icmp @ 0010cec8 size=348
// signature: undefined trace_event_raw_event_print_icmp(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_print_icmp
               (long param_1,long param_2,undefined2 param_3,undefined1 param_4,undefined2 param_5,
               char *param_6,char *param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  undefined4 uVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar8 = __trace_trigger_soft_disabled(param_1), (uVar8 & 1) == 0)) {
    __s = "(null)";
    if (param_6 != (char *)0x0) {
      __s = param_6;
    }
    sVar5 = strlen(__s);
    __s_00 = "(null)";
    if (param_7 != (char *)0x0) {
      __s_00 = param_7;
    }
    iVar1 = (int)sVar5 + 1;
    sVar6 = strlen(__s_00);
    iVar2 = (int)sVar6 + 1;
    lVar7 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar2 + iVar1) + 0x28);
    if (lVar7 != 0) {
      uVar3 = (int)sVar5 + 0x25;
      *(long *)(lVar7 + 8) = param_2;
      *(uint *)(lVar7 + 0x1c) = iVar1 * 0x10000 | 0x24;
      *(uint *)(lVar7 + 0x20) = uVar3 | iVar2 * 0x10000;
      uVar4 = *(undefined4 *)(param_2 + 0x70);
      *(undefined2 *)(lVar7 + 0x14) = param_3;
      *(undefined1 *)(lVar7 + 0x16) = param_4;
      *(undefined2 *)(lVar7 + 0x18) = param_5;
      *(undefined4 *)(lVar7 + 0x10) = uVar4;
      strcpy((char *)(lVar7 + 0x24),__s);
      strcpy((char *)(lVar7 + (ulong)(uVar3 & 0xffff)),__s_00);
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_print_icmp @ 0010d028 size=428
// signature: undefined perf_trace_print_icmp(void)
// callers: []
//------------------------------------------------------------

void perf_trace_print_icmp
               (long param_1,long param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
               char *param_6,char *param_7)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  undefined4 uVar4;
  int iVar5;
  size_t sVar6;
  size_t sVar7;
  long lVar8;
  int iVar9;
  ulong unaff_x30;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  __s = "(null)";
  if (param_6 != (char *)0x0) {
    __s = param_6;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_3;
  local_7c = param_4;
  local_78 = param_5;
  sVar6 = strlen(__s);
  __s_00 = "(null)";
  if (param_7 != (char *)0x0) {
    __s_00 = param_7;
  }
  sVar7 = strlen(__s_00);
  lVar8 = tpidr_el1;
  plVar2 = (long *)(lVar8 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar7 + 1;
    iVar9 = (int)sVar6;
    iVar5 = (iVar9 + iVar1 + 0x34U & 0xfffffff8) - 4;
    lVar8 = perf_trace_buf_alloc(iVar5,&local_70,&local_74);
    if (lVar8 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      *(undefined4 **)(local_70 + 0xf8) = &local_80;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(long *)(lVar8 + 8) = param_2;
      *(int *)(lVar8 + 0x1c) = iVar9 * 0x10000 + 0x10024;
      *(uint *)(lVar8 + 0x20) = iVar9 + 0x25U | iVar1 * 0x10000;
      uVar4 = *(undefined4 *)(param_2 + 0x70);
      *(short *)(lVar8 + 0x14) = (short)local_80;
      *(undefined4 *)(lVar8 + 0x10) = uVar4;
      *(char *)(lVar8 + 0x16) = (char)local_7c;
      *(short *)(lVar8 + 0x18) = (short)local_78;
      strcpy((char *)(lVar8 + 0x24),__s);
      strcpy((char *)(lVar8 + (ulong)(iVar9 + 0x25U & 0xffff)),__s_00);
      perf_trace_run_bpf_submit(lVar8,iVar5,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_print_tcp @ 0010d1d8 size=388
// signature: undefined trace_event_raw_event_print_tcp(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_print_tcp
               (long param_1,long param_2,char *param_3,char *param_4,undefined2 *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar7 = __trace_trigger_soft_disabled(param_1), (uVar7 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar4 = strlen(__s);
    __s_00 = "(null)";
    if (param_4 != (char *)0x0) {
      __s_00 = param_4;
    }
    iVar1 = (int)sVar4 + 1;
    sVar5 = strlen(__s_00);
    iVar2 = (int)sVar5 + 1;
    lVar6 = trace_event_buffer_reserve(&local_88,param_1,(long)(iVar2 + iVar1) + 0x30);
    if (lVar6 != 0) {
      uVar3 = (int)sVar4 + 0x2c;
      *(long *)(lVar6 + 8) = param_2;
      *(uint *)(lVar6 + 0x14) = iVar1 * 0x10000 | 0x2b;
      *(uint *)(lVar6 + 0x18) = uVar3 | iVar2 * 0x10000;
      *(undefined4 *)(lVar6 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      strcpy((char *)(lVar6 + 0x2b),__s);
      strcpy((char *)(lVar6 + (ulong)(uVar3 & 0xffff)),__s_00);
      *(undefined2 *)(lVar6 + 0x1c) = *param_5;
      *(undefined2 *)(lVar6 + 0x1e) = param_5[1];
      *(undefined4 *)(lVar6 + 0x20) = *(undefined4 *)(param_5 + 2);
      *(undefined4 *)(lVar6 + 0x24) = *(undefined4 *)(param_5 + 4);
      *(byte *)(lVar6 + 0x28) = (byte)((ushort)param_5[6] >> 9) & 1;
      *(byte *)(lVar6 + 0x29) = (byte)((ushort)param_5[6] >> 0xc) & 1;
      *(byte *)(lVar6 + 0x2a) = *(byte *)((long)param_5 + 0xd) & 1;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_print_tcp @ 0010d360 size=476
// signature: undefined perf_trace_print_tcp(void)
// callers: []
//------------------------------------------------------------

void perf_trace_print_tcp(long param_1,long param_2,char *param_3,char *param_4,undefined2 *param_5)

{
  int iVar1;
  char *__s;
  char *__s_00;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  long lVar6;
  int iVar7;
  ulong unaff_x30;
  long *local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  __s_00 = "(null)";
  if (param_4 != (char *)0x0) {
    __s_00 = param_4;
  }
  sVar5 = strlen(__s_00);
  lVar6 = tpidr_el1;
  local_80 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*local_80 != 0)) {
    iVar1 = (int)sVar5 + 1;
    iVar7 = (int)sVar4;
    iVar3 = (iVar7 + iVar1 + 0x3cU & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar6 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      *(long ***)(local_70 + 0xf8) = &local_80;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(long *)(lVar6 + 8) = param_2;
      *(int *)(lVar6 + 0x14) = iVar7 * 0x10000 + 0x1002b;
      *(uint *)(lVar6 + 0x18) = iVar7 + 0x2cU | iVar1 * 0x10000;
      *(undefined4 *)(lVar6 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      strcpy((char *)(lVar6 + 0x2b),__s);
      strcpy((char *)(lVar6 + (ulong)(iVar7 + 0x2cU & 0xffff)),__s_00);
      *(undefined2 *)(lVar6 + 0x1c) = *param_5;
      *(undefined2 *)(lVar6 + 0x1e) = param_5[1];
      *(undefined4 *)(lVar6 + 0x20) = *(undefined4 *)(param_5 + 2);
      *(undefined4 *)(lVar6 + 0x24) = *(undefined4 *)(param_5 + 4);
      *(byte *)(lVar6 + 0x28) = (byte)((ushort)param_5[6] >> 9) & 1;
      *(byte *)(lVar6 + 0x29) = (byte)((ushort)param_5[6] >> 0xc) & 1;
      *(byte *)(lVar6 + 0x2a) = *(byte *)((long)param_5 + 0xd) & 1;
      perf_trace_run_bpf_submit(lVar6,iVar3,local_74,param_1,1,local_70,local_80,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_print_udp @ 0010d540 size=352
// signature: undefined trace_event_raw_event_print_udp(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_print_udp
               (long param_1,long param_2,char *param_3,char *param_4,undefined2 *param_5,
               undefined2 param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *__s;
  char *__s_00;
  undefined2 uVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  ulong uVar8;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar8 = __trace_trigger_soft_disabled(param_1), (uVar8 & 1) == 0)) {
    __s = "(null)";
    if (param_3 != (char *)0x0) {
      __s = param_3;
    }
    sVar5 = strlen(__s);
    __s_00 = "(null)";
    if (param_4 != (char *)0x0) {
      __s_00 = param_4;
    }
    iVar1 = (int)sVar5 + 1;
    sVar6 = strlen(__s_00);
    iVar2 = (int)sVar6 + 1;
    lVar7 = trace_event_buffer_reserve(&local_98,param_1,(long)(iVar2 + iVar1) + 0x28);
    if (lVar7 != 0) {
      uVar3 = (int)sVar5 + 0x23;
      *(long *)(lVar7 + 8) = param_2;
      *(uint *)(lVar7 + 0x14) = iVar1 * 0x10000 | 0x22;
      *(uint *)(lVar7 + 0x18) = uVar3 | iVar2 * 0x10000;
      *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      strcpy((char *)(lVar7 + 0x22),__s);
      strcpy((char *)(lVar7 + (ulong)(uVar3 & 0xffff)),__s_00);
      *(undefined2 *)(lVar7 + 0x1c) = *param_5;
      uVar4 = param_5[1];
      *(undefined2 *)(lVar7 + 0x20) = param_6;
      *(undefined2 *)(lVar7 + 0x1e) = uVar4;
      trace_event_buffer_commit(&local_98);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_print_udp @ 0010d6a4 size=428
// signature: undefined perf_trace_print_udp(void)
// callers: []
//------------------------------------------------------------

void perf_trace_print_udp
               (long param_1,long param_2,char *param_3,char *param_4,undefined2 *param_5,
               undefined4 param_6)

{
  int iVar1;
  long *plVar2;
  char *__s;
  char *__s_00;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  long lVar7;
  int iVar8;
  ulong unaff_x30;
  undefined2 *local_80;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  __s = "(null)";
  if (param_3 != (char *)0x0) {
    __s = param_3;
  }
  local_70 = 0;
  local_74 = 0;
  local_80 = param_5;
  local_78 = param_6;
  sVar5 = strlen(__s);
  __s_00 = "(null)";
  if (param_4 != (char *)0x0) {
    __s_00 = param_4;
  }
  sVar6 = strlen(__s_00);
  lVar7 = tpidr_el1;
  plVar2 = (long *)(lVar7 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar6 + 1;
    iVar8 = (int)sVar5;
    iVar4 = (iVar8 + iVar1 + 0x34U & 0xfffffff8) - 4;
    lVar7 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar7 != 0) {
      *(long *)(local_70 + 0xe8) = (long)register0x00000008 + -0x60;
      *(undefined2 ***)(local_70 + 0xf8) = &local_80;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(long *)(lVar7 + 8) = param_2;
      *(int *)(lVar7 + 0x14) = iVar8 * 0x10000 + 0x10022;
      *(uint *)(lVar7 + 0x18) = iVar8 + 0x23U | iVar1 * 0x10000;
      *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(param_2 + 0x70);
      strcpy((char *)(lVar7 + 0x22),__s);
      strcpy((char *)(lVar7 + (ulong)(iVar8 + 0x23U & 0xffff)),__s_00);
      *(undefined2 *)(lVar7 + 0x1c) = *local_80;
      *(undefined2 *)(lVar7 + 0x1e) = local_80[1];
      *(short *)(lVar7 + 0x20) = (short)local_78;
      perf_trace_run_bpf_submit(lVar7,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_print_pfn @ 0010d854 size=228
// signature: undefined trace_event_raw_event_print_pfn(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_print_pfn(long param_1,undefined8 param_2,void *param_3,uint param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,(long)(int)(param_4 << 3) + 0x18),
     lVar1 != 0)) {
    *(undefined8 *)(lVar1 + 8) = param_2;
    *(uint *)(lVar1 + 0x10) = param_4;
    *(uint *)(lVar1 + 0x14) = param_4 << 0x13 | 0x18;
    memcpy((void *)(lVar1 + 0x18),param_3,
           -(ulong)(param_4 >> 0x1f) & 0xfffffff800000000 | (ulong)param_4 << 3);
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_print_pfn @ 0010d93c size=312
// signature: undefined perf_trace_print_pfn(void)
// callers: []
//------------------------------------------------------------

void perf_trace_print_pfn(long param_1,undefined8 param_2,void *param_3,uint param_4)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = param_4 * 8 + 0x1c;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_60,&local_64);
    if (lVar4 != 0) {
      *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_60 + 0xf8) = auStack_70;
      *(ulong *)(local_60 + 0x100) = uVar2;
      *(undefined8 *)(local_60 + 0x108) = 5;
      *(undefined8 *)(lVar4 + 8) = param_2;
      *(uint *)(lVar4 + 0x10) = param_4;
      *(uint *)(lVar4 + 0x14) = param_4 << 0x13 | 0x18;
      memcpy((void *)(lVar4 + 0x18),param_3,
             -(ulong)(param_4 >> 0x1f) & 0xfffffff800000000 | (ulong)param_4 << 3);
      perf_trace_run_bpf_submit(lVar4,iVar3,local_64,param_1,1,local_60,plVar1,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_rmnet_freq_template @ 0010da78 size=176
// signature: undefined trace_event_raw_event_rmnet_freq_template(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rmnet_freq_template(long param_1,undefined1 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rmnet_freq_template @ 0010db2c size=252
// signature: undefined perf_trace_rmnet_freq_template(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rmnet_freq_template(long param_1,undefined1 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_rmnet_freq_update @ 0010dc2c size=192
// signature: undefined trace_event_raw_event_rmnet_freq_update(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_rmnet_freq_update
               (long param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_rmnet_freq_update @ 0010dcf0 size=256
// signature: undefined perf_trace_rmnet_freq_update(void)
// callers: []
//------------------------------------------------------------

void perf_trace_rmnet_freq_update
               (long param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_rmnet_xmit_skb @ 0010ddf4 size=28
// signature: undefined __bpf_trace_rmnet_xmit_skb(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rmnet_xmit_skb(void)

{
  bpf_trace_run1();
  return;
}



//------------------------------------------------------------
// __bpf_trace_rmnet_mod_template @ 0010de14 size=60
// signature: undefined __bpf_trace_rmnet_mod_template(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rmnet_mod_template
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run8(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_print_skb_gso @ 0010de54 size=44
// signature: undefined __bpf_trace_print_skb_gso(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_print_skb_gso
               (undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined2 param_4,
               undefined2 param_5,undefined2 param_6)

{
  bpf_trace_run7(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_print_icmp @ 0010de84 size=40
// signature: undefined __bpf_trace_print_icmp(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_print_icmp
               (undefined8 param_1,undefined8 param_2,undefined2 param_3,undefined1 param_4,
               undefined2 param_5)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_print_tcp @ 0010deb0 size=28
// signature: undefined __bpf_trace_print_tcp(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_print_tcp(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_print_udp @ 0010ded0 size=32
// signature: undefined __bpf_trace_print_udp(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_print_udp(void)

{
  bpf_trace_run5();
  return;
}



//------------------------------------------------------------
// __bpf_trace_print_pfn @ 0010def4 size=32
// signature: undefined __bpf_trace_print_pfn(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_print_pfn(void)

{
  bpf_trace_run3();
  return;
}



//------------------------------------------------------------
// __bpf_trace_rmnet_freq_template @ 0010df18 size=36
// signature: undefined __bpf_trace_rmnet_freq_template(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rmnet_freq_template(undefined8 param_1,undefined1 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_rmnet_freq_update @ 0010df40 size=40
// signature: undefined __bpf_trace_rmnet_freq_update(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_rmnet_freq_update
               (undefined8 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// rmnet_set_skb_proto @ 0010df6c size=116
// signature: undefined rmnet_set_skb_proto(void)
// callers: [rmnet_frag_deliver]
//------------------------------------------------------------

void rmnet_set_skb_proto(long param_1)

{
  long lVar1;
  undefined2 uVar2;
  byte *pbVar3;
  undefined2 uVar4;
  
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    pbVar3 = *(byte **)(param_1 + 0xe0);
  }
  else {
    lVar1 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    pbVar3 = (byte *)(((*(ulong *)(lVar1 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                     (ulong)*(uint *)(lVar1 + 0x54));
  }
  uVar4 = 0xdd86;
  if ((*pbVar3 & 0xf0) != 0x60) {
    uVar4 = 0xf900;
  }
  uVar2 = 8;
  if ((*pbVar3 & 0xf0) != 0x40) {
    uVar2 = uVar4;
  }
  *(undefined2 *)(param_1 + 0xb4) = uVar2;
  return;
}



//------------------------------------------------------------
// rmnet_slow_start_on @ 0010dfec size=76
// signature: undefined rmnet_slow_start_on(void)
// callers: []
//------------------------------------------------------------

uint rmnet_slow_start_on(void)

{
  code *pcVar1;
  uint uVar2;
  
  if (rmnet_shs_slow_start_detect == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(rmnet_shs_slow_start_detect + -4) != -0x61e5284) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10e01c);
      (*pcVar1)();
    }
    uVar2 = (*rmnet_shs_slow_start_detect)();
  }
  return uVar2 & 1;
}



//------------------------------------------------------------
// rmnet_deliver_skb @ 0010e03c size=224
// signature: undefined rmnet_deliver_skb(void)
// callers: [rmnet_frag_deliver, __rmnet_map_ingress_handler]
//------------------------------------------------------------

void rmnet_deliver_skb(long param_1,long param_2)

{
  code *pcVar1;
  int iVar2;
  
  *(short *)(param_1 + 0xb8) =
       (short)*(undefined4 *)(param_1 + 0xe0) - (short)*(undefined4 *)(param_1 + 0xd8);
  rmnet_vnd_rx_fixup(*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x70));
  *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xfff8;
  *(short *)(param_1 + 0xba) =
       (short)*(undefined4 *)(param_1 + 0xe0) - (short)*(undefined4 *)(param_1 + 0xd8);
  if (*(int *)(param_1 + 0x8c) != 0xda1a) {
    __rcu_read_lock();
    if (rmnet_shs_skb_entry != (code *)0x0) {
      if (*(int *)(rmnet_shs_skb_entry + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10e0d8);
        (*pcVar1)();
      }
      (*rmnet_shs_skb_entry)(param_1,param_2 + 0xb00);
      __rcu_read_unlock();
      return;
    }
    __rcu_read_unlock();
  }
  iVar2 = rmnet_module_hook_shs_skb_ll_entry(0,param_1,param_2 + 0xb00);
  if (iVar2 == 0) {
    netif_receive_skb(param_1);
  }
  return;
}



//------------------------------------------------------------
// rmnet_deliver_skb_wq @ 0010e1d4 size=248
// signature: undefined rmnet_deliver_skb_wq(void)
// callers: []
//------------------------------------------------------------

void rmnet_deliver_skb_wq(long param_1,long param_2,int param_3)

{
  undefined8 *puVar1;
  short sVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x10);
  sVar2 = (short)*(undefined4 *)(param_1 + 0xe0) - (short)*(undefined4 *)(param_1 + 0xd8);
  *(short *)(param_1 + 0xb6) = sVar2;
  *(short *)(param_1 + 0xb8) = sVar2;
  rmnet_vnd_rx_fixup(*(undefined8 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x70));
  *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xfff8;
  *(short *)(param_1 + 0xba) =
       (short)*(undefined4 *)(param_1 + 0xe0) - (short)*(undefined4 *)(param_1 + 0xd8);
  __rcu_read_lock();
  puVar1 = &rmnet_shs_skb_entry;
  if (param_3 != 0) {
    puVar1 = &rmnet_shs_skb_entry_wq;
  }
  pcVar3 = (code *)*puVar1;
  if (pcVar3 == (code *)0x0) {
    __rcu_read_unlock();
    if (param_3 == 0) {
      netif_receive_skb(param_1);
    }
    else {
      gro_cells_receive(lVar4 + 0xa58,param_1);
    }
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e284);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,param_2 + 0xb00);
    __rcu_read_unlock();
  }
  return;
}



//------------------------------------------------------------
// rmnet_rx_handler @ 0010e384 size=652
// signature: undefined rmnet_rx_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_rx_handler(undefined8 *param_1)

{
  long lVar1;
  bool bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  
  param_1 = (undefined8 *)*param_1;
  if (param_1 == (undefined8 *)0x0) {
    return 0;
  }
  if ((*(ushort *)(param_1 + 0x10) & 7) == 5) {
    return 3;
  }
  lVar5 = rmnet_get_port(param_1[2]);
  if (lVar5 == 0) {
    dev_core_stats_rx_nohandler_inc(param_1[2]);
LAB_0010e440:
    kfree_skb_reason(param_1,1);
    return 0;
  }
  if (*(char *)(lVar5 + 0xd) == '\x02') {
    if (*(long *)(lVar5 + 0x808) == 0) {
      return 0;
    }
    param_1[2] = *(long *)(lVar5 + 0x808);
    __dev_queue_xmit(param_1,0);
    return 0;
  }
  if (*(char *)(lVar5 + 0xd) != '\x01') {
    return 0;
  }
  __rcu_read_lock();
  pcVar3 = rmnet_shs_switch;
  if (((rmnet_shs_switch != (code *)0x0) && (*(char *)((long)param_1 + 0x29) == '\0')) &&
     (*(int *)((long)param_1 + 0x8c) != 0xda1a)) {
    *(undefined1 *)((long)param_1 + 0x29) = 1;
    if (*(int *)(pcVar3 + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e520);
      (*pcVar3)();
    }
    (*pcVar3)(param_1,lVar5 + 0xb10);
LAB_0010e524:
    __rcu_read_unlock();
    return 0;
  }
  __rcu_read_unlock();
  if (*(short *)(param_1[2] + 0x128) == 1) {
    iVar4 = pskb_expand_head(param_1,0xe,0,0xa20);
    if (iVar4 != 0) goto LAB_0010e440;
    skb_push(param_1,0xe);
  }
  if (((*(uint *)(lVar5 + 8) & 0x30) != 0) && (*(int *)((long)param_1 + 0x74) != 0)) {
    rmnet_frag_ingress_handler(param_1,lVar5);
    return 0;
  }
  if ((*(uint *)(lVar5 + 8) & 1) == 0) {
    __rmnet_map_ingress_handler(param_1,lVar5);
    return 0;
  }
  if (*(int *)((long)param_1 + 0x8c) != 0xda1a) {
    __rcu_read_lock();
    if (rmnet_perf_deag_entry != (code *)0x0) {
      if (*(int *)(rmnet_perf_deag_entry + -4) != 0x1a038a4a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10e4f0);
        (*pcVar3)();
      }
      (*rmnet_perf_deag_entry)(param_1,lVar5);
      goto LAB_0010e524;
    }
    __rcu_read_unlock();
  }
  bVar2 = false;
  puVar7 = param_1;
  do {
    puVar8 = (undefined8 *)*puVar7;
    lVar1 = puVar7[0x1b] + (ulong)*(uint *)((long)puVar7 + 0xd4);
    puVar9 = *(undefined8 **)(lVar1 + 8);
    *(undefined8 *)(lVar1 + 8) = 0;
    *puVar7 = 0;
    do {
      puVar6 = (undefined8 *)rmnet_map_deaggregate(puVar7,lVar5);
      if (puVar6 == (undefined8 *)0x0) {
        consume_skb(puVar7);
        break;
      }
      __rmnet_map_ingress_handler(puVar6,lVar5);
    } while (puVar6 != puVar7);
    if (puVar7 == param_1) {
      if (puVar9 == (undefined8 *)0x0) {
        puVar8 = (undefined8 *)0x0;
        puVar7 = puVar8;
        if (!bVar2) goto LAB_0010e580;
      }
      else {
        bVar2 = true;
        *(long *)(lVar5 + 0xad8) = *(long *)(lVar5 + 0xad8) + 1;
        puVar8 = puVar9;
      }
LAB_0010e574:
      *(long *)(lVar5 + 0xae0) = *(long *)(lVar5 + 0xae0) + 1;
      puVar7 = puVar8;
    }
    else {
      if (puVar9 != (undefined8 *)0x0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10e604);
        (*pcVar3)();
      }
      puVar7 = puVar8;
      if (bVar2) goto LAB_0010e574;
    }
LAB_0010e580:
    if (puVar7 == (undefined8 *)0x0) {
      return 0;
    }
  } while( true );
}



//------------------------------------------------------------
// dev_core_stats_rx_nohandler_inc @ 0010e6cc size=132
// signature: undefined dev_core_stats_rx_nohandler_inc(void)
// callers: [rmnet_rx_handler]
//------------------------------------------------------------

void dev_core_stats_rx_nohandler_inc(long param_1)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x1e8);
  if ((lVar6 != 0) || (lVar6 = netdev_core_stats_alloc(param_1), lVar6 != 0)) {
    lVar4 = sp_el0;
    *(int *)(lVar4 + 0x10) = *(int *)(lVar4 + 0x10) + 1;
    lVar5 = tpidr_el1;
    plVar1 = (long *)(lVar6 + lVar5 + 0x10);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar3) {
        *plVar1 = *plVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    lVar6 = *(long *)(lVar4 + 0x10) + -1;
    *(int *)(lVar4 + 0x10) = (int)lVar6;
    if ((lVar6 == 0) || (*(long *)(lVar4 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_rx_priv_handler @ 0010e754 size=124
// signature: undefined rmnet_rx_priv_handler(void)
// callers: []
//------------------------------------------------------------

int rmnet_rx_priv_handler(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *param_1;
  local_2c = 3;
  rmnet_module_hook_wlan_ingress_rx_handler(&local_2c,param_1);
  iVar2 = local_2c;
  if (local_2c == 3) {
    rmnet_module_hook_perf_ingress_rx_handler(uVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// rmnet_egress_handler @ 0010e7d4 size=776
// signature: undefined rmnet_egress_handler(void)
// callers: [rmnet_vnd_start_xmit]
//------------------------------------------------------------

void rmnet_egress_handler(long param_1,ulong param_2)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  bool bVar13;
  undefined8 uVar14;
  
  lVar10 = *(long *)(param_1 + 0x18);
  if (((lVar10 != 0) && ((1 << (ulong)(*(byte *)(lVar10 + 0x12) & 0x1f) & 0xffffefbfU) != 0)) &&
     (*(char *)(lVar10 + 0x211) != '\b')) {
    *(undefined1 *)(lVar10 + 0x211) = 8;
  }
  lVar12 = *(long *)(param_1 + 0x10);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar12 + 0xa48);
  uVar4 = *(undefined1 *)(lVar12 + 0xa40);
  lVar10 = rmnet_get_port();
  if (lVar10 == 0) goto LAB_0010ea1c;
  uVar9 = *(uint *)(lVar10 + 8);
  if ((uVar9 >> 3 & 1) == 0) {
    if ((uVar9 & 0x10000040) != 0) {
      uVar14 = 0x40;
      goto LAB_0010e880;
    }
    iVar7 = 0;
    uVar14 = 0;
    bVar13 = true;
  }
  else {
    uVar14 = 8;
LAB_0010e880:
    bVar13 = false;
    iVar7 = 4;
  }
  uVar1 = iVar7 + 4;
  uVar3 = *(undefined4 *)(param_1 + 0x70);
  if ((uint)(*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xd8)) < uVar1) {
    iVar6 = pskb_expand_head(param_1,uVar1,0,0xa20);
    if (iVar6 != 0) goto LAB_0010ea1c;
    uVar9 = *(uint *)(lVar10 + 8);
  }
  if ((uVar9 >> 0x1b & 1) != 0) {
    qmi_rmnet_work_maybe_restart(lVar10,0,0);
  }
  lVar11 = lVar10 + (param_2 & 1) * 0xe0;
  if (bVar13) {
LAB_0010e958:
    bVar13 = false;
  }
  else {
    lVar8 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    if (((*(uint *)(lVar8 + 0x18) & 0x20011) == 0) || (*(short *)(lVar8 + 4) == 0)) {
      rmnet_map_checksum_uplink_packet(param_1,lVar10,lVar12,uVar14);
      goto LAB_0010e958;
    }
    _raw_spin_lock_bh(lVar10 + (param_2 & 1) * 0xe0 + 0x8b8);
    rmnet_map_send_agg_skb(lVar11 + 0x818);
    iVar6 = rmnet_map_add_tso_header(param_1,lVar10,lVar12);
    if (iVar6 != 0) goto LAB_0010ea1c;
    bVar13 = true;
  }
  lVar8 = rmnet_map_add_map_header(param_1,iVar7,0,lVar10);
  if (lVar8 != 0) {
    *(undefined1 *)(lVar8 + 1) = uVar4;
    if ((*(int *)(lVar10 + 8) < 0) && (1 < *(byte *)(lVar11 + 0x81a))) {
      iVar7 = rmnet_map_tx_agg_skip(param_1,uVar1);
      if (iVar7 != 0) {
        bVar13 = true;
      }
      if (!bVar13) {
        rmnet_map_tx_aggregate(param_1,lVar10,(uint)param_2 & 1);
        rmnet_vnd_tx_fixup(lVar12,uVar3);
        return;
      }
    }
    *(undefined2 *)(param_1 + 0xb4) = 0xf900;
    rmnet_vnd_tx_fixup(lVar12,uVar3);
    if ((param_2 & 1) == 0) {
      __dev_queue_xmit(param_1,0);
      return;
    }
    iVar7 = rmnet_ll_send_skb();
    if (iVar7 == 0) {
      return;
    }
    lVar10 = sp_el0;
    *(int *)(lVar10 + 0x10) = *(int *)(lVar10 + 0x10) + 1;
    lVar11 = tpidr_el1;
    piVar2 = (int *)(*(long *)(lVar12 + 0xa50) + lVar11 + 0x20);
    do {
      cVar5 = '\x01';
      bVar13 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar13) {
        *piVar2 = *piVar2 + 1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    lVar12 = *(long *)(lVar10 + 0x10) + -1;
    *(int *)(lVar10 + 0x10) = (int)lVar12;
    if ((lVar12 == 0) || (*(long *)(lVar10 + 0x10) == 0)) {
      preempt_schedule_notrace();
      return;
    }
    return;
  }
LAB_0010ea1c:
  lVar10 = sp_el0;
  *(int *)(lVar10 + 0x10) = *(int *)(lVar10 + 0x10) + 1;
  lVar11 = tpidr_el1;
  piVar2 = (int *)(*(long *)(lVar12 + 0xa50) + lVar11 + 0x20);
  do {
    cVar5 = '\x01';
    bVar13 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar13) {
      *piVar2 = *piVar2 + 1;
      cVar5 = ExclusiveMonitorsStatus();
    }
  } while (cVar5 != '\0');
  lVar12 = *(long *)(lVar10 + 0x10) + -1;
  *(int *)(lVar10 + 0x10) = (int)lVar12;
  if ((lVar12 == 0) || (*(long *)(lVar10 + 0x10) == 0)) {
    preempt_schedule_notrace();
  }
  kfree_skb_reason(param_1,1);
  return;
}



//------------------------------------------------------------
// trace_raw_output_rmnet_xmit_skb @ 0010eb94 size=108
// signature: undefined trace_raw_output_rmnet_xmit_skb(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rmnet_xmit_skb(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev_name=%s len=%u\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rmnet_mod_template @ 0010ec04 size=128
// signature: undefined trace_raw_output_rmnet_mod_template(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rmnet_mod_template(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"fun:%u ev:%u u1:%u u2:%u ul1:%llu ul2:%llu p1:0x%pK p2:0x%pK\n",
                       *(undefined1 *)(lVar2 + 8),*(undefined1 *)(lVar2 + 9),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined8 *)(lVar2 + 0x18),*(undefined8 *)(lVar2 + 0x20),
                       *(undefined8 *)(lVar2 + 0x28),*(undefined8 *)(lVar2 + 0x30));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_print_skb_gso @ 0010ec88 size=220
// signature: undefined trace_raw_output_print_skb_gso(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_print_skb_gso(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar3 = trace_raw_output_prep(param_1,param_3);
  if (iVar3 == 1) {
    puVar1 = &DAT_0012140b;
    if (*(short *)(lVar4 + 0x1c) != 8) {
      puVar1 = &DAT_00121410;
    }
    puVar2 = &DAT_001211f6;
    if (*(short *)(lVar4 + 0x1e) != 6) {
      puVar2 = (undefined *)((long)&DAT_001216bd + 4);
    }
    trace_event_printf(param_1,
                       "GSO: skbaddr=%pK, len=%d, data_len=%d, [%s][%s] src=%s %u dest=%s %u\n",
                       *(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar4 + 0x10),
                       *(undefined4 *)(lVar4 + 0x14),puVar1,puVar2,
                       lVar4 + (ulong)*(ushort *)(lVar4 + 0x20),
                       *(ushort *)(lVar4 + 0x18) >> 8 | *(ushort *)(lVar4 + 0x18) << 8,
                       lVar4 + (ulong)*(ushort *)(lVar4 + 0x24),
                       *(ushort *)(lVar4 + 0x1a) >> 8 | *(ushort *)(lVar4 + 0x1a) << 8);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_print_icmp @ 0010ed68 size=176
// signature: undefined trace_raw_output_print_icmp(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_print_icmp(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    puVar1 = &DAT_0012140b;
    if (*(short *)(lVar3 + 0x14) != 8) {
      puVar1 = &DAT_00121410;
    }
    trace_event_printf(param_1,
                       "ICMP: skbaddr=%pK, len=%d, [%s] type=%u sequence=%u source=%s dest=%s\n",
                       *(undefined8 *)(lVar3 + 8),*(undefined4 *)(lVar3 + 0x10),puVar1,
                       *(undefined1 *)(lVar3 + 0x16),
                       *(ushort *)(lVar3 + 0x18) >> 8 | *(ushort *)(lVar3 + 0x18) << 8,
                       lVar3 + (ulong)*(ushort *)(lVar3 + 0x1c),
                       lVar3 + (ulong)*(ushort *)(lVar3 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_print_tcp @ 0010ee1c size=220
// signature: undefined trace_raw_output_print_tcp(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_print_tcp(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x20f0);
  iVar3 = trace_raw_output_prep(param_1,param_3);
  if (iVar3 == 1) {
    uVar1 = (*(uint *)(lVar4 + 0x20) & 0xff00ff00) >> 8 | (*(uint *)(lVar4 + 0x20) & 0xff00ff) << 8;
    uVar2 = (*(uint *)(lVar4 + 0x24) & 0xff00ff00) >> 8 | (*(uint *)(lVar4 + 0x24) & 0xff00ff) << 8;
    trace_event_printf(param_1,
                       "TCP: skbaddr=%pK, len=%d source=%s %u dest=%s %u seq=%u ack_seq=%u syn=%u ack=%u fin=%u\n"
                       ,*(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar4 + 0x10),
                       lVar4 + (ulong)*(ushort *)(lVar4 + 0x14),
                       *(ushort *)(lVar4 + 0x1c) >> 8 | *(ushort *)(lVar4 + 0x1c) << 8,
                       lVar4 + (ulong)*(ushort *)(lVar4 + 0x18),
                       *(ushort *)(lVar4 + 0x1e) >> 8 | *(ushort *)(lVar4 + 0x1e) << 8,
                       uVar1 >> 0x10 | uVar1 << 0x10,uVar2 >> 0x10 | uVar2 << 0x10,
                       *(char *)(lVar4 + 0x28) != '\0',*(char *)(lVar4 + 0x29) != '\0',
                       *(char *)(lVar4 + 0x2a) != '\0');
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_print_udp @ 0010eefc size=160
// signature: undefined trace_raw_output_print_udp(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_print_udp(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"UDP: skbaddr=%pK, len=%d source=%s %u dest=%s %u ip_id=%u\n",
                       *(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0x10),
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x14),
                       *(ushort *)(lVar2 + 0x1c) >> 8 | *(ushort *)(lVar2 + 0x1c) << 8,
                       lVar2 + (ulong)*(ushort *)(lVar2 + 0x18),
                       *(ushort *)(lVar2 + 0x1e) >> 8 | *(ushort *)(lVar2 + 0x1e) << 8,
                       *(undefined2 *)(lVar2 + 0x20));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_print_pfn @ 0010efa0 size=148
// signature: undefined trace_raw_output_print_pfn(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_print_pfn(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    uVar1 = *(undefined4 *)(lVar5 + 0x10);
    uVar4 = *(undefined8 *)(lVar5 + 8);
    uVar3 = trace_print_array_seq(param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0x14),uVar1,8);
    trace_event_printf(param_1,"skbaddr=%pK count=%d pfn=%s\n",uVar4,uVar1,uVar3);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rmnet_freq_template @ 0010f038 size=104
// signature: undefined trace_raw_output_rmnet_freq_template(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rmnet_freq_template(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"freq policy core:%u freq floor :%u\n",*(undefined1 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_rmnet_freq_update @ 0010f0a4 size=104
// signature: undefined trace_raw_output_rmnet_freq_update(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_rmnet_freq_update(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"freq policy update core:%u policy freq floor :%u freq ceil :%u\n",
                       *(undefined1 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// __rmnet_map_ingress_handler @ 0010f10c size=928
// signature: undefined __rmnet_map_ingress_handler(void)
// callers: [rmnet_rx_handler]
//------------------------------------------------------------

void __rmnet_map_ingress_handler(undefined8 *param_1,long param_2)

{
  undefined2 uVar1;
  long *plVar2;
  long *plVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  long **pplVar7;
  undefined8 *puVar8;
  long **pplVar9;
  int iVar10;
  long lVar11;
  uint uVar12;
  byte *pbVar13;
  undefined2 uVar14;
  uint uVar15;
  long *local_60;
  undefined8 *local_58;
  undefined8 local_50;
  long local_48;
  
  local_58 = &local_60;
  local_60 = (long *)&local_60;
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  local_50 = 0;
  if ((*(int *)((long)param_1 + 0x74) == 0) ||
     (*(int *)(param_1 + 0xe) != *(int *)((long)param_1 + 0x74))) {
    pbVar13 = (byte *)param_1[0x1c];
    bVar5 = *pbVar13;
    if ((char)bVar5 < '\0') goto LAB_0010f198;
LAB_0010f1e4:
    pplVar7 = &local_60;
    pplVar9 = &local_60;
    if (pbVar13[1] != 0xff) {
      uVar4 = *(ushort *)(pbVar13 + 2);
      lVar11 = rmnet_get_endpoint(param_2);
      pplVar7 = (long **)local_60;
      pplVar9 = (long **)local_58;
      if (lVar11 != 0) {
        uVar6 = (uint)(uVar4 >> 8) | (uVar4 & 0xff00ff) << 8;
        param_1[2] = *(undefined8 *)(lVar11 + 8);
        uVar12 = uVar6 - ((int)(char)bVar5 & 0x3fU);
        if (((*pbVar13 >> 6 & 1) == 0) || ((*(byte *)(param_2 + 8) & 0x30) == 0)) {
          uVar15 = *(uint *)(param_1 + 0xe);
          iVar10 = *(int *)((long)param_1 + 0x74);
          if (uVar15 - iVar10 < 4) {
            if (3 < uVar15) {
              lVar11 = __pskb_pull_tail(param_1,4 - (uVar15 - iVar10));
              if (lVar11 != 0) {
                uVar15 = *(uint *)(param_1 + 0xe);
                goto LAB_0010f28c;
              }
              goto LAB_0010f2a0;
            }
            if (iVar10 != 0) goto LAB_0010f2a8;
LAB_0010f324:
            pbVar13 = (byte *)param_1[0x1c];
          }
          else {
LAB_0010f28c:
            *(uint *)(param_1 + 0xe) = uVar15 - 4;
            param_1[0x1c] = param_1[0x1c] + 4;
LAB_0010f2a0:
            iVar10 = *(int *)((long)param_1 + 0x74);
            if (iVar10 == 0) goto LAB_0010f324;
LAB_0010f2a8:
            if (*(int *)(param_1 + 0xe) != iVar10) goto LAB_0010f324;
            lVar11 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
            pbVar13 = (byte *)(((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 |
                               0xff00000000000000) + (ulong)*(uint *)(lVar11 + 0x54));
          }
          uVar14 = 0xdd86;
          if ((*pbVar13 & 0xf0) != 0x60) {
            uVar14 = 0xf900;
          }
          uVar1 = 8;
          if ((*pbVar13 & 0xf0) != 0x40) {
            uVar1 = uVar14;
          }
          *(undefined2 *)((long)param_1 + 0xb4) = uVar1;
          if (((*(byte *)(param_2 + 8) >> 2 & 1) != 0) &&
             (iVar10 = rmnet_map_checksum_downlink_packet(param_1,uVar6), iVar10 == 0)) {
            *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xffbf | 0x20;
          }
          uVar12 = uVar12 & 0xffff;
          if (uVar12 < *(uint *)(param_1 + 0xe)) {
            if (*(int *)((long)param_1 + 0x74) == 0) {
              *(uint *)(param_1 + 0xe) = uVar12;
              *(uint *)(param_1 + 0x1a) =
                   (*(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x1b)) + uVar12;
            }
            else {
              ___pskb_trim(param_1);
            }
          }
          *param_1 = &local_60;
          param_1[1] = local_58;
          puVar8 = param_1;
          *local_58 = param_1;
          local_58 = puVar8;
          local_50 = CONCAT44(local_50._4_4_,(int)local_50 + 1);
        }
        else {
          iVar10 = rmnet_map_process_next_hdr_packet(param_1,&local_60,uVar12);
          pplVar7 = (long **)local_60;
          pplVar9 = (long **)local_58;
          if (iVar10 != 0) goto LAB_0010f240;
        }
        if ((*(byte *)(param_2 + 0xb) >> 3 & 1) != 0) {
          plVar2 = (long *)0x0;
          if ((long **)local_60 != &local_60) {
            plVar2 = local_60;
          }
          qmi_rmnet_work_maybe_restart(param_2,0,plVar2);
        }
        plVar2 = local_60;
        puVar8 = local_58;
        if ((long **)local_60 != &local_60) {
          do {
            local_60 = plVar2;
            local_58 = puVar8;
            if (plVar2 == (long *)0x0) break;
            local_50._4_4_ = (undefined4)((ulong)local_50 >> 0x20);
            local_50 = CONCAT44(local_50._4_4_,(int)local_50 + -1);
            lVar11 = *plVar2;
            plVar3 = (long *)plVar2[1];
            *plVar2 = 0;
            plVar2[1] = 0;
            *(long **)(lVar11 + 8) = plVar3;
            *plVar3 = lVar11;
            if ((*(int *)((long)plVar2 + 0x74) == 0) ||
               ((int)plVar2[0xe] != *(int *)((long)plVar2 + 0x74))) {
              pbVar13 = (byte *)plVar2[0x1c];
            }
            else {
              lVar11 = plVar2[0x1b] + (ulong)*(uint *)((long)plVar2 + 0xd4);
              pbVar13 = (byte *)(((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 |
                                 0xff00000000000000) + (ulong)*(uint *)(lVar11 + 0x54));
            }
            uVar14 = 0xdd86;
            if ((*pbVar13 & 0xf0) != 0x60) {
              uVar14 = 0xf900;
            }
            uVar1 = 8;
            if ((*pbVar13 & 0xf0) != 0x40) {
              uVar1 = uVar14;
            }
            *(undefined2 *)((long)plVar2 + 0xb4) = uVar1;
            rmnet_deliver_skb(plVar2,param_2);
            plVar2 = local_60;
            puVar8 = local_58;
          } while ((long **)local_60 != &local_60);
        }
        goto LAB_0010f24c;
      }
    }
  }
  else {
    lVar11 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
    pbVar13 = (byte *)(((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                      (ulong)*(uint *)(lVar11 + 0x54));
    bVar5 = *pbVar13;
    if (-1 < (char)bVar5) goto LAB_0010f1e4;
LAB_0010f198:
    local_60 = (long *)&local_60;
    local_58 = &local_60;
    qmi_rmnet_set_dl_msg_active(param_2);
    uVar12 = *(uint *)(param_2 + 8);
    if ((uVar12 & 0x60000000) != 0) {
      iVar10 = rmnet_map_flow_command(param_1,param_2,0);
      if (iVar10 == 0) goto LAB_0010f24c;
      uVar12 = *(uint *)(param_2 + 8);
    }
    pplVar7 = (long **)local_60;
    pplVar9 = (long **)local_58;
    if ((uVar12 >> 1 & 1) != 0) {
      rmnet_map_command(param_1,param_2);
      goto LAB_0010f24c;
    }
  }
LAB_0010f240:
  local_58 = pplVar9;
  local_60 = (long *)pplVar7;
  kfree_skb_reason(param_1,1);
LAB_0010f24c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_dl_hdr_notify_v2 @ 0010f538 size=116
// signature: undefined rmnet_map_dl_hdr_notify_v2(void)
// callers: [rmnet_frag_flow_command]
//------------------------------------------------------------

void rmnet_map_dl_hdr_notify_v2(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x9e0);
  while( true ) {
    if (plVar2 == (long *)(param_1 + 0x9e0)) {
      return;
    }
    if (*(int *)((code *)plVar2[-2] + -4) != -0xc2c6687) break;
    (*(code *)plVar2[-2])(param_2,param_3);
    plVar2 = (long *)*plVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f588);
  (*pcVar1)();
}



//------------------------------------------------------------
// rmnet_map_dl_trl_notify_v2 @ 0010f5b0 size=116
// signature: undefined rmnet_map_dl_trl_notify_v2(void)
// callers: [rmnet_frag_flow_command]
//------------------------------------------------------------

void rmnet_map_dl_trl_notify_v2(long param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0x9e0);
  while( true ) {
    if (plVar2 == (long *)(param_1 + 0x9e0)) {
      return;
    }
    if (*(int *)((code *)plVar2[-1] + -4) != 0x5fb5f8bf) break;
    (*(code *)plVar2[-1])(param_2,param_3);
    plVar2 = (long *)*plVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f600);
  (*pcVar1)();
}



//------------------------------------------------------------
// rmnet_map_pb_ind_notify @ 0010f628 size=120
// signature: undefined rmnet_map_pb_ind_notify(void)
// callers: [rmnet_frag_flow_command]
//------------------------------------------------------------

void rmnet_map_pb_ind_notify(long param_1,uint *param_2)

{
  code *pcVar1;
  long *plVar2;
  
  plVar2 = *(long **)(param_1 + 0xaf0);
  while( true ) {
    if (plVar2 == (long *)(param_1 + 0xaf0)) {
      return;
    }
    *(ulong *)(param_1 + 0xad0) = (ulong)*param_2;
    if (*(int *)((code *)plVar2[-1] + -4) != 0x54024d0f) break;
    (*(code *)plVar2[-1])(param_2);
    plVar2 = (long *)*plVar2;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10f67c);
  (*pcVar1)();
}



//------------------------------------------------------------
// rmnet_map_command @ 0010f6a4 size=408
// signature: undefined rmnet_map_command(void)
// callers: [__rmnet_map_ingress_handler]
//------------------------------------------------------------

void rmnet_map_command(long param_1,long param_2)

{
  int iVar1;
  char cVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    lVar6 = *(long *)(param_1 + 0xe0);
  }
  else {
    lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    lVar6 = ((*(ulong *)(lVar6 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
            (ulong)*(uint *)(lVar6 + 0x54);
  }
  if (*(char *)(lVar6 + 4) == '\x02') {
    uVar3 = 1;
  }
  else {
    if (*(char *)(lVar6 + 4) != '\x01') {
      kfree_skb_reason(param_1,1);
      return;
    }
    uVar3 = 0;
  }
  cVar2 = rmnet_map_do_flow_control(param_1,param_2,uVar3);
  if (cVar2 == '\x01') {
    lVar6 = *(long *)(param_1 + 0x10);
    if (((*(byte *)(param_2 + 8) >> 2 & 1) != 0) &&
       (iVar1 = *(uint *)(param_1 + 0x70) - 8, 7 < *(uint *)(param_1 + 0x70))) {
      if (*(int *)(param_1 + 0x74) == 0) {
        *(int *)(param_1 + 0x70) = iVar1;
        *(int *)(param_1 + 0xd0) = iVar1 + (*(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0xd8));
      }
      else {
        ___pskb_trim(param_1);
      }
    }
    *(undefined2 *)(param_1 + 0xb4) = 0xf900;
    if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
      lVar4 = *(long *)(param_1 + 0xe0);
    }
    else {
      lVar4 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      lVar4 = ((*(ulong *)(lVar4 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
              (ulong)*(uint *)(lVar4 + 0x54);
    }
    *(byte *)(lVar4 + 5) = *(byte *)(lVar4 + 5) & 0xfc | 1;
    netif_tx_lock(lVar6);
    pcVar5 = *(code **)(*(long *)(lVar6 + 0xd0) + 0x20);
    if (*(int *)(pcVar5 + -4) != 0x44e57e43) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10f830);
      (*pcVar5)();
    }
    (*pcVar5)(param_1,lVar6);
    netif_tx_unlock(lVar6);
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_do_flow_control @ 0010f84c size=224
// signature: undefined rmnet_map_do_flow_control(void)
// callers: [rmnet_map_command]
//------------------------------------------------------------

undefined8 rmnet_map_do_flow_control(long param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    cVar1 = *(char *)(*(long *)(param_1 + 0xe0) + 1);
  }
  else {
    lVar3 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    cVar1 = *(char *)(((*(ulong *)(lVar3 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                      (ulong)*(uint *)(lVar3 + 0x54) + 1);
  }
  if ((cVar1 == -1) || (lVar3 = rmnet_get_endpoint(param_2,cVar1), lVar3 == 0)) {
    uVar4 = 0;
  }
  else {
    iVar2 = rmnet_vnd_do_flow_control(*(undefined8 *)(lVar3 + 8),param_3);
    if (iVar2 == 0) {
      return 1;
    }
    uVar4 = 2;
  }
  kfree_skb_reason(param_1,1);
  return uVar4;
}



//------------------------------------------------------------
// rmnet_map_flow_command @ 0010f938 size=1480
// signature: undefined rmnet_map_flow_command(void)
// callers: [__rmnet_map_ingress_handler]
//------------------------------------------------------------

undefined8 rmnet_map_flow_command(long param_1,long param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  uint *puVar10;
  long *plVar11;
  
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    lVar9 = *(long *)(param_1 + 0xe0);
  }
  else {
    lVar9 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    lVar9 = ((*(ulong *)(lVar9 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
            (ulong)*(uint *)(lVar9 + 0x54);
  }
  uVar5 = (uint)*(byte *)(lVar9 + 4);
  if ((*(int *)(param_1 + 0x8c) == 0xda1a) && (uVar5 - 7 < 2)) {
LAB_0010f9d0:
    if ((param_3 & 1) != 0) {
      return 0;
    }
    goto LAB_0010f9d4;
  }
  if (uVar5 == 0x23) {
    uVar5 = *(uint *)(param_1 + 0x70);
    if (uVar5 < 0x1c) goto LAB_0010f9d0;
    uVar1 = *(uint *)(param_2 + 8);
    if ((uVar1 >> 0x1d & 1) != 0) {
      uVar8 = uVar5 - *(int *)(param_1 + 0x74);
      if (uVar8 < 0xc) {
        lVar9 = __pskb_pull_tail(param_1,0xc - uVar8);
        if (lVar9 == 0) goto LAB_0010fa68;
        uVar5 = *(uint *)(param_1 + 0x70);
      }
      *(uint *)(param_1 + 0x70) = uVar5 - 0xc;
      *(long *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + 0xc;
    }
LAB_0010fa68:
    if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
      puVar10 = *(uint **)(param_1 + 0xe0);
    }
    else {
      lVar9 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      puVar10 = (uint *)(((*(ulong *)(lVar9 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                        (ulong)*(uint *)(lVar9 + 0x54));
    }
    *(long *)(param_2 + 0xac8) = *(long *)(param_2 + 0xac8) + 1;
    if ((uVar1 >> 0x1d & 1) != 0) {
      for (plVar11 = *(long **)(param_2 + 0xaf0); plVar11 != (long *)(param_2 + 0xaf0);
          plVar11 = (long *)*plVar11) {
        *(ulong *)(param_2 + 0xad0) = (ulong)*puVar10;
        if (*(int *)((code *)plVar11[-1] + -4) != 0x54024d0f) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10fb24);
          (*pcVar3)();
        }
        (*(code *)plVar11[-1])(puVar10);
      }
    }
    if ((param_3 & 1) == 0) goto LAB_0010f9d4;
    uVar5 = *(uint *)(param_1 + 0x70);
    iVar6 = *(int *)(param_1 + 0x74);
  }
  else {
    if (uVar5 == 8) {
      uVar5 = *(uint *)(param_1 + 0x70);
      if (uVar5 < 0x10) goto LAB_0010f9d0;
      uVar1 = *(uint *)(param_2 + 8);
      if ((uVar1 >> 0x1d & 1) == 0) {
        lVar9 = 0;
      }
      else {
        uVar8 = uVar5 - *(int *)(param_1 + 0x74);
        if (uVar8 < 4) {
          lVar9 = __pskb_pull_tail(param_1,4 - uVar8);
          if (lVar9 != 0) {
            uVar5 = *(uint *)(param_1 + 0x70);
            goto LAB_0010fbc4;
          }
        }
        else {
LAB_0010fbc4:
          *(uint *)(param_1 + 0x70) = uVar5 - 4;
          *(long *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + 4;
        }
        iVar6 = *(int *)(param_1 + 0x74);
        if ((iVar6 == 0) || (*(int *)(param_1 + 0x70) != iVar6)) {
          lVar9 = *(long *)(param_1 + 0xe0);
        }
        else {
          lVar9 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
          lVar9 = ((*(ulong *)(lVar9 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                  (ulong)*(uint *)(lVar9 + 0x54);
          iVar6 = *(int *)(param_1 + 0x74);
        }
        uVar5 = *(uint *)(param_1 + 0x70);
        if (uVar5 - iVar6 < 8) {
          if ((uVar5 < 8) || (lVar4 = __pskb_pull_tail(param_1,8 - (uVar5 - iVar6)), lVar4 == 0))
          goto LAB_0010fd8c;
          uVar5 = *(uint *)(param_1 + 0x70);
        }
        *(uint *)(param_1 + 0x70) = uVar5 - 8;
        *(long *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + 8;
      }
LAB_0010fd8c:
      if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74)))
      {
        puVar10 = *(uint **)(param_1 + 0xe0);
      }
      else {
        lVar4 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
        puVar10 = (uint *)(((*(ulong *)(lVar4 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000)
                          + (ulong)*(uint *)(lVar4 + 0x54));
      }
      *(ulong *)(param_2 + 0xa40) = (ulong)*puVar10;
      *(long *)(param_2 + 0xa48) = *(long *)(param_2 + 0xa48) + 1;
      if ((uVar1 >> 0x1d & 1) != 0) {
        for (plVar11 = *(long **)(param_2 + 0x9e0); plVar11 != (long *)(param_2 + 0x9e0);
            plVar11 = (long *)*plVar11) {
          if (*(int *)((code *)plVar11[-1] + -4) != 0x5fb5f8bf) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10fe28);
            (*pcVar3)();
          }
          (*(code *)plVar11[-1])(puVar10,lVar9);
        }
      }
      if ((param_3 & 1) == 0) goto LAB_0010f9d4;
      uVar5 = *(uint *)(param_1 + 0x70);
      iVar6 = *(int *)(param_1 + 0x74);
      uVar7 = 0xc;
      uVar8 = 4;
      goto LAB_0010fe4c;
    }
    if (uVar5 != 7) {
      return 1;
    }
    uVar5 = *(uint *)(param_1 + 0x70);
    if (uVar5 < 0x1c) goto LAB_0010f9d0;
    uVar1 = *(uint *)(param_2 + 8);
    if ((uVar1 >> 0x1d & 1) == 0) {
      lVar9 = 0;
LAB_0010fc70:
      iVar6 = *(int *)(param_1 + 0x74);
    }
    else {
      uVar8 = uVar5 - *(int *)(param_1 + 0x74);
      if (uVar8 < 4) {
        lVar9 = __pskb_pull_tail(param_1,4 - uVar8);
        if (lVar9 != 0) {
          uVar5 = *(uint *)(param_1 + 0x70);
          goto LAB_0010fb54;
        }
      }
      else {
LAB_0010fb54:
        *(uint *)(param_1 + 0x70) = uVar5 - 4;
        *(long *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + 4;
      }
      if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74)))
      {
        lVar9 = *(long *)(param_1 + 0xe0);
      }
      else {
        lVar9 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
        lVar9 = ((*(ulong *)(lVar9 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                (ulong)*(uint *)(lVar9 + 0x54);
      }
      *(ulong *)(param_2 + 0x9f8) = (ulong)*(ushort *)(lVar9 + 2) & 0x7fff;
      *(ulong *)(param_2 + 0x9f0) = (ulong)(*(ushort *)(lVar9 + 1) >> 2) & 0x1f;
      *(ulong *)(param_2 + 0xa00) = (ulong)*(uint *)(lVar9 + 4);
      uVar5 = *(uint *)(param_1 + 0x70);
      iVar6 = *(int *)(param_1 + 0x74);
      if (7 < uVar5 - iVar6) {
LAB_0010fc5c:
        *(uint *)(param_1 + 0x70) = uVar5 - 8;
        *(long *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + 8;
        goto LAB_0010fc70;
      }
      if (7 < uVar5) {
        lVar4 = __pskb_pull_tail(param_1,8 - (uVar5 - iVar6));
        if (lVar4 == 0) goto LAB_0010fc70;
        uVar5 = *(uint *)(param_1 + 0x70);
        goto LAB_0010fc5c;
      }
    }
    if ((iVar6 == 0) || (*(int *)(param_1 + 0x70) != iVar6)) {
      puVar10 = *(uint **)(param_1 + 0xe0);
    }
    else {
      lVar4 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      puVar10 = (uint *)(((*(ulong *)(lVar4 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                        (ulong)*(uint *)(lVar4 + 0x54));
    }
    *(ulong *)(param_2 + 0xa08) = (ulong)*puVar10;
    uVar5 = puVar10[1];
    *(ulong *)(param_2 + 0xa10) = (ulong)uVar5;
    uVar8 = puVar10[2];
    *(ulong *)(param_2 + 0xa18) = (ulong)uVar8;
    uVar7 = puVar10[3];
    *(ulong *)(param_2 + 0xa30) = *(long *)(param_2 + 0xa30) + (ulong)uVar5;
    *(ulong *)(param_2 + 0xa38) = *(long *)(param_2 + 0xa38) + (ulong)uVar8;
    *(ulong *)(param_2 + 0xa20) = (ulong)uVar7;
    *(long *)(param_2 + 0xa28) = *(long *)(param_2 + 0xa28) + 1;
    if ((uVar1 >> 0x1d & 1) != 0) {
      for (plVar11 = *(long **)(param_2 + 0x9e0); plVar11 != (long *)(param_2 + 0x9e0);
          plVar11 = (long *)*plVar11) {
        if (*(int *)((code *)plVar11[-2] + -4) != -0xc2c6687) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10fd3c);
          (*pcVar3)();
        }
        (*(code *)plVar11[-2])(puVar10,lVar9);
      }
    }
    if ((param_3 & 1) == 0) {
LAB_0010f9d4:
      consume_skb(param_1);
      return 0;
    }
    uVar5 = *(uint *)(param_1 + 0x70);
    iVar6 = *(int *)(param_1 + 0x74);
  }
  uVar7 = 0x18;
  uVar8 = 0x10;
LAB_0010fe4c:
  if ((uVar1 & 4) != 0) {
    uVar8 = uVar7;
  }
  iVar2 = uVar8 - (uVar5 - iVar6);
  if (uVar5 - iVar6 <= uVar8 && iVar2 != 0) {
    if (uVar5 < uVar8) {
      return 0;
    }
    lVar9 = __pskb_pull_tail(param_1,iVar2);
    if (lVar9 == 0) {
      return 0;
    }
    uVar5 = *(uint *)(param_1 + 0x70);
  }
  *(uint *)(param_1 + 0x70) = uVar5 - uVar8;
  *(ulong *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + (ulong)uVar8;
  return 0;
}



//------------------------------------------------------------
// rmnet_map_cmd_exit @ 0010ff34 size=188
// signature: undefined rmnet_map_cmd_exit(void)
// callers: [rmnet_unregister_real_device]
//------------------------------------------------------------

void rmnet_map_cmd_exit(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar3 = *(long **)(param_1 + 0x9e0);
  while (plVar3 != (long *)(param_1 + 0x9e0)) {
    plVar5 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    plVar3[1] = -0x2152fffffffffede;
    plVar3 = plVar5;
  }
  plVar3 = *(long **)(param_1 + 0xaf0);
  while (plVar3 != (long *)(param_1 + 0xaf0)) {
    plVar5 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    plVar3[1] = -0x2152fffffffffede;
    plVar3 = plVar5;
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_cmd_init @ 0010fff4 size=28
// signature: undefined rmnet_map_cmd_init(void)
// callers: [rmnet_register_real_device]
//------------------------------------------------------------

void rmnet_map_cmd_init(long param_1)

{
  *(long *)(param_1 + 0x9e0) = param_1 + 0x9e0;
  *(long *)(param_1 + 0x9e8) = param_1 + 0x9e0;
  *(long *)(param_1 + 0xaf0) = param_1 + 0xaf0;
  *(long *)(param_1 + 0xaf8) = param_1 + 0xaf0;
  return;
}



//------------------------------------------------------------
// rmnet_map_dl_ind_register @ 00110014 size=340
// signature: undefined rmnet_map_dl_ind_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_map_dl_ind_register(long param_1,byte *param_2)

{
  byte *pbVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  
  uVar2 = 0xffffffea;
  if ((((param_1 != 0) && (param_2 != (byte *)0x0)) && (*(long *)(param_2 + 8) != 0)) &&
     (*(long *)(param_2 + 0x10) != 0)) {
    plVar4 = *(long **)(param_1 + 0x9e0);
    plVar6 = (long *)(param_1 + 0x9e0);
    if (plVar4 == plVar6) {
      pbVar1 = param_2 + 0x18;
      uVar3 = __list_add_valid(pbVar1,plVar6,plVar6);
      if ((uVar3 & 1) != 0) {
        *(long **)(param_2 + 0x18) = plVar6;
        *(long **)(param_2 + 0x20) = plVar6;
        *(byte **)(param_1 + 0x9e0) = pbVar1;
        *(byte **)(param_1 + 0x9e8) = pbVar1;
        return 0;
      }
    }
    else {
      do {
        if (*param_2 <= *(byte *)(plVar4 + -3)) {
          plVar6 = (long *)plVar4[1];
          pbVar1 = param_2 + 0x18;
          uVar3 = __list_add_valid(pbVar1,plVar6,plVar4);
          if ((uVar3 & 1) != 0) {
            *(long **)(param_2 + 0x18) = plVar4;
            *(long **)(param_2 + 0x20) = plVar6;
            *plVar6 = (long)pbVar1;
            plVar4[1] = (long)pbVar1;
            return 0;
          }
          break;
        }
        if (*plVar4 == 0) {
          pbVar1 = param_2 + 0x18;
          uVar3 = __list_add_valid(pbVar1,plVar4,0);
          if ((uVar3 & 1) != 0) {
            param_2[0x18] = 0;
            param_2[0x19] = 0;
            param_2[0x1a] = 0;
            param_2[0x1b] = 0;
            param_2[0x1c] = 0;
            param_2[0x1d] = 0;
            param_2[0x1e] = 0;
            param_2[0x1f] = 0;
            *(long **)(param_2 + 0x20) = plVar4;
            *plVar4 = (long)pbVar1;
            _DAT_00000008 = pbVar1;
            return 0;
          }
          break;
        }
        lVar5 = *plVar4;
        if (*param_2 < *(byte *)(lVar5 + -0x18)) {
          pbVar1 = param_2 + 0x18;
          uVar3 = __list_add_valid(pbVar1,plVar4,lVar5);
          if ((uVar3 & 1) != 0) {
            *(long *)(param_2 + 0x18) = lVar5;
            *(long **)(param_2 + 0x20) = plVar4;
            *plVar4 = (long)pbVar1;
            *(byte **)(lVar5 + 8) = pbVar1;
            return 0;
          }
          break;
        }
        plVar4 = (long *)*plVar4;
      } while (plVar4 != plVar6);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_map_dl_ind_deregister @ 0011016c size=144
// signature: undefined rmnet_map_dl_ind_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_map_dl_ind_deregister(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  
  uVar2 = 0xffffffea;
  if (((param_1 != 0) && (param_2 != 0)) &&
     (plVar4 = *(long **)(param_1 + 0x9e0), plVar4 != (long *)0x0)) {
    for (; plVar4 != (long *)(param_1 + 0x9e0); plVar4 = (long *)*plVar4) {
      if (plVar4 + -3 == (long *)param_2) {
        uVar3 = __list_del_entry_valid(param_2 + 0x18);
        if ((uVar3 & 1) != 0) {
          lVar1 = *(long *)(param_2 + 0x18);
          plVar4 = *(long **)(param_2 + 0x20);
          *(long **)(lVar1 + 8) = plVar4;
          *plVar4 = lVar1;
        }
        *(undefined8 *)(param_2 + 0x20) = 0xdead000000000122;
        return 0;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_map_pb_ind_register @ 00110200 size=332
// signature: undefined rmnet_map_pb_ind_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_map_pb_ind_register(long param_1,byte *param_2)

{
  byte *pbVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  
  uVar2 = 0xffffffea;
  if (((param_1 != 0) && (param_2 != (byte *)0x0)) && (*(long *)(param_2 + 8) != 0)) {
    plVar4 = *(long **)(param_1 + 0xaf0);
    plVar6 = (long *)(param_1 + 0xaf0);
    if (plVar4 == plVar6) {
      pbVar1 = param_2 + 0x10;
      uVar3 = __list_add_valid(pbVar1,plVar6,plVar6);
      if ((uVar3 & 1) != 0) {
        *(long **)(param_2 + 0x10) = plVar6;
        *(long **)(param_2 + 0x18) = plVar6;
        *(byte **)(param_1 + 0xaf0) = pbVar1;
        *(byte **)(param_1 + 0xaf8) = pbVar1;
        return 0;
      }
    }
    else {
      do {
        if (*param_2 <= *(byte *)(plVar4 + -2)) {
          plVar6 = (long *)plVar4[1];
          pbVar1 = param_2 + 0x10;
          uVar3 = __list_add_valid(pbVar1,plVar6,plVar4);
          if ((uVar3 & 1) != 0) {
            *(long **)(param_2 + 0x10) = plVar4;
            *(long **)(param_2 + 0x18) = plVar6;
            *plVar6 = (long)pbVar1;
            plVar4[1] = (long)pbVar1;
            return 0;
          }
          break;
        }
        if (*plVar4 == 0) {
          pbVar1 = param_2 + 0x10;
          uVar3 = __list_add_valid(pbVar1,plVar4,0);
          if ((uVar3 & 1) != 0) {
            param_2[0x10] = 0;
            param_2[0x11] = 0;
            param_2[0x12] = 0;
            param_2[0x13] = 0;
            param_2[0x14] = 0;
            param_2[0x15] = 0;
            param_2[0x16] = 0;
            param_2[0x17] = 0;
            *(long **)(param_2 + 0x18) = plVar4;
            *plVar4 = (long)pbVar1;
            _DAT_00000008 = pbVar1;
            return 0;
          }
          break;
        }
        lVar5 = *plVar4;
        if (*param_2 < *(byte *)(lVar5 + -0x10)) {
          pbVar1 = param_2 + 0x10;
          uVar3 = __list_add_valid(pbVar1,plVar4,lVar5);
          if ((uVar3 & 1) != 0) {
            *(long *)(param_2 + 0x10) = lVar5;
            *(long **)(param_2 + 0x18) = plVar4;
            *plVar4 = (long)pbVar1;
            *(byte **)(lVar5 + 8) = pbVar1;
            return 0;
          }
          break;
        }
        plVar4 = (long *)*plVar4;
      } while (plVar4 != plVar6);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_map_pb_ind_deregister @ 00110350 size=144
// signature: undefined rmnet_map_pb_ind_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_map_pb_ind_deregister(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  
  uVar2 = 0xffffffea;
  if (((param_1 != 0) && (param_2 != 0)) &&
     (plVar4 = *(long **)(param_1 + 0xaf0), plVar4 != (long *)0x0)) {
    for (; plVar4 != (long *)(param_1 + 0xaf0); plVar4 = (long *)*plVar4) {
      if (plVar4 + -2 == (long *)param_2) {
        uVar3 = __list_del_entry_valid(param_2 + 0x10);
        if ((uVar3 & 1) != 0) {
          lVar1 = *(long *)(param_2 + 0x10);
          plVar4 = *(long **)(param_2 + 0x18);
          *(long **)(lVar1 + 8) = plVar4;
          *plVar4 = lVar1;
        }
        *(undefined8 *)(param_2 + 0x18) = 0xdead000000000122;
        return 0;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_map_add_map_header @ 001103e4 size=240
// signature: undefined rmnet_map_add_map_header(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

byte * rmnet_map_add_map_header(long param_1,int param_2,int param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  void *__s;
  byte bVar5;
  
  iVar2 = *(int *)(param_1 + 0x70);
  pbVar4 = (byte *)skb_push(param_1,4);
  pbVar4[0] = 0;
  pbVar4[1] = 0;
  pbVar4[2] = 0;
  pbVar4[3] = 0;
  bVar5 = 0;
  if ((*(byte *)(param_4 + 8) >> 6 & 1) != 0) {
    bVar5 = 0x40;
    *pbVar4 = 0x40;
  }
  uVar3 = iVar2 - param_2;
  if (param_3 == 0) {
    *(ushort *)(pbVar4 + 2) = (ushort)(uVar3 >> 8) & 0xff | (ushort)((uVar3 & 0xff00ff) << 8);
    return pbVar4;
  }
  uVar1 = uVar3 + 3;
  uVar3 = (uVar1 & 0xfffffffc) - uVar3;
  if (uVar3 == 0) {
LAB_001104a4:
    *pbVar4 = bVar5 & 0xc0 | (byte)uVar3 & 0x3f;
    *(ushort *)(pbVar4 + 2) = (ushort)(uVar1 >> 8) & 0xff | (ushort)((uVar1 & 0xff00fc) << 8);
  }
  else {
    if (*(int *)(param_1 + 0x74) == 0) {
      if (uVar3 <= (uint)(*(int *)(param_1 + 0xd4) - *(int *)(param_1 + 0xd0))) goto LAB_00110488;
    }
    else if (uVar3 == 0) {
LAB_00110488:
      __s = (void *)skb_put(param_1,(ulong)uVar3);
      memset(__s,0,(ulong)uVar3);
      bVar5 = *pbVar4;
      goto LAB_001104a4;
    }
    pbVar4 = (byte *)0x0;
  }
  return pbVar4;
}



//------------------------------------------------------------
// rmnet_map_deaggregate @ 001104d8 size=504
// signature: undefined rmnet_map_deaggregate(void)
// callers: [rmnet_rx_handler]
//------------------------------------------------------------

long rmnet_map_deaggregate(long param_1,long param_2)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  char *__src;
  undefined8 uVar10;
  
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    __src = *(char **)(param_1 + 0xe0);
    iVar1 = *(int *)(param_1 + 0x70);
  }
  else {
    lVar5 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    __src = (char *)(((*(ulong *)(lVar5 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                    (ulong)*(uint *)(lVar5 + 0x54));
    iVar1 = *(int *)(param_1 + 0x70);
  }
  if (iVar1 == 0) {
    lVar5 = 0;
  }
  else {
    uVar2 = *(ushort *)(__src + 2);
    uVar7 = (uint)(uVar2 >> 8) | (uVar2 & 0xff00ff) << 8;
    if ((*(uint *)(param_2 + 8) >> 2 & 1) == 0) {
      uVar9 = uVar7 + 4;
      if ((*(uint *)(param_2 + 8) >> 5 & 1) == 0) {
        puVar8 = (uint *)0x0;
      }
      else {
        bVar4 = ((long)*__src & 0x80000000U) == 0;
        if (bVar4) {
          uVar9 = uVar7 + 8;
        }
        puVar8 = (uint *)0x0;
        if (bVar4) {
          puVar8 = (uint *)(__src + 4);
        }
      }
    }
    else {
      puVar8 = (uint *)0x0;
      uVar9 = uVar7 + 0xc;
    }
    lVar5 = 0;
    if ((-1 < (int)(iVar1 - uVar9)) && (uVar2 != 0)) {
      if ((puVar8 == (uint *)0x0) || ((*puVar8 & 0xfe) != 2)) {
        if (*(int *)(param_1 + 0x74) == 0) {
          lVar5 = __alloc_skb(uVar9 + 0x40,0xa20,0,0xffffffff);
          if (lVar5 == 0) {
            return 0;
          }
          *(long *)(lVar5 + 0xe0) = *(long *)(lVar5 + 0xe0) + 0x20;
          *(int *)(lVar5 + 0xd0) = *(int *)(lVar5 + 0xd0) + 0x20;
          skb_put(lVar5,uVar9);
          memcpy(*(void **)(lVar5 + 0xe0),__src,(ulong)uVar9);
        }
        else {
          lVar6 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
          uVar10 = *(undefined8 *)(lVar6 + 0x48);
          lVar5 = __alloc_skb(0x20,0xa20,0,0xffffffff);
          if (lVar5 == 0) {
            return 0;
          }
          skb_append_pagefrags(lVar5,uVar10,*(undefined4 *)(lVar6 + 0x54),uVar9);
          *(uint *)(lVar5 + 0x70) = *(int *)(lVar5 + 0x70) + uVar9;
          *(uint *)(lVar5 + 0x74) = *(int *)(lVar5 + 0x74) + uVar9;
        }
        *(undefined4 *)(lVar5 + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
        uVar7 = *(uint *)(param_1 + 0x70);
        uVar3 = uVar7 - *(int *)(param_1 + 0x74);
        iVar1 = uVar9 - uVar3;
        if (uVar3 <= uVar9 && iVar1 != 0) {
          if (uVar7 < uVar9) {
            return lVar5;
          }
          lVar6 = __pskb_pull_tail(param_1,iVar1);
          if (lVar6 == 0) {
            return lVar5;
          }
          uVar7 = *(uint *)(param_1 + 0x70);
        }
        *(uint *)(param_1 + 0x70) = uVar7 - uVar9;
        *(ulong *)(param_1 + 0xe0) = *(long *)(param_1 + 0xe0) + (ulong)uVar9;
      }
      else {
        lVar5 = param_1;
      }
    }
  }
  return lVar5;
}



//------------------------------------------------------------
// rmnet_map_checksum_downlink_packet @ 001106dc size=1036
// signature: undefined rmnet_map_checksum_downlink_packet(void)
// callers: [__rmnet_map_ingress_handler]
//------------------------------------------------------------

undefined4 rmnet_map_checksum_downlink_packet(long param_1,ushort param_2)

{
  ushort *puVar1;
  ulong uVar2;
  ulong uVar3;
  char cVar4;
  ushort uVar5;
  bool bVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  undefined4 uVar10;
  long lVar11;
  uint uVar12;
  ulong uVar13;
  int iVar14;
  ulong *puVar15;
  ulong *puVar16;
  long lVar17;
  ushort *puVar18;
  
  lVar17 = *(long *)(param_1 + 0x10);
  if ((*(byte *)(lVar17 + 0xed) & 1) == 0) {
    uVar10 = 0xffffffa1;
    lVar9 = 0xaa0;
    goto LAB_001109cc;
  }
  if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
    lVar9 = *(long *)(param_1 + 0xe0);
  }
  else {
    lVar9 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    lVar9 = ((*(ulong *)(lVar9 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
            (ulong)*(uint *)(lVar9 + 0x54);
  }
  lVar9 = lVar9 + (ulong)param_2;
  if ((*(byte *)(lVar9 + 1) & 1) == 0) {
    uVar10 = 0xffffffea;
    lVar9 = 0xa68;
    goto LAB_001109cc;
  }
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
      lVar11 = *(long *)(param_1 + 0xe0);
    }
    else {
      lVar11 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      lVar11 = ((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)(lVar11 + 0x54);
    }
    if (*(char *)(lVar11 + 6) == '\x06') {
      puVar18 = (ushort *)(lVar11 + 0x38);
    }
    else {
      if (*(char *)(lVar11 + 6) != '\x11') goto LAB_001109c4;
      puVar18 = (ushort *)(lVar11 + 0x2e);
    }
    if (puVar18 == (ushort *)0x0) goto LAB_001109c4;
    uVar5 = *(ushort *)(lVar9 + 6);
    uVar7 = ip_compute_csum(lVar11,0x28);
    puVar1 = (ushort *)(lVar11 + 0x2c);
    if (*(char *)(lVar11 + 6) != '\x11') {
      puVar1 = (ushort *)(lVar11 + 4);
    }
    uVar7 = (((uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8) & 0xffff) +
            (((~(uint)uVar5 & 0xff00ff00) >> 8 | (~(uint)uVar5 & 0xff00ff) << 8) & 0xffff);
    uVar8 = csum_ipv6_magic(lVar11 + 8,lVar11 + 0x18,*puVar1 >> 8 | *puVar1 << 8,
                            *(char *)(lVar11 + 6),0);
    uVar5 = *puVar18;
    uVar12 = (uint)(uVar5 >> 8) | (uVar5 & 0xff00ff) << 8;
    uVar7 = (((~uVar8 & 0xff00ff00) >> 8 | (~uVar8 & 0xff00ff) << 8) & 0xffff) +
            (uVar7 + (uVar7 >> 0x10) & 0xffff);
    uVar7 = uVar7 + ~uVar12 + (uVar7 >> 0x10);
    if ((uVar7 & 0xffff) < (~uVar12 & 0xffff)) {
      uVar7 = uVar7 + 1;
    }
    uVar8 = ~uVar7;
    if (((uVar7 ^ 0xffffffff) & 0xffff) == 0) {
      if (*(char *)(lVar11 + 6) == '\x06') {
LAB_00110af8:
        if (uVar5 == 0xffff) {
          uVar8 = 0xffffffff;
        }
      }
      else {
        if (*(char *)(lVar11 + 6) != '\x11') goto LAB_00110af0;
LAB_00110ac8:
        uVar8 = 0xffff;
      }
    }
  }
  else {
    if (*(short *)(param_1 + 0xb4) != 8) {
      uVar10 = 0xffffffa3;
      lVar9 = 0xa80;
      goto LAB_001109cc;
    }
    if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
      puVar16 = *(ulong **)(param_1 + 0xe0);
    }
    else {
      lVar11 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      puVar16 = (ulong *)(((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000)
                         + (ulong)*(uint *)(lVar11 + 0x54));
    }
    if ((*puVar16 & 0xff3f000000000000) != 0) {
      uVar10 = 0xffffffa1;
      lVar9 = 0xa90;
      goto LAB_001109cc;
    }
    if ((*(int *)(param_1 + 0x74) == 0) || (*(int *)(param_1 + 0x70) != *(int *)(param_1 + 0x74))) {
      lVar11 = *(long *)(param_1 + 0xe0);
    }
    else {
      lVar11 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      lVar11 = ((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
               (ulong)*(uint *)(lVar11 + 0x54);
    }
    cVar4 = *(char *)((long)puVar16 + 9);
    lVar11 = lVar11 + ((ulong)(byte)*puVar16 & 0xf) * 4;
    if (cVar4 == '\x11') {
      puVar18 = (ushort *)(lVar11 + 6);
    }
    else {
      if (cVar4 != '\x06') goto LAB_001109c4;
      puVar18 = (ushort *)(lVar11 + 0x10);
    }
    if (puVar18 == (ushort *)0x0) {
LAB_001109c4:
      uVar10 = 0xffffffa3;
      lVar9 = 0xa88;
      goto LAB_001109cc;
    }
    if ((cVar4 == '\x11') && (*puVar18 == 0)) {
      uVar10 = 0;
      lVar9 = 0xa98;
      goto LAB_001109cc;
    }
    uVar2 = *puVar16;
    uVar3 = puVar16[1];
    iVar14 = ((byte)*puVar16 & 0xf) - 3;
    uVar13 = uVar2 + uVar3 + (ulong)CARRY8(uVar3,uVar2);
    puVar15 = puVar16 + 2;
    do {
      iVar14 = iVar14 + -1;
      uVar13 = uVar13 + (uint)*puVar15;
      puVar15 = (ulong *)((long)puVar15 + 4);
    } while (1 < iVar14);
    uVar12 = (uint)(uVar2 >> 0x10);
    uVar7 = (uint)((uVar13 >> 0x20 | uVar13 << 0x20) + uVar13 >> 0x20);
    uVar7 = (((~(uint)*(ushort *)(lVar9 + 6) & 0xff00ff00) >> 8 |
             (~(uint)*(ushort *)(lVar9 + 6) & 0xff00ff) << 8) & 0xffff) +
            (~((uVar7 >> 0x10 | uVar7 << 0x10) + uVar7) >> 0x10);
    uVar8 = csum_tcpudp_nofold(uVar3 >> 0x20,(int)puVar16[2],
                               (((uVar12 & 0xff00ff00) >> 8 | (uVar12 & 0xff00ff) << 8) & 0xffff) +
                               ((uint)uVar2 & 0xf) * -4,cVar4,0);
    uVar5 = *puVar18;
    uVar8 = (uVar8 >> 0x10 | uVar8 << 0x10) + uVar8;
    uVar12 = (uint)(uVar5 >> 8) | (uVar5 & 0xff00ff) << 8;
    uVar7 = (uVar7 + (uVar7 >> 0x10) & 0xffff) +
            (((uVar8 & 0xff00ff00) >> 8 | (uVar8 & 0xff00ff) << 8) >> 0x10);
    uVar7 = uVar7 + ~uVar12 + (uVar7 >> 0x10);
    if ((uVar7 & 0xffff) < (~uVar12 & 0xffff)) {
      uVar7 = uVar7 + 1;
    }
    uVar8 = ~uVar7;
    if (((uVar7 ^ 0xffffffff) & 0xffff) == 0) {
      if (*(char *)((long)puVar16 + 9) == '\x06') goto LAB_00110af8;
      if (*(char *)((long)puVar16 + 9) == '\x11') goto LAB_00110ac8;
LAB_00110af0:
      uVar8 = 0;
    }
  }
  bVar6 = (uVar8 & 0xffff) != uVar12;
  lVar9 = 0xa60;
  if (bVar6) {
    lVar9 = 0xa70;
  }
  uVar10 = 0;
  if (bVar6) {
    uVar10 = 0xffffffea;
  }
LAB_001109cc:
  *(long *)(lVar17 + lVar9) = *(long *)(lVar17 + lVar9) + 1;
  return uVar10;
}



//------------------------------------------------------------
// rmnet_map_v4_checksum_uplink_packet @ 00110b0c size=416
// signature: undefined rmnet_map_v4_checksum_uplink_packet(void)
// callers: [rmnet_map_checksum_uplink_packet]
//------------------------------------------------------------

void rmnet_map_v4_checksum_uplink_packet(long param_1,long param_2)

{
  ushort *puVar1;
  uint uVar2;
  ulong uVar3;
  ushort *puVar4;
  long lVar5;
  long lVar6;
  
  puVar4 = (ushort *)skb_push(param_1,4);
  if (((*(byte *)(param_2 + 0xe8) & 0x12) != 0) &&
     (((*(ushort *)(param_1 + 0x80) ^ 0xffff) & 0x60) == 0)) {
    puVar1 = puVar4 + 2;
    if (*(short *)(param_1 + 0xb4) == -0x227a) {
      uVar2 = (*(int *)(param_1 + 0xd8) + (uint)*(ushort *)(param_1 + 0xb6)) - (int)puVar1;
      *puVar4 = (ushort)(uVar2 >> 8) & 0xff | (ushort)((uVar2 & 0xff00ff) << 8);
      uVar2 = *(ushort *)(param_1 + 0x8a) | 0xc000;
      if ((char)puVar4[5] != '\x11') {
        uVar2 = *(ushort *)(param_1 + 0x8a) & 0x3fff | 0x8000;
      }
      puVar4[1] = (ushort)(uVar2 >> 8) | (ushort)((uVar2 & 0xff00ff) << 8);
      *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xff9f;
      if ((char)puVar4[5] == '\x06') {
        lVar6 = 0x38;
      }
      else {
        if ((char)puVar4[5] != '\x11') {
LAB_00110c74:
          lVar5 = 0xaa8;
          goto LAB_00110c58;
        }
        lVar6 = 0x2e;
      }
      lVar5 = 0xaa8;
      *(ushort *)((long)puVar1 + lVar6) = ~*(ushort *)((long)puVar1 + lVar6);
      goto LAB_00110c58;
    }
    if (*(short *)(param_1 + 0xb4) == 8) {
      uVar2 = (*(int *)(param_1 + 0xd8) + (uint)*(ushort *)(param_1 + 0xb6)) - (int)puVar1;
      *puVar4 = (ushort)(uVar2 >> 8) & 0xff | (ushort)((uVar2 & 0xff00ff) << 8);
      uVar2 = *(ushort *)(param_1 + 0x8a) | 0xc000;
      if (*(char *)((long)puVar4 + 0xd) != '\x11') {
        uVar2 = *(ushort *)(param_1 + 0x8a) & 0x3fff | 0x8000;
      }
      puVar4[1] = (ushort)(uVar2 >> 8) | (ushort)((uVar2 & 0xff00ff) << 8);
      *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xff9f;
      uVar3 = (ulong)(byte)puVar4[2] & 0xf;
      if (*(char *)((long)puVar4 + 0xd) == '\x11') {
        lVar6 = uVar3 * 2 + 3;
      }
      else {
        if (*(char *)((long)puVar4 + 0xd) != '\x06') goto LAB_00110c74;
        lVar6 = uVar3 * 2 + 8;
      }
      lVar5 = 0xaa8;
      puVar1[lVar6] = ~puVar1[lVar6];
      goto LAB_00110c58;
    }
    *(long *)(param_2 + 0xa80) = *(long *)(param_2 + 0xa80) + 1;
  }
  lVar5 = 0xaa0;
  puVar4[0] = 0;
  puVar4[1] = 0;
LAB_00110c58:
  *(long *)(param_2 + lVar5) = *(long *)(param_2 + lVar5) + 1;
  return;
}



//------------------------------------------------------------
// rmnet_map_v5_checksum_uplink_packet @ 00110cb0 size=348
// signature: undefined rmnet_map_v5_checksum_uplink_packet(void)
// callers: [rmnet_map_checksum_uplink_packet]
//------------------------------------------------------------

void rmnet_map_v5_checksum_uplink_packet(long param_1,long param_2,long param_3)

{
  ushort *puVar1;
  uint uVar2;
  long lVar3;
  ushort *puVar4;
  ushort *puVar5;
  
  puVar1 = (ushort *)skb_push(param_1,4);
  puVar1[0] = 4;
  puVar1[1] = 0;
  if ((*(byte *)(param_2 + 0xb) >> 4 & 1) != 0) {
    uVar2 = *(uint *)(param_1 + 0x8c);
    if (uVar2 == 0xda001a) {
      *(long *)(param_3 + 0xbd8) = *(long *)(param_3 + 0xbd8) + 1;
      *puVar1 = *puVar1 | 0x2000;
      uVar2 = *(uint *)(param_1 + 0x8c);
    }
    if ((uVar2 & 0xffff0200) == 0x9b6d0200) {
      *(long *)(param_3 + 0xc18) = *(long *)(param_3 + 0xc18) + 1;
      *puVar1 = *puVar1 | 0x1000;
    }
  }
  if ((*(byte *)(param_2 + 8) >> 6 & 1) == 0) {
    return;
  }
  if (((*(ushort *)(param_1 + 0x80) ^ 0xffff) & 0x60) == 0) {
    if (*(short *)(param_1 + 0xb4) == -0x227a) {
      puVar5 = puVar1 + 5;
      puVar4 = puVar1 + 0x16;
    }
    else {
      if (*(short *)(param_1 + 0xb4) != 8) {
        lVar3 = 0xaa0;
        *(long *)(param_3 + 0xa80) = *(long *)(param_3 + 0xa80) + 1;
        goto LAB_00110db4;
      }
      puVar5 = (ushort *)((long)puVar1 + 0xd);
      puVar4 = puVar1 + 2 + ((ulong)(byte)puVar1[2] & 0xf) * 2;
    }
    if ((char)*puVar5 == '\x11') {
      if (puVar4 != (ushort *)0xfffffffffffffffa) goto LAB_00110df0;
    }
    else if (((char)*puVar5 == '\x06') && (puVar4 != (ushort *)0xfffffffffffffff0)) {
LAB_00110df0:
      *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xff9f;
      lVar3 = 0xaa8;
      *puVar1 = *puVar1 | 0x8000;
      goto LAB_00110db4;
    }
  }
  lVar3 = 0xaa0;
LAB_00110db4:
  *(long *)(param_3 + lVar3) = *(long *)(param_3 + lVar3) + 1;
  return;
}



//------------------------------------------------------------
// rmnet_map_checksum_uplink_packet @ 00110e10 size=56
// signature: undefined rmnet_map_checksum_uplink_packet(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

void rmnet_map_checksum_uplink_packet
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  if (param_4 == 0x40) {
    rmnet_map_v5_checksum_uplink_packet();
  }
  else if (param_4 == 8) {
    rmnet_map_v4_checksum_uplink_packet(param_1,param_3);
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_v5_csum_buggy @ 00110e4c size=80
// signature: undefined rmnet_map_v5_csum_buggy(void)
// callers: [rmnet_frag_process_next_hdr_packet]
//------------------------------------------------------------

undefined8 rmnet_map_v5_csum_buggy(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  if ((((uVar1 & 0x7000) == 0x1000) && (*(char *)((long)param_1 + 7) == '\x01')) &&
     ((uVar2 = uVar1 >> 0x10 & 0xf, uVar2 == 4 || ((uVar2 == 3 && ((uVar1 >> 0x14 & 0xf) - 1 < 3))))
     )) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_map_process_next_hdr_packet @ 00110ea0 size=2700
// signature: undefined rmnet_map_process_next_hdr_packet(void)
// callers: [__rmnet_map_ingress_handler]
//------------------------------------------------------------

void rmnet_map_process_next_hdr_packet(long *param_1,long *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  short sVar10;
  bool bVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  undefined8 uVar16;
  int iVar17;
  long lVar18;
  long lVar19;
  long *plVar20;
  undefined2 uVar21;
  undefined4 uVar22;
  long lVar23;
  uint *puVar24;
  ulong uVar25;
  ushort uVar26;
  byte *pbVar27;
  byte local_90 [4];
  short local_8c [2];
  byte *local_88;
  byte *local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar18 = sp_el0;
  local_68 = *(long *)(lVar18 + 0x638);
  lVar18 = param_1[2];
  if ((*(int *)((long)param_1 + 0x74) == 0) || ((int)param_1[0xe] != *(int *)((long)param_1 + 0x74))
     ) {
    lVar19 = param_1[0x1c];
  }
  else {
    lVar19 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
    lVar19 = ((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
             (ulong)*(uint *)(lVar19 + 0x54);
  }
  bVar7 = *(byte *)(lVar19 + 4) >> 1;
  if (bVar7 == 2) {
    if ((*(byte *)(param_1[2] + 0xed) & 1) == 0) {
      *(long *)(lVar18 + 0xaa0) = *(long *)(lVar18 + 0xaa0) + 1;
    }
    else {
      if ((*(int *)((long)param_1 + 0x74) == 0) ||
         ((int)param_1[0xe] != *(int *)((long)param_1 + 0x74))) {
        sVar10 = *(short *)(param_1[0x1c] + 4);
      }
      else {
        lVar19 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
        sVar10 = *(short *)(((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000
                            ) + (ulong)*(uint *)(lVar19 + 0x54) + 4);
      }
      if (sVar10 < 0) {
        *(long *)(lVar18 + 0xa60) = *(long *)(lVar18 + 0xa60) + 1;
        *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xffbf | 0x20;
      }
      else {
        *(long *)(lVar18 + 0xa68) = *(long *)(lVar18 + 0xa68) + 1;
      }
    }
    uVar15 = *(uint *)(param_1 + 0xe);
    uVar14 = uVar15 - *(int *)((long)param_1 + 0x74);
    if (uVar14 < 8) {
      if ((7 < uVar15) && (lVar18 = __pskb_pull_tail(param_1,8 - uVar14), lVar18 != 0)) {
        uVar15 = *(uint *)(param_1 + 0xe);
        goto LAB_0011107c;
      }
    }
    else {
LAB_0011107c:
      *(uint *)(param_1 + 0xe) = uVar15 - 8;
      param_1[0x1c] = param_1[0x1c] + 8;
    }
    rmnet_map_move_headers(param_1);
    param_3 = param_3 & 0xffff;
    if (param_3 < *(uint *)(param_1 + 0xe)) {
      if (*(int *)((long)param_1 + 0x74) == 0) {
        *(uint *)(param_1 + 0xe) = param_3;
        *(uint *)(param_1 + 0x1a) = ((int)param_1[0x1c] - (int)param_1[0x1b]) + param_3;
      }
      else {
        ___pskb_trim(param_1);
      }
    }
    plVar20 = (long *)param_2[1];
    *param_1 = (long)param_2;
    uVar16 = 0;
    param_1[1] = (long)plVar20;
    param_2[1] = (long)param_1;
    *plVar20 = (long)param_1;
    *(int *)(param_2 + 2) = (int)param_2[2] + 1;
    goto LAB_001111e0;
  }
  if (bVar7 != 1) {
    uVar16 = 0xffffffea;
    goto LAB_001111e0;
  }
  *(long *)(lVar18 + 0xab0) = *(long *)(lVar18 + 0xab0) + 1;
  if ((*(int *)((long)param_1 + 0x74) == 0) || ((int)param_1[0xe] != *(int *)((long)param_1 + 0x74))
     ) {
    lVar18 = param_1[0x1c];
  }
  else {
    lVar18 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
    lVar18 = ((*(ulong *)(lVar18 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
             (ulong)*(uint *)(lVar18 + 0x54);
  }
  uVar15 = *(uint *)(lVar18 + 4);
  lVar19 = param_1[2];
  uVar14 = uVar15 >> 0xc & 7;
  if ((uVar14 == 0) || (uVar14 == 7)) {
    uVar16 = 0xffffffea;
    *(long *)(lVar19 + 0xac0) = *(long *)(lVar19 + 0xac0) + 1;
    goto LAB_001111e0;
  }
  if (((((0x30 < *(byte *)(lVar18 + 0xb)) ||
        (bVar7 = *(char *)(lVar18 + 0xf) + *(byte *)(lVar18 + 0xb), 0x30 < bVar7)) ||
       (bVar7 = *(char *)(lVar18 + 0x13) + bVar7, 0x30 < bVar7)) ||
      ((bVar7 = *(char *)(lVar18 + 0x17) + bVar7, 0x30 < bVar7 ||
       (bVar7 = *(char *)(lVar18 + 0x1b) + bVar7, 0x30 < bVar7)))) ||
     (bVar7 = *(char *)(lVar18 + 0x1f) + bVar7, 0x30 < bVar7)) {
    uVar16 = 0xffffffea;
    *(long *)(lVar19 + 0xac8) = *(long *)(lVar19 + 0xac8) + 1;
    goto LAB_001111e0;
  }
  bVar1 = *(byte *)(lVar18 + 0x1a);
  bVar2 = *(byte *)(lVar18 + 0x16);
  bVar3 = *(byte *)(lVar18 + 0x12);
  bVar4 = *(byte *)(lVar18 + 0xe);
  bVar5 = *(byte *)(lVar18 + 10);
  bVar6 = *(byte *)(lVar18 + 0x1e);
  *(ulong *)(lVar19 + 0xab8) = *(long *)(lVar19 + 0xab8) + (ulong)bVar7;
  lVar23 = 0xaf0;
  switch(*(uint *)(lVar18 + 4) >> 0x10 & 0xf) {
  case 0:
    break;
  case 1:
    lVar23 = 0xaf8;
    break;
  case 2:
    lVar23 = 0xb00;
    break;
  case 3:
    uVar14 = *(uint *)(lVar18 + 4) >> 0x14 & 0xf;
    if (uVar14 < 5) {
      lVar23 = (ulong)(uVar14 << 3) + 0xb08;
      break;
    }
    goto switchD_00111184_default;
  case 4:
    lVar23 = 0xb30;
    break;
  default:
    goto switchD_00111184_default;
  }
  *(long *)(lVar19 + lVar23) = *(long *)(lVar19 + lVar23) + 1;
switchD_00111184_default:
  lVar18 = lVar19 + 0xa40 + (ulong)(uVar15 >> 0x1c) * 8;
  local_88 = (byte *)0x0;
  local_80 = (byte *)0x0;
  local_78 = 0;
  local_70 = 0;
  *(long *)(lVar18 + 0xf8) = *(long *)(lVar18 + 0xf8) + 1;
  uVar15 = *(uint *)(param_1 + 0xe);
  iVar17 = *(int *)((long)param_1 + 0x74);
  lVar18 = param_1[2];
  uVar16 = *(undefined8 *)(lVar18 + 0xe8);
  if (uVar15 - iVar17 < 4) {
    if (3 < uVar15) {
      lVar19 = __pskb_pull_tail(param_1,4 - (uVar15 - iVar17));
      if (lVar19 != 0) {
        uVar15 = *(uint *)(param_1 + 0xe);
        goto LAB_00111278;
      }
      goto LAB_0011128c;
    }
    if (iVar17 != 0) goto LAB_00111294;
LAB_00111378:
    puVar24 = (uint *)param_1[0x1c];
  }
  else {
LAB_00111278:
    *(uint *)(param_1 + 0xe) = uVar15 - 4;
    param_1[0x1c] = param_1[0x1c] + 4;
LAB_0011128c:
    iVar17 = *(int *)((long)param_1 + 0x74);
    if (iVar17 == 0) goto LAB_00111378;
LAB_00111294:
    if ((int)param_1[0xe] != iVar17) goto LAB_00111378;
    lVar19 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
    puVar24 = (uint *)(((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                      (ulong)*(uint *)(lVar19 + 0x54));
    iVar17 = *(int *)((long)param_1 + 0x74);
  }
  uVar15 = *(uint *)(param_1 + 0xe);
  if (uVar15 - iVar17 < 0x1c) {
    if (0x1b < uVar15) {
      lVar19 = __pskb_pull_tail(param_1,0x1c - (uVar15 - iVar17));
      if (lVar19 != 0) {
        uVar15 = *(uint *)(param_1 + 0xe);
        goto LAB_0011138c;
      }
      goto LAB_001113a0;
    }
  }
  else {
LAB_0011138c:
    *(uint *)(param_1 + 0xe) = uVar15 - 0x1c;
    param_1[0x1c] = param_1[0x1c] + 0x1c;
LAB_001113a0:
    iVar17 = *(int *)((long)param_1 + 0x74);
  }
  if ((iVar17 == 0) || ((int)param_1[0xe] != iVar17)) {
    pbVar27 = (byte *)param_1[0x1c];
  }
  else {
    lVar19 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
    pbVar27 = (byte *)(((*(ulong *)(lVar19 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                      (ulong)*(uint *)(lVar19 + 0x54));
  }
  bVar7 = *pbVar27;
  bVar9 = bVar7 >> 4;
  uVar15 = (uint)((ulong)uVar16 >> 0x20);
  if (bVar9 == 6) {
    local_90[0] = pbVar27[6];
    local_8c[0] = 0;
    local_70 = CONCAT71(local_70._1_7_,6);
    uVar12 = ipv6_skip_exthdr(param_1,0x28,local_90,local_8c);
    local_78 = CONCAT62(local_78._2_6_,uVar12);
    local_70._0_2_ = CONCAT11(local_90[0],(undefined1)local_70);
    local_88 = pbVar27;
    if (local_8c[0] != 0) goto LAB_00111488;
    uVar14 = 0;
    if (uVar12 < 0x29) {
      uVar14 = uVar15 >> 0x17 & 1;
    }
    bVar7 = local_90[0];
LAB_001114bc:
    if (bVar7 == 0x11) {
      uVar26 = 8;
      local_80 = pbVar27 + uVar12;
      local_78._0_4_ = CONCAT22(8,(short)local_78);
      if (bVar9 == 4) {
        bVar11 = *(short *)(local_80 + 6) == 0;
      }
      else {
        bVar11 = false;
      }
    }
    else {
      if (bVar7 != 6) {
        *(long *)(lVar18 + 0xae8) = *(long *)(lVar18 + 0xae8) + 1;
        local_88 = pbVar27;
        goto LAB_001117fc;
      }
      local_80 = pbVar27 + uVar12;
      bVar11 = false;
      uVar26 = *(ushort *)(local_80 + 0xc) >> 2 & 0x3c;
      local_78 = CONCAT44(local_78._4_4_,CONCAT22(*(ushort *)(local_80 + 0xc) >> 2,(short)local_78))
                 & 0xffffffff003cffff;
    }
    uVar15 = *puVar24;
    if (((uVar15 & 0x7000) == 0x1000) && (*(char *)((long)puVar24 + 7) == '\x01')) {
      uVar8 = uVar15 >> 0x10 & 0xf;
      if (uVar8 != 4) {
        if (uVar8 != 3) goto LAB_00111574;
        if ((uVar15 >> 0x14 & 0xf) - 4 < 0xfffffffd) {
          bVar11 = true;
        }
      }
      if (bVar11) goto LAB_00111574;
      local_88 = pbVar27;
      rmnet_map_move_headers(param_1);
      if ((*(int *)((long)param_1 + 0x74) == 0) ||
         ((int)param_1[0xe] != *(int *)((long)param_1 + 0x74))) {
        lVar18 = param_1[0x1c];
      }
      else {
        lVar18 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
        lVar18 = ((*(ulong *)(lVar18 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                 (ulong)*(uint *)(lVar18 + 0x54);
      }
      iVar17 = (int)param_1[0xe] - (uint)uVar12;
      if (bVar9 == 4) {
        uVar15 = csum_tcpudp_nofold(*(undefined4 *)(lVar18 + 0xc),*(undefined4 *)(lVar18 + 0x10),
                                    iVar17,bVar7,0);
        uVar15 = (uVar15 >> 0x10 | uVar15 << 0x10) + uVar15 >> 0x10;
      }
      else {
        uVar15 = csum_ipv6_magic(lVar18 + 8,lVar18 + 0x18,iVar17,bVar7,0);
        uVar15 = ~uVar15;
      }
      uVar15 = skb_checksum(param_1,(uint)uVar12,iVar17,uVar15 & 0xffff);
      if (0xfffeffff < (uVar15 >> 0x10 | uVar15 << 0x10) + uVar15) {
        *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xffbf | 0x20;
      }
    }
    else {
LAB_00111574:
      uVar8 = 0;
      if ((uVar15 & 0xf000) == 0x9000) {
        uVar8 = uVar14;
      }
      if (uVar8 == 0) {
        local_88 = pbVar27;
        if ((uVar15 & 0x7000) != 0) {
          lVar19 = 0;
          iVar17 = 0;
          uVar25 = (ulong)bVar1 << 0x20 | (ulong)bVar2 << 0x18 | (ulong)bVar3 << 0x10 | (ulong)bVar5
                   | (ulong)bVar4 << 8 | (ulong)bVar6 << 0x28;
          do {
            pbVar27 = (byte *)((long)puVar24 + lVar19 * 4 + 7);
            sVar10 = (short)local_78 + local_78._2_2_;
            local_78 = CONCAT26(((ushort)puVar24[lVar19 + 1] >> 8 | (ushort)puVar24[lVar19 + 1] << 8
                                ) - sVar10,(undefined6)local_78);
            if (*pbVar27 != 0) {
              uVar15 = 0;
              do {
                if (uVar14 == 0) {
                  local_70._0_4_ = CONCAT13(1,(undefined3)local_70);
                  if ((uVar25 & 1) != 0) {
                    *(long *)(lVar18 + 0xad0) = *(long *)(lVar18 + 0xad0) + 1;
                  }
                  bVar11 = (uVar25 & 1) == 0;
LAB_0011168c:
                  __rmnet_map_segment_coal_skb(param_1,&local_88,param_2,iVar17,bVar11);
                }
                else {
                  if ((uVar25 & 1) != 0) {
                    *(long *)(lVar18 + 0xad0) = *(long *)(lVar18 + 0xad0) + 1;
                    if (local_70._3_1_ != '\0') {
                      __rmnet_map_segment_coal_skb(param_1,&local_88,param_2,iVar17,1);
                    }
                    bVar11 = false;
                    local_70._0_4_ = CONCAT13(1,(undefined3)local_70);
                    goto LAB_0011168c;
                  }
                  local_70._0_4_ = CONCAT13(local_70._3_1_ + '\x01',(undefined3)local_70);
                }
                uVar15 = uVar15 + 1;
                iVar17 = iVar17 + 1;
                uVar25 = uVar25 >> 1;
              } while (uVar15 < *pbVar27);
            }
            if (local_70._3_1_ != '\0') {
              __rmnet_map_segment_coal_skb(param_1,&local_88,param_2,iVar17,1);
            }
            lVar19 = lVar19 + 1;
          } while ((uint)lVar19 < (*puVar24 >> 0xc & 7));
        }
        goto LAB_001117fc;
      }
      local_88 = pbVar27;
      rmnet_map_move_headers(param_1);
      *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xffbf | 0x20;
      bVar1 = *(byte *)((long)puVar24 + 7);
      if (1 < bVar1) {
        uVar15 = puVar24[1];
        lVar18 = param_1[0x1c];
        sVar10 = (short)param_1[0xe] - uVar12;
        if (bVar9 == 4) {
          uVar14 = csum_tcpudp_nofold(*(undefined4 *)(lVar18 + 0xc),*(undefined4 *)(lVar18 + 0x10),
                                      sVar10,bVar7,0);
          uVar13 = (ushort)((uVar14 >> 0x10 | uVar14 << 0x10) + uVar14 >> 0x10);
        }
        else {
          uVar13 = csum_ipv6_magic(lVar18 + 8,lVar18 + 0x18,sVar10,bVar7,0);
          uVar13 = ~uVar13;
        }
        if (bVar7 == 6) {
          uVar21 = 0x10;
          *(ushort *)(lVar18 + (ulong)uVar12 + 0x10) = uVar13;
        }
        else {
          uVar21 = 6;
          *(ushort *)(lVar18 + (ulong)uVar12 + 6) = uVar13;
        }
        *(undefined2 *)((long)param_1 + 0x8a) = uVar21;
        uVar22 = 0x10;
        if (bVar9 == 4) {
          uVar22 = 1;
        }
        if (bVar7 != 6) {
          uVar22 = 0x20000;
        }
        lVar18 = param_1[0x1b] + (ulong)*(uint *)((long)param_1 + 0xd4);
        *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) | 0x60;
        *(ushort *)(param_1 + 0x11) = ((short)param_1[0x1c] + uVar12) - (short)param_1[0x1b];
        *(undefined4 *)(lVar18 + 0x18) = uVar22;
        *(ushort *)(lVar18 + 4) = (((ushort)uVar15 >> 8 | (ushort)uVar15 << 8) - uVar26) - uVar12;
        *(ushort *)(lVar18 + 6) = (ushort)bVar1;
      }
    }
    plVar20 = (long *)param_2[1];
    *param_1 = (long)param_2;
    param_1[1] = (long)plVar20;
    param_2[1] = (long)param_1;
    *plVar20 = (long)param_1;
    *(int *)(param_2 + 2) = (int)param_2[2] + 1;
  }
  else {
    if (bVar9 == 4) {
      uVar12 = (bVar7 & 0xf) << 2;
      uVar14 = 0;
      if ((bVar7 & 0xf) == 5) {
        uVar14 = uVar15 >> 0x17 & 1;
      }
      local_78 = CONCAT62(local_78._2_6_,uVar12);
      local_70._0_2_ = CONCAT11(pbVar27[9],4);
      bVar7 = pbVar27[9];
      goto LAB_001114bc;
    }
LAB_00111488:
    *(long *)(lVar18 + 0xae0) = *(long *)(lVar18 + 0xae0) + 1;
  }
LAB_001117fc:
  plVar20 = (long *)0x0;
  if ((long *)*param_2 != param_2) {
    plVar20 = (long *)*param_2;
  }
  if (plVar20 != param_1) {
    consume_skb(param_1);
  }
  uVar16 = 0;
LAB_001111e0:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar16);
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_move_headers @ 0011195c size=356
// signature: undefined rmnet_map_move_headers(void)
// callers: [rmnet_map_process_next_hdr_packet]
//------------------------------------------------------------

void rmnet_map_move_headers(long param_1)

{
  long lVar1;
  short sVar2;
  ushort uVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  byte local_40 [4];
  undefined2 local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (*(int *)(param_1 + 0x74) == 0) goto LAB_00111a98;
  if (*(int *)(param_1 + 0x70) == *(int *)(param_1 + 0x74)) {
    lVar1 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    pbVar6 = (byte *)(((*(ulong *)(lVar1 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                     (ulong)*(uint *)(lVar1 + 0x54));
  }
  else {
    pbVar6 = *(byte **)(param_1 + 0xe0);
  }
  bVar4 = *pbVar6 >> 4;
  if (bVar4 == 6) {
    local_40[0] = pbVar6[6];
    local_3c[0] = 0;
    uVar3 = ipv6_skip_exthdr(param_1,0x28,local_40,local_3c);
    bVar4 = local_40[0];
    if (local_40[0] == 0x2c) {
LAB_00111a08:
      uVar5 = 0;
      uVar3 = uVar3 + 8;
    }
    else {
LAB_00111a44:
      if (bVar4 == 0x11) {
        uVar5 = 8;
      }
      else {
        if (bVar4 != 6) goto LAB_00111a68;
        uVar5 = *(ushort *)(pbVar6 + (ulong)uVar3 + 0xc) >> 2 & 0x3c;
      }
    }
  }
  else {
    if (bVar4 != 4) goto LAB_00111a98;
    uVar3 = (*pbVar6 & 0xf) << 2;
    if ((*(ushort *)(pbVar6 + 6) & 0xff1f) == 0) {
      bVar4 = pbVar6[9];
      if (pbVar6[9] != 0x2c) goto LAB_00111a44;
      goto LAB_00111a08;
    }
LAB_00111a68:
    uVar5 = 0;
  }
  __pskb_pull_tail(param_1,uVar5 + uVar3);
  sVar2 = (short)*(undefined8 *)(param_1 + 0xe0) - (short)*(undefined8 *)(param_1 + 0xd8);
  *(short *)(param_1 + 0xb8) = sVar2;
  if (uVar5 != 0) {
    *(ushort *)(param_1 + 0xb6) = uVar3 + sVar2;
  }
LAB_00111a98:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_tx_agg_skip @ 00111acc size=100
// signature: undefined rmnet_map_tx_agg_skip(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

bool rmnet_map_tx_agg_skip(long param_1,int param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xe0) + (long)param_2;
  if (*(short *)(param_1 + 0xb4) == -0x227a) {
    if (*(char *)(lVar1 + 6) == ':') {
      return true;
    }
    if (*(char *)(lVar1 + 6) == ',') {
      return *(char *)(lVar1 + 0x28) == ':';
    }
  }
  else if (*(short *)(param_1 + 0xb4) == 8) {
    return *(char *)(lVar1 + 9) == '\x01';
  }
  return false;
}



//------------------------------------------------------------
// rmnet_map_flush_tx_packet_queue @ 00111b34 size=48
// signature: undefined rmnet_map_flush_tx_packet_queue(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_map_flush_tx_packet_queue(long param_1)

{
  queue_work_on(0x20,_system_wq,param_1 + 0x48);
  return 0;
}



//------------------------------------------------------------
// rmnet_map_send_agg_skb @ 00111b68 size=120
// signature: undefined rmnet_map_send_agg_skb(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

void rmnet_map_send_agg_skb(long param_1)

{
  code *pcVar1;
  
  if (*(long *)(param_1 + 0xa8) == 0) {
    _raw_spin_unlock_bh(param_1 + 0xa0);
  }
  else {
    *(undefined8 *)(param_1 + 0xa8) = 0;
    *(undefined1 *)(param_1 + 0xbc) = 0;
    *(undefined8 *)(param_1 + 8) = 0;
    *(undefined8 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0xb8) = 0;
    if (*(int *)(*(code **)(param_1 + 0xb0) + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x111bb0);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0xb0))();
    _raw_spin_unlock_bh(param_1 + 0xa0);
    hrtimer_cancel(param_1 + 0x28);
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_tx_aggregate @ 00111be4 size=1352
// signature: undefined rmnet_map_tx_aggregate(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

void rmnet_map_tx_aggregate(long param_1,long param_2,ulong param_3)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  byte *pbVar5;
  undefined8 *puVar6;
  long lVar7;
  long *plVar8;
  int *piVar9;
  long lVar10;
  int iVar11;
  char cVar12;
  bool bVar13;
  code *pcVar14;
  long lVar15;
  uint uVar16;
  long lVar17;
  long *plVar18;
  long *plVar19;
  ulong uVar20;
  undefined4 local_7c;
  ulong local_78;
  long local_70;
  long local_68;
  
  param_3 = param_3 & 1;
  lVar17 = param_2 + param_3 * 0xe0;
  lVar2 = sp_el0;
  piVar1 = (int *)(lVar17 + 0x8d0);
  local_68 = *(long *)(lVar2 + 0x638);
  lVar2 = lVar17 + 0x8b8;
  plVar18 = (long *)(lVar17 + 0x830);
  plVar3 = (long *)(lVar17 + 0x8c0);
  plVar4 = (long *)(lVar17 + 0x820);
  pbVar5 = (byte *)(lVar17 + 0x8d4);
  puVar6 = (undefined8 *)(lVar17 + 0x8c8);
  lVar7 = lVar17 + 0x840;
  while( true ) {
    _raw_spin_lock_bh(lVar2);
    lVar15 = *plVar18;
    lVar10 = *(long *)(lVar17 + 0x838);
    ktime_get_real_ts64(plVar18);
    if (((*(byte *)(param_2 + 0xb) >> 4 & 1) != 0) &&
       ((*(uint *)(param_1 + 0x8c) == 0xda001a ||
        ((*(uint *)(param_1 + 0x8c) & 0xffff0200) == 0x9b6d0200)))) {
      if (*plVar3 == 0) {
        _raw_spin_unlock_bh(lVar2);
      }
      else {
        *plVar3 = 0;
        *pbVar5 = 0;
        *plVar4 = 0;
        *(undefined8 *)(lVar17 + 0x828) = 0;
        *piVar1 = 0;
        if (*(int *)((code *)*puVar6 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
          pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x111e0c);
          (*pcVar14)();
        }
        (*(code *)*puVar6)();
        _raw_spin_unlock_bh(lVar2);
        hrtimer_cancel(lVar7);
      }
      *(undefined2 *)(param_1 + 0xb4) = 0xf900;
      if (*(int *)((code *)*puVar6 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x11207c);
        (*pcVar14)();
      }
      (*(code *)*puVar6)(param_1);
      goto LAB_00112080;
    }
    if (*plVar3 == 0) break;
    local_78 = 0;
    local_70 = 0;
    set_normalized_timespec64
              (&local_78,*plVar18 - *plVar4,*(long *)(lVar17 + 0x838) - *(long *)(lVar17 + 0x828));
    lVar15 = *plVar3;
    if (*(int *)(lVar15 + 0x74) == 0) {
      uVar16 = *(int *)(lVar15 + 0xd4) - *(int *)(lVar15 + 0xd0);
    }
    else {
      uVar16 = 0;
    }
    if (((*(uint *)(param_1 + 0x70) <= uVar16) && (*pbVar5 < *(byte *)(lVar17 + 0x81a))) &&
       (((long)local_78 < 1 && (local_70 <= rmnet_agg_time_limit)))) {
      rmnet_map_linearize_copy(lVar15,param_1);
      *pbVar5 = *pbVar5 + 1;
      goto LAB_00111e38;
    }
    if (lVar15 == 0) {
      _raw_spin_unlock_bh(lVar2);
    }
    else {
      *plVar3 = 0;
      *pbVar5 = 0;
      *plVar4 = 0;
      *(undefined8 *)(lVar17 + 0x828) = 0;
      *piVar1 = 0;
      if (*(int *)((code *)*puVar6 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x111c9c);
        (*pcVar14)();
      }
      (*(code *)*puVar6)();
      _raw_spin_unlock_bh(lVar2);
      hrtimer_cancel(lVar7);
    }
  }
  local_78 = 0;
  local_70 = 0;
  set_normalized_timespec64(&local_78,*plVar18 - lVar15,*(long *)(lVar17 + 0x838) - lVar10);
  if (((0 < (long)local_78) || (rmnet_agg_bypass_time < local_70)) ||
     ((int)((uint)*(ushort *)(lVar17 + 0x818) - *(int *)(param_1 + 0x70)) < 1)) goto LAB_00111da4;
  local_7c = 2;
  local_78 = local_78 & 0xffffffff00000000;
  if ((*(byte *)(lVar17 + 0x81b) & 1) == 0) goto LAB_00111fa0;
  lVar15 = param_2 + param_3 * 0xe0;
  plVar18 = *(long **)(lVar15 + 0x8e8);
  if (plVar18 == (long *)0x0) goto LAB_00111fa0;
  uVar20 = plVar18[2];
  plVar8 = (long *)(lVar15 + 0x8e8);
  if (*(int *)(uVar20 + 0x34) == 1) {
LAB_00111f6c:
    piVar9 = (int *)(uVar20 + 0x34);
    Hint_Prefetch(piVar9,2,0,1);
    do {
      cVar12 = '\x01';
      bVar13 = (bool)ExclusiveMonitorPass(piVar9,0x10);
      if (bVar13) {
        *piVar9 = *piVar9 + 1;
        cVar12 = ExclusiveMonitorsStatus();
      }
    } while (cVar12 != '\0');
    plVar19 = *(long **)(param_2 + param_3 * 0xe0 + 0x8f0);
    *plVar19 = *plVar19 + 1;
    *plVar8 = *plVar18;
    if (uVar20 != 0) {
LAB_00111fd8:
      lVar15 = build_skb((uVar20 & 0x3ffffffffffc0) << 6 | 0xff00000000000000,
                         0x1000L << ((ulong)*(byte *)(param_2 + param_3 * 0xe0 + 0x8d5) & 0x3f));
      if (lVar15 == 0) {
        if ((*(ulong *)(uVar20 + 8) & 1) != 0) {
          uVar20 = *(ulong *)(uVar20 + 8) - 1;
        }
        piVar1 = (int *)(uVar20 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar11 = *piVar1;
          cVar12 = '\x01';
          bVar13 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar13) {
            *piVar1 = iVar11 + -1;
            cVar12 = ExclusiveMonitorsStatus();
          }
        } while (cVar12 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar11 + -1 == 0) {
          __folio_put(uVar20);
        }
        goto LAB_001120e4;
      }
      *plVar3 = lVar15;
      rmnet_map_linearize_copy(lVar15,param_1);
      *(undefined8 *)(*plVar3 + 0x10) = *(undefined8 *)(param_1 + 0x10);
      *(undefined2 *)(*plVar3 + 0xb4) = 0xf900;
      *pbVar5 = 1;
      ktime_get_real_ts64(plVar4);
LAB_00111e38:
      __dev_kfree_skb_any(param_1,0);
      if (*piVar1 != -0x73) {
        *piVar1 = -0x73;
        hrtimer_start_range_ns(lVar7,*(undefined4 *)(lVar17 + 0x81c),0,1);
      }
      goto LAB_00111e70;
    }
  }
  else {
    plVar18 = (long *)*plVar18;
    *plVar8 = (long)plVar18;
    if (plVar18 != (long *)0x0) {
      uVar20 = plVar18[2];
      if (*(int *)(uVar20 + 0x34) == 1) goto LAB_00111f6c;
      plVar18 = (long *)*plVar18;
      *plVar8 = (long)plVar18;
      if (plVar18 != (long *)0x0) {
        uVar20 = plVar18[2];
        if (*(int *)(uVar20 + 0x34) == 1) goto LAB_00111f6c;
        plVar18 = (long *)*plVar18;
        *plVar8 = (long)plVar18;
        if (plVar18 != (long *)0x0) {
          uVar20 = plVar18[2];
          if (*(int *)(uVar20 + 0x34) == 1) goto LAB_00111f6c;
          plVar18 = (long *)*plVar18;
          *plVar8 = (long)plVar18;
          if (plVar18 != (long *)0x0) {
            uVar20 = plVar18[2];
            if (*(int *)(uVar20 + 0x34) == 1) goto LAB_00111f6c;
            plVar18 = (long *)*plVar18;
            *plVar8 = (long)plVar18;
            if (plVar18 != (long *)0x0) {
              uVar20 = plVar18[2];
              if (*(int *)(uVar20 + 0x34) == 1) goto LAB_00111f6c;
              *plVar8 = *plVar18;
            }
          }
        }
      }
    }
  }
LAB_00111fa0:
  lVar15 = param_2 + param_3 * 0xe0;
  uVar20 = rmnet_mem_get_pages_entry(0xa20,*(undefined1 *)(lVar15 + 0x8d5),&local_78,&local_7c,2);
  lVar15 = *(long *)(lVar15 + 0x8f0);
  *(long *)(lVar15 + 8) = *(long *)(lVar15 + 8) + 1;
  if (uVar20 != 0) goto LAB_00111fd8;
LAB_001120e4:
  *plVar3 = 0;
  *pbVar5 = 0;
  *plVar4 = 0;
  *(undefined8 *)(lVar17 + 0x828) = 0;
LAB_00111da4:
  *(undefined2 *)(param_1 + 0xb4) = 0xf900;
  if (*(int *)((code *)*puVar6 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
    pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x111dcc);
    (*pcVar14)();
  }
  (*(code *)*puVar6)(param_1);
LAB_00111e70:
  _raw_spin_unlock_bh(lVar2);
LAB_00112080:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_linearize_copy @ 00112160 size=268
// signature: undefined rmnet_map_linearize_copy(void)
// callers: [rmnet_map_tx_aggregate]
//------------------------------------------------------------

void rmnet_map_linearize_copy(undefined8 param_1,long *param_2)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  void *pvVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  void *__src;
  int iVar8;
  long lVar9;
  
  iVar8 = *(int *)((long)param_2 + 0x74);
  __src = (void *)param_2[0x1c];
  uVar7 = (ulong)(uint)((int)param_2[0xe] - iVar8);
  pvVar4 = (void *)skb_put(param_1,uVar7);
  memcpy(pvVar4,__src,uVar7);
  while (plVar3 = param_2, iVar8 != 0) {
    lVar5 = plVar3[0x1b] + (ulong)*(uint *)((long)plVar3 + 0xd4);
    if (*(char *)(lVar5 + 2) != '\0') {
      lVar9 = 0;
      uVar7 = 0;
      do {
        lVar5 = lVar5 + lVar9;
        uVar1 = *(uint *)(lVar5 + 0x50);
        uVar6 = *(ulong *)(lVar5 + 0x48);
        uVar2 = *(uint *)(lVar5 + 0x54);
        pvVar4 = (void *)skb_put(param_1,(ulong)uVar1);
        memcpy(pvVar4,(void *)(((uVar6 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) + (ulong)uVar2)
               ,(ulong)uVar1);
        iVar8 = iVar8 - uVar1;
        uVar7 = uVar7 + 1;
        lVar9 = lVar9 + 0x10;
        lVar5 = plVar3[0x1b] + (ulong)*(uint *)((long)plVar3 + 0xd4);
      } while (uVar7 < *(byte *)(lVar5 + 2));
    }
    param_2 = *(long **)(lVar5 + 8);
    if ((*(long **)(lVar5 + 8) == (long *)0x0) && (param_2 = plVar3, (long *)*plVar3 != (long *)0x0)
       ) {
      param_2 = (long *)*plVar3;
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_update_ul_agg_config @ 00112278 size=488
// signature: undefined rmnet_map_update_ul_agg_config(void)
// callers: [rmnet_newlink, rmnet_changelink, rmnet_map_tx_aggregate_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_map_update_ul_agg_config
               (ushort *param_1,ushort param_2,undefined1 param_3,undefined1 param_4,
               undefined4 param_5)

{
  uint uVar1;
  ushort *puVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 *puVar5;
  long lVar6;
  ushort *puVar7;
  undefined8 *puVar8;
  int iVar9;
  ushort *puVar10;
  undefined4 local_60;
  undefined4 uStack_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  _raw_spin_lock_bh(param_1 + 0x50);
  *(undefined1 *)(param_1 + 1) = param_3;
  *(undefined4 *)(param_1 + 2) = param_5;
  *param_1 = param_2;
  puVar7 = param_1 + 0x60;
  *(undefined1 *)((long)param_1 + 3) = param_4;
  puVar2 = *(ushort **)puVar7;
  while (puVar2 != puVar7) {
    puVar10 = *(ushort **)puVar2;
    uVar4 = __list_del_entry_valid(puVar2);
    if ((uVar4 & 1) != 0) {
      lVar6 = *(long *)puVar2;
      plVar3 = *(long **)(puVar2 + 4);
      *(long **)(lVar6 + 8) = plVar3;
      *plVar3 = lVar6;
    }
    puVar2[0] = 0x100;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0xdead;
    puVar2[4] = 0x122;
    puVar2[5] = 0;
    puVar2[6] = 0;
    puVar2[7] = 0xdead;
    rmnet_mem_put_page_entry(*(long *)(puVar2 + 8));
    kfree(puVar2);
    puVar2 = puVar10;
  }
  param_1[0x68] = 0;
  param_1[0x69] = 0;
  param_1[0x6a] = 0;
  param_1[0x6b] = 0;
  if (0xfff < param_2) {
    uVar1 = 0;
    if (param_2 != 0x1000) {
      uVar1 = 0x40 - (int)LZCOUNT((ulong)param_2 - 1 >> 0xc);
    }
    *(char *)((long)param_1 + 0xbd) = (char)uVar1;
    *param_1 = (short)(0x1000L << ((ulong)uVar1 & 0x3f)) - 0x180;
    if (*(char *)((long)param_1 + 3) == '\x01') {
      iVar9 = 0x180;
      do {
        local_60 = 2;
        uStack_5c = 0;
        puVar5 = (undefined8 *)kmalloc_trace(___stack_chk_fail,0xb20,0x18);
        if (puVar5 != (undefined8 *)0x0) {
          lVar6 = rmnet_mem_get_pages_entry
                            (0xa20,*(undefined1 *)((long)param_1 + 0xbd),&uStack_5c,&local_60,2);
          if (lVar6 == 0) {
            kfree(puVar5);
          }
          else {
            puVar5[2] = lVar6;
            *puVar5 = puVar5;
            puVar5[1] = puVar5;
            puVar8 = *(undefined8 **)(param_1 + 100);
            uVar4 = __list_add_valid(puVar5,puVar8,puVar7);
            if ((uVar4 & 1) != 0) {
              *(undefined8 **)(param_1 + 100) = puVar5;
              *puVar5 = puVar7;
              puVar5[1] = puVar8;
              *puVar8 = puVar5;
            }
          }
        }
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      puVar2 = (ushort *)0x0;
      if (*(ushort **)(param_1 + 0x60) != puVar7) {
        puVar2 = *(ushort **)(param_1 + 0x60);
      }
      *(ushort **)(param_1 + 0x68) = puVar2;
    }
  }
  _raw_spin_unlock_bh(param_1 + 0x50);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_tx_aggregate_init @ 00112464 size=284
// signature: undefined rmnet_map_tx_aggregate_init(void)
// callers: [rmnet_register_real_device]
//------------------------------------------------------------

void rmnet_map_tx_aggregate_init(long param_1)

{
  *(undefined4 *)(param_1 + 0x8b8) = 0;
  *(long *)(param_1 + 0x8d8) = param_1 + 0x8d8;
  *(long *)(param_1 + 0x8e0) = param_1 + 0x8d8;
  hrtimer_init(param_1 + 0x840,1,1);
  *(code **)(param_1 + 0x868) = rmnet_map_flush_tx_packet_queue;
  *(undefined8 *)(param_1 + 0x888) = 0xfffffffe0;
  *(long *)(param_1 + 0x890) = param_1 + 0x890;
  *(long *)(param_1 + 0x898) = param_1 + 0x890;
  *(code **)(param_1 + 0x8a0) = rmnet_map_flush_tx_packet_work;
  *(long *)(param_1 + 0x8f0) = param_1 + 0xa50;
  rmnet_map_update_ul_agg_config(param_1 + 0x818,0xfff,0x14,0,3000000);
  *(undefined4 *)(param_1 + 0x998) = 0;
  *(long *)(param_1 + 0x9b8) = param_1 + 0x9b8;
  *(long *)(param_1 + 0x9c0) = param_1 + 0x9b8;
  hrtimer_init(param_1 + 0x920,1,1);
  *(code **)(param_1 + 0x948) = rmnet_map_flush_tx_packet_queue;
  *(undefined8 *)(param_1 + 0x968) = 0xfffffffe0;
  *(long *)(param_1 + 0x970) = param_1 + 0x970;
  *(long *)(param_1 + 0x978) = param_1 + 0x970;
  *(code **)(param_1 + 0x980) = rmnet_map_flush_tx_packet_work;
  *(long *)(param_1 + 0x9d0) = param_1 + 0xa50;
  rmnet_map_update_ul_agg_config(param_1 + 0x8f8,0xfff,0x14,0,3000000);
  *(code **)(param_1 + 0x8c8) = dev_queue_xmit;
  *(code **)(param_1 + 0x9a8) = rmnet_ll_send_skb;
  return;
}



//------------------------------------------------------------
// rmnet_map_flush_tx_packet_work @ 00112584 size=132
// signature: undefined rmnet_map_flush_tx_packet_work(void)
// callers: []
//------------------------------------------------------------

void rmnet_map_flush_tx_packet_work(long param_1)

{
  code *pcVar1;
  
  _raw_spin_lock_bh(param_1 + 0x30);
  if (*(int *)(param_1 + 0x48) == -0x73) {
    if (*(long *)(param_1 + 0x38) == 0) {
      *(undefined4 *)(param_1 + 0x48) = 0;
    }
    else {
      *(undefined8 *)(param_1 + 0x38) = 0;
      *(undefined1 *)(param_1 + 0x4c) = 0;
      *(undefined8 *)(param_1 + -0x68) = 0;
      *(undefined8 *)(param_1 + -0x60) = 0;
      *(undefined4 *)(param_1 + 0x48) = 0;
      if (*(int *)(*(code **)(param_1 + 0x40) + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1125e4);
        (*pcVar1)();
      }
      (**(code **)(param_1 + 0x40))();
    }
  }
  _raw_spin_unlock_bh(param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// dev_queue_xmit @ 0011260c size=32
// signature: undefined dev_queue_xmit(void)
// callers: []
//------------------------------------------------------------

void dev_queue_xmit(undefined8 param_1)

{
  __dev_queue_xmit(param_1,0);
  return;
}



//------------------------------------------------------------
// rmnet_map_tx_aggregate_exit @ 00112630 size=404
// signature: undefined rmnet_map_tx_aggregate_exit(void)
// callers: [rmnet_unregister_real_device]
//------------------------------------------------------------

void rmnet_map_tx_aggregate_exit(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  hrtimer_cancel(param_1 + 0x840);
  cancel_work_sync(param_1 + 0x888);
  hrtimer_cancel(param_1 + 0x920);
  cancel_work_sync(param_1 + 0x968);
  _raw_spin_lock_bh(param_1 + 0x8b8);
  if (*(int *)(param_1 + 0x8d0) == -0x73) {
    if (*(long *)(param_1 + 0x8c0) != 0) {
      kfree_skb_reason(*(long *)(param_1 + 0x8c0),1);
      *(undefined8 *)(param_1 + 0x8c0) = 0;
      *(undefined1 *)(param_1 + 0x8d4) = 0;
      *(undefined8 *)(param_1 + 0x820) = 0;
      *(undefined8 *)(param_1 + 0x828) = 0;
    }
    *(undefined4 *)(param_1 + 0x8d0) = 0;
  }
  plVar3 = *(long **)(param_1 + 0x8d8);
  while (plVar3 != (long *)(param_1 + 0x8d8)) {
    plVar5 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    rmnet_mem_put_page_entry(plVar3[2]);
    kfree(plVar3);
    plVar3 = plVar5;
  }
  *(undefined8 *)(param_1 + 0x8e8) = 0;
  _raw_spin_unlock_bh(param_1 + 0x8b8);
  _raw_spin_lock_bh(param_1 + 0x998);
  if (*(int *)(param_1 + 0x9b0) == -0x73) {
    if (*(long *)(param_1 + 0x9a0) != 0) {
      kfree_skb_reason(*(long *)(param_1 + 0x9a0),1);
      *(undefined8 *)(param_1 + 0x9a0) = 0;
      *(undefined1 *)(param_1 + 0x9b4) = 0;
      *(undefined8 *)(param_1 + 0x900) = 0;
      *(undefined8 *)(param_1 + 0x908) = 0;
    }
    *(undefined4 *)(param_1 + 0x9b0) = 0;
  }
  plVar3 = *(long **)(param_1 + 0x9b8);
  while (plVar3 != (long *)(param_1 + 0x9b8)) {
    plVar5 = (long *)*plVar3;
    uVar4 = __list_del_entry_valid(plVar3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar3;
      plVar2 = (long *)plVar3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    rmnet_mem_put_page_entry(plVar3[2]);
    kfree(plVar3);
    plVar3 = plVar5;
  }
  *(undefined8 *)(param_1 + 0x9c8) = 0;
  _raw_spin_unlock_bh(param_1 + 0x998);
  return;
}



//------------------------------------------------------------
// rmnet_map_tx_qmap_cmd @ 001127c8 size=280
// signature: undefined rmnet_map_tx_qmap_cmd(void)
// callers: [dfc_send_ack, rmnet_qmap_send]
//------------------------------------------------------------

void rmnet_map_tx_qmap_cmd(long param_1,byte param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  if (1 < param_2) {
    param_2 = 0;
  }
  lVar3 = rmnet_get_port(*(undefined8 *)(param_1 + 0x10));
  if (lVar3 == 0) {
    kfree_skb_reason(param_1,1);
  }
  else {
    uVar4 = (uint)param_2;
    if (((param_3 & 1) != 0) && (*(int *)(lVar3 + 8) < 0)) {
      lVar5 = lVar3 + (ulong)uVar4 * 0xe0;
      lVar1 = lVar5 + 0x8b8;
      _raw_spin_lock_bh(lVar1);
      if (*(long *)(lVar5 + 0x8c0) == 0) {
        _raw_spin_unlock_bh(lVar1);
      }
      else {
        lVar6 = lVar3 + (ulong)uVar4 * 0xe0;
        *(undefined8 *)(lVar5 + 0x8c0) = 0;
        *(undefined1 *)(lVar6 + 0x8d4) = 0;
        *(undefined8 *)(lVar6 + 0x820) = 0;
        *(undefined8 *)(lVar6 + 0x828) = 0;
        *(undefined4 *)(lVar6 + 0x8d0) = 0;
        if (*(int *)(*(code **)(lVar6 + 0x8c8) + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11286c);
          (*pcVar2)();
        }
        (**(code **)(lVar6 + 0x8c8))();
        _raw_spin_unlock_bh(lVar1);
        hrtimer_cancel(lVar6 + 0x840);
      }
    }
    pcVar2 = *(code **)(lVar3 + (ulong)uVar4 * 0xe0 + 0x8c8);
    if (*(int *)(pcVar2 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1128c4);
      (*pcVar2)();
    }
    (*pcVar2)(param_1);
  }
  return;
}



//------------------------------------------------------------
// rmnet_map_add_tso_header @ 001128e4 size=296
// signature: undefined rmnet_map_add_tso_header(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

undefined8 rmnet_map_add_tso_header(long param_1,long param_2,long param_3)

{
  ushort uVar1;
  ushort *puVar2;
  undefined8 uVar3;
  ushort uVar4;
  long lVar5;
  ulong uVar6;
  
  if ((*(ulong *)(param_3 + 0xe8) & 0x2001d0000) == 0) {
    uVar3 = 0xffffffea;
    lVar5 = 0xbe8;
  }
  else {
    puVar2 = (ushort *)skb_push(param_1,4);
    puVar2[0] = 6;
    puVar2[1] = 0;
    if (((*(byte *)(param_2 + 0xb) >> 4 & 1) == 0) || (*(int *)(param_1 + 0x8c) != 0xda001a)) {
      uVar4 = 0x8006;
    }
    else {
      *(long *)(param_3 + 0xbd8) = *(long *)(param_3 + 0xbd8) + 1;
      uVar4 = *puVar2 | 0xa000;
      *puVar2 = *puVar2 | 0x2000;
    }
    uVar1 = *(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 4);
    puVar2[1] = uVar1 >> 8 | uVar1 << 8;
    lVar5 = *(long *)(param_1 + 0xd8);
    uVar6 = (ulong)*(uint *)(param_1 + 0xd4);
    if ((*(byte *)(lVar5 + uVar6 + 0x18) >> 3 & 1) != 0) {
      *puVar2 = uVar4;
      lVar5 = *(long *)(param_1 + 0xd8);
      uVar6 = (ulong)*(uint *)(param_1 + 0xd4);
    }
    uVar3 = 0;
    *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) & 0xff9f;
    *(undefined2 *)(lVar5 + uVar6 + 4) = 0;
    *(undefined2 *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6) = 0;
    lVar5 = 0xbe0;
    *(undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 0x18) = 0;
  }
  *(long *)(param_3 + lVar5) = *(long *)(param_3 + lVar5) + 1;
  return uVar3;
}



//------------------------------------------------------------
// rmnet_map_partial_csum @ 00112a0c size=220
// signature: undefined rmnet_map_partial_csum(void)
// callers: [__rmnet_map_segment_coal_skb]
//------------------------------------------------------------

void rmnet_map_partial_csum(long param_1,long param_2)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  undefined2 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xe0);
  sVar1 = *(short *)(param_1 + 0x70) - *(short *)(param_2 + 0x10);
  if (*(char *)(param_2 + 0x18) == '\x04') {
    uVar3 = csum_tcpudp_nofold(*(undefined4 *)(lVar5 + 0xc),*(undefined4 *)(lVar5 + 0x10),sVar1,
                               *(undefined1 *)(param_2 + 0x19),0);
    uVar2 = (ushort)((uVar3 >> 0x10 | uVar3 << 0x10) + uVar3 >> 0x10);
  }
  else {
    uVar2 = csum_ipv6_magic(lVar5 + 8,lVar5 + 0x18,sVar1,*(undefined1 *)(param_2 + 0x19),0);
    uVar2 = ~uVar2;
  }
  lVar5 = lVar5 + (ulong)*(ushort *)(param_2 + 0x10);
  if (*(char *)(param_2 + 0x19) == '\x06') {
    uVar4 = 0x10;
    *(ushort *)(lVar5 + 0x10) = uVar2;
  }
  else {
    uVar4 = 6;
    *(ushort *)(lVar5 + 6) = uVar2;
  }
  *(undefined2 *)(param_1 + 0x8a) = uVar4;
  *(ushort *)(param_1 + 0x80) = *(ushort *)(param_1 + 0x80) | 0x60;
  *(short *)(param_1 + 0x88) =
       ((short)*(undefined4 *)(param_1 + 0xe0) + *(short *)(param_2 + 0x10)) -
       (short)*(undefined4 *)(param_1 + 0xd8);
  return;
}



//------------------------------------------------------------
// __rmnet_map_segment_coal_skb @ 00112ae8 size=1248
// signature: undefined __rmnet_map_segment_coal_skb(void)
// callers: [rmnet_map_process_next_hdr_packet]
//------------------------------------------------------------

void __rmnet_map_segment_coal_skb
               (long param_1,undefined8 *param_2,long param_3,char param_4,uint param_5)

{
  ulong *puVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  uint uVar7;
  long *plVar8;
  void *__dest;
  int iVar9;
  long *plVar10;
  long lVar11;
  ulong uVar12;
  ulong *puVar13;
  undefined4 uVar14;
  int iVar15;
  size_t __n;
  ushort *puVar16;
  long lVar17;
  
  iVar4 = (uint)*(byte *)((long)param_2 + 0x1b) * (uint)*(ushort *)((long)param_2 + 0x16);
  lVar17 = *(long *)(param_1 + 0x10);
  iVar9 = iVar4;
  if (*(int *)(param_1 + 0x74) != 0) {
    iVar9 = 0;
  }
  lVar11 = (ulong)*(ushort *)((long)param_2 + 0x12) + (ulong)*(ushort *)(param_2 + 2);
  iVar15 = (int)lVar11;
  plVar8 = (long *)__alloc_skb(iVar9 + iVar15,0xa20,0,0xffffffff);
  if (plVar8 == (long *)0x0) {
    return;
  }
  plVar8[0x1c] = plVar8[0x1c] + lVar11;
  *(int *)(plVar8 + 0x1a) = (int)plVar8[0x1a] + iVar15;
  iVar9 = *(int *)(param_1 + 0x74);
  if ((iVar9 == 0) || (*(int *)(param_1 + 0x70) != iVar9)) {
    lVar11 = *(long *)(param_1 + 0xe0);
  }
  else {
    lVar11 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    lVar11 = ((*(ulong *)(lVar11 + 0x48) & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
             (ulong)*(uint *)(lVar11 + 0x54);
    iVar9 = *(int *)(param_1 + 0x74);
  }
  uVar6 = *(ushort *)(param_2 + 2);
  __n = (ulong)*(byte *)((long)param_2 + 0x1b) * (ulong)*(ushort *)((long)param_2 + 0x16);
  uVar2 = *(ushort *)((long)param_2 + 0x12);
  if (iVar9 == 0) {
    uVar3 = *(ushort *)((long)param_2 + 0x14);
    __dest = (void *)skb_put(plVar8,__n);
    memcpy(__dest,(void *)(lVar11 + (ulong)uVar6 + (ulong)uVar2 + (ulong)uVar3),__n);
  }
  else {
    lVar11 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
    skb_append_pagefrags
              (plVar8,*(undefined8 *)(lVar11 + 0x48),
               (uint)uVar2 + (uint)uVar6 + (uint)*(ushort *)((long)param_2 + 0x14) +
               *(int *)(lVar11 + 0x54),__n);
    *(int *)(plVar8 + 0xe) = (int)plVar8[0xe] + (int)__n;
    *(int *)((long)plVar8 + 0x74) = *(int *)((long)plVar8 + 0x74) + (int)__n;
  }
  skb_push(plVar8,*(undefined2 *)((long)param_2 + 0x12));
  memcpy((void *)plVar8[0x1c],(void *)param_2[1],(ulong)*(ushort *)((long)param_2 + 0x12));
  lVar11 = plVar8[0x1b];
  uVar12 = plVar8[0x1c] - lVar11;
  *(short *)((long)plVar8 + 0xb6) = (short)uVar12;
  if (*(char *)((long)param_2 + 0x19) == '\x11') {
    lVar11 = lVar11 + (uVar12 & 0xffff);
    puVar16 = (ushort *)(lVar11 + 6);
    *(ushort *)(lVar11 + 4) = *(ushort *)(plVar8 + 0xe) >> 8 | *(ushort *)(plVar8 + 0xe) << 8;
    if (*(char *)(param_2 + 3) == '\x04') {
      bVar5 = *puVar16 == 0;
      goto LAB_00112d58;
    }
  }
  else {
    if (*(char *)((long)param_2 + 0x19) != '\x06') {
      bVar5 = false;
      puVar16 = (ushort *)0x0;
      goto LAB_00112d58;
    }
    lVar11 = lVar11 + (uVar12 & 0xffff);
    puVar16 = (ushort *)(lVar11 + 0x10);
    uVar7 = (*(uint *)(lVar11 + 4) & 0xff00ff00) >> 8 | (*(uint *)(lVar11 + 4) & 0xff00ff) << 8;
    uVar7 = (uVar7 >> 0x10 | uVar7 << 0x10) + (uint)*(ushort *)((long)param_2 + 0x14);
    uVar7 = (uVar7 & 0xff00ff00) >> 8 | (uVar7 & 0xff00ff) << 8;
    *(uint *)(lVar11 + 4) = uVar7 >> 0x10 | uVar7 << 0x10;
    if (((*(ushort *)(lVar11 + 0xc) & 0x900) != 0) &&
       (iVar15 + iVar4 + (uint)*(ushort *)((long)param_2 + 0x14) < *(uint *)(param_1 + 0x70))) {
      bVar5 = false;
      *(ushort *)(lVar11 + 0xc) = *(ushort *)(lVar11 + 0xc) & 0xf6ff;
      goto LAB_00112d58;
    }
  }
  bVar5 = false;
LAB_00112d58:
  skb_push(plVar8,*(undefined2 *)(param_2 + 2));
  memcpy((void *)plVar8[0x1c],(void *)*param_2,(ulong)*(ushort *)(param_2 + 2));
  lVar11 = plVar8[0x1b];
  uVar12 = plVar8[0x1c] - lVar11;
  *(short *)(plVar8 + 0x17) = (short)uVar12;
  if (*(char *)(param_2 + 3) == '\x04') {
    puVar1 = (ulong *)(lVar11 + (uVar12 & 0xffff));
    uVar7 = (uint)*(byte *)((long)param_2 + 0x1a) +
            ((uint)(*(ushort *)((long)puVar1 + 4) >> 8) |
            (*(ushort *)((long)puVar1 + 4) & 0xff00ff) << 8);
    *(ushort *)((long)puVar1 + 4) = (ushort)(uVar7 >> 8) & 0xff | (ushort)((uVar7 & 0xff00ff) << 8);
    uVar6 = *(ushort *)(plVar8 + 0xe);
    *(undefined2 *)((long)puVar1 + 10) = 0;
    *(ushort *)((long)puVar1 + 2) = uVar6 >> 8 | uVar6 << 8;
    uVar12 = *puVar1 + puVar1[1] + (ulong)CARRY8(puVar1[1],*puVar1);
    iVar9 = ((byte)*puVar1 & 0xf) - 3;
    puVar13 = puVar1 + 2;
    do {
      iVar9 = iVar9 + -1;
      uVar12 = uVar12 + (uint)*puVar13;
      puVar13 = (ulong *)((long)puVar13 + 4);
    } while (1 < iVar9);
    uVar7 = (uint)((uVar12 >> 0x20 | uVar12 << 0x20) + uVar12 >> 0x20);
    *(ushort *)((long)puVar1 + 10) =
         (ushort)((uVar7 >> 0x10 | uVar7 << 0x10) + uVar7 >> 0x10) ^ 0xffff;
  }
  else {
    *(ushort *)(lVar11 + (uVar12 & 0xffff) + 4) =
         (ushort)(*(ushort *)(plVar8 + 0xe) - 0x28 >> 8) & 0xff |
         (ushort)((*(ushort *)(plVar8 + 0xe) - 0x28 & 0xff00ff) << 8);
  }
  if (bVar5 || (param_5 & 1) != 0) {
    rmnet_map_partial_csum(plVar8,param_2);
  }
  else if (puVar16 != (ushort *)0x0) {
    iVar9 = ((int)plVar8[0x1b] + (uint)*(ushort *)((long)plVar8 + 0xb6)) - (int)plVar8[0x1c];
    lVar11 = plVar8[0x1b] + (ulong)*(ushort *)(plVar8 + 0x17);
    if (*(char *)(param_2 + 3) == '\x04') {
      uVar7 = csum_tcpudp_nofold(*(undefined4 *)(lVar11 + 0xc),*(undefined4 *)(lVar11 + 0x10),
                                 (int)plVar8[0xe] - (uint)*(ushort *)(param_2 + 2),
                                 *(undefined1 *)((long)param_2 + 0x19),0);
      uVar6 = (ushort)((uVar7 >> 0x10 | uVar7 << 0x10) + uVar7 >> 0x10);
    }
    else {
      uVar6 = csum_ipv6_magic(lVar11 + 8,lVar11 + 0x18,
                              (int)plVar8[0xe] - (uint)*(ushort *)(param_2 + 2),
                              *(undefined1 *)((long)param_2 + 0x19),0);
      uVar6 = ~uVar6;
    }
    *puVar16 = uVar6;
    uVar7 = skb_checksum(plVar8,iVar9,(int)plVar8[0xe] - iVar9,0);
    iVar9 = -((uVar7 >> 0x10 | uVar7 << 0x10) + uVar7 >> 0x10);
    uVar7 = iVar9 + 0xff;
    uVar6 = (ushort)uVar7;
    if ((uVar7 & 0xffff) < 0x100) {
      uVar6 = (short)iVar9 + 0x100;
    }
    *puVar16 = uVar6;
    *(ushort *)(plVar8 + 0x10) = *(ushort *)(plVar8 + 0x10) & 0xff9f;
  }
  plVar8[2] = *(long *)(param_1 + 0x10);
  *(long *)(lVar17 + 0xad8) = *(long *)(lVar17 + 0xad8) + 1;
  if (1 < *(byte *)((long)param_2 + 0x1b)) {
    if (*(char *)((long)param_2 + 0x19) == '\x06') {
      uVar14 = 0x10;
      if (*(char *)(param_2 + 3) == '\x04') {
        uVar14 = 1;
      }
    }
    else {
      uVar14 = 0x20000;
    }
    lVar17 = plVar8[0x1b] + (ulong)*(uint *)((long)plVar8 + 0xd4);
    *(undefined4 *)(lVar17 + 0x18) = uVar14;
    *(undefined2 *)(lVar17 + 4) = *(undefined2 *)((long)param_2 + 0x16);
    *(ushort *)(lVar17 + 6) = (ushort)*(byte *)((long)param_2 + 0x1b);
  }
  *(undefined4 *)((long)plVar8 + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  plVar10 = *(long **)(param_3 + 8);
  *plVar8 = param_3;
  plVar8[1] = (long)plVar10;
  *(long **)(param_3 + 8) = plVar8;
  *plVar10 = (long)plVar8;
  *(int *)(param_3 + 0x10) = *(int *)(param_3 + 0x10) + 1;
  *(char *)((long)param_2 + 0x1a) = param_4 + '\x01';
  *(undefined1 *)((long)param_2 + 0x1b) = 0;
  *(short *)((long)param_2 + 0x14) = *(short *)((long)param_2 + 0x14) + (short)iVar4;
  return;
}



//------------------------------------------------------------
// rmnet_module_hook_register @ 00112fd4 size=84
// signature: undefined rmnet_module_hook_register(void)
// callers: []
//------------------------------------------------------------

void rmnet_module_hook_register(long param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  if (0 < (int)param_2) {
    uVar3 = (ulong)param_2;
    puVar4 = (undefined8 *)(param_1 + 8);
    do {
      uVar1 = *(uint *)(puVar4 + -1);
      if ((int)uVar1 < 0x13) {
        if (0x13 < uVar1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x113028);
          (*pcVar2)();
        }
        (&rmnet_module_hooks)[uVar1] = *puVar4;
      }
      puVar4 = puVar4 + 2;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



//------------------------------------------------------------
// rmnet_module_hook_is_set @ 0011302c size=52
// signature: undefined rmnet_module_hook_is_set(void)
// callers: []
//------------------------------------------------------------

bool rmnet_module_hook_is_set(uint param_1)

{
  code *pcVar1;
  
  if (0x12 < (int)param_1) {
    return false;
  }
  if (0x12 < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x113060);
    (*pcVar1)();
  }
  return (&rmnet_module_hooks)[param_1] != 0;
}



//------------------------------------------------------------
// rmnet_module_hook_unregister_no_sync @ 00113064 size=72
// signature: undefined rmnet_module_hook_unregister_no_sync(void)
// callers: []
//------------------------------------------------------------

void rmnet_module_hook_unregister_no_sync(uint *param_1,uint param_2)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  
  if (0 < (int)param_2) {
    uVar3 = (ulong)param_2;
    do {
      uVar1 = *param_1;
      if ((int)uVar1 < 0x13) {
        if (0x13 < uVar1) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1130ac);
          (*pcVar2)();
        }
        (&rmnet_module_hooks)[uVar1] = 0;
      }
      param_1 = param_1 + 4;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return;
}



//------------------------------------------------------------
// rmnet_module_hook_offload_ingress @ 001130b0 size=112
// signature: undefined rmnet_module_hook_offload_ingress(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_offload_ingress(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (rmnet_module_hooks == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(rmnet_module_hooks + -4) != -0xb6b45e) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1130f8);
      (*pcVar1)();
    }
    (*rmnet_module_hooks)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_offload_chain_end @ 00113124 size=96
// signature: undefined rmnet_module_hook_offload_chain_end(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_offload_chain_end(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_001289d8 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_001289d8 + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11315c);
      (*pcVar1)();
    }
    (*DAT_001289d8)();
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_shs_skb_entry @ 00113188 size=132
// signature: undefined rmnet_module_hook_shs_skb_entry(void)
// callers: []
//------------------------------------------------------------

undefined8
rmnet_module_hook_shs_skb_entry(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_001289e0 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_001289e0 + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1131d8);
      (*pcVar1)();
    }
    uVar2 = (*DAT_001289e0)(param_2,param_3);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_module_hook_shs_skb_ll_entry @ 00113210 size=132
// signature: undefined rmnet_module_hook_shs_skb_ll_entry(void)
// callers: [rmnet_deliver_skb]
//------------------------------------------------------------

undefined8
rmnet_module_hook_shs_skb_ll_entry(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_001289e8 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_001289e8 + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113260);
      (*pcVar1)();
    }
    uVar2 = (*DAT_001289e8)(param_2,param_3);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_module_hook_shs_switch @ 00113298 size=132
// signature: undefined rmnet_module_hook_shs_switch(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_shs_switch(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_001289f0 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_001289f0 + -4) != -0x4bc665f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1132e8);
      (*pcVar1)();
    }
    uVar2 = (*DAT_001289f0)(param_2,param_3);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_tether_ingress @ 00113320 size=112
// signature: undefined rmnet_module_hook_perf_tether_ingress(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_tether_ingress(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_001289f8 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_001289f8 + -4) != -0x47fee3e2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113368);
      (*pcVar1)();
    }
    (*DAT_001289f8)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_tether_egress @ 00113394 size=104
// signature: undefined rmnet_module_hook_perf_tether_egress(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_tether_egress(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a00 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a00 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1133d4);
      (*pcVar1)();
    }
    (*DAT_00128a00)(param_1);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_tether_cmd @ 00113400 size=112
// signature: undefined rmnet_module_hook_perf_tether_cmd(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_tether_cmd(undefined4 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a08 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a08 + -4) != 0x1f1615a4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113448);
      (*pcVar1)();
    }
    (*DAT_00128a08)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_ingress @ 00113474 size=116
// signature: undefined rmnet_module_hook_perf_ingress(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_ingress(undefined4 *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_00128a10 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_00128a10 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1134b8);
      (*pcVar1)();
    }
    uVar2 = (*DAT_00128a10)(param_2);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_egress @ 001134ec size=104
// signature: undefined rmnet_module_hook_perf_egress(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_egress(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a18 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a18 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11352c);
      (*pcVar1)();
    }
    (*DAT_00128a18)(param_1);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_set_thresh @ 00113558 size=112
// signature: undefined rmnet_module_hook_perf_set_thresh(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_set_thresh(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a20 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a20 + -4) != 0x672f477d) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1135a0);
      (*pcVar1)();
    }
    (*DAT_00128a20)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_aps_pre_queue @ 001135cc size=112
// signature: undefined rmnet_module_hook_aps_pre_queue(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_aps_pre_queue(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a28 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a28 + -4) != -0x4bbdebc5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113614);
      (*pcVar1)();
    }
    (*DAT_00128a28)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_aps_post_queue @ 00113640 size=132
// signature: undefined rmnet_module_hook_aps_post_queue(void)
// callers: []
//------------------------------------------------------------

undefined8
rmnet_module_hook_aps_post_queue(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_00128a30 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_00128a30 + -4) != -0x2ffe9d0e) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113690);
      (*pcVar1)();
    }
    uVar2 = (*DAT_00128a30)(param_2,param_3);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_module_hook_wlan_flow_match @ 001136c8 size=104
// signature: undefined rmnet_module_hook_wlan_flow_match(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_module_hook_wlan_flow_match(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a38 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a38 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113708);
      (*pcVar1)();
    }
    (*DAT_00128a38)(param_1);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_aps_data_inactive @ 00113734 size=96
// signature: undefined rmnet_module_hook_aps_data_inactive(void)
// callers: [qmi_rmnet_check_stats_2, qmi_rmnet_pm_notify_cb]
//------------------------------------------------------------

undefined8 rmnet_module_hook_aps_data_inactive(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a40 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a40 + -4) != -0x5abf98f4) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11376c);
      (*pcVar1)();
    }
    (*DAT_00128a40)();
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_aps_data_active @ 00113798 size=112
// signature: undefined rmnet_module_hook_aps_data_active(void)
// callers: [qmi_rmnet_work_maybe_restart]
//------------------------------------------------------------

undefined8 rmnet_module_hook_aps_data_active(undefined8 param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a48 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a48 + -4) != 0x29ec6bc9) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1137e0);
      (*pcVar1)();
    }
    (*DAT_00128a48)(param_1,param_2);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_aps_data_report @ 0011380c size=104
// signature: undefined rmnet_module_hook_aps_data_report(void)
// callers: [rmnet_qmap_cmd_handler]
//------------------------------------------------------------

undefined8 rmnet_module_hook_aps_data_report(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a50 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a50 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11384c);
      (*pcVar1)();
    }
    (*DAT_00128a50)(param_1);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_perf_ingress_rx_handler @ 00113878 size=104
// signature: undefined rmnet_module_hook_perf_ingress_rx_handler(void)
// callers: [rmnet_rx_priv_handler]
//------------------------------------------------------------

undefined8 rmnet_module_hook_perf_ingress_rx_handler(undefined8 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  __rcu_read_lock();
  if (DAT_00128a58 == (code *)0x0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(DAT_00128a58 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1138b8);
      (*pcVar1)();
    }
    (*DAT_00128a58)(param_1);
    uVar2 = 1;
  }
  __rcu_read_unlock();
  return uVar2;
}



//------------------------------------------------------------
// rmnet_module_hook_wlan_ingress_rx_handler @ 001138e4 size=116
// signature: undefined rmnet_module_hook_wlan_ingress_rx_handler(void)
// callers: [rmnet_rx_priv_handler]
//------------------------------------------------------------

undefined8 rmnet_module_hook_wlan_ingress_rx_handler(undefined4 *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  __rcu_read_lock();
  if (DAT_00128a60 == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(DAT_00128a60 + -4) != 0x68f38d23) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x113928);
      (*pcVar1)();
    }
    uVar2 = (*DAT_00128a60)(param_2);
    uVar3 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = uVar2;
    }
  }
  __rcu_read_unlock();
  return uVar3;
}



//------------------------------------------------------------
// rmnet_vnd_rx_fixup @ 0011395c size=32
// signature: undefined rmnet_vnd_rx_fixup(void)
// callers: [rmnet_deliver_skb_wq, rmnet_deliver_skb]
//------------------------------------------------------------

void rmnet_vnd_rx_fixup(long param_1,uint param_2)

{
  long *plVar1;
  long lVar2;
  
  lVar2 = tpidr_el1;
  plVar1 = (long *)(lVar2 + *(long *)(param_1 + 0xa50));
  *plVar1 = *plVar1 + 1;
  plVar1[1] = plVar1[1] + (ulong)param_2;
  return;
}



//------------------------------------------------------------
// rmnet_vnd_tx_fixup @ 00113980 size=32
// signature: undefined rmnet_vnd_tx_fixup(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

void rmnet_vnd_tx_fixup(long param_1,uint param_2)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  lVar1 = lVar1 + *(long *)(param_1 + 0xa50);
  *(long *)(lVar1 + 0x10) = *(long *)(lVar1 + 0x10) + 1;
  *(ulong *)(lVar1 + 0x18) = *(long *)(lVar1 + 0x18) + (ulong)param_2;
  return;
}



//------------------------------------------------------------
// rmnet_vnd_setup @ 001139a4 size=152
// signature: undefined rmnet_vnd_setup(void)
// callers: []
//------------------------------------------------------------

void rmnet_vnd_setup(long param_1)

{
  *(undefined4 *)(param_1 + 0xe0) = 0x5dc;
  *(undefined ***)(param_1 + 0xd0) = &rmnet_vnd_ops;
  *(undefined2 *)(param_1 + 0xe4) = 0x10;
  get_random_bytes(param_1 + 0x224,6);
  *(undefined8 *)(param_1 + 0x218) = 0;
  *(undefined4 *)(param_1 + 0x3d8) = 1000;
  *(undefined2 *)(param_1 + 0x128) = 0x207;
  *(undefined2 *)(param_1 + 0xde) = 0;
  *(uint *)(param_1 + 0xc0) = *(uint *)(param_1 + 0xc0) & 0xffffeffd;
  *(undefined1 *)(param_1 + 0x4f4) = 1;
  *(byte *)(param_1 + 0x224) = *(byte *)(param_1 + 0x224) & 0xfc | 2;
  *(undefined1 **)(param_1 + 0x208) = rmnet_ethtool_ops;
  return;
}



//------------------------------------------------------------
// rmnet_vnd_newlink @ 00113a40 size=216
// signature: undefined rmnet_vnd_newlink(void)
// callers: [rmnet_newlink]
//------------------------------------------------------------

undefined8
rmnet_vnd_newlink(undefined4 param_1,long param_2,long param_3,undefined8 param_4,
                 undefined1 *param_5)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(long *)(param_5 + 8) == 0) {
    lVar2 = rmnet_get_endpoint(param_3,param_1);
    if (lVar2 == 0) {
      *(undefined8 *)(param_2 + 0xa48) = param_4;
      *(undefined4 *)(param_2 + 0x8e0) = 0xffff;
      *(undefined8 *)(param_2 + 0xf0) = 0x800102001d0013;
      uVar1 = register_netdevice(param_2);
      if ((int)uVar1 == 0) {
        *(long *)(param_5 + 8) = param_2;
        *param_5 = (char)param_1;
        *(char *)(param_3 + 0xc) = *(char *)(param_3 + 0xc) + '\x01';
        *(undefined1 **)(param_2 + 0x8d8) = &rmnet_link_ops;
        *(char *)(param_2 + 0xa40) = (char)param_1;
        uVar1 = qmi_rmnet_qos_init(param_4,param_2,param_1);
        *(undefined8 *)(param_2 + 0xc20) = uVar1;
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0xfffffff0;
    }
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_vnd_dellink @ 00113b1c size=52
// signature: undefined rmnet_vnd_dellink(void)
// callers: [rmnet_dellink, rmnet_config_notify_cb]
//------------------------------------------------------------

undefined8 rmnet_vnd_dellink(char param_1,long param_2,long param_3)

{
  if ((param_1 == -1) || (*(long *)(param_3 + 8) == 0)) {
    return 0xffffffea;
  }
  *(undefined8 *)(param_3 + 8) = 0;
  *(char *)(param_2 + 0xc) = *(char *)(param_2 + 0xc) + -1;
  return 0;
}



//------------------------------------------------------------
// rmnet_vnd_get_mux @ 00113b54 size=8
// signature: undefined rmnet_vnd_get_mux(void)
// callers: [rmnet_dellink]
//------------------------------------------------------------

undefined1 rmnet_vnd_get_mux(long param_1)

{
  return *(undefined1 *)(param_1 + 0xa40);
}



//------------------------------------------------------------
// rmnet_vnd_do_flow_control @ 00113b60 size=92
// signature: undefined rmnet_vnd_do_flow_control(void)
// callers: [rmnet_map_do_flow_control, rmnet_frag_command]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 rmnet_vnd_do_flow_control(long param_1,int param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x3c0);
  if (param_2 == 0) {
    *(undefined8 *)(lVar4 + 200) = _jiffies;
    DataMemoryBarrier(2,3);
    puVar1 = (ulong *)(lVar4 + 0xd0);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  else {
    netif_tx_wake_queue();
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_vnd_reset_mac_addr @ 00113bcc size=84
// signature: undefined rmnet_vnd_reset_mac_addr(void)
// callers: [rmnet_config_notify_cb]
//------------------------------------------------------------

void rmnet_vnd_reset_mac_addr(long param_1)

{
  if (*(undefined ***)(param_1 + 0xd0) == &rmnet_vnd_ops) {
    get_random_bytes(param_1 + 0x224,6);
    *(byte *)(param_1 + 0x224) = *(byte *)(param_1 + 0x224) & 0xfc | 2;
  }
  return;
}



//------------------------------------------------------------
// rmnet_vnd_init @ 00113c24 size=96
// signature: undefined rmnet_vnd_init(void)
// callers: []
//------------------------------------------------------------

int rmnet_vnd_init(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = __alloc_percpu(0x28,8);
  *(long *)(param_1 + 0xa50) = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0xc;
  }
  else {
    iVar1 = gro_cells_init(param_1 + 0xa58,param_1);
    if (iVar1 != 0) {
      free_percpu(*(undefined8 *)(param_1 + 0xa50));
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// rmnet_vnd_uninit @ 00113c88 size=64
// signature: undefined rmnet_vnd_uninit(void)
// callers: []
//------------------------------------------------------------

void rmnet_vnd_uninit(long param_1)

{
  undefined8 uVar1;
  
  gro_cells_destroy(param_1 + 0xa58);
  free_percpu(*(undefined8 *)(param_1 + 0xa50));
  uVar1 = *(undefined8 *)(param_1 + 0xc20);
  *(undefined8 *)(param_1 + 0xc20) = 0;
  qmi_rmnet_qos_exit_pre(uVar1);
  return;
}



//------------------------------------------------------------
// rmnet_vnd_start_xmit @ 00113ccc size=1184
// signature: undefined rmnet_vnd_start_xmit(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_vnd_start_xmit(long param_1,long param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  ushort uVar6;
  long lVar7;
  short sVar8;
  code *pcVar9;
  bool bVar10;
  int iVar11;
  undefined8 *puVar12;
  undefined8 uVar13;
  char cVar14;
  undefined4 uVar15;
  long lVar16;
  undefined8 *puVar17;
  uint uVar18;
  char local_60 [4];
  char local_5c [4];
  long local_58;
  
  lVar16 = sp_el0;
  local_58 = *(long *)(lVar16 + 0x638);
  local_5c[0] = '\0';
  local_60[0] = '\0';
  if (rmnet_aps_post_queue == (code *)0x0) {
LAB_00113d3c:
    if (*(long *)(param_2 + 0xa48) == 0) {
      lVar16 = sp_el0;
      *(int *)(lVar16 + 0x10) = *(int *)(lVar16 + 0x10) + 1;
      lVar7 = tpidr_el1;
      piVar1 = (int *)(*(long *)(param_2 + 0xa50) + lVar7 + 0x20);
      do {
        cVar14 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar10) {
          *piVar1 = *piVar1 + 1;
          cVar14 = ExclusiveMonitorsStatus();
        }
      } while (cVar14 != '\0');
      goto LAB_00113e40;
    }
    uVar2 = *(undefined4 *)(param_1 + 0xa8);
    uVar3 = *(undefined4 *)(param_1 + 0x70);
    uVar15 = 2;
    if ((*(byte *)(*(long *)(param_1 + 0xd8) + (ulong)*(ushort *)(param_1 + 0xb8)) & 0xf0) != 0x40)
    {
      uVar15 = 10;
    }
    if (rmnet_perf_tether_egress_hook != (code *)0x0) {
      if (*(int *)(rmnet_perf_tether_egress_hook + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x113d98);
        (*pcVar9)();
      }
      (*rmnet_perf_tether_egress_hook)(param_1);
    }
    if (rmnet_wlan_ll_tuple_hook != (code *)0x0) {
      if (*(int *)(rmnet_wlan_ll_tuple_hook + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x113dc4);
        (*pcVar9)();
      }
      (*rmnet_wlan_ll_tuple_hook)(param_1);
    }
    qmi_rmnet_get_flow_state(param_2,param_1,local_60,local_5c);
    if (local_60[0] != '\0') {
      lVar16 = sp_el0;
      *(int *)(lVar16 + 0x10) = *(int *)(lVar16 + 0x10) + 1;
      lVar7 = tpidr_el1;
      piVar1 = (int *)(*(long *)(param_2 + 0xa50) + lVar7 + 0x20);
      do {
        cVar14 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar10) {
          *piVar1 = *piVar1 + 1;
          cVar14 = ExclusiveMonitorsStatus();
        }
      } while (cVar14 != '\0');
      goto LAB_00113e40;
    }
    if ((*(uint *)(param_1 + 0x8c) & 0xffff0100) != 0x9b6d0100) {
      if (local_5c[0] != '\0') goto LAB_00113e68;
      lVar16 = *(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4);
      uVar6 = *(ushort *)(lVar16 + 4);
      if ((*(uint *)(param_1 + 0x8c) & 0xffff0200) == 0x9b6d0200) {
        if (uVar6 == 0) goto LAB_0011402c;
        goto LAB_00113e7c;
      }
      uVar18 = (uint)uVar6;
      if (uVar18 == 0) {
LAB_0011402c:
        cVar14 = '\0';
        goto LAB_00114030;
      }
      uVar4 = *(uint *)(*(long *)(param_2 + 0xa48) + 0x8e0);
      if (uVar4 == 0) {
        uVar4 = 1;
      }
      if ((*(uint *)(param_1 + 0x70) < uVar4) || (0xffff < uVar4)) {
        bVar10 = false;
        *(long *)(param_2 + 0xc00) = *(long *)(param_2 + 0xc00) + 1;
        goto LAB_00114038;
      }
      sVar8 = 0;
      if (uVar18 != 0) {
        sVar8 = (short)((uVar4 & 0xffff) / uVar18);
      }
      uVar5 = *(undefined4 *)(lVar16 + 0x18);
      *(ushort *)(lVar16 + 4) = sVar8 * uVar6;
      puVar12 = (undefined8 *)__skb_gso_segment(param_1,0x13,0);
      if ((puVar12 == (undefined8 *)0x0) || ((undefined8 *)0xfffffffffffff000 < puVar12)) {
        *(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 4) = uVar6;
        *(undefined4 *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 0x18) = uVar5
        ;
        bVar10 = local_5c[0] != '\0';
        *(long *)(param_2 + 0xbf8) = *(long *)(param_2 + 0xbf8) + 1;
        goto LAB_00114038;
      }
      consume_skb(param_1);
      do {
        puVar12[2] = param_2;
        puVar17 = (undefined8 *)*puVar12;
        *(ushort *)(puVar12[0x1b] + (ulong)*(uint *)((long)puVar12 + 0xd4) + 4) = uVar6;
        *(undefined4 *)(puVar12[0x1b] + (ulong)*(uint *)((long)puVar12 + 0xd4) + 0x18) = uVar5;
        *(long *)(param_2 + 0xbf0) = *(long *)(param_2 + 0xbf0) + 1;
        *puVar12 = 0;
        rmnet_egress_handler(puVar12,local_5c[0]);
        puVar12 = puVar17;
      } while (puVar17 != (undefined8 *)0x0);
LAB_00114040:
      qmi_rmnet_burst_fc_check(param_2,uVar15,uVar2,uVar3);
      uVar13 = rmnet_get_rmnet_port(param_2);
      qmi_rmnet_work_maybe_restart(uVar13,0,0);
      goto LAB_00114068;
    }
    local_5c[0] = '\x01';
LAB_00113e68:
    cVar14 = local_5c[0];
    if (*(short *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 4) == 0) {
LAB_00114030:
      bVar10 = cVar14 != '\0';
LAB_00114038:
      rmnet_egress_handler(param_1,bVar10);
      goto LAB_00114040;
    }
LAB_00113e7c:
    puVar12 = (undefined8 *)
              __skb_gso_segment(param_1,*(ulong *)(param_2 + 0xe8) & 0xfffffff80000ffff,1);
    if ((puVar12 != (undefined8 *)0x0) && (puVar12 < (undefined8 *)0xfffffffffffff001)) {
      consume_skb(param_1);
      do {
        puVar12[2] = param_2;
        puVar17 = (undefined8 *)*puVar12;
        *(long *)(param_2 + 0xc08) = *(long *)(param_2 + 0xc08) + 1;
        *puVar12 = 0;
        rmnet_egress_handler(puVar12,local_5c[0]);
        puVar12 = puVar17;
      } while (puVar17 != (undefined8 *)0x0);
      goto LAB_00114040;
    }
    lVar16 = sp_el0;
    *(int *)(lVar16 + 0x10) = *(int *)(lVar16 + 0x10) + 1;
    lVar7 = tpidr_el1;
    piVar1 = (int *)(*(long *)(param_2 + 0xa50) + lVar7 + 0x20);
    uVar6 = *(ushort *)(*(long *)(param_1 + 0xd8) + (ulong)*(uint *)(param_1 + 0xd4) + 6);
    do {
      cVar14 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = *piVar1 + (uint)uVar6;
        cVar14 = ExclusiveMonitorsStatus();
      }
    } while (cVar14 != '\0');
    lVar7 = *(long *)(lVar16 + 0x10) + -1;
    *(int *)(lVar16 + 0x10) = (int)lVar7;
    if ((lVar7 == 0) || (*(long *)(lVar16 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
    *(long *)(param_2 + 0xc10) = *(long *)(param_2 + 0xc10) + 1;
  }
  else {
    if (*(int *)(rmnet_aps_post_queue + -4) != -0x2ffe9d0e) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x113d34);
      (*pcVar9)();
    }
    iVar11 = (*rmnet_aps_post_queue)(param_2,param_1);
    if (iVar11 == 0) goto LAB_00113d3c;
    lVar16 = sp_el0;
    *(int *)(lVar16 + 0x10) = *(int *)(lVar16 + 0x10) + 1;
    lVar7 = tpidr_el1;
    piVar1 = (int *)(*(long *)(param_2 + 0xa50) + lVar7 + 0x20);
    do {
      cVar14 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = *piVar1 + 1;
        cVar14 = ExclusiveMonitorsStatus();
      }
    } while (cVar14 != '\0');
LAB_00113e40:
    lVar7 = *(long *)(lVar16 + 0x10) + -1;
    *(int *)(lVar16 + 0x10) = (int)lVar7;
    if ((lVar7 == 0) || (*(long *)(lVar16 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
  }
  kfree_skb_reason(param_1,1);
LAB_00114068:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_vnd_select_queue @ 001141d8 size=296
// signature: undefined rmnet_vnd_select_queue(void)
// callers: []
//------------------------------------------------------------

void rmnet_vnd_select_queue(long param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 local_b4;
  undefined8 local_b0 [13];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_b0[0] = 0;
  local_b4 = 0;
  if (rmnet_perf_egress_hook1 != (code *)0x0) {
    if (*(int *)(rmnet_perf_egress_hook1 + -4) != 0x50ad483a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x114238);
      (*pcVar2)();
    }
    (*rmnet_perf_egress_hook1)(param_2);
  }
  if (*(long *)(param_1 + 0xa48) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = qmi_rmnet_get_queue(param_1,param_2);
  }
  if (rmnet_core_userspace_connected != 0) {
    lVar1 = sp_el0;
    rmnet_update_pid_and_check_boost
              (*(undefined4 *)(lVar1 + 0x630),*(undefined4 *)(param_2 + 0x70),&local_b4,local_b0);
  }
  if (rmnet_aps_pre_queue != (code *)0x0) {
    if (*(int *)(rmnet_aps_pre_queue + -4) != -0x4bbdebc5) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1142bc);
      (*pcVar2)();
    }
    (*rmnet_aps_pre_queue)(param_1,param_2);
  }
  lVar1 = sp_el0;
  if (*(uint *)(param_1 + 0x3cc) <= uVar3) {
    uVar3 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// rmnet_vnd_change_mtu @ 00114948 size=28
// signature: undefined rmnet_vnd_change_mtu(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_vnd_change_mtu(long param_1,uint param_2)

{
  if (param_2 < 0x4001) {
    *(uint *)(param_1 + 0xe0) = param_2;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// rmnet_get_stats64 @ 00114968 size=228
// signature: undefined rmnet_get_stats64(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_get_stats64(long param_1,long *param_2)

{
  long *plVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  uint uVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = 0;
  lVar5 = 0;
  lVar8 = 0;
  lVar6 = 0;
  uVar7 = 0;
  iVar4 = 0;
  while( true ) {
    uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar4);
    if (_nr_cpu_ids <= uVar3) {
      *param_2 = lVar9;
      param_2[1] = lVar8;
      param_2[2] = lVar5;
      param_2[3] = lVar6;
      param_2[7] = (ulong)uVar7;
      return;
    }
    if (0x1f < (ulong)uVar3) break;
    plVar1 = (long *)(*(long *)(&__per_cpu_offset + (ulong)uVar3 * 8) + *(long *)(param_1 + 0xa50));
    lVar8 = plVar1[2] + lVar8;
    lVar6 = plVar1[3] + lVar6;
    lVar9 = *plVar1 + lVar9;
    lVar5 = plVar1[1] + lVar5;
    uVar7 = (int)plVar1[4] + uVar7;
    iVar4 = uVar3 + 1;
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x114a4c);
  (*pcVar2)();
}



//------------------------------------------------------------
// rmnet_vnd_get_iflink @ 00114a50 size=12
// signature: undefined rmnet_vnd_get_iflink(void)
// callers: []
//------------------------------------------------------------

undefined4 rmnet_vnd_get_iflink(long param_1)

{
  return *(undefined4 *)(*(long *)(param_1 + 0xa48) + 0xd8);
}



//------------------------------------------------------------
// rmnet_stats_reset @ 00114a60 size=204
// signature: undefined rmnet_stats_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_stats_reset(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = rmnet_get_port(*(undefined8 *)(param_1 + 0xa48));
  if (lVar1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    *(undefined8 *)(lVar1 + 0xae0) = 0;
    *(undefined8 *)(lVar1 + 0xad8) = 0;
    *(undefined8 *)(lVar1 + 0xad0) = 0;
    *(undefined8 *)(lVar1 + 0xac8) = 0;
    *(undefined8 *)(lVar1 + 0xac0) = 0;
    *(undefined8 *)(lVar1 + 0xab8) = 0;
    *(undefined8 *)(lVar1 + 0xab0) = 0;
    *(undefined8 *)(lVar1 + 0xaa8) = 0;
    *(undefined8 *)(lVar1 + 0xaa0) = 0;
    *(undefined8 *)(lVar1 + 0xa98) = 0;
    *(undefined8 *)(lVar1 + 0xa90) = 0;
    *(undefined8 *)(lVar1 + 0xa88) = 0;
    *(undefined8 *)(lVar1 + 0xa80) = 0;
    *(undefined8 *)(lVar1 + 0xa78) = 0;
    *(undefined8 *)(lVar1 + 0xa70) = 0;
    *(undefined8 *)(lVar1 + 0xa68) = 0;
    *(undefined8 *)(lVar1 + 0xa60) = 0;
    *(undefined8 *)(lVar1 + 0xa58) = 0;
    *(undefined8 *)(lVar1 + 0xa50) = 0;
    *(undefined8 *)(lVar1 + 0xa48) = 0;
    *(undefined8 *)(lVar1 + 0xa40) = 0;
    *(undefined8 *)(lVar1 + 0xa38) = 0;
    *(undefined8 *)(lVar1 + 0xa30) = 0;
    *(undefined8 *)(lVar1 + 0xa28) = 0;
    *(undefined8 *)(lVar1 + 0xa20) = 0;
    *(undefined8 *)(lVar1 + 0xa18) = 0;
    *(undefined8 *)(lVar1 + 0xa10) = 0;
    *(undefined8 *)(lVar1 + 0xa08) = 0;
    *(undefined8 *)(lVar1 + 0xa00) = 0;
    *(undefined8 *)(lVar1 + 0x9f8) = 0;
    *(undefined8 *)(lVar1 + 0x9f0) = 0;
    memset((void *)(param_1 + 0xa60),0,0x1c0);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// rmnet_get_strings @ 00114b30 size=124
// signature: undefined rmnet_get_strings(void)
// callers: []
//------------------------------------------------------------

void rmnet_get_strings(undefined8 param_1,int param_2,void *param_3)

{
  if (param_2 == 1) {
    memcpy(param_3,"Checksum ok",0x700);
    memcpy((void *)((long)param_3 + 0x700),"MAP Cmd last version",0x3e0);
    memcpy((void *)((long)param_3 + 0xae0),"LL TX queues",0x200);
    memcpy((void *)((long)param_3 + 0xce0),"QMAP RX success",0xa0);
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_ethtool_stats @ 00114bb0 size=308
// signature: undefined rmnet_get_ethtool_stats(void)
// callers: []
//------------------------------------------------------------

void rmnet_get_ethtool_stats(long param_1,undefined8 param_2,void *param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 *puVar5;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = rmnet_get_port(*(undefined8 *)(param_1 + 0xa48));
  if ((param_3 != (void *)0x0) && (lVar4 != 0)) {
    puVar5 = (undefined8 *)rmnet_ll_get_stats();
    memcpy(param_3,(void *)(param_1 + 0xa60),0x1c0);
    memcpy((void *)((long)param_3 + 0x1c0),(void *)(lVar4 + 0x9f0),0xf8);
    uVar2 = puVar5[1];
    uVar1 = puVar5[2];
    uVar3 = puVar5[3];
    *(undefined8 *)((long)param_3 + 0x2b8) = *puVar5;
    *(undefined8 *)((long)param_3 + 0x2c0) = uVar2;
    *(undefined8 *)((long)param_3 + 0x2c8) = uVar1;
    *(undefined8 *)((long)param_3 + 0x2d0) = uVar3;
    uVar2 = puVar5[5];
    local_60 = 0;
    uVar1 = puVar5[6];
    uVar3 = puVar5[7];
    local_58 = 0;
    uStack_50 = 0;
    *(undefined8 *)((long)param_3 + 0x2d8) = puVar5[4];
    *(undefined8 *)((long)param_3 + 0x2e0) = uVar2;
    *(undefined8 *)((long)param_3 + 0x2e8) = uVar1;
    *(undefined8 *)((long)param_3 + 0x2f0) = uVar3;
    uVar2 = puVar5[9];
    local_48 = 0;
    uStack_40 = 0;
    uVar1 = puVar5[10];
    uVar3 = puVar5[0xb];
    *(undefined8 *)((long)param_3 + 0x2f8) = puVar5[8];
    *(undefined8 *)((long)param_3 + 0x300) = uVar2;
    *(undefined8 *)((long)param_3 + 0x308) = uVar1;
    *(undefined8 *)((long)param_3 + 0x310) = uVar3;
    uVar2 = puVar5[0xd];
    uVar1 = puVar5[0xe];
    uVar3 = puVar5[0xf];
    *(undefined8 *)((long)param_3 + 0x318) = puVar5[0xc];
    *(undefined8 *)((long)param_3 + 800) = uVar2;
    *(undefined8 *)((long)param_3 + 0x328) = uVar1;
    *(undefined8 *)((long)param_3 + 0x330) = uVar3;
    rmnet_ctl_get_stats(&local_60,5);
    *(undefined8 *)((long)param_3 + 0x340) = local_58;
    *(undefined8 *)((long)param_3 + 0x348) = uStack_50;
    *(undefined8 *)((long)param_3 + 0x338) = local_60;
    *(undefined8 *)((long)param_3 + 0x350) = local_48;
    *(undefined8 *)((long)param_3 + 0x358) = uStack_40;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_get_sset_count @ 00114ce8 size=20
// signature: undefined rmnet_get_sset_count(void)
// callers: []
//------------------------------------------------------------

undefined4 rmnet_get_sset_count(undefined8 param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0x6c;
  if (param_2 != 1) {
    uVar1 = 0xffffffa1;
  }
  return uVar1;
}



//------------------------------------------------------------
// dfc_qmap_cmd_handler @ 00114d6c size=1084
// signature: undefined dfc_qmap_cmd_handler(void)
// callers: [rmnet_qmap_cmd_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 dfc_qmap_cmd_handler(long param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  uint uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  undefined4 uVar9;
  long lVar10;
  
  puVar8 = qmap_dfc_data;
  lVar10 = *(long *)(param_1 + 0xe0);
  cVar2 = *(char *)(lVar10 + 4);
  bVar1 = *(byte *)(lVar10 + 5) & 3;
  if (cVar2 == '\f') {
    if (bVar1 != 1) {
      return 0xffffffff;
    }
  }
  else if ((*(byte *)(lVar10 + 5) & 3) != 0) {
    if (bVar1 != 1) {
      return 0xffffffff;
    }
    if (cVar2 == '\n') {
      dfc_config_acked = 1;
      return 0xffffffff;
    }
    return 0xffffffff;
  }
  if ((qmap_dfc_data != (undefined8 *)0x0) && (*(int *)(qmap_dfc_data + 0x3d) == 0)) {
    if ((dfc_config_acked & 1) == 0) {
      dfc_qmap_send_config(qmap_dfc_data);
      cVar2 = *(char *)(lVar10 + 4);
      dfc_config_acked = 1;
    }
    if (cVar2 == '\r') {
      if (*(uint *)(param_1 + 0x70) < 0x18) {
        return 3;
      }
      lVar10 = *(long *)(param_1 + 0xe0);
      uVar3 = *(undefined1 *)(lVar10 + 0xe);
      uVar4 = *(ushort *)(lVar10 + 0x12);
      uVar5 = *(uint *)(lVar10 + 8);
      lVar10 = rmnet_get_rmnet_dev(*puVar8,*(undefined1 *)(lVar10 + 1));
      if ((lVar10 == 0) || (lVar10 = rmnet_get_qos_pt(), lVar10 == 0)) {
        return 1;
      }
      _raw_spin_lock_bh(lVar10 + 0x14c);
      lVar6 = qmi_rmnet_get_bearer_map(lVar10,uVar3);
      if (lVar6 == 0) {
        uVar9 = 1;
      }
      else if ((*(ushort *)(lVar6 + 0x28) == (ushort)(uVar4 >> 8 | uVar4 << 8)) &&
              (*(int *)(lVar6 + 0x18) != 0)) {
        uVar5 = (uVar5 & 0xff00ff00) >> 8 | (uVar5 & 0xff00ff) << 8;
        uVar9 = 0xffffffff;
        *(undefined1 *)(lVar6 + 0x22) = 1;
        *(uint *)(lVar6 + 0x38) = uVar5 >> 0x10 | uVar5 << 0x10;
      }
      else {
        uVar9 = 0xffffffff;
        lVar7 = __alloc_skb(0x1c,0xa20,0,0xffffffff);
        if (lVar7 != 0) {
          puVar8 = (undefined8 *)skb_put(lVar7,0x1c);
          *puVar8 = 0;
          puVar8[1] = 0;
          puVar8[2] = 0;
          *(undefined4 *)(puVar8 + 3) = 0;
          *(undefined1 *)puVar8 = 0xc0;
          uVar3 = *(undefined1 *)(lVar10 + 0x10);
          *(uint *)((long)puVar8 + 0xc) = uVar5;
          *(undefined4 *)((long)puVar8 + 2) = 0x41400;
          *(undefined2 *)(puVar8 + 1) = 0x10d;
          *(undefined1 *)((long)puVar8 + 1) = uVar3;
          *(undefined1 *)(puVar8 + 2) = 1;
          uVar3 = *(undefined1 *)(lVar6 + 0x10);
          *(ushort *)((long)puVar8 + 0x16) = uVar4;
          *(undefined1 *)((long)puVar8 + 0x12) = uVar3;
          rmnet_qmap_send(lVar7,*(undefined1 *)(lVar6 + 0x90),1);
        }
      }
      _raw_spin_unlock_bh(lVar10 + 0x14c);
      return uVar9;
    }
    if (cVar2 != '\f') {
      if (cVar2 != '\v') {
        uVar9 = 2;
        if ((*(byte *)(lVar10 + 5) & 3) != 0) {
          uVar9 = 0xffffffff;
        }
        return uVar9;
      }
      if (*(uint *)(param_1 + 0x70) < 0x20) {
        uVar9 = 3;
      }
      else {
        lVar10 = *(long *)(param_1 + 0xe0);
        if ((*(byte *)(lVar10 + 0x11) & 1) == 0) {
          memset(&qmap_flow_ind,0,0x308);
          qmap_flow_ind = 0x101;
          DAT_00128b24 = *(byte *)(lVar10 + 0x13) >> 4 & 1;
          DAT_00128b01 = *(undefined1 *)(lVar10 + 1);
          DAT_00128b02 = *(undefined1 *)(lVar10 + 0x12);
          uVar5 = (*(uint *)(lVar10 + 0x14) & 0xff00ff00) >> 8 |
                  (*(uint *)(lVar10 + 0x14) & 0xff00ff) << 8;
          DAT_00128b04 = uVar5 >> 0x10 | uVar5 << 0x10;
          DAT_00128b08 = *(ushort *)(lVar10 + 0xe) >> 8 | *(ushort *)(lVar10 + 0xe) << 8;
          if ((*(byte *)(lVar10 + 0x11) >> 2 & 1) != 0) {
            DAT_00128b1c = 1;
            uVar5 = (*(uint *)(lVar10 + 0x18) & 0xff00ff00) >> 8 |
                    (*(uint *)(lVar10 + 0x18) & 0xff00ff) << 8;
            DAT_00128b20 = uVar5 >> 0x10 | uVar5 << 0x10;
          }
          if ((*(byte *)(lVar10 + 0x13) & 1) != 0) {
            DAT_00128d82 = 0x101;
            DAT_00128d85 = *(undefined1 *)(lVar10 + 1);
            DAT_00128d86 = *(undefined1 *)(lVar10 + 0x12);
            DAT_00128d88 = 1;
          }
          dfc_do_burst_flow_control(puVar8,&qmap_flow_ind,0);
        }
        else {
          _DAT_00128af8 = 0;
          _DAT_00128ae8 = 0;
          _DAT_00128af0 = 0;
          _DAT_00128ad8 = 0;
          _DAT_00128ae0 = 0;
          _DAT_00128ac8 = 0;
          _DAT_00128ad0 = 0;
          _DAT_00128ab8 = 0;
          _DAT_00128ac0 = 0;
          _DAT_00128aa8 = 0;
          _DAT_00128ab0 = 0;
          _DAT_00128a98 = 0;
          _DAT_00128aa0 = 0;
          _DAT_00128a88 = 0;
          _DAT_00128a90 = 0;
          DAT_00128a80 = 0;
          _qmap_tx_ind = CONCAT15(*(undefined1 *)(lVar10 + 1),0x10100);
          _qmap_tx_ind = CONCAT71(CONCAT16(*(undefined1 *)(lVar10 + 0x12),_qmap_tx_ind) >> 8,
                                  *(byte *)(lVar10 + 0x11) >> 1) & 0xffffffffffff01;
          dfc_handle_tx_link_status_ind(puVar8);
        }
        uVar9 = 1;
      }
      qmi_rmnet_set_dl_msg_active(*puVar8);
      return uVar9;
    }
    if ((0x1b < *(uint *)(param_1 + 0x70)) &&
       (lVar10 = *(long *)(param_1 + 0xe0), (*(ushort *)(lVar10 + 0xe) >> 8 & 1) == 0)) {
      memset(&qmap_flow_ind,0,0x308);
      DAT_00128b02 = *(undefined1 *)(lVar10 + 0xd);
      qmap_flow_ind = 0x101;
      uVar5 = (*(uint *)(lVar10 + 0x10) & 0xff00ff00) >> 8 |
              (*(uint *)(lVar10 + 0x10) & 0xff00ff) << 8;
      DAT_00128b04 = uVar5 >> 0x10 | uVar5 << 0x10;
      DAT_00128b01 = *(undefined1 *)(lVar10 + 1);
      uVar4 = *(ushort *)(lVar10 + 0xe);
      DAT_00128b08 = 0xffff;
      if ((uVar4 >> 1 & 1) != 0) {
        DAT_00128b1c = 1;
        uVar5 = (*(uint *)(lVar10 + 0x14) & 0xff00ff00) >> 8 |
                (*(uint *)(lVar10 + 0x14) & 0xff00ff) << 8;
        DAT_00128b20 = uVar5 >> 0x10 | uVar5 << 0x10;
        uVar4 = *(ushort *)(lVar10 + 0xe);
      }
      if ((uVar4 & 1) != 0) {
        DAT_00128d82 = 0x101;
        DAT_00128d85 = *(undefined1 *)(lVar10 + 1);
        DAT_00128d86 = *(undefined1 *)(lVar10 + 0xd);
        DAT_00128d88 = 1;
      }
      dfc_do_burst_flow_control(puVar8,&qmap_flow_ind,1);
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// dfc_qmap_send_config @ 001151a8 size=196
// signature: undefined dfc_qmap_send_config(void)
// callers: [dfc_qmap_cmd_handler, dfc_qmap_client_init]
//------------------------------------------------------------

void dfc_qmap_send_config(long param_1)

{
  uint uVar1;
  long lVar2;
  undefined4 *puVar3;
  
  lVar2 = __alloc_skb(0x1c,0xa20,0,0xffffffff);
  if (lVar2 != 0) {
    *(undefined2 *)(lVar2 + 0xb4) = 0xf900;
    puVar3 = (undefined4 *)skb_put(lVar2,0x1c);
    *(undefined8 *)(puVar3 + 1) = 0;
    *(undefined8 *)(puVar3 + 3) = 0;
    *(undefined8 *)(puVar3 + 5) = 0;
    *puVar3 = 0x18000080;
    *(undefined1 *)(puVar3 + 1) = 10;
    uVar1 = rmnet_qmap_next_txid();
    uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    puVar3[2] = uVar1 >> 0x10 | uVar1 << 0x10;
    *(undefined2 *)(puVar3 + 3) = 0xb01;
    *(byte *)((long)puVar3 + 0xf) = *(byte *)((long)puVar3 + 0xf) | 1;
    uVar1 = (*(uint *)(param_1 + 0x198) & 0xff00ff00) >> 8 |
            (*(uint *)(param_1 + 0x198) & 0xff00ff) << 8;
    puVar3[4] = uVar1 >> 0x10 | uVar1 << 0x10;
    uVar1 = (*(uint *)(param_1 + 0x19c) & 0xff00ff00) >> 8 |
            (*(uint *)(param_1 + 0x19c) & 0xff00ff) << 8;
    puVar3[5] = uVar1 >> 0x10 | uVar1 << 0x10;
    rmnet_qmap_send(lVar2,0xff,0);
  }
  return;
}



//------------------------------------------------------------
// dfc_qmap_set_powersave @ 00115270 size=356
// signature: undefined dfc_qmap_set_powersave(void)
// callers: [qmi_rmnet_check_stats_2, qmi_rmnet_pm_notify_cb]
//------------------------------------------------------------

undefined8 dfc_qmap_set_powersave(ulong param_1,byte param_2,void *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  
  __rcu_read_lock(param_1,(uint)param_1 & 0xff);
  if (qmap_dfc_data == 0) {
    __rcu_read_unlock();
    uVar6 = 0xffffffea;
  }
  else {
    uVar1 = *(uint *)(qmap_dfc_data + 0x198);
    uVar2 = *(uint *)(qmap_dfc_data + 0x19c);
    __rcu_read_unlock();
    lVar4 = __alloc_skb(0x3c,0xa20,0,0xffffffff);
    if (lVar4 == 0) {
      uVar6 = 0xfffffff4;
    }
    else {
      *(undefined2 *)(lVar4 + 0xb4) = 0xf900;
      puVar5 = (undefined4 *)skb_put(lVar4,0x3c);
      *(undefined8 *)(puVar5 + 1) = 0;
      *(undefined8 *)(puVar5 + 3) = 0;
      *(undefined8 *)(puVar5 + 5) = 0;
      *(undefined8 *)(puVar5 + 7) = 0;
      *(undefined8 *)(puVar5 + 9) = 0;
      *(undefined8 *)(puVar5 + 0xb) = 0;
      *(undefined8 *)(puVar5 + 0xd) = 0;
      *puVar5 = 0x38000080;
      *(undefined1 *)(puVar5 + 1) = 0xe;
      uVar3 = rmnet_qmap_next_txid();
      uVar3 = (uVar3 & 0xff00ff00) >> 8 | (uVar3 & 0xff00ff) << 8;
      puVar5[2] = uVar3 >> 0x10 | uVar3 << 0x10;
      *(undefined1 *)(puVar5 + 3) = 3;
      *(byte *)((long)puVar5 + 0xf) = *(byte *)((long)puVar5 + 0xf) & 0xfe | (param_1 & 0xff) != 0;
      if (((param_1 & 0xff) != 0) && (param_2 != 0)) {
        if (0x20 < param_2) {
          param_2 = 0x20;
        }
        *(byte *)(puVar5 + 6) = param_2;
        *(byte *)((long)puVar5 + 0xd) = *(byte *)((long)puVar5 + 0xd) | 3;
        memcpy((void *)((long)puVar5 + 0x19),param_3,(ulong)param_2);
      }
      uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      puVar5[4] = uVar1 >> 0x10 | uVar1 << 0x10;
      puVar5[5] = uVar2 >> 0x10 | uVar2 << 0x10;
      uVar6 = rmnet_qmap_send(lVar4,0xff,0);
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// dfc_qmap_send_ack @ 0011543c size=368
// signature: undefined dfc_qmap_send_ack(void)
// callers: [dfc_send_ack, dfc_do_burst_flow_control]
//------------------------------------------------------------

void dfc_qmap_send_ack(long param_1,undefined4 param_2,uint param_3,char param_4)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined8 *puVar4;
  undefined1 *puVar5;
  undefined1 uVar6;
  undefined8 uVar7;
  
  if (param_4 == '\x02') {
    uVar6 = *(undefined1 *)(param_1 + 0x10);
    lVar3 = __alloc_skb(0x14,0xa20,0,0xffffffff);
    if (lVar3 == 0) {
      return;
    }
    *(undefined2 *)(lVar3 + 0xb4) = 0xf900;
    puVar5 = (undefined1 *)skb_put(lVar3,0x14);
    *(undefined8 *)(puVar5 + 4) = 0;
    *(undefined8 *)(puVar5 + 0xc) = 0;
    *puVar5 = 0x80;
    puVar5[1] = uVar6;
    *(undefined2 *)(puVar5 + 2) = 0x1000;
    puVar5[4] = 0xc;
    uVar1 = rmnet_qmap_next_txid();
    uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    uVar6 = 0xff;
    uVar7 = 0;
    puVar5[0xe] = (char)param_2;
    puVar5[0xc] = 1;
    *(uint *)(puVar5 + 8) = uVar1 >> 0x10 | uVar1 << 0x10;
  }
  else {
    if (param_4 != '\x01') {
      return;
    }
    lVar2 = qmi_rmnet_get_bearer_map(param_1,param_2);
    if (lVar2 == 0) {
      return;
    }
    uVar1 = *(uint *)(lVar2 + 0x38);
    lVar3 = __alloc_skb(0x1c,0xa20,0,0xffffffff);
    if (lVar3 == 0) {
      return;
    }
    puVar4 = (undefined8 *)skb_put(lVar3,0x1c);
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    uVar7 = 1;
    *(undefined1 *)puVar4 = 0xc0;
    *(undefined4 *)(puVar4 + 3) = 0;
    uVar6 = *(undefined1 *)(param_1 + 0x10);
    *(undefined4 *)((long)puVar4 + 2) = 0x41400;
    uVar1 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
    *(undefined2 *)(puVar4 + 1) = 0x10d;
    *(undefined1 *)((long)puVar4 + 1) = uVar6;
    *(uint *)((long)puVar4 + 0xc) = uVar1 >> 0x10 | uVar1 << 0x10;
    *(undefined1 *)(puVar4 + 2) = 1;
    uVar6 = *(undefined1 *)(lVar2 + 0x10);
    *(ushort *)((long)puVar4 + 0x16) =
         (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
    *(undefined1 *)((long)puVar4 + 0x12) = uVar6;
    uVar6 = *(undefined1 *)(lVar2 + 0x90);
  }
  rmnet_qmap_send(lVar3,uVar6,uVar7);
  return;
}



//------------------------------------------------------------
// dfc_qmap_client_init @ 001155b0 size=300
// signature: undefined dfc_qmap_client_init(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 dfc_qmap_client_init(long param_1,uint param_2,undefined8 *param_3,long param_4)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  
  uVar4 = 0xffffffea;
  if (((param_1 != 0) && (param_4 != 0)) && (qmap_dfc_data == (long *)0x0)) {
    plVar5 = (long *)kmalloc_trace(_netdev_rx_handler_register,0xdc0,0x1f0);
    if (plVar5 == (long *)0x0) {
      uVar4 = 0xfffffff4;
    }
    else {
      uVar4 = *param_3;
      uVar1 = *(undefined4 *)(param_3 + 1);
      *plVar5 = param_1;
      *(uint *)((long)plVar5 + 0x1e4) = param_2;
      *(undefined8 *)((long)plVar5 + 0x194) = uVar4;
      *(undefined4 *)((long)plVar5 + 0x19c) = uVar1;
      if (1 < param_2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1156dc);
        (*pcVar2)();
      }
      *(long **)(param_4 + (ulong)param_2 * 8 + 0x18) = plVar5;
      qmap_dfc_data = plVar5;
      iVar3 = rmnet_qmap_init(param_1);
      if (iVar3 < 0) {
        qmap_dfc_data = (long *)0x0;
        synchronize_rcu();
        kfree(plVar5);
        uVar4 = 0xfffffff2;
      }
      else {
        trace_dfc_client_state_up
                  (*(undefined4 *)((long)plVar5 + 0x1e4),*(undefined4 *)((long)plVar5 + 0x194),
                   (int)plVar5[0x33],*(undefined4 *)((long)plVar5 + 0x19c));
        _printk(&DAT_00120fac);
        if (*(int *)(param_4 + 0x4c) == 0) {
          dfc_config_acked = 0;
          dfc_qmap_send_config(plVar5);
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
          dfc_config_acked = 1;
        }
      }
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// trace_dfc_client_state_up @ 001156dc size=36
// signature: undefined trace_dfc_client_state_up(void)
// callers: [dfc_qmap_client_init]
//------------------------------------------------------------

void trace_dfc_client_state_up(void)

{
  return;
}



//------------------------------------------------------------
// dfc_qmap_client_exit @ 00115778 size=116
// signature: undefined dfc_qmap_client_exit(void)
// callers: [__qmi_rmnet_delete_client]
//------------------------------------------------------------

void dfc_qmap_client_exit(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00120e98,"dfc_qmap_client_exit");
  }
  else {
    rmnet_qmap_exit(param_1,*(undefined4 *)(param_1 + 0x1e4));
    *(undefined4 *)(param_1 + 0x1e8) = 1;
    qmap_dfc_data = 0;
    synchronize_rcu();
    kfree(param_1);
    _printk(&DAT_00121596);
  }
  return;
}



//------------------------------------------------------------
// __traceiter_dfc_qmi_tc @ 00115864 size=124
// signature: undefined __traceiter_dfc_qmi_tc(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_dfc_qmi_tc(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00129948;
  plVar2 = DAT_00129948;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x19f08d48) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1158bc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_flow_ind @ 001158e4 size=196
// signature: undefined __traceiter_dfc_flow_ind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_flow_ind
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
          undefined4 param_9)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129990;
  plVar2 = _DAT_00129990;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4e09f9f9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115974);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_flow_check @ 001159ac size=148
// signature: undefined __traceiter_dfc_flow_check(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_flow_check
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_001299d8;
  plVar2 = _DAT_001299d8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x63a78a18) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115a18);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_flow_info @ 00115a44 size=164
// signature: undefined __traceiter_dfc_flow_info(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_flow_info
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129a20;
  plVar2 = _DAT_00129a20;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x2a661dd9) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115abc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_client_state_up @ 00115aec size=140
// signature: undefined __traceiter_dfc_client_state_up(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_client_state_up
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129a68;
  plVar2 = _DAT_00129a68;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x2900707a) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115b50);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_client_state_down @ 00115b7c size=116
// signature: undefined __traceiter_dfc_client_state_down(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_client_state_down(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129ab0;
  plVar2 = _DAT_00129ab0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x5885f495) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115bcc);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_qmap_cmd @ 00115bf4 size=148
// signature: undefined __traceiter_dfc_qmap_cmd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_qmap_cmd
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129af8;
  plVar2 = _DAT_00129af8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x235a83cc) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115c60);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_tx_link_status_ind @ 00115c8c size=148
// signature: undefined __traceiter_dfc_tx_link_status_ind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_tx_link_status_ind
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129b40;
  plVar2 = _DAT_00129b40;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x67082951) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115cf8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_qmap @ 00115d24 size=140
// signature: undefined __traceiter_dfc_qmap(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_qmap
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,uint param_4,undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  
  if (_DAT_00129b88 != (long *)0x0) {
    plVar2 = _DAT_00129b88;
    do {
      if (*(int *)((code *)*plVar2 + -4) != -0x1a801ebe) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115d88);
        (*pcVar1)();
      }
      (*(code *)*plVar2)(plVar2[1],param_2,param_3,param_4 & 1,param_5);
      plVar2 = plVar2 + 3;
    } while (*plVar2 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_dfc_adjust_grant @ 00115db4 size=164
// signature: undefined __traceiter_dfc_adjust_grant(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_adjust_grant
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129bd0;
  plVar2 = _DAT_00129bd0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x6e41d47c) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5,param_6,param_7);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115e2c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_watchdog @ 00115e5c size=124
// signature: undefined __traceiter_dfc_watchdog(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_watchdog
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129c18;
  plVar2 = _DAT_00129c18;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != 0x71ebd069) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115eb4);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_ll_switch @ 00115edc size=140
// signature: undefined __traceiter_dfc_ll_switch(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_dfc_ll_switch
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
          undefined8 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129c60;
  plVar2 = _DAT_00129c60;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x14215a7c) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115f40);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_set_powersave_mode @ 00115f6c size=100
// signature: undefined __traceiter_dfc_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_dfc_set_powersave_mode(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129ca8;
  plVar2 = _DAT_00129ca8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x115fb0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_dfc_pm_event @ 00115fd4 size=100
// signature: undefined __traceiter_dfc_pm_event(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_dfc_pm_event(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129cf0;
  plVar2 = _DAT_00129cf0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x116018);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_qmi_tc @ 0011603c size=252
// signature: undefined trace_event_raw_event_dfc_qmi_tc(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_qmi_tc
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x14);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x14;
      strcpy((char *)(lVar3 + 0x14),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_qmi_tc @ 0011613c size=336
// signature: undefined perf_trace_dfc_qmi_tc(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_qmi_tc(long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x1c;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x10014;
      strcpy((char *)(lVar5 + 0x14),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_flow_ind @ 00116290 size=248
// signature: undefined trace_event_raw_event_dfc_flow_ind(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_flow_ind
               (long param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined1 param_8,
               undefined4 param_9)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_88,param_1,0x20), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined1 *)(lVar1 + 0x10) = param_4;
    *(undefined1 *)(lVar1 + 0x11) = param_5;
    *(undefined4 *)(lVar1 + 0x14) = param_6;
    *(undefined2 *)(lVar1 + 0x18) = param_7;
    *(undefined1 *)(lVar1 + 0x1a) = param_8;
    *(undefined4 *)(lVar1 + 0x1c) = param_9;
    trace_event_buffer_commit(&local_88);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_flow_ind @ 0011638c size=312
// signature: undefined perf_trace_dfc_flow_ind(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_flow_ind
               (long param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined1 param_8,
               undefined4 param_9)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x24,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined1 *)(lVar3 + 0x10) = param_4;
    *(undefined1 *)(lVar3 + 0x11) = param_5;
    *(undefined4 *)(lVar3 + 0x14) = param_6;
    *(undefined2 *)(lVar3 + 0x18) = param_7;
    *(undefined1 *)(lVar3 + 0x1a) = param_8;
    *(undefined4 *)(lVar3 + 0x1c) = param_9;
    perf_trace_run_bpf_submit(lVar3,0x24,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_flow_check @ 001164c8 size=276
// signature: undefined trace_event_raw_event_dfc_flow_check(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_flow_check
               (long param_1,char *param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x1c);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x1c;
      strcpy((char *)(lVar3 + 0x1c),__s);
      *(undefined1 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_flow_check @ 001165e0 size=352
// signature: undefined perf_trace_dfc_flow_check(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_flow_check
               (long param_1,char *param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [8];
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_78 = param_6;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x24;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x1001c;
      strcpy((char *)(lVar5 + 0x1c),__s);
      *(undefined1 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_78;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_flow_info @ 00116744 size=280
// signature: undefined trace_event_raw_event_dfc_flow_info(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_flow_info
               (long param_1,char *param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)iVar1 + 0x20);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x20;
      strcpy((char *)(lVar3 + 0x20),__s);
      *(undefined1 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      *(undefined4 *)(lVar3 + 0x14) = param_5;
      *(undefined4 *)(lVar3 + 0x18) = param_6;
      *(undefined4 *)(lVar3 + 0x1c) = param_7;
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_flow_info @ 00116860 size=360
// signature: undefined perf_trace_dfc_flow_info(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_flow_info
               (long param_1,char *param_2,undefined1 param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  char *__s;
  ulong uVar2;
  int iVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  local_7c = param_6;
  local_78 = param_7;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar1 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)sVar4 + 0x2cU & 0xfffffff8) - 4;
    lVar5 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(int *)(lVar5 + 8) = (int)sVar4 * 0x10000 + 0x10020;
      strcpy((char *)(lVar5 + 0x20),__s);
      *(undefined1 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      *(undefined4 *)(lVar5 + 0x14) = param_5;
      *(undefined4 *)(lVar5 + 0x18) = local_7c;
      *(undefined4 *)(lVar5 + 0x1c) = local_78;
      perf_trace_run_bpf_submit(lVar5,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_client_state_up @ 001169cc size=196
// signature: undefined trace_event_raw_event_dfc_client_state_up(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_client_state_up
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_client_state_up @ 00116a94 size=268
// signature: undefined perf_trace_dfc_client_state_up(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_client_state_up
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_client_state_down @ 00116ba4 size=172
// signature: undefined trace_event_raw_event_dfc_client_state_down(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_client_state_down(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0x10), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_client_state_down @ 00116c54 size=248
// signature: undefined perf_trace_dfc_client_state_down(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_client_state_down(long param_1,undefined4 param_2,undefined4 param_3)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_qmap_cmd @ 00116d50 size=220
// signature: undefined trace_event_raw_event_dfc_qmap_cmd(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_qmap_cmd
               (long param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined1 param_5,undefined4 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x14), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined1 *)(lVar1 + 9) = param_3;
    *(undefined2 *)(lVar1 + 10) = param_4;
    *(undefined1 *)(lVar1 + 0xc) = param_5;
    *(undefined4 *)(lVar1 + 0x10) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_qmap_cmd @ 00116e30 size=284
// signature: undefined perf_trace_dfc_qmap_cmd(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_qmap_cmd
               (long param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined1 param_5,undefined4 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined1 *)(lVar3 + 9) = param_3;
    *(undefined2 *)(lVar3 + 10) = param_4;
    *(undefined1 *)(lVar3 + 0xc) = param_5;
    *(undefined4 *)(lVar3 + 0x10) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x14,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_tx_link_status_ind @ 00116f50 size=216
// signature: undefined trace_event_raw_event_dfc_tx_link_status_ind(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_tx_link_status_ind
               (long param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined1 *)(lVar1 + 0x10) = param_4;
    *(undefined1 *)(lVar1 + 0x11) = param_5;
    *(undefined1 *)(lVar1 + 0x12) = param_6;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_tx_link_status_ind @ 0011702c size=280
// signature: undefined perf_trace_dfc_tx_link_status_ind(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_tx_link_status_ind
               (long param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined1 *)(lVar3 + 0x10) = param_4;
    *(undefined1 *)(lVar3 + 0x11) = param_5;
    *(undefined1 *)(lVar3 + 0x12) = param_6;
    perf_trace_run_bpf_submit(lVar3,0x14,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_qmap @ 00117148 size=248
// signature: undefined trace_event_raw_event_dfc_qmap(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_qmap
               (long param_1,void *param_2,size_t param_3,byte param_4,undefined1 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) {
    lVar1 = trace_event_buffer_reserve(&local_78,param_1,(long)(int)param_3 + 0x20);
    if (lVar1 != 0) {
      *(size_t *)(lVar1 + 0x10) = param_3;
      *(byte *)(lVar1 + 8) = param_4 & 1;
      *(uint *)(lVar1 + 0x18) = (int)param_3 << 0x10 | 0x1d;
      memcpy((void *)(lVar1 + 0x1d),param_2,param_3);
      *(undefined1 *)(lVar1 + 0x1c) = param_5;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_qmap @ 00117244 size=332
// signature: undefined perf_trace_dfc_qmap(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_qmap(long param_1,void *param_2,size_t param_3,byte param_4,undefined1 param_5)

{
  long *plVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar4 = tpidr_el1;
  plVar1 = (long *)(lVar4 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) {
    iVar3 = ((int)param_3 + 0x2bU & 0xfffffff8) - 4;
    lVar4 = perf_trace_buf_alloc(iVar3,&local_70,&local_74);
    if (lVar4 != 0) {
      uVar2 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar2 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar2;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar4 + 0x18) = (int)param_3 << 0x10 | 0x1d;
      *(size_t *)(lVar4 + 0x10) = param_3;
      *(byte *)(lVar4 + 8) = param_4 & 1;
      memcpy((void *)(lVar4 + 0x1d),param_2,param_3);
      *(undefined1 *)(lVar4 + 0x1c) = param_5;
      perf_trace_run_bpf_submit(lVar4,iVar3,local_74,param_1,1,local_70,plVar1,0);
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_adjust_grant @ 00117394 size=220
// signature: undefined trace_event_raw_event_dfc_adjust_grant(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_adjust_grant
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_78,param_1,0x1c), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined1 *)(lVar1 + 9) = param_3;
    *(undefined4 *)(lVar1 + 0xc) = param_4;
    *(undefined4 *)(lVar1 + 0x10) = param_5;
    *(undefined4 *)(lVar1 + 0x14) = param_6;
    *(undefined4 *)(lVar1 + 0x18) = param_7;
    trace_event_buffer_commit(&local_78);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_adjust_grant @ 00117474 size=292
// signature: undefined perf_trace_dfc_adjust_grant(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_adjust_grant
               (long param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_70 = 0;
  local_74 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_70,&local_74), lVar3 != 0)) {
    *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_70 + 0xf8) = auStack_80;
    *(ulong *)(local_70 + 0x100) = uVar2;
    *(undefined8 *)(local_70 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined1 *)(lVar3 + 9) = param_3;
    *(undefined4 *)(lVar3 + 0xc) = param_4;
    *(undefined4 *)(lVar3 + 0x10) = param_5;
    *(undefined4 *)(lVar3 + 0x14) = param_6;
    *(undefined4 *)(lVar3 + 0x18) = param_7;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_74,param_1,1,local_70,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_watchdog @ 0011759c size=196
// signature: undefined trace_event_raw_event_dfc_watchdog(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_watchdog
               (long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0xc), lVar1 != 0)) {
    *(undefined1 *)(lVar1 + 8) = param_2;
    *(undefined1 *)(lVar1 + 9) = param_3;
    *(undefined1 *)(lVar1 + 10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_watchdog @ 00117664 size=260
// signature: undefined perf_trace_dfc_watchdog(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_watchdog(long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined1 *)(lVar3 + 8) = param_2;
    *(undefined1 *)(lVar3 + 9) = param_3;
    *(undefined1 *)(lVar3 + 10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0xc,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_ll_switch @ 0011776c size=308
// signature: undefined trace_event_raw_event_dfc_ll_switch(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_ll_switch
               (long param_1,char *param_2,undefined1 param_3,byte param_4,void *param_5)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_88,param_1,(long)(int)(iVar1 + (uint)param_4) + 0x14);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x14;
      *(uint *)(lVar3 + 0x10) = (int)sVar2 + 0x15U | (uint)param_4 << 0x10;
      strcpy((char *)(lVar3 + 0x14),__s);
      *(undefined1 *)(lVar3 + 0xc) = param_3;
      *(byte *)(lVar3 + 0xd) = param_4;
      memcpy((void *)(lVar3 + (ulong)*(ushort *)(lVar3 + 0x10)),param_5,(ulong)param_4);
      trace_event_buffer_commit(&local_88);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_ll_switch @ 001178a4 size=392
// signature: undefined perf_trace_dfc_ll_switch(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_ll_switch
               (long param_1,char *param_2,undefined4 param_3,byte param_4,void *param_5)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  int iVar4;
  size_t sVar5;
  long lVar6;
  ulong unaff_x30;
  undefined1 auStack_90 [12];
  undefined4 local_84;
  void *local_80;
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_70 = 0;
  local_74 = 0;
  local_84 = param_3;
  local_80 = param_5;
  sVar5 = strlen(__s);
  lVar6 = tpidr_el1;
  plVar2 = (long *)(lVar6 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = (int)sVar5 + 1;
    iVar4 = ((uint)param_4 + iVar1 + 0x1f & 0xfffffff8) - 4;
    lVar6 = perf_trace_buf_alloc(iVar4,&local_70,&local_74);
    if (lVar6 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_90 + 0x30;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_90;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar6 + 8) = iVar1 * 0x10000 | 0x14;
      *(uint *)(lVar6 + 0x10) = (int)sVar5 + 0x15U | (uint)param_4 << 0x10;
      strcpy((char *)(lVar6 + 0x14),__s);
      *(byte *)(lVar6 + 0xd) = param_4;
      *(char *)(lVar6 + 0xc) = (char)local_84;
      memcpy((void *)(lVar6 + (ulong)*(ushort *)(lVar6 + 0x10)),local_80,(ulong)param_4);
      perf_trace_run_bpf_submit(lVar6,iVar4,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_set_powersave_mode @ 00117a30 size=168
// signature: undefined trace_event_raw_event_dfc_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_set_powersave_mode(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_set_powersave_mode @ 00117adc size=236
// signature: undefined perf_trace_dfc_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_set_powersave_mode(long param_1,undefined4 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_dfc_pm_event @ 00117bcc size=168
// signature: undefined trace_event_raw_event_dfc_pm_event(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_dfc_pm_event(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_dfc_pm_event @ 00117c78 size=236
// signature: undefined perf_trace_dfc_pm_event(void)
// callers: []
//------------------------------------------------------------

void perf_trace_dfc_pm_event(long param_1,undefined4 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_qmi_tc @ 00117d68 size=36
// signature: undefined __bpf_trace_dfc_qmi_tc(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_qmi_tc
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_flow_ind @ 00117d90 size=72
// signature: undefined __bpf_trace_dfc_flow_ind(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_flow_ind
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined4 param_6,undefined2 param_7,undefined1 param_8,
               undefined4 param_9)

{
  bpf_trace_run8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_flow_check @ 00117ddc size=44
// signature: undefined __bpf_trace_dfc_flow_check(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_flow_check
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_flow_info @ 00117e0c size=48
// signature: undefined __bpf_trace_dfc_flow_info(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_flow_info
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_client_state_up @ 00117e40 size=44
// signature: undefined __bpf_trace_dfc_client_state_up(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_client_state_up
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_client_state_down @ 00117e70 size=36
// signature: undefined __bpf_trace_dfc_client_state_down(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_client_state_down(undefined8 param_1,undefined4 param_2,undefined4 param_3)

{
  bpf_trace_run2(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_qmap_cmd @ 00117e98 size=48
// signature: undefined __bpf_trace_dfc_qmap_cmd(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_qmap_cmd
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined2 param_4,
               undefined1 param_5,undefined4 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_tx_link_status_ind @ 00117ecc size=48
// signature: undefined __bpf_trace_dfc_tx_link_status_ind(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_tx_link_status_ind
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,
               undefined1 param_5,undefined1 param_6)

{
  bpf_trace_run5(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_qmap @ 00117f00 size=36
// signature: undefined __bpf_trace_dfc_qmap(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_qmap(void)

{
  bpf_trace_run4();
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_adjust_grant @ 00117f28 size=52
// signature: undefined __bpf_trace_dfc_adjust_grant(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_adjust_grant
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  bpf_trace_run6(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_watchdog @ 00117f60 size=40
// signature: undefined __bpf_trace_dfc_watchdog(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_watchdog
               (undefined8 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_ll_switch @ 00117f8c size=36
// signature: undefined __bpf_trace_dfc_ll_switch(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_ll_switch
               (undefined8 param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_set_powersave_mode @ 00117fb4 size=32
// signature: undefined __bpf_trace_dfc_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_set_powersave_mode(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run1(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_dfc_pm_event @ 00117fd8 size=32
// signature: undefined __bpf_trace_dfc_pm_event(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_dfc_pm_event(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run1(param_1,param_2);
  return;
}



//------------------------------------------------------------
// dfc_bearer_flow_ctl @ 00117ffc size=152
// signature: undefined dfc_bearer_flow_ctl(void)
// callers: [qmi_rmnet_watchdog_fn, qmi_rmnet_enable_all_flows]
//------------------------------------------------------------

undefined8 dfc_bearer_flow_ctl(undefined8 param_1,long param_2,long param_3)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (*(int *)(param_2 + 0x40) != 0xff) {
    if (iVar1 == 0) {
      uVar2 = *(undefined1 *)(param_2 + 0x34);
    }
    else {
      uVar2 = 1;
    }
    qmi_rmnet_flow_control(param_1,*(int *)(param_2 + 0x40),uVar2);
  }
  qmi_rmnet_flow_control(param_1,*(undefined4 *)(param_2 + 0x3c),iVar1 != 0);
  if ((iVar1 == 0) && (*(char *)(param_2 + 0x22) != '\0')) {
    dfc_send_ack(param_1,*(undefined1 *)(param_2 + 0x10),*(undefined2 *)(param_2 + 0x20),
                 *(undefined1 *)(param_3 + 0x10),1);
  }
  return 0;
}



//------------------------------------------------------------
// dfc_send_ack @ 00118094 size=292
// signature: undefined dfc_send_ack(void)
// callers: [dfc_qmi_burst_check, dfc_handle_tx_link_status_ind, dfc_all_bearer_flow_ctl, dfc_do_burst_flow_control, dfc_bearer_flow_ctl]
//------------------------------------------------------------

void dfc_send_ack(undefined8 param_1,undefined4 param_2,uint param_3,undefined1 param_4,uint param_5
                 )

{
  uint uVar1;
  long lVar2;
  long lVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  
  lVar2 = rmnet_get_qos_pt();
  if (lVar2 != 0) {
    if (dfc_qmap == 0) {
      lVar3 = __alloc_skb(0x14,0xa20,0,0xffffffff);
      if (lVar3 != 0) {
        puVar4 = (undefined1 *)skb_put(lVar3,0x14);
        *(undefined8 *)(puVar4 + 4) = 0;
        *(undefined8 *)(puVar4 + 0xc) = 0;
        *puVar4 = 0x80;
        *(undefined2 *)(puVar4 + 2) = 0x1000;
        puVar4[1] = param_4;
        puVar4[4] = 4;
        puVar4[0x13] = (char)param_2;
        *(ushort *)(puVar4 + 0xe) =
             (ushort)(param_3 >> 8) & 0xff | (ushort)((param_3 & 0xff00ff) << 8);
        *(ushort *)(puVar4 + 0xc) = (ushort)((param_5 & 3) << 8) | 2;
        uVar1 = (*(uint *)(lVar2 + 0x148) & 0xff00ff00) >> 8 |
                (*(uint *)(lVar2 + 0x148) & 0xff00ff) << 8;
        *(uint *)(puVar4 + 8) = uVar1 >> 0x10 | uVar1 << 0x10;
        uVar5 = *(undefined8 *)(lVar2 + 0x18);
        *(undefined2 *)(lVar3 + 0xb4) = 0xf900;
        *(undefined8 *)(lVar3 + 0x10) = uVar5;
        *(int *)(lVar2 + 0x148) = *(int *)(lVar2 + 0x148) + 1;
        rmnet_map_tx_qmap_cmd(lVar3,0,1);
      }
    }
    else {
      dfc_qmap_send_ack(lVar2,param_2,param_3,param_5);
    }
  }
  return;
}



//------------------------------------------------------------
// dfc_do_burst_flow_control @ 00118268 size=1152
// signature: undefined dfc_do_burst_flow_control(void)
// callers: [dfc_qmi_query_flow, dfc_qmi_ind_work, dfc_qmap_cmd_handler]
//------------------------------------------------------------

void dfc_do_burst_flow_control(undefined8 *param_1,long param_2,uint param_3)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  undefined2 uVar4;
  undefined8 uVar5;
  bool bVar6;
  code *pcVar7;
  bool bVar8;
  undefined4 uVar9;
  long lVar10;
  int iVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  uint *puVar15;
  uint uVar16;
  ulong uVar17;
  long lVar18;
  undefined2 *puVar19;
  uint local_6c;
  
  if (*(char *)(param_2 + 0x284) == '\0') {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)(param_2 + 0x285);
  }
  __rcu_read_lock();
  if (*(char *)(param_2 + 1) != '\0') {
    uVar17 = 0;
    uVar5 = sp_el0;
    do {
      if (uVar17 == 0x11) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x118880);
        (*pcVar7)();
      }
      if (*(char *)(param_2 + 0x286) == '\0') {
        local_6c = 0;
      }
      else {
        uVar12 = (ulong)*(byte *)(param_2 + 0x287);
        if (uVar12 != 0) {
          lVar14 = param_2 + uVar17 * 0x28;
          puVar15 = (uint *)(param_2 + 0x28c);
          do {
            if ((*(char *)((long)puVar15 + -3) == *(char *)(lVar14 + 5)) &&
               (*(char *)((long)puVar15 + -2) == *(char *)(lVar14 + 6))) {
              local_6c = *puVar15;
              goto LAB_00118370;
            }
            puVar15 = puVar15 + 2;
            uVar12 = uVar12 - 1;
          } while (uVar12 != 0);
        }
        local_6c = 0;
      }
LAB_00118370:
      lVar18 = param_2 + uVar17 * 0x28;
      puVar19 = (undefined2 *)(lVar18 + 0xc);
      puVar15 = (uint *)(lVar18 + 8);
      lVar14 = rmnet_get_rmnet_dev(*param_1,*(undefined1 *)(lVar18 + 5));
      if (lVar14 == 0) break;
      lVar10 = rmnet_get_qos_pt();
      if (lVar10 != 0) {
        _raw_spin_lock_bh(lVar10 + 0x14c);
        uVar12 = qmi_rmnet_ignore_grant(*param_1);
        if ((uVar12 & 1) == 0) {
LAB_00118400:
          if (*(char *)(lVar18 + 6) == -1) {
            dfc_all_bearer_flow_ctl(lVar14,lVar10,cVar2,local_6c,param_2 + uVar17 * 0x28 + 4);
          }
          else {
            lVar13 = qmi_rmnet_get_bearer_map(lVar10);
            if ((lVar13 == 0) && ((param_3 & 1) == 0)) {
              if (*puVar15 == 0) goto LAB_001182e0;
              lVar13 = qmi_rmnet_get_bearer_noref(lVar10,*(char *)(lVar18 + 6));
            }
            if (lVar13 != 0) {
              if ((local_6c >> 1 & 1) == 0) {
                if (*(char *)(lVar13 + 0x35) != '\0') goto LAB_001182e0;
                cVar3 = *(char *)(lVar13 + 0x36);
              }
              else {
                *(bool *)(lVar13 + 0x35) = *puVar15 == 0;
                cVar3 = *(char *)(lVar13 + 0x36);
              }
              if ((cVar3 == '\0') || (*puVar15 == 0)) {
                if ((*(char *)(param_2 + uVar17 * 0x28 + 0x28) != '\0') &&
                   (*(char *)(lVar13 + 0x90) != '\x01')) {
                  *(undefined1 *)(lVar13 + 0x90) = 1;
                  *(undefined1 *)(lVar13 + 0x94) = 1;
                  if (*(uint *)(lVar13 + 0x3c) < 0x10) {
                    *(undefined1 *)(lVar10 + (ulong)*(uint *)(lVar13 + 0x3c) * 0x10 + 0x50) = 1;
                  }
                }
                if ((dfc_qmap == 0) || ((param_3 & 1) == 0)) {
                  uVar16 = *puVar15;
                  *(undefined4 *)(lVar13 + 0x2c) = 0;
LAB_001185c8:
                  iVar11 = *(int *)(lVar13 + 0x18);
                  if (iVar11 != 0) goto LAB_001185d4;
LAB_001185d0:
                  if (uVar16 == 0) goto LAB_001185d4;
LAB_001185f8:
                  bVar6 = true;
                }
                else {
                  if (*(char *)(param_2 + uVar17 * 0x28 + 0x20) != '\0') {
                    uVar16 = *(uint *)(param_2 + uVar17 * 0x28 + 0x24);
                    uVar1 = 0;
                    if (uVar16 <= *(uint *)(lVar13 + 0x2c)) {
                      uVar1 = *(uint *)(lVar13 + 0x2c) - uVar16;
                    }
                    *(uint *)(lVar13 + 0x2c) = uVar1;
                    uVar16 = 0;
                    if (uVar1 <= *puVar15) {
                      uVar16 = *puVar15 - uVar1;
                    }
                    goto LAB_001185c8;
                  }
                  uVar16 = *puVar15;
                  iVar11 = *(int *)(lVar13 + 0x18);
                  if (iVar11 == 0) goto LAB_001185d0;
LAB_001185d4:
                  if (((iVar11 != 0) && (uVar16 == 0)) ||
                     ((local_6c & 1) != (uint)*(byte *)(lVar13 + 0x34))) goto LAB_001185f8;
                  bVar6 = false;
                }
                if (dfc_qmap == 0) {
                  *(uint *)(lVar13 + 0x18) = uVar16;
LAB_00118684:
                  uVar9 = qmi_rmnet_grant_per(uVar16);
                  *(undefined4 *)(lVar13 + 0x1c) = uVar9;
                  qmi_rmnet_watchdog_remove(lVar13);
                }
                else {
                  bVar8 = true;
                  if (((cVar2 == '\0') && (*(char *)(lVar13 + 0x22) != '\0')) && (iVar11 != 0)) {
                    dfc_qmap_send_ack(lVar10,*(undefined1 *)(lVar13 + 0x10),
                                      *(undefined2 *)(lVar13 + 0x20),1);
                    bVar8 = dfc_qmap != 0;
                  }
                  *(uint *)(lVar13 + 0x18) = uVar16;
                  if (((!bVar8) || ((param_3 & 1) == 0)) || (*puVar15 / 5 <= uVar16))
                  goto LAB_00118684;
                  *(uint *)(lVar13 + 0x1c) = uVar16;
                  qmi_rmnet_watchdog_add(lVar13);
                }
                *(undefined2 *)(lVar13 + 0x20) = *puVar19;
                *(char *)(lVar13 + 0x22) = cVar2;
                *(byte *)(lVar13 + 0x34) = (byte)local_6c & 1;
                *(uint *)(lVar13 + 0x24) = *puVar15;
                uVar4 = *puVar19;
                *(uint *)(lVar13 + 0x30) = uVar16;
                *(undefined2 *)(lVar13 + 0x28) = uVar4;
                if (bVar6) {
                  iVar11 = *(int *)(lVar13 + 0x18);
                  if (*(int *)(lVar13 + 0x40) != 0xff) {
                    local_6c = local_6c & 1;
                    if (iVar11 != 0) {
                      local_6c = 1;
                    }
                    qmi_rmnet_flow_control(lVar14,*(int *)(lVar13 + 0x40),local_6c);
                  }
                  qmi_rmnet_flow_control(lVar14,*(undefined4 *)(lVar13 + 0x3c),iVar11 != 0);
                  if ((iVar11 == 0) && (*(char *)(lVar13 + 0x22) != '\0')) {
                    dfc_send_ack(lVar14,*(undefined1 *)(lVar13 + 0x10),
                                 *(undefined2 *)(lVar13 + 0x20),*(undefined1 *)(lVar10 + 0x10),1);
                  }
                }
              }
            }
          }
        }
        else if (*puVar15 != 0) {
          *puVar19 = 0;
          lVar13 = param_2 + uVar17 * 0x28;
          *puVar15 = 1;
          *(undefined1 *)(lVar13 + 0x20) = 1;
          *(undefined4 *)(lVar13 + 0x24) = 0xffffffff;
          goto LAB_00118400;
        }
LAB_001182e0:
        _raw_spin_unlock_bh(lVar10 + 0x14c);
      }
      uVar17 = uVar17 + 1;
    } while (uVar17 < *(byte *)(param_2 + 1));
  }
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// dfc_all_bearer_flow_ctl @ 00118880 size=260
// signature: undefined dfc_all_bearer_flow_ctl(void)
// callers: [dfc_do_burst_flow_control]
//------------------------------------------------------------

void dfc_all_bearer_flow_ctl
               (undefined8 param_1,long param_2,undefined1 param_3,byte param_4,long param_5)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  long *plVar5;
  long *plVar6;
  
  plVar5 = (long *)(param_2 + 0x38);
  plVar6 = (long *)*plVar5;
  if (plVar6 != plVar5) {
    do {
      *(undefined4 *)(plVar6 + 3) = *(undefined4 *)(param_5 + 4);
      uVar4 = qmi_rmnet_grant_per();
      *(undefined4 *)((long)plVar6 + 0x1c) = uVar4;
      uVar3 = *(undefined2 *)(param_5 + 8);
      *(undefined1 *)((long)plVar6 + 0x22) = param_3;
      *(byte *)((long)plVar6 + 0x34) = param_4 & 1;
      iVar2 = (int)plVar6[3];
      *(undefined2 *)(plVar6 + 4) = uVar3;
      *(undefined4 *)((long)plVar6 + 0x24) = *(undefined4 *)(param_5 + 4);
      *(undefined2 *)(plVar6 + 5) = *(undefined2 *)(param_5 + 8);
      *(undefined4 *)(plVar6 + 6) = *(undefined4 *)(param_5 + 4);
      if ((int)plVar6[8] != 0xff) {
        bVar1 = param_4 & 1;
        if (iVar2 != 0) {
          bVar1 = 1;
        }
        qmi_rmnet_flow_control(param_1,(int)plVar6[8],bVar1);
      }
      qmi_rmnet_flow_control(param_1,*(undefined4 *)((long)plVar6 + 0x3c),iVar2 != 0);
      if ((iVar2 == 0) && (*(char *)((long)plVar6 + 0x22) != '\0')) {
        dfc_send_ack(param_1,(char)plVar6[2],(short)plVar6[4],*(undefined1 *)(param_2 + 0x10),1);
      }
      plVar6 = (long *)*plVar6;
    } while (plVar6 != plVar5);
  }
  return;
}



//------------------------------------------------------------
// dfc_handle_tx_link_status_ind @ 00118988 size=452
// signature: undefined dfc_handle_tx_link_status_ind(void)
// callers: [dfc_qmi_ind_work, dfc_qmap_cmd_handler]
//------------------------------------------------------------

void dfc_handle_tx_link_status_ind(undefined8 *param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined1 uVar9;
  ulong uVar10;
  
  __rcu_read_lock();
  if (param_2[2] != '\0') {
    uVar10 = 0;
    uVar4 = sp_el0;
    do {
      lVar6 = rmnet_get_rmnet_dev(*param_1,param_2[uVar10 * 8 + 5]);
      if (lVar6 == 0) break;
      lVar7 = rmnet_get_qos_pt();
      if (lVar7 != 0) {
        _raw_spin_lock_bh(lVar7 + 0x14c);
        cVar3 = *param_2;
        lVar8 = qmi_rmnet_get_bearer_map(lVar7,param_2[uVar10 * 8 + 6]);
        if ((lVar8 != 0) && ((bool)*(char *)(lVar8 + 0x36) != (cVar3 == '\0'))) {
          if ((cVar3 == '\0') && (*(int *)(lVar8 + 0x18) != 0)) {
            *(undefined4 *)(lVar8 + 0x18) = 0;
            *(undefined1 *)(lVar8 + 0x34) = 0;
            *(undefined4 *)(lVar8 + 0x2c) = 0;
            qmi_rmnet_watchdog_remove(lVar8);
            iVar1 = *(int *)(lVar8 + 0x40);
            iVar2 = *(int *)(lVar8 + 0x18);
joined_r0x00118ad4:
            if (iVar1 != 0xff) {
              if (iVar2 == 0) {
                uVar9 = *(undefined1 *)(lVar8 + 0x34);
              }
              else {
                uVar9 = 1;
              }
              qmi_rmnet_flow_control(lVar6,iVar1,uVar9);
            }
            qmi_rmnet_flow_control(lVar6,*(undefined4 *)(lVar8 + 0x3c),iVar2 != 0);
            if ((iVar2 == 0) && (*(char *)(lVar8 + 0x22) != '\0')) {
              dfc_send_ack(lVar6,*(undefined1 *)(lVar8 + 0x10),*(undefined2 *)(lVar8 + 0x20),
                           *(undefined1 *)(lVar7 + 0x10),1);
            }
          }
          else if (((cVar3 != '\0') && (*(int *)(lVar8 + 0x18) == 0)) &&
                  (*(char *)(lVar8 + 0x35) == '\0')) {
            *(undefined4 *)(lVar8 + 0x18) = 1;
            uVar5 = qmi_rmnet_grant_per(1);
            iVar1 = *(int *)(lVar8 + 0x40);
            *(undefined4 *)(lVar8 + 0x1c) = uVar5;
            iVar2 = *(int *)(lVar8 + 0x18);
            *(undefined2 *)(lVar8 + 0x20) = 0;
            *(undefined1 *)(lVar8 + 0x22) = 0;
            goto joined_r0x00118ad4;
          }
          *(bool *)(lVar8 + 0x36) = cVar3 == '\0';
        }
        _raw_spin_unlock_bh(lVar7 + 0x14c);
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < (byte)param_2[2]);
  }
  __rcu_read_unlock();
  return;
}



//------------------------------------------------------------
// dfc_qmi_client_init @ 00118c00 size=464
// signature: undefined dfc_qmi_client_init(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int dfc_qmi_client_init(long param_1,uint param_2,undefined8 *param_3,long param_4)

{
  long *plVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  long *plVar5;
  long lVar6;
  undefined8 uVar7;
  
  iVar4 = -0x16;
  if ((param_1 != 0) && (param_4 != 0)) {
    plVar5 = (long *)kmalloc_trace(_netdev_rx_handler_register,0xdc0,0x1f0);
    if (plVar5 == (long *)0x0) {
      iVar4 = -0xc;
    }
    else {
      uVar7 = *param_3;
      uVar2 = *(undefined4 *)(param_3 + 1);
      *plVar5 = param_1;
      *(undefined8 *)((long)plVar5 + 0x194) = uVar7;
      *(uint *)((long)plVar5 + 0x1e4) = param_2;
      *(undefined4 *)(plVar5 + 0x3d) = 0;
      *(undefined4 *)((long)plVar5 + 0x19c) = uVar2;
      plVar5[0x34] = 0xfffffffe0;
      plVar5[0x35] = (long)(plVar5 + 0x35);
      plVar5[0x36] = (long)(plVar5 + 0x35);
      plVar5[0x37] = (long)dfc_qmi_ind_work;
      plVar5[0x3a] = (long)(plVar5 + 0x3a);
      plVar5[0x3b] = (long)(plVar5 + 0x3a);
      *(undefined4 *)(plVar5 + 0x3c) = 0;
      lVar6 = alloc_workqueue(&DAT_00120d2e,0xe000a,1,"dfc_wq");
      plVar5[1] = lVar6;
      if (lVar6 == 0) {
        _printk(&DAT_001216ce,"dfc_qmi_client_init");
        iVar4 = -0xc;
      }
      else {
        plVar1 = plVar5 + 8;
        plVar5[2] = 0xfffffffe0;
        plVar5[3] = (long)(plVar5 + 3);
        plVar5[4] = (long)(plVar5 + 3);
        plVar5[5] = (long)dfc_svc_init;
        iVar4 = qmi_handle_init(plVar1,0x21f,&server_ops,qmi_indication_handler);
        if (iVar4 < 0) {
          _printk(&DAT_00121679,"dfc_qmi_client_init",iVar4);
        }
        else {
          iVar4 = qmi_add_lookup(plVar1,0x4e,1,*(undefined4 *)param_3);
          if (-1 < iVar4) {
            if (1 < param_2) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x118dd0);
              (*pcVar3)();
            }
            *(long **)(param_4 + (ulong)param_2 * 8 + 0x28) = plVar5;
            return 0;
          }
          _printk(&DAT_00121381,"dfc_qmi_client_init",iVar4);
          qmi_handle_release(plVar1);
        }
        destroy_workqueue(plVar5[1]);
      }
      kfree(plVar5);
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// dfc_qmi_ind_work @ 00118dd4 size=300
// signature: undefined dfc_qmi_ind_work(void)
// callers: []
//------------------------------------------------------------

void dfc_qmi_ind_work(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  long *plVar7;
  long *plVar8;
  
  puVar4 = (undefined8 *)(param_1 + -0x1a0);
  if (puVar4 != (undefined8 *)0x0) {
    lVar2 = sp_el0;
    lVar1 = param_1 + 0x40;
    *(int *)(lVar2 + 0x10) = *(int *)(lVar2 + 0x10) + 0x200;
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    plVar8 = (long *)(param_1 + 0x30);
    plVar7 = (long *)*plVar8;
    while ((plVar7 != plVar8 && (plVar7 != (long *)0x0))) {
      uVar6 = __list_del_entry_valid(plVar7);
      if ((uVar6 & 1) != 0) {
        lVar2 = *plVar7;
        plVar3 = (long *)plVar7[1];
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      *plVar7 = -0x2152ffffffffff00;
      plVar7[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      if (*(int *)(param_1 + 0x48) == 0) {
        if ((short)plVar7[2] == 0x24) {
          dfc_handle_tx_link_status_ind(puVar4,(long)plVar7 + 0x14);
        }
        else if ((short)plVar7[2] == 0x22) {
          dfc_do_burst_flow_control(puVar4,(long)plVar7 + 0x14,0);
        }
      }
      kfree(plVar7);
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      plVar7 = (long *)*plVar8;
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    local_bh_enable();
    qmi_rmnet_set_dl_msg_active(*puVar4);
  }
  return;
}



//------------------------------------------------------------
// dfc_svc_init @ 00118f04 size=924
// signature: undefined dfc_svc_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dfc_svc_init(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  long lVar8;
  undefined *puVar9;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  if (*(int *)(param_1 + 0x1d8) == 1) goto LAB_00119148;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  puVar6 = (undefined2 *)kmalloc_trace(___stack_chk_fail,0xb20,0xc);
  if (puVar6 == (undefined2 *)0x0) {
LAB_0011912c:
    iVar5 = -0xc;
  }
  else {
    puVar7 = (ushort *)kmalloc_trace(___stack_chk_fail,0xb20,4);
    if (puVar7 == (ushort *)0x0) {
LAB_00119124:
      kfree(puVar6);
      goto LAB_0011912c;
    }
    lVar8 = param_1 + 0x30;
    iVar5 = qmi_txn_init(lVar8,&local_a0,dfc_bind_client_resp_msg_v01_ei,puVar7);
    if (iVar5 < 0) {
      puVar9 = &DAT_00120ef6;
LAB_001191ac:
      _printk(puVar9,"dfc_bind_client_req",iVar5);
    }
    else {
      uVar1 = *(undefined4 *)(param_1 + 0x188);
      uVar2 = *(undefined4 *)(param_1 + 0x18c);
      *(undefined1 *)puVar6 = 1;
      *(undefined4 *)(puVar6 + 2) = uVar1;
      *(undefined4 *)(puVar6 + 4) = uVar2;
      iVar5 = qmi_send_request(lVar8,param_1 + 0x178,&local_a0,0x20,0xb,
                               dfc_bind_client_req_msg_v01_ei,puVar6);
      if (iVar5 < 0) {
        qmi_txn_cancel(&local_a0);
        puVar9 = &DAT_001213bf;
        goto LAB_001191ac;
      }
      iVar5 = qmi_txn_wait(&local_a0,0xfa);
      if (iVar5 < 0) {
        puVar9 = &DAT_00120ffa;
        goto LAB_001191ac;
      }
      if (*puVar7 != 0) {
        _printk(&DAT_001209a2,"dfc_bind_client_req",*puVar7,puVar7[1]);
        iVar5 = -(uint)*puVar7;
      }
    }
    kfree(puVar7);
    kfree(puVar6);
    if (-1 < iVar5) {
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_98 = 0;
      uStack_90 = 0;
      local_a0 = 0;
      puVar6 = (undefined2 *)kmalloc_trace(___stack_chk_fail,0xb20,4);
      if (puVar6 == (undefined2 *)0x0) goto LAB_0011912c;
      puVar7 = (ushort *)kmalloc_trace(___stack_chk_fail,0xb20,4);
      if (puVar7 == (ushort *)0x0) goto LAB_00119124;
      iVar5 = qmi_txn_init(lVar8,&local_a0,dfc_indication_register_resp_msg_v01_ei,puVar7);
      iVar3 = dfc_ps_ext;
      if (iVar5 < 0) {
        puVar9 = &DAT_00120ef6;
LAB_00119210:
        _printk(puVar9,"dfc_indication_register_req",iVar5);
      }
      else {
        *puVar6 = 0x101;
        if (iVar3 == 0) {
          puVar6[1] = 0x101;
        }
        iVar5 = qmi_send_request(lVar8,param_1 + 0x178,&local_a0,1,8,
                                 dfc_indication_register_req_msg_v01_ei,puVar6);
        if (iVar5 < 0) {
          qmi_txn_cancel(&local_a0);
          puVar9 = &DAT_001213bf;
          goto LAB_00119210;
        }
        iVar5 = qmi_txn_wait(&local_a0,0xfa);
        if (iVar5 < 0) {
          puVar9 = &DAT_00120ffa;
          goto LAB_00119210;
        }
        if (*puVar7 != 0) {
          _printk(&DAT_001209a2,"dfc_indication_register_req",*puVar7,puVar7[1]);
          iVar5 = -(uint)*puVar7;
        }
      }
      kfree(puVar7);
      kfree(puVar6);
      if (-1 < iVar5) {
        if (*(int *)(param_1 + 0x1d8) != 1) {
          do {
            iVar5 = rtnl_trylock();
            if (iVar5 != 0) {
              lVar8 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + -0x10));
              if (lVar8 == 0) {
                rtnl_unlock();
                break;
              }
              if (*(uint *)(param_1 + 0x1d4) < 2) {
                *(undefined8 *)(lVar8 + (ulong)*(uint *)(param_1 + 0x1d4) * 8 + 0x28) = 0;
                if (*(uint *)(param_1 + 0x1d4) < 2) {
                  *(undefined8 **)(lVar8 + (ulong)*(uint *)(param_1 + 0x1d4) * 8 + 0x18) =
                       (undefined8 *)(param_1 + -0x10);
                  trace_dfc_client_state_up
                            (*(undefined4 *)(param_1 + 0x1d4),*(undefined4 *)(param_1 + 0x184),
                             *(undefined4 *)(param_1 + 0x188),*(undefined4 *)(param_1 + 0x18c));
                  rtnl_unlock();
                  _printk(&DAT_00120f6f);
                  break;
                }
              }
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1192a0);
              (*pcVar4)();
            }
          } while (*(int *)(param_1 + 0x1d8) == 0);
        }
        goto LAB_00119148;
      }
    }
  }
  _printk(&DAT_001214bc,"dfc_svc_init",iVar5);
LAB_00119148:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dfc_qmi_client_exit @ 001192a4 size=120
// signature: undefined dfc_qmi_client_exit(void)
// callers: [__qmi_rmnet_delete_client]
//------------------------------------------------------------

void dfc_qmi_client_exit(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00120e98,"dfc_qmi_client_exit");
  }
  else {
    *(undefined4 *)(param_1 + 0x1e8) = 1;
    qmi_handle_release(*(undefined4 *)(param_1 + 0x1e4),param_1 + 0x40);
    drain_workqueue(*(undefined8 *)(param_1 + 8));
    destroy_workqueue(*(undefined8 *)(param_1 + 8));
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// dfc_qmi_burst_check @ 001193c0 size=300
// signature: undefined dfc_qmi_burst_check(void)
// callers: [qmi_rmnet_burst_fc_check]
//------------------------------------------------------------

void dfc_qmi_burst_check(undefined8 param_1,long param_2,undefined4 param_3,undefined4 param_4,
                        uint param_5)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  _raw_spin_lock_bh(param_2 + 0x14c);
  lVar2 = qmi_rmnet_get_flow_map(param_2,param_4,param_3);
  if ((lVar2 != 0) && (lVar2 = *(long *)(lVar2 + 0x20), lVar2 != 0)) {
    uVar1 = *(uint *)(lVar2 + 0x18);
    *(uint *)(lVar2 + 0x2c) = *(int *)(lVar2 + 0x2c) + param_5;
    if (uVar1 != 0) {
      uVar3 = 0;
      if (param_5 <= uVar1) {
        uVar3 = uVar1 - param_5;
      }
      *(uint *)(lVar2 + 0x18) = uVar3;
      if (*(uint *)(lVar2 + 0x1c) < uVar1) {
        if (*(uint *)(lVar2 + 0x1c) < uVar3) goto LAB_001194c4;
        dfc_send_ack(param_1,*(undefined1 *)(lVar2 + 0x10),*(undefined2 *)(lVar2 + 0x20),
                     *(undefined1 *)(param_2 + 0x10),2);
        uVar3 = *(uint *)(lVar2 + 0x18);
      }
      if (uVar3 == 0) {
        if (*(int *)(lVar2 + 0x40) != 0xff) {
          qmi_rmnet_flow_control(param_1,*(int *)(lVar2 + 0x40),*(undefined1 *)(lVar2 + 0x34));
        }
        qmi_rmnet_flow_control(param_1,*(undefined4 *)(lVar2 + 0x3c),0);
        if (*(char *)(lVar2 + 0x22) != '\0') {
          dfc_send_ack(param_1,*(undefined1 *)(lVar2 + 0x10),*(undefined2 *)(lVar2 + 0x20),
                       *(undefined1 *)(param_2 + 0x10),1);
        }
      }
    }
  }
LAB_001194c4:
  _raw_spin_unlock_bh(param_2 + 0x14c);
  return;
}



//------------------------------------------------------------
// dfc_qmi_query_flow @ 001195a0 size=496
// signature: undefined dfc_qmi_query_flow(void)
// callers: [qmi_rmnet_check_stats]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dfc_qmi_query_flow(long param_1)

{
  byte bVar1;
  int iVar2;
  ushort *puVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  
  puVar3 = (ushort *)kmalloc_trace(___warn_printk,0xb20,0x288);
  if (puVar3 == (ushort *)0x0) {
    return;
  }
  lVar4 = kmalloc_trace(___warn_printk,0xb20,800);
  if (lVar4 == 0) goto LAB_00119708;
  if ((param_1 != 0) && (lVar5 = kmalloc_trace(___stack_chk_fail,0xb20,0x12), lVar5 != 0)) {
    lVar6 = kmalloc_trace(_rtnl_is_locked,0xb20,0x48);
    if (lVar6 == 0) {
      kfree(lVar5);
    }
    else {
      iVar2 = qmi_txn_init(param_1 + 0x40,lVar6,dfc_get_flow_status_resp_msg_v01_ei,puVar3);
      if (iVar2 < 0) {
        puVar7 = &DAT_00120ef6;
LAB_00119758:
        _printk(puVar7,"dfc_get_flow_status_req",iVar2);
      }
      else {
        iVar2 = qmi_send_request(param_1 + 0x40,param_1 + 0x188,lVar6,0x23,0x14,
                                 dfc_get_flow_status_req_msg_v01_ei,lVar5);
        if (iVar2 < 0) {
          qmi_txn_cancel(lVar6);
          puVar7 = &DAT_001213bf;
          goto LAB_00119758;
        }
        iVar2 = qmi_txn_wait(lVar6,0xfa);
        if (iVar2 < 0) {
          puVar7 = &DAT_00120ffa;
          goto LAB_00119758;
        }
        if (*puVar3 != 0) {
          _printk(&DAT_001209a2,"dfc_get_flow_status_req",*puVar3,puVar3[1]);
          iVar2 = -(uint)*puVar3;
        }
      }
      kfree(lVar6);
      kfree(lVar5);
      if ((-1 < iVar2) && ((char)puVar3[2] != '\0')) {
        bVar1 = *(byte *)((long)puVar3 + 5);
        if (0xffffffef < bVar1 - 0x11) {
          *(char *)(lVar4 + 0x14) = (char)puVar3[2];
          *(byte *)(lVar4 + 0x15) = bVar1;
          memcpy((void *)(lVar4 + 0x18),puVar3 + 4,(ulong)bVar1 * 0x28);
          dfc_do_burst_flow_control(param_1,(char *)(lVar4 + 0x14),1);
        }
      }
    }
  }
  kfree(lVar4);
LAB_00119708:
  kfree(puVar3);
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_qmi_tc @ 00119794 size=132
// signature: undefined trace_raw_output_dfc_qmi_tc(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_qmi_tc(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "disable";
    if (*(int *)(lVar3 + 0x10) != 0) {
      pcVar1 = "enable";
    }
    trace_event_printf(param_1,"dev=%s txq=%u %s\n",lVar3 + (ulong)*(ushort *)(lVar3 + 8),
                       *(undefined4 *)(lVar3 + 0xc),pcVar1);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_flow_ind @ 0011981c size=140
// signature: undefined trace_raw_output_dfc_flow_ind(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_flow_ind(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"src=%d [%d]: mid=%u bid=%u grant=%u seq=%u ack=%u anc=%u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined1 *)(lVar2 + 0x10),*(undefined1 *)(lVar2 + 0x11),
                       *(undefined4 *)(lVar2 + 0x14),*(undefined2 *)(lVar2 + 0x18),
                       *(undefined1 *)(lVar2 + 0x1a),*(undefined4 *)(lVar2 + 0x1c));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_flow_check @ 001198ac size=116
// signature: undefined trace_raw_output_dfc_flow_check(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_flow_check(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"dev=%s bearer_id=%u skb_len=%u mark=%u current_grant=%u\n",
                       lVar2 + (ulong)*(ushort *)(lVar2 + 8),*(undefined1 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14),
                       *(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_flow_info @ 00119924 size=140
// signature: undefined trace_raw_output_dfc_flow_info(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_flow_info(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "delete flow";
    if (*(int *)(lVar3 + 0x1c) != 0) {
      pcVar1 = "add flow";
    }
    trace_event_printf(param_1,"%s: dev=%s bearer_id=%u flow_id=%u ip_type=%d txq=%d\n",pcVar1,
                       lVar3 + (ulong)*(ushort *)(lVar3 + 8),*(undefined1 *)(lVar3 + 0xc),
                       *(undefined4 *)(lVar3 + 0x10),*(undefined4 *)(lVar3 + 0x14),
                       *(undefined4 *)(lVar3 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_client_state_up @ 001199b4 size=104
// signature: undefined trace_raw_output_dfc_client_state_up(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_client_state_up(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"DFC Client[%d] connect: instance=%u ep_type=%u iface_id=%u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_client_state_down @ 00119a20 size=100
// signature: undefined trace_raw_output_dfc_client_state_down(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_client_state_down(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"DFC Client[%d] exit: callback %d\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_qmap_cmd @ 00119a88 size=116
// signature: undefined trace_raw_output_dfc_qmap_cmd(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_qmap_cmd(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"mux_id=%u bearer_id=%u seq_num=%u type=%u tran=%u\n",
                       *(undefined1 *)(lVar2 + 8),*(undefined1 *)(lVar2 + 9),
                       *(undefined2 *)(lVar2 + 10),*(undefined1 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_tx_link_status_ind @ 00119b00 size=112
// signature: undefined trace_raw_output_dfc_tx_link_status_ind(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_tx_link_status_ind(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"src=%d [%d]: status=%u mux_id=%u bearer_id=%u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined1 *)(lVar2 + 0x10),*(undefined1 *)(lVar2 + 0x11),
                       *(undefined1 *)(lVar2 + 0x12));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_qmap @ 00119b74 size=172
// signature: undefined trace_raw_output_dfc_qmap(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_qmap(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  undefined1 uVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x20f0);
  iVar3 = trace_raw_output_prep(param_1,param_3);
  if (iVar3 == 1) {
    uVar2 = *(undefined1 *)(lVar5 + 0x1c);
    puVar1 = &UNK_00120bda;
    if (*(char *)(lVar5 + 8) != '\0') {
      puVar1 = &DAT_0012141e;
    }
    uVar4 = trace_print_array_seq
                      (param_1 + 0x90,lVar5 + (ulong)*(ushort *)(lVar5 + 0x18),
                       *(undefined4 *)(lVar5 + 0x10),1);
    trace_event_printf(param_1,"[0x%02x] %s %s\n",uVar2,puVar1,uVar4);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_adjust_grant @ 00119c24 size=112
// signature: undefined trace_raw_output_dfc_adjust_grant(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_adjust_grant(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"mid=%u bid=%u grant=%u rx=%u inflight=%u adjusted_grant=%u\n",
                       *(undefined1 *)(lVar2 + 8),*(undefined1 *)(lVar2 + 9),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x14),*(undefined4 *)(lVar2 + 0x18));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_watchdog @ 00119c98 size=108
// signature: undefined trace_raw_output_dfc_watchdog(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_watchdog(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"mid=%u bid=%u event=%u\n",*(undefined1 *)(lVar2 + 8),
                       *(undefined1 *)(lVar2 + 9),*(undefined1 *)(lVar2 + 10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_ll_switch @ 00119d08 size=160
// signature: undefined trace_raw_output_dfc_ll_switch(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_ll_switch(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  ushort uVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0x20f0);
  iVar4 = trace_raw_output_prep(param_1,param_3);
  if (iVar4 == 1) {
    uVar1 = *(undefined1 *)(lVar6 + 0xd);
    uVar3 = *(ushort *)(lVar6 + 8);
    uVar2 = *(undefined1 *)(lVar6 + 0xc);
    uVar5 = trace_print_array_seq(param_1 + 0x90,lVar6 + (ulong)*(ushort *)(lVar6 + 0x10),uVar1,1);
    trace_event_printf(param_1,"%s type=%u num_bearer=%u bearers={%s}\n",lVar6 + (ulong)uVar3,uVar2,
                       uVar1,uVar5);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_set_powersave_mode @ 00119dac size=116
// signature: undefined trace_raw_output_dfc_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_set_powersave_mode(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "disable";
    if (*(int *)(lVar3 + 8) != 0) {
      pcVar1 = "enable";
    }
    trace_event_printf(param_1,"set powersave mode to %s\n",pcVar1);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_dfc_pm_event @ 00119e24 size=100
// signature: undefined trace_raw_output_dfc_pm_event(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_dfc_pm_event(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"Got PM event from notifier %d\n",*(undefined4 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// local_bh_enable @ 00119e88 size=40
// signature: undefined local_bh_enable(void)
// callers: [dfc_qmi_ind_work]
//------------------------------------------------------------

void local_bh_enable(void)

{
  __local_bh_enable_ip(local_bh_enable,0x200);
  return;
}



//------------------------------------------------------------
// trace_dfc_client_state_up @ 00119eb0 size=44
// signature: undefined trace_dfc_client_state_up(void)
// callers: [dfc_svc_init]
//------------------------------------------------------------

void trace_dfc_client_state_up(void)

{
  return;
}



//------------------------------------------------------------
// dfc_svc_arrive @ 00119f90 size=68
// signature: undefined dfc_svc_arrive(void)
// callers: []
//------------------------------------------------------------

undefined8 dfc_svc_arrive(long param_1,long param_2)

{
  *(undefined2 *)(param_1 + 0x148) = 0x2a;
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_2 + 0x10);
  queue_work_on(0x20,*(undefined8 *)(param_1 + -0x38),param_1 + -0x30);
  return 0;
}



//------------------------------------------------------------
// dfc_svc_exit @ 00119fd8 size=4
// signature: undefined dfc_svc_exit(void)
// callers: []
//------------------------------------------------------------

void dfc_svc_exit(void)

{
  return;
}



//------------------------------------------------------------
// dfc_clnt_ind_cb @ 00119fe0 size=236
// signature: undefined dfc_clnt_ind_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dfc_clnt_ind_cb(long param_1,undefined8 param_2,undefined8 param_3,char *param_4)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  if (*param_4 != '\0') {
    if ((byte)param_4[1] < 0x11) {
      plVar1 = (long *)kmalloc_trace(___warn_printk,0xb20,800);
      if (plVar1 != (long *)0x0) {
        *(undefined2 *)(plVar1 + 2) = 0x22;
        memcpy((void *)((long)plVar1 + 0x14),param_4,0x308);
        uVar2 = _raw_spin_lock_irqsave(param_1 + 0x1a0);
        puVar4 = *(undefined8 **)(param_1 + 0x198);
        uVar3 = __list_add_valid(plVar1,puVar4,param_1 + 400);
        if ((uVar3 & 1) != 0) {
          *(long **)(param_1 + 0x198) = plVar1;
          *plVar1 = param_1 + 400;
          plVar1[1] = (long)puVar4;
          *puVar4 = plVar1;
        }
        _raw_spin_unlock_irqrestore(param_1 + 0x1a0,uVar2);
        queue_work_on(0x20,*(undefined8 *)(param_1 + -0x38),param_1 + 0x160);
      }
    }
    else {
      _printk(&DAT_00121422,"dfc_clnt_ind_cb");
    }
  }
  return;
}



//------------------------------------------------------------
// dfc_tx_link_status_ind_cb @ 0011a0d0 size=236
// signature: undefined dfc_tx_link_status_ind_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void dfc_tx_link_status_ind_cb(long param_1,undefined8 param_2,undefined8 param_3,void *param_4)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  if (*(char *)((long)param_4 + 1) != '\0') {
    if (*(byte *)((long)param_4 + 2) < 0x11) {
      plVar1 = (long *)kmalloc_trace(___warn_printk,0xb20,800);
      if (plVar1 != (long *)0x0) {
        *(undefined2 *)(plVar1 + 2) = 0x24;
        memcpy((void *)((long)plVar1 + 0x14),param_4,0x84);
        uVar2 = _raw_spin_lock_irqsave(param_1 + 0x1a0);
        puVar4 = *(undefined8 **)(param_1 + 0x198);
        uVar3 = __list_add_valid(plVar1,puVar4,param_1 + 400);
        if ((uVar3 & 1) != 0) {
          *(long **)(param_1 + 0x198) = plVar1;
          *plVar1 = param_1 + 400;
          plVar1[1] = (long)puVar4;
          *puVar4 = plVar1;
        }
        _raw_spin_unlock_irqrestore(param_1 + 0x1a0,uVar2);
        queue_work_on(0x20,*(undefined8 *)(param_1 + -0x38),param_1 + 0x160);
      }
    }
    else {
      _printk(&DAT_001215da,"dfc_tx_link_status_ind_cb");
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_has_dfc_client @ 0011a214 size=28
// signature: undefined qmi_rmnet_has_dfc_client(void)
// callers: []
//------------------------------------------------------------

long qmi_rmnet_has_dfc_client(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if ((param_1 == 0) || (lVar1 = *(long *)(param_1 + 0x18), lVar1 != 0)) {
    return lVar1;
  }
  return *(long *)(param_1 + 0x20);
}



//------------------------------------------------------------
// qmi_rmnet_get_flow_map @ 0011a234 size=64
// signature: undefined qmi_rmnet_get_flow_map(void)
// callers: [dfc_qmi_burst_check]
//------------------------------------------------------------

undefined8 * qmi_rmnet_get_flow_map(long param_1,int param_2,int param_3)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)0x0;
  if (param_1 != 0) {
    puVar1 = *(undefined8 **)(param_1 + 0x28);
    while( true ) {
      if (puVar1 == (undefined8 *)(param_1 + 0x28)) {
        return (undefined8 *)0x0;
      }
      if ((*(int *)((long)puVar1 + 0x14) == param_2) && (*(int *)(puVar1 + 3) == param_3)) break;
      puVar1 = (undefined8 *)*puVar1;
    }
  }
  return puVar1;
}



//------------------------------------------------------------
// qmi_rmnet_get_bearer_map @ 0011a278 size=52
// signature: undefined qmi_rmnet_get_bearer_map(void)
// callers: [dfc_qmap_send_ack, dfc_handle_tx_link_status_ind, ll_qmap_cmd_handler, dfc_qmap_cmd_handler, rmnet_ll_switch, dfc_do_burst_flow_control]
//------------------------------------------------------------

long * qmi_rmnet_get_bearer_map(long param_1,char param_2)

{
  long *plVar1;
  
  plVar1 = (long *)0x0;
  if (param_1 != 0) {
    plVar1 = (long *)(param_1 + 0x38);
    do {
      plVar1 = (long *)*plVar1;
      if (plVar1 == (long *)(param_1 + 0x38)) {
        return (long *)0;
      }
    } while (*(char *)(plVar1 + 2) != param_2);
  }
  return plVar1;
}



//------------------------------------------------------------
// qmi_rmnet_flow_control @ 0011a2b0 size=160
// signature: undefined qmi_rmnet_flow_control(void)
// callers: [__qmi_rmnet_update_mq, dfc_qmi_burst_check, dfc_handle_tx_link_status_ind, dfc_all_bearer_flow_ctl, dfc_do_burst_flow_control, dfc_bearer_flow_ctl, __qmi_rmnet_bearer_put]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qmi_rmnet_flow_control(long param_1,uint param_2,int param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  if ((param_2 < *(uint *)(param_1 + 0x3c8)) &&
     (*(long *)(param_1 + 0x3c0) + (ulong)param_2 * 0x1c0 != 0)) {
    if (param_3 == 0) {
      lVar4 = *(long *)(param_1 + 0x3c0) + (ulong)param_2 * 0x1c0;
      *(undefined8 *)(lVar4 + 200) = _jiffies;
      puVar1 = (ulong *)(lVar4 + 0xd0);
      DataMemoryBarrier(2,3);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      netif_tx_wake_queue();
    }
  }
  return 0;
}



//------------------------------------------------------------
// qmi_rmnet_watchdog_add @ 0011a3cc size=92
// signature: undefined qmi_rmnet_watchdog_add(void)
// callers: [dfc_do_burst_flow_control]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_rmnet_watchdog_add(long param_1)

{
  *(undefined1 *)(param_1 + 0x89) = 0;
  if (*(char *)(param_1 + 0x88) == '\0') {
    *(undefined1 *)(param_1 + 0x88) = 1;
    mod_timer(param_1 + 0x50,_jiffies + 0xd);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_watchdog_remove @ 0011a494 size=80
// signature: undefined qmi_rmnet_watchdog_remove(void)
// callers: [dfc_handle_tx_link_status_ind, dfc_do_burst_flow_control, qmi_rmnet_enable_all_flows, qmi_rmnet_prepare_ps_bearers]
//------------------------------------------------------------

void qmi_rmnet_watchdog_remove(long param_1)

{
  *(undefined1 *)(param_1 + 0x89) = 1;
  if (*(char *)(param_1 + 0x88) != '\0') {
    del_timer(param_1 + 0x50);
    *(undefined1 *)(param_1 + 0x88) = 0;
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_get_bearer_noref @ 0011a550 size=44
// signature: undefined qmi_rmnet_get_bearer_noref(void)
// callers: [dfc_do_burst_flow_control]
//------------------------------------------------------------

void qmi_rmnet_get_bearer_noref(void)

{
  long lVar1;
  
  lVar1 = __qmi_rmnet_bearer_get();
  if (lVar1 != 0) {
    *(int *)(lVar1 + 0x14) = *(int *)(lVar1 + 0x14) + -1;
  }
  return;
}



//------------------------------------------------------------
// __qmi_rmnet_bearer_get @ 0011a57c size=276
// signature: undefined __qmi_rmnet_bearer_get(void)
// callers: [qmi_rmnet_get_bearer_noref, qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * __qmi_rmnet_bearer_get(long param_1,char param_2)

{
  uint uVar1;
  uint uVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  long lVar6;
  
  if (param_1 != 0) {
    plVar5 = (long *)(param_1 + 0x38);
    do {
      plVar5 = (long *)*plVar5;
      if (plVar5 == (long *)(param_1 + 0x38)) goto LAB_0011a5d0;
    } while (*(char *)(plVar5 + 2) != param_2);
    if (plVar5 != (long *)0x0) {
      *(int *)((long)plVar5 + 0x14) = *(int *)((long)plVar5 + 0x14) + 1;
      return plVar5;
    }
  }
LAB_0011a5d0:
  plVar5 = (long *)kmalloc_trace(_memset,0xb20,0xe8);
  uVar2 = qmi_rmnet_scale_factor;
  if (plVar5 != (long *)0x0) {
    *(char *)(plVar5 + 2) = param_2;
    uVar1 = 0;
    if (uVar2 != 0) {
      uVar1 = 0x5000 / uVar2;
    }
    *(undefined8 *)((long)plVar5 + 0x3c) = 0xff000000ff;
    plVar5[9] = param_1;
    *(undefined8 *)((long)plVar5 + 0x14) = 0x500000000001;
    *(uint *)((long)plVar5 + 0x1c) = uVar1;
    init_timer_key(plVar5 + 10,qmi_rmnet_watchdog_fn,0,0,0);
    init_timer_key(plVar5 + 0x15,rmnet_ll_guard_fn,0,0,0);
    plVar4 = (long *)(param_1 + 0x38);
    lVar6 = *plVar4;
    uVar3 = __list_add_valid(plVar5,plVar4,lVar6);
    if ((uVar3 & 1) != 0) {
      *(long **)(lVar6 + 8) = plVar5;
      *plVar5 = lVar6;
      plVar5[1] = (long)plVar4;
      *plVar4 = (long)plVar5;
    }
  }
  return plVar5;
}



//------------------------------------------------------------
// qmi_rmnet_change_link @ 0011a694 size=1632
// signature: undefined qmi_rmnet_change_link(void)
// callers: [rmnet_changelink]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_rmnet_change_link(undefined8 param_1,long param_2,undefined1 *param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  undefined8 uVar9;
  long lVar10;
  uint uVar11;
  long lVar12;
  ulong uVar13;
  uint *puVar14;
  long *plVar15;
  long *plVar16;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  puVar8 = (uint *)rmnet_get_qmi_pt(param_2);
  uVar9 = 0;
  switch(*param_3) {
  case 1:
    uVar9 = 0;
    if ((puVar8 == (uint *)0x0) || (dfc_mode != 4)) goto switchD_0011a708_caseD_3;
    if ((*(long *)(puVar8 + 6) != 0) || (*(long *)(puVar8 + 8) != 0)) {
      lVar10 = rmnet_get_qos_pt(param_1);
      local_70 = 0;
      local_80 = 0;
      local_78 = 0;
      if (((param_3 != (undefined1 *)0x0) && (lVar10 != 0)) && (*(uint *)(param_3 + 8) < 0x10)) {
        iVar6 = rtnl_is_locked();
        if ((iVar6 == 0) && ((qmi_rmnet_add_flow___already_done & 1) == 0)) {
          qmi_rmnet_add_flow___already_done = 1;
          __warn_printk("RTNL: assertion failed at %s (%d)\n",
                        "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x1c1);
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11acf8);
          (*pcVar5)();
        }
        cVar3 = param_3[1];
        iVar2 = *(int *)(param_3 + 4);
        iVar6 = *(int *)(param_3 + 8);
        iVar7 = *(int *)(param_3 + 0xc);
        lVar1 = lVar10 + 0x14c;
        _raw_spin_lock_bh(lVar1);
        plVar15 = (long *)(lVar10 + 0x28);
        for (plVar16 = (long *)*plVar15; plVar16 != plVar15; plVar16 = (long *)*plVar16) {
          while ((*(int *)((long)plVar16 + 0x14) == iVar7 && ((int)plVar16[3] == iVar2))) {
            if (plVar16 == (long *)0x0) goto LAB_0011aa30;
            if ((char)plVar16[2] != cVar3) {
              __qmi_rmnet_bearer_put(param_1,lVar10,plVar16[4],0);
              lVar12 = __qmi_rmnet_bearer_get(lVar10,cVar3);
              if (lVar12 == 0) goto LAB_0011aaa0;
              *(char *)(plVar16 + 2) = cVar3;
              *(int *)((long)plVar16 + 0x14) = iVar7;
              *(int *)(plVar16 + 3) = iVar2;
              *(int *)((long)plVar16 + 0x1c) = iVar6;
              goto LAB_0011aa8c;
            }
            if (*(int *)((long)plVar16 + 0x1c) == iVar6) goto LAB_0011aaa0;
            local_80._0_2_ = CONCAT11(cVar3,(undefined1)local_80);
            local_78 = CONCAT44(iVar7,*(int *)((long)plVar16 + 0x1c));
            local_80 = CONCAT44(iVar2,(undefined4)local_80);
            _raw_spin_unlock_bh(lVar1);
            qmi_rmnet_del_flow(param_1,&local_80);
            _raw_spin_lock_bh(lVar1);
            plVar16 = (long *)*plVar15;
            if (plVar16 == plVar15) goto LAB_0011aa30;
          }
        }
LAB_0011aa30:
        plVar16 = (long *)kmalloc_trace(___stack_chk_fail,0xb20,0x28);
        if (plVar16 == (long *)0x0) {
          _raw_spin_unlock_bh(lVar1);
        }
        else {
          *(char *)(plVar16 + 2) = cVar3;
          *(int *)((long)plVar16 + 0x14) = iVar7;
          *(int *)(plVar16 + 3) = iVar2;
          *(int *)((long)plVar16 + 0x1c) = iVar6;
          lVar12 = *plVar15;
          uVar13 = __list_add_valid(plVar16,plVar15,lVar12);
          if ((uVar13 & 1) != 0) {
            *(long **)(lVar12 + 8) = plVar16;
            *plVar16 = lVar12;
            plVar16[1] = (long)plVar15;
            *plVar15 = (long)plVar16;
          }
          lVar12 = __qmi_rmnet_bearer_get(lVar10,cVar3);
          if (lVar12 != 0) {
LAB_0011aa8c:
            plVar16[4] = lVar12;
            __qmi_rmnet_update_mq(param_1,lVar10,lVar12,plVar16);
          }
LAB_0011aaa0:
          _raw_spin_unlock_bh(lVar1);
          if (*(long *)(lVar10 + 0x150) != 0) {
            *(undefined1 *)(*(long *)(lVar10 + 0x150) + 0x89) = 1;
            del_timer_sync(*(long *)(lVar10 + 0x150) + 0x50);
            *(undefined1 *)(*(long *)(lVar10 + 0x150) + 0xa4) = 1;
            del_timer_sync(*(long *)(lVar10 + 0x150) + 0xa8);
            kfree(*(undefined8 *)(lVar10 + 0x150));
            *(undefined8 *)(lVar10 + 0x150) = 0;
          }
        }
      }
    }
    break;
  case 2:
    uVar9 = 0;
    if ((puVar8 == (uint *)0x0) || (dfc_mode != 4)) goto switchD_0011a708_caseD_3;
    qmi_rmnet_del_flow(param_1,param_3);
    break;
  default:
    goto switchD_0011a708_caseD_3;
  case 4:
    uVar11 = *(uint *)(param_3 + 4);
    dfc_mode = uVar11 & 0xf;
    dfc_qmap = uVar11 & 0x20;
    dfc_ps_ext = uVar11 & 0x40;
    if ((dfc_mode == 4) || ((uVar11 >> 4 & 1) != 0)) {
      iVar6 = rtnl_is_locked(0);
      if ((iVar6 == 0) && ((qmi_rmnet_setup_client___already_done & 1) == 0)) {
        qmi_rmnet_setup_client___already_done = 1;
        __warn_printk("RTNL: assertion failed at %s (%d)\n",
                      "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x26b);
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11acd0);
        (*pcVar5)();
      }
      iVar6 = *(int *)(param_3 + 8);
      uVar13 = (ulong)(iVar6 != 0);
      if (puVar8 == (uint *)0x0) {
        puVar8 = (uint *)kmalloc_trace(_rtnl_is_locked,0xb20,0x50);
        if (puVar8 != (uint *)0x0) {
          rmnet_init_qmi_pt(param_2,puVar8);
          *(code **)(param_2 + 0xb30) = qmi_rmnet_pm_notify_cb;
          register_pm_notifier(param_2 + 0xb30);
          goto LAB_0011a8b4;
        }
LAB_0011abdc:
        lVar10 = rmnet_get_qmi_pt(param_2);
        uVar9 = 0;
        if (lVar10 == 0) goto switchD_0011a708_caseD_3;
        if (((*(long *)(lVar10 + 8) == 0) && (*(long *)(lVar10 + 0x18) == 0)) &&
           ((*(long *)(lVar10 + 0x20) == 0 &&
            (((*(long *)(lVar10 + 0x10) == 0 && (*(long *)(lVar10 + 0x28) == 0)) &&
             (*(long *)(lVar10 + 0x30) == 0)))))) {
          unregister_pm_notifier(param_2 + 0xb30);
          rmnet_reset_qmi_pt(param_2);
          kfree(lVar10);
        }
      }
      else {
LAB_0011a8b4:
        uVar11 = *(uint *)(param_3 + 4);
        *puVar8 = uVar11;
        *(undefined1 *)(puVar8 + 0x12) = 1;
        uVar4 = dfc_mode;
        puVar8[0x13] = uVar11 & 0x40;
        local_80 = CONCAT44(*(undefined4 *)(param_3 + 0x10),*(undefined4 *)(param_3 + 8));
        local_78 = CONCAT44(local_78._4_4_,*(undefined4 *)(param_3 + 0xc));
        if (((uVar4 == 4) && (*(long *)(puVar8 + uVar13 * 2 + 6) == 0)) &&
           (*(long *)(puVar8 + uVar13 * 2 + 10) == 0)) {
          if (dfc_qmap == 0) {
            iVar7 = dfc_qmi_client_init(param_2,uVar13,&local_80,puVar8);
          }
          else {
            iVar7 = dfc_qmap_client_init(param_2,uVar13,&local_80,puVar8);
          }
          if (iVar7 == 0) {
            *(undefined1 *)((long)puVar8 + uVar13 + 0x38) = 0;
            uVar11 = *(uint *)(param_3 + 4);
            goto joined_r0x0011a904;
          }
          rmnet_reset_qmi_pt(param_2);
          kfree(puVar8);
LAB_0011ab7c:
          if (iVar7 < 0) goto LAB_0011abdc;
          uVar11 = *(uint *)(param_3 + 4);
        }
        else {
          uVar11 = *(uint *)(param_3 + 4);
joined_r0x0011a904:
          if ((((uVar11 >> 4 & 1) != 0) && (iVar6 == 0)) &&
             ((*(long *)(puVar8 + 2) == 0 && (*(long *)(puVar8 + 4) == 0)))) {
            iVar7 = wda_qmi_client_init(param_2,&local_80,puVar8);
            goto LAB_0011ab7c;
          }
        }
        if ((uVar11 & 0x10) != 0) {
          qmi_rmnet_work_init(param_2);
          rmnet_set_powersave_format(param_2);
        }
        rmnet_ll_wq_init();
      }
    }
    break;
  case 5:
    if (puVar8 != (uint *)0x0) {
      iVar6 = *(int *)(param_3 + 8);
      if (iVar6 == 0) {
        rmnet_clear_powersave_format(param_2);
        lVar10 = *(long *)(puVar8 + 2);
        if (lVar10 == 0) {
          lVar10 = *(long *)(puVar8 + 4);
        }
        wda_qmi_client_release(lVar10);
        uVar9 = qmi_rmnet_work_exit(param_2);
        iVar6 = *(int *)(param_3 + 8);
      }
      iVar7 = rtnl_is_locked(uVar9);
      if ((iVar7 == 0) && ((qmi_rmnet_delete_client___already_done & 1) == 0)) {
        qmi_rmnet_delete_client___already_done = 1;
        __warn_printk("RTNL: assertion failed at %s (%d)\n",
                      "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x2c7);
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x11aca8);
        (*pcVar5)();
      }
      puVar14 = puVar8 + 2;
      lVar10 = *(long *)puVar14;
      if (lVar10 == 0) {
        lVar10 = *(long *)(puVar8 + 4);
      }
      if ((iVar6 == 0) && (lVar10 != 0)) {
        wda_qmi_client_exit();
        puVar14[0] = 0;
        puVar14[1] = 0;
        puVar8[4] = 0;
        puVar8[5] = 0;
      }
      else {
        *(undefined1 *)((long)puVar8 + (ulong)(iVar6 != 0) + 0x38) = 1;
        if (rmnet_ps_wq != 0) {
          __flush_workqueue();
        }
      }
      __qmi_rmnet_delete_client(param_2,puVar8,(ulong)(iVar6 != 0));
      rmnet_ll_wq_exit();
    }
    break;
  case 6:
    if (*(int *)(param_3 + 4) != 0) {
      uVar9 = 0;
      qmi_rmnet_scale_factor = *(int *)(param_3 + 4);
      goto switchD_0011a708_caseD_3;
    }
    break;
  case 7:
    if (*(int *)(param_3 + 4) < 100) {
      uVar9 = 0xffffffea;
    }
    else {
      uVar9 = 0;
      rmnet_wq_frequency = *(int *)(param_3 + 4);
    }
    goto switchD_0011a708_caseD_3;
  case 8:
    uVar9 = 0;
    if (puVar8 == (uint *)0x0) goto switchD_0011a708_caseD_3;
    if (dfc_mode != 4) goto switchD_0011a708_caseD_3;
    if ((*(long *)(puVar8 + 6) != 0) || (*(long *)(puVar8 + 8) != 0)) {
      uVar9 = rmnet_ll_switch(param_1,param_3,param_4);
      goto switchD_0011a708_caseD_3;
    }
  }
  uVar9 = 0;
switchD_0011a708_caseD_3:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_del_flow @ 0011ad7c size=416
// signature: undefined qmi_rmnet_del_flow(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void qmi_rmnet_del_flow(long param_1,long param_2)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  
  lVar4 = rmnet_get_qos_pt();
  if (lVar4 != 0) {
    iVar3 = rtnl_is_locked();
    if ((iVar3 == 0) && ((qmi_rmnet_del_flow___already_done & 1) == 0)) {
      qmi_rmnet_del_flow___already_done = 1;
      __warn_printk("RTNL: assertion failed at %s (%d)\n",
                    "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x20d);
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x11af1c);
      (*pcVar2)();
    }
    _raw_spin_lock_bh(lVar4 + 0x14c);
    plVar8 = (long *)(lVar4 + 0x28);
    plVar6 = (long *)*plVar8;
    if (plVar6 != plVar8) {
      do {
        if ((*(int *)((long)plVar6 + 0x14) == *(int *)(param_2 + 0xc)) &&
           ((int)plVar6[3] == *(int *)(param_2 + 4))) {
          if (plVar6 != (long *)0x0) {
            __qmi_rmnet_bearer_put
                      (param_1,lVar4,plVar6[4],1,*(int *)(param_2 + 4),
                       *(undefined4 *)((long)plVar6 + 0x1c));
            uVar5 = __list_del_entry_valid(plVar6);
            if ((uVar5 & 1) != 0) {
              lVar7 = *plVar6;
              plVar1 = (long *)plVar6[1];
              *(long **)(lVar7 + 8) = plVar1;
              *plVar1 = lVar7;
            }
            *plVar6 = -0x2152ffffffffff00;
            plVar6[1] = -0x2152fffffffffede;
            kfree(plVar6);
          }
          break;
        }
        plVar6 = (long *)*plVar6;
      } while (plVar6 != plVar8);
    }
    if (((long *)*plVar8 == plVar8) && (*(int *)(param_1 + 0x3c8) != 0)) {
      lVar7 = 0;
      uVar5 = 0;
      do {
        netif_tx_wake_queue(*(long *)(param_1 + 0x3c0) + lVar7);
        uVar5 = uVar5 + 1;
        lVar7 = lVar7 + 0x1c0;
      } while (uVar5 < *(uint *)(param_1 + 0x3c8));
    }
    _raw_spin_unlock_bh(lVar4 + 0x14c);
    if (*(long *)(lVar4 + 0x150) != 0) {
      *(undefined1 *)(*(long *)(lVar4 + 0x150) + 0x89) = 1;
      del_timer_sync(*(long *)(lVar4 + 0x150) + 0x50);
      *(undefined1 *)(*(long *)(lVar4 + 0x150) + 0xa4) = 1;
      del_timer_sync(*(long *)(lVar4 + 0x150) + 0xa8);
      kfree(*(undefined8 *)(lVar4 + 0x150));
      *(undefined8 *)(lVar4 + 0x150) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_work_init @ 0011af90 size=320
// signature: undefined qmi_rmnet_work_init(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_rmnet_work_init(undefined8 param_1)

{
  undefined8 *puVar1;
  ulong *puVar2;
  code *pcVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined8 *puVar7;
  long lVar8;
  
  if ((rmnet_ps_wq == 0) &&
     (rmnet_ps_wq = alloc_workqueue("rmnet_powersave_work",0x20,1), rmnet_ps_wq != 0)) {
    puVar7 = (undefined8 *)kmalloc_trace(_kfree,0xb20,0xa0);
    iVar6 = dfc_ps_ext;
    rmnet_work = puVar7;
    if (puVar7 == (undefined8 *)0x0) {
      destroy_workqueue(rmnet_ps_wq);
      rmnet_ps_wq = 0;
    }
    else {
      *puVar7 = 0xfffffffe0;
      pcVar3 = qmi_rmnet_check_stats;
      if (iVar6 != 0) {
        pcVar3 = qmi_rmnet_check_stats_2;
      }
      puVar7[1] = puVar7 + 1;
      puVar7[2] = puVar7 + 1;
      puVar7[3] = pcVar3;
      init_timer_key(puVar7 + 6,&delayed_work_timer_fn,0x200000,0,0);
      puVar7 = rmnet_work + 0x12;
      puVar1 = rmnet_work + 0x13;
      rmnet_work[0x11] = param_1;
      rmnet_get_packets(param_1,puVar7,puVar1);
      rmnet_work_quit = 0;
      lVar8 = rmnet_get_qmi_pt(rmnet_work[0x11]);
      if (lVar8 != 0) {
        puVar2 = (ulong *)(lVar8 + 0x40);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar5) {
            *puVar2 = *puVar2 & 0xfffffffffffffffe;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
      rmnet_work_inited = 1;
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_work_exit @ 0011b0e0 size=184
// signature: undefined qmi_rmnet_work_exit(void)
// callers: [qmi_rmnet_qmi_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

void qmi_rmnet_work_exit(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  
  if (rmnet_ps_wq != 0 && rmnet_work != 0) {
    rmnet_work_quit = 1;
    synchronize_rcu();
    unregister_pm_notifier(param_1 + 0xb30);
    rmnet_work_inited = 0;
    cancel_delayed_work_sync(rmnet_work);
    destroy_workqueue(rmnet_ps_wq);
    lVar4 = rmnet_get_qmi_pt(param_1);
    if (lVar4 != 0) {
      puVar1 = (ulong *)(lVar4 + 0x40);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    rmnet_ps_wq = 0;
    kfree(rmnet_work);
    rmnet_work = 0;
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_qmi_exit @ 0011b1a8 size=196
// signature: undefined qmi_rmnet_qmi_exit(void)
// callers: [rmnet_dellink, rmnet_config_notify_cb]
//------------------------------------------------------------

void qmi_rmnet_qmi_exit(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 != 0) {
    iVar2 = rtnl_is_locked();
    if ((iVar2 == 0) && ((qmi_rmnet_qmi_exit___already_done & 1) == 0)) {
      qmi_rmnet_qmi_exit___already_done = 1;
      __warn_printk("RTNL: assertion failed at %s (%d)\n",
                    "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x342);
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11b26c);
      (*pcVar1)();
    }
    lVar3 = *(long *)(param_1 + 8);
    if (lVar3 == 0) {
      lVar3 = *(long *)(param_1 + 0x10);
    }
    wda_qmi_client_release(lVar3);
    qmi_rmnet_work_exit(param_2);
    rmnet_ll_wq_exit();
    if (lVar3 != 0) {
      wda_qmi_client_exit(lVar3);
      *(long *)(param_1 + 8) = 0;
      *(undefined8 *)(param_1 + 0x10) = 0;
    }
    iVar2 = __qmi_rmnet_delete_client(param_2,param_1,0);
    if (iVar2 != 0) {
      __qmi_rmnet_delete_client(param_2,param_1,1);
    }
  }
  return;
}



//------------------------------------------------------------
// __qmi_rmnet_delete_client @ 0011b270 size=252
// signature: undefined __qmi_rmnet_delete_client(void)
// callers: [qmi_rmnet_qmi_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

undefined8 __qmi_rmnet_delete_client(undefined8 param_1,long param_2,ulong param_3)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long *plVar4;
  
  param_3 = param_3 & 0xffffffff;
  iVar2 = rtnl_is_locked();
  if ((iVar2 == 0) && ((__qmi_rmnet_delete_client___already_done & 1) == 0)) {
    __qmi_rmnet_delete_client___already_done = 1;
    __warn_printk("RTNL: assertion failed at %s (%d)\n",
                  "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x2a5);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11b36c);
    (*pcVar1)();
  }
  plVar4 = (long *)(param_2 + param_3 * 8 + 0x18);
  if ((*plVar4 != 0) || (*(long *)(param_2 + param_3 * 8 + 0x28) != 0)) {
    if (dfc_qmap == 0) {
      dfc_qmi_client_exit();
    }
    else {
      dfc_qmap_client_exit();
    }
    *plVar4 = 0;
    *(undefined8 *)(param_2 + param_3 * 8 + 0x28) = 0;
  }
  if (((*(long *)(param_2 + 8) == 0) &&
      (((param_2 == 0 || ((*(long *)(param_2 + 0x18) == 0 && (*(long *)(param_2 + 0x20) == 0)))) &&
       (*(long *)(param_2 + 0x10) == 0)))) &&
     ((*(long *)(param_2 + 0x28) == 0 && (*(long *)(param_2 + 0x30) == 0)))) {
    rmnet_reset_qmi_pt(param_1);
    kfree(param_2);
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  return uVar3;
}



//------------------------------------------------------------
// qmi_rmnet_enable_all_flows @ 0011b374 size=208
// signature: undefined qmi_rmnet_enable_all_flows(void)
// callers: [rmnet_enable_all_flows]
//------------------------------------------------------------

void qmi_rmnet_enable_all_flows(undefined8 param_1)

{
  int iVar1;
  bool bVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = rmnet_get_qos_pt();
  if (lVar3 != 0) {
    _raw_spin_lock_bh(lVar3 + 0x14c);
    for (plVar4 = *(long **)(lVar3 + 0x38); plVar4 != (long *)(lVar3 + 0x38);
        plVar4 = (long *)*plVar4) {
      *(undefined2 *)(plVar4 + 4) = 0;
      *(undefined1 *)((long)plVar4 + 0x22) = 0;
      *(undefined4 *)((long)plVar4 + 0x2c) = 0;
      *(undefined2 *)((long)plVar4 + 0x34) = 0;
      qmi_rmnet_watchdog_remove(plVar4);
      if (*(char *)((long)plVar4 + 0x36) == '\0') {
        bVar2 = qmi_rmnet_scale_factor == 1;
        iVar1 = *(int *)(plVar4 + 3);
        *(undefined4 *)(plVar4 + 3) = 1;
        *(uint *)((long)plVar4 + 0x1c) = (uint)bVar2;
        if (iVar1 == 0) {
          dfc_bearer_flow_ctl(param_1,plVar4,lVar3);
        }
      }
    }
    _raw_spin_unlock_bh(lVar3 + 0x14c);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_grant_per @ 0011b448 size=16
// signature: undefined qmi_rmnet_grant_per(void)
// callers: [dfc_handle_tx_link_status_ind, dfc_all_bearer_flow_ctl, dfc_do_burst_flow_control]
//------------------------------------------------------------

uint qmi_rmnet_grant_per(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (qmi_rmnet_scale_factor != 0) {
    uVar1 = param_1 / qmi_rmnet_scale_factor;
  }
  return uVar1;
}



//------------------------------------------------------------
// qmi_rmnet_all_flows_enabled @ 0011b45c size=108
// signature: undefined qmi_rmnet_all_flows_enabled(void)
// callers: [rmnet_all_flows_enabled]
//------------------------------------------------------------

bool qmi_rmnet_all_flows_enabled(void)

{
  bool bVar1;
  long lVar2;
  long *plVar3;
  
  lVar2 = rmnet_get_qos_pt();
  if (lVar2 == 0) {
    bVar1 = true;
  }
  else {
    _raw_spin_lock_bh(lVar2 + 0x14c);
    plVar3 = (long *)(lVar2 + 0x38);
    do {
      plVar3 = (long *)*plVar3;
      bVar1 = plVar3 == (long *)(lVar2 + 0x38);
      if (bVar1) break;
    } while (*(int *)(plVar3 + 3) != 0);
    _raw_spin_unlock_bh(lVar2 + 0x14c);
  }
  return bVar1;
}



//------------------------------------------------------------
// qmi_rmnet_prepare_ps_bearers @ 0011b4cc size=268
// signature: undefined qmi_rmnet_prepare_ps_bearers(void)
// callers: [rmnet_prepare_ps_bearers]
//------------------------------------------------------------

void qmi_rmnet_prepare_ps_bearers(undefined8 param_1,byte *param_2,long param_3)

{
  bool bVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  byte bVar5;
  byte bVar6;
  
  lVar2 = rmnet_get_qos_pt();
  if ((param_2 != (byte *)0x0) && (lVar2 != 0)) {
    _raw_spin_lock_bh(lVar2 + 0x14c);
    plVar3 = (long *)(lVar2 + 0x38);
    plVar4 = (long *)*plVar3;
    if (plVar4 == plVar3) {
      bVar5 = 0;
    }
    else {
      bVar5 = 0;
      bVar6 = *param_2;
      do {
        if ((int)plVar4[3] == 0) {
          if (bVar6 == 0) {
            _printk(&DAT_00120ab1);
            bVar6 = 0;
          }
          else {
            if (param_3 != 0) {
              *(char *)(param_3 + (ulong)bVar5) = (char)plVar4[2];
            }
            bVar5 = bVar5 + 1;
            bVar6 = bVar6 - 1;
          }
        }
        else {
          *(undefined2 *)(plVar4 + 4) = 0;
          *(undefined1 *)((long)plVar4 + 0x22) = 0;
          *(undefined4 *)((long)plVar4 + 0x2c) = 0;
          *(undefined2 *)((long)plVar4 + 0x34) = 0;
          qmi_rmnet_watchdog_remove(plVar4);
          bVar1 = qmi_rmnet_scale_factor == 1;
          *(undefined4 *)(plVar4 + 3) = 1;
          *(uint *)((long)plVar4 + 0x1c) = (uint)bVar1;
        }
        plVar4 = (long *)*plVar4;
      } while (plVar4 != plVar3);
    }
    *param_2 = bVar5;
    _raw_spin_unlock_bh(lVar2 + 0x14c);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_get_flow_state @ 0011b5dc size=172
// signature: undefined qmi_rmnet_get_flow_state(void)
// callers: [rmnet_vnd_start_xmit]
//------------------------------------------------------------

bool qmi_rmnet_get_flow_state
               (undefined8 param_1,long param_2,undefined8 param_3,undefined1 *param_4)

{
  bool bVar1;
  ushort uVar2;
  code *pcVar3;
  bool bVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  
  lVar5 = rmnet_get_qos_pt();
  uVar2 = *(ushort *)(param_2 + 0x7c);
  uVar6 = uVar2 - 0xf;
  if (uVar2 < 0xf || uVar6 == 0) {
    uVar6 = (uint)uVar2;
  }
  uVar7 = (ulong)uVar6;
  bVar1 = lVar5 != 0 && (int)uVar6 < 0x10;
  if (bVar1) {
    if (uVar6 == 0) {
      uVar7 = 0;
      bVar4 = false;
    }
    else {
      if (0xf < uVar6) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11b688);
        (*pcVar3)();
      }
      if (*(long *)(lVar5 + (ulong)uVar6 * 0x10 + 0x48) == 0) {
        bVar4 = *(char *)(lVar5 + uVar7 * 0x10 + 0x51) != '\0';
      }
      else {
        bVar4 = false;
      }
    }
    *(bool *)param_3 = bVar4;
    *param_4 = *(undefined1 *)(lVar5 + uVar7 * 0x10 + 0x50);
  }
  return bVar1;
}



//------------------------------------------------------------
// qmi_rmnet_burst_fc_check @ 0011b68c size=88
// signature: undefined qmi_rmnet_burst_fc_check(void)
// callers: [rmnet_vnd_start_xmit]
//------------------------------------------------------------

void qmi_rmnet_burst_fc_check
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  
  lVar1 = rmnet_get_qos_pt();
  if (lVar1 != 0) {
    dfc_qmi_burst_check(param_1,lVar1,param_2,param_3,param_4);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_get_queue @ 0011b6e8 size=516
// signature: undefined qmi_rmnet_get_queue(void)
// callers: [rmnet_vnd_select_queue]
//------------------------------------------------------------

undefined4 qmi_rmnet_get_queue(undefined8 param_1,long param_2)

{
  byte *pbVar1;
  int iVar2;
  ushort uVar3;
  long lVar4;
  int iVar5;
  long *plVar6;
  uint uVar7;
  long lVar8;
  undefined4 uVar9;
  long *plVar10;
  
  lVar4 = rmnet_get_qos_pt();
  if (lVar4 == 0) {
    return 0;
  }
  if (dfc_mode == 4) {
    if (*(short *)(param_2 + 0xb4) == -0x227a) {
      if ((*(char *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8) + 6) == ':') &&
         ((byte)(*(char *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb6)) + 0x7bU)
          < 5)) {
        return 0;
      }
      iVar5 = 10;
    }
    else {
      iVar5 = 2;
    }
    _raw_spin_lock_bh(lVar4 + 0x14c);
    plVar10 = (long *)(lVar4 + 0x28);
    plVar6 = (long *)*plVar10;
    if (plVar6 != plVar10) {
      do {
        if ((*(int *)((long)plVar6 + 0x14) == *(int *)(param_2 + 0xa8)) && ((int)plVar6[3] == iVar5)
           ) {
          if (plVar6 != (long *)0x0) {
            if (plVar6[4] == 0) goto LAB_0011b864;
            if (*(int *)(param_2 + 0xe8) != 2) {
              if (*(short *)(param_2 + 0xb4) == -0x227a) {
                lVar8 = *(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8);
                if (*(char *)(lVar8 + 6) != '\x06') goto LAB_0011b864;
                uVar3 = *(ushort *)(lVar8 + 4);
                lVar8 = 0x28;
                uVar7 = (uint)(uVar3 >> 8) | (uVar3 & 0xff00ff) << 8;
              }
              else {
                if ((*(short *)(param_2 + 0xb4) != 8) ||
                   (pbVar1 = (byte *)(*(long *)(param_2 + 0xd8) + (ulong)*(ushort *)(param_2 + 0xb8)
                                     ), pbVar1[9] != 6)) goto LAB_0011b864;
                lVar8 = ((ulong)*pbVar1 & 0xf) << 2;
                uVar7 = ((uint)(*(ushort *)(pbVar1 + 2) >> 8) |
                        (*(ushort *)(pbVar1 + 2) & 0xff00ff) << 8) - (int)lVar8;
              }
              if (uVar7 != (*(ushort *)(*(long *)(param_2 + 0xe0) + lVar8 + 0xc) >> 2 & 0x3c))
              goto LAB_0011b864;
            }
            uVar9 = *(undefined4 *)(plVar6[4] + 0x40);
            goto LAB_0011b8a0;
          }
          break;
        }
        plVar6 = (long *)*plVar6;
      } while (plVar6 != plVar10);
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0xa8);
    iVar5 = 10;
    if (*(short *)(param_2 + 0xb4) != -0x227a) {
      iVar5 = 2;
    }
    _raw_spin_lock_bh(lVar4 + 0x14c);
    for (plVar6 = *(long **)(lVar4 + 0x28); plVar6 != (long *)(lVar4 + 0x28);
        plVar6 = (long *)*plVar6) {
      if ((*(int *)((long)plVar6 + 0x14) == iVar2) && (*(int *)(plVar6 + 3) == iVar5)) {
        if (plVar6 != (long *)0x0) goto LAB_0011b864;
        break;
      }
    }
  }
  uVar9 = 0;
LAB_0011b8a0:
  _raw_spin_unlock_bh(lVar4 + 0x14c);
  return uVar9;
LAB_0011b864:
  uVar9 = *(undefined4 *)((long)plVar6 + 0x1c);
  goto LAB_0011b8a0;
}



//------------------------------------------------------------
// qmi_rmnet_qos_init @ 0011b8f0 size=112
// signature: undefined qmi_rmnet_qos_init(void)
// callers: [rmnet_vnd_newlink]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qmi_rmnet_qos_init(undefined8 param_1,undefined8 param_2,undefined1 param_3)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_netdev_rx_handler_register,0xdc0,0x158);
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x10) = param_3;
    *(undefined8 *)(lVar1 + 0x18) = param_1;
    *(undefined8 *)(lVar1 + 0x20) = param_2;
    *(undefined8 *)(lVar1 + 0x148) = 0;
    *(long *)(lVar1 + 0x28) = lVar1 + 0x28;
    *(long *)(lVar1 + 0x30) = lVar1 + 0x28;
    *(long *)(lVar1 + 0x38) = lVar1 + 0x38;
    *(long *)(lVar1 + 0x40) = lVar1 + 0x38;
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_qos_exit_pre @ 0011b964 size=152
// signature: undefined qmi_rmnet_qos_exit_pre(void)
// callers: [rmnet_vnd_uninit]
//------------------------------------------------------------

void qmi_rmnet_qos_exit_pre(long *param_1)

{
  undefined *puVar1;
  ulong uVar2;
  long *plVar3;
  
  if (param_1 != (long *)0x0) {
    puVar1 = qos_cleanup_list;
    for (plVar3 = (long *)param_1[7]; qos_cleanup_list = puVar1, plVar3 != param_1 + 7;
        plVar3 = (long *)*plVar3) {
      *(undefined1 *)((long)plVar3 + 0x89) = 1;
      del_timer_sync(plVar3 + 10);
      *(undefined1 *)((long)plVar3 + 0xa4) = 1;
      del_timer_sync(plVar3 + 0x15);
      puVar1 = qos_cleanup_list;
    }
    uVar2 = __list_add_valid(param_1,&qos_cleanup_list,puVar1);
    if ((uVar2 & 1) != 0) {
      *(long **)(puVar1 + 8) = param_1;
      *param_1 = (long)puVar1;
      param_1[1] = (long)&qos_cleanup_list;
      qos_cleanup_list = (undefined *)param_1;
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_qos_exit_post @ 0011ba00 size=440
// signature: undefined qmi_rmnet_qos_exit_post(void)
// callers: [rmnet_dellink, rmnet_config_notify_cb]
//------------------------------------------------------------

void qmi_rmnet_qos_exit_post(void)

{
  undefined *puVar1;
  long *plVar2;
  undefined **ppuVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  
  synchronize_rcu();
  ppuVar7 = (undefined **)qos_cleanup_list;
  if ((undefined **)qos_cleanup_list != &qos_cleanup_list) {
    do {
      ppuVar9 = (undefined **)*ppuVar7;
      uVar6 = __list_del_entry_valid(ppuVar7);
      if ((uVar6 & 1) != 0) {
        puVar1 = *ppuVar7;
        plVar2 = (long *)ppuVar7[1];
        *(long **)(puVar1 + 8) = plVar2;
        *plVar2 = (long)puVar1;
      }
      *ppuVar7 = (undefined *)0xdead000000000100;
      ppuVar7[1] = (undefined *)0xdead000000000122;
      iVar5 = rtnl_is_locked();
      if ((iVar5 == 0) && ((qmi_rmnet_clean_flow_list___already_done & 1) == 0)) {
        qmi_rmnet_clean_flow_list___already_done = 1;
        __warn_printk("RTNL: assertion failed at %s (%d)\n",
                      "../vendor/qcom/opensource/datarmnet/core/qmi_rmnet.c",0x9e);
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x11bb98);
        (*pcVar4)();
      }
      ppuVar3 = (undefined **)ppuVar7[5];
      while (ppuVar3 != ppuVar7 + 5) {
        ppuVar8 = (undefined **)*ppuVar3;
        uVar6 = __list_del_entry_valid(ppuVar3);
        if ((uVar6 & 1) != 0) {
          puVar1 = *ppuVar3;
          plVar2 = (long *)ppuVar3[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar3 = (undefined *)0xdead000000000100;
        ppuVar3[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar3);
        ppuVar3 = ppuVar8;
      }
      ppuVar3 = (undefined **)ppuVar7[7];
      while (ppuVar3 != ppuVar7 + 7) {
        ppuVar8 = (undefined **)*ppuVar3;
        uVar6 = __list_del_entry_valid(ppuVar3);
        if ((uVar6 & 1) != 0) {
          puVar1 = *ppuVar3;
          plVar2 = (long *)ppuVar3[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar3 = (undefined *)0xdead000000000100;
        ppuVar3[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar3);
        ppuVar3 = ppuVar8;
      }
      ppuVar7[0x27] = (undefined *)0x0;
      ppuVar7[0x28] = (undefined *)0x0;
      ppuVar7[0x25] = (undefined *)0x0;
      ppuVar7[0x26] = (undefined *)0x0;
      ppuVar7[0x23] = (undefined *)0x0;
      ppuVar7[0x24] = (undefined *)0x0;
      ppuVar7[0x21] = (undefined *)0x0;
      ppuVar7[0x22] = (undefined *)0x0;
      ppuVar7[0x1f] = (undefined *)0x0;
      ppuVar7[0x20] = (undefined *)0x0;
      ppuVar7[0x1d] = (undefined *)0x0;
      ppuVar7[0x1e] = (undefined *)0x0;
      ppuVar7[0x1b] = (undefined *)0x0;
      ppuVar7[0x1c] = (undefined *)0x0;
      ppuVar7[0x19] = (undefined *)0x0;
      ppuVar7[0x1a] = (undefined *)0x0;
      ppuVar7[0x17] = (undefined *)0x0;
      ppuVar7[0x18] = (undefined *)0x0;
      ppuVar7[0x15] = (undefined *)0x0;
      ppuVar7[0x16] = (undefined *)0x0;
      ppuVar7[0x13] = (undefined *)0x0;
      ppuVar7[0x14] = (undefined *)0x0;
      ppuVar7[0x11] = (undefined *)0x0;
      ppuVar7[0x12] = (undefined *)0x0;
      ppuVar7[0xf] = (undefined *)0x0;
      ppuVar7[0x10] = (undefined *)0x0;
      ppuVar7[0xd] = (undefined *)0x0;
      ppuVar7[0xe] = (undefined *)0x0;
      ppuVar7[0xb] = (undefined *)0x0;
      ppuVar7[0xc] = (undefined *)0x0;
      ppuVar7[9] = (undefined *)0x0;
      ppuVar7[10] = (undefined *)0x0;
      kfree(ppuVar7);
      ppuVar7 = ppuVar9;
    } while (ppuVar9 != &qos_cleanup_list);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_ps_on_notify @ 0011bbc0 size=112
// signature: undefined qmi_rmnet_ps_on_notify(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_ps_on_notify(undefined8 param_1)

{
  code *pcVar1;
  undefined **ppuVar2;
  
  ppuVar2 = (undefined **)ps_list;
  if ((undefined **)ps_list != &ps_list) {
    do {
      if (*(int *)(ppuVar2[-2] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11bc0c);
        (*pcVar1)();
      }
      (*(code *)ppuVar2[-2])(param_1);
      ppuVar2 = (undefined **)*ppuVar2;
    } while (ppuVar2 != &ps_list);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_ps_off_notify @ 0011bc34 size=112
// signature: undefined qmi_rmnet_ps_off_notify(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_ps_off_notify(undefined8 param_1)

{
  code *pcVar1;
  undefined **ppuVar2;
  
  ppuVar2 = (undefined **)ps_list;
  if ((undefined **)ps_list != &ps_list) {
    do {
      if (*(int *)(ppuVar2[-1] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11bc80);
        (*pcVar1)();
      }
      (*(code *)ppuVar2[-1])(param_1);
      ppuVar2 = (undefined **)*ppuVar2;
    } while (ppuVar2 != &ps_list);
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_register @ 0011bca8 size=136
// signature: undefined qmi_rmnet_ps_ind_register(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_rmnet_ps_ind_register(long param_1,long *param_2)

{
  long *plVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  puVar2 = ps_list;
  uVar3 = 0xffffffea;
  if ((((param_1 != 0) && (param_2 != (long *)0x0)) && (*param_2 != 0)) && (param_2[1] != 0)) {
    plVar1 = param_2 + 2;
    uVar4 = __list_add_valid(plVar1,&ps_list,ps_list);
    if ((uVar4 & 1) == 0) {
      uVar3 = 0;
    }
    else {
      param_2[2] = (long)puVar2;
      param_2[3] = (long)&ps_list;
      uVar3 = 0;
      ps_list = (undefined *)plVar1;
      *(long **)(puVar2 + 8) = plVar1;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qmi_rmnet_ps_ind_deregister @ 0011bd34 size=136
// signature: undefined qmi_rmnet_ps_ind_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_rmnet_ps_ind_deregister(long param_1,undefined **param_2)

{
  undefined *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  uVar3 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != (undefined **)0x0)) {
    ppuVar5 = &ps_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &ps_list) {
        return 0;
      }
    } while (ppuVar5 + -2 != param_2);
    uVar4 = __list_del_entry_valid(param_2 + 2);
    if ((uVar4 & 1) != 0) {
      puVar1 = param_2[2];
      plVar2 = (long *)param_2[3];
      *(long **)(puVar1 + 8) = plVar2;
      *plVar2 = (long)puVar1;
    }
    uVar3 = 0;
    param_2[3] = (undefined *)0xdead000000000122;
  }
  return uVar3;
}



//------------------------------------------------------------
// qmi_rmnet_set_powersave_mode @ 0011bdc0 size=140
// signature: undefined qmi_rmnet_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

int qmi_rmnet_set_powersave_mode
              (undefined8 param_1,uint param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  
  lVar2 = rmnet_get_qmi_pt();
  if ((lVar2 == 0) || (*(long *)(lVar2 + 8) == 0)) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = wda_set_powersave_mode(*(long *)(lVar2 + 8),param_2,param_3,param_4);
    if (iVar1 < 0) {
      _printk(&DAT_00120d84,"qmi_rmnet_set_powersave_mode",param_2 & 0xff,iVar1);
    }
    else {
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// qmi_rmnet_check_stats_2 @ 0011be50 size=716
// signature: undefined qmi_rmnet_check_stats_2(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_check_stats_2(long param_1)

{
  ulong *puVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  undefined1 uVar5;
  code *pcVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined **ppuVar12;
  undefined1 local_4c [4];
  long local_48;
  long lStack_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_48 = 0;
  lStack_40 = 0;
  if ((*(long *)(param_1 + 0x88) == 0) || (lVar8 = rmnet_get_qmi_pt(), lVar8 == 0))
  goto LAB_0011c068;
  rmnet_get_packets(*(undefined8 *)(param_1 + 0x88),&lStack_40,&local_48);
  lVar9 = *(long *)(param_1 + 0x90);
  lVar2 = *(long *)(param_1 + 0x98);
  *(long *)(param_1 + 0x90) = lStack_40;
  *(long *)(param_1 + 0x98) = local_48;
  if (*(char *)(lVar8 + 0x48) == '\0') {
    if ((lStack_40 == lVar9) && (local_48 == lVar2)) {
      *(undefined1 *)(lVar8 + 0x4a) = 1;
      *(undefined1 *)(lVar8 + 0x48) = 1;
      rmnet_module_hook_aps_data_inactive();
      puVar1 = (ulong *)(lVar8 + 0x40);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xfffffffffffffffe;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
      local_4c[0] = 0x20;
      ps_bearer_id = 0;
      DAT_00128e32 = 0;
      DAT_00128e3a = 0;
      DAT_00128e42 = 0;
      rmnet_prepare_ps_bearers(*(undefined8 *)(param_1 + 0x88),local_4c);
      uVar5 = local_4c[0];
      if (dfc_qmap == 0) {
        lVar8 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + 0x88));
        if (((lVar8 != 0) && (*(long *)(lVar8 + 8) != 0)) &&
           (iVar7 = wda_set_powersave_mode(*(long *)(lVar8 + 8),1,uVar5,&ps_bearer_id), iVar7 < 0))
        {
          _printk(&DAT_00120d84,"qmi_rmnet_set_powersave_mode",1,iVar7);
        }
      }
      else {
        dfc_qmap_set_powersave(1,local_4c[0],&ps_bearer_id);
      }
      iVar7 = rmnet_get_powersave_notif(*(undefined8 *)(param_1 + 0x88));
      if ((iVar7 != 0) &&
         (uVar11 = *(undefined8 *)(param_1 + 0x88), ppuVar12 = (undefined **)ps_list,
         (undefined **)ps_list != &ps_list)) {
        do {
          if (*(int *)(ppuVar12[-2] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11bf98);
            (*pcVar6)();
          }
          (*(code *)ppuVar12[-2])(uVar11);
          ppuVar12 = (undefined **)*ppuVar12;
        } while (ppuVar12 != &ps_list);
      }
      goto LAB_0011c068;
    }
  }
  else {
    *(undefined1 *)(lVar8 + 0x4a) = 0;
    if (dfc_qmap == 0) {
      lVar9 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + 0x88));
      if ((lVar9 != 0) && (*(long *)(lVar9 + 8) != 0)) {
        iVar7 = wda_set_powersave_mode(*(long *)(lVar9 + 8),0,0,0);
        if (-1 < iVar7) goto LAB_0011bfd4;
        _printk(&DAT_00120d84,"qmi_rmnet_set_powersave_mode",0,iVar7);
      }
    }
    else {
      iVar7 = dfc_qmap_set_powersave(0,0,0);
      if (iVar7 == 0) {
LAB_0011bfd4:
        *(undefined1 *)(lVar8 + 0x48) = 0;
        iVar7 = rmnet_get_powersave_notif(*(undefined8 *)(param_1 + 0x88));
        if (iVar7 != 0) {
          uVar11 = *(undefined8 *)(param_1 + 0x88);
          for (ppuVar12 = (undefined **)ps_list; ppuVar12 != &ps_list;
              ppuVar12 = (undefined **)*ppuVar12) {
            if (*(int *)(ppuVar12[-1] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11c01c);
              (*pcVar6)();
            }
            (*(code *)ppuVar12[-1])(uVar11);
          }
        }
      }
    }
  }
  __rcu_read_lock();
  uVar11 = rmnet_ps_wq;
  if ((rmnet_work_quit & 1) == 0) {
    uVar10 = __msecs_to_jiffies(rmnet_wq_frequency);
    queue_delayed_work_on(0x20,uVar11,param_1,uVar10);
  }
  __rcu_read_unlock();
LAB_0011c068:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_check_stats @ 0011c12c size=704
// signature: undefined qmi_rmnet_check_stats(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_check_stats(long param_1)

{
  ulong *puVar1;
  long lVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined **ppuVar12;
  long local_48;
  long lStack_40;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_48 = 0;
  lStack_40 = 0;
  if (((param_1 == 0) || (*(long *)(param_1 + 0x88) == 0)) ||
     (lVar7 = rmnet_get_qmi_pt(), lVar7 == 0)) goto LAB_0011c38c;
  rmnet_get_packets(*(undefined8 *)(param_1 + 0x88),&lStack_40,&local_48);
  lVar8 = *(long *)(param_1 + 0x90);
  lVar2 = *(long *)(param_1 + 0x98);
  *(long *)(param_1 + 0x90) = lStack_40;
  *(long *)(param_1 + 0x98) = local_48;
  cVar3 = *(char *)(lVar7 + 0x49);
  *(undefined1 *)(lVar7 + 0x49) = 0;
  if (*(char *)(lVar7 + 0x48) == '\0') {
    if ((((lStack_40 == lVar8) && (local_48 == lVar2)) &&
        ((cVar3 != '\0' ||
         (uVar9 = rmnet_all_flows_enabled(*(undefined8 *)(param_1 + 0x88)), (uVar9 & 1) != 0)))) &&
       ((lVar8 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + 0x88)), lVar8 != 0 &&
        (*(long *)(lVar8 + 8) != 0)))) {
      iVar6 = wda_set_powersave_mode(*(long *)(lVar8 + 8),1,0,0);
      if (-1 < iVar6) {
        *(undefined1 *)(lVar7 + 0x48) = 1;
        *(undefined1 *)(lVar7 + 0x4a) = 1;
        puVar1 = (ulong *)(lVar7 + 0x40);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 & 0xfffffffffffffffe;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        rmnet_enable_all_flows(*(undefined8 *)(param_1 + 0x88));
        iVar6 = rmnet_get_powersave_notif(*(undefined8 *)(param_1 + 0x88));
        if ((iVar6 != 0) &&
           (uVar11 = *(undefined8 *)(param_1 + 0x88), ppuVar12 = (undefined **)ps_list,
           (undefined **)ps_list != &ps_list)) {
          do {
            if (*(int *)(ppuVar12[-2] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11c30c);
              (*pcVar5)();
            }
            (*(code *)ppuVar12[-2])(uVar11);
            ppuVar12 = (undefined **)*ppuVar12;
          } while (ppuVar12 != &ps_list);
        }
        goto LAB_0011c38c;
      }
      uVar11 = 1;
LAB_0011c34c:
      _printk(&DAT_00120d84,"qmi_rmnet_set_powersave_mode",uVar11,iVar6);
    }
  }
  else {
    *(undefined1 *)(lVar7 + 0x4a) = 0;
    lVar8 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + 0x88));
    if ((lVar8 != 0) && (*(long *)(lVar8 + 8) != 0)) {
      iVar6 = wda_set_powersave_mode(*(long *)(lVar8 + 8),0,0,0);
      if (iVar6 < 0) {
        uVar11 = 0;
        goto LAB_0011c34c;
      }
      *(undefined1 *)(lVar7 + 0x48) = 0;
      iVar6 = dfc_qmap;
      if ((*(long *)(lVar7 + 0x18) == 0) || (dfc_qmap != 0)) {
LAB_0011c1ec:
        lVar8 = *(long *)(lVar7 + 0x20);
      }
      else {
        if (*(char *)(lVar7 + 0x38) != '\0') {
          iVar6 = 0;
          goto LAB_0011c1ec;
        }
        dfc_qmi_query_flow();
        lVar8 = *(long *)(lVar7 + 0x20);
        iVar6 = dfc_qmap;
      }
      if (((lVar8 != 0) && (iVar6 == 0)) && (*(char *)(lVar7 + 0x39) == '\0')) {
        dfc_qmi_query_flow();
      }
      iVar6 = rmnet_get_powersave_notif(*(undefined8 *)(param_1 + 0x88));
      if ((iVar6 != 0) &&
         (uVar11 = *(undefined8 *)(param_1 + 0x88), ppuVar12 = (undefined **)ps_list,
         (undefined **)ps_list != &ps_list)) {
        do {
          if (*(int *)(ppuVar12[-1] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11c248);
            (*pcVar5)();
          }
          (*(code *)ppuVar12[-1])(uVar11);
          ppuVar12 = (undefined **)*ppuVar12;
        } while (ppuVar12 != &ps_list);
      }
    }
  }
  __rcu_read_lock();
  uVar11 = rmnet_ps_wq;
  if ((rmnet_work_quit & 1) == 0) {
    uVar10 = __msecs_to_jiffies(rmnet_wq_frequency);
    queue_delayed_work_on(0x20,uVar11,param_1,uVar10);
  }
  __rcu_read_unlock();
LAB_0011c38c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_work_maybe_restart @ 0011c3fc size=172
// signature: undefined qmi_rmnet_work_maybe_restart(void)
// callers: [rmnet_frag_ingress_handler, rmnet_vnd_start_xmit, __rmnet_map_ingress_handler, rmnet_egress_handler]
//------------------------------------------------------------

void qmi_rmnet_work_maybe_restart(undefined8 param_1,long param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = rmnet_get_qmi_pt();
  if ((lVar4 != 0) && (rmnet_work_inited != '\0')) {
    puVar1 = (ulong *)(lVar4 + 0x40);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar5 = *puVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = uVar5 | 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar5 & 1) == 0) {
      *(undefined1 *)(lVar4 + 0x4a) = 0;
      __rcu_read_lock();
      if ((rmnet_work_quit & 1) == 0) {
        queue_delayed_work_on(0x20,rmnet_ps_wq,rmnet_work,0);
      }
      __rcu_read_unlock();
      if (param_2 != 0 || param_3 != 0) {
        rmnet_module_hook_aps_data_active(param_2,param_3);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_set_dl_msg_active @ 0011c4bc size=40
// signature: undefined qmi_rmnet_set_dl_msg_active(void)
// callers: [dfc_qmi_ind_work, dfc_qmap_cmd_handler, rmnet_frag_ingress_handler, __rmnet_map_ingress_handler]
//------------------------------------------------------------

void qmi_rmnet_set_dl_msg_active(void)

{
  long lVar1;
  
  lVar1 = rmnet_get_qmi_pt();
  if (lVar1 != 0) {
    *(undefined1 *)(lVar1 + 0x49) = 1;
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_flush_ps_wq @ 0011c4e8 size=40
// signature: undefined qmi_rmnet_flush_ps_wq(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_flush_ps_wq(void)

{
  if (rmnet_ps_wq != 0) {
    __flush_workqueue();
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_ignore_grant @ 0011c514 size=44
// signature: undefined qmi_rmnet_ignore_grant(void)
// callers: [dfc_do_burst_flow_control]
//------------------------------------------------------------

bool qmi_rmnet_ignore_grant(void)

{
  bool bVar1;
  long lVar2;
  
  lVar2 = rmnet_get_qmi_pt();
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = *(char *)(lVar2 + 0x4a) != '\0';
  }
  return bVar1;
}



//------------------------------------------------------------
// qmi_rmnet_watchdog_fn @ 0011c544 size=172
// signature: undefined qmi_rmnet_watchdog_fn(void)
// callers: []
//------------------------------------------------------------

void qmi_rmnet_watchdog_fn(long param_1)

{
  uint uVar1;
  
  _raw_spin_lock_bh(*(long *)(param_1 + -8) + 0x14c,*(undefined1 *)(*(long *)(param_1 + -8) + 0x10),
                    *(undefined1 *)(param_1 + -0x40));
  if (*(char *)(param_1 + 0x39) == '\0') {
    *(undefined4 *)(param_1 + -0x24) = 0;
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 1;
    if (*(uint *)(param_1 + -0x38) == 0) {
      *(undefined4 *)(param_1 + -0x38) = 0x5000;
      uVar1 = 0;
      if (qmi_rmnet_scale_factor != 0) {
        uVar1 = 0x5000 / qmi_rmnet_scale_factor;
      }
      *(uint *)(param_1 + -0x34) = uVar1;
      dfc_bearer_flow_ctl(*(undefined8 *)(*(long *)(param_1 + -8) + 0x20),param_1 + -0x50);
    }
    else {
      uVar1 = 0;
      if (qmi_rmnet_scale_factor != 0) {
        uVar1 = *(uint *)(param_1 + -0x38) / qmi_rmnet_scale_factor;
      }
      *(uint *)(param_1 + -0x34) = uVar1;
    }
  }
  *(undefined1 *)(param_1 + 0x38) = 0;
  _raw_spin_unlock_bh(*(long *)(param_1 + -8) + 0x14c);
  return;
}



//------------------------------------------------------------
// __qmi_rmnet_update_mq @ 0011c658 size=236
// signature: undefined __qmi_rmnet_update_mq(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void __qmi_rmnet_update_mq(undefined8 param_1,long param_2,long param_3,long param_4)

{
  uint uVar1;
  char cVar2;
  code *pcVar3;
  bool bVar4;
  
  uVar1 = *(uint *)(param_4 + 0x1c);
  if (dfc_mode != 4 || uVar1 != 0) {
    if (0x10 < uVar1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11c744);
      (*pcVar3)();
    }
    param_2 = param_2 + (ulong)uVar1 * 0x10;
    if (*(long *)(param_2 + 0x48) == 0) {
      *(long *)(param_2 + 0x48) = param_3;
      cVar2 = *(char *)(param_3 + 0x90);
      *(undefined1 *)(param_2 + 0x51) = 0;
      *(bool *)(param_2 + 0x50) = cVar2 != '\0';
      DataMemoryBarrier(2,3);
      bVar4 = dfc_mode == 4;
      *(undefined4 *)(param_3 + 0x3c) = *(undefined4 *)(param_4 + 0x1c);
      if (bVar4) {
        *(int *)(param_3 + 0x40) = *(int *)(param_4 + 0x1c) + 0xf;
      }
      if (*(int *)(param_3 + 0x18) == 0) {
        bVar4 = qmi_rmnet_scale_factor == 1;
        *(undefined4 *)(param_3 + 0x18) = 1;
        *(uint *)(param_3 + 0x1c) = (uint)bVar4;
      }
      qmi_rmnet_flow_control(param_1,*(undefined4 *)(param_4 + 0x1c),1);
      if (dfc_mode == 4) {
        qmi_rmnet_flow_control(param_1,*(undefined4 *)(param_3 + 0x40),1);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// __qmi_rmnet_bearer_put @ 0011c744 size=248
// signature: undefined __qmi_rmnet_bearer_put(void)
// callers: [qmi_rmnet_del_flow, qmi_rmnet_change_link]
//------------------------------------------------------------

void __qmi_rmnet_bearer_put(undefined8 param_1,long param_2,long *param_3,byte param_4)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  
  if ((param_3 != (long *)0x0) &&
     (iVar3 = *(int *)((long)param_3 + 0x14) + -1, *(int *)((long)param_3 + 0x14) = iVar3,
     iVar3 == 0)) {
    uVar4 = 0;
    puVar5 = (undefined8 *)(param_2 + 0x48);
    do {
      if ((long *)*puVar5 == param_3) {
        *puVar5 = 0;
        *(undefined1 *)(puVar5 + 1) = 0;
        *(byte *)((long)puVar5 + 9) = param_4 & 1;
        DataMemoryBarrier(2,3);
        qmi_rmnet_flow_control(param_1,uVar4 & 0xffffffff,1);
        if (dfc_mode == 4) {
          qmi_rmnet_flow_control(param_1,(int)uVar4 + 0xf,1);
        }
      }
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 2;
    } while (uVar4 != 0x10);
    uVar4 = __list_del_entry_valid(param_3);
    if ((uVar4 & 1) != 0) {
      lVar1 = *param_3;
      plVar2 = (long *)param_3[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *param_3 = -0x2152ffffffffff00;
    param_3[1] = -0x2152fffffffffede;
    *(long **)(param_2 + 0x150) = param_3;
  }
  return;
}



//------------------------------------------------------------
// qmi_rmnet_pm_notify_cb @ 0011c840 size=432
// signature: undefined qmi_rmnet_pm_notify_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qmi_rmnet_pm_notify_cb(long param_1,long param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined1 uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  undefined **ppuVar8;
  undefined1 local_3c [4];
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + -0x158);
  if (param_2 == 4) {
    puVar1 = (ulong *)(lVar7 + 0x40);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffffe;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  else if ((param_2 == 3) && (cancel_delayed_work_sync(rmnet_work), *(char *)(lVar7 + 0x48) == '\0')
          ) {
    param_1 = param_1 + -0xb30;
    *(undefined1 *)(lVar7 + 0x4a) = 1;
    *(undefined1 *)(lVar7 + 0x48) = 1;
    rmnet_module_hook_aps_data_inactive();
    DataMemoryBarrier(2,3);
    local_3c[0] = 0x20;
    ps_bearer_id = 0;
    DAT_00128e32 = 0;
    DAT_00128e3a = 0;
    DAT_00128e42 = 0;
    rmnet_prepare_ps_bearers(param_1,local_3c);
    uVar4 = local_3c[0];
    if (dfc_qmap == 0) {
      lVar7 = rmnet_get_qmi_pt(param_1);
      if (((lVar7 != 0) && (*(long *)(lVar7 + 8) != 0)) &&
         (iVar6 = wda_set_powersave_mode(*(long *)(lVar7 + 8),1,uVar4,&ps_bearer_id), iVar6 < 0)) {
        _printk(&DAT_00120d84,"qmi_rmnet_set_powersave_mode",1,iVar6);
      }
    }
    else {
      dfc_qmap_set_powersave(1,local_3c[0],&ps_bearer_id);
    }
    iVar6 = rmnet_get_powersave_notif(param_1);
    if ((iVar6 != 0) && (ppuVar8 = (undefined **)ps_list, (undefined **)ps_list != &ps_list)) {
      do {
        if (*(int *)(ppuVar8[-2] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11c938);
          (*pcVar5)();
        }
        (*(code *)ppuVar8[-2])(param_1);
        ppuVar8 = (undefined **)*ppuVar8;
      } while (ppuVar8 != &ps_list);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// __traceiter_wda_set_powersave_mode @ 0011ca8c size=100
// signature: undefined __traceiter_wda_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 __traceiter_wda_set_powersave_mode(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00129d38;
  plVar2 = DAT_00129d38;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11cad0);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_wda_client_state_up @ 0011caf4 size=124
// signature: undefined __traceiter_wda_client_state_up(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_wda_client_state_up
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129d80;
  plVar2 = _DAT_00129d80;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x7b62ce0c) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11cb4c);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_wda_client_state_down @ 0011cb74 size=100
// signature: undefined __traceiter_wda_client_state_down(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __traceiter_wda_client_state_down(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00129dc8;
  plVar2 = _DAT_00129dc8;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0xce76772) break;
    (*(code *)*plVar3)(plVar3[1],param_2);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11cbb8);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_wda_set_powersave_mode @ 0011cbdc size=168
// signature: undefined trace_event_raw_event_wda_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_wda_set_powersave_mode(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_wda_set_powersave_mode @ 0011cc88 size=236
// signature: undefined perf_trace_wda_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void perf_trace_wda_set_powersave_mode(long param_1,undefined4 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_wda_client_state_up @ 0011cd78 size=192
// signature: undefined trace_event_raw_event_wda_client_state_up(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_wda_client_state_up
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x14), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_wda_client_state_up @ 0011ce3c size=256
// signature: undefined perf_trace_wda_client_state_up(void)
// callers: []
//------------------------------------------------------------

void perf_trace_wda_client_state_up
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_60 [12];
  undefined4 local_54;
  long local_50;
  undefined8 local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = 0;
  local_54 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x14,&local_50,&local_54), lVar3 != 0)) {
    *(undefined1 **)(local_50 + 0xe8) = auStack_60 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_50 + 0xf8) = auStack_60;
    *(ulong *)(local_50 + 0x100) = uVar2;
    *(undefined8 *)(local_50 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    perf_trace_run_bpf_submit(lVar3,0x14,local_54,param_1,1,local_50,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_wda_client_state_down @ 0011cf40 size=168
// signature: undefined trace_event_raw_event_wda_client_state_down(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_wda_client_state_down(long param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_58,param_1,0xc), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    trace_event_buffer_commit(&local_58);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_wda_client_state_down @ 0011cfec size=236
// signature: undefined perf_trace_wda_client_state_down(void)
// callers: []
//------------------------------------------------------------

void perf_trace_wda_client_state_down(long param_1,undefined4 param_2)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  long local_40;
  undefined8 local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  local_44 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0xc,&local_40,&local_44), lVar3 != 0)) {
    *(undefined1 **)(local_40 + 0xe8) = auStack_50 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_40 + 0xf8) = auStack_50;
    *(ulong *)(local_40 + 0x100) = uVar2;
    *(undefined8 *)(local_40 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    perf_trace_run_bpf_submit(lVar3,0xc,local_44,param_1,1,local_40,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_wda_set_powersave_mode @ 0011d0dc size=32
// signature: undefined __bpf_trace_wda_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_wda_set_powersave_mode(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run1(param_1,param_2);
  return;
}



//------------------------------------------------------------
// __bpf_trace_wda_client_state_up @ 0011d100 size=40
// signature: undefined __bpf_trace_wda_client_state_up(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_wda_client_state_up
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// __bpf_trace_wda_client_state_down @ 0011d12c size=32
// signature: undefined __bpf_trace_wda_client_state_down(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_wda_client_state_down(undefined8 param_1,undefined4 param_2)

{
  bpf_trace_run1(param_1,param_2);
  return;
}



//------------------------------------------------------------
// wda_qmi_client_init @ 0011d150 size=392
// signature: undefined wda_qmi_client_init(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wda_qmi_client_init(long param_1,undefined8 *param_2,long param_3)

{
  long *plVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined8 uVar6;
  
  iVar3 = -0x16;
  if ((param_1 != 0) && (param_3 != 0)) {
    plVar4 = (long *)kmalloc_trace(_netdev_rx_handler_register,0xdc0,0x1a8);
    if (plVar4 == (long *)0x0) {
      iVar3 = -0xc;
    }
    else {
      lVar5 = alloc_workqueue(&DAT_00120d2e,0xe000a,1,"wda_wq");
      plVar4[1] = lVar5;
      if (lVar5 == 0) {
        _printk(&DAT_001216ce,"wda_qmi_client_init");
        iVar3 = -0xc;
      }
      else {
        uVar6 = *param_2;
        *plVar4 = param_1;
        plVar1 = plVar4 + 8;
        uVar2 = *(undefined4 *)(param_2 + 1);
        *(undefined8 *)((long)plVar4 + 0x194) = uVar6;
        *(undefined4 *)((long)plVar4 + 0x19c) = uVar2;
        plVar4[2] = 0xfffffffe0;
        *(undefined4 *)(plVar4 + 0x34) = 0;
        plVar4[3] = (long)(plVar4 + 3);
        plVar4[4] = (long)(plVar4 + 3);
        plVar4[5] = (long)wda_svc_config;
        iVar3 = qmi_handle_init(plVar1,0xe,&server_ops,0);
        if (iVar3 < 0) {
          _printk(&DAT_0012124a,"wda_qmi_client_init",iVar3);
        }
        else {
          iVar3 = qmi_add_lookup(plVar1,0x1a,1,*(undefined4 *)param_2);
          if (-1 < iVar3) {
            *(long **)(param_3 + 0x10) = plVar4;
            return 0;
          }
          _printk(&DAT_00120ac9,"wda_qmi_client_init",iVar3);
          qmi_handle_release(plVar1);
        }
        destroy_workqueue(plVar4[1]);
      }
      kfree(plVar4);
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// wda_svc_config @ 0011d2dc size=660
// signature: undefined wda_svc_config(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wda_svc_config(long param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  ushort *puVar6;
  long lVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined8 local_90;
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
  iVar3 = rtnl_trylock();
  while (iVar3 == 0) {
    if (*(int *)(param_1 + 400) != 0) goto LAB_0011d498;
    msleep(1);
    iVar3 = rtnl_trylock();
  }
  iVar3 = rmnet_get_dlmarker_info(*(undefined8 *)(param_1 + -0x10));
  rtnl_unlock();
  if (*(int *)(param_1 + 400) == 1) goto LAB_0011d498;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  puVar5 = (undefined4 *)kmalloc_trace(___stack_chk_fail,0xb20,0x10);
  if (puVar5 == (undefined4 *)0x0) {
LAB_0011d47c:
    iVar4 = -0xc;
  }
  else {
    puVar6 = (ushort *)kmalloc_trace(___stack_chk_fail,0xb20,0xc);
    if (puVar6 == (ushort *)0x0) {
      kfree(puVar5);
      goto LAB_0011d47c;
    }
    iVar4 = qmi_txn_init(param_1 + 0x30,&local_90,wda_set_powersave_config_resp_msg_v01_ei,puVar6);
    if (iVar4 < 0) {
      puVar8 = &DAT_00120ef6;
LAB_0011d4f4:
      _printk(puVar8,"wda_set_powersave_config_req",iVar4);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x18c);
      uVar9 = 2;
      if (iVar3 != 0) {
        uVar9 = 0x7fffffff;
      }
      *puVar5 = *(undefined4 *)(param_1 + 0x188);
      puVar5[1] = uVar2;
      *(undefined1 *)(puVar5 + 2) = 1;
      puVar5[3] = uVar9;
      iVar4 = qmi_send_request(param_1 + 0x30,param_1 + 0x178,&local_90,0x2d,0x12,
                               wda_set_powersave_config_req_msg_v01_ei,puVar5);
      if (iVar4 < 0) {
        qmi_txn_cancel(&local_90);
        puVar8 = &DAT_001213bf;
        goto LAB_0011d4f4;
      }
      iVar4 = qmi_txn_wait(&local_90,0xfa);
      if (iVar4 < 0) {
        puVar8 = &DAT_00120ffa;
        goto LAB_0011d4f4;
      }
      if (*puVar6 != 0) {
        _printk(&DAT_00120f3f,"wda_set_powersave_config_req",*puVar6,puVar6[1]);
        iVar4 = -(uint)*puVar6;
      }
    }
    kfree(puVar6);
    kfree(puVar5);
    if (-1 < iVar4) {
      if (*(int *)(param_1 + 400) != 1) {
        iVar4 = rtnl_trylock();
        while (iVar4 == 0) {
          if (*(int *)(param_1 + 400) != 0) goto LAB_0011d498;
          msleep(1);
          iVar4 = rtnl_trylock();
        }
        lVar7 = rmnet_get_qmi_pt(*(undefined8 *)(param_1 + -0x10));
        if (lVar7 == 0) {
          rtnl_unlock();
        }
        else {
          *(undefined8 **)(lVar7 + 8) = (undefined8 *)(param_1 + -0x10);
          *(undefined8 *)(lVar7 + 0x10) = 0;
          trace_wda_client_state_up
                    (*(undefined4 *)(param_1 + 0x184),*(undefined4 *)(param_1 + 0x188),
                     *(undefined4 *)(param_1 + 0x18c));
          rtnl_unlock();
          pcVar1 = "disabled";
          if (iVar3 != 0) {
            pcVar1 = "enabled";
          }
          _printk(&DAT_001215fe,pcVar1);
        }
      }
      goto LAB_0011d498;
    }
  }
  _printk(&DAT_001214bc,"wda_svc_config",iVar4);
LAB_0011d498:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// wda_qmi_client_exit @ 0011d574 size=100
// signature: undefined wda_qmi_client_exit(void)
// callers: [qmi_rmnet_qmi_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

void wda_qmi_client_exit(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_0012145a,"wda_qmi_client_exit");
  }
  else {
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    destroy_workqueue(*(undefined8 *)(param_1 + 8));
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// wda_set_powersave_mode @ 0011d674 size=532
// signature: undefined wda_set_powersave_mode(void)
// callers: [qmi_rmnet_check_stats_2, qmi_rmnet_check_stats, qmi_rmnet_pm_notify_cb, qmi_rmnet_set_powersave_mode]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wda_set_powersave_mode(long *param_1,char param_2,byte param_3,void *param_4)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  ushort *puVar4;
  undefined *puVar5;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    iVar2 = -0x16;
    goto LAB_0011d7e8;
  }
  pcVar3 = (char *)kmalloc_trace(___stack_chk_fail,0xb20,0x27);
  if (pcVar3 == (char *)0x0) {
    iVar2 = -0xc;
    goto LAB_0011d7e8;
  }
  puVar4 = (ushort *)kmalloc_trace(___stack_chk_fail,0xb20,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    iVar2 = qmi_txn_init(param_1 + 8,&local_a0,wda_set_powersave_mode_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      puVar5 = &DAT_00120ef6;
LAB_0011d84c:
      _printk(puVar5,"wda_set_powersave_mode_req",iVar2);
    }
    else {
      *pcVar3 = param_2;
      if ((((param_3 < 0x21) && (param_2 != '\0')) && (param_3 != 0)) && (param_4 != (void *)0x0)) {
        pcVar3[4] = param_3;
        pcVar3[1] = '\x01';
        pcVar3[2] = '\x01';
        pcVar3[3] = '\x01';
        memcpy(pcVar3 + 5,param_4,(ulong)param_3);
        pcVar3[0x25] = '\x01';
        pcVar3[0x26] = '\x01';
      }
      iVar2 = qmi_send_request(param_1 + 8,param_1 + 0x31,&local_a0,0x2e,0x30,
                               wda_set_powersave_mode_req_msg_v01_ei,pcVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_a0);
        puVar5 = &DAT_001213bf;
        goto LAB_0011d84c;
      }
      iVar2 = qmi_txn_wait(&local_a0,0xfa);
      if (iVar2 < 0) {
        puVar5 = &DAT_00120ffa;
        goto LAB_0011d84c;
      }
      if (*puVar4 != 0) {
        _printk(&DAT_001209a2,"wda_set_powersave_mode_req",*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar4);
  }
  kfree(pcVar3);
LAB_0011d7e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wda_qmi_client_release @ 0011d924 size=36
// signature: undefined wda_qmi_client_release(void)
// callers: [qmi_rmnet_qmi_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

void wda_qmi_client_release(long param_1)

{
  if (param_1 != 0) {
    qmi_handle_release(param_1 + 0x40);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_wda_set_powersave_mode @ 0011d94c size=116
// signature: undefined trace_raw_output_wda_set_powersave_mode(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_wda_set_powersave_mode(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x20f0);
  iVar2 = trace_raw_output_prep(param_1,param_3);
  if (iVar2 == 1) {
    pcVar1 = "disable";
    if (*(int *)(lVar3 + 8) != 0) {
      pcVar1 = "enable";
    }
    trace_event_printf(param_1,"set powersave mode to %s\n",pcVar1);
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_wda_client_state_up @ 0011d9c4 size=104
// signature: undefined trace_raw_output_wda_client_state_up(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_wda_client_state_up(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"Client: Connected with WDA instance=%u ep_type=%u i_id=%u\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_wda_client_state_down @ 0011da30 size=100
// signature: undefined trace_raw_output_wda_client_state_down(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_wda_client_state_down(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"Client: Connection with WDA lost Exit by callback %d\n",
                       *(undefined4 *)(lVar2 + 8));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_wda_client_state_up @ 0011da94 size=44
// signature: undefined trace_wda_client_state_up(void)
// callers: [wda_svc_config]
//------------------------------------------------------------

void trace_wda_client_state_up(void)

{
  return;
}



//------------------------------------------------------------
// wda_svc_arrive @ 0011db6c size=68
// signature: undefined wda_svc_arrive(void)
// callers: []
//------------------------------------------------------------

undefined8 wda_svc_arrive(long param_1,long param_2)

{
  *(undefined2 *)(param_1 + 0x148) = 0x2a;
  *(undefined4 *)(param_1 + 0x14c) = *(undefined4 *)(param_2 + 0xc);
  *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(param_2 + 0x10);
  queue_work_on(0x20,*(undefined8 *)(param_1 + -0x38),param_1 + -0x30);
  return 0;
}



//------------------------------------------------------------
// wda_svc_exit @ 0011dbb4 size=56
// signature: undefined wda_svc_exit(void)
// callers: []
//------------------------------------------------------------

void wda_svc_exit(long param_1)

{
  if (param_1 == 0x40) {
    _printk(&DAT_0012145a,"wda_svc_exit");
    return;
  }
  return;
}



//------------------------------------------------------------
// rmnet_ll_buffer_pool_alloc @ 0011dc08 size=32
// signature: undefined rmnet_ll_buffer_pool_alloc(void)
// callers: []
//------------------------------------------------------------

undefined8 rmnet_ll_buffer_pool_alloc(long param_1)

{
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(long *)param_1 = param_1;
  *(long *)(param_1 + 8) = param_1;
  *(long *)(param_1 + 0x18) = param_1;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}



//------------------------------------------------------------
// rmnet_ll_buffer_pool_free @ 0011dc2c size=216
// signature: undefined rmnet_ll_buffer_pool_free(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_buffer_pool_free(long *param_1)

{
  int *piVar1;
  long *plVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  long *plVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  
  plVar6 = (long *)*param_1;
  while (plVar6 != param_1) {
    plVar9 = (long *)*plVar6;
    uVar7 = __list_del_entry_valid(plVar6);
    if ((uVar7 & 1) != 0) {
      lVar8 = *plVar6;
      plVar2 = (long *)plVar6[1];
      *(long **)(lVar8 + 8) = plVar2;
      *plVar2 = lVar8;
    }
    lVar8 = plVar6[2];
    *plVar6 = -0x2152ffffffffff00;
    plVar6[1] = -0x2152fffffffffede;
    if ((*(ulong *)(lVar8 + 8) & 1) != 0) {
      lVar8 = *(ulong *)(lVar8 + 8) - 1;
    }
    piVar1 = (int *)(lVar8 + 0x34);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar3 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    plVar6 = plVar9;
    if (iVar3 + -1 == 0) {
      __folio_put();
    }
  }
  param_1[3] = 0;
  return;
}



//------------------------------------------------------------
// rmnet_ll_buffers_recycle @ 0011dd30 size=612
// signature: undefined rmnet_ll_buffers_recycle(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_ll_buffers_recycle(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  long ****pppplVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  long ***ppplVar7;
  long ***ppplVar8;
  long ****pppplVar9;
  int iVar10;
  uint uVar11;
  long ****pppplVar12;
  long ****local_68;
  long ****local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = (long ****)&local_68;
  local_60 = local_68;
  if (_DAT_001281a0 != (code *)0x0) {
    if (*(int *)(_DAT_001281a0 + -4) != 0x3261c7a6) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11dd8c);
      (*pcVar4)();
    }
    iVar5 = (*_DAT_001281a0)();
    if (iVar5 != 0) {
      pppplVar9 = (long ****)**(long *****)(param_1 + 0x18);
      if (pppplVar9 == *(long *****)(param_1 + 0x18)) {
        iVar10 = 0;
      }
      else {
        iVar10 = 0;
        uVar11 = 0;
        do {
          if (0xf < uVar11) break;
          if (iVar10 == iVar5) {
            *(long *****)(param_1 + 0x18) = pppplVar9;
            if (iVar10 != 0) goto LAB_0011de50;
            goto LAB_0011de90;
          }
          pppplVar12 = (long ****)*pppplVar9;
          if (*(char *)((long)pppplVar9 + 0x19) == '\0') {
            uVar6 = __list_del_entry_valid(pppplVar9);
            pppplVar3 = local_60;
            if ((uVar6 & 1) != 0) {
              ppplVar7 = *pppplVar9;
              ppplVar8 = pppplVar9[1];
              ppplVar7[1] = (long **)ppplVar8;
              *ppplVar8 = (long **)ppplVar7;
            }
            iVar10 = iVar10 + 1;
            uVar6 = __list_add_valid(pppplVar9,local_60,&local_68);
            if ((uVar6 & 1) != 0) {
              *pppplVar9 = (long ***)&local_68;
              pppplVar9[1] = (long ***)pppplVar3;
              local_60 = pppplVar9;
              *pppplVar3 = (long ***)pppplVar9;
            }
          }
          uVar11 = uVar11 + 1;
          pppplVar9 = pppplVar12;
        } while (pppplVar12 != *(long *****)(param_1 + 0x18));
        *(long *****)(param_1 + 0x18) = pppplVar9;
        if (iVar10 != 0) {
LAB_0011de50:
          rmnet_ll_buffers_submit(param_1,&local_68);
          ppplVar7 = *(long ****)(param_1 + 0x18);
          if ((long *****)local_68 != &local_68) {
            ppplVar8 = (long ***)ppplVar7[1];
            local_68[1] = ppplVar8;
            *ppplVar8 = (long **)local_68;
            *local_60 = ppplVar7;
            ppplVar7[1] = (long **)local_60;
            local_68 = (long ****)&local_68;
            local_60 = (long ****)&local_68;
          }
        }
      }
LAB_0011de90:
      if (iVar10 < iVar5) {
        iVar5 = iVar5 - iVar10;
        do {
          uVar2 = tpidr_el1;
          ppplVar7 = (long ***)__alloc_pages(uVar2,0x60a20,*(undefined4 *)(param_1 + 0x3c),0,0);
          pppplVar9 = local_60;
          if (ppplVar7 == (long ***)0x0) break;
          pppplVar12 = (long ****)
                       ((((ulong)ppplVar7 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                       (ulong)*(uint *)(param_1 + 0x40));
          pppplVar12[2] = ppplVar7;
          *(undefined1 *)((long)pppplVar12 + 0x19) = 0;
          *pppplVar12 = (long ***)pppplVar12;
          pppplVar12[1] = (long ***)pppplVar12;
          if (pppplVar12 == (long ****)0x0) break;
          uVar6 = __list_add_valid(pppplVar12,local_60,&local_68);
          if ((uVar6 & 1) != 0) {
            *pppplVar12 = (long ***)&local_68;
            pppplVar12[1] = (long ***)pppplVar9;
            local_60 = pppplVar12;
            *pppplVar9 = (long ***)pppplVar12;
          }
          *(undefined1 *)(pppplVar12 + 3) = 1;
          iVar5 = iVar5 + -1;
          rmnet_ll_stats._80_8_ = rmnet_ll_stats._80_8_ + 1;
        } while (iVar5 != 0);
      }
      if ((long *****)local_68 != &local_68) {
        rmnet_ll_buffers_submit(param_1,&local_68);
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// rmnet_ll_buffers_submit @ 0011df9c size=284
// signature: undefined rmnet_ll_buffers_submit(void)
// callers: [rmnet_ll_buffers_recycle]
//------------------------------------------------------------

void rmnet_ll_buffers_submit(undefined8 param_1,long *param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long *plVar7;
  
  plVar7 = (long *)*param_2;
  do {
    if (plVar7 == param_2) {
      return;
    }
    if (*(char *)((long)plVar7 + 0x19) == '\0') {
      if (rmnet_ll_client != (code *)0x0) {
        if (*(int *)(rmnet_ll_client + -4) != -0x2b3cd2b2) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11e034);
          (*pcVar4)();
        }
        iVar5 = (*rmnet_ll_client)(param_1,plVar7);
        if (iVar5 == 0) {
          *(undefined1 *)((long)plVar7 + 0x19) = 1;
          rmnet_ll_stats._32_8_ = rmnet_ll_stats._32_8_ + 1;
          goto LAB_0011dff8;
        }
      }
      rmnet_ll_stats._40_8_ = rmnet_ll_stats._40_8_ + 1;
      if (*(char *)(plVar7 + 3) != '\0') {
        lVar6 = plVar7[2];
        if ((*(ulong *)(lVar6 + 8) & 1) != 0) {
          lVar6 = *(ulong *)(lVar6 + 8) - 1;
        }
        piVar1 = (int *)(lVar6 + 0x34);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar5 = *piVar1;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar3) {
            *piVar1 = iVar5 + -1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar5 + -1 == 0) {
          __folio_put();
        }
      }
    }
LAB_0011dff8:
    plVar7 = (long *)*plVar7;
  } while( true );
}



//------------------------------------------------------------
// rmnet_ll_send_skb @ 0011e0e4 size=148
// signature: undefined rmnet_ll_send_skb(void)
// callers: [rmnet_egress_handler]
//------------------------------------------------------------

int rmnet_ll_send_skb(undefined8 param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  
  _raw_spin_lock_bh(&rmnet_ll_tx_lock);
  if (*(int *)(PTR_rmnet_ll_ipa_tx_001281a8 + -4) != 0x1d6d0cb6) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11e130);
    (*pcVar2)();
  }
  iVar3 = (*(code *)PTR_rmnet_ll_ipa_tx_001281a8)(param_1);
  _raw_spin_unlock_bh(&rmnet_ll_tx_lock);
  lVar1 = (ulong)(iVar3 != 0) * 8;
  *(long *)(rmnet_ll_stats + lVar1) = *(long *)(rmnet_ll_stats + lVar1) + 1;
  return iVar3;
}



//------------------------------------------------------------
// rmnet_ll_get_stats @ 0011e17c size=12
// signature: undefined rmnet_ll_get_stats(void)
// callers: [rmnet_get_ethtool_stats, rmnet_ll_ipa_tx_pending, rmnet_ll_ipa_tx, rmnet_ll_ipa_rx]
//------------------------------------------------------------

undefined1 * rmnet_ll_get_stats(void)

{
  return rmnet_ll_stats;
}



//------------------------------------------------------------
// rmnet_ll_init @ 0011e18c size=60
// signature: undefined rmnet_ll_init(void)
// callers: [init_module]
//------------------------------------------------------------

void rmnet_ll_init(void)

{
  code *pcVar1;
  
  if (*(int *)(PTR_rmnet_ll_ipa_init_001281b0 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11e1b8);
    (*pcVar1)();
  }
  (*(code *)PTR_rmnet_ll_ipa_init_001281b0)();
  return;
}



//------------------------------------------------------------
// rmnet_ll_exit @ 0011e1cc size=60
// signature: undefined rmnet_ll_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void rmnet_ll_exit(void)

{
  code *pcVar1;
  
  if (*(int *)(PTR_rmnet_ll_ipa_exit_001281b8 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11e1f8);
    (*pcVar1)();
  }
  (*(code *)PTR_rmnet_ll_ipa_exit_001281b8)();
  return;
}



//------------------------------------------------------------
// rmnet_ll_ipa_tx_pending @ 0011e210 size=244
// signature: undefined rmnet_ll_ipa_tx_pending(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_ipa_tx_pending(void)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = rmnet_ll_get_stats();
  _raw_spin_lock_bh(&rmnet_ll_tx_lock);
  if (((long **)tx_pending_list != &tx_pending_list) && (tx_pending_list != (long *)0x0)) {
    while( true ) {
      plVar3 = tx_pending_list;
      DAT_00128ee8 = DAT_00128ee8 + -1;
      lVar1 = *tx_pending_list;
      plVar2 = (long *)tx_pending_list[1];
      *tx_pending_list = 0;
      plVar3[1] = 0;
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
      iVar4 = ipa_rmnet_ll_xmit(plVar3);
      if (iVar4 == -0xb) break;
      lVar1 = 0x78;
      if (-1 < iVar4) {
        lVar1 = 0x70;
      }
      *(long *)(lVar5 + lVar1) = *(long *)(lVar5 + lVar1) + 1;
      if (((long **)tx_pending_list == &tx_pending_list) || (tx_pending_list == (long *)0x0))
      goto LAB_0011e2e0;
    }
    *(long *)(lVar5 + 0x58) = *(long *)(lVar5 + 0x58) + 1;
    *plVar3 = (long)tx_pending_list;
    plVar3[1] = (long)&tx_pending_list;
    tx_pending_list[1] = (long)plVar3;
    DAT_00128ee8 = DAT_00128ee8 + 1;
    tx_pending_list = plVar3;
  }
LAB_0011e2e0:
  _raw_spin_unlock_bh(&rmnet_ll_tx_lock);
  return;
}



//------------------------------------------------------------
// rmnet_ll_ipa_tx @ 0011e308 size=220
// signature: undefined rmnet_ll_ipa_tx(void)
// callers: [rmnet_ll_send_skb]
//------------------------------------------------------------

undefined8 rmnet_ll_ipa_tx(undefined8 *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = rmnet_ll_get_stats();
  if (rmnet_ll_ipa_ep == 0) {
    return 0xffffffed;
  }
  if ((undefined8 **)tx_pending_list == &tx_pending_list) {
    uVar3 = ipa_rmnet_ll_xmit(param_1);
    if (-1 < (int)uVar3) {
      return 0;
    }
    if ((int)uVar3 != -0xb) {
      return uVar3;
    }
    *(long *)(lVar2 + 0x58) = *(long *)(lVar2 + 0x58) + 1;
  }
  if (DAT_00128ee8 < 1000) {
    *param_1 = &tx_pending_list;
    uVar3 = 0;
    param_1[1] = DAT_00128ee0;
    puVar1 = param_1;
    *DAT_00128ee0 = param_1;
    DAT_00128ee0 = puVar1;
    DAT_00128ee8 = DAT_00128ee8 + 1;
    *(long *)(lVar2 + 0x68) = *(long *)(lVar2 + 0x68) + 1;
  }
  else {
    kfree_skb_reason(param_1,1);
    uVar3 = 0xfffffff4;
  }
  return uVar3;
}



//------------------------------------------------------------
// rmnet_ll_ipa_init @ 0011e3e8 size=144
// signature: undefined rmnet_ll_ipa_init(void)
// callers: [rmnet_ll_init]
//------------------------------------------------------------

ulong rmnet_ll_ipa_init(void)

{
  ulong uVar1;
  
  tx_pending_list = &tx_pending_list;
  DAT_00128ee0 = &tx_pending_list;
  DAT_00128ee8 = 0;
  uVar1 = ipa_register_ipa_ready_cb(rmnet_ll_ipa_ready,0);
  if (((int)uVar1 == -0x11) &&
     (uVar1 = ipa_register_rmnet_ll_cb
                        (rmnet_ll_ipa_probe,&rmnet_ll_ipa_ep,rmnet_ll_ipa_remove,&rmnet_ll_ipa_ep,
                         rmnet_ll_ipa_rx,&rmnet_ll_ipa_ep), (int)uVar1 != 0)) {
    _printk(&DAT_001210e7,"rmnet_ll_ipa_ready",uVar1 & 0xffffffff);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_ll_ipa_exit @ 0011e47c size=56
// signature: undefined rmnet_ll_ipa_exit(void)
// callers: [rmnet_ll_exit]
//------------------------------------------------------------

undefined8 rmnet_ll_ipa_exit(void)

{
  if (rmnet_ll_ipa_ep != 0) {
    ipa_unregister_rmnet_ll_cb();
    rmnet_ll_ipa_ep = 0;
  }
  return 0;
}



//------------------------------------------------------------
// rmnet_ll_ipa_ready @ 0011e4b8 size=100
// signature: undefined rmnet_ll_ipa_ready(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_ipa_ready(void)

{
  int iVar1;
  
  iVar1 = ipa_register_rmnet_ll_cb
                    (rmnet_ll_ipa_probe,&rmnet_ll_ipa_ep,rmnet_ll_ipa_remove,&rmnet_ll_ipa_ep,
                     rmnet_ll_ipa_rx,&rmnet_ll_ipa_ep);
  if (iVar1 != 0) {
    _printk(&DAT_001210e7,"rmnet_ll_ipa_ready",iVar1);
  }
  return;
}



//------------------------------------------------------------
// rmnet_ll_ipa_probe @ 0011e520 size=152
// signature: undefined rmnet_ll_ipa_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rmnet_ll_ipa_probe(long *param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = kmalloc_trace(_rtnl_is_locked,0xdc0,0x48);
  if (lVar1 == 0) {
    _printk(&DAT_00121190,"rmnet_ll_ipa_probe");
  }
  else {
    lVar2 = dev_get_by_name(&init_net,"rmnet_ipa0");
    *(long *)(lVar1 + 0x28) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_00120db2,"rmnet_ll_ipa_probe");
      kfree(lVar1);
    }
    else {
      *param_1 = lVar1;
    }
  }
  return;
}



//------------------------------------------------------------
// rmnet_ll_ipa_remove @ 0011e5bc size=240
// signature: undefined rmnet_ll_ipa_remove(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_ipa_remove(long *param_1)

{
  int *piVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  
  lVar8 = *(long *)(*param_1 + 0x28);
  if (lVar8 != 0) {
    lVar5 = sp_el0;
    *(int *)(lVar5 + 0x10) = *(int *)(lVar5 + 0x10) + 1;
    lVar6 = tpidr_el1;
    piVar1 = (int *)(lVar6 + *(long *)(lVar8 + 0x4d8));
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = *piVar1 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar8 = *(long *)(lVar5 + 0x10) + -1;
    *(int *)(lVar5 + 0x10) = (int)lVar8;
    if ((lVar8 == 0) || (*(long *)(lVar5 + 0x10) == 0)) {
      preempt_schedule_notrace();
    }
  }
  kfree(*param_1);
  *param_1 = 0;
  _raw_spin_lock_bh(&rmnet_ll_tx_lock);
  plVar7 = tx_pending_list;
  if ((long **)tx_pending_list != &tx_pending_list) {
    do {
      tx_pending_list = plVar7;
      if (plVar7 == (long *)0x0) break;
      DAT_00128ee8 = DAT_00128ee8 + -1;
      lVar8 = *plVar7;
      plVar2 = (long *)plVar7[1];
      *plVar7 = 0;
      plVar7[1] = 0;
      *(long **)(lVar8 + 8) = plVar2;
      *plVar2 = lVar8;
      kfree_skb_reason(plVar7,1);
      plVar7 = tx_pending_list;
    } while ((long **)tx_pending_list != &tx_pending_list);
  }
  _raw_spin_unlock_bh(&rmnet_ll_tx_lock);
  return;
}



//------------------------------------------------------------
// rmnet_ll_ipa_rx @ 0011e6b0 size=276
// signature: undefined rmnet_ll_ipa_rx(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_ipa_rx(long param_1,long *param_2)

{
  char cVar1;
  bool bVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  
  lVar4 = rmnet_ll_ipa_ep;
  lVar5 = rmnet_ll_get_stats();
  if (param_1 == 2) {
    *(long *)(lVar5 + 0x60) = *(long *)(lVar5 + 0x60) + 1;
    Hint_Prefetch(0x128178,2,0,1);
    do {
      uVar3 = DAT_00128178;
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(0x128178,0x10);
      if (bVar2) {
        cVar1 = ExclusiveMonitorsStatus();
        DAT_00128178 = DAT_00128178 | 1;
      }
    } while (cVar1 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar3 & 1) == 0) {
      __tasklet_schedule(&tx_pending_task);
    }
  }
  else if (param_1 == 1) {
    param_2[2] = *(long *)(lVar4 + 0x28);
    *(undefined2 *)((long)param_2 + 0xb4) = 0xf900;
    *(undefined2 *)((long)param_2 + 0x7c) = 2;
    if (param_2 != (long *)0x0) {
      plVar6 = param_2;
      do {
        *(undefined4 *)((long)plVar6 + 0x8c) = 0xda1a;
        if (plVar6 == param_2) {
          plVar6 = (long *)(param_2[0x1b] + (ulong)*(uint *)((long)param_2 + 0xd4) + 8);
        }
        plVar6 = (long *)*plVar6;
      } while (plVar6 != (long *)0x0);
    }
    *(long *)(lVar5 + 0x48) = *(long *)(lVar5 + 0x48) + 1;
    netif_rx(param_2);
  }
  else {
    _printk(&DAT_00120a41,"rmnet_ll_ipa_rx",param_1);
  }
  return;
}



//------------------------------------------------------------
// rmnet_qmap_send @ 0011e7f0 size=264
// signature: undefined rmnet_qmap_send(void)
// callers: [dfc_qmap_send_ack, dfc_qmap_send_config, dfc_qmap_cmd_handler, rmnet_qmap_cmd_handler, dfc_qmap_set_powersave, ll_qmap_send_switch]
//------------------------------------------------------------

undefined8 rmnet_qmap_send(long param_1,uint param_2,uint param_3)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  
  if ((((param_2 ^ 0xffffffff) & 0xff) == 0) || (real_data_dev == 0)) {
    if (*(int *)(*(code **)(rmnet_ctl + 0x10) + -4) != -0x329e6429) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11e8c8);
      (*pcVar2)();
    }
    uVar3 = (**(code **)(rmnet_ctl + 0x10))
                      (rmnet_ctl_handle,param_1,*(undefined4 *)(param_1 + 0x70));
    if ((int)uVar3 != 0) {
      _printk(&DAT_00120f20);
      uVar3 = 0xffffffba;
    }
  }
  else {
    *(long *)(param_1 + 0x10) = real_data_dev;
    lVar1 = rmnet_ctl;
    *(undefined2 *)(param_1 + 0xb4) = 0xf900;
    if (*(int *)(*(code **)(lVar1 + 0x18) + -4) != 0x37da4fd1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11e87c);
      (*pcVar2)();
    }
    (**(code **)(lVar1 + 0x18))
              (3,&DAT_0012163b,0,*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0x70));
    rmnet_map_tx_qmap_cmd(param_1,param_2,param_3 & 1);
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// rmnet_qmap_next_txid @ 0011e968 size=4
// signature: undefined rmnet_qmap_next_txid(void)
// callers: [dfc_qmap_send_ack, dfc_qmap_send_config, dfc_qmap_set_powersave, ll_qmap_send_switch]
//------------------------------------------------------------

void rmnet_qmap_next_txid(void)

{
  char cVar1;
  bool bVar2;
  
  Hint_Prefetch(0x128f10,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(0x128f10,0x10);
    if (bVar2) {
      cVar1 = ExclusiveMonitorsStatus();
      qmap_txid = qmap_txid + 1;
    }
  } while (cVar1 != '\0');
  DataMemoryBarrier(2,3);
  return;
}



//------------------------------------------------------------
// FUN_0011e984 @ 0011e984 size=36
// signature: undefined FUN_0011e984(void)
// callers: []
//------------------------------------------------------------

void FUN_0011e984(void)

{
  char cVar1;
  bool bVar2;
  
  Hint_Prefetch(0x128f10,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(0x128f10,0x10);
    if (bVar2) {
      cVar1 = ExclusiveMonitorsStatus();
      qmap_txid = qmap_txid + 1;
    }
  } while (cVar1 != '\0');
  DataMemoryBarrier(2,3);
  return;
}



//------------------------------------------------------------
// rmnet_qmap_get_dev @ 0011e9ac size=40
// signature: undefined rmnet_qmap_get_dev(void)
// callers: [ll_qmap_cmd_handler]
//------------------------------------------------------------

void rmnet_qmap_get_dev(undefined4 param_1)

{
  rmnet_get_rmnet_dev(rmnet_port,param_1);
  return;
}



//------------------------------------------------------------
// rmnet_qmap_init @ 0011e9d8 size=184
// signature: undefined rmnet_qmap_init(void)
// callers: [dfc_qmap_client_init]
//------------------------------------------------------------

undefined8 rmnet_qmap_init(undefined8 param_1)

{
  undefined8 uVar1;
  undefined *puVar2;
  code *pcVar3;
  
  if (rmnet_ctl_handle == 0) {
    qmap_txid = 0;
    rmnet_port = param_1;
    real_data_dev = rmnet_get_real_dev();
    rmnet_ctl = (undefined8 *)rmnet_ctl_if();
    if (rmnet_ctl == (undefined8 *)0x0) {
      puVar2 = &DAT_00121271;
    }
    else {
      pcVar3 = (code *)*rmnet_ctl;
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x5add9fa5) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11ea48);
          (*pcVar3)();
        }
        rmnet_ctl_handle = (*pcVar3)(&cb);
      }
      if (rmnet_ctl_handle != 0) goto LAB_0011ea54;
      puVar2 = &DAT_00121290;
    }
    _printk(puVar2);
    uVar1 = 0xfffffff2;
  }
  else {
LAB_0011ea54:
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// rmnet_qmap_exit @ 0011ea94 size=108
// signature: undefined rmnet_qmap_exit(void)
// callers: [dfc_qmap_client_exit]
//------------------------------------------------------------

void rmnet_qmap_exit(void)

{
  code *pcVar1;
  
  if ((rmnet_ctl != 0) && (pcVar1 = *(code **)(rmnet_ctl + 8), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11ead8);
      (*pcVar1)();
    }
    (*pcVar1)(rmnet_ctl_handle);
  }
  rmnet_ctl_handle = 0;
  real_data_dev = 0;
  rmnet_port = 0;
  return;
}



//------------------------------------------------------------
// rmnet_qmap_cmd_handler @ 0011eb04 size=292
// signature: undefined rmnet_qmap_cmd_handler(void)
// callers: []
//------------------------------------------------------------

void rmnet_qmap_cmd_handler(long param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  byte bVar4;
  char *pcVar5;
  
  if (param_1 == 0) {
    return;
  }
  if (((*(uint *)(param_1 + 0x70) < 0xc) || (pcVar5 = *(char **)(param_1 + 0xe0), -1 < *pcVar5)) ||
     (((uint)(*(ushort *)(pcVar5 + 2) >> 8) | (*(ushort *)(pcVar5 + 2) & 0xff00ff) << 8) + 4 !=
      *(uint *)(param_1 + 0x70))) goto LAB_0011ec04;
  __rcu_read_lock(param_1,*(undefined8 *)(param_1 + 0xe0),*(undefined4 *)(param_1 + 0x70));
  bVar4 = pcVar5[4];
  if (bVar4 - 10 < 5) {
    iVar2 = dfc_qmap_cmd_handler(param_1);
joined_r0x0011ebb0:
    if (iVar2 == -2) {
      bVar1 = pcVar5[5];
      uVar3 = 0;
      bVar4 = 1;
      goto LAB_0011ebc0;
    }
    if (iVar2 != -1) {
      bVar1 = pcVar5[5];
      goto LAB_0011eb88;
    }
  }
  else {
    if (bVar4 - 0x19 < 2) {
      iVar2 = ll_qmap_cmd_handler(param_1);
      goto joined_r0x0011ebb0;
    }
    if (bVar4 != 0x22) {
      bVar1 = pcVar5[5];
      if ((bVar1 & 3) != 0) goto LAB_0011ec00;
      iVar2 = 2;
LAB_0011eb88:
      bVar4 = (byte)iVar2 & 3;
      uVar3 = 0xff;
LAB_0011ebc0:
      pcVar5[5] = bVar1 & 0xfc | bVar4;
      rmnet_qmap_send(param_1,uVar3,0);
      __rcu_read_unlock();
      return;
    }
    rmnet_module_hook_aps_data_report(param_1);
  }
LAB_0011ec00:
  __rcu_read_unlock();
LAB_0011ec04:
  kfree_skb_reason(param_1,1);
  return;
}



//------------------------------------------------------------
// rmnet_ll_wq_init @ 0011eca0 size=76
// signature: undefined rmnet_ll_wq_init(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

void rmnet_ll_wq_init(void)

{
  code *pcVar1;
  
  if (ll_wq != 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x11ecec);
    (*pcVar1)();
  }
  ll_wq = alloc_workqueue("rmnet_ll_wq",0xa0002,1);
  return;
}



//------------------------------------------------------------
// rmnet_ll_wq_exit @ 0011ecf4 size=96
// signature: undefined rmnet_ll_wq_exit(void)
// callers: [qmi_rmnet_qmi_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

void rmnet_ll_wq_exit(void)

{
  long lVar1;
  
  _raw_spin_lock_bh(&ll_wq_lock);
  lVar1 = ll_wq;
  if (ll_wq == 0) {
    _raw_spin_unlock_bh(&ll_wq_lock);
  }
  else {
    ll_wq = 0;
    _raw_spin_unlock_bh(&ll_wq_lock);
    destroy_workqueue(lVar1);
  }
  return;
}



//------------------------------------------------------------
// ll_qmap_cmd_handler @ 0011ed58 size=848
// signature: undefined ll_qmap_cmd_handler(void)
// callers: [rmnet_qmap_cmd_handler]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ll_qmap_cmd_handler(long param_1,undefined8 param_2,undefined8 param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  undefined1 uVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  char *pcVar9;
  undefined1 auVar10 [16];
  
  lVar8 = *(long *)(param_1 + 0xe0);
  if (*(char *)(lVar8 + 4) == '\x19') {
    if (((((*(byte *)(lVar8 + 5) & 3) == 1) && (0xf < *(uint *)(param_1 + 0x70))) &&
        (*(byte *)(lVar8 + 0xf) != 0)) &&
       (((uint)*(byte *)(lVar8 + 0xf) * 4 + 0x10 <= *(uint *)(param_1 + 0x70) &&
        (lVar2 = rmnet_qmap_get_dev(*(undefined1 *)(lVar8 + 1)), lVar2 != 0)))) {
      auVar10 = rmnet_get_qos_pt();
      lVar2 = auVar10._0_8_;
      if (lVar2 != 0) {
        lVar5 = lVar2 + 0x14c;
        _raw_spin_lock_bh(lVar5,auVar10._8_8_,param_3,*(undefined1 *)(lVar8 + 0xf),lVar8 + 0x10);
        if (*(char *)(lVar8 + 0xf) != '\0') {
          uVar7 = 0;
          pcVar9 = (char *)(lVar8 + 0x11);
          do {
            lVar3 = qmi_rmnet_get_bearer_map(lVar2,pcVar9[-1]);
            if (lVar3 != 0) {
              cVar1 = *pcVar9;
              if (cVar1 == '\x02') {
                uVar4 = 0;
LAB_0011eec4:
                *(undefined1 *)(lVar3 + 0x90) = uVar4;
                if (*(uint *)(lVar3 + 0x3c) < 0x10) {
                  *(bool *)(lVar2 + (ulong)*(uint *)(lVar3 + 0x3c) * 0x10 + 0x50) = cVar1 != '\x02';
                }
              }
              else if (cVar1 == '\x03') {
                uVar4 = 1;
                goto LAB_0011eec4;
              }
              if ((*(int *)(lVar3 + 0x98) == 1) && (*(int *)(lVar3 + 0x9c) == *(int *)(lVar8 + 8)))
              {
                cVar1 = *pcVar9;
                if (cVar1 == '\x01') {
                  *(undefined4 *)(lVar3 + 0x98) = 2;
                }
                else {
                  *(char *)(lVar3 + 0x93) = cVar1;
                  if ((cVar1 == '\x04') && (*(char *)(lVar3 + 0x92) != '\0')) {
                    *(undefined4 *)(lVar3 + 0x98) = 3;
                    mod_timer(lVar3 + 0xa8,_jiffies + 0x9c4);
                    *(char *)(lVar3 + 0x92) = *(char *)(lVar3 + 0x92) + -1;
                  }
                  else {
                    *(undefined1 *)(lVar3 + 0xa4) = 1;
                    del_timer(lVar3 + 0xa8);
                    *(undefined4 *)(lVar3 + 0x98) = 0;
                    *(undefined1 *)(lVar3 + 0x92) = 0;
                    ll_send_nl_ack(lVar3);
                    *(undefined4 *)(lVar3 + 0xa0) = 0;
                  }
                }
              }
            }
            uVar7 = uVar7 + 1;
            pcVar9 = pcVar9 + 4;
          } while (uVar7 < *(byte *)(lVar8 + 0xf));
        }
        uVar6 = 0xffffffff;
LAB_0011ef6c:
        _raw_spin_unlock_bh(lVar5);
        return uVar6;
      }
    }
  }
  else if ((*(byte *)(lVar8 + 5) & 3) == 0) {
    if (*(char *)(lVar8 + 4) != '\x1a') {
      return 2;
    }
    if (*(uint *)(param_1 + 0x70) < 0x10) {
      return 3;
    }
    if (*(byte *)(lVar8 + 0xf) != 0) {
      if (*(uint *)(param_1 + 0x70) < (uint)*(byte *)(lVar8 + 0xf) * 4 + 0x10) {
        return 3;
      }
      lVar2 = rmnet_qmap_get_dev(*(undefined1 *)(lVar8 + 1));
      if (lVar2 != 0) {
        auVar10 = rmnet_get_qos_pt();
        lVar2 = auVar10._0_8_;
        if (lVar2 != 0) {
          lVar5 = lVar2 + 0x14c;
          _raw_spin_lock_bh(lVar5,auVar10._8_8_,param_3,*(undefined1 *)(lVar8 + 0xf),lVar8 + 0x10);
          uVar6 = 1;
          if (*(char *)(lVar8 + 0xf) != '\0') {
            uVar7 = 0;
            pcVar9 = (char *)(lVar8 + 0x11);
            do {
              lVar3 = qmi_rmnet_get_bearer_map(lVar2,pcVar9[-1]);
              if (lVar3 != 0) {
                cVar1 = *pcVar9;
                if (cVar1 == '\x02') {
                  uVar4 = 0;
LAB_0011f038:
                  *(undefined1 *)(lVar3 + 0x90) = uVar4;
                  if (*(uint *)(lVar3 + 0x3c) < 0x10) {
                    *(bool *)(lVar2 + (ulong)*(uint *)(lVar3 + 0x3c) * 0x10 + 0x50) =
                         cVar1 != '\x02';
                  }
                }
                else if (cVar1 == '\x03') {
                  uVar4 = 1;
                  goto LAB_0011f038;
                }
                if (*(int *)(lVar3 + 0x98) == 2) {
                  cVar1 = *pcVar9;
                  *(char *)(lVar3 + 0x93) = cVar1;
                  if ((cVar1 == '\x04') && (*(char *)(lVar3 + 0x92) != '\0')) {
                    *(undefined4 *)(lVar3 + 0x98) = 3;
                    mod_timer(lVar3 + 0xa8,_jiffies + 0x9c4);
                    *(char *)(lVar3 + 0x92) = *(char *)(lVar3 + 0x92) + -1;
                  }
                  else {
                    *(undefined1 *)(lVar3 + 0xa4) = 1;
                    del_timer(lVar3 + 0xa8);
                    *(undefined4 *)(lVar3 + 0x98) = 0;
                    *(undefined1 *)(lVar3 + 0x92) = 0;
                    ll_send_nl_ack(lVar3);
                    *(undefined4 *)(lVar3 + 0xa0) = 0;
                  }
                }
              }
              uVar7 = uVar7 + 1;
              pcVar9 = pcVar9 + 4;
            } while (uVar7 < *(byte *)(lVar8 + 0xf));
            uVar6 = 1;
          }
          goto LAB_0011ef6c;
        }
      }
    }
    return 1;
  }
  return 0xffffffff;
}



//------------------------------------------------------------
// rmnet_ll_switch @ 0011f18c size=576
// signature: undefined rmnet_ll_switch(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int rmnet_ll_switch(long param_1,long param_2,int param_3)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined4 local_6c;
  long local_68;
  
  lVar5 = sp_el0;
  iVar4 = -0x16;
  local_68 = *(long *)(lVar5 + 0x638);
  local_6c = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    cVar2 = *(char *)(param_2 + 1);
    if ((byte)(cVar2 - 2U) < 0xfd) {
      iVar4 = -0x5f;
    }
    else {
      bVar3 = *(byte *)(param_2 + 2);
      if (((bVar3 != 0) && (bVar3 < 0x10)) && ((ulong)bVar3 <= (long)param_3 - 0x14U)) {
        uVar1 = *(uint *)(param_2 + 0x10);
        puVar9 = (undefined1 *)(param_2 + 0x14);
        uVar10 = (uint)bVar3;
        if (bVar3 != 0) {
          uVar7 = 0;
          do {
            uVar8 = 0;
            do {
              if ((uVar7 != uVar8) && (puVar9[uVar7] == puVar9[uVar8])) goto LAB_0011f380;
              uVar8 = uVar8 + 1;
            } while (uVar10 != uVar8);
            uVar7 = uVar7 + 1;
          } while (uVar7 != uVar10);
        }
        lVar5 = rmnet_get_qos_pt();
        if (lVar5 == 0) {
LAB_0011f380:
          iVar4 = -0x16;
        }
        else {
          _raw_spin_lock_bh(lVar5 + 0x14c);
          if (uVar10 == 0) {
            iVar4 = ll_qmap_send_switch(*(undefined1 *)(lVar5 + 0x10),cVar2,0,puVar9,&local_6c);
          }
          else {
            uVar8 = (ulong)uVar10;
            uVar7 = uVar8;
            puVar11 = puVar9;
            do {
              lVar6 = qmi_rmnet_get_bearer_map(lVar5,*puVar11);
              if (lVar6 == 0) {
                iVar4 = -0xe;
                goto LAB_0011f3bc;
              }
              if (*(int *)(lVar6 + 0x98) != 0) {
                iVar4 = -0x10;
                goto LAB_0011f3bc;
              }
              puVar11 = puVar11 + 1;
              uVar7 = uVar7 - 1;
            } while (uVar7 != 0);
            iVar4 = ll_qmap_send_switch(*(undefined1 *)(lVar5 + 0x10),cVar2,bVar3,puVar9,&local_6c);
            if ((iVar4 == 0) && (bVar3 != 0)) {
              do {
                lVar6 = qmi_rmnet_get_bearer_map(lVar5,*puVar9);
                if (lVar6 != 0) {
                  *(char *)(lVar6 + 0x91) = cVar2;
                  *(byte *)(lVar6 + 0x92) = -((byte)(uVar1 >> 1) & 1) & 3;
                  *(undefined1 *)(lVar6 + 0x93) = 0xff;
                  *(undefined4 *)(lVar6 + 0x98) = 1;
                  *(undefined4 *)(lVar6 + 0x9c) = local_6c;
                  *(uint *)(lVar6 + 0xa0) = uVar1;
                  *(undefined1 *)(lVar6 + 0xa4) = 0;
                  mod_timer(lVar6 + 0xa8,_jiffies + 0x4e2);
                  *(undefined4 *)(lVar6 + 0xe0) = *(undefined4 *)(param_2 + 8);
                  *(undefined4 *)(lVar6 + 0xe4) = *(undefined4 *)(param_2 + 0xc);
                }
                puVar9 = puVar9 + 1;
                uVar8 = uVar8 - 1;
              } while (uVar8 != 0);
              iVar4 = 0;
            }
          }
LAB_0011f3bc:
          _raw_spin_unlock_bh(lVar5 + 0x14c);
        }
      }
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// ll_qmap_send_switch @ 0011f3cc size=356
// signature: undefined ll_qmap_send_switch(void)
// callers: [rmnet_ll_switch, rmnet_ll_guard_fn]
//------------------------------------------------------------

undefined8
ll_qmap_send_switch(byte param_1,char param_2,byte param_3,byte *param_4,undefined4 *param_5)

{
  byte bVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  byte *__s;
  byte bVar5;
  byte *pbVar6;
  ulong uVar7;
  
  uVar3 = 0xffffffea;
  if ((param_3 < 0x10) && (param_4 != (byte *)0x0)) {
    uVar7 = (ulong)((uint)param_3 * 4 + 0x10);
    lVar4 = __alloc_skb(uVar7,0xa20,0,0xffffffff);
    if (lVar4 == 0) {
      uVar3 = 0xfffffff4;
    }
    else {
      *(undefined2 *)(lVar4 + 0xb4) = 0xf900;
      __s = (byte *)skb_put(lVar4,uVar7);
      memset(__s,0,uVar7);
      uVar2 = (uint)param_3 * 4 + 0xc;
      __s[1] = param_1;
      __s[4] = 0x19;
      *(ushort *)(__s + 2) = (ushort)(uVar2 >> 8) | (ushort)((uVar2 & 0xff00ff) << 8);
      *__s = *__s | 0x80;
      __s[5] = __s[5] & 0xfc;
      uVar2 = rmnet_qmap_next_txid();
      uVar2 = (uVar2 & 0xff00ff00) >> 8 | (uVar2 & 0xff00ff) << 8;
      bVar5 = 1;
      if (param_2 != '\x01') {
        bVar5 = 2;
      }
      __s[0xc] = 1;
      bVar1 = 3;
      if (param_2 != -1) {
        bVar1 = bVar5;
      }
      *(uint *)(__s + 8) = uVar2 >> 0x10 | uVar2 << 0x10;
      __s[0xf] = param_3;
      __s[0xe] = bVar1;
      if (param_3 != 0) {
        uVar7 = (ulong)param_3;
        pbVar6 = __s + 0x10;
        do {
          uVar7 = uVar7 - 1;
          *pbVar6 = *param_4;
          pbVar6 = pbVar6 + 4;
          param_4 = param_4 + 1;
        } while (uVar7 != 0);
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = *(undefined4 *)(__s + 8);
      }
      uVar3 = rmnet_qmap_send(lVar4,0xff,0);
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// rmnet_ll_guard_fn @ 0011f5a4 size=236
// signature: undefined rmnet_ll_guard_fn(void)
// callers: []
//------------------------------------------------------------

void rmnet_ll_guard_fn(long param_1)

{
  long lVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  _raw_spin_lock_bh(*(long *)(param_1 + -0x60) + 0x14c);
  if ((*(char *)(param_1 + -4) != '\0') || (*(int *)(param_1 + -0x10) == 0)) goto LAB_0011f644;
  if (*(int *)(param_1 + -0x10) == 3) {
    if (*(char *)(param_1 + -0x18) != *(char *)(param_1 + -0x17)) {
      iVar2 = ll_qmap_send_switch(*(undefined1 *)(*(long *)(param_1 + -0x60) + 0x10),
                                  *(char *)(param_1 + -0x17),1,param_1 + -0x98,&local_2c);
      if (iVar2 == 0) {
        *(undefined4 *)(param_1 + -0x10) = 1;
        *(undefined4 *)(param_1 + -0xc) = local_2c;
        *(undefined1 *)(param_1 + -0x15) = 0xff;
        goto LAB_0011f644;
      }
      goto LAB_0011f628;
    }
    uVar3 = 0xfd;
  }
  else {
LAB_0011f628:
    uVar3 = 0xfe;
  }
  *(undefined4 *)(param_1 + -0x10) = 0;
  *(undefined1 *)(param_1 + -0x15) = uVar3;
  *(undefined1 *)(param_1 + -0x16) = 0;
  ll_send_nl_ack(param_1 + -0xa8);
  *(undefined4 *)(param_1 + -8) = 0;
LAB_0011f644:
  _raw_spin_unlock_bh(*(long *)(param_1 + -0x60) + 0x14c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ll_send_nl_ack @ 0011f690 size=196
// signature: undefined ll_send_nl_ack(void)
// callers: [ll_qmap_cmd_handler, rmnet_ll_guard_fn]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ll_send_nl_ack(long param_1)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined8 *puVar5;
  
  if (((*(byte *)(param_1 + 0xa0) & 1) != 0) &&
     (puVar5 = (undefined8 *)kmalloc_trace(___stack_chk_fail,0xb20,0x40),
     puVar5 != (undefined8 *)0x0)) {
    uVar1 = *(undefined4 *)(param_1 + 0xe4);
    uVar2 = *(undefined1 *)(param_1 + 0x10);
    uVar3 = *(undefined1 *)(param_1 + 0x93);
    *(undefined4 *)(puVar5 + 6) = *(undefined4 *)(param_1 + 0xe0);
    *(undefined4 *)((long)puVar5 + 0x34) = uVar1;
    uVar4 = *(undefined1 *)(param_1 + 0x90);
    *(undefined1 *)(puVar5 + 7) = uVar2;
    *(undefined1 *)((long)puVar5 + 0x39) = uVar3;
    *(undefined1 *)((long)puVar5 + 0x3a) = uVar4;
    *puVar5 = 0xfffffffe0;
    puVar5[1] = puVar5 + 1;
    puVar5[2] = puVar5 + 1;
    puVar5[3] = ll_ack_fn;
    _raw_spin_lock_bh(&ll_wq_lock);
    if (ll_wq == 0) {
      kfree(puVar5);
    }
    else {
      queue_work_on(0x20,ll_wq,puVar5);
    }
    _raw_spin_unlock_bh(&ll_wq_lock);
  }
  return;
}



//------------------------------------------------------------
// ll_ack_fn @ 0011f758 size=172
// signature: undefined ll_ack_fn(void)
// callers: []
//------------------------------------------------------------

void ll_ack_fn(long param_1)

{
  long lVar1;
  int *piVar2;
  
  lVar1 = __alloc_skb(0x24,0xcc0,0,0xffffffff);
  if (lVar1 != 0) {
    piVar2 = (int *)__nlmsg_put(lVar1,*(undefined4 *)(param_1 + 0x30),
                                *(undefined4 *)(param_1 + 0x34),2,0x14,0x100);
    piVar2[4] = 0;
    piVar2[5] = 0x10;
    *(ushort *)(piVar2 + 6) = (ushort)*(byte *)(param_1 + 0x38);
    *(ushort *)((long)piVar2 + 0x1a) = (ushort)*(byte *)(param_1 + 0x39);
    piVar2[7] = (uint)*(byte *)(param_1 + 0x3a);
    piVar2[8] = *(int *)(param_1 + 0x30);
    *piVar2 = (*(int *)(lVar1 + 0xd8) + *(int *)(lVar1 + 0xd0)) - (int)piVar2;
    rtnl_unicast(lVar1,&init_net,*(undefined4 *)(param_1 + 0x30));
  }
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// init_module @ 00120860 size=148
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = register_netdevice_notifier(&rmnet_dev_notifier);
  if (iVar1 == 0) {
    iVar1 = rtnl_link_register(&rmnet_link_ops);
    if (iVar1 == 0) {
      iVar1 = rmnet_ll_init();
      if (iVar1 == 0) {
        rmnet_core_genl_init();
        try_module_get(&__this_module);
      }
      else {
        unregister_netdevice_notifier(&rmnet_dev_notifier);
        rtnl_link_unregister(&rmnet_link_ops);
      }
    }
    else {
      unregister_netdevice_notifier(&rmnet_dev_notifier);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001208f8 size=68
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_netdevice_notifier(&rmnet_dev_notifier);
  rtnl_link_unregister(&rmnet_link_ops);
  rmnet_ll_exit();
  rmnet_core_genl_deinit();
  module_put(&__this_module);
  return;
}



//------------------------------------------------------------
// __dev_get_by_index @ 0012e000 size=1
// signature: undefined __dev_get_by_index(void)
// callers: [rmnet_changelink, rmnet_newlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_get_by_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0012e010 size=1
// signature: undefined kmalloc_trace(void)
// callers: [__qmi_rmnet_bearer_get, dfc_qmi_query_flow, rmnet_frag_descriptor_add_frags_from, qmi_rmnet_work_init, wda_svc_config, wda_qmi_client_init, rmnet_map_update_ul_agg_config, rmnet_get_frag_descriptor, wda_set_powersave_mode, rmnet_update_pid_and_check_boost, dfc_tx_link_status_ind_cb, rmnet_frag_deaggregate, dfc_clnt_ind_cb, rmnet_ll_ipa_probe, ll_send_nl_ack, dfc_qmi_client_init, qmi_rmnet_qos_init, rmnet_newlink, dfc_svc_init, dfc_qmap_client_init, rmnet_frag_descriptor_add_frag, rmnet_descriptor_init, qmi_rmnet_change_link, rmnet_register_real_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0012e018 size=1
// signature: undefined kfree(void)
// callers: [dfc_qmi_query_flow, qmi_rmnet_del_flow, rmnet_frag_deliver, rmnet_dellink, rmnet_descriptor_deinit, wda_qmi_client_init, rmnet_map_update_ul_agg_config, wda_set_powersave_mode, rmnet_frag_pull, rmnet_ll_ipa_remove, rmnet_map_tx_aggregate_exit, rmnet_ll_ipa_probe, rmnet_unregister_real_device, dfc_qmap_client_exit, ll_send_nl_ack, rmnet_newlink, __qmi_rmnet_delete_client, dfc_qmi_client_exit, qmi_rmnet_change_link, rmnet_register_real_device, ll_ack_fn, rmnet_recycle_frag_descriptor, rmnet_frag_trim, dfc_qmi_ind_work, wda_svc_config, rmnet_config_notify_cb, qmi_rmnet_qos_exit_post, wda_qmi_client_exit, dfc_qmi_client_init, qmi_rmnet_work_exit, dfc_svc_init, dfc_qmap_client_init, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_rcu @ 0012e020 size=1
// signature: undefined synchronize_rcu(void)
// callers: [rmnet_dellink, dfc_qmap_client_exit, qmi_rmnet_work_exit, rmnet_config_notify_cb, dfc_qmap_client_init, qmi_rmnet_qos_exit_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_rcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_queue @ 0012e028 size=1
// signature: undefined unregister_netdevice_queue(void)
// callers: [rmnet_dellink, rmnet_config_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 0012e030 size=1
// signature: undefined nla_put(void)
// callers: [rmnet_fill_info, rmnet_core_genl_send_resp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0012e038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_rmnet_xmit_skb, rmnet_frag_deliver, trace_event_raw_event_wda_client_state_up, perf_trace_dfc_adjust_grant, perf_trace_dfc_watchdog, wda_set_powersave_mode, perf_trace_wda_client_state_down, rmnet_rx_priv_handler, trace_event_raw_event_dfc_client_state_up, perf_trace_dfc_qmap, rmnet_frag_process_next_hdr_packet, qmi_rmnet_check_stats_2, trace_event_raw_event_print_icmp, trace_event_raw_event_dfc_adjust_grant, qmi_rmnet_check_stats, trace_event_raw_event_print_skb_gso, trace_event_raw_event_dfc_pm_event, wda_svc_config, rmnet_ll_switch, rmnet_config_notify_cb, rmnet_ll_guard_fn, perf_trace_dfc_qmap_cmd, qmi_rmnet_pm_notify_cb, rmnet_frag_deaggregate, perf_trace_dfc_qmi_tc, perf_trace_wda_set_powersave_mode, rmnet_get_ethtool_stats, trace_event_raw_event_dfc_qmap, perf_trace_rmnet_freq_template, rmnet_map_move_headers, perf_trace_dfc_flow_info, perf_trace_dfc_set_powersave_mode, rmnet_fill_info, trace_event_raw_event_dfc_watchdog, trace_event_raw_event_dfc_ll_switch, perf_trace_print_icmp, perf_trace_dfc_tx_link_status_ind, perf_trace_dfc_pm_event, __rmnet_frag_segment_data, trace_event_raw_event_rmnet_freq_update, perf_trace_dfc_client_state_up, perf_trace_dfc_ll_switch, perf_trace_print_udp, perf_trace_dfc_flow_ind, trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, rmnet_frag_ipv6_skip_exthdr, rmnet_map_update_ul_agg_config, rmnet_core_genl_pid_boost_req_hdlr, trace_event_raw_event_dfc_qmap_cmd, trace_event_raw_event_wda_client_state_down, trace_event_raw_event_rmnet_mod_template, rmnet_frag_command, perf_trace_print_tcp, rmnet_vnd_select_queue, perf_trace_dfc_flow_check, trace_event_raw_event_dfc_tx_link_status_ind, trace_event_raw_event_rmnet_xmit_skb, rmnet_prepare_ps_bearers, trace_event_raw_event_rmnet_freq_template, trace_event_raw_event_dfc_flow_check, perf_trace_print_pfn, rmnet_vnd_start_xmit, qmi_rmnet_change_link, trace_event_raw_event_print_pfn, rmnet_map_process_next_hdr_packet, trace_event_raw_event_dfc_client_state_down, rmnet_ll_buffers_recycle, trace_event_raw_event_wda_set_powersave_mode, rmnet_frag_ingress_handler, trace_event_raw_event_dfc_flow_ind, perf_trace_wda_client_state_up, perf_trace_dfc_client_state_down, rmnet_map_tx_aggregate, perf_trace_rmnet_freq_update, rmnet_core_genl_tether_info_req_hdlr, trace_event_raw_event_dfc_qmi_tc, trace_event_raw_event_print_tcp, rmnet_descriptor_trace_pfn, trace_event_raw_event_dfc_set_powersave_mode, perf_trace_rmnet_mod_template, dfc_svc_init, perf_trace_print_skb_gso, rmnet_frag_flow_command, __rmnet_map_ingress_handler, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_is_locked @ 0012e040 size=1
// signature: undefined rtnl_is_locked(void)
// callers: [qmi_rmnet_del_flow, qmi_rmnet_qmi_exit, rmnet_config_notify_cb, __qmi_rmnet_delete_client, qmi_rmnet_change_link, rmnet_register_real_device, qmi_rmnet_qos_exit_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_is_locked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0012e048 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [dfc_qmap_cmd_handler, rmnet_core_genl_pid_boost_req_hdlr, rmnet_map_add_map_header, ll_qmap_send_switch, rmnet_register_real_device, rmnet_stats_reset, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_rx_handler_register @ 0012e050 size=1
// signature: undefined netdev_rx_handler_register(void)
// callers: [rmnet_config_notify_cb, rmnet_register_real_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_rx_handler_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0012e058 size=1
// signature: undefined __warn_printk(void)
// callers: [qmi_rmnet_del_flow, qmi_rmnet_qmi_exit, rmnet_config_notify_cb, __qmi_rmnet_delete_client, qmi_rmnet_change_link, rmnet_register_real_device, qmi_rmnet_qos_exit_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 0012e060 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [dev_core_stats_rx_nohandler_inc, rmnet_unregister_real_device, rmnet_vnd_start_xmit, rmnet_register_real_device, rmnet_egress_handler, rmnet_ll_ipa_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_rx_handler_unregister @ 0012e068 size=1
// signature: undefined netdev_rx_handler_unregister(void)
// callers: [rmnet_unregister_real_device, rmnet_config_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_rx_handler_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 0012e070 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [rmnet_get_packets, rmnet_module_hook_wlan_ingress_rx_handler, dfc_handle_tx_link_status_ind, rmnet_qmap_cmd_handler, dfc_qmap_set_powersave, rmnet_module_hook_aps_data_report, rmnet_module_hook_perf_ingress, rmnet_module_hook_offload_chain_end, qmi_rmnet_check_stats_2, rmnet_deliver_skb_wq, rmnet_prepare_ps_bearers, qmi_rmnet_work_maybe_restart, rmnet_module_hook_shs_switch, qmi_rmnet_check_stats, rmnet_module_hook_aps_data_active, rmnet_module_hook_perf_egress, rmnet_deliver_skb, rmnet_module_hook_wlan_flow_match, rmnet_frag_ingress_handler, rmnet_module_hook_shs_skb_ll_entry, rmnet_module_hook_aps_data_inactive, rmnet_module_hook_perf_tether_ingress, rmnet_module_hook_shs_skb_entry, rmnet_module_hook_perf_tether_egress, rmnet_module_hook_aps_post_queue, rmnet_all_flows_enabled, rmnet_module_hook_offload_ingress, dfc_do_burst_flow_control, rmnet_enable_all_flows, rmnet_module_hook_perf_tether_cmd, rmnet_module_hook_perf_set_thresh, rmnet_rx_handler, rmnet_module_hook_perf_ingress_rx_handler, rmnet_module_hook_aps_pre_queue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0012e090 size=1
// signature: undefined _find_next_bit(void)
// callers: [rmnet_get_packets, rmnet_get_stats64]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 0012e098 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [rmnet_get_packets, rmnet_module_hook_wlan_ingress_rx_handler, dfc_handle_tx_link_status_ind, rmnet_qmap_cmd_handler, dfc_qmap_set_powersave, rmnet_module_hook_aps_data_report, rmnet_module_hook_perf_ingress, rmnet_module_hook_offload_chain_end, qmi_rmnet_check_stats_2, rmnet_deliver_skb_wq, rmnet_prepare_ps_bearers, qmi_rmnet_work_maybe_restart, rmnet_module_hook_shs_switch, qmi_rmnet_check_stats, rmnet_module_hook_aps_data_active, rmnet_module_hook_perf_egress, rmnet_deliver_skb, rmnet_module_hook_wlan_flow_match, rmnet_frag_ingress_handler, rmnet_module_hook_shs_skb_ll_entry, rmnet_module_hook_aps_data_inactive, rmnet_module_hook_perf_tether_ingress, rmnet_module_hook_shs_skb_entry, rmnet_module_hook_perf_tether_egress, rmnet_module_hook_aps_post_queue, rmnet_all_flows_enabled, rmnet_module_hook_offload_ingress, dfc_do_burst_flow_control, rmnet_enable_all_flows, rmnet_module_hook_perf_tether_cmd, rmnet_module_hook_perf_set_thresh, rmnet_rx_handler, rmnet_module_hook_perf_ingress_rx_handler, rmnet_module_hook_aps_pre_queue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice_notifier @ 0012e0a0 size=1
// signature: undefined register_netdevice_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_link_register @ 0012e0a8 size=1
// signature: undefined rtnl_link_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_link_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_notifier @ 0012e0b0 size=1
// signature: undefined unregister_netdevice_notifier(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_link_unregister @ 0012e0b8 size=1
// signature: undefined rtnl_link_unregister(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_link_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 0012e0c0 size=1
// signature: undefined try_module_get(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 0012e0c8 size=1
// signature: undefined module_put(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdevice_many @ 0012e0d0 size=1
// signature: undefined unregister_netdevice_many(void)
// callers: [rmnet_config_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdevice_many(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0012e0d8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [rmnet_recycle_frag_descriptor, dfc_clnt_ind_cb, dfc_qmi_ind_work, rmnet_get_frag_descriptor, rmnet_boost_for_pid, rmnet_core_genl_pid_boost_req_hdlr, rmnet_update_pid_and_check_boost, dfc_tx_link_status_ind_cb, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0012e0e0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [rmnet_recycle_frag_descriptor, qmi_rmnet_del_flow, rmnet_ll_buffers_recycle, rmnet_ll_buffer_pool_free, rmnet_map_cmd_exit, rmnet_frag_trim, dfc_qmi_ind_work, rmnet_map_update_ul_agg_config, rmnet_get_frag_descriptor, rmnet_frag_ingress_handler, qmi_rmnet_ps_ind_deregister, qmi_rmnet_qos_exit_post, rmnet_frag_pull, __qmi_rmnet_bearer_put, rmnet_map_tx_aggregate_exit, rmnet_frag_process_next_hdr_packet, rmnet_map_dl_ind_deregister, rmnet_map_pb_ind_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0012e0e8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [rmnet_recycle_frag_descriptor, dfc_clnt_ind_cb, dfc_qmi_ind_work, rmnet_get_frag_descriptor, rmnet_boost_for_pid, rmnet_core_genl_pid_boost_req_hdlr, rmnet_update_pid_and_check_boost, dfc_tx_link_status_ind_cb, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __folio_put @ 0012e100 size=1
// signature: undefined __folio_put(void)
// callers: [rmnet_recycle_frag_descriptor, rmnet_ll_buffer_pool_free, rmnet_ll_buffers_submit, rmnet_frag_trim, rmnet_map_tx_aggregate, rmnet_frag_pull]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __folio_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0012e110 size=1
// signature: undefined __list_add_valid(void)
// callers: [rmnet_recycle_frag_descriptor, __qmi_rmnet_bearer_get, rmnet_frag_descriptor_add_frags_from, qmi_rmnet_qos_exit_pre, rmnet_ll_buffers_recycle, rmnet_map_update_ul_agg_config, rmnet_frag_ingress_handler, rmnet_map_dl_ind_register, dfc_tx_link_status_ind_cb, rmnet_frag_deaggregate, rmnet_frag_process_next_hdr_packet, dfc_clnt_ind_cb, qmi_rmnet_ps_ind_register, rmnet_map_pb_ind_register, rmnet_frag_descriptor_add_frag, rmnet_descriptor_init, __rmnet_frag_segment_data, qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0012e120 size=1
// signature: undefined _printk(void)
// callers: [dfc_qmi_query_flow, wda_qmi_client_init, wda_set_powersave_mode, rmnet_qmap_send, dfc_tx_link_status_ind_cb, rmnet_ll_ipa_rx, rmnet_frag_pull, rmnet_ll_ipa_probe, dfc_qmap_client_exit, qmi_rmnet_check_stats_2, qmi_rmnet_check_stats, dfc_qmi_client_exit, qmi_rmnet_prepare_ps_bearers, rmnet_frag_trim, wda_svc_config, rmnet_ll_ipa_init, wda_svc_exit, rmnet_qmap_init, qmi_rmnet_pm_notify_cb, qmi_rmnet_set_powersave_mode, dfc_clnt_ind_cb, wda_qmi_client_exit, dfc_qmi_client_init, rmnet_ll_ipa_ready, dfc_svc_init, dfc_qmap_client_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0012e128 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [dfc_qmi_query_flow, rmnet_frag_deliver, dfc_qmap_set_powersave, wda_set_powersave_mode, rmnet_map_linearize_copy, rmnet_get_strings, dfc_tx_link_status_ind_cb, perf_trace_dfc_qmap, rmnet_frag_process_next_hdr_packet, dfc_clnt_ind_cb, rmnet_get_ethtool_stats, trace_event_raw_event_dfc_qmap, rmnet_map_deaggregate, trace_event_raw_event_dfc_ll_switch, perf_trace_print_pfn, rmnet_frag_header_ptr, trace_event_raw_event_print_pfn, perf_trace_dfc_ll_switch, __rmnet_map_segment_coal_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_ext_hdr @ 0012e130 size=1
// signature: undefined ipv6_ext_hdr(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_ipv6_skip_exthdr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_ext_hdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 0012e138 size=1
// signature: undefined __alloc_skb(void)
// callers: [rmnet_frag_deliver, dfc_qmap_send_ack, dfc_qmap_send_config, dfc_qmap_cmd_handler, rmnet_map_deaggregate, dfc_qmap_set_powersave, dfc_send_ack, ll_qmap_send_switch, rmnet_frag_command, rmnet_core_genl_send_resp, __rmnet_map_segment_coal_skb, ll_ack_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_tx_lock @ 0012e140 size=1
// signature: undefined netif_tx_lock(void)
// callers: [rmnet_map_command, rmnet_frag_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_tx_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_tx_unlock @ 0012e148 size=1
// signature: undefined netif_tx_unlock(void)
// callers: [rmnet_map_command, rmnet_frag_command]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_tx_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 0012e150 size=1
// signature: undefined skb_copy_bits(void)
// callers: [rmnet_frag_deaggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 0012e158 size=1
// signature: undefined skb_put(void)
// callers: [rmnet_frag_deliver, dfc_qmap_send_ack, dfc_qmap_send_config, dfc_qmap_cmd_handler, rmnet_map_deaggregate, dfc_qmap_set_powersave, dfc_send_ack, rmnet_map_add_map_header, rmnet_map_linearize_copy, ll_qmap_send_switch, __rmnet_map_segment_coal_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_add_rx_frag @ 0012e160 size=1
// signature: undefined skb_add_rx_frag(void)
// callers: [rmnet_frag_deliver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_add_rx_frag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// csum_tcpudp_nofold @ 0012e168 size=1
// signature: undefined csum_tcpudp_nofold(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_deliver, rmnet_map_checksum_downlink_packet, rmnet_map_process_next_hdr_packet, __rmnet_map_segment_coal_skb, rmnet_map_partial_csum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void csum_tcpudp_nofold(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// csum_ipv6_magic @ 0012e170 size=1
// signature: undefined csum_ipv6_magic(void)
// callers: [rmnet_frag_process_next_hdr_packet, rmnet_frag_deliver, rmnet_map_checksum_downlink_packet, rmnet_map_process_next_hdr_packet, __rmnet_map_segment_coal_skb, rmnet_map_partial_csum]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void csum_ipv6_magic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_checksum @ 0012e178 size=1
// signature: undefined skb_checksum(void)
// callers: [rmnet_frag_deliver, rmnet_map_process_next_hdr_packet, __rmnet_map_segment_coal_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_checksum(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// csum_partial @ 0012e198 size=1
// signature: undefined csum_partial(void)
// callers: [rmnet_frag_process_next_hdr_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void csum_partial(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// consume_skb @ 0012e1a0 size=1
// signature: undefined consume_skb(void)
// callers: [rmnet_map_flow_command, rmnet_frag_ingress_handler, rmnet_vnd_start_xmit, rmnet_map_process_next_hdr_packet, rmnet_rx_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void consume_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 0012e1b0 size=1
// signature: undefined genlmsg_put(void)
// callers: [rmnet_core_genl_send_resp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 0012e1b8 size=1
// signature: undefined netlink_unicast(void)
// callers: [rmnet_core_genl_send_resp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_memcpy @ 0012e1c0 size=1
// signature: undefined nla_memcpy(void)
// callers: [rmnet_core_genl_pid_boost_req_hdlr, rmnet_core_genl_pid_bps_req_hdlr, rmnet_core_genl_tether_info_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_memcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_real_ts64 @ 0012e1c8 size=1
// signature: undefined ktime_get_real_ts64(void)
// callers: [rmnet_map_tx_aggregate, rmnet_core_genl_pid_bps_req_hdlr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_real_ts64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 0012e1d0 size=1
// signature: undefined genl_register_family(void)
// callers: [rmnet_core_genl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 0012e1d8 size=1
// signature: undefined genl_unregister_family(void)
// callers: [rmnet_core_genl_deinit, rmnet_core_genl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0012e1e0 size=1
// signature: size_t strlen(char * __s)
// callers: [perf_trace_rmnet_xmit_skb, trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, perf_trace_print_tcp, trace_event_raw_event_dfc_qmi_tc, perf_trace_dfc_flow_check, perf_trace_dfc_qmi_tc, trace_event_raw_event_print_tcp, trace_event_raw_event_rmnet_xmit_skb, perf_trace_dfc_flow_info, trace_event_raw_event_print_icmp, perf_trace_print_skb_gso, trace_event_raw_event_dfc_ll_switch, trace_event_raw_event_dfc_flow_check, perf_trace_print_icmp, trace_event_raw_event_print_skb_gso, perf_trace_dfc_ll_switch, perf_trace_print_udp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0012e1e8 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, trace_event_raw_event_wda_client_state_up, trace_event_raw_event_dfc_qmap_cmd, trace_event_raw_event_wda_client_state_down, trace_event_raw_event_rmnet_mod_template, trace_event_raw_event_dfc_client_state_up, trace_event_raw_event_dfc_tx_link_status_ind, trace_event_raw_event_rmnet_xmit_skb, trace_event_raw_event_print_icmp, trace_event_raw_event_rmnet_freq_template, trace_event_raw_event_dfc_adjust_grant, trace_event_raw_event_dfc_flow_check, trace_event_raw_event_print_skb_gso, trace_event_raw_event_print_pfn, trace_event_raw_event_dfc_client_state_down, trace_event_raw_event_wda_set_powersave_mode, trace_event_raw_event_dfc_pm_event, trace_event_raw_event_dfc_flow_ind, trace_event_raw_event_dfc_qmi_tc, trace_event_raw_event_print_tcp, trace_event_raw_event_dfc_qmap, trace_event_raw_event_dfc_set_powersave_mode, trace_event_raw_event_dfc_watchdog, trace_event_raw_event_dfc_ll_switch, trace_event_raw_event_rmnet_freq_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0012e1f0 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [perf_trace_rmnet_xmit_skb, trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, perf_trace_print_tcp, trace_event_raw_event_dfc_qmi_tc, perf_trace_dfc_flow_check, perf_trace_dfc_qmi_tc, trace_event_raw_event_print_tcp, trace_event_raw_event_rmnet_xmit_skb, perf_trace_dfc_flow_info, trace_event_raw_event_print_icmp, perf_trace_print_skb_gso, trace_event_raw_event_dfc_ll_switch, trace_event_raw_event_dfc_flow_check, perf_trace_print_icmp, trace_event_raw_event_print_skb_gso, perf_trace_dfc_ll_switch, perf_trace_print_udp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0012e1f8 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, trace_event_raw_event_wda_client_state_up, trace_event_raw_event_dfc_qmap_cmd, trace_event_raw_event_wda_client_state_down, trace_event_raw_event_rmnet_mod_template, trace_event_raw_event_dfc_client_state_up, trace_event_raw_event_dfc_tx_link_status_ind, trace_event_raw_event_rmnet_xmit_skb, trace_event_raw_event_print_icmp, trace_event_raw_event_rmnet_freq_template, trace_event_raw_event_dfc_adjust_grant, trace_event_raw_event_dfc_flow_check, trace_event_raw_event_print_skb_gso, trace_event_raw_event_print_pfn, trace_event_raw_event_dfc_client_state_down, trace_event_raw_event_wda_set_powersave_mode, trace_event_raw_event_dfc_pm_event, trace_event_raw_event_dfc_flow_ind, trace_event_raw_event_dfc_qmi_tc, trace_event_raw_event_print_tcp, trace_event_raw_event_dfc_qmap, trace_event_raw_event_dfc_set_powersave_mode, trace_event_raw_event_dfc_watchdog, trace_event_raw_event_dfc_ll_switch, trace_event_raw_event_rmnet_freq_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0012e200 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_dfc_flow_info, trace_event_raw_event_print_udp, trace_event_raw_event_wda_client_state_up, trace_event_raw_event_dfc_qmap_cmd, trace_event_raw_event_wda_client_state_down, trace_event_raw_event_rmnet_mod_template, trace_event_raw_event_dfc_client_state_up, trace_event_raw_event_dfc_tx_link_status_ind, trace_event_raw_event_rmnet_xmit_skb, trace_event_raw_event_print_icmp, trace_event_raw_event_rmnet_freq_template, trace_event_raw_event_dfc_adjust_grant, trace_event_raw_event_dfc_flow_check, trace_event_raw_event_print_skb_gso, trace_event_raw_event_print_pfn, trace_event_raw_event_dfc_client_state_down, trace_event_raw_event_wda_set_powersave_mode, trace_event_raw_event_dfc_pm_event, trace_event_raw_event_dfc_flow_ind, trace_event_raw_event_dfc_qmi_tc, trace_event_raw_event_print_tcp, trace_event_raw_event_dfc_qmap, trace_event_raw_event_dfc_set_powersave_mode, trace_event_raw_event_dfc_watchdog, trace_event_raw_event_dfc_ll_switch, trace_event_raw_event_rmnet_freq_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0012e208 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_rmnet_xmit_skb, perf_trace_dfc_flow_ind, perf_trace_dfc_adjust_grant, perf_trace_dfc_watchdog, perf_trace_wda_client_state_down, perf_trace_print_tcp, perf_trace_dfc_flow_check, perf_trace_dfc_qmap, perf_trace_print_pfn, perf_trace_wda_client_state_up, perf_trace_dfc_client_state_down, perf_trace_rmnet_freq_update, perf_trace_dfc_qmap_cmd, perf_trace_dfc_qmi_tc, perf_trace_wda_set_powersave_mode, perf_trace_rmnet_freq_template, perf_trace_dfc_flow_info, perf_trace_dfc_set_powersave_mode, perf_trace_rmnet_mod_template, perf_trace_print_skb_gso, perf_trace_print_icmp, perf_trace_dfc_tx_link_status_ind, perf_trace_dfc_pm_event, perf_trace_dfc_client_state_up, perf_trace_dfc_ll_switch, perf_trace_print_udp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0012e210 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_rmnet_xmit_skb, perf_trace_dfc_flow_ind, perf_trace_dfc_adjust_grant, perf_trace_dfc_watchdog, perf_trace_wda_client_state_down, perf_trace_print_tcp, perf_trace_dfc_flow_check, perf_trace_dfc_qmap, perf_trace_print_pfn, perf_trace_wda_client_state_up, perf_trace_dfc_client_state_down, perf_trace_rmnet_freq_update, perf_trace_dfc_qmap_cmd, perf_trace_dfc_qmi_tc, perf_trace_wda_set_powersave_mode, perf_trace_rmnet_freq_template, perf_trace_dfc_flow_info, perf_trace_dfc_set_powersave_mode, perf_trace_rmnet_mod_template, perf_trace_print_skb_gso, perf_trace_print_icmp, perf_trace_dfc_tx_link_status_ind, perf_trace_dfc_pm_event, perf_trace_dfc_client_state_up, perf_trace_dfc_ll_switch, perf_trace_print_udp]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run1 @ 0012e218 size=1
// signature: undefined bpf_trace_run1(void)
// callers: [__bpf_trace_rmnet_xmit_skb, __bpf_trace_dfc_set_powersave_mode, __bpf_trace_dfc_pm_event, __bpf_trace_wda_set_powersave_mode, __bpf_trace_wda_client_state_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run1(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run8 @ 0012e220 size=1
// signature: undefined bpf_trace_run8(void)
// callers: [__bpf_trace_dfc_flow_ind, __bpf_trace_rmnet_mod_template]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run7 @ 0012e228 size=1
// signature: undefined bpf_trace_run7(void)
// callers: [__bpf_trace_print_skb_gso]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run7(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run6 @ 0012e230 size=1
// signature: undefined bpf_trace_run6(void)
// callers: [__bpf_trace_print_icmp, __bpf_trace_dfc_flow_info, __bpf_trace_dfc_adjust_grant]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run6(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0012e238 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_print_tcp, __bpf_trace_dfc_qmap, __bpf_trace_dfc_client_state_up, __bpf_trace_dfc_ll_switch]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run5 @ 0012e240 size=1
// signature: undefined bpf_trace_run5(void)
// callers: [__bpf_trace_dfc_qmap_cmd, __bpf_trace_dfc_flow_check, __bpf_trace_print_udp, __bpf_trace_dfc_tx_link_status_ind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run5(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0012e248 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_print_pfn, __bpf_trace_rmnet_freq_update, __bpf_trace_dfc_watchdog, __bpf_trace_dfc_qmi_tc, __bpf_trace_wda_client_state_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run2 @ 0012e250 size=1
// signature: undefined bpf_trace_run2(void)
// callers: [__bpf_trace_rmnet_freq_template, __bpf_trace_dfc_client_state_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run2(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_receive_skb @ 0012e258 size=1
// signature: undefined netif_receive_skb(void)
// callers: [rmnet_deliver_skb_wq, rmnet_deliver_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_receive_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gro_cells_receive @ 0012e260 size=1
// signature: undefined gro_cells_receive(void)
// callers: [rmnet_deliver_skb_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gro_cells_receive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pskb_expand_head @ 0012e268 size=1
// signature: undefined pskb_expand_head(void)
// callers: [rmnet_rx_handler, rmnet_egress_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pskb_expand_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 0012e270 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [rmnet_map_tx_aggregate_exit, rmnet_map_do_flow_control, rmnet_qmap_cmd_handler, rmnet_map_command, rmnet_ll_ipa_tx, rmnet_vnd_start_xmit, rmnet_map_tx_qmap_cmd, __rmnet_map_ingress_handler, rmnet_rx_handler, rmnet_egress_handler, rmnet_ll_ipa_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_queue_xmit @ 0012e278 size=1
// signature: undefined __dev_queue_xmit(void)
// callers: [dev_queue_xmit, rmnet_rx_handler, rmnet_egress_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_queue_xmit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_push @ 0012e280 size=1
// signature: undefined skb_push(void)
// callers: [rmnet_map_v4_checksum_uplink_packet, rmnet_map_v5_checksum_uplink_packet, rmnet_map_add_map_header, rmnet_map_add_tso_header, rmnet_rx_handler, __rmnet_map_segment_coal_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_push(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netdev_core_stats_alloc @ 0012e288 size=1
// signature: undefined netdev_core_stats_alloc(void)
// callers: [dev_core_stats_rx_nohandler_inc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netdev_core_stats_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_bh @ 0012e290 size=1
// signature: undefined _raw_spin_lock_bh(void)
// callers: [rmnet_ll_wq_exit, qmi_rmnet_del_flow, dfc_qmi_burst_check, dfc_handle_tx_link_status_ind, rmnet_map_update_ul_agg_config, qmi_rmnet_enable_all_flows, rmnet_map_tx_qmap_cmd, rmnet_ll_ipa_remove, rmnet_map_tx_aggregate_exit, ll_send_nl_ack, rmnet_ll_ipa_tx_pending, qmi_rmnet_change_link, qmi_rmnet_prepare_ps_bearers, qmi_rmnet_watchdog_fn, ll_qmap_cmd_handler, rmnet_ll_send_skb, dfc_qmap_cmd_handler, qmi_rmnet_get_queue, rmnet_ll_switch, rmnet_map_tx_aggregate, rmnet_ll_guard_fn, rmnet_map_flush_tx_packet_work, dfc_do_burst_flow_control, rmnet_egress_handler, qmi_rmnet_all_flows_enabled]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0012e298 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_print_udp, trace_raw_output_dfc_adjust_grant, trace_raw_output_dfc_pm_event, trace_raw_output_dfc_watchdog, trace_raw_output_print_pfn, trace_raw_output_dfc_client_state_up, trace_raw_output_dfc_tx_link_status_ind, trace_raw_output_print_icmp, trace_raw_output_wda_set_powersave_mode, trace_raw_output_print_skb_gso, trace_raw_output_wda_client_state_down, trace_raw_output_print_tcp, trace_raw_output_dfc_flow_ind, trace_raw_output_dfc_qmap, trace_raw_output_rmnet_freq_template, trace_raw_output_dfc_set_powersave_mode, trace_raw_output_dfc_ll_switch, trace_raw_output_dfc_flow_check, trace_raw_output_dfc_flow_info, trace_raw_output_rmnet_mod_template, trace_raw_output_wda_client_state_up, trace_raw_output_rmnet_freq_update, trace_raw_output_dfc_qmi_tc, trace_raw_output_dfc_qmap_cmd, trace_raw_output_rmnet_xmit_skb, trace_raw_output_dfc_client_state_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0012e2a0 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_print_udp, trace_raw_output_dfc_adjust_grant, trace_raw_output_dfc_pm_event, trace_raw_output_dfc_watchdog, trace_raw_output_print_pfn, trace_raw_output_dfc_client_state_up, trace_raw_output_dfc_tx_link_status_ind, trace_raw_output_print_icmp, trace_raw_output_wda_set_powersave_mode, trace_raw_output_print_skb_gso, trace_raw_output_wda_client_state_down, trace_raw_output_print_tcp, trace_raw_output_dfc_flow_ind, trace_raw_output_dfc_qmap, trace_raw_output_rmnet_freq_template, trace_raw_output_dfc_set_powersave_mode, trace_raw_output_dfc_ll_switch, trace_raw_output_dfc_flow_check, trace_raw_output_dfc_flow_info, trace_raw_output_rmnet_mod_template, trace_raw_output_wda_client_state_up, trace_raw_output_rmnet_freq_update, trace_raw_output_dfc_qmi_tc, trace_raw_output_dfc_qmap_cmd, trace_raw_output_rmnet_xmit_skb, trace_raw_output_dfc_client_state_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0012e2a8 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_print_udp, trace_raw_output_dfc_adjust_grant, trace_raw_output_dfc_pm_event, trace_raw_output_dfc_watchdog, trace_raw_output_print_pfn, trace_raw_output_dfc_client_state_up, trace_raw_output_dfc_tx_link_status_ind, trace_raw_output_print_icmp, trace_raw_output_wda_set_powersave_mode, trace_raw_output_print_skb_gso, trace_raw_output_wda_client_state_down, trace_raw_output_print_tcp, trace_raw_output_dfc_flow_ind, trace_raw_output_dfc_qmap, trace_raw_output_rmnet_freq_template, trace_raw_output_dfc_set_powersave_mode, trace_raw_output_dfc_ll_switch, trace_raw_output_dfc_flow_check, trace_raw_output_dfc_flow_info, trace_raw_output_rmnet_mod_template, trace_raw_output_wda_client_state_up, trace_raw_output_rmnet_freq_update, trace_raw_output_dfc_qmi_tc, trace_raw_output_dfc_qmap_cmd, trace_raw_output_rmnet_xmit_skb, trace_raw_output_dfc_client_state_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_print_array_seq @ 0012e2b0 size=1
// signature: undefined trace_print_array_seq(void)
// callers: [trace_raw_output_dfc_ll_switch, trace_raw_output_dfc_qmap, trace_raw_output_print_pfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_print_array_seq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pskb_pull_tail @ 0012e2b8 size=1
// signature: undefined __pskb_pull_tail(void)
// callers: [rmnet_map_move_headers, rmnet_map_flow_command, rmnet_map_deaggregate, __rmnet_map_ingress_handler, rmnet_map_process_next_hdr_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pskb_pull_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___pskb_trim @ 0012e2c0 size=1
// signature: undefined ___pskb_trim(void)
// callers: [rmnet_map_command, __rmnet_map_ingress_handler, rmnet_map_process_next_hdr_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___pskb_trim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_append_pagefrags @ 0012e2d8 size=1
// signature: undefined skb_append_pagefrags(void)
// callers: [rmnet_map_deaggregate, __rmnet_map_segment_coal_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_append_pagefrags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ip_compute_csum @ 0012e2e0 size=1
// signature: undefined ip_compute_csum(void)
// callers: [rmnet_map_checksum_downlink_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ip_compute_csum(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipv6_skip_exthdr @ 0012e2e8 size=1
// signature: undefined ipv6_skip_exthdr(void)
// callers: [rmnet_map_move_headers, rmnet_map_process_next_hdr_packet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipv6_skip_exthdr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0012e2f8 size=1
// signature: undefined queue_work_on(void)
// callers: [dfc_clnt_ind_cb, ll_send_nl_ack, wda_svc_arrive, dfc_svc_arrive, rmnet_map_flush_tx_packet_queue, dfc_tx_link_status_ind_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_bh @ 0012e300 size=1
// signature: undefined _raw_spin_unlock_bh(void)
// callers: [rmnet_ll_wq_exit, qmi_rmnet_del_flow, dfc_qmi_burst_check, dfc_handle_tx_link_status_ind, rmnet_map_update_ul_agg_config, qmi_rmnet_enable_all_flows, rmnet_map_tx_qmap_cmd, rmnet_ll_ipa_remove, rmnet_map_tx_aggregate_exit, ll_send_nl_ack, rmnet_ll_ipa_tx_pending, qmi_rmnet_change_link, qmi_rmnet_prepare_ps_bearers, qmi_rmnet_watchdog_fn, ll_qmap_cmd_handler, rmnet_ll_send_skb, dfc_qmap_cmd_handler, qmi_rmnet_get_queue, rmnet_ll_switch, rmnet_map_tx_aggregate, rmnet_ll_guard_fn, rmnet_map_flush_tx_packet_work, dfc_do_burst_flow_control, qmi_rmnet_all_flows_enabled, rmnet_map_send_agg_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 0012e308 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [rmnet_map_tx_aggregate_exit, rmnet_map_tx_aggregate, rmnet_map_tx_qmap_cmd, rmnet_map_send_agg_skb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_normalized_timespec64 @ 0012e310 size=1
// signature: undefined set_normalized_timespec64(void)
// callers: [rmnet_map_tx_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_normalized_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_kfree_skb_any @ 0012e318 size=1
// signature: undefined __dev_kfree_skb_any(void)
// callers: [rmnet_map_tx_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_kfree_skb_any(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 0012e320 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [rmnet_map_tx_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_mem_get_pages_entry @ 0012e328 size=1
// signature: undefined rmnet_mem_get_pages_entry(void)
// callers: [rmnet_map_update_ul_agg_config, rmnet_map_tx_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_mem_get_pages_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// build_skb @ 0012e330 size=1
// signature: undefined build_skb(void)
// callers: [rmnet_map_tx_aggregate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void build_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_mem_put_page_entry @ 0012e338 size=1
// signature: undefined rmnet_mem_put_page_entry(void)
// callers: [rmnet_map_tx_aggregate_exit, rmnet_map_update_ul_agg_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_mem_put_page_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 0012e340 size=1
// signature: undefined hrtimer_init(void)
// callers: [rmnet_map_tx_aggregate_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0012e348 size=1
// signature: undefined cancel_work_sync(void)
// callers: [rmnet_map_tx_aggregate_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 0012e350 size=1
// signature: undefined get_random_bytes(void)
// callers: [rmnet_vnd_setup, rmnet_vnd_reset_mac_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdevice @ 0012e358 size=1
// signature: undefined register_netdevice(void)
// callers: [rmnet_vnd_newlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdevice(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_tx_wake_queue @ 0012e368 size=1
// signature: undefined netif_tx_wake_queue(void)
// callers: [qmi_rmnet_del_flow, qmi_rmnet_flow_control, rmnet_vnd_do_flow_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_tx_wake_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_percpu @ 0012e370 size=1
// signature: undefined __alloc_percpu(void)
// callers: [rmnet_vnd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gro_cells_init @ 0012e378 size=1
// signature: undefined gro_cells_init(void)
// callers: [rmnet_vnd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gro_cells_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu @ 0012e380 size=1
// signature: undefined free_percpu(void)
// callers: [rmnet_vnd_uninit, rmnet_vnd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gro_cells_destroy @ 0012e388 size=1
// signature: undefined gro_cells_destroy(void)
// callers: [rmnet_vnd_uninit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gro_cells_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __skb_gso_segment @ 0012e390 size=1
// signature: undefined __skb_gso_segment(void)
// callers: [rmnet_vnd_start_xmit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __skb_gso_segment(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_ctl_get_stats @ 0012e398 size=1
// signature: undefined rmnet_ctl_get_stats(void)
// callers: [rmnet_get_ethtool_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_ctl_get_stats(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0012e3a0 size=1
// signature: undefined alloc_workqueue(void)
// callers: [rmnet_ll_wq_init, dfc_qmi_client_init, qmi_rmnet_work_init, wda_qmi_client_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 0012e3a8 size=1
// signature: undefined qmi_handle_init(void)
// callers: [dfc_qmi_client_init, wda_qmi_client_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 0012e3b0 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [dfc_qmi_client_init, wda_qmi_client_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 0012e3b8 size=1
// signature: undefined qmi_handle_release(void)
// callers: [dfc_qmi_client_init, wda_qmi_client_init, wda_qmi_client_release, dfc_qmi_client_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0012e3c0 size=1
// signature: undefined destroy_workqueue(void)
// callers: [rmnet_ll_wq_exit, wda_qmi_client_exit, dfc_qmi_client_init, qmi_rmnet_work_init, wda_qmi_client_init, qmi_rmnet_work_exit, dfc_qmi_client_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 0012e3c8 size=1
// signature: undefined qmi_txn_init(void)
// callers: [dfc_qmi_query_flow, wda_svc_config, dfc_svc_init, wda_set_powersave_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 0012e3d0 size=1
// signature: undefined qmi_send_request(void)
// callers: [dfc_qmi_query_flow, wda_svc_config, dfc_svc_init, wda_set_powersave_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 0012e3d8 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [dfc_qmi_query_flow, wda_svc_config, dfc_svc_init, wda_set_powersave_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_trylock @ 0012e3e0 size=1
// signature: undefined rtnl_trylock(void)
// callers: [wda_svc_config, dfc_svc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_unlock @ 0012e3e8 size=1
// signature: undefined rtnl_unlock(void)
// callers: [wda_svc_config, dfc_svc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 0012e3f0 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [dfc_qmi_query_flow, wda_svc_config, dfc_svc_init, wda_set_powersave_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// drain_workqueue @ 0012e3f8 size=1
// signature: undefined drain_workqueue(void)
// callers: [dfc_qmi_client_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void drain_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __local_bh_enable_ip @ 0012e400 size=1
// signature: undefined __local_bh_enable_ip(void)
// callers: [local_bh_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __local_bh_enable_ip(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 0012e410 size=1
// signature: undefined mod_timer(void)
// callers: [ll_qmap_cmd_handler, rmnet_ll_switch, qmi_rmnet_watchdog_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 0012e418 size=1
// signature: undefined del_timer(void)
// callers: [qmi_rmnet_watchdog_remove, ll_qmap_cmd_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0012e420 size=1
// signature: undefined init_timer_key(void)
// callers: [__qmi_rmnet_bearer_get, qmi_rmnet_work_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 0012e428 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer_sync @ 0012e430 size=1
// signature: undefined del_timer_sync(void)
// callers: [qmi_rmnet_del_flow, qmi_rmnet_qos_exit_pre, qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 0012e438 size=1
// signature: undefined __flush_workqueue(void)
// callers: [qmi_rmnet_flush_ps_wq, qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 0012e440 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [qmi_rmnet_work_exit, qmi_rmnet_change_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0012e450 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [qmi_rmnet_work_exit, qmi_rmnet_pm_notify_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0012e458 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [qmi_rmnet_check_stats_2, qmi_rmnet_check_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0012e460 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [qmi_rmnet_check_stats_2, qmi_rmnet_work_maybe_restart, qmi_rmnet_check_stats]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0012e468 size=1
// signature: undefined msleep(void)
// callers: [wda_svc_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_pages @ 0012e470 size=1
// signature: undefined __alloc_pages(void)
// callers: [rmnet_ll_buffers_recycle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_rmnet_ll_xmit @ 0012e478 size=1
// signature: undefined ipa_rmnet_ll_xmit(void)
// callers: [rmnet_ll_ipa_tx_pending, rmnet_ll_ipa_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_rmnet_ll_xmit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_register_ipa_ready_cb @ 0012e480 size=1
// signature: undefined ipa_register_ipa_ready_cb(void)
// callers: [rmnet_ll_ipa_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_register_ipa_ready_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_register_rmnet_ll_cb @ 0012e488 size=1
// signature: undefined ipa_register_rmnet_ll_cb(void)
// callers: [rmnet_ll_ipa_ready, rmnet_ll_ipa_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_register_rmnet_ll_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipa_unregister_rmnet_ll_cb @ 0012e490 size=1
// signature: undefined ipa_unregister_rmnet_ll_cb(void)
// callers: [rmnet_ll_ipa_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipa_unregister_rmnet_ll_cb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_by_name @ 0012e4a0 size=1
// signature: undefined dev_get_by_name(void)
// callers: [rmnet_ll_ipa_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tasklet_schedule @ 0012e4a8 size=1
// signature: undefined __tasklet_schedule(void)
// callers: [rmnet_ll_ipa_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_rx @ 0012e4b0 size=1
// signature: undefined netif_rx(void)
// callers: [rmnet_ll_ipa_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_rx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rmnet_ctl_if @ 0012e4b8 size=1
// signature: undefined rmnet_ctl_if(void)
// callers: [rmnet_qmap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rmnet_ctl_if(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __nlmsg_put @ 0012e4c0 size=1
// signature: undefined __nlmsg_put(void)
// callers: [ll_ack_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __nlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtnl_unicast @ 0012e4c8 size=1
// signature: undefined rtnl_unicast(void)
// callers: [ll_ack_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtnl_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



