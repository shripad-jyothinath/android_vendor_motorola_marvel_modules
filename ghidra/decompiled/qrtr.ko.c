// Decompiled by Ghidra 12.2
// Program: qrtr.ko
// Image base: 00100000

//------------------------------------------------------------
// get_qrtr_wakeup_source @ 00101114 size=16
// signature: undefined get_qrtr_wakeup_source(void)
// callers: []
//------------------------------------------------------------

undefined4 get_qrtr_wakeup_source(void)

{
  undefined4 uVar1;
  
  uVar1 = wakeup_source;
  wakeup_source = 0;
  return uVar1;
}



//------------------------------------------------------------
// qrtr_print_wakeup_reason @ 00101128 size=324
// signature: undefined qrtr_print_wakeup_reason(void)
// callers: []
//------------------------------------------------------------

void qrtr_print_wakeup_reason(char *param_1)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  long lVar8;
  undefined8 local_60;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  local_60 = 0;
  if (*param_1 == '\x03') {
    lVar8 = (ulong)(byte)param_1[3] + 0x10;
    uVar4 = (uint)*(ushort *)(param_1 + 8);
    uVar5 = 0xfffffffe;
    if (*(ushort *)(param_1 + 10) != 0xfffe) {
      uVar5 = (uint)*(ushort *)(param_1 + 10);
    }
    uVar6 = (uint)*(ushort *)(param_1 + 0xc);
    uVar7 = 0xfffffffe;
    if (*(ushort *)(param_1 + 0xe) != 0xfffe) {
      uVar7 = (uint)*(ushort *)(param_1 + 0xe);
    }
    puVar3 = (uint *)(param_1 + 4);
  }
  else {
    if (*param_1 != '\x01') goto LAB_00101170;
    uVar4 = *(uint *)(param_1 + 8);
    uVar5 = *(uint *)(param_1 + 0xc);
    uVar6 = *(uint *)(param_1 + 0x18);
    uVar7 = *(uint *)(param_1 + 0x1c);
    puVar3 = (uint *)(param_1 + 0x14);
    lVar8 = 0x20;
  }
  uVar2 = *puVar3;
  iVar1 = qrtr_get_service_id(uVar4,uVar5);
  if (iVar1 < 0) {
    iVar1 = qrtr_get_service_id(uVar6,uVar7);
  }
  if (7 < uVar2) {
    uVar2 = 8;
  }
  memcpy(&local_60,param_1 + lVar8,(ulong)uVar2);
  wakeup_source = uVar5 | uVar4 << 0x10;
  _printk(&DAT_001087ba,"qrtr_print_wakeup_reason",uVar4,uVar5,uVar6,uVar7,local_60 & 0xffffffff,
          local_60._4_4_,iVar1);
LAB_00101170:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_peek_pkt_size @ 00101270 size=104
// signature: undefined qrtr_peek_pkt_size(void)
// callers: []
//------------------------------------------------------------

int qrtr_peek_pkt_size(char *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*param_1 == '\x03') {
    piVar2 = (int *)(param_1 + 4);
    iVar1 = (byte)param_1[3] + 0x10;
  }
  else {
    if (*param_1 != '\x01') {
      _printk(&DAT_00108a0d);
      return -0x16;
    }
    piVar2 = (int *)(param_1 + 0x14);
    iVar1 = 0x20;
  }
  return (*piVar2 + 3U & 0xfffffffc) + iVar1;
}



//------------------------------------------------------------
// qrtr_endpoint_post @ 001012dc size=1232
// signature: undefined qrtr_endpoint_post(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qrtr_endpoint_post(long param_1,char *param_2,ulong param_3)

{
  uint uVar1;
  undefined4 uVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  long lVar8;
  undefined8 *puVar9;
  long lVar10;
  undefined1 uVar11;
  char cVar12;
  long lVar13;
  uint uVar14;
  uint *puVar15;
  long lVar16;
  undefined4 local_6c;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar16 = sp_el0;
  local_48 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 8);
  uVar7 = 0xffffffea;
  local_6c = 0;
  if ((param_3 == 0) || ((param_3 & 3) != 0)) goto LAB_00101660;
  lVar8 = alloc_skb_with_frags(0x20,param_3,0,&local_6c,0xa20);
  if (lVar8 == 0) {
    if (param_3 < 0x400) {
      puVar9 = &qrtr_backup_lo;
LAB_00101368:
      lVar8 = skb_dequeue(puVar9);
      if (lVar8 != 0) {
        queue_work_on(0x20,_system_unbound_wq,&qrtr_backup_work);
        goto LAB_0010138c;
      }
    }
    else if (param_3 >> 0xe == 0) {
      puVar9 = &qrtr_backup_hi;
      goto LAB_00101368;
    }
    _printk(&DAT_00108c4c,param_3);
    uVar7 = 0xfffffff4;
    goto LAB_00101660;
  }
LAB_0010138c:
  *(long *)(lVar8 + 0xe0) = *(long *)(lVar8 + 0xe0) + 0x20;
  *(int *)(lVar8 + 0xd0) = *(int *)(lVar8 + 0xd0) + 0x20;
  if (*param_2 != '\x03') {
    if (*param_2 == '\x01') {
      if (0x1f < param_3) {
        cVar12 = param_2[4];
        puVar15 = (uint *)(param_2 + 0x14);
        *(char *)(lVar8 + 0x38) = cVar12;
        *(undefined4 *)(lVar8 + 0x28) = *(undefined4 *)(param_2 + 8);
        *(undefined4 *)(lVar8 + 0x2c) = *(undefined4 *)(param_2 + 0xc);
        *(bool *)(lVar8 + 0x39) = *(int *)(param_2 + 0x10) != 0;
        *(undefined4 *)(lVar8 + 0x30) = *(undefined4 *)(param_2 + 0x18);
        lVar13 = 0x20;
        uVar14 = *(uint *)(param_2 + 0x1c);
        *(uint *)(lVar8 + 0x34) = uVar14;
        goto LAB_00101470;
      }
    }
    else {
      _printk(&DAT_00108a0d);
    }
    goto LAB_00101650;
  }
  if (param_3 < 0x10) goto LAB_00101650;
  cVar12 = param_2[1];
  bVar3 = param_2[3];
  *(char *)(lVar8 + 0x38) = cVar12;
  *(byte *)(lVar8 + 0x39) = param_2[2] & 1;
  *(uint *)(lVar8 + 0x28) = (uint)*(ushort *)(param_2 + 8);
  uVar4 = *(ushort *)(param_2 + 10);
  *(uint *)(lVar8 + 0x2c) = (uint)uVar4;
  *(uint *)(lVar8 + 0x30) = (uint)*(ushort *)(param_2 + 0xc);
  uVar14 = (uint)*(ushort *)(param_2 + 0xe);
  *(uint *)(lVar8 + 0x34) = uVar14;
  if (uVar4 == 0xfffe) {
    *(undefined4 *)(lVar8 + 0x2c) = 0xfffffffe;
  }
  lVar13 = (ulong)bVar3 + 0x10;
  if (uVar14 == 0xfffe) {
    uVar14 = 0xfffffffe;
    *(undefined4 *)(lVar8 + 0x34) = 0xfffffffe;
  }
  puVar15 = (uint *)(param_2 + 4);
LAB_00101470:
  uVar1 = *puVar15;
  if (uVar14 == 0xffff) {
    uVar14 = 0xfffffffe;
    *(undefined4 *)(lVar8 + 0x34) = 0xfffffffe;
  }
  if ((((uVar1 == 0) || (((ulong)uVar1 + 3 & 0x1fffffffc) + lVar13 != param_3)) ||
      (((cVar12 == '\x04' || (cVar12 == '\a')) && (uVar1 < 0x14)))) ||
     (((uVar14 != 0xfffffffe && (cVar12 != '\a')) && (cVar12 != '\x01')))) goto LAB_00101650;
  *(uint *)(lVar8 + 0x70) = uVar1;
  *(uint *)(lVar8 + 0x74) = uVar1;
  skb_store_bits(lVar8,0,param_2 + lVar13);
  iVar5 = *(int *)(lVar8 + 0x28);
  if ((iVar5 != -1) && (*(int *)(lVar16 + 0x3c) != iVar5)) {
    uVar7 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
    lVar10 = radix_tree_lookup(qrtr_nodes,iVar5);
    if (lVar10 == 0) {
      radix_tree_insert(qrtr_nodes,iVar5,lVar16);
    }
    if (*(int *)(lVar16 + 0x3c) == -1) {
      *(int *)(lVar16 + 0x3c) = iVar5;
    }
    _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar7);
  }
  cVar12 = *(char *)(lVar8 + 0x38);
  if (cVar12 == '\x04') {
    qrtr_node_assign(lVar16,*(undefined4 *)(param_2 + lVar13 + 0xc));
    cVar12 = *(char *)(lVar8 + 0x38);
  }
  local_50 = 0;
  local_60 = 0;
  local_58 = 0;
  local_68 = 0;
  if (cVar12 == '\x01') {
    uVar14 = *(uint *)(lVar8 + 0x70);
    if (7 < uVar14) {
      uVar14 = 8;
    }
    skb_copy_bits(lVar8,0,&local_68,uVar14);
    ipc_log_string(*(undefined8 *)(lVar16 + 0x150),
                   "RX DATA: Len:0x%x CF:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%08x %08x]\n",
                   *(undefined4 *)(lVar8 + 0x70),*(undefined1 *)(lVar8 + 0x39),
                   *(undefined4 *)(lVar8 + 0x28),*(undefined4 *)(lVar8 + 0x2c),
                   *(undefined4 *)(lVar8 + 0x30),*(undefined4 *)(lVar8 + 0x34),(int)local_68,
                   (int)((ulong)local_68 >> 0x20));
    goto switchD_0010162c_caseD_8;
  }
  skb_copy_bits(lVar8,0,&local_60,0x14);
  uVar11 = *(undefined1 *)(lVar8 + 0x38);
  switch(uVar11) {
  case 2:
  case 3:
    uVar7 = *(undefined8 *)(lVar16 + 0x150);
    uVar2 = *(undefined4 *)(lVar8 + 0x28);
    goto LAB_001016d8;
  case 4:
  case 5:
    ipc_log_string(*(undefined8 *)(lVar16 + 0x150),
                   "RX CTRL: cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",uVar11,local_60._4_4_,
                   local_58 & 0xffffffff,local_58._4_4_,local_50);
    break;
  case 6:
  case 7:
    ipc_log_string(*(undefined8 *)(lVar16 + 0x150),"RX CTRL: cmd:0x%x addr[0x%x:0x%x]\n",uVar11,
                   local_60._4_4_,local_58 & 0xffffffff);
    break;
  case 0xd:
    uVar7 = *(undefined8 *)(lVar16 + 0x150);
    uVar11 = 0xd;
    uVar2 = (undefined4)local_58;
LAB_001016d8:
    ipc_log_string(uVar7,"RX CTRL: cmd:0x%x node[0x%x]\n",uVar11,uVar2);
  }
switchD_0010162c_caseD_8:
  iVar5 = qrtr_get_service_id(*(undefined4 *)(lVar8 + 0x28),*(undefined4 *)(lVar8 + 0x2c));
  if ((*(char *)(lVar8 + 0x38) == '\x01') && (*(int *)(lVar8 + 0x30) == qrtr_local_nid)) {
    lVar13 = qrtr_port_lookup(*(undefined4 *)(lVar8 + 0x34));
    if (lVar13 == 0) {
      kfree_skb_reason(lVar8,1);
      uVar7 = 0xffffffed;
    }
    else {
      iVar6 = sock_queue_rcv_skb_reason(lVar13,lVar8,0);
      if (iVar6 == 0) {
        lVar8 = xa_load(lVar16 + 0x158,(long)iVar5);
        if (lVar8 == 0) {
          pm_wakeup_ws_event(*(undefined8 *)(lVar16 + 0x148),0,1);
        }
        qrtr_port_put(lVar13);
        uVar7 = 0;
      }
      else {
        qrtr_port_put(lVar13);
LAB_00101650:
        kfree_skb_reason(lVar8,1);
        uVar7 = 0xffffffea;
      }
    }
  }
  else {
    skb_queue_tail(lVar16 + 0x90,lVar8);
    kthread_queue_work(lVar16 + 0xb8,lVar16 + 0xf8);
    pm_wakeup_ws_event(*(undefined8 *)(lVar16 + 0x148),0,1);
    uVar7 = 0;
  }
LAB_00101660:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// qrtr_node_assign @ 001017ac size=160
// signature: undefined qrtr_node_assign(void)
// callers: [qrtr_endpoint_post]
//------------------------------------------------------------

void qrtr_node_assign(long param_1,int param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_2 != -1) {
    if (*(int *)(param_1 + 0x3c) != param_2) {
      uVar1 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
      lVar2 = radix_tree_lookup(qrtr_nodes,param_2);
      if (lVar2 == 0) {
        radix_tree_insert(qrtr_nodes,param_2,param_1);
      }
      if (*(int *)(param_1 + 0x3c) == -1) {
        *(int *)(param_1 + 0x3c) = param_2;
      }
      _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// qrtr_port_lookup @ 0010184c size=164
// signature: undefined qrtr_port_lookup(void)
// callers: [qrtr_endpoint_post, qrtr_node_rx_work, qrtr_local_enqueue]
//------------------------------------------------------------

long qrtr_port_lookup(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  long lVar7;
  undefined8 uVar8;
  
  iVar2 = 0;
  if (param_1 != -2) {
    iVar2 = param_1;
  }
  uVar6 = _raw_spin_lock_irqsave(&qrtr_port_lock);
  lVar7 = xa_load(qrtr_ports,(long)iVar2);
  if (lVar7 != 0) {
    puVar1 = (uint *)(lVar7 + 0x80);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar3 = *puVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = uVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (uVar3 == 0) {
      uVar8 = 2;
    }
    else {
      if (-1 < (int)(uVar3 + 1 | uVar3)) goto LAB_001018ac;
      uVar8 = 1;
    }
    refcount_warn_saturate(puVar1,uVar8);
  }
LAB_001018ac:
  _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar6);
  return lVar7;
}



//------------------------------------------------------------
// qrtr_port_put @ 001018fc size=104
// signature: undefined qrtr_port_put(void)
// callers: [qrtr_endpoint_post]
//------------------------------------------------------------

void qrtr_port_put(_STACK *param_1)

{
  _STACK *p_Var1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  p_Var1 = param_1 + 4;
  Hint_Prefetch(p_Var1,2,0,1);
  do {
    iVar2 = p_Var1->num;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
    if (bVar4) {
      p_Var1->num = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 == 1) {
    DataMemoryBarrier(2,1);
    sk_free(param_1);
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(p_Var1,3);
  }
  return;
}



//------------------------------------------------------------
// qrtr_endpoint_register @ 00101978 size=688
// signature: undefined qrtr_endpoint_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qrtr_endpoint_register(long *param_1,undefined4 param_2,ulong param_3,long *param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined *puVar4;
  undefined4 uVar5;
  undefined *puVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  ulong uVar11;
  sched_param local_70 [2];
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_70[0].__sched_priority = 1;
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    iVar7 = -0x16;
  }
  else {
    lVar8 = kmalloc_trace(__raw_spin_lock,0xdc0,0x168);
    if (lVar8 == 0) {
      iVar7 = -0xc;
    }
    else {
      *(undefined4 *)(lVar8 + 0x38) = 1;
      __mutex_init(lVar8,"&node->ep_lock",&qrtr_endpoint_register___key);
      *(long **)(lVar8 + 0x30) = param_1;
      lVar1 = lVar8 + 0xb8;
      lVar2 = lVar8 + 0x120;
      *(long *)(lVar8 + 0x98) = lVar8 + 0x90;
      *(undefined8 *)(lVar8 + 0xa0) = 0;
      *(long *)(lVar8 + 0x90) = lVar8 + 0x90;
      *(undefined4 *)(lVar8 + 0x3c) = 0xffffffff;
      *(undefined4 *)(lVar8 + 0x44) = 0;
      *(undefined4 *)(lVar8 + 0x48) = 0;
      *(undefined8 *)(lVar8 + 0x110) = 0;
      *(undefined8 *)(lVar8 + 0x118) = 0;
      *(long *)(lVar8 + 0xf8) = lVar8 + 0xf8;
      *(long *)(lVar8 + 0x100) = lVar8 + 0xf8;
      *(undefined8 *)(lVar8 + 0x120) = 0;
      *(undefined8 *)(lVar8 + 0x128) = 0;
      *(undefined8 *)(lVar8 + 0x130) = 0;
      *(undefined8 *)(lVar8 + 0x138) = 0;
      *(undefined8 *)(lVar8 + 0x140) = 0;
      *(code **)(lVar8 + 0x108) = qrtr_node_rx_work;
      *(long *)(lVar8 + 0x120) = lVar2;
      *(long *)(lVar8 + 0x128) = lVar2;
      *(code **)(lVar8 + 0x130) = qrtr_hello_work;
      __kthread_init_worker(lVar1,"(&node->kworker)->lock",&qrtr_endpoint_register___key_7);
      uVar9 = kthread_create_on_node(&kthread_worker_fn,lVar1,0xffffffff,"qrtr_rx");
      if (uVar9 < 0xfffffffffffff001) {
        wake_up_process(uVar9);
        *(ulong *)(lVar8 + 0xf0) = uVar9;
        if ((param_3 & 1) != 0) {
          sched_setscheduler((__pid_t)uVar9,1,local_70);
        }
        *(undefined8 *)(lVar8 + 0x158) = 0;
        *(undefined8 *)(lVar8 + 0x160) = 0;
        if ((param_4 != (long *)0x0) && (uVar9 = param_4[1], uVar9 != 0)) {
          uVar11 = 0;
          lVar3 = lVar8 + 0x158;
          do {
            uVar5 = *(undefined4 *)(*param_4 + uVar11 * 4);
            _raw_spin_lock(lVar3);
            iVar7 = __xa_insert(lVar3,uVar5,lVar8,0xcc0);
            _raw_spin_unlock(lVar3);
            if (iVar7 != 0) {
              kfree(lVar8);
              goto LAB_00101ac0;
            }
            uVar11 = (ulong)((int)uVar11 + 1);
          } while (uVar11 < uVar9);
        }
        *(undefined8 *)(lVar8 + 0x50) = 0xcc000000000;
        *(undefined8 *)(lVar8 + 0x58) = 0;
        __mutex_init(lVar8 + 0x60,"&node->qrtr_tx_lock",&qrtr_endpoint_register___key_10);
        *(undefined4 *)(lVar8 + 0x40) = param_2;
        down_write(qrtr_epts_lock);
        puVar6 = qrtr_all_epts;
        puVar4 = (undefined *)(lVar8 + 0xa8);
        uVar9 = __list_add_valid(puVar4,&qrtr_all_epts,qrtr_all_epts);
        if ((uVar9 & 1) != 0) {
          *(undefined **)(puVar6 + 8) = puVar4;
          *(undefined **)(lVar8 + 0xa8) = puVar6;
          *(undefined ***)(lVar8 + 0xb0) = &qrtr_all_epts;
          qrtr_all_epts = puVar4;
        }
        up_write(qrtr_epts_lock);
        param_1[1] = lVar8;
        uVar10 = wakeup_source_register(0,"qrtr_ws");
        *(undefined8 *)(lVar8 + 0x148) = uVar10;
        kthread_queue_work(lVar1,lVar2);
        iVar7 = 0;
      }
      else {
        *(ulong *)(lVar8 + 0xf0) = uVar9;
        kfree(lVar8);
        iVar7 = -0xc;
      }
    }
  }
LAB_00101ac0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// qrtr_node_rx_work @ 00101c2c size=1800
// signature: undefined qrtr_node_rx_work(void)
// callers: []
//------------------------------------------------------------

void qrtr_node_rx_work(long param_1)

{
  undefined1 *puVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  _STACK *p_Var8;
  ulong uVar9;
  long lVar10;
  long lVar11;
  long *plVar12;
  ulong uVar13;
  undefined8 uVar14;
  long lVar15;
  int *piVar16;
  _STACK *p_Var17;
  long lVar18;
  long *plVar19;
  undefined **ppuVar20;
  long *plVar21;
  undefined **ppuVar22;
  long *plVar23;
  undefined8 local_e8;
  long local_e0;
  undefined4 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  ulong local_c0;
  undefined4 local_b8;
  undefined4 local_b0;
  int iStack_ac;
  undefined4 local_a8;
  undefined8 local_a0;
  undefined4 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  if (*(long *)(param_1 + 0x58) == 0) {
    snprintf((char *)&local_90,0x20,"qrtr_%d",*(int *)(param_1 + -0xbc));
    uVar14 = ipc_log_context_create(4,&local_90,0);
    *(undefined8 *)(param_1 + 0x58) = uVar14;
  }
  lVar7 = skb_dequeue(param_1 + -0x68);
  if (lVar7 != 0) {
    lVar18 = param_1 + -0x98;
    lVar15 = param_1 + -0xa8;
    piVar16 = (int *)(param_1 + -0xb0);
    do {
      if (*(char *)(lVar7 + 0x38) == '\x01') {
        iVar6 = *(int *)(lVar7 + 0x30);
        if (iVar6 != qrtr_local_nid) goto LAB_00101fb4;
LAB_00101d08:
        p_Var8 = (_STACK *)qrtr_port_lookup(*(undefined4 *)(lVar7 + 0x34));
        if (p_Var8 == (_STACK *)0x0) {
          kfree_skb_reason(lVar7,1);
          goto LAB_00101cdc;
        }
        if (*(char *)(lVar7 + 0x38) == '\x02') {
          if (*(int *)(param_1 + -0xb0) == 0) {
            Hint_Prefetch(piVar16,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(piVar16,0x10);
              if (bVar4) {
                *piVar16 = *piVar16 + 1;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            goto LAB_001021e4;
          }
LAB_00101d2c:
          kfree_skb_reason(lVar7,1);
        }
        else {
LAB_001021e4:
          if (p_Var8[0x1b].num == -2) {
            puVar1 = (undefined1 *)((long)&p_Var8[0x1c].comp + 4);
            while ((iVar6 = sock_queue_rcv_skb_reason(p_Var8,lVar7,0), iVar6 == -0xc ||
                   (iVar6 == -0x69))) {
              uVar14 = _raw_spin_lock_irqsave(puVar1);
              *(undefined4 *)&p_Var8[0x1b].comp = 0;
              *(undefined1 *)&p_Var8[0x1c].comp = 1;
              _raw_spin_unlock_irqrestore(puVar1,uVar14);
              wait_for_completion(&p_Var8[0x1b].comp);
            }
          }
          else {
            iVar6 = sock_queue_rcv_skb_reason(p_Var8,lVar7,0);
          }
          if (iVar6 != 0) {
            _printk(&DAT_00108603,"qrtr_sock_queue_skb",*(undefined1 *)(lVar7 + 0x39));
            goto LAB_00101d2c;
          }
        }
        p_Var17 = p_Var8 + 4;
        Hint_Prefetch(p_Var17,2,0,1);
        do {
          iVar6 = p_Var17->num;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(p_Var17,0x10);
          if (bVar4) {
            p_Var17->num = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        if (iVar6 == 1) {
          DataMemoryBarrier(2,1);
          sk_free(p_Var8);
        }
        else if (iVar6 < 1) {
          refcount_warn_saturate(p_Var17,3);
        }
      }
      else {
        down_read(qrtr_epts_lock);
        for (ppuVar22 = (undefined **)qrtr_all_epts; ppuVar22 != &qrtr_all_epts;
            ppuVar22 = (undefined **)*ppuVar22) {
          ppuVar20 = ppuVar22 + -0x15;
          local_e8 = CONCAT44(local_e8._4_4_,0x2a);
          local_c8 = CONCAT44(local_c8._4_4_,0x2a);
          if (param_1 == 0xf8) {
LAB_00101d58:
            lVar11 = skb_clone(lVar7,0xcc0);
            if (lVar11 == 0) break;
            local_e8 = CONCAT44(*(undefined4 *)(lVar7 + 0x28),(int)local_e8);
            local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar7 + 0x2c));
            local_c8 = CONCAT44(*(undefined4 *)((long)ppuVar22 + -0x6c),(undefined4)local_c8);
            local_c0 = CONCAT44(local_c0._4_4_,0xfffffffe);
            qrtr_node_enqueue(ppuVar20,lVar11,*(undefined1 *)(lVar7 + 0x38),&local_e8,&local_c8,0);
          }
          else if ((((ppuVar20 != (undefined **)0x0) && (*(char *)(lVar7 + 0x38) != '\x02')) &&
                   (*(char *)(lVar7 + 0x38) != '\a')) &&
                  ((ppuVar20 != (undefined **)(param_1 + -0xf8) &&
                   (*(int *)((long)ppuVar22 + -0x6c) != -1)))) {
            iVar5 = *(int *)(ppuVar22 + -0xd) - *(int *)(param_1 + -0xb8);
            iVar6 = -iVar5;
            if (-1 < iVar5) {
              iVar6 = iVar5;
            }
            if (1 < iVar6) goto LAB_00101d58;
          }
        }
        up_read(qrtr_epts_lock);
        cVar3 = *(char *)(lVar7 + 0x38);
        iVar6 = *(int *)(lVar7 + 0x30);
        if (cVar3 == '\a') {
          if (iVar6 != qrtr_local_nid) goto LAB_00101fb4;
          local_d8 = 0;
          local_e8 = 0;
          local_e0 = 0;
          local_c8 = CONCAT44(local_c8._4_4_,0x2a);
          skb_copy_bits(lVar7,0,&local_e8,0x14);
          if ((int)local_e8 == 7) {
            uVar14 = CONCAT44(local_e8._4_4_,(undefined4)local_e0);
            local_c8 = CONCAT44(local_e8._4_4_,(undefined4)local_c8);
            local_c0 = CONCAT44(local_c0._4_4_,(undefined4)local_e0);
            mutex_lock(lVar18);
            lVar11 = radix_tree_lookup(lVar15,uVar14);
            mutex_unlock(lVar18);
            if (lVar11 != 0) {
              uVar14 = _raw_spin_lock_irqsave(lVar11 + 0x30);
              *(undefined4 *)(lVar11 + 0x18) = 0;
              __wake_up(lVar11,1,0,0);
              plVar12 = *(long **)(lVar11 + 0x20);
              while (plVar12 != (long *)(lVar11 + 0x20)) {
                plVar23 = (long *)*plVar12;
                uVar9 = __list_del_entry_valid(plVar12);
                if ((uVar9 & 1) != 0) {
                  lVar10 = *plVar12;
                  plVar21 = (long *)plVar12[1];
                  *(long **)(lVar10 + 8) = plVar21;
                  *plVar21 = lVar10;
                }
                *plVar12 = -0x2152ffffffffff00;
                plVar12[1] = -0x2152fffffffffede;
                lVar10 = __alloc_skb(0,0xa20,0,0xffffffff);
                if (lVar10 != 0) {
                  qrtr_local_enqueue(lVar10,lVar10,7,&local_c8,plVar12[2] + 0x358);
                }
                p_Var17 = (_STACK *)plVar12[2];
                p_Var8 = p_Var17 + 4;
                Hint_Prefetch(p_Var8,2,0,1);
                do {
                  iVar6 = p_Var8->num;
                  cVar3 = '\x01';
                  bVar4 = (bool)ExclusiveMonitorPass(p_Var8,0x10);
                  if (bVar4) {
                    p_Var8->num = iVar6 + -1;
                    cVar3 = ExclusiveMonitorsStatus();
                  }
                } while (cVar3 != '\0');
                if (iVar6 == 1) {
                  DataMemoryBarrier(2,1);
                  sk_free(p_Var17);
                }
                else if (iVar6 < 1) {
                  refcount_warn_saturate(p_Var8,3);
                }
                kfree(plVar12);
                plVar12 = plVar23;
              }
              _raw_spin_unlock_irqrestore(lVar11 + 0x30,uVar14);
              consume_skb(lVar7);
            }
          }
        }
        else if ((iVar6 == qrtr_local_nid) || (cVar3 != '\x01')) {
          if (cVar3 != '\r') goto LAB_00101d08;
          local_b0 = 0x2a;
          iStack_ac = qrtr_local_nid;
          local_98 = 0xfffffffe;
          local_a0 = 0x2a;
          local_a8 = 0xfffffffe;
          local_b8 = 0;
          local_c8 = 0;
          local_c0 = 0;
          local_d8 = 0;
          uStack_d0 = 0;
          skb_copy_bits(lVar7,0,&local_c8,0x14);
          uVar9 = local_c0 & 0xffffffff;
          local_a0 = CONCAT44((undefined4)local_c0,(undefined4)local_a0);
          mutex_lock(lVar18);
          local_e8 = 0;
          local_e0 = 0;
LAB_0010208c:
          plVar12 = (long *)radix_tree_next_chunk(lVar15,&local_e8,0);
          if (plVar12 != (long *)0x0) {
            do {
              lVar11 = *plVar12;
              if (uVar9 == local_e8 >> 0x20) {
                plVar21 = (long *)(lVar11 + 0x20);
                plVar23 = (long *)*plVar21;
                while (plVar23 != plVar21) {
                  plVar19 = (long *)*plVar23;
                  uVar13 = __list_del_entry_valid(plVar23);
                  if ((uVar13 & 1) != 0) {
                    lVar10 = *plVar23;
                    plVar2 = (long *)plVar23[1];
                    *(long **)(lVar10 + 8) = plVar2;
                    *plVar2 = lVar10;
                  }
                  p_Var17 = (_STACK *)plVar23[2];
                  p_Var8 = p_Var17 + 4;
                  *plVar23 = -0x2152ffffffffff00;
                  plVar23[1] = -0x2152fffffffffede;
                  Hint_Prefetch(p_Var8,2,0,1);
                  do {
                    iVar6 = p_Var8->num;
                    cVar3 = '\x01';
                    bVar4 = (bool)ExclusiveMonitorPass(p_Var8,0x10);
                    if (bVar4) {
                      p_Var8->num = iVar6 + -1;
                      cVar3 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar3 != '\0');
                  if (iVar6 == 1) {
                    DataMemoryBarrier(2,1);
                    sk_free(p_Var17);
                  }
                  else if (iVar6 < 1) {
                    refcount_warn_saturate(p_Var8,3);
                  }
                  kfree(plVar23);
                  plVar23 = plVar19;
                }
                kfree(lVar11);
                radix_tree_delete(lVar15,local_e8);
              }
              lVar11 = ~local_e8 + local_e0;
              do {
                if (lVar11 < 1) goto LAB_0010208c;
                local_e8 = local_e8 + 1;
                plVar12 = plVar12 + 1;
                lVar11 = lVar11 + -1;
              } while (*plVar12 == 0);
            } while (plVar12 != (long *)0x0);
            goto LAB_0010208c;
          }
          mutex_unlock(lVar18);
          *(undefined8 *)((ulong)&local_c8 | 4) = 0;
          ((undefined8 *)((ulong)&local_c8 | 4))[1] = 0;
          local_c8 = CONCAT44(local_c8._4_4_,3);
          uVar14 = skb_store_bits(lVar7,0,&local_c8,0x14);
          qrtr_local_enqueue(uVar14,lVar7,3,&local_a0,&local_b0);
        }
        else {
LAB_00101fb4:
          local_c8 = CONCAT44(iVar6,0x2a);
          local_e8 = CONCAT44(*(undefined4 *)(lVar7 + 0x28),0x2a);
          local_e0 = CONCAT44(local_e0._4_4_,*(undefined4 *)(lVar7 + 0x2c));
          local_c0 = CONCAT44(local_c0._4_4_,*(undefined4 *)(lVar7 + 0x34));
          lVar11 = qrtr_node_lookup();
          if (lVar11 == 0) {
            kfree_skb_reason(lVar7,1);
          }
          else {
            qrtr_node_enqueue(lVar11,lVar7,*(undefined1 *)(lVar7 + 0x38),&local_e8,&local_c8,0);
            qrtr_node_release(lVar11);
          }
        }
      }
LAB_00101cdc:
      lVar7 = skb_dequeue(param_1 + -0x68);
    } while (lVar7 != 0);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_hello_work @ 00102368 size=504
// signature: undefined qrtr_hello_work(void)
// callers: []
//------------------------------------------------------------

void qrtr_hello_work(long param_1)

{
  _STACK *p_Var1;
  uint uVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  _STACK *p_Var7;
  long lVar8;
  undefined4 *puVar9;
  undefined8 uVar10;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_40 = 0xfffffffe;
  local_48 = 0x2a;
  local_50 = 0xfffffffe;
  local_58 = 0x2a;
  uVar6 = _raw_spin_lock_irqsave(&qrtr_port_lock);
  p_Var7 = (_STACK *)xa_load(qrtr_ports,0);
  if (p_Var7 == (_STACK *)0x0) {
    _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar6);
    goto LAB_0010254c;
  }
  p_Var1 = p_Var7 + 4;
  Hint_Prefetch(p_Var1,2,0,1);
  do {
    uVar2 = p_Var1->num;
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
    if (bVar5) {
      p_Var1->num = uVar2 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar2 == 0) {
    uVar10 = 2;
LAB_001024f4:
    refcount_warn_saturate(p_Var1,uVar10);
  }
  else if ((int)(uVar2 + 1 | uVar2) < 0) {
    uVar10 = 1;
    goto LAB_001024f4;
  }
  _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar6);
  lVar8 = __alloc_skb(0x34,0xcc0,0,0xffffffff);
  if (lVar8 == 0) {
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar3 = p_Var1->num;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar5) {
        p_Var1->num = iVar3 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar3 == 1) {
      DataMemoryBarrier(2,1);
      goto LAB_001024c4;
    }
  }
  else {
    *(long *)(lVar8 + 0xe0) = *(long *)(lVar8 + 0xe0) + 0x20;
    *(int *)(lVar8 + 0xd0) = *(int *)(lVar8 + 0xd0) + 0x20;
    puVar9 = (undefined4 *)skb_put(lVar8,0x14);
    *(undefined8 *)(puVar9 + 1) = 0;
    *(undefined8 *)(puVar9 + 3) = 0;
    *puVar9 = 2;
    local_48 = CONCAT44(qrtr_local_nid,(undefined4)local_48);
    local_58 = CONCAT44(*(undefined4 *)(param_1 + -0xe4),(undefined4)local_58);
    qrtr_node_enqueue(param_1 + -0x120,lVar8,2,&local_48,&local_58,0);
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar3 = p_Var1->num;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar5) {
        p_Var1->num = iVar3 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar3 == 1) {
      DataMemoryBarrier(2,1);
LAB_001024c4:
      sk_free(p_Var7);
      goto LAB_0010254c;
    }
  }
  if (iVar3 < 1) {
    refcount_warn_saturate(p_Var1,3);
  }
LAB_0010254c:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_endpoint_unregister @ 00102590 size=956
// signature: undefined qrtr_endpoint_unregister(void)
// callers: []
//------------------------------------------------------------

void qrtr_endpoint_unregister(long param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  long *plVar6;
  long lVar7;
  undefined4 *puVar8;
  uint uVar9;
  ulong uVar10;
  undefined **ppuVar11;
  undefined **ppuVar12;
  undefined **ppuVar13;
  ulong local_c8;
  long lStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 uStack_a0;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined8 local_88;
  undefined4 local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  ppuVar11 = *(undefined ***)(param_1 + 8);
  local_a8 = 0x2a;
  local_a4 = qrtr_local_nid;
  uStack_a0 = 0xfffffffe;
  local_94 = *(undefined4 *)((long)ppuVar11 + 0x3c);
  local_98 = 0x2a;
  local_b8 = 0;
  uStack_b0 = 0;
  uStack_90 = 0xfffffffe;
  mutex_lock(ppuVar11);
  ppuVar11[6] = (undefined *)0x0;
  mutex_unlock(ppuVar11);
  uVar5 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
  local_c8 = 0;
  lStack_c0 = 0;
LAB_00102658:
  do {
    plVar6 = (long *)radix_tree_next_chunk(qrtr_nodes,&local_c8,0);
    if (plVar6 == (long *)0x0) {
      _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar5);
      mutex_lock(ppuVar11 + 0xc);
      local_c8 = 0;
      lStack_c0 = 0;
LAB_001028ac:
      do {
        plVar6 = (long *)radix_tree_next_chunk(ppuVar11 + 10,&local_c8,0);
        if (plVar6 == (long *)0x0) {
          mutex_unlock(ppuVar11 + 0xc);
          qrtr_node_release(ppuVar11);
          *(undefined8 *)(param_1 + 8) = 0;
          lVar7 = sp_el0;
          if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
            __stack_chk_fail();
          }
          return;
        }
        do {
          __wake_up(*plVar6,1,0,0);
          lVar7 = ~local_c8 + lStack_c0;
          do {
            uVar10 = local_c8 + 1;
            if (lVar7 < 1) goto LAB_001028ac;
            plVar6 = plVar6 + 1;
            lVar7 = lVar7 + -1;
            local_c8 = uVar10;
          } while (*plVar6 == 0);
        } while (plVar6 != (long *)0x0);
      } while( true );
    }
    do {
      if ((undefined **)*plVar6 == ppuVar11) {
        local_94 = (undefined4)local_c8;
        _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar5);
        lVar7 = __alloc_skb(0x34,0xcc0,0,0xffffffff);
        if (lVar7 != 0) {
          *(long *)(lVar7 + 0xe0) = *(long *)(lVar7 + 0xe0) + 0x20;
          *(int *)(lVar7 + 0xd0) = *(int *)(lVar7 + 0xd0) + 0x20;
          puVar8 = (undefined4 *)skb_put(lVar7,0x14);
          *(undefined8 *)(puVar8 + 1) = 0;
          *(undefined8 *)(puVar8 + 3) = 0;
          *puVar8 = 3;
          qrtr_local_enqueue(puVar8,lVar7,3,&local_98,&local_a8);
        }
        uVar4 = (uint)local_c8;
        local_70 = 0xfffffffe;
        local_78 = 0x2a;
        local_80 = 0xfffffffe;
        local_88 = 0x2a;
        down_read(qrtr_epts_lock);
        if ((undefined **)qrtr_all_epts != &qrtr_all_epts) {
          uVar1 = (uVar4 >> 0x10) + (uVar4 & 0xffff) + 0xe11e;
          ppuVar12 = (undefined **)qrtr_all_epts;
          do {
            ppuVar13 = ppuVar12 + -0x15;
            if (ppuVar11 == (undefined **)0x0) {
LAB_001027b4:
              lVar7 = __alloc_skb(0x34,0xcc0,0,0xffffffff);
              if (lVar7 == 0) goto LAB_00102838;
              *(long *)(lVar7 + 0xe0) = *(long *)(lVar7 + 0xe0) + 0x20;
              *(int *)(lVar7 + 0xd0) = *(int *)(lVar7 + 0xd0) + 0x20;
              puVar8 = (undefined4 *)skb_put(lVar7,0x14);
              *(undefined8 *)(puVar8 + 3) = 0;
              *puVar8 = 0xd;
              puVar8[2] = uVar4;
              if (puVar8 == (undefined4 *)0x0) {
                uVar9 = 0;
              }
              else {
                uVar9 = uVar1;
                if (0xffff < uVar1) {
                  do {
                    uVar9 = (uVar9 >> 0x10) + (uVar9 & 0xffff);
                  } while (uVar9 >> 0x10 != 0);
                }
                uVar9 = uVar9 ^ 0xffff;
              }
              puVar8[1] = uVar9;
              local_78 = CONCAT44(*(undefined4 *)((long)ppuVar11 + 0x3c),(undefined4)local_78);
              local_88 = CONCAT44(*(undefined4 *)((long)ppuVar12 + -0x6c),(undefined4)local_88);
              qrtr_node_enqueue(ppuVar13,lVar7,0xd,&local_78,&local_88,0);
            }
            else if (((ppuVar13 != (undefined **)0x0) && (ppuVar13 != ppuVar11)) &&
                    (*(int *)((long)ppuVar12 + -0x6c) != -1)) {
              iVar3 = *(int *)(ppuVar12 + -0xd) - *(int *)(ppuVar11 + 8);
              iVar2 = -iVar3;
              if (-1 < iVar3) {
                iVar2 = iVar3;
              }
              if (1 < iVar2) goto LAB_001027b4;
            }
            ppuVar12 = (undefined **)*ppuVar12;
          } while (ppuVar12 != &qrtr_all_epts);
        }
        up_read(qrtr_epts_lock);
LAB_00102838:
        uVar5 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
      }
      lVar7 = ~local_c8 + lStack_c0;
      do {
        uVar10 = local_c8 + 1;
        if (lVar7 < 1) goto LAB_00102658;
        plVar6 = plVar6 + 1;
        lVar7 = lVar7 + -1;
        local_c8 = uVar10;
      } while (*plVar6 == 0);
    } while (plVar6 != (long *)0x0);
  } while( true );
}



//------------------------------------------------------------
// qrtr_local_enqueue @ 00102950 size=616
// signature: undefined qrtr_local_enqueue(void)
// callers: [qrtr_node_rx_work, qrtr_port_remove, qrtr_sendmsg, qrtr_endpoint_unregister, qrtr_bcast_enqueue]
//------------------------------------------------------------

undefined8
qrtr_local_enqueue(undefined8 param_1,long param_2,undefined4 param_3,long param_4,long param_5)

{
  _STACK *p_Var1;
  undefined1 *puVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  _STACK *p_Var7;
  undefined8 uVar8;
  long lVar9;
  
  lVar9 = *(long *)(param_2 + 0x18);
  p_Var7 = (_STACK *)qrtr_port_lookup(*(undefined4 *)(param_5 + 8));
  if (p_Var7 == (_STACK *)0x0) {
    if (*(int *)(param_5 + 8) != -2) goto LAB_00102b70;
  }
  else {
    if (p_Var7 == *(_STACK **)(param_2 + 0x18)) {
      p_Var1 = p_Var7 + 4;
      Hint_Prefetch(p_Var1,2,0,1);
      do {
        iVar6 = p_Var1->num;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
        if (bVar5) {
          p_Var1->num = iVar6 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar6 == 1) {
        DataMemoryBarrier(2,1);
        sk_free(p_Var7);
      }
      else if (iVar6 < 1) {
        refcount_warn_saturate(p_Var1,3);
      }
LAB_00102b70:
      uVar8 = 0xffffffed;
      goto LAB_00102bb0;
    }
    if ((lVar9 == 0) || (*(int *)(lVar9 + 0x230) != 0x66)) {
      *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(param_4 + 4);
      uVar8 = qrtr_local_ilc;
      lVar9 = sp_el0;
      *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(param_4 + 8);
      ipc_log_string(uVar8,"LOCAL ENQUEUE: cmd:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%s] pid:%d\n",
                     param_3,*(undefined4 *)(param_4 + 4),*(undefined4 *)(param_4 + 8),
                     *(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 8),lVar9 + 0x848,
                     *(undefined4 *)(lVar9 + 0x630));
      if (p_Var7[0x1b].num == -2) {
        puVar2 = (undefined1 *)((long)&p_Var7[0x1c].comp + 4);
        while ((iVar6 = sock_queue_rcv_skb_reason(p_Var7,param_2,0), iVar6 == -0xc ||
               (iVar6 == -0x69))) {
          uVar8 = _raw_spin_lock_irqsave(puVar2);
          *(undefined4 *)&p_Var7[0x1b].comp = 0;
          *(undefined1 *)&p_Var7[0x1c].comp = 1;
          _raw_spin_unlock_irqrestore(puVar2,uVar8);
          wait_for_completion(&p_Var7[0x1b].comp);
        }
      }
      else {
        iVar6 = sock_queue_rcv_skb_reason(p_Var7,param_2,0);
      }
      p_Var1 = p_Var7 + 4;
      Hint_Prefetch(p_Var1,2,0,1);
      do {
        iVar3 = p_Var1->num;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
        if (bVar5) {
          p_Var1->num = iVar3 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (iVar3 == 1) {
        DataMemoryBarrier(2,1);
        sk_free(p_Var7);
      }
      else if (iVar3 < 1) {
        refcount_warn_saturate(p_Var1,3);
      }
      if (iVar6 == 0) {
        return 0;
      }
      uVar8 = 0xffffffe4;
      goto LAB_00102bb0;
    }
    *(undefined4 *)(lVar9 + 0x230) = 0x66;
    sk_error_report(lVar9);
    p_Var1 = p_Var7 + 4;
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar6 = p_Var1->num;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar5) {
        p_Var1->num = iVar6 + -1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    if (iVar6 == 1) {
      DataMemoryBarrier(2,1);
      sk_free(p_Var7);
    }
    else if (iVar6 < 1) {
      refcount_warn_saturate(p_Var1,3);
    }
  }
  uVar8 = 0;
LAB_00102bb0:
  kfree_skb_reason(param_2,1);
  return uVar8;
}



//------------------------------------------------------------
// qrtr_node_release @ 00102be8 size=808
// signature: undefined qrtr_node_release(void)
// callers: [qrtr_node_rx_work, qrtr_recvmsg, qrtr_port_remove, qrtr_sendmsg, qrtr_endpoint_unregister]
//------------------------------------------------------------

void qrtr_node_release(long param_1)

{
  int *piVar1;
  _STACK *p_Var2;
  long lVar3;
  long *plVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  long *plVar8;
  ulong uVar9;
  undefined8 uVar10;
  long *plVar11;
  _STACK *p_Var12;
  long lVar13;
  long *plVar14;
  long *plVar15;
  ulong local_88;
  long lStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x38);
    uVar9 = refcount_dec_not_one(piVar1);
    if ((uVar9 & 1) == 0) {
      down_write(qrtr_epts_lock);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar5 = *piVar1;
        cVar6 = '\x01';
        bVar7 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar7) {
          *piVar1 = iVar5 + -1;
          cVar6 = ExclusiveMonitorsStatus();
        }
      } while (cVar6 != '\0');
      if (iVar5 == 1) {
        DataMemoryBarrier(2,1);
        local_78 = 0;
        uStack_70 = 0;
        uVar10 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
        local_88 = 0;
        lStack_80 = 0;
LAB_00102c9c:
        plVar11 = (long *)radix_tree_next_chunk(qrtr_nodes,&local_88,0);
        if (plVar11 != (long *)0x0) {
          do {
            if (*plVar11 == param_1) {
              radix_tree_iter_delete(qrtr_nodes,&local_88,plVar11);
            }
            lVar13 = ~local_88 + lStack_80;
            do {
              uVar9 = local_88 + 1;
              if (lVar13 < 1) goto LAB_00102c9c;
              plVar11 = plVar11 + 1;
              lVar13 = lVar13 + -1;
              local_88 = uVar9;
            } while (*plVar11 == 0);
          } while (plVar11 != (long *)0x0);
          goto LAB_00102c9c;
        }
        _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar10);
        uVar9 = __list_del_entry_valid(param_1 + 0xa8);
        if ((uVar9 & 1) != 0) {
          lVar13 = *(long *)(param_1 + 0xa8);
          plVar11 = *(long **)(param_1 + 0xb0);
          *(long **)(lVar13 + 8) = plVar11;
          *plVar11 = lVar13;
        }
        *(undefined8 *)(param_1 + 0xa8) = 0xdead000000000100;
        *(undefined8 *)(param_1 + 0xb0) = 0xdead000000000122;
        up_write(qrtr_epts_lock);
        kthread_flush_worker(param_1 + 0xb8);
        kthread_stop(*(undefined8 *)(param_1 + 0xf0));
        skb_queue_purge(param_1 + 0x90);
        wakeup_source_unregister(*(undefined8 *)(param_1 + 0x148));
        xa_destroy(param_1 + 0x158);
        mutex_lock(param_1 + 0x60);
        local_88 = 0;
        lStack_80 = 0;
LAB_00102da0:
        plVar11 = (long *)radix_tree_next_chunk(param_1 + 0x50,&local_88,0);
        if (plVar11 != (long *)0x0) {
          do {
            lVar13 = *plVar11;
            plVar15 = (long *)(lVar13 + 0x20);
            plVar8 = (long *)*plVar15;
            while (plVar8 != plVar15) {
              plVar14 = (long *)*plVar8;
              uVar9 = __list_del_entry_valid(plVar8);
              if ((uVar9 & 1) != 0) {
                lVar3 = *plVar8;
                plVar4 = (long *)plVar8[1];
                *(long **)(lVar3 + 8) = plVar4;
                *plVar4 = lVar3;
              }
              p_Var12 = (_STACK *)plVar8[2];
              p_Var2 = p_Var12 + 4;
              *plVar8 = -0x2152ffffffffff00;
              plVar8[1] = -0x2152fffffffffede;
              Hint_Prefetch(p_Var2,2,0,1);
              do {
                iVar5 = p_Var2->num;
                cVar6 = '\x01';
                bVar7 = (bool)ExclusiveMonitorPass(p_Var2,0x10);
                if (bVar7) {
                  p_Var2->num = iVar5 + -1;
                  cVar6 = ExclusiveMonitorsStatus();
                }
              } while (cVar6 != '\0');
              if (iVar5 == 1) {
                DataMemoryBarrier(2,1);
                sk_free(p_Var12);
              }
              else if (iVar5 < 1) {
                refcount_warn_saturate(p_Var2,3);
              }
              kfree(plVar8);
              plVar8 = plVar14;
            }
            radix_tree_iter_delete(param_1 + 0x50,&local_88,plVar11);
            kfree(lVar13);
            lVar13 = ~local_88 + lStack_80;
            do {
              uVar9 = local_88 + 1;
              if (lVar13 < 1) goto LAB_00102da0;
              plVar11 = plVar11 + 1;
              lVar13 = lVar13 + -1;
              local_88 = uVar9;
            } while (*plVar11 == 0);
          } while (plVar11 != (long *)0x0);
          goto LAB_00102da0;
        }
        mutex_unlock(param_1 + 0x60);
        kfree(param_1);
      }
      else {
        if (iVar5 < 1) {
          refcount_warn_saturate(piVar1,3);
        }
        up_write(qrtr_epts_lock);
      }
    }
  }
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_node_enqueue @ 00102f30 size=2324
// signature: undefined qrtr_node_enqueue(void)
// callers: [qrtr_node_rx_work, qrtr_hello_work, qrtr_recvmsg, qrtr_port_remove, qrtr_endpoint_unregister, qrtr_bcast_enqueue]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00103808) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qrtr_node_enqueue(long param_1,long param_2,int param_3,long param_4,long param_5,uint param_6
                       )

{
  long lVar1;
  long *plVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  char cVar8;
  bool bVar9;
  uint uVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  long lVar14;
  undefined4 *puVar15;
  undefined8 *puVar16;
  uint uVar17;
  uint uVar18;
  long *plVar19;
  uint uVar20;
  ulong uVar21;
  ulong uVar22;
  uint uVar23;
  undefined8 uVar24;
  long lVar25;
  ulong local_a8;
  undefined8 local_98;
  undefined8 local_90;
  ulong local_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar25 = sp_el0;
  local_68 = *(long *)(lVar25 + 0x638);
  uVar18 = *(uint *)(param_2 + 0x70);
  mutex_lock();
  if (((param_3 != 2) && (*(int *)(param_1 + 0x44) == 0)) ||
     ((param_3 == 2 && (*(int *)(param_1 + 0x44) != 0)))) {
    kfree_skb_reason(param_2,1);
    mutex_unlock(param_1);
    uVar21 = 0;
    goto LAB_00102fb8;
  }
  if ((param_3 == 2) && (*(int *)(param_1 + 0x44) == 0)) {
    piVar4 = (int *)(param_1 + 0x44);
    Hint_Prefetch(piVar4,2,0,1);
    do {
      cVar8 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(piVar4,0x10);
      if (bVar9) {
        *piVar4 = *piVar4 + 1;
        cVar8 = ExclusiveMonitorsStatus();
      }
    } while (cVar8 != '\0');
  }
  mutex_unlock(param_1);
  lVar25 = *(long *)(param_2 + 0x18);
  if (lVar25 == 0) {
    uVar22 = (ulong)*(byte *)(param_2 + 0x39);
  }
  else if (param_3 == 1) {
    uVar24 = CONCAT44(*(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 8));
    if ((param_6 >> 6 & 1) == 0) {
      local_a8 = *(ulong *)(lVar25 + 400);
    }
    else {
      local_a8 = 0;
    }
    lVar1 = param_1 + 0x60;
    mutex_lock(lVar1);
    lVar14 = radix_tree_lookup(param_1 + 0x50,uVar24);
    if (lVar14 != 0) {
LAB_00103080:
      mutex_unlock(lVar1);
      lVar1 = lVar14 + 0x30;
      _raw_spin_lock_irq(lVar1);
      uVar22 = local_a8;
      if ((*(int *)(lVar14 + 0x18) < 10) || (*(int *)(lVar14 + 0x1c) != 0)) {
        if (local_a8 != 0) goto LAB_001030b8;
        uVar22 = 1;
LAB_00103144:
        if (*(long *)(param_1 + 0x30) != 0) {
          if (*(int *)(lVar14 + 0x1c) == 0) {
            if ((uVar22 == 0) && (9 < *(int *)(lVar14 + 0x18))) {
              plVar2 = (long *)(lVar14 + 0x20);
              plVar19 = plVar2;
LAB_001031f4:
              plVar19 = (long *)*plVar19;
              if (plVar19 != plVar2) goto code_r0x00103200;
              plVar19 = (long *)kmalloc_trace(_kfree,0xb20,0x18);
              if (plVar19 == (long *)0x0) {
                uVar22 = 0xfffffff4;
                goto LAB_001037a4;
              }
              puVar3 = (uint *)(lVar25 + 0x80);
              plVar19[2] = lVar25;
              Hint_Prefetch(puVar3,2,0,1);
              do {
                uVar18 = *puVar3;
                cVar8 = '\x01';
                bVar9 = (bool)ExclusiveMonitorPass(puVar3,0x10);
                if (bVar9) {
                  *puVar3 = uVar18 + 1;
                  cVar8 = ExclusiveMonitorsStatus();
                }
              } while (cVar8 != '\0');
              if (uVar18 == 0) {
                uVar24 = 2;
LAB_00103870:
                refcount_warn_saturate(puVar3,uVar24);
              }
              else if ((int)(uVar18 + 1 | uVar18) < 0) {
                uVar24 = 1;
                goto LAB_00103870;
              }
              puVar16 = *(undefined8 **)(lVar14 + 0x28);
              uVar21 = __list_add_valid(plVar19,puVar16,plVar2);
              if ((uVar21 & 1) != 0) {
                *(long **)(lVar14 + 0x28) = plVar19;
                *plVar19 = (long)plVar2;
                plVar19[1] = (long)puVar16;
                *puVar16 = plVar19;
              }
              lVar25 = sp_el0;
              ipc_log_string(*(undefined8 *)(param_1 + 0x150),"new waiter %s[%d] for [0x%x:0x%x]\n",
                             lVar25 + 0x848,*(undefined4 *)(lVar25 + 0x630),
                             *(undefined4 *)(param_5 + 4),*(undefined4 *)(param_5 + 8));
LAB_001037a0:
              uVar22 = 0xfffffff5;
              goto LAB_001037a4;
            }
            iVar12 = *(int *)(lVar14 + 0x18) + 1;
            uVar22 = (ulong)(iVar12 == 5);
            *(int *)(lVar14 + 0x18) = iVar12;
          }
          else {
            uVar22 = 1;
            *(undefined4 *)(lVar14 + 0x1c) = 0;
          }
          _raw_spin_unlock_irq(lVar1);
          goto LAB_00103228;
        }
        uVar22 = 0xffffffe0;
LAB_001037a4:
        _raw_spin_unlock_irq(lVar1);
      }
      else {
        if (*(long *)(param_1 + 0x30) == 0 && local_a8 == 0) {
          uVar22 = 1;
        }
        if ((*(long *)(param_1 + 0x30) != 0) && (uVar22 != 0)) {
          local_80 = 0;
          uStack_78 = 0;
          local_90 = 0;
          local_88 = 0;
          local_98 = 0;
          init_wait_entry(&local_98,0);
          uVar22 = prepare_to_wait_event(lVar14,&local_98,1);
          if (9 < *(int *)(lVar14 + 0x18)) {
            while (*(int *)(lVar14 + 0x1c) == 0) {
              if (*(long *)(param_1 + 0x30) == 0 && local_a8 == 0) {
                local_a8 = 1;
              }
              if ((*(long *)(param_1 + 0x30) == 0) || (local_a8 == 0)) goto LAB_001031c4;
              if (uVar22 != 0) goto LAB_001030b8;
              _raw_spin_unlock_irq(lVar1);
              local_a8 = schedule_timeout(local_a8);
              _raw_spin_lock_irq(lVar1);
              uVar22 = prepare_to_wait_event(lVar14,&local_98,1);
              if (*(int *)(lVar14 + 0x18) < 10) break;
            }
          }
          if (local_a8 == 0) {
            local_a8 = 1;
          }
LAB_001031c4:
          uVar22 = local_a8;
          finish_wait(lVar14,&local_98);
        }
LAB_001030b8:
        if (-1 < (long)uVar22) goto LAB_00103144;
        _raw_spin_unlock_irq(lVar1);
        if (-1 < (int)uVar22) goto LAB_00103228;
      }
      kfree_skb_reason(param_2,1);
      uVar21 = uVar22 & 0xffffffff;
      goto LAB_00102fb8;
    }
    lVar14 = kmalloc_trace(_kfree,0xdc0,0x38);
    if (lVar14 != 0) {
      *(long *)(lVar14 + 0x20) = lVar14 + 0x20;
      *(long *)(lVar14 + 0x28) = lVar14 + 0x20;
      __init_waitqueue_head(lVar14,"&flow->resume_tx",&qrtr_tx_wait___key);
      *(undefined4 *)(lVar14 + 0x30) = 0;
      iVar12 = radix_tree_insert(param_1 + 0x50,uVar24,lVar14);
      if (iVar12 == 0) goto LAB_00103080;
      kfree(lVar14);
    }
    mutex_unlock(lVar1);
    uVar22 = 1;
  }
  else {
    uVar22 = 0;
  }
LAB_00103228:
  puVar15 = (undefined4 *)skb_push(param_2,0x20);
  *puVar15 = 1;
  puVar15[1] = param_3;
  puVar15[2] = *(undefined4 *)(param_4 + 4);
  puVar15[3] = *(undefined4 *)(param_4 + 8);
  if (*(int *)(param_5 + 8) == -2) {
    puVar15[6] = *(undefined4 *)(param_1 + 0x3c);
    uVar6 = 0xfffffffe;
  }
  else {
    puVar15[6] = *(undefined4 *)(param_5 + 4);
    uVar6 = *(undefined4 *)(param_5 + 8);
  }
  puVar15[7] = uVar6;
  local_98 = 0;
  local_90 = 0;
  local_70 = 0;
  puVar15[4] = (uint)((int)uVar22 != 0);
  puVar15[5] = uVar18;
  local_88 = local_88 & 0xffffffff00000000;
  if ((param_2 != 0) && (puVar15 != (undefined4 *)0x0)) {
    uVar17 = puVar15[1];
    if (uVar17 == 1) {
      uVar17 = uVar18;
      if (7 < uVar18) {
        uVar17 = 8;
      }
      skb_copy_bits(param_2,0x20,&local_70,uVar17);
      lVar25 = sp_el0;
      ipc_log_string(*(undefined8 *)(param_1 + 0x150),
                     "TX DATA: Len:0x%x CF:0x%x src[0x%x:0x%x] dst[0x%x:0x%x] [%08x %08x] [%s]\n",
                     puVar15[5],puVar15[4],puVar15[2],puVar15[3],puVar15[6],puVar15[7],(int)local_70
                     ,(int)((ulong)local_70 >> 0x20),lVar25 + 0x848);
    }
    else {
      skb_copy_bits(param_2,0x20,&local_98,0x14);
      uVar23 = uVar17 & 0xfffffffe;
      if (uVar23 == 2) {
        uVar24 = *(undefined8 *)(param_1 + 0x150);
        uVar6 = puVar15[2];
LAB_0010339c:
        ipc_log_string(uVar24,"TX CTRL: cmd:0x%x node[0x%x]\n",uVar17,uVar6);
      }
      else if (uVar23 == 6) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x150),"TX CTRL: cmd:0x%x addr[0x%x:0x%x]\n",uVar17
                       ,local_98._4_4_,local_90 & 0xffffffff);
      }
      else if (uVar23 == 4) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x150),
                       "TX CTRL: cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",uVar17,local_98._4_4_,
                       local_90 & 0xffffffff,local_90._4_4_,local_88 & 0xffffffff);
      }
      else if (uVar17 == 0xd) {
        uVar24 = *(undefined8 *)(param_1 + 0x150);
        uVar17 = 0xd;
        uVar6 = (undefined4)local_90;
        goto LAB_0010339c;
      }
    }
  }
  if (*(int *)(param_2 + 0x74) == 0) {
    uVar18 = (uVar18 + 3 & 0xfffffffc) + 0x20;
    iVar12 = uVar18 - *(uint *)(param_2 + 0x70);
    if (uVar18 < *(uint *)(param_2 + 0x70) || iVar12 == 0) goto LAB_00103544;
    iVar13 = __skb_pad(param_2,iVar12,1);
    if (iVar13 == 0) {
      if (*(int *)(param_2 + 0x74) != 0) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x800,0x103880);
        (*pcVar11)();
      }
      *(int *)(param_2 + 0xd0) = *(int *)(param_2 + 0xd0) + iVar12;
      *(int *)(param_2 + 0x70) = *(int *)(param_2 + 0x70) + iVar12;
      goto LAB_00103544;
    }
    uVar21 = 0xfffffff4;
    _printk(&DAT_00108a45,"qrtr_node_enqueue",*(int *)(param_2 + 0x70),
            *(int *)(param_2 + 0x70) + 3U & 0xfffffffc,0xfffffff4);
LAB_001035a0:
    if ((int)uVar22 != 0) {
      uVar18 = *(uint *)(param_5 + 4);
      iVar12 = *(int *)(param_5 + 8);
      mutex_lock(param_1 + 0x60);
      lVar25 = radix_tree_lookup(param_1 + 0x50,(long)iVar12 | (ulong)uVar18 << 0x20);
      mutex_unlock(param_1 + 0x60);
      if (lVar25 != 0) {
        _raw_spin_lock_irq(lVar25 + 0x30);
        *(undefined4 *)(lVar25 + 0x1c) = 1;
        _raw_spin_unlock_irq(lVar25 + 0x30);
      }
    }
  }
  else {
    uVar18 = *(uint *)(param_2 + 0x70);
    uVar17 = uVar18 + 3 & 0xfffffffc;
    uVar23 = uVar17 - uVar18;
    if (uVar23 != 0) {
      uVar21 = (ulong)*(byte *)(*(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + 2);
      if (uVar21 != 0) {
        lVar25 = 0;
        uVar20 = uVar18 - *(int *)(param_2 + 0x74);
        lVar1 = sp_el0;
        do {
          lVar14 = *(long *)(param_2 + 0xd8) + (ulong)*(uint *)(param_2 + 0xd4) + lVar25;
          iVar12 = *(int *)(lVar14 + 0x50);
          uVar5 = iVar12 + uVar20;
          if (uVar18 <= uVar5) {
            uVar7 = *(uint *)(lVar14 + 0x54);
            lVar14 = *(long *)(lVar14 + 0x48);
            if (uVar5 < uVar17) {
              if (iVar12 != 0) {
                uVar10 = iVar12 - (uVar18 - uVar20);
                *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
                *(int *)(lVar1 + 0xb68) = *(int *)(lVar1 + 0xb68) + 1;
                memset((void *)(((lVar14 + ((ulong)(uVar7 >> 6) & 0x3ffffc0)) * 0x40 &
                                 0xfffffffffff000 | 0xff00000000000000) + (ulong)(uVar7 & 0xfff) +
                               (ulong)(uVar18 - uVar20)),0,(ulong)uVar10);
                *(int *)(lVar1 + 0xb68) = *(int *)(lVar1 + 0xb68) + -1;
                lVar14 = *(long *)(lVar1 + 0x10) + -1;
                *(int *)(lVar1 + 0x10) = (int)lVar14;
                if ((lVar14 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
                  preempt_schedule();
                }
                uVar23 = uVar23 - uVar10;
                uVar18 = *(int *)(param_2 + 0x70) + uVar10;
                *(uint *)(param_2 + 0x70) = uVar18;
                *(uint *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) + uVar23;
                if (uVar18 != uVar17) goto LAB_001033f8;
                goto LAB_00103544;
              }
            }
            else if (iVar12 != 0) {
              lVar1 = sp_el0;
              *(int *)(lVar1 + 0x10) = *(int *)(lVar1 + 0x10) + 1;
              *(int *)(lVar1 + 0xb68) = *(int *)(lVar1 + 0xb68) + 1;
              memset((void *)(((lVar14 + ((ulong)(uVar7 >> 6) & 0x3ffffc0)) * 0x40 &
                               0xfffffffffff000 | 0xff00000000000000) + (ulong)(uVar7 & 0xfff) +
                             (ulong)(uVar18 - uVar20)),0,(ulong)uVar23);
              *(int *)(lVar1 + 0xb68) = *(int *)(lVar1 + 0xb68) + -1;
              lVar25 = *(long *)(lVar1 + 0x10) + -1;
              *(int *)(lVar1 + 0x10) = (int)lVar25;
              if ((lVar25 == 0) || (*(long *)(lVar1 + 0x10) == 0)) {
                preempt_schedule();
              }
              *(uint *)(param_2 + 0x70) = uVar17;
              *(uint *)(param_2 + 0x74) = *(int *)(param_2 + 0x74) + uVar23;
              goto LAB_00103544;
            }
            uVar5 = uVar20;
            if (uVar18 == uVar17) goto LAB_00103544;
          }
LAB_001033f8:
          uVar20 = uVar5;
          lVar25 = lVar25 + 0x10;
        } while (uVar21 * 0x10 != lVar25);
      }
      if (uVar18 != uVar17) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x800,0x1037cc);
        (*pcVar11)();
      }
    }
LAB_00103544:
    mutex_lock(param_1);
    puVar16 = *(undefined8 **)(param_1 + 0x30);
    if (puVar16 == (undefined8 *)0x0) {
      kfree_skb_reason(param_2,1);
      uVar21 = 0xffffffed;
    }
    else {
      if (*(int *)((code *)*puVar16 + -4) != 0x7a1e53f7) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x103574);
        (*pcVar11)();
      }
      uVar21 = (*(code *)*puVar16)(puVar16,param_2);
      uVar21 = uVar21 & 0xffffffff;
    }
    mutex_unlock(param_1);
    if ((int)uVar21 != 0) goto LAB_001035a0;
  }
  if ((param_3 == 2) && ((int)uVar21 != 0)) {
    piVar4 = (int *)(param_1 + 0x44);
    Hint_Prefetch(piVar4,2,0,1);
    do {
      cVar8 = '\x01';
      bVar9 = (bool)ExclusiveMonitorPass(piVar4,0x10);
      if (bVar9) {
        *piVar4 = *piVar4 + -1;
        cVar8 = ExclusiveMonitorsStatus();
      }
    } while (cVar8 != '\0');
    kthread_queue_work(param_1 + 0xb8,param_1 + 0x120);
  }
LAB_00102fb8:
  lVar25 = sp_el0;
  if (*(long *)(lVar25 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar21;
code_r0x00103200:
  if (plVar19[2] == lVar25) goto LAB_001037a0;
  goto LAB_001031f4;
}



//------------------------------------------------------------
// qrtr_node_lookup @ 00103880 size=184
// signature: undefined qrtr_node_lookup(void)
// callers: [qrtr_node_rx_work, qrtr_recvmsg, qrtr_port_remove, qrtr_sendmsg]
//------------------------------------------------------------

long qrtr_node_lookup(undefined4 param_1)

{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  undefined8 uVar7;
  
  down_read(qrtr_epts_lock);
  uVar5 = _raw_spin_lock_irqsave(&qrtr_nodes_lock);
  lVar6 = radix_tree_lookup(qrtr_nodes,param_1);
  if (lVar6 != 0) {
    puVar1 = (uint *)(lVar6 + 0x38);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar2 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 0) {
      uVar7 = 2;
    }
    else {
      if (-1 < (int)(uVar2 + 1 | uVar2)) goto LAB_001038e8;
      uVar7 = 1;
    }
    refcount_warn_saturate(puVar1,uVar7);
  }
LAB_001038e8:
  _raw_spin_unlock_irqrestore(&qrtr_nodes_lock,uVar5);
  up_read(qrtr_epts_lock);
  return lVar6;
}



//------------------------------------------------------------
// qrtr_create @ 00103948 size=224
// signature: undefined qrtr_create(void)
// callers: []
//------------------------------------------------------------

undefined8 qrtr_create(undefined8 param_1,long param_2,undefined8 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (*(short *)(param_2 + 4) == 2) {
    lVar2 = sk_alloc(param_1,0x2a,0xcc0,qrtr_proto,param_4);
    if (lVar2 == 0) {
      uVar3 = 0xfffffff4;
    }
    else {
      *(ulong *)(lVar2 + 0x60) = *(ulong *)(lVar2 + 0x60) | 0x100;
      *(uint *)(lVar2 + 0x208) = *(uint *)(lVar2 + 0x208) | 0x4000;
      sock_init_data(param_2,lVar2);
      *(undefined1 **)(param_2 + 0x20) = qrtr_proto_ops;
      uVar1 = qrtr_local_nid;
      *(undefined2 *)(lVar2 + 0x358) = 0x2a;
      *(undefined4 *)(lVar2 + 0x360) = 0;
      *(undefined1 *)(lVar2 + 0x398) = 0;
      *(undefined4 *)(lVar2 + 0x370) = 0xffffffff;
      *(undefined4 *)(lVar2 + 0x35c) = uVar1;
      *(undefined4 *)(lVar2 + 0x378) = 0;
      __init_swait_queue_head(lVar2 + 0x380,"&x->wait",&init_completion___key);
      uVar3 = 0;
      *(undefined4 *)(lVar2 + 0x39c) = 0;
    }
  }
  else {
    uVar3 = 0xffffffa5;
  }
  return uVar3;
}



//------------------------------------------------------------
// qrtr_release @ 00103a2c size=360
// signature: undefined qrtr_release(void)
// callers: []
//------------------------------------------------------------

undefined8 qrtr_release(long param_1)

{
  _STACK *p_Var1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  ulong uVar6;
  undefined **ppuVar7;
  _STACK *p_Var8;
  
  p_Var8 = *(_STACK **)(param_1 + 0x18);
  if (p_Var8 != (_STACK *)0x0) {
    lock_sock_nested(p_Var8,0);
    if (p_Var8[0x1b].num == -2) {
      down_write(qrtr_epts_lock);
      for (ppuVar7 = (undefined **)qrtr_all_epts; ppuVar7 != &qrtr_all_epts;
          ppuVar7 = (undefined **)*ppuVar7) {
        *(undefined4 *)((long)ppuVar7 + -100) = 0;
        *(undefined4 *)(ppuVar7 + -0xc) = 0;
      }
      up_write(qrtr_epts_lock);
    }
    *(undefined1 *)((long)&p_Var8[0x13].sorted + 2) = 3;
    uVar6 = *(ulong *)(p_Var8 + 3);
    if ((uVar6 & 1) == 0) {
      if (*(int *)(*(code **)&p_Var8[0x15].sorted + -4) != 0x72ab2a2a) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x103ad4);
        (*pcVar5)();
      }
      (**(code **)&p_Var8[0x15].sorted)(p_Var8);
      uVar6 = *(ulong *)(p_Var8 + 3);
    }
    *(ulong *)(p_Var8 + 3) = uVar6 | 1;
    _raw_write_lock_bh(&p_Var8[0x11].data);
    uVar6 = *(ulong *)(p_Var8 + 3);
    *(undefined8 *)(p_Var8 + 0x14) = 0;
    p_Var8[9].data = (char **)0x0;
    *(ulong *)(p_Var8 + 3) = uVar6 | 1;
    _raw_write_unlock_bh(&p_Var8[0x11].data);
    *(undefined8 *)(param_1 + 0x18) = 0;
    if (((uint)*(undefined8 *)(p_Var8 + 3) >> 8 & 1) == 0) {
      qrtr_port_remove(p_Var8);
    }
    skb_queue_purge(&p_Var8[6].comp);
    release_sock(p_Var8);
    p_Var1 = p_Var8 + 4;
    Hint_Prefetch(p_Var1,2,0,1);
    do {
      iVar2 = p_Var1->num;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(p_Var1,0x10);
      if (bVar4) {
        p_Var1->num = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 == 1) {
      DataMemoryBarrier(2,1);
      sk_free(p_Var8);
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(p_Var1,3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// qrtr_bind @ 00103ba8 size=144
// signature: undefined qrtr_bind(void)
// callers: []
//------------------------------------------------------------

undefined4 qrtr_bind(long param_1,short *param_2,uint param_3)

{
  undefined4 uVar1;
  long lVar2;
  
  if (((param_3 < 0xc) || (*param_2 != 0x2a)) ||
     (lVar2 = *(long *)(param_1 + 0x18), *(int *)(param_2 + 2) != *(int *)(lVar2 + 0x35c))) {
    return 0xffffffea;
  }
  lock_sock_nested(lVar2,0);
  uVar1 = __qrtr_bind(param_1,param_2,(uint)*(undefined8 *)(lVar2 + 0x60) >> 8 & 1);
  release_sock(lVar2);
  return uVar1;
}



//------------------------------------------------------------
// qrtr_connect @ 00103c3c size=260
// signature: undefined qrtr_connect(void)
// callers: []
//------------------------------------------------------------

int qrtr_connect(undefined4 *param_1,short *param_2,uint param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if ((param_3 < 0xc) || (*param_2 != 0x2a)) {
    iVar1 = -0x16;
    goto LAB_00103d0c;
  }
  lVar3 = *(long *)(param_1 + 6);
  lock_sock_nested(lVar3,0);
  *(undefined1 *)(lVar3 + 0x12) = 7;
  *param_1 = 1;
  local_48 = 0x2a;
  if (((uint)*(undefined8 *)(*(long *)(param_1 + 6) + 0x60) >> 8 & 1) == 0) {
LAB_00103cd4:
    iVar1 = 0;
    uVar2 = *(undefined8 *)param_2;
    *(undefined4 *)(lVar3 + 0x36c) = *(undefined4 *)(param_2 + 4);
    *(undefined8 *)(lVar3 + 0x364) = uVar2;
    *param_1 = 3;
    *(undefined1 *)(lVar3 + 0x12) = 1;
  }
  else {
    local_44 = qrtr_local_nid;
    uStack_40 = 0;
    iVar1 = __qrtr_bind(param_1,&local_48,1);
    if (iVar1 == 0) goto LAB_00103cd4;
  }
  release_sock(lVar3);
LAB_00103d0c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// qrtr_getname @ 00103d44 size=208
// signature: undefined qrtr_getname(void)
// callers: []
//------------------------------------------------------------

void qrtr_getname(long param_1,undefined2 *param_2,int param_3)

{
  undefined2 uVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar3 = sp_el0;
  lVar3 = *(long *)(lVar3 + 0x638);
  lVar6 = *(long *)(param_1 + 0x18);
  lock_sock_nested(lVar6,0);
  if (param_3 == 0) {
    lVar4 = 0x35a;
  }
  else {
    if (*(char *)(lVar6 + 0x12) != '\x01') {
      release_sock(lVar6);
      uVar2 = 0xffffff95;
      goto LAB_00103de4;
    }
    lVar4 = 0x366;
  }
  uVar5 = *(undefined8 *)(lVar6 + lVar4);
  uVar1 = *(undefined2 *)((undefined8 *)(lVar6 + lVar4) + 1);
  release_sock(lVar6);
  uVar2 = 0xc;
  *param_2 = 0x2a;
  *(undefined8 *)(param_2 + 1) = uVar5;
  param_2[5] = uVar1;
LAB_00103de4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != lVar3) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qrtr_ioctl @ 00103e18 size=780
// signature: undefined qrtr_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 qrtr_ioctl(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int iVar5;
  undefined4 uVar6;
  long *plVar7;
  ulong uVar8;
  long lVar9;
  undefined4 uVar10;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar9 = sp_el0;
  local_38 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x18);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  local_50 = 0;
  local_60 = 0;
  lock_sock_nested(lVar9,0);
  uVar1 = param_2 - 0x890b;
  if (uVar1 < 0x12) {
    uVar10 = 0xffffffea;
    if ((1 << (ulong)(uVar1 & 0x1f) & 0x3f803U) != 0) goto LAB_00103e8c;
    if (uVar1 == 10) {
      iVar5 = get_user_ifreq(&local_60,0,param_3);
      uVar10 = 0xfffffff2;
      if (iVar5 == 0) {
        local_50 = *(undefined8 *)(lVar9 + 0x358);
        local_48 = CONCAT44(local_48._4_4_,*(undefined4 *)(lVar9 + 0x360));
        iVar5 = put_user_ifreq(&local_60,param_3);
        uVar10 = 0;
        if (iVar5 != 0) {
          uVar10 = 0xfffffff2;
        }
      }
      goto LAB_00103e8c;
    }
  }
  if (param_2 == 0x541b) {
    uVar6 = 0;
    plVar7 = *(long **)(lVar9 + 0xd8);
    if ((plVar7 != (long *)(lVar9 + 0xd8)) && (plVar7 != (long *)0x0)) {
      uVar6 = *(undefined4 *)(plVar7 + 0xe);
    }
    puVar3 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    uVar10 = 0xfffffff2;
    if (uVar8 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar3[1];
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar10 = 0;
      *(undefined4 *)(param_3 & 0xff7fffffffffffff) = uVar6;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
  }
  else if (param_2 == 0x5411) {
    puVar3 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar3 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar3 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    uVar10 = 0xfffffff2;
    if (uVar8 < 0x7ffffffffd) {
      iVar2 = *(int *)(lVar9 + 0x14c) - *(int *)(lVar9 + 0x154);
      iVar5 = 0;
      if (0 < iVar2 + 1) {
        iVar5 = iVar2 + 1;
      }
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr1_el1 = puVar3[1] & 0xffff000000000000 | uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar3[1];
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      uVar10 = 0;
      *(int *)(param_3 & 0xff7fffffffffffff) = iVar5;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar4 = daif;
          daif = uVar4 | 0xc0;
        }
        uVar4 = ttbr1_el1;
        ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar4 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
    }
  }
  else {
    uVar10 = 0xfffffdfd;
  }
LAB_00103e8c:
  release_sock(lVar9);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
}



//------------------------------------------------------------
// qrtr_sendmsg @ 00104158 size=984
// signature: undefined qrtr_sendmsg(void)
// callers: []
//------------------------------------------------------------

int qrtr_sendmsg(long param_1,undefined8 *param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  ulong uVar8;
  uint uVar9;
  long lVar10;
  ushort *puVar11;
  long lVar12;
  code *pcVar13;
  int local_84;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined4 local_70;
  int local_6c;
  uint local_68;
  int local_64;
  undefined4 uStack_60;
  long local_58;
  
  lVar10 = sp_el0;
  local_58 = *(long *)(lVar10 + 0x638);
  local_6c = 1;
  puVar11 = (ushort *)*param_2;
  local_70 = 0;
  lVar10 = *(long *)(param_1 + 0x18);
  local_80 = 0;
  uStack_78 = 0;
  local_84 = 0;
  if ((*(uint *)((long)param_2 + 0x44) & 0xffffffbf) != 0) {
    iVar2 = -0x16;
    goto LAB_001044d8;
  }
  if (param_3 >> 0x10 != 0) {
    iVar2 = -0x5a;
    goto LAB_001044d8;
  }
  lock_sock_nested(lVar10,0);
  if (puVar11 == (ushort *)0x0) {
    if (*(char *)(lVar10 + 0x12) == '\x01') {
      puVar11 = (ushort *)(lVar10 + 0x364);
      goto LAB_00104230;
    }
LAB_00104280:
    release_sock(lVar10);
    iVar2 = -0x6b;
    goto LAB_001044d8;
  }
  if ((*(uint *)(param_2 + 1) < 0xc) || (uVar6 = (uint)*puVar11, uVar6 != 0x2a)) {
    release_sock(lVar10);
    iVar2 = -0x16;
    goto LAB_001044d8;
  }
  local_68 = uVar6;
  if (((uint)*(undefined8 *)(*(long *)(param_1 + 0x18) + 0x60) >> 8 & 1) == 0) {
    local_84 = 0;
  }
  else {
    local_64 = qrtr_local_nid;
    uStack_60 = 0;
    iVar2 = __qrtr_bind(param_1,&local_68,1);
    local_84 = iVar2;
    if (iVar2 != 0) {
      release_sock(lVar10);
      goto LAB_001044d8;
    }
  }
LAB_00104230:
  if (*(int *)(puVar11 + 2) == -1) {
    lVar12 = 0;
    pcVar13 = qrtr_bcast_enqueue;
    if ((*(int *)(puVar11 + 4) != -2) && (qrtr_local_nid != -1)) goto LAB_00104280;
  }
  else if (*(int *)(puVar11 + 2) == *(int *)(lVar10 + 0x35c)) {
    lVar12 = 0;
    pcVar13 = qrtr_local_enqueue;
  }
  else {
    lVar12 = qrtr_node_lookup();
    if (lVar12 == 0) {
      release_sock(lVar10);
      iVar2 = -0x68;
      goto LAB_001044d8;
    }
    iVar2 = *(int *)(lVar10 + 0x370);
    if (iVar2 < 0) {
      if (iVar2 == -1) {
        uVar7 = *(undefined4 *)(lVar12 + 0x3c);
        goto LAB_00104308;
      }
    }
    else if (iVar2 != *(int *)(lVar12 + 0x3c)) {
      uVar7 = 0xfffffffe;
LAB_00104308:
      *(undefined4 *)(lVar10 + 0x370) = uVar7;
    }
    pcVar13 = qrtr_node_enqueue;
  }
  uVar8 = param_3 + 3 & 0xfffffffffffffffc;
  uVar6 = (int)uVar8 - 16000;
  if (uVar8 < 0x3e81) {
    uVar6 = 0;
  }
  uVar9 = (int)uVar8 - 0x2e81U & 0xfffff000;
  if (uVar8 < 0x3e81) {
    uVar9 = 0;
  }
  lVar3 = sock_alloc_send_pskb
                    (lVar10,(uVar8 - uVar6) + 0x20,uVar9,*(uint *)((long)param_2 + 0x44) & 0x40,
                     &local_84,3);
  if (lVar3 == 0) {
    local_84 = -0xc;
  }
  else {
    iVar2 = (int)param_3;
    *(long *)(lVar3 + 0xe0) = *(long *)(lVar3 + 0xe0) + 0x20;
    *(int *)(lVar3 + 0xd0) = *(int *)(lVar3 + 0xd0) + 0x20;
    skb_put(lVar3,iVar2 - uVar6);
    *(int *)(lVar3 + 0x70) = iVar2;
    *(uint *)(lVar3 + 0x74) = uVar6;
    local_84 = skb_copy_datagram_from_iter(lVar3,0,param_2 + 2,param_3 & 0xffffffff);
    if (local_84 == 0) {
      if ((*(int *)(lVar10 + 0x360) == -2) || (*(int *)(puVar11 + 4) == -2)) {
        if (param_3 < 4) {
          local_84 = -0x16;
          goto LAB_001043a8;
        }
        skb_copy_bits(lVar3,0,&local_6c,4);
        iVar5 = local_6c;
        if ((*(int *)(puVar11 + 4) == -2) && (local_6c == 4)) {
          *(undefined4 *)(lVar10 + 0x370) = 0xfffffffe;
          skb_copy_bits(lVar3,0,&local_80,0x14);
          lVar4 = qrtr_node_lookup(uStack_78._4_4_);
          if (lVar4 != 0) {
            if (((lVar12 != 0) && (lVar12 != lVar4)) && (*(int *)(lVar12 + 0x3c) != -1)) {
              iVar1 = *(int *)(lVar12 + 0x40) - *(int *)(lVar4 + 0x40);
              iVar5 = -iVar1;
              if (-1 < iVar1) {
                iVar5 = iVar1;
              }
              if (1 < iVar5) goto LAB_00104474;
            }
            local_84 = 0;
            kfree_skb_reason(lVar3,1);
            qrtr_node_release(lVar4);
            goto LAB_001044c4;
          }
LAB_00104474:
          qrtr_node_release(lVar4);
          iVar5 = 4;
        }
      }
      else {
        iVar5 = 1;
      }
      if (*(int *)(pcVar13 + -4) != -0x486da343) {
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(0x823a,0x1044b4);
        (*pcVar13)();
      }
      local_84 = (*pcVar13)(lVar12,lVar3,iVar5,lVar10 + 0x358,puVar11,
                            *(undefined4 *)((long)param_2 + 0x44));
      if (-1 < local_84) {
        local_84 = iVar2;
      }
    }
    else {
LAB_001043a8:
      kfree_skb_reason(lVar3,1);
    }
  }
LAB_001044c4:
  qrtr_node_release(lVar12);
  release_sock(lVar10);
  iVar2 = local_84;
LAB_001044d8:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qrtr_recvmsg @ 00104534 size=528
// signature: undefined qrtr_recvmsg(void)
// callers: []
//------------------------------------------------------------

void qrtr_recvmsg(long param_1,undefined8 *param_2,ulong param_3,undefined4 param_4)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  undefined8 *puVar9;
  int local_6c [3];
  undefined4 local_60;
  undefined4 local_58;
  undefined4 uStack_54;
  undefined4 local_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  lVar7 = *(long *)(param_1 + 0x18);
  local_6c[0] = 0;
  puVar9 = (undefined8 *)*param_2;
  if (((uint)*(undefined8 *)(lVar7 + 0x60) >> 8 & 1) == 0) {
    lVar2 = skb_recv_datagram(lVar7,param_4,local_6c);
    if (lVar2 != 0) {
      lock_sock_nested(lVar7,0);
      uVar8 = (ulong)*(int *)(lVar2 + 0x70);
      if (param_3 < uVar8) {
        uVar8 = param_3 & 0xffffffff;
        *(uint *)((long)param_2 + 0x44) = *(uint *)((long)param_2 + 0x44) | 0x20;
      }
      local_6c[0] = skb_copy_datagram_iter(lVar2,0,param_2 + 2,uVar8 & 0xffffffff);
      if ((-1 < local_6c[0]) && (local_6c[0] = (int)uVar8, puVar9 != (undefined8 *)0x0)) {
        *puVar9 = 0;
        *(undefined4 *)(puVar9 + 1) = 0;
        *(undefined2 *)puVar9 = 0x2a;
        *(undefined4 *)((long)puVar9 + 4) = *(undefined4 *)(lVar2 + 0x28);
        *(undefined4 *)(puVar9 + 1) = *(undefined4 *)(lVar2 + 0x2c);
        *(undefined4 *)(param_2 + 1) = 0xc;
      }
      if (*(char *)(lVar2 + 0x39) != '\0') {
        uStack_54 = *(undefined4 *)(lVar2 + 0x28);
        local_50 = *(undefined4 *)(lVar2 + 0x2c);
        local_6c[2] = *(undefined4 *)(lVar2 + 0x30);
        local_60 = *(undefined4 *)(lVar2 + 0x34);
        local_58 = 0x2a;
        local_6c[1] = 0x2a;
        lVar3 = qrtr_node_lookup();
        if (lVar3 != 0) {
          lVar4 = __alloc_skb(0x34,0xcc0,0,0xffffffff);
          if (lVar4 != 0) {
            *(long *)(lVar4 + 0xe0) = *(long *)(lVar4 + 0xe0) + 0x20;
            *(int *)(lVar4 + 0xd0) = *(int *)(lVar4 + 0xd0) + 0x20;
            puVar5 = (undefined4 *)skb_put(lVar4,0x14);
            *(undefined8 *)(puVar5 + 1) = 0;
            *(undefined8 *)(puVar5 + 3) = 0;
            *puVar5 = 7;
            puVar5[1] = *(undefined4 *)(lVar2 + 0x30);
            puVar5[2] = *(undefined4 *)(lVar2 + 0x34);
            qrtr_node_enqueue(lVar3,lVar4,7,local_6c + 1,&local_58,0);
          }
          qrtr_node_release(lVar3);
        }
      }
      skb_free_datagram(lVar7,lVar2);
      if (*(int *)(lVar7 + 0x360) == -2) {
        uVar6 = _raw_spin_lock_irqsave(lVar7 + 0x39c);
        if (*(char *)(lVar7 + 0x398) != '\0') {
          complete_all(lVar7 + 0x378);
          *(undefined1 *)(lVar7 + 0x398) = 0;
        }
        _raw_spin_unlock_irqrestore(lVar7 + 0x39c,uVar6);
      }
      release_sock(lVar7);
    }
    iVar1 = local_6c[0];
  }
  else {
    iVar1 = -99;
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// qrtr_port_remove @ 00104744 size=472
// signature: undefined qrtr_port_remove(void)
// callers: [qrtr_release, __qrtr_bind]
//------------------------------------------------------------

void qrtr_port_remove(long param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  bool bVar7;
  long lVar8;
  undefined4 *puVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  undefined8 uVar13;
  undefined4 local_58;
  undefined8 local_54;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  iVar3 = *(int *)(param_1 + 0x360);
  local_58 = 0x2a;
  lVar8 = __alloc_skb(0x34,0xcc0,0,0xffffffff);
  if (lVar8 != 0) {
    *(long *)(lVar8 + 0xe0) = *(long *)(lVar8 + 0xe0) + 0x20;
    *(int *)(lVar8 + 0xd0) = *(int *)(lVar8 + 0xd0) + 0x20;
    puVar9 = (undefined4 *)skb_put(lVar8,0x14);
    *(undefined8 *)(puVar9 + 1) = 0;
    *(undefined8 *)(puVar9 + 3) = 0;
    lVar1 = param_1 + 0x358;
    *puVar9 = 6;
    local_54 = 0xfffffffeffffffff;
    puVar9[1] = *(undefined4 *)(param_1 + 0x35c);
    puVar9[2] = *(undefined4 *)(param_1 + 0x360);
    skb_set_owner_w(lVar8,param_1);
    uVar4 = *(uint *)(param_1 + 0x370);
    uVar10 = (ulong)uVar4;
    if (uVar4 == 0xfffffffe) {
      qrtr_bcast_enqueue(0xfffffffe,lVar8,6,lVar1,&local_58,0);
    }
    else {
      if ((-1 < (int)uVar4) && (lVar11 = qrtr_node_lookup(), uVar10 = 0, lVar11 != 0)) {
        lVar12 = skb_clone(lVar8,0xcc0);
        if (lVar12 != 0) {
          skb_set_owner_w(lVar12,param_1);
          qrtr_node_enqueue(lVar11,lVar12,6,lVar1,&local_58,0);
        }
        uVar10 = qrtr_node_release(lVar11);
      }
      qrtr_local_enqueue(uVar10,lVar8,6,lVar1,&local_58);
    }
  }
  piVar2 = (int *)(param_1 + 0x80);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    iVar5 = *piVar2;
    cVar6 = '\x01';
    bVar7 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar7) {
      *piVar2 = iVar5 + -1;
      cVar6 = ExclusiveMonitorsStatus();
    }
  } while (cVar6 != '\0');
  if (iVar5 < 2) {
    refcount_warn_saturate(piVar2,4);
  }
  iVar5 = 0;
  if (iVar3 != -2) {
    iVar5 = iVar3;
  }
  uVar13 = _raw_spin_lock_irqsave(&qrtr_port_lock);
  xa_erase(qrtr_ports,(long)iVar5);
  _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar13);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_bcast_enqueue @ 00104930 size=260
// signature: undefined qrtr_bcast_enqueue(void)
// callers: [qrtr_port_remove]
//------------------------------------------------------------

undefined8
qrtr_bcast_enqueue(undefined8 param_1,long param_2,int param_3,undefined8 param_4,undefined8 param_5
                  ,undefined4 param_6)

{
  long lVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  
  down_read(qrtr_epts_lock);
  for (ppuVar3 = (undefined **)qrtr_all_epts; ppuVar3 != &qrtr_all_epts;
      ppuVar3 = (undefined **)*ppuVar3) {
    if ((param_3 == 2) || (*(int *)((long)ppuVar3 + -0x6c) != -1)) {
      lVar1 = __pskb_copy_fclone(param_2,*(int *)(param_2 + 0xe0) - *(int *)(param_2 + 0xd8),0xcc0,0
                                );
      if (lVar1 == 0) break;
      skb_set_owner_w(lVar1,*(undefined8 *)(param_2 + 0x18));
      qrtr_node_enqueue(ppuVar3 + -0x15,lVar1,param_3,param_4,param_5,param_6);
    }
  }
  uVar2 = up_read(qrtr_epts_lock);
  qrtr_local_enqueue(uVar2,param_2,param_3,param_4,param_5);
  return 0;
}



//------------------------------------------------------------
// __qrtr_bind @ 00104a34 size=800
// signature: undefined __qrtr_bind(void)
// callers: [qrtr_connect, qrtr_bind, qrtr_sendmsg]
//------------------------------------------------------------

int __qrtr_bind(long param_1,long param_2,int param_3)

{
  uint *puVar1;
  _STACK *p_Var2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  _STACK *p_Var9;
  long lVar10;
  undefined8 uVar11;
  long lVar12;
  int local_74;
  undefined8 local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0x18);
  if ((param_3 == 0) && (*(int *)(param_2 + 8) == *(int *)(lVar12 + 0x360))) {
    iVar6 = 0;
    goto LAB_00104d08;
  }
  uVar7 = _raw_spin_lock_irqsave(&qrtr_port_lock);
  local_74 = *(int *)(param_2 + 8);
  if (local_74 == 0) {
    _raw_spin_lock(qrtr_ports);
    iVar6 = __xa_alloc_cyclic(qrtr_ports,&local_74,lVar12,0x400000007fff,&qrtr_ports_next,0xa20);
LAB_00104b5c:
    _raw_spin_unlock(qrtr_ports);
    if (iVar6 == -0x10) {
      iVar6 = -0x62;
    }
    else if (-1 < iVar6) {
      puVar1 = (uint *)(lVar12 + 0x80);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar3 = *puVar1;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = uVar3 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      if (uVar3 == 0) {
        uVar11 = 2;
LAB_00104d6c:
        refcount_warn_saturate(puVar1,uVar11);
      }
      else if ((int)(uVar3 + 1 | uVar3) < 0) {
        uVar11 = 1;
        goto LAB_00104d6c;
      }
      if (local_74 == -2) {
        __rcu_read_lock();
        local_70 = 1;
        p_Var9 = (_STACK *)xa_find(qrtr_ports,&local_70,0xffffffffffffffff,8);
        if (p_Var9 != (_STACK *)0x0) {
          do {
            p_Var2 = p_Var9 + 4;
            Hint_Prefetch(p_Var2,2,0,1);
            do {
              uVar3 = p_Var2->num;
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(p_Var2,0x10);
              if (bVar5) {
                p_Var2->num = uVar3 + 1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            if (uVar3 == 0) {
              uVar11 = 2;
LAB_00104c8c:
              refcount_warn_saturate(p_Var2,uVar11);
            }
            else if ((int)(uVar3 + 1 | uVar3) < 0) {
              uVar11 = 1;
              goto LAB_00104c8c;
            }
            p_Var9[0x11].sorted = 0x66;
            sk_error_report(p_Var9);
            Hint_Prefetch(p_Var2,2,0,1);
            do {
              iVar6 = p_Var2->num;
              cVar4 = '\x01';
              bVar5 = (bool)ExclusiveMonitorPass(p_Var2,0x10);
              if (bVar5) {
                p_Var2->num = iVar6 + -1;
                cVar4 = ExclusiveMonitorsStatus();
              }
            } while (cVar4 != '\0');
            if (iVar6 == 1) {
              DataMemoryBarrier(2,1);
              sk_free(p_Var9);
            }
            else if (iVar6 < 1) {
              refcount_warn_saturate(p_Var2,3);
            }
            p_Var9 = (_STACK *)xa_find_after(qrtr_ports,&local_70,0xffffffffffffffff,8);
          } while (p_Var9 != (_STACK *)0x0);
        }
        __rcu_read_unlock();
      }
      _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar7);
      if (param_3 == 0) {
        qrtr_port_remove(lVar12);
      }
      iVar6 = 0;
      *(int *)(lVar12 + 0x360) = local_74;
      *(ulong *)(lVar12 + 0x60) = *(ulong *)(lVar12 + 0x60) & 0xfffffffffffffeff;
      goto LAB_00104d08;
    }
  }
  else {
    if (0x3fff < local_74) {
LAB_00104afc:
      lVar10 = (long)local_74;
      _raw_spin_lock(qrtr_ports);
LAB_00104b18:
      iVar6 = __xa_insert(qrtr_ports,lVar10,lVar12,0xa20);
      goto LAB_00104b5c;
    }
    uVar8 = capable(0xc);
    if ((((uVar8 & 1) != 0) || (iVar6 = in_egroup_p(0xb5a), iVar6 != 0)) ||
       (iVar6 = in_egroup_p(0), iVar6 != 0)) {
      if (local_74 != -2) goto LAB_00104afc;
      _raw_spin_lock(qrtr_ports);
      lVar10 = 0;
      goto LAB_00104b18;
    }
    iVar6 = -0xd;
  }
  _raw_spin_unlock_irqrestore(&qrtr_port_lock,uVar7);
LAB_00104d08:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qrtr_alloc_backup @ 00104d78 size=232
// signature: undefined qrtr_alloc_backup(void)
// callers: []
//------------------------------------------------------------

void qrtr_alloc_backup(void)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  while ((DAT_00108340 < 0x14 &&
         (lVar1 = alloc_skb_with_frags(0x20,0x400,0,&local_2c,0xcc0), lVar1 != 0))) {
    skb_queue_tail(&qrtr_backup_lo,lVar1);
  }
  while ((DAT_00108358 < 5 &&
         (lVar1 = alloc_skb_with_frags(0x20,0x4000,0,&local_2c,0xcc0), lVar1 != 0))) {
    skb_queue_tail(&qrtr_backup_hi,lVar1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __traceiter_qrtr_ns_service_announce_new @ 00104eb4 size=140
// signature: undefined __traceiter_qrtr_ns_service_announce_new(void)
// callers: []
//------------------------------------------------------------

undefined8
__traceiter_qrtr_ns_service_announce_new
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = DAT_00108f08;
  plVar2 = DAT_00108f08;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1be7c0c7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104f18);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_qrtr_ns_service_announce_del @ 00104f44 size=140
// signature: undefined __traceiter_qrtr_ns_service_announce_del(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qrtr_ns_service_announce_del
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108f50;
  plVar2 = _DAT_00108f50;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1be7c0c7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104fa8);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_qrtr_ns_server_add @ 00104fd4 size=140
// signature: undefined __traceiter_qrtr_ns_server_add(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qrtr_ns_server_add
          (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108f98;
  plVar2 = _DAT_00108f98;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x1be7c0c7) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4,param_5);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x105038);
  (*pcVar1)();
}



//------------------------------------------------------------
// __traceiter_qrtr_ns_message @ 00105064 size=124
// signature: undefined __traceiter_qrtr_ns_message(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
__traceiter_qrtr_ns_message
          (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  long *plVar2;
  long *plVar3;
  
  plVar3 = _DAT_00108fe0;
  plVar2 = _DAT_00108fe0;
  while( true ) {
    if (plVar2 == (long *)0x0) {
      return 0;
    }
    if (*(int *)((code *)*plVar3 + -4) != -0x4c44e7db) break;
    (*(code *)*plVar3)(plVar3[1],param_2,param_3,param_4);
    plVar3 = plVar3 + 3;
    plVar2 = (long *)*plVar3;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1050bc);
  (*pcVar1)();
}



//------------------------------------------------------------
// trace_event_raw_event_qrtr_ns_service_announce_new @ 001050e4 size=196
// signature: undefined trace_event_raw_event_qrtr_ns_service_announce_new(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qrtr_ns_service_announce_new
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qrtr_ns_service_announce_new @ 001051ac size=268
// signature: undefined perf_trace_qrtr_ns_service_announce_new(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qrtr_ns_service_announce_new
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qrtr_ns_service_announce_del @ 001052bc size=196
// signature: undefined trace_event_raw_event_qrtr_ns_service_announce_del(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qrtr_ns_service_announce_del
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qrtr_ns_service_announce_del @ 00105384 size=268
// signature: undefined perf_trace_qrtr_ns_service_announce_del(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qrtr_ns_service_announce_del
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qrtr_ns_server_add @ 00105494 size=196
// signature: undefined trace_event_raw_event_qrtr_ns_server_add(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qrtr_ns_server_add
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  if (((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
       (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
      (uVar2 = __trace_trigger_soft_disabled(param_1), (uVar2 & 1) == 0)) &&
     (lVar1 = trace_event_buffer_reserve(&local_68,param_1,0x18), lVar1 != 0)) {
    *(undefined4 *)(lVar1 + 8) = param_2;
    *(undefined4 *)(lVar1 + 0xc) = param_3;
    *(undefined4 *)(lVar1 + 0x10) = param_4;
    *(undefined4 *)(lVar1 + 0x14) = param_5;
    trace_event_buffer_commit(&local_68);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qrtr_ns_server_add @ 0010555c size=268
// signature: undefined perf_trace_qrtr_ns_server_add(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qrtr_ns_server_add
               (long param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  ulong unaff_x30;
  undefined1 auStack_70 [12];
  undefined4 local_64;
  long local_60;
  undefined8 local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  local_60 = 0;
  local_64 = 0;
  lVar3 = tpidr_el1;
  plVar1 = (long *)(lVar3 + *(long *)(param_1 + 0x78));
  if (((*(long *)(param_1 + 0x80) != 0) || (*plVar1 != 0)) &&
     (lVar3 = perf_trace_buf_alloc(0x1c,&local_60,&local_64), lVar3 != 0)) {
    *(undefined1 **)(local_60 + 0xe8) = auStack_70 + 0x20;
    uVar2 = unaff_x30 & 0xff80007fffffffff;
    if ((unaff_x30 & 0x80000000000000) != 0) {
      uVar2 = unaff_x30 | 0xffffff8000000000;
    }
    *(undefined1 **)(local_60 + 0xf8) = auStack_70;
    *(ulong *)(local_60 + 0x100) = uVar2;
    *(undefined8 *)(local_60 + 0x108) = 5;
    *(undefined4 *)(lVar3 + 8) = param_2;
    *(undefined4 *)(lVar3 + 0xc) = param_3;
    *(undefined4 *)(lVar3 + 0x10) = param_4;
    *(undefined4 *)(lVar3 + 0x14) = param_5;
    perf_trace_run_bpf_submit(lVar3,0x1c,local_64,param_1,1,local_60,plVar1,0);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// trace_event_raw_event_qrtr_ns_message @ 0010566c size=252
// signature: undefined trace_event_raw_event_qrtr_ns_message(void)
// callers: []
//------------------------------------------------------------

void trace_event_raw_event_qrtr_ns_message
               (long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if ((((*(ulong *)(param_1 + 0x48) & 0x2c0) == 0) ||
      (((uint)*(ulong *)(param_1 + 0x48) >> 8 & 1) != 0)) ||
     (uVar4 = __trace_trigger_soft_disabled(param_1), (uVar4 & 1) == 0)) {
    __s = "(null)";
    if (param_2 != (char *)0x0) {
      __s = param_2;
    }
    sVar2 = strlen(__s);
    iVar1 = (int)sVar2 + 1;
    lVar3 = trace_event_buffer_reserve(&local_78,param_1,(long)iVar1 + 0x14);
    if (lVar3 != 0) {
      *(uint *)(lVar3 + 8) = iVar1 * 0x10000 | 0x14;
      strcpy((char *)(lVar3 + 0x14),__s);
      *(undefined4 *)(lVar3 + 0xc) = param_3;
      *(undefined4 *)(lVar3 + 0x10) = param_4;
      trace_event_buffer_commit(&local_78);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// perf_trace_qrtr_ns_message @ 0010576c size=336
// signature: undefined perf_trace_qrtr_ns_message(void)
// callers: []
//------------------------------------------------------------

void perf_trace_qrtr_ns_message(long param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  long *plVar2;
  char *__s;
  ulong uVar3;
  size_t sVar4;
  long lVar5;
  ulong unaff_x30;
  undefined1 auStack_80 [12];
  undefined4 local_74;
  long local_70;
  undefined8 local_68;
  
  lVar5 = sp_el0;
  __s = "(null)";
  if (param_2 != (char *)0x0) {
    __s = param_2;
  }
  local_68 = *(long *)(lVar5 + 0x638);
  local_70 = 0;
  local_74 = 0;
  sVar4 = strlen(__s);
  lVar5 = tpidr_el1;
  plVar2 = (long *)(lVar5 + *(long *)(param_1 + 0x78));
  if ((*(long *)(param_1 + 0x80) != 0) || (*plVar2 != 0)) {
    iVar1 = ((uint)sVar4 & 0xfffffff8) + 0x1c;
    lVar5 = perf_trace_buf_alloc(iVar1,&local_70,&local_74);
    if (lVar5 != 0) {
      *(undefined1 **)(local_70 + 0xe8) = auStack_80 + 0x20;
      uVar3 = unaff_x30 & 0xff80007fffffffff;
      if ((unaff_x30 & 0x80000000000000) != 0) {
        uVar3 = unaff_x30 | 0xffffff8000000000;
      }
      *(undefined1 **)(local_70 + 0xf8) = auStack_80;
      *(ulong *)(local_70 + 0x100) = uVar3;
      *(undefined8 *)(local_70 + 0x108) = 5;
      *(uint *)(lVar5 + 8) = (uint)sVar4 * 0x10000 + 0x10014;
      strcpy((char *)(lVar5 + 0x14),__s);
      *(undefined4 *)(lVar5 + 0xc) = param_3;
      *(undefined4 *)(lVar5 + 0x10) = param_4;
      perf_trace_run_bpf_submit(lVar5,iVar1,local_74,param_1,1,local_70,plVar2,0);
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// __bpf_trace_qrtr_ns_service_announce_new @ 001058c0 size=44
// signature: undefined __bpf_trace_qrtr_ns_service_announce_new(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qrtr_ns_service_announce_new
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qrtr_ns_service_announce_del @ 001058f0 size=44
// signature: undefined __bpf_trace_qrtr_ns_service_announce_del(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qrtr_ns_service_announce_del
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qrtr_ns_server_add @ 00105920 size=44
// signature: undefined __bpf_trace_qrtr_ns_server_add(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qrtr_ns_server_add
               (undefined8 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5)

{
  bpf_trace_run4(param_1,param_2,param_3,param_4,param_5);
  return;
}



//------------------------------------------------------------
// __bpf_trace_qrtr_ns_message @ 00105950 size=36
// signature: undefined __bpf_trace_qrtr_ns_message(void)
// callers: []
//------------------------------------------------------------

void __bpf_trace_qrtr_ns_message
               (undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4)

{
  bpf_trace_run3(param_1,param_2,param_3,param_4);
  return;
}



//------------------------------------------------------------
// qrtr_get_service_id @ 00105978 size=204
// signature: undefined qrtr_get_service_id(void)
// callers: [qrtr_endpoint_post, qrtr_print_wakeup_reason]
//------------------------------------------------------------

void qrtr_get_service_id(int param_1,int param_2)

{
  undefined4 uVar1;
  long lVar2;
  undefined4 *puVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = xa_load(&nodes,param_1);
  if (lVar2 != 0) {
    local_40 = 0;
    puVar3 = (undefined4 *)xa_find(lVar2 + 8,&local_40,0xffffffffffffffff,8);
    while (puVar3 != (undefined4 *)0x0) {
      if ((puVar3[2] == param_1) && (puVar3[3] == param_2)) {
        uVar1 = *puVar3;
        goto LAB_001059dc;
      }
      puVar3 = (undefined4 *)xa_find_after(lVar2 + 8,&local_40,0xffffffffffffffff,8);
    }
  }
  uVar1 = 0xffffffea;
LAB_001059dc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// qrtr_ns_init @ 00105a48 size=700
// signature: undefined qrtr_ns_init(void)
// callers: [init_module]
//------------------------------------------------------------

int qrtr_ns_init(void)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined4 local_dc;
  undefined8 local_d8;
  undefined4 local_d0;
  undefined4 *local_c8;
  undefined8 uStack_c0;
  undefined2 *local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_d0 = 0;
  local_d8 = 0;
  local_dc = 0x7fffffff;
  DAT_001083d0 = &DAT_001083d0;
  DAT_001083d8 = &DAT_001083d0;
  __kthread_init_worker(&DAT_001083e0,"(&qrtr_ns.kworker)->lock",&qrtr_ns_init___key);
  DAT_00108430 = 0;
  DAT_00108438 = 0;
  DAT_00108418 = &DAT_00108418;
  DAT_00108420 = &DAT_00108418;
  DAT_00108428 = qrtr_ns_worker;
  ns_ilc = ipc_log_context_create(4,"qrtr_ns",0);
  iVar2 = sock_create_kern(&init_net,0x2a,2,0x2a,&qrtr_ns);
  if (-1 < iVar2) {
    iVar2 = kernel_getsockname(qrtr_ns,&local_d8);
    if (iVar2 < 0) {
      _printk(&DAT_00108cc5,"qrtr_ns_init");
    }
    else {
      uVar3 = kthread_create_on_node(&kthread_worker_fn,&DAT_001083e0,0xffffffff,"qrtr_ns");
      if (uVar3 < 0xfffffffffffff001) {
        wake_up_process(uVar3);
        lVar1 = qrtr_ns;
        local_d0 = 0xfffffffe;
        DAT_00108440 = uVar3;
        *(code **)(*(long *)(qrtr_ns + 0x18) + 0x2b8) = qrtr_ns_data_ready;
        DAT_00108448 = local_d8._4_4_;
        iVar2 = kernel_bind(lVar1,&local_d8,0xc);
        if (iVar2 < 0) {
          _printk(&DAT_00108879,"qrtr_ns_init");
        }
        else {
          sock_setsockopt(qrtr_ns,1,8,&local_dc,1,4);
          DAT_001083c0 = 0x2a;
          DAT_001083c4 = 0xfffffffeffffffff;
          local_c8 = &local_50;
          local_58 = 0;
          local_68 = 0;
          uStack_60 = 0;
          uStack_c0 = 0x14;
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_4c = 0;
          local_44 = 0;
          local_50 = 2;
          local_b8 = &DAT_001083c0;
          local_b0 = 0xc;
          iVar2 = kernel_sendmsg(qrtr_ns,&local_b8,&local_c8,1,0x14);
          if (-1 < iVar2) {
            module_put(*(undefined8 *)(*(long *)(qrtr_ns + 0x20) + 8));
            module_put(*(undefined8 *)(*(long *)(*(long *)(qrtr_ns + 0x18) + 0x220) + 0x180));
            iVar2 = 0;
            goto LAB_00105cd0;
          }
          _printk(&DAT_00108477,"say_hello",iVar2);
        }
        kthread_stop(DAT_00108440);
      }
      else {
        DAT_00108440 = uVar3;
        _printk(&DAT_00108be2,"qrtr_ns_init",uVar3);
      }
    }
    sock_release(qrtr_ns);
  }
LAB_00105cd0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qrtr_ns_worker @ 00105d08 size=3764
// signature: undefined qrtr_ns_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qrtr_ns_worker(void)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  long *plVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  uint *puVar13;
  long lVar14;
  uint *puVar15;
  ulong uVar16;
  undefined *puVar17;
  undefined4 *puVar18;
  char *pcVar19;
  undefined8 *puVar20;
  long *plVar21;
  long *plVar22;
  uint *local_1a0;
  undefined8 uStack_198;
  undefined8 *local_190;
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
  undefined8 local_128;
  uint local_120 [2];
  undefined8 local_118;
  undefined4 local_110;
  undefined8 local_108;
  undefined8 *local_100;
  undefined8 local_f8;
  long *local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
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
  undefined8 local_88;
  uint local_80;
  uint uStack_7c;
  uint uStack_78;
  long local_70;
  
  lVar14 = sp_el0;
  local_70 = *(long *)(lVar14 + 0x638);
  local_190 = &local_128;
  local_120[0] = 0;
  local_130 = 0;
  local_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_188 = 0xc;
  local_160 = 0;
  uStack_158 = 0;
  local_170 = 0;
  uStack_168 = 0;
  local_180 = 0;
  uStack_178 = 0;
  puVar11 = (uint *)kmalloc_trace(_down_write,0xdc0,0x1000);
  if (puVar11 != (uint *)0x0) {
    uStack_198 = 0x1000;
    local_1a0 = puVar11;
    iVar8 = kernel_recvmsg(qrtr_ns,&local_190,&local_1a0,1,0x1000,0x40);
    if (iVar8 != -0xb) {
      puVar20 = (undefined8 *)((ulong)&local_88 | 4);
      uVar7 = sp_el0;
      do {
        if (iVar8 < 0) {
          _printk(&DAT_00108537,"qrtr_ns_worker",(long)iVar8);
          break;
        }
        uVar5 = *puVar11;
        uVar6 = uVar5;
        if (uVar5 < 0xc) {
          uVar6 = *puVar11;
        }
        uVar2 = uVar6 & 0xfffffffe;
        if (uVar2 == 2) {
          ipc_log_string(ns_ilc,"cmd:0x%x node[0x%x]\n",uVar6,local_128._4_4_);
        }
        else {
          if (uVar6 == 6) {
            uVar2 = puVar11[1];
            uVar3 = puVar11[2];
            pcVar19 = "cmd:0x%x addr[0x%x:0x%x]\n";
          }
          else {
            if (uVar2 != 10) {
              if (uVar2 == 4) {
                ipc_log_string(ns_ilc,"cmd:0x%x SVC[0x%x:0x%x] addr[0x%x:0x%x]\n",uVar6,puVar11[1],
                               puVar11[2],puVar11[3],puVar11[4]);
              }
              goto LAB_00105f38;
            }
            pcVar19 = "cmd:0x%x SVC[0x%x:0x%x]\n";
            uVar2 = puVar11[1];
            uVar3 = puVar11[2];
          }
          ipc_log_string(ns_ilc,pcVar19,uVar6,uVar2,uVar3);
        }
LAB_00105f38:
        uVar7 = qrtr_ns;
        uVar6 = local_128._4_4_;
        lVar14 = local_128;
        switch(uVar5) {
        case 2:
          local_100 = &local_88;
          local_98 = 0;
          uStack_90 = 0;
          local_a8 = 0;
          uStack_a0 = 0;
          local_88 = CONCAT44(local_88._4_4_,2);
          local_b8 = 0;
          uStack_b0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          local_f0 = &local_128;
          local_d8 = 0;
          uStack_d0 = 0;
          uStack_e0 = 0;
          local_f8 = 0x14;
          *puVar20 = 0;
          puVar20[1] = 0;
          local_e8 = 0xc;
          iVar8 = kernel_sendmsg(uVar7,&local_f0,&local_100,1,0x14);
          if (iVar8 < 0) {
            puVar17 = &DAT_00108477;
            pcVar19 = "say_hello";
LAB_00106b54:
            _printk(puVar17,pcVar19,iVar8);
            goto LAB_00106b80;
          }
          local_f0 = (long *)0x0;
          local_88 = 0;
          piVar12 = (int *)xa_find(&nodes,&local_88,0xffffffffffffffff,8);
          lVar14 = local_128;
          while (piVar12 != (int *)0x0) {
            local_128._4_4_ = (uint)((ulong)lVar14 >> 0x20);
            local_128 = lVar14;
            if (*piVar12 == local_128._4_4_) {
              _printk(&DAT_0010882b,"announce_servers");
            }
            else {
              local_f0 = (long *)0x0;
              lVar14 = xa_find(piVar12 + 2,&local_f0,0xffffffffffffffff,8);
              if (lVar14 != 0) {
                do {
                  iVar8 = service_announce_new(&local_128,lVar14);
                  if ((iVar8 < 0) && (iVar8 != -0x13)) {
                    _printk(&DAT_00108b37,"announce_servers",iVar8);
                    goto LAB_00106828;
                  }
                  lVar14 = xa_find_after(piVar12 + 2,&local_f0,0xffffffffffffffff,8);
                } while (lVar14 != 0);
              }
            }
            piVar12 = (int *)xa_find_after(&nodes,&local_88,0xffffffffffffffff,8);
            lVar14 = local_128;
          }
          break;
        case 3:
          local_100 = &local_88;
          uStack_78 = 0;
          local_88 = 0;
          local_80 = 0;
          uStack_7c = 0;
          local_110 = 0;
          local_118 = 0;
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
          local_e8 = 0;
          uStack_e0 = 0;
          local_f8 = 0x14;
          local_f0 = (long *)0x0;
          puVar15 = (uint *)xa_load(&nodes,local_128._4_4_);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
            lVar14 = local_128;
            if (puVar15 == (uint *)0x0) break;
            *puVar15 = uVar6;
            puVar15[2] = 0;
            puVar15[3] = 0;
            puVar15[4] = 0;
            puVar15[5] = 0;
            xa_store(&nodes,uVar6,puVar15,0xa20);
          }
          local_108 = 0;
          lVar14 = xa_find(puVar15 + 2,&local_108,0xffffffffffffffff,8);
          uVar5 = DAT_00108448;
          while (DAT_00108448 = uVar5, lVar14 != 0) {
            server_del(puVar15,*(undefined4 *)(lVar14 + 0xc),1);
            lVar14 = xa_find_after(puVar15 + 2,&local_108,0xffffffffffffffff,8);
            uVar5 = DAT_00108448;
          }
          puVar15 = (uint *)xa_load(&nodes,uVar5);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
            lVar14 = local_128;
            if (puVar15 == (uint *)0x0) break;
            *puVar15 = uVar5;
            puVar15[2] = 0;
            puVar15[3] = 0;
            puVar15[4] = 0;
            puVar15[5] = 0;
            xa_store(&nodes,uVar5,puVar15,0xa20);
          }
          uStack_78 = 0;
          local_80 = 0;
          uStack_7c = 0;
          local_108 = 0;
          local_88 = CONCAT44(local_128._4_4_,3);
          puVar18 = (undefined4 *)xa_find(puVar15 + 2,&local_108,0xffffffffffffffff,8);
          lVar14 = local_128;
          if (puVar18 != (undefined4 *)0x0) {
            do {
              local_110 = puVar18[3];
              local_118 = CONCAT62(local_118._2_6_,0x2a);
              local_118 = CONCAT44(puVar18[2],(undefined4)local_118);
              local_e8 = CONCAT44(local_e8._4_4_,0xc);
              local_f0 = &local_118;
              iVar8 = kernel_sendmsg(qrtr_ns,&local_f0,&local_100,1,0x14);
              if (((iVar8 < 0) && (iVar8 != -0x13)) &&
                 (iVar9 = ___ratelimit(ctrl_cmd_bye__rs,"ctrl_cmd_bye"), iVar9 != 0)) {
                _printk(&DAT_00108c13,"ctrl_cmd_bye",*puVar18,puVar18[1],puVar18[3],iVar8);
              }
              puVar18 = (undefined4 *)xa_find_after(puVar15 + 2,&local_108,0xffffffffffffffff,8);
              lVar14 = local_128;
            } while (puVar18 != (undefined4 *)0x0);
          }
          break;
        case 4:
          uVar6 = puVar11[1];
          uVar5 = local_128._4_4_;
          puVar15 = local_120;
          if (local_128._4_4_ != DAT_00108448) {
            uVar5 = puVar11[3];
            puVar15 = puVar11 + 4;
          }
          if ((uVar6 != 0) && (uVar2 = *puVar15, uVar2 != 0)) {
            uVar3 = puVar11[2];
            puVar15 = (uint *)kmalloc_trace(_kfree,0xdc0,0x20);
            if (puVar15 != (uint *)0x0) {
              *puVar15 = uVar6;
              puVar15[1] = uVar3;
              puVar15[2] = uVar5;
              puVar15[3] = uVar2;
              puVar13 = (uint *)xa_load(&nodes,uVar5);
              if (puVar13 != (uint *)0x0) {
LAB_001065cc:
                uVar16 = xa_store(puVar13 + 2,uVar2,puVar15,0xcc0);
                if (uVar16 != 0) {
                  if ((0xffffffffffffc005 < uVar16) && ((uVar16 & 3) == 2)) {
                    _printk(&DAT_0010867e,"server_add",*puVar15,puVar15[1],uVar16 >> 2);
                    goto LAB_00106b78;
                  }
                  kfree();
                }
                ipc_log_string(ns_ilc,"%s: [0x%x:0x%x]@[0x%x:0x%x]\n","server_add",*puVar15,
                               puVar15[1],puVar15[2],puVar15[3]);
                if (puVar15[2] == DAT_00108448) {
                  iVar8 = service_announce_new(&DAT_001083c0,puVar15);
                  if (iVar8 < 0) {
                    puVar17 = &DAT_00108b37;
                    pcVar19 = "ctrl_cmd_new_server";
                    goto LAB_00106b54;
                  }
                }
                else {
                  iVar8 = 0;
                }
                plVar21 = DAT_001083d0;
                lVar14 = local_128;
                if ((long **)DAT_001083d0 != &DAT_001083d0) {
                  do {
                    if (((*(uint *)(plVar21 + -3) == 0) || (*(uint *)(plVar21 + -3) == uVar6)) &&
                       ((*(uint *)((long)plVar21 + -0x14) == 0 ||
                        (*(uint *)((long)plVar21 + -0x14) == uVar3)))) {
                      local_80 = puVar15[1];
                      local_98 = 0;
                      uStack_90 = 0;
                      local_88 = CONCAT44(*puVar15,4);
                      uStack_7c = puVar15[2];
                      uStack_78 = puVar15[3];
                      local_a8 = 0;
                      uStack_a0 = 0;
                      local_b8 = 0;
                      uStack_b0 = 0;
                      local_c8 = 0;
                      uStack_c0 = 0;
                      local_f0 = plVar21 + -2;
                      local_d8 = 0;
                      uStack_d0 = 0;
                      uStack_e0 = 0;
                      local_f8 = 0x14;
                      local_e8 = 0xc;
                      local_100 = &local_88;
                      iVar9 = kernel_sendmsg(qrtr_ns,&local_f0,&local_100,1,0x14);
                      if (((iVar9 < 0) && (iVar9 != -0x13)) &&
                         (iVar10 = ___ratelimit(lookup_notify__rs,"lookup_notify"), iVar10 != 0)) {
                        _printk(&DAT_001086d1,"lookup_notify",iVar9);
                      }
                    }
                    plVar21 = (long *)*plVar21;
                  } while ((long **)plVar21 != &DAT_001083d0);
LAB_00106828:
                  lVar14 = local_128;
                  if (iVar8 < 0) goto LAB_00106b80;
                }
                break;
              }
              puVar13 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
              if (puVar13 != (uint *)0x0) {
                *puVar13 = uVar5;
                puVar13[2] = 0;
                puVar13[3] = 0;
                puVar13[4] = 0;
                puVar13[5] = 0;
                xa_store(&nodes,uVar5,puVar13,0xa20);
                goto LAB_001065cc;
              }
LAB_00106b78:
              kfree(puVar15);
            }
          }
          goto LAB_00106b80;
        case 5:
          uVar5 = local_128._4_4_;
          puVar15 = local_120;
          if (local_128._4_4_ != DAT_00108448) {
            uVar5 = puVar11[3];
            puVar15 = puVar11 + 4;
          }
          uVar6 = *puVar15;
          puVar15 = (uint *)xa_load(&nodes,uVar5);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
            if (puVar15 == (uint *)0x0) goto LAB_00106b80;
            *puVar15 = uVar5;
            puVar15[2] = 0;
            puVar15[3] = 0;
            puVar15[4] = 0;
            puVar15[5] = 0;
            xa_store(&nodes,uVar5,puVar15,0xa20);
          }
          server_del(puVar15,uVar6,1);
          lVar14 = local_128;
          break;
        case 6:
          uStack_78 = 0;
          local_88 = 0;
          local_80 = 0;
          uStack_7c = 0;
          local_98 = 0;
          uStack_90 = 0;
          uVar5 = puVar11[1];
          uVar6 = puVar11[2];
          local_a8 = 0;
          uStack_a0 = 0;
          local_100 = &local_88;
          local_b8 = 0;
          uStack_b0 = 0;
          local_c8 = 0;
          uStack_c0 = 0;
          local_d8 = 0;
          uStack_d0 = 0;
          local_e8 = 0;
          uStack_e0 = 0;
          local_110 = 0;
          local_118 = 0;
          local_f8 = 0x14;
          local_f0 = (long *)0x0;
          plVar21 = DAT_001083d0;
          if ((local_128._4_4_ == DAT_00108448) && (local_120[0] != uVar6)) goto LAB_00106b80;
          while (plVar22 = plVar21, (long **)plVar22 != &DAT_001083d0) {
            plVar21 = (long *)*plVar22;
            if ((*(uint *)((long)plVar22 + -0xc) == uVar5) && (*(uint *)(plVar22 + -1) == uVar6)) {
              uVar16 = __list_del_entry_valid(plVar22);
              if ((uVar16 & 1) != 0) {
                lVar14 = *plVar22;
                plVar4 = (long *)plVar22[1];
                *(long **)(lVar14 + 8) = plVar4;
                *plVar4 = lVar14;
              }
              *plVar22 = -0x2152ffffffffff00;
              plVar22[1] = -0x2152fffffffffede;
              kfree(plVar22 + -3);
            }
          }
          puVar15 = (uint *)xa_load(&nodes,uVar5);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
            if (puVar15 != (uint *)0x0) {
              *puVar15 = uVar5;
              puVar15[2] = 0;
              puVar15[3] = 0;
              puVar15[4] = 0;
              puVar15[5] = 0;
              xa_store(&nodes,uVar5,puVar15,0xa20);
              goto LAB_00106894;
            }
          }
          else {
LAB_00106894:
            server_del(puVar15,uVar6,0);
          }
          uVar2 = DAT_00108448;
          puVar15 = (uint *)xa_load(&nodes,DAT_00108448);
          if (puVar15 == (uint *)0x0) {
            puVar15 = (uint *)kmalloc_trace(_kfree,0xb20,0x18);
            lVar14 = local_128;
            if (puVar15 == (uint *)0x0) break;
            *puVar15 = uVar2;
            puVar15[2] = 0;
            puVar15[3] = 0;
            puVar15[4] = 0;
            puVar15[5] = 0;
            xa_store(&nodes,uVar2,puVar15,0xa20);
          }
          uStack_7c = 0;
          uStack_78 = 0;
          local_88 = CONCAT44(uVar5,6);
          local_108 = 0;
          local_80 = uVar6;
          puVar18 = (undefined4 *)xa_find(puVar15 + 2,&local_108,0xffffffffffffffff,8);
          lVar14 = local_128;
          if (puVar18 != (undefined4 *)0x0) {
            do {
              local_f0 = &local_118;
              local_118 = CONCAT62(local_118._2_6_,0x2a);
              local_110 = puVar18[3];
              local_118 = CONCAT44(puVar18[2],(undefined4)local_118);
              local_e8 = CONCAT44(local_e8._4_4_,0xc);
              iVar8 = kernel_sendmsg(qrtr_ns,&local_f0,&local_100,1,0x14);
              if (((iVar8 < 0) && (iVar8 != -0x13)) &&
                 (iVar9 = ___ratelimit(ctrl_cmd_del_client__rs,"ctrl_cmd_del_client"), iVar9 != 0))
              {
                _printk(&DAT_001084da,"ctrl_cmd_del_client",*puVar18,puVar18[1],puVar18[3],iVar8);
              }
              puVar18 = (undefined4 *)xa_find_after(puVar15 + 2,&local_108,0xffffffffffffffff,8);
              lVar14 = local_128;
            } while (puVar18 != (undefined4 *)0x0);
          }
          break;
        case 10:
          local_108 = 0;
          uVar5 = puVar11[1];
          uVar6 = puVar11[2];
          if (local_128._4_4_ == DAT_00108448) {
            puVar13 = (uint *)kmalloc_trace(_kfree,0xdc0,0x28);
            puVar15 = DAT_001083d8;
            if (puVar13 != (uint *)0x0) {
              puVar1 = puVar13 + 6;
              *puVar13 = uVar5;
              puVar13[1] = uVar6;
              *(long *)(puVar13 + 2) = local_128;
              puVar13[4] = local_120[0];
              uVar16 = __list_add_valid(puVar1,puVar15);
              if ((uVar16 & 1) != 0) {
                DAT_001083d8 = puVar1;
                *(long ***)(puVar13 + 6) = &DAT_001083d0;
                *(uint **)(puVar13 + 8) = puVar15;
                *(uint **)puVar15 = puVar1;
              }
              local_118 = 0;
              lVar14 = xa_find(&nodes,&local_118,0xffffffffffffffff,8);
              uVar7 = qrtr_ns;
              while (qrtr_ns = uVar7, lVar14 != 0) {
                local_108 = 0;
                puVar15 = (uint *)xa_find(lVar14 + 8,&local_108,0xffffffffffffffff,8);
                while (puVar15 != (uint *)0x0) {
                  if (((uVar5 == 0) || (*puVar15 == uVar5)) &&
                     ((uVar6 == 0 || (puVar15[1] == uVar6)))) {
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
                    uStack_e0 = 0;
                    local_f8 = 0x14;
                    *puVar20 = 0;
                    puVar20[1] = 0;
                    local_88 = CONCAT44(*puVar15,4);
                    local_80 = puVar15[1];
                    uStack_7c = puVar15[2];
                    uStack_78 = puVar15[3];
                    local_e8 = 0xc;
                    local_100 = &local_88;
                    local_f0 = &local_128;
                    iVar8 = kernel_sendmsg(qrtr_ns,&local_f0,&local_100,1,0x14);
                    if (((iVar8 < 0) && (iVar8 != -0x13)) &&
                       (iVar9 = ___ratelimit(lookup_notify__rs,"lookup_notify"), iVar9 != 0)) {
                      _printk(&DAT_001086d1,"lookup_notify",iVar8);
                    }
                  }
                  puVar15 = (uint *)xa_find_after(lVar14 + 8,&local_108,0xffffffffffffffff,8);
                }
                lVar14 = xa_find_after(&nodes,&local_118,0xffffffffffffffff,8);
                uVar7 = qrtr_ns;
              }
              local_88._4_4_ = (undefined4)((ulong)local_88 >> 0x20);
              local_88 = CONCAT44(local_88._4_4_,4);
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
              uStack_e0 = 0;
              local_f8 = 0x14;
              *puVar20 = 0;
              puVar20[1] = 0;
              local_e8 = 0xc;
              local_100 = &local_88;
              local_f0 = &local_128;
              iVar8 = kernel_sendmsg(uVar7,&local_f0,&local_100,1,0x14);
              lVar14 = local_128;
              if ((iVar8 < 0) && (iVar8 != -0x13)) {
                iVar9 = ___ratelimit(lookup_notify__rs,"lookup_notify");
                lVar14 = local_128;
                if (iVar9 != 0) {
                  _printk(&DAT_001086d1,"lookup_notify",iVar8);
                  lVar14 = local_128;
                }
              }
              break;
            }
          }
LAB_00106b80:
          _printk(&DAT_00108784,"qrtr_ns_worker",local_128._4_4_,local_120[0]);
          lVar14 = local_128;
          break;
        case 0xb:
          if ((long **)DAT_001083d0 != &DAT_001083d0) {
            uVar5 = puVar11[1];
            uVar6 = puVar11[2];
            plVar21 = DAT_001083d0;
            do {
              plVar22 = (long *)*plVar21;
              if ((((*(int *)((long)plVar21 + -0xc) == local_128._4_4_) &&
                   (*(uint *)(plVar21 + -1) == local_120[0])) && (*(uint *)(plVar21 + -3) == uVar5))
                 && ((*(uint *)((long)plVar21 + -0x14) == 0 ||
                     (*(uint *)((long)plVar21 + -0x14) == uVar6)))) {
                uVar16 = __list_del_entry_valid(plVar21);
                if ((uVar16 & 1) != 0) {
                  lVar14 = *plVar21;
                  plVar4 = (long *)plVar21[1];
                  *(long **)(lVar14 + 8) = plVar4;
                  *plVar4 = lVar14;
                }
                *plVar21 = -0x2152ffffffffff00;
                plVar21[1] = -0x2152fffffffffede;
                kfree(plVar21 + -3);
              }
              plVar21 = plVar22;
              lVar14 = local_128;
            } while ((long **)plVar22 != &DAT_001083d0);
          }
        }
        local_128 = lVar14;
        uStack_198 = 0x1000;
        local_1a0 = puVar11;
        iVar8 = kernel_recvmsg(qrtr_ns,&local_190,&local_1a0,1,0x1000,0x40);
      } while (iVar8 != -0xb);
    }
    kfree(puVar11);
  }
  lVar14 = sp_el0;
  if (*(long *)(lVar14 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qrtr_ns_data_ready @ 00106d28 size=40
// signature: undefined qrtr_ns_data_ready(void)
// callers: []
//------------------------------------------------------------

void qrtr_ns_data_ready(void)

{
  kthread_queue_work(&DAT_001083e0,&DAT_00108418);
  return;
}



//------------------------------------------------------------
// qrtr_ns_remove @ 00106d54 size=100
// signature: undefined qrtr_ns_remove(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void qrtr_ns_remove(void)

{
  kthread_flush_worker(&DAT_001083e0);
  kthread_stop(DAT_00108440);
  __module_get(*(undefined8 *)(*(long *)(qrtr_ns + 0x20) + 8));
  __module_get(*(undefined8 *)(*(long *)(*(long *)(qrtr_ns + 0x18) + 0x220) + 0x180));
  sock_release(qrtr_ns);
  return;
}



//------------------------------------------------------------
// trace_raw_output_qrtr_ns_service_announce_new @ 00106dbc size=104
// signature: undefined trace_raw_output_qrtr_ns_service_announce_new(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qrtr_ns_service_announce_new
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"advertising new server [%d:%x]@[%d:%d]\n",*(undefined4 *)(lVar2 + 8)
                       ,*(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qrtr_ns_service_announce_del @ 00106e28 size=104
// signature: undefined trace_raw_output_qrtr_ns_service_announce_del(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qrtr_ns_service_announce_del
               (long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"advertising removal of server [%d:%x]@[%d:%d]\n",
                       *(undefined4 *)(lVar2 + 8),*(undefined4 *)(lVar2 + 0xc),
                       *(undefined4 *)(lVar2 + 0x10),*(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qrtr_ns_server_add @ 00106e94 size=104
// signature: undefined trace_raw_output_qrtr_ns_server_add(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qrtr_ns_server_add(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"add server [%d:%x]@[%d:%d]\n",*(undefined4 *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10),
                       *(undefined4 *)(lVar2 + 0x14));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// trace_raw_output_qrtr_ns_message @ 00106f00 size=108
// signature: undefined trace_raw_output_qrtr_ns_message(void)
// callers: []
//------------------------------------------------------------

void trace_raw_output_qrtr_ns_message(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x20f0);
  iVar1 = trace_raw_output_prep(param_1,param_3);
  if (iVar1 == 1) {
    trace_event_printf(param_1,"%s from %d:%d\n",lVar2 + (ulong)*(ushort *)(lVar2 + 8),
                       *(undefined4 *)(lVar2 + 0xc),*(undefined4 *)(lVar2 + 0x10));
    trace_handle_return(param_1 + 0x10c8);
  }
  return;
}



//------------------------------------------------------------
// service_announce_new @ 00106f6c size=244
// signature: undefined service_announce_new(void)
// callers: [qrtr_ns_worker]
//------------------------------------------------------------

void service_announce_new(undefined8 param_1,undefined4 *param_2)

{
  long lVar1;
  undefined4 *local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined4 uStack_4c;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  ipc_log_string(ns_ilc,"%s: [0x%x:0x%x]@[0x%x:0x%x]\n","service_announce_new",*param_2,param_2[1],
                 param_2[2],param_2[3]);
  local_c8 = &local_50;
  uStack_4c = *param_2;
  local_48 = *(undefined8 *)(param_2 + 1);
  uStack_c0 = 0x14;
  local_40 = param_2[3];
  local_50 = 4;
  local_b0 = CONCAT44(local_b0._4_4_,0xc);
  local_b8 = param_1;
  kernel_sendmsg(qrtr_ns,&local_b8,&local_c8,1,0x14);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// server_del @ 00107104 size=692
// signature: undefined server_del(void)
// callers: [qrtr_ns_worker]
//------------------------------------------------------------

void server_del(long param_1,undefined4 param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined8 *puVar5;
  undefined4 *local_f8;
  undefined8 uStack_f0;
  long *local_e8;
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
  undefined4 local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  piVar4 = (int *)xa_load(param_1 + 8,param_2);
  if (piVar4 != (int *)0x0) {
    xa_erase(param_1 + 8,param_2);
    if ((piVar4[2] == DAT_00108448) && ((param_3 & 1) != 0)) {
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
      ipc_log_string(ns_ilc,"%s: [0x%x:0x%x]@[0x%x:0x%x]\n","service_announce_del",*piVar4,piVar4[1]
                     ,piVar4[2],piVar4[3]);
      local_f8 = &local_80;
      uStack_f0 = 0x14;
      local_80 = 5;
      local_7c = *piVar4;
      local_78 = piVar4[1];
      local_e8 = (long *)&DAT_001083c0;
      local_74 = piVar4[2];
      local_70 = piVar4[3];
      local_e0 = CONCAT44(local_e0._4_4_,0xc);
      iVar2 = kernel_sendmsg(qrtr_ns,&local_e8,&local_f8,1,0x14);
      if ((iVar2 < 0) &&
         ((iVar2 != -0x13 &&
          (iVar3 = ___ratelimit(service_announce_del__rs,"service_announce_del"), iVar3 != 0)))) {
        _printk(&DAT_00108ba4,"service_announce_del",iVar2);
      }
    }
    if ((undefined8 **)DAT_001083d0 != &DAT_001083d0) {
      puVar5 = DAT_001083d0;
      do {
        if (((*(int *)(puVar5 + -3) == 0) || (*(int *)(puVar5 + -3) == *piVar4)) &&
           ((*(int *)((long)puVar5 + -0x14) == 0 || (*(int *)((long)puVar5 + -0x14) == piVar4[1]))))
        {
          local_90 = 0;
          uStack_88 = 0;
          local_e8 = puVar5 + -2;
          local_a0 = 0;
          uStack_98 = 0;
          local_b0 = 0;
          uStack_a8 = 0;
          local_c0 = 0;
          uStack_b8 = 0;
          local_d0 = 0;
          uStack_c8 = 0;
          uStack_d8 = 0;
          uStack_f0 = 0x14;
          local_80 = 5;
          local_7c = *piVar4;
          local_78 = piVar4[1];
          local_74 = piVar4[2];
          local_e0 = 0xc;
          local_70 = piVar4[3];
          local_f8 = &local_80;
          iVar2 = kernel_sendmsg(qrtr_ns,&local_e8,&local_f8,1,0x14);
          if (((iVar2 < 0) && (iVar2 != -0x13)) &&
             (iVar3 = ___ratelimit(lookup_notify__rs,"lookup_notify"), iVar3 != 0)) {
            _printk(&DAT_001086d1,"lookup_notify",iVar2);
          }
        }
        puVar5 = (undefined8 *)*puVar5;
      } while ((undefined8 **)puVar5 != &DAT_001083d0);
    }
    kfree(piVar4);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00107704 size=368
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  lVar3 = 0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  do {
    lVar3 = of_find_compatible_node(lVar3,0,"qcom,qrtr");
    if (lVar3 == 0) goto LAB_0010777c;
    iVar2 = of_property_read_variable_u32_array(lVar3,"qcom,node-id",&local_3c,1,0);
  } while (iVar2 < 0);
  qrtr_local_nid = local_3c;
LAB_0010777c:
  qrtr_local_ilc = ipc_log_context_create(4,"qrtr_local",0);
  iVar2 = proto_register(qrtr_proto,1);
  if (iVar2 == 0) {
    iVar2 = sock_register(qrtr_family);
    if (iVar2 == 0) {
      iVar2 = qrtr_ns_init();
      if (iVar2 == 0) {
        qrtr_backup_lo = &qrtr_backup_lo;
        DAT_00108338 = &qrtr_backup_lo;
        _DAT_00108340 = 0;
        qrtr_backup_work = 0xfffffffe0;
        qrtr_backup_hi = &qrtr_backup_hi;
        DAT_00108350 = &qrtr_backup_hi;
        _DAT_00108358 = 0;
        DAT_00108368 = &DAT_00108368;
        DAT_00108370 = &DAT_00108368;
        DAT_00108378 = qrtr_alloc_backup;
        queue_work_on(0x20,_system_unbound_wq);
        goto LAB_001077e4;
      }
      sock_unregister(0x2a);
    }
    proto_unregister(qrtr_proto);
  }
LAB_001077e4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// cleanup_module @ 00107878 size=84
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  qrtr_ns_remove();
  sock_unregister(0x2a);
  proto_unregister(qrtr_proto);
  cancel_work_sync(&qrtr_backup_work);
  skb_queue_purge(&qrtr_backup_lo);
  skb_queue_purge(&qrtr_backup_hi);
  return;
}



//------------------------------------------------------------
// memcpy @ 0010c000 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qrtr_print_wakeup_reason]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010c008 size=1
// signature: undefined _printk(void)
// callers: [qrtr_endpoint_post, qrtr_ns_worker, qrtr_node_rx_work, qrtr_node_enqueue, qrtr_peek_pkt_size, qrtr_print_wakeup_reason, qrtr_ns_init, server_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010c010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [perf_trace_qrtr_ns_service_announce_del, qrtr_connect, qrtr_node_rx_work, qrtr_node_enqueue, qrtr_alloc_backup, qrtr_recvmsg, qrtr_node_release, qrtr_port_remove, perf_trace_qrtr_ns_server_add, trace_event_raw_event_qrtr_ns_message, qrtr_endpoint_unregister, perf_trace_qrtr_ns_message, qrtr_get_service_id, qrtr_endpoint_post, qrtr_hello_work, qrtr_endpoint_register, qrtr_getname, qrtr_sendmsg, qrtr_ns_init, trace_event_raw_event_qrtr_ns_server_add, trace_event_raw_event_qrtr_ns_service_announce_new, trace_event_raw_event_qrtr_ns_service_announce_del, qrtr_ns_worker, service_announce_new, qrtr_print_wakeup_reason, perf_trace_qrtr_ns_service_announce_new, server_del, __qrtr_bind, qrtr_ioctl, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_skb_with_frags @ 0010c018 size=1
// signature: undefined alloc_skb_with_frags(void)
// callers: [qrtr_alloc_backup, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_skb_with_frags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue @ 0010c020 size=1
// signature: undefined skb_dequeue(void)
// callers: [qrtr_node_rx_work, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010c030 size=1
// signature: undefined queue_work_on(void)
// callers: [init_module, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_store_bits @ 0010c038 size=1
// signature: undefined skb_store_bits(void)
// callers: [qrtr_node_rx_work, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_store_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010c040 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qrtr_port_lookup, qrtr_node_rx_work, qrtr_hello_work, qrtr_recvmsg, qrtr_node_release, qrtr_endpoint_unregister, qrtr_local_enqueue, qrtr_node_assign, qrtr_node_lookup, qrtr_port_remove, __qrtr_bind, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// radix_tree_lookup @ 0010c048 size=1
// signature: undefined radix_tree_lookup(void)
// callers: [qrtr_node_enqueue, qrtr_node_rx_work, qrtr_node_assign, qrtr_node_lookup, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void radix_tree_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// radix_tree_insert @ 0010c050 size=1
// signature: undefined radix_tree_insert(void)
// callers: [qrtr_node_enqueue, qrtr_node_assign, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void radix_tree_insert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010c058 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qrtr_port_lookup, qrtr_node_rx_work, qrtr_hello_work, qrtr_recvmsg, qrtr_node_release, qrtr_endpoint_unregister, qrtr_local_enqueue, qrtr_node_assign, qrtr_node_lookup, qrtr_port_remove, __qrtr_bind, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_bits @ 0010c060 size=1
// signature: undefined skb_copy_bits(void)
// callers: [qrtr_node_enqueue, qrtr_node_rx_work, qrtr_sendmsg, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010c068 size=1
// signature: undefined ipc_log_string(void)
// callers: [qrtr_node_enqueue, qrtr_ns_worker, service_announce_new, qrtr_local_enqueue, server_del, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 0010c070 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [qrtr_node_enqueue, qrtr_node_rx_work, qrtr_local_enqueue, qrtr_sendmsg, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_queue_rcv_skb_reason @ 0010c078 size=1
// signature: undefined sock_queue_rcv_skb_reason(void)
// callers: [qrtr_node_rx_work, qrtr_local_enqueue, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_queue_rcv_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 0010c080 size=1
// signature: undefined skb_queue_tail(void)
// callers: [qrtr_alloc_backup, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_queue_work @ 0010c088 size=1
// signature: undefined kthread_queue_work(void)
// callers: [qrtr_node_enqueue, qrtr_ns_data_ready, qrtr_endpoint_register, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_queue_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 0010c090 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_load @ 0010c098 size=1
// signature: undefined xa_load(void)
// callers: [qrtr_get_service_id, qrtr_ns_worker, qrtr_port_lookup, qrtr_hello_work, server_del, qrtr_endpoint_post]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010c0a8 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qrtr_node_enqueue, qrtr_port_lookup, qrtr_node_rx_work, qrtr_hello_work, qrtr_node_release, qrtr_local_enqueue, qrtr_release, qrtr_node_lookup, qrtr_port_remove, __qrtr_bind, qrtr_port_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_free @ 0010c0b0 size=1
// signature: void sk_free(_STACK * param_1)
// callers: [qrtr_node_rx_work, qrtr_hello_work, qrtr_node_release, qrtr_local_enqueue, qrtr_release, __qrtr_bind, qrtr_port_put]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void sk_free(_STACK *param_1)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010c0c0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qrtr_node_enqueue, qrtr_ns_worker, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010c0c8 size=1
// signature: undefined __mutex_init(void)
// callers: [qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kthread_init_worker @ 0010c0d0 size=1
// signature: undefined __kthread_init_worker(void)
// callers: [qrtr_ns_init, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kthread_init_worker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0010c0e0 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [qrtr_ns_init, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010c0e8 size=1
// signature: undefined kfree(void)
// callers: [qrtr_node_enqueue, qrtr_ns_worker, qrtr_node_rx_work, qrtr_node_release, qrtr_endpoint_register, server_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0010c0f0 size=1
// signature: undefined wake_up_process(void)
// callers: [qrtr_ns_init, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_setscheduler @ 0010c0f8 size=1
// signature: int sched_setscheduler(__pid_t __pid, int __policy, sched_param * __param)
// callers: [qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 0010c100 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [qrtr_endpoint_register, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __xa_insert @ 0010c108 size=1
// signature: undefined __xa_insert(void)
// callers: [qrtr_endpoint_register, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __xa_insert(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 0010c110 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [qrtr_endpoint_register, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 0010c118 size=1
// signature: undefined down_write(void)
// callers: [qrtr_node_release, qrtr_release, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010c120 size=1
// signature: undefined __list_add_valid(void)
// callers: [qrtr_node_enqueue, qrtr_ns_worker, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 0010c128 size=1
// signature: undefined up_write(void)
// callers: [qrtr_node_release, qrtr_release, qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 0010c130 size=1
// signature: undefined wakeup_source_register(void)
// callers: [qrtr_endpoint_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_read @ 0010c138 size=1
// signature: undefined down_read(void)
// callers: [qrtr_bcast_enqueue, qrtr_node_rx_work, qrtr_endpoint_unregister, qrtr_node_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_clone @ 0010c140 size=1
// signature: undefined skb_clone(void)
// callers: [qrtr_node_rx_work, qrtr_port_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_clone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 0010c148 size=1
// signature: undefined up_read(void)
// callers: [qrtr_bcast_enqueue, qrtr_node_rx_work, qrtr_endpoint_unregister, qrtr_node_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010c150 size=1
// signature: undefined mutex_lock(void)
// callers: [qrtr_node_enqueue, qrtr_node_rx_work, qrtr_node_release, qrtr_endpoint_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010c158 size=1
// signature: undefined mutex_unlock(void)
// callers: [qrtr_node_enqueue, qrtr_node_rx_work, qrtr_node_release, qrtr_endpoint_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010c160 size=1
// signature: undefined __wake_up(void)
// callers: [qrtr_node_rx_work, qrtr_endpoint_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// consume_skb @ 0010c168 size=1
// signature: undefined consume_skb(void)
// callers: [qrtr_node_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void consume_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010c170 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qrtr_ns_worker, qrtr_node_rx_work, qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 0010c178 size=1
// signature: undefined __alloc_skb(void)
// callers: [qrtr_node_rx_work, qrtr_hello_work, qrtr_recvmsg, qrtr_endpoint_unregister, qrtr_port_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// radix_tree_next_chunk @ 0010c180 size=1
// signature: undefined radix_tree_next_chunk(void)
// callers: [qrtr_node_rx_work, qrtr_node_release, qrtr_endpoint_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void radix_tree_next_chunk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// radix_tree_delete @ 0010c188 size=1
// signature: undefined radix_tree_delete(void)
// callers: [qrtr_node_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void radix_tree_delete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 0010c190 size=1
// signature: undefined wait_for_completion(void)
// callers: [qrtr_node_rx_work, qrtr_local_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010c198 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qrtr_node_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010c1a0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qrtr_node_rx_work, init_module, qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 0010c1a8 size=1
// signature: undefined skb_put(void)
// callers: [qrtr_hello_work, qrtr_recvmsg, qrtr_endpoint_unregister, qrtr_sendmsg, qrtr_port_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_error_report @ 0010c1b0 size=1
// signature: undefined sk_error_report(void)
// callers: [qrtr_local_enqueue, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sk_error_report(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_dec_not_one @ 0010c1b8 size=1
// signature: undefined refcount_dec_not_one(void)
// callers: [qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_dec_not_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// radix_tree_iter_delete @ 0010c1c0 size=1
// signature: undefined radix_tree_iter_delete(void)
// callers: [qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void radix_tree_iter_delete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_flush_worker @ 0010c1c8 size=1
// signature: undefined kthread_flush_worker(void)
// callers: [qrtr_ns_remove, qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_flush_worker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 0010c1d0 size=1
// signature: undefined kthread_stop(void)
// callers: [qrtr_ns_remove, qrtr_node_release, qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_purge @ 0010c1d8 size=1
// signature: undefined skb_queue_purge(void)
// callers: [cleanup_module, qrtr_node_release, qrtr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_purge(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 0010c1e0 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_destroy @ 0010c1e8 size=1
// signature: undefined xa_destroy(void)
// callers: [qrtr_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_compatible_node @ 0010c1f0 size=1
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
// of_property_read_variable_u32_array @ 0010c1f8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proto_register @ 0010c200 size=1
// signature: undefined proto_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proto_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_register @ 0010c208 size=1
// signature: undefined sock_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_unregister @ 0010c210 size=1
// signature: undefined sock_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proto_unregister @ 0010c218 size=1
// signature: undefined proto_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proto_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0010c220 size=1
// signature: undefined cancel_work_sync(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irq @ 0010c228 size=1
// signature: undefined _raw_spin_lock_irq(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irq @ 0010c230 size=1
// signature: undefined _raw_spin_unlock_irq(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010c238 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010c240 size=1
// signature: undefined init_wait_entry(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010c248 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010c250 size=1
// signature: undefined finish_wait(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_push @ 0010c258 size=1
// signature: undefined skb_push(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_push(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010c268 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule @ 0010c270 size=1
// signature: undefined preempt_schedule(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __skb_pad @ 0010c278 size=1
// signature: undefined __skb_pad(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __skb_pad(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010c280 size=1
// signature: undefined schedule_timeout(void)
// callers: [qrtr_node_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sk_alloc @ 0010c288 size=1
// signature: undefined sk_alloc(void)
// callers: [qrtr_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sk_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_init_data @ 0010c290 size=1
// signature: undefined sock_init_data(void)
// callers: [qrtr_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_init_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010c298 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qrtr_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// lock_sock_nested @ 0010c2a0 size=1
// signature: undefined lock_sock_nested(void)
// callers: [qrtr_connect, qrtr_bind, qrtr_recvmsg, qrtr_ioctl, qrtr_getname, qrtr_release, qrtr_sendmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void lock_sock_nested(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_bh @ 0010c2a8 size=1
// signature: undefined _raw_write_lock_bh(void)
// callers: [qrtr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_bh @ 0010c2b0 size=1
// signature: undefined _raw_write_unlock_bh(void)
// callers: [qrtr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_sock @ 0010c2b8 size=1
// signature: undefined release_sock(void)
// callers: [qrtr_connect, qrtr_bind, qrtr_recvmsg, qrtr_ioctl, qrtr_getname, qrtr_release, qrtr_sendmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_sock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_user_ifreq @ 0010c2c0 size=1
// signature: undefined get_user_ifreq(void)
// callers: [qrtr_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_user_ifreq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_user_ifreq @ 0010c2c8 size=1
// signature: undefined put_user_ifreq(void)
// callers: [qrtr_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_user_ifreq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_alloc_send_pskb @ 0010c2e0 size=1
// signature: undefined sock_alloc_send_pskb(void)
// callers: [qrtr_sendmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_alloc_send_pskb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_datagram_from_iter @ 0010c2e8 size=1
// signature: undefined skb_copy_datagram_from_iter(void)
// callers: [qrtr_sendmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_datagram_from_iter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_recv_datagram @ 0010c2f0 size=1
// signature: undefined skb_recv_datagram(void)
// callers: [qrtr_recvmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_recv_datagram(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_copy_datagram_iter @ 0010c2f8 size=1
// signature: undefined skb_copy_datagram_iter(void)
// callers: [qrtr_recvmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_copy_datagram_iter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_free_datagram @ 0010c300 size=1
// signature: undefined skb_free_datagram(void)
// callers: [qrtr_recvmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_free_datagram(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010c308 size=1
// signature: undefined complete_all(void)
// callers: [qrtr_recvmsg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_set_owner_w @ 0010c310 size=1
// signature: undefined skb_set_owner_w(void)
// callers: [qrtr_bcast_enqueue, qrtr_port_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_set_owner_w(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_erase @ 0010c318 size=1
// signature: undefined xa_erase(void)
// callers: [qrtr_port_remove, server_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_erase(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pskb_copy_fclone @ 0010c320 size=1
// signature: undefined __pskb_copy_fclone(void)
// callers: [qrtr_bcast_enqueue]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pskb_copy_fclone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// capable @ 0010c328 size=1
// signature: undefined capable(void)
// callers: [__qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// in_egroup_p @ 0010c330 size=1
// signature: undefined in_egroup_p(void)
// callers: [__qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void in_egroup_p(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __xa_alloc_cyclic @ 0010c338 size=1
// signature: undefined __xa_alloc_cyclic(void)
// callers: [__qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __xa_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 0010c340 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [__qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find @ 0010c348 size=1
// signature: undefined xa_find(void)
// callers: [qrtr_get_service_id, qrtr_ns_worker, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_find_after @ 0010c350 size=1
// signature: undefined xa_find_after(void)
// callers: [qrtr_get_service_id, qrtr_ns_worker, __qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_find_after(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 0010c358 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [__qrtr_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_reserve @ 0010c3a0 size=1
// signature: undefined trace_event_buffer_reserve(void)
// callers: [trace_event_raw_event_qrtr_ns_service_announce_new, trace_event_raw_event_qrtr_ns_service_announce_del, trace_event_raw_event_qrtr_ns_message, trace_event_raw_event_qrtr_ns_server_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_buffer_commit @ 0010c3a8 size=1
// signature: undefined trace_event_buffer_commit(void)
// callers: [trace_event_raw_event_qrtr_ns_service_announce_new, trace_event_raw_event_qrtr_ns_service_announce_del, trace_event_raw_event_qrtr_ns_message, trace_event_raw_event_qrtr_ns_server_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_buffer_commit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __trace_trigger_soft_disabled @ 0010c3b0 size=1
// signature: undefined __trace_trigger_soft_disabled(void)
// callers: [trace_event_raw_event_qrtr_ns_service_announce_new, trace_event_raw_event_qrtr_ns_service_announce_del, trace_event_raw_event_qrtr_ns_message, trace_event_raw_event_qrtr_ns_server_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __trace_trigger_soft_disabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_buf_alloc @ 0010c3b8 size=1
// signature: undefined perf_trace_buf_alloc(void)
// callers: [perf_trace_qrtr_ns_service_announce_del, perf_trace_qrtr_ns_server_add, perf_trace_qrtr_ns_service_announce_new, perf_trace_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_buf_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_trace_run_bpf_submit @ 0010c3c0 size=1
// signature: undefined perf_trace_run_bpf_submit(void)
// callers: [perf_trace_qrtr_ns_service_announce_del, perf_trace_qrtr_ns_server_add, perf_trace_qrtr_ns_service_announce_new, perf_trace_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_trace_run_bpf_submit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010c3c8 size=1
// signature: size_t strlen(char * __s)
// callers: [trace_event_raw_event_qrtr_ns_message, perf_trace_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcpy @ 0010c3d0 size=1
// signature: char * strcpy(char * __dest, char * __src)
// callers: [trace_event_raw_event_qrtr_ns_message, perf_trace_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strcpy(char *__dest,char *__src)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run4 @ 0010c3d8 size=1
// signature: undefined bpf_trace_run4(void)
// callers: [__bpf_trace_qrtr_ns_service_announce_del, __bpf_trace_qrtr_ns_service_announce_new, __bpf_trace_qrtr_ns_server_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run4(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bpf_trace_run3 @ 0010c3e0 size=1
// signature: undefined bpf_trace_run3(void)
// callers: [__bpf_trace_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bpf_trace_run3(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_create_kern @ 0010c3f0 size=1
// signature: undefined sock_create_kern(void)
// callers: [qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_create_kern(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_getsockname @ 0010c3f8 size=1
// signature: undefined kernel_getsockname(void)
// callers: [qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_getsockname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_bind @ 0010c400 size=1
// signature: undefined kernel_bind(void)
// callers: [qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_bind(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_setsockopt @ 0010c408 size=1
// signature: undefined sock_setsockopt(void)
// callers: [qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_setsockopt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_sendmsg @ 0010c410 size=1
// signature: undefined kernel_sendmsg(void)
// callers: [qrtr_ns_worker, service_announce_new, qrtr_ns_init, server_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_sendmsg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 0010c418 size=1
// signature: undefined module_put(void)
// callers: [qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_release @ 0010c420 size=1
// signature: undefined sock_release(void)
// callers: [qrtr_ns_remove, qrtr_ns_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_recvmsg @ 0010c428 size=1
// signature: undefined kernel_recvmsg(void)
// callers: [qrtr_ns_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_recvmsg(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010c430 size=1
// signature: undefined ___ratelimit(void)
// callers: [qrtr_ns_worker, server_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// xa_store @ 0010c438 size=1
// signature: undefined xa_store(void)
// callers: [qrtr_ns_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void xa_store(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __module_get @ 0010c458 size=1
// signature: undefined __module_get(void)
// callers: [qrtr_ns_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_raw_output_prep @ 0010c460 size=1
// signature: undefined trace_raw_output_prep(void)
// callers: [trace_raw_output_qrtr_ns_server_add, trace_raw_output_qrtr_ns_service_announce_new, trace_raw_output_qrtr_ns_service_announce_del, trace_raw_output_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_raw_output_prep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_event_printf @ 0010c468 size=1
// signature: undefined trace_event_printf(void)
// callers: [trace_raw_output_qrtr_ns_server_add, trace_raw_output_qrtr_ns_service_announce_new, trace_raw_output_qrtr_ns_service_announce_del, trace_raw_output_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_event_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// trace_handle_return @ 0010c470 size=1
// signature: undefined trace_handle_return(void)
// callers: [trace_raw_output_qrtr_ns_server_add, trace_raw_output_qrtr_ns_service_announce_new, trace_raw_output_qrtr_ns_service_announce_del, trace_raw_output_qrtr_ns_message]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void trace_handle_return(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



