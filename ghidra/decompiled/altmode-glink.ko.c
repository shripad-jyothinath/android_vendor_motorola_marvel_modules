// Decompiled by Ghidra 12.2
// Program: altmode-glink.ko
// Image base: 00100000

//------------------------------------------------------------
// altmode_register_notifier @ 001003ac size=396
// signature: undefined altmode_register_notifier(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int altmode_register_notifier(long param_1,code *param_2,long param_3)

{
  undefined *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  iVar4 = -0x16;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (((param_1 != 0) && (param_2 != (code *)0x0)) && (param_3 != 0)) {
    iVar4 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,altmode-dev","#altmode-cells",
                       0xffffffff,0,&local_98);
    uVar2 = local_98;
    if (iVar4 == 0) {
      mutex_lock(&notify_lock);
      lVar5 = of_find_device_by_node(uVar2);
      if ((lVar5 == 0) || (*(long *)(lVar5 + 0xa8) == 0)) {
        puVar6 = (undefined8 *)kmalloc_trace(___list_del_entry_valid,0xdc0,0x28);
        if (puVar6 == (undefined8 *)0x0) {
          mutex_unlock(&notify_lock);
          iVar4 = -0xc;
          goto LAB_00100500;
        }
        puVar6[3] = param_2;
        puVar6[4] = param_3;
        puVar6[2] = uVar2;
        puVar1 = probe_notify_list;
        uVar7 = __list_add_valid(puVar6,&probe_notify_list,probe_notify_list);
        if ((uVar7 & 1) != 0) {
          *(undefined8 **)(puVar1 + 8) = puVar6;
          *puVar6 = puVar1;
          puVar6[1] = &probe_notify_list;
          probe_notify_list = (undefined *)puVar6;
        }
      }
      else {
        if (*(int *)(param_2 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8233,0x10046c);
          (*pcVar3)();
        }
        (*param_2)(param_3);
      }
      mutex_unlock(&notify_lock);
      iVar4 = 0;
    }
    else {
      _dev_err(param_1,"Error parsing qcom,altmode-dev property: %d\n",iVar4);
    }
  }
LAB_00100500:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// altmode_deregister_notifier @ 0010053c size=344
// signature: undefined altmode_deregister_notifier(void)
// callers: []
//------------------------------------------------------------

int altmode_deregister_notifier(long param_1,undefined *param_2)

{
  undefined *puVar1;
  long *plVar2;
  long lVar3;
  int iVar4;
  ulong uVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  undefined *local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = (undefined *)0x0;
  uStack_80 = 0;
  if (param_1 == 0) {
    iVar4 = -0x16;
  }
  else {
    iVar4 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,altmode-dev","#altmode-cells",
                       0xffffffff,0,&local_88);
    puVar1 = local_88;
    if (iVar4 == 0) {
      mutex_lock(&notify_lock);
      ppuVar7 = (undefined **)probe_notify_list;
      if ((undefined **)probe_notify_list != &probe_notify_list) {
        do {
          ppuVar6 = (undefined **)*ppuVar7;
          if ((ppuVar7[2] == puVar1) && (ppuVar7[4] == param_2)) {
            uVar5 = __list_del_entry_valid(ppuVar7);
            if ((uVar5 & 1) != 0) {
              puVar1 = *ppuVar7;
              plVar2 = (long *)ppuVar7[1];
              *(long **)(puVar1 + 8) = plVar2;
              *plVar2 = (long)puVar1;
            }
            *ppuVar7 = (undefined *)0xdead000000000100;
            ppuVar7[1] = (undefined *)0xdead000000000122;
            kfree(ppuVar7);
            break;
          }
          ppuVar7 = ppuVar6;
        } while (ppuVar6 != &probe_notify_list);
      }
      mutex_unlock(&notify_lock);
      iVar4 = 0;
    }
    else {
      _dev_err(param_1,"Error parsing qcom,altmode-dev property: %d\n",iVar4);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// altmode_send_data @ 00100698 size=32
// signature: undefined altmode_send_data(void)
// callers: []
//------------------------------------------------------------

void altmode_send_data(undefined8 *param_1)

{
  __altmode_send_data(*param_1);
  return;
}



//------------------------------------------------------------
// __altmode_send_data @ 001006b8 size=248
// signature: undefined __altmode_send_data(void)
// callers: [altmode_send_data]
//------------------------------------------------------------

int __altmode_send_data(long param_1,void *param_2,ulong param_3)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined4 local_38;
  undefined8 local_34;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  local_34 = 0;
  if (param_3 < 9) {
    local_40 = 0x10000800c;
    local_38 = 0x15;
    memcpy(&local_34,param_2,param_3);
    *(undefined4 *)(param_1 + 0x198) = 0;
    iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + 8),&local_40,0x18);
    if (iVar2 == 0) {
      iVar2 = wait_for_completion_timeout(param_1 + 0x198,0xfa);
      if (iVar2 != 0) {
        iVar2 = 0;
        goto LAB_00100738;
      }
      iVar2 = -0x6e;
    }
    _printk(&DAT_00101700,"altmode_write",iVar2);
  }
  else {
    _printk(&DAT_0010151d,"__altmode_send_data",param_3,8);
    iVar2 = -0x16;
  }
LAB_00100738:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// altmode_register_client @ 001007b4 size=664
// signature: undefined altmode_register_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * altmode_register_client(long param_1,short *param_2)

{
  long *plVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar5 = sp_el0;
  plVar9 = (long *)0xffffffffffffffea;
  local_48 = *(long *)(lVar5 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  local_90 = 0;
  if (((((param_1 != 0) && (param_2 != (short *)0x0)) && (*(long *)(param_2 + 4) != 0)) &&
      ((*(long *)(param_2 + 8) != 0 && (*(long *)(param_2 + 0xc) != 0)))) && (*param_2 != 0)) {
    iVar4 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2e8),"qcom,altmode-dev","#altmode-cells",
                       0xffffffff,0,&local_98);
    if (iVar4 == 0) {
      if ((int)local_90 == 1) {
        if (local_90._4_4_ < 4) {
          lVar5 = of_find_device_by_node(local_98);
          if ((lVar5 == 0) || (lVar5 = *(long *)(lVar5 + 0xa8), lVar5 == 0)) {
            plVar9 = (long *)0xfffffffffffffdfb;
          }
          else {
            plVar9 = (long *)kmalloc_trace(_kfree,0xdc0,0x80);
            if (plVar9 == (long *)0x0) {
              plVar9 = (long *)0xfffffffffffffff4;
            }
            else {
              *plVar9 = lVar5;
              sVar2 = *param_2;
              *(char *)(plVar9 + 7) = (char)((ulong)local_90 >> 0x20);
              lVar7 = *(long *)(param_2 + 8);
              lVar11 = *(long *)(param_2 + 0xc);
              *(short *)(plVar9 + 1) = sVar2;
              plVar9[8] = 0xfffffffe0;
              plVar9[3] = lVar7;
              plVar9[4] = lVar11;
              plVar9[9] = (long)(plVar9 + 9);
              plVar9[10] = (long)(plVar9 + 9);
              uVar6 = *(undefined8 *)(param_2 + 4);
              plVar9[0xb] = (long)client_cb_work;
              lVar7 = kstrdup(uVar6,0xcc0);
              plVar9[2] = lVar7;
              if (lVar7 == 0) {
                kfree(plVar9);
                plVar9 = (long *)0xfffffffffffffff4;
              }
              else {
                lVar7 = lVar5 + 0x28;
                mutex_lock(lVar7);
                uVar3 = (uint)CONCAT21((short)plVar9[1],(char)plVar9[7]);
                iVar4 = idr_alloc(lVar5 + 0x10,plVar9,uVar3,uVar3 + 1,0xcc0);
                if (iVar4 < 0) {
                  _printk(&DAT_001015dc,"altmode_register_client",*(undefined8 *)(param_2 + 4),iVar4
                         );
                  mutex_unlock(lVar7);
                  kfree(plVar9[2]);
                  kfree(plVar9);
                  plVar9 = (long *)(long)iVar4;
                }
                else {
                  plVar1 = plVar9 + 5;
                  plVar10 = (long *)(lVar5 + 0x68);
                  lVar11 = *plVar10;
                  uVar8 = __list_add_valid(plVar1,plVar10,lVar11);
                  if ((uVar8 & 1) != 0) {
                    *(long **)(lVar11 + 8) = plVar1;
                    plVar9[5] = lVar11;
                    plVar9[6] = (long)plVar10;
                    *plVar10 = (long)plVar1;
                  }
                  mutex_unlock(lVar7);
                  if (*(int *)(lVar5 + 0x78) == 0) {
                    queue_delayed_work_on(0x20,_system_wq,lVar5 + 0x80,5);
                  }
                }
              }
            }
          }
        }
        else {
          _dev_err(param_1,"Invalid port_index: %d, max is %d\n",local_90._4_4_,3);
        }
      }
      else {
        _dev_err(param_1,"Error in port_index specification\n");
      }
    }
    else {
      _dev_err(param_1,"Error parsing qcom,altmode-dev property: %d\n",iVar4);
      plVar9 = (long *)(long)iVar4;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar9;
}



//------------------------------------------------------------
// client_cb_work @ 00100a50 size=64
// signature: undefined client_cb_work(void)
// callers: []
//------------------------------------------------------------

void client_cb_work(long param_1)

{
  code *pcVar1;
  
  if (*(int *)(*(code **)(param_1 + -0x20) + -4) != 0x7ef77460) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100a80);
    (*pcVar1)();
  }
  (**(code **)(param_1 + -0x20))(*(undefined8 *)(param_1 + -0x28),param_1 + 0x30,0x10);
  return;
}



//------------------------------------------------------------
// altmode_deregister_client @ 00100a94 size=228
// signature: undefined altmode_deregister_client(void)
// callers: []
//------------------------------------------------------------

undefined8 altmode_deregister_client(long *param_1)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  ulong uVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  
  if ((param_1 == (long *)0x0) || (lVar6 = *param_1, lVar6 == 0)) {
    uVar5 = 0xffffffed;
  }
  else {
    cancel_work_sync(param_1 + 8);
    mutex_lock(lVar6 + 0x28);
    idr_remove(lVar6 + 0x10,(ulong)CONCAT21((short)param_1[1],(char)param_1[7]));
    plVar7 = *(long **)(lVar6 + 0x68);
    while (plVar3 = plVar7, plVar3 != (long *)(lVar6 + 0x68)) {
      plVar7 = (long *)*plVar3;
      if (plVar3 + -5 == param_1) {
        uVar4 = __list_del_entry_valid(plVar3);
        if ((uVar4 & 1) != 0) {
          lVar1 = *plVar3;
          plVar2 = (long *)plVar3[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        *plVar3 = -0x2152ffffffffff00;
        plVar3[1] = -0x2152fffffffffede;
      }
    }
    mutex_unlock(lVar6 + 0x28);
    kfree(param_1[2]);
    kfree(param_1);
    uVar5 = 0;
  }
  return uVar5;
}



//------------------------------------------------------------
// altmode_probe @ 00100b7c size=708
// signature: undefined altmode_probe(void)
// callers: []
//------------------------------------------------------------

ulong altmode_probe(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  long lVar3;
  code *pcVar4;
  long *plVar5;
  ulong uVar6;
  long lVar7;
  undefined **ppuVar8;
  undefined **ppuVar9;
  char *local_70;
  undefined8 local_68;
  long *local_60;
  code *local_58;
  code *pcStack_50;
  long local_48;
  
  lVar3 = sp_el0;
  lVar7 = param_1 + 0x10;
  local_48 = *(long *)(lVar3 + 0x638);
  local_68 = 0;
  plVar5 = (long *)devm_kmalloc(lVar7,0x1c0,0xdc0);
  if (plVar5 == (long *)0x0) {
    uVar6 = 0xfffffff4;
  }
  else {
    *plVar5 = lVar7;
    __mutex_init(plVar5 + 5,"&amdev->client_lock",&altmode_probe___key);
    plVar5[3] = 0;
    plVar5[4] = 0;
    plVar5[2] = 0x1000000400000000;
    *(undefined4 *)(plVar5 + 0x33) = 0;
    __init_swait_queue_head(plVar5 + 0x34,"&x->wait",&init_completion___key);
    plVar5[0x10] = 0xfffffffe0;
    plVar5[0x11] = (long)(plVar5 + 0x11);
    plVar5[0x12] = (long)(plVar5 + 0x11);
    plVar5[0x13] = (long)altmode_send_pan_en;
    init_timer_key(plVar5 + 0x16,&delayed_work_timer_fn,0x200000,0,0);
    plVar5[0x21] = 0xfffffffe0;
    plVar5[0x22] = (long)(plVar5 + 0x22);
    plVar5[0x23] = (long)(plVar5 + 0x22);
    plVar5[0x24] = (long)altmode_send_pan_ack;
    init_timer_key(plVar5 + 0x27,&delayed_work_timer_fn,0x200000,0,0);
    plVar5[0xb] = (long)(plVar5 + 0xb);
    plVar5[0xc] = (long)(plVar5 + 0xb);
    plVar5[0xd] = (long)(plVar5 + 0xd);
    plVar5[0xe] = (long)(plVar5 + 0xd);
    local_68 = CONCAT44(local_68._4_4_,0x800c);
    local_70 = "altmode";
    local_58 = altmode_callback;
    pcStack_50 = altmode_state_cb;
    local_60 = plVar5;
    uVar6 = pmic_glink_register_client(*plVar5,&local_70);
    plVar5[1] = uVar6;
    if (uVar6 < 0xfffffffffffff001) {
      *(long **)(param_1 + 0xa8) = plVar5;
      altmode_ipc_log = ipc_log_context_create(10,"altmode",0);
      if (altmode_ipc_log == 0) {
        _dev_warn(lVar7,"Error in creating ipc_log_context\n");
      }
      mutex_lock(&notify_lock);
      ppuVar8 = (undefined **)probe_notify_list;
      if ((undefined **)probe_notify_list != &probe_notify_list) {
        do {
          ppuVar9 = (undefined **)*ppuVar8;
          lVar7 = of_find_device_by_node(ppuVar8[2]);
          if ((lVar7 != 0) &&
             (*(long **)(lVar7 + 0xa8) != (long *)0x0 && *(long **)(lVar7 + 0xa8) == plVar5)) {
            if (*(int *)(ppuVar8[3] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100dac);
              (*pcVar4)();
            }
            (*(code *)ppuVar8[3])(ppuVar8[4]);
            uVar6 = __list_del_entry_valid(ppuVar8);
            if ((uVar6 & 1) != 0) {
              puVar1 = *ppuVar8;
              plVar2 = (long *)ppuVar8[1];
              *(long **)(puVar1 + 8) = plVar2;
              *plVar2 = (long)puVar1;
            }
            *ppuVar8 = (undefined *)0xdead000000000100;
            ppuVar8[1] = (undefined *)0xdead000000000122;
            kfree(ppuVar8);
          }
          ppuVar8 = ppuVar9;
        } while (ppuVar9 != &probe_notify_list);
      }
      mutex_unlock(&notify_lock);
      uVar6 = 0;
    }
    else {
      if ((int)uVar6 != -0x205) {
        _dev_err(lVar7,"Error in pmic_glink registration: %d\n",uVar6 & 0xffffffff);
      }
      idr_destroy(plVar5 + 2);
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// altmode_remove @ 00100e44 size=348
// signature: undefined altmode_remove(void)
// callers: [altmode_probe]
//------------------------------------------------------------

int altmode_remove(long param_1)

{
  undefined *puVar1;
  long lVar2;
  long *plVar3;
  long *plVar4;
  undefined **ppuVar5;
  int iVar6;
  ulong uVar7;
  undefined8 *puVar8;
  undefined **ppuVar9;
  long *plVar10;
  
  puVar8 = *(undefined8 **)(param_1 + 0xa8);
  debugfs_remove(puVar8[0x32]);
  cancel_delayed_work_sync(puVar8 + 0x10);
  cancel_delayed_work_sync(puVar8 + 0x21);
  idr_destroy(puVar8 + 2);
  *(undefined4 *)(puVar8 + 0xf) = 0;
  mutex_lock(&notify_lock);
  ppuVar5 = (undefined **)probe_notify_list;
  while (ppuVar5 != &probe_notify_list) {
    ppuVar9 = (undefined **)*ppuVar5;
    uVar7 = __list_del_entry_valid(ppuVar5);
    if ((uVar7 & 1) != 0) {
      puVar1 = *ppuVar5;
      plVar3 = (long *)ppuVar5[1];
      *(long **)(puVar1 + 8) = plVar3;
      *plVar3 = (long)puVar1;
    }
    *ppuVar5 = (undefined *)0xdead000000000100;
    ppuVar5[1] = (undefined *)0xdead000000000122;
    kfree(ppuVar5);
    ppuVar5 = ppuVar9;
  }
  mutex_unlock(&notify_lock);
  mutex_lock(puVar8 + 5);
  plVar3 = (long *)puVar8[0xd];
  while (plVar3 != puVar8 + 0xd) {
    plVar10 = (long *)*plVar3;
    uVar7 = __list_del_entry_valid(plVar3);
    if ((uVar7 & 1) != 0) {
      lVar2 = *plVar3;
      plVar4 = (long *)plVar3[1];
      *(long **)(lVar2 + 8) = plVar4;
      *plVar4 = lVar2;
    }
    *plVar3 = -0x2152ffffffffff00;
    plVar3[1] = -0x2152fffffffffede;
    plVar3 = plVar10;
  }
  mutex_unlock(puVar8 + 5);
  ipc_log_context_destroy(altmode_ipc_log);
  altmode_ipc_log = 0;
  iVar6 = pmic_glink_unregister_client(puVar8[1]);
  if (iVar6 < 0) {
    _dev_err(*puVar8,"Error in pmic_glink de-registration: %d\n",iVar6);
  }
  return iVar6;
}



//------------------------------------------------------------
// altmode_send_pan_en @ 00100fa4 size=264
// signature: undefined altmode_send_pan_en(void)
// callers: []
//------------------------------------------------------------

void altmode_send_pan_en(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_40 = 0x10000800c;
  local_38 = 0x1000000015;
  uStack_30 = 0;
  *(undefined4 *)(param_1 + 0x118) = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + -0x78),&local_40,0x18);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout(param_1 + 0x118,0xfa);
    if (iVar2 == 0) {
      iVar2 = -0x6e;
      _printk(&DAT_00101700,"altmode_write",0xffffff92);
LAB_0010108c:
      _printk(&DAT_00101633,"altmode_send_pan_en",iVar2);
      goto LAB_00101024;
    }
  }
  else {
    _printk(&DAT_00101700,"altmode_write",iVar2);
    if (iVar2 < 0) goto LAB_0010108c;
  }
  *(undefined4 *)(param_1 + -8) = 1;
  ipc_log_string(altmode_ipc_log,"Sent PAN EN\n");
LAB_00101024:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// altmode_send_pan_ack @ 001010b0 size=292
// signature: undefined altmode_send_pan_ack(void)
// callers: []
//------------------------------------------------------------

void altmode_send_pan_ack(long param_1)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_50;
  undefined4 local_48;
  ulong local_44;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar3 = (ulong)*(byte *)(param_1 + 0xb0);
  local_50 = 0x10000800c;
  *(undefined4 *)(param_1 + 0x90) = 0;
  local_48 = 0x15;
  local_44 = uVar3 << 0x20 | 0x11;
  local_3c = 0;
  iVar2 = pmic_glink_write(*(undefined8 *)(param_1 + -0x100),&local_50,0x18);
  if (iVar2 == 0) {
    iVar2 = wait_for_completion_timeout((undefined4 *)(param_1 + 0x90),0xfa);
    if (iVar2 == 0) {
      iVar2 = -0x6e;
      _printk(&DAT_00101700,"altmode_write",0xffffff92);
LAB_001011b0:
      _printk(&DAT_001017ad,"altmode_send_ack",uVar3,iVar2);
      goto LAB_00101144;
    }
  }
  else {
    _printk(&DAT_00101700,"altmode_write",iVar2);
    if (iVar2 < 0) goto LAB_001011b0;
  }
  ipc_log_string(altmode_ipc_log,"port %u: Sent PAN ACK\n",uVar3);
LAB_00101144:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// altmode_callback @ 001011d8 size=340
// signature: undefined altmode_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 altmode_callback(long param_1,undefined4 *param_2,long param_3)

{
  uint uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 *puVar6;
  
  ipc_log_string(altmode_ipc_log,"len: %zu owner: %u type: %u opcode %04x\n",param_3,*param_2,
                 param_2[1],param_2[2]);
  uVar1 = param_2[2] & 0xff;
  if (uVar1 == 0x16) {
    if (param_3 != 0x20) {
      ipc_log_string(altmode_ipc_log,"Expected length %u, got: %zu\n",0x20,param_3);
      return 0xffffffea;
    }
    uVar1 = (uint)param_2[2] >> 0x10;
    puVar6 = (undefined8 *)(param_2 + 3);
    uVar3 = *(undefined1 *)puVar6;
    mutex_lock(param_1 + 0x28);
    lVar5 = idr_find(param_1 + 0x10,(ulong)CONCAT41(uVar1,uVar3));
    mutex_unlock(param_1 + 0x28);
    if (lVar5 == 0) {
      ipc_log_string(altmode_ipc_log,"No client associated with SVID %#x port %u\n",uVar1,uVar3);
      *(undefined1 *)(param_1 + 0x1b8) = uVar3;
      queue_delayed_work_on(0x20,_system_wq,param_1 + 0x108,5);
    }
    else {
      ipc_log_string(altmode_ipc_log,"Payload: %*ph\n",0x10,puVar6);
      cancel_work_sync(lVar5 + 0x40);
      uVar4 = _system_wq;
      uVar2 = *(undefined8 *)(param_2 + 5);
      *(undefined8 *)(lVar5 + 0x70) = *puVar6;
      *(undefined8 *)(lVar5 + 0x78) = uVar2;
      queue_work_on(0x20,uVar4,lVar5 + 0x40);
    }
  }
  else if (uVar1 == 0x15) {
    complete(param_1 + 0x198);
  }
  return 0;
}



//------------------------------------------------------------
// altmode_state_cb @ 00101330 size=132
// signature: undefined altmode_state_cb(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void altmode_state_cb(long param_1,int param_2)

{
  ipc_log_string(altmode_ipc_log,"state: %d\n",param_2);
  if (param_2 == 1) {
    mutex_lock(param_1 + 0x28);
    if (*(long **)(param_1 + 0x68) != (long *)(param_1 + 0x68)) {
      queue_delayed_work_on(0x20,_system_wq,param_1 + 0x80,5);
    }
    mutex_unlock(param_1 + 0x28);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101434 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&altmode_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101464 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&altmode_driver);
  return;
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00103000 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103008 size=1
// signature: undefined mutex_lock(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_callback, altmode_deregister_client, altmode_register_notifier, altmode_probe, altmode_remove, altmode_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_device_by_node @ 00103010 size=1
// signature: undefined of_find_device_by_node(void)
// callers: [altmode_register_client, altmode_register_notifier, altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_device_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103020 size=1
// signature: undefined kmalloc_trace(void)
// callers: [altmode_register_client, altmode_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103028 size=1
// signature: undefined __list_add_valid(void)
// callers: [altmode_register_client, altmode_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103030 size=1
// signature: undefined mutex_unlock(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_callback, altmode_deregister_client, altmode_register_notifier, altmode_probe, altmode_remove, altmode_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103038 size=1
// signature: undefined _dev_err(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_register_notifier, altmode_probe, altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_send_pan_ack, __altmode_send_data, altmode_register_notifier, altmode_send_pan_en, altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103048 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [altmode_deregister_notifier, altmode_deregister_client, altmode_probe, altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103050 size=1
// signature: undefined kfree(void)
// callers: [altmode_register_client, altmode_deregister_notifier, altmode_deregister_client, altmode_probe, altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103058 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [__altmode_send_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_write @ 00103060 size=1
// signature: undefined pmic_glink_write(void)
// callers: [altmode_send_pan_ack, __altmode_send_data, altmode_send_pan_en]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00103068 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [altmode_send_pan_ack, __altmode_send_data, altmode_send_pan_en]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103070 size=1
// signature: undefined _printk(void)
// callers: [altmode_register_client, altmode_send_pan_ack, __altmode_send_data, altmode_send_pan_en]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 00103078 size=1
// signature: undefined kstrdup(void)
// callers: [altmode_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00103080 size=1
// signature: undefined idr_alloc(void)
// callers: [altmode_register_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00103090 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [altmode_register_client, altmode_callback, altmode_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00103098 size=1
// signature: undefined cancel_work_sync(void)
// callers: [altmode_callback, altmode_deregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 001030a0 size=1
// signature: undefined idr_remove(void)
// callers: [altmode_deregister_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001030a8 size=1
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
// platform_driver_unregister @ 001030b0 size=1
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
// devm_kmalloc @ 001030b8 size=1
// signature: undefined devm_kmalloc(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001030c0 size=1
// signature: undefined __mutex_init(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001030c8 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 001030d8 size=1
// signature: undefined init_timer_key(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_register_client @ 001030e0 size=1
// signature: undefined pmic_glink_register_client(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_register_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_destroy @ 001030e8 size=1
// signature: undefined idr_destroy(void)
// callers: [altmode_probe, altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 001030f0 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 001030f8 size=1
// signature: undefined _dev_warn(void)
// callers: [altmode_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00103100 size=1
// signature: undefined debugfs_remove(void)
// callers: [altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00103108 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 00103110 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pmic_glink_unregister_client @ 00103118 size=1
// signature: undefined pmic_glink_unregister_client(void)
// callers: [altmode_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pmic_glink_unregister_client(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_string @ 00103120 size=1
// signature: undefined ipc_log_string(void)
// callers: [altmode_send_pan_ack, altmode_callback, altmode_send_pan_en, altmode_state_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00103128 size=1
// signature: undefined complete(void)
// callers: [altmode_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00103130 size=1
// signature: undefined idr_find(void)
// callers: [altmode_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00103138 size=1
// signature: undefined queue_work_on(void)
// callers: [altmode_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



