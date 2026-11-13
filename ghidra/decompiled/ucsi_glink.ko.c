// Decompiled by Ghidra 12.2
// Program: ucsi_glink.ko
// Image base: 00100000

//------------------------------------------------------------
// register_ucsi_glink_notifier @ 0010043c size=40
// signature: undefined register_ucsi_glink_notifier(void)
// callers: []
//------------------------------------------------------------

void register_ucsi_glink_notifier(undefined8 param_1)

{
  raw_notifier_chain_register(&ucsi_glink_notifier,param_1);
  return;
}



//------------------------------------------------------------
// unregister_ucsi_glink_notifier @ 00100468 size=40
// signature: undefined unregister_ucsi_glink_notifier(void)
// callers: []
//------------------------------------------------------------

void unregister_ucsi_glink_notifier(undefined8 param_1)

{
  raw_notifier_chain_unregister(&ucsi_glink_notifier,param_1);
  return;
}



//------------------------------------------------------------
// ucsi_probe @ 00100494 size=632
// signature: undefined ucsi_probe(void)
// callers: []
//------------------------------------------------------------

ulong ucsi_probe(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  ulong uVar5;
  undefined *local_70;
  undefined8 local_68;
  long *local_60;
  code *pcStack_58;
  code *local_50;
  long local_48;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_48 = *(long *)(lVar2 + 0x638);
  local_68 = 0;
  plVar3 = (long *)devm_kmalloc(lVar1,0x238,0xdc0);
  if (plVar3 == (long *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    plVar3[0x32] = (long)(plVar3 + 0x32);
    plVar3[0x33] = (long)(plVar3 + 0x32);
    plVar3[0x34] = 0xfffffffe0;
    plVar3[0x35] = (long)(plVar3 + 0x35);
    plVar3[0x36] = (long)(plVar3 + 0x35);
    plVar3[0x3a] = 0xfffffffe0;
    plVar3[0x37] = (long)ucsi_qti_notify_work;
    plVar3[0x3b] = (long)(plVar3 + 0x3b);
    plVar3[0x3c] = (long)(plVar3 + 0x3b);
    plVar3[0x40] = 0xfffffffe0;
    plVar3[0x3d] = (long)ucsi_qti_setup_work;
    plVar3[0x41] = (long)(plVar3 + 0x41);
    plVar3[0x42] = (long)(plVar3 + 0x41);
    plVar3[0x43] = (long)ucsi_qti_unregister_work;
    __mutex_init(plVar3 + 0xf,"&udev->read_lock",&ucsi_probe___key);
    __mutex_init(plVar3 + 0x15,"&udev->write_lock",&ucsi_probe___key_2);
    __mutex_init(plVar3 + 0x1b,"&udev->notify_lock",&ucsi_probe___key_4);
    __mutex_init(plVar3 + 0x21,"&udev->state_lock",&ucsi_probe___key_6);
    *(undefined4 *)(plVar3 + 3) = 0;
    __init_swait_queue_head(plVar3 + 4,"&x->wait",&init_completion___key);
    *(undefined4 *)(plVar3 + 7) = 0;
    __init_swait_queue_head(plVar3 + 8,"&x->wait",&init_completion___key);
    *(undefined4 *)(plVar3 + 0xb) = 0;
    __init_swait_queue_head(plVar3 + 0xc,"&x->wait",&init_completion___key);
    *(undefined4 *)(plVar3 + 0x30) = 0;
    *(undefined4 *)(plVar3 + 0x46) = 1;
    local_68 = CONCAT44(local_68._4_4_,0x800b);
    local_70 = &DAT_00101c37;
    pcStack_58 = ucsi_callback;
    local_50 = ucsi_qti_state_cb;
    local_60 = plVar3;
    uVar4 = pmic_glink_register_client(lVar1,&local_70);
    plVar3[2] = uVar4;
    if (uVar4 < 0xfffffffffffff001) {
      *(long **)(param_1 + 0xa8) = plVar3;
      *plVar3 = lVar1;
      ucsi_ipc_log = ipc_log_context_create(10,&DAT_00101c37,0);
      if (ucsi_ipc_log == 0) {
        _dev_warn(lVar1,"Error in creating ipc_log_context\n");
      }
      uVar5 = ucsi_setup(plVar3);
      uVar4 = uVar5 & 0xffffffff;
      if ((int)uVar5 != 0) {
        ipc_log_context_destroy(ucsi_ipc_log);
        ucsi_ipc_log = 0;
        pmic_glink_unregister_client(plVar3[2]);
      }
    }
    else if ((int)uVar4 == -0x205) {
      uVar4 = 0xfffffdfb;
    }
    else {
      _dev_err(lVar1,"Error in registering with pmic_glink rc=%d\n",uVar4 & 0xffffffff);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4 & 0xffffffff;
}



//------------------------------------------------------------
// ucsi_remove @ 00100710 size=284
// signature: undefined ucsi_remove(void)
// callers: []
//------------------------------------------------------------

int ucsi_remove(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  int iVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  
  lVar7 = *(long *)(param_1 + 0xa8);
  cancel_work_sync(lVar7 + 0x1a0);
  cancel_work_sync(lVar7 + 0x1d0);
  uVar6 = cancel_work_sync(lVar7 + 0x200);
  if ((uVar6 & 1) == 0) {
    mutex_lock(lVar7 + 0xd8);
    plVar1 = (long *)(lVar7 + 400);
    plVar4 = *(long **)(lVar7 + 400);
    while (plVar4 != plVar1) {
      plVar8 = (long *)*plVar4;
      uVar6 = __list_del_entry_valid(plVar4);
      if ((uVar6 & 1) != 0) {
        lVar2 = *plVar4;
        plVar3 = (long *)plVar4[1];
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      kfree(plVar4);
      plVar4 = plVar8;
    }
    *(long **)(lVar7 + 400) = plVar1;
    *(long **)(lVar7 + 0x198) = plVar1;
    mutex_unlock(lVar7 + 0xd8);
    ucsi_unregister(*(undefined8 *)(lVar7 + 8));
    ucsi_destroy(*(undefined8 *)(lVar7 + 8));
  }
  iVar5 = pmic_glink_unregister_client(*(undefined8 *)(lVar7 + 0x10));
  if (iVar5 < 0) {
    _dev_err(param_1 + 0x10,"pmic_glink_unregister_client failed rc=%d\n",iVar5);
  }
  ipc_log_context_destroy(ucsi_ipc_log);
  ucsi_ipc_log = 0;
  return iVar5;
}



//------------------------------------------------------------
// ucsi_qti_notify_work @ 00100830 size=192
// signature: undefined ucsi_qti_notify_work(void)
// callers: []
//------------------------------------------------------------

void ucsi_qti_notify_work(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  
  lVar4 = param_1 + -200;
  mutex_lock(lVar4);
  plVar5 = (long *)(param_1 + -0x10);
  plVar6 = (long *)*plVar5;
  while (plVar6 != plVar5) {
    uVar3 = __list_del_entry_valid(plVar6);
    if ((uVar3 & 1) != 0) {
      lVar1 = *plVar6;
      plVar2 = (long *)plVar6[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar6 = -0x2152ffffffffff00;
    plVar6[1] = -0x2152fffffffffede;
    mutex_unlock(lVar4);
    raw_notifier_call_chain(&ucsi_glink_notifier,0,plVar6 + 2);
    kfree(plVar6);
    mutex_lock(lVar4);
    plVar6 = (long *)*plVar5;
  }
  mutex_unlock(lVar4);
  return;
}



//------------------------------------------------------------
// ucsi_qti_setup_work @ 001008f4 size=32
// signature: undefined ucsi_qti_setup_work(void)
// callers: []
//------------------------------------------------------------

void ucsi_qti_setup_work(long param_1)

{
  ucsi_setup(param_1 + -0x1d0);
  return;
}



//------------------------------------------------------------
// ucsi_qti_unregister_work @ 00100918 size=232
// signature: undefined ucsi_qti_unregister_work(void)
// callers: []
//------------------------------------------------------------

void ucsi_qti_unregister_work(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  long *plVar7;
  
  plVar5 = (long *)(param_1 + -0x1f8);
  if (*plVar5 != 0) {
    mutex_lock(param_1 + -0xf8);
    mutex_lock(param_1 + -0x128);
    plVar6 = (long *)(param_1 + -0x70);
    plVar3 = (long *)*plVar6;
    while (plVar3 != plVar6) {
      plVar7 = (long *)*plVar3;
      uVar4 = __list_del_entry_valid(plVar3);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar3;
        plVar2 = (long *)plVar3[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar3 = -0x2152ffffffffff00;
      plVar3[1] = -0x2152fffffffffede;
      kfree(plVar3);
      plVar3 = plVar7;
    }
    *(long *)(param_1 + -0x70) = param_1 + -0x70;
    *(long **)(param_1 + -0x68) = plVar6;
    mutex_unlock(param_1 + -0x128);
    ucsi_unregister(*plVar5);
    ucsi_destroy(*plVar5);
    *plVar5 = 0;
    mutex_unlock(param_1 + -0xf8);
  }
  return;
}



//------------------------------------------------------------
// ucsi_callback @ 00100a04 size=804
// signature: undefined ucsi_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ucsi_callback(long param_1,undefined8 *param_2,long param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  uint uVar8;
  int iVar9;
  code *pcVar10;
  long lVar11;
  undefined *puVar12;
  char *pcVar13;
  int iVar14;
  ulong uVar15;
  uint local_3c;
  long local_38;
  
  lVar11 = sp_el0;
  local_38 = *(long *)(lVar11 + 0x638);
  if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x100a54);
    (*pcVar10)();
  }
  lVar11 = (*_arch_timer_read_counter)();
  uVar15 = (ulong)(lVar11 * 1000) / 19200000000;
  iVar14 = (int)(uVar15 / 0xe10);
  iVar9 = (int)(uVar15 / 0x3c) + iVar14 * -0x3c;
  ipc_log_string(ucsi_ipc_log,"owner: %u type: %u opcode: %u len:%zu (%02u:%02u:%02u.%06u)\n",
                 *(undefined4 *)param_2,*(undefined4 *)((long)param_2 + 4),
                 *(undefined4 *)(param_2 + 1),param_3,uVar15 / 0xe10,iVar9,
                 (int)uVar15 + iVar14 * -0xe10 + iVar9 * -0x3c,
                 (int)((ulong)(lVar11 * 1000) / 0x4b00) + (int)uVar15 * -1000000);
  iVar9 = *(int *)(param_2 + 1);
  if (iVar9 != 0x13) {
    if (iVar9 == 0x12) {
      if (param_3 != 0x10) {
        _printk(&DAT_00101b0a,"handle_ucsi_write_ack",param_3,0x10);
        goto LAB_00100cf4;
      }
      if (*(int *)((long)param_2 + 0xc) == 0) {
        complete(param_1 + 0x38);
        goto LAB_00100cf4;
      }
      puVar12 = &DAT_00101bba;
      pcVar13 = "handle_ucsi_write_ack";
    }
    else if (iVar9 == 0x11) {
      if (param_3 != 0x40) {
        _printk(&DAT_00101b0a,"handle_ucsi_read_ack",param_3,0x40);
        *(undefined4 *)(param_1 + 0x180) = 0;
        goto LAB_00100cf4;
      }
      uVar1 = param_2[6];
      uVar2 = param_2[4];
      uVar5 = param_2[5];
      *(undefined8 *)(param_1 + 0x170) = param_2[7];
      uVar3 = param_2[2];
      uVar6 = param_2[3];
      uVar4 = *param_2;
      uVar7 = param_2[1];
      *(undefined8 *)(param_1 + 0x160) = uVar5;
      *(undefined8 *)(param_1 + 0x168) = uVar1;
      *(undefined8 *)(param_1 + 0x158) = uVar2;
      *(undefined8 *)(param_1 + 0x148) = uVar3;
      *(undefined8 *)(param_1 + 0x150) = uVar6;
      *(undefined8 *)(param_1 + 0x138) = uVar4;
      *(undefined8 *)(param_1 + 0x140) = uVar7;
      if (*(int *)(param_1 + 0x174) == 0) {
        *(undefined4 *)(param_1 + 0x180) = 1;
        complete(param_1 + 0x18);
        goto LAB_00100cf4;
      }
      puVar12 = &DAT_00101bba;
      pcVar13 = "handle_ucsi_read_ack";
    }
    else {
      puVar12 = &DAT_00101a92;
      pcVar13 = "ucsi_callback";
    }
    _printk(puVar12,pcVar13);
    goto LAB_00100cf4;
  }
  if (param_3 != 0x18) {
    _printk(&DAT_00101b0a,"handle_ucsi_notify",param_3,0x18);
    goto LAB_00100cf4;
  }
  mutex_lock(param_1 + 0x108);
  if (*(int *)(param_1 + 0x230) == 0) {
    puVar12 = &DAT_001019d0;
LAB_00100ce0:
    _printk(puVar12,"handle_ucsi_notify");
  }
  else {
    if (*(long *)(param_1 + 8) == 0) {
      puVar12 = &DAT_00101bfd;
      goto LAB_00100ce0;
    }
    uVar8 = *(uint *)((long)param_2 + 0xc);
    local_3c = uVar8;
    ucsi_log("notify:",4,&local_3c,4);
    if ((((uint)*(undefined8 *)(param_1 + 0x178) >> 1 & 1) != 0) && ((uVar8 & 0xa0000000) != 0)) {
      complete(param_1 + 0x58);
    }
    if (1 < (uVar8 & 0xff)) {
      uVar8 = uVar8 >> 1 & 0x7f;
      if ((((uVar8 <= *(byte *)(*(long *)(param_1 + 8) + 0x24)) &&
           (lVar11 = *(long *)(*(long *)(param_1 + 8) + 0x30), lVar11 != 0)) &&
          (uVar8 = uVar8 - 1, lVar11 + (ulong)uVar8 * 0x3a0 != 0)) &&
         (*(long *)(lVar11 + (ulong)uVar8 * 0x3a0 + 8) != 0)) {
        ucsi_connector_change();
      }
    }
  }
  mutex_unlock(param_1 + 0x108);
LAB_00100cf4:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ucsi_qti_state_cb @ 00100d2c size=128
// signature: undefined ucsi_qti_state_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ucsi_qti_state_cb(long param_1,int param_2)

{
  mutex_lock(param_1 + 0x108);
  *(int *)(param_1 + 0x230) = param_2;
  mutex_unlock(param_1 + 0x108);
  if (param_2 == 1) {
    cancel_work_sync(param_1 + 0x200);
    param_1 = param_1 + 0x1d0;
  }
  else {
    if (param_2 != 0) {
      return;
    }
    cancel_work_sync(param_1 + 0x1d0);
    param_1 = param_1 + 0x200;
  }
  queue_work_on(0x20,_system_wq,param_1);
  return;
}



//------------------------------------------------------------
// ucsi_setup @ 00100dac size=220
// signature: undefined ucsi_setup(void)
// callers: [ucsi_probe, ucsi_qti_setup_work]
//------------------------------------------------------------

ulong ucsi_setup(undefined8 *param_1)

{
  ulong uVar1;
  ulong uVar2;
  
  if (param_1[1] != 0) {
    _dev_err(*param_1,"ucsi is not NULL\n");
    uVar1 = 0xffffffea;
    goto LAB_00100e1c;
  }
  mutex_lock(param_1 + 0x21);
  uVar1 = ucsi_create(*param_1,&ucsi_qti_ops);
  param_1[1] = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    ucsi_set_drvdata(uVar1,param_1);
    uVar2 = ucsi_register(param_1[1]);
    uVar1 = uVar2 & 0xffffffff;
    if ((int)uVar2 != 0) {
      _dev_err(*param_1,"ucsi_register failed rc=%d\n",uVar1);
      ucsi_destroy(param_1[1]);
      goto LAB_00100e80;
    }
  }
  else {
    _dev_err(*param_1,"ucsi_create failed rc=%d\n",uVar1 & 0xffffffff);
LAB_00100e80:
    param_1[1] = 0;
  }
  mutex_unlock(param_1 + 0x21);
LAB_00100e1c:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// ucsi_log @ 00100e88 size=520
// signature: undefined ucsi_log(void)
// callers: [ucsi_callback, ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ucsi_log(undefined8 param_1,uint param_2,long param_3,ulong param_4)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  int iVar6;
  ulong uVar7;
  ulong uVar8;
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
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
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
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
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
  if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100f28);
    (*pcVar2)();
  }
  lVar4 = (*_arch_timer_read_counter)();
  if (param_4 == 0) {
    uVar7 = 0;
  }
  else {
    uVar8 = 0;
    uVar7 = 0;
    do {
      iVar3 = scnprintf((long)&local_170 + uVar7,0x100 - uVar7,"%02x ",
                        *(undefined1 *)(param_3 + uVar8));
      uVar8 = (ulong)((int)uVar8 + 1);
      uVar1 = iVar3 + (int)uVar7;
      uVar7 = (ulong)uVar1;
      if (param_4 <= uVar8) break;
    } while (uVar1 < 0xff);
    if (0xff < uVar1) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100f8c);
      (*pcVar2)();
    }
  }
  uVar1 = param_2 >> 2 | param_2 << 0x1e;
  *(undefined1 *)((long)&local_170 + uVar7) = 0;
  if (uVar1 < 9) {
    pcVar5 = (&PTR_DAT_00101e48)[(int)uVar1];
  }
  else {
    pcVar5 = "UNKNOWN:";
  }
  uVar7 = (ulong)(lVar4 * 1000) / 19200000000;
  iVar6 = (int)(uVar7 / 0xe10);
  iVar3 = (int)(uVar7 / 0x3c) + iVar6 * -0x3c;
  ipc_log_string(ucsi_ipc_log,"%s %s %s (%02u:%02u:%02u.%06u)\n",param_1,pcVar5,&local_170,
                 uVar7 / 0xe10,iVar3,(int)uVar7 + iVar6 * -0xe10 + iVar3 * -0x3c,
                 (int)((ulong)(lVar4 * 1000) / 0x4b00) + (int)uVar7 * -1000000);
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ucsi_qti_read @ 00101094 size=652
// signature: undefined ucsi_qti_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ucsi_qti_read(undefined8 param_1,uint param_2,void *param_3,ulong param_4)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  ushort uVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  undefined8 local_68;
  undefined4 local_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  lVar7 = ucsi_get_drvdata();
  if (((param_2 < 0x30) && (param_4 < 0x31)) && (param_2 + param_4 < 0x31)) {
    if (*(int *)(lVar7 + 0x230) == 0) {
      iVar6 = 0;
    }
    else {
      local_68 = 0x10000800b;
      local_60 = 0x11;
      mutex_lock(lVar7 + 0x78);
      *(undefined4 *)(lVar7 + 0x18) = 0;
      iVar6 = pmic_glink_write(*(undefined8 *)(lVar7 + 0x10),&local_68,0xc);
      if (iVar6 < 0) {
        _printk(&DAT_001019f1,"ucsi_qti_read",iVar6);
      }
      else {
        iVar6 = wait_for_completion_timeout((undefined4 *)(lVar7 + 0x18),0x4e2);
        if (iVar6 == 0) {
          _printk(&DAT_00101b42,"ucsi_qti_read");
          iVar6 = -0x6e;
        }
        else if (*(int *)(lVar7 + 0x180) == 0) {
          iVar6 = -0x3d;
        }
        else {
          memcpy(param_3,(void *)(lVar7 + (ulong)param_2 + 0x144),param_4);
          *(undefined4 *)(lVar7 + 0x180) = 0;
          ucsi_log("read:",param_2,param_3,param_4);
          iVar6 = 0;
          if (param_4 == 9) {
            lVar1 = lVar7 + 0xd8;
            mutex_lock(lVar1);
            uVar11 = *(undefined8 *)(lVar7 + 0x188);
            mutex_unlock(lVar1);
            iVar6 = 0;
            if ((param_2 == 0x10) && (((uint)uVar11 >> 1 & 1) != 0)) {
              plVar8 = (long *)kmalloc_trace(_DAT_00103158,0xdc0,0x18);
              if (plVar8 != (long *)0x0) {
                *plVar8 = (long)plVar8;
                plVar8[1] = (long)plVar8;
                uVar5 = *(ushort *)((long)param_3 + 2) >> 0xd;
                iVar6 = (uint)(uVar5 == 5) << 1;
                if (uVar5 == 6) {
                  iVar6 = 1;
                }
                *(int *)(plVar8 + 2) = iVar6;
                mutex_lock(lVar1);
                puVar10 = *(undefined8 **)(lVar7 + 0x198);
                uVar9 = __list_add_valid(plVar8,puVar10,lVar7 + 400);
                if ((uVar9 & 1) != 0) {
                  *(long **)(lVar7 + 0x198) = plVar8;
                  *plVar8 = lVar7 + 400;
                  plVar8[1] = (long)puVar10;
                  *puVar10 = plVar8;
                }
                puVar2 = (ulong *)(lVar7 + 0x188);
                Hint_Prefetch(puVar2,2,0,1);
                do {
                  cVar3 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
                  if (bVar4) {
                    *puVar2 = *puVar2 & 0xfffffffffffffffd;
                    cVar3 = ExclusiveMonitorsStatus();
                  }
                } while (cVar3 != '\0');
                mutex_unlock(lVar1);
                queue_work_on(0x20,_system_wq,lVar7 + 0x1a0);
              }
              iVar6 = 0;
            }
          }
        }
      }
      mutex_unlock(lVar7 + 0x78);
    }
  }
  else {
    _printk(&DAT_00101900,"validate_ucsi_msg",param_4,param_2);
    iVar6 = -0x16;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// ucsi_qti_sync_write @ 00101330 size=76
// signature: undefined ucsi_qti_sync_write(void)
// callers: []
//------------------------------------------------------------

void ucsi_qti_sync_write(undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4
                        )

{
  undefined8 uVar1;
  
  uVar1 = ucsi_get_drvdata();
  ucsi_qti_glink_write(uVar1,param_2,param_3,param_4,1);
  return;
}



//------------------------------------------------------------
// ucsi_qti_async_write @ 00101380 size=76
// signature: undefined ucsi_qti_async_write(void)
// callers: []
//------------------------------------------------------------

void ucsi_qti_async_write
               (undefined8 param_1,undefined4 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  
  uVar1 = ucsi_get_drvdata();
  ucsi_qti_glink_write(uVar1,param_2,param_3,param_4,0);
  return;
}



//------------------------------------------------------------
// ucsi_qti_glink_write @ 001013cc size=624
// signature: undefined ucsi_qti_glink_write(void)
// callers: [ucsi_qti_async_write, ucsi_qti_sync_write]
//------------------------------------------------------------

int ucsi_qti_glink_write(long param_1,uint param_2,char *param_3,ulong param_4,uint param_5)

{
  ulong *puVar1;
  char *pcVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined8 local_54;
  undefined4 local_4c;
  long local_48;
  
  lVar5 = sp_el0;
  uVar7 = (ulong)param_2;
  local_48 = *(long *)(lVar5 + 0x638);
  local_4c = 0;
  local_54 = 0;
  local_5c = 0;
  local_64 = 0;
  local_6c = 0;
  local_74 = 0;
  local_7c = 0;
  if (((0x2f < param_2) || (0x30 < param_4)) || (0x30 < uVar7 + param_4)) {
    _printk(&DAT_00101900,"validate_ucsi_msg",param_4);
    iVar6 = -0x16;
    goto LAB_00101558;
  }
  pcVar2 = "sync_write:";
  if ((param_5 & 1) == 0) {
    pcVar2 = "async_write:";
  }
  ucsi_log(pcVar2,uVar7,param_3,param_4);
  if (*(int *)(param_1 + 0x230) == 0) {
    iVar6 = 0;
    goto LAB_00101558;
  }
  local_88 = 0x10000800b;
  local_80 = 0x12;
  memcpy((void *)((long)&local_7c + uVar7),param_3,param_4);
  mutex_lock(param_1 + 0xa8);
  *(undefined4 *)(param_1 + 0x38) = 0;
  if ((param_5 & 1) != 0) {
    puVar1 = (ulong *)(param_1 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | 2;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    *(undefined4 *)(param_1 + 0x58) = 0;
  }
  iVar6 = pmic_glink_write(*(undefined8 *)(param_1 + 0x10),&local_88,0x40);
  if (iVar6 < 0) {
    _printk(&DAT_001019f1,"ucsi_qti_glink_write",iVar6);
LAB_00101534:
    if ((param_5 & 1) != 0) goto LAB_00101538;
  }
  else {
    iVar6 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x38),0x4e2);
    if (iVar6 == 0) {
      _printk(&DAT_00101b42,"ucsi_qti_glink_write");
      iVar6 = -0x6e;
      goto LAB_00101534;
    }
    if (((param_5 & 1) == 0) ||
       (iVar6 = wait_for_completion_timeout(param_1 + 0x58,0x4e2), iVar6 != 0)) {
      if (*param_3 == '\x12') {
        mutex_lock(param_1 + 0xd8);
        puVar1 = (ulong *)(param_1 + 0x188);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar4) {
            *puVar1 = *puVar1 | 2;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        mutex_unlock(param_1 + 0xd8);
      }
      iVar6 = 0;
      goto LAB_00101534;
    }
    _printk(&DAT_00101b59,"ucsi_qti_glink_write");
    iVar6 = -0x6e;
LAB_00101538:
    puVar1 = (ulong *)(param_1 + 0x178);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 & 0xfffffffffffffffd;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  mutex_unlock(param_1 + 0xa8);
LAB_00101558:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// init_module @ 001016a4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&ucsi_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001016d4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&ucsi_driver);
  return;
}



//------------------------------------------------------------
// raw_notifier_chain_register @ 00103000 size=1
// signature: undefined raw_notifier_chain_register(void)
// callers: [register_ucsi_glink_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_chain_unregister @ 00103008 size=1
// signature: undefined raw_notifier_chain_unregister(void)
// callers: [unregister_ucsi_glink_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103010 size=1
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
// platform_driver_unregister @ 00103018 size=1
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
// devm_kmalloc @ 00103020 size=1
// signature: undefined devm_kmalloc(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103028 size=1
// signature: undefined __mutex_init(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00103030 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00103038 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00103040 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00103048 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [ucsi_probe, ucsi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00103050 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [ucsi_probe, ucsi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103058 size=1
// signature: undefined _dev_err(void)
// callers: [ucsi_probe, ucsi_remove, ucsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00103060 size=1
// signature: undefined _dev_warn(void)
// callers: [ucsi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [ucsi_probe, ucsi_callback, ucsi_log, ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00103070 size=1
// signature: undefined cancel_work_sync(void)
// callers: [ucsi_remove, ucsi_qti_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103078 size=1
// signature: undefined mutex_lock(void)
// callers: [ucsi_callback, ucsi_qti_notify_work, ucsi_qti_unregister_work, ucsi_remove, ucsi_qti_read, ucsi_qti_glink_write, ucsi_setup, ucsi_qti_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103080 size=1
// signature: undefined kfree(void)
// callers: [ucsi_qti_notify_work, ucsi_qti_unregister_work, ucsi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103088 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [ucsi_qti_notify_work, ucsi_qti_unregister_work, ucsi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103090 size=1
// signature: undefined mutex_unlock(void)
// callers: [ucsi_callback, ucsi_qti_notify_work, ucsi_qti_unregister_work, ucsi_remove, ucsi_qti_read, ucsi_qti_glink_write, ucsi_setup, ucsi_qti_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_unregister @ 00103098 size=1
// signature: undefined ucsi_unregister(void)
// callers: [ucsi_qti_unregister_work, ucsi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_destroy @ 001030a0 size=1
// signature: undefined ucsi_destroy(void)
// callers: [ucsi_qti_unregister_work, ucsi_remove, ucsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// raw_notifier_call_chain @ 001030a8 size=1
// signature: undefined raw_notifier_call_chain(void)
// callers: [ucsi_qti_notify_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void raw_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 001030b8 size=1
// signature: undefined ipc_log_string(void)
// callers: [ucsi_callback, ucsi_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001030c0 size=1
// signature: undefined complete(void)
// callers: [ucsi_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_connector_change @ 001030c8 size=1
// signature: undefined ucsi_connector_change(void)
// callers: [ucsi_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_connector_change(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030d0 size=1
// signature: undefined _printk(void)
// callers: [ucsi_callback, ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030e0 size=1
// signature: undefined queue_work_on(void)
// callers: [ucsi_qti_read, ucsi_qti_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_create @ 001030e8 size=1
// signature: undefined ucsi_create(void)
// callers: [ucsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_set_drvdata @ 001030f0 size=1
// signature: undefined ucsi_set_drvdata(void)
// callers: [ucsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_set_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_register @ 001030f8 size=1
// signature: undefined ucsi_register(void)
// callers: [ucsi_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00103100 size=1
// signature: undefined scnprintf(void)
// callers: [ucsi_log]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ucsi_get_drvdata @ 00103108 size=1
// signature: undefined ucsi_get_drvdata(void)
// callers: [ucsi_qti_async_write, ucsi_qti_sync_write, ucsi_qti_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ucsi_get_drvdata(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00103110 size=1
// signature: undefined pmic_glink_write(void)
// callers: [ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00103118 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103120 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [ucsi_qti_read, ucsi_qti_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103130 size=1
// signature: undefined kmalloc_trace(void)
// callers: [ucsi_qti_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103138 size=1
// signature: undefined __list_add_valid(void)
// callers: [ucsi_qti_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



