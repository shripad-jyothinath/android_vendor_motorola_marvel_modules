// Decompiled by Ghidra 12.2
// Program: qcom-scm.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_scm_set_warm_boot_addr_mc @ 00102a64 size=352
// signature: undefined qcom_scm_set_warm_boot_addr_mc(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_scm_set_warm_boot_addr_mc
               (long param_1,ulong param_2,ulong param_3,ulong param_4,ulong param_5)

{
  ulong uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_90;
  undefined8 local_88;
  long local_80;
  ulong uStack_78;
  ulong local_70;
  ulong uStack_68;
  undefined8 local_60;
  ulong uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = (param_1 << 8) >> 8;
  uVar1 = lVar2 + 0x8000000000;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_50 = 0;
  local_80 = _memstart_addr + uVar1;
  if (uVar1 >> 0x26 != 0) {
    local_80 = lVar2 - _kimage_voffset;
  }
  uStack_78 = param_2 & 0xffffffff;
  local_30 = 2;
  uStack_68 = param_4 & 0xffffffff;
  local_90 = 0x1100000001;
  local_70 = param_3 & 0xffffffff;
  uStack_58 = param_5 & 0xffffffff;
  local_60 = 0xffffffffffffffff;
  local_88 = 6;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_set_warm_boot_addr_mc"), iVar3 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar4 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar3 == 1) {
      uVar4 = scm_legacy_call(uVar4,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar4 = 0xffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_set_warm_boot_addr @ 00102bc8 size=572
// signature: undefined qcom_scm_set_warm_boot_addr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_scm_set_warm_boot_addr(long param_1,undefined8 param_2)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint uVar8;
  undefined8 local_b0;
  undefined8 local_a8;
  long local_a0;
  long local_98;
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
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_b0 = 0x100000001;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_a8 = 2;
  local_98 = 0;
  uStack_90 = 0;
  local_a0 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_set_warm_boot_addr"), iVar2 != 0)) {
    uVar7 = 0xffffffed;
  }
  else {
    uVar8 = 0;
    lVar5 = 0;
    uVar4 = (ulong)_nr_cpu_ids;
    while( true ) {
      uVar3 = _find_next_bit(param_2,uVar4,(long)(int)lVar5);
      uVar4 = (ulong)_nr_cpu_ids;
      if (uVar4 <= (uVar3 & 0xffffffff)) break;
      if ((uVar3 & 0xfffffffc) != 0) goto LAB_00102dfc;
      if (0x40 < ((uVar3 & 0xffffffff) << 4 | 8)) goto LAB_00102df8;
      uVar6 = uVar3 & 0xffffffff;
      if (*(long *)(qcom_scm_wb + uVar6 * 0x10 + 8) != param_1) {
        if (3 < uVar6) goto LAB_00102df8;
        uVar8 = *(uint *)(qcom_scm_wb + uVar6 * 0x10) | uVar8;
      }
      lVar5 = uVar3 + 1;
    }
    if (uVar8 != 0) {
      lVar5 = (param_1 << 8) >> 8;
      uVar4 = lVar5 + 0x8000000000;
      local_a0 = (long)(int)uVar8;
      local_98 = _memstart_addr + uVar4;
      if (uVar4 >> 0x26 != 0) {
        local_98 = lVar5 - _kimage_voffset;
      }
      uVar7 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        uVar7 = __scm_smc_call(uVar7,&local_b0,qcom_scm_convention,0,0);
        iVar2 = (int)uVar7;
      }
      else {
        if (iVar2 != 1) {
          _printk(&DAT_00111e2b,"qcom_scm_call");
          uVar7 = 0xffffffea;
          goto LAB_00102d8c;
        }
        uVar7 = scm_legacy_call(uVar7,&local_b0,0);
        iVar2 = (int)uVar7;
      }
      if (iVar2 != 0) goto LAB_00102d8c;
      lVar5 = 0;
      uVar4 = (ulong)_nr_cpu_ids;
      while( true ) {
        uVar3 = _find_next_bit(param_2,uVar4,(long)(int)lVar5);
        uVar4 = (ulong)_nr_cpu_ids;
        if (uVar4 <= (uVar3 & 0xffffffff)) break;
        if ((uVar3 & 0xfffffffc) != 0) {
LAB_00102dfc:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102e00);
          (*pcVar1)();
        }
        if (0x40 < ((uVar3 & 0xffffffff) << 4 | 8)) {
LAB_00102df8:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x102dfc);
          (*pcVar1)();
        }
        lVar5 = uVar3 + 1;
        *(long *)(qcom_scm_wb + (uVar3 & 0xffffffff) * 0x10 + 8) = param_1;
      }
    }
    uVar7 = 0;
  }
LAB_00102d8c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_set_cold_boot_addr @ 00102e08 size=536
// signature: undefined qcom_scm_set_cold_boot_addr(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_scm_set_cold_boot_addr(long param_1,long param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  long lVar8;
  uint uVar9;
  ulong uVar10;
  undefined8 local_c0;
  undefined8 local_b8;
  long local_b0;
  long local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  local_68 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_c0 = 0x100000001;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_b8 = 2;
  local_60 = 2;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b0 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar5 = _printk(&DAT_00110c5d,"qcom_scm_set_cold_boot_addr"), iVar5 != 0)) {
    uVar7 = 0xffffffed;
    goto LAB_00102fbc;
  }
  if ((param_2 != 0) &&
     (uVar10 = (ulong)_nr_cpu_ids, uVar6 = _find_first_bit(param_2,uVar10), uVar6 != uVar10)) {
    uVar9 = 0;
    lVar8 = 0;
    while (uVar6 = _find_next_bit(param_2,_nr_cpu_ids,(long)(int)lVar8), (uint)uVar6 < _nr_cpu_ids)
    {
      if ((uVar6 & 0xfffffffc) == 0) {
        if (3 < (uVar6 & 0xffffffff)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x10302c);
          (*pcVar4)();
        }
        uVar9 = *(uint *)(&DAT_00111fc8 + (uVar6 & 0xffffffff) * 4) | uVar9;
        lVar8 = uVar6 + 1;
      }
      else {
        puVar1 = (ulong *)(&__cpu_present_mask + (uVar6 >> 6 & 0x3ffffff) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & (1L << (uVar6 & 0x3f) ^ 0xffffffffffffffffU);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar8 = uVar6 + 1;
      }
    }
    lVar8 = (param_1 << 8) >> 8;
    uVar6 = lVar8 + 0x8000000000;
    local_b0 = (long)(int)uVar9;
    local_a8 = _memstart_addr + uVar6;
    if (uVar6 >> 0x26 != 0) {
      local_a8 = lVar8 - _kimage_voffset;
    }
    uVar7 = *__scm;
    iVar5 = __get_convention();
    if (iVar5 - 2U < 2) {
      uVar7 = __scm_smc_call(uVar7,&local_c0,qcom_scm_convention,0,1);
      goto LAB_00102fbc;
    }
    if (iVar5 == 1) {
      uVar7 = scm_legacy_call_atomic(uVar7,&local_c0,0);
      goto LAB_00102fbc;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
  }
  uVar7 = 0xffffffea;
LAB_00102fbc:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_cpu_power_down @ 00103034 size=276
// signature: undefined qcom_scm_cpu_power_down(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_cpu_power_down(uint param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x200000001;
  local_80 = (ulong)(param_1 & 3);
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm != (undefined8 *)0x0) ||
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_cpu_power_down"), iVar2 == 0)) {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
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
// qcom_scm_sec_wdog_deactivate @ 0010314c size=284
// signature: undefined qcom_scm_sec_wdog_deactivate(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_sec_wdog_deactivate(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_80 = 1;
  uStack_78 = 0;
  local_90 = 0x700000001;
  local_88 = 1;
  local_58 = 0;
  uStack_50 = 0;
  local_30 = 2;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_sec_wdog_deactivate"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_sec_wdog_trigger @ 0010326c size=304
// signature: undefined qcom_scm_sec_wdog_trigger(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_sec_wdog_trigger(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x800000001;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_88 = 1;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_sec_wdog_trigger"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_0010332c;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_0010332c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_disable_sdi @ 001033a0 size=312
// signature: undefined qcom_scm_disable_sdi(void)
// callers: [qcom_scm_shutdown]
//------------------------------------------------------------

void qcom_scm_disable_sdi(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x900000001;
  local_80 = 1;
  uStack_78 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_88 = 2;
  local_30 = 2;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_disable_sdi"), iVar2 != 0)) goto LAB_0010348c;
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar2 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
joined_r0x00103458:
    if (iVar2 == 0) goto LAB_0010348c;
  }
  else {
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call_atomic(uVar3,&local_90,0);
      goto joined_r0x00103458;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
    iVar2 = -0x16;
  }
  _printk(&DAT_001117bd,"qcom_scm_disable_sdi",iVar2);
LAB_0010348c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_set_remote_state @ 001034dc size=308
// signature: undefined qcom_scm_set_remote_state(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_set_remote_state(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_90 = 0xa00000001;
  local_80 = param_1 & 0xffffffff;
  local_88 = 2;
  local_30 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_set_remote_state"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001035a0;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001035a0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_spin_cpu @ 00103614 size=284
// signature: undefined qcom_scm_spin_cpu(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_spin_cpu(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0xd00000001;
  local_88 = 1;
  local_68 = 0;
  uStack_60 = 0;
  local_30 = 2;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_spin_cpu"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_set_download_mode @ 00103734 size=396
// signature: undefined qcom_scm_set_download_mode(void)
// callers: [qcom_scm_probe, qcom_scm_shutdown]
//------------------------------------------------------------

void qcom_scm_set_download_mode(uint param_1,long param_2)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (__scm == (undefined8 *)0x0) {
    iVar2 = _printk(&DAT_00110c5d,"qcom_scm_set_download_mode");
    if (iVar2 != 0) goto LAB_00103790;
    uVar4 = *__scm;
    if (param_2 == 0) goto LAB_00103774;
LAB_0010377c:
    iVar2 = qcom_scm_io_writel(param_2,param_1);
LAB_00103788:
    if (iVar2 == 0) goto LAB_00103790;
  }
  else {
    uVar4 = *__scm;
    if (param_2 != 0) goto LAB_0010377c;
LAB_00103774:
    param_2 = __scm[0x27];
    if (param_2 != 0) goto LAB_0010377c;
    uVar3 = __qcom_scm_is_call_available(uVar4,1,0x10);
    if ((uVar3 & 1) == 0) {
      _dev_err(uVar4,"No available mechanism for setting download mode\n");
      goto LAB_00103790;
    }
    local_90 = (ulong)param_1;
    local_48 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_a0 = 0x1000000001;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 2;
    local_40 = 2;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar2 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,0,1);
      goto LAB_00103788;
    }
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call_atomic(uVar4,&local_a0,0);
      goto LAB_00103788;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
  }
  _dev_err(uVar4,"failed to set download mode: %d\n");
LAB_00103790:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_io_writel @ 001038c4 size=284
// signature: undefined qcom_scm_io_writel(void)
// callers: [qcom_scm_set_download_mode]
//------------------------------------------------------------

void qcom_scm_io_writel(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_90 = 0x200000005;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_io_writel"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_is_call_available @ 001039e0 size=352
// signature: undefined __qcom_scm_is_call_available(void)
// callers: [qcom_scm_dcvs_core_available, qcom_scm_is_lmh_debug_get_type_available, qcom_scm_dcvs_ca_available, qcom_scm_ice_available, qcom_scm_lmh_fetch_data, qcom_scm_restore_sec_cfg_available, qcom_scm_kgsl_init_regs, qcom_scm_is_lmh_debug_set_available, qcom_scm_is_lmh_debug_read_buf_size_available, qcom_scm_is_lmh_debug_read_buf_available, qcom_scm_is_mode_switch_available, qcom_scm_hdcp_available, qcom_scm_kgsl_set_smmu_aperture_available, qcom_scm_pas_supported, qcom_scm_ocmem_lock_available, qcom_scm_set_download_mode, qcom_scm_is_secure_wdog_trigger_available, qcom_scm_lmh_dcvsh_available]
//------------------------------------------------------------

void __qcom_scm_is_call_available(undefined8 param_1,uint param_2,uint param_3)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  long local_b8 [17];
  
  lVar1 = sp_el0;
  local_b8[0x10] = *(long *)(lVar1 + 0x638);
  local_b8[0xe] = 0;
  local_b8[0xc] = 0;
  local_b8[0xd] = 0;
  local_b8[10] = 0;
  local_b8[0xb] = 0;
  local_b8[3] = 0x100000006;
  local_b8[8] = 0;
  local_b8[9] = 0;
  local_b8[6] = 0;
  local_b8[7] = 0;
  local_b8[0xf] = 2;
  local_b8[5] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[0] = 0;
  local_b8[4] = 1;
  iVar3 = __get_convention();
  if (iVar3 - 2U < 2) {
    uVar4 = param_3 & 0xff | (param_2 & 0xff) << 8 | 0x2000000;
  }
  else {
    if (iVar3 != 1) {
      _printk(&DAT_00111493,"__qcom_scm_is_call_available");
      bVar2 = false;
      goto LAB_00103ad8;
    }
    uVar4 = param_3 & 0x3ff | param_2 << 10;
  }
  local_b8[5] = (long)uVar4;
  iVar3 = __get_convention();
  if (iVar3 - 2U < 2) {
    iVar3 = __scm_smc_call(param_1,local_b8 + 3,qcom_scm_convention,local_b8,0);
  }
  else if (iVar3 == 1) {
    iVar3 = scm_legacy_call(param_1,local_b8 + 3,local_b8);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    iVar3 = -0x16;
  }
  bVar2 = iVar3 == 0 && local_b8[0] != 0;
LAB_00103ad8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_b8[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_download_mode @ 00103b44 size=192
// signature: undefined qcom_scm_get_download_mode(void)
// callers: []
//------------------------------------------------------------

int qcom_scm_get_download_mode(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (__scm == (undefined8 *)0x0) {
    iVar1 = _printk(&DAT_00110c5d,"qcom_scm_get_download_mode");
    if (iVar1 != 0) {
      return -0x13;
    }
    uVar2 = *__scm;
  }
  else {
    uVar2 = *__scm;
  }
  if ((param_2 == 0) && (param_2 = __scm[0x27], param_2 == 0)) {
    _dev_err(uVar2,"No available mechanism for getting download mode\n");
    iVar1 = -0x16;
  }
  else {
    iVar1 = qcom_scm_io_readl(param_2,param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  _dev_err(uVar2,"failed to get download mode: %d\n",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// qcom_scm_io_readl @ 00103c08 size=320
// signature: undefined qcom_scm_io_readl(void)
// callers: [qcom_scm_get_download_mode]
//------------------------------------------------------------

void qcom_scm_io_readl(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x100000005;
  local_68 = 0;
  uStack_60 = 0;
  uStack_78 = 0;
  local_88 = 1;
  local_70 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_30 = 2;
  local_a8 = 0;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_io_readl"), iVar2 != 0)) {
    iVar2 = -0x13;
    goto LAB_00103cd8;
  }
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar2 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,1);
joined_r0x00103cc4:
    if (-1 < iVar2) {
      *param_2 = (int)local_a8;
    }
  }
  else {
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call_atomic(uVar3,&local_90,&local_a8);
      goto joined_r0x00103cc4;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
    iVar2 = -0x16;
  }
  if (-1 < iVar2) {
    iVar2 = 0;
  }
LAB_00103cd8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_config_cpu_errata @ 00103d4c size=284
// signature: undefined qcom_scm_config_cpu_errata(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_config_cpu_errata(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1200000001;
  local_88 = 0xffffffff;
  local_68 = 0;
  uStack_60 = 0;
  local_30 = 2;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_config_cpu_errata"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_phy_update_scm_level_shifter @ 00103e6c size=328
// signature: undefined qcom_scm_phy_update_scm_level_shifter(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_phy_update_scm_level_shifter(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = 0x1b00000001;
  local_98 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_90 = 0;
  local_40 = 2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_phy_update_scm_level_shifter"), iVar2 != 0))
  goto LAB_00103f64;
  local_98 = CONCAT44(local_98._4_4_,2);
  local_88 = 0;
  uVar3 = *__scm;
  local_90 = param_1 & 0xffffffff;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar2 = __scm_smc_call(uVar3,&local_a0,qcom_scm_convention,0,0);
joined_r0x00103f30:
    if (iVar2 == 0) goto LAB_00103f64;
  }
  else {
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call(uVar3,&local_a0,0);
      goto joined_r0x00103f30;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call");
    iVar2 = -0x16;
  }
  _printk(&DAT_0011126f,"qcom_scm_phy_update_scm_level_shifter",iVar2);
LAB_00103f64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_pas_init_image @ 00103fb8 size=608
// signature: undefined qcom_scm_pas_init_image(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_pas_init_image(ulong param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_90 = param_1 & 0xffffffff;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = 0x100000002;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  local_98 = 0x82;
  local_80 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_40 = 2;
  local_b8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_pas_init_image"), iVar3 != 0)) {
    uVar5 = 0xffffffed;
    goto LAB_00104198;
  }
  uVar5 = qcom_scm_clk_enable();
  if ((int)uVar5 != 0) goto LAB_00104198;
  if (__scm[4] == 0) {
LAB_001040a4:
    uVar7 = *__scm;
    local_88 = param_2;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar7,&local_a0,qcom_scm_convention,&local_b8,0);
    }
    else if (iVar3 == 1) {
      uVar4 = scm_legacy_call(uVar7,&local_a0,&local_b8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar4 = 0xffffffea;
    }
    if ((__scm[4] != 0) && ((ulong)__scm[4] < 0xfffffffffffff001)) {
      mutex_lock(__scm + 0x20);
      puVar6 = __scm;
      iVar3 = *(int *)(__scm + 0x26);
      *(int *)(__scm + 0x26) = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        icc_set_bw(puVar6[4],0,0);
LAB_00104138:
        puVar6 = __scm;
      }
      mutex_unlock(puVar6 + 0x20);
    }
  }
  else if ((ulong)__scm[4] < 0xfffffffffffff001) {
    mutex_lock(__scm + 0x20);
    iVar3 = *(int *)(__scm + 0x26);
    if (iVar3 == 0) {
      uVar4 = icc_set_bw(__scm[4],0,0xffffffff);
      if (-1 < (int)uVar4) {
        iVar3 = *(int *)(__scm + 0x26);
        goto LAB_0010408c;
      }
      _dev_err(*__scm,"failed to set bandwidth request\n");
      goto LAB_00104138;
    }
    uVar4 = 0;
LAB_0010408c:
    puVar6 = __scm + 0x20;
    *(int *)(__scm + 0x26) = iVar3 + 1;
    mutex_unlock(puVar6);
    if (uVar4 == 0) goto LAB_001040a4;
  }
  else {
    uVar4 = 0xffffffea;
  }
  uVar7 = __scm[1];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[2];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[3];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar1 = (uint)local_b8;
  if (uVar4 != 0) {
    uVar1 = uVar4;
  }
  uVar5 = (ulong)uVar1;
LAB_00104198:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_clk_enable @ 00104218 size=224
// signature: undefined qcom_scm_clk_enable(void)
// callers: [qcom_scm_pas_auth_and_reset, qcom_scm_hdcp_req, qcom_scm_pas_init_image, qcom_scm_pas_mem_setup, qcom_scm_pas_shutdown, qcom_scm_hdcp_available]
//------------------------------------------------------------

int qcom_scm_clk_enable(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = *(undefined8 *)(__scm + 8);
  iVar1 = clk_prepare(uVar2);
  if (iVar1 == 0) {
    iVar1 = clk_enable(uVar2);
    if (iVar1 == 0) {
      uVar2 = *(undefined8 *)(__scm + 0x10);
      iVar1 = clk_prepare(uVar2);
      if (iVar1 == 0) {
        iVar1 = clk_enable(uVar2);
        if (iVar1 == 0) {
          uVar2 = *(undefined8 *)(__scm + 0x18);
          iVar1 = clk_prepare(uVar2);
          if (iVar1 == 0) {
            iVar1 = clk_enable(uVar2);
            if (iVar1 == 0) {
              return 0;
            }
            clk_unprepare(uVar2);
          }
          uVar2 = *(undefined8 *)(__scm + 0x10);
          clk_disable(uVar2);
        }
        clk_unprepare(uVar2);
      }
      uVar2 = *(undefined8 *)(__scm + 8);
      clk_disable(uVar2);
    }
    clk_unprepare(uVar2);
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_scm_pas_mem_setup @ 001042fc size=596
// signature: undefined qcom_scm_pas_mem_setup(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_pas_mem_setup(ulong param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_a0 = 0x200000002;
  local_90 = param_1 & 0xffffffff;
  local_48 = 0;
  local_98 = 3;
  uStack_78 = 0;
  local_40 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  uStack_88 = param_2;
  local_80 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_pas_mem_setup"), iVar3 != 0)) {
    uVar5 = 0xffffffed;
    goto LAB_001044d0;
  }
  uVar5 = qcom_scm_clk_enable();
  if ((int)uVar5 != 0) goto LAB_001044d0;
  if (__scm[4] == 0) {
LAB_001043e0:
    uVar7 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar7,&local_a0,qcom_scm_convention,&local_b8,0);
    }
    else if (iVar3 == 1) {
      uVar4 = scm_legacy_call(uVar7,&local_a0,&local_b8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar4 = 0xffffffea;
    }
    if ((__scm[4] != 0) && ((ulong)__scm[4] < 0xfffffffffffff001)) {
      mutex_lock(__scm + 0x20);
      puVar6 = __scm;
      iVar3 = *(int *)(__scm + 0x26);
      *(int *)(__scm + 0x26) = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        icc_set_bw(puVar6[4],0,0);
LAB_00104470:
        puVar6 = __scm;
      }
      mutex_unlock(puVar6 + 0x20);
    }
  }
  else if ((ulong)__scm[4] < 0xfffffffffffff001) {
    mutex_lock(__scm + 0x20);
    iVar3 = *(int *)(__scm + 0x26);
    if (iVar3 == 0) {
      uVar4 = icc_set_bw(__scm[4],0,0xffffffff);
      if (-1 < (int)uVar4) {
        iVar3 = *(int *)(__scm + 0x26);
        goto LAB_001043c8;
      }
      _dev_err(*__scm,"failed to set bandwidth request\n");
      goto LAB_00104470;
    }
    uVar4 = 0;
LAB_001043c8:
    puVar6 = __scm + 0x20;
    *(int *)(__scm + 0x26) = iVar3 + 1;
    mutex_unlock(puVar6);
    if (uVar4 == 0) goto LAB_001043e0;
  }
  else {
    uVar4 = 0xffffffea;
  }
  uVar7 = __scm[1];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[2];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[3];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar1 = (uint)local_b8;
  if (uVar4 != 0) {
    uVar1 = uVar4;
  }
  uVar5 = (ulong)uVar1;
LAB_001044d0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_pas_auth_and_reset @ 00104554 size=600
// signature: undefined qcom_scm_pas_auth_and_reset(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_pas_auth_and_reset(ulong param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_90 = param_1 & 0xffffffff;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = 0x500000002;
  local_78 = 0;
  uStack_70 = 0;
  uStack_88 = 0;
  local_98 = 1;
  local_80 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_40 = 2;
  local_b8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_pas_auth_and_reset"), iVar3 != 0)) {
    uVar5 = 0xffffffed;
    goto LAB_0010472c;
  }
  uVar5 = qcom_scm_clk_enable();
  if ((int)uVar5 != 0) goto LAB_0010472c;
  if (__scm[4] == 0) {
LAB_0010463c:
    uVar7 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar7,&local_a0,qcom_scm_convention,&local_b8,0);
    }
    else if (iVar3 == 1) {
      uVar4 = scm_legacy_call(uVar7,&local_a0,&local_b8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar4 = 0xffffffea;
    }
    if ((__scm[4] != 0) && ((ulong)__scm[4] < 0xfffffffffffff001)) {
      mutex_lock(__scm + 0x20);
      puVar6 = __scm;
      iVar3 = *(int *)(__scm + 0x26);
      *(int *)(__scm + 0x26) = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        icc_set_bw(puVar6[4],0,0);
LAB_001046cc:
        puVar6 = __scm;
      }
      mutex_unlock(puVar6 + 0x20);
    }
  }
  else if ((ulong)__scm[4] < 0xfffffffffffff001) {
    mutex_lock(__scm + 0x20);
    iVar3 = *(int *)(__scm + 0x26);
    if (iVar3 == 0) {
      uVar4 = icc_set_bw(__scm[4],0,0xffffffff);
      if (-1 < (int)uVar4) {
        iVar3 = *(int *)(__scm + 0x26);
        goto LAB_00104624;
      }
      _dev_err(*__scm,"failed to set bandwidth request\n");
      goto LAB_001046cc;
    }
    uVar4 = 0;
LAB_00104624:
    puVar6 = __scm + 0x20;
    *(int *)(__scm + 0x26) = iVar3 + 1;
    mutex_unlock(puVar6);
    if (uVar4 == 0) goto LAB_0010463c;
  }
  else {
    uVar4 = 0xffffffea;
  }
  uVar7 = __scm[1];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[2];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[3];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar1 = (uint)local_b8;
  if (uVar4 != 0) {
    uVar1 = uVar4;
  }
  uVar5 = (ulong)uVar1;
LAB_0010472c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown @ 001047b0 size=600
// signature: undefined qcom_scm_pas_shutdown(void)
// callers: [qcom_scm_pas_shutdown_retry]
//------------------------------------------------------------

void qcom_scm_pas_shutdown(ulong param_1)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 uVar7;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_90 = param_1 & 0xffffffff;
  local_48 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_a0 = 0x600000002;
  local_78 = 0;
  uStack_70 = 0;
  uStack_88 = 0;
  local_98 = 1;
  local_80 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_40 = 2;
  local_b8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_pas_shutdown"), iVar3 != 0)) {
    uVar5 = 0xffffffed;
    goto LAB_00104988;
  }
  uVar5 = qcom_scm_clk_enable();
  if ((int)uVar5 != 0) goto LAB_00104988;
  if (__scm[4] == 0) {
LAB_00104898:
    uVar7 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar7,&local_a0,qcom_scm_convention,&local_b8,0);
    }
    else if (iVar3 == 1) {
      uVar4 = scm_legacy_call(uVar7,&local_a0,&local_b8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar4 = 0xffffffea;
    }
    if ((__scm[4] != 0) && ((ulong)__scm[4] < 0xfffffffffffff001)) {
      mutex_lock(__scm + 0x20);
      puVar6 = __scm;
      iVar3 = *(int *)(__scm + 0x26);
      *(int *)(__scm + 0x26) = iVar3 + -1;
      if (iVar3 + -1 == 0) {
        icc_set_bw(puVar6[4],0,0);
LAB_00104928:
        puVar6 = __scm;
      }
      mutex_unlock(puVar6 + 0x20);
    }
  }
  else if ((ulong)__scm[4] < 0xfffffffffffff001) {
    mutex_lock(__scm + 0x20);
    iVar3 = *(int *)(__scm + 0x26);
    if (iVar3 == 0) {
      uVar4 = icc_set_bw(__scm[4],0,0xffffffff);
      if (-1 < (int)uVar4) {
        iVar3 = *(int *)(__scm + 0x26);
        goto LAB_00104880;
      }
      _dev_err(*__scm,"failed to set bandwidth request\n");
      goto LAB_00104928;
    }
    uVar4 = 0;
LAB_00104880:
    puVar6 = __scm + 0x20;
    *(int *)(__scm + 0x26) = iVar3 + 1;
    mutex_unlock(puVar6);
    if (uVar4 == 0) goto LAB_00104898;
  }
  else {
    uVar4 = 0xffffffea;
  }
  uVar7 = __scm[1];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[2];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar7 = __scm[3];
  clk_disable(uVar7);
  clk_unprepare(uVar7);
  uVar1 = (uint)local_b8;
  if (uVar4 != 0) {
    uVar1 = uVar4;
  }
  uVar5 = (ulong)uVar1;
LAB_00104988:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_pas_shutdown_retry @ 00104a0c size=188
// signature: undefined qcom_scm_pas_shutdown_retry(void)
// callers: []
//------------------------------------------------------------

int qcom_scm_pas_shutdown_retry(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = qcom_scm_pas_shutdown();
  if (iVar1 != 0) {
    _printk(&DAT_00110a38,"qcom_scm_pas_shutdown_retry",iVar1);
    if (pas_shutdown_retry_max == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      do {
        uVar2 = uVar2 + 1;
        msleep(pas_shutdown_retry_interval);
        iVar1 = qcom_scm_pas_shutdown(param_1);
        if (pas_shutdown_retry_max <= uVar2) break;
      } while (iVar1 != 0);
    }
    _printk(&DAT_00111bfe,"qcom_scm_pas_shutdown_retry",uVar2);
  }
  return iVar1;
}



//------------------------------------------------------------
// qcom_scm_pas_supported @ 00104acc size=336
// signature: undefined qcom_scm_pas_supported(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_pas_supported(ulong param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  long local_a8 [6];
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_a8[5] = param_1 & 0xffffffff;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_a8[3] = 0x700000002;
  local_68 = 0;
  uStack_60 = 0;
  uStack_78 = 0;
  local_a8[4] = 1;
  local_70 = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_30 = 2;
  local_a8[0] = 0;
  if (((__scm == (undefined8 *)0x0) &&
      (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_pas_supported"), iVar3 != 0)) ||
     (uVar4 = __qcom_scm_is_call_available(*__scm,2,7), (uVar4 & 1) == 0)) {
    bVar2 = false;
  }
  else {
    uVar5 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar5,local_a8 + 3,qcom_scm_convention,local_a8,0);
    }
    else if (iVar3 == 1) {
      iVar3 = scm_legacy_call(uVar5,local_a8 + 3,local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar3 = -0x16;
    }
    bVar2 = iVar3 == 0 && local_a8[0] != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(bVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_sec_dump_state @ 00104c20 size=308
// signature: undefined qcom_scm_get_sec_dump_state(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_get_sec_dump_state(undefined4 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1000000003;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_get_sec_dump_state"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_get_llcc_missrate @ 00104d58 size=232
// signature: undefined __qcom_scm_get_llcc_missrate(void)
// callers: []
//------------------------------------------------------------

void __qcom_scm_get_llcc_missrate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1400000006;
  uStack_60 = 0;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_2;
  uStack_78 = param_3;
  local_70 = param_4;
  local_68 = param_5;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(param_1,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_llcc_missrate @ 00104e44 size=252
// signature: undefined qcom_scm_get_llcc_missrate(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_get_llcc_missrate
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (__scm == (undefined8 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *__scm;
  }
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uStack_60 = 0;
  local_90 = 0x1400000006;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  local_68 = param_4;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(uVar3,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_get_llcc_occupancy @ 00104f44 size=232
// signature: undefined __qcom_scm_get_llcc_occupancy(void)
// callers: []
//------------------------------------------------------------

void __qcom_scm_get_llcc_occupancy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1300000006;
  uStack_60 = 0;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_2;
  uStack_78 = param_3;
  local_70 = param_4;
  local_68 = param_5;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(param_1,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_llcc_occupancy @ 00105030 size=252
// signature: undefined qcom_scm_get_llcc_occupancy(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_get_llcc_occupancy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (__scm == (undefined8 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *__scm;
  }
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uStack_60 = 0;
  local_90 = 0x1300000006;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  local_68 = param_4;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(uVar3,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_memory_lat_profiler @ 00105130 size=232
// signature: undefined __qcom_scm_memory_lat_profiler(void)
// callers: []
//------------------------------------------------------------

void __qcom_scm_memory_lat_profiler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1500000006;
  uStack_60 = 0;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_2;
  uStack_78 = param_3;
  local_70 = param_4;
  local_68 = param_5;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(param_1,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_memory_lat_profiler @ 0010521c size=252
// signature: undefined qcom_scm_memory_lat_profiler(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_memory_lat_profiler
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (__scm == (undefined8 *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = *__scm;
  }
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  uStack_60 = 0;
  local_90 = 0x1500000006;
  local_88 = 0x224;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  local_68 = param_4;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(uVar3,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_assign_dump_table_region @ 0010531c size=288
// signature: undefined qcom_scm_assign_dump_table_region(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_assign_dump_table_region(ulong param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1300000003;
  local_80 = param_1 & 1;
  local_38 = 0;
  local_88 = 3;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_assign_dump_table_region"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_tz_blsp_modify_owner @ 00105440 size=316
// signature: undefined qcom_scm_tz_blsp_modify_owner(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_tz_blsp_modify_owner(int param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_90 = 0x300000004;
  lStack_78 = (long)param_1;
  local_88 = 2;
  local_30 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_tz_blsp_modify_owner"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_io_reset @ 00105580 size=280
// signature: undefined qcom_scm_io_reset(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_io_reset(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x300000005;
  local_68 = 0;
  uStack_60 = 0;
  local_88 = 2;
  local_30 = 2;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_io_reset"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_is_secure_wdog_trigger_available @ 0010569c size=104
// signature: undefined qcom_scm_is_secure_wdog_trigger_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_secure_wdog_trigger_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_secure_wdog_trigger_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,1,8);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_is_mode_switch_available @ 00105708 size=104
// signature: undefined qcom_scm_is_mode_switch_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_mode_switch_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_mode_switch_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,1,0xf);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// __qcom_scm_get_feat_version @ 00105774 size=316
// signature: undefined __qcom_scm_get_feat_version(void)
// callers: [qcom_scm_get_tz_feat_id_version, qcom_scm_get_jtag_etm_feat_id, qcom_scm_get_tz_log_feat_id, qcom_scm_get_feat_version_cp]
//------------------------------------------------------------

void __qcom_scm_get_feat_version(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x300000006;
  local_68 = 0;
  uStack_60 = 0;
  uStack_78 = 0;
  local_88 = 1;
  local_70 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_30 = 2;
  local_a8 = 0;
  local_80 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"__qcom_scm_get_feat_version"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_jtag_etm_feat_id @ 001058b4 size=92
// signature: undefined qcom_scm_get_jtag_etm_feat_id(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_get_jtag_etm_feat_id(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = param_1;
  if ((__scm == 0) &&
     (uVar1 = _printk(&DAT_00110c5d,"qcom_scm_get_jtag_etm_feat_id"), (int)uVar1 != 0)) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = __qcom_scm_get_feat_version(uVar1,8,param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_scm_halt_spmi_pmic_arbiter @ 00105914 size=272
// signature: undefined qcom_scm_halt_spmi_pmic_arbiter(void)
// callers: [qcom_scm_shutdown]
//------------------------------------------------------------

void qcom_scm_halt_spmi_pmic_arbiter(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x100000009;
  local_88 = 1;
  local_68 = 0;
  uStack_60 = 0;
  local_30 = 2;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if ((__scm != (undefined8 *)0x0) ||
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_halt_spmi_pmic_arbiter"), iVar2 == 0)) {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
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
// qcom_scm_deassert_ps_hold @ 00105a28 size=312
// signature: undefined qcom_scm_deassert_ps_hold(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_deassert_ps_hold(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x200000009;
  local_88 = 1;
  local_68 = 0;
  uStack_60 = 0;
  local_30 = 2;
  local_78 = 0;
  uStack_70 = 0;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_deassert_ps_hold"), iVar2 != 0)) goto LAB_00105b14;
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar2 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
joined_r0x00105ae0:
    if (iVar2 == 0) goto LAB_00105b14;
  }
  else {
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call_atomic(uVar3,&local_90,0);
      goto joined_r0x00105ae0;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
    iVar2 = -0x16;
  }
  _printk(&DAT_00110762,"qcom_scm_deassert_ps_hold",iVar2);
LAB_00105b14:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_paravirt_smmu_attach @ 00105b64 size=368
// signature: undefined qcom_scm_paravirt_smmu_attach(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_paravirt_smmu_attach
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_paravirt_smmu_attach"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    local_68 = 0;
    uStack_70 = 0;
    local_c0 = 0x600000015;
    local_98 = 0;
    local_b0 = 0;
    local_60 = 2;
    local_d0 = 0;
    uStack_c8 = 0;
    local_d8 = 0;
    local_b8 = 0x22200a;
    local_a8 = param_1;
    local_a0 = param_2;
    local_90 = param_3;
    local_88 = param_4;
    local_80 = param_5;
    local_78 = param_6;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_c0,qcom_scm_convention,&local_d8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00105c58;
      }
      iVar3 = scm_legacy_call(uVar4,&local_c0,&local_d8);
    }
    iVar2 = (int)local_d8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00105c58:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_paravirt_tlb_inv @ 00105cd8 size=340
// signature: undefined qcom_scm_paravirt_tlb_inv(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_paravirt_tlb_inv(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_paravirt_tlb_inv"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    local_48 = 0;
    local_a0 = 0x600000015;
    uStack_50 = 0;
    local_40 = 2;
    local_90 = 2;
    local_b0 = 0;
    uStack_a8 = 0;
    local_b8 = 0;
    local_60 = 0;
    local_58 = 0;
    local_70 = 0;
    local_68 = 0;
    local_78 = 0;
    local_98 = 0x22200a;
    local_88 = param_2;
    local_80 = param_1;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,&local_b8,1);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
        iVar2 = -0x16;
        goto LAB_00105db8;
      }
      iVar3 = scm_legacy_call_atomic(uVar4,&local_a0,&local_b8);
    }
    iVar2 = (int)local_b8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00105db8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_paravirt_smmu_detach @ 00105e30 size=332
// signature: undefined qcom_scm_paravirt_smmu_detach(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_paravirt_smmu_detach(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_paravirt_smmu_detach"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    local_38 = 0;
    local_90 = 0x600000015;
    uStack_40 = 0;
    local_30 = 2;
    local_a0 = 0;
    uStack_98 = 0;
    local_80 = 1;
    local_a8 = 0;
    local_50 = 0;
    local_48 = 0;
    local_60 = 0;
    local_58 = 0;
    local_70 = 0;
    local_68 = 0;
    local_88 = 0x22200a;
    local_78 = param_1;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00105f0c;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00105f0c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_mmu_sync @ 00105f80 size=316
// signature: undefined qcom_scm_mmu_sync(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_mmu_sync(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x800000009;
  local_80 = param_1 & 1;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_mmu_sync"), iVar2 != 0)) goto LAB_00106070;
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar2 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
joined_r0x0010603c:
    if (iVar2 == 0) goto LAB_00106070;
  }
  else {
    if (iVar2 == 1) {
      iVar2 = scm_legacy_call_atomic(uVar3,&local_90,0);
      goto joined_r0x0010603c;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
    iVar2 = -0x16;
  }
  _printk(&DAT_00111c6a,"qcom_scm_mmu_sync",iVar2);
LAB_00106070:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_restore_sec_cfg_available @ 001060c0 size=104
// signature: undefined qcom_scm_restore_sec_cfg_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_restore_sec_cfg_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_restore_sec_cfg_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0xc,2);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_restore_sec_cfg @ 0010612c size=308
// signature: undefined qcom_scm_restore_sec_cfg(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_restore_sec_cfg(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_90 = 0x20000000c;
  local_80 = param_1 & 0xffffffff;
  local_88 = 2;
  local_30 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_restore_sec_cfg"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001061f0;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001061f0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_iommu_secure_ptbl_size @ 00106264 size=332
// signature: undefined qcom_scm_iommu_secure_ptbl_size(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_iommu_secure_ptbl_size(ulong param_1,undefined8 *param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x30000000c;
  local_68 = 0;
  uStack_60 = 0;
  uStack_78 = 0;
  local_88 = 1;
  local_70 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_30 = 2;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_iommu_secure_ptbl_size"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar3 = -0x16;
    }
    if (param_2 != (undefined8 *)0x0) {
      *param_2 = local_a8;
    }
    iVar2 = (int)local_a0;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_iommu_secure_ptbl_init @ 001063b4 size=300
// signature: undefined qcom_scm_iommu_secure_ptbl_init(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_iommu_secure_ptbl_init(undefined8 param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  ulong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x40000000c;
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_88 = 0x23;
  local_70 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_iommu_secure_ptbl_init"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,0,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00106470;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,0);
    }
    iVar2 = 0;
    if (iVar3 != -1) {
      iVar2 = iVar3;
    }
  }
LAB_00106470:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_mem_protect_video_var @ 001064e4 size=320
// signature: undefined qcom_scm_mem_protect_video_var(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_mem_protect_video_var(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  ulong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_68 = param_4 & 0xffffffff;
  uStack_78 = param_2 & 0xffffffff;
  local_90 = 0x80000000c;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 4;
  local_70 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_mem_protect_video_var"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001065b4;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001065b4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_mem_protect_region_id @ 00106628 size=280
// signature: undefined qcom_scm_mem_protect_region_id(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_mem_protect_region_id(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_90 = 0x100000000c;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_mem_protect_region_id"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_mem_protect_lock_id2_flat @ 00106744 size=288
// signature: undefined qcom_scm_mem_protect_lock_id2_flat(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_mem_protect_lock_id2_flat
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  long local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x110000000c;
  local_38 = 0;
  local_88 = 0x26;
  local_60 = (long)param_5;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  uStack_68 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_mem_protect_lock_id2_flat"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_iommu_secure_map @ 00106868 size=308
// signature: undefined qcom_scm_iommu_secure_map(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_iommu_secure_map
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               int param_5,undefined8 param_6,undefined8 param_7)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  long local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x120000000c;
  local_38 = 0;
  local_88 = 0x28;
  local_60 = (long)param_5;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  uStack_68 = param_4;
  uStack_58 = param_6;
  local_50 = param_7;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_iommu_secure_map"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_0010692c;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_0010692c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_iommu_secure_unmap @ 001069a0 size=312
// signature: undefined qcom_scm_iommu_secure_unmap(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_iommu_secure_unmap
               (undefined8 param_1,int param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x130000000c;
  lStack_78 = (long)param_2;
  local_38 = 0;
  local_88 = 5;
  local_60 = 1;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  local_70 = param_3;
  uStack_68 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_iommu_secure_unmap"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00106a68;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00106a68:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_assign_mem @ 00106adc size=544
// signature: undefined qcom_scm_assign_mem(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_assign_mem(undefined8 param_1,undefined8 param_2,ulong *param_3,uint *param_4,
                        uint param_5)

{
  long lVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  uint *puVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  long local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar14 = (ulong)param_5;
  local_70 = 0;
  uVar15 = *param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar5 = _printk(&DAT_00110c5d,"qcom_scm_assign_mem"), iVar5 != 0)) {
    uVar8 = 0xffffffed;
  }
  else {
    lVar6 = __sw_hweight64(uVar15);
    lVar12 = uVar14 * 0x18;
    uVar13 = lVar6 * 4 + 0x3fU & 0xffffffffffffffc0;
    lVar1 = uVar13 + 0x40 + (lVar12 + 0x3fU & 0x3fffffffc0);
    lVar7 = dma_alloc_attrs(*__scm,lVar1,&local_70,0xcc0,0);
    if (lVar7 == 0) {
      uVar8 = 0xfffffff4;
    }
    else {
      uVar10 = 0;
      iVar5 = 0;
      do {
        if ((uVar15 >> (uVar10 & 0x3f) & 1) != 0) {
          *(int *)(lVar7 + (long)iVar5 * 4) = (int)uVar10;
          iVar5 = iVar5 + 1;
        }
        uVar10 = uVar10 + 1;
      } while (uVar10 != 0x40);
      puVar2 = (undefined8 *)(lVar7 + uVar13);
      *puVar2 = param_1;
      puVar2[1] = param_2;
      if (param_5 == 0) {
        uVar14 = 0;
      }
      else {
        uVar9 = 0;
        puVar11 = (uint *)(puVar2 + 8);
        do {
          uVar4 = (int)uVar14 - 1;
          uVar14 = (ulong)uVar4;
          *puVar11 = *param_4;
          uVar3 = param_4[1];
          puVar11[2] = 0;
          puVar11[3] = 0;
          puVar11[4] = 0;
          puVar11[1] = uVar3;
          puVar11 = puVar11 + 6;
          uVar9 = uVar9 | (uint)(1L << ((ulong)*param_4 & 0x3f));
          param_4 = param_4 + 2;
        } while (uVar4 != 0);
        uVar14 = (ulong)(int)uVar9;
      }
      iVar5 = __qcom_scm_assign_mem
                        (*__scm,local_70 + uVar13,0x10,local_70,lVar6 * 4,uVar13 + 0x40 + local_70,
                         lVar12);
      dma_free_attrs(*__scm,lVar1,lVar7,local_70,0);
      if (iVar5 == 0) {
        uVar8 = 0;
        *param_3 = uVar14;
      }
      else {
        _dev_err(*__scm,"Assign memory protection call failed %d\n",iVar5);
        uVar8 = 0xffffffea;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar8);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_assign_mem @ 00106cfc size=252
// signature: undefined __qcom_scm_assign_mem(void)
// callers: [qcom_scm_assign_mem_regions, qcom_scm_assign_mem]
//------------------------------------------------------------

void __qcom_scm_assign_mem
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 param_5,undefined8 param_6,undefined8 param_7)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x160000000c;
  local_38 = 0;
  local_88 = 0x1117;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_2;
  uStack_78 = param_3;
  local_70 = param_4;
  uStack_68 = param_5;
  local_60 = param_6;
  uStack_58 = param_7;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,&local_a8,0);
  }
  else {
    if (iVar2 != 1) {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar2 = -0x16;
      goto LAB_00106db0;
    }
    iVar3 = scm_legacy_call(param_1,&local_90,&local_a8);
  }
  iVar2 = (int)local_a8;
  if (iVar3 != 0) {
    iVar2 = iVar3;
  }
LAB_00106db0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_assign_mem_regions @ 00106dfc size=256
// signature: undefined qcom_scm_assign_mem_regions(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
qcom_scm_assign_mem_regions
          (long param_1,undefined8 param_2,long param_3,undefined8 param_4,long param_5,
          undefined8 param_6)

{
  ulong uVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  undefined8 uVar8;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar7 = _printk(&DAT_00110c5d,"qcom_scm_assign_mem_regions"), iVar7 != 0)) {
    uVar8 = 0xffffffed;
  }
  else {
    lVar4 = (param_1 << 8) >> 8;
    uVar1 = lVar4 + 0x8000000000;
    lVar5 = (param_3 << 8) >> 8;
    uVar2 = lVar5 + 0x8000000000;
    lVar3 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      lVar3 = lVar4 - _kimage_voffset;
    }
    lVar6 = (param_5 << 8) >> 8;
    lVar4 = _memstart_addr + uVar2;
    if (uVar2 >> 0x26 != 0) {
      lVar4 = lVar5 - _kimage_voffset;
    }
    uVar1 = lVar6 + 0x8000000000;
    lVar5 = _memstart_addr + uVar1;
    if (uVar1 >> 0x26 != 0) {
      lVar5 = lVar6 - _kimage_voffset;
    }
    uVar8 = __qcom_scm_assign_mem(*__scm,lVar3,param_2,lVar4,param_4,lVar5,param_6);
  }
  return uVar8;
}



//------------------------------------------------------------
// qcom_scm_mem_protect_sd_ctrl @ 00106f00 size=312
// signature: undefined qcom_scm_mem_protect_sd_ctrl(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_mem_protect_sd_ctrl(ulong param_1,undefined8 param_2,undefined8 param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x180000000c;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 0x84;
  uStack_68 = param_4 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_mem_protect_sd_ctrl"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00106fc8;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00106fc8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_kgsl_set_smmu_aperture_available @ 0010703c size=104
// signature: undefined qcom_scm_kgsl_set_smmu_aperture_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_kgsl_set_smmu_aperture_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_kgsl_set_smmu_aperture_available"), iVar2 != 0)) {
    uVar1 = 1;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0xc,0x1b);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_kgsl_set_smmu_aperture @ 001070a8 size=296
// signature: undefined qcom_scm_kgsl_set_smmu_aperture(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_kgsl_set_smmu_aperture(uint param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1b0000000c;
  local_80 = (ulong)(param_1 & 0xff | 0xffff0000);
  local_38 = 0;
  local_88 = 4;
  local_60 = 0;
  uStack_58 = 0;
  uStack_78 = 0xffffffff;
  local_70 = 0xffffffff;
  uStack_68 = 0xffffffff;
  local_50 = 0;
  uStack_48 = 0;
  local_30 = 2;
  local_40 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_kgsl_set_smmu_aperture"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_kgsl_set_smmu_lpac_aperture @ 001071d4 size=296
// signature: undefined qcom_scm_kgsl_set_smmu_lpac_aperture(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_kgsl_set_smmu_lpac_aperture(uint param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1b0000000c;
  local_80 = (ulong)(param_1 & 0xff | 0xffff0100);
  local_38 = 0;
  local_88 = 4;
  local_60 = 0;
  uStack_58 = 0;
  uStack_78 = 0xffffffff;
  local_70 = 0xffffffff;
  uStack_68 = 0xffffffff;
  local_50 = 0;
  uStack_48 = 0;
  local_30 = 2;
  local_40 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_kgsl_set_smmu_lpac_aperture"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_kgsl_init_regs @ 00107300 size=320
// signature: undefined qcom_scm_kgsl_init_regs(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_kgsl_init_regs(ulong param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x100000028;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_kgsl_init_regs"), iVar2 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar3 = __qcom_scm_is_call_available(*__scm,0x28,1);
    if ((uVar3 & 1) == 0) {
      uVar4 = 0xffffffa1;
    }
    else {
      uVar4 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        uVar4 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,0,0);
      }
      else if (iVar2 == 1) {
        uVar4 = scm_legacy_call(uVar4,&local_90,0);
      }
      else {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar4 = 0xffffffea;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_kgsl_dcvs_tuning @ 00107444 size=252
// signature: undefined qcom_scm_kgsl_dcvs_tuning(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_kgsl_dcvs_tuning(ulong param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 0xffffffff;
  local_90 = 0xe0000000d;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 3;
  local_70 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
  }
  else if (iVar2 == 1) {
    uVar3 = scm_legacy_call(uVar3,&local_90,0);
  }
  else {
    _printk(&DAT_00111e2b,"qcom_scm_call");
    uVar3 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_enable_shm_bridge @ 00107544 size=296
// signature: undefined qcom_scm_enable_shm_bridge(void)
// callers: [qtee_shmbridge_enable]
//------------------------------------------------------------

void qcom_scm_enable_shm_bridge(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x1c0000000c;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_enable_shm_bridge"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001075fc;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001075fc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_delete_shm_bridge @ 00107670 size=284
// signature: undefined qcom_scm_delete_shm_bridge(void)
// callers: [qtee_shmbridge_deregister]
//------------------------------------------------------------

void qcom_scm_delete_shm_bridge(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1d0000000c;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_delete_shm_bridge"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_create_shm_bridge @ 00107790 size=328
// signature: undefined qcom_scm_create_shm_bridge(void)
// callers: [qtee_shmbridge_register]
//------------------------------------------------------------

void qcom_scm_create_shm_bridge
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined8 *param_5)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1e0000000c;
  local_38 = 0;
  local_88 = 4;
  local_30 = 2;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  uStack_68 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_create_shm_bridge"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar3 = -0x16;
    }
    if (param_5 != (undefined8 *)0x0) {
      *param_5 = local_a0;
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_smmu_prepare_atos_id @ 001078dc size=292
// signature: undefined qcom_scm_smmu_prepare_atos_id(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_smmu_prepare_atos_id(undefined8 param_1,int param_2,int param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long lStack_78;
  long local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x210000000c;
  lStack_78 = (long)param_2;
  local_38 = 0;
  local_88 = 3;
  local_70 = (long)param_3;
  local_60 = 0;
  uStack_58 = 0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_smmu_prepare_atos_id"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_mdf_assign_memory_to_subsys @ 00107a04 size=304
// signature: undefined qcom_mdf_assign_memory_to_subsys(void)
// callers: []
//------------------------------------------------------------

void qcom_mdf_assign_memory_to_subsys
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x250000000c;
  local_38 = 0;
  local_88 = 4;
  local_30 = 2;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  uStack_68 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_mdf_assign_memory_to_subsys"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00107ac4;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00107ac4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_core_available @ 00107b38 size=148
// signature: undefined qcom_scm_dcvs_core_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_dcvs_core_available(void)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if ((__scm != (undefined8 *)0x0) ||
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_core_available"), iVar2 == 0)) {
    uVar4 = *__scm;
    uVar3 = __qcom_scm_is_call_available(uVar4,0xd,9);
    if (((uVar3 & 1) != 0) && (uVar3 = __qcom_scm_is_call_available(uVar4,0xd,8), (uVar3 & 1) != 0))
    {
      uVar1 = __qcom_scm_is_call_available(uVar4,0xd,7);
      goto LAB_00107bb0;
    }
  }
  uVar1 = 0;
LAB_00107bb0:
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_dcvs_ca_available @ 00107bd0 size=128
// signature: undefined qcom_scm_dcvs_ca_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_dcvs_ca_available(void)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  if ((__scm != (undefined8 *)0x0) ||
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_ca_available"), iVar2 == 0)) {
    uVar4 = *__scm;
    uVar3 = __qcom_scm_is_call_available(uVar4,0xd,0xc);
    if ((uVar3 & 1) != 0) {
      uVar1 = __qcom_scm_is_call_available(uVar4,0xd,0xd);
      goto LAB_00107c34;
    }
  }
  uVar1 = 0;
LAB_00107c34:
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_dcvs_reset @ 00107c54 size=276
// signature: undefined qcom_scm_dcvs_reset(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_reset(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x70000000d;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_reset"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_init_v2 @ 00107d6c size=312
// signature: undefined qcom_scm_dcvs_init_v2(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_init_v2(undefined8 param_1,undefined8 param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xb0000000d;
  local_38 = 0;
  local_88 = 0x22;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 2;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_init_v2"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
      iVar2 = (int)uVar3;
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar3 = 0xffffffea;
        goto LAB_00107e34;
      }
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
      iVar2 = (int)uVar3;
    }
    if (-1 < iVar2) {
      *param_3 = (int)local_a8;
    }
  }
LAB_00107e34:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_init_ca_v2 @ 00107ea8 size=284
// signature: undefined qcom_scm_dcvs_init_ca_v2(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_init_ca_v2(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xc0000000d;
  local_38 = 0;
  local_88 = 0x22;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_init_ca_v2"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_update @ 00107fc8 size=308
// signature: undefined qcom_scm_dcvs_update(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_update(int param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  long local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x80000000d;
  local_80 = (long)param_1;
  local_38 = 0;
  local_88 = 3;
  uStack_68 = 0;
  local_30 = 2;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_update"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,1);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
        iVar2 = -0x16;
        goto LAB_0010808c;
      }
      iVar3 = scm_legacy_call_atomic(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_0010808c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_update_v2 @ 00108100 size=308
// signature: undefined qcom_scm_dcvs_update_v2(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_update_v2(int param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  long local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xa0000000d;
  local_80 = (long)param_1;
  local_38 = 0;
  local_88 = 3;
  uStack_68 = 0;
  local_30 = 2;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_update_v2"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001081c4;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001081c4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_dcvs_update_ca_v2 @ 00108238 size=312
// signature: undefined qcom_scm_dcvs_update_ca_v2(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_dcvs_update_ca_v2(int param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  long local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long lStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xd0000000d;
  local_80 = (long)param_1;
  local_38 = 0;
  local_88 = 4;
  lStack_68 = (long)param_4;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_dcvs_update_ca_v2"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_00108300;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_00108300:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_feat_version_cp @ 00108374 size=92
// signature: undefined qcom_scm_get_feat_version_cp(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_get_feat_version_cp(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = param_1;
  if ((__scm == 0) &&
     (uVar1 = _printk(&DAT_00110c5d,"qcom_scm_get_feat_version_cp"), (int)uVar1 != 0)) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = __qcom_scm_get_feat_version(uVar1,0xc,param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_scm_ocmem_lock_available @ 001083d4 size=104
// signature: undefined qcom_scm_ocmem_lock_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_ocmem_lock_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ocmem_lock_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0xf,1);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_ocmem_lock @ 00108440 size=296
// signature: undefined qcom_scm_ocmem_lock(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_ocmem_lock(ulong param_1,ulong param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  ulong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  undefined3 uStack_2b;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_68 = param_4 & 0xffffffff;
  uStack_78 = param_2 & 0xffffffff;
  local_90 = 0x10000000f;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  uStack_2b = 0;
  local_88 = 4;
  local_70 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ocmem_lock"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_ocmem_unlock @ 0010856c size=292
// signature: undefined qcom_scm_ocmem_unlock(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_ocmem_unlock(ulong param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined5 local_38;
  undefined3 uStack_33;
  undefined5 uStack_30;
  undefined3 uStack_2b;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 0xffffffff;
  local_90 = 0x20000000f;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  uStack_2b = 0;
  local_88 = 3;
  local_70 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  uStack_33 = 0;
  uStack_30 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ocmem_unlock"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_ice_available @ 00108694 size=128
// signature: undefined qcom_scm_ice_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_ice_available(void)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  
  if (((__scm == (undefined8 *)0x0) &&
      (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ice_available"), iVar2 != 0)) ||
     (uVar3 = __qcom_scm_is_call_available(*__scm,0x10,3), (uVar3 & 1) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x10,4);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_ice_invalidate_key @ 00108718 size=288
// signature: undefined qcom_scm_ice_invalidate_key(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_ice_invalidate_key(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x300000010;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ice_invalidate_key"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_ice_set_key @ 0010883c size=432
// signature: undefined qcom_scm_ice_set_key(void)
// callers: []
//------------------------------------------------------------

undefined4
qcom_scm_ice_set_key(ulong param_1,void *param_2,ulong param_3,ulong param_4,ulong param_5)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  void *__dest;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  param_3 = param_3 & 0xffffffff;
  local_a0 = 0x400000010;
  local_90 = param_1 & 0xffffffff;
  local_48 = 0;
  local_98 = 0x85;
  uStack_78 = param_4 & 0xffffffff;
  local_88 = 0;
  local_70 = param_5 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  uStack_68 = 0;
  local_50 = 0;
  local_a8 = 0;
  local_40 = 2;
  local_80 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ice_set_key"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    __dest = (void *)dma_alloc_attrs(*__scm,param_3,&local_a8,0xcc0,0);
    if (__dest == (void *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      memcpy(__dest,param_2,param_3);
      local_88 = local_a8;
      uVar4 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        uVar3 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,0,0);
      }
      else if (iVar2 == 1) {
        uVar3 = scm_legacy_call(uVar4,&local_a0,0);
      }
      else {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar3 = 0xffffffea;
      }
      memset(__dest,0,param_3);
      dma_free_attrs(*__scm,param_3,__dest,local_a8,0);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_scm_config_set_ice_key @ 001089f0 size=300
// signature: undefined qcom_scm_config_set_ice_key(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_config_set_ice_key
               (ulong param_1,undefined8 param_2,undefined8 param_3,ulong param_4,ulong param_5,
               uint param_6)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulong uStack_68;
  ulong local_60;
  ulong uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_58 = (ulong)param_6;
  local_90 = 0x500000010;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 0x86;
  uStack_68 = param_4 & 0xffffffff;
  local_60 = param_5 & 0xffffffff;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_config_set_ice_key"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_hibernate_exit @ 00108b20 size=216
// signature: undefined qcom_scm_hibernate_exit(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_hibernate_exit(void)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0xb00000010;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  uVar4 = *__scm;
  iVar3 = __get_convention();
  if (iVar3 - 2U < 2) {
    uVar4 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,0,2);
  }
  else {
    if (iVar3 == 1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x108bf8);
      (*pcVar2)();
    }
    _printk(&DAT_00111e2b,"qcom_scm_call_noretry");
    uVar4 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_clear_ice_key @ 00108bfc size=288
// signature: undefined qcom_scm_clear_ice_key(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_clear_ice_key(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_80 = param_1 & 0xffffffff;
  local_90 = 0x600000010;
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_clear_ice_key"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_derive_raw_secret @ 00108d20 size=324
// signature: undefined qcom_scm_derive_raw_secret(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_derive_raw_secret
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_b0 = 0x700000010;
  local_a8 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_50 = 2;
  local_a0 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_derive_raw_secret"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    local_a8 = CONCAT44(local_a8._4_4_,0x224);
    uVar3 = *__scm;
    local_a0 = param_1;
    local_98 = param_2;
    local_90 = param_3;
    local_88 = param_4;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_b0,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_b0,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_hdcp_available @ 00108e68 size=196
// signature: undefined qcom_scm_hdcp_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_hdcp_available(void)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  if (((__scm == (undefined8 *)0x0) &&
      (iVar1 = _printk(&DAT_00110c5d,"qcom_scm_hdcp_available"), iVar1 != 0)) ||
     (iVar1 = qcom_scm_clk_enable(), iVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = __qcom_scm_is_call_available(*__scm,0x11,1);
    uVar3 = __scm[1];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
    uVar3 = __scm[2];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
    uVar3 = __scm[3];
    clk_disable(uVar3);
    clk_unprepare(uVar3);
  }
  return uVar2 & 1;
}



//------------------------------------------------------------
// qcom_scm_hdcp_req @ 00108f30 size=452
// signature: undefined qcom_scm_hdcp_req(void)
// callers: []
//------------------------------------------------------------

int qcom_scm_hdcp_req(uint *param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  ulong uStack_88;
  ulong local_80;
  ulong uStack_78;
  ulong local_70;
  ulong uStack_68;
  ulong local_60;
  ulong uStack_58;
  ulong local_50;
  ulong uStack_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0 = 0x100000011;
  local_90 = (ulong)*param_1;
  uStack_88 = (ulong)param_1[1];
  local_98 = 10;
  local_80 = (ulong)param_1[2];
  uStack_78 = (ulong)param_1[3];
  local_70 = (ulong)param_1[4];
  uStack_68 = (ulong)param_1[5];
  local_60 = (ulong)param_1[6];
  uStack_58 = (ulong)param_1[7];
  local_b0 = 0;
  uStack_a8 = 0;
  local_50 = (ulong)param_1[8];
  uStack_48 = (ulong)param_1[9];
  local_b8 = 0;
  local_40 = 2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_hdcp_req"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else if (param_2 < 6) {
    iVar2 = qcom_scm_clk_enable();
    if (iVar2 == 0) {
      uVar3 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        iVar2 = __scm_smc_call(uVar3,&local_a0,qcom_scm_convention,&local_b8,0);
      }
      else if (iVar2 == 1) {
        iVar2 = scm_legacy_call(uVar3,&local_a0,&local_b8);
      }
      else {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
      }
      *param_3 = (int)local_b8;
      uVar3 = __scm[1];
      clk_disable(uVar3);
      clk_unprepare(uVar3);
      uVar3 = __scm[2];
      clk_disable(uVar3);
      clk_unprepare(uVar3);
      uVar3 = __scm[3];
      clk_disable(uVar3);
      clk_unprepare(uVar3);
    }
  }
  else {
    iVar2 = -0x22;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_scm_is_lmh_debug_set_available @ 001090f8 size=104
// signature: undefined qcom_scm_is_lmh_debug_set_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_lmh_debug_set_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_lmh_debug_set_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x13,8);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_is_lmh_debug_read_buf_size_available @ 00109164 size=104
// signature: undefined qcom_scm_is_lmh_debug_read_buf_size_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_lmh_debug_read_buf_size_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_lmh_debug_read_buf_size_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x13,9);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_is_lmh_debug_read_buf_available @ 001091d0 size=104
// signature: undefined qcom_scm_is_lmh_debug_read_buf_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_lmh_debug_read_buf_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_lmh_debug_read_buf_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x13,10);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_is_lmh_debug_get_type_available @ 0010923c size=104
// signature: undefined qcom_scm_is_lmh_debug_get_type_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_is_lmh_debug_get_type_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_is_lmh_debug_get_type_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x13,0xb);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_lmh_read_buf_size @ 001092a8 size=308
// signature: undefined qcom_scm_lmh_read_buf_size(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_read_buf_size(undefined4 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x900000013;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_read_buf_size"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_limit_dcvsh @ 001093e0 size=292
// signature: undefined qcom_scm_lmh_limit_dcvsh(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_limit_dcvsh
               (undefined8 param_1,ulong param_2,undefined8 param_3,ulong param_4,undefined8 param_5
               )

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  ulong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x1000000013;
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_88 = 0x15;
  uStack_68 = param_4 & 0xffffffff;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  local_70 = param_3;
  local_60 = param_5;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_limit_dcvsh"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_debug_read @ 00109508 size=308
// signature: undefined qcom_scm_lmh_debug_read(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_debug_read(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xa00000013;
  local_38 = 0;
  local_88 = 0x22;
  uStack_78 = param_2 & 0xffffffff;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_debug_read"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_001095cc;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_001095cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// __qcom_scm_lmh_debug_config_write @ 00109640 size=300
// signature: undefined __qcom_scm_lmh_debug_config_write(void)
// callers: [qcom_scm_lmh_debug_set_config_write]
//------------------------------------------------------------

void __qcom_scm_lmh_debug_config_write
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,int param_4,uint *param_5,
               int param_6)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined8 local_88;
  undefined8 uStack_80;
  long local_78;
  ulong uStack_70;
  ulong local_68;
  ulong uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_88 = 0x15;
  uStack_70 = (ulong)*param_5;
  local_68 = (ulong)param_5[1];
  local_90 = 0x13;
  local_78 = (long)param_4;
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  uStack_60 = (ulong)param_5[2];
  local_58 = 0;
  uStack_50 = 0;
  local_30 = 2;
  uStack_8c = param_2;
  uStack_80 = param_3;
  if ((__scm == 0) &&
     (iVar2 = _printk(&DAT_00110c5d,"__qcom_scm_lmh_debug_config_write"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
    goto LAB_00109708;
  }
  if (2 < param_6) {
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,0,0);
      goto LAB_00109708;
    }
    if (iVar2 == 1) {
      uVar3 = scm_legacy_call(param_1,&local_90,0);
      goto LAB_00109708;
    }
    _printk(&DAT_00111e2b,"qcom_scm_call");
  }
  uVar3 = 0xffffffea;
LAB_00109708:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_debug_set_config_write @ 00109770 size=144
// signature: undefined qcom_scm_lmh_debug_set_config_write(void)
// callers: []
//------------------------------------------------------------

undefined8
qcom_scm_lmh_debug_set_config_write
          (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined4 param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar1 = _printk(&DAT_00110c5d,"qcom_scm_lmh_debug_set_config_write"), iVar1 != 0)) {
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = __qcom_scm_lmh_debug_config_write(*__scm,8,param_1,param_2,param_3,param_4);
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_scm_lmh_get_type @ 00109804 size=320
// signature: undefined qcom_scm_lmh_get_type(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_get_type
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,ulong param_4,
               undefined4 *param_5)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  ulong uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0xb00000013;
  local_38 = 0;
  local_88 = 0x24;
  uStack_68 = param_4 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  local_70 = param_3;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_get_type"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_fetch_data @ 00109948 size=376
// signature: undefined qcom_scm_lmh_fetch_data(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_fetch_data(ulong param_1,ulong param_2,undefined4 *param_3,undefined4 *param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  ulong local_90;
  ulong uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uStack_88 = param_2 & 0xffffffff;
  local_48 = 0;
  local_a0 = 0xd00000013;
  local_90 = param_1 & 0xffffffff;
  local_98 = 2;
  local_40 = 2;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_fetch_data"), iVar2 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar3 = __qcom_scm_is_call_available(*__scm,0x13,0xd);
    if ((uVar3 & 1) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        uVar4 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,&local_b8,0);
      }
      else if (iVar2 == 1) {
        uVar4 = scm_legacy_call(uVar4,&local_a0,&local_b8);
      }
      else {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar4 = 0xffffffea;
      }
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = (int)local_b8;
      }
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = (int)local_b0;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_smmu_change_pgtbl_format @ 00109ac4 size=292
// signature: undefined qcom_scm_smmu_change_pgtbl_format(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_smmu_change_pgtbl_format(undefined8 param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  long lStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x100000015;
  lStack_78 = (long)param_2;
  local_38 = 0;
  local_88 = 3;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 1;
  uStack_68 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_smmu_change_pgtbl_format"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_qsmmu500_wait_safe_toggle @ 00109bec size=284
// signature: undefined qcom_scm_qsmmu500_wait_safe_toggle(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_qsmmu500_wait_safe_toggle(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x300000015;
  uStack_78 = param_1 & 1;
  local_38 = 0;
  local_88 = 2;
  local_80 = 2;
  local_30 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_qsmmu500_wait_safe_toggle"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_smmu_notify_secure_lut @ 00109d0c size=284
// signature: undefined qcom_scm_smmu_notify_secure_lut(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_smmu_notify_secure_lut(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  uStack_78 = param_2 & 1;
  local_38 = 0;
  local_90 = 0x300000015;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  local_80 = param_1;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_smmu_notify_secure_lut"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_qdss_invoke @ 00109e2c size=328
// signature: undefined qcom_scm_qdss_invoke(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_qdss_invoke(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x100000016;
  local_38 = 0;
  local_88 = 0x12;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 2;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_qdss_invoke"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar3 = -0x16;
    }
    if (param_3 != (undefined8 *)0x0) {
      *param_3 = local_a0;
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_camera_protect_all @ 00109f78 size=288
// signature: undefined qcom_scm_camera_protect_all(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_camera_protect_all(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_80 = param_1 & 0xffffffff;
  local_90 = 0x600000018;
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_camera_protect_all"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_camera_protect_phy_lanes @ 0010a09c size=284
// signature: undefined qcom_scm_camera_protect_phy_lanes(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_camera_protect_phy_lanes(ulong param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_80 = param_1 & 1;
  local_38 = 0;
  local_90 = 0x700000018;
  local_88 = 2;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 2;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_camera_protect_phy_lanes"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_camera_update_camnoc_qos @ 0010a1bc size=500
// signature: undefined qcom_scm_camera_update_camnoc_qos(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_scm_camera_update_camnoc_qos(uint param_1,uint param_2,void *param_3)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  ulong __n;
  void *__dest;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  ulong local_a0;
  undefined8 local_98;
  ulong local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_a8 = 0x83;
  local_b8 = 0;
  uStack_b0 = 0xa00000018;
  local_a0 = (ulong)param_1;
  local_90 = 0;
  uStack_88 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_98 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  local_50 = 2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_camera_update_camnoc_qos"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else if ((param_2 < 3) && ((param_2 == 0 || (param_3 != (void *)0x0)))) {
    __dest = (void *)0x0;
    __n = (ulong)(param_2 << 3);
    if (((param_1 != 0) && (param_2 != 0)) && (param_3 != (void *)0x0)) {
      __dest = (void *)dma_alloc_attrs(*__scm,__n,&local_b8,0xcc0,0);
      if (__dest == (void *)0x0) {
        uVar3 = 0xfffffff4;
        goto LAB_0010a338;
      }
      memcpy(__dest,param_3,__n);
      local_98 = local_b8;
      local_90 = __n;
    }
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar4,&uStack_b0,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar4,&uStack_b0,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (__dest != (void *)0x0) {
      dma_free_attrs(*__scm,__n,__dest,local_b8,0);
    }
  }
  else {
    _printk(&DAT_0011042c,"qcom_scm_camera_update_camnoc_qos",param_2);
    uVar3 = 0xffffffea;
  }
LAB_0010a338:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_scm_tsens_reinit @ 0010a3b4 size=308
// signature: undefined qcom_scm_tsens_reinit(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_tsens_reinit(undefined4 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x50000001e;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 2;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_tsens_reinit"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_ice_restore_cfg @ 0010a4ec size=276
// signature: undefined qcom_scm_ice_restore_cfg(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_ice_restore_cfg(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0x600000005;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 0x32;
  local_80 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_ice_restore_cfg"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_dcvsh_available @ 0010a604 size=104
// signature: undefined qcom_scm_lmh_dcvsh_available(void)
// callers: []
//------------------------------------------------------------

uint qcom_scm_lmh_dcvsh_available(void)

{
  uint uVar1;
  int iVar2;
  
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_dcvsh_available"), iVar2 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = __qcom_scm_is_call_available(*__scm,0x13,0x10);
  }
  return uVar1 & 1;
}



//------------------------------------------------------------
// qcom_scm_lmh_profile_change @ 0010a670 size=288
// signature: undefined qcom_scm_lmh_profile_change(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_lmh_profile_change(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x100000013;
  local_80 = param_1 & 0xffffffff;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_profile_change"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,0);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_lmh_dcvsh @ 0010a794 size=428
// signature: undefined qcom_scm_lmh_dcvsh(void)
// callers: []
//------------------------------------------------------------

undefined4
qcom_scm_lmh_dcvsh(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                  ulong param_5,undefined8 param_6)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  ulong uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_b0 = 0x1000000013;
  uStack_88 = param_5 & 0xffffffff;
  local_b8 = 0;
  local_a8 = 0x15;
  local_58 = 0;
  local_a0 = 0;
  uStack_98 = 0x14;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  local_50 = 2;
  local_90 = param_4;
  local_80 = param_6;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_lmh_dcvsh"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    puVar4 = (undefined4 *)dma_alloc_attrs(*__scm,0x14,&local_b8,0xcc0,0);
    if (puVar4 == (undefined4 *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      *puVar4 = param_1;
      puVar4[1] = 0;
      puVar4[4] = param_3;
      puVar4[2] = param_2;
      puVar4[3] = 1;
      local_a0 = local_b8;
      uVar5 = *__scm;
      iVar2 = __get_convention();
      if (iVar2 - 2U < 2) {
        uVar3 = __scm_smc_call(uVar5,&local_b0,qcom_scm_convention,0,0);
      }
      else if (iVar2 == 1) {
        uVar3 = scm_legacy_call(uVar5,&local_b0,0);
      }
      else {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar3 = 0xffffffea;
      }
      dma_free_attrs(*__scm,0x14,puVar4,local_b8,0);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_scm_prefetch_tgt_ctrl @ 0010a944 size=288
// signature: undefined qcom_scm_prefetch_tgt_ctrl(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_prefetch_tgt_ctrl(ulong param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x100000029;
  local_80 = param_1 & 1;
  local_38 = 0;
  local_88 = 1;
  local_48 = 0;
  uStack_40 = 0;
  uStack_78 = 0;
  local_30 = 2;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_70 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_prefetch_tgt_ctrl"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      uVar3 = scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
      uVar3 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_get_tz_log_feat_id @ 0010aa68 size=92
// signature: undefined qcom_scm_get_tz_log_feat_id(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_get_tz_log_feat_id(undefined8 param_1)

{
  undefined8 uVar1;
  
  uVar1 = param_1;
  if ((__scm == 0) &&
     (uVar1 = _printk(&DAT_00110c5d,"qcom_scm_get_tz_log_feat_id"), (int)uVar1 != 0)) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = __qcom_scm_get_feat_version(uVar1,10,param_1);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_scm_get_tz_feat_id_version @ 0010aac8 size=96
// signature: undefined qcom_scm_get_tz_feat_id_version(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_get_tz_feat_id_version(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = param_1;
  if ((__scm == 0) &&
     (uVar1 = _printk(&DAT_00110c5d,"qcom_scm_get_tz_feat_id_version"), (int)uVar1 != 0)) {
    uVar1 = 0xffffffed;
  }
  else {
    uVar1 = __qcom_scm_get_feat_version(uVar1,param_1,param_2);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_scm_register_qsee_log_buf @ 0010ab2c size=304
// signature: undefined qcom_scm_register_qsee_log_buf(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_register_qsee_log_buf(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x600000001;
  local_38 = 0;
  local_88 = 0x22;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_30 = 0x32;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  local_80 = param_1;
  uStack_78 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_register_qsee_log_buf"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    uVar4 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_0010abec;
      }
      iVar3 = scm_legacy_call(uVar4,&local_90,&local_a8);
    }
    iVar2 = (int)local_a8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_0010abec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_query_encrypted_log_feature @ 0010ac60 size=304
// signature: undefined qcom_scm_query_encrypted_log_feature(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_query_encrypted_log_feature(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0xb00000001;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 0x32;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_query_encrypted_log_feature"), iVar2 != 0)) {
    uVar3 = 0xffffffed;
  }
  else {
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
      iVar2 = (int)uVar3;
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        uVar3 = 0xffffffea;
        goto LAB_0010ad20;
      }
      uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
      iVar2 = (int)uVar3;
    }
    if (iVar2 == 0) {
      *param_1 = local_a8;
    }
  }
LAB_0010ad20:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_query_log_status @ 0010ad94 size=260
// signature: undefined qcom_scm_query_log_status(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_query_log_status(undefined8 *param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0xf00000001;
  uStack_88 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_30 = 0x32;
  local_80 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uVar3 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    uVar3 = __scm_smc_call(uVar3,&local_90,qcom_scm_convention,&local_a8,0);
    iVar2 = (int)uVar3;
  }
  else {
    if (iVar2 != 1) {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      uVar3 = 0xffffffea;
      goto LAB_0010ae50;
    }
    uVar3 = scm_legacy_call(uVar3,&local_90,&local_a8);
    iVar2 = (int)uVar3;
  }
  if (iVar2 == 0) {
    *param_1 = local_a8;
  }
LAB_0010ae50:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_request_encrypted_log @ 0010ae9c size=340
// signature: undefined qcom_scm_request_encrypted_log(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_request_encrypted_log
               (undefined8 param_1,undefined8 param_2,ulong param_3,ulong param_4,ulong param_5)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  ulong local_80;
  ulong local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_a0 = 0xc00000001;
  local_98 = 0;
  local_80 = param_3 & 0xffffffff;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_78 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_b8 = 0;
  local_40 = 0x32;
  local_90 = param_1;
  uStack_88 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"qcom_scm_request_encrypted_log"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    if ((param_4 & 1) == 0) {
      uVar4 = 0x23;
    }
    else {
      local_78 = param_5 & 1;
      uVar4 = 0x24;
    }
    local_98 = CONCAT44(local_98._4_4_,uVar4);
    uVar5 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar3 = __scm_smc_call(uVar5,&local_a0,qcom_scm_convention,&local_b8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        goto LAB_0010af84;
      }
      iVar3 = scm_legacy_call(uVar5,&local_a0,&local_b8);
    }
    iVar2 = (int)local_b8;
    if (iVar3 != 0) {
      iVar2 = iVar3;
    }
  }
LAB_0010af84:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_invoke_smc_legacy @ 0010aff4 size=340
// signature: undefined qcom_scm_invoke_smc_legacy(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_invoke_smc_legacy
               (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
               undefined4 *param_5,undefined8 *param_6,undefined4 *param_7)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0 = 6;
  local_48 = 0;
  local_98 = 0x224;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_40 = 0x100000032;
  local_b0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_90 = param_1;
  uStack_88 = param_2;
  local_80 = param_3;
  uStack_78 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_invoke_smc_legacy"), iVar3 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar4 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,&local_b8,2);
    }
    else {
      if (iVar3 == 1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b148);
        (*pcVar2)();
      }
      _printk(&DAT_00111e2b,"qcom_scm_call_noretry");
      uVar4 = 0xffffffea;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = (int)local_b0;
    }
    if (param_6 != (undefined8 *)0x0) {
      *param_6 = local_b8;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_invoke_smc @ 0010b14c size=344
// signature: undefined qcom_scm_invoke_smc(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_invoke_smc(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4
                        ,undefined4 *param_5,undefined8 *param_6,undefined4 *param_7)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0 = 0x200000006;
  local_48 = 0;
  local_98 = 0x224;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_40 = 0x100000032;
  local_b0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_90 = param_1;
  uStack_88 = param_2;
  local_80 = param_3;
  uStack_78 = param_4;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_invoke_smc"), iVar3 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar4 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,&local_b8,2);
    }
    else {
      if (iVar3 == 1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b2a4);
        (*pcVar2)();
      }
      _printk(&DAT_00111e2b,"qcom_scm_call_noretry");
      uVar4 = 0xffffffea;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = (int)local_b0;
    }
    if (param_6 != (undefined8 *)0x0) {
      *param_6 = local_b8;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_invoke_callback_response @ 0010b2a8 size=344
// signature: undefined qcom_scm_invoke_callback_response(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_invoke_callback_response
               (undefined8 param_1,undefined8 param_2,undefined4 *param_3,undefined8 *param_4,
               undefined4 *param_5)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_a0 = 0x100000006;
  local_48 = 0;
  local_98 = 0x22;
  local_80 = 0;
  uStack_78 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  local_40 = 0x100000032;
  local_b0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_90 = param_1;
  uStack_88 = param_2;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar3 = _printk(&DAT_00110c5d,"qcom_scm_invoke_callback_response"), iVar3 != 0)) {
    uVar4 = 0xffffffed;
  }
  else {
    uVar4 = *__scm;
    iVar3 = __get_convention();
    if (iVar3 - 2U < 2) {
      uVar4 = __scm_smc_call(uVar4,&local_a0,qcom_scm_convention,&local_b8,2);
    }
    else {
      if (iVar3 == 1) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b400);
        (*pcVar2)();
      }
      _printk(&DAT_00111e2b,"qcom_scm_call_noretry");
      uVar4 = 0xffffffea;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = (int)local_b0;
    }
    if (param_4 != (undefined8 *)0x0) {
      *param_4 = local_b8;
    }
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = (int)local_a8;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_invoke_ack_doorbell @ 0010b404 size=272
// signature: undefined qcom_scm_invoke_ack_doorbell(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_invoke_ack_doorbell(ulong param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  ulong uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_90 = 0x600000006;
  uStack_78 = param_2 & 0xffffffff;
  local_38 = 0;
  local_88 = 2;
  local_80 = param_1 & 0xffffffff;
  local_70 = 0;
  uStack_68 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_40 = 0;
  local_30 = 0x100000032;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  uVar4 = *__scm;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar3 = __scm_smc_call(uVar4,&local_90,qcom_scm_convention,&local_a8,1);
  }
  else {
    if (iVar2 != 1) {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
      iVar2 = -0x16;
      goto LAB_0010b4cc;
    }
    iVar3 = scm_legacy_call_atomic(uVar4,&local_90,&local_a8);
  }
  iVar2 = (int)local_a8;
  if (iVar3 != 0) {
    iVar2 = iVar3;
  }
LAB_0010b4cc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_qseecom_call @ 0010b518 size=424
// signature: undefined qcom_scm_qseecom_call(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_qseecom_call(uint param_1,uint *param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  uint local_a0;
  uint uStack_9c;
  ulong local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_a0 = param_1 >> 8 & 0xff;
  local_38 = *(long *)(lVar1 + 0x638);
  uStack_9c = param_1 & 0xff;
  uStack_90 = *(undefined8 *)(param_2 + 2);
  local_88 = *(undefined8 *)(param_2 + 4);
  local_b0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  local_98 = (ulong)*param_2;
  local_80 = *(undefined8 *)(param_2 + 6);
  local_78 = *(undefined8 *)(param_2 + 8);
  local_70 = *(undefined8 *)(param_2 + 10);
  local_68 = *(undefined8 *)(param_2 + 0xc);
  local_60 = *(undefined8 *)(param_2 + 0xe);
  local_58 = *(undefined8 *)(param_2 + 0x10);
  local_50 = *(undefined8 *)(param_2 + 0x12);
  local_48 = *(undefined8 *)(param_2 + 0x14);
  local_40 = (ulong)(param_1 >> 0x18 & 0x3f);
  if ((__scm == (undefined8 *)0x0) &&
     (iVar4 = _printk(&DAT_00110c5d,"qcom_scm_qseecom_call"), iVar4 != 0)) {
    uVar7 = 0xffffffed;
    goto LAB_0010b610;
  }
  uVar7 = *__scm;
  iVar4 = __get_convention();
  bVar3 = 1 < iVar4 - 2U;
  if ((param_3 & 1) == 0) {
    if (!bVar3) {
      uVar6 = 2;
      goto LAB_0010b5f8;
    }
    if (iVar4 == 1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10b6c0);
      (*pcVar2)();
    }
    pcVar5 = "qcom_scm_call_noretry";
LAB_0010b684:
    _printk(&DAT_00111e2b,pcVar5);
    uVar7 = 0xffffffea;
  }
  else if (bVar3) {
    if (iVar4 != 1) {
      pcVar5 = "qcom_scm_call";
      goto LAB_0010b684;
    }
    uVar7 = scm_legacy_call(uVar7,&local_a0,&local_b8);
  }
  else {
    uVar6 = 0;
LAB_0010b5f8:
    uVar7 = __scm_smc_call(uVar7,&local_a0,qcom_scm_convention,&local_b8,uVar6);
  }
  *(undefined8 *)(param_2 + 0x16) = local_b8;
  *(undefined8 *)(param_2 + 0x18) = local_b0;
  *(undefined8 *)(param_2 + 0x1a) = local_a8;
LAB_0010b610:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_is_available @ 0010b6c4 size=20
// signature: undefined qcom_scm_is_available(void)
// callers: []
//------------------------------------------------------------

bool qcom_scm_is_available(void)

{
  return __scm != 0;
}



//------------------------------------------------------------
// qcom_get_scm_device @ 0010b6dc size=28
// signature: undefined qcom_get_scm_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_get_scm_device(void)

{
  if (__scm == (undefined8 *)0x0) {
    return 0;
  }
  return *__scm;
}



//------------------------------------------------------------
// qcom_scm_multi_call_allow @ 0010b6fc size=40
// signature: undefined qcom_scm_multi_call_allow(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

undefined8 qcom_scm_multi_call_allow(long param_1,uint param_2)

{
  if (((param_1 == 0) || ((param_2 & 1) == 0)) || (*(int *)(*(long *)(param_1 + 0x98) + 0xf8) != 1))
  {
    return 0;
  }
  return 1;
}



//------------------------------------------------------------
// qcom_scm_lookup_wq @ 0010b728 size=272
// signature: undefined qcom_scm_lookup_wq(void)
// callers: [__scm_smc_call, scm_irq_work]
//------------------------------------------------------------

undefined4 * qcom_scm_lookup_wq(undefined8 *param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = param_2;
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0x16);
  puVar4 = (undefined4 *)idr_find(param_1 + 0x13,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)devm_kmalloc(*param_1,0x20,0xb20);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0xfffffffffffffff4;
    }
    else {
      *puVar4 = 0;
      __init_swait_queue_head(puVar4 + 2,"&x->wait",&init_completion___key);
      iVar2 = idr_alloc_u32(param_1 + 0x13,puVar4,&local_4c,param_2,0xa20);
      if (iVar2 < 0) {
        devm_kfree(*param_1,puVar4);
        puVar4 = (undefined4 *)(long)iVar2;
      }
    }
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x16,uVar3);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar4;
}



//------------------------------------------------------------
// scm_waitq_flag_handler @ 0010b83c size=104
// signature: undefined scm_waitq_flag_handler(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

void scm_waitq_flag_handler(undefined4 *param_1,int param_2)

{
  if (param_2 == 2) {
    complete_all(param_1);
    *param_1 = 0;
  }
  else if (param_2 == 1) {
    complete(param_1);
  }
  else {
    _printk(&DAT_001113c7,"scm_waitq_flag_handler",param_2);
  }
  return;
}



//------------------------------------------------------------
// scm_mem_protection_init_do @ 0010b8a8 size=392
// signature: undefined scm_mem_protection_init_do(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

int scm_mem_protection_init_do(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  int iVar4;
  ulong local_a8 [17];
  
  lVar1 = sp_el0;
  local_a8[0x10] = *(long *)(lVar1 + 0x638);
  local_a8[0xe] = 0;
  local_a8[0xc] = 0;
  local_a8[0xd] = 0;
  local_a8[10] = 0;
  local_a8[0xb] = 0;
  local_a8[3] = 0x700000019;
  local_a8[8] = 0;
  local_a8[9] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[4] = 2;
  local_a8[0xf] = 2;
  local_a8[5] = 0;
  local_a8[1] = 0;
  local_a8[2] = 0;
  local_a8[0] = 0;
  if ((__scm == (undefined8 *)0x0) &&
     (iVar2 = _printk(&DAT_00110c5d,"scm_mem_protection_init_do"), iVar2 != 0)) {
    iVar2 = -0x13;
  }
  else {
    local_a8[5] = 0x630;
    local_a8[6] = 0x848;
    uVar3 = *__scm;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      iVar2 = __scm_smc_call(uVar3,local_a8 + 3,qcom_scm_convention,local_a8,0);
    }
    else {
      if (iVar2 != 1) {
        _printk(&DAT_00111e2b,"qcom_scm_call");
        iVar2 = -0x16;
        _printk(&DAT_001113ea,"scm_mem_protection_init_do",0xffffffea,0);
        goto LAB_0010b97c;
      }
      iVar2 = scm_legacy_call(uVar3,local_a8 + 3,local_a8);
    }
    iVar4 = (int)local_a8[0];
    if (iVar2 == 0 && (int)local_a8[0] == 0) {
      iVar4 = 0;
    }
    else {
      _printk(&DAT_001113ea,"scm_mem_protection_init_do",iVar2,local_a8[0] & 0xffffffff);
      if (iVar2 != 0) goto LAB_0010b97c;
    }
    iVar2 = iVar4;
  }
LAB_0010b97c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// __get_convention @ 0010ba30 size=416
// signature: undefined __get_convention(void)
// callers: [qcom_scm_mmu_sync, qcom_scm_get_sec_dump_state, qcom_scm_smmu_prepare_atos_id, qcom_scm_io_reset, qcom_scm_qsmmu500_wait_safe_toggle, qcom_scm_query_encrypted_log_feature, qcom_scm_invoke_smc, __qcom_scm_get_feat_version, qcom_scm_smmu_notify_secure_lut, qcom_scm_set_warm_boot_addr, qcom_scm_memory_lat_profiler, qcom_scm_iommu_secure_ptbl_init, qcom_scm_ocmem_lock, qcom_mdf_assign_memory_to_subsys, qcom_scm_register_qsee_log_buf, qcom_scm_ocmem_unlock, qcom_scm_pas_supported, qcom_scm_camera_protect_all, qcom_scm_spin_cpu, qcom_scm_iommu_secure_map, qcom_scm_set_download_mode, qcom_scm_sec_wdog_trigger, qcom_scm_hdcp_req, qcom_scm_paravirt_tlb_inv, qcom_scm_io_readl, qcom_scm_dcvs_update_v2, qcom_scm_lmh_get_type, qcom_scm_lmh_debug_read, qcom_scm_invoke_ack_doorbell, qcom_scm_paravirt_smmu_detach, qcom_scm_delete_shm_bridge, qcom_scm_ice_invalidate_key, __qcom_scm_get_llcc_missrate, qcom_scm_hibernate_exit, qcom_scm_ice_restore_cfg, qcom_scm_cpu_power_down, qcom_scm_deassert_ps_hold, qcom_scm_lmh_fetch_data, qcom_scm_mem_protect_region_id, qcom_scm_set_cold_boot_addr, qcom_scm_pas_auth_and_reset, qcom_scm_invoke_callback_response, qcom_scm_camera_protect_phy_lanes, qcom_scm_mem_protect_lock_id2_flat, qcom_scm_get_llcc_missrate, qcom_scm_dcvs_init_v2, qcom_scm_set_remote_state, qcom_scm_prefetch_tgt_ctrl, qcom_scm_pas_mem_setup, qcom_scm_kgsl_set_smmu_lpac_aperture, qcom_scm_dcvs_update, qcom_scm_halt_spmi_pmic_arbiter, qcom_scm_dcvs_update_ca_v2, qcom_scm_sec_wdog_deactivate, qcom_scm_qdss_invoke, __qcom_scm_assign_mem, qcom_scm_mem_protect_sd_ctrl, qcom_scm_paravirt_smmu_attach, qcom_scm_iommu_secure_ptbl_size, qcom_scm_dcvs_reset, qcom_scm_set_warm_boot_addr_mc, qcom_scm_lmh_read_buf_size, qcom_scm_mem_protect_video_var, qcom_scm_config_cpu_errata, qcom_scm_disable_sdi, qcom_scm_pas_shutdown, qcom_scm_enable_shm_bridge, qcom_scm_iommu_secure_unmap, qcom_scm_pas_init_image, qcom_scm_probe, __qcom_scm_pas_mss_reset, qcom_scm_kgsl_set_smmu_aperture, qcom_scm_get_llcc_occupancy, qcom_scm_clear_ice_key, qcom_scm_kgsl_dcvs_tuning, __qcom_scm_get_llcc_occupancy, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, __qcom_scm_is_call_available, __qcom_scm_memory_lat_profiler, qcom_scm_query_log_status, qcom_scm_config_set_ice_key, __qcom_multi_smc_init, qcom_scm_io_writel, qcom_scm_create_shm_bridge, qcom_scm_do_restart, qcom_scm_lmh_limit_dcvsh, qcom_scm_request_encrypted_log, qcom_scm_tz_blsp_modify_owner, qcom_scm_invoke_smc_legacy, __qcom_scm_lmh_debug_config_write, qcom_scm_camera_update_camnoc_qos, qcom_scm_dcvs_init_ca_v2, qcom_scm_phy_update_scm_level_shifter, qcom_scm_qseecom_call, qcom_scm_assign_dump_table_region, qcom_scm_derive_raw_secret, scm_mem_protection_init_do, qcom_scm_kgsl_init_regs, qcom_scm_tsens_reinit, qcom_scm_restore_sec_cfg, qcom_scm_lmh_profile_change, qcom_scm_smmu_change_pgtbl_format]
//------------------------------------------------------------

void __get_convention(void)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  uint uVar4;
  char *pcVar5;
  long local_b8 [17];
  
  lVar1 = sp_el0;
  local_b8[0x10] = *(long *)(lVar1 + 0x638);
  local_b8[0xe] = 0;
  local_b8[0xc] = 0;
  local_b8[0xd] = 0;
  local_b8[3] = 0x100000006;
  local_b8[10] = 0;
  local_b8[0xb] = 0;
  local_b8[8] = 0;
  local_b8[9] = 0;
  local_b8[4] = 1;
  local_b8[5] = 0x2000601;
  local_b8[6] = 0;
  local_b8[7] = 0;
  local_b8[1] = 0;
  local_b8[2] = 0;
  local_b8[0xf] = 2;
  local_b8[0] = 0;
  if (qcom_scm_convention != 0) goto LAB_0010baa4;
  uVar4 = 3;
  iVar2 = __scm_smc_call(*__scm,local_b8 + 3,3,local_b8,1);
  if ((iVar2 == 0) && (local_b8[0] == 1)) {
LAB_0010bb5c:
    pcVar5 = "";
  }
  else {
    iVar2 = of_device_is_compatible(*(undefined8 *)(*__scm + 0x2e8),"qcom,scm-sc7180");
    if (iVar2 == 0) {
      iVar2 = __scm_smc_call(*__scm,local_b8 + 3,2,local_b8,1);
      uVar4 = 1;
      if (local_b8[0] == 1 && iVar2 == 0) {
        uVar4 = 2;
      }
      goto LAB_0010bb5c;
    }
    pcVar5 = " (forced)";
  }
  uVar3 = _raw_spin_lock_irqsave(&scm_query_lock);
  if (uVar4 != qcom_scm_convention) {
    qcom_scm_convention = uVar4;
    _printk(&DAT_00111417,"__get_convention",(&qcom_scm_convention_names)[uVar4],pcVar5);
  }
  _raw_spin_unlock_irqrestore(&scm_query_lock,uVar3);
LAB_0010baa4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_b8[0x10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(qcom_scm_convention);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_probe @ 0010bbd4 size=756
// signature: undefined qcom_scm_probe(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_probe(long param_1)

{
  long lVar1;
  int iVar2;
  uint uVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  uint local_ec;
  long local_e8 [23];
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_e8[0x16] = *(long *)(lVar6 + 0x638);
  plVar4 = (long *)devm_kmalloc(lVar1,0x140,0xdc0);
  if (plVar4 == (long *)0x0) {
    uVar5 = 0xfffffff4;
    goto LAB_0010be50;
  }
  uVar7 = *(undefined8 *)(param_1 + 0x2f8);
  local_e8[10] = 0;
  local_e8[0xb] = 0;
  local_e8[8] = 0;
  local_e8[9] = 0;
  local_e8[6] = 0;
  local_e8[7] = 0;
  local_e8[4] = 0;
  local_e8[5] = 0;
  local_e8[2] = 0;
  local_e8[3] = 0;
  local_e8[0] = 0;
  local_e8[1] = 0;
  local_ec = 0;
  local_e8[0x14] = 0;
  local_e8[0x15] = 0;
  local_e8[0x12] = 0;
  local_e8[0x13] = 0;
  local_e8[0x10] = 0;
  local_e8[0x11] = 0;
  local_e8[0xe] = 0;
  local_e8[0xf] = 0;
  local_e8[0xc] = 0;
  local_e8[0xd] = 0;
  iVar2 = __of_parse_phandle_with_args(uVar7,"qcom,dload-mode",0,0,0,local_e8 + 0xc);
  if ((iVar2 == 0) && (local_e8[0xc] != 0)) {
    uVar5 = of_address_to_resource(local_e8[0xc],0,local_e8);
    if ((int)uVar5 == 0) {
      uVar5 = of_property_read_u32_index(uVar7,"qcom,dload-mode",1,&local_ec);
      if ((int)uVar5 < 0) goto LAB_0010be50;
      plVar4[0x27] = local_e8[0] + (ulong)local_ec;
    }
    else if ((int)uVar5 < 0) goto LAB_0010be50;
  }
  __mutex_init(plVar4 + 0x20,"&scm->scm_bw_lock",&qcom_scm_probe___key);
  uVar3 = of_device_get_match_data(lVar1);
  *plVar4 = lVar1;
  uVar5 = devm_of_icc_get(lVar1,0);
  plVar4[4] = uVar5;
  if (0xfffffffffffff000 < uVar5) {
    uVar5 = dev_err_probe(lVar1,uVar5,"failed to acquire interconnect path\n");
    goto LAB_0010be50;
  }
  uVar5 = devm_clk_get(lVar1,&DAT_00110cc6);
  plVar4[1] = uVar5;
  if (uVar5 < 0xfffffffffffff001) {
LAB_0010bd4c:
    uVar5 = devm_clk_get(lVar1,"iface");
    plVar4[2] = uVar5;
    if (0xfffffffffffff000 < uVar5) {
      if (uVar5 == 0xfffffffffffffdfb) goto LAB_0010be4c;
      if ((uVar3 >> 1 & 1) != 0) {
        _dev_err(lVar1,"failed to acquire iface clk\n");
        uVar5 = (ulong)*(uint *)(plVar4 + 2);
        goto LAB_0010be50;
      }
      plVar4[2] = 0;
    }
    uVar5 = devm_clk_get(lVar1,&DAT_00110736);
    plVar4[3] = uVar5;
    if (0xfffffffffffff000 < uVar5) {
      if (uVar5 == 0xfffffffffffffdfb) goto LAB_0010be4c;
      if ((uVar3 >> 2 & 1) != 0) {
        _dev_err(lVar1,"failed to acquire bus clk\n");
        uVar5 = (ulong)*(uint *)(plVar4 + 3);
        goto LAB_0010be50;
      }
      plVar4[3] = 0;
    }
    lVar6 = *(long *)(param_1 + 0x2f8);
    plVar4[5] = (long)qcom_scm_pas_reset_ops;
    *(undefined4 *)(plVar4 + 0xf) = 1;
    plVar4[0xc] = lVar6;
    uVar5 = devm_reset_controller_register(lVar1);
    if ((((int)uVar5 == 0) && (uVar5 = clk_set_rate(plVar4[1],0x7fffffff), (int)uVar5 == 0)) &&
       (uVar5 = dma_set_mask_and_coherent(lVar1), (int)uVar5 == 0)) {
      *(long **)(param_1 + 0xa8) = plVar4;
      __scm = plVar4;
      __qcom_scm_init();
      __get_convention();
      uVar5 = __qcom_multi_smc_init(plVar4,param_1);
      if ((int)uVar5 == 0) {
        plVar4[0x10] = (long)qcom_scm_do_restart;
        *(undefined4 *)(plVar4 + 0x12) = 0x82;
        register_restart_handler(plVar4 + 0x10);
        if (download_mode != '\0') {
          qcom_scm_set_download_mode(0x10,0);
        }
        uVar5 = 0;
      }
    }
  }
  else {
    if (uVar5 != 0xfffffffffffffdfb) {
      if ((uVar3 & 1) != 0) {
        _dev_err(lVar1,"failed to acquire core clk\n");
        uVar5 = (ulong)*(uint *)(plVar4 + 1);
        goto LAB_0010be50;
      }
      plVar4[1] = 0;
      goto LAB_0010bd4c;
    }
LAB_0010be4c:
    uVar5 = 0xfffffdfb;
  }
LAB_0010be50:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_e8[0x16]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_shutdown @ 0010becc size=72
// signature: undefined qcom_scm_shutdown(void)
// callers: []
//------------------------------------------------------------

void qcom_scm_shutdown(void)

{
  idr_destroy(__scm + 0x98);
  qcom_scm_disable_sdi();
  qcom_scm_halt_spmi_pmic_arbiter();
  if (download_mode != '\0') {
    qcom_scm_set_download_mode(0,0);
  }
  return;
}



//------------------------------------------------------------
// dma_set_mask_and_coherent @ 0010bf14 size=68
// signature: undefined dma_set_mask_and_coherent(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

int dma_set_mask_and_coherent(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = dma_set_mask(param_1,0xffffffffffffffff);
  if (iVar1 == 0) {
    dma_set_coherent_mask(param_1,0xffffffffffffffff);
  }
  return iVar1;
}



//------------------------------------------------------------
// __qcom_multi_smc_init @ 0010bf58 size=596
// signature: undefined __qcom_multi_smc_init(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

int __qcom_multi_smc_init(long *param_1,undefined8 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  char *pcVar4;
  ulong local_b8;
  ulong local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0x13] = 0x1000000400000000;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  iVar1 = of_device_is_compatible(*(undefined8 *)(*param_1 + 0x2e8),"qcom,scm-v1.1");
  iVar2 = 0;
  if (iVar1 == 0) goto LAB_0010bfb4;
  param_1[0x17] = 0xfffffffe0;
  param_1[0x18] = (long)(param_1 + 0x18);
  param_1[0x19] = (long)(param_1 + 0x18);
  param_1[0x1a] = (long)scm_irq_work;
  iVar2 = platform_get_irq(param_2,0);
  lVar3 = *param_1;
  if (iVar2 < 0) {
    pcVar4 = "WQ IRQ is not specified: %d\n";
  }
  else {
    iVar2 = devm_request_threaded_irq(lVar3,iVar2,qcom_scm_irq_handler,0,0x2000,"qcom-scm",param_1);
    lVar3 = *param_1;
    if (-1 < iVar2) {
      lVar3 = of_find_property(*(undefined8 *)(lVar3 + 0x2e8),"qcom,no-multi-smc-support",0);
      if (lVar3 != 0) {
        _dev_info(*param_1,"Multi smc is not supported\n");
        iVar2 = 0;
        goto LAB_0010bfb4;
      }
      lVar3 = *param_1;
      local_48 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_68 = 0;
      uStack_60 = 0;
      local_a0 = 0x400000024;
      uStack_98 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_88 = 0;
      uStack_80 = 0;
      local_90 = 0;
      local_40 = 2;
      local_b0 = 0;
      uStack_a8 = 0;
      local_b8 = 0;
      *(undefined4 *)(param_1 + 0x1f) = 0;
      iVar1 = __get_convention();
      if (iVar1 - 2U < 2) {
        iVar2 = __scm_smc_call(lVar3,&local_a0,qcom_scm_convention,&local_b8,1);
LAB_0010c120:
        if (iVar2 == 0) {
          param_1[0x1d] = local_b8 & 0xff;
          param_1[0x1e] = local_b0 & 0xffff;
          *(undefined4 *)(param_1 + 0x1f) = 1;
          _printk(&DAT_00110571,"qcom_scm_query_wq_queue_info",1);
          DAT_0011017c = (undefined4)param_1[0x1d];
          qcom_scm_sem_lock = 0;
          PTR_LOOP_00110180 = (pointer_____offset_0x8___)&PTR_LOOP_00110180;
          PTR_LOOP_00110188 = (pointer_____offset_0x8___)&PTR_LOOP_00110180;
          goto LAB_0010bfb4;
        }
      }
      else {
        if (iVar1 == 1) {
          iVar2 = scm_legacy_call_atomic(lVar3,&local_a0,&local_b8);
          goto LAB_0010c120;
        }
        _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
        iVar2 = -0x16;
      }
      _printk(&DAT_00110fe4,"qcom_scm_query_wq_queue_info","qcom_scm_query_wq_queue_info",iVar2);
      goto LAB_0010bfb4;
    }
    pcVar4 = "Failed to request qcom-scm irq: %d\n";
  }
  _dev_err(lVar3,pcVar4,iVar2);
LAB_0010bfb4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qcom_scm_do_restart @ 0010c1b0 size=240
// signature: undefined qcom_scm_do_restart(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_scm_do_restart(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (_reboot_mode == 1) {
    uVar3 = *(undefined8 *)(param_1 + -0x80);
    local_38 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_90 = 0x2200000009;
    uStack_88 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_80 = 0;
    local_30 = 3;
    iVar2 = __get_convention();
    if (iVar2 - 2U < 2) {
      __scm_smc_call(uVar3,&local_90,qcom_scm_convention,0,1);
    }
    else if (iVar2 == 1) {
      scm_legacy_call_atomic(uVar3,&local_90,0);
    }
    else {
      _printk(&DAT_00111e2b,"qcom_scm_call_atomic");
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// qcom_scm_pas_reset_assert @ 0010c2a4 size=104
// signature: undefined qcom_scm_pas_reset_assert(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_pas_reset_assert(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    if ((__scm == (undefined8 *)0x0) &&
       (iVar1 = _printk(&DAT_00110c5d,"qcom_scm_pas_reset_assert"), iVar1 != 0)) {
      uVar2 = 0xffffffed;
    }
    else {
      uVar2 = __qcom_scm_pas_mss_reset(*__scm,1);
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_scm_pas_reset_deassert @ 0010c310 size=104
// signature: undefined qcom_scm_pas_reset_deassert(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_scm_pas_reset_deassert(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_2 == 0) {
    if ((__scm == (undefined8 *)0x0) &&
       (iVar1 = _printk(&DAT_00110c5d,"qcom_scm_pas_reset_deassert"), iVar1 != 0)) {
      uVar2 = 0xffffffed;
    }
    else {
      uVar2 = __qcom_scm_pas_mss_reset(*__scm,0);
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}



//------------------------------------------------------------
// __qcom_scm_pas_mss_reset @ 0010c378 size=252
// signature: undefined __qcom_scm_pas_mss_reset(void)
// callers: [qcom_scm_pas_reset_assert, qcom_scm_pas_reset_deassert]
//------------------------------------------------------------

void __qcom_scm_pas_mss_reset(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_80 = param_2 & 1;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_90 = 0xa00000002;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 2;
  local_30 = 2;
  local_a0 = 0;
  uStack_98 = 0;
  local_a8 = 0;
  iVar2 = __get_convention();
  if (iVar2 - 2U < 2) {
    iVar3 = __scm_smc_call(param_1,&local_90,qcom_scm_convention,&local_a8,0);
  }
  else {
    if (iVar2 != 1) {
      _printk(&DAT_00111e2b,"qcom_scm_call");
      iVar2 = -0x16;
      goto LAB_0010c42c;
    }
    iVar3 = scm_legacy_call(param_1,&local_90,&local_a8);
  }
  iVar2 = (int)local_a8;
  if (iVar3 != 0) {
    iVar2 = iVar3;
  }
LAB_0010c42c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// scm_irq_work @ 0010c478 size=312
// signature: undefined scm_irq_work(void)
// callers: []
//------------------------------------------------------------

void scm_irq_work(long param_1)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_44;
  int local_40;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  local_44 = 0;
  local_40 = 0;
  if (qcom_scm_convention == 3) {
    do {
      iVar2 = scm_get_wq_ctx(&local_3c,&local_40,&local_44);
      if (iVar2 != 0) {
        _printk(&DAT_00111862,"scm_irq_work",iVar2);
        break;
      }
      if (local_40 == 0) break;
      puVar3 = (undefined4 *)qcom_scm_lookup_wq(param_1 + -0xb8,local_3c);
      if ((puVar3 == (undefined4 *)0x0) || ((undefined4 *)0xfffffffffffff000 < puVar3)) {
        _printk(&DAT_0011053b,"scm_irq_work",local_3c,puVar3);
        break;
      }
      if (local_40 == 2) {
        complete_all(puVar3);
        *puVar3 = 0;
      }
      else if (local_40 == 1) {
        complete(puVar3);
      }
      else {
        _printk(&DAT_001113c7,"scm_waitq_flag_handler");
      }
    } while (local_44 != 0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_scm_irq_handler @ 0010c5b4 size=48
// signature: undefined qcom_scm_irq_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_scm_irq_handler(undefined8 param_1,long param_2)

{
  queue_work_on(0x20,_system_wq,param_2 + 0xb8);
  return 1;
}



//------------------------------------------------------------
// scm_get_wq_ctx @ 0010c5e8 size=244
// signature: undefined scm_get_wq_ctx(void)
// callers: [scm_irq_work]
//------------------------------------------------------------

void scm_get_wq_ctx(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  long local_78 [7];
  
  lVar1 = sp_el0;
  local_78[6] = *(long *)(lVar1 + 0x638);
  local_78[2] = 0;
  local_78[3] = 0;
  local_78[0] = 0;
  local_78[1] = 0;
  local_78[4] = 1;
  local_78[5] = 0;
  uVar2 = 0xc2002403;
  while( true ) {
    __arm_smccc_smc(uVar2,0,0,0,0,0,local_78[5],0,local_78,local_78 + 4);
    if (local_78[0] != 1) break;
    uVar2 = 1;
  }
  if ((int)local_78[0] == 0) {
    *param_1 = (int)local_78[1];
    *param_2 = (int)local_78[2];
    *param_3 = (int)local_78[3];
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_78[6]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __scm_smc_call @ 0010c6e0 size=1300
// signature: undefined __scm_smc_call(void)
// callers: [qcom_scm_mmu_sync, qcom_scm_get_sec_dump_state, qcom_scm_smmu_prepare_atos_id, qcom_scm_io_reset, qcom_scm_qsmmu500_wait_safe_toggle, qcom_scm_query_encrypted_log_feature, qcom_scm_invoke_smc, __qcom_scm_get_feat_version, qcom_scm_smmu_notify_secure_lut, qcom_scm_set_warm_boot_addr, qcom_scm_memory_lat_profiler, qcom_scm_iommu_secure_ptbl_init, qcom_scm_ocmem_lock, qcom_mdf_assign_memory_to_subsys, qcom_scm_register_qsee_log_buf, qcom_scm_ocmem_unlock, qcom_scm_pas_supported, qcom_scm_camera_protect_all, qcom_scm_spin_cpu, qcom_scm_iommu_secure_map, qcom_scm_set_download_mode, qcom_scm_sec_wdog_trigger, qcom_scm_hdcp_req, qcom_scm_paravirt_tlb_inv, qcom_scm_io_readl, qcom_scm_dcvs_update_v2, qcom_scm_lmh_get_type, qcom_scm_lmh_debug_read, qcom_scm_invoke_ack_doorbell, qcom_scm_paravirt_smmu_detach, qcom_scm_delete_shm_bridge, qcom_scm_ice_invalidate_key, __qcom_scm_get_llcc_missrate, qcom_scm_hibernate_exit, qcom_scm_ice_restore_cfg, qcom_scm_cpu_power_down, qcom_scm_deassert_ps_hold, qcom_scm_lmh_fetch_data, qcom_scm_mem_protect_region_id, qcom_scm_set_cold_boot_addr, qcom_scm_pas_auth_and_reset, qcom_scm_invoke_callback_response, qcom_scm_camera_protect_phy_lanes, qcom_scm_mem_protect_lock_id2_flat, qcom_scm_get_llcc_missrate, qcom_scm_dcvs_init_v2, qcom_scm_set_remote_state, qcom_scm_prefetch_tgt_ctrl, qcom_scm_pas_mem_setup, qcom_scm_kgsl_set_smmu_lpac_aperture, qcom_scm_dcvs_update, qcom_scm_halt_spmi_pmic_arbiter, qcom_scm_dcvs_update_ca_v2, qcom_scm_sec_wdog_deactivate, qcom_scm_qdss_invoke, __qcom_scm_assign_mem, qcom_scm_mem_protect_sd_ctrl, qcom_scm_paravirt_smmu_attach, qcom_scm_iommu_secure_ptbl_size, qcom_scm_dcvs_reset, qcom_scm_set_warm_boot_addr_mc, qcom_scm_lmh_read_buf_size, qcom_scm_mem_protect_video_var, qcom_scm_config_cpu_errata, qcom_scm_disable_sdi, qcom_scm_pas_shutdown, qcom_scm_enable_shm_bridge, qcom_scm_iommu_secure_unmap, qcom_scm_pas_init_image, __qcom_scm_pas_mss_reset, qcom_scm_kgsl_set_smmu_aperture, qcom_scm_get_llcc_occupancy, qcom_scm_clear_ice_key, qcom_scm_kgsl_dcvs_tuning, __qcom_scm_get_llcc_occupancy, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, __qcom_scm_is_call_available, __qcom_scm_memory_lat_profiler, qcom_scm_query_log_status, qcom_scm_config_set_ice_key, __qcom_multi_smc_init, qcom_scm_io_writel, qcom_scm_create_shm_bridge, qcom_scm_do_restart, qcom_scm_lmh_limit_dcvsh, qcom_scm_request_encrypted_log, qcom_scm_tz_blsp_modify_owner, qcom_scm_invoke_smc_legacy, __qcom_scm_lmh_debug_config_write, qcom_scm_camera_update_camnoc_qos, qcom_scm_dcvs_init_ca_v2, qcom_scm_phy_update_scm_level_shifter, qcom_scm_qseecom_call, __get_convention, qcom_scm_assign_dump_table_region, qcom_scm_derive_raw_secret, scm_mem_protection_init_do, qcom_scm_kgsl_init_regs, qcom_scm_tsens_reinit, qcom_scm_restore_sec_cfg, qcom_scm_lmh_profile_change, qcom_scm_smmu_change_pgtbl_format]
//------------------------------------------------------------

void __scm_smc_call(long param_1,uint *param_2,int param_3,ulong *param_4,int param_5)

{
  undefined8 uVar1;
  ulong uVar2;
  uint uVar3;
  ulong uVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined8 uVar7;
  uint uVar8;
  uint uVar9;
  ulong uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ulong uVar14;
  ulong uVar15;
  long lVar16;
  undefined8 local_100;
  uint local_f4;
  ulong local_d8;
  ulong local_b8;
  ulong local_b0;
  ulong local_a8;
  ulong local_a0;
  long local_98;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar16 = sp_el0;
  local_70 = *(long *)(lVar16 + 0x638);
  uVar11 = param_2[2];
  uVar5 = 0xa20;
  if (param_5 != 1) {
    uVar5 = 0xc00;
  }
  local_90 = (undefined8 *)0x0;
  uStack_88 = 0;
  local_a0 = 0;
  local_98 = 0;
  local_b0 = 0;
  local_a8 = 0;
  local_b8 = 0;
  if (param_1 == 0) {
    local_d8 = 0xfffffdfb;
    goto LAB_0010ca54;
  }
  uVar15 = *(ulong *)(param_2 + 4);
  uVar1 = *(undefined8 *)(param_2 + 6);
  uVar8 = param_2[0x18];
  uVar9 = *param_2;
  uVar13 = param_2[1];
  uVar7 = *(undefined8 *)(param_2 + 8);
  if ((uVar11 & 0xf) < 5) {
    lVar16 = *(long *)(param_2 + 10);
    local_f4 = 0;
    local_100 = 0;
  }
  else {
    local_f4 = qtee_shmbridge_is_enabled();
    if ((local_f4 & 1) == 0) {
      local_90 = (undefined8 *)kzalloc(uVar5);
      if (local_90 == (undefined8 *)0x0) {
        local_d8 = 0xfffffff4;
        goto LAB_0010ca54;
      }
    }
    else {
      local_d8 = qtee_shmbridge_allocate_shm(0x38,&local_98);
      if ((int)local_d8 != 0) goto LAB_0010ca54;
    }
    if (param_3 == 2) {
      *(int *)local_90 = (int)*(undefined8 *)(param_2 + 10);
      *(int *)((long)local_90 + 4) = (int)*(undefined8 *)(param_2 + 0xc);
      *(int *)(local_90 + 1) = (int)*(undefined8 *)(param_2 + 0xe);
      *(int *)((long)local_90 + 0xc) = (int)*(undefined8 *)(param_2 + 0x10);
      *(int *)(local_90 + 2) = (int)*(undefined8 *)(param_2 + 0x12);
      *(int *)((long)local_90 + 0x14) = (int)*(undefined8 *)(param_2 + 0x14);
      *(int *)(local_90 + 3) = (int)*(undefined8 *)(param_2 + 0x16);
    }
    else {
      *local_90 = *(undefined8 *)(param_2 + 10);
      local_90[1] = *(undefined8 *)(param_2 + 0xc);
      local_90[2] = *(undefined8 *)(param_2 + 0xe);
      local_90[3] = *(undefined8 *)(param_2 + 0x10);
      local_90[4] = *(undefined8 *)(param_2 + 0x12);
      local_90[5] = *(undefined8 *)(param_2 + 0x14);
      local_90[6] = *(undefined8 *)(param_2 + 0x16);
    }
    lVar16 = dma_map_single_attrs(param_1,local_90);
    local_98 = lVar16;
    if (lVar16 == -1) {
      if ((local_f4 & 1) == 0) {
        kfree(local_90);
        local_d8 = 0xfffffff4;
      }
      else {
        qtee_shmbridge_free_shm(&local_98);
        local_d8 = 0xfffffff4;
      }
      goto LAB_0010ca54;
    }
    local_100 = 0x38;
  }
  uVar8 = (uint)(param_3 != 2) << 0x1e | (uint)(param_5 == 1) << 0x1f | (uVar8 & 0x3f) << 0x18 |
          (uint)(byte)uVar13 | (uVar9 & 0xff) << 8;
  uVar4 = qcom_scm_multi_call_allow(param_1,(char)param_2[0x19]);
  if (param_5 == 1) {
    local_80 = 1;
    local_78 = 0;
    while (__arm_smccc_smc(uVar8,uVar11,uVar15,uVar1,uVar7,lVar16,local_78,0,&local_b8,&local_80),
          local_b8 == 1) {
      uVar8 = 1;
    }
  }
  else {
    uVar9 = 0;
    do {
      if ((uVar4 & 1) == 0) {
        mutex_lock(&qcom_scm_lock);
      }
      down(&qcom_scm_sem_lock);
      uVar14 = uVar15;
      uVar12 = uVar11;
      uVar13 = uVar8;
      do {
        local_80 = 1;
        local_78 = 0;
        uVar3 = uVar13;
        while (__arm_smccc_smc(uVar3,uVar12,uVar14,uVar1,uVar7,lVar16,local_78,0,&local_b8,&local_80
                              ), uVar2 = local_b0, local_b8 == 1) {
          uVar3 = 1;
        }
        if ((local_b8 & 0xfffffffffffffffe) != 2) {
          if ((long)local_b8 < 0) {
            local_d8 = 0;
          }
          else {
            local_d8 = 0;
            uVar15 = uVar14;
            uVar11 = uVar12;
            uVar8 = uVar13;
          }
          goto LAB_0010c978;
        }
        uVar10 = local_a8 & 0xffffffff;
        uVar6 = local_a0 & 0xffffffff;
        local_d8 = qcom_scm_lookup_wq(*(undefined8 *)(param_1 + 0x98),local_b0 & 0xffffffff);
        if ((local_d8 == 0) || (0xfffffffffffff000 < local_d8)) {
          _printk(&DAT_001105b0,uVar2 & 0xffffffff,local_d8);
          uVar15 = uVar14;
          uVar11 = uVar12;
          uVar8 = uVar13;
          goto LAB_0010c978;
        }
        if (local_b8 == 2) {
          wait_for_completion();
          uVar13 = 0x42002402;
        }
        else {
          scm_waitq_flag_handler(local_d8,uVar6);
          uVar13 = 0x42002401;
        }
        uVar12 = 1;
        uVar14 = uVar10;
      } while ((local_b8 & 0xfffffffffffffffe) == 2);
      local_d8 = 0;
      uVar15 = uVar10;
      uVar11 = 1;
      uVar8 = uVar13;
LAB_0010c978:
      up(&qcom_scm_sem_lock);
      if ((uVar4 & 1) == 0) {
        mutex_unlock(&qcom_scm_lock);
      }
      if (((((int)local_d8 != 0) || (local_b8 != 0xfffffffffffffff4)) || (param_5 == 2)) ||
         (0x14 < uVar9)) goto LAB_0010ca0c;
      uVar9 = uVar9 + 1;
      msleep(0x1e);
    } while (local_b8 == 0xfffffffffffffff4);
  }
  local_d8 = 0;
LAB_0010ca0c:
  if (local_90 != (undefined8 *)0x0) {
    dma_unmap_page_attrs(param_1,local_98,local_100,1,0);
    if ((local_f4 & 1) == 0) {
      kfree(local_90);
    }
    else {
      qtee_shmbridge_free_shm(&local_98);
    }
  }
  if ((int)local_d8 == 0) {
    if (param_4 != (ulong *)0x0) {
      *param_4 = local_b0;
      param_4[1] = local_a8;
      param_4[2] = local_a0;
    }
    if (local_b8 == 0) {
      local_d8 = 0;
    }
    else if ((uint)local_b8 < 0xfffffff4) {
      local_d8 = 0xffffffea;
    }
    else {
      local_d8 = (ulong)*(uint *)(&DAT_0010f8f0 + ((long)((local_b8 << 0x20) + 0xc00000000) >> 0x1e)
                                 );
    }
  }
LAB_0010ca54:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_d8);
  }
  return;
}



//------------------------------------------------------------
// kzalloc @ 0010cbf4 size=84
// signature: undefined kzalloc(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

void kzalloc(uint param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = 1;
  if ((param_1 & 0x10) != 0) {
    lVar1 = 2;
  }
  lVar2 = 0;
  if ((param_1 & 0x400010) != 0) {
    lVar2 = lVar1;
  }
  kmalloc_trace(*(undefined8 *)(gen_pool_free_owner + lVar2 * 0x70),param_1 | 0x100,0x1000);
  return;
}



//------------------------------------------------------------
// dma_map_single_attrs @ 0010cc48 size=184
// signature: undefined dma_map_single_attrs(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

undefined8 dma_map_single_attrs(long *param_1,ulong param_2)

{
  code *pcVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  
  uVar2 = is_vmalloc_addr(param_2);
  if (((uVar2 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar3 = dev_driver_string(param_1);
    lVar4 = param_1[0xe];
    if (lVar4 == 0) {
      lVar4 = *param_1;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar3,lVar4);
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x10ccbc);
    (*pcVar1)();
  }
  if ((uVar2 & 1) == 0) {
    uVar3 = dma_map_page_attrs(param_1,(((long)(param_2 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                       -0x200000000,param_2 & 0xfff,0x38,1,0);
  }
  else {
    uVar3 = 0xffffffffffffffff;
  }
  return uVar3;
}



//------------------------------------------------------------
// __qcom_scm_init @ 0010cd08 size=4
// signature: undefined __qcom_scm_init(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

void __qcom_scm_init(void)

{
  return;
}



//------------------------------------------------------------
// __qcom_scm_qcpe_exit @ 0010cd10 size=4
// signature: undefined __qcom_scm_qcpe_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void __qcom_scm_qcpe_exit(void)

{
  return;
}



//------------------------------------------------------------
// scm_legacy_call @ 0010cd18 size=860
// signature: undefined scm_legacy_call(void)
// callers: [qcom_scm_get_sec_dump_state, qcom_scm_sec_wdog_deactivate, qcom_scm_qdss_invoke, __qcom_scm_assign_mem, qcom_scm_smmu_prepare_atos_id, qcom_scm_query_encrypted_log_feature, qcom_scm_mem_protect_sd_ctrl, __qcom_scm_get_feat_version, qcom_scm_paravirt_smmu_attach, qcom_scm_iommu_secure_ptbl_size, qcom_scm_smmu_notify_secure_lut, qcom_scm_dcvs_reset, qcom_scm_set_warm_boot_addr_mc, qcom_scm_lmh_read_buf_size, qcom_scm_set_warm_boot_addr, qcom_scm_mem_protect_video_var, qcom_scm_config_cpu_errata, qcom_scm_memory_lat_profiler, qcom_scm_iommu_secure_ptbl_init, qcom_scm_ocmem_lock, qcom_mdf_assign_memory_to_subsys, qcom_scm_pas_shutdown, qcom_scm_enable_shm_bridge, qcom_scm_register_qsee_log_buf, qcom_scm_iommu_secure_unmap, qcom_scm_ocmem_unlock, qcom_scm_pas_init_image, qcom_scm_pas_supported, __qcom_scm_pas_mss_reset, qcom_scm_kgsl_set_smmu_aperture, qcom_scm_get_llcc_occupancy, qcom_scm_clear_ice_key, qcom_scm_camera_protect_all, qcom_scm_spin_cpu, qcom_scm_iommu_secure_map, qcom_scm_kgsl_dcvs_tuning, __qcom_scm_get_llcc_occupancy, qcom_scm_sec_wdog_trigger, qcom_scm_hdcp_req, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, __qcom_scm_is_call_available, __qcom_scm_memory_lat_profiler, qcom_scm_query_log_status, qcom_scm_config_set_ice_key, qcom_scm_dcvs_update_v2, qcom_scm_lmh_get_type, qcom_scm_lmh_debug_read, qcom_scm_paravirt_smmu_detach, qcom_scm_create_shm_bridge, qcom_scm_delete_shm_bridge, qcom_scm_lmh_limit_dcvsh, qcom_scm_request_encrypted_log, qcom_scm_ice_invalidate_key, __qcom_scm_get_llcc_missrate, qcom_scm_tz_blsp_modify_owner, qcom_scm_ice_restore_cfg, __qcom_scm_lmh_debug_config_write, qcom_scm_lmh_fetch_data, qcom_scm_mem_protect_region_id, qcom_scm_camera_update_camnoc_qos, qcom_scm_pas_auth_and_reset, qcom_scm_dcvs_init_ca_v2, qcom_scm_phy_update_scm_level_shifter, qcom_scm_qseecom_call, qcom_scm_camera_protect_phy_lanes, qcom_scm_assign_dump_table_region, qcom_scm_mem_protect_lock_id2_flat, qcom_scm_derive_raw_secret, qcom_scm_get_llcc_missrate, qcom_scm_dcvs_init_v2, qcom_scm_set_remote_state, scm_mem_protection_init_do, qcom_scm_pas_mem_setup, qcom_scm_kgsl_init_regs, qcom_scm_kgsl_set_smmu_lpac_aperture, qcom_scm_tsens_reinit, qcom_scm_restore_sec_cfg, qcom_scm_dcvs_update_ca_v2, qcom_scm_lmh_profile_change, qcom_scm_smmu_change_pgtbl_format]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 scm_legacy_call(long *param_1,int *param_2,ulong *param_3)

{
  long lVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  code *pcVar7;
  undefined4 *puVar8;
  ulong uVar9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  undefined4 uVar14;
  ulong uVar15;
  long local_90 [4];
  undefined4 local_6c;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  uVar5 = param_2[2];
  local_6c = 0;
  local_90[2] = 0;
  local_90[3] = 0;
  local_90[0] = 0;
  local_90[1] = 0;
  if (param_1 == (long *)0x0) {
    uVar14 = 0xfffffdfb;
  }
  else {
    puVar8 = (undefined4 *)kmalloc_trace(_gen_pool_free_owner,0xdc0,0x1000);
    if (puVar8 == (undefined4 *)0x0) {
      uVar14 = 0xfffffff4;
    }
    else {
      iVar3 = *param_2;
      uVar4 = param_2[1];
      uVar6 = (uVar5 & 0xf) * 4;
      lVar12 = (ulong)uVar6 + 0x28;
      uVar15 = (ulong)(uVar6 + 0x10);
      uVar5 = uVar5 & 0xf;
      *puVar8 = (int)lVar12;
      puVar8[1] = 0x10;
      puVar8[2] = uVar6 + 0x10;
      puVar8[3] = uVar4 & 0x3ff | iVar3 << 10;
      if ((((((uVar5 != 0) && (puVar8[4] = (int)*(undefined8 *)(param_2 + 4), uVar5 != 1)) &&
            (puVar8[5] = (int)*(undefined8 *)(param_2 + 6), uVar5 != 2)) &&
           ((puVar8[6] = (int)*(undefined8 *)(param_2 + 8), uVar5 != 3 &&
            (puVar8[7] = (int)*(undefined8 *)(param_2 + 10), uVar5 != 4)))) &&
          ((puVar8[8] = (int)*(undefined8 *)(param_2 + 0xc), uVar5 != 5 &&
           ((puVar8[9] = (int)*(undefined8 *)(param_2 + 0xe), uVar5 != 6 &&
            (puVar8[10] = (int)*(undefined8 *)(param_2 + 0x10), uVar5 != 7)))))) &&
         ((puVar8[0xb] = (int)*(undefined8 *)(param_2 + 0x12), uVar5 != 8 &&
          ((puVar8[0xc] = (int)*(undefined8 *)(param_2 + 0x14), uVar5 != 9 &&
           (puVar8[0xd] = (int)*(undefined8 *)(param_2 + 0x16), uVar5 != 10)))))) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10d078);
        (*pcVar7)();
      }
      uVar9 = is_vmalloc_addr(puVar8);
      if (((uVar9 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
        dma_map_single_attrs___already_done = 1;
        uVar11 = dev_driver_string(param_1);
        lVar12 = param_1[0xe];
        if (lVar12 == 0) {
          lVar12 = *param_1;
        }
        __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar11,lVar12);
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10d020);
        (*pcVar7)();
      }
      if (((uVar9 & 1) == 0) &&
         (lVar10 = dma_map_page_attrs(param_1,((((long)puVar8 << 8) >> 8) + 0x8000000000U >> 0xc) *
                                              0x40 + -0x200000000,(ulong)puVar8 & 0xfc0,lVar12,1,0),
         lVar10 != -1)) {
        down(&qcom_scm_sem_lock);
        do {
          __arm_smccc_smc(1,&local_6c,lVar10,0,0,0,0,0,local_90,0);
        } while (local_90[0] == 1);
        if (local_90[0] == 0) {
          up(&qcom_scm_sem_lock);
          lVar1 = (ulong)uVar6 + lVar10 + 0x10;
          do {
            dma_sync_single_for_cpu(param_1,lVar1,0xc,2);
          } while (*(int *)((long)puVar8 + uVar15 + 8) == 0);
          dma_sync_single_for_cpu(param_1,lVar1 + (ulong)*(uint *)((long)puVar8 + uVar15 + 4),0xc,2)
          ;
          if (param_3 == (ulong *)0x0) {
            uVar14 = 0;
          }
          else {
            uVar13 = (ulong)*(uint *)((long)puVar8 + uVar15 + 4);
            uVar9 = uVar15 + uVar13;
            if (0xffc < uVar9) {
LAB_0010d070:
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(1,0x10d074);
              (*pcVar7)();
            }
            puVar2 = (uint *)((long)puVar8 + uVar13 + uVar15);
            *param_3 = (ulong)*puVar2;
            if ((uVar9 - 0xff9 < 4) || (param_3[1] = (ulong)puVar2[1], 0xff4 < uVar9))
            goto LAB_0010d070;
            uVar14 = 0;
            param_3[2] = (ulong)puVar2[2];
          }
        }
        else {
          if ((uint)local_90[0] < 0xfffffff4) {
            uVar14 = 0xffffffea;
          }
          else {
            uVar14 = *(undefined4 *)(&DAT_0010f920 + ((local_90[0] << 0x20) + 0xc00000000 >> 0x1e));
          }
          up(&qcom_scm_sem_lock);
        }
        dma_unmap_page_attrs(param_1,lVar10,lVar12,1,0);
      }
      else {
        uVar14 = 0xfffffff4;
      }
      kfree(puVar8);
    }
  }
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar14;
}



//------------------------------------------------------------
// scm_legacy_call_atomic @ 0010d07c size=192
// signature: undefined scm_legacy_call_atomic(void)
// callers: [qcom_scm_mmu_sync, qcom_scm_paravirt_tlb_inv, qcom_scm_io_readl, qcom_scm_set_cold_boot_addr, __qcom_multi_smc_init, qcom_scm_io_writel, qcom_scm_invoke_ack_doorbell, qcom_scm_io_reset, qcom_scm_qsmmu500_wait_safe_toggle, qcom_scm_set_download_mode, qcom_scm_do_restart, qcom_scm_prefetch_tgt_ctrl, qcom_scm_disable_sdi, qcom_scm_dcvs_update, qcom_scm_halt_spmi_pmic_arbiter, qcom_scm_cpu_power_down, qcom_scm_deassert_ps_hold]
//------------------------------------------------------------

void scm_legacy_call_atomic(undefined8 param_1,int *param_2,undefined8 *param_3)

{
  long lVar1;
  code *pcVar2;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 local_38;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  local_40 = 0;
  local_38 = 0;
  local_50 = 0;
  local_48 = 0;
  if (5 < (param_2[2] & 0xeU)) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10d13c);
    (*pcVar2)();
  }
  __arm_smccc_smc(*param_2 << 0x16 | (param_2[1] & 0x3ffU) << 0xc | param_2[2] & 0xfU | 0x220,
                  &local_2c,*(undefined8 *)(param_2 + 4),*(undefined8 *)(param_2 + 6),
                  *(undefined8 *)(param_2 + 8),*(undefined8 *)(param_2 + 10),
                  *(undefined8 *)(param_2 + 0xc),0,&local_50,0);
  if (param_3 != (undefined8 *)0x0) {
    *param_3 = local_48;
    param_3[1] = local_40;
    param_3[2] = local_38;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_50 & 0xffffffff);
  }
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_is_enabled @ 0010d140 size=12
// signature: undefined qtee_shmbridge_is_enabled(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

undefined1 qtee_shmbridge_is_enabled(void)

{
  return qtee_shmbridge_enabled;
}



//------------------------------------------------------------
// qtee_shmbridge_query @ 0010d150 size=108
// signature: undefined qtee_shmbridge_query(void)
// callers: []
//------------------------------------------------------------

undefined8 qtee_shmbridge_query(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  mutex_lock(&DAT_0010fbd0);
  puVar1 = &bridge_list_head;
  do {
    puVar1 = (undefined8 *)*puVar1;
    if (puVar1 == &bridge_list_head) {
      uVar2 = 0;
      goto LAB_0010d19c;
    }
  } while (puVar1[2] != param_1);
  uVar2 = 0xffffffef;
LAB_0010d19c:
  mutex_unlock(&DAT_0010fbd0);
  return uVar2;
}



//------------------------------------------------------------
// qtee_shmbridge_register @ 0010d1c0 size=700
// signature: undefined qtee_shmbridge_register(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
qtee_shmbridge_register
          (ulong param_1,ulong param_2,uint *param_3,uint *param_4,uint param_5,uint param_6,
          undefined8 *param_7)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  byte bVar7;
  undefined8 uVar8;
  ulong uVar9;
  ushort local_6c [2];
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar8 = 0;
  local_6c[0] = 0;
  if (qtee_shmbridge_enabled == '\x01') {
    uVar9 = (ulong)param_5;
    if ((((param_5 < 5) && (param_4 != (uint *)0x0)) && (param_3 != (uint *)0x0)) &&
       (param_7 != (undefined8 *)0x0)) {
      mutex_lock(&DAT_0010fbd0);
      puVar5 = &bridge_list_head;
      while (puVar5 = (undefined8 *)*puVar5, puVar5 != &bridge_list_head) {
        if (puVar5[2] == param_1) goto LAB_0010d360;
      }
      if ((param_5 == 1) && (support_hyp != '\0')) {
        iVar2 = gh_rm_get_this_vmid(local_6c);
        if (iVar2 == 0) {
          uVar9 = (ulong)(*param_3 != (uint)local_6c[0]);
          goto LAB_0010d2a0;
        }
        uVar9 = 1;
      }
      else {
LAB_0010d2a0:
        if ((int)uVar9 == 0) {
          uVar6 = 0;
          uVar4 = 0;
          bVar7 = 1;
          iVar2 = 0;
          goto LAB_0010d2dc;
        }
      }
      iVar2 = (int)uVar9;
      uVar4 = 0;
      uVar6 = 0;
      do {
        uVar9 = uVar9 - 1;
        uVar6 = (ulong)*param_4 & 7 | uVar6 << 3;
        uVar4 = (ulong)(ushort)*param_3 | uVar4 << 0x10;
        param_4 = param_4 + 1;
        param_3 = param_3 + 1;
      } while (uVar9 != 0);
      bVar7 = 0;
LAB_0010d2dc:
      param_2 = (uint)(iVar2 << 9) | param_2;
      uVar9 = param_2 | 0x1a;
      if (!(bool)(bVar7 & support_hyp != '\0')) {
        uVar9 = param_2;
      }
      iVar2 = qcom_scm_create_shm_bridge(uVar6 | param_1,param_6 | param_1,uVar9,uVar4,param_7);
      if (iVar2 == 0) {
LAB_0010d318:
        uVar8 = *param_7;
        puVar3 = (undefined8 *)kmalloc_trace(_dma_sync_single_for_cpu,0xdc0,0x28);
        puVar5 = DAT_0010fbc8;
        if (puVar3 != (undefined8 *)0x0) {
          puVar3[2] = param_1;
          puVar3[3] = uVar8;
          *(undefined4 *)(puVar3 + 4) = 0;
          uVar9 = __list_add_valid(puVar3,puVar5,&bridge_list_head);
          if ((uVar9 & 1) != 0) {
            DAT_0010fbc8 = puVar3;
            *puVar3 = &bridge_list_head;
            puVar3[1] = puVar5;
            *puVar5 = puVar3;
          }
        }
LAB_0010d360:
        puVar5 = &bridge_list_head;
        do {
          puVar5 = (undefined8 *)*puVar5;
          if (puVar5 == &bridge_list_head) {
            _printk(&DAT_00110dcb,"qtee_shmbridge_list_inc_refcount_locked",0xfa,
                    "qtee_shmbridge_list_inc_refcount_locked",param_1);
            goto LAB_0010d44c;
          }
        } while (puVar5[2] != param_1);
        uVar8 = 0;
        *(int *)(puVar5 + 4) = *(int *)(puVar5 + 4) + 1;
        *param_7 = puVar5[3];
      }
      else {
        _printk(&DAT_00111998,"qtee_shmbridge_register",0x164,"qtee_shmbridge_register",iVar2);
        if (iVar2 == 0xf) {
          _printk(&DAT_0011084f,"qtee_shmbridge_register",0x16d,"qtee_shmbridge_register",param_1);
          goto LAB_0010d318;
        }
LAB_0010d44c:
        uVar8 = 0xffffffea;
      }
      mutex_unlock(&DAT_0010fbd0);
      goto LAB_0010d3a0;
    }
    _printk(&DAT_00110c09,"qtee_shmbridge_register",0x130);
    uVar8 = 0xffffffea;
  }
LAB_0010d3a0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// qtee_shmbridge_deregister @ 0010d480 size=376
// signature: undefined qtee_shmbridge_deregister(void)
// callers: [qtee_shmbridge_remove, qtee_shmbridge_probe]
//------------------------------------------------------------

int qtee_shmbridge_deregister(long param_1)

{
  long lVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  long *plVar5;
  undefined8 *puVar6;
  
  if (qtee_shmbridge_enabled != '\x01') {
    return 0;
  }
  mutex_lock(&DAT_0010fbd0);
  puVar6 = &bridge_list_head;
  do {
    puVar6 = (undefined8 *)*puVar6;
    if (puVar6 == &bridge_list_head) goto LAB_0010d594;
  } while (puVar6[3] != param_1);
  iVar3 = *(int *)(puVar6 + 4) + -1;
  if (*(int *)(puVar6 + 4) < 1) {
    _printk(&DAT_00111a8d,"qtee_shmbridge_list_dec_refcount_locked",0xd5,
            "qtee_shmbridge_list_dec_refcount_locked",param_1);
LAB_0010d594:
    _printk(&DAT_00110d4e,"qtee_shmbridge_list_dec_refcount_locked",0xda,param_1);
    iVar3 = -0x16;
  }
  else {
    *(int *)(puVar6 + 4) = iVar3;
    if (iVar3 == 0) {
      iVar3 = qcom_scm_delete_shm_bridge(param_1);
      if (iVar3 != 0) {
        _printk(&DAT_001111f1,"qtee_shmbridge_list_dec_refcount_locked",0xcb,
                "qtee_shmbridge_list_dec_refcount_locked",param_1,iVar3);
        *(int *)(puVar6 + 4) = *(int *)(puVar6 + 4) + 1;
        if (iVar3 != -0x16) goto LAB_0010d548;
        goto LAB_0010d594;
      }
      plVar5 = &bridge_list_head;
      do {
        plVar5 = (long *)*plVar5;
        if (plVar5 == &bridge_list_head) goto LAB_0010d544;
      } while (plVar5[3] != param_1);
      uVar4 = __list_del_entry_valid(plVar5);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar5;
        plVar2 = (long *)plVar5[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar5 = -0x2152ffffffffff00;
      plVar5[1] = -0x2152fffffffffede;
      kfree(plVar5);
    }
LAB_0010d544:
    iVar3 = 0;
  }
LAB_0010d548:
  mutex_unlock(&DAT_0010fbd0);
  return iVar3;
}



//------------------------------------------------------------
// qtee_shmbridge_allocate_shm @ 0010d5fc size=324
// signature: undefined qtee_shmbridge_allocate_shm(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

undefined8 qtee_shmbridge_allocate_shm(ulong param_1,undefined8 *param_2)

{
  int iVar1;
  ulong uVar2;
  void *__s;
  undefined8 uVar3;
  undefined8 uVar4;
  ulong uVar5;
  size_t __n;
  
  if ((param_2 == (undefined8 *)0x0) || ((undefined8 *)0xfffffffffffff000 < param_2)) {
    _printk(&DAT_0011117b,"qtee_shmbridge_allocate_shm",0x195);
    uVar4 = 0xffffffea;
  }
  else if (DAT_0010fc18 < param_1) {
    _printk(&DAT_001116da,"qtee_shmbridge_allocate_shm",0x19c);
    uVar4 = 0xffffffea;
  }
  else if (DAT_0010fc30 == 0) {
    _printk(&DAT_0011045e,"qtee_shmbridge_allocate_shm",0x1a2);
    uVar4 = 0xfffffff4;
  }
  else {
    iVar1 = 1 << (ulong)(DAT_0010fc28 & 0x1f);
    uVar5 = (ulong)iVar1;
    uVar2 = 0;
    if (uVar5 != 0) {
      uVar2 = (param_1 + (long)(iVar1 + -1)) / uVar5;
    }
    __n = uVar2 * uVar5;
    __s = (void *)gen_pool_alloc_algo_owner
                            (DAT_0010fc30,__n,*(undefined8 *)(DAT_0010fc30 + 0x20),
                             *(undefined8 *)(DAT_0010fc30 + 0x28),0);
    if (__s == (void *)0x0) {
      _printk(&DAT_001111a8,"qtee_shmbridge_allocate_shm",0x1ab,__n);
      uVar4 = 0xfffffff4;
    }
    else {
      memset(__s,0,__n);
      param_2[1] = __s;
      uVar3 = gen_pool_virt_to_phys(DAT_0010fc30,__s);
      uVar4 = 0;
      param_2[2] = __n;
      *param_2 = uVar3;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// qtee_shmbridge_free_shm @ 0010d744 size=68
// signature: undefined qtee_shmbridge_free_shm(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

void qtee_shmbridge_free_shm(ulong param_1)

{
  if (((param_1 != 0) && (param_1 < 0xfffffffffffff001)) && (*(long *)(param_1 + 8) != 0)) {
    gen_pool_free_owner(DAT_0010fc30,*(long *)(param_1 + 8),*(undefined8 *)(param_1 + 0x10),0);
  }
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_flush_shm_buf @ 0010d78c size=56
// signature: undefined qtee_shmbridge_flush_shm_buf(void)
// callers: []
//------------------------------------------------------------

void qtee_shmbridge_flush_shm_buf(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    dma_sync_single_for_device(DAT_0010fc38,*param_1,param_1[2],1);
  }
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_inv_shm_buf @ 0010d7c8 size=56
// signature: undefined qtee_shmbridge_inv_shm_buf(void)
// callers: []
//------------------------------------------------------------

void qtee_shmbridge_inv_shm_buf(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    dma_sync_single_for_cpu(DAT_0010fc38,*param_1,param_1[2],2);
  }
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_probe @ 0010d804 size=1064
// signature: undefined qtee_shmbridge_probe(void)
// callers: [qtee_shmbridge_restore]
//------------------------------------------------------------

int qtee_shmbridge_probe(long param_1)

{
  long *plVar1;
  int *piVar2;
  char *pcVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint uVar12;
  int local_68 [4];
  long local_58;
  
  lVar8 = sp_el0;
  plVar1 = (long *)(param_1 + 0x10);
  local_58 = *(long *)(lVar8 + 0x638);
  iVar6 = dma_set_mask(plVar1,0xffffffffffffffff);
  if (iVar6 < 0) {
    _printk(&DAT_00111f79,"qtee_shmbridge_probe",0x25d,iVar6);
  }
  local_68[0] = 0;
  local_68[1] = 6;
  local_68[2] = 3;
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,support-hypervisor",0);
  support_hyp = lVar8 != 0;
  piVar2 = local_68 + 3;
  if (!(bool)support_hyp) {
    piVar2 = local_68 + 2;
  }
  if (DAT_0010fc10 != 0) {
    _printk(&DAT_00110e15,"qtee_shmbridge_init",0x1f0);
    iVar6 = 0;
    goto LAB_0010dbf4;
  }
  iVar6 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,custom-bridge-size",local_68,1,0);
  uVar12 = local_68[0] << 0xc;
  if (iVar6 < 0) {
    uVar12 = 0x400000;
  }
  DAT_0010fc18 = (ulong)uVar12;
  iVar6 = 0;
  if (DAT_0010fc18 - 1 != 0xfff) {
    iVar6 = 0x40 - (int)LZCOUNT(DAT_0010fc18 - 1 >> 0xc);
  }
  uVar9 = __get_free_pages(0x40cc0,iVar6);
  uVar4 = DAT_0010fc18;
  DAT_0010fc10 = uVar9;
  if (uVar9 == 0) {
    iVar6 = -0xc;
    goto LAB_0010dbf4;
  }
  uVar10 = is_vmalloc_addr();
  if (((uVar10 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
    dma_map_single_attrs___already_done = 1;
    uVar11 = dev_driver_string(plVar1);
    lVar8 = *(long *)(param_1 + 0x80);
    if (lVar8 == 0) {
      lVar8 = *plVar1;
    }
    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar11,lVar8);
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x10dba0);
    (*pcVar5)();
  }
  if ((uVar10 & 1) == 0) {
    default_bridge =
         dma_map_page_attrs(plVar1,(((long)(uVar9 << 8) >> 8) + 0x8000000000U >> 0xc) * 0x40 +
                                   -0x200000000,uVar9 & 0xfff,uVar4,1,0);
    if (default_bridge == -1) goto LAB_0010dbb0;
    DAT_0010fc28 = 0xc;
    DAT_0010fc38 = plVar1;
    DAT_0010fc30 = gen_pool_create(0xc,0xffffffff);
    if (DAT_0010fc30 == 0) {
      _printk(&DAT_0011089f,"qtee_shmbridge_init",0x212);
      iVar6 = -0xc;
    }
    else {
      gen_pool_set_algo(DAT_0010fc30,&gen_pool_best_fit,0);
      iVar6 = gen_pool_add_owner(DAT_0010fc30,DAT_0010fc10,default_bridge,DAT_0010fc18,0xffffffff,0)
      ;
      if (iVar6 == 0) {
        __mutex_init(&DAT_0010fbd0,"&bridge_list_head.lock",&qtee_shmbridge_init___key);
        bridge_list_head = &bridge_list_head;
        DAT_0010fbc8 = &bridge_list_head;
        iVar6 = qtee_shmbridge_enable(1);
        if (iVar6 != 0) {
          iVar6 = 0;
          goto LAB_0010dbf4;
        }
        iVar6 = qtee_shmbridge_register
                          (default_bridge,DAT_0010fc18,piVar2,local_68 + 1,support_hyp == '\0',6,
                           &DAT_0010fc20);
        if (iVar6 == 0) {
          _printk(&DAT_0011159a,"qtee_shmbridge_init",0x23e,DAT_0010fc18,default_bridge);
          iVar7 = scm_mem_protection_init_do();
          pcVar3 = "Enabled";
          if (iVar7 != 0) {
            pcVar3 = "Not enabled";
          }
          _printk(&DAT_00110917,"qtee_shmbridge_init",0x243,pcVar3,iVar7);
          goto LAB_0010dbf4;
        }
        _printk(&DAT_001119da,"qtee_shmbridge_init",0x239,DAT_0010fc18);
        qtee_shmbridge_deregister(DAT_0010fc20);
        qtee_shmbridge_enable(0);
      }
      else {
        _printk(&DAT_001108d6,"qtee_shmbridge_init",0x21c,iVar6);
      }
      gen_pool_destroy(DAT_0010fc30);
      DAT_0010fc30 = 0;
    }
    dma_unmap_page_attrs(plVar1,default_bridge,DAT_0010fc18,1,0);
  }
  else {
    default_bridge = -1;
LAB_0010dbb0:
    _printk(&DAT_00110b63,"qtee_shmbridge_init",0x207);
    iVar6 = -0xc;
  }
  iVar7 = 0;
  if (0xfff < DAT_0010fc18 - 1) {
    iVar7 = 0x40 - (int)LZCOUNT(DAT_0010fc18 - 1 >> 0xc);
  }
  free_pages(DAT_0010fc10,iVar7);
  DAT_0010fc10 = 0;
LAB_0010dbf4:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qtee_shmbridge_remove @ 0010dc34 size=240
// signature: undefined qtee_shmbridge_remove(void)
// callers: [qtee_shmbridge_freeze]
//------------------------------------------------------------

undefined8 qtee_shmbridge_remove(long param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = qtee_shmbridge_deregister(DAT_0010fc20);
  if (iVar1 < 0) {
    _printk(&DAT_00111726,"qtee_shmbridge_remove",0x268,iVar1);
  }
  qtee_shmbridge_enabled = 0;
  lVar2 = of_find_property(*(undefined8 *)(DAT_0010fc38 + 0x2e8),"qcom,disable-shmbridge-support",0)
  ;
  if (lVar2 == 0) {
    _printk(&DAT_00110aea,"qtee_shmbridge_enable",0x7a);
  }
  gen_pool_destroy(DAT_0010fc30);
  DAT_0010fc30 = 0;
  dma_unmap_page_attrs(param_1 + 0x10,default_bridge,DAT_0010fc18,1,0);
  iVar1 = 0;
  if (0xfff < DAT_0010fc18 - 1U) {
    iVar1 = 0x40 - (int)LZCOUNT(DAT_0010fc18 - 1U >> 0xc);
  }
  free_pages(DAT_0010fc10,iVar1);
  DAT_0010fc10 = 0;
  return 0;
}



//------------------------------------------------------------
// qtee_shmbridge_enable @ 0010dd24 size=244
// signature: undefined qtee_shmbridge_enable(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

int qtee_shmbridge_enable(ulong param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  qtee_shmbridge_enabled = 0;
  lVar2 = of_find_property(*(undefined8 *)(DAT_0010fc38 + 0x2e8),"qcom,disable-shmbridge-support",0)
  ;
  iVar1 = 0;
  if (lVar2 == 0) {
    if ((param_1 & 1) == 0) {
      _printk(&DAT_00110aea,"qtee_shmbridge_enable",0x7a);
      iVar1 = 0;
    }
    else {
      iVar1 = qcom_scm_enable_shm_bridge();
      if (iVar1 == 0) {
        puVar3 = &DAT_0011123e;
        uVar4 = 0x88;
        qtee_shmbridge_enabled = 1;
      }
      else {
        _printk(&DAT_001109f7,"qtee_shmbridge_enable",0x81,iVar1);
        if ((iVar1 != 4) && (iVar1 != -5)) {
          return iVar1;
        }
        puVar3 = &DAT_00110949;
        uVar4 = 0x84;
      }
      _printk(puVar3,"qtee_shmbridge_enable",uVar4);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// qtee_shmbridge_freeze @ 0010de1c size=96
// signature: undefined qtee_shmbridge_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 qtee_shmbridge_freeze(long param_1)

{
  _printk(&DAT_00111cde,"qtee_shmbridge_freeze",0x27a);
  qtee_shmbridge_remove(param_1 + -0x10);
  _printk(&DAT_0011135a,"qtee_shmbridge_freeze",0x27e);
  return 0;
}



//------------------------------------------------------------
// qtee_shmbridge_restore @ 0010de80 size=124
// signature: undefined qtee_shmbridge_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 qtee_shmbridge_restore(long param_1)

{
  int iVar1;
  
  _printk(&DAT_001114c6,"qtee_shmbridge_restore",0x286);
  iVar1 = qtee_shmbridge_probe(param_1 + -0x10);
  if (iVar1 < 0) {
    _printk(&DAT_0011176b,"qtee_shmbridge_restore",0x289);
  }
  _printk(&DAT_00110b1e,"qtee_shmbridge_restore",0x28a);
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010ecb8 size=56
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&qcom_scm_driver,&__this_module);
  if (iVar1 == 0) {
    qtee_shmbridge_driver_init();
  }
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_driver_init @ 0010ecf4 size=44
// signature: undefined qtee_shmbridge_driver_init(void)
// callers: [init_module]
//------------------------------------------------------------

void qtee_shmbridge_driver_init(void)

{
  __platform_driver_register(&qtee_shmbridge_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010ed24 size=44
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  __qcom_scm_qcpe_exit();
  platform_driver_unregister(&qcom_scm_driver);
  qtee_shmbridge_driver_exit();
  return;
}



//------------------------------------------------------------
// qtee_shmbridge_driver_exit @ 0010ed54 size=36
// signature: undefined qtee_shmbridge_driver_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void qtee_shmbridge_driver_exit(void)

{
  platform_driver_unregister(&qtee_shmbridge_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00114010 size=1
// signature: undefined _printk(void)
// callers: [qcom_scm_mmu_sync, qcom_scm_get_sec_dump_state, qcom_scm_smmu_prepare_atos_id, qcom_scm_io_reset, qcom_scm_get_tz_log_feat_id, qcom_scm_qsmmu500_wait_safe_toggle, qcom_scm_query_encrypted_log_feature, qcom_scm_invoke_smc, __qcom_scm_get_feat_version, qcom_scm_smmu_notify_secure_lut, qcom_scm_set_warm_boot_addr, qcom_scm_memory_lat_profiler, qcom_scm_iommu_secure_ptbl_init, qcom_scm_ocmem_lock, qcom_mdf_assign_memory_to_subsys, qcom_scm_is_lmh_debug_read_buf_size_available, qcom_scm_register_qsee_log_buf, qcom_scm_ocmem_unlock, qcom_scm_pas_supported, qcom_scm_ocmem_lock_available, qcom_scm_camera_protect_all, qcom_scm_spin_cpu, qcom_scm_iommu_secure_map, qcom_scm_set_download_mode, qcom_scm_pas_reset_deassert, qcom_scm_is_mode_switch_available, qcom_scm_pas_shutdown_retry, qcom_scm_sec_wdog_trigger, qcom_scm_hdcp_req, qcom_scm_lmh_debug_set_config_write, qtee_shmbridge_restore, scm_irq_work, __scm_smc_call, qcom_scm_paravirt_tlb_inv, qcom_scm_io_readl, qcom_scm_dcvs_update_v2, qcom_scm_lmh_get_type, qcom_scm_lmh_debug_read, qcom_scm_invoke_ack_doorbell, qtee_shmbridge_deregister, qcom_scm_paravirt_smmu_detach, qcom_scm_delete_shm_bridge, qcom_scm_dcvs_ca_available, qcom_scm_ice_invalidate_key, __qcom_scm_get_llcc_missrate, qtee_shmbridge_freeze, qcom_scm_get_jtag_etm_feat_id, qcom_scm_hibernate_exit, qcom_scm_get_tz_feat_id_version, qcom_scm_ice_restore_cfg, qcom_scm_cpu_power_down, qcom_scm_deassert_ps_hold, qcom_scm_lmh_fetch_data, qcom_scm_mem_protect_region_id, qcom_scm_set_cold_boot_addr, qcom_scm_pas_auth_and_reset, qcom_scm_invoke_callback_response, qcom_scm_camera_protect_phy_lanes, qcom_scm_get_feat_version_cp, qcom_scm_is_lmh_debug_read_buf_available, qcom_scm_mem_protect_lock_id2_flat, qcom_scm_get_llcc_missrate, qcom_scm_dcvs_init_v2, qcom_scm_set_remote_state, qcom_scm_prefetch_tgt_ctrl, qcom_scm_pas_mem_setup, qcom_scm_kgsl_set_smmu_lpac_aperture, qcom_scm_dcvs_update, qcom_scm_halt_spmi_pmic_arbiter, qcom_scm_dcvs_update_ca_v2, qcom_scm_is_lmh_debug_get_type_available, qcom_scm_sec_wdog_deactivate, qcom_scm_qdss_invoke, __qcom_scm_assign_mem, scm_waitq_flag_handler, qcom_scm_mem_protect_sd_ctrl, qcom_scm_paravirt_smmu_attach, qcom_scm_iommu_secure_ptbl_size, qcom_scm_dcvs_reset, qcom_scm_set_warm_boot_addr_mc, qcom_scm_lmh_read_buf_size, qcom_scm_mem_protect_video_var, qcom_scm_config_cpu_errata, qcom_scm_disable_sdi, qcom_scm_pas_shutdown, qtee_shmbridge_probe, qcom_scm_enable_shm_bridge, qcom_scm_iommu_secure_unmap, qcom_scm_pas_init_image, qtee_shmbridge_remove, __qcom_scm_pas_mss_reset, qcom_scm_kgsl_set_smmu_aperture, qcom_scm_get_llcc_occupancy, qcom_scm_clear_ice_key, qcom_scm_kgsl_dcvs_tuning, __qcom_scm_get_llcc_occupancy, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, __qcom_scm_is_call_available, __qcom_scm_memory_lat_profiler, qcom_scm_query_log_status, qcom_scm_ice_available, qcom_scm_config_set_ice_key, qcom_scm_assign_mem_regions, __qcom_multi_smc_init, qcom_scm_pas_reset_assert, qcom_scm_io_writel, qcom_scm_create_shm_bridge, qcom_scm_do_restart, qcom_scm_lmh_limit_dcvsh, qcom_scm_request_encrypted_log, qtee_shmbridge_allocate_shm, qcom_scm_tz_blsp_modify_owner, qcom_scm_get_download_mode, qcom_scm_dcvs_core_available, qcom_scm_invoke_smc_legacy, __qcom_scm_lmh_debug_config_write, qcom_scm_camera_update_camnoc_qos, qcom_scm_dcvs_init_ca_v2, qcom_scm_phy_update_scm_level_shifter, qcom_scm_qseecom_call, qtee_shmbridge_enable, __get_convention, qcom_scm_assign_dump_table_region, qcom_scm_derive_raw_secret, qcom_scm_hdcp_available, qcom_scm_restore_sec_cfg_available, qcom_scm_kgsl_set_smmu_aperture_available, qcom_scm_is_secure_wdog_trigger_available, scm_mem_protection_init_do, qcom_scm_kgsl_init_regs, qcom_scm_lmh_dcvsh_available, qtee_shmbridge_register, qcom_scm_assign_mem, qcom_scm_is_lmh_debug_set_available, qcom_scm_tsens_reinit, qcom_scm_restore_sec_cfg, qcom_scm_lmh_profile_change, qcom_scm_smmu_change_pgtbl_format]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00114018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_scm_mmu_sync, qcom_scm_get_sec_dump_state, qcom_scm_smmu_prepare_atos_id, qcom_scm_io_reset, qcom_scm_qsmmu500_wait_safe_toggle, qcom_scm_query_encrypted_log_feature, qcom_scm_invoke_smc, __qcom_scm_get_feat_version, qcom_scm_smmu_notify_secure_lut, qcom_scm_set_warm_boot_addr, qcom_scm_memory_lat_profiler, qcom_scm_iommu_secure_ptbl_init, qcom_scm_ocmem_lock, qcom_mdf_assign_memory_to_subsys, qcom_scm_register_qsee_log_buf, qcom_scm_ocmem_unlock, qcom_scm_pas_supported, qcom_scm_camera_protect_all, qcom_scm_spin_cpu, qcom_scm_iommu_secure_map, qcom_scm_set_download_mode, qcom_scm_sec_wdog_trigger, qcom_scm_hdcp_req, scm_irq_work, __scm_smc_call, qcom_scm_paravirt_tlb_inv, qcom_scm_io_readl, qcom_scm_dcvs_update_v2, qcom_scm_lmh_get_type, qcom_scm_lmh_debug_read, qcom_scm_invoke_ack_doorbell, qcom_scm_paravirt_smmu_detach, qcom_scm_delete_shm_bridge, qcom_scm_ice_invalidate_key, __qcom_scm_get_llcc_missrate, qcom_scm_hibernate_exit, qcom_scm_ice_restore_cfg, qcom_scm_cpu_power_down, qcom_scm_deassert_ps_hold, qcom_scm_lmh_fetch_data, qcom_scm_mem_protect_region_id, qcom_scm_set_cold_boot_addr, qcom_scm_pas_auth_and_reset, qcom_scm_invoke_callback_response, qcom_scm_camera_protect_phy_lanes, qcom_scm_mem_protect_lock_id2_flat, qcom_scm_get_llcc_missrate, qcom_scm_dcvs_init_v2, qcom_scm_set_remote_state, qcom_scm_prefetch_tgt_ctrl, qcom_scm_pas_mem_setup, qcom_scm_kgsl_set_smmu_lpac_aperture, qcom_scm_dcvs_update, qcom_scm_halt_spmi_pmic_arbiter, qcom_scm_dcvs_update_ca_v2, qcom_scm_lookup_wq, qcom_scm_sec_wdog_deactivate, qcom_scm_qdss_invoke, __qcom_scm_assign_mem, scm_get_wq_ctx, qcom_scm_mem_protect_sd_ctrl, qcom_scm_paravirt_smmu_attach, qcom_scm_iommu_secure_ptbl_size, qcom_scm_dcvs_reset, qcom_scm_set_warm_boot_addr_mc, qcom_scm_lmh_read_buf_size, qcom_scm_mem_protect_video_var, qcom_scm_config_cpu_errata, qcom_scm_disable_sdi, qcom_scm_pas_shutdown, qtee_shmbridge_probe, qcom_scm_enable_shm_bridge, qcom_scm_iommu_secure_unmap, qcom_scm_pas_init_image, qcom_scm_probe, __qcom_scm_pas_mss_reset, qcom_scm_kgsl_set_smmu_aperture, qcom_scm_get_llcc_occupancy, qcom_scm_clear_ice_key, qcom_scm_kgsl_dcvs_tuning, __qcom_scm_get_llcc_occupancy, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, __qcom_scm_is_call_available, __qcom_scm_memory_lat_profiler, qcom_scm_query_log_status, scm_legacy_call, scm_legacy_call_atomic, qcom_scm_config_set_ice_key, __qcom_multi_smc_init, qcom_scm_io_writel, qcom_scm_create_shm_bridge, qcom_scm_do_restart, qcom_scm_lmh_limit_dcvsh, qcom_scm_request_encrypted_log, qcom_scm_tz_blsp_modify_owner, qcom_scm_invoke_smc_legacy, __qcom_scm_lmh_debug_config_write, qcom_scm_camera_update_camnoc_qos, qcom_scm_dcvs_init_ca_v2, qcom_scm_phy_update_scm_level_shifter, qcom_scm_qseecom_call, __get_convention, qcom_scm_assign_dump_table_region, qcom_scm_derive_raw_secret, scm_mem_protection_init_do, qcom_scm_kgsl_init_regs, qtee_shmbridge_register, qcom_scm_assign_mem, qcom_scm_tsens_reinit, qcom_scm_restore_sec_cfg, qcom_scm_lmh_profile_change, qcom_scm_smmu_change_pgtbl_format]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00114028 size=1
// signature: undefined _find_next_bit(void)
// callers: [qcom_scm_set_cold_boot_addr, qcom_scm_set_warm_boot_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00114030 size=1
// signature: undefined _find_first_bit(void)
// callers: [qcom_scm_set_cold_boot_addr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00114048 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_scm_pas_init_image, qcom_scm_probe, __qcom_multi_smc_init, qcom_scm_pas_auth_and_reset, qcom_scm_get_download_mode, qcom_scm_pas_mem_setup, qcom_scm_assign_mem, qcom_scm_set_download_mode, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00114050 size=1
// signature: undefined mutex_lock(void)
// callers: [__scm_smc_call, qcom_scm_pas_init_image, qcom_scm_pas_auth_and_reset, qcom_scm_pas_mem_setup, qtee_shmbridge_query, qtee_shmbridge_register, qtee_shmbridge_deregister, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// icc_set_bw @ 00114058 size=1
// signature: undefined icc_set_bw(void)
// callers: [qcom_scm_pas_init_image, qcom_scm_pas_auth_and_reset, qcom_scm_pas_mem_setup, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void icc_set_bw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00114060 size=1
// signature: undefined mutex_unlock(void)
// callers: [__scm_smc_call, qcom_scm_pas_init_image, qcom_scm_pas_auth_and_reset, qcom_scm_pas_mem_setup, qtee_shmbridge_query, qtee_shmbridge_register, qtee_shmbridge_deregister, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 00114068 size=1
// signature: undefined clk_disable(void)
// callers: [qcom_scm_hdcp_available, qcom_scm_pas_init_image, qcom_scm_clk_enable, qcom_scm_hdcp_req, qcom_scm_pas_auth_and_reset, qcom_scm_pas_mem_setup, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 00114070 size=1
// signature: undefined clk_unprepare(void)
// callers: [qcom_scm_hdcp_available, qcom_scm_pas_init_image, qcom_scm_clk_enable, qcom_scm_hdcp_req, qcom_scm_pas_auth_and_reset, qcom_scm_pas_mem_setup, qcom_scm_pas_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 00114078 size=1
// signature: undefined clk_prepare(void)
// callers: [qcom_scm_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 00114080 size=1
// signature: undefined clk_enable(void)
// callers: [qcom_scm_clk_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00114088 size=1
// signature: undefined msleep(void)
// callers: [__scm_smc_call, qcom_scm_pas_shutdown_retry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight64 @ 00114090 size=1
// signature: undefined __sw_hweight64(void)
// callers: [qcom_scm_assign_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00114098 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [qcom_scm_camera_update_camnoc_qos, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, qcom_scm_assign_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001140a0 size=1
// signature: undefined dma_free_attrs(void)
// callers: [qcom_scm_camera_update_camnoc_qos, qcom_scm_ice_set_key, qcom_scm_lmh_dcvsh, qcom_scm_assign_mem]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001140a8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_scm_camera_update_camnoc_qos, qcom_scm_ice_set_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001140b0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qtee_shmbridge_allocate_shm, qcom_scm_ice_set_key]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001140b8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_scm_lookup_wq, __get_convention]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 001140c0 size=1
// signature: undefined idr_find(void)
// callers: [qcom_scm_lookup_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001140c8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_scm_lookup_wq, __get_convention]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001140d0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_scm_lookup_wq, qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001140d8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_scm_lookup_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_u32 @ 001140e0 size=1
// signature: undefined idr_alloc_u32(void)
// callers: [qcom_scm_lookup_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 001140e8 size=1
// signature: undefined devm_kfree(void)
// callers: [qcom_scm_lookup_wq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001140f0 size=1
// signature: undefined complete(void)
// callers: [scm_waitq_flag_handler, scm_irq_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 001140f8 size=1
// signature: undefined complete_all(void)
// callers: [scm_waitq_flag_handler, scm_irq_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00114100 size=1
// signature: undefined __platform_driver_register(void)
// callers: [init_module, qtee_shmbridge_driver_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __platform_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00114108 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [qtee_shmbridge_driver_exit, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 00114110 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [__qcom_multi_smc_init, __get_convention]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00114118 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 00114120 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 00114128 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00114130 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_scm_probe, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00114138 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_of_icc_get @ 00114140 size=1
// signature: undefined devm_of_icc_get(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_of_icc_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00114148 size=1
// signature: undefined dev_err_probe(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 00114150 size=1
// signature: undefined devm_clk_get(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_reset_controller_register @ 00114158 size=1
// signature: undefined devm_reset_controller_register(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_reset_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_set_rate @ 00114160 size=1
// signature: undefined clk_set_rate(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_set_rate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_restart_handler @ 00114168 size=1
// signature: undefined register_restart_handler(void)
// callers: [qcom_scm_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 00114170 size=1
// signature: undefined idr_destroy(void)
// callers: [qcom_scm_shutdown]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00114178 size=1
// signature: undefined dma_set_mask(void)
// callers: [dma_set_mask_and_coherent, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_coherent_mask @ 00114180 size=1
// signature: undefined dma_set_coherent_mask(void)
// callers: [dma_set_mask_and_coherent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_coherent_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00114188 size=1
// signature: undefined platform_get_irq(void)
// callers: [__qcom_multi_smc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00114190 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [__qcom_multi_smc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00114198 size=1
// signature: undefined of_find_property(void)
// callers: [__qcom_multi_smc_init, qtee_shmbridge_remove, qtee_shmbridge_enable, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001141a0 size=1
// signature: undefined _dev_info(void)
// callers: [__qcom_multi_smc_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001141b8 size=1
// signature: undefined queue_work_on(void)
// callers: [qcom_scm_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arm_smccc_smc @ 001141d0 size=1
// signature: undefined __arm_smccc_smc(void)
// callers: [__scm_smc_call, scm_legacy_call_atomic, scm_get_wq_ctx, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arm_smccc_smc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down @ 001141d8 size=1
// signature: undefined down(void)
// callers: [__scm_smc_call, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 001141e0 size=1
// signature: undefined wait_for_completion(void)
// callers: [__scm_smc_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up @ 001141e8 size=1
// signature: undefined up(void)
// callers: [__scm_smc_call, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 001141f0 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [__scm_smc_call, qtee_shmbridge_remove, scm_legacy_call, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001141f8 size=1
// signature: undefined kfree(void)
// callers: [__scm_smc_call, qtee_shmbridge_deregister, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00114208 size=1
// signature: undefined kmalloc_trace(void)
// callers: [kzalloc, qtee_shmbridge_register, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00114210 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [dma_map_single_attrs, scm_legacy_call, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 00114218 size=1
// signature: undefined dev_driver_string(void)
// callers: [dma_map_single_attrs, scm_legacy_call, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00114220 size=1
// signature: undefined __warn_printk(void)
// callers: [dma_map_single_attrs, scm_legacy_call, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00114228 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [dma_map_single_attrs, scm_legacy_call, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 00114230 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [qtee_shmbridge_inv_shm_buf, scm_legacy_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_get_this_vmid @ 00114238 size=1
// signature: undefined gh_rm_get_this_vmid(void)
// callers: [qtee_shmbridge_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_get_this_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00114240 size=1
// signature: undefined __list_add_valid(void)
// callers: [qtee_shmbridge_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00114248 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qtee_shmbridge_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_alloc_algo_owner @ 00114250 size=1
// signature: undefined gen_pool_alloc_algo_owner(void)
// callers: [qtee_shmbridge_allocate_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_alloc_algo_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_virt_to_phys @ 00114258 size=1
// signature: undefined gen_pool_virt_to_phys(void)
// callers: [qtee_shmbridge_allocate_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_virt_to_phys(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_free_owner @ 00114260 size=1
// signature: undefined gen_pool_free_owner(void)
// callers: [qtee_shmbridge_free_shm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_free_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_device @ 00114268 size=1
// signature: undefined dma_sync_single_for_device(void)
// callers: [qtee_shmbridge_flush_shm_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00114270 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_free_pages @ 00114278 size=1
// signature: undefined __get_free_pages(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_create @ 00114280 size=1
// signature: undefined gen_pool_create(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_set_algo @ 00114290 size=1
// signature: undefined gen_pool_set_algo(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_set_algo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_add_owner @ 00114298 size=1
// signature: undefined gen_pool_add_owner(void)
// callers: [qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_add_owner(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gen_pool_destroy @ 001142a0 size=1
// signature: undefined gen_pool_destroy(void)
// callers: [qtee_shmbridge_remove, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gen_pool_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_pages @ 001142a8 size=1
// signature: undefined free_pages(void)
// callers: [qtee_shmbridge_remove, qtee_shmbridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_pages(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



