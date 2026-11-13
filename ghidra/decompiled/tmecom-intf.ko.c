// Decompiled by Ghidra 12.2
// Program: tmecom-intf.ko
// Image base: 00100000

//------------------------------------------------------------
// tmecom_process_request @ 00100534 size=632
// signature: undefined tmecom_process_request(void)
// callers: [tme_hwkm_master_derivekey, tmelog_process_request, tmecom_debugfs_write, tme_hwkm_master_clearkey, tme_hwkm_master_unwrapkey, tme_hwkm_master_importkey, tme_hwkm_master_broadcast_transportkey, tme_hwkm_master_wrapkey, tme_hwkm_master_generatekey]
//------------------------------------------------------------

undefined8 tmecom_process_request(void *param_1,size_t param_2,long param_3,ulong *param_4)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  char cVar3;
  undefined8 *puVar4;
  long lVar5;
  int iVar6;
  ulong uVar7;
  char *pcVar8;
  long lVar9;
  undefined8 uVar10;
  uint *puVar11;
  long lVar12;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  puVar4 = tmedev;
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  if (tmedev == (undefined8 *)0x0) {
    _printk(&DAT_0010224a,"tmecom_process_request",0x67,"tmecom_process_request");
    uVar10 = 0xffffffed;
  }
  else {
    if ((param_1 == (void *)0x0) || (param_2 - 0x401 < 0xfffffffffffffbff || param_2 == 0)) {
      uVar10 = *tmedev;
      pcVar8 = "invalid reqbuf or reqsize\n";
    }
    else {
      if (((param_3 != 0) && (param_4 != (ulong *)0x0)) && (*param_4 < 0x401)) {
        puVar1 = tmedev + 9;
        mutex_lock(puVar1);
        *(undefined1 *)(puVar4 + 0x15) = 0;
        memcpy((void *)(puVar4[0x14] + 8),param_1,param_2);
        puVar11 = (uint *)(puVar4 + 0xf);
        *puVar11 = (int)param_2 + 0xbU & 0xfffffffc;
        puVar4[0x10] = puVar4[0x14];
        iVar6 = mbox_send_message(puVar4[8],puVar11);
        if (iVar6 < 0) {
          _dev_err(*puVar4,"failed to send qmp message\n");
          uVar10 = 0xfffffff5;
        }
        else {
          lVar9 = puVar4[3];
          if (lVar9 == 0 && *(char *)(puVar4 + 0x15) != '\0') {
            lVar9 = 1;
          }
          if ((*(char *)(puVar4 + 0x15) == '\0') && (lVar9 != 0)) {
            local_68 = 0;
            uStack_60 = 0;
            lVar12 = puVar4[3];
            local_78 = 0;
            uStack_70 = 0;
            local_80 = 0;
            init_wait_entry(&local_80,0);
            puVar2 = puVar4 + 0x11;
            lVar9 = prepare_to_wait_event(puVar2,&local_80,1);
            cVar3 = *(char *)(puVar4 + 0x15);
            if (lVar12 == 0 && cVar3 != '\0') {
              lVar12 = 1;
            }
            while ((lVar5 = lVar12, cVar3 == '\0' && (lVar5 = 0, lVar12 != 0))) {
              if (lVar9 != 0) goto LAB_00100730;
              lVar12 = schedule_timeout(lVar12);
              lVar9 = prepare_to_wait_event(puVar2,&local_80,1);
              cVar3 = *(char *)(puVar4 + 0x15);
              if (lVar12 == 0 && cVar3 != '\0') {
                lVar12 = 1;
              }
            }
            lVar9 = lVar5;
            finish_wait(puVar2,&local_80);
          }
LAB_00100730:
          if (lVar9 == 0) {
            _dev_err(*puVar4,"request timed out\n");
            uVar10 = 0xffffff92;
          }
          else {
            _dev_info(*puVar4,"response received\n");
            if (*puVar11 < 0xd) {
              _dev_err(*puVar4,"invalid pkt.size received\n");
              uVar10 = 0xffffffb9;
            }
            else {
              uVar7 = tmecom_decode(puVar4,param_3);
              uVar10 = 0;
              *param_4 = uVar7;
              *(undefined1 *)(puVar4 + 0x15) = 0;
            }
          }
        }
        mutex_unlock(puVar1);
        goto LAB_001005e8;
      }
      uVar10 = *tmedev;
      pcVar8 = "invalid respbuf or respsize\n";
    }
    _dev_err(uVar10,pcVar8);
    uVar10 = 0xffffffea;
  }
LAB_001005e8:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// tmecom_decode @ 001007ac size=72
// signature: undefined tmecom_decode(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

long tmecom_decode(long param_1,void *param_2)

{
  memcpy(param_2,(void *)(*(long *)(param_1 + 0x80) + 0xc),(ulong)*(uint *)(param_1 + 0x78) - 0xc);
  return (ulong)*(uint *)(param_1 + 0x78) - 0xc;
}



//------------------------------------------------------------
// tmecom_probe @ 001007f8 size=464
// signature: undefined tmecom_probe(void)
// callers: []
//------------------------------------------------------------

void tmecom_probe(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  long *plVar3;
  undefined8 uVar4;
  char *param3;
  ulong uVar5;
  long lVar6;
  char local_58 [32];
  long local_38;
  
  lVar6 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar6 + 0x638);
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  plVar3 = (long *)devm_kmalloc(lVar1,0xb0,0xdc0);
  if (plVar3 != (long *)0x0) {
    uVar4 = *(undefined8 *)(param_1 + 0x2f8);
    plVar3[1] = lVar1;
    *(undefined1 *)(plVar3 + 2) = 1;
    plVar3[3] = 500;
    *(undefined1 *)(plVar3 + 4) = 0;
    plVar3[5] = (long)tmecom_receive_message;
    param3 = (char *)of_get_property(uVar4,"mbox-names",0);
    if (param3 == (char *)0x0) {
      uVar2 = 0xffffffea;
      goto LAB_00100940;
    }
    snprintf(local_58,0x20,"%s_send_message",param3);
    uVar5 = mbox_request_channel(plVar3 + 1,0);
    plVar3[8] = uVar5;
    if (0xfffffffffffff000 < uVar5) {
      _dev_err(lVar1,"failed to get mbox channel\n");
      uVar2 = (undefined4)plVar3[8];
      goto LAB_00100940;
    }
    __mutex_init(plVar3 + 9,"&tdev->lock",&tmecom_probe___key);
    if (plVar3[8] != 0) {
      lVar6 = devm_kmalloc(lVar1,0x400,0xdc0);
      plVar3[0x14] = lVar6;
      if (lVar6 == 0) {
        _dev_err(lVar1,"message buffer alloc faile\n");
        goto LAB_00100934;
      }
    }
    __init_waitqueue_head(plVar3 + 0x11,"&tdev->waitq",&tmecom_probe___key_19);
    debugfs_file = debugfs_create_file(local_58,0x90,0,plVar3,tmecom_debugfs_ops);
    if (debugfs_file != 0) {
      *(undefined1 *)(plVar3 + 0x15) = 0;
      *plVar3 = lVar1;
      *(long **)(param_1 + 0xa8) = plVar3;
      tmedev = plVar3;
      _dev_info(param_1 + 0x10,"tmecom probe success\n");
      uVar2 = 0;
      goto LAB_00100940;
    }
    mbox_free_channel(plVar3[8]);
  }
LAB_00100934:
  uVar2 = 0xfffffff4;
LAB_00100940:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// tmecom_remove @ 001009cc size=84
// signature: undefined tmecom_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 tmecom_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  debugfs_remove(debugfs_file);
  if (*(long *)(lVar1 + 0x40) != 0) {
    mbox_free_channel();
  }
  _dev_info(param_1 + 0x10,"tmecom remove success\n");
  return 0;
}



//------------------------------------------------------------
// tmecom_receive_message @ 00100a24 size=136
// signature: undefined tmecom_receive_message(void)
// callers: []
//------------------------------------------------------------

void tmecom_receive_message(long *param_1,undefined4 *param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  puVar2 = *(undefined8 **)(*param_1 + 0x98);
  if (param_2 == (undefined4 *)0x0) {
    _dev_err(*puVar2,"spurious message received\n");
  }
  else if (*(char *)(puVar2 + 0x15) == '\0') {
    *(undefined4 *)(puVar2 + 0xf) = *param_2;
    uVar1 = *(undefined8 *)(param_2 + 2);
    *(undefined1 *)(puVar2 + 0x15) = 1;
    puVar2[0x10] = uVar1;
  }
  else {
    _dev_err(*puVar2,"tmecom response pending\n");
  }
  __wake_up(puVar2 + 0x11,1,1,0);
  return;
}



//------------------------------------------------------------
// tmecom_debugfs_write @ 00100ab0 size=504
// signature: undefined tmecom_debugfs_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

size_t tmecom_debugfs_write(undefined8 param_1,ulong param_2,size_t param_3)

{
  long lVar1;
  ulong uVar2;
  size_t __n;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  if (param_3 - 0x401 < 0xfffffffffffffbff || param_3 == 0) {
    _printk(&DAT_001022bb,"tmecom_debugfs_write",0xb3);
    param_3 = 0xffffffffffffffea;
    goto LAB_00100c00;
  }
  dpkt = 0;
  __check_object_size(&dpkt,param_3,0);
  puVar3 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
     (uVar4 = param_2, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
    uVar4 = param_2 & (long)(param_2 << 8) >> 8;
  }
  __n = param_3;
  if (0x8000000000 - param_3 < uVar4) {
LAB_00100c50:
    memset(&dpkt + (param_3 - __n),0,__n);
    if ((int)__n != 0) {
      _printk(&DAT_0010205f,"tmecom_debugfs_write",0xba,"tmecom_debugfs_write",__n & 0xffffffff);
      goto LAB_00100c00;
    }
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      puVar3 = (undefined8 *)puVar3[1];
      uVar2 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar3 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar3;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    __n = __arch_copy_from_user(puVar3,&dpkt,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar4 = daif;
      if ((uVar4 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar4;
    }
    if (__n != 0) goto LAB_00100c50;
  }
  tmecom_process_request(&dpkt,param_3,&dpkt,&local_40);
  tme_hwkm_master_broadcast_transportkey(&dpkt);
LAB_00100c00:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// tme_hwkm_master_clearkey @ 00100cec size=340
// signature: undefined tme_hwkm_master_clearkey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_clearkey(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  int *piVar9;
  long local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_50 = 0x14;
  if (param_2 == (int *)0x0) {
    uVar7 = 0xffffffea;
  }
  else {
    puVar8 = (undefined8 *)kmalloc_trace(_DAT_00104128,0xdc0,0xc);
    piVar9 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar7 = 0xfffffff4;
    if ((puVar8 != (undefined8 *)0x0) && (piVar9 != (int *)0x0)) {
      *(undefined4 *)(puVar8 + 1) = param_1;
      *puVar8 = 0x482f01d9;
      uVar7 = tmecom_process_request(puVar8,0xc,piVar9,&local_50);
      if (uVar7 == 0) {
        if (local_50 == 0x14) {
          iVar1 = *piVar9;
          iVar3 = piVar9[1];
          iVar2 = piVar9[2];
          iVar4 = piVar9[3];
          *param_2 = iVar1;
          param_2[1] = iVar3;
          iVar5 = piVar9[4];
          param_2[2] = iVar2;
          param_2[3] = iVar4;
          uVar7 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_2[4] = iVar5;
        }
        else {
          _printk(&DAT_001022e6,local_50,8);
          uVar7 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_00101f95,param_1);
      }
    }
    kfree(puVar8);
    kfree(piVar9);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// tme_hwkm_master_generatekey @ 00100e44 size=372
// signature: undefined tme_hwkm_master_generatekey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_generatekey
               (undefined4 param_1,undefined8 *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  int *piVar9;
  undefined8 uVar10;
  long local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  uVar7 = 0xffffffea;
  local_60 = 0x14;
  if ((param_2 != (undefined8 *)0x0) && (param_4 != (int *)0x0)) {
    puVar8 = (undefined8 *)kmalloc_trace(_DAT_00104128,0xdc0,0x18);
    piVar9 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar7 = 0xfffffff4;
    if ((puVar8 != (undefined8 *)0x0) && (piVar9 != (int *)0x0)) {
      uVar10 = *param_2;
      *(undefined4 *)(puVar8 + 1) = param_1;
      *(undefined4 *)((long)puVar8 + 0x14) = param_3;
      *puVar8 = 0x1542f01d9;
      *(undefined8 *)((long)puVar8 + 0xc) = uVar10;
      uVar7 = tmecom_process_request(puVar8,0x18,piVar9,&local_60);
      if (uVar7 == 0) {
        if (local_60 == 0x14) {
          iVar1 = *piVar9;
          iVar3 = piVar9[1];
          iVar2 = piVar9[2];
          iVar4 = piVar9[3];
          *param_4 = iVar1;
          param_4[1] = iVar3;
          iVar5 = piVar9[4];
          param_4[2] = iVar2;
          param_4[3] = iVar4;
          uVar7 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_4[4] = iVar5;
        }
        else {
          _printk(&DAT_001022e6,local_60,8);
          uVar7 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_00102275,param_1);
      }
    }
    kfree(puVar8);
    kfree(piVar9);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// tme_hwkm_master_derivekey @ 00100fbc size=384
// signature: undefined tme_hwkm_master_derivekey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_derivekey(undefined4 param_1,void *param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  int *piVar9;
  long local_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  uVar7 = 0xffffffea;
  local_60 = 0x14;
  if ((param_2 != (void *)0x0) && (param_4 != (int *)0x0)) {
    puVar8 = (undefined8 *)kmalloc_trace(_DAT_00104138,0xdc0,0xf8);
    piVar9 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar7 = 0xfffffff4;
    if ((puVar8 != (undefined8 *)0x0) && (piVar9 != (int *)0x0)) {
      *(undefined4 *)(puVar8 + 1) = param_1;
      *(undefined4 *)((long)puVar8 + 0xf4) = param_3;
      *puVar8 = 0x2582f01d9;
      memcpy((void *)((long)puVar8 + 0xc),param_2,0xe8);
      uVar7 = tmecom_process_request(puVar8,0xf8,piVar9,&local_60);
      if (uVar7 == 0) {
        if (local_60 == 0x14) {
          iVar1 = *piVar9;
          iVar3 = piVar9[1];
          iVar2 = piVar9[2];
          iVar4 = piVar9[3];
          *param_4 = iVar1;
          param_4[1] = iVar3;
          iVar5 = piVar9[4];
          param_4[2] = iVar2;
          param_4[3] = iVar4;
          uVar7 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_4[4] = iVar5;
        }
        else {
          _printk(&DAT_001022e6,local_60,8);
          uVar7 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_00102197,param_1);
      }
    }
    kfree(puVar8);
    kfree(piVar9);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// tme_hwkm_master_wrapkey @ 00101140 size=412
// signature: undefined tme_hwkm_master_wrapkey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int tme_hwkm_master_wrapkey
              (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4,
              int *param_5)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  undefined8 *puVar10;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  iVar9 = -0x16;
  local_50 = 0x7c;
  if ((param_4 != (undefined8 *)0x0) && (param_5 != (int *)0x0)) {
    puVar10 = (undefined8 *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    if (puVar10 == (undefined8 *)0x0) {
      iVar9 = -0xc;
    }
    else {
      *(undefined4 *)(puVar10 + 1) = param_1;
      *(undefined4 *)((long)puVar10 + 0xc) = param_2;
      *puVar10 = 0x3502f01d9;
      iVar9 = tmecom_process_request(puVar10,0x14,&gwrpk_response,&local_50);
      iVar2 = gwrpk_response;
      if (iVar9 == 0) {
        if (local_50 == 0x7c) {
          iVar9 = 1;
          *param_5 = gwrpk_response;
          iVar3 = DAT_00101e80;
          param_5[1] = DAT_00101e80;
          iVar4 = DAT_00101e84;
          param_5[2] = DAT_00101e84;
          iVar5 = DAT_00101e88;
          param_5[3] = DAT_00101e88;
          param_5[4] = DAT_00101e8c;
          if ((((iVar2 == 0) && (iVar3 == 0)) && (iVar4 == 0)) && (iVar5 == 0)) {
            iVar9 = 0;
            *param_4 = DAT_00101e90;
            uVar8 = DAT_00101eb0;
            uVar7 = DAT_00101ea0;
            uVar6 = DAT_00101e98;
            param_4[3] = DAT_00101ea8;
            param_4[4] = uVar8;
            param_4[1] = uVar6;
            param_4[2] = uVar7;
            uVar8 = DAT_00101ed0;
            uVar7 = DAT_00101ec0;
            uVar6 = DAT_00101eb8;
            param_4[7] = DAT_00101ec8;
            param_4[8] = uVar8;
            param_4[5] = uVar6;
            param_4[6] = uVar7;
            uVar8 = DAT_00101ef0;
            uVar7 = DAT_00101ee0;
            uVar6 = DAT_00101ed8;
            param_4[0xb] = DAT_00101ee8;
            param_4[0xc] = uVar8;
            param_4[9] = uVar6;
            param_4[10] = uVar7;
          }
        }
        else {
          _printk(&DAT_001022e6,local_50,8);
          iVar9 = -0x4a;
        }
      }
      else {
        _printk(&DAT_001021c0,param_1);
      }
      kfree(puVar10);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// tme_hwkm_master_unwrapkey @ 001012e0 size=420
// signature: undefined tme_hwkm_master_unwrapkey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_unwrapkey
               (undefined4 param_1,undefined4 param_2,undefined8 param_3,undefined8 *param_4,
               int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  int iVar9;
  long lVar10;
  uint uVar11;
  undefined8 *puVar12;
  int *piVar13;
  long local_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  uVar11 = 0xffffffea;
  local_60 = 0x14;
  if ((param_4 != (undefined8 *)0x0) && (param_5 != (int *)0x0)) {
    puVar12 = (undefined8 *)kmalloc_trace(_DAT_00104130,0xdc0,0x7c);
    piVar13 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar11 = 0xfffffff4;
    if ((puVar12 != (undefined8 *)0x0) && (piVar13 != (int *)0x0)) {
      uVar5 = param_4[10];
      uVar6 = param_4[0xb];
      puVar12[0xe] = param_4[0xc];
      *(undefined4 *)(puVar12 + 1) = param_1;
      *(undefined4 *)((long)puVar12 + 0xc) = param_2;
      *puVar12 = 0x4582f01d9;
      puVar12[0xc] = uVar5;
      puVar12[0xd] = uVar6;
      uVar6 = param_4[7];
      uVar5 = param_4[8];
      uVar7 = param_4[9];
      puVar12[8] = param_4[6];
      puVar12[9] = uVar6;
      uVar6 = param_4[2];
      uVar8 = param_4[3];
      puVar12[10] = uVar5;
      puVar12[0xb] = uVar7;
      uVar5 = param_4[4];
      uVar7 = param_4[5];
      puVar12[4] = uVar6;
      puVar12[5] = uVar8;
      uVar6 = *param_4;
      uVar8 = param_4[1];
      puVar12[6] = uVar5;
      puVar12[7] = uVar7;
      puVar12[2] = uVar6;
      puVar12[3] = uVar8;
      uVar11 = tmecom_process_request(puVar12,0x7c,piVar13,&local_60);
      if (uVar11 == 0) {
        if (local_60 == 0x14) {
          iVar1 = *piVar13;
          iVar3 = piVar13[1];
          iVar2 = piVar13[2];
          iVar4 = piVar13[3];
          *param_5 = iVar1;
          param_5[1] = iVar3;
          iVar9 = piVar13[4];
          param_5[2] = iVar2;
          param_5[3] = iVar4;
          uVar11 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_5[4] = iVar9;
        }
        else {
          _printk(&DAT_001022e6,local_60,8);
          uVar11 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_00101fbd,param_1);
      }
    }
    kfree(puVar12);
    kfree(piVar13);
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar11;
}



//------------------------------------------------------------
// tme_hwkm_master_importkey @ 00101488 size=440
// signature: undefined tme_hwkm_master_importkey(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_importkey
               (undefined4 param_1,undefined8 *param_2,undefined8 *param_3,undefined4 param_4,
               int *param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  uint uVar10;
  undefined8 *puVar11;
  int *piVar12;
  undefined8 uVar13;
  long local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  uVar10 = 0xffffffea;
  local_60 = 0x14;
  if (((param_2 != (undefined8 *)0x0) && (param_3 != (undefined8 *)0x0)) && (param_5 != (int *)0x0))
  {
    puVar11 = (undefined8 *)kmalloc_trace(_DAT_00104130,0xdc0,0x60);
    piVar12 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar10 = 0xfffffff4;
    if ((puVar11 != (undefined8 *)0x0) && (piVar12 != (int *)0x0)) {
      uVar5 = param_3[5];
      uVar6 = param_3[6];
      *(undefined8 *)((long)puVar11 + 0xc) = *param_2;
      *(undefined4 *)((long)puVar11 + 0x5c) = param_4;
      *puVar11 = 0x5582f01d9;
      *(undefined8 *)((long)puVar11 + 0x3c) = uVar5;
      uVar5 = param_3[7];
      uVar7 = param_3[8];
      *(undefined8 *)((long)puVar11 + 0x44) = uVar6;
      *(undefined4 *)(puVar11 + 1) = param_1;
      *(undefined8 *)((long)puVar11 + 0x4c) = uVar5;
      uVar5 = param_3[1];
      uVar6 = param_3[2];
      *(undefined8 *)((long)puVar11 + 0x54) = uVar7;
      uVar13 = *param_3;
      *(undefined8 *)((long)puVar11 + 0x1c) = uVar5;
      uVar5 = param_3[3];
      uVar7 = param_3[4];
      *(undefined8 *)((long)puVar11 + 0x24) = uVar6;
      *(undefined8 *)((long)puVar11 + 0x14) = uVar13;
      *(undefined8 *)((long)puVar11 + 0x2c) = uVar5;
      *(undefined8 *)((long)puVar11 + 0x34) = uVar7;
      uVar10 = tmecom_process_request(puVar11,0x60,piVar12,&local_60);
      if (uVar10 == 0) {
        if (local_60 == 0x14) {
          iVar1 = *piVar12;
          iVar3 = piVar12[1];
          iVar2 = piVar12[2];
          iVar4 = piVar12[3];
          *param_5 = iVar1;
          param_5[1] = iVar3;
          iVar8 = piVar12[4];
          param_5[2] = iVar2;
          param_5[3] = iVar4;
          uVar10 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_5[4] = iVar8;
        }
        else {
          _printk(&DAT_001022e6,local_60,8);
          uVar10 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_001020b6,param_1);
      }
    }
    kfree(puVar11);
    kfree(piVar12);
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// tme_hwkm_master_broadcast_transportkey @ 00101644 size=324
// signature: undefined tme_hwkm_master_broadcast_transportkey(void)
// callers: [tmecom_debugfs_write]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint tme_hwkm_master_broadcast_transportkey(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  uint uVar7;
  undefined8 *puVar8;
  int *piVar9;
  long local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0x14;
  if (param_1 == (int *)0x0) {
    uVar7 = 0xffffffea;
  }
  else {
    puVar8 = (undefined8 *)kmalloc_trace(_DAT_00104128,0xdc0,8);
    piVar9 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0x14);
    uVar7 = 0xfffffff4;
    if ((puVar8 != (undefined8 *)0x0) && (piVar9 != (int *)0x0)) {
      *puVar8 = 0x6442f01d9;
      uVar7 = tmecom_process_request(puVar8,8,piVar9,&local_40);
      if (uVar7 == 0) {
        if (local_40 == 0x14) {
          iVar1 = *piVar9;
          iVar3 = piVar9[1];
          iVar2 = piVar9[2];
          iVar4 = piVar9[3];
          *param_1 = iVar1;
          param_1[1] = iVar3;
          iVar5 = piVar9[4];
          param_1[2] = iVar2;
          param_1[3] = iVar4;
          uVar7 = (uint)((iVar1 != 0 || iVar3 != 0) || (iVar2 != 0 || iVar4 != 0));
          param_1[4] = iVar5;
        }
        else {
          _printk(&DAT_001022e6,local_40,8);
          uVar7 = 0xffffffb6;
        }
      }
      else {
        _printk(&DAT_001021f9);
      }
    }
    kfree(puVar8);
    kfree(piVar9);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// tmelog_process_request @ 0010178c size=392
// signature: undefined tmelog_process_request(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int tmelog_process_request(int param_1,undefined4 param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  long local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((param_1 == 0) || (param_3 == (int *)0x0)) {
    _printk(&DAT_001020fb,"tmelog_process_request",0x27);
    iVar2 = -0x16;
  }
  else {
    puVar3 = (undefined4 *)kmalloc_trace(_DAT_00104128,0xdc0,0xc);
    piVar4 = (int *)kmalloc_trace(_DAT_00104128,0xdc0,0xc);
    if ((piVar4 == (int *)0x0) || (puVar3 == (undefined4 *)0x0)) {
      _printk(&DAT_00101ef8,"tmelog_process_request",0x2e);
      iVar2 = -0xc;
    }
    else {
      puVar3[1] = param_2;
      puVar3[2] = param_1;
      *puVar3 = 0x481801d9;
      *piVar4 = -1;
      iVar2 = tmecom_process_request(puVar3,0xc,piVar4,&local_50);
      if (iVar2 == 0) {
        if (local_50 == 0xc) {
          iVar2 = *piVar4;
          *param_3 = piVar4[1];
        }
        else {
          _printk(&DAT_0010231a,"tmelog_process_request",0x44,local_50,8);
          iVar2 = -0x4a;
        }
      }
      else {
        _printk(&DAT_0010201b,"tmelog_process_request",0x3e,iVar2);
      }
    }
    kfree(puVar3);
    kfree(piVar4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// init_module @ 00101a0c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&tmecom_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101a3c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&tmecom_driver);
  return;
}



//------------------------------------------------------------
// _printk @ 00104000 size=1
// signature: undefined _printk(void)
// callers: [tme_hwkm_master_derivekey, tmecom_process_request, tmelog_process_request, tmecom_debugfs_write, tme_hwkm_master_clearkey, tme_hwkm_master_unwrapkey, tme_hwkm_master_importkey, tme_hwkm_master_broadcast_transportkey, tme_hwkm_master_wrapkey, tme_hwkm_master_generatekey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104008 size=1
// signature: undefined _dev_err(void)
// callers: [tmecom_receive_message, tmecom_process_request, tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104010 size=1
// signature: undefined mutex_lock(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104018 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [tme_hwkm_master_derivekey, tmecom_process_request, tmecom_decode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 00104020 size=1
// signature: undefined mbox_send_message(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00104028 size=1
// signature: undefined init_wait_entry(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00104030 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00104038 size=1
// signature: undefined schedule_timeout(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00104040 size=1
// signature: undefined finish_wait(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00104048 size=1
// signature: undefined _dev_info(void)
// callers: [tmecom_remove, tmecom_process_request, tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104050 size=1
// signature: undefined mutex_unlock(void)
// callers: [tmecom_process_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [tme_hwkm_master_derivekey, tmecom_process_request, tmelog_process_request, tmecom_debugfs_write, tme_hwkm_master_clearkey, tme_hwkm_master_unwrapkey, tme_hwkm_master_importkey, tmecom_probe, tme_hwkm_master_broadcast_transportkey, tme_hwkm_master_wrapkey, tme_hwkm_master_generatekey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104060 size=1
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
// platform_driver_unregister @ 00104068 size=1
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
// devm_kmalloc @ 00104070 size=1
// signature: undefined devm_kmalloc(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00104078 size=1
// signature: undefined of_get_property(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00104080 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 00104088 size=1
// signature: undefined mbox_request_channel(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104090 size=1
// signature: undefined __mutex_init(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104098 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001040a0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 001040a8 size=1
// signature: undefined mbox_free_channel(void)
// callers: [tmecom_remove, tmecom_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001040b0 size=1
// signature: undefined debugfs_remove(void)
// callers: [tmecom_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001040b8 size=1
// signature: undefined __wake_up(void)
// callers: [tmecom_receive_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 001040c0 size=1
// signature: undefined __check_object_size(void)
// callers: [tmecom_debugfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001040d8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [tmecom_debugfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001040e0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [tmecom_debugfs_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [tme_hwkm_master_derivekey, tmelog_process_request, tme_hwkm_master_clearkey, tme_hwkm_master_unwrapkey, tme_hwkm_master_importkey, tme_hwkm_master_broadcast_transportkey, tme_hwkm_master_wrapkey, tme_hwkm_master_generatekey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104108 size=1
// signature: undefined kfree(void)
// callers: [tme_hwkm_master_derivekey, tmelog_process_request, tme_hwkm_master_clearkey, tme_hwkm_master_unwrapkey, tme_hwkm_master_importkey, tme_hwkm_master_broadcast_transportkey, tme_hwkm_master_wrapkey, tme_hwkm_master_generatekey]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



