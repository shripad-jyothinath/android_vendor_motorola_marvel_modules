// Decompiled by Ghidra 12.2
// Program: qti_glink_charger.ko
// Image base: 00100000

//------------------------------------------------------------
// qti_charger_set_property @ 001014fc size=76
// signature: undefined qti_charger_set_property(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_charger_set_property(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = qti_charger_write(this_chip,param_1,param_2,param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// qti_charger_write @ 00101548 size=700
// signature: undefined qti_charger_write(void)
// callers: [thermal_secondary_charge_control_limit_store, addr_store, qti_charger_set_constraint, qti_charger_init, qti_charger_set_property, usb_therm_set_mosfet, tx_mode_store, wls_weak_charge_disable_store, qti_charger_get_chg_info, tcmd_store, wls_input_current_limit_store, qti_charger_config_charge, data_store, folio_mode_store, wlc_light_ctl_store, typec_reset_store, force_wls_volt_max_store, wlc_fan_speed_store, wls_fod_gain_store, fg_operation_store, force_usb_suspend_store, thermal_primary_charge_control_limit_store, wls_fod_curr_store, force_wls_en_store, force_wls_curr_max_store, force_pmic_icl_store]
//------------------------------------------------------------

int qti_charger_write(undefined8 *param_1,undefined4 param_2,void *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (param_4 < 0x41) {
    if (*(int *)((long)param_1 + 0x1a4) == 0) {
      _printk(&DAT_0010de13,*param_1,"qti_charger_write");
      ipc_log_string(param_1[0x55],"E %s: %s: ADSP glink state is down\n",*param_1,
                     "qti_charger_write");
      iVar2 = -0x6b;
    }
    else {
      local_60 = 0;
      uStack_58 = 0;
      local_a0 = 0x10000800e;
      local_70 = 0;
      uStack_68 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_98 = 0x10001;
      local_50 = (undefined4)param_4;
      uStack_94 = param_2;
      memcpy(&local_90,param_3,param_4);
      mutex_lock(param_1 + 0x11);
      *(undefined4 *)(param_1 + 7) = 0;
      if (*(char *)param_1[0x67] != '\0') {
        _printk(&DAT_0010dbfc,*param_1,"qti_charger_write",param_2,param_4);
      }
      ipc_log_string(param_1[0x55],"D %s: %s: Start data write for property: %u, len=%zu\n",*param_1
                     ,"qti_charger_write",param_2,param_4);
      iVar2 = pmic_glink_write(param_1[2],&local_a0,0x54);
      if (iVar2 < 0) {
        _printk(&DAT_0010b371,*param_1,"qti_charger_write",iVar2,param_2);
        ipc_log_string(param_1[0x55],"E %s: %s: Error in sending message rc=%d on property: %u\n",
                       *param_1,"qti_charger_write",iVar2,param_2);
      }
      else {
        iVar2 = wait_for_completion_timeout(param_1 + 7,0x4e2);
        if (iVar2 == 0) {
          _printk(&DAT_0010eefa,*param_1,"qti_charger_write",param_2);
          ipc_log_string(param_1[0x55],"E %s: %s: timed out on property: %u\n",*param_1,
                         "qti_charger_write",param_2);
          iVar2 = -0x6e;
        }
        else {
          bm_ulog_print_log(0x1000);
          iVar2 = 0;
        }
      }
      if (*(char *)param_1[0x67] != '\0') {
        _printk(&DAT_0010e852,*param_1,"qti_charger_write",param_2);
      }
      ipc_log_string(param_1[0x55],"D %s: %s: Complete data write for property: %u\n",*param_1,
                     "qti_charger_write",param_2);
      mutex_unlock(param_1 + 0x11);
    }
  }
  else {
    _printk(&DAT_0010e1e4,*param_1,"qti_charger_write",param_4,param_2);
    ipc_log_string(param_1[0x55],"E %s: %s: Incorrect data length %zu for property: %u\n",*param_1,
                   "qti_charger_write",param_4,param_2);
    iVar2 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qti_charger_get_property @ 00101808 size=76
// signature: undefined qti_charger_get_property(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_charger_get_property(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 uVar1;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = qti_charger_read(this_chip,param_1,param_2,param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// qti_charger_read @ 00101854 size=780
// signature: undefined qti_charger_read(void)
// callers: [wireless_fw_ver_show, cur_batt_id_show, tcmd_show, qti_charger_get_chg_info, wireless_chip_id_show, rx_dev_id_show, wlc_tx_capability_show, force_wls_volt_max_show, wlc_fac_ibus_current_show, wlc_tx_power_show, force_wls_curr_max_show, qti_charger_get_property, rx_dev_manufacturing_show, battery_psy_get_prop, wlc_tx_type_show, rx_dev_type_show, force_wls_en_show, qti_charger_get_batt_info, tx_mode_vout_show, data_show, show_wls_dump_info, tx_mode_show, wlc_tx_sn_show, force_usb_suspend_show, force_pmic_icl_show, wlc_tx_id_show, wlc_fac_vbus_voltage_show]
//------------------------------------------------------------

int qti_charger_read(undefined8 *param_1,undefined4 param_2,void *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_70;
  undefined4 local_68;
  undefined4 uStack_64;
  undefined4 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if (0x40 < param_4) {
    _printk(&DAT_0010e1e4,*param_1,"qti_charger_read",param_4,param_2);
    ipc_log_string(param_1[0x55],"E %s: %s: Incorrect data length %zu for property: %u\n",*param_1,
                   "qti_charger_read",param_4,param_2);
    iVar2 = -0x16;
    goto LAB_00101b04;
  }
  if (*(int *)((long)param_1 + 0x1a4) == 0) {
    _printk(&DAT_0010de13,*param_1,"qti_charger_read");
    ipc_log_string(param_1[0x55],"E %s: %s: ADSP glink state is down\n",*param_1,"qti_charger_read")
    ;
    iVar2 = -0x6b;
    goto LAB_00101b04;
  }
  local_60 = (undefined4)param_4;
  local_70 = 0x10000800e;
  local_68 = 0x10000;
  uStack_64 = param_2;
  mutex_lock(param_1 + 0xb);
  *(undefined4 *)(param_1 + 3) = 0;
  if (*(char *)param_1[0x67] != '\0') {
    _printk(&DAT_0010ce00,*param_1,"qti_charger_read",param_2,param_4);
  }
  ipc_log_string(param_1[0x55],"D %s: %s: Start data read for property: %u, len=%zu\n",*param_1,
                 "qti_charger_read",param_2,param_4);
  iVar2 = pmic_glink_write(param_1[2],&local_70,0x14);
  if (iVar2 < 0) {
    _printk(&DAT_0010b371,*param_1,"qti_charger_read",iVar2,param_2);
    ipc_log_string(param_1[0x55],"E %s: %s: Error in sending message rc=%d on property: %u\n",
                   *param_1,"qti_charger_read",iVar2,param_2);
  }
  else {
    iVar2 = wait_for_completion_timeout(param_1 + 3,0x4e2);
    if (iVar2 == 0) {
      _printk(&DAT_0010eefa,*param_1,"qti_charger_read",param_2);
      ipc_log_string(param_1[0x55],"E %s: %s: timed out on property: %u\n",*param_1,
                     "qti_charger_read",param_2);
      iVar2 = -0x6e;
    }
    else {
      if (*(int *)((long)param_1 + 0x10c) != 0) {
        if (*(uint *)(param_1 + 0x21) == param_4) {
          memcpy(param_3,param_1 + 0x19,param_4);
          iVar2 = 0;
          *(undefined4 *)((long)param_1 + 0x10c) = 0;
          goto LAB_00101ad0;
        }
        _printk(&DAT_0010d8bb,*param_1,"qti_charger_read",(ulong)*(uint *)(param_1 + 0x21),param_2);
        ipc_log_string(param_1[0x55],"E %s: %s: Invalid data size %u, on property: %u\n",*param_1,
                       "qti_charger_read",*(undefined4 *)(param_1 + 0x21),param_2);
      }
      iVar2 = -0x3d;
    }
  }
LAB_00101ad0:
  if (*(char *)param_1[0x67] != '\0') {
    _printk(&DAT_0010c596,*param_1,"qti_charger_read",param_2);
  }
  ipc_log_string(param_1[0x55],"D %s: %s: Complete data read for property: %u\n",*param_1,
                 "qti_charger_read",param_2);
  mutex_unlock(param_1 + 0xb);
LAB_00101b04:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qti_charger_register_notifier @ 00101b64 size=40
// signature: undefined qti_charger_register_notifier(void)
// callers: []
//------------------------------------------------------------

void qti_charger_register_notifier(undefined8 param_1)

{
  blocking_notifier_chain_register(&qti_chg_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// qti_charger_unregister_notifier @ 00101b90 size=40
// signature: undefined qti_charger_unregister_notifier(void)
// callers: []
//------------------------------------------------------------

void qti_charger_unregister_notifier(undefined8 param_1)

{
  blocking_notifier_chain_unregister(&qti_chg_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// qti_wireless_charge_dump_info @ 00101bbc size=488
// signature: undefined qti_wireless_charge_dump_info(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

void qti_wireless_charge_dump_info(undefined8 *param_1,undefined4 *param_2)

{
  _printk(&DAT_0010ed3c,*param_1,"qti_wireless_charge_dump_info",*param_2,param_2[1],param_2[2],
          *(undefined2 *)(param_2 + 3),*(undefined2 *)((long)param_2 + 0xe),
          *(undefined2 *)(param_2 + 4),*(undefined2 *)((long)param_2 + 0x12),
          *(undefined2 *)(param_2 + 5),*(undefined2 *)((long)param_2 + 0x16),
          *(undefined2 *)(param_2 + 6));
  ipc_log_string(param_1[0x55],
                 "I %s: %s: Wireless dump info -1: CHIP_ID: 0x%04x, MTP_FW_VER: 0x%04x, IRQ STATUS: 0x%04x, SYS_MODE:  RX/TX %d, OP_MODE:  BPP/EPP 0x%x, RX_FOP: %dkHz, RX_VOUT: %dmV, RX_VRECT: %dmV, RX_IRECT: %dmV, RX_NEG_POWER: %dw "
                 ,*param_1,"qti_wireless_charge_dump_info",*param_2,param_2[1],param_2[2],
                 *(undefined2 *)(param_2 + 3),*(undefined2 *)((long)param_2 + 0xe),
                 *(undefined2 *)(param_2 + 4),*(undefined2 *)((long)param_2 + 0x12),
                 *(undefined2 *)(param_2 + 5),*(undefined2 *)((long)param_2 + 0x16),
                 *(undefined2 *)(param_2 + 6));
  _printk(&DAT_0010b6ce,*param_1,"qti_wireless_charge_dump_info",
          *(undefined2 *)((long)param_2 + 0x1a),*(undefined2 *)(param_2 + 7),
          *(undefined2 *)((long)param_2 + 0x1e),*(undefined2 *)((long)param_2 + 0x26),
          *(undefined2 *)(param_2 + 10),(int)*(short *)((long)param_2 + 0x2a),
          (uint)param_2[2] >> 0xc & 1);
  ipc_log_string(param_1[0x55],
                 "I %s: %s: Wireless dump info -2: TX_IIN: %dmA, TX_VIN: %dmV, TX_VRECT: %dmV, TX_DET_RX_POWER: %dmW, TX_POWER: %dmW, POWER_LOSS: %dmW, TX_FOD: %d, "
                 ,*param_1,"qti_wireless_charge_dump_info",*(undefined2 *)((long)param_2 + 0x1a),
                 *(undefined2 *)(param_2 + 7),*(undefined2 *)((long)param_2 + 0x1e),
                 *(undefined2 *)((long)param_2 + 0x26),*(undefined2 *)(param_2 + 10),
                 (int)*(short *)((long)param_2 + 0x2a),(uint)param_2[2] >> 0xc & 1);
  _printk(&DAT_0010b761,*param_1,"qti_wireless_charge_dump_info",*(undefined2 *)(param_2 + 0xb),
          *(undefined2 *)((long)param_2 + 0x2e),*(undefined2 *)(param_2 + 0xc),
          *(undefined2 *)((long)param_2 + 0x32),*(undefined2 *)(param_2 + 0xd),
          *(undefined2 *)((long)param_2 + 0x36),*(undefined2 *)(param_2 + 0xe),
          *(undefined2 *)((long)param_2 + 0x3a));
  ipc_log_string(param_1[0x55],
                 "I %s: %s: Wireless dump info -3: FOLIO_MODE: %d, PEN_STATUS: %d, PEN_SOC: %d, PEN_ERROR: %d, USB_OTG: %d, WLS_BOOST: %d, WLS_ICL_MA: %dmA, WLS_ICL_THERM_MA: %dmA"
                 ,*param_1,"qti_wireless_charge_dump_info",*(undefined2 *)(param_2 + 0xb),
                 *(undefined2 *)((long)param_2 + 0x2e),*(undefined2 *)(param_2 + 0xc),
                 *(undefined2 *)((long)param_2 + 0x32),*(undefined2 *)(param_2 + 0xd),
                 *(undefined2 *)((long)param_2 + 0x36),*(undefined2 *)(param_2 + 0xe),
                 *(undefined2 *)((long)param_2 + 0x3a));
  return;
}



//------------------------------------------------------------
// qti_switched_dump_info @ 00101da8 size=264
// signature: undefined qti_switched_dump_info(void)
// callers: []
//------------------------------------------------------------

void qti_switched_dump_info(undefined8 *param_1,undefined1 *param_2)

{
  _printk(&DAT_0010ee14,*param_1,"qti_switched_dump_info",param_2[1],param_2[2],*param_2,param_2[3],
          param_2[4],*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
          *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
          *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
          *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),
          *(undefined4 *)(param_2 + 0x28));
  ipc_log_string(param_1[0x55],
                 "I %s: %s: switchedcap dump info [0x%02x-%d]: chg_en %d, work_mode 0x%x, int_stat 0x%x, ibat_ma %d, ibus_ma %d, vbus_mv %d, vout_mv %d, vac_mv %d, vbat_mv %d, vusb_mv %d, vwpc_mv %d, die_temp %d"
                 ,*param_1,"qti_switched_dump_info",param_2[1],param_2[2],*param_2,param_2[3],
                 param_2[4],*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc),
                 *(undefined4 *)(param_2 + 0x10),*(undefined4 *)(param_2 + 0x14),
                 *(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),
                 *(undefined4 *)(param_2 + 0x20),*(undefined4 *)(param_2 + 0x24),
                 *(undefined4 *)(param_2 + 0x28));
  return;
}



//------------------------------------------------------------
// qti_fg_charge_dump_info @ 00101eb4 size=192
// signature: undefined qti_fg_charge_dump_info(void)
// callers: []
//------------------------------------------------------------

void qti_fg_charge_dump_info(undefined8 *param_1,undefined1 *param_2)

{
  _printk(&DAT_0010c77e,*param_1,"qti_fg_charge_dump_info",*param_2,(long)*(short *)(param_2 + 6),
          *(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),(long)*(short *)(param_2 + 8),
          *(undefined2 *)(param_2 + 10),*(undefined4 *)(param_2 + 0xc),
          *(undefined4 *)(param_2 + 0x10));
  ipc_log_string(param_1[0x55],
                 "I %s: %s: FG dump info: WORK_MODE: 0x%x, SOC: %d, VOLTAGE_MV: %dmV, CURRENT_MA: %dmA, TEMP: %d, CYCLE_COUNT: %d, REMAINING_CAPACITY: %d, FULL_CAPACITY: %d"
                 ,*param_1,"qti_fg_charge_dump_info",*param_2,(long)*(short *)(param_2 + 6),
                 *(undefined2 *)(param_2 + 4),*(undefined2 *)(param_2 + 2),
                 (int)*(short *)(param_2 + 8),*(undefined2 *)(param_2 + 10),
                 *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10));
  return;
}



//------------------------------------------------------------
// qti_charger_probe @ 00101f78 size=3728
// signature: undefined qti_charger_probe(void)
// callers: []
//------------------------------------------------------------

ulong qti_charger_probe(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  int *piVar3;
  uint *puVar4;
  long lVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined8 *puVar13;
  long lVar14;
  char *pcVar15;
  size_t sVar16;
  ulong uVar17;
  undefined *puVar18;
  undefined8 uVar19;
  int param2;
  int iVar20;
  long *plVar21;
  uint local_1dc;
  undefined *local_1d8;
  undefined8 local_1d0;
  undefined8 *local_1c8;
  code *local_1c0;
  code *local_1b8;
  uint local_1ac;
  char *local_1a8;
  int local_1a0;
  uint local_19c;
  char *local_198;
  char local_190 [24];
  char local_178 [8];
  char acStack_170 [8];
  undefined8 local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined2 local_148;
  char local_140 [128];
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined4 local_b0;
  char *local_a8;
  char acStack_a0 [8];
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  long local_70;
  
  lVar14 = sp_el0;
  lVar2 = param_1 + 0x10;
  local_70 = *(long *)(lVar14 + 0x638);
  local_1c0 = (code *)0x0;
  local_1b8 = (code *)0x0;
  local_1d0 = 0;
  local_1c8 = (undefined8 *)0x0;
  local_1d8 = (undefined *)0x0;
  puVar13 = (undefined8 *)devm_kmalloc(lVar2,0x428,0xdc0);
  if (puVar13 == (undefined8 *)0x0) {
    uVar17 = 0xfffffff4;
    goto LAB_001024d4;
  }
  puVar13[0x22] = 0xfffffffe0;
  puVar13[0x23] = puVar13 + 0x23;
  puVar13[0x24] = puVar13 + 0x23;
  puVar13[0x25] = qti_charger_setup_work;
  puVar13[0x28] = 0xfffffffe0;
  puVar13[0x29] = puVar13 + 0x29;
  puVar13[0x2a] = puVar13 + 0x29;
  puVar13[0x2b] = qti_charger_notify_work;
  __mutex_init(puVar13 + 0xb,"&chg->read_lock",&qti_charger_probe___key);
  __mutex_init(puVar13 + 0x11,"&chg->write_lock",&qti_charger_probe___key_36);
  *(undefined4 *)(puVar13 + 3) = 0;
  __init_swait_queue_head(puVar13 + 4,"&x->wait",&init_completion___key);
  *(undefined4 *)(puVar13 + 7) = 0;
  __init_swait_queue_head(puVar13 + 8,"&x->wait",&init_completion___key);
  *(undefined4 *)((long)puVar13 + 0x10c) = 0;
  *(undefined4 *)((long)puVar13 + 0x1a4) = 1;
  *(undefined8 **)(param_1 + 0xa8) = puVar13;
  *puVar13 = "qti_glink_charger";
  puVar13[1] = lVar2;
  puVar13[0x67] = &debug_enabled;
  lVar14 = ipc_log_context_create(0x32,"mmi_charger",0);
  puVar13[0x55] = lVar14;
  if (lVar14 == 0) {
    _printk(&DAT_0010cad2,*puVar13,"qti_charger_probe");
    ipc_log_string(puVar13[0x55],"W %s: %s: Error in creating ipc_log_context\n",*puVar13,
                   "qti_charger_probe");
  }
  local_140[0x70] = '\0';
  local_140[0x71] = '\0';
  local_140[0x72] = '\0';
  local_140[0x73] = '\0';
  local_140[0x74] = '\0';
  local_140[0x75] = '\0';
  local_140[0x76] = '\0';
  local_140[0x77] = '\0';
  local_140[0x78] = '\0';
  local_140[0x79] = '\0';
  local_140[0x7a] = '\0';
  local_140[0x7b] = '\0';
  local_140[0x7c] = '\0';
  local_140[0x7d] = '\0';
  local_140[0x7e] = '\0';
  local_140[0x7f] = '\0';
  local_140[0x60] = '\0';
  local_140[0x61] = '\0';
  local_140[0x62] = '\0';
  local_140[99] = '\0';
  local_140[100] = '\0';
  local_140[0x65] = '\0';
  local_140[0x66] = '\0';
  local_140[0x67] = '\0';
  local_140[0x68] = '\0';
  local_140[0x69] = '\0';
  local_140[0x6a] = '\0';
  local_140[0x6b] = '\0';
  local_140[0x6c] = '\0';
  local_140[0x6d] = '\0';
  local_140[0x6e] = '\0';
  local_140[0x6f] = '\0';
  local_140[0x50] = '\0';
  local_140[0x51] = '\0';
  local_140[0x52] = '\0';
  local_140[0x53] = '\0';
  local_140[0x54] = '\0';
  local_140[0x55] = '\0';
  local_140[0x56] = '\0';
  local_140[0x57] = '\0';
  local_140[0x58] = '\0';
  local_140[0x59] = '\0';
  local_140[0x5a] = '\0';
  local_140[0x5b] = '\0';
  local_140[0x5c] = '\0';
  local_140[0x5d] = '\0';
  local_140[0x5e] = '\0';
  local_140[0x5f] = '\0';
  uVar19 = *(undefined8 *)(puVar13[1] + 0x2e8);
  local_140[0x40] = '\0';
  local_140[0x41] = '\0';
  local_140[0x42] = '\0';
  local_140[0x43] = '\0';
  local_140[0x44] = '\0';
  local_140[0x45] = '\0';
  local_140[0x46] = '\0';
  local_140[0x47] = '\0';
  local_140[0x48] = '\0';
  local_140[0x49] = '\0';
  local_140[0x4a] = '\0';
  local_140[0x4b] = '\0';
  local_140[0x4c] = '\0';
  local_140[0x4d] = '\0';
  local_140[0x4e] = '\0';
  local_140[0x4f] = '\0';
  local_140[0x30] = '\0';
  local_140[0x31] = '\0';
  local_140[0x32] = '\0';
  local_140[0x33] = '\0';
  local_140[0x34] = '\0';
  local_140[0x35] = '\0';
  local_140[0x36] = '\0';
  local_140[0x37] = '\0';
  local_140[0x38] = '\0';
  local_140[0x39] = '\0';
  local_140[0x3a] = '\0';
  local_140[0x3b] = '\0';
  local_140[0x3c] = '\0';
  local_140[0x3d] = '\0';
  local_140[0x3e] = '\0';
  local_140[0x3f] = '\0';
  local_140[0x20] = '\0';
  local_140[0x21] = '\0';
  local_140[0x22] = '\0';
  local_140[0x23] = '\0';
  local_140[0x24] = '\0';
  local_140[0x25] = '\0';
  local_140[0x26] = '\0';
  local_140[0x27] = '\0';
  local_140[0x28] = '\0';
  local_140[0x29] = '\0';
  local_140[0x2a] = '\0';
  local_140[0x2b] = '\0';
  local_140[0x2c] = '\0';
  local_140[0x2d] = '\0';
  local_140[0x2e] = '\0';
  local_140[0x2f] = '\0';
  local_140[0x10] = '\0';
  local_140[0x11] = '\0';
  local_140[0x12] = '\0';
  local_140[0x13] = '\0';
  local_140[0x14] = '\0';
  local_140[0x15] = '\0';
  local_140[0x16] = '\0';
  local_140[0x17] = '\0';
  local_140[0x18] = '\0';
  local_140[0x19] = '\0';
  local_140[0x1a] = '\0';
  local_140[0x1b] = '\0';
  local_140[0x1c] = '\0';
  local_140[0x1d] = '\0';
  local_140[0x1e] = '\0';
  local_140[0x1f] = '\0';
  local_140[0] = '\0';
  local_140[1] = '\0';
  local_140[2] = '\0';
  local_140[3] = '\0';
  local_140[4] = '\0';
  local_140[5] = '\0';
  local_140[6] = '\0';
  local_140[7] = '\0';
  local_140[8] = '\0';
  local_140[9] = '\0';
  local_140[10] = '\0';
  local_140[0xb] = '\0';
  local_140[0xc] = '\0';
  local_140[0xd] = '\0';
  local_140[0xe] = '\0';
  local_140[0xf] = '\0';
  local_1a0 = 0;
  local_1a8 = (char *)0x0;
  local_1ac = 0;
  local_148 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_168 = 0;
  uStack_160 = 0;
  local_178[0] = s_mmi_df_serialnum_0010a858[0];
  local_178[1] = s_mmi_df_serialnum_0010a858[1];
  local_178[2] = s_mmi_df_serialnum_0010a858[2];
  local_178[3] = s_mmi_df_serialnum_0010a858[3];
  local_178[4] = s_mmi_df_serialnum_0010a858[4];
  local_178[5] = s_mmi_df_serialnum_0010a858[5];
  local_178[6] = s_mmi_df_serialnum_0010a858[6];
  local_178[7] = s_mmi_df_serialnum_0010a858[7];
  acStack_170[0] = s_mmi_df_serialnum_0010a858[8];
  acStack_170[1] = s_mmi_df_serialnum_0010a858[9];
  acStack_170[2] = s_mmi_df_serialnum_0010a858[10];
  acStack_170[3] = s_mmi_df_serialnum_0010a858[0xb];
  acStack_170[4] = s_mmi_df_serialnum_0010a858[0xc];
  acStack_170[5] = s_mmi_df_serialnum_0010a858[0xd];
  acStack_170[6] = s_mmi_df_serialnum_0010a858[0xe];
  acStack_170[7] = s_mmi_df_serialnum_0010a858[0xf];
  local_190[0x10] = '\0';
  local_190[0x11] = '\0';
  local_190[0x12] = '\0';
  local_190[0x13] = '\0';
  local_190[0] = '\0';
  local_190[1] = '\0';
  local_190[2] = '\0';
  local_190[3] = '\0';
  local_190[4] = '\0';
  local_190[5] = '\0';
  local_190[6] = '\0';
  local_190[7] = '\0';
  local_190[8] = '\0';
  local_190[9] = '\0';
  local_190[10] = '\0';
  local_190[0xb] = '\0';
  local_190[0xc] = '\0';
  local_190[0xd] = '\0';
  local_190[0xe] = '\0';
  local_190[0xf] = '\0';
  pcVar15 = (char *)mmi_get_battery_serialnumber();
  if (pcVar15 == (char *)0x0) {
    local_a8 = (char *)0x0;
    lVar14 = of_find_node_opts_by_path("/chosen",0);
    if ((lVar14 != 0) &&
       (iVar8 = of_property_read_string(lVar14,"mmi,batt_cap",&local_a8), pcVar15 = local_a8,
       iVar8 == 0)) {
      sVar16 = strlen(local_a8);
      if (0x12 < sVar16) {
        sVar16 = 0x13;
      }
      memcpy(local_190,pcVar15,sVar16);
      local_190[sVar16] = '\0';
      snprintf(local_178,0x32,"mmi,df-serialnum-%s",local_190);
    }
    iVar8 = of_property_read_string(uVar19,local_178,&local_1a8);
    if ((iVar8 == 0) && (local_1a8 != (char *)0x0)) {
      _printk(&DAT_0010bd74,*puVar13,"qti_charger_parse_dt");
      ipc_log_string(puVar13[0x55],"I %s: %s: Default Serial Number %s\n",*puVar13,
                     "qti_charger_parse_dt",local_1a8);
      pcVar15 = local_1a8;
    }
    else {
      _printk(&DAT_0010dc96,*puVar13,"qti_charger_parse_dt");
      ipc_log_string(puVar13[0x55],"E %s: %s: No Default Serial Number defined\n",*puVar13,
                     "qti_charger_parse_dt");
      pcVar15 = "unknown-sn";
      local_1a8 = "unknown-sn";
    }
  }
  else {
  }
  sVar16 = strlen(pcVar15);
  if (0x10 < sVar16 + 1) {
    fortify_panic("strcpy");
    goto LAB_00102dfc;
  }
  memcpy(puVar13 + 0x3b,pcVar15,sVar16 + 1);
  local_19c = 0xffffffea;
  local_78 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = (char *)s_profile_ids_map_0010a930._0_8_;
  acStack_a0[0] = s_profile_ids_map_0010a930[8];
  acStack_a0[1] = s_profile_ids_map_0010a930[9];
  acStack_a0[2] = s_profile_ids_map_0010a930[10];
  acStack_a0[3] = s_profile_ids_map_0010a930[0xb];
  acStack_a0[4] = s_profile_ids_map_0010a930[0xc];
  acStack_a0[5] = s_profile_ids_map_0010a930[0xd];
  acStack_a0[6] = s_profile_ids_map_0010a930[0xe];
  acStack_a0[7] = s_profile_ids_map_0010a930[0xf];
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_198 = (char *)0x0;
  lVar14 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar14 != 0) &&
     (iVar8 = of_property_read_string(lVar14,"mmi,batt_cap",&local_198), pcVar15 = local_198,
     iVar8 == 0)) {
    sVar16 = strlen(local_198);
    if (0x12 < sVar16) {
      sVar16 = 0x13;
    }
    memcpy(&local_c0,pcVar15,sVar16);
    local_140[sVar16 + 0x80] = '\0';
    snprintf((char *)&local_a8,0x32,"profile-ids-map-%s",(char *)&local_c0);
  }
  uVar9 = of_property_read_string_helper(*(undefined8 *)(puVar13[1] + 0x2e8),&local_a8,0,0,0);
  if (((int)uVar9 < 1) || ((uVar9 & 1) != 0)) {
    _printk(&DAT_0010d337,*puVar13,"find_profile_id",&local_a8,uVar9);
    ipc_log_string(puVar13[0x55],"E %s: %s: Invalid %s in DT, rc=%d\n",*puVar13,"find_profile_id",
                   &local_a8,uVar9);
LAB_00102228:
    uVar9 = 0x1a1f8;
  }
  else {
    uVar10 = uVar9 >> 1;
    lVar14 = devm_kmalloc(puVar13[1],(ulong)uVar10 << 4,0xcc0);
    if (lVar14 == 0) goto LAB_00102228;
    uVar11 = of_property_read_string_helper
                       (*(undefined8 *)(puVar13[1] + 0x2e8),&local_a8,lVar14,uVar9,0);
    if ((int)uVar11 < 0) {
      _printk(&DAT_0010df89,*puVar13,"find_profile_id",&local_a8,uVar11);
      ipc_log_string(puVar13[0x55],"E %s: %s: Failed to get %s, rc=%d\n",*puVar13,"find_profile_id",
                     &local_a8,uVar11);
      local_19c = uVar11;
    }
    else {
      if (1 < uVar9) {
        uVar17 = 0;
        uVar9 = uVar10;
        if (uVar10 < 2) {
          uVar9 = 1;
        }
        plVar21 = (long *)(lVar14 + 8);
        local_1dc = 0xffffffea;
        do {
          if (*plVar21 == 0) break;
          _printk(&DAT_0010bfdc,*puVar13,"find_profile_id",uVar17 & 0xffffffff,plVar21[-1]);
          ipc_log_string(puVar13[0x55],"I %s: %s: profile_ids_map[%d]: id=%s, sn=%s\n",*puVar13,
                         "find_profile_id",uVar17 & 0xffffffff,plVar21[-1],*plVar21);
          iVar8 = strcmp((char *)*plVar21,(char *)(puVar13 + 0x3b));
          if (iVar8 == 0) {
            local_1dc = (uint)uVar17;
            local_19c = local_1dc;
          }
          uVar17 = uVar17 + 1;
          plVar21 = plVar21 + 2;
        } while (uVar9 != uVar17);
        if ((-1 < (int)local_1dc) && ((int)local_1dc < (int)uVar10)) {
          puVar1 = (undefined8 *)(lVar14 + (ulong)local_1dc * 0x10);
          local_19c = 0;
          uVar9 = kstrtouint(*puVar1,0,&local_19c);
          if (uVar9 == 0) {
            lVar5 = lVar14 + (ulong)local_1dc * 0x10;
            _printk(&DAT_0010b3ee,*puVar13,"find_profile_id",*puVar1,local_19c,
                    *(undefined8 *)(lVar5 + 8));
            ipc_log_string(puVar13[0x55],"I %s: %s: profile id: %s(%d), sn: %s\n",*puVar13,
                           "find_profile_id",*puVar1,local_19c,*(undefined8 *)(lVar5 + 8));
          }
          else {
            lVar5 = lVar14 + (ulong)local_1dc * 0x10;
            _printk(&DAT_0010dfac,*puVar13,"find_profile_id",*puVar1,*(undefined8 *)(lVar5 + 8));
            ipc_log_string(puVar13[0x55],"E %s: %s: Invalid id: %s, sn: %s\n",*puVar13,
                           "find_profile_id",*puVar1,*(undefined8 *)(lVar5 + 8));
            local_19c = uVar9;
          }
          goto LAB_00102a90;
        }
      }
      _printk(&DAT_0010ceb0,*puVar13,"find_profile_id",&local_a8);
      ipc_log_string(puVar13[0x55],"W %s: %s: No matched profile id in %s\n",*puVar13,
                     "find_profile_id",&local_a8);
    }
LAB_00102a90:
    devm_kfree(puVar13[1],lVar14);
    uVar9 = local_19c;
    if ((int)local_19c < 0) goto LAB_00102228;
  }
  piVar3 = (int *)((long)puVar13 + 0x274);
  *(uint *)(puVar13 + 0x52) = uVar9;
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,chrg-iterm-ma",piVar3,1,0);
  if (iVar8 < 0) {
    iVar8 = 300000;
  }
  else {
    iVar8 = *piVar3 * 1000;
  }
  *piVar3 = iVar8;
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,fg-iterm-ma",puVar13 + 0x4e,1,0);
  if (iVar8 < 0) {
    iVar8 = *piVar3 + 50000;
  }
  else {
    iVar8 = *(int *)(puVar13 + 0x4e) * 1000;
  }
  *(int *)(puVar13 + 0x4e) = iVar8;
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,vfloat-comp-uv",puVar13 + 0x50,1,0);
  if (iVar8 < 0) {
    *(undefined4 *)(puVar13 + 0x50) = 0;
  }
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,max-fv-mv",puVar13 + 0x4f,1,0);
  if (iVar8 < 0) {
    iVar8 = 0x1130;
  }
  else {
    iVar8 = *(int *)(puVar13 + 0x4f);
  }
  puVar4 = (uint *)((long)puVar13 + 0x27c);
  *(int *)(puVar13 + 0x4f) = iVar8 * 1000;
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,max-fcc-ma",puVar4,1,0);
  if (iVar8 < 0) {
    uVar9 = 4000;
  }
  else {
    uVar9 = *puVar4;
  }
  *(uint *)((long)puVar13 + 0x27c) = uVar9 * 1000;
  iVar8 = of_property_read_variable_u32_array
                    (uVar19,"mmi,demo-fv-mv",(int *)((long)puVar13 + 0x284),1,0);
  if (iVar8 < 0) {
    iVar8 = 4000;
  }
  else {
    iVar8 = *(int *)((long)puVar13 + 0x284);
  }
  piVar3 = (int *)(puVar13 + 0x51);
  *(int *)((long)puVar13 + 0x284) = iVar8 * 1000;
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,profile-data-block-size",piVar3,1,0);
  if (iVar8 < 0) {
    iVar8 = 4;
  }
  else {
    iVar8 = *piVar3;
  }
  *(undefined4 *)((long)puVar13 + 0x28c) = 0;
  *(int *)(puVar13 + 0x51) = iVar8 << 2;
  lVar14 = of_find_property(uVar19,"mmi,profile-data",&local_1a0);
  if (lVar14 != 0) {
    iVar8 = *piVar3;
    iVar20 = 0;
    if (iVar8 != 0) {
      iVar20 = local_1a0 / iVar8;
    }
    if (local_1a0 == iVar20 * iVar8) {
      lVar14 = devm_kmalloc(puVar13[1],(long)local_1a0,0xdc0);
      puVar13[0x4d] = lVar14;
      if (lVar14 == 0) {
        uVar17 = 0xfffffff4;
        *piVar3 = 0;
        goto LAB_00102900;
      }
      uVar9 = of_property_read_variable_u32_array
                        (uVar19,"mmi,profile-data",lVar14,(ulong)(long)local_1a0 >> 2,0);
      if (-1 < (int)uVar9) {
        *(int *)((long)puVar13 + 0x28c) = local_1a0;
        _printk(&DAT_0010bc36,*puVar13,"qti_charger_parse_dt",*(undefined4 *)(puVar13 + 0x51),iVar20
               );
        ipc_log_string(puVar13[0x55],"I %s: %s: profile data: block size: %d, num: %d\n",*puVar13,
                       "qti_charger_parse_dt",*(undefined4 *)(puVar13 + 0x51),iVar20);
        iVar6 = *(int *)(puVar13 + 0x51);
        iVar8 = iVar6 + 3;
        if (-1 < iVar6) {
          iVar8 = iVar6;
        }
        if (0 < iVar20) {
          param2 = 0;
          local_1dc = 0;
          do {
            local_140[0x70] = '\0';
            local_140[0x71] = '\0';
            local_140[0x72] = '\0';
            local_140[0x73] = '\0';
            local_140[0x74] = '\0';
            local_140[0x75] = '\0';
            local_140[0x76] = '\0';
            local_140[0x77] = '\0';
            local_140[0x78] = '\0';
            local_140[0x79] = '\0';
            local_140[0x7a] = '\0';
            local_140[0x7b] = '\0';
            local_140[0x7c] = '\0';
            local_140[0x7d] = '\0';
            local_140[0x7e] = '\0';
            local_140[0x7f] = '\0';
            local_140[0x60] = '\0';
            local_140[0x61] = '\0';
            local_140[0x62] = '\0';
            local_140[99] = '\0';
            local_140[100] = '\0';
            local_140[0x65] = '\0';
            local_140[0x66] = '\0';
            local_140[0x67] = '\0';
            local_140[0x68] = '\0';
            local_140[0x69] = '\0';
            local_140[0x6a] = '\0';
            local_140[0x6b] = '\0';
            local_140[0x6c] = '\0';
            local_140[0x6d] = '\0';
            local_140[0x6e] = '\0';
            local_140[0x6f] = '\0';
            local_140[0x50] = '\0';
            local_140[0x51] = '\0';
            local_140[0x52] = '\0';
            local_140[0x53] = '\0';
            local_140[0x54] = '\0';
            local_140[0x55] = '\0';
            local_140[0x56] = '\0';
            local_140[0x57] = '\0';
            local_140[0x58] = '\0';
            local_140[0x59] = '\0';
            local_140[0x5a] = '\0';
            local_140[0x5b] = '\0';
            local_140[0x5c] = '\0';
            local_140[0x5d] = '\0';
            local_140[0x5e] = '\0';
            local_140[0x5f] = '\0';
            local_140[0x40] = '\0';
            local_140[0x41] = '\0';
            local_140[0x42] = '\0';
            local_140[0x43] = '\0';
            local_140[0x44] = '\0';
            local_140[0x45] = '\0';
            local_140[0x46] = '\0';
            local_140[0x47] = '\0';
            local_140[0x48] = '\0';
            local_140[0x49] = '\0';
            local_140[0x4a] = '\0';
            local_140[0x4b] = '\0';
            local_140[0x4c] = '\0';
            local_140[0x4d] = '\0';
            local_140[0x4e] = '\0';
            local_140[0x4f] = '\0';
            local_140[0x30] = '\0';
            local_140[0x31] = '\0';
            local_140[0x32] = '\0';
            local_140[0x33] = '\0';
            local_140[0x34] = '\0';
            local_140[0x35] = '\0';
            local_140[0x36] = '\0';
            local_140[0x37] = '\0';
            local_140[0x38] = '\0';
            local_140[0x39] = '\0';
            local_140[0x3a] = '\0';
            local_140[0x3b] = '\0';
            local_140[0x3c] = '\0';
            local_140[0x3d] = '\0';
            local_140[0x3e] = '\0';
            local_140[0x3f] = '\0';
            local_140[0x20] = '\0';
            local_140[0x21] = '\0';
            local_140[0x22] = '\0';
            local_140[0x23] = '\0';
            local_140[0x24] = '\0';
            local_140[0x25] = '\0';
            local_140[0x26] = '\0';
            local_140[0x27] = '\0';
            local_140[0x28] = '\0';
            local_140[0x29] = '\0';
            local_140[0x2a] = '\0';
            local_140[0x2b] = '\0';
            local_140[0x2c] = '\0';
            local_140[0x2d] = '\0';
            local_140[0x2e] = '\0';
            local_140[0x2f] = '\0';
            local_140[0x10] = '\0';
            local_140[0x11] = '\0';
            local_140[0x12] = '\0';
            local_140[0x13] = '\0';
            local_140[0x14] = '\0';
            local_140[0x15] = '\0';
            local_140[0x16] = '\0';
            local_140[0x17] = '\0';
            local_140[0x18] = '\0';
            local_140[0x19] = '\0';
            local_140[0x1a] = '\0';
            local_140[0x1b] = '\0';
            local_140[0x1c] = '\0';
            local_140[0x1d] = '\0';
            local_140[0x1e] = '\0';
            local_140[0x1f] = '\0';
            local_140[0] = '\0';
            local_140[1] = '\0';
            local_140[2] = '\0';
            local_140[3] = '\0';
            local_140[4] = '\0';
            local_140[5] = '\0';
            local_140[6] = '\0';
            local_140[7] = '\0';
            local_140[8] = '\0';
            local_140[9] = '\0';
            local_140[10] = '\0';
            local_140[0xb] = '\0';
            local_140[0xc] = '\0';
            local_140[0xd] = '\0';
            local_140[0xe] = '\0';
            local_140[0xf] = '\0';
            uVar9 = sprintf(local_140,"block%d:",param2);
            if (3 < iVar6) {
              uVar17 = (ulong)(uint)(iVar8 >> 2);
              uVar10 = local_1dc;
              do {
                if (0x80 < uVar9) {
                    /* WARNING: Does not return */
                  pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x102dec);
                  (*pcVar7)();
                }
                iVar12 = sprintf(local_140 + uVar9," %d",
                                 (ulong)*(uint *)(puVar13[0x4d] + (long)(int)uVar10 * 4));
                uVar17 = uVar17 - 1;
                uVar9 = iVar12 + uVar9;
                uVar10 = uVar10 + 1;
              } while (uVar17 != 0);
            }
            _printk(&DAT_0010da76,*puVar13,"qti_charger_parse_dt",local_140);
            ipc_log_string(puVar13[0x55],"I %s: %s: %s\n",*puVar13,"qti_charger_parse_dt",local_140)
            ;
            param2 = param2 + 1;
            local_1dc = local_1dc + (iVar8 >> 2);
          } while (param2 != iVar20);
        }
        goto LAB_001023e8;
      }
      uVar17 = (ulong)uVar9;
      _printk(&DAT_0010bd98,*puVar13,"qti_charger_parse_dt",uVar17);
      ipc_log_string(puVar13[0x55],"E %s: %s: Couldn\'t read profile data, rc = %d\n",*puVar13,
                     "qti_charger_parse_dt",uVar17);
      devm_kfree(puVar13[1],puVar13[0x4d]);
      puVar13[0x4d] = 0;
    }
    else {
      _printk(&DAT_0010ce35,*puVar13,"qti_charger_parse_dt");
      ipc_log_string(puVar13[0x55],"E %s: %s: DT error wrong profile data\n",*puVar13,
                     "qti_charger_parse_dt");
      uVar17 = 0xffffffed;
    }
    *(undefined4 *)(puVar13 + 0x51) = 0;
    goto LAB_00102900;
  }
LAB_001023e8:
  iVar8 = of_property_read_variable_u32_array(uVar19,"mmi,switched-nums",puVar13 + 0x6b,1,0);
  if (iVar8 < 0) {
    *(undefined4 *)(puVar13 + 0x6b) = 1;
  }
  lVar14 = of_find_property(uVar19,"mmi,usb-mosfet-supported",0);
  *(bool *)((long)puVar13 + 0x35c) = lVar14 != 0;
  iVar8 = of_property_count_elems_of_size(uVar19,"mmi,thermal-primary-mitigation",4);
  if (0 < iVar8) {
    iVar20 = 0;
    uVar9 = *puVar4;
    do {
      uVar10 = of_property_read_u32_index(uVar19,"mmi,thermal-primary-mitigation",iVar20,&local_1ac)
      ;
      if ((int)uVar10 < 0) {
        puVar18 = &DAT_0010c616;
        goto LAB_001028f4;
      }
      _printk(&DAT_0010d770,iVar20,local_1ac,uVar9);
      if (uVar9 < local_1ac) {
        _printk(&DAT_0010e8a2);
        *(undefined4 *)(puVar13 + 0x71) = 0xffffffea;
        goto LAB_00102450;
      }
      iVar20 = iVar20 + 1;
      uVar9 = local_1ac;
    } while (iVar8 != iVar20);
    if ((int)(iVar8 + 1U) < 0) {
      uVar17 = 0xfffffff4;
      puVar13[0x6f] = 0;
      goto LAB_00102900;
    }
    lVar14 = devm_kmalloc(puVar13[1],(ulong)(iVar8 + 1U) << 2,0xdc0);
    puVar13[0x6f] = lVar14;
    if (lVar14 == 0) goto LAB_00102718;
    uVar9 = of_property_read_variable_u32_array
                      (uVar19,"mmi,thermal-primary-mitigation",lVar14 + 4,iVar8,0);
    if ((int)uVar9 < 0) {
      puVar18 = &DAT_0010e252;
      goto LAB_00102ad8;
    }
    *(int *)(puVar13 + 0x71) = iVar8;
    *(undefined4 *)(puVar13 + 0x70) = *(undefined4 *)((long)puVar13 + 0x27c);
    *(undefined4 *)puVar13[0x6f] = ((undefined4 *)puVar13[0x6f])[1];
    _printk(&DAT_0010bdc7,*(undefined4 *)(puVar13 + 0x71));
    iVar8 = of_property_count_elems_of_size(uVar19,"mmi,thermal-secondary-mitigation",4);
    if (0 < iVar8) {
      iVar20 = 0;
      uVar9 = *puVar4;
LAB_00102ca4:
      uVar10 = of_property_read_u32_index
                         (uVar19,"mmi,thermal-secondary-mitigation",iVar20,&local_1ac);
      if ((int)uVar10 < 0) {
        puVar18 = &DAT_0010c90c;
LAB_001028f4:
        uVar17 = (ulong)uVar10;
        _printk(puVar18,iVar20,uVar17);
        goto LAB_00102900;
      }
      _printk(&DAT_0010e6c7,iVar20,local_1ac,uVar9);
      if (local_1ac <= uVar9) goto code_r0x00102cdc;
      _printk(&DAT_0010d12e);
      *(undefined4 *)(puVar13 + 0x75) = 0xffffffea;
    }
  }
LAB_00102450:
  local_1d0 = CONCAT44(local_1d0._4_4_,0x800e);
  local_1d8 = &DAT_0010e42b;
  local_1b8 = oem_state_cb;
  local_1c0 = oem_callback;
  local_1c8 = puVar13;
  uVar17 = pmic_glink_register_client(lVar2,&local_1d8);
  puVar13[2] = uVar17;
  if (uVar17 < 0xfffffffffffff001) {
    uVar19 = puVar13[1];
    this_chip = puVar13;
    device_set_wakeup_capable(uVar19,1);
    device_wakeup_enable(uVar19);
    qti_charger_init(puVar13);
    uVar17 = 0;
    goto LAB_001024d4;
  }
  if ((int)uVar17 == -0x205) {
    uVar17 = 0xfffffdfb;
    goto LAB_001024d4;
  }
  _printk(&DAT_0010da40,*puVar13,"qti_charger_probe",uVar17 & 0xffffffff);
  uVar19 = puVar13[0x55];
  pcVar15 = "E %s: %s: Error in registering with pmic_glink rc=%d\n";
  goto LAB_0010292c;
code_r0x00102cdc:
  iVar20 = iVar20 + 1;
  uVar9 = local_1ac;
  if (iVar8 == iVar20) goto code_r0x00102cec;
  goto LAB_00102ca4;
code_r0x00102cec:
  if ((int)(iVar8 + 1U) < 0) {
LAB_00102dfc:
    uVar17 = 0xfffffff4;
    puVar13[0x73] = 0;
  }
  else {
    lVar14 = devm_kmalloc(puVar13[1],(ulong)(iVar8 + 1U) << 2,0xdc0);
    puVar13[0x73] = lVar14;
    if (lVar14 == 0) {
LAB_00102718:
      uVar17 = 0xfffffff4;
    }
    else {
      uVar9 = of_property_read_variable_u32_array
                        (uVar19,"mmi,thermal-secondary-mitigation",lVar14 + 4,iVar8,0);
      if (-1 < (int)uVar9) {
        *(int *)(puVar13 + 0x75) = iVar8;
        *(undefined4 *)(puVar13 + 0x74) = *(undefined4 *)((long)puVar13 + 0x27c);
        *(undefined4 *)puVar13[0x73] = ((undefined4 *)puVar13[0x73])[1];
        _printk(&DAT_0010ce60,*(undefined4 *)(puVar13 + 0x75));
        goto LAB_00102450;
      }
      puVar18 = &DAT_0010da84;
LAB_00102ad8:
      uVar17 = (ulong)uVar9;
      _printk(puVar18,uVar17);
    }
  }
LAB_00102900:
  _printk(&DAT_0010c276,*puVar13,"qti_charger_probe",uVar17);
  uVar19 = puVar13[0x55];
  pcVar15 = "E %s: %s: dt paser failed, rc=%d\n";
LAB_0010292c:
  ipc_log_string(uVar19,pcVar15,*puVar13,"qti_charger_probe",uVar17 & 0xffffffff);
LAB_001024d4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar17 & 0xffffffff;
}



//------------------------------------------------------------
// qti_charger_remove @ 00102e0c size=988
// signature: undefined qti_charger_remove(void)
// callers: []
//------------------------------------------------------------

int qti_charger_remove(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0xa8);
  if (puVar3[0x48] == 0) {
    _printk(&DAT_0010cd93,*puVar3,"qti_charger_deinit");
    ipc_log_string(puVar3[0x55],"I %s: %s: qti charger has not inited yet\n",*puVar3,
                   "qti_charger_deinit");
  }
  else {
    device_remove_file(puVar3[1],&dev_attr_fg_operation);
    device_remove_file(puVar3[1],&dev_attr_typec_reset);
    device_remove_file(puVar3[1],&dev_attr_cid_status);
    device_remove_file(puVar3[1],&dev_attr_tcmd);
    device_remove_file(puVar3[1],&dev_attr_force_pmic_icl);
    device_remove_file(puVar3[1],&dev_attr_force_wls_en);
    device_remove_file(puVar3[1],&dev_attr_force_usb_suspend);
    device_remove_file(puVar3[1],&dev_attr_force_wls_volt_max);
    device_remove_file(puVar3[1],&dev_attr_force_wls_curr_max);
    device_remove_file(puVar3[1],&dev_attr_wireless_chip_id);
    device_remove_file(puVar3[1],&dev_attr_wls_fod_curr);
    device_remove_file(puVar3[1],&dev_attr_wls_fod_gain);
    device_remove_file(puVar3[1],&dev_attr_batt_id);
    device_remove_file(puVar3[1],&dev_attr_cur_batt_id);
    device_remove_file(puVar3[1],&dev_attr_addr);
    device_remove_file(puVar3[1],&dev_attr_data);
    if (puVar3[0x49] != 0) {
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_tx_mode);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_tx_mode_vout);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_rx_connected);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wls_input_current_limit);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_folio_mode);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_light_ctl);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_fan_speed);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_tx_type);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_tx_power);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_tx_capability);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_tx_id);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_tx_sn);
      device_remove_file(*(undefined8 *)(puVar3[0x49] + 0x98),&dev_attr_wlc_st_changed);
      blocking_notifier_chain_unregister(&qti_chg_notifier_list,puVar3 + 0x80);
      power_supply_put(puVar3[0x49]);
      puVar3[0x49] = 0;
    }
    if (puVar3 == (undefined8 *)0x0) {
      _printk(&DAT_0010bfc5);
    }
    else {
      lVar2 = power_supply_get_by_name("battery");
      if (lVar2 == 0) {
        _printk(&DAT_0010b6ad);
      }
      else {
        device_remove_file(*(undefined8 *)(lVar2 + 0x98),
                           &dev_attr_thermal_primary_charge_control_limit);
        device_remove_file(*(undefined8 *)(lVar2 + 0x98),
                           &dev_attr_thermal_primary_charge_control_limit_max);
        device_remove_file(*(undefined8 *)(lVar2 + 0x98),
                           &dev_attr_thermal_secondary_charge_control_limit);
        device_remove_file(*(undefined8 *)(lVar2 + 0x98),
                           &dev_attr_thermal_secondary_charge_control_limit_max);
        thermal_cooling_device_unregister(puVar3[0x72]);
        thermal_cooling_device_unregister(puVar3[0x76]);
      }
    }
    trusted_shash_release();
    if (puVar3[0x83] != 0) {
      debugfs_remove();
    }
    iVar1 = mmi_unregister_charger_driver(puVar3[0x48]);
    if (iVar1 == 0) {
      devm_kfree(puVar3[1],puVar3[0x48]);
      puVar3[0x48] = 0;
    }
    else {
      _printk(&DAT_0010ba78,*puVar3,"qti_charger_deinit",iVar1);
      ipc_log_string(puVar3[0x55],"E %s: %s: qti charger deinit failed, rc=%d\n",*puVar3,
                     "qti_charger_deinit",iVar1);
    }
  }
  iVar1 = pmic_glink_unregister_client(puVar3[2]);
  if (iVar1 < 0) {
    _printk(&DAT_0010aea3,*puVar3,"qti_charger_remove",iVar1);
    ipc_log_string(puVar3[0x55],"E %s: %s: pmic_glink_unregister_client failed rc=%d\n",*puVar3,
                   "qti_charger_remove",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// qti_charger_shutdown @ 001031ec size=88
// signature: undefined qti_charger_shutdown(void)
// callers: []
//------------------------------------------------------------

void qti_charger_shutdown(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xa8);
  _printk(&DAT_0010bd42,*puVar1,"qti_charger_shutdown");
  ipc_log_string(puVar1[0x55],"I %s: %s: qti_charger_shutdown\n",*puVar1,"qti_charger_shutdown");
  return;
}



//------------------------------------------------------------
// qti_charger_setup_work @ 00103248 size=208
// signature: undefined qti_charger_setup_work(void)
// callers: []
//------------------------------------------------------------

void qti_charger_setup_work(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)(param_1 + -0x110);
  if (*(int *)(param_1 + 0x94) == 0) {
    _printk(&DAT_0010de13,*puVar1,"qti_charger_setup_work");
    ipc_log_string(*(undefined8 *)(param_1 + 0x198),"E %s: %s: ADSP glink state is down\n",*puVar1,
                   "qti_charger_setup_work");
    *(undefined8 *)(param_1 + 0xfc) = 0;
    *(undefined8 *)(param_1 + 0x104) = 0;
    *(undefined8 *)(param_1 + 0x10c) = 0;
    *(undefined4 *)(param_1 + 0x114) = 0;
    *(undefined8 *)(param_1 + 0x118) = 0;
    *(undefined8 *)(param_1 + 0x120) = 0;
    *(undefined8 *)(param_1 + 0x128) = 0;
  }
  else if (*(int *)(param_1 + 0x94) == 1) {
    _printk(&DAT_0010cc2b,*puVar1,"qti_charger_setup_work");
    ipc_log_string(*(undefined8 *)(param_1 + 0x198),"I %s: %s: ADSP glink state is up\n",*puVar1,
                   "qti_charger_setup_work");
    qti_charger_init(puVar1);
  }
  return;
}



//------------------------------------------------------------
// qti_charger_notify_work @ 0010331c size=148
// signature: undefined qti_charger_notify_work(void)
// callers: []
//------------------------------------------------------------

void qti_charger_notify_work(long param_1)

{
  long lVar1;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_50 = *(undefined4 *)(param_1 + 0x40);
  local_4c = *(undefined8 *)(param_1 + 0x44);
  local_44 = *(undefined8 *)(param_1 + 0x4c);
  local_3c = *(undefined8 *)(param_1 + 0x54);
  local_34 = *(undefined8 *)(param_1 + 0x5c);
  blocking_notifier_call_chain(&qti_chg_notifier_list,*(undefined4 *)(param_1 + 0x3c),&local_50);
  pm_relax(*(undefined8 *)(param_1 + -0x138));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// oem_callback @ 001033b4 size=904
// signature: undefined oem_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 oem_callback(undefined8 *param_1,undefined8 *param_2,long param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  char *pcVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  
  if (*(char *)param_1[0x67] != '\0') {
    _printk(&DAT_0010c2bf,*param_1,"oem_callback",*(undefined4 *)param_2,
            *(undefined4 *)((long)param_2 + 4),*(undefined4 *)(param_2 + 1),param_3);
  }
  ipc_log_string(param_1[0x55],"D %s: %s: owner: %u type: %u opcode: 0x%x len:%zu\n",*param_1,
                 "oem_callback",*(undefined4 *)param_2,*(undefined4 *)((long)param_2 + 4),
                 *(undefined4 *)(param_2 + 1),param_3);
  iVar1 = *(int *)(param_2 + 1);
  if (iVar1 == 0x10000) {
    if (param_3 != 0x54) {
      _printk(&DAT_0010d4ed,*param_1,"handle_oem_read_ack",param_3,0x54);
      ipc_log_string(param_1[0x55],"E %s: %s: Incorrect received length %zu expected %lu\n",*param_1
                     ,"handle_oem_read_ack",param_3,0x54);
      *(undefined4 *)((long)param_1 + 0x10c) = 0;
      return 0;
    }
    uVar3 = param_2[2];
    uVar5 = *param_2;
    param_1[0x18] = param_2[1];
    param_1[0x19] = uVar3;
    param_1[0x17] = uVar5;
    uVar5 = param_2[6];
    uVar3 = param_2[3];
    uVar6 = param_2[4];
    param_1[0x1c] = param_2[5];
    param_1[0x1d] = uVar5;
    param_1[0x1a] = uVar3;
    param_1[0x1b] = uVar6;
    uVar3 = param_2[8];
    uVar5 = param_2[9];
    uVar6 = param_2[7];
    *(undefined4 *)(param_1 + 0x21) = *(undefined4 *)(param_2 + 10);
    param_1[0x1f] = uVar3;
    param_1[0x20] = uVar5;
    param_1[0x1e] = uVar6;
    *(undefined4 *)((long)param_1 + 0x10c) = 1;
    complete(param_1 + 3);
    if (*(char *)param_1[0x67] != '\0') {
      _printk(&DAT_0010b414,*param_1,"handle_oem_read_ack",*(undefined4 *)((long)param_1 + 0xc4));
    }
    uVar3 = param_1[0x55];
    pcVar4 = "D %s: %s: read ack for property: %u\n";
    uVar5 = *param_1;
    uVar2 = *(undefined4 *)((long)param_1 + 0xc4);
    pcVar8 = "handle_oem_read_ack";
  }
  else if (iVar1 == 0x10001) {
    if (param_3 != 0x10) {
      _printk(&DAT_0010d4ed,*param_1,"handle_oem_write_ack",param_3,0x10);
      ipc_log_string(param_1[0x55],"E %s: %s: Incorrect received length %zu expected %lu\n",*param_1
                     ,"handle_oem_write_ack",param_3,0x10);
      return 0;
    }
    if (*(int *)((long)param_2 + 0xc) == 0) {
      if (*(char *)param_1[0x67] != '\0') {
        _printk(&DAT_0010c318,*param_1,"handle_oem_write_ack");
      }
      ipc_log_string(param_1[0x55],"D %s: %s: write ack\n",*param_1,"handle_oem_write_ack");
      complete(param_1 + 7);
      return 0;
    }
    pcVar8 = "handle_oem_write_ack";
    _printk(&DAT_0010b439,*param_1,"handle_oem_write_ack");
    uVar3 = param_1[0x55];
    pcVar4 = "E %s: %s: write ack, ret_code: %u\n";
    uVar5 = *param_1;
    uVar2 = *(undefined4 *)((long)param_2 + 0xc);
  }
  else {
    if (iVar1 == 0x10002) {
      if (param_3 == 0x34) {
        _printk(&DAT_0010eb78,*param_1,"handle_oem_notification",
                *(undefined4 *)((long)param_2 + 0xc),*(undefined4 *)(param_2 + 2));
        ipc_log_string(param_1[0x55],"I %s: %s: notification: %#x on receiver: %#x\n",*param_1,
                       "handle_oem_notification",*(undefined4 *)((long)param_2 + 0xc),
                       *(undefined4 *)(param_2 + 2));
        pm_stay_awake(param_1[1]);
        uVar3 = param_2[2];
        uVar5 = *param_2;
        param_1[0x2f] = param_2[1];
        param_1[0x30] = uVar3;
        param_1[0x2e] = uVar5;
        uVar6 = _system_wq;
        uVar3 = param_2[4];
        uVar5 = param_2[5];
        uVar7 = param_2[3];
        *(undefined4 *)(param_1 + 0x34) = *(undefined4 *)(param_2 + 6);
        param_1[0x32] = uVar3;
        param_1[0x33] = uVar5;
        param_1[0x31] = uVar7;
        queue_work_on(0x20,uVar6,param_1 + 0x28);
        return 0;
      }
      _printk(&DAT_0010d4ed,*param_1,"handle_oem_notification",param_3,0x34);
      ipc_log_string(param_1[0x55],"E %s: %s: Incorrect received length %zu expected %lu\n",*param_1
                     ,"handle_oem_notification",param_3,0x34);
      return 0;
    }
    pcVar8 = "oem_callback";
    _printk(&DAT_0010b5b5,*param_1,"oem_callback");
    uVar3 = param_1[0x55];
    pcVar4 = "E %s: %s: Unknown message opcode: %d\n";
    uVar5 = *param_1;
    uVar2 = *(undefined4 *)(param_2 + 1);
  }
  ipc_log_string(uVar3,pcVar4,uVar5,pcVar8,uVar2);
  return 0;
}



//------------------------------------------------------------
// oem_state_cb @ 00103740 size=148
// signature: undefined oem_state_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void oem_state_cb(undefined8 *param_1,uint param_2)

{
  if (*(char *)param_1[0x67] != '\0') {
    _printk(&DAT_0010c03c,*param_1,"oem_state_cb",param_2);
  }
  ipc_log_string(param_1[0x55],"D %s: %s: state: %d\n",*param_1,"oem_state_cb",param_2);
  *(uint *)((long)param_1 + 0x1a4) = param_2;
  if (param_2 < 2) {
    queue_work_on(0x20,_system_wq,param_1 + 0x22);
  }
  return;
}



//------------------------------------------------------------
// qti_charger_init @ 001037d4 size=6464
// signature: undefined qti_charger_init(void)
// callers: [qti_charger_probe, qti_charger_setup_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qti_charger_init(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ushort uVar4;
  char cVar5;
  undefined1 uVar6;
  bool bVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  ulong uVar11;
  undefined *puVar12;
  undefined8 uVar13;
  size_t sVar14;
  undefined8 *puVar15;
  char *pcVar16;
  undefined8 uVar17;
  uint uVar18;
  char *pcVar19;
  long lVar20;
  long *plVar21;
  ushort local_84 [2];
  char local_80 [4];
  uint local_7c;
  char *local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 *local_60;
  undefined8 local_58;
  ulong local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar20 = sp_el0;
  local_38 = *(long *)(lVar20 + 0x638);
  local_7c = 0;
  local_80[0] = '\0';
  local_84[0] = 0;
  if (param_1[0x48] != 0) {
    _printk(&DAT_0010d7d9,*param_1,"qti_charger_init");
    uVar13 = param_1[0x55];
    pcVar19 = "W %s: %s: qti charger has already inited\n";
LAB_001038e0:
    ipc_log_string(uVar13,pcVar19,*param_1,"qti_charger_init");
    goto LAB_00103964;
  }
  local_7c = mmi_is_factory_mode();
  local_7c = local_7c & 1;
  uVar11 = qti_charger_write(param_1,0xf,&local_7c,4);
  if ((int)uVar11 == 0) {
    *(bool *)((long)param_1 + 0x22c) = local_7c != 0;
    local_7c = mmi_is_factory_version();
    local_7c = local_7c & 1;
    uVar8 = qti_charger_write(param_1,0x10,&local_7c,4);
    if (uVar8 != 0) {
      uVar11 = (ulong)uVar8;
      _printk(&DAT_0010af61,*param_1,"qti_charger_init",uVar11);
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: qti charger set factory ver failed, rc=%d\n";
      goto LAB_00103954;
    }
    local_78 = (char *)0x0;
    local_70 = (char *)0x0;
    local_50 = local_50 & 0xffffffffffffff00;
    local_60 = (undefined8 *)0x0;
    local_58 = 0;
    local_68 = 0;
    *(bool *)((long)param_1 + 0x22d) = local_7c != 0;
    iVar9 = mmi_get_bootarg("androidboot.radio=",&local_78);
    pcVar19 = local_78;
    if (iVar9 != 0) {
      pcVar19 = "E %s: %s: Could not get radio bootarg\n";
      puVar12 = &DAT_0010b482;
LAB_001039a0:
      _printk(puVar12,*param_1,"mmi_get_sku_type");
      ipc_log_string(param_1[0x55],pcVar19,*param_1,"mmi_get_sku_type");
      _printk(&DAT_0010dfe3,*param_1,"qti_charger_init");
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: Fail to get sku type\n";
      goto LAB_001038e0;
    }
    if (local_78 == (char *)0x0) {
      pcVar19 = "E %s: %s: Could not get SKU type\n";
      puVar12 = &DAT_0010e4c5;
      goto LAB_001039a0;
    }
    sVar14 = strlen(local_78);
    if (0x1f < sVar14) {
      sVar14 = 0x20;
    }
    memcpy(&local_70,pcVar19,sVar14);
    *(undefined1 *)((long)&local_70 + sVar14) = 0;
    if ((short)local_70 == 0x5250 && local_70._2_1_ == 'C') {
      local_80[0] = '\x01';
    }
    else if ((short)local_70 == 0x4f52 && local_70._2_1_ == 'W') {
      local_80[0] = '\x02';
    }
    else if ((short)local_70 == 0x414e) {
      local_80[0] = '\x03';
    }
    else if ((short)local_70 == 0x5a56 && local_70._2_1_ == 'W') {
      local_80[0] = '\x04';
    }
    else if ((short)local_70 == 0x504a) {
      local_80[0] = '\x05';
    }
    else if ((short)local_70 == 0x5449 && local_70._2_1_ == 'A') {
      local_80[0] = '\x06';
    }
    else if ((short)local_70 == 0x414e && local_70._2_1_ == 'E') {
      local_80[0] = '\a';
    }
    else {
      local_80[0] = (local_70 == (char *)0x5445535245505553) << 3;
    }
    _printk(&DAT_0010b5db,*param_1,"mmi_get_sku_type",&local_70);
    ipc_log_string(param_1[0x55],"I %s: %s: SKU type: %s, 0x%02x\n",*param_1,"mmi_get_sku_type",
                   &local_70,local_80[0]);
    iVar9 = qti_charger_write(param_1,0x29,local_80,1);
    if (iVar9 != 0) {
      _printk(&DAT_0010ef50,*param_1,"qti_charger_init",iVar9);
      ipc_log_string(param_1[0x55],"E %s: %s: qti charger set SKU type failed, rc=%d\n",*param_1,
                     "qti_charger_init",iVar9);
    }
    local_78 = (char *)0x0;
    local_70 = (char *)0x0;
    local_50 = local_50 & 0xffffffffffffff00;
    local_60 = (undefined8 *)0x0;
    local_58 = 0;
    local_68 = 0;
    iVar9 = mmi_get_bootarg("androidboot.hwrev=",&local_78);
    pcVar19 = local_78;
    if (iVar9 != 0) {
      _printk(&DAT_0010e4e7,*param_1,"mmi_get_hw_revision");
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: Could not get hwrev bootarg\n";
LAB_00103c40:
      ipc_log_string(uVar13,pcVar19,*param_1,"mmi_get_hw_revision");
LAB_00103c4c:
      _printk(&DAT_0010de42,*param_1,"qti_charger_init");
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: Fail to get HW revision\n";
      goto LAB_001038e0;
    }
    if (local_78 == (char *)0x0) {
      _printk(&DAT_0010b4a9,*param_1,"mmi_get_hw_revision");
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: Could not get HW  revision\n";
      goto LAB_00103c40;
    }
    sVar14 = strlen(local_78);
    if (0x1f < sVar14) {
      sVar14 = 0x20;
    }
    memcpy(&local_70,pcVar19,sVar14);
    *(undefined1 *)((long)&local_70 + sVar14) = 0;
    iVar9 = kstrtou16(&local_70,0x10,local_84);
    if (iVar9 < 0) {
      _printk(&DAT_0010e795,*param_1,"mmi_get_hw_revision",iVar9);
      ipc_log_string(param_1[0x55],"I %s: %s: kstrtou16 error: %d \n",*param_1,"mmi_get_hw_revision"
                     ,iVar9);
      goto LAB_00103c4c;
    }
    _printk(&DAT_0010d3ee,*param_1,"mmi_get_hw_revision",local_84[0]);
    ipc_log_string(param_1[0x55],"I %s: %s: HW revision: 0x%x\n",*param_1,"mmi_get_hw_revision",
                   local_84[0]);
    iVar9 = qti_charger_write(param_1,0x2a,local_84,2);
    if (iVar9 == 0) {
      if (param_1 != (undefined8 *)0x0) goto LAB_00103fb8;
LAB_00103d54:
      local_70 = (char *)0x0;
      if (DAT_00000371 != '\0') {
        uVar8 = 0xffffffff;
        pcVar19 = &DAT_00000371;
        uVar18 = 0xffffffff;
LAB_00103d6c:
        uVar8 = uVar18 | uVar8;
        goto LAB_00103d70;
      }
    }
    else {
      _printk(&DAT_0010e45b,*param_1,"qti_charger_init",iVar9);
      ipc_log_string(param_1[0x55],"E %s: %s: qti charger set HW revision failed, rc=%d\n",*param_1,
                     "qti_charger_init",iVar9);
      if (param_1 == (undefined8 *)0x0) goto LAB_00103d54;
LAB_00103fb8:
      local_70 = (char *)0x0;
      iVar9 = mmi_get_bootarg("secure_hardware=",&local_70);
      pcVar19 = local_70;
      if (iVar9 == 0) {
        if (local_70 == (char *)0x0) {
          _printk(&DAT_0010dda8,*param_1,"mmi_check_secure_hardware");
          ipc_log_string(param_1[0x55],"E %s: %s: Could not get secure_hardware\n",*param_1,
                         "mmi_check_secure_hardware");
        }
        else {
          _printk(&DAT_0010c380,*param_1,"mmi_check_secure_hardware",local_70);
          ipc_log_string(param_1[0x55],"I %s: %s: secure_hardware=%s \n",*param_1,
                         "mmi_check_secure_hardware",pcVar19);
          *(bool *)((long)param_1 + 0x371) = *pcVar19 == '1';
          _printk(&DAT_0010d5d0,*param_1,"mmi_check_secure_hardware");
          ipc_log_string(param_1[0x55],"I %s: %s: secure_hardware: %d\n",*param_1,
                         "mmi_check_secure_hardware",*(undefined1 *)((long)param_1 + 0x371));
        }
        uVar8 = 0;
      }
      else {
        _printk(&DAT_0010b8ba,*param_1,"mmi_check_secure_hardware");
        ipc_log_string(param_1[0x55],"E %s: %s: Could not get bootarg\n",*param_1,
                       "mmi_check_secure_hardware");
        uVar8 = 0xffffffff;
      }
      pcVar19 = (char *)((long)param_1 + 0x371);
      if (*(char *)((long)param_1 + 0x371) != '\0') {
        local_78 = (char *)0x0;
        local_70 = (char *)0x0;
        local_50 = local_50 & 0xffffffffffffff00;
        local_60 = (undefined8 *)0x0;
        local_58 = 0;
        local_68 = 0;
        iVar9 = mmi_get_bootarg("androidboot.cid=",&local_78);
        pcVar16 = local_78;
        if (iVar9 != 0) {
          _printk(&DAT_0010b8ba,*param_1,"mmi_check_hw_cid0");
          uVar13 = param_1[0x55];
          pcVar16 = "E %s: %s: Could not get bootarg\n";
LAB_00104a64:
          ipc_log_string(uVar13,pcVar16,*param_1,"mmi_check_hw_cid0");
          uVar18 = 0xffffffff;
          goto LAB_00103d6c;
        }
        if (local_78 == (char *)0x0) {
          _printk(&DAT_0010c946,*param_1,"mmi_check_hw_cid0");
          uVar13 = param_1[0x55];
          pcVar16 = "E %s: %s: Could not get HW cid\n";
          goto LAB_00104a64;
        }
        sVar14 = strlen(local_78);
        if (0x1f < sVar14) {
          sVar14 = 0x20;
        }
        memcpy(&local_70,pcVar16,sVar14);
        *(undefined1 *)((long)&local_70 + sVar14) = 0;
        cVar5 = (char)local_70;
        sVar14 = strnlen((char *)&local_70,0x21);
        if (0x21 < sVar14) {
          fortify_panic("strnlen");
LAB_00105108:
          fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if (sVar14 == 0x21) goto LAB_00105108;
        iVar9 = (uint)local_70;
        switch((int)sVar14) {
        case 1:
          uVar6 = cVar5 == '0';
          break;
        default:
          uVar6 = *(undefined1 *)((long)param_1 + 0x372);
          goto LAB_00104d60;
        case 3:
          uVar6 = (uint)local_70 == 0x307830;
          break;
        case 4:
          uVar6 = (uint)local_70 == 0x30307830 && local_70._4_1_ == '\0';
          break;
        case 6:
          uVar6 = false;
          if (iVar9 == 0x30307830) {
            uVar6 = local_70._3_4_ == 0x303030;
          }
        }
        *(undefined1 *)((long)param_1 + 0x372) = uVar6;
LAB_00104d60:
        _printk(&DAT_0010b4cf,*param_1,"mmi_check_hw_cid0",uVar6,sVar14 & 0xffffffff,&local_70);
        ipc_log_string(param_1[0x55],"I %s: %s: HW cid0: %d len=%d cid_str=%s\n",*param_1,
                       "mmi_check_hw_cid0",*(undefined1 *)((long)param_1 + 0x372),
                       sVar14 & 0xffffffff,&local_70);
        uVar18 = 0;
        goto LAB_00103d6c;
      }
LAB_00103d70:
      if (uVar8 == 0) {
        if (*pcVar19 == '\0') {
          bVar7 = true;
        }
        else {
          bVar7 = *(char *)((long)param_1 + 0x372) != '\0';
        }
        *(bool *)(param_1 + 0x6e) = bVar7;
      }
    }
    uVar8 = qti_charger_write(param_1,2,param_1 + 0x4e,0x24);
    if (uVar8 != 0) {
      uVar11 = (ulong)uVar8;
      _printk(&DAT_0010e53e,*param_1,"qti_charger_write_profile",uVar11);
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: qti charger write profile info failed, rc=%d\n";
LAB_0010403c:
      ipc_log_string(uVar13,pcVar19,*param_1,"qti_charger_write_profile",uVar11);
      _printk(&DAT_0010dd10,*param_1,"qti_charger_init",uVar11);
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: qti charger set profile data failed, rc=%d\n";
      goto LAB_00103954;
    }
    lVar20 = param_1[0x4d];
    if (lVar20 != 0) {
      iVar9 = 0;
      do {
        while( true ) {
          iVar3 = *(int *)((long)param_1 + 0x28c) - iVar9;
          if (iVar3 == 0 || *(int *)((long)param_1 + 0x28c) < iVar9) goto LAB_00103e3c;
          lVar1 = lVar20 + iVar9;
          if (iVar3 < 0x41) break;
          uVar11 = qti_charger_write(param_1,3,lVar1,0x40);
          iVar9 = iVar9 + 0x40;
          if ((int)uVar11 != 0) goto LAB_00103e0c;
        }
        uVar11 = qti_charger_write(param_1,3,lVar1,(long)iVar3);
        iVar9 = *(int *)((long)param_1 + 0x28c);
      } while ((int)uVar11 == 0);
LAB_00103e0c:
      uVar11 = uVar11 & 0xffffffff;
      _printk(&DAT_0010cce3,*param_1,"qti_charger_write_profile",uVar11);
      uVar13 = param_1[0x55];
      pcVar19 = "E %s: %s: qti charger write profile data failed, rc=%d\n";
      goto LAB_0010403c;
    }
LAB_00103e3c:
    plVar21 = param_1 + 1;
    lVar20 = of_find_property(*(undefined8 *)(*plVar21 + 0x2e8),"mmi,main-battery-enabled",0);
    if (lVar20 == 0) {
LAB_00103e90:
      if ((*(char *)((long)param_1 + 0x35c) != '\0') && (*(char *)((long)param_1 + 0x22d) == '\0'))
      {
        local_78 = (char *)0x0;
        local_70 = (char *)0x0;
        local_50 = local_50 & 0xffffffffffffff00;
        local_60 = (undefined8 *)0x0;
        local_58 = 0;
        local_68 = 0;
        iVar9 = mmi_get_bootarg("androidboot.carrier=",&local_78);
        if (iVar9 == 0) {
          _printk(&DAT_0010be62,*param_1,"mmi_is_softbank_sku");
          ipc_log_string(param_1[0x55],"I %s: %s: Get bootarg androidboot.hardware.sku success",
                         *param_1,"mmi_is_softbank_sku");
          pcVar19 = local_78;
          if (local_78 != (char *)0x0) {
            sVar14 = strlen(local_78);
            if (0x1f < sVar14) {
              sVar14 = 0x20;
            }
            memcpy(&local_70,pcVar19,sVar14);
            *(undefined1 *)((long)&local_70 + sVar14) = 0;
            _printk(&DAT_0010efb0,*param_1,"mmi_is_softbank_sku",&local_70);
            ipc_log_string(param_1[0x55],"I %s: %s: carrier: %s",*param_1,"mmi_is_softbank_sku",
                           &local_70);
            uVar4 = local_84[0];
            if (local_70 == (char *)0x6b6e616274666f73) {
              local_70 = (char *)0x6b6e616200000000;
              if (*plVar21 == 0) {
                uVar13 = 0;
              }
              else {
                uVar13 = *(undefined8 *)(*plVar21 + 0x2e8);
              }
              uVar11 = thermal_of_cooling_device_register
                                 (uVar13,"usb_therm_cooler",param_1,&usb_therm_ops);
              param_1[0x4b] = uVar11;
              if (uVar11 < 0xfffffffffffff001) {
                _printk(&DAT_0010c121,*param_1,"qti_charger_init_usb_therm_cooler");
                ipc_log_string(param_1[0x55],"I %s: %s: Cooling register success for usb_therm.",
                               *param_1,"qti_charger_init_usb_therm_cooler");
                iVar9 = of_property_read_variable_u32_array
                                  (*(undefined8 *)(param_1[1] + 0x2e8),"mmi,support-gpio-hwrev",
                                   &local_70,1,0);
                if (iVar9 < 0) {
                  local_70 = (char *)((ulong)local_70 & 0xffffffff00000000);
                  *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
LAB_00105014:
                  uVar10 = of_get_named_gpio_flags
                                     (*(undefined8 *)(param_1[1] + 0x2e8),"mmi,mos-en-gpio",0,0);
                  *(undefined4 *)(param_1 + 0x6c) = uVar10;
                }
                else {
                  uVar10 = 0xffffffff;
                  *(undefined4 *)(param_1 + 0x6c) = 0xffffffff;
                  if ((uint)local_70 <= uVar4) goto LAB_00105014;
                }
                _printk(&DAT_0010b1cf,*param_1,"qti_charger_init_usb_therm_cooler",(uint)local_70,
                        uVar4,uVar10);
                ipc_log_string(param_1[0x55],
                               "I %s: %s: support_gpio_hwrev=0x%x hwrev=0x%x mos_en_gpio=%d",
                               *param_1,"qti_charger_init_usb_therm_cooler",
                               (ulong)local_70 & 0xffffffff,uVar4,*(undefined4 *)(param_1 + 0x6c));
                if (*(uint *)(param_1 + 0x6c) < 0x200) {
                  iVar9 = gpio_request(*(uint *)(param_1 + 0x6c),"mmi mos en pin");
                  if (iVar9 != 0) {
                    _printk(&DAT_0010de91,*param_1,"qti_charger_init_usb_therm_cooler",
                            "qti_charger_init_usb_therm_cooler",*(undefined4 *)(param_1 + 0x6c));
                    ipc_log_string(param_1[0x55],"E %s: %s: %s: %d gpio(mos en) request failed.",
                                   *param_1,"qti_charger_init_usb_therm_cooler",
                                   "qti_charger_init_usb_therm_cooler",
                                   *(undefined4 *)(param_1 + 0x6c));
                    goto joined_r0x001050f4;
                  }
                  uVar13 = gpio_to_desc(*(undefined4 *)(param_1 + 0x6c));
                  gpiod_direction_output_raw(uVar13,0);
                }
                *(undefined1 *)((long)param_1 + 0x364) = 0;
              }
              else {
                _printk(&DAT_0010e5ae,*param_1,"qti_charger_init_usb_therm_cooler",uVar11);
                ipc_log_string(param_1[0x55],
                               "E %s: %s: Cooling register failed for usb_therm, ret:%ld\n",*param_1
                               ,"qti_charger_init_usb_therm_cooler",param_1[0x4b]);
                iVar9 = *(int *)(param_1 + 0x4b);
joined_r0x001050f4:
                if (iVar9 < 0) {
                  _printk(&DAT_0010c051,*param_1,"qti_charger_init",iVar9);
                  ipc_log_string(param_1[0x55],
                                 "E %s: %s: Couldn\'t initialize usb therm cooler rc=%d.",*param_1,
                                 "qti_charger_init",iVar9);
                }
              }
            }
          }
        }
      }
      puVar15 = (undefined8 *)devm_kmalloc(*plVar21,0x58,0xdc0);
      if (puVar15 == (undefined8 *)0x0) goto LAB_00103964;
      uVar13 = *param_1;
      uVar17 = param_1[1];
      puVar15[10] = param_1;
      param_1[0x48] = puVar15;
      *puVar15 = uVar13;
      puVar15[1] = uVar17;
      puVar15[2] = qti_charger_get_batt_info;
      puVar15[3] = qti_charger_get_chg_info;
      puVar15[4] = qti_charger_config_charge;
      puVar15[5] = qti_charger_is_charge_tapered;
      puVar15[6] = qti_charger_is_charge_halt;
      puVar15[8] = qti_charger_set_constraint;
      *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
      iVar9 = mmi_register_charger_driver();
      if (iVar9 == 0) {
        _printk(&DAT_0010e744,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"I %s: %s: qti charger init successfully\n",*param_1,
                       "qti_charger_init");
      }
      else {
        _printk(&DAT_0010ccb2,*param_1,"qti_charger_init",iVar9);
        ipc_log_string(param_1[0x55],"E %s: %s: qti charger init failed, rc=%d\n",*param_1,
                       "qti_charger_init",iVar9);
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_tcmd);
      if (iVar9 != 0) {
        _printk(&DAT_0010dd46,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create tcmd\n",*param_1,"qti_charger_init"
                      );
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_force_pmic_icl);
      if (iVar9 != 0) {
        _printk(&DAT_0010c0bd,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create force_pmic_icl\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_force_wls_en);
      if (iVar9 != 0) {
        _printk(&DAT_0010ebdb,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create force_wls_en\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_force_usb_suspend);
      if (iVar9 != 0) {
        _printk(&DAT_0010d523,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create force_usb_suspend\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_force_wls_volt_max);
      if (iVar9 != 0) {
        _printk(&DAT_0010ec03,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create force_wls_volt_max\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_force_wls_curr_max);
      if (iVar9 != 0) {
        _printk(&DAT_0010d550,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create force_wls_curr_max\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_wireless_chip_id);
      if (iVar9 != 0) {
        _printk(&DAT_0010ced7,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create wireless_chip_id\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_wireless_fw_ver);
      if (iVar9 != 0) {
        _printk(&DAT_0010e94a,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create wireless_fw_ver\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_addr);
      if (iVar9 != 0) {
        _printk(&DAT_0010c6a9,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create addr\n",*param_1,"qti_charger_init"
                      );
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_data);
      if (iVar9 != 0) {
        _printk(&DAT_0010d803,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create data\n",*param_1,"qti_charger_init"
                      );
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_wls_fod_curr);
      if (iVar9 != 0) {
        _printk(&DAT_0010caff,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create wls_fod_curr\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_wls_fod_gain);
      if (iVar9 != 0) {
        _printk(&DAT_0010e2c8,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create wls_fod_gain\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_batt_id);
      if (iVar9 != 0) {
        _printk(&DAT_0010de65,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create batt_id\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_cur_batt_id);
      if (iVar9 != 0) {
        _printk(&DAT_0010cb27,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create cur_batt_id\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_cid_status);
      if (iVar9 != 0) {
        _printk(&DAT_0010ad5c,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create cid_status\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_typec_reset);
      if (iVar9 != 0) {
        _printk(&DAT_0010e975,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create typec_reset\n",*param_1,
                       "qti_charger_init");
      }
      iVar9 = device_create_file(*plVar21,&dev_attr_fg_operation);
      if (iVar9 != 0) {
        _printk(&DAT_0010d3c2,*param_1,"qti_charger_init");
        ipc_log_string(param_1[0x55],"E %s: %s: Couldn\'t create fg_operation\n",*param_1,
                       "qti_charger_init");
      }
      bm_ulog_print_mask_log(0x1fffbfffff,3,0x1000);
      if (param_1[0x49] == 0) {
        plVar2 = param_1 + 0x49;
        lVar20 = power_supply_get_by_name("wireless");
        *plVar2 = lVar20;
        if (lVar20 == 0) {
          _printk(&DAT_0010e618);
        }
        else {
          _printk(&DAT_0010c6f2);
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_tx_mode);
          if (iVar9 != 0) {
            _printk(&DAT_0010c833);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_tx_mode_vout);
          if (iVar9 != 0) {
            _printk(&DAT_0010ae41);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_rx_connected);
          if (iVar9 != 0) {
            _printk(&DAT_0010bcf6);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_rx_dev_manufacturing)
          ;
          if (iVar9 != 0) {
            _printk(&DAT_0010eca8);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_rx_dev_type);
          if (iVar9 != 0) {
            _printk(&DAT_0010cd35);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_rx_dev_id);
          if (iVar9 != 0) {
            _printk(&DAT_0010c714);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),
                                     &dev_attr_wls_input_current_limit);
          if (iVar9 != 0) {
            _printk(&DAT_0010b66a);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_folio_mode);
          if (iVar9 != 0) {
            _printk(&DAT_0010d65f);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_light_ctl);
          if (iVar9 != 0) {
            _printk(&DAT_0010affb);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_fan_speed);
          if (iVar9 != 0) {
            _printk(&DAT_0010eff3);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_tx_type);
          if (iVar9 != 0) {
            _printk(&DAT_0010cbce);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_tx_power);
          if (iVar9 != 0) {
            _printk(&DAT_0010e04f);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_tx_capability);
          if (iVar9 != 0) {
            _printk(&DAT_0010e3ab);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_tx_id);
          if (iVar9 != 0) {
            _printk(&DAT_0010c857);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_tx_sn);
          if (iVar9 != 0) {
            _printk(&DAT_0010b9e6);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_st_changed);
          if (iVar9 != 0) {
            _printk(&DAT_0010c4f9);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),
                                     &dev_attr_wls_weak_charge_disable);
          if (iVar9 != 0) {
            _printk(&DAT_0010b24c);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_fac_vbus_voltage)
          ;
          if (iVar9 != 0) {
            _printk(&DAT_0010e087);
          }
          iVar9 = device_create_file(*(undefined8 *)(*plVar2 + 0x98),&dev_attr_wlc_fac_ibus_current)
          ;
          if (iVar9 != 0) {
            _printk(&DAT_0010b286);
          }
          param_1[0x80] = wireless_charger_notify_callback;
          iVar9 = blocking_notifier_chain_register(&qti_chg_notifier_list,param_1 + 0x80);
          if (iVar9 != 0) {
            _printk(&DAT_0010e1a0,iVar9);
          }
        }
      }
      if (param_1 == (undefined8 *)0x0) {
        _printk(&DAT_0010bfc5);
      }
      else {
        lVar20 = power_supply_get_by_name("battery");
        if (lVar20 == 0) {
          _printk(&DAT_0010b6ad);
        }
        else {
          lVar20 = lVar20 + 0x38;
          iVar9 = device_create_file(lVar20,&dev_attr_thermal_primary_charge_control_limit);
          if (iVar9 != 0) {
            _printk(&DAT_0010ba33);
          }
          iVar9 = device_create_file(lVar20,&dev_attr_thermal_primary_charge_control_limit_max);
          if (iVar9 != 0) {
            _printk(&DAT_0010c22e);
          }
          iVar9 = device_create_file(lVar20,&dev_attr_thermal_secondary_charge_control_limit);
          if (iVar9 != 0) {
            _printk(&DAT_0010d69a);
          }
          iVar9 = device_create_file(lVar20,&dev_attr_thermal_secondary_charge_control_limit_max);
          if (iVar9 != 0) {
            _printk(&DAT_0010d2a5);
          }
          uVar11 = thermal_cooling_device_register("primary_charge",param_1,&primary_charge_ops);
          param_1[0x72] = uVar11;
          if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
            uVar10 = (undefined4)uVar11;
            if (uVar11 < 0xfffffffffffff001) {
              uVar10 = 0;
            }
            _dev_err(*plVar21,"Failed to register thermal cooling device rc=%d\n",uVar10);
          }
          uVar11 = thermal_cooling_device_register("secondary_charge",param_1,&secondary_charge_ops)
          ;
          param_1[0x76] = uVar11;
          if ((uVar11 == 0) || (0xfffffffffffff000 < uVar11)) {
            uVar10 = (undefined4)uVar11;
            if (uVar11 < 0xfffffffffffff001) {
              uVar10 = 0;
            }
            _dev_err(*plVar21,"Failed to register thermal cooling device rc=%d\n",uVar10);
          }
        }
      }
      lVar20 = debugfs_create_dir("qti_glink_charger",0);
      param_1[0x83] = lVar20;
      if (lVar20 == 0) {
        pcVar19 = "E %s: %s: Couldn\'t create debug dir\n";
        puVar12 = &DAT_0010dbc9;
LAB_00104998:
        _printk(puVar12,*param_1,"create_debugfs_entries");
        ipc_log_string(param_1[0x55],pcVar19,*param_1,"create_debugfs_entries");
      }
      else {
        lVar20 = debugfs_create_file("wls_dump_info",0x8124,lVar20,param_1,
                                     &wls_dump_info_debugfs_ops);
        if (lVar20 == 0) {
          pcVar19 = "E %s: %s: Couldn\'t create wls_dump_info debug file\n";
          puVar12 = &DAT_0010cfc0;
          goto LAB_00104998;
        }
      }
      trusted_shash_alloc();
      goto LAB_00103964;
    }
    local_48 = 0;
    uStack_40 = 0;
    local_70 = *(char **)(param_1[1] + 0x2e8);
    local_58 = 0;
    local_50 = 0;
    local_68 = 0;
    local_60 = param_1;
    uVar11 = devm_power_supply_register(param_1[1],&batt_psy_desc,&local_70);
    param_1[0x84] = uVar11;
    if (uVar11 < 0xfffffffffffff001) goto LAB_00103e90;
    param_1[0x84] = 0;
    _printk(&DAT_0010cc84,*param_1,"qti_charger_init",uVar11 & 0xffffffff);
    uVar13 = param_1[0x55];
    pcVar19 = "E %s: %s: Failed to register main psy, rc=%d\n";
    uVar17 = *param_1;
    uVar11 = uVar11 & 0xffffffff;
  }
  else {
    uVar11 = uVar11 & 0xffffffff;
    _printk(&DAT_0010dcda,*param_1,"qti_charger_init",uVar11);
    uVar13 = param_1[0x55];
    pcVar19 = "E %s: %s: qti charger set factory mode failed, rc=%d\n";
LAB_00103954:
    uVar17 = *param_1;
  }
  ipc_log_string(uVar13,pcVar19,uVar17,"qti_charger_init",uVar11);
LAB_00103964:
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qti_charger_get_batt_info @ 00105118 size=384
// signature: undefined qti_charger_get_batt_info(void)
// callers: []
//------------------------------------------------------------

int qti_charger_get_batt_info(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  int local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  iVar2 = *(int *)(param_1 + 0x1bc);
  local_40 = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  iVar4 = qti_charger_read(param_1,0,&local_68,0x2c);
  if (iVar4 == 0) {
    *(int *)(param_1 + 0x1b0) = local_68._4_4_ / 1000;
    *(int *)(param_1 + 0x1ac) = (int)local_68 / 1000;
    *(int *)(param_1 + 0x1b8) = local_60._4_4_ / 100;
    *(int *)(param_1 + 0x1b4) = (int)local_60 / 100;
    *(undefined4 *)(param_1 + 0x1cc) = (undefined4)local_48;
    *(undefined4 *)(param_1 + 0x1bc) = (undefined4)local_58;
    *(undefined4 *)(param_1 + 0x1c0) = local_58._4_4_;
    *(int *)(param_1 + 0x1d0) = local_48._4_4_ / 1000;
    uVar1 = *(undefined8 *)(param_1 + 0x1b4);
    *(int *)(param_1 + 0x1d4) = local_40 / 1000;
    uVar5 = *(undefined8 *)(param_1 + 0x1ac);
    *(undefined8 *)(param_1 + 0x1c4) = local_50;
    param_2[2] = *(undefined8 *)(param_1 + 0x1bc);
    param_2[3] = local_50;
    *param_2 = uVar5;
    param_2[1] = uVar1;
    uVar1 = *(undefined8 *)(param_1 + 0x1d4);
    uVar5 = *(undefined8 *)(param_1 + 0x1dc);
    uVar6 = *(undefined8 *)(param_1 + 0x1cc);
    *(undefined4 *)(param_2 + 7) = *(undefined4 *)(param_1 + 0x1e4);
    param_2[5] = uVar1;
    param_2[6] = uVar5;
    param_2[4] = uVar6;
    if (iVar2 != *(int *)(param_1 + 0x1bc)) {
      bm_ulog_print_log(0x1000);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qti_charger_get_chg_info @ 0010529c size=2896
// signature: undefined qti_charger_get_chg_info(void)
// callers: []
//------------------------------------------------------------

void qti_charger_get_chg_info(undefined8 *param_1,undefined8 *param_2)

{
  int *piVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  undefined2 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined1 uVar12;
  undefined1 uVar13;
  undefined1 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  ulong uVar25;
  long lVar26;
  char *pcVar27;
  int iVar28;
  undefined8 uVar29;
  uint uVar30;
  undefined8 local_190;
  undefined8 local_188;
  undefined4 local_180;
  undefined8 local_178;
  undefined8 local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 local_158;
  undefined4 local_150;
  undefined8 local_148;
  undefined8 local_140;
  undefined8 local_138;
  undefined8 local_130;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  uint local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined4 local_78;
  long local_70;
  
  lVar26 = sp_el0;
  local_70 = *(long *)(lVar26 + 0x638);
  local_100 = 0;
  local_f8 = 0;
  local_108 = 0;
  local_110 = 0;
  local_120 = 0;
  local_118 = 0;
  local_130 = 0;
  local_128 = 0;
  local_140 = 0;
  local_138 = 0;
  local_148 = 0;
  local_150 = 0;
  local_160 = 0;
  local_158 = 0;
  local_170 = 0;
  local_168 = 0;
  local_178 = 0;
  local_180 = 0;
  local_190 = 0;
  local_188 = 0;
  uVar25 = qti_charger_read(param_1,1,&local_108,0x18);
  if ((int)uVar25 != 0) goto LAB_0010531c;
  piVar1 = (int *)((long)param_1 + 0x294);
  iVar23 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  iVar28 = *(int *)((long)param_1 + 0x294);
  iVar22 = qti_charger_read(param_1,0x15,piVar1,0x10);
  if (iVar22 != 0) {
    *(undefined4 *)((long)param_1 + 0x29c) = 0;
    piVar1[0] = 0;
    piVar1[1] = 0;
    *(undefined4 *)(param_1 + 0x54) = 0xffffffff;
  }
  if (((iVar23 == -1) || (*(int *)(param_1 + 0x54) != -1)) && ((iVar28 != 0 || (*piVar1 == 0)))) {
    iVar22 = *(int *)(param_1 + 0x54);
    if (((iVar23 == -1) && (iVar22 != -1)) || ((iVar28 != 0 && (*piVar1 == 0)))) {
      if ((qti_charger_get_chg_info_lpd_ulog_triggered == 1) &&
         ((qti_charger_get_chg_info_otg_ulog_triggered & 1) == 0)) {
        bm_ulog_enable_log(0,0);
        iVar22 = *(int *)(param_1 + 0x54);
      }
      qti_charger_get_chg_info_lpd_ulog_triggered = 0;
      _printk(&DAT_0010db34,*param_1,"qti_charger_get_chg_info",
              *(undefined4 *)((long)param_1 + 0x294),*(undefined4 *)(param_1 + 0x53),
              *(undefined4 *)((long)param_1 + 0x29c),iVar22);
      pcVar27 = "W %s: %s: LPD: present=%d, rsbu1=%d, rsbu2=%d, cid=%d\n";
    }
    else {
      _printk(&DAT_0010c18a,*param_1,"qti_charger_get_chg_info",*piVar1,
              *(undefined4 *)(param_1 + 0x53),*(undefined4 *)((long)param_1 + 0x29c));
      pcVar27 = "I %s: %s: LPD: present=%d, rsbu1=%d, rsbu2=%d, cid=%d\n";
    }
  }
  else {
    if (((qti_charger_get_chg_info_lpd_ulog_triggered & 1) == 0) &&
       ((qti_charger_get_chg_info_otg_ulog_triggered & 1) == 0)) {
      bm_ulog_enable_log(1,60000);
    }
    qti_charger_get_chg_info_lpd_ulog_triggered = 1;
    _printk(&DAT_0010c9ce,*param_1,"qti_charger_get_chg_info",*(undefined4 *)((long)param_1 + 0x294)
            ,*(undefined4 *)(param_1 + 0x53),*(undefined4 *)((long)param_1 + 0x29c),
            *(undefined4 *)(param_1 + 0x54));
    pcVar27 = "E %s: %s: LPD: present=%d, rsbu1=%d, rsbu2=%d, cid=%d\n";
  }
  ipc_log_string(param_1[0x55],pcVar27,*param_1,"qti_charger_get_chg_info",
                 *(undefined4 *)((long)param_1 + 0x294),*(undefined4 *)(param_1 + 0x53),
                 *(undefined4 *)((long)param_1 + 0x29c),*(undefined4 *)(param_1 + 0x54));
  if (local_f8._4_1_ == '\0') {
LAB_00105560:
    if (local_f8._4_1_ != '\0') {
      if ((qti_charger_get_chg_info_otg_ulog_triggered == 1) &&
         ((qti_charger_get_chg_info_lpd_ulog_triggered & 1) == 0)) {
        bm_ulog_enable_log(0,0);
      }
      qti_charger_get_chg_info_otg_ulog_triggered = 0;
    }
  }
  else {
    uVar25 = local_108 & 0xffffffff;
    if (3999999 < (int)local_108) goto LAB_00105560;
    if (((qti_charger_get_chg_info_otg_ulog_triggered & 1) == 0) &&
       ((qti_charger_get_chg_info_lpd_ulog_triggered & 1) == 0)) {
      bm_ulog_enable_log(1,60000);
      uVar25 = local_108 & 0xffffffff;
    }
    qti_charger_get_chg_info_otg_ulog_triggered = 1;
    _printk(&DAT_0010c1c1,*param_1,"qti_charger_get_chg_info",uVar25);
    ipc_log_string(param_1[0x55],"E %s: %s: OTG: vbus collapse, vbus=%duV\n",*param_1,
                   "qti_charger_get_chg_info",local_108 & 0xffffffff);
  }
  if (((*(char *)(param_1 + 0x6e) != '\0') && ((int)local_f8 != 0)) &&
     (uVar25 = bm_ulog_is_enabled_by_cmd(), (uVar25 & 1) == 0)) {
    lVar26 = ktime_get_with_offset(1);
    lVar26 = lVar26 / 1000000;
    if (*(int *)(param_1 + 0x3f) == (int)local_f8) {
      if ((((qti_charger_get_chg_info_otg_ulog_triggered & 1) != 0) ||
          ((qti_charger_get_chg_info_lpd_ulog_triggered & 1) != 0)) ||
         (lVar26 < (long)param_1[0x6d])) goto LAB_0010562c;
      bm_ulog_enable_log(1,1000);
      lVar26 = lVar26 + 1000;
    }
    else {
      bm_ulog_enable_log(1,60000);
      lVar26 = lVar26 + 60000;
    }
    param_1[0x6d] = lVar26;
  }
LAB_0010562c:
  iVar28 = (int)local_108 / 1000;
  *(int *)((long)param_1 + 0x1ec) = local_108._4_4_ / 1000;
  *(undefined4 *)((long)param_1 + 500) = local_100._4_4_;
  *(int *)(param_1 + 0x3d) = iVar28;
  *(int *)(param_1 + 0x3e) = (int)local_100;
  iVar23 = (int)local_f8;
  if ((*(int *)(param_1 + 0x3f) != 0) && ((int)local_f8 == 0)) {
    local_78 = 0;
    local_88 = 0;
    local_80 = 0;
    local_98 = 0;
    local_90 = 0;
    local_a8 = 0;
    local_a0 = 0;
    local_ec = 0;
    local_d8 = 0;
    local_d0 = 0;
    local_c8 = 0;
    local_c0 = 0;
    get_random_bytes(&local_ec,1);
    iVar23 = (local_ec & 0xff) % 0x1a + 0x61;
    local_b8 = CONCAT44(local_b8._4_4_,iVar23);
    local_e8 = iVar23;
    _printk(&DAT_0010ec7a,*param_1,"qti_encrypt_authentication",0,iVar23,iVar23);
    ipc_log_string(param_1[0x55],"I %s: %s: encrypt random_num1[%d]: %d, 0x%x \n",*param_1,
                   "qti_encrypt_authentication",0,iVar23,iVar23);
    get_random_bytes((ulong)&local_ec | 1,1);
    iVar23 = (local_ec >> 8 & 0xff) % 0x1a + 0x61;
    local_b8 = CONCAT44(iVar23,(int)local_b8);
    local_e4 = iVar23;
    _printk(&DAT_0010ec7a,*param_1,"qti_encrypt_authentication",1,iVar23,iVar23);
    ipc_log_string(param_1[0x55],"I %s: %s: encrypt random_num1[%d]: %d, 0x%x \n",*param_1,
                   "qti_encrypt_authentication",1,iVar23,iVar23);
    get_random_bytes((ulong)&local_ec | 2,1);
    iVar23 = (local_ec >> 0x10 & 0xff) % 0x1a + 0x61;
    local_b0 = CONCAT44(local_b0._4_4_,iVar23);
    local_e0 = iVar23;
    _printk(&DAT_0010ec7a,*param_1,"qti_encrypt_authentication",2,iVar23,iVar23);
    ipc_log_string(param_1[0x55],"I %s: %s: encrypt random_num1[%d]: %d, 0x%x \n",*param_1,
                   "qti_encrypt_authentication",2,iVar23,iVar23);
    get_random_bytes((ulong)&local_ec | 3,1);
    iVar23 = (local_ec >> 0x18) % 0x1a + 0x61;
    local_b0 = CONCAT44(iVar23,(undefined4)local_b0);
    local_dc = iVar23;
    _printk(&DAT_0010ec7a,*param_1,"qti_encrypt_authentication",3,iVar23,iVar23);
    ipc_log_string(param_1[0x55],"I %s: %s: encrypt random_num1[%d]: %d, 0x%x \n",*param_1,
                   "qti_encrypt_authentication",3,iVar23,iVar23);
    trusted_sha1(&local_b8,4,&local_a8);
    iVar23 = trusted_hmac(&local_b8,4,(long)&local_98 + 4);
    if (iVar23 == 0) {
      uVar24 = (local_98._4_4_ & 0xff00ff00) >> 8 | (local_98._4_4_ & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_d8 = CONCAT44(local_d8._4_4_,uVar24);
      _printk(&DAT_0010db6b,*param_1,"qti_encrypt_authentication",0,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha256[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",0,uVar24);
      uVar24 = ((uint)local_90 & 0xff00ff00) >> 8 | ((uint)local_90 & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_d8 = CONCAT44(uVar24,(undefined4)local_d8);
      _printk(&DAT_0010db6b,*param_1,"qti_encrypt_authentication",1,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha256[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",1,uVar24);
      uVar24 = (local_90._4_4_ & 0xff00ff00) >> 8 | (local_90._4_4_ & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_d0 = CONCAT44(local_d0._4_4_,uVar24);
      _printk(&DAT_0010db6b,*param_1,"qti_encrypt_authentication",2,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha256[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",2,uVar24);
      uVar24 = ((uint)local_88 & 0xff00ff00) >> 8 | ((uint)local_88 & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_d0 = CONCAT44(uVar24,(undefined4)local_d0);
      _printk(&DAT_0010db6b,*param_1,"qti_encrypt_authentication",3,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha256[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",3,uVar24);
      uVar24 = ((uint)local_a8 & 0xff00ff00) >> 8 | ((uint)local_a8 & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_c8 = CONCAT44(local_c8._4_4_,uVar24);
      _printk(&DAT_0010b9a5,*param_1,"qti_encrypt_authentication",0,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha1[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",0,uVar24);
      uVar24 = (local_a8._4_4_ & 0xff00ff00) >> 8 | (local_a8._4_4_ & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_c8 = CONCAT44(uVar24,(undefined4)local_c8);
      _printk(&DAT_0010b9a5,*param_1,"qti_encrypt_authentication",1,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha1[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",1,uVar24);
      uVar24 = ((uint)local_a0 & 0xff00ff00) >> 8 | ((uint)local_a0 & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_c0 = CONCAT44(local_c0._4_4_,uVar24);
      _printk(&DAT_0010b9a5,*param_1,"qti_encrypt_authentication",2,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha1[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",2,uVar24);
      uVar24 = (local_a0._4_4_ & 0xff00ff00) >> 8 | (local_a0._4_4_ & 0xff00ff) << 8;
      uVar24 = uVar24 >> 0x10 | uVar24 << 0x10;
      local_c0 = CONCAT44(uVar24,(undefined4)local_c0);
      _printk(&DAT_0010b9a5,*param_1,"qti_encrypt_authentication",3,uVar24);
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt hmac_sha1[%d]: 0x%x \n",*param_1,
                     "qti_encrypt_authentication",3,uVar24);
      qti_charger_write(param_1,0x3b,&local_e8,0x30);
    }
    else {
      _printk(&DAT_0010e9fc,*param_1,"qti_encrypt_authentication");
      ipc_log_string(param_1[0x55],"I %s: %s: encrypt failed\n",*param_1,
                     "qti_encrypt_authentication");
    }
    iVar28 = *(int *)(param_1 + 0x3d);
    iVar23 = (int)local_f8;
  }
  if ((int)local_100 != 0 && iVar23 == 0) {
    iVar23 = 1;
  }
  *(int *)(param_1 + 0x3f) = iVar23;
  *(uint *)(param_1 + 0x41) = (uint)(4000 < iVar28);
  uVar24 = 0;
  if (param_1[0x49] != 0) {
    local_b8 = 0;
    uVar24 = power_supply_get_property(param_1[0x49],4,&local_b8);
    if ((uVar24 == 0) && ((int)local_b8 != 0)) {
      *(undefined4 *)(param_1 + 0x41) = 0;
    }
  }
  *(char *)((long)param_1 + 0x1fc) = local_f8._4_1_;
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)((long)param_1 + 0x294);
  *(undefined4 *)((long)param_1 + 0x204) = *(undefined4 *)(param_1 + 0x54);
  *param_2 = param_1[0x3d];
  uVar2 = param_1[0x3f];
  uVar3 = param_1[0x40];
  uVar29 = param_1[0x3e];
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(param_1 + 0x41);
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  param_2[1] = uVar29;
  if (param_1[0x49] != 0) {
    qti_charger_read(param_1,0x24,&local_148,0x3c);
    local_98 = local_128;
    local_90 = local_120;
    local_88 = local_118;
    local_80 = CONCAT44(local_80._4_4_,local_110);
    local_b8 = local_148;
    local_b0 = local_140;
    local_a8 = local_138;
    local_a0 = local_130;
    qti_wireless_charge_dump_info(param_1,&local_b8);
  }
  if (*(int *)(param_1 + 0x6b) != 0) {
    uVar30 = 0;
    do {
      qti_charger_read(param_1,uVar30 + 0x31,&local_178,0x2c);
      uVar21 = local_150;
      uVar8 = (undefined4)local_170;
      uVar9 = local_170._4_4_;
      uVar15 = (undefined4)local_168;
      uVar16 = local_168._4_4_;
      uVar17 = (undefined4)local_160;
      uVar18 = local_160._4_4_;
      uVar19 = (undefined4)local_158;
      uVar20 = local_158._4_4_;
      uVar10 = (undefined1)local_178;
      uVar11 = local_178._1_1_;
      uVar12 = local_178._2_1_;
      uVar13 = local_178._3_1_;
      uVar14 = local_178._4_1_;
      _printk(&DAT_0010ee14,*param_1,"qti_switched_dump_info");
      ipc_log_string(param_1[0x55],
                     "I %s: %s: switchedcap dump info [0x%02x-%d]: chg_en %d, work_mode 0x%x, int_stat 0x%x, ibat_ma %d, ibus_ma %d, vbus_mv %d, vout_mv %d, vac_mv %d, vbat_mv %d, vusb_mv %d, vwpc_mv %d, die_temp %d"
                     ,*param_1,"qti_switched_dump_info",uVar11,uVar12,uVar10,uVar13,uVar14,uVar8,
                     uVar9,uVar15,uVar16,uVar17,uVar18,uVar19,uVar20,uVar21);
      uVar30 = uVar30 + 1;
    } while (uVar30 < *(uint *)(param_1 + 0x6b));
  }
  qti_charger_read(param_1,0x37,&local_190,0x14);
  uVar9 = local_180;
  uVar25 = local_190 & 0xff;
  uVar4 = local_190._2_2_;
  uVar5 = local_190._4_2_;
  iVar23 = (int)local_190._6_2_;
  sVar6 = (short)local_188;
  uVar8 = local_188._4_4_;
  uVar7 = local_188._2_2_;
  _printk(&DAT_0010c77e,*param_1,"qti_fg_charge_dump_info",uVar25,iVar23,local_190._4_2_,
          local_190._2_2_,(int)(short)local_188,local_188._2_2_,local_188._4_4_,local_180);
  ipc_log_string(param_1[0x55],
                 "I %s: %s: FG dump info: WORK_MODE: 0x%x, SOC: %d, VOLTAGE_MV: %dmV, CURRENT_MA: %dmA, TEMP: %d, CYCLE_COUNT: %d, REMAINING_CAPACITY: %d, FULL_CAPACITY: %d"
                 ,*param_1,"qti_fg_charge_dump_info",uVar25,iVar23,uVar5,uVar4,(int)sVar6,uVar7,
                 uVar8,uVar9);
  _printk(&DAT_0010c442,*param_1,"qti_charger_get_chg_info",*(undefined4 *)((long)param_1 + 900),
          *(undefined4 *)(param_1 + 0x70),*(undefined4 *)((long)param_1 + 0x3a4),
          *(undefined4 *)(param_1 + 0x74));
  ipc_log_string(param_1[0x55],
                 "I %s: %s: Thermal: primary_limit_level = %d, primary_fcc_ma = %d, secondary_limit_level = %d, thermal_secondary_fcc_ma = %d"
                 ,*param_1,"qti_charger_get_chg_info",*(undefined4 *)((long)param_1 + 900),
                 *(undefined4 *)(param_1 + 0x70),*(undefined4 *)((long)param_1 + 0x3a4),
                 *(undefined4 *)(param_1 + 0x74));
  bm_ulog_print_log(0x1000);
  uVar25 = (ulong)uVar24;
LAB_0010531c:
  lVar26 = sp_el0;
  if (*(long *)(lVar26 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar25);
  }
  return;
}



//------------------------------------------------------------
// qti_charger_config_charge @ 00105df0 size=688
// signature: undefined qti_charger_config_charge(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_charger_config_charge(long param_1,int *param_2)

{
  long lVar1;
  int iVar2;
  undefined1 uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (param_2[1] != *(int *)(param_1 + 0x210)) {
    local_2c = param_2[1] * 1000;
    iVar2 = qti_charger_write(param_1,4,&local_2c,4);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x210) = param_2[1];
    }
  }
  if (*param_2 != *(int *)(param_1 + 0x20c)) {
    local_2c = *param_2 * 1000;
    iVar2 = qti_charger_write(param_1,5,&local_2c,4);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x20c) = *param_2;
    }
  }
  if ((uint)*(byte *)(param_2 + 6) != (uint)*(byte *)(param_1 + 0x224)) {
    local_2c = (uint)*(byte *)(param_2 + 6);
    iVar2 = qti_charger_write(param_1,0xc,&local_2c,4);
    if (iVar2 == 0) {
      *(char *)(param_1 + 0x224) = (char)param_2[6];
    }
  }
  if ((uint)*(byte *)((long)param_2 + 0x17) != (uint)*(byte *)(param_1 + 0x223)) {
    local_2c = (uint)*(byte *)((long)param_2 + 0x17);
    iVar2 = qti_charger_write(param_1,0xd,&local_2c,4);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x223) = *(undefined1 *)((long)param_2 + 0x17);
    }
  }
  if (*(char *)((long)param_2 + 0x16) != *(char *)(param_1 + 0x222)) {
    *(char *)(param_1 + 0x222) = *(char *)((long)param_2 + 0x16);
    *(undefined4 *)(param_1 + 0x1a8) = 0;
  }
  if ((char)param_2[5] != *(char *)(param_1 + 0x220)) {
    *(char *)(param_1 + 0x220) = (char)param_2[5];
  }
  if (param_2[4] != *(uint *)(param_1 + 0x21c)) {
    local_2c = param_2[4];
    iVar2 = qti_charger_write(param_1,6,&local_2c,4);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x21c) = param_2[4];
    }
  }
  if (param_2[3] != *(uint *)(param_1 + 0x218)) {
    local_2c = param_2[3];
    iVar2 = qti_charger_write(param_1,7,&local_2c,4);
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x218) = param_2[3];
    }
  }
  if (*(char *)((long)param_2 + 0x15) != *(char *)(param_1 + 0x221)) {
    uVar3 = 0;
    if (*(char *)((long)param_2 + 0x15) != '\0') {
      local_2c = 1;
      qti_charger_write(param_1,0xd,&local_2c,4);
      msleep(200);
      local_2c = 0;
      qti_charger_write(param_1,0xd,&local_2c,4);
      uVar3 = *(undefined1 *)((long)param_2 + 0x15);
    }
    *(undefined1 *)(param_1 + 0x221) = uVar3;
  }
  iVar2 = qti_charger_get_partner_prop(param_1,0x26,&local_2c);
  if (((iVar2 == 0) && (*(uint *)(param_1 + 0x260) != local_2c)) &&
     (iVar2 = qti_charger_write(param_1,0x2f,&local_2c,4), iVar2 == 0)) {
    *(uint *)(param_1 + 0x260) = local_2c;
  }
  iVar2 = qti_charger_get_partner_prop(param_1,0x2f,&local_2c);
  if (((iVar2 == 0) && (*(uint *)(param_1 + 0x264) != local_2c)) &&
     (iVar2 = qti_charger_write(param_1,0x3a,&local_2c,4), iVar2 == 0)) {
    *(uint *)(param_1 + 0x264) = local_2c;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qti_charger_is_charge_tapered @ 001060a4 size=60
// signature: undefined qti_charger_is_charge_tapered(void)
// callers: []
//------------------------------------------------------------

bool qti_charger_is_charge_tapered(long param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(param_1 + 0x1b0);
  iVar1 = -iVar2;
  if (-1 < iVar2) {
    iVar1 = iVar2;
  }
  if (param_2 < iVar1) {
    *(undefined4 *)(param_1 + 0x1a8) = 0;
    return false;
  }
  uVar3 = *(uint *)(param_1 + 0x1a8);
  iVar1 = 0;
  if (uVar3 < 2) {
    iVar1 = uVar3 + 1;
  }
  *(int *)(param_1 + 0x1a8) = iVar1;
  return 1 < uVar3;
}



//------------------------------------------------------------
// qti_charger_is_charge_halt @ 001060e4 size=20
// signature: undefined qti_charger_is_charge_halt(void)
// callers: []
//------------------------------------------------------------

bool qti_charger_is_charge_halt(long param_1)

{
  return *(int *)(param_1 + 0x1bc) - 3U < 2;
}



//------------------------------------------------------------
// qti_charger_set_constraint @ 001060fc size=456
// signature: undefined qti_charger_set_constraint(void)
// callers: []
//------------------------------------------------------------

void qti_charger_set_constraint(long param_1,uint *param_2)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (*param_2 != *(uint *)(param_1 + 0x228)) {
    local_2c = *param_2;
    iVar2 = qti_charger_write(param_1,0xe,&local_2c,4);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x228) = *param_2;
    }
  }
  if ((uint)*(byte *)((long)param_2 + 5) != (uint)*(byte *)(param_1 + 0x22d)) {
    local_2c = (uint)*(byte *)((long)param_2 + 5);
    iVar2 = qti_charger_write(param_1,0x10,&local_2c,4);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + 0x22d) = *(undefined1 *)((long)param_2 + 5);
    }
  }
  if ((uint)(byte)param_2[1] != (uint)*(byte *)(param_1 + 0x22c)) {
    local_2c = (uint)(byte)param_2[1];
    iVar2 = qti_charger_write(param_1,0xf,&local_2c,4);
    if (iVar2 == 0) {
      *(char *)(param_1 + 0x22c) = (char)param_2[1];
    }
  }
  if (param_2[2] != *(uint *)(param_1 + 0x230)) {
    local_2c = param_2[2];
    iVar2 = qti_charger_write(param_1,8,&local_2c,4);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x230) = param_2[2];
    }
  }
  if (param_2[3] != *(uint *)(param_1 + 0x234)) {
    local_2c = param_2[3];
    iVar2 = qti_charger_write(param_1,9,&local_2c,4);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x234) = param_2[3];
    }
  }
  if (param_2[4] != *(uint *)(param_1 + 0x238)) {
    local_2c = param_2[4];
    iVar2 = qti_charger_write(param_1,10,&local_2c,4);
    if (iVar2 == 0) {
      *(uint *)(param_1 + 0x238) = param_2[4];
    }
  }
  if (*(long *)(param_1 + 0x248) != 0) {
    if (param_2[5] != *(uint *)(param_1 + 0x23c)) {
      local_2c = param_2[5];
      iVar2 = qti_charger_write(param_1,0xb,&local_2c,4);
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x23c) = param_2[5];
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
// mmi_get_bootarg @ 001062c4 size=300
// signature: undefined mmi_get_bootarg(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

void mmi_get_bootarg(undefined8 param_1,undefined8 *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *pcVar5;
  char *local_50;
  char *local_48;
  char *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = (char *)0x0;
  local_40 = (char *)0x0;
  local_50 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar3 != 0) &&
     (iVar2 = of_property_read_string(lVar3,"mmi,bootconfig",&local_40), iVar2 == 0)) {
    sVar4 = strlen(local_40);
    pcVar5 = (char *)__kmalloc(sVar4 + 1,0xdc0);
    if (pcVar5 != (char *)0x0) {
      strlcpy(pcVar5,local_40,sVar4 + 1);
      sVar4 = strlen(pcVar5);
      local_48 = (char *)strnstr(pcVar5,param_1,sVar4);
      if (local_48 != (char *)0x0) {
        local_50 = strsep(&local_48," ");
        if ((local_50 != (char *)0x0) && (pcVar5 = strsep(&local_50,"="), pcVar5 != (char *)0x0)) {
          pcVar5 = strsep(&local_50,"\n");
          bVar1 = pcVar5 == (char *)0x0;
          *param_2 = pcVar5;
          goto LAB_00106324;
        }
      }
    }
  }
  bVar1 = true;
LAB_00106324:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// battery_psy_get_prop @ 001063f4 size=292
// signature: undefined battery_psy_get_prop(void)
// callers: []
//------------------------------------------------------------

void battery_psy_get_prop(undefined8 param_1,undefined4 param_2,uint *param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  local_48 = 0;
  local_58 = 0;
  uVar2 = power_supply_get_drvdata();
  *param_3 = 0xffffffc3;
  iVar3 = qti_charger_read(uVar2,0,&local_58,0x2c);
  if (iVar3 != 0) goto switchD_0010646c_caseD_1;
  switch(param_2) {
  case 0:
    uVar4 = (uint)local_48;
    break;
  default:
    goto switchD_0010646c_caseD_1;
  case 3:
    uVar4 = (uint)(-3000 < local_50._4_4_);
    break;
  case 0xc:
    uVar4 = (uint)local_58;
    break;
  case 0x11:
    uVar4 = local_58._4_4_;
    break;
  case 0x16:
    uVar4 = local_40._4_4_;
    break;
  case 0x18:
    uVar4 = (uint)local_40;
    break;
  case 0x1c:
    uVar4 = (uint)local_38;
    break;
  case 0x2f:
    iVar3 = (int)((ulong)((long)(int)local_50 * 0x51eb851f) >> 0x20);
    iVar5 = (int)local_50 / 100 + ((int)local_50 >> 0x1f);
    goto LAB_001064e4;
  case 0x34:
    iVar3 = (int)((ulong)((long)local_50._4_4_ * 0x66666667) >> 0x20);
    iVar5 = local_50._4_4_ / 10 + (local_50._4_4_ >> 0x1f);
LAB_001064e4:
    uVar4 = iVar5 - (iVar3 >> 0x1f);
  }
  *param_3 = uVar4;
switchD_0010646c_caseD_1:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// battery_psy_set_prop @ 0010651c size=116
// signature: undefined battery_psy_set_prop(void)
// callers: []
//------------------------------------------------------------

undefined8 battery_psy_set_prop(undefined8 param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)power_supply_get_drvdata();
  _printk(&DAT_0010d926,*puVar1,"battery_psy_set_prop",param_2);
  ipc_log_string(puVar1[0x55],"E %s: %s: Not supported property: %d\n",*puVar1,
                 "battery_psy_set_prop",param_2);
  return 0xffffffea;
}



//------------------------------------------------------------
// usb_therm_get_max_state @ 00106594 size=16
// signature: undefined usb_therm_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_therm_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}



//------------------------------------------------------------
// usb_therm_get_cur_state @ 001065a8 size=80
// signature: undefined usb_therm_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_therm_get_cur_state(long param_1,long *param_2)

{
  uint uVar1;
  
  if (*(uint *)(*(long *)(param_1 + 0x3b0) + 0x360) < 0x200) {
    gpio_to_desc();
    uVar1 = gpiod_get_raw_value();
  }
  else {
    uVar1 = (uint)*(byte *)(*(long *)(param_1 + 0x3b0) + 0x364);
  }
  *param_2 = (long)(int)uVar1;
  return 0;
}



//------------------------------------------------------------
// usb_therm_set_cur_state @ 001065fc size=148
// signature: undefined usb_therm_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_therm_set_cur_state(long param_1,long param_2)

{
  undefined *puVar1;
  char *pcVar2;
  bool bVar3;
  undefined8 *puVar4;
  
  puVar4 = *(undefined8 **)(param_1 + 0x3b0);
  bVar3 = param_2 != 0;
  puVar1 = &DAT_0010be99;
  if (!bVar3) {
    puVar1 = &DAT_0010e12e;
  }
  pcVar2 = "I %s: %s: Enable typec mosfet.";
  if (!bVar3) {
    pcVar2 = "I %s: %s: Disable typec mosfet.";
  }
  _printk(puVar1,*puVar4,"usb_therm_set_cur_state");
  ipc_log_string(puVar4[0x55],pcVar2,*puVar4,"usb_therm_set_cur_state");
  usb_therm_set_mosfet(puVar4,bVar3);
  return 0;
}



//------------------------------------------------------------
// usb_therm_set_mosfet @ 00106690 size=628
// signature: undefined usb_therm_set_mosfet(void)
// callers: [usb_therm_set_cur_state]
//------------------------------------------------------------

void usb_therm_set_mosfet(undefined8 *param_1,uint param_2)

{
  uint uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  uVar1 = param_2 & 1;
  local_4c = 0;
  _printk(&DAT_0010c98d,*param_1,"usb_therm_set_mosfet","usb_therm_set_mosfet",uVar1,
          *(undefined4 *)(param_1 + 0x3e),*(undefined1 *)((long)param_1 + 0x364));
  ipc_log_string(param_1[0x55],"I %s: %s: %s,set mos en: %d, chrg_type: %d, mosfet_is_enable: %d",
                 *param_1,"usb_therm_set_mosfet","usb_therm_set_mosfet",uVar1,
                 *(undefined4 *)(param_1 + 0x3e),*(undefined1 *)((long)param_1 + 0x364));
  if ((param_2 & 1) == 0) {
    if (*(char *)((long)param_1 + 0x364) != '\0') {
      if (*(uint *)(param_1 + 0x6c) < 0x200) {
        uVar4 = gpio_to_desc();
        gpiod_direction_output_raw(uVar4,0);
      }
      __const_udelay(0x68dbc);
      local_4c = 0;
      qti_charger_write(param_1,0xd,&local_4c,4);
      local_4c = 0;
      uVar3 = qti_charger_write(param_1,0xc,&local_4c,4);
      *(undefined1 *)((long)param_1 + 0x364) = 0;
      _printk(&DAT_0010c421,*param_1,"usb_therm_set_mosfet","usb_therm_set_mosfet",0,uVar3);
      ipc_log_string(param_1[0x55],"I %s: %s: %s,close mos en: %d %d",*param_1,
                     "usb_therm_set_mosfet","usb_therm_set_mosfet",0,uVar3);
      goto LAB_0010678c;
    }
  }
  else if (*(char *)((long)param_1 + 0x364) == '\0') {
    local_4c = 1;
    qti_charger_write(param_1,0xd,&local_4c,4);
    local_4c = 1;
    uVar3 = qti_charger_write(param_1,0xc,&local_4c,4);
    __const_udelay(0x68dbc);
    if (((*(uint *)(param_1 + 0x3e) | 2) != 3) && (*(uint *)(param_1 + 0x6c) < 0x200)) {
      uVar4 = gpio_to_desc();
      gpiod_direction_output_raw(uVar4,uVar1);
      _printk(&DAT_0010beb8,*param_1,"usb_therm_set_mosfet","usb_therm_set_mosfet",uVar1,uVar3);
      ipc_log_string(param_1[0x55],"I %s: %s: %s,open mos en: %d %d",*param_1,"usb_therm_set_mosfet"
                     ,"usb_therm_set_mosfet",uVar1,uVar3);
    }
    *(undefined1 *)((long)param_1 + 0x364) = 1;
    goto LAB_0010678c;
  }
  _printk(&DAT_0010debf,*param_1,"usb_therm_set_mosfet","usb_therm_set_mosfet");
  ipc_log_string(param_1[0x55],"I %s: %s: %s,ignore the usb_therm settings",*param_1,
                 "usb_therm_set_mosfet","usb_therm_set_mosfet");
LAB_0010678c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qti_charger_get_partner_prop @ 00106904 size=376
// signature: undefined qti_charger_get_partner_prop(void)
// callers: [qti_charger_config_charge]
//------------------------------------------------------------

int qti_charger_get_partner_prop(undefined8 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  if (qti_charger_get_partner_prop_partner_psy_name == (char *)0x0) {
    iVar1 = of_property_read_string
                      (*(undefined8 *)(param_1[1] + 0x2e8),"mmi,partner_psy_name",
                       &qti_charger_get_partner_prop_partner_psy_name);
    if (iVar1 != 0) {
      _printk(&DAT_0010bcb9,*param_1,"qti_charger_get_partner_prop");
      ipc_log_string(param_1[0x55],"E %s: %s: Failed get the partner psy name",*param_1,
                     "qti_charger_get_partner_prop");
      qti_charger_get_partner_prop_partner_psy_name = "";
      goto LAB_001069ac;
    }
  }
  else if (*qti_charger_get_partner_prop_partner_psy_name == '\0') {
    iVar1 = 0;
    goto LAB_001069ac;
  }
  lVar2 = param_1[0x4a];
  if (lVar2 == 0) {
    lVar2 = power_supply_get_by_name(qti_charger_get_partner_prop_partner_psy_name);
    param_1[0x4a] = lVar2;
    if (lVar2 == 0) {
      iVar1 = -0x13;
      goto LAB_001069ac;
    }
  }
  iVar1 = power_supply_get_property(lVar2,param_2,&local_50);
  if (iVar1 < 0) {
    _printk(&DAT_0010ca05,*param_1,"qti_charger_get_partner_prop",param_2,iVar1);
    ipc_log_string(param_1[0x55],"E %s: %s: get property %d failed, rc=%d\n",*param_1,
                   "qti_charger_get_partner_prop",param_2,iVar1);
  }
  else {
    *param_3 = (undefined4)local_50;
  }
LAB_001069ac:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// tcmd_show @ 00106a80 size=156
// signature: undefined tcmd_show(void)
// callers: []
//------------------------------------------------------------

void tcmd_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x11,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// tcmd_store @ 00106b20 size=232
// signature: undefined tcmd_store(void)
// callers: []
//------------------------------------------------------------

void tcmd_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x11,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"tcmd_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,"tcmd_store",local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// force_pmic_icl_show @ 00106c0c size=156
// signature: undefined force_pmic_icl_show(void)
// callers: []
//------------------------------------------------------------

void force_pmic_icl_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x12,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// force_pmic_icl_store @ 00106cac size=232
// signature: undefined force_pmic_icl_store(void)
// callers: []
//------------------------------------------------------------

void force_pmic_icl_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x12,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"force_pmic_icl_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,"force_pmic_icl_store",
                     local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// force_wls_en_show @ 00106d98 size=156
// signature: undefined force_wls_en_show(void)
// callers: []
//------------------------------------------------------------

void force_wls_en_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x17,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// force_wls_en_store @ 00106e38 size=232
// signature: undefined force_wls_en_store(void)
// callers: []
//------------------------------------------------------------

void force_wls_en_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x17,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"force_wls_en_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,"force_wls_en_store",
                     local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// force_usb_suspend_show @ 00106f24 size=156
// signature: undefined force_usb_suspend_show(void)
// callers: []
//------------------------------------------------------------

void force_usb_suspend_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x16,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// force_usb_suspend_store @ 00106fc4 size=232
// signature: undefined force_usb_suspend_store(void)
// callers: []
//------------------------------------------------------------

void force_usb_suspend_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x16,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"force_usb_suspend_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,"force_usb_suspend_store"
                     ,local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// force_wls_volt_max_show @ 001070b0 size=156
// signature: undefined force_wls_volt_max_show(void)
// callers: []
//------------------------------------------------------------

void force_wls_volt_max_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x18,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// force_wls_volt_max_store @ 00107150 size=232
// signature: undefined force_wls_volt_max_store(void)
// callers: []
//------------------------------------------------------------

void force_wls_volt_max_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x18,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"force_wls_volt_max_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,
                     "force_wls_volt_max_store",local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// force_wls_curr_max_show @ 0010723c size=156
// signature: undefined force_wls_curr_max_show(void)
// callers: []
//------------------------------------------------------------

void force_wls_curr_max_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x19,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// force_wls_curr_max_store @ 001072dc size=232
// signature: undefined force_wls_curr_max_store(void)
// callers: []
//------------------------------------------------------------

void force_wls_curr_max_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_30 = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtoull(param_3,0,&local_30);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x19,&local_30,8);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010d616,*puVar3,"force_wls_curr_max_store",local_30);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar3,
                     "force_wls_curr_max_store",local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wireless_chip_id_show @ 001073c8 size=156
// signature: undefined wireless_chip_id_show(void)
// callers: []
//------------------------------------------------------------

void wireless_chip_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x1a,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,"0x%04x\n",local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wireless_fw_ver_show @ 00107468 size=156
// signature: undefined wireless_fw_ver_show(void)
// callers: []
//------------------------------------------------------------

void wireless_fw_ver_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x41,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,"0x%04x\n",local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// addr_store @ 00107508 size=232
// signature: undefined addr_store(void)
// callers: []
//------------------------------------------------------------

void addr_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_2c = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtouint(param_3,0,&local_2c);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x13,&local_2c,4);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010c205,*puVar3,"addr_store",local_2c);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid reg_address = 0x%x\n",*puVar3,"addr_store",
                     local_2c);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// data_show @ 001075f4 size=156
// signature: undefined data_show(void)
// callers: []
//------------------------------------------------------------

void data_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(*(long *)(param_1 + 0x98),0x14,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010ddd1,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// data_store @ 00107694 size=232
// signature: undefined data_store(void)
// callers: []
//------------------------------------------------------------

void data_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  local_2c = 0;
  if (puVar3 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar2 = kstrtouint(param_3,0,&local_2c);
    if (iVar2 == 0) {
      iVar2 = qti_charger_write(puVar3,0x14,&local_2c,4);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
    else {
      _printk(&DAT_0010e020,*puVar3,"data_store",local_2c);
      ipc_log_string(puVar3[0x55],"E %s: %s: Invalid reg_data = 0x%x\n",*puVar3,"data_store",
                     local_2c);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wls_fod_curr_show @ 00107780 size=252
// signature: undefined wls_fod_curr_show(void)
// callers: []
//------------------------------------------------------------

long wls_fod_curr_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  iVar1 = scnprintf(param_3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2b0));
  iVar2 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2b4));
  iVar3 = scnprintf(param_3 + (iVar2 + iVar1),0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2b8));
  iVar3 = iVar3 + iVar2 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 700));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2c0));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2c4));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2c8));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,&DAT_0010e12c);
  return (long)(iVar1 + iVar3);
}



//------------------------------------------------------------
// wls_fod_curr_store @ 00107880 size=552
// signature: undefined wls_fod_curr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 wls_fod_curr_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = 0xffffffffffffffed;
  }
  else {
    local_3c = 0;
    iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
    *(uint *)(puVar4 + 0x56) = local_3c;
    if (iVar2 == 2) {
      iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
      *(uint *)((long)puVar4 + 0x2b4) = local_3c;
      if (iVar2 == 2) {
        iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
        *(uint *)(puVar4 + 0x57) = local_3c;
        if (iVar2 == 2) {
          iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
          *(uint *)((long)puVar4 + 700) = local_3c;
          if (iVar2 == 2) {
            iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
            *(uint *)(puVar4 + 0x58) = local_3c;
            if (iVar2 == 2) {
              iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
              *(uint *)((long)puVar4 + 0x2c4) = local_3c;
              if (iVar2 == 2) {
                sscanf(param_3,"%x,%s",&local_3c,param_3);
                *(uint *)(puVar4 + 0x59) = local_3c;
                iVar2 = qti_charger_write(puVar4,0x20,puVar4 + 0x56,0x1c);
                if (iVar2 != 0) {
                  _printk(&DAT_0010cb93,*puVar4,"fod_curr_store",iVar2);
                  ipc_log_string(puVar4[0x55],
                                 "E %s: %s: qti charger write wls rx fod curr failed, rc=%d\n",
                                 *puVar4,"fod_curr_store",iVar2);
                }
                goto LAB_00107a74;
              }
              uVar3 = 6;
            }
            else {
              uVar3 = 5;
            }
          }
          else {
            uVar3 = 4;
          }
        }
        else {
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 2;
      }
    }
    else {
      uVar3 = 1;
    }
    _printk(&DAT_0010bf06,uVar3);
  }
LAB_00107a74:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wls_fod_gain_show @ 00107aac size=468
// signature: undefined wls_fod_gain_show(void)
// callers: []
//------------------------------------------------------------

long wls_fod_gain_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  iVar1 = scnprintf(param_3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2cc));
  iVar2 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2d0));
  iVar3 = scnprintf(param_3 + (iVar2 + iVar1),0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2d4));
  iVar3 = iVar3 + iVar2 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2d8));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2dc));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2e0));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2e4));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2e8));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2ec));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2f0));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2f4));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2f8));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x2fc));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x300));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x304));
  iVar3 = iVar3 + iVar1;
  iVar1 = scnprintf(param_3 + iVar3,0x32,"0x%02x ",*(undefined4 *)(lVar4 + 0x308));
  iVar1 = iVar1 + iVar3;
  iVar3 = scnprintf(param_3 + iVar1,0x32,&DAT_0010e12c);
  return (long)(iVar3 + iVar1);
}



//------------------------------------------------------------
// wls_fod_gain_store @ 00107c84 size=984
// signature: undefined wls_fod_gain_store(void)
// callers: []
//------------------------------------------------------------

undefined8 wls_fod_gain_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x98);
  if (puVar4 == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = 0xffffffffffffffed;
  }
  else {
    local_3c = 0;
    iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
    *(uint *)((long)puVar4 + 0x2cc) = local_3c;
    if (iVar2 == 2) {
      iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
      *(uint *)(puVar4 + 0x5a) = local_3c;
      if (iVar2 == 2) {
        iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
        *(uint *)((long)puVar4 + 0x2d4) = local_3c;
        if (iVar2 == 2) {
          iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
          *(uint *)(puVar4 + 0x5b) = local_3c;
          if (iVar2 == 2) {
            iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
            *(uint *)((long)puVar4 + 0x2dc) = local_3c;
            if (iVar2 == 2) {
              iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
              *(uint *)(puVar4 + 0x5c) = local_3c;
              if (iVar2 == 2) {
                iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                *(uint *)((long)puVar4 + 0x2e4) = local_3c;
                if (iVar2 == 2) {
                  iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                  *(uint *)(puVar4 + 0x5d) = local_3c;
                  if (iVar2 == 2) {
                    iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                    *(uint *)((long)puVar4 + 0x2ec) = local_3c;
                    if (iVar2 == 2) {
                      iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                      *(uint *)(puVar4 + 0x5e) = local_3c;
                      if (iVar2 == 2) {
                        iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                        *(uint *)((long)puVar4 + 0x2f4) = local_3c;
                        if (iVar2 == 2) {
                          iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                          *(uint *)(puVar4 + 0x5f) = local_3c;
                          if (iVar2 == 2) {
                            iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                            *(uint *)((long)puVar4 + 0x2fc) = local_3c;
                            if (iVar2 == 2) {
                              iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                              *(uint *)(puVar4 + 0x60) = local_3c;
                              if (iVar2 == 2) {
                                iVar2 = sscanf(param_3,"%x,%s",&local_3c,param_3);
                                *(uint *)((long)puVar4 + 0x304) = local_3c;
                                if (iVar2 == 2) {
                                  sscanf(param_3,"%x,%s",&local_3c,param_3);
                                  *(uint *)(puVar4 + 0x61) = local_3c;
                                  iVar2 = qti_charger_write(puVar4,0x21,(long)puVar4 + 0x2cc,0x40);
                                  if (iVar2 != 0) {
                                    _printk(&DAT_0010c4be,*puVar4,"fod_gain_store",iVar2);
                                    ipc_log_string(puVar4[0x55],
                                                                                                      
                                                  "E %s: %s: qti charger write wls rx fod gain failed, rc=%d\n"
                                                  ,*puVar4,"fod_gain_store",iVar2);
                                  }
                                  goto LAB_00108028;
                                }
                                uVar3 = 0xf;
                              }
                              else {
                                uVar3 = 0xe;
                              }
                            }
                            else {
                              uVar3 = 0xd;
                            }
                          }
                          else {
                            uVar3 = 0xc;
                          }
                        }
                        else {
                          uVar3 = 0xb;
                        }
                      }
                      else {
                        uVar3 = 10;
                      }
                    }
                    else {
                      uVar3 = 9;
                    }
                  }
                  else {
                    uVar3 = 8;
                  }
                }
                else {
                  uVar3 = 7;
                }
              }
              else {
                uVar3 = 6;
              }
            }
            else {
              uVar3 = 5;
            }
          }
          else {
            uVar3 = 4;
          }
        }
        else {
          uVar3 = 3;
        }
      }
      else {
        uVar3 = 2;
      }
    }
    else {
      uVar3 = 1;
    }
    _printk(&DAT_0010d634,uVar3);
  }
LAB_00108028:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// batt_id_show @ 00108060 size=668
// signature: undefined batt_id_show(void)
// callers: []
//------------------------------------------------------------

long batt_id_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  char *__src;
  int iVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  size_t __n;
  long lVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long *plVar9;
  char *local_b0;
  char local_a8 [24];
  char local_90 [8];
  char acStack_88 [8];
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined2 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  puVar8 = *(undefined8 **)(param_1 + 0x98);
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_90 = (char  [8])s_profile_ids_map_0010a930._0_8_;
  acStack_88 = (char  [8])s_profile_ids_map_0010a930._8_8_;
  local_80 = 0;
  uStack_78 = 0;
  local_a8[0x10] = '\0';
  local_a8[0x11] = '\0';
  local_a8[0x12] = '\0';
  local_a8[0x13] = '\0';
  local_a8[0] = '\0';
  local_a8[1] = '\0';
  local_a8[2] = '\0';
  local_a8[3] = '\0';
  local_a8[4] = '\0';
  local_a8[5] = '\0';
  local_a8[6] = '\0';
  local_a8[7] = '\0';
  local_a8[8] = '\0';
  local_a8[9] = '\0';
  local_a8[10] = '\0';
  local_a8[0xb] = '\0';
  local_a8[0xc] = '\0';
  local_a8[0xd] = '\0';
  local_a8[0xe] = '\0';
  local_a8[0xf] = '\0';
  local_b0 = (char *)0x0;
  lVar5 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar5 != 0) &&
     (iVar2 = of_property_read_string(lVar5,"mmi,batt_cap",&local_b0), __src = local_b0, iVar2 == 0)
     ) {
    __n = strlen(local_b0);
    if (0x12 < __n) {
      __n = 0x13;
    }
    memcpy(local_a8,__src,__n);
    local_a8[__n] = '\0';
    snprintf(local_90,0x32,"profile-ids-map-%s",local_a8);
  }
  uVar3 = of_property_read_string_helper(*(undefined8 *)(puVar8[1] + 0x2e8),local_90,0,0,0);
  if (((int)uVar3 < 1) || ((uVar3 & 1) != 0)) {
    _printk(&DAT_0010d337,*puVar8,"batt_id_show",local_90,uVar3);
    ipc_log_string(puVar8[0x55],"E %s: %s: Invalid %s in DT, rc=%d\n",*puVar8,"batt_id_show",
                   local_90,uVar3);
    lVar5 = -0x16;
  }
  else {
    uVar1 = uVar3 >> 1;
    lVar6 = devm_kmalloc(puVar8[1],(ulong)uVar1 << 4,0xcc0);
    if (lVar6 == 0) {
      lVar5 = -0xc;
    }
    else {
      iVar2 = of_property_read_string_helper
                        (*(undefined8 *)(puVar8[1] + 0x2e8),local_90,lVar6,uVar3,0);
      if (iVar2 < 0) {
        _printk(&DAT_0010df89,*puVar8,"batt_id_show",local_90,iVar2);
        ipc_log_string(puVar8[0x55],"E %s: %s: Failed to get %s, rc=%d\n",*puVar8,"batt_id_show",
                       local_90,iVar2);
        lVar5 = 0;
      }
      else {
        iVar2 = scnprintf(param_3,0x32,&DAT_0010eff0,(ulong)uVar1);
        if (1 < uVar3) {
          plVar9 = (long *)(lVar6 + 8);
          if (uVar1 < 2) {
            uVar1 = 1;
          }
          uVar7 = (ulong)uVar1;
          do {
            if (*plVar9 == 0) break;
            iVar4 = scnprintf(param_3 + iVar2,0x32,&DAT_0010c22b);
            plVar9 = plVar9 + 2;
            iVar2 = iVar4 + iVar2;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        iVar4 = scnprintf(param_3 + iVar2,0x32,&DAT_0010e12c);
        lVar5 = (long)(iVar4 + iVar2);
      }
      devm_kfree(puVar8[1],lVar6);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar5;
}



//------------------------------------------------------------
// cur_batt_id_show @ 00108300 size=188
// signature: undefined cur_batt_id_show(void)
// callers: []
//------------------------------------------------------------

void cur_batt_id_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  ulong uStack_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    iVar2 = qti_charger_read(*(long *)(param_1 + 0x98),0x42,&local_48,0x20);
    if (iVar2 != 0) {
      _printk(&DAT_0010e380,iVar2);
    }
    uStack_30 = uStack_30 & 0xffffffffffffff;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010dbad,&local_48);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// cid_status_show @ 001083c0 size=88
// signature: undefined cid_status_show(void)
// callers: []
//------------------------------------------------------------

long cid_status_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x2a0));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// typec_reset_store @ 0010841c size=264
// signature: undefined typec_reset_store(void)
// callers: []
//------------------------------------------------------------

long typec_reset_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  int local_3c;
  long local_38;
  
  puVar2 = this_chip;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtouint(param_3,0,&local_3c);
    if (iVar3 == 0) {
      if (local_3c != 0) {
        _printk(&DAT_0010e5f7,*puVar2,"typec_reset_store");
        ipc_log_string(puVar2[0x55],"W %s: %s: typec_reset triggered\n",*puVar2,"typec_reset_store")
        ;
        iVar3 = qti_charger_write(puVar2,0x39,&local_3c,4);
        if (iVar3 != 0) {
          param_4 = (long)iVar3;
        }
      }
    }
    else {
      _printk(&DAT_0010b641);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// fg_operation_store @ 00108528 size=192
// signature: undefined fg_operation_store(void)
// callers: []
//------------------------------------------------------------

void fg_operation_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  lVar2 = this_chip;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(lVar2,0x38,&local_30,8);
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
    }
    else {
      _printk(&DAT_0010e17e,local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wireless_charger_notify_callback @ 001085ec size=616
// signature: undefined wireless_charger_notify_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 wireless_charger_notify_callback(long param_1,undefined8 param_2,int *param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  
  if (*param_3 != 1) {
    _printk(&DAT_0010b2c5);
    return 0;
  }
  switch(param_2) {
  case 0:
    iVar1 = param_3[1];
    if ((iVar1 != *(int *)(param_1 + -0xbc)) && (*(long *)(param_1 + -0x1b8) != 0)) {
      _printk(&DAT_0010ae89);
      sysfs_notify(*(undefined8 *)(*(long *)(param_1 + -0x1b8) + 0x98),0,"rx_connected");
      iVar1 = param_3[1];
    }
    *(int *)(param_1 + -0xbc) = iVar1;
    break;
  case 1:
    break;
  case 2:
    if ((param_3[1] == *(int *)(param_1 + -0xf4)) || (*(long *)(param_1 + -0x1b8) == 0)) break;
    _printk(&DAT_0010ecd9);
    lVar3 = *(long *)(param_1 + -0x1b8);
    pcVar2 = "tx_mode";
    goto LAB_001086d0;
  default:
    _printk(&DAT_0010b553,param_2);
    break;
  case 4:
    if (param_3[1] == *(int *)(param_1 + -0xe4)) break;
    *(int *)(param_1 + -0xe4) = param_3[1];
    if (*(long *)(param_1 + -0x1b8) == 0) break;
    _printk(&DAT_0010cbfc,param_3[1]);
    lVar3 = *(long *)(param_1 + -0x1b8);
    pcVar2 = "wlc_st_changed";
LAB_001086d0:
    sysfs_notify(*(undefined8 *)(lVar3 + 0x98),0,pcVar2);
    break;
  case 5:
    iVar1 = param_3[1];
    if (iVar1 != *(int *)(param_1 + -0xb8)) {
      if (*(long *)(param_1 + -0x1b8) != 0) {
        _printk(&DAT_0010ba12);
        sysfs_notify(*(undefined8 *)(*(long *)(param_1 + -0x1b8) + 0x98),0,"rx_dev_manufacturing");
        iVar1 = param_3[1];
      }
      *(int *)(param_1 + -0xb8) = iVar1;
    }
    iVar1 = param_3[2];
    if (iVar1 != *(int *)(param_1 + -0xb4)) {
      if (*(long *)(param_1 + -0x1b8) != 0) {
        _printk(&DAT_0010f023);
        sysfs_notify(*(undefined8 *)(*(long *)(param_1 + -0x1b8) + 0x98),0,"rx_dev_type");
        iVar1 = param_3[2];
      }
      *(int *)(param_1 + -0xb4) = iVar1;
    }
    iVar1 = param_3[3];
    if (iVar1 != *(int *)(param_1 + -0xb0)) {
      if (*(long *)(param_1 + -0x1b8) != 0) {
        _printk(&DAT_0010cd6a);
        sysfs_notify(*(undefined8 *)(*(long *)(param_1 + -0x1b8) + 0x98),0,"rx_dev_id");
        iVar1 = param_3[3];
      }
      *(int *)(param_1 + -0xb0) = iVar1;
    }
  }
  if (*(long *)(param_1 + -0x1b8) != 0) {
    _printk(&DAT_0010ecee,param_2);
    power_supply_changed(*(long *)(param_1 + -0x1b8));
  }
  return 0;
}



//------------------------------------------------------------
// tx_mode_show @ 00108858 size=168
// signature: undefined tx_mode_show(void)
// callers: []
//------------------------------------------------------------

void tx_mode_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x22,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x30c) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// tx_mode_store @ 00108904 size=236
// signature: undefined tx_mode_store(void)
// callers: []
//------------------------------------------------------------

void tx_mode_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = this_chip;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_40);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(lVar2,0x22,&local_40,8);
      *(int *)(lVar2 + 0x30c) = (int)local_40;
      if (*(long *)(lVar2 + 0x248) != 0) {
        sysfs_notify(*(undefined8 *)(*(long *)(lVar2 + 0x248) + 0x98),0,"tx_mode");
      }
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
    }
    else {
      _printk(&DAT_0010d455,local_40);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// tx_mode_vout_show @ 001089f4 size=176
// signature: undefined tx_mode_vout_show(void)
// callers: []
//------------------------------------------------------------

void tx_mode_vout_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined4 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_68 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x24,&local_68,0x3c);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_50._6_2_);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// rx_connected_show @ 00108aa8 size=88
// signature: undefined rx_connected_show(void)
// callers: []
//------------------------------------------------------------

long rx_connected_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x344));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// rx_dev_manufacturing_show @ 00108b04 size=168
// signature: undefined rx_dev_manufacturing_show(void)
// callers: []
//------------------------------------------------------------

void rx_dev_manufacturing_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x3c,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x348) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010ddea);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// rx_dev_type_show @ 00108bb0 size=168
// signature: undefined rx_dev_type_show(void)
// callers: []
//------------------------------------------------------------

void rx_dev_type_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x3d,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x34c) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010ddea);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// rx_dev_id_show @ 00108c5c size=168
// signature: undefined rx_dev_id_show(void)
// callers: []
//------------------------------------------------------------

void rx_dev_id_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x3e,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x350) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010ddea);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wls_input_current_limit_show @ 00108d08 size=88
// signature: undefined wls_input_current_limit_show(void)
// callers: []
//------------------------------------------------------------

long wls_input_current_limit_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x340));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wls_input_current_limit_store @ 00108d64 size=244
// signature: undefined wls_input_current_limit_store(void)
// callers: []
//------------------------------------------------------------

void wls_input_current_limit_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  puVar2 = this_chip;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(puVar2,0x19,&local_30,8);
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
      *(int *)(puVar2 + 0x68) = (int)local_30;
    }
    else {
      _printk(&DAT_0010d616,*puVar2,"wls_input_current_limit_store",local_30);
      ipc_log_string(puVar2[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar2,
                     "wls_input_current_limit_store",local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// folio_mode_show @ 00108e5c size=88
// signature: undefined folio_mode_show(void)
// callers: []
//------------------------------------------------------------

long folio_mode_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x310));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// folio_mode_store @ 00108eb8 size=200
// signature: undefined folio_mode_store(void)
// callers: []
//------------------------------------------------------------

void folio_mode_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  lVar2 = this_chip;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(lVar2,0x23,&local_30,8);
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
      *(int *)(lVar2 + 0x310) = (int)local_30;
    }
    else {
      _printk(&DAT_0010d289,local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wlc_light_ctl_show @ 00108f84 size=88
// signature: undefined wlc_light_ctl_show(void)
// callers: []
//------------------------------------------------------------

long wlc_light_ctl_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x314));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wlc_light_ctl_store @ 00108fe0 size=236
// signature: undefined wlc_light_ctl_store(void)
// callers: []
//------------------------------------------------------------

void wlc_light_ctl_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = this_chip;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_40);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(lVar2,0x25,&local_40,8);
      *(int *)(lVar2 + 0x314) = (int)local_40;
      if (*(long *)(lVar2 + 0x248) != 0) {
        sysfs_notify(*(undefined8 *)(*(long *)(lVar2 + 0x248) + 0x98),0,"wlc_light_ctl");
      }
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
    }
    else {
      _printk(&DAT_0010ca70,local_40);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wlc_fan_speed_show @ 001090d0 size=88
// signature: undefined wlc_fan_speed_show(void)
// callers: []
//------------------------------------------------------------

long wlc_fan_speed_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x318));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wlc_fan_speed_store @ 0010912c size=236
// signature: undefined wlc_fan_speed_store(void)
// callers: []
//------------------------------------------------------------

void wlc_fan_speed_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = this_chip;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_40);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(lVar2,0x26,&local_40,8);
      *(int *)(lVar2 + 0x318) = (int)local_40;
      if (*(long *)(lVar2 + 0x248) != 0) {
        sysfs_notify(*(undefined8 *)(*(long *)(lVar2 + 0x248) + 0x98),0,"wlc_fan_speed");
      }
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
    }
    else {
      _printk(&DAT_0010ae6a,local_40);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wlc_tx_type_show @ 0010921c size=168
// signature: undefined wlc_tx_type_show(void)
// callers: []
//------------------------------------------------------------

void wlc_tx_type_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x27,&local_2c,4);
    *(undefined4 *)(lVar1 + 800) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_tx_power_show @ 001092c8 size=168
// signature: undefined wlc_tx_power_show(void)
// callers: []
//------------------------------------------------------------

void wlc_tx_power_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x28,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x324) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_tx_capability_show @ 00109374 size=168
// signature: undefined wlc_tx_capability_show(void)
// callers: []
//------------------------------------------------------------

void wlc_tx_capability_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x2b,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x328) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_tx_id_show @ 00109420 size=168
// signature: undefined wlc_tx_id_show(void)
// callers: []
//------------------------------------------------------------

void wlc_tx_id_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x2c,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x32c) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_tx_sn_show @ 001094cc size=168
// signature: undefined wlc_tx_sn_show(void)
// callers: []
//------------------------------------------------------------

void wlc_tx_sn_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = this_chip;
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x2d,&local_2c,4);
    *(undefined4 *)(lVar1 + 0x330) = local_2c;
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_st_changed_show @ 00109578 size=88
// signature: undefined wlc_st_changed_show(void)
// callers: []
//------------------------------------------------------------

long wlc_st_changed_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x31c));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wls_weak_charge_disable_show @ 001095d4 size=88
// signature: undefined wls_weak_charge_disable_show(void)
// callers: []
//------------------------------------------------------------

long wls_weak_charge_disable_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x354));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// wls_weak_charge_disable_store @ 00109630 size=244
// signature: undefined wls_weak_charge_disable_store(void)
// callers: []
//------------------------------------------------------------

void wls_weak_charge_disable_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  puVar2 = this_chip;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  if (this_chip == (undefined8 *)0x0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtoull(param_3,0,&local_30);
    if (iVar3 == 0) {
      iVar3 = qti_charger_write(puVar2,0x34,&local_30,8);
      if (iVar3 != 0) {
        param_4 = (long)iVar3;
      }
      *(int *)((long)puVar2 + 0x354) = (int)local_30;
    }
    else {
      _printk(&DAT_0010d616,*puVar2,"wls_weak_charge_disable_store",local_30);
      ipc_log_string(puVar2[0x55],"E %s: %s: Invalid TCMD = %lu\n",*puVar2,
                     "wls_weak_charge_disable_store",local_30);
      param_4 = -0x16;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// wlc_fac_vbus_voltage_show @ 00109728 size=160
// signature: undefined wlc_fac_vbus_voltage_show(void)
// callers: []
//------------------------------------------------------------

void wlc_fac_vbus_voltage_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x3f,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// wlc_fac_ibus_current_show @ 001097cc size=160
// signature: undefined wlc_fac_ibus_current_show(void)
// callers: []
//------------------------------------------------------------

void wlc_fac_ibus_current_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar3 = -0x13;
  }
  else {
    qti_charger_read(this_chip,0x40,&local_2c,4);
    iVar2 = scnprintf(param_3,0x32,&DAT_0010bf02,local_2c);
    lVar3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// thermal_primary_charge_control_limit_show @ 00109870 size=88
// signature: undefined thermal_primary_charge_control_limit_show(void)
// callers: []
//------------------------------------------------------------

long thermal_primary_charge_control_limit_show
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 900));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// thermal_primary_charge_control_limit_store @ 001098cc size=296
// signature: undefined thermal_primary_charge_control_limit_store(void)
// callers: [primary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

void thermal_primary_charge_control_limit_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined *puVar5;
  ulong local_40;
  long local_38;
  
  lVar3 = this_chip;
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else if (*(int *)(this_chip + 0x388) == 0) {
    param_4 = 0;
  }
  else if (*(int *)(this_chip + 0x388) < 0) {
    _printk(&DAT_0010ed14);
    param_4 = -0x16;
  }
  else {
    iVar4 = kstrtoull(param_3,0,&local_40);
    if (iVar4 == 0) {
      if (local_40 <= (ulong)(long)*(int *)(lVar3 + 0x388)) {
        uVar1 = *(undefined4 *)(*(long *)(lVar3 + 0x378) + local_40 * 4);
        *(int *)(lVar3 + 900) = (int)local_40;
        *(undefined4 *)(lVar3 + 0x380) = uVar1;
        _printk(&DAT_0010cf80);
        iVar4 = qti_charger_write(lVar3,0x35,lVar3 + 0x380,4);
        if (iVar4 != 0) {
          param_4 = (long)iVar4;
        }
        goto LAB_0010990c;
      }
      puVar5 = &DAT_0010e63f;
    }
    else {
      puVar5 = &DAT_0010bf51;
    }
    _printk(puVar5);
    param_4 = -0x16;
  }
LAB_0010990c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// thermal_primary_charge_control_limit_max_show @ 001099f8 size=88
// signature: undefined thermal_primary_charge_control_limit_max_show(void)
// callers: []
//------------------------------------------------------------

long thermal_primary_charge_control_limit_max_show
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x388));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// thermal_secondary_charge_control_limit_show @ 00109a54 size=88
// signature: undefined thermal_secondary_charge_control_limit_show(void)
// callers: []
//------------------------------------------------------------

long thermal_secondary_charge_control_limit_show
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010d86e);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x3a4));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// thermal_secondary_charge_control_limit_store @ 00109ab0 size=296
// signature: undefined thermal_secondary_charge_control_limit_store(void)
// callers: [secondary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

void thermal_secondary_charge_control_limit_store
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  undefined4 uVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  undefined *puVar5;
  ulong local_40;
  long local_38;
  
  lVar3 = this_chip;
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    param_4 = -0x13;
  }
  else if (*(int *)(this_chip + 0x3a8) == 0) {
    param_4 = 0;
  }
  else if (*(int *)(this_chip + 0x3a8) < 0) {
    _printk(&DAT_0010ea56);
    param_4 = -0x16;
  }
  else {
    iVar4 = kstrtoull(param_3,0,&local_40);
    if (iVar4 == 0) {
      if (local_40 <= (ulong)(long)*(int *)(lVar3 + 0x3a8)) {
        uVar1 = *(undefined4 *)(*(long *)(lVar3 + 0x398) + local_40 * 4);
        *(int *)(lVar3 + 0x3a4) = (int)local_40;
        *(undefined4 *)(lVar3 + 0x3a0) = uVar1;
        _printk(&DAT_0010c73a);
        iVar4 = qti_charger_write(lVar3,0x36,lVar3 + 0x3a0,4);
        if (iVar4 != 0) {
          param_4 = (long)iVar4;
        }
        goto LAB_00109af0;
      }
      puVar5 = &DAT_0010d495;
    }
    else {
      puVar5 = &DAT_0010e3eb;
    }
    _printk(puVar5);
    param_4 = -0x16;
  }
LAB_00109af0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// thermal_secondary_charge_control_limit_max_show @ 00109bdc size=88
// signature: undefined thermal_secondary_charge_control_limit_max_show(void)
// callers: []
//------------------------------------------------------------

long thermal_secondary_charge_control_limit_max_show
               (undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  if (this_chip == 0) {
    _printk(&DAT_0010bfc5);
    lVar2 = -0x13;
  }
  else {
    iVar1 = scnprintf(param_3,0x32,&DAT_0010bf02,*(undefined4 *)(this_chip + 0x3a8));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// primary_get_max_charge_cntl_limit @ 00109c38 size=20
// signature: undefined primary_get_max_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 primary_get_max_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x388);
  return 0;
}



//------------------------------------------------------------
// primary_get_cur_charge_cntl_limit @ 00109c50 size=20
// signature: undefined primary_get_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 primary_get_cur_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 900);
  return 0;
}



//------------------------------------------------------------
// primary_set_cur_charge_cntl_limit @ 00109c68 size=160
// signature: undefined primary_set_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

void primary_set_cur_charge_cntl_limit(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  size_t sVar2;
  char local_38 [32];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\0';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  local_38[0x18] = '\0';
  local_38[0x19] = '\0';
  local_38[0x1a] = '\0';
  local_38[0x1b] = '\0';
  local_38[0x1c] = '\0';
  local_38[0x1d] = '\0';
  local_38[0x1e] = '\0';
  local_38[0x1f] = '\0';
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  sprintf(local_38,"%ld",param_2);
  sVar2 = strnlen(local_38,0x20);
  if (sVar2 < 0x21) {
    if (sVar2 != 0x20) {
      thermal_primary_charge_control_limit_store();
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) == local_18) {
        return;
      }
      goto LAB_00109d04;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("__fortify_strlen");
LAB_00109d04:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// secondary_get_max_charge_cntl_limit @ 00109d0c size=20
// signature: undefined secondary_get_max_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 secondary_get_max_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x3a8);
  return 0;
}



//------------------------------------------------------------
// secondary_get_cur_charge_cntl_limit @ 00109d24 size=20
// signature: undefined secondary_get_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

undefined8 secondary_get_cur_charge_cntl_limit(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x3a4);
  return 0;
}



//------------------------------------------------------------
// secondary_set_cur_charge_cntl_limit @ 00109d3c size=160
// signature: undefined secondary_set_cur_charge_cntl_limit(void)
// callers: []
//------------------------------------------------------------

void secondary_set_cur_charge_cntl_limit(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  size_t sVar2;
  char local_38 [32];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38[0x10] = '\0';
  local_38[0x11] = '\0';
  local_38[0x12] = '\0';
  local_38[0x13] = '\0';
  local_38[0x14] = '\0';
  local_38[0x15] = '\0';
  local_38[0x16] = '\0';
  local_38[0x17] = '\0';
  local_38[0x18] = '\0';
  local_38[0x19] = '\0';
  local_38[0x1a] = '\0';
  local_38[0x1b] = '\0';
  local_38[0x1c] = '\0';
  local_38[0x1d] = '\0';
  local_38[0x1e] = '\0';
  local_38[0x1f] = '\0';
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  local_38[4] = '\0';
  local_38[5] = '\0';
  local_38[6] = '\0';
  local_38[7] = '\0';
  local_38[8] = '\0';
  local_38[9] = '\0';
  local_38[10] = '\0';
  local_38[0xb] = '\0';
  local_38[0xc] = '\0';
  local_38[0xd] = '\0';
  local_38[0xe] = '\0';
  local_38[0xf] = '\0';
  sprintf(local_38,"%ld",param_2);
  sVar2 = strnlen(local_38,0x20);
  if (sVar2 < 0x21) {
    if (sVar2 != 0x20) {
      thermal_secondary_charge_control_limit_store();
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) == local_18) {
        return;
      }
      goto LAB_00109dd8;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("__fortify_strlen");
LAB_00109dd8:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// wls_dump_info_debugfs_open @ 00109de0 size=48
// signature: undefined wls_dump_info_debugfs_open(void)
// callers: []
//------------------------------------------------------------

void wls_dump_info_debugfs_open(long param_1,undefined8 param_2)

{
  single_open(param_2,show_wls_dump_info,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// show_wls_dump_info @ 00109e14 size=688
// signature: undefined show_wls_dump_info(void)
// callers: []
//------------------------------------------------------------

undefined8 show_wls_dump_info(long param_1)

{
  long lVar1;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  local_48 = 0;
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  qti_charger_read(*(undefined8 *)(param_1 + 0x80),0x24,&local_68,0x3c);
  seq_printf(param_1,"CHIP_ID: 0x%04x\n",local_68 & 0xffffffff);
  seq_printf(param_1,"MTP_FW_VER: 0x%04x\n",local_68._4_4_);
  seq_printf(param_1,"IRQ STATUS: 0x%04x\n",local_60 & 0xffffffff);
  seq_printf(param_1,"SYS_MODE:  RX/TX %d\n",local_60._4_2_);
  seq_printf(param_1,"OP_MODE:  BPP/EPP 0x%x\n",local_60._6_2_);
  seq_printf(param_1,"RX_FOP:   %dkHz\n",local_58 & 0xffff);
  seq_printf(param_1,"RX_VOUT: %dmV\n",local_58._2_2_);
  seq_printf(param_1,"RX_VRECT: %dmV\n",local_58._4_2_);
  seq_printf(param_1,"RX_IRECT: %dmV\n",local_58._6_2_);
  seq_printf(param_1,"RX_NEG_POWER: %dw\n",local_50 & 0xffff);
  seq_printf(param_1,"TX_IIN: %dmA\n",local_50._2_2_);
  seq_printf(param_1,"TX_VIN: %dmV\n",local_50._4_2_);
  seq_printf(param_1,"TX_VRECT: %dmV\n",local_50._6_2_);
  seq_printf(param_1,"TX_FOD_I: %d\n",local_48 & 0xffff);
  seq_printf(param_1,"TX_FOD_II: %d\n",local_48._2_2_);
  seq_printf(param_1,"TX_FOD_RP: %d\n",local_48._4_2_);
  seq_printf(param_1,"TX_DET_RX_POWER: %dmW\n",local_48._6_2_);
  seq_printf(param_1,"TX_POWER: %dmW\n",local_40 & 0xffff);
  seq_printf(param_1,"POWER_LOSS: %dmW\n",(long)local_40._2_2_);
  seq_printf(param_1,"TX_FOD: %d\n",(uint)local_60 >> 0xc & 1);
  seq_printf(param_1,"FOLIO_MODE: %d\n",local_40._4_2_);
  seq_printf(param_1,"PEN_STATUS: %d\n",local_40._6_2_);
  seq_printf(param_1,"PEN_SOC: %d\n",local_38 & 0xffff);
  seq_printf(param_1,"PEN_ERROR: %d\n",local_38._2_2_);
  seq_printf(param_1,"USB_OTG: %d\n",local_38._4_2_);
  seq_printf(param_1,"WLS_BOOST: %d\n",local_38._6_2_);
  seq_printf(param_1,"WLS_ICL_MA: %d\n",(undefined2)local_30);
  seq_printf(param_1,"WLS_ICL_THERM_MA: %d\n",local_30._2_2_);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// trusted_shash_alloc @ 0010a0c8 size=188
// signature: undefined trusted_shash_alloc(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong trusted_shash_alloc(void)

{
  ulong uVar1;
  
  _hmacalg = crypto_alloc_shash("hmac(sha256)",0,0);
  if (_hmacalg < 0xfffffffffffff001) {
    _hashalg = crypto_alloc_shash(&hash_alg,0,0);
    uVar1 = 0;
    if (0xfffffffffffff000 < _hashalg) {
      _printk(&DAT_0010d710,&hash_alg);
      uVar1 = _hashalg & 0xffffffff;
      crypto_destroy_tfm(_hmacalg,_hmacalg + 0x40);
    }
  }
  else {
    _printk(&DAT_0010d710,"hmac(sha256)");
    uVar1 = _hmacalg & 0xffffffff;
  }
  return uVar1;
}



//------------------------------------------------------------
// trusted_shash_release @ 0010a188 size=64
// signature: undefined trusted_shash_release(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trusted_shash_release(void)

{
  if (_hashalg != 0) {
    crypto_destroy_tfm(_hashalg,_hashalg + 0x40);
  }
  if (_hmacalg != 0) {
    crypto_destroy_tfm(_hmacalg,_hmacalg + 0x40);
  }
  return;
}



//------------------------------------------------------------
// trusted_sha1_set @ 0010a1cc size=212
// signature: undefined trusted_sha1_set(void)
// callers: [trusted_sha1]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong trusted_sha1_set(undefined8 param_1,undefined4 param_2,undefined8 param_3)

{
  uint uVar1;
  uint *puVar2;
  code *pcVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined8 *puVar6;
  
  puVar2 = _hashalg;
  if (_hashalg == (uint *)0x0) {
    _printk(&DAT_0010baa4);
    puVar6 = (undefined8 *)0xffffffff;
  }
  else {
    uVar1 = *_hashalg;
    puVar4 = (undefined8 *)__kmalloc((long)(int)(uVar1 + 8),0xcc0);
    if (puVar4 == (undefined8 *)0x0) {
      puVar6 = (undefined8 *)0xfffffffffffffff4;
    }
    else {
      if (0xfffffff7 < uVar1) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x10a2a0);
        (*pcVar3)();
      }
      *puVar4 = puVar2;
      puVar6 = puVar4;
      if (puVar4 < (undefined8 *)0xfffffffffffff001) {
        uVar5 = crypto_shash_digest(puVar4,param_1,param_2,param_3);
        puVar6 = (undefined8 *)(uVar5 & 0xffffffff);
        kfree_sensitive(puVar4);
        goto LAB_0010a250;
      }
    }
    _printk(&DAT_0010c577,&hash_alg);
  }
LAB_0010a250:
  return (ulong)puVar6 & 0xffffffff;
}



//------------------------------------------------------------
// trusted_sha1 @ 0010a2a4 size=228
// signature: undefined trusted_sha1(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trusted_sha1(byte *param_1,int param_2,undefined8 param_3)

{
  long lVar1;
  size_t __n;
  undefined8 uVar2;
  uint local_3c;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  if (param_2 != 4) {
    uVar2 = 0xffffffff;
LAB_0010a344:
    lVar1 = sp_el0;
    if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar2);
    }
    return;
  }
  local_3c = (*(uint *)(param_1 + 8) & 0xff) << 0x10 | *(int *)(param_1 + 0xc) << 0x18 |
             (*(uint *)(param_1 + 4) & 0xff) << 8 | (uint)*param_1;
  __n = strnlen(sha1_key,0x11);
  if (__n < 0x12) {
    if (__n != 0x11) {
      memcpy(&local_38,sha1_key,__n);
      uVar2 = trusted_sha1_set(&local_3c,0x14,param_3);
      goto LAB_0010a344;
    }
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("__fortify_strlen");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trusted_hmac_set @ 0010a38c size=416
// signature: undefined trusted_hmac_set(void)
// callers: [trusted_hmac]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong trusted_hmac_set(undefined8 param_1,undefined8 param_2,undefined4 param_3,long param_4,
                      uint param_5)

{
  undefined4 uVar1;
  ulong uVar2;
  uint *puVar3;
  code *pcVar4;
  long lVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  int iVar8;
  ulong uVar9;
  uint uVar10;
  
  if (_hmacalg == (uint *)0x0) {
    _printk(&DAT_0010e836);
    return 0xffffffff;
  }
  uVar2 = (ulong)param_5 * 4;
  lVar5 = __kmalloc(uVar2,0xdc0);
  if (lVar5 == 0) {
    return 0xfffffff4;
  }
  if (param_5 != 0) {
    uVar10 = 0;
    iVar8 = 3;
    do {
      uVar9 = (ulong)iVar8;
      if (uVar2 < uVar9) goto LAB_0010a528;
      uVar1 = *(undefined4 *)(param_4 + (long)(int)uVar10 * 4);
      *(char *)(lVar5 + uVar9) = (char)uVar1;
      if (uVar2 < uVar9 - 1) goto LAB_0010a528;
      *(char *)(lVar5 + (uVar9 - 1)) = (char)((uint)uVar1 >> 8);
      if (uVar2 < uVar9 - 2) goto LAB_0010a528;
      uVar1 = *(undefined4 *)(param_4 + (long)(int)uVar10 * 4);
      *(char *)(lVar5 + (uVar9 - 2)) = (char)((uint)uVar1 >> 0x10);
      if (uVar2 <= uVar9 - 3) goto LAB_0010a528;
      uVar10 = uVar10 + 1;
      iVar8 = iVar8 + 4;
      *(char *)(lVar5 + (uVar9 - 3)) = (char)((uint)uVar1 >> 0x18);
    } while (param_5 != uVar10);
  }
  puVar3 = _hmacalg;
  uVar10 = *_hmacalg;
  puVar6 = (undefined8 *)__kmalloc((long)(int)(uVar10 + 8),0xcc0);
  if (puVar6 == (undefined8 *)0x0) {
    puVar6 = (undefined8 *)0xfffffffffffffff4;
  }
  else {
    if (0xfffffff7 < uVar10) {
LAB_0010a528:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x10a52c);
      (*pcVar4)();
    }
    *puVar6 = puVar3;
    if (puVar6 < (undefined8 *)0xfffffffffffff001) {
      puVar7 = (undefined8 *)crypto_shash_setkey(_hmacalg,param_2,param_3);
      if (-1 < (int)puVar7) {
        puVar7 = (undefined8 *)crypto_shash_digest(puVar6,lVar5,param_5 << 2,param_1);
      }
      goto LAB_0010a4b8;
    }
  }
  _printk(&DAT_0010c577,"hmac(sha256)");
  puVar7 = puVar6;
LAB_0010a4b8:
  kfree(lVar5);
  kfree_sensitive(puVar6);
  return (ulong)puVar7 & 0xffffffff;
}



//------------------------------------------------------------
// trusted_hmac @ 0010a530 size=120
// signature: undefined trusted_hmac(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

void trusted_hmac(undefined8 *param_1,int param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  if (param_2 == 4) {
    local_28 = *param_1;
    uStack_20 = param_1[1];
    uVar2 = trusted_hmac_set(param_3,hmac_key,0x24,&local_28,4);
  }
  else {
    uVar2 = 0xffffffff;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010a620 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qti_charger_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010a650 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qti_charger_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00112000 size=1
// signature: undefined _printk(void)
// callers: [wireless_fw_ver_show, thermal_secondary_charge_control_limit_store, tcmd_show, addr_store, wlc_st_changed_show, wlc_fan_speed_show, battery_psy_set_prop, qti_charger_init, qti_charger_set_property, usb_therm_set_mosfet, trusted_hmac_set, wls_weak_charge_disable_store, qti_charger_write, thermal_secondary_charge_control_limit_show, qti_charger_get_chg_info, rx_dev_id_show, cid_status_show, force_wls_volt_max_show, data_store, wlc_fac_ibus_current_show, wlc_tx_power_show, wlc_light_ctl_store, force_wls_curr_max_show, batt_id_show, thermal_secondary_charge_control_limit_max_show, typec_reset_store, qti_charger_shutdown, thermal_primary_charge_control_limit_show, rx_dev_manufacturing_show, oem_state_cb, wireless_charger_notify_callback, rx_dev_type_show, tx_mode_vout_show, oem_callback, data_show, tx_mode_show, thermal_primary_charge_control_limit_max_show, fg_operation_store, wlc_tx_sn_show, thermal_primary_charge_control_limit_store, wls_fod_curr_store, qti_charger_setup_work, force_wls_en_store, qti_charger_remove, force_pmic_icl_show, trusted_shash_alloc, cur_batt_id_show, folio_mode_show, wls_input_current_limit_show, tx_mode_store, qti_charger_get_partner_prop, wireless_chip_id_show, wlc_light_ctl_show, qti_wireless_charge_dump_info, wlc_tx_capability_show, qti_charger_probe, tcmd_store, wls_input_current_limit_store, usb_therm_set_cur_state, rx_connected_show, folio_mode_store, qti_charger_get_property, qti_charger_read, wlc_tx_type_show, force_wls_volt_max_store, wlc_fan_speed_store, force_wls_en_show, trusted_sha1_set, wls_fod_gain_store, wls_weak_charge_disable_show, force_usb_suspend_store, force_usb_suspend_show, qti_fg_charge_dump_info, force_wls_curr_max_store, force_pmic_icl_store, qti_switched_dump_info, wlc_tx_id_show, wlc_fac_vbus_voltage_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00112008 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [trusted_sha1, qti_charger_read, qti_charger_probe, qti_charger_init, qti_charger_write, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00112010 size=1
// signature: undefined mutex_lock(void)
// callers: [qti_charger_read, qti_charger_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00112018 size=1
// signature: undefined ipc_log_string(void)
// callers: [addr_store, battery_psy_set_prop, qti_charger_init, usb_therm_set_mosfet, wls_weak_charge_disable_store, qti_charger_write, qti_charger_get_partner_prop, qti_charger_get_chg_info, qti_wireless_charge_dump_info, qti_charger_probe, tcmd_store, wls_input_current_limit_store, usb_therm_set_cur_state, data_store, batt_id_show, typec_reset_store, qti_charger_shutdown, qti_charger_read, oem_state_cb, force_wls_volt_max_store, oem_callback, wls_fod_gain_store, force_usb_suspend_store, wls_fod_curr_store, qti_charger_setup_work, force_wls_en_store, qti_fg_charge_dump_info, qti_charger_remove, force_wls_curr_max_store, force_pmic_icl_store, qti_switched_dump_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00112020 size=1
// signature: undefined pmic_glink_write(void)
// callers: [qti_charger_read, qti_charger_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00112028 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qti_charger_read, qti_charger_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bm_ulog_print_log @ 00112030 size=1
// signature: undefined bm_ulog_print_log(void)
// callers: [qti_charger_get_batt_info, qti_charger_write, qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bm_ulog_print_log(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00112038 size=1
// signature: undefined mutex_unlock(void)
// callers: [qti_charger_read, qti_charger_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00112040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wireless_fw_ver_show, thermal_secondary_charge_control_limit_store, tcmd_show, addr_store, qti_charger_set_constraint, qti_charger_init, usb_therm_set_mosfet, wls_weak_charge_disable_store, qti_charger_write, qti_charger_get_chg_info, rx_dev_id_show, force_wls_volt_max_show, data_store, wlc_fac_ibus_current_show, wlc_tx_power_show, wlc_light_ctl_store, force_wls_curr_max_show, batt_id_show, typec_reset_store, rx_dev_manufacturing_show, battery_psy_get_prop, trusted_hmac, rx_dev_type_show, qti_charger_get_batt_info, tx_mode_vout_show, data_show, tx_mode_show, fg_operation_store, wlc_tx_sn_show, thermal_primary_charge_control_limit_store, wls_fod_curr_store, force_wls_en_store, mmi_get_bootarg, force_pmic_icl_show, cur_batt_id_show, tx_mode_store, qti_charger_get_partner_prop, wireless_chip_id_show, wlc_tx_capability_show, qti_charger_probe, tcmd_store, wls_input_current_limit_store, secondary_set_cur_charge_cntl_limit, qti_charger_config_charge, qti_charger_notify_work, folio_mode_store, trusted_sha1, qti_charger_read, wlc_tx_type_show, force_wls_volt_max_store, wlc_fan_speed_store, force_wls_en_show, show_wls_dump_info, wls_fod_gain_store, force_usb_suspend_store, force_usb_suspend_show, force_wls_curr_max_store, force_pmic_icl_store, wlc_tx_id_show, wlc_fac_vbus_voltage_show, primary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00112048 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [qti_charger_register_notifier, qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00112050 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [qti_charger_unregister_notifier, qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00112058 size=1
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
// platform_driver_unregister @ 00112060 size=1
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
// devm_kmalloc @ 00112068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qti_charger_probe, qti_charger_init, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00112070 size=1
// signature: undefined __mutex_init(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00112078 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00112080 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_get_battery_serialnumber @ 00112088 size=1
// signature: undefined mmi_get_battery_serialnumber(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_get_battery_serialnumber(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00112090 size=1
// signature: size_t strlen(char * __s)
// callers: [qti_charger_probe, qti_charger_init, mmi_get_bootarg, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00112098 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [qti_charger_probe, mmi_get_bootarg, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001120a0 size=1
// signature: undefined of_property_read_string(void)
// callers: [qti_charger_probe, qti_charger_get_partner_prop, mmi_get_bootarg, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001120a8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qti_charger_probe, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001120b0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [qti_charger_probe, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001120b8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qti_charger_probe, qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001120c0 size=1
// signature: undefined of_find_property(void)
// callers: [qti_charger_probe, qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 001120c8 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 001120d0 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 001120d8 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 001120e0 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001120e8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001120f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qti_charger_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001120f8 size=1
// signature: undefined devm_kfree(void)
// callers: [qti_charger_probe, qti_charger_remove, batt_id_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00112100 size=1
// signature: undefined kstrtouint(void)
// callers: [typec_reset_store, addr_store, qti_charger_probe, data_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00112108 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [qti_charger_probe, secondary_set_cur_charge_cntl_limit, primary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00112110 size=1
// signature: undefined fortify_panic(void)
// callers: [trusted_sha1, qti_charger_probe, secondary_set_cur_charge_cntl_limit, qti_charger_init, primary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00112118 size=1
// signature: undefined device_remove_file(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 00112120 size=1
// signature: undefined power_supply_put(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 00112128 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [qti_charger_init, qti_charger_remove, qti_charger_get_partner_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00112130 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00112138 size=1
// signature: undefined debugfs_remove(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_unregister_charger_driver @ 00112140 size=1
// signature: undefined mmi_unregister_charger_driver(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_unregister_charger_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00112148 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [qti_charger_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00112150 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [qti_charger_notify_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00112158 size=1
// signature: undefined pm_relax(void)
// callers: [qti_charger_notify_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00112160 size=1
// signature: undefined complete(void)
// callers: [oem_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00112168 size=1
// signature: undefined pm_stay_awake(void)
// callers: [oem_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00112178 size=1
// signature: undefined queue_work_on(void)
// callers: [oem_callback, oem_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_is_factory_mode @ 00112180 size=1
// signature: undefined mmi_is_factory_mode(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_is_factory_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_is_factory_version @ 00112188 size=1
// signature: undefined mmi_is_factory_version(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_is_factory_version(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou16 @ 00112190 size=1
// signature: undefined kstrtou16(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou16(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_power_supply_register @ 00112198 size=1
// signature: undefined devm_power_supply_register(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_power_supply_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_register_charger_driver @ 001121a0 size=1
// signature: undefined mmi_register_charger_driver(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_register_charger_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 001121a8 size=1
// signature: undefined device_create_file(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bm_ulog_print_mask_log @ 001121b0 size=1
// signature: undefined bm_ulog_print_mask_log(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bm_ulog_print_mask_log(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_register @ 001121b8 size=1
// signature: undefined thermal_cooling_device_register(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001121c0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001121c8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001121d0 size=1
// signature: undefined _dev_err(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001121d8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [trusted_sha1, secondary_set_cur_charge_cntl_limit, qti_charger_init, primary_set_cur_charge_cntl_limit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 001121e0 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 001121e8 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 001121f0 size=1
// signature: undefined gpio_request(void)
// callers: [qti_charger_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 001121f8 size=1
// signature: undefined gpio_to_desc(void)
// callers: [qti_charger_init, usb_therm_set_mosfet, usb_therm_get_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00112200 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [qti_charger_init, usb_therm_set_mosfet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bm_ulog_enable_log @ 00112208 size=1
// signature: undefined bm_ulog_enable_log(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bm_ulog_enable_log(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bm_ulog_is_enabled_by_cmd @ 00112210 size=1
// signature: undefined bm_ulog_is_enabled_by_cmd(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bm_ulog_is_enabled_by_cmd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 00112218 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 00112220 size=1
// signature: undefined get_random_bytes(void)
// callers: [qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 00112228 size=1
// signature: undefined power_supply_get_property(void)
// callers: [qti_charger_get_partner_prop, qti_charger_get_chg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00112230 size=1
// signature: undefined msleep(void)
// callers: [qti_charger_config_charge]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00112238 size=1
// signature: undefined __kmalloc(void)
// callers: [trusted_sha1_set, trusted_hmac_set, mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 00112240 size=1
// signature: undefined strlcpy(void)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 00112248 size=1
// signature: undefined strnstr(void)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 00112250 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [mmi_get_bootarg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_drvdata @ 00112258 size=1
// signature: undefined power_supply_get_drvdata(void)
// callers: [battery_psy_set_prop, battery_psy_get_prop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00112260 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [usb_therm_get_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00112268 size=1
// signature: undefined __const_udelay(void)
// callers: [usb_therm_set_mosfet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00112270 size=1
// signature: undefined scnprintf(void)
// callers: [wireless_fw_ver_show, cur_batt_id_show, tcmd_show, folio_mode_show, wlc_st_changed_show, wlc_fan_speed_show, wls_input_current_limit_show, thermal_secondary_charge_control_limit_show, wls_fod_curr_show, wireless_chip_id_show, wlc_light_ctl_show, rx_dev_id_show, cid_status_show, wlc_tx_capability_show, force_wls_volt_max_show, rx_connected_show, wlc_fac_ibus_current_show, wlc_tx_power_show, wls_fod_gain_show, force_wls_curr_max_show, batt_id_show, thermal_secondary_charge_control_limit_max_show, thermal_primary_charge_control_limit_show, rx_dev_manufacturing_show, wlc_tx_type_show, rx_dev_type_show, force_wls_en_show, tx_mode_vout_show, data_show, tx_mode_show, thermal_primary_charge_control_limit_max_show, wls_weak_charge_disable_show, wlc_tx_sn_show, force_usb_suspend_show, force_pmic_icl_show, wlc_tx_id_show, wlc_fac_vbus_voltage_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00112278 size=1
// signature: undefined kstrtoull(void)
// callers: [thermal_secondary_charge_control_limit_store, force_wls_volt_max_store, tx_mode_store, wls_weak_charge_disable_store, wlc_fan_speed_store, tcmd_store, fg_operation_store, wls_input_current_limit_store, force_usb_suspend_store, thermal_primary_charge_control_limit_store, force_wls_en_store, folio_mode_store, force_wls_curr_max_store, force_pmic_icl_store, wlc_light_ctl_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00112280 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [wls_fod_gain_store, wls_fod_curr_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_notify @ 00112288 size=1
// signature: undefined sysfs_notify(void)
// callers: [wireless_charger_notify_callback, tx_mode_store, wlc_fan_speed_store, wlc_light_ctl_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_changed @ 00112290 size=1
// signature: undefined power_supply_changed(void)
// callers: [wireless_charger_notify_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_changed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00112298 size=1
// signature: undefined single_open(void)
// callers: [wls_dump_info_debugfs_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001122a0 size=1
// signature: undefined seq_printf(void)
// callers: [show_wls_dump_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_alloc_shash @ 001122c8 size=1
// signature: undefined crypto_alloc_shash(void)
// callers: [trusted_shash_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_alloc_shash(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_destroy_tfm @ 001122d0 size=1
// signature: undefined crypto_destroy_tfm(void)
// callers: [trusted_shash_alloc, trusted_shash_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_destroy_tfm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_shash_digest @ 001122d8 size=1
// signature: undefined crypto_shash_digest(void)
// callers: [trusted_sha1_set, trusted_hmac_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_shash_digest(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 001122e0 size=1
// signature: undefined kfree_sensitive(void)
// callers: [trusted_sha1_set, trusted_hmac_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crypto_shash_setkey @ 001122e8 size=1
// signature: undefined crypto_shash_setkey(void)
// callers: [trusted_hmac_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crypto_shash_setkey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001122f0 size=1
// signature: undefined kfree(void)
// callers: [trusted_hmac_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



