// Decompiled by Ghidra 12.2
// Program: qcom_stats.ko
// Image base: 00100000

//------------------------------------------------------------
// has_system_slept @ 001008ec size=268
// signature: undefined has_system_slept(void)
// callers: []
//------------------------------------------------------------

undefined8 has_system_slept(void)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  int iVar7;
  undefined4 local_50;
  undefined1 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  local_50 = 0;
  if (*(long *)(*(long *)(drv + 8) + 0x18) == 0) {
    uVar3 = 1;
  }
  else {
    uVar5 = 0;
    iVar7 = 1;
    uVar3 = 1;
    lVar1 = drv;
    lVar2 = b_system_stats;
    lVar4 = a_system_stats;
    do {
      lVar6 = uVar5 * 0x20;
      if (*(int *)(lVar2 + lVar6 + 4) == *(int *)(lVar4 + lVar6 + 4)) {
        local_50 = *(undefined4 *)(lVar2 + lVar6);
        strim(&local_50);
        _printk(&DAT_001042c8,&local_50);
        uVar3 = 0;
        lVar1 = drv;
        lVar2 = b_system_stats;
        lVar4 = a_system_stats;
      }
      uVar5 = (ulong)iVar7;
      iVar7 = iVar7 + 1;
    } while (uVar5 < *(ulong *)(*(long *)(lVar1 + 8) + 0x18));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// has_subsystem_slept @ 001009fc size=176
// signature: undefined has_subsystem_slept(void)
// callers: []
//------------------------------------------------------------

undefined8 has_subsystem_slept(void)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  char *pcVar4;
  
  lVar3 = 0;
  uVar2 = 1;
  pcVar4 = &DAT_00104478;
  do {
    if (((*pcVar4 == '\0') &&
        (lVar1 = a_subsystem_stats + lVar3,
        *(int *)(b_subsystem_stats + lVar3 + 4) == *(int *)(lVar1 + 4))) &&
       (*(ulong *)(lVar1 + 8) < *(ulong *)(lVar1 + 0x10))) {
      _printk(&DAT_001041cc,*(undefined8 *)(pcVar4 + -0x10));
      uVar2 = 0;
    }
    pcVar4 = pcVar4 + 0x18;
    lVar3 = lVar3 + 0x20;
  } while (lVar3 != 0x1a0);
  return uVar2;
}



//------------------------------------------------------------
// current_subsystem_sleep @ 00100ab0 size=280
// signature: undefined current_subsystem_sleep(void)
// callers: []
//------------------------------------------------------------

bool current_subsystem_sleep(void)

{
  undefined8 *puVar1;
  long lVar2;
  ulong uVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  int *piVar8;
  
  bVar4 = false;
  lVar5 = 0x18;
  lVar6 = 8;
  piVar8 = &DAT_00104470;
  uVar7 = 0;
  do {
    lVar2 = c_subsystem_stats;
    if (piVar8[1] == -2) {
      __memcpy_fromio(c_subsystem_stats + lVar5 + -0x18,
                      *(undefined8 *)(*(long *)(drv + 0x10) + lVar6),0x20);
LAB_00100b78:
      if ((*piVar8 != 0x277) &&
         (*(ulong *)(c_subsystem_stats + lVar5 + -0x10) < *(ulong *)(c_subsystem_stats + lVar5 + -8)
         )) {
        _printk(&DAT_001041a9,*(undefined8 *)(piVar8 + -2));
        return bVar4;
      }
    }
    else {
      uVar3 = qcom_smem_get(piVar8[1],*piVar8,0);
      if (uVar3 < 0xfffffffffffff001) {
        puVar1 = (undefined8 *)(lVar2 + lVar5);
        *(undefined4 *)((long)puVar1 + -0x14) = *(undefined4 *)(uVar3 + 4);
        puVar1[-2] = *(undefined8 *)(uVar3 + 8);
        puVar1[-1] = *(undefined8 *)(uVar3 + 0x10);
        *puVar1 = *(undefined8 *)(uVar3 + 0x18);
        goto LAB_00100b78;
      }
    }
    bVar4 = 0xb < uVar7;
    piVar8 = piVar8 + 6;
    lVar5 = lVar5 + 0x20;
    lVar6 = lVar6 + 0x10;
    uVar7 = uVar7 + 1;
    if (lVar5 == 0x1b8) {
      return bVar4;
    }
  } while( true );
}



//------------------------------------------------------------
// subsystem_sleep_debug_enable @ 00100bcc size=12
// signature: undefined subsystem_sleep_debug_enable(void)
// callers: []
//------------------------------------------------------------

void subsystem_sleep_debug_enable(undefined1 param_1)

{
  subsystem_stats_debug_on = param_1;
  return;
}



//------------------------------------------------------------
// get_aosd_sleep_exit_time @ 00100bdc size=288
// signature: undefined get_aosd_sleep_exit_time(void)
// callers: []
//------------------------------------------------------------

void get_aosd_sleep_exit_time(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  int local_40;
  undefined1 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_40 = 0;
  if (*(long *)(*(long *)(drv + 8) + 0x18) != 0) {
    uVar3 = 0;
    do {
      local_40 = readl_relaxed(*(undefined8 *)(*(long *)(drv + 0x10) + uVar3 * 0x10 + 8));
      strim(&local_40);
      if (local_40 == 0x64736f61) {
        iVar2 = readl_relaxed(*(long *)(*(long *)(drv + 0x10) + uVar3 * 0x10 + 8) + 4);
        if (get_aosd_sleep_exit_time_saved_deep_sleep_count == iVar2) {
          deep_sleep_last_exited_time = 0;
        }
        else {
          get_aosd_sleep_exit_time_saved_deep_sleep_count = iVar2;
          deep_sleep_last_exited_time =
               readq_relaxed(*(long *)(*(long *)(drv + 0x10) + uVar3 * 0x10 + 8) + 0x10);
        }
        break;
      }
      uVar3 = (ulong)((int)uVar3 + 1);
    } while (uVar3 < *(ulong *)(*(long *)(drv + 8) + 0x18));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(deep_sleep_last_exited_time);
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100cfc size=124
// signature: undefined readl_relaxed(void)
// callers: [get_aosd_sleep_exit_time, qcom_stats_probe, cx_stats_get_ss_vote_info, ddr_stats_get_freq_count, qcom_stats_fill_ddr_stats, ddr_stats_get_ss_vote_info]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100d44,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readq_relaxed @ 00100d78 size=124
// signature: undefined readq_relaxed(void)
// callers: [get_aosd_sleep_exit_time, qcom_stats_fill_ddr_stats]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x100dc0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_stats_ddr_freqsync_msg @ 00100df8 size=176
// signature: undefined qcom_stats_ddr_freqsync_msg(void)
// callers: [qcom_stats_device_ioctl]
//------------------------------------------------------------

int qcom_stats_ddr_freqsync_msg(void)

{
  int iVar1;
  undefined8 uVar2;
  
  if (((drv == 0) || (*(long *)(drv + 0xf0) == 0)) || (*(char *)(*(long *)(drv + 8) + 0x23) == '\0')
     ) {
    iVar1 = -0x13;
  }
  else {
    mutex_lock(drv + 0xc0);
    iVar1 = qmp_send(*(undefined8 *)(drv + 0xf0),"{class: ddr, action: freqsync}",0x40);
    if (iVar1 == 0) {
      mutex_unlock(drv + 0xc0);
      uVar2 = ktime_get_with_offset(1);
      *(undefined8 *)(drv + 0xf8) = uVar2;
    }
    else {
      _printk(&DAT_0010428c,iVar1);
      mutex_unlock(drv + 0xc0);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// ddr_stats_get_freq_count @ 00100eac size=180
// signature: undefined ddr_stats_get_freq_count(void)
// callers: []
//------------------------------------------------------------

int ddr_stats_get_freq_count(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  
  if (((drv == (long *)0x0) || (drv[0x1e] == 0)) || (*(char *)(drv[1] + 0x23) == '\0')) {
    iVar3 = -0x13;
  }
  else {
    lVar4 = *drv + *(long *)(drv[1] + 8);
    uVar1 = readl_relaxed(lVar4 + 4);
    if (uVar1 < 0x15) {
      iVar3 = 0;
      if (uVar1 != 0) {
        lVar4 = lVar4 + 8;
        do {
          uVar2 = readl_relaxed(lVar4);
          lVar4 = lVar4 + 0x10;
          if ((uVar2 & 0xff00) == 0x100) {
            iVar3 = iVar3 + 1;
          }
          uVar1 = uVar1 - 1;
        } while (uVar1 != 0);
      }
    }
    else {
      _printk(&DAT_0010432e);
      iVar3 = 0;
    }
  }
  return iVar3;
}



//------------------------------------------------------------
// ddr_stats_get_residency @ 00100f64 size=436
// signature: undefined ddr_stats_get_residency(void)
// callers: []
//------------------------------------------------------------

ulong ddr_stats_get_residency(int param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  uint auStack_2e0 [5];
  uint local_2cc;
  uint local_2c8 [6];
  undefined8 auStack_2b0 [77];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  memset(local_2c8,0,0x280);
  uVar7 = 0xffffffea;
  local_2cc = 0;
  if ((-1 < param_1) && (param_2 != 0)) {
    if ((drv == (long *)0x0) || ((drv[0x1e] == 0 || (*(char *)(drv[1] + 0x23) == '\0')))) {
      uVar7 = 0xffffffed;
    }
    else {
      while (lVar3 = ktime_get_with_offset(1), lVar3 < drv[0x1f]) {
        __const_udelay(0x20c4ac);
      }
      mutex_lock(drv + 0x18);
      qcom_stats_fill_ddr_stats(*drv + *(long *)(drv[1] + 8),local_2c8,&local_2cc);
      if (local_2cc == 0) {
        uVar7 = 0;
      }
      else {
        uVar4 = 0;
        uVar7 = 0;
        uVar5 = 0x18;
        do {
          if (uVar4 == 0x14) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101114);
            (*pcVar2)();
          }
          if ((uVar4 & 0x7ffffffffffffff) == 0x14) {
LAB_0010110c:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x101110);
            (*pcVar2)();
          }
          if ((*(uint *)((long)auStack_2e0 + uVar5) & 0xff00) == 0x100) {
            if (0x280 < uVar5 - 0x14) goto LAB_0010110c;
            if (*(int *)((long)auStack_2e0 + uVar5 + 4) != 0) {
              *(uint *)(param_2 + (-(uVar7 >> 0x1f) & 0xfffffff000000000 | uVar7 << 4)) =
                   *(uint *)((long)auStack_2e0 + uVar5) >> 0x10;
              if (0x280 < uVar5) goto LAB_0010110c;
              iVar6 = (int)uVar7;
              uVar1 = iVar6 + 1;
              uVar7 = (ulong)uVar1;
              *(undefined8 *)(param_2 + (long)iVar6 * 0x10 + 8) =
                   *(undefined8 *)((long)local_2c8 + uVar5);
              if (param_1 < (int)uVar1) break;
            }
          }
          uVar4 = uVar4 + 1;
          uVar5 = uVar5 + 0x20;
        } while (local_2cc != uVar4);
      }
      mutex_unlock(drv + 0x18);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// qcom_stats_fill_ddr_stats @ 00101118 size=264
// signature: undefined qcom_stats_fill_ddr_stats(void)
// callers: [ddr_stats_get_residency, ddr_stats_show, qcom_stats_device_ioctl]
//------------------------------------------------------------

long qcom_stats_fill_ddr_stats(long param_1,long param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  undefined *puVar7;
  
  uVar2 = readl_relaxed(param_1 + 4);
  *param_3 = uVar2;
  if (uVar2 < 0x15) {
    if (uVar2 == 0) {
      return 0;
    }
    uVar2 = 0;
    lVar6 = 0;
    puVar7 = &DAT_001043e7;
    while( true ) {
      iVar4 = readl_relaxed(param_1 + 0xc);
      puVar1 = (undefined4 *)(param_2 + (long)(int)uVar2 * 0x20);
      puVar1[1] = iVar4;
      if (((3 < (int)uVar2) && (iVar4 == 0)) && (*(char *)(*(long *)(drv + 8) + 0x24) != '\0'))
      break;
      uVar3 = readl_relaxed(param_1 + 8);
      *puVar1 = uVar3;
      *(undefined8 *)(puVar1 + 2) = 0xdeaddead;
      *(undefined8 *)(puVar1 + 4) = 0xdeaddead;
      lVar5 = readq_relaxed(param_1 + 0x10);
      *(long *)(puVar1 + 6) = lVar5;
      uVar2 = uVar2 + 1;
      lVar6 = lVar5 + lVar6;
      param_1 = param_1 + 0x10;
      if (*param_3 <= uVar2) {
        return lVar6;
      }
    }
  }
  else {
    puVar7 = &DAT_0010432e;
  }
  _printk(puVar7);
  return 0;
}



//------------------------------------------------------------
// ddr_stats_get_ss_count @ 00101224 size=36
// signature: undefined ddr_stats_get_ss_count(void)
// callers: []
//------------------------------------------------------------

undefined4 ddr_stats_get_ss_count(void)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffa1;
  if (*(char *)(*(long *)(drv + 8) + 0x23) != '\0') {
    uVar1 = 0x1c;
  }
  return uVar1;
}



//------------------------------------------------------------
// ddr_stats_get_ss_vote_info @ 0010124c size=380
// signature: undefined ddr_stats_get_ss_vote_info(void)
// callers: []
//------------------------------------------------------------

int ddr_stats_get_ss_vote_info(int param_1,long param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  long lVar5;
  long lVar6;
  
  if (param_1 != 0x1c) {
    return -0x13;
  }
  if (param_2 == 0) {
    return -0x13;
  }
  if (drv == (long *)0x0) {
    return -0x13;
  }
  if (drv[0x1e] == 0) {
    return -0x5f;
  }
  mutex_lock(drv + 0x18);
  iVar2 = qmp_send(drv[0x1e],"{class: ddr, res: drvs_ddr_votes}",0x40);
  if (iVar2 == 0) {
    uVar3 = readl_relaxed(*drv + *(long *)(drv[1] + 8) + 4);
    if (uVar3 < 0x15) {
      lVar5 = *drv + *(long *)(drv[1] + 8) + (ulong)(uVar3 << 4 | 8);
      if (lVar5 != 0) {
        lVar6 = 0;
        do {
          uVar3 = readl_relaxed(lVar5);
          if (uVar3 == 0xffffdead) {
            uVar4 = 0xffffdead;
            *(undefined4 *)(param_2 + lVar6) = 0xffffdead;
          }
          else if (uVar3 == 0xdeaddead) {
            *(undefined4 *)(param_2 + lVar6) = 0xdeaddead;
            uVar4 = 0xdeaddead;
          }
          else {
            uVar4 = uVar3 & 0x3fff;
            *(uint *)(param_2 + lVar6) = uVar3 >> 0xe & 0x3fff;
          }
          lVar1 = param_2 + lVar6;
          lVar5 = lVar5 + 4;
          lVar6 = lVar6 + 8;
          *(uint *)(lVar1 + 4) = uVar4;
        } while (lVar6 != 0xe0);
        iVar2 = 0;
        goto LAB_00101360;
      }
    }
    else {
      _printk(&DAT_0010432e);
    }
    _printk(&DAT_00104254);
    iVar2 = -0x16;
  }
  else {
    _printk(&DAT_0010428c,iVar2);
  }
LAB_00101360:
  mutex_unlock(drv + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// cx_stats_get_ss_vote_info @ 001013cc size=576
// signature: undefined cx_stats_get_ss_vote_info(void)
// callers: []
//------------------------------------------------------------

int cx_stats_get_ss_vote_info(int param_1,undefined1 *param_2)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  
  if (param_1 != 0x1c) {
    return -0x13;
  }
  if (param_2 == (undefined1 *)0x0) {
    return -0x13;
  }
  if (drv == (long *)0x0) {
    return -0x13;
  }
  if ((drv[0x1e] == 0) || (*(long *)(drv[1] + 0x10) == 0)) {
    return -0x5f;
  }
  mutex_lock(drv + 0x18);
  iVar2 = qmp_send(drv[0x1e],"{class: misc_debug, res: cx_vote}",0x40);
  if (iVar2 == 0) {
    uVar3 = readl_relaxed(*drv + *(long *)(drv[1] + 8) + 4);
    if (uVar3 < 0x15) {
      lVar1 = *drv + *(long *)(drv[1] + 8) + (ulong)(uVar3 << 4 | 8);
      if (lVar1 != 0) {
        uVar5 = readl_relaxed(lVar1);
        uVar5 = uVar5 & 0xffffffff;
        uVar6 = readl_relaxed(lVar1 + 4);
        uVar6 = uVar6 & 0xffffffff;
        uVar7 = readl_relaxed(lVar1 + 8);
        uVar7 = uVar7 & 0xffffffff;
        uVar8 = readl_relaxed(lVar1 + 0xc);
        uVar8 = uVar8 & 0xffffffff;
        uVar9 = readl_relaxed(lVar1 + 0x10);
        uVar9 = uVar9 & 0xffffffff;
        uVar10 = readl_relaxed(lVar1 + 0x14);
        uVar10 = uVar10 & 0xffffffff;
        uVar4 = readl_relaxed(lVar1 + 0x18);
        iVar2 = 0;
        *param_2 = (char)uVar5;
        param_2[1] = (char)(uVar5 >> 8);
        param_2[2] = (char)(uVar5 >> 0x10);
        param_2[3] = (char)(uVar5 >> 0x18);
        param_2[5] = (char)(uVar6 >> 8);
        param_2[6] = (char)(uVar6 >> 0x10);
        param_2[7] = (char)(uVar6 >> 0x18);
        param_2[9] = (char)(uVar7 >> 8);
        param_2[10] = (char)(uVar7 >> 0x10);
        param_2[0xb] = (char)(uVar7 >> 0x18);
        param_2[0xd] = (char)(uVar8 >> 8);
        param_2[0xe] = (char)(uVar8 >> 0x10);
        param_2[0xf] = (char)(uVar8 >> 0x18);
        param_2[0x11] = (char)(uVar9 >> 8);
        param_2[0x12] = (char)(uVar9 >> 0x10);
        param_2[0x13] = (char)(uVar9 >> 0x18);
        param_2[0x15] = (char)(uVar10 >> 8);
        param_2[0x16] = (char)(uVar10 >> 0x10);
        param_2[0x17] = (char)(uVar10 >> 0x18);
        param_2[4] = (char)uVar6;
        param_2[8] = (char)uVar7;
        param_2[0xc] = (char)uVar8;
        param_2[0x10] = (char)uVar9;
        param_2[0x14] = (char)uVar10;
        param_2[0x18] = (char)uVar4;
        param_2[0x19] = (char)((uint)uVar4 >> 8);
        param_2[0x1a] = (char)((uint)uVar4 >> 0x10);
        param_2[0x1b] = (char)((uint)uVar4 >> 0x18);
        goto LAB_0010159c;
      }
    }
    else {
      _printk(&DAT_0010432e);
    }
    _printk(&DAT_00104254);
    iVar2 = -0x16;
  }
  else {
    _printk(&DAT_0010428c,iVar2);
  }
LAB_0010159c:
  mutex_unlock(drv + 0x18);
  return iVar2;
}



//------------------------------------------------------------
// mmi_lpm_dbg_register_notifier @ 00101610 size=40
// signature: undefined mmi_lpm_dbg_register_notifier(void)
// callers: []
//------------------------------------------------------------

void mmi_lpm_dbg_register_notifier(undefined8 param_1)

{
  raw_notifier_chain_register(&subsystem_sleep_state,param_1);
  return;
}



//------------------------------------------------------------
// qcom_stats_probe @ 0010163c size=1760
// signature: undefined qcom_stats_probe(void)
// callers: []
//------------------------------------------------------------

ulong qcom_stats_probe(long param_1)

{
  long lVar1;
  ulong *puVar2;
  char *pcVar3;
  ulong *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  ulong *puVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  ulong uVar16;
  long lVar17;
  ulong uVar18;
  undefined **ppuVar19;
  ulong *puVar20;
  ulong *puVar21;
  ulong *puVar22;
  undefined8 uVar23;
  ulong uVar24;
  int iVar25;
  undefined *puVar26;
  char *local_70;
  long local_68;
  
  lVar17 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_68 = *(long *)(lVar17 + 0x638);
  puVar12 = (ulong *)device_get_match_data(lVar1);
  if (puVar12 == (ulong *)0x0) {
    uVar13 = 0xffffffed;
    goto LAB_00101cbc;
  }
  uVar13 = devm_platform_get_and_ioremap_resource(param_1,0,0);
  if ((((0xfffffffffffff000 < uVar13) || (puVar12[3] >> 0x3c != 0)) ||
      (uVar14 = devm_kmalloc(lVar1,puVar12[3] << 4,0xdc0), uVar14 == 0)) ||
     (drv = (ulong *)devm_kmalloc(lVar1,0x100,0xdc0), drv == (ulong *)0x0)) {
    uVar13 = 0xfffffff4;
    goto LAB_00101cbc;
  }
  if (puVar12[3] != 0) {
    uVar15 = 0;
    do {
      lVar17 = uVar15 * 0x10;
      uVar15 = (ulong)((int)uVar15 + 1);
      *(char *)(uVar14 + lVar17) = (char)puVar12[4];
    } while (uVar15 < puVar12[3]);
  }
  uVar15 = debugfs_create_dir("qcom_stats",0);
  uVar23 = *(undefined8 *)(param_1 + 0x2f8);
  local_70 = (char *)0x0;
  if ((*(char *)((long)puVar12 + 0x22) != '\0') &&
     (iVar8 = of_property_read_string_helper(uVar23,"ss-name",0,0,0), 0 < iVar8)) {
    iVar25 = 0;
    do {
      of_property_read_string_helper(uVar23,"ss-name",&local_70,1,iVar25);
      pcVar3 = local_70;
      puVar7 = subsystems;
      ppuVar19 = &subsystems;
      iVar9 = strcmp(subsystems,local_70);
      puVar26 = PTR_DAT_00104480;
      if (iVar9 == 0) goto LAB_00101900;
      iVar9 = strcmp(PTR_DAT_00104480,pcVar3);
      puVar7 = PTR_DAT_00104498;
      if (iVar9 == 0) {
        ppuVar19 = &PTR_DAT_00104480;
LAB_00101910:
        debugfs_create_file(puVar26,0x100,uVar15,ppuVar19,&qcom_subsystem_sleep_stats_fops);
      }
      else {
        ppuVar19 = &PTR_DAT_00104498;
        iVar9 = strcmp(PTR_DAT_00104498,pcVar3);
        puVar26 = PTR_DAT_001044b0;
        if (iVar9 == 0) {
LAB_00101900:
          puVar26 = puVar7;
          goto LAB_00101910;
        }
        ppuVar19 = &PTR_DAT_001044b0;
        iVar9 = strcmp(PTR_DAT_001044b0,pcVar3);
        puVar5 = PTR_s_cdsp1_001044c8;
        puVar7 = puVar26;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_cdsp1_001044c8;
        iVar9 = strcmp(PTR_s_cdsp1_001044c8,pcVar3);
        puVar26 = PTR_s_gpdsp0_001044e0;
        puVar7 = puVar5;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_gpdsp0_001044e0;
        iVar9 = strcmp(PTR_s_gpdsp0_001044e0,pcVar3);
        puVar5 = PTR_s_gpdsp1_001044f8;
        puVar7 = puVar26;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_gpdsp1_001044f8;
        iVar9 = strcmp(PTR_s_gpdsp1_001044f8,pcVar3);
        puVar26 = PTR_DAT_00104510;
        puVar7 = puVar5;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_DAT_00104510;
        iVar9 = strcmp(PTR_DAT_00104510,pcVar3);
        puVar5 = PTR_DAT_00104528;
        puVar7 = puVar26;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_DAT_00104528;
        iVar9 = strcmp(PTR_DAT_00104528,pcVar3);
        puVar26 = PTR_s_display_00104540;
        puVar7 = puVar5;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_display_00104540;
        iVar9 = strcmp(PTR_s_display_00104540,pcVar3);
        puVar5 = PTR_s_adsp_island_00104558;
        puVar7 = puVar26;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_adsp_island_00104558;
        iVar9 = strcmp(PTR_s_adsp_island_00104558,pcVar3);
        puVar6 = PTR_s_slpi_island_00104570;
        puVar7 = puVar5;
        if (iVar9 == 0) goto LAB_00101900;
        ppuVar19 = &PTR_s_slpi_island_00104570;
        iVar9 = strcmp(PTR_s_slpi_island_00104570,pcVar3);
        puVar26 = PTR_DAT_00104588;
        puVar7 = puVar6;
        if (iVar9 == 0) goto LAB_00101900;
        iVar9 = strcmp(PTR_DAT_00104588,pcVar3);
        if (iVar9 == 0) {
          ppuVar19 = &PTR_DAT_00104588;
          goto LAB_00101910;
        }
      }
      iVar25 = iVar25 + 1;
    } while (iVar8 != iVar25);
  }
  local_70 = (char *)((ulong)local_70 & 0xffffff0000000000);
  if (*(char *)((long)puVar12 + 0x21) == '\0') {
    uVar18 = *puVar12;
    uVar16 = puVar12[3];
  }
  else {
    uVar10 = readl(uVar13 + 0x14);
    uVar18 = (ulong)(uVar10 & 0xffff);
    uVar16 = puVar12[3];
  }
  if (uVar16 != 0) {
    uVar24 = 0;
    uVar16 = 0;
    do {
      pcVar3 = (char *)(uVar14 + uVar24 * 0x10);
      *(ulong *)(pcVar3 + 8) = uVar13 + uVar18 + (uVar16 & 0xffffffff);
      uVar11 = readl();
      local_70 = (char *)CONCAT44(local_70._4_4_,uVar11);
      strim(&local_70);
      debugfs_create_file(&local_70,0x100,uVar15,pcVar3,&qcom_soc_sleep_stats_fops);
      uVar16 = (uVar16 & 0xffffffff) + 0x20;
      if (*pcVar3 != '\0') {
        uVar16 = (uVar16 & 0xffffffff) + 0x10;
      }
      uVar24 = (ulong)((int)uVar24 + 1);
    } while (uVar24 < puVar12[3]);
  }
  if (puVar12[1] != 0) {
    lVar17 = uVar13 + puVar12[1];
    iVar8 = readl_relaxed(lVar17);
    if (iVar8 == -0x5eea858b) {
      debugfs_create_file("ddr_stats",0x100,uVar15,lVar17,&ddr_stats_fops);
    }
  }
  if (*(char *)((long)puVar12 + 0x25) != '\0') {
    debugfs_create_file("island_stats",0x100,uVar15,0,&island_stats_fops);
  }
  puVar4 = drv;
  puVar22 = drv + 0x18;
  *drv = uVar13;
  puVar4[1] = (ulong)puVar12;
  puVar4[2] = uVar14;
  puVar4[3] = uVar15;
  puVar4[0x1f] = 0;
  __mutex_init(puVar22,"&drv->lock",&qcom_stats_probe___key);
  puVar4 = drv;
  puVar22 = drv + 4;
  uVar14 = alloc_chrdev_region(puVar22,0,1,"stats");
  uVar13 = uVar14 & 0xffffffff;
  if ((int)uVar14 == 0) {
    puVar2 = puVar4 + 7;
    cdev_init(puVar2,&qcom_stats_device_fops);
    uVar10 = cdev_add(puVar2,(int)puVar4[4],1);
    if (uVar10 == 0) {
      uVar13 = __class_create(&__this_module,"stats",&qcom_create_stats_device___key);
      puVar20 = puVar4 + 5;
      *puVar20 = uVar13;
      puVar21 = puVar20;
      if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
LAB_00101b4c:
        cdev_del(puVar2);
        unregister_chrdev_region((int)*puVar22,1);
        uVar13 = (ulong)(uint)*puVar21;
        if ((uint)*puVar21 != 0) goto LAB_00101cb0;
      }
      else {
        uVar13 = device_create(uVar13,0,(int)puVar4[4],0,"stats");
        puVar21 = puVar4 + 6;
        *puVar21 = uVar13;
        if ((uVar13 == 0) || (0xfffffffffffff000 < uVar13)) {
          class_destroy(*puVar20);
          goto LAB_00101b4c;
        }
      }
      if ((*(char *)((long)puVar12 + 0x23) == '\0') || (puVar12[1] == 0)) {
LAB_00101b9c:
        subsystem_stats_debug_on = 1;
        b_subsystem_stats = devm_kmalloc(lVar1,0x1a0,0xdc0);
        if (((b_subsystem_stats != 0) &&
            (a_subsystem_stats = devm_kmalloc(lVar1,0x1a0,0xdc0), a_subsystem_stats != 0)) &&
           (c_subsystem_stats = devm_kmalloc(lVar1,0x1a0,0xdc0), c_subsystem_stats != 0)) {
          if (*(ulong *)(drv[1] + 0x18) >> 0x3b != 0) {
            uVar13 = 0xfffffff4;
            b_system_stats = 0;
            goto LAB_00101c74;
          }
          b_system_stats = devm_kmalloc(lVar1,*(ulong *)(drv[1] + 0x18) << 5,0xdc0);
          if (b_system_stats != 0) {
            if (*(ulong *)(drv[1] + 0x18) >> 0x3b != 0) {
              uVar13 = 0xfffffff4;
              a_system_stats = 0;
              goto LAB_00101c74;
            }
            a_system_stats = devm_kmalloc(lVar1,*(ulong *)(drv[1] + 0x18) << 5,0xdc0);
            if (a_system_stats != 0) {
              uVar13 = 0;
              *(ulong **)(param_1 + 0xa8) = drv;
              goto LAB_00101cbc;
            }
          }
        }
        uVar13 = 0xfffffff4;
      }
      else {
        uVar13 = qmp_get(lVar1);
        drv[0x1e] = uVar13;
        if (uVar13 < 0xfffffffffffff001) goto LAB_00101b9c;
      }
LAB_00101c74:
      device_destroy(drv[5],(int)drv[4]);
      class_destroy(drv[5]);
      cdev_del(drv + 7);
      puVar22 = drv + 4;
    }
    else {
      uVar13 = (ulong)uVar10;
    }
    unregister_chrdev_region((int)*puVar22,1);
  }
LAB_00101cb0:
  debugfs_remove(drv[3]);
LAB_00101cbc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar13 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_stats_remove @ 00101d20 size=88
// signature: undefined qcom_stats_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_stats_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  device_destroy(*(undefined8 *)(lVar1 + 0x28),*(undefined4 *)(lVar1 + 0x20));
  class_destroy(*(undefined8 *)(lVar1 + 0x28));
  cdev_del(lVar1 + 0x38);
  unregister_chrdev_region(*(undefined4 *)(lVar1 + 0x20),1);
  debugfs_remove(*(undefined8 *)(lVar1 + 0x18));
  return 0;
}



//------------------------------------------------------------
// qcom_subsystem_sleep_stats_open @ 00101d7c size=48
// signature: undefined qcom_subsystem_sleep_stats_open(void)
// callers: []
//------------------------------------------------------------

void qcom_subsystem_sleep_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_subsystem_sleep_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_subsystem_sleep_stats_show @ 00101db0 size=220
// signature: undefined qcom_subsystem_sleep_stats_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_subsystem_sleep_stats_show(long param_1)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  
  uVar2 = qcom_smem_get(*(undefined4 *)(*(long *)(param_1 + 0x80) + 0xc),
                        *(undefined4 *)(*(long *)(param_1 + 0x80) + 8),0);
  if (uVar2 < 0xfffffffffffff001) {
    lVar4 = *(long *)(uVar2 + 0x18);
    if (*(ulong *)(uVar2 + 0x10) < *(ulong *)(uVar2 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101e14);
        (*pcVar1)();
      }
      lVar3 = (*_arch_timer_read_counter)();
      lVar4 = (lVar3 + lVar4) - *(long *)(uVar2 + 8);
    }
    seq_printf(param_1,"Count: %u\n",*(undefined4 *)(uVar2 + 4));
    seq_printf(param_1,"Last Entered At: %llu\n",*(undefined8 *)(uVar2 + 8));
    seq_printf(param_1,"Last Exited At: %llu\n",*(undefined8 *)(uVar2 + 0x10));
    seq_printf(param_1,"Accumulated Duration: %llu\n",lVar4);
  }
  return 0;
}



//------------------------------------------------------------
// readl @ 00101e8c size=140
// signature: undefined readl(void)
// callers: [qcom_stats_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x101ee4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qcom_soc_sleep_stats_open @ 00101f1c size=48
// signature: undefined qcom_soc_sleep_stats_open(void)
// callers: []
//------------------------------------------------------------

void qcom_soc_sleep_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,qcom_soc_sleep_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// qcom_soc_sleep_stats_show @ 00101f50 size=316
// signature: undefined qcom_soc_sleep_stats_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_soc_sleep_stats_show(long param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined8 local_68;
  ulong local_60;
  ulong local_58;
  long local_50;
  ulong local_48 [3];
  
  lVar4 = sp_el0;
  local_48[2] = *(long *)(lVar4 + 0x638);
  pcVar5 = *(char **)(param_1 + 0x80);
  lVar3 = *(long *)(pcVar5 + 8);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  __memcpy_fromio(&local_68,lVar3,0x20);
  lVar4 = local_50;
  if (local_58 < local_60) {
    if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101fc8);
      (*pcVar1)();
    }
    lVar2 = (*_arch_timer_read_counter)();
    lVar4 = (lVar2 + lVar4) - local_60;
  }
  seq_printf(param_1,"Count: %u\n",local_68._4_4_);
  seq_printf(param_1,"Last Entered At: %llu\n",local_60);
  seq_printf(param_1,"Last Exited At: %llu\n",local_58);
  seq_printf(param_1,"Accumulated Duration: %llu\n",lVar4);
  if (*pcVar5 != '\0') {
    local_48[0] = 0;
    local_48[1] = 0;
    __memcpy_fromio(local_48,lVar3 + 0x20,0x10);
    seq_printf(param_1,"Client Votes: %#x\n",local_48[0] & 0xffffffff);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ddr_stats_open @ 00102090 size=48
// signature: undefined ddr_stats_open(void)
// callers: []
//------------------------------------------------------------

void ddr_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,ddr_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// ddr_stats_show @ 001020c4 size=672
// signature: undefined ddr_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 ddr_stats_show(long param_1)

{
  ulong uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  ulong uVar7;
  char *pcVar8;
  undefined8 uVar9;
  ulong uVar10;
  ulong uVar11;
  uint uVar12;
  long lVar13;
  uint local_2f4;
  uint local_2f0 [6];
  long local_2d8 [13];
  uint local_270 [6];
  long local_258 [63];
  
  lVar13 = sp_el0;
  local_258[0x3d] = *(long *)(lVar13 + 0x638);
  memset(local_2f0,0,0x280);
  local_2f4 = 0;
  uVar7 = qcom_stats_fill_ddr_stats(*(undefined8 *)(param_1 + 0x80),local_2f0,&local_2f4);
  lVar13 = 0;
  uVar12 = 0;
  uVar1 = local_2d8[0xc] + local_2d8[8] + local_2d8[4] + local_2d8[0];
  do {
    if (uVar1 == 0) {
      uVar11 = 0;
    }
    else {
      uVar11 = 0;
      if (uVar1 != 0) {
        uVar11 = (ulong)(*(long *)((long)local_2d8 + lVar13) * 100) / uVar1;
      }
    }
    uVar4 = *(uint *)((long)local_2f0 + lVar13);
    uVar5 = uVar4 >> 8 & 0xff;
    if (uVar5 == 1) {
      if ((0xffff < uVar4) && (iVar3 = *(int *)((long)local_2f0 + lVar13 + 4), iVar3 != 0)) {
        uVar2 = uVar4 & 0x1f;
        uVar5 = uVar4 >> 0x10;
        uVar9 = *(undefined8 *)((long)local_2d8 + lVar13);
        pcVar8 = "Freq %dMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%ld (~%d%%)\n";
        goto LAB_00102160;
      }
    }
    else if (uVar5 == 0) {
      uVar5 = uVar12 + 1;
      uVar2 = uVar4 & 0xff;
      pcVar8 = "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%ld (~%d%%)\n";
      iVar3 = *(int *)((long)local_2f0 + lVar13 + 4);
      uVar9 = *(undefined8 *)((long)local_2d8 + lVar13);
      uVar12 = uVar5;
LAB_00102160:
      seq_printf(param_1,pcVar8,uVar5,uVar2,iVar3,uVar9,uVar11);
    }
    lVar13 = lVar13 + 0x20;
  } while (lVar13 != 0x80);
  if (uVar7 == 0) {
    seq_puts(param_1,"ddr_stats: Freq update failed.\n");
  }
  else {
    uVar11 = (ulong)local_2f4;
    if (4 < local_2f4) {
      lVar13 = 0;
      do {
        if (lVar13 == 0x220) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x102360);
          (*pcVar6)();
        }
        if (uVar7 == uVar1) {
          uVar10 = 0;
        }
        else {
          if (0x280 < lVar13 + 0x98U) goto LAB_0010230c;
          uVar10 = 0;
          if (uVar7 - uVar1 != 0) {
            uVar10 = (ulong)(*(long *)((long)local_258 + lVar13) * 100) / (uVar7 - uVar1);
          }
        }
        if (0x27f < lVar13 + 0x80U) goto LAB_0010230c;
        uVar4 = *(uint *)((long)local_270 + lVar13);
        uVar5 = uVar4 >> 8 & 0xff;
        if (uVar5 == 1) {
          if (0xffff < uVar4) {
            if (0x280 < lVar13 + 0x84U) {
LAB_0010230c:
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(1,0x102310);
              (*pcVar6)();
            }
            iVar3 = *(int *)((long)local_270 + lVar13 + 4);
            if (iVar3 != 0) {
              if (0x280 < lVar13 + 0x98U) goto LAB_0010230c;
              uVar5 = uVar4 & 0x1f;
              uVar4 = uVar4 >> 0x10;
              pcVar8 = "Freq %dMhz:\tCP IDX:%u\tcount:%u\tDuration (ticks):%ld (~%d%%)\n";
              goto LAB_0010223c;
            }
          }
        }
        else if (uVar5 == 0) {
          if ((0x280 < lVar13 + 0x84U) || (0x280 < lVar13 + 0x98U)) goto LAB_0010230c;
          uVar12 = uVar12 + 1;
          uVar5 = uVar4 & 0xff;
          pcVar8 = "LPM %d:\tName:0x%x\tcount:%u\tDuration (ticks):%ld (~%d%%)\n";
          iVar3 = *(int *)((long)local_270 + lVar13 + 4);
          uVar4 = uVar12;
LAB_0010223c:
          seq_printf(param_1,pcVar8,uVar4,uVar5,iVar3,*(undefined8 *)((long)local_258 + lVar13),
                     uVar10);
        }
        lVar13 = lVar13 + 0x20;
      } while (uVar11 * 0x20 + -0x80 != lVar13);
    }
  }
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_258[0x3d]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// island_stats_open @ 00102368 size=48
// signature: undefined island_stats_open(void)
// callers: []
//------------------------------------------------------------

void island_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,island_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// island_stats_show @ 0010239c size=312
// signature: undefined island_stats_show(void)
// callers: []
//------------------------------------------------------------

undefined8 island_stats_show(undefined8 param_1)

{
  char *__s1;
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  uVar2 = qcom_smem_get(2,0x28d,0);
  if (uVar2 < 0xfffffffffffff001) {
    lVar3 = 0;
    do {
      __s1 = (char *)(uVar2 + lVar3);
      iVar1 = strcmp(__s1,"DEADDEAD");
      if (iVar1 != 0) {
        seq_printf(param_1,"Name: %s\n",__s1);
        seq_printf(param_1,"Count: %u\n",*(undefined4 *)(__s1 + 0x10));
        seq_printf(param_1,"Last Entered At: %llu\n",*(undefined8 *)(__s1 + 0x18));
        seq_printf(param_1,"Last Exited At: %llu\n",*(undefined8 *)(__s1 + 0x20));
        seq_printf(param_1,"Accumulated Duration: %llu\n",*(undefined8 *)(__s1 + 0x28));
        seq_printf(param_1,"Vid: %u\n",*(undefined4 *)(__s1 + 0x30));
        seq_printf(param_1,"task_id: %u\n",*(undefined4 *)(__s1 + 0x34));
      }
      lVar3 = lVar3 + 0x48;
    } while (lVar3 != 0x1b0);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_stats_device_ioctl @ 001024d8 size=920
// signature: undefined qcom_stats_device_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_stats_device_ioctl(long param_1,int param_2,undefined8 param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar5;
  undefined4 *puVar4;
  undefined4 *puVar6;
  undefined8 uVar7;
  undefined **ppuVar8;
  long lVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  uint uStack_4c;
  long local_48;
  
  lVar12 = sp_el0;
  local_48 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0xd8);
  mutex_lock(sleep_stats_mutex);
  if (param_2 == -0x7ff762f3) {
    uVar7 = 0x280;
    uVar11 = 0x280;
    uVar5 = _seq_read;
  }
  else {
    uVar7 = 0x20;
    uVar11 = 0x20;
    uVar5 = ___arch_copy_to_user;
  }
  puVar4 = (undefined4 *)kmalloc_trace(uVar5,0xdc0,uVar7);
  if (puVar4 == (undefined4 *)0x0) {
    mutex_unlock(sleep_stats_mutex);
    lVar12 = -0xc;
    goto LAB_00102824;
  }
  ppuVar8 = &subsystems;
  switch(param_2) {
  case -0x7ff76300:
    ppuVar8 = &PTR_s_display_00104540;
    break;
  case -0x7ff762ff:
    break;
  case -0x7ff762fe:
    ppuVar8 = &PTR_DAT_00104480;
    break;
  case -0x7ff762fd:
    ppuVar8 = &PTR_DAT_00104498;
    break;
  case -0x7ff762fc:
    ppuVar8 = &PTR_DAT_00104510;
    break;
  case -0x7ff762fb:
    ppuVar8 = &PTR_DAT_001044b0;
    break;
  case -0x7ff762fa:
    ppuVar8 = &PTR_s_cdsp1_001044c8;
    break;
  case -0x7ff762f9:
    ppuVar8 = &PTR_s_gpdsp0_001044e0;
    break;
  case -0x7ff762f8:
    ppuVar8 = &PTR_s_gpdsp1_001044f8;
    break;
  case -0x7ff762f7:
    ppuVar8 = &PTR_DAT_00104528;
    break;
  case -0x7ff762f6:
    if (*(long *)(*(long *)(lVar12 + 8) + 0x18) == 0) goto switchD_00102590_caseD_80089d0d;
    lVar9 = 0;
LAB_001026d4:
    lVar12 = *(long *)(*(long *)(lVar12 + 0x10) + lVar9 * 0x10 + 8);
    if (lVar12 == 0) goto switchD_00102590_caseD_80089d0d;
    __memcpy_fromio(puVar4,lVar12,0x20);
    if (*(ulong *)(puVar4 + 4) < *(ulong *)(puVar4 + 2)) {
      InstructionSynchronizationBarrier();
      lVar12 = cntvct_el0;
      goto LAB_00102670;
    }
    goto LAB_00102684;
  case -0x7ff762f5:
    if (1 < *(ulong *)(*(long *)(lVar12 + 8) + 0x18)) {
      lVar9 = 1;
      goto LAB_001026d4;
    }
  case -0x7ff762f3:
switchD_00102590_caseD_80089d0d:
    uStack_4c = 0;
    if (*(char *)(drv[1] + 0x23) == '\0') {
LAB_0010275c:
      qcom_stats_fill_ddr_stats(*drv + *(long *)(drv[1] + 8),puVar4,&uStack_4c);
      if (*(char *)(drv[1] + 0x23) == '\0') {
LAB_001027ec:
        uVar10 = 0x14;
      }
      else if (uStack_4c == 0) {
        uVar10 = 0;
      }
      else {
        uVar10 = 0;
        do {
          lVar12 = (long)(int)uVar10;
          if (uVar11 <= (ulong)(lVar12 * 0x20)) {
LAB_00102868:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x10286c);
            (*pcVar2)();
          }
          if (*(char *)((long)puVar4 + lVar12 * 0x20 + 1) == '\x01') {
            if (uVar11 < (lVar12 << 5 | 4U)) goto LAB_00102868;
            if (puVar4[lVar12 * 8 + 1] == 0) goto LAB_001027e4;
          }
          uVar1 = (int)uVar10 + 1;
          uVar10 = (ulong)uVar1;
        } while (uStack_4c != uVar1);
        uVar10 = (ulong)uStack_4c;
LAB_001027e4:
        if (0x13 < (int)uVar10) goto LAB_001027ec;
      }
      uVar11 = -(uVar10 >> 0x1f) & 0xffffffe000000000 | uVar10 << 5;
      goto LAB_00102804;
    }
    iVar3 = qcom_stats_ddr_freqsync_msg();
    if (iVar3 == 0) {
      while (lVar12 = ktime_get_with_offset(1), lVar12 < drv[0x1f]) {
        __const_udelay(0x20c4ac);
      }
      goto LAB_0010275c;
    }
    goto LAB_0010280c;
  case -0x7ff762f4:
    if (2 < *(ulong *)(*(long *)(lVar12 + 8) + 0x18)) {
      lVar9 = 2;
      goto LAB_001026d4;
    }
    goto switchD_00102590_caseD_80089d0d;
  default:
    _printk(&DAT_001042ad);
    iVar3 = -0x16;
    goto LAB_0010280c;
  }
  puVar6 = (undefined4 *)
           qcom_smem_get(*(undefined4 *)((long)ppuVar8 + 0xc),*(undefined4 *)(ppuVar8 + 1),0);
  if (puVar6 < (undefined4 *)0xfffffffffffff001) {
    *puVar4 = *puVar6;
    puVar4[1] = puVar6[1];
    uVar11 = *(ulong *)(puVar6 + 2);
    *(ulong *)(puVar4 + 2) = uVar11;
    uVar10 = *(ulong *)(puVar6 + 4);
    *(ulong *)(puVar4 + 4) = uVar10;
    *(undefined8 *)(puVar4 + 6) = *(undefined8 *)(puVar6 + 6);
    if (uVar10 < uVar11) {
      InstructionSynchronizationBarrier();
      lVar12 = cntvct_el0;
LAB_00102670:
      *(long *)(puVar4 + 6) = (lVar12 - *(long *)(puVar4 + 2)) + *(long *)(puVar4 + 6);
    }
LAB_00102684:
    uVar11 = 0x20;
LAB_00102804:
    iVar3 = qcom_stats_copy_to_user(param_3,puVar4,uVar11);
  }
  else {
    iVar3 = -5;
  }
LAB_0010280c:
  kfree(puVar4);
  mutex_unlock(sleep_stats_mutex);
  lVar12 = (long)iVar3;
LAB_00102824:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar12);
  }
  return;
}



//------------------------------------------------------------
// qcom_stats_device_open @ 00102874 size=48
// signature: undefined qcom_stats_device_open(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_stats_device_open(long param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  uVar1 = 0xffffffea;
  if ((param_2 != 0) && (*(long *)(param_1 + 0x290) != 0)) {
    uVar1 = 0;
    *(long *)(param_2 + 0xd8) = *(long *)(param_1 + 0x290) + -0x38;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_stats_copy_to_user @ 001028a4 size=308
// signature: undefined qcom_stats_copy_to_user(void)
// callers: [qcom_stats_device_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_stats_copy_to_user(ulong param_1,undefined8 param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  undefined8 *puVar3;
  ulong uVar4;
  
  if (param_3 >> 0x1f != 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1029c0);
    (*pcVar2)();
  }
  __check_object_size(param_2,param_3,1);
  puVar3 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_1, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
    uVar4 = param_1 & (long)(param_1 << 8) >> 8;
  }
  if (uVar4 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar3 = (undefined8 *)puVar3[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar3 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar3;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    param_3 = __arch_copy_to_user(puVar3,param_1 & 0xff7fffffffffffff,param_2,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
  }
  return param_3 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_stats_suspend @ 001029f8 size=316
// signature: undefined qcom_stats_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_stats_suspend(long param_1)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined1 *puVar8;
  
  if (subsystem_stats_debug_on != '\0') {
    lVar6 = *(long *)(param_1 + 0x98);
    mutex_lock(sleep_stats_mutex);
    lVar4 = 0x18;
    puVar8 = &DAT_00104478;
    do {
      puVar2 = (undefined4 *)
               qcom_smem_get(*(undefined4 *)(puVar8 + -4),*(undefined4 *)(puVar8 + -8),0);
      lVar5 = b_subsystem_stats;
      if (puVar2 < (undefined4 *)0xfffffffffffff001) {
        *puVar8 = 0;
        puVar1 = (undefined8 *)(lVar5 + lVar4);
        *(undefined4 *)(puVar1 + -3) = *puVar2;
        *(undefined4 *)((long)puVar1 + -0x14) = puVar2[1];
        puVar1[-2] = *(undefined8 *)(puVar2 + 2);
        puVar1[-1] = *(undefined8 *)(puVar2 + 4);
        *puVar1 = *(undefined8 *)(puVar2 + 6);
      }
      else {
        *puVar8 = 1;
      }
      lVar4 = lVar4 + 0x20;
      puVar8 = puVar8 + 0x18;
    } while (lVar4 != 0x1b8);
    lVar4 = *(long *)(lVar6 + 8);
    uVar3 = *(ulong *)(lVar4 + 0x18);
    if (uVar3 != 0) {
      uVar7 = 0;
      lVar5 = 0;
      do {
        if ((uVar7 & 0xffffffff) < uVar3) {
          lVar5 = *(long *)(*(long *)(lVar6 + 0x10) + (uVar7 & 0xffffffff) * 0x10 + 8);
        }
        if (lVar5 != 0) {
          __memcpy_fromio(b_system_stats + uVar7 * 0x20,lVar5,0x20);
          lVar4 = *(long *)(lVar6 + 8);
        }
        uVar3 = *(ulong *)(lVar4 + 0x18);
        uVar7 = (ulong)((int)uVar7 + 1);
      } while (uVar7 < uVar3);
    }
    mutex_unlock(sleep_stats_mutex);
  }
  return 0;
}



//------------------------------------------------------------
// qcom_stats_resume @ 00102b38 size=760
// signature: undefined qcom_stats_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_stats_resume(long param_1)

{
  undefined8 *puVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined8 uVar6;
  int *piVar7;
  int iVar8;
  ulong uVar9;
  long lVar10;
  ulong uVar11;
  long lVar12;
  long lVar13;
  undefined **ppuVar14;
  long *plVar15;
  int local_74;
  int local_70;
  int local_6c;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  local_6c = -1;
  lVar13 = *(long *)(param_1 + 0x98);
  local_74 = -1;
  local_70 = -1;
  if (subsystem_stats_debug_on != '\0') {
    mutex_lock(sleep_stats_mutex);
    ppuVar14 = &subsystems;
    plVar15 = &get_subsystem_sleep_stats_prev_duration;
    lVar12 = 0x18;
    do {
      if ((*(char *)(ppuVar14 + 2) == '\0') &&
         (puVar4 = (undefined4 *)
                   qcom_smem_get(*(undefined4 *)((long)ppuVar14 + 0xc),*(undefined4 *)(ppuVar14 + 1)
                                 ,0), puVar4 < (undefined4 *)0xfffffffffffff001)) {
        puVar1 = (undefined8 *)(a_subsystem_stats + lVar12);
        *(undefined4 *)(puVar1 + -3) = *puVar4;
        *(undefined4 *)((long)puVar1 + -0x14) = puVar4[1];
        puVar1[-2] = *(undefined8 *)(puVar4 + 2);
        puVar1[-1] = *(undefined8 *)(puVar4 + 4);
        *puVar1 = *(undefined8 *)(puVar4 + 6);
        if (puVar4 == (undefined4 *)0x0) {
          _printk(&DAT_001042eb);
          iVar8 = 0;
        }
        else {
          lVar10 = *(long *)(puVar4 + 6);
          if (*(ulong *)(puVar4 + 4) < *(ulong *)(puVar4 + 2)) {
            if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102c98);
              (*pcVar2)();
            }
            lVar5 = (*_arch_timer_read_counter)();
            lVar10 = (lVar5 + lVar10) - *(long *)(puVar4 + 2);
          }
          lVar5 = *plVar15;
          *plVar15 = lVar10;
          iVar8 = (int)((ulong)(lVar10 - lVar5) / 19200000);
        }
        if (iVar8 < 1) {
          iVar8 = 0;
        }
        _printk(&DAT_001043d6,*ppuVar14,iVar8);
        if ((local_70 < 0) && (iVar3 = strcmp(*ppuVar14,"modem"), iVar3 == 0)) {
          piVar7 = &local_70;
          uVar6 = 2;
          local_70 = iVar8;
        }
        else if ((local_74 < 0) && (iVar3 = strcmp(*ppuVar14,"adsp"), iVar3 == 0)) {
          piVar7 = &local_74;
          uVar6 = 3;
          local_74 = *(int *)(a_subsystem_stats + lVar12 + -0x14);
        }
        else {
          if ((-1 < local_6c) || (iVar3 = strcmp(*ppuVar14,"apss"), iVar3 != 0)) goto LAB_00102be0;
          piVar7 = &local_6c;
          uVar6 = 1;
          local_6c = iVar8;
        }
        raw_notifier_call_chain(&subsystem_sleep_state,uVar6,piVar7);
      }
LAB_00102be0:
      lVar12 = lVar12 + 0x20;
      ppuVar14 = ppuVar14 + 3;
      plVar15 = plVar15 + 1;
    } while (lVar12 != 0x1b8);
    lVar12 = *(long *)(lVar13 + 8);
    uVar9 = *(ulong *)(lVar12 + 0x18);
    if (uVar9 != 0) {
      uVar11 = 0;
      lVar10 = 0;
      do {
        if ((uVar11 & 0xffffffff) < uVar9) {
          lVar10 = *(long *)(*(long *)(lVar13 + 0x10) + (uVar11 & 0xffffffff) * 0x10 + 8);
        }
        if (lVar10 != 0) {
          __memcpy_fromio(a_system_stats + uVar11 * 0x20,lVar10,0x20);
          lVar12 = *(long *)(lVar13 + 8);
        }
        uVar9 = *(ulong *)(lVar12 + 0x18);
        uVar11 = (ulong)((int)uVar11 + 1);
      } while (uVar11 < uVar9);
    }
    mutex_unlock(sleep_stats_mutex);
  }
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00102fa4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_stats,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102fd4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_stats);
  return;
}



//------------------------------------------------------------
// strim @ 00106000 size=1
// signature: undefined strim(void)
// callers: [has_system_slept, get_aosd_sleep_exit_time, qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106008 size=1
// signature: undefined _printk(void)
// callers: [has_system_slept, qcom_stats_device_ioctl, qcom_stats_resume, has_subsystem_slept, cx_stats_get_ss_vote_info, qcom_stats_ddr_freqsync_msg, ddr_stats_get_freq_count, qcom_stats_fill_ddr_stats, ddr_stats_get_ss_vote_info, current_subsystem_sleep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [has_system_slept, ddr_stats_get_residency, ddr_stats_show, qcom_stats_device_ioctl, qcom_stats_resume, get_aosd_sleep_exit_time, qcom_stats_probe, qcom_soc_sleep_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00106018 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [qcom_stats_device_ioctl, qcom_stats_resume, qcom_soc_sleep_stats_show, qcom_stats_suspend, current_subsystem_sleep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 00106020 size=1
// signature: undefined qcom_smem_get(void)
// callers: [qcom_stats_device_ioctl, qcom_stats_resume, qcom_subsystem_sleep_stats_show, island_stats_show, qcom_stats_suspend, current_subsystem_sleep]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00106028 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readq_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00106030 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readq_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00106038 size=1
// signature: undefined mutex_lock(void)
// callers: [ddr_stats_get_residency, qcom_stats_device_ioctl, qcom_stats_resume, cx_stats_get_ss_vote_info, qcom_stats_ddr_freqsync_msg, ddr_stats_get_ss_vote_info, qcom_stats_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_send @ 00106040 size=1
// signature: undefined qmp_send(void)
// callers: [cx_stats_get_ss_vote_info, qcom_stats_ddr_freqsync_msg, ddr_stats_get_ss_vote_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106048 size=1
// signature: undefined mutex_unlock(void)
// callers: [ddr_stats_get_residency, qcom_stats_device_ioctl, qcom_stats_resume, cx_stats_get_ss_vote_info, qcom_stats_ddr_freqsync_msg, ddr_stats_get_ss_vote_info, qcom_stats_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 00106050 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [ddr_stats_get_residency, qcom_stats_device_ioctl, qcom_stats_ddr_freqsync_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00106058 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ddr_stats_get_residency, ddr_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00106060 size=1
// signature: undefined __const_udelay(void)
// callers: [ddr_stats_get_residency, qcom_stats_device_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_chain_register @ 00106068 size=1
// signature: undefined raw_notifier_chain_register(void)
// callers: [mmi_lpm_dbg_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00106070 size=1
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
// platform_driver_unregister @ 00106078 size=1
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
// device_get_match_data @ 00106080 size=1
// signature: undefined device_get_match_data(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_get_and_ioremap_resource @ 00106088 size=1
// signature: undefined devm_platform_get_and_ioremap_resource(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_get_and_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00106090 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00106098 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001060a0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001060a8 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_stats_resume, island_stats_show, qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001060b0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001060b8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 001060c0 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 001060c8 size=1
// signature: undefined cdev_init(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 001060d0 size=1
// signature: undefined cdev_add(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 001060d8 size=1
// signature: undefined __class_create(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 001060e0 size=1
// signature: undefined device_create(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001060e8 size=1
// signature: undefined class_destroy(void)
// callers: [qcom_stats_probe, qcom_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001060f0 size=1
// signature: undefined cdev_del(void)
// callers: [qcom_stats_probe, qcom_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001060f8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [qcom_stats_probe, qcom_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qmp_get @ 00106100 size=1
// signature: undefined qmp_get(void)
// callers: [qcom_stats_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qmp_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00106108 size=1
// signature: undefined device_destroy(void)
// callers: [qcom_stats_probe, qcom_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00106110 size=1
// signature: undefined debugfs_remove(void)
// callers: [qcom_stats_probe, qcom_stats_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 00106118 size=1
// signature: undefined single_open(void)
// callers: [ddr_stats_open, island_stats_open, qcom_subsystem_sleep_stats_open, qcom_soc_sleep_stats_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 00106128 size=1
// signature: undefined seq_printf(void)
// callers: [ddr_stats_show, qcom_subsystem_sleep_stats_show, island_stats_show, qcom_soc_sleep_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 00106130 size=1
// signature: undefined seq_puts(void)
// callers: [ddr_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00106140 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_stats_device_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106148 size=1
// signature: undefined kfree(void)
// callers: [qcom_stats_device_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00106150 size=1
// signature: undefined __check_object_size(void)
// callers: [qcom_stats_copy_to_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00106168 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [qcom_stats_copy_to_user]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_call_chain @ 00106178 size=1
// signature: undefined raw_notifier_call_chain(void)
// callers: [qcom_stats_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



