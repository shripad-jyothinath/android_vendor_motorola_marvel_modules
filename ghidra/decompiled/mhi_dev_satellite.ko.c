// Decompiled by Ghidra 12.2
// Program: mhi_dev_satellite.ko
// Image base: 00100000

//------------------------------------------------------------
// init_module @ 00100364 size=560
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puVar3 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x120);
  if (puVar3 == (undefined8 *)0x0) {
    iVar2 = -0xc;
  }
  else {
    mhi_sat_driver_2 = 1;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    mhi_sat_driver_1 = puVar3;
    *puVar3 = &DAT_0010275f;
    __mutex_init(puVar3 + 4,"&subsys->cntrl_mutex",&mhi_sat_init___key);
    *(undefined4 *)(puVar3 + 10) = 0;
    puVar3[2] = puVar3 + 2;
    puVar3[3] = puVar3 + 2;
    scnprintf(&local_68,0x20,"mhi_sat_%s",*puVar3);
    uVar4 = ipc_log_context_create(10,&local_68,0);
    local_58 = 0;
    uStack_50 = 0;
    puVar3[0xb] = uVar4;
    puVar3[0xc] = &DAT_0010268c;
    local_68 = 0;
    uStack_60 = 0;
    __mutex_init(puVar3 + 0x10,"&subsys->cntrl_mutex",&mhi_sat_init___key);
    *(undefined4 *)(puVar3 + 0x16) = 0;
    puVar3[0xe] = puVar3 + 0xe;
    puVar3[0xf] = puVar3 + 0xe;
    scnprintf(&local_68,0x20,"mhi_sat_%s",puVar3[0xc]);
    uVar4 = ipc_log_context_create(10,&local_68,0);
    local_58 = 0;
    uStack_50 = 0;
    puVar3[0x17] = uVar4;
    puVar3[0x18] = &DAT_001026f1;
    local_68 = 0;
    uStack_60 = 0;
    __mutex_init(puVar3 + 0x1c,"&subsys->cntrl_mutex",&mhi_sat_init___key);
    *(undefined4 *)(puVar3 + 0x22) = 0;
    puVar3[0x1a] = puVar3 + 0x1a;
    puVar3[0x1b] = puVar3 + 0x1a;
    scnprintf(&local_68,0x20,"mhi_sat_%s",puVar3[0x18]);
    uVar4 = ipc_log_context_create(10,&local_68,0);
    puVar3[0x23] = uVar4;
    iVar2 = __register_rpmsg_driver(&mhi_sat_rpmsg_driver,&__this_module);
    if (iVar2 == 0) {
      iVar2 = __mhi_driver_register(&mhi_sat_dev_driver,&__this_module);
      if (iVar2 == 0) goto LAB_0010055c;
      unregister_rpmsg_driver(&mhi_sat_rpmsg_driver);
    }
    puVar3 = mhi_sat_driver_1;
    ipc_log_context_destroy(mhi_sat_driver_1[0xb]);
    ipc_log_context_destroy(puVar3[0x17]);
    ipc_log_context_destroy(puVar3[0x23]);
    kfree(mhi_sat_driver_1);
    mhi_sat_driver_1 = (undefined8 *)0x0;
  }
LAB_0010055c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// mhi_sat_rpmsg_probe @ 00100598 size=356
// signature: undefined mhi_sat_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_rpmsg_probe(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  char *__s1;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  undefined8 *puVar6;
  char *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = (char *)0x0;
  uVar4 = of_property_read_string
                    (*(undefined8 *)(*(long *)(param_1 + 0x60) + 0x2e8),"label",&local_50);
  __s1 = local_50;
  puVar2 = mhi_sat_driver_1;
  if ((int)uVar4 != 0) goto LAB_001006c8;
  if (mhi_sat_driver_2 == '\x01') {
    iVar3 = strcmp(local_50,(char *)*mhi_sat_driver_1);
    puVar6 = puVar2;
    if (iVar3 != 0) {
      puVar6 = puVar2 + 0xc;
      iVar3 = strcmp(__s1,(char *)*puVar6);
      if (iVar3 != 0) {
        puVar6 = puVar2 + 0x18;
        iVar3 = strcmp(__s1,(char *)*puVar6);
        if (iVar3 != 0) goto LAB_001006c4;
      }
    }
    if (puVar6 != (undefined8 *)0x0) {
      mutex_lock(puVar6 + 4);
      ipc_log_string(puVar6[0xb],"%s[I][%s] Received RPMSG probe\n",&DAT_001022b2,
                     "mhi_sat_rpmsg_probe");
      *(undefined8 **)(param_1 + 0x98) = puVar6;
      puVar6[1] = param_1;
      _raw_spin_lock_irq(puVar6 + 10);
      for (plVar5 = (long *)puVar6[2]; plVar5 != puVar6 + 2; plVar5 = (long *)*plVar5) {
        queue_work_on(0x20,_system_wq,plVar5 + 0x11);
      }
      _raw_spin_unlock_irq(puVar6 + 10);
      mutex_unlock(puVar6 + 4);
      uVar4 = 0;
      goto LAB_001006c8;
    }
  }
LAB_001006c4:
  uVar4 = 0xffffffea;
LAB_001006c8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// mhi_sat_rpmsg_remove @ 00100700 size=500
// signature: undefined mhi_sat_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void mhi_sat_rpmsg_remove(long param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  undefined8 *puVar7;
  long lVar8;
  
  lVar8 = *(long *)(param_1 + 0x98);
  if (lVar8 != 0) {
    ipc_log_string(*(undefined8 *)(lVar8 + 0x58),"%s[I][%s] Enter\n",&DAT_001022b2,
                   "mhi_sat_rpmsg_remove");
  }
  mutex_lock();
  for (plVar5 = *(long **)(lVar8 + 0x10); plVar5 != (long *)(lVar8 + 0x10); plVar5 = (long *)*plVar5
      ) {
    flush_work(plVar5 + 0x1d);
    lVar1 = (long)(plVar5 + 0x27);
    _raw_spin_lock_irq(lVar1);
    if (*(uint *)((long)plVar5 + 0x134) < 3) {
      *(undefined4 *)((long)plVar5 + 0x134) = 2;
      _raw_spin_unlock_irq(lVar1);
      flush_work(plVar5 + 0x11);
      flush_work(plVar5 + 0x17);
      mutex_lock(plVar5 + 8);
      for (puVar7 = (undefined8 *)plVar5[4]; puVar7 != plVar5 + 4; puVar7 = (undefined8 *)*puVar7) {
        if (*(char *)(puVar7 + 4) != '\0') {
          mhi_unprepare_from_transfer(puVar7[2]);
          *(undefined1 *)(puVar7 + 4) = 0;
        }
      }
      plVar3 = (long *)plVar5[6];
      while (plVar3 != plVar5 + 6) {
        plVar6 = (long *)*plVar3;
        if ((char)plVar3[7] == '\0') {
          dma_unmap_page_attrs
                    (*(undefined8 *)(*(long *)(plVar5[2] + 8) + 0x88),plVar3[4],plVar3[6],0,0x20);
        }
        else {
          dma_unmap_resource();
        }
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
        plVar3 = plVar6;
      }
      mutex_unlock(plVar5 + 8);
      if ((lVar8 != 0) && (plVar5 != (long *)0x0)) {
        ipc_log_string(*(undefined8 *)(lVar8 + 0x58),"%s[I][%s][%x] Removed RPMSG link\n",
                       &DAT_001022b2,"mhi_sat_rpmsg_remove",*(undefined4 *)(plVar5 + 0x23));
      }
    }
    else {
      *(undefined4 *)((long)plVar5 + 0x134) = 5;
      _raw_spin_unlock_irq(lVar1);
    }
  }
  *(undefined8 *)(lVar8 + 8) = 0;
  mutex_unlock(lVar8 + 0x20);
  return;
}



//------------------------------------------------------------
// mhi_sat_rpmsg_cb @ 001008f8 size=524
// signature: undefined mhi_sat_rpmsg_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_sat_rpmsg_cb(long param_1,short *param_2,uint param_3)

{
  undefined8 *puVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  long *plVar5;
  ulong uVar6;
  uint uVar7;
  undefined8 *puVar8;
  short *psVar9;
  undefined8 *puVar10;
  
  puVar8 = *(undefined8 **)(param_1 + 0x98);
  if ((((param_3 < 0x18) || ((ulong)(ushort)param_2[5] + 0x18 != (long)(int)param_3)) ||
      (*param_2 != 1)) || ((param_2[1] != 0 || ((param_2[2] & 0xfffdU) != 0xc)))) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100abc);
    (*pcVar3)();
  }
  puVar1 = puVar8 + 10;
  iVar2 = *(int *)(param_2 + 6);
  uVar4 = _raw_spin_lock_irqsave(puVar1);
  puVar10 = puVar8 + 2;
  do {
    puVar10 = (undefined8 *)*puVar10;
    if (puVar10 == puVar8 + 2) {
      _raw_spin_unlock_irqrestore(puVar1,uVar4);
      return 0;
    }
  } while (*(int *)(puVar10 + 0x23) != iVar2);
  _raw_spin_unlock_irqrestore(puVar1,uVar4);
  if (puVar10 != (undefined8 *)0x0) {
    if (param_2[2] == 0xe) {
      if (0xf < (ushort)param_2[5]) {
        uVar7 = (uint)((ushort)param_2[5] >> 4);
        psVar9 = param_2 + 0x12;
        do {
          if (((char)psVar9[1] == '!') && (param_2[4] == *(short *)((long)puVar10 + 0x13c))) {
            *(uint *)(puVar10 + 0x28) = (uint)*(byte *)((long)psVar9 + -1);
            complete(puVar10 + 0x29);
          }
          uVar7 = uVar7 - 1;
          psVar9 = psVar9 + 8;
        } while (uVar7 != 0);
      }
    }
    else if (*(int *)((long)puVar10 + 0x134) == 1) {
      plVar5 = (long *)__kmalloc((long)(int)param_3 + 0x20,0xa20);
      if (plVar5 != (long *)0x0) {
        plVar5[2] = (long)puVar10;
        plVar5[3] = (long)(plVar5 + 4);
        memcpy(plVar5 + 4,param_2,(long)(int)param_3);
        uVar4 = _raw_spin_lock_irqsave(puVar10 + 0x10);
        puVar8 = (undefined8 *)puVar10[0xf];
        uVar6 = __list_add_valid(plVar5,puVar8,puVar10 + 0xe);
        if ((uVar6 & 1) != 0) {
          puVar10[0xf] = plVar5;
          *plVar5 = (long)(puVar10 + 0xe);
          plVar5[1] = (long)puVar8;
          *puVar8 = plVar5;
        }
        _raw_spin_unlock_irqrestore(puVar10 + 0x10,uVar4);
        queue_work_on(0x20,_system_wq,puVar10 + 0x17);
      }
    }
    else if (puVar8 != (undefined8 *)0x0) {
      _printk(&DAT_0010236c,"mhi_sat_rpmsg_cb",*puVar8,*(undefined4 *)(puVar10 + 0x23));
      ipc_log_string(puVar8[0xb],"%s[E][%s][%x] Message for inactive controller!\n",&DAT_001022b2,
                     "mhi_sat_rpmsg_cb",*(undefined4 *)(puVar10 + 0x23));
    }
  }
  return 0;
}



//------------------------------------------------------------
// mhi_sat_dev_probe @ 00100b0c size=868
// signature: undefined mhi_sat_dev_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 mhi_sat_dev_probe(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  
  lVar2 = mhi_sat_driver_1;
  lVar12 = *(long *)(param_2 + 0x20);
  iVar3 = mhi_controller_get_numeric_id(*(undefined8 *)(param_1 + 0x10));
  if (iVar3 == 0) {
    _printk(&DAT_00102327);
    return 0xffffffea;
  }
  lVar7 = lVar2 + lVar12 * 0x60;
  lVar13 = lVar2 + lVar12 * 0x60;
  lVar10 = lVar7 + 0x50;
  uVar4 = _raw_spin_lock_irqsave(lVar10);
  plVar6 = (long *)(lVar7 + 0x10);
  plVar8 = plVar6;
  do {
    plVar8 = (long *)*plVar8;
    if (plVar8 == plVar6) {
      _raw_spin_unlock_irqrestore(lVar10,uVar4);
      goto LAB_00100ba4;
    }
  } while ((int)plVar8[0x23] != iVar3);
  _raw_spin_unlock_irqrestore(lVar10,uVar4);
  if (plVar8 == (long *)0x0) {
LAB_00100ba4:
    plVar8 = (long *)kmalloc_trace(_kfree,0xdc0,0x198);
    if (plVar8 == (long *)0x0) {
      return 0xfffffff4;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x3c8);
    *(int *)(plVar8 + 0x23) = iVar3;
    lVar7 = *(long *)(param_1 + 0x10);
    *(undefined4 *)((long)plVar8 + 300) = 0xffffffff;
    *(undefined4 *)((long)plVar8 + 0x11c) = uVar1;
    *(undefined2 *)((long)plVar8 + 0x13c) = 0xffff;
    plVar8[2] = lVar7;
    plVar8[3] = lVar13;
    *(undefined4 *)(plVar8 + 0x29) = 0;
    __init_swait_queue_head(plVar8 + 0x2a,"&x->wait",&init_completion___key);
    __mutex_init(plVar8 + 8,"&sat_cntrl->list_mutex",&mhi_sat_dev_probe___key);
    __mutex_init(plVar8 + 0x2d,"&sat_cntrl->cmd_wait_mutex",&mhi_sat_dev_probe___key_24);
    *(undefined4 *)(plVar8 + 0x10) = 0;
    *(undefined4 *)(plVar8 + 0x27) = 0;
    plVar8[0x11] = 0xfffffffe0;
    plVar8[0x12] = (long)(plVar8 + 0x12);
    plVar8[0x13] = (long)(plVar8 + 0x12);
    plVar8[0x14] = (long)mhi_sat_connect_worker;
    plVar8[0x17] = 0xfffffffe0;
    plVar8[0x18] = (long)(plVar8 + 0x18);
    plVar8[0x19] = (long)(plVar8 + 0x18);
    plVar8[0x1a] = (long)mhi_sat_process_worker;
    plVar8[0x1d] = 0xfffffffe0;
    plVar8[0x1e] = (long)(plVar8 + 0x1e);
    plVar8[0x1f] = (long)(plVar8 + 0x1e);
    lVar7 = lVar2 + lVar12 * 0x60 + 0x20;
    plVar8[0x20] = (long)mhi_sat_error_worker;
    plVar8[4] = (long)(plVar8 + 4);
    plVar8[5] = (long)(plVar8 + 4);
    plVar8[6] = (long)(plVar8 + 6);
    plVar8[7] = (long)(plVar8 + 6);
    plVar8[0xe] = (long)(plVar8 + 0xe);
    plVar8[0xf] = (long)(plVar8 + 0xe);
    mutex_lock(lVar7);
    _raw_spin_lock_irq(lVar10);
    lVar11 = *plVar6;
    uVar5 = __list_add_valid(plVar8,plVar6,lVar11);
    if ((uVar5 & 1) != 0) {
      *(long **)(lVar11 + 8) = plVar8;
      *plVar8 = lVar11;
      plVar8[1] = (long)plVar6;
      *plVar6 = (long)plVar8;
    }
    _raw_spin_unlock_irq(lVar10);
    mutex_unlock(lVar7);
    if (lVar13 != 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + lVar12 * 0x60 + 0x58),
                     "%s[I][%s][%x] Controller allocated for 0x%x\n",&DAT_001022b2,
                     "mhi_sat_dev_probe",(int)plVar8[0x23],iVar3);
    }
  }
  *(undefined4 *)((long)plVar8 + 300) = 4;
  iVar3 = *(int *)((long)plVar8 + 0x11c);
  if (*(int *)(param_1 + 0x3c8) <= *(int *)((long)plVar8 + 0x11c)) {
    iVar3 = *(int *)(param_1 + 0x3c8);
  }
  *(int *)((long)plVar8 + 0x11c) = iVar3;
  if (iVar3 <= *(int *)(param_1 + 0x3c8)) {
    iVar3 = *(int *)(param_1 + 0x3c8);
  }
  *(int *)(plVar8 + 0x24) = iVar3;
  plVar6 = (long *)devm_kmalloc(param_1 + 0x28,0x28,0xdc0);
  if (plVar6 == (long *)0x0) {
    return 0xfffffff4;
  }
  plVar6[2] = param_1;
  plVar6[3] = (long)plVar8;
  mutex_lock(plVar8 + 8);
  plVar9 = plVar8 + 4;
  lVar10 = *plVar9;
  uVar5 = __list_add_valid(plVar6,plVar9,lVar10);
  if ((uVar5 & 1) != 0) {
    *(long **)(lVar10 + 8) = plVar6;
    *plVar6 = lVar10;
    plVar6[1] = (long)plVar9;
    *plVar9 = (long)plVar6;
  }
  mutex_unlock(plVar8 + 8);
  *(long **)(param_1 + 0xc0) = plVar6;
  iVar3 = (int)plVar8[0x25] + 1;
  *(int *)(plVar8 + 0x25) = iVar3;
  if (iVar3 == *(int *)((long)plVar8 + 300)) {
    *(int *)((long)plVar8 + 0x124) = ((int)plVar8[0x24] - *(int *)((long)plVar8 + 0x11c)) + 1;
    if (lVar13 != 0) {
      ipc_log_string(*(undefined8 *)(lVar2 + lVar12 * 0x60 + 0x58),
                     "%s[I][%s][%x] All satellite channels probed!\n",&DAT_001022b2,
                     "mhi_sat_dev_probe",(int)plVar8[0x23]);
    }
    queue_work_on(0x20,_system_wq,plVar8 + 0x11);
  }
  return 0;
}



//------------------------------------------------------------
// mhi_sat_dev_remove @ 00100e74 size=1148
// signature: undefined mhi_sat_dev_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_dev_remove(long param_1)

{
  short sVar1;
  long *plVar2;
  long *plVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  undefined4 *puVar8;
  undefined8 uVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  long *plVar13;
  long lVar14;
  undefined8 *puVar15;
  
  plVar12 = *(long **)(param_1 + 0xc0);
  plVar11 = (long *)plVar12[3];
  plVar2 = plVar11 + 8;
  lVar14 = plVar11[3];
  mutex_lock(plVar2);
  uVar7 = __list_del_entry_valid(plVar12);
  if ((uVar7 & 1) != 0) {
    lVar10 = *plVar12;
    plVar13 = (long *)plVar12[1];
    *(long **)(lVar10 + 8) = plVar13;
    *plVar13 = lVar10;
  }
  *plVar12 = -0x2152ffffffffff00;
  plVar12[1] = -0x2152fffffffffede;
  mutex_unlock(plVar2);
  *(int *)(plVar11 + 0x25) = (int)plVar11[0x25] + -1;
  mutex_lock(lVar14 + 0x20);
  cancel_work_sync(plVar11 + 0x1d);
  plVar12 = plVar11 + 0x27;
  _raw_spin_lock_irq(plVar12);
  if ((*(uint *)((long)plVar11 + 0x134) | 2) == 3) {
    *(undefined4 *)((long)plVar11 + 0x134) = 4;
    _raw_spin_unlock_irq(plVar12);
    puVar15 = (undefined8 *)plVar11[3];
    flush_work(plVar11 + 0x11);
    flush_work(plVar11 + 0x17);
    puVar8 = (undefined4 *)kmalloc_trace(___mhi_driver_register,0xcc0,0x28);
    if (puVar8 == (undefined4 *)0x0) {
      if ((plVar11 != (long *)0x0) && (puVar15 != (undefined8 *)0x0)) {
        _printk(&DAT_001023a0,"mhi_sat_send_sys_err",*puVar15,(int)plVar11[0x23]);
        ipc_log_string(puVar15[0xb],"%s[E][%s][%x] Unable to malloc for SYS_ERR message!\n",
                       &DAT_001022b2,"mhi_sat_send_sys_err",(int)plVar11[0x23]);
      }
    }
    else {
      *(undefined8 *)(puVar8 + 6) = 0;
      *(undefined8 *)(puVar8 + 8) = 0xff000000000000;
      mutex_lock(plVar11 + 0x2d);
      lVar10 = plVar11[3];
      sVar1 = 0;
      if ((short)plVar11[0x26] != -2) {
        sVar1 = (short)plVar11[0x26] + 1;
      }
      *(short *)(plVar11 + 0x26) = sVar1;
      *puVar8 = 1;
      *(undefined2 *)(puVar8 + 1) = 0xc;
      *(short *)((long)puVar8 + 6) = sVar1;
      puVar8[2] = 0x10ffff;
      puVar8[3] = (int)plVar11[0x23];
      *(short *)((long)plVar11 + 0x13c) = sVar1;
      iVar6 = rpmsg_send(*(undefined8 *)(*(long *)(lVar10 + 8) + 0x3c8),puVar8,0x28);
      kfree(puVar8);
      if (iVar6 == 0) {
        if (plVar11 != (long *)0x0 && puVar15 != (undefined8 *)0x0) {
          ipc_log_string(puVar15[0xb],"%s[I][%s][%x] SYS_ERR command sent\n",&DAT_001022b2,
                         "mhi_sat_send_sys_err",(int)plVar11[0x23]);
        }
        puVar15 = (undefined8 *)plVar11[3];
        bVar4 = plVar11 != (long *)0x0;
        *(undefined4 *)(plVar11 + 0x29) = 0;
        bVar5 = puVar15 != (undefined8 *)0x0;
        if (bVar4 && bVar5) {
          ipc_log_string(puVar15[0xb],"%s[I][%s][%x] Wait for command completion\n",&DAT_001022b2,
                         "mhi_sat_wait_cmd_completion",(int)plVar11[0x23]);
        }
        uVar9 = __msecs_to_jiffies(*(undefined4 *)(plVar11[2] + 0x180));
        iVar6 = wait_for_completion_timeout(plVar11 + 0x29,uVar9);
        if ((iVar6 == 0) || ((int)plVar11[0x28] != 1)) {
          if (bVar4 && bVar5) {
            _printk(&DAT_001022e4,"mhi_sat_wait_cmd_completion",*puVar15,(int)plVar11[0x23],
                    *(undefined2 *)((long)plVar11 + 0x13c),iVar6,(int)plVar11[0x28]);
            ipc_log_string(puVar15[0xb],
                           "%s[E][%s][%x] Command completion failure:seq:%u:ret:%d:ccs:%d\n",
                           &DAT_001022b2,"mhi_sat_wait_cmd_completion",(int)plVar11[0x23],
                           *(undefined2 *)((long)plVar11 + 0x13c),iVar6,(int)plVar11[0x28]);
          }
        }
        else if (bVar4 && bVar5) {
          ipc_log_string(puVar15[0xb],"%s[I][%s][%x] Command completion successful for seq:%u\n",
                         &DAT_001022b2,"mhi_sat_wait_cmd_completion",(int)plVar11[0x23],
                         *(undefined2 *)((long)plVar11 + 0x13c));
        }
      }
      else if (plVar11 != (long *)0x0 && puVar15 != (undefined8 *)0x0) {
        _printk(&DAT_0010240e,"mhi_sat_send_sys_err",*puVar15,(int)plVar11[0x23]);
        ipc_log_string(puVar15[0xb],"%s[E][%s][%x] Failed to notify SYS_ERR cmd\n",&DAT_001022b2,
                       "mhi_sat_send_sys_err",(int)plVar11[0x23]);
      }
      mutex_unlock(plVar11 + 0x2d);
    }
  }
  else {
    *(undefined4 *)((long)plVar11 + 0x134) = 4;
    _raw_spin_unlock_irq(plVar12);
  }
  if ((int)plVar11[0x25] == 0) {
    cancel_work_sync(plVar11 + 0x11);
    cancel_work_sync(plVar11 + 0x17);
    mutex_lock(plVar2);
    plVar12 = (long *)plVar11[6];
    while (plVar12 != plVar11 + 6) {
      plVar13 = (long *)*plVar12;
      if ((char)plVar12[7] == '\0') {
        dma_unmap_page_attrs
                  (*(undefined8 *)(*(long *)(plVar11[2] + 8) + 0x88),plVar12[4],plVar12[6],0,0x20);
      }
      else {
        dma_unmap_resource();
      }
      uVar7 = __list_del_entry_valid(plVar12);
      if ((uVar7 & 1) != 0) {
        lVar10 = *plVar12;
        plVar3 = (long *)plVar12[1];
        *(long **)(lVar10 + 8) = plVar3;
        *plVar3 = lVar10;
      }
      *plVar12 = -0x2152ffffffffff00;
      plVar12[1] = -0x2152fffffffffede;
      kfree(plVar12);
      plVar12 = plVar13;
    }
    mutex_unlock(plVar2);
    _raw_spin_lock_irq(lVar14 + 0x50);
    uVar7 = __list_del_entry_valid(plVar11);
    if ((uVar7 & 1) != 0) {
      lVar10 = *plVar11;
      plVar2 = (long *)plVar11[1];
      *(long **)(lVar10 + 8) = plVar2;
      *plVar2 = lVar10;
    }
    *plVar11 = -0x2152ffffffffff00;
    plVar11[1] = -0x2152fffffffffede;
    _raw_spin_unlock_irq(lVar14 + 0x50);
    if ((lVar14 != 0) && (plVar11 != (long *)0x0)) {
      ipc_log_string(*(undefined8 *)(lVar14 + 0x58),
                     "%s[I][%s][%x] Satellite controller node removed\n",&DAT_001022b2,
                     "mhi_sat_dev_remove",(int)plVar11[0x23]);
    }
    kfree(plVar11);
  }
  mutex_unlock(lVar14 + 0x20);
  return;
}



//------------------------------------------------------------
// mhi_sat_dev_status_cb @ 001012f4 size=176
// signature: undefined mhi_sat_dev_status_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_dev_status_cb(long param_1,int param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_2 == 7) {
    lVar2 = *(long *)(*(long *)(param_1 + 0xc0) + 0x18);
    if (*(long *)(lVar2 + 0x18) != 0 && lVar2 != 0) {
      ipc_log_string(*(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x58),
                     "%s[I][%s][%x] Device fatal error detected\n",&DAT_001022b2,
                     "mhi_sat_dev_status_cb",*(undefined4 *)(lVar2 + 0x118));
    }
    uVar1 = _raw_spin_lock_irqsave(lVar2 + 0x138);
    if (*(int *)(lVar2 + 0x134) == 1) {
      queue_work_on(0x20,_system_wq,lVar2 + 0xe8);
      *(undefined4 *)(lVar2 + 0x134) = 3;
    }
    _raw_spin_unlock_irqrestore(lVar2 + 0x138,uVar1);
  }
  return;
}



//------------------------------------------------------------
// mhi_sat_connect_worker @ 001013a8 size=664
// signature: undefined mhi_sat_connect_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_connect_worker(long param_1)

{
  long lVar1;
  short sVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort uVar5;
  short sVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  undefined4 *puVar10;
  long lVar11;
  undefined8 *puVar12;
  undefined8 local_60;
  long local_58;
  
  lVar11 = sp_el0;
  lVar1 = param_1 + 0xb0;
  local_58 = *(long *)(lVar11 + 0x638);
  puVar12 = *(undefined8 **)(param_1 + -0x70);
  local_60 = 0;
  _raw_spin_lock_irq(lVar1);
  if (((puVar12[1] != 0) && (*(int *)(param_1 + 0xa4) == *(int *)(param_1 + 0xa0))) &&
     (uVar4 = *(uint *)(param_1 + 0xac), (uVar4 | 2) == 2)) {
    *(undefined4 *)(param_1 + 0xac) = 1;
    _raw_spin_unlock_irq(lVar1);
    bVar7 = param_1 != 0x88;
    bVar8 = puVar12 != (undefined8 *)0x0;
    if (param_1 == 0x88 || puVar12 == (undefined8 *)0x0) {
      iVar9 = mhi_controller_get_base(*(undefined8 *)(param_1 + -0x78),&local_60);
      if (iVar9 == 0) goto LAB_001014bc;
    }
    else {
      ipc_log_string(puVar12[0xb],"%s[I][%s][%x] Entered\n",&DAT_001022b2,"mhi_sat_connect_worker",
                     *(undefined4 *)(param_1 + 0x90));
      iVar9 = mhi_controller_get_base(*(undefined8 *)(param_1 + -0x78),&local_60);
      if (iVar9 == 0) {
LAB_001014bc:
        puVar10 = (undefined4 *)kmalloc_trace(_unregister_rpmsg_driver,0xa20,0x48);
        if (puVar10 != (undefined4 *)0x0) {
          uVar3 = *(undefined4 *)(param_1 + 0x90);
          iVar9 = *(int *)(param_1 + 0x94);
          uVar5 = *(ushort *)(param_1 + 0x9c);
          sVar6 = *(short *)(param_1 + 0xa8);
          *(undefined8 *)(puVar10 + 6) = local_60;
          puVar10[8] = (uint)uVar5 | iVar9 << 0x10;
          puVar10[9] = 0x6e0000;
          sVar2 = 0;
          if (sVar6 != -2) {
            sVar2 = sVar6 + 1;
          }
          *(undefined8 *)(puVar10 + 10) = 0;
          *(undefined8 *)(puVar10 + 0xc) = 0x20000002000000;
          *(undefined8 *)(puVar10 + 0xe) = 0;
          *(undefined8 *)(puVar10 + 0x10) = 0x40000002000000;
          *puVar10 = 1;
          *(short *)(param_1 + 0xa8) = sVar2;
          *(undefined2 *)(puVar10 + 1) = 0xe;
          lVar11 = *(long *)(param_1 + -0x70);
          *(short *)((long)puVar10 + 6) = sVar2;
          puVar10[2] = 0x30ffff;
          puVar10[3] = uVar3;
          iVar9 = rpmsg_send(*(undefined8 *)(*(long *)(lVar11 + 8) + 0x3c8),puVar10,0x48);
          kfree(puVar10);
          if (iVar9 == 0) {
            if (bVar7 && bVar8) {
              ipc_log_string(puVar12[0xb],"%s[I][%s][%x] Device 0x%x sent hello packet\n",
                             &DAT_001022b2,"mhi_sat_connect_worker",*(undefined4 *)(param_1 + 0x90),
                             *(undefined4 *)(param_1 + 0x90));
            }
            goto LAB_0010158c;
          }
          if (bVar7 && bVar8) {
            _printk(&DAT_001020fb,"mhi_sat_connect_worker",*puVar12,*(undefined4 *)(param_1 + 0x90),
                    iVar9);
            ipc_log_string(puVar12[0xb],"%s[E][%s][%x] Failed to send hello packet:%d\n",
                           &DAT_001022b2,"mhi_sat_connect_worker",*(undefined4 *)(param_1 + 0x90),
                           iVar9);
          }
        }
      }
      else {
        _printk(&DAT_0010278b,"mhi_sat_connect_worker",*puVar12,*(undefined4 *)(param_1 + 0x90));
        ipc_log_string(puVar12[0xb],"%s[E][%s][%x] Could not get controller base address\n",
                       &DAT_001022b2,"mhi_sat_connect_worker",*(undefined4 *)(param_1 + 0x90));
      }
    }
    _raw_spin_lock_irq(lVar1);
    if (*(int *)(param_1 + 0xac) == 1) {
      *(uint *)(param_1 + 0xac) = uVar4;
    }
  }
  _raw_spin_unlock_irq(lVar1);
LAB_0010158c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_sat_process_worker @ 00101644 size=2064
// signature: undefined mhi_sat_process_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_process_worker(long param_1)

{
  bool bVar1;
  short sVar2;
  long ****pppplVar3;
  uint uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  ushort uVar7;
  uint uVar8;
  code *pcVar9;
  int iVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  long ***ppplVar14;
  char *pcVar15;
  long ****pppplVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  long ****pppplVar20;
  undefined8 *puVar21;
  long *****ppppplVar22;
  long lVar23;
  long *****ppppplVar24;
  long *plVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  long *plVar28;
  long *plVar29;
  uint uVar30;
  long *****local_d0;
  long *****local_c8;
  undefined8 *local_c0;
  undefined *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined4 uStack_94;
  undefined4 local_90;
  undefined4 uStack_8c;
  undefined4 local_88;
  undefined4 uStack_84;
  undefined8 local_80;
  undefined4 local_78;
  long local_70;
  
  lVar23 = sp_el0;
  local_70 = *(long *)(lVar23 + 0x638);
  lVar23 = *(long *)(param_1 + -0xa0);
  local_d0 = (long *****)&local_d0;
  local_c8 = local_d0;
  if (param_1 != 0xb8 && lVar23 != 0) {
    ipc_log_string(*(undefined8 *)(lVar23 + 0x58),"%s[I][%s][%x] Entered\n",&DAT_001022b2,
                   "mhi_sat_process_worker",*(undefined4 *)(param_1 + 0x60));
  }
  _raw_spin_lock_irq(param_1 + -0x38);
  pppplVar16 = (long ****)(param_1 + -0x48);
  pppplVar20 = (long ****)*pppplVar16;
  if (pppplVar20 != pppplVar16) {
    ppppplVar22 = *(long ******)(param_1 + -0x40);
    pppplVar20[1] = (long ***)local_c8;
    *local_c8 = pppplVar20;
    *ppppplVar22 = (long ****)&local_d0;
    *(long *)(param_1 + -0x48) = param_1 + -0x48;
    *(long *****)(param_1 + -0x40) = pppplVar16;
    local_c8 = ppppplVar22;
  }
  _raw_spin_unlock_irq(param_1 + -0x38);
  if ((long ******)local_d0 != &local_d0) {
    lVar17 = param_1 + -0x78;
    plVar29 = (long *)(param_1 + -0x98);
    ppppplVar22 = local_d0;
    do {
      ppppplVar24 = (long *****)*ppppplVar22;
      pppplVar16 = ppppplVar22[3];
      uVar11 = __list_del_entry_valid(ppppplVar22);
      if ((uVar11 & 1) != 0) {
        pppplVar20 = *ppppplVar22;
        pppplVar3 = ppppplVar22[1];
        pppplVar20[1] = (long ***)pppplVar3;
        *pppplVar3 = (long ***)pppplVar20;
      }
      *ppppplVar22 = (long ****)0xdead000000000100;
      ppppplVar22[1] = (long ****)0xdead000000000122;
      if (*(int *)(param_1 + 0x7c) == 1) {
        uVar7 = *(ushort *)((long)pppplVar16 + 10);
        if (0xf < uVar7) {
          uVar30 = 0;
          puVar21 = *(undefined8 **)(param_1 + -0xa0);
          pppplVar20 = pppplVar16 + 3;
          bVar1 = param_1 != 0xb8 && puVar21 != (undefined8 *)0x0;
          do {
            uVar4 = *(uint *)((long)pppplVar20 + 0xc);
            uVar8 = uVar4 >> 0x10 & 0xff;
            if (uVar8 < 100) {
              if (uVar8 == 0x10) {
                uVar4 = uVar4 >> 0x18;
                mutex_lock(lVar17);
                plVar25 = plVar29;
                do {
                  plVar25 = (long *)*plVar25;
                  if (plVar25 == plVar29) {
                    mutex_unlock(lVar17);
                    goto LAB_00101d84;
                  }
                } while (*(uint *)(plVar25[2] + 0x3c4) != uVar4);
                mutex_unlock(lVar17);
                if (plVar25 == (long *)0x0) {
LAB_00101d84:
                  if (bVar1) {
                    ipc_log_string(puVar21[0xb],
                                   "%s[I][%s][%x] Failed to find the satellite device with id : %d\n"
                                   ,&DAT_001022b2,"mhi_sat_process_cmds",
                                   *(undefined4 *)(param_1 + 0x60),uVar4);
                  }
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101748);
                  (*pcVar9)();
                }
                if ((char)plVar25[4] == '\0') {
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101c70);
                  (*pcVar9)();
                }
                mhi_unprepare_from_transfer(plVar25[2]);
                *(undefined1 *)(plVar25 + 4) = 0;
                if (bVar1) {
                  ipc_log_string(puVar21[0xb],"%s[I][%s][%x] RESET CHANNEL %d CMD successful\n",
                                 &DAT_001022b2,"mhi_sat_process_cmds",
                                 *(undefined4 *)(param_1 + 0x60),uVar4);
                }
                *pppplVar20 = (long ***)0x0;
                pppplVar20[1] = (long ***)0x21000001000000;
              }
              else {
                if (uVar8 == 0x12) {
                  uVar4 = uVar4 >> 0x18;
                  mutex_lock(lVar17);
                  plVar25 = plVar29;
                  do {
                    plVar25 = (long *)*plVar25;
                    if (plVar25 == plVar29) {
                      mutex_unlock(lVar17);
                      goto LAB_00101d40;
                    }
                  } while (*(uint *)(plVar25[2] + 0x3c4) != uVar4);
                  mutex_unlock(lVar17);
                  if (plVar25 == (long *)0x0) {
LAB_00101d40:
                    if (bVar1) {
                      ipc_log_string(puVar21[0xb],
                                     "%s[I][%s][%x] Failed to find the satellite device with id : %d\n"
                                     ,&DAT_001022b2,"mhi_sat_process_cmds",
                                     *(undefined4 *)(param_1 + 0x60),uVar4);
                    }
                    /* WARNING: Does not return */
                    pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101d78);
                    (*pcVar9)();
                  }
                  if (*(char *)(plVar25 + 4) != '\0') {
                    /* WARNING: Does not return */
                    pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101c68);
                    (*pcVar9)();
                  }
                  iVar10 = mhi_prepare_for_transfer(plVar25[2]);
                  if (iVar10 == 0) {
                    uVar27 = 0x1000000;
                    *(undefined1 *)(plVar25 + 4) = 1;
                  }
                  else {
                    uVar27 = 0;
                  }
                  if (bVar1) {
                    pcVar15 = "successful";
                    if (iVar10 != 0) {
                      pcVar15 = "failure";
                    }
                    ipc_log_string(puVar21[0xb],"%s[I][%s][%x] START CHANNEL %d CMD %s\n",
                                   &DAT_001022b2,"mhi_sat_process_cmds",
                                   *(undefined4 *)(param_1 + 0x60),uVar4,pcVar15);
                  }
                  *pppplVar20 = (long ***)0x0;
                  goto LAB_00101d14;
                }
LAB_00101b30:
                if (bVar1) {
                  _printk(&DAT_0010262a,"mhi_sat_process_cmds",*puVar21,
                          *(undefined4 *)(param_1 + 0x60));
                  ipc_log_string(puVar21[0xb],"%s[E][%s][%x] Unhandled MHI satellite command!",
                                 &DAT_001022b2,"mhi_sat_process_cmds",
                                 *(undefined4 *)(param_1 + 0x60));
                }
              }
            }
            else {
              if (uVar8 == 100) {
                ppplVar14 = *pppplVar20;
                uVar8 = uVar4 >> 0x18;
                uVar27 = *(undefined4 *)(pppplVar20 + 1);
                local_78 = 0;
                local_88 = 0;
                uStack_84 = 0;
                local_80 = 0;
                local_98 = 0;
                uStack_94 = 0;
                local_90 = 0;
                uStack_8c = 0;
                local_a8 = 0;
                local_a0 = 0;
                local_b8 = (undefined *)0x0;
                local_b0 = 0;
                local_c0 = (undefined8 *)0x0;
                mutex_lock(lVar17);
                plVar25 = plVar29;
                do {
                  plVar25 = (long *)*plVar25;
                  if (plVar25 == plVar29) {
                    mutex_unlock(lVar17);
                    goto LAB_00101dc4;
                  }
                  lVar18 = 0x3c4;
                  if ((int)((ulong)uVar4 & 1) != 0) {
                    lVar18 = 0x3c8;
                  }
                } while (*(uint *)(plVar25[2] + lVar18) != uVar8);
                mutex_unlock(lVar17);
                if (plVar25 == (long *)0x0) {
LAB_00101dc4:
                  if (bVar1) {
                    ipc_log_string(puVar21[0xb],
                                   "%s[I][%s][%x] Failed to find the satellite device with id : %d\n"
                                   ,&DAT_001022b2,"mhi_sat_process_cmds",
                                   *(undefined4 *)(param_1 + 0x60),uVar8);
                  }
                    /* WARNING: Does not return */
                  pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101dfc);
                  (*pcVar9)();
                }
                local_98 = 0;
                uStack_84 = 0;
                uStack_94 = SUB84(ppplVar14,0);
                local_90 = (undefined4)((ulong)ppplVar14 >> 0x20);
                local_b0 = 0;
                local_a8 = 0x2c;
                local_78 = 0;
                local_80 = 0;
                local_b8 = (&sat_ctxt_str)[(ulong)uVar4 & 1];
                local_88 = 0;
                local_a0 = 0xa00000000;
                local_c0 = &local_a0;
                uStack_8c = uVar27;
                iVar10 = mhi_device_configure(plVar25[2],0,&local_c0,1);
                if (bVar1) {
                  pcVar15 = "successful";
                  if (iVar10 != 0) {
                    pcVar15 = "failed";
                  }
                  ipc_log_string(puVar21[0xb],"%s[I][%s][%x] CTXT UPDATE CMD %s:%d %s\n",
                                 &DAT_001022b2,"mhi_sat_process_cmds",
                                 *(undefined4 *)(param_1 + 0x60),local_b8,uVar8,pcVar15);
                }
                *pppplVar20 = (long ***)0x0;
                *(uint *)(pppplVar20 + 1) = (uint)(iVar10 == 0) << 0x18;
                *(undefined4 *)((long)pppplVar20 + 0xc) = 0x210000;
                goto LAB_00101d20;
              }
              if (uVar8 != 0x65) goto LAB_00101b30;
              plVar28 = *(long **)(*(long *)(*(long *)(param_1 + -0xa8) + 8) + 0x88);
              plVar25 = (long *)kmalloc_trace(___mhi_driver_register,0xa20,0x40);
              if (plVar25 == (long *)0x0) {
LAB_00101cbc:
                uVar26 = 0;
                uVar27 = 0;
                ppplVar14 = (long ***)0xffffffffffffffff;
                pcVar15 = "failed";
              }
              else {
                ppplVar14 = *pppplVar20;
                plVar25[5] = (long)ppplVar14;
                uVar11 = (ulong)*(uint *)(pppplVar20 + 1);
                plVar25[6] = uVar11;
                uVar4 = *(uint *)((long)pppplVar20 + 0xc);
                *(byte *)(plVar25 + 7) = (byte)uVar4 & 1;
                if ((uVar4 & 1) == 0) {
                  uVar19 = (long)ppplVar14 - _memstart_addr;
                  uVar12 = is_vmalloc_addr(uVar19 | 0xffffff8000000000);
                  if (((uVar12 & 1) != 0) && ((dma_map_single_attrs___already_done & 1) == 0)) {
                    dma_map_single_attrs___already_done = 1;
                    uVar13 = dev_driver_string(plVar28);
                    lVar23 = plVar28[0xe];
                    if (lVar23 == 0) {
                      lVar23 = *plVar28;
                    }
                    __warn_printk("%s %s: rejecting DMA map of vmalloc memory\n",uVar13,lVar23);
                    /* WARNING: Does not return */
                    pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101cb0);
                    (*pcVar9)();
                  }
                  if ((uVar12 & 1) == 0) {
                    ppplVar14 = (long ***)
                                dma_map_page_attrs(plVar28,uVar19 >> 6 & 0x1ffffffc0 |
                                                           0xfffffffe00000000,uVar19 & 0xfff,uVar11,
                                                   0,0x20);
                    goto LAB_00101b98;
                  }
LAB_00101cb4:
                  kfree(plVar25);
                  goto LAB_00101cbc;
                }
                ppplVar14 = (long ***)dma_map_resource(plVar28,ppplVar14,uVar11,0,0);
LAB_00101b98:
                if (ppplVar14 == (long ***)0xffffffffffffffff) goto LAB_00101cb4;
                plVar25[4] = (long)ppplVar14;
                mutex_lock(lVar17);
                plVar28 = *(long **)(param_1 + -0x80);
                uVar11 = __list_add_valid(plVar25,plVar28,param_1 + -0x88);
                if ((uVar11 & 1) != 0) {
                  *(long **)(param_1 + -0x80) = plVar25;
                  *plVar25 = param_1 + -0x88;
                  plVar25[1] = (long)plVar28;
                  *plVar28 = (long)plVar25;
                }
                mutex_unlock(lVar17);
                uVar26 = 0x1000000;
                uVar27 = 0x1000000;
                pcVar15 = "successful";
              }
              if (bVar1) {
                ipc_log_string(puVar21[0xb],"%s[I][%s][%x] IOMMU MAP 0x%llx len:%d CMD %s:%llx\n",
                               &DAT_001022b2,"mhi_sat_process_cmds",*(undefined4 *)(param_1 + 0x60),
                               *pppplVar20,*(undefined4 *)(pppplVar20 + 1),pcVar15,ppplVar14);
                uVar27 = uVar26;
              }
              *pppplVar20 = ppplVar14;
LAB_00101d14:
              *(undefined4 *)(pppplVar20 + 1) = uVar27;
              *(undefined4 *)((long)pppplVar20 + 0xc) = 0x210000;
            }
LAB_00101d20:
            uVar30 = uVar30 + 1;
            pppplVar20 = pppplVar20 + 2;
          } while (uVar30 != uVar7 >> 4);
        }
        pppplVar20 = ppppplVar22[3];
        uVar5 = *(undefined2 *)((long)pppplVar16 + 6);
        sVar2 = 0;
        if (*(short *)(param_1 + 0x78) != -2) {
          sVar2 = *(short *)(param_1 + 0x78) + 1;
        }
        uVar7 = *(ushort *)((long)pppplVar16 + 10);
        *(short *)(param_1 + 0x78) = sVar2;
        lVar18 = *(long *)(param_1 + -0xa0);
        *(undefined4 *)pppplVar20 = 1;
        uVar7 = uVar7 & 0xfff0;
        *(undefined2 *)((long)pppplVar20 + 4) = 0xe;
        uVar6 = *(undefined2 *)(param_1 + 0x78);
        *(undefined2 *)(pppplVar20 + 1) = uVar5;
        *(ushort *)((long)pppplVar20 + 10) = uVar7;
        *(undefined2 *)((long)pppplVar20 + 6) = uVar6;
        *(undefined4 *)((long)pppplVar20 + 0xc) = *(undefined4 *)(param_1 + 0x60);
        rpmsg_send(*(undefined8 *)(*(long *)(lVar18 + 8) + 0x3c8),pppplVar20,uVar7 + 0x18);
      }
      kfree(ppppplVar22);
      ppppplVar22 = ppppplVar24;
    } while ((long ******)ppppplVar24 != &local_d0);
  }
  if (param_1 != 0xb8 && lVar23 != 0) {
    ipc_log_string(*(undefined8 *)(lVar23 + 0x58),"%s[I][%s][%x] Exited\n",&DAT_001022b2,
                   "mhi_sat_process_worker",*(undefined4 *)(param_1 + 0x60));
  }
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// mhi_sat_error_worker @ 00101e80 size=396
// signature: undefined mhi_sat_error_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mhi_sat_error_worker(long param_1)

{
  char *pcVar1;
  short sVar2;
  undefined4 uVar3;
  short sVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  undefined4 *puVar8;
  long lVar9;
  undefined8 *puVar10;
  
  puVar10 = *(undefined8 **)(param_1 + -0xd0);
  bVar5 = param_1 != 0xe8;
  bVar6 = puVar10 != (undefined8 *)0x0;
  if (bVar5 && bVar6) {
    ipc_log_string(puVar10[0xb],"%s[I][%s][%x] Entered\n",&DAT_001022b2,"mhi_sat_error_worker",
                   *(undefined4 *)(param_1 + 0x30));
  }
  flush_work(param_1 + -0x60);
  flush_work(param_1 + -0x30);
  puVar8 = (undefined4 *)kmalloc_trace(___mhi_driver_register,0xcc0,0x28);
  if (puVar8 == (undefined4 *)0x0) {
    if (bVar5 && bVar6) {
      _printk(&DAT_001023a0,"mhi_sat_error_worker",*puVar10,*(undefined4 *)(param_1 + 0x30));
      ipc_log_string(puVar10[0xb],"%s[E][%s][%x] Unable to malloc for SYS_ERR message!\n",
                     &DAT_001022b2,"mhi_sat_error_worker",*(undefined4 *)(param_1 + 0x30));
    }
  }
  else {
    sVar4 = *(short *)(param_1 + 0x48);
    *(undefined8 *)(puVar8 + 6) = 0;
    *(undefined8 *)(puVar8 + 8) = 0x200000ff000000;
    sVar2 = 0;
    if (sVar4 != -2) {
      sVar2 = sVar4 + 1;
    }
    *puVar8 = 1;
    uVar3 = *(undefined4 *)(param_1 + 0x30);
    *(undefined2 *)(puVar8 + 1) = 0xe;
    lVar9 = *(long *)(param_1 + -0xd0);
    *(short *)(param_1 + 0x48) = sVar2;
    *(short *)((long)puVar8 + 6) = sVar2;
    puVar8[2] = 0x10ffff;
    puVar8[3] = uVar3;
    iVar7 = rpmsg_send(*(undefined8 *)(*(long *)(lVar9 + 8) + 0x3c8),puVar8,0x28);
    kfree(puVar8);
    if (bVar5 && bVar6) {
      pcVar1 = "success";
      if (iVar7 != 0) {
        pcVar1 = "failure";
      }
      ipc_log_string(puVar10[0xb],"%s[I][%s][%x] SYS_ERROR state change event send %s!\n",
                     &DAT_001022b2,"mhi_sat_error_worker",*(undefined4 *)(param_1 + 0x30),pcVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00102010 size=128
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  bool bVar1;
  undefined8 *puVar2;
  uint uVar3;
  
  unregister_rpmsg_driver(&mhi_sat_rpmsg_driver);
  if (mhi_sat_driver_2 == '\x01') {
    puVar2 = (undefined8 *)(mhi_sat_driver_1 + 0x58);
    uVar3 = 0;
    do {
      ipc_log_context_destroy(*puVar2);
      bVar1 = uVar3 < 2;
      puVar2 = puVar2 + 0xc;
      uVar3 = uVar3 + 1;
    } while (mhi_sat_driver_2 == '\x01' && bVar1);
  }
  kfree(mhi_sat_driver_1);
  mhi_sat_driver_1 = 0;
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00104008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [mhi_sat_dev_remove, init_module, mhi_sat_process_worker, mhi_sat_error_worker, mhi_sat_dev_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104010 size=1
// signature: undefined __mutex_init(void)
// callers: [init_module, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00104018 size=1
// signature: undefined scnprintf(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00104020 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 00104028 size=1
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
// __mhi_driver_register @ 00104030 size=1
// signature: undefined __mhi_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mhi_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 00104038 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00104040 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104048 size=1
// signature: undefined kfree(void)
// callers: [mhi_sat_dev_remove, init_module, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_error_worker, cleanup_module, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [init_module, mhi_sat_process_worker, mhi_sat_rpmsg_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00104058 size=1
// signature: undefined of_property_read_string(void)
// callers: [mhi_sat_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104060 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [mhi_sat_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104068 size=1
// signature: undefined mutex_lock(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_rpmsg_probe, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104070 size=1
// signature: undefined ipc_log_string(void)
// callers: [mhi_sat_dev_remove, mhi_sat_dev_status_cb, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_rpmsg_probe, mhi_sat_error_worker, mhi_sat_rpmsg_cb, mhi_sat_dev_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 00104078 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_rpmsg_probe, mhi_sat_dev_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00104088 size=1
// signature: undefined queue_work_on(void)
// callers: [mhi_sat_dev_status_cb, mhi_sat_rpmsg_probe, mhi_sat_rpmsg_cb, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 00104090 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_rpmsg_probe, mhi_sat_dev_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104098 size=1
// signature: undefined mutex_unlock(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_rpmsg_remove, mhi_sat_rpmsg_probe, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001040a0 size=1
// signature: undefined flush_work(void)
// callers: [mhi_sat_dev_remove, mhi_sat_rpmsg_remove, mhi_sat_error_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_unprepare_from_transfer @ 001040a8 size=1
// signature: undefined mhi_unprepare_from_transfer(void)
// callers: [mhi_sat_process_worker, mhi_sat_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_unprepare_from_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_resource @ 001040b0 size=1
// signature: undefined dma_unmap_resource(void)
// callers: [mhi_sat_dev_remove, mhi_sat_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 001040b8 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [mhi_sat_dev_remove, mhi_sat_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001040c0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001040c8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [mhi_sat_dev_status_cb, mhi_sat_rpmsg_cb, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001040d0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [mhi_sat_dev_status_cb, mhi_sat_rpmsg_cb, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001040d8 size=1
// signature: undefined complete(void)
// callers: [mhi_sat_rpmsg_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001040e0 size=1
// signature: undefined __kmalloc(void)
// callers: [mhi_sat_rpmsg_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001040e8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [mhi_sat_rpmsg_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001040f0 size=1
// signature: undefined __list_add_valid(void)
// callers: [mhi_sat_process_worker, mhi_sat_rpmsg_cb, mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040f8 size=1
// signature: undefined _printk(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_error_worker, mhi_sat_rpmsg_cb, mhi_sat_dev_probe, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_controller_get_numeric_id @ 00104100 size=1
// signature: undefined mhi_controller_get_numeric_id(void)
// callers: [mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_controller_get_numeric_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00104108 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104110 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mhi_sat_dev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00104118 size=1
// signature: undefined cancel_work_sync(void)
// callers: [mhi_sat_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 00104120 size=1
// signature: undefined rpmsg_send(void)
// callers: [mhi_sat_dev_remove, mhi_sat_process_worker, mhi_sat_error_worker, mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00104128 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [mhi_sat_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00104130 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [mhi_sat_dev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_controller_get_base @ 00104138 size=1
// signature: undefined mhi_controller_get_base(void)
// callers: [mhi_sat_connect_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_controller_get_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_prepare_for_transfer @ 00104140 size=1
// signature: undefined mhi_prepare_for_transfer(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_prepare_for_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// is_vmalloc_addr @ 00104150 size=1
// signature: undefined is_vmalloc_addr(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void is_vmalloc_addr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_page_attrs @ 00104158 size=1
// signature: undefined dma_map_page_attrs(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mhi_device_configure @ 00104160 size=1
// signature: undefined mhi_device_configure(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mhi_device_configure(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_map_resource @ 00104168 size=1
// signature: undefined dma_map_resource(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_map_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_driver_string @ 00104170 size=1
// signature: undefined dev_driver_string(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_driver_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 00104178 size=1
// signature: undefined __warn_printk(void)
// callers: [mhi_sat_process_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



