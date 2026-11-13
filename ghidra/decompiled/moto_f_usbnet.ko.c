// Decompiled by Ghidra 12.2
// Program: moto_f_usbnet.ko
// Image base: 00100000

//------------------------------------------------------------
// usb_get_recv_request @ 00100714 size=140
// signature: undefined usb_get_recv_request(void)
// callers: []
//------------------------------------------------------------

long * usb_get_recv_request(long param_1)

{
  long lVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  long *plVar6;
  
  uVar3 = _raw_spin_lock_irqsave();
  plVar6 = *(long **)(param_1 + 0x38);
  if (plVar6 == (long *)(param_1 + 0x38)) {
    plVar5 = (long *)0x0;
  }
  else {
    plVar5 = plVar6 + -8;
    uVar4 = __list_del_entry_valid(plVar6);
    if ((uVar4 & 1) != 0) {
      lVar1 = *plVar6;
      plVar2 = (long *)plVar6[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    *plVar6 = -0x2152ffffffffff00;
    plVar6[1] = -0x2152fffffffffede;
  }
  _raw_spin_unlock_irqrestore(param_1,uVar3);
  return plVar5;
}



//------------------------------------------------------------
// usb_get_xmit_request @ 001007a4 size=236
// signature: undefined usb_get_xmit_request(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * usb_get_xmit_request(int param_1,long param_2)

{
  long *plVar1;
  ulong *puVar2;
  long *plVar3;
  char cVar4;
  bool bVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  
  uVar6 = _raw_spin_lock_irqsave(param_2 + 0xa40);
  plVar10 = *(long **)(param_2 + 0xa88);
  plVar1 = (long *)(param_2 + 0xa88);
  if (plVar10 == plVar1) {
    plVar9 = (long *)0x0;
  }
  else {
    plVar9 = plVar10 + -8;
    uVar7 = __list_del_entry_valid(plVar10);
    if ((uVar7 & 1) != 0) {
      lVar8 = *plVar10;
      plVar3 = (long *)plVar10[1];
      *(long **)(lVar8 + 8) = plVar3;
      *plVar3 = lVar8;
    }
    *plVar10 = -0x2152ffffffffff00;
    plVar10[1] = -0x2152fffffffffede;
    if ((param_1 == 1) && ((long *)*plVar1 == plVar1)) {
      lVar8 = *(long *)(param_2 + 0x3c0);
      *(undefined8 *)(lVar8 + 200) = _jiffies;
      DataMemoryBarrier(2,3);
      puVar2 = (ulong *)(lVar8 + 0xd0);
      Hint_Prefetch(puVar2,2,0,1);
      do {
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar2,0x10);
        if (bVar5) {
          *puVar2 = *puVar2 | 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
    }
  }
  _raw_spin_unlock_irqrestore(param_2 + 0xa40,uVar6);
  return plVar9;
}



//------------------------------------------------------------
// usbnet_alloc_inst @ 001008a4 size=608
// signature: undefined usbnet_alloc_inst(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long usbnet_alloc_inst(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar2 = kmalloc_trace(_free_netdev,0xdc0,200);
  if (lVar2 == 0) {
    return -0xc;
  }
  *(code **)(lVar2 + 0xa8) = usbnet_set_inst_name;
  *(code **)(lVar2 + 0xb0) = usbnet_free_inst;
  config_group_init_type_name(lVar2,&DAT_00102b2e,&usbnet_func_type);
  lVar3 = kmalloc_trace(_free_netdev,0xdc0,0xe8);
  if (lVar3 == 0) {
    _printk(&DAT_00102f5e,"usbnet_alloc_inst");
  }
  else {
    *(long *)(lVar2 + 0xc0) = lVar3;
    lVar4 = alloc_netdev_mqs(400,"tcmd%d",0,usb_ether_setup,1,1);
    if (lVar4 == 0) {
      _printk(&DAT_00102c35,"usbnet_alloc_inst");
    }
    else {
      *(undefined4 *)(lVar4 + 0xe0) = 15000;
      iVar1 = register_netdev();
      if (iVar1 != 0) {
        _printk(&DAT_00102a9f,"usbnet_alloc_inst");
        free_netdev(lVar4);
        kfree(lVar2);
        kfree(lVar3);
        return -0x16;
      }
      iVar1 = device_create_file(lVar4 + 0x520,&dev_attr_description);
      if (-1 < iVar1) {
        iVar1 = sock_create_kern(&init_net,2,2,0,lVar4 + 0xb90);
        if (iVar1 < 0) {
          _printk(&DAT_00102dcc,"usbnet_alloc_inst",iVar1);
          device_remove_file(lVar4 + 0x520,&dev_attr_description);
          unregister_netdev(lVar4);
          free_netdev(lVar4);
          kfree(lVar2);
          kfree(lVar3);
          return (long)iVar1;
        }
        *(long *)(*(long *)(*(long *)(lVar4 + 0xb90) + 0x18) + 0x288) = lVar4 + 0xa40;
        *(undefined8 *)(lVar4 + 0xb50) = 0xfffffffe0;
        *(long *)(lVar4 + 0xb58) = lVar4 + 0xb58;
        *(long *)(lVar4 + 0xb60) = lVar4 + 0xb58;
        *(code **)(lVar4 + 0xb68) = usbnet_if_config;
        *(undefined8 *)(lVar4 + 0xb98) = 0xfffffffe0;
        *(long *)(lVar4 + 0xba0) = lVar4 + 0xba0;
        *(long *)(lVar4 + 0xba8) = lVar4 + 0xba0;
        *(code **)(lVar4 + 0xbb0) = eth_work;
        *(undefined2 *)(lVar4 + 0xa70) = 0;
        *(long *)(lVar3 + 0xe0) = lVar4 + 0xa40;
        *(undefined4 *)(lVar4 + 0xa40) = 0;
        return lVar2;
      }
      _printk(&DAT_001029f4,"usbnet_alloc_inst");
      unregister_netdev(lVar4);
      free_netdev(lVar4);
    }
    kfree(lVar2);
    lVar2 = lVar3;
  }
  kfree(lVar2);
  return -0xc;
}



//------------------------------------------------------------
// usbnet_alloc @ 00100b08 size=164
// signature: undefined usbnet_alloc(void)
// callers: []
//------------------------------------------------------------

undefined8 * usbnet_alloc(long param_1)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  puVar1 = *(undefined8 **)(param_1 + 0xc0);
  if (puVar1 < (undefined8 *)0xfffffffffffff001) {
    uVar2 = *(undefined8 *)(param_1 + 0xb8);
    puVar1[2] = &fs_function;
    puVar1[3] = &hs_function;
    puVar1[4] = &ss_function;
    puVar1[5] = &ss_function;
    puVar1[9] = usbnet_bind;
    puVar1[10] = usbnet_unbind;
    puVar1[0x12] = usbnet_suspend;
    puVar1[0x13] = usbnet_resume;
    puVar1[0xd] = usbnet_set_alt;
    *puVar1 = uVar2;
    puVar1[1] = &usbnet_strings;
    puVar1[0xf] = usbnet_disable;
    puVar1[0x10] = usbnet_ctrlrequest;
    puVar1[0xb] = usbnet_free_func;
    *(undefined8 **)(param_1 + 0xa0) = puVar1;
    return puVar1;
  }
  return (undefined8 *)0x0;
}



//------------------------------------------------------------
// usbnet_set_inst_name @ 00100bb0 size=108
// signature: undefined usbnet_set_inst_name(void)
// callers: []
//------------------------------------------------------------

undefined8 usbnet_set_inst_name(long param_1,char *param_2)

{
  int iVar1;
  size_t sVar2;
  undefined8 uVar3;
  long lVar4;
  
  sVar2 = strlen(param_2);
  iVar1 = (int)sVar2 + 1;
  if (iVar1 < 0x29) {
    lVar4 = kstrndup(param_2,(long)iVar1,0xcc0);
    if (lVar4 == 0) {
      uVar3 = 0xfffffff4;
    }
    else {
      uVar3 = 0;
      *(long *)(param_1 + 0xb8) = lVar4;
    }
  }
  else {
    uVar3 = 0xffffffdc;
  }
  return uVar3;
}



//------------------------------------------------------------
// usbnet_free_inst @ 00100c20 size=208
// signature: undefined usbnet_free_inst(void)
// callers: []
//------------------------------------------------------------

void usbnet_free_inst(long param_1)

{
  code *pcVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  
  uVar3 = *(ulong *)(param_1 + 0xc0);
  if ((uVar3 < 0xfffffffffffff001) && (lVar4 = *(long *)(uVar3 + 0xe0), lVar4 != 0)) {
    lVar2 = *(long *)(lVar4 + 0x150);
    if (lVar2 != 0) {
      pcVar1 = *(code **)(*(long *)(lVar2 + 0x20) + 0x68);
      if (*(int *)(pcVar1 + -4) != 0x1d0d874c) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100c7c);
        (*pcVar1)();
      }
      (*pcVar1)(lVar2,2);
      *(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x288) = 0;
      sock_release(lVar2);
      *(undefined8 *)(lVar4 + 0x150) = 0;
      lVar4 = *(long *)(uVar3 + 0xe0);
      if (lVar4 == 0) goto LAB_00100ccc;
    }
    device_remove_file(*(long *)(lVar4 + 8) + 0x520,&dev_attr_description);
    unregister_netdev(*(undefined8 *)(lVar4 + 8));
    flush_work(lVar4 + 0x158);
    free_netdev(*(undefined8 *)(lVar4 + 8));
    *(undefined8 *)(uVar3 + 0xe0) = 0;
  }
LAB_00100ccc:
  kfree(*(undefined8 *)(param_1 + 0xb8));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// usb_ether_setup @ 00100cf4 size=200
// signature: undefined usb_ether_setup(void)
// callers: []
//------------------------------------------------------------

void usb_ether_setup(long param_1)

{
  long lVar1;
  uint local_30;
  undefined2 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  *(long *)(param_1 + 0xa78) = param_1 + 0xa78;
  *(long *)(param_1 + 0xa80) = param_1 + 0xa78;
  *(long *)(param_1 + 0xa88) = param_1 + 0xa88;
  *(long *)(param_1 + 0xa90) = param_1 + 0xa88;
  *(undefined4 *)(param_1 + 0xa40) = 0;
  *(long *)(param_1 + 0xa48) = param_1;
  *(undefined1 **)(param_1 + 0xd0) = &usbnet_eth_netdev_ops;
  *(undefined4 *)(param_1 + 0x4c0) = 0x14;
  ether_setup();
  local_2c = 0;
  local_30 = 0;
  get_random_bytes(&local_30,6);
  local_30 = local_30 & 0xfffffffc | 2;
  dev_addr_mod(param_1,0,&local_30,6);
  *(undefined1 *)(param_1 + 0x244) = 1;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// usbnet_if_config @ 00100dc0 size=552
// signature: undefined usbnet_if_config(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void usbnet_if_config(long param_1)

{
  int iVar1;
  long lVar2;
  undefined **ppuVar3;
  long *plVar4;
  long lVar5;
  
  if (*(long *)(param_1 + 0x40) == 0) {
    if (param_1 == 0x110) {
      return;
    }
    if (*(long *)(param_1 + -0x100) == 0) {
      return;
    }
    _dev_info(*(long *)(param_1 + -0x100) + 0x78,"%s: Error, socket is empty\n","usbnet_if_config");
    return;
  }
  plVar4 = (long *)(param_1 + -0x108);
  *(undefined8 *)(*(long *)(*(long *)(param_1 + 0x40) + 0x18) + 0x30) =
       *(undefined8 *)(*plVar4 + 0x500);
  _printk(&DAT_00102df1,"usbnet_if_config",*(undefined2 *)(param_1 + -0xe0),
          *(undefined4 *)(param_1 + 0x30));
  _printk(&DAT_00102a14,*(undefined4 *)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x38),
          *(undefined4 *)(param_1 + 0x3c));
  lVar2 = *plVar4 + 0x520;
  if (*(int *)(param_1 + 0x3c) == 0) {
    device_remove_file(lVar2,&dev_attr_ip_addr);
    device_remove_file(lVar2,&dev_attr_subnet_mask);
    ppuVar3 = &dev_attr_iff_flag;
  }
  else {
    iVar1 = device_create_file();
    if (iVar1 < 0) {
      _printk(&DAT_00102add,"usbnet_add_files",iVar1);
      goto LAB_00100f0c;
    }
    iVar1 = device_create_file(lVar2,&dev_attr_subnet_mask);
    if (iVar1 < 0) {
      _printk(&DAT_00102bc8,"usbnet_add_files",iVar1);
      ppuVar3 = &dev_attr_ip_addr;
    }
    else {
      iVar1 = device_create_file(lVar2,&dev_attr_iff_flag);
      if (-1 < iVar1) goto LAB_00100f0c;
      _printk(&DAT_00102e44,"usbnet_add_files",iVar1);
      device_remove_file(lVar2,&dev_attr_ip_addr);
      ppuVar3 = &dev_attr_subnet_mask;
    }
  }
  device_remove_file(lVar2,ppuVar3);
LAB_00100f0c:
  lVar5 = *plVar4;
  lVar2 = kmalloc_trace(_strlen,0xdc0,0xa20);
  if (lVar2 == 0) {
    if ((param_1 != 0x110) && (*(long *)(param_1 + -0x100) != 0)) {
      _dev_info(*(long *)(param_1 + -0x100) + 0x78,"%s: alloc uevent error\n",
                "usbnet_if_config_notify");
    }
  }
  else {
    add_uevent_var(lVar2,"USBNET_IF_CFG_IP_ADDR=0x%08x",*(undefined4 *)(param_1 + 0x30));
    add_uevent_var(lVar2,"USBNET_IP_CFG_ROUTER_ADDR=0x%08x",*(undefined4 *)(param_1 + 0x38));
    add_uevent_var(lVar2,"USBNET_IP_CFG_SUBNET_MASK=0x%08x",*(undefined4 *)(param_1 + 0x34));
    kobject_uevent_env(lVar5 + 0x520,2,lVar2 + 0x18);
    kfree(lVar2);
  }
  return;
}



//------------------------------------------------------------
// eth_work @ 00100fec size=152
// signature: undefined eth_work(void)
// callers: []
//------------------------------------------------------------

void eth_work(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  
  puVar1 = (ulong *)(param_1 + 0x30);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar4 = *puVar1;
    cVar2 = '\x01';
    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar3) {
      *puVar1 = uVar4 & 0xfffffffffffffffe;
      cVar2 = ExclusiveMonitorsStatus();
    }
  } while (cVar2 != '\0');
  DataMemoryBarrier(2,3);
  if (((uVar4 & 1) != 0) && ((*(ulong *)(*(long *)(param_1 + -0x150) + 0x38) & 1) != 0)) {
    rx_fill(param_1 + -0x158);
  }
  if (((param_1 + -0x158 != 0) && (*(long *)(param_1 + 0x30) != 0)) &&
     (*(long *)(param_1 + -0x148) != 0)) {
    _dev_info(*(long *)(param_1 + -0x148) + 0x78,"work done, flags = 0x%lx\n");
  }
  return;
}



//------------------------------------------------------------
// usbnet_opts_release @ 0010109c size=28
// signature: undefined usbnet_opts_release(void)
// callers: []
//------------------------------------------------------------

void usbnet_opts_release(void)

{
  usb_put_function_instance();
  return;
}



//------------------------------------------------------------
// usb_ether_open @ 001010bc size=308
// signature: undefined usb_ether_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 usb_ether_open(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  ulong uVar5;
  
  if (param_1 == -0xa40) {
    Hint_Prefetch(0x188,2,0,1);
    do {
      uVar5 = uRam0000000000000188;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(0x188,0x10);
      if (bVar3) {
        cVar2 = ExclusiveMonitorsStatus();
        uRam0000000000000188 = uRam0000000000000188 | 1;
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar5 & 1) == 0) {
      queue_work_on(0x20,_system_wq,0x158);
    }
  }
  else {
    if (*(long *)(param_1 + 0xa50) != 0) {
      _dev_info(*(long *)(param_1 + 0xa50) + 0x78,&DAT_00102dbc,"usb_ether_open");
    }
    puVar1 = (ulong *)(param_1 + 0xbc8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar5 = *puVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = uVar5 | 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar5 & 1) == 0) {
      uVar5 = queue_work_on(0x20,_system_wq,param_1 + 0xb98);
      if ((uVar5 & 1) == 0) {
        if (*(long *)(param_1 + 0xa50) == 0) {
          return 0;
        }
        _dev_info(*(long *)(param_1 + 0xa50) + 0x78,"kevent %d may have been dropped\n",0);
        lVar4 = *(long *)(param_1 + 0xa50);
      }
      else {
        lVar4 = *(long *)(param_1 + 0xa50);
      }
      if (lVar4 == 0) {
        return 0;
      }
      _dev_info(lVar4 + 0x78,"kevent %d schedule done\n",0);
    }
    if (*(long *)(param_1 + 0xa50) != 0) {
      _dev_info(*(long *)(param_1 + 0xa50) + 0x78,"restart rx work\n");
    }
  }
  return 0;
}



//------------------------------------------------------------
// usb_ether_stop @ 00101214 size=72
// signature: undefined usb_ether_stop(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_ether_stop(long param_1)

{
  if ((param_1 != -0xa40) && (*(long *)(param_1 + 0xa50) != 0)) {
    _dev_info(*(long *)(param_1 + 0xa50) + 0x78,&DAT_00102dbc,"usb_ether_stop");
  }
  return 0;
}



//------------------------------------------------------------
// usb_ether_xmit @ 00101260 size=564
// signature: undefined usb_ether_xmit(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 usb_ether_xmit(long param_1,long param_2)

{
  uint uVar1;
  long *plVar2;
  ulong *puVar3;
  uint uVar4;
  long *plVar5;
  char cVar6;
  bool bVar7;
  int iVar8;
  undefined8 uVar9;
  ulong uVar10;
  char *pcVar11;
  long lVar12;
  long lVar13;
  long *plVar14;
  undefined8 *puVar15;
  
  lVar13 = param_2 + 0xa40;
  if (*(long *)(param_2 + 0xa58) == 0) {
    __dev_kfree_skb_any(param_1,1);
    if (lVar13 == 0) {
      return 0;
    }
    lVar13 = *(long *)(param_2 + 0xa50);
    uVar9 = 0;
    if (lVar13 == 0) {
      return 0;
    }
    pcVar11 = "%s:bulk_in end point is disabled\n";
  }
  else if (*(char *)(*(long *)(param_2 + 0xa58) + 0x2d) == '\0') {
    __dev_kfree_skb_any(param_1,1);
    if (lVar13 == 0) {
      return 0;
    }
    lVar13 = *(long *)(param_2 + 0xa50);
    uVar9 = 0;
    if (lVar13 == 0) {
      return 0;
    }
    pcVar11 = "%s: bulk_in didn\'t enabled\n";
  }
  else {
    uVar9 = _raw_spin_lock_irqsave(lVar13);
    plVar14 = *(long **)(param_2 + 0xa88);
    plVar2 = (long *)(param_2 + 0xa88);
    if (plVar14 == plVar2) {
      _raw_spin_unlock_irqrestore(lVar13,uVar9);
    }
    else {
      uVar10 = __list_del_entry_valid(plVar14);
      if ((uVar10 & 1) != 0) {
        lVar12 = *plVar14;
        plVar5 = (long *)plVar14[1];
        *(long **)(lVar12 + 8) = plVar5;
        *plVar5 = lVar12;
      }
      *plVar14 = -0x2152ffffffffff00;
      plVar14[1] = -0x2152fffffffffede;
      if ((long *)*plVar2 == plVar2) {
        lVar12 = *(long *)(param_2 + 0x3c0);
        *(undefined8 *)(lVar12 + 200) = _jiffies;
        DataMemoryBarrier(2,3);
        puVar3 = (ulong *)(lVar12 + 0xd0);
        Hint_Prefetch(puVar3,2,0,1);
        do {
          cVar6 = '\x01';
          bVar7 = (bool)ExclusiveMonitorPass(puVar3,0x10);
          if (bVar7) {
            *puVar3 = *puVar3 | 1;
            cVar6 = ExclusiveMonitorsStatus();
          }
        } while (cVar6 != '\0');
      }
      _raw_spin_unlock_irqrestore(lVar13,uVar9);
      if (plVar14 + -8 != (long *)0x0) {
        uVar1 = *(int *)(param_1 + 0x70) + 4;
        uVar4 = *(int *)(param_1 + 0x70) + 5;
        if ((uVar1 & 0x3f) != 0) {
          uVar4 = uVar1;
        }
        *(uint *)(param_1 + 0x70) = uVar1;
        plVar14[-1] = param_1;
        lVar12 = *(long *)(param_1 + 0xe0);
        *(uint *)(plVar14 + -7) = uVar4;
        plVar14[-8] = lVar12;
        iVar8 = usb_ep_queue(*(undefined8 *)(param_2 + 0xa58),plVar14 + -8,0xcc0);
        if (iVar8 == 0) {
          return 0;
        }
        uVar9 = _raw_spin_lock_irqsave(lVar13);
        puVar15 = *(undefined8 **)(param_2 + 0xa90);
        uVar10 = __list_add_valid(plVar14,puVar15,plVar2);
        if ((uVar10 & 1) != 0) {
          *(long **)(param_2 + 0xa90) = plVar14;
          *plVar14 = (long)plVar2;
          plVar14[1] = (long)puVar15;
          *puVar15 = plVar14;
        }
        _raw_spin_unlock_irqrestore(lVar13,uVar9);
        __dev_kfree_skb_any(param_1,1);
        *(long *)(param_2 + 0xad0) = *(long *)(param_2 + 0xad0) + 1;
        if (lVar13 == 0) {
          return 0;
        }
        lVar13 = *(long *)(param_2 + 0xa50);
        uVar9 = 0;
        if (lVar13 == 0) {
          return 0;
        }
        pcVar11 = "%s: could not queue tx request\n";
        goto LAB_0010144c;
      }
    }
    if (lVar13 == 0) {
      return 0x10;
    }
    lVar13 = *(long *)(param_2 + 0xa50);
    uVar9 = 0x10;
    if (lVar13 == 0) {
      return 0x10;
    }
    pcVar11 = "%s: could not obtain tx request\n";
  }
LAB_0010144c:
  _dev_info(lVar13 + 0x78,pcVar11,"usb_ether_xmit");
  return uVar9;
}



//------------------------------------------------------------
// usb_ether_get_stats @ 001014a4 size=8
// signature: undefined usb_ether_get_stats(void)
// callers: []
//------------------------------------------------------------

long usb_ether_get_stats(long param_1)

{
  return param_1 + 0xa98;
}



//------------------------------------------------------------
// usbnet_desc_show @ 001014b0 size=56
// signature: undefined usbnet_desc_show(void)
// callers: []
//------------------------------------------------------------

long usbnet_desc_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1e,"%s\n","Motorola BLAN Interface");
  return (long)iVar1;
}



//------------------------------------------------------------
// usbnet_ip_addr_show @ 001014ec size=56
// signature: undefined usbnet_ip_addr_show(void)
// callers: []
//------------------------------------------------------------

long usbnet_ip_addr_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1e,"0x%08x\n",*(uint *)(param_1 + 0x660));
  return (long)iVar1;
}



//------------------------------------------------------------
// usbnet_subnet_mask_show @ 00101528 size=56
// signature: undefined usbnet_subnet_mask_show(void)
// callers: []
//------------------------------------------------------------

long usbnet_subnet_mask_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1e,"0x%08x\n",*(uint *)(param_1 + 0x664));
  return (long)iVar1;
}



//------------------------------------------------------------
// usbnet_iff_flag_show @ 00101564 size=56
// signature: undefined usbnet_iff_flag_show(void)
// callers: []
//------------------------------------------------------------

long usbnet_iff_flag_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1e,"0x%08x\n",*(uint *)(param_1 + 0x66c));
  return (long)iVar1;
}



//------------------------------------------------------------
// rx_fill @ 0010159c size=336
// signature: undefined rx_fill(void)
// callers: [eth_work, do_set_config]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rx_fill(long param_1)

{
  ulong *puVar1;
  long lVar2;
  long *plVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  long *plVar9;
  
  while( true ) {
    uVar7 = _raw_spin_lock_irqsave(param_1);
    plVar9 = *(long **)(param_1 + 0x38);
    if (plVar9 == (long *)(param_1 + 0x38)) {
      _raw_spin_unlock_irqrestore(param_1,uVar7);
      return;
    }
    uVar8 = __list_del_entry_valid(plVar9);
    if ((uVar8 & 1) != 0) {
      lVar2 = *plVar9;
      plVar3 = (long *)plVar9[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar9 = -0x2152ffffffffff00;
    plVar9[1] = -0x2152fffffffffede;
    _raw_spin_unlock_irqrestore(param_1,uVar7);
    if (plVar9 + -8 == (long *)0x0) break;
    iVar6 = ether_queue_out(plVar9 + -8,param_1);
    if (iVar6 < 0) {
      puVar1 = (ulong *)(param_1 + 0x188);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        uVar8 = *puVar1;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar5) {
          *puVar1 = uVar8 | 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      if ((uVar8 & 1) == 0) {
        uVar8 = queue_work_on(0x20,_system_wq,param_1 + 0x158);
        if ((param_1 == 0) || ((uVar8 & 1) != 0)) {
          if (param_1 == 0) {
            return;
          }
        }
        else if (*(long *)(param_1 + 0x10) != 0) {
          _dev_info(*(long *)(param_1 + 0x10) + 0x78,"kevent %d may have been dropped\n",0);
        }
        if (*(long *)(param_1 + 0x10) != 0) {
          _dev_info(*(long *)(param_1 + 0x10) + 0x78,"kevent %d schedule done\n",0);
        }
      }
      else if (param_1 == 0) {
        return;
      }
      if (*(long *)(param_1 + 0x10) != 0) {
        _dev_info(*(long *)(param_1 + 0x10) + 0x78,"rx_fill failed, defer_kevent\n");
      }
      return;
    }
  }
  return;
}



//------------------------------------------------------------
// ether_queue_out @ 001016fc size=524
// signature: undefined ether_queue_out(void)
// callers: [ether_out_complete, rx_fill]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ether_queue_out(undefined8 *param_1,long param_2)

{
  ulong *puVar1;
  undefined8 *puVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  uint uVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  long *plVar12;
  
  if (*(long *)(param_2 + 0x20) == 0) {
    return -0x16;
  }
  uVar8 = (uint)*(ushort *)(*(long *)(param_2 + 0x20) + 0x2e);
  uVar8 = uVar8 + 0x3bff & -uVar8;
  lVar6 = __alloc_skb(uVar8,0xa20,0,0xffffffff);
  if (lVar6 == 0) {
    if ((param_2 != 0) && (lVar10 = *(long *)(param_2 + 0x10), lVar10 != 0)) {
      pcVar7 = "%s: failed to alloc skb\n";
LAB_00101844:
      _dev_info(lVar10 + 0x78,pcVar7,"ether_queue_out");
    }
LAB_001017b4:
    puVar1 = (ulong *)(param_2 + 0x188);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar11 = *puVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = uVar11 | 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if ((uVar11 & 1) != 0) {
      iVar5 = -0xc;
      goto LAB_0010187c;
    }
    uVar11 = queue_work_on(0x20,_system_wq,param_2 + 0x158);
    if ((param_2 == 0) || ((uVar11 & 1) != 0)) {
      if (param_2 == 0) {
        iVar5 = -0xc;
        goto joined_r0x0010181c;
      }
    }
    else if (*(long *)(param_2 + 0x10) != 0) {
      _dev_info(*(long *)(param_2 + 0x10) + 0x78,"kevent %d may have been dropped\n",0);
    }
    if (*(long *)(param_2 + 0x10) != 0) {
      _dev_info(*(long *)(param_2 + 0x10) + 0x78,"kevent %d schedule done\n",0);
    }
    iVar5 = -0xc;
  }
  else {
    uVar9 = *(undefined8 *)(lVar6 + 0xe0);
    *(uint *)(param_1 + 1) = uVar8;
    param_1[7] = lVar6;
    *param_1 = uVar9;
    iVar5 = usb_ep_queue(*(undefined8 *)(param_2 + 0x20),param_1,0xcc0);
    if (iVar5 == 0) {
      return 0;
    }
    if (iVar5 == -0xc) {
      if ((param_2 != 0) && (lVar10 = *(long *)(param_2 + 0x10), lVar10 != 0)) {
        pcVar7 = "%s: failed to enqueue nomem\n";
        goto LAB_00101844;
      }
      goto LAB_001017b4;
    }
LAB_0010187c:
    if (param_2 == 0) goto joined_r0x0010181c;
  }
  if (*(long *)(param_2 + 0x10) != 0) {
    _dev_info(*(long *)(param_2 + 0x10) + 0x78,"ether_queue_out --> %d\n",iVar5);
  }
joined_r0x0010181c:
  if (lVar6 != 0) {
    __dev_kfree_skb_any(lVar6,1);
  }
  uVar9 = _raw_spin_lock_irqsave(param_2);
  plVar12 = *(long **)(param_2 + 0x40);
  puVar2 = param_1 + 8;
  uVar11 = __list_add_valid(puVar2,plVar12,param_2 + 0x38);
  if ((uVar11 & 1) != 0) {
    *(undefined8 **)(param_2 + 0x40) = puVar2;
    param_1[8] = param_2 + 0x38;
    param_1[9] = plVar12;
    *plVar12 = (long)puVar2;
  }
  _raw_spin_unlock_irqrestore(param_2,uVar9);
  return iVar5;
}



//------------------------------------------------------------
// usbnet_bind @ 0010191c size=788
// signature: undefined usbnet_bind(void)
// callers: []
//------------------------------------------------------------

int usbnet_bind(long param_1,long param_2)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  undefined8 uVar5;
  ulong uVar6;
  char *pcVar7;
  long lVar8;
  long *plVar9;
  
  plVar9 = *(long **)(param_1 + 0x30);
  lVar8 = *(long *)(param_2 + 0xe0);
  *(long **)(param_2 + 0xd8) = plVar9;
  iVar2 = usb_interface_id();
  if (iVar2 < 0) {
    return iVar2;
  }
  usbnet_intf_desc[2] = (undefined1)iVar2;
  if (usbnet_string_defs == '\0') {
    iVar2 = usb_string_id(*(undefined8 *)(param_1 + 0x30));
    if (iVar2 < 0) {
      if (lVar8 == 0) {
        return iVar2;
      }
      if (*(long *)(lVar8 + 0x10) == 0) {
        return iVar2;
      }
      _dev_info(*(long *)(lVar8 + 0x10) + 0x78,"string id returned %d\n",iVar2);
      return iVar2;
    }
    usbnet_intf_desc[8] = (char)iVar2;
    usbnet_string_defs = usbnet_intf_desc[8];
  }
  *(long *)(lVar8 + 0x10) = *plVar9;
  plVar3 = (long *)usb_ep_autoconfig(*plVar9,usbnet_fs_bulk_in_desc);
  if (plVar3 == (long *)0x0) {
    if ((lVar8 == 0) || (lVar8 = *(long *)(lVar8 + 0x10), lVar8 == 0)) goto LAB_00101b30;
    pcVar7 = "%s usbnet_hs_bulk_in_desc error\n";
  }
  else {
    *plVar3 = lVar8;
    *(long **)(lVar8 + 0x18) = plVar3;
    plVar3 = (long *)usb_ep_autoconfig(*plVar9,usbnet_fs_bulk_out_desc);
    if (plVar3 == (long *)0x0) {
      if ((lVar8 == 0) || (lVar8 = *(long *)(lVar8 + 0x10), lVar8 == 0)) goto LAB_00101b30;
      pcVar7 = "%s usbnet_hs_bulk_out_desc error\n";
    }
    else {
      *plVar3 = lVar8;
      *(long **)(lVar8 + 0x20) = plVar3;
      plVar3 = (long *)usb_ep_autoconfig(*plVar9,intr_out_desc);
      if (plVar3 != (long *)0x0) {
        *plVar3 = lVar8;
        *(long **)(lVar8 + 0x28) = plVar3;
        if (2 < *(uint *)(*plVar9 + 0x5c)) {
          usbnet_hs_bulk_in_desc[2] = usbnet_fs_bulk_in_desc[2];
          usbnet_hs_bulk_out_desc[2] = usbnet_fs_bulk_out_desc[2];
        }
        if (4 < *(uint *)(**(long **)(param_1 + 0x30) + 0x5c)) {
          usbnet_ss_bulk_in_desc[2] = usbnet_fs_bulk_in_desc[2];
          usbnet_ss_bulk_out_desc[2] = usbnet_fs_bulk_out_desc[2];
        }
        iVar2 = 0x50;
        do {
          lVar4 = usb_ep_alloc_request(*(undefined8 *)(lVar8 + 0x20),0xcc0);
          if (lVar4 == 0) {
            if ((lVar8 != 0) && (*(long *)(lVar8 + 0x10) != 0)) {
              _dev_info(*(long *)(lVar8 + 0x10) + 0x78,"%s: alloc request bulk_out fail\n",
                        "usbnet_bind");
            }
            break;
          }
          *(code **)(lVar4 + 0x30) = ether_out_complete;
          uVar5 = _raw_spin_lock_irqsave(lVar8);
          plVar9 = *(long **)(lVar8 + 0x40);
          lVar1 = lVar4 + 0x40;
          uVar6 = __list_add_valid(lVar1,plVar9,lVar8 + 0x38);
          if ((uVar6 & 1) != 0) {
            *(long *)(lVar8 + 0x40) = lVar1;
            *(long *)(lVar4 + 0x40) = lVar8 + 0x38;
            *(long **)(lVar4 + 0x48) = plVar9;
            *plVar9 = lVar1;
          }
          _raw_spin_unlock_irqrestore(lVar8,uVar5);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        iVar2 = 0x50;
        while (lVar4 = usb_ep_alloc_request(*(undefined8 *)(lVar8 + 0x18),0xcc0), lVar4 != 0) {
          *(code **)(lVar4 + 0x30) = ether_in_complete;
          uVar5 = _raw_spin_lock_irqsave(lVar8);
          plVar9 = *(long **)(lVar8 + 0x50);
          lVar1 = lVar4 + 0x40;
          uVar6 = __list_add_valid(lVar1,plVar9,lVar8 + 0x48);
          if ((uVar6 & 1) != 0) {
            *(long *)(lVar8 + 0x50) = lVar1;
            *(long *)(lVar4 + 0x40) = lVar8 + 0x48;
            *(long **)(lVar4 + 0x48) = plVar9;
            *plVar9 = lVar1;
          }
          _raw_spin_unlock_irqrestore(lVar8,uVar5);
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) {
            return 0;
          }
        }
        if (lVar8 == 0) {
          return 0;
        }
        if (*(long *)(lVar8 + 0x10) == 0) {
          return 0;
        }
        _dev_info(*(long *)(lVar8 + 0x10) + 0x78,"%s: alloc request bulk_in fail\n","usbnet_bind");
        return 0;
      }
      if ((lVar8 == 0) || (lVar8 = *(long *)(lVar8 + 0x10), lVar8 == 0)) goto LAB_00101b30;
      pcVar7 = "%s intr_out_desc error\n";
    }
  }
  _dev_info(lVar8 + 0x78,pcVar7,"usbnet_bind");
LAB_00101b30:
  usbnet_unbind(param_1,param_2);
  return -0x20c;
}



//------------------------------------------------------------
// usbnet_unbind @ 00101c34 size=396
// signature: undefined usbnet_unbind(void)
// callers: [usbnet_bind]
//------------------------------------------------------------

void usbnet_unbind(long param_1,long param_2)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  
  lVar4 = *(long *)(param_2 + 0xe0);
  *(undefined8 *)(param_2 + 0xd8) = *(undefined8 *)(param_1 + 0x30);
  if (*(long *)(lVar4 + 0x18) != 0) {
    usb_ep_disable();
  }
  if (*(long *)(lVar4 + 0x20) != 0) {
    usb_ep_disable();
    uVar2 = _raw_spin_lock_irqsave(lVar4);
    plVar6 = *(long **)(lVar4 + 0x38);
    while (plVar6 != (long *)(lVar4 + 0x38)) {
      uVar3 = __list_del_entry_valid(plVar6);
      if ((uVar3 & 1) != 0) {
        lVar5 = *plVar6;
        plVar1 = (long *)plVar6[1];
        *(long **)(lVar5 + 8) = plVar1;
        *plVar1 = lVar5;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar4,uVar2);
      if (plVar6 + -8 == (long *)0x0) goto LAB_00101cf8;
      usb_ep_free_request(*(undefined8 *)(lVar4 + 0x20),plVar6 + -8);
      uVar2 = _raw_spin_lock_irqsave(lVar4);
      plVar6 = *(long **)(lVar4 + 0x38);
    }
    _raw_spin_unlock_irqrestore(lVar4,uVar2);
  }
LAB_00101cf8:
  if (*(long *)(lVar4 + 0x18) != 0) {
    lVar7 = *(long *)(lVar4 + 8);
    lVar5 = lVar7 + 0xa40;
    uVar2 = _raw_spin_lock_irqsave(lVar5);
    plVar6 = *(long **)(lVar7 + 0xa88);
    if (plVar6 != (long *)(lVar7 + 0xa88)) {
      do {
        uVar3 = __list_del_entry_valid(plVar6);
        if ((uVar3 & 1) != 0) {
          lVar7 = *plVar6;
          plVar1 = (long *)plVar6[1];
          *(long **)(lVar7 + 8) = plVar1;
          *plVar1 = lVar7;
        }
        *plVar6 = -0x2152ffffffffff00;
        plVar6[1] = -0x2152fffffffffede;
        _raw_spin_unlock_irqrestore(lVar5,uVar2);
        if (plVar6 + -8 == (long *)0x0) goto LAB_00101d9c;
        usb_ep_free_request(*(undefined8 *)(lVar4 + 0x18),plVar6 + -8);
        lVar7 = *(long *)(lVar4 + 8);
        lVar5 = lVar7 + 0xa40;
        uVar2 = _raw_spin_lock_irqsave(lVar5);
        plVar6 = *(long **)(lVar7 + 0xa88);
      } while (plVar6 != (long *)(lVar7 + 0xa88));
    }
    _raw_spin_unlock_irqrestore(lVar5,uVar2);
  }
LAB_00101d9c:
  *(undefined2 *)(lVar4 + 0x30) = 0;
  *(undefined8 *)(lVar4 + 0x10) = 0;
  *(undefined8 *)(lVar4 + 0x18) = 0;
  *(undefined8 *)(lVar4 + 0x20) = 0;
  return;
}



//------------------------------------------------------------
// usbnet_set_alt @ 00101dc4 size=96
// signature: undefined usbnet_set_alt(void)
// callers: []
//------------------------------------------------------------

undefined8 usbnet_set_alt(long param_1,undefined4 param_2,undefined4 param_3)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0xe0) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x10), lVar1 != 0)) {
    _dev_info(lVar1 + 0x78,"usbnet_set_alt intf: %d alt: %d\n",param_2,param_3);
  }
  do_set_config(param_1,1);
  return 0;
}



//------------------------------------------------------------
// usbnet_disable @ 00101e28 size=92
// signature: undefined usbnet_disable(void)
// callers: []
//------------------------------------------------------------

void usbnet_disable(long param_1)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0xe0) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x10), lVar1 != 0)) {
    _dev_info(lVar1 + 0x78,&DAT_00102dbc,"usbnet_disable");
  }
  do_set_config(param_1,0);
  return;
}



//------------------------------------------------------------
// usbnet_suspend @ 00101e88 size=68
// signature: undefined usbnet_suspend(void)
// callers: []
//------------------------------------------------------------

void usbnet_suspend(long param_1)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0xe0) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x10), lVar1 != 0)) {
    _dev_info(lVar1 + 0x78,&DAT_00102dbc,"usbnet_suspend");
  }
  return;
}



//------------------------------------------------------------
// usbnet_resume @ 00101ed0 size=68
// signature: undefined usbnet_resume(void)
// callers: []
//------------------------------------------------------------

void usbnet_resume(long param_1)

{
  long lVar1;
  
  if ((*(long *)(param_1 + 0xe0) != 0) &&
     (lVar1 = *(long *)(*(long *)(param_1 + 0xe0) + 0x10), lVar1 != 0)) {
    _dev_info(lVar1 + 0x78,&DAT_00102dbc,"usbnet_resume");
  }
  return;
}



//------------------------------------------------------------
// usbnet_ctrlrequest @ 00101f18 size=364
// signature: undefined usbnet_ctrlrequest(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int usbnet_ctrlrequest(long param_1,byte *param_2)

{
  long lVar1;
  int iVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  short sVar6;
  bool bVar7;
  undefined8 uVar8;
  int iVar9;
  long lVar10;
  
  if ((*param_2 & 0x60) != 0x40) {
    return -0x5f;
  }
  lVar1 = *(long *)(param_1 + 0xe0);
  bVar3 = param_2[1];
  uVar4 = *(undefined2 *)(param_2 + 4);
  uVar5 = *(undefined2 *)(param_2 + 2);
  sVar6 = *(short *)(param_2 + 6);
  lVar10 = *(long *)(*(long *)(param_1 + 0xd8) + 8);
  if (bVar3 == 7) {
    *(uint *)(lVar1 + 0x148) = CONCAT22(uVar5,uVar4);
    iVar2 = *(int *)(lVar1 + 0x140);
  }
  else {
    if (bVar3 == 6) {
      iVar9 = 0;
      bVar7 = true;
      *(uint *)(lVar1 + 0x144) = CONCAT22(uVar5,uVar4);
      iVar2 = *(int *)(lVar1 + 0x140);
      uVar8 = _system_wq;
      goto joined_r0x00101fc8;
    }
    if (bVar3 != 5) {
      bVar7 = false;
      iVar9 = -0x5f;
      iVar2 = *(int *)(lVar1 + 0x140);
      uVar8 = _system_wq;
      goto joined_r0x00101fc8;
    }
    *(uint *)(lVar1 + 0x140) = CONCAT22(uVar5,uVar4);
    iVar2 = *(int *)(lVar1 + 0x140);
  }
  iVar9 = 0;
  bVar7 = true;
  uVar8 = _system_wq;
joined_r0x00101fc8:
  _system_wq = uVar8;
  if (((iVar2 != 0) && (*(int *)(lVar1 + 0x144) != 0)) && (*(int *)(lVar1 + 0x148) != 0)) {
    *(undefined4 *)(lVar1 + 0x14c) = 1;
    queue_work_on(0x20,uVar8,lVar1 + 0x110);
  }
  if (bVar7) {
    *(undefined4 *)(lVar10 + 8) = 0;
    *(uint *)(lVar10 + 0x28) =
         *(uint *)(lVar10 + 0x28) & 0xfff80000 |
         *(uint *)(lVar10 + 0x28) & 0x3ffff | (uint)(sVar6 != 0) << 0x12;
    iVar9 = usb_ep_queue(*(undefined8 *)(**(long **)(param_1 + 0xd8) + 0x40),lVar10,0xa20);
    if (((iVar9 < 0) && (lVar1 != 0)) && (*(long *)(lVar1 + 0x10) != 0)) {
      _dev_info(*(long *)(lVar1 + 0x10) + 0x78,"usbnet setup response error\n");
    }
  }
  return iVar9;
}



//------------------------------------------------------------
// usbnet_free_func @ 00102088 size=4
// signature: undefined usbnet_free_func(void)
// callers: []
//------------------------------------------------------------

void usbnet_free_func(void)

{
  return;
}



//------------------------------------------------------------
// ether_out_complete @ 00102090 size=412
// signature: undefined ether_out_complete(void)
// callers: []
//------------------------------------------------------------

void ether_out_complete(long *param_1,long param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  char *pcVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  
  lVar8 = *(long *)(param_2 + 0x38);
  lVar7 = *param_1;
  if (*(int *)(param_2 + 0x54) != 0) {
    __dev_kfree_skb_any(lVar8,1);
    *(long *)(lVar7 + 0x78) = *(long *)(lVar7 + 0x78) + 1;
    goto LAB_00102174;
  }
  skb_put(lVar8,*(undefined4 *)(param_2 + 0x58));
  uVar1 = eth_type_trans(lVar8,*(undefined8 *)(lVar7 + 8));
  *(undefined2 *)(lVar8 + 0xb4) = uVar1;
  *(long *)(lVar7 + 0x58) = *(long *)(lVar7 + 0x58) + 1;
  *(ulong *)(lVar7 + 0x68) = *(long *)(lVar7 + 0x68) + (ulong)*(uint *)(param_2 + 0x58);
  iVar2 = *(int *)(lVar8 + 0x70);
  if (iVar2 - 0x3a99U < 0xffffc575) {
    if ((lVar7 != 0) && (lVar6 = *(long *)(lVar7 + 0x10), lVar6 != 0)) {
      pcVar5 = "rx length not right %d\n";
LAB_00102224:
      _dev_info(lVar6 + 0x78,pcVar5,iVar2);
    }
  }
  else {
    iVar2 = netif_rx(lVar8);
    if (-1 < iVar2) goto LAB_00102174;
    if ((lVar7 != 0) && (lVar6 = *(long *)(lVar7 + 0x10), lVar6 != 0)) {
      pcVar5 = "netif_rx failed  %d\n";
      goto LAB_00102224;
    }
  }
  *(long *)(lVar7 + 0x78) = *(long *)(lVar7 + 0x78) + 1;
  __dev_kfree_skb_any(lVar8,1);
LAB_00102174:
  if ((*(int *)(param_2 + 0x54) == -0x13) || (*(int *)(param_2 + 0x54) == -0x6c)) {
    uVar3 = _raw_spin_lock_irqsave(lVar7);
    plVar9 = *(long **)(lVar7 + 0x40);
    lVar8 = param_2 + 0x40;
    uVar4 = __list_add_valid(lVar8,plVar9,lVar7 + 0x38);
    if ((uVar4 & 1) != 0) {
      *(long *)(lVar7 + 0x40) = lVar8;
      *(long *)(param_2 + 0x40) = lVar7 + 0x38;
      *(long **)(param_2 + 0x48) = plVar9;
      *plVar9 = lVar8;
    }
    _raw_spin_unlock_irqrestore(lVar7,uVar3);
  }
  else {
    iVar2 = ether_queue_out(param_2,lVar7);
    if ((iVar2 != 0) && ((lVar7 != 0 && (*(long *)(lVar7 + 0x10) != 0)))) {
      _dev_info(*(long *)(lVar7 + 0x10) + 0x78,"ether_out: cannot requeue\n");
    }
  }
  return;
}



//------------------------------------------------------------
// ether_in_complete @ 00102230 size=248
// signature: undefined ether_in_complete(void)
// callers: []
//------------------------------------------------------------

void ether_in_complete(long *param_1,long param_2)

{
  long lVar1;
  ulong *puVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  
  uVar5 = *(undefined8 *)(param_2 + 0x38);
  lVar7 = *param_1;
  if (*(int *)(param_2 + 0x54) == 0) {
    *(long *)(lVar7 + 0x60) = *(long *)(lVar7 + 0x60) + 1;
    plVar8 = (long *)(lVar7 + 0x70);
    uVar6 = (ulong)*(uint *)(param_2 + 0x58);
  }
  else {
    plVar8 = (long *)(lVar7 + 0x80);
    uVar6 = 1;
  }
  *plVar8 = *plVar8 + uVar6;
  __dev_kfree_skb_any(uVar5,1);
  uVar5 = _raw_spin_lock_irqsave(lVar7);
  plVar8 = (long *)(lVar7 + 0x48);
  if ((long *)*plVar8 == plVar8) {
    puVar2 = (ulong *)(*(long *)(*(long *)(lVar7 + 8) + 0x3c0) + 0xd0);
    Hint_Prefetch(puVar2,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar2,0x10);
      if (bVar4) {
        *puVar2 = *puVar2 & 0xfffffffffffffffe;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
  }
  plVar9 = *(long **)(lVar7 + 0x50);
  lVar1 = param_2 + 0x40;
  uVar6 = __list_add_valid(lVar1,plVar9,plVar8);
  if ((uVar6 & 1) != 0) {
    *(long *)(lVar7 + 0x50) = lVar1;
    *(long **)(param_2 + 0x40) = plVar8;
    *(long **)(param_2 + 0x48) = plVar9;
    *plVar9 = lVar1;
  }
  _raw_spin_unlock_irqrestore(lVar7,uVar5);
  return;
}



//------------------------------------------------------------
// do_set_config @ 00102334 size=592
// signature: undefined do_set_config(void)
// callers: [usbnet_set_alt, usbnet_disable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void do_set_config(long param_1,short param_2)

{
  int iVar1;
  long lVar2;
  undefined8 *puVar3;
  
  lVar2 = *(long *)(param_1 + 0xe0);
  puVar3 = *(undefined8 **)(*(long *)(param_1 + 0x30) + 0x30);
  if ((lVar2 != 0) && (*(long *)(lVar2 + 0x10) != 0)) {
    _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"do_set_config ep %s\n",
              *(undefined8 *)(*(long *)(lVar2 + 0x18) + 8));
  }
  if (*(short *)(lVar2 + 0x30) != param_2) {
    *(short *)(lVar2 + 0x30) = param_2;
    if (param_2 == 1) {
      if ((lVar2 != 0) && (*(long *)(lVar2 + 0x10) != 0)) {
        _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"config_ep_by_speed ep %s\n",
                  *(undefined8 *)(*(long *)(lVar2 + 0x18) + 8));
      }
      iVar1 = config_ep_by_speed(*puVar3,param_1,*(undefined8 *)(lVar2 + 0x18));
      if (iVar1 == 0) {
        iVar1 = usb_ep_enable();
        if (((lVar2 != 0) && (iVar1 != 0)) && (*(long *)(lVar2 + 0x10) != 0)) {
          _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"%s:  failed to enable BULK_IN EP ret=%d\n",
                    "do_set_config",iVar1);
        }
        **(long **)(lVar2 + 0x18) = lVar2;
        iVar1 = config_ep_by_speed(*puVar3,param_1,*(undefined8 *)(lVar2 + 0x20));
        if (iVar1 == 0) {
          iVar1 = usb_ep_enable();
          if (((lVar2 != 0) && (iVar1 != 0)) && (*(long *)(lVar2 + 0x10) != 0)) {
            _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"%s: failed to enable BULK_OUT EP ret = %d\n",
                      "do_set_config",iVar1);
          }
          **(long **)(lVar2 + 0x20) = lVar2;
          *(undefined1 **)(*(long *)(lVar2 + 0x28) + 0x38) = intr_out_desc;
          iVar1 = usb_ep_enable(*(undefined8 *)(lVar2 + 0x28));
          if (((lVar2 != 0) && (iVar1 != 0)) && (*(long *)(lVar2 + 0x10) != 0)) {
            _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"%s: failed to enable INTR_OUT EP ret = %d\n",
                      "do_set_config",iVar1);
          }
          **(long **)(lVar2 + 0x28) = lVar2;
          rx_fill(lVar2);
        }
        else {
          *(undefined8 *)(*(long *)(lVar2 + 0x20) + 0x38) = 0;
          if ((lVar2 != 0) && (*(long *)(lVar2 + 0x10) != 0)) {
            _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"config_ep_by_speed failed: ep %s, result %d\n"
                      ,*(undefined8 *)(*(long *)(lVar2 + 0x20) + 8));
          }
          usb_ep_disable(*(undefined8 *)(lVar2 + 0x18));
        }
      }
      else {
        *(undefined8 *)(*(long *)(lVar2 + 0x18) + 0x38) = 0;
        if ((lVar2 != 0) && (*(long *)(lVar2 + 0x10) != 0)) {
          _dev_info(*(long *)(lVar2 + 0x10) + 0x78,"config_ep_by_speed failed: ep %s, result %d\n",
                    *(undefined8 *)(*(long *)(lVar2 + 0x18) + 8));
        }
      }
    }
    else {
      if (*(long *)(lVar2 + 0x18) != 0) {
        usb_ep_disable();
      }
      if (*(long *)(lVar2 + 0x20) != 0) {
        usb_ep_disable();
      }
      if (*(long *)(lVar2 + 0x28) != 0) {
        usb_ep_disable();
      }
      *(undefined8 *)(lVar2 + 0x140) = 0;
      *(undefined8 *)(lVar2 + 0x148) = 0;
      queue_work_on(0x20,_system_wq,lVar2 + 0x110);
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00102588 size=84
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = usb_function_register(&usbnetusb_func);
  if (iVar1 != 0) {
    _printk(&DAT_00102ee6,"usbnet_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 001025e0 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  usb_function_unregister(&usbnetusb_func);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ether_out_complete, ether_in_complete, usbnet_bind, usb_ether_xmit, usb_get_xmit_request, ether_queue_out, usbnet_unbind, rx_fill, usb_get_recv_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105008 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [usb_ether_xmit, usb_get_xmit_request, usbnet_unbind, rx_fill, usb_get_recv_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105010 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ether_out_complete, ether_in_complete, usbnet_bind, usb_ether_xmit, usb_get_xmit_request, ether_queue_out, usbnet_unbind, rx_fill, usb_get_recv_request]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_register @ 00105028 size=1
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
// _printk @ 00105030 size=1
// signature: undefined _printk(void)
// callers: [usbnet_alloc_inst, init_module, usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_unregister @ 00105038 size=1
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
// kmalloc_trace @ 00105048 size=1
// signature: undefined kmalloc_trace(void)
// callers: [usbnet_alloc_inst, usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 00105050 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_netdev_mqs @ 00105058 size=1
// signature: undefined alloc_netdev_mqs(void)
// callers: [usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_netdev_mqs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_netdev @ 00105060 size=1
// signature: undefined register_netdev(void)
// callers: [usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_netdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00105068 size=1
// signature: undefined device_create_file(void)
// callers: [usbnet_alloc_inst, usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_create_kern @ 00105078 size=1
// signature: undefined sock_create_kern(void)
// callers: [usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_create_kern(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_netdev @ 00105080 size=1
// signature: undefined free_netdev(void)
// callers: [usbnet_free_inst, usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_netdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105088 size=1
// signature: undefined kfree(void)
// callers: [usbnet_free_inst, usbnet_alloc_inst, usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_netdev @ 00105090 size=1
// signature: undefined unregister_netdev(void)
// callers: [usbnet_free_inst, usbnet_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_netdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00105098 size=1
// signature: undefined device_remove_file(void)
// callers: [usbnet_free_inst, usbnet_alloc_inst, usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001050a0 size=1
// signature: size_t strlen(char * __s)
// callers: [usbnet_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 001050a8 size=1
// signature: undefined kstrndup(void)
// callers: [usbnet_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sock_release @ 001050b0 size=1
// signature: undefined sock_release(void)
// callers: [usbnet_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sock_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_work @ 001050b8 size=1
// signature: undefined flush_work(void)
// callers: [usbnet_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ether_setup @ 001050c0 size=1
// signature: undefined ether_setup(void)
// callers: [usb_ether_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ether_setup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_random_bytes @ 001050c8 size=1
// signature: undefined get_random_bytes(void)
// callers: [usb_ether_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_random_bytes(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_addr_mod @ 001050d0 size=1
// signature: undefined dev_addr_mod(void)
// callers: [usb_ether_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_addr_mod(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001050d8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [usb_ether_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001050e0 size=1
// signature: undefined _dev_info(void)
// callers: [usb_ether_xmit, usbnet_suspend, eth_work, rx_fill, usbnet_set_alt, usbnet_if_config, usbnet_resume, do_set_config, usbnet_disable, usb_ether_stop, ether_out_complete, usb_ether_open, usbnet_bind, ether_queue_out, usbnet_ctrlrequest]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 001050e8 size=1
// signature: undefined add_uevent_var(void)
// callers: [usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 001050f0 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [usbnet_if_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_function_instance @ 001050f8 size=1
// signature: undefined usb_put_function_instance(void)
// callers: [usbnet_opts_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_function_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00105108 size=1
// signature: undefined queue_work_on(void)
// callers: [usb_ether_open, ether_queue_out, usbnet_ctrlrequest, rx_fill, do_set_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_queue @ 00105110 size=1
// signature: undefined usb_ep_queue(void)
// callers: [usb_ether_xmit, ether_queue_out, usbnet_ctrlrequest]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105118 size=1
// signature: undefined __list_add_valid(void)
// callers: [ether_out_complete, ether_in_complete, usbnet_bind, usb_ether_xmit, ether_queue_out]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __dev_kfree_skb_any @ 00105120 size=1
// signature: undefined __dev_kfree_skb_any(void)
// callers: [ether_out_complete, ether_in_complete, usb_ether_xmit, ether_queue_out]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __dev_kfree_skb_any(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00105128 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [usbnet_desc_show, usbnet_subnet_mask_show, usbnet_iff_flag_show, usbnet_ip_addr_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00105130 size=1
// signature: undefined __alloc_skb(void)
// callers: [ether_queue_out]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_interface_id @ 00105138 size=1
// signature: undefined usb_interface_id(void)
// callers: [usbnet_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_interface_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_string_id @ 00105140 size=1
// signature: undefined usb_string_id(void)
// callers: [usbnet_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_string_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_autoconfig @ 00105148 size=1
// signature: undefined usb_ep_autoconfig(void)
// callers: [usbnet_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_autoconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_alloc_request @ 00105150 size=1
// signature: undefined usb_ep_alloc_request(void)
// callers: [usbnet_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_disable @ 00105158 size=1
// signature: undefined usb_ep_disable(void)
// callers: [usbnet_unbind, do_set_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_free_request @ 00105160 size=1
// signature: undefined usb_ep_free_request(void)
// callers: [usbnet_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 00105168 size=1
// signature: undefined skb_put(void)
// callers: [ether_out_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// eth_type_trans @ 00105170 size=1
// signature: undefined eth_type_trans(void)
// callers: [ether_out_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void eth_type_trans(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netif_rx @ 00105178 size=1
// signature: undefined netif_rx(void)
// callers: [ether_out_complete]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netif_rx(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_ep_by_speed @ 00105180 size=1
// signature: undefined config_ep_by_speed(void)
// callers: [do_set_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_ep_by_speed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_enable @ 00105188 size=1
// signature: undefined usb_ep_enable(void)
// callers: [do_set_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



