// Decompiled by Ghidra 12.2
// Program: icnss2.ko
// Image base: 00100000

//------------------------------------------------------------
// icnss_debugfs_create @ 001036cc size=168
// signature: undefined icnss_debugfs_create(void)
// callers: [icnss_probe]
//------------------------------------------------------------

ulong icnss_debugfs_create(long param_1)

{
  ulong uVar1;
  
  uVar1 = debugfs_create_dir("icnss",0);
  if (uVar1 < 0xfffffffffffff001) {
    *(ulong *)(param_1 + 0x8b0) = uVar1;
    debugfs_create_file("stats",0x180,uVar1,param_1,&icnss_stats_fops);
    uVar1 = 0;
  }
  else {
    _printk("%sUnable to create debugfs %d\n",&DAT_0011c04b,uVar1 & 0xffffffff);
    ipc_log_string(icnss_ipc_log_context,"%sUnable to create debugfs %d\n",&DAT_0011dab7,
                   uVar1 & 0xffffffff);
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_debugfs_destroy @ 00103778 size=32
// signature: undefined icnss_debugfs_destroy(void)
// callers: [icnss_remove]
//------------------------------------------------------------

void icnss_debugfs_destroy(long param_1)

{
  debugfs_remove(*(undefined8 *)(param_1 + 0x8b0));
  return;
}



//------------------------------------------------------------
// icnss_debug_init @ 0010379c size=352
// signature: undefined icnss_debug_init(void)
// callers: [init_module]
//------------------------------------------------------------

void icnss_debug_init(void)

{
  icnss_ipc_log_context = ipc_log_context_create(10,"icnss",0);
  if (icnss_ipc_log_context == 0) {
    _printk("%sUnable to create log context\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sUnable to create log context\n",&DAT_0011dab7);
  }
  icnss_ipc_log_long_context = ipc_log_context_create(4,"icnss_long",0);
  if (icnss_ipc_log_long_context == 0) {
    _printk("%sUnable to create log long context\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sUnable to create log long context\n",&DAT_0011dab7);
  }
  icnss_ipc_log_smp2p_context = ipc_log_context_create(4,"icnss_smp2p",0);
  if (icnss_ipc_log_smp2p_context == 0) {
    _printk("%sUnable to create log smp2p context\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sUnable to create log smp2p context\n",&DAT_0011dab7);
  }
  icnss_ipc_soc_wake_context = ipc_log_context_create(4,"icnss_soc_wake",0);
  if (icnss_ipc_soc_wake_context == 0) {
    _printk("%sUnable to create log soc_wake context\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sUnable to create log soc_wake context\n",&DAT_0011dab7);
  }
  return;
}



//------------------------------------------------------------
// icnss_debug_deinit @ 00103900 size=112
// signature: undefined icnss_debug_deinit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void icnss_debug_deinit(void)

{
  if (icnss_ipc_log_context != 0) {
    ipc_log_context_destroy();
    icnss_ipc_log_context = 0;
  }
  if (icnss_ipc_log_long_context != 0) {
    ipc_log_context_destroy();
    icnss_ipc_log_long_context = 0;
  }
  if (icnss_ipc_log_smp2p_context != 0) {
    ipc_log_context_destroy();
    icnss_ipc_log_smp2p_context = 0;
  }
  if (icnss_ipc_soc_wake_context != 0) {
    ipc_log_context_destroy();
    icnss_ipc_soc_wake_context = 0;
  }
  return;
}



//------------------------------------------------------------
// icnss_stats_write @ 00103974 size=144
// signature: undefined icnss_stats_write(void)
// callers: []
//------------------------------------------------------------

long icnss_stats_write(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0xd8) + 0x80);
  iVar1 = kstrtouint_from_user(param_2,param_3,0,&local_2c);
  if (iVar1 == 0) {
    memset((void *)(lVar2 + 0x8bc),0,0x240);
  }
  else {
    param_3 = (long)iVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// icnss_stats_open @ 00103a08 size=48
// signature: undefined icnss_stats_open(void)
// callers: []
//------------------------------------------------------------

void icnss_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,icnss_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// icnss_stats_show @ 00103a3c size=2260
// signature: undefined icnss_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_stats_show(long param_1)

{
  bool bVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  undefined4 *puVar7;
  int iVar8;
  
  lVar6 = *(long *)(param_1 + 0x80);
  seq_printf(param_1,"%24s: %u\n","ind_register_req",*(undefined4 *)(lVar6 + 0xa54));
  seq_printf(param_1,"%24s: %u\n","ind_register_resp",*(undefined4 *)(lVar6 + 0xa58));
  seq_printf(param_1,"%24s: %u\n","ind_register_err",*(undefined4 *)(lVar6 + 0xa5c));
  seq_printf(param_1,"%24s: %u\n","cap_req",*(undefined4 *)(lVar6 + 0xa7c));
  seq_printf(param_1,"%24s: %u\n","cap_resp",*(undefined4 *)(lVar6 + 0xa80));
  seq_printf(param_1,"%24s: %u\n","cap_err",*(undefined4 *)(lVar6 + 0xa84));
  seq_printf(param_1,"%24s: %u\n","pin_connect_result",*(undefined4 *)(lVar6 + 0xa88));
  seq_printf(param_1,"%24s: %u\n","cfg_req",*(undefined4 *)(lVar6 + 0xa8c));
  seq_printf(param_1,"%24s: %u\n","cfg_resp",*(undefined4 *)(lVar6 + 0xa90));
  seq_printf(param_1,"%24s: %u\n","cfg_req_err",*(undefined4 *)(lVar6 + 0xa94));
  seq_printf(param_1,"%24s: %u\n","mode_req",*(undefined4 *)(lVar6 + 0xa98));
  seq_printf(param_1,"%24s: %u\n","mode_resp",*(undefined4 *)(lVar6 + 0xa9c));
  seq_printf(param_1,"%24s: %u\n","mode_req_err",*(undefined4 *)(lVar6 + 0xaa0));
  seq_printf(param_1,"%24s: %u\n","ini_req",*(undefined4 *)(lVar6 + 0xaa4));
  seq_printf(param_1,"%24s: %u\n","ini_resp",*(undefined4 *)(lVar6 + 0xaa8));
  seq_printf(param_1,"%24s: %u\n","ini_req_err",*(undefined4 *)(lVar6 + 0xaac));
  seq_printf(param_1,"%24s: %u\n","recovery.pdr_fw_crash",*(undefined4 *)(lVar6 + 0xa1c));
  seq_printf(param_1,"%24s: %u\n","recovery.pdr_host_error",*(undefined4 *)(lVar6 + 0xa20));
  seq_printf(param_1,"%24s: %u\n","recovery.root_pd_crash",*(undefined4 *)(lVar6 + 0xa24));
  seq_printf(param_1,"%24s: %u\n","recovery.root_pd_shutdown",*(undefined4 *)(lVar6 + 0xa28));
  seq_puts(param_1,"\n<------------------ PM stats ------------------->\n");
  seq_printf(param_1,"%24s: %u\n","pm_suspend",*(undefined4 *)(lVar6 + 0xa2c));
  seq_printf(param_1,"%24s: %u\n","pm_suspend_err",*(undefined4 *)(lVar6 + 0xa30));
  seq_printf(param_1,"%24s: %u\n","pm_resume",*(undefined4 *)(lVar6 + 0xa34));
  seq_printf(param_1,"%24s: %u\n","pm_resume_err",*(undefined4 *)(lVar6 + 0xa38));
  seq_printf(param_1,"%24s: %u\n","pm_suspend_noirq",*(undefined4 *)(lVar6 + 0xa3c));
  seq_printf(param_1,"%24s: %u\n","pm_suspend_noirq_err",*(undefined4 *)(lVar6 + 0xa40));
  seq_printf(param_1,"%24s: %u\n","pm_resume_noirq",*(undefined4 *)(lVar6 + 0xa44));
  seq_printf(param_1,"%24s: %u\n","pm_resume_noirq_err",*(undefined4 *)(lVar6 + 0xa48));
  seq_printf(param_1,"%24s: %u\n","pm_stay_awake",*(undefined4 *)(lVar6 + 0xa4c));
  seq_printf(param_1,"%24s: %u\n","pm_relax",*(undefined4 *)(lVar6 + 0xa50));
  if (*(long *)(lVar6 + 0x108) == 0xabcd) {
    seq_puts(param_1,"\n<------------------ MSA stats ------------------->\n");
    seq_printf(param_1,"%24s: %u\n","msa_info_req",*(undefined4 *)(lVar6 + 0xa60));
    seq_printf(param_1,"%24s: %u\n","msa_info_resp",*(undefined4 *)(lVar6 + 0xa64));
    seq_printf(param_1,"%24s: %u\n","msa_info_err",*(undefined4 *)(lVar6 + 0xa68));
    seq_printf(param_1,"%24s: %u\n","msa_ready_req",*(undefined4 *)(lVar6 + 0xa6c));
    seq_printf(param_1,"%24s: %u\n","msa_ready_resp",*(undefined4 *)(lVar6 + 0xa70));
    seq_printf(param_1,"%24s: %u\n","msa_ready_err",*(undefined4 *)(lVar6 + 0xa74));
    seq_printf(param_1,"%24s: %u\n","msa_ready_ind",*(undefined4 *)(lVar6 + 0xa78));
    seq_puts(param_1,"\n<------------------ Rejuvenate stats ------------------->\n");
    seq_printf(param_1,"%24s: %u\n","rejuvenate_ind",*(undefined4 *)(lVar6 + 0xab0));
    seq_printf(param_1,"%24s: %u\n","rejuvenate_ack_req",*(undefined4 *)(lVar6 + 0xab4));
    seq_printf(param_1,"%24s: %u\n","rejuvenate_ack_resp",*(undefined4 *)(lVar6 + 0xab8));
    seq_printf(param_1,"%24s: %u\n","rejuvenate_ack_err",*(undefined4 *)(lVar6 + 0xabc));
    if (*(int *)(lVar6 + 0xab0) != 0) {
      seq_puts(param_1,"\n<---------------- Rejuvenate Info ----------------->\n");
      seq_printf(param_1,"Number of Rejuvenations: %u\n",*(undefined4 *)(lVar6 + 0xab0));
      seq_printf(param_1,"Cause for Rejuvenation: 0x%x\n",*(undefined1 *)(lVar6 + 0xbdb));
      seq_printf(param_1,"Requesting Sub-System: 0x%x\n",*(undefined1 *)(lVar6 + 0xbdc));
      seq_printf(param_1,"Line Number: %u\n",*(undefined2 *)(lVar6 + 0xbde));
      seq_printf(param_1,"Function Name: %s\n",lVar6 + 0xc68);
    }
  }
  seq_puts(param_1,"\n<------------------ IRQ stats ------------------->\n");
  seq_printf(param_1,"%4s %4s %8s %8s %8s %8s\n","CE_ID",&DAT_0011fce3,"Request",&DAT_00123cfd,
             "Enable","Disable");
  uVar5 = 0;
  puVar7 = (undefined4 *)(lVar6 + 0x968);
  do {
    seq_printf(param_1,"%4d: %4u %8u %8u %8u %8u\n",uVar5 & 0xffffffff,
               *(undefined4 *)(lVar6 + 0x134 + uVar5 * 4),puVar7[-3],puVar7[-2],puVar7[-1],*puVar7);
    uVar5 = uVar5 + 1;
    puVar7 = puVar7 + 4;
  } while (uVar5 != 0xc);
  if (((uint)*(undefined8 *)(lVar6 + 0x778) >> 2 & 1) != 0) {
    seq_puts(param_1,"\n<---------------- FW Capability ----------------->\n");
    seq_printf(param_1,"Chip ID: 0x%x\n",*(undefined4 *)(lVar6 + 0x780));
    seq_printf(param_1,"Chip family: 0x%x\n",*(undefined4 *)(lVar6 + 0x784));
    seq_printf(param_1,"Board ID: 0x%x\n",*(undefined4 *)(lVar6 + 0x788));
    seq_printf(param_1,"SOC Info: 0x%x\n",*(undefined4 *)(lVar6 + 0x78c));
    seq_printf(param_1,"Firmware Version: 0x%x\n",*(undefined4 *)(lVar6 + 0x790));
    seq_printf(param_1,"Firmware Build Timestamp: %s\n",lVar6 + 0x794);
    seq_printf(param_1,"Firmware Build ID: %s\n",lVar6 + 0x7b8);
    seq_printf(param_1,"RD card chain cap: %d\n",*(undefined4 *)(lVar6 + 0x1794));
    seq_printf(param_1,"PHY HE channel width cap: %d\n",*(undefined4 *)(lVar6 + 0x1798));
    seq_printf(param_1,"PHY QAM cap: %d\n",*(undefined4 *)(lVar6 + 0x179c));
  }
  seq_puts(param_1,"\n<----------------- Events stats ------------------->\n");
  seq_printf(param_1,"%24s %16s %16s\n","Events","Posted","Processed");
  uVar5 = 0;
  puVar7 = (undefined4 *)(lVar6 + 0x8c0);
  do {
    uVar2 = icnss_driver_event_to_str(uVar5 & 0xffffffff);
    seq_printf(param_1,"%24s %16u %16u\n",uVar2,puVar7[-1],*puVar7);
    uVar5 = uVar5 + 1;
    puVar7 = puVar7 + 2;
  } while (uVar5 != 0x12);
  seq_printf(param_1,"\nSerial Number: 0x%llx",
             (ulong)CONCAT24(*(undefined2 *)(lVar6 + 0x17a4),*(undefined4 *)(lVar6 + 0x17a8)));
  seq_printf(param_1,"\nState: 0x%lx(",*(undefined8 *)(lVar6 + 0x778));
  if (*(ulong *)(lVar6 + 0x778) != 0) {
    iVar8 = 0;
    iVar4 = 0;
    uVar5 = *(ulong *)(lVar6 + 0x778);
    do {
      if ((uVar5 & 1) != 0) {
        if (iVar8 != 0) {
          seq_puts(param_1,&DAT_0011ac22);
        }
        iVar8 = iVar8 + 1;
        switch(iVar4) {
        case 0:
          pcVar3 = "FW CONN";
          break;
        case 1:
          pcVar3 = "POWER ON";
          break;
        case 2:
          pcVar3 = "FW READY";
          break;
        case 3:
          pcVar3 = "DRIVER PROBED";
          break;
        case 4:
          pcVar3 = "FW TEST MODE";
          break;
        case 5:
          pcVar3 = "PM SUSPEND";
          break;
        case 6:
          pcVar3 = "PM SUSPEND NOIRQ";
          break;
        case 7:
          pcVar3 = "SSR REGISTERED";
          break;
        case 8:
          pcVar3 = "PDR REGISTERED";
          break;
        case 9:
          pcVar3 = "PD RESTART";
          break;
        case 10:
          pcVar3 = "WLAN FW EXISTS";
          break;
        case 0xb:
          pcVar3 = "SHUTDOWN DONE";
          break;
        case 0xc:
          pcVar3 = "HOST TRIGGERED PDR";
          break;
        case 0xd:
          pcVar3 = "FW DOWN";
          break;
        case 0xe:
          pcVar3 = "DRIVER UNLOADING";
          break;
        case 0xf:
          pcVar3 = "FW REJUVENATE";
          break;
        case 0x10:
          pcVar3 = "MODE ON DONE";
          break;
        case 0x11:
          pcVar3 = "BLOCK SHUTDOWN";
          break;
        case 0x12:
          pcVar3 = "PDR TRIGGERED";
          break;
        case 0x13:
          pcVar3 = "IMS_CONNECTED";
          break;
        case 0x14:
          pcVar3 = "DEL SERVER";
          break;
        case 0x15:
          pcVar3 = "COLD BOOT CALIBRATION";
          break;
        case 0x16:
          pcVar3 = "DMS_CONNECTED";
          break;
        case 0x17:
          pcVar3 = "SLATE SSR REGISTERED";
          break;
        case 0x18:
          pcVar3 = "ICNSS SLATE UP";
          break;
        case 0x19:
          pcVar3 = "ICNSS SLATE READY";
          break;
        case 0x1a:
          seq_puts(param_1,"ICNSS LOW POWER");
        default:
          seq_printf(param_1,"UNKNOWN-%d",iVar4);
          goto LAB_00104148;
        }
        seq_puts(param_1,pcVar3);
      }
LAB_00104148:
      iVar4 = iVar4 + 1;
      bVar1 = 1 < uVar5;
      uVar5 = uVar5 >> 1;
    } while (bVar1);
  }
  seq_puts(param_1,&DAT_0011e96f);
  return 0;
}



//------------------------------------------------------------
// icnss_genl_send_msg @ 00104314 size=1088
// signature: undefined icnss_genl_send_msg(void)
// callers: [icnss_wlfw_qdss_data_send_sync, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_genl_send_msg(long param_1,undefined1 param_2,char *param_3,uint param_4)

{
  undefined1 uVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  size_t sVar8;
  long lVar9;
  long lVar10;
  bool bVar11;
  uint uVar12;
  undefined1 *puVar13;
  uint uVar14;
  uint uVar15;
  long local_98;
  uint local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  ipc_log_string(icnss_ipc_log_context,"cnss_genl: type: %u, total_size: %x\n");
  if (param_4 != 0) {
    uVar15 = 0;
    uVar1 = 0;
    local_98 = param_1;
    uVar14 = param_4;
    do {
      uVar12 = uVar14;
      if (0x3bff < uVar14) {
        uVar12 = 0x3c00;
      }
      if (uVar14 < 0x3c01) {
        uVar1 = 1;
      }
      bVar11 = true;
LAB_001043f4:
      local_70 = 0;
      local_80 = 0;
      uStack_78 = 0;
      ipc_log_string(icnss_ipc_log_context,
                     "cnss_genl: type: %u, file_name %s, total_size: %x, seg_id %u, end %u, data_len %u\n"
                     ,param_2,param_3,param_4,uVar15,uVar1,uVar12);
      if (param_3 == (char *)0x0) {
        local_80 = CONCAT17(local_80._7_1_,0x746c7561000000);
        local_80 = CONCAT44(local_80._4_4_,0x61666564);
        puVar13 = (undefined1 *)((long)&local_80 + 7);
      }
      else {
        sVar8 = strlen(param_3);
        if (0xf < sVar8) {
          sVar8 = 0x10;
        }
        memcpy(&local_80,param_3,sVar8);
        puVar13 = (undefined1 *)((long)&local_80 + sVar8);
      }
      *puVar13 = 0;
      sVar8 = strnlen((char *)&local_80,0x11);
      if (0x11 < sVar8) {
LAB_0010473c:
                    /* WARNING: Subroutine does not return */
        fortify_panic("strnlen");
      }
      if (sVar8 == 0x11) {
LAB_00104748:
                    /* WARNING: Subroutine does not return */
        fortify_panic("__fortify_strlen");
      }
      lVar9 = __alloc_skb((uVar12 + 7 & 0x7ffc) + ((uint)sVar8 & 0xfffffffc) + 0x54,0xcc0,0,
                          0xffffffff);
      if (lVar9 == 0) {
        iVar6 = -0xc;
        goto LAB_001043e4;
      }
      lVar10 = genlmsg_put(lVar9,0,0,&icnss_genl_family,0,1);
      if (lVar10 == 0) {
        iVar6 = -0xc;
LAB_00104664:
        _printk("%scnss_genl: Fail to generate genl msg: %d\n",&DAT_0011c04b,iVar6);
        ipc_log_string(icnss_ipc_log_context,"%scnss_genl: Fail to generate genl msg: %d\n",
                       &DAT_0011dab7,iVar6);
        kfree_skb_reason(lVar9,1);
LAB_001043e4:
        msleep(100);
        bVar2 = !bVar11;
        bVar11 = false;
        if (bVar2) {
          _printk("%scnss_genl: fail to send genl data, ret %d\n",&DAT_0011c04b,iVar6);
          ipc_log_string(icnss_ipc_log_context,"%scnss_genl: fail to send genl data, ret %d\n",
                         &DAT_0011dab7,iVar6);
          goto LAB_001046c4;
        }
        goto LAB_001043f4;
      }
      local_84 = CONCAT31(local_84._1_3_,param_2);
      iVar6 = nla_put(lVar9,1,1,&local_84);
      if (iVar6 < 0) goto LAB_00104664;
      sVar8 = strnlen((char *)&local_80,0x11);
      if (0x11 < sVar8) goto LAB_0010473c;
      if (sVar8 == 0x11) goto LAB_00104748;
      iVar6 = nla_put(lVar9,2,(int)sVar8 + 1,&local_80);
      if (iVar6 < 0) goto LAB_00104664;
      local_84 = param_4;
      iVar6 = nla_put(lVar9,3,4,&local_84);
      if (iVar6 < 0) goto LAB_00104664;
      local_84 = uVar15;
      iVar6 = nla_put(lVar9,4,4,&local_84);
      if (iVar6 < 0) goto LAB_00104664;
      local_84 = CONCAT31(local_84._1_3_,uVar1);
      iVar6 = nla_put(lVar9,5,1,&local_84);
      if (iVar6 < 0) goto LAB_00104664;
      local_84 = uVar12;
      iVar6 = nla_put(lVar9,6,4,&local_84);
      if ((iVar6 < 0) || (iVar6 = nla_put(lVar9,7,uVar12,local_98), iVar6 < 0)) goto LAB_00104664;
      *(int *)(lVar10 + -0x14) =
           (*(int *)(lVar9 + 0xd8) + *(int *)(lVar9 + 0xd0)) - ((int)lVar10 + -0x14);
      uVar4 = _thermal_cooling_device_unregister;
      uVar3 = DAT_00124388;
      if (DAT_0012438f == '\0') {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x800,0x1046bc);
        (*pcVar5)();
      }
      *(undefined4 *)(lVar9 + 0x38) = DAT_00124388;
      iVar7 = netlink_broadcast(uVar4,lVar9,0,uVar3,0xcc0);
      iVar6 = iVar7;
      if (-1 < iVar7) {
        iVar6 = 0;
      }
      if (iVar7 < 0) {
        _printk("%scnss_genl: Fail to send genl msg: %d\n",&DAT_0011c04b,iVar6);
        ipc_log_string(icnss_ipc_log_context,"%scnss_genl: Fail to send genl msg: %d\n",
                       &DAT_0011dab7,iVar6);
        if (iVar6 < 0) goto LAB_001043e4;
      }
      uVar15 = uVar15 + 1;
      uVar14 = uVar14 - uVar12;
      local_98 = local_98 + (ulong)uVar12;
    } while (uVar14 != 0);
  }
  iVar6 = 0;
LAB_001046c4:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// icnss_genl_init @ 0010475c size=116
// signature: undefined icnss_genl_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

int icnss_genl_init(void)

{
  int iVar1;
  
  iVar1 = genl_register_family(&icnss_genl_family);
  if (iVar1 != 0) {
    _printk("%scnss_genl: genl_register_family fail: %d\n",&DAT_0011c04b,iVar1);
    ipc_log_string(icnss_ipc_log_context,"%scnss_genl: genl_register_family fail: %d\n",
                   &DAT_0011dab7,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// icnss_genl_exit @ 001047d4 size=36
// signature: undefined icnss_genl_exit(void)
// callers: [icnss_remove]
//------------------------------------------------------------

void icnss_genl_exit(void)

{
  genl_unregister_family(&icnss_genl_family);
  return;
}



//------------------------------------------------------------
// icnss_genl_process_msg @ 001047fc size=8
// signature: undefined icnss_genl_process_msg(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_genl_process_msg(void)

{
  return 0;
}



//------------------------------------------------------------
// icnss_get_fw_cap @ 00104808 size=196
// signature: undefined icnss_get_fw_cap(void)
// callers: []
//------------------------------------------------------------

ulong icnss_get_fw_cap(long param_1,int param_2)

{
  char *pcVar1;
  ulong uVar2;
  ulong uVar3;
  
  if ((*(long *)(param_1 + 0x98) == 0) ||
     (uVar2 = *(ulong *)(*(long *)(param_1 + 0x98) + 0x17b0), uVar2 == 0)) {
    uVar3 = 0;
  }
  else {
    if (param_2 == 0) {
      uVar2 = uVar2 & 0x10;
      uVar3 = uVar2 >> 4;
      pcVar1 = "supported";
      if (uVar2 == 0) {
        pcVar1 = "not supported";
      }
    }
    else {
      _printk("%sicnss2: Invalid FW Capability: 0x%x\n",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid FW Capability: 0x%x\n",&DAT_0011dab7,
                     param_2);
      uVar3 = 0;
      pcVar1 = "not supported";
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2: FW Capability 0x%x is %s\n",param_2,pcVar1);
  }
  return uVar3;
}



//------------------------------------------------------------
// icnss_driver_event_to_str @ 001048d0 size=36
// signature: undefined icnss_driver_event_to_str(void)
// callers: [icnss_stats_show]
//------------------------------------------------------------

char * icnss_driver_event_to_str(uint param_1)

{
  if (param_1 < 0x13) {
    return (&PTR_s_SERVER_ARRIVE_0011aaa0)[(int)param_1];
  }
  return "UNKNOWN";
}



//------------------------------------------------------------
// icnss_soc_wake_event_to_str @ 001048f8 size=36
// signature: undefined icnss_soc_wake_event_to_str(void)
// callers: []
//------------------------------------------------------------

char * icnss_soc_wake_event_to_str(uint param_1)

{
  if (param_1 < 3) {
    return (&PTR_s_SOC_WAKE_REQUEST_0011ab38)[(int)param_1];
  }
  return "UNKNOWN";
}



//------------------------------------------------------------
// icnss_driver_event_post @ 00104920 size=856
// signature: undefined icnss_driver_event_post(void)
// callers: [wlfw_qdss_trace_free_ind_cb, wlfw_qdss_trace_save_ind_cb, icnss_wpss_notifier_nb, icnss_wlfw_process_twt_cfg_ind, fw_crash_indication_handler, wlfw_qdss_trace_req_mem_ind_cb, icnss_update_state_send_modem_shutdown, fw_init_done_ind_cb, icnss_wlfw_m3_dump_upload_segs_req_ind_cb, icnss_idle_restart, wlfw_new_server, icnss_unregister_driver, __icnss_register_driver, icnss_idle_shutdown, icnss_pdr_notifier_cb, icnss_modem_notifier_nb, icnss_ims_process_wfc_call_ind_cb, rejuvenate_ind_cb, fw_ready_ind_cb, rproc_restart_level_notifier, wlfw_del_server]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 icnss_driver_event_post(long param_1,uint param_2,uint param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  
  if (param_1 == 0) {
    uVar12 = 0xffffffed;
  }
  else {
    if (param_2 < 0x13) {
      pcVar11 = (&PTR_s_SERVER_ARRIVE_0011aaa0)[(int)param_2];
    }
    else {
      pcVar11 = "UNKNOWN";
    }
    lVar2 = sp_el0;
    ipc_log_string(icnss_ipc_log_context,
                   "icnss2: Posting event: %s(%d), %s, flags: 0x%x, state: 0x%lx\n",pcVar11,param_2,
                   lVar2 + 0x848,param_3,*(undefined8 *)(param_1 + 0x778));
    if (param_2 < 0x12) {
      if (((((*(uint *)(lVar2 + 0x10) & 0xffff00) == 0) && (*(int *)(lVar2 + 0x10) == 0)) &&
          (uVar9 = daif, (uVar9 & 0x80) == 0)) && (*(int *)(lVar2 + 0x4b4) == 0)) {
        uVar10 = 0xdc0;
      }
      else {
        uVar10 = 0xb20;
      }
      plVar8 = (long *)kmalloc_trace(__raw_spin_unlock_irqrestore,uVar10,0x48);
      if (plVar8 == (long *)0x0) {
        uVar12 = 0xfffffff4;
      }
      else {
        piVar3 = (int *)(param_1 + 0xba0);
        Hint_Prefetch(piVar3,2,0,1);
        do {
          iVar7 = *piVar3;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar3,0x10);
          if (bVar5) {
            *piVar3 = iVar7 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 + 1 == 1) {
          ipc_log_string(icnss_ipc_log_long_context,
                         "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
                         *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
          pm_stay_awake(*(long *)(param_1 + 8) + 0x10);
          *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + 1;
        }
        *(uint *)(plVar8 + 2) = param_2;
        plVar8[8] = param_4;
        *(undefined4 *)(plVar8 + 3) = 0;
        __init_swait_queue_head(plVar8 + 4,"&x->wait",&init_completion___key);
        lVar2 = param_1 + 0x688;
        *(undefined4 *)(plVar8 + 7) = 0xbad;
        *(byte *)((long)plVar8 + 0x14) = (byte)param_3 & 1;
        uVar10 = _raw_spin_lock_irqsave(lVar2);
        puVar13 = *(undefined8 **)(param_1 + 0x670);
        uVar9 = __list_add_valid(plVar8,puVar13,param_1 + 0x668);
        if ((uVar9 & 1) != 0) {
          *(long **)(param_1 + 0x670) = plVar8;
          *plVar8 = param_1 + 0x668;
          plVar8[1] = (long)puVar13;
          *puVar13 = plVar8;
        }
        _raw_spin_unlock_irqrestore(lVar2,uVar10);
        lVar1 = param_1 + (ulong)param_2 * 8;
        uVar10 = *(undefined8 *)(param_1 + 0x740);
        *(int *)(lVar1 + 0x8bc) = *(int *)(lVar1 + 0x8bc) + 1;
        queue_work_on(0x20,uVar10,param_1 + 0x6b0);
        if ((param_3 & 1) == 0) {
          uVar12 = 0;
        }
        else {
          if ((param_3 >> 1 & 1) == 0) {
            iVar7 = wait_for_completion_interruptible();
          }
          else {
            wait_for_completion(plVar8 + 3);
            iVar7 = 0;
          }
          if (param_2 < 0x12) {
            pcVar11 = (&PTR_s_SERVER_ARRIVE_0011a680)[(int)param_2];
          }
          else {
            pcVar11 = "UNKNOWN";
          }
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Completed event: %s(%d), state: 0x%lx, ret: %d/%d\n",pcVar11,
                         param_2,*(undefined8 *)(param_1 + 0x778),iVar7,(int)plVar8[7]);
          uVar10 = _raw_spin_lock_irqsave(lVar2);
          if ((iVar7 == -0x200) && ((int)plVar8[7] == 0xbad)) {
            *(undefined1 *)((long)plVar8 + 0x14) = 0;
            _raw_spin_unlock_irqrestore(lVar2,uVar10);
            uVar12 = 0xfffffffc;
          }
          else {
            _raw_spin_unlock_irqrestore(lVar2,uVar10);
            uVar12 = (undefined4)plVar8[7];
            kfree(plVar8);
          }
        }
        piVar3 = (int *)(param_1 + 0xba0);
        Hint_Prefetch(piVar3,2,0,1);
        do {
          iVar7 = *piVar3 + -1;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar3,0x10);
          if (bVar5) {
            *piVar3 = iVar7;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar7 < 0) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x800,0x104ca4);
          (*pcVar6)();
        }
        if (iVar7 == 0) {
          ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM relax, state: 0x%lx, count: %d\n",
                         *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
          pm_relax(*(long *)(param_1 + 8) + 0x10);
          *(int *)(param_1 + 0xa50) = *(int *)(param_1 + 0xa50) + 1;
        }
      }
    }
    else {
      _printk("%sicnss2: Invalid Event type: %d, can\'t post",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid Event type: %d, can\'t post",
                     &DAT_0011dab7,param_2);
      uVar12 = 0xffffffea;
    }
  }
  return uVar12;
}



//------------------------------------------------------------
// icnss_soc_wake_event_post @ 00104cac size=848
// signature: undefined icnss_soc_wake_event_post(void)
// callers: [icnss_force_wake_release, icnss_force_wake_request]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 icnss_soc_wake_event_post(long param_1,uint param_2,uint param_3,long param_4)

{
  long lVar1;
  long lVar2;
  int *piVar3;
  char *pcVar4;
  char cVar5;
  bool bVar6;
  code *pcVar7;
  int iVar8;
  long *plVar9;
  ulong uVar10;
  undefined8 uVar11;
  char *pcVar12;
  undefined4 uVar13;
  undefined8 *puVar14;
  
  if (param_1 == 0) {
    uVar13 = 0xffffffed;
  }
  else {
    pcVar12 = "UNKNOWN";
    if (param_2 < 3) {
      pcVar12 = (&PTR_s_SOC_WAKE_REQUEST_0011ab38)[(int)param_2];
    }
    lVar2 = sp_el0;
    ipc_log_string(icnss_ipc_soc_wake_context,
                   "icnss2: Posting event: %s(%d), %s, flags: 0x%x, state: 0x%lx\n",pcVar12,param_2,
                   lVar2 + 0x848,param_3,*(undefined8 *)(param_1 + 0x778));
    if (param_2 < 2) {
      if (((*(uint *)(lVar2 + 0x10) & 0xffff00) == 0) && (uVar10 = daif, (uVar10 & 0x80) == 0)) {
        uVar11 = 0xdc0;
      }
      else {
        uVar11 = 0xb20;
      }
      plVar9 = (long *)kmalloc_trace(__raw_spin_unlock_irqrestore,uVar11,0x48);
      if (plVar9 == (long *)0x0) {
        uVar13 = 0xfffffff4;
      }
      else {
        piVar3 = (int *)(param_1 + 0xba0);
        Hint_Prefetch(piVar3,2,0,1);
        do {
          iVar8 = *piVar3;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar3,0x10);
          if (bVar6) {
            *piVar3 = iVar8 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar8 + 1 == 1) {
          ipc_log_string(icnss_ipc_log_long_context,
                         "icnss2: PM stay awake, state: 0x%lx, count: %d\n",
                         *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
          pm_stay_awake(*(long *)(param_1 + 8) + 0x10);
          *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + 1;
        }
        *(uint *)(plVar9 + 2) = param_2;
        plVar9[8] = param_4;
        *(undefined4 *)(plVar9 + 3) = 0;
        __init_swait_queue_head(plVar9 + 4,"&x->wait",&init_completion___key);
        lVar2 = param_1 + 0x68c;
        *(undefined4 *)(plVar9 + 7) = 0xbad;
        *(byte *)((long)plVar9 + 0x14) = (byte)param_3 & 1;
        uVar11 = _raw_spin_lock_irqsave(lVar2);
        puVar14 = *(undefined8 **)(param_1 + 0x680);
        uVar10 = __list_add_valid(plVar9,puVar14,param_1 + 0x678);
        if ((uVar10 & 1) != 0) {
          *(long **)(param_1 + 0x680) = plVar9;
          *plVar9 = param_1 + 0x678;
          plVar9[1] = (long)puVar14;
          *puVar14 = plVar9;
        }
        _raw_spin_unlock_irqrestore(lVar2,uVar11);
        lVar1 = param_1 + (ulong)param_2 * 8;
        uVar11 = *(undefined8 *)(param_1 + 0x748);
        *(int *)(lVar1 + 0x94c) = *(int *)(lVar1 + 0x94c) + 1;
        queue_work_on(0x20,uVar11,param_1 + 0x710);
        if ((param_3 & 1) == 0) {
          uVar13 = 0;
        }
        else {
          if ((param_3 >> 1 & 1) == 0) {
            iVar8 = wait_for_completion_interruptible();
          }
          else {
            wait_for_completion(plVar9 + 3);
            iVar8 = 0;
          }
          pcVar12 = "SOC_WAKE_RELEASE";
          if (param_2 != 1) {
            pcVar12 = "UNKNOWN";
          }
          pcVar4 = "SOC_WAKE_REQUEST";
          if (param_2 != 0) {
            pcVar4 = pcVar12;
          }
          ipc_log_string(icnss_ipc_soc_wake_context,
                         "icnss2: Completed event: %s(%d), state: 0x%lx, ret: %d/%d\n",pcVar4,
                         param_2,*(undefined8 *)(param_1 + 0x778),iVar8,(int)plVar9[7]);
          uVar11 = _raw_spin_lock_irqsave(lVar2);
          if ((iVar8 == -0x200) && ((int)plVar9[7] == 0xbad)) {
            *(undefined1 *)((long)plVar9 + 0x14) = 0;
            _raw_spin_unlock_irqrestore(lVar2,uVar11);
            uVar13 = 0xfffffffc;
          }
          else {
            _raw_spin_unlock_irqrestore(lVar2,uVar11);
            uVar13 = (undefined4)plVar9[7];
            kfree(plVar9);
          }
        }
        piVar3 = (int *)(param_1 + 0xba0);
        Hint_Prefetch(piVar3,2,0,1);
        do {
          iVar8 = *piVar3 + -1;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(piVar3,0x10);
          if (bVar6) {
            *piVar3 = iVar8;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
        if (iVar8 < 0) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x105028);
          (*pcVar7)();
        }
        if (iVar8 == 0) {
          ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM relax, state: 0x%lx, count: %d\n",
                         *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
          pm_relax(*(long *)(param_1 + 8) + 0x10);
          *(int *)(param_1 + 0xa50) = *(int *)(param_1 + 0xa50) + 1;
        }
      }
    }
    else {
      _printk("%sicnss2: Invalid Event type: %d, can\'t post",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid Event type: %d, can\'t post",
                     &DAT_0011dab7,param_2);
      uVar13 = 0xffffffea;
    }
  }
  return uVar13;
}



//------------------------------------------------------------
// icnss_is_fw_ready @ 00105030 size=32
// signature: undefined icnss_is_fw_ready(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_fw_ready(void)

{
  if (penv == 0) {
    return 0;
  }
  return *(ulong *)(penv + 0x778) >> 2 & 1;
}



//------------------------------------------------------------
// icnss_request_bus_bandwidth @ 00105054 size=336
// signature: undefined icnss_request_bus_bandwidth(void)
// callers: []
//------------------------------------------------------------

int icnss_request_bus_bandwidth(long param_1,uint param_2)

{
  undefined4 *puVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 == 0) {
    iVar2 = -0x13;
  }
  else if ((int)param_2 < 0) {
    iVar2 = -0x16;
  }
  else if (*(int *)(lVar3 + 0x6a0) == 0) {
    iVar2 = -0x5f;
  }
  else if (param_2 < *(uint *)(lVar3 + 0x6a8)) {
    plVar4 = (long *)(lVar3 + 0x690);
    do {
      plVar4 = (long *)*plVar4;
      if (plVar4 == (long *)(lVar3 + 0x690)) {
        *(uint *)(lVar3 + 0x6a4) = param_2;
        return 0;
      }
      puVar1 = (undefined4 *)(plVar4[4] + (ulong)param_2 * 8);
      iVar2 = icc_set_bw(plVar4[3],*puVar1,puVar1[1]);
    } while (iVar2 == 0);
    lVar3 = (ulong)param_2 * 8;
    puVar1 = (undefined4 *)(plVar4[4] + lVar3);
    _printk("%sicnss2: Could not set BW Cfg: %d, err = %d ICC Path: %s Val: %d %d\n",&DAT_0011c04b,
            param_2,iVar2,plVar4[2],*puVar1,puVar1[1]);
    puVar1 = (undefined4 *)(plVar4[4] + lVar3);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Could not set BW Cfg: %d, err = %d ICC Path: %s Val: %d %d\n",
                   &DAT_0011dab7,param_2,iVar2,plVar4[2],*puVar1,puVar1[1]);
  }
  else {
    _printk("%sicnss2: Invalid bus bandwidth Type: %d",&DAT_0011c04b,param_2);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid bus bandwidth Type: %d",&DAT_0011dab7,
                   param_2);
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_block_shutdown @ 001051a8 size=132
// signature: undefined icnss_block_shutdown(void)
// callers: [icnss_call_driver_probe, icnss_driver_event_fw_ready_ind, icnss_driver_event_work]
//------------------------------------------------------------

void icnss_block_shutdown(ulong param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  if (penv != 0) {
    if ((param_1 & 1) == 0) {
      puVar1 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffdffff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      complete(penv + 0xc48);
    }
    else {
      puVar1 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x20000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      *(undefined4 *)(penv + 0xc48) = 0;
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_is_fw_down @ 00105248 size=56
// signature: undefined icnss_is_fw_down(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_fw_down(void)

{
  if (penv == 0) {
    return 0;
  }
  if ((((uint)*(undefined8 *)(penv + 0x778) >> 0xd & 1) == 0) &&
     (((uint)*(undefined8 *)(penv + 0x778) >> 9 & 1) == 0)) {
    return *(ulong *)(penv + 0x778) >> 0xf & 1;
  }
  return 1;
}



//------------------------------------------------------------
// icnss_get_device_config @ 00105284 size=28
// signature: undefined icnss_get_device_config(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_get_device_config(void)

{
  if (penv == 0) {
    return 0;
  }
  return *(undefined8 *)(penv + 0x16e8);
}



//------------------------------------------------------------
// icnss_is_rejuvenate @ 001052a4 size=32
// signature: undefined icnss_is_rejuvenate(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_rejuvenate(void)

{
  if (penv == 0) {
    return 0;
  }
  return *(ulong *)(penv + 0x778) >> 0xf & 1;
}



//------------------------------------------------------------
// icnss_is_pdr @ 001052c8 size=32
// signature: undefined icnss_is_pdr(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_pdr(void)

{
  if (penv == 0) {
    return 0;
  }
  return *(ulong *)(penv + 0x778) >> 0x12 & 1;
}



//------------------------------------------------------------
// icnss_is_low_power @ 001052ec size=32
// signature: undefined icnss_is_low_power(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_low_power(void)

{
  if (penv == 0) {
    return 0;
  }
  return *(ulong *)(penv + 0x778) >> 0x1a & 1;
}



//------------------------------------------------------------
// icnss_call_driver_uevent @ 00105310 size=204
// signature: undefined icnss_call_driver_uevent(void)
// callers: [icnss_wpss_notifier_nb, icnss_pdr_notifier_cb, icnss_modem_notifier_nb, rejuvenate_ind_cb]
//------------------------------------------------------------

void icnss_call_driver_uevent(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  if ((*(long *)(param_1 + 0x10) == 0) || (*(long *)(*(long *)(param_1 + 0x10) + 0x120) == 0)) {
    uVar2 = 0;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                   *(undefined8 *)(param_1 + 0x778),param_2);
    local_48 = CONCAT44(local_48._4_4_,param_2);
    pcVar3 = *(code **)(*(long *)(param_1 + 0x10) + 0x120);
    local_40 = param_3;
    if (*(int *)(pcVar3 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1053a0);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(*(long *)(param_1 + 8) + 0x10,&local_48);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// icnss_do_host_ramdump @ 001053e0 size=1144
// signature: undefined icnss_do_host_ramdump(void)
// callers: [icnss_collect_host_dump_info]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 icnss_do_host_ramdump(long param_1,long param_2,ulong param_3)

{
  long ****pppplVar1;
  long ****pppplVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  long lVar7;
  long *****ppppplVar8;
  long *****ppppplVar9;
  char *__s2;
  undefined8 uVar10;
  ulong uVar11;
  long lVar12;
  char *__s1;
  long *****local_5e8;
  long *****local_5e0;
  long ***local_5d8;
  undefined4 local_5d0;
  undefined4 uStack_5cc;
  uint local_5c8 [342];
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  memset(&local_5d8,0,0x568);
  local_5e8 = (long *****)0x0;
  local_5e0 = (long *****)0x0;
  uVar6 = dump_enabled();
  if ((uVar6 & 1) == 0) {
    _printk("%sicnss2: Dump collection is not enabled\n",&DAT_0011e9ea);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Dump collection is not enabled\n",&DAT_0011dab7)
    ;
    uVar5 = 0;
  }
  else {
    lVar7 = kmalloc_trace(_wait_for_completion,0xdc0,0x390);
    if (lVar7 == 0) {
      _printk("%sicnss2: Failed to alloc device mem\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to alloc device mem\n",&DAT_0011dab7);
      uVar5 = 0xfffffff4;
    }
    else {
      *(code **)(lVar7 + 0x328) = icnss_host_ramdump_dev_release;
      device_initialize();
      dev_set_name(lVar7,"wlan_driver");
      iVar4 = device_add(lVar7);
      if (iVar4 == 0) {
        local_5e8 = (long *****)&local_5e8;
        local_5e0 = local_5e8;
        if (param_3 != 0) {
          uVar6 = 0;
          do {
            uVar11 = uVar6 * 0xc + 0x10;
            if ((0x568 < uVar11) || (uVar6 == 0x72)) {
LAB_00105850:
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(1,0x105854);
              (*pcVar3)();
            }
            local_5c8[uVar6 * 3] = 0xffffffff;
            ppppplVar8 = (long *****)kmalloc_trace(___list_add_valid,0xdc0,0x28);
            if (ppppplVar8 == (long *****)0x0) {
              _printk("%sicnss2: Failed to alloc seg entry %d\n",&DAT_0011c04b,uVar6 & 0xffffffff);
              ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to alloc seg entry %d\n",
                             &DAT_0011dab7,uVar6 & 0xffffffff);
            }
            else {
              lVar12 = 0;
              __s1 = (char *)(param_2 + uVar6 * 0x30);
              pppplVar1 = *(long *****)(__s1 + 0x20);
              pppplVar2 = *(long *****)(__s1 + 0x28);
              __s1[0x1f] = '\0';
              ppppplVar8[2] = pppplVar1;
              ppppplVar8[3] = pppplVar1;
              ppppplVar8[4] = pppplVar2;
              do {
                __s2 = "unknown";
                if ((uint)lVar12 < 0x72) {
                  __s2 = (&PTR_s_wlan_logs_0011a710)[lVar12];
                }
                iVar4 = strncmp(__s1,__s2,0x1f);
                ppppplVar9 = local_5e0;
                if (iVar4 == 0) {
                  if ((0x568 < uVar11) || (uVar6 == 0x72)) goto LAB_00105850;
                  local_5c8[uVar6 * 3] = (uint)lVar12;
                  break;
                }
                lVar12 = lVar12 + 1;
              } while ((int)lVar12 != 0x72);
              if ((uVar6 * 0xc - 0x555 < 0xfffffffffffffa97) ||
                 (local_5c8[uVar6 * 3 + 1] = (int)uVar6 + 1,
                 uVar6 * 0xc - 0x551 < 0xfffffffffffffa97)) goto LAB_00105850;
              local_5c8[uVar6 * 3 + 2] = local_5c8[uVar6 * 3 + 2] + 1;
              uVar11 = __list_add_valid(ppppplVar8,local_5e0,&local_5e8);
              if ((uVar11 & 1) != 0) {
                *ppppplVar8 = (long ****)&local_5e8;
                ppppplVar8[1] = (long ****)ppppplVar9;
                local_5e0 = ppppplVar8;
                *ppppplVar9 = (long ****)ppppplVar8;
              }
            }
            uVar6 = (ulong)((int)uVar6 + 1);
          } while (uVar6 < param_3);
        }
        ppppplVar9 = (long *****)kmalloc_trace(___list_add_valid,0xdc0,0x28);
        ppppplVar8 = local_5e8;
        if (ppppplVar9 == (long *****)0x0) {
          _printk("%sicnss2: %s: Failed to allocate mem for host dump seg\n",&DAT_0011c04b,
                  "icnss_do_host_ramdump");
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: %s: Failed to allocate mem for host dump seg\n",&DAT_0011dab7,
                         "icnss_do_host_ramdump");
          uVar5 = 0;
        }
        else {
          uVar10 = *(undefined8 *)(param_1 + 0x108);
          local_5d8 = (long ***)0x574c414e;
          ppppplVar9[2] = &local_5d8;
          ppppplVar9[3] = &local_5d8;
          local_5d0 = (undefined4)uVar10;
          uStack_5cc = (undefined4)param_3;
          ppppplVar9[4] = (long ****)0x568;
          uVar6 = __list_add_valid(ppppplVar9,&local_5e8,local_5e8);
          if ((uVar6 & 1) != 0) {
            ppppplVar8[1] = (long ****)ppppplVar9;
            *ppppplVar9 = (long ****)ppppplVar8;
            ppppplVar9[1] = (long ****)&local_5e8;
            local_5e8 = ppppplVar9;
          }
          uVar5 = qcom_elf_dump(&local_5e8,lVar7,2);
        }
        ppppplVar8 = local_5e8;
        while (local_5e8 = ppppplVar8, (long ******)ppppplVar8 != &local_5e8) {
          uVar6 = __list_del_entry_valid(ppppplVar8);
          if ((uVar6 & 1) != 0) {
            pppplVar1 = *ppppplVar8;
            pppplVar2 = ppppplVar8[1];
            pppplVar1[1] = (long ***)pppplVar2;
            *pppplVar2 = (long ***)pppplVar1;
          }
          *ppppplVar8 = (long ****)0xdead000000000100;
          ppppplVar8[1] = (long ****)0xdead000000000122;
          kfree(ppppplVar8);
          ppppplVar8 = local_5e8;
        }
        device_del(lVar7);
      }
      else {
        _printk("%sicnss2: Failed to add new device\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to add new device\n",&DAT_0011dab7);
        uVar5 = 0;
      }
      put_device(lVar7);
      ipc_log_string(icnss_ipc_log_context,"icnss2: host ramdump result %d\n",uVar5);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// icnss_host_ramdump_dev_release @ 0010585c size=64
// signature: undefined icnss_host_ramdump_dev_release(void)
// callers: []
//------------------------------------------------------------

void icnss_host_ramdump_dev_release(undefined8 param_1)

{
  ipc_log_string(icnss_ipc_log_context,"icnss2: free host ramdump device\n");
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// icnss_collect_host_dump_info @ 001058a0 size=448
// signature: undefined icnss_collect_host_dump_info(void)
// callers: [icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_collect_host_dump_info(long param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  ulong uVar4;
  code *pcVar5;
  char *pcVar6;
  long lVar7;
  ulong uVar8;
  ulong local_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  lVar7 = *(long *)(param_1 + 8);
  local_70 = 0;
  lVar2 = kmalloc_trace(_icc_set_bw,0xcc0,0x1560);
  if (lVar2 == 0) {
    pcVar6 = "%sicnss2: ssr_entry malloc failed";
    puVar3 = &DAT_0011c04b;
  }
  else {
    if ((*(long *)(param_1 + 0x10) != 0) &&
       (pcVar5 = *(code **)(*(long *)(param_1 + 0x10) + 0x138), pcVar5 != (code *)0x0)) {
      if (*(int *)(pcVar5 + -4) != -0xd3d937f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10592c);
        (*pcVar5)();
      }
      iVar1 = (*pcVar5)(lVar7 + 0x10,lVar2,&local_70);
      if (iVar1 == 0) {
        if (local_70 == 0) {
          uVar4 = 0;
        }
        else {
          uVar8 = 0;
          do {
            if ((uVar8 * 0x30 - 0x1541 < 0xffffffffffffea9f) ||
               (uVar8 * 0x30 - 0x1539 < 0xffffffffffffea9f)) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x105a5c);
              (*pcVar5)();
            }
            lVar7 = lVar2 + uVar8 * 0x30;
            ipc_log_string(icnss_ipc_log_long_context,
                           "icnss2: Idx:%d, ptr: %p, name: %s, size: %zu\n",uVar8 & 0xffffffff,
                           *(undefined8 *)(lVar7 + 0x20),lVar2 + uVar8 * 0x30,
                           *(undefined8 *)(lVar7 + 0x28));
            uVar8 = (ulong)((int)uVar8 + 1);
            uVar4 = local_70;
          } while (uVar8 < local_70);
        }
        icnss_do_host_ramdump(param_1,lVar2,uVar4);
        kfree(lVar2);
        goto LAB_00105a20;
      }
      kfree(lVar2);
    }
    kfree(lVar2);
    pcVar6 = "%sicnss2: Host SSR elf dump collection feature disabled\n";
    puVar3 = &DAT_0011e9ea;
  }
  _printk(pcVar6,puVar3);
  ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7);
LAB_00105a20:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// icnss_free_qdss_mem @ 00105a64 size=224
// signature: undefined icnss_free_qdss_mem(void)
// callers: [wlfw_qdss_trace_req_mem_ind_cb]
//------------------------------------------------------------

void icnss_free_qdss_mem(long param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  
  uVar1 = *(uint *)(param_1 + 0xd08);
  if (uVar1 != 0) {
    lVar3 = *(long *)(param_1 + 8);
    uVar2 = 0;
    do {
      plVar4 = (long *)(param_1 + 0xd10 + (long)(int)uVar2 * 0x28);
      if ((plVar4[1] != 0) && (*plVar4 != 0)) {
        lVar5 = param_1 + 0xd10 + (long)(int)uVar2 * 0x28;
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
                       lVar5 + 0x10,*plVar4,*(undefined4 *)(lVar5 + 0x1c));
        dma_free_attrs(lVar3 + 0x10,*plVar4,plVar4[1],*(undefined8 *)(lVar5 + 0x10),0);
        *plVar4 = 0;
        plVar4[1] = 0;
        plVar4[2] = 0;
        uVar1 = *(uint *)(param_1 + 0xd08);
        *(undefined4 *)(lVar5 + 0x1c) = 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  *(undefined4 *)(param_1 + 0xd08) = 0;
  return;
}



//------------------------------------------------------------
// icnss_thermal_cdev_register @ 00105b48 size=508
// signature: undefined icnss_thermal_cdev_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong icnss_thermal_cdev_register(long param_1,long param_2,int param_3)

{
  long *plVar1;
  long *plVar2;
  undefined8 *puVar3;
  long lVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  char local_60 [24];
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + 0x98);
  local_60[0x10] = '\0';
  local_60[0x11] = '\0';
  local_60[0x12] = '\0';
  local_60[0x13] = '\0';
  local_60[0] = '\0';
  local_60[1] = '\0';
  local_60[2] = '\0';
  local_60[3] = '\0';
  local_60[4] = '\0';
  local_60[5] = '\0';
  local_60[6] = '\0';
  local_60[7] = '\0';
  local_60[8] = '\0';
  local_60[9] = '\0';
  local_60[10] = '\0';
  local_60[0xb] = '\0';
  local_60[0xc] = '\0';
  local_60[0xd] = '\0';
  local_60[0xe] = '\0';
  local_60[0xf] = '\0';
  plVar2 = (long *)kmalloc_trace(___list_add_valid,0xdc0,0x38);
  if (plVar2 == (long *)0x0) {
    uVar5 = 0xfffffff4;
  }
  else {
    *(int *)(plVar2 + 2) = param_3;
    plVar2[4] = param_2;
    snprintf(local_60,0x14,"qcom,icnss_cdev%d",param_3);
    puVar3 = (undefined8 *)of_find_node_by_name(0,local_60);
    if (puVar3 == (undefined8 *)0x0) {
      _printk("%sicnss2: Failed to get cooling device node\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get cooling device node\n",
                     &DAT_0011dab7);
      uVar5 = 0xffffffea;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2: tcdev node->name=%s\n",*puVar3);
      lVar4 = of_find_property(puVar3,"#cooling-cells",0);
      if (lVar4 == 0) {
        ipc_log_string(icnss_ipc_log_context,"icnss2: Cooling device registration not supported");
        uVar5 = 0xffffffa1;
      }
      else {
        uVar5 = thermal_of_cooling_device_register(puVar3,local_60,plVar2,&icnss_cooling_ops);
        plVar2[6] = uVar5;
        if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
          _printk("%sicnss2: Cooling device register failed: %d, for cdev id %d\n",&DAT_0011c04b,
                  uVar5 & 0xffffffff,(int)plVar2[2]);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: Cooling device register failed: %d, for cdev id %d\n",
                         &DAT_0011dab7,uVar5 & 0xffffffff,(int)plVar2[2]);
        }
        else {
          ipc_log_string(icnss_ipc_log_context,"icnss2: Cooling device registered for cdev id %d",
                         (int)plVar2[2]);
          plVar1 = (long *)(lVar7 + 0x1578);
          lVar7 = *(long *)(lVar7 + 0x1578);
          uVar6 = __list_add_valid(plVar2,plVar1,lVar7);
          uVar5 = 0;
          if ((uVar6 & 1) != 0) {
            *(long **)(lVar7 + 8) = plVar2;
            *plVar2 = lVar7;
            plVar2[1] = (long)plVar1;
            *plVar1 = (long)plVar2;
          }
        }
      }
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_thermal_cdev_unregister @ 00105d48 size=140
// signature: undefined icnss_thermal_cdev_unregister(void)
// callers: []
//------------------------------------------------------------

void icnss_thermal_cdev_unregister(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar1 = (long *)(*(long *)(param_1 + 0x98) + 0x1578);
  plVar5 = *(long **)(*(long *)(param_1 + 0x98) + 0x1578);
  while (plVar5 != plVar1) {
    thermal_cooling_device_unregister(plVar5[6]);
    uVar4 = __list_del_entry_valid(plVar5);
    if ((uVar4 & 1) != 0) {
      lVar2 = *plVar5;
      plVar3 = (long *)plVar5[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar5 = -0x2152ffffffffff00;
    plVar5[1] = -0x2152fffffffffede;
    kfree(plVar5);
    plVar5 = (long *)*plVar1;
  }
  return;
}



//------------------------------------------------------------
// icnss_get_curr_therm_cdev_state @ 00105dd8 size=192
// signature: undefined icnss_get_curr_therm_cdev_state(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_get_curr_therm_cdev_state(long param_1,undefined8 *param_2,int param_3)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x1588;
  mutex_lock(lVar1);
  plVar2 = (long *)(lVar3 + 0x1578);
  plVar4 = plVar2;
  do {
    plVar4 = (long *)*plVar4;
    if (plVar4 == plVar2) {
      mutex_unlock(lVar1);
      ipc_log_string(icnss_ipc_log_context,"icnss2: Cooling device ID not found: %d",param_3);
      return 0xffffffea;
    }
  } while (*(int *)(plVar4 + 2) != param_3);
  *param_2 = plVar4[3];
  mutex_unlock(lVar1);
  ipc_log_string(icnss_ipc_log_context,"icnss2: Cooling device current state: %ld, for cdev id %d",
                 plVar4[3],param_3);
  return 0;
}



//------------------------------------------------------------
// icnss_qmi_send @ 00105e9c size=100
// signature: undefined icnss_qmi_send(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_qmi_send(void)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 in_x4;
  undefined8 in_x5;
  
  lVar1 = penv;
  if (penv == 0) {
    uVar2 = 0xffffffed;
  }
  else if ((*(ulong *)(penv + 0x778) & 1) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    *(undefined8 *)(penv + 0x1538) = in_x5;
    *(undefined8 *)(lVar1 + 0x1530) = in_x4;
    uVar2 = icnss_wlfw_get_info_send_sync(lVar1);
    if ((int)uVar2 != 0) {
      *(undefined8 *)(lVar1 + 0x1530) = 0;
      *(undefined8 *)(lVar1 + 0x1538) = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_register_driver_async_data_cb @ 00105f04 size=48
// signature: undefined icnss_register_driver_async_data_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_register_driver_async_data_cb(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (lVar1 == 0) {
    return 0xffffffed;
  }
  if ((*(ulong *)(lVar1 + 0x778) & 1) == 0) {
    return 0xffffffea;
  }
  *(undefined8 *)(lVar1 + 0x1548) = param_3;
  *(undefined8 *)(lVar1 + 0x1540) = param_2;
  return 0;
}



//------------------------------------------------------------
// __icnss_register_driver @ 00105f38 size=376
// signature: undefined __icnss_register_driver(void)
// callers: []
//------------------------------------------------------------

int __icnss_register_driver(long param_1)

{
  ushort uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  ushort *puVar6;
  
  lVar2 = penv;
  if ((penv == 0) || (*(long *)(penv + 8) == 0)) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: icnss2 is not ready for register driver\n");
    iVar4 = -0xb;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2: Registering driver, state: 0x%lx\n",
                   *(undefined8 *)(penv + 0x778));
    if (*(long *)(lVar2 + 0x10) == 0) {
      lVar5 = *(long *)(param_1 + 8);
      if (lVar5 == 0) {
        _printk("%sicnss2: WLAN driver devinfo is null, Reject wlan driver loading",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: WLAN driver devinfo is null, Reject wlan driver loading",
                       &DAT_0011dab7);
        iVar4 = -0x16;
      }
      else {
        uVar1 = *(ushort *)(lVar5 + 10);
        if (uVar1 != 0) {
          puVar6 = (ushort *)(lVar5 + 0x16);
          do {
            if (*(ulong *)(lVar2 + 0x108) == (ulong)uVar1) {
              if ((*(long *)(param_1 + 200) == 0) || (*(long *)(param_1 + 0xd0) == 0)) {
                return -0x16;
              }
              iVar3 = icnss_driver_event_post(lVar2,3,0,param_1);
              iVar4 = 0;
              if (iVar3 != -4) {
                iVar4 = iVar3;
              }
              return iVar4;
            }
            uVar1 = *puVar6;
            puVar6 = puVar6 + 6;
          } while (uVar1 != 0);
        }
        _printk("%sicnss2: WLAN driver dev name is %s, not supported by platform driver\n",
                &DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: WLAN driver dev name is %s, not supported by platform driver\n",
                       &DAT_0011dab7,*(undefined8 *)(param_1 + 8));
        iVar4 = -0x13;
      }
    }
    else {
      _printk("%sicnss2: Driver already registered\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Driver already registered\n",&DAT_0011dab7);
      iVar4 = -0x11;
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// icnss_unregister_driver @ 001060b4 size=164
// signature: undefined icnss_unregister_driver(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_unregister_driver(void)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = penv;
  if ((penv == 0) || (*(long *)(penv + 8) == 0)) {
    uVar2 = 0xffffffed;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2: Unregistering driver, state: 0x%lx\n",
                   *(undefined8 *)(penv + 0x778));
    if (*(long *)(lVar1 + 0x10) == 0) {
      _printk("%sicnss2: Driver not registered\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Driver not registered\n",&DAT_0011dab7);
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = icnss_driver_event_post(lVar1,4,3,0);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_get_user_msi_assignment @ 0010615c size=416
// signature: undefined icnss_get_user_msi_assignment(void)
// callers: []
//------------------------------------------------------------

undefined8
icnss_get_user_msi_assignment
          (long param_1,char *param_2,undefined4 *param_3,int *param_4,undefined4 *param_5)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  
  lVar6 = *(long *)(param_1 + 0x98);
  if (lVar6 == 0) {
    uVar5 = 0xffffffed;
  }
  else {
    lVar7 = *(long *)(lVar6 + 0x110);
    if (lVar7 == 0) {
      _printk("%sicnss2: MSI is not supported.\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: MSI is not supported.\n",&DAT_0011dab7);
    }
    else {
      uVar2 = *(uint *)(lVar7 + 4);
      if (0 < (int)uVar2) {
        uVar8 = 0;
        lVar10 = *(long *)(lVar7 + 8);
        lVar9 = 0xc;
        do {
          lVar1 = lVar10 + lVar9;
          iVar4 = strcmp(param_2,*(char **)(lVar1 + -0xc));
          if (iVar4 == 0) {
            *param_3 = *(undefined4 *)(lVar1 + -4);
            *param_4 = *(int *)(lVar6 + 0x118) + *(int *)(*(long *)(lVar7 + 8) + lVar9);
            *param_5 = *(undefined4 *)(*(long *)(lVar7 + 8) + lVar9);
            if (1 < uVar8) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(1,0x1062fc);
              (*pcVar3)();
            }
            iVar4 = *(int *)((long)&print_optimize + uVar8 * 4);
            *(int *)((long)&print_optimize + uVar8 * 4) = iVar4 + 1;
            if (iVar4 == 0) {
              ipc_log_string(icnss_ipc_log_context,
                             "icnss2: Assign MSI to user: %s, num_vectors: %d, user_base_data: %u, base_vector: %u\n"
                             ,param_2,*param_3,*param_4);
              return 0;
            }
            return 0;
          }
          uVar8 = uVar8 + 1;
          lVar9 = lVar9 + 0x10;
        } while (uVar2 != uVar8);
      }
      _printk("%sicnss2: Failed to find MSI assignment for %s!\n",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to find MSI assignment for %s!\n",
                     &DAT_0011dab7,param_2);
    }
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// icnss_get_msi_irq @ 00106300 size=88
// signature: undefined icnss_get_msi_irq(void)
// callers: []
//------------------------------------------------------------

undefined4 icnss_get_msi_irq(long param_1,uint param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  
  if (0x1f < param_2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x106358);
    (*pcVar2)();
  }
  uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x98) + (ulong)param_2 * 4 + 0x164);
  ipc_log_string(icnss_ipc_log_context,"icnss2: Get IRQ number %d for vector index %d\n",uVar1,
                 param_2);
  return uVar1;
}



//------------------------------------------------------------
// icnss_get_msi_address @ 0010635c size=24
// signature: undefined icnss_get_msi_address(void)
// callers: []
//------------------------------------------------------------

void icnss_get_msi_address(long param_1,undefined4 *param_2,undefined4 *param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  *param_2 = (int)*(undefined8 *)(lVar1 + 0x760);
  *param_3 = *(undefined4 *)(lVar1 + 0x764);
  return;
}



//------------------------------------------------------------
// icnss_ce_request_irq @ 00106378 size=488
// signature: undefined icnss_ce_request_irq(void)
// callers: []
//------------------------------------------------------------

int icnss_ce_request_irq
              (long param_1,uint param_2,long param_3,undefined8 param_4,undefined8 param_5,
              undefined8 param_6)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  long *plVar5;
  int *piVar6;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if ((lVar3 == 0) || (*(long *)(lVar3 + 8) == 0)) {
    iVar4 = -0x13;
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: CE request IRQ: %d, state: 0x%lx\n",param_2,
                   *(undefined8 *)(lVar3 + 0x778));
    if (param_2 < 0xc) {
      lVar1 = lVar3 + (ulong)param_2 * 0x10;
      plVar5 = (long *)(lVar1 + 0x20);
      iVar4 = *(int *)(lVar3 + (ulong)param_2 * 4 + 0x134);
      if ((*plVar5 == 0) && (piVar6 = (int *)(lVar1 + 0x18), *piVar6 == 0)) {
        iVar2 = request_threaded_irq(iVar4,param_3,0,param_4,param_5,param_6);
        if (iVar2 == 0) {
          *piVar6 = iVar4;
          *plVar5 = param_3;
          ipc_log_string(icnss_ipc_log_long_context,"icnss2: IRQ requested: %d, ce_id: %d\n",iVar4,
                         param_2);
          lVar3 = penv + (ulong)param_2 * 0x10;
          *(int *)(lVar3 + 0x95c) = *(int *)(lVar3 + 0x95c) + 1;
          return 0;
        }
        _printk("%sicnss2: IRQ request failed: %d, ce_id: %d, ret: %d\n",&DAT_0011c04b,iVar4,param_2
                ,iVar2);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: IRQ request failed: %d, ce_id: %d, ret: %d\n",&DAT_0011dab7,iVar4,
                       param_2,iVar2);
        return iVar2;
      }
      _printk("%sicnss2: IRQ already requested: %d, ce_id: %d\n",&DAT_0011c04b,iVar4,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: IRQ already requested: %d, ce_id: %d\n",
                     &DAT_0011dab7,iVar4,param_2);
      iVar4 = -0x11;
    }
    else {
      _printk("%sicnss2: Invalid CE ID, ce_id: %d\n",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid CE ID, ce_id: %d\n",&DAT_0011dab7,
                     param_2);
      iVar4 = -0x16;
    }
  }
  return iVar4;
}



//------------------------------------------------------------
// icnss_ce_free_irq @ 00106564 size=352
// signature: undefined icnss_ce_free_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_ce_free_irq(long param_1,uint param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  long *plVar4;
  int *piVar5;
  
  if (penv == 0) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = 0xffffffed;
    if ((param_1 != 0) && (*(long *)(penv + 8) != 0)) {
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: CE free IRQ: %d, state: 0x%lx\n",param_2,
                     *(undefined8 *)(penv + 0x778));
      if (param_2 < 0xc) {
        lVar1 = penv + (ulong)param_2 * 0x10;
        plVar4 = (long *)(lVar1 + 0x20);
        uVar2 = *(undefined4 *)(penv + (ulong)param_2 * 4 + 0x134);
        if ((*plVar4 != 0) && (piVar5 = (int *)(lVar1 + 0x18), *piVar5 != 0)) {
          free_irq(uVar2,param_3);
          *piVar5 = 0;
          *plVar4 = 0;
          lVar1 = penv + (ulong)param_2 * 0x10;
          *(int *)(lVar1 + 0x960) = *(int *)(lVar1 + 0x960) + 1;
          return 0;
        }
        _printk("%sicnss2: IRQ not requested: %d, ce_id: %d\n",&DAT_0011c04b,uVar2,param_2);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: IRQ not requested: %d, ce_id: %d\n",
                       &DAT_0011dab7,uVar2,param_2);
        uVar3 = 0xffffffef;
      }
      else {
        _printk("%sicnss2: Invalid CE ID to free, ce_id: %d\n",&DAT_0011c04b,param_2);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid CE ID to free, ce_id: %d\n",
                       &DAT_0011dab7,param_2);
        uVar3 = 0xffffffea;
      }
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// icnss_enable_irq @ 001066c8 size=240
// signature: undefined icnss_enable_irq(void)
// callers: []
//------------------------------------------------------------

void icnss_enable_irq(long param_1,uint param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  if (((penv == 0) || (param_1 == 0)) || (*(long *)(penv + 8) == 0)) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: Enable IRQ: ce_id: %d, state: 0x%lx\n",
                   param_2,*(undefined8 *)(penv + 0x778));
    if (param_2 < 0xc) {
      lVar1 = penv + (ulong)param_2 * 0x10;
      uVar2 = *(undefined4 *)(penv + (ulong)param_2 * 4 + 0x134);
      *(int *)(lVar1 + 0x964) = *(int *)(lVar1 + 0x964) + 1;
      enable_irq(uVar2);
    }
    else {
      _printk("%sicnss2: Invalid CE ID to enable IRQ, ce_id: %d\n",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid CE ID to enable IRQ, ce_id: %d\n",
                     &DAT_0011dab7,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_disable_irq @ 001067bc size=244
// signature: undefined icnss_disable_irq(void)
// callers: []
//------------------------------------------------------------

void icnss_disable_irq(long param_1,uint param_2)

{
  long lVar1;
  
  if (((penv == 0) || (param_1 == 0)) || (*(long *)(penv + 8) == 0)) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: Disable IRQ: ce_id: %d, state: 0x%lx\n",
                   param_2,*(undefined8 *)(penv + 0x778));
    if (param_2 < 0xc) {
      disable_irq(*(undefined4 *)(penv + (ulong)param_2 * 4 + 0x134));
      lVar1 = penv + (ulong)param_2 * 0x10;
      *(int *)(lVar1 + 0x968) = *(int *)(lVar1 + 0x968) + 1;
    }
    else {
      _printk("%sicnss2: Invalid CE ID to disable IRQ, ce_id: %d\n",&DAT_0011c04b,param_2);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid CE ID to disable IRQ, ce_id: %d\n",
                     &DAT_0011dab7,param_2);
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_get_soc_info @ 001068b4 size=396
// signature: undefined icnss_get_soc_info(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_get_soc_info(long param_1,undefined8 *param_2)

{
  size_t sVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  if (lVar5 == 0) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
    return 0xffffffea;
  }
  *param_2 = *(undefined8 *)(lVar5 + 0x1f0);
  param_2[1] = *(undefined8 *)(lVar5 + 0x1e8);
  *(undefined4 *)(param_2 + 2) = *(undefined4 *)(lVar5 + 0x780);
  *(undefined4 *)((long)param_2 + 0x14) = *(undefined4 *)(lVar5 + 0x784);
  *(undefined4 *)(param_2 + 3) = *(undefined4 *)(lVar5 + 0x788);
  *(undefined4 *)((long)param_2 + 0x1c) = *(undefined4 *)(lVar5 + 0x78c);
  *(undefined4 *)(param_2 + 4) = *(undefined4 *)(lVar5 + 0x790);
  *(undefined1 *)(lVar5 + 0x7b4) = 0;
  sVar1 = strnlen((char *)(lVar5 + 0x794),0x21);
  if (0x21 < sVar1) {
LAB_00106a28:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar1 != 0x21) {
    memcpy((void *)((long)param_2 + 0x24),(char *)(lVar5 + 0x794),sVar1);
    *(undefined1 *)((long)param_2 + 0x24 + sVar1) = 0;
    sVar1 = strnlen((char *)(lVar5 + 0x7b8),0x81);
    if (0x81 < sVar1) goto LAB_00106a28;
    if (sVar1 != 0x81) {
      memcpy((void *)((long)param_2 + 0x45),(char *)(lVar5 + 0x7b8),sVar1);
      *(undefined1 *)((long)param_2 + 0x45 + sVar1) = 0;
      *(undefined4 *)(param_2 + 0x19) = *(undefined4 *)(lVar5 + 0x1794);
      *(undefined4 *)((long)param_2 + 0xcc) = *(undefined4 *)(lVar5 + 0x1798);
      *(undefined4 *)(param_2 + 0x1a) = *(undefined4 *)(lVar5 + 0x179c);
      uVar2 = *(undefined8 *)(lVar5 + 0x8a8);
      uVar3 = *(undefined8 *)(lVar5 + 0x898);
      uVar4 = *(undefined8 *)(lVar5 + 0x890);
      param_2[0x21] = *(undefined8 *)(lVar5 + 0x8a0);
      param_2[0x22] = uVar2;
      param_2[0x1f] = uVar4;
      param_2[0x20] = uVar3;
      uVar2 = *(undefined8 *)(lVar5 + 0x888);
      uVar3 = *(undefined8 *)(lVar5 + 0x878);
      uVar4 = *(undefined8 *)(lVar5 + 0x870);
      param_2[0x1d] = *(undefined8 *)(lVar5 + 0x880);
      param_2[0x1e] = uVar2;
      param_2[0x1b] = uVar4;
      param_2[0x1c] = uVar3;
      return 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  fortify_panic("__fortify_strlen");
}



//------------------------------------------------------------
// icnss_get_mhi_state @ 00106a44 size=116
// signature: undefined icnss_get_mhi_state(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_get_mhi_state(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
    uVar1 = 0xffffffea;
  }
  else if (*(long *)(*(long *)(param_1 + 0x98) + 0x208) == 0) {
    uVar1 = 0xfffffff4;
  }
  else {
    uVar1 = readl();
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_set_fw_log_mode @ 00106abc size=320
// signature: undefined icnss_set_fw_log_mode(void)
// callers: []
//------------------------------------------------------------

int icnss_set_fw_log_mode(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == 0) {
    iVar2 = -0x13;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x98);
    if (lVar3 == 0) {
      _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",
                     &DAT_0011dab7);
      iVar2 = -0x16;
    }
    else if ((((uint)*(undefined8 *)(penv + 0x778) >> 0xd & 1) == 0) &&
            (((uint)*(undefined8 *)(penv + 0x778) >> 2 & 1) != 0)) {
      uVar1 = param_2 & 0xff;
      ipc_log_string(icnss_ipc_log_context,"icnss2: FW log mode: %u\n",uVar1);
      iVar2 = wlfw_ini_send_sync_msg(lVar3,param_2);
      if (iVar2 != 0) {
        _printk("%sicnss2: Fail to send ini, ret = %d, fw_log_mode: %u\n",&DAT_0011c04b,iVar2,uVar1)
        ;
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Fail to send ini, ret = %d, fw_log_mode: %u\n",&DAT_0011dab7,iVar2
                       ,uVar1);
      }
    }
    else {
      _printk("%sicnss2: FW down, ignoring fw_log_mode state: 0x%lx\n",&DAT_0011c04b,
              *(undefined8 *)(lVar3 + 0x778));
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: FW down, ignoring fw_log_mode state: 0x%lx\n",
                     &DAT_0011dab7,*(undefined8 *)(lVar3 + 0x778));
      iVar2 = -0x16;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_force_wake_request @ 00106c00 size=292
// signature: undefined icnss_force_wake_request(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_force_wake_request(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined *puVar7;
  int iVar8;
  long lVar9;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffed;
  }
  else {
    lVar9 = *(long *)(param_1 + 0x98);
    if (lVar9 == 0) {
      _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
      puVar7 = &DAT_0011dab7;
      pcVar6 = "%sicnss2: Platform driver not initialized\n";
      uVar5 = icnss_ipc_log_context;
    }
    else {
      puVar7 = *(undefined **)(lVar9 + 0x778);
      if ((((uint)puVar7 >> 0xd & 1) == 0) &&
         (puVar7 = *(undefined **)(lVar9 + 0x778), ((uint)puVar7 >> 2 & 1) != 0)) {
        piVar1 = (int *)(lVar9 + 0x1550);
        iVar8 = *(int *)(lVar9 + 0x1550);
        do {
          if (iVar8 == 0) {
            ipc_log_string(icnss_ipc_soc_wake_context,"icnss2: Calling SOC Wake request");
            icnss_soc_wake_event_post(lVar9,0,0,0);
            return 0;
          }
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar8) goto LAB_00106c7c;
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar4) {
              *piVar1 = iVar8 + 1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00106c7c:
          bVar4 = iVar8 == iVar2;
          iVar8 = iVar2;
          if (bVar4) {
            ipc_log_string(icnss_ipc_soc_wake_context,"icnss2: SOC already awake, Ref count: %d",
                           *piVar1);
            return 0;
          }
        } while( true );
      }
      pcVar6 = "icnss2: FW down, ignoring SOC Wake request state: 0x%lx\n";
      uVar5 = icnss_ipc_soc_wake_context;
    }
    ipc_log_string(uVar5,pcVar6,puVar7);
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// icnss_force_wake_release @ 00106d3c size=304
// signature: undefined icnss_force_wake_release(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_force_wake_release(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  undefined8 uVar6;
  char *pcVar7;
  undefined *puVar8;
  int iVar9;
  long lVar10;
  
  if (param_1 == 0) {
    uVar6 = 0xffffffed;
  }
  else {
    lVar10 = *(long *)(param_1 + 0x98);
    if (lVar10 == 0) {
      _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
      puVar8 = &DAT_0011dab7;
      pcVar7 = "%sicnss2: Platform driver not initialized\n";
      uVar6 = icnss_ipc_log_context;
    }
    else {
      puVar8 = *(undefined **)(lVar10 + 0x778);
      if ((((uint)puVar8 >> 0xd & 1) == 0) &&
         (puVar8 = *(undefined **)(lVar10 + 0x778), ((uint)puVar8 >> 2 & 1) != 0)) {
        ipc_log_string(icnss_ipc_soc_wake_context,"icnss2: Calling SOC Wake response");
        if (*(int *)(lVar10 + 0x1550) == 0) {
LAB_00106e58:
          icnss_soc_wake_event_post(lVar10,1,0,0);
        }
        else {
          piVar1 = (int *)(lVar10 + 0x1550);
          iVar9 = *piVar1;
          do {
            iVar4 = iVar9 + -1;
            if (iVar4 < 1) {
              if (iVar4 == 0) goto LAB_00106e58;
              break;
            }
            Hint_Prefetch(piVar1,2,0,1);
            do {
              iVar2 = *piVar1;
              if (iVar2 != iVar9) goto LAB_00106dd8;
              cVar3 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
              if (bVar5) {
                *piVar1 = iVar4;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            DataMemoryBarrier(2,3);
LAB_00106dd8:
            bVar5 = iVar9 != iVar2;
            iVar9 = iVar2;
          } while (bVar5);
          ipc_log_string(icnss_ipc_soc_wake_context,
                         "icnss2: SOC previous release pending, Ref count: %d",*piVar1);
        }
        return 0;
      }
      pcVar7 = "icnss2: FW down, ignoring SOC Wake release state: 0x%lx\n";
      uVar6 = icnss_ipc_soc_wake_context;
    }
    ipc_log_string(uVar6,pcVar7,puVar8);
    uVar6 = 0xffffffea;
  }
  return uVar6;
}



//------------------------------------------------------------
// icnss_is_device_awake @ 00106e84 size=100
// signature: undefined icnss_is_device_awake(void)
// callers: []
//------------------------------------------------------------

undefined4 icnss_is_device_awake(long param_1)

{
  undefined4 uVar1;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x1550);
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_is_pci_ep_awake @ 00106eec size=120
// signature: undefined icnss_is_pci_ep_awake(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_is_pci_ep_awake(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk("%sicnss2: Platform driver not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Platform driver not initialized\n",&DAT_0011dab7
                  );
    uVar1 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0x208);
    if (lVar2 == 0) {
      uVar1 = 0xfffffff4;
    }
    else {
      uVar1 = readl(lVar2 + 4);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_athdiag_read @ 00106f68 size=340
// signature: undefined icnss_athdiag_read(void)
// callers: []
//------------------------------------------------------------

undefined8
icnss_athdiag_read(long param_1,undefined8 param_2,undefined8 param_3,int param_4,long param_5)

{
  undefined8 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x98);
  if (*piVar2 == 0x5abc5abc) {
    if ((param_5 == 0) || (param_4 - 0x1801U < 0xffffe800)) {
      _printk("%sicnss2: Invalid parameters for diag read: output %pK, data_len %u\n",&DAT_0011c04b,
              param_5,param_4);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Invalid parameters for diag read: output %pK, data_len %u\n",
                     &DAT_0011dab7,param_5,param_4);
      uVar1 = 0xffffffea;
    }
    else {
      uVar1 = *(undefined8 *)(piVar2 + 0x1de);
      if ((((uint)uVar1 >> 2 & 1) == 0) ||
         (uVar1 = *(undefined8 *)(piVar2 + 0x1de), ((uint)uVar1 >> 1 & 1) == 0)) {
        _printk("%sicnss2: Invalid state for diag read: 0x%lx\n",&DAT_0011c04b,uVar1);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid state for diag read: 0x%lx\n",
                       &DAT_0011dab7,*(undefined8 *)(piVar2 + 0x1de));
        uVar1 = 0xffffffea;
      }
      else {
        uVar1 = wlfw_athdiag_read_send_sync_msg(piVar2,param_2,param_3,param_4,param_5);
      }
    }
  }
  else {
    _printk("%sicnss2: Invalid drvdata for diag read: dev %pK, data %pK, magic 0x%x\n",&DAT_0011c04b
            ,param_1,piVar2);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for diag read: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar2,*piVar2);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_athdiag_write @ 001070c0 size=340
// signature: undefined icnss_athdiag_write(void)
// callers: []
//------------------------------------------------------------

undefined8
icnss_athdiag_write(long param_1,undefined8 param_2,undefined8 param_3,int param_4,long param_5)

{
  undefined8 uVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x98);
  if (*piVar2 == 0x5abc5abc) {
    if ((param_5 == 0) || (param_4 - 0x1801U < 0xffffe800)) {
      _printk("%sicnss2: Invalid parameters for diag write: input %pK, data_len %u\n",&DAT_0011c04b,
              param_5,param_4);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Invalid parameters for diag write: input %pK, data_len %u\n",
                     &DAT_0011dab7,param_5,param_4);
      uVar1 = 0xffffffea;
    }
    else {
      uVar1 = *(undefined8 *)(piVar2 + 0x1de);
      if ((((uint)uVar1 >> 2 & 1) == 0) ||
         (uVar1 = *(undefined8 *)(piVar2 + 0x1de), ((uint)uVar1 >> 1 & 1) == 0)) {
        _printk("%sicnss2: Invalid state for diag write: 0x%lx\n",&DAT_0011c04b,uVar1);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid state for diag write: 0x%lx\n",
                       &DAT_0011dab7,*(undefined8 *)(piVar2 + 0x1de));
        uVar1 = 0xffffffea;
      }
      else {
        uVar1 = wlfw_athdiag_write_send_sync_msg(piVar2,param_2,param_3,param_4,param_5);
      }
    }
  }
  else {
    _printk("%sicnss2: Invalid drvdata for diag write: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar2);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for diag write: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar2,*piVar2);
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_wlan_enable @ 00107218 size=408
// signature: undefined icnss_wlan_enable(void)
// callers: []
//------------------------------------------------------------

undefined4 icnss_wlan_enable(long param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  uint uVar4;
  long lVar5;
  char *pcVar6;
  int local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  if ((((uint)*(undefined8 *)(lVar5 + 0x778) >> 0xd & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar5 + 0x778) >> 2 & 1) != 0)) {
    if (((uint)*(undefined8 *)(lVar5 + 0x778) >> 0x10 & 1) == 0) {
      if (((*(char *)(lVar5 + 0x16f0) != '\0') && (*(char *)(lVar5 + 0x15c1) == '\0')) &&
         (*(char *)(lVar5 + 0x15c0) == '\0')) {
        icnss_setup_dms_mac(lVar5);
      }
      lVar3 = *(long *)(lVar5 + 0x108);
      if (lVar3 == 0x6750) {
        iVar1 = icnss_get_temperature(lVar5,&local_3c);
        if ((iVar1 == 0) &&
           (ipc_log_string(icnss_ipc_log_context,"icnss2: Temperature: %d\n",local_3c),
           local_3c < 5000)) {
          uVar4 = *(uint *)(lVar5 + 0x1648);
          if (uVar4 < 0x1f5) {
            uVar4 = 500;
          }
          *(uint *)(lVar5 + 0x1644) = uVar4;
        }
        lVar3 = *(long *)(lVar5 + 0x108);
      }
      if (lVar3 == 0x6450) {
        icnss_hw_power_off(lVar5);
      }
      uVar2 = icnss_send_wlan_enable_to_fw(lVar5,param_2,param_3,param_4);
      if (*(long *)(lVar5 + 0x108) == 0x6450) {
        icnss_hw_power_on(lVar5);
      }
      goto LAB_0010737c;
    }
    pcVar6 = "%sicnss2: Already Mode on, ignoring wlan_enable state: 0x%lx\n";
  }
  else {
    pcVar6 = "%sicnss2: FW down, ignoring wlan_enable state: 0x%lx\n";
  }
  _printk(pcVar6,&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,*(undefined8 *)(lVar5 + 0x778));
  uVar2 = 0xffffffea;
LAB_0010737c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_setup_dms_mac @ 001073b0 size=248
// signature: undefined icnss_setup_dms_mac(void)
// callers: [icnss_wlan_enable, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

void icnss_setup_dms_mac(long param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  pcVar1 = (char *)(param_1 + 0x15c0);
  iVar2 = icnss_qmi_get_dms_mac();
  if (((iVar2 != 0) || (*pcVar1 == '\0')) && (*(char *)(param_1 + 0x15c8) != '\0')) {
    if ((*pcVar1 == '\0') && (iVar2 = icnss_qmi_get_dms_mac(param_1), iVar2 == -0xb)) {
      msleep(0x32);
      iVar2 = 199;
      do {
        if ((*pcVar1 != '\0') || (iVar3 = icnss_qmi_get_dms_mac(param_1), iVar3 != -0xb)) break;
        msleep(0x32);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if ((*(char *)(param_1 + 0x15c1) == '\0') && (*pcVar1 == '\0')) {
      _printk("%sicnss2: Unable to get MAC from DMS after retries\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to get MAC from DMS after retries\n",
                     &DAT_0011dab7);
      return;
    }
  }
  if (*pcVar1 != '\0') {
    icnss_wlfw_wlan_mac_req_send_sync(param_1,param_1 + 0x15c2,6);
  }
  return;
}



//------------------------------------------------------------
// icnss_get_temperature @ 001074a8 size=308
// signature: undefined icnss_get_temperature(void)
// callers: [icnss_driver_event_work, icnss_wlan_enable]
//------------------------------------------------------------

ulong icnss_get_temperature(long param_1,undefined8 param_2)

{
  long lVar1;
  ulong uVar2;
  ulong uVar3;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  uVar2 = of_property_read_string(*(undefined8 *)(*(long *)(param_1 + 8) + 0x2f8),"tsens",&local_40)
  ;
  uVar3 = uVar2 & 0xffffffff;
  if ((int)uVar2 == 0) {
    ipc_log_string(icnss_ipc_log_context,"icnss2: Thermal Sensor is %s\n",local_40);
    uVar3 = thermal_zone_get_zone_by_name(local_40);
    if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
      _printk("%sicnss2: Fail to get thermal zone. ret: %ld",&DAT_0011c04b,uVar3);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to get thermal zone. ret: %ld",
                     &DAT_0011dab7,uVar3);
    }
    else {
      uVar2 = thermal_zone_get_temp(uVar3,param_2);
      uVar3 = uVar2 & 0xffffffff;
      if ((int)uVar2 != 0) {
        _printk("%sicnss2: Fail to get temperature. ret: %d",&DAT_0011c04b,uVar3);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to get temperature. ret: %d",
                       &DAT_0011dab7,uVar3);
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_wlan_disable @ 001075e0 size=68
// signature: undefined icnss_wlan_disable(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_wlan_disable(long param_1)

{
  undefined8 uVar1;
  
  if (((uint)*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x778) >> 0xd & 1) == 0) {
    uVar1 = icnss_send_wlan_disable_to_fw();
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2: FW down, ignoring wlan_disable state: 0x%lx\n");
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_is_qmi_disable @ 00107628 size=20
// signature: undefined icnss_is_qmi_disable(void)
// callers: []
//------------------------------------------------------------

ulong icnss_is_qmi_disable(void)

{
  return *(ulong *)(penv + 0x120) >> 2 & 1;
}



//------------------------------------------------------------
// icnss_get_ce_id @ 00107640 size=376
// signature: undefined icnss_get_ce_id(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_get_ce_id(long param_1,int param_2)

{
  undefined8 uVar1;
  
  if (penv == 0) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = 0xffffffed;
    if ((param_1 != 0) && (*(long *)(penv + 8) != 0)) {
      if (*(int *)(penv + 0x134) == param_2) {
        uVar1 = 0;
      }
      else if (*(int *)(penv + 0x138) == param_2) {
        uVar1 = 1;
      }
      else if (*(int *)(penv + 0x13c) == param_2) {
        uVar1 = 2;
      }
      else if (*(int *)(penv + 0x140) == param_2) {
        uVar1 = 3;
      }
      else if (*(int *)(penv + 0x144) == param_2) {
        uVar1 = 4;
      }
      else if (*(int *)(penv + 0x148) == param_2) {
        uVar1 = 5;
      }
      else if (*(int *)(penv + 0x14c) == param_2) {
        uVar1 = 6;
      }
      else if (*(int *)(penv + 0x150) == param_2) {
        uVar1 = 7;
      }
      else if (*(int *)(penv + 0x154) == param_2) {
        uVar1 = 8;
      }
      else if (*(int *)(penv + 0x158) == param_2) {
        uVar1 = 9;
      }
      else if (*(int *)(penv + 0x15c) == param_2) {
        uVar1 = 10;
      }
      else if (*(int *)(penv + 0x160) == param_2) {
        uVar1 = 0xb;
      }
      else {
        _printk("%sicnss2: No matching CE id for irq %d\n",&DAT_0011c04b,param_2);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: No matching CE id for irq %d\n",
                       &DAT_0011dab7,param_2);
        uVar1 = 0xffffffea;
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_get_irq @ 001077bc size=80
// signature: undefined icnss_get_irq(void)
// callers: []
//------------------------------------------------------------

undefined4 icnss_get_irq(long param_1,uint param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (penv == 0) {
    return 0xffffffed;
  }
  uVar2 = 0xffffffed;
  if ((param_1 != 0) && (*(long *)(penv + 8) != 0)) {
    if (0xb < (int)param_2) {
      return 0xffffffea;
    }
    if (0xb < param_2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10780c);
      (*pcVar1)();
    }
    uVar2 = *(undefined4 *)(penv + (ulong)param_2 * 4 + 0x134);
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_smmu_get_domain @ 00107810 size=112
// signature: undefined icnss_smmu_get_domain(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_smmu_get_domain(long param_1)

{
  undefined8 uVar1;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    _printk("%sicnss2: Invalid drvdata: dev %pK\n",&DAT_0011c04b,param_1);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid drvdata: dev %pK\n",&DAT_0011dab7,
                   param_1);
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined8 *)(*(long *)(param_1 + 0x98) + 0x218);
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_smmu_map @ 00107884 size=656
// signature: undefined icnss_smmu_map(void)
// callers: []
//------------------------------------------------------------

int icnss_smmu_map(ulong *param_1,ulong param_2,int *param_3,long param_4)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 local_64;
  ulong local_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  uVar7 = param_1[0x13];
  local_64 = 0;
  local_60 = param_2;
  if (uVar7 == 0) {
    _printk("%sicnss2: Invalid drvdata: dev %pK, data %pK\n",&DAT_0011c04b,param_1,0);
    pcVar3 = "%sicnss2: Invalid drvdata: dev %pK, data %pK\n";
    param_4 = 0;
  }
  else {
    if (param_3 != (int *)0x0) {
      uVar5 = *(long *)(uVar7 + 0x238) + 0xfffU & 0xfffffffffffff000;
      lVar2 = of_get_property(param_1[0x5d],"qcom,iommu-geometry",&local_64);
      if (lVar2 != 0) {
        if ((ulong)(*(long *)(uVar7 + 0x240) + *(long *)(uVar7 + 0x230)) <= uVar5) {
          _printk("%sicnss2: No IOVA space to map, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n"
                  ,&DAT_0011c04b,uVar5,uVar7 + 0x230);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: No IOVA space to map, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n"
                         ,&DAT_0011dab7,uVar5,uVar7 + 0x230,*(undefined8 *)(uVar7 + 0x240));
          iVar1 = -0xc;
          goto LAB_001079cc;
        }
      }
      uVar6 = (param_2 & 0xfff) + param_4 + 0xfff & 0xfffffffffffff000;
      lVar2 = of_find_property(param_1[0x5d],"dma-coherent",0);
      pcVar3 = "disabled";
      if (lVar2 != 0) {
        pcVar3 = "enabled";
      }
      uVar4 = 3;
      if (lVar2 != 0) {
        uVar4 = 7;
      }
      ipc_log_string(7,icnss_ipc_log_context,"icnss2: dma-coherent is %s\n",pcVar3);
      ipc_log_string(icnss_ipc_log_context,"icnss2: IOMMU Map: iova %lx, len %zu\n",uVar5,uVar6);
      iVar1 = iommu_map(*(undefined8 *)(uVar7 + 0x218),uVar5,param_2 & 0xfffffffffffff000,uVar6,
                        uVar4);
      if (iVar1 == 0) {
        *(ulong *)(uVar7 + 0x238) = uVar5 + uVar6;
        *param_3 = ((int)uVar5 + (uint)param_2) - ((uint)param_2 & 0xfffff000);
        ipc_log_string(icnss_ipc_log_context,"icnss2: IOVA addr mapped to physical addr %x\n");
      }
      else {
        _printk("%sicnss2: PA to IOVA mapping failed, ret %d\n",&DAT_0011c04b,iVar1);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: PA to IOVA mapping failed, ret %d\n",
                       &DAT_0011dab7,iVar1);
      }
      goto LAB_001079cc;
    }
    _printk("%sicnss2: iova_addr is NULL, paddr %pa, size %zu\n",&DAT_0011c04b,&local_60,param_4);
    param_1 = &local_60;
    pcVar3 = "%sicnss2: iova_addr is NULL, paddr %pa, size %zu\n";
  }
  ipc_log_string(icnss_ipc_log_context,pcVar3,&DAT_0011dab7,param_1,param_4);
  iVar1 = -0x16;
LAB_001079cc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// icnss_smmu_unmap @ 00107b18 size=428
// signature: undefined icnss_smmu_unmap(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_smmu_unmap(long param_1,uint param_2,ulong param_3)

{
  ulong uVar1;
  char *pcVar2;
  ulong uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
    _printk("%sicnss2: Invalid drvdata: dev %pK, data %pK\n",&DAT_0011c04b,param_1,0);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid drvdata: dev %pK, data %pK\n",
                   &DAT_0011dab7,param_1,0);
    return 0xffffffea;
  }
  if (param_2 == 0) {
    pcVar2 = "%sicnss2: iova_addr is NULL, size %zu\n";
    _printk("%sicnss2: iova_addr is NULL, size %zu\n",&DAT_0011c04b,param_3);
  }
  else {
    uVar1 = (ulong)param_2 & 0xfffff000;
    if ((ulong)(*(long *)(lVar4 + 0x240) + *(long *)(lVar4 + 0x230)) <= uVar1) {
      _printk("%sicnss2: Out of IOVA space during unmap, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n"
              ,&DAT_0011c04b,uVar1,lVar4 + 0x230);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Out of IOVA space during unmap, iova %lx, smmu_iova_ipa_start %pad, smmu_iova_ipa_len %zu\n"
                     ,&DAT_0011dab7,uVar1,lVar4 + 0x230,*(undefined8 *)(lVar4 + 0x240));
      return 0xfffffff4;
    }
    uVar3 = ((param_3 + param_2) - uVar1) + 0xfff & 0xfffffffffffff000;
    ipc_log_string(icnss_ipc_log_context,"icnss2: IOMMU Unmap: iova %lx, len %zu\n",uVar1,uVar3);
    param_3 = iommu_unmap(*(undefined8 *)(lVar4 + 0x218),uVar1,uVar3);
    if (param_3 == uVar3) {
      *(ulong *)(lVar4 + 0x238) = uVar1;
      return 0;
    }
    pcVar2 = "%sicnss2: Failed to unmap, %zu\n";
    _printk("%sicnss2: Failed to unmap, %zu\n",&DAT_0011c04b,param_3);
  }
  ipc_log_string(icnss_ipc_log_context,pcVar2,&DAT_0011dab7,param_3);
  return 0xffffffea;
}



//------------------------------------------------------------
// icnss_socinfo_get_serial_number @ 00107cc8 size=28
// signature: undefined icnss_socinfo_get_serial_number(void)
// callers: []
//------------------------------------------------------------

void icnss_socinfo_get_serial_number(void)

{
  socinfo_get_serial_number();
  return;
}



//------------------------------------------------------------
// icnss_trigger_recovery @ 00107ce8 size=440
// signature: undefined icnss_trigger_recovery(void)
// callers: [icnss_smmu_fault_handler]
//------------------------------------------------------------

undefined8 icnss_trigger_recovery(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x98);
  if (*piVar5 == 0x5abc5abc) {
    if (((uint)*(undefined8 *)(piVar5 + 0x1de) >> 9 & 1) == 0) {
      if ((char)piVar5[0x5bc] == '\0') {
        if (((uint)*(undefined8 *)(piVar5 + 0x1de) >> 8 & 1) == 0) {
          _printk("%sicnss2: PD restart not enabled to trigger recovery: state: 0x%lx\n",
                  &DAT_0011c04b);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: PD restart not enabled to trigger recovery: state: 0x%lx\n",
                         &DAT_0011dab7,*(undefined8 *)(piVar5 + 0x1de));
          return 0xffffffa1;
        }
        _printk("%sicnss2: Initiate PD restart at WLAN FW, state: 0x%lx\n",&DAT_0011c1f3);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Initiate PD restart at WLAN FW, state: 0x%lx\n",&DAT_0011dab7,
                       *(undefined8 *)(piVar5 + 0x1de));
        uVar4 = pdr_restart_pd(*(undefined8 *)(piVar5 + 0x574),*(undefined8 *)(piVar5 + 0x576));
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        puVar1 = (ulong *)(piVar5 + 0x1de);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 0x1000;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      else {
        ipc_log_string(icnss_ipc_log_long_context,"icnss2: Initiate Root PD restart");
        uVar4 = icnss_send_smp2p(piVar5,3,0);
        if ((int)uVar4 != 0) {
          return uVar4;
        }
        puVar1 = (ulong *)(piVar5 + 0x1de);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 0x1000;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      uVar4 = 0;
    }
    else {
      _printk("%sicnss2: PD recovery already in progress: state: 0x%lx\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: PD recovery already in progress: state: 0x%lx\n",&DAT_0011dab7,
                     *(undefined8 *)(piVar5 + 0x1de));
      uVar4 = 0xffffffff;
    }
  }
  else {
    _printk("%sicnss2: Invalid drvdata: magic 0x%x\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid drvdata: magic 0x%x\n",&DAT_0011dab7,
                   *piVar5);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// icnss_send_smp2p @ 00107ebc size=596
// signature: undefined icnss_send_smp2p(void)
// callers: [icnss_exit_power_save, icnss_pm_suspend, icnss_soc_wake_msg_work, icnss_trigger_recovery, icnss_allow_l1, icnss_prevent_l1, icnss_pm_runtime_suspend]
//------------------------------------------------------------

int icnss_send_smp2p(long param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined *puVar7;
  
  if (param_1 == 0) {
    return -0x16;
  }
  if (((*(long *)(param_1 + 0x108) == 0x6450) || (*(long *)(param_1 + 0x108) == 0x6750)) ||
     (*(char *)(param_1 + 0x16f0) != '\0')) {
    uVar6 = *(ulong *)(param_1 + (ulong)param_3 * 0x10 + 0xc20);
    if (uVar6 == 0) {
      return -0x16;
    }
    if (0xfffffffffffff000 < uVar6) {
      return -0x16;
    }
  }
  if (param_2 == 0) {
    param_1 = param_1 + (ulong)param_3 * 0x10;
    *(undefined2 *)(param_1 + 0xc18) = 0;
    iVar4 = qcom_smem_state_update_bits(*(undefined8 *)(param_1 + 0xc20),0xffffffff,0);
    if (iVar4 == 0) {
      return 0;
    }
    if (param_3 < 3) {
      puVar7 = (&icnss_smp2p_str)[param_3];
      _printk("%sicnss2: Error in SMP2P sent. ret: %d, %s\n",&DAT_0011c04b,iVar4,puVar7);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Error in SMP2P sent. ret: %d, %s\n",
                     &DAT_0011dab7,iVar4,puVar7);
      return iVar4;
    }
  }
  else {
    if ((((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) ||
       (((uint)*(undefined8 *)(param_1 + 0x778) >> 2 & 1) == 0)) {
      ipc_log_string(icnss_ipc_log_smp2p_context,
                     "icnss2: FW down, ignoring sending SMP2P state: 0x%lx\n");
      return -0x16;
    }
    lVar5 = param_1 + (ulong)param_3 * 0x10;
    uVar6 = (ulong)param_3;
    uVar1 = *(ushort *)(lVar5 + 0xc18);
    uVar2 = param_2 | (uint)uVar1 << 0x10;
    *(ushort *)(lVar5 + 0xc18) = uVar1 + 1;
    ipc_log_string(icnss_ipc_log_smp2p_context,"icnss2: Sending SMP2P value: 0x%X\n",uVar2);
    if ((param_2 & 0xfffffffe) == 4) {
      *(undefined4 *)(penv + 0x1660) = 0;
    }
    iVar4 = qcom_smem_state_update_bits
                      (*(undefined8 *)(param_1 + uVar6 * 0x10 + 0xc20),0xffffffff,uVar2);
    if (iVar4 == 0) {
      if (((param_2 & 0xfffffffe) != 4) ||
         (lVar5 = wait_for_completion_timeout(param_1 + 0x1660,0x7d), lVar5 != 0)) {
        return 0;
      }
      if (param_3 < 3) {
        puVar7 = (&icnss_smp2p_str)[uVar6];
        _printk("%sicnss2: SMP2P Soc Wake timeout msg %d, %s\n",&DAT_0011c04b,param_2,puVar7);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: SMP2P Soc Wake timeout msg %d, %s\n",
                       &DAT_0011dab7,param_2,puVar7);
        return 0;
      }
    }
    else if (param_3 < 3) {
      ipc_log_string(icnss_ipc_log_smp2p_context,"icnss2: Error in SMP2P send ret: %d, %s\n",iVar4,
                     (&icnss_smp2p_str)[uVar6]);
      return iVar4;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x108110);
  (*pcVar3)();
}



//------------------------------------------------------------
// icnss_idle_shutdown @ 00108114 size=228
// signature: undefined icnss_idle_shutdown(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_idle_shutdown(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    _printk("%sicnss2: Invalid drvdata: dev %pK",&DAT_0011c04b,param_1);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid drvdata: dev %pK",&DAT_0011dab7,param_1)
    ;
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined4 *)(lVar2 + 0xd04) = 1;
    if ((((*(char *)(lVar2 + 0xcea) == '\0') &&
         (((uint)*(undefined8 *)(lVar2 + 0x778) >> 0x12 & 1) == 0)) &&
        (((uint)*(undefined8 *)(lVar2 + 0x778) >> 0xf & 1) == 0)) && (*(int *)(lVar2 + 0xd00) == 0))
    {
      uVar1 = icnss_driver_event_post(lVar2,7,3,0);
    }
    else {
      _printk("%sicnss2: SSR/PDR/Shutdown is already in-progress during idle shutdown\n",
              &DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: SSR/PDR/Shutdown is already in-progress during idle shutdown\n",
                     &DAT_0011dab7);
      uVar1 = 0xfffffff0;
    }
    *(undefined4 *)(lVar2 + 0xd04) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_idle_restart @ 001081fc size=204
// signature: undefined icnss_idle_restart(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_idle_restart(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (lVar1 == 0) {
    _printk("%sicnss2: Invalid drvdata: dev %pK",&DAT_0011c04b,param_1);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid drvdata: dev %pK",&DAT_0011dab7,param_1)
    ;
    uVar2 = 0xffffffea;
  }
  else if (((*(char *)(lVar1 + 0xcea) == '\0') &&
           (((uint)*(undefined8 *)(lVar1 + 0x778) >> 0x12 & 1) == 0)) &&
          (((uint)*(undefined8 *)(lVar1 + 0x778) >> 0xf & 1) == 0)) {
    uVar2 = icnss_driver_event_post(lVar1,8,3,0);
  }
  else {
    _printk("%sicnss2: SSR/PDR is already in-progress during idle restart\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: SSR/PDR is already in-progress during idle restart\n",&DAT_0011dab7);
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_exit_power_save @ 001082cc size=96
// signature: undefined icnss_exit_power_save(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_exit_power_save(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: Calling Exit Power Save\n");
  if ((((uint)*(undefined8 *)(lVar2 + 0x778) >> 9 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar2 + 0x778) >> 0x10 & 1) != 0)) {
    uVar1 = icnss_send_smp2p(lVar2,2,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_prevent_l1 @ 00108330 size=64
// signature: undefined icnss_prevent_l1(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_prevent_l1(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((((uint)*(undefined8 *)(lVar1 + 0x778) >> 9 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar1 + 0x778) >> 0x10 & 1) != 0)) {
    uVar2 = icnss_send_smp2p(lVar1,7,2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_allow_l1 @ 00108374 size=56
// signature: undefined icnss_allow_l1(void)
// callers: []
//------------------------------------------------------------

void icnss_allow_l1(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if ((((uint)*(undefined8 *)(lVar1 + 0x778) >> 9 & 1) == 0) &&
     (((uint)*(undefined8 *)(lVar1 + 0x778) >> 0x10 & 1) != 0)) {
    icnss_send_smp2p(lVar1,6,2);
  }
  return;
}



//------------------------------------------------------------
// icnss_allow_recursive_recovery @ 001083b0 size=92
// signature: undefined icnss_allow_recursive_recovery(void)
// callers: []
//------------------------------------------------------------

void icnss_allow_recursive_recovery(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x98) + 0xbd9) = 1;
  _printk("%sicnss2: Recursive recovery allowed for WLAN\n",&DAT_0011e9ea);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Recursive recovery allowed for WLAN\n",
                 &DAT_0011dab7);
  return;
}



//------------------------------------------------------------
// icnss_disallow_recursive_recovery @ 00108410 size=88
// signature: undefined icnss_disallow_recursive_recovery(void)
// callers: []
//------------------------------------------------------------

void icnss_disallow_recursive_recovery(long param_1)

{
  *(undefined1 *)(*(long *)(param_1 + 0x98) + 0xbd9) = 0;
  _printk("%sicnss2: Recursive recovery disallowed for WLAN\n",&DAT_0011e9ea);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Recursive recovery disallowed for WLAN\n",
                 &DAT_0011dab7);
  return;
}



//------------------------------------------------------------
// icnss_get_iova @ 0010846c size=52
// signature: undefined icnss_get_iova(void)
// callers: [wlfw_host_cap_send_sync]
//------------------------------------------------------------

undefined8 icnss_get_iova(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_1 == 0) {
    return 0xffffffed;
  }
  if (*(long *)(param_1 + 0x228) == 0) {
    return 0xffffffea;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x220);
  *param_3 = *(undefined8 *)(param_1 + 0x228);
  return 0;
}



//------------------------------------------------------------
// icnss_get_iova_ipa @ 001084a4 size=52
// signature: undefined icnss_get_iova_ipa(void)
// callers: [wlfw_host_cap_send_sync]
//------------------------------------------------------------

undefined8 icnss_get_iova_ipa(long param_1,undefined8 *param_2,undefined8 *param_3)

{
  if (param_1 == 0) {
    return 0xffffffed;
  }
  if (*(long *)(param_1 + 0x240) == 0) {
    return 0xffffffea;
  }
  *param_2 = *(undefined8 *)(param_1 + 0x230);
  *param_3 = *(undefined8 *)(param_1 + 0x240);
  return 0;
}



//------------------------------------------------------------
// icnss_add_fw_prefix_name @ 001084dc size=184
// signature: undefined icnss_add_fw_prefix_name(void)
// callers: [icnss_wlfw_bdf_dnld_send_sync, icnss_wlfw_qdss_dnld_send_sync]
//------------------------------------------------------------

void icnss_add_fw_prefix_name(long param_1,undefined8 param_2,undefined8 param_3)

{
  char *pcVar1;
  long lVar2;
  
  if (param_1 == 0) {
    return;
  }
  if (*(char *)(param_1 + 0x131) == '\0') {
    scnprintf(param_2,0x32,&DAT_0011d029,param_3);
    return;
  }
  lVar2 = *(long *)(param_1 + 0x108);
  if (lVar2 == 0x6450) {
    pcVar1 = "wcn6450/%s";
  }
  else if (lVar2 == 0xabcd) {
    pcVar1 = "adrastea/%s";
  }
  else {
    if (lVar2 != 0x6750) goto LAB_0010856c;
    pcVar1 = "qca6750/%s";
  }
  scnprintf(param_2,0x32,pcVar1,param_3);
LAB_0010856c:
  ipc_log_string(icnss_ipc_log_context,"icnss2: File added with prefix: %s\n",param_2);
  return;
}



//------------------------------------------------------------
// icnss_recovery_timeout_hdlr @ 00108598 size=112
// signature: undefined icnss_recovery_timeout_hdlr(void)
// callers: []
//------------------------------------------------------------

void icnss_recovery_timeout_hdlr(long param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = (undefined8 *)(param_1 + -0xfa8);
  if (*(char *)(param_1 + -0x28) == '\0') {
    uVar1 = *puVar2;
  }
  else {
    uVar1 = *puVar2;
    if (((uint)uVar1 >> 0x18 & 1) == 0) {
      return;
    }
  }
  _printk("%sicnss2: Timeout waiting for FW Ready 0x%lx\n",&DAT_0011c04b,uVar1);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Timeout waiting for FW Ready 0x%lx\n",
                 &DAT_0011dab7,*puVar2);
  return;
}



//------------------------------------------------------------
// icnss_wpss_ssr_timeout_hdlr @ 0010860c size=116
// signature: undefined icnss_wpss_ssr_timeout_hdlr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_wpss_ssr_timeout_hdlr(long param_1)

{
  _printk("%sicnss2: Timeout waiting for WPSS SSR notification 0x%lx\n",&DAT_0011c04b,
          *(undefined8 *)(param_1 + -0xfe0));
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Timeout waiting for WPSS SSR notification 0x%lx\n"
                 ,&DAT_0011dab7,*(undefined8 *)(param_1 + -0xfe0));
  queue_work_on(0x20,_system_wq,&wpss_ssr_work);
  return;
}



//------------------------------------------------------------
// icnss_tcdev_get_max_state @ 00108684 size=20
// signature: undefined icnss_tcdev_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_tcdev_get_max_state(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(long *)(param_1 + 0x3b0) + 0x20);
  return 0;
}



//------------------------------------------------------------
// icnss_tcdev_get_cur_state @ 0010869c size=20
// signature: undefined icnss_tcdev_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_tcdev_get_cur_state(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(long *)(param_1 + 0x3b0) + 0x18);
  return 0;
}



//------------------------------------------------------------
// icnss_tcdev_set_cur_state @ 001086b4 size=320
// signature: undefined icnss_tcdev_set_cur_state(void)
// callers: []
//------------------------------------------------------------

int icnss_tcdev_set_cur_state(long param_1,ulong param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  
  if ((*(long *)(penv + 0x10) == 0) || (*(long *)(*(long *)(penv + 0x10) + 0x140) == 0)) {
    iVar1 = 0;
  }
  else {
    lVar4 = *(long *)(param_1 + 0x3b0);
    if (*(ulong *)(lVar4 + 0x20) < param_2) {
      iVar1 = -0x16;
    }
    else {
      lVar2 = *(long *)(penv + 8);
      ipc_log_string(icnss_ipc_log_long_context,
                     "icnss2: Cooling device set current state: %ld,for cdev id %d",param_2,
                     *(undefined4 *)(lVar4 + 0x10));
      mutex_lock(penv + 0x1588);
      pcVar3 = *(code **)(*(long *)(penv + 0x10) + 0x140);
      if (*(int *)(pcVar3 + -4) != 0x339c9611) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x108768);
        (*pcVar3)();
      }
      iVar1 = (*pcVar3)(lVar2 + 0x10,param_2,*(undefined4 *)(lVar4 + 0x10));
      lVar2 = penv;
      if (iVar1 == 0) {
        *(ulong *)(lVar4 + 0x18) = param_2;
        mutex_unlock(lVar2 + 0x1588);
      }
      else {
        mutex_unlock(penv + 0x1588);
        _printk("%sicnss2: Setting Current Thermal State Failed: %d,for cdev id %d",&DAT_0011c04b,
                iVar1,*(undefined4 *)(lVar4 + 0x10));
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Setting Current Thermal State Failed: %d,for cdev id %d",
                       &DAT_0011dab7,iVar1,*(undefined4 *)(lVar4 + 0x10));
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// readl @ 001087f4 size=140
// signature: undefined readl(void)
// callers: [icnss_is_pci_ep_awake, icnss_get_mhi_state]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x10884c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// icnss_probe @ 00108884 size=5412
// signature: undefined icnss_probe(void)
// callers: []
//------------------------------------------------------------

ulong icnss_probe(long param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  ulong *puVar5;
  long *plVar6;
  undefined4 uVar7;
  char cVar8;
  bool bVar9;
  code *pcVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  long lVar14;
  undefined4 *puVar15;
  long *plVar16;
  undefined8 *puVar17;
  long lVar18;
  ulong uVar19;
  long *plVar20;
  undefined8 uVar21;
  char *pcVar22;
  long lVar23;
  int *piVar24;
  long lVar25;
  ulong uVar26;
  undefined8 *puVar27;
  long *plVar28;
  int local_c4;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  ulong local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  if (*(long *)(param_1 + 0xa8) != 0) {
    _printk("%sicnss2: Driver is already initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Driver is already initialized\n",&DAT_0011dab7);
    uVar26 = 0xffffffef;
    goto LAB_00108960;
  }
  lVar14 = of_match_device(icnss_dt_match,param_1 + 0x10);
  if ((lVar14 == 0) || (lVar14 = *(long *)(lVar14 + 0xc0), lVar14 == 0)) {
    _printk("%sicnss2: Failed to find of match device!\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to find of match device!\n",&DAT_0011dab7
                  );
    uVar26 = 0xffffffed;
  }
  else {
    lVar23 = *(long *)(lVar14 + 0x18);
    if (lVar23 == 0x6450) {
      pcVar22 = "EVROS";
    }
    else if (lVar23 == 0x6750) {
      pcVar22 = "MOSELLE";
    }
    else if (lVar23 == 0xabcd) {
      pcVar22 = "ADRASTEA";
    }
    else {
      pcVar22 = "UNKNOWN";
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2: Platform driver probe for %s!\n",pcVar22);
    puVar15 = (undefined4 *)devm_kmalloc(param_1 + 0x10,0x17b8,0xdc0);
    if (puVar15 == (undefined4 *)0x0) {
      uVar26 = 0xfffffff4;
      goto LAB_00108960;
    }
    *(undefined4 **)(param_1 + 0xa8) = puVar15;
    *(long *)(puVar15 + 2) = param_1;
    *puVar15 = 0x5abc5abc;
    *(undefined8 *)(puVar15 + 0x42) = *(undefined8 *)(lVar14 + 0x18);
    *(undefined1 *)(puVar15 + 0x56e) = 1;
    *(undefined4 **)(puVar15 + 0x36) = puVar15 + 0x36;
    *(undefined4 **)(puVar15 + 0x38) = puVar15 + 0x36;
    *(undefined4 **)(puVar15 + 0x3a) = puVar15 + 0x3a;
    *(undefined4 **)(puVar15 + 0x3c) = puVar15 + 0x3a;
    *(undefined1 *)((long)puVar15 + 0xbd9) = 1;
    _printk("%sicnss2: Recursive recovery allowed for WLAN\n",&DAT_0011e9ea);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Recursive recovery allowed for WLAN\n",
                   &DAT_0011dab7);
    cnss_initialize_prealloc_pool(*(undefined8 *)(puVar15 + 0x42));
    *(undefined8 *)(puVar15 + 0x48) = 0x40;
    *(undefined8 *)(puVar15 + 0x4a) = 0x1000002ee;
    if (((*(long *)(puVar15 + 0x42) == 0x6450) || (*(long *)(puVar15 + 0x42) == 0x6750)) ||
       (lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                                  "wpss-support-enable",0), lVar14 != 0)) {
      *(undefined1 *)(puVar15 + 0x5bc) = 1;
    }
    lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),"bdf-download-support"
                              ,0);
    if (lVar14 != 0) {
      *(undefined1 *)((long)puVar15 + 0x1685) = 1;
    }
    lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),"rproc-fw-download",0)
    ;
    if (lVar14 != 0) {
      *(undefined1 *)(puVar15 + 0x5e8) = 1;
    }
    if ((*(char *)((long)puVar15 + 0x1685) != '\0') && (*(long *)(puVar15 + 0x42) == 0xabcd)) {
      puVar15[0x4b] = 0;
    }
    lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),"wlan-ipa-disabled",0)
    ;
    if (lVar14 != 0) {
      puVar5 = (ulong *)(puVar15 + 0x5ba);
      Hint_Prefetch(puVar5,2,0,1);
      do {
        cVar8 = '\x01';
        bVar9 = (bool)ExclusiveMonitorPass(puVar5,0x10);
        if (bVar9) {
          *puVar5 = *puVar5 | 1;
          cVar8 = ExclusiveMonitorsStatus();
        }
      } while (cVar8 != '\0');
    }
    lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                              "qcom,wpss-self-recovery",0);
    if (lVar14 != 0) {
      *(undefined1 *)(puVar15 + 0x5e4) = 1;
    }
    lVar14 = *(long *)(puVar15 + 2);
    local_c0 = (char *)((ulong)local_c0._4_4_ << 0x20);
    uVar11 = icnss_get_vreg(puVar15);
    if (uVar11 != 0) {
      uVar26 = (ulong)uVar11;
      _printk("%sicnss2: Failed to get vreg, err = %d\n",&DAT_0011c04b,uVar26);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get vreg, err = %d\n",&DAT_0011dab7,
                     uVar26);
      goto LAB_001089d0;
    }
    uVar11 = icnss_get_clk(puVar15);
    if (uVar11 == 0) {
      lVar23 = of_find_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,psf-supported",0);
      if (lVar23 != 0) {
        uVar26 = icnss_get_psf_info(puVar15);
        if ((int)uVar26 < 0) {
          uVar26 = uVar26 & 0xffffffff;
          goto LAB_001089d0;
        }
        *(undefined1 *)((long)puVar15 + 0x1686) = 1;
      }
      lVar23 = *(long *)(puVar15 + 0x42);
      if ((lVar23 == 0x6450) || (lVar23 == 0x6750)) {
        puVar17 = (undefined8 *)platform_get_resource_byname(lVar14,0x200,"msi_addr");
        if (puVar17 == (undefined8 *)0x0) {
          pcVar22 = "%sicnss2: MSI address not found in DT\n";
LAB_001094b0:
          _printk(pcVar22,&DAT_0011c04b);
          ipc_log_string(icnss_ipc_log_context,pcVar22,&DAT_0011dab7);
          uVar26 = 0xffffffea;
        }
        else {
          uVar21 = *puVar17;
          *(undefined8 *)(puVar15 + 0x1d6) = uVar21;
          lVar23 = dma_map_resource(lVar14 + 0x10,uVar21,0x1000,2,0);
          *(long *)(puVar15 + 0x1d8) = lVar23;
          if (lVar23 == -1) {
            _printk("%sicnss2: MSI: failed to map msi address\n",&DAT_0011c04b);
            ipc_log_string(icnss_ipc_log_context,"%sicnss2: MSI: failed to map msi address\n",
                           &DAT_0011dab7);
            uVar26 = 0xfffffff4;
            *(undefined8 *)(puVar15 + 0x1d8) = 0;
          }
          else {
            ipc_log_string(icnss_ipc_log_context,"icnss2: MSI Addr pa: %pa, iova: 0x%lluK\n",
                           puVar15 + 0x1d6,lVar23);
            uVar11 = of_property_read_u32_index
                               (*(undefined8 *)(lVar14 + 0x2f8),"interrupts",1,&local_c0);
            uVar21 = icnss_ipc_log_context;
            if (uVar11 == 0) {
              puVar15[0x46] = (int)local_c0 + 0x20;
              ipc_log_string(uVar21,"icnss2:  MSI Base Data: %d, IRQ Index: %d\n");
              piVar24 = &msi_config_wcn6750;
              if (*(long *)(puVar15 + 0x42) != 0x6750) {
                piVar24 = &msi_config_wcn6450;
              }
              iVar12 = *piVar24;
              *(int **)(puVar15 + 0x44) = piVar24;
              if (0 < iVar12) {
                uVar26 = 0;
                do {
                  iVar12 = platform_get_irq(*(undefined8 *)(puVar15 + 2),uVar26 & 0xffffffff);
                  if (iVar12 < 0) {
                    _printk("%sicnss2: Fail to get IRQ-%d\n",&DAT_0011c04b,uVar26 & 0xffffffff);
                    uVar26 = uVar26 & 0xffffffff;
                    goto LAB_00109818;
                  }
                  if (uVar26 == 0x20) {
                    /* WARNING: Does not return */
                    pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x109d88);
                    (*pcVar10)();
                  }
                  piVar24 = *(int **)(puVar15 + 0x44);
                  puVar15[uVar26 + 0x59] = iVar12;
                  uVar26 = uVar26 + 1;
                } while ((long)uVar26 < (long)*piVar24);
              }
              goto LAB_00108f5c;
            }
            uVar26 = (ulong)uVar11;
            ipc_log_string(icnss_ipc_log_context,"icnss2: Read interrupt prop failed");
          }
        }
      }
      else {
        if (lVar23 != 0xabcd) {
LAB_00108f5c:
          lVar14 = *(long *)(puVar15 + 2);
          local_70 = 0;
          local_80 = 0;
          uStack_78 = 0;
          local_90 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_c0 = (char *)0x0;
          uStack_b8 = 0;
          iVar12 = __of_parse_phandle_with_args
                             (*(undefined8 *)(lVar14 + 0x2f8),"qcom,wlan-msa-fixed-region",0,0,0,
                              &local_c0);
          pcVar22 = local_c0;
          if ((iVar12 != 0) || (local_c0 == (char *)0x0)) {
            puVar1 = puVar15 + 0x1da;
            uVar13 = of_property_read_variable_u32_array
                               (*(undefined8 *)(lVar14 + 0x2f8),"qcom,wlan-msa-memory",puVar1,1,0);
            iVar12 = puVar15[0x1da];
            uVar11 = uVar13;
            if (-1 < (int)uVar13) {
              uVar11 = 0;
            }
            uVar26 = (ulong)uVar11;
            if ((int)uVar13 < 0) {
              _printk("%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",&DAT_0011c04b,iVar12,
                      uVar26);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",&DAT_0011dab7,
                             *puVar1,uVar26);
            }
            else if (iVar12 == 0) {
              _printk("%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",&DAT_0011c04b,0,uVar26);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2: Fail to get MSA Memory Size: %u ret: %d\n",&DAT_0011dab7,
                             *puVar1,uVar26);
              if (-1 < (int)uVar13) goto LAB_00109090;
            }
            else {
              lVar14 = dmam_alloc_attrs(lVar14 + 0x10,iVar12,puVar15 + 0x1d4,0xcc0,0);
              *(long *)(puVar15 + 0x1dc) = lVar14;
              if (lVar14 != 0) {
                uVar7 = *puVar1;
                goto LAB_00109058;
              }
              _printk("%sicnss2: DMA alloc failed for MSA\n",&DAT_0011c04b);
              ipc_log_string(icnss_ipc_log_context,"%sicnss2: DMA alloc failed for MSA\n",
                             &DAT_0011dab7);
              uVar26 = 0xfffffff4;
            }
            goto LAB_001095e4;
          }
          lVar14 = __of_get_address(local_c0,0,0xffffffff,&local_70,0);
          if (lVar14 == 0) {
            pcVar22 = "%sicnss2: Failed to get assigned-addresses or property\n";
LAB_00109708:
            _printk(pcVar22,&DAT_0011c04b);
            ipc_log_string(icnss_ipc_log_context,pcVar22,&DAT_0011dab7);
            uVar26 = 0xffffffea;
          }
          else {
            lVar14 = of_translate_address(pcVar22,lVar14);
            *(long *)(puVar15 + 0x1d4) = lVar14;
            if (lVar14 == -1) {
              pcVar22 = "%sicnss2: Failed to translate MSA PA from device-tree\n";
              goto LAB_00109708;
            }
            lVar14 = memremap(lVar14,local_70,2);
            *(long *)(puVar15 + 0x1dc) = lVar14;
            if (lVar14 == 0) {
              _printk("%sicnss2: MSA PA ioremap failed: phy addr: %pa\n",&DAT_0011c04b,
                      puVar15 + 0x1d4);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2: MSA PA ioremap failed: phy addr: %pa\n",&DAT_0011dab7,
                             puVar15 + 0x1d4);
              uVar26 = 0xffffffea;
            }
            else {
              puVar15[0x1da] = (undefined4)local_70;
              uVar7 = (undefined4)local_70;
LAB_00109058:
              ipc_log_string(icnss_ipc_log_context,
                             "icnss2: MSA pa: %pa, MSA va: 0x%pK MSA Memory Size: 0x%x\n",
                             puVar15 + 0x1d4,lVar14,uVar7);
              lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                                        "qcom,fw-prefix",0);
              *(bool *)((long)puVar15 + 0x131) = lVar14 != 0;
LAB_00109090:
              plVar16 = (long *)(puVar15 + 0x1a4);
              lVar14 = *(long *)(puVar15 + 2);
              puVar2 = puVar15 + 0x1a8;
              *(long **)(puVar15 + 0x1a4) = plVar16;
              *(long **)(puVar15 + 0x1a6) = plVar16;
              iVar12 = of_property_read_variable_u32_array
                                 (*(undefined8 *)(lVar14 + 0x2f8),"qcom,icc-path-count",puVar2,1,0);
              if (iVar12 < 0) {
                ipc_log_string(icnss_ipc_log_context,
                               "icnss2: Platform Bus Interconnect path not configured\n");
              }
              else {
                puVar3 = puVar15 + 0x1aa;
                uVar11 = of_property_read_variable_u32_array
                                   (*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                                    "qcom,bus-bw-cfg-count",puVar3,1,0);
                if ((int)uVar11 < 0) {
                  uVar26 = (ulong)uVar11;
                  lVar23 = 0;
                  pcVar22 = "%sicnss2: Failed to get Bus BW Config table size\n";
                }
                else {
                  uVar26 = (ulong)(*puVar2 * *puVar3 * 2);
                  lVar23 = __kmalloc(uVar26 << 2,0xdc0);
                  if (lVar23 == 0) {
                    uVar26 = 0xfffffff4;
                    pcVar22 = "%sicnss2: Failed to alloc cfg table mem\n";
                  }
                  else {
                    uVar11 = of_property_read_variable_u32_array
                                       (*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                                        "qcom,bus-bw-cfg",lVar23,uVar26,0);
                    if (-1 < (int)uVar11) {
                      ipc_log_string(icnss_ipc_log_context,
                                     "icnss2: ICC Path_Count: %d BW_CFG_Count: %d\n",*puVar2,*puVar3
                                    );
                      if (*puVar2 != 0) {
                        uVar11 = 0;
                        local_c4 = 0;
                        do {
                          puVar17 = (undefined8 *)devm_kmalloc(lVar14 + 0x10,0x28,0xdc0);
                          if (puVar17 == (undefined8 *)0x0) {
                            uVar26 = 0xfffffff4;
LAB_001093a4:
                            plVar20 = (long *)*plVar16;
                            while (plVar20 != plVar16) {
                              plVar28 = (long *)*plVar20;
                              uVar19 = __list_del_entry_valid(plVar20);
                              if ((uVar19 & 1) != 0) {
                                lVar14 = *plVar20;
                                plVar6 = (long *)plVar20[1];
                                *(long **)(lVar14 + 8) = plVar6;
                                *plVar6 = lVar14;
                              }
                              *plVar20 = -0x2152ffffffffff00;
                              plVar20[1] = -0x2152fffffffffede;
                              plVar20 = plVar28;
                            }
                            goto LAB_0010950c;
                          }
                          puVar27 = puVar17 + 2;
                          uVar13 = of_property_read_string_helper
                                             (*(undefined8 *)(lVar14 + 0x2f8),"interconnect-names",
                                              puVar27,1,uVar11);
                          if ((int)uVar13 < 0) {
                            uVar26 = (ulong)uVar13;
                            goto LAB_001093a4;
                          }
                          uVar26 = of_icc_get(*(long *)(puVar15 + 2) + 0x10,puVar17[2]);
                          puVar17[3] = uVar26;
                          if ((0xfffffffffffff000 < uVar26) && ((uVar26 & 0xffffffff) != 0xfffffdfb)
                             ) {
                            _printk("%sicnss2: Failed to get Interconnect path for %s. Err: %d\n",
                                    &DAT_0011c04b,*puVar27,uVar26 & 0xffffffff);
                            ipc_log_string(icnss_ipc_log_context,
                                           "%sicnss2: Failed to get Interconnect path for %s. Err: %d\n"
                                           ,&DAT_0011dab7,*puVar27,uVar26 & 0xffffffff);
                            goto LAB_001093a4;
                          }
                          lVar18 = devm_kmalloc(lVar14 + 0x10,(ulong)*puVar3 << 3,0xdc0);
                          puVar17[4] = lVar18;
                          if (lVar18 == 0) {
                            uVar26 = 0xfffffff4;
                            goto LAB_001093a4;
                          }
                          ipc_log_string(icnss_ipc_log_context,"icnss2: ICC Vote CFG for path: %s\n"
                                         ,*puVar27);
                          uVar13 = *puVar3;
                          if (uVar13 != 0) {
                            lVar18 = 0;
                            uVar26 = 0;
                            do {
                              uVar4 = uVar13 * local_c4 + (int)lVar18;
                              lVar25 = lVar18 * 4;
                              *(undefined4 *)(puVar17[4] + lVar25) =
                                   *(undefined4 *)(lVar23 + (ulong)uVar4 * 4);
                              *(undefined4 *)(puVar17[4] + lVar25 + 4) =
                                   *(undefined4 *)(lVar23 + (ulong)(uVar4 + 1) * 4);
                              ipc_log_string(icnss_ipc_log_context,
                                             "icnss2: ICC Vote BW: %d avg: %d peak: %d\n",
                                             uVar26 & 0xffffffff,
                                             *(undefined4 *)(puVar17[4] + lVar25),
                                             ((undefined4 *)(puVar17[4] + lVar25))[1]);
                              uVar26 = uVar26 + 1;
                              lVar18 = lVar18 + 2;
                            } while (uVar26 < *puVar3);
                          }
                          puVar27 = *(undefined8 **)(puVar15 + 0x1a6);
                          uVar26 = __list_add_valid(puVar17,puVar27,plVar16);
                          if ((uVar26 & 1) != 0) {
                            *(undefined8 **)(puVar15 + 0x1a6) = puVar17;
                            *puVar17 = plVar16;
                            puVar17[1] = puVar27;
                            *puVar27 = puVar17;
                          }
                          uVar11 = uVar11 + 1;
                          local_c4 = local_c4 + 2;
                        } while (uVar11 < *puVar2);
                      }
                      kfree(lVar23);
                      goto LAB_00109520;
                    }
                    uVar26 = (ulong)uVar11;
                    pcVar22 = "%sicnss2: Invalid Bus BW Config Table\n";
                  }
                }
                _printk(pcVar22,&DAT_0011c04b);
                ipc_log_string(icnss_ipc_log_context,pcVar22,&DAT_0011dab7);
LAB_0010950c:
                kfree(lVar23);
                *(undefined8 *)(puVar15 + 0x1a8) = 0;
                *(undefined8 *)(puVar15 + 0x1aa) = 0;
                *plVar16 = 0;
                *(undefined8 *)(puVar15 + 0x1a6) = 0;
                if ((int)uVar26 != 0) goto LAB_001095e4;
              }
LAB_00109520:
              lVar14 = *(long *)(puVar15 + 2);
              local_c0 = (char *)0x0;
              local_70 = 0;
              iVar12 = of_property_read_variable_u32_array
                                 (*(undefined8 *)(lVar14 + 0x2f8),"qcom,iommu-dma-addr-pool",
                                  &local_70,2,0);
              uVar21 = icnss_ipc_log_context;
              if (iVar12 < 0) {
                pcVar22 = "%sicnss2: SMMU IOVA base not found\n";
LAB_00109690:
                _printk(pcVar22,&DAT_0011c04b);
                ipc_log_string(icnss_ipc_log_context,pcVar22,&DAT_0011dab7);
LAB_00109868:
                *(undefined8 *)(puVar15 + 0x1a2) = 0;
                puVar15[0x22e] = 0;
                __mutex_init(puVar15 + 0x2f8,"&priv->dev_lock",&icnss_probe___key);
                __mutex_init(puVar15 + 0x562,"&priv->tcdev_lock",&icnss_probe___key_280);
                lVar14 = alloc_workqueue("icnss_driver_event",2,1);
                *(long *)(puVar15 + 0x1d0) = lVar14;
                if (lVar14 == 0) {
                  _printk("%sicnss2: Workqueue creation failed\n",&DAT_0011c04b);
                  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Workqueue creation failed\n",
                                 &DAT_0011dab7);
                  uVar26 = 0xfffffff2;
                }
                else {
                  *(undefined8 *)(puVar15 + 0x1ac) = 0xfffffffe0;
                  *(undefined4 **)(puVar15 + 0x1ae) = puVar15 + 0x1ae;
                  *(undefined4 **)(puVar15 + 0x1b0) = puVar15 + 0x1ae;
                  *(code **)(puVar15 + 0x1b2) = icnss_driver_event_work;
                  *(undefined4 **)(puVar15 + 0x19a) = puVar15 + 0x19a;
                  *(undefined4 **)(puVar15 + 0x19c) = puVar15 + 0x19a;
                  if (*(char *)(puVar15 + 0x5be) != '\0') {
                    puVar15[0x5c0] = 0;
                    __init_swait_queue_head(puVar15 + 0x5c2,"&x->wait",&init_completion___key);
                  }
                  uVar11 = icnss_register_fw_service(puVar15);
                  if (-1 < (int)uVar11) {
                    icnss_power_misc_params_init(puVar15);
                    icnss_enable_recovery(puVar15);
                    icnss_debugfs_create(puVar15);
                    icnss_sysfs_create(puVar15);
                    lVar14 = *(long *)(puVar15 + 2);
                    device_set_wakeup_capable(lVar14 + 0x10,1);
                    iVar12 = device_wakeup_enable(lVar14 + 0x10);
                    if (iVar12 != 0) {
                      _printk("%sicnss2: Failed to init platform device wakeup source, err = %d\n",
                              &DAT_0011c04b,iVar12);
                      ipc_log_string(icnss_ipc_log_context,
                                     "%sicnss2: Failed to init platform device wakeup source, err = %d\n"
                                     ,&DAT_0011dab7,iVar12);
                    }
                    penv = puVar15;
                    puVar15[0x312] = 0;
                    __init_swait_queue_head(puVar15 + 0x314,"&x->wait",&init_completion___key);
                    if ((*(long *)(puVar15 + 0x42) == 0x6750) ||
                       (*(long *)(puVar15 + 0x42) == 0x6450)) {
                      lVar14 = alloc_workqueue("icnss_soc_wake_event",0x12,1);
                      *(long *)(puVar15 + 0x1d2) = lVar14;
                      if (lVar14 == 0) {
                        _printk("%sicnss2: Soc wake Workqueue creation failed\n",&DAT_0011c04b);
                        ipc_log_string(icnss_ipc_log_context,
                                       "%sicnss2: Soc wake Workqueue creation failed\n",
                                       &DAT_0011dab7);
                        icnss_unregister_fw_service(puVar15);
                        uVar26 = 0xfffffff2;
                        goto LAB_00109a9c;
                      }
                      *(undefined8 *)(puVar15 + 0x1c4) = 0xfffffffe0;
                      *(undefined4 **)(puVar15 + 0x1c6) = puVar15 + 0x1c6;
                      *(undefined4 **)(puVar15 + 0x1c8) = puVar15 + 0x1c6;
                      *(code **)(puVar15 + 0x1ca) = icnss_soc_wake_msg_work;
                      *(undefined4 **)(puVar15 + 0x19e) = puVar15 + 0x19e;
                      *(undefined4 **)(puVar15 + 0x1a0) = puVar15 + 0x19e;
                      iVar12 = icnss_genl_init();
                      if (iVar12 < 0) {
                        _printk("%sicnss2: ICNSS genl init failed %d\n",&DAT_0011c04b,iVar12);
                        ipc_log_string(icnss_ipc_log_context,"%sicnss2: ICNSS genl init failed %d\n"
                                       ,&DAT_0011dab7,iVar12);
                      }
                      puVar15[0x598] = 0;
                      __init_swait_queue_head(puVar15 + 0x59a,"&x->wait",&init_completion___key);
                      icnss_runtime_pm_init(puVar15);
                      icnss_aop_interface_init(puVar15);
                      puVar5 = (ulong *)(puVar15 + 0x1de);
                      Hint_Prefetch(puVar5,2,0,1);
                      do {
                        cVar8 = '\x01';
                        bVar9 = (bool)ExclusiveMonitorPass(puVar5,0x10);
                        if (bVar9) {
                          *puVar5 = *puVar5 | 0x200000;
                          cVar8 = ExclusiveMonitorsStatus();
                        }
                      } while (cVar8 != '\0');
                      *(undefined1 *)((long)puVar15 + 0x1685) = 1;
                      tracepoint_probe_register
                                (&__tracepoint_android_vh_rproc_recovery_set,
                                 rproc_restart_level_notifier,0);
                    }
                    if (*(char *)(puVar15 + 0x5bc) == '\0') {
LAB_00109c50:
                      if (*(char *)(puVar15 + 0x5e8) != '\0') goto LAB_00109c58;
                    }
                    else {
                      iVar12 = icnss_dms_init(puVar15);
                      if (iVar12 != 0) {
                        _printk("%sicnss2: ICNSS DMS init failed %d\n",&DAT_0011c04b,iVar12);
                        ipc_log_string(icnss_ipc_log_context,"%sicnss2: ICNSS DMS init failed %d\n",
                                       &DAT_0011dab7,iVar12);
                      }
                      lVar14 = of_find_property(*(undefined8 *)(*(long *)(puVar15 + 2) + 0x2f8),
                                                "use-nv-mac",0);
                      uVar21 = icnss_ipc_log_context;
                      pcVar22 = "Mandatory";
                      if (lVar14 == 0) {
                        pcVar22 = "Not Mandatory";
                      }
                      *(bool *)(puVar15 + 0x572) = lVar14 != 0;
                      ipc_log_string(uVar21,"icnss2: NV MAC feature is %s\n",pcVar22);
                      if (*(char *)(puVar15 + 0x5bc) == '\0') goto LAB_00109c50;
LAB_00109c58:
                      wpss_loader = 0xfffffffe0;
                      DAT_00124248 = &DAT_00124248;
                      DAT_00124250 = &DAT_00124248;
                      DAT_00124258 = icnss_wpss_load;
                    }
                    init_timer_key(puVar15 + 0x5c8,icnss_recovery_timeout_hdlr,0,0,0);
                    if (*(char *)(puVar15 + 0x5e4) != '\0') {
                      wpss_ssr_work = 0xfffffffe0;
                      DAT_00124210 = &DAT_00124210;
                      DAT_00124218 = &DAT_00124210;
                      DAT_00124220 = icnss_wpss_self_recovery;
                      init_timer_key(puVar15 + 0x5d6,icnss_wpss_ssr_timeout_hdlr,0,0,0);
                    }
                    icnss_register_ims_service(puVar15);
                    *(undefined4 **)(puVar15 + 0x55e) = puVar15 + 0x55e;
                    *(undefined4 **)(puVar15 + 0x560) = puVar15 + 0x55e;
                    _printk("%sicnss2: Platform driver probed successfully\n",&DAT_0011e9ea);
                    ipc_log_string(icnss_ipc_log_context,
                                   "%sicnss2: Platform driver probed successfully\n",&DAT_0011dab7);
                    uVar26 = 0;
                    goto LAB_00108960;
                  }
                  uVar26 = (ulong)uVar11;
                  _printk("%sicnss2: fw service registration failed: %d\n",&DAT_0011c04b,uVar26);
                  ipc_log_string(icnss_ipc_log_context,
                                 "%sicnss2: fw service registration failed: %d\n",&DAT_0011dab7,
                                 uVar26);
LAB_00109a9c:
                  destroy_workqueue(*(undefined8 *)(puVar15 + 0x1d0));
                }
                *(undefined8 *)(puVar15 + 0x86) = 0;
              }
              else {
                *(ulong *)(puVar15 + 0x88) = local_70 & 0xffffffff;
                *(ulong *)(puVar15 + 0x8a) = local_70 >> 0x20;
                ipc_log_string(uVar21,"icnss2: SMMU IOVA start: %pa, len: %zx\n",puVar15 + 0x88);
                lVar23 = iommu_get_domain_for_dev(lVar14 + 0x10);
                *(long *)(puVar15 + 0x86) = lVar23;
                if (lVar23 != 0) {
                  iVar12 = of_property_read_string
                                     (*(undefined8 *)(lVar14 + 0x2f8),"qcom,iommu-dma",&local_c0);
                  if ((iVar12 == 0) && (iVar12 = strcmp("fastmap",local_c0), iVar12 == 0)) {
                    ipc_log_string(icnss_ipc_log_context,"icnss2: SMMU S1 stage enabled\n");
                    *(undefined1 *)((long)puVar15 + 0xceb) = 1;
                    if ((*(long *)(puVar15 + 0x42) == 0x6750) ||
                       (*(long *)(puVar15 + 0x42) == 0x6450)) {
                      iommu_set_fault_handler
                                (*(undefined8 *)(puVar15 + 0x86),icnss_smmu_fault_handler,puVar15);
                    }
                  }
                  plVar20 = (long *)platform_get_resource_byname(lVar14,0x200,"smmu_iova_ipa");
                  if (plVar20 == (long *)0x0) {
                    pcVar22 = "%sicnss2: SMMU IOVA IPA not found\n";
                    goto LAB_00109690;
                  }
                  *(long *)(puVar15 + 0x8c) = *plVar20;
                  *(long *)(puVar15 + 0x8e) = *plVar20;
                  uVar21 = icnss_ipc_log_context;
                  *(long *)(puVar15 + 0x90) = (plVar20[1] - *plVar20) + 1;
                  ipc_log_string(uVar21,"icnss2: SMMU IOVA IPA start: %pa, len: %zx\n",
                                 puVar15 + 0x8c);
                  goto LAB_00109868;
                }
                uVar26 = 0xfffffdfb;
              }
              plVar20 = (long *)*plVar16;
              while (plVar20 != plVar16) {
                plVar28 = (long *)*plVar20;
                uVar19 = __list_del_entry_valid(plVar20);
                if ((uVar19 & 1) != 0) {
                  lVar14 = *plVar20;
                  plVar6 = (long *)plVar20[1];
                  *(long **)(lVar14 + 8) = plVar6;
                  *plVar6 = lVar14;
                }
                plVar6 = plVar20 + 3;
                *plVar20 = -0x2152ffffffffff00;
                plVar20[1] = -0x2152fffffffffede;
                plVar20 = plVar28;
                if (*plVar6 != 0) {
                  icc_put();
                }
              }
              *(undefined8 *)(puVar15 + 0x1a8) = 0;
              *(undefined8 *)(puVar15 + 0x1aa) = 0;
              *plVar16 = 0;
              *(undefined8 *)(puVar15 + 0x1a6) = 0;
            }
          }
LAB_001095e4:
          icnss_put_resources(puVar15);
          goto LAB_001089d0;
        }
        plVar16 = (long *)platform_get_resource_byname(lVar14,0x200,"membase");
        if (plVar16 == (long *)0x0) {
          pcVar22 = "%sicnss2: Memory base not found in DT\n";
          goto LAB_001094b0;
        }
        lVar23 = *plVar16;
        puVar1 = puVar15 + 0x7a;
        *(long *)(puVar15 + 0x7a) = lVar23;
        lVar23 = devm_ioremap(lVar14 + 0x10,lVar23,(plVar16[1] - *plVar16) + 1);
        *(long *)(puVar15 + 0x7c) = lVar23;
        if (lVar23 == 0) {
          _printk("%sicnss2: Memory base ioremap failed: phy addr: %pa\n",&DAT_0011c04b,puVar1);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: Memory base ioremap failed: phy addr: %pa\n",&DAT_0011dab7,
                         puVar1);
          uVar26 = 0xffffffea;
        }
        else {
          ipc_log_string(icnss_ipc_log_context,"icnss2: MEM_BASE pa: %pa, va: 0x%pK\n",puVar1,lVar23
                        );
          iVar12 = platform_get_irq(lVar14,0);
          if (iVar12 < 0) {
            uVar26 = 0;
          }
          else {
            puVar15[0x4d] = iVar12;
            uVar26 = 1;
            iVar12 = platform_get_irq(lVar14,1);
            if (-1 < iVar12) {
              puVar15[0x4e] = iVar12;
              uVar26 = 2;
              iVar12 = platform_get_irq(lVar14,2);
              if (-1 < iVar12) {
                puVar15[0x4f] = iVar12;
                uVar26 = 3;
                iVar12 = platform_get_irq(lVar14,3);
                if (-1 < iVar12) {
                  puVar15[0x50] = iVar12;
                  uVar26 = 4;
                  iVar12 = platform_get_irq(lVar14,4);
                  if (-1 < iVar12) {
                    puVar15[0x51] = iVar12;
                    uVar26 = 5;
                    iVar12 = platform_get_irq(lVar14,5);
                    if (-1 < iVar12) {
                      puVar15[0x52] = iVar12;
                      uVar26 = 6;
                      iVar12 = platform_get_irq(lVar14,6);
                      if (-1 < iVar12) {
                        puVar15[0x53] = iVar12;
                        uVar26 = 7;
                        iVar12 = platform_get_irq(lVar14,7);
                        if (-1 < iVar12) {
                          puVar15[0x54] = iVar12;
                          uVar26 = 8;
                          iVar12 = platform_get_irq(lVar14,8);
                          if (-1 < iVar12) {
                            puVar15[0x55] = iVar12;
                            uVar26 = 9;
                            iVar12 = platform_get_irq(lVar14,9);
                            if (-1 < iVar12) {
                              puVar15[0x56] = iVar12;
                              uVar26 = 10;
                              iVar12 = platform_get_irq(lVar14,10);
                              if (-1 < iVar12) {
                                puVar15[0x57] = iVar12;
                                uVar26 = 0xb;
                                iVar12 = platform_get_irq(lVar14,0xb);
                                if (-1 < iVar12) {
                                  puVar15[0x58] = iVar12;
                                  lVar23 = of_find_property(*(undefined8 *)(lVar14 + 0x2f8),
                                                            "qcom,is_low_power",0);
                                  uVar21 = icnss_ipc_log_context;
                                  if (lVar23 != 0) {
                                    *(undefined1 *)((long)puVar15 + 0x16f1) = 1;
                                    ipc_log_string(uVar21,
                                                  "icnss2: Deep Sleep/Hibernate mode supported\n");
                                  }
                                  iVar12 = of_property_read_variable_u32_array
                                                     (*(undefined8 *)(lVar14 + 0x2f8),
                                                      "qcom,rf_subtype",puVar15 + 0x5bd,1,0);
                                  uVar21 = icnss_ipc_log_context;
                                  if (-1 < iVar12) {
                                    *(undefined1 *)((long)puVar15 + 0x16f2) = 1;
                                    ipc_log_string(uVar21,"icnss2: RF subtype 0x%x\n",puVar15[0x5bd]
                                                  );
                                  }
                                  lVar14 = of_find_property(*(undefined8 *)(lVar14 + 0x2f8),
                                                            "qcom,is_slate_rfa",0);
                                  if (lVar14 != 0) {
                                    *(undefined1 *)(puVar15 + 0x5be) = 1;
                                    _printk("%sicnss2: SLATE rfa is enabled\n",&DAT_0011c04b);
                                    ipc_log_string(icnss_ipc_log_context,
                                                   "%sicnss2: SLATE rfa is enabled\n",&DAT_0011dab7)
                                    ;
                                  }
                                  goto LAB_00108f5c;
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
          }
          _printk("%sicnss2: Fail to get IRQ-%d\n",&DAT_0011c04b,uVar26);
LAB_00109818:
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to get IRQ-%d\n",&DAT_0011dab7,uVar26
                        );
          uVar26 = 0xffffffed;
        }
      }
      icnss_put_clk(puVar15);
    }
    else {
      uVar26 = (ulong)uVar11;
      _printk("%sicnss2: Failed to get clocks, err = %d\n",&DAT_0011c04b,uVar26);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get clocks, err = %d\n",
                     &DAT_0011dab7,uVar26);
    }
    icnss_put_vreg(puVar15);
  }
LAB_001089d0:
  cnss_deinitialize_prealloc_pool();
  *(undefined8 *)(param_1 + 0xa8) = 0;
LAB_00108960:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar26 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_remove @ 00109dc8 size=1040
// signature: undefined icnss_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 icnss_remove(long param_1)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  long lVar6;
  undefined4 *puVar7;
  
  lVar6 = *(long *)(param_1 + 0xa8);
  _printk("%sicnss2: Removing driver: state: 0x%lx\n",&DAT_0011e9ea,*(undefined8 *)(lVar6 + 0x778));
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Removing driver: state: 0x%lx\n",&DAT_0011dab7,
                 *(undefined8 *)(lVar6 + 0x778));
  del_timer(lVar6 + 0x1720);
  if (*(char *)(lVar6 + 0x1790) != '\0') {
    del_timer(lVar6 + 0x1758);
  }
  lVar1 = *(long *)(lVar6 + 8) + 0x10;
  device_wakeup_disable(lVar1);
  device_set_wakeup_capable(lVar1,0);
  icnss_unregister_ims_service(lVar6);
  icnss_debugfs_destroy(lVar6);
  lVar1 = penv;
  if (*(long *)(penv + 0x16a0) != 0) {
    power_supply_put();
  }
  if (*(char *)(lVar1 + 0x1686) != '\0') {
    __flush_workqueue(*(undefined8 *)(lVar1 + 0x16e0));
    destroy_workqueue(*(undefined8 *)(lVar1 + 0x16e0));
    power_supply_unreg_notifier(lVar1 + 0x1688);
  }
  if (*(long *)(lVar6 + 0xcf0) != 0) {
    kobject_put();
  }
  sysfs_remove_link(_kernel_kobj,"icnss");
  devm_device_remove_group(*(long *)(lVar6 + 8) + 0x10,icnss_attr_group);
  complete_all(lVar6 + 0xc48);
  if (*(char *)(lVar6 + 0x16f8) != '\0') {
    complete(lVar6 + 0x1700);
  }
  puVar7 = *(undefined4 **)(lVar6 + 0xba8);
  if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
    device_unregister(*(undefined8 *)(puVar7 + 10));
    ida_free(rd_minor_id,*puVar7);
    kfree(puVar7);
  }
  if (*(char *)(lVar6 + 0x16f0) == '\0') {
    puVar2 = (ulong *)(lVar6 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar5 = *puVar2;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = uVar5 & 0xffffffffffffff7f;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (((uint)uVar5 >> 7 & 1) != 0) {
      qcom_unregister_ssr_notifier(*(undefined8 *)(lVar6 + 0xb00),lVar6 + 0xb20);
      *(undefined8 *)(lVar6 + 0xb00) = 0;
    }
    puVar2 = (ulong *)(lVar6 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar5 = *puVar2;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = uVar5 & 0xfffffffffffffeff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (((uint)uVar5 >> 8 & 1) != 0) {
      pdr_handle_release(*(undefined8 *)(lVar6 + 0x15d0));
    }
  }
  else {
    icnss_dms_deinit(lVar6);
    uVar5 = *(ulong *)(lVar6 + 0xb10);
    if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
      qcom_unregister_early_ssr_notifier(uVar5,lVar6 + 0xb50);
      *(undefined8 *)(lVar6 + 0xb10) = 0;
    }
    puVar2 = (ulong *)(lVar6 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar5 = *puVar2;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = uVar5 & 0xffffffffffffff7f;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (((uint)uVar5 >> 7 & 1) != 0) {
      qcom_unregister_ssr_notifier(*(undefined8 *)(lVar6 + 0xb08),lVar6 + 0xb38);
      *(undefined8 *)(lVar6 + 0xb08) = 0;
    }
  }
  if ((*(long *)(lVar6 + 0x108) == 0x6750) || (*(long *)(lVar6 + 0x108) == 0x6450)) {
    icnss_genl_exit();
    __pm_runtime_disable(*(long *)(lVar6 + 8) + 0x10,1);
    pm_runtime_allow(*(long *)(lVar6 + 8) + 0x10);
    __pm_runtime_idle(*(long *)(lVar6 + 8) + 0x10,4);
    tracepoint_probe_unregister
              (&__tracepoint_android_vh_rproc_recovery_set,rproc_restart_level_notifier,0);
    complete_all(lVar6 + 0x1660);
    puVar7 = *(undefined4 **)(lVar6 + 0xbb0);
    if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
      device_unregister(*(undefined8 *)(puVar7 + 10));
      ida_free(rd_minor_id,*puVar7);
      kfree(puVar7);
    }
    puVar7 = *(undefined4 **)(lVar6 + 3000);
    if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
      device_unregister(*(undefined8 *)(puVar7 + 10));
      ida_free(rd_minor_id,*puVar7);
      kfree(puVar7);
    }
    puVar7 = *(undefined4 **)(lVar6 + 0xbc0);
    if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
      device_unregister(*(undefined8 *)(puVar7 + 10));
      ida_free(rd_minor_id,*puVar7);
      kfree(puVar7);
    }
    puVar7 = *(undefined4 **)(lVar6 + 0xbc8);
    if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
      device_unregister(*(undefined8 *)(puVar7 + 10));
      ida_free(rd_minor_id,*puVar7);
      kfree(puVar7);
    }
    puVar7 = *(undefined4 **)(lVar6 + 0xbd0);
    if ((puVar7 != (undefined4 *)0x0) && (puVar7 < (undefined4 *)0xfffffffffffff001)) {
      device_unregister(*(undefined8 *)(puVar7 + 10));
      ida_free(rd_minor_id,*puVar7);
      kfree(puVar7);
    }
    if (*(long *)(lVar6 + 0x748) != 0) {
      destroy_workqueue();
    }
    icnss_aop_interface_deinit(lVar6);
  }
  class_destroy(*(undefined8 *)(lVar6 + 0x1650));
  unregister_chrdev_region(*(undefined4 *)(lVar6 + 0x1658),0x100);
  icnss_unregister_fw_service(lVar6);
  if (*(long *)(lVar6 + 0x740) != 0) {
    destroy_workqueue();
  }
  *(undefined8 *)(lVar6 + 0x218) = 0;
  icnss_hw_power_off(lVar6);
  icnss_put_resources(lVar6);
  cnss_deinitialize_prealloc_pool();
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// icnss_driver_event_work @ 0010a20c size=7392
// signature: undefined icnss_driver_event_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_driver_event_work(long param_1)

{
  ulong *puVar1;
  undefined8 *****pppppuVar2;
  undefined4 *puVar3;
  ulong *puVar4;
  int *piVar5;
  char *pcVar6;
  long lVar7;
  undefined8 *****pppppuVar8;
  int iVar9;
  char *pcVar10;
  long *plVar11;
  uint uVar12;
  char cVar13;
  code *pcVar14;
  bool bVar15;
  bool bVar16;
  int iVar17;
  int iVar18;
  undefined8 uVar19;
  ulong uVar20;
  undefined8 *****pppppuVar21;
  uint uVar22;
  char *pcVar23;
  long *plVar24;
  long *plVar25;
  long *plVar26;
  long *plVar27;
  long lVar28;
  uint uVar29;
  undefined8 ****ppppuVar30;
  undefined8 *****pppppuVar31;
  long *plVar32;
  undefined4 *puVar33;
  undefined1 *puVar34;
  long *plVar35;
  long lVar36;
  long lVar37;
  int local_144;
  undefined8 *****local_a8;
  undefined8 *****local_a0;
  undefined8 *****local_98;
  undefined8 *****local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  long local_70;
  
  lVar37 = sp_el0;
  local_70 = *(long *)(lVar37 + 0x638);
  piVar5 = (int *)(param_1 + 0x4f0);
  Hint_Prefetch(piVar5,2,0,1);
  do {
    iVar18 = *piVar5;
    cVar13 = '\x01';
    bVar15 = (bool)ExclusiveMonitorPass(piVar5,0x10);
    if (bVar15) {
      *piVar5 = iVar18 + 1;
      cVar13 = ExclusiveMonitorsStatus();
    }
  } while (cVar13 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar18 + 1 == 1) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM stay awake, state: 0x%lx, count: %d\n",
                   *(undefined8 *)(param_1 + 200),*(undefined4 *)(param_1 + 0x4f0));
    pm_stay_awake(*(long *)(param_1 + -0x6a8) + 0x10);
    *(int *)(param_1 + 0x39c) = *(int *)(param_1 + 0x39c) + 1;
  }
  lVar37 = param_1 + -0x28;
  uVar19 = _raw_spin_lock_irqsave(lVar37);
  plVar32 = (long *)(param_1 + -0x48);
  plVar35 = (long *)*plVar32;
  if (plVar35 == plVar32) {
LAB_0010bee8:
    _raw_spin_unlock_irqrestore(lVar37,uVar19);
    piVar5 = (int *)(param_1 + 0x4f0);
    Hint_Prefetch(piVar5,2,0,1);
    do {
      iVar18 = *piVar5 + -1;
      cVar13 = '\x01';
      bVar15 = (bool)ExclusiveMonitorPass(piVar5,0x10);
      if (bVar15) {
        *piVar5 = iVar18;
        cVar13 = ExclusiveMonitorsStatus();
      }
    } while (cVar13 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar18 < 0) {
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0x800,0x10bfd8);
      (*pcVar14)();
    }
    if (iVar18 == 0) {
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM relax, state: 0x%lx, count: %d\n",
                     *(undefined8 *)(param_1 + 200),*(undefined4 *)(param_1 + 0x4f0));
      pm_relax(*(long *)(param_1 + -0x6a8) + 0x10);
      *(int *)(param_1 + 0x3a0) = *(int *)(param_1 + 0x3a0) + 1;
    }
    lVar37 = sp_el0;
    if (*(long *)(lVar37 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  plVar27 = (long *)(param_1 + -0x5a8);
  pcVar6 = (char *)(param_1 + 0x1040);
  lVar36 = param_1 + -0x6b0;
  puVar1 = (ulong *)(param_1 + 200);
  pppppuVar2 = (undefined8 *****)(param_1 + 0x660);
  plVar24 = (long *)(param_1 + -0x6a8);
  plVar25 = (long *)(param_1 + -0x6a0);
  plVar26 = (long *)(param_1 + -0x4a8);
LAB_0010a3b0:
  uVar20 = __list_del_entry_valid(plVar35);
  if ((uVar20 & 1) != 0) {
    lVar28 = *plVar35;
    plVar11 = (long *)plVar35[1];
    *(long **)(lVar28 + 8) = plVar11;
    *plVar11 = lVar28;
  }
  *plVar35 = -0x2152ffffffffff00;
  plVar35[1] = -0x2152fffffffffede;
  _raw_spin_unlock_irqrestore(lVar37,uVar19);
  uVar22 = *(uint *)(plVar35 + 2);
  pcVar23 = "UNKNOWN";
  if (uVar22 < 0x13) {
    pcVar23 = (&PTR_s_SERVER_ARRIVE_0011aaa0)[(int)uVar22];
  }
  pcVar10 = "";
  if (*(char *)((long)plVar35 + 0x14) != '\0') {
    pcVar10 = "-sync";
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2: Processing event: %s%s(%d), state: 0x%lx\n",pcVar23,
                 pcVar10,(long)(int)uVar22,*puVar1);
  switch((int)plVar35[2]) {
  case 0:
    lVar28 = plVar35[8];
    local_98 = (undefined8 *****)((ulong)local_98 & 0xffffffff00000000);
    if (lVar36 == 0) {
      iVar18 = -0x13;
    }
    else {
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 | 0x400;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 & 0xffffffffffffdfff;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      icnss_ignore_fw_timeout(0);
      if ((*puVar1 & 1) != 0) {
        _printk("%sicnss2: QMI Server already in Connected State\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: QMI Server already in Connected State\n",
                       &DAT_0011dab7);
      }
      iVar18 = icnss_connect_to_fw_server(lVar36,lVar28);
      if (iVar18 == 0) {
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar13 = '\x01';
          bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar15) {
            *puVar1 = *puVar1 | 1;
            cVar13 = ExclusiveMonitorsStatus();
          }
        } while (cVar13 != '\0');
        if ((*plVar27 != 0xabcd) || (iVar18 = icnss_hw_power_on(lVar36), iVar18 == 0)) {
          iVar17 = wlfw_ind_register_send_sync_msg(lVar36);
          if (iVar17 < 0) {
            iVar18 = 0;
            if (iVar17 != -0x72) {
              iVar18 = iVar17;
            }
          }
          else {
            if (*(char *)(param_1 + 0x1042) != '\0') {
              iVar17 = *(int *)(param_1 + 0x1044);
              iVar18 = 0x7fffffff;
              if (iVar17 == 1) {
                iVar18 = 1;
              }
              iVar9 = 0;
              if (iVar17 != 0) {
                iVar9 = iVar18;
              }
              if (iVar9 == 0x7fffffff) {
                pcVar23 = "icnss2: Invalid rf subtype %d in DT\n";
              }
              else {
                iVar17 = wlfw_wlan_hw_init_cfg_msg(lVar36);
                if (-1 < iVar17) goto LAB_0010b2b8;
                pcVar23 = "icnss2: Sending rf_subtype failed ret %d\n";
              }
              ipc_log_string(icnss_ipc_log_context,pcVar23,iVar17);
            }
LAB_0010b2b8:
            lVar28 = *plVar27;
            if ((lVar28 == 0x6750) || (lVar28 == 0x6450)) {
              iVar18 = icnss_get_temperature(lVar36,&local_98);
              if (iVar18 == 0) {
                ipc_log_string(icnss_ipc_log_context,"icnss2: Temperature: %d\n",
                               (ulong)local_98 & 0xffffffff);
                if ((int)local_98 < 5000) {
                  uVar22 = *(uint *)(param_1 + 0xf98);
                  if (uVar22 < 0x1f5) {
                    uVar22 = 500;
                  }
                  *(uint *)(param_1 + 0xf94) = uVar22;
                }
              }
              iVar18 = wlfw_host_cap_send_sync(lVar36);
              if (iVar18 < 0) break;
              lVar28 = *plVar27;
            }
            if (lVar28 == 0xabcd) {
              if (*(long *)(param_1 + 0xc0) == 0) {
                _printk("%sicnss2: Invalid MSA address\n",&DAT_0011c04b);
                ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid MSA address\n",&DAT_0011dab7
                              );
                iVar18 = -0x16;
              }
              else {
                iVar18 = wlfw_msa_mem_info_send_sync_msg(lVar36);
                if ((-1 < iVar18) && (iVar18 = wlfw_msa_ready_send_sync_msg(lVar36), -1 < iVar18)) {
                  lVar28 = *plVar27;
                  goto LAB_0010b36c;
                }
              }
            }
            else {
LAB_0010b36c:
              if (lVar28 == 0x6450) {
                icnss_hw_power_off(lVar36);
              }
              iVar18 = wlfw_cap_send_sync_msg(lVar36);
              if (-1 < iVar18) {
                lVar28 = *plVar27;
                if (lVar28 == 0xabcd) {
                  if (*(char *)(param_1 + 0xf08) != '\0') {
                    iVar18 = icnss_power_on_chain1_reg(lVar36);
                    if (iVar18 != 0) break;
                    lVar28 = *plVar27;
                    goto LAB_0010b3c4;
                  }
LAB_0010baac:
                  if (*(char *)(param_1 + 0xfd5) != '\0') {
                    icnss_wlfw_bdf_dnld_send_sync(lVar36,4);
                    iVar18 = icnss_wlfw_bdf_dnld_send_sync(lVar36,*(undefined4 *)(param_1 + -0x584))
                    ;
                    if (iVar18 < 0) goto LAB_0010bc6c;
                  }
                  lVar28 = *plVar27;
                  if (lVar28 == 0x6450) {
                    iVar18 = icnss_wlfw_qdss_dnld_send_sync(lVar36);
                    if (iVar18 < 0) {
                      _printk("%sicnss2: Failed to download qdss config file for WCN6450, ret = %d\n"
                              ,&DAT_0011e9ea,iVar18);
                      ipc_log_string(icnss_ipc_log_context,
                                     "%sicnss2: Failed to download qdss config file for WCN6450, ret = %d\n"
                                     ,&DAT_0011dab7,iVar18);
                    }
                    lVar28 = *plVar27;
                  }
                  if ((lVar28 == 0x6750) || (lVar28 == 0x6450)) {
                    if (*(int *)(param_1 + 0xfd0) == 0) {
                      register_soc_wake_notif(*plVar24 + 0x10);
                    }
                    icnss_get_smp2p_info(lVar36,1);
                    icnss_get_smp2p_info(lVar36,2);
                  }
                  if (*pcVar6 != '\0') {
                    icnss_get_smp2p_info(lVar36,0);
                  }
                  if (*plVar27 == 0xabcd) {
                    if ((*(char *)(param_1 + 0xfd5) != '\0') &&
                       (iVar18 = wlfw_cal_report_req(lVar36), iVar18 < 0)) goto LAB_0010bc6c;
                    wlfw_dynamic_feature_mask_send_sync_msg(lVar36,dynamic_feature_mask);
                  }
                  if (*(int *)(param_1 + 0x560) == 0) {
                    register_fw_error_notifications(*plVar24 + 0x10);
                    if (*(int *)(param_1 + 0x564) == 0) goto LAB_0010bbd4;
LAB_0010bbb0:
                    cVar13 = *(char *)(param_1 + 0xfd6);
                  }
                  else {
                    if (*(int *)(param_1 + 0x564) != 0) goto LAB_0010bbb0;
LAB_0010bbd4:
                    register_early_crash_notifications(*plVar24 + 0x10);
                    cVar13 = *(char *)(param_1 + 0xfd6);
                  }
                  if (cVar13 != '\0') {
                    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x1030),param_1 + 0x1000);
                  }
                }
                else {
LAB_0010b3c4:
                  if ((lVar28 != 0x6750) && (lVar28 != 0x6450)) goto LAB_0010baac;
                  iVar18 = icnss_hw_power_on(lVar36);
                  if (iVar18 != 0) break;
                  iVar18 = wlfw_device_info_send_msg(lVar36);
                  if (-1 < iVar18) {
                    lVar28 = devm_ioremap(*plVar24 + 0x10,*(undefined8 *)(param_1 + -0x4c8),
                                          *(undefined4 *)(param_1 + -0x4b8));
                    *(long *)(param_1 + -0x4c0) = lVar28;
                    if (lVar28 != 0) {
                      ipc_log_string(icnss_ipc_log_context,
                                     "icnss2: Non-Secured Bar Address pa: %pa, va: 0x%pK\n",
                                     (undefined8 *)(param_1 + -0x4c8),lVar28);
                      lVar28 = *(long *)(param_1 + -0x4b0);
                      if (lVar28 == 0) {
                        lVar28 = *plVar26;
                      }
                      else {
                        lVar28 = devm_ioremap(*plVar24 + 0x10,lVar28,0x1000);
                        *plVar26 = lVar28;
                      }
                      if (lVar28 == 0) {
                        _printk("%sicnss2: Ioremap failed for MHI info address\n",&DAT_0011c04b);
                        ipc_log_string(icnss_ipc_log_context,
                                       "%sicnss2: Ioremap failed for MHI info address\n",
                                       &DAT_0011dab7);
                        lVar28 = *plVar26;
                      }
                      ipc_log_string(icnss_ipc_log_context,
                                     "icnss2: MHI state info Address pa: %pa, va: 0x%pK\n",
                                     (long *)(param_1 + -0x4b0),lVar28);
                      goto LAB_0010baac;
                    }
                    _printk("%sicnss2: Ioremap failed for bar address\n",&DAT_0011c04b);
                    ipc_log_string(icnss_ipc_log_context,
                                   "%sicnss2: Ioremap failed for bar address\n",&DAT_0011dab7);
                  }
LAB_0010bc6c:
                  icnss_hw_power_off(lVar36);
                }
              }
            }
          }
        }
      }
    }
    break;
  case 1:
    if (lVar36 != 0) {
      _printk("%sicnss2: WLAN FW Service Disconnected: 0x%lx\n",&DAT_0011e9ea,
              *(undefined8 *)(param_1 + 200));
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: WLAN FW Service Disconnected: 0x%lx\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 200));
      icnss_clear_server(lVar36);
      if (*(char *)(param_1 + 0xfd6) == '\0') {
LAB_0010b198:
        iVar18 = 0;
      }
      else {
        iVar18 = 0;
        *(undefined4 *)(param_1 + 0xff8) = 0;
      }
      break;
    }
    iVar18 = -0x13;
    uVar20 = 1;
    goto LAB_0010b84c;
  case 2:
    iVar18 = icnss_driver_event_fw_ready_ind(lVar36);
    break;
  case 3:
    if (*plVar25 != 0) {
      iVar18 = -0x11;
      uVar20 = 3;
      goto LAB_0010b84c;
    }
    *plVar25 = plVar35[8];
    if (((uint)*(undefined8 *)(param_1 + -0x590) >> 2 & 1) == 0) {
      uVar22 = (uint)*puVar1;
    }
    else {
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 | 4;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      uVar22 = (uint)*puVar1;
    }
    if ((uVar22 >> 0xd & 1) == 0) {
      if (((uint)*puVar1 >> 2 & 1) == 0) {
        ipc_log_string(icnss_ipc_log_context,"icnss2: FW is not ready yet, state: 0x%lx\n");
        iVar18 = 0;
      }
      else {
        iVar18 = icnss_hw_power_on(lVar36);
        if (iVar18 == 0) {
          if (penv != 0) {
            puVar4 = (ulong *)(penv + 0x778);
            Hint_Prefetch(puVar4,2,0,1);
            do {
              cVar13 = '\x01';
              bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
              if (bVar15) {
                *puVar4 = *puVar4 | 0x20000;
                cVar13 = ExclusiveMonitorsStatus();
              }
            } while (cVar13 != '\0');
            *(undefined4 *)(penv + 0xc48) = 0;
          }
          if (*(int *)(*(code **)(*plVar25 + 200) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10afac);
            (*pcVar14)();
          }
          iVar18 = (**(code **)(*plVar25 + 200))(*plVar24 + 0x10);
          if (iVar18 == -0x205) {
            if (*(int *)(*(code **)(*plVar25 + 200) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
              pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10afe4);
              (*pcVar14)();
            }
            iVar18 = (**(code **)(*plVar25 + 200))(*plVar24 + 0x10);
            uVar19 = 2;
          }
          else {
            uVar19 = 1;
          }
          if (iVar18 == 0) {
            if (penv != 0) {
              puVar4 = (ulong *)(penv + 0x778);
              Hint_Prefetch(puVar4,2,0,1);
              do {
                cVar13 = '\x01';
                bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
                if (bVar15) {
                  *puVar4 = *puVar4 & 0xfffffffffffdffff;
                  cVar13 = ExclusiveMonitorsStatus();
                }
              } while (cVar13 != '\0');
              complete(penv + 0xc48);
            }
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar13 = '\x01';
              bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar15) {
                *puVar1 = *puVar1 | 8;
                cVar13 = ExclusiveMonitorsStatus();
              }
            } while (cVar13 != '\0');
            iVar18 = 0;
          }
          else {
            _printk("%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",&DAT_0011c04b
                    ,iVar18,*puVar1,uVar19);
            ipc_log_string(icnss_ipc_log_context,
                           "%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",
                           &DAT_0011dab7,iVar18,*puVar1,uVar19);
            icnss_block_shutdown(0);
            icnss_hw_power_off(lVar36);
          }
        }
      }
    }
    else {
      _printk("%sicnss2: FW is in bad state, state: 0x%lx\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: FW is in bad state, state: 0x%lx\n",
                     &DAT_0011dab7,*puVar1);
      iVar18 = -0x13;
    }
    break;
  case 4:
    if (((uint)*puVar1 >> 3 & 1) == 0) {
      iVar18 = 0;
      *plVar25 = 0;
    }
    else {
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 | 0x4000;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      lVar28 = penv;
      if (penv != 0) {
        puVar4 = (ulong *)(penv + 0x778);
        Hint_Prefetch(puVar4,2,0,1);
        do {
          cVar13 = '\x01';
          bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
          if (bVar15) {
            *puVar4 = *puVar4 | 0x20000;
            cVar13 = ExclusiveMonitorsStatus();
          }
          lVar28 = penv;
        } while (cVar13 != '\0');
        *(undefined4 *)(penv + 0xc48) = 0;
      }
      if (*plVar25 != 0) {
        pcVar14 = *(code **)(*plVar25 + 0xd0);
        if (*(int *)(pcVar14 + -4) != -0x6b11820d) {
                    /* WARNING: Does not return */
          pcVar14 = (code *)SoftwareBreakpoint(0x8229,0x10ac38);
          (*pcVar14)();
        }
        (*pcVar14)(*plVar24 + 0x10);
        lVar28 = penv;
      }
      if (lVar28 != 0) {
        puVar4 = (ulong *)(lVar28 + 0x778);
        Hint_Prefetch(puVar4,2,0,1);
        do {
          cVar13 = '\x01';
          bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
          if (bVar15) {
            *puVar4 = *puVar4 & 0xfffffffffffdffff;
            cVar13 = ExclusiveMonitorsStatus();
          }
        } while (cVar13 != '\0');
        complete(penv + 0xc48);
      }
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 & 0xffffffffffffbfff;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar15) {
          *puVar1 = *puVar1 & 0xfffffffffffffff7;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      *plVar25 = 0;
      icnss_hw_power_off(lVar36);
      iVar18 = 0;
    }
    break;
  case 5:
    pcVar23 = (char *)plVar35[8];
    if (((uint)*puVar1 >> 10 & 1) == 0) {
      icnss_ignore_fw_timeout(0);
    }
    else {
      lVar28 = *plVar27;
      if ((lVar28 == 0x6750) || (lVar28 == 0x6450)) {
        if (lVar36 != 0) {
          if (((lVar28 == 0x6450) || (lVar28 == 0x6750)) || (*pcVar6 != '\0')) {
            uVar20 = *(ulong *)(param_1 + 0x580);
            if ((uVar20 != 0) && (uVar20 < 0xfffffffffffff001)) goto LAB_0010b500;
          }
          else {
            uVar20 = *(ulong *)(param_1 + 0x580);
LAB_0010b500:
            *(undefined2 *)(param_1 + 0x578) = 0;
            iVar18 = qcom_smem_state_update_bits(uVar20,0xffffffff,0);
            if (iVar18 != 0) {
              _printk("%sicnss2: Error in SMP2P sent. ret: %d, %s\n",&DAT_0011c04b,iVar18,
                      "wlan-soc-wake-smp2p-out");
              ipc_log_string(icnss_ipc_log_context,"%sicnss2: Error in SMP2P sent. ret: %d, %s\n",
                             &DAT_0011dab7,iVar18,"wlan-soc-wake-smp2p-out");
            }
          }
          if (((*plVar27 == 0x6450) || (*plVar27 == 0x6750)) || (*pcVar6 != '\0')) {
            uVar20 = *(ulong *)(param_1 + 0x590);
            if ((uVar20 == 0) || (0xfffffffffffff000 < uVar20)) goto LAB_0010b56c;
          }
          else {
            uVar20 = *(ulong *)(param_1 + 0x590);
          }
          *(undefined2 *)(param_1 + 0x588) = 0;
          iVar18 = qcom_smem_state_update_bits(uVar20,0xffffffff,0);
          if (iVar18 == 0) goto LAB_0010b56c;
          _printk("%sicnss2: Error in SMP2P sent. ret: %d, %s\n",&DAT_0011c04b,iVar18,
                  "wlan-ep-powersave-smp2p-out");
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: Error in SMP2P sent. ret: %d, %s\n",
                         &DAT_0011dab7,iVar18,"wlan-ep-powersave-smp2p-out");
          if (lVar36 == 0) goto LAB_0010b5a0;
          goto LAB_0010b570;
        }
      }
      else {
LAB_0010b56c:
        if (lVar36 != 0) {
LAB_0010b570:
          if (((*pcVar6 != '\0') && (uVar20 = *(ulong *)(param_1 + 0x570), uVar20 != 0)) &&
             (uVar20 < 0xfffffffffffff001)) {
            *(undefined2 *)(param_1 + 0x568) = 0;
            iVar18 = qcom_smem_state_update_bits(uVar20,0xffffffff,0);
            if (iVar18 != 0) {
              _printk("%sicnss2: Error in SMP2P sent. ret: %d, %s\n",&DAT_0011c04b,iVar18,
                      "wlan-smp2p-out");
              ipc_log_string(icnss_ipc_log_context,"%sicnss2: Error in SMP2P sent. ret: %d, %s\n",
                             &DAT_0011dab7,iVar18,"wlan-smp2p-out");
            }
          }
        }
      }
LAB_0010b5a0:
      local_a8 = (undefined8 *****)0x0;
      local_a0 = (undefined8 *****)0x0;
      if (*(char *)(param_1 + 0x52a) == '\0') {
LAB_0010b6c4:
        local_98 = (undefined8 *****)0x2;
        if ((*plVar25 != 0) && (*(long *)(*plVar25 + 0x120) != 0)) {
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",*puVar1,2);
          local_90 = &local_a8;
          if (*(int *)(*(code **)(*plVar25 + 0x120) + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10b738);
            (*pcVar14)();
          }
          (**(code **)(*plVar25 + 0x120))(*plVar24 + 0x10,&local_98);
        }
        cVar13 = *(char *)(param_1 + 0x52a);
      }
      else {
        if (*(long *)(param_1 + 0xeb0) == 0) {
LAB_0010b694:
          _printk("%sicnss2: Unable to allocate memory for Hang event data\n",&DAT_0011c04b);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: Unable to allocate memory for Hang event data\n",&DAT_0011dab7);
          goto LAB_0010b6c4;
        }
        pppppuVar21 = (undefined8 *****)
                      kmemdup(*(long *)(param_1 + 0xeb0),*(undefined2 *)(param_1 + 0xeb8),0xa20);
        *(undefined8 ******)(param_1 + 0xec0) = pppppuVar21;
        if (pppppuVar21 == (undefined8 *****)0x0) goto LAB_0010b694;
        local_a0 = (undefined8 *****)CONCAT62(local_a0._2_6_,*(undefined2 *)(param_1 + 0xeb8));
        local_98 = (undefined8 *****)0x2;
        local_a8 = pppppuVar21;
        if ((*plVar25 != 0) && (*(long *)(*plVar25 + 0x120) != 0)) {
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                         *(undefined8 *)(param_1 + 200),2);
          local_90 = &local_a8;
          if (*(int *)(*(code **)(*plVar25 + 0x120) + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10b650);
            (*pcVar14)();
          }
          (**(code **)(*plVar25 + 0x120))(*plVar24 + 0x10,&local_98);
          pppppuVar21 = *(undefined8 ******)(param_1 + 0xec0);
        }
        kfree(pppppuVar21);
        *(undefined8 *)(param_1 + 0xec0) = 0;
        cVar13 = *(char *)(param_1 + 0x52a);
      }
      if (cVar13 == '\0') {
        if ((((uint)*puVar1 >> 9 & 1) == 0) || (*pcVar23 == '\0')) {
          if (((uint)*puVar1 >> 9 & 1) == 0) {
            icnss_fw_crashed(lVar36,pcVar23);
          }
        }
        else {
          _printk("%sicnss2: fatal: PD Down while recovery inprogress, crashed: %d, state: 0x%lx\n",
                  &DAT_0011c04b,1);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: fatal: PD Down while recovery inprogress, crashed: %d, state: 0x%lx\n"
                         ,&DAT_0011dab7,*pcVar23,*puVar1);
        }
      }
      else {
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: PD Down ignored as early indication is processed: %d, state: 0x%lx\n"
                       ,*pcVar23,*puVar1);
      }
    }
    kfree(pcVar23);
    iVar18 = 0;
    break;
  case 6:
    lVar28 = plVar35[8];
    if (((uint)*puVar1 >> 10 & 1) == 0) {
      icnss_ignore_fw_timeout(0);
    }
    else {
      *(undefined1 *)(param_1 + 0x52a) = 1;
      if (((uint)*(undefined8 *)(param_1 + 200) >> 9 & 1) == 0) {
        icnss_fw_crashed(lVar36,0);
      }
    }
    kfree(lVar28);
    iVar18 = 0;
    break;
  case 7:
    if (*plVar25 == 0) {
      iVar18 = 0;
      uVar20 = 7;
      goto LAB_0010b84c;
    }
    if (*(long *)(*plVar25 + 0x128) == 0) goto LAB_0010b198;
    if (((*(char *)(param_1 + 0x63a) == '\0') && (((uint)*puVar1 >> 0x12 & 1) == 0)) &&
       (((uint)*puVar1 >> 0xf & 1) == 0)) {
      ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver idle shutdown, state: 0x%lx\n");
      if (penv != 0) {
        puVar4 = (ulong *)(penv + 0x778);
        Hint_Prefetch(puVar4,2,0,1);
        do {
          cVar13 = '\x01';
          bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
          if (bVar15) {
            *puVar4 = *puVar4 | 0x20000;
            cVar13 = ExclusiveMonitorsStatus();
          }
        } while (cVar13 != '\0');
        *(undefined4 *)(penv + 0xc48) = 0;
      }
      print_optimize = 0;
      if (*(int *)(*(code **)(*plVar25 + 0x128) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10a784);
        (*pcVar14)();
      }
      iVar18 = (**(code **)(*plVar25 + 0x128))(*plVar24 + 0x10);
      if (penv != 0) {
        puVar4 = (ulong *)(penv + 0x778);
        Hint_Prefetch(puVar4,2,0,1);
        do {
          cVar13 = '\x01';
          bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
          if (bVar15) {
            *puVar4 = *puVar4 & 0xfffffffffffdffff;
            cVar13 = ExclusiveMonitorsStatus();
          }
        } while (cVar13 != '\0');
LAB_0010a9f8:
        complete(penv + 0xc48);
      }
    }
    else {
      pcVar23 = "%sicnss2: SSR/PDR is already in-progress during idle shutdown callback\n";
LAB_0010b02c:
      _printk(pcVar23,&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,pcVar23,&DAT_0011dab7);
      iVar18 = -0x10;
    }
    break;
  case 8:
    if (*plVar25 == 0) {
      iVar18 = 0;
      uVar20 = 8;
      goto LAB_0010b84c;
    }
    if (*(long *)(*plVar25 + 0x130) == 0) goto LAB_0010b198;
    if (((*(char *)(param_1 + 0x63a) != '\0') || (((uint)*puVar1 >> 0x12 & 1) != 0)) ||
       (((uint)*puVar1 >> 0xf & 1) != 0)) {
      pcVar23 = "%sicnss2: SSR/PDR is already in-progress during idle restart callback\n";
      goto LAB_0010b02c;
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver idle restart, state: 0x%lx\n");
    if (penv != 0) {
      puVar4 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar4,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar15) {
          *puVar4 = *puVar4 | 0x20000;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      *(undefined4 *)(penv + 0xc48) = 0;
    }
    print_optimize = 0;
    if (*(int *)(*(code **)(*plVar25 + 0x130) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10a9d4);
      (*pcVar14)();
    }
    iVar18 = (**(code **)(*plVar25 + 0x130))(*plVar24 + 0x10);
    if (penv != 0) {
      puVar4 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar4,2,0,1);
      do {
        cVar13 = '\x01';
        bVar15 = (bool)ExclusiveMonitorPass(puVar4,0x10);
        if (bVar15) {
          *puVar4 = *puVar4 & 0xfffffffffffdffff;
          cVar13 = ExclusiveMonitorsStatus();
        }
      } while (cVar13 != '\0');
      goto LAB_0010a9f8;
    }
    break;
  case 9:
    if (lVar36 == 0) {
      iVar18 = -0x13;
      uVar20 = 9;
      goto LAB_0010b84c;
    }
    _printk("%sicnss2: WLAN FW Initialization done: 0x%lx\n",&DAT_0011e9ea,*puVar1);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: WLAN FW Initialization done: 0x%lx\n",
                   &DAT_0011dab7,*puVar1);
    if (*plVar27 == 0x6750) {
      iVar18 = icnss_wlfw_qdss_dnld_send_sync(lVar36);
      if (iVar18 < 0) {
        _printk("%sicnss2: Failed to download qdss config file for WCN6750, ret = %d\n",
                &DAT_0011e9ea,iVar18);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Failed to download qdss config file for WCN6750, ret = %d\n",
                       &DAT_0011dab7,iVar18);
      }
    }
    else {
      iVar18 = 0;
    }
    if (((uint)*puVar1 >> 0x15 & 1) == 0) {
      icnss_driver_event_fw_ready_ind(lVar36);
    }
    else {
      mod_timer(param_1 + 0x1070,_jiffies + 10000);
      iVar18 = wlfw_wlan_mode_send_sync_msg(lVar36,7);
    }
    break;
  case 10:
    uVar22 = *(uint *)(param_1 + 0x658);
    if (uVar22 != 0) {
      uVar29 = 0;
      lVar28 = *plVar24;
      do {
        pppppuVar21 = pppppuVar2 + (long)(int)uVar29 * 5;
        if ((pppppuVar21[1] == (undefined8 ****)0x0) && (*pppppuVar21 != (undefined8 ****)0x0)) {
          ppppuVar30 = (undefined8 ****)
                       dma_alloc_attrs(lVar28 + 0x10,*pppppuVar21,
                                       pppppuVar2 + (long)(int)uVar29 * 5 + 2,0xcc0,0);
          pppppuVar21[1] = ppppuVar30;
          if (ppppuVar30 == (undefined8 ****)0x0) {
            _printk("%sicnss2: Failed to allocate QDSS memory for FW, size: 0x%zx, type: %u, chuck-ID: %d\n"
                    ,&DAT_0011c04b,*pppppuVar21,
                    *(undefined4 *)((long)pppppuVar2 + (long)(int)uVar29 * 0x28 + 0x1c),uVar29);
            ipc_log_string(icnss_ipc_log_context,
                           "%sicnss2: Failed to allocate QDSS memory for FW, size: 0x%zx, type: %u, chuck-ID: %d\n"
                           ,&DAT_0011dab7,*pppppuVar21,
                           *(undefined4 *)((long)pppppuVar2 + (long)(int)uVar29 * 0x28 + 0x1c),
                           uVar29);
            uVar22 = *(uint *)(param_1 + 0x658);
            break;
          }
          uVar22 = *(uint *)(param_1 + 0x658);
        }
        uVar29 = uVar29 + 1;
      } while (uVar29 < uVar22);
      if (uVar29 < uVar22) {
        uVar22 = uVar29;
        do {
          lVar28 = (long)(int)uVar22;
          uVar22 = uVar22 + 1;
          pppppuVar2[lVar28 * 5] = (undefined8 ****)0x0;
          uVar12 = *(uint *)(param_1 + 0x658);
          *(undefined4 *)((long)(pppppuVar2 + lVar28 * 5) + 0x1c) = 0;
        } while (uVar22 < uVar12);
        *(uint *)(param_1 + 0x658) = uVar29;
      }
    }
    iVar18 = wlfw_qdss_trace_mem_info_send_sync(lVar36);
    break;
  case 0xb:
    lVar28 = plVar35[8];
    local_80 = 0;
    local_78 = 0;
    local_90 = (undefined8 *****)0x0;
    local_88 = 0;
    local_a8 = (undefined8 *****)0x0;
    local_98 = (undefined8 *****)0x0;
    if (*(int *)(lVar28 + 8) == 6) {
      iVar17 = *(int *)(param_1 + 0x658);
      pppppuVar21 = pppppuVar2;
      if (iVar17 == 0) goto LAB_0010b1d8;
LAB_0010ad34:
      if (*(int *)(lVar28 + 4) == 0) {
        if (*(int *)(param_1 + 0x658) == 0) {
          iVar18 = 0;
        }
        else {
          uVar22 = 0;
          do {
            iVar18 = icnss_genl_send_msg((pppppuVar2 + (long)(int)uVar22 * 5)[1],1,lVar28 + 0x210,
                                         *(undefined4 *)(pppppuVar2 + (long)(int)uVar22 * 5));
            if (iVar18 < 0) goto LAB_0010b4c0;
            uVar22 = uVar22 + 1;
          } while (uVar22 < *(uint *)(param_1 + 0x658));
        }
      }
      else {
        uVar20 = 0;
        do {
          if (uVar20 == 0x20) goto LAB_0010bf80;
          lVar7 = lVar28 + uVar20 * 0x10;
          iVar18 = 0;
          local_a8 = *(undefined8 ******)(lVar7 + 0x10);
          uVar22 = *(uint *)(lVar7 + 0x18);
          while( true ) {
            pppppuVar31 = (undefined8 *****)(pppppuVar21 + (long)iVar18 * 5)[2];
            ppppuVar30 = pppppuVar21[(long)iVar18 * 5];
            bVar15 = false;
            bVar16 = true;
            if (local_a8 == pppppuVar31) {
              uVar29 = (uint)ppppuVar30;
              bVar16 = uVar29 <= uVar22;
              bVar15 = uVar22 == uVar29;
            }
            if (!bVar16 || bVar15) {
              ppppuVar30 = pppppuVar21[(long)iVar18 * 5 + 1];
              if (ppppuVar30 == (undefined8 ****)0x0) goto LAB_0010aedc;
              goto LAB_0010adc8;
            }
            bVar15 = local_a8 < pppppuVar31;
            bVar16 = (long)local_a8 - (long)pppppuVar31 == 0;
            pppppuVar8 = (undefined8 *****)(((ulong)ppppuVar30 & 0xffffffff) + (long)pppppuVar31);
            if ((((!bVar15 && !bVar16) && local_a8 <= pppppuVar8) &&
                ((bVar15 || bVar16) || pppppuVar8 != local_a8)) &&
                (undefined8 *****)((long)local_a8 + (ulong)uVar22) < pppppuVar8 ||
                (((!bVar15 && !bVar16) && local_a8 <= pppppuVar8) &&
                ((bVar15 || bVar16) || pppppuVar8 != local_a8)) &&
                (undefined8 *****)((long)local_a8 + (ulong)uVar22) == pppppuVar8) break;
            iVar18 = iVar18 + 1;
            if (iVar17 == iVar18) goto LAB_0010aedc;
          }
          ppppuVar30 = (undefined8 ****)
                       ((long)pppppuVar21[(long)iVar18 * 5 + 1] +
                       ((long)local_a8 - (long)pppppuVar31));
          if (ppppuVar30 == (undefined8 ****)0x0) {
LAB_0010aedc:
            _printk("%sicnss2: Fail to find matching va for pa %pa\n",&DAT_0011c04b,&local_a8);
            ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to find matching va for pa %pa\n",
                           &DAT_0011dab7,&local_a8);
            goto LAB_0010af14;
          }
LAB_0010adc8:
          iVar18 = icnss_genl_send_msg(ppppuVar30,1,lVar28 + 0x210);
          if (iVar18 < 0) goto LAB_0010b4c0;
          uVar20 = uVar20 + 1;
        } while (uVar20 < *(uint *)(lVar28 + 4));
      }
    }
    else {
      if (*(int *)(lVar28 + 8) == 1) {
        iVar17 = 1;
        local_90 = *(undefined8 ******)(param_1 + 0xc0);
        local_88 = *(undefined8 *)(param_1 + 0xa0);
        local_98 = (undefined8 *****)(ulong)*(uint *)(param_1 + 0xb8);
        pppppuVar21 = &local_98;
        goto LAB_0010ad34;
      }
LAB_0010b1d8:
      _printk("%sicnss2: FW Mem type %d not allocated. Invalid save request\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: FW Mem type %d not allocated. Invalid save request\n",&DAT_0011dab7,
                     *(undefined4 *)(lVar28 + 8));
LAB_0010af14:
      iVar18 = -0x16;
    }
    goto LAB_0010aff8;
  case 0xc:
    uVar22 = *(uint *)(param_1 + 0x658);
    if (uVar22 != 0) {
      uVar29 = 0;
      lVar28 = *plVar24;
      do {
        pppppuVar21 = pppppuVar2 + (long)(int)uVar29 * 5;
        if ((pppppuVar21[1] != (undefined8 ****)0x0) && (*pppppuVar21 != (undefined8 ****)0x0)) {
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
                         pppppuVar2 + (long)(int)uVar29 * 5 + 2,*pppppuVar21,
                         *(undefined4 *)((long)pppppuVar2 + (long)(int)uVar29 * 0x28 + 0x1c));
          dma_free_attrs(lVar28 + 0x10,*pppppuVar21,pppppuVar21[1],
                         pppppuVar2[(long)(int)uVar29 * 5 + 2],0);
          *pppppuVar21 = (undefined8 ****)0x0;
          pppppuVar21[1] = (undefined8 ****)0x0;
          pppppuVar21[2] = (undefined8 ****)0x0;
          uVar22 = *(uint *)(param_1 + 0x658);
          *(undefined4 *)((long)pppppuVar2 + (long)(int)uVar29 * 0x28 + 0x1c) = 0;
        }
        uVar29 = uVar29 + 1;
      } while (uVar29 < uVar22);
    }
    iVar18 = 0;
    *(undefined4 *)(param_1 + 0x658) = 0;
    break;
  case 0xd:
    puVar33 = (undefined4 *)plVar35[8];
    local_80 = 0;
    local_78 = 0;
    local_90 = (undefined8 *****)0x0;
    local_88 = 0;
    local_98 = (undefined8 *****)0x0;
    uVar20 = dump_enabled();
    if ((uVar20 & 1) == 0) {
      _printk("%sicnss2: Dump collection is not enabled\n",&DAT_0011e9ea);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Dump collection is not enabled\n",
                     &DAT_0011dab7);
      iVar18 = 0;
    }
    else {
      iVar18 = 0;
      if ((*(ulong *)(param_1 + 0x500) != 0) && (*(ulong *)(param_1 + 0x500) < 0xfffffffffffff001))
      {
        iVar18 = 0;
        if ((*(ulong *)(param_1 + 0x508) != 0) && (*(ulong *)(param_1 + 0x508) < 0xfffffffffffff001)
           ) {
          iVar18 = 0;
          if ((*(ulong *)(param_1 + 0x510) != 0) &&
             (*(ulong *)(param_1 + 0x510) < 0xfffffffffffff001)) {
            iVar18 = 0;
            if ((*(ulong *)(param_1 + 0x518) != 0) &&
               (*(ulong *)(param_1 + 0x518) < 0xfffffffffffff001)) {
              iVar18 = 0;
              if ((*(ulong *)(param_1 + 0x520) != 0) &&
                 (*(ulong *)(param_1 + 0x520) < 0xfffffffffffff001)) {
                local_a8 = &local_a8;
                local_a0 = local_a8;
                if (puVar33[1] == 0) {
                  local_144 = 0;
                  iVar18 = 0;
                }
                else {
                  uVar22 = 0;
                  iVar18 = 0;
                  local_144 = 0;
                  do {
                    local_80 = 0;
                    local_78 = 0;
                    local_90 = (undefined8 *****)0x0;
                    local_88 = 0;
                    local_98 = (undefined8 *****)0x0;
                    local_80 = devm_ioremap(*plVar24 + 0x10,
                                            *(undefined8 *)(puVar33 + (long)(int)uVar22 * 0xc + 4),
                                            *(undefined8 *)(puVar33 + (long)(int)uVar22 * 0xc + 6));
                    pppppuVar21 = local_a8;
                    if (local_80 == 0) {
                      _printk("%sicnss2: Failed to ioremap M3 Dump region",&DAT_0011c04b);
                      ipc_log_string(icnss_ipc_log_context,
                                     "%sicnss2: Failed to ioremap M3 Dump region",&DAT_0011dab7);
                      iVar18 = -0xc;
                      break;
                    }
                    local_78 = *(undefined8 *)(puVar33 + (long)(int)uVar22 * 0xc + 6);
                    uVar20 = __list_add_valid(&local_98,&local_a8,local_a8);
                    if ((uVar20 & 1) != 0) {
                      local_a8 = &local_98;
                      pppppuVar21[1] = local_a8;
                      local_98 = pppppuVar21;
                      local_90 = &local_a8;
                    }
                    puVar3 = puVar33 + (long)(int)uVar22 * 0xc + 8;
                    ipc_log_string(icnss_ipc_log_context,
                                   "icnss2: Started Dump colletcion for %s segment",puVar3);
                    switch(puVar33[(long)(int)uVar22 * 0xc + 2]) {
                    case 1:
                      lVar28 = *(long *)(param_1 + 0x500);
                      break;
                    case 2:
                      lVar28 = *(long *)(param_1 + 0x508);
                      break;
                    case 3:
                      lVar28 = *(long *)(param_1 + 0x510);
                      break;
                    case 4:
                      lVar28 = *(long *)(param_1 + 0x518);
                      break;
                    case 5:
                      lVar28 = *(long *)(param_1 + 0x520);
                      break;
                    default:
                      _printk("%sicnss2: Invalid Segment type: %d",&DAT_0011c04b);
                      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid Segment type: %d",
                                     &DAT_0011dab7,puVar33[(long)(int)uVar22 * 0xc + 2]);
                      goto joined_r0x0010ab84;
                    }
                    iVar18 = qcom_dump(&local_a8,*(undefined8 *)(lVar28 + 0x28));
joined_r0x0010ab84:
                    if (iVar18 != 0) {
                      _printk("%sicnss2: Failed to dump m3 %s segment, err = %d\n",&DAT_0011c04b,
                              puVar3,iVar18);
                      ipc_log_string(icnss_ipc_log_context,
                                     "%sicnss2: Failed to dump m3 %s segment, err = %d\n",
                                     &DAT_0011dab7,puVar3,iVar18);
                      local_144 = iVar18;
                    }
                    uVar20 = __list_del_entry_valid(&local_98);
                    if ((uVar20 & 1) != 0) {
                      local_98[1] = local_90;
                      *local_90 = local_98;
                    }
                    local_98 = (undefined8 *****)0xdead000000000100;
                    local_90 = (undefined8 *****)0xdead000000000122;
                    uVar22 = uVar22 + 1;
                  } while (uVar22 < (uint)puVar33[1]);
                }
                icnss_wlfw_m3_dump_upload_done_send_sync(lVar36,*puVar33,local_144);
              }
            }
          }
        }
      }
    }
    break;
  case 0xe:
    iVar18 = icnss_process_wfc_call_ind_event(lVar36,plVar35[8]);
    break;
  case 0xf:
    iVar18 = icnss_process_twt_cfg_ind_event(lVar36,plVar35[8]);
    break;
  case 0x10:
    if (lVar36 == 0) {
      iVar18 = -0x13;
      uVar20 = 0x10;
      goto LAB_0010b84c;
    }
    puVar33 = (undefined4 *)plVar35[8];
    if (puVar33 == (undefined4 *)0x0) {
      iVar18 = -0x16;
    }
    else {
      iVar18 = icnss_wlfw_qdss_data_send_sync(lVar36,puVar33 + 0x84,*puVar33);
      kfree(puVar33);
    }
    break;
  case 0x11:
    puVar34 = (undefined1 *)plVar35[8];
    if (puVar34 == (undefined1 *)0x0) {
      iVar18 = -0x16;
      uVar20 = 0x11;
      goto LAB_0010b84c;
    }
    if (lVar36 == 0) {
      iVar18 = -0x13;
    }
    else {
      iVar18 = wlfw_subsys_restart_level_msg(lVar36,*puVar34);
    }
    kfree(puVar34);
    break;
  default:
    _printk("%sicnss2: Invalid Event type: %d",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid Event type: %d",&DAT_0011dab7,
                   (int)plVar35[2]);
    kfree(plVar35);
    goto LAB_0010a3a4;
  }
  goto LAB_0010b840;
LAB_0010b4c0:
  _printk("%sicnss2: Fail to save QDSS data: %d\n",&DAT_0011c04b,iVar18);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to save QDSS data: %d\n",&DAT_0011dab7,iVar18
                );
LAB_0010aff8:
  kfree(lVar28);
LAB_0010b840:
  uVar20 = (ulong)*(uint *)(plVar35 + 2);
  if (0x11 < *(uint *)(plVar35 + 2)) {
LAB_0010bf80:
                    /* WARNING: Does not return */
    pcVar14 = (code *)SoftwareBreakpoint(0x5512,0x10bf84);
    (*pcVar14)();
  }
LAB_0010b84c:
  pcVar23 = "UNKNOWN";
  lVar28 = param_1 + 0x20c + uVar20 * 8;
  *(int *)(lVar28 + 4) = *(int *)(lVar28 + 4) + 1;
  uVar22 = *(uint *)(plVar35 + 2);
  if (uVar22 < 0x13) {
    pcVar23 = (&PTR_s_SERVER_ARRIVE_0011aaa0)[(int)uVar22];
  }
  pcVar10 = "";
  if (*(char *)((long)plVar35 + 0x14) != '\0') {
    pcVar10 = "-sync";
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2: Event Processed: %s%s(%d), ret: %d, state: 0x%lx\n",
                 pcVar23,pcVar10,(long)(int)uVar22,iVar18,*puVar1);
  uVar19 = _raw_spin_lock_irqsave(lVar37);
  if (*(char *)((long)plVar35 + 0x14) == '\0') {
    _raw_spin_unlock_irqrestore(lVar37,uVar19);
    kfree(plVar35);
    uVar19 = _raw_spin_lock_irqsave(lVar37);
  }
  else {
    *(int *)(plVar35 + 7) = iVar18;
    complete(plVar35 + 3);
  }
LAB_0010a3a4:
  plVar35 = (long *)*plVar32;
  if (plVar35 == plVar32) goto LAB_0010bee8;
  goto LAB_0010a3b0;
}



//------------------------------------------------------------
// icnss_enable_recovery @ 0010bfdc size=1296
// signature: undefined icnss_enable_recovery(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_enable_recovery(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  ulong uVar6;
  char *pcVar7;
  undefined *puVar8;
  
  if (((uint)*(undefined8 *)(param_1 + 0x120) >> 3 & 1) != 0) {
    pcVar7 = "icnss2: Recovery disabled through module parameter\n";
    goto LAB_0010c204;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x120) >> 5 & 1) == 0) {
    if (*(long *)(param_1 + 8) == 0) {
      pcVar7 = "%sicnss2: Platform priv or pdev is NULL\n";
    }
    else {
      uVar5 = __class_create(&__this_module,"icnss_ramdump",&icnss_ramdump_devnode_init___key);
      *(ulong *)(param_1 + 0x1650) = uVar5;
      if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
        _printk("%sicnss2: %s:Class create failed for ramdump devices (%d)\n",&DAT_0011c04b,
                "icnss_ramdump_devnode_init",uVar5 & 0xffffffff);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: %s:Class create failed for ramdump devices (%d)\n",&DAT_0011dab7,
                       "icnss_ramdump_devnode_init",uVar5 & 0xffffffff);
        if ((int)uVar5 != 0) {
          return;
        }
      }
      else {
        iVar4 = alloc_chrdev_region(param_1 + 0x1658,0,0x100,"icnss_ramdump");
        if (iVar4 < 0) {
          _printk("%sicnss2: %s: Unable to allocate major\n",&DAT_0011c04b,
                  "icnss_ramdump_devnode_init");
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: %s: Unable to allocate major\n",
                         &DAT_0011dab7,"icnss_ramdump_devnode_init");
          class_destroy(*(undefined8 *)(param_1 + 0x1650));
          return;
        }
      }
      uVar5 = icnss_create_ramdump_device(param_1,"wcss_msa0");
      *(ulong *)(param_1 + 0xba8) = uVar5;
      if (((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) || (*(long *)(uVar5 + 0x28) == 0)) {
        pcVar7 = "%sicnss2: Failed to create msa0 dump device!";
      }
      else {
        if ((*(long *)(param_1 + 0x108) != 0x6750) && (*(long *)(param_1 + 0x108) != 0x6450)) {
LAB_0010c168:
          if (*(char *)(param_1 + 0x16f0) != '\0') {
            *(code **)(param_1 + 0xb50) = icnss_wpss_early_notifier_nb;
            uVar5 = qcom_register_early_ssr_notifier(&DAT_00120417,param_1 + 0xb50);
            *(ulong *)(param_1 + 0xb10) = uVar5;
            if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
              _printk("%sicnss2: WPSS register early notifier failed: %d\n",&DAT_0011c04b,
                      uVar5 & 0xffffffff);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2: WPSS register early notifier failed: %d\n",&DAT_0011dab7,
                             uVar5 & 0xffffffff);
            }
            *(undefined4 *)(param_1 + 0xb48) = 1;
            *(code **)(param_1 + 0xb38) = icnss_wpss_notifier_nb;
            uVar5 = qcom_register_ssr_notifier(&DAT_00120417,param_1 + 0xb38);
            *(ulong *)(param_1 + 0xb08) = uVar5;
            if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
              _printk("%sicnss2: WPSS register notifier failed: %d\n",&DAT_0011c04b,
                      uVar5 & 0xffffffff);
              ipc_log_string(icnss_ipc_log_context,"%sicnss2: WPSS register notifier failed: %d\n",
                             &DAT_0011dab7,uVar5 & 0xffffffff);
            }
            puVar1 = (ulong *)(param_1 + 0x778);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 | 0x80;
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
            *(undefined4 *)(param_1 + 0xd04) = 0;
            return;
          }
          if (*(char *)(param_1 + 0x17a0) == '\0') {
            icnss_modem_ssr_register_notifier(param_1);
          }
          if (((uint)*(undefined8 *)(param_1 + 0x120) >> 4 & 1) != 0) {
            pcVar7 = "icnss2: PDR disabled through module parameter\n";
LAB_0010c204:
            ipc_log_string(icnss_ipc_log_context,pcVar7);
            return;
          }
          goto LAB_0010c258;
        }
        uVar5 = icnss_create_ramdump_device(param_1,"wcnss_phyareg");
        *(ulong *)(param_1 + 0xbb0) = uVar5;
        if ((uVar5 == 0) || ((0xfffffffffffff000 < uVar5 || (*(long *)(uVar5 + 0x28) == 0)))) {
          pcVar7 = "%sicnss2: Failed to create m3 dump for Phyareg segment device!";
        }
        else {
          uVar5 = icnss_create_ramdump_device(param_1,"wcnss_phydbg");
          *(ulong *)(param_1 + 3000) = uVar5;
          if (((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) || (*(long *)(uVar5 + 0x28) == 0)) {
            pcVar7 = "%sicnss2: Failed to create m3 dump for Phydbg segment device!";
          }
          else {
            uVar5 = icnss_create_ramdump_device(param_1,"wcnss_wmac0reg");
            *(ulong *)(param_1 + 0xbc0) = uVar5;
            if (((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) || (*(long *)(uVar5 + 0x28) == 0)) {
              pcVar7 = "%sicnss2: Failed to create m3 dump for Wmac0reg segment device!";
            }
            else {
              uVar5 = icnss_create_ramdump_device(param_1,"wcnss_WCSSDBG");
              *(ulong *)(param_1 + 0xbc8) = uVar5;
              if (((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) || (*(long *)(uVar5 + 0x28) == 0))
              {
                pcVar7 = "%sicnss2: Failed to create m3 dump for Wcssdbg segment device!";
              }
              else {
                uVar5 = icnss_create_ramdump_device(param_1,"wcnss_PHYAPDMEM");
                *(ulong *)(param_1 + 0xbd0) = uVar5;
                if (((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) && (*(long *)(uVar5 + 0x28) != 0)
                   ) goto LAB_0010c168;
                pcVar7 = "%sicnss2: Failed to create m3 dump for Phyapdmem segment device!";
              }
            }
          }
        }
      }
    }
    puVar8 = &DAT_0011c04b;
LAB_0010c3e8:
    _printk(pcVar7,puVar8);
    ipc_log_string(icnss_ipc_log_context,pcVar7,&DAT_0011dab7);
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2: SSR disabled through module parameter\n");
LAB_0010c258:
    uVar5 = pdr_handle_alloc(icnss_pdr_notifier_cb,param_1);
    if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
      _printk("%sicnss2: Failed to alloc pdr handle, err %d",&DAT_0011c04b,uVar5 & 0xffffffff);
      pcVar7 = "%sicnss2: Failed to alloc pdr handle, err %d";
    }
    else {
      uVar6 = pdr_add_lookup(uVar5,"wlan/fw","msm/modem/wlan_pd");
      if ((uVar6 != 0) && (uVar6 < 0xfffffffffffff001)) {
        *(ulong *)(param_1 + 0x15d0) = uVar5;
        *(ulong *)(param_1 + 0x15d8) = uVar6;
        puVar1 = (ulong *)(param_1 + 0x778);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 0x100;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        pcVar7 = "%sicnss2: PDR registration happened";
        puVar8 = &DAT_0011e9ea;
        goto LAB_0010c3e8;
      }
      _printk("%sicnss2: Failed to add lookup, err %d",&DAT_0011c04b,uVar6 & 0xffffffff);
      pcVar7 = "%sicnss2: Failed to add lookup, err %d";
      uVar5 = uVar6;
    }
    ipc_log_string(icnss_ipc_log_context,pcVar7,&DAT_0011dab7,uVar5 & 0xffffffff);
  }
  return;
}



//------------------------------------------------------------
// icnss_sysfs_create @ 0010c50c size=412
// signature: undefined icnss_sysfs_create(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_sysfs_create(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = devm_device_add_group(*(long *)(param_1 + 8) + 0x10,icnss_attr_group);
  if (iVar1 == 0) {
    iVar1 = sysfs_create_link(_kernel_kobj,*(long *)(param_1 + 8) + 0x10,"icnss");
    if (iVar1 != 0) {
      _printk("%sicnss2: Failed to create icnss link, err = %d\n",&DAT_0011c04b,iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to create icnss link, err = %d\n",
                     &DAT_0011dab7,iVar1);
    }
    *(undefined4 *)(param_1 + 0xd00) = 0;
    lVar2 = kobject_create_and_add("shutdown_wlan",_kernel_kobj);
    if (lVar2 == 0) {
      _printk("%sicnss2: Unable to create shutdown_wlan kernel object",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to create shutdown_wlan kernel object",
                     &DAT_0011dab7);
    }
    else {
      *(long *)(param_1 + 0xcf0) = lVar2;
      iVar1 = sysfs_create_file_ns(lVar2,&icnss_sysfs_attribute,0);
      if (iVar1 == 0) {
        return;
      }
      _printk("%sicnss2: Unable to create icnss sysfs file err:%d",&DAT_0011c04b,iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to create icnss sysfs file err:%d",
                     &DAT_0011dab7,iVar1);
    }
    devm_device_remove_group(*(long *)(param_1 + 8) + 0x10,icnss_attr_group);
  }
  else {
    _printk("%sicnss2: Failed to create icnss device group, err = %d\n",&DAT_0011c04b,iVar1);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to create icnss device group, err = %d\n"
                   ,&DAT_0011dab7,iVar1);
  }
  return;
}



//------------------------------------------------------------
// icnss_soc_wake_msg_work @ 0010c6ac size=1072
// signature: undefined icnss_soc_wake_msg_work(void)
// callers: []
//------------------------------------------------------------

void icnss_soc_wake_msg_work(long param_1)

{
  int *piVar1;
  char *pcVar2;
  long lVar3;
  long *plVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  code *pcVar9;
  bool bVar10;
  int iVar11;
  undefined8 uVar12;
  ulong uVar13;
  char *pcVar14;
  long lVar15;
  long *plVar16;
  long lVar17;
  long *plVar18;
  
  piVar1 = (int *)(param_1 + 0x490);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar11 = *piVar1;
    cVar8 = '\x01';
    bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar10) {
      *piVar1 = iVar11 + 1;
      cVar8 = ExclusiveMonitorsStatus();
    }
  } while (cVar8 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar11 + 1 == 1) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM stay awake, state: 0x%lx, count: %d\n",
                   *(undefined8 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x490));
    pm_stay_awake(*(long *)(param_1 + -0x708) + 0x10);
    *(int *)(param_1 + 0x33c) = *(int *)(param_1 + 0x33c) + 1;
  }
  lVar17 = param_1 + -0x84;
  uVar12 = _raw_spin_lock_irqsave(lVar17);
  plVar16 = (long *)(param_1 + -0x98);
  plVar18 = (long *)*plVar16;
  if (plVar18 == plVar16) {
LAB_0010ca64:
    _raw_spin_unlock_irqrestore(lVar17,uVar12);
    piVar1 = (int *)(param_1 + 0x490);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar11 = *piVar1 + -1;
      cVar8 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = iVar11;
        cVar8 = ExclusiveMonitorsStatus();
      }
    } while (cVar8 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar11 < 0) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x800,0x10cb3c);
      (*pcVar9)();
    }
    if (iVar11 == 0) {
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM relax, state: 0x%lx, count: %d\n",
                     *(undefined8 *)(param_1 + 0x68),*(undefined4 *)(param_1 + 0x490));
      pm_relax(*(long *)(param_1 + -0x708) + 0x10);
      *(int *)(param_1 + 0x340) = *(int *)(param_1 + 0x340) + 1;
    }
    return;
  }
  lVar15 = param_1 + -0x710;
  piVar1 = (int *)(param_1 + 0xe40);
LAB_0010c7cc:
  uVar13 = __list_del_entry_valid(plVar18);
  if ((uVar13 & 1) != 0) {
    lVar3 = *plVar18;
    plVar4 = (long *)plVar18[1];
    *(long **)(lVar3 + 8) = plVar4;
    *plVar4 = lVar3;
  }
  *plVar18 = -0x2152ffffffffff00;
  plVar18[1] = -0x2152fffffffffede;
  _raw_spin_unlock_irqrestore(lVar17,uVar12);
  uVar5 = *(uint *)(plVar18 + 2);
  pcVar14 = "UNKNOWN";
  if (uVar5 < 3) {
    pcVar14 = (&PTR_s_SOC_WAKE_REQUEST_0011ab38)[(int)uVar5];
  }
  pcVar2 = "";
  if (*(char *)((long)plVar18 + 0x14) != '\0') {
    pcVar2 = "-sync";
  }
  ipc_log_string(icnss_ipc_soc_wake_context,"icnss2: Processing event: %s%s(%d), state: 0x%lx\n",
                 pcVar14,pcVar2,(long)(int)uVar5,*(undefined8 *)(param_1 + 0x68));
  if ((int)plVar18[2] == 1) {
    if (lVar15 == 0) {
      iVar11 = -0x13;
      uVar13 = 1;
      goto LAB_0010c960;
    }
    iVar11 = *piVar1;
    do {
      iVar6 = iVar11 + -1;
      if (iVar6 < 0) goto LAB_0010c928;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar7 = *piVar1;
        if (iVar7 != iVar11) goto LAB_0010c8e0;
        cVar8 = '\x01';
        bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar10) {
          *piVar1 = iVar6;
          cVar8 = ExclusiveMonitorsStatus();
        }
      } while (cVar8 != '\0');
      DataMemoryBarrier(2,3);
LAB_0010c8e0:
      bVar10 = iVar11 != iVar7;
      iVar11 = iVar7;
    } while (bVar10);
    if (iVar6 != 0) {
LAB_0010c928:
      pcVar14 = "icnss2: Wake release not called. Ref count: %d";
      goto LAB_0010c934;
    }
    iVar11 = icnss_send_smp2p(lVar15,5,1);
    goto LAB_0010c940;
  }
  if ((int)plVar18[2] == 0) {
    if (lVar15 != 0) {
      iVar11 = *piVar1;
LAB_0010c85c:
      if (iVar11 != 0) goto code_r0x0010c860;
      iVar11 = icnss_send_smp2p(lVar15,4,1);
      if (iVar11 == 0) {
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar8 = '\x01';
          bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar10) {
            *piVar1 = *piVar1 + 1;
            cVar8 = ExclusiveMonitorsStatus();
          }
        } while (cVar8 != '\0');
        goto LAB_0010c93c;
      }
      goto LAB_0010c940;
    }
    iVar11 = -0x13;
    uVar13 = 0;
    goto LAB_0010c960;
  }
  _printk("%sicnss2: Invalid Event type: %d",&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Invalid Event type: %d",&DAT_0011dab7,
                 (int)plVar18[2]);
  kfree(plVar18);
  goto LAB_0010c7c0;
code_r0x0010c860:
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar6 = *piVar1;
    if (iVar6 != iVar11) goto LAB_0010c87c;
    cVar8 = '\x01';
    bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar10) {
      *piVar1 = iVar11 + 1;
      cVar8 = ExclusiveMonitorsStatus();
    }
  } while (cVar8 != '\0');
  DataMemoryBarrier(2,3);
LAB_0010c87c:
  bVar10 = iVar11 == iVar6;
  iVar11 = iVar6;
  if (bVar10) goto LAB_0010c914;
  goto LAB_0010c85c;
LAB_0010c914:
  pcVar14 = "icnss2: SOC awake after posting work, Ref count: %d";
LAB_0010c934:
  ipc_log_string(icnss_ipc_soc_wake_context,pcVar14,*piVar1);
LAB_0010c93c:
  iVar11 = 0;
LAB_0010c940:
  uVar13 = (ulong)*(uint *)(plVar18 + 2);
  if (1 < *(uint *)(plVar18 + 2)) {
                    /* WARNING: Does not return */
    pcVar9 = (code *)SoftwareBreakpoint(0x5512,0x10caec);
    (*pcVar9)();
  }
LAB_0010c960:
  pcVar14 = "UNKNOWN";
  lVar3 = param_1 + 0x23c + uVar13 * 8;
  *(int *)(lVar3 + 4) = *(int *)(lVar3 + 4) + 1;
  uVar5 = *(uint *)(plVar18 + 2);
  if (uVar5 < 3) {
    pcVar14 = (&PTR_s_SOC_WAKE_REQUEST_0011ab38)[(int)uVar5];
  }
  pcVar2 = "";
  if (*(char *)((long)plVar18 + 0x14) != '\0') {
    pcVar2 = "-sync";
  }
  ipc_log_string(icnss_ipc_soc_wake_context,
                 "icnss2: Event Processed: %s%s(%d), ret: %d, state: 0x%lx\n",pcVar14,pcVar2,
                 (long)(int)uVar5,iVar11,*(undefined8 *)(param_1 + 0x68));
  uVar12 = _raw_spin_lock_irqsave(lVar17);
  if (*(char *)((long)plVar18 + 0x14) == '\0') {
    _raw_spin_unlock_irqrestore(lVar17,uVar12);
    kfree(plVar18);
    uVar12 = _raw_spin_lock_irqsave(lVar17);
  }
  else {
    *(int *)(plVar18 + 7) = iVar11;
    complete(plVar18 + 3);
  }
LAB_0010c7c0:
  plVar18 = (long *)*plVar16;
  if (plVar18 == plVar16) goto LAB_0010ca64;
  goto LAB_0010c7cc;
}



//------------------------------------------------------------
// icnss_runtime_pm_init @ 0010cb40 size=92
// signature: undefined icnss_runtime_pm_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_runtime_pm_init(long param_1)

{
  __pm_runtime_resume(*(long *)(param_1 + 8) + 0x10,4);
  pm_runtime_forbid(*(long *)(param_1 + 8) + 0x10);
  __pm_runtime_set_status(*(long *)(param_1 + 8) + 0x10,0);
  pm_runtime_enable(*(long *)(param_1 + 8) + 0x10);
  return;
}



//------------------------------------------------------------
// icnss_wpss_load @ 0010cba0 size=300
// signature: undefined icnss_wpss_load(void)
// callers: []
//------------------------------------------------------------

void icnss_wpss_load(void)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = penv;
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(penv + 8) + 0x2f8),"qcom,rproc-handle",&local_3c,1,0)
  ;
  if (iVar3 < 0) {
    pcVar5 = "%sicnss2: error reading rproc phandle\n";
  }
  else {
    uVar4 = rproc_get_by_phandle(local_3c);
    *(ulong *)(lVar2 + 0xcf8) = uVar4;
    if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
      iVar3 = rproc_boot();
      if (iVar3 != 0) {
        _printk("%sicnss2: Failed to boot wpss rproc, ret: %d",&DAT_0011c04b,iVar3);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to boot wpss rproc, ret: %d",
                       &DAT_0011dab7,iVar3);
        rproc_put(*(undefined8 *)(lVar2 + 0xcf8));
      }
      goto LAB_0010cc14;
    }
    pcVar5 = "%sicnss2: rproc not found";
  }
  _printk(pcVar5,&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7);
LAB_0010cc14:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// icnss_wpss_self_recovery @ 0010ccd0 size=140
// signature: undefined icnss_wpss_self_recovery(void)
// callers: []
//------------------------------------------------------------

void icnss_wpss_self_recovery(void)

{
  long lVar1;
  int iVar2;
  
  lVar1 = penv;
  rproc_shutdown(*(undefined8 *)(penv + 0xcf8));
  iVar2 = rproc_boot(*(undefined8 *)(lVar1 + 0xcf8));
  if (iVar2 != 0) {
    _printk("%sicnss2: Failed to self recover wpss rproc, ret: %d",&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to self recover wpss rproc, ret: %d",
                   &DAT_0011dab7,iVar2);
    rproc_put(*(undefined8 *)(lVar1 + 0xcf8));
  }
  return;
}



//------------------------------------------------------------
// icnss_smmu_fault_handler @ 0010cd60 size=452
// signature: undefined icnss_smmu_fault_handler(void)
// callers: []
//------------------------------------------------------------

void icnss_smmu_fault_handler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               long param_5)

{
  undefined8 uVar1;
  long lVar2;
  code *pcVar3;
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined1 *local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_50[0] = 0;
  _printk("%sicnss2: fatal: SMMU fault happened with IOVA 0x%lx\n",&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: fatal: SMMU fault happened with IOVA 0x%lx\n",
                 &DAT_0011dab7,param_3);
  if (param_5 == 0) {
    _printk("%sicnss2: priv is NULL\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: priv is NULL\n",&DAT_0011dab7);
    uVar1 = 0xffffffed;
    goto LAB_0010ceb0;
  }
  if (((uint)*(undefined8 *)(param_5 + 0x778) >> 2 & 1) != 0) {
    lVar2 = *(long *)(param_5 + 0x10);
    local_50[0] = 1;
    local_48 = 3;
    if (lVar2 != 0) {
      if (*(long *)(lVar2 + 0x120) == 0) {
        lVar2 = *(long *)(lVar2 + 0x120);
      }
      else {
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                       *(undefined8 *)(param_5 + 0x778),3);
        pcVar3 = *(code **)(*(long *)(param_5 + 0x10) + 0x120);
        if (*(int *)(pcVar3 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10ce34);
          local_40 = local_50;
          (*pcVar3)();
        }
        local_40 = local_50;
        (*pcVar3)(*(long *)(param_5 + 8) + 0x10,&local_48);
        local_48 = 0;
        if (*(long *)(param_5 + 0x10) == 0) goto LAB_0010cea0;
        lVar2 = *(long *)(*(long *)(param_5 + 0x10) + 0x120);
      }
      local_48 = 0;
      if (lVar2 != 0) {
        local_48 = 0;
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                       *(undefined8 *)(param_5 + 0x778),1);
        local_48 = CONCAT44(local_48._4_4_,1);
        pcVar3 = *(code **)(*(long *)(param_5 + 0x10) + 0x120);
        if (*(int *)(pcVar3 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10ce9c);
          local_40 = local_50;
          (*pcVar3)();
        }
        local_40 = local_50;
        (*pcVar3)(*(long *)(param_5 + 8) + 0x10,&local_48);
      }
    }
  }
LAB_0010cea0:
  icnss_trigger_recovery(*(long *)(param_5 + 8) + 0x10);
  uVar1 = 0xffffffda;
LAB_0010ceb0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// icnss_driver_event_fw_ready_ind @ 0010cf24 size=1416
// signature: undefined icnss_driver_event_fw_ready_ind(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

int icnss_driver_event_fw_ready_ind(long param_1)

{
  ulong *puVar1;
  int *piVar2;
  ulong *puVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  int iVar7;
  ulong uVar8;
  uint uVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  long *plVar13;
  
  if (param_1 == 0) {
    return -0x13;
  }
  del_timer(param_1 + 0x1720);
  puVar1 = (ulong *)(param_1 + 0x778);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 | 4;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 & 0xfffffffffffeffff;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  *(undefined4 *)(param_1 + 0x1550) = 0;
  if (*(long *)(param_1 + 0x108) == 0x6750) {
    uVar9 = *(uint *)(param_1 + 0xd08);
    if (uVar9 != 0) {
      lVar11 = *(long *)(param_1 + 8);
      uVar10 = 0;
      do {
        plVar13 = (long *)(param_1 + 0xd10 + (long)(int)uVar10 * 0x28);
        if ((plVar13[1] != 0) && (*plVar13 != 0)) {
          lVar12 = param_1 + 0xd10 + (long)(int)uVar10 * 0x28;
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
                         lVar12 + 0x10,*plVar13,*(undefined4 *)(lVar12 + 0x1c));
          dma_free_attrs(lVar11 + 0x10,*plVar13,plVar13[1],*(undefined8 *)(lVar12 + 0x10),0);
          *plVar13 = 0;
          plVar13[1] = 0;
          plVar13[2] = 0;
          uVar9 = *(uint *)(param_1 + 0xd08);
          *(undefined4 *)(lVar12 + 0x1c) = 0;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar9);
    }
    *(undefined4 *)(param_1 + 0xd08) = 0;
  }
  _printk("%sicnss2: WLAN FW is ready: 0x%lx\n",&DAT_0011e9ea,*(undefined8 *)(param_1 + 0x778));
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: WLAN FW is ready: 0x%lx\n",&DAT_0011dab7,
                 *(undefined8 *)(param_1 + 0x778));
  icnss_hw_power_off(param_1);
  if (*(long *)(param_1 + 8) == 0) {
    _printk("%sicnss2: Device is not ready\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Device is not ready\n",&DAT_0011dab7);
    return -0x13;
  }
  if (((uint)*puVar1 >> 9 & 1) == 0) {
    if (*(char *)(param_1 + 0x16f0) != '\0') {
      icnss_setup_dms_mac(param_1);
    }
LAB_0010d160:
    iVar7 = icnss_call_driver_probe(param_1);
  }
  else {
    piVar2 = (int *)(param_1 + 0xba0);
    Hint_Prefetch(piVar2,2,0,1);
    do {
      iVar7 = *piVar2 + -1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
      if (bVar5) {
        *piVar2 = iVar7;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if (iVar7 < 0) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x10d438);
      (*pcVar6)();
    }
    if (iVar7 == 0) {
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM relax, state: 0x%lx, count: %d\n",
                     *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
      pm_relax(*(long *)(param_1 + 8) + 0x10);
      *(int *)(param_1 + 0xa50) = *(int *)(param_1 + 0xa50) + 1;
    }
    icnss_collect_host_dump_info(param_1);
    if ((((((uint)*(undefined8 *)(param_1 + 0x778) >> 3 & 1) != 0) &&
         (*(long *)(param_1 + 0x10) != 0)) && (*(long *)(*(long *)(param_1 + 0x10) + 0xd8) != 0)) &&
       (((uint)*puVar1 >> 0xb & 1) == 0)) {
      ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver shutdown state: 0x%lx\n");
      print_optimize = 0;
      pcVar6 = *(code **)(*(long *)(param_1 + 0x10) + 0xd8);
      if (*(int *)(pcVar6 + -4) != -0x6b11820d) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10d0f8);
        (*pcVar6)();
      }
      (*pcVar6)(*(long *)(param_1 + 8) + 0x10);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 0x800;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & 0xfffffffffffbffff;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & 0xffffffffffff7fff;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & 0xfffffffffffffdff;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & 0xfffffffffbffffff;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    *(undefined1 *)(param_1 + 0xbda) = 0;
    *(undefined1 *)(param_1 + 0xcea) = 0;
    if ((*(long *)(param_1 + 0x10) != 0) && (*(long *)(*(long *)(param_1 + 0x10) + 0xe0) != 0)) {
      if (((uint)*puVar1 >> 0xd & 1) == 0) {
        if (((uint)*puVar1 >> 3 & 1) == 0) goto LAB_0010d160;
        ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver reinit state: 0x%lx\n");
        icnss_hw_power_on(param_1);
        if (penv != 0) {
          puVar3 = (ulong *)(penv + 0x778);
          Hint_Prefetch(puVar3,2,0,1);
          do {
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
            if (bVar5) {
              *puVar3 = *puVar3 | 0x20000;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          *(undefined4 *)(penv + 0xc48) = 0;
        }
        print_optimize = 0;
        pcVar6 = *(code **)(*(long *)(param_1 + 0x10) + 0xe0);
        if (*(int *)(pcVar6 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x10d264);
          (*pcVar6)();
        }
        iVar7 = (*pcVar6)(*(long *)(param_1 + 8) + 0x10);
        if (iVar7 < 0) {
          _printk("%sicnss2: fatal: Driver reinit failed: %d, state: 0x%lx\n",&DAT_0011c04b,iVar7,
                  *(undefined8 *)(param_1 + 0x778));
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: fatal: Driver reinit failed: %d, state: 0x%lx\n",&DAT_0011dab7,
                         iVar7,*(undefined8 *)(param_1 + 0x778));
          icnss_block_shutdown(0);
          icnss_hw_power_off(param_1);
          goto LAB_0010d2a0;
        }
        if (penv != 0) {
          puVar3 = (ulong *)(penv + 0x778);
          Hint_Prefetch(puVar3,2,0,1);
          do {
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(puVar3,0x10);
            if (bVar5) {
              *puVar3 = *puVar3 & 0xfffffffffffdffff;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          complete(penv + 0xc48);
        }
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar5) {
            *puVar1 = *puVar1 & 0xfffffffffffff7ff;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
      else {
        _printk("%sicnss2: FW is in bad state, state: 0x%lx\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: FW is in bad state, state: 0x%lx\n",
                       &DAT_0011dab7,*puVar1);
      }
    }
    iVar7 = 0;
  }
LAB_0010d2a0:
  uVar8 = cpu_latency_qos_request_active(pm_qos_req);
  if ((uVar8 & 1) == 0) {
    cpu_latency_qos_add_request(pm_qos_req,0xffffffff);
  }
  else {
    cpu_latency_qos_update_request(pm_qos_req,0xffffffff);
  }
  if (wlan_pm_qos_update_last_value == '\x01') {
    wlan_pm_qos_update_last_value = '\0';
    _printk("%sicnss2:  PM_QOS_DEFAULT_VALUE  ",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2:  PM_QOS_DEFAULT_VALUE  ",&DAT_0011dab7);
  }
  icnss_vreg_unvote(param_1);
  return iVar7;
}



//------------------------------------------------------------
// register_soc_wake_notif @ 0010d51c size=396
// signature: undefined register_soc_wake_notif(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

void register_soc_wake_notif(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 != 0) {
    puVar3 = (undefined8 *)of_find_node_by_name(0,"qcom,smp2p_map_wlan_2_in");
    if (puVar3 == (undefined8 *)0x0) {
      _printk("%sicnss2: Failed to get smp2p node for soc-wake-ack\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get smp2p node for soc-wake-ack\n",
                     &DAT_0011dab7);
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2: smp2p node->name=%s\n",*puVar3);
      iVar1 = strcmp("qcom,smp2p_map_wlan_2_in",(char *)*puVar3);
      if (iVar1 == 0) {
        iVar1 = of_irq_get_byname(puVar3,"qcom,smp2p-soc-wake-ack");
        if (iVar1 < 0) {
          _printk("%sicnss2: Unable to get soc wake ack irq %d\n",&DAT_0011c04b,iVar1);
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to get soc wake ack irq %d\n",
                         &DAT_0011dab7,iVar1);
          return;
        }
      }
      else {
        iVar1 = 0;
      }
      iVar2 = devm_request_threaded_irq
                        (param_1,iVar1,0,fw_soc_wake_ack_handler,0x2003,"wlanfw-soc-wake-ack",lVar4)
      ;
      if (iVar2 < 0) {
        _printk("%sicnss2: Unable to register for SOC Wake ACK IRQ handler %d ret = %d",
                &DAT_0011c04b,iVar1,iVar2);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Unable to register for SOC Wake ACK IRQ handler %d ret = %d",
                       &DAT_0011dab7,iVar1,iVar2);
      }
      else {
        ipc_log_string(icnss_ipc_log_context,"icnss2: FW SOC Wake ACK handler registered irq = %d\n"
                       ,iVar1);
        *(int *)(lVar4 + 0x1680) = iVar1;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_get_smp2p_info @ 0010d6a8 size=772
// signature: undefined icnss_get_smp2p_info(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

void icnss_get_smp2p_info(long param_1,uint param_2)

{
  ulong *puVar1;
  char *pcVar2;
  code *pcVar3;
  ulong uVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  
  lVar6 = param_1 + (ulong)param_2 * 0x10;
  if (*(long *)(lVar6 + 0xc20) == 0) {
    if (2 < param_2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x10d9ac);
      (*pcVar3)();
    }
    puVar1 = (ulong *)(lVar6 + 0xc20);
    puVar7 = (&icnss_smp2p_str)[param_2];
    lVar6 = param_1 + (ulong)param_2 * 0x10 + 0xc1c;
    pcVar2 = (char *)(param_1 + 0x16f0);
    uVar4 = qcom_smem_state_get(*(long *)(param_1 + 8) + 0x10,puVar7,lVar6);
    lVar5 = *(long *)(param_1 + 0x108);
    *puVar1 = uVar4;
    if ((((lVar5 == 0x6450) || (lVar5 == 0x6750)) || (*pcVar2 != '\0')) &&
       ((uVar4 == 0 || (0xfffffffffffff000 < uVar4)))) {
      _printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011c04b,
              uVar4 & 0xffffffff,puVar7);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get smem state, ret: %d Entry: %s",
                     &DAT_0011dab7,uVar4 & 0xffffffff,puVar7);
      msleep(500);
      uVar4 = qcom_smem_state_get(*(long *)(param_1 + 8) + 0x10,puVar7,lVar6);
      lVar5 = *(long *)(param_1 + 0x108);
      *puVar1 = uVar4;
      if (((lVar5 == 0x6450) || ((lVar5 == 0x6750 || (*pcVar2 != '\0')))) &&
         ((uVar4 == 0 || (0xfffffffffffff000 < uVar4)))) {
        _printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011c04b,
                uVar4 & 0xffffffff,puVar7);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to get smem state, ret: %d Entry: %s"
                       ,&DAT_0011dab7,uVar4 & 0xffffffff,puVar7);
        msleep(500);
        uVar4 = qcom_smem_state_get(*(long *)(param_1 + 8) + 0x10,puVar7,lVar6);
        lVar5 = *(long *)(param_1 + 0x108);
        *puVar1 = uVar4;
        if ((((lVar5 == 0x6450) || (lVar5 == 0x6750)) || (*pcVar2 != '\0')) &&
           ((uVar4 == 0 || (0xfffffffffffff000 < uVar4)))) {
          _printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011c04b,
                  uVar4 & 0xffffffff,puVar7);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011dab7,
                         uVar4 & 0xffffffff,puVar7);
          msleep(500);
          uVar4 = qcom_smem_state_get(*(long *)(param_1 + 8) + 0x10,puVar7,lVar6);
          lVar5 = *(long *)(param_1 + 0x108);
          *puVar1 = uVar4;
          if (((lVar5 == 0x6450) || ((lVar5 == 0x6750 || (*pcVar2 != '\0')))) &&
             ((uVar4 == 0 || (0xfffffffffffff000 < uVar4)))) {
            _printk("%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011c04b,
                    uVar4 & 0xffffffff,puVar7);
            ipc_log_string(icnss_ipc_log_context,
                           "%sicnss2: Failed to get smem state, ret: %d Entry: %s",&DAT_0011dab7,
                           uVar4 & 0xffffffff,puVar7);
            msleep(500);
            uVar4 = qcom_smem_state_get(*(long *)(param_1 + 8) + 0x10,puVar7,lVar6);
            lVar6 = *(long *)(param_1 + 0x108);
            *puVar1 = uVar4;
            if (((lVar6 == 0x6450) || (lVar6 == 0x6750)) || (*pcVar2 != '\0')) {
              if (uVar4 == 0) {
                return;
              }
              if (0xfffffffffffff000 < uVar4) {
                return;
              }
            }
          }
        }
      }
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2: smem state, Entry: %s",puVar7);
  }
  return;
}



//------------------------------------------------------------
// register_fw_error_notifications @ 0010d9ac size=396
// signature: undefined register_fw_error_notifications(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

void register_fw_error_notifications(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 != 0) {
    puVar3 = (undefined8 *)of_find_node_by_name(0,"qcom,smp2p_map_wlan_1_in");
    if (puVar3 == (undefined8 *)0x0) {
      _printk("%sicnss2: Failed to get smp2p node for force-fatal-error\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Failed to get smp2p node for force-fatal-error\n",&DAT_0011dab7);
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2: smp2p node->name=%s\n",*puVar3);
      iVar1 = strcmp("qcom,smp2p_map_wlan_1_in",(char *)*puVar3);
      if (iVar1 == 0) {
        iVar1 = of_irq_get_byname(puVar3,"qcom,smp2p-force-fatal-error");
        if (iVar1 < 0) {
          _printk("%sicnss2: Unable to get force-fatal-error irq %d\n",&DAT_0011c04b,iVar1);
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to get force-fatal-error irq %d\n",
                         &DAT_0011dab7,iVar1);
          return;
        }
      }
      else {
        iVar1 = 0;
      }
      iVar2 = devm_request_threaded_irq
                        (param_1,iVar1,0,fw_error_fatal_handler,0x2001,"wlanfw-err",lVar4);
      if (iVar2 < 0) {
        _printk("%sicnss2: Unable to register for error fatal IRQ handler %d ret = %d",&DAT_0011c04b
                ,iVar1,iVar2);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Unable to register for error fatal IRQ handler %d ret = %d",
                       &DAT_0011dab7,iVar1,iVar2);
      }
      else {
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: FW force error fatal handler registered irq = %d\n",iVar1);
        *(int *)(lVar4 + 0xc10) = iVar1;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// register_early_crash_notifications @ 0010db38 size=396
// signature: undefined register_early_crash_notifications(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

void register_early_crash_notifications(long param_1)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 != 0) {
    puVar3 = (undefined8 *)of_find_node_by_name(0,"qcom,smp2p_map_wlan_1_in");
    if (puVar3 == (undefined8 *)0x0) {
      _printk("%sicnss2: Failed to get smp2p node for early-crash-ind\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Failed to get smp2p node for early-crash-ind\n",&DAT_0011dab7);
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2: smp2p node->name=%s\n",*puVar3);
      iVar1 = strcmp("qcom,smp2p_map_wlan_1_in",(char *)*puVar3);
      if (iVar1 == 0) {
        iVar1 = of_irq_get_byname(puVar3,"qcom,smp2p-early-crash-ind");
        if (iVar1 < 0) {
          _printk("%sicnss2: Unable to get early-crash-ind irq %d\n",&DAT_0011c04b,iVar1);
          ipc_log_string(icnss_ipc_log_context,"%sicnss2: Unable to get early-crash-ind irq %d\n",
                         &DAT_0011dab7,iVar1);
          return;
        }
      }
      else {
        iVar1 = 0;
      }
      iVar2 = devm_request_threaded_irq
                        (param_1,iVar1,0,fw_crash_indication_handler,0x2001,"wlanfw-early-crash-ind"
                         ,lVar4);
      if (iVar2 < 0) {
        _printk("%sicnss2: Unable to register for early crash indication IRQ handler %d ret = %d",
                &DAT_0011c04b,iVar1,iVar2);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2: Unable to register for early crash indication IRQ handler %d ret = %d"
                       ,&DAT_0011dab7,iVar1,iVar2);
      }
      else {
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: FW crash indication handler registered irq = %d\n",iVar1);
        *(int *)(lVar4 + 0xc14) = iVar1;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// fw_soc_wake_ack_handler @ 0010dcc8 size=44
// signature: undefined fw_soc_wake_ack_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 fw_soc_wake_ack_handler(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    complete(param_2 + 0x1660);
  }
  return 1;
}



//------------------------------------------------------------
// fw_error_fatal_handler @ 0010dcf8 size=96
// signature: undefined fw_error_fatal_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 fw_error_fatal_handler(undefined8 param_1,long param_2)

{
  if (param_2 != 0) {
    *(undefined1 *)(param_2 + 0xbd8) = 1;
  }
  _printk("%sicnss2: Received force error fatal request from FW\n",&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Received force error fatal request from FW\n",
                 &DAT_0011dab7);
  return 1;
}



//------------------------------------------------------------
// fw_crash_indication_handler @ 0010dd5c size=392
// signature: undefined fw_crash_indication_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 fw_crash_indication_handler(undefined8 param_1,long param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  code *pcVar5;
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined1 *local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_50[0] = 0;
  _printk("%sicnss2: Received early crash indication from FW\n",&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: Received early crash indication from FW\n",
                 &DAT_0011dab7);
  if (param_2 != 0) {
    if (*(char *)(param_2 + 0x1790) != '\0') {
      mod_timer(param_2 + 0x1758,_jiffies + 0x4e2);
    }
    puVar1 = (ulong *)(param_2 + 0x778);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x2000;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    icnss_ignore_fw_timeout(1);
    if (((uint)*(undefined8 *)(param_2 + 0x778) >> 2 & 1) != 0) {
      puVar1 = (ulong *)(param_2 + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      local_50[0] = 1;
      local_48 = 1;
      if ((*(long *)(param_2 + 0x10) != 0) && (*(long *)(*(long *)(param_2 + 0x10) + 0x120) != 0)) {
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                       *(undefined8 *)(param_2 + 0x778),1);
        pcVar5 = *(code **)(*(long *)(param_2 + 0x10) + 0x120);
        if (*(int *)(pcVar5 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10de74);
          local_40 = local_50;
          (*pcVar5)();
        }
        local_40 = local_50;
        (*pcVar5)(*(long *)(param_2 + 8) + 0x10,&local_48);
      }
    }
  }
  icnss_driver_event_post(param_2,6,0,0);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// icnss_call_driver_probe @ 0010defc size=460
// signature: undefined icnss_call_driver_probe(void)
// callers: [icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

int icnss_call_driver_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  code *pcVar5;
  undefined8 uVar6;
  
  if ((*(long *)(param_1 + 0x10) != 0) && (*(long *)(*(long *)(param_1 + 0x10) + 200) != 0)) {
    if (((uint)*(undefined8 *)(param_1 + 0x778) >> 3 & 1) != 0) {
      return -0x16;
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2: Calling driver probe state: 0x%lx\n");
    icnss_hw_power_on(param_1);
    if (penv != 0) {
      puVar1 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x20000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      *(undefined4 *)(penv + 0xc48) = 0;
    }
    pcVar5 = *(code **)(*(long *)(param_1 + 0x10) + 200);
    if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10df94);
      (*pcVar5)();
    }
    iVar4 = (*pcVar5)(*(long *)(param_1 + 8) + 0x10);
    if (iVar4 == -0x205) {
      pcVar5 = *(code **)(*(long *)(param_1 + 0x10) + 200);
      if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10dfc4);
        (*pcVar5)();
      }
      iVar4 = (*pcVar5)(*(long *)(param_1 + 8) + 0x10);
      uVar6 = 2;
    }
    else {
      uVar6 = 1;
    }
    if (iVar4 < 0) {
      _printk("%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",&DAT_0011c04b,iVar4
              ,*(undefined8 *)(param_1 + 0x778),uVar6);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2: Driver probe failed: %d, state: 0x%lx, probe_cnt: %d\n",
                     &DAT_0011dab7,iVar4,*(undefined8 *)(param_1 + 0x778),uVar6);
      icnss_block_shutdown(0);
      icnss_hw_power_off(param_1);
      return iVar4;
    }
    if (penv != 0) {
      puVar1 = (ulong *)(penv + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffdffff;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      complete(penv + 0xc48);
    }
    puVar1 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 8;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return 0;
}



//------------------------------------------------------------
// icnss_fw_crashed @ 0010e0ec size=552
// signature: undefined icnss_fw_crashed(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

void icnss_fw_crashed(long param_1,long param_2)

{
  ulong *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  ulong uVar7;
  code *pcVar8;
  undefined1 local_50 [8];
  undefined8 local_48;
  undefined1 *local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_50[0] = 0;
  ipc_log_string(icnss_ipc_log_context,"icnss2: FW crashed, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  uVar7 = cpu_latency_qos_request_active(pm_qos_req);
  if ((uVar7 & 1) == 0) {
    cpu_latency_qos_add_request(pm_qos_req,0);
  }
  else {
    cpu_latency_qos_update_request(pm_qos_req,0);
  }
  if ((wlan_pm_qos_update_last_value & 1) == 0) {
    wlan_pm_qos_update_last_value = 1;
    _printk("%sicnss2:  value = %d  ",&DAT_0011c04b,2);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2:  value = %d  ",&DAT_0011dab7,2);
  }
  puVar1 = (ulong *)(param_1 + 0x778);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 | 0x200;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  piVar2 = (int *)(param_1 + 0xba0);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    iVar3 = *piVar2;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = iVar3 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar3 + 1 == 1) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM stay awake, state: 0x%lx, count: %d\n",
                   *(undefined8 *)(param_1 + 0x778),*(undefined4 *)(param_1 + 0xba0));
    pm_stay_awake(*(long *)(param_1 + 8) + 0x10);
    *(int *)(param_1 + 0xa4c) = *(int *)(param_1 + 0xa4c) + 1;
  }
  if ((((uint)*(undefined8 *)(param_1 + 0x778) >> 3 & 1) != 0) &&
     (((uint)*(undefined8 *)(param_1 + 0x778) >> 2 & 1) != 0)) {
    puVar1 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & 0xfffffffffffffffb;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    local_50[0] = 1;
    local_48 = 1;
    if ((*(long *)(param_1 + 0x10) != 0) && (*(long *)(*(long *)(param_1 + 0x10) + 0x120) != 0)) {
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",
                     *(undefined8 *)(param_1 + 0x778),1);
      pcVar8 = *(code **)(*(long *)(param_1 + 0x10) + 0x120);
      if (*(int *)(pcVar8 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x10e258);
        local_40 = local_50;
        (*pcVar8)();
      }
      local_40 = local_50;
      (*pcVar8)(*(long *)(param_1 + 8) + 0x10,&local_48);
    }
  }
  if ((param_2 != 0) && (*(char *)(param_2 + 1) != '\0')) {
    wlfw_rejuvenate_ack_send_sync_msg(param_1);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// icnss_modem_ssr_register_notifier @ 0010e344 size=192
// signature: undefined icnss_modem_ssr_register_notifier(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

void icnss_modem_ssr_register_notifier(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  
  *(undefined4 *)(param_1 + 0xb30) = 1;
  *(code **)(param_1 + 0xb20) = icnss_modem_notifier_nb;
  uVar4 = qcom_register_ssr_notifier(&DAT_0012090e,param_1 + 0xb20);
  *(ulong *)(param_1 + 0xb00) = uVar4;
  if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
    _printk("%sicnss2: Modem register notifier failed: %d\n",&DAT_0011c04b,uVar4 & 0xffffffff);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Modem register notifier failed: %d\n",
                   &DAT_0011dab7,uVar4 & 0xffffffff);
  }
  puVar1 = (ulong *)(param_1 + 0x778);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 0x80;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// icnss_create_ramdump_device @ 0010e410 size=480
// signature: undefined icnss_create_ramdump_device(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * icnss_create_ramdump_device(long param_1,char *param_2)

{
  uint uVar1;
  uint *puVar2;
  ulong uVar3;
  uint *puVar4;
  
  puVar2 = (uint *)kmalloc_trace(___list_add_valid,0xdc0,0x30);
  if (puVar2 == (uint *)0x0) {
    puVar4 = (uint *)0xfffffffffffffff4;
  }
  else if (param_2 == (char *)0x0) {
    _printk("%sicnss2: %s: Invalid device name.\n",&DAT_0011c04b,"icnss_create_ramdump_device");
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: %s: Invalid device name.\n",&DAT_0011dab7,
                   "icnss_create_ramdump_device");
    puVar4 = (uint *)0x0;
  }
  else {
    puVar4 = puVar2 + 1;
    snprintf((char *)puVar4,0x20,"icnss_%s",param_2);
    uVar1 = ida_alloc_range(rd_minor_id,0,0xff,0xcc0);
    *puVar2 = uVar1;
    if ((int)uVar1 < 0) {
      _printk("%sicnss2: %s: No more minor numbers left! rc:%d\n",&DAT_0011c04b,
              "icnss_create_ramdump_device",uVar1);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: %s: No more minor numbers left! rc:%d\n",
                     &DAT_0011dab7,"icnss_create_ramdump_device",uVar1);
      puVar4 = (uint *)0xffffffffffffffed;
    }
    else {
      uVar3 = device_create(*(undefined8 *)(param_1 + 0x1650),0,
                            *(uint *)(param_1 + 0x1658) & 0xfff00000 | uVar1,puVar2,puVar4);
      *(ulong *)(puVar2 + 10) = uVar3;
      if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
        return puVar2;
      }
      _printk("%sicnss2: %s: Device create failed for %s (%d)\n",&DAT_0011c04b,
              "icnss_create_ramdump_device",puVar4,uVar3 & 0xffffffff);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: %s: Device create failed for %s (%d)\n",
                     &DAT_0011dab7,"icnss_create_ramdump_device",puVar4,uVar3 & 0xffffffff);
      ida_free(rd_minor_id,*puVar2);
      puVar4 = (uint *)(long)(int)uVar3;
    }
    kfree(puVar2);
  }
  return puVar4;
}



//------------------------------------------------------------
// icnss_wpss_early_notifier_nb @ 0010e5f4 size=152
// signature: undefined icnss_wpss_early_notifier_nb(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_wpss_early_notifier_nb(long param_1,ulong param_2)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  ulong *puVar4;
  
  if ((param_2 & 0xfffffffc) == 0) {
    pcVar3 = *(char **)((long)&PTR_s_BEFORE_POWERUP_0011ab50 +
                       (-(param_2 >> 0x1f & 1) & 0xfffffff800000000 | (param_2 & 0xffffffff) << 3));
  }
  else {
    pcVar3 = "UNKNOWN";
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: WPSS-EARLY-Notify: event %s(%lu)\n",pcVar3,
                 param_2);
  if (param_2 == 2) {
    puVar4 = (ulong *)(param_1 + -0x3d8);
    Hint_Prefetch(puVar4,2,0,1);
    do {
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(puVar4,0x10);
      if (bVar2) {
        *puVar4 = *puVar4 | 0x2000;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    icnss_ignore_fw_timeout(1);
  }
  return 0;
}



//------------------------------------------------------------
// icnss_wpss_notifier_nb @ 0010e698 size=664
// signature: undefined icnss_wpss_notifier_nb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_wpss_notifier_nb(long param_1,ulong param_2,long param_3)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  ulong *puVar8;
  undefined1 local_50 [8];
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar7 = param_1 + -0xb38;
  local_50[0] = 0;
  if ((param_2 & 0xfffffffc) == 0) {
    pcVar6 = *(char **)((long)&PTR_s_BEFORE_POWERUP_0011ab50 +
                       (-(param_2 >> 0x1f & 1) & 0xfffffff800000000 | (param_2 & 0xffffffff) << 3));
  }
  else {
    pcVar6 = "UNKNOWN";
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: WPSS-Notify: event %s(%lu)\n",pcVar6,param_2);
  if (param_2 == 3) {
    if (*(char *)(param_1 + -0x20) != '\0') {
      _printk("%sicnss2: Collecting msa0 segment dump\n",&DAT_0011e9ea);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Collecting msa0 segment dump\n",&DAT_0011dab7)
      ;
      icnss_msa0_ramdump(lVar7);
      *(undefined1 *)(param_1 + -0x20) = 0;
    }
  }
  else if (param_2 == 2) {
    *(undefined1 *)(param_1 + -0x20) = *(undefined1 *)(param_3 + 8);
    if (*(char *)(param_1 + 0xc58) != '\0') {
      del_timer(param_1 + 0xc20);
    }
    puVar8 = (ulong *)(param_1 + -0x3c0);
    *(undefined1 *)(param_1 + 0x1b2) = 1;
    _printk("%sicnss2: WPSS went down, state: 0x%lx, crashed: %d\n",&DAT_0011e9ea,*puVar8,
            *(undefined1 *)(param_3 + 8));
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: WPSS went down, state: 0x%lx, crashed: %d\n",
                   &DAT_0011dab7,*puVar8,*(undefined1 *)(param_3 + 8));
    if (*(long *)(param_1 + -0xa30) == 0xabcd) {
      icnss_update_state_send_modem_shutdown(lVar7,param_3);
    }
    Hint_Prefetch(puVar8,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar8,0x10);
      if (bVar3) {
        *puVar8 = *puVar8 | 0x2000;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    icnss_ignore_fw_timeout(1);
    lVar1 = -0x110;
    if (*(char *)(param_3 + 8) != '\0') {
      lVar1 = -0x114;
    }
    *(int *)(param_1 + lVar1) = *(int *)(param_1 + lVar1) + 1;
    puVar4 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,2);
    if (puVar4 == (undefined1 *)0x0) {
      uVar5 = 0x800d;
      goto LAB_0010e890;
    }
    local_50[0] = *(undefined1 *)(param_3 + 8);
    *puVar4 = local_50[0];
    if (((uint)*puVar8 >> 2 & 1) != 0) {
      Hint_Prefetch(puVar8,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar8,0x10);
        if (bVar3) {
          *puVar8 = *puVar8 & 0xfffffffffffffffb;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      local_50[0] = *(undefined1 *)(param_3 + 8);
      icnss_call_driver_uevent(lVar7,1,local_50);
    }
    icnss_driver_event_post(lVar7,5,1,puVar4);
    if (*(char *)(param_3 + 8) != '\0') {
      mod_timer(param_1 + 0xbe8,_jiffies + 15000);
    }
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: Exit %s,state: 0x%lx\n",
                 "icnss_wpss_notifier_nb",*(undefined8 *)(param_1 + -0x3c0));
  uVar5 = 1;
LAB_0010e890:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// icnss_msa0_ramdump @ 0010e940 size=360
// signature: undefined icnss_msa0_ramdump(void)
// callers: [icnss_wpss_notifier_nb, icnss_modem_notifier_nb]
//------------------------------------------------------------

void icnss_msa0_ramdump(long param_1)

{
  long lVar1;
  undefined1 *puVar2;
  undefined8 *puVar3;
  int iVar4;
  ulong uVar5;
  undefined *puVar6;
  char *pcVar7;
  ulong uVar8;
  undefined1 **local_70;
  undefined1 **local_68;
  undefined1 *local_60;
  undefined8 *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar8 = *(ulong *)(param_1 + 0xba8);
  uVar5 = dump_enabled();
  if ((uVar5 & 1) == 0) {
    pcVar7 = "%sicnss2: Dump collection is not enabled\n";
    puVar6 = &DAT_0011e9ea;
  }
  else {
    if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) goto LAB_0010ea78;
    uStack_48 = *(undefined8 *)(param_1 + 0x770);
    local_60 = (undefined1 *)0x0;
    local_58 = (undefined8 *)0x0;
    local_40 = (ulong)*(uint *)(param_1 + 0x768);
    local_50 = 0;
    local_70 = (undefined1 **)&local_70;
    local_68 = (undefined1 **)&local_70;
    uVar5 = __list_add_valid(&local_60,&local_70,&local_70);
    if ((uVar5 & 1) != 0) {
      local_70 = &local_60;
      local_68 = &local_60;
      local_60 = (undefined1 *)&local_70;
      local_58 = &local_70;
    }
    if (*(long *)(uVar8 + 0x28) != 0) {
      iVar4 = qcom_dump(&local_70);
      if (iVar4 == 0) {
        uVar5 = __list_del_entry_valid(&local_60);
        puVar3 = local_58;
        puVar2 = local_60;
        if ((uVar5 & 1) != 0) {
          *(undefined8 **)(local_60 + 8) = local_58;
          *puVar3 = puVar2;
        }
      }
      else {
        _printk("%sicnss2: Failed to dump msa0, err = %d\n",&DAT_0011c04b,iVar4);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to dump msa0, err = %d\n",
                       &DAT_0011dab7,iVar4);
      }
      goto LAB_0010ea78;
    }
    pcVar7 = "%sicnss2: Created Dump Device not found\n";
    puVar6 = &DAT_0011c04b;
  }
  _printk(pcVar7,puVar6);
  ipc_log_string(icnss_ipc_log_context,pcVar7,&DAT_0011dab7);
LAB_0010ea78:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// icnss_update_state_send_modem_shutdown @ 0010eaa8 size=296
// signature: undefined icnss_update_state_send_modem_shutdown(void)
// callers: [icnss_wpss_notifier_nb, icnss_modem_notifier_nb]
//------------------------------------------------------------

void icnss_update_state_send_modem_shutdown(long param_1,long param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  
  if (*(char *)(param_2 + 8) == '\0') {
    if ((((*(int *)(param_1 + 0xd00) != 0) &&
         (*(undefined4 *)(param_1 + 0xd00) = 0,
         ((uint)*(undefined8 *)(param_1 + 0x778) >> 9 & 1) == 0)) &&
        (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xb & 1) == 0)) &&
       ((((uint)*(undefined8 *)(param_1 + 0x778) >> 0x11 & 1) == 0 &&
        (*(int *)(param_1 + 0xd04) == 0)))) {
      puVar1 = (ulong *)(param_1 + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffb;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      icnss_driver_event_post(param_1,4,3,0);
    }
    if ((((uint)*(undefined8 *)(param_1 + 0x778) >> 0x11 & 1) != 0) &&
       (lVar5 = wait_for_completion_timeout(param_1 + 0xc48,0xea6), lVar5 == 0)) {
      _printk("%sicnss2: modem block shutdown timeout\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: modem block shutdown timeout\n",&DAT_0011dab7)
      ;
    }
    iVar4 = wlfw_send_modem_shutdown_msg(param_1);
    if (iVar4 < 0) {
      _printk("%sicnss2: Fail to send modem shutdown Indication %d\n",&DAT_0011c04b,iVar4);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Fail to send modem shutdown Indication %d\n",
                     &DAT_0011dab7,iVar4);
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_modem_notifier_nb @ 0010ebe0 size=924
// signature: undefined icnss_modem_notifier_nb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_modem_notifier_nb(long param_1,ulong param_2,long param_3)

{
  long lVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  undefined1 *puVar5;
  char *pcVar6;
  code *pcVar7;
  long lVar8;
  ulong *puVar9;
  undefined1 local_60 [8];
  undefined8 local_58;
  undefined1 *local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = param_1 + -0xb20;
  local_60[0] = 0;
  if ((param_2 & 0xfffffffc) == 0) {
    pcVar6 = *(char **)((long)&PTR_s_BEFORE_POWERUP_0011ab50 +
                       (-(param_2 >> 0x1f & 1) & 0xfffffff800000000 | (param_2 & 0xffffffff) << 3));
  }
  else {
    pcVar6 = "UNKNOWN";
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: Modem-Notify: event %s(%lu)\n",pcVar6,param_2);
  if (param_2 == 3) {
    if (*(char *)(param_3 + 8) != '\0') {
      _printk("%sicnss2: Collecting msa0 segment dump\n",&DAT_0011e9ea);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Collecting msa0 segment dump\n",&DAT_0011dab7)
      ;
      icnss_msa0_ramdump(lVar8);
    }
  }
  else if (param_2 == 2) {
    if (*(char *)(param_1 + 0xbd8) != '\0') {
      complete(param_1 + 0xbe0);
    }
    if ((*(char *)(param_3 + 8) == '\0') && (*(char *)(param_1 + 0xbd1) != '\0')) {
      puVar9 = (ulong *)(param_1 + -0x3a8);
      if (((uint)*puVar9 >> 0x10 & 1) != 0) {
        icnss_driver_event_post(lVar8,7,3,0);
      }
      Hint_Prefetch(puVar9,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
        if (bVar3) {
          *puVar9 = *puVar9 | 0x4000000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    *(undefined1 *)(param_1 + 0x1ca) = 1;
    lVar1 = -0xf8;
    if (*(byte *)(param_3 + 8) != 0) {
      lVar1 = -0xfc;
    }
    *(byte *)(param_1 + 0xac0) = *(byte *)(param_3 + 8) ^ 1;
    *(int *)(param_1 + lVar1) = *(int *)(param_1 + lVar1) + 1;
    icnss_update_state_send_modem_shutdown(lVar8,param_3);
    puVar9 = (ulong *)(param_1 + -0x3a8);
    if (((uint)*puVar9 >> 8 & 1) == 0) {
      _printk("%sicnss2: Modem went down, state: 0x%lx, crashed: %d\n",&DAT_0011e9ea,*puVar9,
              *(undefined1 *)(param_3 + 8));
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Modem went down, state: 0x%lx, crashed: %d\n",
                     &DAT_0011dab7,*puVar9,*(undefined1 *)(param_3 + 8));
      Hint_Prefetch(puVar9,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
        if (bVar3) {
          *puVar9 = *puVar9 | 0x2000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      icnss_ignore_fw_timeout(1);
      puVar5 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,2);
      if (puVar5 == (undefined1 *)0x0) {
        uVar4 = 0x800d;
        goto LAB_0010edd0;
      }
      local_60[0] = *(undefined1 *)(param_3 + 8);
      *puVar5 = local_60[0];
      if (((uint)*puVar9 >> 2 & 1) != 0) {
        Hint_Prefetch(puVar9,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
          if (bVar3) {
            *puVar9 = *puVar9 & 0xfffffffffffffffb;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        local_60[0] = *(undefined1 *)(param_3 + 8);
        icnss_call_driver_uevent(lVar8,1,local_60);
      }
      icnss_driver_event_post(lVar8,5,1,puVar5);
      if (*(char *)(param_3 + 8) != '\0') {
        mod_timer(param_1 + 0xc00,_jiffies + 15000);
      }
    }
    else {
      Hint_Prefetch(puVar9,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
        if (bVar3) {
          *puVar9 = *puVar9 | 0x2000;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      icnss_ignore_fw_timeout(1);
      if (((uint)*puVar9 >> 2 & 1) != 0) {
        Hint_Prefetch(puVar9,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar9,0x10);
          if (bVar3) {
            *puVar9 = *puVar9 & 0xfffffffffffffffb;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        local_60[0] = *(undefined1 *)(param_3 + 8);
        lVar8 = *(long *)(param_1 + -0xb10);
        local_58 = 1;
        if ((lVar8 != 0) && (*(long *)(lVar8 + 0x120) != 0)) {
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2: Calling driver uevent state: 0x%lx, uevent: %d\n",*puVar9,1);
          pcVar7 = *(code **)(*(long *)(param_1 + -0xb10) + 0x120);
          if (*(int *)(pcVar7 + -4) != -0x2ad3b498) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8229,0x10ed9c);
            local_50 = local_60;
            (*pcVar7)();
          }
          local_50 = local_60;
          (*pcVar7)(*(long *)(param_1 + -0xb18) + 0x10,&local_58);
        }
      }
    }
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: Exit %s,state: 0x%lx\n",
                 "icnss_modem_notifier_nb",*(undefined8 *)(param_1 + -0x3a8));
  uVar4 = 1;
LAB_0010edd0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// icnss_pdr_notifier_cb @ 0010efa8 size=656
// signature: undefined icnss_pdr_notifier_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_pdr_notifier_cb(int param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  undefined1 *puVar5;
  long lVar6;
  undefined *puVar7;
  bool bVar8;
  undefined1 uVar9;
  undefined1 local_60 [8];
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_60[0] = 0;
  if (param_3 != 0) {
    puVar1 = (ulong *)(param_3 + 0x778);
    ipc_log_string(icnss_ipc_log_context,"icnss2: PD service notification: 0x%x state: 0x%lx\n",
                   param_1,*(undefined8 *)(param_3 + 0x778));
    if (param_1 == 0x1fffffff) {
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar8) {
          *puVar1 = *puVar1 & 0xffffffffffffdfff;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
    }
    else if ((param_1 == 0xfffffff) &&
            (puVar5 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,2),
            puVar5 != (undefined1 *)0x0)) {
      cVar3 = *(char *)(param_3 + 0xcea);
      *puVar5 = 1;
      if (cVar3 == '\0') {
        puVar2 = (ulong *)(penv + 0x778);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          cVar3 = '\x01';
          bVar8 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar8) {
            *puVar2 = *puVar2 | 0x40000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (((uint)*puVar1 >> 0xc & 1) == 0) {
          bVar8 = false;
          lVar6 = 0;
          uVar9 = 1;
          *(int *)(param_3 + 0xa1c) = *(int *)(param_3 + 0xa1c) + 1;
        }
        else {
          bVar8 = false;
          uVar9 = 1;
          lVar6 = 3;
          *(int *)(param_3 + 0xa20) = *(int *)(param_3 + 0xa20) + 1;
        }
      }
      else if (*(char *)(param_3 + 0x15e0) == '\0') {
        bVar8 = false;
        uVar9 = 1;
        lVar6 = 1;
      }
      else {
        uVar9 = 0;
        bVar8 = true;
        lVar6 = 2;
        *puVar5 = 0;
      }
      puVar7 = (&icnss_pdr_cause)[lVar6];
      _printk("%sicnss2: PD service down, state: 0x%lx: cause: %s\n",&DAT_0011e9ea,*puVar1,puVar7);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: PD service down, state: 0x%lx: cause: %s\n",
                     &DAT_0011dab7,*puVar1,puVar7);
      if (((uint)*puVar1 >> 0xd & 1) == 0) {
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 0x2000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        icnss_ignore_fw_timeout(1);
        if (((uint)*puVar1 >> 2 & 1) != 0) {
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar4) {
              *puVar1 = *puVar1 & 0xfffffffffffffffb;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          local_60[0] = uVar9;
          icnss_call_driver_uevent(param_3,1,local_60);
        }
      }
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar4) {
          *puVar1 = *puVar1 & 0xffffffffffffefff;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      if (!bVar8) {
        mod_timer(param_3 + 0x1720,_jiffies + 15000);
      }
      icnss_driver_event_post(param_3,5,1,puVar5);
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
// qdss_tr_start_store @ 0010f274 size=68
// signature: undefined qdss_tr_start_store(void)
// callers: []
//------------------------------------------------------------

undefined8
qdss_tr_start_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  wlfw_qdss_trace_start(*(undefined8 *)(param_1 + 0x98));
  ipc_log_string(icnss_ipc_log_context,"icnss2: Received QDSS start command\n");
  return param_4;
}



//------------------------------------------------------------
// qdss_tr_stop_store @ 0010f2bc size=164
// signature: undefined qdss_tr_stop_store(void)
// callers: []
//------------------------------------------------------------

undefined8 qdss_tr_stop_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uVar3 = *(undefined8 *)(param_1 + 0x98);
  local_2c = 0;
  iVar2 = sscanf(param_3,"%du",&local_2c);
  if (iVar2 == 1) {
    wlfw_qdss_trace_stop(uVar3,local_2c);
    ipc_log_string(icnss_ipc_log_context,"icnss2: Received QDSS stop command\n");
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
// qdss_conf_download_store @ 0010f364 size=68
// signature: undefined qdss_conf_download_store(void)
// callers: []
//------------------------------------------------------------

undefined8
qdss_conf_download_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  icnss_wlfw_qdss_dnld_send_sync(*(undefined8 *)(param_1 + 0x98));
  ipc_log_string(icnss_ipc_log_context,"icnss2: Received QDSS download config command\n");
  return param_4;
}



//------------------------------------------------------------
// hw_trc_override_store @ 0010f3ac size=160
// signature: undefined hw_trc_override_store(void)
// callers: []
//------------------------------------------------------------

undefined8 hw_trc_override_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  long lVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar2 = sscanf(param_3,"%du",&local_2c);
  uVar1 = icnss_ipc_log_context;
  if (iVar2 == 1) {
    *(undefined4 *)(lVar3 + 0x15bc) = local_2c;
    ipc_log_string(uVar1,"icnss2: Received QDSS hw_trc_override indication\n");
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wpss_boot_store @ 0010f450 size=320
// signature: undefined wpss_boot_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 wpss_boot_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined *puVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  if ((*(char *)(lVar3 + 0x16f0) != '\0') || (*(char *)(lVar3 + 0x17a0) != '\0')) {
    iVar2 = sscanf(param_3,"%du",&local_2c);
    if (iVar2 == 1) {
      puVar1 = &DAT_00121828;
      if (local_2c != 0) {
        puVar1 = &DAT_00123b3c;
      }
      ipc_log_string(icnss_ipc_log_context,"icnss2: WPSS Remote Processor: %s",puVar1);
      if (local_2c == 0) {
        if ((lVar3 != 0) && (*(long *)(lVar3 + 0xcf8) != 0)) {
          rproc_shutdown();
          rproc_put(*(undefined8 *)(lVar3 + 0xcf8));
          *(undefined8 *)(lVar3 + 0xcf8) = 0;
        }
      }
      else if (local_2c == 1) {
        queue_work_on(0x20,_system_wq,&wpss_loader);
      }
    }
    else {
      _printk("%sicnss2: Failed to read wpss rproc info",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to read wpss rproc info",&DAT_0011dab7)
      ;
      param_4 = 0xffffffffffffffea;
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
// wlan_en_delay_store @ 0010f594 size=228
// signature: undefined wlan_en_delay_store(void)
// callers: []
//------------------------------------------------------------

undefined8 wlan_en_delay_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  if (*(long *)(lVar2 + 0x108) != 0xabcd) {
    iVar1 = sscanf(param_3,"%du",&local_2c);
    if (iVar1 == 1) {
      ipc_log_string(icnss_ipc_log_context,"icnss2: WLAN_EN delay: %dms",local_2c);
      *(undefined4 *)(lVar2 + 0x1648) = local_2c;
    }
    else {
      _printk("%sicnss2: Failed to read wlan_en_delay",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2: Failed to read wlan_en_delay",&DAT_0011dab7);
      param_4 = 0xffffffffffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// icnss_sysfs_store @ 0010f67c size=152
// signature: undefined icnss_sysfs_store(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_sysfs_store(void)

{
  char *pcVar1;
  long lVar2;
  undefined8 in_x3;
  
  lVar2 = penv;
  if (penv != 0) {
    pcVar1 = (char *)(penv + 0x16f0);
    ipc_log_string(icnss_ipc_log_context,"icnss2: Received shutdown indication");
    *(undefined4 *)(lVar2 + 0xd00) = 1;
    if ((((*pcVar1 != '\0') || (*(char *)(lVar2 + 0x17a0) != '\0')) &&
        (*(long *)(lVar2 + 0x108) == 0xabcd)) && (*(long *)(lVar2 + 0xcf8) != 0)) {
      rproc_shutdown();
      rproc_put(*(undefined8 *)(lVar2 + 0xcf8));
      *(undefined8 *)(lVar2 + 0xcf8) = 0;
    }
  }
  return in_x3;
}



//------------------------------------------------------------
// rproc_restart_level_notifier @ 0010f718 size=240
// signature: undefined rproc_restart_level_notifier(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rproc_restart_level_notifier(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  size_t sVar2;
  long lVar3;
  byte *pbVar4;
  char *pcVar5;
  
  pcVar5 = *(char **)(param_2 + 0x18);
  sVar2 = strlen(pcVar5);
  _printk("%sicnss2: rproc name: %s(%zu) recovery disable: %d",&DAT_0011e9ea,pcVar5,sVar2,
          *(undefined1 *)(param_2 + 0x4c4));
  uVar1 = icnss_ipc_log_context;
  pcVar5 = *(char **)(param_2 + 0x18);
  sVar2 = strlen(pcVar5);
  ipc_log_string(uVar1,"%sicnss2: rproc name: %s(%zu) recovery disable: %d",&DAT_0011dab7,pcVar5,
                 sVar2,*(undefined1 *)(param_2 + 0x4c4));
  pcVar5 = *(char **)(param_2 + 0x18);
  sVar2 = strlen(pcVar5);
  lVar3 = strnstr(pcVar5,&DAT_00120417,sVar2);
  if ((lVar3 != 0) &&
     (pbVar4 = (byte *)kmalloc_trace(___list_add_valid,0xb20,1), uVar1 = penv, pbVar4 != (byte *)0x0
     )) {
    *pbVar4 = *(byte *)(param_2 + 0x4c4) ^ 1;
    icnss_driver_event_post(uVar1,0x11,0);
  }
  return;
}



//------------------------------------------------------------
// icnss_pm_suspend @ 0010f80c size=420
// signature: undefined icnss_pm_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_suspend(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  code *pcVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x98);
  if (*piVar6 != 0x5abc5abc) {
    _printk("%sicnss2: Invalid drvdata for pm suspend: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar6);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for pm suspend: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar6,*piVar6);
    return 0xffffffea;
  }
  ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM Suspend, state: 0x%lx\n",
                 *(undefined8 *)(piVar6 + 0x1de));
  if ((*(long *)(piVar6 + 4) != 0) &&
     (pcVar5 = *(code **)(*(long *)(piVar6 + 4) + 0xf0), pcVar5 != (code *)0x0)) {
    if ((*(long *)(piVar6 + 0x42) == 0x6450) ||
       ((*(long *)(piVar6 + 0x42) == 0x6750 || ((char)piVar6[0x5bc] != '\0')))) {
      if (*(ulong *)(piVar6 + 0x308) == 0) {
        return 0;
      }
      if (0xfffffffffffff000 < *(ulong *)(piVar6 + 0x308)) {
        return 0;
      }
    }
    if (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 3 & 1) != 0) {
      if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10f8dc);
        (*pcVar5)();
      }
      uVar4 = (*pcVar5)(param_1);
      if ((int)uVar4 != 0) {
        piVar6[0x28c] = piVar6[0x28c] + 1;
        return uVar4;
      }
      if ((*(long *)(piVar6 + 0x42) == 0x6750) || (*(long *)(piVar6 + 0x42) == 0x6450)) {
        if (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 9 & 1) != 0) {
          return 0;
        }
        if (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 0x10 & 1) == 0) {
          return 0;
        }
        uVar4 = icnss_send_smp2p(piVar6,1,0);
      }
      else {
        uVar4 = 0;
      }
      piVar6[0x28b] = piVar6[0x28b] + 1;
      puVar1 = (ulong *)(piVar6 + 0x1de);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 | 0x20;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      return uVar4;
    }
  }
  return 0;
}



//------------------------------------------------------------
// icnss_pm_resume @ 0010f9c4 size=352
// signature: undefined icnss_pm_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_resume(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  code *pcVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x98);
  if (*piVar6 == 0x5abc5abc) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM resume, state: 0x%lx\n",
                   *(undefined8 *)(piVar6 + 0x1de));
    if ((((*(long *)(piVar6 + 4) != 0) &&
         (pcVar5 = *(code **)(*(long *)(piVar6 + 4) + 0xf8), pcVar5 != (code *)0x0)) &&
        (((*(long *)(piVar6 + 0x42) != 0x6450 &&
          ((*(long *)(piVar6 + 0x42) != 0x6750 && ((char)piVar6[0x5bc] == '\0')))) ||
         ((*(ulong *)(piVar6 + 0x308) != 0 && (*(ulong *)(piVar6 + 0x308) < 0xfffffffffffff001))))))
       && (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 3 & 1) != 0)) {
      if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10fa78);
        (*pcVar5)();
      }
      uVar4 = (*pcVar5)(param_1);
      if ((int)uVar4 != 0) {
        piVar6[0x28e] = piVar6[0x28e] + 1;
        return uVar4;
      }
    }
    piVar6[0x28d] = piVar6[0x28d] + 1;
    puVar1 = (ulong *)(piVar6 + 0x1de);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffffffdf;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    uVar4 = 0;
  }
  else {
    _printk("%sicnss2: Invalid drvdata for pm resume: dev %pK, data %pK, magic 0x%x\n",&DAT_0011c04b
            ,param_1,piVar6);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for pm resume: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar6,*piVar6);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// icnss_pm_suspend_noirq @ 0010fb34 size=292
// signature: undefined icnss_pm_suspend_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_suspend_noirq(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  code *pcVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x98);
  if (*piVar6 == 0x5abc5abc) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM suspend_noirq, state: 0x%lx\n",
                   *(undefined8 *)(piVar6 + 0x1de));
    if (((*(long *)(piVar6 + 4) != 0) &&
        (pcVar5 = *(code **)(*(long *)(piVar6 + 4) + 0x100), pcVar5 != (code *)0x0)) &&
       (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 3 & 1) != 0)) {
      if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10fbb0);
        (*pcVar5)();
      }
      uVar4 = (*pcVar5)(param_1);
      if ((int)uVar4 != 0) {
        piVar6[0x290] = piVar6[0x290] + 1;
        return uVar4;
      }
    }
    piVar6[0x28f] = piVar6[0x28f] + 1;
    puVar1 = (ulong *)(piVar6 + 0x1de);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x40;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    uVar4 = 0;
  }
  else {
    _printk("%sicnss2: Invalid drvdata for pm suspend_noirq: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar6);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for pm suspend_noirq: dev %pK, data %pK, magic 0x%x\n"
                   ,&DAT_0011dab7,param_1,piVar6,*piVar6);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// icnss_pm_resume_noirq @ 0010fc68 size=296
// signature: undefined icnss_pm_resume_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_resume_noirq(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  code *pcVar5;
  int *piVar6;
  
  piVar6 = *(int **)(param_1 + 0x98);
  if (*piVar6 == 0x5abc5abc) {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: PM resume_noirq, state: 0x%lx\n",
                   *(undefined8 *)(piVar6 + 0x1de));
    if (((*(long *)(piVar6 + 4) != 0) &&
        (pcVar5 = *(code **)(*(long *)(piVar6 + 4) + 0x108), pcVar5 != (code *)0x0)) &&
       (((uint)*(undefined8 *)(piVar6 + 0x1de) >> 3 & 1) != 0)) {
      if (*(int *)(pcVar5 + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10fce4);
        (*pcVar5)();
      }
      uVar4 = (*pcVar5)(param_1);
      if ((int)uVar4 != 0) {
        piVar6[0x292] = piVar6[0x292] + 1;
        return uVar4;
      }
    }
    piVar6[0x291] = piVar6[0x291] + 1;
    puVar1 = (ulong *)(piVar6 + 0x1de);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffffffbf;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    uVar4 = 0;
  }
  else {
    _printk("%sicnss2: Invalid drvdata for pm resume_noirq: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar6);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for pm resume_noirq: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar6,*piVar6);
    uVar4 = 0xffffffea;
  }
  return uVar4;
}



//------------------------------------------------------------
// icnss_pm_runtime_suspend @ 0010fda0 size=392
// signature: undefined icnss_pm_runtime_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_runtime_suspend(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x98);
  lVar3 = *(long *)(piVar4 + 0x42);
  if (lVar3 == 0xabcd) {
    _printk("%sicnss2: Ignore runtime suspend:\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Ignore runtime suspend:\n",&DAT_0011dab7);
    uVar2 = 0;
  }
  else if (*piVar4 == 0x5abc5abc) {
    if ((*(long *)(piVar4 + 4) != 0) && (*(long *)(*(long *)(piVar4 + 4) + 0x110) != 0)) {
      if ((lVar3 == 0x6450) || ((lVar3 == 0x6750 || ((char)piVar4[0x5bc] != '\0')))) {
        if (*(ulong *)(piVar4 + 0x308) == 0) {
          return 0;
        }
        if (0xfffffffffffff000 < *(ulong *)(piVar4 + 0x308)) {
          return 0;
        }
      }
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: Runtime suspend\n");
      if (*(int *)(*(code **)(*(long *)(piVar4 + 4) + 0x110) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10fe60);
        (*pcVar1)();
      }
      uVar2 = (**(code **)(*(long *)(piVar4 + 4) + 0x110))(param_1);
      if ((int)uVar2 != 0) {
        return uVar2;
      }
      if ((((uint)*(undefined8 *)(piVar4 + 0x1de) >> 9 & 1) == 0) &&
         (((uint)*(undefined8 *)(piVar4 + 0x1de) >> 0x10 & 1) != 0)) {
        uVar2 = icnss_send_smp2p(piVar4,1,0);
        return uVar2;
      }
    }
    uVar2 = 0;
  }
  else {
    _printk("%sicnss2: Invalid drvdata for runtime suspend: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar4);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for runtime suspend: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar4,*piVar4);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_pm_runtime_resume @ 0010ff2c size=360
// signature: undefined icnss_pm_runtime_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_runtime_resume(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x98);
  lVar3 = *(long *)(piVar4 + 0x42);
  if (lVar3 == 0xabcd) {
    _printk("%sicnss2: Ignore runtime resume\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Ignore runtime resume\n",&DAT_0011dab7);
    uVar2 = 0;
  }
  else if (*piVar4 == 0x5abc5abc) {
    if ((*(long *)(piVar4 + 4) == 0) || (*(long *)(*(long *)(piVar4 + 4) + 0x118) == 0)) {
      uVar2 = 0;
    }
    else {
      if (((lVar3 == 0x6450) || (lVar3 == 0x6750)) || ((char)piVar4[0x5bc] != '\0')) {
        if (*(ulong *)(piVar4 + 0x308) == 0) {
          return 0;
        }
        if (0xfffffffffffff000 < *(ulong *)(piVar4 + 0x308)) {
          return 0;
        }
      }
      ipc_log_string(icnss_ipc_log_long_context,"icnss2: Runtime resume, state: 0x%lx\n",
                     *(undefined8 *)(piVar4 + 0x1de));
      if (*(int *)(*(code **)(*(long *)(piVar4 + 4) + 0x118) + -4) != 0x3f45655f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10fff0);
        (*pcVar1)();
      }
      uVar2 = (**(code **)(*(long *)(piVar4 + 4) + 0x118))(param_1);
    }
  }
  else {
    _printk("%sicnss2: Invalid drvdata for runtime resume: dev %pK, data %pK, magic 0x%x\n",
            &DAT_0011c04b,param_1,piVar4);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2: Invalid drvdata for runtime resume: dev %pK, data %pK, magic 0x%x\n",
                   &DAT_0011dab7,param_1,piVar4,*piVar4);
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// icnss_pm_runtime_idle @ 00110098 size=144
// signature: undefined icnss_pm_runtime_idle(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_pm_runtime_idle(long param_1)

{
  if (*(long *)(*(long *)(param_1 + 0x98) + 0x108) == 0xabcd) {
    _printk("%sicnss2: Ignore runtime idle\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2: Ignore runtime idle\n",&DAT_0011dab7);
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,"icnss2: Runtime idle\n");
    __pm_runtime_suspend(param_1,9);
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// icnss_get_vreg @ 00110140 size=1036
// signature: undefined icnss_get_vreg(void)
// callers: [icnss_probe]
//------------------------------------------------------------

ulong icnss_get_vreg(long param_1)

{
  undefined **ppuVar1;
  undefined *puVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  uint *puVar6;
  uint uVar7;
  long lVar8;
  undefined **ppuVar9;
  long lVar10;
  int iVar11;
  undefined8 *puVar12;
  long *plVar13;
  long lVar14;
  char *pcVar15;
  long local_a0;
  uint local_8c;
  char local_88 [32];
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  lVar10 = *(long *)(param_1 + 0x108);
  lVar8 = *(long *)(param_1 + 8);
  if (lVar10 == 0x6450) {
    local_a0 = 5;
    ppuVar9 = &icnss_wcn6450_vreg_list;
  }
  else if (lVar10 == 0x6750) {
    local_a0 = 4;
    ppuVar9 = &icnss_wcn6750_vreg_list;
  }
  else {
    if (lVar10 != 0xabcd) {
      _printk("%sUnsupported device_id 0x%lx\n",&DAT_0011c04b,lVar10);
      ipc_log_string(icnss_ipc_log_context,"%sUnsupported device_id 0x%lx\n",&DAT_0011dab7,lVar10);
      uVar5 = 0xffffffea;
      goto LAB_00110490;
    }
    local_a0 = 5;
    ppuVar9 = &icnss_adrestea_vreg_list;
  }
  lVar10 = 0;
  do {
    plVar4 = (long *)devm_kmalloc(lVar8 + 0x10,0x40,0xdc0);
    if (plVar4 == (long *)0x0) {
      uVar5 = 0xfffffff4;
      goto LAB_00110490;
    }
    lVar14 = *(long *)(param_1 + 8);
    local_88[0x10] = '\0';
    local_88[0x11] = '\0';
    local_88[0x12] = '\0';
    local_88[0x13] = '\0';
    local_88[0x14] = '\0';
    local_88[0x15] = '\0';
    local_88[0x16] = '\0';
    local_88[0x17] = '\0';
    local_88[0x18] = '\0';
    local_88[0x19] = '\0';
    local_88[0x1a] = '\0';
    local_88[0x1b] = '\0';
    local_88[0x1c] = '\0';
    local_88[0x1d] = '\0';
    local_88[0x1e] = '\0';
    local_88[0x1f] = '\0';
    ppuVar1 = ppuVar9 + lVar10 * 4;
    local_88[0] = '\0';
    local_88[1] = '\0';
    local_88[2] = '\0';
    local_88[3] = '\0';
    local_88[4] = '\0';
    local_88[5] = '\0';
    local_88[6] = '\0';
    local_88[7] = '\0';
    local_88[8] = '\0';
    local_88[9] = '\0';
    local_88[10] = '\0';
    local_88[0xb] = '\0';
    local_88[0xc] = '\0';
    local_88[0xd] = '\0';
    local_88[0xe] = '\0';
    local_88[0xf] = '\0';
    local_8c = 0;
    puVar2 = ppuVar1[1];
    plVar13 = plVar4 + 3;
    *plVar13 = (long)*ppuVar1;
    plVar4[4] = (long)puVar2;
    puVar2 = ppuVar1[3];
    plVar4[5] = (long)ppuVar1[2];
    plVar4[6] = (long)puVar2;
    uVar5 = devm_regulator_get_optional(lVar14 + 0x10,*plVar13);
    if (uVar5 < 0xfffffffffffff001) {
      plVar4[2] = uVar5;
      snprintf(local_88,0x20,"qcom,%s-config",(char *)plVar4[3]);
      puVar6 = (uint *)of_get_property(*(undefined8 *)(lVar14 + 0x2f8),local_88,&local_8c);
      ipc_log_string(icnss_ipc_log_context,"Got regulator config, prop: %s, len: %d\n",local_88,
                     local_8c);
      if ((puVar6 == (uint *)0x0) || (local_8c < 8)) {
        pcVar15 = "doesn\'t exist";
        if (puVar6 != (uint *)0x0) {
          pcVar15 = "invalid format";
        }
        ipc_log_string(icnss_ipc_log_context,"Property %s %s, use default\n",local_88,pcVar15);
      }
      else {
        iVar11 = 0;
        uVar7 = local_8c;
        do {
          switch(iVar11) {
          case 0:
            uVar3 = (*puVar6 & 0xff00ff00) >> 8 | (*puVar6 & 0xff00ff) << 8;
            *(uint *)(plVar4 + 4) = uVar3 >> 0x10 | uVar3 << 0x10;
            break;
          case 1:
            uVar3 = (puVar6[1] & 0xff00ff00) >> 8 | (puVar6[1] & 0xff00ff) << 8;
            *(uint *)((long)plVar4 + 0x24) = uVar3 >> 0x10 | uVar3 << 0x10;
            break;
          case 2:
            uVar3 = (puVar6[2] & 0xff00ff00) >> 8 | (puVar6[2] & 0xff00ff) << 8;
            *(uint *)(plVar4 + 5) = uVar3 >> 0x10 | uVar3 << 0x10;
            break;
          case 3:
            uVar3 = (puVar6[3] & 0xff00ff00) >> 8 | (puVar6[3] & 0xff00ff) << 8;
            *(uint *)((long)plVar4 + 0x2c) = uVar3 >> 0x10 | uVar3 << 0x10;
            break;
          case 4:
            if (*(long *)(param_1 + 0x108) == 0x6750) {
              uVar3 = (puVar6[4] & 0xff00ff00) >> 8 | (puVar6[4] & 0xff00ff) << 8;
              *(uint *)(plVar4 + 6) = uVar3 >> 0x10 | uVar3 << 0x10;
            }
            else {
              *(undefined4 *)(plVar4 + 6) = 0;
            }
            break;
          default:
            ipc_log_string(icnss_ipc_log_context,"Property %s, ignoring value at %d\n",local_88,
                           iVar11);
            uVar7 = local_8c;
          }
          iVar11 = iVar11 + 1;
        } while ((ulong)((long)iVar11 * 4) < (ulong)(long)(int)uVar7);
      }
LAB_001103e4:
      ipc_log_string(icnss_ipc_log_context,
                     "Got regulator: %s, min_uv: %u, max_uv: %u, load_ua: %u, delay_us: %u, need_unvote: %u\n"
                     ,plVar4[3],(int)plVar4[4],*(undefined4 *)((long)plVar4 + 0x24),(int)plVar4[5],
                     *(undefined4 *)((long)plVar4 + 0x2c),(int)plVar4[6]);
LAB_00110404:
      puVar12 = *(undefined8 **)(param_1 + 0xe0);
      uVar5 = __list_add_valid(plVar4,puVar12,param_1 + 0xd8);
      if ((uVar5 & 1) != 0) {
        *(long **)(param_1 + 0xe0) = plVar4;
        *plVar4 = param_1 + 0xd8;
        plVar4[1] = (long)puVar12;
        *puVar12 = plVar4;
      }
    }
    else {
      iVar11 = (int)uVar5;
      if (iVar11 != -0x13) {
        if (iVar11 == -0x205) {
          _printk("%sEPROBE_DEFER for regulator: %s\n",&DAT_0011e9ea,*plVar13);
          ipc_log_string(icnss_ipc_log_context,"%sEPROBE_DEFER for regulator: %s\n",&DAT_0011dab7,
                         *plVar13);
          uVar5 = 0xfffffdfb;
          goto LAB_00110490;
        }
        if (*(long *)(param_1 + 0x108) == 0xabcd) {
          if (*(char *)((long)plVar4 + 0x34) == '\0') {
            ipc_log_string(icnss_ipc_log_context,"Optional regulator %s doesn\'t exist: %d\n",
                           *plVar13,uVar5 & 0xffffffff);
            goto LAB_001103e4;
          }
          pcVar15 = "%sRegulator %s doesn\'t exist: %d\n";
        }
        else {
          pcVar15 = "%sFailed to get regulator %s, err = %d\n";
        }
        _printk(pcVar15,&DAT_0011c04b,*plVar13,uVar5 & 0xffffffff);
        ipc_log_string(icnss_ipc_log_context,pcVar15,&DAT_0011dab7,*plVar13,uVar5 & 0xffffffff);
        if (iVar11 != -0x13) {
          if (iVar11 == 0) goto LAB_00110404;
          goto LAB_00110490;
        }
      }
    }
    lVar10 = lVar10 + 1;
  } while (lVar10 != local_a0);
  uVar5 = 0;
LAB_00110490:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_put_vreg @ 00110550 size=116
// signature: undefined icnss_put_vreg(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_put_vreg(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  plVar4 = (long *)(param_1 + 0xd8);
  plVar5 = (long *)*plVar4;
  while (plVar5 != plVar4) {
    uVar3 = __list_del_entry_valid(plVar5);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar5;
      plVar2 = (long *)plVar5[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar5 = -0x2152ffffffffff00;
    plVar5[1] = -0x2152fffffffffede;
    plVar5 = (long *)*plVar4;
  }
  return;
}



//------------------------------------------------------------
// icnss_vreg_unvote @ 001105c8 size=376
// signature: undefined icnss_vreg_unvote(void)
// callers: [icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

undefined8 icnss_vreg_unvote(long param_1)

{
  int iVar1;
  long lVar2;
  
  for (lVar2 = *(long *)(param_1 + 0xe0); lVar2 != param_1 + 0xd8; lVar2 = *(long *)(lVar2 + 8)) {
    if (((*(ulong *)(lVar2 + 0x10) != 0) && (*(ulong *)(lVar2 + 0x10) < 0xfffffffffffff001)) &&
       (*(int *)(lVar2 + 0x30) != 0)) {
      if (*(int *)(lVar2 + 0x38) == 0) {
        ipc_log_string(icnss_ipc_log_context,"Regulator %s is already disabled\n",
                       *(undefined8 *)(lVar2 + 0x18));
      }
      else {
        ipc_log_string(icnss_ipc_log_context,"Removing vote for Regulator %s\n",
                       *(undefined8 *)(lVar2 + 0x18));
        if ((*(int *)(lVar2 + 0x28) == 0) ||
           (iVar1 = regulator_set_load(*(undefined8 *)(lVar2 + 0x10),0), -1 < iVar1)) {
          iVar1 = *(int *)(lVar2 + 0x20);
        }
        else {
          _printk("%sFailed to set load for regulator %s, err = %d\n",&DAT_0011c04b,
                  *(undefined8 *)(lVar2 + 0x18),iVar1);
          ipc_log_string(icnss_ipc_log_context,"%sFailed to set load for regulator %s, err = %d\n",
                         &DAT_0011dab7,*(undefined8 *)(lVar2 + 0x18),iVar1);
          iVar1 = *(int *)(lVar2 + 0x20);
        }
        if (((iVar1 != 0) && (*(int *)(lVar2 + 0x24) != 0)) &&
           (iVar1 = regulator_set_voltage(*(undefined8 *)(lVar2 + 0x10),0), iVar1 != 0)) {
          _printk("%sFailed to set voltage for regulator %s, err = %d\n",&DAT_0011c04b,
                  *(undefined8 *)(lVar2 + 0x18),iVar1);
          ipc_log_string(icnss_ipc_log_context,
                         "%sFailed to set voltage for regulator %s, err = %d\n",&DAT_0011dab7,
                         *(undefined8 *)(lVar2 + 0x18),iVar1);
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// icnss_get_clk @ 00110744 size=520
// signature: undefined icnss_get_clk(void)
// callers: [icnss_probe]
//------------------------------------------------------------

ulong icnss_get_clk(long param_1)

{
  long *plVar1;
  undefined *puVar2;
  long *plVar3;
  undefined8 *puVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  undefined **ppuVar9;
  undefined8 *puVar10;
  
  if (param_1 == 0) {
    uVar5 = 0xffffffed;
    goto LAB_00110850;
  }
  lVar7 = *(long *)(param_1 + 0x108);
  plVar1 = (long *)(param_1 + 0xe8);
  if (lVar7 == 0x6450) {
LAB_00110794:
    ppuVar9 = &icnss_clk_list;
LAB_001107b0:
    if ((long *)*plVar1 == plVar1) {
      puVar4 = (undefined8 *)devm_kmalloc(*(long *)(param_1 + 8) + 0x10,0x30,0xdc0);
      if (puVar4 == (undefined8 *)0x0) {
        uVar5 = 0xfffffff4;
LAB_00110870:
        plVar8 = (long *)*plVar1;
        while (plVar8 != plVar1) {
          uVar6 = __list_del_entry_valid(plVar8);
          if ((uVar6 & 1) != 0) {
            lVar7 = *plVar8;
            plVar3 = (long *)plVar8[1];
            *(long **)(lVar7 + 8) = plVar3;
            *plVar3 = lVar7;
          }
          *plVar8 = -0x2152ffffffffff00;
          plVar8[1] = -0x2152fffffffffede;
          plVar8 = (long *)*plVar1;
        }
      }
      else {
        lVar7 = *(long *)(param_1 + 8);
        puVar2 = ppuVar9[1];
        puVar10 = puVar4 + 3;
        *puVar10 = *ppuVar9;
        puVar4[4] = puVar2;
        uVar5 = devm_clk_get(lVar7 + 0x10);
        if (uVar5 < 0xfffffffffffff001) {
          puVar4[2] = uVar5;
          ipc_log_string(icnss_ipc_log_context,"Got clock: %s, freq: %u\n",puVar4[3],
                         *(undefined4 *)(puVar4 + 4));
        }
        else {
          if (*(int *)((long)puVar4 + 0x24) == 0) {
            ipc_log_string(icnss_ipc_log_context,"Failed to get optional clock %s, err = %d\n",
                           *puVar10,uVar5 & 0xffffffff);
          }
          else {
            _printk("%sFailed to get clock %s, err = %d\n",&DAT_0011c04b,*puVar10,uVar5 & 0xffffffff
                   );
            ipc_log_string(icnss_ipc_log_context,"%sFailed to get clock %s, err = %d\n",
                           &DAT_0011dab7,*puVar10,uVar5 & 0xffffffff);
          }
          if ((int)uVar5 != 0) {
            if (*(int *)((long)puVar4 + 0x24) == 0) goto LAB_0011084c;
            goto LAB_00110870;
          }
        }
        puVar10 = *(undefined8 **)(param_1 + 0xf0);
        uVar6 = __list_add_valid(puVar4,puVar10,plVar1);
        uVar5 = 0;
        if ((uVar6 & 1) != 0) {
          *(undefined8 **)(param_1 + 0xf0) = puVar4;
          *puVar4 = plVar1;
          puVar4[1] = puVar10;
          *puVar10 = puVar4;
        }
      }
      goto LAB_00110850;
    }
LAB_00110838:
    ipc_log_string(icnss_ipc_log_context,"Clocks have already been updated\n");
  }
  else {
    if (lVar7 == 0xabcd) {
      ppuVar9 = (undefined **)icnss_adrestea_clk_list;
      goto LAB_001107b0;
    }
    if (lVar7 == 0x6750) goto LAB_00110794;
    if ((long *)*plVar1 != plVar1) goto LAB_00110838;
  }
LAB_0011084c:
  uVar5 = 0;
LAB_00110850:
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// icnss_put_clk @ 00110950 size=120
// signature: undefined icnss_put_clk(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_put_clk(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  if (param_1 != 0) {
    plVar4 = (long *)(param_1 + 0xe8);
    plVar5 = (long *)*plVar4;
    while (plVar5 != plVar4) {
      uVar3 = __list_del_entry_valid(plVar5);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar5;
        plVar2 = (long *)plVar5[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar5 = -0x2152ffffffffff00;
      plVar5[1] = -0x2152fffffffffede;
      plVar5 = (long *)*plVar4;
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_hw_power_on @ 001109cc size=852
// signature: undefined icnss_hw_power_on(void)
// callers: [icnss_driver_event_work, icnss_power_on, icnss_wlan_enable, icnss_call_driver_probe, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

int icnss_hw_power_on(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 *puVar8;
  long *plVar9;
  long *plVar10;
  
  ipc_log_string(icnss_ipc_log_context,"HW Power on: state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  lVar7 = param_1 + 0x8b8;
  _raw_spin_lock(lVar7);
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 1 & 1) == 0) {
    puVar1 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 2;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    _raw_spin_unlock(lVar7);
    puVar8 = (undefined8 *)(param_1 + 0xd8);
    for (puVar5 = (undefined8 *)*puVar8; puVar5 != puVar8; puVar5 = (undefined8 *)*puVar5) {
      if ((((puVar5[2] != 0) && ((ulong)puVar5[2] < 0xfffffffffffff001)) &&
          (*(char *)((long)puVar5 + 0x35) != '\0')) &&
         (iVar4 = icnss_vreg_on_single(puVar5), iVar4 != 0)) goto LAB_00110a74;
    }
    plVar9 = (long *)(param_1 + 0xe8);
    for (plVar10 = (long *)*plVar9; plVar10 != plVar9; plVar10 = (long *)*plVar10) {
      if ((plVar10[2] != 0) && ((ulong)plVar10[2] < 0xfffffffffffff001)) {
        if (*(int *)(plVar10 + 5) == 0) {
          ipc_log_string(icnss_ipc_log_context,"Clock %s is being enabled\n",plVar10[3]);
          if ((*(int *)(plVar10 + 4) == 0) || (iVar4 = clk_set_rate(plVar10[2]), iVar4 == 0)) {
            uVar6 = plVar10[2];
            iVar4 = clk_prepare(uVar6);
            if (iVar4 == 0) {
              iVar4 = clk_enable(uVar6);
              if (iVar4 == 0) {
                *(undefined4 *)(plVar10 + 5) = 1;
                goto LAB_00110ae0;
              }
              clk_unprepare(uVar6);
            }
            _printk("%sFailed to enable clock %s, err = %d\n",&DAT_0011c04b,plVar10[3],iVar4);
            ipc_log_string(icnss_ipc_log_context,"%sFailed to enable clock %s, err = %d\n",
                           &DAT_0011dab7,plVar10[3],iVar4);
          }
          else {
            _printk("%sFailed to set frequency %u for clock %s, err = %d\n",&DAT_0011c04b,
                    *(undefined4 *)(plVar10 + 4),plVar10[3],iVar4);
            ipc_log_string(icnss_ipc_log_context,
                           "%sFailed to set frequency %u for clock %s, err = %d\n",&DAT_0011dab7,
                           *(undefined4 *)(plVar10 + 4),plVar10[3],iVar4);
          }
          for (plVar10 = (long *)plVar10[1]; plVar10 != plVar9; plVar10 = (long *)plVar10[1]) {
            if ((plVar10[2] != 0) && ((ulong)plVar10[2] < 0xfffffffffffff001)) {
              if ((int)plVar10[5] == 0) {
                ipc_log_string(icnss_ipc_log_context,"Clock %s is already disabled\n",plVar10[3]);
              }
              else {
                ipc_log_string(icnss_ipc_log_context,"Clock %s is being disabled\n",plVar10[3]);
                lVar7 = plVar10[2];
                clk_disable(lVar7);
                clk_unprepare(lVar7);
                *(undefined4 *)(plVar10 + 5) = 0;
              }
            }
          }
          for (puVar5 = *(undefined8 **)(param_1 + 0xe0); puVar5 != puVar8;
              puVar5 = (undefined8 *)puVar5[1]) {
            if ((puVar5[2] != 0) && ((ulong)puVar5[2] < 0xfffffffffffff001)) {
              icnss_vreg_off_single(puVar5);
            }
          }
          goto LAB_00110ba8;
        }
        ipc_log_string(icnss_ipc_log_context,"Clock %s is already enabled\n",plVar10[3]);
      }
LAB_00110ae0:
    }
  }
  else {
    _raw_spin_unlock(lVar7);
  }
  return 0;
LAB_00110a74:
  while (puVar5 = (undefined8 *)puVar5[1], puVar5 != puVar8) {
    if (((puVar5[2] != 0) && ((ulong)puVar5[2] < 0xfffffffffffff001)) && (*(int *)(puVar5 + 7) != 0)
       ) {
      icnss_vreg_off_single(puVar5);
    }
  }
  _printk("%sFailed to turn on vreg, err = %d\n",&DAT_0011c04b,iVar4);
  ipc_log_string(icnss_ipc_log_context,"%sFailed to turn on vreg, err = %d\n",&DAT_0011dab7,iVar4);
LAB_00110ba8:
  puVar1 = (ulong *)(param_1 + 0x778);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 & 0xfffffffffffffffd;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return iVar4;
}



//------------------------------------------------------------
// icnss_hw_power_off @ 00110d40 size=348
// signature: undefined icnss_hw_power_off(void)
// callers: [icnss_driver_event_work, icnss_wlan_enable, icnss_power_off, icnss_remove, icnss_call_driver_probe, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

undefined8 icnss_hw_power_off(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (((*(ulong *)(param_1 + 0x120) & 1) == 0) &&
     (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) == 0)) {
    ipc_log_string(icnss_ipc_log_context,"HW Power off: 0x%lx\n");
    lVar5 = param_1 + 0x8b8;
    _raw_spin_lock(lVar5);
    if (((uint)*(undefined8 *)(param_1 + 0x778) >> 1 & 1) == 0) {
      _raw_spin_unlock(lVar5);
    }
    else {
      puVar1 = (ulong *)(param_1 + 0x778);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffffd;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      _raw_spin_unlock(lVar5);
      for (lVar5 = *(long *)(param_1 + 0xf0); lVar5 != param_1 + 0xe8; lVar5 = *(long *)(lVar5 + 8))
      {
        if ((*(ulong *)(lVar5 + 0x10) != 0) && (*(ulong *)(lVar5 + 0x10) < 0xfffffffffffff001)) {
          if (*(int *)(lVar5 + 0x28) == 0) {
            ipc_log_string(icnss_ipc_log_context,"Clock %s is already disabled\n",
                           *(undefined8 *)(lVar5 + 0x18));
          }
          else {
            ipc_log_string(icnss_ipc_log_context,"Clock %s is being disabled\n",
                           *(undefined8 *)(lVar5 + 0x18));
            uVar4 = *(undefined8 *)(lVar5 + 0x10);
            clk_disable(uVar4);
            clk_unprepare(uVar4);
            *(undefined4 *)(lVar5 + 0x28) = 0;
          }
        }
      }
      for (lVar5 = *(long *)(param_1 + 0xe0); lVar5 != param_1 + 0xd8; lVar5 = *(long *)(lVar5 + 8))
      {
        if ((*(ulong *)(lVar5 + 0x10) != 0) && (*(ulong *)(lVar5 + 0x10) < 0xfffffffffffff001)) {
          icnss_vreg_off_single(lVar5);
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// icnss_power_on @ 00110eac size=148
// signature: undefined icnss_power_on(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_power_on(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    _printk("%sInvalid drvdata: dev %pK, data %pK\n",&DAT_0011c04b,param_1,0);
    ipc_log_string(icnss_ipc_log_context,"%sInvalid drvdata: dev %pK, data %pK\n",&DAT_0011dab7,
                   param_1,0);
    uVar1 = 0xffffffea;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"Power On: 0x%lx\n",*(undefined8 *)(lVar2 + 0x778));
    uVar1 = icnss_hw_power_on(lVar2);
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_power_off @ 00110f44 size=152
// signature: undefined icnss_power_off(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_power_off(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 == 0) {
    _printk("%sInvalid drvdata: dev %pK, data %pK\n",&DAT_0011c04b,param_1,0);
    ipc_log_string(icnss_ipc_log_context,"%sInvalid drvdata: dev %pK, data %pK\n",&DAT_0011dab7,
                   param_1,0);
    uVar1 = 0xffffffea;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"Power Off: 0x%lx\n",*(undefined8 *)(lVar2 + 0x778));
    icnss_hw_power_off(lVar2);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// icnss_power_on_chain1_reg @ 00110fe0 size=156
// signature: undefined icnss_power_on_chain1_reg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

undefined8 icnss_power_on_chain1_reg(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long *plVar3;
  long *plVar4;
  
  plVar4 = (long *)(param_1 + 0xd8);
  plVar3 = (long *)*plVar4;
  if (plVar3 != plVar4) {
    do {
      iVar1 = strcmp("vdd-3.3-ch1",(char *)plVar3[3]);
      if ((iVar1 == 0) && (*(char *)(param_1 + 0x15b8) != '\0')) {
        *(undefined1 *)((long)plVar3 + 0x35) = 1;
        uVar2 = icnss_vreg_on_single(plVar3);
        goto LAB_0011105c;
      }
      plVar3 = (long *)*plVar3;
    } while (plVar3 != plVar4);
  }
  uVar2 = 0;
LAB_0011105c:
  *(undefined1 *)(param_1 + 0x15b8) = 0;
  return uVar2;
}



//------------------------------------------------------------
// icnss_vreg_on_single @ 0011107c size=400
// signature: undefined icnss_vreg_on_single(void)
// callers: [icnss_hw_power_on, icnss_power_on_chain1_reg]
//------------------------------------------------------------

int icnss_vreg_on_single(long param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    ipc_log_string(icnss_ipc_log_context,"Regulator %s is being enabled\n",
                   *(undefined8 *)(param_1 + 0x18));
    if (((*(int *)(param_1 + 0x20) == 0) || (*(int *)(param_1 + 0x24) == 0)) ||
       (iVar1 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x10)), iVar1 == 0)) {
      if ((*(int *)(param_1 + 0x28) == 0) ||
         (iVar1 = regulator_set_load(*(undefined8 *)(param_1 + 0x10)), -1 < iVar1)) {
        if (*(int *)(param_1 + 0x2c) != 0) {
          __udelay();
        }
        iVar1 = regulator_enable(*(undefined8 *)(param_1 + 0x10));
        if (iVar1 == 0) {
          *(undefined4 *)(param_1 + 0x38) = 1;
        }
        else {
          _printk("%sFailed to enable regulator %s, err = %d\n",&DAT_0011c04b,
                  *(undefined8 *)(param_1 + 0x18),iVar1);
          ipc_log_string(icnss_ipc_log_context,"%sFailed to enable regulator %s, err = %d\n",
                         &DAT_0011dab7,*(undefined8 *)(param_1 + 0x18),iVar1);
        }
      }
      else {
        _printk("%sFailed to set load for regulator %s, load: %u, err = %d\n",&DAT_0011c04b,
                *(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x28),iVar1);
        ipc_log_string(icnss_ipc_log_context,
                       "%sFailed to set load for regulator %s, load: %u, err = %d\n",&DAT_0011dab7,
                       *(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x28),iVar1);
      }
    }
    else {
      _printk("%sFailed to set voltage for regulator %s, min_uv: %u, max_uv: %u, err = %d\n",
              &DAT_0011c04b,*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),
              *(undefined4 *)(param_1 + 0x24),iVar1);
      ipc_log_string(icnss_ipc_log_context,
                     "%sFailed to set voltage for regulator %s, min_uv: %u, max_uv: %u, err = %d\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 0x18),*(undefined4 *)(param_1 + 0x20),
                     *(undefined4 *)(param_1 + 0x24),iVar1);
    }
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"Regulator %s is already enabled\n",
                   *(undefined8 *)(param_1 + 0x18));
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// icnss_put_resources @ 00111210 size=172
// signature: undefined icnss_put_resources(void)
// callers: [icnss_probe, icnss_remove]
//------------------------------------------------------------

void icnss_put_resources(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  if (param_1 != 0) {
    plVar5 = (long *)(param_1 + 0xe8);
    plVar4 = (long *)*plVar5;
    while (plVar4 != plVar5) {
      uVar3 = __list_del_entry_valid(plVar4);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar4;
        plVar2 = (long *)plVar4[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      plVar4 = (long *)*plVar5;
    }
  }
  plVar4 = (long *)(param_1 + 0xd8);
  plVar5 = (long *)*plVar4;
  while (plVar5 != plVar4) {
    uVar3 = __list_del_entry_valid(plVar5);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar5;
      plVar2 = (long *)plVar5[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar5 = -0x2152ffffffffff00;
    plVar5[1] = -0x2152fffffffffede;
    plVar5 = (long *)*plVar4;
  }
  return;
}



//------------------------------------------------------------
// icnss_aop_interface_init @ 001112c0 size=408
// signature: undefined icnss_aop_interface_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

int icnss_aop_interface_init(long param_1)

{
  int iVar1;
  ulong uVar2;
  char *pcVar3;
  
  iVar1 = of_property_read_string
                    (*(undefined8 *)(*(long *)(param_1 + 8) + 0x2f8),"qcom,vreg_ol_cpr",
                     param_1 + 0xf8);
  if ((iVar1 == 0) || (*(long *)(param_1 + 0x1638) != 0)) {
    *(undefined1 *)(param_1 + 0x1600) = 0;
    *(undefined8 *)(param_1 + 0x15f8) = 1000;
    *(long *)(param_1 + 0x15e8) = *(long *)(param_1 + 8) + 0x10;
    *(undefined1 *)(param_1 + 0x15f0) = 1;
    *(undefined8 *)(param_1 + 0x1620) = 0;
    *(undefined8 *)(param_1 + 0x1628) = 0;
    *(undefined1 *)(param_1 + 0x1630) = 0;
    uVar2 = mbox_request_channel(param_1 + 0x15e8,0);
    if (uVar2 < 0xfffffffffffff001) {
      pcVar3 = "Mbox channel initialized\n";
      *(ulong *)(param_1 + 0x1620) = uVar2;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"Failed to get mbox channel with err %d\n");
      uVar2 = qmp_get(*(long *)(param_1 + 8) + 0x10);
      *(ulong *)(param_1 + 0x1628) = uVar2;
      if (0xfffffffffffff000 < uVar2) {
        _printk("%sFailed to get qmp\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sFailed to get qmp\n",&DAT_0011dab7);
        return *(int *)(param_1 + 0x1628);
      }
      pcVar3 = "QMP initialized\n";
      *(undefined1 *)(param_1 + 0x1630) = 1;
    }
    ipc_log_string(icnss_ipc_log_context,pcVar3);
    iVar1 = icnss_aop_pdc_reconfig(param_1);
    if (iVar1 != 0) {
      _printk("%sFailed to reconfig WLAN PDC, err = %d\n",&DAT_0011c04b,iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sFailed to reconfig WLAN PDC, err = %d\n",&DAT_0011dab7
                     ,iVar1);
    }
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"Vreg for OL CPR and pdc_init table not configured\n");
    iVar1 = -0x16;
  }
  return iVar1;
}



//------------------------------------------------------------
// icnss_aop_pdc_reconfig @ 0011145c size=452
// signature: undefined icnss_aop_pdc_reconfig(void)
// callers: [icnss_aop_interface_init]
//------------------------------------------------------------

int icnss_aop_pdc_reconfig(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_78 = 0;
  local_70 = 0;
  if (((*(int *)(param_1 + 0x1640) < 1) || (*(long *)(param_1 + 0x1638) == 0)) ||
     (ipc_log_string(icnss_ipc_log_context,"Setting PDC defaults for device ID: (0x%lx)\n",
                     *(undefined8 *)(param_1 + 0x108)), *(int *)(param_1 + 0x1640) == 0)) {
    iVar2 = 0;
  }
  else {
    uVar3 = 0;
    do {
      uVar4 = *(undefined8 *)(*(long *)(param_1 + 0x1638) + uVar3 * 8);
      if (*(char *)(param_1 + 0x1630) == '\0') {
        ipc_log_string(icnss_ipc_log_context,"Sending AOP Mbox msg: %s\n",uVar4);
        local_78 = CONCAT44(local_78._4_4_,0x40);
        local_70 = uVar4;
        iVar2 = mbox_send_message(*(undefined8 *)(param_1 + 0x1620),&local_78);
        if (-1 < iVar2) goto LAB_0011157c;
        _printk("%sFailed to send AOP mbox msg: %s,ret: %d\n",&DAT_0011c04b,uVar4,iVar2);
        ipc_log_string(icnss_ipc_log_context,"%sFailed to send AOP mbox msg: %s,ret: %d\n",
                       &DAT_0011dab7,uVar4,iVar2);
      }
      else {
        ipc_log_string(icnss_ipc_log_context,"Sending AOP QMP msg: %s\n",uVar4);
        iVar2 = qmp_send(*(undefined8 *)(param_1 + 0x1628),uVar4,0x40);
        if (iVar2 < 0) {
          _printk("%sFailed to send AOP QMP msg: %s\n",&DAT_0011c04b,uVar4);
          ipc_log_string(icnss_ipc_log_context,"%sFailed to send AOP QMP msg: %s\n",&DAT_0011dab7,
                         uVar4);
        }
        else {
LAB_0011157c:
          iVar2 = 0;
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x1640));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_aop_interface_deinit @ 00111624 size=84
// signature: undefined icnss_aop_interface_deinit(void)
// callers: [icnss_remove]
//------------------------------------------------------------

void icnss_aop_interface_deinit(long param_1)

{
  if ((*(ulong *)(param_1 + 0x1620) != 0) && (*(ulong *)(param_1 + 0x1620) < 0xfffffffffffff001)) {
    mbox_free_channel();
  }
  if ((*(ulong *)(param_1 + 0x1628) != 0) && (*(ulong *)(param_1 + 0x1628) < 0xfffffffffffff001)) {
    qmp_put();
    *(undefined1 *)(param_1 + 0x1630) = 0;
  }
  return;
}



//------------------------------------------------------------
// icnss_power_misc_params_init @ 0011167c size=216
// signature: undefined icnss_power_misc_params_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_power_misc_params_init(long param_1)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 8);
  uVar1 = of_property_read_string_helper(*(undefined8 *)(lVar5 + 0x2f8),"qcom,pdc_init_table",0,0,0)
  ;
  *(uint *)(param_1 + 0x1640) = uVar1;
  if ((int)uVar1 < 1) {
    ipc_log_string(icnss_ipc_log_context,"PDC Init Table not configured\n");
  }
  else {
    lVar3 = __kmalloc((ulong)uVar1 << 3,0xdc0);
    *(long *)(param_1 + 0x1638) = lVar3;
    if (lVar3 == 0) {
      pcVar4 = "%sFailed to alloc PDC Init Table mem\n";
    }
    else {
      iVar2 = of_property_read_string_helper
                        (*(undefined8 *)(lVar5 + 0x2f8),"qcom,pdc_init_table",lVar3,
                         (long)*(int *)(param_1 + 0x1640),0);
      if (-1 < iVar2) {
        return;
      }
      pcVar4 = "%sFailed to get PDC Init Table\n";
    }
    _printk(pcVar4,&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7);
  }
  return;
}



//------------------------------------------------------------
// icnss_update_cpr_info @ 00111758 size=536
// signature: undefined icnss_update_cpr_info(void)
// callers: [wlfw_cap_send_sync_msg]
//------------------------------------------------------------

int icnss_update_cpr_info(long param_1)

{
  long lVar1;
  int iVar2;
  uint param6;
  undefined8 local_88;
  char *local_80;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((*(char **)(param_1 + 0xf8) == (char *)0x0) ||
     ((*(long *)(param_1 + 0x1620) == 0 && (*(char *)(param_1 + 0x1630) == '\0')))) {
    ipc_log_string(icnss_ipc_log_context,"Mbox channel / QMP / OL CPR Vreg not configured\n");
  }
  else {
    param6 = *(uint *)(param_1 + 0x100);
    if (param6 == 0) {
      _printk("%sVoltage %dmV is not valid\n",&DAT_0011c04b,0);
      ipc_log_string(icnss_ipc_log_context,"%sVoltage %dmV is not valid\n",&DAT_0011dab7,
                     *(undefined4 *)(param_1 + 0x100));
      iVar2 = -0x16;
      goto LAB_001118b8;
    }
    if (*(long *)(param_1 + 0x108) != 0x6450) {
      if (param6 < 0x3b7) {
        param6 = 0x3b6;
      }
      *(uint *)(param_1 + 0x100) = param6;
    }
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
    local_88 = 0x40;
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
    snprintf(local_78,0x40,"{class: wlan_pdc, res: %s.%s, %s: %d}",*(char **)(param_1 + 0xf8),"v",
             "upval",param6);
    if (*(char *)(param_1 + 0x1630) == '\0') {
      ipc_log_string(icnss_ipc_log_context,"Sending AOP Mbox msg: %s\n",local_78);
      local_80 = local_78;
      iVar2 = mbox_send_message(*(undefined8 *)(param_1 + 0x1620),&local_88);
      if (iVar2 < 0) {
        _printk("%sFailed to send AOP mbox msg: %s,ret: %d\n",&DAT_0011c04b,local_78,iVar2);
        ipc_log_string(icnss_ipc_log_context,"%sFailed to send AOP mbox msg: %s,ret: %d\n",
                       &DAT_0011dab7,local_78,iVar2);
        goto LAB_001118b8;
      }
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"Sending AOP QMP msg: %s\n",local_78);
      iVar2 = qmp_send(*(undefined8 *)(param_1 + 0x1628),local_78,0x40);
      if (iVar2 < 0) {
        _printk("%sFailed to send AOP QMP msg: %s\n",&DAT_0011c04b,local_78);
        ipc_log_string(icnss_ipc_log_context,"%sFailed to send AOP QMP msg: %s\n",&DAT_0011dab7,
                       local_78);
        goto LAB_001118b8;
      }
    }
  }
  iVar2 = 0;
LAB_001118b8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_get_psf_info @ 00111974 size=272
// signature: undefined icnss_get_psf_info(void)
// callers: [icnss_probe]
//------------------------------------------------------------

int icnss_get_psf_info(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = alloc_workqueue("icnss_soc_update",2,1);
  *(long *)(param_1 + 0x16e0) = lVar2;
  if (lVar2 == 0) {
    _printk("%sWorkqueue creation failed for soc update\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sWorkqueue creation failed for soc update\n",
                   &DAT_0011dab7);
    iVar1 = -0xe;
  }
  else {
    *(code **)(param_1 + 0x1688) = icnss_battery_supply_callback;
    iVar1 = power_supply_reg_notifier(param_1 + 0x1688);
    if (iVar1 < 0) {
      _printk("%sPower supply framework registration err: %d\n",&DAT_0011c04b,iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sPower supply framework registration err: %d\n",
                     &DAT_0011dab7,iVar1);
      destroy_workqueue(*(undefined8 *)(param_1 + 0x16e0));
    }
    else {
      iVar1 = 0;
      *(undefined8 *)(param_1 + 0x16b0) = 0xfffffffe0;
      *(long *)(param_1 + 0x16b8) = param_1 + 0x16b8;
      *(long *)(param_1 + 0x16c0) = param_1 + 0x16b8;
      *(code **)(param_1 + 0x16c8) = icnss_update_soc_level;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// icnss_battery_supply_callback @ 00111a88 size=100
// signature: undefined icnss_battery_supply_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 icnss_battery_supply_callback(long param_1,undefined8 param_2,undefined8 *param_3)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)*param_3,"battery");
  if (((iVar1 == 0) && ((*(ulong *)(param_1 + -0xf10) & 1) != 0)) &&
     (((uint)*(ulong *)(param_1 + -0xf10) >> 0xd & 1) == 0)) {
    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x58),param_1 + 0x28);
  }
  return 1;
}



//------------------------------------------------------------
// icnss_update_soc_level @ 00111af0 size=484
// signature: undefined icnss_update_soc_level(void)
// callers: []
//------------------------------------------------------------

void icnss_update_soc_level(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + -0x10);
  local_40 = 0;
  if (lVar3 == 0) {
    lVar3 = power_supply_get_by_name("battery");
    *(long *)(param_1 + -0x10) = lVar3;
    if (lVar3 != 0) goto LAB_00111b40;
    iVar1 = 0;
LAB_00111b54:
    _printk("%sBattery Percentage: %d\n",&DAT_0011e9ea,iVar1);
    ipc_log_string(icnss_ipc_log_context,"%sBattery Percentage: %d\n",&DAT_0011dab7,iVar1);
    if ((iVar1 == 0) || (100 < iVar1)) goto LAB_00111c00;
    if (iVar1 < 0x46) {
      if (iVar1 < 0x3c) {
        if (iVar1 < 0x32) {
          if (iVar1 < 0x19) {
            if (iVar1 < 0) goto LAB_00111c84;
            lVar3 = 4;
          }
          else {
            lVar3 = 3;
          }
        }
        else {
          lVar3 = 2;
        }
      }
      else {
        lVar3 = 1;
      }
    }
    else {
      lVar3 = 0;
    }
    iVar1 = *(int *)(icnss_battery_level + lVar3 * 8 + 4);
    if (*(int *)(param_1 + -8) == iVar1) goto LAB_00111c84;
    iVar2 = icnss_send_vbatt_update(param_1 + -0x16b0,(long)iVar1);
    if (-1 < iVar2) {
      *(int *)(param_1 + -8) = iVar1;
      goto LAB_00111c84;
    }
    pcVar4 = "%sUnable to update ldo voltage";
    _printk("%sUnable to update ldo voltage",&DAT_0011c04b);
  }
  else {
LAB_00111b40:
    iVar1 = power_supply_get_property(lVar3,0x2f,&local_40);
    if (iVar1 == 0) {
      iVar1 = (int)local_40;
      goto LAB_00111b54;
    }
    _printk("%sbattery percentage read error:%d\n",&DAT_0011c04b,iVar1);
    ipc_log_string(icnss_ipc_log_context,"%sbattery percentage read error:%d\n",&DAT_0011dab7,iVar1)
    ;
LAB_00111c00:
    pcVar4 = "%sBattery percentage read failure\n";
    _printk("%sBattery percentage read failure\n",&DAT_0011c04b);
  }
  ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7);
LAB_00111c84:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// icnss_vreg_off_single @ 00111cd4 size=376
// signature: undefined icnss_vreg_off_single(void)
// callers: [icnss_hw_power_off, icnss_hw_power_on]
//------------------------------------------------------------

void icnss_vreg_off_single(long param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x38) == 0) {
    ipc_log_string(icnss_ipc_log_context,"Regulator %s is already disabled\n",
                   *(undefined8 *)(param_1 + 0x18));
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"Regulator %s is being disabled\n",
                   *(undefined8 *)(param_1 + 0x18));
    iVar1 = regulator_disable(*(undefined8 *)(param_1 + 0x10));
    if (iVar1 == 0) {
      iVar1 = *(int *)(param_1 + 0x28);
    }
    else {
      _printk("%sFailed to disable regulator %s, err = %d\n",&DAT_0011c04b,
              *(undefined8 *)(param_1 + 0x18),iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sFailed to disable regulator %s, err = %d\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 0x18),iVar1);
      iVar1 = *(int *)(param_1 + 0x28);
    }
    if ((iVar1 != 0) && (iVar1 = regulator_set_load(*(undefined8 *)(param_1 + 0x10),0), iVar1 < 0))
    {
      _printk("%sFailed to set load for regulator %s, err = %d\n",&DAT_0011c04b,
              *(undefined8 *)(param_1 + 0x18),iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sFailed to set load for regulator %s, err = %d\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 0x18),iVar1);
    }
    if (((*(int *)(param_1 + 0x20) != 0) && (*(int *)(param_1 + 0x24) != 0)) &&
       (iVar1 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x10),0), iVar1 != 0)) {
      _printk("%sFailed to set voltage for regulator %s, err = %d\n",&DAT_0011c04b,
              *(undefined8 *)(param_1 + 0x18),iVar1);
      ipc_log_string(icnss_ipc_log_context,"%sFailed to set voltage for regulator %s, err = %d\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 0x18),iVar1);
    }
    *(undefined4 *)(param_1 + 0x38) = 0;
  }
  return;
}



//------------------------------------------------------------
// icnss_ignore_fw_timeout @ 00111e50 size=4
// signature: undefined icnss_ignore_fw_timeout(void)
// callers: [icnss_driver_event_work, icnss_pdr_notifier_cb, icnss_wpss_notifier_nb, icnss_wpss_early_notifier_nb, icnss_modem_notifier_nb, fw_crash_indication_handler]
//------------------------------------------------------------

void icnss_ignore_fw_timeout(void)

{
  return;
}



//------------------------------------------------------------
// wlfw_msa_mem_info_send_sync_msg @ 00111e58 size=960
// signature: undefined wlfw_msa_mem_info_send_sync_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_msa_mem_info_send_sync_msg(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  uint uVar3;
  long lVar4;
  ushort uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 *puVar8;
  ushort *puVar9;
  ulong uVar10;
  ulong uVar11;
  ulong *puVar12;
  size_t __n;
  char *pcVar13;
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
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar7 = -0x13;
    goto LAB_001121a0;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending MSA mem info, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  puVar8 = (undefined8 *)kmalloc_trace(___list_add_valid,0xdc0,0x10);
  if (puVar8 == (undefined8 *)0x0) {
    iVar7 = -0xc;
    goto LAB_001121a0;
  }
  puVar9 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,0x28);
  if (puVar9 == (ushort *)0x0) {
    kfree(puVar8);
    iVar7 = -0xc;
    goto LAB_001121a0;
  }
  iVar7 = *(int *)(param_1 + 0xa60);
  uVar2 = *(undefined4 *)(param_1 + 0x768);
  *puVar8 = *(undefined8 *)(param_1 + 0x750);
  *(undefined4 *)(puVar8 + 1) = uVar2;
  *(int *)(param_1 + 0xa60) = iVar7 + 1;
  iVar7 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_msa_info_resp_msg_v01_ei,puVar9);
  if (iVar7 < 0) {
    pcVar13 = "%sicnss2_qmi: fatal: Fail to init txn for MSA Mem info resp %d\n";
LAB_00112114:
    _printk(pcVar13,&DAT_0011c04b,iVar7);
    ipc_log_string(icnss_ipc_log_context,pcVar13,&DAT_0011dab7,iVar7);
  }
  else {
    iVar7 = qmi_send_request(param_1 + 0x248,0,&local_90,0x2d,0x12,&wlfw_msa_info_req_msg_v01_ei,
                             puVar8);
    if (iVar7 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar13 = "%sicnss2_qmi: fatal: Fail to send MSA Mem info req %d\n";
      goto LAB_00112114;
    }
    iVar7 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar7 < 0) {
      pcVar13 = "%sicnss2_qmi: fatal: MSA Mem info resp wait failed ret %d\n";
      goto LAB_00112114;
    }
    if (*puVar9 == 0) {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Receive mem_region_info_len: %d\n",
                     *(undefined4 *)(puVar9 + 2));
      uVar3 = *(uint *)(puVar9 + 2);
      if (uVar3 < 3) {
        *(uint *)(param_1 + 0x848) = uVar3;
        *(int *)(param_1 + 0xa64) = *(int *)(param_1 + 0xa64) + 1;
        if (uVar3 == 0) goto LAB_00112078;
        uVar3 = *(uint *)(puVar9 + 8);
        uVar11 = (ulong)uVar3;
        puVar12 = (ulong *)(puVar9 + 4);
        if (*(uint *)(param_1 + 0x768) < uVar3) {
LAB_001120b0:
          __n = 0;
        }
        else {
          uVar10 = *puVar12;
          uVar1 = *(ulong *)(param_1 + 0x750) + (ulong)*(uint *)(param_1 + 0x768);
          if (uVar1 <= uVar10) goto LAB_001120b0;
          __n = 0;
          if ((*(ulong *)(param_1 + 0x750) <= uVar10) && (uVar10 + uVar11 <= uVar1)) {
            uVar5 = puVar9[10];
            *(ulong *)(param_1 + 0x850) = uVar10;
            *(uint *)(param_1 + 0x858) = uVar3;
            *(char *)(param_1 + 0x85c) = (char)uVar5;
            ipc_log_string(icnss_ipc_log_context,
                           "icnss2_qmi: Memory Region: %d Addr: 0x%llx Size: 0x%x Flag: 0x%08x\n",0)
            ;
            if (1 < *(uint *)(puVar9 + 2)) {
              uVar3 = *(uint *)(puVar9 + 0x10);
              uVar11 = (ulong)uVar3;
              puVar12 = (ulong *)(puVar9 + 0xc);
              if ((((*(uint *)(param_1 + 0x768) < uVar3) || (uVar10 = *puVar12, uVar1 <= uVar10)) ||
                  (uVar10 < *(ulong *)(param_1 + 0x750))) || (uVar1 < uVar10 + uVar11)) {
                __n = 0x10;
                goto LAB_001120b4;
              }
              uVar5 = puVar9[0x12];
              *(ulong *)(param_1 + 0x860) = uVar10;
              *(uint *)(param_1 + 0x868) = uVar3;
              *(char *)(param_1 + 0x86c) = (char)uVar5;
              ipc_log_string(icnss_ipc_log_context,
                             "icnss2_qmi: Memory Region: %d Addr: 0x%llx Size: 0x%x Flag: 0x%08x\n",
                             1);
              if (2 < *(uint *)(puVar9 + 2)) {
                    /* WARNING: Does not return */
                pcVar6 = (code *)SoftwareBreakpoint(1,0x112218);
                (*pcVar6)();
              }
            }
LAB_00112078:
            kfree(puVar9);
            kfree(puVar8);
            iVar7 = 0;
            goto LAB_001121a0;
          }
        }
LAB_001120b4:
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2_qmi: Received out of range Addr: 0x%llx Size: 0x%x\n",*puVar12,uVar11
                      );
        memset((void *)(param_1 + 0x850),0,__n);
      }
      else {
        _printk("%sicnss2_qmi: fatal: Invalid memory region length received: %d\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: fatal: Invalid memory region length received: %d\n",
                       &DAT_0011dab7,*(undefined4 *)(puVar9 + 2));
      }
      iVar7 = -0x16;
    }
    else {
      _printk("%sicnss2_qmi: fatal: QMI MSA Mem info request rejected, result:%d error:%d\n",
              &DAT_0011c04b,*puVar9,puVar9[1]);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: fatal: QMI MSA Mem info request rejected, result:%d error:%d\n",
                     &DAT_0011dab7,*puVar9,puVar9[1]);
      iVar7 = -(uint)*puVar9;
    }
  }
  kfree(puVar9);
  kfree(puVar8);
  *(int *)(param_1 + 0xa68) = *(int *)(param_1 + 0xa68) + 1;
LAB_001121a0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// wlfw_msa_ready_send_sync_msg @ 0011221c size=568
// signature: undefined wlfw_msa_ready_send_sync_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_msa_ready_send_sync_msg(long param_1)

{
  int iVar1;
  long lVar2;
  ushort *puVar3;
  char *pcVar4;
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
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar1 = -0x13;
    goto LAB_0011241c;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending MSA ready request message, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  lVar2 = kmalloc_trace(___list_add_valid,0xdc0,1);
  if (lVar2 == 0) {
    iVar1 = -0xc;
    goto LAB_0011241c;
  }
  puVar3 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar3 == (ushort *)0x0) {
    kfree(lVar2);
    iVar1 = -0xc;
    goto LAB_0011241c;
  }
  *(int *)(param_1 + 0xa6c) = *(int *)(param_1 + 0xa6c) + 1;
  iVar1 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_msa_ready_resp_msg_v01_ei,puVar3);
  if (iVar1 < 0) {
    pcVar4 = "%sicnss2_qmi: fatal: Fail to init txn for MSA Mem Ready resp %d\n";
LAB_00112390:
    _printk(pcVar4,&DAT_0011c04b,iVar1);
    ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7,iVar1);
  }
  else {
    iVar1 = qmi_send_request(param_1 + 0x248,0,&local_90,0x2e,0,&wlfw_msa_ready_req_msg_v01_ei,lVar2
                            );
    if (iVar1 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar4 = "%sicnss2_qmi: fatal: Fail to send MSA Mem Ready req %d\n";
      goto LAB_00112390;
    }
    iVar1 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar1 < 0) {
      pcVar4 = "%sicnss2_qmi: fatal: MSA Mem Ready resp wait failed with ret %d\n";
      goto LAB_00112390;
    }
    if (*puVar3 == 0) {
      *(int *)(param_1 + 0xa70) = *(int *)(param_1 + 0xa70) + 1;
      kfree(puVar3);
      kfree(lVar2);
      iVar1 = 0;
      goto LAB_0011241c;
    }
    _printk("%sicnss2_qmi: fatal: QMI MSA Mem Ready request rejected, result:%d error:%d\n",
            &DAT_0011c04b,*puVar3,puVar3[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: fatal: QMI MSA Mem Ready request rejected, result:%d error:%d\n",
                   &DAT_0011dab7,*puVar3,puVar3[1]);
    iVar1 = -(uint)*puVar3;
  }
  kfree(puVar3);
  kfree(lVar2);
  *(int *)(param_1 + 0xa74) = *(int *)(param_1 + 0xa74) + 1;
LAB_0011241c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// wlfw_device_info_send_msg @ 00112458 size=816
// signature: undefined wlfw_device_info_send_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_device_info_send_msg(long param_1)

{
  ushort uVar1;
  int iVar2;
  long lVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00112720;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending Device Info request message, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  lVar3 = kmalloc_trace(___list_add_valid,0xdc0,1);
  if (lVar3 == 0) {
    iVar2 = -0xc;
    goto LAB_00112720;
  }
  puVar4 = (ushort *)kmalloc_trace(_alt_cb_patch_nops,0xdc0,0x88);
  if (puVar4 == (ushort *)0x0) {
    kfree(lVar3);
    iVar2 = -0xc;
    goto LAB_00112720;
  }
  *(int *)(param_1 + 0xac0) = *(int *)(param_1 + 0xac0) + 1;
  iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_device_info_resp_msg_v01_ei,puVar4);
  if (iVar2 < 0) {
    pcVar5 = "%sicnss2_qmi: fatal: Fail to init txn for Device Info resp %d\n";
LAB_0011262c:
    _printk(pcVar5,&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x4c,0,&wlfw_device_info_req_msg_v01_ei,
                             lVar3);
    if (iVar2 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar5 = "%sicnss2_qmi: fatal: Fail to send device info req %d\n";
      goto LAB_0011262c;
    }
    iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: fatal: Device Info resp wait failed with ret %d\n";
      goto LAB_0011262c;
    }
    if (*puVar4 == 0) {
      uVar1 = puVar4[2];
      *(int *)(param_1 + 0xac4) = *(int *)(param_1 + 0xac4) + 1;
      if ((char)uVar1 != '\0') {
        *(undefined8 *)(param_1 + 0x1e8) = *(undefined8 *)(puVar4 + 4);
      }
      if ((char)puVar4[8] != '\0') {
        *(undefined4 *)(param_1 + 0x1f8) = *(undefined4 *)(puVar4 + 10);
      }
      if (*(long *)(param_1 + 0x1e8) == 0) {
        _printk("%sicnss2_qmi: fatal: Fail to get bar address\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: fatal: Fail to get bar address\n",
                       &DAT_0011dab7);
      }
      else {
        if (*(uint *)(param_1 + 0x1f8) >> 0x15 != 0) {
          if ((char)puVar4[0xc] != '\0') {
            *(undefined8 *)(param_1 + 0x200) = *(undefined8 *)(puVar4 + 0x10);
          }
          if ((char)puVar4[0x14] != '\0') {
            *(undefined4 *)(param_1 + 0x210) = *(undefined4 *)(puVar4 + 0x16);
          }
          if (*(long *)(param_1 + 0x200) == 0) {
            _printk("%sicnss2_qmi: Fail to get MHI info address\n",&DAT_0011c04b);
            ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Fail to get MHI info address\n",
                           &DAT_0011dab7);
          }
          kfree(puVar4);
          kfree(lVar3);
          iVar2 = 0;
          goto LAB_00112720;
        }
        _printk("%sicnss2_qmi: fatal: Bar size is not proper 0x%x\n",&DAT_0011c04b);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: fatal: Bar size is not proper 0x%x\n",
                       &DAT_0011dab7,*(undefined4 *)(param_1 + 0x1f8));
      }
      iVar2 = -0x16;
    }
    else {
      _printk("%sicnss2_qmi: fatal: QMI Device info request rejected, result:%d error:%d\n",
              &DAT_0011c04b,*puVar4,puVar4[1]);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: fatal: QMI Device info request rejected, result:%d error:%d\n",
                     &DAT_0011dab7,*puVar4,puVar4[1]);
      iVar2 = -(uint)*puVar4;
    }
  }
  kfree(puVar4);
  kfree(lVar3);
  *(int *)(param_1 + 0xac8) = *(int *)(param_1 + 0xac8) + 1;
LAB_00112720:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_power_save_send_msg @ 0011278c size=512
// signature: undefined wlfw_power_save_send_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_power_save_send_msg(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  char *pcVar4;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
  }
  else if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) == 0) {
    if ((((uint)*(undefined8 *)(param_1 + 0x778) >> 9 & 1) == 0) &&
       (((uint)*(undefined8 *)(param_1 + 0x778) >> 0x10 & 1) != 0)) {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending power save mode: %d, state: 0x%lx\n"
                     ,param_2);
      puVar3 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,8);
      if (puVar3 == (undefined1 *)0x0) {
        iVar2 = -0xc;
      }
      else {
        lVar1 = 0xacc;
        if (param_2 != 1) {
          lVar1 = 0xad8;
        }
        *(int *)(puVar3 + 4) = param_2;
        iVar2 = *(int *)(param_1 + lVar1);
        *puVar3 = 1;
        *(int *)(param_1 + lVar1) = iVar2 + 1;
        iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,0,0);
        if (iVar2 < 0) {
          pcVar4 = "%sicnss2_qmi: fatal: Fail to init txn for exit power save%d\n";
        }
        else {
          iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x50,7,
                                   &wlfw_power_save_req_msg_v01_ei,puVar3);
          qmi_txn_cancel(&local_90);
          if (-1 < iVar2) {
            lVar1 = 0xad0;
            if (param_2 != 1) {
              lVar1 = 0xadc;
            }
            *(int *)(param_1 + lVar1) = *(int *)(param_1 + lVar1) + 1;
            kfree(puVar3);
            iVar2 = 0;
            goto LAB_001127fc;
          }
          pcVar4 = "%sicnss2_qmi: fatal: Fail to send exit power save req %d\n";
        }
        _printk(pcVar4,&DAT_0011c04b,iVar2);
        ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7,iVar2);
        kfree(puVar3);
        if (param_2 == 1) {
          *(int *)(param_1 + 0xad4) = *(int *)(param_1 + 0xad4) + 1;
        }
        else {
          *(int *)(param_1 + 0xae0) = *(int *)(param_1 + 0xae0) + 1;
        }
      }
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = -0x16;
  }
LAB_001127fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_send_soc_wake_msg @ 00112990 size=608
// signature: undefined wlfw_send_soc_wake_msg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_send_soc_wake_msg(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00112bb8;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) {
    iVar2 = -0x16;
    goto LAB_00112bb8;
  }
  ipc_log_string(icnss_ipc_soc_wake_context,"icnss2_qmi: Sending soc wake msg, type: 0x%x\n",param_2
                );
  puVar3 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,8);
  if (puVar3 == (undefined1 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00112bb8;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    kfree(puVar3);
    iVar2 = -0xc;
    goto LAB_00112bb8;
  }
  iVar2 = *(int *)(param_1 + 0xae4);
  *puVar3 = 1;
  *(undefined4 *)(puVar3 + 4) = param_2;
  *(int *)(param_1 + 0xae4) = iVar2 + 1;
  iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_soc_wake_resp_msg_v01_ei,puVar4);
  if (iVar2 < 0) {
    pcVar5 = "%sicnss2_qmi: Fail to init txn for wake msg resp %d\n";
LAB_00112b24:
    _printk(pcVar5,&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x4f,7,&wlfw_soc_wake_req_msg_v01_ei,puVar3
                            );
    if (iVar2 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar5 = "%sicnss2_qmi: Fail to send soc wake msg %d\n";
      goto LAB_00112b24;
    }
    iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: fatal: SOC wake timed out with ret %d\n";
      goto LAB_00112b24;
    }
    if (*puVar4 == 0) {
      *(int *)(param_1 + 0xae8) = *(int *)(param_1 + 0xae8) + 1;
      kfree(puVar4);
      kfree(puVar3);
      iVar2 = 0;
      goto LAB_00112bb8;
    }
    _printk("%sicnss2_qmi: fatal: SOC wake request rejected,result:%d error:%d\n",&DAT_0011c04b,
            *puVar4,puVar4[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: fatal: SOC wake request rejected,result:%d error:%d\n",
                   &DAT_0011dab7,*puVar4,puVar4[1]);
    iVar2 = -(uint)*puVar4;
  }
  kfree(puVar3);
  kfree(puVar4);
  *(int *)(param_1 + 0xaec) = *(int *)(param_1 + 0xaec) + 1;
LAB_00112bb8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_ind_register_send_sync_msg @ 00112bf4 size=716
// signature: undefined wlfw_ind_register_send_sync_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_ind_register_send_sync_msg(long param_1)

{
  ushort uVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  long lVar5;
  char *pcVar6;
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
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00112e88;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending indication register message, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  puVar3 = (undefined2 *)kmalloc_trace(___list_add_valid,0xdc0,0x38);
  if (puVar3 == (undefined2 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00112e88;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,0x10);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    lVar5 = *(long *)(param_1 + 0x108);
    *(undefined1 *)(puVar3 + 5) = 1;
    *(undefined4 *)(puVar3 + 6) = 0x4b4e454c;
    *puVar3 = 0x101;
    puVar3[4] = 0x101;
    if ((lVar5 == 0x6450) || (lVar5 == 0x6750)) {
      puVar3[10] = 0x101;
      puVar3[0x17] = 0x101;
      *(undefined8 *)(puVar3 + 0xf) = 0x101010101010101;
      puVar3[0x13] = 0x101;
    }
    else if ((lVar5 == 0xabcd) &&
            (puVar3[3] = 0x101, ((uint)*(undefined8 *)(param_1 + 0x120) >> 6 & 1) != 0)) {
      *(undefined1 *)(puVar3 + 0xb) = 1;
      *(undefined4 *)(puVar3 + 0xc) = 1;
    }
    iVar2 = *(int *)(param_1 + 0xa54);
    puVar3[0x19] = 0x101;
    *(int *)(param_1 + 0xa54) = iVar2 + 1;
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_ind_register_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar6 = "%sicnss2_qmi: fatal: Fail to init txn for Ind Register resp %d\n";
LAB_00112dfc:
      _printk(pcVar6,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar2);
LAB_00112e6c:
      *(int *)(param_1 + 0xa5c) = *(int *)(param_1 + 0xa5c) + 1;
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x20,0x62,
                               &wlfw_ind_register_req_msg_v01_ei,puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar6 = "%sicnss2_qmi: fatal: Fail to send Ind Register req %d\n";
        goto LAB_00112dfc;
      }
      iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar6 = "%sicnss2_qmi: fatal: Ind Register resp wait failed with ret %d\n";
        goto LAB_00112dfc;
      }
      if (*puVar4 != 0) {
        _printk("%sicnss2_qmi: fatal: QMI Ind Register request rejected, result:%d error:%d\n",
                &DAT_0011c04b,*puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: fatal: QMI Ind Register request rejected, result:%d error:%d\n"
                       ,&DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
        goto LAB_00112e6c;
      }
      uVar1 = puVar4[2];
      *(int *)(param_1 + 0xa58) = *(int *)(param_1 + 0xa58) + 1;
      if (((char)uVar1 == '\0') || ((puVar4[4] & 1) == 0)) {
        iVar2 = 0;
      }
      else {
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: WLFW already registered\n");
        iVar2 = -0x72;
      }
    }
    kfree(puVar4);
  }
  kfree(puVar3);
LAB_00112e88:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_cal_report_req @ 00112ec4 size=564
// signature: undefined wlfw_cal_report_req(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_cal_report_req(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
  }
  else if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) == 0) {
    _printk("%sicnss2_qmi: Sending cal report request, state: 0x%lx\n",&DAT_0011e9ea);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Sending cal report request, state: 0x%lx\n",
                   &DAT_0011dab7,*(undefined8 *)(param_1 + 0x778));
    puVar3 = (undefined4 *)kmalloc_trace(___list_add_valid,0xdc0,0x28);
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = -0xc;
    }
    else {
      puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
      if (puVar4 == (ushort *)0x0) {
        kfree(puVar3);
        iVar2 = -0xc;
      }
      else {
        *puVar3 = 0;
        iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_cal_report_resp_msg_v01_ei,puVar4);
        if (iVar2 < 0) {
          pcVar5 = "%sicnss2_qmi: fatal: Fail to init txn for cal report req %d\n";
        }
        else {
          iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x26,0x2b,
                                   &wlfw_cal_report_req_msg_v01_ei,puVar3);
          if (iVar2 < 0) {
            qmi_txn_cancel(&local_90);
            pcVar5 = "%sicnss2_qmi: fatal: Fail to send cal report req %d\n";
          }
          else {
            iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
            if (-1 < iVar2) {
              if (*puVar4 == 0) {
                kfree(puVar4);
                kfree(puVar3);
                iVar2 = 0;
              }
              else {
                _printk("%sicnss2_qmi: fatal: QMI cal report request rejected, result:%d error:%d\n"
                        ,&DAT_0011c04b,*puVar4,puVar4[1]);
                ipc_log_string(icnss_ipc_log_context,
                               "%sicnss2_qmi: fatal: QMI cal report request rejected, result:%d error:%d\n"
                               ,&DAT_0011dab7,*puVar4,puVar4[1]);
                iVar2 = -(uint)*puVar4;
              }
              goto LAB_00112f1c;
            }
            pcVar5 = "%sicnss2_qmi: fatal: Cal report wait failed with ret %d\n";
          }
        }
        _printk(pcVar5,&DAT_0011c04b,iVar2);
        ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
      }
    }
  }
  else {
    iVar2 = -0x16;
  }
LAB_00112f1c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_cap_send_sync_msg @ 001130fc size=1500
// signature: undefined wlfw_cap_send_sync_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_cap_send_sync_msg(long param_1)

{
  undefined8 uVar1;
  uint uVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  long lVar6;
  ushort *puVar7;
  long lVar8;
  size_t sVar9;
  ulong uVar10;
  undefined4 uVar11;
  undefined1 uVar12;
  char *pcVar13;
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
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if (param_1 == 0) {
    iVar5 = -0x13;
    goto LAB_001134b0;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending target capability message, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  lVar6 = kmalloc_trace(___list_add_valid,0xdc0,1);
  if (lVar6 == 0) {
    iVar5 = -0xc;
    goto LAB_001134b0;
  }
  puVar7 = (ushort *)kmalloc_trace(_pm_relax,0xdc0,0x928);
  if (puVar7 == (ushort *)0x0) {
    kfree(lVar6);
    iVar5 = -0xc;
    goto LAB_001134b0;
  }
  *(int *)(param_1 + 0xa7c) = *(int *)(param_1 + 0xa7c) + 1;
  iVar5 = qmi_txn_init(param_1 + 0x248,&local_a0,&wlfw_cap_resp_msg_v01_ei,puVar7);
  if (iVar5 < 0) {
    pcVar13 = "%sicnss2_qmi: fatal: Fail to init txn for Capability resp %d\n";
LAB_00113468:
    _printk(pcVar13,&DAT_0011c04b,iVar5);
    ipc_log_string(icnss_ipc_log_context,pcVar13,&DAT_0011dab7,iVar5);
  }
  else {
    iVar5 = qmi_send_request(param_1 + 0x248,0,&local_a0,0x24,0,&wlfw_cap_req_msg_v01_ei,lVar6);
    if (iVar5 < 0) {
      qmi_txn_cancel(&local_a0);
      pcVar13 = "%sicnss2_qmi: fatal: Fail to send Capability req %d\n";
      goto LAB_00113468;
    }
    uVar2 = *(uint *)(param_1 + 0x128);
    lVar8 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x1644));
    iVar5 = qmi_txn_wait(&local_a0,lVar8 + (ulong)uVar2);
    if (iVar5 < 0) {
      pcVar13 = "%sicnss2_qmi: fatal: Capability resp wait failed with ret %d\n";
      goto LAB_00113468;
    }
    if (*puVar7 == 0) {
      uVar4 = puVar7[2];
      *(int *)(param_1 + 0xa80) = *(int *)(param_1 + 0xa80) + 1;
      if ((char)uVar4 != '\0') {
        uVar11 = *(undefined4 *)(puVar7 + 6);
        *(undefined4 *)(param_1 + 0x780) = *(undefined4 *)(puVar7 + 4);
        *(undefined4 *)(param_1 + 0x784) = uVar11;
      }
      if ((char)puVar7[8] == '\0') {
        uVar11 = 0xff;
      }
      else {
        uVar11 = *(undefined4 *)(puVar7 + 10);
      }
      uVar4 = puVar7[0xc];
      *(undefined4 *)(param_1 + 0x788) = uVar11;
      if ((char)uVar4 != '\0') {
        *(undefined4 *)(param_1 + 0x78c) = *(undefined4 *)(puVar7 + 0xe);
      }
      if ((char)puVar7[0x10] != '\0') {
        *(undefined4 *)(param_1 + 0x790) = *(undefined4 *)(puVar7 + 0x12);
        sVar9 = strnlen((char *)(puVar7 + 0x14),0x21);
        if (0x21 < sVar9) goto LAB_001136c0;
        if (sVar9 == 0x21) goto LAB_001136cc;
        memcpy((void *)(param_1 + 0x794),puVar7 + 0x14,sVar9);
        *(undefined1 *)(param_1 + 0x794 + sVar9) = 0;
      }
      if ((char)puVar7[0x84] == '\0') {
        cVar3 = (char)puVar7[0x68];
        uVar1 = icnss_ipc_log_context;
      }
      else {
        uVar1 = *(undefined8 *)(puVar7 + 0x8c);
        *(undefined8 *)(param_1 + 0x870) = *(undefined8 *)(puVar7 + 0x88);
        *(undefined8 *)(param_1 + 0x878) = uVar1;
        _printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                &DAT_0011e9ea,0);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                       &DAT_0011dab7,0,*(undefined8 *)(param_1 + 0x870),
                       *(undefined8 *)(param_1 + 0x878));
        uVar1 = *(undefined8 *)(puVar7 + 0x94);
        *(undefined8 *)(param_1 + 0x880) = *(undefined8 *)(puVar7 + 0x90);
        *(undefined8 *)(param_1 + 0x888) = uVar1;
        _printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                &DAT_0011e9ea,1);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                       &DAT_0011dab7,1,*(undefined8 *)(param_1 + 0x880),
                       *(undefined8 *)(param_1 + 0x888));
        uVar1 = *(undefined8 *)(puVar7 + 0x9c);
        *(undefined8 *)(param_1 + 0x890) = *(undefined8 *)(puVar7 + 0x98);
        *(undefined8 *)(param_1 + 0x898) = uVar1;
        _printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                &DAT_0011e9ea,2);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                       &DAT_0011dab7,2,*(undefined8 *)(param_1 + 0x890),
                       *(undefined8 *)(param_1 + 0x898));
        uVar1 = *(undefined8 *)(puVar7 + 0xa4);
        *(undefined8 *)(param_1 + 0x8a0) = *(undefined8 *)(puVar7 + 0xa0);
        *(undefined8 *)(param_1 + 0x8a8) = uVar1;
        _printk("%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                &DAT_0011e9ea,3);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Device memory info[%d]: start = 0x%llx, size = 0x%llx\n",
                       &DAT_0011dab7,3,*(undefined8 *)(param_1 + 0x8a0),
                       *(undefined8 *)(param_1 + 0x8a8));
        cVar3 = (char)puVar7[0x68];
        uVar1 = icnss_ipc_log_context;
      }
      icnss_ipc_log_context = uVar1;
      if (cVar3 != '\0') {
        *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(puVar7 + 0x6a);
        ipc_log_string(uVar1,"icnss2_qmi: Voltage for CPR: %dmV\n");
        icnss_update_cpr_info(param_1);
      }
      if ((char)puVar7[0x26] != '\0') {
        sVar9 = strnlen((char *)((long)puVar7 + 0x4d),0x81);
        if (0x81 < sVar9) {
LAB_001136c0:
                    /* WARNING: Subroutine does not return */
          fortify_panic("strnlen");
        }
        if (sVar9 == 0x81) {
LAB_001136cc:
                    /* WARNING: Subroutine does not return */
          fortify_panic("__fortify_strlen");
        }
        memcpy((void *)(param_1 + 0x7b8),(char *)((long)puVar7 + 0x4d),sVar9);
        *(undefined1 *)(param_1 + 0x7b8 + sVar9) = 0;
      }
      if (((char)puVar7[0x80] != '\0') &&
         (iVar5 = *(int *)(puVar7 + 0x82), *(int *)(param_1 + 0x1794) = iVar5, iVar5 == 1)) {
        *(undefined1 *)(param_1 + 0x15b8) = 0;
      }
      if ((char)puVar7[0xa8] == '\0') {
        if (((char)puVar7[2] != '\0') && (*(int *)(param_1 + 0x780) == 0x4320)) {
          uVar12 = 0x75;
          goto LAB_00113368;
        }
      }
      else {
        uVar12 = *(undefined1 *)((long)puVar7 + 0x151);
LAB_00113368:
        *(undefined1 *)(param_1 + 0x1684) = uVar12;
      }
      if ((char)puVar7[0x241] != '\0') {
        *(undefined4 *)(param_1 + 0x1798) = *(undefined4 *)(puVar7 + 0x242);
      }
      if ((char)puVar7[0x244] != '\0') {
        *(undefined4 *)(param_1 + 0x179c) = *(undefined4 *)(puVar7 + 0x246);
      }
      if ((char)puVar7[0x248] == '\0') {
        cVar3 = (char)puVar7[0x78];
      }
      else {
        uVar10 = *(ulong *)(puVar7 + 0x24a);
        *(ulong *)(param_1 + 0x17a4) = uVar10;
        _printk("%sicnss2_qmi: serial id  0x%x 0x%x\n",&DAT_0011e9ea,uVar10,uVar10 >> 0x20);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: serial id  0x%x 0x%x\n",&DAT_0011dab7,
                       *(undefined4 *)(puVar7 + 0x24a),*(undefined4 *)(puVar7 + 0x24c));
        cVar3 = (char)puVar7[0x78];
      }
      if (cVar3 != '\0') {
        *(undefined8 *)(param_1 + 0x17b0) = *(undefined8 *)(puVar7 + 0x7c);
      }
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: Capability, chip_id: 0x%x, chip_family: 0x%x, board_id: 0x%x, soc_id: 0x%x"
                     ,*(undefined4 *)(param_1 + 0x780),*(undefined4 *)(param_1 + 0x784),
                     *(undefined4 *)(param_1 + 0x788),*(undefined4 *)(param_1 + 0x78c));
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: fw_version: 0x%x, fw_build_timestamp: %s,\t\t     fw_build_id: %s, fw_caps: 0x%llx"
                     ,*(undefined4 *)(param_1 + 0x790),param_1 + 0x794,param_1 + 0x7b8,
                     *(undefined8 *)(param_1 + 0x17b0));
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: RD card chain cap: %d, PHY HE channel width cap: %d, PHY QAM cap: %d"
                     ,*(undefined4 *)(param_1 + 0x1794),*(undefined4 *)(param_1 + 0x1798),
                     *(undefined4 *)(param_1 + 0x179c));
      kfree(puVar7);
      kfree(lVar6);
      iVar5 = 0;
      goto LAB_001134b0;
    }
    iVar5 = -(uint)*puVar7;
    if (puVar7[1] == 0x77) {
      _printk("%sicnss2_qmi: RF card not present\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: RF card not present\n",&DAT_0011dab7);
    }
    else {
      _printk("%sicnss2_qmi: fatal: QMI Capability request rejected, result:%d error:%d\n",
              &DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: fatal: QMI Capability request rejected, result:%d error:%d\n",
                     &DAT_0011dab7,*puVar7,puVar7[1]);
    }
  }
  kfree(puVar7);
  kfree(lVar6);
  *(int *)(param_1 + 0xa84) = *(int *)(param_1 + 0xa84) + 1;
LAB_001134b0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// icnss_qmi_get_dms_mac @ 001136dc size=708
// signature: undefined icnss_qmi_get_dms_mac(void)
// callers: [icnss_setup_dms_mac]
//------------------------------------------------------------

int icnss_qmi_get_dms_mac(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined4 local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0x16 & 1) == 0) {
    _printk("%sicnss2_qmi: DMS QMI connection not established\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: DMS QMI connection not established\n",
                   &DAT_0011dab7);
    iVar3 = -0xb;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Requesting DMS MAC address");
    local_60 = 0;
    local_58 = 0;
    local_50 = 0;
    iVar3 = qmi_txn_init(param_1 + 0x390,&local_b0,&dms_get_mac_address_resp_msg_v01_ei,&local_60);
    if (iVar3 < 0) {
      pcVar4 = "%sicnss2_qmi: Failed to initialize txn for dms, err: %d\n";
    }
    else {
      local_68[0] = 0;
      iVar3 = qmi_send_request(param_1 + 0x390,0,&local_b0,0x5c,7,
                               &dms_get_mac_address_req_msg_v01_ei,local_68);
      if (iVar3 < 0) {
        qmi_txn_cancel(&local_b0);
        pcVar4 = "%sicnss2_qmi: Failed to send QMI_DMS_GET_MAC_ADDRESS_REQ_V01, err: %d\n";
      }
      else {
        iVar3 = qmi_txn_wait(&local_b0,*(undefined4 *)(param_1 + 0x128));
        if (-1 < iVar3) {
          if ((ushort)local_60 == 0) {
            if ((local_60._4_1_ == '\0') || ((int)local_58 != 6)) {
              _printk("%sicnss2_qmi: Invalid MAC address received from DMS\n",&DAT_0011c04b);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2_qmi: Invalid MAC address received from DMS\n",&DAT_0011dab7);
              *(undefined1 *)(param_1 + 0x15c0) = 0;
            }
            else {
              puVar1 = (undefined4 *)(param_1 + 0x15c2);
              *(undefined2 *)(param_1 + 0x15c6) = (undefined2)local_50;
              *(undefined1 *)(param_1 + 0x15c0) = 1;
              *puVar1 = local_58._4_4_;
              _printk("%sicnss2_qmi: Received DMS MAC: [%pM]\n",&DAT_0011e9ea,puVar1);
              ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Received DMS MAC: [%pM]\n",
                             &DAT_0011dab7,puVar1);
            }
          }
          else {
            if (local_60._2_2_ == 0x10) {
              _printk("%sicnss2_qmi: NV MAC address is not provisioned",&DAT_0011c04b);
              ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: NV MAC address is not provisioned"
                             ,&DAT_0011dab7);
              *(undefined1 *)(param_1 + 0x15c1) = 1;
            }
            else {
              _printk("%sicnss2_qmi: QMI_DMS_GET_MAC_ADDRESS_REQ_V01 failed, result: %d, err: %d\n",
                      &DAT_0011c04b);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2_qmi: QMI_DMS_GET_MAC_ADDRESS_REQ_V01 failed, result: %d, err: %d\n"
                             ,&DAT_0011dab7,local_60 & 0xffff,local_60._2_2_);
            }
            iVar3 = -(uint)(ushort)local_60;
          }
          goto LAB_00113834;
        }
        pcVar4 = "%sicnss2_qmi: Failed to wait for QMI_DMS_GET_MAC_ADDRESS_RESP_V01, err: %d\n";
      }
    }
    _printk(pcVar4,&DAT_0011c04b,iVar3);
    ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7,iVar3);
  }
LAB_00113834:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// icnss_wlfw_wlan_mac_req_send_sync @ 001139a4 size=536
// signature: undefined icnss_wlfw_wlan_mac_req_send_sync(void)
// callers: [icnss_setup_dms_mac]
//------------------------------------------------------------

int icnss_wlfw_wlan_mac_req_send_sync(long param_1,undefined4 *param_2,int param_3)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  uint local_48 [2];
  undefined1 local_40;
  undefined4 local_3f;
  undefined2 local_3b;
  long local_38;
  
  lVar1 = sp_el0;
  iVar2 = -0x16;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48[0] = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) && (param_3 == 6)) {
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_mac_addr_resp_msg_v01_ei,local_48);
    if (iVar2 < 0) {
      _printk("%sicnss2_qmi: Failed to initialize txn for mac req, err: %d\n",&DAT_0011c04b,iVar2);
      pcVar3 = "%sicnss2_qmi: Failed to initialize txn for mac req, err: %d\n";
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending WLAN mac req [%pM], state: 0x%lx\n",
                     param_2,*(undefined8 *)(param_1 + 0x778));
      local_3f = *param_2;
      local_3b = *(undefined2 *)(param_2 + 1);
      local_40 = 1;
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x33,9,&wlfw_mac_addr_req_msg_v01_ei,
                               &local_40);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        _printk("%sicnss2_qmi: Failed to send mac req, err: %d\n",&DAT_0011c04b,iVar2);
        pcVar3 = "%sicnss2_qmi: Failed to send mac req, err: %d\n";
      }
      else {
        iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
        if (-1 < iVar2) {
          if ((short)local_48[0] != 0) {
            _printk("%sicnss2_qmi: WLAN mac req failed, result: %d\n",&DAT_0011c04b);
            ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: WLAN mac req failed, result: %d\n",
                           &DAT_0011dab7,(short)local_48[0]);
            iVar2 = -(local_48[0] & 0xffff);
          }
          goto LAB_00113a98;
        }
        _printk("%sicnss2_qmi: Failed to wait for resp of mac req, err: %d\n",&DAT_0011c04b,iVar2);
        pcVar3 = "%sicnss2_qmi: Failed to wait for resp of mac req, err: %d\n";
      }
    }
    ipc_log_string(icnss_ipc_log_context,pcVar3,&DAT_0011dab7,iVar2);
    iVar2 = -5;
  }
LAB_00113a98:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_dms_init @ 00113bc0 size=172
// signature: undefined icnss_dms_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

int icnss_dms_init(long param_1)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = qmi_handle_init(param_1 + 0x390,0x100,&qmi_dms_ops,0);
  if (iVar1 < 0) {
    pcVar2 = "%sicnss2_qmi: Failed to initialize DMS handle, err: %d\n";
  }
  else {
    iVar1 = qmi_add_lookup(param_1 + 0x390,2,1,0);
    if (-1 < iVar1) {
      return iVar1;
    }
    pcVar2 = "%sicnss2_qmi: Failed to add DMS lookup, err: %d\n";
  }
  _printk(pcVar2,&DAT_0011c04b,iVar1);
  ipc_log_string(icnss_ipc_log_context,pcVar2,&DAT_0011dab7,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// icnss_dms_deinit @ 00113c70 size=32
// signature: undefined icnss_dms_deinit(void)
// callers: [icnss_remove]
//------------------------------------------------------------

void icnss_dms_deinit(long param_1)

{
  qmi_handle_release(param_1 + 0x390);
  return;
}



//------------------------------------------------------------
// icnss_wlfw_bdf_dnld_send_sync @ 00113c94 size=2288
// signature: undefined icnss_wlfw_bdf_dnld_send_sync(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_wlfw_bdf_dnld_send_sync(long param_1,uint param_2)

{
  undefined4 uVar1;
  char cVar2;
  ushort uVar3;
  long lVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  size_t sVar10;
  char *pcVar11;
  char *pcVar12;
  uint uVar13;
  undefined8 uVar14;
  uint uVar15;
  void *__src;
  uint *local_168;
  undefined8 uStack_160;
  undefined8 local_158;
  undefined8 uStack_150;
  undefined8 local_148;
  undefined8 uStack_140;
  undefined8 local_138;
  undefined8 uStack_130;
  undefined8 local_128;
  undefined8 uStack_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined2 local_e8;
  char local_e0 [8];
  undefined2 uStack_d8;
  undefined1 uStack_d6;
  undefined1 local_d5;
  undefined4 uStack_d4;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  ushort local_b0;
  undefined7 local_a8;
  char cStack_a1;
  undefined2 uStack_a0;
  undefined1 uStack_9e;
  undefined5 uStack_9d;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  long local_70;
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
  local_128 = 0;
  uStack_120 = 0;
  local_138 = 0;
  uStack_130 = 0;
  local_148 = 0;
  uStack_140 = 0;
  local_158 = 0;
  uStack_150 = 0;
  local_168 = (uint *)0x0;
  uStack_160 = 0;
  local_e8 = 0;
  local_f8 = 0;
  uStack_f0 = 0;
  local_108 = 0;
  uStack_100 = 0;
  local_118 = 0;
  uStack_110 = 0;
  if (param_2 < 5) {
    pcVar12 = (&PTR_DAT_0011abc0)[(int)param_2];
  }
  else {
    pcVar12 = "UNKNOWN";
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending %s download message, state: 0x%lx, type: %d\n",pcVar12,
                 *(undefined8 *)(param_1 + 0x778),param_2);
  puVar8 = (ushort *)kmalloc_trace(_icc_set_bw,0xdc0,0x1824);
  if (puVar8 == (ushort *)0x0) {
    iVar7 = -0xc;
    goto LAB_00114128;
  }
  puVar9 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,0x10);
  if (puVar9 == (ushort *)0x0) {
    iVar7 = -0xc;
  }
  else {
    local_78 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    cStack_a1 = '\0';
    uStack_a0 = 0;
    uStack_9e = 0;
    uStack_9d = 0;
    local_b0 = 0;
    local_c0 = 0;
    uStack_b8 = 0;
    local_d0 = 0;
    uStack_c8 = 0;
    local_e0[0] = '\0';
    local_e0[1] = '\0';
    local_e0[2] = '\0';
    local_e0[3] = '\0';
    local_e0[4] = '\0';
    local_e0[5] = '\0';
    local_e0[6] = '\0';
    local_e0[7] = '\0';
    uStack_d8 = 0;
    uStack_d6 = 0;
    local_d5 = 0;
    uStack_d4 = 0;
    if (param_2 == 0) {
      iVar7 = selectFileNameByProduct(&local_a8);
      if (iVar7 < 1) {
        if (*(uint *)(param_1 + 0x788) == 0xff) {
          uStack_a0 = 0x6e69;
          uStack_9e = 0;
          local_a8 = s_bdwlan_bin_0012068e._0_7_;
          cStack_a1 = s_bdwlan_bin_0012068e[7];
        }
        else {
          if (*(uint *)(param_1 + 0x788) < 0x100) {
            pcVar12 = "bdwlan.b%02x";
          }
          else {
            pcVar12 = "bdwlan.%03x";
          }
          snprintf((char *)&local_a8,0x32,pcVar12);
        }
      }
      else {
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: %s: Using %s for %s\n",
                       "icnss_get_bdf_file_name",&local_a8,&device_ptr);
      }
      cVar2 = *(char *)(param_1 + 0x1684);
      if (cVar2 != '\0') {
        sVar10 = strnlen((char *)&local_a8,0x32);
        if (0x32 < sVar10) {
LAB_0011456c:
                    /* WARNING: Subroutine does not return */
          fortify_panic("strnlen");
        }
        if (sVar10 == 0x32) {
LAB_00114578:
                    /* WARNING: Subroutine does not return */
          fortify_panic("__fortify_strlen");
        }
        memcpy(local_e0,&local_a8,sVar10);
        local_e0[sVar10] = '\0';
        local_d5 = uStack_d6;
        uVar6 = uStack_d8;
        uVar5 = CONCAT11(local_e0[7],local_e0[6]);
        local_b0 = local_b0 & 0xff;
        local_e0[7] = local_e0[6];
        uStack_d8 = (undefined2)(CONCAT22(uStack_d8,uVar5) >> 8);
        uStack_d6 = (undefined1)((ushort)uVar6 >> 8);
        local_e0[6] = cVar2;
        sVar10 = strnlen(local_e0,0x32);
        if (0x32 < sVar10) goto LAB_0011456c;
        if (sVar10 == 0x32) goto LAB_00114578;
        memcpy(&local_a8,local_e0,sVar10);
        *(undefined1 *)((long)&local_a8 + sVar10) = 0;
      }
LAB_00113f94:
      icnss_add_fw_prefix_name(param_1,&local_118,&local_a8);
      iVar7 = firmware_request_nowarn(&local_168,&local_118,*(long *)(param_1 + 8) + 0x10);
      if (iVar7 == 0) {
        uVar15 = *local_168;
        if (param_2 < 5) {
          pcVar12 = (&PTR_DAT_0011abc0)[(int)param_2];
        }
        else {
          pcVar12 = "UNKNOWN";
        }
        __src = *(void **)(local_168 + 2);
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Downloading %s: %s, size: %u\n",pcVar12,
                       &local_118,uVar15);
        if (uVar15 != 0) {
          do {
            uVar1 = *(undefined4 *)(param_1 + 0x788);
            *(undefined1 *)(puVar8 + 4) = 1;
            *puVar8 = 0x101;
            *(undefined4 *)(puVar8 + 2) = uVar1;
            uVar14 = *(undefined8 *)local_168;
            *(undefined1 *)(puVar8 + 8) = 1;
            *(undefined1 *)(puVar8 + 0xc) = 1;
            *(undefined1 *)(puVar8 + 0xc10) = 1;
            *(undefined1 *)(puVar8 + 0xc11) = 1;
            *(int *)(puVar8 + 6) = (int)uVar14;
            *(char *)((long)puVar8 + 0x1823) = (char)param_2;
            if (uVar15 < 0x1801) {
              *(uint *)(puVar8 + 0xe) = uVar15;
              *(undefined1 *)((long)puVar8 + 0x1821) = 1;
              uVar13 = uVar15;
            }
            else {
              puVar8[0xe] = 0x1800;
              puVar8[0xf] = 0;
              uVar13 = 0x1800;
            }
            memcpy(puVar8 + 0x10,__src,(ulong)uVar13);
            iVar7 = qmi_txn_init(param_1 + 0x248,&uStack_160,&wlfw_bdf_download_resp_msg_v01_ei,
                                 puVar9);
            if (iVar7 < 0) {
              if (param_2 < 2) {
                pcVar12 = "BDF";
LAB_001143bc:
                _printk("%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n",
                        &DAT_0011c04b,pcVar12,iVar7);
                if (param_2 < 2) {
                  pcVar12 = "BDF";
                }
                else {
                  if (param_2 == 4) goto LAB_001143f4;
                  pcVar12 = "UNKNOWN";
                }
              }
              else {
                if (param_2 != 4) {
                  pcVar12 = "UNKNOWN";
                  goto LAB_001143bc;
                }
                _printk("%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n",
                        &DAT_0011c04b,"REGDB",iVar7);
LAB_001143f4:
                pcVar12 = "REGDB";
              }
              pcVar11 = "%sicnss2_qmi: Failed to initialize txn for %s download request, err: %d\n";
LAB_0011451c:
              ipc_log_string(icnss_ipc_log_context,pcVar11,&DAT_0011dab7,pcVar12,iVar7);
LAB_0011455c:
              release_firmware(local_168);
              goto LAB_00114118;
            }
            iVar7 = qmi_send_request(param_1 + 0x248,0,&uStack_160,0x25,0x1826,
                                     &wlfw_bdf_download_req_msg_v01_ei,puVar8);
            if (iVar7 < 0) {
              qmi_txn_cancel(&uStack_160);
              if (param_2 < 2) {
                pcVar12 = "BDF";
LAB_00114408:
                _printk("%sicnss2_qmi: Failed to send respond %s download request, err: %d\n",
                        &DAT_0011c04b,pcVar12,iVar7);
                if (param_2 < 2) {
                  pcVar12 = "BDF";
                }
                else {
                  if (param_2 == 4) goto LAB_00114440;
                  pcVar12 = "UNKNOWN";
                }
              }
              else {
                if (param_2 != 4) {
                  pcVar12 = "UNKNOWN";
                  goto LAB_00114408;
                }
                _printk("%sicnss2_qmi: Failed to send respond %s download request, err: %d\n",
                        &DAT_0011c04b,"REGDB",iVar7);
LAB_00114440:
                pcVar12 = "REGDB";
              }
              pcVar11 = "%sicnss2_qmi: Failed to send respond %s download request, err: %d\n";
              goto LAB_0011451c;
            }
            iVar7 = qmi_txn_wait(&uStack_160,*(undefined4 *)(param_1 + 0x128));
            if (iVar7 < 0) {
              if (param_2 < 2) {
                pcVar12 = "BDF";
LAB_00114454:
                _printk("%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n"
                        ,&DAT_0011c04b,pcVar12,iVar7);
                if (param_2 < 2) {
                  pcVar12 = "BDF";
                }
                else {
                  if (param_2 == 4) goto LAB_0011448c;
                  pcVar12 = "UNKNOWN";
                }
              }
              else {
                if (param_2 != 4) {
                  pcVar12 = "UNKNOWN";
                  goto LAB_00114454;
                }
                _printk("%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n"
                        ,&DAT_0011c04b,"REGDB",iVar7);
LAB_0011448c:
                pcVar12 = "REGDB";
              }
              pcVar11 = 
              "%sicnss2_qmi: Failed to wait for response of %s download request, err: %d\n";
              goto LAB_0011451c;
            }
            uVar3 = *puVar9;
            if (uVar3 != 0) {
              if (param_2 < 2) {
                pcVar12 = "BDF";
LAB_001144a0:
                _printk("%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                        &DAT_0011c04b,pcVar12,uVar3,puVar9[1]);
                if (param_2 < 2) {
                  pcVar12 = "BDF";
                }
                else {
                  if (param_2 == 4) goto LAB_001144d8;
                  pcVar12 = "UNKNOWN";
                }
              }
              else {
                if (param_2 != 4) {
                  pcVar12 = "UNKNOWN";
                  goto LAB_001144a0;
                }
                _printk("%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                        &DAT_0011c04b,"REGDB",uVar3,puVar9[1]);
LAB_001144d8:
                pcVar12 = "REGDB";
              }
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2_qmi: %s download request failed, result: %d, err: %d\n",
                             &DAT_0011dab7,pcVar12,*puVar9,puVar9[1]);
              iVar7 = -(uint)*puVar9;
              goto LAB_0011455c;
            }
            uVar15 = uVar15 - *(uint *)(puVar8 + 0xe);
            __src = (void *)((long)__src + (ulong)*(uint *)(puVar8 + 0xe));
            *(int *)(puVar8 + 10) = *(int *)(puVar8 + 10) + 1;
          } while (uVar15 != 0);
        }
        release_firmware(local_168);
        iVar7 = 0;
      }
      else {
        if (param_2 < 2) {
          pcVar12 = "BDF";
LAB_00114344:
          _printk("%sicnss2_qmi: Failed to load %s: %s ret:%d\n",&DAT_0011c04b,pcVar12,&local_118,
                  iVar7);
          if (param_2 < 2) {
            pcVar12 = "BDF";
          }
          else {
            if (param_2 == 4) goto LAB_00114380;
            pcVar12 = "UNKNOWN";
          }
        }
        else {
          if (param_2 != 4) {
            pcVar12 = "UNKNOWN";
            goto LAB_00114344;
          }
          _printk("%sicnss2_qmi: Failed to load %s: %s ret:%d\n",&DAT_0011c04b,"REGDB",&local_118,
                  iVar7);
LAB_00114380:
          pcVar12 = "REGDB";
        }
        ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Failed to load %s: %s ret:%d\n",
                       &DAT_0011dab7,pcVar12,&local_118,iVar7);
      }
    }
    else {
      if (param_2 == 4) {
        uStack_a0 = 0x6e;
        local_a8 = s_regdb_bin_0011f449._0_7_;
        cStack_a1 = s_regdb_bin_0011f449[7];
        goto LAB_00113f94;
      }
      if (param_2 == 1) {
        iVar7 = selectFileNameByProduct(&local_a8);
        if (iVar7 < 1) {
          uVar15 = *(uint *)(param_1 + 0x788);
          if (uVar15 == 0xff) {
            uStack_a0 = 0x666c;
            uStack_9e = 0;
            local_a8 = s_bdwlan_elf_00121953._0_7_;
            cStack_a1 = s_bdwlan_elf_00121953[7];
          }
          else if (uVar15 < 0xff) {
            snprintf((char *)&local_a8,0x32,"bdwlan.e%02x",uVar15);
          }
          else {
            snprintf((char *)&local_a8,0x32,"bdwlan%02x.e%02x",uVar15 >> 8 & 0xff,uVar15 & 0xff);
          }
        }
        else {
          ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: %s: Using %s for %s\n",
                         "icnss_get_bdf_file_name",&local_a8,&device_ptr);
        }
        goto LAB_00113f94;
      }
      _printk("%sicnss2_qmi: Invalid BDF type: %d\n",&DAT_0011c04b,*(undefined4 *)(param_1 + 300));
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Invalid BDF type: %d\n",&DAT_0011dab7,
                     *(undefined4 *)(param_1 + 300));
      iVar7 = -0x16;
    }
LAB_00114118:
    kfree(puVar8);
    puVar8 = puVar9;
  }
  kfree(puVar8);
LAB_00114128:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// icnss_wlfw_qdss_data_send_sync @ 00114588 size=1164
// signature: undefined icnss_wlfw_qdss_data_send_sync(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_wlfw_qdss_data_send_sync(long param_1,undefined8 param_2,uint param_3)

{
  ushort *puVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  ushort *puVar5;
  ushort *puVar6;
  void *pvVar7;
  char cVar8;
  char *pcVar9;
  uint uVar10;
  void *__dest;
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
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: %s","icnss_wlfw_qdss_data_send_sync");
  puVar5 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar5 == (ushort *)0x0) {
    iVar4 = -0xc;
    goto LAB_001147d0;
  }
  puVar6 = (ushort *)kmalloc_trace(_icc_set_bw,0xdc0,0x1820);
  if (puVar6 == (ushort *)0x0) {
    iVar4 = -0xc;
  }
  else {
    pvVar7 = (void *)__kmalloc(param_3,0xdc0);
    if (pvVar7 == (void *)0x0) {
      iVar4 = 0xc;
    }
    else {
      puVar1 = puVar6 + 0xc0e;
      if (param_3 != 0) {
        __dest = pvVar7;
        uVar10 = param_3;
        do {
          if (*(char *)((long)puVar6 + 0x181d) != '\0') {
            cVar8 = (char)*puVar1;
            goto LAB_00114904;
          }
          iVar4 = qmi_txn_init(param_1 + 0x248,&local_b0,&wlfw_qdss_trace_data_resp_msg_v01_ei,
                               puVar6);
          if (iVar4 < 0) {
            pcVar9 = "%sicnss2_qmi: Fail to init txn for QDSS trace resp %d\n";
LAB_0011498c:
            _printk(pcVar9,&DAT_0011c04b,iVar4);
            ipc_log_string(icnss_ipc_log_context,pcVar9,&DAT_0011dab7,iVar4);
            goto LAB_0011479c;
          }
          iVar4 = qmi_send_request(param_1 + 0x248,0,&local_b0,0x42,7,
                                   &wlfw_qdss_trace_data_req_msg_v01_ei,puVar5);
          if (iVar4 < 0) {
            qmi_txn_cancel(&local_b0);
            pcVar9 = "%sicnss2_qmi: Fail to send QDSS trace data req %d\n";
            goto LAB_0011498c;
          }
          iVar4 = qmi_txn_wait(&local_b0,*(undefined4 *)(param_1 + 0x128));
          if (iVar4 < 0) {
            pcVar9 = "%sicnss2_qmi: QDSS trace resp wait failed with rc %d\n";
            goto LAB_0011498c;
          }
          if (*puVar6 != 0) {
            _printk("%sicnss2_qmi: QMI QDSS trace request rejected, result:%d error:%d\n",
                    &DAT_0011c04b,*puVar6,puVar6[1]);
            ipc_log_string(icnss_ipc_log_context,
                           "%sicnss2_qmi: QMI QDSS trace request rejected, result:%d error:%d\n",
                           &DAT_0011dab7,*puVar6,puVar6[1]);
            iVar4 = -(uint)*puVar6;
            goto LAB_0011479c;
          }
          ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: %s: response total size  %d data len %d"
                         ,"icnss_wlfw_qdss_data_send_sync",*(int *)(puVar6 + 4),
                         *(int *)(puVar6 + 0xc));
          cVar8 = (char)puVar6[2];
          if (cVar8 != '\x01') {
LAB_00114810:
            _printk("%sicnss2_qmi: %s: Unmatched qdss trace data, Expect total_size %u, seg_id %u, Recv total_size_valid %u, total_size %u, seg_id_valid %u, seg_id %u, data_len_valid %u, data_len %u"
                    ,&DAT_0011c04b,"icnss_wlfw_qdss_data_send_sync",param_3,*(int *)puVar5,cVar8,
                    *(uint *)(puVar6 + 4),(char)puVar6[6],*(int *)(puVar6 + 8),(char)puVar6[10],
                    *(int *)(puVar6 + 0xc));
            ipc_log_string(icnss_ipc_log_context,
                           "%sicnss2_qmi: %s: Unmatched qdss trace data, Expect total_size %u, seg_id %u, Recv total_size_valid %u, total_size %u, seg_id_valid %u, seg_id %u, data_len_valid %u, data_len %u"
                           ,&DAT_0011dab7,"icnss_wlfw_qdss_data_send_sync",param_3,*(int *)puVar5,
                           (char)puVar6[2],*(int *)(puVar6 + 4),(char)puVar6[6],*(int *)(puVar6 + 8)
                           ,(char)puVar6[10],*(int *)(puVar6 + 0xc));
            iVar4 = -0x16;
            goto LAB_0011479c;
          }
          if ((((*(uint *)(puVar6 + 4) != param_3) || ((char)puVar6[6] != '\x01')) ||
              (*(int *)(puVar6 + 8) != *(int *)puVar5)) || ((char)puVar6[10] != '\x01')) {
            cVar8 = '\x01';
            goto LAB_00114810;
          }
          uVar2 = *(uint *)(puVar6 + 0xc);
          cVar8 = '\x01';
          if ((0x1800 < uVar2) || (uVar10 < uVar2)) goto LAB_00114810;
          memcpy(__dest,puVar6 + 0xe,(ulong)uVar2);
          uVar10 = uVar10 - *(uint *)(puVar6 + 0xc);
          __dest = (void *)((long)__dest + (ulong)*(uint *)(puVar6 + 0xc));
          *(int *)puVar5 = *(int *)puVar5 + 1;
        } while (uVar10 != 0);
      }
      cVar8 = (char)*puVar1;
      if (cVar8 == '\0') {
        uVar10 = 0;
LAB_00114904:
        _printk("%sicnss2_qmi: %s: QDSS trace file corrupted: remaining %u, end_valid %u, end %u",
                &DAT_0011c04b,"icnss_wlfw_qdss_data_send_sync",uVar10,cVar8);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: %s: QDSS trace file corrupted: remaining %u, end_valid %u, end %u"
                       ,&DAT_0011dab7,"icnss_wlfw_qdss_data_send_sync",uVar10,(char)*puVar1,
                       *(undefined1 *)((long)puVar6 + 0x181d));
LAB_00114954:
        iVar4 = -0x16;
      }
      else {
        if (*(char *)((long)puVar6 + 0x181d) == '\0') {
          uVar10 = 0;
          goto LAB_00114904;
        }
        iVar4 = icnss_genl_send_msg(pvVar7,1,param_2,param_3);
        if (iVar4 < 0) {
          _printk("%sicnss2_qmi: Fail to save QDSS trace data: %d\n",&DAT_0011c04b,iVar4);
          ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Fail to save QDSS trace data: %d\n",
                         &DAT_0011dab7,iVar4);
          goto LAB_00114954;
        }
      }
LAB_0011479c:
      kfree(pvVar7);
    }
    kfree(puVar5);
    puVar5 = puVar6;
  }
  kfree(puVar5);
LAB_001147d0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// icnss_wlfw_qdss_dnld_send_sync @ 00114a18 size=920
// signature: undefined icnss_wlfw_qdss_dnld_send_sync(void)
// callers: [icnss_driver_event_work, qdss_conf_download_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_wlfw_qdss_dnld_send_sync(long param_1)

{
  long lVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  uint uVar5;
  char *pcVar6;
  void *__src;
  uint uVar7;
  uint *local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined2 local_b0;
  char local_a8 [56];
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = (uint *)0x0;
  uStack_128 = 0;
  local_b0 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending QDSS config download message, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  puVar3 = (ushort *)kmalloc_trace(_icc_set_bw,0xdc0,0x181c);
  if (puVar3 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
    if (puVar4 == (ushort *)0x0) {
      iVar2 = -0xc;
    }
    else {
      local_a8[0x30] = '\0';
      local_a8[0x31] = '\0';
      local_a8[0x20] = '\0';
      local_a8[0x21] = '\0';
      local_a8[0x22] = '\0';
      local_a8[0x23] = '\0';
      local_a8[0x24] = '\0';
      local_a8[0x25] = '\0';
      local_a8[0x26] = '\0';
      local_a8[0x27] = '\0';
      local_a8[0x28] = '\0';
      local_a8[0x29] = '\0';
      local_a8[0x2a] = '\0';
      local_a8[0x2b] = '\0';
      local_a8[0x2c] = '\0';
      local_a8[0x2d] = '\0';
      local_a8[0x2e] = '\0';
      local_a8[0x2f] = '\0';
      local_a8[0x10] = '\0';
      local_a8[0x11] = '\0';
      local_a8[0x12] = '\0';
      local_a8[0x13] = '\0';
      local_a8[0x14] = '\0';
      local_a8[0x15] = '\0';
      local_a8[0x16] = '\0';
      local_a8[0x17] = '\0';
      local_a8[0x18] = '\0';
      local_a8[0x19] = '\0';
      local_a8[0x1a] = '\0';
      local_a8[0x1b] = '\0';
      local_a8[0x1c] = '\0';
      local_a8[0x1d] = '\0';
      local_a8[0x1e] = '\0';
      local_a8[0x1f] = '\0';
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
      if (*(long *)(param_1 + 0x108) == 0x6450) {
        snprintf(local_a8,0x32,"qdss_trace_config_%s%s.cfg","perf_","v1");
      }
      else {
        local_a8[0] = s_qdss_trace_config_cfg_0011efb1[0];
        local_a8[1] = s_qdss_trace_config_cfg_0011efb1[1];
        local_a8[2] = s_qdss_trace_config_cfg_0011efb1[2];
        local_a8[3] = s_qdss_trace_config_cfg_0011efb1[3];
        local_a8[4] = s_qdss_trace_config_cfg_0011efb1[4];
        local_a8[5] = s_qdss_trace_config_cfg_0011efb1[5];
        local_a8[6] = s_qdss_trace_config_cfg_0011efb1[6];
        local_a8[7] = s_qdss_trace_config_cfg_0011efb1[7];
        local_a8[8] = s_qdss_trace_config_cfg_0011efb1[8];
        local_a8[9] = s_qdss_trace_config_cfg_0011efb1[9];
        local_a8[10] = s_qdss_trace_config_cfg_0011efb1[10];
        local_a8[0xb] = s_qdss_trace_config_cfg_0011efb1[0xb];
        local_a8[0xc] = s_qdss_trace_config_cfg_0011efb1[0xc];
        local_a8[0xd] = s_qdss_trace_config_cfg_0011efb1[0xd];
        local_a8[0xe] = s_qdss_trace_config_cfg_0011efb1[0xe];
        local_a8[0xf] = s_qdss_trace_config_cfg_0011efb1[0xf];
        local_a8[0x10] = s_qdss_trace_config_cfg_0011efb1[0x10];
        local_a8[0x11] = s_qdss_trace_config_cfg_0011efb1[0x11];
        local_a8[0x12] = s_qdss_trace_config_cfg_0011efb1[0x12];
        local_a8[0x13] = s_qdss_trace_config_cfg_0011efb1[0x13];
        local_a8[0x14] = s_qdss_trace_config_cfg_0011efb1[0x14];
        local_a8[0x15] = s_qdss_trace_config_cfg_0011efb1[0x15];
      }
      icnss_add_fw_prefix_name(param_1,&local_e0,local_a8);
      iVar2 = firmware_request_nowarn(&local_130,&local_e0,*(long *)(param_1 + 8) + 0x10);
      if (iVar2 == 0) {
        uVar7 = *local_130;
        __src = *(void **)(local_130 + 2);
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Downloading QDSS: %s, size: %u\n",
                       &local_e0,uVar7);
        if (uVar7 != 0) {
          do {
            *(undefined1 *)puVar3 = 1;
            *(uint *)(puVar3 + 2) = uVar7;
            *(undefined1 *)(puVar3 + 4) = 1;
            *(undefined1 *)(puVar3 + 8) = 1;
            *(undefined1 *)(puVar3 + 0xc0c) = 1;
            if (uVar7 < 0x1801) {
              *(uint *)(puVar3 + 10) = uVar7;
              *(undefined1 *)((long)puVar3 + 0x1819) = 1;
              uVar5 = uVar7;
            }
            else {
              puVar3[10] = 0x1800;
              puVar3[0xb] = 0;
              uVar5 = 0x1800;
            }
            memcpy(puVar3 + 0xc,__src,(ulong)uVar5);
            iVar2 = qmi_txn_init(param_1 + 0x248,&uStack_128,
                                 &wlfw_qdss_trace_config_download_resp_msg_v01_ei,puVar4);
            if (iVar2 < 0) {
              pcVar6 = "%sicnss2_qmi: Failed to initialize txn for QDSS download request, err: %d\n"
              ;
LAB_00114d28:
              _printk(pcVar6,&DAT_0011c04b,iVar2);
              ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar2);
LAB_00114da0:
              release_firmware(local_130);
              goto LAB_00114c68;
            }
            iVar2 = qmi_send_request(param_1 + 0x248,0,&uStack_128,0x44,0x1817,
                                     &wlfw_qdss_trace_config_download_req_msg_v01_ei,puVar3);
            if (iVar2 < 0) {
              qmi_txn_cancel(&uStack_128);
              pcVar6 = "%sicnss2_qmi: Failed to send respond QDSS download request, err: %d\n";
              goto LAB_00114d28;
            }
            iVar2 = qmi_txn_wait(&uStack_128,*(undefined4 *)(param_1 + 0x128));
            if (iVar2 < 0) {
              pcVar6 = 
              "%sicnss2_qmi: Failed to wait for response of QDSS download request, err: %d\n";
              goto LAB_00114d28;
            }
            if (*puVar4 != 0) {
              _printk("%sicnss2_qmi: QDSS download request failed, result: %d, err: %d\n",
                      &DAT_0011c04b,*puVar4,puVar4[1]);
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2_qmi: QDSS download request failed, result: %d, err: %d\n",
                             &DAT_0011dab7,*puVar4,puVar4[1]);
              iVar2 = -(uint)*puVar4;
              goto LAB_00114da0;
            }
            uVar7 = uVar7 - *(uint *)(puVar3 + 10);
            __src = (void *)((long)__src + (ulong)*(uint *)(puVar3 + 10));
            *(int *)(puVar3 + 6) = *(int *)(puVar3 + 6) + 1;
          } while (uVar7 != 0);
        }
        release_firmware(local_130);
        iVar2 = 0;
      }
      else {
        _printk("%sicnss2_qmi: Failed to load QDSS: %s ret:%d\n",&DAT_0011c04b,&local_e0,iVar2);
        ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Failed to load QDSS: %s ret:%d\n",
                       &DAT_0011dab7,&local_e0,iVar2);
      }
LAB_00114c68:
      kfree(puVar3);
      puVar3 = puVar4;
    }
    kfree(puVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_wlan_mode_send_sync_msg @ 00114db4 size=804
// signature: undefined wlfw_wlan_mode_send_sync_msg(void)
// callers: [icnss_driver_event_work, icnss_send_wlan_disable_to_fw, icnss_send_wlan_enable_to_fw]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_wlan_mode_send_sync_msg(long param_1,int param_2)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  int iVar6;
  int *piVar7;
  ushort *puVar8;
  long lVar9;
  char *pcVar10;
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
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if (param_1 == 0) {
    iVar6 = -0x13;
    goto LAB_00114fbc;
  }
  if (((param_2 == 4) && (((uint)*(undefined8 *)(param_1 + 0x778) >> 9 & 1) != 0)) ||
     ((param_2 == 4 && (((uint)*(undefined8 *)(param_1 + 0x778) >> 0x10 & 1) == 0)))) {
LAB_00114fb8:
    iVar6 = 0;
    goto LAB_00114fbc;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending Mode request, state: 0x%lx, mode: %d\n",
                 *(undefined8 *)(param_1 + 0x778),param_2);
  piVar7 = (int *)kmalloc_trace(___list_add_valid,0xdc0,0x14);
  if (piVar7 == (int *)0x0) {
    iVar6 = -0xc;
    goto LAB_00114fbc;
  }
  puVar8 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar8 == (ushort *)0x0) {
    kfree(piVar7);
    iVar6 = -0xc;
    goto LAB_00114fbc;
  }
  *piVar7 = param_2;
  *(undefined1 *)(piVar7 + 1) = 1;
  uVar2 = *(uint *)(param_1 + 0x1644);
  *(byte *)((long)piVar7 + 5) = (byte)((uint)*(undefined8 *)(param_1 + 0x120) >> 1) & 1;
  if (99 < uVar2) {
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Setting WLAN_EN delay: %d ms\n");
    iVar6 = *(int *)(param_1 + 0x1644);
    *(undefined1 *)(piVar7 + 2) = 1;
    piVar7[3] = iVar6;
  }
  *(int *)(param_1 + 0xa98) = *(int *)(param_1 + 0xa98) + 1;
  iVar6 = qmi_txn_init(param_1 + 0x248,&local_a0,&wlfw_wlan_mode_resp_msg_v01_ei,puVar8);
  if (iVar6 < 0) {
    pcVar10 = "%sicnss2_qmi: fatal: Fail to init txn for Mode resp %d\n";
LAB_00115024:
    _printk(pcVar10,&DAT_0011c04b,iVar6);
    ipc_log_string(icnss_ipc_log_context,pcVar10,&DAT_0011dab7,iVar6);
  }
  else {
    iVar6 = qmi_send_request(param_1 + 0x248,0,&local_a0,0x22,0x1a,&wlfw_wlan_mode_req_msg_v01_ei,
                             piVar7);
    if (iVar6 < 0) {
      qmi_txn_cancel(&local_a0);
      pcVar10 = "%sicnss2_qmi: fatal: Fail to send Mode req %d\n";
      goto LAB_00115024;
    }
    uVar2 = *(uint *)(param_1 + 0x128);
    lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x1644));
    iVar6 = qmi_txn_wait(&local_a0,lVar9 + (ulong)uVar2);
    uVar5 = icnss_ipc_log_context;
    if (iVar6 < 0) {
      pcVar10 = "%sicnss2_qmi: fatal: Mode resp wait failed with ret %d\n";
      goto LAB_00115024;
    }
    if (*puVar8 == 0) {
      *(int *)(param_1 + 0xa9c) = *(int *)(param_1 + 0xa9c) + 1;
      if (param_2 == 4) {
        ipc_log_string(uVar5,"icnss2_qmi: Clear mode on 0x%lx, mode: %d\n",
                       *(undefined8 *)(param_1 + 0x778),4);
        puVar1 = (ulong *)(param_1 + 0x778);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 & 0xfffffffffffeffff;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      else {
        ipc_log_string(uVar5,"icnss2_qmi: Set mode on 0x%lx, mode: %d\n",
                       *(undefined8 *)(param_1 + 0x778),param_2);
        puVar1 = (ulong *)(param_1 + 0x778);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 0x10000;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      kfree(puVar8);
      kfree(piVar7);
      goto LAB_00114fb8;
    }
    _printk("%sicnss2_qmi: fatal: QMI Mode request rejected, result:%d error:%d\n",&DAT_0011c04b,
            *puVar8,puVar8[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: fatal: QMI Mode request rejected, result:%d error:%d\n",
                   &DAT_0011dab7,*puVar8,puVar8[1]);
    iVar6 = -(uint)*puVar8;
  }
  kfree(puVar8);
  kfree(piVar7);
  *(int *)(param_1 + 0xaa0) = *(int *)(param_1 + 0xaa0) + 1;
LAB_00114fbc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// wlfw_qdss_trace_start @ 001150f8 size=36
// signature: undefined wlfw_qdss_trace_start(void)
// callers: [qdss_tr_start_store]
//------------------------------------------------------------

void wlfw_qdss_trace_start(undefined8 param_1)

{
  wlfw_send_qdss_trace_mode_req(param_1,1,0);
  return;
}



//------------------------------------------------------------
// wlfw_send_qdss_trace_mode_req @ 0011511c size=576
// signature: undefined wlfw_send_qdss_trace_mode_req(void)
// callers: [wlfw_qdss_trace_stop, wlfw_qdss_trace_start]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_send_qdss_trace_mode_req(long param_1,undefined4 param_2,undefined8 param_3)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined1 *puVar4;
  ushort *puVar5;
  char *pcVar6;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar3 = -0x13;
    goto LAB_00115284;
  }
  puVar4 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,0x20);
  if (puVar4 == (undefined1 *)0x0) {
    iVar3 = -0xc;
    goto LAB_00115284;
  }
  puVar5 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  uVar2 = icnss_ipc_log_context;
  if (puVar5 == (ushort *)0x0) {
    iVar3 = -0xc;
  }
  else {
    iVar3 = *(int *)(param_1 + 0x15bc);
    if (iVar3 < 1) {
      iVar3 = 0;
    }
    if (1 < iVar3) {
      iVar3 = 2;
    }
    *puVar4 = 1;
    *(undefined4 *)(puVar4 + 4) = param_2;
    puVar4[8] = 1;
    puVar4[0x18] = 1;
    *(undefined8 *)(puVar4 + 0x10) = param_3;
    *(int *)(puVar4 + 0x1c) = iVar3;
    ipc_log_string(uVar2,"icnss2_qmi: %s: mode %u, option %llu, hw_trc_disable_override: %u",
                   "wlfw_send_qdss_trace_mode_req",param_2,param_3);
    iVar3 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_qdss_trace_mode_resp_msg_v01_ei,puVar5);
    if (iVar3 < 0) {
      pcVar6 = "%sicnss2_qmi: fatal: Fail to init txn for QDSS Mode resp %d\n";
LAB_001152e4:
      _printk(pcVar6,&DAT_0011c04b,iVar3);
      ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar3);
    }
    else {
      iVar3 = qmi_send_request(param_1 + 0x248,0,&local_90,0x45,0x19,
                               &wlfw_qdss_trace_mode_req_msg_v01_ei,puVar4);
      if (iVar3 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar6 = "%sicnss2_qmi: fatal: Fail to send QDSS Mode req %d\n";
        goto LAB_001152e4;
      }
      iVar3 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar3 < 0) {
        pcVar6 = "%sicnss2_qmi: fatal: QDSS Mode resp wait failed with rc %d\n";
        goto LAB_001152e4;
      }
      if (*puVar5 != 0) {
        _printk("%sicnss2_qmi: fatal: QMI QDSS Mode request rejected, result:%d error:%d\n",
                &DAT_0011c04b,*puVar5,puVar5[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: fatal: QMI QDSS Mode request rejected, result:%d error:%d\n",
                       &DAT_0011dab7,*puVar5,puVar5[1]);
        iVar3 = -(uint)*puVar5;
      }
    }
    kfree(puVar5);
  }
  kfree(puVar4);
LAB_00115284:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wlfw_qdss_trace_stop @ 00115360 size=36
// signature: undefined wlfw_qdss_trace_stop(void)
// callers: [qdss_tr_stop_store]
//------------------------------------------------------------

void wlfw_qdss_trace_stop(undefined8 param_1,undefined8 param_2)

{
  wlfw_send_qdss_trace_mode_req(param_1,0,param_2);
  return;
}



//------------------------------------------------------------
// wlfw_send_modem_shutdown_msg @ 00115388 size=524
// signature: undefined wlfw_send_modem_shutdown_msg(void)
// callers: [icnss_update_state_send_modem_shutdown]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_send_modem_shutdown_msg(long param_1)

{
  long lVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_001154bc;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) {
    iVar2 = -0x16;
    goto LAB_001154bc;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending modem shutdown request, state: 0x%lx\n")
  ;
  puVar3 = (undefined2 *)kmalloc_trace(___list_add_valid,0xdc0,2);
  if (puVar3 == (undefined2 *)0x0) {
    iVar2 = -0xc;
    goto LAB_001154bc;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *puVar3 = 0x101;
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_shutdown_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Fail to init txn for shutdown resp %d\n";
LAB_0011551c:
      _printk(pcVar5,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x43,4,&wlfw_shutdown_req_msg_v01_ei,
                               puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar5 = "%sicnss2_qmi: Fail to send Shutdown req %d\n";
        goto LAB_0011551c;
      }
      iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar5 = "%sicnss2_qmi: Shutdown resp wait failed with ret %d\n";
        goto LAB_0011551c;
      }
      if (*puVar4 != 0) {
        _printk("%sicnss2_qmi: QMI modem shutdown request rejected result:%d error:%d\n",
                &DAT_0011c04b,*puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: QMI modem shutdown request rejected result:%d error:%d\n",
                       &DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar4);
  }
  kfree(puVar3);
LAB_001154bc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_ini_send_sync_msg @ 00115598 size=588
// signature: undefined wlfw_ini_send_sync_msg(void)
// callers: [icnss_set_fw_log_mode]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_ini_send_sync_msg(long param_1,undefined1 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_001157ac;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending ini sync request, state: 0x%lx, fw_log_mode: %d\n",
                 *(undefined8 *)(param_1 + 0x778),param_2);
  puVar3 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,2);
  if (puVar3 == (undefined1 *)0x0) {
    iVar2 = -0xc;
    goto LAB_001157ac;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    kfree(puVar3);
    iVar2 = -0xc;
    goto LAB_001157ac;
  }
  iVar2 = *(int *)(param_1 + 0xaa4);
  *puVar3 = 1;
  puVar3[1] = param_2;
  *(int *)(param_1 + 0xaa4) = iVar2 + 1;
  iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_ini_resp_msg_v01_ei,puVar4);
  if (iVar2 < 0) {
    pcVar5 = "%sicnss2_qmi: fatal: Fail to init txn for INI resp %d\n";
LAB_00115720:
    _printk(pcVar5,&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x2f,4,&wlfw_ini_req_msg_v01_ei,puVar3);
    if (iVar2 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar5 = "%sicnss2_qmi: fatal: Fail to send INI req %d\n";
      goto LAB_00115720;
    }
    iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: fatal: INI resp wait failed with ret %d\n";
      goto LAB_00115720;
    }
    if (*puVar4 == 0) {
      *(int *)(param_1 + 0xaa8) = *(int *)(param_1 + 0xaa8) + 1;
      kfree(puVar4);
      kfree(puVar3);
      iVar2 = 0;
      goto LAB_001157ac;
    }
    _printk("%sicnss2_qmi: fatal: QMI INI request rejected, result:%d error:%d\n",&DAT_0011c04b,
            *puVar4,puVar4[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: fatal: QMI INI request rejected, result:%d error:%d\n",
                   &DAT_0011dab7,*puVar4,puVar4[1]);
    iVar2 = -(uint)*puVar4;
  }
  kfree(puVar4);
  kfree(puVar3);
  *(int *)(param_1 + 0xaac) = *(int *)(param_1 + 0xaac) + 1;
LAB_001157ac:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_athdiag_read_send_sync_msg @ 001157e8 size=684
// signature: undefined wlfw_athdiag_read_send_sync_msg(void)
// callers: [icnss_athdiag_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_athdiag_read_send_sync_msg
              (long param_1,undefined4 param_2,undefined4 param_3,uint param_4,void *param_5)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined4 *puVar4;
  ushort *puVar5;
  char *pcVar6;
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
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  if (param_1 == 0) {
    iVar3 = -0x13;
    goto LAB_00115968;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Diag read: state 0x%lx, offset %x, mem_type %x, data_len %u\n",
                 *(undefined8 *)(param_1 + 0x778),param_2,param_3,param_4);
  puVar4 = (undefined4 *)kmalloc_trace(___list_add_valid,0xdc0,0xc);
  if (puVar4 == (undefined4 *)0x0) {
    iVar3 = -0xc;
    goto LAB_00115968;
  }
  puVar5 = (ushort *)kmalloc_trace(_icc_set_bw,0xdc0,0x180c);
  if (puVar5 == (ushort *)0x0) {
    iVar3 = -0xc;
  }
  else {
    *puVar4 = param_2;
    puVar4[1] = param_3;
    puVar4[2] = param_4;
    iVar3 = qmi_txn_init(param_1 + 0x248,&local_b0,&wlfw_athdiag_read_resp_msg_v01_ei,puVar5);
    if (iVar3 < 0) {
      pcVar6 = "%sicnss2_qmi: Fail to init txn for Athdiag Read resp %d\n";
LAB_001159d4:
      _printk(pcVar6,&DAT_0011c04b,iVar3);
      ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar3);
    }
    else {
      iVar3 = qmi_send_request(param_1 + 0x248,0,&local_b0,0x30,0x15,
                               &wlfw_athdiag_read_req_msg_v01_ei,puVar4);
      if (iVar3 < 0) {
        qmi_txn_cancel(&local_b0);
        pcVar6 = "%sicnss2_qmi: Fail to send Athdiag Read req %d\n";
        goto LAB_001159d4;
      }
      iVar3 = qmi_txn_wait(&local_b0,*(undefined4 *)(param_1 + 0x128));
      if (iVar3 < 0) {
        pcVar6 = "%sicnss2_qmi: Athdaig Read resp wait failed with ret %d\n";
        goto LAB_001159d4;
      }
      if (*puVar5 == 0) {
        uVar1 = *(uint *)(puVar5 + 4);
        if (((char)puVar5[2] == '\0') || (uVar1 < param_4)) {
          _printk("%sicnss2_qmi: Athdiag read data is invalid, data_valid = %u, data_len = %u\n",
                  &DAT_0011c04b);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2_qmi: Athdiag read data is invalid, data_valid = %u, data_len = %u\n"
                         ,&DAT_0011dab7,(char)puVar5[2],*(undefined4 *)(puVar5 + 4));
          iVar3 = -0x16;
        }
        else {
          if (0x1800 < uVar1) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("memcpy");
          }
          memcpy(param_5,puVar5 + 6,(ulong)uVar1);
          iVar3 = 0;
        }
      }
      else {
        _printk("%sicnss2_qmi: QMI Athdiag Read request rejected, result:%d error:%d\n",
                &DAT_0011c04b,*puVar5,puVar5[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: QMI Athdiag Read request rejected, result:%d error:%d\n",
                       &DAT_0011dab7,*puVar5,puVar5[1]);
        iVar3 = -(uint)*puVar5;
      }
    }
    kfree(puVar5);
  }
  kfree(puVar4);
LAB_00115968:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// wlfw_athdiag_write_send_sync_msg @ 00115a98 size=600
// signature: undefined wlfw_athdiag_write_send_sync_msg(void)
// callers: [icnss_athdiag_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_athdiag_write_send_sync_msg
              (long param_1,undefined4 param_2,undefined4 param_3,uint param_4,void *param_5)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00115c04;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Diag write: state 0x%lx, offset %x, mem_type %x, data_len %u, data %pK\n"
                 ,*(undefined8 *)(param_1 + 0x778),param_2,param_3,param_4,param_5);
  puVar3 = (undefined4 *)kmalloc_trace(_icc_set_bw,0xdc0,0x180c);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00115c04;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *puVar3 = param_2;
    puVar3[1] = param_3;
    puVar3[2] = param_4;
    if (0x1800 < param_4) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("memcpy");
    }
    memcpy(puVar3 + 3,param_5,(ulong)param_4);
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_a0,&wlfw_athdiag_write_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Fail to init txn for Athdiag Write resp %d\n";
LAB_00115c6c:
      _printk(pcVar5,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_a0,0x31,0x1813,
                               &wlfw_athdiag_write_req_msg_v01_ei,puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_a0);
        pcVar5 = "%sicnss2_qmi: Fail to send Athdiag Write req %d\n";
        goto LAB_00115c6c;
      }
      iVar2 = qmi_txn_wait(&local_a0,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar5 = "%sicnss2_qmi: Athdiag Write resp wait failed with ret %d\n";
        goto LAB_00115c6c;
      }
      if (*puVar4 == 0) {
        iVar2 = 0;
      }
      else {
        _printk("%sicnss2_qmi: QMI Athdiag Write request rejected, result:%d error:%d\n",
                &DAT_0011c04b,*puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: QMI Athdiag Write request rejected, result:%d error:%d\n",
                       &DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar4);
  }
  kfree(puVar3);
LAB_00115c04:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_rejuvenate_ack_send_sync_msg @ 00115cf4 size=568
// signature: undefined wlfw_rejuvenate_ack_send_sync_msg(void)
// callers: [icnss_fw_crashed]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_rejuvenate_ack_send_sync_msg(long param_1)

{
  int iVar1;
  long lVar2;
  ushort *puVar3;
  char *pcVar4;
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
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar1 = -0x13;
    goto LAB_00115ef4;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending rejuvenate ack request, state: 0x%lx\n",
                 *(undefined8 *)(param_1 + 0x778));
  lVar2 = kmalloc_trace(___list_add_valid,0xdc0,1);
  if (lVar2 == 0) {
    iVar1 = -0xc;
    goto LAB_00115ef4;
  }
  puVar3 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar3 == (ushort *)0x0) {
    kfree(lVar2);
    iVar1 = -0xc;
    goto LAB_00115ef4;
  }
  *(int *)(param_1 + 0xab4) = *(int *)(param_1 + 0xab4) + 1;
  iVar1 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_rejuvenate_ack_resp_msg_v01_ei,puVar3);
  if (iVar1 < 0) {
    pcVar4 = "%sicnss2_qmi: fatal: Fail to init txn for Rejuvenate Ack resp %d\n";
LAB_00115e68:
    _printk(pcVar4,&DAT_0011c04b,iVar1);
    ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7,iVar1);
  }
  else {
    iVar1 = qmi_send_request(param_1 + 0x248,0,&local_90,0x3a,0,&wlfw_rejuvenate_ack_req_msg_v01_ei,
                             lVar2);
    if (iVar1 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar4 = "%sicnss2_qmi: fatal: Fail to send Rejuvenate Ack req %d\n";
      goto LAB_00115e68;
    }
    iVar1 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar1 < 0) {
      pcVar4 = "%sicnss2_qmi: fatal: Rejuvenate Ack resp wait failed with ret %d\n";
      goto LAB_00115e68;
    }
    if (*puVar3 == 0) {
      *(int *)(param_1 + 0xab8) = *(int *)(param_1 + 0xab8) + 1;
      kfree(puVar3);
      kfree(lVar2);
      iVar1 = 0;
      goto LAB_00115ef4;
    }
    _printk("%sicnss2_qmi: fatal: QMI Rejuvenate Ack request rejected, result:%d error:%d\n",
            &DAT_0011c04b,*puVar3,puVar3[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: fatal: QMI Rejuvenate Ack request rejected, result:%d error:%d\n",
                   &DAT_0011dab7,*puVar3,puVar3[1]);
    iVar1 = -(uint)*puVar3;
  }
  kfree(puVar3);
  kfree(lVar2);
  *(int *)(param_1 + 0xabc) = *(int *)(param_1 + 0xabc) + 1;
LAB_00115ef4:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// wlfw_dynamic_feature_mask_send_sync_msg @ 00115f30 size=660
// signature: undefined wlfw_dynamic_feature_mask_send_sync_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_dynamic_feature_mask_send_sync_msg(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_001160ec;
  }
  if ((*(ulong *)(param_1 + 0x778) & 1) == 0) {
    _printk("%sicnss2_qmi: Invalid state for dynamic feature: 0x%lx\n",&DAT_0011c04b,
            *(ulong *)(param_1 + 0x778));
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Invalid state for dynamic feature: 0x%lx\n",
                   &DAT_0011dab7,*(undefined8 *)(param_1 + 0x778));
    iVar2 = -0x16;
    goto LAB_001160ec;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x120) >> 6 & 1) == 0) {
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: FW rejuvenate is disabled from quirks\n");
    iVar2 = 0;
    goto LAB_001160ec;
  }
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Sending dynamic feature mask request, val 0x%llx, state: 0x%lx\n",
                 param_2);
  puVar3 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,0x10);
  if (puVar3 == (undefined1 *)0x0) {
    iVar2 = -0xc;
    goto LAB_001160ec;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,0x20);
  if (puVar4 == (ushort *)0x0) {
    kfree(puVar3);
    iVar2 = -0xc;
    goto LAB_001160ec;
  }
  *puVar3 = 1;
  *(undefined8 *)(puVar3 + 8) = param_2;
  iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_dynamic_feature_mask_resp_msg_v01_ei,puVar4);
  if (iVar2 < 0) {
    pcVar5 = "%sicnss2_qmi: Fail to init txn for Dynamic Feature Mask resp %d\n";
LAB_0011614c:
    _printk(pcVar5,&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x3b,0xb,
                             &wlfw_dynamic_feature_mask_req_msg_v01_ei,puVar3);
    if (iVar2 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar5 = "%sicnss2_qmi: Fail to send Dynamic Feature Mask req %d\n";
      goto LAB_0011614c;
    }
    iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Dynamic Feature Mask resp wait failed with ret %d\n";
      goto LAB_0011614c;
    }
    if (*puVar4 == 0) {
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: prev_mask_valid %u, prev_mask 0x%llx, curr_maks_valid %u, curr_mask 0x%llx\n"
                     ,(char)puVar4[2],*(undefined8 *)(puVar4 + 4),(char)puVar4[8],
                     *(undefined8 *)(puVar4 + 0xc));
    }
    else {
      _printk("%sicnss2_qmi: QMI Dynamic Feature Mask request rejected, result:%d error:%d\n",
              &DAT_0011c04b,*puVar4,puVar4[1]);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: QMI Dynamic Feature Mask request rejected, result:%d error:%d\n"
                     ,&DAT_0011dab7,*puVar4,puVar4[1]);
      iVar2 = -(uint)*puVar4;
    }
  }
  kfree(puVar4);
  kfree(puVar3);
LAB_001160ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_qdss_trace_mem_info_send_sync @ 001161c8 size=740
// signature: undefined wlfw_qdss_trace_mem_info_send_sync(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_qdss_trace_mem_info_send_sync(long param_1)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  char *pcVar6;
  ulong uVar7;
  undefined4 *puVar8;
  long lVar9;
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
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) {
    iVar3 = -0x16;
    goto LAB_00116388;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending QDSS trace mem info, state: 0x%lx\n");
  puVar4 = (uint *)kmalloc_trace(_kfree,0xdc0,0x4f0);
  if (puVar4 == (uint *)0x0) {
    iVar3 = -0xc;
    goto LAB_00116388;
  }
  puVar5 = (uint *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar5 == (uint *)0x0) {
    iVar3 = -0xc;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0xd08);
    *puVar4 = uVar1;
    if (uVar1 < 0x35) {
      if (uVar1 != 0) {
        uVar7 = 0;
        puVar8 = (undefined4 *)(param_1 + 0xd2c);
        lVar9 = -0x4e0;
        do {
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2_qmi: Memory for FW, va: 0x%pK, pa: %pa, size: 0x%zx, type: %u\n",
                         *(undefined8 *)(puVar8 + -5),puVar8 + -3,*(undefined8 *)(puVar8 + -7),
                         *puVar8);
          if (lVar9 == 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1164a8);
            (*pcVar2)();
          }
          *(undefined8 *)((long)puVar4 + lVar9 + 0x4e8) = *(undefined8 *)(puVar8 + -3);
          if ((lVar9 == 0) ||
             (*(int *)((long)puVar4 + lVar9 + 0x4f0) = (int)*(undefined8 *)(puVar8 + -7),
             lVar9 + 3U < 0xfffffffffffffb0f)) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x1164a4);
            (*pcVar2)();
          }
          uVar7 = uVar7 + 1;
          *(undefined4 *)((long)puVar4 + lVar9 + 0x4f4) = *puVar8;
          puVar8 = puVar8 + 10;
          lVar9 = lVar9 + 0x18;
        } while (uVar7 < *puVar4);
      }
      iVar3 = qmi_txn_init(param_1 + 0x248,&local_b0,&wlfw_qdss_trace_mem_info_resp_msg_v01_ei,
                           puVar5);
      if (iVar3 < 0) {
        pcVar6 = "%sicnss2_qmi: Fail to initialize txn for QDSS trace mem request: err %d\n";
      }
      else {
        iVar3 = qmi_send_request(param_1 + 0x248,0,&local_b0,0x40,0x37c,
                                 &wlfw_qdss_trace_mem_info_req_msg_v01_ei,puVar4);
        if (iVar3 < 0) {
          qmi_txn_cancel(&local_b0);
          pcVar6 = "%sicnss2_qmi: Fail to send QDSS trace mem info request: err %d\n";
        }
        else {
          iVar3 = qmi_txn_wait(&local_b0,*(undefined4 *)(param_1 + 0x128));
          if (-1 < iVar3) {
            if ((short)*puVar5 == 0) {
              iVar3 = 0;
            }
            else {
              _printk("%sicnss2_qmi: QDSS trace mem info request failed, result: %d, err: %d\n",
                      &DAT_0011c04b,(short)*puVar5,*(undefined2 *)((long)puVar5 + 2));
              ipc_log_string(icnss_ipc_log_context,
                             "%sicnss2_qmi: QDSS trace mem info request failed, result: %d, err: %d\n"
                             ,&DAT_0011dab7,(short)*puVar5,*(undefined2 *)((long)puVar5 + 2));
              iVar3 = -(uint)(ushort)*puVar5;
            }
            goto LAB_0011635c;
          }
          pcVar6 = 
          "%sicnss2_qmi: Fail to wait for response of QDSS trace mem info request, err %d\n";
        }
      }
      _printk(pcVar6,&DAT_0011c04b,iVar3);
      ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar3);
    }
    else {
      _printk("%sicnss2_qmi: Invalid seg len %u\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Invalid seg len %u\n",&DAT_0011dab7,
                     *(undefined4 *)(param_1 + 0xd08));
      iVar3 = -0x16;
    }
LAB_0011635c:
    kfree(puVar4);
    puVar4 = puVar5;
  }
  kfree(puVar4);
LAB_00116388:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// icnss_wlfw_m3_dump_upload_done_send_sync @ 001164b0 size=520
// signature: undefined icnss_wlfw_m3_dump_upload_done_send_sync(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_wlfw_m3_dump_upload_done_send_sync(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  puVar3 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,8);
  if (puVar3 == (ushort *)0x0) {
    iVar2 = -0xc;
    goto LAB_001165dc;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    ipc_log_string(icnss_ipc_log_context,
                   "icnss2_qmi: Sending M3 Upload done req, pdev %d, status %d\n",param_2,param_3);
    *(undefined4 *)puVar3 = param_2;
    *(undefined4 *)(puVar3 + 2) = param_3;
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_a0,&wlfw_m3_dump_upload_done_resp_msg_v01_ei,puVar4)
    ;
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Fail to initialize txn for M3 dump upload done req: err %d\n";
LAB_00116640:
      _printk(pcVar5,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_a0,0x4e,0xe,
                               &wlfw_m3_dump_upload_done_req_msg_v01_ei,puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_a0);
        pcVar5 = "%sicnss2_qmi: Fail to send M3 dump upload done request: err %d\n";
        goto LAB_00116640;
      }
      iVar2 = qmi_txn_wait(&local_a0,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar5 = "%sicnss2_qmi: Fail to wait for response of M3 dump upload done request, err %d\n";
        goto LAB_00116640;
      }
      if (*puVar4 != 0) {
        _printk("%sicnss2_qmi: M3 Dump Upload Done Req failed, result: %d, err: 0x%X\n",
                &DAT_0011c04b,*puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: M3 Dump Upload Done Req failed, result: %d, err: 0x%X\n",
                       &DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar3);
    puVar3 = puVar4;
  }
  kfree(puVar3);
LAB_001165dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_process_twt_cfg_ind_event @ 001166bc size=668
// signature: undefined icnss_process_twt_cfg_ind_event(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_process_twt_cfg_ind_event(long param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  long lVar6;
  int iVar7;
  undefined1 *puVar8;
  ushort *puVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  char *pcVar12;
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
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0x13 & 1) == 0) {
    _printk("%sicnss2_qmi: Drop FW WFC indication as IMS QMI not connected\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Drop FW WFC indication as IMS QMI not connected\n",&DAT_0011dab7);
    iVar7 = -0x16;
    goto LAB_00116870;
  }
  puVar8 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,0x28);
  if (puVar8 == (undefined1 *)0x0) {
    iVar7 = -0xc;
    goto LAB_00116870;
  }
  puVar9 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar9 == (ushort *)0x0) {
    kfree(puVar8);
    iVar7 = -0xc;
    goto LAB_00116870;
  }
  uVar11 = *(undefined8 *)(param_2 + 8);
  uVar1 = param_2[0x10];
  uVar4 = *(undefined2 *)(param_2 + 0x12);
  *puVar8 = *param_2;
  uVar2 = param_2[0x14];
  *(undefined8 *)(puVar8 + 8) = uVar11;
  uVar5 = *(undefined2 *)(param_2 + 0x16);
  puVar8[0x10] = uVar1;
  uVar1 = param_2[0x18];
  *(undefined2 *)(puVar8 + 0x12) = uVar4;
  uVar4 = *(undefined2 *)(param_2 + 0x1a);
  puVar8[0x14] = uVar2;
  uVar2 = param_2[0x20];
  *(undefined2 *)(puVar8 + 0x16) = uVar5;
  uVar11 = icnss_ipc_log_context;
  uVar3 = param_2[0x21];
  puVar8[0x18] = uVar1;
  uVar10 = *(undefined8 *)(param_1 + 0x778);
  *(undefined2 *)(puVar8 + 0x1a) = uVar4;
  puVar8[0x20] = uVar2;
  puVar8[0x21] = uVar3;
  ipc_log_string(uVar11,"icnss2_qmi: CNSS->IMS: TWT_CFG_REQ: state: 0x%lx\n",uVar10);
  iVar7 = qmi_txn_init(param_1 + 0x4d8,&local_a0,
                       &ims_private_service_wfc_call_twt_config_rsp_msg_v01_ei,puVar9);
  if (iVar7 < 0) {
    pcVar12 = "%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Txn Init Err: %d\n";
LAB_001168e0:
    _printk(pcVar12,&DAT_0011c04b,iVar7);
    ipc_log_string(icnss_ipc_log_context,pcVar12,&DAT_0011dab7,iVar7);
  }
  else {
    iVar7 = qmi_send_request(param_1 + 0x4d8,0,&local_a0,0x41,0x23,
                             &ims_private_service_wfc_call_twt_config_req_msg_v01_ei,puVar8);
    if (iVar7 < 0) {
      qmi_txn_cancel(&local_a0);
      pcVar12 = "%sicnss2_qmi: CNSS->IMS: TWT_CFG_REQ: QMI Send Err: %d\n";
      goto LAB_001168e0;
    }
    iVar7 = qmi_txn_wait(&local_a0,*(undefined4 *)(param_1 + 0x128));
    if (iVar7 < 0) {
      pcVar12 = "%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: QMI Wait Err: %d\n";
      goto LAB_001168e0;
    }
    if (*puVar9 == 0) {
      iVar7 = 0;
    }
    else {
      _printk("%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: Result: %d Err: %d\n",&DAT_0011c04b,*puVar9,
              puVar9[1]);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: IMS->CNSS: TWT_CFG_RSP: Result: %d Err: %d\n",&DAT_0011dab7,
                     *puVar9,puVar9[1]);
      iVar7 = -(uint)*puVar9;
    }
  }
  kfree(puVar8);
  kfree(puVar9);
LAB_00116870:
  kfree(param_2);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// icnss_connect_to_fw_server @ 0011695c size=280
// signature: undefined icnss_connect_to_fw_server(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

int icnss_connect_to_fw_server(long param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
  }
  else {
    local_40 = param_2[1];
    local_48 = CONCAT44(*param_2,0x2a);
    iVar2 = kernel_connect(*(undefined8 *)(param_1 + 0x248),&local_48,0xc,0);
    if (iVar2 < 0) {
      _printk("%sicnss2_qmi: Fail to connect to remote service port\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Fail to connect to remote service port\n",
                     &DAT_0011dab7);
    }
    else {
      _printk("%sicnss2_qmi: QMI Server Connected: state: 0x%lx\n",&DAT_0011e9ea,
              *(undefined8 *)(param_1 + 0x778));
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: QMI Server Connected: state: 0x%lx\n",
                     &DAT_0011dab7,*(undefined8 *)(param_1 + 0x778));
      iVar2 = 0;
    }
  }
  kfree(param_2);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_clear_server @ 00116a78 size=364
// signature: undefined icnss_clear_server(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

undefined8 icnss_clear_server(long param_1)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined8 uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    uVar6 = 0xffffffed;
  }
  else {
    _printk("%sicnss2_qmi: QMI Service Disconnected: 0x%lx\n",&DAT_0011e9ea,
            *(undefined8 *)(param_1 + 0x778));
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: QMI Service Disconnected: 0x%lx\n",
                   &DAT_0011dab7,*(undefined8 *)(param_1 + 0x778));
    puVar2 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xfffffffffffffffe;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    puVar2 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 | 0x100000;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    lVar1 = param_1 + 0x248;
    qmi_handle_release(lVar1);
    puVar2 = (ulong *)(param_1 + 0x778);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xffffffffffefffff;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    iVar5 = qmi_handle_init(lVar1,0x1826,&wlfw_qmi_ops,wlfw_msg_handlers);
    if (-1 < iVar5) {
      uVar7 = 3;
      if (*(long *)(param_1 + 0x108) != 0x6450 && *(long *)(param_1 + 0x108) != 0x6750) {
        uVar7 = 0;
      }
      iVar5 = qmi_add_lookup(lVar1,0x45,1,uVar7);
      if (-1 < iVar5) {
        return 0;
      }
    }
    _printk("%sicnss2_qmi: WLFW server registration failed\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: WLFW server registration failed\n",
                   &DAT_0011dab7);
    uVar6 = 0;
  }
  return uVar6;
}



//------------------------------------------------------------
// icnss_unregister_fw_service @ 00116c0c size=64
// signature: undefined icnss_unregister_fw_service(void)
// callers: [icnss_remove, icnss_probe]
//------------------------------------------------------------

void icnss_unregister_fw_service(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  puVar1 = (ulong *)(param_1 + 0x778);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 | 0x100000;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  qmi_handle_release(param_1 + 0x248);
  return;
}



//------------------------------------------------------------
// icnss_register_fw_service @ 00116c5c size=116
// signature: undefined icnss_register_fw_service(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_register_fw_service(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = qmi_handle_init(param_1 + 0x248,0x1826,&wlfw_qmi_ops,wlfw_msg_handlers);
  if (-1 < iVar1) {
    uVar2 = 3;
    if (*(long *)(param_1 + 0x108) != 0x6450 && *(long *)(param_1 + 0x108) != 0x6750) {
      uVar2 = 0;
    }
    qmi_add_lookup(param_1 + 0x248,0x45,1,uVar2);
  }
  return;
}



//------------------------------------------------------------
// icnss_send_wlan_enable_to_fw @ 00116cd4 size=1272
// signature: undefined icnss_send_wlan_enable_to_fw(void)
// callers: [icnss_wlan_enable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_send_wlan_enable_to_fw(long param_1,uint *param_2,ulong param_3,char *param_4)

{
  undefined4 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined1 *puVar4;
  size_t sVar5;
  undefined1 *__dest;
  ushort *puVar6;
  void *pvVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  char *pcVar13;
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
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Mode: %d, config: %pK, host_version: %s\n",
                 param_3,param_2,param_4);
  if (((int)param_3 == 3) || ((int)param_3 == 5)) {
LAB_00116d40:
    iVar3 = wlfw_wlan_mode_send_sync_msg(param_1,param_3 & 0xffffffff);
  }
  else if ((param_2 == (uint *)0x0) || (param_4 == (char *)0x0)) {
    _printk("%sicnss2_qmi: Invalid cfg pointer, config: %pK, host_version: %pK\n",&DAT_0011c04b,
            param_2,param_4);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Invalid cfg pointer, config: %pK, host_version: %pK\n",
                   &DAT_0011dab7,param_2,param_4);
    iVar3 = -0x16;
  }
  else {
    puVar4 = (undefined1 *)kmalloc_trace(_pm_relax,0xdc0,0xd44);
    if (puVar4 == (undefined1 *)0x0) {
      iVar3 = -0xc;
      goto LAB_00116d5c;
    }
    *puVar4 = 1;
    sVar5 = strlen(param_4);
    if (0xf < sVar5) {
      sVar5 = 0x10;
    }
    memcpy(puVar4 + 1,param_4,sVar5);
    uVar10 = *param_2;
    (puVar4 + 1)[sVar5] = 0;
    puVar4[0x12] = 1;
    if (uVar10 < 0xd) {
      *(uint *)(puVar4 + 0x14) = uVar10;
      if (uVar10 != 0) goto LAB_00116e18;
    }
    else {
      *(undefined4 *)(puVar4 + 0x14) = 0xc;
LAB_00116e18:
      uVar8 = 0;
      puVar12 = (undefined4 *)(*(long *)(param_2 + 2) + 8);
      puVar11 = (undefined4 *)(puVar4 + 0x28);
      do {
        if (uVar8 == 0xc) goto LAB_001171c4;
        uVar8 = uVar8 + 1;
        puVar11[-4] = puVar12[-2];
        puVar11[-3] = puVar12[-1];
        puVar11[-2] = *puVar12;
        puVar11[-1] = puVar12[1];
        puVar1 = puVar12 + 2;
        puVar12 = puVar12 + 6;
        *puVar11 = *puVar1;
        puVar11 = puVar11 + 5;
      } while (uVar8 < *(uint *)(puVar4 + 0x14));
    }
    uVar10 = param_2[4];
    puVar4[0x108] = 1;
    if (uVar10 < 0x19) {
      *(uint *)(puVar4 + 0x10c) = uVar10;
      if (uVar10 != 0) goto LAB_00116e94;
    }
    else {
      *(undefined4 *)(puVar4 + 0x10c) = 0x18;
LAB_00116e94:
      uVar8 = 0;
      puVar12 = (undefined4 *)(puVar4 + 0x118);
      puVar11 = (undefined4 *)(*(long *)(param_2 + 6) + 8);
      do {
        if (uVar8 == 0x18) {
LAB_001171c4:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1171c8);
          (*pcVar2)();
        }
        uVar8 = uVar8 + 1;
        puVar12[-2] = puVar11[-2];
        puVar12[-1] = puVar11[-1];
        *puVar12 = *puVar11;
        puVar12 = puVar12 + 3;
        puVar11 = puVar11 + 3;
      } while (uVar8 < *(uint *)(puVar4 + 0x10c));
    }
    lVar9 = *(long *)(param_1 + 0x108);
    if (lVar9 == 0x6450) {
      uVar10 = param_2[0x10];
      __dest = puVar4 + 0x37c;
      pvVar7 = *(void **)(param_2 + 0x12);
      if (0x25 < uVar10) {
        uVar10 = 0x26;
      }
      puVar4[0x374] = 1;
      sVar5 = (size_t)(uVar10 << 2);
      *(uint *)(puVar4 + 0x378) = uVar10;
LAB_00116f7c:
      memcpy(__dest,pvVar7,sVar5);
      if ((*(long *)(param_1 + 0x108) == 0x6450) && ((*(byte *)(param_1 + 0x17b0) >> 4 & 1) != 0)) {
        uVar10 = param_2[0x17];
        pvVar7 = *(void **)(param_2 + 0x18);
        if (99 < uVar10) {
          uVar10 = 100;
        }
        puVar4[0x46c] = 1;
        *(uint *)(puVar4 + 0x470) = uVar10;
        memcpy(puVar4 + 0x474,pvVar7,(ulong)(uVar10 * 0xc));
      }
    }
    else {
      if (lVar9 == 0xabcd) {
        uVar10 = param_2[8];
        pvVar7 = *(void **)(param_2 + 10);
        __dest = puVar4 + 0x238;
        if (0x17 < uVar10) {
          uVar10 = 0x18;
        }
        puVar4[0x230] = 1;
        sVar5 = (size_t)(uVar10 << 2);
        *(uint *)(puVar4 + 0x234) = uVar10;
        goto LAB_00116f7c;
      }
      if (lVar9 == 0x6750) {
        uVar10 = param_2[0xc];
        pvVar7 = *(void **)(param_2 + 0xe);
        __dest = puVar4 + 0x2a0;
        if (0x23 < uVar10) {
          uVar10 = 0x24;
        }
        puVar4[0x298] = 1;
        sVar5 = (size_t)(uVar10 << 2);
        *(uint *)(puVar4 + 0x29c) = uVar10;
        goto LAB_00116f7c;
      }
    }
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b0 = 0;
    if (param_1 == 0) {
      iVar3 = -0x13;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending config request, state: 0x%lx\n",
                     *(undefined8 *)(param_1 + 0x778));
      puVar6 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
      if (puVar6 != (ushort *)0x0) {
        *(int *)(param_1 + 0xa8c) = *(int *)(param_1 + 0xa8c) + 1;
        iVar3 = qmi_txn_init(param_1 + 0x248,&local_b0,&wlfw_wlan_cfg_resp_msg_v01_ei,puVar6);
        if (iVar3 < 0) {
          pcVar13 = "%sicnss2_qmi: fatal: Fail to init txn for Config resp %d\n";
LAB_00117130:
          _printk(pcVar13,&DAT_0011c04b,iVar3);
          ipc_log_string(icnss_ipc_log_context,pcVar13,&DAT_0011dab7,iVar3);
        }
        else {
          iVar3 = qmi_send_request(param_1 + 0x248,0,&local_b0,0x23,0xd25,
                                   &wlfw_wlan_cfg_req_msg_v01_ei,puVar4);
          if (iVar3 < 0) {
            qmi_txn_cancel(&local_b0);
            pcVar13 = "%sicnss2_qmi: fatal: Fail to send Config req %d\n";
            goto LAB_00117130;
          }
          iVar3 = qmi_txn_wait(&local_b0,*(undefined4 *)(param_1 + 0x128));
          if (iVar3 < 0) {
            pcVar13 = "%sicnss2_qmi: fatal: Config resp wait failed with ret %d\n";
            goto LAB_00117130;
          }
          if (*puVar6 == 0) {
            *(int *)(param_1 + 0xa90) = *(int *)(param_1 + 0xa90) + 1;
            kfree(puVar6);
            kfree(puVar4);
            goto LAB_00116d40;
          }
          _printk("%sicnss2_qmi: fatal: QMI Config request rejected, result:%d error:%d\n",
                  &DAT_0011c04b,*puVar6,puVar6[1]);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2_qmi: fatal: QMI Config request rejected, result:%d error:%d\n",
                         &DAT_0011dab7,*puVar6,puVar6[1]);
          iVar3 = -(uint)*puVar6;
        }
        kfree(puVar6);
        *(int *)(param_1 + 0xa94) = *(int *)(param_1 + 0xa94) + 1;
        kfree(puVar4);
        if (iVar3 == 0) goto LAB_00116d40;
        goto LAB_00116d50;
      }
      iVar3 = -0xc;
    }
    kfree(puVar4);
  }
LAB_00116d50:
  if ((*(ulong *)(param_1 + 0x120) & 4) != 0) {
    iVar3 = 0;
  }
LAB_00116d5c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar3);
  }
  return;
}



//------------------------------------------------------------
// icnss_send_wlan_disable_to_fw @ 001171d0 size=32
// signature: undefined icnss_send_wlan_disable_to_fw(void)
// callers: [icnss_wlan_disable]
//------------------------------------------------------------

void icnss_send_wlan_disable_to_fw(undefined8 param_1)

{
  wlfw_wlan_mode_send_sync_msg(param_1,4);
  return;
}



//------------------------------------------------------------
// wlfw_host_cap_send_sync @ 001171f4 size=1176
// signature: undefined wlfw_host_cap_send_sync(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_host_cap_send_sync(long param_1)

{
  uint uVar1;
  undefined1 uVar2;
  undefined8 uVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  ushort *puVar7;
  long lVar8;
  undefined4 uVar9;
  char *pcVar10;
  undefined8 uVar11;
  long local_d0 [4];
  undefined4 local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  int local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_ac = 0;
  local_d0[2] = 0;
  local_d0[3] = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending host capability message, state: 0x%lx\n"
                 ,*(undefined8 *)(param_1 + 0x778));
  puVar6 = (ushort *)kmalloc_trace(_wait_for_completion,0xdc0,1000);
  if (puVar6 == (ushort *)0x0) {
    iVar4 = -0xc;
    goto LAB_001175ac;
  }
  puVar7 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  uVar3 = icnss_ipc_log_context;
  if (puVar7 == (ushort *)0x0) {
    iVar4 = -0xc;
  }
  else {
    uVar2 = *(undefined1 *)(param_1 + 0x130);
    *(undefined1 *)puVar6 = 1;
    puVar6[2] = 1;
    puVar6[3] = 0;
    puVar6[0x4d] = 0x101;
    *(undefined1 *)(puVar6 + 0x53) = 1;
    *(undefined1 *)((long)puVar6 + 0xa7) = uVar2;
    ipc_log_string(uVar3,"icnss2_qmi: Calibration done is %d\n");
    if (((*(char *)(param_1 + 0xceb) != '\0') &&
        (iVar4 = icnss_get_iova(param_1,local_d0 + 3,local_d0 + 2), iVar4 == 0)) &&
       (iVar4 = icnss_get_iova_ipa(param_1,local_d0 + 1,local_d0), iVar4 == 0)) {
      uVar11 = *(undefined8 *)(param_1 + 0x750);
      uVar1 = *(uint *)(param_1 + 0x768);
      *(undefined1 *)(puVar6 + 0x7c) = 1;
      uVar3 = icnss_ipc_log_context;
      *(undefined8 *)(puVar6 + 0x88) = uVar11;
      *(ulong *)(puVar6 + 0x8c) = (ulong)uVar1;
      *(long *)(puVar6 + 0x80) = local_d0[3];
      *(long *)(puVar6 + 0x84) = local_d0[0] + local_d0[2];
      ipc_log_string(uVar3,"icnss2_qmi: Sending iova starting 0x%llx with size 0x%llx\n");
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: Sending msa starting 0x%llx with size 0x%llx\n",uVar11,
                     (ulong)uVar1);
    }
    uVar1 = *(uint *)(param_1 + 0x1644);
    *(undefined1 *)(puVar6 + 0x98) = 1;
    puVar6[0x9a] = 2;
    puVar6[0x9b] = 0;
    if (99 < uVar1) {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Setting WLAN_EN delay: %d ms\n");
      uVar9 = *(undefined4 *)(param_1 + 0x1644);
      *(undefined1 *)(puVar6 + 0xba) = 1;
      *(undefined4 *)(puVar6 + 0xbc) = uVar9;
    }
    local_5c = 0;
    lVar8 = of_find_node_opts_by_path("/memory",0);
    if (((lVar8 != 0) &&
        (iVar5 = of_property_read_variable_u32_array(lVar8,"ddr_device_type",&local_5c,1,0),
        iVar4 = local_5c, -1 < iVar5)) && (0 < local_5c)) {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: DDR Type: %d\n",local_5c);
      *(int *)(puVar6 + 0xc0) = iVar4;
      *(undefined1 *)(puVar6 + 0xbe) = 1;
    }
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(*(long *)(param_1 + 8) + 0x2f8),"wlan-en-gpio",&local_ac,1,0)
    ;
    if (iVar4 < 0) {
      uVar9 = 0xffff;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: WLAN_EN_GPIO modified through DT: %d\n",
                     local_ac);
      *(undefined1 *)(puVar6 + 0xc2) = 1;
      uVar9 = local_ac;
    }
    lVar8 = *(long *)(param_1 + 8);
    *(undefined4 *)(puVar6 + 0xc6) = uVar9;
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(lVar8 + 0x2f8),"bt-en-gpio",&local_ac,1,0);
    if (iVar4 < 0) {
      uVar9 = 0xffff;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: BT_EN_GPIO modified through DT: %d\n",
                     local_ac);
      *(undefined1 *)(puVar6 + 0xc2) = 1;
      uVar9 = local_ac;
    }
    lVar8 = *(long *)(param_1 + 8);
    *(undefined4 *)(puVar6 + 200) = uVar9;
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(lVar8 + 0x2f8),"host-sol-gpio",&local_ac,1,0);
    if (iVar4 < 0) {
      uVar9 = 0xffff;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: HOST_SOL_GPIO modified through DT: %d\n",
                     local_ac);
      *(undefined1 *)(puVar6 + 0xc2) = 1;
      uVar9 = local_ac;
    }
    lVar8 = *(long *)(param_1 + 8);
    *(undefined4 *)(puVar6 + 0xca) = uVar9;
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(lVar8 + 0x2f8),"target-sol-gpio",&local_ac,1,0);
    if (iVar4 < 0) {
      uVar9 = 0xffff;
    }
    else {
      ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: TARGET_SOL_GPIO modified through DT: %d\n",
                     local_ac);
      *(undefined1 *)(puVar6 + 0xc2) = 1;
      uVar9 = local_ac;
    }
    *(undefined4 *)(puVar6 + 0xcc) = uVar9;
    puVar6[0xc4] = 6;
    puVar6[0xc5] = 0;
    iVar4 = qmi_txn_init(param_1 + 0x248,&local_a8,&wlfw_host_cap_resp_msg_v01_ei,puVar7);
    if (iVar4 < 0) {
      pcVar10 = "%sicnss2_qmi: Failed to initialize txn for host capability request, err: %d\n";
LAB_00117614:
      _printk(pcVar10,&DAT_0011c04b,iVar4);
      ipc_log_string(icnss_ipc_log_context,pcVar10,&DAT_0011dab7,iVar4);
    }
    else {
      iVar4 = qmi_send_request(param_1 + 0x248,0,&local_a8,0x34,0x3d6,&wlfw_host_cap_req_msg_v01_ei,
                               puVar6);
      if (iVar4 < 0) {
        qmi_txn_cancel(&local_a8);
        pcVar10 = "%sicnss2_qmi: Failed to send host capability request, err: %d\n";
        goto LAB_00117614;
      }
      iVar4 = qmi_txn_wait(&local_a8,*(undefined4 *)(param_1 + 0x128));
      if (iVar4 < 0) {
        pcVar10 = "%sicnss2_qmi: Failed to wait for response of host capability request, err: %d\n";
        goto LAB_00117614;
      }
      if (*puVar7 == 0) {
        iVar4 = 0;
      }
      else {
        _printk("%sicnss2_qmi: Host capability request failed, result: %d, err: %d\n",&DAT_0011c04b,
                *puVar7,puVar7[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Host capability request failed, result: %d, err: %d\n",
                       &DAT_0011dab7,*puVar7,puVar7[1]);
        iVar4 = -(uint)*puVar7;
      }
    }
    kfree(puVar6);
    puVar6 = puVar7;
  }
  kfree(puVar6);
LAB_001175ac:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// icnss_wlfw_get_info_send_sync @ 00117690 size=576
// signature: undefined icnss_wlfw_get_info_send_sync(void)
// callers: [icnss_qmi_send]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_wlfw_get_info_send_sync(long param_1,undefined1 param_2,void *param_3,uint param_4)

{
  long lVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if ((0x1800 < (int)param_4) || (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0)) {
    iVar2 = -0x16;
    goto LAB_001177c4;
  }
  puVar3 = (ushort *)kmalloc_trace(_icc_set_bw,0x9c0,0x1808);
  if (puVar3 == (ushort *)0x0) {
    iVar2 = -0xc;
    goto LAB_001177c4;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0x9c0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *(undefined1 *)puVar3 = param_2;
    *(uint *)(puVar3 + 2) = param_4;
    if (0x1800 < param_4) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("memcpy");
    }
    memcpy(puVar3 + 4,param_3,(ulong)param_4);
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_get_info_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Failed to initialize txn for get info request, err: %d\n";
LAB_00117844:
      _printk(pcVar5,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x4a,0x1809,&wlfw_get_info_req_msg_v01_ei
                               ,puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar5 = "%sicnss2_qmi: Failed to send get info request, err: %d\n";
        goto LAB_00117844;
      }
      iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar5 = "%sicnss2_qmi: Failed to wait for response of get info request, err: %d\n";
        goto LAB_00117844;
      }
      if (*puVar4 == 0) {
        iVar2 = 0;
      }
      else {
        _printk("%sicnss2_qmi: Get info request failed, result: %d, err: %d\n",&DAT_0011c04b,*puVar4
                ,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: Get info request failed, result: %d, err: %d\n",&DAT_0011dab7,
                       *puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar3);
    puVar3 = puVar4;
  }
  kfree(puVar3);
LAB_001177c4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_subsys_restart_level_msg @ 001178d4 size=600
// signature: undefined wlfw_subsys_restart_level_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_subsys_restart_level_msg(long param_1,undefined1 param_2)

{
  long lVar1;
  int iVar2;
  undefined1 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00117af4;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) {
    iVar2 = -0x16;
    goto LAB_00117af4;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending subsystem restart level: 0x%x\n",param_2
                );
  puVar3 = (undefined1 *)kmalloc_trace(___list_add_valid,0xdc0,2);
  if (puVar3 == (undefined1 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00117af4;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    kfree(puVar3);
    iVar2 = -0xc;
    goto LAB_00117af4;
  }
  iVar2 = *(int *)(param_1 + 0xaf0);
  *puVar3 = 1;
  puVar3[1] = param_2;
  *(int *)(param_1 + 0xaf0) = iVar2 + 1;
  iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_subsys_restart_level_resp_msg_v01_ei,puVar4);
  if (iVar2 < 0) {
    pcVar5 = "%sicnss2_qmi: Fail to init txn for subsystem restart level, resp %d\n";
LAB_00117a68:
    _printk(pcVar5,&DAT_0011c04b,iVar2);
    ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
  }
  else {
    iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x55,4,
                             &wlfw_subsys_restart_level_req_msg_v01_ei,puVar3);
    if (iVar2 < 0) {
      qmi_txn_cancel(&local_90);
      pcVar5 = "%sicnss2_qmi: Fail to send subsystem restart level %d\n";
      goto LAB_00117a68;
    }
    iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Subsystem restart level timed out with ret %d\n";
      goto LAB_00117a68;
    }
    if (*puVar4 == 0) {
      *(int *)(param_1 + 0xaf4) = *(int *)(param_1 + 0xaf4) + 1;
      kfree(puVar4);
      kfree(puVar3);
      iVar2 = 0;
      goto LAB_00117af4;
    }
    _printk("%sicnss2_qmi: Subsystem restart level request rejected,result:%d error:%d\n",
            &DAT_0011c04b,*puVar4,puVar4[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Subsystem restart level request rejected,result:%d error:%d\n",
                   &DAT_0011dab7,*puVar4,puVar4[1]);
    iVar2 = -(uint)*puVar4;
  }
  kfree(puVar3);
  kfree(puVar4);
  *(int *)(param_1 + 0xaf8) = *(int *)(param_1 + 0xaf8) + 1;
LAB_00117af4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_send_vbatt_update @ 00117b30 size=528
// signature: undefined icnss_send_vbatt_update(void)
// callers: [icnss_update_soc_level]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_send_vbatt_update(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  ushort *puVar4;
  char *pcVar5;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00117c64;
  }
  if (((uint)*(undefined8 *)(param_1 + 0x778) >> 0xd & 1) != 0) {
    iVar2 = -0x16;
    goto LAB_00117c64;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending Vbatt message, state: 0x%lx\n");
  puVar3 = (undefined8 *)kmalloc_trace(___list_add_valid,0xdc0,8);
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -0xc;
    goto LAB_00117c64;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *puVar3 = param_2;
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_vbatt_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar5 = "%sicnss2_qmi: Fail to init txn for Vbatt message resp %d\n";
LAB_00117cc8:
      _printk(pcVar5,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar5,&DAT_0011dab7,iVar2);
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x32,0xb,&wlfw_vbatt_req_msg_v01_ei,
                               puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar5 = "%sicnss2_qmi: Fail to send Vbatt message req %d\n";
        goto LAB_00117cc8;
      }
      iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar5 = "%sicnss2_qmi: VBATT message resp wait failed with ret %d\n";
        goto LAB_00117cc8;
      }
      if (*puVar4 == 0) {
        iVar2 = 0;
      }
      else {
        _printk("%sicnss2_qmi: QMI Vbatt message request rejected, result:%d error:%d\n",
                &DAT_0011c04b,*puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: QMI Vbatt message request rejected, result:%d error:%d\n",
                       &DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
      }
    }
    kfree(puVar4);
  }
  kfree(puVar3);
LAB_00117c64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wlfw_wlan_hw_init_cfg_msg @ 00117d44 size=536
// signature: undefined wlfw_wlan_hw_init_cfg_msg(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wlfw_wlan_hw_init_cfg_msg(long param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  char *pcVar6;
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
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  if (param_1 == 0) {
    iVar2 = -0x13;
    goto LAB_00117f24;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending hw init cfg, rf_subtype: 0x%x\n",param_2
                );
  puVar3 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,8);
  if (puVar3 == (ushort *)0x0) {
    iVar2 = -0xc;
    goto LAB_00117f24;
  }
  puVar4 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar4 == (ushort *)0x0) {
    iVar2 = -0xc;
  }
  else {
    *(undefined1 *)puVar3 = 1;
    *(undefined4 *)(puVar3 + 2) = param_2;
    iVar2 = qmi_txn_init(param_1 + 0x248,&local_90,&wlfw_wlan_hw_init_cfg_resp_msg_v01_ei,puVar4);
    if (iVar2 < 0) {
      pcVar6 = "%sicnss2_qmi: Fail to init txn for hw init cfg, resp %d\n";
LAB_00117ea0:
      _printk(pcVar6,&DAT_0011c04b,iVar2);
      ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7,iVar2);
LAB_00117f10:
      puVar5 = puVar3;
      puVar3 = puVar4;
    }
    else {
      iVar2 = qmi_send_request(param_1 + 0x248,0,&local_90,0x58,7,
                               &wlfw_wlan_hw_init_cfg_req_msg_v01_ei,puVar3);
      if (iVar2 < 0) {
        qmi_txn_cancel(&local_90);
        pcVar6 = "%sicnss2_qmi: Fail to send hw init cfg %d\n";
        goto LAB_00117ea0;
      }
      iVar2 = qmi_txn_wait(&local_90,*(undefined4 *)(param_1 + 0x128));
      if (iVar2 < 0) {
        pcVar6 = "%sicnss2_qmi: HW init cfg timed out with ret %d\n";
        goto LAB_00117ea0;
      }
      if (*puVar4 != 0) {
        _printk("%sicnss2_qmi: HW init cfg request rejected,result:%d error:%d\n",&DAT_0011c04b,
                *puVar4,puVar4[1]);
        ipc_log_string(icnss_ipc_log_context,
                       "%sicnss2_qmi: HW init cfg request rejected,result:%d error:%d\n",
                       &DAT_0011dab7,*puVar4,puVar4[1]);
        iVar2 = -(uint)*puVar4;
        goto LAB_00117f10;
      }
      iVar2 = 0;
      puVar5 = puVar4;
    }
    kfree(puVar5);
  }
  kfree(puVar3);
LAB_00117f24:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// icnss_process_wfc_call_ind_event @ 00117f60 size=684
// signature: undefined icnss_process_wfc_call_ind_event(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int icnss_process_wfc_call_ind_event(long param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  long lVar6;
  undefined8 uVar7;
  int iVar8;
  undefined4 *puVar9;
  ushort *puVar10;
  undefined8 uVar11;
  char *pcVar12;
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
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if ((((uint)*(undefined8 *)(param_1 + 0x778) >> 2 & 1) == 0) ||
     (((uint)*(undefined8 *)(param_1 + 0x778) >> 0x10 & 1) == 0)) {
    _printk("%sicnss2_qmi: Drop IMS WFC indication as FW not initialized\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Drop IMS WFC indication as FW not initialized\n",&DAT_0011dab7);
    iVar8 = -0x16;
    goto LAB_00118124;
  }
  puVar9 = (undefined4 *)kmalloc_trace(_wait_for_completion_interruptible,0xdc0,0x128);
  if (puVar9 == (undefined4 *)0x0) {
    iVar8 = -0xc;
    goto LAB_00118124;
  }
  puVar10 = (ushort *)kmalloc_trace(___list_add_valid,0xdc0,4);
  if (puVar10 == (ushort *)0x0) {
    kfree(puVar9);
    iVar8 = -0xc;
    goto LAB_00118124;
  }
  uVar2 = *param_2;
  uVar1 = *(undefined4 *)(param_2 + 2);
  *puVar9 = 1;
  uVar3 = param_2[1];
  *(undefined1 *)(puVar9 + 0x41) = 1;
  uVar11 = *(undefined8 *)(param_2 + 8);
  *(undefined1 *)(puVar9 + 1) = uVar2;
  uVar7 = icnss_ipc_log_context;
  *(undefined1 *)((long)puVar9 + 0x105) = uVar2;
  uVar2 = param_2[0x10];
  *(undefined4 *)((long)puVar9 + 0x107) = uVar1;
  uVar5 = *(undefined2 *)(param_2 + 0x12);
  uVar4 = param_2[0x14];
  *(undefined8 *)(puVar9 + 0x44) = uVar11;
  uVar1 = *(undefined4 *)(param_2 + 0x18);
  uVar11 = *(undefined8 *)(param_1 + 0x778);
  *(undefined1 *)((long)puVar9 + 0x106) = uVar3;
  *(undefined1 *)(puVar9 + 0x46) = uVar2;
  *(undefined2 *)((long)puVar9 + 0x11a) = uVar5;
  *(undefined1 *)(puVar9 + 0x47) = uVar4;
  puVar9[0x48] = uVar1;
  ipc_log_string(uVar7,"icnss2_qmi: CNSS->FW: WFC_CALL_REQ: state: 0x%lx\n",uVar11);
  iVar8 = qmi_txn_init(param_1 + 0x248,&local_a0,&wlfw_wfc_call_status_resp_msg_v01_ei,puVar10);
  if (iVar8 < 0) {
    pcVar12 = "%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Txn Init: Err %d\n";
LAB_00118194:
    _printk(pcVar12,&DAT_0011c04b,iVar8);
    ipc_log_string(icnss_ipc_log_context,pcVar12,&DAT_0011dab7,iVar8);
  }
  else {
    iVar8 = qmi_send_request(param_1 + 0x248,0,&local_a0,0x49,0x128,
                             &wlfw_wfc_call_status_req_msg_v01_ei,puVar9);
    if (iVar8 < 0) {
      qmi_txn_cancel(&local_a0);
      pcVar12 = "%sicnss2_qmi: CNSS->FW: WFC_CALL_REQ: QMI Send Err: %d\n";
      goto LAB_00118194;
    }
    iVar8 = qmi_txn_wait(&local_a0,*(undefined4 *)(param_1 + 0x128));
    if (iVar8 < 0) {
      pcVar12 = "%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: QMI Wait Err: %d\n";
      goto LAB_00118194;
    }
    if (*puVar10 == 0) {
      iVar8 = 0;
    }
    else {
      _printk("%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n",&DAT_0011c04b,*puVar10,
              puVar10[1]);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: FW->CNSS: WFC_CALL_RSP: Result: %d Err: %d\n",&DAT_0011dab7,
                     *puVar10,puVar10[1]);
      iVar8 = -(uint)*puVar10;
    }
  }
  kfree(puVar9);
  kfree(puVar10);
LAB_00118124:
  kfree(param_2);
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar8;
}



//------------------------------------------------------------
// icnss_register_ims_service @ 00118210 size=88
// signature: undefined icnss_register_ims_service(void)
// callers: [icnss_probe]
//------------------------------------------------------------

void icnss_register_ims_service(long param_1)

{
  int iVar1;
  
  iVar1 = qmi_handle_init(param_1 + 0x4d8,0x2000,&ims_qmi_ops,qmi_ims_msg_handlers);
  if (-1 < iVar1) {
    qmi_add_lookup(param_1 + 0x4d8,0x4d,1,0);
  }
  return;
}



//------------------------------------------------------------
// icnss_unregister_ims_service @ 0011826c size=32
// signature: undefined icnss_unregister_ims_service(void)
// callers: [icnss_remove]
//------------------------------------------------------------

void icnss_unregister_ims_service(long param_1)

{
  qmi_handle_release(param_1 + 0x4d8);
  return;
}



//------------------------------------------------------------
// dms_new_server @ 00118290 size=304
// signature: undefined dms_new_server(void)
// callers: []
//------------------------------------------------------------

int dms_new_server(undefined8 *param_1,long param_2)

{
  ulong *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  int iVar7;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (param_2 == 0) {
    iVar7 = -0x16;
  }
  else {
    uVar2 = *(undefined4 *)(param_2 + 0xc);
    uVar3 = *(undefined4 *)(param_2 + 0x10);
    local_48 = 0x2a;
    uStack_44 = uVar2;
    local_40 = uVar3;
    iVar7 = kernel_connect(*param_1,&local_48,0xc,0);
    if (iVar7 < 0) {
      _printk("%sicnss2_qmi: Failed to connect to QMI DMS remote service Node: %d Port: %d\n",
              &DAT_0011c04b,uVar2,uVar3);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: Failed to connect to QMI DMS remote service Node: %d Port: %d\n"
                     ,&DAT_0011dab7,uVar2,uVar3);
    }
    else {
      puVar1 = param_1 + 0x7d;
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = *puVar1 | 0x400000;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      _printk("%sicnss2_qmi: QMI DMS service connected, state: 0x%lx\n",&DAT_0011e9ea,param_1[0x7d])
      ;
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: QMI DMS service connected, state: 0x%lx\n"
                     ,&DAT_0011dab7,param_1[0x7d]);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// dms_del_server @ 001183d0 size=128
// signature: undefined dms_del_server(void)
// callers: []
//------------------------------------------------------------

void dms_del_server(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  puVar1 = (ulong *)(param_1 + 1000);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 & 0xffffffffffbfffff;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  _printk("%sicnss2_qmi: QMI DMS service disconnected, state: 0x%lx\n",&DAT_0011e9ea,
          *(undefined8 *)(param_1 + 1000));
  ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: QMI DMS service disconnected, state: 0x%lx\n",
                 &DAT_0011dab7,*(undefined8 *)(param_1 + 1000));
  return;
}



//------------------------------------------------------------
// selectFileNameByProduct @ 0011845c size=1140
// signature: undefined selectFileNameByProduct(void)
// callers: [icnss_wlfw_bdf_dnld_send_sync]
//------------------------------------------------------------

void selectFileNameByProduct(char *param_1)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  ulong uVar5;
  char *pcVar6;
  ulong uVar7;
  long lVar8;
  char *local_78;
  char *local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_78 = (char *)0x0;
  local_70 = (char *)0x0;
  iVar2 = cnss_get_bootarg_dt("androidboot.hardware.sku=",&local_70);
  pcVar6 = local_70;
  if ((iVar2 == 0) && (local_70 != (char *)0x0)) {
    sVar3 = strlen(local_70);
    if (0x1e < sVar3) {
      sVar3 = 0x1f;
    }
    memcpy(sku_ptr,pcVar6,sVar3);
    sku_ptr[sVar3] = 0;
    sVar3 = strnlen(sku_ptr,0x20);
    if (0x20 < sVar3) {
LAB_001188bc:
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (sVar3 == 0x20) {
LAB_0011853c:
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    iVar2 = strncmp("XT2605-6",sku_ptr,sVar3);
    if (iVar2 == 0) {
      radio_ptr = 0x504a;
      DAT_001242d2 = 0;
    }
    else {
      sVar3 = strnlen((char *)&radio_ptr,0x20);
      if (0x20 < sVar3) goto LAB_001188bc;
      if (sVar3 == 0) {
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: sku&radio not listed!");
        goto LAB_00118590;
      }
      if (sVar3 == 0x20) goto LAB_0011853c;
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: get radio by sku:%s",&radio_ptr);
LAB_001185dc:
    local_70 = (char *)0x0;
    iVar2 = cnss_get_bootarg_dt("androidboot.device=",&local_70);
    pcVar6 = local_70;
    if ((iVar2 == 0) && (local_70 != (char *)0x0)) {
      sVar3 = strlen(local_70);
      if (0x1e < sVar3) {
        sVar3 = 0x1f;
      }
      memcpy(&device_ptr,pcVar6,sVar3);
      (&device_ptr)[sVar3] = 0;
      goto LAB_0011862c;
    }
    pcVar6 = "%sicnss2_qmi: device string is error";
  }
  else {
    _printk("%sicnss2_qmi: get hardware.sku string failed",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: get hardware.sku string failed",
                   &DAT_0011dab7);
LAB_00118590:
    iVar2 = cnss_get_bootarg_dt("androidboot.radio=",&local_78);
    pcVar6 = local_78;
    if ((iVar2 == 0) && (local_78 != (char *)0x0)) {
      sVar3 = strlen(local_78);
      if (0x1e < sVar3) {
        sVar3 = 0x1f;
      }
      memcpy(&radio_ptr,pcVar6,sVar3);
      *(undefined1 *)((long)&radio_ptr + sVar3) = 0;
      goto LAB_001185dc;
    }
    pcVar6 = "%sicnss2_qmi: radio string is error";
  }
  _printk(pcVar6,&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,pcVar6,&DAT_0011dab7);
  _printk("%sicnss2_qmi: device or radio not present ",&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: device or radio not present ",&DAT_0011dab7);
LAB_0011862c:
  uVar5 = 0;
  do {
    uVar7 = -(uVar5 >> 0x1f) & 0xffffff8000000000 | uVar5 << 7;
    iVar2 = (int)uVar5;
    if (&products_list + uVar7 != (char *)0x0) {
      if (((iVar2 == 4) || (0x200 < uVar7)) || (0x200 < uVar7)) goto LAB_001188b8;
      sVar3 = strnlen(&products_list + uVar7,0x20);
      if (0x20 < sVar3) goto LAB_001188bc;
      if (sVar3 == 0) {
        if ((0x200 < (uVar7 | 0x20)) || (0x200 < ((long)iVar2 << 7 | 0x20U))) goto LAB_001188b8;
        sVar3 = strnlen(&DAT_00124c20 + (long)iVar2 * 0x80,0x20);
        if (0x20 < sVar3) goto LAB_001188bc;
        if (sVar3 == 0) {
          if (iVar2 < 1) goto LAB_001187d8;
          lVar8 = 0;
          uVar7 = 0;
          break;
        }
      }
      if (sVar3 == 0x20) goto LAB_0011853c;
    }
    uVar5 = (ulong)(iVar2 + 1);
  } while( true );
LAB_001186fc:
  if (lVar8 == 0x280) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1188cc);
    (*pcVar1)();
  }
  if ((uVar7 & 0x1fffffffffffffc) != 0) goto LAB_001188b8;
  sVar3 = strnlen(&products_list + lVar8,0x20);
  if (0x20 < sVar3) goto LAB_001188bc;
  if (sVar3 == 0x20) goto LAB_0011853c;
  iVar2 = strncmp(&device_ptr,&products_list + lVar8,sVar3);
  if (iVar2 == 0) {
    if (0x200 < lVar8 + 0x20U) {
LAB_001188b8:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x1188bc);
      (*pcVar1)();
    }
    pcVar6 = &DAT_00124c20 + lVar8;
    sVar3 = strnlen(pcVar6,0x20);
    if (0x20 < sVar3) goto LAB_001188bc;
    if (sVar3 == 0x20) goto LAB_0011853c;
    iVar2 = strncmp((char *)&radio_ptr,pcVar6,sVar3);
    if (iVar2 != 0) {
      sVar3 = strnlen(pcVar6,0x20);
      if (0x20 < sVar3) goto LAB_001188bc;
      if (sVar3 == 0x20) goto LAB_0011853c;
      iVar2 = strncmp(pcVar6,"all",sVar3);
      if (iVar2 != 0) goto LAB_001186ec;
    }
    sprintf(param_1,"%s.%s.%s","bdwlan.elf",&products_list + lVar8,&DAT_00124c40 + lVar8);
    uVar4 = 1;
    goto LAB_001187dc;
  }
LAB_001186ec:
  uVar7 = uVar7 + 1;
  lVar8 = lVar8 + 0x80;
  if (uVar5 * 0x80 == lVar8) {
LAB_001187d8:
    uVar4 = 0;
LAB_001187dc:
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail(uVar4);
    }
    return;
  }
  goto LAB_001186fc;
}



//------------------------------------------------------------
// cnss_get_bootarg_dt @ 001188d0 size=332
// signature: undefined cnss_get_bootarg_dt(void)
// callers: [selectFileNameByProduct]
//------------------------------------------------------------

void cnss_get_bootarg_dt(undefined8 param_1,undefined8 *param_2)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  size_t sVar4;
  char *pcVar5;
  char *local_60;
  char *local_58;
  char *local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_50 = (char *)0x0;
  lVar3 = of_find_node_opts_by_path("/chosen",0);
  if ((lVar3 != 0) &&
     (iVar2 = of_property_read_string(lVar3,"mmi,bootconfig",&local_50), pcVar5 = local_50,
     iVar2 == 0)) {
    sVar4 = strlen(local_50);
    if (bootargs_str == (char *)0x0) {
      bootargs_str = (char *)__kmalloc(sVar4 + 1,0xdc0);
      if (bootargs_str == (char *)0x0) goto LAB_0011892c;
      pcVar5 = local_50;
    }
    strlcpy(bootargs_str,pcVar5,sVar4 + 1);
    pcVar5 = bootargs_str;
    sVar4 = strlen(bootargs_str);
    local_58 = (char *)strnstr(pcVar5,param_1,sVar4);
    if (local_58 != (char *)0x0) {
      local_60 = strsep(&local_58," ");
      if ((local_60 != (char *)0x0) && (pcVar5 = strsep(&local_60,"="), pcVar5 != (char *)0x0)) {
        pcVar5 = strsep(&local_60,"\n");
        bVar1 = pcVar5 == (char *)0x0;
        *param_2 = pcVar5;
        goto LAB_00118930;
      }
    }
  }
LAB_0011892c:
  bVar1 = true;
LAB_00118930:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar1);
  }
  return;
}



//------------------------------------------------------------
// wlfw_new_server @ 00118a20 size=208
// signature: undefined wlfw_new_server(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 wlfw_new_server(long param_1,long param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 + -0x248 == 0) || (((uint)*(undefined8 *)(param_1 + 0x530) >> 0x14 & 1) == 0)) {
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: WLFW server arrive: node %u port %u\n",
                   *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10));
    puVar2 = (undefined4 *)kmalloc_trace(___list_add_valid,0xdc0,8);
    if (puVar2 == (undefined4 *)0x0) {
      return 0xfffffff4;
    }
    uVar1 = *(undefined4 *)(param_2 + 0x10);
    *puVar2 = *(undefined4 *)(param_2 + 0xc);
    puVar2[1] = uVar1;
    icnss_driver_event_post(param_1 + -0x248,0,0,puVar2);
  }
  else {
    _printk("%sicnss2_qmi: WLFW server delete in progress, Ignore server arrive: 0x%lx\n",
            &DAT_0011e9ea);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: WLFW server delete in progress, Ignore server arrive: 0x%lx\n",
                   &DAT_0011dab7,*(undefined8 *)(param_1 + 0x530));
  }
  return 0;
}



//------------------------------------------------------------
// wlfw_del_server @ 00118af4 size=232
// signature: undefined wlfw_del_server(void)
// callers: []
//------------------------------------------------------------

void wlfw_del_server(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  if (param_1 + -0x248 == 0) {
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: WLFW server delete\n");
  }
  else {
    if (((uint)*(undefined8 *)(param_1 + 0x530) >> 0x14 & 1) != 0) {
      _printk("%sicnss2_qmi: WLFW server delete / icnss remove in progress, Ignore server delete:  0x%lx\n"
              ,&DAT_0011e9ea);
      ipc_log_string(icnss_ipc_log_context,
                     "%sicnss2_qmi: WLFW server delete / icnss remove in progress, Ignore server delete:  0x%lx\n"
                     ,&DAT_0011dab7,*(undefined8 *)(param_1 + 0x530));
      return;
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: WLFW server delete\n");
    puVar1 = (ulong *)(param_1 + 0x530);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x100000;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    puVar1 = (ulong *)(param_1 + 0x530);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | 0x2000;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  icnss_driver_event_post(param_1 + -0x248,1,0,0);
  return;
}



//------------------------------------------------------------
// fw_ready_ind_cb @ 00118bfc size=100
// signature: undefined fw_ready_ind_cb(void)
// callers: []
//------------------------------------------------------------

void fw_ready_ind_cb(long param_1,undefined8 param_2,long param_3)

{
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received FW Ready Indication\n");
  if (param_3 == 0) {
    _printk(&DAT_001234ae);
  }
  else {
    icnss_driver_event_post(param_1 + -0x248,2,0,0);
  }
  return;
}



//------------------------------------------------------------
// msa_ready_ind_cb @ 00118c64 size=400
// signature: undefined msa_ready_ind_cb(void)
// callers: []
//------------------------------------------------------------

void msa_ready_ind_cb(long param_1,undefined8 param_2,long param_3,char *param_4)

{
  ulong uVar1;
  ushort uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x508);
  lVar3 = *(long *)(param_1 + -0x240);
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received MSA Ready Indication\n");
  if (param_3 == 0) {
    _printk(&DAT_001234ae);
    return;
  }
  *(int *)(param_1 + 0x830) = *(int *)(param_1 + 0x830) + 1;
  if (((param_4[8] != '\0') && (*(ushort *)(param_4 + 10) - 1 < 400)) &&
     (*(ushort *)(param_1 + 0x1320) = *(ushort *)(param_4 + 10), *param_4 != '\0')) {
    uVar2 = *(ushort *)(param_4 + 10);
    uVar1 = (ulong)*(uint *)(param_4 + 4);
    if (*(uint *)(param_4 + 4) <= *(int *)(param_1 + 0x520) - (uint)uVar2) {
      lVar4 = lVar4 + uVar1;
      if (*(long *)(param_1 + 0x1310) == lVar4) {
        lVar4 = *(long *)(param_1 + 0x1318);
LAB_00118d30:
        ipc_log_string(icnss_ipc_log_context,
                       "icnss2_qmi: Hang Event Data details,Offset:0x%x, Length:0x%x,va_addr: 0x%pK\n"
                       ,uVar1,uVar2,lVar4);
        return;
      }
      *(long *)(param_1 + 0x1310) = lVar4;
      lVar4 = devm_ioremap(lVar3 + 0x10,lVar4,*(undefined2 *)(param_4 + 10));
      *(long *)(param_1 + 0x1318) = lVar4;
      if (lVar4 != 0) {
        uVar1 = (ulong)*(uint *)(param_4 + 4);
        uVar2 = *(ushort *)(param_4 + 10);
        goto LAB_00118d30;
      }
      _printk("%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n",&DAT_0011c04b,
              param_1 + 0x1310);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n"
                     ,&DAT_0011dab7,param_1 + 0x1310);
      goto LAB_00118d80;
    }
  }
  _printk("%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",&DAT_0011c04b,
          *(undefined4 *)(param_4 + 4),*(undefined2 *)(param_4 + 10));
  ipc_log_string(icnss_ipc_log_context,
                 "%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",&DAT_0011dab7,
                 *(undefined4 *)(param_4 + 4),*(undefined2 *)(param_4 + 10));
LAB_00118d80:
  *(undefined2 *)(param_1 + 0x1320) = 0;
  *(undefined8 *)(param_1 + 0x1318) = 0;
  *(undefined8 *)(param_1 + 0x1310) = 0;
  return;
}



//------------------------------------------------------------
// pin_connect_result_ind_cb @ 00118df8 size=180
// signature: undefined pin_connect_result_ind_cb(void)
// callers: []
//------------------------------------------------------------

void pin_connect_result_ind_cb(long param_1,undefined8 param_2,long param_3,char *param_4)

{
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received Pin Connect Result Indication\n");
  if (param_3 == 0) {
    _printk(&DAT_001234ae);
  }
  else {
    if (*param_4 != '\0') {
      *(undefined4 *)(param_1 + 0x5f4) = *(undefined4 *)(param_4 + 4);
    }
    if (param_4[8] != '\0') {
      *(undefined4 *)(param_1 + 0x5f8) = *(undefined4 *)(param_4 + 0xc);
    }
    if (param_4[0x10] != '\0') {
      *(undefined4 *)(param_1 + 0x5fc) = *(undefined4 *)(param_4 + 0x14);
    }
    ipc_log_string(icnss_ipc_log_context,
                   "icnss2_qmi: Pin connect Result: pwr_pin: 0x%x phy_io_pin: 0x%x rf_io_pin: 0x%x\n"
                   ,*(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 0xc),
                   *(undefined4 *)(param_4 + 0x14));
    *(int *)(param_1 + 0x840) = *(int *)(param_1 + 0x840) + 1;
  }
  return;
}



//------------------------------------------------------------
// rejuvenate_ind_cb @ 00118eb0 size=496
// signature: undefined rejuvenate_ind_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rejuvenate_ind_cb(long param_1,undefined8 param_2,long param_3,char *param_4)

{
  ulong *puVar1;
  bool bVar2;
  long lVar3;
  undefined2 *puVar4;
  char cVar5;
  char cVar6;
  undefined2 uVar7;
  undefined1 local_60 [8];
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received Rejuvenate Indication\n");
  if (param_3 == 0) {
    _printk(&DAT_001234ae);
  }
  else {
    if (*param_4 == '\0') {
      cVar5 = '\0';
    }
    else {
      cVar5 = param_4[1];
    }
    *(char *)(param_1 + 0x993) = cVar5;
    if (param_4[2] == '\0') {
      cVar6 = '\0';
    }
    else {
      cVar6 = param_4[3];
    }
    *(char *)(param_1 + 0x994) = cVar6;
    if (param_4[4] == '\0') {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined2 *)(param_4 + 6);
    }
    *(undefined2 *)(param_1 + 0x996) = uVar7;
    if (param_4[8] == '\0') {
      *(undefined1 *)(param_1 + 0xaa0) = 0;
      *(undefined8 *)(param_1 + 0xa90) = 0;
      *(undefined8 *)(param_1 + 0xa98) = 0;
      *(undefined8 *)(param_1 + 0xa80) = 0;
      *(undefined8 *)(param_1 + 0xa88) = 0;
      *(undefined8 *)(param_1 + 0xa70) = 0;
      *(undefined8 *)(param_1 + 0xa78) = 0;
      *(undefined8 *)(param_1 + 0xa60) = 0;
      *(undefined8 *)(param_1 + 0xa68) = 0;
      *(undefined8 *)(param_1 + 0xa50) = 0;
      *(undefined8 *)(param_1 + 0xa58) = 0;
      *(undefined8 *)(param_1 + 0xa40) = 0;
      *(undefined8 *)(param_1 + 0xa48) = 0;
      *(undefined8 *)(param_1 + 0xa30) = 0;
      *(undefined8 *)(param_1 + 0xa38) = 0;
      *(undefined8 *)(param_1 + 0xa20) = 0;
      *(undefined8 *)(param_1 + 0xa28) = 0;
    }
    else {
      memcpy((undefined8 *)(param_1 + 0xa20),param_4 + 9,0x81);
    }
    _printk("%sicnss2_qmi: Cause for rejuvenation: 0x%x, requesting sub-system: 0x%x, line number: %u, function name: %s\n"
            ,&DAT_0011e9ea,cVar5,cVar6,uVar7,param_1 + 0xa20);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Cause for rejuvenation: 0x%x, requesting sub-system: 0x%x, line number: %u, function name: %s\n"
                   ,&DAT_0011dab7,*(undefined1 *)(param_1 + 0x993),*(undefined1 *)(param_1 + 0x994),
                   *(undefined2 *)(param_1 + 0x996),param_1 + 0xa20);
    *(int *)(param_1 + 0x868) = *(int *)(param_1 + 0x868) + 1;
    puVar4 = (undefined2 *)kmalloc_trace(___list_add_valid,0xdc0,2);
    if (puVar4 != (undefined2 *)0x0) {
      *puVar4 = 0x101;
      local_60[0] = 1;
      puVar1 = (ulong *)(param_1 + 0x530);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar5 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar2) {
          *puVar1 = *puVar1 | 0x8000;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      icnss_call_driver_uevent(param_1 + -0x248,1,local_60);
      icnss_driver_event_post(param_1 + -0x248,5,0,puVar4);
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
// cal_done_ind_cb @ 001190b0 size=168
// signature: undefined cal_done_ind_cb(void)
// callers: []
//------------------------------------------------------------

void cal_done_ind_cb(long param_1,undefined8 param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received QMI WLFW calibration done indication\n"
                );
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
  }
  else {
    *(undefined1 *)(param_1 + -0x118) = 1;
    puVar1 = (ulong *)(param_1 + 0x530);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xffffffffffdfffff;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return;
}



//------------------------------------------------------------
// fw_init_done_ind_cb @ 00119168 size=444
// signature: undefined fw_init_done_ind_cb(void)
// callers: []
//------------------------------------------------------------

void fw_init_done_ind_cb(long param_1,undefined8 param_2,long param_3,char *param_4)

{
  ulong uVar1;
  ushort uVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x508);
  lVar3 = *(long *)(param_1 + -0x240);
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Received QMI WLFW FW initialization done indication\n");
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
    return;
  }
  if (((param_4[8] == '\0') || (399 < *(ushort *)(param_4 + 10) - 1)) ||
     (*(ushort *)(param_1 + 0x1320) = *(ushort *)(param_4 + 10), *param_4 == '\0')) {
LAB_00119240:
    _printk("%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",&DAT_0011c04b,
            *(undefined4 *)(param_4 + 4),*(undefined2 *)(param_4 + 10));
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: Invalid Hang Data details, Offset:0x%x, Length:0x%x",&DAT_0011dab7
                   ,*(undefined4 *)(param_4 + 4),*(undefined2 *)(param_4 + 10));
  }
  else {
    uVar2 = *(ushort *)(param_4 + 10);
    uVar1 = (ulong)*(uint *)(param_4 + 4);
    if (*(int *)(param_1 + 0x520) - (uint)uVar2 < *(uint *)(param_4 + 4)) goto LAB_00119240;
    lVar4 = lVar4 + uVar1;
    if (*(long *)(param_1 + 0x1310) == lVar4) {
      lVar4 = *(long *)(param_1 + 0x1318);
LAB_0011922c:
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: Hang Event Data details,Offset:0x%x, Length:0x%x,va_addr: 0x%pK\n"
                     ,uVar1,uVar2,lVar4);
      goto LAB_00119288;
    }
    *(long *)(param_1 + 0x1310) = lVar4;
    lVar4 = devm_ioremap(lVar3 + 0x10,lVar4,*(undefined2 *)(param_4 + 10));
    *(long *)(param_1 + 0x1318) = lVar4;
    if (lVar4 != 0) {
      uVar1 = (ulong)*(uint *)(param_4 + 4);
      uVar2 = *(ushort *)(param_4 + 10);
      goto LAB_0011922c;
    }
    _printk("%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n",&DAT_0011c04b,param_1 + 0x1310
           );
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Hang Data ioremap failed: phy addr: %pa\n",
                   &DAT_0011dab7,param_1 + 0x1310);
  }
  *(undefined2 *)(param_1 + 0x1320) = 0;
  *(undefined8 *)(param_1 + 0x1318) = 0;
  *(undefined8 *)(param_1 + 0x1310) = 0;
LAB_00119288:
  icnss_driver_event_post(param_1 + -0x248,9,0,0);
  return;
}



//------------------------------------------------------------
// wlfw_qdss_trace_req_mem_ind_cb @ 00119328 size=368
// signature: undefined wlfw_qdss_trace_req_mem_ind_cb(void)
// callers: []
//------------------------------------------------------------

void wlfw_qdss_trace_req_mem_ind_cb(long param_1,undefined8 param_2,long param_3,uint *param_4)

{
  uint *puVar1;
  uint uVar2;
  code *pcVar3;
  char *pcVar4;
  ulong uVar5;
  ulong *puVar6;
  
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Received QMI WLFW QDSS trace request mem indication\n");
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
  }
  else {
    if (*(long *)(param_1 + -0x140) == 0x6450) {
      icnss_free_qdss_mem(param_1 + -0x248);
    }
    if (*(int *)(param_1 + 0xac0) == 0) {
      uVar2 = *param_4;
      *(uint *)(param_1 + 0xac0) = uVar2;
      if (uVar2 < 0x35) {
        if (uVar2 != 0) {
          uVar5 = 0;
          param_4 = param_4 + 3;
          puVar6 = (ulong *)(param_1 + 0xac8);
          do {
            ipc_log_string(icnss_ipc_log_context,
                           "icnss2_qmi: QDSS requests for memory, size: 0x%x, type: %u\n",
                           param_4[-1],*param_4);
            if (uVar5 == 0x34) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x119498);
              (*pcVar3)();
            }
            uVar5 = uVar5 + 1;
            *(uint *)((long)puVar6 + 0x1c) = *param_4;
            puVar1 = param_4 + -1;
            param_4 = param_4 + 0xc;
            *puVar6 = (ulong)*puVar1;
            puVar6 = puVar6 + 5;
          } while (uVar5 < *(uint *)(param_1 + 0xac0));
        }
        icnss_driver_event_post(param_1 + -0x248,10,0,0);
        return;
      }
      pcVar4 = "%sicnss2_qmi: Invalid seg len %u\n";
    }
    else {
      pcVar4 = "%sicnss2_qmi: Ignore double allocation for QDSS trace, current len %u\n";
    }
    _printk(pcVar4,&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,pcVar4,&DAT_0011dab7,*(undefined4 *)(param_1 + 0xac0));
  }
  return;
}



//------------------------------------------------------------
// wlfw_qdss_trace_save_ind_cb @ 0011949c size=644
// signature: undefined wlfw_qdss_trace_save_ind_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void wlfw_qdss_trace_save_ind_cb(long param_1,undefined8 param_2,long param_3,int *param_4)

{
  char *__s;
  int iVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  size_t __n;
  undefined8 uVar6;
  ulong uVar7;
  int *piVar8;
  int *piVar9;
  
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received QMI WLFW QDSS trace save indication\n")
  ;
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
    return;
  }
  __s = (char *)((long)param_4 + 0x4f1);
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: QDSS_trace_save info: source %u, total_size %u, file_name_valid %u, file_name %s\n"
                 ,*param_4,param_4[1],(char)param_4[0x13c],__s);
  piVar5 = (int *)kmalloc_trace(_wait_for_completion,0xdc0,0x228);
  if (piVar5 == (int *)0x0) {
    return;
  }
  iVar1 = param_4[7];
  uVar2 = param_4[3];
  iVar3 = param_4[2];
  *piVar5 = param_4[1];
  piVar5[1] = uVar2;
  piVar5[2] = iVar1;
  if ((char)iVar3 != '\0') {
    if (0x20 < uVar2) {
      _printk("%sicnss2_qmi: Invalid seg len %u\n",&DAT_0011c04b);
      ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Invalid seg len %u\n",&DAT_0011dab7,
                     param_4[3]);
LAB_00119710:
      kfree(piVar5);
      return;
    }
    ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: QDSS_trace_save seg len %u\n");
    if (param_4[3] != 0) {
      uVar7 = 0;
      piVar8 = param_4 + 7;
      piVar9 = piVar5 + 6;
      do {
        if (uVar7 == 0x20) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x119720);
          (*pcVar4)();
        }
        iVar1 = piVar8[-1];
        iVar3 = *piVar8;
        *(undefined8 *)(piVar9 + -2) = *(undefined8 *)(piVar8 + -3);
        *piVar9 = iVar1;
        if (piVar5[2] != iVar3) {
          _printk("%sicnss2_qmi: FW Mem file save ind cannot have multiple mem types\n",
                  &DAT_0011c04b);
          ipc_log_string(icnss_ipc_log_context,
                         "%sicnss2_qmi: FW Mem file save ind cannot have multiple mem types\n",
                         &DAT_0011dab7);
          goto LAB_00119710;
        }
        ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: seg-%d: addr 0x%llx size 0x%x\n",
                       uVar7 & 0xffffffff);
        uVar7 = uVar7 + 1;
        piVar8 = piVar8 + 6;
        piVar9 = piVar9 + 4;
      } while (uVar7 < (uint)param_4[3]);
    }
  }
  if ((char)param_4[0x13c] == '\0') {
    if (*param_4 == 1) {
      *(undefined1 *)(piVar5 + 0x88) = 0;
      uVar6 = s_qdss_trace_wcss_etb_00123c9f._8_8_;
      *(undefined8 *)(piVar5 + 0x84) = s_qdss_trace_wcss_etb_00123c9f._0_8_;
      *(undefined8 *)(piVar5 + 0x86) = uVar6;
      goto LAB_00119624;
    }
    *(undefined1 *)((long)piVar5 + 0x21e) = 0;
    uVar6 = CONCAT62(s_qdss_trace_ddr_001227fc._8_6_,s_qdss_trace_ddr_001227fc._6_2_);
    *(ulong *)(piVar5 + 0x84) =
         CONCAT26(s_qdss_trace_ddr_001227fc._6_2_,s_qdss_trace_ddr_001227fc._0_6_);
    *(undefined8 *)((long)piVar5 + 0x216) = uVar6;
  }
  else {
    __n = strlen(__s);
    if (0xf < __n) {
      __n = 0x10;
    }
    memcpy(piVar5 + 0x84,__s,__n);
    iVar1 = *param_4;
    *(undefined1 *)((long)(piVar5 + 0x84) + __n) = 0;
    if (iVar1 == 1) {
LAB_00119624:
      uVar6 = 0x10;
      goto LAB_00119654;
    }
  }
  uVar6 = 0xb;
LAB_00119654:
  icnss_driver_event_post(param_1 + -0x248,uVar6,0,piVar5);
  return;
}



//------------------------------------------------------------
// wlfw_qdss_trace_free_ind_cb @ 00119724 size=44
// signature: undefined wlfw_qdss_trace_free_ind_cb(void)
// callers: []
//------------------------------------------------------------

void wlfw_qdss_trace_free_ind_cb(long param_1)

{
  icnss_driver_event_post(param_1 + -0x248,0xc,0,0);
  return;
}



//------------------------------------------------------------
// icnss_wlfw_respond_get_info_ind_cb @ 00119754 size=192
// signature: undefined icnss_wlfw_respond_get_info_ind_cb(void)
// callers: []
//------------------------------------------------------------

void icnss_wlfw_respond_get_info_ind_cb
               (long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  code *pcVar1;
  
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,
                   "icnss2_qmi: Extract message with event length: %d, type: %d, is last: %d, seq no: %d\n"
                   ,*param_4,*(undefined1 *)((long)param_4 + 0x1805),
                   *(undefined1 *)((long)param_4 + 0x1807),param_4[0x603]);
    if ((*(long *)(param_1 + 0x12e8) != 0) &&
       (pcVar1 = *(code **)(param_1 + 0x12f0), pcVar1 != (code *)0x0)) {
      if (*(int *)(pcVar1 + -4) != 0x405ad735) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1197cc);
        (*pcVar1)();
      }
      (*pcVar1)(*(long *)(param_1 + 0x12e8),param_4 + 1,*param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_wlfw_m3_dump_upload_segs_req_ind_cb @ 00119818 size=552
// signature: undefined icnss_wlfw_m3_dump_upload_segs_req_ind_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void icnss_wlfw_m3_dump_upload_segs_req_ind_cb
               (long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  ulong uVar1;
  int iVar2;
  code *pcVar3;
  bool bVar4;
  undefined4 *puVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  undefined4 *puVar10;
  
  ipc_log_string(icnss_ipc_log_context,
                 "icnss2_qmi: Received QMI WLFW M3 dump upload sigments indication\n");
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
  }
  else {
    ipc_log_string(icnss_ipc_log_context,
                   "icnss2_qmi: M3 Dump upload info: pdev_id: %d no_of_segments: %d\n",*param_4,
                   param_4[1]);
    if (((uint)param_4[1] < 0xb) &&
       (puVar5 = (undefined4 *)kmalloc_trace(_wait_for_completion_interruptible,0xdc0,0x1e8),
       puVar5 != (undefined4 *)0x0)) {
      iVar2 = param_4[1];
      *puVar5 = *param_4;
      puVar5[1] = iVar2;
      if (iVar2 != 0) {
        uVar1 = *(long *)(param_1 + 0x508) + (ulong)*(uint *)(param_1 + 0x520);
        uVar8 = 1;
        do {
          iVar2 = uVar8 - 1;
          lVar7 = (long)iVar2;
          uVar6 = *(ulong *)(param_4 + (long)iVar2 * 0xc + 6);
          uVar9 = (ulong)(uint)param_4[(long)iVar2 * 0xc + 4];
          puVar10 = param_4 + (long)iVar2 * 0xc + 2;
          if ((*(uint *)(param_1 + 0x520) < uVar6 || uVar1 <= uVar9) ||
             (uVar9 < *(ulong *)(param_1 + 0x508) || uVar1 < uVar6 + uVar9)) {
            ipc_log_string(icnss_ipc_log_context,
                           "icnss2_qmi: Received out of range Segment %d Addr: 0x%llx Size: 0x%llx, Name: %s, type: %d\n"
                           ,uVar8,uVar9,uVar6,param_4 + (long)iVar2 * 0xc + 8,*puVar10);
            kfree(puVar5);
            return;
          }
          if (((lVar7 * 0x30 - 0x1d9U < 0xfffffffffffffe17) ||
              (*(ulong *)(puVar5 + lVar7 * 0xc + 4) = uVar9,
              lVar7 * 0x30 - 0x1d1U < 0xfffffffffffffe17)) ||
             (*(ulong *)(puVar5 + (long)iVar2 * 0xc + 6) = uVar6, 0x1e7 < (lVar7 * 0x30 | 8U))) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x119a40);
            (*pcVar3)();
          }
          puVar5[lVar7 * 0xc + 2] = *puVar10;
          strlcpy(puVar5 + lVar7 * 0xc + 8,param_4 + lVar7 * 0xc + 8,0x11);
          ipc_log_string(icnss_ipc_log_context,
                         "icnss2_qmi: Received Segment %d Addr: 0x%llx Size: 0x%llx, Name: %s, type: %d\n"
                         ,uVar8,uVar9,*(ulong *)(param_4 + (long)iVar2 * 0xc + 6),
                         param_4 + lVar7 * 0xc + 8,*puVar10);
          bVar4 = uVar8 < (uint)param_4[1];
          uVar8 = uVar8 + 1;
        } while (bVar4);
      }
      icnss_driver_event_post(param_1 + -0x248,0xd,0,puVar5);
    }
  }
  return;
}



//------------------------------------------------------------
// icnss_wlfw_process_twt_cfg_ind @ 00119a44 size=252
// signature: undefined icnss_wlfw_process_twt_cfg_ind(void)
// callers: []
//------------------------------------------------------------

void icnss_wlfw_process_twt_cfg_ind
               (long param_1,undefined8 param_2,long param_3,undefined1 *param_4)

{
  long lVar1;
  char *pcVar2;
  
  if (param_3 == 0) {
    pcVar2 = "%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Spurious indication\n";
  }
  else {
    if (param_4 != (undefined1 *)0x0) {
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: FW->CNSS: TWT_CFG_IND: %x %llx, %x %x, %x %x, %x %x, %x %x, %x %x\n"
                     ,*param_4,*(undefined8 *)(param_4 + 8),param_4[0x10],
                     *(undefined2 *)(param_4 + 0x12),param_4[0x14],*(undefined2 *)(param_4 + 0x16),
                     param_4[0x18],*(undefined2 *)(param_4 + 0x1a),param_4[0x1c],
                     *(undefined2 *)(param_4 + 0x1e),param_4[0x20],param_4[0x21]);
      lVar1 = kmemdup(param_4,0x28,0xcc0);
      if (lVar1 == 0) {
        return;
      }
      icnss_driver_event_post(param_1 + -0x248,0xf,0,lVar1);
      return;
    }
    pcVar2 = "%sicnss2_qmi: FW->CNSS: TWT_CFG_IND: Invalid indication\n";
  }
  _printk(pcVar2,&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,pcVar2,&DAT_0011dab7);
  return;
}



//------------------------------------------------------------
// icnss_wlfw_driver_async_data_ind_cb @ 00119b44 size=208
// signature: undefined icnss_wlfw_driver_async_data_ind_cb(void)
// callers: []
//------------------------------------------------------------

void icnss_wlfw_driver_async_data_ind_cb
               (long param_1,undefined8 param_2,long param_3,undefined4 *param_4)

{
  code *pcVar1;
  
  ipc_log_string(icnss_ipc_log_long_context,
                 "icnss2_qmi: Received QMI WLFW driver async data indication\n");
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: Spurious indication\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Spurious indication\n",&DAT_0011dab7);
  }
  else {
    ipc_log_string(icnss_ipc_log_long_context,
                   "icnss2_qmi: Extract message with event length: %d, type: %d\n",*param_4,
                   *(undefined2 *)(param_4 + 0x601));
    if ((*(long *)(param_1 + 0x12f8) != 0) &&
       (pcVar1 = *(code **)(param_1 + 0x1300), pcVar1 != (code *)0x0)) {
      if (*(int *)(pcVar1 + -4) != 0x3b38947) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119bc8);
        (*pcVar1)();
      }
      (*pcVar1)(*(long *)(param_1 + 0x12f8),*(undefined2 *)(param_4 + 0x601),param_4 + 1,*param_4);
    }
  }
  return;
}



//------------------------------------------------------------
// ims_new_server @ 00119c18 size=516
// signature: undefined ims_new_server(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ims_new_server(undefined8 *param_1,long param_2)

{
  undefined8 *puVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_58 = 0;
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: IMS server arrive: node %u port %u\n",
                 *(undefined4 *)(param_2 + 0xc),*(undefined4 *)(param_2 + 0x10));
  local_54 = *(undefined4 *)(param_2 + 0xc);
  uStack_50 = *(undefined4 *)(param_2 + 0x10);
  local_58 = CONCAT22(local_58._2_2_,0x2a);
  iVar5 = kernel_connect(*param_1,&local_58,0xc,0);
  if (iVar5 < 0) {
    _printk("%sicnss2_qmi: Fail to connect to remote service port\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: Fail to connect to remote service port\n",
                   &DAT_0011dab7);
    goto LAB_00119d84;
  }
  puVar2 = param_1 + 0x54;
  Hint_Prefetch(puVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar4) {
      *puVar2 = *puVar2 | 0x80000;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: IMS Server Connected: 0x%lx\n",param_1[0x54]);
  if (param_1 == (undefined8 *)0x4d8) {
    iVar5 = -0x13;
    goto LAB_00119d84;
  }
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Sending ASYNC ims subscribe for indication\n");
  lVar6 = kmalloc_trace(___list_add_valid,0xdc0,4);
  if (lVar6 == 0) {
    iVar5 = -0xc;
    goto LAB_00119d84;
  }
  puVar1 = param_1 + 0x29;
  *(undefined2 *)(lVar6 + 2) = 0x101;
  iVar5 = qmi_txn_init(param_1,puVar1,0,0);
  if (iVar5 < 0) {
    pcVar7 = "%sicnss2_qmi: Fail to init txn for ims subscribe for indication resp %d\n";
LAB_00119dd8:
    _printk(pcVar7,&DAT_0011c04b,iVar5);
    ipc_log_string(icnss_ipc_log_context,pcVar7,&DAT_0011dab7,iVar5);
  }
  else {
    iVar5 = qmi_send_request(param_1,0,puVar1,0x3e,8,
                             &ims_private_service_subscribe_ind_req_msg_v01_ei,lVar6);
    if (iVar5 < 0) {
      qmi_txn_cancel(puVar1);
      pcVar7 = "%sicnss2_qmi: Fail to send ims subscribe for indication req %d\n";
      goto LAB_00119dd8;
    }
    iVar5 = 0;
  }
  kfree(lVar6);
LAB_00119d84:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// ims_del_server @ 00119e2c size=92
// signature: undefined ims_del_server(void)
// callers: []
//------------------------------------------------------------

void ims_del_server(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: IMS server exit\n");
  puVar1 = (ulong *)(param_1 + 0x2a0);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = *puVar1 & 0xfffffffffff7ffff;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  return;
}



//------------------------------------------------------------
// ims_subscribe_for_indication_resp_cb @ 00119e98 size=200
// signature: undefined ims_subscribe_for_indication_resp_cb(void)
// callers: []
//------------------------------------------------------------

void ims_subscribe_for_indication_resp_cb
               (undefined8 param_1,undefined8 param_2,long param_3,ushort *param_4)

{
  ipc_log_string(icnss_ipc_log_context,"icnss2_qmi: Received IMS subscribe indication response\n");
  if (param_3 == 0) {
    _printk("%sicnss2_qmi: spurious response\n",&DAT_0011c04b);
    ipc_log_string(icnss_ipc_log_context,"%sicnss2_qmi: spurious response\n",&DAT_0011dab7);
  }
  else if (*param_4 != 0) {
    _printk("%sicnss2_qmi: IMS subscribe for indication request rejected, result:%d error:%d\n",
            &DAT_0011c04b,*param_4,param_4[1]);
    ipc_log_string(icnss_ipc_log_context,
                   "%sicnss2_qmi: IMS subscribe for indication request rejected, result:%d error:%d\n"
                   ,&DAT_0011dab7,*param_4,param_4[1]);
    *(uint *)(param_3 + 0x30) = -(uint)*param_4;
  }
  return;
}



//------------------------------------------------------------
// icnss_ims_process_wfc_call_ind_cb @ 00119f64 size=244
// signature: undefined icnss_ims_process_wfc_call_ind_cb(void)
// callers: []
//------------------------------------------------------------

void icnss_ims_process_wfc_call_ind_cb
               (long param_1,undefined8 param_2,long param_3,undefined1 *param_4)

{
  long lVar1;
  char *pcVar2;
  
  if (param_3 == 0) {
    pcVar2 = "%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Spurious indication\n";
  }
  else {
    if (param_4 != (undefined1 *)0x0) {
      ipc_log_string(icnss_ipc_log_context,
                     "icnss2_qmi: IMS->CNSS: WFC_CALL_IND: %x, %x %x, %x %x, %x %llx, %x %x, %x %x\n"
                     ,*param_4,param_4[1],param_4[2],param_4[3],param_4[4],param_4[5],
                     *(undefined8 *)(param_4 + 8),param_4[0x10],*(undefined2 *)(param_4 + 0x12),
                     param_4[0x14],*(undefined4 *)(param_4 + 0x18));
      lVar1 = kmemdup(param_4,0x20,0xcc0);
      if (lVar1 == 0) {
        return;
      }
      icnss_driver_event_post(param_1 + -0x4d8,0xe,0,lVar1);
      return;
    }
    pcVar2 = "%sicnss2_qmi: IMS->CNSS: WFC_CALL_IND: Invalid indication\n";
  }
  _printk(pcVar2,&DAT_0011c04b);
  ipc_log_string(icnss_ipc_log_context,pcVar2,&DAT_0011dab7);
  return;
}



//------------------------------------------------------------
// init_module @ 00125208 size=184
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  
  lVar1 = of_find_matching_node_and_match(0,icnss_dt_match,0);
  if (lVar1 != 0) {
    do {
      uVar2 = of_device_is_available(lVar1);
      if ((uVar2 & 1) != 0) {
        icnss_debug_init();
        uVar3 = __platform_driver_register(&icnss_driver,&__this_module);
        return uVar3;
      }
      lVar1 = of_find_matching_node_and_match(lVar1,icnss_dt_match,0);
    } while (lVar1 != 0);
  }
  _printk("%sicnss2: No valid icnss2 dtsi entry\n",&DAT_0011e9ea);
  ipc_log_string(icnss_ipc_log_context,"%sicnss2: No valid icnss2 dtsi entry\n",&DAT_0011dab7);
  return 0xffffffed;
}



//------------------------------------------------------------
// cleanup_module @ 001252c4 size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&icnss_driver);
  icnss_debug_deinit();
  return;
}



//------------------------------------------------------------
// debugfs_create_dir @ 0012b000 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [icnss_debugfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0012b008 size=1
// signature: undefined debugfs_create_file(void)
// callers: [icnss_debugfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0012b010 size=1
// signature: undefined _printk(void)
// callers: [cal_done_ind_cb, icnss_get_fw_cap, wlfw_rejuvenate_ack_send_sync_msg, icnss_fw_crashed, icnss_power_off, icnss_wpss_load, icnss_allow_recursive_recovery, wlfw_new_server, wlfw_qdss_trace_mem_info_send_sync, pin_connect_result_ind_cb, icnss_driver_event_fw_ready_ind, icnss_do_host_ramdump, icnss_modem_ssr_register_notifier, icnss_power_misc_params_init, icnss_soc_wake_msg_work, wlfw_qdss_trace_save_ind_cb, icnss_sysfs_create, __icnss_register_driver, icnss_smmu_fault_handler, wlan_en_delay_store, dms_del_server, wlfw_cap_send_sync_msg, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_pm_runtime_resume, wlfw_power_save_send_msg, icnss_update_cpr_info, wlfw_subsys_restart_level_msg, icnss_get_vreg, icnss_wlan_enable, icnss_process_twt_cfg_ind_event, icnss_athdiag_write, icnss_vreg_off_single, fw_init_done_ind_cb, icnss_get_temperature, icnss_get_ce_id, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_ims_process_wfc_call_ind_cb, icnss_probe, icnss_recovery_timeout_hdlr, icnss_smmu_unmap, register_fw_error_notifications, fw_error_fatal_handler, icnss_wpss_notifier_nb, icnss_smmu_get_domain, fw_ready_ind_cb, icnss_force_wake_request, icnss_collect_host_dump_info, wlfw_ind_register_send_sync_msg, icnss_genl_init, icnss_unregister_driver, icnss_ce_request_irq, wlfw_device_info_send_msg, icnss_debug_init, icnss_driver_event_work, icnss_wlfw_m3_dump_upload_segs_req_ind_cb, icnss_set_fw_log_mode, icnss_send_vbatt_update, icnss_call_driver_probe, icnss_wlfw_process_twt_cfg_ind, icnss_send_wlan_enable_to_fw, icnss_wlfw_driver_async_data_ind_cb, icnss_get_soc_info, wlfw_send_modem_shutdown_msg, icnss_disable_irq, wlfw_athdiag_read_send_sync_msg, icnss_thermal_cdev_register, icnss_get_clk, icnss_aop_interface_init, icnss_update_soc_level, icnss_enable_irq, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, rproc_restart_level_notifier, icnss_setup_dms_mac, icnss_force_wake_release, icnss_trigger_recovery, icnss_idle_restart, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, wlfw_qdss_trace_req_mem_ind_cb, wpss_boot_store, wlfw_send_soc_wake_msg, icnss_vreg_unvote, icnss_wpss_self_recovery, icnss_pm_runtime_suspend, wlfw_wlan_hw_init_cfg_msg, dms_new_server, icnss_connect_to_fw_server, icnss_send_smp2p, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, icnss_is_pci_ep_awake, icnss_get_mhi_state, wlfw_dynamic_feature_mask_send_sync_msg, init_module, icnss_power_on, selectFileNameByProduct, msa_ready_ind_cb, icnss_vreg_on_single, icnss_idle_shutdown, icnss_get_psf_info, icnss_pm_resume, wlfw_ini_send_sync_msg, icnss_pm_suspend_noirq, icnss_create_ramdump_device, icnss_clear_server, ims_subscribe_for_indication_resp_cb, icnss_hw_power_on, icnss_update_state_send_modem_shutdown, icnss_dms_init, register_early_crash_notifications, wlfw_del_server, icnss_qmi_get_dms_mac, icnss_pm_runtime_idle, icnss_driver_event_post, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_qdss_dnld_send_sync, fw_crash_indication_handler, icnss_msa0_ramdump, icnss_get_smp2p_info, icnss_request_bus_bandwidth, icnss_wpss_ssr_timeout_hdlr, icnss_debugfs_create, icnss_is_device_awake, icnss_athdiag_read, rejuvenate_ind_cb, icnss_enable_recovery, register_soc_wake_notif, icnss_smmu_map, icnss_tcdev_set_cur_state, icnss_disallow_recursive_recovery, icnss_ce_free_irq, icnss_modem_notifier_nb, icnss_pm_resume_noirq, icnss_soc_wake_event_post, wlfw_host_cap_send_sync, icnss_genl_send_msg, icnss_aop_pdc_reconfig, icnss_pm_suspend, icnss_remove, icnss_wlfw_respond_get_info_ind_cb, icnss_wlfw_wlan_mac_req_send_sync, icnss_process_wfc_call_ind_event, icnss_get_user_msi_assignment, icnss_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0012b018 size=1
// signature: undefined ipc_log_string(void)
// callers: [icnss_exit_power_save, cal_done_ind_cb, ims_del_server, icnss_get_fw_cap, icnss_fw_crashed, wlfw_rejuvenate_ack_send_sync_msg, icnss_power_off, icnss_wpss_load, icnss_allow_recursive_recovery, wlfw_new_server, wlfw_qdss_trace_mem_info_send_sync, pin_connect_result_ind_cb, icnss_driver_event_fw_ready_ind, icnss_do_host_ramdump, icnss_modem_ssr_register_notifier, icnss_power_misc_params_init, icnss_soc_wake_msg_work, wlfw_qdss_trace_save_ind_cb, icnss_wlan_disable, icnss_sysfs_create, __icnss_register_driver, icnss_smmu_fault_handler, wlan_en_delay_store, dms_del_server, wlfw_cap_send_sync_msg, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_wpss_early_notifier_nb, icnss_pm_runtime_resume, wlfw_power_save_send_msg, icnss_update_cpr_info, wlfw_subsys_restart_level_msg, icnss_get_vreg, icnss_wlan_enable, icnss_process_twt_cfg_ind_event, icnss_athdiag_write, icnss_vreg_off_single, fw_init_done_ind_cb, icnss_get_temperature, icnss_get_ce_id, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_hw_power_off, icnss_ims_process_wfc_call_ind_cb, icnss_probe, icnss_recovery_timeout_hdlr, icnss_smmu_unmap, register_fw_error_notifications, fw_error_fatal_handler, icnss_wpss_notifier_nb, icnss_smmu_get_domain, fw_ready_ind_cb, icnss_force_wake_request, icnss_get_curr_therm_cdev_state, icnss_collect_host_dump_info, wlfw_ind_register_send_sync_msg, icnss_genl_init, icnss_free_qdss_mem, icnss_unregister_driver, icnss_ce_request_irq, wlfw_device_info_send_msg, icnss_debug_init, icnss_driver_event_work, icnss_wlfw_m3_dump_upload_segs_req_ind_cb, icnss_get_msi_irq, icnss_set_fw_log_mode, icnss_send_vbatt_update, icnss_add_fw_prefix_name, qdss_tr_stop_store, icnss_call_driver_probe, icnss_wlfw_process_twt_cfg_ind, icnss_send_wlan_enable_to_fw, icnss_wlfw_driver_async_data_ind_cb, icnss_get_soc_info, wlfw_send_modem_shutdown_msg, icnss_disable_irq, wlfw_athdiag_read_send_sync_msg, icnss_thermal_cdev_register, icnss_get_clk, icnss_aop_interface_init, icnss_update_soc_level, icnss_enable_irq, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, rproc_restart_level_notifier, icnss_setup_dms_mac, qdss_conf_download_store, icnss_force_wake_release, icnss_trigger_recovery, icnss_idle_restart, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, wlfw_qdss_trace_req_mem_ind_cb, wpss_boot_store, wlfw_send_soc_wake_msg, icnss_vreg_unvote, icnss_wpss_self_recovery, icnss_pm_runtime_suspend, wlfw_wlan_hw_init_cfg_msg, dms_new_server, icnss_connect_to_fw_server, icnss_send_smp2p, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, icnss_is_pci_ep_awake, icnss_get_mhi_state, wlfw_dynamic_feature_mask_send_sync_msg, init_module, icnss_power_on, selectFileNameByProduct, msa_ready_ind_cb, icnss_vreg_on_single, icnss_idle_shutdown, icnss_get_psf_info, icnss_pm_resume, wlfw_ini_send_sync_msg, icnss_pm_suspend_noirq, icnss_create_ramdump_device, icnss_clear_server, ims_subscribe_for_indication_resp_cb, icnss_hw_power_on, icnss_host_ramdump_dev_release, icnss_update_state_send_modem_shutdown, icnss_dms_init, register_early_crash_notifications, wlfw_del_server, icnss_qmi_get_dms_mac, icnss_pm_runtime_idle, icnss_driver_event_post, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_qdss_dnld_send_sync, fw_crash_indication_handler, icnss_msa0_ramdump, icnss_get_smp2p_info, icnss_request_bus_bandwidth, icnss_wpss_ssr_timeout_hdlr, icnss_debugfs_create, icnss_is_device_awake, icnss_athdiag_read, rejuvenate_ind_cb, icnss_enable_recovery, register_soc_wake_notif, icnss_smmu_map, icnss_tcdev_set_cur_state, hw_trc_override_store, icnss_disallow_recursive_recovery, icnss_ce_free_irq, icnss_modem_notifier_nb, icnss_sysfs_store, icnss_call_driver_uevent, icnss_pm_resume_noirq, icnss_soc_wake_event_post, wlfw_host_cap_send_sync, icnss_genl_send_msg, icnss_aop_pdc_reconfig, icnss_pm_suspend, icnss_remove, icnss_wlfw_respond_get_info_ind_cb, icnss_wlfw_wlan_mac_req_send_sync, qdss_tr_start_store, icnss_process_wfc_call_ind_event, icnss_get_user_msi_assignment, icnss_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 0012b020 size=1
// signature: undefined debugfs_remove(void)
// callers: [icnss_debugfs_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0012b028 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [icnss_debug_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 0012b030 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [icnss_debug_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint_from_user @ 0012b038 size=1
// signature: undefined kstrtouint_from_user(void)
// callers: [icnss_stats_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0012b040 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [icnss_stats_write, icnss_do_host_ramdump, wlfw_msa_mem_info_send_sync_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0012b048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wlfw_athdiag_read_send_sync_msg, icnss_thermal_cdev_register, icnss_update_soc_level, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, icnss_fw_crashed, wlfw_rejuvenate_ack_send_sync_msg, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_wpss_load, wpss_boot_store, wlfw_send_soc_wake_msg, wlfw_qdss_trace_mem_info_send_sync, icnss_do_host_ramdump, wlfw_wlan_hw_init_cfg_msg, dms_new_server, icnss_connect_to_fw_server, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, wlfw_dynamic_feature_mask_send_sync_msg, selectFileNameByProduct, icnss_smmu_fault_handler, icnss_stats_write, wlan_en_delay_store, wlfw_cap_send_sync_msg, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, wlfw_ini_send_sync_msg, wlfw_power_save_send_msg, icnss_update_cpr_info, wlfw_subsys_restart_level_msg, icnss_get_vreg, icnss_wlan_enable, icnss_process_twt_cfg_ind_event, icnss_qmi_get_dms_mac, wlfw_wlan_mode_send_sync_msg, icnss_get_temperature, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, fw_crash_indication_handler, icnss_msa0_ramdump, icnss_probe, icnss_wpss_notifier_nb, rejuvenate_ind_cb, icnss_collect_host_dump_info, icnss_smmu_map, wlfw_ind_register_send_sync_msg, hw_trc_override_store, icnss_modem_notifier_nb, icnss_call_driver_uevent, wlfw_device_info_send_msg, icnss_driver_event_work, wlfw_host_cap_send_sync, icnss_genl_send_msg, icnss_aop_pdc_reconfig, cnss_get_bootarg_dt, icnss_send_vbatt_update, icnss_wlfw_wlan_mac_req_send_sync, qdss_tr_stop_store, icnss_send_wlan_enable_to_fw, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg, icnss_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 0012b050 size=1
// signature: undefined single_open(void)
// callers: [icnss_stats_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 0012b058 size=1
// signature: undefined seq_printf(void)
// callers: [icnss_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 0012b060 size=1
// signature: undefined seq_puts(void)
// callers: [icnss_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0012b080 size=1
// signature: undefined msleep(void)
// callers: [icnss_genl_send_msg, icnss_get_smp2p_info, icnss_setup_dms_mac]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0012b088 size=1
// signature: size_t strlen(char * __s)
// callers: [icnss_genl_send_msg, cnss_get_bootarg_dt, selectFileNameByProduct, wlfw_qdss_trace_save_ind_cb, rproc_restart_level_notifier, icnss_send_wlan_enable_to_fw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0012b090 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [wlfw_athdiag_read_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_qdss_trace_save_ind_cb, wlfw_athdiag_write_send_sync_msg, icnss_wlfw_bdf_dnld_send_sync, icnss_wlfw_get_info_send_sync, icnss_genl_send_msg, icnss_wlfw_qdss_dnld_send_sync, selectFileNameByProduct, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, icnss_get_soc_info, rejuvenate_ind_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0012b098 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [icnss_genl_send_msg, selectFileNameByProduct, icnss_wlfw_bdf_dnld_send_sync, wlfw_cap_send_sync_msg, icnss_get_soc_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 0012b0a0 size=1
// signature: undefined __alloc_skb(void)
// callers: [icnss_genl_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 0012b0a8 size=1
// signature: undefined genlmsg_put(void)
// callers: [icnss_genl_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_put @ 0012b0b0 size=1
// signature: undefined nla_put(void)
// callers: [icnss_genl_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_broadcast @ 0012b0c0 size=1
// signature: undefined netlink_broadcast(void)
// callers: [icnss_genl_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_broadcast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 0012b0c8 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [icnss_genl_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0012b0d0 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [icnss_genl_send_msg, wlfw_athdiag_read_send_sync_msg, selectFileNameByProduct, wlfw_athdiag_write_send_sync_msg, icnss_wlfw_bdf_dnld_send_sync, wlfw_cap_send_sync_msg, icnss_get_soc_info, icnss_wlfw_get_info_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_register_family @ 0012b0d8 size=1
// signature: undefined genl_register_family(void)
// callers: [icnss_genl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 0012b0e0 size=1
// signature: undefined genl_unregister_family(void)
// callers: [icnss_genl_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0012b0f0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_power_save_send_msg, wlfw_subsys_restart_level_msg, icnss_thermal_cdev_register, icnss_create_ramdump_device, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, rproc_restart_level_notifier, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_driver_event_post, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_new_server, wlfw_qdss_trace_mem_info_send_sync, icnss_do_host_ramdump, wlfw_wlan_hw_init_cfg_msg, icnss_wpss_notifier_nb, rejuvenate_ind_cb, icnss_collect_host_dump_info, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_qdss_trace_save_ind_cb, wlfw_athdiag_write_send_sync_msg, icnss_modem_notifier_nb, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, icnss_wlfw_m3_dump_upload_segs_req_ind_cb, icnss_soc_wake_event_post, wlfw_host_cap_send_sync, icnss_send_vbatt_update, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg, icnss_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 0012b100 size=1
// signature: undefined pm_stay_awake(void)
// callers: [icnss_soc_wake_msg_work, icnss_fw_crashed, icnss_driver_event_post, icnss_driver_event_work, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0012b108 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [icnss_probe, icnss_driver_event_post, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0012b110 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [icnss_soc_wake_msg_work, icnss_driver_event_post, icnss_driver_event_work, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0012b118 size=1
// signature: undefined __list_add_valid(void)
// callers: [icnss_get_vreg, icnss_msa0_ramdump, icnss_thermal_cdev_register, icnss_get_clk, icnss_probe, icnss_do_host_ramdump, icnss_driver_event_post, icnss_driver_event_work, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0012b120 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [icnss_soc_wake_msg_work, icnss_driver_event_post, icnss_driver_event_work, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0012b128 size=1
// signature: undefined queue_work_on(void)
// callers: [icnss_battery_supply_callback, icnss_wpss_ssr_timeout_hdlr, icnss_driver_event_post, icnss_driver_event_work, wpss_boot_store, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 0012b130 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [icnss_driver_event_post, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 0012b138 size=1
// signature: undefined wait_for_completion(void)
// callers: [icnss_driver_event_post, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0012b140 size=1
// signature: undefined kfree(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_power_save_send_msg, wlfw_subsys_restart_level_msg, icnss_thermal_cdev_unregister, icnss_create_ramdump_device, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, icnss_host_ramdump_dev_release, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_driver_event_post, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_qdss_trace_mem_info_send_sync, icnss_probe, icnss_do_host_ramdump, wlfw_wlan_hw_init_cfg_msg, icnss_connect_to_fw_server, icnss_collect_host_dump_info, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, icnss_soc_wake_msg_work, wlfw_qdss_trace_save_ind_cb, wlfw_athdiag_write_send_sync_msg, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, icnss_driver_event_work, icnss_wlfw_m3_dump_upload_segs_req_ind_cb, icnss_soc_wake_event_post, wlfw_host_cap_send_sync, icnss_send_vbatt_update, icnss_remove, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 0012b148 size=1
// signature: undefined pm_relax(void)
// callers: [icnss_soc_wake_msg_work, icnss_driver_event_fw_ready_ind, icnss_driver_event_post, icnss_driver_event_work, icnss_soc_wake_event_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 0012b150 size=1
// signature: undefined icc_set_bw(void)
// callers: [icnss_request_bus_bandwidth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0012b158 size=1
// signature: undefined complete(void)
// callers: [icnss_remove, icnss_soc_wake_msg_work, fw_soc_wake_ack_handler, icnss_call_driver_probe, icnss_driver_event_fw_ready_ind, icnss_modem_notifier_nb, icnss_block_shutdown, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dump_enabled @ 0012b160 size=1
// signature: undefined dump_enabled(void)
// callers: [icnss_msa0_ramdump, icnss_do_host_ramdump, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 0012b168 size=1
// signature: undefined device_initialize(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 0012b170 size=1
// signature: undefined dev_set_name(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 0012b178 size=1
// signature: undefined device_add(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 0012b180 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [selectFileNameByProduct, icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_elf_dump @ 0012b188 size=1
// signature: undefined qcom_elf_dump(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_elf_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0012b190 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [icnss_put_vreg, icnss_msa0_ramdump, icnss_thermal_cdev_unregister, icnss_get_clk, icnss_soc_wake_msg_work, icnss_put_resources, icnss_probe, icnss_put_clk, icnss_do_host_ramdump, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_del @ 0012b198 size=1
// signature: undefined device_del(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 0012b1a0 size=1
// signature: undefined put_device(void)
// callers: [icnss_do_host_ramdump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 0012b1a8 size=1
// signature: undefined dma_free_attrs(void)
// callers: [icnss_free_qdss_mem, icnss_driver_event_fw_ready_ind, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0012b1b0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [icnss_update_cpr_info, icnss_get_vreg, icnss_wlfw_qdss_dnld_send_sync, icnss_thermal_cdev_register, icnss_create_ramdump_device, icnss_wlfw_bdf_dnld_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_by_name @ 0012b1b8 size=1
// signature: undefined of_find_node_by_name(void)
// callers: [register_soc_wake_notif, icnss_thermal_cdev_register, register_fw_error_notifications, register_early_crash_notifications]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0012b1c0 size=1
// signature: undefined of_find_property(void)
// callers: [icnss_smmu_map, icnss_thermal_cdev_register, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 0012b1c8 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [icnss_thermal_cdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 0012b1d0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [icnss_thermal_cdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0012b1d8 size=1
// signature: undefined mutex_lock(void)
// callers: [icnss_get_curr_therm_cdev_state, icnss_tcdev_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0012b1e0 size=1
// signature: undefined mutex_unlock(void)
// callers: [icnss_get_curr_therm_cdev_state, icnss_tcdev_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0012b1e8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [register_soc_wake_notif, icnss_power_on_chain1_reg, icnss_probe, icnss_battery_supply_callback, register_fw_error_notifications, register_early_crash_notifications, icnss_get_user_msi_assignment]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 0012b1f0 size=1
// signature: undefined request_threaded_irq(void)
// callers: [icnss_ce_request_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 0012b1f8 size=1
// signature: undefined free_irq(void)
// callers: [icnss_ce_free_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0012b200 size=1
// signature: undefined enable_irq(void)
// callers: [icnss_enable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0012b208 size=1
// signature: undefined disable_irq(void)
// callers: [icnss_disable_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0012b210 size=1
// signature: undefined of_property_read_string(void)
// callers: [icnss_get_temperature, cnss_get_bootarg_dt, icnss_aop_interface_init, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_get_zone_by_name @ 0012b218 size=1
// signature: undefined thermal_zone_get_zone_by_name(void)
// callers: [icnss_get_temperature]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_get_zone_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_get_temp @ 0012b220 size=1
// signature: undefined thermal_zone_get_temp(void)
// callers: [icnss_get_temperature]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_get_temp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0012b228 size=1
// signature: undefined of_get_property(void)
// callers: [icnss_smmu_map, icnss_get_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_map @ 0012b230 size=1
// signature: undefined iommu_map(void)
// callers: [icnss_smmu_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_unmap @ 0012b238 size=1
// signature: undefined iommu_unmap(void)
// callers: [icnss_smmu_unmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_unmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// socinfo_get_serial_number @ 0012b240 size=1
// signature: undefined socinfo_get_serial_number(void)
// callers: [icnss_socinfo_get_serial_number]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void socinfo_get_serial_number(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_restart_pd @ 0012b248 size=1
// signature: undefined pdr_restart_pd(void)
// callers: [icnss_trigger_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_restart_pd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_update_bits @ 0012b250 size=1
// signature: undefined qcom_smem_state_update_bits(void)
// callers: [icnss_send_smp2p, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0012b258 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [icnss_send_smp2p, icnss_update_state_send_modem_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0012b260 size=1
// signature: undefined scnprintf(void)
// callers: [icnss_add_fw_prefix_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_matching_node_and_match @ 0012b270 size=1
// signature: undefined of_find_matching_node_and_match(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_matching_node_and_match(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 0012b278 size=1
// signature: undefined of_device_is_available(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0012b280 size=1
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
// platform_driver_unregister @ 0012b288 size=1
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
// log_read_mmio @ 0012b290 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0012b298 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 0012b2a0 size=1
// signature: undefined of_match_device(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0012b2a8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [icnss_get_vreg, icnss_get_clk, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cnss_deinitialize_prealloc_pool @ 0012b2b0 size=1
// signature: undefined cnss_deinitialize_prealloc_pool(void)
// callers: [icnss_remove, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cnss_deinitialize_prealloc_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cnss_initialize_prealloc_pool @ 0012b2b8 size=1
// signature: undefined cnss_initialize_prealloc_pool(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cnss_initialize_prealloc_pool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 0012b2c0 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 0012b2c8 size=1
// signature: undefined devm_ioremap(void)
// callers: [msa_ready_ind_cb, icnss_probe, icnss_driver_event_work, fw_init_done_ind_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 0012b2d0 size=1
// signature: undefined platform_get_irq(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0012b2d8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [icnss_probe, icnss_wpss_load, wlfw_host_cap_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_resource @ 0012b2e0 size=1
// signature: undefined dma_map_resource(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0012b2e8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0012b2f0 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 0012b2f8 size=1
// signature: undefined __of_get_address(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_translate_address @ 0012b300 size=1
// signature: undefined of_translate_address(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_translate_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memremap @ 0012b308 size=1
// signature: undefined memremap(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void memremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 0012b310 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0012b318 size=1
// signature: undefined __kmalloc(void)
// callers: [icnss_power_misc_params_init, cnss_get_bootarg_dt, icnss_wlfw_qdss_data_send_sync, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0012b320 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [icnss_power_misc_params_init, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 0012b328 size=1
// signature: undefined of_icc_get(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_get_domain_for_dev @ 0012b330 size=1
// signature: undefined iommu_get_domain_for_dev(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_get_domain_for_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_put @ 0012b338 size=1
// signature: undefined icc_put(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iommu_set_fault_handler @ 0012b340 size=1
// signature: undefined iommu_set_fault_handler(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iommu_set_fault_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0012b348 size=1
// signature: undefined __mutex_init(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0012b350 size=1
// signature: undefined alloc_workqueue(void)
// callers: [icnss_probe, icnss_get_psf_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 0012b358 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [icnss_remove, icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 0012b360 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0012b368 size=1
// signature: undefined destroy_workqueue(void)
// callers: [icnss_remove, icnss_probe, icnss_get_psf_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 0012b378 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0012b380 size=1
// signature: undefined init_timer_key(void)
// callers: [icnss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 0012b388 size=1
// signature: undefined del_timer(void)
// callers: [icnss_remove, icnss_driver_event_fw_ready_ind, icnss_wpss_notifier_nb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 0012b390 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_put @ 0012b398 size=1
// signature: undefined power_supply_put(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 0012b3a0 size=1
// signature: undefined __flush_workqueue(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 0012b3a8 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 0012b3b0 size=1
// signature: undefined kobject_put(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_link @ 0012b3c0 size=1
// signature: undefined sysfs_remove_link(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_device_remove_group @ 0012b3c8 size=1
// signature: undefined devm_device_remove_group(void)
// callers: [icnss_remove, icnss_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_device_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0012b3d0 size=1
// signature: undefined complete_all(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 0012b3d8 size=1
// signature: undefined device_unregister(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 0012b3e0 size=1
// signature: undefined ida_free(void)
// callers: [icnss_create_ramdump_device, icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_early_ssr_notifier @ 0012b3e8 size=1
// signature: undefined qcom_unregister_early_ssr_notifier(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_early_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 0012b3f0 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_release @ 0012b3f8 size=1
// signature: undefined pdr_handle_release(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 0012b400 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_allow @ 0012b408 size=1
// signature: undefined pm_runtime_allow(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_allow(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0012b410 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 0012b418 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0012b420 size=1
// signature: undefined class_destroy(void)
// callers: [icnss_enable_recovery, icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 0012b428 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [icnss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 0012b430 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_dump @ 0012b438 size=1
// signature: undefined qcom_dump(void)
// callers: [icnss_msa0_ramdump, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 0012b448 size=1
// signature: undefined mod_timer(void)
// callers: [fw_crash_indication_handler, icnss_modem_notifier_nb, icnss_wpss_notifier_nb, icnss_driver_event_work, icnss_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 0012b450 size=1
// signature: undefined kmemdup(void)
// callers: [icnss_ims_process_wfc_call_ind_cb, icnss_wlfw_process_twt_cfg_ind, icnss_driver_event_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0012b458 size=1
// signature: undefined __class_create(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 0012b460 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_early_ssr_notifier @ 0012b468 size=1
// signature: undefined qcom_register_early_ssr_notifier(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_early_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 0012b470 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [icnss_enable_recovery, icnss_modem_ssr_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_alloc @ 0012b478 size=1
// signature: undefined pdr_handle_alloc(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_add_lookup @ 0012b480 size=1
// signature: undefined pdr_add_lookup(void)
// callers: [icnss_enable_recovery]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_device_add_group @ 0012b488 size=1
// signature: undefined devm_device_add_group(void)
// callers: [icnss_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_device_add_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_link @ 0012b490 size=1
// signature: undefined sysfs_create_link(void)
// callers: [icnss_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 0012b498 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [icnss_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0012b4a0 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [icnss_sysfs_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0012b4a8 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [icnss_runtime_pm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_forbid @ 0012b4b0 size=1
// signature: undefined pm_runtime_forbid(void)
// callers: [icnss_runtime_pm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_forbid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 0012b4b8 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [icnss_runtime_pm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 0012b4c0 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [icnss_runtime_pm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 0012b4c8 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [icnss_wpss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_boot @ 0012b4d0 size=1
// signature: undefined rproc_boot(void)
// callers: [icnss_wpss_self_recovery, icnss_wpss_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_boot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_put @ 0012b4d8 size=1
// signature: undefined rproc_put(void)
// callers: [icnss_wpss_self_recovery, icnss_sysfs_store, icnss_wpss_load, wpss_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_shutdown @ 0012b4e0 size=1
// signature: undefined rproc_shutdown(void)
// callers: [icnss_wpss_self_recovery, icnss_sysfs_store, wpss_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_shutdown(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_request_active @ 0012b4e8 size=1
// signature: undefined cpu_latency_qos_request_active(void)
// callers: [icnss_fw_crashed, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_request_active(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_update_request @ 0012b4f0 size=1
// signature: undefined cpu_latency_qos_update_request(void)
// callers: [icnss_fw_crashed, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 0012b4f8 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [icnss_fw_crashed, icnss_driver_event_fw_ready_ind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 0012b500 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [register_soc_wake_notif, register_fw_error_notifications, register_early_crash_notifications]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0012b508 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [register_soc_wake_notif, register_fw_error_notifications, register_early_crash_notifications]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_get @ 0012b510 size=1
// signature: undefined qcom_smem_state_get(void)
// callers: [icnss_get_smp2p_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 0012b518 size=1
// signature: undefined ida_alloc_range(void)
// callers: [icnss_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0012b520 size=1
// signature: undefined device_create(void)
// callers: [icnss_create_ramdump_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0012b528 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [hw_trc_override_store, wlan_en_delay_store, qdss_tr_stop_store, wpss_boot_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0012b530 size=1
// signature: undefined strnstr(void)
// callers: [cnss_get_bootarg_dt, rproc_restart_level_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 0012b538 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [icnss_pm_runtime_idle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 0012b540 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [icnss_get_vreg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0012b548 size=1
// signature: undefined regulator_set_load(void)
// callers: [icnss_vreg_unvote, icnss_vreg_on_single, icnss_vreg_off_single]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 0012b550 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [icnss_vreg_unvote, icnss_vreg_on_single, icnss_vreg_off_single]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0012b558 size=1
// signature: undefined devm_clk_get(void)
// callers: [icnss_get_clk]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 0012b560 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [icnss_hw_power_off, icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 0012b568 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [icnss_hw_power_off, icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 0012b570 size=1
// signature: undefined clk_set_rate(void)
// callers: [icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0012b578 size=1
// signature: undefined clk_prepare(void)
// callers: [icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0012b580 size=1
// signature: undefined clk_enable(void)
// callers: [icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0012b588 size=1
// signature: undefined clk_unprepare(void)
// callers: [icnss_hw_power_off, icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0012b590 size=1
// signature: undefined clk_disable(void)
// callers: [icnss_hw_power_off, icnss_hw_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __udelay @ 0012b598 size=1
// signature: undefined __udelay(void)
// callers: [icnss_vreg_on_single]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0012b5a0 size=1
// signature: undefined regulator_enable(void)
// callers: [icnss_vreg_on_single]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 0012b5a8 size=1
// signature: undefined mbox_request_channel(void)
// callers: [icnss_aop_interface_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 0012b5b0 size=1
// signature: undefined qmp_get(void)
// callers: [icnss_aop_interface_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_send @ 0012b5b8 size=1
// signature: undefined qmp_send(void)
// callers: [icnss_aop_pdc_reconfig, icnss_update_cpr_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 0012b5c0 size=1
// signature: undefined mbox_send_message(void)
// callers: [icnss_aop_pdc_reconfig, icnss_update_cpr_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 0012b5c8 size=1
// signature: undefined mbox_free_channel(void)
// callers: [icnss_aop_interface_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_put @ 0012b5d0 size=1
// signature: undefined qmp_put(void)
// callers: [icnss_aop_interface_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 0012b5d8 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [icnss_get_psf_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 0012b5e0 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [icnss_update_soc_level]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 0012b5e8 size=1
// signature: undefined power_supply_get_property(void)
// callers: [icnss_update_soc_level]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0012b5f0 size=1
// signature: undefined regulator_disable(void)
// callers: [icnss_vreg_off_single]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_init @ 0012b600 size=1
// signature: undefined qmi_txn_init(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_power_save_send_msg, wlfw_subsys_restart_level_msg, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_qmi_get_dms_mac, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_qdss_trace_mem_info_send_sync, wlfw_wlan_hw_init_cfg_msg, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, wlfw_host_cap_send_sync, icnss_send_vbatt_update, icnss_wlfw_wlan_mac_req_send_sync, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_send_request @ 0012b610 size=1
// signature: undefined qmi_send_request(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_power_save_send_msg, wlfw_subsys_restart_level_msg, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_qmi_get_dms_mac, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_qdss_trace_mem_info_send_sync, wlfw_wlan_hw_init_cfg_msg, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, wlfw_host_cap_send_sync, icnss_send_vbatt_update, icnss_wlfw_wlan_mac_req_send_sync, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_send_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_wait @ 0012b618 size=1
// signature: undefined qmi_txn_wait(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_subsys_restart_level_msg, icnss_wlfw_bdf_dnld_send_sync, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_qmi_get_dms_mac, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_qdss_trace_mem_info_send_sync, wlfw_wlan_hw_init_cfg_msg, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, wlfw_host_cap_send_sync, icnss_send_vbatt_update, icnss_wlfw_wlan_mac_req_send_sync, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_txn_cancel @ 0012b620 size=1
// signature: undefined qmi_txn_cancel(void)
// callers: [wlfw_ini_send_sync_msg, wlfw_athdiag_read_send_sync_msg, wlfw_power_save_send_msg, wlfw_subsys_restart_level_msg, icnss_wlfw_bdf_dnld_send_sync, ims_new_server, wlfw_rejuvenate_ack_send_sync_msg, icnss_process_twt_cfg_ind_event, wlfw_msa_mem_info_send_sync_msg, icnss_wlfw_get_info_send_sync, icnss_qmi_get_dms_mac, wlfw_send_soc_wake_msg, wlfw_wlan_mode_send_sync_msg, wlfw_send_qdss_trace_mode_req, icnss_wlfw_m3_dump_upload_done_send_sync, icnss_wlfw_qdss_dnld_send_sync, wlfw_qdss_trace_mem_info_send_sync, wlfw_wlan_hw_init_cfg_msg, wlfw_ind_register_send_sync_msg, icnss_wlfw_qdss_data_send_sync, wlfw_athdiag_write_send_sync_msg, wlfw_device_info_send_msg, wlfw_dynamic_feature_mask_send_sync_msg, wlfw_host_cap_send_sync, icnss_send_vbatt_update, icnss_wlfw_wlan_mac_req_send_sync, wlfw_cap_send_sync_msg, icnss_send_wlan_enable_to_fw, wlfw_msa_ready_send_sync_msg, wlfw_cal_report_req, icnss_process_wfc_call_ind_event, wlfw_send_modem_shutdown_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_txn_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 0012b690 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [wlfw_wlan_mode_send_sync_msg, wlfw_cap_send_sync_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_init @ 0012b6b8 size=1
// signature: undefined qmi_handle_init(void)
// callers: [icnss_register_ims_service, icnss_register_fw_service, icnss_clear_server, icnss_dms_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_add_lookup @ 0012b6c0 size=1
// signature: undefined qmi_add_lookup(void)
// callers: [icnss_register_ims_service, icnss_register_fw_service, icnss_clear_server, icnss_dms_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmi_handle_release @ 0012b6c8 size=1
// signature: undefined qmi_handle_release(void)
// callers: [icnss_clear_server, icnss_dms_deinit, icnss_unregister_fw_service, icnss_unregister_ims_service]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmi_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// firmware_request_nowarn @ 0012b6d0 size=1
// signature: undefined firmware_request_nowarn(void)
// callers: [icnss_wlfw_qdss_dnld_send_sync, icnss_wlfw_bdf_dnld_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void firmware_request_nowarn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0012b6e8 size=1
// signature: undefined release_firmware(void)
// callers: [icnss_wlfw_qdss_dnld_send_sync, icnss_wlfw_bdf_dnld_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_connect @ 0012b7c0 size=1
// signature: undefined kernel_connect(void)
// callers: [ims_new_server, dms_new_server, icnss_connect_to_fw_server]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_connect(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 0012b7d8 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [cnss_get_bootarg_dt, wlfw_host_cap_send_sync]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 0012b840 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [selectFileNameByProduct]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcpy @ 0012b848 size=1
// signature: undefined strlcpy(void)
// callers: [cnss_get_bootarg_dt, icnss_wlfw_m3_dump_upload_segs_req_ind_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0012b850 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [cnss_get_bootarg_dt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



