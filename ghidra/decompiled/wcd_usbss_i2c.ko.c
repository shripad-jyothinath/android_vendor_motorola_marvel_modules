// Decompiled by Ghidra 12.2
// Program: wcd_usbss_i2c.ko
// Image base: 00100000

//------------------------------------------------------------
// wcd_usbss_writeable_register @ 00100b1c size=44
// signature: undefined wcd_usbss_writeable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd_usbss_writeable_register(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  if (0x4eb < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100b48);
    (*pcVar1)();
  }
  return (byte)(&wcd_usbss_reg_access)[param_2] >> 1 & 1;
}



//------------------------------------------------------------
// wcd_usbss_volatile_register @ 00100b4c size=52
// signature: undefined wcd_usbss_volatile_register(void)
// callers: []
//------------------------------------------------------------

bool wcd_usbss_volatile_register(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if (param_2 == 0) {
    return false;
  }
  if (0x4eb < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100b80);
    (*pcVar1)();
  }
  return ((&wcd_usbss_reg_access)[param_2] & 3) == 1;
}



//------------------------------------------------------------
// wcd_usbss_regmap_init @ 00100b84 size=52
// signature: undefined wcd_usbss_regmap_init(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

void wcd_usbss_regmap_init(undefined8 param_1,undefined8 param_2)

{
  __devm_regmap_init(param_1,&regmap_bus_config,param_1,param_2,0,0);
  return;
}



//------------------------------------------------------------
// regmap_bus_write @ 00100bbc size=84
// signature: undefined regmap_bus_write(void)
// callers: []
//------------------------------------------------------------

undefined8 regmap_bus_write(long param_1,long param_2,ulong param_3)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    if (param_3 < 2) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100c08);
      (*pcVar1)();
    }
    if (3 < param_3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100c14);
      (*pcVar1)();
    }
    uVar2 = regmap_bus_gather_write(param_1,param_2,2,param_2 + 2,param_3 - 2);
  }
  return uVar2;
}



//------------------------------------------------------------
// regmap_bus_gather_write @ 00100c1c size=340
// signature: undefined regmap_bus_gather_write(void)
// callers: [regmap_bus_write]
//------------------------------------------------------------

int regmap_bus_gather_write
              (long param_1,undefined2 *param_2,long param_3,long param_4,ulong param_5)

{
  undefined2 uVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  undefined2 local_5c [2];
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
    pcVar3 = "%s: ctxt is NULL\n";
  }
  else {
    if ((param_2 != (undefined2 *)0x0) && (param_4 != 0)) {
      if (param_3 == 2) {
        mutex_lock(lVar4 + 0x180);
        uVar1 = *param_2;
        local_5c[0] = uVar1;
        iVar2 = wcd_usbss_page_write(lVar4,local_5c);
        if (iVar2 == 0) {
          iVar2 = wcd_usbss_i2c_write_device(lVar4,local_5c[0],param_4,param_5 & 0xffffffff);
          if (iVar2 < 0) {
            _dev_err(param_1,"%s: Codec write failed (%d), reg:0x%x, size:%zd\n",
                     "regmap_bus_gather_write",iVar2,uVar1,param_5);
          }
        }
        mutex_unlock(lVar4 + 0x180);
      }
      else {
        _dev_err(param_1,"%s: register size %zd bytes, not supported\n","regmap_bus_gather_write",
                 param_3);
        iVar2 = -0x16;
      }
      goto LAB_00100cc0;
    }
    pcVar3 = "%s: reg or val is NULL\n";
  }
  _dev_err(param_1,pcVar3,"regmap_bus_gather_write");
  iVar2 = -0x16;
LAB_00100cc0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// regmap_bus_read @ 00100d74 size=520
// signature: undefined regmap_bus_read(void)
// callers: []
//------------------------------------------------------------

int regmap_bus_read(long param_1,ushort *param_2,long param_3,long param_4,undefined8 param_5)

{
  ushort uVar1;
  int iVar2;
  char *pcVar3;
  long lVar4;
  long lVar5;
  ushort uVar6;
  uint uVar7;
  ushort local_90 [2];
  undefined1 local_8c [4];
  undefined8 local_88;
  undefined1 *local_80;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 == 0) {
    pcVar3 = "%s: ctxt is NULL\n";
  }
  else {
    if ((param_2 != (ushort *)0x0) && (param_4 != 0)) {
      if (param_3 == 2) {
        mutex_lock(lVar4 + 0x180);
        uVar1 = *param_2;
        local_90[0] = uVar1;
        iVar2 = wcd_usbss_page_write(lVar4,local_90);
        if (iVar2 == 0) {
          local_80 = (undefined1 *)0x0;
          local_78 = 0;
          lVar5 = *(long *)(lVar4 + 0x10);
          local_88 = 0;
          if (lVar5 == 0) {
            iVar2 = -0x13;
LAB_00100f50:
            _dev_err(param_1,"%s: Codec read failed (%d), reg: 0x%x, size:%zd\n","regmap_bus_read",
                     iVar2,uVar1,param_5);
          }
          else {
            if (0 < (int)param_5) {
              uVar7 = 0;
              uVar6 = local_90[0];
              do {
                local_88 = CONCAT26(local_88._6_2_,0x100000000);
                local_8c[0] = (undefined1)uVar6;
                local_88 = CONCAT62(local_88._2_6_,*(undefined2 *)(lVar5 + 2));
                local_78._0_6_ = CONCAT42(0x10001,*(undefined2 *)(lVar5 + 2));
                local_80 = local_8c;
                local_70 = param_4;
                iVar2 = i2c_transfer(*(undefined8 *)(lVar5 + 0x18),&local_88,2);
                if ((iVar2 != 2) &&
                   (iVar2 = i2c_transfer(*(undefined8 *)(lVar5 + 0x18),&local_88,2), iVar2 != 2)) {
                  _printk(&DAT_00106588);
                  if (iVar2 < 0) goto LAB_00100f50;
                  goto LAB_00100ebc;
                }
                param_4 = param_4 + 1;
                uVar7 = uVar7 + 1;
                uVar6 = uVar6 + 1;
              } while ((int)(uVar7 & 0xff) < (int)param_5);
            }
            iVar2 = 0;
          }
        }
LAB_00100ebc:
        mutex_unlock(lVar4 + 0x180);
      }
      else {
        _dev_err(param_1,"%s: register size %zd bytes, not supported\n","regmap_bus_read",param_3);
        iVar2 = -0x16;
      }
      goto LAB_00100ec4;
    }
    pcVar3 = "%s: reg or val is NULL\n";
  }
  _dev_err(param_1,pcVar3,"regmap_bus_read");
  iVar2 = -0x16;
LAB_00100ec4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd_usbss_page_write @ 00100f7c size=272
// signature: undefined wcd_usbss_page_write(void)
// callers: [regmap_bus_gather_write, regmap_bus_read]
//------------------------------------------------------------

int wcd_usbss_page_write(long param_1,ushort *param_2)

{
  ushort uVar1;
  undefined1 uVar2;
  long lVar3;
  ushort uVar4;
  int iVar5;
  undefined1 local_4c [4];
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  uVar1 = *param_2;
  uVar4 = uVar1 >> 8;
  uVar2 = (undefined1)(uVar1 >> 8);
  local_4c[0] = uVar2;
  if (*(char *)(param_1 + 0x179) == '\0') {
    iVar5 = wcd_usbss_i2c_write_device(param_1,0,local_4c,1);
    if (iVar5 < 0) {
      _printk(&DAT_00106a19,uVar4);
    }
    else {
      *(undefined1 *)(param_1 + 0x178) = uVar2;
      *(undefined1 *)(param_1 + 0x179) = 1;
    }
  }
  else if (uVar4 == *(byte *)(param_1 + 0x178)) {
    iVar5 = 0;
  }
  else {
    iVar5 = wcd_usbss_i2c_write_device(param_1,0,local_4c,1);
    if (iVar5 < 0) {
      _dev_err(*(undefined8 *)(param_1 + 8),"page write error, pg_num: 0x%x\n",uVar4);
    }
    else {
      *(undefined1 *)(param_1 + 0x178) = uVar2;
    }
  }
  *param_2 = uVar1 & 0xff;
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// wcd_usbss_i2c_write_device @ 0010108c size=276
// signature: undefined wcd_usbss_i2c_write_device(void)
// callers: [regmap_bus_gather_write, wcd_usbss_page_write]
//------------------------------------------------------------

int wcd_usbss_i2c_write_device(long param_1,undefined1 param_2,undefined1 *param_3,int param_4)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  long lVar6;
  undefined8 local_68;
  undefined1 *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x10);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  local_60 = (undefined1 *)0x0;
  if (lVar6 == 0) {
    iVar4 = -0x13;
  }
  else {
    puVar5 = (undefined1 *)__kmalloc(param_4 + 1,0xdc0);
    if (puVar5 == (undefined1 *)0x0) {
      iVar4 = -0xc;
    }
    else {
      uVar1 = *param_3;
      uVar2 = *(ushort *)(lVar6 + 2);
      *puVar5 = param_2;
      puVar5[1] = uVar1;
      local_68._0_4_ = (uint)uVar2;
      local_68._0_6_ = CONCAT24((short)(param_4 + 1),(uint)local_68);
      local_60 = puVar5;
      iVar3 = i2c_transfer(*(undefined8 *)(lVar6 + 0x18),&local_68,1);
      iVar4 = 0;
      if (iVar3 != 1) {
        iVar4 = i2c_transfer(*(undefined8 *)(lVar6 + 0x18),&local_68,1);
        if (iVar4 == 1) {
          iVar4 = 0;
        }
        else {
          _printk(&DAT_00106d6c);
        }
      }
      kfree(puVar5);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// wcd_usbss_get_sbu_switch_orientation @ 001011a4 size=212
// signature: undefined wcd_usbss_get_sbu_switch_orientation(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_get_sbu_switch_orientation(void)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if ((wcd_usbss_ctxt_ == (long *)0x0) || (*wcd_usbss_ctxt_ == 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = acquire_runtime_env();
    if (iVar2 < 0) {
      _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
               "wcd_usbss_get_sbu_switch_orientation",iVar2);
    }
    else {
      regmap_read(*wcd_usbss_ctxt_,0x404,&local_2c);
      release_runtime_env(wcd_usbss_ctxt_);
      iVar2 = (uint)((local_2c & 3) == 2) << 1;
      if ((local_2c & 3) == 1) {
        iVar2 = 1;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// acquire_runtime_env @ 00101278 size=508
// signature: undefined acquire_runtime_env(void)
// callers: [wcd_usbss_register_update, wcd_usbss_surge_kthread_fn, wcd_usbss_update_default_trim, wcd_usbss_standby_control, wcd_usbss_set_switch_settings_enable, wcd_usbss_dpdm_switch_update, wcd_usbss_audio_config, wcd_usbss_linearizer_rdac_cal_code_select, wcd_usbss_set_linearizer_sw_tap, wcd_usbss_switch_update, wcd_usbss_probe, wcd_usbss_sdam_notifier_handler, wcd_usbss_get_sbu_switch_orientation]
//------------------------------------------------------------

int acquire_runtime_env(long param_1)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  long lVar9;
  
  mutex_lock(param_1 + 0x208);
  uVar2 = *(uint *)(param_1 + 0x270);
  *(uint *)(param_1 + 0x270) = uVar2 + 1;
  if (uVar2 == 0) {
    pm_stay_awake(*(undefined8 *)(param_1 + 8));
    lVar9 = *(long *)(param_1 + 8);
    iVar6 = __pm_runtime_resume(lVar9,4);
    if (iVar6 < 0) {
      iVar7 = 0;
      do {
        piVar1 = (int *)(lVar9 + 0x1f8);
        iVar8 = *(int *)(lVar9 + 0x1f8);
        do {
          if (iVar8 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar4 = *piVar1;
            if (iVar4 != iVar8) goto LAB_001013a0;
            cVar3 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar8 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_001013a0:
          bVar5 = iVar8 != iVar4;
          iVar8 = iVar4;
        } while (bVar5);
        if (-1 < iVar6) break;
        if (iVar6 == -0xd) {
          usleep_range_state(5000,0x157c,2);
          if (iVar7 == 7) {
            _dev_err(*(undefined8 *)(param_1 + 8),"%s: pm runtime in disabled state\n",
                     "acquire_runtime_env");
LAB_00101474:
            pm_relax(*(undefined8 *)(param_1 + 8));
            iVar7 = *(int *)(param_1 + 0x270) + -1;
            goto LAB_001012e0;
          }
        }
        else {
          _dev_err(*(undefined8 *)(param_1 + 8),"%s: pm_runtime_resume_and_get failed: %i\n",
                   "acquire_runtime_env",iVar6);
          if (iVar7 == 7) goto LAB_00101474;
        }
        iVar7 = iVar7 + 1;
        lVar9 = *(long *)(param_1 + 8);
        iVar6 = __pm_runtime_resume(lVar9,4);
      } while (iVar6 < 0);
    }
  }
  else if (0x7ffffffe < uVar2) {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: priv->runtime_env_counter %d underrun\n",
             "acquire_runtime_env");
    iVar7 = 0;
    iVar6 = 0;
LAB_001012e0:
    *(int *)(param_1 + 0x270) = iVar7;
    goto LAB_00101308;
  }
  iVar6 = 0;
LAB_00101308:
  mutex_unlock(param_1 + 0x208);
  mutex_lock(param_1 + 0x238);
  cVar3 = *(char *)(param_1 + 0x280);
  mutex_unlock(param_1 + 0x238);
  if (((-1 < iVar6) && (cVar3 != '\0')) &&
     (iVar7 = wait_for_completion_timeout(param_1 + 0x288,0x7d), iVar7 == 0)) {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: bus don\'t resume from pm, rc = %d\n",
             "acquire_runtime_env",0);
  }
  return iVar6;
}



//------------------------------------------------------------
// release_runtime_env @ 00101488 size=148
// signature: undefined release_runtime_env(void)
// callers: [wcd_usbss_register_update, wcd_usbss_surge_kthread_fn, wcd_usbss_update_default_trim, wcd_usbss_standby_control, wcd_usbss_set_switch_settings_enable, wcd_usbss_dpdm_switch_update, wcd_usbss_audio_config, wcd_usbss_linearizer_rdac_cal_code_select, wcd_usbss_set_linearizer_sw_tap, wcd_usbss_switch_update, wcd_usbss_probe, wcd_usbss_sdam_notifier_handler, wcd_usbss_get_sbu_switch_orientation]
//------------------------------------------------------------

void release_runtime_env(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  mutex_lock(param_1 + 0x208);
  iVar1 = *(int *)(param_1 + 0x270) + -1;
  *(int *)(param_1 + 0x270) = iVar1;
  if (iVar1 == 0) {
    lVar3 = *(long *)(param_1 + 8);
    uVar2 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar3 + 0x220) = uVar2;
    __pm_runtime_suspend(*(undefined8 *)(param_1 + 8),0xd);
    pm_relax(*(undefined8 *)(param_1 + 8));
  }
  else if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: priv->runtime_env_counter %d underrun\n",
             "release_runtime_env");
    *(undefined4 *)(param_1 + 0x270) = 0;
  }
  mutex_unlock(param_1 + 0x208);
  return;
}



//------------------------------------------------------------
// wcd_usbss_set_switch_settings_enable @ 00101520 size=200
// signature: undefined wcd_usbss_set_switch_settings_enable(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_set_switch_settings_enable(uint param_1,uint param_2)

{
  int iVar1;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else {
    iVar1 = -0x16;
    if (((param_2 < 2) && (param_1 < 8)) && (*wcd_usbss_ctxt_ != 0)) {
      iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
      if (iVar1 < 0) {
        _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
                 "wcd_usbss_set_switch_settings_enable",iVar1);
      }
      else {
        regmap_update_bits_base
                  (*wcd_usbss_ctxt_,0x403,1 << (ulong)(param_1 & 0x1f),
                   param_2 << (ulong)(param_1 & 0x1f),0,0,0);
        release_runtime_env(wcd_usbss_ctxt_);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_linearizer_rdac_cal_code_select @ 001015ec size=184
// signature: undefined wcd_usbss_linearizer_rdac_cal_code_select(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_linearizer_rdac_cal_code_select(uint param_1)

{
  int iVar1;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else {
    iVar1 = -0x16;
    if ((param_1 < 2) && (*wcd_usbss_ctxt_ != 0)) {
      iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
      if (iVar1 < 0) {
        _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
                 "wcd_usbss_linearizer_rdac_cal_code_select",iVar1);
      }
      else {
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x413,4,param_1 << 2,0,0,0);
        release_runtime_env(wcd_usbss_ctxt_);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_set_linearizer_sw_tap @ 001016a8 size=460
// signature: undefined wcd_usbss_set_linearizer_sw_tap(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_set_linearizer_sw_tap(uint param_1,uint param_2)

{
  int iVar1;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else {
    iVar1 = -0x16;
    if (((param_2 | param_1) < 0x400) && (*wcd_usbss_ctxt_ != 0)) {
      iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
      if (iVar1 < 0) {
        _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
                 "wcd_usbss_set_linearizer_sw_tap",iVar1);
      }
      else {
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x465,0xff,param_1 & 0xff,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x466,3,param_1 >> 8,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x467,0xff,param_1 & 0xff,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x468,3,param_1 >> 8,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x469,0xff,param_2 & 0xff,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x46a,3,param_2 >> 8,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x46b,0xff,param_2 & 0xff,0,0,0);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x46c,3,param_2 >> 8,0,0,0);
        release_runtime_env(wcd_usbss_ctxt_);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_register_update @ 00101878 size=296
// signature: undefined wcd_usbss_register_update(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_register_update(long param_1,ulong param_2,long param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else if (*wcd_usbss_ctxt_ == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
    if (iVar1 < 0) {
      _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n","wcd_usbss_register_update"
               ,iVar1);
    }
    else {
      if (param_3 != 0) {
        puVar2 = (undefined4 *)(param_1 + 4);
        do {
          if ((param_2 & 1) == 0) {
            iVar1 = regmap_read(*wcd_usbss_ctxt_,puVar2[-1],puVar2);
            if (iVar1 != 0) {
              _dev_err(wcd_usbss_ctxt_[1],"%s: USB-SS register 0x%x read failed\n",
                       "wcd_usbss_register_update",puVar2[-1]);
              break;
            }
          }
          else {
            iVar1 = regmap_write(*wcd_usbss_ctxt_,puVar2[-1],*(undefined1 *)puVar2);
            if (iVar1 != 0) {
              _dev_err(wcd_usbss_ctxt_[1],"%s: USB-SS register 0x%x (value of 0x%x) write failed\n",
                       "wcd_usbss_register_update",puVar2[-1],*puVar2);
              break;
            }
          }
          puVar2 = puVar2 + 2;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      release_runtime_env(wcd_usbss_ctxt_);
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_dpdm_switch_update @ 001019a4 size=300
// signature: undefined wcd_usbss_dpdm_switch_update(void)
// callers: [wcd_usbss_switch_update]
//------------------------------------------------------------

int wcd_usbss_dpdm_switch_update(ulong param_1,ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else if (*wcd_usbss_ctxt_ == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
    if (iVar1 < 0) {
      _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
               "wcd_usbss_dpdm_switch_update",iVar1);
    }
    else {
      uVar2 = 0x18;
      if ((param_1 & 1) == 0) {
        uVar2 = 0;
      }
      iVar1 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,uVar2,0,0,0);
      if (iVar1 != 0) {
        _printk(&DAT_00106b72,"wcd_usbss_dpdm_switch_update",iVar1);
      }
      uVar2 = 0x80;
      if ((param_2 & 1) == 0) {
        uVar2 = 0;
      }
      iVar1 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x415,0x80,uVar2,0,0,0);
      if (iVar1 != 0) {
        _printk(&DAT_00106dc8,"wcd_usbss_dpdm_switch_update",iVar1);
      }
      release_runtime_env(wcd_usbss_ctxt_);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_audio_config @ 00101ad4 size=620
// signature: undefined wcd_usbss_audio_config(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_audio_config(undefined8 param_1,int param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar2 = -0x13;
    goto LAB_00101b1c;
  }
  if (*wcd_usbss_ctxt_ == 0) {
    iVar2 = -0x16;
    goto LAB_00101b1c;
  }
  _printk(&DAT_001067f2,"wcd_usbss_audio_config",(int)wcd_usbss_ctxt_[0x36],param_3);
  if ((*(byte *)(wcd_usbss_ctxt_ + 0x36) & 0xb8) == 0) {
    iVar2 = 0;
    goto LAB_00101b1c;
  }
  iVar2 = acquire_runtime_env();
  if (iVar2 < 0) {
    _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n","wcd_usbss_audio_config",
             iVar2);
    goto LAB_00101b1c;
  }
  regmap_read(*wcd_usbss_ctxt_,0x419,&local_3c);
  if ((local_3c & 7) == param_3) {
LAB_00101ce8:
    iVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      if (param_3 == 1) {
        regmap_write(*wcd_usbss_ctxt_,0x43,0x98);
        regmap_write(*wcd_usbss_ctxt_,1,0xf);
        regmap_write(*wcd_usbss_ctxt_,0x3d,0x82);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,7,1,0,0,0);
        regmap_write(*wcd_usbss_ctxt_,0x3d,2);
        regmap_write(*wcd_usbss_ctxt_,0x43,0x9e);
        uVar3 = 4;
        uVar4 = 0x10;
      }
      else {
        regmap_write(*wcd_usbss_ctxt_,0x3d,0x82);
        uVar5 = 0x1c;
        if (param_3 != 2) {
          uVar5 = 0x10;
        }
        regmap_write(*wcd_usbss_ctxt_,4,uVar5);
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,7,param_3,0,0,0);
        regmap_write(*wcd_usbss_ctxt_,1,0);
        regmap_write(*wcd_usbss_ctxt_,0x3d,0xb2);
        uVar3 = 0x43;
        uVar4 = 0x90;
      }
      regmap_write(*wcd_usbss_ctxt_,uVar3,uVar4);
      goto LAB_00101ce8;
    }
    _printk(&DAT_001066bc,"wcd_usbss_audio_config",param_2);
    iVar2 = -0x16;
  }
  release_runtime_env(wcd_usbss_ctxt_);
LAB_00101b1c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd_usbss_switch_update @ 00101d44 size=2544
// signature: undefined wcd_usbss_switch_update(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_switch_update(ulong param_1,int param_2)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  uint uVar9;
  uint uVar10;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    return -0x13;
  }
  if (*wcd_usbss_ctxt_ == 0) {
    return -0x16;
  }
  mutex_lock(wcd_usbss_ctxt_ + 0x3b);
  _printk(&DAT_00106faa,"wcd_usbss_switch_update",param_1 & 0xffffffff,param_2);
  iVar2 = acquire_runtime_env(wcd_usbss_ctxt_);
  plVar1 = wcd_usbss_ctxt_;
  if (iVar2 < 0) {
    _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n","wcd_usbss_switch_update",
             iVar2);
    goto LAB_0010249c;
  }
  if (param_2 == 1) {
    uVar10 = (uint)(1L << (param_1 & 0x3f));
    *(uint *)(wcd_usbss_ctxt_ + 0x36) = *(uint *)(wcd_usbss_ctxt_ + 0x36) | uVar10;
    wcd_usbss_pd_pu_enable();
    wcd_usbss_standby_control_locked(0);
    switch(param_1 & 0xffffffff) {
    case 0:
      wcd_usbss_dpdm_switch_update(1,1);
      break;
    case 1:
    case 2:
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x81,7,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x80,0xe0,0xe0,0,0,0);
      iVar2 = wcd_usbss_display_port_switch_update(wcd_usbss_ctxt_,param_1 & 0xffffffff);
      if (iVar2 != 0) {
        *(uint *)(wcd_usbss_ctxt_ + 0x36) =
             *(uint *)(wcd_usbss_ctxt_ + 0x36) & (uVar10 ^ 0xffffffff);
      }
      goto LAB_00102480;
    case 3:
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,7,1,0,0,0);
      regmap_write(*wcd_usbss_ctxt_,1,0xf);
      regmap_write(*wcd_usbss_ctxt_,0x43,0x9e);
      regmap_write(*wcd_usbss_ctxt_,0x3d,2);
      if ((int)wcd_usbss_ctxt_[0x4d] == 1) {
        regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x40,0x40,0,0,0);
      }
      audio_fsm_mode = '\x01';
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x7f,0,0,0,0);
      if (audio_fsm_mode == '\x01') {
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x433,1,1,0,0,1);
      }
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x404,0x3f,2,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x29,8,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,6,6,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x405,1,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,1,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0x18,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x411,0xff,2,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x40d,0xff,2,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x40e,0xff,1,0,0,0);
      if (audio_fsm_mode == '\x01') {
        regmap_update_bits_base(*wcd_usbss_ctxt_,0x433,1,1,0,0,1);
      }
      lVar4 = 0;
      do {
        regmap_update_bits_base
                  (*wcd_usbss_ctxt_,*(undefined2 *)((long)&coeff_init + lVar4),
                   (&DAT_0010603e)[lVar4],(&DAT_0010603f)[lVar4],0,0,0);
        lVar4 = lVar4 + 4;
      } while (lVar4 != 0x28);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,8,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,8,8,0,0,0);
      usleep_range_state(10000,0x2774,2);
      break;
    case 4:
      _dev_info(wcd_usbss_ctxt_[1],"%s: GND MIC Swap register updates..\n","wcd_usbss_switch_update"
               );
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,7,1,0,0,0);
      regmap_write(*wcd_usbss_ctxt_,1,0xf);
      if ((int)wcd_usbss_ctxt_[0x4d] == 1) {
        regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x40,0x40,0,0,0);
      }
      audio_fsm_mode = '\x01';
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x7f,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x404,0x3f,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x25,8,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,6,6,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x405,1,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,1,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0x18,0,0,0);
      uVar7 = 0x433;
      uVar3 = 1;
      uVar5 = 1;
      lVar4 = *wcd_usbss_ctxt_;
      uVar8 = 1;
      goto LAB_00102478;
    case 5:
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,7,1,0,0,0);
      regmap_write(*wcd_usbss_ctxt_,1,0xf);
      regmap_write(*wcd_usbss_ctxt_,0x43,0x9e);
      regmap_write(*wcd_usbss_ctxt_,0x3d,2);
      if ((int)wcd_usbss_ctxt_[0x4d] == 1) {
        regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x40,0x40,0,0,0);
      }
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x404,3,1,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x405,1,0,0,0,0);
      uVar3 = 0x25;
      uVar5 = 8;
      uVar7 = 0;
      goto LAB_00102444;
    case 6:
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x404,0x3c,0x28,0,0,0);
      uVar3 = 0x18;
      uVar5 = 0x18;
      goto LAB_00102468;
    case 7:
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,7,0,0,0,0);
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x404,3,2,0,0,0);
      uVar3 = 0x405;
      uVar5 = 1;
      uVar7 = 1;
LAB_00102444:
      regmap_update_bits_base(*wcd_usbss_ctxt_,uVar3,uVar5,uVar7,0,0,0);
      uVar3 = 7;
      uVar5 = 7;
LAB_00102468:
      uVar7 = 0x403;
      lVar4 = *wcd_usbss_ctxt_;
      uVar8 = 0;
LAB_00102478:
      regmap_update_bits_base(lVar4,uVar7,uVar3,uVar5,0,0,uVar8);
    }
    iVar2 = 0;
LAB_00102480:
    if ((*(byte *)(wcd_usbss_ctxt_ + 0x36) & 0xb8) != 0) {
      plVar1 = wcd_usbss_ctxt_ + 1;
      *(undefined4 *)((long)wcd_usbss_ctxt_ + 0x26c) = 8;
      _dev_info(*plVar1,"%s: wcd state transition to %s complete\n","wcd_usbss_switch_update",
                "AUDIO");
    }
    goto switchD_00101e14_caseD_6;
  }
  if (param_2 != 0) goto LAB_00101f8c;
  iVar2 = 0;
  uVar10 = *(uint *)(wcd_usbss_ctxt_ + 0x36) & ((uint)(1L << (param_1 & 0x3f)) ^ 0xffffffff);
  *(uint *)(wcd_usbss_ctxt_ + 0x36) = uVar10;
  uVar9 = 0xffffffef;
  switch(param_1 & 0xffffffff) {
  case 0:
    if (((char)plVar1[0x3a] == '\0') || (*(char *)((long)plVar1 + 0x1d1) == '\0')) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    wcd_usbss_dpdm_switch_update(uVar3,0);
    iVar2 = 0;
    goto switchD_00101e14_caseD_6;
  case 1:
  case 2:
    regmap_update_bits_base(*plVar1,0x404,0xc0,0,0,0,0);
    regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x60,0,0,0,0);
    iVar2 = 0;
    *(uint *)(wcd_usbss_ctxt_ + 0x36) = *(uint *)(wcd_usbss_ctxt_ + 0x36) & 0xfffffff9;
    goto switchD_00101e14_caseD_6;
  case 3:
    break;
  case 4:
    uVar9 = 0xfffffff7;
    break;
  case 5:
    uVar9 = 0xffffff7f;
    break;
  default:
    goto switchD_00101e14_caseD_6;
  case 7:
    uVar9 = 0xffffffdf;
  }
  uVar10 = uVar10 & uVar9;
  *(uint *)(plVar1 + 0x36) = uVar10;
  if (uVar10 == 0) {
    wcd_usbss_switch_update_defaults();
    if ((char)wcd_usbss_ctxt_[0x3a] == '\0') {
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0x18,0,0,0);
      pcVar6 = "USB";
      lVar4 = wcd_usbss_ctxt_[1];
      *(undefined4 *)((long)wcd_usbss_ctxt_ + 0x26c) = 2;
    }
    else {
      regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0,0,0,0);
      wcd_usbss_standby_control_locked(1);
      pcVar6 = "STANDBY";
      lVar4 = wcd_usbss_ctxt_[1];
      *(undefined4 *)((long)wcd_usbss_ctxt_ + 0x26c) = 0;
    }
    _dev_info(lVar4,"wcd state transition to %s complete\n",pcVar6);
    iVar2 = 0;
  }
  else {
LAB_00101f8c:
    iVar2 = 0;
  }
switchD_00101e14_caseD_6:
  release_runtime_env(wcd_usbss_ctxt_);
LAB_0010249c:
  mutex_unlock(wcd_usbss_ctxt_ + 0x3b);
  return iVar2;
}



//------------------------------------------------------------
// wcd_usbss_switch_update_defaults @ 00102734 size=492
// signature: undefined wcd_usbss_switch_update_defaults(void)
// callers: [wcd_usbss_switch_update, wcd_usbss_sdam_handle_events_locked]
//------------------------------------------------------------

uint wcd_usbss_switch_update_defaults(undefined8 *param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar1 = regmap_update_bits_base(*param_1,0x403,7,0,0,0,0);
  uVar2 = regmap_update_bits_base(*param_1,0x405,1,0,0,0,0);
  uVar3 = regmap_update_bits_base(*param_1,0x404,3,0,0,0,0);
  uVar4 = regmap_update_bits_base(*param_1,0x25,8,8,0,0,0);
  uVar5 = regmap_update_bits_base(*param_1,0x29,8,8,0,0,0);
  uVar6 = regmap_update_bits_base(*param_1,0x433,1,1,0,0,1);
  uVar7 = regmap_update_bits_base(*param_1,0x404,0x3c,0x14,0,0,0);
  uVar8 = regmap_update_bits_base(*param_1,0x419,7,5,0,0,0);
  uVar9 = regmap_write(*param_1,1,0);
  uVar1 = uVar2 | uVar1 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9;
  if (*(int *)(wcd_usbss_ctxt_ + 0x4d) == 1) {
    uVar2 = regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x40,0,0,0,0);
    uVar1 = uVar2 | uVar1;
  }
  uVar2 = regmap_write(*wcd_usbss_ctxt_,0x43,0);
  uVar3 = regmap_write(*wcd_usbss_ctxt_,0x3d,0);
  audio_fsm_mode = 0;
  return uVar2 | uVar1 | uVar3;
}



//------------------------------------------------------------
// wcd_usbss_standby_control_locked @ 00102920 size=212
// signature: undefined wcd_usbss_standby_control_locked(void)
// callers: [wcd_usbss_switch_update, wcd_usbss_standby_control]
//------------------------------------------------------------

void wcd_usbss_standby_control_locked(byte param_1)

{
  int iVar1;
  undefined8 uVar2;
  char *pcVar3;
  
  if (*(byte *)((long)wcd_usbss_ctxt_ + 0x1d1) != (param_1 & 1)) {
    if ((param_1 & 1) == 0) {
      iVar1 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,0x10,0,0,0,0);
      if (-1 < iVar1) {
        usleep_range_state(10000,0x2774,2);
        *(undefined1 *)((long)wcd_usbss_ctxt_ + 0x1d1) = 0;
        return;
      }
      pcVar3 = "%s: exit standby failed\n";
      uVar2 = wcd_usbss_ctxt_[1];
    }
    else {
      iVar1 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,0x10,0x10,0,0,0);
      if (-1 < iVar1) {
        *(undefined1 *)((long)wcd_usbss_ctxt_ + 0x1d1) = 1;
        return;
      }
      uVar2 = wcd_usbss_ctxt_[1];
      pcVar3 = "%s: enter standby failed\n";
    }
    _dev_err(uVar2,pcVar3,"wcd_usbss_standby_control_locked");
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_pd_pu_enable @ 001029f4 size=252
// signature: undefined wcd_usbss_pd_pu_enable(void)
// callers: [wcd_usbss_switch_update]
//------------------------------------------------------------

void wcd_usbss_pd_pu_enable(void)

{
  regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x20,0,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x2c,0x20,0,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x1f,1,1,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x22,1,1,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x25,1,1,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x29,1,1,0,0,0);
  return;
}



//------------------------------------------------------------
// wcd_usbss_display_port_switch_update @ 00102af0 size=320
// signature: undefined wcd_usbss_display_port_switch_update(void)
// callers: [wcd_usbss_switch_update]
//------------------------------------------------------------

void wcd_usbss_display_port_switch_update(undefined8 *param_1,int param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00106a88);
  regmap_update_bits_base(*param_1,0x403,0x60,0,0,0,0);
  uVar3 = 0x40;
  if (param_2 != 1) {
    uVar3 = 0x80;
  }
  regmap_update_bits_base(*param_1,0x404,0xc0,uVar3,0,0,0);
  regmap_update_bits_base(*param_1,0x403,0x60,0x60,0,0,0);
  local_2c = 0;
  uVar2 = regmap_read(*param_1,0x407,&local_2c);
  if ((int)uVar2 == 0) {
    local_2c = local_2c & 0xcc;
    _printk(&DAT_001064c2);
    if (((param_2 == 1) && (local_2c == 0x48)) || ((param_2 == 2 && (local_2c == 0x84)))) {
      uVar2 = 0;
    }
    else {
      _printk(&DAT_00106f03);
      uVar2 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_reg_notifier @ 00102c34 size=108
// signature: undefined wcd_usbss_reg_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_usbss_reg_notifier(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_find_i2c_device_by_node(param_2);
  if ((lVar1 == 0) || (lVar1 = *(long *)(lVar1 + 0xb8), lVar1 == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = blocking_notifier_chain_register(lVar1 + 0x68,param_1);
    if ((int)uVar2 == 0) {
      if (*(int *)(lVar1 + 0x30) == 1) {
        uVar2 = wcd_usbss_usbc_analog_setup_switches(lVar1);
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_usbss_usbc_analog_setup_switches @ 00102ca0 size=244
// signature: undefined wcd_usbss_usbc_analog_setup_switches(void)
// callers: [wcd_usbss_reg_notifier, wcd_usbss_usbc_analog_work_fn]
//------------------------------------------------------------

void wcd_usbss_usbc_analog_setup_switches(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *puVar3;
  long lVar4;
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 8);
  local_3c[0] = 0;
  if (lVar4 == 0) {
    uVar2 = 0xffffffea;
    goto LAB_00102cd4;
  }
  mutex_lock(param_1 + 0xb0);
  iVar1 = *(int *)(param_1 + 0x30);
  _dev_info(lVar4,"%s: setting GPIOs active = %d cable_status = %d mode = %d\n",
            "wcd_usbss_usbc_analog_setup_switches",iVar1 != 0,*(undefined4 *)(param_1 + 0x1b0),iVar1
           );
  if (iVar1 == 0) {
    uVar2 = 0;
    puVar3 = (undefined1 *)0x0;
LAB_00102d7c:
    blocking_notifier_call_chain(param_1 + 0x68,uVar2,puVar3);
  }
  else if (iVar1 == 1) {
    if ((*(byte *)(param_1 + 0x1b0) & 0xb8) != 0) {
      local_3c[0] = 1;
    }
    puVar3 = local_3c;
    uVar2 = 1;
    goto LAB_00102d7c;
  }
  mutex_unlock(param_1 + 0xb0);
  uVar2 = 0;
LAB_00102cd4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_unreg_notifier @ 00102d98 size=76
// signature: undefined wcd_usbss_unreg_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_usbss_unreg_notifier(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  undefined8 uVar2;
  
  lVar1 = of_find_i2c_device_by_node(param_2);
  if ((lVar1 == 0) || (*(long *)(lVar1 + 0xb8) == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = blocking_notifier_chain_unregister(*(long *)(lVar1 + 0xb8) + 0x68,param_1);
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_usbss_update_default_trim @ 00102de8 size=208
// signature: undefined wcd_usbss_update_default_trim(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_update_default_trim(void)

{
  int iVar1;
  
  if (wcd_usbss_ctxt_ == (long *)0x0) {
    iVar1 = -0x13;
  }
  else if (*wcd_usbss_ctxt_ == 0) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = acquire_runtime_env();
    if (iVar1 < 0) {
      _dev_err(wcd_usbss_ctxt_[1],"%s: acquire_runtime_env failed: %i\n",
               "wcd_usbss_update_default_trim",iVar1);
    }
    else {
      regmap_write(*wcd_usbss_ctxt_,0x50,1);
      regmap_write(*wcd_usbss_ctxt_,0x90,0);
      regmap_write(*wcd_usbss_ctxt_,0x91,0);
      regmap_write(*wcd_usbss_ctxt_,0x92,0);
      release_runtime_env(wcd_usbss_ctxt_);
      iVar1 = 0;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_remove @ 00102ebc size=316
// signature: undefined wcd_usbss_remove(void)
// callers: []
//------------------------------------------------------------

void wcd_usbss_remove(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0xb8);
  if (lVar9 != 0) {
    lVar8 = *(long *)(lVar9 + 8);
    iVar5 = __pm_runtime_resume(lVar8,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar8 + 0x1f8);
      iVar6 = *(int *)(lVar8 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_00102fb8;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00102fb8:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
      _dev_err(*(undefined8 *)(lVar9 + 8),"%s: pm_runtime_resume_and_get failed: %i\n",
               "wcd_usbss_remove",iVar5);
    }
    else {
      iVar5 = 0;
    }
    if ((*(char *)(wcd_usbss_ctxt_ + 0x1b4) != '\0') && (*(long *)(wcd_usbss_ctxt_ + 0x1c0) != 0)) {
      kthread_stop();
      *(undefined8 *)(wcd_usbss_ctxt_ + 0x1c0) = 0;
    }
    unregister_ucsi_glink_notifier(lVar9 + 0x18);
    cancel_work_sync(lVar9 + 0x38);
    pm_relax(*(undefined8 *)(lVar9 + 8));
    if (-1 < iVar5) {
      __pm_runtime_idle(*(undefined8 *)(lVar9 + 8),4);
    }
    __pm_runtime_use_autosuspend(*(undefined8 *)(lVar9 + 8),0);
    __pm_runtime_disable(*(undefined8 *)(lVar9 + 8),1);
    uVar7 = *(undefined8 *)(lVar9 + 8);
    device_wakeup_disable(uVar7);
    device_set_wakeup_capable(uVar7,0);
    *(undefined8 *)(param_1 + 0xb8) = 0;
    wcd_usbss_ctxt_ = 0;
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_probe @ 00103010 size=1236
// signature: undefined wcd_usbss_probe(void)
// callers: []
//------------------------------------------------------------

int wcd_usbss_probe(ulong param_1)

{
  long lVar1;
  int iVar2;
  ulong *puVar3;
  char *pcVar4;
  ulong uVar5;
  ulong *puVar6;
  int local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  uVar5 = param_1 + 0x20;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  puVar3 = (ulong *)devm_kmalloc(uVar5,0x2a8,0xdc0);
  if (puVar3 == (ulong *)0x0) {
    iVar2 = -0xc;
    goto LAB_0010305c;
  }
  puVar3[1] = uVar5;
  puVar3[2] = param_1;
  *(undefined4 *)(puVar3 + 0x4e) = 0;
  __mutex_init(puVar3 + 0x30,"&priv->io_lock",&wcd_usbss_probe___key);
  __mutex_init(puVar3 + 0x3b,"&priv->switch_update_lock",&wcd_usbss_probe___key_29);
  __mutex_init(puVar3 + 0x41,"&priv->runtime_env_counter_lock",&wcd_usbss_probe___key_31);
  __mutex_init(puVar3 + 0x47,"&priv->suspend_status_lock",&wcd_usbss_probe___key_33);
  *(ulong **)(param_1 + 0xb8) = puVar3;
  pm_runtime_enable(uVar5);
  __pm_runtime_use_autosuspend(uVar5,1);
  pm_runtime_set_autosuspend_delay(uVar5,600);
  uVar5 = puVar3[1];
  device_set_wakeup_capable(uVar5,1);
  device_wakeup_enable(uVar5);
  iVar2 = acquire_runtime_env(puVar3);
  if (iVar2 < 0) {
    pcVar4 = "%s: acquire_runtime_env failed: %i\n";
    uVar5 = wcd_usbss_ctxt_[1];
LAB_0010315c:
    _dev_err(uVar5,pcVar4,"wcd_usbss_probe",iVar2);
  }
  else {
    puVar6 = puVar3 + 0x1c;
    *puVar6 = (ulong)"vdd-usb-cp";
    iVar2 = devm_regulator_bulk_get(puVar3[1],1,puVar6);
    if (iVar2 < 0) {
      uVar5 = puVar3[1];
      pcVar4 = "Failed to get supplies: %d\n";
    }
    else {
      iVar2 = regulator_bulk_enable(1,puVar6);
      if (iVar2 == 0) {
        wcd_usbss_init_optional_reset_pins(puVar3);
        wcd_usbss_regmap_config._40_8_ = wcd_usbss_readable_register;
        uVar5 = wcd_usbss_regmap_init(puVar3[1]);
        *puVar3 = uVar5;
        if ((uVar5 != 0) && (uVar5 < 0xfffffffffffff001)) {
          regmap_update_bits_base(uVar5,99,0x77,0x77,0,0,0);
          regmap_update_bits_base(*puVar3,0x1e,0xe,8,0,0,0);
          regmap_update_bits_base(*puVar3,0x21,0xe,8,0,0,0);
          regmap_update_bits_base(*puVar3,0x81,7,1,0,0,0);
          regmap_update_bits_base(*puVar3,0x80,0xe0,0xe0,0,0,0);
          regmap_update_bits_base(*puVar3,0x82,0xe0,0xe0,0,0,0);
          regmap_update_bits_base(*puVar3,0x24,0xc,0xc,0,0,0);
          regmap_update_bits_base(*puVar3,0x28,0xc,0xc,0,0,0);
          regmap_read(*puVar3,0x439,&local_4c);
          if (local_4c == 1) {
            regmap_update_bits_base(*puVar3,0x24,2,0,0,0,0);
            regmap_update_bits_base(*puVar3,0x28,2,0,0,0,0);
          }
          *(int *)(puVar3 + 0x4d) = local_4c;
          devm_regmap_qti_debugfs_register(puVar3[1],*puVar3);
          wcd_usbss_ctxt_ = puVar3;
          *(ulong **)(param_1 + 0xb8) = puVar3;
          iVar2 = wcd_usbss_sdam_registration(puVar3);
          if (iVar2 == 0) {
            *(undefined1 *)(puVar3 + 0x3a) = 1;
          }
          else {
            _dev_info(puVar3[1],"wcd standby feature not enabled\n");
          }
          puVar3[3] = (ulong)wcd_usbss_usbc_event_changed;
          *(undefined4 *)(puVar3 + 5) = 0;
          iVar2 = register_ucsi_glink_notifier();
          if (iVar2 == 0) {
            __mutex_init(puVar3 + 0x16,"&priv->notification_lock",&wcd_usbss_probe___key_40);
            wcd_usbss_update_reg_init(*puVar3);
            puVar3[7] = 0xfffffffe0;
            puVar3[8] = (ulong)(puVar3 + 8);
            puVar3[9] = (ulong)(puVar3 + 8);
            puVar3[10] = (ulong)wcd_usbss_usbc_analog_work_fn;
            __init_rwsem(puVar3 + 0xd,"&(&priv->wcd_usbss_notifier)->rwsem",
                         &wcd_usbss_probe___key_42);
            puVar3[0x15] = 0;
            iVar2 = wcd_usbss_sysfs_init(puVar3);
            if (iVar2 == 0) {
              *(undefined4 *)(puVar3 + 0x39) = 15000;
              *(undefined1 *)((long)puVar3 + 0x1b4) = 1;
              wcd_usbss_enable_surge_kthread();
            }
            puVar6 = wcd_usbss_ctxt_ + 0x52;
            *(undefined4 *)(wcd_usbss_ctxt_ + 0x51) = 0;
            __init_swait_queue_head(puVar6,"&x->wait",&init_completion___key);
            release_runtime_env(wcd_usbss_ctxt_);
            _dev_info(puVar3[1],"Probe completed!\n");
            iVar2 = 0;
            goto LAB_0010305c;
          }
          uVar5 = puVar3[1];
          pcVar4 = "%s: ucsi glink notifier registration failed: %d\n";
          goto LAB_0010315c;
        }
        iVar2 = -0x16;
        if (uVar5 != 0) {
          iVar2 = (int)uVar5;
        }
        uVar5 = puVar3[1];
        pcVar4 = "Failed to initialize regmap: %d\n";
      }
      else {
        uVar5 = puVar3[1];
        pcVar4 = "Failed to enable supplies: %d\n";
      }
    }
    _dev_err(uVar5,pcVar4,iVar2);
  }
  uVar5 = puVar3[1];
  device_wakeup_disable(uVar5);
  device_set_wakeup_capable(uVar5,0);
  __pm_runtime_use_autosuspend(wcd_usbss_ctxt_[1],0);
  __pm_runtime_disable(wcd_usbss_ctxt_[1],1);
LAB_0010305c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// wcd_usbss_shutdown @ 001034e8 size=280
// signature: undefined wcd_usbss_shutdown(void)
// callers: []
//------------------------------------------------------------

void wcd_usbss_shutdown(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_1 + 0xb8);
  if (lVar9 != 0) {
    lVar8 = *(long *)(lVar9 + 8);
    iVar5 = __pm_runtime_resume(lVar8,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar8 + 0x1f8);
      iVar6 = *(int *)(lVar8 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_001035c0;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_001035c0:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
      _dev_err(*(undefined8 *)(lVar9 + 8),"%s: pm_runtime_resume_and_get failed: %i\n",
               "wcd_usbss_shutdown",iVar5);
    }
    else {
      iVar5 = 0;
    }
    if ((*(char *)(wcd_usbss_ctxt_ + 0x1b4) != '\0') && (*(long *)(wcd_usbss_ctxt_ + 0x1c0) != 0)) {
      kthread_stop();
      *(undefined8 *)(wcd_usbss_ctxt_ + 0x1c0) = 0;
    }
    if (-1 < iVar5) {
      __pm_runtime_idle(*(undefined8 *)(lVar9 + 8),4);
    }
    __pm_runtime_use_autosuspend(*(undefined8 *)(lVar9 + 8),0);
    __pm_runtime_disable(*(undefined8 *)(lVar9 + 8),1);
    uVar7 = *(undefined8 *)(lVar9 + 8);
    device_wakeup_disable(uVar7);
    device_set_wakeup_capable(uVar7,0);
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_init_optional_reset_pins @ 00103614 size=100
// signature: undefined wcd_usbss_init_optional_reset_pins(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

void wcd_usbss_init_optional_reset_pins(long param_1)

{
  ulong uVar1;
  
  uVar1 = devm_pinctrl_get(*(undefined8 *)(param_1 + 8));
  *(ulong *)(param_1 + 0x160) = uVar1;
  if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
    uVar1 = pinctrl_lookup_state(uVar1,"active");
    *(ulong *)(param_1 + 0x168) = uVar1;
    if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
      pinctrl_select_state(*(undefined8 *)(param_1 + 0x160),uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_readable_register @ 0010367c size=76
// signature: undefined wcd_usbss_readable_register(void)
// callers: []
//------------------------------------------------------------

byte wcd_usbss_readable_register(undefined8 param_1,uint param_2)

{
  code *pcVar1;
  
  if ((param_2 == 0) ||
     (((wcd_usbss_ctxt_ != 0 && (param_2 - 0x4e1 < 0xb)) && (*(int *)(wcd_usbss_ctxt_ + 0x268) == 0)
      ))) {
    return 0;
  }
  if (0x4eb < param_2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1036c8);
    (*pcVar1)();
  }
  return (&wcd_usbss_reg_access)[param_2] & 1;
}



//------------------------------------------------------------
// wcd_usbss_sdam_registration @ 001036c8 size=232
// signature: undefined wcd_usbss_sdam_registration(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

ulong wcd_usbss_sdam_registration(long param_1)

{
  uint uVar1;
  ulong uVar2;
  
  *(undefined4 *)(param_1 + 0x26c) = 2;
  uVar2 = devm_nvmem_cell_get(*(undefined8 *)(param_1 + 8),"usb_mode");
  *(ulong *)(param_1 + 0x278) = uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar1 = devm_request_threaded_irq
                      (*(undefined8 *)(param_1 + 8),
                       *(undefined4 *)(*(long *)(param_1 + 0x10) + 0x3b4),0,
                       wcd_usbss_sdam_notifier_handler,0x2000,"wcd-usbss-sdam",param_1);
    if (uVar1 != 0) {
      uVar2 = (ulong)uVar1;
      _dev_err(*(undefined8 *)(param_1 + 8),
               "sdam registration failed, standby not supported, rc:%d\n",uVar2);
      goto LAB_00103710;
    }
    irq_set_irq_wake(*(undefined4 *)(*(long *)(param_1 + 0x10) + 0x3b4),1);
  }
  else {
    if ((int)uVar2 == -0x205) {
      uVar2 = 0xfffffdfb;
      goto LAB_00103710;
    }
    _dev_err(*(undefined8 *)(param_1 + 8),"nvmem cell get failed, rc:%d\n",uVar2 & 0xffffffff);
    if ((int)uVar2 != 0) goto LAB_00103710;
  }
  _dev_info(*(undefined8 *)(param_1 + 8),"sdam registration successful\n");
  uVar2 = 0;
LAB_00103710:
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// wcd_usbss_usbc_event_changed @ 001037b4 size=152
// signature: undefined wcd_usbss_usbc_event_changed(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 wcd_usbss_usbc_event_changed(long param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  undefined8 uVar2;
  
  if ((param_1 == 0x18) || (*(long *)(param_1 + -0x10) == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar1 = *param_3;
    _dev_info(*(long *)(param_1 + -0x10),
              "%s: USB change event received, supply mode %d, usbc mode %ld, expected %d\n",
              "wcd_usbss_usbc_event_changed",uVar1,*(undefined4 *)(param_1 + 0x18),1);
    if ((uVar1 < 2) && (*(uint *)(param_1 + 0x18) != uVar1)) {
      *(uint *)(param_1 + 0x18) = uVar1;
      pm_stay_awake(*(undefined8 *)(param_1 + -0x10));
      queue_work_on(0x20,_system_freezable_wq,param_1 + 0x20);
    }
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_usbss_update_reg_init @ 0010384c size=260
// signature: undefined wcd_usbss_update_reg_init(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

void wcd_usbss_update_reg_init(undefined8 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (audio_fsm_mode != '\0') {
    uVar1 = 2;
  }
  regmap_update_bits_base(param_1,0x413,3,uVar1,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x20,9,9,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x27,0x24,0x24,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0x2b,0x24,0x24,0,0,0);
  regmap_update_bits_base(param_1,0x415,0x80,0,0,0,0);
  regmap_update_bits_base(*wcd_usbss_ctxt_,0xa1,0xff,0xff,0,0,0);
  return;
}



//------------------------------------------------------------
// wcd_usbss_usbc_analog_work_fn @ 00103954 size=80
// signature: undefined wcd_usbss_usbc_analog_work_fn(void)
// callers: []
//------------------------------------------------------------

void wcd_usbss_usbc_analog_work_fn(long param_1)

{
  if (param_1 + -0x38 == 0) {
    _printk(&DAT_00106613,"wcd_usbss_usbc_analog_work_fn");
  }
  else {
    wcd_usbss_usbc_analog_setup_switches(param_1 + -0x38);
    pm_relax(*(undefined8 *)(param_1 + -0x30));
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_sysfs_init @ 001039a4 size=248
// signature: undefined wcd_usbss_sysfs_init(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int wcd_usbss_sysfs_init(long param_1)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  char *pcVar4;
  
  lVar2 = kobject_create_and_add("wcd_usbss",_kernel_kobj);
  *(long *)(param_1 + 0x1b8) = lVar2;
  if (lVar2 == 0) {
    _dev_err(*(undefined8 *)(param_1 + 8),"%s: sysfs failed, surge kobj not created\n",
             "wcd_usbss_sysfs_init");
    iVar1 = -0xc;
  }
  else {
    iVar1 = sysfs_create_file_ns(lVar2,&wcd_usbss_surge_enable_attribute,0);
    if (iVar1 < 0) {
      uVar3 = *(undefined8 *)(param_1 + 8);
      pcVar4 = "%s: sysfs failed, unable to register surge enable attribute. rc: %d\n";
    }
    else {
      iVar1 = sysfs_create_file_ns
                        (*(undefined8 *)(param_1 + 0x1b8),&wcd_usbss_surge_period_attribute,0);
      if (iVar1 < 0) {
        uVar3 = *(undefined8 *)(param_1 + 8);
        pcVar4 = "%s: sysfs failed, unable to register surge period attribute. rc: %d\n";
      }
      else {
        iVar1 = sysfs_create_file_ns
                          (*(undefined8 *)(param_1 + 0x1b8),&wcd_usbss_standby_enable_attribute,0);
        if (-1 < iVar1) {
          return 0;
        }
        uVar3 = *(undefined8 *)(param_1 + 8);
        pcVar4 = "%s: sysfs failed, unable to register standby enable attribute. rc: %d\n";
      }
    }
    _dev_err(uVar3,pcVar4,"wcd_usbss_sysfs_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// wcd_usbss_enable_surge_kthread @ 00103a9c size=140
// signature: undefined wcd_usbss_enable_surge_kthread(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

void wcd_usbss_enable_surge_kthread(void)

{
  ulong uVar1;
  
  if ((*(char *)(wcd_usbss_ctxt_ + 0x1b4) != '\0') && (*(long *)(wcd_usbss_ctxt_ + 0x1c0) == 0)) {
    uVar1 = kthread_create_on_node(wcd_usbss_surge_kthread_fn,0,0xffffffff,"Surge kthread");
    if (uVar1 < 0xfffffffffffff001) {
      wake_up_process(uVar1);
    }
    *(ulong *)(wcd_usbss_ctxt_ + 0x1c0) = uVar1;
    if (uVar1 == 0) {
      _printk(&DAT_00106f48,"wcd_usbss_enable_surge_kthread");
    }
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_sdam_notifier_handler @ 00103b2c size=576
// signature: undefined wcd_usbss_sdam_notifier_handler(void)
// callers: []
//------------------------------------------------------------

ulong wcd_usbss_sdam_notifier_handler(undefined8 param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  int iVar3;
  byte *pbVar4;
  char *pcVar5;
  undefined8 local_48;
  byte local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_48 = 0;
  pbVar4 = (byte *)nvmem_cell_read(*(undefined8 *)(param_2 + 0x278),&local_48);
  if ((byte *)0xfffffffffffff000 < pbVar4) {
    _dev_err(*(undefined8 *)(param_2 + 8),"nvmem cell read failed, rc:%d\n",
             (ulong)pbVar4 & 0xffffffff);
    goto LAB_00103d20;
  }
  local_3c[0] = *pbVar4;
  *pbVar4 = *pbVar4 & 3;
  mutex_lock(wcd_usbss_ctxt_ + 0x1d8);
  bVar1 = *pbVar4;
  if (*(uint *)(param_2 + 0x26c) == (uint)bVar1) {
    if (bVar1 < 9) {
      pcVar5 = (&PTR_s_STANDBY_001062f8)[(char)bVar1];
    }
    else {
      pcVar5 = "UNDEFINED";
    }
    _dev_info(*(undefined8 *)(param_2 + 8),"%s: wcd already in %s mode:\n",
              "wcd_usbss_sdam_notifier_handler",pcVar5);
    goto LAB_00103cc0;
  }
  iVar3 = acquire_runtime_env(wcd_usbss_ctxt_);
  lVar2 = wcd_usbss_ctxt_;
  if ((iVar3 == -0xd) || (-1 < iVar3)) {
    if (*(char *)(wcd_usbss_ctxt_ + 0x280) == '\0') {
      iVar3 = wcd_usbss_sdam_handle_events_locked(*pbVar4);
      if (iVar3 == 0) {
        bVar1 = *pbVar4;
        *(uint *)(param_2 + 0x26c) = (uint)bVar1;
        if (bVar1 < 9) {
          pcVar5 = (&PTR_s_STANDBY_001062f8)[(char)bVar1];
        }
        else {
          pcVar5 = "UNDEFINED";
        }
        _dev_info(*(undefined8 *)(param_2 + 8),"%s: wcd state transition to %s complete\n",
                  "wcd_usbss_sdam_notifier_handler",pcVar5);
        release_runtime_env(wcd_usbss_ctxt_);
        goto LAB_00103cc0;
      }
      release_runtime_env(wcd_usbss_ctxt_);
    }
    else {
      *(undefined1 *)(wcd_usbss_ctxt_ + 0x281) = 1;
      *(uint *)(lVar2 + 0x284) = (uint)*pbVar4;
      release_runtime_env();
      if (iVar3 == 0) {
LAB_00103cc0:
        bVar1 = local_3c[0];
        _dev_info(*(undefined8 *)(param_2 + 8),"%s: write wcd mode=0x%x\n",
                  "wcd_usbss_sdam_notifier_handler",local_3c[0]);
        local_3c[0] = bVar1 | *pbVar4 << 4 | *pbVar4;
        iVar3 = nvmem_cell_write(*(undefined8 *)(param_2 + 0x278),local_3c,1);
        if (iVar3 != 1) {
          _dev_err(*(undefined8 *)(param_2 + 8),"nvmem cell write failed, rc:%d\n",iVar3);
        }
      }
    }
  }
  else {
    _dev_err(*(undefined8 *)(param_2 + 8),"%s: acquire_runtime_env failed: %d\n",
             "wcd_usbss_sdam_notifier_handler",iVar3);
  }
  mutex_unlock(wcd_usbss_ctxt_ + 0x1d8);
  kfree(pbVar4);
  pbVar4 = (byte *)0x1;
LAB_00103d20:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)pbVar4 & 0xffffffff;
}



//------------------------------------------------------------
// wcd_usbss_sdam_handle_events_locked @ 00103d6c size=1168
// signature: undefined wcd_usbss_sdam_handle_events_locked(void)
// callers: [wcd_usbss_sdam_notifier_handler, wcd_usbss_pm_resume]
//------------------------------------------------------------

uint wcd_usbss_sdam_handle_events_locked(undefined4 param_1)

{
  undefined8 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  undefined8 uVar10;
  char *pcVar11;
  undefined8 uVar12;
  
  puVar1 = wcd_usbss_ctxt_;
  switch(param_1) {
  case 0:
    uVar2 = wcd_usbss_switch_update_defaults(wcd_usbss_ctxt_);
    uVar3 = regmap_update_bits_base(*puVar1,2,0x20,0,0,0,0);
    uVar4 = regmap_update_bits_base(*puVar1,0x2c,0x20,0,0,0,0);
    uVar5 = regmap_update_bits_base(*puVar1,0x1f,1,1,0,0,0);
    uVar6 = regmap_update_bits_base(*puVar1,0x22,1,1,0,0,0);
    uVar7 = regmap_update_bits_base(*puVar1,0x25,1,1,0,0,0);
    uVar8 = regmap_update_bits_base(*puVar1,0x29,1,1,0,0,0);
    iVar9 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x403,0x18,0,0,0,0);
    if (iVar9 != 0) {
      _printk(&DAT_00106b72,"wcd_usbss_dpdm_switch_update_from_handler",iVar9);
    }
    uVar2 = uVar3 | uVar2 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8;
    iVar9 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x415,0x80,0,0,0,0);
    if (iVar9 != 0) {
      _printk(&DAT_00106dc8,"wcd_usbss_dpdm_switch_update_from_handler",iVar9);
    }
    if (*(char *)((long)wcd_usbss_ctxt_ + 0x1d1) == '\x01') {
      return uVar2;
    }
    iVar9 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,0x10,0x10,0,0,0);
    if (-1 < iVar9) {
      *(undefined1 *)((long)wcd_usbss_ctxt_ + 0x1d1) = 1;
      return uVar2;
    }
    uVar10 = wcd_usbss_ctxt_[1];
    pcVar11 = "%s: enter standby failed\n";
    goto LAB_001041ec;
  case 1:
  case 3:
    uVar2 = regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x20,0x20,0,0,0);
    uVar3 = regmap_update_bits_base(*puVar1,0x2c,0x20,0x20,0,0,0);
    uVar4 = regmap_update_bits_base(*puVar1,0x1f,1,0,0,0,0);
    uVar5 = regmap_update_bits_base(*puVar1,0x22,1,0,0,0,0);
    uVar2 = uVar3 | uVar2 | uVar4 | uVar5;
    uVar3 = regmap_update_bits_base(*puVar1,0x25,1,0,0,0,0);
    uVar10 = *puVar1;
    uVar12 = 0;
    break;
  case 2:
    uVar2 = regmap_update_bits_base(*wcd_usbss_ctxt_,2,0x20,0,0,0,0);
    uVar3 = regmap_update_bits_base(*puVar1,0x2c,0x20,0,0,0,0);
    uVar4 = regmap_update_bits_base(*puVar1,0x1f,1,1,0,0,0);
    uVar5 = regmap_update_bits_base(*puVar1,0x22,1,1,0,0,0);
    uVar2 = uVar3 | uVar2 | uVar4 | uVar5;
    uVar3 = regmap_update_bits_base(*puVar1,0x25,1,1,0,0,0);
    uVar10 = *puVar1;
    uVar12 = 1;
    break;
  default:
    _dev_err(wcd_usbss_ctxt_[1],"unexpected state:%d\n");
    return 0xffffffea;
  }
  uVar4 = regmap_update_bits_base(uVar10,0x29,1,uVar12,0,0,0);
  uVar2 = uVar2 | uVar3 | uVar4;
  regmap_update_bits_base(*puVar1,0x403,0x18,0x18,0,0,0);
  if (*(char *)((long)wcd_usbss_ctxt_ + 0x1d1) != '\0') {
    iVar9 = regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,0x10,0,0,0,0);
    if (iVar9 < 0) {
      pcVar11 = "%s: exit standby failed\n";
      uVar10 = wcd_usbss_ctxt_[1];
LAB_001041ec:
      _dev_err(uVar10,pcVar11,"wcd_usbss_standby_control_locked");
    }
    else {
      usleep_range_state(10000,0x2774,2);
      *(undefined1 *)((long)wcd_usbss_ctxt_ + 0x1d1) = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// wcd_usbss_surge_enable_store @ 00104200 size=156
// signature: undefined wcd_usbss_surge_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
wcd_usbss_surge_enable_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  lVar1 = wcd_usbss_ctxt_;
  if (iVar2 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    if (*(int *)(wcd_usbss_ctxt_ + 0x1c8) == 0) {
      *(undefined4 *)(wcd_usbss_ctxt_ + 0x1c8) = 15000;
    }
    *(bool *)(lVar1 + 0x1b4) = local_2c != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wcd_usbss_surge_period_store @ 001042a0 size=200
// signature: undefined wcd_usbss_surge_period_store(void)
// callers: []
//------------------------------------------------------------

undefined8
wcd_usbss_surge_period_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtouint(param_3,10,&local_2c);
  lVar1 = wcd_usbss_ctxt_;
  if (iVar2 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    if (local_2c - 3U < 0x12) {
      *(int *)(wcd_usbss_ctxt_ + 0x1c8) = local_2c * 1000;
      lVar3 = *(long *)(lVar1 + 0x1c0);
    }
    else {
      lVar3 = *(long *)(wcd_usbss_ctxt_ + 0x1c0);
    }
    if (((lVar3 != 0) && (*(int *)(lVar1 + 0x1b0) != 0)) && (*(char *)(lVar1 + 0x1b4) != '\0')) {
      wake_up_process();
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wcd_usbss_standby_store @ 0010436c size=184
// signature: undefined wcd_usbss_standby_store(void)
// callers: []
//------------------------------------------------------------

undefined8
wcd_usbss_standby_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar3 = kstrtouint(param_3,10,&local_2c);
  lVar1 = wcd_usbss_ctxt_;
  if (iVar3 < 0) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    *(undefined1 *)(wcd_usbss_ctxt_ + 0x1d0) = 1;
    if (local_2c == 0) {
      bVar2 = false;
    }
    else {
      bVar2 = *(int *)(lVar1 + 0x1b0) == 0;
    }
    wcd_usbss_standby_control(bVar2);
    *(bool *)(wcd_usbss_ctxt_ + 0x1d0) = local_2c != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// wcd_usbss_standby_control @ 00104424 size=136
// signature: undefined wcd_usbss_standby_control(void)
// callers: [wcd_usbss_standby_store]
//------------------------------------------------------------

void wcd_usbss_standby_control(uint param_1)

{
  int iVar1;
  
  if (*(char *)(wcd_usbss_ctxt_ + 0x1d0) != '\0') {
    mutex_lock(wcd_usbss_ctxt_ + 0x1d8);
    iVar1 = acquire_runtime_env(wcd_usbss_ctxt_);
    if (iVar1 < 0) {
      _dev_err(*(undefined8 *)(wcd_usbss_ctxt_ + 8),"%s: acquire_runtime_env failed: %i\n",
               "wcd_usbss_standby_control",iVar1);
    }
    else {
      wcd_usbss_standby_control_locked(param_1 & 1);
      release_runtime_env(wcd_usbss_ctxt_);
    }
    mutex_unlock(wcd_usbss_ctxt_ + 0x1d8);
  }
  return;
}



//------------------------------------------------------------
// wcd_usbss_surge_kthread_fn @ 001044b0 size=992
// signature: undefined wcd_usbss_surge_kthread_fn(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_usbss_surge_kthread_fn(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ulong uVar6;
  char *pcVar7;
  uint local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  uVar6 = kthread_should_stop();
  do {
    if ((uVar6 & 1) != 0) {
      lVar1 = sp_el0;
      if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return 0;
    }
    iVar2 = acquire_runtime_env(wcd_usbss_ctxt_);
    if (-1 < iVar2) {
      if (*(char *)((long)wcd_usbss_ctxt_ + 0x1b4) != '\0') {
        local_5c = 0;
        iVar2 = regmap_read(*wcd_usbss_ctxt_,0xa1,&local_5c);
        if (iVar2 == 0) {
          if (local_5c == 0xff) {
            iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
            if (iVar2 == 0) {
              if (((byte)local_5c >> 1 & 1) != 0) {
                iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                if (iVar2 != 0) goto LAB_00104568;
                if (((byte)local_5c >> 1 & 1) != 0) {
                  iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                  if (iVar2 != 0) goto LAB_00104568;
                  if (((byte)local_5c >> 1 & 1) != 0) {
                    iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                    if (iVar2 != 0) goto LAB_00104568;
                    if (((byte)local_5c >> 1 & 1) != 0) {
                      iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                      if (iVar2 != 0) goto LAB_00104568;
                      if (((byte)local_5c >> 1 & 1) != 0) {
                        iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                        if (iVar2 != 0) goto LAB_00104568;
                        if (((byte)local_5c >> 1 & 1) != 0) {
                          iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                          if (iVar2 != 0) goto LAB_00104568;
                          if (((byte)local_5c >> 1 & 1) != 0) {
                            iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                            if (iVar2 != 0) goto LAB_00104568;
                            if (((byte)local_5c >> 1 & 1) != 0) {
                              iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                              if (iVar2 != 0) goto LAB_00104568;
                              if (((byte)local_5c >> 1 & 1) != 0) {
                                iVar2 = regmap_read(*wcd_usbss_ctxt_,0x15,&local_5c);
                                if (iVar2 != 0) goto LAB_00104568;
                                if (((byte)local_5c >> 1 & 1) != 0) {
                                  pcVar7 = "%s: Surge check #2 failed\n";
                                  goto LAB_001047ac;
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
              mutex_lock(wcd_usbss_ctxt_ + 0x3b);
              if (*(char *)((long)wcd_usbss_ctxt_ + 0x1d1) == '\0') {
                iVar2 = regmap_update_bits_base(*wcd_usbss_ctxt_,5,1,0,0,0,0);
                iVar3 = regmap_update_bits_base(*wcd_usbss_ctxt_,5,1,1,0,0,0);
                iVar4 = regmap_update_bits_base(*wcd_usbss_ctxt_,5,1,0,0,0,0);
                iVar5 = regmap_read(*wcd_usbss_ctxt_,6,&local_5c);
                if (((iVar3 == 0 && iVar2 == 0) && (iVar4 == 0 && iVar5 == 0)) &&
                   ((local_5c & 1) == 0)) {
                  _dev_err(wcd_usbss_ctxt_[1],"%s: Surge check #3 failed\n",
                           "wcd_usbss_is_in_reset_state");
                  mutex_unlock(wcd_usbss_ctxt_ + 0x3b);
                  goto LAB_001047b8;
                }
              }
              mutex_unlock(wcd_usbss_ctxt_ + 0x3b);
            }
          }
          else {
            pcVar7 = "%s: Surge check #1 failed\n";
LAB_001047ac:
            _dev_err(wcd_usbss_ctxt_[1],pcVar7,"wcd_usbss_is_in_reset_state");
LAB_001047b8:
            regcache_mark_dirty(*wcd_usbss_ctxt_);
            regcache_sync(*wcd_usbss_ctxt_);
            regmap_update_bits_base(*wcd_usbss_ctxt_,0xa1,0xff,0xff,0,0,0);
            regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,8,0,0,0,0);
            regmap_update_bits_base(*wcd_usbss_ctxt_,0x419,8,8,0,0,0);
            if ((*(byte *)(wcd_usbss_ctxt_ + 0x36) & 0xb8) != 0) {
              blocking_notifier_call_chain(wcd_usbss_ctxt_ + 0xd,3,0);
            }
          }
        }
      }
LAB_00104568:
      release_runtime_env(wcd_usbss_ctxt_);
    }
    msleep_interruptible(*(undefined4 *)(wcd_usbss_ctxt_ + 0x39));
    uVar6 = kthread_should_stop();
  } while( true );
}



//------------------------------------------------------------
// wcd_usbss_pm_suspend @ 00104894 size=84
// signature: undefined wcd_usbss_pm_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_usbss_pm_suspend(void)

{
  long lVar1;
  
  if (wcd_usbss_ctxt_ != 0) {
    mutex_lock(wcd_usbss_ctxt_ + 0x1d8);
    lVar1 = wcd_usbss_ctxt_ + 0x1d8;
    *(undefined1 *)(wcd_usbss_ctxt_ + 0x280) = 1;
    mutex_unlock(lVar1);
    *(undefined4 *)(wcd_usbss_ctxt_ + 0x288) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// wcd_usbss_pm_resume @ 001048ec size=120
// signature: undefined wcd_usbss_pm_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 wcd_usbss_pm_resume(void)

{
  int iVar1;
  long lVar2;
  
  if (wcd_usbss_ctxt_ != 0) {
    mutex_lock(wcd_usbss_ctxt_ + 0x1d8);
    lVar2 = wcd_usbss_ctxt_;
    if (*(char *)(wcd_usbss_ctxt_ + 0x281) != '\0') {
      iVar1 = wcd_usbss_sdam_handle_events_locked(*(undefined4 *)(wcd_usbss_ctxt_ + 0x284));
      lVar2 = wcd_usbss_ctxt_;
      *(undefined1 *)(wcd_usbss_ctxt_ + 0x281) = 0;
      if (iVar1 == 0) {
        *(undefined4 *)(lVar2 + 0x26c) = *(undefined4 *)(lVar2 + 0x284);
      }
    }
    *(undefined1 *)(lVar2 + 0x280) = 0;
    mutex_unlock(lVar2 + 0x1d8);
    complete(wcd_usbss_ctxt_ + 0x288);
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010713c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,&wcd_usbss_i2c_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010716c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(&wcd_usbss_i2c_driver);
  return;
}



//------------------------------------------------------------
// __devm_regmap_init @ 00109000 size=1
// signature: undefined __devm_regmap_init(void)
// callers: [wcd_usbss_regmap_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_regmap_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109008 size=1
// signature: undefined mutex_lock(void)
// callers: [wcd_usbss_pm_suspend, wcd_usbss_surge_kthread_fn, wcd_usbss_switch_update, wcd_usbss_sdam_notifier_handler, release_runtime_env, wcd_usbss_standby_control, wcd_usbss_pm_resume, acquire_runtime_env, wcd_usbss_usbc_analog_setup_switches, regmap_bus_gather_write, regmap_bus_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109010 size=1
// signature: undefined mutex_unlock(void)
// callers: [wcd_usbss_pm_suspend, wcd_usbss_surge_kthread_fn, wcd_usbss_switch_update, wcd_usbss_sdam_notifier_handler, release_runtime_env, wcd_usbss_standby_control, wcd_usbss_pm_resume, acquire_runtime_env, wcd_usbss_usbc_analog_setup_switches, regmap_bus_gather_write, regmap_bus_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109018 size=1
// signature: undefined _dev_err(void)
// callers: [wcd_usbss_register_update, wcd_usbss_standby_control_locked, wcd_usbss_surge_kthread_fn, wcd_usbss_update_default_trim, release_runtime_env, wcd_usbss_standby_control, wcd_usbss_sdam_registration, wcd_usbss_sysfs_init, wcd_usbss_remove, acquire_runtime_env, wcd_usbss_set_switch_settings_enable, wcd_usbss_sdam_handle_events_locked, regmap_bus_gather_write, wcd_usbss_page_write, wcd_usbss_dpdm_switch_update, wcd_usbss_audio_config, wcd_usbss_linearizer_rdac_cal_code_select, wcd_usbss_set_linearizer_sw_tap, wcd_usbss_switch_update, wcd_usbss_probe, wcd_usbss_sdam_notifier_handler, regmap_bus_read, wcd_usbss_get_sbu_switch_orientation, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [wcd_usbss_surge_kthread_fn, wcd_usbss_standby_store, wcd_usbss_i2c_write_device, wcd_usbss_usbc_analog_setup_switches, regmap_bus_gather_write, wcd_usbss_page_write, wcd_usbss_audio_config, wcd_usbss_probe, wcd_usbss_sdam_notifier_handler, wcd_usbss_surge_enable_store, wcd_usbss_display_port_switch_update, regmap_bus_read, wcd_usbss_get_sbu_switch_orientation, wcd_usbss_surge_period_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 00109028 size=1
// signature: undefined i2c_transfer(void)
// callers: [wcd_usbss_i2c_write_device, regmap_bus_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109030 size=1
// signature: undefined _printk(void)
// callers: [wcd_usbss_audio_config, wcd_usbss_switch_update, wcd_usbss_enable_surge_kthread, wcd_usbss_i2c_write_device, wcd_usbss_display_port_switch_update, wcd_usbss_usbc_analog_work_fn, wcd_usbss_sdam_handle_events_locked, wcd_usbss_page_write, regmap_bus_read, wcd_usbss_dpdm_switch_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00109038 size=1
// signature: undefined __kmalloc(void)
// callers: [wcd_usbss_i2c_write_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00109040 size=1
// signature: undefined kfree(void)
// callers: [wcd_usbss_sdam_notifier_handler, wcd_usbss_i2c_write_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00109048 size=1
// signature: undefined regmap_read(void)
// callers: [wcd_usbss_register_update, wcd_usbss_audio_config, wcd_usbss_surge_kthread_fn, wcd_usbss_probe, wcd_usbss_display_port_switch_update, wcd_usbss_get_sbu_switch_orientation]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00109050 size=1
// signature: undefined pm_stay_awake(void)
// callers: [wcd_usbss_usbc_event_changed, acquire_runtime_env]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00109058 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [wcd_usbss_remove, acquire_runtime_env, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00109060 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [acquire_runtime_env]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00109070 size=1
// signature: undefined usleep_range_state(void)
// callers: [wcd_usbss_standby_control_locked, wcd_usbss_switch_update, acquire_runtime_env, wcd_usbss_sdam_handle_events_locked]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00109078 size=1
// signature: undefined pm_relax(void)
// callers: [release_runtime_env, wcd_usbss_remove, wcd_usbss_usbc_analog_work_fn, acquire_runtime_env]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 00109080 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [release_runtime_env]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 00109088 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [release_runtime_env]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00109090 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [wcd_usbss_standby_control_locked, wcd_usbss_surge_kthread_fn, wcd_usbss_switch_update_defaults, wcd_usbss_set_switch_settings_enable, wcd_usbss_sdam_handle_events_locked, wcd_usbss_dpdm_switch_update, wcd_usbss_audio_config, wcd_usbss_pd_pu_enable, wcd_usbss_linearizer_rdac_cal_code_select, wcd_usbss_update_reg_init, wcd_usbss_set_linearizer_sw_tap, wcd_usbss_probe, wcd_usbss_switch_update, wcd_usbss_display_port_switch_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00109098 size=1
// signature: undefined regmap_write(void)
// callers: [wcd_usbss_register_update, wcd_usbss_audio_config, wcd_usbss_update_default_trim, wcd_usbss_switch_update, wcd_usbss_switch_update_defaults]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001090a0 size=1
// signature: undefined _dev_info(void)
// callers: [wcd_usbss_usbc_event_changed, wcd_usbss_switch_update, wcd_usbss_probe, wcd_usbss_sdam_notifier_handler, wcd_usbss_sdam_registration, wcd_usbss_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_i2c_device_by_node @ 001090a8 size=1
// signature: undefined of_find_i2c_device_by_node(void)
// callers: [wcd_usbss_unreg_notifier, wcd_usbss_reg_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_i2c_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 001090b0 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [wcd_usbss_reg_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 001090b8 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [wcd_usbss_surge_kthread_fn, wcd_usbss_usbc_analog_setup_switches]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 001090c0 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [wcd_usbss_unreg_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 001090c8 size=1
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
// i2c_del_driver @ 001090d0 size=1
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
// kthread_stop @ 001090d8 size=1
// signature: undefined kthread_stop(void)
// callers: [wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_ucsi_glink_notifier @ 001090e0 size=1
// signature: undefined unregister_ucsi_glink_notifier(void)
// callers: [wcd_usbss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_ucsi_glink_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001090e8 size=1
// signature: undefined cancel_work_sync(void)
// callers: [wcd_usbss_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001090f0 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 001090f8 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [wcd_usbss_probe, wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 00109100 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [wcd_usbss_probe, wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00109108 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [wcd_usbss_probe, wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00109110 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [wcd_usbss_probe, wcd_usbss_remove, wcd_usbss_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109118 size=1
// signature: undefined devm_kmalloc(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00109120 size=1
// signature: undefined __mutex_init(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 00109128 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 00109130 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00109138 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_bulk_get @ 00109140 size=1
// signature: undefined devm_regulator_bulk_get(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_bulk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_bulk_enable @ 00109148 size=1
// signature: undefined regulator_bulk_enable(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_bulk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regmap_qti_debugfs_register @ 00109150 size=1
// signature: undefined devm_regmap_qti_debugfs_register(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regmap_qti_debugfs_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_ucsi_glink_notifier @ 00109158 size=1
// signature: undefined register_ucsi_glink_notifier(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_ucsi_glink_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 00109160 size=1
// signature: undefined __init_rwsem(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00109168 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [wcd_usbss_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00109170 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [wcd_usbss_init_optional_reset_pins]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00109178 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [wcd_usbss_init_optional_reset_pins]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00109180 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [wcd_usbss_init_optional_reset_pins]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_nvmem_cell_get @ 00109188 size=1
// signature: undefined devm_nvmem_cell_get(void)
// callers: [wcd_usbss_sdam_registration]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_nvmem_cell_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00109190 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [wcd_usbss_sdam_registration]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00109198 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [wcd_usbss_sdam_registration]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001091a8 size=1
// signature: undefined queue_work_on(void)
// callers: [wcd_usbss_usbc_event_changed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 001091b8 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [wcd_usbss_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 001091c0 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [wcd_usbss_sysfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 001091c8 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [wcd_usbss_enable_surge_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 001091d0 size=1
// signature: undefined wake_up_process(void)
// callers: [wcd_usbss_enable_surge_kthread, wcd_usbss_surge_period_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_read @ 001091d8 size=1
// signature: undefined nvmem_cell_read(void)
// callers: [wcd_usbss_sdam_notifier_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nvmem_cell_write @ 001091e0 size=1
// signature: undefined nvmem_cell_write(void)
// callers: [wcd_usbss_sdam_notifier_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nvmem_cell_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 001091e8 size=1
// signature: undefined kstrtouint(void)
// callers: [wcd_usbss_surge_enable_store, wcd_usbss_standby_store, wcd_usbss_surge_period_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 001091f0 size=1
// signature: undefined kthread_should_stop(void)
// callers: [wcd_usbss_surge_kthread_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep_interruptible @ 001091f8 size=1
// signature: undefined msleep_interruptible(void)
// callers: [wcd_usbss_surge_kthread_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_mark_dirty @ 00109200 size=1
// signature: undefined regcache_mark_dirty(void)
// callers: [wcd_usbss_surge_kthread_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_mark_dirty(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regcache_sync @ 00109208 size=1
// signature: undefined regcache_sync(void)
// callers: [wcd_usbss_surge_kthread_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regcache_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00109210 size=1
// signature: undefined complete(void)
// callers: [wcd_usbss_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



