// Decompiled by Ghidra 12.2
// Program: qcom_glink.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_glink_rx_done_supported @ 00100dd4 size=28
// signature: undefined qcom_glink_rx_done_supported(void)
// callers: []
//------------------------------------------------------------

byte qcom_glink_rx_done_supported(long param_1)

{
  code *pcVar1;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x100df0);
    (*pcVar1)();
  }
  return *(byte *)(*(long *)(param_1 + 0x68) + 0x160) >> 3 & 1;
}



//------------------------------------------------------------
// qcom_glink_rx_done @ 00100df8 size=252
// signature: undefined qcom_glink_rx_done(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_rx_done(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  code *pcVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100ef4);
    (*pcVar4)();
  }
  lVar7 = *(long *)(param_1 + 0x68);
  if ((*(byte *)(lVar7 + 0x160) >> 3 & 1) == 0) {
LAB_00100ed0:
    uVar5 = 0xffffffea;
  }
  else {
    lVar1 = param_1 + 0x88;
    uVar5 = _raw_spin_lock_irqsave(lVar1);
    plVar8 = (long *)(param_1 + 0xf8);
    do {
      plVar8 = (long *)*plVar8;
      if (plVar8 == (long *)(param_1 + 0xf8)) {
        _raw_spin_unlock_irqrestore(lVar1,uVar5);
        goto LAB_00100ed0;
      }
    } while (plVar8[-4] != param_2);
    uVar6 = __list_del_entry_valid(plVar8);
    if ((uVar6 & 1) != 0) {
      lVar2 = *plVar8;
      plVar3 = (long *)plVar8[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar8 = -0x2152ffffffffff00;
    plVar8[1] = -0x2152fffffffffede;
    if ((char)plVar8[-1] == '\0') {
      idr_remove(param_1 + 0x90,(int)plVar8[-3]);
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    qcom_glink_send_rx_done(lVar7,param_1,plVar8 + -4,1);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// qcom_glink_send_rx_done @ 00100ef8 size=284
// signature: undefined qcom_glink_send_rx_done(void)
// callers: [qcom_glink_rx_done_work, __qcom_glink_rx_done, qcom_glink_rx_done]
//------------------------------------------------------------

int qcom_glink_send_rx_done(undefined8 param_1,long param_2,undefined8 *param_3,undefined4 param_4)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  undefined4 uVar5;
  undefined2 local_50;
  undefined2 local_4e;
  undefined4 local_4c;
  long local_48;
  
  lVar4 = sp_el0;
  local_48 = *(long *)(lVar4 + 0x638);
  cVar2 = *(char *)(param_3 + 3);
  uVar1 = *(undefined4 *)(param_3 + 1);
  local_50 = 6;
  if (cVar2 != '\0') {
    local_50 = 0xe;
  }
  local_4e = (undefined2)*(undefined4 *)(param_2 + 0x80);
  local_4c = uVar1;
  iVar3 = qcom_glink_tx(param_1,&local_50,8,0,0,param_4);
  if (iVar3 != 0) goto LAB_00100fb4;
  if (param_3[2] == 0) {
    *param_3 = 0;
    uVar5 = *(undefined4 *)((long)param_3 + 0x1c);
    if (cVar2 == '\0') goto LAB_00100ff4;
LAB_00100f80:
    lVar4 = *(long *)(param_2 + 0x68);
  }
  else {
    uVar5 = *(undefined4 *)((long)param_3 + 0x1c);
    if (cVar2 != '\0') goto LAB_00100f80;
LAB_00100ff4:
    kfree(*param_3);
    kfree(param_3);
    lVar4 = *(long *)(param_2 + 0x68);
  }
  if (lVar4 != 0) {
    ipc_log_string(*(undefined8 *)(lVar4 + 400),"%s[%d:%d] %s: reuse:%d liid:%d data_size:%d",
                   *(undefined8 *)(param_2 + 0x78),*(undefined4 *)(param_2 + 0x80),
                   *(undefined4 *)(param_2 + 0x84),"qcom_glink_send_rx_done",cVar2,uVar1,uVar5);
  }
LAB_00100fb4:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qcom_glink_is_wakeup @ 00101018 size=32
// signature: undefined qcom_glink_is_wakeup(void)
// callers: []
//------------------------------------------------------------

char qcom_glink_is_wakeup(ulong param_1)

{
  char cVar1;
  
  cVar1 = glink_resume_pkt;
  if ((glink_resume_pkt == '\x01') && ((param_1 & 1) != 0)) {
    glink_resume_pkt = '\0';
  }
  return cVar1;
}



//------------------------------------------------------------
// qcom_glink_get_signals @ 0010103c size=12
// signature: undefined qcom_glink_get_signals(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_glink_get_signals(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1d0);
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_glink_set_signals @ 0010104c size=268
// signature: undefined qcom_glink_set_signals(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_set_signals(long param_1,uint param_2,ulong param_3)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  undefined2 local_30;
  undefined2 uStack_2e;
  uint uStack_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x68);
    uVar1 = *(uint *)(param_1 + 0x1cc) | param_2 & 0xc6;
    if ((param_3 & 2) != 0) {
      uVar1 = uVar1 & 0xfffffffd;
    }
    if ((param_3 & 4) != 0) {
      uVar1 = uVar1 & 0xfffffffb;
    }
    if ((param_3 & 0x40) != 0) {
      uVar1 = uVar1 & 0xffffffbf;
    }
    if ((param_3 & 0x80) != 0) {
      uVar1 = uVar1 & 0xffffff7f;
    }
    *(uint *)(param_1 + 0x1cc) = uVar1;
    _local_30 = CONCAT44((uVar1 >> 1) << 0x1f | (uVar1 >> 2 & 1) << 0x1e | (uVar1 >> 6 & 1) << 0x1d
                         | uVar1 & 0xfff | (uVar1 >> 7 & 1) << 0x1c,
                         CONCAT22((short)*(undefined4 *)(param_1 + 0x80),0xf));
    ipc_log_string(*(undefined8 *)(lVar3 + 400),"[%s]: signals:%d\n","qcom_glink_send_signals");
    uVar2 = qcom_glink_tx(lVar3,&local_30,8,0,0,1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_register_signals_cb @ 0010115c size=28
// signature: undefined qcom_glink_register_signals_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_register_signals_cb(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = 0xffffffea;
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar1 = 0;
    *(long *)(param_1 + 0x1d8) = param_2;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_glink_early_ssr_notify @ 0010117c size=272
// signature: undefined qcom_glink_early_ssr_notify(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

void qcom_glink_early_ssr_notify(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  long lVar5;
  int local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x158);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    __wake_up(param_1 + 0x170,3,0,0);
    uVar4 = _raw_spin_lock_irqsave(param_1 + 0x124);
    local_3c = 0;
    lVar5 = idr_get_next(param_1 + 0x128,&local_3c);
    if (lVar5 != 0) {
      do {
        __wake_up(lVar5 + 0x198,3,1,0);
        __wake_up(lVar5 + 0x1b0,3,1,0);
        local_3c = local_3c + 1;
        lVar5 = idr_get_next(param_1 + 0x128,&local_3c);
      } while (lVar5 != 0);
    }
    _raw_spin_unlock_irqrestore(param_1 + 0x124,uVar4);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_native_probe @ 0010129c size=568
// signature: undefined qcom_glink_native_probe(void)
// callers: []
//------------------------------------------------------------

long * qcom_glink_native_probe(long param_1,long param_2,long param_3,long param_4,byte param_5)

{
  int iVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  plVar2 = (long *)devm_kmalloc(param_1,0x198,0xdc0);
  if (plVar2 == (long *)0x0) {
    plVar2 = (long *)0xfffffffffffffff4;
  }
  else {
    *plVar2 = param_1;
    *(byte *)(plVar2 + 0x2d) = param_5 & 1;
    plVar2[10] = param_3;
    plVar2[0xb] = param_4;
    plVar2[0x2c] = param_2;
    *(undefined4 *)(plVar2 + 0x24) = 0;
    *(undefined4 *)(plVar2 + 0x21) = 0;
    plVar2[0x22] = (long)(plVar2 + 0x22);
    plVar2[0x23] = (long)(plVar2 + 0x22);
    plVar2[0x1b] = 0xfffffffe0;
    plVar2[0x1c] = (long)(plVar2 + 0x1c);
    plVar2[0x1d] = (long)(plVar2 + 0x1c);
    plVar2[0x1e] = (long)qcom_glink_work;
    __init_waitqueue_head(plVar2 + 0x2e,"&glink->tx_avail_notify",&qcom_glink_native_probe___key);
    plVar2[0x26] = 0;
    plVar2[0x27] = 0;
    plVar2[0x2a] = 0;
    *(undefined8 *)((long)plVar2 + 0x124) = 0;
    *(undefined4 *)((long)plVar2 + 300) = 0x10000004;
    plVar2[0x28] = 0x1000000400000000;
    plVar2[0x29] = 0;
    *(undefined4 *)(plVar2 + 0x2b) = 0;
    *(undefined ***)(*plVar2 + 800) = &qcom_glink_groups;
    iVar1 = device_add_groups(param_1);
    if (iVar1 != 0) {
      _dev_err(param_1,"failed to add groups\n");
    }
    iVar1 = of_property_read_string(*(undefined8 *)(param_1 + 0x2e8),"label",plVar2 + 1);
    if (iVar1 < 0) {
      plVar2[1] = **(long **)(param_1 + 0x2e8);
    }
    plVar2[2] = param_1;
    *(undefined1 *)(plVar2 + 5) = 1;
    uVar3 = mbox_request_channel(plVar2 + 2,0);
    plVar2[9] = uVar3;
    if (uVar3 < 0xfffffffffffff001) {
      __kthread_init_worker
                (plVar2 + 0x12,"(&glink->kworker)->lock",&qcom_glink_native_probe___key_4);
      uVar3 = kthread_create_on_node
                        (&kthread_worker_fn,plVar2 + 0x12,0xffffffff,"glink_%s",plVar2[1]);
      if (uVar3 < 0xfffffffffffff001) {
        wake_up_process(uVar3);
        plVar2[0x19] = uVar3;
        scnprintf((long)plVar2 + 100,0x20,"glink-native-%s",plVar2[1]);
        lVar4 = ipc_log_context_create(0x20,plVar2[1],0);
        plVar2[0x32] = lVar4;
      }
      else {
        plVar2[0x19] = uVar3;
        _dev_err(param_1,"failed to spawn intent kthread %ld\n",uVar3);
        plVar2 = (long *)plVar2[0x19];
      }
    }
    else if (uVar3 == 0xfffffffffffffdfb) {
      plVar2 = (long *)0xfffffffffffffdfb;
    }
    else {
      _dev_err(param_1,"failed to acquire IPC channel\n");
      plVar2 = (long *)plVar2[9];
    }
  }
  return plVar2;
}



//------------------------------------------------------------
// qcom_glink_work @ 001014d8 size=2620
// signature: undefined qcom_glink_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_glink_work(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  long *plVar5;
  ushort uVar6;
  char cVar7;
  bool bVar8;
  code *pcVar9;
  int iVar10;
  undefined8 uVar11;
  ulong uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  uint *puVar16;
  undefined8 uVar17;
  char *pcVar18;
  undefined4 uVar19;
  undefined4 uVar20;
  long *plVar21;
  long *plVar22;
  long *plVar23;
  uint uVar24;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x30;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar11 = _raw_spin_lock_irqsave(lVar1);
  plVar23 = (long *)(param_1 + 0x38);
  plVar22 = (long *)*plVar23;
  if (plVar22 != plVar23) {
    plVar21 = (long *)(param_1 + -0xd8);
    lVar2 = param_1 + 0x4c;
    lVar3 = param_1 + 0x68;
    do {
      uVar12 = __list_del_entry_valid(plVar22);
      if ((uVar12 & 1) != 0) {
        lVar13 = *plVar22;
        plVar5 = (long *)plVar22[1];
        *(long **)(lVar13 + 8) = plVar5;
        *plVar5 = lVar13;
      }
      *plVar22 = -0x2152ffffffffff00;
      plVar22[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar1,uVar11);
      if (0xb < *(ushort *)(plVar22 + 2)) {
switchD_001015dc_caseD_4:
        __warn_printk("Unknown defer object %d\n");
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101768);
        (*pcVar9)();
      }
      uVar6 = *(ushort *)((long)plVar22 + 0x12);
      uVar12 = (ulong)*(uint *)((long)plVar22 + 0x14);
      uVar24 = (uint)uVar6;
      switch(*(ushort *)(plVar22 + 2)) {
      case 0:
        ipc_log_string(*(undefined8 *)(param_1 + 0xb8),"[%s]: vers:%d features:%d\n",
                       "qcom_glink_receive_version",uVar6,uVar12);
        if (uVar6 != 0) {
          if (uVar6 == 1) {
            uVar12 = *(ulong *)(param_1 + 0x88) & uVar12;
            *(ulong *)(param_1 + 0x88) = uVar12;
          }
          else {
            uVar12 = *(ulong *)(param_1 + 0x88);
          }
          uVar19 = (undefined4)uVar12;
          uVar11 = *(undefined8 *)(param_1 + 0xb8);
          uVar20 = 0x10001;
          pcVar18 = "qcom_glink_send_version_ack";
LAB_00101b40:
          local_90 = (char *)CONCAT44(uVar19,uVar20);
          ipc_log_string(uVar11,"[%s]: vers:%d features:%d\n",pcVar18,1);
          qcom_glink_tx(plVar21,&local_90,8,0,0,1);
        }
        break;
      case 1:
        ipc_log_string(*(undefined8 *)(param_1 + 0xb8),"[%s]: vers:%d features:%d\n",
                       "qcom_glink_receive_version_ack",uVar6,uVar12);
        if (uVar24 != 0) {
          if (uVar24 == 1) {
            if (*(ulong *)(param_1 + 0x88) == uVar12) break;
            uVar12 = *(ulong *)(param_1 + 0x88) & uVar12;
            *(ulong *)(param_1 + 0x88) = uVar12;
          }
          else {
            uVar12 = *(ulong *)(param_1 + 0x88);
          }
          uVar19 = (undefined4)uVar12;
          uVar20 = 0x10000;
          uVar11 = *(undefined8 *)(param_1 + 0xb8);
          pcVar18 = "qcom_glink_send_version";
          goto LAB_00101b40;
        }
        break;
      case 2:
        plVar5 = plVar22 + 3;
        uVar11 = _raw_spin_lock_irqsave(lVar2);
        local_98 = local_98 & 0xffffffff00000000;
        uVar12 = idr_get_next(lVar3,&local_98);
        if (uVar12 != 0) {
          do {
            iVar10 = strcmp(*(char **)(uVar12 + 0x78),(char *)plVar5);
            if (iVar10 == 0) {
              _raw_spin_unlock_irqrestore(lVar2,uVar11);
              bVar8 = false;
              goto LAB_00101b84;
            }
            local_98 = CONCAT44(local_98._4_4_,(uint)local_98 + 1);
            uVar12 = idr_get_next(lVar3,&local_98);
          } while (uVar12 != 0);
        }
        _raw_spin_unlock_irqrestore(lVar2,uVar11);
        uVar12 = qcom_glink_alloc_channel(plVar21,plVar5);
        if (uVar12 < 0xfffffffffffff001) {
          bVar8 = true;
LAB_00101b84:
          uVar11 = _raw_spin_lock_irqsave(lVar2);
          iVar10 = idr_alloc(lVar3,uVar12,uVar6,uVar24 + 1,0xa20);
          if (iVar10 < 0) {
            _dev_err(*plVar21,"Unable to insert channel into rcid list\n");
          }
          else {
            *(int *)(uVar12 + 0x84) = iVar10;
            _raw_spin_unlock_irqrestore(lVar2,uVar11);
            complete_all(uVar12 + 0x138);
            local_90._0_4_ = CONCAT22((short)*(undefined4 *)(uVar12 + 0x84),4);
            local_90 = (char *)(ulong)(uint)local_90;
            if (*(long *)(uVar12 + 0x68) != 0) {
              ipc_log_string(*(undefined8 *)(*(long *)(uVar12 + 0x68) + 400),"%s[%d:%d] %s: \n",
                             *(undefined8 *)(uVar12 + 0x78),*(undefined4 *)(uVar12 + 0x80),
                             *(undefined4 *)(uVar12 + 0x84),"qcom_glink_send_open_ack");
            }
            qcom_glink_tx(plVar21,&local_90,8,0,0,1);
            if (!bVar8) {
LAB_00101da8:
              if (*(long *)(uVar12 + 0x68) != 0) {
                ipc_log_string(*(undefined8 *)(*(long *)(uVar12 + 0x68) + 400),"%s[%d:%d] %s: \n",
                               *(undefined8 *)(uVar12 + 0x78),*(undefined4 *)(uVar12 + 0x80),
                               *(undefined4 *)(uVar12 + 0x84),"qcom_glink_rx_open");
              }
              break;
            }
            lVar13 = kmalloc_trace(_nr_cpu_ids,0xdc0,0x3e0);
            if (lVar13 != 0) {
              *(ulong *)(lVar13 + 0x3c8) = uVar12;
              strscpy_pad(lVar13 + 0x390,plVar5,0x20);
              lVar14 = *plVar21;
              lVar15 = 0;
              local_90 = (char *)0x0;
              *(undefined8 *)(lVar13 + 0x3c0) = 0xffffffffffffffff;
              *(undefined1 **)(lVar13 + 0x3d8) = glink_device_ops;
              uVar11 = *(undefined8 *)(lVar14 + 0x2e8);
              do {
                lVar15 = of_get_next_available_child(uVar11,lVar15);
                if (lVar15 == 0) break;
                iVar10 = of_property_read_string(lVar15,"qcom,glink-channels",&local_90);
              } while ((iVar10 != 0) || (iVar10 = strcmp(local_90,(char *)plVar5), iVar10 != 0));
              *(long *)(lVar13 + 0x2e8) = lVar15;
              *(long *)(lVar13 + 0x60) = *plVar21;
              *(code **)(lVar13 + 0x328) = qcom_glink_rpdev_release;
              iVar10 = rpmsg_register_device(lVar13);
              if (iVar10 == 0) {
                *(long *)(uVar12 + 0x60) = lVar13;
                goto LAB_00101da8;
              }
            }
            if (*(long *)(uVar12 + 0x68) != 0) {
              ipc_log_string(*(undefined8 *)(*(long *)(uVar12 + 0x68) + 400),
                             "%s[%d:%d] %s: rcid_remove\n",*(undefined8 *)(uVar12 + 0x78),
                             *(undefined4 *)(uVar12 + 0x80),*(undefined4 *)(uVar12 + 0x84),
                             "qcom_glink_rx_open");
            }
            uVar11 = _raw_spin_lock_irqsave(lVar2);
            idr_remove(lVar3,*(undefined4 *)(uVar12 + 0x84));
            *(undefined4 *)(uVar12 + 0x84) = 0;
          }
          _raw_spin_unlock_irqrestore(lVar2,uVar11);
          if (*(long *)(uVar12 + 0x68) != 0) {
            ipc_log_string(*(undefined8 *)(*(long *)(uVar12 + 0x68) + 400),
                           "%s[%d:%d] %s: free_channel\n",*(undefined8 *)(uVar12 + 0x78),
                           *(undefined4 *)(uVar12 + 0x80),*(undefined4 *)(uVar12 + 0x84),
                           "qcom_glink_rx_open");
          }
          if (bVar8) {
            piVar4 = (int *)(uVar12 + 0x70);
            Hint_Prefetch(piVar4,2,0,1);
            do {
              iVar10 = *piVar4;
              cVar7 = '\x01';
              bVar8 = (bool)ExclusiveMonitorPass(piVar4,0x10);
              if (bVar8) {
                *piVar4 = iVar10 + -1;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            if (iVar10 == 1) {
              DataMemoryBarrier(2,1);
              qcom_glink_channel_release();
            }
            else if (iVar10 < 1) {
              refcount_warn_saturate(piVar4,3);
            }
          }
        }
        break;
      case 3:
        local_78 = 0;
        local_70 = 0;
        local_88 = 0;
        uStack_80 = 0;
        local_90 = (char *)0x0;
        uVar11 = _raw_spin_lock_irqsave(lVar2);
        lVar13 = idr_find(lVar3,uVar6);
        _raw_spin_unlock_irqrestore(lVar2,uVar11);
        if (lVar13 == 0) {
          __warn_printk("close request on unknown channel\n");
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101e54);
          (*pcVar9)();
        }
        if (*(long *)(lVar13 + 0x68) != 0) {
          ipc_log_string(*(undefined8 *)(*(long *)(lVar13 + 0x68) + 400),"%s[%d:%d] %s: \n",
                         *(undefined8 *)(lVar13 + 0x78),*(undefined4 *)(lVar13 + 0x80),
                         *(undefined4 *)(lVar13 + 0x84),"qcom_glink_rx_close");
        }
        kthread_cancel_work_sync(lVar13 + 0xc0);
        if (*(long *)(lVar13 + 0x60) != 0) {
          strscpy_pad(&local_90,*(undefined8 *)(lVar13 + 0x78),0x20);
          local_70 = 0xffffffffffffffff;
          rpmsg_unregister_device(*plVar21,&local_90);
        }
        *(undefined8 *)(lVar13 + 0x60) = 0;
        local_98._0_4_ = CONCAT22((short)*(undefined4 *)(lVar13 + 0x84),0xb);
        local_98 = (ulong)(uint)local_98;
        ipc_log_string(*(undefined8 *)(param_1 + 0xb8),"[%s]: rcid:%d\n","qcom_glink_send_close_ack"
                      );
        qcom_glink_tx(plVar21,&local_98,8,0,0,1);
        uVar11 = _raw_spin_lock_irqsave(lVar2);
        idr_remove(lVar3,*(undefined4 *)(lVar13 + 0x84));
        *(undefined4 *)(lVar13 + 0x84) = 0;
        _raw_spin_unlock_irqrestore(lVar2,uVar11);
        puVar16 = (uint *)(lVar13 + 0x70);
        Hint_Prefetch(puVar16,2,0,1);
        do {
          uVar24 = *puVar16;
          cVar7 = '\x01';
          bVar8 = (bool)ExclusiveMonitorPass(puVar16,0x10);
          if (bVar8) {
            *puVar16 = uVar24 - 1;
            cVar7 = ExclusiveMonitorsStatus();
          }
        } while (cVar7 != '\0');
        if (uVar24 == 1) {
          DataMemoryBarrier(2,1);
          qcom_glink_channel_release();
        }
        else {
LAB_00101a10:
          if ((int)uVar24 < 1) {
LAB_00101af8:
            refcount_warn_saturate(puVar16,3);
          }
        }
        break;
      default:
        goto switchD_001015dc_caseD_4;
      case 7:
        if (plVar21 != (long *)0x0) {
          uVar11 = _raw_spin_lock_irqsave(lVar2);
          lVar13 = idr_find(lVar3,uVar6);
          if (lVar13 != 0) {
            puVar16 = (uint *)(lVar13 + 0x70);
            Hint_Prefetch(puVar16,2,0,1);
            do {
              uVar24 = *puVar16;
              cVar7 = '\x01';
              bVar8 = (bool)ExclusiveMonitorPass(puVar16,0x10);
              if (bVar8) {
                *puVar16 = uVar24 + 1;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            if (uVar24 == 0) {
              uVar17 = 2;
LAB_00101eb8:
              refcount_warn_saturate(puVar16,uVar17);
            }
            else if ((int)(uVar24 + 1 | uVar24) < 0) {
              uVar17 = 1;
              goto LAB_00101eb8;
            }
            _raw_spin_unlock_irqrestore(lVar2,uVar11);
            lVar15 = lVar13 + 0x88;
            uVar11 = _raw_spin_lock_irqsave(lVar15);
            local_98 = local_98 & 0xffffffff00000000;
LAB_0010195c:
            lVar14 = idr_get_next(lVar13 + 0x90,&local_98);
            if (lVar14 != 0) {
              if ((*(ulong *)(lVar14 + 0x10) < uVar12) || (*(char *)(lVar14 + 0x18) == '\0'))
              goto LAB_00101950;
              _raw_spin_unlock_irqrestore(lVar15,uVar11);
              local_90._0_4_ = CONCAT22((short)*(undefined4 *)(lVar13 + 0x80),8);
              local_90 = (char *)CONCAT44(1,(uint)local_90);
              if (*(long *)(lVar13 + 0x68) != 0) {
                ipc_log_string(*(undefined8 *)(*(long *)(lVar13 + 0x68) + 400),"%s[%d:%d] %s: \n",
                               *(undefined8 *)(lVar13 + 0x78),*(undefined4 *)(lVar13 + 0x80),
                               *(undefined4 *)(lVar13 + 0x84),"qcom_glink_send_intent_req_ack");
              }
              qcom_glink_tx(plVar21,&local_90,8,0,0,1);
              Hint_Prefetch(puVar16,2,0,1);
              do {
                uVar24 = *puVar16;
                cVar7 = '\x01';
                bVar8 = (bool)ExclusiveMonitorPass(puVar16,0x10);
                if (bVar8) {
                  *puVar16 = uVar24 - 1;
                  cVar7 = ExclusiveMonitorsStatus();
                }
              } while (cVar7 != '\0');
              if (uVar24 == 1) {
                DataMemoryBarrier(2,1);
                goto LAB_00101ae0;
              }
              goto LAB_00101aec;
            }
            _raw_spin_unlock_irqrestore(lVar15,uVar11);
            lVar15 = qcom_glink_alloc_intent(lVar13,uVar12,0);
            if ((lVar15 != 0) && (*(char *)(lVar13 + 0x189) != '\0')) {
              qcom_glink_advertise_intent(plVar21,lVar13,lVar15);
            }
            local_90._0_4_ = CONCAT22((short)*(undefined4 *)(lVar13 + 0x80),8);
            local_90 = (char *)(ulong)CONCAT14(lVar15 != 0,(uint)local_90);
            if (*(long *)(lVar13 + 0x68) != 0) {
              ipc_log_string(*(undefined8 *)(*(long *)(lVar13 + 0x68) + 400),"%s[%d:%d] %s: \n",
                             *(undefined8 *)(lVar13 + 0x78),*(undefined4 *)(lVar13 + 0x80),
                             *(undefined4 *)(lVar13 + 0x84),"qcom_glink_send_intent_req_ack");
            }
            qcom_glink_tx(plVar21,&local_90,8,0,0,1);
            Hint_Prefetch(puVar16,2,0,1);
            do {
              uVar24 = *puVar16;
              cVar7 = '\x01';
              bVar8 = (bool)ExclusiveMonitorPass(puVar16,0x10);
              if (bVar8) {
                *puVar16 = uVar24 - 1;
                cVar7 = ExclusiveMonitorsStatus();
              }
            } while (cVar7 != '\0');
            if (uVar24 == 1) {
              DataMemoryBarrier(2,1);
LAB_00101ae0:
              qcom_glink_channel_release(puVar16);
            }
            else {
LAB_00101aec:
              if ((int)uVar24 < 1) goto LAB_00101af8;
            }
            break;
          }
          _raw_spin_unlock_irqrestore(lVar2,uVar11);
        }
        _printk(&DAT_0010691d,"qcom_glink_handle_intent_req",uVar6);
        break;
      case 0xb:
        __wake_up(param_1 + 0x98,3,0,0);
        uVar11 = _raw_spin_lock_irqsave(lVar2);
        lVar13 = idr_find(param_1 + 0x50,uVar6);
        if (lVar13 == 0) {
          __warn_printk("close ack on unknown channel\n");
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x800,0x101e34);
          (*pcVar9)();
        }
        if (*(long *)(lVar13 + 0x68) != 0) {
          ipc_log_string(*(undefined8 *)(*(long *)(lVar13 + 0x68) + 400),"%s[%d:%d] %s: \n",
                         *(undefined8 *)(lVar13 + 0x78),*(undefined4 *)(lVar13 + 0x80),
                         *(undefined4 *)(lVar13 + 0x84),"qcom_glink_rx_close_ack");
        }
        idr_remove(param_1 + 0x50,*(undefined4 *)(lVar13 + 0x80));
        *(undefined4 *)(lVar13 + 0x80) = 0;
        _raw_spin_unlock_irqrestore(lVar2,uVar11);
        puVar16 = (uint *)(lVar13 + 0x70);
        *(undefined4 *)(lVar13 + 0x118) = 0;
        *(undefined1 *)(lVar13 + 0x189) = 0;
        Hint_Prefetch(puVar16,2,0,1);
        do {
          uVar24 = *puVar16;
          cVar7 = '\x01';
          bVar8 = (bool)ExclusiveMonitorPass(puVar16,0x10);
          if (bVar8) {
            *puVar16 = uVar24 - 1;
            cVar7 = ExclusiveMonitorsStatus();
          }
        } while (cVar7 != '\0');
        if (uVar24 != 1) goto LAB_00101a10;
        DataMemoryBarrier(2,1);
        qcom_glink_channel_release();
      }
      kfree(plVar22);
      uVar11 = _raw_spin_lock_irqsave(lVar1);
      plVar22 = (long *)*plVar23;
    } while (plVar22 != plVar23);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar11);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
LAB_00101950:
  local_98 = CONCAT44(local_98._4_4_,(uint)local_98 + 1);
  goto LAB_0010195c;
}



//------------------------------------------------------------
// qcom_glink_native_start @ 00101f6c size=816
// signature: undefined qcom_glink_native_start(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_glink_native_start(long *param_1)

{
  long *__s;
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  ulong uVar10;
  char *pcVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  undefined8 local_70;
  long local_68;
  
  lVar12 = sp_el0;
  local_68 = *(long *)(lVar12 + 0x638);
  lVar12 = *param_1;
  *(undefined4 *)((long)param_1 + 0x84) = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  uVar5 = of_irq_get(*(undefined8 *)(lVar12 + 0x2e8),0);
  iVar6 = devm_request_threaded_irq
                    (lVar12,uVar5,qcom_glink_native_intr,qcom_glink_native_thread_intr,0x4000,
                     (long)param_1 + 100,param_1);
  if (iVar6 == 0) {
    *(undefined4 *)(param_1 + 0xc) = uVar5;
    uVar7 = of_property_count_elems_of_size(*(undefined8 *)(lVar12 + 0x2e8),"cpu-affinity",4);
    if (0 < (int)uVar7) {
      uVar13 = (ulong)uVar7;
      uVar10 = uVar13 * 4;
      lVar9 = __kmalloc(uVar10,0xcc0);
      if (lVar9 == 0) {
        iVar6 = -0xc;
        goto LAB_00102220;
      }
      iVar6 = of_property_read_variable_u32_array
                        (*(undefined8 *)(lVar12 + 0x2e8),"cpu-affinity",lVar9,uVar13,0);
      if (-1 < iVar6) {
        __s = param_1 + 0x1a;
        memset(__s,0,(ulong)(_nr_cpu_ids + 0x3fU >> 3 & 0x1ffffff8));
        uVar14 = 0;
        do {
          if (uVar10 <= uVar14 * 4) {
LAB_001022a0:
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x1022a4);
            (*pcVar4)();
          }
          uVar7 = *(uint *)(lVar9 + uVar14 * 4);
          uVar8 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
          if (uVar7 < uVar8) {
            if (uVar10 <= uVar14 * 4) goto LAB_001022a0;
            uVar7 = *(uint *)(lVar9 + uVar14 * 4);
            puVar1 = (ulong *)(__s + (uVar7 >> 6));
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar2 = '\x01';
              bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar3) {
                *puVar1 = *puVar1 | 1L << ((ulong)uVar7 & 0x3f);
                cVar2 = ExclusiveMonitorsStatus();
              }
            } while (cVar2 != '\0');
          }
          uVar14 = (ulong)((int)uVar14 + 1);
        } while (uVar14 < uVar13);
        iVar6 = __irq_apply_affinity_hint((int)param_1[0xc],__s,1);
        if (iVar6 != 0) {
          _dev_err(*param_1,"failed to set irq affinity\n");
        }
        iVar6 = set_cpus_allowed_ptr(param_1[0x19],__s);
        if (iVar6 != 0) {
          _dev_err(*param_1,"failed to set task affinity\n");
        }
      }
      kfree(lVar9);
    }
    local_70 = CONCAT44((int)param_1[0x2c],0x10000);
    ipc_log_string(param_1[0x32],"[%s]: vers:%d features:%d\n","qcom_glink_send_version",1);
    iVar6 = qcom_glink_tx(param_1,&local_70,8,0,0,1);
    if (iVar6 == 0) {
      lVar12 = kmalloc_trace(CONCAT44(uRam000000000010a14c,_nr_cpu_ids),0xdc0,0x3e0);
      if (lVar12 == 0) {
LAB_001021c8:
        _dev_err(*param_1,"failed to register chrdev\n");
      }
      else {
        uVar10 = qcom_glink_alloc_channel(param_1,"rpmsg_chrdev");
        if (uVar10 < 0xfffffffffffff001) {
          *(long *)(uVar10 + 0x60) = lVar12;
          lVar9 = *param_1;
          *(undefined1 **)(lVar12 + 0x3d8) = glink_device_ops;
          *(ulong *)(lVar12 + 0x3c8) = uVar10;
          *(long *)(lVar12 + 0x60) = lVar9;
          *(code **)(lVar12 + 0x328) = qcom_glink_device_release;
          iVar6 = rpmsg_register_device_override(lVar12,"rpmsg_ctrl");
        }
        else {
          kfree(lVar12);
          iVar6 = (int)uVar10;
        }
        if (iVar6 != 0) goto LAB_001021c8;
      }
      iVar6 = 0;
      goto LAB_00102220;
    }
    lVar12 = *param_1;
    pcVar11 = "failed to send version: %d\n";
  }
  else {
    pcVar11 = "failed to request IRQ with %d\n";
  }
  _dev_err(lVar12,pcVar11,iVar6);
LAB_00102220:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// qcom_glink_native_intr @ 001022ac size=48
// signature: undefined qcom_glink_native_intr(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_glink_native_intr(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = qcom_glink_native_rx(param_2,0xf);
  uVar2 = 1;
  if (iVar1 != 0) {
    uVar2 = 2;
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_glink_native_thread_intr @ 001022e0 size=60
// signature: undefined qcom_glink_native_thread_intr(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_native_thread_intr(undefined8 param_1,undefined8 param_2)

{
  uint uVar1;
  
  do {
    uVar1 = qcom_glink_native_rx(param_2,0);
  } while (7 < uVar1);
  return 1;
}



//------------------------------------------------------------
// qcom_glink_native_remove @ 00102320 size=808
// signature: undefined qcom_glink_native_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_native_remove(long *param_1)

{
  int *piVar1;
  long *plVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long *plVar6;
  long lVar7;
  code *pcVar8;
  int local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  qcom_glink_early_ssr_notify();
  disable_irq((int)param_1[0xc]);
  cancel_work_sync(param_1 + 0x1b);
  plVar6 = (long *)param_1[0x22];
  while (plVar6 != param_1 + 0x22) {
    plVar6 = (long *)*plVar6;
    kfree();
  }
  iVar5 = device_for_each_child(*param_1,0,qcom_glink_remove_device);
  if (iVar5 != 0) {
    _dev_warn(*param_1,"Can\'t remove GLINK devices: %d\n",iVar5);
  }
  plVar6 = param_1 + 0x25;
  local_4c = 0;
  lVar7 = idr_get_next(plVar6,&local_4c);
  while (lVar7 != 0) {
    piVar1 = (int *)(lVar7 + 0x70);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar5 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release();
    }
    else if (iVar5 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
    idr_remove(plVar6,(long)local_4c);
    local_4c = local_4c + 1;
    lVar7 = idr_get_next(plVar6,&local_4c);
  }
  plVar2 = param_1 + 0x28;
  local_4c = 0;
  lVar7 = idr_get_next(plVar2,&local_4c);
  while (lVar7 != 0) {
    piVar1 = (int *)(lVar7 + 0x70);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar5 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release();
    }
    else if (iVar5 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
    idr_remove(plVar2,(long)local_4c);
    local_4c = local_4c + 1;
    lVar7 = idr_get_next(plVar2,&local_4c);
  }
  local_4c = 0;
  lVar7 = idr_get_next(plVar2,&local_4c);
  while (lVar7 != 0) {
    piVar1 = (int *)(lVar7 + 0x70);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar5 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar5 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar5 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release();
    }
    else if (iVar5 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
    local_4c = local_4c + 1;
    lVar7 = idr_get_next(plVar2,&local_4c);
  }
  idr_destroy(plVar6);
  idr_destroy(plVar2);
  kthread_flush_worker(param_1 + 0x12);
  kthread_stop(param_1[0x19]);
  pcVar8 = *(code **)(param_1[0xb] + 0x28);
  if (pcVar8 != (code *)0x0) {
    if (*(int *)(pcVar8 + -4) != -0x6d35713b) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1025a4);
      (*pcVar8)();
    }
    (*pcVar8)();
  }
  pcVar8 = *(code **)(param_1[10] + 0x28);
  if (pcVar8 != (code *)0x0) {
    if (*(int *)(pcVar8 + -4) != -0x6d35713b) {
                    /* WARNING: Does not return */
      pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x1025cc);
      (*pcVar8)();
    }
    (*pcVar8)();
  }
  mbox_free_channel(param_1[9]);
  iVar5 = of_property_count_elems_of_size(*(undefined8 *)(*param_1 + 0x2e8),"cpu-affinity",4);
  if ((0 < iVar5) && (iVar5 = __irq_apply_affinity_hint((int)param_1[0xc],0,1), iVar5 != 0)) {
    _dev_err(*param_1,"failed to clear irq affinity\n");
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_remove_device @ 00102670 size=32
// signature: undefined qcom_glink_remove_device(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_remove_device(void)

{
  device_unregister();
  return 0;
}



//------------------------------------------------------------
// qcom_glink_channel_release @ 00102694 size=592
// signature: undefined qcom_glink_channel_release(void)
// callers: [qcom_glink_channel_ref_put, qcom_glink_create_ept, qcom_glink_native_remove, qcom_glink_work, qcom_glink_device_release, qcom_glink_handle_rx_done, qcom_glink_native_rx]
//------------------------------------------------------------

void qcom_glink_channel_release(long param_1)

{
  char *pcVar1;
  int *piVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  long lVar7;
  long *plVar8;
  int local_4c;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  local_4c = 0;
  if (*(long *)(param_1 + -8) != 0) {
    ipc_log_string(*(undefined8 *)(*(long *)(param_1 + -8) + 400),"%s[%d:%d] %s: \n",
                   *(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x10),
                   *(undefined4 *)(param_1 + 0x14),"qcom_glink_channel_release");
  }
  piVar2 = (int *)(param_1 + 0x11c);
  *(undefined1 *)(param_1 + 0x118) = 0;
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = *piVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  __wake_up(param_1 + 0x128,3,1,0);
  piVar2 = (int *)(param_1 + 0x120);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar4) {
      *piVar2 = *piVar2 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  __wake_up(param_1 + 0x140,3,1,0);
  kthread_cancel_work_sync(param_1 + 0x50);
  uVar5 = _raw_spin_lock_irqsave(param_1 + 0x18);
  plVar8 = *(long **)(param_1 + 0x78);
  while (plVar8 != (long *)(param_1 + 0x78)) {
    puVar6 = plVar8 + -4;
    if (plVar8[-2] == 0) {
      *puVar6 = 0;
    }
    pcVar1 = (char *)(plVar8 + -1);
    plVar8 = (long *)*plVar8;
    if (*pcVar1 == '\0') {
      kfree(*puVar6);
      kfree(puVar6);
    }
  }
  plVar8 = *(long **)(param_1 + 0x88);
  while (plVar8 != (long *)(param_1 + 0x88)) {
    puVar6 = plVar8 + -4;
    if (plVar8[-2] == 0) {
      *puVar6 = 0;
    }
    pcVar1 = (char *)(plVar8 + -1);
    plVar8 = (long *)*plVar8;
    if (*pcVar1 == '\0') {
      kfree(*puVar6);
      kfree(puVar6);
    }
  }
  lVar7 = param_1 + 0x20;
  local_4c = 0;
  puVar6 = (undefined8 *)idr_get_next(lVar7,&local_4c);
  if (puVar6 != (undefined8 *)0x0) {
    do {
      kfree(*puVar6);
      kfree(puVar6);
      local_4c = local_4c + 1;
      puVar6 = (undefined8 *)idr_get_next(lVar7,&local_4c);
    } while (puVar6 != (undefined8 *)0x0);
  }
  idr_destroy(lVar7);
  local_4c = 0;
  while (lVar7 = idr_get_next(param_1 + 0x38,&local_4c), lVar7 != 0) {
    kfree();
    local_4c = local_4c + 1;
  }
  idr_destroy(param_1 + 0x38);
  _raw_spin_unlock_irqrestore(param_1 + 0x18,uVar5);
  kfree(*(undefined8 *)(param_1 + 8));
  kfree(param_1 + -0x70);
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_native_unregister @ 001028fc size=32
// signature: undefined qcom_glink_native_unregister(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_native_unregister(undefined8 *param_1)

{
  device_unregister(*param_1);
  return;
}



//------------------------------------------------------------
// qcom_glink_suspend_no_irq @ 00102920 size=20
// signature: undefined qcom_glink_suspend_no_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_suspend_no_irq(void)

{
  should_wake = 1;
  return 0;
}



//------------------------------------------------------------
// qcom_glink_resume_no_irq @ 00102938 size=16
// signature: undefined qcom_glink_resume_no_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_resume_no_irq(void)

{
  should_wake = 0;
  return 0;
}



//------------------------------------------------------------
// qcom_glink_tx @ 00102948 size=864
// signature: undefined qcom_glink_tx(void)
// callers: [__qcom_glink_send, qcom_glink_advertise_intent, qcom_glink_destroy_ept, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_set_signals, qcom_glink_work, qcom_glink_send_rx_done, qcom_glink_native_start]
//------------------------------------------------------------

undefined8
qcom_glink_tx(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
             undefined8 param_5,uint param_6)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  code *pcVar6;
  undefined8 uVar7;
  long lVar8;
  ulong uVar9;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar9 = (ulong)(uint)((int)param_5 + (int)param_3);
  if (uVar9 < **(ulong **)(param_1 + 0x58)) {
    if (*(int *)(param_1 + 0x158) == 0) {
      lVar1 = param_1 + 0x120;
      uVar3 = _raw_spin_lock_irqsave(lVar1);
      pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
      if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1029ec);
        (*pcVar6)();
      }
      uVar4 = (*pcVar6)();
      uVar5 = uVar3;
      if (uVar4 < uVar9) {
        lVar2 = param_1 + 0x170;
        do {
          if ((param_6 & 1) == 0) {
            uVar7 = 0xfffffff5;
            goto LAB_00102c60;
          }
          if (*(char *)(param_1 + 0x188) == '\0') {
            *(undefined1 *)(param_1 + 0x188) = 1;
            local_90 = 0xd;
            ipc_log_string(*(undefined8 *)(param_1 + 400),"[%s]: send READ NOTIFY cmd\n",
                           "qcom_glink_send_read_notify");
            pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 0x20);
            if (*(int *)(pcVar6 + -4) != -0x45dc26dd) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102a94);
              (*pcVar6)();
            }
            (*pcVar6)(*(long *)(param_1 + 0x58),&local_90,8,0,0);
            mbox_send_message(*(undefined8 *)(param_1 + 0x48),0);
            mbox_client_txdone(*(undefined8 *)(param_1 + 0x48),0);
          }
          _raw_spin_unlock_irqrestore(lVar1,uVar5);
          pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
          if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102adc);
            (*pcVar6)();
          }
          uVar4 = (*pcVar6)();
          if ((uVar4 < uVar9) && (*(int *)(param_1 + 0x158) == 0)) {
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_90 = 0;
            init_wait_entry(&local_90,0);
            prepare_to_wait_event(lVar2,&local_90,2);
            pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
            if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102b38);
              (*pcVar6)();
            }
            uVar4 = (*pcVar6)();
            if (uVar4 < uVar9) {
              lVar8 = 0x9c4;
              do {
                if (lVar8 == 0 && *(int *)(param_1 + 0x158) != 0) {
                  lVar8 = 1;
                }
                if ((*(int *)(param_1 + 0x158) != 0) || (lVar8 == 0)) break;
                lVar8 = schedule_timeout();
                prepare_to_wait_event(lVar2,&local_90,2);
                pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
                if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
                  pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102b98);
                  (*pcVar6)();
                }
                uVar4 = (*pcVar6)();
              } while (uVar4 < uVar9);
            }
            finish_wait(lVar2,&local_90);
          }
          uVar5 = _raw_spin_lock_irqsave(lVar1);
          if (*(int *)(param_1 + 0x158) != 0) {
            uVar7 = 0xffffff98;
            uVar3 = uVar5;
            goto LAB_00102c60;
          }
          pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
          if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102be4);
            (*pcVar6)();
          }
          uVar4 = (*pcVar6)();
          if (uVar9 <= uVar4) {
            *(undefined1 *)(param_1 + 0x188) = 0;
          }
          pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 8);
          if (*(int *)(pcVar6 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102a24);
            (*pcVar6)();
          }
          uVar4 = (*pcVar6)();
        } while (uVar4 < uVar9);
      }
      pcVar6 = *(code **)(*(long *)(param_1 + 0x58) + 0x20);
      if (*(int *)(pcVar6 + -4) != -0x45dc26dd) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102c28);
        (*pcVar6)();
      }
      (*pcVar6)(*(long *)(param_1 + 0x58),param_2,param_3,param_4,param_5);
      mbox_send_message(*(undefined8 *)(param_1 + 0x48),0);
      mbox_client_txdone(*(undefined8 *)(param_1 + 0x48),0);
      uVar7 = 0;
      uVar3 = uVar5;
LAB_00102c60:
      _raw_spin_unlock_irqrestore(lVar1,uVar3);
    }
    else {
      uVar7 = 0xffffff98;
    }
  }
  else {
    uVar7 = 0xffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// qcom_glink_alloc_channel @ 00102ca8 size=356
// signature: undefined qcom_glink_alloc_channel(void)
// callers: [qcom_glink_create_ept, qcom_glink_work, qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long qcom_glink_alloc_channel(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar1 = kmalloc_trace(_of_property_read_variable_u32_array,0xdc0,0x1e0);
  if (lVar1 != 0) {
    *(undefined4 *)(lVar1 + 0x74) = 0;
    *(undefined4 *)(lVar1 + 0x88) = 0;
    __mutex_init(lVar1 + 0x158,"&channel->intent_req_lock",&qcom_glink_alloc_channel___key);
    *(undefined8 *)(lVar1 + 0x68) = param_1;
    lVar2 = kstrdup(param_2,0xcc0);
    *(long *)(lVar1 + 0x78) = lVar2;
    if (lVar2 != 0) {
      *(undefined4 *)(lVar1 + 0x138) = 0;
      __init_swait_queue_head(lVar1 + 0x140,"&x->wait",&init_completion___key);
      *(undefined4 *)(lVar1 + 0x118) = 0;
      __init_swait_queue_head(lVar1 + 0x120,"&x->wait",&init_completion___key);
      *(undefined4 *)(lVar1 + 0x18c) = 0;
      *(undefined4 *)(lVar1 + 400) = 0;
      __init_waitqueue_head
                (lVar1 + 0x198,"&channel->intent_req_ack",&qcom_glink_alloc_channel___key_25);
      __init_waitqueue_head
                (lVar1 + 0x1b0,"&channel->intent_req_comp",&qcom_glink_alloc_channel___key_27);
      puVar3 = (undefined8 *)(lVar1 + 0xc0);
      *puVar3 = 0;
      *(undefined4 *)(lVar1 + 0x1c8) = 0;
      *(long *)(lVar1 + 0xe8) = lVar1 + 0xe8;
      *(long *)(lVar1 + 0xf0) = lVar1 + 0xe8;
      *(long *)(lVar1 + 0xf8) = lVar1 + 0xf8;
      *(long *)(lVar1 + 0x100) = lVar1 + 0xf8;
      *(undefined8 *)(lVar1 + 200) = 0;
      *(undefined8 *)(lVar1 + 0xd8) = 0;
      *(undefined8 *)(lVar1 + 0xe0) = 0;
      *puVar3 = puVar3;
      *(undefined8 **)(lVar1 + 200) = puVar3;
      *(undefined8 *)(lVar1 + 0x90) = 0x1000000400000000;
      *(undefined8 *)(lVar1 + 0x98) = 0;
      *(undefined8 *)(lVar1 + 0xa0) = 0;
      *(undefined8 *)(lVar1 + 0xa8) = 0x1000000400000000;
      *(code **)(lVar1 + 0xd0) = qcom_glink_rx_done_work;
      *(undefined8 *)(lVar1 + 0xb0) = 0;
      *(undefined8 *)(lVar1 + 0xb8) = 0;
      *(undefined4 *)(lVar1 + 0x70) = 1;
      return lVar1;
    }
    kfree(lVar1);
  }
  return -0xc;
}



//------------------------------------------------------------
// qcom_glink_rpdev_release @ 00102e10 size=52
// signature: undefined qcom_glink_rpdev_release(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_rpdev_release(long param_1)

{
  kfree(*(undefined8 *)(param_1 + 0x3b8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// qcom_glink_rx_done_work @ 00102e48 size=228
// signature: undefined qcom_glink_rx_done_work(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_rx_done_work(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  undefined8 uVar7;
  long *plVar8;
  long *plVar9;
  
  lVar5 = param_1 + -0x38;
  uVar7 = *(undefined8 *)(param_1 + -0x58);
  uVar3 = _raw_spin_lock_irqsave(lVar5);
  plVar6 = (long *)(param_1 + 0x28);
  if ((long *)*plVar6 != plVar6) {
    plVar8 = (long *)*plVar6;
    do {
      plVar9 = (long *)*plVar8;
      uVar4 = __list_del_entry_valid(plVar8);
      if ((uVar4 & 1) != 0) {
        lVar1 = *plVar8;
        plVar2 = (long *)plVar8[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar8 = -0x2152ffffffffff00;
      plVar8[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar5,uVar3);
      qcom_glink_send_rx_done(uVar7,param_1 + -0xc0,plVar8 + -4,1);
      uVar3 = _raw_spin_lock_irqsave(lVar5);
      plVar8 = plVar9;
    } while (plVar9 != plVar6);
  }
  _raw_spin_unlock_irqrestore(lVar5,uVar3);
  return;
}



//------------------------------------------------------------
// qcom_glink_create_ept @ 00102f30 size=1016
// signature: undefined qcom_glink_create_ept(void)
// callers: []
//------------------------------------------------------------

long * qcom_glink_create_ept(long param_1,long param_2,long param_3,char *param_4)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  long lVar6;
  long lVar7;
  int local_74;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar7 = *(long *)(*(long *)(param_1 + 0x3c8) + 0x68);
  lVar6 = lVar7 + 0x124;
  uVar4 = _raw_spin_lock_irqsave(lVar6);
  local_74 = 0;
  plVar5 = (long *)idr_get_next(lVar7 + 0x140,&local_74);
  if (plVar5 != (long *)0x0) {
    do {
      iVar3 = strcmp((char *)plVar5[0xf],param_4);
      if (iVar3 == 0) {
        _raw_spin_unlock_irqrestore(lVar6,uVar4);
        if (plVar5[0xd] != 0) {
          ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: \n",plVar5[0xf],
                         (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                         "qcom_glink_create_remote");
        }
        iVar3 = qcom_glink_send_open_req(lVar7,plVar5);
        if (iVar3 == 0) {
          iVar3 = wait_for_completion_timeout(plVar5 + 0x23,0x4e2);
          if (iVar3 != 0) goto LAB_001031b4;
          iVar3 = -0x6e;
          lVar6 = plVar5[0xd];
          if (lVar6 != 0) goto LAB_001030d0;
LAB_00103240:
          local_70._0_4_ = CONCAT22((short)plVar5[0x10],3);
          local_70 = (ulong)(uint)local_70;
        }
        else {
          lVar6 = plVar5[0xd];
          if (lVar6 == 0) goto LAB_00103240;
LAB_001030d0:
          ipc_log_string(*(undefined8 *)(lVar6 + 400),"%s[%d:%d] %s: close_link %d\n",plVar5[0xf],
                         (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                         "qcom_glink_create_remote",iVar3);
          local_70._0_4_ = CONCAT22((short)plVar5[0x10],3);
          local_70 = (ulong)(uint)local_70;
          if (plVar5[0xd] != 0) {
            ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: \n",plVar5[0xf],
                           (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                           "qcom_glink_send_close_req");
          }
        }
        qcom_glink_tx(lVar7,&local_70,8,0,0,1);
        goto LAB_001032f4;
      }
      local_74 = local_74 + 1;
      plVar5 = (long *)idr_get_next(lVar7 + 0x140,&local_74);
    } while (plVar5 != (long *)0x0);
  }
  _raw_spin_unlock_irqrestore(lVar6,uVar4);
  plVar5 = (long *)qcom_glink_alloc_channel(lVar7,param_4);
  if (plVar5 < (long *)0xfffffffffffff001) {
    if (plVar5[0xd] != 0) {
      ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: \n",plVar5[0xf],
                     (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                     "qcom_glink_create_local");
    }
    iVar3 = qcom_glink_send_open_req(lVar7,plVar5);
    if (iVar3 == 0) {
      iVar3 = wait_for_completion_timeout(plVar5 + 0x23,0x4e2);
      if ((iVar3 != 0) && (iVar3 = wait_for_completion_timeout(plVar5 + 0x27,0x4e2), iVar3 != 0)) {
LAB_001031b4:
        if (plVar5[0xd] == 0) {
          *plVar5 = param_1;
          plVar5[2] = param_2;
          plVar5[10] = param_3;
          plVar5[0xb] = (long)&glink_endpoint_ops;
        }
        else {
          ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: Initializing ept\n",
                         plVar5[0xf],(int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                         "qcom_glink_create_ept");
          *plVar5 = param_1;
          plVar5[2] = param_2;
          plVar5[10] = param_3;
          plVar5[0xb] = (long)&glink_endpoint_ops;
          if (plVar5[0xd] != 0) {
            ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: Initialized ept\n",
                           plVar5[0xf],(int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                           "qcom_glink_create_ept");
          }
        }
        goto LAB_001032f8;
      }
      if (plVar5[0xd] != 0) {
        ipc_log_string(*(undefined8 *)(plVar5[0xd] + 400),"%s[%d:%d] %s: err_timeout\n",plVar5[0xf],
                       (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                       "qcom_glink_create_local");
      }
      uVar4 = _raw_spin_lock_irqsave(lVar6);
      idr_remove(lVar7 + 0x128,(int)plVar5[0x10]);
      _raw_spin_unlock_irqrestore(lVar6,uVar4);
      lVar6 = plVar5[0xd];
    }
    else {
      lVar6 = plVar5[0xd];
    }
    if (lVar6 != 0) {
      ipc_log_string(*(undefined8 *)(lVar6 + 400),"%s[%d:%d] %s: release_channel\n",plVar5[0xf],
                     (int)plVar5[0x10],*(undefined4 *)((long)plVar5 + 0x84),
                     "qcom_glink_create_local");
    }
    plVar5 = plVar5 + 0xe;
    Hint_Prefetch(plVar5,2,0,1);
    do {
      iVar3 = (int)*plVar5;
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(plVar5,0x10);
      if (bVar2) {
        *(int *)plVar5 = iVar3 + -1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    if (iVar3 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release(plVar5);
    }
    else if (iVar3 < 1) {
      refcount_warn_saturate(plVar5,3);
    }
    Hint_Prefetch(plVar5,2,0,1);
    do {
      iVar3 = (int)*plVar5;
      cVar1 = '\x01';
      bVar2 = (bool)ExclusiveMonitorPass(plVar5,0x10);
      if (bVar2) {
        *(int *)plVar5 = iVar3 + -1;
        cVar1 = ExclusiveMonitorsStatus();
      }
    } while (cVar1 != '\0');
    if (iVar3 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release(plVar5);
    }
    else if (iVar3 < 1) {
      refcount_warn_saturate(plVar5,3);
    }
  }
LAB_001032f4:
  plVar5 = (long *)0x0;
LAB_001032f8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar5;
}



//------------------------------------------------------------
// qcom_glink_announce_create @ 0010334c size=520
// signature: undefined qcom_glink_announce_create(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_announce_create(long param_1)

{
  uint uVar1;
  ulong uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  uint *puVar9;
  int iVar10;
  uint uVar11;
  int local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x3c8);
  uVar8 = *(undefined8 *)(param_1 + 0x2e8);
  lVar7 = *(long *)(lVar6 + 0x68);
  if (lVar7 != 0) {
    ipc_log_string(*(undefined8 *)(lVar7 + 400),"%s[%d:%d] %s: Entered\n",
                   *(undefined8 *)(lVar6 + 0x78),*(undefined4 *)(lVar6 + 0x80),
                   *(undefined4 *)(lVar6 + 0x84),"qcom_glink_announce_create");
  }
  if ((*(char *)(lVar7 + 0x168) != '\0') ||
     (uVar2 = completion_done(lVar6 + 0x118), (uVar2 & 1) == 0)) goto LAB_001034a8;
  lVar5 = lVar6 + 0x88;
  *(undefined1 *)(lVar6 + 0x189) = 1;
  uVar3 = _raw_spin_lock_irqsave(lVar5);
  local_5c = 0;
  lVar4 = idr_get_next(lVar6 + 0x90,&local_5c);
  if (lVar4 != 0) {
    do {
      if ((*(char *)(lVar4 + 0x18) == '\0') && (*(char *)(lVar4 + 0x1a) == '\0')) {
        _raw_spin_unlock_irqrestore(lVar5,uVar3);
        qcom_glink_advertise_intent(lVar7,lVar6,lVar4);
        uVar3 = _raw_spin_lock_irqsave(lVar5);
      }
      local_5c = local_5c + 1;
      lVar4 = idr_get_next(lVar6 + 0x90,&local_5c);
    } while (lVar4 != 0);
  }
  _raw_spin_unlock_irqrestore(lVar5,uVar3);
  lVar5 = of_find_property(uVar8,"qcom,intents",0);
  if (lVar5 == 0) {
    iVar10 = 2;
    puVar9 = &DAT_001075e0;
LAB_00103504:
    do {
      uVar11 = puVar9[1];
      iVar10 = iVar10 + -1;
      if (uVar11 != 0) {
        uVar11 = (uVar11 & 0xff00ff00) >> 8 | (uVar11 & 0xff00ff) << 8;
        uVar11 = uVar11 >> 0x10 | uVar11 << 0x10;
        uVar1 = (*puVar9 & 0xff00ff00) >> 8 | (*puVar9 & 0xff00ff) << 8;
        do {
          lVar5 = qcom_glink_alloc_intent(lVar6,(long)(int)(uVar1 >> 0x10 | uVar1 << 0x10),1);
          if (lVar5 == 0) break;
          uVar11 = uVar11 - 1;
          qcom_glink_advertise_intent(lVar7,lVar6,lVar5);
        } while (uVar11 != 0);
      }
      puVar9 = puVar9 + 2;
    } while (iVar10 != 0);
  }
  else if (7 < *(uint *)(lVar5 + 8)) {
    puVar9 = *(uint **)(lVar5 + 0x10);
    iVar10 = (int)*(uint *)(lVar5 + 8) >> 3;
    goto LAB_00103504;
  }
  if (*(long *)(lVar6 + 0x68) != 0) {
    ipc_log_string(*(undefined8 *)(*(long *)(lVar6 + 0x68) + 400),"%s[%d:%d] %s: Exit\n",
                   *(undefined8 *)(lVar6 + 0x78),*(undefined4 *)(lVar6 + 0x80),
                   *(undefined4 *)(lVar6 + 0x84),"qcom_glink_announce_create");
  }
LAB_001034a8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_glink_send_open_req @ 00103554 size=540
// signature: undefined qcom_glink_send_open_req(void)
// callers: [qcom_glink_create_ept]
//------------------------------------------------------------

int qcom_glink_send_open_req(long param_1,long param_2)

{
  long lVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  size_t sVar6;
  ulong uVar7;
  uint *puVar8;
  undefined8 uVar9;
  char *__string;
  undefined2 local_80;
  undefined2 local_7e;
  int local_7c;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  sVar6 = strlen(*(char **)(param_2 + 0x78));
  puVar8 = (uint *)(param_2 + 0x70);
  do {
    Hint_Prefetch(puVar8,2,0,1);
    do {
      uVar2 = *puVar8;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar8,0x10);
      if (bVar4) {
        *puVar8 = uVar2 + 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar2 == 0) {
      uVar9 = 2;
LAB_00103774:
      refcount_warn_saturate(puVar8,uVar9);
    }
    else if ((int)(uVar2 + 1 | uVar2) < 0) {
      uVar9 = 1;
      goto LAB_00103774;
    }
    lVar1 = param_1 + 0x124;
    uVar9 = _raw_spin_lock_irqsave(lVar1);
    iVar5 = idr_alloc_cyclic(param_1 + 0x128,param_2,1,0x10000,0xa20);
    _raw_spin_unlock_irqrestore(lVar1,uVar9);
    if (iVar5 < 0) goto LAB_001036fc;
    *(int *)(param_2 + 0x80) = iVar5;
    if (*(long *)(param_2 + 0x68) != 0) {
      ipc_log_string(*(undefined8 *)(*(long *)(param_2 + 0x68) + 400),"%s[%d:%d] %s: \n",
                     *(undefined8 *)(param_2 + 0x78),iVar5,*(undefined4 *)(param_2 + 0x84),
                     "qcom_glink_send_open_req");
      iVar5 = *(int *)(param_2 + 0x80);
    }
    local_7e = (undefined2)iVar5;
    __string = *(char **)(param_2 + 0x78);
    local_80 = 2;
    local_7c = (int)sVar6 + 1;
    uVar7 = strnlen(__string,0x20);
    if (uVar7 == 0xffffffffffffffff) {
      fortify_panic("strnlen");
    }
    else {
      if (uVar7 != 0x20) {
        uVar7 = uVar7 + 1;
      }
      if (uVar7 < 0x21) {
        strscpy(&local_78,__string);
        iVar5 = qcom_glink_tx(param_1,&local_80,
                              (long)(((sVar6 >> 3) << 0x23) + 0x1000000000) >> 0x20,0,0,1);
        if (iVar5 != 0) {
          if (*(long *)(param_2 + 0x68) != 0) {
            ipc_log_string(*(undefined8 *)(*(long *)(param_2 + 0x68) + 400),
                           "%s[%d:%d] %s: remote_idr\n",*(undefined8 *)(param_2 + 0x78),
                           *(undefined4 *)(param_2 + 0x80),*(undefined4 *)(param_2 + 0x84),
                           "qcom_glink_send_open_req");
          }
          uVar9 = _raw_spin_lock_irqsave(lVar1);
          idr_remove(param_1 + 0x128,*(undefined4 *)(param_2 + 0x80));
          *(undefined4 *)(param_2 + 0x80) = 0;
          _raw_spin_unlock_irqrestore(lVar1,uVar9);
        }
LAB_001036fc:
        lVar1 = sp_el0;
        if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
          __stack_chk_fail();
        }
        return iVar5;
      }
    }
    puVar8 = (uint *)fortify_panic("strscpy");
  } while( true );
}



//------------------------------------------------------------
// qcom_glink_destroy_ept @ 00103780 size=224
// signature: undefined qcom_glink_destroy_ept(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_destroy_ept(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x74;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + 0x68);
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (*(long *)(param_1 + 0x10) == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
  }
  else {
    *(undefined8 *)(param_1 + 0x10) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    local_40 = (ulong)CONCAT22((short)*(undefined4 *)(param_1 + 0x80),3);
    if (*(long *)(param_1 + 0x68) != 0) {
      ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x68) + 400),"%s[%d:%d] %s: \n",
                     *(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x80),
                     *(undefined4 *)(param_1 + 0x84),"qcom_glink_send_close_req");
    }
    qcom_glink_tx(uVar4,&local_40,8,0,0,1);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_send @ 00103864 size=32
// signature: undefined qcom_glink_send(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_send(void)

{
  __qcom_glink_send();
  return;
}



//------------------------------------------------------------
// qcom_glink_sendto @ 00103888 size=32
// signature: undefined qcom_glink_sendto(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_sendto(void)

{
  __qcom_glink_send();
  return;
}



//------------------------------------------------------------
// qcom_glink_trysend @ 001038ac size=32
// signature: undefined qcom_glink_trysend(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_trysend(void)

{
  __qcom_glink_send();
  return;
}



//------------------------------------------------------------
// qcom_glink_trysendto @ 001038d0 size=32
// signature: undefined qcom_glink_trysendto(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_trysendto(void)

{
  __qcom_glink_send();
  return;
}



//------------------------------------------------------------
// __qcom_glink_send @ 001038f0 size=1544
// signature: undefined __qcom_glink_send(void)
// callers: [qcom_glink_send, qcom_glink_trysend, qcom_glink_trysendto, qcom_glink_sendto]
//------------------------------------------------------------

int __qcom_glink_send(long param_1,long param_2,int param_3,byte param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  long lVar9;
  ulong uVar10;
  undefined8 *puVar11;
  int iVar12;
  undefined8 *puVar13;
  ulong uVar14;
  long lVar15;
  int local_ac;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  puVar13 = *(undefined8 **)(param_1 + 0x68);
  local_ac = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (*(char *)(puVar13 + 0x2d) == '\0') {
    lVar1 = param_1 + 0x88;
    uVar14 = (ulong)param_3;
    lVar2 = param_1 + 0x158;
    lVar3 = param_1 + 0x198;
    lVar4 = param_1 + 0x1b0;
    do {
      uVar8 = _raw_spin_lock_irqsave(lVar1);
      local_ac = 0;
      lVar9 = idr_get_next(param_1 + 0xa8,&local_ac);
      if (lVar9 != 0) {
        lVar15 = 0;
        do {
          uVar10 = *(ulong *)(lVar9 + 0x10);
          if ((uVar14 <= uVar10) && (*(char *)(lVar9 + 0x19) == '\0')) {
            if (lVar15 != 0) {
              if (*(ulong *)(lVar15 + 0x10) <= uVar10) {
                lVar9 = lVar15;
              }
              uVar10 = *(ulong *)(lVar9 + 0x10);
            }
            lVar15 = lVar9;
            if (uVar10 == uVar14) goto LAB_00103c48;
          }
          local_ac = local_ac + 1;
          lVar9 = idr_get_next(param_1 + 0xa8,&local_ac);
        } while (lVar9 != 0);
        if (lVar15 != 0) {
LAB_00103c48:
          *(undefined1 *)(lVar15 + 0x19) = 1;
          _raw_spin_unlock_irqrestore(lVar1,uVar8);
          local_ac = *(int *)(lVar15 + 8);
          puVar11 = *(undefined8 **)(param_1 + 0x68);
          goto LAB_00103c70;
        }
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      if ((*(int *)(puVar13 + 0x2b) != 0) || ((param_4 & 1) == 0)) {
        iVar7 = -0x10;
        if (*(int *)(puVar13 + 0x2b) != 0) {
          iVar7 = -0x68;
        }
        goto LAB_00103e18;
      }
      local_80 = 7;
      mutex_lock(lVar2);
      *(undefined4 *)(param_1 + 0x18c) = 0;
      *(undefined4 *)(param_1 + 400) = 0;
      local_80 = CONCAT44(param_3,CONCAT22((short)*(undefined4 *)(param_1 + 0x80),
                                           (undefined2)local_80));
      if (*(long *)(param_1 + 0x68) != 0) {
        ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x68) + 400),"%s[%d:%d] %s: size:%zd\n",
                       *(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x80),
                       *(undefined4 *)(param_1 + 0x84),"qcom_glink_request_intent",uVar14);
      }
      iVar7 = qcom_glink_tx(puVar13,&local_80,8,0,0,1);
      if (iVar7 == 0) {
        if ((*(int *)(param_1 + 0x18c) == 0) && (*(int *)(puVar13 + 0x2b) == 0)) {
          local_90 = 0;
          uStack_88 = 0;
          local_a0 = 0;
          uStack_98 = 0;
          local_a8 = 0;
          init_wait_entry(&local_a8,0);
          prepare_to_wait_event(lVar3,&local_a8,2);
          if (*(int *)(param_1 + 0x18c) != 0) {
LAB_00103b04:
            finish_wait(lVar3,&local_a8);
            goto LAB_00103b68;
          }
          lVar9 = 0x9c4;
          do {
            if (*(int *)(puVar13 + 0x2b) != 0 && lVar9 == 0) {
              lVar9 = 1;
            }
            if ((*(int *)(puVar13 + 0x2b) != 0) || (lVar9 == 0)) goto LAB_00103b58;
            lVar9 = schedule_timeout(lVar9);
            prepare_to_wait_event(lVar3,&local_a8,2);
          } while (*(int *)(param_1 + 0x18c) == 0);
          if (lVar9 == 0) goto LAB_00103b04;
LAB_00103b58:
          finish_wait(lVar3,&local_a8);
          if ((int)lVar9 != 0) goto LAB_00103b68;
          _dev_err(*puVar13,"%s: intent request ack timed out (%d)\n",
                   *(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x1c8));
          iVar7 = *(int *)(param_1 + 0x1c8) + 1;
          *(int *)(param_1 + 0x1c8) = iVar7;
          if (1 < iVar7) {
            ipc_log_string(puVar13[0x32],
                           "[%s]: WARN at line %d: remoteproc:%s channel:%s unresponsive\n",
                           "qcom_glink_request_intent",0x75e,puVar13[1],
                           *(undefined8 *)(param_1 + 0x78));
            _printk(&DAT_001069b2,"qcom_glink_request_intent",0x75e,puVar13[1],
                    *(undefined8 *)(param_1 + 0x78));
          }
          iVar7 = -0x6e;
        }
        else {
LAB_00103b68:
          if (*(int *)(puVar13 + 0x2b) == 0) {
            if (*(char *)(param_1 + 0x188) != '\0') {
              mutex_unlock(lVar2);
              iVar7 = *(int *)(param_1 + 400);
              goto joined_r0x00103b84;
            }
            iVar7 = -0x7d;
          }
          else {
            if (*(long *)(param_1 + 0x68) != 0) {
              ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x68) + 400),
                             "%s[%d:%d] %s: ssr detected\n",*(undefined8 *)(param_1 + 0x78),
                             *(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84),
                             "qcom_glink_request_intent");
            }
            iVar7 = -0x68;
          }
        }
        mutex_unlock(lVar2);
        goto LAB_00103e18;
      }
      mutex_unlock(lVar2);
      if (iVar7 < 0) goto LAB_00103e18;
      iVar7 = *(int *)(param_1 + 400);
joined_r0x00103b84:
      if ((iVar7 == 0) && (*(int *)(puVar13 + 0x2b) == 0)) {
        local_90 = 0;
        uStack_88 = 0;
        local_a0 = 0;
        uStack_98 = 0;
        local_a8 = 0;
        init_wait_entry(&local_a8,0);
        prepare_to_wait_event(lVar4,&local_a8,2);
        if (*(int *)(param_1 + 400) == 0) {
          lVar9 = 0x9c4;
          do {
            if (lVar9 == 0 && *(int *)(puVar13 + 0x2b) != 0) {
              lVar9 = 1;
            }
            if ((*(int *)(puVar13 + 0x2b) != 0) || (lVar9 == 0)) goto LAB_00103c24;
            lVar9 = schedule_timeout(lVar9);
            prepare_to_wait_event(lVar4,&local_a8,2);
          } while (*(int *)(param_1 + 400) == 0);
          if (lVar9 != 0) {
LAB_00103c24:
            finish_wait(lVar4,&local_a8);
            if ((int)lVar9 != 0) goto LAB_00103c30;
            _dev_err(*puVar13,"intent request completion timed out\n");
            iVar7 = -0x6e;
            goto LAB_00103e18;
          }
        }
        finish_wait(lVar4,&local_a8);
      }
LAB_00103c30:
      if (*(int *)(puVar13 + 0x2b) != 0) {
        if (*(long *)(param_1 + 0x68) != 0) {
          ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x68) + 400),
                         "%s[%d:%d] %s: ssr detected\n",*(undefined8 *)(param_1 + 0x78),
                         *(undefined4 *)(param_1 + 0x80),*(undefined4 *)(param_1 + 0x84),
                         "__qcom_glink_send");
        }
        iVar7 = -0x68;
        goto LAB_00103e18;
      }
    } while (*(char *)(param_1 + 0x188) != '\0');
    iVar7 = -0x7d;
  }
  else {
    lVar15 = 0;
    puVar11 = puVar13;
LAB_00103c70:
    iVar5 = param_3 + -0x2000;
    iVar6 = 0x2000;
    if (((iVar5 != 0 && 0x1fff < param_3) & param_4) == 0) {
      iVar5 = 0;
      iVar6 = param_3;
    }
    local_78._0_4_ = CONCAT22((short)*(undefined4 *)(param_1 + 0x80),9);
    local_78 = CONCAT44(local_ac,(undefined4)local_78);
    uStack_70 = CONCAT44(iVar5,iVar6);
    if (puVar11 != (undefined8 *)0x0) {
      ipc_log_string(puVar11[0x32],"%s[%d:%d] %s: iid:%d chunk_size:%d left_size:%d\n",
                     *(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x80),
                     *(undefined4 *)(param_1 + 0x84),"__qcom_glink_send",local_ac,iVar6,iVar5);
    }
    iVar7 = qcom_glink_tx(puVar13,&local_78,0x10,param_2,(long)iVar6,param_4 & 1);
    while (iVar7 == 0) {
      if (iVar5 < 1) {
        iVar7 = 0;
        goto LAB_00103e18;
      }
      iVar12 = iVar5;
      if (0x1fff < iVar5) {
        iVar12 = 0x2000;
      }
      iVar5 = iVar5 - iVar12;
      local_78._0_4_ = CONCAT22((short)*(undefined4 *)(param_1 + 0x80),0xc);
      local_78 = CONCAT44(local_ac,(undefined4)local_78);
      uStack_70 = CONCAT44(iVar5,iVar12);
      if (*(long *)(param_1 + 0x68) != 0) {
        ipc_log_string(*(undefined8 *)(*(long *)(param_1 + 0x68) + 400),
                       "%s[%d:%d] %s: iid:%d chunk_size:%d left_size:%d\n",
                       *(undefined8 *)(param_1 + 0x78),*(undefined4 *)(param_1 + 0x80),
                       *(undefined4 *)(param_1 + 0x84),"__qcom_glink_send",local_ac,iVar12,iVar5);
      }
      param_2 = param_2 + iVar6;
      iVar7 = qcom_glink_tx(puVar13,&local_78,0x10,param_2,iVar12,param_4 & 1);
      iVar6 = iVar12;
    }
    if (lVar15 != 0) {
      *(undefined1 *)(lVar15 + 0x19) = 0;
    }
  }
LAB_00103e18:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// qcom_glink_advertise_intent @ 00103ef8 size=264
// signature: undefined qcom_glink_advertise_intent(void)
// callers: [qcom_glink_work, qcom_glink_announce_create]
//------------------------------------------------------------

void qcom_glink_advertise_intent(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined2 local_58;
  undefined2 local_56;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  lVar1 = param_2 + 0x88;
  local_48 = *(long *)(lVar2 + 0x638);
  uVar3 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(param_3 + 0x1a) == '\0') {
    *(undefined1 *)(param_3 + 0x1a) = 1;
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
    local_4c = *(undefined4 *)(param_3 + 8);
    local_58 = 5;
    local_56 = (undefined2)*(undefined4 *)(param_2 + 0x80);
    uStack_50 = (undefined4)*(undefined8 *)(param_3 + 0x10);
    local_54 = 1;
    if (*(long *)(param_2 + 0x68) != 0) {
      ipc_log_string(*(undefined8 *)(*(long *)(param_2 + 0x68) + 400),
                     "%s[%d:%d] %s: count:%d size:%zd liid:%d\n",*(undefined8 *)(param_2 + 0x78),
                     *(undefined4 *)(param_2 + 0x80),*(undefined4 *)(param_2 + 0x84),
                     "qcom_glink_advertise_intent",1,*(undefined8 *)(param_3 + 0x10),local_4c);
    }
    qcom_glink_tx(param_1,&local_58,0x10,0,0,1);
  }
  else {
    _raw_spin_unlock_irqrestore(lVar1,uVar3);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_alloc_intent @ 00104000 size=216
// signature: undefined qcom_glink_alloc_intent(void)
// callers: [qcom_glink_work, qcom_glink_announce_create]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * qcom_glink_alloc_intent(long param_1,long param_2,byte param_3)

{
  int iVar1;
  long *plVar2;
  long lVar3;
  undefined8 uVar4;
  
  plVar2 = (long *)kmalloc_trace(_devm_request_threaded_irq,0xdc0,0x30);
  if (plVar2 == (long *)0x0) {
    return (long *)0x0;
  }
  if (param_2 != 0) {
    lVar3 = __kmalloc(param_2,0xdc0);
    *plVar2 = lVar3;
    if (lVar3 == 0) goto LAB_001040b0;
  }
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0x88);
  iVar1 = idr_alloc_cyclic(param_1 + 0x90,plVar2,1,0xffffffff,0xa20);
  _raw_spin_unlock_irqrestore(param_1 + 0x88,uVar4);
  if (-1 < iVar1) {
    *(int *)(plVar2 + 1) = iVar1;
    plVar2[2] = param_2;
    *(byte *)(plVar2 + 3) = param_3 & 1;
    return plVar2;
  }
  kfree(*plVar2);
LAB_001040b0:
  kfree(plVar2);
  return (long *)0x0;
}



//------------------------------------------------------------
// qcom_glink_channel_ref_put @ 001040d8 size=100
// signature: undefined qcom_glink_channel_ref_put(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

void qcom_glink_channel_ref_put(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0x70);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (iVar2 == 1) {
      DataMemoryBarrier(2,1);
      qcom_glink_channel_release();
    }
    else if (iVar2 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return;
}



//------------------------------------------------------------
// rpmsg_name_show @ 00104150 size=152
// signature: undefined rpmsg_name_show(void)
// callers: []
//------------------------------------------------------------

long rpmsg_name_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = of_property_read_string(*(undefined8 *)(param_1 + 0x2e8),"label",&local_30);
  if (iVar2 < 0) {
    local_30 = **(undefined8 **)(param_1 + 0x2e8);
  }
  iVar2 = sysfs_emit(param_3,&DAT_00106e08,local_30);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// qcom_glink_native_rx @ 001041e8 size=5428
// signature: undefined qcom_glink_native_rx(void)
// callers: [qcom_glink_native_intr, qcom_glink_native_thread_intr]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00104ce4) */
/* WARNING: Removing unreachable block (ram,0x00104cd0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_glink_native_rx(undefined8 *param_1,int param_2)

{
  long lVar1;
  undefined8 *puVar2;
  long lVar3;
  int *piVar4;
  undefined8 *puVar5;
  long *plVar6;
  undefined4 uVar7;
  uint uVar8;
  char cVar9;
  undefined2 uVar10;
  code *pcVar11;
  int iVar12;
  int iVar13;
  undefined8 uVar14;
  ulong uVar15;
  undefined8 *puVar16;
  long lVar17;
  long lVar18;
  uint *puVar19;
  long lVar20;
  char *pcVar21;
  undefined8 uVar22;
  uint uVar23;
  long lVar24;
  bool bVar25;
  long *plVar26;
  ulong uVar27;
  ulong uVar28;
  int iVar29;
  long *plVar30;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_88 = 0;
  if (should_wake == '\x01') {
    _printk(&DAT_001070f2,"qcom_glink_native_rx",(long)param_1 + 100);
    should_wake = '\0';
    glink_resume_pkt = '\x01';
    pm_system_wakeup();
  }
  lVar1 = (long)param_1 + 0x84;
  uVar14 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(param_1 + 0x11) == '\0') {
    *(undefined1 *)(param_1 + 0x11) = 1;
    _raw_spin_unlock_irqrestore(lVar1,uVar14);
    __wake_up(param_1 + 0x2e,3,0,0);
    if (-1 < param_2) {
      puVar2 = param_1 + 0x28;
      iVar29 = 0;
      lVar3 = (long)param_1 + 0x124;
      do {
        if (*(int *)(*(code **)(param_1[10] + 8) + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1042c4);
          (*pcVar11)();
        }
        uVar15 = (**(code **)(param_1[10] + 8))();
        uVar15 = uVar15 & 0xffffffff;
        if (uVar15 < 8) break;
        pcVar11 = *(code **)(param_1[10] + 0x10);
        if (*(int *)(pcVar11 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104300);
          (*pcVar11)();
        }
        (*pcVar11)(param_1[10],&local_88,0,8);
        uVar28 = local_88;
        if (0xf < (ushort)local_88) {
          _dev_err(*param_1,"unhandled rx cmd: %d\n");
          break;
        }
        uVar10 = local_88._2_2_;
        uVar23 = local_88._4_4_;
        uVar27 = (ulong)local_88._4_4_;
        switch(local_88 & 0xffff) {
        default:
          uVar27 = 0;
          goto LAB_00104330;
        case 2:
          uVar27 = uVar27 & 0xffff;
LAB_00104330:
          iVar12 = qcom_glink_rx_defer(param_1,uVar27);
          break;
        case 4:
          if (param_1 == (undefined8 *)0x0) {
LAB_00104fb4:
            _dev_err(*param_1,"Invalid open ack packet\n");
            iVar12 = -0x16;
          }
          else {
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            lVar20 = idr_find(param_1 + 0x25,uVar10);
            if (lVar20 == 0) {
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              goto LAB_00104fb4;
            }
            puVar19 = (uint *)(lVar20 + 0x70);
            Hint_Prefetch(puVar19,2,0,1);
            do {
              uVar23 = *puVar19;
              cVar9 = '\x01';
              bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
              if (bVar25) {
                *puVar19 = uVar23 + 1;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            if (uVar23 == 0) {
              uVar22 = 2;
LAB_001055d0:
              refcount_warn_saturate(puVar19,uVar22);
            }
            else if ((int)(uVar23 + 1 | uVar23) < 0) {
              uVar22 = 1;
              goto LAB_001055d0;
            }
            _raw_spin_unlock_irqrestore(lVar3,uVar14);
            if (*(long *)(lVar20 + 0x68) != 0) {
              ipc_log_string(*(undefined8 *)(*(long *)(lVar20 + 0x68) + 400),"%s[%d:%d] %s: \n",
                             *(undefined8 *)(lVar20 + 0x78),*(undefined4 *)(lVar20 + 0x80),
                             *(undefined4 *)(lVar20 + 0x84),"qcom_glink_rx_open_ack");
            }
            complete_all(lVar20 + 0x118);
            Hint_Prefetch(puVar19,2,0,1);
            do {
              uVar23 = *puVar19;
              cVar9 = '\x01';
              bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
              if (bVar25) {
                *puVar19 = uVar23 - 1;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            if (uVar23 == 1) {
              DataMemoryBarrier(2,1);
              qcom_glink_channel_release(puVar19);
            }
            else if ((int)uVar23 < 1) {
              refcount_warn_saturate(puVar19,3);
            }
            iVar12 = 0;
          }
          pcVar11 = *(code **)(param_1[10] + 0x18);
          if (*(int *)(pcVar11 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104b40);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],8);
          break;
        case 5:
          lVar24 = uVar27 * 8;
          uVar28 = lVar24 + 8;
          if (uVar15 < uVar28) goto LAB_00104f8c;
          if (param_1 != (undefined8 *)0x0) {
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            lVar20 = idr_find(puVar2,uVar10);
            if (lVar20 != 0) {
              puVar19 = (uint *)(lVar20 + 0x70);
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar8 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar8 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar8 == 0) {
                uVar22 = 2;
LAB_001054d8:
                refcount_warn_saturate(puVar19,uVar22);
              }
              else if ((int)(uVar8 + 1 | uVar8) < 0) {
                uVar22 = 1;
                goto LAB_001054d8;
              }
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              lVar17 = __kmalloc(uVar28,0xa20);
              if (lVar17 == 0) {
                Hint_Prefetch(puVar19,2,0,1);
                do {
                  uVar23 = *puVar19;
                  cVar9 = '\x01';
                  bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                  if (bVar25) {
                    *puVar19 = uVar23 - 1;
                    cVar9 = ExclusiveMonitorsStatus();
                  }
                } while (cVar9 != '\0');
                if (uVar23 != 1) goto LAB_00104c28;
                DataMemoryBarrier(2,1);
              }
              else {
                pcVar11 = *(code **)(param_1[10] + 0x10);
                if (*(int *)(pcVar11 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104670);
                  (*pcVar11)();
                }
                (*pcVar11)(param_1[10],lVar17,0,uVar28);
                if (uVar23 != 0) {
                  uVar15 = 0;
                  do {
                    lVar18 = kmalloc_trace(_devm_request_threaded_irq,0xb20,0x30);
                    if (lVar18 == 0) break;
                    uVar27 = -(uVar15 >> 0x1f) & 0xfffffff800000000 | uVar15 << 3;
                    if ((uVar28 < uVar27 + 0xc) || (uVar28 - (uVar27 + 0xc) < 4)) {
LAB_001057a8:
                    /* WARNING: Does not return */
                      pcVar11 = (code *)SoftwareBreakpoint(1,0x1057ac);
                      (*pcVar11)();
                    }
                    iVar12 = (int)uVar15;
                    uVar15 = (long)iVar12 * 8 + 0xc;
                    if ((uVar28 < uVar15) || (uVar28 - uVar15 < 4)) goto LAB_001057a8;
                    *(undefined4 *)(lVar18 + 8) = *(undefined4 *)(lVar17 + (long)iVar12 * 8 + 0xc);
                    if ((uVar28 < uVar27 + 8) || (uVar28 - (uVar27 + 8) < 4)) goto LAB_001057a8;
                    uVar27 = uVar27 + 8;
                    if ((uVar28 < uVar27) || (uVar28 - uVar27 < 4)) goto LAB_001057a8;
                    *(ulong *)(lVar18 + 0x10) = (ulong)*(uint *)(uVar27 + lVar17);
                    if (*(long *)(lVar20 + 0x68) != 0) {
                      ipc_log_string(*(undefined8 *)(*(long *)(lVar20 + 0x68) + 400),
                                     "%s[%d:%d] %s: riid:%d size:%zd\n",
                                     *(undefined8 *)(lVar20 + 0x78),*(undefined4 *)(lVar20 + 0x80),
                                     *(undefined4 *)(lVar20 + 0x84),"qcom_glink_handle_intent");
                    }
                    uVar14 = _raw_spin_lock_irqsave(lVar20 + 0x88);
                    iVar13 = idr_alloc(lVar20 + 0xa8,lVar18,*(int *)(lVar18 + 8),
                                       *(int *)(lVar18 + 8) + 1,0xa20);
                    _raw_spin_unlock_irqrestore(lVar20 + 0x88,uVar14);
                    if (iVar13 < 0) {
                      _dev_err(*param_1,"failed to store remote intent\n");
                    }
                    uVar15 = (ulong)(iVar12 + 1U);
                  } while (uVar23 != iVar12 + 1U);
                }
                piVar4 = (int *)(lVar20 + 400);
                Hint_Prefetch(piVar4,2,0,1);
                do {
                  cVar9 = '\x01';
                  bVar25 = (bool)ExclusiveMonitorPass(piVar4,0x10);
                  if (bVar25) {
                    *piVar4 = *piVar4 + 1;
                    cVar9 = ExclusiveMonitorsStatus();
                  }
                } while (cVar9 != '\0');
                __wake_up(lVar20 + 0x1b0,3,1,0);
                kfree(lVar17);
                pcVar11 = *(code **)(param_1[10] + 0x18);
                if (*(int *)(pcVar11 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104bb0);
                  (*pcVar11)();
                }
                (*pcVar11)(param_1[10],lVar24 + 0xfU & 0xffffffff8);
                Hint_Prefetch(puVar19,2,0,1);
                do {
                  uVar23 = *puVar19;
                  cVar9 = '\x01';
                  bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                  if (bVar25) {
                    *puVar19 = uVar23 - 1;
                    cVar9 = ExclusiveMonitorsStatus();
                  }
                } while (cVar9 != '\0');
                if (uVar23 != 1) {
LAB_00104c28:
                  if ((int)uVar23 < 1) {
                    refcount_warn_saturate(puVar19,3);
                  }
                  goto LAB_00104f8c;
                }
                DataMemoryBarrier(2,1);
              }
              qcom_glink_channel_release(puVar19);
              goto LAB_00104f8c;
            }
            _raw_spin_unlock_irqrestore(lVar3,uVar14);
          }
          _dev_err(*param_1,"intents for non-existing channel\n");
          lVar20 = param_1[10];
          uVar15 = lVar24 + 0xfU & 0xffffffff8;
          goto LAB_00104f6c;
        case 6:
          qcom_glink_handle_rx_done(param_1,local_88._2_2_,uVar27,0);
          goto LAB_00104f64;
        case 8:
          if (param_1 != (undefined8 *)0x0) {
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            lVar20 = idr_find(puVar2,uVar10);
            if (lVar20 != 0) {
              puVar19 = (uint *)(lVar20 + 0x70);
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar8 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar8 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar8 == 0) {
                uVar22 = 2;
LAB_00105530:
                refcount_warn_saturate(puVar19,uVar22);
              }
              else if ((int)(uVar8 + 1 | uVar8) < 0) {
                uVar22 = 1;
                goto LAB_00105530;
              }
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              piVar4 = (int *)(lVar20 + 0x18c);
              *(bool *)(lVar20 + 0x188) = uVar23 != 0;
              *(undefined4 *)(lVar20 + 0x1c8) = 0;
              Hint_Prefetch(piVar4,2,0,1);
              do {
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(piVar4,0x10);
                if (bVar25) {
                  *piVar4 = *piVar4 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              __wake_up(lVar20 + 0x198,3,1,0);
              if (*(long *)(lVar20 + 0x68) != 0) {
                ipc_log_string(*(undefined8 *)(*(long *)(lVar20 + 0x68) + 400),"%s[%d:%d] %s: \n",
                               *(undefined8 *)(lVar20 + 0x78),*(undefined4 *)(lVar20 + 0x80),
                               *(undefined4 *)(lVar20 + 0x84),"qcom_glink_handle_intent_req_ack");
              }
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar23 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar23 - 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar23 == 1) {
                DataMemoryBarrier(2,1);
LAB_001045b4:
                qcom_glink_channel_release(puVar19);
              }
              else if ((int)uVar23 < 1) goto LAB_00104b04;
              goto LAB_00104f64;
            }
            _raw_spin_unlock_irqrestore(lVar3,uVar14);
          }
          uVar14 = *param_1;
          pcVar21 = "unable to find channel\n";
          goto LAB_00104f60;
        case 9:
        case 0xc:
          local_80 = 0;
          local_78 = 0;
          if (uVar15 < 0x10) {
LAB_00104498:
            local_78 = 0;
            local_80 = 0;
            goto LAB_00105734;
          }
          pcVar11 = *(code **)(param_1[10] + 0x10);
          if (*(int *)(pcVar11 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104378);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],&local_80,0,0x10);
          iVar12 = (int)local_78;
          uVar28 = local_78 & 0xffffffff;
          if (uVar15 < uVar28 + 0x10) goto LAB_00105734;
          if (param_1 == (undefined8 *)0x0) {
            puVar16 = (undefined8 *)0x0;
            iVar12 = 0;
            bVar25 = true;
          }
          else {
            iVar13 = local_78._4_4_;
            uVar10 = local_80._2_2_;
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            puVar16 = (undefined8 *)idr_find(puVar2,uVar10);
            if (puVar16 == (undefined8 *)0x0) {
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              bVar25 = true;
LAB_0010538c:
              iVar12 = 0;
            }
            else {
              puVar19 = (uint *)(puVar16 + 0xe);
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar23 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar23 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar23 == 0) {
                uVar22 = 2;
LAB_001054f0:
                refcount_warn_saturate(puVar19,uVar22);
              }
              else if ((int)(uVar23 + 1 | uVar23) < 0) {
                uVar22 = 1;
                goto LAB_001054f0;
              }
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              if (puVar16[0xd] != 0) {
                ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                               "%s[%d:%d] %s: chunk_size:%d left_size:%d\n",puVar16[0xf],
                               *(undefined4 *)(puVar16 + 0x10),*(undefined4 *)((long)puVar16 + 0x84)
                               ,"qcom_glink_rx_data",uVar28,iVar13);
              }
              if (*(char *)(param_1 + 0x2d) == '\0') {
                uVar7 = local_80._4_4_;
                uVar14 = _raw_spin_lock_irqsave(puVar16 + 0x11);
                plVar26 = (long *)idr_find(puVar16 + 0x12,uVar7);
                _raw_spin_unlock_irqrestore(puVar16 + 0x11,uVar14);
                if (plVar26 == (long *)0x0) {
                  _dev_err(*param_1,"no intent found for channel %s intent %d",puVar16[0xf],uVar7);
                  bVar25 = false;
                  iVar12 = -2;
                  goto LAB_00105394;
                }
              }
              else {
                plVar26 = (long *)puVar16[0x21];
                if (plVar26 == (long *)0x0) {
                  plVar26 = (long *)kmalloc_trace(_devm_request_threaded_irq,0xb20,0x30);
                  if (plVar26 != (long *)0x0) {
                    uVar15 = (ulong)(uint)(iVar13 + iVar12);
                    lVar20 = __kmalloc(uVar15,0xa20);
                    *plVar26 = lVar20;
                    if (lVar20 != 0) {
                      plVar26[2] = uVar15;
                      *(undefined4 *)((long)plVar26 + 0x1c) = 0;
                      *(undefined4 *)(plVar26 + 1) = 0xbabababa;
                      puVar16[0x21] = plVar26;
                      goto LAB_00104d2c;
                    }
                    kfree(plVar26);
                  }
                  qcom_glink_channel_ref_put(puVar16);
                  goto LAB_00105734;
                }
              }
LAB_00104d2c:
              if (plVar26[2] - (ulong)*(uint *)((long)plVar26 + 0x1c) < uVar28) {
                _dev_err(*param_1,"Insufficient space in intent\n");
              }
              else {
                pcVar11 = *(code **)(param_1[10] + 0x10);
                if (*(int *)(pcVar11 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104d70);
                  (*pcVar11)();
                }
                (*pcVar11)(param_1[10],*plVar26 + (ulong)*(uint *)((long)plVar26 + 0x1c),0x10,uVar28
                          );
                *(int *)((long)plVar26 + 0x1c) = *(int *)((long)plVar26 + 0x1c) + iVar12;
                if (iVar13 == 0) {
                  if (*(char *)(param_1 + 0x2d) == '\0') {
                    uVar14 = _raw_spin_lock_irqsave(puVar16 + 0x11);
                    plVar30 = (long *)puVar16[0x20];
                    plVar6 = plVar26 + 4;
                    uVar15 = __list_add_valid(plVar6,plVar30,puVar16 + 0x1f);
                    if ((uVar15 & 1) != 0) {
                      puVar16[0x20] = plVar6;
                      plVar26[4] = (long)(puVar16 + 0x1f);
                      plVar26[5] = (long)plVar30;
                      *plVar30 = (long)plVar6;
                    }
                    _raw_spin_unlock_irqrestore(puVar16 + 0x11,uVar14);
                  }
                  uVar14 = _raw_spin_lock_irqsave((long)puVar16 + 0x74);
                  pcVar11 = (code *)puVar16[2];
                  if (pcVar11 == (code *)0x0) {
                    if (puVar16[0xd] != 0) {
                      ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                                     "%s[%d:%d] %s: callback not present\n",puVar16[0xf],
                                     *(undefined4 *)(puVar16 + 0x10),
                                     *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_rx_data");
                      iVar12 = ___ratelimit(qcom_glink_rx_data__rs_64,"qcom_glink_rx_data");
                      if (iVar12 != 0) {
                        _dev_err(*(undefined8 *)puVar16[0xd],"[%s]: callback not present\n",
                                 "qcom_glink_rx_data");
                      }
                    }
                    iVar12 = 0;
                  }
                  else {
                    if (*(int *)(pcVar11 + -4) != 0x505af011) {
                    /* WARNING: Does not return */
                      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104e9c);
                      (*pcVar11)();
                    }
                    iVar12 = (*pcVar11)(*puVar16,*plVar26,*(undefined4 *)((long)plVar26 + 0x1c),
                                        puVar16[10],0xffffffff);
                    if (((iVar12 < 0) && (iVar12 != -0x13)) && (puVar16[0xd] != 0)) {
                      ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                                     "%s[%d:%d] %s: callback error ret = %d\n",puVar16[0xf],
                                     *(undefined4 *)(puVar16 + 0x10),
                                     *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_rx_data",
                                     iVar12);
                      iVar13 = ___ratelimit(qcom_glink_rx_data__rs,"qcom_glink_rx_data");
                      if (iVar13 != 0) {
                        _dev_err(*(undefined8 *)puVar16[0xd],"[%s]: callback error ret = %d\n",
                                 "qcom_glink_rx_data",iVar12);
                      }
                    }
                  }
                  _raw_spin_unlock_irqrestore((long)puVar16 + 0x74,uVar14);
                  if (glink_resume_pkt == '\x01') {
                    glink_resume_pkt = '\0';
                    _printk(&DAT_00106ace,puVar16[0xf],*(undefined4 *)(puVar16 + 0x10),
                            *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_rx_data",
                            *(undefined4 *)((long)plVar26 + 0x1c));
                  }
                  *(undefined4 *)((long)plVar26 + 0x1c) = 0;
                  puVar16[0x21] = 0;
                  if (((*(byte *)(puVar16[0xd] + 0x160) >> 3 & 1) == 0) || (iVar12 != 1)) {
                    __qcom_glink_rx_done(param_1,puVar16,plVar26);
                  }
                  bVar25 = false;
                  goto LAB_0010538c;
                }
              }
              bVar25 = false;
              iVar12 = 0;
            }
          }
LAB_00105394:
          pcVar11 = *(code **)(param_1[10] + 0x18);
          if (*(int *)(pcVar11 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1053bc);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],uVar28 + 0x17 & 0x1fffffff8);
          if (!bVar25) {
            piVar4 = (int *)(puVar16 + 0xe);
            Hint_Prefetch(piVar4,2,0,1);
            do {
              iVar13 = *piVar4;
              cVar9 = '\x01';
              bVar25 = (bool)ExclusiveMonitorPass(piVar4,0x10);
              if (bVar25) {
                *piVar4 = iVar13 + -1;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            if (iVar13 == 1) {
              DataMemoryBarrier(2,1);
              qcom_glink_channel_release();
            }
            else if (iVar13 < 1) {
              refcount_warn_saturate(piVar4,3);
              if (iVar12 == 0) goto LAB_00104f8c;
              goto LAB_00105734;
            }
          }
          break;
        case 10:
          local_78 = 0;
          local_70 = 0;
          local_80 = 0;
          if (uVar15 < 0x18) goto LAB_00104498;
          pcVar11 = *(code **)(param_1[10] + 0x10);
          if (*(int *)(pcVar11 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1048d8);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],&local_80,0,0x18);
          puVar16 = (undefined8 *)0x0;
          if ((param_1 != (undefined8 *)0x0) && (*(char *)(param_1 + 0x2d) == '\0')) {
            uVar10 = local_80._2_2_;
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            puVar16 = (undefined8 *)idr_find(puVar2,uVar10);
            if (puVar16 == (undefined8 *)0x0) {
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
            }
            else {
              puVar19 = (uint *)(puVar16 + 0xe);
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar23 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar23 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar23 == 0) {
                uVar22 = 2;
LAB_001056d0:
                refcount_warn_saturate(puVar19,uVar22);
              }
              else if ((int)(uVar23 + 1 | uVar23) < 0) {
                uVar22 = 1;
                goto LAB_001056d0;
              }
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              puVar5 = puVar16 + 0x11;
              uVar7 = local_80._4_4_;
              uVar14 = _raw_spin_lock_irqsave(puVar5);
              plVar26 = (long *)idr_find(puVar16 + 0x12,uVar7);
              _raw_spin_unlock_irqrestore(puVar5,uVar14);
              uVar14 = local_70;
              if (plVar26 == (long *)0x0) {
                if (puVar16[0xd] != 0) {
                  ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                                 "%s[%d:%d] %s: no intent found liid:%d\n",puVar16[0xf],
                                 *(undefined4 *)(puVar16 + 0x10),
                                 *(undefined4 *)((long)puVar16 + 0x84),
                                 "qcom_glink_rx_data_zero_copy",uVar7);
                  iVar12 = ___ratelimit(qcom_glink_rx_data_zero_copy__rs,
                                        "qcom_glink_rx_data_zero_copy");
                  if (iVar12 != 0) {
                    _dev_err(*(undefined8 *)puVar16[0xd],"[%s]: no intent found liid:%d\n",
                             "qcom_glink_rx_data_zero_copy",uVar7);
                  }
                }
              }
              else if (plVar26[2] == 0) {
                uVar7 = local_78._4_4_;
                lVar20 = qcom_glink_prepare_da_for_cpu(local_70,local_78._4_4_);
                lVar24 = puVar16[0xd];
                if (lVar20 == 0) {
                  if (lVar24 != 0) {
                    ipc_log_string(*(undefined8 *)(lVar24 + 400),
                                   "%s[%d:%d] %s: failed to get va da:0x%llx len:%d\n",puVar16[0xf],
                                   *(undefined4 *)(puVar16 + 0x10),
                                   *(undefined4 *)((long)puVar16 + 0x84),
                                   "qcom_glink_rx_data_zero_copy",uVar14,uVar7);
                    iVar12 = ___ratelimit(qcom_glink_rx_data_zero_copy__rs_73,
                                          "qcom_glink_rx_data_zero_copy");
                    if (iVar12 != 0) {
                      _dev_err(*(undefined8 *)puVar16[0xd],
                               "[%s]: failed to get va da:0x%llx len:%d\n",
                               "qcom_glink_rx_data_zero_copy",uVar14,uVar7);
                    }
                  }
                }
                else {
                  if (lVar24 != 0) {
                    ipc_log_string(*(undefined8 *)(lVar24 + 400),
                                   "%s[%d:%d] %s: da:0x%llx va:0x%llx len:%d\n",puVar16[0xf],
                                   *(undefined4 *)(puVar16 + 0x10),
                                   *(undefined4 *)((long)puVar16 + 0x84),
                                   "qcom_glink_rx_data_zero_copy",uVar14,lVar20,uVar7);
                  }
                  *plVar26 = lVar20;
                  *(undefined4 *)((long)plVar26 + 0x1c) = uVar7;
                  uVar14 = _raw_spin_lock_irqsave(puVar5);
                  plVar30 = (long *)puVar16[0x20];
                  plVar6 = plVar26 + 4;
                  uVar15 = __list_add_valid(plVar6,plVar30,puVar16 + 0x1f);
                  if ((uVar15 & 1) != 0) {
                    puVar16[0x20] = plVar6;
                    plVar26[4] = (long)(puVar16 + 0x1f);
                    plVar26[5] = (long)plVar30;
                    *plVar30 = (long)plVar6;
                  }
                  _raw_spin_unlock_irqrestore(puVar5,uVar14);
                  uVar14 = _raw_spin_lock_irqsave((long)puVar16 + 0x74);
                  pcVar11 = (code *)puVar16[2];
                  if (pcVar11 == (code *)0x0) {
                    if (puVar16[0xd] != 0) {
                      ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                                     "%s[%d:%d] %s: callback not present\n",puVar16[0xf],
                                     *(undefined4 *)(puVar16 + 0x10),
                                     *(undefined4 *)((long)puVar16 + 0x84),
                                     "qcom_glink_rx_data_zero_copy");
                      iVar12 = ___ratelimit(qcom_glink_rx_data_zero_copy__rs_77,
                                            "qcom_glink_rx_data_zero_copy");
                      if (iVar12 != 0) {
                        _dev_err(*(undefined8 *)puVar16[0xd],"[%s]: callback not present\n",
                                 "qcom_glink_rx_data_zero_copy");
                      }
                    }
LAB_001052e0:
                    iVar12 = 0;
                  }
                  else {
                    if (*(int *)(pcVar11 + -4) != 0x505af011) {
                    /* WARNING: Does not return */
                      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x1050b4);
                      (*pcVar11)();
                    }
                    iVar12 = (*pcVar11)(*puVar16,*plVar26,*(undefined4 *)((long)plVar26 + 0x1c),
                                        puVar16[10],0xffffffff);
                    if ((iVar12 < 0) && (iVar12 != -0x13)) {
                      if (puVar16[0xd] != 0) {
                        ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                                       "%s[%d:%d] %s: callback error ret = %d\n",puVar16[0xf],
                                       *(undefined4 *)(puVar16 + 0x10),
                                       *(undefined4 *)((long)puVar16 + 0x84),
                                       "qcom_glink_rx_data_zero_copy",iVar12);
                        iVar13 = ___ratelimit(qcom_glink_rx_data_zero_copy__rs_76,
                                              "qcom_glink_rx_data_zero_copy");
                        if (iVar13 != 0) {
                          _dev_err(*(undefined8 *)puVar16[0xd],"[%s]: callback error ret = %d\n",
                                   "qcom_glink_rx_data_zero_copy",iVar12);
                        }
                      }
                      goto LAB_001052e0;
                    }
                  }
                  _raw_spin_unlock_irqrestore((long)puVar16 + 0x74,uVar14);
                  if (glink_resume_pkt == '\x01') {
                    glink_resume_pkt = '\0';
                    _printk(&DAT_00106ace,puVar16[0xf],*(undefined4 *)(puVar16 + 0x10),
                            *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_rx_data_zero_copy",
                            *(undefined4 *)((long)plVar26 + 0x1c));
                  }
                  *(undefined4 *)((long)plVar26 + 0x1c) = 0;
                  if (((*(byte *)(puVar16[0xd] + 0x160) >> 3 & 1) == 0) || (iVar12 != 1)) {
                    __qcom_glink_rx_done(param_1,puVar16,plVar26);
                  }
                }
              }
              else if (puVar16[0xd] != 0) {
                ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),
                               "%s[%d:%d] %s: zero copy req wrong intent liid:%d size:%d\n",
                               puVar16[0xf],*(undefined4 *)(puVar16 + 0x10),
                               *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_rx_data_zero_copy",
                               uVar7);
                iVar12 = ___ratelimit(qcom_glink_rx_data_zero_copy__rs_70,
                                      "qcom_glink_rx_data_zero_copy");
                if (iVar12 != 0) {
                  _dev_err(*(undefined8 *)puVar16[0xd],
                           "[%s]: zero copy req wrong intent liid:%d size:%d\n",
                           "qcom_glink_rx_data_zero_copy",uVar7,plVar26[2]);
                }
              }
            }
          }
          pcVar11 = *(code **)(param_1[10] + 0x18);
          if (*(int *)(pcVar11 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104c94);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],0x18);
          if (puVar16 != (undefined8 *)0x0) {
            piVar4 = (int *)(puVar16 + 0xe);
            Hint_Prefetch(piVar4,2,0,1);
            do {
              iVar12 = *piVar4;
              cVar9 = '\x01';
              bVar25 = (bool)ExclusiveMonitorPass(piVar4,0x10);
              if (bVar25) {
                *piVar4 = iVar12 + -1;
                cVar9 = ExclusiveMonitorsStatus();
              }
            } while (cVar9 != '\0');
            if (iVar12 == 1) {
              DataMemoryBarrier(2,1);
              qcom_glink_channel_release();
            }
            else if (iVar12 < 1) {
              refcount_warn_saturate(piVar4,3);
            }
          }
          goto LAB_00104f8c;
        case 0xd:
          pcVar11 = *(code **)(param_1[10] + 0x18);
          if (*(int *)(pcVar11 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10488c);
            (*pcVar11)();
          }
          (*pcVar11)(param_1[10],8);
          mbox_send_message(param_1[9],0);
          mbox_client_txdone(param_1[9],0);
          goto LAB_00104f8c;
        case 0xe:
          qcom_glink_handle_rx_done(param_1,local_88._2_2_,uVar27,1);
          goto LAB_00104f64;
        case 0xf:
          if (param_1 != (undefined8 *)0x0) {
            uVar14 = _raw_spin_lock_irqsave(lVar3);
            puVar16 = (undefined8 *)idr_find(puVar2,uVar10);
            if (puVar16 != (undefined8 *)0x0) {
              puVar19 = (uint *)(puVar16 + 0xe);
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar8 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar8 + 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar8 == 0) {
                uVar22 = 2;
LAB_0010558c:
                refcount_warn_saturate(puVar19,uVar22);
              }
              else if ((int)(uVar8 + 1 | uVar8) < 0) {
                uVar22 = 1;
                goto LAB_0010558c;
              }
              _raw_spin_unlock_irqrestore(lVar3,uVar14);
              uVar8 = uVar23 | 0x100;
              if (-1 < (long)uVar28) {
                uVar8 = uVar23;
              }
              uVar7 = *(undefined4 *)(puVar16 + 0x3a);
              *(uint *)(puVar16 + 0x3a) =
                   uVar8 >> 0x17 & 0x40 | uVar8 & 0xfff |
                   uVar8 >> 0x19 & 0x20 | uVar8 >> 0x15 & 0x80;
              if (puVar16[0xd] != 0) {
                ipc_log_string(*(undefined8 *)(puVar16[0xd] + 400),"%s[%d:%d] %s: old:%d new:%d\n",
                               puVar16[0xf],*(undefined4 *)(puVar16 + 0x10),
                               *(undefined4 *)((long)puVar16 + 0x84),"qcom_glink_handle_signals",
                               uVar7);
              }
              pcVar11 = (code *)puVar16[0x3b];
              if (pcVar11 != (code *)0x0) {
                if (*(int *)(pcVar11 + -4) != -0x28f03d04) {
                    /* WARNING: Does not return */
                  pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10458c);
                  (*pcVar11)();
                }
                (*pcVar11)(*puVar16,puVar16[10],uVar7,*(undefined4 *)(puVar16 + 0x3a));
              }
              Hint_Prefetch(puVar19,2,0,1);
              do {
                uVar23 = *puVar19;
                cVar9 = '\x01';
                bVar25 = (bool)ExclusiveMonitorPass(puVar19,0x10);
                if (bVar25) {
                  *puVar19 = uVar23 - 1;
                  cVar9 = ExclusiveMonitorsStatus();
                }
              } while (cVar9 != '\0');
              if (uVar23 == 1) {
                DataMemoryBarrier(2,1);
                goto LAB_001045b4;
              }
              if (0 < (int)uVar23) goto LAB_00104f64;
LAB_00104b04:
              refcount_warn_saturate(puVar19,3);
              goto LAB_00104f64;
            }
            _raw_spin_unlock_irqrestore(lVar3,uVar14);
          }
          uVar14 = *param_1;
          pcVar21 = "signal for non-existing channel\n";
LAB_00104f60:
          _dev_err(uVar14,pcVar21);
LAB_00104f64:
          lVar20 = param_1[10];
          uVar15 = 8;
LAB_00104f6c:
          if (*(int *)(*(code **)(lVar20 + 0x18) + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
            pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x104f88);
            (*pcVar11)();
          }
          (**(code **)(lVar20 + 0x18))(lVar20,uVar15);
          goto LAB_00104f8c;
        }
        if (iVar12 != 0) break;
LAB_00104f8c:
        iVar29 = iVar29 + 1;
      } while ((param_2 == 0) || (iVar29 < param_2));
    }
LAB_00105734:
    uVar14 = _raw_spin_lock_irqsave(lVar1);
    *(undefined1 *)(param_1 + 0x11) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar14);
    if (*(int *)(*(code **)(param_1[10] + 8) + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x10576c);
      (*pcVar11)();
    }
    uVar14 = (**(code **)(param_1[10] + 8))();
  }
  else {
    _raw_spin_unlock_irqrestore(lVar1,uVar14);
    uVar14 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar14);
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_rx_defer @ 001057b0 size=340
// signature: undefined qcom_glink_rx_defer(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_glink_rx_defer(long param_1,long param_2)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 uVar3;
  long *plVar4;
  code *pcVar5;
  ulong uVar6;
  undefined8 *puVar7;
  
  uVar6 = param_2 + 7U & 0xfffffffffffffff8;
  pcVar5 = *(code **)(*(long *)(param_1 + 0x50) + 8);
  if (*(int *)(pcVar5 + -4) != 0xab0952e) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1057f8);
    (*pcVar5)();
  }
  uVar2 = (*pcVar5)();
  uVar1 = uVar6 + 8;
  if (uVar2 < uVar1) {
    uVar3 = 0xfffffffa;
  }
  else {
    plVar4 = (long *)__kmalloc(uVar6 + 0x18,0xb20);
    if (plVar4 == (long *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      *plVar4 = (long)plVar4;
      plVar4[1] = (long)plVar4;
      pcVar5 = *(code **)(*(long *)(param_1 + 0x50) + 0x10);
      if (*(int *)(pcVar5 + -4) != -0x3ac0e644) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x105858);
        (*pcVar5)();
      }
      (*pcVar5)(*(long *)(param_1 + 0x50),plVar4 + 2,0,uVar1);
      uVar3 = _raw_spin_lock_irqsave(param_1 + 0x108);
      puVar7 = *(undefined8 **)(param_1 + 0x118);
      uVar6 = __list_add_valid(plVar4,puVar7,param_1 + 0x110);
      if ((uVar6 & 1) != 0) {
        *(long **)(param_1 + 0x118) = plVar4;
        *plVar4 = param_1 + 0x110;
        plVar4[1] = (long)puVar7;
        *puVar7 = plVar4;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x108,uVar3);
      queue_work_on(0x20,_system_highpri_wq,param_1 + 0xd8);
      pcVar5 = *(code **)(*(long *)(param_1 + 0x50) + 0x18);
      if (*(int *)(pcVar5 + -4) != -0x8ee255f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1058d8);
        (*pcVar5)();
      }
      (*pcVar5)(*(long *)(param_1 + 0x50),uVar1);
      uVar3 = 0;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// qcom_glink_handle_rx_done @ 00105904 size=504
// signature: undefined qcom_glink_handle_rx_done(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

void qcom_glink_handle_rx_done
               (undefined8 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  long lVar1;
  uint *puVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  
  if (param_1 == (undefined8 *)0x0) {
LAB_00105a34:
    _dev_err(*param_1,"invalid channel id received\n");
    return;
  }
  lVar1 = (long)param_1 + 0x124;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar6 = idr_find(param_1 + 0x28,param_2);
  if (lVar6 == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    goto LAB_00105a34;
  }
  puVar2 = (uint *)(lVar6 + 0x70);
  Hint_Prefetch(puVar2,2,0,1);
  do {
    uVar9 = *puVar2;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
    if (bVar4) {
      *puVar2 = uVar9 + 1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (uVar9 == 0) {
    uVar8 = 2;
LAB_00105aa4:
    refcount_warn_saturate(puVar2,uVar8);
  }
  else if ((int)(uVar9 + 1 | uVar9) < 0) {
    uVar8 = 1;
    goto LAB_00105aa4;
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  lVar1 = lVar6 + 0x88;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  lVar7 = idr_find(lVar6 + 0xa8,param_3);
  if (lVar7 == 0) {
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    _dev_err(*param_1,"invalid intent id received\n");
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar9 = *puVar2;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = uVar9 - 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar9 == 1) {
      DataMemoryBarrier(2,1);
      goto LAB_00105a1c;
    }
  }
  else {
    *(undefined1 *)(lVar7 + 0x19) = 0;
    if (*(long *)(lVar6 + 0x68) != 0) {
      ipc_log_string(*(undefined8 *)(*(long *)(lVar6 + 0x68) + 400),
                     "%s[%d:%d] %s: reuse:%d iid:%d\n",*(undefined8 *)(lVar6 + 0x78),
                     *(undefined4 *)(lVar6 + 0x80),*(undefined4 *)(lVar6 + 0x84),
                     "qcom_glink_handle_rx_done",param_4 & 1,*(undefined4 *)(lVar7 + 8));
    }
    if ((param_4 & 1) == 0) {
      idr_remove(lVar6 + 0xa8,*(undefined4 *)(lVar7 + 8));
      kfree(lVar7);
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      uVar9 = *puVar2;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = uVar9 - 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    if (uVar9 == 1) {
      DataMemoryBarrier(2,1);
LAB_00105a1c:
      qcom_glink_channel_release(puVar2);
      return;
    }
  }
  if ((int)uVar9 < 1) {
    refcount_warn_saturate(puVar2,3);
    return;
  }
  return;
}



//------------------------------------------------------------
// __qcom_glink_rx_done @ 00105b28 size=308
// signature: undefined __qcom_glink_rx_done(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

void __qcom_glink_rx_done(long param_1,long param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  long *plVar7;
  
  if (*(char *)(param_1 + 0x168) == '\0') {
    if (*(char *)(param_3 + 3) == '\0') {
      uVar4 = _raw_spin_lock_irqsave(param_2 + 0x88);
      idr_remove(param_2 + 0x90,*(undefined4 *)(param_3 + 1));
      _raw_spin_unlock_irqrestore(param_2 + 0x88,uVar4);
    }
    uVar4 = _raw_spin_lock_irqsave(param_2 + 0x88);
    puVar1 = param_3 + 4;
    uVar5 = __list_del_entry_valid(puVar1);
    if ((uVar5 & 1) != 0) {
      lVar2 = param_3[4];
      plVar6 = (long *)param_3[5];
      *(long **)(lVar2 + 8) = plVar6;
      *plVar6 = lVar2;
    }
    param_3[4] = 0xdead000000000100;
    param_3[5] = 0xdead000000000122;
    plVar6 = (long *)(param_2 + 0xe8);
    if (((long *)*plVar6 != plVar6) ||
       (iVar3 = qcom_glink_send_rx_done(param_1,param_2,param_3,0), iVar3 != 0)) {
      plVar7 = *(long **)(param_2 + 0xf0);
      uVar5 = __list_add_valid(puVar1,plVar7,plVar6);
      if ((uVar5 & 1) != 0) {
        *(undefined8 **)(param_2 + 0xf0) = puVar1;
        param_3[4] = plVar6;
        param_3[5] = plVar7;
        *plVar7 = (long)puVar1;
      }
      kthread_queue_work(param_1 + 0x90,param_2 + 0xc0);
    }
    _raw_spin_unlock_irqrestore(param_2 + 0x88,uVar4);
  }
  else {
    kfree(*param_3);
    kfree(param_3);
  }
  return;
}



//------------------------------------------------------------
// qcom_glink_device_release @ 00105c60 size=128
// signature: undefined qcom_glink_device_release(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_device_release(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  
  piVar1 = (int *)(*(long *)(param_1 + 0x3c8) + 0x70);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  if (iVar2 == 1) {
    DataMemoryBarrier(2,1);
    qcom_glink_channel_release();
  }
  else if (iVar2 < 1) {
    refcount_warn_saturate(piVar1,3);
  }
  kfree(*(undefined8 *)(param_1 + 0x3b8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// qcom_glink_ssr_notify @ 00105cf4 size=44
// signature: undefined qcom_glink_ssr_notify(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_ssr_notify(undefined8 param_1)

{
  blocking_notifier_call_chain(&ssr_notifiers,0,param_1);
  return;
}



//------------------------------------------------------------
// qcom_glink_ssr_probe @ 00105d24 size=132
// signature: undefined qcom_glink_ssr_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_ssr_probe(long param_1)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  
  plVar1 = (long *)devm_kmalloc(param_1,0x50,0xdc0);
  if (plVar1 == (long *)0x0) {
    uVar2 = 0xfffffff4;
  }
  else {
    *(undefined4 *)(plVar1 + 6) = 0;
    __init_swait_queue_head(plVar1 + 7,"&x->wait",&init_completion___key);
    lVar3 = *(long *)(param_1 + 0x3c8);
    *plVar1 = param_1;
    plVar1[1] = lVar3;
    plVar1[2] = (long)qcom_glink_ssr_notifier_call;
    *(long **)(param_1 + 0x98) = plVar1;
    uVar2 = blocking_notifier_chain_register(&ssr_notifiers);
  }
  return uVar2;
}



//------------------------------------------------------------
// qcom_glink_ssr_remove @ 00105dac size=44
// signature: undefined qcom_glink_ssr_remove(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_ssr_remove(long param_1)

{
  blocking_notifier_chain_unregister(&ssr_notifiers,*(long *)(param_1 + 0x98) + 0x10);
  return;
}



//------------------------------------------------------------
// qcom_glink_ssr_callback @ 00105ddc size=132
// signature: undefined qcom_glink_ssr_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_ssr_callback(long param_1,int *param_2,uint param_3)

{
  undefined8 uVar1;
  char *pcVar2;
  undefined8 *puVar3;
  
  puVar3 = *(undefined8 **)(param_1 + 0x98);
  if (param_3 < 0xc) {
    uVar1 = *puVar3;
    pcVar2 = "message too short\n";
LAB_00105e44:
    _dev_err(uVar1,pcVar2);
    uVar1 = 0xffffffea;
  }
  else {
    if (*param_2 != 0) {
      return 0xffffffea;
    }
    if (param_2[1] == 1) {
      if (param_2[2] != *(int *)(puVar3 + 5)) {
        uVar1 = *puVar3;
        pcVar2 = "invalid sequence number of response\n";
        goto LAB_00105e44;
      }
      complete(puVar3 + 6);
    }
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_glink_ssr_notifier_call @ 00105e64 size=268
// signature: undefined qcom_glink_ssr_notifier_call(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_glink_ssr_notifier_call(long param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  size_t __n;
  long lVar2;
  int iVar3;
  size_t sVar4;
  undefined8 uVar5;
  undefined8 local_78;
  undefined8 local_70;
  long local_68 [5];
  
  lVar2 = sp_el0;
  local_68[4] = *(long *)(lVar2 + 0x638);
  *(undefined4 *)(param_1 + 0x20) = 0;
  local_78 = 0;
  local_68[0] = 0;
  local_68[1] = 0;
  local_68[2] = 0;
  local_68[3] = 0;
  uVar1 = *(int *)(param_1 + 0x18) + 1;
  *(uint *)(param_1 + 0x18) = uVar1;
  local_70 = (ulong)uVar1;
  sVar4 = strlen(param_3);
  __n = sVar4;
  if (0x1e < sVar4) {
    __n = 0x1f;
  }
  local_70 = CONCAT44((int)sVar4,(undefined4)local_70);
  memcpy(local_68,param_3,__n);
  uVar5 = *(undefined8 *)(param_1 + -8);
  *(undefined1 *)((long)local_68 + __n) = 0;
  iVar3 = rpmsg_send(uVar5,&local_78,0x30);
  if (iVar3 < 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x10),"failed to send cleanup message\n");
  }
  iVar3 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x20),0xfa);
  if (iVar3 == 0) {
    _dev_err(*(undefined8 *)(param_1 + -0x10),"timeout waiting for cleanup done message\n");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68[4]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_glink_mem_entry_init @ 00105f74 size=200
// signature: undefined qcom_glink_mem_entry_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
qcom_glink_mem_entry_init
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
          undefined4 param_5)

{
  undefined8 *puVar1;
  undefined *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  ulong uVar5;
  
  puVar3 = (undefined8 *)kmalloc_trace(_devm_request_threaded_irq,0xdc0,0x38);
  if (puVar3 != (undefined8 *)0x0) {
    *(undefined4 *)(puVar3 + 4) = param_5;
    puVar1 = puVar3 + 5;
    *puVar3 = param_1;
    puVar3[1] = param_2;
    puVar3[2] = param_3;
    puVar3[3] = param_4;
    puVar3[5] = puVar1;
    puVar3[6] = puVar1;
    uVar4 = _raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
    puVar2 = PTR_qcom_glink_mem_entries_00107520;
    uVar5 = __list_add_valid(puVar1,PTR_qcom_glink_mem_entries_00107520,&qcom_glink_mem_entries);
    if ((uVar5 & 1) != 0) {
      PTR_qcom_glink_mem_entries_00107520 = (undefined *)puVar1;
      puVar3[5] = &qcom_glink_mem_entries;
      puVar3[6] = puVar2;
      *(undefined8 **)puVar2 = puVar1;
    }
    _raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock,uVar4);
  }
  return puVar3;
}



//------------------------------------------------------------
// qcom_glink_mem_entry_free @ 00106040 size=156
// signature: undefined qcom_glink_mem_entry_free(void)
// callers: []
//------------------------------------------------------------

void qcom_glink_mem_entry_free(undefined **param_1)

{
  undefined *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  
  uVar3 = _raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
  ppuVar5 = &qcom_glink_mem_entries;
  do {
    ppuVar5 = (undefined **)*ppuVar5;
    if (ppuVar5 == &qcom_glink_mem_entries) goto LAB_001060b4;
  } while (ppuVar5 + -5 != param_1);
  uVar4 = __list_del_entry_valid(param_1 + 5);
  if ((uVar4 & 1) != 0) {
    puVar1 = param_1[5];
    plVar2 = (long *)param_1[6];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  param_1[5] = (undefined *)0xdead000000000100;
  param_1[6] = (undefined *)0xdead000000000122;
LAB_001060b4:
  _raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock,uVar3);
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// qcom_glink_prepare_da_for_cpu @ 001060e0 size=180
// signature: undefined qcom_glink_prepare_da_for_cpu(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

undefined * qcom_glink_prepare_da_for_cpu(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  
  uVar2 = _raw_spin_lock_irqsave(&qcom_glink_mem_entry_lock);
  ppuVar3 = (undefined **)qcom_glink_mem_entries;
  do {
    if (ppuVar3 == &qcom_glink_mem_entries) {
      puVar4 = (undefined *)0x0;
LAB_0010616c:
      _raw_spin_unlock_irqrestore(&qcom_glink_mem_entry_lock,uVar2);
      return puVar4;
    }
    if (((ppuVar3[-4] != (undefined *)0x0) &&
        (uVar1 = (int)param_1 - *(int *)(ppuVar3 + -1), -1 < (int)uVar1)) &&
       ((undefined *)(param_2 + (ulong)uVar1) <= ppuVar3[-2])) {
      puVar4 = ppuVar3[-4] + uVar1;
      dma_sync_single_for_cpu(ppuVar3[-5],param_1,param_2,2);
      goto LAB_0010616c;
    }
    ppuVar3 = (undefined **)*ppuVar3;
  } while( true );
}



//------------------------------------------------------------
// init_module @ 001075f4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __register_rpmsg_driver(&qcom_glink_ssr_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00107624 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_rpmsg_driver(&qcom_glink_ssr_driver);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_glink_prepare_da_for_cpu, qcom_glink_destroy_ept, qcom_glink_mem_entry_init, qcom_glink_rx_defer, qcom_glink_work, qcom_glink_rx_done, qcom_glink_tx, qcom_glink_alloc_intent, qcom_glink_handle_rx_done, qcom_glink_early_ssr_notify, __qcom_glink_send, qcom_glink_advertise_intent, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_rx_done_work, __qcom_glink_rx_done, qcom_glink_channel_release, qcom_glink_announce_create, qcom_glink_mem_entry_free, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010a008 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_glink_rx_done_work, __qcom_glink_rx_done, qcom_glink_work, qcom_glink_rx_done, qcom_glink_mem_entry_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 0010a010 size=1
// signature: undefined idr_remove(void)
// callers: [qcom_glink_send_open_req, qcom_glink_create_ept, __qcom_glink_rx_done, qcom_glink_native_remove, qcom_glink_work, qcom_glink_rx_done, qcom_glink_handle_rx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a018 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_glink_prepare_da_for_cpu, qcom_glink_destroy_ept, qcom_glink_mem_entry_init, qcom_glink_rx_defer, qcom_glink_work, qcom_glink_rx_done, qcom_glink_tx, qcom_glink_alloc_intent, qcom_glink_handle_rx_done, qcom_glink_early_ssr_notify, __qcom_glink_send, qcom_glink_advertise_intent, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_rx_done_work, __qcom_glink_rx_done, qcom_glink_channel_release, qcom_glink_announce_create, qcom_glink_mem_entry_free, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 0010a020 size=1
// signature: undefined ipc_log_string(void)
// callers: [qcom_glink_destroy_ept, qcom_glink_work, qcom_glink_tx, qcom_glink_handle_rx_done, __qcom_glink_send, qcom_glink_advertise_intent, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_set_signals, qcom_glink_channel_release, qcom_glink_announce_create, qcom_glink_send_rx_done, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a028 size=1
// signature: undefined kfree(void)
// callers: [qcom_glink_work, qcom_glink_device_release, qcom_glink_alloc_intent, qcom_glink_handle_rx_done, qcom_glink_rpdev_release, __qcom_glink_rx_done, qcom_glink_native_remove, qcom_glink_alloc_channel, qcom_glink_channel_release, qcom_glink_mem_entry_free, qcom_glink_send_rx_done, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_glink_destroy_ept, rpmsg_name_show, qcom_glink_work, qcom_glink_tx, qcom_glink_early_ssr_notify, __qcom_glink_send, qcom_glink_advertise_intent, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_ssr_notifier_call, qcom_glink_native_remove, qcom_glink_set_signals, qcom_glink_channel_release, qcom_glink_announce_create, qcom_glink_send_rx_done, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010a040 size=1
// signature: undefined __wake_up(void)
// callers: [qcom_glink_work, qcom_glink_channel_release, qcom_glink_early_ssr_notify, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_get_next @ 0010a048 size=1
// signature: undefined idr_get_next(void)
// callers: [__qcom_glink_send, qcom_glink_create_ept, qcom_glink_native_remove, qcom_glink_work, qcom_glink_channel_release, qcom_glink_announce_create, qcom_glink_early_ssr_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_get_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010a050 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_glink_ssr_probe, qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010a058 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qcom_glink_native_probe, qcom_glink_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add_groups @ 0010a060 size=1
// signature: undefined device_add_groups(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add_groups(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010a068 size=1
// signature: undefined of_property_read_string(void)
// callers: [rpmsg_name_show, qcom_glink_work, qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 0010a070 size=1
// signature: undefined mbox_request_channel(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kthread_init_worker @ 0010a078 size=1
// signature: undefined __kthread_init_worker(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kthread_init_worker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0010a088 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0010a090 size=1
// signature: undefined wake_up_process(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a098 size=1
// signature: undefined scnprintf(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 0010a0a0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qcom_glink_native_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a0a8 size=1
// signature: undefined _dev_err(void)
// callers: [__qcom_glink_send, qcom_glink_ssr_notifier_call, qcom_glink_native_remove, qcom_glink_ssr_callback, qcom_glink_work, qcom_glink_native_probe, qcom_glink_handle_rx_done, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010a0b0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [qcom_glink_create_ept, qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 0010a0b8 size=1
// signature: undefined idr_find(void)
// callers: [qcom_glink_work, qcom_glink_handle_rx_done, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0010a0c0 size=1
// signature: undefined __warn_printk(void)
// callers: [qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_cancel_work_sync @ 0010a0c8 size=1
// signature: undefined kthread_cancel_work_sync(void)
// callers: [qcom_glink_work, qcom_glink_channel_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy_pad @ 0010a0d0 size=1
// signature: undefined strscpy_pad(void)
// callers: [qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy_pad(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_unregister_device @ 0010a0d8 size=1
// signature: undefined rpmsg_unregister_device(void)
// callers: [qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 0010a0e0 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [qcom_glink_channel_ref_put, qcom_glink_send_open_req, qcom_glink_create_ept, qcom_glink_native_remove, qcom_glink_work, qcom_glink_device_release, qcom_glink_handle_rx_done, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 0010a0e8 size=1
// signature: undefined idr_alloc(void)
// callers: [qcom_glink_work, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 0010a0f0 size=1
// signature: undefined complete_all(void)
// callers: [qcom_glink_work, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_glink_mem_entry_init, qcom_glink_work, qcom_glink_alloc_intent, qcom_glink_alloc_channel, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010a108 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_register_device @ 0010a110 size=1
// signature: undefined rpmsg_register_device(void)
// callers: [qcom_glink_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a118 size=1
// signature: undefined _printk(void)
// callers: [__qcom_glink_send, qcom_glink_work, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get @ 0010a120 size=1
// signature: undefined of_irq_get(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0010a128 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010a130 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [qcom_glink_native_remove, qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a138 size=1
// signature: undefined __kmalloc(void)
// callers: [qcom_glink_rx_defer, qcom_glink_alloc_intent, qcom_glink_native_start, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010a140 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a150 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 0010a160 size=1
// signature: undefined __bitmap_weight(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __irq_apply_affinity_hint @ 0010a168 size=1
// signature: undefined __irq_apply_affinity_hint(void)
// callers: [qcom_glink_native_remove, qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __irq_apply_affinity_hint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// set_cpus_allowed_ptr @ 0010a170 size=1
// signature: undefined set_cpus_allowed_ptr(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void set_cpus_allowed_ptr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_register_device_override @ 0010a178 size=1
// signature: undefined rpmsg_register_device_override(void)
// callers: [qcom_glink_native_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_register_device_override(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0010a180 size=1
// signature: undefined disable_irq(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 0010a188 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 0010a190 size=1
// signature: undefined device_for_each_child(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 0010a198 size=1
// signature: undefined idr_destroy(void)
// callers: [qcom_glink_native_remove, qcom_glink_channel_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_flush_worker @ 0010a1a0 size=1
// signature: undefined kthread_flush_worker(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_flush_worker(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 0010a1a8 size=1
// signature: undefined kthread_stop(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 0010a1b0 size=1
// signature: undefined mbox_free_channel(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010a1b8 size=1
// signature: undefined _dev_warn(void)
// callers: [qcom_glink_native_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 0010a1c0 size=1
// signature: undefined device_unregister(void)
// callers: [qcom_glink_remove_device, qcom_glink_native_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 0010a1c8 size=1
// signature: undefined mbox_send_message(void)
// callers: [qcom_glink_tx, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_client_txdone @ 0010a1d0 size=1
// signature: undefined mbox_client_txdone(void)
// callers: [qcom_glink_tx, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_client_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010a1d8 size=1
// signature: undefined init_wait_entry(void)
// callers: [__qcom_glink_send, qcom_glink_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010a1e0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [__qcom_glink_send, qcom_glink_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010a1e8 size=1
// signature: undefined schedule_timeout(void)
// callers: [__qcom_glink_send, qcom_glink_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010a1f0 size=1
// signature: undefined finish_wait(void)
// callers: [__qcom_glink_send, qcom_glink_tx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010a1f8 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_glink_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 0010a200 size=1
// signature: undefined kstrdup(void)
// callers: [qcom_glink_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 0010a208 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [qcom_glink_ssr_probe, qcom_glink_alloc_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 0010a210 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [qcom_glink_create_ept, qcom_glink_ssr_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// completion_done @ 0010a218 size=1
// signature: undefined completion_done(void)
// callers: [qcom_glink_announce_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void completion_done(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010a220 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_glink_announce_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010a228 size=1
// signature: size_t strlen(char * __s)
// callers: [qcom_glink_send_open_req, qcom_glink_ssr_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 0010a230 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [qcom_glink_send_open_req, qcom_glink_alloc_intent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0010a238 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [qcom_glink_send_open_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 0010a240 size=1
// signature: undefined strscpy(void)
// callers: [qcom_glink_send_open_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a248 size=1
// signature: undefined fortify_panic(void)
// callers: [qcom_glink_send_open_req]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a250 size=1
// signature: undefined mutex_lock(void)
// callers: [__qcom_glink_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a258 size=1
// signature: undefined mutex_unlock(void)
// callers: [__qcom_glink_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 0010a260 size=1
// signature: undefined sysfs_emit(void)
// callers: [rpmsg_name_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 0010a268 size=1
// signature: undefined ___ratelimit(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010a270 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_glink_mem_entry_init, qcom_glink_rx_defer, __qcom_glink_rx_done, qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_system_wakeup @ 0010a278 size=1
// signature: undefined pm_system_wakeup(void)
// callers: [qcom_glink_native_rx]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_system_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010a288 size=1
// signature: undefined queue_work_on(void)
// callers: [qcom_glink_rx_defer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_queue_work @ 0010a290 size=1
// signature: undefined kthread_queue_work(void)
// callers: [__qcom_glink_rx_done]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_queue_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 0010a298 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [qcom_glink_ssr_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 0010a2a0 size=1
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
// unregister_rpmsg_driver @ 0010a2a8 size=1
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
// blocking_notifier_chain_register @ 0010a2b0 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [qcom_glink_ssr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 0010a2b8 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [qcom_glink_ssr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a2c0 size=1
// signature: undefined complete(void)
// callers: [qcom_glink_ssr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010a2c8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [qcom_glink_ssr_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 0010a2d0 size=1
// signature: undefined rpmsg_send(void)
// callers: [qcom_glink_ssr_notifier_call]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_sync_single_for_cpu @ 0010a2d8 size=1
// signature: undefined dma_sync_single_for_cpu(void)
// callers: [qcom_glink_prepare_da_for_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_sync_single_for_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



