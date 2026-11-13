// Decompiled by Ghidra 12.2
// Program: qsee_ipc_irq_bridge.ko
// Image base: 00100000

//------------------------------------------------------------
// qsee_ipc_irq_bridge_probe @ 0010029c size=1948
// signature: undefined qsee_ipc_irq_bridge_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint qsee_ipc_irq_bridge_probe(long param_1)

{
  ulong *puVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  ulong uVar5;
  ulong *puVar6;
  long lVar7;
  uint uVar8;
  undefined8 uVar9;
  char *pcVar10;
  ulong uVar11;
  ulong *puVar12;
  ulong local_78;
  ulong local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  uVar9 = *(undefined8 *)(param_1 + 0x2f8);
  lVar4 = of_get_next_available_child(uVar9,0);
  if (lVar4 == 0) {
    *(undefined4 *)(qiib_info + 8) = 0;
  }
  else {
    iVar3 = 0;
    do {
      lVar4 = of_get_next_available_child(uVar9,lVar4);
      puVar6 = qiib_info;
      iVar3 = iVar3 + -1;
    } while (lVar4 != 0);
    *(int *)(qiib_info + 8) = -iVar3;
    if (iVar3 != 0) {
      uVar2 = alloc_chrdev_region(puVar6 + 10,0,-iVar3,"qsee_ipc_irq_bridge");
      if (uVar2 < 0xfffff001) {
        uVar5 = __class_create(&__this_module,"qsee_ipc_irq_bridge",&qiib_alloc_chrdev_region___key)
        ;
        qiib_info[9] = uVar5;
        if (uVar5 < 0xfffffffffffff001) {
          lVar4 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0);
          if (lVar4 != 0) {
            uVar8 = 0;
            pcVar10 = "qcom,dev-name";
            do {
              puVar6 = (ulong *)kmalloc_trace(_kfree,0xdc0,0x108);
              if ((puVar6 == (ulong *)0x0) || ((ulong *)0xfffffffffffff000 < puVar6)) {
                _printk(&DAT_001015c9,"qsee_ipc_irq_bridge_probe",uVar8);
                ipc_log_string(qiib_info[0xb],"%s:Allocation failed id:%d\n",
                               "qsee_ipc_irq_bridge_probe",uVar8);
                uVar2 = 0xfffffff4;
                qiib_cleanup();
                goto LAB_00100614;
              }
              local_78 = 0;
              local_70 = 0;
              uVar2 = of_property_read_string(lVar4,"qcom,dev-name",&local_78);
              if (uVar2 != 0) {
LAB_00100770:
                _printk(&DAT_001015b2,"qiib_parse_node",pcVar10);
                ipc_log_string(qiib_info[0xb],"%s: missing key: %s\n","qiib_parse_node",pcVar10);
                _printk(&DAT_0010187d,"qsee_ipc_irq_bridge_probe",uVar8);
                pcVar10 = "%s:qiib_parse_node failed %d\n";
LAB_001009a0:
                ipc_log_string(qiib_info[0xb],pcVar10,"qsee_ipc_irq_bridge_probe",uVar8);
                qiib_cleanup();
                goto LAB_00100614;
              }
              if (qiib_info[0xb] != 0) {
                ipc_log_string(qiib_info[0xb],"%s: %s = %s\n","qiib_parse_node","qcom,dev-name",
                               local_78);
              }
              uVar2 = of_property_read_string(lVar4,"label",&local_70);
              if (uVar2 != 0) {
                pcVar10 = "label";
                goto LAB_00100770;
              }
              if (qiib_info[0xb] != 0) {
                ipc_log_string(qiib_info[0xb],"%s: %s = %s\n","qiib_parse_node","label",local_70);
              }
              *(uint *)(puVar6 + 2) = uVar8;
              puVar6[3] = local_78;
              puVar6[0x1b] = local_70;
              __init_waitqueue_head(puVar6 + 0x16,"&devp->poll_wait_queue",&qiib_add_device___key);
              puVar12 = puVar6 + 4;
              *(undefined4 *)(puVar6 + 0x1a) = 0;
              cdev_init(puVar12,&qiib_fops);
              puVar1 = qiib_info;
              puVar6[0x10] = (ulong)&__this_module;
              uVar2 = cdev_add(puVar12,uVar8 + (int)puVar1[10],1);
              if (0xfffff000 < uVar2) {
                _printk(&DAT_001018bb,"qiib_add_device",puVar6[3],uVar2);
                ipc_log_string(qiib_info[0xb],"%s: cdev_add() failed for dev [%s] ret:%i\n",
                               "qiib_add_device",puVar6[3],uVar2);
LAB_00100820:
                _printk(&DAT_001013f5,"qsee_ipc_irq_bridge_probe",puVar6[3],uVar2);
                ipc_log_string(qiib_info[0xb],"%s: add [%s] device failed ret=%d\n",
                               "qsee_ipc_irq_bridge_probe",puVar6[3],uVar2);
                qiib_cleanup();
                goto LAB_00100614;
              }
              uVar5 = device_create(qiib_info[9],0,uVar8 + (int)qiib_info[10],0,puVar6[3]);
              puVar6[0x15] = uVar5;
              if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
                _printk(&DAT_0010135b,"qiib_add_device",puVar6[3]);
                ipc_log_string(qiib_info[0xb],"%s: device_create() failed for dev [%s]\n",
                               "qiib_add_device",puVar6[3]);
                cdev_del(puVar12);
                uVar2 = 0xfffffff4;
                goto LAB_00100820;
              }
              mutex_lock(qiib_info + 2);
              puVar12 = qiib_info;
              uVar11 = *qiib_info;
              uVar5 = __list_add_valid(puVar6,qiib_info,uVar11);
              if ((uVar5 & 1) != 0) {
                *(ulong **)(uVar11 + 8) = puVar6;
                *puVar6 = uVar11;
                puVar6[1] = (ulong)puVar12;
                *puVar12 = (ulong)puVar6;
              }
              mutex_unlock(qiib_info + 2);
              if ((int)uVar2 < 0) goto LAB_00100820;
              iVar3 = irq_of_parse_and_map(lVar4,0);
              *(int *)(puVar6 + 0x19) = iVar3;
              if (iVar3 == 0) {
                _printk(&DAT_001015b2,"qiib_init_notifs","interrupts");
                ipc_log_string(qiib_info[0xb],"%s: missing key: %s\n","qiib_init_notifs",
                               "interrupts");
                uVar2 = 0xffffffed;
LAB_00100970:
                _printk(&DAT_00101427,"qsee_ipc_irq_bridge_probe",uVar2);
                pcVar10 = "%s: qiib_init_notifs failed ret=%d\n";
                uVar8 = uVar2;
                goto LAB_001009a0;
              }
              if (qiib_info[0xb] != 0) {
                ipc_log_string(qiib_info[0xb],"%s: %s = %d\n","qiib_init_notifs","interrupts");
                iVar3 = (int)puVar6[0x19];
              }
              lVar7 = irq_get_irq_data(iVar3);
              if (lVar7 == 0) {
                _printk(&DAT_001015e7,"qiib_init_notifs",(int)puVar6[0x19]);
                ipc_log_string(qiib_info[0xb],"%s: get irqdata fail:%d\n","qiib_init_notifs",
                               (int)puVar6[0x19]);
                uVar2 = 0xffffffed;
                goto LAB_00100970;
              }
              uVar2 = **(uint **)(lVar7 + 0x10) & 0xf;
              if (qiib_info[0xb] != 0) {
                ipc_log_string(qiib_info[0xb],"%s: irqtype = %d\n","qiib_init_notifs",uVar2);
              }
              puVar12 = puVar6 + 0x1c;
              *puVar12 = (ulong)qiib_restart_notifier_cb;
              uVar5 = qcom_register_ssr_notifier(puVar6[0x1b],puVar12);
              puVar6[0x1f] = uVar5;
              if ((uVar5 == 0) || (0xfffffffffffff000 < uVar5)) {
                _printk(&DAT_00101540,"qiib_init_notifs");
                ipc_log_string(qiib_info[0xb],"%s: Could not register SSR notifier cb\n",
                               "qiib_init_notifs");
                uVar2 = 0xffffffea;
                goto LAB_00100970;
              }
              uVar2 = request_threaded_irq
                                ((int)puVar6[0x19],qiib_irq_handler,0,uVar2,puVar6[3],puVar6);
              if ((int)uVar2 < 0) {
                _printk(&DAT_001013d3,"qiib_init_notifs",(int)puVar6[0x19]);
                ipc_log_string(qiib_info[0xb],"%s: request_irq() failed on %d\n","qiib_init_notifs",
                               (int)puVar6[0x19]);
                qcom_unregister_ssr_notifier(puVar6[0x1f],puVar12);
                goto LAB_00100970;
              }
              uVar8 = uVar8 + 1;
              lVar4 = of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),lVar4);
            } while (lVar4 != 0);
          }
          if (qiib_info[0xb] != 0) {
            ipc_log_string(qiib_info[0xb],"%s: Driver Initialized.\n","qsee_ipc_irq_bridge_probe");
          }
          uVar2 = 0;
          goto LAB_00100614;
        }
        _printk(&DAT_00101a63,"qiib_alloc_chrdev_region");
        ipc_log_string(qiib_info[0xb],"%s: class_create() failed ENOMEM\n",
                       "qiib_alloc_chrdev_region");
        unregister_chrdev_region((uint)qiib_info[10] >> 0x14,(int)qiib_info[8]);
        uVar2 = 0xfffffff4;
      }
      else {
        _printk(&DAT_001014fc,"qiib_alloc_chrdev_region",uVar2);
        ipc_log_string(qiib_info[0xb],"%s: alloc_chrdev_region() failed ret:%i\n",
                       "qiib_alloc_chrdev_region",uVar2);
      }
      _printk(&DAT_001016ce,"qsee_ipc_irq_bridge_probe",uVar2);
      ipc_log_string(qiib_info[0xb],"%s: chrdev_region allocation failed ret:%i\n",
                     "qsee_ipc_irq_bridge_probe",uVar2);
      goto LAB_00100614;
    }
  }
  _printk(&DAT_00101693,"qsee_ipc_irq_bridge_probe",0);
  ipc_log_string(qiib_info[0xb],"%s:Fail nports = %d\n","qsee_ipc_irq_bridge_probe",
                 (int)qiib_info[8]);
  uVar2 = 0xffffffea;
LAB_00100614:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// qsee_ipc_irq_bridge_remove @ 00100a3c size=32
// signature: undefined qsee_ipc_irq_bridge_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qsee_ipc_irq_bridge_remove(void)

{
  qiib_cleanup();
  return 0;
}



//------------------------------------------------------------
// qiib_cleanup @ 00100a5c size=256
// signature: undefined qiib_cleanup(void)
// callers: [qsee_ipc_irq_bridge_probe, qsee_ipc_irq_bridge_remove]
//------------------------------------------------------------

void qiib_cleanup(void)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  mutex_lock(qiib_info + 2);
  plVar4 = (long *)*qiib_info;
  plVar5 = qiib_info;
  if (plVar4 != qiib_info) {
    do {
      plVar5 = (long *)*plVar4;
      cdev_del(plVar4 + 4);
      uVar3 = __list_del_entry_valid(plVar4);
      if ((uVar3 & 1) != 0) {
        lVar1 = *plVar4;
        plVar2 = (long *)plVar4[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
      device_destroy(qiib_info[9],*(uint *)(qiib_info + 10) & 0xfff00000 | *(uint *)(plVar4 + 2));
      if (plVar4[0x1f] != 0) {
        qcom_unregister_ssr_notifier(plVar4[0x1f],plVar4 + 0x1c);
      }
      kfree(plVar4);
      plVar4 = plVar5;
    } while (plVar5 != qiib_info);
  }
  mutex_unlock(plVar5 + 2);
  plVar4 = qiib_info;
  if ((qiib_info[9] != 0) && ((ulong)qiib_info[9] < 0xfffffffffffff001)) {
    class_destroy();
    plVar4 = qiib_info;
    qiib_info[9] = 0;
  }
  unregister_chrdev_region(*(uint *)(plVar4 + 10) >> 0x14,(int)plVar4[8]);
  return;
}



//------------------------------------------------------------
// qiib_poll @ 00100b60 size=336
// signature: undefined qiib_poll(void)
// callers: []
//------------------------------------------------------------

uint qiib_poll(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xd8);
  if (lVar4 == 0) {
    _printk(&DAT_00101824,"qiib_poll");
    ipc_log_string(*(undefined8 *)(qiib_info + 0x58),"%s on NULL device\n","qiib_poll");
    uVar3 = 8;
  }
  else if (*(char *)(lVar4 + 0x100) == '\0') {
    if (((param_2 != (undefined8 *)0x0) && (lVar4 != -0xb0)) &&
       (pcVar2 = (code *)*param_2, pcVar2 != (code *)0x0)) {
      if (*(int *)(pcVar2 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100bd8);
        (*pcVar2)();
      }
      (*pcVar2)();
      DataMemoryBarrier(2,3);
    }
    uVar1 = _raw_spin_lock_irqsave(lVar4 + 0xd0);
    if (*(int *)(lVar4 + 0xcc) == 0) {
      uVar3 = 0;
    }
    else {
      if (*(long *)(qiib_info + 0x58) != 0) {
        ipc_log_string(*(long *)(qiib_info + 0x58),"%s set POLLIN on [%s] count[%d]\n","qiib_poll",
                       *(undefined8 *)(lVar4 + 0x18));
      }
      uVar3 = 1;
      *(undefined4 *)(lVar4 + 0xcc) = 0;
    }
    _raw_spin_unlock_irqrestore(lVar4 + 0xd0,uVar1);
    if (*(char *)(lVar4 + 0x100) != '\0') {
      uVar3 = uVar3 | 0x2000;
      if (*(long *)(qiib_info + 0x58) != 0) {
        ipc_log_string(*(long *)(qiib_info + 0x58),"%s set POLLRDHUP on [%s] count[%d]\n",
                       "qiib_poll",*(undefined8 *)(lVar4 + 0x18),*(undefined4 *)(lVar4 + 0xcc));
      }
    }
  }
  else {
    uVar3 = 0x2000;
  }
  return uVar3;
}



//------------------------------------------------------------
// qiib_open @ 00100cb4 size=152
// signature: undefined qiib_open(void)
// callers: []
//------------------------------------------------------------

undefined8 qiib_open(long param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x290);
  lVar1 = lVar3 + -0x20;
  if (lVar1 == 0) {
    _printk(&DAT_00101824,"qiib_open");
    ipc_log_string(*(undefined8 *)(qiib_info + 0x58),"%s on NULL device\n","qiib_open");
    uVar2 = 0xffffffea;
  }
  else {
    *(long *)(param_2 + 0xd8) = lVar1;
    uVar2 = 0;
    if (*(long *)(qiib_info + 0x58) != 0) {
      ipc_log_string(*(long *)(qiib_info + 0x58),"%s on [%s]\n","qiib_open",
                     *(undefined8 *)(lVar3 + -8));
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// qiib_release @ 00100d50 size=144
// signature: undefined qiib_release(void)
// callers: []
//------------------------------------------------------------

undefined8 qiib_release(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (*(long *)(param_2 + 0xd8) == 0) {
    _printk(&DAT_00101824,"qiib_release");
    ipc_log_string(*(undefined8 *)(qiib_info + 0x58),"%s on NULL device\n","qiib_release");
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = 0;
    if (*(long *)(qiib_info + 0x58) != 0) {
      ipc_log_string(*(long *)(qiib_info + 0x58),"%s on [%s]\n","qiib_release",
                     *(undefined8 *)(*(long *)(param_2 + 0xd8) + 0x18));
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// qiib_restart_notifier_cb @ 00100de4 size=212
// signature: undefined qiib_restart_notifier_cb(void)
// callers: []
//------------------------------------------------------------

undefined1  [16] qiib_restart_notifier_cb(long param_1,long param_2)

{
  undefined1 auVar1 [16];
  
  if (param_2 == 1) {
    if (*(long *)(qiib_info + 0x58) != 0) {
      ipc_log_string(*(long *)(qiib_info + 0x58),"%s: %s: subsystem restart for %s\n",
                     "qiib_restart_notifier_cb","QCOM_SSR_AFTER_POWERUP",
                     *(undefined8 *)(param_1 + -8));
    }
    *(undefined1 *)(param_1 + 0x20) = 0;
  }
  else if (param_2 == 2) {
    if (*(long *)(qiib_info + 0x58) != 0) {
      ipc_log_string(*(long *)(qiib_info + 0x58),"%s: %s: subsystem restart for %s\n",
                     "qiib_restart_notifier_cb","QCOM_SSR_BEFORE_SHUTDOWN",
                     *(undefined8 *)(param_1 + -8));
    }
    *(undefined1 *)(param_1 + 0x20) = 1;
    __wake_up(param_1 + -0x30,1,1,0);
  }
  auVar1._8_8_ = 0;
  auVar1._0_8_ = *(ulong *)(param_1 + -8);
  return auVar1 << 0x40;
}



//------------------------------------------------------------
// qiib_irq_handler @ 00101018 size=140
// signature: undefined qiib_irq_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qiib_irq_handler(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_2 + 0xd0);
  *(int *)(param_2 + 0xcc) = *(int *)(param_2 + 0xcc) + 1;
  _raw_spin_unlock_irqrestore(param_2 + 0xd0,uVar1);
  __wake_up(param_2 + 0xb0,1,1,0);
  if (*(long *)(qiib_info + 0x58) != 0) {
    ipc_log_string(*(long *)(qiib_info + 0x58),"%s name[%s] pend_count[%d]\n","qiib_irq_handler",
                   *(undefined8 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0xcc));
  }
  return 1;
}



//------------------------------------------------------------
// init_module @ 001010b4 size=340
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int init_module(void)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  
  lVar2 = kmalloc_trace(_platform_driver_unregister,0xdc0,0x60);
  qiib_info = lVar2;
  if (lVar2 == 0) {
    iVar1 = -0xc;
    _printk(&DAT_00101904,"qsee_ipc_irq_bridge_init",0xfffffff4);
    pcVar3 = "%s: driver data init failed %d\n";
  }
  else {
    *(long *)lVar2 = lVar2;
    *(long *)(lVar2 + 8) = lVar2;
    __mutex_init(lVar2 + 0x10,"&qiib_info->list_lock",&qiib_driver_data_init___key);
    lVar2 = ipc_log_context_create(4,"qsee_ipc_irq_bridge",0);
    *(long *)(qiib_info + 0x58) = lVar2;
    if (lVar2 == 0) {
      _printk(&DAT_0010193f,"qiib_driver_data_init");
      ipc_log_string(*(undefined8 *)(qiib_info + 0x58),"%s: unable to create logging context\n",
                     "qiib_driver_data_init");
    }
    iVar1 = __platform_driver_register(&qsee_ipc_irq_bridge_driver,&__this_module);
    if (iVar1 == 0) {
      return 0;
    }
    _printk(&DAT_001014b8,"qsee_ipc_irq_bridge_init",iVar1);
    pcVar3 = "%s: platform driver register failed %d\n";
  }
  ipc_log_string(*(undefined8 *)(qiib_info + 0x58),pcVar3,"qsee_ipc_irq_bridge_init",iVar1);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010120c size=80
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qsee_ipc_irq_bridge_driver);
  if (*(long *)(qiib_info + 0x58) == 0) {
    ipc_log_context_destroy(0);
  }
  kfree(qiib_info);
  qiib_info = 0;
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00103008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qsee_ipc_irq_bridge_probe, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103010 size=1
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
// ipc_log_context_create @ 00103018 size=1
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
// __platform_driver_register @ 00103020 size=1
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
// _printk @ 00103028 size=1
// signature: undefined _printk(void)
// callers: [qiib_release, qiib_poll, qsee_ipc_irq_bridge_probe, qiib_open, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00103030 size=1
// signature: undefined ipc_log_string(void)
// callers: [qiib_release, qiib_poll, qsee_ipc_irq_bridge_probe, qiib_restart_notifier_cb, qiib_open, init_module, qiib_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 00103038 size=1
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
// ipc_log_context_destroy @ 00103040 size=1
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
// kfree @ 00103048 size=1
// signature: undefined kfree(void)
// callers: [qiib_cleanup, cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00103050 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00103058 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00103060 size=1
// signature: undefined __class_create(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00103068 size=1
// signature: undefined of_property_read_string(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00103070 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00103078 size=1
// signature: undefined cdev_init(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00103080 size=1
// signature: undefined cdev_add(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00103088 size=1
// signature: undefined device_create(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103090 size=1
// signature: undefined mutex_lock(void)
// callers: [qsee_ipc_irq_bridge_probe, qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103098 size=1
// signature: undefined __list_add_valid(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001030a0 size=1
// signature: undefined mutex_unlock(void)
// callers: [qsee_ipc_irq_bridge_probe, qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_of_parse_and_map @ 001030a8 size=1
// signature: undefined irq_of_parse_and_map(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_of_parse_and_map(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_get_irq_data @ 001030b0 size=1
// signature: undefined irq_get_irq_data(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_get_irq_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 001030b8 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 001030c0 size=1
// signature: undefined request_threaded_irq(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001030c8 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [qsee_ipc_irq_bridge_probe, qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 001030d0 size=1
// signature: undefined cdev_del(void)
// callers: [qsee_ipc_irq_bridge_probe, qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 001030d8 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [qsee_ipc_irq_bridge_probe, qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030e0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qsee_ipc_irq_bridge_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030e8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 001030f0 size=1
// signature: undefined device_destroy(void)
// callers: [qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 001030f8 size=1
// signature: undefined class_destroy(void)
// callers: [qiib_cleanup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103100 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qiib_poll, qiib_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103108 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qiib_poll, qiib_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00103118 size=1
// signature: undefined __wake_up(void)
// callers: [qiib_restart_notifier_cb, qiib_irq_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



