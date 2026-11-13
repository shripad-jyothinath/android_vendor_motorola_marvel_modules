// Decompiled by Ghidra 12.2
// Program: cdsprm.ko
// Image base: 00100000

//------------------------------------------------------------
// cdsprm_register_cdspl3gov @ 0010083c size=76
// signature: undefined cdsprm_register_cdspl3gov(void)
// callers: []
//------------------------------------------------------------

void cdsprm_register_cdspl3gov(undefined8 *param_1)

{
  undefined8 uVar1;
  
  if (param_1 != (undefined8 *)0x0) {
    uVar1 = _raw_spin_lock_irqsave(&DAT_00105738);
    DAT_001058f0 = *param_1;
    _raw_spin_unlock_irqrestore(&DAT_00105738,uVar1);
  }
  return;
}



//------------------------------------------------------------
// cdsprm_cxlimit_npu_limit_register @ 0010088c size=32
// signature: undefined cdsprm_cxlimit_npu_limit_register(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_cxlimit_npu_limit_register(undefined8 *param_1)

{
  if (param_1 == (undefined8 *)0x0) {
    return 0xffffffea;
  }
  DAT_00105900 = *param_1;
  return 0;
}



//------------------------------------------------------------
// cdsprm_cxlimit_npu_limit_deregister @ 001008b0 size=32
// signature: undefined cdsprm_cxlimit_npu_limit_deregister(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_cxlimit_npu_limit_deregister(void)

{
  if (DAT_00105900 == 0) {
    return 0xffffffea;
  }
  DAT_00105900 = 0;
  return 0;
}



//------------------------------------------------------------
// cdsprm_compute_core_set_priority @ 001008d4 size=136
// signature: undefined cdsprm_compute_core_set_priority(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_compute_core_set_priority(undefined4 param_1)

{
  long lVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  DAT_001057c0 = param_1;
  if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
    local_28 = 3;
    local_20 = 0xc;
    uStack_24 = param_1;
    rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_28,0xc);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// cdsprm_compute_vtcm_set_partition_map @ 00100960 size=420
// signature: undefined cdsprm_compute_vtcm_set_partition_map(void)
// callers: [process_cdsp_request_thread, cdsprm_vtcm_partition_state_write]
//------------------------------------------------------------

int cdsprm_compute_vtcm_set_partition_map(undefined4 param_1)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  undefined4 local_150;
  undefined8 local_14c;
  undefined4 local_144;
  byte local_140;
  byte local_13f;
  undefined1 local_13c [4];
  undefined4 local_138 [47];
  undefined1 local_7c [68];
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  memset(&local_140,0,0x104);
  iVar5 = -0x16;
  if ((DAT_00105770 != 0) && (1 < gcdsprm)) {
    local_14c = 0xd00000002;
    local_140 = DAT_001055bc;
    local_13f = DAT_001055bd;
    local_144 = param_1;
    if ((ulong)DAT_001055bc != 0) {
      lVar6 = 0;
      do {
        if (lVar6 == 0xc0) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100b00);
          (*pcVar4)();
        }
        lVar1 = lVar6 + 0xc;
        uVar2 = *(undefined4 *)((long)&DAT_001055c4 + lVar6);
        uVar3 = *(undefined4 *)((long)&DAT_001055c8 + lVar6);
        local_13c[lVar6] = (&DAT_001055c0)[lVar6];
        *(undefined4 *)((long)local_138 + lVar6) = uVar2;
        *(undefined4 *)((long)local_138 + lVar6 + 4) = uVar3;
        lVar6 = lVar1;
      } while ((ulong)DAT_001055bc * 0xc != lVar1);
    }
    if (DAT_001055bd != 0) {
      lVar6 = 0;
      do {
        if (((lVar6 - 0x41U < 0xfffffffffffffeeb) || (lVar6 == 0x40)) ||
           (local_7c[lVar6] = (&DAT_00105680)[lVar6], lVar6 - 0x40U < 0xfffffffffffffeeb)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x100afc);
          (*pcVar4)();
        }
        lVar1 = lVar6 + 2;
        local_7c[lVar6 + 1] = (&DAT_00105681)[lVar6];
        lVar6 = lVar1;
      } while ((ulong)DAT_001055bd * 2 != lVar1);
    }
    local_150 = 0x114;
    iVar5 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_150,0x114);
    DAT_00104db0 = local_144;
    if (iVar5 == 0) {
      _printk(&DAT_0010698a);
    }
    else {
      _printk(&DAT_00106d15);
    }
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_config @ 00100b08 size=232
// signature: undefined cdsprm_resmgr_pdkill_config(void)
// callers: []
//------------------------------------------------------------

int cdsprm_resmgr_pdkill_config(int param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 local_150;
  undefined4 local_148;
  int iStack_144;
  undefined1 auStack_140 [264];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  memset(auStack_140,0,0x104);
  iVar2 = -0x16;
  if ((DAT_00105770 != 0) && (2 < gcdsprm)) {
    local_148 = 0x10;
    local_150 = 0x200000114;
    iStack_144 = param_1;
    iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_150,0x114);
    if (iVar2 == 0) {
      puVar3 = &DAT_00107bb8;
      DAT_00104dbc = param_1;
    }
    else {
      puVar3 = &DAT_00106de5;
      param_1 = iVar2;
    }
    _printk(puVar3,param_1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cdsprm_cxlimit_npu_activity_notify @ 00100bf4 size=420
// signature: undefined cdsprm_cxlimit_npu_activity_notify(void)
// callers: []
//------------------------------------------------------------

int cdsprm_cxlimit_npu_activity_notify(int param_1)

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
  if (DAT_001057f8 == '\0') {
    iVar2 = -0x16;
    goto LAB_00100d64;
  }
  mutex_lock(&DAT_001057c8);
  if (param_1 == 0) {
    if (DAT_00105850 != 0) {
      iVar2 = -1;
      goto LAB_00100c60;
    }
    if (DAT_001057fc != 0) {
      iVar2 = -0x16;
      DAT_001057fc = param_1;
      if ((DAT_00105770 != 0) && (gcdsprm != 0)) goto LAB_00100cec;
      goto LAB_00100d58;
    }
LAB_00100d54:
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
LAB_00100c60:
    DAT_00105850 = DAT_00105850 + iVar2;
    if ((DAT_00105850 != 0) == (DAT_001057fc != 0)) goto LAB_00100d54;
    iVar2 = -0x16;
    DAT_001057fc = param_1;
    if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
      if (param_1 != 0) {
        DAT_00105804 = DAT_00105804 + 1;
      }
LAB_00100cec:
      local_48 = CONCAT44(param_1,6);
      local_40 = 0xc;
      DAT_001057fc = param_1;
      iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      if ((DAT_001057fc == 0) || (iVar2 == 0)) {
        if ((DAT_001057fc == 0) || (iVar2 != 0)) goto LAB_00100d58;
        mutex_unlock(&DAT_001057c8);
        wait_for_completion(&DAT_00105810);
        mutex_lock(&DAT_001057c8);
      }
      DAT_00105804 = DAT_00105804 + -1;
    }
  }
LAB_00100d58:
  mutex_unlock(&DAT_001057c8);
LAB_00100d64:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cdsprm_cxlimit_npu_corner_notify @ 00100d9c size=332
// signature: undefined cdsprm_cxlimit_npu_corner_notify(void)
// callers: []
//------------------------------------------------------------

uint cdsprm_cxlimit_npu_corner_notify(uint param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  if ((DAT_001058ab != '\0') || (DAT_001057f8 == '\0')) goto LAB_00100eb4;
  mutex_lock(&DAT_001057c8);
  uVar2 = DAT_00105854;
  uVar3 = param_1;
  if ((DAT_00105770 != 0) && (uVar3 = param_1, gcdsprm != 0)) {
    if (DAT_00105854 <= param_1 - 1) {
      DAT_00105808 = DAT_00105808 + 1;
    }
    local_48 = CONCAT44(param_1,8);
    local_40 = 0xc;
    DAT_00105854 = param_1;
    iVar4 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
    if ((DAT_00105854 - 1 < uVar2) || (iVar4 == 0)) {
      uVar3 = DAT_00105854;
      if ((DAT_00105854 - 1 < uVar2) || (iVar4 != 0)) goto LAB_00100ea8;
      mutex_unlock(&DAT_001057c8);
      wait_for_completion(&DAT_00105830);
      mutex_lock(&DAT_001057c8);
      if (DAT_00105858 != 0) {
        DAT_00105854 = DAT_00105858;
        param_1 = DAT_00105858;
      }
    }
    DAT_00105808 = DAT_00105808 + -1;
    uVar3 = DAT_00105854;
  }
LAB_00100ea8:
  DAT_00105854 = uVar3;
  mutex_unlock(&DAT_001057c8);
LAB_00100eb4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_1;
}



//------------------------------------------------------------
// cdsprm_cxlimit_camera_activity_notify @ 00100eec size=160
// signature: undefined cdsprm_cxlimit_camera_activity_notify(void)
// callers: []
//------------------------------------------------------------

void cdsprm_cxlimit_camera_activity_notify(undefined4 param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  if (DAT_001057f8 == '\0') {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
    DAT_00105800 = param_1;
    if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
      local_28 = 0xb;
      local_20 = 0xc;
      uStack_24 = param_1;
      rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_28,0xc);
      uVar2 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// cdsprm_unregister_cdspl3gov @ 00100f90 size=64
// signature: undefined cdsprm_unregister_cdspl3gov(void)
// callers: []
//------------------------------------------------------------

void cdsprm_unregister_cdspl3gov(void)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(&DAT_00105738);
  DAT_001058f0 = 0;
  _raw_spin_unlock_irqrestore(&DAT_00105738,uVar1);
  return;
}



//------------------------------------------------------------
// dcvs_vcorner_ext @ 00100fd4 size=108
// signature: undefined dcvs_vcorner_ext(void)
// callers: [cdsprm_sysmon_dcvs_clients_votes]
//------------------------------------------------------------

char * dcvs_vcorner_ext(uint param_1)

{
  char *pcVar1;
  
  if (param_1 < 0x2c1) {
                    /* WARNING: Could not recover jumptable at 0x00101000. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    pcVar1 = (char *)(*(code *)(&UNK_00101004 + (ulong)(byte)(&DAT_00103920)[param_1] * 4))
                               ("DISABLE");
    return pcVar1;
  }
  if (param_1 - 0x2c1 < 0xfd3f) {
    return "MAX";
  }
  pcVar1 = "MIN";
  if (0xff < param_1 - 1) {
    pcVar1 = "INVALID";
  }
  return pcVar1;
}



//------------------------------------------------------------
// cdsprm_sysmon_dcvs_clients_votes @ 001010c8 size=2936
// signature: undefined cdsprm_sysmon_dcvs_clients_votes(void)
// callers: [dcvs_clients_show]
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 cdsprm_sysmon_dcvs_clients_votes(void *param_1,ulong param_2)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined *puVar10;
  char *pcVar11;
  char *pcVar12;
  undefined *puVar13;
  char *pcVar14;
  ulong uVar15;
  undefined8 uVar16;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  long local_70;
  
  lVar5 = sp_el0;
  local_70 = *(long *)(lVar5 + 0x638);
  if ((param_1 == (void *)0x0) && ((param_2 & 1) == 0)) {
    _printk(&DAT_00106931);
    uVar16 = 6;
    goto LAB_001011a4;
  }
  memset((void *)((long)&local_180 + 4),0,0x108);
  if ((DAT_00105770 == 0) || (gcdsprm < 5)) {
    uVar16 = 5;
    _printk(&DAT_00106c6e,5);
    goto LAB_001011a4;
  }
  local_180 = CONCAT44(local_180._4_4_,0x14);
  local_188 = 0x200000114;
  iVar4 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_188,0x114);
  if (iVar4 != 0) {
    _printk(&DAT_0010740a,iVar4);
    uVar16 = 4;
    goto LAB_001011a4;
  }
  lVar5 = wait_for_completion_timeout(&DAT_00106730,0x19);
  if (lVar5 == 0) {
    _printk(&DAT_00107b0d);
    uVar16 = 3;
    goto LAB_001011a4;
  }
  if (DAT_0010598c == '\x01') {
    if (((param_2 & 1) != 0) && (_printk(&DAT_00106cb3,DAT_00105988), DAT_00105988 != 0)) {
      _printk(&DAT_00107944);
      if ((ulong)(long)DAT_00105929 < 10) {
        puVar8 = (&PTR_s_DISABLE_00104730)[DAT_00105929];
      }
      else {
        puVar8 = &DAT_0010767e;
      }
      if ((ulong)(long)DAT_0010592a < 10) {
        puVar10 = (&PTR_s_DISABLE_00104730)[DAT_0010592a];
      }
      else {
        puVar10 = &DAT_0010767e;
      }
      if ((ulong)(long)DAT_00105928 < 10) {
        puVar13 = (&PTR_s_DISABLE_00104730)[DAT_00105928];
      }
      else {
        puVar13 = &DAT_0010767e;
      }
      _printk(&DAT_00107b37,puVar8,puVar10,puVar13);
      puVar8 = &DAT_00107682;
      if (DAT_00105979 != '\0') {
        puVar8 = &DAT_00107735;
      }
      _printk(&DAT_00106785,puVar8);
      if ((ulong)(long)DAT_0010592c < 10) {
        puVar8 = (&PTR_s_DISABLE_00104730)[DAT_0010592c];
      }
      else {
        puVar8 = &DAT_0010767e;
      }
      if ((ulong)(long)DAT_0010592d < 10) {
        puVar10 = (&PTR_s_DISABLE_00104730)[DAT_0010592d];
      }
      else {
        puVar10 = &DAT_0010767e;
      }
      if ((ulong)(long)DAT_0010592b < 10) {
        puVar13 = (&PTR_s_DISABLE_00104730)[DAT_0010592b];
      }
      else {
        puVar13 = &DAT_0010767e;
      }
      _printk(&DAT_00107118,puVar8,puVar10,puVar13);
      puVar8 = &DAT_00107682;
      if (DAT_0010597a != '\0') {
        puVar8 = &DAT_00107735;
      }
      _printk(&DAT_00106ea0,puVar8);
      if (DAT_0010592f != '\0') {
        if (DAT_0010592e - 1 < 5) {
          pcVar11 = (&PTR_s_ADSP_DCVS_POLICY_BALANCED_001046f0)[(char)(DAT_0010592e - 1)];
        }
        else {
          pcVar11 = "INVALID_DCVS_POLICY";
        }
        _printk(&DAT_0010724d,"ENABLED",pcVar11);
      }
      if (DAT_00105930 != 0) {
        _printk(&DAT_00107284);
      }
      if (DAT_00105934 != 0) {
        _printk(&DAT_00107153);
      }
      puVar8 = &DAT_001069bb;
      if (DAT_00105978 != '\0') {
        puVar8 = &DAT_00106cda;
      }
      _printk(&DAT_00107687,puVar8);
      uVar16 = dcvs_vcorner_ext(DAT_0010593c);
      uVar6 = dcvs_vcorner_ext(DAT_00105940);
      uVar7 = dcvs_vcorner_ext(DAT_00105938);
      _printk(&DAT_00106d3e,uVar16,uVar6,uVar7);
      puVar8 = &DAT_00107682;
      if (DAT_0010597b != '\0') {
        puVar8 = &DAT_00107735;
      }
      _printk(&DAT_00107369,puVar8);
      if (DAT_00105944 != 0) {
        _printk(&DAT_0010738b);
      }
      if (DAT_00105948 != 0) {
        _printk(&DAT_00106d79);
      }
      if (DAT_0010594c != 0) {
        _printk(&DAT_00106896);
      }
      if (DAT_00105950 != 0) {
        _printk(&DAT_00106ec2);
      }
      if ((ulong)(long)DAT_00105955 < 10) {
        puVar8 = (&PTR_s_DISABLE_00104730)[DAT_00105955];
      }
      else {
        puVar8 = &DAT_0010767e;
      }
      if ((ulong)(long)DAT_00105956 < 10) {
        puVar10 = (&PTR_s_DISABLE_00104730)[DAT_00105956];
      }
      else {
        puVar10 = &DAT_0010767e;
      }
      puVar13 = &DAT_0010767e;
      if ((ulong)(long)DAT_00105954 < 10) {
        puVar13 = (&PTR_s_DISABLE_00104730)[DAT_00105954];
      }
      _printk(&DAT_00106f59,puVar8,puVar10,puVar13);
      puVar8 = &DAT_00107682;
      if (DAT_00105957 != '\0') {
        puVar8 = &DAT_00107735;
      }
      _printk(&DAT_00107538,puVar8);
      if (DAT_00105958 != 0) {
        _printk(&DAT_00106a00);
      }
      if (DAT_00105960 != 0) {
        _printk(&DAT_00106aa7);
      }
      if (DAT_00105964 != 0) {
        _printk(&DAT_00107a0a);
      }
      if (DAT_00105968 != 0) {
        _printk(&DAT_00107a3b);
      }
      if (DAT_0010596c != 0) {
        _printk(&DAT_001077c8);
      }
      if (DAT_00105970 != 0) {
        _printk(&DAT_00107962);
      }
      if (DAT_00105974 != 0) {
        if (DAT_00105974 == 1) {
          pcVar11 = "ALL_LPM_DISABLED";
        }
        else if (DAT_00105974 == 3) {
          pcVar11 = "RPM_ASSISTED_APCR_ENABLED";
        }
        else if (DAT_00105974 == 2) {
          pcVar11 = "STANDALONE_APCR_ENABLED";
        }
        else {
          pcVar11 = "UNKNOWN";
        }
        _printk(&DAT_00106cdd,pcVar11);
      }
      if (DAT_00105988 != 0) {
        uVar15 = 0;
        pcVar11 = &DAT_00105a6e;
        do {
          _printk(&DAT_00107739,*(undefined4 *)(pcVar11 + -0x42));
          _printk(&DAT_00106cfa,*(undefined4 *)(pcVar11 + -0x3e));
          _printk(&DAT_00106adc,*(undefined4 *)(pcVar11 + -0x46));
          if (pcVar11[-0xd6] == '\0') {
            if (pcVar11[-0x3a] == '\0') goto LAB_001016dc;
LAB_001016fc:
            pcVar9 = "ADSP_DCVS_ADJUST_UP_DOWN";
            switch(*(undefined4 *)(pcVar11 + -0x2e)) {
            case 1:
              break;
            case 2:
              pcVar9 = "DSP_DCVS_ADJUST_ONLY_UP";
              break;
            default:
              pcVar9 = "INVALID_DCVS_POLICY";
              break;
            case 4:
              pcVar9 = "ADSP_DCVS_POWER_SAVER_MODE";
              break;
            case 8:
              pcVar9 = "ADSP_DCVS_POWER_SAVER_AGGRESSIVE_MODE";
              break;
            case 0x10:
              pcVar9 = "ADSP_DCVS_PERFORMANCE_MODE";
              break;
            case 0x20:
              pcVar9 = "ADSP_DCVS_DUTY_CYCLE_MODE";
            }
            _printk(&DAT_001079b6,"ENABLED",pcVar9);
            cVar2 = pcVar11[-0x39];
          }
          else {
            _printk(&DAT_001072aa);
            if (pcVar11[-0x3a] != '\0') goto LAB_001016fc;
LAB_001016dc:
            cVar2 = pcVar11[-0x39];
          }
          if ((cVar2 != '\0') && (*(int *)(pcVar11 + -0x36) != 0xffff)) {
            _printk(&DAT_00107449);
          }
          uVar1 = *(uint *)(pcVar11 + -0x32);
          if (uVar1 == 0) {
            if (pcVar11[-0x2a] == '\0') goto LAB_001017b8;
LAB_00101840:
            puVar8 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x28] < 10) {
              puVar8 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x28]];
            }
            puVar10 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x27] < 10) {
              puVar10 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x27]];
            }
            puVar13 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x29] < 10) {
              puVar13 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x29]];
            }
            _printk(&DAT_001067a8,puVar8,puVar10,puVar13);
            puVar8 = &DAT_00107682;
            if (pcVar11[-1] != '\0') {
              puVar8 = &DAT_00107735;
            }
            _printk(&DAT_00106785,puVar8);
            if (pcVar11[-0x26] != '\0') goto LAB_001018a8;
LAB_001017c0:
            cVar2 = pcVar11[-6];
          }
          else {
            local_120 = 0;
            uStack_118 = 0;
            local_130 = 0;
            uStack_128 = 0;
            local_140 = 0;
            uStack_138 = 0;
            local_150 = 0;
            uStack_148 = 0;
            local_160 = 0;
            uStack_158 = 0;
            local_170 = 0;
            uStack_168 = 0;
            local_180 = 0;
            uStack_178 = 0;
            local_188 = 0;
            strscpy(&local_188,"Client Class: ",0xf);
            if ((uVar1 & 1) != 0) {
              strlcat(&local_188,"AUDIO ",0x78);
            }
            if ((uVar1 >> 1 & 1) != 0) {
              strlcat(&local_188,"VOICE ",0x78);
            }
            if ((uVar1 >> 2 & 1) != 0) {
              strlcat(&local_188,"COMPUTE ",0x78);
            }
            if ((uVar1 >> 3 & 1) != 0) {
              strlcat(&local_188,"STREAMING_1_HVX ",0x78);
            }
            if ((uVar1 >> 4 & 1) != 0) {
              strlcat(&local_188,"STREAMING_2_HVX ",0x78);
            }
            _printk(&DAT_00106a4d,&local_188);
            if (pcVar11[-0x2a] != '\0') goto LAB_00101840;
LAB_001017b8:
            if (pcVar11[-0x26] == '\0') goto LAB_001017c0;
LAB_001018a8:
            puVar8 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x24] < 10) {
              puVar8 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x24]];
            }
            puVar10 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x23] < 10) {
              puVar10 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x23]];
            }
            puVar13 = &DAT_0010767e;
            if ((ulong)(long)pcVar11[-0x25] < 10) {
              puVar13 = (&PTR_s_DISABLE_00104730)[pcVar11[-0x25]];
            }
            _printk(&DAT_00107be2,puVar8,puVar10,puVar13);
            puVar8 = &DAT_00107682;
            if (*pcVar11 != '\0') {
              puVar8 = &DAT_00107735;
            }
            _printk(&DAT_00106ea0,puVar8);
            cVar2 = pcVar11[-6];
          }
          if ((cVar2 != '\0') && (*(int *)(pcVar11 + -0x22) != 0 || *(int *)(pcVar11 + -0x1e) != 0))
          {
            _printk(&DAT_00106af4);
          }
          if ((pcVar11[-5] != '\0') && (*(long *)(pcVar11 + -0x16) != 0)) {
            _printk(&DAT_00106bd4,*(long *)(pcVar11 + -0x16),*(undefined4 *)(pcVar11 + -0xe));
          }
          if ((*(int *)(pcVar11 + -10) != 0xffff) && (pcVar11[-4] != '\0')) {
            _printk(&DAT_00106c1c);
          }
          bVar3 = pcVar11[-2];
          if ((bVar3 != 0) && (pcVar11[-3] != '\0')) {
            pcVar9 = "UNKNOWN";
            if (bVar3 < 4) {
              pcVar9 = (&PTR_s_ALL_LPM_DISABLED_00104718)[(char)(bVar3 - 1)];
            }
            _printk(&DAT_00107b73,pcVar9);
          }
          puVar8 = &DAT_001069bb;
          if (pcVar11[-0x96] != '\0') {
            puVar8 = &DAT_00106cda;
          }
          _printk(&DAT_00107687,puVar8);
          if (pcVar11[-0x95] != '\0') {
            uVar16 = dcvs_vcorner_ext(*(undefined4 *)(pcVar11 + -0x86));
            uVar6 = dcvs_vcorner_ext(*(undefined4 *)(pcVar11 + -0x82));
            uVar7 = dcvs_vcorner_ext(*(undefined4 *)(pcVar11 + -0x8a));
            _printk(&DAT_00106d3e,uVar16,uVar6,uVar7);
            puVar8 = &DAT_00107682;
            if (pcVar11[-0x7e] != '\0') {
              puVar8 = &DAT_00107735;
            }
            _printk(&DAT_00107369,puVar8);
            pcVar9 = "FALSE";
            if (pcVar11[-0x94] != '\0') {
              pcVar9 = "TRUE";
            }
            _printk(&DAT_00106e20,pcVar9);
            if (*(int *)(pcVar11 + -0x92) == 0) {
              if (*(int *)(pcVar11 + -0x8e) == 0) goto LAB_00101a68;
LAB_00101c24:
              _printk(&DAT_00106eea);
              iVar4 = *(int *)(pcVar11 + -0x7a);
            }
            else {
              _printk(&DAT_00107753);
              if (*(int *)(pcVar11 + -0x8e) != 0) goto LAB_00101c24;
LAB_00101a68:
              iVar4 = *(int *)(pcVar11 + -0x7a);
            }
            if (iVar4 != 0) {
              _printk(&DAT_00106896);
            }
          }
          uVar1 = *(uint *)(pcVar11 + -0x6a);
          if (uVar1 < 10) {
            pcVar9 = (&PTR_s_DISABLE_00104730)[(int)uVar1];
          }
          else {
            pcVar9 = "MAX";
            if (0xf5 < uVar1 - 10) {
              pcVar9 = "INVALID";
            }
          }
          uVar1 = *(uint *)(pcVar11 + -0x66);
          if (uVar1 < 10) {
            pcVar12 = (&PTR_s_DISABLE_00104730)[(int)uVar1];
          }
          else {
            pcVar12 = "MAX";
            if (0xf5 < uVar1 - 10) {
              pcVar12 = "INVALID";
            }
          }
          uVar1 = *(uint *)(pcVar11 + -0x6e);
          if (uVar1 < 10) {
            pcVar14 = (&PTR_s_DISABLE_00104730)[(int)uVar1];
          }
          else {
            pcVar14 = "MAX";
            if (0xf5 < uVar1 - 10) {
              pcVar14 = "INVALID";
            }
          }
          _printk(&DAT_001075a1,pcVar9,pcVar12,pcVar14);
          puVar8 = &DAT_00107682;
          if (pcVar11[-0x52] != '\0') {
            puVar8 = &DAT_00107735;
          }
          _printk(&DAT_001076a5,puVar8);
          if (*(long *)(pcVar11 + -0x5e) != 0) {
            _printk(&DAT_001070ac,*(long *)(pcVar11 + -0x5e),*(undefined4 *)(pcVar11 + -0x56));
          }
          puVar8 = &DAT_001069bf;
          if ((((pcVar11[-0x39] != '\0') &&
               (puVar8 = &DAT_001069bf, *(int *)(pcVar11 + -0x36) - 1U < 4999)) &&
              (puVar8 = &DAT_001069bf, pcVar11[-2] != '\0')) &&
             (puVar8 = &DAT_001069bf, pcVar11[-3] != '\0')) {
            puVar8 = &DAT_00107998;
          }
          _printk(&DAT_001073b1,puVar8);
          uVar16 = 0;
          if (0xd < uVar15) break;
          uVar15 = uVar15 + 1;
          pcVar11 = pcVar11 + 0xe8;
        } while (uVar15 < DAT_00105988);
        goto LAB_0010118c;
      }
    }
    uVar16 = 0;
  }
  else {
    _printk(&DAT_0010790b);
    uVar16 = 2;
  }
LAB_0010118c:
  if (param_1 != (void *)0x0) {
    memcpy(param_1,&DAT_00105928,0xe08);
  }
LAB_001011a4:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar16;
}



//------------------------------------------------------------
// process_cdsp_request_thread @ 00101c44 size=1788
// signature: undefined process_cdsp_request_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 process_cdsp_request_thread(void)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  undefined *puVar8;
  undefined4 uVar9;
  long *plVar10;
  undefined8 local_1a8;
  undefined4 local_1a0;
  undefined8 local_198;
  undefined4 local_190;
  undefined8 local_188;
  undefined8 local_180;
  undefined8 uStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  local_1a0 = 0;
  local_1a8 = 0;
  uVar5 = kthread_should_stop();
  if ((uVar5 & 1) == 0) {
    plVar10 = (long *)0x0;
    do {
      uVar5 = kthread_should_stop();
      if ((uVar5 & 1) == 0) {
        uVar6 = _raw_spin_lock_irqsave(0x10573c);
        plVar10 = (long *)cdsprm_list;
        _raw_spin_unlock_irqrestore(0x10573c,uVar6);
        if (((undefined **)plVar10 != &cdsprm_list) && (plVar10 != (long *)0x0)) goto LAB_00101d60;
        local_170 = 0;
        uStack_168 = 0;
        local_180 = 0;
        uStack_178 = 0;
        local_188 = 0;
        init_wait_entry(&local_188,0);
        lVar7 = prepare_to_wait_event(cdsprm_wq,&local_188,1);
        uVar5 = kthread_should_stop();
        plVar10 = (long *)0x0;
        if ((uVar5 & 1) == 0) {
          do {
            uVar6 = _raw_spin_lock_irqsave(0x10573c);
            plVar10 = (long *)cdsprm_list;
            _raw_spin_unlock_irqrestore(0x10573c,uVar6);
            if (((undefined **)plVar10 != &cdsprm_list) && (plVar10 != (long *)0x0))
            goto LAB_00101df4;
            if (lVar7 != 0) {
              plVar10 = (long *)0x0;
              uVar5 = kthread_should_stop();
              if ((uVar5 & 1) == 0) goto LAB_00101e0c;
              goto LAB_00101c84;
            }
            schedule();
            lVar7 = prepare_to_wait_event(cdsprm_wq,&local_188,1);
            uVar5 = kthread_should_stop();
          } while ((uVar5 & 1) == 0);
          plVar10 = (long *)0x0;
        }
LAB_00101df4:
        finish_wait(cdsprm_wq,&local_188);
        uVar5 = kthread_should_stop();
      }
      else {
LAB_00101d60:
        uVar5 = kthread_should_stop();
      }
      lVar7 = 0;
      if ((uVar5 & 1) != 0) break;
LAB_00101e0c:
      if ((int)lVar7 == 0) {
        if (plVar10 == (long *)0x0) break;
        if (plVar10 + 2 == (long *)0x0) goto LAB_00101f94;
        iVar3 = (int)plVar10[2];
        if ((iVar3 == 2) && (DAT_001058aa != '\0')) {
          mutex_lock(&DAT_00105708);
          if (*(int *)((long)plVar10 + 0x14) == 1) {
            if (DAT_001058b0 != DAT_001057b8) {
              set_qos_latency();
              DAT_001058b0 = DAT_001057b8;
            }
            DAT_00105780 = plVar10[3];
            if (DAT_00105778 < 3) {
              if (DAT_00105778 == 0) goto LAB_00101f74;
            }
            else {
              __flush_workqueue(DAT_001056d0);
              if (DAT_00105778 == 4) {
LAB_00101f74:
                DAT_00105778 = 1;
                queue_work_on(0x20,DAT_001056d0,&DAT_001056d8);
              }
            }
          }
          else if ((*(int *)((long)plVar10 + 0x14) == 2) && (DAT_001058b0 != 0x7fffffff)) {
            set_qos_latency(0x7fffffff);
            DAT_001058b0 = 0x7fffffff;
          }
          mutex_unlock(&DAT_00105708);
          goto LAB_00101f94;
        }
        if (iVar3 == 0xc) {
          local_190 = 0;
          local_198 = 0;
          if (gcdsprm == 0) goto LAB_00101f94;
          if ((gcdsprm != 1) && (DAT_00104db4 != 0)) {
            cdsprm_compute_vtcm_set_partition_map(1);
          }
          if (DAT_001057f8 != '\0') {
            DAT_00105810 = 0;
            DAT_00105830 = 0;
            if (DAT_00105854 != 0) {
              local_198 = CONCAT44(DAT_00105854,8);
              local_190 = 0xc;
              rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_198,0xc);
            }
            if (DAT_001057fc != 0) {
              local_198 = CONCAT44(DAT_001057fc,6);
              local_190 = 0xc;
              rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_198,0xc);
            }
            if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
              local_188 = CONCAT44(DAT_001057c0,3);
              local_180 = CONCAT44(local_180._4_4_,0xc);
              rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_188,0xc);
            }
            if (DAT_00105800 != 0) {
              local_198 = CONCAT44(DAT_00105800,0xb);
              local_190 = 0xc;
              rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_198,0xc);
            }
          }
          iVar4 = DAT_00105894;
          iVar3 = DAT_00105890;
          if (DAT_00105890 == 0) {
            if (DAT_00105894 != 0) {
              local_180 = (ulong)local_180._4_4_ << 0x20;
              local_188 = 0;
              mutex_lock(&DAT_00105860);
              if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
                local_188._0_6_ = CONCAT24((short)iVar4,10);
                local_180 = CONCAT44(local_180._4_4_,0xc);
                local_188 = CONCAT26((short)DAT_00105890,(undefined6)local_188);
                iVar3 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_188,0xc);
                if (iVar3 == 0) {
                  DAT_00105894 = iVar4;
                }
              }
              goto LAB_00102288;
            }
          }
          else {
            local_180 = (ulong)local_180._4_4_ << 0x20;
            local_188 = 0;
            mutex_lock(&DAT_00105860);
            if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
              local_188._0_6_ = CONCAT24((short)DAT_00105894,10);
              local_188 = CONCAT26((short)iVar3,(undefined6)local_188);
              local_180 = CONCAT44(local_180._4_4_,0xc);
              iVar4 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_188,0xc);
              if (iVar4 == 0) {
                DAT_00105890 = iVar3;
              }
            }
LAB_00102288:
            mutex_unlock(&DAT_00105860);
          }
          iVar3 = DAT_00104dbc;
          memset(&uStack_178,0,0x104);
          if ((DAT_00105770 != 0) && (2 < gcdsprm)) {
            local_180 = CONCAT44(iVar3,0x10);
            local_188 = 0x200000114;
            iVar4 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_188,0x114);
            if (iVar4 == 0) {
              puVar8 = &DAT_00107bb8;
              DAT_00104dbc = iVar3;
              iVar4 = iVar3;
            }
            else {
              puVar8 = &DAT_00106de5;
            }
LAB_00102334:
            _printk(puVar8,iVar4);
          }
        }
        else if (iVar3 == 5) {
          mutex_lock(&DAT_001057c8);
          DAT_00105908 = DAT_00105900;
          if (DAT_00105900 == (code *)0x0) {
            mutex_unlock(&DAT_001057c8);
            uVar9 = 0;
          }
          else {
            DAT_0010585c = *(undefined4 *)((long)plVar10 + 0x14);
            DAT_001058ab = 1;
            if (*(int *)(DAT_00105900 + -4) != -0x137bf691) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10219c);
              (*pcVar2)();
            }
            iVar3 = (*DAT_00105900)();
            DAT_001058ab = 0;
            mutex_unlock(&DAT_001057c8);
            uVar9 = 0;
            if (iVar3 == 0) {
              uVar9 = *(undefined4 *)((long)plVar10 + 0x14);
            }
          }
          local_1a8 = CONCAT44(uVar9,4);
          local_1a0 = 0xc;
          iVar4 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_1a8,0xc);
          if (iVar4 != 0) {
            puVar8 = &DAT_00107799;
            goto LAB_00102334;
          }
        }
        else if (iVar3 == 1) {
          uVar9 = *(undefined4 *)((long)plVar10 + 0x14);
          uVar6 = _raw_spin_lock_irqsave(&DAT_00105738);
          DAT_001058f8 = DAT_001058f0;
          _raw_spin_unlock_irqrestore(&DAT_00105738,uVar6);
          if (DAT_001058f8 != (code *)0x0) {
            if (*(int *)(DAT_001058f8 + -4) != -0x54ac3a37) {
                    /* WARNING: Does not return */
              pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101f24);
              (*pcVar2)();
            }
            (*DAT_001058f8)(uVar9);
          }
        }
LAB_00101f94:
        uVar6 = _raw_spin_lock_irqsave(0x10573c);
        uVar5 = __list_del_entry_valid(plVar10);
        if ((uVar5 & 1) != 0) {
          lVar7 = *plVar10;
          plVar1 = (long *)plVar10[1];
          *(long **)(lVar7 + 8) = plVar1;
          *plVar1 = lVar7;
        }
        *(undefined1 *)((long)plVar10 + 0x24) = 0;
        *plVar10 = -0x2152ffffffffff00;
        plVar10[1] = -0x2152fffffffffede;
        _raw_spin_unlock_irqrestore(0x10573c,uVar6);
      }
      uVar5 = kthread_should_stop();
    } while ((uVar5 & 1) == 0);
  }
LAB_00101c84:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// process_delayed_rm_request @ 00102344 size=308
// signature: undefined process_delayed_rm_request(void)
// callers: []
//------------------------------------------------------------

void process_delayed_rm_request(void)

{
  ulong uVar1;
  
  mutex_lock(&DAT_00105708);
  InstructionSynchronizationBarrier();
  uVar1 = cntvct_el0;
  if ((DAT_001058b0 == DAT_001057b8) && (uVar1 < DAT_00105780)) {
    while (uVar1 = DAT_00105780 - uVar1, uVar1 < (uint)(DAT_001057bc * 0x4b00)) {
      DAT_00105778 = 2;
      mutex_unlock(&DAT_00105708);
      uVar1 = (uVar1 / 0x4b00) * 1000;
      usleep_range_state(uVar1 & 0xfffffff8,(int)uVar1 + 2000,2);
      mutex_lock(&DAT_00105708);
      DAT_00105778 = 3;
      InstructionSynchronizationBarrier();
      uVar1 = cntvct_el0;
      if ((DAT_001058b0 != DAT_001057b8) || (DAT_00105780 <= uVar1)) break;
    }
  }
  set_qos_latency(0x7fffffff);
  DAT_001058b0 = 0x7fffffff;
  DAT_00105778 = 4;
  mutex_unlock(&DAT_00105708);
  return;
}



//------------------------------------------------------------
// set_qos_latency @ 00102478 size=324
// signature: undefined set_qos_latency(void)
// callers: [process_delayed_rm_request, cleanup_module, process_cdsp_request_thread]
//------------------------------------------------------------

void set_qos_latency(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  
  if (DAT_001058ac == '\0') {
    if (DAT_001058a8 == '\0') {
      cpu_latency_qos_add_request(&DAT_00105788,param_1);
      DAT_001058a8 = '\x01';
    }
    else {
      cpu_latency_qos_update_request(&DAT_00105788,param_1);
    }
  }
  else {
    if (DAT_00105918 != 0) {
      lVar4 = 0;
      uVar5 = 0;
      do {
        uVar1 = *(undefined4 *)(DAT_00105910 + uVar5 * 4);
        if (DAT_001058a8 == '\0') {
          uVar3 = get_cpu_device(uVar1);
          iVar2 = dev_pm_qos_add_request(uVar3,DAT_00105920 + lVar4,1,param_1);
        }
        else {
          iVar2 = dev_pm_qos_update_request(DAT_00105920 + lVar4,param_1);
        }
        if (iVar2 < 0) {
          lVar4 = sp_el0;
          _printk(&DAT_00107a9e,lVar4 + 0x848,"set_qos_latency",uVar1,iVar2,DAT_001058a8);
          return;
        }
        uVar5 = uVar5 + 1;
        lVar4 = lVar4 + 0x50;
      } while (uVar5 < DAT_00105918);
    }
    DAT_001058a8 = '\x01';
  }
  return;
}



//------------------------------------------------------------
// cdsp_rm_driver_probe @ 001025c0 size=1732
// signature: undefined cdsp_rm_driver_probe(void)
// callers: []
//------------------------------------------------------------

int cdsp_rm_driver_probe(long param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  ulong uVar5;
  char *pcVar6;
  ulong uVar7;
  uint uVar8;
  ulong uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  local_70 = 0;
  lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,qos-cores",0);
  DAT_001058ac = lVar4 != 0;
  if ((lVar4 != 0) &&
     (of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,qos-cores",&DAT_00105918),
     DAT_00105918 != 0)) {
    uVar8 = DAT_00105918 & 0xfffffffc;
    DAT_00105918 = DAT_00105918 >> 2;
    lVar4 = __kmalloc(uVar8,0xdc0);
    if (lVar4 == 0) {
      pcVar6 = "kcalloc failed for cpucores\n";
    }
    else {
      if (DAT_00105918 != 0) {
        uVar8 = 0;
        do {
          iVar2 = of_property_read_u32_index
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,qos-cores",uVar8,
                             lVar4 + (long)(int)uVar8 * 4);
          if (iVar2 != 0) {
            _dev_err(param_1 + 0x10,"%s: failed to read QOS coree for core:%d\n","qos_cores_init",
                     uVar8);
            DAT_001058ac = 0;
          }
          uVar8 = uVar8 + 1;
        } while (uVar8 < DAT_00105918);
      }
      DAT_00105910 = lVar4;
      DAT_00105920 = __kmalloc((ulong)DAT_00105918 * 0x50,0xdc0);
      if (DAT_00105920 != 0) goto LAB_001026f4;
      pcVar6 = "kcalloc failed for dev_pm_qos_req\n";
    }
    _dev_err(param_1 + 0x10,pcVar6);
    DAT_001058ac = 0;
  }
LAB_001026f4:
  iVar2 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,qos-latency-us",&DAT_001057b8,1,0);
  if ((-1 < iVar2) &&
     (iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,qos-maxhold-ms",&DAT_001057bc,1,0),
     -1 < iVar2)) {
    DAT_001058c0 = debugfs_create_dir("compute",0);
    if (DAT_001058c0 == 0) {
      _dev_err(param_1 + 0x10,"Failed to create debugfs directory for cdsprm\n");
    }
    DAT_001057c0 = 4;
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"qcom,compute-priority-mode",&DAT_001057c0,1,0);
    lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,compute-cx-limit-en",0);
    DAT_001057f8 = lVar4 != 0;
    if (((lVar4 != 0) && (DAT_001058c0 != 0)) &&
       (DAT_001058c8 = debugfs_create_file("priority",0x1a4,DAT_001058c0,0,&cdsprm_debugfs_fops),
       DAT_001058c8 == 0)) {
      debugfs_remove(DAT_001058c0);
      _dev_err(param_1 + 0x10,"Failed to create debugfs file\n");
    }
    of_property_read_variable_u32_array
              (*(undefined8 *)(param_1 + 0x2f8),"#cooling-cells",&local_70,1,0);
    if ((int)local_70 != 0) {
      uVar5 = thermal_of_cooling_device_register
                        (*(undefined8 *)(param_1 + 0x2f8),&DAT_001071cd,0,&cdsp_cooling_ops);
      if (0xfffffffffffff000 < uVar5) {
        _dev_err(param_1 + 0x10,"CDSP thermal driver reg failed\n");
      }
      DAT_00105898 = uVar5;
    }
    DAT_001058aa = 1;
    lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-info",0);
    DAT_00104db4 = (uint)(lVar4 != 0);
    if (lVar4 == 0) {
LAB_00102a3c:
      lVar4 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,resmgr-pdkill-enable",0);
      DAT_00104db8 = (uint)(lVar4 != 0);
      DAT_00104dbc = DAT_00104db8;
      if (DAT_001058c0 != 0) {
        DAT_001058d8 = debugfs_create_file("resmgr_pdkill_override_state",0x1a4,DAT_001058c0,0,
                                           &cdsprm_resmgr_pdkill_debugfs_fops);
        if (DAT_001058d8 == 0) {
          _dev_err(param_1 + 0x10,"Failed to create resmgr debugfs file\n");
        }
        DAT_001058e0 = debugfs_create_file("resmgr_pdkill_state",0x124,DAT_001058c0,0,
                                           &cdsprm_resmgr_pdkill_state_fops);
        if (DAT_001058e0 == 0) {
          _dev_err(param_1 + 0x10,"Failed to create resmgr debugfs file\n");
        }
        DAT_001058e8 = debugfs_create_file("dcvs_clients",0x124,DAT_001058c0,0,&dcvs_clients_fops);
        if (DAT_001058e8 == 0) {
          _dev_err(param_1 + 0x10,"Failed to create dcvs_clients_show file\n");
        }
      }
      iVar2 = 0;
      goto LAB_00102c24;
    }
    iVar2 = of_property_count_elems_of_size
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-info",4);
    uVar8 = iVar2 / 3;
    DAT_001055bc = (byte)uVar8;
    if (iVar2 == uVar8 * 3) {
      if ((uVar8 & 0xff) != 0) {
        uVar5 = 0;
        lVar4 = -0x30;
        puVar11 = &DAT_001055c8;
        do {
          iVar10 = (int)lVar4;
          iVar2 = of_property_read_u32_index
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-info",
                             iVar10 + 0x30,(long)&local_70 + 4);
          if (iVar2 != 0) goto LAB_00102b14;
          if (lVar4 == 0) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102c80);
            (*pcVar1)();
          }
          *(char *)(puVar11 + -2) = (char)((ulong)local_70 >> 0x20);
          if ((int)uVar8 <= (int)(local_70._4_4_ & 0xff)) {
            pcVar6 = "partition id is invalid: %d\n";
            goto LAB_00102c1c;
          }
          iVar2 = of_property_read_u32_index
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-info",
                             iVar10 + 0x31,(long)&local_70 + 4);
          if (iVar2 != 0) {
LAB_00102b14:
            pcVar6 = "Error reading partition element %d :%d\n";
            goto LAB_00102b7c;
          }
          puVar11[-1] = local_70._4_4_;
          iVar2 = of_property_read_u32_index
                            (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-info",
                             iVar10 + 0x32,(long)&local_70 + 4);
          if (iVar2 != 0) goto LAB_00102b14;
          uVar5 = uVar5 + 1;
          lVar4 = lVar4 + 3;
          *puVar11 = local_70._4_4_;
          puVar11 = puVar11 + 3;
        } while (uVar5 < DAT_001055bc);
      }
      uVar3 = of_property_count_elems_of_size
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-map",4);
      uVar8 = uVar3;
      if ((int)uVar3 < 0) {
        uVar8 = uVar3 + 1;
      }
      uVar8 = (int)uVar8 >> 1;
      DAT_001055bd = (byte)uVar8;
      if ((uVar3 & 1) == 0) {
        if ((uVar8 & 0xff) != 0) {
          uVar5 = 0;
          uVar9 = 0;
          do {
            iVar2 = of_property_read_u32_index
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-map",
                               uVar9 & 0xffffffff,(long)&local_70 + 4);
            if (iVar2 != 0) {
LAB_00102b68:
              pcVar6 = "Error reading map element %d :%d\n";
LAB_00102b7c:
              _dev_err(param_1 + 0x10,pcVar6,uVar5 & 0xffffffff,local_70._4_4_);
              goto LAB_00102c24;
            }
            (&DAT_00105680)[uVar9] = (char)((ulong)local_70 >> 0x20);
            iVar2 = of_property_read_u32_index
                              (*(undefined8 *)(param_1 + 0x2f8),"qcom,vtcm-partition-map",
                               (int)uVar9 + 1,(long)&local_70 + 4);
            if (iVar2 != 0) goto LAB_00102b68;
            uVar7 = (ulong)DAT_001055bd;
            uVar5 = uVar5 + 1;
            (&DAT_00105681)[uVar9] = (char)((ulong)local_70 >> 0x20);
            uVar9 = uVar9 + 2;
          } while (uVar5 < uVar7);
        }
        if ((DAT_001058c0 == 0) &&
           (DAT_001058c0 = debugfs_create_dir("compute",0), DAT_001058c0 == 0)) {
          _dev_err(param_1 + 0x10,"Failed to find debugfs directory for cdsprm\n",0);
        }
        else {
          DAT_001058d0 = debugfs_create_file("vtcm_partition_state",0x1a4,DAT_001058c0,0,
                                             &cdsprmvtcm_debugfs_fops);
        }
        if (DAT_001058d0 == 0 && DAT_001058c8 == 0) {
          debugfs_remove(DAT_001058c0);
          _dev_err(param_1 + 0x10,"Failed to create debugfs file\n");
        }
        goto LAB_00102a3c;
      }
      pcVar6 = "Maps to have %d elements each entry\n";
    }
    else {
      pcVar6 = "Maps are expected to have %d elements each entry\n";
    }
LAB_00102c1c:
    _dev_err(param_1 + 0x10,pcVar6,uVar8);
  }
  iVar2 = -0x16;
LAB_00102c24:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cdsprm_debugfs_fops_open @ 00102c88 size=52
// signature: undefined cdsprm_debugfs_fops_open(void)
// callers: []
//------------------------------------------------------------

void cdsprm_debugfs_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,cdsprm_compute_prio_read,cdsprm_compute_prio_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// cdsprm_compute_prio_read @ 00102cc0 size=20
// signature: undefined cdsprm_compute_prio_read(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_compute_prio_read(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_001057c0;
  return 0;
}



//------------------------------------------------------------
// cdsprm_compute_prio_write @ 00102cd8 size=132
// signature: undefined cdsprm_compute_prio_write(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_compute_prio_write(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 local_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  DAT_001057c0 = param_2;
  if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
    local_28 = 3;
    local_20 = 0xc;
    uStack_24 = param_2;
    rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_28,0xc);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// cdsp_get_max_state @ 00102d60 size=16
// signature: undefined cdsp_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsp_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 10;
  return 0;
}



//------------------------------------------------------------
// cdsp_get_cur_state @ 00102d74 size=20
// signature: undefined cdsp_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsp_get_cur_state(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_00105890;
  return 0;
}



//------------------------------------------------------------
// cdsp_set_cur_state @ 00102d8c size=216
// signature: undefined cdsp_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsp_set_cur_state(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (DAT_00105890 != param_2) {
    local_40 = 0;
    local_48 = 0;
    mutex_lock(&DAT_00105860);
    if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
      local_40 = 0xc;
      local_48._6_2_ = (undefined2)param_2;
      local_48._0_6_ = CONCAT24((short)DAT_00105894,10);
      iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      if (iVar2 == 0) {
        DAT_00105890 = (uint)param_2;
      }
    }
    mutex_unlock(&DAT_00105860);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// cdsprmvtcm_debugfs_fops_open @ 00102e68 size=52
// signature: undefined cdsprmvtcm_debugfs_fops_open(void)
// callers: []
//------------------------------------------------------------

void cdsprmvtcm_debugfs_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,cdsprm_vtcm_partition_state_read,
                   cdsprm_vtcm_partition_state_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// cdsprm_vtcm_partition_state_read @ 00102ea0 size=20
// signature: undefined cdsprm_vtcm_partition_state_read(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_vtcm_partition_state_read(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_00104db0;
  return 0;
}



//------------------------------------------------------------
// cdsprm_vtcm_partition_state_write @ 00102eb8 size=64
// signature: undefined cdsprm_vtcm_partition_state_write(void)
// callers: []
//------------------------------------------------------------

undefined4 cdsprm_vtcm_partition_state_write(undefined8 param_1,ulong param_2)

{
  undefined4 uVar1;
  
  cdsprm_compute_vtcm_set_partition_map(param_2 & 0xffffffff);
  uVar1 = 0;
  if (DAT_00104db0 != param_2) {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_debugfs_fops_open @ 00102efc size=52
// signature: undefined cdsprm_resmgr_pdkill_debugfs_fops_open(void)
// callers: []
//------------------------------------------------------------

void cdsprm_resmgr_pdkill_debugfs_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,cdsprm_resmgr_pdkill_override_read,
                   cdsprm_resmgr_pdkill_override_write,"%llu\n");
  return;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_override_read @ 00102f34 size=20
// signature: undefined cdsprm_resmgr_pdkill_override_read(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_resmgr_pdkill_override_read(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_00104dc0;
  return 0;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_override_write @ 00102f4c size=248
// signature: undefined cdsprm_resmgr_pdkill_override_write(void)
// callers: []
//------------------------------------------------------------

ulong cdsprm_resmgr_pdkill_override_write(undefined8 param_1,ulong param_2)

{
  long lVar1;
  ulong uVar2;
  undefined *puVar3;
  ulong uVar4;
  undefined8 local_150;
  undefined4 local_148;
  undefined4 uStack_144;
  undefined1 auStack_140 [264];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  memset(auStack_140,0,0x104);
  uVar4 = 0xffffffea;
  if ((DAT_00105770 != 0) && (2 < gcdsprm)) {
    local_148 = 0x10;
    local_150 = 0x200000114;
    uStack_144 = (int)param_2;
    uVar2 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_150,0x114);
    uVar4 = uVar2 & 0xffffffff;
    if ((int)uVar2 == 0) {
      puVar3 = &DAT_00107bb8;
      uVar2 = param_2 & 0xffffffff;
      DAT_00104dbc = (int)param_2;
    }
    else {
      puVar3 = &DAT_00106de5;
      uVar2 = uVar4;
    }
    _printk(puVar3,uVar2);
  }
  _printk(&DAT_00107872,param_2,uVar4);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_state_open @ 00103048 size=48
// signature: undefined cdsprm_resmgr_pdkill_state_open(void)
// callers: []
//------------------------------------------------------------

void cdsprm_resmgr_pdkill_state_open(long param_1,undefined8 param_2)

{
  single_open(param_2,cdsprm_resmgr_pdkill_state_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// cdsprm_resmgr_pdkill_state_show @ 0010307c size=100
// signature: undefined cdsprm_resmgr_pdkill_state_show(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_resmgr_pdkill_state_show(undefined8 param_1)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = "\nresmgr pdkill feature is disabled\n";
  if (DAT_00104db8 != 0) {
    pcVar1 = "\nresmgr pdkill feature is disabled by debugfs override\n";
  }
  pcVar2 = "\nresmgr pdkill feature is enabled by debugfs override\n";
  if (DAT_00104db8 != 0) {
    pcVar2 = "\nresmgr pdkill feature is enabled\n";
  }
  if (DAT_00104dc0 != 0) {
    pcVar1 = pcVar2;
  }
  seq_puts(param_1,pcVar1);
  return 0;
}



//------------------------------------------------------------
// dcvs_clients_open @ 001030e4 size=48
// signature: undefined dcvs_clients_open(void)
// callers: []
//------------------------------------------------------------

void dcvs_clients_open(long param_1,undefined8 param_2)

{
  single_open(param_2,dcvs_clients_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// dcvs_clients_show @ 00103118 size=96
// signature: undefined dcvs_clients_show(void)
// callers: []
//------------------------------------------------------------

undefined8 dcvs_clients_show(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = cdsprm_sysmon_dcvs_clients_votes(0,1);
  if (iVar1 == 0) {
    seq_puts(param_1,"Check kernel log for cdsprm_sysmon_dcvs_clients_votes() output\n");
  }
  else {
    seq_printf(param_1,"cdsprm_sysmon_dcvs_clients_votes() failed. Error : %d\n",iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// hvx_rm_driver_probe @ 0010317c size=192
// signature: undefined hvx_rm_driver_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 hvx_rm_driver_probe(long param_1)

{
  long lVar1;
  ulong uVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  of_property_read_variable_u32_array
            (*(undefined8 *)(param_1 + 0x2f8),"#cooling-cells",&local_2c,1,0);
  if (local_2c != 0) {
    uVar2 = thermal_of_cooling_device_register
                      (*(undefined8 *)(param_1 + 0x2f8),&DAT_00107044,0,&hvx_cooling_ops);
    if (0xfffffffffffff000 < uVar2) {
      _dev_err(param_1 + 0x10,"HVX thermal driver reg failed\n");
    }
    DAT_001058a0 = uVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// hvx_get_max_state @ 00103240 size=16
// signature: undefined hvx_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 hvx_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 10;
  return 0;
}



//------------------------------------------------------------
// hvx_get_cur_state @ 00103254 size=20
// signature: undefined hvx_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 hvx_get_cur_state(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_00105894;
  return 0;
}



//------------------------------------------------------------
// hvx_set_cur_state @ 0010326c size=216
// signature: undefined hvx_set_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 hvx_set_cur_state(undefined8 param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (DAT_00105894 != param_2) {
    local_40 = 0;
    local_48 = 0;
    mutex_lock(&DAT_00105860);
    if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
      local_48 = CONCAT44((uint)param_2 & 0xffff,10);
      local_40 = 0xc;
      local_48 = CONCAT26((short)DAT_00105890,(undefined6)local_48);
      iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      if (iVar2 == 0) {
        DAT_00105894 = (uint)param_2;
      }
    }
    mutex_unlock(&DAT_00105860);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// cdsprm_rpmsg_probe @ 00103348 size=68
// signature: undefined cdsprm_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 cdsprm_rpmsg_probe(long param_1)

{
  of_platform_populate(*(undefined8 *)(param_1 + 0x2e8),0,0,param_1);
  DAT_00105770 = param_1;
  return 0;
}



//------------------------------------------------------------
// cdsprm_rpmsg_remove @ 00103390 size=152
// signature: undefined cdsprm_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void cdsprm_rpmsg_remove(void)

{
  code *pcVar1;
  
  DAT_00105770 = 0;
  gcdsprm = 0;
  if (DAT_001057f8 != '\0') {
    mutex_lock(&DAT_001057c8);
    complete_all(&DAT_00105810);
    complete_all(&DAT_00105830);
    mutex_unlock(&DAT_001057c8);
    DAT_00105908 = DAT_00105900;
    if ((DAT_0010585c < 8) && (DAT_00105900 != (code *)0x0)) {
      if (*(int *)(DAT_00105900 + -4) != -0x137bf691) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103414);
        (*pcVar1)();
      }
      (*DAT_00105900)(8);
    }
  }
  return;
}



//------------------------------------------------------------
// cdsprm_rpmsg_callback @ 0010342c size=928
// signature: undefined cdsprm_rpmsg_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

undefined8 cdsprm_rpmsg_callback(undefined8 param_1,uint *param_2,uint param_3)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  uint uVar4;
  long lVar5;
  undefined *puVar6;
  code *pcVar7;
  ulong uVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  ulong uVar11;
  
  if ((param_2 == (uint *)0x0) || (param_3 < 0x14)) {
    uVar10 = 0x14;
LAB_0010366c:
    _dev_err(param_1,"Invalid message in rpmsg callback, length: %d, expected: >= %lu\n",param_3,
             uVar10);
    return 0xffffffea;
  }
  uVar4 = *param_2;
  if (uVar4 < 0x15) {
    if ((uVar4 != 2) || (DAT_001058aa == '\0')) goto LAB_00103498;
  }
  else {
    if (param_2[1] != param_3) {
      uVar10 = 0xe20;
      goto LAB_0010366c;
    }
LAB_00103498:
    if (uVar4 == 9) {
      if (DAT_001057f8 == '\0') {
switchD_00103698_caseD_d:
        _dev_err(param_1,"Received incorrect msg feature %d\n");
        return 0;
      }
      DAT_00105858 = param_2[1];
      if (DAT_00105808 == 0) {
        return 0;
      }
      puVar9 = &DAT_00105830;
      goto LAB_00103740;
    }
    if (uVar4 == 1) {
      uVar10 = _raw_spin_lock_irqsave(&DAT_00105738);
      DAT_001058f8 = DAT_001058f0;
      _raw_spin_unlock_irqrestore(&DAT_00105738,uVar10);
      if (DAT_001058f8 == 0) {
        return 0;
      }
    }
    else if ((uVar4 != 5) || (DAT_001057f8 == '\0')) {
      if ((uVar4 == 7) && (DAT_001057f8 != '\0')) {
        if (DAT_00105804 == 0) {
          return 0;
        }
        puVar9 = &DAT_00105810;
LAB_00103740:
        complete(puVar9);
        return 0;
      }
      switch(uVar4) {
      case 0xc:
        gcdsprm = param_2[1];
        break;
      default:
        goto switchD_00103698_caseD_d;
      case 0xe:
        if (param_2[1] == 0) {
          DAT_00104db0 = 1;
          return 0;
        }
        DAT_00104db0 = 0;
        return 0;
      case 0x11:
        if (param_2[1] == 0) {
          DAT_00104dc0 = DAT_00104dbc;
          return 0;
        }
        return 0;
      case 0x15:
        memset(&DAT_00105928,0,0xe08);
        uVar4 = param_2[1];
        if (0xe28 < uVar4) {
          fortify_panic("memcpy");
          UnkSytemRegRead(3,3,0xe,0,6);
          UnkSytemRegRead(3,3,0xe,0,6);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        if ((0xe08 < uVar4) && ((cdsprm_rpmsg_callback___already_done & 1) == 0)) {
          cdsprm_rpmsg_callback___already_done = 1;
          __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                        ,(ulong)uVar4,
                        "field \"&gcdsprm.dcvs_clients_votes\" at drivers/soc/qcom/cdsprm.c:1133",
                        0xe08);
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x800,0x1037a8);
          (*pcVar7)();
        }
        memcpy(&DAT_00105928,param_2 + 6,(ulong)uVar4);
        puVar9 = &DAT_00106730;
        goto LAB_00103740;
      }
    }
  }
  uVar10 = _raw_spin_lock_irqsave(0x10573c);
  if (0x31 < DAT_001056c0) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x1037b4);
    (*pcVar7)();
  }
  uVar11 = (ulong)DAT_001056c0 * 0x28;
  if (uVar11 < 0x1945) {
    if ((&DAT_00104e0c)[uVar11] != '\0') {
      _raw_spin_unlock_irqrestore(0x10573c,uVar10);
      return 0xfffffff4;
    }
    if (uVar11 < 0x1945) {
      lVar5 = (ulong)DAT_001056c0 * 0x28;
      (&DAT_00104e0c)[uVar11] = '\x01';
      puVar6 = PTR_cdsprm_list_00108018;
      uVar2 = *(undefined8 *)param_2;
      uVar3 = *(undefined8 *)(param_2 + 2);
      puVar1 = (undefined8 *)(&DAT_00104de8 + uVar11);
      *(uint *)(&DAT_00104e08 + lVar5) = param_2[4];
      *(undefined8 *)(&DAT_00104df8 + lVar5) = uVar2;
      *(undefined8 *)(&DAT_00104e00 + lVar5) = uVar3;
      uVar4 = 0;
      if (DAT_001056c0 < 0x31) {
        uVar4 = DAT_001056c0 + 1;
      }
      DAT_001056c0 = uVar4;
      uVar8 = __list_add_valid(puVar1,puVar6,&cdsprm_list);
      if ((uVar8 & 1) != 0) {
        PTR_cdsprm_list_00108018 = (undefined *)puVar1;
        if ((0x1968 < uVar11) || (*puVar1 = &cdsprm_list, 0x1960 < uVar11)) goto LAB_001037ac;
        *(undefined **)(&DAT_00104df0 + uVar11) = puVar6;
        *(undefined8 **)puVar6 = puVar1;
      }
      _raw_spin_unlock_irqrestore(0x10573c,uVar10);
      __wake_up(cdsprm_wq,1,1,0);
      return 0;
    }
  }
LAB_001037ac:
                    /* WARNING: Does not return */
  pcVar7 = (code *)SoftwareBreakpoint(1,0x1037b0);
  (*pcVar7)();
}



//------------------------------------------------------------
// init_module @ 00104784 size=644
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  ulong uVar2;
  undefined *puVar3;
  
  __mutex_init(&DAT_00105708,"&gcdsprm.rm_lock",&cdsprm_init___key);
  __mutex_init(&DAT_00105740,"&gcdsprm.rpmsg_lock",&cdsprm_init___key_114);
  __mutex_init(&DAT_001057c8,"&gcdsprm.npu_activity_lock",&cdsprm_init___key_116);
  __mutex_init(&DAT_00105860,"&gcdsprm.thermal_lock",&cdsprm_init___key_118);
  DAT_00105738 = 0;
  DAT_00104dc8 = 0;
  __init_swait_queue_head(&DAT_00104dd0,"&x->wait",&init_completion___key);
  DAT_00105810 = 0;
  __init_swait_queue_head(&DAT_00105818,"&x->wait",&init_completion___key);
  DAT_00105830 = 0;
  __init_swait_queue_head(&DAT_00105838,"&x->wait",&init_completion___key);
  uVar2 = kthread_create_on_node(process_cdsp_request_thread,0,0xffffffff,"cdsprm-wq");
  if (uVar2 < 0xfffffffffffff001) {
    wake_up_process(uVar2);
    DAT_001056c8 = uVar2;
    DAT_001056d0 = alloc_workqueue(&DAT_00106d12,0xe000a,1,"cdsprm-wq-delay");
    if (DAT_001056d0 == 0) {
      _printk(&DAT_0010695a);
      iVar1 = -0xc;
    }
    else {
      DAT_001056d8 = 0xfffffffe0;
      DAT_001056e0 = &DAT_001056e0;
      DAT_001056e8 = &DAT_001056e0;
      DAT_001056f0 = process_delayed_rm_request;
      iVar1 = __platform_driver_register(&cdsp_rm,&__this_module);
      if (iVar1 == 0) {
        DAT_001058b4 = 1;
        DAT_00106730 = 0;
        __init_swait_queue_head(&DAT_00106738,"&x->wait",&init_completion___key);
        iVar1 = __platform_driver_register(&hvx_rm,&__this_module);
        if (iVar1 == 0) {
          DAT_001058b8 = 1;
          iVar1 = __register_rpmsg_driver(&cdsprm_rpmsg_client,&__this_module);
          if (iVar1 == 0) {
            DAT_001058a9 = 1;
            _printk(&DAT_00107081);
            return 0;
          }
          puVar3 = &DAT_00106b30;
        }
        else {
          puVar3 = &DAT_00107811;
        }
      }
      else {
        puVar3 = &DAT_00106fde;
      }
      _printk(puVar3,iVar1);
      destroy_workqueue(DAT_001056d0);
    }
    kthread_stop(DAT_001056c8);
  }
  else {
    DAT_001056c8 = uVar2;
    _printk(&DAT_001075e1);
    iVar1 = -0xc;
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00104a0c size=896
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cleanup_module(void)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 local_48;
  undefined4 local_40;
  undefined8 local_38;
  undefined4 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_48 = 0;
  _printk(&DAT_001079ec);
  if (DAT_001058a8 != '\0') {
    set_qos_latency(0x7fffffff);
    DAT_001058b0 = 0x7fffffff;
  }
  if (DAT_001058a0 != 0) {
    thermal_cooling_device_unregister();
  }
  if (DAT_00105898 != 0) {
    thermal_cooling_device_unregister();
  }
  if (DAT_001057f8 != '\0') {
    mutex_lock(&DAT_001057c8);
    complete_all(&DAT_00105810);
    complete_all(&DAT_00105830);
    mutex_unlock(&DAT_001057c8);
    DAT_00105908 = DAT_00105900;
    if ((DAT_0010585c < 8) && (DAT_00105900 != (code *)0x0)) {
      if (*(int *)(DAT_00105900 + -4) != -0x137bf691) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x104ae8);
        (*pcVar2)();
      }
      (*DAT_00105900)(8);
    }
  }
  if ((gcdsprm != 0) && (DAT_001057f8 != '\0')) {
    if (DAT_001057fc != 0) {
      local_48 = 6;
      local_40 = 0xc;
      rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      DAT_001057fc = 0;
    }
    if (DAT_00105854 != 0) {
      local_48 = 8;
      local_40 = 0xc;
      rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      DAT_00105854 = 0;
    }
    if (DAT_00105800 != 0) {
      local_48 = 0xb;
      local_40 = 0xc;
      rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_48,0xc);
      DAT_00105800 = 0;
    }
  }
  complete_all(&DAT_00106730);
  if (DAT_00105890 == 0) {
    if (DAT_00105894 != 0) {
      local_30 = 0;
      local_38 = 0;
      mutex_lock(&DAT_00105860);
      if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
        local_30 = 0xc;
        local_38 = CONCAT26((short)DAT_00105890,10);
        iVar3 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_38,0xc);
        if (iVar3 == 0) {
          DAT_00105894 = 0;
        }
      }
      mutex_unlock(&DAT_00105860);
      DAT_00105894 = 0;
    }
  }
  else {
    local_30 = 0;
    local_38 = 0;
    mutex_lock(&DAT_00105860);
    if ((DAT_00105770 != 0) && (gcdsprm != 0)) {
      local_30 = 0xc;
      local_38 = (ulong)CONCAT24((short)DAT_00105894,10);
      iVar3 = rpmsg_send(*(undefined8 *)(DAT_00105770 + 0x3c8),&local_38,0xc);
      if (iVar3 == 0) {
        DAT_00105890 = 0;
      }
    }
    mutex_unlock(&DAT_00105860);
    DAT_00105890 = 0;
  }
  if (DAT_001058a9 != '\0') {
    unregister_rpmsg_driver(&cdsprm_rpmsg_client);
    DAT_00105770 = 0;
    gcdsprm = 0;
  }
  if (DAT_001056c8 != 0) {
    kthread_stop();
  }
  if (DAT_001056d0 != 0) {
    destroy_workqueue();
  }
  if (DAT_001058b4 != 0) {
    platform_driver_unregister(&cdsp_rm);
  }
  if (DAT_001058b8 != 0) {
    platform_driver_unregister(&hvx_rm);
  }
  debugfs_remove(DAT_001058c0);
  DAT_001058a9 = 0;
  _DAT_001058b4 = 0;
  DAT_00105898 = 0;
  DAT_001058a0 = 0;
  DAT_001058c0 = 0;
  DAT_001058c8 = 0;
  DAT_001058d0 = 0;
  DAT_001058d8 = 0;
  DAT_001058e0 = 0;
  _printk(&DAT_00107048);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cdsprm_register_cdspl3gov, cdsprm_rpmsg_callback, process_cdsp_request_thread, cdsprm_unregister_cdspl3gov]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cdsprm_register_cdspl3gov, cdsprm_rpmsg_callback, process_cdsp_request_thread, cdsprm_unregister_cdspl3gov]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 0010a010 size=1
// signature: undefined rpmsg_send(void)
// callers: [cdsprm_compute_core_set_priority, cdsprm_cxlimit_npu_corner_notify, hvx_set_cur_state, cdsprm_cxlimit_npu_activity_notify, process_cdsp_request_thread, cdsprm_resmgr_pdkill_config, cdsprm_sysmon_dcvs_clients_votes, cdsprm_compute_prio_write, cleanup_module, cdsprm_resmgr_pdkill_override_write, cdsp_set_cur_state, cdsprm_cxlimit_camera_activity_notify, cdsprm_compute_vtcm_set_partition_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a018 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cdsprm_compute_core_set_priority, cdsprm_cxlimit_npu_corner_notify, hvx_set_cur_state, cdsprm_cxlimit_npu_activity_notify, process_cdsp_request_thread, cdsprm_resmgr_pdkill_config, cdsprm_sysmon_dcvs_clients_votes, cdsprm_compute_prio_write, hvx_rm_driver_probe, cleanup_module, cdsprm_resmgr_pdkill_override_write, cdsp_rm_driver_probe, cdsp_set_cur_state, cdsprm_cxlimit_camera_activity_notify, cdsprm_compute_vtcm_set_partition_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a020 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [cdsprm_rpmsg_callback, cdsprm_resmgr_pdkill_override_write, process_cdsp_request_thread, cdsprm_resmgr_pdkill_config, cdsprm_sysmon_dcvs_clients_votes, cdsprm_compute_vtcm_set_partition_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a028 size=1
// signature: undefined _printk(void)
// callers: [set_qos_latency, cleanup_module, cdsprm_resmgr_pdkill_override_write, process_cdsp_request_thread, cdsprm_resmgr_pdkill_config, cdsprm_sysmon_dcvs_clients_votes, init_module, cdsprm_compute_vtcm_set_partition_map]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a030 size=1
// signature: undefined mutex_lock(void)
// callers: [process_delayed_rm_request, cdsprm_cxlimit_npu_corner_notify, hvx_set_cur_state, cleanup_module, cdsprm_rpmsg_remove, cdsprm_cxlimit_npu_activity_notify, process_cdsp_request_thread, cdsp_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a038 size=1
// signature: undefined mutex_unlock(void)
// callers: [process_delayed_rm_request, cdsprm_cxlimit_npu_corner_notify, hvx_set_cur_state, cleanup_module, cdsprm_rpmsg_remove, cdsprm_cxlimit_npu_activity_notify, process_cdsp_request_thread, cdsp_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 0010a040 size=1
// signature: undefined wait_for_completion(void)
// callers: [cdsprm_cxlimit_npu_corner_notify, cdsprm_cxlimit_npu_activity_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010a048 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [cdsprm_sysmon_dcvs_clients_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a050 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [cdsprm_rpmsg_callback, cdsprm_sysmon_dcvs_clients_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 0010a058 size=1
// signature: undefined strscpy(void)
// callers: [cdsprm_sysmon_dcvs_clients_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlcat @ 0010a060 size=1
// signature: undefined strlcat(void)
// callers: [cdsprm_sysmon_dcvs_clients_votes]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strlcat(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010a068 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010a070 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0010a078 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0010a080 size=1
// signature: undefined wake_up_process(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010a088 size=1
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
// __platform_driver_register @ 0010a090 size=1
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
// __register_rpmsg_driver @ 0010a098 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 0010a0a0 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 0010a0a8 size=1
// signature: undefined kthread_stop(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 0010a0b0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010a0b8 size=1
// signature: undefined complete_all(void)
// callers: [cleanup_module, cdsprm_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 0010a0c0 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010a0c8 size=1
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
// debugfs_remove @ 0010a0d0 size=1
// signature: undefined debugfs_remove(void)
// callers: [cleanup_module, cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 0010a0d8 size=1
// signature: undefined kthread_should_stop(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010a0e0 size=1
// signature: undefined init_wait_entry(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010a0e8 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010a0f0 size=1
// signature: undefined schedule(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010a0f8 size=1
// signature: undefined finish_wait(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 0010a100 size=1
// signature: undefined __flush_workqueue(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010a108 size=1
// signature: undefined queue_work_on(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010a110 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [process_cdsp_request_thread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010a118 size=1
// signature: undefined usleep_range_state(void)
// callers: [process_delayed_rm_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 0010a120 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [set_qos_latency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 0010a128 size=1
// signature: undefined get_cpu_device(void)
// callers: [set_qos_latency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 0010a130 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [set_qos_latency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_update_request @ 0010a138 size=1
// signature: undefined cpu_latency_qos_update_request(void)
// callers: [set_qos_latency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 0010a140 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [set_qos_latency]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010a148 size=1
// signature: undefined of_find_property(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a150 size=1
// signature: undefined __kmalloc(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 0010a158 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a160 size=1
// signature: undefined _dev_err(void)
// callers: [cdsprm_rpmsg_callback, cdsp_rm_driver_probe, hvx_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a168 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [cdsp_rm_driver_probe, hvx_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 0010a170 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 0010a178 size=1
// signature: undefined debugfs_create_file(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 0010a180 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [cdsp_rm_driver_probe, hvx_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010a188 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [cdsp_rm_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 0010a190 size=1
// signature: undefined simple_attr_open(void)
// callers: [cdsprm_debugfs_fops_open, cdsprmvtcm_debugfs_fops_open, cdsprm_resmgr_pdkill_debugfs_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 0010a198 size=1
// signature: undefined single_open(void)
// callers: [dcvs_clients_open, cdsprm_resmgr_pdkill_state_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 0010a1a0 size=1
// signature: undefined seq_puts(void)
// callers: [cdsprm_resmgr_pdkill_state_show, dcvs_clients_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 0010a1a8 size=1
// signature: undefined seq_printf(void)
// callers: [dcvs_clients_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 0010a1b0 size=1
// signature: undefined of_platform_populate(void)
// callers: [cdsprm_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a1b8 size=1
// signature: undefined __list_add_valid(void)
// callers: [cdsprm_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010a1c0 size=1
// signature: undefined __wake_up(void)
// callers: [cdsprm_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a1c8 size=1
// signature: undefined complete(void)
// callers: [cdsprm_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010a1d0 size=1
// signature: undefined __warn_printk(void)
// callers: [cdsprm_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a1d8 size=1
// signature: undefined fortify_panic(void)
// callers: [cdsprm_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



