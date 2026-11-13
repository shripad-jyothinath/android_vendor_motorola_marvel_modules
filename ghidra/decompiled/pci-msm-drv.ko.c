// Decompiled by Ghidra 12.2
// Program: pci-msm-drv.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_pcie_reg_dump @ 00102f94 size=908
// signature: undefined msm_pcie_reg_dump(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_reg_dump(long param_1,long param_2,uint param_3)

{
  void *__s;
  undefined1 uVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined *puVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  long lVar9;
  long lVar10;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  while ((*(char *)(param_1 + 0x6c) == '\0' || ((*(ushort *)(param_1 + 0x72) & 0xf0) != 0x40))) {
    if ((*(uint *)(param_1 + 0xac9) >> 0x17 & 1) != 0) {
      param_1 = *(long *)(param_1 + 0xc80);
    }
    if ((*(long *)(*(long *)(param_1 + 0x10) + 0x10) == 0) ||
       (param_1 = *(long *)(*(long *)(param_1 + 0x10) + 0x38), param_1 == 0)) {
      return 0xffffffed;
    }
  }
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar5 == 0) {
    puVar4 = &DAT_0012c28c;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d hang event dump buff=0x%x len=%u\n"
                   ,"msm_pcie_reg_dump",*(undefined4 *)(lVar5 + 0x570),param_2,param_3);
    if (*(int *)(lVar5 + 0x4b0) == 4) {
      puVar4 = &DAT_0012ab4f;
    }
    else {
      if (*(char *)(lVar5 + 0x6a0) == '\0') {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d buf=0x%x size=%u, reg_len=%u\n"
                       ,"msm_pcie_reg_copy",*(undefined4 *)(lVar5 + 0x570),param_2,param_3,4);
        lVar7 = *(long *)(lVar5 + 0xce0);
        if ((lVar7 == 0) || (iVar8 = *(int *)(lVar5 + 0xcd8), iVar8 == 0)) {
          uVar6 = 0;
        }
        else {
          lVar9 = 0;
          lVar10 = *(long *)(lVar5 + 0x380);
          uVar6 = iVar8 << 2;
          do {
            if (param_3 < (uint)lVar9 + 4) {
              uVar6 = (uint)lVar9;
              break;
            }
            ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d *seq:%u\n",
                           "msm_pcie_reg_copy",*(undefined4 *)(lVar5 + 0x570),
                           *(undefined4 *)(lVar7 + lVar9));
            uVar2 = readl_relaxed(lVar10 + (ulong)*(uint *)(lVar7 + lVar9));
            iVar8 = iVar8 + -1;
            *(undefined4 *)(param_2 + lVar9) = uVar2;
            lVar9 = lVar9 + 4;
          } while (iVar8 != 0);
        }
        __s = (void *)(param_2 + (ulong)uVar6);
        param_3 = param_3 - uVar6;
        uVar3 = readl_relaxed(*(long *)(lVar5 + 0x388) + (ulong)*(uint *)(lVar5 + 0x518));
        if (((uVar3 & 0xffffffff) >> ((ulong)*(uint *)(lVar5 + 0x51c) & 0x3f) & 1) == 0) {
          ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d Dump DBI registers\n",
                         "msm_pcie_reg_dump",*(undefined4 *)(lVar5 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar5 + 0x730),
                         "DUMP:%s: RC%d buf=0x%x size=%u, reg_len=%u\n","msm_pcie_reg_copy",
                         *(undefined4 *)(lVar5 + 0x570),__s,param_3,4);
          lVar7 = *(long *)(lVar5 + 0xcf0);
          if ((lVar7 == 0) || (iVar8 = *(int *)(lVar5 + 0xce8), iVar8 == 0)) {
            uVar6 = 0;
          }
          else {
            lVar9 = 0;
            lVar10 = *(long *)(lVar5 + 0x3a0);
            uVar6 = iVar8 << 2;
            do {
              if (param_3 < (uint)lVar9 + 4) {
                uVar6 = (uint)lVar9;
                break;
              }
              ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d *seq:%u\n",
                             "msm_pcie_reg_copy",*(undefined4 *)(lVar5 + 0x570),
                             *(undefined4 *)(lVar7 + lVar9));
              uVar2 = readl_relaxed(lVar10 + (ulong)*(uint *)(lVar7 + lVar9));
              iVar8 = iVar8 + -1;
              *(undefined4 *)((long)__s + lVar9) = uVar2;
              lVar9 = lVar9 + 4;
            } while (iVar8 != 0);
          }
        }
        else {
          ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d PHY is off, skip DBI\n",
                         "msm_pcie_reg_dump",*(undefined4 *)(lVar5 + 0x570));
          memset(__s,0,(ulong)(uint)(*(int *)(lVar5 + 0xce8) << 2));
          uVar6 = *(int *)(lVar5 + 0xce8) << 2;
        }
        ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d buf=0x%x size=%u, reg_len=%u\n"
                       ,"msm_pcie_reg_copy",*(undefined4 *)(lVar5 + 0x570),(long)__s + (ulong)uVar6,
                       param_3 - uVar6,1);
        lVar7 = *(long *)(lVar5 + 0xcd0);
        if ((lVar7 != 0) && (iVar8 = *(int *)(lVar5 + 0xccc), iVar8 != 0)) {
          lVar9 = 0;
          lVar10 = *(long *)(lVar5 + 0x388);
          do {
            if (param_3 - uVar6 <= (uint)lVar9) break;
            ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d *seq:%u\n",
                           "msm_pcie_reg_copy",*(undefined4 *)(lVar5 + 0x570),
                           *(undefined4 *)(lVar7 + lVar9 * 4));
            uVar1 = readl_relaxed(lVar10 + (ulong)*(uint *)(lVar7 + lVar9 * 4));
            *(undefined1 *)((long)__s + (ulong)uVar6 + lVar9) = uVar1;
            lVar9 = lVar9 + 1;
          } while (iVar8 != (int)lVar9);
        }
        ipc_log_string(*(undefined8 *)(lVar5 + 0x730),"DUMP:%s: RC%d hang event Exit\n",
                       "msm_pcie_reg_dump",*(undefined4 *)(lVar5 + 0x570));
        return 0;
      }
      puVar4 = &DAT_001293df;
    }
  }
  _printk(puVar4);
  return 0xffffffed;
}



//------------------------------------------------------------
// readl_relaxed @ 00103320 size=124
// signature: undefined readl_relaxed(void)
// callers: [aspm_stat_show, pcie_dm_core_dump, msm_pcie_config_bandwidth_int, msm_pcie_access_reg, pcie_sm_dump, msm_pcie_l1ss_timeout_disable, handle_global_irq, msm_pcie_restore_sid_config, msm_pcie_enable_link, msm_pcie_iatu_setup_ecam_blocker, msm_pcie_reg_dump, msm_pcie_parf_cesta_config, msm_pcie_oper_conf, msm_pcie_check_ep_access, msm_pcie_link_retrain, msm_pcie_check_link_dev_status, msm_pcie_config_controller, msm_pcie_allow_l1, pcie_phy_dump, msm_pcie_enable, msm_pcie_disable, msm_pcie_loopback, msm_pcie_prevent_l1, msm_pcie_cfg_bdf, msm_pcie_config_sid, msm_pcie_pm_suspend, msm_pcie_config_tc_bdf_sid_map, msm_pcie_handle_linkdown, pcie_parf_dump, msm_pcie_probe, handle_sbr_func, msm_pcie_enumerate, msm_pcie_pm_resume_noirq, msm_pcie_sel_debug_testcase, msm_pcie_config_l1ss, msm_pcie_write_mask, msm_pcie_rumi_init, msm_pcie_poll_for_l0_from_l0s, init_module, msm_pcie_deenumerate, msm_pcie_confirm_linkup, msm_pcie_pm_suspend_noirq, msm_pcie_l1ss_timeout_enable, msm_pcie_pm_control, msm_pcie_iatu_config_shift, msm_pcie_debugfs_aer_enable]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x103368,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_pcie_fmd_enable @ 001033a0 size=292
// signature: undefined msm_pcie_fmd_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_fmd_enable(long param_1)

{
  int iVar1;
  long lVar2;
  
  while( true ) {
    if (param_1 == 0) {
      return 0xffffffed;
    }
    if ((*(char *)(param_1 + 0x6c) != '\0') && ((*(ushort *)(param_1 + 0x72) & 0xf0) == 0x40))
    break;
    if ((*(uint *)(param_1 + 0xac9) >> 0x17 & 1) != 0) {
      param_1 = *(long *)(param_1 + 0xc80);
    }
    if (*(long *)(*(long *)(param_1 + 0x10) + 0x10) == 0) {
      return 0xffffffed;
    }
    param_1 = *(long *)(*(long *)(param_1 + 0x10) + 0x38);
  }
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar2 == 0) {
    _printk(&DAT_0012c28c);
    return 0xffffffed;
  }
  ipc_log_string(*(undefined8 *)(lVar2 + 0x728),"INFO:%s: RC%d Enable FMD\n","msm_pcie_fmd_enable",
                 *(undefined4 *)(lVar2 + 0x570));
  ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: RC%d Enable FMD\n","msm_pcie_fmd_enable",
                 *(undefined4 *)(lVar2 + 0x570));
  _printk(&DAT_00124d65,"msm_pcie_fmd_enable",*(undefined4 *)(lVar2 + 0x570));
  if (*(char *)(lVar2 + 0xda8) != '\0') {
    _printk(&DAT_00122bf7,*(undefined4 *)(lVar2 + 0x570));
    return 0;
  }
  gpio_to_desc(*(undefined4 *)(lVar2 + 0xe8));
  iVar1 = gpiod_get_raw_value();
  if (iVar1 == 0) {
    msm_pcie_config_perst(lVar2,0);
  }
  *(undefined1 *)(lVar2 + 0xda8) = 1;
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_perst @ 001034c4 size=276
// signature: undefined msm_pcie_config_perst(void)
// callers: [msm_pcie_enable, msm_pcie_disable, msm_pcie_handle_linkdown, msm_pcie_enable_link, msm_pcie_fmd_enable, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_config_perst(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined8 uVar2;
  int iVar3;
  
  if (*(char *)(param_1 + 0xda8) == '\0') {
    if ((param_2 & 1) == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"INFO:%s: PCIe: RC%d: de-assert PERST\n",
                       "msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: de-assert PERST\n",
                       "msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
      }
      _printk(&DAT_00121bb9,"msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
      uVar1 = *(undefined4 *)(param_1 + 0xe8);
      iVar3 = 1 - *(int *)(param_1 + 0xf0);
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"INFO:%s: PCIe: RC%d: assert PERST\n",
                       "msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: assert PERST\n",
                       "msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
      }
      _printk(&DAT_0012c9d4,"msm_pcie_config_perst",*(undefined4 *)(param_1 + 0x570));
      uVar1 = *(undefined4 *)(param_1 + 0xe8);
      iVar3 = *(int *)(param_1 + 0xf0);
    }
    uVar2 = gpio_to_desc(uVar1);
    gpiod_set_raw_value(uVar2,iVar3);
  }
  else {
    _printk(&DAT_00126c6b,*(undefined4 *)(param_1 + 0x570));
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_debug_info @ 001035dc size=360
// signature: undefined msm_pcie_debug_info(void)
// callers: []
//------------------------------------------------------------

undefined8
msm_pcie_debug_info(long param_1,uint param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   undefined4 param_6)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_0012d152);
    uVar2 = 0xffffffed;
  }
  else {
    if (param_2 - 0xc < 3) {
      if (param_3 - 10U < 0xfffffff7) {
        _printk(&DAT_0012750c,"msm_pcie_debug_info");
        _printk(&DAT_00124d7c,"msm_pcie_debug_info",base_sel);
        return 0xffffffea;
      }
      base_sel = param_3;
      _printk(&DAT_00120282,"msm_pcie_debug_info");
      if ((param_2 & 0xfffffffe) == 0xc) {
        wr_offset = param_4;
        wr_mask = param_5;
        wr_value = param_6;
        _printk(&DAT_0012d176,"msm_pcie_debug_info",param_4);
        _printk(&DAT_0012ef1c,"msm_pcie_debug_info",wr_mask);
        _printk(&DAT_0012c2be,"msm_pcie_debug_info",wr_value);
      }
    }
    lVar1 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
    rc_sel = (undefined4)(1L << ((ulong)*(uint *)(lVar1 + 0x570) & 0x3f));
    msm_pcie_sel_debug_testcase(lVar1,param_2);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_pcie_sel_debug_testcase @ 00103744 size=4380
// signature: undefined msm_pcie_sel_debug_testcase(void)
// callers: [msm_pcie_debug_info, msm_pcie_debugfs_case_select]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pcie_sel_debug_testcase(long param_1,undefined4 param_2)

{
  char *pcVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined *puVar12;
  undefined8 uVar13;
  ulong uVar14;
  int *piVar15;
  uint uVar16;
  uint uVar17;
  undefined4 *puVar18;
  
  switch(param_2) {
  case 0:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: Status for RC%d:\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012dbf0,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    msm_pcie_show_status(param_1);
    break;
  case 1:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: disable link\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_001284da,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    iVar3 = msm_pcie_pm_control(1,0,*(undefined8 *)(param_1 + 8));
    if (iVar3 == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe:%s:disabled link\n",
                       "msm_pcie_sel_debug_testcase","msm_pcie_sel_debug_testcase");
      }
      puVar12 = &DAT_00120b37;
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: PCIe:%s:failed to disable link\n","msm_pcie_sel_debug_testcase",
                       "msm_pcie_sel_debug_testcase");
      }
      puVar12 = &DAT_00121bf8;
    }
    goto LAB_00104238;
  case 2:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: enable link and recover config space\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_001213cb,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    goto LAB_00103a0c;
  case 3:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: disable and enable link then recover config space\n\n"
                     ,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00121c1e,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    iVar3 = msm_pcie_pm_control(1,0,*(undefined8 *)(param_1 + 8));
    puVar12 = &DAT_00120b37;
    if (iVar3 != 0) {
      puVar12 = &DAT_00121bf8;
    }
    if (param_1 != 0) {
      pcVar1 = "DBG_FS:%s: PCIe:%s:disabled link\n";
      if (iVar3 != 0) {
        pcVar1 = "DBG_FS:%s: PCIe:%s:failed to disable link\n";
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),pcVar1,"msm_pcie_sel_debug_testcase",
                     "msm_pcie_sel_debug_testcase");
    }
    _printk(puVar12,"msm_pcie_sel_debug_testcase","msm_pcie_sel_debug_testcase");
LAB_00103a0c:
    iVar3 = msm_pcie_pm_control(2,0,*(undefined8 *)(param_1 + 8));
    if (iVar3 != 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe:%s:failed to enable link\n"
                       ,"msm_pcie_sel_debug_testcase","msm_pcie_sel_debug_testcase");
      }
      puVar12 = &DAT_001245bc;
LAB_00104238:
      _printk(puVar12,"msm_pcie_sel_debug_testcase","msm_pcie_sel_debug_testcase");
    }
    break;
  case 4:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: disable L0s\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012b4cb,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(int *)(param_1 + 0x4b0) == 1) {
      msm_pcie_config_l0s_disable_all(param_1,*(undefined8 *)(*(long *)(param_1 + 8) + 0x10));
    }
    *(undefined1 *)(param_1 + 0x4d9) = 0;
    break;
  case 5:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: enable L0s\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012ac9f,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined1 *)(param_1 + 0x4d9) = 1;
    if (*(int *)(param_1 + 0x4b0) == 1) {
      msm_pcie_config_l0s_enable_all(param_1);
    }
    break;
  case 6:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: disable L1\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012d36b,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    mutex_lock(param_1 + 0x648);
    if (*(int *)(param_1 + 0x4b0) == 1) {
      msm_pcie_config_l1_disable_all(param_1,*(undefined8 *)(*(long *)(param_1 + 8) + 0x10));
    }
    *(undefined1 *)(param_1 + 0x4da) = 0;
    *(undefined1 *)(param_1 + 0x4d8) = 1;
    goto LAB_00103c04;
  case 7:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: enable L1\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_001256e6,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    mutex_lock(param_1 + 0x648);
    *(undefined1 *)(param_1 + 0x4da) = 1;
    *(undefined1 *)(param_1 + 0x4d8) = 1;
    if ((*(int *)(param_1 + 0x4b0) == 1) &&
       (msm_pcie_write_mask(*(long *)(param_1 + 0x380) + 0x20,0x20,0),
       *(char *)(param_1 + 0x4da) != '\0')) {
      pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1_enable,param_1)
      ;
    }
LAB_00103c04:
    mutex_unlock(param_1 + 0x648);
    break;
  case 8:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: disable L1ss\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00126c8c,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(int *)(param_1 + 0x4b0) == 1) {
      msm_pcie_config_l1ss_disable_all(param_1,*(undefined8 *)(*(long *)(param_1 + 8) + 0x10));
    }
    *(undefined1 *)(param_1 + 0x4df) = 0;
    *(undefined4 *)(param_1 + 0x4db) = 0;
    break;
  case 9:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: enable L1ss\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00125706,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined4 *)(param_1 + 0x4db) = 0x1010101;
    *(undefined1 *)(param_1 + 0x4df) = 1;
    if (*(int *)(param_1 + 0x4b0) == 1) {
      pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_check_l1ss_support,
                   param_1);
      msm_pcie_config_l1ss_enable_all(param_1);
    }
    break;
  case 10:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: attempting to enumerate RC%d\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012a31b,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(char *)(param_1 + 0x579) == '\0') {
      iVar3 = msm_pcie_enumerate(*(undefined4 *)(param_1 + 0x570));
      if (iVar3 == 0) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d is successfully enumerated\n",
                         "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
        }
        param_2 = *(undefined4 *)(param_1 + 0x570);
        puVar12 = &DAT_0012bc66;
      }
      else {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d enumeration failed\n","msm_pcie_sel_debug_testcase",
                         *(undefined4 *)(param_1 + 0x570));
        }
        param_2 = *(undefined4 *)(param_1 + 0x570);
        puVar12 = &DAT_00123cc9;
      }
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d is already enumerated\n","msm_pcie_sel_debug_testcase"
                       ,*(undefined4 *)(param_1 + 0x570));
      }
      param_2 = *(undefined4 *)(param_1 + 0x570);
      puVar12 = &DAT_0012e8ce;
    }
    goto LAB_001047d4;
  case 0xb:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: attempting to de enumerate RC%d\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_001245e1,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(char *)(param_1 + 0x579) == '\0') {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d is already de enumerated\n",
                       "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
      }
      param_2 = *(undefined4 *)(param_1 + 0x570);
      puVar12 = &DAT_0012948f;
    }
    else {
      msm_pcie_deenumerate(*(undefined4 *)(param_1 + 0x570));
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d is successfully de enumerated\n",
                       "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
      }
      param_2 = *(undefined4 *)(param_1 + 0x570);
      puVar12 = &DAT_0012e380;
    }
    goto LAB_001047d4;
  case 0xc:
    msm_pcie_access_reg(param_1,0);
    break;
  case 0xd:
    msm_pcie_access_reg(param_1,1);
    break;
  case 0xe:
    uVar17 = base_sel - 1;
    uVar14 = (ulong)uVar17;
    if ((uVar17 < 10) &&
       (piVar15 = *(int **)(param_1 + uVar14 * 0x18 + 0x168), piVar15 != (int *)0x0)) {
      if (base_sel == 1) {
        pcie_parf_dump(param_1);
        return;
      }
      if (base_sel == 2) {
        pcie_phy_dump(param_1);
        return;
      }
      if (base_sel == 6) {
        uVar16 = 0x1000;
      }
      else {
        iVar3 = piVar15[2] - *piVar15;
        uVar16 = 0x1000;
        if (iVar3 + 1U < 0x1000) {
          uVar16 = iVar3 + 1;
        }
        if (base_sel != 3) {
          uVar16 = iVar3 + 1;
        }
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: \n\nPCIe: Dumping %s Registers for RC%d\n\n",
                       "msm_pcie_sel_debug_testcase",
                       *(undefined8 *)(param_1 + (ulong)uVar17 * 0x18 + 0x160),
                       *(undefined4 *)(param_1 + 0x570));
        uVar14 = (ulong)(base_sel - 1U);
        if (9 < base_sel - 1U) {
LAB_0010485c:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104860);
          (*pcVar2)();
        }
      }
      _printk(&DAT_0012acc0,"msm_pcie_sel_debug_testcase",
              *(undefined8 *)(param_1 + uVar14 * 0x18 + 0x160),*(undefined4 *)(param_1 + 0x570));
      if (uVar16 == 0) {
        return;
      }
      uVar17 = 0;
      do {
        if (param_1 != 0) {
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar13 = *(undefined8 *)(param_1 + 0x730);
          uVar5 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)uVar17);
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar6 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)(uVar17 + 4));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar4 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)(uVar17 + 8));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar7 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)(uVar17 + 0xc));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar8 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)(uVar17 + 0x10));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar9 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                (long)(int)(uVar17 + 0x14));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar10 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                 (long)(int)(uVar17 + 0x18));
          if (9 < base_sel - 1U) goto LAB_0010485c;
          uVar11 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                                 (long)(int)(uVar17 + 0x1c));
          ipc_log_string(uVar13,"DBG_FS:%s: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                         "msm_pcie_sel_debug_testcase",uVar17,uVar5,uVar6,uVar4,uVar7,uVar8,uVar9,
                         uVar10,uVar11);
        }
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar5 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)uVar17);
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar6 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)(uVar17 + 4));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar4 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)(uVar17 + 8));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar7 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)(uVar17 + 0xc));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar8 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)(uVar17 + 0x10));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar9 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                              (long)(int)(uVar17 + 0x14));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar10 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                               (long)(int)(uVar17 + 0x18));
        if (9 < base_sel - 1U) goto LAB_0010485c;
        uVar11 = readl_relaxed(*(long *)(param_1 + (ulong)(base_sel - 1U) * 0x18 + 0x170) +
                               (long)(int)(uVar17 + 0x1c));
        _printk(&DAT_00129c37,"msm_pcie_sel_debug_testcase",uVar17,uVar5,uVar6,uVar4,uVar7,uVar8,
                uVar9,uVar10,uVar11);
        uVar17 = uVar17 + 0x20;
        if (uVar16 <= uVar17) {
          return;
        }
      } while( true );
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: PCIe: RC%d Resource does not exist\n","msm_pcie_sel_debug_testcase"
                     ,*(undefined4 *)(param_1 + 0x570));
    }
    param_2 = *(undefined4 *)(param_1 + 0x570);
    puVar12 = &DAT_00124646;
    goto LAB_001047d4;
  case 0xf:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: clear AER enable flag\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012acee,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined1 *)(param_1 + 0x4eb) = 0;
    break;
  case 0x10:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: set AER enable flag\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012ad1a,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined1 *)(param_1 + 0x4eb) = 1;
    break;
  case 0x11:
    if (param_1 == 0) {
      puVar18 = (undefined4 *)&DAT_00000570;
      _printk(&DAT_00125728,"msm_pcie_sel_debug_testcase",_DAT_00000570);
      uVar6 = _DAT_00000570;
      uVar5 = _DAT_000000e8;
      gpio_to_desc(_DAT_000000e8);
      uVar4 = gpiod_get_raw_value();
      _printk(&DAT_001203f8,"msm_pcie_sel_debug_testcase",uVar6,uVar5,uVar4);
    }
    else {
      puVar18 = (undefined4 *)(param_1 + 0x570);
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: PERST and WAKE status\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
      _printk(&DAT_00125728,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
      uVar5 = *(undefined4 *)(param_1 + 0xe8);
      uVar13 = *(undefined8 *)(param_1 + 0x730);
      uVar6 = *(undefined4 *)(param_1 + 0x570);
      gpio_to_desc(uVar5);
      uVar4 = gpiod_get_raw_value();
      ipc_log_string(uVar13,"DBG_FS:%s: PCIe: RC%d: PERST: gpio%u value: %d\n",
                     "msm_pcie_sel_debug_testcase",uVar6,uVar5,uVar4);
      uVar5 = *(undefined4 *)(param_1 + 0xe8);
      uVar6 = *(undefined4 *)(param_1 + 0x570);
      gpio_to_desc(uVar5);
      uVar4 = gpiod_get_raw_value();
      _printk(&DAT_001203f8,"msm_pcie_sel_debug_testcase",uVar6,uVar5,uVar4);
      uVar5 = *(undefined4 *)(param_1 + 0x108);
      uVar13 = *(undefined8 *)(param_1 + 0x730);
      uVar6 = *(undefined4 *)(param_1 + 0x570);
      gpio_to_desc(uVar5);
      uVar4 = gpiod_get_raw_value();
      ipc_log_string(uVar13,"DBG_FS:%s: PCIe: RC%d: WAKE: gpio%u value: %d\n",
                     "msm_pcie_sel_debug_testcase",uVar6,uVar5,uVar4);
    }
    uVar5 = *(undefined4 *)(param_1 + 0x108);
    uVar6 = *puVar18;
    gpio_to_desc(uVar5);
    uVar4 = gpiod_get_raw_value();
    _printk(&DAT_00125d95,"msm_pcie_sel_debug_testcase",uVar6,uVar5,uVar4);
    break;
  case 0x12:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: assert PERST\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00123d5a,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    uVar13 = 1;
    goto LAB_00103f3c;
  case 0x13:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: de-assert PERST\n\n","msm_pcie_sel_debug_testcase",
                     *(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00120423,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    uVar13 = 0;
LAB_00103f3c:
    msm_pcie_config_perst(param_1,uVar13);
    usleep_range_state(*(undefined4 *)(param_1 + 0x540),*(undefined4 *)(param_1 + 0x544),2);
    break;
  case 0x14:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: set keep resources on flag\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00124670,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    msm_pcie_keep_resources_on =
         msm_pcie_keep_resources_on | (uint)(1L << ((ulong)*(uint *)(param_1 + 0x570) & 0x3f));
    break;
  case 0x15:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: set target speed to Gen 1\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00120449,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined4 *)(param_1 + 0x4f4) = 1;
    break;
  case 0x16:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: set target speed to Gen 2\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00126416,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined4 *)(param_1 + 0x4f4) = 2;
    break;
  case 0x17:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: set target speed to Gen 3\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012a37d,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    *(undefined4 *)(param_1 + 0x4f4) = 3;
    break;
  case 0x18:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: \n\nPCIe: RC%d: Trigger SBR\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012efbe,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(int *)(param_1 + 0x4b0) == 1) {
      msm_pcie_write_mask(*(long *)(param_1 + 0x3a0) + 0x3c,0,0x400000);
      usleep_range_state(2000,0x7d1,2);
      msm_pcie_write_mask(*(long *)(param_1 + 0x3a0) + 0x3c,0x400000,0);
    }
    break;
  case 0x19:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: Move to remote loopback mode\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012c352,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(char *)(param_1 + 0x579) != '\0') {
      msm_pcie_config_l0s_disable_all(param_1,*(undefined8 *)(*(long *)(param_1 + 8) + 0x10));
      *(undefined1 *)(param_1 + 0x4d9) = 0;
      mutex_lock(param_1 + 0x648);
      msm_pcie_config_l1_disable_all(param_1,*(undefined8 *)(*(long *)(param_1 + 8) + 0x10));
      *(undefined1 *)(param_1 + 0x4da) = 0;
      *(undefined1 *)(param_1 + 0x4d8) = 1;
      mutex_unlock(param_1 + 0x648);
      msm_pcie_loopback(param_1,0);
      return;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: the link is not up yet\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    param_2 = *(undefined4 *)(param_1 + 0x570);
    puVar12 = &DAT_0012d38c;
    goto LAB_001047d4;
  case 0x1a:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: Move to local loopback mode\n\n",
                     "msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_00126446,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    if (*(char *)(param_1 + 0x579) == '\0') {
      msm_pcie_keep_resources_on =
           msm_pcie_keep_resources_on | (uint)(1L << ((ulong)*(uint *)(param_1 + 0x570) & 0x3f));
      msm_pcie_enable(param_1);
      msm_pcie_loopback(param_1,1);
      return;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: \n\nPCIe: RC%d: EP is already enumerated, use remote loopback mode\n\n"
                     ,"msm_pcie_sel_debug_testcase",*(undefined4 *)(param_1 + 0x570));
    }
    param_2 = *(undefined4 *)(param_1 + 0x570);
    puVar12 = &DAT_00127645;
    goto LAB_001047d4;
  default:
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: Invalid testcase: %d.\n",
                     "msm_pcie_sel_debug_testcase",param_2);
    }
    puVar12 = &DAT_0012e3b0;
LAB_001047d4:
    _printk(puVar12,"msm_pcie_sel_debug_testcase",param_2);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_clk_dump @ 00104864 size=256
// signature: undefined msm_pcie_clk_dump(void)
// callers: [msm_pcie_prevent_l1]
//------------------------------------------------------------

void msm_pcie_clk_dump(long param_1)

{
  uint uVar1;
  uint uVar2;
  long *plVar3;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"ERR:%s: PCIe: RC%d: Dump PCIe clocks\n",
                   "msm_pcie_clk_dump",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: Dump PCIe clocks\n",
                   "msm_pcie_clk_dump",*(undefined4 *)(param_1 + 0x570));
  }
  _printk(&DAT_00128c82,"msm_pcie_clk_dump",*(undefined4 *)(param_1 + 0x570));
  uVar1 = *(uint *)(param_1 + 0x370);
  if (uVar1 != 0) {
    uVar2 = 0;
    plVar3 = *(long **)(param_1 + 0x378);
    do {
      if (*plVar3 != 0) {
        qcom_clk_dump(*plVar3,0,0);
        uVar1 = *(uint *)(param_1 + 0x370);
      }
      uVar2 = uVar2 + 1;
      plVar3 = plVar3 + 3;
    } while (uVar2 < uVar1);
  }
  uVar1 = *(uint *)(param_1 + 0x360);
  if (uVar1 != 0) {
    uVar2 = 0;
    plVar3 = *(long **)(param_1 + 0x368);
    do {
      if (*plVar3 != 0) {
        qcom_clk_dump(*plVar3,0,0);
        uVar1 = *(uint *)(param_1 + 0x360);
      }
      uVar2 = uVar2 + 1;
      plVar3 = plVar3 + 3;
    } while (uVar2 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_ecam_rd_conf @ 00104968 size=44
// signature: undefined msm_pcie_ecam_rd_conf(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_ecam_rd_conf
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined8 param_5)

{
  msm_pcie_ecam_oper_conf(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// msm_pcie_ecam_wr_conf @ 00104998 size=96
// signature: undefined msm_pcie_ecam_wr_conf(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_ecam_wr_conf
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = param_5;
  msm_pcie_ecam_oper_conf(param_1,param_2,1,param_3,param_4,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_enumerate @ 001049fc size=1448
// signature: undefined msm_pcie_enumerate(void)
// callers: [enumerate_store, msm_pcie_probe, msm_pcie_sel_debug_testcase, handle_wake_func]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_pcie_enumerate(uint param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  uint uVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  long *plVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  undefined8 ****local_58;
  undefined8 ****ppppuStack_50;
  long local_48;
  
  lVar13 = sp_el0;
  local_48 = *(long *)(lVar13 + 0x638);
  if (4 < param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104fa0);
    (*pcVar2)();
  }
  plVar11 = (long *)(&msm_pcie_dev)[param_1];
  local_58 = &local_58;
  ppppuStack_50 = local_58;
  if (plVar11 == (long *)0x0) {
    _printk(&DAT_0012d1ab,param_1);
    uVar5 = 0xfffffdfb;
    goto LAB_00104e18;
  }
  mutex_lock(plVar11 + 0x8a);
  ipc_log_string(plVar11[0xe5],"DBG1:%s: Enumerate RC%d\n","msm_pcie_enumerate",param_1);
  ipc_log_string(plVar11[0xe4],"%s: Enumerate RC%d\n","msm_pcie_enumerate",param_1);
  *(undefined1 *)(plVar11 + 0x1b5) = 0;
  if ((char)plVar11[0xaf] == '\0') {
    ipc_log_string(plVar11[0xe5],"DBG1:%s: PCIe: RC%d: has not been successfully probed yet\n",
                   "msm_pcie_enumerate",param_1);
    ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: has not been successfully probed yet\n",
                   "msm_pcie_enumerate",param_1);
    uVar5 = 0xfffffdfb;
  }
  else if (*(char *)((long)plVar11 + 0x579) == '\0') {
    lVar13 = plVar11[0x1a4];
    uVar3 = msm_pcie_enable(plVar11);
    if (uVar3 == 0) {
      *(undefined1 *)(plVar11 + 0x88) = 1;
      uVar5 = readl_relaxed(plVar11[0x74]);
      uVar12 = uVar5 >> 0x10 & 0xffff;
      uVar3 = (uint)uVar5 & 0xffff;
      ipc_log_string(plVar11[0xe5],"DBG1:%s: PCIe: RC%d: vendor-id:0x%x device_id:0x%x\n",
                     "msm_pcie_enumerate",(int)plVar11[0xae],uVar3,uVar12);
      ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: vendor-id:0x%x device_id:0x%x\n",
                     "msm_pcie_enumerate",(int)plVar11[0xae],uVar3,uVar12);
      if ((char)plVar11[0xac] == '\0') {
        if (*(char *)((long)plVar11 + 0xda9) != '\0') {
          msm_msi_config_access(*(undefined8 *)(plVar11[1] + 0x350),1);
          goto LAB_00104b34;
        }
        uVar12 = msm_msi_init(*plVar11 + 0x10);
        uVar5 = uVar12 & 0xffffffff;
        if ((int)uVar12 != 0) goto LAB_00104e10;
        *(undefined1 *)((long)plVar11 + 0xda9) = 1;
        if (*(char *)((long)plVar11 + 0xdaa) == '\0') goto LAB_00104bf4;
LAB_00104b3c:
        plVar10 = (long *)(lVar13 + 0x3b8);
        do {
          plVar10 = (long *)*plVar10;
          if (plVar10 == (long *)(lVar13 + 0x3b8)) goto LAB_00104dc0;
        } while ((*(ulong *)(plVar10[2] + 0x18) & 0x1f00) != 0x1000);
        if (plVar10 == (long *)0x0) {
LAB_00104dc0:
          ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: Fetching bus resource failed\n",
                         "msm_pcie_enumerate",(int)plVar11[0xae]);
          ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: Fetching bus resource failed\n",
                         "msm_pcie_enumerate",(int)plVar11[0xae]);
          uVar1 = (undefined4)plVar11[0xae];
          puVar8 = &DAT_00129adc;
          goto LAB_00104e04;
        }
        uVar5 = pci_ecam_create(*plVar11 + 0x10,plVar11[0x33],plVar10[2],msm_pcie_ecam_ops);
        if (0xfffffffffffff000 < uVar5) {
          ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: ECAM creation failed\n",
                         "msm_pcie_enumerate",(int)plVar11[0xae]);
          ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: ECAM creation failed\n","msm_pcie_enumerate"
                         ,(int)plVar11[0xae]);
          uVar1 = (undefined4)plVar11[0xae];
          puVar8 = &DAT_0012e2f6;
          goto LAB_00104f3c;
        }
        puVar9 = msm_pcie_ecam_ops + 8;
        uVar12 = uVar5;
      }
      else {
LAB_00104b34:
        if (*(char *)((long)plVar11 + 0xdaa) != '\0') goto LAB_00104b3c;
LAB_00104bf4:
        uVar12 = kmalloc_trace(_pci_dev_put,0xdc0,0xe8);
        uVar5 = 0;
        if (uVar12 == 0) goto LAB_00104e10;
        puVar9 = msm_pcie_ops;
      }
      *(undefined1 **)(lVar13 + 0x398) = puVar9;
      *(long **)(uVar12 + 200) = plVar11;
      *(ulong *)(lVar13 + 0x3a8) = uVar12;
      uVar3 = pci_host_probe(lVar13);
      if (uVar3 == 0) {
        *(undefined1 *)((long)plVar11 + 0x579) = 1;
        if ((char)plVar11[0x111] != '\0') {
          queue_work_on(0x20,mpcie_wq,plVar11 + 0xff);
        }
        lVar13 = plVar11[0x74] + 4;
        uVar3 = readl_relaxed(lVar13);
        writel_relaxed(uVar3 | 6,lVar13);
        readl_relaxed(lVar13);
        uVar3 = *(uint *)(plVar11 + 0xa7);
        if ((uVar3 != 0) && ((char)plVar11[0xe0] != '\0')) {
          lVar13 = plVar11[0x74] + 0x98;
          uVar4 = readl_relaxed(lVar13);
          writel_relaxed(uVar4 & 0xfffffff0 | uVar3,lVar13);
          readl_relaxed(lVar13);
        }
        uVar6 = of_get_pci_domain_nr(*(undefined8 *)(*plVar11 + 0x2f8));
        if ((int)uVar6 < 0) {
          uVar5 = 0xffffffed;
        }
        else {
          lVar13 = pci_get_domain_bus_and_slot(uVar6,0,0);
          if (lVar13 == 0) {
            ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: Did not find PCI device.\n",
                           "msm_pcie_enumerate",(int)plVar11[0xae]);
            ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: Did not find PCI device.\n",
                           "msm_pcie_enumerate",(int)plVar11[0xae]);
            _printk(&DAT_0012442d,"msm_pcie_enumerate",(int)plVar11[0xae]);
            uVar5 = 0xffffffed;
          }
          else {
            plVar11[1] = lVar13;
            pci_walk_bus(*(undefined8 *)(lVar13 + 0x10),msm_pcie_config_device_info,plVar11);
            pci_walk_bus(*(undefined8 *)(plVar11[1] + 0x10),msm_pcie_check_l1ss_support,plVar11);
            msm_pcie_config_link_pm(plVar11);
            pci_save_state(lVar13);
            lVar7 = pci_store_saved_state(lVar13);
            plVar11[0x97] = lVar7;
            if (lVar7 != 0) {
              if ((*(byte *)(plVar11 + 0xab) & 1) != 0) {
                *(byte *)(lVar13 + 0x220) = *(byte *)(lVar13 + 0x220) | 2;
              }
              pci_dev_put(lVar13);
              goto LAB_00104e0c;
            }
            pci_dev_put(lVar13);
            uVar5 = 0xfffffff4;
            plVar11[1] = 0;
          }
        }
      }
      else {
        uVar5 = (ulong)uVar3;
        ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: pci_host_probe failed %d\n",
                       "msm_pcie_enumerate",(int)plVar11[0xae],uVar5);
        ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: pci_host_probe failed %d\n",
                       "msm_pcie_enumerate",(int)plVar11[0xae],uVar5);
        _printk(&DAT_0012f690,"msm_pcie_enumerate",(int)plVar11[0xae],uVar5);
      }
    }
    else {
      uVar5 = (ulong)uVar3;
      ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: failed to enable\n","msm_pcie_enumerate",
                     (int)plVar11[0xae]);
      ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: failed to enable\n","msm_pcie_enumerate",
                     (int)plVar11[0xae]);
      uVar1 = (undefined4)plVar11[0xae];
      puVar8 = &DAT_00126b8e;
LAB_00104f3c:
      _printk(puVar8,"msm_pcie_enumerate",uVar1);
    }
  }
  else {
    ipc_log_string(plVar11[0xe5],"ERR:%s: PCIe: RC%d: has already been enumerated.\n",
                   "msm_pcie_enumerate",(int)plVar11[0xae]);
    ipc_log_string(plVar11[0xe4],"%s: PCIe: RC%d: has already been enumerated.\n",
                   "msm_pcie_enumerate",(int)plVar11[0xae]);
    uVar1 = (undefined4)plVar11[0xae];
    puVar8 = &DAT_00123419;
LAB_00104e04:
    _printk(puVar8,"msm_pcie_enumerate",uVar1);
LAB_00104e0c:
    uVar5 = 0;
  }
LAB_00104e10:
  mutex_unlock(plVar11 + 0x8a);
LAB_00104e18:
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5 & 0xffffffff;
}



//------------------------------------------------------------
// msm_pcie_enable @ 00104fa4 size=2468
// signature: undefined msm_pcie_enable(void)
// callers: [msm_pcie_enumerate, msm_pcie_pm_resume, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

int msm_pcie_enable(undefined8 *param_1)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  code *pcVar7;
  int iVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  
  if (param_1 != (undefined8 *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: entry\n","msm_pcie_enable",
                   *(undefined4 *)(param_1 + 0xae));
    ipc_log_string(param_1[0xe4],"%s: RC%d: entry\n","msm_pcie_enable",
                   *(undefined4 *)(param_1 + 0xae));
  }
  puVar1 = param_1 + 0x90;
  *(undefined4 *)(param_1 + 0xcf) = 0;
  *(undefined1 *)(param_1 + 0x9b) = 0;
  mutex_lock(puVar1);
  if (*(int *)(param_1 + 0x96) == 1) {
    if (param_1 != (undefined8 *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: the link of RC%d is already enabled\n",
                     "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
      ipc_log_string(param_1[0xe4],"%s: PCIe: the link of RC%d is already enabled\n",
                     "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
    }
    _printk(&DAT_0012f946,"msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
    iVar2 = 0;
  }
  else {
    iVar2 = msm_pcie_vreg_init(param_1);
    if (iVar2 == 0) {
      if (param_1 != (undefined8 *)0x0) {
        ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: entry\n","msm_pcie_gdsc_init",
                       *(undefined4 *)(param_1 + 0xae));
        ipc_log_string(param_1[0xe4],"%s: RC%d: entry\n","msm_pcie_gdsc_init",
                       *(undefined4 *)(param_1 + 0xae));
      }
      if ((param_1[2] == 0) || (iVar2 = regulator_enable(), iVar2 == 0)) {
        if ((param_1[3] != 0) && (iVar2 = regulator_enable(), iVar2 != 0)) {
          if (param_1 != (undefined8 *)0x0) {
            ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: fail to enable GDSC-PHY for RC%d (%s)\n",
                           "msm_pcie_gdsc_init",*(undefined4 *)(param_1 + 0xae),
                           *(undefined8 *)*param_1);
            ipc_log_string(param_1[0xe4],"%s: PCIe: fail to enable GDSC-PHY for RC%d (%s)\n",
                           "msm_pcie_gdsc_init",*(undefined4 *)(param_1 + 0xae),
                           *(undefined8 *)*param_1);
          }
          puVar6 = (undefined8 *)*param_1;
          puVar4 = &DAT_00123f0a;
          goto LAB_00105494;
        }
        if (param_1 != (undefined8 *)0x0) {
          ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: exit\n","msm_pcie_gdsc_init",
                         *(undefined4 *)(param_1 + 0xae));
          ipc_log_string(param_1[0xe4],"%s: RC%d: exit\n","msm_pcie_gdsc_init",
                         *(undefined4 *)(param_1 + 0xae));
          ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: entry\n","msm_pcie_clk_init",
                         *(undefined4 *)(param_1 + 0xae));
          ipc_log_string(param_1[0xe4],"%s: RC%d: entry\n","msm_pcie_clk_init",
                         *(undefined4 *)(param_1 + 0xae));
        }
        if ((param_1[0x82] != 0) && (param_1[0x83] != 0)) {
          clk_set_parent();
        }
        iVar2 = msm_pcie_icc_vote(param_1,1,1,0);
        if (iVar2 == 0) {
          if (*(int *)(param_1 + 0x6e) != 0) {
            uVar3 = 0;
LAB_00105178:
            lVar11 = param_1[0x6f];
            plVar9 = (long *)(lVar11 + (long)(int)uVar3 * 0x18);
            if (*plVar9 == 0) goto LAB_00105168;
            if (*(int *)(lVar11 + (long)(int)uVar3 * 0x18 + 0x10) == 0) {
LAB_001051c0:
              lVar10 = *plVar9;
              iVar2 = clk_prepare(lVar10);
              if (iVar2 == 0) {
                iVar2 = clk_enable(lVar10);
                if (iVar2 == 0) {
                  if (param_1 != (undefined8 *)0x0) {
                    ipc_log_string(param_1[0xe4],"DBG2:%s: enable clk %s for RC%d.\n",
                                   "msm_pcie_clk_init",
                                   *(undefined8 *)(lVar11 + (long)(int)uVar3 * 0x18 + 8),
                                   *(undefined4 *)(param_1 + 0xae));
                  }
                  goto LAB_00105168;
                }
                clk_unprepare(lVar10);
              }
              if (param_1 != (undefined8 *)0x0) {
                lVar10 = lVar11 + (long)(int)uVar3 * 0x18;
                ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d failed to enable clk %s\n",
                               "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                               *(undefined8 *)(lVar10 + 8));
                ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d failed to enable clk %s\n",
                               "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                               *(undefined8 *)(lVar10 + 8));
              }
              _printk(&DAT_001265c2,"msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                      *(undefined8 *)(lVar11 + (long)(int)uVar3 * 0x18 + 8));
            }
            else {
              iVar2 = clk_set_rate();
              if (iVar2 == 0) {
                if (param_1 != (undefined8 *)0x0) {
                  ipc_log_string(param_1[0xe4],"DBG2:%s: PCIe: RC%d set rate for clk %s.\n",
                                 "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                                 *(undefined8 *)(lVar11 + (long)(int)uVar3 * 0x18 + 8));
                }
                goto LAB_001051c0;
              }
              if (param_1 != (undefined8 *)0x0) {
                lVar10 = lVar11 + (long)(int)uVar3 * 0x18;
                ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d can\'t set rate for clk %s: %d.\n",
                               "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                               *(undefined8 *)(lVar10 + 8),iVar2);
                ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d can\'t set rate for clk %s: %d.\n",
                               "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                               *(undefined8 *)(lVar10 + 8),iVar2);
              }
              _printk(&DAT_0012a5f1,"msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae),
                      *(undefined8 *)(lVar11 + (long)(int)uVar3 * 0x18 + 8),iVar2);
            }
            if (param_1 != (undefined8 *)0x0) {
              ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d disable clocks for error handling.\n",
                             "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae));
              ipc_log_string(param_1[0xe4],"%s: RC%d disable clocks for error handling.\n",
                             "msm_pcie_clk_init",*(undefined4 *)(param_1 + 0xae));
            }
            if (uVar3 != 0) {
              iVar8 = uVar3 - 1;
              do {
                lVar11 = *(long *)(param_1[0x6f] + (long)iVar8 * 0x18);
                if (lVar11 != 0) {
                  clk_disable(lVar11);
                  clk_unprepare(lVar11);
                }
                iVar8 = iVar8 + -1;
              } while (iVar8 != -1);
            }
            if ((param_1[0x82] != 0) && (param_1[0x86] != 0)) {
              clk_set_parent();
            }
            goto LAB_00105204;
          }
LAB_00105200:
          iVar2 = 0;
LAB_00105204:
          if (param_1 != (undefined8 *)0x0) {
            ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: exit\n","msm_pcie_clk_init",
                           *(undefined4 *)(param_1 + 0xae));
            ipc_log_string(param_1[0xe4],"%s: RC%d: exit\n","msm_pcie_clk_init",
                           *(undefined4 *)(param_1 + 0xae));
          }
          DataSynchronizationBarrier(3,2,0);
          if (iVar2 == 0) {
            if (param_1[0x1a0] == 0) {
LAB_00105278:
              uVar3 = readl_relaxed(param_1[0x70] + 0x24);
              if ((uVar3 >> 0x1e & 1) == 0) {
                if (param_1 != (undefined8 *)0x0) {
                  ipc_log_string(param_1[0xe5],
                                 "INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n",
                                 "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
                  ipc_log_string(param_1[0xe4],"%s: PCIe: Assert the reset of endpoint of RC%d.\n",
                                 "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
                }
                _printk(&DAT_0012f140,"msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
                msm_pcie_config_perst(param_1,1);
                usleep_range_state(*(undefined4 *)(param_1 + 0xa8),
                                   *(undefined4 *)((long)param_1 + 0x544),2);
                iVar2 = msm_pcie_gpio_init(param_1);
                if (iVar2 == 0) {
                  iVar2 = msm_pcie_core_phy_reset(param_1);
                  DataSynchronizationBarrier(3,2,0);
                  if (iVar2 == 0) {
                    pcVar7 = (code *)param_1[0x197];
                    if (pcVar7 != (code *)0x0) {
                      if (*(int *)(pcVar7 + -4) != -0x506c57f8) {
                    /* WARNING: Does not return */
                        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1055ec);
                        (*pcVar7)();
                      }
                      (*pcVar7)(param_1);
                    }
                    iVar2 = msm_pcie_enable_link(param_1);
                    if (iVar2 == 0) goto LAB_00105600;
                    goto LAB_00105640;
                  }
LAB_001056a8:
                  msm_pcie_gpio_deinit(param_1);
                }
              }
              else {
                uVar3 = readl_relaxed(param_1[0x74] + 0x80);
                *(uint *)((long)param_1 + 0x4fc) = uVar3 >> 0x10 & 0xf;
                *(uint *)((long)param_1 + 0x504) = uVar3 >> 0x14 & 0x3f;
                if (param_1 != (undefined8 *)0x0) {
                  ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: Link is up at Gen%dX%d\n",
                                 "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae));
                  ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: Link is up at Gen%dX%d\n",
                                 "msm_pcie_enable",*(undefined4 *)(param_1 + 0xae),
                                 *(undefined4 *)((long)param_1 + 0x4fc),
                                 *(undefined4 *)((long)param_1 + 0x504));
                }
                iVar2 = msm_pcie_pipe_clk_init(param_1);
                DataSynchronizationBarrier(3,2,0);
                if (iVar2 == 0) {
LAB_00105600:
                  if (*(int *)(param_1 + 0xad) != 0) {
                    msm_pcie_parf_cesta_config(param_1);
                  }
                  if (param_1[0x1b6] == 0) {
                    iVar2 = msm_pcie_save_sid_config(param_1);
                    if (iVar2 != 0) {
                      param_1[0x1b6] = 0;
                      goto LAB_00105640;
                    }
                  }
                  else {
                    iVar2 = msm_pcie_restore_sid_config(param_1);
                    if (iVar2 != 0) {
LAB_00105640:
                      if ((msm_pcie_keep_resources_on >> ((ulong)*(uint *)(param_1 + 0xae) & 0x3f) &
                          1) != 0) goto LAB_00105314;
                      if (*(int *)(param_1 + 0x25) != 0) {
                        iVar8 = *(int *)(param_1 + 0x26);
                        uVar5 = gpio_to_desc();
                        gpiod_set_raw_value(uVar5,1 - iVar8);
                      }
                      if (*(uint *)(param_1 + 0xa4) != 0) {
                        lVar11 = param_1[0x71] + (ulong)*(uint *)(param_1 + 0xa4);
                        writel_relaxed(0,lVar11);
                        readl_relaxed(lVar11);
                      }
                      msm_pcie_disable_cesta(param_1);
                      msm_pcie_pipe_clk_deinit(param_1);
                      goto LAB_001056a8;
                    }
                  }
                  if (*(char *)(param_1 + 0x1a5) != '\0') {
                    msm_pcie_icc_vote(param_1,*(undefined4 *)((long)param_1 + 0x4fc),
                                      *(undefined4 *)((long)param_1 + 0x504),0);
                  }
                  *(undefined1 *)(param_1 + 0xd4) = 0;
                  *(undefined4 *)(param_1 + 0x96) = 1;
                  *(undefined1 *)((long)param_1 + 0x71c) = 1;
                  param_1[0xd1] = param_1[0xd1] + 1;
                  if (*(char *)((long)param_1 + 0x579) != '\0') {
                    if (*(char *)(param_1 + 0xac) == '\0') {
                      msm_msi_config(*(undefined8 *)(param_1[1] + 0x350));
                    }
                    msm_pcie_config_link_pm(param_1);
                  }
                  if ((param_1[0x1a6] != 0) &&
                     (pcVar7 = (code *)param_1[0x1b2], pcVar7 != (code *)0x0)) {
                    if (*(int *)(pcVar7 + -4) != 0xe5d4f91) {
                    /* WARNING: Does not return */
                      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x105740);
                      (*pcVar7)();
                    }
                    (*pcVar7)(param_1 + 0x1a6,0);
                    if (param_1 == (undefined8 *)0x0) {
                      msleep(200);
                      mutex_unlock(0x480);
                      return 0;
                    }
                    ipc_log_string(param_1[0xe5],
                                   "DBG1:%s: PCIe: Bring EPs out of reset and then wait for link training.\n"
                                   ,"msm_pcie_enable");
                    ipc_log_string(param_1[0xe4],
                                   "%s: PCIe: Bring EPs out of reset and then wait for link training.\n"
                                   ,"msm_pcie_enable");
                    msleep(200);
                    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: Finish EPs link training wait.\n",
                                   "msm_pcie_enable");
                    ipc_log_string(param_1[0xe4],"%s: PCIe: Finish EPs link training wait.\n",
                                   "msm_pcie_enable");
                    mutex_unlock(puVar1);
                    iVar2 = 0;
                    goto LAB_00105320;
                  }
                  iVar2 = 0;
                  goto LAB_00105314;
                }
              }
            }
            else {
              msm_pcie_cesta_map._8_4_ = *(int *)(param_1 + 0x80) + 1;
              msm_pcie_cesta_map._12_4_ = msm_pcie_cesta_map._8_4_;
              msm_pcie_cesta_map._20_4_ = msm_pcie_cesta_map._8_4_;
              iVar2 = msm_pcie_cesta_map_apply(param_1,1);
              if (iVar2 == 0) goto LAB_00105278;
              if (param_1 != (undefined8 *)0x0) {
                ipc_log_string(param_1[0xe5],"ERR:%s: Fail to go to D0 State %d\n",
                               "msm_pcie_enable_cesta",iVar2);
                ipc_log_string(param_1[0xe4],"%s: Fail to go to D0 State %d\n",
                               "msm_pcie_enable_cesta",iVar2);
              }
              _printk(&DAT_00128f67,"msm_pcie_enable_cesta",iVar2);
            }
            msm_pcie_clk_deinit(param_1);
          }
        }
        else {
          DataSynchronizationBarrier(3,2,0);
        }
        msm_pcie_gdsc_deinit(param_1);
      }
      else {
        if (param_1 != (undefined8 *)0x0) {
          ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
                         "msm_pcie_gdsc_init",*(undefined4 *)(param_1 + 0xae),
                         *(undefined8 *)*param_1);
          ipc_log_string(param_1[0xe4],"%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
                         "msm_pcie_gdsc_init",*(undefined4 *)(param_1 + 0xae),
                         *(undefined8 *)*param_1);
        }
        puVar6 = (undefined8 *)*param_1;
        puVar4 = &DAT_0012dccf;
LAB_00105494:
        _printk(puVar4,"msm_pcie_gdsc_init",*(undefined4 *)(param_1 + 0xae),*puVar6);
      }
      msm_pcie_vreg_deinit(param_1);
    }
  }
LAB_00105314:
  mutex_unlock(puVar1);
  if (param_1 == (undefined8 *)0x0) {
    return iVar2;
  }
LAB_00105320:
  ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: exit\n","msm_pcie_enable",
                 *(undefined4 *)(param_1 + 0xae));
  ipc_log_string(param_1[0xe4],"%s: RC%d: exit\n","msm_pcie_enable",*(undefined4 *)(param_1 + 0xae))
  ;
  return iVar2;
LAB_00105168:
  uVar3 = uVar3 + 1;
  if (*(uint *)(param_1 + 0x6e) <= uVar3) goto LAB_00105200;
  goto LAB_00105178;
}



//------------------------------------------------------------
// msm_pcie_write_mask @ 00105948 size=80
// signature: undefined msm_pcie_write_mask(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_write_mask(undefined8 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = readl_relaxed();
  writel_relaxed(uVar1 & (param_2 ^ 0xffffffff) | param_3,param_1);
  readl_relaxed(param_1);
  return;
}



//------------------------------------------------------------
// msm_pcie_config_device_info @ 0010599c size=580
// signature: undefined msm_pcie_config_device_info(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_pcie_config_device_info(long param_1,long param_2)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  if (param_2 != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                   "DBG1:%s: PCI device found: vendor-id:0x%x device-id:0x%x\n",
                   "msm_pcie_config_device_info",*(undefined2 *)(param_1 + 0x3c),
                   *(undefined2 *)(param_1 + 0x3e));
    ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                   "%s: PCI device found: vendor-id:0x%x device-id:0x%x\n",
                   "msm_pcie_config_device_info",*(undefined2 *)(param_1 + 0x3c),
                   *(undefined2 *)(param_1 + 0x3e));
  }
  if ((*(ushort *)(param_1 + 0x72) & 0xf0) == 0) {
    plVar2 = (long *)kmalloc_trace(_pci_save_state,0xdc0,0x18);
    if (plVar2 == (long *)0x0) {
      return -0xc;
    }
    puVar4 = *(undefined8 **)(param_2 + 0x6b8);
    plVar2[2] = param_1;
    uVar3 = __list_add_valid(plVar2,puVar4,param_2 + 0x6b0);
    if ((uVar3 & 1) != 0) {
      *(long **)(param_2 + 0x6b8) = plVar2;
      *plVar2 = param_2 + 0x6b0;
      plVar2[1] = (long)puVar4;
      *puVar4 = plVar2;
    }
  }
  if ((*(ushort *)(param_1 + 0x72) & 0xf0) == 0x50) {
    iVar1 = pci_enable_device(param_1);
    if (iVar1 != 0) {
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "ERR:%s: PCIe: BDF 0x%04x pci_enable_device failed\n",
                       "msm_pcie_config_device_info",
                       *(uint *)(param_1 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_1 + 0x10) + 0xf8) << 8);
        ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                       "%s: PCIe: BDF 0x%04x pci_enable_device failed\n",
                       "msm_pcie_config_device_info",
                       *(uint *)(param_1 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_1 + 0x10) + 0xf8) << 8);
      }
      _printk(&DAT_00129f42,"msm_pcie_config_device_info",
              *(uint *)(param_1 + 0x38) | (uint)*(byte *)(*(long *)(param_1 + 0x10) + 0xf8) << 8);
      return iVar1;
    }
    pci_set_master(param_1);
  }
  if (*(char *)(param_2 + 0x4eb) != '\0') {
    if ((*(ushort *)(param_1 + 0x72) & 0xf0) == 0x40) {
      *(undefined8 *)(param_2 + 0xcb0) = *(undefined8 *)(param_1 + 0x50);
    }
    iVar1 = pci_enable_pcie_error_reporting(param_1);
    if (iVar1 != 0) {
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "ERR:%s: PCIe: RC%d: PCIE error reporting unavailable on %02x:%02x:%01x\n",
                       "msm_pcie_config_device_info",*(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                       "%s: PCIe: RC%d: PCIE error reporting unavailable on %02x:%02x:%01x\n",
                       "msm_pcie_config_device_info",*(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      }
      _printk(&DAT_00122ffc,"msm_pcie_config_device_info",*(undefined4 *)(param_2 + 0x570),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    }
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_link_pm @ 00105be0 size=252
// signature: undefined msm_pcie_config_link_pm(void)
// callers: [msm_pcie_enable, msm_pcie_enumerate]
//------------------------------------------------------------

void msm_pcie_config_link_pm(long param_1)

{
  if (*(char *)(param_1 + 0x4e8) != '\0') {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_common_clock_enable,
                 param_1);
  }
  if (*(char *)(param_1 + 0x4e9) != '\0') {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),
                 msm_pcie_config_clock_power_management_enable,param_1);
  }
  if (*(char *)(param_1 + 0x4db) != '\0') {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1_2_threshold,
                 param_1);
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1ss_enable,param_1)
    ;
  }
  if (*(char *)(param_1 + 0x4da) != '\0') {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1_enable,param_1);
  }
  if ((*(char *)(param_1 + 0x4d9) != '\0') &&
     (pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_check_l0s_support,param_1
                  ), *(char *)(param_1 + 0x4d9) != '\0')) {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l0s_enable,param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_deenumerate @ 00105ce0 size=504
// signature: undefined msm_pcie_deenumerate(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

undefined8 msm_pcie_deenumerate(uint param_1)

{
  long lVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  undefined1 *puVar7;
  
  if (4 < param_1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105ed8);
    (*pcVar3)();
  }
  lVar5 = (&msm_pcie_dev)[param_1];
  lVar1 = lVar5 + 0x450;
  lVar6 = *(long *)(lVar5 + 0xd20);
  mutex_lock(lVar1);
  if (lVar5 == 0) {
    if (DAT_00000579 == '\0') goto LAB_00105e6c;
    puVar7 = &DAT_00000579;
    if (DAT_00000758 == '\0') goto LAB_00105dc4;
  }
  else {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x728),"DBG1:%s: RC%d: Entry\n","msm_pcie_deenumerate",
                   *(undefined4 *)(lVar5 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: RC%d: Entry\n","msm_pcie_deenumerate",
                   *(undefined4 *)(lVar5 + 0x570));
    if (*(char *)(lVar5 + 0x579) == '\0') {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x728),"DBG1:%s: RC%d:device is not enumerated\n",
                     "msm_pcie_deenumerate",*(undefined4 *)(lVar5 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: RC%d:device is not enumerated\n",
                     "msm_pcie_deenumerate",*(undefined4 *)(lVar5 + 0x570));
LAB_00105e6c:
      mutex_unlock(lVar1);
      return 0;
    }
    puVar7 = (undefined1 *)(lVar5 + 0x579);
    if (*(char *)(lVar5 + 0x758) == '\0') goto LAB_00105dc4;
    ipc_log_string(*(undefined8 *)(lVar5 + 0x728),"DBG1:%s: RC%d: cancel link_recover_wq\n",
                   "msm_pcie_deenumerate",*(undefined4 *)(lVar5 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: RC%d: cancel link_recover_wq\n",
                   "msm_pcie_deenumerate",*(undefined4 *)(lVar5 + 0x570));
  }
  cancel_work_sync(lVar5 + 0x760);
LAB_00105dc4:
  uVar4 = _raw_spin_lock_irqsave(lVar5 + 0x444);
  *(undefined8 *)(lVar5 + 0x448) = uVar4;
  *(undefined1 *)(lVar5 + 0x440) = 0;
  _raw_spin_unlock_irqrestore(lVar5 + 0x444,uVar4);
  pci_stop_root_bus(*(undefined8 *)(lVar6 + 0x390));
  pci_remove_root_bus(*(undefined8 *)(lVar6 + 0x390));
  lVar2 = *(long *)(lVar5 + 0x380) + 0x22c;
  writel_relaxed(0,lVar2);
  readl_relaxed(lVar2);
  msm_pcie_disable(lVar5);
  *puVar7 = 0;
  mutex_unlock(lVar1);
  if (*(char *)(lVar5 + 0xdaa) == '\0') {
    kfree(*(undefined8 *)(lVar6 + 0x3a8));
  }
  else {
    pci_ecam_free();
  }
  if (lVar5 != 0) {
    ipc_log_string(*(undefined8 *)(lVar5 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_deenumerate",
                   *(undefined4 *)(lVar5 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: RC%d: exit\n","msm_pcie_deenumerate",
                   *(undefined4 *)(lVar5 + 0x570));
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_disable @ 00105ed8 size=780
// signature: undefined msm_pcie_disable(void)
// callers: [msm_pcie_deenumerate, msm_pcie_pm_suspend, msm_pcie_disable_resource]
//------------------------------------------------------------

void msm_pcie_disable(long param_1)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  undefined8 uVar5;
  code *pcVar6;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_disable",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_disable",
                   *(undefined4 *)(param_1 + 0x570));
  }
  lVar1 = param_1 + 0x480;
  mutex_lock(lVar1);
  if (*(char *)(param_1 + 0x71c) == '\0') {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: the link of RC%d is already power down.\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: the link of RC%d is already power down.\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
    }
    mutex_unlock(lVar1);
  }
  else {
    if (*(char *)(param_1 + 0x560) == '\0') {
      msm_msi_config_access(*(undefined8 *)(*(long *)(param_1 + 8) + 0x350),0);
    }
    *(undefined1 *)(param_1 + 0x71c) = 0;
    *(undefined4 *)(param_1 + 0x4b0) = 2;
    *(long *)(param_1 + 0x690) = *(long *)(param_1 + 0x690) + 1;
    if ((*(long *)(param_1 + 0xd30) != 0) &&
       (pcVar6 = *(code **)(param_1 + 0xd90), pcVar6 != (code *)0x0)) {
      if (*(int *)(pcVar6 + -4) != 0xe5d4f91) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x105ff8);
        (*pcVar6)();
      }
      (*pcVar6)(param_1 + 0xd30,1);
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: Assert the reset of endpoint of RC%d.\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012f140,"msm_pcie_disable",*(undefined4 *)(param_1 + 0x570));
    msm_pcie_config_perst(param_1,1);
    if (*(uint *)(param_1 + 0x520) != 0) {
      lVar2 = *(long *)(param_1 + 0x388) + (ulong)*(uint *)(param_1 + 0x520);
      writel_relaxed(0,lVar2);
      readl_relaxed(lVar2);
    }
    lVar2 = *(long *)(param_1 + 0x380) + 0x40;
    uVar3 = readl_relaxed(lVar2);
    writel_relaxed(uVar3 | 1,lVar2);
    readl_relaxed(lVar2);
    lVar2 = *(long *)(param_1 + 0x380) + 0x2c4;
    uVar3 = readl_relaxed(lVar2);
    writel_relaxed(uVar3 | 1,lVar2);
    readl_relaxed(lVar2);
    msm_pcie_pipe_reset(param_1);
    DataSynchronizationBarrier(3,2,0);
    msm_pcie_core_phy_reset(param_1);
    DataSynchronizationBarrier(3,2,0);
    if ((*(long *)(param_1 + 0xd00) != 0) &&
       (iVar4 = msm_pcie_cesta_map_apply(param_1,0), iVar4 != 0)) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: Failed to move to D3 cold state %d\n","msm_pcie_disable",iVar4);
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: Failed to move to D3 cold state %d\n",
                       "msm_pcie_disable",iVar4);
      }
      _printk(&DAT_0012ddeb,"msm_pcie_disable",iVar4);
    }
    msm_pcie_clk_deinit(param_1);
    msm_pcie_gdsc_deinit(param_1);
    msm_pcie_vreg_deinit(param_1);
    msm_pcie_pipe_clk_deinit(param_1);
    if (*(int *)(param_1 + 0x128) != 0) {
      iVar4 = *(int *)(param_1 + 0x130);
      uVar5 = gpio_to_desc();
      gpiod_set_raw_value(uVar5,1 - iVar4);
    }
    msm_pcie_gpio_deinit(param_1);
    mutex_unlock(lVar1);
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_disable",
                     *(undefined4 *)(param_1 + 0x570));
    }
  }
  return;
}



//------------------------------------------------------------
// msm_aer_print_error @ 001061e8 size=1388
// signature: undefined msm_aer_print_error(void)
// callers: [msm_aer_process_err_devices]
//------------------------------------------------------------

void msm_aer_print_error(long param_1,long *param_2)

{
  uint uVar1;
  ushort uVar2;
  undefined **ppuVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  byte bVar8;
  ulong uVar9;
  code *pcVar10;
  bool bVar11;
  int iVar12;
  ulong uVar13;
  long lVar14;
  ulong uVar15;
  uint uVar16;
  long lVar17;
  long lVar18;
  undefined *puVar19;
  undefined *puVar20;
  ulong local_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  uVar6 = *(uint *)(param_2 + 7);
  uVar7 = *(uint *)(param_1 + 0x38);
  bVar8 = *(byte *)(*(long *)(param_1 + 0x10) + 0xf8);
  if (uVar6 == 0) {
    lVar14 = *param_2;
    if (lVar14 != 0) {
      uVar13 = (ulong)*(ushort *)((long)param_2 + 0x36) & 3;
      if ((int)uVar13 != 3) {
        ipc_log_string(*(undefined8 *)(lVar14 + 0x728),
                       "DBG1:%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=Inaccessible, (Unregistered Agent ID)\n"
                       ,"msm_aer_print_error",*(undefined4 *)(lVar14 + 0x570),
                       (&aer_error_severity_string)[uVar13]);
        uVar13 = (ulong)*(ushort *)((long)param_2 + 0x36) & 3;
        if ((int)uVar13 != 3) {
          ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                         "%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=Inaccessible, (Unregistered Agent ID)\n"
                         ,"msm_aer_print_error",*(undefined4 *)(*param_2 + 0x570),
                         (&aer_error_severity_string)[uVar13]);
          goto LAB_001066b0;
        }
      }
      goto LAB_0010674c;
    }
    goto LAB_001066b0;
  }
  uVar1 = *(uint *)((long)param_2 + 0x34) & 0x30000;
  bVar11 = uVar1 == 0x20000;
  uVar16 = 0x10;
  if (bVar11) {
    uVar16 = 0x11c0;
  }
  lVar14 = 1;
  if ((uVar16 & uVar6) == 0) {
    lVar14 = 2;
  }
  if (bVar11 && (uVar6 & 1) != 0) {
    lVar14 = 0;
  }
  if ((uVar6 & (uint)!bVar11 << 0xf) == 0) {
    uVar16 = 0;
    if (uVar1 != 0x20000) {
      uVar16 = 0x104000;
    }
    if ((uVar16 & uVar6) == 0) {
      uVar16 = 0x1100;
      if (uVar1 != 0x20000) {
        uVar16 = 0;
      }
      lVar17 = 0;
      if ((uVar16 & uVar6) != 0) {
        lVar17 = 3;
      }
      lVar18 = *param_2;
    }
    else {
      lVar17 = 1;
      lVar18 = *param_2;
    }
  }
  else {
    lVar17 = 2;
    lVar18 = *param_2;
  }
  if (lVar18 != 0) {
    uVar13 = (ulong)(*(uint *)((long)param_2 + 0x34) >> 0x10) & 3;
    if ((int)uVar13 == 3) {
LAB_0010674c:
                    /* WARNING: Does not return */
      pcVar10 = (code *)SoftwareBreakpoint(0x5512,0x106750);
      (*pcVar10)();
    }
    puVar19 = (&aer_error_layer)[lVar14];
    puVar20 = (&aer_agent_string)[lVar17];
    ipc_log_string(*(undefined8 *)(lVar18 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=%s, (%s)\n",
                   "msm_aer_print_error",*(undefined4 *)(lVar18 + 0x570),
                   (&aer_error_severity_string)[uVar13],puVar19,puVar20);
    uVar13 = (ulong)*(ushort *)((long)param_2 + 0x36) & 3;
    if ((int)uVar13 == 3) goto LAB_0010674c;
    ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                   "%s: PCIe: RC%d: PCIe Bus Error: severity=%s, type=%s, (%s)\n",
                   "msm_aer_print_error",*(undefined4 *)(*param_2 + 0x570),
                   (&aer_error_severity_string)[uVar13],puVar19,puVar20);
    lVar14 = *param_2;
    if (lVar14 != 0) {
      ipc_log_string(*(undefined8 *)(lVar14 + 0x728),
                     "DBG1:%s: PCIe: RC%d: device [%04x:%04x] error status/mask=%08x/%08x\n",
                     "msm_aer_print_error",*(undefined4 *)(lVar14 + 0x570),
                     *(undefined2 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x3e),(int)param_2[7]
                     ,*(undefined4 *)((long)param_2 + 0x3c));
      ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                     "%s: PCIe: RC%d: device [%04x:%04x] error status/mask=%08x/%08x\n",
                     "msm_aer_print_error",*(undefined4 *)(*param_2 + 0x570),
                     *(undefined2 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x3e),(int)param_2[7]
                     ,*(undefined4 *)((long)param_2 + 0x3c));
      lVar14 = *param_2;
      if (lVar14 != 0) {
        ipc_log_string(*(undefined8 *)(lVar14 + 0x728),
                       "DBG1:%s: PCIe: RC%d: device [%04x:%04x] error l1ss_ctl1=%x lnkstat=%x\n",
                       "msm_aer_print_error",*(undefined4 *)(lVar14 + 0x570),
                       *(undefined2 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x3e),
                       (int)param_2[10],*(undefined2 *)((long)param_2 + 0x54));
        ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                       "%s: PCIe: RC%d: device [%04x:%04x] error l1ss_ctl1=%x lnkstat=%x\n",
                       "msm_aer_print_error",*(undefined4 *)(*param_2 + 0x570),
                       *(undefined2 *)(param_1 + 0x3c),*(undefined2 *)(param_1 + 0x3e),
                       (int)param_2[10],*(undefined2 *)((long)param_2 + 0x54));
      }
    }
  }
  uVar6 = *(uint *)(param_2 + 7);
  uVar1 = *(uint *)((long)param_2 + 0x3c);
  uVar13 = 0;
  ppuVar3 = &aer_correctable_error_string;
  if ((*(uint *)((long)param_2 + 0x34) & 0x30000) != 0x20000) {
    ppuVar3 = &aer_uncorrectable_error_string;
  }
  do {
    uVar13 = -1L << (uVar13 & 0x3f) & (ulong)(uVar6 & (uVar1 ^ 0xffffffff));
    uVar15 = (uVar13 & 0xaaaaaaaaaaaaaaaa) >> 1 | (uVar13 & 0x5555555555555555) << 1;
    uVar15 = (uVar15 & 0xcccccccccccccccc) >> 2 | (uVar15 & 0x3333333333333333) << 2;
    uVar15 = (uVar15 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar15 & 0xf0f0f0f0f0f0f0f) << 4;
    uVar9 = (uVar15 & 0xff00ff00ff00ff00) >> 8 | (uVar15 & 0xff00ff00ff00ff) << 8;
    uVar15 = 0x20;
    if (uVar13 != 0) {
      uVar15 = LZCOUNT((uVar9 >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10) << 0x20);
    }
    uVar16 = (uint)uVar15;
    if (0x1f < uVar16) break;
    lVar14 = *param_2;
    if (lVar14 != 0) {
      if (0x1f < uVar15) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(1,0x10659c);
        (*pcVar10)();
      }
      pcVar4 = "Unknown Error Bit";
      if (ppuVar3[uVar15] != (char *)0x0) {
        pcVar4 = ppuVar3[uVar15];
      }
      pcVar5 = " (First)";
      if ((*(byte *)((long)param_2 + 0x37) & 0x1f) != uVar16) {
        pcVar5 = "";
      }
      ipc_log_string(*(undefined8 *)(lVar14 + 0x728),"DBG1:%s: PCIe: RC%d: [%2d] %-22s%s\n",
                     "msm_aer_print_error_stats",*(undefined4 *)(lVar14 + 0x570),uVar15,pcVar4,
                     pcVar5);
      pcVar5 = " (First)";
      if ((*(byte *)((long)param_2 + 0x37) & 0x1f) != uVar16) {
        pcVar5 = "";
      }
      ipc_log_string(*(undefined8 *)(*param_2 + 0x720),"%s: PCIe: RC%d: [%2d] %-22s%s\n",
                     "msm_aer_print_error_stats",*(undefined4 *)(*param_2 + 0x570),uVar15,pcVar4,
                     pcVar5);
    }
    uVar13 = uVar15 + 1;
  } while (uVar15 < 0x1f);
  local_70 = (ulong)(*(uint *)(param_2 + 7) & (*(uint *)((long)param_2 + 0x3c) ^ 0xffffffff));
  lVar14 = *(long *)(param_1 + 0x50);
  if (lVar14 != 0) {
    uVar2 = *(ushort *)((long)param_2 + 0x36) & 3;
    if ((*(ushort *)((long)param_2 + 0x36) & 3) == 0) {
      *(long *)(lVar14 + 0x240) = *(long *)(lVar14 + 0x240) + 1;
      lVar14 = lVar14 + 0x158;
LAB_0010660c:
      iVar12 = 0x1b;
    }
    else {
      if (uVar2 == 1) {
        *(long *)(lVar14 + 0x238) = *(long *)(lVar14 + 0x238) + 1;
        lVar14 = lVar14 + 0x80;
        goto LAB_0010660c;
      }
      if (uVar2 == 2) {
        iVar12 = 0x10;
        *(long *)(lVar14 + 0x230) = *(long *)(lVar14 + 0x230) + 1;
      }
      else {
        lVar14 = 0;
        iVar12 = -1;
      }
    }
    lVar17 = 0;
    while (uVar13 = _find_next_bit(&local_70,(long)iVar12,(long)(int)lVar17), (int)uVar13 < iVar12)
    {
      uVar15 = -(uVar13 >> 0x1f & 1) & 0xfffffff800000000 | (uVar13 & 0xffffffff) << 3;
      lVar17 = uVar13 + 1;
      *(long *)(lVar14 + uVar15) = *(long *)(lVar14 + uVar15) + 1;
    }
  }
  if ((*(int *)((long)param_2 + 0x34) < 0) && (lVar14 = *param_2, lVar14 != 0)) {
    ipc_log_string(*(undefined8 *)(lVar14 + 0x728),
                   "DBG1:%s: PCIe: RC%d: TLP Header: %08x %08x %08x %08x\n","msm_print_tlp_header",
                   *(undefined4 *)(lVar14 + 0x570),(int)param_2[8],
                   *(undefined4 *)((long)param_2 + 0x44),(int)param_2[9],
                   *(undefined4 *)((long)param_2 + 0x4c));
    ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                   "%s: PCIe: RC%d: TLP Header: %08x %08x %08x %08x\n","msm_print_tlp_header",
                   *(undefined4 *)(*param_2 + 0x570),(int)param_2[8],
                   *(undefined4 *)((long)param_2 + 0x44),(int)param_2[9],
                   *(undefined4 *)((long)param_2 + 0x4c));
  }
LAB_001066b0:
  if ((((*(ushort *)((long)param_2 + 0x34) != 0) && (1 < (int)param_2[6])) &&
      ((uint)*(ushort *)((long)param_2 + 0x34) == (uVar7 | (uint)bVar8 << 8))) &&
     (lVar14 = *param_2, lVar14 != 0)) {
    ipc_log_string(*(undefined8 *)(lVar14 + 0x728),
                   "DBG1:%s: PCIe: RC%d: Error of this Agent is reported first\n",
                   "msm_aer_print_error",*(undefined4 *)(lVar14 + 0x570));
    ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                   "%s: PCIe: RC%d: Error of this Agent is reported first\n","msm_aer_print_error",
                   *(undefined4 *)(*param_2 + 0x570));
  }
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_dsp_link_control @ 00106758 size=684
// signature: undefined msm_pcie_dsp_link_control(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_dsp_link_control(long param_1,ulong param_2)

{
  undefined8 uVar1;
  char *pcVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  undefined4 local_44;
  ushort local_40 [2];
  ushort local_3c [2];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_3c[0] = 0;
  local_40[0] = 0;
  local_44 = 0;
  lVar5 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (*(char *)(lVar5 + 0x71c) != '\0') {
    lVar3 = *(long *)(*(long *)(param_1 + 0x10) + 0x38);
    if ((*(ushort *)(lVar3 + 0x72) & 0xf0) == 0x60) {
      pci_read_config_dword(lVar3,*(byte *)(lVar3 + 0x6c) + 0xc,&local_44);
      pci_read_config_word(lVar3,*(byte *)(lVar3 + 0x6c) + 0x10,local_3c);
      if ((param_2 & 1) != 0) {
        local_3c[0] = local_3c[0] & 0xffef;
        pci_write_config_word(lVar3,*(byte *)(lVar3 + 0x6c) + 0x10);
        if (lVar5 != 0) {
          ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                         "DBG1:%s: PCIe: RC%d: DSP<->EP Link is enabled\n",
                         "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: PCIe: RC%d: DSP<->EP Link is enabled\n"
                         ,"msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
        }
        iVar4 = 0;
        do {
          usleep_range_state(5000,0x13ed,2);
          pci_read_config_word(lVar3,*(byte *)(lVar3 + 0x6c) + 0x12,local_40);
          if ((local_44._2_1_ >> 4 & 1) == 0) {
            if ((local_40[0] >> 0xb & 1) != 0) goto LAB_00106848;
LAB_00106890:
            if (lVar5 != 0) {
              ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                             "DBG1:%s: PCIe: RC%d: DSP<->EP link status: 0x%04x\n",
                             "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
              ipc_log_string(*(undefined8 *)(lVar5 + 0x720),
                             "%s: PCIe: RC%d: DSP<->EP link status: 0x%04x\n",
                             "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570),local_40[0])
              ;
              ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                             "DBG1:%s: PCIe: RC%d: DSP<->EP Link is up after %d checkings\n",
                             "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570),iVar4);
              ipc_log_string(*(undefined8 *)(lVar5 + 0x720),
                             "%s: PCIe: RC%d: DSP<->EP Link is up after %d checkings\n",
                             "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570),iVar4);
            }
            goto LAB_00106994;
          }
          if ((local_40[0] & 0x2800) == 0x2000) goto LAB_00106890;
LAB_00106848:
          iVar4 = iVar4 + 1;
        } while (iVar4 != 0x15);
        if (lVar5 != 0) {
          ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                         "DBG1:%s: DSP<->EP link initialization failed\n",
                         "msm_pcie_dsp_link_control");
          ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: DSP<->EP link initialization failed\n",
                         "msm_pcie_dsp_link_control");
        }
        uVar1 = 0xffffffff;
        goto LAB_00106998;
      }
      local_3c[0] = local_3c[0] | 0x10;
      pci_write_config_word(lVar3,*(byte *)(lVar3 + 0x6c) + 0x10);
      if (lVar5 != 0) {
        ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                       "DBG1:%s: PCIe: RC%d: DSP<->EP Link is disabled\n",
                       "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
        uVar1 = *(undefined8 *)(lVar5 + 0x720);
        pcVar2 = "%s: PCIe: RC%d: DSP<->EP Link is disabled\n";
        goto LAB_00106988;
      }
    }
    else if (lVar5 != 0) {
      ipc_log_string(*(undefined8 *)(lVar5 + 0x728),
                     "DBG1:%s: PCIe: RC%d: no DSP<->EP link under this RC\n",
                     "msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
      uVar1 = *(undefined8 *)(lVar5 + 0x720);
      pcVar2 = "%s: PCIe: RC%d: no DSP<->EP link under this RC\n";
LAB_00106988:
      ipc_log_string(uVar1,pcVar2,"msm_pcie_dsp_link_control",*(undefined4 *)(lVar5 + 0x570));
    }
  }
LAB_00106994:
  uVar1 = 0;
LAB_00106998:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_allow_l1 @ 00106a08 size=672
// signature: undefined msm_pcie_allow_l1(void)
// callers: [msm_pcie_prevent_l1, msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

undefined8 msm_pcie_allow_l1(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  long lVar7;
  undefined8 uVar8;
  
  if (param_1 != 0) {
    lVar7 = param_1;
    do {
      if ((*(char *)(lVar7 + 0x6c) != '\0') && ((*(ushort *)(lVar7 + 0x72) & 0xf0) == 0x40)) {
        lVar7 = *(long *)(*(long *)(*(long *)(lVar7 + 0x10) + 0xe8) + 200);
        mutex_lock(lVar7 + 0x480);
        mutex_lock(lVar7 + 0x648);
        if (*(char *)(lVar7 + 0x4d8) == '\0') {
          if (*(char *)(lVar7 + 0x4da) == '\0') {
            if (lVar7 != 0) {
              pcVar5 = "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: l1 not supported\n";
              uVar4 = *(uint *)(param_1 + 0x38);
              uVar8 = *(undefined8 *)(lVar7 + 0x720);
              uVar2 = *(undefined4 *)(lVar7 + 0x570);
              uVar3 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
LAB_00106ba0:
              ipc_log_string(uVar8,pcVar5,"msm_pcie_allow_l1",uVar2,uVar3,uVar4 >> 3 & 0x1f,
                             uVar4 & 7);
            }
          }
          else {
            if (*(int *)(lVar7 + 0x4b0) != 1) {
              if (lVar7 != 0) {
                ipc_log_string(*(undefined8 *)(lVar7 + 0x720),
                               "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: lnk_sts %d\n",
                               "msm_pcie_allow_l1",*(undefined4 *)(lVar7 + 0x570),
                               *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                               *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
              }
              uVar8 = 0xffffffea;
              goto LAB_00106bb0;
            }
            iVar6 = *(int *)(lVar7 + 0x678) + -1;
            *(int *)(lVar7 + 0x678) = iVar6;
            if (iVar6 < 0) {
              if (lVar7 != 0) {
                ipc_log_string(*(undefined8 *)(lVar7 + 0x728),
                               "ERR:%s: PCIe: RC%d: %02x:%02x.%01x: unbalanced prevent_l1: %d < 0\n"
                               ,"msm_pcie_allow_l1",*(undefined4 *)(lVar7 + 0x570),
                               *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                               *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
                ipc_log_string(*(undefined8 *)(lVar7 + 0x720),
                               "%s: PCIe: RC%d: %02x:%02x.%01x: unbalanced prevent_l1: %d < 0\n",
                               "msm_pcie_allow_l1",*(undefined4 *)(lVar7 + 0x570),
                               *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                               *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7,
                               *(undefined4 *)(lVar7 + 0x678));
                iVar6 = *(int *)(lVar7 + 0x678);
              }
              _printk(&DAT_00128cd0,"msm_pcie_allow_l1",*(undefined4 *)(lVar7 + 0x570),
                      *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                      *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7,iVar6);
              iVar6 = *(int *)(lVar7 + 0x678);
            }
            if (iVar6 == 0) {
              if (*(char *)(lVar7 + 0x4da) != '\0') {
                pci_walk_bus(*(undefined8 *)(*(long *)(lVar7 + 8) + 0x10),msm_pcie_config_l1_enable,
                             lVar7);
              }
              lVar1 = *(long *)(lVar7 + 0x380) + 0x20;
              uVar4 = readl_relaxed(lVar1);
              writel_relaxed(uVar4 & 0xffffffdf,lVar1);
              readl_relaxed(lVar1);
              if (lVar7 != 0) {
                uVar4 = *(uint *)(param_1 + 0x38);
                pcVar5 = "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: exit\n";
                uVar8 = *(undefined8 *)(lVar7 + 0x720);
                uVar2 = *(undefined4 *)(lVar7 + 0x570);
                uVar3 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
                goto LAB_00106ba0;
              }
            }
          }
        }
        else if (lVar7 != 0) {
          ipc_log_string(*(undefined8 *)(lVar7 + 0x720),
                         "DBG2:%s: PCIe: RC%d: debugfs_l1 is set so no-op\n","msm_pcie_allow_l1",
                         *(undefined4 *)(lVar7 + 0x570));
        }
        uVar8 = 0;
LAB_00106bb0:
        mutex_unlock(lVar7 + 0x648);
        mutex_unlock(lVar7 + 0x480);
        return uVar8;
      }
      if ((*(uint *)(lVar7 + 0xac9) >> 0x17 & 1) != 0) {
        lVar7 = *(long *)(lVar7 + 0xc80);
      }
    } while ((*(long *)(*(long *)(lVar7 + 0x10) + 0x10) != 0) &&
            (lVar7 = *(long *)(*(long *)(lVar7 + 0x10) + 0x38), lVar7 != 0));
  }
  return 0xffffffed;
}



//------------------------------------------------------------
// msm_pcie_prevent_l1 @ 00106cac size=904
// signature: undefined msm_pcie_prevent_l1(void)
// callers: [msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

undefined8 msm_pcie_prevent_l1(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  uint uVar5;
  char *pcVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  int iVar10;
  
  if (param_1 != 0) {
    lVar7 = param_1;
    do {
      if ((*(char *)(lVar7 + 0x6c) != '\0') && ((*(ushort *)(lVar7 + 0x72) & 0xf0) == 0x40)) {
        lVar9 = *(long *)(*(long *)(*(long *)(lVar7 + 0x10) + 0xe8) + 200);
        lVar7 = lVar9 + 0x480;
        mutex_lock(lVar7);
        lVar1 = lVar9 + 0x648;
        mutex_lock(lVar1);
        if (*(char *)(lVar9 + 0x4d8) != '\0') {
          if (lVar9 != 0) {
            ipc_log_string(*(undefined8 *)(lVar9 + 0x720),
                           "DBG2:%s: PCIe: RC%d: debugfs_l1 is set so no-op\n","msm_pcie_prevent_l1"
                           ,*(undefined4 *)(lVar9 + 0x570));
          }
          goto LAB_00106eac;
        }
        if (*(char *)(lVar9 + 0x4da) == '\0') {
          if (lVar9 == 0) goto LAB_00106eac;
          pcVar6 = "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: L1 not supported\n";
          uVar5 = *(uint *)(param_1 + 0x38);
          uVar8 = *(undefined8 *)(lVar9 + 0x720);
          uVar3 = *(undefined4 *)(lVar9 + 0x570);
          uVar4 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
          goto LAB_00106ea0;
        }
        if (*(int *)(lVar9 + 0x4b0) != 1) {
          if (lVar9 != 0) {
            ipc_log_string(*(undefined8 *)(lVar9 + 0x720),
                           "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: lnk_sts %d\n","msm_pcie_prevent_l1"
                           ,*(undefined4 *)(lVar9 + 0x570),
                           *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                           *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
          }
          uVar8 = 0xffffffea;
          goto LAB_00106eb0;
        }
        iVar10 = *(int *)(lVar9 + 0x678);
        *(int *)(lVar9 + 0x678) = iVar10 + 1;
        if (iVar10 != 0) goto LAB_00106eac;
        lVar2 = *(long *)(lVar9 + 0x380) + 0x20;
        uVar5 = readl_relaxed(lVar2);
        writel_relaxed(uVar5 | 0x20,lVar2);
        readl_relaxed(lVar2);
        uVar5 = readl_relaxed(*(long *)(lVar9 + 0x380) + 0x1b0);
        if ((uVar5 & 0x3f) == 0x11) goto LAB_00106e3c;
        iVar10 = 0x3e9;
        goto LAB_00106de8;
      }
      if ((*(uint *)(lVar7 + 0xac9) >> 0x17 & 1) != 0) {
        lVar7 = *(long *)(lVar7 + 0xc80);
      }
    } while ((*(long *)(*(long *)(lVar7 + 0x10) + 0x10) != 0) &&
            (lVar7 = *(long *)(*(long *)(lVar7 + 0x10) + 0x38), lVar7 != 0));
  }
  return 0xffffffed;
LAB_00106de8:
  do {
    uVar5 = readl_relaxed(*(long *)(lVar9 + 0x380) + 0x1b0);
    if ((uVar5 & 0x3f) == 0x12) break;
    if (*(int *)(lVar9 + 0x4b0) == 4) {
LAB_00107014:
      mutex_unlock(lVar1);
      mutex_unlock(lVar7);
      msm_pcie_allow_l1(param_1);
      return 0xfffffffb;
    }
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) {
      if (lVar9 != 0) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x728),
                       "ERR:%s: PCIe: RC%d: %02x:%02x.%01x: failed to transition to L0\n",
                       "msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        ipc_log_string(*(undefined8 *)(lVar9 + 0x720),
                       "%s: PCIe: RC%d: %02x:%02x.%01x: failed to transition to L0\n",
                       "msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      }
      _printk(&DAT_0012f728,"msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570),
              *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
              *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      if (lVar9 != 0) {
        ipc_log_string(*(undefined8 *)(lVar9 + 0x728),"ERR:%s: PCIe: RC%d: dump PCIe registers\n",
                       "msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar9 + 0x720),"%s: PCIe: RC%d: dump PCIe registers\n",
                       "msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570));
      }
      _printk(&DAT_00127d08,"msm_pcie_prevent_l1",*(undefined4 *)(lVar9 + 0x570));
      msm_pcie_clk_dump(lVar9);
      pcie_parf_dump(lVar9);
      pcie_dm_core_dump(lVar9);
      pcie_phy_dump(lVar9);
      pcie_sm_dump(lVar9);
      pcie_crm_dump(lVar9);
      goto LAB_00107014;
    }
    usleep_range_state(100,0x69,2);
    uVar5 = readl_relaxed(*(long *)(lVar9 + 0x380) + 0x1b0);
  } while ((uVar5 & 0x3f) != 0x11);
LAB_00106e3c:
  msm_pcie_config_l1_disable_all(lVar9,*(undefined8 *)(*(long *)(lVar9 + 8) + 0x10));
  if (lVar9 != 0) {
    uVar5 = *(uint *)(param_1 + 0x38);
    pcVar6 = "DBG2:%s: PCIe: RC%d: %02x:%02x.%01x: exit\n";
    uVar8 = *(undefined8 *)(lVar9 + 0x720);
    uVar3 = *(undefined4 *)(lVar9 + 0x570);
    uVar4 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
LAB_00106ea0:
    ipc_log_string(uVar8,pcVar6,"msm_pcie_prevent_l1",uVar3,uVar4,uVar5 >> 3 & 0x1f,uVar5 & 7);
  }
LAB_00106eac:
  uVar8 = 0;
LAB_00106eb0:
  mutex_unlock(lVar1);
  mutex_unlock(lVar7);
  return uVar8;
}



//------------------------------------------------------------
// pcie_parf_dump @ 00107034 size=592
// signature: undefined pcie_parf_dump(void)
// callers: [msm_aer_process_err_devices, msm_pcie_prevent_l1, msm_pcie_set_link_bandwidth, handle_wake_irq, msm_pcie_sel_debug_testcase, msm_pcie_handle_linkdown]
//------------------------------------------------------------

void pcie_parf_dump(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  ulong uVar11;
  undefined8 uVar12;
  uint uVar13;
  uint uVar14;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DUMP:%s: PCIe: RC%d PARF testbus\n",
                   "pcie_parf_dump",*(undefined4 *)(param_1 + 0x570));
  }
  uVar1 = readl_relaxed(*(undefined8 *)(param_1 + 0x380));
  uVar13 = 0;
  uVar14 = 0;
  do {
    uVar12 = *(undefined8 *)(param_1 + 0x380);
    uVar2 = readl_relaxed(uVar12);
    writel_relaxed(uVar2 & 0xff00ffff | uVar13,uVar12);
    readl_relaxed(uVar12);
    if (param_1 != 0) {
      uVar12 = *(undefined8 *)(param_1 + 0x730);
      uVar5 = *(undefined4 *)(param_1 + 0x570);
      uVar3 = readl_relaxed(*(undefined8 *)(param_1 + 0x380));
      uVar4 = readl_relaxed(*(long *)(param_1 + 0x380) + 0xe4);
      ipc_log_string(uVar12,"DUMP:%s: RC%d: PARF_SYS_CTRL: 0%08x PARF_TEST_BUS: 0%08x\n",
                     "pcie_parf_dump",uVar5,uVar3,uVar4);
    }
    uVar14 = uVar14 + 1;
    uVar13 = uVar13 + 0x10000;
  } while (uVar14 <= *(uint *)(param_1 + 0x6d0));
  uVar12 = *(undefined8 *)(param_1 + 0x380);
  writel_relaxed(uVar1,uVar12);
  readl_relaxed(uVar12);
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DUMP:%s: PCIe: RC%d PARF register dump\n",
                   "pcie_parf_dump",*(undefined4 *)(param_1 + 0x570));
  }
  uVar11 = 0xffffffffffffffe0;
  do {
    if (param_1 != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x570);
      uVar12 = *(undefined8 *)(param_1 + 0x730);
      uVar5 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x20);
      uVar3 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x24);
      uVar4 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x28);
      uVar6 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x2c);
      uVar7 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x30);
      uVar8 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x34);
      uVar9 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x38);
      uVar10 = readl_relaxed(*(long *)(param_1 + 0x380) + uVar11 + 0x3c);
      ipc_log_string(uVar12,"DUMP:%s: RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                     "pcie_parf_dump",uVar1,(int)uVar11 + 0x20,uVar5,uVar3,uVar4,uVar6,uVar7,uVar8,
                     uVar9,uVar10);
    }
    uVar11 = uVar11 + 0x20;
  } while (uVar11 >> 5 < 0xff);
  return;
}



//------------------------------------------------------------
// pcie_dm_core_dump @ 00107284 size=404
// signature: undefined pcie_dm_core_dump(void)
// callers: [msm_aer_process_err_devices, msm_pcie_prevent_l1, msm_pcie_set_link_bandwidth, handle_wake_irq, msm_pcie_handle_linkdown]
//------------------------------------------------------------

void pcie_dm_core_dump(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  long lVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DUMP:%s: PCIe: RC%d DBI/dm_core register dump\n","pcie_dm_core_dump",
                   *(undefined4 *)(param_1 + 0x570));
  }
  lVar11 = (*(long **)(param_1 + 0x198))[1] - **(long **)(param_1 + 0x198);
  uVar1 = 0x1000;
  if (lVar11 + 1U < 0x1000) {
    uVar1 = lVar11 + 1;
  }
  if (uVar1 != 0) {
    uVar12 = 0;
    do {
      if (param_1 != 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x570);
        uVar13 = *(undefined8 *)(param_1 + 0x730);
        uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12);
        uVar4 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 4);
        uVar5 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 8);
        uVar6 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 0xc);
        uVar7 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 0x10);
        uVar8 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 0x14);
        uVar9 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 0x18);
        uVar10 = readl_relaxed(*(long *)(param_1 + 0x3a0) + uVar12 + 0x1c);
        ipc_log_string(uVar13,"DUMP:%s: RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n",
                       "pcie_dm_core_dump",uVar2,uVar12 & 0xffffffff,uVar3,uVar4,uVar5,uVar6,uVar7,
                       uVar8,uVar9,uVar10);
      }
      uVar12 = uVar12 + 0x20;
    } while (uVar12 < uVar1);
  }
  return;
}



//------------------------------------------------------------
// pcie_phy_dump @ 00107418 size=368
// signature: undefined pcie_phy_dump(void)
// callers: [msm_aer_process_err_devices, msm_pcie_prevent_l1, msm_pcie_enable_link, msm_pcie_set_link_bandwidth, handle_wake_irq, msm_pcie_sel_debug_testcase, msm_pcie_handle_linkdown]
//------------------------------------------------------------

void pcie_phy_dump(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined8 uVar12;
  
  iVar1 = ((*(int **)(param_1 + 0x180))[2] - **(int **)(param_1 + 0x180)) + 1;
  if (0 < iVar1) {
    iVar11 = 0;
    do {
      if (param_1 != 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x570);
        uVar12 = *(undefined8 *)(param_1 + 0x730);
        uVar3 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)iVar11);
        uVar4 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 4));
        uVar5 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 8));
        uVar6 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 0xc));
        uVar7 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 0x10));
        uVar8 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 0x14));
        uVar9 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 0x18));
        uVar10 = readl_relaxed(*(long *)(param_1 + 0x388) + (long)(iVar11 + 0x1c));
        ipc_log_string(uVar12,
                       "DUMP:%s: PCIe PHY of RC%d: 0x%04x %08x %08x %08x %08x %08x %08x %08x %08x\n"
                       ,"pcie_phy_dump",uVar2,iVar11,uVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9,
                       uVar10);
      }
      iVar11 = iVar11 + 0x20;
    } while (iVar11 < iVar1);
  }
  return;
}



//------------------------------------------------------------
// pcie_sm_dump @ 00107588 size=252
// signature: undefined pcie_sm_dump(void)
// callers: [msm_aer_process_err_devices, msm_pcie_prevent_l1, msm_pcie_set_link_bandwidth, handle_wake_irq, msm_pcie_handle_linkdown]
//------------------------------------------------------------

void pcie_sm_dump(long param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  
  if (*(long *)(param_1 + 0xd00) != 0) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DUMP:%s: PCIe: RC%d State Manager reg dump\n"
                     ,"pcie_sm_dump",*(undefined4 *)(param_1 + 0x570));
    }
    lVar4 = *(long *)(param_1 + 0xd08);
    if ((0 < *(int *)(lVar4 + 0x28)) &&
       (uVar1 = ((*(long **)(param_1 + 0x1f8))[1] - **(long **)(param_1 + 0x1f8)) + 1,
       (uVar1 & 0xffffffff) != 0)) {
      uVar7 = 0;
      do {
        if (param_1 != 0) {
          uVar6 = *(undefined8 *)(param_1 + 0x730);
          uVar5 = (ulong)*(uint *)(*(long *)(lVar4 + 0x18) + uVar7 * 4);
          uVar2 = *(undefined4 *)(param_1 + 0x570);
          uVar3 = readl_relaxed(*(long *)(param_1 + 0xd00) + uVar5);
          ipc_log_string(uVar6,"DUMP:%s: RC%d: 0x%04x %08x\n","pcie_sm_dump",uVar2,uVar5,uVar3);
          lVar4 = *(long *)(param_1 + 0xd08);
        }
        uVar7 = uVar7 + 1;
      } while (((long)uVar7 < (long)*(int *)(lVar4 + 0x28)) && (uVar7 < (uVar1 & 0xffffffff)));
    }
  }
  return;
}



//------------------------------------------------------------
// pcie_crm_dump @ 00107684 size=96
// signature: undefined pcie_crm_dump(void)
// callers: [msm_pcie_prevent_l1, msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

void pcie_crm_dump(long param_1)

{
  int iVar1;
  
  if (((*(long *)(param_1 + 0xd00) != 0) && (iVar1 = crm_dump_regs("pcie_crm"), param_1 != 0)) &&
     (iVar1 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n","pcie_crm_dump",
                   *(undefined4 *)(param_1 + 0x570),iVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1_disable_all @ 001076e4 size=120
// signature: undefined msm_pcie_config_l1_disable_all(void)
// callers: [msm_pcie_config_l1_disable_all, msm_pcie_prevent_l1, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_config_l1_disable_all(long param_1,long param_2)

{
  long *plVar1;
  
  if (*(char *)(param_1 + 0x4da) != '\0') {
    for (plVar1 = *(long **)(param_2 + 0x28); plVar1 != (long *)(param_2 + 0x28);
        plVar1 = (long *)*plVar1) {
      if (plVar1[3] != 0) {
        msm_pcie_config_l1_disable_all(param_1);
      }
      msm_pcie_config_l1(param_1,plVar1,0);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_set_target_link_speed @ 00107760 size=316
// signature: undefined msm_pcie_set_target_link_speed(void)
// callers: [link_speed_override_store]
//------------------------------------------------------------

undefined8 msm_pcie_set_target_link_speed(uint param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  
  if (param_1 < 5) {
    lVar3 = (&msm_pcie_dev)[param_1];
    if ((lVar3 == 0) || (*(char *)(lVar3 + 0x578) == '\0')) {
      _printk(&DAT_00122cf7);
      return 0xfffffdfb;
    }
    if ((param_2 <= *(uint *)(lVar3 + 0x400)) &&
       (((uVar2 = *(uint *)(lVar3 + 0x4f8), uVar2 == 0 || (param_2 <= uVar2)) ||
        ((param_3 & 1) != 0)))) {
      uVar1 = *(uint *)(lVar3 + 0x400);
      if ((param_3 & 1) == 0 && uVar2 != 0) {
        uVar1 = uVar2;
      }
      if (param_2 != 0) {
        uVar1 = param_2;
      }
      *(uint *)(lVar3 + 0x4f4) = uVar1;
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                     "DBG1:%s: PCIe: RC%d: target_link_speed is now: 0x%x.\n",
                     "msm_pcie_set_target_link_speed",*(undefined4 *)(lVar3 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                     "%s: PCIe: RC%d: target_link_speed is now: 0x%x.\n",
                     "msm_pcie_set_target_link_speed",*(undefined4 *)(lVar3 + 0x570),
                     *(undefined4 *)(lVar3 + 0x4f4));
      return 0;
    }
    ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                   "DBG1:%s: PCIe: RC%d: invalid target link speed: %d\n",
                   "msm_pcie_set_target_link_speed",*(undefined4 *)(lVar3 + 0x570),param_2);
    ipc_log_string(*(undefined8 *)(lVar3 + 0x720),"%s: PCIe: RC%d: invalid target link speed: %d\n",
                   "msm_pcie_set_target_link_speed",*(undefined4 *)(lVar3 + 0x570),param_2);
  }
  else {
    _printk(&DAT_00120306);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// msm_pcie_set_link_bandwidth @ 001078a0 size=936
// signature: undefined msm_pcie_set_link_bandwidth(void)
// callers: []
//------------------------------------------------------------

int msm_pcie_set_link_bandwidth(long param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  int iVar3;
  long lVar4;
  uint uVar5;
  ushort local_60 [2];
  uint local_5c;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  local_60[0] = 0;
  if (param_1 == 0) {
LAB_00107a14:
    iVar3 = -0x16;
  }
  else {
    do {
      if ((*(char *)(param_1 + 0x6c) != '\0') && ((*(ushort *)(param_1 + 0x72) & 0xf0) == 0x40)) {
        uVar5 = param_2 & 0xffff;
        lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
        if ((*(uint *)(lVar4 + 0x400) < uVar5) ||
           (*(uint *)(lVar4 + 0x4f4) != 0 && *(uint *)(lVar4 + 0x4f4) < uVar5)) {
          if (lVar4 != 0) {
            ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                           "DBG1:%s: PCIe: RC%d: invalid target link speed: %d\n",
                           "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar5);
            ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                           "%s: PCIe: RC%d: invalid target link speed: %d\n",
                           "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar5);
          }
          goto LAB_00107a14;
        }
        pcie_capability_read_word(param_1,0x12,local_60);
        uVar2 = local_60[0];
        uVar1 = local_60[0] & 0xf;
        if ((uVar1 != (param_2 & 0xffff)) && (lVar4 != 0)) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                         "DBG1:%s: PCIe: RC%d: switching from Gen%d to Gen%d\n",
                         "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar1,uVar5);
          ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                         "%s: PCIe: RC%d: switching from Gen%d to Gen%d\n",
                         "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar1,uVar5);
        }
        if (uVar1 == (param_2 & 0xffff)) {
          iVar3 = 0;
        }
        else {
          if (lVar4 != 0) {
            uVar2 = uVar2 >> 4 & 0x3f;
            ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                           "DBG1:%s: PCIe: RC%d: current link width:%d max link width:%d\n",
                           "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar2,
                           *(undefined4 *)(lVar4 + 0x404));
            ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                           "%s: PCIe: RC%d: current link width:%d max link width:%d\n",
                           "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar2,
                           *(undefined4 *)(lVar4 + 0x404));
          }
          local_5c = 0;
          iVar3 = *(byte *)(param_1 + 0x6c) + 0x30;
          pci_read_config_dword(param_1,iVar3,&local_5c);
          local_5c = local_5c & 0xfffffff0 | uVar5;
          pci_write_config_dword(param_1,iVar3);
          iVar3 = msm_pcie_prevent_l1(param_1);
          if (iVar3 == 0) {
            msm_pcie_config_l0s_disable_all(lVar4,*(undefined8 *)(param_1 + 0x10));
            msm_pcie_poll_for_l0_from_l0s(lVar4);
            if (uVar1 < (param_2 & 0xffff)) {
              msm_pcie_scale_link_bandwidth(lVar4,param_2);
            }
            iVar3 = msm_pcie_link_retrain(lVar4,param_1);
            if (iVar3 == 0) {
              if (*(uint *)(lVar4 + 0x4fc) != uVar5) {
                if (lVar4 != 0) {
                  ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                                 "ERR:%s: PCIe: RC%d: failed to switch bandwidth: target speed: %d\n"
                                 ,"msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar5
                                );
                  ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                                 "%s: PCIe: RC%d: failed to switch bandwidth: target speed: %d\n",
                                 "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),uVar5)
                  ;
                }
                _printk(&DAT_00128d48,"msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570),
                        uVar5);
                iVar3 = -5;
                goto LAB_00107b24;
              }
              if ((param_2 & 0xffff) < uVar1) {
                msm_pcie_scale_link_bandwidth(lVar4,param_2);
                uVar5 = *(uint *)(lVar4 + 0x4fc);
              }
              msm_pcie_icc_vote(lVar4,uVar5,*(undefined4 *)(lVar4 + 0x504),0);
              if (lVar4 != 0) {
                ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                               "DBG1:%s: PCIe: RC%d: successfully switched link bandwidth\n",
                               "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570));
                ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                               "%s: PCIe: RC%d: successfully switched link bandwidth\n",
                               "msm_pcie_set_link_bandwidth",*(undefined4 *)(lVar4 + 0x570));
              }
              iVar3 = 0;
            }
            else {
LAB_00107b24:
              pcie_parf_dump(lVar4);
              pcie_dm_core_dump(lVar4);
              pcie_phy_dump(lVar4);
              pcie_sm_dump(lVar4);
              pcie_crm_dump(lVar4);
            }
            msm_pcie_config_l0s_enable_all(lVar4);
            msm_pcie_allow_l1(param_1);
          }
        }
        goto LAB_00107a18;
      }
      if ((*(uint *)(param_1 + 0xac9) >> 0x17 & 1) != 0) {
        param_1 = *(long *)(param_1 + 0xc80);
      }
    } while ((*(long *)(*(long *)(param_1 + 0x10) + 0x10) != 0) &&
            (param_1 = *(long *)(*(long *)(param_1 + 0x10) + 0x38), param_1 != 0));
    iVar3 = -0x13;
  }
LAB_00107a18:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_pcie_config_l0s_disable_all @ 00107c48 size=120
// signature: undefined msm_pcie_config_l0s_disable_all(void)
// callers: [msm_pcie_set_link_bandwidth, msm_pcie_sel_debug_testcase, msm_pcie_config_l0s_disable_all]
//------------------------------------------------------------

void msm_pcie_config_l0s_disable_all(long param_1,long param_2)

{
  long *plVar1;
  
  if (*(char *)(param_1 + 0x4d9) != '\0') {
    for (plVar1 = *(long **)(param_2 + 0x28); plVar1 != (long *)(param_2 + 0x28);
        plVar1 = (long *)*plVar1) {
      if (plVar1[3] != 0) {
        msm_pcie_config_l0s_disable_all(param_1);
      }
      msm_pcie_config_l0s(param_1,plVar1,0);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_poll_for_l0_from_l0s @ 00107cc0 size=120
// signature: undefined msm_pcie_poll_for_l0_from_l0s(void)
// callers: [msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

void msm_pcie_poll_for_l0_from_l0s(long param_1)

{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x4d9) != '\0') {
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x380) + 0x1b0);
    while ((uVar1 & 0x3f) != 0x11) {
      pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_read_devid_all,param_1);
      uVar1 = readl_relaxed(*(long *)(param_1 + 0x380) + 0x1b0);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_scale_link_bandwidth @ 00107d38 size=412
// signature: undefined msm_pcie_scale_link_bandwidth(void)
// callers: [msm_pcie_enable_link, msm_pcie_set_link_bandwidth, msm_pcie_pm_control]
//------------------------------------------------------------

void msm_pcie_scale_link_bandwidth(long param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x3f8);
  if (lVar4 != 0) {
    param_2 = param_2 & 0xffff;
    uVar1 = param_2 - 1;
    if (uVar1 < *(uint *)(param_1 + 0x400)) {
      if (*(long *)(param_1 + 0xd00) == 0) {
        puVar3 = *(undefined8 **)(param_1 + 1000);
        if (puVar3 != (undefined8 *)0x0) {
          regulator_set_voltage
                    (*puVar3,*(undefined4 *)(lVar4 + (ulong)uVar1 * 0xc),*(undefined4 *)(puVar3 + 2)
                    );
        }
        puVar3 = *(undefined8 **)(param_1 + 0x3f0);
        if (puVar3 != (undefined8 *)0x0) {
          regulator_set_voltage
                    (*puVar3,*(undefined4 *)(lVar4 + (ulong)uVar1 * 0xc + 4),
                     *(undefined4 *)(puVar3 + 2));
        }
        if (*(long *)(param_1 + 0x408) != 0) {
          clk_set_rate(*(long *)(param_1 + 0x408),*(undefined4 *)(lVar4 + (ulong)uVar1 * 0xc + 8));
        }
      }
      else {
        iVar2 = param_2 + 1;
        if (iVar2 != msm_pcie_cesta_map._12_4_) {
          msm_pcie_cesta_map._8_4_ = iVar2;
          msm_pcie_cesta_map._12_4_ = iVar2;
          msm_pcie_cesta_map._20_4_ = iVar2;
          iVar2 = msm_pcie_cesta_map_apply(param_1,1);
          if (iVar2 != 0) {
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                             "ERR:%s: Failed to move to D0 state %d\n",
                             "msm_pcie_scale_link_bandwidth",iVar2);
              ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: Failed to move to D0 state %d\n",
                             "msm_pcie_scale_link_bandwidth",iVar2);
            }
            _printk(&DAT_0012e565,"msm_pcie_scale_link_bandwidth",iVar2);
          }
        }
      }
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d: invalid target link speed: %d\n",
                       "msm_pcie_scale_link_bandwidth",*(undefined4 *)(param_1 + 0x570),param_2);
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d: invalid target link speed: %d\n",
                       "msm_pcie_scale_link_bandwidth",*(undefined4 *)(param_1 + 0x570),param_2);
      }
      _printk(&DAT_00120644,"msm_pcie_scale_link_bandwidth",*(undefined4 *)(param_1 + 0x570),param_2
             );
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_link_retrain @ 00107ed4 size=484
// signature: undefined msm_pcie_link_retrain(void)
// callers: [msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

void msm_pcie_link_retrain(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  msm_pcie_config_bandwidth_int(param_1,1);
  *(undefined4 *)(param_1 + 0x860) = 0;
  local_3c = 0;
  iVar2 = *(byte *)(param_2 + 0x6c) + 0x10;
  pci_read_config_dword(param_2,iVar2,&local_3c);
  local_3c = local_3c | 0x20;
  pci_write_config_dword(param_2,iVar2);
  iVar2 = wait_for_completion_timeout(param_1 + 0x860,0x19);
  if (iVar2 == 0) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Bandwidth int: completion timeout\n",
                     "msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: RC%d: Bandwidth int: completion timeout\n","msm_pcie_link_retrain",
                     *(undefined4 *)(param_1 + 0x570));
    }
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + (ulong)*(byte *)(param_2 + 0x6c) + 0x10);
    if ((uVar3 >> 0x1e & 1) == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"ERR:%s: PCIe: RC%d: failed to retrain\n",
                       "msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: failed to retrain\n",
                       "msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570));
      }
      _printk(&DAT_0012b778,"msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570));
      uVar4 = 0xfffffffb;
      goto LAB_0010802c;
    }
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + (ulong)*(byte *)(param_2 + 0x6c) + 0x10);
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: Status set 0x%x\n",
                     "msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570),uVar3 & 0x40000000);
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: Status set 0x%x\n",
                     "msm_pcie_link_retrain",*(undefined4 *)(param_1 + 0x570),uVar3 & 0x40000000);
    }
  }
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x80);
  uVar4 = 0;
  *(uint *)(param_1 + 0x4fc) = uVar3 >> 0x10 & 0xf;
  *(uint *)(param_1 + 0x504) = uVar3 >> 0x14 & 0x3f;
LAB_0010802c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_icc_vote @ 001080b8 size=524
// signature: undefined msm_pcie_icc_vote(void)
// callers: [msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq, msm_pcie_enable, msm_pcie_set_link_bandwidth, msm_pcie_clk_deinit, msm_pcie_pm_control]
//------------------------------------------------------------

int msm_pcie_icc_vote(long param_1,undefined1 param_2,uint param_3,ulong param_4)

{
  int iVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  long lVar5;
  
  if (*(long *)(param_1 + 0x4d0) == 0) {
    return 0;
  }
  if (*(long *)(param_1 + 0xd00) != 0) {
    uVar4 = 2;
    if ((param_4 & 1) == 0) {
      uVar4 = 3;
    }
    icc_set_tag(*(long *)(param_1 + 0x4d0),uVar4);
  }
  iVar1 = 250000;
  switch(param_2) {
  case 0:
    uVar2 = *(undefined8 *)(param_1 + 0x4d0);
    iVar1 = 0;
    uVar3 = 0;
    goto LAB_00108198;
  case 1:
    break;
  case 2:
    iVar1 = 500000;
    break;
  case 3:
    iVar1 = 1000000;
    break;
  case 4:
    iVar1 = 2000000;
    break;
  case 5:
    iVar1 = 4000000;
    break;
  default:
    iVar1 = 0;
  }
  uVar2 = *(undefined8 *)(param_1 + 0x4d0);
  if (*(char *)(param_1 + 0xd28) == '\0') {
    iVar1 = 500;
    uVar3 = 800;
  }
  else {
    uVar3 = 0;
    iVar1 = iVar1 * (param_3 & 0xff);
  }
LAB_00108198:
  iVar1 = icc_set_bw(uVar2,iVar1,uVar3);
  if (iVar1 == 0) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: ICC vote successful\n",
                     "msm_pcie_icc_vote",*(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: ICC vote successful\n",
                     "msm_pcie_icc_vote",*(undefined4 *)(param_1 + 0x570));
    }
    lVar5 = *(long *)(param_1 + 0xd00);
  }
  else {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "ERR:%s: PCIe: RC%d: failed to put the ICC vote %d.\n","msm_pcie_icc_vote",
                     *(undefined4 *)(param_1 + 0x570),iVar1);
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: RC%d: failed to put the ICC vote %d.\n","msm_pcie_icc_vote",
                     *(undefined4 *)(param_1 + 0x570),iVar1);
    }
    _printk(&DAT_0012498c,"msm_pcie_icc_vote",*(undefined4 *)(param_1 + 0x570),iVar1);
    lVar5 = *(long *)(param_1 + 0xd00);
  }
  if (((lVar5 != 0) &&
      (iVar1 = crm_write_pwr_states
                         (*(undefined8 *)(param_1 + 0xcf8),*(undefined4 *)(param_1 + 0x570)),
      param_1 != 0)) && (iVar1 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: pwr_states %d\n",
                   "msm_pcie_icc_vote",*(undefined4 *)(param_1 + 0x570),iVar1);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: pwr_states %d\n",
                   "msm_pcie_icc_vote",*(undefined4 *)(param_1 + 0x570),iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_pcie_config_l0s_enable_all @ 001082c4 size=100
// signature: undefined msm_pcie_config_l0s_enable_all(void)
// callers: [msm_pcie_set_link_bandwidth, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_config_l0s_enable_all(long param_1)

{
  if ((*(char *)(param_1 + 0x4d9) != '\0') &&
     (pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_check_l0s_support,param_1
                  ), *(char *)(param_1 + 0x4d9) != '\0')) {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l0s_enable,param_1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_fixup_suspend @ 0010832c size=388
// signature: undefined msm_pcie_fixup_suspend(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_fixup_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar4 != 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_fixup_suspend",
                   *(undefined4 *)(lVar4 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar4 + 0x720),"%s: RC%d\n","msm_pcie_fixup_suspend",
                   *(undefined4 *)(lVar4 + 0x570));
  }
  if ((*(int *)(lVar4 + 0x4b0) == 1) && (*(long *)(*(long *)(param_1 + 0x10) + 0x10) == 0)) {
    lVar1 = lVar4 + 0x444;
    uVar3 = _raw_spin_lock_irqsave(lVar1);
    *(undefined8 *)(lVar4 + 0x448) = uVar3;
    if (*(char *)(lVar4 + 0x4b5) == '\0') {
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      mutex_lock(lVar4 + 0x610);
      iVar2 = msm_pcie_pm_suspend(param_1);
      if (iVar2 != 0) {
        if (lVar4 != 0) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                         "ERR:%s: PCIe: RC%d got failure in suspend:%d.\n","msm_pcie_fixup_suspend",
                         *(undefined4 *)(lVar4 + 0x570),iVar2);
          ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                         "%s: PCIe: RC%d got failure in suspend:%d.\n","msm_pcie_fixup_suspend",
                         *(undefined4 *)(lVar4 + 0x570),iVar2);
        }
        _printk(&DAT_0012f58f,"msm_pcie_fixup_suspend",*(undefined4 *)(lVar4 + 0x570),iVar2);
      }
      mutex_unlock(lVar4 + 0x610);
    }
    else {
      if (lVar4 != 0) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                       "DBG1:%s: RC%d: Skip suspend because of user request\n",
                       "msm_pcie_fixup_suspend",*(undefined4 *)(lVar4 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar4 + 0x720),
                       "%s: RC%d: Skip suspend because of user request\n","msm_pcie_fixup_suspend",
                       *(undefined4 *)(lVar4 + 0x570));
        uVar3 = *(undefined8 *)(lVar4 + 0x448);
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_fixup_resume @ 001084b4 size=284
// signature: undefined msm_pcie_fixup_resume(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_fixup_resume(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar2 != 0) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_fixup_resume",
                   *(undefined4 *)(lVar2 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: RC%d\n","msm_pcie_fixup_resume",
                   *(undefined4 *)(lVar2 + 0x570));
  }
  if (((*(int *)(lVar2 + 0x4b0) == 2) && (*(char *)(lVar2 + 0x4b4) == '\0')) &&
     (*(long *)(*(long *)(param_1 + 0x10) + 0x10) == 0)) {
    mutex_lock(lVar2 + 0x610);
    iVar1 = msm_pcie_pm_resume(param_1);
    if (iVar1 != 0) {
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                       "ERR:%s: PCIe: RC%d got failure in fixup resume:%d.\n",
                       "msm_pcie_fixup_resume",*(undefined4 *)(lVar2 + 0x570),iVar1);
        ipc_log_string(*(undefined8 *)(lVar2 + 0x720),
                       "%s: PCIe: RC%d got failure in fixup resume:%d.\n","msm_pcie_fixup_resume",
                       *(undefined4 *)(lVar2 + 0x570),iVar1);
      }
      _printk(&DAT_001222de,"msm_pcie_fixup_resume",*(undefined4 *)(lVar2 + 0x570),iVar1);
    }
    mutex_unlock(lVar2 + 0x610);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_fixup_resume_early @ 001085d4 size=284
// signature: undefined msm_pcie_fixup_resume_early(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_fixup_resume_early(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar2 != 0) {
    ipc_log_string(*(undefined8 *)(lVar2 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_fixup_resume_early",
                   *(undefined4 *)(lVar2 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: RC%d\n","msm_pcie_fixup_resume_early",
                   *(undefined4 *)(lVar2 + 0x570));
  }
  if (((*(int *)(lVar2 + 0x4b0) == 2) && (*(char *)(lVar2 + 0x4b4) == '\0')) &&
     (*(long *)(*(long *)(param_1 + 0x10) + 0x10) == 0)) {
    mutex_lock(lVar2 + 0x610);
    iVar1 = msm_pcie_pm_resume(param_1);
    if (iVar1 != 0) {
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                       "ERR:%s: PCIe: RC%d got failure in resume:%d.\n",
                       "msm_pcie_fixup_resume_early",*(undefined4 *)(lVar2 + 0x570),iVar1);
        ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: PCIe: RC%d got failure in resume:%d.\n",
                       "msm_pcie_fixup_resume_early",*(undefined4 *)(lVar2 + 0x570),iVar1);
      }
      _printk(&DAT_00120948,"msm_pcie_fixup_resume_early",*(undefined4 *)(lVar2 + 0x570),iVar1);
    }
    mutex_unlock(lVar2 + 0x610);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_pm_control @ 001086f4 size=5508
// signature: undefined msm_pcie_pm_control(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

int msm_pcie_pm_control(uint param_1,undefined4 param_2,long param_3,undefined8 param_4,uint param_5
                       )

{
  ulong *puVar1;
  long *plVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined *puVar8;
  undefined8 uVar9;
  long lVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  long lVar13;
  undefined8 uVar14;
  bool bVar15;
  long lVar16;
  long *plVar17;
  undefined8 *puVar18;
  uint uVar19;
  char *pcVar20;
  long *plVar21;
  long lVar22;
  
  if (param_3 == 0) {
    puVar8 = &DAT_00121302;
LAB_00108d54:
    _printk(puVar8);
    return -0x13;
  }
  lVar13 = *(long *)(*(long *)(*(long *)(param_3 + 0x10) + 0xe8) + 200);
  if (lVar13 == 0) {
    puVar8 = &DAT_0012c28c;
    goto LAB_00108d54;
  }
  ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                 "DBG1:%s: PCIe: RC%d: pm_opt:%d;busnr:%d;options:%d\n","msm_pcie_pm_control",
                 *(undefined4 *)(lVar13 + 0x570),param_1,param_2,param_5);
  ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: pm_opt:%d;busnr:%d;options:%d\n",
                 "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),param_1,param_2,param_5);
  if (*(char *)(lVar13 + 0x578) == '\0') {
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "ERR:%s: RC%d has not been successfully probed yet\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: RC%d has not been successfully probed yet\n"
                   ,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    _printk(&DAT_0012f766,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    return -0x205;
  }
  if (6 < param_1) {
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "ERR:%s: PCIe: RC%d: unsupported pm operation:%d.\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570),param_1);
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: unsupported pm operation:%d.\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),param_1);
    _printk(&DAT_0012458c,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),param_1);
    return -0x13;
  }
  uVar14 = *(undefined8 *)(lVar13 + 8);
  switch(param_1) {
  case 0:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: PCIe: RC%d: DRV: user requests for DRV suspend\n","msm_pcie_pm_control"
                   ,*(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                   "%s: PCIe: RC%d: DRV: user requests for DRV suspend\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    flush_work(lVar13 + 0x7c8);
    pcVar20 = *(char **)(lVar13 + 0x790);
    if ((*(long *)(lVar13 + 0xd00) == 0) && (*pcVar20 == '\0')) {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "ERR:%s: PCIe: RC%d: DRV: client requests to DRV suspend while not connected\n"
                     ,"msm_pcie_drv_suspend",*(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d: DRV: client requests to DRV suspend while not connected\n",
                     "msm_pcie_drv_suspend",*(undefined4 *)(lVar13 + 0x570));
      _printk(&DAT_0012ff2a,"msm_pcie_drv_suspend",*(undefined4 *)(lVar13 + 0x570));
      return -0x16;
    }
    lVar16 = lVar13 + 0x610;
    mutex_lock(lVar16);
    if (*(long *)(lVar13 + 0xd00) == 0) {
      disable_irq(*(undefined4 *)(lVar13 + 0x298));
    }
    iVar4 = msm_pcie_drv_send_rpmsg(lVar13,pcVar20 + 1);
    if (iVar4 != 0) {
      if (*(long *)(lVar13 + 0xd00) == 0) {
        enable_irq(*(undefined4 *)(lVar13 + 0x298));
      }
      mutex_unlock(lVar16);
      return -0x10;
    }
    if (*(char *)(lVar13 + 0x560) == '\0') {
      msm_msi_config_access(*(undefined8 *)(*(long *)(lVar13 + 8) + 0x350),0);
    }
    uVar6 = *(uint *)(lVar13 + 0x570);
    *(undefined1 *)(lVar13 + 0x4b4) = 1;
    puVar1 = (ulong *)(&DAT_00130148 + (ulong)(uVar6 >> 6) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar15) {
        *puVar1 = *puVar1 | 1L << ((ulong)uVar6 & 0x3f);
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    uVar14 = _raw_spin_lock_irqsave(lVar13 + 0x640);
    uVar9 = _raw_spin_lock_irqsave(lVar13 + 0x444);
    *(undefined1 *)(lVar13 + 0x440) = 0;
    _raw_spin_unlock_irqrestore(lVar13 + 0x444,uVar9);
    _raw_spin_unlock_irqrestore(lVar13 + 0x640,uVar14);
    lVar10 = lVar13 + 0x480;
    mutex_lock(lVar10);
    mutex_lock(lVar13 + 0x648);
    *(undefined4 *)(lVar13 + 0x4b0) = 3;
    mutex_unlock(lVar13 + 0x648);
    if (*(long *)(lVar13 + 0xd00) == 0) {
LAB_00108edc:
      uVar6 = *(uint *)(lVar13 + 0x360);
    }
    else {
      if ((param_5 >> 2 & 1) == 0) {
        lVar22 = *(long *)(lVar13 + 0x380) + 0x180;
        writel_relaxed(0x80000000,lVar22);
        readl_relaxed(lVar22);
        lVar22 = *(long *)(lVar13 + 0x380) + 0x180;
        writel_relaxed(*(int *)(lVar13 + 0x54c) * *(int *)(lVar13 + 0xd10) | 0x80000000,lVar22);
        readl_relaxed(lVar22);
      }
      iVar4 = msm_gpio_mpm_wake_set(*(undefined4 *)(lVar13 + 0xd18),1);
      if (iVar4 != 0) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: Failed to make clkreq wakeup capable%d\n",
                       "msm_pcie_cesta_enable_drv",iVar4);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: Failed to make clkreq wakeup capable%d\n","msm_pcie_cesta_enable_drv",
                       iVar4);
        _printk(&DAT_0012d9ff,"msm_pcie_cesta_enable_drv",iVar4);
      }
      iVar4 = pcie_pdc_cfg_irq(*(undefined4 *)(lVar13 + 0xd18),2,1);
      if (iVar4 != 0) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: Failed to make clkreq pdc wakeup capable%d\n",
                       "msm_pcie_cesta_enable_drv",iVar4);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: Failed to make clkreq pdc wakeup capable%d\n",
                       "msm_pcie_cesta_enable_drv",iVar4);
        _printk(&DAT_0012831c,"msm_pcie_cesta_enable_drv",iVar4);
      }
      iVar4 = msm_pcie_cesta_map_apply(lVar13,2);
      if (iVar4 == 0) goto LAB_00108edc;
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"ERR:%s: Failed to move to DRV state %d\n",
                     "msm_pcie_cesta_enable_drv",iVar4);
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: Failed to move to DRV state %d\n",
                     "msm_pcie_cesta_enable_drv",iVar4);
      _printk(&DAT_00122ab9,"msm_pcie_cesta_enable_drv",iVar4);
      uVar6 = *(uint *)(lVar13 + 0x360);
    }
    if (uVar6 != 0) {
      uVar19 = 0;
      plVar17 = *(long **)(lVar13 + 0x368);
      do {
        lVar22 = *plVar17;
        if ((lVar22 != 0) && (*(char *)((long)plVar17 + 0x14) == '\0')) {
          clk_disable(lVar22);
          clk_unprepare(lVar22);
          uVar6 = *(uint *)(lVar13 + 0x360);
        }
        uVar19 = uVar19 + 1;
        plVar17 = plVar17 + 3;
      } while (uVar19 < uVar6);
    }
    uVar6 = *(uint *)(lVar13 + 0x370);
    if (uVar6 != 0) {
      uVar19 = 0;
      plVar17 = *(long **)(lVar13 + 0x378);
      do {
        lVar22 = *plVar17;
        if ((lVar22 != 0) && (*(char *)((long)plVar17 + 0x14) == '\0')) {
          clk_disable(lVar22);
          clk_unprepare(lVar22);
          uVar6 = *(uint *)(lVar13 + 0x370);
        }
        uVar19 = uVar19 + 1;
        plVar17 = plVar17 + 3;
      } while (uVar19 < uVar6);
    }
    if (*(int *)(lVar13 + 0xd14) == 0 && (param_5 & 4) == 0) {
      msm_pcie_drv_send_rpmsg(lVar13,pcVar20 + 0x51);
    }
    if (*(long *)(lVar13 + 0xd00) == 0) {
      uVar11 = 0;
      uVar12 = 0;
    }
    else {
      uVar11 = *(undefined4 *)(lVar13 + 0x4fc);
      uVar12 = *(undefined4 *)(lVar13 + 0x504);
    }
    iVar4 = msm_pcie_icc_vote(lVar13,uVar11,uVar12,1);
    if (iVar4 != 0) {
      mutex_unlock(lVar10);
      mutex_unlock(lVar16);
      return iVar4;
    }
    if ((*(long *)(lVar13 + 0x10) != 0) && (*(char *)(lVar13 + 0x562) == '\0')) {
      regulator_disable();
    }
    msm_pcie_vreg_deinit(lVar13);
    mutex_unlock(lVar10);
    break;
  case 1:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d requests to suspend the link\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: User of RC%d requests to suspend the link\n"
                   ,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    if (*(int *)(lVar13 + 0x4b0) != 1) {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "DBG1:%s: PCIe: RC%d: requested to suspend when link is not enabled:%d.\n",
                     "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d: requested to suspend when link is not enabled:%d.\n",
                     "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),
                     *(undefined4 *)(lVar13 + 0x4b0));
    }
    if (*(char *)(lVar13 + 0x71c) == '\0') {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "ERR:%s: PCIe: RC%d: requested to suspend when link is powered down:%d.\n",
                     "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),
                     *(undefined4 *)(lVar13 + 0x4b0));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d: requested to suspend when link is powered down:%d.\n",
                     "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),
                     *(undefined4 *)(lVar13 + 0x4b0));
      _printk(&DAT_0012bb8c,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),
              *(undefined4 *)(lVar13 + 0x4b0));
      return 0;
    }
    lVar16 = lVar13 + 0x610;
    mutex_lock(lVar16);
    lVar10 = lVar13 + 0x450;
    mutex_lock(lVar10);
    plVar17 = (long *)(lVar13 + 0x6b0);
    plVar21 = plVar17;
    do {
      plVar21 = (long *)*plVar21;
      if (plVar21 == plVar17) goto LAB_00108bc4;
    } while (plVar21[2] != param_3);
    uVar7 = __list_del_entry_valid(plVar21);
    if ((uVar7 & 1) != 0) {
      lVar22 = *plVar21;
      plVar2 = (long *)plVar21[1];
      *(long **)(lVar22 + 8) = plVar2;
      *plVar2 = lVar22;
    }
    *plVar21 = -0x2152ffffffffff00;
    plVar21[1] = -0x2152fffffffffede;
    puVar18 = *(undefined8 **)(lVar13 + 0x6c8);
    uVar7 = __list_add_valid(plVar21,puVar18,lVar13 + 0x6c0);
    if ((uVar7 & 1) != 0) {
      *(long **)(lVar13 + 0x6c8) = plVar21;
      *plVar21 = lVar13 + 0x6c0;
      plVar21[1] = (long)puVar18;
      *puVar18 = plVar21;
    }
    if (plVar21 == (long *)0x0) {
LAB_00108bc4:
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "DBG1:%s: PCIe: RC%d: ep BDF 0x%04x not in enum list\n","msm_pcie_pm_control",
                     *(undefined4 *)(lVar13 + 0x570),
                     *(uint *)(param_3 + 0x38) |
                     (uint)*(byte *)(*(long *)(param_3 + 0x10) + 0xf8) << 8);
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d: ep BDF 0x%04x not in enum list\n","msm_pcie_pm_control",
                     *(undefined4 *)(lVar13 + 0x570),
                     *(uint *)(param_3 + 0x38) |
                     (uint)*(byte *)(*(long *)(param_3 + 0x10) + 0xf8) << 8);
      plVar21 = (long *)0x0;
      bVar15 = true;
    }
    else {
      bVar15 = false;
    }
    if (((param_5 >> 4 & 1) != 0) || ((long *)*plVar17 == plVar17)) {
      *(undefined1 *)(lVar13 + 0x4b4) = 1;
      iVar4 = msm_pcie_pm_suspend(uVar14);
      if (iVar4 != 0) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: PCIe: RC%d: user failed to suspend the link.\n",
                       "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: user failed to suspend the link.\n","msm_pcie_pm_control",
                       *(undefined4 *)(lVar13 + 0x570));
        _printk(&DAT_0012e34c,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        *(undefined1 *)(lVar13 + 0x4b4) = 0;
        if (!bVar15) {
          uVar7 = __list_del_entry_valid(plVar21);
          if ((uVar7 & 1) != 0) {
            lVar22 = *plVar21;
            plVar2 = (long *)plVar21[1];
            *(long **)(lVar22 + 8) = plVar2;
            *plVar2 = lVar22;
          }
          *plVar21 = -0x2152ffffffffff00;
          plVar21[1] = -0x2152fffffffffede;
          puVar18 = *(undefined8 **)(lVar13 + 0x6b8);
          uVar7 = __list_add_valid(plVar21,puVar18,plVar17);
          if ((uVar7 & 1) != 0) {
            *(long **)(lVar13 + 0x6b8) = plVar21;
            *plVar21 = (long)plVar17;
            plVar21[1] = (long)puVar18;
            *puVar18 = plVar21;
          }
        }
      }
      mutex_unlock(lVar10);
      mutex_unlock(lVar16);
      return iVar4;
    }
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: PCIe: RC%d: request to suspend the link is rejected\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                   "%s: PCIe: RC%d: request to suspend the link is rejected\n","msm_pcie_pm_control"
                   ,*(undefined4 *)(lVar13 + 0x570));
    mutex_unlock(lVar10);
    break;
  case 2:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d requests to resume the link\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: User of RC%d requests to resume the link\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    if (*(int *)(lVar13 + 0x4b0) == 3) {
      lVar16 = *(long *)(lVar13 + 0x790);
      mutex_lock(lVar13 + 0x610);
      lVar10 = lVar13 + 0x480;
      mutex_lock(lVar10);
      if (((*(ulong *)(&DAT_00130148 + ((ulong)(*(uint *)(lVar13 + 0x570) >> 3) & 0x1ffffff8)) >>
            ((ulong)*(uint *)(lVar13 + 0x570) & 0x3f) & 1) == 0) || (*(int *)(lVar13 + 0xd14) != 0))
      {
        iVar4 = 0;
      }
      else {
        iVar4 = msm_pcie_drv_send_rpmsg(lVar13,lVar16 + 0x79);
      }
      msm_pcie_vreg_init(lVar13);
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: PCIe: RC%d:enable gdsc-core\n",
                     "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d:enable gdsc-core\n",
                     "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
      if (((*(long *)(lVar13 + 0x10) != 0) && (*(char *)(lVar13 + 0x562) == '\0')) &&
         (iVar5 = regulator_enable(), iVar5 != 0)) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: PCIe: RC%d: failed to enable GDSC: ret %d\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570),iVar5);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: failed to enable GDSC: ret %d\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570),iVar5);
        _printk(&DAT_00123abc,"msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570),iVar5);
      }
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: PCIe: RC%d:set ICC path vote\n",
                     "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d:set ICC path vote\n",
                     "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
      iVar5 = msm_pcie_icc_vote(lVar13,*(undefined4 *)(lVar13 + 0x4fc),
                                *(undefined4 *)(lVar13 + 0x504),0);
      if (iVar5 == 0) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d:turn on unsuppressible clks\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d:turn on unsuppressible clks\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570));
        if (*(int *)(lVar13 + 0x370) != 0) {
          uVar6 = 0;
          plVar17 = *(long **)(lVar13 + 0x378);
          do {
            lVar22 = *plVar17;
            if ((lVar22 != 0) && (*(char *)((long)plVar17 + 0x14) == '\0')) {
              iVar5 = clk_prepare(lVar22);
              if (iVar5 == 0) {
                iVar5 = clk_enable(lVar22);
                if (iVar5 == 0) goto LAB_00109148;
                clk_unprepare(lVar22);
              }
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570),plVar17[1]);
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570),plVar17[1]);
            }
LAB_00109148:
            uVar6 = uVar6 + 1;
            plVar17 = plVar17 + 3;
          } while (uVar6 < *(uint *)(lVar13 + 0x370));
        }
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d:turn on unsuppressible clks Done.\n",
                       "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d:turn on unsuppressible clks Done.\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570));
        if (*(long *)(lVar13 + 0xd00) != 0) {
          iVar5 = msm_pcie_cesta_map_apply(lVar13,1);
          if (iVar5 != 0) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"ERR:%s: Failed to move to D0 State %d\n"
                           ,"msm_pcie_cesta_disable_drv",iVar5);
            ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: Failed to move to D0 State %d\n",
                           "msm_pcie_cesta_disable_drv",iVar5);
            _printk(&DAT_00124c93,"msm_pcie_cesta_disable_drv",iVar5);
          }
          lVar22 = *(long *)(lVar13 + 0x380) + 0x180;
          writel_relaxed(0,lVar22);
          readl_relaxed(lVar22);
          iVar5 = msm_gpio_mpm_wake_set(*(undefined4 *)(lVar13 + 0xd18),0);
          if (iVar5 != 0) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                           "ERR:%s: Fail to remove clkreq wakeup capable%d\n",
                           "msm_pcie_cesta_disable_drv",iVar5);
            ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                           "%s: Fail to remove clkreq wakeup capable%d\n",
                           "msm_pcie_cesta_disable_drv",iVar5);
            _printk(&DAT_00121a63,"msm_pcie_cesta_disable_drv",iVar5);
          }
          iVar5 = pcie_pdc_cfg_irq(*(undefined4 *)(lVar13 + 0xd18),2,0);
          if (iVar5 != 0) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                           "ERR:%s: Fail to remove clkreq pdc wakeup capable%d\n",
                           "msm_pcie_cesta_disable_drv",iVar5);
            ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                           "%s: Fail to remove clkreq pdc wakeup capable%d\n",
                           "msm_pcie_cesta_disable_drv",iVar5);
            _printk(&DAT_00128c01,"msm_pcie_cesta_disable_drv",iVar5);
          }
        }
        uVar6 = readl_relaxed(*(long *)(lVar13 + 0x380) + 0x2b0);
        if ((uVar6 >> 1 & 1) != 0) {
          ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                         "DBG1:%s: PCIe: RC%d: CLKREQ Override detected\n","msm_pcie_drv_resume",
                         *(undefined4 *)(lVar13 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                         "%s: PCIe: RC%d: CLKREQ Override detected\n","msm_pcie_drv_resume",
                         *(undefined4 *)(lVar13 + 0x570));
          if (*(long *)(lVar13 + 0x410) != 0) {
            if (*(long *)(lVar13 + 0x430) != 0) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d: setting PCIe PIPE MUX to XO\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d: setting PCIe PIPE MUX to XO\n","msm_pcie_drv_resume",
                             *(undefined4 *)(lVar13 + 0x570));
              clk_set_parent(*(undefined8 *)(lVar13 + 0x410),*(undefined8 *)(lVar13 + 0x430));
            }
            if (*(long *)(lVar13 + 0x418) != 0) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d: setting PCIe PIPE MUX to PCIe PIPE\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d: setting PCIe PIPE MUX to PCIe PIPE\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              clk_set_parent(*(undefined8 *)(lVar13 + 0x410),*(undefined8 *)(lVar13 + 0x418));
            }
          }
          if (*(long *)(lVar13 + 0x420) != 0) {
            if (*(long *)(lVar13 + 0x430) != 0) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d: setting PCIe phy aux MUX to XO\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d: setting PCIe phy aux MUX to XO\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              clk_set_parent(*(undefined8 *)(lVar13 + 0x420),*(undefined8 *)(lVar13 + 0x430));
            }
            if (*(long *)(lVar13 + 0x428) != 0) {
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d: setting PCIe phy aux MUX to phy aux clk\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d: setting PCIe phy aux MUX to phy aux clk\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
              clk_set_parent(*(undefined8 *)(lVar13 + 0x420),*(undefined8 *)(lVar13 + 0x428));
            }
          }
        }
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: PCIe: RC%d:turn on pipe clk\n",
                       "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d:turn on pipe clk\n",
                       "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
        if (*(int *)(lVar13 + 0x360) != 0) {
          uVar19 = 0;
          plVar17 = *(long **)(lVar13 + 0x368);
          do {
            lVar22 = *plVar17;
            if ((lVar22 != 0) && (*(char *)((long)plVar17 + 0x14) == '\0')) {
              iVar5 = clk_prepare(lVar22);
              if (iVar5 == 0) {
                iVar5 = clk_enable(lVar22);
                if (iVar5 == 0) goto LAB_00109420;
                clk_unprepare(lVar22);
              }
              ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                             "DBG1:%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570),plVar17[1]);
              ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                             "%s: PCIe: RC%d:clk_prepare_enable failed for %s\n",
                             "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570),plVar17[1]);
            }
LAB_00109420:
            uVar19 = uVar19 + 1;
            plVar17 = plVar17 + 3;
          } while (uVar19 < *(uint *)(lVar13 + 0x360));
        }
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d:turn on pipe clk, Done\n","msm_pcie_drv_resume",
                       *(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d:turn on pipe clk, Done\n",
                       "msm_pcie_drv_resume",*(undefined4 *)(lVar13 + 0x570));
        if ((uVar6 >> 1 & 1) != 0) {
          lVar22 = *(long *)(lVar13 + 0x380) + 0x2b0;
          uVar6 = readl_relaxed(lVar22);
          writel_relaxed(uVar6 & 0xfffffffd,lVar22);
          readl_relaxed(lVar22);
          lVar22 = *(long *)(lVar13 + 0x380) + 0x2b0;
          uVar6 = readl_relaxed(lVar22);
          writel_relaxed(uVar6 & 0xfffffff7,lVar22);
          readl_relaxed(lVar22);
        }
        if (((*(ulong *)(&DAT_00130148 + ((ulong)(*(uint *)(lVar13 + 0x570) >> 3) & 0x1ffffff8)) >>
              ((ulong)*(uint *)(lVar13 + 0x570) & 0x3f) & 1) != 0) && (iVar4 == 0)) {
          msm_pcie_drv_send_rpmsg(lVar13,lVar16 + 0x29);
          uVar6 = *(uint *)(lVar13 + 0x570);
          puVar1 = (ulong *)(&DAT_00130148 + (ulong)(uVar6 >> 6) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar15 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar15) {
              *puVar1 = *puVar1 & (1L << ((ulong)uVar6 & 0x3f) ^ 0xffffffffffffffffU);
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        uVar6 = readl_relaxed(*(long *)(lVar13 + 0x3a0) + 0x80);
        *(uint *)(lVar13 + 0x4fc) = uVar6 >> 0x10 & 0xf;
        msm_pcie_scale_link_bandwidth(lVar13);
        *(undefined1 *)(lVar13 + 0x4b4) = 0;
        _raw_spin_lock_irq(lVar13 + 0x444);
        *(undefined1 *)(lVar13 + 0x440) = 1;
        _raw_spin_unlock_irq(lVar13 + 0x444);
        mutex_lock(lVar13 + 0x648);
        *(undefined4 *)(lVar13 + 0x4b0) = 1;
        mutex_unlock(lVar13 + 0x648);
        if (*(char *)(lVar13 + 0x560) == '\0') {
          msm_msi_config_access(*(undefined8 *)(*(long *)(lVar13 + 8) + 0x350),1);
        }
        if (*(long *)(lVar13 + 0xd00) == 0) {
          enable_irq(*(undefined4 *)(lVar13 + 0x298));
        }
        iVar5 = 0;
      }
    }
    else {
      lVar16 = lVar13 + 0x610;
      mutex_lock(lVar16);
      lVar10 = lVar13 + 0x450;
      mutex_lock(lVar10);
      plVar17 = (long *)(lVar13 + 0x6c0);
      plVar21 = plVar17;
      do {
        plVar21 = (long *)*plVar21;
        if (plVar21 == plVar17) goto LAB_00108f28;
      } while (plVar21[2] != param_3);
      uVar7 = __list_del_entry_valid(plVar21);
      if ((uVar7 & 1) != 0) {
        lVar22 = *plVar21;
        plVar2 = (long *)plVar21[1];
        *(long **)(lVar22 + 8) = plVar2;
        *plVar2 = lVar22;
      }
      *plVar21 = -0x2152ffffffffff00;
      plVar21[1] = -0x2152fffffffffede;
      puVar18 = *(undefined8 **)(lVar13 + 0x6b8);
      uVar7 = __list_add_valid(plVar21,puVar18,lVar13 + 0x6b0);
      if ((uVar7 & 1) != 0) {
        *(long **)(lVar13 + 0x6b8) = plVar21;
        *plVar21 = lVar13 + 0x6b0;
        plVar21[1] = (long)puVar18;
        *puVar18 = plVar21;
      }
      if (plVar21 == (long *)0x0) {
LAB_00108f28:
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d: ep BDF 0x%04x not in susp list\n","msm_pcie_pm_control"
                       ,*(undefined4 *)(lVar13 + 0x570),
                       *(uint *)(param_3 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_3 + 0x10) + 0xf8) << 8);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: ep BDF 0x%04x not in susp list\n","msm_pcie_pm_control",
                       *(undefined4 *)(lVar13 + 0x570),
                       *(uint *)(param_3 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_3 + 0x10) + 0xf8) << 8);
        plVar21 = (long *)0x0;
        bVar15 = true;
      }
      else {
        bVar15 = false;
      }
      mutex_unlock(lVar10);
      if (*(char *)(lVar13 + 0x71c) != '\0') {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: PCIe: RC%d: requested to resume when link is already powered on.\n",
                       "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: requested to resume when link is already powered on.\n",
                       "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        _printk(&DAT_0012d28a,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        break;
      }
      iVar5 = msm_pcie_pm_resume(uVar14);
      if (iVar5 == 0) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d: user succeeded to resume the link.\n",
                       "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: user succeeded to resume the link.\n","msm_pcie_pm_control",
                       *(undefined4 *)(lVar13 + 0x570));
        *(undefined1 *)(lVar13 + 0x4b4) = 0;
        goto LAB_001095c8;
      }
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "ERR:%s: PCIe: RC%d: user failed to resume the link.\n","msm_pcie_pm_control",
                     *(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d: user failed to resume the link.\n","msm_pcie_pm_control",
                     *(undefined4 *)(lVar13 + 0x570));
      _printk(&DAT_00121323,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
      mutex_lock(lVar10);
      if (!bVar15) {
        uVar7 = __list_del_entry_valid(plVar21);
        if ((uVar7 & 1) != 0) {
          lVar16 = *plVar21;
          plVar2 = (long *)plVar21[1];
          *(long **)(lVar16 + 8) = plVar2;
          *plVar2 = lVar16;
        }
        *plVar21 = -0x2152ffffffffff00;
        plVar21[1] = -0x2152fffffffffede;
        puVar18 = *(undefined8 **)(lVar13 + 0x6c8);
        uVar7 = __list_add_valid(plVar21,puVar18,plVar17);
        if ((uVar7 & 1) != 0) {
          *(long **)(lVar13 + 0x6c8) = plVar21;
          *plVar21 = (long)plVar17;
          plVar21[1] = (long)puVar18;
          *puVar18 = plVar21;
        }
      }
    }
    mutex_unlock(lVar10);
LAB_001095c8:
    mutex_unlock(lVar13 + 0x610);
    return iVar5;
  case 3:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d requests to keep the link always alive.\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                   "%s: User of RC%d requests to keep the link always alive.\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    uVar14 = _raw_spin_lock_irqsave(lVar13 + 0x444);
    *(undefined8 *)(lVar13 + 0x448) = uVar14;
    if (*(char *)(lVar13 + 0x6a0) == '\0') {
      iVar4 = 0;
      *(undefined1 *)(lVar13 + 0x4b5) = 1;
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "ERR:%s: PCIe: RC%d Link has been suspended before request\n",
                     "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: PCIe: RC%d Link has been suspended before request\n","msm_pcie_pm_control"
                     ,*(undefined4 *)(lVar13 + 0x570));
      _printk(&DAT_00124553,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
      uVar14 = *(undefined8 *)(lVar13 + 0x448);
      iVar4 = -1;
    }
    _raw_spin_unlock_irqrestore(lVar13 + 0x444,uVar14);
    return iVar4;
  case 4:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d cancels the request of alive link.\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                   "%s: User of RC%d cancels the request of alive link.\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    lVar16 = lVar13 + 0x444;
    uVar14 = _raw_spin_lock_irqsave(lVar16);
    *(undefined8 *)(lVar13 + 0x448) = uVar14;
    *(undefined1 *)(lVar13 + 0x4b5) = 0;
    goto LAB_00108b28;
  case 5:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d requests handling link down.\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: User of RC%d requests handling link down.\n"
                   ,"msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570));
    lVar16 = lVar13 + 0x640;
    uVar14 = _raw_spin_lock_irqsave(lVar16);
    msm_pcie_handle_linkdown(lVar13);
LAB_00108b28:
    _raw_spin_unlock_irqrestore(lVar16,uVar14);
    return 0;
  case 6:
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                   "DBG1:%s: User of RC%d requests handling drv pc options %u.\n",
                   "msm_pcie_pm_control",*(undefined4 *)(lVar13 + 0x570),param_5);
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                   "%s: User of RC%d requests handling drv pc options %u.\n","msm_pcie_pm_control",
                   *(undefined4 *)(lVar13 + 0x570),param_5);
    if (*(long *)(lVar13 + 0xd00) != 0) {
      return 0;
    }
    lVar16 = lVar13 + 0x830;
    mutex_lock(lVar16);
    *(uint *)(lVar13 + 0x828) = param_5 & 8;
    if ((*(char **)(lVar13 + 0x790) != (char *)0x0) && (**(char **)(lVar13 + 0x790) != '\0')) {
      if ((param_5 & 8) == 0) {
        queue_work_on(0x20,mpcie_wq,lVar13 + 0x798);
        flush_work(lVar13 + 0x798);
      }
      else {
        queue_work_on(0x20,mpcie_wq,lVar13 + 0x7c8);
      }
    }
  }
  mutex_unlock(lVar16);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_pm_suspend @ 00109c98 size=1312
// signature: undefined msm_pcie_pm_suspend(void)
// callers: [msm_pcie_fixup_suspend, msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_pcie_pm_suspend(long param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined *puVar9;
  long lVar10;
  long lVar11;
  char *pcVar12;
  long lVar13;
  long lVar14;
  
  lVar13 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar13 != 0) {
    ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_pm_suspend",
                   *(undefined4 *)(lVar13 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: RC%d: entry\n","msm_pcie_pm_suspend",
                   *(undefined4 *)(lVar13 + 0x570));
  }
  uVar7 = _raw_spin_lock_irqsave(lVar13 + 0x640);
  *(undefined1 *)(lVar13 + 0x6a0) = 1;
  _raw_spin_unlock_irqrestore(lVar13 + 0x640,uVar7);
  if ((*(char *)(lVar13 + 0x758) != '\0') && ((*(ulong *)(lVar13 + 0x760) & 1) != 0)) {
    if (lVar13 != 0) {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "DBG1:%s: RC%d: cancel link_recover_wq at pm suspend\n","msm_pcie_pm_suspend",
                     *(undefined4 *)(lVar13 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                     "%s: RC%d: cancel link_recover_wq at pm suspend\n","msm_pcie_pm_suspend",
                     *(undefined4 *)(lVar13 + 0x570));
    }
    cancel_work_sync(lVar13 + 0x760);
  }
  if (*(char *)(lVar13 + 0x71c) == '\0') {
    if (lVar13 != 0) {
      ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                     "DBG1:%s: PCIe: power of RC%d has been turned off.\n","msm_pcie_pm_suspend",
                     *(undefined4 *)(lVar13 + 0x570));
      uVar7 = *(undefined8 *)(lVar13 + 0x720);
      pcVar12 = "%s: PCIe: power of RC%d has been turned off.\n";
LAB_0010a11c:
      ipc_log_string(uVar7,pcVar12,"msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
    }
LAB_0010a128:
    iVar4 = 0;
  }
  else {
    uVar8 = msm_pcie_confirm_linkup(lVar13,1,1,param_1);
    if ((uVar8 & 1) == 0) {
      kfree(*(undefined8 *)(lVar13 + 0x4c0));
      *(undefined8 *)(lVar13 + 0x4c0) = 0;
      if (lVar13 == 0) {
        iVar4 = pci_load_saved_state(param_1,_DAT_000004b8);
        if (iVar4 == 0) goto LAB_00109f18;
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "DBG1:%s: PCIe: RC%d: load default config space\n","msm_pcie_pm_suspend",
                       *(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: load default config space\n"
                       ,"msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
        iVar4 = pci_load_saved_state(param_1,*(undefined8 *)(lVar13 + 0x4b8));
        if (iVar4 == 0) goto LAB_00109eb0;
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: PCIe: RC%d: fail to load default state:%d.\n","msm_pcie_pm_suspend",
                       *(undefined4 *)(lVar13 + 0x570),iVar4);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),
                       "%s: PCIe: RC%d: fail to load default state:%d.\n","msm_pcie_pm_suspend",
                       *(undefined4 *)(lVar13 + 0x570),iVar4);
      }
      uVar2 = *(undefined4 *)(lVar13 + 0x570);
      puVar9 = &DAT_0012f614;
    }
    else {
      if (lVar13 == 0) {
        iVar4 = pci_save_state(param_1);
        if (iVar4 == 0) goto LAB_00109f18;
      }
      else {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: PCIe: RC%d: save config space\n",
                       "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: save config space\n",
                       "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
        iVar4 = pci_save_state(param_1);
        if (iVar4 == 0) {
LAB_00109eb0:
          ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: PCIe: RC%d: store saved state\n",
                         "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: store saved state\n",
                         "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
LAB_00109f18:
          uVar7 = pci_store_saved_state(param_1);
          *(undefined8 *)(lVar13 + 0x4c0) = uVar7;
          uVar7 = _raw_spin_lock_irqsave(lVar13 + 0x444);
          *(undefined8 *)(lVar13 + 0x448) = uVar7;
          *(undefined1 *)(lVar13 + 0x440) = 0;
          _raw_spin_unlock_irqrestore(lVar13 + 0x444,uVar7);
          writel_relaxed(0x10,*(long *)(lVar13 + 0x390) + 4);
          DataSynchronizationBarrier(3,2,0);
          if (lVar13 != 0) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                           "DBG1:%s: RC%d: PME_TURNOFF_MSG is sent out\n","msm_pcie_pm_suspend",
                           *(undefined4 *)(lVar13 + 0x570));
            ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: RC%d: PME_TURNOFF_MSG is sent out\n"
                           ,"msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
          }
          lVar14 = *(long *)(lVar13 + 0x698);
          lVar10 = ktime_get();
          uVar5 = readl(*(long *)(lVar13 + 0x380) + 0x28);
          if ((uVar5 & 0x380) != 0x180) {
            do {
              if ((lVar14 != 0) && (lVar11 = ktime_get(), lVar10 + lVar14 * 1000 < lVar11)) {
                uVar5 = readl(*(long *)(lVar13 + 0x380) + 0x28);
                break;
              }
              usleep_range_state(0x8cb,9000,2);
              Yield();
              uVar5 = readl(*(long *)(lVar13 + 0x380) + 0x28);
            } while ((uVar5 & 0x380) != 0x180);
          }
          if (lVar13 != 0) {
            uVar7 = *(undefined8 *)(lVar13 + 0x728);
            uVar2 = *(undefined4 *)(lVar13 + 0x570);
            uVar6 = readl_relaxed(*(long *)(lVar13 + 0x380) + 0x28);
            ipc_log_string(uVar7,"DBG1:%s: RC%d: PCIE20_PARF_PM_STTS_1 is 0x%x.\n",
                           "msm_pcie_pm_suspend",uVar2,uVar6);
            uVar7 = *(undefined8 *)(lVar13 + 0x720);
            uVar2 = *(undefined4 *)(lVar13 + 0x570);
            uVar6 = readl_relaxed(*(long *)(lVar13 + 0x380) + 0x28);
            ipc_log_string(uVar7,"%s: RC%d: PCIE20_PARF_PM_STTS_1 is 0x%x.\n","msm_pcie_pm_suspend",
                           uVar2,uVar6);
            bVar3 = (uVar5 & 0x380) != 0x180;
            pcVar12 = "DBG1:%s: RC%d: PM_Enter_L23 is received\n";
            if (bVar3) {
              pcVar12 = "DBG1:%s: RC%d: PM_Enter_L23 is NOT received\n";
            }
            pcVar1 = "%s: RC%d: PM_Enter_L23 is received\n";
            if (bVar3) {
              pcVar1 = "%s: RC%d: PM_Enter_L23 is NOT received\n";
            }
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),pcVar12,"msm_pcie_pm_suspend",
                           *(undefined4 *)(lVar13 + 0x570));
            ipc_log_string(*(undefined8 *)(lVar13 + 0x720),pcVar1,"msm_pcie_pm_suspend",
                           *(undefined4 *)(lVar13 + 0x570));
          }
          if ((*(char *)(lVar13 + 0x738) != '\0') && (*(long *)(lVar13 + 0x750) != 0)) {
            pinctrl_select_state(*(undefined8 *)(lVar13 + 0x740));
          }
          msm_pcie_disable(lVar13);
          if (lVar13 != 0) {
            ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"DBG1:%s: RC%d: exit\n",
                           "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570));
            uVar7 = *(undefined8 *)(lVar13 + 0x720);
            pcVar12 = "%s: RC%d: exit\n";
            goto LAB_0010a11c;
          }
          goto LAB_0010a128;
        }
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),
                       "ERR:%s: PCIe: RC%d: fail to save state:%d.\n","msm_pcie_pm_suspend",
                       *(undefined4 *)(lVar13 + 0x570),iVar4);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: PCIe: RC%d: fail to save state:%d.\n",
                       "msm_pcie_pm_suspend",*(undefined4 *)(lVar13 + 0x570),iVar4);
      }
      uVar2 = *(undefined4 *)(lVar13 + 0x570);
      puVar9 = &DAT_0012e7fd;
    }
    _printk(puVar9,"msm_pcie_pm_suspend",uVar2,iVar4);
    *(undefined1 *)(lVar13 + 0x6a0) = 0;
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_pcie_pm_resume @ 0010a1b8 size=528
// signature: undefined msm_pcie_pm_resume(void)
// callers: [msm_pcie_fixup_resume_early, msm_pcie_fixup_resume, msm_pcie_pm_control]
//------------------------------------------------------------

int msm_pcie_pm_resume(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar3 != 0) {
    ipc_log_string(*(undefined8 *)(lVar3 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_pm_resume",
                   *(undefined4 *)(lVar3 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar3 + 0x720),"%s: RC%d: entry\n","msm_pcie_pm_resume",
                   *(undefined4 *)(lVar3 + 0x570));
  }
  if ((*(char *)(lVar3 + 0x738) != '\0') && (*(long *)(lVar3 + 0x748) != 0)) {
    pinctrl_select_state(*(undefined8 *)(lVar3 + 0x740));
  }
  uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x444);
  *(undefined8 *)(lVar3 + 0x448) = uVar2;
  *(undefined1 *)(lVar3 + 0x440) = 1;
  _raw_spin_unlock_irqrestore(lVar3 + 0x444,uVar2);
  iVar1 = msm_pcie_enable(lVar3);
  if (iVar1 == 0) {
    *(undefined1 *)(lVar3 + 0x6a0) = 0;
    if (lVar3 == 0) {
      pci_set_power_state(param_1,0);
      pci_load_and_free_saved_state(param_1,0x4c0);
      pci_restore_state(param_1);
    }
    else {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                     "DBG1:%s: dev->bus->number = %d dev->bus->primary = %d\n","msm_pcie_pm_resume",
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf9));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                     "%s: dev->bus->number = %d dev->bus->primary = %d\n","msm_pcie_pm_resume",
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf9));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),"DBG1:%s: RC%d: restore config space\n",
                     "msm_pcie_pm_resume",*(undefined4 *)(lVar3 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),"%s: RC%d: restore config space\n",
                     "msm_pcie_pm_resume",*(undefined4 *)(lVar3 + 0x570));
      pci_set_power_state(param_1,0);
      pci_load_and_free_saved_state(param_1,lVar3 + 0x4c0);
      pci_restore_state(param_1);
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_pm_resume",
                     *(undefined4 *)(lVar3 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),"%s: RC%d: exit\n","msm_pcie_pm_resume",
                     *(undefined4 *)(lVar3 + 0x570));
    }
  }
  else {
    if (lVar3 != 0) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                     "ERR:%s: PCIe: RC%d fail to enable PCIe link in resume.\n","msm_pcie_pm_resume"
                     ,*(undefined4 *)(lVar3 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                     "%s: PCIe: RC%d fail to enable PCIe link in resume.\n","msm_pcie_pm_resume",
                     *(undefined4 *)(lVar3 + 0x570));
    }
    _printk(&DAT_0012f646,"msm_pcie_pm_resume",*(undefined4 *)(lVar3 + 0x570));
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_pcie_handle_linkdown @ 0010a3c8 size=868
// signature: undefined msm_pcie_handle_linkdown(void)
// callers: [msm_pcie_pm_control, handle_global_irq]
//------------------------------------------------------------

void msm_pcie_handle_linkdown(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  char *pcVar5;
  
  if (*(int *)(param_1 + 0x4b0) != 4) {
    *(undefined4 *)(param_1 + 0x4b0) = 4;
    if (*(int *)(param_1 + 0x148) != 0) {
      gpio_to_desc();
      iVar2 = gpiod_get_raw_value();
      if (iVar2 != 0) {
        if (param_1 == 0) {
          return;
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DUMP:%s: Linkdown due to card removal\n",
                       "msm_pcie_handle_linkdown");
        return;
      }
    }
    if ((*(char *)(param_1 + 0x6a0) == '\0') && (*(char *)(param_1 + 0xda8) == '\0')) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DUMP:%s: PCIe:Linkdown IRQ for RC%d Dumping PCIe registers\n",
                       "msm_pcie_handle_linkdown",*(undefined4 *)(param_1 + 0x570));
      }
      pcie_phy_dump(param_1);
      pcie_parf_dump(param_1);
      pcie_dm_core_dump(param_1);
      pcie_sm_dump(param_1);
      if (((*(long *)(param_1 + 0xd00) != 0) && (iVar2 = crm_dump_regs("pcie_crm"), param_1 != 0))
         && (iVar2 != 0)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n","pcie_crm_dump",
                       *(undefined4 *)(param_1 + 0x570),iVar2);
      }
    }
    if (*(char *)(param_1 + 0x561) == '\0') {
LAB_0010a5e8:
      if ((msm_pcie_keep_resources_on >> ((ulong)*(uint *)(param_1 + 0x570) & 0x3f) & 1) == 0) {
        msm_pcie_config_perst(param_1,1);
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"ERR:%s: PCIe link is down for RC%d\n",
                       "msm_pcie_handle_linkdown",*(undefined4 *)(param_1 + 0x570));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe link is down for RC%d\n",
                       "msm_pcie_handle_linkdown",*(undefined4 *)(param_1 + 0x570));
      }
      _printk(&DAT_0012119e,"msm_pcie_handle_linkdown",*(undefined4 *)(param_1 + 0x570));
      if (*(char *)(param_1 + 0x554) != '\0') {
                    /* WARNING: Subroutine does not return */
        panic("User has chosen to panic on linkdown\n");
      }
      msm_pcie_notify_client(param_1,1);
      if (msm_pcie_keep_resources_on == 0) {
        queue_work_on(0x20,mpcie_wq,param_1 + 0x5e0);
      }
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DUMP:%s: PCIe:Linkdown IRQ for RC%d attempt recovery\n",
                       "msm_pcie_linkdown_recovery",*(undefined4 *)(param_1 + 0x570));
      }
      iVar2 = 99;
      do {
        uVar3 = readl_relaxed(*(long *)(param_1 + 0x380) + 0x230);
        if ((uVar3 >> 8 & 1) != 0) {
          if (param_1 == 0) {
            if (iVar2 == 0) goto LAB_0010a5e8;
          }
          else {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "DBG1:%s: flush complete (%d), status:%x\n","msm_pcie_linkdown_recovery",
                           iVar2,uVar3);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: flush complete (%d), status:%x\n",
                           "msm_pcie_linkdown_recovery",iVar2,uVar3);
            if (iVar2 == 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: flush timeout, status:%x\n",
                             "msm_pcie_linkdown_recovery",uVar3);
              uVar4 = *(undefined8 *)(param_1 + 0x720);
              pcVar5 = "%s: flush timeout, status:%x\n";
              goto LAB_0010a5d4;
            }
          }
          break;
        }
        __const_udelay(0xa7c6);
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
      lVar1 = *(long *)(param_1 + 0x380) + 0x1b0;
      uVar3 = readl_relaxed(lVar1);
      writel_relaxed(uVar3 | 0x400,lVar1);
      readl_relaxed(lVar1);
      iVar2 = 99;
      do {
        uVar3 = readl_relaxed(*(long *)(param_1 + 0x380) + 0x1b0);
        if ((uVar3 >> 0xb & 1) == 0) {
          if (param_1 == 0) {
            if (iVar2 != 0) {
              return;
            }
          }
          else {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: flush mode clear:%d, %x\n",
                           "msm_pcie_linkdown_recovery",iVar2,uVar3);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: flush mode clear:%d, %x\n",
                           "msm_pcie_linkdown_recovery",iVar2,uVar3);
            if (iVar2 != 0) {
              return;
            }
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "DBG1:%s: flush-mode timeout, status:%x\n","msm_pcie_linkdown_recovery",
                           uVar3);
            uVar4 = *(undefined8 *)(param_1 + 0x720);
            pcVar5 = "%s: flush-mode timeout, status:%x\n";
LAB_0010a5d4:
            ipc_log_string(uVar4,pcVar5,"msm_pcie_linkdown_recovery",uVar3);
          }
          goto LAB_0010a5e8;
        }
        __const_udelay(0xa7c6);
        iVar2 = iVar2 + -1;
      } while (iVar2 != -1);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_l1ss_timeout_disable @ 0010a730 size=108
// signature: undefined msm_pcie_l1ss_timeout_disable(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_l1ss_timeout_disable(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  lVar1 = *(long *)(lVar3 + 0x380) + 400;
  uVar2 = readl_relaxed(lVar1);
  writel_relaxed(uVar2 & 0xfffffffe,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(lVar3 + 0x380) + 0x180;
  writel_relaxed(0,lVar1);
  readl_relaxed(lVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_l1ss_timeout_enable @ 0010a7a0 size=188
// signature: undefined msm_pcie_l1ss_timeout_enable(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_l1ss_timeout_enable(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  lVar1 = *(long *)(lVar3 + 0x380) + 0x180;
  writel_relaxed(0x80000000,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(lVar3 + 0x380) + 0x228;
  uVar2 = readl_relaxed(lVar1);
  writel_relaxed(uVar2 | 0x200,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(lVar3 + 0x380) + 400;
  uVar2 = readl_relaxed(lVar1);
  writel_relaxed(uVar2 | 1,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(lVar3 + 0x380) + 0x180;
  writel_relaxed(*(int *)(lVar3 + 0x54c) * 100000 | 0x80000000,lVar1);
  readl_relaxed(lVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_register_event @ 0010a860 size=396
// signature: undefined msm_pcie_register_event(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_register_event(long *param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined *puVar5;
  long *plVar6;
  long lVar7;
  undefined8 *puVar8;
  long lVar9;
  
  if (param_1 == (long *)0x0) {
    puVar5 = &DAT_0012f7c6;
  }
  else {
    lVar7 = param_1[3];
    if (lVar7 == 0) {
      puVar5 = &DAT_00120ae5;
    }
    else {
      lVar9 = *(long *)(*(long *)(*(long *)(lVar7 + 0x10) + 0xe8) + 200);
      if (lVar9 != 0) {
        lVar1 = lVar9 + 0x718;
        uVar3 = _raw_spin_lock_irqsave(lVar1);
        plVar2 = (long *)(lVar9 + 0x708);
        plVar6 = plVar2;
        do {
          plVar6 = (long *)*plVar6;
          if (plVar6 == plVar2) {
            puVar8 = *(undefined8 **)(lVar9 + 0x710);
            uVar4 = __list_add_valid(param_1,puVar8,plVar2);
            if ((uVar4 & 1) != 0) {
              *(long **)(lVar9 + 0x710) = param_1;
              *param_1 = (long)plVar2;
              param_1[1] = (long)puVar8;
              *puVar8 = param_1;
            }
            _raw_spin_unlock_irqrestore(lVar1,uVar3);
            if (*(char *)(lVar9 + 0x888) != '\0') {
              queue_work_on(0x20,mpcie_wq,lVar9 + 0x7f8);
            }
            return 0;
          }
        } while (plVar6[3] != param_1[3]);
        ipc_log_string(*(undefined8 *)(lVar9 + 0x728),
                       "ERR:%s: PCIe: RC%d: EP BDF 0x%4x already registered\n",
                       "msm_pcie_register_event",*(undefined4 *)(lVar9 + 0x570),
                       *(uint *)(lVar7 + 0x38) |
                       (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8);
        ipc_log_string(*(undefined8 *)(lVar9 + 0x720),
                       "%s: PCIe: RC%d: EP BDF 0x%4x already registered\n","msm_pcie_register_event"
                       ,*(undefined4 *)(lVar9 + 0x570),
                       *(uint *)(lVar7 + 0x38) |
                       (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8);
        _printk(&DAT_0012d30d,"msm_pcie_register_event",*(undefined4 *)(lVar9 + 0x570),
                *(uint *)(lVar7 + 0x38) | (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8);
        _raw_spin_unlock(lVar1);
        return 0xffffffef;
      }
      puVar5 = &DAT_0012c28c;
    }
  }
  _printk(puVar5);
  return 0xffffffed;
}



//------------------------------------------------------------
// msm_pcie_deregister_event @ 0010a9f0 size=452
// signature: undefined msm_pcie_deregister_event(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_deregister_event(long *param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined *puVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  
  if (param_1 == (long *)0x0) {
    puVar5 = &DAT_0012ac4b;
  }
  else {
    lVar7 = param_1[3];
    if (lVar7 != 0) {
      lVar8 = *(long *)(*(long *)(*(long *)(lVar7 + 0x10) + 0xe8) + 200);
      if (lVar8 == 0) {
        _printk(&DAT_0012bc3f,"msm_pcie_deregister_event",
                "PCIe: did not find RC for pci endpoint device.\n");
        return 0xffffffed;
      }
      lVar1 = lVar8 + 0x718;
      uVar3 = _raw_spin_lock_irqsave(lVar1);
      plVar6 = (long *)(lVar8 + 0x708);
      do {
        plVar6 = (long *)*plVar6;
        if (plVar6 == (long *)(lVar8 + 0x708)) {
          _raw_spin_unlock_irqrestore(lVar1,uVar3);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "DBG1:%s: PCIe: RC%d: Failed to deregister event for BDF 0x%04x\n",
                         "msm_pcie_deregister_event",*(undefined4 *)(lVar8 + 0x570),
                         *(uint *)(lVar7 + 0x38) |
                         (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: Failed to deregister event for BDF 0x%04x\n",
                         "msm_pcie_deregister_event",*(undefined4 *)(lVar8 + 0x570),
                         *(uint *)(lVar7 + 0x38) |
                         (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8);
          return 0xffffffea;
        }
      } while (plVar6[3] != param_1[3]);
      uVar4 = __list_del_entry_valid(param_1);
      if ((uVar4 & 1) != 0) {
        lVar2 = *param_1;
        plVar6 = (long *)param_1[1];
        *(long **)(lVar2 + 8) = plVar6;
        *plVar6 = lVar2;
      }
      *param_1 = -0x2152ffffffffff00;
      param_1[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
      ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Event deregistered for BDF 0x%04x\n",
                     "msm_pcie_deregister_event",*(undefined4 *)(lVar8 + 0x570),
                     *(uint *)(lVar7 + 0x38) | (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8)
      ;
      ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                     "%s: PCIe: RC%d: Event deregistered for BDF 0x%04x\n",
                     "msm_pcie_deregister_event",*(undefined4 *)(lVar8 + 0x570),
                     *(uint *)(lVar7 + 0x38) | (uint)*(byte *)(*(long *)(lVar7 + 0x10) + 0xf8) << 8)
      ;
      return 0;
    }
    puVar5 = &DAT_0012ac71;
  }
  _printk(puVar5);
  return 0xffffffed;
}



//------------------------------------------------------------
// msm_pcie_show_status @ 0010abb4 size=4548
// signature: undefined msm_pcie_show_status(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pcie_show_status(long param_1)

{
  undefined *puVar1;
  char *pcVar2;
  
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_00000579 != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001285b1,"msm_pcie_show_status",_DAT_00000570,puVar1);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x579) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe: RC%d is %s enumerated\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x570),puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x579) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001285b1,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x570),puVar1);
    pcVar2 = "enabled";
    if (*(int *)(param_1 + 0x4b0) != 1) {
      pcVar2 = "disabled";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe: link is %s\n",
                   "msm_pcie_show_status",pcVar2);
  }
  pcVar2 = "enabled";
  if (*(int *)(param_1 + 0x4b0) != 1) {
    pcVar2 = "disabled";
  }
  _printk(&DAT_0012352e,"msm_pcie_show_status",pcVar2);
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_00000440 != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001246a1,"msm_pcie_show_status",puVar1);
    _printk(&DAT_0012d3b9,"msm_pcie_show_status",DAT_00000738);
    _printk(&DAT_00128e4a,"msm_pcie_show_status",_DAT_0000054c);
    _printk(&DAT_0012e96f,"msm_pcie_show_status",DAT_000004b4);
    _printk(&DAT_0012efe0,"msm_pcie_show_status",_DAT_000006d0);
    _printk(&DAT_0012ad7c,"msm_pcie_show_status",_DAT_000006d4);
    _printk(&DAT_001204b1,"msm_pcie_show_status",_DAT_00000360);
    _printk(&DAT_00127692,"msm_pcie_show_status",_DAT_00000370);
    _printk(&DAT_00126d0f,"msm_pcie_show_status",DAT_000004b5);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x440) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: cfg_access is %s allowed\n",
                   "msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x440) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001246a1,"msm_pcie_show_status",puVar1);
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: use_pinctrl is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x738));
    _printk(&DAT_0012d3b9,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x738));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: aux_clk_freq is %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x54c));
    _printk(&DAT_00128e4a,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x54c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: user_suspend is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4b4));
    _printk(&DAT_0012e96f,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4b4));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: num_parf_testbus_sel is 0x%x",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x6d0));
    _printk(&DAT_0012efe0,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x6d0));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: phy_len is %d",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x6d4));
    _printk(&DAT_0012ad7c,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x6d4));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: num_pipe_clk: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x360));
    _printk(&DAT_001204b1,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x360));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: num_clk: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x370));
    _printk(&DAT_00127692,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x370));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: disable_pc is %d",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4b5));
    _printk(&DAT_00126d0f,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4b5));
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4d9) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l0s_supported is %s supported\n",
                   "msm_pcie_show_status",puVar1);
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x4d9) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_001276a5,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_000004da != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_00128e64,"msm_pcie_show_status",puVar1);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4da) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l1_supported is %s supported\n",
                   "msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4da) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_00128e64,"msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4db) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l1ss_supported is %s supported\n",
                   "msm_pcie_show_status",puVar1);
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x4db) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_00126d51,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_000004dc != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001246c1,"msm_pcie_show_status",puVar1);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4dc) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DBG_FS:%s: l1_1_pcipm_supported is %s supported\n","msm_pcie_show_status",puVar1
                  );
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4dc) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_001246c1,"msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4dd) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DBG_FS:%s: l1_2_pcipm_supported is %s supported\n","msm_pcie_show_status",puVar1
                  );
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x4dd) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_0012f003,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_000004de != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_00125dbf,"msm_pcie_show_status",puVar1);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4de) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DBG_FS:%s: l1_1_aspm_supported is %s supported\n","msm_pcie_show_status",puVar1)
    ;
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4de) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_00125dbf,"msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4df) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DBG_FS:%s: l1_2_aspm_supported is %s supported\n","msm_pcie_show_status",puVar1)
    ;
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x4df) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_0012bcca,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    _printk(&DAT_00122dcd,"msm_pcie_show_status",_DAT_000004e0);
    _printk(&DAT_00127e50,"msm_pcie_show_status",_DAT_000004e4);
    _printk(&DAT_0012a3c9,"msm_pcie_show_status",DAT_000004e8);
    _printk(&DAT_0012e989,"msm_pcie_show_status",DAT_000004e9);
    _printk(&DAT_0012258e,"msm_pcie_show_status",DAT_000004ea);
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l1_2_th_scale is %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4e0));
    _printk(&DAT_00122dcd,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4e0));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l1_2_th_value is %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4e4));
    _printk(&DAT_00127e50,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4e4));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: common_clk_en is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4e8));
    _printk(&DAT_0012a3c9,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4e8));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: clk_power_manage_en is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4e9));
    _printk(&DAT_0012e989,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4e9));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: aux_clk_sync is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4ea));
    _printk(&DAT_0012258e,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x4ea));
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x4eb) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: AER is %s enable\n",
                   "msm_pcie_show_status",puVar1);
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x4eb) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_0012e3f5,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    _printk(&DAT_0012ca76,"msm_pcie_show_status",_DAT_00000558);
    _printk(&DAT_0012a3e4,"msm_pcie_show_status",_DAT_0000055c);
    _printk(&DAT_00128ea2,"msm_pcie_show_status",_DAT_00000574);
    _printk(&DAT_0012577a,"msm_pcie_show_status",DAT_00000578);
    _printk(&DAT_00123d9d,"msm_pcie_show_status",DAT_00000554);
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: boot_option is 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x558));
    _printk(&DAT_0012ca76,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x558));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: link_speed_override is 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x55c));
    _printk(&DAT_0012a3e4,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x55c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: phy_ver is %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x574));
    _printk(&DAT_00128ea2,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x574));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: drv_ready is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x578));
    _printk(&DAT_0012577a,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x578));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: linkdown_panic is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x554));
    _printk(&DAT_00123d9d,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x554));
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x6a0) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: the link is %s suspending\n",
                   "msm_pcie_show_status",puVar1);
  }
  puVar1 = &DAT_0012768e;
  if (*(char *)(param_1 + 0x6a0) != '\0') {
    puVar1 = &DAT_00125754;
  }
  _printk(&DAT_00123db9,"msm_pcie_show_status",puVar1);
  if (param_1 == 0) {
    puVar1 = &DAT_0012768e;
    if (DAT_0000071c != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_0012f04f,"msm_pcie_show_status",puVar1);
    _printk(&DAT_00126d93,"msm_pcie_show_status",_DAT_000004ec);
    _printk(&DAT_00126dae,"msm_pcie_show_status",_DAT_00000508);
    _printk(&DAT_0012e40d,"msm_pcie_show_status",_DAT_0000050c);
    _printk(&DAT_00123581,"msm_pcie_show_status",_DAT_00000510);
    _printk(&DAT_001285ec,"msm_pcie_show_status",_DAT_00000514);
    _printk(&DAT_00122e10,"msm_pcie_show_status",DAT_00000563);
    _printk(&DAT_0012f06f,"msm_pcie_show_status",DAT_0000056c);
    _printk(&DAT_001294e3,"msm_pcie_show_status",_DAT_00000518);
    _printk(&DAT_001276f3,"msm_pcie_show_status",_DAT_0000051c);
    _printk(&DAT_00125791,"msm_pcie_show_status",_DAT_00000520);
    _printk(&DAT_001257b4,"msm_pcie_show_status",_DAT_0000052c);
    _printk(&DAT_00126dbf,"msm_pcie_show_status",_DAT_00000530);
    _printk(&DAT_00121cd3,"msm_pcie_show_status",_DAT_00000534);
    _printk(&DAT_001264db,"msm_pcie_show_status",_DAT_00000538);
    _printk(&DAT_0012770d,"msm_pcie_show_status",_DAT_0000053c);
    _printk(&DAT_0012d45a,"msm_pcie_show_status",_DAT_00000540);
    _printk(&DAT_0012d47a,"msm_pcie_show_status",_DAT_00000544);
    _printk(&DAT_001214a9,"msm_pcie_show_status",_DAT_00000548);
    _printk(&DAT_00120510,"msm_pcie_show_status",_DAT_00000680);
    _printk(&DAT_00127e90,"msm_pcie_show_status",_DAT_000006a8);
    _printk(&DAT_00126512,"msm_pcie_show_status",_DAT_000004f0);
    _printk(&DAT_0012e9aa,"msm_pcie_show_status",_DAT_00000678);
    _printk(&DAT_0012cab0,"msm_pcie_show_status",_DAT_000004f4);
    _printk(&DAT_00129502,"msm_pcie_show_status",_DAT_000004fc);
    _printk(&DAT_00126532,"msm_pcie_show_status",_DAT_00000500);
    _printk(&DAT_0012654f,"msm_pcie_show_status",_DAT_00000504);
    _printk(&DAT_0012d49a,"msm_pcie_show_status",_DAT_00000404);
    _printk(&DAT_0012b512,"msm_pcie_show_status",_DAT_00000688);
    _printk(&DAT_00127726,"msm_pcie_show_status",_DAT_00000690);
    _printk(&DAT_00120573,"msm_pcie_show_status",_DAT_00000698);
  }
  else {
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x71c) != '\0') {
      puVar1 = &DAT_00125754;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: the power of RC is %s on\n",
                   "msm_pcie_show_status",puVar1);
    puVar1 = &DAT_0012768e;
    if (*(char *)(param_1 + 0x71c) != '\0') {
      puVar1 = &DAT_00125754;
    }
    _printk(&DAT_0012f04f,"msm_pcie_show_status",puVar1);
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: smmu_sid_base: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4ec));
    _printk(&DAT_00126d93,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4ec));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: n_fts: %d\n","msm_pcie_show_status",
                   *(undefined4 *)(param_1 + 0x508));
    _printk(&DAT_00126dae,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x508));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: ep_latency: %dms\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x50c));
    _printk(&DAT_0012e40d,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x50c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: switch_latency: %dms\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x510));
    _printk(&DAT_00123581,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x510));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: wr_halt_size: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x514));
    _printk(&DAT_001285ec,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x514));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe: bdf_halt_dis is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x563));
    _printk(&DAT_00122e10,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x563));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe: halt_feature_dis is %d\n",
                   "msm_pcie_show_status",*(undefined1 *)(param_1 + 0x56c));
    _printk(&DAT_0012f06f,"msm_pcie_show_status",*(undefined1 *)(param_1 + 0x56c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: phy_status_offset: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x518));
    _printk(&DAT_001294e3,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x518));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: phy_status_bit: %u\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x51c));
    _printk(&DAT_001276f3,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x51c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: phy_power_down_offset: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x520));
    _printk(&DAT_00125791,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x520));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: eq_pset_req_vec: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x52c));
    _printk(&DAT_001257b4,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x52c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: core_preset: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x530));
    _printk(&DAT_00126dbf,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x530));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: eq_fmdc_t_min_phase23: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x534));
    _printk(&DAT_00121cd3,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x534));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: cpl_timeout: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x538));
    _printk(&DAT_001264db,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x538));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: current_bdf: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x53c));
    _printk(&DAT_0012770d,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x53c));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: perst_delay_us_min: %dus\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x540));
    _printk(&DAT_0012d45a,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x540));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: perst_delay_us_max: %dus\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x544));
    _printk(&DAT_0012d47a,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x544));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: tlp_rd_size: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x548));
    _printk(&DAT_001214a9,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x548));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: linkdown_counter: %lu\n",
                   "msm_pcie_show_status",*(undefined8 *)(param_1 + 0x680));
    _printk(&DAT_00120510,"msm_pcie_show_status",*(undefined8 *)(param_1 + 0x680));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: wake_counter: %lu\n",
                   "msm_pcie_show_status",*(undefined8 *)(param_1 + 0x6a8));
    _printk(&DAT_00127e90,"msm_pcie_show_status",*(undefined8 *)(param_1 + 0x6a8));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: link_check_max_count: %u\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4f0));
    _printk(&DAT_00126512,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4f0));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: prevent_l1: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x678));
    _printk(&DAT_0012e9aa,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x678));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: target_link_speed: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4f4));
    _printk(&DAT_0012cab0,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4f4));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: current_link_speed: 0x%x\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4fc));
    _printk(&DAT_00129502,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x4fc));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: target_link_width: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x500));
    _printk(&DAT_00126532,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x500));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: current_link_width: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x504));
    _printk(&DAT_0012654f,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x504));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: link_width_max: %d\n",
                   "msm_pcie_show_status",*(undefined4 *)(param_1 + 0x404));
    _printk(&DAT_0012d49a,"msm_pcie_show_status",*(undefined4 *)(param_1 + 0x404));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: link_turned_on_counter: %lu\n",
                   "msm_pcie_show_status",*(undefined8 *)(param_1 + 0x688));
    _printk(&DAT_0012b512,"msm_pcie_show_status",*(undefined8 *)(param_1 + 0x688));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: link_turned_off_counter: %lu\n",
                   "msm_pcie_show_status",*(undefined8 *)(param_1 + 0x690));
    _printk(&DAT_00127726,"msm_pcie_show_status",*(undefined8 *)(param_1 + 0x690));
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: l23_rdy_poll_timeout: %llu\n",
                   "msm_pcie_show_status",*(undefined8 *)(param_1 + 0x698));
    _printk(&DAT_00120573,"msm_pcie_show_status",*(undefined8 *)(param_1 + 0x698));
    pcVar2 = "not_supported";
    if (*(long *)(param_1 + 0xd00) != 0) {
      pcVar2 = "supported";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: PCIe CESTA is %s\n",
                   "msm_pcie_show_status",pcVar2);
  }
  pcVar2 = "not_supported";
  if (*(long *)(param_1 + 0xd00) != 0) {
    pcVar2 = "supported";
  }
  _printk(&DAT_001214c2,"msm_pcie_show_status",pcVar2);
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1ss_disable_all @ 0010bd78 size=120
// signature: undefined msm_pcie_config_l1ss_disable_all(void)
// callers: [msm_pcie_config_l1ss_disable_all, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_config_l1ss_disable_all(long param_1,long param_2)

{
  long *plVar1;
  
  if (*(char *)(param_1 + 0x4db) != '\0') {
    for (plVar1 = *(long **)(param_2 + 0x28); plVar1 != (long *)(param_2 + 0x28);
        plVar1 = (long *)*plVar1) {
      if (plVar1[3] != 0) {
        msm_pcie_config_l1ss_disable_all(param_1);
      }
      msm_pcie_config_l1ss(param_1,plVar1,0);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1ss_enable_all @ 0010bdf0 size=92
// signature: undefined msm_pcie_config_l1ss_enable_all(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_config_l1ss_enable_all(long param_1)

{
  if (*(char *)(param_1 + 0x4db) != '\0') {
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1_2_threshold,
                 param_1);
    pci_walk_bus(*(undefined8 *)(*(long *)(param_1 + 8) + 0x10),msm_pcie_config_l1ss_enable,param_1)
    ;
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_access_reg @ 0010be4c size=944
// signature: undefined msm_pcie_access_reg(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

void msm_pcie_access_reg(long param_1,ulong param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  int *piVar12;
  char *pcVar13;
  ulong uVar14;
  undefined8 uVar15;
  long local_50;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  local_50 = 0;
  if (param_1 == 0) {
    pcVar13 = "writing";
    if ((param_2 & 1) == 0) {
      pcVar13 = "reading";
    }
  }
  else {
    pcVar13 = "writing";
    if ((param_2 & 1) == 0) {
      pcVar13 = "reading";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                   "DBG_FS:%s: \n\nPCIe: RC%d: %s a PCIe register\n\n","msm_pcie_access_reg",
                   *(undefined4 *)(param_1 + 0x570),pcVar13);
  }
  _printk(&DAT_0012774a,"msm_pcie_access_reg",*(undefined4 *)(param_1 + 0x570),pcVar13);
  if (base_sel == 0) {
    if (param_1 == 0) {
      iVar9 = 0;
    }
    else {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DBG_FS:%s: Invalid base_sel: 0x%x\n",
                     "msm_pcie_access_reg",0);
      iVar9 = base_sel;
    }
    puVar8 = &DAT_0012750c;
  }
  else {
    uVar6 = base_sel - 1;
    lVar11 = param_1 + (ulong)uVar6 * 0x18;
    if (*(long *)(lVar11 + 0x168) != 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: base: %s: 0x%pK\nwr_offset: 0x%x\n","msm_pcie_access_reg",
                       *(undefined8 *)(lVar11 + 0x160),
                       *(undefined8 *)(param_1 + (ulong)uVar6 * 0x18 + 0x170),wr_offset);
        uVar6 = base_sel - 1;
      }
      if (9 < uVar6) {
LAB_0010c1f4:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10c1f8);
        (*pcVar5)();
      }
      lVar11 = param_1 + (ulong)uVar6 * 0x18;
      _printk(&DAT_001257d8,"msm_pcie_access_reg",*(undefined8 *)(lVar11 + 0x160),
              *(undefined8 *)(lVar11 + 0x170),wr_offset);
      iVar9 = wr_value;
      uVar4 = wr_mask;
      uVar3 = wr_offset;
      uVar6 = base_sel - 1;
      uVar10 = (ulong)uVar6;
      if (9 < uVar6) goto LAB_0010c1f4;
      uVar14 = (ulong)wr_offset;
      piVar12 = *(int **)(param_1 + uVar10 * 0x18 + 0x168);
      uVar2 = (piVar12[2] - *piVar12) - 3;
      if (wr_offset <= uVar2) {
        if ((wr_offset & 3) == 0) {
          if ((param_2 & 1) == 0) {
            local_50 = **(long **)(param_1 + 0x198) + uVar14;
            if (param_1 != 0) {
              uVar1 = *(undefined4 *)(param_1 + 0x570);
              uVar15 = *(undefined8 *)(param_1 + 0x730);
              uVar7 = readl_relaxed(*(long *)(param_1 + (ulong)uVar6 * 0x18 + 0x170) + uVar14);
              ipc_log_string(uVar15,"DBG_FS:%s: PCIe: RC%d: register: 0x%pa value: 0x%x\n",
                             "msm_pcie_access_reg",uVar1,&local_50,uVar7);
              uVar10 = (ulong)(base_sel - 1U);
              if (9 < base_sel - 1U) goto LAB_0010c1f4;
            }
            uVar1 = *(undefined4 *)(param_1 + 0x570);
            uVar7 = readl_relaxed(*(long *)(param_1 + uVar10 * 0x18 + 0x170) + (ulong)wr_offset);
            _printk(&DAT_00123df8,"msm_pcie_access_reg",uVar1,&local_50,uVar7);
          }
          else {
            uVar10 = ((ulong)wr_mask & 0xaaaaaaaaaaaaaaaa) >> 1 |
                     ((ulong)wr_mask & 0x5555555555555555) << 1;
            uVar10 = (uVar10 & 0xcccccccccccccccc) >> 2 | (uVar10 & 0x3333333333333333) << 2;
            uVar10 = (uVar10 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar10 & 0xf0f0f0f0f0f0f0f) << 4;
            uVar10 = (uVar10 & 0xff00ff00ff00ff00) >> 8 | (uVar10 & 0xff00ff00ff00ff) << 8;
            lVar11 = *(long *)(param_1 + (ulong)uVar6 * 0x18 + 0x170) + uVar14;
            uVar6 = readl_relaxed(lVar11);
            writel_relaxed(iVar9 << (ulong)((uint)LZCOUNT((uVar10 >> 0x10 |
                                                          (uVar10 & 0xffff0000ffff) << 0x10) << 0x20
                                                         ) & 0x1f) | uVar6 & (uVar4 ^ 0xffffffff),
                           lVar11);
            readl_relaxed(lVar11);
          }
          goto LAB_0010c074;
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "ERR:%s: PCIe: RC%d: offset 0x%x is not correctly aligned\n",
                         "msm_pcie_check_align",*(undefined4 *)(param_1 + 0x570),wr_offset);
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: PCIe: RC%d: offset 0x%x is not correctly aligned\n",
                         "msm_pcie_check_align",*(undefined4 *)(param_1 + 0x570),uVar3);
        }
        _printk(&DAT_00121d5b,"msm_pcie_check_align",*(undefined4 *)(param_1 + 0x570),uVar3);
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: Invalid wr_offset: 0x%x. wr_offset should be no more than 0x%x\n"
                       ,"msm_pcie_access_reg",*(undefined4 *)(param_1 + 0x570),wr_offset,uVar2);
      }
      _printk(&DAT_0012adb5,"msm_pcie_access_reg",*(undefined4 *)(param_1 + 0x570),wr_offset,uVar2);
      goto LAB_0010c074;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x730),
                     "DBG_FS:%s: PCIe: RC%d Resource does not exist\n","msm_pcie_access_reg",
                     *(undefined4 *)(param_1 + 0x570));
    }
    iVar9 = *(int *)(param_1 + 0x570);
    puVar8 = &DAT_00124646;
  }
  _printk(puVar8,"msm_pcie_access_reg",iVar9);
LAB_0010c074:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_loopback @ 0010c1fc size=3164
// signature: undefined msm_pcie_loopback(void)
// callers: [msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pcie_loopback(long *param_1,uint param_2)

{
  ulong uVar1;
  undefined8 uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  long lVar10;
  undefined *puVar11;
  char *pcVar12;
  char cVar13;
  char cVar14;
  bool bVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  long lVar19;
  long lVar20;
  long lVar21;
  undefined8 local_70;
  long local_68;
  
  lVar17 = sp_el0;
  local_68 = *(long *)(lVar17 + 0x638);
  lVar17 = *(long *)param_1[0x33];
  local_70 = 0;
  uVar1 = lVar17 + 0x800000;
  uVar2 = 0x68000000000713;
  if (arm64_use_ng_mappings != '\0') {
    uVar2 = 0x68000000000f13;
  }
  lVar10 = ioremap_prot(uVar1,0x1000,uVar2);
  if (lVar10 == 0) {
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d: ioremap fails for loopback_lbar_phy\n",
                     "msm_pcie_loopback",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: ioremap fails for loopback_lbar_phy\n",
                     "msm_pcie_loopback",(int)param_1[0xae]);
    }
    _printk(&DAT_0012e9c0,"msm_pcie_loopback",(int)param_1[0xae]);
  }
  else {
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: Allocate 4K DDR memory and map LBAR.\n",
                     "msm_pcie_loopback",(int)param_1[0xae]);
    }
    _printk(&DAT_00125e41,"msm_pcie_loopback",(int)param_1[0xae]);
    lVar16 = *param_1;
    iVar5 = dma_set_mask(lVar16 + 0x10,0xffffffffffffffff);
    if (iVar5 == 0) {
      dma_set_coherent_mask(lVar16 + 0x10,0xffffffffffffffff);
      lVar16 = dma_alloc_attrs(*param_1 + 0x10,0x1000,&local_70,0xcc0,0);
      if (lVar16 != 0) {
        if (param_1 == (long *)0x0) {
          _printk(&DAT_0012ea1e,"msm_pcie_loopback",_DAT_00000570,lVar16);
        }
        else {
          ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: VIR DDR memory address: 0x%pK\n",
                         "msm_pcie_loopback",(int)param_1[0xae],lVar16);
          _printk(&DAT_0012ea1e,"msm_pcie_loopback",(int)param_1[0xae],lVar16);
          ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: IOVA DDR memory address: %pad\n",
                         "msm_pcie_loopback",(int)param_1[0xae],&local_70);
        }
        _printk(&DAT_001257ff,"msm_pcie_loopback",(int)param_1[0xae],&local_70);
        uVar9 = (uint)local_70;
        iVar5 = (int)lVar17;
        if ((param_2 & 1) == 0) {
          if (param_1 != (long *)0x0) {
            ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: Configure remote Loopback.\n",
                           "msm_pcie_loopback",(int)param_1[0xae]);
          }
          _printk(&DAT_0012479f,"msm_pcie_loopback",(int)param_1[0xae]);
        }
        else {
          if (param_1 != (long *)0x0) {
            ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: Configure Local Loopback.\n",
                           "msm_pcie_loopback",(int)param_1[0xae]);
          }
          _printk(&DAT_0012bd67,"msm_pcie_loopback",(int)param_1[0xae]);
          lVar17 = param_1[0x74] + 0x890;
          uVar6 = readl_relaxed(lVar17);
          writel_relaxed(uVar6 | 0x10000,lVar17);
          readl_relaxed(lVar17);
          uVar8 = _DAT_00000570;
          if (param_1 == (long *)0x0) {
            uVar7 = readl_relaxed(lRam00000000000003a0 + 0x890);
            _printk(&DAT_0012cb0d,"msm_pcie_loopback",uVar8,iVar5 + 0x890,uVar7);
            lVar17 = lRam00000000000003a0 + 0x8b8;
            uVar6 = readl_relaxed(lVar17);
            writel_relaxed(uVar6 | 0x80000000,lVar17);
            readl_relaxed(lVar17);
          }
          else {
            lVar19 = param_1[0xe6];
            lVar17 = param_1[0xae];
            uVar8 = readl_relaxed(param_1[0x74] + 0x890);
            ipc_log_string(lVar19,"DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n","msm_pcie_loopback",
                           (int)lVar17,iVar5 + 0x890,uVar8);
            lVar17 = param_1[0xae];
            uVar8 = readl_relaxed(param_1[0x74] + 0x890);
            _printk(&DAT_0012cb0d,"msm_pcie_loopback",(int)lVar17,iVar5 + 0x890,uVar8);
            lVar17 = param_1[0x74] + 0x8b8;
            uVar6 = readl_relaxed(lVar17);
            writel_relaxed(uVar6 | 0x80000000,lVar17);
            readl_relaxed(lVar17);
            lVar19 = param_1[0xe6];
            lVar17 = param_1[0xae];
            uVar8 = readl_relaxed(param_1[0x74] + 0x8b8);
            ipc_log_string(lVar19,"DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n","msm_pcie_loopback",
                           (int)lVar17,iVar5 + 0x8b8,uVar8);
          }
          lVar17 = param_1[0xae];
          uVar8 = readl_relaxed(param_1[0x74] + 0x8b8);
          _printk(&DAT_0012cb0d,"msm_pcie_loopback",(int)lVar17,iVar5 + 0x8b8,uVar8);
        }
        lVar17 = param_1[0x74] + 0x710;
        uVar6 = readl_relaxed(lVar17);
        writel_relaxed(uVar6 | 4,lVar17);
        readl_relaxed(lVar17);
        lVar17 = param_1[0x74] + 4;
        uVar6 = readl_relaxed(lVar17);
        writel_relaxed(uVar6 | 6,lVar17);
        readl_relaxed(lVar17);
        if (param_1 != (long *)0x0) {
          lVar19 = param_1[0xe6];
          lVar17 = param_1[0xae];
          uVar8 = readl_relaxed(param_1[0x74] + 0x710);
          ipc_log_string(lVar19,"DBG_FS:%s: PCIe: RC%d: 0x%x: 0x%x\n","msm_pcie_loopback",
                         (int)lVar17,iVar5 + 0x710,uVar8);
        }
        lVar17 = param_1[0xae];
        uVar8 = readl_relaxed(param_1[0x74] + 0x710);
        _printk(&DAT_0012cb0d,"msm_pcie_loopback",(int)lVar17,iVar5 + 0x710,uVar8);
        lVar17 = param_1[0x73];
        iVar3 = *(int *)param_1[0x39];
        if (param_1 != (long *)0x0) {
          ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: Setup iATU.\n","msm_pcie_loopback",
                         (int)param_1[0xae]);
        }
        _printk(&DAT_00124f38,"msm_pcie_loopback",(int)param_1[0xae]);
        lVar19 = lVar17 + 0x204;
        writel_relaxed(0,lVar19);
        readl_relaxed(lVar19);
        lVar18 = lVar17 + 0x200;
        writel_relaxed(0,lVar18);
        if (param_1 != (long *)0x0) {
          lVar21 = param_1[0xe6];
          lVar20 = param_1[0xae];
          uVar8 = readl_relaxed(lVar18);
          ipc_log_string(lVar21,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_CTRL1:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar20,iVar3 + 0x200,uVar8);
        }
        lVar20 = param_1[0xae];
        uVar8 = readl_relaxed(lVar18);
        _printk(&DAT_00128643,"msm_pcie_loopback",(int)lVar20,iVar3 + 0x200,uVar8);
        lVar18 = lVar17 + 0x208;
        writel_relaxed(uVar1 & 0xffffffff,lVar18);
        if (param_1 != (long *)0x0) {
          lVar21 = param_1[0xe6];
          lVar20 = param_1[0xae];
          uVar8 = readl_relaxed(lVar18);
          ipc_log_string(lVar21,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LBAR:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar20,iVar3 + 0x208,uVar8);
        }
        lVar20 = param_1[0xae];
        uVar8 = readl_relaxed(lVar18);
        _printk(&DAT_0012953f,"msm_pcie_loopback",(int)lVar20,iVar3 + 0x208,uVar8);
        lVar18 = lVar17 + 0x20c;
        writel_relaxed(0,lVar18);
        if (param_1 != (long *)0x0) {
          lVar21 = param_1[0xe6];
          lVar20 = param_1[0xae];
          uVar8 = readl_relaxed(lVar18);
          ipc_log_string(lVar21,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_UBAR:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar20,iVar3 + 0x20c,uVar8);
        }
        lVar20 = param_1[0xae];
        uVar8 = readl_relaxed(lVar18);
        _printk(&DAT_0012e42d,"msm_pcie_loopback",(int)lVar20,iVar3 + 0x20c,uVar8);
        lVar18 = lVar17 + 0x210;
        writel_relaxed(iVar5 + 0x801fff,lVar18);
        if (param_1 != (long *)0x0) {
          lVar21 = param_1[0xe6];
          lVar20 = param_1[0xae];
          uVar8 = readl_relaxed(lVar18);
          ipc_log_string(lVar21,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LAR:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar20,iVar3 + 0x210,uVar8);
        }
        lVar20 = param_1[0xae];
        uVar8 = readl_relaxed(lVar18);
        _printk(&DAT_00123e74,"msm_pcie_loopback",(int)lVar20,iVar3 + 0x210,uVar8);
        lVar18 = lVar17 + 0x214;
        writel_relaxed(uVar9 & 0xfffff000,lVar18);
        if (param_1 != (long *)0x0) {
          lVar21 = param_1[0xe6];
          lVar20 = param_1[0xae];
          uVar8 = readl_relaxed(lVar18);
          ipc_log_string(lVar21,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_LTAR:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar20,iVar3 + 0x214,uVar8);
        }
        lVar20 = param_1[0xae];
        uVar8 = readl_relaxed(lVar18);
        _printk(&DAT_00128678,"msm_pcie_loopback",(int)lVar20,iVar3 + 0x214,uVar8);
        lVar17 = lVar17 + 0x218;
        writel_relaxed(local_70._4_4_,lVar17);
        uVar8 = _DAT_00000570;
        if (param_1 == (long *)0x0) {
          uVar7 = readl_relaxed(lVar17);
          _printk(&DAT_001295ac,"msm_pcie_loopback",uVar8,iVar3 + 0x218,uVar7);
          writel_relaxed(0x80000000,lVar19);
          uVar8 = _DAT_00000570;
          uVar7 = readl_relaxed(lVar19);
          _printk(&DAT_0012ea82,"msm_pcie_loopback",uVar8,iVar3 + 0x204,uVar7);
        }
        else {
          lVar20 = param_1[0xe6];
          lVar18 = param_1[0xae];
          uVar8 = readl_relaxed(lVar17);
          ipc_log_string(lVar20,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_UTAR:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar18,iVar3 + 0x218,uVar8);
          lVar18 = param_1[0xae];
          uVar8 = readl_relaxed(lVar17);
          _printk(&DAT_001295ac,"msm_pcie_loopback",(int)lVar18,iVar3 + 0x218,uVar8);
          writel_relaxed(0x80000000,lVar19);
          lVar18 = param_1[0xe6];
          lVar17 = param_1[0xae];
          uVar8 = readl_relaxed(lVar19);
          ipc_log_string(lVar18,"DBG_FS:%s: PCIe: RC%d: PCIE20_PLR_IATU_CTRL2:\t0x%x: 0x%x\n",
                         "msm_pcie_loopback",(int)lVar17,iVar3 + 0x204,uVar8);
          lVar17 = param_1[0xae];
          uVar8 = readl_relaxed(lVar19);
          _printk(&DAT_0012ea82,"msm_pcie_loopback",(int)lVar17,iVar3 + 0x204,uVar8);
          lVar19 = param_1[0xe6];
          lVar17 = param_1[0xae];
          uVar9 = readl_relaxed(param_1[0x72] + 8);
          if ((uVar9 & 0x3c000) < 0x23001) {
            uVar9 = readl_relaxed(param_1[0x72] + 8);
            uVar9 = uVar9 >> 0xc & 0x3f;
            if (0x23 < uVar9) goto LAB_0010ce50;
            pcVar12 = (&msm_pcie_ltssm_str)[uVar9];
          }
          else {
            pcVar12 = "LTSSM_INVALID";
          }
          ipc_log_string(lVar19,"DBG_FS:%s: PCIe RC%d: LTSSM_STATE: %s\n","msm_pcie_loopback",
                         (int)lVar17,pcVar12);
        }
        lVar17 = param_1[0xae];
        uVar9 = readl_relaxed(param_1[0x72] + 8);
        if ((uVar9 & 0x3c000) < 0x23001) {
          uVar9 = readl_relaxed(param_1[0x72] + 8);
          uVar9 = uVar9 >> 0xc & 0x3f;
          if (0x23 < uVar9) {
LAB_0010ce50:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10ce54);
            (*pcVar4)();
          }
          pcVar12 = (&msm_pcie_ltssm_str)[uVar9];
        }
        else {
          pcVar12 = "LTSSM_INVALID";
        }
        _printk(&DAT_0012a50a,"msm_pcie_loopback",(int)lVar17,pcVar12);
        get_random_bytes(lVar10,0x1000);
        usleep_range_state(100,0x65,2);
        lVar17 = 0;
        bVar15 = false;
        do {
          lVar19 = lVar17;
          while( true ) {
            cVar13 = *(char *)(lVar10 + lVar19);
            cVar14 = *(char *)(lVar16 + lVar19);
            if (cVar13 != cVar14) break;
            lVar19 = lVar19 + 1;
            if (lVar19 == 0x1000) {
              if (bVar15) goto LAB_0010cd38;
              if (param_1 == (long *)0x0) {
                pcVar12 = "Local";
                if ((param_2 & 1) == 0) {
                  pcVar12 = "Remote";
                }
              }
              else {
                pcVar12 = "Local";
                if ((param_2 & 1) == 0) {
                  pcVar12 = "Remote";
                }
                ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: %s Loopback Test Passed\n",
                               "msm_pcie_loopback",(int)param_1[0xae],pcVar12);
              }
              uVar8 = (undefined4)param_1[0xae];
              puVar11 = &DAT_0012eab7;
              goto LAB_0010cde4;
            }
          }
          if (param_1 != (long *)0x0) {
            ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: exp %x: got %x\n",
                           "msm_pcie_loopback",(int)param_1[0xae]);
            cVar13 = *(char *)(lVar10 + lVar19);
            cVar14 = *(char *)(lVar16 + lVar19);
          }
          _printk(&DAT_00123654,"msm_pcie_loopback",(int)param_1[0xae],cVar13,cVar14);
          lVar17 = lVar19 + 1;
          bVar15 = true;
        } while (lVar19 != 0xfff);
LAB_0010cd38:
        if (param_1 == (long *)0x0) {
          pcVar12 = "Local";
          if ((param_2 & 1) == 0) {
            pcVar12 = "Remote";
          }
        }
        else {
          pcVar12 = "Local";
          if ((param_2 & 1) == 0) {
            pcVar12 = "Remote";
          }
          ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: %s Loopback Test failed\n",
                         "msm_pcie_loopback",(int)param_1[0xae],pcVar12);
        }
        uVar8 = (undefined4)param_1[0xae];
        puVar11 = &DAT_0012ae2e;
LAB_0010cde4:
        _printk(puVar11,"msm_pcie_loopback",uVar8,pcVar12);
        iounmap(lVar10);
        dma_free_attrs(*param_1 + 0x10,0x1000,lVar16,local_70,0);
        goto LAB_0010ce18;
      }
      if (param_1 != (long *)0x0) {
        ipc_log_string(param_1[0xe6],"DBG_FS:%s: PCIe: RC%d: failed to dma_alloc_coherent.\n",
                       "msm_pcie_loopback",(int)param_1[0xae]);
      }
      uVar8 = (undefined4)param_1[0xae];
      puVar11 = &DAT_0012b535;
    }
    else {
      if (param_1 != (long *)0x0) {
        ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d: DMA set mask failed\n","msm_pcie_loopback"
                       ,(int)param_1[0xae]);
        ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: DMA set mask failed\n","msm_pcie_loopback",
                       (int)param_1[0xae]);
      }
      uVar8 = (undefined4)param_1[0xae];
      puVar11 = &DAT_0012e9f7;
    }
    _printk(puVar11,"msm_pcie_loopback",uVar8);
    iounmap(lVar10);
  }
LAB_0010ce18:
  lVar17 = sp_el0;
  if (*(long *)(lVar17 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1ss @ 0010ce58 size=896
// signature: undefined msm_pcie_config_l1ss(void)
// callers: [msm_pcie_config_l1ss_disable_all, msm_pcie_config_l1ss_enable]
//------------------------------------------------------------

void msm_pcie_config_l1ss(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  undefined1 uVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  long lVar10;
  ushort uVar11;
  uint uVar12;
  undefined8 uVar13;
  char *pcVar14;
  char *pcVar15;
  undefined4 local_54;
  undefined4 local_50;
  uint local_4c;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  uVar12 = *(uint *)(param_2 + 0x38);
  local_54 = 0;
  local_50 = 0;
  bVar4 = *(byte *)(param_2 + 0x6c);
  if ((param_1 != 0) && ((uVar12 & 7) != 0)) {
    pcVar15 = "msm_pcie_is_non_zero_function";
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n",
                   "msm_pcie_is_non_zero_function",*(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),uVar12 >> 3 & 0x1f);
    uVar12 = *(uint *)(param_2 + 0x38);
    pcVar14 = "%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n";
    uVar13 = *(undefined8 *)(param_1 + 0x720);
    uVar3 = *(undefined4 *)(param_1 + 0x570);
    uVar9 = uVar12 >> 3;
    uVar5 = *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8);
LAB_0010cef4:
    ipc_log_string(uVar13,pcVar14,pcVar15,uVar3,uVar5,uVar9 & 0x1f,uVar12 & 7);
    goto LAB_0010cf04;
  }
  if ((uVar12 & 7) != 0) goto LAB_0010cf04;
  if (param_1 == 0) {
    uVar11 = pci_find_ext_capability(param_2,0x1e);
    if (uVar11 == 0) goto LAB_0010cf04;
  }
  else {
    pcVar14 = "enable";
    if ((param_3 & 1) == 0) {
      pcVar14 = "disable";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n","msm_pcie_config_l1ss",
                   *(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),uVar12 >> 3 & 0x1f,0,pcVar14);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n"
                   ,"msm_pcie_config_l1ss",*(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                   *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7,pcVar14);
    uVar11 = pci_find_ext_capability(param_2,0x1e);
    if (uVar11 == 0) {
      pcVar15 = "msm_pcie_config_l1ss";
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n"
                     ,"msm_pcie_config_l1ss",*(undefined4 *)(param_1 + 0x570),
                     *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                     *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7);
      pcVar14 = 
      "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n";
      uVar12 = *(uint *)(param_2 + 0x38);
      uVar13 = *(undefined8 *)(param_1 + 0x720);
      uVar3 = *(undefined4 *)(param_1 + 0x570);
      uVar5 = *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8);
      uVar9 = uVar12 >> 3 & 0xe000001f;
      goto LAB_0010cef4;
    }
  }
  iVar1 = bVar4 + 0x28;
  iVar2 = uVar11 + 8;
  if ((*(long *)(*(long *)(param_2 + 0x10) + 0x10) == 0) && (*(char *)(param_1 + 0x4ea) == '\0')) {
    uVar13 = *(undefined8 *)(param_1 + 0x380);
    uVar12 = readl_relaxed(uVar13);
    if ((param_3 & 1) == 0) {
      writel_relaxed(uVar12 | 8,uVar13);
      readl_relaxed(uVar13);
      goto LAB_0010d100;
    }
    writel_relaxed(uVar12 & 0xfffffff7,uVar13);
    readl_relaxed(uVar13);
LAB_0010d05c:
    local_4c = 0;
    pci_read_config_dword(param_2,iVar1,&local_4c);
    local_4c = local_4c | 0x400;
    pci_write_config_dword(param_2,iVar1);
    bVar4 = *(byte *)(param_1 + 0x4dc);
    bVar6 = *(byte *)(param_1 + 0x4dd);
    bVar7 = *(byte *)(param_1 + 0x4de);
    bVar8 = *(byte *)(param_1 + 0x4df);
    local_4c = 0;
    pci_read_config_dword(param_2,iVar2,&local_4c);
    local_4c = (uint)bVar6 | (uint)bVar4 << 1 | (uint)bVar7 << 3 | (uint)bVar8 << 2 | local_4c;
  }
  else {
    if ((param_3 & 1) != 0) goto LAB_0010d05c;
LAB_0010d100:
    local_4c = 0;
    pci_read_config_dword(param_2,iVar1,&local_4c);
    local_4c = local_4c & 0xfffffbff;
    pci_write_config_dword(param_2,iVar1);
    local_4c = 0;
    pci_read_config_dword(param_2,iVar2,&local_4c);
    local_4c = local_4c & 0xfffffff0;
  }
  pci_write_config_dword(param_2,iVar2);
  pci_read_config_dword(param_2,iVar2,&local_50);
  if (param_1 == 0) {
    pci_read_config_dword(param_2,iVar1,&local_54);
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"DBG2:%s: PCIe: RC%d: L1SUB_CONTROL1:0x%x\n",
                   "msm_pcie_config_l1ss",*(undefined4 *)(param_1 + 0x570),local_50);
    pci_read_config_dword(param_2,iVar1,&local_54);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                   "DBG2:%s: PCIe: RC%d: DEVICE_CONTROL2_STATUS2::0x%x\n","msm_pcie_config_l1ss",
                   *(undefined4 *)(param_1 + 0x570),local_54);
  }
LAB_0010cf04:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1_2_threshold @ 0010d1dc size=504
// signature: undefined msm_pcie_config_l1_2_threshold(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_l1_2_threshold(long param_1,long param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  long lVar6;
  ushort uVar7;
  undefined8 uVar8;
  char *pcVar9;
  char *pcVar10;
  uint local_3c;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  if (*(int *)(param_2 + 0x4e4) == 0) goto LAB_0010d3a0;
  uVar1 = *(uint *)(param_1 + 0x38);
  if ((param_2 == 0) || ((uVar1 & 7) == 0)) {
    if ((uVar1 & 7) != 0) goto LAB_0010d3a0;
    if (param_2 == 0) {
      uVar7 = pci_find_ext_capability(param_1,0x1e);
      if (uVar7 == 0) goto LAB_0010d3a0;
    }
    else {
      pcVar10 = "msm_pcie_config_l1_2_threshold";
      ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                     "msm_pcie_config_l1_2_threshold",*(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),uVar1 >> 3 & 0x1f,0);
      ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                     "msm_pcie_config_l1_2_threshold",*(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      uVar7 = pci_find_ext_capability(param_1,0x1e);
      if (uVar7 == 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n"
                       ,"msm_pcie_config_l1_2_threshold",*(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        pcVar9 = 
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n";
        uVar1 = *(uint *)(param_1 + 0x38);
        uVar8 = *(undefined8 *)(param_2 + 0x720);
        uVar2 = *(undefined4 *)(param_2 + 0x570);
        uVar4 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
        uVar5 = uVar1 >> 3 & 0xe000001f;
        goto LAB_0010d270;
      }
    }
    iVar3 = *(int *)(param_2 + 0x4e0);
    uVar1 = *(uint *)(param_2 + 0x4e4);
    local_3c = 0;
    pci_read_config_dword(param_1,uVar7 + 8,&local_3c);
    local_3c = local_3c | iVar3 << 0x1d | (uVar1 & 0x3ff) << 0x10;
    pci_write_config_dword(param_1,uVar7 + 8);
  }
  else {
    pcVar10 = "msm_pcie_is_non_zero_function";
    ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n",
                   "msm_pcie_is_non_zero_function",*(undefined4 *)(param_2 + 0x570),
                   *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),uVar1 >> 3 & 0x1f);
    uVar1 = *(uint *)(param_1 + 0x38);
    pcVar9 = "%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n";
    uVar8 = *(undefined8 *)(param_2 + 0x720);
    uVar2 = *(undefined4 *)(param_2 + 0x570);
    uVar5 = uVar1 >> 3;
    uVar4 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
LAB_0010d270:
    ipc_log_string(uVar8,pcVar9,pcVar10,uVar2,uVar4,uVar5 & 0x1f,uVar1 & 7);
  }
LAB_0010d3a0:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_l1ss_enable @ 0010d3d8 size=48
// signature: undefined msm_pcie_config_l1ss_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_l1ss_enable(undefined8 param_1,undefined8 param_2)

{
  msm_pcie_config_l1ss(param_2,param_1,1);
  return 0;
}



//------------------------------------------------------------
// writel_relaxed @ 0010d408 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_pcie_write_mask, msm_pcie_enable_link, msm_pcie_oper_conf, msm_pcie_handle_linkdown, msm_pcie_config_controller, msm_pcie_access_reg, msm_pcie_parf_cesta_config, msm_pcie_config_tc_bdf_sid_map, msm_pcie_debugfs_aer_enable, msm_pcie_pm_suspend_noirq, msm_pcie_enable, msm_pcie_allow_l1, msm_pcie_restore_sid_config, msm_pcie_loopback, handle_sbr_func, msm_pcie_pm_resume_noirq, msm_pcie_disable, msm_pcie_prevent_l1, msm_pcie_config_l1ss, msm_pcie_iatu_setup_ecam_blocker, msm_pcie_pm_suspend, msm_pcie_deenumerate, pcie_parf_dump, msm_pcie_l1ss_timeout_disable, msm_pcie_probe, msm_pcie_config_bandwidth_int, msm_pcie_rumi_init, init_module, msm_pcie_config_sid, msm_pcie_l1ss_timeout_enable, msm_pcie_enumerate, msm_pcie_pm_control, handle_global_irq, msm_pcie_iatu_config_shift, msm_pcie_cfg_bdf]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10d420,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x10d45c,uVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_ecam_oper_conf @ 0010d48c size=452
// signature: undefined msm_pcie_ecam_oper_conf(void)
// callers: [msm_pcie_ecam_rd_conf, msm_pcie_ecam_wr_conf]
//------------------------------------------------------------

int msm_pcie_ecam_oper_conf
              (long param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
              undefined4 *param_6)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0xe8) + 200);
  if (lVar3 == 0) {
    _printk(&DAT_0012a52c);
    iVar1 = 0x86;
  }
  else {
    uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x444);
    *(undefined8 *)(lVar3 + 0x448) = uVar2;
    iVar1 = msm_pcie_check_link_dev_status(lVar3,param_1,param_2,param_3,param_4,param_5);
    if (iVar1 == 0) {
      if (param_3 == 0) {
        iVar1 = pci_generic_config_read(param_1,param_2,param_4,param_5,param_6);
        pcVar4 = "read";
      }
      else {
        iVar1 = pci_generic_config_write(param_1,param_2,param_4,param_5,*param_6);
        pcVar4 = "write";
      }
      ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                     "DBG3:%s: RC%d %d:0x%02x + 0x%04x[%d] %s val 0x%08x\n",
                     "msm_pcie_ecam_oper_conf",*(undefined4 *)(lVar3 + 0x570),
                     *(undefined1 *)(param_1 + 0xf8),param_2,param_4,param_5,pcVar4,*param_6);
      if (iVar1 != 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x728),"ERR:%s: PCIe: RC%d %d: %s operation failed\n"
                       ,"msm_pcie_ecam_oper_conf",*(undefined4 *)(lVar3 + 0x570),
                       *(undefined1 *)(param_1 + 0xf8),pcVar4);
        ipc_log_string(*(undefined8 *)(lVar3 + 0x720),"%s: PCIe: RC%d %d: %s operation failed\n",
                       "msm_pcie_ecam_oper_conf",*(undefined4 *)(lVar3 + 0x570),
                       *(undefined1 *)(param_1 + 0xf8),pcVar4);
        _printk(&DAT_0012eb0d,"msm_pcie_ecam_oper_conf",*(undefined4 *)(lVar3 + 0x570),
                *(undefined1 *)(param_1 + 0xf8),pcVar4);
      }
    }
    else {
      *param_6 = 0xffffffff;
    }
    _raw_spin_unlock_irqrestore(lVar3 + 0x444,*(undefined8 *)(lVar3 + 0x448));
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_pcie_check_link_dev_status @ 0010d650 size=440
// signature: undefined msm_pcie_check_link_dev_status(void)
// callers: [msm_pcie_oper_conf, msm_pcie_ecam_oper_conf]
//------------------------------------------------------------

undefined8
msm_pcie_check_link_dev_status
          (long param_1,long param_2,int param_3,int param_4,undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  undefined4 uVar2;
  byte bVar3;
  uint uVar4;
  undefined8 uVar5;
  char *pcVar6;
  int iVar7;
  uint *puVar8;
  
  bVar3 = *(byte *)(param_2 + 0xf8);
  uVar2 = *(undefined4 *)(param_1 + 0x570);
  if (*(char *)(param_1 + 0x440) == '\0') {
    uVar5 = *(undefined8 *)(param_1 + 0x720);
    pcVar6 = "DBG3:%s: Access denied for RC%d %d:0x%02x + 0x%04x[%d]\n";
  }
  else {
    if ((param_3 != 0) && (bVar3 == 0)) {
      puVar1 = &DAT_0012155e;
      if (param_4 != 0) {
        puVar1 = &DAT_00122620;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),"DBG3:%s: RC%d invalid %s - bus %d devfn %d\n"
                     ,"msm_pcie_check_link_dev_status",uVar2,puVar1,0,param_3,param_6);
      return 0x86;
    }
    if (*(int *)(param_1 + 0x4b0) == 1) {
      if ((bVar3 != 0) &&
         (uVar4 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x80), (uVar4 >> 0x1d & 1) == 0)) {
        puVar1 = &DAT_0012155e;
        if (param_4 != 0) {
          puVar1 = &DAT_00122620;
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d %s fail, link down - bus %d devfn %d\n",
                       "msm_pcie_check_link_dev_status",uVar2,puVar1,*(undefined1 *)(param_2 + 0xf8)
                       ,param_3);
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d %s fail, link down - bus %d devfn %d\n",
                       "msm_pcie_check_link_dev_status",uVar2,puVar1,*(undefined1 *)(param_2 + 0xf8)
                       ,param_3);
        _printk(&DAT_00129d3c,"msm_pcie_check_link_dev_status",uVar2,puVar1,
                *(undefined1 *)(param_2 + 0xf8),param_3);
        return 0x86;
      }
      iVar7 = *(int *)(param_1 + 0xcc8);
      if (iVar7 != 0) {
        puVar8 = *(uint **)(param_1 + 0xcc0);
        do {
          if (*puVar8 == ((uint)bVar3 << 0x18 | param_3 << 0x10)) {
            return 0x86;
          }
          iVar7 = iVar7 + -1;
          puVar8 = puVar8 + 1;
        } while (iVar7 != 0);
      }
      return 0;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x720);
    pcVar6 = "DBG3:%s: Access to RC%d %d:0x%02x + 0x%04x[%d] is denied because link is down\n";
  }
  ipc_log_string(uVar5,pcVar6,"msm_pcie_check_link_dev_status",uVar2,bVar3,param_3,param_5,param_6);
  return 0x86;
}



//------------------------------------------------------------
// msm_pcie_vreg_init @ 0010d808 size=956
// signature: undefined msm_pcie_vreg_init(void)
// callers: [msm_pcie_enable, msm_pcie_pm_control]
//------------------------------------------------------------

int msm_pcie_vreg_init(long param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined8 *puVar5;
  long lVar6;
  int *piVar7;
  ulong uVar8;
  long lVar9;
  char *__s1;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_vreg_init",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_vreg_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  piVar7 = (int *)(param_1 + 0x38);
  uVar8 = 0xffffffffffffffff;
  do {
    lVar6 = *(long *)(piVar7 + -6);
    if (lVar6 != 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"DBG2:%s: RC%d Vreg %s is being enabled\n",
                       "msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(piVar7 + -4));
      }
      if ((piVar7[-2] == 0) || (iVar1 = regulator_set_voltage(lVar6,piVar7[-1]), iVar1 == 0)) {
        if ((*piVar7 == 0) || (iVar1 = regulator_set_load(lVar6), -1 < iVar1)) {
          iVar1 = regulator_enable(lVar6);
          if (iVar1 == 0) goto LAB_0010d890;
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d can\'t enable regulator %s: %d\n",
                           "msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),
                           *(undefined8 *)(piVar7 + -4),iVar1);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d can\'t enable regulator %s: %d\n","msm_pcie_vreg_init",
                           *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(piVar7 + -4),iVar1);
          }
          uVar4 = *(undefined4 *)(param_1 + 0x570);
          puVar3 = &DAT_00125f38;
        }
        else {
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d can\'t set mode for %s: %d\n","msm_pcie_vreg_init",
                           *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(piVar7 + -4),iVar1);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d can\'t set mode for %s: %d\n","msm_pcie_vreg_init",
                           *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(piVar7 + -4),iVar1);
          }
          uVar4 = *(undefined4 *)(param_1 + 0x570);
          puVar3 = &DAT_00121ddc;
        }
      }
      else {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "ERR:%s: PCIe: RC%d can\'t set voltage for %s: %d\n","msm_pcie_vreg_init",
                         *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(piVar7 + -4),iVar1);
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: PCIe: RC%d can\'t set voltage for %s: %d\n","msm_pcie_vreg_init",
                         *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(piVar7 + -4),iVar1);
        }
        uVar4 = *(undefined4 *)(param_1 + 0x570);
        puVar3 = &DAT_00124850;
      }
      _printk(puVar3,"msm_pcie_vreg_init",uVar4,*(undefined8 *)(piVar7 + -4),iVar1);
      if (uVar8 != 0xffffffffffffffff) {
        do {
          lVar6 = param_1 + (uVar8 & 0xffffffff) * 0x20;
          lVar9 = *(long *)(lVar6 + 0x20);
          if (lVar9 != 0) {
            regulator_disable(lVar9);
            puVar5 = (undefined8 *)(lVar6 + 0x28);
            __s1 = (char *)*puVar5;
            iVar2 = strcmp(__s1,"vreg-cx");
            if ((iVar2 == 0) || (iVar2 = strcmp(__s1,"vreg-mx"), iVar2 == 0)) {
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: Removing %s vote.\n"
                               ,"msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),__s1);
                ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: Removing %s vote.\n",
                               "msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),*puVar5);
              }
              regulator_set_voltage(lVar9,0x10,0xffff);
            }
            if (*(int *)(param_1 + (uVar8 & 0xffffffff) * 0x20 + 0x38) != 0) {
              iVar1 = regulator_set_load(lVar9,0);
              if (iVar1 < 0) {
                if (param_1 != 0) {
                  ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                                 "ERR:%s: PCIe: RC%d can\'t set mode for %s: %d\n",
                                 "msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),*puVar5,iVar1
                                );
                  ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                                 "%s: PCIe: RC%d can\'t set mode for %s: %d\n","msm_pcie_vreg_init",
                                 *(undefined4 *)(param_1 + 0x570),*puVar5,iVar1);
                }
                _printk(&DAT_00121ddc,"msm_pcie_vreg_init",*(undefined4 *)(param_1 + 0x570),*puVar5,
                        iVar1);
              }
            }
          }
          iVar2 = (int)uVar8;
          uVar8 = uVar8 - 1;
        } while (iVar2 != 0);
      }
      goto LAB_0010d954;
    }
LAB_0010d890:
    uVar8 = uVar8 + 1;
    piVar7 = piVar7 + 8;
  } while (uVar8 != 5);
  iVar1 = 0;
LAB_0010d954:
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_vreg_init",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_vreg_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_pcie_pipe_clk_init @ 0010dbc4 size=788
// signature: undefined msm_pcie_pipe_clk_init(void)
// callers: [msm_pcie_enable, msm_pcie_enable_link]
//------------------------------------------------------------

int msm_pcie_pipe_clk_init(long param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n",
                   "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_pipe_clk_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  if (*(int *)(param_1 + 0x360) != 0) {
    uVar2 = 0;
    do {
      lVar6 = *(long *)(param_1 + 0x368);
      plVar4 = (long *)(lVar6 + (long)(int)uVar2 * 0x18);
      if (*plVar4 != 0) {
        if (*(int *)(lVar6 + (long)(int)uVar2 * 0x18 + 0x10) == 0) {
LAB_0010dcac:
          lVar5 = *plVar4;
          iVar1 = clk_prepare(lVar5);
          if (iVar1 == 0) {
            iVar1 = clk_enable(lVar5);
            if (iVar1 == 0) {
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                               "DBG2:%s: RC%d enabled pipe clk %s.\n","msm_pcie_pipe_clk_init",
                               *(undefined4 *)(param_1 + 0x570),
                               *(undefined8 *)(lVar6 + (long)(int)uVar2 * 0x18 + 8));
              }
              goto LAB_0010dc50;
            }
            clk_unprepare(lVar5);
          }
          if (param_1 != 0) {
            lVar5 = lVar6 + (long)(int)uVar2 * 0x18;
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d failed to enable clk %s.\n","msm_pcie_pipe_clk_init",
                           *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar5 + 8));
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d failed to enable clk %s.\n","msm_pcie_pipe_clk_init",
                           *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar5 + 8));
          }
          _printk(&DAT_00123f6e,"msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570),
                  *(undefined8 *)(lVar6 + (long)(int)uVar2 * 0x18 + 8));
        }
        else {
          iVar1 = clk_set_rate();
          if (iVar1 == 0) {
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                             "DBG2:%s: PCIe: RC%d set rate for clk %s: %d.\n",
                             "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570),
                             *(undefined8 *)(lVar6 + (long)(int)uVar2 * 0x18 + 8),0);
            }
            goto LAB_0010dcac;
          }
          if (param_1 != 0) {
            lVar5 = lVar6 + (long)(int)uVar2 * 0x18;
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d can\'t set rate for clk %s: %d.\n",
                           "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570),
                           *(undefined8 *)(lVar5 + 8),iVar1);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d can\'t set rate for clk %s: %d.\n",
                           "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570),
                           *(undefined8 *)(lVar5 + 8),iVar1);
          }
          _printk(&DAT_0012a5f1,"msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570),
                  *(undefined8 *)(lVar6 + (long)(int)uVar2 * 0x18 + 8),iVar1);
        }
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "DBG1:%s: RC%d disable pipe clocks for error handling.\n",
                         "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570));
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: RC%d disable pipe clocks for error handling.\n",
                         "msm_pcie_pipe_clk_init",*(undefined4 *)(param_1 + 0x570));
        }
        if (uVar2 != 0) {
          iVar3 = uVar2 - 1;
          do {
            lVar6 = *(long *)(*(long *)(param_1 + 0x368) + (long)iVar3 * 0x18);
            if (lVar6 != 0) {
              clk_disable(lVar6);
              clk_unprepare(lVar6);
            }
            iVar3 = iVar3 + -1;
          } while (iVar3 != -1);
        }
        goto LAB_0010dcf0;
      }
LAB_0010dc50:
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0x360));
  }
  iVar1 = 0;
LAB_0010dcf0:
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_pipe_clk_init"
                   ,*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_pipe_clk_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  return iVar1;
}



//------------------------------------------------------------
// msm_pcie_gpio_init @ 0010ded8 size=580
// signature: undefined msm_pcie_gpio_init(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

int msm_pcie_gpio_init(long param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  undefined8 *puVar8;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_gpio_init",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d\n","msm_pcie_gpio_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  uVar5 = (ulong)*(uint *)(param_1 + 0x3d8);
  if (*(uint *)(param_1 + 0x3d8) != 0) {
    uVar7 = 0;
    puVar8 = (undefined8 *)(param_1 + 0xe0);
    do {
      if (uVar7 == 5) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10e11c);
        (*pcVar2)();
      }
      if (*(int *)(puVar8 + 1) != 0) {
        iVar3 = gpio_request(*(int *)(puVar8 + 1),*puVar8);
        if (iVar3 != 0) {
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d can\'t get gpio %s; %d\n","msm_pcie_gpio_init",
                           *(undefined4 *)(param_1 + 0x570),*puVar8,iVar3);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d can\'t get gpio %s; %d\n","msm_pcie_gpio_init",
                           *(undefined4 *)(param_1 + 0x570),*puVar8,iVar3);
          }
          _printk(&DAT_00122f77,"msm_pcie_gpio_init",*(undefined4 *)(param_1 + 0x570),*puVar8,iVar3)
          ;
LAB_0010e0b0:
          if (uVar7 == 0) {
            return iVar3;
          }
          iVar6 = (int)uVar7;
          gpio_free(*(undefined4 *)(param_1 + (ulong)(iVar6 - 1U) * 0x20 + 0xe8));
          if (iVar6 - 1U == 0) {
            return iVar3;
          }
          gpio_free(*(undefined4 *)(param_1 + (ulong)(iVar6 - 2U) * 0x20 + 0xe8));
          if (iVar6 - 2U == 0) {
            return iVar3;
          }
          gpio_free(*(undefined4 *)(param_1 + (ulong)(iVar6 - 3U) * 0x20 + 0xe8));
          if (iVar6 - 3U == 0) {
            return iVar3;
          }
          gpio_free(*(undefined4 *)(param_1 + (ulong)(iVar6 - 4U) * 0x20 + 0xe8));
          if (iVar6 - 4U == 0) {
            return iVar3;
          }
          gpio_free(*(undefined4 *)(param_1 + (ulong)(iVar6 - 5) * 0x20 + 0xe8));
          return iVar3;
        }
        if (*(char *)((long)puVar8 + 0xc) == '\0') {
          gpio_to_desc(*(undefined4 *)(puVar8 + 1));
          iVar3 = gpiod_direction_input();
        }
        else {
          uVar1 = *(undefined4 *)((long)puVar8 + 0x14);
          uVar4 = gpio_to_desc(*(undefined4 *)(puVar8 + 1));
          iVar3 = gpiod_direction_output_raw(uVar4,uVar1);
        }
        if (iVar3 != 0) {
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d can\'t set direction for GPIO %s:%d\n",
                           "msm_pcie_gpio_init",*(undefined4 *)(param_1 + 0x570),*puVar8,iVar3);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d can\'t set direction for GPIO %s:%d\n",
                           "msm_pcie_gpio_init",*(undefined4 *)(param_1 + 0x570),*puVar8,iVar3);
          }
          _printk(&DAT_00129df1,"msm_pcie_gpio_init",*(undefined4 *)(param_1 + 0x570),*puVar8,iVar3)
          ;
          gpio_free(*(undefined4 *)(puVar8 + 1));
          goto LAB_0010e0b0;
        }
        uVar5 = (ulong)*(uint *)(param_1 + 0x3d8);
      }
      uVar7 = uVar7 + 1;
      puVar8 = puVar8 + 4;
    } while (uVar7 < uVar5);
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_core_phy_reset @ 0010e11c size=616
// signature: undefined msm_pcie_core_phy_reset(void)
// callers: [msm_pcie_disable, msm_pcie_enable]
//------------------------------------------------------------

int msm_pcie_core_phy_reset(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n",
                   "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_core_phy_reset",
                   *(undefined4 *)(param_1 + 0x570));
  }
  lVar5 = 0;
  iVar1 = 0;
  do {
    while (iVar2 = iVar1, lVar3 = param_1 + lVar5 * 0x18, *(long *)(lVar3 + 0x2a0) == 0) {
LAB_0010e1cc:
      lVar5 = lVar5 + 1;
      iVar1 = iVar2;
      if (lVar5 == 5) {
        if (param_1 == 0) {
          return iVar2;
        }
LAB_0010e328:
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n",
                       "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_core_phy_reset"
                       ,*(undefined4 *)(param_1 + 0x570));
        return iVar2;
      }
    }
    iVar1 = reset_control_assert();
    if (iVar1 == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n",
                       "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(param_1 + lVar5 * 0x18 + 0x2a8));
      }
    }
    else {
      if (param_1 != 0) {
        lVar4 = param_1 + lVar5 * 0x18;
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n",
                       "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(lVar4 + 0x2a8));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d failed to assert reset for %s.\n","msm_pcie_core_phy_reset",
                       *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar4 + 0x2a8));
      }
      _printk(&DAT_0012cc3a,"msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
              *(undefined8 *)(param_1 + lVar5 * 0x18 + 0x2a8));
    }
    usleep_range_state(1000,0x3ed,2);
    iVar2 = reset_control_deassert(*(undefined8 *)(lVar3 + 0x2a0));
    if (iVar2 != 0) {
      if (param_1 != 0) {
        lVar3 = param_1 + lVar5 * 0x18;
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n",
                       "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(lVar3 + 0x2a8));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d failed to deassert reset for %s.\n","msm_pcie_core_phy_reset"
                       ,*(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar3 + 0x2a8));
      }
      _printk(&DAT_0012f9c2,"msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
              *(undefined8 *)(param_1 + lVar5 * 0x18 + 0x2a8));
      goto LAB_0010e1cc;
    }
    if (param_1 == 0) {
      lVar5 = lVar5 + 1;
      iVar1 = 0;
      if (lVar5 == 5) {
        return 0;
      }
    }
    else {
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n",
                     "msm_pcie_core_phy_reset",*(undefined4 *)(param_1 + 0x570),
                     *(undefined8 *)(param_1 + lVar5 * 0x18 + 0x2a8));
      iVar2 = 0;
      lVar5 = lVar5 + 1;
      iVar1 = 0;
      if (lVar5 == 5) goto LAB_0010e328;
    }
  } while( true );
}



//------------------------------------------------------------
// msm_pcie_enable_link @ 0010e384 size=5176
// signature: undefined msm_pcie_enable_link(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pcie_enable_link(long *param_1)

{
  long *plVar1;
  long lVar2;
  bool bVar3;
  byte bVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ulong uVar12;
  undefined8 uVar13;
  long lVar14;
  ulong uVar15;
  code *pcVar16;
  long lVar17;
  long lVar18;
  undefined4 *puVar19;
  uint *puVar20;
  undefined4 *puVar21;
  long *plVar22;
  char *pcVar23;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar14 = sp_el0;
  local_68 = *(long *)(lVar14 + 0x638);
  local_78 = 0;
  uStack_70 = 0;
  plVar22 = (long *)param_1[0x33];
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  local_c0 = 0;
  if ((int)param_1[0xaa] == 0) {
    uVar5 = readl_relaxed(param_1[0x70] + 0x170);
    *(undefined4 *)(param_1 + 0xaa) = uVar5;
  }
  lVar14 = param_1[0x70];
  writel_relaxed(4,lVar14 + 0x1000);
  readl_relaxed(lVar14 + 0x1000);
  if (*(char *)((long)param_1 + 0x4da) != '\0') {
    lVar14 = param_1[0x70] + 0x20;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 & 0xffffffdf,lVar14);
    readl_relaxed(lVar14);
  }
  lVar14 = param_1[0x70] + 0x40;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 & 0xfffffffe,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x70];
  writel_relaxed(0x365e,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x70] + 0x174;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 0x10,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x70];
  writel_relaxed(0,lVar14 + 0x22c);
  readl_relaxed(lVar14 + 0x22c);
  lVar14 = param_1[0x70] + 0x22c;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 0x7f80d202,lVar14);
  readl_relaxed(lVar14);
  if (param_1 != (long *)0x0) {
    lVar18 = param_1[0xe5];
    lVar14 = param_1[0xae];
    uVar5 = readl_relaxed(param_1[0x70] + 0x22c);
    ipc_log_string(lVar18,"INFO:%s: PCIe: RC%d: PCIE20_PARF_INT_ALL_MASK: 0x%x\n",
                   "msm_pcie_enable_link",(int)lVar14,uVar5);
    lVar18 = param_1[0xe4];
    lVar14 = param_1[0xae];
    uVar5 = readl_relaxed(param_1[0x70] + 0x22c);
    ipc_log_string(lVar18,"%s: PCIe: RC%d: PCIE20_PARF_INT_ALL_MASK: 0x%x\n","msm_pcie_enable_link",
                   (int)lVar14,uVar5);
  }
  lVar14 = param_1[0xae];
  uVar5 = readl_relaxed(param_1[0x70] + 0x22c);
  _printk(&DAT_0012b62d,"msm_pcie_enable_link",(int)lVar14,uVar5);
  lVar14 = param_1[0x70];
  puVar19 = (undefined4 *)param_1[0x33];
  puVar21 = (undefined4 *)param_1[0x39];
  writel_relaxed(*puVar19,lVar14 + 0x350);
  readl_relaxed(lVar14 + 0x350);
  lVar14 = param_1[0x70];
  writel_relaxed(puVar19[1],lVar14 + 0x354);
  readl_relaxed(lVar14 + 0x354);
  lVar14 = param_1[0x70];
  writel_relaxed(*puVar21,lVar14 + 0x634);
  readl_relaxed(lVar14 + 0x634);
  lVar14 = param_1[0x70];
  writel_relaxed(puVar21[1],lVar14 + 0x638);
  readl_relaxed(lVar14 + 0x638);
  lVar14 = param_1[0x70];
  writel_relaxed(0,lVar14 + 0x358);
  readl_relaxed(lVar14 + 0x358);
  lVar14 = param_1[0x70];
  writel_relaxed(0x80000000,lVar14 + 0x35c);
  readl_relaxed(lVar14 + 0x35c);
  if (*(char *)((long)param_1 + 0x56c) == '\0') {
    uVar6 = *(uint *)((long)param_1 + 0x514);
    if (uVar6 == 0) {
      uVar6 = readl_relaxed(param_1[0x70] + 0x1a8);
    }
    uVar6 = uVar6 | 0x80000000;
    lVar14 = param_1[0x70] + 0x1a8;
  }
  else {
    uVar6 = readl_relaxed(param_1[0x70] + 0x1a8);
    lVar14 = param_1[0x70];
    writel_relaxed(uVar6 & 0x7fffffff,lVar14 + 0x1a8);
    readl_relaxed(lVar14 + 0x1a8);
    uVar6 = readl_relaxed(param_1[0x70] + 0x1a4);
    uVar6 = uVar6 & 0xfffffffe;
    lVar14 = param_1[0x70] + 0x1a4;
  }
  writel_relaxed(uVar6,lVar14);
  readl_relaxed(lVar14);
  if (*(char *)((long)param_1 + 0x563) != '\0') {
    uVar6 = readl_relaxed(param_1[0x70] + 0x4a0);
    lVar14 = param_1[0x70];
    writel_relaxed(uVar6 & 0xfffffffe,lVar14 + 0x4a0);
    readl_relaxed(lVar14 + 0x4a0);
  }
  if ((uint *)param_1[0xdd] != (uint *)0x0) {
    puVar20 = (uint *)param_1[0xdd];
    for (iVar10 = (int)param_1[0xdc]; iVar10 != 0; iVar10 = iVar10 + -1) {
      uVar6 = *puVar20;
      lVar14 = param_1[0x77];
      writel_relaxed(puVar20[1],lVar14 + (ulong)uVar6);
      readl_relaxed(lVar14 + (ulong)uVar6);
      puVar20 = puVar20 + 2;
    }
  }
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: Initializing PHY\n","pcie_phy_init",
                   (int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: Initializing PHY\n","pcie_phy_init",
                   (int)param_1[0xae]);
  }
  puVar20 = (uint *)param_1[0xdb];
  if (puVar20 != (uint *)0x0) {
    iVar10 = *(int *)((long)param_1 + 0x6d4);
    while (iVar10 != 0) {
      uVar6 = *puVar20;
      lVar14 = param_1[0x71];
      iVar10 = iVar10 + -1;
      writel_relaxed(puVar20[1],lVar14 + (ulong)uVar6);
      readl_relaxed(lVar14 + (ulong)uVar6);
      uVar6 = puVar20[2];
      if (uVar6 != 0) {
        usleep_range_state(uVar6,uVar6 + 1,2);
      }
      puVar20 = puVar20 + 3;
    }
  }
  usleep_range_state(0x3e3,0x3ed,2);
  msm_pcie_pipe_clk_init(param_1);
  DataSynchronizationBarrier(3,2,0);
  msm_pcie_pipe_reset(param_1);
  DataSynchronizationBarrier(3,2,0);
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe RC%d: waiting for phy ready...\n","pcie_phy_init",
                   (int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe RC%d: waiting for phy ready...\n","pcie_phy_init",
                   (int)param_1[0xae]);
  }
  lVar14 = 0;
  do {
    if ((param_1[0x78] != 0) ||
       (uVar12 = readl_relaxed(param_1[0x71] + (ulong)*(uint *)(param_1 + 0xa3)),
       ((uVar12 & 0xffffffff) >> ((ulong)*(uint *)((long)param_1 + 0x51c) & 0x3f) & 1) == 0)) break;
    lVar14 = lVar14 + 1;
    usleep_range_state(1000,0x3ed,2);
  } while (lVar14 != 10);
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: number of PHY retries: %ld.\n",
                   "pcie_phy_init",(int)param_1[0xae],lVar14);
    ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: number of PHY retries: %ld.\n","pcie_phy_init",
                   (int)param_1[0xae],lVar14);
  }
  if ((param_1[0x78] == 0) &&
     (uVar12 = readl_relaxed(param_1[0x71] + (ulong)*(uint *)(param_1 + 0xa3)),
     ((uVar12 & 0xffffffff) >> ((ulong)*(uint *)((long)param_1 + 0x51c) & 0x3f) & 1) != 0)) {
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe PHY RC%d failed to come up!\n","pcie_phy_init",
                     (int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe PHY RC%d failed to come up!\n","pcie_phy_init",
                     (int)param_1[0xae]);
    }
    _printk(&DAT_00121e3e,"pcie_phy_init",(int)param_1[0xae]);
    pcie_phy_dump(param_1);
    uVar13 = 0xffffffed;
    goto LAB_0010f710;
  }
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"INFO:%s: PCIe RC%d PHY is ready!\n","pcie_phy_init",
                   (int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe RC%d PHY is ready!\n","pcie_phy_init",(int)param_1[0xae])
    ;
  }
  _printk(&DAT_0012aed8,"pcie_phy_init",(int)param_1[0xae]);
  if ((param_1[0x84] != 0) && (param_1[0x85] != 0)) {
    clk_set_parent();
  }
  iVar10 = *(int *)((long)param_1 + 0x50c) * 1000;
  usleep_range_state(iVar10,iVar10,2);
  if ((int)param_1[0x25] != 0) {
    lVar14 = param_1[0x26];
    uVar13 = gpio_to_desc();
    gpiod_set_raw_value(uVar13,(int)lVar14);
  }
  uVar6 = readl_relaxed(param_1[0x74] + 0x7c);
  *(uint *)((long)param_1 + 0x404) = uVar6 >> 4 & 0x3f;
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: Maximum supported link width is %d\n",
                   "msm_pcie_enable_link",(int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: Maximum supported link width is %d\n",
                   "msm_pcie_enable_link",(int)param_1[0xae],*(undefined4 *)((long)param_1 + 0x404))
    ;
  }
  uVar6 = *(uint *)(param_1 + 0xa0);
  if (uVar6 != 0) {
    uVar9 = *(uint *)((long)param_1 + 0x404);
    if (uVar9 < uVar6) {
LAB_0010eba4:
      if (param_1 != (long *)0x0) {
        ipc_log_string(param_1[0xe5],
                       "ERR:%s: PCIe: RC%d: unsupported link width request: %d, Max: %d\n",
                       "msm_pcie_set_link_width",(int)param_1[0xae],uVar6 & 0xfff);
        ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: unsupported link width request: %d, Max: %d\n"
                       ,"msm_pcie_set_link_width",(int)param_1[0xae],uVar6 & 0xfff,
                       *(undefined4 *)((long)param_1 + 0x404));
        uVar9 = *(uint *)((long)param_1 + 0x404);
      }
      _printk(&DAT_0012c52f,"msm_pcie_set_link_width",(int)param_1[0xae],uVar6 & 0xfff,uVar9);
      uVar13 = 0xffffffea;
      goto LAB_0010f710;
    }
    if ((uVar6 & 0xfff) == 1) {
      iVar10 = 1;
    }
    else {
      if ((uVar6 & 0xfff) != 2) goto LAB_0010eba4;
      iVar10 = 3;
    }
    lVar14 = param_1[0x74] + 0x710;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 & 0xffc0ffff | iVar10 << 0x10,lVar14);
    readl_relaxed(lVar14);
    lVar14 = param_1[0x74] + 0x80c;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 & 0xffffe0ff | iVar10 << 8,lVar14);
    readl_relaxed(lVar14);
    lVar14 = param_1[0x74] + 0x8bc;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 | 1,lVar14);
    readl_relaxed(lVar14);
    lVar14 = param_1[0x74] + 0x7c;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 & 0xfffffc0f | iVar10 << 4,lVar14);
    readl_relaxed(lVar14);
    lVar14 = param_1[0x74] + 0x8bc;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 & 0xfffffffe,lVar14);
    readl_relaxed(lVar14);
    uVar6 = readl_relaxed(param_1[0x74] + 0x7c);
    *(uint *)((long)param_1 + 0x404) = uVar6 >> 4 & 0x3f;
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe5],
                     "DBG1:%s: PCIe: RC%d: updated maximum link width supported to: %d\n",
                     "msm_pcie_set_link_width",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: updated maximum link width supported to: %d\n",
                     "msm_pcie_set_link_width",(int)param_1[0xae],
                     *(undefined4 *)((long)param_1 + 0x404));
    }
  }
  lVar14 = param_1[0x74] + 0x8bc;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 1,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x74] + 8;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 & 0xff | 0x6040000,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x74] + 0x8bc;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 & 0xfffffffe,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x70] + 0x2c4;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 & 0xfffffffe,lVar14);
  readl_relaxed(lVar14);
  if (*(uint *)(param_1 + 0xaa) >> 4 < 0x147) {
    lVar14 = param_1[0x70] + 0x2c4;
    uVar6 = readl_relaxed(lVar14);
    writel_relaxed(uVar6 | 0x100,lVar14);
    readl_relaxed(lVar14);
  }
  lVar14 = param_1[0x74] + 0x714;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 0x20,lVar14);
  readl_relaxed(lVar14);
  lVar14 = param_1[0x74] + 0x8bc;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 1,lVar14);
  readl_relaxed(lVar14);
  if (*(int *)((long)param_1 + 0x564) != 0) {
    lVar14 = param_1[0x74];
    writel_relaxed(*(int *)((long)param_1 + 0x564),lVar14);
    readl_relaxed(lVar14);
  }
  bVar4 = readl_relaxed(param_1[0x74] + 0x34);
  uVar6 = (uint)bVar4;
  if (bVar4 != 0) {
    uVar12 = 0;
    do {
      uVar15 = (ulong)uVar6;
      uVar6 = readl_relaxed(param_1[0x74] + uVar15);
      if (0x14 < (uVar6 & 0xff)) break;
      if ((uVar6 & 0xff) == 0x11) {
        lVar14 = param_1[0x74] + 0x34;
        if ((int)uVar12 != 0) {
          lVar14 = param_1[0x74] + uVar12 + 1;
        }
        writeb(uVar6 >> 8,lVar14);
        break;
      }
      uVar6 = uVar6 >> 8 & 0xff;
      uVar12 = uVar15;
    } while (uVar6 != 0);
  }
  lVar14 = param_1[0x74] + 0x8bc;
  uVar6 = readl_relaxed(lVar14);
  writel_relaxed(uVar6 | 1,lVar14);
  readl_relaxed(lVar14);
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"INFO:%s: PCIe: Release the reset of endpoint of RC%d.\n",
                   "msm_pcie_enable_link",(int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe: Release the reset of endpoint of RC%d.\n",
                   "msm_pcie_enable_link",(int)param_1[0xae]);
  }
  _printk(&DAT_0012f9f5,"msm_pcie_enable_link",(int)param_1[0xae]);
  msm_pcie_config_perst(param_1,0);
  usleep_range_state((int)param_1[0xa8],*(undefined4 *)((long)param_1 + 0x544),2);
  lVar18 = _jiffies;
  uVar6 = jiffies_to_usecs(0x3ffffffffffffffe);
  lVar14 = 0x3ffffffffffffffe;
  if (999999 < uVar6) {
    lVar14 = 0xfa;
  }
  plVar1 = param_1 + 0x1a6;
  if ((param_1[0x1a6] != 0) && (pcVar16 = (code *)param_1[0x1b4], pcVar16 != (code *)0x0)) {
    if (*(int *)(pcVar16 + -4) != -0x6f96fed1) {
                    /* WARNING: Does not return */
      pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10ed30);
      (*pcVar16)();
    }
    (*pcVar16)(plVar1);
    msleep(0x14);
  }
  lVar17 = param_1[0x74] + 0x80c;
  uVar6 = readl_relaxed(lVar17);
  writel_relaxed(uVar6 & 0xffffe0ff | 0x100,lVar17);
  readl_relaxed(lVar17);
  uVar6 = readl_relaxed(param_1[0x74] + 0x7c);
  if (2 < (uVar6 & 0xf)) {
    uVar9 = 0;
    do {
      lVar17 = param_1[0x74] + 0x890;
      uVar7 = readl_relaxed(lVar17);
      writel_relaxed(uVar7 & 0xfcffffff | uVar9,lVar17);
      readl_relaxed(lVar17);
      iVar10 = *(int *)((long)param_1 + 0x52c);
      lVar17 = param_1[0x74] + 0x8a8;
      uVar7 = readl_relaxed(lVar17);
      writel_relaxed(uVar7 & 0xff0000ff | iVar10 << 8,lVar17);
      readl_relaxed(lVar17);
      lVar17 = param_1[0x74] + 0x890;
      uVar7 = readl_relaxed(lVar17);
      writel_relaxed(uVar7 & 0xfffffffe,lVar17);
      readl_relaxed(lVar17);
      uVar7 = *(uint *)((long)param_1 + 0x534);
      lVar17 = param_1[0x74] + 0x8ac;
      uVar8 = readl_relaxed(lVar17);
      writel_relaxed(uVar8 & 0xffffffe0 | uVar7,lVar17);
      readl_relaxed(lVar17);
      uVar9 = uVar9 + 0x1000000;
    } while ((uVar6 & 0xf) * 0x1000000 + 0xfe000000 != uVar9);
  }
  uVar6 = readl_relaxed(param_1[0x74] + 0x7c);
  lVar17 = param_1[0x74] + 0x8bc;
  uVar9 = readl_relaxed(lVar17);
  writel_relaxed(uVar9 | 1,lVar17);
  readl_relaxed(lVar17);
  uVar9 = readl_relaxed(param_1[0x74] + 0x3c);
  lVar17 = param_1[0x74];
  writel_relaxed(uVar9 & 0xffff00ff | 0x100,lVar17 + 0x3c);
  readl_relaxed(lVar17 + 0x3c);
  if ((uVar6 & 0xf) < 3) {
LAB_0010f134:
    lVar17 = param_1[0x74] + 0x8bc;
    uVar6 = readl_relaxed(lVar17);
    writel_relaxed(uVar6 & 0xfffffffe,lVar17);
    readl_relaxed(lVar17);
  }
  else {
    uVar12 = readl_relaxed(param_1[0x74] + 0x100);
    if ((uint)uVar12 != 0) {
      if (((uint)uVar12 & 0xffff) == 0x19) {
        uVar12 = 0x10c;
      }
      else {
        uVar9 = 0xfffffe20;
        do {
          uVar7 = (uint)(uVar12 >> 0x14) & 0xffc;
          if (uVar7 < 0x100) goto LAB_0010f158;
          uVar12 = readl_relaxed(param_1[0x74] + (ulong)uVar7);
          bVar3 = 0xfffffffe < uVar9;
          uVar9 = uVar9 + 1;
          if (bVar3) goto LAB_0010f158;
        } while (((uint)uVar12 & 0xffff) != 0x19);
        uVar12 = (ulong)(uVar7 + 0xc);
      }
      lVar17 = param_1[0x74];
      uVar9 = uVar6 >> 4 & 0x3f;
      writel_relaxed((int)param_1[0xa6],lVar17 + uVar12);
      readl_relaxed(lVar17 + uVar12);
      if (2 < uVar9) {
        uVar7 = 2;
        do {
          uVar12 = uVar12 + 4;
          lVar17 = param_1[0x74];
          writel_relaxed((int)param_1[0xa6],lVar17 + uVar12);
          readl_relaxed(lVar17 + uVar12);
          uVar7 = uVar7 + 2;
        } while (uVar7 < uVar9);
      }
      if (3 < (uVar6 & 0xf)) {
        uVar12 = readl_relaxed(param_1[0x74] + 0x100);
        if ((uint)uVar12 == 0) goto LAB_0010f158;
        if (((uint)uVar12 & 0xffff) == 0x26) {
          uVar12 = 0x120;
        }
        else {
          uVar6 = 0xfffffe20;
          do {
            uVar7 = (uint)(uVar12 >> 0x14) & 0xffc;
            if (uVar7 < 0x100) goto LAB_0010f158;
            uVar12 = readl_relaxed(param_1[0x74] + (ulong)uVar7);
            bVar3 = 0xfffffffe < uVar6;
            uVar6 = uVar6 + 1;
            if (bVar3) goto LAB_0010f158;
          } while (((uint)uVar12 & 0xffff) != 0x26);
          uVar12 = (ulong)(uVar7 + 0x20);
        }
        lVar17 = param_1[0x74];
        writel_relaxed((int)param_1[0xa6],lVar17 + uVar12);
        readl_relaxed(lVar17 + uVar12);
        if (4 < uVar9) {
          lVar17 = 4;
          do {
            lVar2 = param_1[0x74] + uVar12 + lVar17;
            writel_relaxed((int)param_1[0xa6],lVar2);
            readl_relaxed(lVar2);
            lVar17 = lVar17 + 4;
          } while ((uint)lVar17 < uVar9);
        }
      }
      goto LAB_0010f134;
    }
  }
LAB_0010f158:
  uVar6 = *(uint *)((long)param_1 + 0x4f4);
  if (uVar6 != 0) {
    lVar17 = param_1[0x74] + 0xa0;
    uVar9 = readl_relaxed(lVar17);
    writel_relaxed(uVar9 & 0xfffffff0 | uVar6,lVar17);
    readl_relaxed(lVar17);
  }
  lVar2 = param_1[0xa9];
  lVar17 = param_1[0x74] + 0x78;
  uVar6 = readl_relaxed(lVar17);
  writel_relaxed(uVar6 & 0xffff8fff | (int)lVar2 << 0xc,lVar17);
  readl_relaxed(lVar17);
  lVar17 = param_1[0x70] + 0x1b0;
  uVar6 = readl_relaxed(lVar17);
  writel_relaxed(uVar6 | 0x100,lVar17);
  readl_relaxed(lVar17);
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: %s","msm_pcie_link_train","check if link is up\n");
    ipc_log_string(param_1[0xe4],"%s: %s","msm_pcie_link_train","check if link is up\n");
  }
  uVar6 = 0;
  do {
    while( true ) {
      usleep_range_state(5000,0x13ed,2);
      uVar9 = readl_relaxed(param_1[0x72] + 8);
      if (param_1 != (long *)0x0) {
        uVar7 = uVar9 >> 0xc & 0x3f;
        if (uVar7 < 0x24) {
          pcVar23 = (&msm_pcie_ltssm_str)[uVar7];
          ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe RC%d: LTSSM_STATE: %s\n","msm_pcie_link_train"
                         ,(int)param_1[0xae],pcVar23);
        }
        else {
          ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe RC%d: LTSSM_STATE: %s\n","msm_pcie_link_train"
                         ,(int)param_1[0xae],"LTSSM_INVALID");
          pcVar23 = "LTSSM_INVALID";
        }
        ipc_log_string(param_1[0xe4],"%s: PCIe RC%d: LTSSM_STATE: %s\n","msm_pcie_link_train",
                       (int)param_1[0xae],pcVar23);
      }
      if ((uVar9 >> 10 & 1) != 0) break;
      bVar3 = *(uint *)(param_1 + 0x9e) <= uVar6;
      uVar6 = uVar6 + 1;
      if (bVar3) goto LAB_0010f324;
    }
    uVar7 = readl_relaxed(param_1[0x74] + 0x80);
    uVar9 = uVar6;
    if ((uVar7 >> 0x1d & 1) != 0) break;
    uVar9 = uVar6 + 1;
    bVar3 = uVar6 < *(uint *)(param_1 + 0x9e);
    uVar6 = uVar9;
  } while (bVar3);
  uVar6 = readl_relaxed(param_1[0x74] + 0x80);
  if ((uVar6 >> 0x1d & 1) == 0) {
LAB_0010f324:
    if ((*plVar1 != 0) && (pcVar16 = (code *)param_1[0x1b3], pcVar16 != (code *)0x0)) {
      if (*(int *)(pcVar16 + -4) != -0x6f96fed1) {
                    /* WARNING: Does not return */
        pcVar16 = (code *)SoftwareBreakpoint(0x8228,0x10f350);
        (*pcVar16)();
      }
      (*pcVar16)(plVar1);
    }
    if (param_1 == (long *)0x0) {
      _printk(&DAT_0012f140,"msm_pcie_link_train",_DAT_00000570);
      msm_pcie_config_perst(0,1);
    }
    else {
      ipc_log_string(param_1[0xe5],"INFO:%s: PCIe: Assert the reset of endpoint of RC%d.\n",
                     "msm_pcie_link_train",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe: Assert the reset of endpoint of RC%d.\n",
                     "msm_pcie_link_train",(int)param_1[0xae]);
      _printk(&DAT_0012f140,"msm_pcie_link_train",(int)param_1[0xae]);
      msm_pcie_config_perst(param_1,1);
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe RC%d link initialization failed\n",
                     "msm_pcie_link_train",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe RC%d link initialization failed\n",
                     "msm_pcie_link_train",(int)param_1[0xae]);
    }
    _printk(&DAT_00129e8b,"msm_pcie_link_train",(int)param_1[0xae]);
    uVar13 = 0xffffffff;
    goto LAB_0010f710;
  }
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: Link is up after %d checkings\n","msm_pcie_link_train",
                   uVar9);
    ipc_log_string(param_1[0xe4],"%s: Link is up after %d checkings\n","msm_pcie_link_train",uVar9);
    ipc_log_string(param_1[0xe5],"INFO:%s: PCIe RC%d link initialized\n","msm_pcie_link_train",
                   (int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe RC%d link initialized\n","msm_pcie_link_train",
                   (int)param_1[0xae]);
  }
  _printk(&DAT_0012aef7,"msm_pcie_link_train",(int)param_1[0xae]);
  uVar6 = readl_relaxed(param_1[0x74] + 0x80);
  *(uint *)((long)param_1 + 0x4fc) = uVar6 >> 0x10 & 0xf;
  *(uint *)((long)param_1 + 0x504) = uVar6 >> 0x14 & 0x3f;
  if (param_1 != (long *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: Link is up at Gen%dX%d\n",
                   "msm_pcie_link_train",(int)param_1[0xae]);
    ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: Link is up at Gen%dX%d\n","msm_pcie_link_train",
                   (int)param_1[0xae],*(undefined4 *)((long)param_1 + 0x4fc),
                   *(undefined4 *)((long)param_1 + 0x504));
  }
  if ((((*(char *)((long)param_1 + 0x579) == '\0') && (*(char *)((long)param_1 + 0x889) != '\0')) &&
      (*(int *)((long)param_1 + 0x4f4) != 0)) &&
     (*(int *)((long)param_1 + 0x4f4) != *(int *)((long)param_1 + 0x4fc))) {
                    /* WARNING: Subroutine does not return */
    panic("PCIe: RC%d: Gen-speed mismatch:%d, expected:%d\n",(int)param_1[0xae]);
  }
  if (param_1[0x7f] == 0) {
LAB_0010f570:
    uVar6 = *(uint *)(param_1 + 0xa2);
  }
  else {
    uVar6 = *(uint *)((long)param_1 + 0x4fc);
    if (*(uint *)(param_1 + 0x80) <= uVar6) goto LAB_0010f570;
    if (uVar6 - 1 < *(uint *)(param_1 + 0x80)) {
      lVar17 = param_1[0x74] + 0xa0;
      uVar9 = readl_relaxed(lVar17);
      writel_relaxed(uVar9 & 0xfffffff0 | uVar6,lVar17);
      readl_relaxed(lVar17);
      msm_pcie_scale_link_bandwidth(param_1,*(undefined4 *)((long)param_1 + 0x4fc));
      goto LAB_0010f570;
    }
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d: unsupported gen speed: %d\n",
                     "msm_pcie_link_train",(int)param_1[0xae],uVar6);
      ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: unsupported gen speed: %d\n",
                     "msm_pcie_link_train",(int)param_1[0xae],*(undefined4 *)((long)param_1 + 0x4fc)
                    );
      uVar6 = *(uint *)((long)param_1 + 0x4fc);
    }
    _printk(&DAT_00122623,"msm_pcie_link_train",(int)param_1[0xae],uVar6);
    uVar6 = *(uint *)(param_1 + 0xa2);
  }
  if (uVar6 != 0) {
    if (param_1 != (long *)0x0) {
      ipc_log_string(param_1[0xe5],"DBG1:%s: switch_latency: %dms\n","msm_pcie_enable_link");
      ipc_log_string(param_1[0xe4],"%s: switch_latency: %dms\n","msm_pcie_enable_link",
                     (int)param_1[0xa2]);
      uVar6 = *(uint *)(param_1 + 0xa2);
    }
    if (uVar6 < 0x15) {
      usleep_range_state(uVar6 * 1000,uVar6 * 1000,2);
    }
    else {
      msleep(uVar6);
    }
  }
  if (*(int *)((long)param_1 + 0xdac) == 0) {
    uVar13 = msm_pcie_config_sid(param_1);
    iVar10 = (int)uVar13;
  }
  else {
    uVar13 = msm_pcie_config_tc_bdf_sid_map(param_1);
    iVar10 = (int)uVar13;
  }
  if (iVar10 == 0) {
    msm_pcie_config_controller(param_1);
    if (*(char *)((long)param_1 + 0xdaa) == '\0') {
      uVar13 = msm_pcie_check_ep_access(param_1,lVar14 + lVar18);
    }
    else {
      lVar14 = *plVar22;
      iVar11 = msm_of_pci_parse_bus_range(*(undefined8 *)(*param_1 + 0x2f8),&local_c8);
      iVar10 = 0x100;
      if (iVar11 == 0) {
        iVar10 = ((int)local_c0 - (int)local_c8) + 1;
      }
      if (param_1 != (long *)0x0) {
        ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: configure ECAM for bus range:%d\n",
                       "msm_pcie_enable_link",(int)param_1[0xae],iVar10);
        ipc_log_string(param_1[0xe4],"%s: RC%d: configure ECAM for bus range:%d\n",
                       "msm_pcie_enable_link",(int)param_1[0xae],iVar10);
      }
      if (2 < iVar10) {
        msm_pcie_iatu_config_shift(param_1,0,4,lVar14 + 0x100000,(int)lVar14 + 0x1fffff);
        msm_pcie_iatu_config_shift
                  (param_1,1,5,lVar14 + 0x200000,
                   (int)(lVar14 + 0x200000) + iVar10 * 0x100000 + -0x200001);
      }
      msm_pcie_iatu_setup_ecam_blocker(param_1);
      uVar13 = 0;
    }
  }
LAB_0010f710:
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar13);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_parf_cesta_config @ 0010f7bc size=116
// signature: undefined msm_pcie_parf_cesta_config(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

void msm_pcie_parf_cesta_config(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xd00);
  lVar2 = *(long *)(param_1 + 0x380) + (ulong)*(uint *)(param_1 + 0x568);
  uVar1 = readl_relaxed(lVar2);
  if (lVar3 == 0) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  else {
    uVar1 = uVar1 | 9;
    lVar2 = *(long *)(param_1 + 0x380) + (ulong)*(uint *)(param_1 + 0x568);
  }
  writel_relaxed(uVar1,lVar2);
  readl_relaxed(lVar2);
  return;
}



//------------------------------------------------------------
// msm_pcie_save_sid_config @ 0010f830 size=280
// signature: undefined msm_pcie_save_sid_config(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

undefined8 msm_pcie_save_sid_config(long *param_1)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == (long *)0x0) {
    uVar4 = 0xffffffea;
  }
  else {
    iVar2 = *(int *)((long)param_1 + 0xdac);
    lVar5 = param_1[0x70];
    uVar4 = 0x400;
    if (iVar2 != 0) {
      uVar4 = 0x100;
    }
    lVar3 = devm_kmalloc(*param_1 + 0x10,uVar4,0xdc0);
    param_1[0x1b6] = lVar3;
    if (lVar3 == 0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe: RC%d: Failed to allocate memory for SID table\n",
                     "msm_pcie_save_sid_config",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: Failed to allocate memory for SID table\n",
                     "msm_pcie_save_sid_config",(int)param_1[0xae]);
      _printk(&DAT_00124019,"msm_pcie_save_sid_config",(int)param_1[0xae]);
      uVar4 = 0xfffffff4;
    }
    else {
      lVar1 = 0x2000;
      if (iVar2 != 0) {
        lVar1 = 0x4000;
      }
      __memcpy_fromio(lVar3,lVar5 + lVar1,uVar4);
      ipc_log_string(param_1[0xe5],"DBG1:%s: PCIe: RC%d: SID config saved.\n",
                     "msm_pcie_save_sid_config",(int)param_1[0xae]);
      ipc_log_string(param_1[0xe4],"%s: PCIe: RC%d: SID config saved.\n","msm_pcie_save_sid_config",
                     (int)param_1[0xae]);
      uVar4 = 0;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// msm_pcie_restore_sid_config @ 0010f948 size=196
// signature: undefined msm_pcie_restore_sid_config(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

undefined8 msm_pcie_restore_sid_config(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  bool bVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  bVar3 = *(int *)(param_1 + 0xdac) != 0;
  lVar1 = 0x2000;
  if (bVar3) {
    lVar1 = 0x4000;
  }
  uVar2 = 0x400;
  if (bVar3) {
    uVar2 = 0x100;
  }
  __memcpy_toio(*(long *)(param_1 + 0x380) + lVar1,*(undefined8 *)(param_1 + 0xdb0),uVar2);
  ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: SID config restored.\n",
                 "msm_pcie_restore_sid_config",*(undefined4 *)(param_1 + 0x570));
  ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: SID config restored.\n",
                 "msm_pcie_restore_sid_config",*(undefined4 *)(param_1 + 0x570));
  lVar1 = *(long *)(param_1 + 0x380) + 0x2c00;
  uVar4 = readl_relaxed(lVar1);
  writel_relaxed(uVar4 & 0xfffffffe,lVar1);
  readl_relaxed(lVar1);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_disable_cesta @ 0010fa0c size=156
// signature: undefined msm_pcie_disable_cesta(void)
// callers: [msm_pcie_enable]
//------------------------------------------------------------

void msm_pcie_disable_cesta(long param_1)

{
  int iVar1;
  
  if ((*(long *)(param_1 + 0xd00) != 0) && (iVar1 = msm_pcie_cesta_map_apply(param_1,0), iVar1 != 0)
     ) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),"ERR:%s: Fail to move to D3 cold state %d\n",
                     "msm_pcie_disable_cesta",iVar1);
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: Fail to move to D3 cold state %d\n",
                     "msm_pcie_disable_cesta",iVar1);
    }
    _printk(&DAT_001296a7,"msm_pcie_disable_cesta",iVar1);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_pipe_clk_deinit @ 0010faa8 size=236
// signature: undefined msm_pcie_pipe_clk_deinit(void)
// callers: [msm_pcie_disable, msm_pcie_pm_suspend_noirq, msm_pcie_enable]
//------------------------------------------------------------

void msm_pcie_pipe_clk_deinit(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n",
                   "msm_pcie_pipe_clk_deinit",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_pipe_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  uVar1 = *(uint *)(param_1 + 0x360);
  if (uVar1 != 0) {
    uVar3 = 0;
    do {
      lVar2 = *(long *)(*(long *)(param_1 + 0x368) + (long)(int)uVar3 * 0x18);
      if (lVar2 != 0) {
        clk_disable(lVar2);
        clk_unprepare(lVar2);
        uVar1 = *(uint *)(param_1 + 0x360);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n",
                   "msm_pcie_pipe_clk_deinit",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_pipe_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_gpio_deinit @ 0010fb94 size=188
// signature: undefined msm_pcie_gpio_deinit(void)
// callers: [msm_pcie_disable, msm_pcie_enable, msm_pcie_remove]
//------------------------------------------------------------

void msm_pcie_gpio_deinit(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_gpio_deinit",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d\n","msm_pcie_gpio_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  if (*(int *)(param_1 + 0x3d8) != 0) {
    gpio_free(*(undefined4 *)(param_1 + 0xe8));
    if (1 < *(uint *)(param_1 + 0x3d8)) {
      gpio_free(*(undefined4 *)(param_1 + 0x108));
      if (2 < *(uint *)(param_1 + 0x3d8)) {
        gpio_free(*(undefined4 *)(param_1 + 0x128));
        if ((3 < *(uint *)(param_1 + 0x3d8)) &&
           (gpio_free(*(undefined4 *)(param_1 + 0x148)), 4 < *(uint *)(param_1 + 0x3d8))) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x10fc50);
          (*pcVar1)();
        }
      }
    }
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_clk_deinit @ 0010fc50 size=296
// signature: undefined msm_pcie_clk_deinit(void)
// callers: [msm_pcie_disable, msm_pcie_enable, msm_pcie_remove]
//------------------------------------------------------------

void msm_pcie_clk_deinit(long param_1)

{
  uint uVar1;
  long lVar2;
  uint uVar3;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  uVar1 = *(uint *)(param_1 + 0x370);
  if (uVar1 != 0) {
    uVar3 = 0;
    do {
      lVar2 = *(long *)(*(long *)(param_1 + 0x378) + (long)(int)uVar3 * 0x18);
      if (lVar2 != 0) {
        clk_disable(lVar2);
        clk_unprepare(lVar2);
        uVar1 = *(uint *)(param_1 + 0x370);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar1);
  }
  msm_pcie_icc_vote(param_1,0,0,0);
  if ((*(long *)(param_1 + 0x420) != 0) && (*(long *)(param_1 + 0x430) != 0)) {
    clk_set_parent();
  }
  if ((*(long *)(param_1 + 0x410) != 0) && (*(long *)(param_1 + 0x430) != 0)) {
    clk_set_parent();
  }
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_clk_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_gdsc_deinit @ 0010fd78 size=392
// signature: undefined msm_pcie_gdsc_deinit(void)
// callers: [msm_pcie_disable, msm_pcie_enable, msm_pcie_remove]
//------------------------------------------------------------

void msm_pcie_gdsc_deinit(undefined8 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  
  if (param_1 != (undefined8 *)0x0) {
    ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: entry\n","msm_pcie_gdsc_deinit",
                   *(undefined4 *)(param_1 + 0xae));
    ipc_log_string(param_1[0xe4],"%s: RC%d: entry\n","msm_pcie_gdsc_deinit",
                   *(undefined4 *)(param_1 + 0xae));
  }
  if ((param_1[2] == 0) || (iVar1 = regulator_disable(), iVar1 == 0)) {
    if ((param_1[3] == 0) || (iVar1 = regulator_disable(), iVar1 == 0)) {
      if (param_1 == (undefined8 *)0x0) {
        return;
      }
      ipc_log_string(param_1[0xe5],"DBG1:%s: RC%d: exit\n","msm_pcie_gdsc_deinit",
                     *(undefined4 *)(param_1 + 0xae));
      ipc_log_string(param_1[0xe4],"%s: RC%d: exit\n","msm_pcie_gdsc_deinit",
                     *(undefined4 *)(param_1 + 0xae));
      return;
    }
    if (param_1 != (undefined8 *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe:RC%d fail to disable GDSC-PHY (%s)\n",
                     "msm_pcie_gdsc_deinit",*(undefined4 *)(param_1 + 0xae),*(undefined8 *)*param_1)
      ;
      ipc_log_string(param_1[0xe4],"%s: PCIe:RC%d fail to disable GDSC-PHY (%s)\n",
                     "msm_pcie_gdsc_deinit",*(undefined4 *)(param_1 + 0xae),*(undefined8 *)*param_1)
      ;
    }
    puVar3 = (undefined8 *)*param_1;
    puVar2 = &DAT_00127f70;
  }
  else {
    if (param_1 != (undefined8 *)0x0) {
      ipc_log_string(param_1[0xe5],"ERR:%s: PCIe:RC%d fail to disable GDSC-CORE (%s)\n",
                     "msm_pcie_gdsc_deinit",*(undefined4 *)(param_1 + 0xae),*(undefined8 *)*param_1)
      ;
      ipc_log_string(param_1[0xe4],"%s: PCIe:RC%d fail to disable GDSC-CORE (%s)\n",
                     "msm_pcie_gdsc_deinit",*(undefined4 *)(param_1 + 0xae),*(undefined8 *)*param_1)
      ;
    }
    puVar3 = (undefined8 *)*param_1;
    puVar2 = &DAT_0012507c;
  }
  _printk(puVar2,"msm_pcie_gdsc_deinit",*(undefined4 *)(param_1 + 0xae),*puVar3);
  return;
}



//------------------------------------------------------------
// msm_pcie_vreg_deinit @ 0010ff00 size=564
// signature: undefined msm_pcie_vreg_deinit(void)
// callers: [msm_pcie_disable, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_remove]
//------------------------------------------------------------

void msm_pcie_vreg_deinit(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  char *__s1;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_vreg_deinit",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_vreg_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  lVar5 = 0;
  do {
    lVar1 = param_1 + lVar5;
    lVar4 = *(long *)(lVar1 + 0xc0);
    if (lVar4 != 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: Vreg %s is being disabled\n",
                       "msm_pcie_vreg_deinit",*(undefined8 *)(param_1 + lVar5 + 200));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: Vreg %s is being disabled\n",
                       "msm_pcie_vreg_deinit",*(undefined8 *)(param_1 + lVar5 + 200));
        lVar4 = *(long *)(lVar1 + 0xc0);
      }
      regulator_disable(lVar4);
      lVar4 = param_1 + lVar5;
      __s1 = *(char **)(lVar4 + 200);
      iVar3 = strcmp(__s1,"vreg-cx");
      if ((iVar3 == 0) || (iVar3 = strcmp(__s1,"vreg-mx"), iVar3 == 0)) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: Removing %s vote.\n",
                         "msm_pcie_vreg_deinit",*(undefined4 *)(param_1 + 0x570),__s1);
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: Removing %s vote.\n",
                         "msm_pcie_vreg_deinit",*(undefined4 *)(param_1 + 0x570),
                         *(undefined8 *)(lVar4 + 200));
        }
        regulator_set_voltage(*(undefined8 *)(lVar1 + 0xc0),0x10,0xffff);
      }
      if ((*(int *)(param_1 + lVar5 + 0xd8) != 0) &&
         (iVar3 = regulator_set_load(*(undefined8 *)(lVar1 + 0xc0),0), iVar3 < 0)) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "ERR:%s: PCIe: RC%d can\'t set mode for %s: %d\n","msm_pcie_vreg_deinit",
                         *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar4 + 200),iVar3);
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: PCIe: RC%d can\'t set mode for %s: %d\n","msm_pcie_vreg_deinit",
                         *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(lVar4 + 200),iVar3);
        }
        _printk(&DAT_00121ddc,"msm_pcie_vreg_deinit",*(undefined4 *)(param_1 + 0x570),
                *(undefined8 *)(lVar4 + 200),iVar3);
      }
    }
    bVar2 = lVar5 != -0xa0;
    lVar5 = lVar5 + -0x20;
  } while (bVar2);
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_vreg_deinit",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_vreg_deinit",
                   *(undefined4 *)(param_1 + 0x570));
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_cesta_map_apply @ 00110134 size=724
// signature: undefined msm_pcie_cesta_map_apply(void)
// callers: [msm_pcie_disable, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_disable_cesta, msm_pcie_scale_link_bandwidth, msm_pcie_remove]
//------------------------------------------------------------

int msm_pcie_cesta_map_apply(long param_1,uint param_2)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  char *pcVar6;
  ulong uVar7;
  undefined *puVar8;
  undefined8 uVar9;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_4c = 0;
  if (*(long *)(param_1 + 0xd00) == 0) {
LAB_001103c8:
    iVar4 = 0;
    goto LAB_001103cc;
  }
  uVar7 = (ulong)param_2;
  if (param_1 != 0) {
    uVar9 = *(undefined8 *)(param_1 + 0x728);
    uVar5 = msm_pcie_cesta_curr_perf_ol(param_1);
    ipc_log_string(uVar9,"DBG1:%s: Current perf ol is %s\n","msm_pcie_cesta_map_apply",uVar5);
    uVar9 = *(undefined8 *)(param_1 + 0x720);
    uVar5 = msm_pcie_cesta_curr_perf_ol(param_1);
    ipc_log_string(uVar9,"%s: Current perf ol is %s\n","msm_pcie_cesta_map_apply",uVar5);
    if ((3 < param_2) || (0x18 < (uVar7 << 3 | 4))) goto LAB_00110400;
    puVar8 = (&msm_pcie_cesta_states)[uVar7];
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: Setting the scenario to %s and perf_idx %d\n",
                   "msm_pcie_cesta_map_apply",puVar8,
                   *(undefined4 *)(msm_pcie_cesta_map + uVar7 * 8 + 4));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                   "%s: Setting the scenario to %s and perf_idx %d\n","msm_pcie_cesta_map_apply",
                   puVar8,*(undefined4 *)(msm_pcie_cesta_map + uVar7 * 8 + 4));
  }
  uStack_54 = *(undefined4 *)(param_1 + 0x570);
  local_58 = 0;
  if (2 < uVar7) {
LAB_00110400:
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(1,0x110404);
    (*pcVar3)();
  }
  local_50 = *(undefined4 *)(msm_pcie_cesta_map + uVar7 * 8);
  iVar4 = crm_write_perf_ol(*(undefined8 *)(param_1 + 0xcf8),0,uStack_54,&local_58);
  if (iVar4 == 0) {
    uStack_54 = *(undefined4 *)(param_1 + 0x570);
    local_58 = 1;
    if (0x18 < (uVar7 << 3 | 4)) goto LAB_00110400;
    local_50 = *(undefined4 *)(msm_pcie_cesta_map + uVar7 * 8 + 4);
    iVar4 = crm_write_perf_ol(*(undefined8 *)(param_1 + 0xcf8),0,uStack_54,&local_58);
    if (iVar4 != 0) {
      uVar5 = 1;
      goto joined_r0x001102c8;
    }
    iVar4 = crm_write_pwr_states(*(undefined8 *)(param_1 + 0xcf8),*(undefined4 *)(param_1 + 0x570));
    if (iVar4 == 0) {
      if (param_1 != 0) {
        uVar9 = *(undefined8 *)(param_1 + 0x728);
        uVar5 = msm_pcie_cesta_curr_perf_ol(param_1);
        ipc_log_string(uVar9,"DBG1:%s: New perf ol is %s\n","msm_pcie_cesta_map_apply",uVar5);
        uVar9 = *(undefined8 *)(param_1 + 0x720);
        uVar5 = msm_pcie_cesta_curr_perf_ol(param_1);
        ipc_log_string(uVar9,"%s: New perf ol is %s\n","msm_pcie_cesta_map_apply",uVar5);
      }
      goto LAB_001103c8;
    }
    if (param_1 == 0) goto LAB_001103cc;
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: pwr_st %d pwr_states %d\n"
                   ,"msm_pcie_cesta_map_apply",*(undefined4 *)(param_1 + 0x570),2,iVar4);
    uVar9 = *(undefined8 *)(param_1 + 0x720);
    pcVar6 = "%s: PCIe: RC%d: pwr_st %d pwr_states %d\n";
    uVar1 = *(undefined4 *)(param_1 + 0x570);
    uVar5 = 2;
  }
  else {
    uVar5 = 0;
joined_r0x001102c8:
    if (param_1 == 0) goto LAB_001103cc;
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: pwr_st %d perf_ol %d\n",
                   "msm_pcie_cesta_map_apply",*(undefined4 *)(param_1 + 0x570),uVar5,iVar4);
    uVar9 = *(undefined8 *)(param_1 + 0x720);
    pcVar6 = "%s: PCIe: RC%d: pwr_st %d perf_ol %d\n";
    uVar1 = *(undefined4 *)(param_1 + 0x570);
  }
  ipc_log_string(uVar9,pcVar6,"msm_pcie_cesta_map_apply",uVar1,uVar5,iVar4);
LAB_001103cc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_pcie_cesta_curr_perf_ol @ 00110408 size=244
// signature: undefined msm_pcie_cesta_curr_perf_ol(void)
// callers: [msm_pcie_cesta_map_apply]
//------------------------------------------------------------

void msm_pcie_cesta_curr_perf_ol(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar2 = crm_read_curr_perf_ol("pcie_crm",*(undefined4 *)(param_1 + 0x570),&local_3c);
  if (iVar2 == 0) {
    uVar4 = local_3c;
    if (5 < local_3c) {
      uVar4 = 6;
    }
    uVar3 = (ulong)uVar4;
  }
  else {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "ERR:%s: PCIE: RC:%d Error getting curr_perf_ol %d\n",
                   "msm_pcie_cesta_curr_perf_ol",*(undefined4 *)(param_1 + 0x570),iVar2);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                   "%s: PCIE: RC:%d Error getting curr_perf_ol %d\n","msm_pcie_cesta_curr_perf_ol",
                   *(undefined4 *)(param_1 + 0x570),iVar2);
    _printk(&DAT_00123f3d,"msm_pcie_cesta_curr_perf_ol",*(undefined4 *)(param_1 + 0x570),iVar2);
    uVar3 = 6;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail((&msm_pcie_cesta_curr_perf_lvl)[uVar3]);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_sid @ 001104fc size=508
// signature: undefined msm_pcie_config_sid(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void msm_pcie_config_sid(long param_1)

{
  ushort *puVar1;
  long lVar2;
  long lVar3;
  ushort uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  undefined8 uVar8;
  int iVar9;
  byte bVar10;
  long lVar11;
  ushort local_6c [2];
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  if (*(long *)(param_1 + 0xdb0) == 0) {
    if (*(long *)(param_1 + 0x6f8) == 0) {
      uVar8 = 0xffffffea;
      goto LAB_001106b4;
    }
    lVar3 = *(long *)(param_1 + 0x380) + 0x2000;
    __memset_io(lVar3,0,0x400);
    if (*(int *)(param_1 + 0x6f0) != 0) {
      uVar7 = 0;
      do {
        lVar11 = *(long *)(param_1 + 0x6f8);
        puVar1 = (ushort *)(lVar11 + (long)(int)uVar7 * 0x10);
        uVar4 = *puVar1;
        local_6c[0] = uVar4 >> 8 | uVar4 << 8;
        bVar5 = crc8(msm_pcie_crc8_table,local_6c,2,0);
LAB_00110614:
        bVar10 = bVar5;
        uVar6 = readl_relaxed(lVar3 + (ulong)bVar10 * 4);
        if (uVar6 != 0) {
          bVar5 = bVar10 + 1;
          if ((uVar6 & 0xff) == 0) {
            lVar2 = lVar3 + (ulong)bVar10 * 4;
            writel_relaxed(uVar6 | bVar5,lVar2);
            readl_relaxed(lVar2);
            if (*(int *)(param_1 + 0x6f0) != 0) {
              iVar9 = 0;
              do {
                if (*(byte *)(*(long *)(param_1 + 0x6f8) + (long)iVar9 * 0x10 + 3) == bVar10) {
                  *(byte *)(*(long *)(param_1 + 0x6f8) + (long)iVar9 * 0x10 + 4) = bVar5;
                  *(uint *)(*(long *)(param_1 + 0x6f8) + (long)iVar9 * 0x10 + 0xc) = uVar6 | bVar5;
                  break;
                }
                iVar9 = iVar9 + 1;
              } while (*(int *)(param_1 + 0x6f0) != iVar9);
            }
          }
          goto LAB_00110614;
        }
        lVar2 = lVar3 + (ulong)bVar10 * 4;
        lVar11 = lVar11 + (long)(int)uVar7 * 0x10;
        uVar6 = (uint)*puVar1 << 0x10 | (uint)*(byte *)(lVar11 + 2) << 8;
        writel_relaxed(uVar6,lVar2);
        readl_relaxed(lVar2);
        *(byte *)(lVar11 + 3) = bVar10;
        uVar7 = uVar7 + 1;
        *(uint *)(lVar11 + 0xc) = uVar6;
      } while (uVar7 < *(uint *)(param_1 + 0x6f0));
    }
    lVar3 = *(long *)(param_1 + 0x380) + 0x2c00;
    uVar7 = readl_relaxed(lVar3);
    writel_relaxed(uVar7 & 0xfffffffe,lVar3);
    readl_relaxed(lVar3);
  }
  uVar8 = 0;
LAB_001106b4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_tc_bdf_sid_map @ 001106f8 size=576
// signature: undefined msm_pcie_config_tc_bdf_sid_map(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

undefined8 msm_pcie_config_tc_bdf_sid_map(long param_1)

{
  ushort *puVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  
  if (*(long *)(param_1 + 0xdb0) == 0) {
    if (*(long *)(param_1 + 0x6f8) == 0) {
      return 0xffffffed;
    }
    lVar3 = *(long *)(param_1 + 0x380) + 0x4000;
    __memset_io(lVar3,0,0x100);
    uVar5 = *(uint *)(param_1 + 0x6f0);
    if (uVar5 != 0) {
      iVar8 = 0;
      uVar11 = 0;
      do {
        puVar1 = (ushort *)(*(long *)(param_1 + 0x6f8) + (long)(int)uVar11 * 0x10);
        puVar10 = puVar1 + 1;
        bVar9 = (byte)*puVar10;
        if (0x3f < bVar9) {
          if (param_1 != 0) {
            ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                           "ERR:%s: PCIe: RC%d: out of range pcie_sid -%d\n",
                           "msm_pcie_config_tc_bdf_sid_map",*(undefined4 *)(param_1 + 0x570),bVar9);
            ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                           "%s: PCIe: RC%d: out of range pcie_sid -%d\n",
                           "msm_pcie_config_tc_bdf_sid_map",*(undefined4 *)(param_1 + 0x570),
                           (byte)*puVar10);
            bVar9 = (byte)*puVar10;
          }
          _printk(&DAT_00125fb3,"msm_pcie_config_tc_bdf_sid_map",*(undefined4 *)(param_1 + 0x570),
                  bVar9);
          return 0xffffffea;
        }
        if (0 < *(int *)(param_1 + 0xdac)) {
          iVar7 = iVar8;
          if (iVar8 < 0x41) {
            iVar7 = 0x40;
          }
          iVar12 = 0;
          uVar5 = iVar8 << 2;
          iVar4 = 0;
          do {
            iVar6 = iVar4;
            if (iVar7 - iVar8 == iVar6) {
              if (param_1 != 0) {
                ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                               "ERR:%s: PCIe: RC%d: LUT table overflow\n",
                               "msm_pcie_config_tc_bdf_sid_map",*(undefined4 *)(param_1 + 0x570));
                ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                               "%s: PCIe: RC%d: LUT table overflow\n",
                               "msm_pcie_config_tc_bdf_sid_map",*(undefined4 *)(param_1 + 0x570));
              }
              _printk(&DAT_0012ec12,"msm_pcie_config_tc_bdf_sid_map",
                      *(undefined4 *)(param_1 + 0x570));
              return 0xffffffe4;
            }
            lVar2 = lVar3 + (ulong)uVar5;
            writel_relaxed(iVar12 + (uint)*puVar1 * 0x80 | (uint)bVar9 << 1 | 1,lVar2);
            readl_relaxed(lVar2);
            if (*puVar1 == 0) break;
            bVar9 = bVar9 + 1;
            uVar5 = uVar5 + 4;
            iVar12 = iVar12 + 0x800000;
            iVar4 = iVar6 + 1;
          } while (iVar6 + 1 < *(int *)(param_1 + 0xdac));
          uVar5 = *(uint *)(param_1 + 0x6f0);
          iVar8 = iVar8 + iVar6 + 1;
        }
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar5);
    }
    lVar3 = *(long *)(param_1 + 0x380) + 0x2c00;
    uVar5 = readl_relaxed(lVar3);
    writel_relaxed(uVar5 & 0xfffffffe,lVar3);
    readl_relaxed(lVar3);
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_controller @ 00110938 size=572
// signature: undefined msm_pcie_config_controller(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void msm_pcie_config_controller(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_config_controller",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d\n","msm_pcie_config_controller",
                   *(undefined4 *)(param_1 + 0x570));
  }
  if (*(char *)(param_1 + 0xdaa) == '\0') {
    *(undefined4 *)(param_1 + 0x53c) = 0;
    msm_pcie_cfg_bdf(param_1,1,0);
  }
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x720);
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x70c);
    ipc_log_string(uVar6,"DBG2:%s: Original PCIE20_ACK_F_ASPM_CTRL_REG:0x%x\n",
                   "msm_pcie_config_controller",uVar3);
  }
  iVar2 = *(int *)(param_1 + 0x508);
  lVar1 = *(long *)(param_1 + 0x3a0) + 0x70c;
  if (iVar2 == 0) {
    uVar4 = readl_relaxed(lVar1);
    uVar4 = uVar4 | 0x8000;
  }
  else {
    uVar4 = readl_relaxed(lVar1);
    uVar4 = uVar4 & 0xffff00ff | iVar2 << 8;
  }
  writel_relaxed(uVar4,lVar1);
  readl_relaxed(lVar1);
  if (param_1 != 0) {
    uVar6 = *(undefined8 *)(param_1 + 0x720);
    uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x70c);
    ipc_log_string(uVar6,"DBG2:%s: Updated PCIE20_ACK_F_ASPM_CTRL_REG:0x%x\n",
                   "msm_pcie_config_controller",uVar3);
  }
  if (*(int *)(param_1 + 0x54c) != 0) {
    lVar1 = *(long *)(param_1 + 0x3a0) + 0xb40;
    writel_relaxed(*(int *)(param_1 + 0x54c),lVar1);
    readl_relaxed(lVar1);
  }
  uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0xb40);
  uVar4 = *(uint *)(param_1 + 0x538);
  *(undefined4 *)(param_1 + 0x54c) = uVar3;
  if ((uVar4 != 0) && (*(char *)(param_1 + 0x700) != '\0')) {
    lVar1 = *(long *)(param_1 + 0x3a0) + 0x98;
    uVar5 = readl_relaxed(lVar1);
    writel_relaxed(uVar5 & 0xfffffff0 | uVar4,lVar1);
    readl_relaxed(lVar1);
  }
  if (*(char *)(param_1 + 0x4eb) != '\0') {
    lVar1 = *(long *)(param_1 + 0x3a0) + 0x3c;
    uVar4 = readl_relaxed(lVar1);
    writel_relaxed(uVar4 | 0x30000,lVar1);
    readl_relaxed(lVar1);
    lVar1 = *(long *)(param_1 + 0x3a0) + 0x78;
    uVar4 = readl_relaxed(lVar1);
    writel_relaxed(uVar4 | 0xf,lVar1);
    readl_relaxed(lVar1);
    if (param_1 != 0) {
      uVar6 = *(undefined8 *)(param_1 + 0x728);
      uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x78);
      ipc_log_string(uVar6,"DBG1:%s: RC\'s PCIE20_CAP_DEVCTRLSTATUS:0x%x\n",
                     "msm_pcie_config_controller",uVar3);
      uVar6 = *(undefined8 *)(param_1 + 0x720);
      uVar3 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x78);
      ipc_log_string(uVar6,"%s: RC\'s PCIE20_CAP_DEVCTRLSTATUS:0x%x\n","msm_pcie_config_controller",
                     uVar3);
    }
  }
  return;
}



//------------------------------------------------------------
// msm_of_pci_parse_bus_range @ 00110b74 size=144
// signature: undefined msm_of_pci_parse_bus_range(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void msm_of_pci_parse_bus_range(ulong *param_1,ulong *param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = of_property_read_variable_u32_array(param_1,"bus-range",&local_30,2,0);
  if (-1 < iVar2) {
    uVar3 = *param_1;
    *param_2 = local_30 & 0xffffffff;
    param_2[1] = local_30 >> 0x20;
    param_2[2] = uVar3;
    param_2[3] = 0x1000;
  }
  lVar1 = sp_el0;
  if (-1 < iVar2) {
    iVar2 = 0;
  }
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_iatu_config_shift @ 00110c04 size=256
// signature: undefined msm_pcie_iatu_config_shift(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void msm_pcie_iatu_config_shift
               (long param_1,int param_2,undefined1 param_3,ulong param_4,undefined4 param_5)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x398);
  lVar1 = lVar3 + (ulong)(param_2 << 9 | 4);
  writel_relaxed(0,lVar1);
  readl_relaxed(lVar1);
  lVar2 = lVar3 + (ulong)(uint)(param_2 << 9);
  writel_relaxed(param_3,lVar2);
  readl_relaxed(lVar2);
  lVar2 = lVar3 + (ulong)(param_2 << 9 | 8);
  writel_relaxed(param_4 & 0xffffffff,lVar2);
  readl_relaxed(lVar2);
  lVar2 = lVar3 + (ulong)(param_2 << 9 | 0xc);
  writel_relaxed(param_4 >> 0x20,lVar2);
  readl_relaxed(lVar2);
  lVar3 = lVar3 + (ulong)(param_2 << 9 | 0x10);
  writel_relaxed(param_5,lVar3);
  readl_relaxed(lVar3);
  writel_relaxed(0x90000000,lVar1);
  readl_relaxed(lVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_iatu_setup_ecam_blocker @ 00110d04 size=384
// signature: undefined msm_pcie_iatu_setup_ecam_blocker(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void msm_pcie_iatu_setup_ecam_blocker(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  uVar4 = **(ulong **)(param_1 + 0x198);
  lVar1 = *(long *)(param_1 + 0x380) + 0x380;
  writel_relaxed(uVar4 & 0xffffffff,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 900;
  writel_relaxed(uVar4 >> 0x20,lVar1);
  readl_relaxed(lVar1);
  uVar2 = uVar4 + 0x1000;
  uVar4 = uVar4 + 0xfffff;
  lVar1 = *(long *)(param_1 + 0x380) + 0x360;
  writel_relaxed(uVar2 & 0xffffffff,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x364;
  writel_relaxed(uVar2 >> 0x20,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x370;
  writel_relaxed(uVar2 & 0xffffffff,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x374;
  writel_relaxed(uVar2 >> 0x20,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x368;
  writel_relaxed(uVar4 & 0xffffffff,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x36c;
  writel_relaxed(uVar4 >> 0x20,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x378;
  writel_relaxed(uVar4 & 0xffffffff,lVar1);
  readl_relaxed(lVar1);
  lVar1 = *(long *)(param_1 + 0x380) + 0x37c;
  writel_relaxed(uVar4 >> 0x20,lVar1);
  readl_relaxed(lVar1);
  uVar3 = *(undefined8 *)(param_1 + 0x380);
  writel_relaxed(0x4000000,uVar3);
  readl_relaxed(uVar3);
  return;
}



//------------------------------------------------------------
// msm_pcie_check_ep_access @ 00110e84 size=304
// signature: undefined msm_pcie_check_ep_access(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_pcie_check_ep_access(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  lVar1 = _jiffies - param_2;
  while ((lVar1 < 0 && (iVar2 = readl_relaxed(*(undefined8 *)(param_1 + 0x3a8)), iVar2 == -1))) {
    usleep_range_state(1000,0x3ed,2);
    lVar1 = _jiffies - param_2;
  }
  iVar2 = readl_relaxed(*(undefined8 *)(param_1 + 0x3a8));
  if (iVar2 == -1) {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "ERR:%s: PCIe: RC%d: endpoint config space is not accessible\n",
                     "msm_pcie_check_ep_access",*(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: RC%d: endpoint config space is not accessible\n",
                     "msm_pcie_check_ep_access",*(undefined4 *)(param_1 + 0x570));
    }
    _printk(&DAT_0012601d,"msm_pcie_check_ep_access",*(undefined4 *)(param_1 + 0x570));
    uVar3 = 0xffffffed;
    *(undefined1 *)(param_1 + 0x71c) = 0;
    *(undefined4 *)(param_1 + 0x4b0) = 2;
    *(long *)(param_1 + 0x690) = *(long *)(param_1 + 0x690) + 1;
  }
  else {
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: RC%d: endpoint config space is accessible\n",
                     "msm_pcie_check_ep_access",*(undefined4 *)(param_1 + 0x570));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: RC%d: endpoint config space is accessible\n",
                     "msm_pcie_check_ep_access",*(undefined4 *)(param_1 + 0x570));
    }
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// msm_pcie_pipe_reset @ 00110fb4 size=472
// signature: undefined msm_pcie_pipe_reset(void)
// callers: [msm_pcie_disable, msm_pcie_enable_link]
//------------------------------------------------------------

void msm_pcie_pipe_reset(long param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: entry\n","msm_pcie_pipe_reset",
                   *(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: entry\n","msm_pcie_pipe_reset",
                   *(undefined4 *)(param_1 + 0x570));
  }
  if (*(long *)(param_1 + 0x318) != 0) {
    iVar1 = reset_control_assert();
    if (iVar1 == 0) {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "DBG2:%s: PCIe: RC%d successfully asserted pipe reset for %s.\n",
                       "msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(param_1 + 800));
      }
    }
    else {
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d failed to assert pipe reset for %s.\n",
                       "msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
                       *(undefined8 *)(param_1 + 800));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d failed to assert pipe reset for %s.\n","msm_pcie_pipe_reset",
                       *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(param_1 + 800));
      }
      _printk(&DAT_0012be00,"msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
              *(undefined8 *)(param_1 + 800));
    }
    usleep_range_state(1000,0x3ed,2);
    iVar1 = reset_control_deassert(*(undefined8 *)(param_1 + 0x318));
    if (iVar1 == 0) {
      if (param_1 == 0) {
        return;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "DBG2:%s: PCIe: RC%d successfully deasserted pipe reset for %s.\n",
                     "msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
                     *(undefined8 *)(param_1 + 800));
      goto LAB_00111144;
    }
    if (param_1 != 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "ERR:%s: PCIe: RC%d failed to deassert pipe reset for %s.\n",
                     "msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
                     *(undefined8 *)(param_1 + 800));
      ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                     "%s: PCIe: RC%d failed to deassert pipe reset for %s.\n","msm_pcie_pipe_reset",
                     *(undefined4 *)(param_1 + 0x570),*(undefined8 *)(param_1 + 800));
    }
    _printk(&DAT_00126f4d,"msm_pcie_pipe_reset",*(undefined4 *)(param_1 + 0x570),
            *(undefined8 *)(param_1 + 800));
  }
  if (param_1 == 0) {
    return;
  }
LAB_00111144:
  ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: RC%d: exit\n","msm_pcie_pipe_reset",
                 *(undefined4 *)(param_1 + 0x570));
  ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: RC%d: exit\n","msm_pcie_pipe_reset",
                 *(undefined4 *)(param_1 + 0x570));
  return;
}



//------------------------------------------------------------
// writeb @ 0011118c size=136
// signature: undefined writeb(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

void writeb(undefined1 param_1,undefined1 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,8,param_2,0x1111a8,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,8,param_2,0x1111e4,uVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_cfg_bdf @ 00111214 size=444
// signature: undefined msm_pcie_cfg_bdf(void)
// callers: [msm_pcie_config_controller, msm_pcie_oper_conf]
//------------------------------------------------------------

void msm_pcie_cfg_bdf(long param_1,byte param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long local_78;
  long local_70;
  
  uVar1 = (uint)param_2 << 0x18 | (param_3 & 0xff) << 0x10;
  if (*(uint *)(param_1 + 0x53c) == uVar1) {
    return;
  }
  lVar7 = *(long *)(param_1 + 0x398);
  uVar2 = 4;
  if (param_2 != 1) {
    uVar2 = 5;
  }
  uVar5 = **(ulong **)(param_1 + 0x1e0);
  if (lVar7 == 0) {
    if (uVar1 == 0) goto LAB_001113a8;
    lVar7 = *(long *)(param_1 + 0x3a0);
    writel_relaxed(0,lVar7 + 0x900);
    readl_relaxed(lVar7 + 0x900);
    lVar3 = 0x908;
    lVar6 = 0x904;
    lVar8 = 0x90c;
    lVar9 = 0x910;
    local_78 = 0x914;
    local_70 = 0x918;
    lVar4 = 0x91c;
  }
  else {
    if (uVar1 == 0) goto LAB_001113a8;
    lVar6 = 0;
    lVar3 = 4;
    lVar8 = 8;
    lVar9 = 0xc;
    local_78 = 0x10;
    local_70 = 0x14;
    lVar4 = 0x18;
  }
  lVar3 = lVar7 + lVar3;
  writel_relaxed(0,lVar3);
  readl_relaxed(lVar3);
  writel_relaxed(uVar2,lVar7 + lVar6);
  readl_relaxed(lVar7 + lVar6);
  writel_relaxed(uVar5 & 0xffffffff,lVar7 + lVar8);
  readl_relaxed(lVar7 + lVar8);
  writel_relaxed(uVar5 >> 0x20,lVar7 + lVar9);
  readl_relaxed(lVar7 + lVar9);
  writel_relaxed((int)uVar5 + 0xfff,lVar7 + local_78);
  readl_relaxed(lVar7 + local_78);
  writel_relaxed(uVar1,lVar7 + local_70);
  readl_relaxed(lVar7 + local_70);
  writel_relaxed(0,lVar7 + lVar4);
  readl_relaxed(lVar7 + lVar4);
  writel_relaxed(0x80000000,lVar3);
  readl_relaxed(lVar3);
LAB_001113a8:
  *(uint *)(param_1 + 0x53c) = uVar1;
  return;
}



//------------------------------------------------------------
// msm_pcie_rd_conf @ 001113d4 size=44
// signature: undefined msm_pcie_rd_conf(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_rd_conf(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                     undefined8 param_5)

{
  msm_pcie_oper_conf(param_1,param_2,0,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// msm_pcie_wr_conf @ 00111404 size=96
// signature: undefined msm_pcie_wr_conf(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_wr_conf(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5)

{
  long lVar1;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = param_5;
  msm_pcie_oper_conf(param_1,param_2,1,param_3,param_4,&local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_oper_conf @ 00111464 size=676
// signature: undefined msm_pcie_oper_conf(void)
// callers: [msm_pcie_rd_conf, msm_pcie_wr_conf]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_pcie_oper_conf(long param_1,undefined4 param_2,int param_3,uint param_4,int param_5,
                      uint *param_6)

{
  long lVar1;
  undefined4 uVar2;
  char cVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  char *pcVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  
  lVar13 = *(long *)(*(long *)(param_1 + 0xe8) + 200);
  if (lVar13 == 0) {
    _printk(&DAT_0012a52c);
    iVar7 = 0x86;
  }
  else {
    uVar10 = _raw_spin_lock_irqsave(lVar13 + 0x444);
    *(undefined8 *)(lVar13 + 0x448) = uVar10;
    iVar7 = msm_pcie_check_link_dev_status(lVar13,param_1,param_2,param_3,param_4,param_5);
    if (iVar7 == 0) {
      cVar3 = *(char *)(param_1 + 0xf8);
      uVar2 = *(undefined4 *)(lVar13 + 0x570);
      if (cVar3 != '\0') {
        msm_pcie_cfg_bdf(lVar13,cVar3,param_2);
      }
      uVar14 = (param_4 & 3) << 3;
      lVar1 = 0x3a0;
      if (cVar3 != '\0') {
        lVar1 = 0x3a8;
      }
      lVar12 = *(long *)(lVar13 + lVar1);
      uVar6 = 0xffffffff >> (ulong)(param_5 * -8 & 0x1f);
      uVar5 = uVar6 << (ulong)uVar14;
      lVar1 = lVar12 + (ulong)(param_4 & 0xfffffffc);
      uVar8 = readl_relaxed(lVar1);
      if (param_3 == 0) {
        pcVar11 = "DBG3:%s: RC%d %d:0x%02x + 0x%04x[%d] -> 0x%08x; rd 0x%08x\n";
        uVar14 = (uVar8 & uVar5) >> (ulong)uVar14;
        *param_6 = uVar14;
        uVar10 = *(undefined8 *)(lVar13 + 0x720);
        uVar4 = *(undefined1 *)(param_1 + 0xf8);
      }
      else {
        uVar5 = (*param_6 & uVar6) << (ulong)uVar14 | uVar8 & (uVar5 ^ 0xffffffff);
        uVar14 = uVar5 | 0x30000;
        if (*(char *)(param_1 + 0xf8) != '\0' || param_4 != 0x3c) {
          uVar14 = uVar5;
        }
        writel_relaxed(uVar14,lVar1);
        readl_relaxed(lVar1);
        pcVar11 = "DBG3:%s: RC%d %d:0x%02x + 0x%04x[%d] <- 0x%08x; rd 0x%08x val 0x%08x\n";
        uVar10 = *(undefined8 *)(lVar13 + 0x720);
        uVar4 = *(undefined1 *)(param_1 + 0xf8);
      }
      ipc_log_string(uVar10,pcVar11,"msm_pcie_oper_conf",uVar2,uVar4,param_2,param_4,param_5,uVar14,
                     uVar8);
      if (((uVar8 == 0xffffffff) && (iVar9 = readl_relaxed(lVar12), iVar9 == -1)) &&
         (*(char *)(lVar13 + 0x758) != '\0')) {
        ipc_log_string(*(undefined8 *)(lVar13 + 0x728),"ERR:%s: RC%d link recovery schedule\n",
                       "msm_pcie_oper_conf",uVar2);
        ipc_log_string(*(undefined8 *)(lVar13 + 0x720),"%s: RC%d link recovery schedule\n",
                       "msm_pcie_oper_conf",uVar2);
        _printk(&DAT_00128849,"msm_pcie_oper_conf",uVar2);
        *(undefined1 *)(lVar13 + 0x440) = 0;
        queue_work_on(0x20,_system_wq,lVar13 + 0x760);
      }
    }
    else {
      *param_6 = 0xffffffff;
    }
    _raw_spin_unlock_irqrestore(lVar13 + 0x444,*(undefined8 *)(lVar13 + 0x448));
  }
  return iVar7;
}



//------------------------------------------------------------
// msm_pcie_config_common_clock_enable @ 0011170c size=248
// signature: undefined msm_pcie_config_common_clock_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_common_clock_enable(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (param_2 != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                   "msm_pcie_config_common_clock_enable",*(undefined4 *)(param_2 + 0x570),
                   *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                   *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                   "msm_pcie_config_common_clock_enable",*(undefined4 *)(param_2 + 0x570),
                   *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                   *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
  }
  local_3c = 0;
  iVar1 = *(byte *)(param_1 + 0x6c) + 0x10;
  pci_read_config_dword(param_1,iVar1,&local_3c);
  local_3c = local_3c | 0x40;
  pci_write_config_dword(param_1,iVar1);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_clock_power_management_enable @ 00111808 size=392
// signature: undefined msm_pcie_config_clock_power_management_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_clock_power_management_enable(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  undefined4 local_40;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if (*(long *)(*(long *)(param_1 + 0x10) + 0x10) != 0) {
    if (param_2 != 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                     "msm_pcie_config_clock_power_management_enable",
                     *(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x\n",
                     "msm_pcie_config_clock_power_management_enable",
                     *(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    }
    pci_read_config_dword(param_1,*(byte *)(param_1 + 0x6c) + 0xc,&local_40);
    if ((local_40._2_1_ >> 2 & 1) == 0) {
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support clock power management\n"
                       ,"msm_pcie_config_clock_power_management_enable",
                       *(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                       "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support clock power management\n"
                       ,"msm_pcie_config_clock_power_management_enable",
                       *(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      }
    }
    else {
      local_3c = 0;
      iVar1 = *(byte *)(param_1 + 0x6c) + 0x10;
      pci_read_config_dword(param_1,iVar1,&local_3c);
      local_3c = local_3c | 0x100;
      pci_write_config_dword(param_1,iVar1);
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
// msm_pcie_check_l1ss_support @ 00111994 size=548
// signature: undefined msm_pcie_check_l1ss_support(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_check_l1ss_support(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  long lVar7;
  ushort uVar8;
  undefined8 uVar9;
  char *pcVar10;
  uint local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_3c = 0;
  if (*(char *)(param_2 + 0x4db) == '\0') {
    uVar9 = 0xfffffffa;
    goto LAB_00111a4c;
  }
  uVar1 = *(uint *)(param_1 + 0x38) & 7;
  if ((param_2 != 0) && (uVar1 != 0)) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n",
                   "msm_pcie_is_non_zero_function",*(undefined4 *)(param_2 + 0x570),
                   *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                   *(uint *)(param_1 + 0x38) >> 3 & 0x1f);
    ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                   "%s: PCIe: RC%d: PCI device %02x:%02x.%01x Ignore non-zero function\n",
                   "msm_pcie_is_non_zero_function",*(undefined4 *)(param_2 + 0x570),
                   *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                   *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
    uVar9 = 0;
    goto LAB_00111a4c;
  }
  if (uVar1 == 0) {
    uVar8 = pci_find_ext_capability(param_1,0x1e);
    if (uVar8 == 0) {
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n"
                       ,"msm_pcie_check_l1ss_support",*(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        pcVar10 = 
        "%s: PCIe: RC%d: PCI device %02x:%02x.%01x could not find L1ss capability register\n";
        uVar1 = *(uint *)(param_1 + 0x38);
        uVar9 = *(undefined8 *)(param_2 + 0x720);
        uVar5 = *(undefined4 *)(param_2 + 0x570);
        uVar6 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
LAB_00111ba0:
        ipc_log_string(uVar9,pcVar10,"msm_pcie_check_l1ss_support",uVar5,uVar6,uVar1 >> 3 & 0x1f,
                       uVar1 & 7);
      }
    }
    else {
      pci_read_config_dword(param_1,uVar8 + 4,&local_3c);
      uVar1 = (uint)*(byte *)(param_2 + 0x4dc) & local_3c >> 1;
      uVar2 = local_3c & *(byte *)(param_2 + 0x4dd);
      uVar3 = (uint)*(byte *)(param_2 + 0x4de) & local_3c >> 3;
      uVar4 = (uint)*(byte *)(param_2 + 0x4df) & local_3c >> 2;
      *(char *)(param_2 + 0x4dc) = (char)uVar1;
      *(char *)(param_2 + 0x4dd) = (char)uVar2;
      *(char *)(param_2 + 0x4de) = (char)uVar3;
      *(char *)(param_2 + 0x4df) = (char)uVar4;
      if ((uVar1 != 0 || uVar2 != 0) || (uVar3 != 0 || uVar4 != 0)) goto LAB_00111a48;
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support any L1ss\n",
                       "msm_pcie_check_l1ss_support",*(undefined4 *)(param_2 + 0x570),
                       *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                       *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
        uVar1 = *(uint *)(param_1 + 0x38);
        pcVar10 = "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support any L1ss\n";
        uVar9 = *(undefined8 *)(param_2 + 0x720);
        uVar5 = *(undefined4 *)(param_2 + 0x570);
        uVar6 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
        goto LAB_00111ba0;
      }
    }
    uVar9 = 0xfffffffa;
    *(undefined1 *)(param_2 + 0x4db) = 0;
  }
  else {
LAB_00111a48:
    uVar9 = 0;
  }
LAB_00111a4c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l1_enable @ 00111bbc size=48
// signature: undefined msm_pcie_config_l1_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_l1_enable(undefined8 param_1,undefined8 param_2)

{
  msm_pcie_config_l1(param_2,param_1,1);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_l1 @ 00111bec size=624
// signature: undefined msm_pcie_config_l1(void)
// callers: [msm_pcie_config_l1_disable_all, msm_pcie_config_l1_enable]
//------------------------------------------------------------

void msm_pcie_config_l1(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  uint local_50;
  undefined4 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  iVar1 = *(byte *)(param_2 + 0x6c) + 0x10;
  if (param_1 != 0) {
    pcVar4 = "enable";
    if ((param_3 & 1) == 0) {
      pcVar4 = "disable";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n","msm_pcie_config_l1",
                   *(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                   *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7,pcVar4);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n"
                   ,"msm_pcie_config_l1",*(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                   *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7,pcVar4);
  }
  if ((param_3 & 1) == 0) {
    local_4c = 0;
    pci_read_config_dword(param_2,iVar1,&local_4c);
    local_4c = local_4c & 0xfffffffd;
LAB_00111db0:
    pci_write_config_dword(param_2,iVar1);
  }
  else {
    local_4c = 0;
    lVar5 = *(long *)(*(long *)(param_2 + 0x10) + 0x38);
    if (lVar5 == 0) {
LAB_00111d04:
      pci_read_config_dword(param_2,*(byte *)(param_2 + 0x6c) + 0xc,&local_4c);
      if ((local_4c._1_1_ >> 3 & 1) != 0) {
        local_4c = 0;
        pci_read_config_dword(param_2,iVar1,&local_4c);
        local_4c = local_4c | 2;
        goto LAB_00111db0;
      }
      if (param_1 == 0) goto LAB_00111e28;
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L1\n",
                     "msm_pcie_check_l1_support",*(undefined4 *)(param_1 + 0x570),
                     *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                     *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7);
      uVar2 = *(uint *)(param_2 + 0x38);
      pcVar4 = "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L1\n";
      lVar5 = *(long *)(param_2 + 0x10);
      uVar3 = *(undefined8 *)(param_1 + 0x720);
    }
    else {
      local_50 = 0;
      pci_read_config_dword(lVar5,*(byte *)(lVar5 + 0x6c) + 0xc,&local_4c);
      pci_read_config_dword(lVar5,*(byte *)(lVar5 + 0x6c) + 0x10,&local_50);
      local_4c = local_4c >> 0xb & (local_50 & 2) >> 1;
      if (local_4c != 0) goto LAB_00111d04;
      if (param_1 == 0) goto LAB_00111e28;
      ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L1\n",
                     "msm_pcie_check_l1_support",*(undefined4 *)(param_1 + 0x570),
                     *(undefined1 *)(*(long *)(lVar5 + 0x10) + 0xf8),
                     *(uint *)(lVar5 + 0x38) >> 3 & 0x1f,*(uint *)(lVar5 + 0x38) & 7);
      uVar2 = *(uint *)(lVar5 + 0x38);
      pcVar4 = "%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L1\n";
      lVar5 = *(long *)(lVar5 + 0x10);
      uVar3 = *(undefined8 *)(param_1 + 0x720);
    }
    ipc_log_string(uVar3,pcVar4,"msm_pcie_check_l1_support",*(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(lVar5 + 0xf8),uVar2 >> 3 & 0x1f,uVar2 & 7);
  }
LAB_00111e28:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_config_l0s @ 00111e5c size=324
// signature: undefined msm_pcie_config_l0s(void)
// callers: [msm_pcie_config_l0s_enable, msm_pcie_config_l0s_disable_all]
//------------------------------------------------------------

void msm_pcie_config_l0s(long param_1,long param_2,ulong param_3)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  iVar1 = *(byte *)(param_2 + 0x6c) + 0x10;
  if (param_1 != 0) {
    pcVar2 = "enable";
    if ((param_3 & 1) == 0) {
      pcVar2 = "disable";
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n","msm_pcie_config_l0s",
                   *(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                   *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7,pcVar2);
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: PCI device %02x:%02x.%01x %s\n"
                   ,"msm_pcie_config_l0s",*(undefined4 *)(param_1 + 0x570),
                   *(undefined1 *)(*(long *)(param_2 + 0x10) + 0xf8),
                   *(uint *)(param_2 + 0x38) >> 3 & 0x1f,*(uint *)(param_2 + 0x38) & 7,pcVar2);
  }
  if ((param_3 & 1) == 0) {
    local_4c = 0;
    pci_read_config_dword(param_2,iVar1,&local_4c);
    local_4c = local_4c & 0xfffffffe;
  }
  else {
    local_4c = 0;
    pci_read_config_dword(param_2,iVar1,&local_4c);
    local_4c = local_4c | 1;
  }
  pci_write_config_dword(param_2,iVar1);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_read_devid_all @ 00111fa4 size=88
// signature: undefined msm_pcie_read_devid_all(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_read_devid_all(undefined8 param_1)

{
  long lVar1;
  undefined2 local_1c [2];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  pci_read_config_word(param_1,2,local_1c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_bandwidth_int @ 00111ffc size=332
// signature: undefined msm_pcie_config_bandwidth_int(void)
// callers: [msm_pcie_link_retrain]
//------------------------------------------------------------

void msm_pcie_config_bandwidth_int(long param_1,ulong param_2)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 8);
  if ((param_2 & 1) == 0) {
    lVar1 = *(long *)(param_1 + 0x380) + 0x508;
    uVar2 = readl_relaxed(lVar1);
    writel_relaxed(uVar2 & 0xfdffffff,lVar1);
    readl_relaxed(lVar1);
    local_3c = 0;
    iVar4 = *(byte *)(lVar3 + 0x6c) + 0x10;
    pci_read_config_dword(lVar3,iVar4,&local_3c);
    local_3c = local_3c & 0xfffffbff;
  }
  else {
    lVar1 = *(long *)(param_1 + 0x3a0) + 4;
    uVar2 = readl_relaxed(lVar1);
    writel_relaxed(uVar2 & 0xfffffbff,lVar1);
    readl_relaxed(lVar1);
    lVar1 = *(long *)(param_1 + 0x3a0) + 0x50;
    uVar2 = readl_relaxed(lVar1);
    writel_relaxed(uVar2 & 0xfffeffff,lVar1);
    readl_relaxed(lVar1);
    lVar1 = *(long *)(param_1 + 0x380) + 0x508;
    uVar2 = readl_relaxed(lVar1);
    writel_relaxed(uVar2 | 0x2000000,lVar1);
    readl_relaxed(lVar1);
    local_3c = 0;
    iVar4 = *(byte *)(lVar3 + 0x6c) + 0x10;
    pci_read_config_dword(lVar3,iVar4,&local_3c);
    local_3c = local_3c | 0x400;
  }
  pci_write_config_dword(lVar3,iVar4);
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_check_l0s_support @ 0011214c size=380
// signature: undefined msm_pcie_check_l0s_support(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_check_l0s_support(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  undefined4 local_3c;
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_3c = 0;
  lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 0x38);
  if (lVar7 == 0) {
LAB_00112210:
    pci_read_config_dword(param_1,*(byte *)(param_1 + 0x6c) + 0xc,&local_3c);
    if ((local_3c._1_1_ >> 2 & 1) != 0) goto LAB_00112294;
    if (param_2 != 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L0s\n",
                     "msm_pcie_check_l0s_support",*(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8),
                     *(uint *)(param_1 + 0x38) >> 3 & 0x1f,*(uint *)(param_1 + 0x38) & 7);
      uVar1 = *(uint *)(param_1 + 0x38);
      pcVar6 = "%s: PCIe: RC%d: PCI device %02x:%02x.%01x does not support L0s\n";
      uVar5 = *(undefined8 *)(param_2 + 0x720);
      uVar3 = *(undefined4 *)(param_2 + 0x570);
      uVar4 = *(undefined1 *)(*(long *)(param_1 + 0x10) + 0xf8);
      goto LAB_0011228c;
    }
  }
  else {
    pci_read_config_dword(lVar7,*(byte *)(lVar7 + 0x6c) + 0xc,&local_3c);
    uVar1 = local_3c & 0x400;
    uVar2 = local_3c >> 10;
    local_3c = uVar1;
    if ((uVar2 & 1) != 0) goto LAB_00112210;
    if (param_2 != 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L0s\n",
                     "msm_pcie_check_l0s_support",*(undefined4 *)(param_2 + 0x570),
                     *(undefined1 *)(*(long *)(lVar7 + 0x10) + 0xf8),
                     *(uint *)(lVar7 + 0x38) >> 3 & 0x1f,*(uint *)(lVar7 + 0x38) & 7);
      pcVar6 = "%s: PCIe: RC%d: Parent PCI device %02x:%02x.%01x does not support L0s\n";
      uVar1 = *(uint *)(lVar7 + 0x38);
      uVar5 = *(undefined8 *)(param_2 + 0x720);
      uVar3 = *(undefined4 *)(param_2 + 0x570);
      uVar4 = *(undefined1 *)(*(long *)(lVar7 + 0x10) + 0xf8);
LAB_0011228c:
      ipc_log_string(uVar5,pcVar6,"msm_pcie_check_l0s_support",uVar3,uVar4,uVar1 >> 3 & 0x1f,
                     uVar1 & 7);
    }
  }
  *(undefined1 *)(param_2 + 0x4d9) = 0;
LAB_00112294:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_config_l0s_enable @ 001122cc size=56
// signature: undefined msm_pcie_config_l0s_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_config_l0s_enable(undefined8 param_1,long param_2)

{
  if (*(char *)(param_2 + 0x4d9) != '\0') {
    msm_pcie_config_l0s(param_2,param_1,1);
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_ssr_notifier @ 00112308 size=584
// signature: undefined msm_pcie_ssr_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_ssr_notifier(long param_1,long param_2)

{
  long lVar1;
  char *pcVar2;
  
  if (param_2 == 2) {
    *(undefined8 *)(param_1 + -0xa8) = 0;
    *(undefined8 *)(param_1 + -0x98) = 0;
    lVar1 = **(long **)(param_1 + -0xa0);
    if ((lVar1 != 0) && (pcVar2 = *(char **)(lVar1 + 0x790), pcVar2 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      if (*pcVar2 != '\0') {
        msm_pcie_notify_client(lVar1,4);
      }
    }
    lVar1 = *(long *)(*(long *)(param_1 + -0xa0) + 8);
    if ((lVar1 != 0) && (pcVar2 = *(char **)(lVar1 + 0x790), pcVar2 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      if (*pcVar2 != '\0') {
        msm_pcie_notify_client(lVar1,4);
      }
    }
    lVar1 = *(long *)(*(long *)(param_1 + -0xa0) + 0x10);
    if ((lVar1 != 0) && (pcVar2 = *(char **)(lVar1 + 0x790), pcVar2 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      if (*pcVar2 != '\0') {
        msm_pcie_notify_client(lVar1,4);
      }
    }
    lVar1 = *(long *)(*(long *)(param_1 + -0xa0) + 0x18);
    if ((lVar1 != 0) && (pcVar2 = *(char **)(lVar1 + 0x790), pcVar2 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      if (*pcVar2 != '\0') {
        msm_pcie_notify_client(lVar1,4);
      }
    }
    lVar1 = *(long *)(*(long *)(param_1 + -0xa0) + 0x20);
    if ((lVar1 != 0) && (pcVar2 = *(char **)(lVar1 + 0x790), pcVar2 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),4);
      if (*pcVar2 != '\0') {
        msm_pcie_notify_client(lVar1,4);
      }
    }
  }
  return 1;
}



//------------------------------------------------------------
// msm_pcie_drv_connect_notify_all @ 00112554 size=320
// signature: undefined msm_pcie_drv_connect_notify_all(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_connect_notify_all(long param_1)

{
  ulong uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  
  if (*(long *)(param_1 + -8) != 0) {
    lVar4 = 0;
    lVar3 = 0;
    do {
      lVar2 = *(long *)(*(long *)(param_1 + -0x10) + lVar4);
      if (((lVar2 != 0) && (pcVar5 = *(char **)(lVar2 + 0x790), pcVar5 != (char *)0x0)) &&
         (*pcVar5 == '\0')) {
        uVar1 = msm_pcie_notify_client(lVar2,0x10);
        if ((uVar1 & 1) != 0) {
          mutex_lock(lVar2 + 0x830);
          *pcVar5 = '\x01';
          if (*(int *)(lVar2 + 0x828) != 0) {
            queue_work_on(0x20,mpcie_wq,lVar2 + 0x7c8);
          }
          mutex_unlock(lVar2 + 0x830);
        }
        lVar3 = lVar2;
      }
      lVar4 = lVar4 + 8;
    } while (lVar4 != 0x28);
    if ((*(long *)(param_1 + 0xa8) == 0) && (lVar3 != 0)) {
      uVar1 = qcom_register_early_ssr_notifier(*(undefined8 *)(lVar3 + 0x880),param_1 + 0x90);
      *(ulong *)(param_1 + 0xa8) = uVar1;
      if (0xfffffffffffff000 < uVar1) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                       "ERR:%s: PCIe: RC%d: DRV: failed to register ssr notifier\n",
                       "msm_pcie_drv_connect_notify_all",*(undefined4 *)(lVar3 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                       "%s: PCIe: RC%d: DRV: failed to register ssr notifier\n",
                       "msm_pcie_drv_connect_notify_all",*(undefined4 *)(lVar3 + 0x570));
        _printk(&DAT_00128040,"msm_pcie_drv_connect_notify_all",*(undefined4 *)(lVar3 + 0x570));
        *(undefined8 *)(param_1 + 0xa8) = 0;
      }
    }
  }
  return;
}



//------------------------------------------------------------
// pcie_i2c_ctrl_probe @ 00112698 size=316
// signature: undefined pcie_i2c_ctrl_probe(void)
// callers: []
//------------------------------------------------------------

void pcie_i2c_ctrl_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = -0x16;
  pcVar5 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
  if (*(int *)(pcVar5 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1126e8);
    (*pcVar5)();
  }
  uVar2 = (*pcVar5)();
  lVar1 = param_1 + 0x20;
  if ((uVar2 & 1) == 0) {
    _dev_err(lVar1,"I2C functionality not supported\n");
    uVar3 = 0xfffffffb;
  }
  else {
    if (*(long *)(param_1 + 0x308) == 0) {
      uVar3 = 0;
    }
    else {
      lVar4 = of_match_device(of_i2c_id_table,lVar1);
      if (lVar4 == 0) {
        _dev_err(lVar1,"Error: No device match found\n");
        uVar3 = 0xffffffed;
        goto LAB_00112790;
      }
      uVar3 = *(undefined8 *)(param_1 + 0x308);
    }
    of_property_read_variable_u32_array(uVar3,"rc-index",&local_2c,1,0);
    _dev_info(lVar1,"%s: PCIe rc-index: 0x%X\n","pcie_i2c_ctrl_probe",local_2c);
    if (local_2c < 5) {
      uVar3 = 0;
    }
    else {
      _dev_err(lVar1,"invalid RC index %d\n");
      uVar3 = 0xffffffea;
    }
  }
LAB_00112790:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_rc_select @ 001127d8 size=360
// signature: undefined msm_pcie_debugfs_rc_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

long msm_pcie_debugfs_rc_select(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_2c);
  if (iVar2 != 0) {
    param_3 = (long)iVar2;
    goto LAB_00112818;
  }
  if (local_2c == 0) {
LAB_0011286c:
    _printk(&DAT_0012c6fe);
    puVar3 = &DAT_0012609f;
    uVar4 = rc_sel;
    if (rc_sel == 0) {
      uVar4 = 1;
    }
  }
  else {
    uVar4 = 0x1f;
    if (rc_sel_max == '\0') {
      uVar4 = 0;
    }
    if (uVar4 < local_2c) goto LAB_0011286c;
    puVar3 = &DAT_001266ca;
    rc_sel = local_2c;
    uVar4 = local_2c;
  }
  _printk(puVar3,uVar4);
  _printk(&DAT_00124175);
  if ((rc_sel & 1) != 0) {
    _printk(&DAT_0012af7b,0);
  }
  if ((rc_sel >> 1 & 1) != 0) {
    _printk(&DAT_0012af7b,1);
  }
  if ((rc_sel >> 2 & 1) != 0) {
    _printk(&DAT_0012af7b,2);
  }
  if ((rc_sel >> 3 & 1) != 0) {
    _printk(&DAT_0012af7b,3);
  }
  if ((rc_sel >> 4 & 1) != 0) {
    _printk(&DAT_0012af7b,4);
  }
LAB_00112818:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_rc_select_open @ 00112944 size=44
// signature: undefined msm_pcie_debugfs_rc_select_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_rc_select_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_rc_select_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_parse_input @ 00112970 size=468
// signature: undefined msm_pcie_debugfs_parse_input(void)
// callers: [msm_pcie_debugfs_aer_enable, msm_pcie_debugfs_case_select, msm_pcie_debugfs_wr_value, msm_pcie_debugfs_wr_offset, msm_pcie_debugfs_wr_mask, msm_pcie_debugfs_corr_counter_limit, msm_pcie_debugfs_rc_select, msm_pcie_debugfs_base_select, msm_pcie_debugfs_linkdown_panic, msm_pcie_debugfs_boot_option]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void msm_pcie_debugfs_parse_input(ulong param_1,ulong param_2,undefined8 param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  undefined4 uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = __kmalloc(param_2 + 1,0xcc0);
  if (lVar4 == 0) {
    uVar6 = 0xfffffff4;
  }
  else {
    if (param_2 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x112b04);
      (*pcVar2)();
    }
    __check_object_size(lVar4,param_2,0);
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_1, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar8 = param_1 & (long)(param_1 << 8) >> 8;
    }
    uVar5 = param_2;
    if (uVar8 <= 0x8000000000 - param_2) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar5 = daif;
          daif = uVar5 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar5 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar5 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar5 = __arch_copy_from_user(puVar7,lVar4,param_1 & 0xff7fffffffffffff,param_2);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
    if (uVar5 == 0) {
      if ((long)param_2 < 0) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x112b30);
        (*pcVar2)();
      }
      *(undefined1 *)(lVar4 + param_2) = 0;
      local_40 = lVar4;
      iVar3 = get_option(&local_40,param_3);
      kfree(lVar4);
      uVar6 = 0;
      if (iVar3 != 1) {
        uVar6 = 0xffffffea;
      }
    }
    else {
      memset((void *)(lVar4 + (param_2 - uVar5)),0,uVar5);
      kfree(lVar4);
      uVar6 = 0xfffffff2;
    }
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_rc_select_show @ 00112b64 size=220
// signature: undefined msm_pcie_debugfs_rc_select_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 msm_pcie_debugfs_rc_select_show(undefined8 param_1)

{
  seq_printf(param_1,"Current rc_sel: %d which selects:\n",rc_sel);
  if ((rc_sel & 1) != 0) {
    seq_printf(param_1,"\tPCIe%d\n",0);
  }
  if ((rc_sel >> 1 & 1) != 0) {
    seq_printf(param_1,"\tPCIe%d\n",1);
  }
  if ((rc_sel >> 2 & 1) != 0) {
    seq_printf(param_1,"\tPCIe%d\n",2);
  }
  if ((rc_sel >> 3 & 1) != 0) {
    seq_printf(param_1,"\tPCIe%d\n",3);
  }
  if ((rc_sel >> 4 & 1) != 0) {
    seq_printf(param_1,"\tPCIe%d\n",4);
  }
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_case_select @ 00112c44 size=276
// signature: undefined msm_pcie_debugfs_case_select(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

long msm_pcie_debugfs_case_select(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_2c);
  if (iVar2 == 0) {
    _printk(&DAT_0012e5a8,local_2c);
    if ((rc_sel & 1) != 0) {
      msm_pcie_sel_debug_testcase(msm_pcie_dev,local_2c);
    }
    if ((rc_sel >> 1 & 1) != 0) {
      msm_pcie_sel_debug_testcase(DAT_0012fff8,local_2c);
    }
    if ((rc_sel >> 2 & 1) != 0) {
      msm_pcie_sel_debug_testcase(DAT_00130000,local_2c);
    }
    if ((rc_sel >> 3 & 1) != 0) {
      msm_pcie_sel_debug_testcase(DAT_00130008,local_2c);
    }
    if ((rc_sel >> 4 & 1) != 0) {
      msm_pcie_sel_debug_testcase(DAT_00130010,local_2c);
    }
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_case_open @ 00112d5c size=44
// signature: undefined msm_pcie_debugfs_case_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_case_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_case_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_case_show @ 00112d8c size=100
// signature: undefined msm_pcie_debugfs_case_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_debugfs_case_show(undefined8 param_1)

{
  ulong uVar1;
  
  uVar1 = 0;
  do {
    seq_printf(param_1,"\t%d:\t %s\n",uVar1 & 0xffffffff,(&msm_pcie_debugfs_option_desc)[uVar1]);
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0x1b);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_base_select @ 00112df4 size=260
// signature: undefined msm_pcie_debugfs_base_select(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_base_select(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  iVar4 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_2c);
  if (iVar4 == 0) {
    if (local_2c - 0xbU < 0xfffffff6) {
      _printk(&DAT_0012166d);
      _printk(&DAT_00127a17,base_sel);
    }
    else {
      base_sel = local_2c;
      _printk(&DAT_00126714);
      uVar1 = base_sel - 1;
      if (9 < uVar1) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x112ef4);
        (*pcVar3)();
      }
      if (0xf0 < ((ulong)uVar1 + (ulong)uVar1 * 2) * 8) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x112ef8);
        (*pcVar3)();
      }
      _printk(&DAT_0012f2b6,(&msm_pcie_res_info)[(ulong)uVar1 * 3]);
    }
  }
  else {
    param_3 = (long)iVar4;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_base_select_open @ 00112efc size=44
// signature: undefined msm_pcie_debugfs_base_select_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_base_select_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_base_select_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_base_select_show @ 00112f2c size=392
// signature: undefined msm_pcie_debugfs_base_select_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_debugfs_base_select_show(undefined8 param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined *puVar3;
  
  seq_puts(param_1,"Options:\n");
  seq_printf(param_1,"\t%d: %s\n",1,&DAT_00125146);
  seq_printf(param_1,"\t%d: %s\n",2,&DAT_0012fbee);
  seq_printf(param_1,"\t%d: %s\n",3,"dm_core");
  seq_printf(param_1,"\t%d: %s\n",4,&DAT_001249ef);
  seq_printf(param_1,"\t%d: %s\n",5,&DAT_0012973d);
  seq_printf(param_1,"\t%d: %s\n",6,&DAT_0012276a);
  seq_printf(param_1,"\t%d: %s\n",7,"pcie_sm");
  seq_printf(param_1,"\t%d: %s\n",8,&DAT_001206b8);
  seq_printf(param_1,"\t%d: %s\n",9,&DAT_0012a001);
  seq_printf(param_1,"\t%d: %s\n",10,&DAT_0012fbf2);
  if (base_sel == 0) {
    puVar3 = &DAT_0012f2bc;
  }
  else {
    uVar1 = base_sel - 1;
    if ((0xf0 < (ulong)uVar1 * 0x18) || (uVar1 == 10)) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1130b4);
      (*pcVar2)();
    }
    puVar3 = (&msm_pcie_res_info)[(ulong)uVar1 * 3];
  }
  seq_printf(param_1,"\nCurrent base_sel: %d: %s\n",base_sel,puVar3);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_linkdown_panic @ 001130b8 size=680
// signature: undefined msm_pcie_debugfs_linkdown_panic(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

long msm_pcie_debugfs_linkdown_panic(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar5 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_3c);
  lVar1 = msm_pcie_dev;
  if (iVar5 == 0) {
    uVar6 = (uint)(local_3c != 0);
    lVar2 = DAT_0012fff8;
    if ((rc_sel & 1) != 0) {
      uVar4 = local_3c != 0;
      *(undefined1 *)(msm_pcie_dev + 0x554) = uVar4;
      if (lVar1 != 0) {
        bVar3 = local_3c != 0;
        local_3c = uVar6;
        ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: linkdown_panic is now %d\n",
                       "msm_pcie_debugfs_linkdown_panic",0,bVar3);
        uVar4 = *(undefined1 *)(msm_pcie_dev + 0x554);
        uVar6 = local_3c;
      }
      local_3c = uVar6;
      _printk(&DAT_00126732,"msm_pcie_debugfs_linkdown_panic",0,uVar4);
      lVar2 = DAT_0012fff8;
      uVar6 = local_3c;
    }
    local_3c = uVar6;
    DAT_0012fff8 = lVar2;
    lVar1 = DAT_00130000;
    if ((rc_sel >> 1 & 1) != 0) {
      uVar4 = local_3c != 0;
      *(undefined1 *)(lVar2 + 0x554) = uVar4;
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: linkdown_panic is now %d\n",
                       "msm_pcie_debugfs_linkdown_panic",1,local_3c != 0);
        uVar4 = *(undefined1 *)(DAT_0012fff8 + 0x554);
      }
      _printk(&DAT_00126732,"msm_pcie_debugfs_linkdown_panic",1,uVar4);
      lVar1 = DAT_00130000;
    }
    DAT_00130000 = lVar1;
    lVar2 = DAT_00130008;
    if ((rc_sel >> 2 & 1) != 0) {
      uVar4 = local_3c != 0;
      *(undefined1 *)(lVar1 + 0x554) = uVar4;
      if (lVar1 != 0) {
        ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: linkdown_panic is now %d\n",
                       "msm_pcie_debugfs_linkdown_panic",2,local_3c != 0);
        uVar4 = *(undefined1 *)(DAT_00130000 + 0x554);
      }
      _printk(&DAT_00126732,"msm_pcie_debugfs_linkdown_panic",2,uVar4);
      lVar2 = DAT_00130008;
    }
    DAT_00130008 = lVar2;
    lVar1 = DAT_00130010;
    if ((rc_sel >> 3 & 1) != 0) {
      uVar4 = local_3c != 0;
      *(undefined1 *)(lVar2 + 0x554) = uVar4;
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: linkdown_panic is now %d\n",
                       "msm_pcie_debugfs_linkdown_panic",3,local_3c != 0);
        uVar4 = *(undefined1 *)(DAT_00130008 + 0x554);
      }
      _printk(&DAT_00126732,"msm_pcie_debugfs_linkdown_panic",3,uVar4);
      lVar1 = DAT_00130010;
    }
    DAT_00130010 = lVar1;
    if ((rc_sel >> 4 & 1) != 0) {
      uVar4 = local_3c != 0;
      *(undefined1 *)(lVar1 + 0x554) = uVar4;
      if (lVar1 != 0) {
        ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                       "DBG_FS:%s: PCIe: RC%d: linkdown_panic is now %d\n",
                       "msm_pcie_debugfs_linkdown_panic",4,local_3c != 0);
        uVar4 = *(undefined1 *)(DAT_00130010 + 0x554);
      }
      _printk(&DAT_00126732,"msm_pcie_debugfs_linkdown_panic",4,uVar4);
    }
  }
  else {
    param_3 = (long)iVar5;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_offset @ 00113364 size=96
// signature: undefined msm_pcie_debugfs_wr_offset(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_wr_offset(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  wr_offset = 0;
  iVar1 = msm_pcie_debugfs_parse_input(param_2,param_3);
  if (iVar1 == 0) {
    _printk(&DAT_00121697,wr_offset);
  }
  else {
    param_3 = (long)iVar1;
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_offset_open @ 001133c8 size=44
// signature: undefined msm_pcie_debugfs_wr_offset_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_wr_offset_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_wr_offset_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_offset_show @ 001133f8 size=48
// signature: undefined msm_pcie_debugfs_wr_offset_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_debugfs_wr_offset_show(undefined8 param_1)

{
  seq_printf(param_1,"0x%x\n",wr_offset);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_mask @ 0011342c size=96
// signature: undefined msm_pcie_debugfs_wr_mask(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_wr_mask(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  wr_mask = 0;
  iVar1 = msm_pcie_debugfs_parse_input(param_2,param_3);
  if (iVar1 == 0) {
    _printk(&DAT_00120e14,wr_mask);
  }
  else {
    param_3 = (long)iVar1;
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_mask_open @ 00113490 size=44
// signature: undefined msm_pcie_debugfs_wr_mask_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_wr_mask_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_wr_mask_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_mask_show @ 001134c0 size=48
// signature: undefined msm_pcie_debugfs_wr_mask_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_debugfs_wr_mask_show(undefined8 param_1)

{
  seq_printf(param_1,"0x%x\n",wr_mask);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_value @ 001134f4 size=96
// signature: undefined msm_pcie_debugfs_wr_value(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_wr_value(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  wr_value = 0;
  iVar1 = msm_pcie_debugfs_parse_input(param_2,param_3);
  if (iVar1 == 0) {
    _printk(&DAT_0012d5fc,wr_value);
  }
  else {
    param_3 = (long)iVar1;
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_value_open @ 00113558 size=44
// signature: undefined msm_pcie_debugfs_wr_value_open(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_debugfs_wr_value_open(undefined8 param_1,undefined8 param_2)

{
  single_open(param_2,msm_pcie_debugfs_wr_value_show,0);
  return;
}



//------------------------------------------------------------
// msm_pcie_debugfs_wr_value_show @ 00113588 size=48
// signature: undefined msm_pcie_debugfs_wr_value_show(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_debugfs_wr_value_show(undefined8 param_1)

{
  seq_printf(param_1,"0x%x\n",wr_value);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_debugfs_boot_option @ 001135bc size=636
// signature: undefined msm_pcie_debugfs_boot_option(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

long msm_pcie_debugfs_boot_option(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar3 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_3c);
  lVar1 = msm_pcie_dev;
  if (iVar3 == 0) {
    if (local_3c < 4) {
      lVar2 = DAT_0012fff8;
      if ((rc_sel & 1) != 0) {
        *(uint *)(msm_pcie_dev + 0x558) = local_3c;
        uVar4 = local_3c;
        if (lVar1 != 0) {
          ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
                         "msm_pcie_debugfs_boot_option",0);
          uVar4 = *(uint *)(msm_pcie_dev + 0x558);
        }
        _printk(&DAT_001206bc,"msm_pcie_debugfs_boot_option",0,uVar4);
        lVar2 = DAT_0012fff8;
      }
      DAT_0012fff8 = lVar2;
      lVar1 = DAT_00130000;
      if ((rc_sel >> 1 & 1) != 0) {
        *(uint *)(lVar2 + 0x558) = local_3c;
        uVar4 = local_3c;
        if (lVar2 != 0) {
          ipc_log_string(*(undefined8 *)(lVar2 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
                         "msm_pcie_debugfs_boot_option",1);
          uVar4 = *(uint *)(DAT_0012fff8 + 0x558);
        }
        _printk(&DAT_001206bc,"msm_pcie_debugfs_boot_option",1,uVar4);
        lVar1 = DAT_00130000;
      }
      DAT_00130000 = lVar1;
      lVar2 = DAT_00130008;
      if ((rc_sel >> 2 & 1) != 0) {
        *(uint *)(lVar1 + 0x558) = local_3c;
        uVar4 = local_3c;
        if (lVar1 != 0) {
          ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
                         "msm_pcie_debugfs_boot_option",2);
          uVar4 = *(uint *)(DAT_00130000 + 0x558);
        }
        _printk(&DAT_001206bc,"msm_pcie_debugfs_boot_option",2,uVar4);
        lVar2 = DAT_00130008;
      }
      DAT_00130008 = lVar2;
      lVar1 = DAT_00130010;
      if ((rc_sel >> 3 & 1) != 0) {
        *(uint *)(lVar2 + 0x558) = local_3c;
        uVar4 = local_3c;
        if (lVar2 != 0) {
          ipc_log_string(*(undefined8 *)(lVar2 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
                         "msm_pcie_debugfs_boot_option",3);
          uVar4 = *(uint *)(DAT_00130008 + 0x558);
        }
        _printk(&DAT_001206bc,"msm_pcie_debugfs_boot_option",3,uVar4);
        lVar1 = DAT_00130010;
      }
      DAT_00130010 = lVar1;
      if ((rc_sel >> 4 & 1) != 0) {
        *(uint *)(lVar1 + 0x558) = local_3c;
        uVar4 = local_3c;
        if (lVar1 != 0) {
          ipc_log_string(*(undefined8 *)(lVar1 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: boot_option is now 0x%x\n",
                         "msm_pcie_debugfs_boot_option",4);
          uVar4 = *(uint *)(DAT_00130010 + 0x558);
        }
        _printk(&DAT_001206bc,"msm_pcie_debugfs_boot_option",4,uVar4);
      }
    }
    else {
      _printk(&DAT_00120e31,local_3c);
    }
  }
  else {
    param_3 = (long)iVar3;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_aer_enable @ 0011383c size=468
// signature: undefined msm_pcie_debugfs_aer_enable(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_aer_enable(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  ulong uVar8;
  uint uVar9;
  undefined8 uVar10;
  uint local_6c;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_6c = 0;
  iVar2 = msm_pcie_debugfs_parse_input(param_2,param_3,&local_6c);
  if (iVar2 == 0) {
    uVar8 = 0;
    uVar5 = (ulong)rc_sel;
    local_6c = (uint)(local_6c != 0);
    do {
      if ((uVar5 >> (uVar8 & 0x3f) & 1) != 0) {
        *(bool *)((&msm_pcie_dev)[uVar8] + 0x4eb) = local_6c != 0;
        lVar6 = (&msm_pcie_dev)[uVar8];
        lVar7 = 0;
        if (lVar6 != 0) {
          ipc_log_string(*(undefined8 *)(lVar6 + 0x730),
                         "DBG_FS:%s: PCIe: RC%d: aer_enable is now %d\n",
                         "msm_pcie_debugfs_aer_enable",uVar8 & 0xffffffff,
                         *(undefined1 *)(lVar6 + 0x4eb));
          lVar7 = (&msm_pcie_dev)[uVar8];
        }
        _printk(&DAT_001270b0,"msm_pcie_debugfs_aer_enable",uVar8 & 0xffffffff,
                *(undefined1 *)(lVar7 + 0x4eb));
        uVar1 = local_6c;
        lVar7 = *(long *)((&msm_pcie_dev)[uVar8] + 0x3a0) + 0x3c;
        uVar3 = readl_relaxed(lVar7);
        uVar9 = 0xfffeffff;
        if (uVar1 != 0) {
          uVar9 = 0xffffffff;
        }
        writel_relaxed(uVar9 & uVar3 | (uint)(uVar1 != 0) << 0x10,lVar7);
        readl_relaxed(lVar7);
        lVar6 = (&msm_pcie_dev)[uVar8];
        lVar7 = 0;
        if (lVar6 != 0) {
          uVar10 = *(undefined8 *)(lVar6 + 0x730);
          uVar4 = readl_relaxed(*(long *)(lVar6 + 0x3a0) + 0x3c);
          ipc_log_string(uVar10,"DBG_FS:%s: RC%d: PCIE20_BRIDGE_CTRL: 0x%x\n",
                         "msm_pcie_debugfs_aer_enable",uVar8 & 0xffffffff,uVar4);
          lVar7 = (&msm_pcie_dev)[uVar8];
        }
        uVar4 = readl_relaxed(*(long *)(lVar7 + 0x3a0) + 0x3c);
        _printk(&DAT_0012888a,"msm_pcie_debugfs_aer_enable",uVar8 & 0xffffffff,uVar4);
        uVar5 = (ulong)rc_sel;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 != 5);
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pcie_debugfs_corr_counter_limit @ 00113a14 size=96
// signature: undefined msm_pcie_debugfs_corr_counter_limit(void)
// callers: []
//------------------------------------------------------------

long msm_pcie_debugfs_corr_counter_limit(undefined8 param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  
  corr_counter_limit = 0;
  iVar1 = msm_pcie_debugfs_parse_input(param_2,param_3);
  if (iVar1 == 0) {
    _printk(&DAT_00122779,corr_counter_limit);
  }
  else {
    param_3 = (long)iVar1;
  }
  return param_3;
}



//------------------------------------------------------------
// msm_pci_probe @ 00113a78 size=296
// signature: undefined msm_pci_probe(void)
// callers: []
//------------------------------------------------------------

int msm_pci_probe(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(*(long *)(param_1 + 0x10) + 0xe8) + 200);
  if (lVar4 != 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 0x728),"DBG1:%s: PCIe: RC%d: PCI Probe\n","msm_pci_probe"
                   ,*(undefined4 *)(lVar4 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar4 + 0x720),"%s: PCIe: RC%d: PCI Probe\n","msm_pci_probe",
                   *(undefined4 *)(lVar4 + 0x570));
  }
  if (*(long *)(param_1 + 0x3b8) == 0) {
    iVar2 = -0x13;
  }
  else {
    lVar1 = param_1 + 0xd0;
    plVar3 = (long *)devm_kmalloc(lVar1,0x10,0xdc0);
    if (plVar3 == (long *)0x0) {
      iVar2 = -0xc;
    }
    else {
      *plVar3 = lVar4;
      plVar3[1] = param_1;
      *(long **)(param_1 + 0x168) = plVar3;
      iVar2 = dma_set_mask(lVar1,0xffffffffffffffff);
      if (iVar2 == 0) {
        dma_set_coherent_mask(lVar1,0xffffffffffffffff);
      }
      else {
        if (lVar4 != 0) {
          ipc_log_string(*(undefined8 *)(lVar4 + 0x728),"ERR:%s: DMA set mask failed (%d)\n",
                         "msm_pci_probe",iVar2);
          ipc_log_string(*(undefined8 *)(lVar4 + 0x720),"%s: DMA set mask failed (%d)\n",
                         "msm_pci_probe",iVar2);
        }
        _printk(&DAT_0012598b,"msm_pci_probe",iVar2);
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// msm_pcie_drv_notify_client @ 00113ba0 size=252
// signature: undefined msm_pcie_drv_notify_client(void)
// callers: [msm_pcie_drv_rpmsg_remove]
//------------------------------------------------------------

void msm_pcie_drv_notify_client(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = 0;
  do {
    lVar1 = *(long *)(*(long *)(param_1 + 0x10) + lVar2);
    if ((lVar1 != 0) && (pcVar3 = *(char **)(lVar1 + 0x790), pcVar3 != (char *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar1 + 0x728),"DBG1:%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),param_2);
      ipc_log_string(*(undefined8 *)(lVar1 + 0x720),"%s: PCIe: RC%d: event %d received\n",
                     "msm_pcie_drv_notify_client",*(undefined4 *)(lVar1 + 0x570),param_2);
      if ((*pcVar3 != '\0') && (msm_pcie_notify_client(lVar1,param_2), (param_2 >> 5 & 1) != 0)) {
        mutex_lock(lVar1 + 0x830);
        *pcVar3 = '\0';
        cancel_work_sync(lVar1 + 0x7c8);
        cancel_work_sync(lVar1 + 0x798);
        mutex_unlock(lVar1 + 0x830);
      }
    }
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0x28);
  return;
}



//------------------------------------------------------------
// msm_pcie_notify_client @ 00113c9c size=404
// signature: undefined msm_pcie_notify_client(void)
// callers: [msm_pcie_ssr_notifier, handle_link_recover, handle_wake_func, msm_pcie_drv_notify_client, msm_pcie_handle_linkdown, msm_pcie_drv_connect_worker, handle_wake_irq, handle_global_irq, msm_pcie_drv_cesta_connect_worker, msm_pcie_drv_connect_notify_all]
//------------------------------------------------------------

undefined8 msm_pcie_notify_client(long param_1,uint param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  code *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x718;
  local_48 = *(long *)(lVar2 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  plVar4 = (long *)*(long *)(param_1 + 0x708);
  do {
    plVar3 = plVar4;
    if (plVar3 == (long *)(param_1 + 0x708)) {
      uVar7 = 0;
      goto LAB_00113cf8;
    }
    plVar4 = (long *)*plVar3;
  } while (((*(uint *)(plVar3 + 2) & param_2) == 0) || (plVar3[5] == 0));
  local_60 = plVar3[3];
  local_68 = CONCAT44(local_68._4_4_,param_2);
  local_58 = plVar3[8];
  local_50 = CONCAT44(local_50._4_4_,*(undefined4 *)(plVar3 + 9));
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x730),"DUMP:%s: PCIe: callback RC%d for event %d\n",
                   "msm_pcie_notify_client",*(undefined4 *)(param_1 + 0x570),param_2);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  if (*(int *)((code *)plVar3[5] + -4) != 0x68eb264) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x113dc4);
    (*pcVar5)();
  }
  (*(code *)plVar3[5])(&local_68);
  uVar6 = _raw_spin_lock_irqsave(lVar1);
  uVar7 = 1;
  if (((param_2 == 1) && ((*(uint *)(plVar3 + 0xb) >> 1 & 1) != 0)) &&
     (*(undefined1 *)(param_1 + 0x4b4) = 1, param_1 != 0)) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: Client of RC%d will recover the link later.\n",
                   "msm_pcie_notify_client",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                   "%s: PCIe: Client of RC%d will recover the link later.\n",
                   "msm_pcie_notify_client",*(undefined4 *)(param_1 + 0x570));
  }
LAB_00113cf8:
  _raw_spin_unlock_irqrestore(lVar1,uVar6);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// msm_pcie_probe @ 00113e34 size=17900
// signature: undefined msm_pcie_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong msm_pcie_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  code *pcVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  undefined4 uVar13;
  long lVar14;
  undefined8 uVar15;
  long lVar16;
  long *plVar17;
  undefined4 *puVar18;
  int *piVar19;
  undefined *puVar20;
  char *pcVar21;
  uint *puVar22;
  long lVar23;
  undefined8 *puVar24;
  undefined8 uVar25;
  ulong uVar26;
  ulong uVar27;
  ulong uVar28;
  long *plVar29;
  long *plVar30;
  char *pcVar31;
  undefined4 *puVar32;
  ulong *puVar33;
  ulong *puVar34;
  undefined8 *puVar35;
  ulong uVar36;
  undefined8 uVar37;
  int local_cc;
  uint local_c8;
  int local_c4;
  undefined8 local_c0;
  undefined7 uStack_b8;
  undefined1 uStack_b1;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar14 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_70 = *(long *)(lVar14 + 0x638);
  local_cc = 0;
  local_c8 = 0xffffffff;
  _dev_info(plVar1,"PCIe: %s\n","msm_pcie_probe");
  mutex_lock(&DAT_00130190);
  uVar37 = *(undefined8 *)(param_1 + 0x2f8);
  uVar10 = of_property_read_variable_u32_array(uVar37,"cell-index",&local_c8,1,0);
  if ((int)uVar10 < 0) {
    uVar36 = (ulong)uVar10;
    _dev_err(plVar1,"PCIe: %s: Did not find RC index\n","msm_pcie_probe");
LAB_00117bdc:
    if (local_c8 < 5) goto LAB_00117be8;
  }
  else {
    if ((int)local_c8 < 5) {
      lVar14 = devm_pci_alloc_host_bridge(plVar1,0xdb8);
      uVar10 = local_c8;
      uVar28 = (ulong)local_c8;
      if (lVar14 == 0) {
        uVar36 = 0xfffffff4;
        _printk(&DAT_0012cde6,uVar28,0xfffffff4);
        goto LAB_00117bdc;
      }
      if (4 < local_c8) goto LAB_001183f8;
      uStack_b8 = 0;
      (&msm_pcie_dev)[uVar28] = lVar14 + 0x440;
      local_c0._0_4_ = 0;
      local_c0._4_4_ = 0;
      scnprintf(&local_c0,0xf,"pcie%d-short",uVar28);
      uVar15 = ipc_log_context_create(0x32,&local_c0,0);
      *(undefined8 *)((&msm_pcie_dev)[uVar28] + 0x720) = uVar15;
      scnprintf(&local_c0,0xf,"pcie%d-long",uVar10);
      uVar15 = ipc_log_context_create(0x32,&local_c0,0);
      *(undefined8 *)((&msm_pcie_dev)[uVar28] + 0x728) = uVar15;
      scnprintf(&local_c0,0xf,"pcie%d-dump",uVar10);
      uVar15 = ipc_log_context_create(0x32,&local_c0,0);
      *(undefined8 *)((&msm_pcie_dev)[uVar28] + 0x730) = uVar15;
      lVar23 = (&msm_pcie_dev)[uVar28];
      if (((*(long *)(lVar23 + 0x720) == 0) || (*(long *)(lVar23 + 0x728) == 0)) ||
         (*(long *)(lVar23 + 0x730) == 0)) {
        _printk(&DAT_001290da,"msm_pcie_create_ipc_logs",&local_c0);
      }
      pcie_drv = pcie_drv + 1;
      if (4 < local_c8) goto LAB_001183f8;
      plVar29 = (long *)(&msm_pcie_dev)[local_c8];
      *(uint *)(plVar29 + 0xae) = local_c8;
      *plVar29 = param_1;
      *(undefined4 *)(plVar29 + 0x96) = 0;
      plVar29[0x1a4] = lVar14;
      *(undefined4 *)((long)plVar29 + 0x444) = 0;
      *(undefined4 *)(plVar29 + 0xe3) = 0;
      *(undefined1 *)(plVar29 + 0x88) = 0;
      __mutex_init(plVar29 + 0x8a,"&pcie_dev->enumerate_lock",&msm_pcie_lock_init___key);
      __mutex_init(plVar29 + 0x90,"&pcie_dev->setup_lock",&msm_pcie_lock_init___key_965);
      __mutex_init(plVar29 + 0xc2,"&pcie_dev->recovery_lock",&msm_pcie_lock_init___key_967);
      __mutex_init(plVar29 + 0xc9,"&pcie_dev->aspm_lock",&msm_pcie_lock_init___key_969);
      __mutex_init(plVar29 + 0x106,"&pcie_dev->drv_pc_lock",&msm_pcie_lock_init___key_971);
      *(undefined4 *)(plVar29 + 200) = 0;
      plVar4 = plVar29 + 0x100;
      *(undefined1 *)(plVar29 + 0xaf) = 0;
      plVar29[0xd3] = 100000;
      plVar29[0xf9] = 0xfffffffe0;
      plVar29[0xfa] = (long)(plVar29 + 0xfa);
      plVar29[0xfb] = (long)(plVar29 + 0xfa);
      plVar29[0xfc] = (long)msm_pcie_drv_disable_pc;
      plVar29[0xf3] = 0xfffffffe0;
      plVar29[0xf4] = (long)(plVar29 + 0xf4);
      plVar29[0xf5] = (long)(plVar29 + 0xf4);
      plVar29[0xf6] = (long)msm_pcie_drv_enable_pc;
      plVar29[0xff] = 0xfffffffe0;
      plVar29[0x100] = (long)plVar4;
      plVar29[0x101] = (long)plVar4;
      plVar29[0x102] = (long)msm_pcie_drv_connect_worker;
      plVar29[0xbc] = 0xfffffffe0;
      plVar29[0xbd] = (long)(plVar29 + 0xbd);
      plVar29[0xbe] = (long)(plVar29 + 0xbd);
      plVar29[0xbf] = (long)msm_pcie_disable_resource;
      plVar29[0xd6] = (long)(plVar29 + 0xd6);
      plVar29[0xd7] = (long)(plVar29 + 0xd6);
      plVar29[0xd8] = (long)(plVar29 + 0xd8);
      plVar29[0xd9] = (long)(plVar29 + 0xd8);
      plVar29[0xe1] = (long)(plVar29 + 0xe1);
      plVar29[0xe2] = (long)(plVar29 + 0xe1);
      if (plVar29 != (long *)0x0) {
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC index is %d.\n","msm_pcie_probe",
                       (int)plVar29[0xae]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC index is %d.\n","msm_pcie_probe",
                       (int)plVar29[0xae]);
      }
      uVar10 = local_c8;
      uVar36 = (ulong)local_c8;
      lVar14 = of_find_property(uVar37,"qcom,no-l0s-supported",0);
      *(bool *)((long)plVar29 + 0x4d9) = lVar14 == 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125754;
        if (lVar14 != 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: L0s is %s supported.\n","msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_0012768e;
        if (*(char *)((long)plVar29 + 0x4d9) != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: L0s is %s supported.\n","msm_pcie_read_dt",puVar20);
      }
      lVar14 = of_find_property(uVar37,"qcom,no-l1-supported",0);
      *(bool *)((long)plVar29 + 0x4da) = lVar14 == 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125754;
        if (lVar14 != 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: L1 is %s supported.\n","msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_0012768e;
        if (*(char *)((long)plVar29 + 0x4da) != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: L1 is %s supported.\n","msm_pcie_read_dt",puVar20);
      }
      lVar14 = of_find_property(uVar37,"qcom,no-l1ss-supported",0);
      bVar9 = lVar14 == 0;
      *(byte *)((long)plVar29 + 0x4db) = bVar9;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125754;
        if (lVar14 != 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: L1ss is %s supported.\n","msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_0012768e;
        if (*(char *)((long)plVar29 + 0x4db) != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: L1ss is %s supported.\n","msm_pcie_read_dt",puVar20);
        bVar9 = *(byte *)((long)plVar29 + 0x4db);
      }
      *(uint *)((long)plVar29 + 0x4dc) = (uint)bVar9 * 0x1010101;
      lVar14 = of_find_property(uVar37,"qcom,apss-based-l1ss-sleep",0);
      *(bool *)((long)plVar29 + 0x441) = lVar14 != 0;
      lVar14 = of_find_property(uVar37,"qcom,no-client-based-bw-voting",0);
      *(bool *)(plVar29 + 0x1a5) = lVar14 != 0;
      of_property_read_variable_u32_array(uVar37,"qcom,l1-2-th-scale",plVar29 + 0x9c,1,0);
      of_property_read_variable_u32_array(uVar37,"qcom,l1-2-th-value",(long)plVar29 + 0x4e4,1,0);
      if (plVar29 != (long *)0x0) {
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: L1.2 threshold scale: %d value: %d.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x9c],
                       *(undefined4 *)((long)plVar29 + 0x4e4));
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: L1.2 threshold scale: %d value: %d.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x9c],
                       *(undefined4 *)((long)plVar29 + 0x4e4));
      }
      of_property_read_variable_u32_array(uVar37,"qcom,device-vendor-id",(long)plVar29 + 0x564,1,0);
      lVar14 = of_find_property(uVar37,"qcom,common-clk-en",0);
      *(bool *)(plVar29 + 0x9d) = lVar14 != 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125754;
        if (lVar14 == 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: Common clock is %s enabled.\n","msm_pcie_read_dt",
                       puVar20);
        puVar20 = &DAT_0012768e;
        if ((char)plVar29[0x9d] != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: Common clock is %s enabled.\n","msm_pcie_read_dt",puVar20)
        ;
      }
      lVar14 = of_find_property(uVar37,"qcom,clk-power-manage-en",0);
      *(bool *)((long)plVar29 + 0x4e9) = lVar14 != 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125754;
        if (lVar14 == 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: Clock power management is %s enabled.\n",
                       "msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_0012768e;
        if (*(char *)((long)plVar29 + 0x4e9) != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: Clock power management is %s enabled.\n",
                       "msm_pcie_read_dt",puVar20);
      }
      lVar14 = of_find_property(uVar37,"qcom,no-aux-clk-sync",0);
      *(bool *)((long)plVar29 + 0x4ea) = lVar14 == 0;
      if (plVar29 == (long *)0x0) {
        of_property_read_variable_u32_array(uVar37,"qcom,smmu-sid-base",0x4ec,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,boot-option",0x558,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,pcie-phy-ver",0x574,1,0);
        _DAT_000004f0 = 0x14;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,link-check-max-count",0x4f0,1,0);
        plVar30 = (long *)&DAT_000004f8;
        of_property_read_variable_u32_array(uVar37,"qcom,target-link-speed",0x4f8,1,0);
      }
      else {
        puVar20 = &DAT_00125754;
        if (lVar14 != 0) {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: AUX clock is %s synchronous to Core clock.\n",
                       "msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_0012768e;
        if (*(char *)((long)plVar29 + 0x4ea) != '\0') {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe4],"%s: AUX clock is %s synchronous to Core clock.\n",
                       "msm_pcie_read_dt",puVar20);
        of_property_read_variable_u32_array(uVar37,"qcom,smmu-sid-base",(long)plVar29 + 0x4ec,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: qcom,smmu-sid-base: 0x%x.\n","msm_pcie_read_dt"
                       ,(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x4ec));
        ipc_log_string(plVar29[0xe4],"%s: RC%d: qcom,smmu-sid-base: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x4ec));
        of_property_read_variable_u32_array(uVar37,"qcom,boot-option",plVar29 + 0xab,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d boot option is 0x%x.\n","msm_pcie_read_dt"
                       ,(int)plVar29[0xae],(int)plVar29[0xab]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d boot option is 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xab]);
        of_property_read_variable_u32_array(uVar37,"qcom,pcie-phy-ver",(long)plVar29 + 0x574,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: pcie-phy-ver: %d.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x574));
        ipc_log_string(plVar29[0xe4],"%s: RC%d: pcie-phy-ver: %d.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x574));
        *(undefined4 *)(plVar29 + 0x9e) = 0x14;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,link-check-max-count",plVar29 + 0x9e,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: link-check-max-count: %u.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x9e]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: link-check-max-count: %u.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x9e]);
        plVar30 = plVar29 + 0x9f;
        of_property_read_variable_u32_array(uVar37,"qcom,target-link-speed",plVar30,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: target-link-speed: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x9f]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: target-link-speed: 0x%x.\n","msm_pcie_read_dt"
                       ,(int)plVar29[0xae],(int)plVar29[0x9f]);
      }
      *(int *)((long)plVar29 + 0x4f4) = (int)*plVar30;
      if (4 < uVar10) goto LAB_001183f8;
      *(undefined4 *)((&msm_pcie_dev)[uVar36] + 0x500) = 0;
      of_property_read_variable_u32_array(uVar37,"qcom,target-link-width",plVar29 + 0xa0,1,0);
      if (plVar29 == (long *)0x0) {
        of_property_read_variable_u32_array(uVar37,"qcom,n-fts",0x508,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,ep-latency",0x50c,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,switch-latency",0x510,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,wr-halt-size",0x514,1,0);
      }
      else {
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: target-link-width: %d.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa0]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: target-link-width: %d.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa0]);
        of_property_read_variable_u32_array(uVar37,"qcom,n-fts",plVar29 + 0xa1,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: n-fts: 0x%x.\n","msm_pcie_read_dt",(int)plVar29[0xa1]
                      );
        ipc_log_string(plVar29[0xe4],"%s: n-fts: 0x%x.\n","msm_pcie_read_dt",(int)plVar29[0xa1]);
        of_property_read_variable_u32_array(uVar37,"qcom,ep-latency",(long)plVar29 + 0x50c,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: ep-latency: %ums.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x50c));
        ipc_log_string(plVar29[0xe4],"%s: RC%d: ep-latency: %ums.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x50c));
        of_property_read_variable_u32_array(uVar37,"qcom,switch-latency",plVar29 + 0xa2,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: switch-latency: %ums.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa2]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: switch-latency: %ums.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa2]);
        iVar11 = of_property_read_variable_u32_array
                           (uVar37,"qcom,wr-halt-size",(long)plVar29 + 0x514,1,0);
        if (iVar11 < 0) {
          ipc_log_string(plVar29[0xe5],
                         "DBG1:%s: RC%d: wr-halt-size not specified in dt. Use default value.\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],
                         "%s: RC%d: wr-halt-size not specified in dt. Use default value.\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae]);
        }
        else {
          ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: wr-halt-size: 0x%x.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x514));
          ipc_log_string(plVar29[0xe4],"%s: RC%d: wr-halt-size: 0x%x.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x514));
        }
      }
      lVar14 = of_find_property(uVar37,"qcom,gdsc-clk-drv-ss-nonvotable",0);
      *(bool *)((long)plVar29 + 0x562) = lVar14 != 0;
      if (plVar29 == (long *)0x0) {
        of_property_read_variable_u32_array(uVar37,"qcom,num-parf-testbus-sel",0x6d0,1,0);
      }
      else {
        puVar20 = &DAT_0012768e;
        if (lVar14 == 0) {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: Gdsc clk is %s votable during drv hand over.\n",
                       "msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_00125754;
        if (*(char *)((long)plVar29 + 0x562) != '\0') {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe4],"%s: Gdsc clk is %s votable during drv hand over.\n",
                       "msm_pcie_read_dt",puVar20);
        of_property_read_variable_u32_array(uVar37,"qcom,num-parf-testbus-sel",plVar29 + 0xda,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: num-parf-testbus-sel: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xda]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: num-parf-testbus-sel: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xda]);
      }
      lVar14 = of_find_property(uVar37,"qcom,bdf-halt-dis",0);
      *(bool *)((long)plVar29 + 0x563) = lVar14 != 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_0012768e;
        if (lVar14 == 0) {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe BDF halt feature is %s enabled.\n",
                       "msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_00125754;
        if (*(char *)((long)plVar29 + 0x563) != '\0') {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe4],"%s: PCIe BDF halt feature is %s enabled.\n","msm_pcie_read_dt"
                       ,puVar20);
      }
      lVar14 = of_find_property(uVar37,"qcom,pcie-halt-feature-dis",0);
      *(bool *)((long)plVar29 + 0x56c) = lVar14 != 0;
      if (plVar29 == (long *)0x0) {
        of_property_read_variable_u32_array(uVar37,"qcom,phy-status-offset",0x518,1,0);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,phy-status-bit",0x51c,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,phy-power-down-offset",0x520,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,phy-aux-clk-config1-offset",0x524,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,phy-pll-clk-enable1-offset",0x528,1,0);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,eq-pset-req-vec",0x52c,1,0);
        _DAT_00000530 = 0x55555555;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,core-preset",0x530,1,0);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,eq-fmdc-t-min-phase23",0x534,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,cpl-timeout",0x538,1,0);
      }
      else {
        puVar20 = &DAT_0012768e;
        if (lVar14 == 0) {
          puVar20 = &DAT_00125754;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe halt feature is %s enabled.\n",
                       "msm_pcie_read_dt",puVar20);
        puVar20 = &DAT_00125754;
        if (*(char *)((long)plVar29 + 0x56c) != '\0') {
          puVar20 = &DAT_0012768e;
        }
        ipc_log_string(plVar29[0xe4],"%s: PCIe halt feature is %s enabled.\n","msm_pcie_read_dt",
                       puVar20);
        of_property_read_variable_u32_array(uVar37,"qcom,phy-status-offset",plVar29 + 0xa3,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: phy-status-offset: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa3]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: phy-status-offset: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa3]);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,phy-status-bit",(long)plVar29 + 0x51c,1,0)
        ;
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: phy-status-bit: %u.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x51c));
        ipc_log_string(plVar29[0xe4],"%s: RC%d: phy-status-bit: %u.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x51c));
        of_property_read_variable_u32_array(uVar37,"qcom,phy-power-down-offset",plVar29 + 0xa4,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: phy-power-down-offset: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa4]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: phy-power-down-offset: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa4]);
        of_property_read_variable_u32_array
                  (uVar37,"qcom,phy-aux-clk-config1-offset",(long)plVar29 + 0x524,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: phy-aux-clk-config1-offset: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x524))
        ;
        ipc_log_string(plVar29[0xe4],"%s: RC%d: phy-aux-clk-config1-offset: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x524))
        ;
        of_property_read_variable_u32_array
                  (uVar37,"qcom,phy-pll-clk-enable1-offset",plVar29 + 0xa5,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: phy-pll-clk-enable1-offset: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa5]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: phy-pll-clk-enable1-offset: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa5]);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,eq-pset-req-vec",(long)plVar29 + 0x52c,1,0
                  );
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: eq-pset-req-vec: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x52c));
        ipc_log_string(plVar29[0xe4],"%s: RC%d: eq-pset-req-vec: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x52c));
        *(undefined4 *)(plVar29 + 0xa6) = 0x55555555;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,core-preset",plVar29 + 0xa6,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: core-preset: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa6]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: core-preset: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa6]);
        of_property_read_variable_u32_array
                  (*(undefined8 *)(param_1 + 0x2f8),"qcom,eq-fmdc-t-min-phase23",
                   (long)plVar29 + 0x534,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: qcom,eq-fmdc-t-min-phase23: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x534))
        ;
        ipc_log_string(plVar29[0xe4],"%s: RC%d: qcom,eq-fmdc-t-min-phase23: 0x%x.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x534))
        ;
        of_property_read_variable_u32_array(uVar37,"qcom,cpl-timeout",plVar29 + 0xa7,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: cpl-timeout: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa7]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: cpl-timeout: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa7]);
      }
      plVar29[0xa8] = 0x3ed000003e8;
      of_property_read_variable_u32_array(uVar37,"qcom,perst-delay-us-min",plVar29 + 0xa8,1,0);
      of_property_read_variable_u32_array
                (uVar37,"qcom,perst-delay-us-max",(long)plVar29 + 0x544,1,0);
      if (plVar29 == (long *)0x0) {
        _DAT_00000548 = 5;
        of_property_read_variable_u32_array(uVar37,"qcom,tlp-rd-size",0x548,1,0);
        of_property_read_variable_u32_array(uVar37,"qcom,aux-clk-freq",0x54c,1,0);
        DAT_000004eb = 1;
        lVar14 = of_find_property(uVar37,"msi-map",0);
        if (lVar14 != 0) goto LAB_00115170;
      }
      else {
        ipc_log_string(plVar29[0xe5],
                       "DBG1:%s: RC%d: perst-delay-us-min: %dus. perst-delay-us-max: %dus.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa8],
                       *(undefined4 *)((long)plVar29 + 0x544));
        ipc_log_string(plVar29[0xe4],
                       "%s: RC%d: perst-delay-us-min: %dus. perst-delay-us-max: %dus.\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0xa8],
                       *(undefined4 *)((long)plVar29 + 0x544));
        *(undefined4 *)(plVar29 + 0xa9) = 5;
        of_property_read_variable_u32_array(uVar37,"qcom,tlp-rd-size",plVar29 + 0xa9,1,0);
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: tlp-rd-size: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa9]);
        ipc_log_string(plVar29[0xe4],"%s: RC%d: tlp-rd-size: 0x%x.\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0xa9]);
        iVar11 = of_property_read_variable_u32_array
                           (uVar37,"qcom,aux-clk-freq",(long)plVar29 + 0x54c,1,0);
        if (iVar11 < 0) {
          ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: using default aux clock frequency.\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: RC%d: using default aux clock frequency.\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae]);
        }
        else {
          ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: aux clock frequency: %d.\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae],
                         *(undefined4 *)((long)plVar29 + 0x54c));
          ipc_log_string(plVar29[0xe4],"%s: RC%d: aux clock frequency: %d.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0x54c));
        }
        *(undefined1 *)((long)plVar29 + 0x4eb) = 1;
        lVar14 = of_find_property(uVar37,"msi-map",0);
        if (lVar14 == 0) {
          ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: LPI not supported.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: RC%d: LPI not supported.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae]);
        }
        else {
          ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: LPI supported.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: RC%d: LPI supported.\n","msm_pcie_read_dt",
                         (int)plVar29[0xae]);
LAB_00115170:
          *(undefined1 *)(plVar29 + 0xac) = 1;
        }
      }
      iVar11 = of_property_read_variable_u32_array
                         (uVar37,"qcom,pcie-clkreq-offset",plVar29 + 0xad,1,0);
      if (iVar11 < 0) {
        *(undefined4 *)(plVar29 + 0xad) = 0;
      }
      lVar14 = of_find_property(uVar37,"qcom,config-recovery",0);
      *(bool *)(plVar29 + 0xeb) = lVar14 != 0;
      if (lVar14 != 0) {
        if (plVar29 != (long *)0x0) {
          ipc_log_string(plVar29[0xe6],"DUMP:%s: PCIe RC%d config space recovery enabled\n",
                         "msm_pcie_read_dt",(int)plVar29[0xae]);
        }
        plVar29[0xec] = 0xfffffffe0;
        plVar29[0xed] = (long)(plVar29 + 0xed);
        plVar29[0xee] = (long)(plVar29 + 0xed);
        plVar29[0xef] = (long)handle_link_recover;
      }
      of_property_read_variable_u32_array
                (uVar37,"qcom,l1ss-sleep-disable",(long)plVar29 + 0xd14,1,0);
      iVar11 = of_property_read_variable_u32_array
                         (uVar37,"qcom,drv-l1ss-timeout-us",plVar29 + 0x1a2,1,0);
      if (iVar11 < 0) {
        *(undefined4 *)(plVar29 + 0x1a2) = 100000;
      }
      if (plVar29 != (long *)0x0) {
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: DRV L1ss timeout: %dus\n",
                       "msm_pcie_read_dt",(int)plVar29[0xae],(int)plVar29[0x1a2]);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: DRV L1ss timeout: %dus\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],(int)plVar29[0x1a2]);
      }
      plVar30 = plVar29 + 0xae;
      iVar11 = of_property_read_string(uVar37,"qcom,drv-name",plVar29 + 0x110);
      if (iVar11 == 0) {
        *(undefined1 *)(plVar29 + 0x111) = 1;
        lVar14 = devm_kmalloc(*plVar29 + 0x10,0x120,0xdc0);
        if (lVar14 == 0) {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(plVar29[0xe5],"ERR:%s: PCIe: RC%d: DRV: failed to setup DRV: ret: %d\n",
                           "msm_pcie_read_dt",(int)plVar29[0xae],0xfffffff4);
            ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: DRV: failed to setup DRV: ret: %d\n",
                           "msm_pcie_read_dt",(int)plVar29[0xae],0xfffffff4);
          }
          _printk(&DAT_00120ecf,"msm_pcie_read_dt",(int)*plVar30,0xfffffff4);
        }
        else {
          uVar13 = (undefined4)plVar29[0xae];
          *(undefined4 *)(lVar14 + 1) = 1;
          *(undefined4 *)(lVar14 + 0x19) = 0xc0000000;
          *(undefined4 *)(lVar14 + 0xf4) = uVar13;
          *(undefined2 *)(lVar14 + 5) = 0xc;
          *(undefined4 *)(lVar14 + 0x41) = 0xc0000001;
          *(undefined2 *)(lVar14 + 0xb) = 0x10;
          *(undefined4 *)(lVar14 + 0xd) = uVar13;
          *(undefined4 *)(lVar14 + 0x1d) = uVar13;
          *(undefined4 *)(lVar14 + 0x29) = 1;
          *(undefined2 *)(lVar14 + 0x2d) = 0xc;
          *(undefined2 *)(lVar14 + 0x33) = 0x10;
          *(undefined4 *)(lVar14 + 0x35) = uVar13;
          *(undefined4 *)(lVar14 + 0x45) = uVar13;
          *(undefined4 *)(lVar14 + 0x51) = 1;
          *(undefined2 *)(lVar14 + 0x55) = 0xc;
          *(undefined2 *)(lVar14 + 0x5b) = 0x10;
          *(undefined4 *)(lVar14 + 0x5d) = uVar13;
          *(undefined4 *)(lVar14 + 0x69) = 0xc0000005;
          *(undefined4 *)(lVar14 + 0x6d) = uVar13;
          uVar10 = *(uint *)(plVar29 + 0x1a2);
          *(undefined2 *)(lVar14 + 0x7d) = 0xc;
          *(undefined2 *)(lVar14 + 0xa5) = 0xc;
          *(undefined2 *)(lVar14 + 0xcd) = 0xc;
          *(undefined4 *)(lVar14 + 0x79) = 1;
          *(undefined2 *)(lVar14 + 0x83) = 0x10;
          *(undefined4 *)(lVar14 + 0x85) = uVar13;
          *(undefined4 *)(lVar14 + 0x95) = uVar13;
          *(undefined4 *)(lVar14 + 0xa1) = 1;
          *(uint *)(lVar14 + 0x71) = uVar10 / 1000;
          *(undefined2 *)(lVar14 + 0xab) = 0x10;
          *(undefined4 *)(lVar14 + 0xad) = uVar13;
          *(undefined4 *)(lVar14 + 0x91) = 0xc0000006;
          *(undefined4 *)(lVar14 + 0xb9) = 0xc0000008;
          *(undefined4 *)(lVar14 + 0xbd) = uVar13;
          *(undefined4 *)(lVar14 + 0xc9) = 1;
          *(undefined2 *)(lVar14 + 0xd3) = 0x10;
          *(undefined4 *)(lVar14 + 0xd5) = uVar13;
          *(undefined4 *)(lVar14 + 0xe1) = 0xc0000007;
          *(undefined4 *)(lVar14 + 0xe5) = uVar13;
          *(undefined4 *)(lVar14 + 0x100) = 0;
          __init_swait_queue_head(lVar14 + 0x108,"&x->wait",&init_completion___key);
          *(undefined4 *)(lVar14 + 0xfc) = 0xfa;
          plVar29[0xf2] = lVar14;
        }
      }
      lVar14 = of_find_property(uVar37,"qcom,panic-genspeed-mismatch",0);
      *(bool *)((long)plVar29 + 0x889) = lVar14 != 0;
      lVar14 = of_find_property(uVar37,"qcom,ecam-mode",0);
      *(bool *)((long)plVar29 + 0xdaa) = lVar14 != 0;
      if (plVar29 != (long *)0x0) {
        puVar20 = &DAT_00125a9d;
        if (lVar14 == 0) {
          puVar20 = &DAT_0012b06d;
        }
        ipc_log_string(plVar29[0xe5],"DBG1:%s: RC%d: ecam mode:%s\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],puVar20);
        puVar20 = &DAT_0012b06d;
        if (*(char *)((long)plVar29 + 0xdaa) != '\0') {
          puVar20 = &DAT_00125a9d;
        }
        ipc_log_string(plVar29[0xe4],"%s: RC%d: ecam mode:%s\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],puVar20);
      }
      *(undefined4 *)((long)plVar29 + 0xdac) = 0;
      iVar11 = of_property_read_variable_u32_array
                         (uVar37,"qcom,tc2bdf-tc-count",(long)plVar29 + 0xdac,1,0);
      if ((plVar29 != (long *)0x0) && (-1 < iVar11)) {
        ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: tc2bdf_tc_count: %d\n","msm_pcie_read_dt"
                       ,(int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0xdac));
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: tc2bdf_tc_count: %d\n","msm_pcie_read_dt",
                       (int)plVar29[0xae],*(undefined4 *)((long)plVar29 + 0xdac));
      }
      memcpy(plVar29 + 4,msm_pcie_vreg_info,0xc0);
      lVar16 = _DAT_0011f9a8;
      lVar23 = _DAT_0011f9a0;
      lVar14 = _DAT_0011f998;
      plVar29[0x28] = (long)PTR_s_card_presence_pin_0011f990;
      plVar29[0x29] = lVar14;
      lVar14 = _DAT_0011f978;
      puVar20 = PTR_s_qcom_ep_gpio_0011f970;
      plVar29[0x2a] = lVar23;
      plVar29[0x2b] = lVar16;
      lVar16 = _DAT_0011f988;
      lVar23 = _DAT_0011f980;
      plVar29[0x24] = (long)puVar20;
      plVar29[0x25] = lVar14;
      lVar14 = _DAT_0011f958;
      puVar20 = PTR_s_wake_gpio_0011f950;
      plVar29[0x26] = lVar23;
      plVar29[0x27] = lVar16;
      lVar16 = _DAT_0011f968;
      lVar23 = _DAT_0011f960;
      plVar29[0x20] = (long)puVar20;
      plVar29[0x21] = lVar14;
      lVar14 = DAT_0011f938;
      puVar20 = msm_pcie_gpio_info;
      plVar29[0x22] = lVar23;
      plVar29[0x23] = lVar16;
      lVar16 = DAT_0011f948;
      lVar23 = DAT_0011f940;
      plVar29[0x1c] = (long)puVar20;
      plVar29[0x1d] = lVar14;
      plVar29[0x1e] = lVar23;
      plVar29[0x1f] = lVar16;
      memcpy(plVar29 + 0x2c,&msm_pcie_res_info,0xf0);
      lVar23 = _DAT_0011f9f8;
      puVar7 = PTR_s_int_global_int_0011f9f0;
      lVar14 = _DAT_0011f9e8;
      plVar29[0x50] = (long)PTR_s_int_d_0011f9e0;
      plVar29[0x51] = lVar14;
      lVar14 = _DAT_0011f9c8;
      puVar20 = PTR_s_int_b_0011f9c0;
      plVar29[0x52] = (long)puVar7;
      plVar29[0x53] = lVar23;
      lVar23 = _DAT_0011f9d8;
      puVar7 = PTR_s_int_c_0011f9d0;
      plVar29[0x4c] = (long)puVar20;
      plVar29[0x4d] = lVar14;
      lVar14 = DAT_0011f9b8;
      puVar20 = msm_pcie_irq_info;
      plVar29[0x4e] = (long)puVar7;
      plVar29[0x4f] = lVar23;
      plVar29[0x4a] = (long)puVar20;
      plVar29[0x4b] = lVar14;
      if (5 < local_c8) {
LAB_001183f8:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x1183fc);
        (*pcVar8)();
      }
      lVar5 = (ulong)local_c8 * 0x78;
      lVar14 = *(long *)(msm_pcie_reset_info + lVar5 + 0x10);
      lVar23 = *(long *)(msm_pcie_reset_info + lVar5);
      plVar29[0x55] = *(long *)(msm_pcie_reset_info + lVar5 + 8);
      plVar29[0x56] = lVar14;
      plVar29[0x54] = lVar23;
      lVar23 = *(long *)(msm_pcie_reset_info + lVar5 + 0x30);
      lVar14 = *(long *)(msm_pcie_reset_info + lVar5 + 0x18);
      lVar16 = *(long *)(msm_pcie_reset_info + lVar5 + 0x20);
      plVar29[0x59] = *(long *)(msm_pcie_reset_info + lVar5 + 0x28);
      plVar29[0x5a] = lVar23;
      plVar29[0x57] = lVar14;
      plVar29[0x58] = lVar16;
      lVar23 = *(long *)(msm_pcie_reset_info + lVar5 + 0x50);
      lVar14 = *(long *)(msm_pcie_reset_info + lVar5 + 0x38);
      lVar16 = *(long *)(msm_pcie_reset_info + lVar5 + 0x40);
      plVar29[0x5d] = *(long *)(msm_pcie_reset_info + lVar5 + 0x48);
      plVar29[0x5e] = lVar23;
      plVar29[0x5b] = lVar14;
      plVar29[0x5c] = lVar16;
      lVar23 = *(long *)(msm_pcie_reset_info + lVar5 + 0x70);
      lVar6 = (ulong)local_c8 * 0x18;
      lVar14 = *(long *)(msm_pcie_reset_info + lVar5 + 0x58);
      lVar16 = *(long *)(msm_pcie_reset_info + lVar5 + 0x60);
      plVar29[0x61] = *(long *)(msm_pcie_reset_info + lVar5 + 0x68);
      plVar29[0x62] = lVar23;
      plVar29[0x5f] = lVar14;
      plVar29[0x60] = lVar16;
      lVar14 = *(long *)(msm_pcie_pipe_reset_info + lVar6 + 0x10);
      lVar5 = (ulong)local_c8 * 0x30;
      lVar23 = *(long *)(msm_pcie_pipe_reset_info + lVar6);
      plVar29[100] = *(long *)(msm_pcie_pipe_reset_info + lVar6 + 8);
      plVar29[0x65] = lVar14;
      plVar29[99] = lVar23;
      lVar14 = *(long *)(msm_pcie_linkdown_reset_info + lVar5 + 8);
      plVar29[0x66] = *(long *)(msm_pcie_linkdown_reset_info + lVar5);
      plVar29[0x67] = lVar14;
      lVar14 = *(long *)(msm_pcie_linkdown_reset_info + lVar5 + 0x20);
      lVar16 = *(long *)(msm_pcie_linkdown_reset_info + lVar5 + 0x28);
      lVar23 = *(long *)(msm_pcie_linkdown_reset_info + lVar5 + 0x10);
      lVar5 = *(long *)(msm_pcie_linkdown_reset_info + lVar5 + 0x18);
      *(undefined4 *)(plVar29 + 0x10c) = 0;
      plVar29[0x6a] = lVar14;
      plVar29[0x6b] = lVar16;
      plVar29[0x68] = lVar23;
      plVar29[0x69] = lVar5;
      __init_swait_queue_head(plVar29 + 0x10d,"&x->wait",&init_completion___key);
      plVar29[0x1b6] = 0;
      *(long **)(param_1 + 0xa8) = plVar29;
      lVar14 = *plVar29;
      local_c4 = 0;
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = 0;
      uStack_a8 = 0;
      local_c0._0_4_ = 0;
      local_c0._4_4_ = 0;
      uStack_b8 = 0;
      uStack_b1 = 0;
      iVar11 = __of_parse_phandle_with_args
                         (*(undefined8 *)(lVar14 + 0x2f8),"pcie-i2c-phandle",0,0,0,&local_c0);
      if ((iVar11 == 0) && (CONCAT44(local_c0._4_4_,(int)local_c0) != 0)) {
        lVar23 = of_find_i2c_device_by_node();
        if (lVar23 == 0) {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: No i2c probe yet\n",
                           "msm_pcie_i2c_ctrl_init",(int)plVar29[0xae]);
            ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: No i2c probe yet\n",
                           "msm_pcie_i2c_ctrl_init",(int)plVar29[0xae]);
          }
          uVar36 = 0xfffffdfb;
          goto LAB_00117b6c;
        }
        plVar29[0x1a6] = lVar23;
        plVar29[0x1b0] = (long)ntn3_i2c_read;
        plVar29[0x1b1] = (long)ntn3_i2c_write;
        plVar29[0x1b2] = (long)ntn3_ep_reset_ctrl;
        plVar29[0x1b3] = (long)ntn3_dump_regs;
        plVar29[0x1b4] = (long)ntn3_de_emphasis_wa;
        lVar23 = *(long *)(lVar23 + 0x308);
        if (lVar23 == 0) {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(plVar29[0xe5],"ERR:%s: PCIe: RC%d: No i2c slave node phandle found\n",
                           "msm_pcie_i2c_ctrl_init",(int)plVar29[0xae]);
            ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: No i2c slave node phandle found\n",
                           "msm_pcie_i2c_ctrl_init",(int)plVar29[0xae]);
          }
          _printk(&DAT_0012d765,"msm_pcie_i2c_ctrl_init",(int)*plVar30);
          lVar14 = *plVar29;
joined_r0x0011592c:
          if (plVar29 != (long *)0x0) goto LAB_00115974;
          goto LAB_001159ac;
        }
        lVar14 = lVar14 + 0x10;
        of_property_read_variable_u32_array(lVar23,"gpio-config-reg",plVar29 + 0x1a7,1,0);
        of_property_read_variable_u32_array(lVar23,"ep-reset-reg",(long)plVar29 + 0xd3c,1,0);
        of_property_read_variable_u32_array(lVar23,"ep-reset-gpio-mask",plVar29 + 0x1a8,1,0);
        of_property_read_variable_u32_array(lVar23,"version-reg",(long)plVar29 + 0xd64,1,0);
        lVar16 = of_find_property(lVar23,"force-i2c-setting",0);
        *(bool *)(plVar29 + 0x1ad) = lVar16 != 0;
        lVar16 = of_find_property(lVar23,"ep_reset_postlinkup",0);
        *(bool *)((long)plVar29 + 0xd69) = lVar16 != 0;
        of_get_property(lVar23,"dump-regs",&local_c4);
        if (local_c4 == 0) {
LAB_00115868:
          of_get_property(lVar23,"reg_update",&local_c4);
          if (local_c4 != 0) {
            lVar16 = devm_kmalloc(lVar14,(long)local_c4,0xdc0);
            plVar29[0x1ab] = lVar16;
            if (lVar16 == 0) goto LAB_00117b68;
            *(int *)(plVar29 + 0x1ac) = local_c4 >> 3;
            iVar11 = of_property_read_variable_u32_array
                               (lVar23,"reg_update",lVar16,(ulong)(long)local_c4 >> 2,0);
            if (iVar11 < 0) {
              *(undefined4 *)(plVar29 + 0x1ac) = 0;
            }
          }
          of_get_property(lVar23,"switch_reg_update",&local_c4);
          if (local_c4 != 0) {
            lVar14 = devm_kmalloc(lVar14,(long)local_c4,0xdc0);
            plVar29[0x1ae] = lVar14;
            if (lVar14 == 0) goto LAB_00117b68;
            *(int *)(plVar29 + 0x1af) = local_c4 >> 3;
            iVar11 = of_property_read_variable_u32_array
                               (lVar23,"switch_reg_update",lVar14,(ulong)(long)local_c4 >> 2,0);
            if (iVar11 < 0) {
              *(undefined4 *)(plVar29 + 0x1af) = 0;
            }
          }
          lVar14 = *plVar29;
          goto joined_r0x0011592c;
        }
        lVar16 = devm_kmalloc(lVar14,(long)local_c4,0xdc0);
        plVar29[0x1a9] = lVar16;
        if (lVar16 != 0) {
          *(int *)(plVar29 + 0x1aa) = local_c4 >> 2;
          iVar11 = of_property_read_variable_u32_array(lVar23,"dump-regs",lVar16,local_c4 >> 2,0);
          if (iVar11 < 0) {
            *(undefined4 *)(plVar29 + 0x1aa) = 0;
          }
          goto LAB_00115868;
        }
        goto LAB_00117b68;
      }
      if (plVar29 == (long *)0x0) {
LAB_001183f4:
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(1,0x1183f8);
        (*pcVar8)();
      }
      ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: No i2c phandle found\n",
                     "msm_pcie_i2c_ctrl_init",(int)plVar29[0xae]);
      ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: No i2c phandle found\n","msm_pcie_i2c_ctrl_init"
                     ,(int)plVar29[0xae]);
      lVar14 = *plVar29;
LAB_00115974:
      ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: entry\n","msm_pcie_get_resources",
                     (int)plVar29[0xae]);
      ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: entry\n","msm_pcie_get_resources",
                     (int)plVar29[0xae]);
LAB_001159ac:
      puVar34 = (ulong *)(plVar29 + 99);
      lVar23 = 0;
      plVar2 = plVar29 + 0xe5;
      plVar3 = plVar29 + 0xe4;
      do {
        plVar17 = (long *)platform_get_resource_byname
                                    (*plVar29,0x200,*(undefined8 *)((long)plVar29 + lVar23 + 0x160))
        ;
        if (plVar17 == (long *)0x0) {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: no %s resource found.\n","msm_pcie_get_reg",
                           (int)*plVar30,*(undefined8 *)((long)plVar29 + lVar23 + 0x160));
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: no %s resource found.\n","msm_pcie_get_reg",
                           (int)*plVar30,*(undefined8 *)((long)plVar29 + lVar23 + 0x160));
          }
          _printk(&DAT_00125305,"msm_pcie_get_reg",(int)*plVar30,
                  *(undefined8 *)((long)plVar29 + lVar23 + 0x160));
        }
        else {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: start addr for %s is %pa.\n","msm_pcie_get_reg",
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x160),plVar17);
            ipc_log_string(*plVar3,"%s: start addr for %s is %pa.\n","msm_pcie_get_reg",
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x160),plVar17);
          }
          lVar16 = devm_ioremap(*plVar29 + 0x10,*plVar17,(plVar17[1] - *plVar17) + 1);
          *(long *)((long)plVar29 + lVar23 + 0x170) = lVar16;
          if (lVar16 == 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: can\'t remap %s.\n","msm_pcie_get_reg",
                             (int)*plVar30,*(undefined8 *)((long)plVar29 + lVar23 + 0x160));
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: can\'t remap %s.\n","msm_pcie_get_reg",
                             (int)*plVar30,*(undefined8 *)((long)plVar29 + lVar23 + 0x160));
            }
            _printk(&DAT_001220c6,"msm_pcie_get_reg",(int)*plVar30,
                    *(undefined8 *)((long)plVar29 + lVar23 + 0x160));
            goto LAB_00117b68;
          }
          *(long **)((long)plVar29 + lVar23 + 0x168) = plVar17;
        }
        lVar23 = lVar23 + 0x18;
      } while (lVar23 != 0xf0);
      plVar29[0x70] = plVar29[0x2e];
      plVar29[0x71] = plVar29[0x31];
      plVar29[0x72] = plVar29[0x37];
      plVar29[0x73] = plVar29[0x3a];
      plVar29[0x74] = plVar29[0x34];
      plVar29[0x75] = plVar29[0x3d];
      plVar29[0x1a0] = plVar29[0x40];
      plVar29[0x76] = plVar29[0x43];
      plVar29[0x77] = plVar29[0x46];
      plVar29[0x78] = plVar29[0x49];
      if ((*(char *)((long)plVar29 + 0xdaa) != '\0') &&
         (puVar22 = (uint *)plVar29[0x33], (*puVar22 & 0xfffffff) != 0)) {
        if (plVar29 != (long *)0x0) {
          ipc_log_string(plVar29[0xe5],
                         "ERR:%s: PCIE: RC%d: Unaligned DBI address(%pa) for ECAM mode\n",
                         "msm_pcie_get_reg",(int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: PCIE: RC%d: Unaligned DBI address(%pa) for ECAM mode\n",
                         "msm_pcie_get_reg",(int)plVar29[0xae],plVar29[0x33]);
          puVar22 = (uint *)plVar29[0x33];
        }
        _printk(&DAT_0012fd23,"msm_pcie_get_reg",(int)*plVar30,puVar22);
        uVar36 = 0xffffffea;
        goto LAB_00117b6c;
      }
      uVar36 = of_icc_get(lVar14 + 0x10,"icc_path");
      plVar29[0x9a] = uVar36;
      if (0xfffffffffffff000 < uVar36) {
        uVar36 = uVar36 & 0xffffffff;
        if (plVar29 != (long *)0x0) {
          ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: failed to get ICC path: %d\n",
                         "msm_pcie_get_resources",(int)*plVar30,uVar36);
          ipc_log_string(*plVar3,"%s: PCIe: RC%d: failed to get ICC path: %d\n",
                         "msm_pcie_get_resources",(int)*plVar30,uVar36);
        }
        _printk(&DAT_00128155,"msm_pcie_get_resources",(int)plVar29[0xae],uVar36);
        if (plVar29[0x78] != 0) goto LAB_00115b6c;
        goto LAB_001172b4;
      }
LAB_00115b6c:
      lVar23 = 0;
      do {
        iVar11 = platform_get_irq_byname(lVar14,*(undefined8 *)((long)plVar29 + lVar23 + 0x250));
        if (iVar11 < 0) {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: can\'t find IRQ # for %s. ret %d\n",
                           "msm_pcie_get_resources",(int)*plVar30,
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x250),iVar11);
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: can\'t find IRQ # for %s. ret %d\n",
                           "msm_pcie_get_resources",(int)*plVar30,
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x250),iVar11);
          }
        }
        else {
          *(int *)((long)plVar29 + lVar23 + 600) = iVar11;
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: IRQ # for %s is %d.\n","msm_pcie_get_resources",
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x250),iVar11);
            ipc_log_string(*plVar3,"%s: IRQ # for %s is %d.\n","msm_pcie_get_resources",
                           *(undefined8 *)((long)plVar29 + lVar23 + 0x250),
                           *(undefined4 *)((long)plVar29 + lVar23 + 600));
          }
        }
        lVar23 = lVar23 + 0x10;
      } while (lVar23 != 0x50);
      local_c0._0_4_ = 0;
      of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,tcsr",&local_c0);
      if ((int)local_c0 == 0) {
        if (plVar29 != (long *)0x0) {
          ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: tcsr is not present in DT\n",
                         "msm_pcie_get_tcsr_values",(int)*plVar30);
          ipc_log_string(*plVar3,"%s: PCIe: RC%d: tcsr is not present in DT\n",
                         "msm_pcie_get_tcsr_values",(int)*plVar30);
        }
      }
      else {
        lVar23 = devm_kmalloc(lVar14 + 0x10,(long)(int)local_c0,0xdc0);
        plVar29[0xdd] = lVar23;
        if (lVar23 == 0) goto LAB_00117b68;
        *(int *)(plVar29 + 0xdc) = (int)local_c0 >> 3;
        of_property_read_variable_u32_array
                  (*(undefined8 *)(lVar14 + 0x2f8),"qcom,tcsr",lVar23,
                   (ulong)(long)(int)local_c0 >> 2,0);
      }
      lVar23 = *plVar29;
      local_c0._0_4_ = 0;
      local_c0._4_4_ = 0;
      lVar14 = lVar23 + 0x10;
      uVar10 = devm_clk_bulk_get_all(lVar14,&local_c0);
      uVar36 = (ulong)uVar10;
      if ((int)uVar10 < 1) {
        if (plVar29 != (long *)0x0) {
          ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: failed to get clocks: ret: %d\n",
                         "msm_pcie_get_clk",(int)*plVar30,uVar36);
          ipc_log_string(*plVar3,"%s: PCIe: RC%d: failed to get clocks: ret: %d\n",
                         "msm_pcie_get_clk",(int)*plVar30,uVar36);
        }
        uVar13 = (undefined4)*plVar30;
        puVar20 = &DAT_0012e02a;
LAB_00117180:
        _printk(puVar20,"msm_pcie_get_clk",uVar13,uVar36);
        uVar36 = 0xfffffffb;
      }
      else {
        uVar12 = of_property_count_elems_of_size
                           (*(undefined8 *)(lVar23 + 0x2f8),"clock-frequency",4);
        if (uVar12 == uVar10) {
          puVar18 = (undefined4 *)devm_kmalloc(lVar14,uVar36 << 2,0xdc0);
          if (puVar18 == (undefined4 *)0x0) goto LAB_00117b68;
          uVar12 = of_property_read_variable_u32_array
                             (*(undefined8 *)(lVar23 + 0x2f8),"clock-frequency",puVar18,uVar36,0);
          if ((int)uVar12 < 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,
                             "ERR:%s: PCIe: RC%d: failed to get clock frequencies: ret: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,uVar12);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: failed to get clock frequencies: ret: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,uVar12);
            }
            uVar13 = (undefined4)*plVar30;
            puVar20 = &DAT_001220e9;
LAB_00117174:
            uVar36 = (ulong)uVar12;
            goto LAB_00117180;
          }
          uVar12 = of_property_count_elems_of_size
                             (*(undefined8 *)(lVar23 + 0x2f8),"clock-suppressible",4);
          if (uVar12 != uVar10) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,
                             "ERR:%s: PCIe: RC%d: mismatch between number of clock and suppressible entries: %d != %d\n"
                             ,"msm_pcie_get_clk",(int)*plVar30,uVar36,uVar12);
              ipc_log_string(*plVar3,
                             "%s: PCIe: RC%d: mismatch between number of clock and suppressible entries: %d != %d\n"
                             ,"msm_pcie_get_clk",(int)*plVar30,uVar36,uVar12);
            }
            uVar13 = (undefined4)*plVar30;
            puVar20 = &DAT_0012b991;
            goto LAB_00117114;
          }
          piVar19 = (int *)devm_kmalloc(lVar14,uVar36 << 2,0xdc0);
          if (piVar19 == (int *)0x0) goto LAB_00117b68;
          uVar12 = of_property_read_variable_u32_array
                             (*(undefined8 *)(lVar23 + 0x2f8),"clock-suppressible",piVar19,uVar36,0)
          ;
          if ((int)uVar12 < 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,
                             "ERR:%s: PCIe: RC%d: failed to get clock suppressible info: ret: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,uVar12);
              ipc_log_string(*plVar3,
                             "%s: PCIe: RC%d: failed to get clock suppressible info: ret: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,uVar12);
            }
            uVar13 = (undefined4)*plVar30;
            puVar20 = &DAT_0012d817;
            goto LAB_00117174;
          }
          lVar23 = devm_kmalloc(lVar14,uVar36 * 0x18,0xdc0);
          if (lVar23 == 0) goto LAB_00117b68;
          puVar32 = (undefined4 *)(lVar23 + 0x10);
          plVar29[0x6f] = lVar23;
          plVar29[0x6d] = lVar23;
          do {
            uVar15 = *local_c0;
            iVar11 = *piVar19;
            uVar13 = *puVar18;
            *(undefined8 *)(puVar32 + -2) = uVar15;
            uVar25 = local_c0[1];
            *puVar32 = uVar13;
            *(undefined8 *)(puVar32 + -4) = uVar25;
            *(bool *)(puVar32 + 1) = iVar11 != 0;
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: %s: frequency: %d: suppressible: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,uVar15,uVar13,iVar11 != 0);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: %s: frequency: %d: suppressible: %d\n",
                             "msm_pcie_get_clk",(int)*plVar30,*(undefined8 *)(puVar32 + -2),*puVar32
                             ,*(undefined1 *)(puVar32 + 1));
            }
            local_c0 = local_c0 + 2;
            uVar12 = (int)uVar36 - 1;
            uVar36 = (ulong)uVar12;
            puVar32 = puVar32 + 6;
            piVar19 = piVar19 + 1;
            puVar18 = puVar18 + 1;
          } while (uVar12 != 0);
          lVar23 = plVar29[0x6f];
          iVar11 = strcmp(*(char **)(lVar23 + 8),"pcie_pipe_clk");
          if (iVar11 != 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: could not find entry for pcie_pipe_clk\n",
                             "msm_pcie_get_clk",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: could not find entry for pcie_pipe_clk\n",
                             "msm_pcie_get_clk",(int)*plVar30);
            }
            _printk(&DAT_00127b6f,"msm_pcie_get_clk",(int)plVar29[0xae]);
            if (plVar29[0x1a0] != 0) {
              iVar11 = (int)plVar29[0x6c];
              goto LAB_00115ef4;
            }
            goto LAB_001181d8;
          }
          iVar11 = (int)plVar29[0x6c] + 1;
          plVar29[0x6f] = lVar23 + 0x18;
          *(int *)(plVar29 + 0x6c) = iVar11;
LAB_00115ef4:
          *(uint *)(plVar29 + 0x6e) = uVar10 - iVar11;
          uVar36 = clk_get(lVar14,"pcie_rate_change_clk");
          plVar29[0x81] = uVar36;
          if (0xfffffffffffff000 < uVar36) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: pcie_rate_change_clk is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: pcie_rate_change_clk is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
            }
            plVar29[0x81] = 0;
          }
          uVar36 = clk_get(lVar14,"pcie_pipe_clk_mux");
          plVar29[0x82] = uVar36;
          if (0xfffffffffffff000 < uVar36) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: pcie_pipe_clk_mux is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: pcie_pipe_clk_mux is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
            }
            plVar29[0x82] = 0;
          }
          uVar36 = clk_get(lVar14,"pcie_pipe_clk_ext_src");
          plVar29[0x83] = uVar36;
          if (0xfffffffffffff000 < uVar36) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: pcie_pipe_clk_ext_src is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: pcie_pipe_clk_ext_src is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
            }
            plVar29[0x83] = 0;
          }
          uVar28 = clk_get(lVar14,"pcie_phy_aux_clk_mux");
          uVar36 = 0;
          if (uVar28 < 0xfffffffffffff001) {
            uVar36 = uVar28;
          }
          plVar29[0x84] = uVar36;
          uVar28 = clk_get(lVar14,"pcie_phy_aux_clk_ext_src");
          uVar36 = 0;
          if (uVar28 < 0xfffffffffffff001) {
            uVar36 = uVar28;
          }
          plVar29[0x85] = uVar36;
          uVar36 = clk_get(lVar14,"pcie_ref_clk_src");
          plVar29[0x86] = uVar36;
          if (0xfffffffffffff000 < uVar36) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: pcie_ref_clk_src is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: pcie_ref_clk_src is not present\n",
                             "msm_pcie_get_clk",(int)*plVar30);
            }
            plVar29[0x86] = 0;
          }
          uVar36 = clk_get(lVar14,"pcie_cfg_ahb_clk");
          plVar29[0x87] = uVar36;
          if ((0xfffffffffffff000 < uVar36) && (plVar29[0x87] = 0, plVar29 != (long *)0x0)) {
            ipc_log_string(*plVar2,"DBG1:%s: Clock ahb isn\'t available\n","msm_pcie_get_clk");
            ipc_log_string(*plVar3,"%s: Clock ahb isn\'t available\n","msm_pcie_get_clk");
          }
          puVar35 = (undefined8 *)*plVar29;
          lVar14 = 0;
          puVar24 = puVar35 + 2;
          local_c4 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_c0._0_4_ = 0;
          local_c0._4_4_ = 0;
          uStack_b8 = 0;
          uStack_b1 = 0;
          do {
            uVar36 = devm_regulator_get_optional
                               (puVar24,*(undefined8 *)((long)plVar29 + lVar14 + 0x28));
            puVar33 = (ulong *)((long)plVar29 + lVar14 + 0x20);
            *puVar33 = uVar36;
            if (uVar36 == 0xfffffffffffffdfb) {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: EPROBE_DEFER for VReg:%s\n","msm_pcie_get_vreg",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
                ipc_log_string(*plVar3,"%s: EPROBE_DEFER for VReg:%s\n","msm_pcie_get_vreg",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
                uVar36 = (ulong)*(uint *)((long)plVar29 + lVar14 + 0x20);
                goto LAB_0011631c;
              }
              uVar36 = 0xfffffdfb;
              pcie_drv = pcie_drv + -1;
              goto LAB_00117bc0;
            }
            if (uVar36 < 0xfffffffffffff001) {
              *(int *)((long)plVar29 + 0x3d4) = *(int *)((long)plVar29 + 0x3d4) + 1;
              scnprintf(&local_c0,0x20,"qcom,%s-voltage-level",
                        *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
              puVar22 = (uint *)of_get_property(puVar35[0x5f],&local_c0,&local_c4);
              if ((puVar22 == (uint *)0x0) || (local_c4 != 0xc)) {
                if (plVar29 != (long *)0x0) {
                  pcVar21 = "no";
                  if (puVar22 != (uint *)0x0) {
                    pcVar21 = "invalid format";
                  }
                  ipc_log_string(*plVar2,"DBG1:%s: %s %s property\n","msm_pcie_get_vreg",pcVar21,
                                 &local_c0);
                  ipc_log_string(*plVar3,"%s: %s %s property\n","msm_pcie_get_vreg",pcVar21,
                                 &local_c0);
                }
              }
              else {
                uVar10 = (*puVar22 & 0xff00ff00) >> 8 | (*puVar22 & 0xff00ff) << 8;
                *(uint *)((long)plVar29 + lVar14 + 0x30) = uVar10 >> 0x10 | uVar10 << 0x10;
                uVar10 = (puVar22[1] & 0xff00ff00) >> 8 | (puVar22[1] & 0xff00ff) << 8;
                *(uint *)((long)plVar29 + lVar14 + 0x34) = uVar10 >> 0x10 | uVar10 << 0x10;
                uVar10 = (puVar22[2] & 0xff00ff00) >> 8 | (puVar22[2] & 0xff00ff) << 8;
                *(uint *)((long)plVar29 + lVar14 + 0x38) = uVar10 >> 0x10 | uVar10 << 0x10;
              }
              pcVar21 = *(char **)((long)plVar29 + lVar14 + 0x28);
              iVar11 = strcmp(pcVar21,"vreg-cx");
              if (iVar11 == 0) {
                plVar29[0x7d] = (long)puVar33;
                pcVar21 = *(char **)((long)plVar29 + lVar14 + 0x28);
              }
              iVar11 = strcmp(pcVar21,"vreg-mx");
              if (iVar11 == 0) {
                plVar29[0x7e] = (long)puVar33;
              }
            }
            else {
              if ((*(char *)((long)plVar29 + lVar14 + 0x3c) != '\0') && (plVar29[0x1a0] == 0)) {
                if (plVar29 == (long *)0x0) {
                  uVar36 = uVar36 & 0xffffffff;
                }
                else {
                  ipc_log_string(*plVar2,"DBG1:%s: Vreg %s doesn\'t exist\n","msm_pcie_get_vreg",
                                 *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
                  ipc_log_string(*plVar3,"%s: Vreg %s doesn\'t exist\n","msm_pcie_get_vreg",
                                 *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
                  uVar36 = *(ulong *)((long)plVar29 + lVar14 + 0x20) & 0xffffffff;
                }
                goto LAB_0011631c;
              }
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: Optional Vreg %s doesn\'t exist\n",
                               "msm_pcie_get_vreg",*(undefined8 *)((long)plVar29 + lVar14 + 0x28));
                ipc_log_string(*plVar3,"%s: Optional Vreg %s doesn\'t exist\n","msm_pcie_get_vreg",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0x28));
              }
              *puVar33 = 0;
            }
            lVar14 = lVar14 + 0x20;
          } while (lVar14 != 0xc0);
          uVar36 = devm_regulator_get(puVar24,"gdsc-core-vdd");
          plVar29[2] = uVar36;
          if (uVar36 < 0xfffffffffffff001) {
LAB_00116344:
            uVar36 = devm_regulator_get(puVar24,"gdsc-phy-vdd");
            plVar29[3] = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(plVar29[0xe5],"ERR:%s: PCIe: RC%d: Failed to get %s GDSC-PHY:%ld\n",
                               "msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35);
                ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: Failed to get %s GDSC-PHY:%ld\n",
                               "msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35,plVar29[3]);
                uVar36 = plVar29[3];
              }
              _printk(&DAT_001289fd,"msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35,uVar36);
              uVar10 = 0;
              if (plVar29[3] == -0x205) {
                uVar10 = 0xfffffdfb;
              }
              uVar36 = (ulong)uVar10;
              if ((plVar29 != (long *)0x0) && (plVar29[3] == -0x205)) {
                ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: EPROBE_DEFER for %s GDSC-PHY\n",
                               "msm_pcie_get_vreg",*puVar35);
                ipc_log_string(plVar29[0xe4],"%s: PCIe: EPROBE_DEFER for %s GDSC-PHY\n",
                               "msm_pcie_get_vreg",*puVar35);
                uVar36 = (ulong)*(uint *)(plVar29 + 3);
              }
              goto LAB_0011631c;
            }
          }
          else {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(plVar29[0xe5],"ERR:%s: PCIe: RC%d: Failed to get %s GDSC-CORE:%ld\n",
                             "msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35);
              ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: Failed to get %s GDSC-CORE:%ld\n",
                             "msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35,plVar29[2]);
              uVar36 = plVar29[2];
            }
            _printk(&DAT_0012a891,"msm_pcie_get_vreg",(int)plVar29[0xae],*puVar35,uVar36);
            if ((plVar29 != (long *)0x0) && (plVar29[2] == -0x205)) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: EPROBE_DEFER for %s GDSC-CORE\n",
                             "msm_pcie_get_vreg",*puVar35);
              ipc_log_string(*plVar3,"%s: PCIe: EPROBE_DEFER for %s GDSC-CORE\n","msm_pcie_get_vreg"
                             ,*puVar35);
            }
            if (plVar29[0x1a0] != 0) goto LAB_00116344;
            uVar36 = (ulong)*(uint *)(plVar29 + 2);
LAB_0011631c:
            if ((int)uVar36 != 0) goto LAB_00117b6c;
          }
          lVar14 = 0;
          do {
            uVar36 = __devm_reset_control_get
                               (*plVar29 + 0x10,*(undefined8 *)((long)plVar29 + lVar14 + 0x2a8),0,0,
                                0,1);
            *(ulong *)((long)plVar29 + lVar14 + 0x2a0) = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              if (*(char *)((long)plVar29 + lVar14 + 0x2b0) != '\0') {
                if (plVar29 == (long *)0x0) goto LAB_00116864;
                pcVar31 = "%s: Reset %s isn\'t available:%ld\n";
                plVar17 = (long *)((long)plVar29 + lVar14 + 0x2a8);
                puVar34 = (ulong *)((long)plVar29 + lVar14 + 0x2a0);
                pcVar21 = "DBG1:%s: Reset %s isn\'t available:%ld\n";
                goto LAB_00116828;
              }
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: Ignoring Reset %s\n","msm_pcie_get_reset",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0x2a8));
                ipc_log_string(*plVar3,"%s: Ignoring Reset %s\n","msm_pcie_get_reset",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0x2a8));
              }
              *(undefined8 *)((long)plVar29 + lVar14 + 0x2a0) = 0;
            }
            lVar14 = lVar14 + 0x18;
          } while (lVar14 != 0x78);
          uVar36 = __devm_reset_control_get(*plVar29 + 0x10,plVar29[100],0,0,0,1);
          plVar29[99] = uVar36;
          if (uVar36 < 0xfffffffffffff001) {
LAB_0011657c:
            uVar36 = __devm_reset_control_get(*plVar29 + 0x10,plVar29[0x67],0,0,0,1);
            plVar29[0x66] = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              plVar17 = plVar29 + 0x67;
              puVar34 = (ulong *)(plVar29 + 0x66);
              if ((char)plVar29[0x68] == '\0') {
                if (plVar29 != (long *)0x0) {
                  ipc_log_string(*plVar2,"DBG1:%s: Ignoring Linkdown Reset %s\n",
                                 "msm_pcie_get_reset",*plVar17);
                  ipc_log_string(*plVar3,"%s: Ignoring Linkdown Reset %s\n","msm_pcie_get_reset",
                                 *plVar17);
                }
                plVar29[0x66] = 0;
                goto LAB_001167d4;
              }
joined_r0x001165bc:
              if (plVar29 != (long *)0x0) {
                pcVar31 = "%s: Linkdown Reset %s isn\'t available:%ld\n";
                pcVar21 = "DBG1:%s: Linkdown Reset %s isn\'t available:%ld\n";
                goto LAB_00116828;
              }
              goto LAB_00116864;
            }
LAB_001167d4:
            uVar36 = __devm_reset_control_get(*plVar29 + 0x10,plVar29[0x6a],0,0,0,1);
            plVar29[0x69] = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              puVar34 = (ulong *)(plVar29 + 0x69);
              plVar17 = plVar29 + 0x6a;
              if ((char)plVar29[0x6b] != '\0') goto joined_r0x001165bc;
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: Ignoring Linkdown Reset %s\n","msm_pcie_get_reset",
                               *plVar17);
                ipc_log_string(*plVar3,"%s: Ignoring Linkdown Reset %s\n","msm_pcie_get_reset",
                               *plVar17);
              }
              *puVar34 = 0;
            }
          }
          else {
            plVar17 = plVar29 + 100;
            if ((char)plVar29[0x65] == '\0') {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: Ignoring Pipe Reset %s\n","msm_pcie_get_reset",
                               *plVar17);
                ipc_log_string(*plVar3,"%s: Ignoring Pipe Reset %s\n","msm_pcie_get_reset",*plVar17)
                ;
              }
              *puVar34 = 0;
              goto LAB_0011657c;
            }
            if (plVar29 != (long *)0x0) {
              pcVar31 = "%s: Pipe Reset %s isn\'t available:%ld\n";
              pcVar21 = "DBG1:%s: Pipe Reset %s isn\'t available:%ld\n";
LAB_00116828:
              ipc_log_string(*plVar2,pcVar21,"msm_pcie_get_reset",*plVar17,uVar36);
              ipc_log_string(*plVar3,pcVar31,"msm_pcie_get_reset",*plVar17,*puVar34);
              uVar36 = *puVar34;
            }
LAB_00116864:
            if ((int)uVar36 != 0) goto LAB_00117b6c;
          }
          local_c0._0_4_ = 0;
          lVar14 = *plVar29;
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,bw-scale",&local_c0);
          if ((int)local_c0 == 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: RC%d: bandwidth scaling is not supported\n",
                             "msm_pcie_get_bw_scale",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: RC%d: bandwidth scaling is not supported\n",
                             "msm_pcie_get_bw_scale",(int)*plVar30);
            }
          }
          else {
            lVar23 = devm_kmalloc(lVar14 + 0x10,(long)(int)local_c0,0xdc0);
            plVar29[0x7f] = lVar23;
            if (lVar23 == 0) goto LAB_00117b68;
            of_property_read_variable_u32_array
                      (*(undefined8 *)(lVar14 + 0x2f8),"qcom,bw-scale",lVar23,
                       (ulong)(long)(int)local_c0 >> 2,0);
            *(int *)(plVar29 + 0x80) = (int)((ulong)(long)(int)local_c0 / 0xc);
          }
          local_c0._0_4_ = 0;
          lVar14 = *plVar29;
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,phy-sequence",&local_c0);
          if ((int)local_c0 == 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: phy sequence is not present in DT\n",
                             "msm_pcie_get_phy",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: phy sequence is not present in DT\n",
                             "msm_pcie_get_phy",(int)*plVar30);
            }
          }
          else {
            lVar23 = devm_kmalloc(lVar14 + 0x10,(long)(int)local_c0,0xdc0);
            plVar29[0xdb] = lVar23;
            if (lVar23 == 0) goto LAB_00117b68;
            *(int *)((long)plVar29 + 0x6d4) = (int)((ulong)(long)(int)local_c0 / 0xc);
            iVar11 = of_property_read_variable_u32_array
                               (*(undefined8 *)(lVar14 + 0x2f8),"qcom,phy-sequence",lVar23,
                                (ulong)(long)(int)local_c0 >> 2,0);
            if (iVar11 < 0) {
              uVar36 = 0xffffffea;
              goto LAB_00117b6c;
            }
          }
          lVar14 = *plVar29;
          local_c0._0_4_ = 0;
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"iommu-map",&local_c0);
          uVar36 = (ulong)(int)local_c0;
          if ((int)local_c0 != 0) {
            lVar23 = __kmalloc(uVar36,0xdc0);
            if (lVar23 != 0) {
              of_property_read_variable_u32_array
                        (*(undefined8 *)(lVar14 + 0x2f8),"iommu-map",lVar23,
                         (ulong)(long)(int)local_c0 >> 2,0);
              *(int *)(plVar29 + 0xde) = (int)local_c0 >> 4;
              lVar14 = devm_kmalloc(lVar14 + 0x10,(ulong)(uint)((int)local_c0 >> 4) << 4,0xdc0);
              plVar29[0xdf] = lVar14;
              if (lVar14 != 0) {
                if ((int)plVar29[0xde] != 0) {
                  uVar28 = 0;
                  do {
                    iVar11 = (int)uVar28;
                    if (((iVar11 < 0) ||
                        (uVar28 = -(uVar28 >> 0x1f) & 0xfffffff000000000 | uVar28 << 4,
                        uVar36 < uVar28)) || (uVar36 - uVar28 < 4)) goto LAB_001183f4;
                    uVar26 = (ulong)iVar11;
                    uVar27 = uVar26 * 0x10;
                    if ((uVar36 < uVar27) || (uVar36 + uVar26 * -0x10 < 4)) goto LAB_001183f4;
                    *(short *)(plVar29[0xdf] + uVar27) = (short)*(undefined4 *)(lVar23 + uVar27);
                    if (((((long)uVar28 < 0) ||
                         ((uVar36 < (uVar28 | 8) || (uVar36 - (uVar28 | 8) < 4)))) ||
                        (uVar28 = uVar26 << 4 | 8, (uVar26 & 0xfffffffffffffff) >> 0x3b != 0)) ||
                       ((uVar36 < uVar28 || (uVar36 - uVar28 < 4)))) goto LAB_001183f4;
                    uVar28 = (ulong)(iVar11 + 1U);
                    *(undefined4 *)(plVar29[0xdf] + uVar27 + 8) =
                         *(undefined4 *)(lVar23 + uVar27 + 8);
                    *(char *)(plVar29[0xdf] + uVar27 + 2) =
                         (char)*(undefined4 *)(plVar29[0xdf] + uVar27 + 8) -
                         (char)*(undefined4 *)((long)plVar29 + 0x4ec);
                  } while (iVar11 + 1U < *(uint *)(plVar29 + 0xde));
                }
                kfree(lVar23);
                goto LAB_00116b64;
              }
              kfree(lVar23);
            }
            goto LAB_00117b68;
          }
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: iommu-map is not present in DT.\n",
                           "msm_pcie_get_iommu_map",(int)*plVar30);
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: iommu-map is not present in DT.\n",
                           "msm_pcie_get_iommu_map",(int)*plVar30);
          }
LAB_00116b64:
          lVar14 = 0;
          *(undefined4 *)(plVar29 + 0x7b) = 0;
          do {
            uVar28 = of_get_named_gpio_flags
                               (*(undefined8 *)(*plVar29 + 0x2f8),
                                *(undefined8 *)((long)plVar29 + lVar14 + 0xe0),0,0);
            uVar36 = uVar28 & 0xffffffff;
            if ((int)uVar28 < 0) {
              if (*(char *)((long)plVar29 + lVar14 + 0xf8) != '\0') {
                if (plVar29 != (long *)0x0) {
                  ipc_log_string(*plVar2,"ERR:%s: Could not get required GPIO %s\n",
                                 "msm_pcie_get_gpio",*(undefined8 *)((long)plVar29 + lVar14 + 0xe0))
                  ;
                  ipc_log_string(*plVar3,"%s: Could not get required GPIO %s\n","msm_pcie_get_gpio",
                                 *(undefined8 *)((long)plVar29 + lVar14 + 0xe0));
                }
                _printk(&DAT_00128a56,"msm_pcie_get_gpio",
                        *(undefined8 *)((long)plVar29 + lVar14 + 0xe0));
                goto LAB_00117b6c;
              }
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: Could not get optional GPIO %s\n",
                               "msm_pcie_get_gpio",*(undefined8 *)((long)plVar29 + lVar14 + 0xe0));
                ipc_log_string(*plVar3,"%s: Could not get optional GPIO %s\n","msm_pcie_get_gpio",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0xe0));
              }
            }
            else {
              *(int *)((long)plVar29 + lVar14 + 0xe8) = (int)uVar28;
              *(int *)(plVar29 + 0x7b) = (int)plVar29[0x7b] + 1;
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"DBG1:%s: GPIO num for %s is %d\n","msm_pcie_get_gpio",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0xe0),uVar28 & 0xffffffff);
                ipc_log_string(*plVar3,"%s: GPIO num for %s is %d\n","msm_pcie_get_gpio",
                               *(undefined8 *)((long)plVar29 + lVar14 + 0xe0),
                               *(undefined4 *)((long)plVar29 + lVar14 + 0xe8));
              }
            }
            lVar14 = lVar14 + 0x20;
          } while (lVar14 != 0x80);
          *(undefined4 *)(plVar29 + 0x7a) = 0;
          if ((int)plVar29[0x21] != 0) {
            gpio_to_desc();
            uVar13 = gpiod_to_irq();
            *(undefined4 *)(plVar29 + 0x7a) = uVar13;
          }
          local_c0._0_4_ = 0;
          lVar14 = *plVar29;
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: Enter\n","msm_pcie_get_parf_status_reg",
                           (int)*plVar30);
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: Enter\n","msm_pcie_get_parf_status_reg",
                           (int)*plVar30);
          }
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,parf-debug-reg",&local_c0);
          if ((int)local_c0 == 0) {
            if (plVar29 == (long *)0x0) {
              puVar24 = (undefined8 *)&DAT_00000ce0;
              goto LAB_00118414;
            }
            ipc_log_string(plVar29[0xe5],
                           "DBG1:%s: PCIe: RC%d: parf debug registers not present in DT\n",
                           "msm_pcie_get_parf_status_reg",(int)plVar29[0xae]);
            ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: parf debug registers not present in DT\n",
                           "msm_pcie_get_parf_status_reg",(int)plVar29[0xae]);
            plVar29[0x19c] = 0;
          }
          else {
            lVar23 = __kmalloc((long)(int)local_c0,0xcc0);
            plVar29[0x19c] = lVar23;
            if (lVar23 == 0) goto LAB_00117b68;
            *(int *)(plVar29 + 0x19b) = (int)local_c0 >> 2;
            iVar11 = of_property_read_variable_u32_array
                               (*(undefined8 *)(lVar14 + 0x2f8),"qcom,parf-debug-reg",lVar23,
                                (ulong)(long)(int)local_c0 >> 2,0);
            if (iVar11 < 0) {
              kfree(plVar29[0x19c]);
              uVar36 = 0xffffffea;
              plVar29[0x19c] = 0;
              goto LAB_00117b6c;
            }
            if (plVar29 == (long *)0x0) goto LAB_00118400;
            ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: no of parf dbg regs:%u size:%u\n",
                           "msm_pcie_get_parf_status_reg",(int)*plVar30,
                           (ulong)(long)(int)local_c0 >> 2);
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: no of parf dbg regs:%u size:%u\n",
                           "msm_pcie_get_parf_status_reg",(int)*plVar30,
                           (ulong)(long)(int)local_c0 >> 2);
          }
          local_c0._0_4_ = 0;
          lVar14 = *plVar29;
          ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: Enter\n","msm_pcie_get_dbi_status_reg",
                         (int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: Enter\n","msm_pcie_get_dbi_status_reg",
                         (int)plVar29[0xae]);
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,dbi-debug-reg",&local_c0);
          if ((int)local_c0 == 0) {
            if (plVar29 == (long *)0x0) {
              puVar24 = (undefined8 *)&DAT_00000cf0;
LAB_00118414:
              *puVar24 = 0;
              local_c0._0_4_ = 0;
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(1,0x118420);
              (*pcVar8)();
            }
            ipc_log_string(plVar29[0xe5],
                           "DBG1:%s: PCIe: RC%d: dbi debug registers not present in DT\n",
                           "msm_pcie_get_dbi_status_reg",(int)plVar29[0xae]);
            ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: dbi debug registers not present in DT\n",
                           "msm_pcie_get_dbi_status_reg",(int)plVar29[0xae]);
            plVar29[0x19e] = 0;
          }
          else {
            lVar23 = __kmalloc((long)(int)local_c0,0xcc0);
            plVar29[0x19e] = lVar23;
            if (lVar23 == 0) goto LAB_00117b68;
            *(int *)(plVar29 + 0x19d) = (int)local_c0 >> 2;
            iVar11 = of_property_read_variable_u32_array
                               (*(undefined8 *)(lVar14 + 0x2f8),"qcom,dbi-debug-reg",lVar23,
                                (ulong)(long)(int)local_c0 >> 2,0);
            if (iVar11 < 0) {
              kfree(plVar29[0x19e]);
              uVar36 = 0xffffffea;
              plVar29[0x19e] = 0;
              goto LAB_00117b6c;
            }
            if (plVar29 == (long *)0x0) {
LAB_00118400:
              local_c0._0_4_ = 0;
                    /* WARNING: Does not return */
              pcVar8 = (code *)SoftwareBreakpoint(1,0x118408);
              (*pcVar8)();
            }
            ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: no of dbi dbg regs:%u size:%u\n",
                           "msm_pcie_get_dbi_status_reg",(int)*plVar30,
                           (ulong)(long)(int)local_c0 >> 2);
            ipc_log_string(*plVar3,"%s: PCIe: RC%d: no of dbi dbg regs:%u size:%u\n",
                           "msm_pcie_get_dbi_status_reg",(int)*plVar30,
                           (ulong)(long)(int)local_c0 >> 2);
          }
          local_c0._0_4_ = 0;
          lVar14 = *plVar29;
          ipc_log_string(plVar29[0xe5],"DBG1:%s: PCIe: RC%d: Enter\n","msm_pcie_get_phy_status_reg",
                         (int)plVar29[0xae]);
          ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: Enter\n","msm_pcie_get_phy_status_reg",
                         (int)plVar29[0xae]);
          of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,phy-debug-reg",&local_c0);
          if ((int)local_c0 == 0) {
            if (plVar29 == (long *)0x0) {
              uRam0000000000000cd0 = 0;
            }
            else {
              ipc_log_string(plVar29[0xe5],
                             "DBG1:%s: PCIe: RC%d: phy debug registers not present in DT\n",
                             "msm_pcie_get_phy_status_reg",(int)plVar29[0xae]);
              ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: phy debug registers not present in DT\n"
                             ,"msm_pcie_get_phy_status_reg",(int)plVar29[0xae]);
              plVar29[0x19a] = 0;
LAB_00116fe8:
              ipc_log_string(*plVar2,"DBG1:%s: RC%d: exit\n","msm_pcie_get_resources",(int)*plVar30)
              ;
              ipc_log_string(*plVar3,"%s: RC%d: exit\n","msm_pcie_get_resources",(int)*plVar30);
            }
          }
          else {
            lVar23 = __kmalloc((long)(int)local_c0,0xcc0);
            plVar29[0x19a] = lVar23;
            if (lVar23 == 0) {
              uVar36 = 0xfffffff4;
            }
            else {
              *(int *)((long)plVar29 + 0xccc) = (int)local_c0 >> 2;
              iVar11 = of_property_read_variable_u32_array
                                 (*(undefined8 *)(lVar14 + 0x2f8),"qcom,phy-debug-reg",lVar23,
                                  (ulong)(long)(int)local_c0 >> 2,0);
              if (iVar11 < 0) {
                kfree(plVar29[0x19a]);
                uVar36 = 0xffffffea;
                plVar29[0x19a] = 0;
              }
              else {
                if (plVar29 != (long *)0x0) {
                  ipc_log_string(*plVar2,"DBG1:%s: PCIe: RC%d: no of phy dbg regs:%u size:%u\n",
                                 "msm_pcie_get_phy_status_reg",(int)*plVar30,
                                 (ulong)(long)(int)local_c0 >> 2);
                  ipc_log_string(*plVar3,"%s: PCIe: RC%d: no of phy dbg regs:%u size:%u\n",
                                 "msm_pcie_get_phy_status_reg",(int)*plVar30,
                                 (ulong)(long)(int)local_c0 >> 2);
                  goto LAB_00116fe8;
                }
                uVar36 = 0;
              }
            }
LAB_001172b4:
            if ((int)uVar36 != 0) goto LAB_00117b6c;
          }
          if (plVar29[0x78] != 0) {
            plVar29[0x197] = (long)msm_pcie_rumi_init;
          }
          if (plVar29[0x1a0] != 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"DBG1:%s: pcie CESTA is supported\n","msm_pcie_probe");
              ipc_log_string(*plVar3,"%s: pcie CESTA is supported\n","msm_pcie_probe");
            }
            uVar12 = of_property_read_variable_u32_array
                               (uVar37,"qcom,pcie-clkreq-gpio",plVar29 + 0x1a3,1,0);
            uVar10 = uVar12;
            if (-1 < (int)uVar12) {
              uVar10 = 0;
            }
            uVar36 = (ulong)uVar10;
            if ((int)uVar12 < 0) {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"ERR:%s: Couldn\'t find clkreq gpio %d\n",
                               "msm_pcie_cesta_init",uVar36);
                ipc_log_string(*plVar3,"%s: Couldn\'t find clkreq gpio %d\n","msm_pcie_cesta_init",
                               uVar36);
              }
              _printk(&DAT_00123294,"msm_pcie_cesta_init",uVar36);
              goto LAB_00117b6c;
            }
            local_c0._0_4_ = 0;
            lVar14 = *plVar29;
            of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,pcie-sm-seq",&local_c0);
            if ((int)local_c0 == 0) {
              if (plVar29 != (long *)0x0) {
                pcVar31 = "%s: PCIe: RC%d: state manager seq is not present in DT\n";
                pcVar21 = "DBG1:%s: PCIe: RC%d: state manager seq is not present in DT\n";
LAB_001181a8:
                ipc_log_string(*plVar2,pcVar21,"msm_pcie_cesta_get_sm_seq",(int)*plVar30);
                ipc_log_string(*plVar3,pcVar31,"msm_pcie_cesta_get_sm_seq",(int)*plVar30);
              }
LAB_001181d8:
              uVar36 = 0xfffffffb;
            }
            else {
              lVar23 = lVar14 + 0x10;
              piVar19 = (int *)devm_kmalloc(lVar23,0x30,0xdc0);
              if (piVar19 != (int *)0x0) {
                iVar11 = (int)local_c0 >> 2;
                piVar19[8] = iVar11;
                lVar16 = devm_kmalloc(lVar23,(long)(int)local_c0,0xdc0);
                *(long *)(piVar19 + 2) = lVar16;
                if (lVar16 != 0) {
                  iVar11 = of_property_read_variable_u32_array
                                     (*(undefined8 *)(lVar14 + 0x2f8),"qcom,pcie-sm-seq",lVar16,
                                      (long)iVar11,0);
                  if (-1 < iVar11) {
                    iVar11 = of_property_read_variable_u32_array
                                       (*(undefined8 *)(lVar14 + 0x2f8),"qcom,pcie-sm-branch-offset"
                                        ,piVar19,1,0);
                    if (-1 < iVar11) {
                      iVar11 = of_property_read_variable_u32_array
                                         (*(undefined8 *)(lVar14 + 0x2f8),
                                          "qcom,pcie-sm-start-offset",piVar19 + 1,1,0);
                      if (-1 < iVar11) {
                        of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,pcie-sm-branch-seq",
                                        &local_c0);
                        if ((int)local_c0 == 0) {
                          if (plVar29 != (long *)0x0) {
                            pcVar31 = "%s: PCIe: RC%d: sm branch seq is not present in DT\n";
                            pcVar21 = "DBG1:%s: PCIe: RC%d: sm branch seq is not present in DT\n";
                            goto LAB_001181a8;
                          }
                        }
                        else {
                          piVar19[9] = (int)local_c0 >> 2;
                          lVar16 = devm_kmalloc(lVar23,(long)(int)local_c0,0xdc0);
                          *(long *)(piVar19 + 4) = lVar16;
                          if (lVar16 == 0) goto LAB_00117b68;
                          iVar11 = of_property_read_variable_u32_array
                                             (*(undefined8 *)(lVar14 + 0x2f8),
                                              "qcom,pcie-sm-branch-seq",lVar16,(long)piVar19[9],0);
                          if (-1 < iVar11) {
                            of_get_property(*(undefined8 *)(lVar14 + 0x2f8),"qcom,pcie-sm-debug",
                                            &local_c0);
                            if ((int)local_c0 == 0) {
                              if (plVar29 != (long *)0x0) {
                                ipc_log_string(*plVar2,
                                               "DBG1:%s: PCIe: RC%d: sm debugs regs are not present in DT\n"
                                               ,"msm_pcie_cesta_get_sm_seq",(int)*plVar30);
                                ipc_log_string(*plVar3,
                                               "%s: PCIe: RC%d: sm debugs regs are not present in DT\n"
                                               ,"msm_pcie_cesta_get_sm_seq",(int)*plVar30);
                              }
                            }
                            else {
                              piVar19[10] = (int)local_c0 >> 2;
                              lVar23 = devm_kmalloc(lVar23,(long)(int)local_c0,0xdc0);
                              *(long *)(piVar19 + 6) = lVar23;
                              if (lVar23 == 0) goto LAB_00117b68;
                              iVar11 = of_property_read_variable_u32_array
                                                 (*(undefined8 *)(lVar14 + 0x2f8),
                                                  "qcom,pcie-sm-debug",lVar23,(long)piVar19[10],0);
                              if (iVar11 < 0) {
                                piVar19[10] = 0;
                              }
                            }
                            plVar29[0x1a1] = (long)piVar19;
                            lVar14 = plVar29[0x1a0] +
                                     (ulong)(uint)(DAT_00130028 + DAT_00130030 * (int)plVar29[0xae])
                            ;
                            writel_relaxed(0,lVar14);
                            readl_relaxed(lVar14);
                            lVar14 = plVar29[0x1a0] +
                                     (ulong)(uint)(DAT_0013002c + DAT_00130030 * (int)plVar29[0xae])
                            ;
                            writel_relaxed(0,lVar14);
                            readl_relaxed(lVar14);
                            if (0 < piVar19[8]) {
                              lVar14 = 0;
                              do {
                                uVar36 = lVar14 * 4;
                                if (plVar29 != (long *)0x0) {
                                  ipc_log_string(*plVar2,"DBG1:%s: sm seq val 0x%x\n",
                                                 "msm_pcie_cesta_load_sm_seq",
                                                 *(undefined4 *)(*(long *)(piVar19 + 2) + uVar36));
                                  ipc_log_string(*plVar3,"%s: sm seq val 0x%x\n",
                                                 "msm_pcie_cesta_load_sm_seq",
                                                 *(undefined4 *)(*(long *)(piVar19 + 2) + uVar36));
                                }
                                lVar23 = plVar29[0x1a0] + (uVar36 & 0xfffffffc);
                                writel_relaxed(*(undefined4 *)(*(long *)(piVar19 + 2) + uVar36),
                                               lVar23);
                                readl_relaxed(lVar23);
                                lVar14 = lVar14 + 1;
                              } while (lVar14 < piVar19[8]);
                            }
                            if (0 < piVar19[9]) {
                              iVar11 = 0;
                              lVar14 = 0;
                              do {
                                if (plVar29 != (long *)0x0) {
                                  ipc_log_string(*plVar2,"DBG1:%s: branch seq val 0x%x\n",
                                                 "msm_pcie_cesta_load_sm_seq",
                                                 *(undefined4 *)
                                                  (*(long *)(piVar19 + 4) + lVar14 * 4));
                                  ipc_log_string(*plVar3,"%s: branch seq val 0x%x\n",
                                                 "msm_pcie_cesta_load_sm_seq",
                                                 *(undefined4 *)
                                                  (*(long *)(piVar19 + 4) + lVar14 * 4));
                                }
                                lVar23 = plVar29[0x1a0] + (ulong)(uint)(iVar11 + *piVar19);
                                writel_relaxed(*(undefined4 *)(*(long *)(piVar19 + 4) + lVar14 * 4),
                                               lVar23);
                                readl_relaxed(lVar23);
                                lVar14 = lVar14 + 1;
                                iVar11 = iVar11 + 4;
                              } while (lVar14 < piVar19[9]);
                            }
                            lVar14 = plVar29[0x1a0] + (ulong)(uint)piVar19[1];
                            uVar10 = readl_relaxed(lVar14);
                            writel_relaxed(uVar10 | 1,lVar14);
                            readl_relaxed(lVar14);
                            uVar36 = crm_get_device("pcie_crm");
                            plVar29[0x19f] = uVar36;
                            if (uVar36 < 0xfffffffffffff001) {
                              msm_pcie_cesta_map._8_4_ = (int)plVar29[0x80] + 1;
                              plVar29[0xff] = 0xfffffffe0;
                              msm_pcie_cesta_map._12_4_ = msm_pcie_cesta_map._8_4_;
                              msm_pcie_cesta_map._20_4_ = msm_pcie_cesta_map._8_4_;
                              plVar29[0x100] = (long)(plVar29 + 0x100);
                              plVar29[0x101] = (long)plVar4;
                              *(undefined1 *)(plVar29 + 0x111) = 1;
                              plVar29[0x102] = (long)msm_pcie_drv_cesta_connect_worker;
                            }
                            else {
                              if (plVar29 != (long *)0x0) {
                                ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: fail to get crm_dev\n",
                                               "msm_pcie_cesta_init",(int)*plVar30);
                                ipc_log_string(*plVar3,"%s: PCIe: RC%d: fail to get crm_dev\n",
                                               "msm_pcie_cesta_init",(int)*plVar30);
                              }
                              _printk(&DAT_001299a1,"msm_pcie_cesta_init",(int)*plVar30);
                            }
                            goto LAB_001177d8;
                          }
                        }
                      }
                    }
                  }
                  goto LAB_001181d8;
                }
              }
LAB_00117b68:
              uVar36 = 0xfffffff4;
            }
            goto LAB_00117b6c;
          }
          if ((((plVar29[0x110] != 0) || ((char)plVar29[0x111] != '\0')) &&
              (iVar11 = __register_rpmsg_driver(&msm_pcie_drv_rpmsg_driver,&__this_module),
              iVar11 != -0x10)) && (iVar11 != 0)) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"ERR:%s: PCIe %d: DRV: rpmsg register fail: ret: %d\n",
                             "msm_pcie_probe",(int)*plVar30,iVar11);
              ipc_log_string(*plVar3,"%s: PCIe %d: DRV: rpmsg register fail: ret: %d\n",
                             "msm_pcie_probe",(int)*plVar30,iVar11);
            }
            _printk(&DAT_001260bd,"msm_pcie_probe",(int)*plVar30,iVar11);
          }
LAB_001177d8:
          uVar36 = devm_pinctrl_get(plVar1);
          plVar29[0xe8] = uVar36;
          if ((uVar36 == 0) || (0xfffffffffffff000 < uVar36)) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d failed to get pinctrl\n",
                             "msm_pcie_get_pinctrl",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d failed to get pinctrl\n","msm_pcie_get_pinctrl"
                             ,(int)*plVar30);
            }
            _printk(&DAT_0012e6ee,"msm_pcie_get_pinctrl",(int)plVar29[0xae]);
            if ((char)plVar29[0xe7] != '\0') {
              uVar36 = plVar29[0xe8];
              goto LAB_001177f8;
            }
          }
          else {
            *(undefined1 *)(plVar29 + 0xe7) = 1;
LAB_001177f8:
            uVar36 = pinctrl_lookup_state(uVar36,"default");
            plVar29[0xe9] = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d could not get pinctrl default state\n",
                               "msm_pcie_get_pinctrl",(int)*plVar30);
                ipc_log_string(*plVar3,"%s: PCIe: RC%d could not get pinctrl default state\n",
                               "msm_pcie_get_pinctrl",(int)*plVar30);
              }
              _printk(&DAT_001210b5,"msm_pcie_get_pinctrl",(int)plVar29[0xae]);
              plVar29[0xe9] = 0;
            }
            uVar36 = pinctrl_lookup_state(plVar29[0xe8],"sleep");
            plVar29[0xea] = uVar36;
            if (0xfffffffffffff000 < uVar36) {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d could not get pinctrl sleep state\n",
                               "msm_pcie_get_pinctrl",(int)*plVar30);
                ipc_log_string(*plVar3,"%s: PCIe: RC%d could not get pinctrl sleep state\n",
                               "msm_pcie_get_pinctrl",(int)*plVar30);
              }
              _printk(&DAT_00124b9c,"msm_pcie_get_pinctrl",(int)plVar29[0xae]);
              plVar29[0xea] = 0;
            }
          }
          lVar14 = *plVar29;
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,"DBG1:%s: RC%d\n","msm_pcie_irq_init",(int)*plVar30);
            ipc_log_string(*plVar3,"%s: RC%d\n","msm_pcie_irq_init",(int)*plVar30);
          }
          lVar23 = *(long *)(lVar14 + 0x80);
          plVar4 = (long *)(lVar14 + 0x10);
          if (lVar23 == 0) {
            lVar23 = *plVar4;
          }
          lVar14 = wakeup_source_register(plVar4,lVar23);
          plVar29[0x99] = lVar14;
          if (lVar14 == 0) {
            if (plVar29 != (long *)0x0) {
              ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: failed to register wakeup source\n",
                             "msm_pcie_irq_init",(int)*plVar30);
              ipc_log_string(*plVar3,"%s: PCIe: RC%d: failed to register wakeup source\n",
                             "msm_pcie_irq_init",(int)*plVar30);
            }
            _printk(&DAT_00121904,"msm_pcie_irq_init",(int)*plVar30);
            uVar36 = 0xfffffff4;
          }
          else if (((int)plVar29[0x53] == 0) ||
                  (uVar10 = devm_request_threaded_irq
                                      (plVar4,(int)plVar29[0x53],handle_global_irq,handle_aer_irq,
                                       0x2001,plVar29[0x52],plVar29), uVar10 == 0)) {
            if ((int)plVar29[0x7a] == 0) {
LAB_0011793c:
              plVar29[0x112] = 0;
              plVar29[0x113] = 0x80000007f;
              plVar29[0x114] = (long)(plVar29 + 0x115);
              iVar11 = sysfs_create_group(*plVar29 + 0x10,&msm_pcie_debug_attr_group);
              if (iVar11 != 0) {
                if (plVar29 != (long *)0x0) {
                  ipc_log_string(plVar29[0xe6],
                                 "DBG_FS:%s: RC%d: failed to create sysfs debug group\n",
                                 "msm_pcie_sysfs_init",(int)plVar29[0xae]);
                }
                _printk(&DAT_0012b31e,"msm_pcie_sysfs_init",(int)*plVar30);
              }
              iVar11 = sysfs_create_group(*plVar29 + 0x10,&msm_aer_stats_attr_group);
              if (iVar11 != 0) {
                if (plVar29 != (long *)0x0) {
                  ipc_log_string(plVar29[0xe6],
                                 "DBG_FS:%s: RC%d: failed to create sysfs debug group\n",
                                 "msm_pcie_sysfs_init",(int)plVar29[0xae]);
                }
                _printk(&DAT_0012b31e,"msm_pcie_sysfs_init",(int)*plVar30);
              }
              *(undefined1 *)(plVar29 + 0xaf) = 1;
              of_get_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,filtered-bdfs",&local_cc);
              if (local_cc != 0) {
                lVar14 = devm_kmalloc(plVar1,(long)local_cc,0xdc0);
                plVar29[0x198] = lVar14;
                if (lVar14 == 0) {
                  uVar36 = 0xfffffff4;
                  goto LAB_00117be8;
                }
                *(int *)(plVar29 + 0x199) = local_cc >> 2;
                iVar11 = of_property_read_variable_u32_array
                                   (*(undefined8 *)(param_1 + 0x2f8),"qcom,filtered-bdfs",lVar14,
                                    local_cc >> 2,0);
                if (iVar11 < 0) {
                  *(undefined4 *)(plVar29 + 0x199) = 0;
                }
              }
              if ((*(byte *)(plVar29 + 0xab) & 1) == 0) {
                iVar11 = msm_pcie_enumerate(local_c8);
                puVar20 = &DAT_001237be;
                if (iVar11 != 0) {
                  puVar20 = &DAT_0012a6c9;
                }
                if (plVar29 == (long *)0x0) {
                  _printk(puVar20,"msm_pcie_probe",_DAT_00000570);
                }
                else {
                  pcVar21 = "ERR:%s: RC%d is enabled in bootup\n";
                  if (iVar11 != 0) {
                    pcVar21 = 
                    "ERR:%s: PCIe: RC%d is not enabled during bootup; it will be enumerated upon client request.\n"
                    ;
                  }
                  pcVar31 = "%s: RC%d is enabled in bootup\n";
                  if (iVar11 != 0) {
                    pcVar31 = 
                    "%s: PCIe: RC%d is not enabled during bootup; it will be enumerated upon client request.\n"
                    ;
                  }
                  ipc_log_string(*plVar2,pcVar21,"msm_pcie_probe",(int)*plVar30);
                  ipc_log_string(*plVar3,pcVar31,"msm_pcie_probe",(int)*plVar30);
                  _printk(puVar20,"msm_pcie_probe",(int)*plVar30);
                  lVar14 = *(long *)(param_1 + 0x80);
                  if (lVar14 == 0) {
                    lVar14 = *plVar1;
                  }
                  ipc_log_string(*plVar2,"DBG1:%s: PCIe probed %s\n","msm_pcie_probe",lVar14);
                  lVar14 = *(long *)(param_1 + 0x80);
                  if (lVar14 == 0) {
                    lVar14 = *plVar1;
                  }
                  ipc_log_string(*plVar3,"%s: PCIe probed %s\n","msm_pcie_probe",lVar14);
                }
              }
              else if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,
                               "DBG1:%s: PCIe: RC%d will be enumerated by client or endpoint.\n",
                               "msm_pcie_probe",(int)*plVar30);
                ipc_log_string(*plVar3,"%s: PCIe: RC%d will be enumerated by client or endpoint.\n",
                               "msm_pcie_probe",(int)*plVar30);
              }
              uVar36 = 0;
              goto LAB_00117be8;
            }
            uVar10 = devm_request_threaded_irq
                               (plVar4,(int)plVar29[0x7a],handle_wake_irq,0,2,"msm_pcie_wake",
                                plVar29);
            if (uVar10 == 0) {
              plVar29[0xb0] = 0xfffffffe0;
              plVar29[0xb1] = (long)(plVar29 + 0xb1);
              plVar29[0xb2] = (long)(plVar29 + 0xb1);
              plVar29[0xb3] = (long)handle_wake_func;
              plVar29[0xb6] = 0xfffffffe0;
              plVar29[0xb7] = (long)(plVar29 + 0xb7);
              plVar29[0xb8] = (long)(plVar29 + 0xb7);
              plVar29[0xb9] = (long)handle_sbr_func;
              uVar10 = irq_set_irq_wake((int)plVar29[0x7a],1);
              if (uVar10 == 0) goto LAB_0011793c;
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: Unable to enable wake interrupt\n",
                               "msm_pcie_irq_init",(int)*plVar30);
                ipc_log_string(*plVar3,"%s: PCIe: RC%d: Unable to enable wake interrupt\n",
                               "msm_pcie_irq_init",(int)*plVar30);
              }
              uVar13 = (undefined4)*plVar30;
              puVar20 = &DAT_0012297a;
            }
            else {
              if (plVar29 != (long *)0x0) {
                ipc_log_string(*plVar2,"ERR:%s: PCIe: RC%d: Unable to request wake interrupt\n",
                               "msm_pcie_irq_init",(int)*plVar30);
                ipc_log_string(*plVar3,"%s: PCIe: RC%d: Unable to request wake interrupt\n",
                               "msm_pcie_irq_init",(int)*plVar30);
              }
              uVar13 = (undefined4)*plVar30;
              puVar20 = &DAT_0012e716;
            }
            uVar36 = (ulong)uVar10;
            _printk(puVar20,"msm_pcie_irq_init",uVar13);
          }
          else {
            uVar36 = (ulong)uVar10;
            if (plVar29 != (long *)0x0) {
              ipc_log_string(plVar29[0xe5],
                             "ERR:%s: PCIe: RC%d: Unable to request global_int interrupt: %d\n",
                             "msm_pcie_irq_init",(int)plVar29[0xae],(int)plVar29[0x53]);
              ipc_log_string(plVar29[0xe4],
                             "%s: PCIe: RC%d: Unable to request global_int interrupt: %d\n",
                             "msm_pcie_irq_init",(int)plVar29[0xae],(int)plVar29[0x53]);
            }
            _printk(&DAT_0012cfdb,"msm_pcie_irq_init",(int)plVar29[0xae],(int)plVar29[0x53]);
          }
          plVar29[0x70] = 0;
          plVar29[0x1a0] = 0;
          plVar29[0x72] = 0;
          plVar29[0x73] = 0;
          plVar29[0x74] = 0;
          plVar29[0x75] = 0;
          plVar29[0x76] = 0;
          plVar29[0x77] = 0;
          plVar29[0x78] = 0;
          kfree(plVar29[0x19c]);
          kfree(plVar29[0x19e]);
          kfree(plVar29[0x19a]);
          plVar29[0x19c] = 0;
          plVar29[0x19e] = 0;
          plVar29[0x19a] = 0;
        }
        else {
          if (plVar29 != (long *)0x0) {
            ipc_log_string(*plVar2,
                           "ERR:%s: PCIe: RC%d: mismatch between number of clock and frequency entries: %d != %d\n"
                           ,"msm_pcie_get_clk",(int)*plVar30,uVar36,uVar12);
            ipc_log_string(*plVar3,
                           "%s: PCIe: RC%d: mismatch between number of clock and frequency entries: %d != %d\n"
                           ,"msm_pcie_get_clk",(int)*plVar30,uVar36,uVar12);
          }
          uVar13 = (undefined4)*plVar30;
          puVar20 = &DAT_00127224;
LAB_00117114:
          _printk(puVar20,"msm_pcie_get_clk",uVar13,uVar36,uVar12);
          uVar36 = 0xfffffffb;
        }
      }
LAB_00117b6c:
      pcie_drv = pcie_drv + -1;
      if (plVar29 != (long *)0x0) {
        ipc_log_string(plVar29[0xe5],"ERR:%s: PCIe: RC%d: Driver probe failed. ret: %d\n",
                       "msm_pcie_probe",(int)plVar29[0xae],uVar36 & 0xffffffff);
        ipc_log_string(plVar29[0xe4],"%s: PCIe: RC%d: Driver probe failed. ret: %d\n",
                       "msm_pcie_probe",(int)plVar29[0xae],uVar36 & 0xffffffff);
      }
LAB_00117bc0:
      _printk(&DAT_00121f92,"msm_pcie_probe",(int)*plVar30,uVar36 & 0xffffffff);
      goto LAB_00117bdc;
    }
    uVar36 = 0;
  }
  _printk(&DAT_001216b6);
LAB_00117be8:
  mutex_unlock(&DAT_00130190);
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar36 & 0xffffffff;
}



//------------------------------------------------------------
// msm_pcie_remove @ 00118424 size=900
// signature: undefined msm_pcie_remove(void)
// callers: []
//------------------------------------------------------------

int msm_pcie_remove(long param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  uint local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  mutex_lock(&DAT_00130190);
  iVar3 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"cell-index",&local_4c,1,0);
  if (iVar3 < 0) {
    _printk(&DAT_001282fe,"msm_pcie_remove");
LAB_00118754:
    if (-1 < iVar3) {
      iVar3 = 0;
    }
    mutex_unlock(&DAT_00130190);
    lVar5 = sp_el0;
    if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return iVar3;
  }
  pcie_drv = pcie_drv + -1;
  _dev_info(param_1 + 0x10,"PCIe: RC%d: being removed\n",local_4c);
  uVar4 = (ulong)local_4c;
  if (local_4c < 5) {
    lVar5 = (&msm_pcie_dev)[uVar4];
    if (*(long *)(lVar5 + 0x4c0) != 0) {
      pci_load_and_free_saved_state(*(undefined8 *)(lVar5 + 8),lVar5 + 0x4c0);
      uVar4 = (ulong)local_4c;
      if (4 < local_4c) goto LAB_0011879c;
    }
    if ((uint)uVar4 < 5) {
      lVar5 = (&msm_pcie_dev)[uVar4];
      if (*(long *)(lVar5 + 0x4b8) != 0) {
        pci_load_and_free_saved_state(*(undefined8 *)(lVar5 + 8),lVar5 + 0x4b8);
        uVar4 = (ulong)local_4c;
        if (4 < local_4c) goto LAB_0011879c;
      }
      if ((uint)uVar4 < 5) {
        if (*(long *)((&msm_pcie_dev)[uVar4] + 0xd00) != 0) {
          msm_pcie_cesta_map_apply((&msm_pcie_dev)[uVar4],0);
          uVar4 = (ulong)local_4c;
          if (4 < local_4c) goto LAB_0011879c;
        }
        if ((uint)uVar4 < 5) {
          lVar5 = (&msm_pcie_dev)[uVar4];
          if (lVar5 != 0) {
            ipc_log_string(*(undefined8 *)(lVar5 + 0x728),"DBG1:%s: RC%d\n","msm_pcie_irq_deinit",
                           *(undefined4 *)(lVar5 + 0x570));
            ipc_log_string(*(undefined8 *)(lVar5 + 0x720),"%s: RC%d\n","msm_pcie_irq_deinit",
                           *(undefined4 *)(lVar5 + 0x570));
          }
          wakeup_source_unregister(*(undefined8 *)(lVar5 + 0x4c8));
          if (*(int *)(lVar5 + 0x3d0) != 0) {
            disable_irq();
          }
          if (local_4c < 5) {
            msm_pcie_vreg_deinit((&msm_pcie_dev)[local_4c]);
            if (local_4c < 5) {
              msm_pcie_clk_deinit((&msm_pcie_dev)[local_4c]);
              if (local_4c < 5) {
                msm_pcie_gdsc_deinit((&msm_pcie_dev)[local_4c]);
                if (local_4c < 5) {
                  msm_pcie_gpio_deinit((&msm_pcie_dev)[local_4c]);
                  if (local_4c < 5) {
                    lVar5 = (&msm_pcie_dev)[local_4c];
                    *(undefined8 *)(lVar5 + 0x380) = 0;
                    *(undefined8 *)(lVar5 + 0xd00) = 0;
                    *(undefined8 *)(lVar5 + 0x390) = 0;
                    *(undefined8 *)(lVar5 + 0x398) = 0;
                    *(undefined8 *)(lVar5 + 0x3a0) = 0;
                    *(undefined8 *)(lVar5 + 0x3a8) = 0;
                    *(undefined8 *)(lVar5 + 0x3b0) = 0;
                    *(undefined8 *)(lVar5 + 0x3b8) = 0;
                    *(undefined8 *)(lVar5 + 0x3c0) = 0;
                    kfree(*(undefined8 *)(lVar5 + 0xce0));
                    kfree(*(undefined8 *)(lVar5 + 0xcf0));
                    kfree(*(undefined8 *)(lVar5 + 0xcd0));
                    uVar4 = (ulong)local_4c;
                    *(undefined8 *)(lVar5 + 0xce0) = 0;
                    *(undefined8 *)(lVar5 + 0xcf0) = 0;
                    *(undefined8 *)(lVar5 + 0xcd0) = 0;
                    if (local_4c < 5) {
                      plVar6 = *(long **)((&msm_pcie_dev)[uVar4] + 0x6b0);
                      do {
                        if (4 < uVar4) goto LAB_001187a0;
                        if (plVar6 == (long *)((&msm_pcie_dev)[uVar4] + 0x6b0)) {
                          plVar6 = *(long **)((&msm_pcie_dev)[uVar4] + 0x6c0);
                          goto LAB_001186f0;
                        }
                        plVar7 = (long *)*plVar6;
                        uVar4 = __list_del_entry_valid(plVar6);
                        if ((uVar4 & 1) != 0) {
                          lVar5 = *plVar6;
                          plVar1 = (long *)plVar6[1];
                          *(long **)(lVar5 + 8) = plVar1;
                          *plVar1 = lVar5;
                        }
                        *plVar6 = -0x2152ffffffffff00;
                        plVar6[1] = -0x2152fffffffffede;
                        kfree(plVar6);
                        uVar4 = (ulong)local_4c;
                        plVar6 = plVar7;
                      } while (local_4c < 5);
                    }
                  }
                }
              }
            }
          }
          goto LAB_0011879c;
        }
      }
    }
LAB_001187a0:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(1,0x1187a4);
    (*pcVar2)();
  }
  goto LAB_0011879c;
  while( true ) {
    if (plVar6 == (long *)((&msm_pcie_dev)[uVar4] + 0x6c0)) {
      ipc_log_context_destroy(*(undefined8 *)((&msm_pcie_dev)[uVar4] + 0x720));
      if (4 < uVar4) goto LAB_001187a0;
      ipc_log_context_destroy(*(undefined8 *)((&msm_pcie_dev)[uVar4] + 0x728));
      ipc_log_context_destroy(*(undefined8 *)((&msm_pcie_dev)[uVar4] + 0x730));
      goto LAB_00118754;
    }
    plVar7 = (long *)*plVar6;
    uVar4 = __list_del_entry_valid(plVar6);
    if ((uVar4 & 1) != 0) {
      lVar5 = *plVar6;
      plVar1 = (long *)plVar6[1];
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
    }
    *plVar6 = -0x2152ffffffffff00;
    plVar6[1] = -0x2152fffffffffede;
    kfree(plVar6);
    uVar4 = (ulong)local_4c;
    plVar6 = plVar7;
    if (4 < local_4c) break;
LAB_001186f0:
    if (4 < uVar4) goto LAB_001187a0;
  }
LAB_0011879c:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1187a0);
  (*pcVar2)();
}



//------------------------------------------------------------
// msm_pcie_rumi_init @ 001187ac size=452
// signature: undefined msm_pcie_rumi_init(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_rumi_init(long param_1)

{
  long lVar1;
  uint uVar2;
  
  if (param_1 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: RC%d: enter.\n",
                   "msm_pcie_rumi_init",*(undefined4 *)(param_1 + 0x570));
    ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: PCIe: RC%d: enter.\n","msm_pcie_rumi_init",
                   *(undefined4 *)(param_1 + 0x570));
  }
  lVar1 = *(long *)(param_1 + 0x3c0) + 0x54;
  writel_relaxed(0x7c70,lVar1);
  readl_relaxed(lVar1);
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x3c0) + 0x40);
  lVar1 = *(long *)(param_1 + 0x3c0) + 0x40;
  writel_relaxed(uVar2 | 0x1000,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(10000,0x2711,2);
  lVar1 = *(long *)(param_1 + 0x3c0) + 4;
  writel_relaxed(0x800,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(50000,0xc351,2);
  lVar1 = *(long *)(param_1 + 0x3c0) + 4;
  writel_relaxed(0xffffffff,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(50000,0xc351,2);
  lVar1 = *(long *)(param_1 + 0x3c0) + 4;
  writel_relaxed(0x800,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(50000,0xc351,2);
  lVar1 = *(long *)(param_1 + 0x3c0) + 4;
  writel_relaxed(0,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(50000,0xc351,2);
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x3c0) + 0x40);
  lVar1 = *(long *)(param_1 + 0x3c0) + 0x40;
  writel_relaxed(uVar2 & 0xffffefff,lVar1);
  readl_relaxed(lVar1);
  usleep_range_state(10000,0x2711,2);
  uVar2 = readl_relaxed(*(long *)(param_1 + 0x3c0) + 0x40);
  lVar1 = *(long *)(param_1 + 0x3c0) + 0x40;
  writel_relaxed(uVar2 & 0xfffffffe,lVar1);
  readl_relaxed(lVar1);
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_disable_pc @ 00118974 size=44
// signature: undefined msm_pcie_drv_disable_pc(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_disable_pc(long param_1)

{
  msm_pcie_drv_send_rpmsg(param_1 + -0x7c8,*(long *)(param_1 + -0x38) + 0xc9);
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_enable_pc @ 001189a4 size=44
// signature: undefined msm_pcie_drv_enable_pc(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_enable_pc(long param_1)

{
  msm_pcie_drv_send_rpmsg(param_1 + -0x798,*(long *)(param_1 + -8) + 0xa1);
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_connect_worker @ 001189d4 size=148
// signature: undefined msm_pcie_drv_connect_worker(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_connect_worker(long param_1)

{
  ulong uVar1;
  char *pcVar2;
  
  pcVar2 = *(char **)(param_1 + -0x68);
  if (((DAT_00130158 != 0 && pcVar2 != (char *)0x0) && (*pcVar2 == '\0')) &&
     (uVar1 = msm_pcie_notify_client(param_1 + -0x7f8,0x10), (uVar1 & 1) != 0)) {
    mutex_lock(param_1 + 0x38);
    *pcVar2 = '\x01';
    if (*(int *)(param_1 + 0x30) != 0) {
      queue_work_on(0x20,mpcie_wq,param_1 + -0x30);
    }
    mutex_unlock(param_1 + 0x38);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_disable_resource @ 00118a6c size=32
// signature: undefined msm_pcie_disable_resource(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_disable_resource(long param_1)

{
  msm_pcie_disable(param_1 + -0x5e0);
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_send_rpmsg @ 00118a8c size=608
// signature: undefined msm_pcie_drv_send_rpmsg(void)
// callers: [msm_pcie_drv_disable_pc, msm_pcie_pm_control, msm_pcie_drv_enable_pc]
//------------------------------------------------------------

int msm_pcie_drv_send_rpmsg(long param_1,long param_2)

{
  short sVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  int iVar6;
  
  if (*(long *)(param_1 + 0xd00) == 0) {
    lVar5 = *(long *)(param_1 + 0x790);
    mutex_lock(&DAT_001301c0);
    lVar2 = DAT_00130158;
    if (DAT_00130158 == 0) {
      iVar3 = -5;
    }
    else {
      sVar1 = *(short *)(lVar5 + 0xf8);
      *(undefined4 *)(lVar5 + 0x100) = 0;
      *(short *)(lVar5 + 0xfa) = sVar1;
      *(short *)(lVar5 + 0xf8) = sVar1 + 1;
      *(short *)(param_2 + 6) = sVar1;
      if (*(short *)(lVar5 + 0xf8) == -1) {
        *(undefined2 *)(lVar5 + 0xf8) = 0;
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "DBG1:%s: PCIe: RC%d: DRV: sending rpmsg: command: 0x%x\n",
                       "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570),
                       *(undefined4 *)(param_2 + 0x18));
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d: DRV: sending rpmsg: command: 0x%x\n",
                       "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570),
                       *(undefined4 *)(param_2 + 0x18));
      }
      iVar3 = rpmsg_trysend(*(undefined8 *)(lVar2 + 0x3c8),param_2,0x28);
      if (iVar3 != 0) {
        iVar6 = -0x14;
        do {
          if ((iVar3 != -0x10) || (iVar6 == 0)) {
            if (param_1 != 0) {
              ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                             "ERR:%s: PCIe: RC%d: DRV: failed to send rpmsg, ret:%d\n",
                             "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570),iVar3);
              ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                             "%s: PCIe: RC%d: DRV: failed to send rpmsg, ret:%d\n",
                             "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570),iVar3);
            }
            _printk(&DAT_00129109,"msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570),iVar3);
            goto LAB_00118bf8;
          }
          usleep_range_state(5000,0x1389,2);
          iVar3 = rpmsg_trysend(*(undefined8 *)(lVar2 + 0x3c8),param_2,0x28);
          iVar6 = iVar6 + 1;
        } while (iVar3 != 0);
      }
      uVar4 = __msecs_to_jiffies(*(undefined4 *)(lVar5 + 0xfc));
      iVar3 = wait_for_completion_timeout(lVar5 + 0x100,uVar4);
      if (iVar3 == 0) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: completion timeout for rpmsg\n",
                         "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570));
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: PCIe: RC%d: DRV: completion timeout for rpmsg\n",
                         "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570));
        }
        _printk(&DAT_00121fd7,"msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570));
        iVar3 = -0x6e;
      }
      else {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                         "DBG1:%s: PCIe: RC%d: DRV: rpmsg successfully sent\n",
                         "msm_pcie_drv_send_rpmsg",*(undefined4 *)(param_1 + 0x570));
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                         "%s: PCIe: RC%d: DRV: rpmsg successfully sent\n","msm_pcie_drv_send_rpmsg",
                         *(undefined4 *)(param_1 + 0x570));
        }
        iVar3 = 0;
      }
    }
LAB_00118bf8:
    mutex_unlock(&DAT_001301c0);
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}



//------------------------------------------------------------
// handle_link_recover @ 00118cf0 size=124
// signature: undefined handle_link_recover(void)
// callers: []
//------------------------------------------------------------

void handle_link_recover(long param_1)

{
  if (param_1 + -0x760 != 0) {
    ipc_log_string(*(undefined8 *)(param_1 + -0x38),"DBG1:%s: PCIe: link recover start for RC%d\n",
                   "handle_link_recover",*(undefined4 *)(param_1 + -0x1f0));
    ipc_log_string(*(undefined8 *)(param_1 + -0x40),"%s: PCIe: link recover start for RC%d\n",
                   "handle_link_recover",*(undefined4 *)(param_1 + -0x1f0));
  }
  msm_pcie_notify_client(param_1 + -0x760,0x40);
  return;
}



//------------------------------------------------------------
// ntn3_i2c_read @ 00118d70 size=188
// signature: undefined ntn3_i2c_read(void)
// callers: []
//------------------------------------------------------------

void ntn3_i2c_read(long param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined2 local_48;
  undefined6 uStack_46;
  undefined1 *puStack_40;
  undefined2 local_38;
  undefined6 uStack_36;
  undefined1 *puStack_30;
  long local_28;
  
  puStack_30 = (undefined1 *)&local_50;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_4c = (undefined1)((ulong)param_2 >> 0x10);
  puStack_40 = &local_4c;
  local_4a = (undefined1)param_2;
  local_50 = 0;
  local_4b = (undefined1)((ulong)param_2 >> 8);
  _local_48 = CONCAT62(0x30000,*(undefined2 *)(param_1 + 2));
  _local_38 = CONCAT62(0x40001,*(undefined2 *)(param_1 + 2));
  uVar2 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_48,2);
  if ((int)uVar2 == 2) {
    uVar2 = 0;
    *param_3 = local_50;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// ntn3_i2c_write @ 00118e30 size=164
// signature: undefined ntn3_i2c_write(void)
// callers: []
//------------------------------------------------------------

void ntn3_i2c_write(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  undefined2 local_30;
  undefined6 uStack_2e;
  undefined1 *puStack_28;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  puStack_28 = &local_20;
  local_20 = (undefined1)((ulong)param_2 >> 0x10);
  local_1f = (undefined1)((ulong)param_2 >> 8);
  local_1c = (undefined1)((ulong)param_3 >> 8);
  local_1e = (undefined1)param_2;
  _local_30 = CONCAT62(0x70000,*(undefined2 *)(param_1 + 2));
  local_1b = (undefined1)((ulong)param_3 >> 0x10);
  local_1d = (undefined1)param_3;
  local_1a = (undefined1)((ulong)param_3 >> 0x18);
  iVar3 = i2c_transfer(*(undefined8 *)(param_1 + 0x18),&local_30,1);
  lVar2 = sp_el0;
  iVar1 = 0;
  if (iVar3 != 1) {
    iVar1 = iVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// ntn3_ep_reset_ctrl @ 00118ed8 size=704
// signature: undefined ntn3_ep_reset_ctrl(void)
// callers: []
//------------------------------------------------------------

int ntn3_ep_reset_ctrl(undefined8 *param_1,ulong param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  code *pcVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  if ((param_1[0xb] == 0) || (pcVar5 = (code *)param_1[10], pcVar5 == (code *)0x0)) {
    iVar3 = -0x5f;
    goto LAB_0011900c;
  }
  if (*(int *)(pcVar5 + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x118f40);
    (*pcVar5)();
  }
  iVar3 = (*pcVar5)(*param_1,*(undefined4 *)(param_1 + 1),&local_3c);
  if (iVar3 == 0) {
    local_3c = local_3c & (*(uint *)(param_1 + 2) ^ 0xffffffff);
    if (*(int *)((code *)param_1[0xb] + -4) != -0x7f8b7687) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x118f7c);
      (*pcVar5)();
    }
    (*(code *)param_1[0xb])(*param_1,*(undefined4 *)(param_1 + 1));
    if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x118fa8);
      (*pcVar5)();
    }
    iVar3 = (*(code *)param_1[10])(*param_1,*(undefined4 *)(param_1 + 1),&local_3c);
    if (iVar3 != 0) goto LAB_00118fb0;
    if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x119064);
      (*pcVar5)();
    }
    iVar3 = (*(code *)param_1[10])(*param_1,*(undefined4 *)((long)param_1 + 0xc),&local_3c);
    if (iVar3 == 0) {
      local_3c = local_3c & (*(uint *)(param_1 + 2) ^ 0xffffffff);
      if (*(int *)((code *)param_1[0xb] + -4) != -0x7f8b7687) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11909c);
        (*pcVar5)();
      }
      (*(code *)param_1[0xb])(*param_1,*(undefined4 *)((long)param_1 + 0xc));
      if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1190c8);
        (*pcVar5)();
      }
      iVar3 = (*(code *)param_1[10])(*param_1,*(undefined4 *)((long)param_1 + 0xc),&local_3c);
      if (iVar3 == 0) {
        if ((param_2 & 1) != 0) {
          iVar3 = 0;
          goto LAB_0011900c;
        }
        local_3c = local_3c | *(uint *)(param_1 + 2);
        if (*(int *)((code *)param_1[0xb] + -4) != -0x7f8b7687) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x119154);
          (*pcVar5)();
        }
        (*(code *)param_1[0xb])(*param_1,*(undefined4 *)((long)param_1 + 0xc));
        if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x119180);
          (*pcVar5)();
        }
        iVar3 = (*(code *)param_1[10])(*param_1,*(undefined4 *)((long)param_1 + 0xc),&local_3c);
        if (iVar3 == 0) goto LAB_0011900c;
      }
    }
    if (param_1 == (undefined8 *)0xd30) goto LAB_0011900c;
    ipc_log_string(param_1[-0xc1],"DBG1:%s: PCIe: RC%d: ep_reset_gpio read failed : %d\n",
                   "ntn3_ep_reset_ctrl",*(undefined4 *)(param_1 + -0xf8),iVar3);
    uVar1 = *(undefined4 *)(param_1 + -0xf8);
    pcVar4 = "%s: PCIe: RC%d: ep_reset_gpio read failed : %d\n";
  }
  else {
LAB_00118fb0:
    if (param_1 == (undefined8 *)0xd30) goto LAB_0011900c;
    ipc_log_string(param_1[-0xc1],"DBG1:%s: PCIe: RC%d: gpio config reg read failed : %d\n",
                   "ntn3_ep_reset_ctrl",*(undefined4 *)(param_1 + -0xf8),iVar3);
    uVar1 = *(undefined4 *)(param_1 + -0xf8);
    pcVar4 = "%s: PCIe: RC%d: gpio config reg read failed : %d\n";
  }
  ipc_log_string(param_1[-0xc2],pcVar4,"ntn3_ep_reset_ctrl",uVar1,iVar3);
LAB_0011900c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// ntn3_dump_regs @ 0011919c size=316
// signature: undefined ntn3_dump_regs(void)
// callers: []
//------------------------------------------------------------

void ntn3_dump_regs(undefined8 *param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  if (((param_1[10] != 0) && (*(int *)(param_1 + 4) != 0)) &&
     ((param_1 == (undefined8 *)0xd30 ||
      (ipc_log_string(param_1[-0xc0],"DUMP:%s: PCIe: RC%d: NTN3 reg dumps\n","ntn3_dump_regs",
                      *(undefined4 *)(param_1 + -0xf8)), *(int *)(param_1 + 4) != 0)))) {
    uVar3 = 0;
    do {
      if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x822a,0x119274);
        (*pcVar2)();
      }
      (*(code *)param_1[10])(*param_1,*(undefined4 *)(param_1[3] + (long)(int)uVar3 * 4),&local_5c);
      if (param_1 != (undefined8 *)0xd30) {
        ipc_log_string(param_1[-0xc0],"DUMP:%s: PCIe: RC%d: reg: 0x%04x val: 0x%08x\n",
                       "ntn3_dump_regs",*(undefined4 *)(param_1 + -0xf8),
                       *(undefined4 *)(param_1[3] + (long)(int)uVar3 * 4),local_5c);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 4));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ntn3_de_emphasis_wa @ 001192dc size=1008
// signature: undefined ntn3_de_emphasis_wa(void)
// callers: []
//------------------------------------------------------------

void ntn3_de_emphasis_wa(long *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  local_70 = 0;
  if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x119340);
    (*pcVar4)();
  }
  iVar5 = (*(code *)param_1[10])(*param_1,*(undefined4 *)((long)param_1 + 0x34),&local_70);
  if ((param_1 != (long *)0xd30) && (iVar5 != 0)) {
    ipc_log_string(param_1[-0xc1],"DBG1:%s: PCIe: RC%d: gpio version reg read failed : %d\n",
                   "ntn3_de_emphasis_wa",(int)param_1[-0xf8],iVar5);
    ipc_log_string(param_1[-0xc2],"%s: PCIe: RC%d: gpio version reg read failed : %d\n",
                   "ntn3_de_emphasis_wa",(int)param_1[-0xf8],iVar5);
  }
  lVar6 = of_find_property(*(undefined8 *)(*param_1 + 0x308),"force-i2c-setting",0);
  uVar7 = local_70 & 0xff;
  iVar5 = (int)uVar7;
  local_70 = CONCAT44(local_70._4_4_,(uint)(byte)local_70);
  *(bool *)(param_1 + 7) = lVar6 != 0;
  if (param_1 != (long *)0xd30) {
    puVar3 = &DAT_00125754;
    if (lVar6 == 0) {
      puVar3 = &DAT_0012768e;
    }
    ipc_log_string(param_1[-0xc1],
                   "DBG1:%s: PCIe: RC%d: NTN3 Version reg:0x%x and force-i2c-setting is %s enabled",
                   "ntn3_de_emphasis_wa",(int)param_1[-0xf8],uVar7,puVar3);
    puVar3 = &DAT_0012768e;
    if ((char)param_1[7] != '\0') {
      puVar3 = &DAT_00125754;
    }
    ipc_log_string(param_1[-0xc2],
                   "%s: PCIe: RC%d: NTN3 Version reg:0x%x and force-i2c-setting is %s enabled",
                   "ntn3_de_emphasis_wa",(int)param_1[-0xf8],local_70 & 0xffffffff,puVar3);
    iVar5 = (int)local_70;
  }
  if ((iVar5 == 0) || ((char)param_1[7] != '\0')) {
    if (param_1 != (long *)0xd30) {
      ipc_log_string(param_1[-0xc1],"DBG1:%s: PCIe: RC%d: NTN3 reg update\n","ntn3_de_emphasis_wa",
                     (int)param_1[-0xf8]);
      ipc_log_string(param_1[-0xc2],"%s: PCIe: RC%d: NTN3 reg update\n","ntn3_de_emphasis_wa",
                     (int)param_1[-0xf8]);
    }
    if ((int)param_1[6] != 0) {
      uVar7 = 0;
      do {
        uVar8 = -(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar7 << 3;
        puVar2 = (undefined4 *)(param_1[5] + uVar8);
        if (*(int *)((code *)param_1[0xb] + -4) != -0x7f8b7687) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x822a,0x119508);
          (*pcVar4)();
        }
        (*(code *)param_1[0xb])(*param_1,*puVar2,puVar2[1]);
        if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x119538);
          (*pcVar4)();
        }
        (*(code *)param_1[10])(*param_1,*(undefined4 *)(param_1[5] + uVar8),(long)&local_70 + 4);
        if (param_1 != (long *)0xd30) {
          lVar6 = (long)(int)uVar7 * 8;
          puVar2 = (undefined4 *)(param_1[5] + lVar6);
          ipc_log_string(param_1[-0xc1],
                         "DBG1:%s: PCIe: RC%d: NTN3 reg off:0x%x wr_val:0x%x rd_val:0x%x\n",
                         "ntn3_de_emphasis_wa",(int)param_1[-0xf8],*puVar2,puVar2[1],local_70._4_4_)
          ;
          puVar2 = (undefined4 *)(param_1[5] + lVar6);
          ipc_log_string(param_1[-0xc2],
                         "%s: PCIe: RC%d: NTN3 reg off:0x%x wr_val:0x%x rd_val:0x%x\n",
                         "ntn3_de_emphasis_wa",(int)param_1[-0xf8],*puVar2,puVar2[1],local_70._4_4_)
          ;
        }
        uVar1 = (int)uVar7 + 1;
        uVar7 = (ulong)uVar1;
      } while (uVar1 < *(uint *)(param_1 + 6));
    }
  }
  if ((int)param_1[9] != 0) {
    uVar7 = 0;
    do {
      uVar8 = -(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar7 << 3;
      puVar2 = (undefined4 *)(param_1[8] + uVar8);
      if (*(int *)((code *)param_1[0xb] + -4) != -0x7f8b7687) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x822a,0x119608);
        (*pcVar4)();
      }
      (*(code *)param_1[0xb])(*param_1,*puVar2,puVar2[1]);
      if (*(int *)((code *)param_1[10] + -4) != -0x49d493a) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x119638);
        (*pcVar4)();
      }
      (*(code *)param_1[10])(*param_1,*(undefined4 *)(param_1[8] + uVar8),(long)&local_70 + 4);
      if (param_1 != (long *)0xd30) {
        lVar6 = (long)(int)uVar7 * 8;
        puVar2 = (undefined4 *)(param_1[8] + lVar6);
        ipc_log_string(param_1[-0xc1],
                       "DBG1:%s: PCIe: RC%d: NTN3 reg off:0x%x wr_val:0x%x rd_val:0x%x\n",
                       "ntn3_de_emphasis_wa",(int)param_1[-0xf8],*puVar2,puVar2[1],local_70._4_4_);
        puVar2 = (undefined4 *)(param_1[8] + lVar6);
        ipc_log_string(param_1[-0xc2],"%s: PCIe: RC%d: NTN3 reg off:0x%x wr_val:0x%x rd_val:0x%x\n",
                       "ntn3_de_emphasis_wa",(int)param_1[-0xf8],*puVar2,puVar2[1],local_70._4_4_);
      }
      uVar1 = (int)uVar7 + 1;
      uVar7 = (ulong)uVar1;
    } while (uVar1 < *(uint *)(param_1 + 9));
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_cesta_connect_worker @ 001196d0 size=36
// signature: undefined msm_pcie_drv_cesta_connect_worker(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_cesta_connect_worker(long param_1)

{
  msm_pcie_notify_client(param_1 + -0x7f8,0x10);
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_rpmsg_probe @ 001196f8 size=104
// signature: undefined msm_pcie_drv_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_pcie_drv_rpmsg_probe(long param_1)

{
  mutex_lock(&DAT_001301c0);
  DAT_00130158 = param_1;
  *(undefined4 **)(param_1 + 0x98) = &pcie_drv;
  mutex_unlock(&DAT_001301c0);
  queue_work_on(0x20,_system_wq,&DAT_00130160);
  return 0;
}



//------------------------------------------------------------
// msm_pcie_drv_rpmsg_remove @ 00119764 size=240
// signature: undefined msm_pcie_drv_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void msm_pcie_drv_rpmsg_remove(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar2 = *(long *)(param_1 + 0x98);
  lVar3 = **(long **)(lVar2 + 0x10);
  mutex_lock(lVar2 + 0x80);
  *(undefined8 *)(lVar2 + 8) = 0;
  *(undefined8 *)(lVar2 + 0x18) = 0;
  mutex_unlock(lVar2 + 0x80);
  __flush_workqueue(mpcie_wq);
  flush_work(lVar2 + 0x20);
  msm_pcie_drv_notify_client(lVar2,0x20);
  if (*(long *)(lVar2 + 200) != 0) {
    iVar1 = qcom_unregister_ssr_notifier(*(long *)(lVar2 + 200),lVar2 + 0xb0);
    if (iVar1 != 0) {
      if (lVar3 != 0) {
        ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                       "ERR:%s: PCIe: RC%d: DRV: error %d unregistering notifier\n",
                       "msm_pcie_drv_rpmsg_remove",*(undefined4 *)(lVar3 + 0x570),iVar1);
        ipc_log_string(*(undefined8 *)(lVar3 + 0x720),
                       "%s: PCIe: RC%d: DRV: error %d unregistering notifier\n",
                       "msm_pcie_drv_rpmsg_remove",*(undefined4 *)(lVar3 + 0x570),iVar1);
      }
      _printk(&DAT_00128a7c,"msm_pcie_drv_rpmsg_remove",*(undefined4 *)(lVar3 + 0x570),iVar1);
    }
    *(undefined8 *)(lVar2 + 200) = 0;
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_drv_rpmsg_cb @ 00119858 size=840
// signature: undefined msm_pcie_drv_rpmsg_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_pcie_drv_rpmsg_cb(long param_1,long param_2,uint param_3)

{
  undefined4 uVar1;
  ushort uVar2;
  uint uVar3;
  undefined *puVar4;
  short sVar5;
  uint uVar6;
  short sVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  if (param_3 != 0) {
    lVar9 = 0;
    lVar10 = *(long *)(param_1 + 0x98);
    uVar3 = param_3;
    do {
      if (uVar3 < 0x18) {
        _printk(&DAT_0012a111,uVar3);
        return 0xffffffea;
      }
      uVar6 = *(uint *)(param_2 + lVar9 + 0xc);
      if (4 < uVar6) {
        _printk(&DAT_00125429);
        return 0xffffffea;
      }
      lVar8 = *(long *)(*(long *)(lVar10 + 0x10) + (ulong)uVar6 * 8);
      lVar11 = *(long *)(lVar8 + 0x790);
      if (lVar11 == 0) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: no device info found\n","msm_pcie_drv_rpmsg_cb",
                         *(undefined4 *)(lVar8 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: DRV: no device info found\n","msm_pcie_drv_rpmsg_cb",
                         *(undefined4 *)(lVar8 + 0x570));
        }
        _printk(&DAT_00122168,"msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
        return 0xffffffed;
      }
      uVar2 = *(ushort *)(param_2 + lVar9 + 4);
      if (uVar2 != 10) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: unsupported command: 0x%x\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: DRV: unsupported command: 0x%x\n","msm_pcie_drv_rpmsg_cb",
                         *(undefined4 *)(lVar8 + 0x570),*(undefined2 *)(param_2 + lVar9 + 4));
          uVar2 = *(ushort *)(param_2 + lVar9 + 4);
        }
        uVar1 = *(undefined4 *)(lVar8 + 0x570);
        puVar4 = &UNK_00123321;
LAB_00119a5c:
        uVar6 = (uint)uVar2;
LAB_00119ac8:
        _printk(puVar4,"msm_pcie_drv_rpmsg_cb",uVar1,uVar6);
        return 0xffffffea;
      }
      uVar2 = *(ushort *)(param_2 + lVar9 + 10);
      if (uVar2 != 4) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: invalid payload size: %d\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: DRV: invalid payload size: %d\n","msm_pcie_drv_rpmsg_cb",
                         *(undefined4 *)(lVar8 + 0x570),*(undefined2 *)(param_2 + lVar9 + 10));
          uVar2 = *(ushort *)(param_2 + lVar9 + 10);
        }
        uVar1 = *(undefined4 *)(lVar8 + 0x570);
        puVar4 = &DAT_0012baac;
        goto LAB_00119a5c;
      }
      uVar6 = uVar3 - 0x18;
      if (uVar6 < 4) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: invalid status length: %d\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570),uVar6);
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: DRV: invalid status length: %d\n","msm_pcie_drv_rpmsg_cb",
                         *(undefined4 *)(lVar8 + 0x570),uVar6);
        }
        uVar1 = *(undefined4 *)(lVar8 + 0x570);
        puVar4 = &DAT_0012fe11;
        goto LAB_00119ac8;
      }
      sVar7 = *(short *)(lVar11 + 0xfa);
      sVar5 = *(short *)(param_2 + lVar9 + 8);
      if (sVar5 != sVar7) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),
                         "ERR:%s: PCIe: RC%d: DRV: incorrect reply seq: %d: expected seq: %d\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),
                         "%s: PCIe: RC%d: DRV: incorrect reply seq: %d: expected seq: %d\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570),
                         *(undefined2 *)(param_2 + lVar9 + 8),*(undefined2 *)(lVar11 + 0xfa));
          sVar5 = *(short *)(param_2 + lVar9 + 8);
          sVar7 = *(short *)(lVar11 + 0xfa);
        }
        _printk(&DAT_00123a09,"msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570),sVar5,sVar7);
        return 0xffffffea;
      }
      if (*(int *)(param_2 + lVar9 + 0x18) != 0) {
        if (lVar8 != 0) {
          ipc_log_string(*(undefined8 *)(lVar8 + 0x728),"ERR:%s: PCIe: RC%d: DRV: invalid status\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
          ipc_log_string(*(undefined8 *)(lVar8 + 0x720),"%s: PCIe: RC%d: DRV: invalid status\n",
                         "msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
        }
        _printk(&DAT_0012695c,"msm_pcie_drv_rpmsg_cb",*(undefined4 *)(lVar8 + 0x570));
        return 0xffffffea;
      }
      complete(lVar11 + 0x100);
      lVar9 = lVar9 + 0x1c;
      uVar3 = uVar3 - 0x1c;
    } while (param_3 != (uint)lVar9);
  }
  return 0;
}



//------------------------------------------------------------
// handle_global_irq @ 00119ba4 size=1476
// signature: undefined handle_global_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 handle_global_irq(undefined4 param_1,long param_2)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  char *pcVar9;
  long lVar10;
  long lVar11;
  ulong uVar12;
  ulong local_78;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  lVar10 = *(long *)(param_2 + 8);
  local_78 = 0;
  uVar6 = _raw_spin_lock_irqsave(param_2 + 0x640);
  if (*(char *)(param_2 + 0x6a0) == '\0') {
    if (*(char *)(param_2 + 0x440) != '\0') {
      uVar3 = readl_relaxed(*(long *)(param_2 + 0x380) + 0x224);
      uVar4 = readl_relaxed(*(long *)(param_2 + 0x380) + 0x22c);
      uVar4 = uVar4 & uVar3;
      lVar11 = *(long *)(param_2 + 0x380) + 0x228;
      uVar3 = readl_relaxed(lVar11);
      writel_relaxed(uVar3 | uVar4,lVar11);
      readl_relaxed(lVar11);
      uVar5 = readl_relaxed(*(long *)(param_2 + 0x380) + 0x500);
      uVar3 = readl_relaxed(*(long *)(param_2 + 0x380) + 0x508);
      uVar3 = uVar3 & uVar5;
      lVar11 = *(long *)(param_2 + 0x380) + 0x504;
      uVar5 = readl_relaxed(lVar11);
      writel_relaxed(uVar5 | uVar3,lVar11);
      readl_relaxed(lVar11);
      if (param_2 != 0) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x730),
                       "DUMP:%s: RC%d: Global IRQ %d received: 0x%x status2: 0x%x\n",
                       "handle_global_irq",*(undefined4 *)(param_2 + 0x570),param_1,uVar4,uVar3);
      }
      uVar12 = 0;
      uVar7 = 1;
      do {
        if ((uVar4 >> (uVar12 & 0x3f) & 1) != 0) {
          switch((int)uVar12) {
          case 1:
            if (param_2 == 0) {
              _DAT_00000680 = _DAT_00000680 + 1;
              if (DAT_00000579 != '\0') goto LAB_00119f34;
LAB_00119f7c:
              if (param_2 == 0) break;
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                             "DBG1:%s: PCIe:Linkdown IRQ for RC%d when the link is not enabled\n",
                             "handle_linkdown_irq",*(undefined4 *)(param_2 + 0x570));
              uVar8 = *(undefined8 *)(param_2 + 0x720);
              pcVar9 = "%s: PCIe:Linkdown IRQ for RC%d when the link is not enabled\n";
            }
            else {
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                             "DBG1:%s: PCIe: RC%d: handle linkdown event.\n","handle_global_irq",
                             *(undefined4 *)(param_2 + 0x570));
              ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                             "%s: PCIe: RC%d: handle linkdown event.\n","handle_global_irq",
                             *(undefined4 *)(param_2 + 0x570));
              lVar11 = *(long *)(param_2 + 0x680) + 1;
              *(long *)(param_2 + 0x680) = lVar11;
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                             "DBG1:%s: PCIe: No. %ld linkdown IRQ for RC%d.\n","handle_linkdown_irq"
                             ,lVar11,*(undefined4 *)(param_2 + 0x570));
              ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                             "%s: PCIe: No. %ld linkdown IRQ for RC%d.\n","handle_linkdown_irq",
                             *(undefined8 *)(param_2 + 0x680),*(undefined4 *)(param_2 + 0x570));
              if (*(char *)(param_2 + 0x579) == '\0') goto LAB_00119f7c;
LAB_00119f34:
              if (*(int *)(param_2 + 0x4b0) != 1) goto LAB_00119f7c;
              if (*(char *)(param_2 + 0x6a0) == '\0') {
                msm_pcie_handle_linkdown(param_2);
                break;
              }
              if (param_2 == 0) break;
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                             "DBG1:%s: PCIe:the link of RC%d is suspending.\n","handle_linkdown_irq"
                             ,*(undefined4 *)(param_2 + 0x570));
              uVar8 = *(undefined8 *)(param_2 + 0x720);
              pcVar9 = "%s: PCIe:the link of RC%d is suspending.\n";
            }
            ipc_log_string(uVar8,pcVar9,"handle_linkdown_irq",*(undefined4 *)(param_2 + 0x570));
            break;
          default:
            if (param_2 != 0) {
              ipc_log_string(*(undefined8 *)(param_2 + 0x730),
                             "DUMP:%s: PCIe: RC%d: Unexpected event %d is caught!\n",
                             "handle_global_irq",*(undefined4 *)(param_2 + 0x570),
                             uVar12 & 0xffffffff);
            }
            break;
          case 9:
            msm_pcie_notify_client(param_2,8);
            break;
          case 0xc:
            if (param_2 != 0) {
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),"DBG1:%s: PCIe: RC%d: FLUSH event.\n",
                             "handle_global_irq",*(undefined4 *)(param_2 + 0x570));
              ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: RC%d: FLUSH event.\n",
                             "handle_global_irq",*(undefined4 *)(param_2 + 0x570));
            }
            queue_work_on(0x20,_system_wq,param_2 + 0x5b0);
            break;
          case 0xe:
          case 0xf:
            if (param_2 == 0) {
              if (lVar10 == 0) goto LAB_0011a11c;
            }
            else {
              ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                             "DBG1:%s: PCIe: RC%d: AER event idx %d.\n","handle_global_irq",
                             *(undefined4 *)(param_2 + 0x570),uVar12 & 0xffffffff);
              ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: RC%d: AER event idx %d.\n",
                             "handle_global_irq",*(undefined4 *)(param_2 + 0x570),
                             uVar12 & 0xffffffff);
              if (lVar10 == 0) {
                ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                               "DBG2:%s: PCIe: RC%d pci_dev is not allocated.\n","handle_global_irq"
                               ,*(undefined4 *)(param_2 + 0x570));
                goto LAB_0011a11c;
              }
            }
            uVar2 = *(ushort *)(lVar10 + 0x4a);
            iVar1 = uVar2 + 0x30;
            pci_read_config_dword(lVar10,iVar1,&local_78);
            if ((local_78 & 5) == 0) {
              uVar7 = 0;
              goto LAB_0011a11c;
            }
            pci_read_config_dword(lVar10,uVar2 + 0x34,(ulong)&local_78 | 4);
            pci_write_config_dword(lVar10,iVar1,local_78 & 0xffffffff);
            if (*(uint *)(param_2 + 0x890) - *(int *)(param_2 + 0x894) <= *(uint *)(param_2 + 0x898)
               ) {
              uVar7 = 2;
              *(ulong *)(param_2 + 0x8a8 +
                        (ulong)(*(uint *)(param_2 + 0x898) & *(uint *)(param_2 + 0x890)) * 8) =
                   local_78;
              DataMemoryBarrier(2,2);
              *(int *)(param_2 + 0x890) = *(int *)(param_2 + 0x890) + 1;
            }
          }
        }
        uVar12 = uVar12 + 1;
      } while (uVar12 != 0x1f);
      if ((uVar3 >> 0x19 & 1) != 0) {
        lVar11 = *(long *)(param_2 + 8);
        lVar10 = *(long *)(param_2 + 0x380) + 0x508;
        uVar4 = readl_relaxed(lVar10);
        writel_relaxed(uVar4 & 0xfdffffff,lVar10);
        readl_relaxed(lVar10);
        local_6c = 0;
        iVar1 = *(byte *)(lVar11 + 0x6c) + 0x10;
        pci_read_config_dword(lVar11,iVar1,&local_6c);
        local_6c = local_6c & 0xfffffbff;
        pci_write_config_dword(lVar11,iVar1);
        lVar10 = *(long *)(param_2 + 8);
        local_6c = 0;
        iVar1 = *(byte *)(lVar10 + 0x6c) + 0x10;
        pci_read_config_dword(lVar10,iVar1,&local_6c);
        local_6c = local_6c & 0xfffffbff;
        pci_write_config_dword(lVar10,iVar1);
        lVar10 = *(long *)(param_2 + 0x380) + 0x504;
        uVar4 = readl_relaxed(lVar10);
        writel_relaxed(uVar4 | 0x2000000,lVar10);
        readl_relaxed(lVar10);
        if (param_2 != 0) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x728),
                         "DBG1:%s: PCIe: RC%d: Speed change interrupt received.\n",
                         "handle_global_irq",*(undefined4 *)(param_2 + 0x570));
          ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                         "%s: PCIe: RC%d: Speed change interrupt received.\n","handle_global_irq",
                         *(undefined4 *)(param_2 + 0x570));
        }
        complete(param_2 + 0x860);
      }
      goto LAB_0011a11c;
    }
    if (param_2 == 0) goto LAB_0011a0e8;
    uVar7 = *(undefined8 *)(param_2 + 0x720);
    pcVar9 = "DBG2:%s: PCIe: RC%d: Either in drv suspend or res init not done\n";
  }
  else {
    if (param_2 == 0) {
LAB_0011a0e8:
      uVar7 = 1;
      goto LAB_0011a11c;
    }
    uVar7 = *(undefined8 *)(param_2 + 0x720);
    pcVar9 = "DBG2:%s: PCIe: RC%d is currently suspending.\n";
  }
  ipc_log_string(uVar7,pcVar9,"handle_global_irq",*(undefined4 *)(param_2 + 0x570));
  uVar7 = 1;
LAB_0011a11c:
  _raw_spin_unlock_irqrestore(param_2 + 0x640,uVar6);
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// handle_aer_irq @ 0011a16c size=524
// signature: undefined handle_aer_irq(void)
// callers: []
//------------------------------------------------------------

void handle_aer_irq(undefined8 param_1,long param_2)

{
  long lVar1;
  uint *puVar2;
  long lVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  uint uVar7;
  long lVar8;
  uint uVar9;
  long local_c0 [6];
  undefined4 uStack_90;
  uint local_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar7 = *(uint *)(param_2 + 0x894);
  if (*(uint *)(param_2 + 0x890) == uVar7) {
    uVar5 = 0;
  }
  else {
    lVar1 = param_2 + 0x444;
    do {
      puVar2 = (uint *)(param_2 + 0x8a8 + (ulong)(*(uint *)(param_2 + 0x898) & uVar7) * 8);
      uVar7 = *puVar2;
      uVar4 = puVar2[1];
      DataMemoryBarrier(2,2);
      *(int *)(param_2 + 0x894) = *(int *)(param_2 + 0x894) + 1;
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      *(undefined8 *)(param_2 + 0x448) = uVar5;
      if (*(char *)(param_2 + 0x440) == '\0') {
        if (param_2 != 0) {
          ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                         "DBG2:%s: PCIe: RC%d is currently in drv suspend.\n","handle_aer_irq",
                         *(undefined4 *)(param_2 + 0x570));
          uVar5 = *(undefined8 *)(param_2 + 0x448);
        }
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        break;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar5);
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_c0[5] = 0;
      _uStack_90 = 0;
      lVar8 = *(long *)(*(long *)(param_2 + 8) + 0x50);
      local_c0[3] = 0;
      local_c0[4] = 0;
      local_c0[1] = 0;
      local_c0[2] = 0;
      if (lVar8 != 0) {
        if ((uVar7 & 1) != 0) {
          *(long *)(lVar8 + 0x248) = *(long *)(lVar8 + 0x248) + 1;
        }
        if ((uVar7 >> 2 & 1) != 0) {
          lVar3 = 600;
          if ((uVar7 & 0x40) != 0) {
            lVar3 = 0x250;
          }
          *(long *)(lVar8 + lVar3) = *(long *)(lVar8 + lVar3) + 1;
        }
      }
      local_c0[0] = param_2;
      if ((uVar7 & 1) != 0) {
        uVar9 = 0x20000;
        if ((uVar7 & 2) != 0) {
          uVar9 = 0x820000;
        }
        _uStack_90 = (ulong)(uVar9 | uVar4 & 0xffff) << 0x20;
        msm_aer_print_port_info(*(undefined8 *)(param_2 + 8),local_c0);
        uVar6 = msm_find_source_device(*(undefined8 *)(param_2 + 8),local_c0);
        if ((uVar6 & 1) != 0) {
          msm_aer_process_err_devices(local_c0);
        }
      }
      if ((uVar7 >> 2 & 1) != 0) {
        uVar4 = (uVar7 & 0x40) << 10 | uVar4 >> 0x10;
        uVar9 = uVar4 | local_8c & 0xff7c0000;
        if ((uVar7 & 8) != 0) {
          uVar9 = uVar4 | local_8c & 0xfffc0000 | 0x800000;
        }
        _uStack_90 = CONCAT44(uVar9,uStack_90);
        msm_aer_print_port_info(*(undefined8 *)(param_2 + 8),local_c0);
        uVar6 = msm_find_source_device(*(undefined8 *)(param_2 + 8),local_c0);
        if ((uVar6 & 1) != 0) {
          msm_aer_process_err_devices(local_c0);
        }
      }
      uVar7 = *(uint *)(param_2 + 0x894);
    } while (*(uint *)(param_2 + 0x890) != uVar7);
    uVar5 = 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// handle_wake_irq @ 0011a37c size=456
// signature: undefined handle_wake_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 handle_wake_irq(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar3 = _raw_spin_lock_irqsave(param_2 + 0x640);
  lVar1 = *(long *)(param_2 + 0x6a8) + 1;
  *(long *)(param_2 + 0x6a8) = lVar1;
  if (param_2 != 0) {
    ipc_log_string(*(undefined8 *)(param_2 + 0x728),"DBG1:%s: PCIe: No. %ld wake IRQ for RC%d\n",
                   "handle_wake_irq",lVar1,*(undefined4 *)(param_2 + 0x570));
    ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: PCIe: No. %ld wake IRQ for RC%d\n",
                   "handle_wake_irq",*(undefined8 *)(param_2 + 0x6a8),
                   *(undefined4 *)(param_2 + 0x570));
    ipc_log_string(*(undefined8 *)(param_2 + 0x720),
                   "DBG2:%s: PCIe WAKE is asserted by Endpoint of RC%d\n","handle_wake_irq",
                   *(undefined4 *)(param_2 + 0x570));
  }
  if ((*(char *)(param_2 + 0x579) == '\0') && ((*(byte *)(param_2 + 0x558) >> 1 & 1) == 0)) {
    if (param_2 != 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x728),"DBG1:%s: Start enumerating RC%d\n",
                     "handle_wake_irq",*(undefined4 *)(param_2 + 0x570));
      ipc_log_string(*(undefined8 *)(param_2 + 0x720),"%s: Start enumerating RC%d\n",
                     "handle_wake_irq",*(undefined4 *)(param_2 + 0x570));
    }
    queue_work_on(0x20,_system_wq,param_2 + 0x580);
  }
  else {
    if (param_2 != 0) {
      ipc_log_string(*(undefined8 *)(param_2 + 0x720),"DBG2:%s: Wake up RC%d\n","handle_wake_irq",
                     *(undefined4 *)(param_2 + 0x570));
    }
    __pm_stay_awake(*(undefined8 *)(param_2 + 0x4c8));
    __pm_relax(*(undefined8 *)(param_2 + 0x4c8));
    if (((*(char *)(param_2 + 0x888) != '\0') && (*(char *)(param_2 + 0x6a0) == '\0')) &&
       (*(int *)(param_2 + 0x4b0) == 1)) {
      pcie_phy_dump(param_2);
      pcie_parf_dump(param_2);
      pcie_dm_core_dump(param_2);
      pcie_sm_dump(param_2);
      if (((*(long *)(param_2 + 0xd00) != 0) && (iVar2 = crm_dump_regs("pcie_crm"), param_2 != 0))
         && (iVar2 != 0)) {
        ipc_log_string(*(undefined8 *)(param_2 + 0x730),
                       "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n","pcie_crm_dump",
                       *(undefined4 *)(param_2 + 0x570),iVar2);
      }
    }
    msm_pcie_notify_client(param_2,4);
  }
  _raw_spin_unlock_irqrestore(param_2 + 0x640,uVar3);
  return 1;
}



//------------------------------------------------------------
// handle_wake_func @ 0011a548 size=416
// signature: undefined handle_wake_func(void)
// callers: []
//------------------------------------------------------------

void handle_wake_func(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if (param_1 + -0x580 == 0) {
    mutex_lock(param_1 + 0x90);
    if (*(char *)(param_1 + -7) != '\0') goto LAB_0011a6cc;
    iVar2 = msm_pcie_enumerate(*(undefined4 *)(param_1 + -0x10));
    if (iVar2 == 0) goto LAB_0011a660;
LAB_0011a68c:
    uVar1 = *(undefined4 *)(param_1 + -0x10);
    puVar3 = &DAT_0012225b;
  }
  else {
    puVar4 = (undefined4 *)(param_1 + -0x10);
    ipc_log_string(*(undefined8 *)(param_1 + 0x1a8),"DBG1:%s: PCIe: Wake work for RC%d\n",
                   "handle_wake_func",*puVar4);
    ipc_log_string(*(undefined8 *)(param_1 + 0x1a0),"%s: PCIe: Wake work for RC%d\n",
                   "handle_wake_func",*puVar4);
    mutex_lock(param_1 + 0x90);
    if (*(char *)(param_1 + -7) == '\0') {
      ipc_log_string(*(undefined8 *)(param_1 + 0x1a8),
                     "DBG1:%s: PCIe: Start enumeration for RC%d upon the wake from endpoint.\n",
                     "handle_wake_func",*puVar4);
      ipc_log_string(*(undefined8 *)(param_1 + 0x1a0),
                     "%s: PCIe: Start enumeration for RC%d upon the wake from endpoint.\n",
                     "handle_wake_func",*(undefined4 *)(param_1 + -0x10));
      iVar2 = msm_pcie_enumerate(*(undefined4 *)(param_1 + -0x10));
      if (iVar2 == 0) {
LAB_0011a660:
        msm_pcie_notify_client(param_1 + -0x580,2);
        goto LAB_0011a66c;
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x1a8),
                     "ERR:%s: PCIe: failed to enable RC%d upon wake request from the device.\n",
                     "handle_wake_func",*(undefined4 *)(param_1 + -0x10));
      ipc_log_string(*(undefined8 *)(param_1 + 0x1a0),
                     "%s: PCIe: failed to enable RC%d upon wake request from the device.\n",
                     "handle_wake_func",*(undefined4 *)(param_1 + -0x10));
      goto LAB_0011a68c;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x1a8),
                   "ERR:%s: PCIe: The enumeration for RC%d has already been done.\n",
                   "handle_wake_func",*puVar4);
    ipc_log_string(*(undefined8 *)(param_1 + 0x1a0),
                   "%s: PCIe: The enumeration for RC%d has already been done.\n","handle_wake_func",
                   *(undefined4 *)(param_1 + -0x10));
LAB_0011a6cc:
    uVar1 = *(undefined4 *)(param_1 + -0x10);
    puVar3 = &DAT_0012d92f;
  }
  _printk(puVar3,"handle_wake_func",uVar1);
LAB_0011a66c:
  mutex_unlock(param_1 + 0x90);
  return;
}



//------------------------------------------------------------
// handle_sbr_func @ 0011a6ec size=1556
// signature: undefined handle_sbr_func(void)
// callers: []
//------------------------------------------------------------

void handle_sbr_func(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  long *plVar9;
  char *pcVar10;
  char *pcVar11;
  
  if (param_1 != 0x5b0) {
    ipc_log_string(*(undefined8 *)(param_1 + 0x178),"DBG1:%s: PCIe: SBR work for RC%d\n",
                   "handle_sbr_func",*(undefined4 *)(param_1 + -0x40));
    ipc_log_string(*(undefined8 *)(param_1 + 0x170),"%s: PCIe: SBR work for RC%d\n",
                   "handle_sbr_func",*(undefined4 *)(param_1 + -0x40));
  }
  plVar9 = (long *)(param_1 + -0x280);
  if (*plVar9 != 0) {
    iVar3 = reset_control_assert();
    if (iVar3 == 0) {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n","handle_sbr_func"
                       ,*(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
      }
    }
    else {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),
                       "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "%s: PCIe: RC%d failed to assert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
      }
      _printk(&DAT_0012cc3a,"handle_sbr_func",*(undefined4 *)(param_1 + -0x40),
              *(undefined8 *)(param_1 + -0x278));
    }
  }
  if (*(long *)(param_1 + -0x268) != 0) {
    iVar3 = reset_control_assert();
    if (iVar3 == 0) {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "DBG2:%s: PCIe: RC%d successfully asserted reset for %s.\n","handle_sbr_func"
                       ,*(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x260));
      }
    }
    else {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),
                       "ERR:%s: PCIe: RC%d failed to assert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x260));
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "%s: PCIe: RC%d failed to assert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x260));
      }
      _printk(&DAT_0012cc3a,"handle_sbr_func",*(undefined4 *)(param_1 + -0x40),
              *(undefined8 *)(param_1 + -0x260));
    }
  }
  usleep_range_state(1000,0x3ed,2);
  if (*(long *)(param_1 + -0x268) == 0) {
LAB_0011a8e8:
    if (*plVar9 == 0) goto joined_r0x0011aa04;
LAB_0011a968:
    iVar3 = reset_control_deassert();
    if (iVar3 != 0) {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),
                       "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "%s: PCIe: RC%d failed to deassert reset for %s.\n","handle_sbr_func",
                       *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
      }
      _printk(&DAT_0012f9c2,"handle_sbr_func",*(undefined4 *)(param_1 + -0x40),
              *(undefined8 *)(param_1 + -0x278));
      goto joined_r0x0011aa04;
    }
    if (param_1 == 0x5b0) goto LAB_0011aa64;
    ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                   "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n","handle_sbr_func",
                   *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x278));
  }
  else {
    iVar3 = reset_control_deassert();
    if (iVar3 == 0) {
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                       "DBG2:%s: PCIe: RC%d successfully deasserted reset for %s.\n",
                       "handle_sbr_func",*(undefined4 *)(param_1 + -0x40),
                       *(undefined8 *)(param_1 + -0x260));
      }
      goto LAB_0011a8e8;
    }
    if (param_1 != 0x5b0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x178),
                     "ERR:%s: PCIe: RC%d failed to deassert reset for %s.\n","handle_sbr_func",
                     *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x260));
      ipc_log_string(*(undefined8 *)(param_1 + 0x170),
                     "%s: PCIe: RC%d failed to deassert reset for %s.\n","handle_sbr_func",
                     *(undefined4 *)(param_1 + -0x40),*(undefined8 *)(param_1 + -0x260));
    }
    _printk(&DAT_0012f9c2,"handle_sbr_func",*(undefined4 *)(param_1 + -0x40),
            *(undefined8 *)(param_1 + -0x260));
    if (*plVar9 != 0) goto LAB_0011a968;
joined_r0x0011aa04:
    if (param_1 == 0x5b0) goto LAB_0011aa64;
  }
  uVar7 = *(undefined8 *)(param_1 + 0x178);
  uVar4 = readl_relaxed(*(long *)(param_1 + -0x230) + 0x1b0);
  ipc_log_string(uVar7,"DBG1:%s: post reset ltssm:%x\n","handle_sbr_func",uVar4);
  uVar7 = *(undefined8 *)(param_1 + 0x170);
  uVar4 = readl_relaxed(*(long *)(param_1 + -0x230) + 0x1b0);
  ipc_log_string(uVar7,"%s: post reset ltssm:%x\n","handle_sbr_func",uVar4);
LAB_0011aa64:
  lVar1 = *(long *)(param_1 + -0x230) + 0x1b0;
  uVar5 = readl_relaxed(lVar1);
  writel_relaxed(uVar5 | 0x100,lVar1);
  readl_relaxed(lVar1);
  uVar5 = 0;
  do {
    uVar6 = readl_relaxed(*(long *)(param_1 + -0x220) + 8);
    if (param_1 != 0x5b0) {
      uVar2 = uVar6 >> 0xc & 0x3f;
      if (uVar2 < 0x24) {
        pcVar11 = (&msm_pcie_ltssm_str)[uVar2];
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),"DBG1:%s: PCIe RC%d: LTSSM_STATE: %x %s\n",
                       "handle_sbr_func",*(undefined4 *)(param_1 + -0x40),uVar6,pcVar11);
      }
      else {
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),"DBG1:%s: PCIe RC%d: LTSSM_STATE: %x %s\n",
                       "handle_sbr_func",*(undefined4 *)(param_1 + -0x40),uVar6,"LTSSM_INVALID");
        pcVar11 = "LTSSM_INVALID";
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x170),"%s: PCIe RC%d: LTSSM_STATE: %x %s\n",
                     "handle_sbr_func",*(undefined4 *)(param_1 + -0x40),uVar6,pcVar11);
    }
    usleep_range_state(10000,11000,2);
    if ((uVar6 >> 10 & 1) == 0) {
      if (9 < uVar5) {
        puVar8 = &DAT_00129e8b;
        if (param_1 == 0x5b0) goto LAB_0011accc;
        goto LAB_0011ac3c;
      }
    }
    else {
      uVar6 = readl_relaxed(*(long *)(param_1 + -0x210) + 0x80);
      if ((uVar6 >> 0x1d & 1) != 0) goto LAB_0011abb4;
      if (param_1 != 0x5b0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x178),
                       "DBG1:%s: PCIe: The link of RC %d is not up.\n","msm_pcie_confirm_linkup",
                       *(undefined4 *)(param_1 + -0x40));
        ipc_log_string(*(undefined8 *)(param_1 + 0x170),"%s: PCIe: The link of RC %d is not up.\n",
                       "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + -0x40));
      }
      if (9 < uVar5) break;
    }
    uVar5 = uVar5 + 1;
  } while( true );
  uVar5 = 0xb;
LAB_0011abb4:
  uVar6 = readl_relaxed(*(long *)(param_1 + -0x210) + 0x80);
  if ((uVar6 >> 0x1d & 1) == 0) {
    if (param_1 == 0x5b0) {
      puVar8 = &DAT_00129e8b;
      goto LAB_0011accc;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x178),"DBG1:%s: PCIe: The link of RC %d is not up.\n",
                   "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + -0x40));
    ipc_log_string(*(undefined8 *)(param_1 + 0x170),"%s: PCIe: The link of RC %d is not up.\n",
                   "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + -0x40));
LAB_0011ac3c:
    puVar8 = &DAT_00129e8b;
    pcVar10 = "%s: PCIe RC%d link initialization failed\n";
    pcVar11 = "ERR:%s: PCIe RC%d link initialization failed\n";
  }
  else {
    *(undefined4 *)(param_1 + -0x100) = 1;
    if (param_1 == 0x5b0) {
      puVar8 = &DAT_0012aef7;
      goto LAB_0011accc;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x178),"DBG1:%s: Link is up after %d checkings\n",
                   "handle_sbr_func",uVar5);
    ipc_log_string(*(undefined8 *)(param_1 + 0x170),"%s: Link is up after %d checkings\n",
                   "handle_sbr_func",uVar5);
    puVar8 = &DAT_0012aef7;
    pcVar10 = "%s: PCIe RC%d link initialized\n";
    pcVar11 = "INFO:%s: PCIe RC%d link initialized\n";
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x178),pcVar11,"handle_sbr_func",
                 *(undefined4 *)(param_1 + -0x40));
  ipc_log_string(*(undefined8 *)(param_1 + 0x170),pcVar10,"handle_sbr_func",
                 *(undefined4 *)(param_1 + -0x40));
LAB_0011accc:
  _printk(puVar8,"handle_sbr_func",*(undefined4 *)(param_1 + -0x40));
  return;
}



//------------------------------------------------------------
// msm_aer_print_port_info @ 0011ad00 size=272
// signature: undefined msm_aer_print_port_info(void)
// callers: [handle_aer_irq]
//------------------------------------------------------------

void msm_aer_print_port_info(long param_1,long *param_2)

{
  char *pcVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = *param_2;
  if (lVar4 == 0) {
    return;
  }
  uVar2 = *(uint *)((long)param_2 + 0x34);
  uVar5 = (ulong)(uVar2 >> 0x10) & 3;
  if ((int)uVar5 != 3) {
    pcVar1 = "";
    if ((uVar2 & 0x800000) != 0) {
      pcVar1 = "Multiple ";
    }
    ipc_log_string(*(undefined8 *)(lVar4 + 0x728),
                   "DBG1:%s: PCIe: RC%d: %s%s error received: %04x:%02x:%02x.%d\n",
                   "msm_aer_print_port_info",*(undefined4 *)(lVar4 + 0x570),pcVar1,
                   (&aer_error_severity_string)[uVar5],
                   *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xfc),uVar2 >> 8 & 0xff,
                   uVar2 >> 3 & 0x1f,uVar2 & 7);
    uVar2 = *(uint *)((long)param_2 + 0x34);
    uVar5 = (ulong)(uVar2 >> 0x10) & 3;
    if ((int)uVar5 != 3) {
      pcVar1 = "";
      if ((uVar2 & 0x800000) != 0) {
        pcVar1 = "Multiple ";
      }
      ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                     "%s: PCIe: RC%d: %s%s error received: %04x:%02x:%02x.%d\n",
                     "msm_aer_print_port_info",*(undefined4 *)(*param_2 + 0x570),pcVar1,
                     (&aer_error_severity_string)[uVar5],
                     *(undefined4 *)(*(long *)(param_1 + 0x10) + 0xfc),uVar2 >> 8 & 0xff,
                     uVar2 >> 3 & 0x1f,uVar2 & 7);
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x11ae10);
  (*pcVar3)();
}



//------------------------------------------------------------
// msm_find_source_device @ 0011ae10 size=168
// signature: undefined msm_find_source_device(void)
// callers: [handle_aer_irq]
//------------------------------------------------------------

undefined8 msm_find_source_device(long param_1,long *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  *(undefined4 *)(param_2 + 6) = 0;
  iVar1 = msm_find_device_iter();
  if ((iVar1 == 0) &&
     (pci_walk_bus(*(undefined8 *)(param_1 + 0x18),msm_find_device_iter,param_2),
     (int)param_2[6] == 0)) {
    lVar3 = *param_2;
    if (lVar3 != 0) {
      ipc_log_string(*(undefined8 *)(lVar3 + 0x728),
                     "DBG1:%s: PCIe: RC%d: can\'t find device of ID%04x\n","msm_find_source_device",
                     *(undefined4 *)(lVar3 + 0x570),*(undefined2 *)((long)param_2 + 0x34));
      ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                     "%s: PCIe: RC%d: can\'t find device of ID%04x\n","msm_find_source_device",
                     *(undefined4 *)(*param_2 + 0x570),*(undefined2 *)((long)param_2 + 0x34));
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_aer_process_err_devices @ 0011aeb8 size=852
// signature: undefined msm_aer_process_err_devices(void)
// callers: [handle_aer_irq]
//------------------------------------------------------------

void msm_aer_process_err_devices(long *param_1)

{
  bool bVar1;
  long lVar2;
  ushort uVar3;
  uint uVar4;
  ushort uVar5;
  code *pcVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  uint uVar10;
  long lVar11;
  long lVar12;
  undefined8 local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  if ((int)param_1[6] < 1) goto LAB_0011b1b8;
  if (param_1[1] != 0) {
    iVar7 = msm_aer_get_device_error_info(param_1[1],param_1);
    if (iVar7 != 0) {
      msm_aer_print_error(param_1[1],param_1);
    }
    iVar7 = (int)param_1[6];
    if (1 < iVar7) {
      if (param_1[2] == 0) goto LAB_0011afdc;
      iVar7 = msm_aer_get_device_error_info(param_1[2],param_1);
      if (iVar7 != 0) {
        msm_aer_print_error(param_1[2],param_1);
      }
      iVar7 = (int)param_1[6];
      if (2 < iVar7) {
        if (param_1[3] == 0) goto LAB_0011afdc;
        iVar7 = msm_aer_get_device_error_info(param_1[3],param_1);
        if (iVar7 != 0) {
          msm_aer_print_error(param_1[3],param_1);
        }
        iVar7 = (int)param_1[6];
        if (3 < iVar7) {
          if (param_1[4] == 0) goto LAB_0011afdc;
          iVar7 = msm_aer_get_device_error_info(param_1[4],param_1);
          if (iVar7 != 0) {
            msm_aer_print_error(param_1[4],param_1);
          }
          iVar7 = (int)param_1[6];
          if (4 < iVar7) {
            if (param_1[5] == 0) goto LAB_0011afdc;
            iVar7 = msm_aer_get_device_error_info(param_1[5],param_1);
            if (iVar7 != 0) {
              msm_aer_print_error(param_1[5],param_1);
            }
            iVar7 = (int)param_1[6];
            if (5 < iVar7) {
LAB_0011b1f0:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x11b1f4);
              (*pcVar6)();
            }
          }
        }
      }
    }
    if (iVar7 < 1) goto LAB_0011b1b8;
  }
LAB_0011afdc:
  lVar9 = 1;
  do {
    if (lVar9 == 6) goto LAB_0011b1f0;
    if (param_1[lVar9] == 0) break;
    iVar7 = msm_aer_get_device_error_info(param_1[lVar9],param_1);
    if (iVar7 != 0) {
      lVar11 = param_1[lVar9];
      local_70 = 0;
      lVar12 = *param_1;
      uVar5 = *(ushort *)(lVar11 + 0x4a);
      if ((((*(char *)(lVar12 + 0xca8) == '\0') && (*(char *)(lVar12 + 0x6a0) == '\0')) &&
          (*(int *)(lVar12 + 0x4b0) == 1)) &&
         ((*(undefined1 *)(lVar12 + 0xca8) = 1,
          (*(uint *)((long)param_1 + 0x34) & 0x30000) != 0x20000 ||
          (*(char *)(lVar12 + 0xca9) != '\0')))) {
        lVar2 = lVar12 + 0x444;
        uVar8 = _raw_spin_lock_irqsave(lVar2);
        *(undefined8 *)(lVar12 + 0x448) = uVar8;
        if (*(char *)(lVar12 + 0x440) == '\0') {
          if (lVar12 != 0) {
            ipc_log_string(*(undefined8 *)(lVar12 + 0x720),
                           "DBG2:%s: PCIe: RC%d is currently in drv suspend.\n",
                           "msm_handle_error_source",*(undefined4 *)(lVar12 + 0x570));
            uVar8 = *(undefined8 *)(lVar12 + 0x448);
          }
          _raw_spin_unlock_irqrestore(lVar2,uVar8);
          goto LAB_0011b020;
        }
        pcie_parf_dump(lVar12);
        pcie_dm_core_dump(lVar12);
        pcie_phy_dump(lVar12);
        pcie_sm_dump(lVar12);
        if (((*(long *)(lVar12 + 0xd00) != 0) && (iVar7 = crm_dump_regs("pcie_crm"), lVar12 != 0))
           && (iVar7 != 0)) {
          ipc_log_string(*(undefined8 *)(lVar12 + 0x730),
                         "DUMP:%s: PCIe: RC%d Error dumping crm regs %d\n","pcie_crm_dump",
                         *(undefined4 *)(lVar12 + 0x570),iVar7);
        }
        _raw_spin_unlock_irqrestore(lVar2,*(undefined8 *)(lVar12 + 0x448));
        if (*(char *)(lVar12 + 0xca9) != '\0') {
          uVar3 = *(ushort *)((long)param_1 + 0x36) & 3;
          goto LAB_0011b200;
        }
      }
      uVar3 = *(ushort *)((long)param_1 + 0x36) & 3;
      uVar10 = (uint)uVar5;
      if ((*(ushort *)((long)param_1 + 0x36) & 3) == 0) {
        if (uVar10 != 0) {
          iVar7 = uVar10 + 4;
          pci_read_config_dword(lVar11,iVar7,(long)&local_70 + 4);
          pci_read_config_dword(lVar11,uVar10 + 0xc,&local_70);
          uVar4 = local_70._4_4_ & ((uint)local_70 ^ 0xffffffff);
          local_70 = CONCAT44(uVar4,(uint)local_70);
          if (uVar4 != 0) goto LAB_0011b000;
        }
      }
      else {
        if (uVar3 != 2) {
LAB_0011b200:
                    /* WARNING: Subroutine does not return */
          panic("AER error severity %d\n",uVar3);
        }
        if (uVar10 != 0) {
          uVar4 = *(uint *)(param_1 + 7);
          iVar7 = uVar10 + 0x10;
LAB_0011b000:
          pci_write_config_dword(lVar11,iVar7,uVar4);
        }
      }
      pcie_capability_clear_and_set_word(lVar11,10,0,7);
      pci_dev_put(lVar11);
    }
LAB_0011b020:
    bVar1 = lVar9 < (int)param_1[6];
    lVar9 = lVar9 + 1;
  } while (bVar1);
LAB_0011b1b8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_find_device_iter @ 0011b210 size=360
// signature: undefined msm_find_device_iter(void)
// callers: [msm_find_source_device]
//------------------------------------------------------------

void msm_find_device_iter(long param_1,long param_2)

{
  uint uVar1;
  ushort uVar2;
  long lVar3;
  code *pcVar4;
  bool bVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  ushort local_44 [2];
  uint local_40;
  uint local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  uVar1 = *(uint *)(param_2 + 0x34);
  local_3c = 0;
  uVar2 = *(ushort *)(param_1 + 0x4a);
  local_40 = 0;
  local_44[0] = 0;
  if (((uVar1 & 0xff00) == 0) || ((*(ushort *)(*(long *)(param_1 + 0x10) + 0x132) >> 2 & 1) != 0)) {
LAB_0011b280:
    if (((*(int *)(param_1 + 0xad0) != 0) &&
        (pcie_capability_read_word(param_1,8,local_44), (local_44[0] & 0xf) != 0)) && (uVar2 != 0))
    {
      bVar5 = (*(uint *)(param_2 + 0x34) & 0x30000) != 0x20000;
      iVar7 = 0x10;
      if (bVar5) {
        iVar7 = 4;
      }
      iVar8 = 0x14;
      if (bVar5) {
        iVar8 = 8;
      }
      pci_read_config_dword(param_1,iVar7 + (uint)uVar2,&local_3c);
      pci_read_config_dword(param_1,iVar8 + (uint)uVar2,&local_40);
      if ((local_3c & (local_40 ^ 0xffffffff)) != 0) goto LAB_0011b2fc;
    }
  }
  else {
    if ((uVar1 & 0xffff) ==
        (*(uint *)(param_1 + 0x38) | (uint)*(byte *)(*(long *)(param_1 + 0x10) + 0xf8) << 8)) {
LAB_0011b2fc:
      if (*(int *)(param_2 + 0x30) < 5) {
        uVar6 = pci_dev_get(param_1);
        if (4 < *(uint *)(param_2 + 0x30)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x11b378);
          (*pcVar4)();
        }
        *(undefined8 *)(param_2 + (ulong)*(uint *)(param_2 + 0x30) * 8 + 8) = uVar6;
        *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + 1;
        if (*(char *)(param_2 + 0x36) < '\0') goto LAB_0011b340;
      }
      uVar6 = 1;
      goto LAB_0011b344;
    }
    if ((uVar1 >> 0x17 & 1) != 0) goto LAB_0011b280;
  }
LAB_0011b340:
  uVar6 = 0;
LAB_0011b344:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// msm_aer_get_device_error_info @ 0011b378 size=572
// signature: undefined msm_aer_get_device_error_info(void)
// callers: [msm_aer_process_err_devices]
//------------------------------------------------------------

void msm_aer_get_device_error_info(long param_1,long *param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort uVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  uint uVar8;
  uint local_4c;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  uVar1 = *(ushort *)(param_1 + 0x72);
  local_4c = 0;
  uVar2 = *(ushort *)(param_1 + 0x4a);
  plVar7 = param_2 + 7;
  *(undefined4 *)plVar7 = 0;
  *(uint *)((long)param_2 + 0x34) = *(uint *)((long)param_2 + 0x34) & 0x7fffffff;
  if (uVar2 != 0) {
    uVar4 = pci_find_ext_capability(param_1,0x1e);
    if (uVar4 != 0) {
      uVar8 = (uint)uVar2;
      if ((*(ushort *)((long)param_2 + 0x36) & 3) == 2) {
        pci_read_config_dword(param_1,uVar8 + 0x10,plVar7);
        pci_read_config_dword(param_1,uVar8 + 0x14,(long)param_2 + 0x3c);
        pci_read_config_dword(param_1,uVar4 + 8,param_2 + 10);
        pcie_capability_read_word(param_1,0x12,(long)param_2 + 0x54);
        if ((*(uint *)(param_2 + 7) & (*(uint *)((long)param_2 + 0x3c) ^ 0xffffffff)) == 0)
        goto LAB_0011b570;
      }
      else {
        uVar3 = uVar1 >> 4 & 0xf;
        if (((uVar3 < 0xb) && ((1 << (ulong)uVar3 & 0x450U) != 0)) ||
           ((*(ushort *)((long)param_2 + 0x36) & 3) == 0)) {
          pci_read_config_dword(param_1,uVar2 + 4,plVar7);
          pci_read_config_dword(param_1,uVar8 + 8,(long)param_2 + 0x3c);
          pci_read_config_dword(param_1,uVar4 + 8,param_2 + 10);
          pcie_capability_read_word(param_1,0x12,(long)param_2 + 0x54);
          if ((*(uint *)(param_2 + 7) & (*(uint *)((long)param_2 + 0x3c) ^ 0xffffffff)) == 0)
          goto LAB_0011b570;
          pci_read_config_dword(param_1,uVar8 + 0x18,&local_4c);
          uVar3 = *(uint *)((long)param_2 + 0x34) & 0xe0000000 |
                  *(uint *)((long)param_2 + 0x34) & 0xffffff | (local_4c & 0x1f) << 0x18;
          *(uint *)((long)param_2 + 0x34) = uVar3;
          if ((*(uint *)(param_2 + 7) & 0x1d9000) != 0) {
            *(uint *)((long)param_2 + 0x34) = uVar3 | 0x80000000;
            pci_read_config_dword(param_1,uVar8 + 0x1c,param_2 + 8);
            pci_read_config_dword(param_1,uVar8 + 0x20,(long)param_2 + 0x44);
            pci_read_config_dword(param_1,uVar8 + 0x24,param_2 + 9);
            pci_read_config_dword(param_1,uVar8 + 0x28,(long)param_2 + 0x4c);
          }
        }
      }
      uVar5 = 1;
      goto LAB_0011b580;
    }
    lVar6 = *param_2;
    if (lVar6 != 0) {
      ipc_log_string(*(undefined8 *)(lVar6 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Could not read l1ss cap reg offset\n",
                     "msm_aer_get_device_error_info",*(undefined4 *)(lVar6 + 0x570));
      ipc_log_string(*(undefined8 *)(*param_2 + 0x720),
                     "%s: PCIe: RC%d: Could not read l1ss cap reg offset\n",
                     "msm_aer_get_device_error_info",*(undefined4 *)(*param_2 + 0x570));
      uVar5 = 0;
      goto LAB_0011b580;
    }
  }
LAB_0011b570:
  uVar5 = 0;
LAB_0011b580:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// msm_pcie_confirm_linkup @ 0011b5b4 size=360
// signature: undefined msm_pcie_confirm_linkup(void)
// callers: [msm_pcie_pm_suspend]
//------------------------------------------------------------

undefined8 msm_pcie_confirm_linkup(long param_1,ulong param_2,ulong param_3,long param_4)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if (((param_2 & 1) == 0) || (*(int *)(param_1 + 0x4b0) == 1)) {
    uVar1 = readl_relaxed(*(long *)(param_1 + 0x3a0) + 0x80);
    if ((uVar1 >> 0x1d & 1) != 0) {
      if (((param_3 & 1) == 0) || (uVar3 = pci_device_is_present(param_4), (uVar3 & 1) != 0)) {
        return 1;
      }
      if (param_1 != 0) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                       "ERR:%s: PCIe: RC%d: Config space access failed for BDF 0x%04x\n",
                       "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + 0x570),
                       *(uint *)(param_4 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_4 + 0x10) + 0xf8) << 8);
        ipc_log_string(*(undefined8 *)(param_1 + 0x720),
                       "%s: PCIe: RC%d: Config space access failed for BDF 0x%04x\n",
                       "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + 0x570),
                       *(uint *)(param_4 + 0x38) |
                       (uint)*(byte *)(*(long *)(param_4 + 0x10) + 0xf8) << 8);
      }
      _printk(&DAT_001242d5,"msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + 0x570),
              *(uint *)(param_4 + 0x38) | (uint)*(byte *)(*(long *)(param_4 + 0x10) + 0xf8) << 8);
      return 0;
    }
    if (param_1 == 0) {
      return 0;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: PCIe: The link of RC %d is not up.\n",
                   "msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + 0x570));
    uVar2 = *(undefined8 *)(param_1 + 0x720);
    pcVar4 = "%s: PCIe: The link of RC %d is not up.\n";
  }
  else {
    if (param_1 == 0) {
      return 0;
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x728),
                   "DBG1:%s: PCIe: The link of RC %d is not enabled.\n","msm_pcie_confirm_linkup",
                   *(undefined4 *)(param_1 + 0x570));
    uVar2 = *(undefined8 *)(param_1 + 0x720);
    pcVar4 = "%s: PCIe: The link of RC %d is not enabled.\n";
  }
  ipc_log_string(uVar2,pcVar4,"msm_pcie_confirm_linkup",*(undefined4 *)(param_1 + 0x570));
  return 0;
}



//------------------------------------------------------------
// link_check_max_count_show @ 0011b720 size=60
// signature: undefined link_check_max_count_show(void)
// callers: []
//------------------------------------------------------------

long link_check_max_count_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00124312,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x4f0))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// link_check_max_count_store @ 0011b760 size=132
// signature: undefined link_check_max_count_store(void)
// callers: []
//------------------------------------------------------------

undefined8
link_check_max_count_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 == 0) {
    *(undefined4 *)(lVar2 + 0x4f0) = local_2c;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// enumerate_store @ 0011b7e8 size=56
// signature: undefined enumerate_store(void)
// callers: []
//------------------------------------------------------------

undefined8 enumerate_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  if (*(long *)(param_1 + 0x98) != 0) {
    msm_pcie_enumerate(*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x570));
  }
  return param_4;
}



//------------------------------------------------------------
// aspm_stat_show @ 0011b824 size=256
// signature: undefined aspm_stat_show(void)
// callers: []
//------------------------------------------------------------

long aspm_stat_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x98);
  if (*(long *)(lVar8 + 0x3b0) == 0) {
    uVar1 = *(undefined4 *)(lVar8 + 0x570);
    pcVar7 = "PCIe: RC%d: No dev or MHI space found\n";
  }
  else {
    mutex_lock(lVar8 + 0x648);
    iVar6 = *(int *)(lVar8 + 0x4b0);
    mutex_unlock(lVar8 + 0x648);
    uVar1 = *(undefined4 *)(lVar8 + 0x570);
    if (iVar6 == 1) {
      uVar2 = readl_relaxed(*(long *)(lVar8 + 0x3b0) + 0xc10);
      uVar3 = readl_relaxed(*(long *)(lVar8 + 0x3b0) + 0xc0c);
      uVar4 = readl_relaxed(*(long *)(lVar8 + 0x3b0) + 0xc84);
      uVar5 = readl_relaxed(*(long *)(lVar8 + 0x3b0) + 0xc88);
      iVar6 = scnprintf(param_3,0x1000,"PCIe: RC%d: L0s: %u L1: %u L1.1: %u L1.2: %u\n",uVar1,uVar2,
                        uVar3,uVar4,uVar5);
      goto LAB_0011b908;
    }
    pcVar7 = "PCIe: RC%d: registers are not accessible\n";
  }
  iVar6 = scnprintf(param_3,0x1000,pcVar7,uVar1);
LAB_0011b908:
  return (long)iVar6;
}



//------------------------------------------------------------
// l23_rdy_poll_timeout_show @ 0011b928 size=60
// signature: undefined l23_rdy_poll_timeout_show(void)
// callers: []
//------------------------------------------------------------

long l23_rdy_poll_timeout_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%llu\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x698));
  return (long)iVar1;
}



//------------------------------------------------------------
// l23_rdy_poll_timeout_store @ 0011b968 size=204
// signature: undefined l23_rdy_poll_timeout_store(void)
// callers: []
//------------------------------------------------------------

undefined8
l23_rdy_poll_timeout_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    *(undefined8 *)(lVar2 + 0x698) = local_40;
    if (lVar2 != 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: L23_Ready poll timeout: %llu\n",
                     "l23_rdy_poll_timeout_store",*(undefined4 *)(lVar2 + 0x570));
      ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: PCIe: RC%d: L23_Ready poll timeout: %llu\n"
                     ,"l23_rdy_poll_timeout_store",*(undefined4 *)(lVar2 + 0x570),
                     *(undefined8 *)(lVar2 + 0x698));
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// boot_option_show @ 0011ba38 size=60
// signature: undefined boot_option_show(void)
// callers: []
//------------------------------------------------------------

long boot_option_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0012bb16,*(undefined4 *)(*(long *)(param_1 + 0x98) + 0x558))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// boot_option_store @ 0011ba78 size=232
// signature: undefined boot_option_store(void)
// callers: []
//------------------------------------------------------------

undefined8 boot_option_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 == 0) {
    if (local_3c < 4) {
      *(uint *)(lVar2 + 0x558) = local_3c;
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: boot_option is now 0x%x\n","boot_option_store",
                       *(undefined4 *)(lVar2 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar2 + 0x720),"%s: PCIe: RC%d: boot_option is now 0x%x\n",
                       "boot_option_store",*(undefined4 *)(lVar2 + 0x570),
                       *(undefined4 *)(lVar2 + 0x558));
      }
    }
    else {
      _printk(&DAT_00120e31,local_3c);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// panic_on_aer_show @ 0011bb64 size=60
// signature: undefined panic_on_aer_show(void)
// callers: []
//------------------------------------------------------------

long panic_on_aer_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0012bb16,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0xca9))
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// panic_on_aer_store @ 0011bba4 size=140
// signature: undefined panic_on_aer_store(void)
// callers: []
//------------------------------------------------------------

undefined8 panic_on_aer_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_2c = 0;
  iVar1 = kstrtouint(param_3,0,&local_2c);
  if (iVar1 == 0) {
    *(bool *)(lVar2 + 0xca9) = local_2c != 0;
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// link_speed_override_show @ 0011bc34 size=64
// signature: undefined link_speed_override_show(void)
// callers: []
//------------------------------------------------------------

long link_speed_override_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"PCIe: RC%d: link speed override is set to: 0x%x\n",
                    *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x570),
                    *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x55c));
  return (long)iVar1;
}



//------------------------------------------------------------
// link_speed_override_store @ 0011bc78 size=308
// signature: undefined link_speed_override_store(void)
// callers: []
//------------------------------------------------------------

undefined8
link_speed_override_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 == 0) {
    iVar1 = msm_pcie_set_target_link_speed(*(undefined4 *)(lVar2 + 0x570),local_3c,1);
    if (iVar1 == 0) {
      *(undefined4 *)(lVar2 + 0x55c) = local_3c;
      if (lVar2 != 0) {
        ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                       "DBG1:%s: PCIe: RC%d: link speed override set to: %d\n",
                       "link_speed_override_store",*(undefined4 *)(lVar2 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar2 + 0x720),
                       "%s: PCIe: RC%d: link speed override set to: %d\n",
                       "link_speed_override_store",*(undefined4 *)(lVar2 + 0x570),local_3c);
      }
    }
    else if (lVar2 != 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: Failed to override link speed: %d. %d\n",
                     "link_speed_override_store",*(undefined4 *)(lVar2 + 0x570),local_3c,iVar1);
      ipc_log_string(*(undefined8 *)(lVar2 + 0x720),
                     "%s: PCIe: RC%d: Failed to override link speed: %d. %d\n",
                     "link_speed_override_store",*(undefined4 *)(lVar2 + 0x570),local_3c,iVar1);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sbr_link_recovery_show @ 0011bdb0 size=64
// signature: undefined sbr_link_recovery_show(void)
// callers: []
//------------------------------------------------------------

long sbr_link_recovery_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"PCIe: RC%d: sbr_link_recovery is set to: 0x%x\n",
                    *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x570),
                    *(undefined1 *)(*(long *)(param_1 + 0x98) + 0x561));
  return (long)iVar1;
}



//------------------------------------------------------------
// sbr_link_recovery_store @ 0011bdf4 size=232
// signature: undefined sbr_link_recovery_store(void)
// callers: []
//------------------------------------------------------------

undefined8
sbr_link_recovery_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar1 = kstrtouint(param_3,0,&local_3c);
  if (iVar1 == 0) {
    if ((*(long *)(lVar2 + 0x330) != 0) && (*(long *)(lVar2 + 0x348) != 0)) {
      *(bool *)(lVar2 + 0x561) = local_3c != 0;
    }
    if (lVar2 != 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + 0x728),
                     "DBG1:%s: PCIe: RC%d: sbr_link_recovery is set to: %d\n",
                     "sbr_link_recovery_store",*(undefined4 *)(lVar2 + 0x570),local_3c);
      ipc_log_string(*(undefined8 *)(lVar2 + 0x720),
                     "%s: PCIe: RC%d: sbr_link_recovery is set to: %d\n","sbr_link_recovery_store",
                     *(undefined4 *)(lVar2 + 0x570),local_3c);
    }
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// aer_dev_correctable_show @ 0011bee0 size=232
// signature: undefined aer_dev_correctable_show(void)
// callers: []
//------------------------------------------------------------

long aer_dev_correctable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0x98);
  lVar5 = *(long *)(lVar4 + 0xcb0);
  if (lVar5 == 0) {
    lVar4 = -0x13;
  }
  else {
    uVar3 = 0;
    uVar2 = 0;
    do {
      if ((&aer_correctable_error_string)[uVar3] == (undefined *)0x0) {
        if (*(long *)(lVar5 + uVar3 * 8) != 0) {
          iVar1 = sysfs_emit_at(param_3,uVar2 & 0xffffffff,"dev_cor_errs_bit[%d] %llu\n",
                                uVar3 & 0xffffffff);
          goto LAB_0011bf44;
        }
      }
      else {
        iVar1 = sysfs_emit_at(param_3,uVar2 & 0xffffffff,"%s %llu\n",
                              (&aer_correctable_error_string)[uVar3],
                              *(undefined8 *)(lVar5 + uVar3 * 8));
LAB_0011bf44:
        uVar2 = uVar2 + (long)iVar1;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x10);
    iVar1 = sysfs_emit_at(param_3,uVar2 & 0xffffffff,"TOTAL_%s %llu\n","ERR_COR",
                          *(undefined8 *)(*(long *)(lVar4 + 0xcb0) + 0x230));
    lVar4 = uVar2 + (long)iVar1;
  }
  return lVar4;
}



//------------------------------------------------------------
// aer_dev_fatal_show @ 0011bfcc size=260
// signature: undefined aer_dev_fatal_show(void)
// callers: []
//------------------------------------------------------------

long aer_dev_fatal_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar5 + 0xcb0);
  if (lVar2 == 0) {
    lVar2 = -0x13;
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    lVar2 = lVar2 + 0x80;
    do {
      if ((0xf8000fceU >> (uVar4 & 0x3f) & 1) == 0) {
        iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"%s %llu\n",
                              (&aer_uncorrectable_error_string)[uVar4],
                              *(undefined8 *)(lVar2 + uVar4 * 8));
LAB_0011c048:
        uVar3 = uVar3 + (long)iVar1;
      }
      else if (*(long *)(lVar2 + uVar4 * 8) != 0) {
        iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"dev_fatal_errs_bit[%d] %llu\n",
                              uVar4 & 0xffffffff);
        goto LAB_0011c048;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0x1b);
    iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"TOTAL_%s %llu\n","ERR_FATAL",
                          *(undefined8 *)(*(long *)(lVar5 + 0xcb0) + 0x238));
    lVar2 = uVar3 + (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// aer_dev_nonfatal_show @ 0011c0d4 size=260
// signature: undefined aer_dev_nonfatal_show(void)
// callers: []
//------------------------------------------------------------

long aer_dev_nonfatal_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar2 = *(long *)(lVar5 + 0xcb0);
  if (lVar2 == 0) {
    lVar2 = -0x13;
  }
  else {
    uVar4 = 0;
    uVar3 = 0;
    lVar2 = lVar2 + 0x158;
    do {
      if ((0xf8000fceU >> (uVar4 & 0x3f) & 1) == 0) {
        iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"%s %llu\n",
                              (&aer_uncorrectable_error_string)[uVar4],
                              *(undefined8 *)(lVar2 + uVar4 * 8));
LAB_0011c150:
        uVar3 = uVar3 + (long)iVar1;
      }
      else if (*(long *)(lVar2 + uVar4 * 8) != 0) {
        iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"dev_nonfatal_errs_bit[%d] %llu\n",
                              uVar4 & 0xffffffff);
        goto LAB_0011c150;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0x1b);
    iVar1 = sysfs_emit_at(param_3,uVar3 & 0xffffffff,"TOTAL_%s %llu\n","ERR_NONFATAL",
                          *(undefined8 *)(*(long *)(lVar5 + 0xcb0) + 0x240));
    lVar2 = uVar3 + (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// aer_rootport_total_err_cor_show @ 0011c1dc size=72
// signature: undefined aer_rootport_total_err_cor_show(void)
// callers: []
//------------------------------------------------------------

long aer_rootport_total_err_cor_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xcb0);
  if (lVar2 == 0) {
    lVar2 = -0x13;
  }
  else {
    iVar1 = sysfs_emit(param_3,"%llu\n",*(undefined8 *)(lVar2 + 0x248));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// aer_rootport_total_err_fatal_show @ 0011c228 size=72
// signature: undefined aer_rootport_total_err_fatal_show(void)
// callers: []
//------------------------------------------------------------

long aer_rootport_total_err_fatal_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xcb0);
  if (lVar2 == 0) {
    lVar2 = -0x13;
  }
  else {
    iVar1 = sysfs_emit(param_3,"%llu\n",*(undefined8 *)(lVar2 + 0x250));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// aer_rootport_total_err_nonfatal_show @ 0011c274 size=72
// signature: undefined aer_rootport_total_err_nonfatal_show(void)
// callers: []
//------------------------------------------------------------

long aer_rootport_total_err_nonfatal_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xcb0);
  if (lVar2 == 0) {
    lVar2 = -0x13;
  }
  else {
    iVar1 = sysfs_emit(param_3,"%llu\n",*(undefined8 *)(lVar2 + 600));
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// msm_pcie_pm_suspend_noirq @ 0011c2c0 size=1044
// signature: undefined msm_pcie_pm_suspend_noirq(void)
// callers: []
//------------------------------------------------------------

int msm_pcie_pm_suspend_noirq(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  undefined8 uVar6;
  uint uVar7;
  long lVar8;
  char local_68 [32];
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x98);
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  if (lVar8 != 0) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x728),"DBG1:%s: RC%d: entry\n",
                   "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar8 + 0x720),"%s: RC%d: entry\n","msm_pcie_pm_suspend_noirq",
                   *(undefined4 *)(lVar8 + 0x570));
  }
  scnprintf(local_68,0x20,"pcie_cfg_ahb_clk");
  lVar1 = lVar8 + 0x610;
  mutex_lock(lVar1);
  if (((*(char *)(lVar8 + 0x579) != '\0') && (*(char *)(lVar8 + 0x71c) != '\0')) &&
     (*(char *)(lVar8 + 0x441) != '\0')) {
    lVar4 = ktime_get();
    uVar2 = readl(*(long *)(lVar8 + 0x380) + 0x24);
    if ((uVar2 >> 8 & 1) == 0) {
      do {
        lVar5 = ktime_get();
        if (lVar4 + 200000000 < lVar5) {
          uVar2 = readl(*(long *)(lVar8 + 0x380) + 0x24);
          break;
        }
        usleep_range_state(0xfb,1000,2);
        Yield();
        uVar2 = readl(*(long *)(lVar8 + 0x380) + 0x24);
      } while ((uVar2 >> 8 & 1) == 0);
    }
    if ((uVar2 >> 8 & 1) == 0) {
      if (lVar8 != 0) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x728),"INFO:%s: RC%d: Link is not in L1ss\n",
                       "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar8 + 0x720),"%s: RC%d: Link is not in L1ss\n",
                       "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
      }
      _printk(&DAT_0012d9de,"msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
    }
    else {
      if (lVar8 != 0) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x728),"DBG1:%s: RC%d: Link is in L1ss\n",
                       "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
        ipc_log_string(*(undefined8 *)(lVar8 + 0x720),"%s: RC%d: Link is in L1ss\n",
                       "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
      }
      *(undefined1 *)(lVar8 + 0x71c) = 0;
      *(undefined1 *)(lVar8 + 0x4b4) = 1;
      uVar6 = _raw_spin_lock_irqsave(lVar8 + 0x640);
      *(undefined1 *)(lVar8 + 0x6a0) = 1;
      _raw_spin_unlock_irqrestore(lVar8 + 0x640,uVar6);
      uVar6 = _raw_spin_lock_irqsave(lVar8 + 0x444);
      *(undefined8 *)(lVar8 + 0x448) = uVar6;
      *(undefined1 *)(lVar8 + 0x440) = 0;
      _raw_spin_unlock_irqrestore(lVar8 + 0x444,uVar6);
      if (*(char *)(lVar8 + 0x560) == '\0') {
        msm_msi_config_access(*(undefined8 *)(*(long *)(lVar8 + 8) + 0x350),0);
      }
      lVar4 = *(long *)(lVar8 + 0x380) + 0x2b0;
      writel_relaxed(10,lVar4);
      readl_relaxed(lVar4);
      if ((*(char *)(lVar8 + 0x738) != '\0') && (*(long *)(lVar8 + 0x750) != 0)) {
        pinctrl_select_state(*(undefined8 *)(lVar8 + 0x740));
      }
      uVar2 = *(uint *)(lVar8 + 0x370);
      if (uVar2 != 0) {
        uVar7 = 0;
        do {
          lVar4 = *(long *)(*(long *)(lVar8 + 0x378) + (long)(int)uVar7 * 0x18);
          if ((lVar4 != 0) &&
             (iVar3 = strcmp(*(char **)(*(long *)(lVar8 + 0x378) + (long)(int)uVar7 * 0x18 + 8),
                             local_68), iVar3 != 0)) {
            clk_disable(lVar4);
            clk_unprepare(lVar4);
            uVar2 = *(uint *)(lVar8 + 0x370);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar2);
      }
      iVar3 = msm_pcie_icc_vote(lVar8,0,0,0);
      if (iVar3 != 0) {
        mutex_unlock(lVar1);
        goto LAB_0011c644;
      }
      if ((*(long *)(lVar8 + 0x420) != 0) && (*(long *)(lVar8 + 0x430) != 0)) {
        clk_set_parent();
      }
      if ((*(long *)(lVar8 + 0x410) != 0) && (*(long *)(lVar8 + 0x430) != 0)) {
        clk_set_parent();
      }
      msm_pcie_pipe_clk_deinit(lVar8);
      if (*(uint *)(lVar8 + 0x524) != 0) {
        lVar4 = *(long *)(lVar8 + 0x388) + (ulong)*(uint *)(lVar8 + 0x524);
        uVar2 = readl_relaxed(lVar4);
        writel_relaxed(uVar2 & 0xffffff3f | 0x80,lVar4);
        readl_relaxed(lVar4);
      }
      if (*(uint *)(lVar8 + 0x528) != 0) {
        lVar4 = *(long *)(lVar8 + 0x388) + (ulong)*(uint *)(lVar8 + 0x528);
        uVar2 = readl_relaxed(lVar4);
        writel_relaxed(uVar2 | 2,lVar4);
        readl_relaxed(lVar4);
      }
      if (*(uint *)(lVar8 + 0x520) != 0) {
        lVar4 = *(long *)(lVar8 + 0x388) + (ulong)*(uint *)(lVar8 + 0x520);
        writel_relaxed(0,lVar4);
        readl_relaxed(lVar4);
      }
      uVar6 = *(undefined8 *)(lVar8 + 0x438);
      clk_disable(uVar6);
      clk_unprepare(uVar6);
      regulator_disable(*(undefined8 *)(lVar8 + 0x10));
      msm_pcie_vreg_deinit_analog_rails(lVar8);
    }
  }
  mutex_unlock(lVar1);
  if (lVar8 != 0) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x728),"DBG1:%s: RC%d: exit\n",
                   "msm_pcie_pm_suspend_noirq",*(undefined4 *)(lVar8 + 0x570));
    ipc_log_string(*(undefined8 *)(lVar8 + 0x720),"%s: RC%d: exit\n","msm_pcie_pm_suspend_noirq",
                   *(undefined4 *)(lVar8 + 0x570));
  }
  iVar3 = 0;
LAB_0011c644:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// msm_pcie_pm_resume_noirq @ 0011c6d8 size=1512
// signature: undefined msm_pcie_pm_resume_noirq(void)
// callers: []
//------------------------------------------------------------

int msm_pcie_pm_resume_noirq(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  char *__s1;
  char local_88 [32];
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  puVar4 = *(undefined8 **)(param_1 + 0x98);
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
  if (puVar4 != (undefined8 *)0x0) {
    ipc_log_string(puVar4[0xe5],"DBG1:%s: RC%d: entry\n","msm_pcie_pm_resume_noirq",
                   *(undefined4 *)(puVar4 + 0xae));
    ipc_log_string(puVar4[0xe4],"%s: RC%d: entry\n","msm_pcie_pm_resume_noirq",
                   *(undefined4 *)(puVar4 + 0xae));
  }
  scnprintf(local_88,0x20,"pcie_cfg_ahb_clk");
  puVar1 = puVar4 + 0xc2;
  mutex_lock(puVar1);
  if (((*(char *)((long)puVar4 + 0x579) == '\0') || (*(char *)((long)puVar4 + 0x71c) != '\0')) ||
     (*(char *)((long)puVar4 + 0x441) == '\0')) {
LAB_0011c780:
    mutex_unlock(puVar1);
    if (puVar4 != (undefined8 *)0x0) {
      ipc_log_string(puVar4[0xe5],"DBG1:%s: RC%d: exit\n","msm_pcie_pm_resume_noirq",
                     *(undefined4 *)(puVar4 + 0xae));
      ipc_log_string(puVar4[0xe4],"%s: RC%d: exit\n","msm_pcie_pm_resume_noirq",
                     *(undefined4 *)(puVar4 + 0xae));
    }
    iVar2 = 0;
  }
  else {
    lVar7 = 0;
    do {
      lVar6 = *(long *)((long)puVar4 + lVar7 + 0x20);
      if (lVar6 != 0) {
        __s1 = *(char **)((long)puVar4 + lVar7 + 0x28);
        iVar2 = strcmp(__s1,"vreg-3p3");
        if (iVar2 != 0) {
          if (puVar4 == (undefined8 *)0x0) {
            iVar2 = regulator_enable(lVar6);
            if (iVar2 != 0) goto LAB_0011c8f0;
          }
          else {
            ipc_log_string(puVar4[0xe5],"DBG1:%s: Vreg %s is being enabled\n",
                           "msm_pcie_vreg_init_analog_rails",__s1);
            ipc_log_string(puVar4[0xe4],"%s: Vreg %s is being enabled\n",
                           "msm_pcie_vreg_init_analog_rails",
                           *(undefined8 *)((long)puVar4 + lVar7 + 0x28));
            iVar2 = regulator_enable(*(undefined8 *)((long)puVar4 + lVar7 + 0x20));
            if (iVar2 != 0) {
              ipc_log_string(puVar4[0xe5],"ERR:%s: PCIe: RC%d can\'t enable regulator %s: %d\n",
                             "msm_pcie_vreg_init_analog_rails",*(undefined4 *)(puVar4 + 0xae),
                             *(undefined8 *)((long)puVar4 + lVar7 + 0x28),iVar2);
              ipc_log_string(puVar4[0xe4],"%s: PCIe: RC%d can\'t enable regulator %s: %d\n",
                             "msm_pcie_vreg_init_analog_rails",*(undefined4 *)(puVar4 + 0xae),
                             *(undefined8 *)((long)puVar4 + lVar7 + 0x28),iVar2);
LAB_0011c8f0:
              _printk(&DAT_00125f38,"msm_pcie_vreg_init_analog_rails",*(undefined4 *)(puVar4 + 0xae)
                      ,*(undefined8 *)((long)puVar4 + lVar7 + 0x28),iVar2);
            }
          }
        }
      }
      lVar7 = lVar7 + 0x20;
    } while (lVar7 != 0xc0);
    iVar2 = regulator_enable(puVar4[2]);
    if (iVar2 == 0) {
      uVar5 = puVar4[0x87];
      iVar2 = clk_prepare(uVar5);
      if ((iVar2 == 0) && (iVar2 = clk_enable(uVar5), iVar2 != 0)) {
        clk_unprepare(uVar5);
      }
      if ((puVar4[0x82] != 0) && (puVar4[0x83] != 0)) {
        clk_set_parent();
      }
      if (*(uint *)(puVar4 + 0xa5) != 0) {
        lVar7 = puVar4[0x71] + (ulong)*(uint *)(puVar4 + 0xa5);
        uVar3 = readl_relaxed(lVar7);
        writel_relaxed(uVar3 & 0xfffffffd,lVar7);
        readl_relaxed(lVar7);
      }
      if (*(uint *)((long)puVar4 + 0x524) != 0) {
        lVar7 = puVar4[0x71] + (ulong)*(uint *)((long)puVar4 + 0x524);
        uVar3 = readl_relaxed(lVar7);
        writel_relaxed(uVar3 & 0xffffff3f,lVar7);
        readl_relaxed(lVar7);
      }
      if (*(uint *)(puVar4 + 0xa4) != 0) {
        lVar7 = puVar4[0x71] + (ulong)*(uint *)(puVar4 + 0xa4);
        writel_relaxed(3,lVar7);
        readl_relaxed(lVar7);
      }
      iVar2 = msm_pcie_icc_vote(puVar4,*(undefined4 *)((long)puVar4 + 0x4fc),
                                *(undefined4 *)((long)puVar4 + 0x504),0);
      if (iVar2 == 0) {
        if (*(int *)(puVar4 + 0x6e) != 0) {
          uVar3 = 0;
          do {
            lVar7 = *(long *)(puVar4[0x6f] + (long)(int)uVar3 * 0x18);
            if ((lVar7 != 0) &&
               (iVar2 = strcmp(*(char **)(puVar4[0x6f] + (long)(int)uVar3 * 0x18 + 8),local_88),
               iVar2 != 0)) {
              iVar2 = clk_prepare(lVar7);
              if (iVar2 == 0) {
                iVar2 = clk_enable(lVar7);
                if (iVar2 == 0) {
                  if (puVar4 != (undefined8 *)0x0) {
                    ipc_log_string(puVar4[0xe4],"DBG2:%s: enable clk %s for RC%d.\n",
                                   "msm_pcie_pm_resume_noirq",
                                   *(undefined8 *)(puVar4[0x6f] + (long)(int)uVar3 * 0x18 + 8),
                                   *(undefined4 *)(puVar4 + 0xae));
                  }
                  goto LAB_0011ca74;
                }
                clk_unprepare(lVar7);
              }
              if (puVar4 != (undefined8 *)0x0) {
                ipc_log_string(puVar4[0xe5],"ERR:%s: PCIe: RC%d failed to enable clk %s\n",
                               "msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
                               *(undefined8 *)(puVar4[0x6f] + (long)(int)uVar3 * 0x18 + 8));
                ipc_log_string(puVar4[0xe4],"%s: PCIe: RC%d failed to enable clk %s\n",
                               "msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
                               *(undefined8 *)(puVar4[0x6f] + (long)(int)uVar3 * 0x18 + 8));
              }
              _printk(&DAT_001265c2,"msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
                      *(undefined8 *)(puVar4[0x6f] + (long)(int)uVar3 * 0x18 + 8));
            }
LAB_0011ca74:
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(puVar4 + 0x6e));
        }
        if (*(int *)(puVar4 + 0x6c) != 0) {
          uVar3 = 0;
          do {
            lVar7 = *(long *)(puVar4[0x6d] + (long)(int)uVar3 * 0x18);
            if (((lVar7 != 0) && (iVar2 = clk_prepare(lVar7), iVar2 == 0)) &&
               (iVar2 = clk_enable(lVar7), iVar2 != 0)) {
              clk_unprepare(lVar7);
            }
            uVar3 = uVar3 + 1;
          } while (uVar3 < *(uint *)(puVar4 + 0x6c));
        }
        if ((puVar4[0x84] != 0) && (puVar4[0x85] != 0)) {
          clk_set_parent();
        }
        lVar7 = puVar4[0x70];
        writel_relaxed(0,lVar7 + 0x2b0);
        readl_relaxed(lVar7 + 0x2b0);
        if ((*(char *)(puVar4 + 0xe7) != '\0') && (puVar4[0xe9] != 0)) {
          pinctrl_select_state(puVar4[0xe8]);
        }
        *(undefined1 *)((long)puVar4 + 0x4b4) = 0;
        *(undefined1 *)((long)puVar4 + 0x71c) = 1;
        uVar5 = _raw_spin_lock_irqsave(puVar4 + 200);
        *(undefined1 *)(puVar4 + 0xd4) = 0;
        _raw_spin_unlock_irqrestore(puVar4 + 200,uVar5);
        uVar5 = _raw_spin_lock_irqsave((long)puVar4 + 0x444);
        puVar4[0x89] = uVar5;
        *(undefined1 *)(puVar4 + 0x88) = 1;
        _raw_spin_unlock_irqrestore((long)puVar4 + 0x444,uVar5);
        if (*(char *)(puVar4 + 0xac) == '\0') {
          msm_msi_config_access(*(undefined8 *)(puVar4[1] + 0x350),1);
        }
        goto LAB_0011c780;
      }
      if ((puVar4[0x83] != 0) && (puVar4[0x82] != 0)) {
        clk_set_parent();
      }
      regulator_disable(puVar4[2]);
    }
    else {
      if (puVar4 != (undefined8 *)0x0) {
        ipc_log_string(puVar4[0xe5],"ERR:%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
                       "msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
                       *(undefined8 *)*puVar4);
        ipc_log_string(puVar4[0xe4],"%s: PCIe: fail to enable GDSC-CORE for RC%d (%s)\n",
                       "msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
                       *(undefined8 *)*puVar4);
      }
      _printk(&DAT_0012dccf,"msm_pcie_pm_resume_noirq",*(undefined4 *)(puVar4 + 0xae),
              *(undefined8 *)*puVar4);
    }
    msm_pcie_vreg_deinit_analog_rails(puVar4);
    mutex_unlock(puVar1);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// readl @ 0011ccc0 size=140
// signature: undefined readl(void)
// callers: [msm_pcie_pm_suspend_noirq, msm_pcie_pm_suspend]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x11cd18,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_pcie_vreg_deinit_analog_rails @ 0011cd4c size=212
// signature: undefined msm_pcie_vreg_deinit_analog_rails(void)
// callers: [msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

void msm_pcie_vreg_deinit_analog_rails(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long lVar4;
  char *__s1;
  long lVar5;
  
  lVar5 = 0;
  do {
    lVar1 = param_1 + lVar5;
    lVar4 = *(long *)(lVar1 + 0xc0);
    if (lVar4 != 0) {
      __s1 = *(char **)(lVar1 + 200);
      iVar3 = strcmp(__s1,"vreg-3p3");
      if (iVar3 != 0) {
        if (param_1 != 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x728),"DBG1:%s: Vreg %s is being disabled\n",
                         "msm_pcie_vreg_deinit_analog_rails",__s1);
          ipc_log_string(*(undefined8 *)(param_1 + 0x720),"%s: Vreg %s is being disabled\n",
                         "msm_pcie_vreg_deinit_analog_rails",*(undefined8 *)(lVar1 + 200));
          lVar4 = *(long *)(lVar1 + 0xc0);
        }
        regulator_disable(lVar4);
      }
    }
    bVar2 = lVar5 != -0xa0;
    lVar5 = lVar5 + -0x20;
  } while (bVar2);
  return;
}



//------------------------------------------------------------
// msm_msi_config_access @ 0011ce54 size=80
// signature: undefined msm_msi_config_access(void)
// callers: [msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq, msm_pcie_disable, msm_pcie_pm_control, msm_pcie_enumerate]
//------------------------------------------------------------

void msm_msi_config_access(long param_1,undefined1 param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x50) + 0x20);
  lVar1 = lVar3 + 0x90;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  *(undefined1 *)(lVar3 + 0x94) = param_2;
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  return;
}



//------------------------------------------------------------
// msm_msi_config @ 0011cea8 size=192
// signature: undefined msm_msi_config(void)
// callers: [msm_msi_init, msm_pcie_enable]
//------------------------------------------------------------

void msm_msi_config(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x50) + 0x20);
  uVar2 = _raw_spin_lock_irqsave(lVar4 + 0x90);
  *(undefined1 *)(lVar4 + 0x94) = 1;
  _raw_spin_unlock_irqrestore(lVar4 + 0x90,uVar2);
  if (*(int *)(lVar4 + 0x8c) != 0) {
    writel_relaxed(*(undefined4 *)(lVar4 + 0x80),*(long *)(lVar4 + 0x98) + 0x820);
    writel_relaxed(0,*(long *)(lVar4 + 0x98) + 0x824);
    if (0 < *(int *)(lVar4 + 0x28)) {
      lVar3 = 0;
      lVar5 = 0;
      do {
        puVar1 = (undefined8 *)(*(long *)(lVar4 + 0x30) + lVar3);
        writel_relaxed(*(undefined4 *)(puVar1 + 3),puVar1[1]);
        writel_relaxed(0xffffffff,*puVar1);
        lVar5 = lVar5 + 1;
        lVar3 = lVar3 + 0x420;
      } while (lVar5 < *(int *)(lVar4 + 0x28));
    }
  }
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 0011cf68 size=132
// signature: undefined writel_relaxed(void)
// callers: [msm_msi_config, msm_msi_snps_unmask_irq, msm_msi_snps_handler]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x11cf80,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x11cfbc,uVar1);
  return;
}



//------------------------------------------------------------
// msm_msi_init @ 0011cff0 size=1072
// signature: undefined msm_msi_init(void)
// callers: [msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int msm_msi_init(long param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  int iVar4;
  long lVar5;
  uint *puVar6;
  long lVar7;
  undefined8 uVar8;
  long *plVar9;
  char *pcVar10;
  int iVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  uint local_dc;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  long local_88 [11];
  
  lVar7 = sp_el0;
  local_88[10] = *(long *)(lVar7 + 0x638);
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_dc = 0;
  if (*(long *)(param_1 + 0x2e8) == 0) {
    pcVar10 = "MSI: missing DT node\n";
    goto LAB_0011d174;
  }
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  iVar4 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),"msi-parent",0,0,0,local_88);
  lVar7 = local_88[0];
  if ((iVar4 == 0) && (local_88[0] != 0)) {
    iVar4 = of_device_is_compatible(local_88[0],"qcom,pci-msi");
    if (iVar4 != 0) {
      lVar5 = of_find_property(lVar7,"msi-controller",0);
      if (lVar5 == 0) {
        iVar4 = -0x13;
        goto LAB_0011d17c;
      }
      lVar5 = kmalloc_trace(_pci_host_probe,0xdc0,0xb0);
      if (lVar5 == 0) {
        iVar4 = -0xc;
        goto LAB_0011d17c;
      }
      *(long *)(lVar5 + 0x10) = param_1;
      *(long *)(lVar5 + 0x18) = lVar7;
      __mutex_init(lVar5 + 0x40,"&msi->mutex",&msm_msi_init___key);
      *(undefined4 *)(lVar5 + 0x90) = 0;
      *(long *)lVar5 = lVar5;
      *(long *)(lVar5 + 8) = lVar5;
      puVar6 = (uint *)__of_get_address(*(undefined8 *)(lVar5 + 0x18),0,0xffffffff,0,0);
      if (puVar6 == (uint *)0x0) {
        param_1 = *(long *)(lVar5 + 0x10);
        pcVar10 = "MSI: missing \'reg\' devicetree\n";
      }
      else {
        uVar1 = *puVar6;
        uVar2 = (uVar1 & 0xff00ff00) >> 8 | (uVar1 & 0xff00ff) << 8;
        *(ulong *)(lVar5 + 0x80) = (ulong)(uVar2 >> 0x10 | uVar2 << 0x10);
        if (uVar1 != 0) {
          of_property_read_variable_u32_array(lVar7,"qcom,msi-addr-size-exp",&local_dc,1,0);
          if (local_dc < 0xd) {
            local_dc = 0xc;
          }
          *(int *)(lVar5 + 0x88) = 1 << (ulong)(local_dc & 0x1f);
          lVar7 = of_find_property(*(undefined8 *)(lVar5 + 0x18),"qcom,snps",0);
          pcVar10 = "synopsys";
          if (lVar7 == 0) {
            pcVar10 = "qgic";
          }
          *(uint *)(lVar5 + 0x8c) = (uint)(lVar7 != 0);
          _dev_info(*(undefined8 *)(lVar5 + 0x10),"MSI: %s controller is present\n",pcVar10);
          uVar8 = *(undefined8 *)(lVar5 + 0x18);
          iVar4 = *(int *)(lVar5 + 0x20);
          while (iVar4 = of_irq_parse_one(uVar8,iVar4,&local_d8), iVar4 == 0) {
            uVar8 = *(undefined8 *)(lVar5 + 0x18);
            iVar4 = *(int *)(lVar5 + 0x20) + 1;
            *(int *)(lVar5 + 0x20) = iVar4;
          }
          iVar4 = *(int *)(lVar5 + 0x20);
          if (iVar4 != 0) {
            if (*(int *)(lVar5 + 0x8c) == 1) {
              plVar9 = (long *)platform_get_resource_byname(param_1 + -0x10,0x200,"dm_core");
              if (plVar9 == (long *)0x0) {
                param_1 = *(long *)(lVar5 + 0x10);
                pcVar10 = "MSI: failed to get PCIe register base\n";
                goto LAB_0011d0f4;
              }
              uVar8 = 0x68000000000713;
              if (arm64_use_ng_mappings != '\0') {
                uVar8 = 0x68000000000f13;
              }
              lVar7 = ioremap_prot(*plVar9,(plVar9[1] - *plVar9) + 1,uVar8);
              *(long *)(lVar5 + 0x98) = lVar7;
              if (lVar7 != 0) {
                iVar11 = *(int *)(lVar5 + 0x20);
                pcVar14 = msm_msi_snps_irq_setup;
                pcVar12 = msm_msi_snps_unmask_irq;
                pcVar13 = msm_msi_snps_mask_irq;
                iVar4 = iVar11 << 5;
                goto LAB_0011d2fc;
              }
              iVar4 = -0xc;
            }
            else {
              pcVar14 = msm_msi_qgic_irq_setup;
              iVar11 = 1;
              pcVar12 = msm_msi_qgic_unmask_irq;
              pcVar13 = msm_msi_qgic_mask_irq;
LAB_0011d2fc:
              *(int *)(lVar5 + 0x24) = iVar4;
              *(int *)(lVar5 + 0x28) = iVar11;
              auVar3._8_8_ = 0;
              auVar3._0_8_ = (long)iVar11;
              *(code **)(lVar5 + 0xa0) = pcVar13;
              *(code **)(lVar5 + 0xa8) = pcVar12;
              if (SUB168(auVar3 * ZEXT816(0x420),8) == 0) {
                lVar7 = __kmalloc((long)iVar11 * 0x420,0xdc0);
                *(long *)(lVar5 + 0x30) = lVar7;
                if (lVar7 == 0) {
                  iVar4 = -0xc;
                }
                else {
                  lVar7 = __kmalloc((long)*(int *)(lVar5 + 0x24) + 0x3fU >> 3 & 0x1ffffffffffffff8,
                                    0xdc0);
                  *(long *)(lVar5 + 0x38) = lVar7;
                  if (lVar7 == 0) {
                    iVar4 = -0xc;
                  }
                  else {
                    iVar4 = msm_msi_alloc_domains(lVar5);
                    if (iVar4 == 0) {
                      if (*(int *)(pcVar14 + -4) != 0x4d2972b) {
                    /* WARNING: Does not return */
                        pcVar12 = (code *)SoftwareBreakpoint(0x8235,0x11d378);
                        (*pcVar12)();
                      }
                      iVar4 = (*pcVar14)(lVar5);
                      if (iVar4 == 0) {
                        msm_msi_config(*(undefined8 *)(lVar5 + 0x78));
                        goto LAB_0011d17c;
                      }
                      irq_domain_remove();
                      irq_domain_remove(*(undefined8 *)(lVar5 + 0x70));
                    }
                    else {
                      _dev_err(*(undefined8 *)(lVar5 + 0x10),"MSI: failed to allocate MSI domains\n"
                              );
                    }
                    kfree(*(undefined8 *)(lVar5 + 0x38));
                  }
                  kfree(*(undefined8 *)(lVar5 + 0x30));
                }
              }
              else {
                iVar4 = -0xc;
                *(undefined8 *)(lVar5 + 0x30) = 0;
              }
              iounmap(*(undefined8 *)(lVar5 + 0x98));
            }
            kfree(lVar5);
            goto LAB_0011d17c;
          }
          param_1 = *(long *)(lVar5 + 0x10);
          pcVar10 = "MSI: found no MSI interrupts\n";
          goto LAB_0011d0f4;
        }
        param_1 = *(long *)(lVar5 + 0x10);
        pcVar10 = "MSI: failed to get MSI address\n";
      }
LAB_0011d174:
      _dev_err(param_1,pcVar10);
      iVar4 = -0x16;
      goto LAB_0011d17c;
    }
    pcVar10 = "MSI: no compatible qcom,pci-msi found\n";
  }
  else {
    pcVar10 = "MSI: no phandle for MSI found\n";
  }
LAB_0011d0f4:
  _dev_err(param_1,pcVar10);
  iVar4 = -0x13;
LAB_0011d17c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// msm_msi_snps_mask_irq @ 0011d424 size=100
// signature: undefined msm_msi_snps_mask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_snps_mask_irq(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long *plVar4;
  
  plVar4 = *(long **)(param_1 + 0x30);
  lVar2 = plVar4[1];
  lVar1 = *(long *)(*plVar4 + 0x10) + 0x90;
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  *(uint *)(lVar2 + 0x18) =
       *(uint *)(lVar2 + 0x18) | (uint)(1L << ((ulong)*(uint *)(plVar4 + 2) & 0x3f));
  _raw_spin_unlock_irqrestore(lVar1,uVar3);
  return;
}



//------------------------------------------------------------
// msm_msi_snps_unmask_irq @ 0011d48c size=124
// signature: undefined msm_msi_snps_unmask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_snps_unmask_irq(long param_1)

{
  long lVar1;
  uint uVar2;
  long lVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  
  plVar5 = *(long **)(param_1 + 0x30);
  lVar3 = plVar5[1];
  lVar6 = *(long *)(*plVar5 + 0x10);
  lVar1 = lVar6 + 0x90;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  uVar2 = *(uint *)(lVar3 + 0x18) &
          ((uint)(1L << ((ulong)*(uint *)(plVar5 + 2) & 0x3f)) ^ 0xffffffff);
  *(uint *)(lVar3 + 0x18) = uVar2;
  if (*(char *)(lVar6 + 0x94) != '\0') {
    writel_relaxed(uVar2,*(undefined8 *)(lVar3 + 8));
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  return;
}



//------------------------------------------------------------
// msm_msi_snps_irq_setup @ 0011d50c size=412
// signature: undefined msm_msi_snps_irq_setup(void)
// callers: [msm_msi_init]
//------------------------------------------------------------

int msm_msi_snps_irq_setup(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  int *piVar8;
  ulong uVar9;
  int iVar10;
  long lVar11;
  
  if (0 < *(int *)(param_1 + 0x20)) {
    iVar10 = 0;
    uVar9 = 0;
    lVar11 = 0x3c;
    do {
      uVar4 = irq_of_parse_and_map(*(undefined8 *)(param_1 + 0x18),uVar9 & 0xffffffff);
      if ((int)uVar4 == 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x10),"MSI: failed to parse/map interrupt\n");
        iVar3 = -0x13;
LAB_0011d658:
        uVar2 = (int)uVar9 - 1;
        if ((int)uVar2 < 0) {
          return iVar3;
        }
        lVar11 = (ulong)uVar2 * 0x420 + 0x34;
        do {
          uVar1 = *(undefined4 *)(*(long *)(param_1 + 0x30) + lVar11);
          irq_set_chained_handler_and_data(uVar1,0,0);
          irq_set_irq_wake(uVar1,0);
          irq_dispose_mapping(uVar1);
          uVar2 = (int)uVar9 - 1;
          uVar9 = (ulong)uVar2;
          lVar11 = lVar11 + -0x420;
        } while (uVar2 != 0);
        return iVar3;
      }
      iVar3 = irq_set_irq_wake(uVar4,1);
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x10),
                 "MSI: Unable to set enable_irq_wake for interrupt: %d: %d\n",uVar9 & 0xffffffff,
                 uVar4 & 0xffffffff);
        irq_dispose_mapping(uVar4 & 0xffffffff);
        goto LAB_0011d658;
      }
      lVar7 = *(long *)(param_1 + 0x30);
      iVar3 = (int)uVar9 * 0xc;
      lVar6 = 0;
      plVar5 = (long *)(lVar7 + uVar9 * 0x420);
      *plVar5 = *(long *)(param_1 + 0x98) + (long)(iVar3 + 0x828);
      plVar5[1] = *(long *)(param_1 + 0x98) + (long)(iVar3 + 0x82c);
      plVar5[2] = *(long *)(param_1 + 0x98) + (long)(iVar3 + 0x830);
      piVar8 = (int *)(lVar7 + lVar11);
      do {
        iVar3 = (int)lVar6;
        piVar8[-3] = iVar3;
        piVar8[-2] = (int)uVar4;
        lVar6 = lVar6 + 1;
        *(long **)(piVar8 + -5) = plVar5;
        *piVar8 = iVar10 + iVar3;
        piVar8 = piVar8 + 8;
      } while (lVar6 != 0x20);
      irq_set_chained_handler_and_data(uVar4 & 0xffffffff,msm_msi_snps_handler);
      uVar9 = uVar9 + 1;
      iVar10 = iVar10 + 0x20;
      lVar11 = lVar11 + 0x420;
    } while ((long)uVar9 < (long)*(int *)(param_1 + 0x20));
  }
  return 0;
}



//------------------------------------------------------------
// msm_msi_qgic_mask_irq @ 0011d6ac size=76
// signature: undefined msm_msi_qgic_mask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_qgic_mask_irq(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = irq_get_irq_data(*(undefined4 *)(param_1 + 8));
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x18) != 0)) {
    pcVar2 = *(code **)(*(long *)(lVar1 + 0x18) + 0x30);
    if (*(int *)(pcVar2 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11d6e8);
      (*pcVar2)();
    }
    (*pcVar2)();
  }
  return;
}



//------------------------------------------------------------
// msm_msi_qgic_unmask_irq @ 0011d6fc size=76
// signature: undefined msm_msi_qgic_unmask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_qgic_unmask_irq(long param_1)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = irq_get_irq_data(*(undefined4 *)(param_1 + 8));
  if ((lVar1 != 0) && (*(long *)(lVar1 + 0x18) != 0)) {
    pcVar2 = *(code **)(*(long *)(lVar1 + 0x18) + 0x40);
    if (*(int *)(pcVar2 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11d738);
      (*pcVar2)();
    }
    (*pcVar2)();
  }
  return;
}



//------------------------------------------------------------
// msm_msi_qgic_irq_setup @ 0011d74c size=336
// signature: undefined msm_msi_qgic_irq_setup(void)
// callers: []
//------------------------------------------------------------

int msm_msi_qgic_irq_setup(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  uint uVar6;
  ulong uVar7;
  int iVar8;
  
  if (0 < *(int *)(param_1 + 0x20)) {
    uVar7 = 0;
    do {
      uVar4 = irq_of_parse_and_map(*(undefined8 *)(param_1 + 0x18),uVar7);
      uVar6 = (uint)uVar7;
      if ((int)uVar4 == 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x10),"MSI: failed to parse/map interrupt\n");
        iVar3 = -0x13;
LAB_0011d840:
        if (uVar6 == 0) {
          return iVar3;
        }
        iVar8 = uVar6 + 1;
        do {
          uVar2 = *(undefined4 *)
                   (*(long *)(param_1 + 0x30) + (ulong)(iVar8 - 2U >> 5) * 0x420 +
                    (ulong)(iVar8 - 2U & 0x1f) * 0x20 + 0x34);
          irq_set_chained_handler_and_data(uVar2,0,0);
          irq_set_irq_wake(uVar2,0);
          irq_dispose_mapping(uVar2);
          iVar8 = iVar8 + -1;
        } while (1 < iVar8);
        return iVar3;
      }
      iVar3 = irq_set_irq_wake(uVar4,1);
      if (iVar3 != 0) {
        _dev_err(*(undefined8 *)(param_1 + 0x10),
                 "MSI: Unable to set enable_irq_wake for interrupt: %d: %d\n",uVar7,
                 uVar4 & 0xffffffff);
        irq_dispose_mapping(uVar4 & 0xffffffff);
        goto LAB_0011d840;
      }
      lVar5 = *(long *)(param_1 + 0x30) + (uVar7 >> 5) * 0x420;
      lVar1 = lVar5 + (ulong)(uVar6 & 0x1f) * 0x20;
      *(long *)(lVar1 + 0x28) = lVar5;
      *(uint *)(lVar1 + 0x3c) = uVar6;
      *(uint *)(lVar1 + 0x30) = uVar6 & 0x1f;
      *(int *)(lVar1 + 0x34) = (int)uVar4;
      irq_set_chained_handler_and_data(uVar4 & 0xffffffff,msm_msi_qgic_handler,param_1);
      uVar7 = (ulong)(uVar6 + 1);
    } while ((int)(uVar6 + 1) < *(int *)(param_1 + 0x20));
  }
  return 0;
}



//------------------------------------------------------------
// msm_msi_alloc_domains @ 0011d89c size=172
// signature: undefined msm_msi_alloc_domains(void)
// callers: [msm_msi_init]
//------------------------------------------------------------

undefined8 msm_msi_alloc_domains(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = __irq_domain_add(0,*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x24),0,
                           &msi_domain_ops,param_1);
  *(long *)(param_1 + 0x70) = lVar2;
  if (lVar2 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 0x10),"MSI: failed to create IRQ domain\n");
  }
  else {
    lVar1 = 0;
    if (*(long *)(param_1 + 0x18) != 0) {
      lVar1 = *(long *)(param_1 + 0x18) + 0x18;
    }
    lVar2 = pci_msi_create_irq_domain(lVar1,&msm_msi_domain_info,lVar2);
    *(long *)(param_1 + 0x78) = lVar2;
    if (lVar2 != 0) {
      return 0;
    }
    _dev_err(*(undefined8 *)(param_1 + 0x10),"MSI: failed to create MSI domain\n");
    irq_domain_remove(*(undefined8 *)(param_1 + 0x70));
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// msm_msi_snps_handler @ 0011d94c size=300
// signature: undefined msm_msi_snps_handler(void)
// callers: []
//------------------------------------------------------------

void msm_msi_snps_handler(long param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  undefined4 *puVar5;
  long lVar6;
  long lVar7;
  
  lVar6 = *(long *)(param_1 + 0x48);
  if (*(long *)(lVar6 + 0x48) == 0) {
    pcVar4 = *(code **)(lVar6 + 0x38);
    if (pcVar4 == (code *)0x0) {
      if (*(int *)(*(code **)(lVar6 + 0x30) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11d9a8);
        (*pcVar4)();
      }
      (**(code **)(lVar6 + 0x30))(param_1 + 0x30);
      pcVar4 = *(code **)(lVar6 + 0x28);
      if (pcVar4 == (code *)0x0) goto LAB_0011d9d4;
    }
    if (*(int *)(pcVar4 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11d9d0);
      (*pcVar4)();
    }
    (*pcVar4)(param_1 + 0x30);
  }
LAB_0011d9d4:
  lVar7 = *(long *)(param_1 + 8);
  uVar3 = readl_relaxed(*(undefined8 *)(lVar7 + 0x10));
  uVar2 = *(uint *)(lVar7 + 0x18);
  writel_relaxed(uVar2,*(undefined8 *)(lVar7 + 8));
  uVar3 = uVar3 & (uVar2 ^ 0xffffffff);
  writel_relaxed(uVar3,*(undefined8 *)(lVar7 + 0x10));
  if (uVar3 != 0) {
    puVar5 = (undefined4 *)(lVar7 + 0x38);
    do {
      if ((uVar3 & 1) != 0) {
        generic_handle_irq(*puVar5);
      }
      puVar5 = puVar5 + 8;
      bVar1 = 1 < uVar3;
      uVar3 = uVar3 >> 1;
    } while (bVar1);
  }
  pcVar4 = *(code **)(lVar6 + 0x48);
  if (pcVar4 == (code *)0x0) {
    pcVar4 = *(code **)(lVar6 + 0x40);
  }
  if (*(int *)(pcVar4 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11da5c);
    (*pcVar4)();
  }
  (*pcVar4)(param_1 + 0x30);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 0011da78 size=124
// signature: undefined readl_relaxed(void)
// callers: [msm_msi_snps_handler]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x11dac0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// msm_msi_qgic_handler @ 0011daf8 size=280
// signature: undefined msm_msi_qgic_handler(void)
// callers: []
//------------------------------------------------------------

void msm_msi_qgic_handler(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  long lVar4;
  undefined4 local_3c;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x48);
  if (*(long *)(lVar4 + 0x48) == 0) {
    pcVar3 = *(code **)(lVar4 + 0x38);
    if (pcVar3 == (code *)0x0) {
      if (*(int *)(*(code **)(lVar4 + 0x30) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11db60);
        (*pcVar3)();
      }
      (**(code **)(lVar4 + 0x30))(param_1 + 0x30);
      pcVar3 = *(code **)(lVar4 + 0x28);
      if (pcVar3 == (code *)0x0) goto LAB_0011db8c;
    }
    if (*(int *)(pcVar3 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11db88);
      (*pcVar3)();
    }
    (*pcVar3)(param_1 + 0x30);
  }
LAB_0011db8c:
  local_3c = 0;
  lVar2 = __irq_resolve_mapping
                    (*(undefined8 *)(*(long *)(param_1 + 8) + 0x70),*(undefined4 *)(param_1 + 0x34),
                     &local_3c);
  uVar1 = 0;
  if (lVar2 != 0) {
    uVar1 = local_3c;
  }
  generic_handle_irq(uVar1);
  pcVar3 = *(code **)(lVar4 + 0x48);
  if (pcVar3 == (code *)0x0) {
    pcVar3 = *(code **)(lVar4 + 0x40);
  }
  if (*(int *)(pcVar3 + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11dbdc);
    (*pcVar3)();
  }
  (*pcVar3)(param_1 + 0x30);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// msm_msi_irq_domain_alloc @ 0011dc14 size=364
// signature: undefined msm_msi_irq_domain_alloc(void)
// callers: []
//------------------------------------------------------------

undefined4 msm_msi_irq_domain_alloc(long param_1,int param_2,int param_3,long *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  
  plVar5 = *(long **)(param_1 + 0x20);
  lVar4 = *(long *)(*param_4 + 8);
  mutex_lock(plVar5 + 8);
  plVar6 = plVar5;
  do {
    plVar6 = (long *)*plVar6;
    if (plVar6 == plVar5) goto LAB_0011dd40;
  } while (plVar6[3] != lVar4);
  if (plVar6 == (long *)0x0) {
LAB_0011dd40:
    _dev_err(plVar5[2],"MSI: failed to find client dev\n");
    uVar3 = 0xffffffed;
  }
  else {
    iVar2 = bitmap_find_next_zero_area_off
                      (plVar5[7],(long)*(int *)((long)plVar5 + 0x24),0,param_3,param_3 + -1,0);
    if (iVar2 < *(int *)((long)plVar5 + 0x24)) {
      __bitmap_set(plVar5[7],iVar2,param_3);
      uVar3 = 0;
      if (param_3 != 0) {
        do {
          iVar1 = iVar2 + 0x1f;
          if (-1 < iVar2) {
            iVar1 = iVar2;
          }
          lVar4 = plVar5[6] + (ulong)(uint)(iVar1 >> 5) * 0x420 + (ulong)(uint)(iVar2 % 0x20) * 0x20
          ;
          *(long *)(lVar4 + 0x20) = (long)plVar6;
          *(int *)(lVar4 + 0x38) = param_2;
          irq_domain_set_info(param_1,param_2,*(undefined4 *)(lVar4 + 0x34),&msm_msi_bottom_irq_chip
                              ,(long *)(lVar4 + 0x20),&handle_simple_irq,0,0);
          iVar2 = iVar2 + 1;
          param_3 = param_3 + -1;
          param_2 = param_2 + 1;
          *(int *)(plVar6 + 4) = *(int *)(plVar6 + 4) + 1;
        } while (param_3 != 0);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0xffffffe4;
    }
  }
  mutex_unlock(plVar5 + 8);
  return uVar3;
}



//------------------------------------------------------------
// msm_msi_irq_domain_free @ 0011dd84 size=240
// signature: undefined msm_msi_irq_domain_free(void)
// callers: []
//------------------------------------------------------------

void msm_msi_irq_domain_free(undefined8 param_1,undefined4 param_2,int param_3)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 *puVar7;
  
  lVar4 = irq_domain_get_irq_data();
  if (lVar4 != 0) {
    puVar7 = *(undefined8 **)(lVar4 + 0x30);
    plVar6 = (long *)*puVar7;
    lVar4 = plVar6[2];
    mutex_lock(lVar4 + 0x40);
    __bitmap_clear(*(undefined8 *)(lVar4 + 0x38),*(undefined4 *)((long)puVar7 + 0x1c),param_3);
    iVar3 = (int)plVar6[4] - param_3;
    *(int *)(plVar6 + 4) = iVar3;
    if (iVar3 == 0) {
      if (*(int *)(lVar4 + 0x8c) == 0) {
        dma_unmap_resource(plVar6[3],plVar6[5],0x1000,2,0);
      }
      uVar5 = __list_del_entry_valid(plVar6);
      if ((uVar5 & 1) != 0) {
        lVar1 = *plVar6;
        plVar2 = (long *)plVar6[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      kfree(plVar6);
    }
    mutex_unlock(lVar4 + 0x40);
    irq_domain_free_irqs_parent(param_1,param_2,param_3);
  }
  return;
}



//------------------------------------------------------------
// msm_msi_irq_set_affinity @ 0011de78 size=116
// signature: undefined msm_msi_irq_set_affinity(void)
// callers: []
//------------------------------------------------------------

undefined8 msm_msi_irq_set_affinity(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  lVar1 = irq_get_irq_data(*(undefined4 *)(param_1 + 8));
  if (lVar1 == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    pcVar3 = *(code **)(*(long *)(lVar1 + 0x18) + 0x50);
    if (pcVar3 == (code *)0x0) {
      uVar2 = 0xffffffea;
    }
    else {
      if (*(int *)(pcVar3 + -4) != 0x5b961711) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11dec8);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)(lVar1,param_2,param_3 & 1);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// msm_msi_irq_compose_msi_msg @ 0011def0 size=100
// signature: undefined msm_msi_irq_compose_msi_msg(void)
// callers: []
//------------------------------------------------------------

void msm_msi_irq_compose_msi_msg(long param_1,undefined4 *param_2)

{
  long lVar1;
  undefined4 uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  
  plVar5 = *(long **)(param_1 + 0x30);
  lVar1 = irq_get_irq_data(*(undefined4 *)(param_1 + 8));
  if (lVar1 != 0) {
    lVar3 = *plVar5;
    lVar4 = *(long *)(lVar3 + 0x10);
    *param_2 = (int)*(undefined8 *)(lVar3 + 0x28);
    param_2[1] = *(undefined4 *)(lVar3 + 0x2c);
    if (*(int *)(lVar4 + 0x8c) == 0) {
      uVar2 = *(undefined4 *)(lVar1 + 8);
    }
    else {
      uVar2 = *(undefined4 *)((long)plVar5 + 0x1c);
    }
    param_2[2] = uVar2;
  }
  return;
}



//------------------------------------------------------------
// msm_msi_domain_prepare @ 0011df58 size=256
// signature: undefined msm_msi_domain_prepare(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_msi_domain_prepare(long param_1,long param_2,undefined8 param_3,undefined8 *param_4)

{
  long *plVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  long *plVar6;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x50) + 0x20);
  plVar1 = (long *)kmalloc_trace(_pci_save_state,0xdc0,0x30);
  if (plVar1 == (long *)0x0) {
LAB_0011e03c:
    uVar4 = 0xfffffff4;
  }
  else {
    plVar1[2] = lVar5;
    plVar1[3] = param_2;
    plVar1[5] = *(long *)(lVar5 + 0x80);
    if (*(int *)(lVar5 + 0x8c) == 0) {
      lVar2 = dma_map_resource(param_2,*(undefined8 *)(lVar5 + 0x80),*(undefined4 *)(lVar5 + 0x88),2
                               ,0);
      plVar1[5] = lVar2;
      if (lVar2 == -1) {
        _dev_err(*(undefined8 *)(lVar5 + 0x10),"MSI: failed to map msi address\n");
        plVar1[5] = 0;
        kfree(plVar1);
        goto LAB_0011e03c;
      }
    }
    mutex_lock(lVar5 + 0x40);
    plVar6 = *(long **)(lVar5 + 8);
    uVar3 = __list_add_valid(plVar1,plVar6,lVar5);
    if ((uVar3 & 1) != 0) {
      *(long **)(lVar5 + 8) = plVar1;
      *plVar1 = lVar5;
      plVar1[1] = (long)plVar6;
      *plVar6 = (long)plVar1;
    }
    mutex_unlock(lVar5 + 0x40);
    uVar4 = 0;
    param_4[3] = 0;
    param_4[4] = 0;
    param_4[1] = 0;
    param_4[2] = 0;
    *param_4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// msm_msi_unmask_irq @ 0011e05c size=140
// signature: undefined msm_msi_unmask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_unmask_irq(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x28) != 0) {
    lVar3 = *(long *)(**(long **)(*(long *)(param_1 + 0x28) + 0x30) + 0x10);
    if (*(int *)(*(code **)(lVar3 + 0xa8) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11e0a4);
      (*pcVar1)();
    }
    (**(code **)(lVar3 + 0xa8))();
    uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x90);
    if (*(char *)(lVar3 + 0x94) != '\0') {
      pci_msi_unmask_irq(param_1);
    }
    _raw_spin_unlock_irqrestore(lVar3 + 0x90,uVar2);
  }
  return;
}



//------------------------------------------------------------
// msm_msi_mask_irq @ 0011e0ec size=152
// signature: undefined msm_msi_mask_irq(void)
// callers: []
//------------------------------------------------------------

void msm_msi_mask_irq(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 0x28);
  if (lVar3 != 0) {
    lVar4 = *(long *)(**(long **)(lVar3 + 0x30) + 0x10);
    uVar2 = _raw_spin_lock_irqsave(lVar4 + 0x90);
    if (*(char *)(lVar4 + 0x94) != '\0') {
      pci_msi_mask_irq(param_1);
    }
    _raw_spin_unlock_irqrestore(lVar4 + 0x90,uVar2);
    if (*(int *)(*(code **)(lVar4 + 0xa0) + -4) != 0x4c4af168) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x11e168);
      (*pcVar1)();
    }
    (**(code **)(lVar4 + 0xa0))(lVar3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0011faa4 size=1312
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  pcie_drv = 0;
  __mutex_init(&DAT_00130190,"&pcie_drv.drv_lock",&pcie_init___key);
  __mutex_init(&DAT_001301c0,"&pcie_drv.rpmsg_lock",&pcie_init___key_806);
  iVar1 = i2c_register_driver(&__this_module,pcie_i2c_ctrl_driver);
  if (iVar1 != 0) {
    _printk(&DAT_0012bf10,iVar1);
  }
  crc8_populate_msb(msm_pcie_crc8_table,7);
  rc_sel_max = 1;
  wr_mask = 0xffffffff;
  dent_msm_pcie = debugfs_create_dir("pci-msm",0);
  if (dent_msm_pcie < 0xfffffffffffff001) {
    dfile_rc_sel = debugfs_create_file("rc_sel",0x1b4,dent_msm_pcie,0,msm_pcie_debugfs_rc_select_ops
                                      );
    puVar2 = &DAT_00121f05;
    if ((dfile_rc_sel != 0) && (dfile_rc_sel < 0xfffffffffffff001)) {
      dfile_case = debugfs_create_file(&DAT_00129072,0x1b4,dent_msm_pcie,0,msm_pcie_debugfs_case_ops
                                      );
      puVar2 = &DAT_00127fec;
      if ((dfile_case != 0) && (dfile_case < 0xfffffffffffff001)) {
        dfile_base_sel =
             debugfs_create_file("base_sel",0x1b4,dent_msm_pcie,0,msm_pcie_debugfs_base_select_ops);
        puVar2 = &DAT_0012ecc2;
        if ((dfile_base_sel != 0) && (dfile_base_sel < 0xfffffffffffff001)) {
          dfile_linkdown_panic =
               debugfs_create_file("linkdown_panic",0x1a4,dent_msm_pcie,0,
                                   msm_pcie_debugfs_linkdown_panic_ops);
          puVar2 = &DAT_00124137;
          if ((dfile_linkdown_panic != 0) && (dfile_linkdown_panic < 0xfffffffffffff001)) {
            dfile_wr_offset =
                 debugfs_create_file("wr_offset",0x1b4,dent_msm_pcie,0,
                                     msm_pcie_debugfs_wr_offset_ops);
            puVar2 = &DAT_0012162a;
            if ((dfile_wr_offset != 0) && (dfile_wr_offset < 0xfffffffffffff001)) {
              dfile_wr_mask =
                   debugfs_create_file("wr_mask",0x1b4,dent_msm_pcie,0,msm_pcie_debugfs_wr_mask_ops)
              ;
              puVar2 = &DAT_00121f45;
              if ((dfile_wr_mask != 0) && (dfile_wr_mask < 0xfffffffffffff001)) {
                dfile_wr_value =
                     debugfs_create_file("wr_value",0x1b4,dent_msm_pcie,0,
                                         msm_pcie_debugfs_wr_value_ops);
                puVar2 = &DAT_0012af43;
                if ((dfile_wr_value != 0) && (dfile_wr_value < 0xfffffffffffff001)) {
                  dfile_boot_option =
                       debugfs_create_file("boot_option",0x1b4,dent_msm_pcie,0,
                                           msm_pcie_debugfs_boot_option_ops);
                  puVar2 = &DAT_001279c9;
                  if ((dfile_boot_option != 0) && (dfile_boot_option < 0xfffffffffffff001)) {
                    dfile_aer_enable =
                         debugfs_create_file("aer_enable",0x1b4,dent_msm_pcie,0,
                                             msm_pcie_debugfs_aer_enable_ops);
                    puVar2 = &DAT_0012b79d;
                    if ((dfile_aer_enable != 0) && (dfile_aer_enable < 0xfffffffffffff001)) {
                      dfile_corr_counter_limit =
                           debugfs_create_file("corr_counter_limit",0x1b4,dent_msm_pcie,0,
                                               msm_pcie_debugfs_corr_counter_limit_ops);
                      puVar2 = &DAT_00126688;
                      if ((dfile_corr_counter_limit != 0) &&
                         (dfile_corr_counter_limit < 0xfffffffffffff001)) goto LAB_0011fde4;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    _printk(puVar2);
    debugfs_remove(dent_msm_pcie);
  }
  else {
    _printk(&DAT_001249be);
  }
LAB_0011fde4:
  if ((count == 5) && (0 < DAT_00130034)) {
    iVar1 = 0;
    do {
      uVar3 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar3 = 0x68000000000f13;
      }
      uVar3 = ioremap_prot((long)(DAT_00130028 + pcie_sm_regs + DAT_00130030 * iVar1),4,uVar3);
      writel_relaxed(1,uVar3);
      readl_relaxed(uVar3);
      iounmap(uVar3);
      uVar3 = 0x68000000000713;
      if (arm64_use_ng_mappings != '\0') {
        uVar3 = 0x68000000000f13;
      }
      uVar3 = ioremap_prot((long)(DAT_0013002c + pcie_sm_regs + DAT_00130030 * iVar1),4,uVar3);
      writel_relaxed(1,uVar3);
      readl_relaxed(uVar3);
      iounmap(uVar3);
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_00130034);
  }
  iVar1 = __pci_register_driver(msm_pci_driver,&__this_module,"pci_msm_drv");
  if (iVar1 == 0) {
    mpcie_wq = alloc_workqueue("mpcie_wq",0xa001a,1);
    if (mpcie_wq == 0) {
      iVar1 = -0xc;
    }
    else {
      DAT_001301f0 = msm_pcie_ssr_notifier;
      DAT_00130160 = 0xfffffffe0;
      DAT_00130168 = &DAT_00130168;
      DAT_00130170 = &DAT_00130168;
      DAT_00130178 = msm_pcie_drv_connect_notify_all;
      msm_pcie_dev = 0;
      DAT_0012fff8 = 0;
      DAT_00130000 = 0;
      DAT_00130008 = 0;
      DAT_00130010 = 0;
      DAT_00130150 = &msm_pcie_dev;
      iVar1 = __platform_driver_register(&msm_pcie_driver,&__this_module);
      if (iVar1 != 0) {
        destroy_workqueue(mpcie_wq);
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0011ffc8 size=200
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  
  _printk(&DAT_0012ff08,"pcie_exit");
  i2c_del_driver(pcie_i2c_ctrl_driver);
  if (mpcie_wq != 0) {
    destroy_workqueue();
  }
  platform_driver_unregister(&msm_pcie_driver);
  debugfs_remove(dent_msm_pcie);
  lVar2 = 0;
  do {
    plVar3 = *(long **)((long)&msm_pcie_dev + lVar2);
    lVar1 = *plVar3;
    if (lVar1 != 0) {
      sysfs_remove_group(lVar1 + 0x10,&msm_pcie_debug_attr_group);
      sysfs_remove_group(*plVar3 + 0x10,&msm_aer_stats_attr_group);
    }
    lVar2 = lVar2 + 8;
  } while (lVar2 != 0x28);
  return;
}



//------------------------------------------------------------
// ipc_log_string @ 00135000 size=1
// signature: undefined ipc_log_string(void)
// callers: [msm_pcie_config_l0s, msm_aer_print_error, handle_wake_func, msm_pcie_handle_linkdown, msm_pcie_save_sid_config, ntn3_ep_reset_ctrl, msm_pcie_deenumerate, msm_pcie_notify_client, msm_pcie_pm_suspend_noirq, ntn3_dump_regs, msm_pcie_icc_vote, msm_pcie_rumi_init, msm_pcie_debugfs_aer_enable, msm_pcie_pm_suspend, msm_pcie_config_device_info, msm_pcie_clk_deinit, pcie_parf_dump, msm_aer_process_err_devices, msm_pcie_gdsc_deinit, msm_pcie_config_tc_bdf_sid_map, pcie_sm_dump, msm_pcie_confirm_linkup, msm_pcie_disable_cesta, sbr_link_recovery_store, msm_pcie_enable_link, msm_pcie_oper_conf, handle_aer_irq, msm_pcie_link_retrain, msm_pcie_pm_resume, msm_pcie_drv_notify_client, msm_pcie_gpio_deinit, msm_pcie_dsp_link_control, msm_find_source_device, pcie_dm_core_dump, msm_pcie_show_status, msm_pcie_loopback, msm_pcie_cesta_curr_perf_ol, msm_pcie_check_l1ss_support, msm_aer_get_device_error_info, msm_pcie_enable, msm_pcie_restore_sid_config, msm_pcie_config_clock_power_management_enable, msm_pci_probe, handle_link_recover, msm_pcie_config_controller, msm_pcie_drv_connect_notify_all, msm_pcie_config_l1, msm_pcie_pipe_reset, msm_pcie_gpio_init, msm_pcie_scale_link_bandwidth, boot_option_store, msm_pcie_set_link_bandwidth, msm_pcie_ssr_notifier, msm_pcie_pm_control, msm_pcie_allow_l1, msm_pcie_check_link_dev_status, msm_pcie_check_l0s_support, msm_pcie_prevent_l1, msm_pcie_clk_dump, msm_pcie_drv_rpmsg_cb, msm_pcie_fixup_resume_early, msm_pcie_fixup_suspend, msm_pcie_core_phy_reset, msm_pcie_vreg_deinit_analog_rails, msm_pcie_debugfs_boot_option, msm_pcie_config_common_clock_enable, msm_pcie_vreg_deinit, msm_pcie_pm_resume_noirq, msm_pcie_check_ep_access, msm_pcie_config_l1ss, msm_pcie_pipe_clk_init, msm_pcie_config_perst, l23_rdy_poll_timeout_store, msm_pcie_cesta_map_apply, msm_pcie_fixup_resume, handle_global_irq, msm_pcie_sel_debug_testcase, msm_pcie_config_l1_2_threshold, msm_pcie_drv_rpmsg_remove, msm_pcie_disable, msm_pcie_set_target_link_speed, msm_pcie_pipe_clk_deinit, msm_pcie_drv_send_rpmsg, pcie_phy_dump, msm_pcie_register_event, msm_pcie_vreg_init, msm_pcie_deregister_event, pcie_crm_dump, msm_pcie_ecam_oper_conf, ntn3_de_emphasis_wa, msm_pcie_probe, msm_aer_print_port_info, msm_pcie_debugfs_linkdown_panic, handle_sbr_func, msm_pcie_reg_dump, handle_wake_irq, msm_pcie_fmd_enable, msm_pcie_enumerate, msm_pcie_remove, msm_pcie_access_reg, link_speed_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00135008 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [msm_pcie_reg_dump, msm_pcie_debugfs_parse_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00135010 size=1
// signature: undefined _printk(void)
// callers: [msm_pcie_gpio_init, msm_pcie_debugfs_wr_offset, msm_pcie_debugfs_corr_counter_limit, msm_pcie_scale_link_bandwidth, msm_pcie_debugfs_base_select, handle_wake_func, boot_option_store, msm_pcie_set_link_bandwidth, msm_pcie_handle_linkdown, msm_pcie_save_sid_config, msm_pcie_pm_control, msm_pcie_allow_l1, msm_pcie_check_link_dev_status, msm_pcie_debug_info, msm_pcie_pm_suspend_noirq, msm_pcie_icc_vote, msm_pcie_prevent_l1, msm_pcie_debugfs_aer_enable, msm_pcie_clk_dump, msm_pcie_drv_rpmsg_cb, msm_pcie_pm_suspend, msm_pcie_config_device_info, msm_pcie_fixup_resume_early, msm_pcie_fixup_suspend, msm_pcie_gdsc_deinit, msm_pcie_core_phy_reset, init_module, msm_pcie_config_tc_bdf_sid_map, msm_pcie_confirm_linkup, msm_pcie_disable_cesta, msm_pcie_debugfs_boot_option, msm_pcie_vreg_deinit, msm_pcie_pm_resume_noirq, msm_pcie_check_ep_access, msm_pcie_enable_link, msm_pcie_pipe_clk_init, msm_pcie_config_perst, msm_pcie_oper_conf, cleanup_module, msm_pcie_fixup_resume, msm_pcie_link_retrain, msm_pcie_pm_resume, msm_pcie_sel_debug_testcase, msm_pcie_drv_rpmsg_remove, msm_pcie_disable, msm_pcie_set_target_link_speed, msm_pcie_show_status, msm_pcie_drv_send_rpmsg, msm_pcie_debugfs_wr_mask, msm_pcie_loopback, msm_pcie_cesta_curr_perf_ol, msm_pcie_register_event, msm_pcie_vreg_init, msm_pcie_deregister_event, msm_pcie_enable, msm_pcie_ecam_oper_conf, msm_pci_probe, msm_pcie_probe, msm_pcie_debugfs_case_select, msm_pcie_drv_connect_notify_all, msm_pcie_debugfs_linkdown_panic, handle_sbr_func, msm_pcie_reg_dump, msm_pcie_fmd_enable, msm_pcie_pipe_reset, msm_pcie_debugfs_rc_select, msm_pcie_enumerate, msm_pcie_debugfs_wr_value, msm_pcie_remove, msm_pcie_access_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00135018 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00135020 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 00135028 size=1
// signature: undefined gpio_to_desc(void)
// callers: [msm_pcie_gpio_init, msm_pcie_config_perst, msm_pcie_disable, msm_pcie_enable, msm_pcie_fmd_enable, msm_pcie_probe, msm_pcie_sel_debug_testcase, msm_pcie_handle_linkdown, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 00135030 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [msm_pcie_fmd_enable, msm_pcie_sel_debug_testcase, msm_pcie_handle_linkdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 00135038 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [msm_pcie_config_perst, msm_pcie_disable, msm_pcie_enable, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00135040 size=1
// signature: undefined mutex_lock(void)
// callers: [msm_pcie_drv_connect_worker, msm_pcie_fixup_resume, handle_wake_func, msm_pcie_drv_notify_client, msm_pcie_drv_rpmsg_probe, msm_pcie_sel_debug_testcase, msm_pcie_drv_rpmsg_remove, msm_msi_irq_domain_free, msm_pcie_disable, msm_pcie_pm_control, msm_pcie_drv_send_rpmsg, msm_pcie_deenumerate, msm_pcie_allow_l1, msm_pcie_pm_suspend_noirq, aspm_stat_show, msm_pcie_prevent_l1, msm_msi_domain_prepare, msm_pcie_enable, msm_msi_irq_domain_alloc, msm_pcie_fixup_resume_early, msm_pcie_fixup_suspend, msm_pcie_probe, msm_pcie_drv_connect_notify_all, msm_pcie_pm_resume_noirq, msm_pcie_enumerate, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_walk_bus @ 00135048 size=1
// signature: undefined pci_walk_bus(void)
// callers: [msm_pcie_config_l1ss_enable_all, msm_pcie_config_link_pm, msm_pcie_poll_for_l0_from_l0s, msm_pcie_config_l0s_enable_all, msm_pcie_allow_l1, msm_pcie_enumerate, msm_find_source_device, msm_pcie_sel_debug_testcase]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_walk_bus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00135050 size=1
// signature: undefined mutex_unlock(void)
// callers: [msm_pcie_drv_connect_worker, msm_pcie_fixup_resume, handle_wake_func, msm_pcie_drv_notify_client, msm_pcie_drv_rpmsg_probe, msm_pcie_sel_debug_testcase, msm_pcie_drv_rpmsg_remove, msm_msi_irq_domain_free, msm_pcie_disable, msm_pcie_pm_control, msm_pcie_drv_send_rpmsg, msm_pcie_deenumerate, msm_pcie_allow_l1, msm_pcie_pm_suspend_noirq, aspm_stat_show, msm_pcie_prevent_l1, msm_msi_domain_prepare, msm_pcie_enable, msm_msi_irq_domain_alloc, msm_pcie_fixup_resume_early, msm_pcie_fixup_suspend, msm_pcie_probe, msm_pcie_drv_connect_notify_all, msm_pcie_pm_resume_noirq, msm_pcie_enumerate, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00135058 size=1
// signature: undefined usleep_range_state(void)
// callers: [msm_pcie_rumi_init, msm_pcie_prevent_l1, msm_pcie_enable, msm_pcie_pm_suspend, msm_pcie_dsp_link_control, msm_pcie_sel_debug_testcase, msm_pcie_core_phy_reset, handle_sbr_func, msm_pcie_drv_send_rpmsg, msm_pcie_pipe_reset, msm_pcie_check_ep_access, msm_pcie_pm_suspend_noirq, msm_pcie_loopback, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_clk_dump @ 00135060 size=1
// signature: undefined qcom_clk_dump(void)
// callers: [msm_pcie_clk_dump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_clk_dump(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00135068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [msm_pcie_config_l0s, msm_aer_print_error, msm_msi_init, msm_pcie_debugfs_base_select, msm_pcie_read_devid_all, boot_option_store, msm_pcie_set_link_bandwidth, ntn3_ep_reset_ctrl, msm_pcie_notify_client, msm_pcie_check_l0s_support, msm_pcie_pm_suspend_noirq, ntn3_dump_regs, msm_pcie_debugfs_aer_enable, msm_pcie_config_sid, msm_aer_process_err_devices, msm_find_device_iter, msm_pcie_debugfs_boot_option, msm_pcie_config_common_clock_enable, sbr_link_recovery_store, msm_pcie_pm_resume_noirq, link_check_max_count_store, msm_pcie_config_l1ss, msm_pcie_enable_link, l23_rdy_poll_timeout_store, msm_pcie_cesta_map_apply, msm_of_pci_parse_bus_range, handle_global_irq, handle_aer_irq, msm_pcie_link_retrain, msm_pcie_config_bandwidth_int, msm_pcie_dsp_link_control, ntn3_i2c_read, msm_pcie_config_l1_2_threshold, panic_on_aer_store, msm_pcie_wr_conf, msm_pcie_loopback, msm_pcie_cesta_curr_perf_ol, msm_pcie_check_l1ss_support, msm_aer_get_device_error_info, msm_pcie_config_clock_power_management_enable, ntn3_de_emphasis_wa, pcie_i2c_ctrl_probe, msm_pcie_probe, msm_pcie_ecam_wr_conf, msm_pcie_debugfs_case_select, msm_pcie_config_l1, msm_pcie_debugfs_linkdown_panic, msm_msi_qgic_handler, msm_pcie_debugfs_parse_input, ntn3_i2c_write, msm_pcie_debugfs_rc_select, msm_pcie_enumerate, msm_pcie_remove, msm_pcie_access_reg, link_speed_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_ecam_create @ 00135070 size=1
// signature: undefined pci_ecam_create(void)
// callers: [msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_ecam_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00135080 size=1
// signature: undefined kmalloc_trace(void)
// callers: [msm_msi_init, msm_msi_domain_prepare, msm_pcie_config_device_info, msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_host_probe @ 00135088 size=1
// signature: undefined pci_host_probe(void)
// callers: [msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_host_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00135090 size=1
// signature: undefined queue_work_on(void)
// callers: [msm_pcie_register_event, msm_pcie_drv_connect_worker, msm_pcie_oper_conf, handle_global_irq, handle_wake_irq, msm_pcie_pm_control, msm_pcie_drv_rpmsg_probe, msm_pcie_enumerate, msm_pcie_handle_linkdown, msm_pcie_drv_connect_notify_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_pci_domain_nr @ 00135098 size=1
// signature: undefined of_get_pci_domain_nr(void)
// callers: [msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_pci_domain_nr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_get_domain_bus_and_slot @ 001350a0 size=1
// signature: undefined pci_get_domain_bus_and_slot(void)
// callers: [msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_get_domain_bus_and_slot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_save_state @ 001350a8 size=1
// signature: undefined pci_save_state(void)
// callers: [msm_pcie_pm_suspend, msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_save_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_store_saved_state @ 001350b0 size=1
// signature: undefined pci_store_saved_state(void)
// callers: [msm_pcie_pm_suspend, msm_pcie_enumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_store_saved_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_dev_put @ 001350b8 size=1
// signature: undefined pci_dev_put(void)
// callers: [msm_pcie_enumerate, msm_aer_process_err_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_dev_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 001350c0 size=1
// signature: undefined regulator_enable(void)
// callers: [msm_pcie_vreg_init, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_pm_resume_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_parent @ 001350c8 size=1
// signature: undefined clk_set_parent(void)
// callers: [msm_pcie_enable, msm_pcie_pm_control, msm_pcie_clk_deinit, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 001350d0 size=1
// signature: undefined clk_set_rate(void)
// callers: [msm_pcie_pipe_clk_init, msm_pcie_scale_link_bandwidth, msm_pcie_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 001350d8 size=1
// signature: undefined clk_prepare(void)
// callers: [msm_pcie_pipe_clk_init, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_pm_resume_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 001350e0 size=1
// signature: undefined clk_enable(void)
// callers: [msm_pcie_pipe_clk_init, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_pm_resume_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 001350e8 size=1
// signature: undefined clk_unprepare(void)
// callers: [msm_pcie_pipe_clk_init, msm_pcie_pipe_clk_deinit, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_clk_deinit, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 001350f0 size=1
// signature: undefined msleep(void)
// callers: [msm_pcie_enable, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 001350f8 size=1
// signature: undefined clk_disable(void)
// callers: [msm_pcie_pipe_clk_init, msm_pcie_pipe_clk_deinit, msm_pcie_enable, msm_pcie_pm_control, msm_pcie_clk_deinit, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_enable_device @ 00135100 size=1
// signature: undefined pci_enable_device(void)
// callers: [msm_pcie_config_device_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_enable_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_set_master @ 00135108 size=1
// signature: undefined pci_set_master(void)
// callers: [msm_pcie_config_device_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_set_master(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_enable_pcie_error_reporting @ 00135110 size=1
// signature: undefined pci_enable_pcie_error_reporting(void)
// callers: [msm_pcie_config_device_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_enable_pcie_error_reporting(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00135118 size=1
// signature: undefined __list_add_valid(void)
// callers: [msm_pcie_register_event, msm_msi_domain_prepare, msm_pcie_pm_control, msm_pcie_config_device_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00135120 size=1
// signature: undefined cancel_work_sync(void)
// callers: [msm_pcie_pm_suspend, msm_pcie_drv_notify_client, msm_pcie_deenumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00135128 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [msm_pcie_register_event, msm_pcie_oper_conf, handle_global_irq, handle_aer_irq, msm_pcie_deregister_event, msm_msi_mask_irq, msm_pcie_pm_suspend, msm_pcie_pm_resume, msm_msi_snps_unmask_irq, msm_pcie_ecam_oper_conf, msm_pcie_fixup_suspend, msm_aer_process_err_devices, msm_msi_snps_mask_irq, msm_msi_config, msm_msi_config_access, handle_wake_irq, msm_pcie_pm_control, msm_pcie_deenumerate, msm_pcie_notify_client, msm_msi_unmask_irq, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00135130 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [msm_pcie_register_event, msm_pcie_oper_conf, handle_global_irq, handle_aer_irq, msm_pcie_deregister_event, msm_msi_mask_irq, msm_pcie_pm_suspend, msm_pcie_pm_resume, msm_msi_snps_unmask_irq, msm_pcie_ecam_oper_conf, msm_pcie_fixup_suspend, msm_aer_process_err_devices, msm_msi_snps_mask_irq, msm_msi_config, msm_msi_config_access, handle_wake_irq, msm_pcie_pm_control, msm_pcie_deenumerate, msm_pcie_notify_client, msm_msi_unmask_irq, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_stop_root_bus @ 00135138 size=1
// signature: undefined pci_stop_root_bus(void)
// callers: [msm_pcie_deenumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_stop_root_bus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_remove_root_bus @ 00135140 size=1
// signature: undefined pci_remove_root_bus(void)
// callers: [msm_pcie_deenumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_remove_root_bus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_ecam_free @ 00135148 size=1
// signature: undefined pci_ecam_free(void)
// callers: [msm_pcie_deenumerate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_ecam_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00135150 size=1
// signature: undefined kfree(void)
// callers: [msm_msi_irq_domain_free, msm_msi_init, msm_pcie_debugfs_parse_input, msm_msi_domain_prepare, msm_pcie_pm_suspend, msm_pcie_deenumerate, msm_pcie_probe, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00135158 size=1
// signature: undefined _find_next_bit(void)
// callers: [msm_aer_print_error]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_read_config_dword @ 00135160 size=1
// signature: undefined pci_read_config_dword(void)
// callers: [msm_pcie_config_l0s, msm_pcie_check_l1ss_support, handle_global_irq, msm_aer_get_device_error_info, msm_pcie_link_retrain, msm_pcie_config_bandwidth_int, msm_pcie_config_clock_power_management_enable, msm_pcie_dsp_link_control, msm_pcie_set_link_bandwidth, msm_aer_process_err_devices, msm_pcie_config_l1_2_threshold, msm_pcie_config_l1, msm_find_device_iter, msm_pcie_config_common_clock_enable, msm_pcie_config_l1ss, msm_pcie_check_l0s_support]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_read_config_dword(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_read_config_word @ 00135168 size=1
// signature: undefined pci_read_config_word(void)
// callers: [msm_pcie_read_devid_all, msm_pcie_dsp_link_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_read_config_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_write_config_word @ 00135170 size=1
// signature: undefined pci_write_config_word(void)
// callers: [msm_pcie_dsp_link_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_write_config_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_dump_regs @ 00135178 size=1
// signature: undefined crm_dump_regs(void)
// callers: [handle_wake_irq, pcie_crm_dump, msm_aer_process_err_devices, msm_pcie_handle_linkdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_dump_regs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pcie_capability_read_word @ 00135180 size=1
// signature: undefined pcie_capability_read_word(void)
// callers: [msm_find_device_iter, msm_aer_get_device_error_info, msm_pcie_set_link_bandwidth]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pcie_capability_read_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_write_config_dword @ 00135188 size=1
// signature: undefined pci_write_config_dword(void)
// callers: [msm_pcie_config_l0s, msm_pcie_config_l1_2_threshold, msm_pcie_config_l1, handle_global_irq, msm_pcie_link_retrain, msm_pcie_config_bandwidth_int, msm_pcie_config_common_clock_enable, msm_pcie_config_clock_power_management_enable, msm_pcie_config_l1ss, msm_pcie_set_link_bandwidth, msm_aer_process_err_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_write_config_dword(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 00135190 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [msm_pcie_vreg_init, msm_pcie_scale_link_bandwidth, msm_pcie_vreg_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00135198 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [msm_pcie_link_retrain, msm_pcie_drv_send_rpmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_tag @ 001351a0 size=1
// signature: undefined icc_set_tag(void)
// callers: [msm_pcie_icc_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_tag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 001351a8 size=1
// signature: undefined icc_set_bw(void)
// callers: [msm_pcie_icc_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_write_pwr_states @ 001351b0 size=1
// signature: undefined crm_write_pwr_states(void)
// callers: [msm_pcie_icc_vote, msm_pcie_cesta_map_apply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_write_pwr_states(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001351b8 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module, msm_msi_init, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 001351c0 size=1
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
// crc8_populate_msb @ 001351c8 size=1
// signature: undefined crc8_populate_msb(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crc8_populate_msb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001351d0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001351d8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001351e0 size=1
// signature: undefined debugfs_remove(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ioremap_prot @ 001351f0 size=1
// signature: undefined ioremap_prot(void)
// callers: [init_module, msm_msi_init, msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ioremap_prot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iounmap @ 001351f8 size=1
// signature: undefined iounmap(void)
// callers: [init_module, msm_msi_init, msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iounmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pci_register_driver @ 00135200 size=1
// signature: undefined __pci_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pci_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00135208 size=1
// signature: undefined alloc_workqueue(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00135210 size=1
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
// destroy_workqueue @ 00135218 size=1
// signature: undefined destroy_workqueue(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 00135220 size=1
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
// platform_driver_unregister @ 00135228 size=1
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
// sysfs_remove_group @ 00135230 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 00135238 size=1
// signature: undefined flush_work(void)
// callers: [msm_pcie_drv_rpmsg_remove, msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 00135240 size=1
// signature: undefined disable_irq(void)
// callers: [msm_pcie_pm_control, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00135248 size=1
// signature: undefined enable_irq(void)
// callers: [msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00135250 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [msm_msi_irq_domain_free, msm_pcie_deregister_event, msm_pcie_pm_control, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_gpio_mpm_wake_set @ 00135260 size=1
// signature: undefined msm_gpio_mpm_wake_set(void)
// callers: [msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_gpio_mpm_wake_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pcie_pdc_cfg_irq @ 00135268 size=1
// signature: undefined pcie_pdc_cfg_irq(void)
// callers: [msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pcie_pdc_cfg_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 00135270 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 00135278 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [msm_pcie_pm_control]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00135280 size=1
// signature: undefined regulator_disable(void)
// callers: [msm_pcie_gdsc_deinit, msm_pcie_vreg_init, msm_pcie_vreg_deinit_analog_rails, msm_pcie_pm_control, msm_pcie_vreg_deinit, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_load_saved_state @ 00135288 size=1
// signature: undefined pci_load_saved_state(void)
// callers: [msm_pcie_pm_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_load_saved_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00135290 size=1
// signature: undefined ktime_get(void)
// callers: [msm_pcie_pm_suspend, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00135298 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [msm_pcie_pm_suspend, msm_pcie_pm_resume, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_set_power_state @ 001352a0 size=1
// signature: undefined pci_set_power_state(void)
// callers: [msm_pcie_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_set_power_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_load_and_free_saved_state @ 001352a8 size=1
// signature: undefined pci_load_and_free_saved_state(void)
// callers: [msm_pcie_pm_resume, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_load_and_free_saved_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_restore_state @ 001352b0 size=1
// signature: undefined pci_restore_state(void)
// callers: [msm_pcie_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_restore_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001352b8 size=1
// signature: undefined __const_udelay(void)
// callers: [msm_pcie_handle_linkdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 001352c0 size=1
// signature: noreturn undefined panic(void)
// callers: [msm_aer_process_err_devices, msm_pcie_handle_linkdown, msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001352c8 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [msm_pcie_register_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 001352d0 size=1
// signature: undefined dma_set_mask(void)
// callers: [msm_pci_probe, msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 001352d8 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [msm_pci_probe, msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 001352e0 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 001352e8 size=1
// signature: undefined get_random_bytes(void)
// callers: [msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001352f0 size=1
// signature: undefined dma_free_attrs(void)
// callers: [msm_pcie_loopback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_find_ext_capability @ 001352f8 size=1
// signature: undefined pci_find_ext_capability(void)
// callers: [msm_pcie_config_l1_2_threshold, msm_pcie_check_l1ss_support, msm_aer_get_device_error_info, msm_pcie_config_l1ss]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_find_ext_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00135300 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writeb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00135308 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed, writeb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_generic_config_write @ 00135310 size=1
// signature: undefined pci_generic_config_write(void)
// callers: [msm_pcie_ecam_oper_conf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_generic_config_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_generic_config_read @ 00135318 size=1
// signature: undefined pci_generic_config_read(void)
// callers: [msm_pcie_ecam_oper_conf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_generic_config_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 00135320 size=1
// signature: undefined regulator_set_load(void)
// callers: [msm_pcie_vreg_init, msm_pcie_vreg_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00135328 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [msm_pcie_vreg_init, msm_pcie_vreg_deinit_analog_rails, msm_pcie_vreg_deinit, msm_pcie_probe, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 00135330 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [msm_pcie_gpio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 00135338 size=1
// signature: undefined gpio_request(void)
// callers: [msm_pcie_gpio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00135340 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [msm_pcie_gpio_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00135348 size=1
// signature: undefined gpio_free(void)
// callers: [msm_pcie_gpio_init, msm_pcie_gpio_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_assert @ 00135350 size=1
// signature: undefined reset_control_assert(void)
// callers: [msm_pcie_core_phy_reset, handle_sbr_func, msm_pcie_pipe_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_assert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// reset_control_deassert @ 00135358 size=1
// signature: undefined reset_control_deassert(void)
// callers: [msm_pcie_core_phy_reset, handle_sbr_func, msm_pcie_pipe_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void reset_control_deassert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_usecs @ 00135368 size=1
// signature: undefined jiffies_to_usecs(void)
// callers: [msm_pcie_enable_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_usecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00135370 size=1
// signature: undefined devm_kmalloc(void)
// callers: [msm_pci_probe, msm_pcie_probe, msm_pcie_save_sid_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00135378 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [msm_pcie_save_sid_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_toio @ 00135380 size=1
// signature: undefined __memcpy_toio(void)
// callers: [msm_pcie_restore_sid_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_toio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_write_perf_ol @ 00135388 size=1
// signature: undefined crm_write_perf_ol(void)
// callers: [msm_pcie_cesta_map_apply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_write_perf_ol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_read_curr_perf_ol @ 00135390 size=1
// signature: undefined crm_read_curr_perf_ol(void)
// callers: [msm_pcie_cesta_curr_perf_ol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_read_curr_perf_ol(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 00135398 size=1
// signature: undefined __memset_io(void)
// callers: [msm_pcie_config_tc_bdf_sid_map, msm_pcie_config_sid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crc8 @ 001353a0 size=1
// signature: undefined crc8(void)
// callers: [msm_pcie_config_sid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crc8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001353a8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [msm_of_pci_parse_bus_range, msm_msi_init, pcie_i2c_ctrl_probe, msm_pcie_probe, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_early_ssr_notifier @ 001353b8 size=1
// signature: undefined qcom_register_early_ssr_notifier(void)
// callers: [msm_pcie_drv_connect_notify_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_early_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001353c0 size=1
// signature: undefined _dev_err(void)
// callers: [msm_msi_init, msm_msi_alloc_domains, msm_msi_snps_irq_setup, msm_msi_domain_prepare, msm_msi_irq_domain_alloc, msm_msi_qgic_irq_setup, pcie_i2c_ctrl_probe, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 001353c8 size=1
// signature: undefined of_match_device(void)
// callers: [pcie_i2c_ctrl_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001353d0 size=1
// signature: undefined _dev_info(void)
// callers: [msm_msi_init, pcie_i2c_ctrl_probe, msm_pcie_probe, msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001353d8 size=1
// signature: undefined single_open(void)
// callers: [msm_pcie_debugfs_wr_mask_open, msm_pcie_debugfs_base_select_open, msm_pcie_debugfs_wr_offset_open, msm_pcie_debugfs_rc_select_open, msm_pcie_debugfs_case_open, msm_pcie_debugfs_wr_value_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001353e0 size=1
// signature: undefined __kmalloc(void)
// callers: [msm_msi_init, msm_pcie_debugfs_parse_input, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001353e8 size=1
// signature: undefined __check_object_size(void)
// callers: [msm_pcie_debugfs_parse_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001353f8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [msm_pcie_debugfs_parse_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_option @ 00135400 size=1
// signature: undefined get_option(void)
// callers: [msm_pcie_debugfs_parse_input]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_option(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00135410 size=1
// signature: undefined seq_printf(void)
// callers: [msm_pcie_debugfs_wr_offset_show, msm_pcie_debugfs_case_show, msm_pcie_debugfs_wr_mask_show, msm_pcie_debugfs_rc_select_show, msm_pcie_debugfs_wr_value_show, msm_pcie_debugfs_base_select_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00135418 size=1
// signature: undefined seq_puts(void)
// callers: [msm_pcie_debugfs_base_select_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pci_alloc_host_bridge @ 00135420 size=1
// signature: undefined devm_pci_alloc_host_bridge(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pci_alloc_host_bridge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00135428 size=1
// signature: undefined scnprintf(void)
// callers: [l23_rdy_poll_timeout_show, boot_option_show, sbr_link_recovery_show, link_check_max_count_show, msm_pcie_probe, panic_on_aer_show, msm_pcie_pm_resume_noirq, msm_pcie_pm_suspend_noirq, aspm_stat_show, link_speed_override_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00135430 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00135438 size=1
// signature: undefined of_find_property(void)
// callers: [msm_msi_init, ntn3_de_emphasis_wa, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00135440 size=1
// signature: undefined of_property_read_string(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00135448 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00135450 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00135458 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [msm_msi_init, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_i2c_device_by_node @ 00135460 size=1
// signature: undefined of_find_i2c_device_by_node(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_i2c_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00135468 size=1
// signature: undefined of_get_property(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00135470 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [msm_msi_init, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00135478 size=1
// signature: undefined devm_ioremap(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_icc_get @ 00135480 size=1
// signature: undefined of_icc_get(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq_byname @ 00135488 size=1
// signature: undefined platform_get_irq_byname(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_bulk_get_all @ 00135490 size=1
// signature: undefined devm_clk_bulk_get_all(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_bulk_get_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 00135498 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_get @ 001354a0 size=1
// signature: undefined clk_get(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get_optional @ 001354a8 size=1
// signature: undefined devm_regulator_get_optional(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get_optional(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 001354b0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_reset_control_get @ 001354b8 size=1
// signature: undefined __devm_reset_control_get(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_reset_control_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 001354c0 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 001354c8 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 001354d0 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// crm_get_device @ 001354d8 size=1
// signature: undefined crm_get_device(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void crm_get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 001354e0 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 001354e8 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001354f0 size=1
// signature: undefined wakeup_source_register(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001354f8 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00135500 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [msm_msi_snps_irq_setup, msm_msi_qgic_irq_setup, msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 00135508 size=1
// signature: undefined sysfs_create_group(void)
// callers: [msm_pcie_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 00135510 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00135518 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [msm_pcie_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_trysend @ 00135520 size=1
// signature: undefined rpmsg_trysend(void)
// callers: [msm_pcie_drv_send_rpmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_trysend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00135528 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [msm_pcie_drv_send_rpmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 00135530 size=1
// signature: undefined i2c_transfer(void)
// callers: [ntn3_i2c_write, ntn3_i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00135538 size=1
// signature: undefined __flush_workqueue(void)
// callers: [msm_pcie_drv_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 00135540 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [msm_pcie_drv_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00135548 size=1
// signature: undefined complete(void)
// callers: [handle_global_irq, msm_pcie_drv_rpmsg_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_stay_awake @ 00135550 size=1
// signature: undefined __pm_stay_awake(void)
// callers: [handle_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 00135558 size=1
// signature: undefined __pm_relax(void)
// callers: [handle_wake_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pcie_capability_clear_and_set_word @ 00135560 size=1
// signature: undefined pcie_capability_clear_and_set_word(void)
// callers: [msm_aer_process_err_devices]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pcie_capability_clear_and_set_word(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_dev_get @ 00135568 size=1
// signature: undefined pci_dev_get(void)
// callers: [msm_find_device_iter]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_dev_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_device_is_present @ 00135570 size=1
// signature: undefined pci_device_is_present(void)
// callers: [msm_pcie_confirm_linkup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_device_is_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00135578 size=1
// signature: undefined kstrtouint(void)
// callers: [panic_on_aer_store, boot_option_store, sbr_link_recovery_store, link_check_max_count_store, link_speed_override_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00135580 size=1
// signature: undefined kstrtoull(void)
// callers: [l23_rdy_poll_timeout_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit_at @ 00135588 size=1
// signature: undefined sysfs_emit_at(void)
// callers: [aer_dev_nonfatal_show, aer_dev_fatal_show, aer_dev_correctable_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit_at(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00135590 size=1
// signature: undefined sysfs_emit(void)
// callers: [aer_rootport_total_err_cor_show, aer_rootport_total_err_fatal_show, aer_rootport_total_err_nonfatal_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 001355c0 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [msm_msi_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_get_address @ 001355c8 size=1
// signature: undefined __of_get_address(void)
// callers: [msm_msi_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_get_address(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_parse_one @ 001355d0 size=1
// signature: undefined of_irq_parse_one(void)
// callers: [msm_msi_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_parse_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_remove @ 001355d8 size=1
// signature: undefined irq_domain_remove(void)
// callers: [msm_msi_init, msm_msi_alloc_domains]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_of_parse_and_map @ 001355e0 size=1
// signature: undefined irq_of_parse_and_map(void)
// callers: [msm_msi_snps_irq_setup, msm_msi_qgic_irq_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_of_parse_and_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_chained_handler_and_data @ 001355e8 size=1
// signature: undefined irq_set_chained_handler_and_data(void)
// callers: [msm_msi_snps_irq_setup, msm_msi_qgic_irq_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_chained_handler_and_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_dispose_mapping @ 001355f0 size=1
// signature: undefined irq_dispose_mapping(void)
// callers: [msm_msi_snps_irq_setup, msm_msi_qgic_irq_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_dispose_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 001355f8 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [msm_msi_qgic_mask_irq, msm_msi_irq_set_affinity, msm_msi_irq_compose_msi_msg, msm_msi_qgic_unmask_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_domain_add @ 00135600 size=1
// signature: undefined __irq_domain_add(void)
// callers: [msm_msi_alloc_domains]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_domain_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_msi_create_irq_domain @ 00135608 size=1
// signature: undefined pci_msi_create_irq_domain(void)
// callers: [msm_msi_alloc_domains]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_msi_create_irq_domain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// generic_handle_irq @ 00135610 size=1
// signature: undefined generic_handle_irq(void)
// callers: [msm_msi_qgic_handler, msm_msi_snps_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void generic_handle_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_resolve_mapping @ 00135618 size=1
// signature: undefined __irq_resolve_mapping(void)
// callers: [msm_msi_qgic_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_resolve_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_find_next_zero_area_off @ 00135620 size=1
// signature: undefined bitmap_find_next_zero_area_off(void)
// callers: [msm_msi_irq_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_find_next_zero_area_off(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_set @ 00135628 size=1
// signature: undefined __bitmap_set(void)
// callers: [msm_msi_irq_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_set_info @ 00135638 size=1
// signature: undefined irq_domain_set_info(void)
// callers: [msm_msi_irq_domain_alloc]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_set_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_get_irq_data @ 00135640 size=1
// signature: undefined irq_domain_get_irq_data(void)
// callers: [msm_msi_irq_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_clear @ 00135648 size=1
// signature: undefined __bitmap_clear(void)
// callers: [msm_msi_irq_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_clear(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_resource @ 00135650 size=1
// signature: undefined dma_unmap_resource(void)
// callers: [msm_msi_irq_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_domain_free_irqs_parent @ 00135658 size=1
// signature: undefined irq_domain_free_irqs_parent(void)
// callers: [msm_msi_irq_domain_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_domain_free_irqs_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_resource @ 00135660 size=1
// signature: undefined dma_map_resource(void)
// callers: [msm_msi_domain_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_msi_unmask_irq @ 00135668 size=1
// signature: undefined pci_msi_unmask_irq(void)
// callers: [msm_msi_unmask_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_msi_unmask_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pci_msi_mask_irq @ 00135670 size=1
// signature: undefined pci_msi_mask_irq(void)
// callers: [msm_msi_mask_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pci_msi_mask_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



