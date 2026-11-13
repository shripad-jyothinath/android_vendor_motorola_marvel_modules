// Decompiled by Ghidra 12.2
// Program: usb_f_qdss.ko
// Image base: 00100000

//------------------------------------------------------------
// usb_qdss_free_req @ 0010067c size=128
// signature: undefined usb_qdss_free_req(void)
// callers: []
//------------------------------------------------------------

void usb_qdss_free_req(undefined8 *param_1)

{
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_001029e8,"usb_qdss_free_req");
  }
  else {
    mutex_lock(param_1 + 0x1a);
    if (*(char *)(param_1 + 0x20) == '\0') {
      _printk(&DAT_0010279c,"usb_qdss_free_req",*param_1);
    }
    else {
      qdss_free_reqs(param_1 + -0x24);
    }
    mutex_unlock(param_1 + 0x1a);
  }
  return;
}



//------------------------------------------------------------
// qdss_free_reqs @ 001006fc size=248
// signature: undefined qdss_free_reqs(void)
// callers: [usb_qdss_free_req, usb_qdss_close, usb_qdss_alloc_req]
//------------------------------------------------------------

void qdss_free_reqs(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  int iVar5;
  long *plVar6;
  long *plVar7;
  
  uVar3 = _raw_spin_lock_irqsave(param_1 + 0x1e0);
  if (*(long **)(param_1 + 0x150) == (long *)(param_1 + 0x150)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    plVar6 = *(long **)(param_1 + 0x150);
    do {
      plVar7 = (long *)*plVar6;
      uVar4 = __list_del_entry_valid(plVar6);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar6;
        plVar2 = (long *)plVar6[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      usb_ep_free_request(*(undefined8 *)(param_1 + 0xe8),plVar6[-2]);
      kfree(plVar6 + -2);
      iVar5 = iVar5 + 1;
      plVar6 = plVar7;
    } while (plVar7 != (long *)(param_1 + 0x150));
  }
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s data_write_req:%d freed\n","qdss_free_reqs",
                 *(undefined8 *)(param_1 + 0x120),iVar5);
  _raw_spin_unlock_irqrestore(param_1 + 0x1e0,uVar3);
  return;
}



//------------------------------------------------------------
// usb_qdss_alloc_req @ 001007f8 size=428
// signature: undefined usb_qdss_alloc_req(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 usb_qdss_alloc_req(undefined8 *param_1,int param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  undefined8 uVar7;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_001029e8,"usb_qdss_alloc_req");
    uVar7 = 0xffffffea;
  }
  else {
    ipc_log_string(_qdss_ipc_log,"%s: channel:%s num_write_buf:%d\n","usb_qdss_alloc_req",*param_1,
                   param_2);
    if (param_1 + -0x24 == (undefined8 *)0x0) {
      _printk(&DAT_0010294a,"usb_qdss_alloc_req",*param_1);
      uVar7 = 0xffffffed;
    }
    else {
      mutex_lock();
      if (0 < param_2) {
        uVar7 = param_1[-7];
        do {
          plVar2 = (long *)kmalloc_trace(_strcmp,0xdc0,0x20);
          if (plVar2 == (long *)0x0) {
LAB_0010096c:
            qdss_free_reqs(param_1 + -0x24);
            mutex_unlock(param_1 + 0x1a);
            return 0xfffffff4;
          }
          lVar3 = usb_ep_alloc_request(uVar7,0xa20);
          if (lVar3 == 0) {
            _printk(&DAT_0010295f,"usb_qdss_alloc_req");
            kfree(plVar2);
            goto LAB_0010096c;
          }
          uVar4 = _raw_spin_lock_irqsave(param_1 + 0x18);
          *plVar2 = lVar3;
          plVar1 = plVar2 + 2;
          *(code **)(lVar3 + 0x30) = qdss_write_complete;
          *(long **)(lVar3 + 0x38) = plVar2;
          plVar6 = (long *)param_1[7];
          uVar5 = __list_add_valid(plVar1,plVar6,param_1 + 6);
          if ((uVar5 & 1) != 0) {
            param_1[7] = plVar1;
            plVar2[2] = (long)(param_1 + 6);
            plVar2[3] = (long)plVar6;
            *plVar6 = (long)plVar1;
          }
          _raw_spin_unlock_irqrestore(param_1 + 0x18,uVar4);
          param_2 = param_2 + -1;
        } while (param_2 != 0);
      }
      mutex_unlock(param_1 + 0x1a);
      uVar7 = 0;
    }
  }
  return uVar7;
}



//------------------------------------------------------------
// qdss_write_complete @ 001009a8 size=348
// signature: undefined qdss_write_complete(void)
// callers: []
//------------------------------------------------------------

void qdss_write_complete(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  ulong uVar5;
  code *pcVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_2 + 0x38);
  lVar2 = *param_1;
  lVar7 = *(long *)(lVar9 + 8);
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s ep:%s req:%pK req->status:%d req->length:%d\n",
                 "qdss_write_complete",*(undefined8 *)(lVar2 + 0x120),param_1[1],param_2,
                 *(undefined4 *)(param_2 + 0x54),*(undefined4 *)(param_2 + 8));
  uVar4 = _raw_spin_lock_irqsave(lVar2 + 0x1e0);
  lVar1 = lVar9 + 0x10;
  uVar5 = __list_del_entry_valid(lVar1);
  if ((uVar5 & 1) != 0) {
    lVar3 = *(long *)(lVar9 + 0x10);
    plVar8 = *(long **)(lVar9 + 0x18);
    *(long **)(lVar3 + 8) = plVar8;
    *plVar8 = lVar3;
  }
  plVar8 = *(long **)(lVar2 + 0x158);
  uVar5 = __list_add_valid(lVar1,plVar8,lVar2 + 0x150);
  if ((uVar5 & 1) != 0) {
    *(long *)(lVar2 + 0x158) = lVar1;
    *(long *)(lVar9 + 0x10) = lVar2 + 0x150;
    *(long **)(lVar9 + 0x18) = plVar8;
    *plVar8 = lVar1;
  }
  if (((*(char *)(lVar2 + 0x220) == '\0') && (*(long *)(lVar2 + 0x170) == lVar2 + 0x170)) &&
     (*(long *)(lVar2 + 0x160) == lVar2 + 0x160)) {
    complete(lVar2 + 0x228);
  }
  if (*(int *)(param_2 + 8) != 0) {
    *(undefined4 *)(lVar7 + 0xc) = *(undefined4 *)(param_2 + 0x58);
    *(undefined4 *)(lVar7 + 0x10) = *(undefined4 *)(param_2 + 0x54);
  }
  _raw_spin_unlock_irqrestore(lVar2 + 0x1e0,uVar4);
  pcVar6 = *(code **)(lVar2 + 0x138);
  if (pcVar6 != (code *)0x0) {
    if (*(int *)(pcVar6 + -4) != -0x5a774cb) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x100ae0);
      (*pcVar6)();
    }
    (*pcVar6)(*(undefined8 *)(lVar2 + 0x140),3,lVar7,0);
  }
  return;
}



//------------------------------------------------------------
// usb_qdss_write @ 00100b08 size=604
// signature: undefined usb_qdss_write(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_qdss_write(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  char *pcVar9;
  long lVar10;
  long *plVar11;
  long *plVar12;
  undefined8 *puVar13;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_001029e8,"usb_qdss_write");
    return 0xffffffea;
  }
  puVar1 = param_1 + 0x1a;
  mutex_lock(puVar1);
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s d_req:%pK\n","usb_qdss_write",*param_1,param_2);
  puVar2 = param_1 + 0x18;
  uVar7 = _raw_spin_lock_irqsave(puVar2);
  if ((*(char *)(param_1 + 0x20) == '\0') || (*(int *)((long)param_1 + -0x14) == 0)) {
    _raw_spin_unlock_irqrestore(puVar2,uVar7);
    ipc_log_string(_qdss_ipc_log,"%s: return -EIO\n","usb_qdss_write");
  }
  else {
    plVar12 = param_1 + 6;
    plVar11 = (long *)*plVar12;
    if (plVar11 == plVar12) {
      _printk(&DAT_00102723);
      _raw_spin_unlock_irqrestore(puVar2,uVar7);
      mutex_unlock(puVar1);
      return 0xfffffff5;
    }
    uVar8 = __list_del_entry_valid(plVar11);
    if ((uVar8 & 1) != 0) {
      lVar10 = *plVar11;
      plVar3 = (long *)plVar11[1];
      *(long **)(lVar10 + 8) = plVar3;
      *plVar3 = lVar10;
    }
    puVar13 = (undefined8 *)param_1[9];
    uVar8 = __list_add_valid(plVar11,puVar13,param_1 + 8);
    if ((uVar8 & 1) != 0) {
      param_1[9] = plVar11;
      *plVar11 = (long)(param_1 + 8);
      plVar11[1] = (long)puVar13;
      *puVar13 = plVar11;
    }
    _raw_spin_unlock_irqrestore(puVar2,uVar7);
    plVar11[-1] = (long)param_2;
    puVar13 = (undefined8 *)plVar11[-2];
    *puVar13 = *param_2;
    uVar7 = _qdss_ipc_log;
    uVar4 = *(undefined4 *)(param_2 + 1);
    *(undefined4 *)(puVar13 + 1) = uVar4;
    lVar10 = param_2[4];
    puVar13[3] = lVar10;
    uVar5 = *(undefined4 *)(param_2 + 5);
    *(undefined4 *)(puVar13 + 4) = uVar5;
    if (lVar10 == 0) {
      pcVar9 = "%s: %s: req:%pK rq->length:0x%x\n";
    }
    else {
      pcVar9 = "%s: %s: req:%pK req->num_sgs:0x%x\n";
      uVar4 = uVar5;
    }
    ipc_log_string(uVar7,pcVar9,"usb_qdss_write",*param_1,puVar13,uVar4);
    iVar6 = usb_ep_queue(param_1[-7],puVar13,0xa20);
    if (iVar6 == 0) {
      mutex_unlock(puVar1);
      return 0;
    }
    uVar7 = _raw_spin_lock_irqsave(puVar2);
    uVar8 = __list_del_entry_valid(plVar11);
    if ((uVar8 & 1) != 0) {
      lVar10 = *plVar11;
      plVar3 = (long *)plVar11[1];
      *(long **)(lVar10 + 8) = plVar3;
      *plVar3 = lVar10;
    }
    puVar13 = (undefined8 *)param_1[7];
    uVar8 = __list_add_valid(plVar11,puVar13,plVar12);
    if ((uVar8 & 1) != 0) {
      param_1[7] = plVar11;
      *plVar11 = (long)plVar12;
      plVar11[1] = (long)puVar13;
      *puVar13 = plVar11;
    }
    _raw_spin_unlock_irqrestore(puVar2,uVar7);
    _printk(&DAT_001025e3);
  }
  mutex_unlock(puVar1);
  return 0xfffffffb;
}



//------------------------------------------------------------
// usb_qdss_open @ 00100d68 size=508
// signature: undefined usb_qdss_open(void)
// callers: []
//------------------------------------------------------------

undefined ** usb_qdss_open(char *param_1,undefined *param_2,undefined *param_3)

{
  int iVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  ipc_log_string(_qdss_ipc_log,"%s: called for channel:%s\n","usb_qdss_open",param_1);
  if (param_3 == (undefined *)0x0) {
    _printk(&DAT_001024e4,"usb_qdss_open");
  }
  else {
    uVar2 = _raw_spin_lock_irqsave(&channel_lock);
    while( true ) {
      ppuVar4 = &usb_qdss_ch_list;
      do {
        ppuVar4 = (undefined **)*ppuVar4;
        if (ppuVar4 == &usb_qdss_ch_list) {
          iVar1 = strcmp(param_1,"qdss_sw");
          if (iVar1 == 0) goto LAB_00100e0c;
          _raw_spin_unlock_irqrestore(&channel_lock,uVar2);
          goto LAB_00100f04;
        }
        iVar1 = strcmp(param_1,ppuVar4[-1]);
      } while (iVar1 != 0);
      ppuVar3 = ppuVar4 + -0x25;
      iVar1 = strcmp(param_1,"qdss_sw");
      if (iVar1 != 0) break;
      if ((ppuVar3 != (undefined **)0x0) && (*ppuVar3 != (undefined *)0x0)) {
        _raw_spin_unlock_irqrestore(&channel_lock,uVar2);
LAB_00100e9c:
        mutex_lock(ppuVar4 + 0x19);
        ipc_log_string(_qdss_ipc_log,"%s: qdss ctx found for channel:%s\n","usb_qdss_open",param_1);
        *(undefined4 *)(ppuVar4 + 0x20) = 0;
        *(undefined1 *)(ppuVar4 + 0x1f) = 1;
        ppuVar4[2] = param_3;
        ppuVar4[3] = param_2;
        if (*(int *)((long)ppuVar4 + -0x1c) != 0) {
          queue_work_on(0x20,ppuVar4[0x18],ppuVar4 + 0xb);
        }
        mutex_unlock(ppuVar4 + 0x19);
        return ppuVar4 + -1;
      }
LAB_00100e0c:
      ipc_log_string(_qdss_ipc_log,"%s: qdss_sw not added to config, fall back to qdss_mdm\n",
                     "usb_qdss_open");
      param_1 = "qdss_mdm";
    }
    _raw_spin_unlock_irqrestore(&channel_lock,uVar2);
    if (ppuVar3 != (undefined **)0x0) goto LAB_00100e9c;
LAB_00100f04:
    ipc_log_string(_qdss_ipc_log,"%s: failed to find channel:%s\n","usb_qdss_open",param_1);
  }
  return (undefined **)0x0;
}



//------------------------------------------------------------
// usb_qdss_close @ 00100f68 size=596
// signature: undefined usb_qdss_close(void)
// callers: []
//------------------------------------------------------------

void usb_qdss_close(undefined8 *param_1)

{
  undefined8 *puVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 *puVar9;
  char *__s1;
  long *plVar10;
  undefined8 *puVar11;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_001029e8,"usb_qdss_close");
  }
  else {
    ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","usb_qdss_close",*param_1);
    mutex_lock(param_1 + 0x1a);
    if (*(char *)(param_1 + 0x20) == '\0') {
      _printk(&DAT_0010279c,"usb_qdss_close",*param_1);
    }
    else {
      puVar1 = param_1 + 0x18;
      uVar7 = _raw_spin_lock_irqsave(puVar1);
      puVar9 = param_1 + 8;
      *(undefined1 *)(param_1 + 0x20) = 0;
      if ((undefined8 *)*puVar9 != puVar9) {
        do {
          plVar10 = (long *)param_1[9];
          uVar8 = __list_del_entry_valid(plVar10);
          if ((uVar8 & 1) != 0) {
            lVar2 = *plVar10;
            plVar3 = (long *)plVar10[1];
            *(long **)(lVar2 + 8) = plVar3;
            *plVar3 = lVar2;
          }
          puVar11 = (undefined8 *)param_1[0xb];
          uVar8 = __list_add_valid(plVar10,puVar11,param_1 + 10);
          if ((uVar8 & 1) != 0) {
            param_1[0xb] = plVar10;
            *plVar10 = (long)(param_1 + 10);
            plVar10[1] = (long)puVar11;
            *puVar11 = plVar10;
          }
          _raw_spin_unlock_irqrestore(puVar1,uVar7);
          uVar5 = usb_ep_dequeue(param_1[-7],plVar10[-2]);
          ipc_log_string(_qdss_ipc_log,"%s: dequeue req:%pK status=%d\n","usb_qdss_close",
                         plVar10[-2],uVar5);
          uVar7 = _raw_spin_lock_irqsave(puVar1);
        } while ((undefined8 *)param_1[8] != puVar9);
      }
      puVar9 = param_1 + 10;
      puVar11 = (undefined8 *)*puVar9;
      _raw_spin_unlock_irqrestore(puVar1,uVar7);
      if (puVar11 != puVar9) {
        ipc_log_string(_qdss_ipc_log,"%s: waiting for completion on dequeued requests\n",
                       "usb_qdss_close");
        wait_for_completion(param_1 + 0x21);
      }
      if ((undefined8 *)*puVar9 != puVar9) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1011bc);
        (*pcVar4)();
      }
      qdss_free_reqs(param_1 + -0x24);
      param_1[3] = 0;
      if (*(int *)((long)param_1 + -0x14) != 0) {
        __s1 = (char *)*param_1;
        iVar6 = strcmp(__s1,"qdss_mdm");
        if ((iVar6 != 0) && (iVar6 = strcmp(__s1,"qdss_sw"), iVar6 != 0)) {
          if (param_1[-1] != 0) {
            usb_ep_dequeue(param_1[-7]);
          }
          iVar6 = set_qdss_data_connection(param_1 + -0x24,0);
          if (iVar6 != 0) {
            _printk(&DAT_00102837,"usb_qdss_close");
          }
        }
      }
    }
    mutex_unlock(param_1 + 0x1a);
  }
  return;
}



//------------------------------------------------------------
// qdss_alloc_inst @ 001011c4 size=112
// signature: undefined qdss_alloc_inst(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long qdss_alloc_inst(void)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_usb_ep_dequeue,0xdc0,200);
  if (lVar1 == 0) {
    lVar1 = -0xc;
  }
  else {
    *(code **)(lVar1 + 0xa8) = usb_qdss_set_inst_name;
    *(code **)(lVar1 + 0xb0) = usb_qdss_free_inst;
    config_group_init_type_name(lVar1,&DAT_001026e4,&qdss_func_type);
  }
  return lVar1;
}



//------------------------------------------------------------
// qdss_alloc @ 00101238 size=84
// signature: undefined qdss_alloc(void)
// callers: []
//------------------------------------------------------------

void qdss_alloc(long param_1)

{
  undefined8 *puVar1;
  
  puVar1 = *(undefined8 **)(param_1 + 0xb8);
  *puVar1 = "usb_qdss";
  puVar1[1] = &qdss_strings;
  puVar1[9] = qdss_bind;
  puVar1[10] = qdss_unbind;
  puVar1[0xd] = qdss_set_alt;
  puVar1[0xb] = qdss_free_func;
  puVar1[0xf] = qdss_disable;
  puVar1[0x10] = 0;
  return;
}



//------------------------------------------------------------
// usb_qdss_free_inst @ 00101290 size=52
// signature: undefined usb_qdss_free_inst(void)
// callers: []
//------------------------------------------------------------

void usb_qdss_free_inst(long param_1)

{
  kfree(*(undefined8 *)(param_1 + 0xb8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// usb_qdss_set_inst_name @ 001012c8 size=644
// signature: undefined usb_qdss_set_inst_name(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 usb_qdss_set_inst_name(long param_1,char *param_2)

{
  undefined *puVar1;
  int iVar2;
  size_t sVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined *puVar8;
  undefined4 uVar9;
  char *__s1;
  undefined **ppuVar10;
  
  sVar3 = strlen(param_2);
  if (sVar3 + 1 < 0x10) {
    lVar5 = kstrndup(param_2,sVar3 + 1,0xcc0);
    uVar4 = _qdss_ipc_log;
    if (lVar5 == 0) {
      puVar8 = &DAT_00102b20;
      uVar4 = 0;
    }
    else {
      *(long *)(param_1 + 0xc0) = lVar5;
      ipc_log_string(uVar4,"%s: qdss: channel_name:%s\n","usb_qdss_set_inst_name");
      __s1 = *(char **)(param_1 + 0xc0);
      uVar4 = _raw_spin_lock_irqsave(&channel_lock);
      ppuVar10 = &usb_qdss_ch_list;
      do {
        ppuVar10 = (undefined **)*ppuVar10;
        if (ppuVar10 == &usb_qdss_ch_list) {
          _raw_spin_unlock_irqrestore(&channel_lock,uVar4);
          uVar6 = kmalloc_trace(_ipc_log_context_create,0xdc0,0x248);
          if (uVar6 != 0) {
            lVar5 = alloc_workqueue(&DAT_00102622,0xe000a,1,__s1);
            *(long *)(uVar6 + 0x1e8) = lVar5;
            if (lVar5 == 0) {
              kfree(uVar6);
            }
            else {
              uVar4 = _raw_spin_lock_irqsave(&channel_lock);
              *(char **)(uVar6 + 0x120) = __s1;
              iVar2 = strcmp(__s1,"qdss_ebc");
              puVar1 = PTR_usb_qdss_ch_list_00102c58;
              puVar8 = (undefined *)(uVar6 + 0x128);
              uVar9 = 3;
              if (iVar2 != 0) {
                uVar9 = 0;
              }
              *(undefined4 *)(uVar6 + 0x148) = uVar9;
              uVar7 = __list_add_valid(puVar8,puVar1,&usb_qdss_ch_list);
              if ((uVar7 & 1) != 0) {
                PTR_usb_qdss_ch_list_00102c58 = puVar8;
                *(undefined ***)(uVar6 + 0x128) = &usb_qdss_ch_list;
                *(undefined **)(uVar6 + 0x130) = puVar1;
                *(undefined **)puVar1 = puVar8;
              }
              _raw_spin_unlock_irqrestore(&channel_lock,uVar4);
              *(undefined4 *)(uVar6 + 0x1e0) = 0;
              *(ulong *)(uVar6 + 0x150) = uVar6 + 0x150;
              *(ulong *)(uVar6 + 0x158) = uVar6 + 0x150;
              *(ulong *)(uVar6 + 0x160) = uVar6 + 0x160;
              *(ulong *)(uVar6 + 0x168) = uVar6 + 0x160;
              *(ulong *)(uVar6 + 0x170) = uVar6 + 0x170;
              *(ulong *)(uVar6 + 0x178) = uVar6 + 0x170;
              *(undefined8 *)(uVar6 + 0x180) = 0xfffffffe0;
              *(ulong *)(uVar6 + 0x188) = uVar6 + 0x188;
              *(ulong *)(uVar6 + 400) = uVar6 + 0x188;
              *(undefined8 *)(uVar6 + 0x1b0) = 0xfffffffe0;
              *(code **)(uVar6 + 0x198) = usb_qdss_connect_work;
              *(ulong *)(uVar6 + 0x1b8) = uVar6 + 0x1b8;
              *(ulong *)(uVar6 + 0x1c0) = uVar6 + 0x1b8;
              *(code **)(uVar6 + 0x1c8) = usb_qdss_disconnect_work;
              __mutex_init(uVar6 + 0x1f0,"&qdss->mutex",&alloc_usb_qdss___key);
              *(undefined4 *)(uVar6 + 0x228) = 0;
              __init_swait_queue_head(uVar6 + 0x230,"&x->wait",&init_completion___key);
              if (uVar6 < 0xfffffffffffff001) {
                *(ulong *)(param_1 + 0xb8) = uVar6;
                return 0;
              }
            }
          }
          goto LAB_00101520;
        }
        iVar2 = strcmp(__s1,ppuVar10[-1]);
      } while (iVar2 != 0);
      _raw_spin_unlock_irqrestore(&channel_lock,uVar4);
      _printk(&DAT_0010277a,"alloc_usb_qdss",__s1);
LAB_00101520:
      uVar4 = *(undefined8 *)(param_1 + 0xc0);
      puVar8 = &DAT_001026e5;
    }
    _printk(puVar8,uVar4);
    uVar4 = 0xfffffff4;
  }
  else {
    uVar4 = 0xffffffdc;
  }
  return uVar4;
}



//------------------------------------------------------------
// usb_qdss_connect_work @ 00101550 size=384
// signature: undefined usb_qdss_connect_work(void)
// callers: []
//------------------------------------------------------------

void usb_qdss_connect_work(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  code *pcVar4;
  undefined8 *puVar5;
  char *__s1;
  long lVar6;
  
  if (*(int *)(param_1 + -0x74) == 0) {
    cancel_work_sync(param_1 + 0x30);
    if (*(long *)(param_1 + -0x80) == 0) {
      return;
    }
    lVar3 = *(long *)(*(long *)(param_1 + -0x80) + 0xd8);
    if (lVar3 == 0) {
      return;
    }
    __pm_runtime_idle(lVar3,5);
    return;
  }
  lVar3 = param_1 + 0x70;
  mutex_lock(lVar3);
  puVar5 = (undefined8 *)(param_1 + -0x60);
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s opened:%d\n","usb_qdss_connect_work",*puVar5,
                 *(undefined1 *)(param_1 + 0xa0));
  if (*(char *)(param_1 + 0xa0) != '\0') {
    __s1 = (char *)*puVar5;
    iVar1 = strcmp(__s1,"qdss_mdm");
    if ((iVar1 == 0) || (iVar1 = strcmp(__s1,"qdss_sw"), iVar1 == 0)) {
LAB_00101620:
      mutex_unlock(lVar3);
      pcVar4 = *(code **)(param_1 + -0x48);
      if (pcVar4 == (code *)0x0) {
        return;
      }
      if (*(int *)(pcVar4 + -4) != -0x5a774cb) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x101658);
        (*pcVar4)();
      }
      (*pcVar4)(*(undefined8 *)(param_1 + -0x40),0,0,puVar5);
      return;
    }
    iVar1 = set_qdss_data_connection(param_1 + -0x180,1);
    if (iVar1 == 0) {
      uVar2 = _raw_spin_lock_irqsave(param_1 + 0x60);
      lVar6 = *(long *)(param_1 + -0x68);
      _raw_spin_unlock_irqrestore(param_1 + 0x60,uVar2);
      if (lVar6 != 0) {
        iVar1 = usb_ep_queue(*(undefined8 *)(param_1 + -0x98),lVar6,0xa20);
        if (iVar1 == 0) goto LAB_00101620;
        _printk(&DAT_001029c9,"usb_qdss_connect_work",iVar1);
      }
    }
    else {
      _printk(&DAT_00102575,iVar1);
    }
  }
  mutex_unlock(lVar3);
  return;
}



//------------------------------------------------------------
// usb_qdss_disconnect_work @ 001016d4 size=264
// signature: undefined usb_qdss_disconnect_work(void)
// callers: []
//------------------------------------------------------------

void usb_qdss_disconnect_work(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  char *__s1;
  
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","usb_qdss_disconnect_work",
                 *(undefined8 *)(param_1 + -0x90));
  pcVar2 = *(code **)(param_1 + -0x78);
  if (pcVar2 != (code *)0x0) {
    if (*(int *)(pcVar2 + -4) != -0x5a774cb) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10173c);
      (*pcVar2)();
    }
    (*pcVar2)(*(undefined8 *)(param_1 + -0x70),1,0,0);
  }
  mutex_lock(param_1 + 0x40);
  if (*(char *)(param_1 + 0x70) != '\0') {
    __s1 = *(char **)(param_1 + -0x90);
    iVar1 = strcmp(__s1,"qdss_mdm");
    if (((iVar1 != 0) && (iVar1 = strcmp(__s1,"qdss_sw"), iVar1 != 0)) &&
       (iVar1 = set_qdss_data_connection(param_1 + -0x1b0,0), iVar1 != 0)) {
      _printk(&DAT_0010259b);
      lVar3 = *(long *)(param_1 + -0xb0);
      goto joined_r0x00101794;
    }
  }
  lVar3 = *(long *)(param_1 + -0xb0);
joined_r0x00101794:
  if ((lVar3 != 0) && (*(long *)(lVar3 + 0xd8) != 0)) {
    __pm_runtime_idle(*(long *)(lVar3 + 0xd8),5);
  }
  mutex_unlock(param_1 + 0x40);
  return;
}



//------------------------------------------------------------
// qdss_attr_release @ 001017e0 size=28
// signature: undefined qdss_attr_release(void)
// callers: []
//------------------------------------------------------------

void qdss_attr_release(void)

{
  usb_put_function_instance();
  return;
}



//------------------------------------------------------------
// qdss_enable_debug_inface_show @ 00101800 size=80
// signature: undefined qdss_enable_debug_inface_show(void)
// callers: []
//------------------------------------------------------------

long qdss_enable_debug_inface_show(long param_1,undefined8 param_2)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = "Disabled";
  if (*(char *)(*(long *)(param_1 + 0xb8) + 0x110) != '\0') {
    pcVar1 = "Enabled";
  }
  iVar2 = scnprintf(param_2,0x1000,&DAT_0010295b,pcVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// qdss_enable_debug_inface_store @ 00101854 size=212
// signature: undefined qdss_enable_debug_inface_store(void)
// callers: []
//------------------------------------------------------------

undefined8 qdss_enable_debug_inface_store(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  char local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0xb8);
  local_3c[0] = '\0';
  if (param_2 == 0) {
    _printk(&DAT_0010285c);
  }
  else {
    iVar2 = kstrtou8(param_2,0,local_3c);
    if (iVar2 != 0) {
      if ((local_3c[0] != '\0') && (local_3c[0] != '\x01')) {
        _printk(&DAT_00102b5d);
        goto LAB_001018d4;
      }
    }
    lVar1 = lVar4 + 0x1e0;
    uVar3 = _raw_spin_lock_irqsave(lVar1);
    *(bool *)(lVar4 + 0x110) = local_3c[0] != '\0';
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
  }
LAB_001018d4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// qdss_bind @ 0010192c size=788
// signature: undefined qdss_bind(void)
// callers: []
//------------------------------------------------------------

int qdss_bind(long param_1,long param_2)

{
  char cVar1;
  int iVar2;
  long *plVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  undefined8 uVar7;
  char *pcVar8;
  
  uVar7 = **(undefined8 **)(param_1 + 0x30);
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","qdss_bind",*(undefined8 *)(param_2 + 0x120));
  iVar2 = usb_interface_id(param_1,param_2);
  if (iVar2 < 0) {
LAB_00101bd8:
    _printk(&DAT_00102a9d);
    return iVar2;
  }
  qdss_data_intf_desc[2] = (undefined1)iVar2;
  *(undefined1 *)(param_2 + 0x10b) = qdss_data_intf_desc[2];
  if (qdss_string_defs == '\0') {
    iVar2 = usb_string_id(*(undefined8 *)(param_1 + 0x30));
    if (iVar2 < 0) {
      return iVar2;
    }
    qdss_string_defs = (char)iVar2;
    cVar1 = *(char *)(param_2 + 0x110);
    qdss_data_intf_desc[8] = qdss_string_defs;
  }
  else {
    cVar1 = *(char *)(param_2 + 0x110);
  }
  if (cVar1 != '\0') {
    iVar2 = usb_interface_id(param_1,param_2);
    if (iVar2 < 0) goto LAB_00101bd8;
    qdss_ctrl_intf_desc[2] = (undefined1)iVar2;
    *(undefined1 *)(param_2 + 0x10a) = qdss_ctrl_intf_desc[2];
    if (DAT_00102d38 == '\0') {
      iVar2 = usb_string_id(*(undefined8 *)(param_1 + 0x30));
      if (iVar2 < 0) {
        return iVar2;
      }
      DAT_00102d38 = (char)iVar2;
      qdss_ctrl_intf_desc[8] = DAT_00102d38;
    }
  }
  pcVar8 = *(char **)(param_2 + 0x120);
  iVar2 = strcmp(pcVar8,"qdss_mdm");
  if ((iVar2 == 0) || (iVar2 = strcmp(pcVar8,"qdss_sw"), iVar2 == 0)) {
    qdss_data_ep_comp_desc._2_1_ = 0;
  }
  plVar3 = (long *)usb_ep_autoconfig(uVar7,qdss_fs_data_desc);
  if (plVar3 != (long *)0x0) {
    *(long **)(param_2 + 0xe8) = plVar3;
    *plVar3 = param_2;
    pcVar8 = *(char **)(param_2 + 0x120);
    iVar2 = strcmp(pcVar8,"qdss_mdm");
    if ((iVar2 != 0) && (iVar2 = strcmp(pcVar8,"qdss_sw"), iVar2 != 0)) {
      iVar2 = msm_ep_set_mode(*(undefined8 *)(param_2 + 0xe8),*(undefined4 *)(param_2 + 0x148));
      if (iVar2 < 0) goto LAB_00101bfc;
      msm_ep_update_ops(*(undefined8 *)(param_2 + 0xe8));
    }
    if (*(char *)(param_2 + 0x110) == '\0') {
LAB_00101aec:
      pcVar8 = *(char **)(param_2 + 0x120);
      iVar2 = strcmp(pcVar8,"qdss_mdm");
      if (((iVar2 == 0) || (iVar2 = strcmp(pcVar8,"qdss_sw"), iVar2 == 0)) ||
         (iVar2 = alloc_hw_req(*(undefined8 *)(param_2 + 0xe8)), iVar2 == 0)) {
        qdss_ss_data_desc[2] = qdss_fs_data_desc[2];
        qdss_hs_data_desc[2] = qdss_fs_data_desc[2];
        if (*(char *)(param_2 + 0x110) == '\0') {
          ppuVar4 = &qdss_fs_data_only_desc;
          ppuVar5 = &qdss_hs_data_only_desc;
          ppuVar6 = &qdss_ss_data_only_desc;
        }
        else {
          ppuVar4 = &qdss_fs_desc;
          ppuVar5 = &qdss_hs_desc;
          qdss_ss_ctrl_in_desc[2] = qdss_fs_ctrl_in_desc[2];
          ppuVar6 = &qdss_ss_desc;
          qdss_hs_ctrl_in_desc[2] = qdss_fs_ctrl_in_desc[2];
          qdss_ss_ctrl_out_desc[2] = qdss_fs_ctrl_out_desc[2];
          qdss_hs_ctrl_out_desc[2] = qdss_fs_ctrl_out_desc[2];
        }
        iVar2 = usb_assign_descriptors(param_2,ppuVar4,ppuVar5,ppuVar6,ppuVar6);
        if (iVar2 == 0) {
          return 0;
        }
        if (*(long *)(param_2 + 0x118) != 0) {
          usb_ep_free_request(*(undefined8 *)(param_2 + 0xe8));
          *(undefined8 *)(param_2 + 0x118) = 0;
        }
      }
      else {
        _printk(&DAT_00102686,"qdss_bind",iVar2);
      }
      goto LAB_00101bfc;
    }
    plVar3 = (long *)usb_ep_autoconfig(uVar7,qdss_fs_ctrl_in_desc);
    if (plVar3 != (long *)0x0) {
      *(long **)(param_2 + 0xe0) = plVar3;
      *plVar3 = param_2;
      plVar3 = (long *)usb_ep_autoconfig(uVar7,qdss_fs_ctrl_out_desc);
      if (plVar3 != (long *)0x0) {
        *(long **)(param_2 + 0xd8) = plVar3;
        *plVar3 = param_2;
        goto LAB_00101aec;
      }
    }
  }
  _printk(&DAT_0010290e,"qdss_bind");
LAB_00101bfc:
  clear_eps(param_2);
  return -0x5f;
}



//------------------------------------------------------------
// qdss_unbind @ 00101c44 size=164
// signature: undefined qdss_unbind(void)
// callers: []
//------------------------------------------------------------

void qdss_unbind(undefined8 param_1,long param_2)

{
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","qdss_unbind",*(undefined8 *)(param_2 + 0x120));
  qdss_disable(param_2);
  __flush_workqueue(*(undefined8 *)(param_2 + 0x1e8));
  if (*(long *)(param_2 + 0x118) != 0) {
    usb_ep_free_request(*(undefined8 *)(param_2 + 0xe8));
    *(undefined8 *)(param_2 + 0x118) = 0;
  }
  qdss_string_defs = 0;
  DAT_00102d38 = 0;
  clear_eps(param_2);
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","clear_desc",*(undefined8 *)(param_2 + 0x120));
  usb_free_all_descriptors(param_2);
  return;
}



//------------------------------------------------------------
// qdss_set_alt @ 00101cec size=680
// signature: undefined qdss_set_alt(void)
// callers: []
//------------------------------------------------------------

int qdss_set_alt(long param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined8 uVar4;
  bool bVar5;
  int iVar6;
  undefined *puVar7;
  char *pcVar8;
  byte bVar9;
  long lVar10;
  undefined8 *puVar11;
  
  lVar10 = **(long **)(*(long *)(param_1 + 0x30) + 0x30);
  ipc_log_string(_qdss_ipc_log,"%s: qdss pointer = %pK\n","qdss_set_alt",param_1);
  *(long *)(param_1 + 0x100) = lVar10;
  if (param_3 != 0) {
    iVar6 = 0;
    goto LAB_00101f84;
  }
  if (*(uint *)(lVar10 + 0x58) < 3) {
    _printk(&DAT_0010286e,"qdss_set_alt");
  }
  else {
    if ((*(byte *)(param_1 + 0x10b) == param_2) && ((*(byte *)(param_1 + 0x1e4) & 1) == 0)) {
      if ((lVar10 != 0) &&
         (((*(long *)(lVar10 + 0xd8) != 0 &&
           (iVar6 = __pm_runtime_resume(*(long *)(lVar10 + 0xd8),5), iVar6 < 0)) && (iVar6 != -0x73)
          ))) {
        piVar1 = (int *)(*(long *)(lVar10 + 0xd8) + 0x1f8);
        iVar6 = *(int *)(*(long *)(lVar10 + 0xd8) + 0x1f8);
        do {
          if (iVar6 == 0) break;
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar2 = *piVar1;
            if (iVar2 != iVar6) goto LAB_00101db0;
            cVar3 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar5) {
              *piVar1 = iVar6 + -1;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
          DataMemoryBarrier(2,3);
LAB_00101db0:
          bVar5 = iVar6 != iVar2;
          iVar6 = iVar2;
        } while (bVar5);
      }
      puVar11 = (undefined8 *)(param_1 + 0xe8);
      iVar6 = config_ep_by_speed(lVar10,param_1,*puVar11);
      if (iVar6 == 0) {
        iVar6 = usb_ep_enable(*puVar11);
        if (iVar6 == 0) {
          bVar9 = 1;
LAB_00101e80:
          *(long *)*puVar11 = param_1;
          *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | bVar9;
          goto LAB_00101e94;
        }
        puVar7 = &DAT_00102bb7;
      }
      else {
        puVar7 = &DAT_00102508;
      }
      _printk(puVar7,"qdss_set_alt",iVar6);
      if ((*(long *)(param_1 + 0x100) != 0) &&
         (lVar10 = *(long *)(*(long *)(param_1 + 0x100) + 0xd8), lVar10 != 0)) {
        __pm_runtime_idle(lVar10,5);
      }
      goto LAB_00101f84;
    }
    if ((*(byte *)(param_1 + 0x10a) != param_2) || (*(char *)(param_1 + 0x110) == '\0')) {
LAB_00101e94:
      uVar4 = _qdss_ipc_log;
      if (*(char *)(param_1 + 0x110) == '\0') {
        if ((*(byte *)(param_1 + 0x1e4) & 1) == 0) goto LAB_00101edc;
        pcVar8 = "%s: usb_connected INTF disabled\n";
      }
      else {
        if (((*(byte *)(param_1 + 0x1e4) ^ 0xff) & 7) != 0) goto LAB_00101edc;
        pcVar8 = "%s: usb_connected INTF enabled\n";
      }
      *(undefined4 *)(param_1 + 0x10c) = 1;
      ipc_log_string(uVar4,pcVar8,"qdss_set_alt");
LAB_00101edc:
      if (*(int *)(param_1 + 0x10c) != 0) {
        queue_work_on(0x20,*(undefined8 *)(param_1 + 0x1e8),param_1 + 0x180);
      }
      return 0;
    }
    iVar6 = config_ep_by_speed(lVar10,param_1,*(undefined8 *)(param_1 + 0xe0));
    if (iVar6 == 0) {
      iVar6 = usb_ep_enable(*(undefined8 *)(param_1 + 0xe0));
      if (iVar6 != 0) goto LAB_00101f84;
      **(long **)(param_1 + 0xe0) = param_1;
      puVar11 = (undefined8 *)(param_1 + 0xd8);
      *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) | 2;
      iVar6 = config_ep_by_speed(lVar10,param_1,*puVar11);
      if (iVar6 == 0) {
        iVar6 = usb_ep_enable(*puVar11);
        if (iVar6 != 0) goto LAB_00101f84;
        bVar9 = 4;
        goto LAB_00101e80;
      }
    }
  }
  iVar6 = -0x16;
LAB_00101f84:
  _printk(&DAT_001026a6,"qdss_set_alt",iVar6);
  qdss_eps_disable(param_1);
  return iVar6;
}



//------------------------------------------------------------
// qdss_disable @ 00101fac size=140
// signature: undefined qdss_disable(void)
// callers: [qdss_unbind]
//------------------------------------------------------------

void qdss_disable(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","qdss_disable",*(undefined8 *)(param_1 + 0x120));
  lVar1 = param_1 + 0x1e0;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  if (*(int *)(param_1 + 0x10c) == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
  }
  else {
    *(undefined4 *)(param_1 + 0x10c) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
    qdss_eps_disable(param_1);
    queue_work_on(0x20,*(undefined8 *)(param_1 + 0x1e8),param_1 + 0x1b0);
  }
  return;
}



//------------------------------------------------------------
// qdss_free_func @ 0010203c size=8
// signature: undefined qdss_free_func(void)
// callers: []
//------------------------------------------------------------

void qdss_free_func(long param_1)

{
  *(undefined1 *)(param_1 + 0x110) = 0;
  return;
}



//------------------------------------------------------------
// clear_eps @ 00102044 size=180
// signature: undefined clear_eps(void)
// callers: [qdss_unbind, qdss_bind]
//------------------------------------------------------------

void clear_eps(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  char *__s1;
  
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","clear_eps",*(undefined8 *)(param_1 + 0x120));
  if (*(undefined8 **)(param_1 + 0xe0) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0xe0) = 0;
  }
  if (*(undefined8 **)(param_1 + 0xd8) != (undefined8 *)0x0) {
    **(undefined8 **)(param_1 + 0xd8) = 0;
  }
  puVar2 = *(undefined8 **)(param_1 + 0xe8);
  if (puVar2 != (undefined8 *)0x0) {
    __s1 = *(char **)(param_1 + 0x120);
    iVar1 = strcmp(__s1,"qdss_mdm");
    if ((iVar1 != 0) && (iVar1 = strcmp(__s1,"qdss_sw"), iVar1 != 0)) {
      msm_ep_clear_ops(puVar2);
      msm_ep_set_mode(*(undefined8 *)(param_1 + 0xe8),0);
      puVar2 = *(undefined8 **)(param_1 + 0xe8);
    }
    *puVar2 = 0;
  }
  return;
}



//------------------------------------------------------------
// qdss_eps_disable @ 001020f8 size=156
// signature: undefined qdss_eps_disable(void)
// callers: [qdss_set_alt, qdss_disable]
//------------------------------------------------------------

void qdss_eps_disable(long param_1)

{
  byte bVar1;
  byte bVar2;
  
  ipc_log_string(_qdss_ipc_log,"%s: channel:%s\n","qdss_eps_disable",
                 *(undefined8 *)(param_1 + 0x120));
  bVar1 = *(byte *)(param_1 + 0x1e4);
  bVar2 = bVar1;
  if ((bVar1 >> 1 & 1) != 0) {
    usb_ep_disable(*(undefined8 *)(param_1 + 0xe0));
    bVar2 = *(byte *)(param_1 + 0x1e4);
    bVar1 = bVar2 & 0xfd;
    *(byte *)(param_1 + 0x1e4) = bVar1;
  }
  if ((bVar2 >> 2 & 1) != 0) {
    usb_ep_disable(*(undefined8 *)(param_1 + 0xd8));
    bVar1 = *(byte *)(param_1 + 0x1e4);
    *(byte *)(param_1 + 0x1e4) = bVar1 & 0xfb;
  }
  if ((bVar1 & 1) != 0) {
    usb_ep_disable(*(undefined8 *)(param_1 + 0xe8));
    *(byte *)(param_1 + 0x1e4) = *(byte *)(param_1 + 0x1e4) & 0xfe;
  }
  return;
}



//------------------------------------------------------------
// alloc_hw_req @ 00102198 size=88
// signature: undefined alloc_hw_req(void)
// callers: [qdss_bind]
//------------------------------------------------------------

undefined8 alloc_hw_req(long *param_1)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *param_1;
  lVar1 = usb_ep_alloc_request(param_1,0xa20);
  if (lVar1 == 0) {
    _printk(&DAT_00102b2d);
    uVar2 = 0xfffffff4;
  }
  else {
    uVar2 = 0;
    *(undefined4 *)(lVar1 + 8) = 0x8000;
    *(long *)(lVar3 + 0x118) = lVar1;
  }
  return uVar2;
}



//------------------------------------------------------------
// set_qdss_data_connection @ 001021f4 size=140
// signature: undefined set_qdss_data_connection(void)
// callers: [usb_qdss_close, usb_qdss_disconnect_work, usb_qdss_connect_work]
//------------------------------------------------------------

int set_qdss_data_connection(long param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  
  if (param_1 == 0) {
    _printk(&DAT_001028a0,"set_qdss_data_connection");
    iVar1 = -0x16;
  }
  else {
    if (param_2 == 0) {
      iVar1 = msm_ep_unconfig(*(undefined8 *)(param_1 + 0xe8));
      if (iVar1 == 0) {
        return 0;
      }
      puVar2 = &DAT_0010255b;
    }
    else {
      iVar1 = msm_ep_config(*(undefined8 *)(param_1 + 0xe8),*(undefined8 *)(param_1 + 0x118),1);
      if (iVar1 == 0) {
        return 0;
      }
      puVar2 = &DAT_001027e1;
    }
    _printk(puVar2);
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 001022fc size=140
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  ulong uVar2;
  
  uVar2 = ipc_log_context_create(10,"usb_qdss",0);
  _qdss_ipc_log = 0;
  if (uVar2 < 0xfffffffffffff001 && uVar2 != 0) {
    _qdss_ipc_log = uVar2;
  }
  usb_qdss_ch_list = (undefined *)&usb_qdss_ch_list;
  PTR_usb_qdss_ch_list_00102c58 = (undefined *)&usb_qdss_ch_list;
  iVar1 = usb_function_register(&qdssusb_func);
  if (iVar1 != 0) {
    _printk(&DAT_00102758,"usb_qdss_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010238c size=240
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  undefined *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  ipc_log_context_destroy(_qdss_ipc_log);
  usb_function_unregister(&qdssusb_func);
  ipc_log_string(_qdss_ipc_log,"%s: cleaning up channel resources.\n","qdss_cleanup");
  ppuVar5 = (undefined **)usb_qdss_ch_list;
  if ((undefined **)usb_qdss_ch_list != &usb_qdss_ch_list) {
    do {
      ppuVar6 = (undefined **)*ppuVar5;
      destroy_workqueue(ppuVar5[0x18]);
      uVar3 = _raw_spin_lock_irqsave(&channel_lock);
      if (ppuVar5[3] == (undefined *)0x0) {
        uVar4 = __list_del_entry_valid(ppuVar5);
        if ((uVar4 & 1) != 0) {
          puVar1 = *ppuVar5;
          plVar2 = (long *)ppuVar5[1];
          *(long **)(puVar1 + 8) = plVar2;
          *plVar2 = (long)puVar1;
        }
        *ppuVar5 = (undefined *)0xdead000000000100;
        ppuVar5[1] = (undefined *)0xdead000000000122;
        kfree(ppuVar5 + -0x25);
      }
      _raw_spin_unlock_irqrestore(&channel_lock,uVar3);
      ppuVar5 = ppuVar6;
    } while (ppuVar6 != &usb_qdss_ch_list);
  }
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [usb_qdss_free_req, usb_qdss_write, usb_qdss_close, usb_qdss_disconnect_work, usb_qdss_alloc_req, usb_qdss_connect_work, usb_qdss_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105008 size=1
// signature: undefined mutex_unlock(void)
// callers: [usb_qdss_free_req, usb_qdss_write, usb_qdss_close, usb_qdss_disconnect_work, usb_qdss_alloc_req, usb_qdss_connect_work, usb_qdss_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105010 size=1
// signature: undefined _printk(void)
// callers: [usb_qdss_free_req, usb_qdss_close, usb_qdss_set_inst_name, init_module, usb_qdss_disconnect_work, qdss_enable_debug_inface_store, qdss_set_alt, qdss_bind, set_qdss_data_connection, usb_qdss_open, alloc_hw_req, usb_qdss_write, usb_qdss_alloc_req, usb_qdss_connect_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105018 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cleanup_module, usb_qdss_write, qdss_write_complete, usb_qdss_close, usb_qdss_set_inst_name, qdss_enable_debug_inface_store, usb_qdss_alloc_req, usb_qdss_connect_work, qdss_disable, usb_qdss_open, qdss_free_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_free_request @ 00105020 size=1
// signature: undefined usb_ep_free_request(void)
// callers: [qdss_unbind, qdss_bind, qdss_free_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105028 size=1
// signature: undefined kfree(void)
// callers: [cleanup_module, usb_qdss_set_inst_name, usb_qdss_alloc_req, usb_qdss_free_inst, qdss_free_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105030 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cleanup_module, usb_qdss_write, qdss_write_complete, usb_qdss_close, qdss_free_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00105038 size=1
// signature: undefined ipc_log_string(void)
// callers: [usb_qdss_close, usb_qdss_set_inst_name, usb_qdss_disconnect_work, qdss_set_alt, qdss_bind, qdss_eps_disable, clear_eps, usb_qdss_open, qdss_free_reqs, cleanup_module, usb_qdss_write, qdss_unbind, qdss_write_complete, usb_qdss_alloc_req, usb_qdss_connect_work, qdss_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105040 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cleanup_module, usb_qdss_write, qdss_write_complete, usb_qdss_close, usb_qdss_set_inst_name, qdss_enable_debug_inface_store, usb_qdss_alloc_req, usb_qdss_connect_work, qdss_disable, usb_qdss_open, qdss_free_reqs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105050 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qdss_alloc_inst, usb_qdss_set_inst_name, usb_qdss_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_alloc_request @ 00105058 size=1
// signature: undefined usb_ep_alloc_request(void)
// callers: [alloc_hw_req, usb_qdss_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105060 size=1
// signature: undefined __list_add_valid(void)
// callers: [usb_qdss_write, qdss_write_complete, usb_qdss_close, usb_qdss_set_inst_name, usb_qdss_alloc_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00105068 size=1
// signature: undefined complete(void)
// callers: [qdss_write_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_queue @ 00105070 size=1
// signature: undefined usb_ep_queue(void)
// callers: [usb_qdss_write, usb_qdss_connect_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105078 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [usb_qdss_close, usb_qdss_set_inst_name, usb_qdss_disconnect_work, qdss_bind, clear_eps, usb_qdss_connect_work, usb_qdss_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105080 size=1
// signature: undefined queue_work_on(void)
// callers: [qdss_set_alt, qdss_disable, usb_qdss_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_dequeue @ 00105088 size=1
// signature: undefined usb_ep_dequeue(void)
// callers: [usb_qdss_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 00105090 size=1
// signature: undefined wait_for_completion(void)
// callers: [usb_qdss_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00105098 size=1
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
// usb_function_register @ 001050a0 size=1
// signature: undefined usb_function_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001050a8 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_unregister @ 001050b0 size=1
// signature: undefined usb_function_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 001050b8 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 001050c0 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [qdss_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001050c8 size=1
// signature: size_t strlen(char * __s)
// callers: [usb_qdss_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 001050d0 size=1
// signature: undefined kstrndup(void)
// callers: [usb_qdss_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001050d8 size=1
// signature: undefined alloc_workqueue(void)
// callers: [usb_qdss_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001050e0 size=1
// signature: undefined __mutex_init(void)
// callers: [usb_qdss_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001050e8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [usb_qdss_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001050f0 size=1
// signature: undefined cancel_work_sync(void)
// callers: [usb_qdss_connect_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 001050f8 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [usb_qdss_disconnect_work, qdss_set_alt, usb_qdss_connect_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_function_instance @ 00105100 size=1
// signature: undefined usb_put_function_instance(void)
// callers: [qdss_attr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_function_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00105108 size=1
// signature: undefined scnprintf(void)
// callers: [qdss_enable_debug_inface_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 00105110 size=1
// signature: undefined kstrtou8(void)
// callers: [qdss_enable_debug_inface_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105118 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qdss_enable_debug_inface_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_interface_id @ 00105120 size=1
// signature: undefined usb_interface_id(void)
// callers: [qdss_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_interface_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_string_id @ 00105128 size=1
// signature: undefined usb_string_id(void)
// callers: [qdss_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_string_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_autoconfig @ 00105130 size=1
// signature: undefined usb_ep_autoconfig(void)
// callers: [qdss_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_autoconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_set_mode @ 00105138 size=1
// signature: undefined msm_ep_set_mode(void)
// callers: [qdss_bind, clear_eps]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_set_mode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_update_ops @ 00105140 size=1
// signature: undefined msm_ep_update_ops(void)
// callers: [qdss_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_update_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_assign_descriptors @ 00105148 size=1
// signature: undefined usb_assign_descriptors(void)
// callers: [qdss_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_assign_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00105150 size=1
// signature: undefined __flush_workqueue(void)
// callers: [qdss_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_free_all_descriptors @ 00105158 size=1
// signature: undefined usb_free_all_descriptors(void)
// callers: [qdss_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_free_all_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00105160 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [qdss_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_ep_by_speed @ 00105170 size=1
// signature: undefined config_ep_by_speed(void)
// callers: [qdss_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_ep_by_speed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_enable @ 00105178 size=1
// signature: undefined usb_ep_enable(void)
// callers: [qdss_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_clear_ops @ 00105180 size=1
// signature: undefined msm_ep_clear_ops(void)
// callers: [clear_eps]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_clear_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_disable @ 00105188 size=1
// signature: undefined usb_ep_disable(void)
// callers: [qdss_eps_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_config @ 00105190 size=1
// signature: undefined msm_ep_config(void)
// callers: [set_qdss_data_connection]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_config(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_ep_unconfig @ 00105198 size=1
// signature: undefined msm_ep_unconfig(void)
// callers: [set_qdss_data_connection]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_ep_unconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



