// Decompiled by Ghidra 12.2
// Program: qcom_aoss.ko
// Image base: 00100000

//------------------------------------------------------------
// qmp_send @ 0010056c size=748
// signature: undefined qmp_send(void)
// callers: [aoss_send_message_store, qmp_qdss_clk_prepare, aoss_dbg_write, qmp_cdev_set_cur_state, qmp_qdss_clk_unprepare]
//------------------------------------------------------------

ulong qmp_send(long *param_1,long param_2,ulong param_3)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if (((param_1 == (long *)0x0) || ((long *)0xfffffffffffff000 < param_1)) || (param_2 == 0)) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100844);
    (*pcVar3)();
  }
  if ((char)param_1[0x1a] != '\0') {
    uVar7 = 0xfffffffa;
    goto LAB_001007e8;
  }
  if ((ulong)param_1[0xb] < param_3 + 4) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x100850);
    (*pcVar3)();
  }
  if ((param_3 & 3) != 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x10085c);
    (*pcVar3)();
  }
  mutex_lock(param_1 + 0xf);
  __iowrite32_copy(*param_1 + param_1[10] + 4,param_2,param_3 >> 2);
  writel(param_3 & 0xffffffff,*param_1 + param_1[10]);
  readl(*param_1 + param_1[10]);
  mbox_send_message(param_1[9],0);
  mbox_client_txdone(param_1[9],0);
  ipc_log_string(ilc,"[%s]: msg: %.*s\n","qmp_send",param_3,param_2);
  uVar2 = ilc;
  uVar4 = readl(*param_1 + param_1[10]);
  ipc_log_string(uVar2,"[%s]: ack msg size: %u\n","qmp_message_empty",uVar4);
  iVar5 = readl(*param_1 + param_1[10]);
  if (iVar5 == 0) {
LAB_001007bc:
    ipc_log_string(ilc,"[%s]: ack: %.*s\n","qmp_send",param_3,param_2);
    uVar7 = 0;
  }
  else {
    uStack_90 = 0;
    local_78 = 0;
    uStack_70 = 0;
    local_88 = 0;
    uStack_80 = 0;
    init_wait_entry(&uStack_90,0);
    uVar7 = 0xfa;
    while( true ) {
      uVar6 = prepare_to_wait_event(param_1 + 0xc,&uStack_90,1);
      uVar2 = ilc;
      uVar4 = readl(*param_1 + param_1[10]);
      ipc_log_string(uVar2,"[%s]: ack msg size: %u\n","qmp_message_empty",uVar4);
      iVar5 = readl(*param_1 + param_1[10]);
      if (uVar7 == 0 && iVar5 == 0) {
        uVar7 = 1;
      }
      if ((iVar5 == 0) || (uVar7 == 0)) {
        finish_wait(param_1 + 0xc,&uStack_90);
        if (uVar7 != 0) goto LAB_001007b4;
        _dev_err(param_1[1],"ucore did not ack channel\n");
        ipc_log_string(ilc,"[%s]: timed out clearing msg: %.*s\n","qmp_send",param_3,param_2);
        writel(0,*param_1 + param_1[10]);
        uVar7 = 0xffffff92;
        goto LAB_001007e0;
      }
      if (uVar6 != 0) break;
      uVar7 = schedule_timeout(uVar7);
    }
    uVar7 = uVar6;
LAB_001007b4:
    if (-1 < (long)uVar7) goto LAB_001007bc;
    _dev_err(param_1[1],"wait error %ld\n",uVar7);
  }
LAB_001007e0:
  mutex_unlock(param_1 + 0xf);
LAB_001007e8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// writel @ 00100864 size=136
// signature: undefined writel(void)
// callers: [qmp_send, qmp_probe, qmp_open, qmp_remove]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10087c,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1008bc,uVar1);
  return;
}



//------------------------------------------------------------
// readl @ 001008ec size=140
// signature: undefined readl(void)
// callers: [qmp_send, qmp_open]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x100944,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qmp_get @ 0010097c size=192
// signature: undefined qmp_get(void)
// callers: []
//------------------------------------------------------------

void qmp_get(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long local_68 [11];
  
  lVar2 = sp_el0;
  local_68[10] = *(long *)(lVar2 + 0x638);
  if ((param_1 != 0) && (*(long *)(param_1 + 0x2e8) != 0)) {
    local_68[8] = 0;
    local_68[9] = 0;
    local_68[6] = 0;
    local_68[7] = 0;
    local_68[4] = 0;
    local_68[5] = 0;
    local_68[2] = 0;
    local_68[3] = 0;
    local_68[0] = 0;
    local_68[1] = 0;
    iVar1 = __of_parse_phandle_with_args(*(long *)(param_1 + 0x2e8),"qcom,qmp",0,0,0,local_68);
    lVar2 = -0x13;
    if ((iVar1 != 0) || (local_68[0] == 0)) goto LAB_00100a14;
    lVar3 = of_find_device_by_node(local_68[0]);
    if (lVar3 != 0) {
      lVar2 = *(long *)(lVar3 + 0xa8);
      if (lVar2 == 0) {
        put_device(lVar3 + 0x10);
        lVar2 = -0x205;
      }
      goto LAB_00100a14;
    }
  }
  lVar2 = -0x16;
LAB_00100a14:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar2);
  }
  return;
}



//------------------------------------------------------------
// qmp_put @ 00100a40 size=44
// signature: undefined qmp_put(void)
// callers: []
//------------------------------------------------------------

void qmp_put(ulong param_1)

{
  if ((param_1 != 0) && (param_1 < 0xfffffffffffff001)) {
    put_device(*(undefined8 *)(param_1 + 8));
  }
  return;
}



//------------------------------------------------------------
// qmp_probe @ 00100a70 size=1016
// signature: undefined qmp_probe(void)
// callers: []
//------------------------------------------------------------

ulong qmp_probe(long param_1)

{
  ulong *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  ulong *puVar6;
  ulong uVar7;
  ulong uVar8;
  ulong *puVar9;
  long lVar10;
  ulong uVar11;
  ulong uVar12;
  undefined8 uVar13;
  
  uVar12 = param_1 + 0x10;
  puVar6 = (ulong *)devm_kmalloc(uVar12,0xd8,0xdc0);
  if (puVar6 == (ulong *)0x0) {
    uVar7 = 0xfffffff4;
    goto LAB_00100c34;
  }
  puVar6[1] = uVar12;
  __init_waitqueue_head(puVar6 + 0xc,"&qmp->event",&qmp_probe___key);
  __mutex_init(puVar6 + 0xf,"&qmp->tx_lock",&qmp_probe___key_9);
  ilc = ipc_log_context_create(2,&DAT_00101bbb,0);
  uVar7 = devm_platform_ioremap_resource(param_1,0);
  *puVar6 = uVar7;
  if (0xfffffffffffff000 < uVar7) goto LAB_00100c34;
  puVar6[2] = uVar12;
  *(undefined1 *)(puVar6 + 5) = 1;
  uVar7 = mbox_request_channel(puVar6 + 2,0);
  puVar6[9] = uVar7;
  if (0xfffffffffffff000 < uVar7) {
    _dev_err(uVar12,"failed to acquire ipc mailbox\n");
    uVar7 = (ulong)(uint)puVar6[9];
    goto LAB_00100c34;
  }
  uVar3 = platform_get_irq(param_1,0);
  uVar4 = devm_request_threaded_irq(uVar12,uVar3,qmp_intr,0,0,"aoss-qmp",puVar6);
  if ((int)uVar4 < 0) {
    uVar7 = (ulong)uVar4;
    _dev_err(uVar12,"failed to request interrupt\n");
  }
  else {
    irq_set_irq_wake(uVar3,1);
    uVar4 = qmp_open(puVar6);
    if ((int)uVar4 < 0) {
      uVar7 = (ulong)uVar4;
    }
    else {
      puVar9 = puVar6 + 0x15;
      puVar6[0x17] = (ulong)&qmp_qdss_clk_add_qdss_init;
      uVar8 = clk_hw_register(puVar6[1],puVar9);
      uVar7 = uVar8 & 0xffffffff;
      if ((int)uVar8 < 0) {
        _dev_err(puVar6[1],"failed to register qdss clock\n");
      }
      else {
        uVar8 = of_clk_add_hw_provider
                          (*(undefined8 *)(puVar6[1] + 0x2e8),&of_clk_hw_simple_get,puVar9);
        uVar7 = uVar8 & 0xffffffff;
        if ((int)uVar8 < 0) {
          _dev_err(puVar6[1],"unable to register of clk hw provider\n");
          clk_hw_unregister(puVar9);
        }
        else if ((int)uVar8 == 0) {
          uVar13 = *(undefined8 *)(puVar6[1] + 0x2e8);
          uVar7 = devm_kmalloc(puVar6[1],0x40,0xdc0);
          puVar6[0x18] = uVar7;
          if (uVar7 == 0) {
LAB_00100e3c:
            _dev_err(uVar12,"failed to register aoss cooling devices\n");
          }
          else {
            puVar9 = (ulong *)of_get_next_available_child(uVar13,0);
            if (puVar9 == (ulong *)0x0) {
LAB_00100d44:
              uVar11 = 0;
LAB_00100d9c:
              devm_kfree(puVar6[1],puVar6[0x18]);
              if ((int)uVar11 != 0) goto LAB_00100e3c;
            }
            else {
              uVar7 = 0;
              do {
                lVar10 = of_find_property(puVar9,"#cooling-cells",0);
                if (lVar10 == 0) {
                  uVar8 = uVar7;
                }
                else {
                  iVar5 = (int)uVar7;
                  uVar8 = *puVar9;
                  puVar1 = (ulong *)(puVar6[0x18] + (long)iVar5 * 0x20);
                  *(undefined1 *)(puVar1 + 3) = 0;
                  puVar1[1] = (ulong)puVar6;
                  puVar1[2] = uVar8;
                  uVar11 = devm_thermal_of_cooling_device_register
                                     (puVar6[1],puVar9,uVar8,puVar1,&qmp_cooling_device_ops);
                  *puVar1 = uVar11;
                  if (0xfffffffffffff000 < uVar11) {
                    _dev_err(puVar6[1],"unable to register %s cooling device\n",uVar8);
                    uVar11 = *puVar1;
                  }
                  uVar8 = (ulong)(iVar5 + 1);
                  if ((0xfffffffffffff000 < uVar11) && ((uVar11 & 0xffffffff) != 0)) {
                    if (-1 < iVar5) {
                      lVar10 = uVar7 << 5;
                      do {
                        thermal_cooling_device_unregister(*(undefined8 *)(puVar6[0x18] + lVar10));
                        bVar2 = lVar10 != 0;
                        lVar10 = lVar10 + -0x20;
                      } while (bVar2);
                    }
                    goto LAB_00100d9c;
                  }
                }
                puVar9 = (ulong *)of_get_next_available_child(uVar13,puVar9);
                uVar7 = uVar8;
              } while (puVar9 != (ulong *)0x0);
              if ((int)uVar8 == 0) goto LAB_00100d44;
            }
          }
          *(ulong **)(param_1 + 0xa8) = puVar6;
          lVar10 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"moto_aoss_enable",0);
          if (lVar10 != 0) {
            iVar5 = device_create_file(puVar6[1],&dev_attr_aoss_send_message);
            if (iVar5 == 0) {
              *(undefined1 *)((long)puVar6 + 0xd1) = 1;
            }
            else {
              _dev_err(puVar6[1],"failed to create sysfs node aoss_send_message: %d\n",iVar5);
            }
          }
          uVar12 = debugfs_create_file("aoss_send_message",0x90,0,puVar6,aoss_dbg_fops);
          uVar7 = 0;
          puVar6[0x19] = uVar12;
          goto LAB_00100c34;
        }
      }
      writel(0xffff0000,*puVar6 + 0x2c);
      writel(0xffff0000,*puVar6 + 0x24);
      mbox_send_message(puVar6[9],0);
      mbox_client_txdone(puVar6[9],0);
    }
  }
  mbox_free_channel(puVar6[9]);
LAB_00100c34:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// qmp_remove @ 00100e6c size=180
// signature: undefined qmp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_remove(long param_1)

{
  long *plVar1;
  
  plVar1 = *(long **)(param_1 + 0xa8);
  if (*(char *)((long)plVar1 + 0xd1) != '\0') {
    device_remove_file(plVar1[1],&dev_attr_aoss_send_message);
  }
  debugfs_remove(plVar1[0x19]);
  of_clk_del_provider(*(undefined8 *)(plVar1[1] + 0x2e8));
  clk_hw_unregister(plVar1 + 0x15);
  thermal_cooling_device_unregister(*(undefined8 *)plVar1[0x18]);
  thermal_cooling_device_unregister(*(undefined8 *)(plVar1[0x18] + 0x20));
  writel(0xffff0000,*plVar1 + 0x2c);
  writel(0xffff0000,*plVar1 + 0x24);
  mbox_send_message(plVar1[9],0);
  mbox_client_txdone(plVar1[9],0);
  mbox_free_channel(plVar1[9]);
  return 0;
}



//------------------------------------------------------------
// qmp_intr @ 00100f24 size=88
// signature: undefined qmp_intr(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_intr(undefined8 param_1,long param_2)

{
  ipc_log_string(ilc,"[%s]: \n","qmp_intr");
  __wake_up(param_2 + 0x60,3,0,0);
  return 1;
}



//------------------------------------------------------------
// qmp_open @ 00100f7c size=1088
// signature: undefined qmp_open(void)
// callers: [aoss_qmp_mbox_resume_early, qmp_probe, aoss_qmp_mbox_restore]
//------------------------------------------------------------

void qmp_open(long *param_1)

{
  long *plVar1;
  int iVar2;
  uint uVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  iVar2 = readl(*param_1);
  if (iVar2 != 0x4d41494c) {
    lVar7 = param_1[1];
    pcVar6 = "QMP magic doesn\'t match\n";
LAB_0010133c:
    _dev_err(lVar7,pcVar6);
    uVar5 = 0xffffffea;
    goto LAB_001012d4;
  }
  iVar2 = readl(*param_1 + 4);
  if (iVar2 != 1) {
    _dev_err(param_1[1],"unsupported QMP version %d\n",iVar2);
    uVar5 = 0xffffffea;
    goto LAB_001012d4;
  }
  uVar4 = readl(*param_1 + 0x38);
  param_1[10] = uVar4 & 0xffffffff;
  uVar3 = readl(*param_1 + 0x34);
  param_1[0xb] = (ulong)uVar3;
  if (uVar3 == 0) {
    lVar7 = param_1[1];
    pcVar6 = "invalid mailbox size\n";
    goto LAB_0010133c;
  }
  uVar5 = readl(*param_1 + 0xc);
  writel(uVar5,*param_1 + 0x10);
  writel(0xffff,*param_1 + 0x24);
  mbox_send_message(param_1[9],0);
  mbox_client_txdone(param_1[9],0);
  iVar2 = readl(*param_1 + 0x28);
  if (iVar2 == 0xffff) {
LAB_00101100:
    writel(0xffff,*param_1 + 0x2c);
    mbox_send_message(param_1[9],0);
    mbox_client_txdone(param_1[9],0);
    iVar2 = readl(*param_1 + 0x14);
    if (iVar2 == 0xffff) {
LAB_001011e4:
      writel(0xffff,*param_1 + 0x18);
      mbox_send_message(param_1[9],0);
      mbox_client_txdone(param_1[9],0);
      iVar2 = readl(*param_1 + 0x30);
      if (iVar2 != 0xffff) {
        local_58 = 0;
        uStack_50 = 0;
        local_68 = 0;
        uStack_60 = 0;
        local_70 = 0;
        init_wait_entry(&local_70,0);
        plVar1 = param_1 + 0xc;
        prepare_to_wait_event(plVar1,&local_70,2);
        iVar2 = readl(*param_1 + 0x30);
        if (iVar2 == 0xffff) {
          finish_wait(plVar1,&local_70);
        }
        else {
          lVar7 = 0xfa;
          do {
            lVar7 = schedule_timeout(lVar7);
            prepare_to_wait_event(plVar1,&local_70,2);
            iVar2 = readl(*param_1 + 0x30);
            if (lVar7 == 0 && iVar2 == 0xffff) {
              lVar7 = 1;
            }
          } while ((iVar2 != 0xffff) && (lVar7 != 0));
          finish_wait(plVar1,&local_70);
          if ((int)lVar7 == 0) {
            pcVar6 = "ucore didn\'t ack channel\n";
            goto LAB_00101370;
          }
        }
      }
      uVar5 = 0;
      *(undefined1 *)(param_1 + 0x1a) = 0;
      goto LAB_001012d4;
    }
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_70 = 0;
    init_wait_entry(&local_70,0);
    plVar1 = param_1 + 0xc;
    prepare_to_wait_event(plVar1,&local_70,2);
    iVar2 = readl(*param_1 + 0x14);
    if (iVar2 == 0xffff) {
      finish_wait(plVar1,&local_70);
      goto LAB_001011e4;
    }
    lVar7 = 0xfa;
    do {
      lVar7 = schedule_timeout(lVar7);
      prepare_to_wait_event(plVar1,&local_70,2);
      iVar2 = readl(*param_1 + 0x14);
      if (lVar7 == 0 && iVar2 == 0xffff) {
        lVar7 = 1;
      }
    } while ((iVar2 != 0xffff) && (lVar7 != 0));
    finish_wait(plVar1,&local_70);
    if ((int)lVar7 != 0) goto LAB_001011e4;
    pcVar6 = "ucore didn\'t open channel\n";
LAB_00101370:
    _dev_err(param_1[1],pcVar6);
    writel(0xffff0000,*param_1 + 0x2c);
  }
  else {
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_70 = 0;
    init_wait_entry(&local_70,0);
    plVar1 = param_1 + 0xc;
    prepare_to_wait_event(plVar1,&local_70,2);
    iVar2 = readl(*param_1 + 0x28);
    if (iVar2 == 0xffff) {
      finish_wait(plVar1,&local_70);
      goto LAB_00101100;
    }
    lVar7 = 0xfa;
    do {
      lVar7 = schedule_timeout(lVar7);
      prepare_to_wait_event(plVar1,&local_70,2);
      iVar2 = readl(*param_1 + 0x28);
      if (lVar7 == 0 && iVar2 == 0xffff) {
        lVar7 = 1;
      }
    } while ((iVar2 != 0xffff) && (lVar7 != 0));
    finish_wait(plVar1,&local_70);
    if ((int)lVar7 != 0) goto LAB_00101100;
    _dev_err(param_1[1],"ucore didn\'t ack link\n");
  }
  writel(0xffff0000,*param_1 + 0x24);
  mbox_send_message(param_1[9],0);
  mbox_client_txdone(param_1[9],0);
  uVar5 = 0xffffff92;
LAB_001012d4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// qmp_qdss_clk_prepare @ 001013c0 size=44
// signature: undefined qmp_qdss_clk_prepare(void)
// callers: []
//------------------------------------------------------------

void qmp_qdss_clk_prepare(long param_1)

{
  qmp_send(param_1 + -0xa8,"{class: clock, res: qdss, val: 1}",0x40);
  return;
}



//------------------------------------------------------------
// qmp_qdss_clk_unprepare @ 001013f0 size=44
// signature: undefined qmp_qdss_clk_unprepare(void)
// callers: []
//------------------------------------------------------------

void qmp_qdss_clk_unprepare(long param_1)

{
  qmp_send(param_1 + -0xa8,"{class: clock, res: qdss, val: 0}",0x40);
  return;
}



//------------------------------------------------------------
// qmp_cdev_get_max_state @ 00101420 size=16
// signature: undefined qmp_cdev_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_cdev_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}



//------------------------------------------------------------
// qmp_cdev_get_cur_state @ 00101434 size=20
// signature: undefined qmp_cdev_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 qmp_cdev_get_cur_state(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(byte *)(*(long *)(param_1 + 0x3b0) + 0x18);
  return 0;
}



//------------------------------------------------------------
// qmp_cdev_set_cur_state @ 0010144c size=196
// signature: undefined qmp_cdev_set_cur_state(void)
// callers: []
//------------------------------------------------------------

void qmp_cdev_set_cur_state(long param_1,ulong param_2)

{
  char *param4;
  undefined8 uVar1;
  long lVar2;
  char local_68 [64];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x3b0);
  local_68[0x30] = '\0';
  local_68[0x31] = '\0';
  local_68[0x32] = '\0';
  local_68[0x33] = '\0';
  local_68[0x34] = '\0';
  local_68[0x35] = '\0';
  local_68[0x36] = '\0';
  local_68[0x37] = '\0';
  local_68[0x38] = '\0';
  local_68[0x39] = '\0';
  local_68[0x3a] = '\0';
  local_68[0x3b] = '\0';
  local_68[0x3c] = '\0';
  local_68[0x3d] = '\0';
  local_68[0x3e] = '\0';
  local_68[0x3f] = '\0';
  local_68[0x20] = '\0';
  local_68[0x21] = '\0';
  local_68[0x22] = '\0';
  local_68[0x23] = '\0';
  local_68[0x24] = '\0';
  local_68[0x25] = '\0';
  local_68[0x26] = '\0';
  local_68[0x27] = '\0';
  local_68[0x28] = '\0';
  local_68[0x29] = '\0';
  local_68[0x2a] = '\0';
  local_68[0x2b] = '\0';
  local_68[0x2c] = '\0';
  local_68[0x2d] = '\0';
  local_68[0x2e] = '\0';
  local_68[0x2f] = '\0';
  local_68[0x10] = '\0';
  local_68[0x11] = '\0';
  local_68[0x12] = '\0';
  local_68[0x13] = '\0';
  local_68[0x14] = '\0';
  local_68[0x15] = '\0';
  local_68[0x16] = '\0';
  local_68[0x17] = '\0';
  local_68[0x18] = '\0';
  local_68[0x19] = '\0';
  local_68[0x1a] = '\0';
  local_68[0x1b] = '\0';
  local_68[0x1c] = '\0';
  local_68[0x1d] = '\0';
  local_68[0x1e] = '\0';
  local_68[0x1f] = '\0';
  local_68[0] = '\0';
  local_68[1] = '\0';
  local_68[2] = '\0';
  local_68[3] = '\0';
  local_68[4] = '\0';
  local_68[5] = '\0';
  local_68[6] = '\0';
  local_68[7] = '\0';
  local_68[8] = '\0';
  local_68[9] = '\0';
  local_68[10] = '\0';
  local_68[0xb] = '\0';
  local_68[0xc] = '\0';
  local_68[0xd] = '\0';
  local_68[0xe] = '\0';
  local_68[0xf] = '\0';
  if (*(byte *)(lVar2 + 0x18) == param_2) {
    uVar1 = 0;
  }
  else {
    param4 = "on";
    if (param_2 == 0) {
      param4 = "off";
    }
    snprintf(local_68,0x40,"{class: volt_flr, event:zero_temp, res:%s, value:%s}",
             *(char **)(lVar2 + 0x10),param4);
    uVar1 = qmp_send(*(undefined8 *)(lVar2 + 8),local_68,0x40);
    if ((int)uVar1 == 0) {
      *(bool *)(lVar2 + 0x18) = param_2 != 0;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar1);
  }
  return;
}



//------------------------------------------------------------
// aoss_send_message_store @ 00101514 size=280
// signature: undefined aoss_send_message_store(void)
// callers: []
//------------------------------------------------------------

void aoss_send_message_store(long param_1,undefined8 param_2,void *param_3,size_t param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x98);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_4 - 0x40 < 0xffffffffffffffc1) {
    param_4 = 0xffffffffffffffea;
  }
  else {
    memcpy(&local_78,param_3,param_4);
    if (0x3f < param_4) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x10162c);
      (*pcVar2)();
    }
    *(undefined1 *)((long)&local_78 + param_4) = 0;
    uVar4 = strim(&local_78);
    _dev_err(param_1,"AOSS_SYSFS: writing message: %s\n",uVar4);
    uVar4 = strim(&local_78);
    iVar3 = qmp_send(uVar5,uVar4,0x40);
    if (iVar3 == 0) {
      _dev_err(param_1,"AOSS_SYSFS: qmp_send successfully acked!\n");
    }
    else {
      _dev_err(param_1,"AOSS_SYSFS: qmp_send failed with ret=%d\n",iVar3);
    }
    if (iVar3 != 0) {
      param_4 = (long)iVar3;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// aoss_dbg_write @ 00101630 size=452
// signature: undefined aoss_dbg_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void aoss_dbg_write(long param_1,ulong param_2,size_t param_3)

{
  long lVar1;
  ulong uVar2;
  int iVar3;
  size_t __n;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar7 = *(undefined8 *)(param_1 + 0xd8);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_3 - 0x40 < 0xffffffffffffffc1) {
    param_3 = 0xffffffffffffffea;
    goto LAB_00101788;
  }
  __check_object_size(&local_78,param_3,0);
  puVar5 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar5 + 0x46) >> 5 & 1) != 0) ||
     (uVar6 = param_2, ((uint)*puVar5 >> 0x1a & 1) != 0)) {
    uVar6 = param_2 & (long)(param_2 << 8) >> 8;
  }
  __n = param_3;
  if (0x8000000000 - param_3 < uVar6) {
LAB_001017b4:
    memset((void *)((long)&local_78 + (param_3 - __n)),0,__n);
    if ((int)__n != 0) {
      param_3 = 0xfffffffffffffff2;
      goto LAB_00101788;
    }
  }
  else {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      puVar5 = (undefined8 *)puVar5[1];
      uVar2 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar5 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar5;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    __n = __arch_copy_from_user(puVar5,&local_78,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    if (__n != 0) goto LAB_001017b4;
  }
  uVar4 = strim(&local_78);
  iVar3 = qmp_send(uVar7,uVar4,0x40);
  if (iVar3 != 0) {
    param_3 = (long)iVar3;
  }
LAB_00101788:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}



//------------------------------------------------------------
// aoss_qmp_mbox_resume_early @ 00101810 size=112
// signature: undefined aoss_qmp_mbox_resume_early(void)
// callers: []
//------------------------------------------------------------

int aoss_qmp_mbox_resume_early(long param_1)

{
  int iVar1;
  
  if ((pm_suspend_global_flags & 1) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = qmp_open(*(undefined8 *)(param_1 + 0x98));
    if (iVar1 < 0) {
      _dev_err(param_1,"QMP restore failed, ret = %d\n",iVar1);
    }
    _dev_info(param_1,"AOSS: Deep sleep exit\n");
  }
  return iVar1;
}



//------------------------------------------------------------
// aoss_qmp_mbox_freeze @ 00101884 size=8
// signature: undefined aoss_qmp_mbox_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 aoss_qmp_mbox_freeze(void)

{
  return 0;
}



//------------------------------------------------------------
// aoss_qmp_mbox_restore @ 00101890 size=76
// signature: undefined aoss_qmp_mbox_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 aoss_qmp_mbox_restore(long param_1)

{
  int iVar1;
  
  iVar1 = qmp_open(*(undefined8 *)(param_1 + 0x98));
  if (iVar1 < 0) {
    _dev_err(param_1,"QMP restore failed, ret = %d\n",iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// aoss_qmp_mbox_suspend_noirq @ 001018e0 size=68
// signature: undefined aoss_qmp_mbox_suspend_noirq(void)
// callers: []
//------------------------------------------------------------

undefined8 aoss_qmp_mbox_suspend_noirq(long param_1)

{
  if ((pm_suspend_global_flags & 1) != 0) {
    *(undefined1 *)(*(long *)(param_1 + 0x98) + 0xd0) = 1;
    _dev_info(param_1,"AOSS: Deep sleep entry\n");
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010198c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qmp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001019bc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qmp_driver);
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00105000 size=1
// signature: undefined mutex_lock(void)
// callers: [qmp_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __iowrite32_copy @ 00105008 size=1
// signature: undefined __iowrite32_copy(void)
// callers: [qmp_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __iowrite32_copy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 00105010 size=1
// signature: undefined mbox_send_message(void)
// callers: [qmp_send, qmp_probe, qmp_open, qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_client_txdone @ 00105018 size=1
// signature: undefined mbox_client_txdone(void)
// callers: [qmp_send, qmp_probe, qmp_open, qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_client_txdone(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00105020 size=1
// signature: undefined ipc_log_string(void)
// callers: [qmp_send, qmp_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00105028 size=1
// signature: undefined init_wait_entry(void)
// callers: [qmp_send, qmp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00105030 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [qmp_send, qmp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 00105038 size=1
// signature: undefined schedule_timeout(void)
// callers: [qmp_send, qmp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00105040 size=1
// signature: undefined finish_wait(void)
// callers: [qmp_send, qmp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105048 size=1
// signature: undefined _dev_err(void)
// callers: [aoss_send_message_store, qmp_send, aoss_qmp_mbox_resume_early, qmp_probe, qmp_open, aoss_qmp_mbox_restore]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105050 size=1
// signature: undefined mutex_unlock(void)
// callers: [qmp_send]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [aoss_send_message_store, qmp_send, aoss_dbg_write, qmp_cdev_set_cur_state, qmp_get, qmp_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00105060 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00105068 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00105070 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00105078 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00105080 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [qmp_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00105088 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [qmp_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00105090 size=1
// signature: undefined put_device(void)
// callers: [qmp_put, qmp_get]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00105098 size=1
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
// platform_driver_unregister @ 001050a0 size=1
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
// devm_kmalloc @ 001050a8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 001050b0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001050b8 size=1
// signature: undefined __mutex_init(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001050c0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_platform_ioremap_resource @ 001050c8 size=1
// signature: undefined devm_platform_ioremap_resource(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_platform_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 001050d0 size=1
// signature: undefined mbox_request_channel(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 001050d8 size=1
// signature: undefined platform_get_irq(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 001050e0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 001050e8 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_register @ 001050f0 size=1
// signature: undefined clk_hw_register(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_clk_add_hw_provider @ 00105100 size=1
// signature: undefined of_clk_add_hw_provider(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_clk_add_hw_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_free_channel @ 00105108 size=1
// signature: undefined mbox_free_channel(void)
// callers: [qmp_probe, qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_free_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00105110 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00105118 size=1
// signature: undefined of_find_property(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_thermal_of_cooling_device_register @ 00105120 size=1
// signature: undefined devm_thermal_of_cooling_device_register(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00105128 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [qmp_probe, qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00105130 size=1
// signature: undefined devm_kfree(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00105138 size=1
// signature: undefined device_create_file(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 00105140 size=1
// signature: undefined debugfs_create_file(void)
// callers: [qmp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_hw_unregister @ 00105148 size=1
// signature: undefined clk_hw_unregister(void)
// callers: [qmp_probe, qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_hw_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00105150 size=1
// signature: undefined device_remove_file(void)
// callers: [qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105158 size=1
// signature: undefined debugfs_remove(void)
// callers: [qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_clk_del_provider @ 00105160 size=1
// signature: undefined of_clk_del_provider(void)
// callers: [qmp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_clk_del_provider(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00105168 size=1
// signature: undefined __wake_up(void)
// callers: [qmp_intr]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00105170 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [qmp_cdev_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105178 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [aoss_send_message_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strim @ 00105180 size=1
// signature: undefined strim(void)
// callers: [aoss_send_message_store, aoss_dbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00105188 size=1
// signature: undefined __check_object_size(void)
// callers: [aoss_dbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001051a0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [aoss_dbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001051a8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [aoss_dbg_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001051c0 size=1
// signature: undefined _dev_info(void)
// callers: [aoss_qmp_mbox_resume_early, aoss_qmp_mbox_suspend_noirq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



