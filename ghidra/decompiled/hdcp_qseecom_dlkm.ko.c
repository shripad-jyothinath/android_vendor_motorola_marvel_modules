// Decompiled by Ghidra 12.2
// Program: hdcp_qseecom_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// select_interface @ 0010109c size=396
// signature: undefined select_interface(void)
// callers: [init_module]
//------------------------------------------------------------

void select_interface(ulong param_1)

{
  if ((param_1 & 1) == 0) {
    DAT_00105ba8 = hdcp2_update_app_data_qseecom;
    DAT_00105ba0 = hdcp2_close_stream_qseecom;
    DAT_00105b98 = hdcp2_open_stream_qseecom;
    DAT_00105b90 = hdcp2_force_encryption_qseecom;
    DAT_00105b88 = hdcp2_feature_supported_qseecom;
    DAT_00105b80 = hdcp2_app_stop_qseecom;
    DAT_00105b78 = hdcp2_app_query_stream_qseecom;
    DAT_00105b68 = hdcp2_app_timeout_qseecom;
    DAT_00105b70 = hdcp2_app_enable_encryption_qseecom;
    DAT_00105b60 = hdcp2_app_process_msg_qseecom;
    DAT_00105b58 = hdcp2_app_start_auth_qseecom;
    DAT_00105b50 = hdcp2_app_start_qseecom;
    DAT_00105b48 = hdcp2_deinit_qseecom;
    DAT_00105b40 = hdcp2_init_qseecom;
    DAT_00105b38 = hdcp1_stop_qseecom;
    DAT_00105b30 = hdcp1_start_qseecom;
    DAT_00105b28 = hdcp1_ops_notify_qseecom;
    DAT_00105b20 = hdcp1_set_enc_qseecom;
    DAT_00105b18 = hdcp1_feature_supported_qseecom;
    ta_interface = hdcp1_init_qseecom;
  }
  else {
    DAT_00105ba8 = hdcp2_update_app_data_smcinvoke;
    DAT_00105ba0 = hdcp2_close_stream_smcinvoke;
    DAT_00105b98 = hdcp2_open_stream_smcinvoke;
    DAT_00105b90 = hdcp2_force_encryption_smcinvoke;
    DAT_00105b88 = hdcp2_feature_supported_smcinvoke;
    DAT_00105b80 = hdcp2_app_stop_smcinvoke;
    DAT_00105b78 = hdcp2_app_query_stream_smcinvoke;
    DAT_00105b68 = hdcp2_app_timeout_smcinvoke;
    DAT_00105b70 = hdcp2_app_enable_encryption_smcinvoke;
    DAT_00105b60 = hdcp2_app_process_msg_smcinvoke;
    DAT_00105b58 = hdcp2_app_start_auth_smcinvoke;
    DAT_00105b50 = hdcp2_app_start_smcinvoke;
    DAT_00105b48 = hdcp2_deinit_smcinvoke;
    DAT_00105b40 = hdcp2_init_smcinvoke;
    DAT_00105b38 = hdcp1_stop_smcinvoke;
    DAT_00105b30 = hdcp1_start_smcinvoke;
    DAT_00105b28 = hdcp1_ops_notify_smcinvoke;
    DAT_00105b20 = hdcp1_set_enc_smcinvoke;
    DAT_00105b18 = hdcp1_feature_supported_smcinvoke;
    ta_interface = hdcp1_init_smcinvoke;
  }
  return;
}



//------------------------------------------------------------
// hdcp1_count_ones @ 0010122c size=104
// signature: undefined hdcp1_count_ones(void)
// callers: []
//------------------------------------------------------------

int hdcp1_count_ones(byte *param_1,byte param_2)

{
  byte bVar1;
  int iVar2;
  ulong uVar3;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar2 = 0;
  uVar3 = (ulong)param_2;
  do {
    bVar1 = *param_1;
    uVar3 = uVar3 - 1;
    iVar2 = (bVar1 >> 6 & 1) +
            (bVar1 >> 5 & 1) + (bVar1 >> 4 & 1) + (bVar1 >> 3 & 1) +
            (bVar1 >> 2 & 1) + (bVar1 >> 1 & 1) + (bVar1 & 1) + iVar2 + (uint)(bVar1 >> 7);
    param_1 = param_1 + 1;
  } while (uVar3 != 0);
  return iVar2;
}



//------------------------------------------------------------
// hdcp1_validate_aksv @ 00101298 size=368
// signature: undefined hdcp1_validate_aksv(void)
// callers: [hdcp1_start_smcinvoke, hdcp1_start_qseecom]
//------------------------------------------------------------

undefined8 hdcp1_validate_aksv(uint param_1,uint param_2)

{
  if ((param_1 & 1) +
      (param_2 >> 0x19 & 1) + (param_2 >> 0x1a & 1) + (param_2 >> 0x1b & 1) + (param_2 >> 0x1c & 1)
      + (param_2 >> 0x1d & 1) + (param_2 >> 0x1e & 1) + (param_1 >> 7 & 1) + (param_1 >> 1 & 1) +
      (((param_2 >> 0x18 & 1) + (param_2 >> 0x15 & 1) + (param_2 >> 0x16 & 1) +
       (param_2 >> 0x10 & 1) + (param_2 >> 0x17 & 1) + (param_2 >> 0x11 & 1) + (param_2 >> 0x12 & 1)
       + (param_2 >> 0x13 & 1) + (param_2 >> 0x14 & 1) +
       (param_2 >> 8 & 1) + (param_2 >> 6 & 1) + (param_2 >> 0xf & 1) + (param_2 >> 9 & 1) +
       (param_2 & 1) + (param_2 >> 7 & 1) + (param_2 >> 1 & 1) + (param_2 >> 2 & 1) +
       (param_2 >> 3 & 1) + (param_2 >> 4 & 1) + (param_2 >> 5 & 1) +
       (param_2 >> 10 & 1) + (param_2 >> 0xb & 1) + (param_2 >> 0xc & 1) + (param_2 >> 0xd & 1) +
       (param_2 >> 0xe & 1)) - ((int)param_2 >> 0x1f)) +
      (param_1 >> 2 & 1) + (param_1 >> 3 & 1) + (param_1 >> 4 & 1) + (param_1 >> 5 & 1) +
      (param_1 >> 6 & 1) == 0x14) {
    return 0;
  }
  _printk(&DAT_00105f1c);
  return 0xffffffea;
}



//------------------------------------------------------------
// hdcp2_feature_supported @ 0010140c size=108
// signature: undefined hdcp2_feature_supported(void)
// callers: []
//------------------------------------------------------------

uint hdcp2_feature_supported(undefined8 param_1)

{
  code *pcVar1;
  uint uVar2;
  
  mutex_lock(&hdcp2_mutex_g);
  if (*(int *)(DAT_00105b88 + -4) != -0x672c52fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101454);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b88)(param_1);
  mutex_unlock(&hdcp2_mutex_g);
  return uVar2 & 1;
}



//------------------------------------------------------------
// hdcp2_force_encryption @ 0010147c size=124
// signature: undefined hdcp2_force_encryption(void)
// callers: []
//------------------------------------------------------------

undefined4 hdcp2_force_encryption(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  mutex_lock(&hdcp2_mutex_g);
  if (*(int *)(DAT_00105b90 + -4) != 0x2a7efc50) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1014d0);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b90)(param_1,param_2);
  mutex_unlock(&hdcp2_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp2_app_comm @ 001014fc size=368
// signature: undefined hdcp2_app_comm(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_comm(long param_1,undefined4 param_2,long param_3)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  
  if ((param_1 == 0) || (param_3 == 0)) {
    _printk(&DAT_00106222);
    return -0x16;
  }
  uVar1 = *(undefined4 *)(param_3 + 0x10);
  mutex_lock(&hdcp2_mutex_g);
  switch(param_2) {
  case 0:
    pcVar2 = DAT_00105b50;
    break;
  case 1:
    pcVar2 = DAT_00105b58;
    break;
  case 2:
    if (*(int *)(DAT_00105b80 + -4) != -0x76049ec3) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10159c);
      (*pcVar2)();
    }
    iVar3 = (*DAT_00105b80)(param_1);
    if (iVar3 != 0) goto LAB_00101634;
    goto LAB_00101604;
  case 3:
    pcVar2 = DAT_00105b60;
    break;
  case 4:
    pcVar2 = DAT_00105b68;
    break;
  case 5:
    pcVar2 = DAT_00105b70;
    break;
  case 6:
    pcVar2 = DAT_00105b78;
    break;
  default:
    iVar3 = 0;
    goto LAB_00101634;
  }
  if (*(int *)(pcVar2 + -4) != 0x2a7efc50) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1015f8);
    (*pcVar2)();
  }
  iVar3 = (*pcVar2)(param_1,uVar1);
  if (iVar3 == 0) {
LAB_00101604:
    if (*(int *)(DAT_00105ba8 + -4) != 0x6da65f85) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10162c);
      (*pcVar2)();
    }
    iVar3 = (*DAT_00105ba8)(param_1,param_3);
  }
LAB_00101634:
  mutex_unlock(&hdcp2_mutex_g);
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_open_stream @ 00101670 size=148
// signature: undefined hdcp2_open_stream(void)
// callers: []
//------------------------------------------------------------

undefined4
hdcp2_open_stream(undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  mutex_lock(&hdcp2_mutex_g);
  if (*(int *)(DAT_00105b98 + -4) != 0x3efb5002) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1016d8);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b98)(param_1,param_2,param_3,param_4);
  mutex_unlock(&hdcp2_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp2_close_stream @ 00101708 size=124
// signature: undefined hdcp2_close_stream(void)
// callers: []
//------------------------------------------------------------

undefined4 hdcp2_close_stream(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  mutex_lock(&hdcp2_mutex_g);
  if (*(int *)(DAT_00105ba0 + -4) != 0x2a7efc50) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10175c);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105ba0)(param_1,param_2);
  mutex_unlock(&hdcp2_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp2_init @ 00101788 size=108
// signature: undefined hdcp2_init(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp2_init(undefined4 param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  mutex_lock(&hdcp2_mutex_g);
  if (*(int *)(DAT_00105b40 + -4) != 0x71e196ff) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1017d0);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b40)(param_1);
  mutex_unlock(&hdcp2_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp2_set_hdcp_key_verify_retries @ 001017f8 size=8
// signature: undefined hdcp2_set_hdcp_key_verify_retries(void)
// callers: []
//------------------------------------------------------------

void hdcp2_set_hdcp_key_verify_retries(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x80) = param_2;
  return;
}



//------------------------------------------------------------
// hdcp2_deinit @ 00101804 size=60
// signature: undefined hdcp2_deinit(void)
// callers: []
//------------------------------------------------------------

void hdcp2_deinit(void)

{
  code *pcVar1;
  
  if (*(int *)(DAT_00105b48 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101830);
    (*pcVar1)();
  }
  (*DAT_00105b48)();
  return;
}



//------------------------------------------------------------
// hdcp1_init @ 00101844 size=100
// signature: undefined hdcp1_init(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp1_init(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  mutex_lock(hdcp1_mutex_g);
  if (*(int *)(ta_interface + -4) != -0x5bfd9863) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101884);
    (*pcVar1)();
  }
  uVar2 = (*ta_interface)();
  mutex_unlock(hdcp1_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp1_set_hdcp_key_verify_retries @ 001018ac size=8
// signature: undefined hdcp1_set_hdcp_key_verify_retries(void)
// callers: []
//------------------------------------------------------------

void hdcp1_set_hdcp_key_verify_retries(long param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return;
}



//------------------------------------------------------------
// hdcp1_deinit @ 001018b8 size=28
// signature: undefined hdcp1_deinit(void)
// callers: []
//------------------------------------------------------------

void hdcp1_deinit(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// hdcp1_feature_supported @ 001018d8 size=108
// signature: undefined hdcp1_feature_supported(void)
// callers: []
//------------------------------------------------------------

uint hdcp1_feature_supported(undefined8 param_1)

{
  code *pcVar1;
  uint uVar2;
  
  mutex_lock(hdcp1_mutex_g);
  if (*(int *)(DAT_00105b18 + -4) != -0x672c52fe) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101920);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b18)(param_1);
  mutex_unlock(hdcp1_mutex_g);
  return uVar2 & 1;
}



//------------------------------------------------------------
// hdcp1_set_enc @ 00101948 size=124
// signature: undefined hdcp1_set_enc(void)
// callers: []
//------------------------------------------------------------

undefined4 hdcp1_set_enc(undefined8 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  mutex_lock(hdcp1_mutex_g);
  if (*(int *)(DAT_00105b20 + -4) != -0x7aea7739) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10199c);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b20)(param_1,param_2);
  mutex_unlock(hdcp1_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp1_ops_notify @ 001019c8 size=60
// signature: undefined hdcp1_ops_notify(void)
// callers: []
//------------------------------------------------------------

void hdcp1_ops_notify(void)

{
  code *pcVar1;
  
  if (*(int *)(DAT_00105b28 + -4) != 0xcde3764) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1019f4);
    (*pcVar1)();
  }
  (*DAT_00105b28)();
  return;
}



//------------------------------------------------------------
// hdcp1_start @ 00101a08 size=132
// signature: undefined hdcp1_start(void)
// callers: []
//------------------------------------------------------------

undefined4 hdcp1_start(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  mutex_lock(hdcp1_mutex_g);
  if (*(int *)(DAT_00105b30 + -4) != -0x56f8fbc2) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101a64);
    (*pcVar1)();
  }
  uVar2 = (*DAT_00105b30)(param_1,param_2,param_3);
  mutex_unlock(hdcp1_mutex_g);
  return uVar2;
}



//------------------------------------------------------------
// hdcp1_stop @ 00101a90 size=100
// signature: undefined hdcp1_stop(void)
// callers: []
//------------------------------------------------------------

void hdcp1_stop(undefined8 param_1)

{
  code *pcVar1;
  
  mutex_lock(hdcp1_mutex_g);
  if (*(int *)(DAT_00105b38 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101ad8);
    (*pcVar1)();
  }
  (*DAT_00105b38)(param_1);
  mutex_unlock(hdcp1_mutex_g);
  return;
}



//------------------------------------------------------------
// hdcp1_init_qseecom @ 00101af8 size=60
// signature: undefined hdcp1_init_qseecom(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hdcp1_init_qseecom(void)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_kfree_sensitive,0xdc0,0x30);
  if (lVar1 != 0) {
    *(char **)(lVar1 + 0x20) = "hdcp1";
  }
  return;
}



//------------------------------------------------------------
// hdcp1_feature_supported_qseecom @ 00101b38 size=392
// signature: undefined hdcp1_feature_supported_qseecom(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp1_feature_supported_qseecom(long *param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  undefined8 uVar5;
  uint uVar6;
  long lVar7;
  
  if (param_1 == (long *)0x0) {
    _printk(&DAT_00106331);
    uVar5 = 0;
  }
  else if ((char)param_1[2] == '\0') {
    iVar1 = hdcp1_app_load(param_1);
    if ((iVar1 == 0) && ((*(byte *)(param_1 + 3) & 1) != 0)) {
      uVar6 = 0;
      do {
        lVar2 = *param_1;
        if (lVar2 == 0) {
          _printk(&DAT_00106b2e);
        }
        else if ((*(byte *)(param_1 + 3) & 1) == 0) {
          _printk(&DAT_00105fba,param_1[4]);
        }
        else {
          puVar4 = *(undefined4 **)(lVar2 + 8);
          *puVar4 = 0xcc;
          lVar7 = *(long *)(lVar2 + 8);
          iVar1 = qseecom_send_command(lVar2,puVar4,0x40,lVar7 + 0x40,0x40);
          if (iVar1 < 0) {
            puVar3 = &DAT_00106818;
          }
          else {
            iVar1 = *(int *)(lVar7 + 0x44);
            qseecomd_down = iVar1 == -0x1007;
            if (iVar1 == 0) {
              uVar5 = 1;
              *(undefined1 *)(param_1 + 2) = 1;
              goto LAB_00101c94;
            }
            puVar3 = &DAT_00106ab0;
          }
          _printk(puVar3,iVar1);
        }
        if (qseecomd_down != 1) goto LAB_00101ca8;
        msleep(100);
        uVar6 = uVar6 + 1;
      } while (uVar6 <= *(uint *)(param_1 + 5));
      if ((qseecomd_down & 1) != 0) {
        _printk(&DAT_00105f77);
      }
LAB_00101ca8:
      uVar5 = 0;
LAB_00101c94:
      hdcp1_app_unload(param_1);
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 1;
  }
  return uVar5;
}



//------------------------------------------------------------
// hdcp1_app_load @ 00101cc0 size=212
// signature: undefined hdcp1_app_load(void)
// callers: [hdcp1_start_qseecom, hdcp1_feature_supported_qseecom]
//------------------------------------------------------------

int hdcp1_app_load(long *param_1)

{
  int iVar1;
  
  if ((hdcp1_qseecom_handle_g == 0) &&
     (iVar1 = qseecom_start_app(&hdcp1_qseecom_handle_g,param_1[4],0x1000), iVar1 != 0)) {
    _printk(&DAT_00105e8c,param_1[4],iVar1);
  }
  else {
    *param_1 = hdcp1_qseecom_handle_g;
    hdcp1_app_started = hdcp1_app_started + 1;
    iVar1 = qseecom_start_app(param_1 + 1,&DAT_00106902,0x1000);
    if (iVar1 != 0) {
      _printk(&DAT_00105cd9,&DAT_00106902,iVar1);
      param_1[1] = 0;
    }
    *(uint *)(param_1 + 3) = *(uint *)(param_1 + 3) | 1;
  }
  return iVar1;
}



//------------------------------------------------------------
// hdcp1_app_unload @ 00101d94 size=220
// signature: undefined hdcp1_app_unload(void)
// callers: [hdcp1_stop_qseecom, hdcp1_start_qseecom, hdcp1_feature_supported_qseecom]
//------------------------------------------------------------

void hdcp1_app_unload(long *param_1)

{
  int iVar1;
  
  if (*param_1 == 0) {
    _printk(&DAT_00106331);
  }
  else if ((*(byte *)(param_1 + 3) & 1) == 0) {
    _printk(&DAT_001062b7,param_1[4]);
  }
  else {
    if ((param_1[1] != 0) && (iVar1 = qseecom_shutdown_app(), iVar1 != 0)) {
      _printk(&DAT_0010604e,&DAT_00106902,iVar1);
    }
    hdcp1_app_started = hdcp1_app_started + -1;
    if (hdcp1_app_started == 0) {
      iVar1 = qseecom_shutdown_app(&hdcp1_qseecom_handle_g);
      if (iVar1 != 0) {
        _printk(&DAT_00106dcd,param_1[4],iVar1);
        return;
      }
      hdcp1_qseecom_handle_g = 0;
    }
    *param_1 = 0;
    *(uint *)(param_1 + 3) = *(uint *)(param_1 + 3) & 0xfffffffe;
  }
  return;
}



//------------------------------------------------------------
// hdcp1_set_enc_qseecom @ 00101e74 size=208
// signature: undefined hdcp1_set_enc_qseecom(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp1_set_enc_qseecom(long *param_1,uint param_2)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  long lVar5;
  
  if ((param_1 == (long *)0x0) || (lVar2 = *param_1, lVar2 == 0)) {
    _printk(&DAT_00106b2e);
  }
  else if ((char)param_1[2] == '\0') {
    _printk(&DAT_001061e0);
  }
  else if ((*(byte *)(param_1 + 3) & 1) == 0) {
    _printk(&DAT_00105fba,param_1[4]);
  }
  else {
    puVar4 = *(undefined4 **)(lVar2 + 8);
    *puVar4 = 0xcd;
    puVar4[1] = param_2 & 1;
    lVar5 = *(long *)(lVar2 + 8);
    iVar1 = qseecom_send_command(lVar2,puVar4,0x40,lVar5 + 0x40,0x40);
    if (iVar1 < 0) {
      puVar3 = &DAT_00106781;
    }
    else {
      iVar1 = *(int *)(lVar5 + 0x44);
      if (iVar1 == 0) {
        return 0;
      }
      puVar3 = &DAT_001060bb;
    }
    _printk(puVar3,iVar1);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// hdcp1_ops_notify_qseecom @ 00101f48 size=276
// signature: undefined hdcp1_ops_notify_qseecom(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp1_ops_notify_qseecom(long param_1,undefined4 *param_2,byte param_3)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 *puVar3;
  long lVar4;
  
  if ((param_1 == 0) || (lVar2 = *(long *)(param_1 + 8), lVar2 == 0)) {
    _printk(&DAT_00106a78);
  }
  else if (*(char *)(param_1 + 0x10) == '\0') {
    _printk(&DAT_001061e0);
  }
  else if ((*(byte *)(param_1 + 0x18) & 1) == 0) {
    _printk(&DAT_00105fba,&DAT_00106902);
  }
  else {
    puVar3 = *(undefined8 **)(lVar2 + 8);
    *puVar3 = 0x800200000001;
    *(byte *)((long)puVar3 + 0xc4) = param_3 & 1;
    *(undefined4 *)((long)puVar3 + 0xac) = *param_2;
    *(undefined4 *)(puVar3 + 0x16) = param_2[1];
    *(undefined4 *)((long)puVar3 + 0xb4) = param_2[2];
    uVar1 = param_2[3];
    *(undefined8 *)((long)puVar3 + 0xbc) = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[8] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
    puVar3[0xc] = 0;
    *(undefined4 *)(puVar3 + 0x17) = uVar1;
    puVar3[0xd] = 0;
    puVar3[0xe] = 0;
    puVar3[0xf] = 0;
    puVar3[0x10] = 0;
    puVar3[0x11] = 0;
    puVar3[0x12] = 0;
    puVar3[0x13] = 0;
    puVar3[0x14] = 0;
    lVar4 = *(long *)(lVar2 + 8);
    qseecom_send_command(lVar2,puVar3,0x100,lVar4 + 0x100,0x40);
    if (-1 < *(int *)(lVar4 + 0x104)) {
      return 0;
    }
    _printk(&DAT_001060d5);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// hdcp1_start_qseecom @ 00102060 size=356
// signature: undefined hdcp1_start_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp1_start_qseecom(long *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  long lVar6;
  
  if ((param_2 == (uint *)0x0) || (param_3 == (uint *)0x0)) {
    puVar4 = &DAT_00105c04;
  }
  else if (param_1 == (long *)0x0) {
    puVar4 = &DAT_00106331;
  }
  else {
    if ((char)param_1[2] != '\0') {
      if ((*(byte *)(param_1 + 3) & 1) != 0) {
        return 0;
      }
      iVar2 = hdcp1_app_load(param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
      lVar3 = *param_1;
      if (lVar3 == 0) {
        _printk(&DAT_00106b2e);
        iVar2 = -0x16;
      }
      else if ((*(byte *)(param_1 + 3) & 1) == 0) {
        _printk(&DAT_00105fba,param_1[4]);
        iVar2 = -0x16;
      }
      else {
        puVar5 = *(undefined4 **)(lVar3 + 8);
        *puVar5 = 0xca;
        lVar6 = *(long *)(lVar3 + 8);
        iVar2 = qseecom_send_command(lVar3,puVar5,0x40,lVar6 + 0x40,0x40);
        if (iVar2 < 0) {
          puVar4 = &DAT_00106781;
        }
        else {
          iVar2 = *(int *)(lVar6 + 0x44);
          if (iVar2 == 0) {
            uVar1 = (*(uint *)(lVar6 + 0x48) & 0xff00ff00) >> 8 |
                    (*(uint *)(lVar6 + 0x48) & 0xff00ff) << 8;
            *param_2 = uVar1 >> 0x10 | uVar1 << 0x10;
            uVar1 = (*(uint *)(lVar6 + 0x4c) & 0xff00ff00) >> 8 |
                    (*(uint *)(lVar6 + 0x4c) & 0xff00ff) << 8;
            *param_3 = uVar1 >> 0x10 | uVar1 << 0x10;
            iVar2 = hdcp1_validate_aksv(*param_2);
            if (iVar2 == 0) {
              return 0;
            }
            _printk(&DAT_001063e9,iVar2);
            goto LAB_001021b8;
          }
          puVar4 = &DAT_00106dea;
        }
        _printk(puVar4,iVar2);
        iVar2 = -0x7e;
      }
LAB_001021b8:
      hdcp1_app_unload(param_1);
      return iVar2;
    }
    puVar4 = &DAT_001066ed;
  }
  _printk(puVar4);
  return -0x16;
}



//------------------------------------------------------------
// hdcp1_stop_qseecom @ 001021c8 size=72
// signature: undefined hdcp1_stop_qseecom(void)
// callers: []
//------------------------------------------------------------

void hdcp1_stop_qseecom(long *param_1)

{
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    _printk(&DAT_00106331);
  }
  else if ((*(byte *)(param_1 + 3) & 1) != 0) {
    hdcp1_app_unload();
  }
  return;
}



//------------------------------------------------------------
// hdcp2_init_qseecom @ 00102214 size=180
// signature: undefined hdcp2_init_qseecom(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long hdcp2_init_qseecom(undefined4 param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = kmalloc_trace(_qseecom_send_command,0xdc0,0x88);
  if (lVar2 != 0) {
    *(undefined4 *)(lVar2 + 0x50) = param_1;
    uVar1 = _fortify_panic;
    *(char **)(lVar2 + 0x58) = "hdcp2p2";
    lVar3 = kmalloc_trace(uVar1,0xcc0,0x1000);
    *(long *)(lVar2 + 0x68) = lVar3;
    if (lVar3 != 0) {
      lVar4 = kmalloc_trace(_fortify_panic,0xcc0,0x1000);
      *(long *)(lVar2 + 0x60) = lVar4;
      if (lVar4 != 0) {
        *(long *)(lVar2 + 8) = lVar4;
        *(long *)(lVar2 + 0x18) = lVar3;
        return lVar2;
      }
      kfree_sensitive(lVar3);
    }
    kfree_sensitive(lVar2);
  }
  return 0;
}



//------------------------------------------------------------
// hdcp2_deinit_qseecom @ 001022cc size=80
// signature: undefined hdcp2_deinit_qseecom(void)
// callers: []
//------------------------------------------------------------

void hdcp2_deinit_qseecom(long param_1)

{
  if (param_1 == 0) {
    _printk(&DAT_00106331);
  }
  else {
    kfree_sensitive(*(undefined8 *)(param_1 + 0x68));
    kfree_sensitive(*(undefined8 *)(param_1 + 0x60));
  }
  kfree_sensitive(param_1);
  return;
}



//------------------------------------------------------------
// hdcp2_app_start_qseecom @ 00102320 size=380
// signature: undefined hdcp2_app_start_qseecom(void)
// callers: []
//------------------------------------------------------------

ulong hdcp2_app_start_qseecom(long param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined *puVar3;
  char *pcVar4;
  ulong uVar5;
  code *pcVar6;
  undefined4 *puVar7;
  undefined1 auVar8 [16];
  
  if (param_1 == 0) {
LAB_001023fc:
    puVar3 = &DAT_00106331;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    auVar8 = hdcp2_app_load();
    uVar5 = auVar8._0_8_ & 0xffffffff;
    if (auVar8._0_4_ != 0) {
      return uVar5;
    }
    if (*(char *)(param_1 + 0x4c) == '\0') {
      if (*(long *)(param_1 + 0x38) == 0) {
        puVar3 = &DAT_001064a7;
        pcVar4 = "session_init";
LAB_0010244c:
        _printk(puVar3,pcVar4);
        return 0xffffffea;
      }
      puVar7 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
      *puVar7 = 0x1010;
      if ((*(long *)(param_1 + 0x38) == 0) || (*(long *)(*(long *)(param_1 + 0x38) + 8) == 0))
      goto LAB_001023fc;
      if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
        pcVar4 = *(char **)(param_1 + 0x58);
        puVar3 = &DAT_00105fba;
        goto LAB_0010244c;
      }
      if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
        puVar7[1] = *(undefined4 *)(param_1 + 0x50);
        uVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar7,0x40,puVar7 + 0x10,0x40)
        ;
        uVar1 = puVar7[0x10];
        if (((int)uVar2 < 0) || (uVar1 != 0)) {
          if (uVar1 < 0x44) {
            puVar3 = (&hdcp_errors)[uVar1];
          }
          else {
            puVar3 = &DAT_0010611c;
          }
          _printk(&DAT_001063b2,"session_init",(ulong)uVar2,(ulong)uVar1,puVar3);
          return 0xffffffea;
        }
        if (uVar2 != 0) {
          return (ulong)uVar2;
        }
        *(undefined4 *)(param_1 + 0x48) = puVar7[0x12];
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
      }
      else {
        _printk(&DAT_00106556,auVar8._8_8_,uVar5,puVar7 + 0x10);
      }
    }
    pcVar6 = *(code **)(param_1 + 0x78);
    if (pcVar6 != (code *)0x0) {
      if (*(int *)(pcVar6 + -4) != 0x3812d23d) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102374);
        (*pcVar6)();
      }
      uVar5 = (*pcVar6)(param_1);
      return uVar5 & 0xffffffff;
    }
    puVar3 = &DAT_00106906;
  }
  _printk(puVar3);
  return 0xffffffea;
}



//------------------------------------------------------------
// hdcp2_app_load @ 0010249c size=648
// signature: undefined hdcp2_app_load(void)
// callers: [hdcp2_app_start_qseecom, hdcp2_feature_supported_qseecom]
//------------------------------------------------------------

int hdcp2_app_load(long param_1)

{
  code *pcVar1;
  uint uVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  undefined *puVar6;
  long lVar7;
  undefined4 *puVar8;
  
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    _printk(&DAT_0010606b,*(undefined8 *)(param_1 + 0x58));
    return 0;
  }
  if ((qseecom_handle_g == 0) &&
     (iVar5 = qseecom_start_app(&qseecom_handle_g,*(undefined8 *)(param_1 + 0x58),0x1000),
     iVar5 != 0)) {
    _printk(&DAT_00106b54,iVar5);
    return iVar5;
  }
  lVar7 = qseecom_handle_g;
  *(long *)(param_1 + 0x38) = qseecom_handle_g;
  if (hdcpsrm_qseecom_handle_g == 0) {
    iVar5 = qseecom_start_app(&hdcpsrm_qseecom_handle_g,"hdcpsrm",0x1000);
    if (iVar5 != 0) {
      _printk(&DAT_001064d5,iVar5);
      goto joined_r0x001026bc;
    }
    lVar7 = *(long *)(param_1 + 0x38);
  }
  *(long *)(param_1 + 0x40) = hdcpsrm_qseecom_handle_g;
  if (lVar7 == 0) {
    _printk(&DAT_001064a7,"version");
LAB_00102688:
    iVar5 = -0x16;
LAB_0010268c:
    puVar6 = &DAT_001060f6;
  }
  else {
    puVar8 = *(undefined4 **)(lVar7 + 8);
    *puVar8 = 0x100e;
    if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
      iVar5 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar8,0x40,puVar8 + 0x10,0x40);
      uVar2 = puVar8[0x10];
      if ((iVar5 < 0) || (uVar2 != 0)) {
        if (uVar2 < 0x44) {
          puVar6 = (&hdcp_errors)[uVar2];
        }
        else {
          puVar6 = &DAT_0010611c;
        }
        _printk(&DAT_001063b2,"version",iVar5,(ulong)uVar2,puVar6);
        goto LAB_00102688;
      }
      if (iVar5 == 0) {
        if (*(char *)((long)puVar8 + 0x4a) == '\x01') {
          *(undefined1 *)(param_1 + 0x4c) = 1;
        }
        goto LAB_0010257c;
      }
      goto LAB_0010268c;
    }
    _printk(&DAT_00105eaf);
LAB_0010257c:
    iVar5 = hdcp2_app_started;
    bVar4 = *(char *)(param_1 + 0x4c) != '\0';
    pcVar3 = hdcp2_app_init;
    if (bVar4) {
      pcVar3 = hdcp2_app_init_legacy;
    }
    pcVar1 = hdcp2_app_tx_init;
    if (bVar4) {
      pcVar1 = hdcp2_app_tx_init_legacy;
    }
    *(code **)(param_1 + 0x70) = pcVar3;
    *(code **)(param_1 + 0x78) = pcVar1;
    if (iVar5 != 0) {
LAB_001025e0:
      hdcp2_app_started = iVar5 + 1;
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1;
      return 0;
    }
    if (*(int *)(pcVar3 + -4) != 0x3812d23d) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1025d4);
      (*pcVar3)();
    }
    iVar5 = (*pcVar3)(param_1);
    if (iVar5 == 0) {
      iVar5 = hdcp2_app_started;
      goto LAB_001025e0;
    }
    puVar6 = &DAT_00106408;
  }
  _printk(puVar6);
  if (hdcp2_app_started == 0) {
    qseecom_shutdown_app(&hdcpsrm_qseecom_handle_g);
    hdcpsrm_qseecom_handle_g = 0;
  }
  *(undefined8 *)(param_1 + 0x40) = 0;
joined_r0x001026bc:
  if (hdcp2_app_started == 0) {
    qseecom_shutdown_app(&qseecom_handle_g);
    qseecom_handle_g = 0;
  }
  *(undefined8 *)(param_1 + 0x38) = 0;
  return iVar5;
}



//------------------------------------------------------------
// hdcp2_app_start_auth_qseecom @ 00102728 size=292
// signature: undefined hdcp2_app_start_auth_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_start_auth_qseecom(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 0xe) == 0)) {
    _printk(&DAT_001064a7,"start_auth");
  }
  else {
    puVar5 = *(undefined4 **)(*(long *)(param_1 + 0xe) + 8);
    *puVar5 = 0x1012;
    param_1[4] = (int)param_2;
    if (((uint)param_1[0xc] >> 1 & 1) == 0) {
      puVar4 = &DAT_0010602a;
    }
    else {
      if (((uint)param_1[0xc] >> 2 & 1) != 0) {
        puVar5[1] = param_1[10];
        iVar3 = qseecom_send_command(*(undefined8 *)(param_1 + 0xe),puVar5,0x40,puVar5 + 0x10,0xc0);
        uVar1 = puVar5[0x10];
        if ((-1 < iVar3) && (uVar1 == 0)) {
          if (iVar3 == 0) {
            memcpy(*(void **)(param_1 + 0x1a),puVar5 + 0x15,(ulong)(uint)puVar5[0x14]);
            param_1[8] = puVar5[0x14];
            uVar2 = puVar5[0x13];
            *(undefined1 *)(param_1 + 1) = 0;
            *param_1 = uVar2;
            param_1[10] = puVar5[0x12];
            return 0;
          }
          return iVar3;
        }
        if (uVar1 < 0x44) {
          puVar4 = (&hdcp_errors)[uVar1];
        }
        else {
          puVar4 = &DAT_0010611c;
        }
        _printk(&DAT_001063b2,"start_auth",iVar3,(ulong)uVar1,puVar4);
        return -0x16;
      }
      puVar4 = &DAT_00106a97;
    }
    _printk(puVar4,param_2,param_3,puVar5 + 0x10);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_process_msg_qseecom @ 00102850 size=312
// signature: undefined hdcp2_app_process_msg_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_process_msg_qseecom(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 0xe) == 0)) {
    _printk(&DAT_001064a7,"rcvd_msg");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0xe) + 8);
    *puVar4 = 0x1003;
    param_1[4] = param_2;
    if (*(long *)(param_1 + 2) == 0) {
      _printk(&DAT_00105c82);
    }
    else {
      puVar4[2] = param_2;
      puVar4[1] = param_1[10];
      memcpy(puVar4 + 3,*(void **)(param_1 + 0x18),(ulong)(uint)param_1[4]);
      iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0xe),puVar4,0x240,puVar4 + 0x90,0xc0);
      uVar1 = puVar4[0x90];
      if ((-1 < iVar2) && (uVar1 == 0)) {
        if (iVar2 != 0) {
          return iVar2;
        }
        if (puVar4[0x94] == 1) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        memcpy(*(void **)(param_1 + 0x1a),puVar4 + 0x96,(ulong)(uint)puVar4[0x95]);
        param_1[8] = puVar4[0x95];
        *param_1 = puVar4[0x93];
        return 0;
      }
      if (uVar1 < 0x44) {
        puVar3 = (&hdcp_errors)[uVar1];
      }
      else {
        puVar3 = &DAT_0010611c;
      }
      _printk(&DAT_001063b2,"rcvd_msg",iVar2,(ulong)uVar1,puVar3);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_timeout_qseecom @ 0010298c size=232
// signature: undefined hdcp2_app_timeout_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_timeout_qseecom(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 0xe) == 0)) {
    _printk(&DAT_001064a7,"send_timeout");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0xe) + 8);
    *puVar4 = 0x1004;
    param_1[4] = param_2;
    iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0xe),puVar4,0x40,puVar4 + 0x10,0xc0);
    uVar1 = puVar4[0x10];
    if ((-1 < iVar2) && (uVar1 == 0)) {
      if (iVar2 == 0) {
        memcpy(*(void **)(param_1 + 0x1a),puVar4 + 0x14,(ulong)(uint)puVar4[0x13]);
        param_1[8] = puVar4[0x13];
        *param_1 = puVar4[0x12];
        return 0;
      }
      return iVar2;
    }
    if (uVar1 < 0x44) {
      puVar3 = (&hdcp_errors)[uVar1];
    }
    else {
      puVar3 = &DAT_0010611c;
    }
    _printk(&DAT_001063b2,"send_timeout",iVar2,(ulong)uVar1,puVar3);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_enable_encryption_qseecom @ 00102a78 size=236
// signature: undefined hdcp2_app_enable_encryption_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_enable_encryption_qseecom(long param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"set_hw_key");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    *puVar4 = 0x1005;
    *(undefined4 *)(param_1 + 0x10) = param_2;
    msleep(300);
    puVar4[1] = *(undefined4 *)(param_1 + 0x28);
    iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar4,0x40,puVar4 + 0x10,0x40);
    uVar1 = puVar4[0x10];
    if ((-1 < iVar2) && (uVar1 == 0)) {
      if (iVar2 == 0) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 8;
        return 0;
      }
      return iVar2;
    }
    if (uVar1 < 0x44) {
      puVar3 = (&hdcp_errors)[uVar1];
    }
    else {
      puVar3 = &DAT_0010611c;
    }
    _printk(&DAT_001063b2,"set_hw_key",iVar2,(ulong)uVar1,puVar3);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_query_stream_qseecom @ 00102b68 size=240
// signature: undefined hdcp2_app_query_stream_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_query_stream_qseecom(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 0xe) == 0)) {
    _printk(&DAT_001064a7,"query_stream_type");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0xe) + 8);
    *puVar4 = 0x1006;
    param_1[4] = param_2;
    puVar4[1] = param_1[10];
    iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0xe),puVar4,0x40,puVar4 + 0x10,0xc0);
    uVar1 = puVar4[0x10];
    if ((-1 < iVar2) && (uVar1 == 0)) {
      if (iVar2 == 0) {
        memcpy(*(void **)(param_1 + 0x1a),puVar4 + 0x14,(ulong)(uint)puVar4[0x13]);
        param_1[8] = puVar4[0x13];
        *param_1 = puVar4[0x12];
        return 0;
      }
      return iVar2;
    }
    if (uVar1 < 0x44) {
      puVar3 = (&hdcp_errors)[uVar1];
    }
    else {
      puVar3 = &DAT_0010611c;
    }
    _printk(&DAT_001063b2,"query_stream_type",iVar2,(ulong)uVar1,puVar3);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_stop_qseecom @ 00102c5c size=472
// signature: undefined hdcp2_app_stop_qseecom(void)
// callers: []
//------------------------------------------------------------

ulong hdcp2_app_stop_qseecom(long param_1,undefined8 param_2,ulong param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  undefined1 auVar7 [16];
  
  if (param_1 == 0) {
    puVar5 = &DAT_00106205;
LAB_00102d8c:
    _printk(puVar5,param_2,param_3,param_4);
  }
  else {
    if (*(long *)(param_1 + 0x38) == 0) {
      puVar5 = &DAT_001064a7;
      pcVar3 = "tx_deinit";
    }
    else {
      puVar6 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
      param_4 = puVar6 + 0x10;
      *puVar6 = 0x1002;
      if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
        if ((*(uint *)(param_1 + 0x30) >> 2 & 1) == 0) {
          puVar5 = &DAT_00106a97;
        }
        else {
          puVar6[1] = *(undefined4 *)(param_1 + 0x28);
          auVar7 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar6,0x40,param_4,0x40);
          param_2 = auVar7._8_8_;
          param_3 = auVar7._0_8_ & 0xffffffff;
          uVar1 = puVar6[0x10];
          uVar4 = (ulong)uVar1;
          if ((auVar7._0_4_ < 0) || (uVar1 != 0)) {
            if (uVar1 < 0x44) {
              puVar5 = (&hdcp_errors)[uVar4];
            }
            else {
              puVar5 = &DAT_0010611c;
            }
            pcVar3 = "tx_deinit";
LAB_00102dc4:
            _printk(&DAT_001063b2,pcVar3,param_3,uVar4,puVar5);
            return 0xffffffea;
          }
          if (auVar7._0_4_ != 0) {
            return param_3;
          }
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb;
          if (*(char *)(param_1 + 0x4c) != '\0') {
LAB_00102cdc:
            uVar4 = hdcp2_app_unload(param_1);
            return uVar4 & 0xffffffff;
          }
          if (*(long *)(param_1 + 0x38) == 0) {
            puVar5 = &DAT_001064a7;
            pcVar3 = "session_deinit";
            param_4 = (undefined4 *)0x0;
            goto LAB_00102d7c;
          }
          puVar6 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
          param_4 = puVar6 + 0x10;
          *puVar6 = 0x1011;
          if ((*(uint *)(param_1 + 0x30) & 1) == 0) goto LAB_00102d5c;
          if ((*(uint *)(param_1 + 0x30) >> 1 & 1) != 0) {
            puVar6[1] = *(undefined4 *)(param_1 + 0x48);
            uVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar6,0x40,param_4,0x40);
            param_3 = (ulong)uVar2;
            uVar1 = puVar6[0x10];
            uVar4 = (ulong)uVar1;
            if (((int)uVar2 < 0) || (uVar1 != 0)) {
              if (uVar1 < 0x44) {
                puVar5 = (&hdcp_errors)[uVar4];
              }
              else {
                puVar5 = &DAT_0010611c;
              }
              pcVar3 = "session_deinit";
              goto LAB_00102dc4;
            }
            if (uVar2 != 0) {
              return param_3;
            }
            *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffd;
            goto LAB_00102cdc;
          }
          puVar5 = &DAT_0010602a;
        }
        goto LAB_00102d8c;
      }
LAB_00102d5c:
      pcVar3 = *(char **)(param_1 + 0x58);
      puVar5 = &DAT_00105fba;
    }
LAB_00102d7c:
    _printk(puVar5,pcVar3,param_3,param_4);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// hdcp2_app_unload @ 00102e34 size=340
// signature: undefined hdcp2_app_unload(void)
// callers: [hdcp2_app_stop_qseecom, hdcp2_feature_supported_qseecom]
//------------------------------------------------------------

int hdcp2_app_unload(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  long *plVar4;
  undefined4 *puVar5;
  
  plVar4 = (long *)(param_1 + 0x38);
  if (*plVar4 == 0) {
    _printk(&DAT_001064a7,"deinit");
    if (hdcp2_app_started == 0) {
      qseecom_shutdown_app(param_1 + 0x40);
    }
    iVar2 = -0x16;
  }
  else {
    puVar5 = *(undefined4 **)(*plVar4 + 8);
    *puVar5 = 0x100c;
    hdcp2_app_started = hdcp2_app_started + -1;
    if (hdcp2_app_started == 0) {
      iVar2 = qseecom_send_command(*plVar4,puVar5,0x40,puVar5 + 0x10,0x40);
      uVar1 = puVar5[0x10];
      if ((iVar2 < 0) || (uVar1 != 0)) {
        if (uVar1 < 0x44) {
          puVar3 = (&hdcp_errors)[uVar1];
        }
        else {
          puVar3 = &DAT_0010611c;
        }
        _printk(&DAT_001063b2,"deinit",iVar2,(ulong)uVar1,puVar3);
      }
      iVar2 = qseecom_shutdown_app(param_1 + 0x40);
      if (iVar2 != 0) {
        _printk(&DAT_00105ec9,iVar2);
      }
      hdcpsrm_qseecom_handle_g = 0;
      iVar2 = qseecom_shutdown_app(plVar4);
      if (iVar2 != 0) {
        _printk(&DAT_00105d78,iVar2);
        return iVar2;
      }
      qseecom_handle_g = 0;
    }
    iVar2 = 0;
    *plVar4 = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;
  }
  return iVar2;
}



//------------------------------------------------------------
// hdcp2_feature_supported_qseecom @ 00102f8c size=436
// signature: undefined hdcp2_feature_supported_qseecom(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp2_feature_supported_qseecom(long param_1)

{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  undefined8 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    _printk(&DAT_00106222);
  }
  else {
    if (*(char *)(param_1 + 0x2c) != '\0') {
      return 1;
    }
    iVar2 = hdcp2_app_load(param_1);
    if (iVar2 == 0) {
      uVar7 = 0;
      do {
        if (*(long *)(param_1 + 0x38) == 0) {
          puVar4 = &DAT_001064a7;
          pcVar3 = "verify_key";
LAB_001030a8:
          _printk(puVar4,pcVar3);
          if (qseecomd_down != '\x01') goto LAB_0010311c;
        }
        else {
          puVar6 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
          *puVar6 = 0x100f;
          if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
            pcVar3 = *(char **)(param_1 + 0x58);
            puVar4 = &DAT_00105fba;
            goto LAB_001030a8;
          }
          iVar2 = qseecom_send_command
                            (*(undefined8 *)(param_1 + 0x38),puVar6,0x40,puVar6 + 0x10,0x40);
          uVar1 = puVar6[0x10];
          if ((-1 < iVar2) && (uVar1 == 0)) {
            uVar5 = 0;
            qseecomd_down = '\0';
            if (iVar2 == 0) {
              uVar5 = 1;
              *(undefined1 *)(param_1 + 0x2c) = 1;
            }
            goto LAB_001030d0;
          }
          puVar4 = &DAT_0010611c;
          if (uVar1 < 0x44) {
            puVar4 = (&hdcp_errors)[uVar1];
          }
          _printk(&DAT_001063b2,"verify_key",iVar2,(ulong)uVar1,puVar4);
          if (puVar6[0x10] != -0x1007) {
            uVar5 = 0;
            qseecomd_down = '\0';
            goto LAB_001030d0;
          }
          qseecomd_down = '\x01';
        }
        msleep(100);
        uVar7 = uVar7 + 1;
        if (*(uint *)(param_1 + 0x80) < uVar7) {
          if (qseecomd_down == '\x01') {
            _printk(&DAT_00106274);
          }
LAB_0010311c:
          uVar5 = 0;
LAB_001030d0:
          hdcp2_app_unload(param_1);
          return uVar5;
        }
      } while( true );
    }
  }
  return 0;
}



//------------------------------------------------------------
// hdcp2_force_encryption_qseecom @ 00103144 size=232
// signature: undefined hdcp2_force_encryption_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_force_encryption_qseecom(long param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"force_encryption");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    *puVar4 = 0x1016;
    if (*(int *)(param_1 + 0x30) == 8) {
      msleep(200);
    }
    puVar4[1] = *(undefined4 *)(param_1 + 0x28);
    puVar4[2] = param_2;
    iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar4,0x40,puVar4 + 0x10,0x40);
    uVar1 = puVar4[0x10];
    if ((-1 < iVar2) && (uVar1 == 0)) {
      return iVar2;
    }
    if (uVar1 < 0x44) {
      puVar3 = (&hdcp_errors)[uVar1];
    }
    else {
      puVar3 = &DAT_0010611c;
    }
    _printk(&DAT_001063b2,"force_encryption",iVar2,(ulong)uVar1,puVar3);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_open_stream_qseecom @ 00103230 size=260
// signature: undefined hdcp2_open_stream_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_open_stream_qseecom
              (long param_1,undefined8 param_2,undefined8 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 *puVar4;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"session_open_stream");
  }
  else {
    puVar4 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    *puVar4 = 0x1014;
    if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
      puVar3 = &DAT_0010602a;
    }
    else {
      if ((*(uint *)(param_1 + 0x30) >> 2 & 1) != 0) {
        puVar4[1] = *(undefined4 *)(param_1 + 0x48);
        puVar4[2] = (uint)param_2 & 0xff;
        puVar4[3] = (uint)param_3 & 0xff;
        puVar4[4] = 0;
        iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar4,0x40,puVar4 + 0x10,0x40)
        ;
        uVar1 = puVar4[0x10];
        if ((-1 < iVar2) && (uVar1 == 0)) {
          if (iVar2 == 0) {
            *param_4 = puVar4[0x12];
            return 0;
          }
          return iVar2;
        }
        if (uVar1 < 0x44) {
          puVar3 = (&hdcp_errors)[uVar1];
        }
        else {
          puVar3 = &DAT_0010611c;
        }
        _printk(&DAT_001063b2,"session_open_stream",iVar2,(ulong)uVar1,puVar3);
        return -0x16;
      }
      puVar3 = &DAT_00106a97;
    }
    _printk(puVar3,param_2,param_3,puVar4 + 0x10);
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_close_stream_qseecom @ 00103338 size=232
// signature: undefined hdcp2_close_stream_qseecom(void)
// callers: []
//------------------------------------------------------------

int hdcp2_close_stream_qseecom(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"session_close_stream");
  }
  else {
    puVar5 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    puVar3 = puVar5 + 0x10;
    *puVar5 = 0x1015;
    if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
      _printk(&DAT_0010602a,param_2,param_3,puVar3);
    }
    else if ((*(uint *)(param_1 + 0x30) >> 2 & 1) == 0) {
      _printk(&DAT_00106a97,param_2,param_3,puVar3);
    }
    else {
      puVar5[1] = *(undefined4 *)(param_1 + 0x48);
      puVar5[2] = (int)param_2;
      iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar5,0x40,puVar3,0x40);
      uVar1 = puVar5[0x10];
      if ((-1 < iVar2) && (uVar1 == 0)) {
        return iVar2;
      }
      if (uVar1 < 0x44) {
        puVar4 = (&hdcp_errors)[uVar1];
      }
      else {
        puVar4 = &DAT_0010611c;
      }
      _printk(&DAT_001063b2,"session_close_stream",iVar2,(ulong)uVar1,puVar4);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_update_app_data_qseecom @ 00103424 size=100
// signature: undefined hdcp2_update_app_data_qseecom(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp2_update_app_data_qseecom(undefined4 *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    _printk(&DAT_00106222);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 2);
    param_2[4] = param_1[4];
    *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 6);
    param_2[8] = param_1[8];
    *param_2 = *param_1;
    uVar1 = 0;
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 1);
  }
  return uVar1;
}



//------------------------------------------------------------
// hdcp2_app_init_legacy @ 0010348c size=232
// signature: undefined hdcp2_app_init_legacy(void)
// callers: [hdcp2_app_load]
//------------------------------------------------------------

int hdcp2_app_init_legacy(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"init_v1");
  }
  else {
    puVar5 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    puVar3 = puVar5 + 0x10;
    *puVar5 = 0x100b;
    if (*(char *)(param_1 + 0x4c) == '\0') {
      _printk(&DAT_00106e08,param_2,param_3,puVar3);
    }
    else {
      if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
        _printk(&DAT_00105eaf,param_2,param_3,puVar3);
        return 0;
      }
      iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar5,0x40,puVar3,0xc0);
      uVar1 = puVar5[0x10];
      if ((-1 < iVar2) && (uVar1 == 0)) {
        return iVar2;
      }
      if (uVar1 < 0x44) {
        puVar4 = (&hdcp_errors)[uVar1];
      }
      else {
        puVar4 = &DAT_0010611c;
      }
      _printk(&DAT_001063b2,"init_v1",iVar2,(ulong)uVar1,puVar4);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_tx_init_legacy @ 00103578 size=284
// signature: undefined hdcp2_app_tx_init_legacy(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_tx_init_legacy(undefined4 *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  
  if ((param_1 == (undefined4 *)0x0) || (*(long *)(param_1 + 0xe) == 0)) {
    _printk(&DAT_001064a7,"tx_init_v1");
  }
  else {
    puVar6 = *(undefined4 **)(*(long *)(param_1 + 0xe) + 8);
    puVar4 = puVar6 + 0x10;
    *puVar6 = 0x1001;
    if ((param_1[0xc] & 1) == 0) {
      _printk(&DAT_00106502,param_2,param_3,puVar4);
    }
    else {
      if (((uint)param_1[0xc] >> 2 & 1) != 0) {
        _printk(&DAT_00106840,param_2,param_3,puVar4);
        return 0;
      }
      iVar3 = qseecom_send_command(*(undefined8 *)(param_1 + 0xe),puVar6,0x40,puVar4,0xc0);
      uVar1 = puVar6[0x10];
      if ((-1 < iVar3) && (uVar1 == 0)) {
        if (iVar3 == 0) {
          *(undefined4 **)(param_1 + 6) = puVar6 + 0x15;
          param_1[8] = puVar6[0x14];
          *param_1 = puVar6[0x13];
          uVar2 = puVar6[0x12];
          param_1[0xc] = param_1[0xc] | 4;
          param_1[10] = uVar2;
          return 0;
        }
        return iVar3;
      }
      if (uVar1 < 0x44) {
        puVar5 = (&hdcp_errors)[uVar1];
      }
      else {
        puVar5 = &DAT_0010611c;
      }
      _printk(&DAT_001063b2,"tx_init_v1",iVar3,(ulong)uVar1,puVar5);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// hdcp2_app_init @ 00103698 size=300
// signature: undefined hdcp2_app_init(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,&DAT_001069e9);
    iVar2 = -0x16;
  }
  else {
    puVar5 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    puVar3 = puVar5 + 0x10;
    *puVar5 = 0x100b;
    if (*(char *)(param_1 + 0x4c) == '\0') {
      if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
        puVar5[1] = 0x20100;
        iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar5,0x40,puVar3,0x40);
        uVar1 = puVar5[0x10];
        if ((iVar2 < 0) || (uVar1 != 0)) {
          if (uVar1 < 0x44) {
            puVar4 = (&hdcp_errors)[uVar1];
          }
          else {
            puVar4 = &DAT_0010611c;
          }
          _printk(&DAT_001063b2,&DAT_001069e9,iVar2,(ulong)uVar1,puVar4);
          iVar2 = -0x16;
        }
        else if (iVar2 == 0) {
          if (*(char *)((long)puVar5 + 0x49) == '\x01') {
            iVar2 = 0;
          }
          else {
            _printk(&DAT_001065c2,*(char *)((long)puVar5 + 0x49),1);
            iVar2 = -1;
          }
        }
      }
      else {
        _printk(&DAT_00105eaf,param_2,param_3,puVar3);
        iVar2 = 0;
      }
    }
    else {
      _printk(&DAT_00106e08,param_2,param_3,puVar3);
      iVar2 = -0x16;
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// hdcp2_app_tx_init @ 001037c8 size=268
// signature: undefined hdcp2_app_tx_init(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_tx_init(long param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x38) == 0)) {
    _printk(&DAT_001064a7,"tx_init");
  }
  else {
    puVar5 = *(undefined4 **)(*(long *)(param_1 + 0x38) + 8);
    puVar3 = puVar5 + 0x10;
    *puVar5 = 0x1001;
    if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
      _printk(&DAT_0010602a,param_2,param_3,puVar3);
    }
    else {
      if ((*(uint *)(param_1 + 0x30) >> 2 & 1) != 0) {
        _printk(&DAT_00106840,param_2,param_3,puVar3);
        return 0;
      }
      puVar5[1] = *(undefined4 *)(param_1 + 0x48);
      iVar2 = qseecom_send_command(*(undefined8 *)(param_1 + 0x38),puVar5,0x40,puVar3,0x40);
      uVar1 = puVar5[0x10];
      if ((-1 < iVar2) && (uVar1 == 0)) {
        if (iVar2 == 0) {
          *(undefined4 *)(param_1 + 0x28) = puVar5[0x12];
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
          return 0;
        }
        return iVar2;
      }
      if (uVar1 < 0x44) {
        puVar4 = (&hdcp_errors)[uVar1];
      }
      else {
        puVar4 = &DAT_0010611c;
      }
      _printk(&DAT_001063b2,"tx_init",iVar2,(ulong)uVar1,puVar4);
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// load_app @ 001038d8 size=600
// signature: undefined load_app(void)
// callers: [hdcp1_app_load, hdcp2_app_load]
//------------------------------------------------------------

int load_app(undefined8 param_1,undefined8 *param_2,undefined8 *param_3)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  code *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_6c;
  undefined4 *local_68;
  undefined8 uStack_60;
  code *local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = (code *)0x0;
  local_98 = 0;
  puVar5 = (undefined4 *)firmware_request_from_smcinvoke(param_1,&local_90,&uStack_88);
  if (puVar5 == (undefined4 *)0x0) {
    _printk(&DAT_001069ee);
    iVar4 = -0x16;
    goto LAB_00103a70;
  }
  iVar4 = get_client_env_object(&local_a0);
  if (iVar4 == 0) {
    local_68 = &local_6c;
    local_58 = (code *)0x0;
    uStack_50 = 0;
    local_6c = 3;
    uStack_60 = 4;
    if (*(int *)(local_a0 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x103974);
      (*pcVar3)();
    }
    iVar4 = (*local_a0)(local_98,0,&local_68,0x1001);
    uVar2 = uStack_50;
    pcVar3 = local_58;
    if (iVar4 != 0) {
      _printk(&DAT_001067b2,iVar4);
      goto LAB_00103ae8;
    }
    local_58 = (code *)0x0;
    uStack_50 = 0;
    uStack_60 = local_90;
    local_68 = puVar5;
    if (*(int *)(pcVar3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8238,0x1039b4);
      (*pcVar3)();
    }
    iVar4 = (*pcVar3)(uVar2,0,&local_68,0x1001);
    *param_3 = local_58;
    param_3[1] = uStack_50;
    if (iVar4 == 0) {
      local_68 = (undefined4 *)0x0;
      uStack_60 = 0;
      if (*(int *)((code *)*param_3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1039f0);
        (*pcVar3)();
      }
      iVar4 = (*(code *)*param_3)(param_3[1],2,&local_68,0x1000);
      *param_2 = local_68;
      param_2[1] = uStack_60;
      if (iVar4 != 0) {
        _printk(&DAT_00106358,iVar4);
      }
    }
    else {
      _printk(&DAT_00106d6b,iVar4);
      *param_3 = 0;
      param_3[1] = 0;
    }
    qtee_shmbridge_free_shm(&uStack_88);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8238,0x103a38);
        (*pcVar3)();
      }
      (*pcVar3)(uVar2,0xffff,0,0);
    }
  }
  else {
    _printk(&DAT_0010685d,iVar4);
    local_a0 = (code *)0x0;
    local_98 = 0;
LAB_00103ae8:
    qtee_shmbridge_free_shm(&uStack_88);
  }
  if (local_a0 != (code *)0x0) {
    if (*(int *)(local_a0 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103a6c);
      (*pcVar3)();
    }
    (*local_a0)(local_98,0xffff,0,0);
  }
LAB_00103a70:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdcp1_init_smcinvoke @ 00103b34 size=44
// signature: undefined hdcp1_init_smcinvoke(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hdcp1_init_smcinvoke(void)

{
  kmalloc_trace(_memcpy,0xdc0,0x50);
  return;
}



//------------------------------------------------------------
// hdcp1_feature_supported_smcinvoke @ 00103b64 size=260
// signature: undefined hdcp1_feature_supported_smcinvoke(void)
// callers: []
//------------------------------------------------------------

bool hdcp1_feature_supported_smcinvoke(undefined8 *param_1)

{
  long lVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00106331);
  }
  else {
    if (*(char *)(param_1 + 8) != '\0') {
      bVar3 = true;
      goto LAB_00103c20;
    }
    iVar4 = hdcp1_app_load(param_1);
    if ((iVar4 == 0) && ((*(byte *)(param_1 + 9) & 1) != 0)) {
      local_48 = &local_4c;
      local_4c = 1;
      uStack_40 = 4;
      if (*(int *)((code *)*param_1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x822a,0x103bf0);
        (*pcVar2)();
      }
      iVar4 = (*(code *)*param_1)(param_1[1],1,&local_48,1);
      bVar3 = iVar4 == 0;
      if (iVar4 == 0) {
        *(undefined1 *)(param_1 + 8) = 1;
      }
      else {
        _printk(&DAT_00105fe1,iVar4);
      }
      hdcp1_app_unload(param_1);
      goto LAB_00103c20;
    }
  }
  bVar3 = false;
LAB_00103c20:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bVar3;
}



//------------------------------------------------------------
// hdcp1_app_load @ 00103c68 size=220
// signature: undefined hdcp1_app_load(void)
// callers: [hdcp1_feature_supported_smcinvoke, hdcp1_start_smcinvoke]
//------------------------------------------------------------

int hdcp1_app_load(long *param_1)

{
  int iVar1;
  undefined *puVar2;
  
  if ((*(byte *)(param_1 + 9) & 1) != 0) {
    return 0;
  }
  iVar1 = load_app("hdcp1",param_1,param_1 + 2);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      puVar2 = &DAT_00105d5f;
    }
    else {
      iVar1 = load_app(&DAT_00106902,param_1 + 4,param_1 + 6);
      if (iVar1 != 0) {
        puVar2 = &DAT_00106575;
        goto LAB_00103d24;
      }
      if (param_1[4] != 0) {
        *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) | 1;
        return 0;
      }
      puVar2 = &DAT_00106899;
    }
    _printk(puVar2);
    iVar1 = -0x16;
  }
  else {
    puVar2 = &DAT_00105d43;
LAB_00103d24:
    _printk(puVar2,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// hdcp1_app_unload @ 00103d44 size=336
// signature: undefined hdcp1_app_unload(void)
// callers: [hdcp1_feature_supported_smcinvoke, hdcp1_start_smcinvoke]
//------------------------------------------------------------

void hdcp1_app_unload(undefined8 *param_1)

{
  code *pcVar1;
  
  if (param_1[1] == 0) {
    _printk(&DAT_00106331);
  }
  else if ((*(byte *)(param_1 + 9) & 1) == 0) {
    _printk(&DAT_00106001);
  }
  else {
    pcVar1 = (code *)*param_1;
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103d98);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[1],0xffff,0,0);
    }
    *param_1 = 0;
    param_1[1] = 0;
    pcVar1 = (code *)param_1[2];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103dd4);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[3],0xffff,0,0);
    }
    param_1[2] = 0;
    param_1[3] = 0;
    pcVar1 = (code *)param_1[4];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103e10);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[5],0xffff,0,0);
    }
    param_1[4] = 0;
    param_1[5] = 0;
    pcVar1 = (code *)param_1[6];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103e4c);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[7],0xffff,0,0);
    }
    param_1[6] = 0;
    param_1[7] = 0;
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xfffffffe;
  }
  return;
}



//------------------------------------------------------------
// hdcp1_set_enc_smcinvoke @ 00103e98 size=264
// signature: undefined hdcp1_set_enc_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp1_set_enc_smcinvoke(undefined8 *param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  uint local_3c;
  uint *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if ((param_1 == (undefined8 *)0x0) || (param_1[1] == 0)) {
    puVar4 = &DAT_00106b2e;
  }
  else {
    if (*(char *)(param_1 + 8) != '\0') {
      if ((*(byte *)(param_1 + 9) & 1) == 0) {
        _printk(&DAT_00105fba,"hdcp1");
        iVar3 = -0x16;
      }
      else {
        local_3c = param_2 & 1;
        local_38 = &local_3c;
        uStack_30 = 4;
        if (*(int *)((code *)*param_1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x103f14);
          (*pcVar2)();
        }
        iVar3 = (*(code *)*param_1)(param_1[1],2,&local_38,1);
        if (iVar3 != 0) {
          _printk(&DAT_0010660a,iVar3);
        }
      }
      goto LAB_00103f20;
    }
    puVar4 = &DAT_001061e0;
  }
  _printk(puVar4);
  iVar3 = -0x16;
LAB_00103f20:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp1_ops_notify_smcinvoke @ 00103fa4 size=204
// signature: undefined hdcp1_ops_notify_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp1_ops_notify_smcinvoke(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x28) == 0)) {
    puVar3 = &DAT_00106a78;
  }
  else {
    if (*(char *)(param_1 + 0x40) != '\0') {
      if ((*(byte *)(param_1 + 0x48) & 1) == 0) {
        _printk(&DAT_00105fba,&DAT_00106902);
        return -0x16;
      }
      if (*(int *)(*(code **)(param_1 + 0x20) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x103ffc);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(param_1 + 0x20))(*(long *)(param_1 + 0x28),0,0,0);
      if (iVar2 == 0) {
        return 0;
      }
      _printk(&DAT_00106976,iVar2);
      return iVar2;
    }
    puVar3 = &DAT_001061e0;
  }
  _printk(puVar3);
  return -0x16;
}



//------------------------------------------------------------
// hdcp1_start_smcinvoke @ 00104074 size=392
// signature: undefined hdcp1_start_smcinvoke(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hdcp1_start_smcinvoke(undefined8 *param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  uint *puVar6;
  undefined *puVar7;
  uint *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if ((param_2 == (uint *)0x0) || (param_3 == (uint *)0x0)) {
    puVar7 = &DAT_00105c04;
  }
  else if (param_1 == (undefined8 *)0x0) {
    puVar7 = &DAT_00106331;
  }
  else {
    if (*(char *)(param_1 + 8) != '\0') {
      if ((*(byte *)(param_1 + 9) & 1) != 0) {
        iVar5 = 0;
        goto LAB_001041b0;
      }
      iVar5 = hdcp1_app_load(param_1);
      if (iVar5 != 0) goto LAB_001041b0;
      puVar6 = (uint *)kmalloc_trace(_kfree_sensitive,0xdc0,8);
      if (puVar6 == (uint *)0x0) {
LAB_001041a4:
        iVar5 = -0x16;
      }
      else {
        if ((*(byte *)(param_1 + 9) & 1) == 0) {
          _printk(&DAT_00106881);
          goto LAB_001041a4;
        }
        uStack_40 = 8;
        local_48 = puVar6;
        if (*(int *)((code *)*param_1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x104124);
          (*pcVar4)();
        }
        iVar5 = (*(code *)*param_1)(param_1[1],4,&local_48,0x10);
        if (iVar5 == 0) {
          uVar1 = (*puVar6 & 0xff00ff00) >> 8 | (*puVar6 & 0xff00ff) << 8;
          uVar2 = (puVar6[1] & 0xff00ff00) >> 8 | (puVar6[1] & 0xff00ff) << 8;
          *param_2 = uVar1 >> 0x10 | uVar1 << 0x10;
          *param_3 = uVar2 >> 0x10 | uVar2 << 0x10;
          iVar5 = hdcp1_validate_aksv(*param_2);
          if (iVar5 == 0) goto LAB_001041b0;
          _printk(&DAT_001063e9,iVar5);
        }
        else {
          _printk(&DAT_001062cc,iVar5);
          iVar5 = -0x7e;
        }
      }
      hdcp1_app_unload(param_1);
      goto LAB_001041b0;
    }
    puVar7 = &DAT_001066ed;
  }
  _printk(puVar7);
  iVar5 = -0x16;
LAB_001041b0:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// hdcp1_stop_smcinvoke @ 00104200 size=336
// signature: undefined hdcp1_stop_smcinvoke(void)
// callers: []
//------------------------------------------------------------

void hdcp1_stop_smcinvoke(undefined8 *param_1)

{
  code *pcVar1;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_00106b2e);
  }
  else if ((*(byte *)(param_1 + 9) & 1) == 0) {
    _printk(&DAT_00106881);
  }
  else {
    pcVar1 = (code *)*param_1;
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104254);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[1],0xffff,0,0);
    }
    *param_1 = 0;
    param_1[1] = 0;
    pcVar1 = (code *)param_1[2];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104290);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[3],0xffff,0,0);
    }
    param_1[2] = 0;
    param_1[3] = 0;
    pcVar1 = (code *)param_1[4];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1042cc);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[5],0xffff,0,0);
    }
    param_1[4] = 0;
    param_1[5] = 0;
    pcVar1 = (code *)param_1[6];
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104308);
        (*pcVar1)();
      }
      (*pcVar1)(param_1[7],0xffff,0,0);
    }
    param_1[6] = 0;
    param_1[7] = 0;
    *(uint *)(param_1 + 9) = *(uint *)(param_1 + 9) & 0xfffffffe;
  }
  return;
}



//------------------------------------------------------------
// hdcp2_init_smcinvoke @ 00104354 size=64
// signature: undefined hdcp2_init_smcinvoke(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void hdcp2_init_smcinvoke(undefined4 param_1)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_memcpy,0xdc0,0x80);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x7c) = param_1;
  }
  return;
}



//------------------------------------------------------------
// hdcp2_deinit_smcinvoke @ 00104398 size=28
// signature: undefined hdcp2_deinit_smcinvoke(void)
// callers: []
//------------------------------------------------------------

void hdcp2_deinit_smcinvoke(void)

{
  kfree_sensitive();
  return;
}



//------------------------------------------------------------
// hdcp_get_version @ 001043b8 size=196
// signature: undefined hdcp_get_version(void)
// callers: []
//------------------------------------------------------------

int hdcp_get_version(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
    local_38 = &local_3c;
    uStack_30 = 4;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x822a,0x104418);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),10,&local_38,0x10);
    if (iVar3 != 0) {
      _printk(&DAT_00106c48,iVar3);
    }
  }
  else {
    _printk(&DAT_00105cf4);
    iVar3 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_init @ 00104480 size=304
// signature: undefined hdcp2_app_init(void)
// callers: [hdcp2_app_load]
//------------------------------------------------------------

int hdcp2_app_init(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  undefined1 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
    local_48 = &local_4c;
    local_4c = 0x20100;
    uStack_40 = 4;
    uStack_30 = 4;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1044f4);
      local_38 = (undefined1 *)&local_50;
      (*pcVar2)();
    }
    local_38 = (undefined1 *)&local_50;
    iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),8,&local_48,0x11);
    if (iVar3 != 0) {
      _printk(&DAT_00106d93,iVar3);
      goto LAB_00104580;
    }
    if (local_50._1_1_ != '\x01') {
      _printk(&DAT_001065c2,local_50._1_1_,1);
      iVar3 = -1;
      goto LAB_00104580;
    }
    _printk(&DAT_00105d11,2,1,0);
    _printk(&DAT_00106a18,local_50 >> 0x10 & 0xff,local_50 >> 8 & 0xff,local_50 & 0xff);
  }
  else {
    _printk(&DAT_00105cf4);
  }
  iVar3 = 0;
LAB_00104580:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_tx_init @ 001045b4 size=260
// signature: undefined hdcp2_app_tx_init(void)
// callers: [hdcp2_app_start_smcinvoke]
//------------------------------------------------------------

int hdcp2_app_tx_init(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  undefined1 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
    _printk(&DAT_0010602a);
    iVar3 = -0x16;
  }
  else if ((*(uint *)(param_1 + 0x30) >> 2 & 1) == 0) {
    local_4c = *(undefined4 *)(param_1 + 0x78);
    local_48 = &local_4c;
    uStack_40 = 4;
    uStack_30 = 4;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10462c);
      local_38 = (undefined1 *)&local_50;
      (*pcVar2)();
    }
    local_38 = (undefined1 *)&local_50;
    iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),2,&local_48,0x11);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0x28) = local_50;
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
    }
    else {
      _printk(&DAT_00105def,iVar3);
    }
  }
  else {
    _printk(&DAT_00106840);
    iVar3 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_tx_deinit @ 001046bc size=232
// signature: undefined hdcp2_app_tx_deinit(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_tx_deinit(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
    puVar4 = &DAT_00105e73;
  }
  else {
    if ((*(uint *)(param_1 + 0x30) >> 2 & 1) != 0) {
      local_3c = *(undefined4 *)(param_1 + 0x28);
      local_38 = &local_3c;
      uStack_30 = 4;
      if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x822b,0x104728);
        (*pcVar2)();
      }
      iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),3,&local_38,1);
      if (iVar3 == 0) {
        *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffb;
      }
      else {
        _printk(&DAT_00106dad,iVar3);
      }
      goto LAB_00104740;
    }
    puVar4 = &DAT_00106a97;
  }
  _printk(puVar4);
  iVar3 = -0x16;
LAB_00104740:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_start_smcinvoke @ 001047a8 size=380
// signature: undefined hdcp2_app_start_smcinvoke(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int hdcp2_app_start_smcinvoke(long param_1)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  undefined1 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (param_1 == 0) {
    puVar3 = &DAT_00106205;
LAB_001048a8:
    _printk(puVar3);
  }
  else {
    lVar2 = kmalloc_trace(_qtee_shmbridge_free_shm,0xcc0,0x216);
    *(long *)(param_1 + 8) = lVar2;
    if (lVar2 != 0) {
      lVar2 = kmalloc_trace(_qseecom_send_command,0xcc0,0x81);
      *(long *)(param_1 + 0x18) = lVar2;
      if (lVar2 != 0) {
        iVar1 = hdcp2_app_load(param_1);
        if (iVar1 != 0) goto LAB_001048b0;
        local_50 = 0;
        if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
          if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
            pcVar4 = *(code **)(param_1 + 0x38);
            if (pcVar4 == (code *)0x0) {
              _printk(&DAT_00106382);
            }
            else {
              local_4c = *(undefined4 *)(param_1 + 0x7c);
              local_48 = &local_4c;
              uStack_40 = 4;
              uStack_30 = 4;
              if (*(int *)(pcVar4 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x104874);
                local_38 = (undefined1 *)&local_50;
                (*pcVar4)();
              }
              local_38 = (undefined1 *)&local_50;
              iVar1 = (*pcVar4)(*(undefined8 *)(param_1 + 0x40),0xb,&local_48,0x11);
              if (iVar1 != 0) {
                _printk(&DAT_00106149,iVar1);
                goto LAB_001048b0;
              }
              *(undefined4 *)(param_1 + 0x78) = local_50;
              *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
            }
          }
          else {
            _printk(&DAT_00106556);
          }
          iVar1 = hdcp2_app_tx_init(param_1);
          goto LAB_001048b0;
        }
        puVar3 = &DAT_00106cfc;
        goto LAB_001048a8;
      }
    }
  }
  iVar1 = -0x16;
LAB_001048b0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// hdcp2_app_load @ 00104924 size=460
// signature: undefined hdcp2_app_load(void)
// callers: [hdcp2_feature_supported_smcinvoke, hdcp2_app_start_smcinvoke]
//------------------------------------------------------------

int hdcp2_app_load(long param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  long lVar5;
  undefined4 local_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    _printk(&DAT_00105cf4);
    iVar3 = 0;
    goto LAB_00104a00;
  }
  iVar3 = load_app("hdcp2p2",(long *)(param_1 + 0x38),param_1 + 0x48);
  if (iVar3 == 0) {
    if (*(long *)(param_1 + 0x38) == 0) {
      puVar4 = &DAT_00106706;
    }
    else {
      plVar1 = (long *)(param_1 + 0x58);
      iVar3 = load_app("hdcpsrm",plVar1,param_1 + 0x68);
      if (iVar3 == 0) {
        lVar5 = *plVar1;
      }
      else {
        if (iVar3 != 0x10) {
          puVar4 = &DAT_0010619e;
          goto LAB_00104a9c;
        }
        _printk(&DAT_00106bb0);
        lVar5 = *plVar1;
      }
      if (lVar5 != 0) {
        local_4c = 0;
        if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
          local_48 = &local_4c;
          uStack_40 = 4;
          if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x822a,0x1049dc);
            (*pcVar2)();
          }
          iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),10,&local_48,0x10);
          if (iVar3 != 0) {
            _printk(&DAT_00106c48,iVar3);
            _printk(&DAT_001060f6);
            goto LAB_00104a00;
          }
        }
        else {
          _printk(&DAT_00105cf4);
        }
        iVar3 = hdcp2_app_init(param_1);
        if (iVar3 == 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 1;
        }
        else {
          _printk(&DAT_00106408);
        }
        goto LAB_00104a00;
      }
      puVar4 = &DAT_00106cde;
    }
    _printk(puVar4);
    iVar3 = -0x16;
  }
  else {
    puVar4 = &DAT_00106127;
LAB_00104a9c:
    _printk(puVar4,iVar3);
  }
LAB_00104a00:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_start_auth_smcinvoke @ 00104af4 size=388
// signature: undefined hdcp2_app_start_auth_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_start_auth_smcinvoke(undefined4 *param_1,undefined4 param_2)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  code *pcVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 local_110;
  undefined4 local_108;
  undefined4 uStack_104;
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
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 local_80;
  undefined4 *local_78;
  undefined8 uStack_70;
  undefined1 *local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  ulong local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_80 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  if (param_1 == (undefined4 *)0x0) {
    puVar7 = &DAT_00106205;
  }
  else {
    param_1[4] = param_2;
    if (((uint)param_1[0xc] >> 1 & 1) == 0) {
      puVar7 = &DAT_0010602a;
    }
    else {
      if (((uint)param_1[0xc] >> 2 & 1) != 0) {
        uStack_104 = param_1[10];
        local_78 = &uStack_104;
        local_108 = 0;
        uStack_60 = 0xc;
        uStack_70 = 4;
        local_58 = &local_100;
        local_110 = 0;
        local_50 = 0x81;
        if (*(int *)(*(code **)(param_1 + 0xe) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x822a,0x104bb0);
          local_68 = (undefined1 *)&local_110;
          (*pcVar5)();
        }
        local_68 = (undefined1 *)&local_110;
        iVar6 = (**(code **)(param_1 + 0xe))(*(undefined8 *)(param_1 + 0x10),0xd,&local_78,0x21);
        uVar4 = local_50;
        uVar3 = local_108;
        if (iVar6 == 0) {
          if (0x81 < local_50) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("memcpy");
          }
          uVar2 = (undefined4)local_110;
          memcpy(*(void **)(param_1 + 6),&local_100,local_50);
          iVar6 = 0;
          param_1[8] = (int)uVar4;
          *param_1 = uVar2;
          *(undefined1 *)(param_1 + 1) = 0;
          param_1[10] = uVar3;
        }
        else {
          _printk(&DAT_00105c22,iVar6);
        }
        goto LAB_00104bf0;
      }
      puVar7 = &DAT_00106a97;
    }
  }
  _printk(puVar7);
  iVar6 = -0x16;
LAB_00104bf0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// hdcp2_app_process_msg_smcinvoke @ 00104c7c size=384
// signature: undefined hdcp2_app_process_msg_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_process_msg_smcinvoke(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  long lVar6;
  undefined8 local_120;
  undefined4 local_118;
  undefined4 uStack_114;
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
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined1 local_90;
  long local_88;
  ulong uStack_80;
  undefined4 *local_78;
  undefined8 uStack_70;
  undefined1 *local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  ulong local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_90 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  if (param_1 == (undefined4 *)0x0) {
    puVar5 = &DAT_00106205;
  }
  else {
    lVar6 = *(long *)(param_1 + 2);
    param_1[4] = param_2;
    if (lVar6 != 0) {
      uStack_114 = param_1[10];
      local_120 = 0;
      local_118 = 0;
      uStack_80 = (ulong)param_2;
      uStack_60 = 0xc;
      local_78 = &uStack_114;
      local_58 = &local_110;
      uStack_70 = 4;
      local_50 = 0x81;
      local_88 = lVar6;
      if (*(int *)(*(code **)(param_1 + 0xe) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x104d3c);
        local_68 = (undefined1 *)&local_120;
        (*pcVar3)();
      }
      local_68 = (undefined1 *)&local_120;
      iVar4 = (**(code **)(param_1 + 0xe))(*(undefined8 *)(param_1 + 0x10),4,&local_88,0x22);
      uVar2 = local_50;
      if (iVar4 == 0) {
        if (0x81 < local_50) {
                    /* WARNING: Subroutine does not return */
          fortify_panic("memcpy");
        }
        uVar1 = (undefined4)local_120;
        iVar4 = local_120._4_4_;
        memcpy(*(void **)(param_1 + 6),&local_110,local_50);
        if (iVar4 == 1) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        iVar4 = 0;
        param_1[8] = (int)uVar2;
        *param_1 = uVar1;
      }
      else {
        _printk(&DAT_00105c43,iVar4);
      }
      goto LAB_00104d80;
    }
    puVar5 = &DAT_00105c82;
  }
  _printk(puVar5);
  iVar4 = -0x16;
LAB_00104d80:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdcp2_app_timeout_smcinvoke @ 00104e00 size=328
// signature: undefined hdcp2_app_timeout_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_timeout_smcinvoke(undefined4 *param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
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
  undefined1 local_70;
  undefined4 *local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  ulong local_50;
  undefined4 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_f8 = 0;
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  if (param_1 == (undefined4 *)0x0) {
    _printk(&DAT_00106205);
    iVar4 = -0x16;
  }
  else {
    local_f4 = param_1[10];
    local_58 = &local_f0;
    local_68 = &local_f4;
    param_1[4] = param_2;
    local_50 = 0x81;
    uStack_60 = 4;
    local_48 = &local_f8;
    uStack_40 = 4;
    if (*(int *)(*(code **)(param_1 + 0xe) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822a,0x104ea8);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(param_1 + 0xe))(*(undefined8 *)(param_1 + 0x10),5,&local_68,0x21);
    uVar2 = local_50;
    if (iVar4 == 0) {
      if (0x81 < local_50) {
                    /* WARNING: Subroutine does not return */
        fortify_panic("memcpy");
      }
      memcpy(*(void **)(param_1 + 6),&local_f0,local_50);
      iVar4 = 0;
      param_1[8] = (int)uVar2;
      *param_1 = local_f8;
    }
    else {
      _printk(&DAT_00105ef9,iVar4);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdcp2_app_enable_encryption_smcinvoke @ 00104f4c size=224
// signature: undefined hdcp2_app_enable_encryption_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_enable_encryption_smcinvoke(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00106205);
    iVar3 = -0x16;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = param_2;
    msleep(300);
    local_38 = &local_3c;
    local_3c = *(undefined4 *)(param_1 + 0x28);
    uStack_30 = 4;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x822b,0x104fbc);
      (*pcVar2)();
    }
    iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),6,&local_38,1);
    if (iVar3 == 0) {
      *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 8;
    }
    else {
      _printk(&DAT_00106696,iVar3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_app_query_stream_smcinvoke @ 00105030 size=328
// signature: undefined hdcp2_app_query_stream_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_query_stream_smcinvoke(undefined4 *param_1,undefined4 param_2)

{
  long lVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
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
  undefined1 local_70;
  undefined4 *local_68;
  undefined8 uStack_60;
  undefined8 *local_58;
  ulong local_50;
  undefined4 *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_f8 = 0;
  local_70 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  if (param_1 == (undefined4 *)0x0) {
    _printk(&DAT_00106205);
    iVar4 = -0x16;
  }
  else {
    local_f4 = param_1[10];
    local_58 = &local_f0;
    local_68 = &local_f4;
    param_1[4] = param_2;
    local_50 = 0x81;
    uStack_60 = 4;
    local_48 = &local_f8;
    uStack_40 = 4;
    if (*(int *)(*(code **)(param_1 + 0xe) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822a,0x1050d8);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(param_1 + 0xe))(*(undefined8 *)(param_1 + 0x10),7,&local_68,0x21);
    uVar2 = local_50;
    if (iVar4 == 0) {
      if (0x81 < local_50) {
                    /* WARNING: Subroutine does not return */
        fortify_panic("memcpy");
      }
      memcpy(*(void **)(param_1 + 6),&local_f0,local_50);
      iVar4 = 0;
      param_1[8] = (int)uVar2;
      *param_1 = local_f8;
    }
    else {
      _printk(&DAT_00106b88,iVar4);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdcp2_app_stop_smcinvoke @ 0010517c size=404
// signature: undefined hdcp2_app_stop_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_app_stop_smcinvoke(long param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (param_1 == 0) {
    puVar5 = &DAT_00106205;
  }
  else if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
    puVar5 = &DAT_00105e73;
  }
  else if ((*(uint *)(param_1 + 0x30) >> 2 & 1) == 0) {
    puVar5 = &DAT_00106a97;
  }
  else {
    local_38 = &local_3c;
    local_3c = *(undefined4 *)(param_1 + 0x28);
    uStack_30 = 4;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x1051ec);
      (*pcVar3)();
    }
    iVar4 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),3,&local_38,1);
    if (iVar4 != 0) {
      puVar5 = &DAT_00106dad;
LAB_001052d8:
      _printk(puVar5,iVar4);
      goto LAB_001052e0;
    }
    uVar1 = *(uint *)(param_1 + 0x30);
    *(uint *)(param_1 + 0x30) = uVar1 & 0xfffffffb;
    if ((uVar1 & 1) == 0) {
      puVar5 = &DAT_00106cfc;
    }
    else {
      if ((uVar1 >> 1 & 1) != 0) {
        local_38 = &local_3c;
        local_3c = *(undefined4 *)(param_1 + 0x78);
        uStack_30 = 4;
        if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x105244);
          (*pcVar3)();
        }
        iVar4 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),0xc,&local_38,1);
        if (iVar4 == 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffd;
          iVar4 = hdcp2_app_unload(param_1);
          kfree(*(undefined8 *)(param_1 + 8));
          kfree(*(undefined8 *)(param_1 + 0x18));
          goto LAB_001052e0;
        }
        puVar5 = &DAT_001061bc;
        goto LAB_001052d8;
      }
      puVar5 = &DAT_0010602a;
    }
  }
  _printk(puVar5);
  iVar4 = -0x16;
LAB_001052e0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// hdcp2_app_unload @ 00105310 size=372
// signature: undefined hdcp2_app_unload(void)
// callers: [hdcp2_feature_supported_smcinvoke, hdcp2_app_stop_smcinvoke]
//------------------------------------------------------------

int hdcp2_app_unload(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 *puVar3;
  
  puVar3 = (undefined8 *)(param_1 + 0x38);
  if (*(int *)((code *)*puVar3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105354);
    (*pcVar1)();
  }
  iVar2 = (*(code *)*puVar3)(*(undefined8 *)(param_1 + 0x40),9,0,0);
  if (iVar2 == 0) {
    pcVar1 = (code *)*puVar3;
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105390);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + 0x40),0xffff,0,0);
    }
    *puVar3 = 0;
    *(undefined8 *)(param_1 + 0x40) = 0;
    pcVar1 = *(code **)(param_1 + 0x48);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1053cc);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + 0x50),0xffff,0,0);
    }
    *(undefined8 *)(param_1 + 0x48) = 0;
    *(undefined8 *)(param_1 + 0x50) = 0;
    pcVar1 = *(code **)(param_1 + 0x58);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105408);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + 0x60),0xffff,0,0);
    }
    *(undefined8 *)(param_1 + 0x58) = 0;
    *(undefined8 *)(param_1 + 0x60) = 0;
    pcVar1 = *(code **)(param_1 + 0x68);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105444);
        (*pcVar1)();
      }
      (*pcVar1)(*(undefined8 *)(param_1 + 0x70),0xffff,0,0);
    }
    *(undefined8 *)(param_1 + 0x68) = 0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) & 0xfffffffe;
  }
  else {
    _printk(&DAT_00106acd,iVar2);
  }
  return iVar2;
}



//------------------------------------------------------------
// hdcp2_feature_supported_smcinvoke @ 00105488 size=216
// signature: undefined hdcp2_feature_supported_smcinvoke(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp2_feature_supported_smcinvoke(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    _printk(&DAT_00106222);
  }
  else {
    if (*(char *)(param_1 + 0x2c) != '\0') {
      return 1;
    }
    iVar2 = hdcp2_app_load(param_1);
    if (iVar2 == 0) {
      if ((*(byte *)(param_1 + 0x30) & 1) == 0) {
        _printk(&DAT_00105fba,"hdcp2p2");
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
        if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1054f0);
          (*pcVar1)();
        }
        iVar2 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),1,0,0);
        if (iVar2 == 0) {
          *(undefined1 *)(param_1 + 0x2c) = 1;
        }
        else {
          _printk(&DAT_001068b5,iVar2);
          uVar3 = 0;
        }
      }
      hdcp2_app_unload(param_1);
      return uVar3;
    }
  }
  return 0;
}



//------------------------------------------------------------
// hdcp2_force_encryption_smcinvoke @ 00105564 size=224
// signature: undefined hdcp2_force_encryption_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_force_encryption_smcinvoke(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00106205);
    iVar3 = -0x16;
  }
  else {
    if (*(int *)(param_1 + 0x30) == 8) {
      msleep(200);
    }
    local_40 = *(undefined4 *)(param_1 + 0x28);
    uStack_30 = 8;
    uStack_3c = param_2;
    if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1055e0);
      local_38 = (undefined1 *)&local_40;
      (*pcVar2)();
    }
    local_38 = (undefined1 *)&local_40;
    iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),0x10,&local_38,1);
    if (iVar3 != 0) {
      _printk(&DAT_00106c66,iVar3);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_open_stream_smcinvoke @ 00105648 size=272
// signature: undefined hdcp2_open_stream_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_open_stream_smcinvoke(long param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 local_5c;
  undefined4 local_58;
  uint uStack_54;
  uint local_50;
  undefined4 uStack_4c;
  undefined4 *local_48;
  undefined8 uStack_40;
  undefined4 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_5c = 0;
  if (param_1 == 0) {
    puVar4 = &DAT_00106205;
  }
  else if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
    puVar4 = &DAT_0010602a;
  }
  else {
    if ((*(uint *)(param_1 + 0x30) >> 2 & 1) != 0) {
      local_48 = &local_58;
      local_58 = *(undefined4 *)(param_1 + 0x78);
      uStack_54 = param_2 & 0xff;
      uStack_40 = 0x10;
      local_50 = param_3 & 0xff;
      uStack_4c = 0;
      local_38 = &local_5c;
      uStack_30 = 4;
      if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x822a,0x1056d4);
        (*pcVar2)();
      }
      iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),0xe,&local_48,0x11);
      if (iVar3 == 0) {
        *param_4 = local_5c;
      }
      else {
        _printk(&DAT_00106514,iVar3);
      }
      goto LAB_001056e8;
    }
    puVar4 = &DAT_00106a97;
  }
  _printk(puVar4);
  iVar3 = -0x16;
LAB_001056e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_close_stream_smcinvoke @ 0010575c size=232
// signature: undefined hdcp2_close_stream_smcinvoke(void)
// callers: []
//------------------------------------------------------------

int hdcp2_close_stream_smcinvoke(long param_1,undefined4 param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 *local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if (param_1 == 0) {
    puVar4 = &DAT_00106205;
  }
  else if ((*(uint *)(param_1 + 0x30) >> 1 & 1) == 0) {
    puVar4 = &DAT_0010602a;
  }
  else {
    if ((*(uint *)(param_1 + 0x30) >> 2 & 1) != 0) {
      local_40 = *(undefined4 *)(param_1 + 0x78);
      uStack_30 = 8;
      uStack_3c = param_2;
      if (*(int *)(*(code **)(param_1 + 0x38) + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1057c8);
        local_38 = (undefined1 *)&local_40;
        (*pcVar2)();
      }
      local_38 = (undefined1 *)&local_40;
      iVar3 = (**(code **)(param_1 + 0x38))(*(undefined8 *)(param_1 + 0x40),0xf,&local_38,1);
      if (iVar3 != 0) {
        _printk(&DAT_00105e0d,iVar3);
      }
      goto LAB_001057d4;
    }
    puVar4 = &DAT_00106a97;
  }
  _printk(puVar4);
  iVar3 = -0x16;
LAB_001057d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// hdcp2_update_app_data_smcinvoke @ 00105848 size=104
// signature: undefined hdcp2_update_app_data_smcinvoke(void)
// callers: []
//------------------------------------------------------------

undefined8 hdcp2_update_app_data_smcinvoke(undefined4 *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (undefined4 *)0x0)) {
    _printk(&DAT_00106205);
    uVar1 = 0xffffffea;
  }
  else {
    *(undefined8 *)(param_2 + 2) = *(undefined8 *)(param_1 + 2);
    param_2[4] = param_1[4];
    *(undefined8 *)(param_2 + 6) = *(undefined8 *)(param_1 + 6);
    param_2[8] = param_1[8];
    *param_2 = *param_1;
    uVar1 = 0;
    *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 1);
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001059e4 size=292
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  
  lVar1 = of_find_compatible_node(0,0,"qcom,hdcp");
  if (lVar1 == 0) {
    ta_interface = hdcp1_init_qseecom;
    DAT_00105b18 = hdcp1_feature_supported_qseecom;
    DAT_00105b20 = hdcp1_set_enc_qseecom;
    DAT_00105b28 = hdcp1_ops_notify_qseecom;
    DAT_00105b30 = hdcp1_start_qseecom;
    DAT_00105b38 = hdcp1_stop_qseecom;
    DAT_00105b40 = hdcp2_init_qseecom;
    DAT_00105b48 = hdcp2_deinit_qseecom;
    DAT_00105b50 = hdcp2_app_start_qseecom;
    DAT_00105b58 = hdcp2_app_start_auth_qseecom;
    DAT_00105b60 = hdcp2_app_process_msg_qseecom;
    DAT_00105b68 = hdcp2_app_timeout_qseecom;
    DAT_00105b70 = hdcp2_app_enable_encryption_qseecom;
    DAT_00105b78 = hdcp2_app_query_stream_qseecom;
    DAT_00105b80 = hdcp2_app_stop_qseecom;
    DAT_00105b88 = hdcp2_feature_supported_qseecom;
    DAT_00105b90 = hdcp2_force_encryption_qseecom;
    DAT_00105b98 = hdcp2_open_stream_qseecom;
    DAT_00105ba0 = hdcp2_close_stream_qseecom;
    DAT_00105ba8 = hdcp2_update_app_data_qseecom;
  }
  else {
    lVar1 = of_find_property(lVar1,"qcom,use-smcinvoke",0);
    select_interface(lVar1 != 0);
  }
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00105b0c size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// _printk @ 00108000 size=1
// signature: undefined _printk(void)
// callers: [hdcp2_app_stop_qseecom, hdcp1_app_load, hdcp1_start_smcinvoke, hdcp1_start_qseecom, hdcp2_app_start_smcinvoke, hdcp2_open_stream_qseecom, hdcp1_app_unload, hdcp2_app_unload, hdcp2_update_app_data_qseecom, hdcp2_app_process_msg_smcinvoke, hdcp2_app_timeout_smcinvoke, hdcp2_app_start_auth_qseecom, hdcp2_app_tx_init, hdcp2_app_load, hdcp2_app_init, hdcp2_app_tx_init, hdcp2_feature_supported_smcinvoke, hdcp2_close_stream_qseecom, hdcp2_app_unload, hdcp2_deinit_qseecom, hdcp2_app_start_auth_smcinvoke, hdcp2_app_enable_encryption_smcinvoke, hdcp_get_version, hdcp2_app_init_legacy, load_app, hdcp1_set_enc_smcinvoke, hdcp1_feature_supported_qseecom, hdcp2_feature_supported_qseecom, hdcp2_app_comm, hdcp1_ops_notify_qseecom, hdcp1_stop_qseecom, hdcp1_app_unload, hdcp2_app_stop_smcinvoke, hdcp2_close_stream_smcinvoke, hdcp1_set_enc_qseecom, hdcp1_ops_notify_smcinvoke, hdcp2_app_query_stream_smcinvoke, hdcp2_app_enable_encryption_qseecom, hdcp2_app_tx_deinit, hdcp1_stop_smcinvoke, hdcp2_app_start_qseecom, hdcp2_app_query_stream_qseecom, hdcp2_force_encryption_smcinvoke, hdcp2_app_process_msg_qseecom, hdcp2_app_timeout_qseecom, hdcp2_open_stream_smcinvoke, hdcp2_app_tx_init_legacy, hdcp2_update_app_data_smcinvoke, hdcp1_validate_aksv, hdcp1_feature_supported_smcinvoke, hdcp2_force_encryption_qseecom, hdcp1_app_load, hdcp2_app_init, hdcp2_app_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00108008 size=1
// signature: undefined mutex_lock(void)
// callers: [hdcp2_feature_supported, hdcp2_open_stream, hdcp1_feature_supported, hdcp1_start, hdcp2_close_stream, hdcp1_stop, hdcp1_set_enc, hdcp2_app_comm, hdcp1_init, hdcp2_force_encryption, hdcp2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00108010 size=1
// signature: undefined mutex_unlock(void)
// callers: [hdcp2_feature_supported, hdcp2_open_stream, hdcp1_feature_supported, hdcp1_start, hdcp2_close_stream, hdcp1_stop, hdcp1_set_enc, hdcp2_app_comm, hdcp1_init, hdcp2_force_encryption, hdcp2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00108018 size=1
// signature: undefined kfree(void)
// callers: [hdcp2_app_stop_smcinvoke, hdcp1_deinit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 00108020 size=1
// signature: undefined of_find_compatible_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_compatible_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00108028 size=1
// signature: undefined of_find_property(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00108038 size=1
// signature: undefined kmalloc_trace(void)
// callers: [hdcp1_init_smcinvoke, hdcp1_init_qseecom, hdcp1_start_smcinvoke, hdcp2_init_smcinvoke, hdcp2_app_start_smcinvoke, hdcp2_init_qseecom]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qseecom_send_command @ 00108040 size=1
// signature: undefined qseecom_send_command(void)
// callers: [hdcp2_app_stop_qseecom, hdcp1_ops_notify_qseecom, hdcp2_close_stream_qseecom, hdcp2_app_start_qseecom, hdcp1_start_qseecom, hdcp2_app_query_stream_qseecom, hdcp2_open_stream_qseecom, hdcp2_app_unload, hdcp2_app_process_msg_qseecom, hdcp2_app_timeout_qseecom, hdcp2_app_tx_init_legacy, hdcp1_set_enc_qseecom, hdcp2_app_start_auth_qseecom, hdcp2_force_encryption_qseecom, hdcp2_app_tx_init, hdcp2_app_init_legacy, hdcp1_feature_supported_qseecom, hdcp2_feature_supported_qseecom, hdcp2_app_init, hdcp2_app_load, hdcp2_app_enable_encryption_qseecom]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qseecom_send_command(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 00108048 size=1
// signature: undefined msleep(void)
// callers: [hdcp2_force_encryption_qseecom, hdcp2_app_enable_encryption_smcinvoke, hdcp2_force_encryption_smcinvoke, hdcp1_feature_supported_qseecom, hdcp2_feature_supported_qseecom, hdcp2_app_enable_encryption_qseecom]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qseecom_start_app @ 00108050 size=1
// signature: undefined qseecom_start_app(void)
// callers: [hdcp1_app_load, hdcp2_app_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qseecom_start_app(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qseecom_shutdown_app @ 00108058 size=1
// signature: undefined qseecom_shutdown_app(void)
// callers: [hdcp1_app_unload, hdcp2_app_load, hdcp2_app_unload]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qseecom_shutdown_app(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_sensitive @ 00108060 size=1
// signature: undefined kfree_sensitive(void)
// callers: [hdcp2_deinit_smcinvoke, hdcp2_init_qseecom, hdcp2_deinit_qseecom]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_sensitive(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00108068 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [hdcp2_app_process_msg_smcinvoke, hdcp2_app_timeout_smcinvoke, hdcp2_app_start_auth_qseecom, hdcp2_app_start_auth_smcinvoke, hdcp2_app_query_stream_smcinvoke, hdcp2_app_query_stream_qseecom, hdcp2_app_process_msg_qseecom, hdcp2_app_timeout_qseecom]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// firmware_request_from_smcinvoke @ 00108070 size=1
// signature: undefined firmware_request_from_smcinvoke(void)
// callers: [load_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void firmware_request_from_smcinvoke(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_client_env_object @ 00108078 size=1
// signature: undefined get_client_env_object(void)
// callers: [load_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_client_env_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qtee_shmbridge_free_shm @ 00108080 size=1
// signature: undefined qtee_shmbridge_free_shm(void)
// callers: [load_app]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qtee_shmbridge_free_shm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [hdcp2_app_tx_init, hdcp1_start_smcinvoke, hdcp2_app_start_smcinvoke, hdcp2_app_stop_smcinvoke, hdcp2_force_encryption_smcinvoke, hdcp2_close_stream_smcinvoke, hdcp2_open_stream_smcinvoke, hdcp2_app_process_msg_smcinvoke, hdcp2_app_timeout_smcinvoke, hdcp1_feature_supported_smcinvoke, hdcp2_app_start_auth_smcinvoke, hdcp2_app_enable_encryption_smcinvoke, hdcp2_app_query_stream_smcinvoke, hdcp_get_version, load_app, hdcp1_set_enc_smcinvoke, hdcp2_app_init, hdcp2_app_tx_deinit, hdcp2_app_load]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00108090 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [hdcp2_app_process_msg_smcinvoke, hdcp2_app_timeout_smcinvoke, hdcp2_app_start_auth_smcinvoke, hdcp2_app_query_stream_smcinvoke]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



