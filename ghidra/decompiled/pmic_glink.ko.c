// Decompiled by Ghidra 12.2
// Program: pmic_glink.ko
// Image base: 00100000

//------------------------------------------------------------
// pmic_glink_write @ 00100394 size=380
// signature: undefined pmic_glink_write(void)
// callers: []
//------------------------------------------------------------

int pmic_glink_write(long *param_1,int *param_2,ulong param_3)

{
  int iVar1;
  
  if (((param_1 == (long *)0x0) || (*param_1 == 0)) || (param_1[1] == 0)) {
    iVar1 = -0x13;
  }
  else {
    down_read(*param_1 + 0x70);
    if ((*(long *)*param_1 == 0) || ((int)((long *)*param_1)[0x28] == 0)) {
      _printk(&DAT_00101cc0,"pmic_glink_write",param_1[1]);
      up_read(*param_1 + 0x70);
      iVar1 = -0x6b;
    }
    else {
      mutex_lock(param_1 + 3);
      iVar1 = rpmsg_send(*(undefined8 *)(*(long *)*param_1 + 0x3c8),param_2,param_3 & 0xffffffff);
      mutex_unlock(param_1 + 3);
      up_read(*param_1 + 0x70);
      if (iVar1 < 0) {
        _printk(&DAT_00101904,"pmic_glink_write",param_3,param_2,param_1[1],iVar1);
      }
      else if (iVar1 == 0) {
        if (*(char *)(*param_1 + 0x150) != '\0') {
          iVar1 = *(int *)(*param_1 + 0x14c);
          if (iVar1 == *param_2) {
            _printk(&DAT_00101a9c,"pmic_glink_write",param_3,param_2);
          }
          else if (iVar1 == 0xffff) {
            _printk(&DAT_00101dd8,"pmic_glink_write",*param_2,param_3,param_2);
          }
        }
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// pmic_glink_register_client @ 00100514 size=600
// signature: undefined pmic_glink_register_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * pmic_glink_register_client(long param_1,long *param_2)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 *puVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  undefined *puVar8;
  undefined **ppuVar9;
  long *plVar10;
  undefined **ppuVar11;
  
  if ((param_1 == 0) || (puVar8 = *(undefined **)(param_1 + 0x60), puVar8 == (undefined *)0x0)) {
    puVar4 = (undefined8 *)0xffffffffffffffed;
  }
  else if ((((int)param_2[1] == 0) || (param_2[3] == 0)) || (*param_2 == 0)) {
    puVar4 = (undefined8 *)0xffffffffffffffea;
  }
  else {
    mutex_lock(&pmic_glink_dev_lock);
    ppuVar11 = &pmic_glink_dev_list;
    do {
      ppuVar11 = (undefined **)*ppuVar11;
      if (ppuVar11 == &pmic_glink_dev_list) {
        mutex_unlock(&pmic_glink_dev_lock);
        goto LAB_001006f0;
      }
    } while (ppuVar11[-0x25] != puVar8);
    mutex_unlock(&pmic_glink_dev_lock);
    if (ppuVar11 + -0x26 == (undefined **)0x0) {
LAB_001006f0:
      _printk(&DAT_001016f5,"pmic_glink_register_client",*param_2);
      puVar4 = (undefined8 *)0xffffffffffffffed;
    }
    else {
      down_read(ppuVar11 + -0x18);
      iVar3 = *(int *)(ppuVar11 + 2);
      up_read(ppuVar11 + -0x18);
      if (iVar3 == 0) {
        _printk(&DAT_00101968,"pmic_glink_register_client");
        puVar4 = (undefined8 *)0xfffffffffffffdfb;
      }
      else {
        puVar4 = (undefined8 *)kmalloc_trace(_kfree,0xdc0,0x70);
        if (puVar4 == (undefined8 *)0x0) {
          puVar4 = (undefined8 *)0xfffffffffffffff4;
        }
        else {
          lVar5 = kstrdup(*param_2,0xcc0);
          puVar4[1] = lVar5;
          if (lVar5 == 0) {
            kfree(puVar4);
            puVar4 = (undefined8 *)0xfffffffffffffff4;
          }
          else {
            __mutex_init(puVar4 + 3,"&client->lock",&pmic_glink_register_client___key);
            lVar7 = param_2[1];
            *puVar4 = ppuVar11 + -0x26;
            lVar5 = param_2[2];
            lVar2 = param_2[3];
            *(int *)(puVar4 + 2) = (int)lVar7;
            lVar7 = param_2[4];
            ppuVar9 = ppuVar11 + -0x1e;
            puVar4[9] = lVar5;
            puVar4[10] = lVar2;
            puVar4[0xd] = lVar7;
            mutex_lock(ppuVar9);
            iVar3 = idr_alloc(ppuVar11 + -0x21,puVar4,*(int *)(puVar4 + 2),*(int *)(puVar4 + 2) + 1,
                              0xcc0);
            if (iVar3 < 0) {
              _printk(&DAT_00101cf7,"pmic_glink_register_client",puVar4[1],iVar3);
              mutex_unlock(ppuVar9);
              kfree(puVar4[1]);
              kfree(puVar4);
              puVar4 = (undefined8 *)(long)iVar3;
            }
            else {
              if (puVar4[0xd] != 0) {
                puVar1 = puVar4 + 0xb;
                puVar4[0xb] = puVar1;
                puVar4[0xc] = puVar1;
                plVar10 = (long *)ppuVar11[6];
                uVar6 = __list_add_valid(puVar1,plVar10,ppuVar11 + 5);
                if ((uVar6 & 1) != 0) {
                  ppuVar11[6] = (undefined *)puVar1;
                  puVar4[0xb] = ppuVar11 + 5;
                  puVar4[0xc] = plVar10;
                  *plVar10 = (long)puVar1;
                }
              }
              mutex_unlock(ppuVar9);
              ipc_log_string(ppuVar11[-0x22],"Registered client %s\n",puVar4[1]);
            }
          }
        }
      }
    }
  }
  return puVar4;
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00100770 size=240
// signature: undefined pmic_glink_unregister_client(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_glink_unregister_client(long *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    uVar2 = 0xffffffed;
  }
  else {
    mutex_lock(*param_1 + 0x40);
    lVar3 = *param_1;
    plVar4 = *(long **)(lVar3 + 0x158);
    if (plVar4 != (long *)(lVar3 + 0x158)) {
      do {
        plVar5 = plVar4 + -0xb;
        plVar4 = (long *)*plVar4;
        if (plVar5 == param_1) {
          uVar1 = __list_del_entry_valid(param_1 + 0xb);
          if ((uVar1 & 1) != 0) {
            lVar3 = param_1[0xb];
            plVar5 = (long *)param_1[0xc];
            *(long **)(lVar3 + 8) = plVar5;
            *plVar5 = lVar3;
          }
          lVar3 = *param_1;
          param_1[0xb] = -0x2152ffffffffff00;
          param_1[0xc] = -0x2152fffffffffede;
        }
      } while (plVar4 != (long *)(lVar3 + 0x158));
    }
    idr_remove(lVar3 + 0x28,(int)param_1[2]);
    mutex_unlock(*param_1 + 0x40);
    ipc_log_string(*(undefined8 *)(*param_1 + 0x20),"Unregistered client %s\n",param_1[1]);
    kfree(param_1[1]);
    kfree(param_1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// pmic_glink_probe @ 00100864 size=1260
// signature: undefined pmic_glink_probe(void)
// callers: []
//------------------------------------------------------------

ulong pmic_glink_probe(long param_1)

{
  long *plVar1;
  undefined *puVar2;
  uint uVar3;
  long lVar4;
  size_t sVar5;
  long lVar6;
  ulong uVar7;
  undefined *puVar8;
  undefined8 uVar9;
  char *__s;
  
  lVar4 = devm_kmalloc(param_1 + 0x10,0x1b0,0xdc0);
  if (lVar4 == 0) {
    uVar7 = 0xfffffff4;
    goto LAB_00100cb4;
  }
  uVar3 = of_property_read_string
                    (*(undefined8 *)(param_1 + 0x2f8),"qcom,pmic-glink-channel",
                     (undefined8 *)(lVar4 + 0x18));
  if ((int)uVar3 < 0) {
    uVar7 = (ulong)uVar3;
    puVar8 = &DAT_001017db;
    goto LAB_00100c84;
  }
  __s = *(char **)(lVar4 + 0x18);
  sVar5 = strlen(__s);
  if (0x20 < sVar5) {
    puVar8 = &DAT_00101b1f;
    goto LAB_00100cac;
  }
  plVar1 = (long *)(lVar4 + 0x180);
  of_property_read_string(*(undefined8 *)(param_1 + 0x2f8),"qcom,subsys-name",plVar1);
  lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,protection-domain",0);
  if (lVar6 != 0) {
    uVar3 = of_property_read_string_helper
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,protection-domain",
                       (undefined8 *)(lVar4 + 0x198),1,0);
    if ((int)uVar3 < 0) {
      uVar7 = (ulong)uVar3;
      puVar8 = &DAT_00101bfe;
LAB_00100c84:
      _printk(puVar8,"pmic_glink_probe",uVar7);
    }
    else {
      __s = *(char **)(lVar4 + 0x198);
      sVar5 = strlen(__s);
      if (sVar5 < 0x41) {
        uVar3 = of_property_read_string_helper
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,protection-domain",
                           (undefined8 *)(lVar4 + 0x1a0),1,1);
        if ((int)uVar3 < 0) {
          uVar7 = (ulong)uVar3;
          puVar8 = &DAT_00101a50;
          goto LAB_00100c84;
        }
        __s = *(char **)(lVar4 + 0x1a0);
        sVar5 = strlen(__s);
        if (sVar5 < 0x41) goto LAB_00100970;
        puVar8 = &DAT_001019bf;
      }
      else {
        puVar8 = &DAT_00101b5c;
      }
LAB_00100cac:
      _printk(puVar8,"pmic_glink_probe",__s);
      uVar7 = 0xffffffea;
    }
    goto LAB_00100cb4;
  }
LAB_00100970:
  lVar6 = alloc_workqueue(&DAT_00101901,0xe000a,1,"pmic_glink_rx");
  *(long *)(lVar4 + 0x118) = lVar6;
  if (lVar6 == 0) {
    _printk(&DAT_00101a0a,"pmic_glink_probe");
    uVar7 = 0xfffffff4;
    goto LAB_00100cb4;
  }
  __init_rwsem(lVar4 + 0x70,"&pgdev->rpdev_sem",&pmic_glink_probe___key);
  puVar8 = (undefined *)(lVar4 + 0x130);
  *(undefined8 *)(lVar4 + 0xb8) = 0xfffffffe0;
  *(long *)(lVar4 + 0xc0) = lVar4 + 0xc0;
  *(long *)(lVar4 + 200) = lVar4 + 0xc0;
  *(code **)(lVar4 + 0xd0) = pmic_glink_rx_work;
  *(undefined8 *)(lVar4 + 0xe8) = 0xfffffffe0;
  *(long *)(lVar4 + 0xf0) = lVar4 + 0xf0;
  *(long *)(lVar4 + 0xf8) = lVar4 + 0xf0;
  *(code **)(lVar4 + 0x100) = pmic_glink_init_work;
  *(long *)(lVar4 + 0x158) = lVar4 + 0x158;
  *(long *)(lVar4 + 0x160) = lVar4 + 0x158;
  *(long *)(lVar4 + 0x120) = lVar4 + 0x120;
  *(long *)(lVar4 + 0x128) = lVar4 + 0x120;
  *(undefined **)(lVar4 + 0x130) = puVar8;
  *(undefined **)(lVar4 + 0x138) = puVar8;
  *(undefined4 *)(lVar4 + 0xb0) = 0;
  __mutex_init(lVar4 + 0x40,"&pgdev->client_lock",&pmic_glink_probe___key_24);
  *(undefined8 *)(lVar4 + 0x28) = 0x1000000400000000;
  *(undefined8 *)(lVar4 + 0x30) = 0;
  *(undefined8 *)(lVar4 + 0x38) = 0;
  *(undefined4 *)(lVar4 + 0x144) = 0;
  *(undefined4 *)(lVar4 + 0x1a8) = 0x7fffffff;
  lVar6 = ipc_log_context_create(10,*(undefined8 *)(lVar4 + 0x18),0);
  *(long *)(lVar4 + 0x20) = lVar6;
  if (lVar6 == 0) {
    _printk(&DAT_0010172c,"pmic_glink_probe");
    lVar6 = *plVar1;
    if (lVar6 != 0) goto LAB_00100a6c;
LAB_00100a8c:
    if (*(long *)(lVar4 + 0x198) == 0) {
LAB_00100b24:
      *(long *)(param_1 + 0xa8) = lVar4;
      *(long *)(lVar4 + 8) = param_1 + 0x10;
      mutex_lock(&pmic_glink_dev_lock);
      puVar2 = pmic_glink_dev_list;
      uVar7 = __list_add_valid(puVar8,&pmic_glink_dev_list,pmic_glink_dev_list);
      if ((uVar7 & 1) != 0) {
        *(undefined **)(puVar2 + 8) = puVar8;
        *(undefined **)(lVar4 + 0x130) = puVar2;
        *(undefined ***)(lVar4 + 0x138) = &pmic_glink_dev_list;
        pmic_glink_dev_list = puVar8;
      }
      mutex_unlock(&pmic_glink_dev_lock);
      lVar6 = (*(long **)(lVar4 + 8))[0xe];
      if (lVar6 == 0) {
        lVar6 = **(long **)(lVar4 + 8);
      }
      uVar7 = debugfs_create_dir(lVar6,0);
      if (uVar7 < 0xfffffffffffff001) {
        *(ulong *)(lVar4 + 0x10) = uVar7;
        debugfs_create_u32("filter",0x180,uVar7,lVar4 + 0x14c);
        debugfs_create_bool("enable",0x180,uVar7,lVar4 + 0x150);
      }
      else {
        _printk(&DAT_00101b8f,"pmic_glink_add_debugfs",uVar7);
      }
      uVar9 = *(undefined8 *)(lVar4 + 8);
      device_set_wakeup_capable(uVar9,1);
      device_wakeup_enable(uVar9);
      ipc_log_string(*(undefined8 *)(lVar4 + 0x20),"%s probed successfully\n",
                     *(undefined8 *)(lVar4 + 0x18));
      uVar7 = 0;
      goto LAB_00100cb4;
    }
    uVar7 = pdr_handle_alloc(pmic_glink_pdr_notifier_cb,lVar4);
    *(ulong *)(lVar4 + 400) = uVar7;
    if (uVar7 < 0xfffffffffffff001) {
      uVar7 = pdr_add_lookup(uVar7,*(undefined8 *)(lVar4 + 0x198),*(undefined8 *)(lVar4 + 0x1a0));
      if ((uVar7 < 0xfffffffffffff001) || (uVar7 == 0xffffffffffffff8e)) {
        ipc_log_string(*(undefined8 *)(lVar4 + 0x20),
                       "Registering PDR for path_name: %s service_name: %s\n",
                       *(undefined8 *)(lVar4 + 0x1a0),*(undefined8 *)(lVar4 + 0x198));
        goto LAB_00100b24;
      }
      _printk(&DAT_00101abd,"pmic_glink_probe",uVar7 & 0xffffffff);
      pdr_handle_release(*(undefined8 *)(lVar4 + 400));
    }
    else if ((int)uVar7 == -0x205) {
      uVar7 = 0xfffffdfb;
    }
    else {
      _printk(&DAT_0010181d,"pmic_glink_probe",uVar7 & 0xffffffff);
    }
    qcom_unregister_ssr_notifier(*(undefined8 *)(lVar4 + 0x188),lVar4 + 0x168);
  }
  else {
    lVar6 = *plVar1;
    if (lVar6 == 0) goto LAB_00100a8c;
LAB_00100a6c:
    *(code **)(lVar4 + 0x168) = pmic_glink_ssr_notifier_cb;
    uVar7 = qcom_register_ssr_notifier(lVar6,lVar4 + 0x168);
    *(ulong *)(lVar4 + 0x188) = uVar7;
    if (uVar7 < 0xfffffffffffff001) goto LAB_00100a8c;
    _printk(&DAT_001018c3,"pmic_glink_probe",uVar7 & 0xffffffff);
  }
  ipc_log_context_destroy(*(undefined8 *)(lVar4 + 0x20));
  idr_destroy((undefined8 *)(lVar4 + 0x28));
  destroy_workqueue(*(undefined8 *)(lVar4 + 0x118));
LAB_00100cb4:
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// pmic_glink_remove @ 00100d54 size=280
// signature: undefined pmic_glink_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_glink_remove(long param_1)

{
  long *plVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  ppuVar5 = *(undefined ***)(param_1 + 0xa8);
  ipc_log_context_destroy(ppuVar5[4]);
  pdr_handle_release(ppuVar5[0x32]);
  qcom_unregister_ssr_notifier(ppuVar5[0x31],ppuVar5 + 0x2d);
  puVar4 = ppuVar5[1];
  device_wakeup_disable(puVar4);
  device_set_wakeup_capable(puVar4,0);
  debugfs_remove(ppuVar5[2]);
  __flush_workqueue(ppuVar5[0x23]);
  destroy_workqueue(ppuVar5[0x23]);
  idr_destroy(ppuVar5 + 5);
  of_platform_depopulate(param_1 + 0x10);
  *(undefined1 *)(ppuVar5 + 0x29) = 0;
  mutex_lock(&pmic_glink_dev_lock);
  if ((undefined **)pmic_glink_dev_list != &pmic_glink_dev_list) {
    ppuVar3 = (undefined **)pmic_glink_dev_list;
    do {
      ppuVar6 = (undefined **)*ppuVar3;
      if (ppuVar3 + -0x26 == ppuVar5) {
        uVar2 = __list_del_entry_valid(ppuVar5 + 0x26);
        if ((uVar2 & 1) != 0) {
          puVar4 = ppuVar5[0x26];
          plVar1 = (long *)ppuVar5[0x27];
          *(long **)(puVar4 + 8) = plVar1;
          *plVar1 = (long)puVar4;
        }
        ppuVar5[0x26] = (undefined *)0xdead000000000100;
        ppuVar5[0x27] = (undefined *)0xdead000000000122;
      }
      ppuVar3 = ppuVar6;
    } while (ppuVar6 != &pmic_glink_dev_list);
  }
  mutex_unlock(&pmic_glink_dev_lock);
  return 0;
}



//------------------------------------------------------------
// pmic_glink_rx_work @ 00100e70 size=432
// signature: undefined pmic_glink_rx_work(void)
// callers: []
//------------------------------------------------------------

void pmic_glink_rx_work(long param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  long lVar3;
  ulong uVar4;
  long lVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  
  lVar5 = param_1 + -8;
  uVar2 = _raw_spin_lock_irqsave(lVar5);
  plVar8 = (long *)(param_1 + 0x68);
  if ((long *)*plVar8 != plVar8) {
    plVar6 = (long *)*plVar8;
    do {
      plVar7 = (long *)*plVar6;
      _raw_spin_unlock_irqrestore(lVar5,uVar2);
      mutex_lock(param_1 + -0x78);
      plVar9 = plVar6 + 3;
      lVar3 = idr_find(param_1 + -0x90,(int)*plVar9);
      mutex_unlock(param_1 + -0x78);
      if ((lVar3 == 0) || (*(long *)(lVar3 + 0x50) == 0)) {
        _printk(&DAT_00101d37,"pmic_glink_rx_callback",(int)*plVar9);
      }
      else {
        if (*(char *)(param_1 + 0x98) != '\0') {
          if (*(int *)(param_1 + 0x94) == (int)*plVar9) {
            _printk(&DAT_00101947,"pmic_glink_rx_callback",plVar6[2],plVar9);
          }
          else if (*(int *)(param_1 + 0x94) == 0xffff) {
            _printk(&DAT_00101851,"pmic_glink_rx_callback",(int)*plVar9,plVar6[2],plVar9);
          }
        }
        if (*(int *)(*(code **)(lVar3 + 0x50) + -4) != 0x7ef77460) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100f6c);
          (*pcVar1)();
        }
        (**(code **)(lVar3 + 0x50))(*(undefined8 *)(lVar3 + 0x48),plVar9,plVar6[2]);
      }
      uVar2 = _raw_spin_lock_irqsave(lVar5);
      uVar4 = __list_del_entry_valid(plVar6);
      if ((uVar4 & 1) != 0) {
        lVar3 = *plVar6;
        plVar9 = (long *)plVar6[1];
        *(long **)(lVar3 + 8) = plVar9;
        *plVar9 = lVar3;
      }
      *plVar6 = -0x2152ffffffffff00;
      plVar6[1] = -0x2152fffffffffede;
      kfree(plVar6);
      plVar6 = plVar7;
    } while (plVar7 != plVar8);
  }
  _raw_spin_unlock_irqrestore(lVar5,uVar2);
  return;
}



//------------------------------------------------------------
// pmic_glink_init_work @ 00101024 size=292
// signature: undefined pmic_glink_init_work(void)
// callers: []
//------------------------------------------------------------

void pmic_glink_init_work(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  
  lVar3 = *(long *)(param_1 + -0xe0);
  if ((*(int *)(param_1 + 0xc0) == 0xfffffff) || (*(int *)(param_1 + 0x5c) == 2)) {
    pm_stay_awake(lVar3);
    mutex_lock(param_1 + -0xa8);
    for (plVar4 = *(long **)(param_1 + 0x70); plVar4 != (long *)(param_1 + 0x70);
        plVar4 = (long *)*plVar4) {
      if (*(int *)((code *)plVar4[2] + -4) != 0x14b5f38e) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1010a8);
        (*pcVar1)();
      }
      (*(code *)plVar4[2])(plVar4[-2],1);
    }
    mutex_unlock(param_1 + -0xa8);
    pm_relax(*(undefined8 *)(param_1 + -0xe0));
    ipc_log_string(*(undefined8 *)(param_1 + -200),"state_cb done %d\n",1);
    *(undefined4 *)(param_1 + 0xc0) = 0x1fffffff;
    *(undefined4 *)(param_1 + 0x5c) = 1;
  }
  if (*(char *)(param_1 + 0x60) == '\0') {
    iVar2 = of_platform_populate(*(undefined8 *)(lVar3 + 0x2e8),0,0,lVar3);
    if (iVar2 < 0) {
      _printk(&DAT_00101759,"pmic_glink_init_work",iVar2);
    }
    else {
      *(undefined1 *)(param_1 + 0x60) = 1;
    }
  }
  return;
}



//------------------------------------------------------------
// pmic_glink_ssr_notifier_cb @ 0010114c size=224
// signature: undefined pmic_glink_ssr_notifier_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_glink_ssr_notifier_cb(long param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  
  ipc_log_string(*(undefined8 *)(param_1 + -0x148),"code: %lu\n",param_2);
  if (param_2 == 2) {
    *(undefined4 *)(param_1 + -0x24) = 2;
    pm_stay_awake(*(undefined8 *)(param_1 + -0x160));
    mutex_lock(param_1 + -0x128);
    for (plVar2 = *(long **)(param_1 + -0x10); plVar2 != (long *)(param_1 + -0x10);
        plVar2 = (long *)*plVar2) {
      if (*(int *)((code *)plVar2[2] + -4) != 0x14b5f38e) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1011dc);
        (*pcVar1)();
      }
      (*(code *)plVar2[2])(plVar2[-2],0);
    }
    mutex_unlock(param_1 + -0x128);
    pm_relax(*(undefined8 *)(param_1 + -0x160));
    ipc_log_string(*(undefined8 *)(param_1 + -0x148),"state_cb done %d\n",0);
  }
  return 0;
}



//------------------------------------------------------------
// pmic_glink_pdr_notifier_cb @ 00101230 size=268
// signature: undefined pmic_glink_pdr_notifier_cb(void)
// callers: []
//------------------------------------------------------------

void pmic_glink_pdr_notifier_cb(int param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  long *plVar2;
  
  ipc_log_string(*(undefined8 *)(param_3 + 0x20),"PDR state: %x\n",param_1);
  if (param_1 == 0x1fffffff) {
    ipc_log_string(*(undefined8 *)(param_3 + 0x20),"PD state up for %s\n",
                   *(undefined8 *)(param_3 + 0x198));
  }
  else if (param_1 == 0xfffffff) {
    ipc_log_string(*(undefined8 *)(param_3 + 0x20),"PD state down for %s\n",
                   *(undefined8 *)(param_3 + 0x198));
    pm_stay_awake(*(undefined8 *)(param_3 + 8));
    mutex_lock(param_3 + 0x40);
    for (plVar2 = *(long **)(param_3 + 0x158); plVar2 != (long *)(param_3 + 0x158);
        plVar2 = (long *)*plVar2) {
      if (*(int *)((code *)plVar2[2] + -4) != 0x14b5f38e) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1012d4);
        (*pcVar1)();
      }
      (*(code *)plVar2[2])(plVar2[-2],0);
    }
    mutex_unlock(param_3 + 0x40);
    pm_relax(*(undefined8 *)(param_3 + 8));
    ipc_log_string(*(undefined8 *)(param_3 + 0x20),"state_cb done %d\n",0);
    *(undefined4 *)(param_3 + 0x1a8) = 0xfffffff;
  }
  return;
}



//------------------------------------------------------------
// pmic_glink_rpmsg_probe @ 00101340 size=260
// signature: undefined pmic_glink_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pmic_glink_rpmsg_probe(undefined *param_1)

{
  char *__s1;
  int iVar1;
  undefined8 uVar2;
  undefined **ppuVar3;
  undefined **ppuVar4;
  
  mutex_lock(&pmic_glink_dev_lock);
  __s1 = param_1 + 0x390;
  ppuVar3 = &pmic_glink_dev_list;
  do {
    ppuVar3 = (undefined **)*ppuVar3;
    if (ppuVar3 == &pmic_glink_dev_list) {
      mutex_unlock(&pmic_glink_dev_lock);
      goto LAB_00101424;
    }
    iVar1 = strcmp(__s1,ppuVar3[-0x23]);
  } while (iVar1 != 0);
  ppuVar4 = ppuVar3 + -0x26;
  mutex_unlock(&pmic_glink_dev_lock);
  if (ppuVar4 == (undefined **)0x0) {
LAB_00101424:
    _printk(&DAT_001016f5,"pmic_glink_rpmsg_probe",__s1);
    uVar2 = 0xfffffdfb;
  }
  else {
    down_write(ppuVar3 + -0x18);
    *(undefined ***)(param_1 + 0x98) = ppuVar4;
    *ppuVar4 = param_1;
    *(undefined4 *)(ppuVar3 + 2) = 1;
    up_write(ppuVar3 + -0x18);
    queue_work_on(0x20,_system_wq,ppuVar3 + -9);
    ipc_log_string(ppuVar3[-0x22],"%s probed\n",__s1);
    uVar2 = 0;
  }
  return uVar2;
}



//------------------------------------------------------------
// pmic_glink_rpmsg_remove @ 00101448 size=216
// signature: undefined pmic_glink_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void pmic_glink_rpmsg_remove(long param_1)

{
  char *__s1;
  int iVar1;
  undefined **ppuVar2;
  
  mutex_lock(&pmic_glink_dev_lock);
  __s1 = (char *)(param_1 + 0x390);
  ppuVar2 = &pmic_glink_dev_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &pmic_glink_dev_list) {
      mutex_unlock(&pmic_glink_dev_lock);
      goto LAB_00101504;
    }
    iVar1 = strcmp(__s1,ppuVar2[-0x23]);
  } while (iVar1 != 0);
  mutex_unlock(&pmic_glink_dev_lock);
  if (ppuVar2 + -0x26 == (undefined **)0x0) {
LAB_00101504:
    _printk(&DAT_001016f5,"pmic_glink_rpmsg_remove",__s1);
  }
  else {
    down_write(ppuVar2 + -0x18);
    *(undefined4 *)(ppuVar2 + 2) = 0;
    ppuVar2[-0x26] = (undefined *)0x0;
    up_write(ppuVar2 + -0x18);
    ipc_log_string(ppuVar2[-0x22],"%s removed\n",__s1);
  }
  return;
}



//------------------------------------------------------------
// pmic_glink_rpmsg_callback @ 00101524 size=236
// signature: undefined pmic_glink_rpmsg_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 pmic_glink_rpmsg_callback(long param_1,void *param_2,undefined8 param_3)

{
  long *plVar1;
  undefined8 uVar2;
  ulong uVar3;
  size_t __n;
  undefined8 *puVar4;
  long lVar5;
  
  if ((uint)param_3 < 0xc) {
    _printk(&DAT_00101d63,"pmic_glink_rpmsg_callback",param_3,0xc);
    uVar2 = 0xffffffea;
  }
  else {
    __n = (size_t)(int)(uint)param_3;
    lVar5 = *(long *)(param_1 + 0x98);
    plVar1 = (long *)__kmalloc(__n + 0x18,0xb20);
    if (plVar1 == (long *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      plVar1[2] = __n;
      memcpy(plVar1 + 3,param_2,__n);
      uVar2 = _raw_spin_lock_irqsave(lVar5 + 0xb0);
      puVar4 = *(undefined8 **)(lVar5 + 0x128);
      uVar3 = __list_add_valid(plVar1,puVar4,lVar5 + 0x120);
      if ((uVar3 & 1) != 0) {
        *(long **)(lVar5 + 0x128) = plVar1;
        *plVar1 = lVar5 + 0x120;
        plVar1[1] = (long)puVar4;
        *puVar4 = plVar1;
      }
      _raw_spin_unlock_irqrestore(lVar5 + 0xb0,uVar2);
      queue_work_on(0x20,*(undefined8 *)(lVar5 + 0x118),lVar5 + 0xb8);
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// init_module @ 00101660 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&pmic_glink_driver,&__this_module);
  if (-1 < iVar1) {
    __register_rpmsg_driver(&pmic_glink_rpmsg_driver,&__this_module);
  }
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001016a8 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  unregister_rpmsg_driver(&pmic_glink_rpmsg_driver);
  platform_driver_unregister(&pmic_glink_driver);
  return;
}



//------------------------------------------------------------
// down_read @ 00104000 size=1
// signature: undefined down_read(void)
// callers: [pmic_glink_register_client, pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104008 size=1
// signature: undefined mutex_lock(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_ssr_notifier_cb, pmic_glink_unregister_client, pmic_glink_remove, pmic_glink_register_client, pmic_glink_rpmsg_remove, pmic_glink_init_work, pmic_glink_pdr_notifier_cb, pmic_glink_probe, pmic_glink_rx_work, pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 00104010 size=1
// signature: undefined rpmsg_send(void)
// callers: [pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104018 size=1
// signature: undefined mutex_unlock(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_ssr_notifier_cb, pmic_glink_unregister_client, pmic_glink_remove, pmic_glink_register_client, pmic_glink_rpmsg_remove, pmic_glink_init_work, pmic_glink_pdr_notifier_cb, pmic_glink_probe, pmic_glink_rx_work, pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_read @ 00104020 size=1
// signature: undefined up_read(void)
// callers: [pmic_glink_register_client, pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104028 size=1
// signature: undefined _printk(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_register_client, pmic_glink_rpmsg_remove, pmic_glink_init_work, pmic_glink_probe, pmic_glink_rpmsg_callback, pmic_glink_rx_work, pmic_glink_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104038 size=1
// signature: undefined kmalloc_trace(void)
// callers: [pmic_glink_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00104040 size=1
// signature: undefined kstrdup(void)
// callers: [pmic_glink_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104048 size=1
// signature: undefined __mutex_init(void)
// callers: [pmic_glink_register_client, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00104050 size=1
// signature: undefined idr_alloc(void)
// callers: [pmic_glink_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00104058 size=1
// signature: undefined __list_add_valid(void)
// callers: [pmic_glink_register_client, pmic_glink_probe, pmic_glink_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00104060 size=1
// signature: undefined ipc_log_string(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_ssr_notifier_cb, pmic_glink_unregister_client, pmic_glink_register_client, pmic_glink_rpmsg_remove, pmic_glink_init_work, pmic_glink_pdr_notifier_cb, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104068 size=1
// signature: undefined kfree(void)
// callers: [pmic_glink_unregister_client, pmic_glink_register_client, pmic_glink_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00104070 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [pmic_glink_unregister_client, pmic_glink_remove, pmic_glink_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00104078 size=1
// signature: undefined idr_remove(void)
// callers: [pmic_glink_unregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104080 size=1
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
// __register_rpmsg_driver @ 00104088 size=1
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
// unregister_rpmsg_driver @ 00104090 size=1
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
// platform_driver_unregister @ 00104098 size=1
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
// devm_kmalloc @ 001040a0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 001040a8 size=1
// signature: undefined of_property_read_string(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 001040b0 size=1
// signature: size_t strlen(char * __s)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001040b8 size=1
// signature: undefined of_find_property(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 001040c0 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 001040c8 size=1
// signature: undefined alloc_workqueue(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_rwsem @ 001040d0 size=1
// signature: undefined __init_rwsem(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_rwsem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001040d8 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_register_ssr_notifier @ 001040e0 size=1
// signature: undefined qcom_register_ssr_notifier(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_register_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_alloc @ 001040e8 size=1
// signature: undefined pdr_handle_alloc(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_unregister_ssr_notifier @ 001040f0 size=1
// signature: undefined qcom_unregister_ssr_notifier(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_unregister_ssr_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001040f8 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 00104100 size=1
// signature: undefined idr_destroy(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00104108 size=1
// signature: undefined destroy_workqueue(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_add_lookup @ 00104110 size=1
// signature: undefined pdr_add_lookup(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_add_lookup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00104118 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00104120 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_bool @ 00104128 size=1
// signature: undefined debugfs_create_bool(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_bool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00104130 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00104138 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pdr_handle_release @ 00104140 size=1
// signature: undefined pdr_handle_release(void)
// callers: [pmic_glink_remove, pmic_glink_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pdr_handle_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_disable @ 00104148 size=1
// signature: undefined device_wakeup_disable(void)
// callers: [pmic_glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00104150 size=1
// signature: undefined debugfs_remove(void)
// callers: [pmic_glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __flush_workqueue @ 00104158 size=1
// signature: undefined __flush_workqueue(void)
// callers: [pmic_glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __flush_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_depopulate @ 00104160 size=1
// signature: undefined of_platform_depopulate(void)
// callers: [pmic_glink_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_depopulate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104168 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [pmic_glink_rpmsg_callback, pmic_glink_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104170 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [pmic_glink_rpmsg_callback, pmic_glink_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00104178 size=1
// signature: undefined idr_find(void)
// callers: [pmic_glink_rx_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_stay_awake @ 00104180 size=1
// signature: undefined pm_stay_awake(void)
// callers: [pmic_glink_ssr_notifier_cb, pmic_glink_init_work, pmic_glink_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_stay_awake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_relax @ 00104188 size=1
// signature: undefined pm_relax(void)
// callers: [pmic_glink_ssr_notifier_cb, pmic_glink_init_work, pmic_glink_pdr_notifier_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 00104190 size=1
// signature: undefined of_platform_populate(void)
// callers: [pmic_glink_init_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104198 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 001041a0 size=1
// signature: undefined down_write(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 001041a8 size=1
// signature: undefined up_write(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_rpmsg_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001041b8 size=1
// signature: undefined queue_work_on(void)
// callers: [pmic_glink_rpmsg_probe, pmic_glink_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001041c0 size=1
// signature: undefined __kmalloc(void)
// callers: [pmic_glink_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001041c8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [pmic_glink_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



