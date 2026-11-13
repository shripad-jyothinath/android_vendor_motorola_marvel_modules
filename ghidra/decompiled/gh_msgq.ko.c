// Decompiled by Ghidra 12.2
// Program: gh_msgq.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_msgq_alloc_entry @ 001002f4 size=292
// signature: undefined gh_msgq_alloc_entry(void)
// callers: [gh_msgq_register, gh_msgq_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gh_msgq_alloc_entry(undefined4 param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  
  lVar3 = kmalloc_trace(___init_waitqueue_head,0xb20,0x90);
  if (lVar3 != 0) {
    *(undefined8 *)(lVar3 + 0x18) = 0xffffffffffffffff;
    *(undefined8 *)(lVar3 + 0x10) = 0xffffffffffffffff;
    *(undefined2 *)(lVar3 + 0x40) = 0x100;
    *(undefined4 *)(lVar3 + 0x78) = param_1;
    __init_waitqueue_head(lVar3 + 0x48,"&cap_table_entry->tx_wq",&gh_msgq_alloc_entry___key);
    __init_waitqueue_head(lVar3 + 0x60,"&cap_table_entry->rx_wq",&gh_msgq_alloc_entry___key_1);
    *(undefined8 *)(lVar3 + 0x38) = 0;
    *(undefined4 *)(lVar3 + 8) = 0;
    lVar4 = kasprintf(0xa20,"gh_msgq_tx_%d",param_1);
    *(long *)(lVar3 + 0x28) = lVar4;
    uVar6 = 0;
    if (lVar4 != 0) {
      lVar4 = kasprintf(0xa20,"gh_msgq_rx_%d",param_1);
      *(long *)(lVar3 + 0x30) = lVar4;
      puVar2 = gh_msgq_cap_list;
      if (lVar4 != 0) {
        puVar1 = (undefined *)(lVar3 + 0x80);
        uVar5 = __list_add_valid(puVar1,&gh_msgq_cap_list,gh_msgq_cap_list);
        if ((uVar5 & 1) == 0) {
          return lVar3;
        }
        *(undefined **)(puVar2 + 8) = puVar1;
        *(undefined **)(lVar3 + 0x80) = puVar2;
        *(undefined ***)(lVar3 + 0x88) = &gh_msgq_cap_list;
        gh_msgq_cap_list = puVar1;
        return lVar3;
      }
      uVar6 = *(undefined8 *)(lVar3 + 0x28);
    }
    kfree(uVar6);
    kfree(*(undefined8 *)(lVar3 + 0x30));
    kfree(lVar3);
  }
  return -0xc;
}



//------------------------------------------------------------
// gh_msgq_recv @ 0010041c size=892
// signature: undefined gh_msgq_recv(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_msgq_recv(undefined4 *param_1,long param_2,ulong param_3,long *param_4,ulong param_5)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined *puVar6;
  long lVar7;
  undefined8 uVar8;
  ulong uVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar5 = sp_el0;
  uVar10 = 0xffffffea;
  local_68 = *(long *)(lVar5 + 0x638);
  if ((((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == 0)) ||
     (param_4 == (long *)0x0)) goto LAB_0010067c;
  if (0xf0 < param_3) {
    uVar10 = 0xfffffff9;
    goto LAB_0010067c;
  }
  puVar11 = *(undefined8 **)(param_1 + 2);
  if (puVar11 == (undefined8 *)0x0) {
LAB_0010054c:
    uVar10 = 0xfffffff5;
  }
  else {
    puVar1 = puVar11 + 1;
    _raw_spin_lock(puVar1);
    if ((undefined4 *)*puVar11 == param_1) {
      if ((puVar11[3] == -1) && (((param_5 >> 0x20 & 1) != 0 || (*(char *)(param_1 + 1) != '\0'))))
      {
        iVar4 = ___ratelimit(gh_msgq_recv__rs,"gh_msgq_recv");
        if (iVar4 != 0) {
          uVar2 = *param_1;
          puVar6 = &DAT_00101792;
LAB_00100740:
          _printk(puVar6,"gh_msgq_recv",uVar2);
        }
      }
      else {
        _raw_spin_unlock(puVar1);
        if (puVar11[3] == -1) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          while (lVar5 = prepare_to_wait_event(puVar11 + 0xc,&local_90,1), puVar11[3] == -1) {
            if (lVar5 != 0) {
              if ((int)lVar5 != 0) goto LAB_0010071c;
              goto LAB_00100520;
            }
            schedule();
          }
          finish_wait(puVar11 + 0xc,&local_90);
        }
LAB_00100520:
        _raw_spin_lock(puVar1);
        if (*(int *)((long)puVar11 + 0x24) != 0) {
          _raw_spin_unlock(puVar1);
          bVar3 = *(char *)((long)puVar11 + 0x41) == '\0';
          if (((param_5 >> 0x20 & 1) == 0) || (*(char *)((long)puVar11 + 0x41) == '\0')) {
            lVar5 = (long)puVar11 + 0x3c;
            uVar10 = 0xfffffff5;
            do {
              if (!bVar3) {
                local_78 = 0;
                uStack_70 = 0;
                local_88 = 0;
                uStack_80 = 0;
                local_90 = 0;
                init_wait_entry(&local_90,0);
                while (lVar7 = prepare_to_wait_event(puVar11 + 0xc,&local_90,1),
                      *(char *)((long)puVar11 + 0x41) != '\0') {
                  if (lVar7 != 0) {
                    if ((int)lVar7 == 0) goto LAB_001005e0;
                    goto LAB_0010071c;
                  }
                  schedule();
                }
                finish_wait(puVar11 + 0xc,&local_90);
              }
LAB_001005e0:
              uVar8 = _raw_spin_lock_irqsave(lVar5);
              uVar9 = puVar11[3];
              CallHyperVisor(0x601c);
              local_90 = 0;
              iVar4 = (int)uVar9;
              if (iVar4 != 0x3c) {
                switch(iVar4) {
                case 0:
                  *param_4 = param_2;
                  *(bool *)((long)puVar11 + 0x41) = param_3 == 0;
                  _raw_spin_unlock_irqrestore(lVar5,uVar8,param_3,0,0,0,0,0);
                  uVar10 = 0;
                  goto LAB_0010067c;
                default:
                  uVar10 = 0xffffffea;
                  break;
                case 10:
                  uVar10 = 0xfffffff4;
                  break;
                case 0x1e:
                case 0x32:
                case 0x33:
                case 0x34:
                case 0x35:
                case 0x36:
                  uVar10 = 0xfffffff3;
                  break;
                case 0x1f:
                case 0x20:
                  uVar10 = 0xfffffff0;
                  break;
                case 0x28:
                case 0x29:
                case 0x3d:
                  uVar10 = 0xfffffffb;
                  break;
                case -2:
                case -1:
                  uVar10 = 0xffffffa1;
                }
                _raw_spin_unlock_irqrestore(lVar5,uVar8,param_3,0,0,0,0,0);
                _printk(&DAT_00101686,"__gh_msgq_recv",uVar9 & 0xffffffff);
                break;
              }
              *(undefined1 *)((long)puVar11 + 0x41) = 1;
              _raw_spin_unlock_irqrestore(lVar5,uVar8,param_3,0,0,0,0,0);
              bVar3 = *(char *)((long)puVar11 + 0x41) == '\0';
            } while (((param_5 >> 0x20 & 1) == 0) || (*(char *)((long)puVar11 + 0x41) == '\0'));
            goto LAB_0010067c;
          }
          goto LAB_0010054c;
        }
        iVar4 = ___ratelimit(gh_msgq_recv__rs_7,"gh_msgq_recv");
        if (iVar4 != 0) {
          uVar2 = *param_1;
          puVar6 = &DAT_001014cf;
          goto LAB_00100740;
        }
      }
      uVar10 = 0xfffffff5;
    }
    else {
      _printk(&DAT_001016d9,"gh_msgq_recv");
    }
    _raw_spin_unlock(puVar1);
  }
LAB_0010067c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10;
LAB_0010071c:
  uVar10 = 0xfffffe00;
  goto LAB_0010067c;
}



//------------------------------------------------------------
// gh_msgq_send @ 0010079c size=884
// signature: undefined gh_msgq_send(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_msgq_send(undefined4 *param_1,long param_2,ulong param_3,ulong param_4)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined *puVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined8 uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar5 = sp_el0;
  uVar9 = 0xffffffea;
  local_68 = *(long *)(lVar5 + 0x638);
  if (((param_1 == (undefined4 *)0x0) || (param_2 == 0)) || (param_3 == 0)) goto LAB_001009f8;
  if (0xf0 < param_3) {
    uVar9 = 0xfffffff9;
    goto LAB_001009f8;
  }
  puVar11 = *(undefined8 **)(param_1 + 2);
  if (puVar11 == (undefined8 *)0x0) {
LAB_001008c4:
    uVar9 = 0xfffffff5;
  }
  else {
    puVar1 = puVar11 + 1;
    _raw_spin_lock(puVar1);
    if ((undefined4 *)*puVar11 == param_1) {
      if ((puVar11[2] == -1) && (((param_4 >> 0x20 & 1) != 0 || (*(char *)(param_1 + 1) != '\0'))))
      {
        iVar4 = ___ratelimit(gh_msgq_send__rs,"gh_msgq_send");
        if (iVar4 != 0) {
          uVar2 = *param_1;
          puVar6 = &DAT_00101594;
LAB_00100ab8:
          _printk(puVar6,"gh_msgq_send",uVar2);
        }
      }
      else {
        _raw_spin_unlock(puVar1);
        if (puVar11[2] == -1) {
          local_78 = 0;
          uStack_70 = 0;
          local_88 = 0;
          uStack_80 = 0;
          local_90 = 0;
          init_wait_entry(&local_90,0);
          while (lVar5 = prepare_to_wait_event(puVar11 + 9,&local_90,1), puVar11[2] == -1) {
            if (lVar5 != 0) {
              if ((int)lVar5 != 0) goto LAB_00100a94;
              goto LAB_00100898;
            }
            schedule();
          }
          finish_wait(puVar11 + 9,&local_90);
        }
LAB_00100898:
        _raw_spin_lock(puVar1);
        if (*(int *)(puVar11 + 4) != 0) {
          _raw_spin_unlock(puVar1);
          bVar3 = *(char *)(puVar11 + 8) == '\0';
          if (((param_4 >> 0x20 & 1) == 0) || (*(char *)(puVar11 + 8) == '\0')) {
            uVar10 = param_4 & 0xffffffff;
            puVar1 = puVar11 + 7;
            uVar9 = 0xfffffff5;
            do {
              if (!bVar3) {
                local_78 = 0;
                uStack_70 = 0;
                local_88 = 0;
                uStack_80 = 0;
                local_90 = 0;
                init_wait_entry(&local_90,0);
                while (lVar5 = prepare_to_wait_event(puVar11 + 9,&local_90,1),
                      *(char *)(puVar11 + 8) != '\0') {
                  if (lVar5 != 0) {
                    if ((int)lVar5 == 0) goto LAB_0010095c;
                    goto LAB_00100a94;
                  }
                  schedule();
                }
                finish_wait(puVar11 + 9,&local_90);
              }
LAB_0010095c:
              uVar7 = _raw_spin_lock_irqsave(puVar1);
              uVar8 = puVar11[2];
              CallHyperVisor(0x601b);
              local_90 = 0;
              iVar4 = (int)uVar8;
              if (iVar4 != 0x3d) {
                switch(iVar4) {
                case 0:
                  *(bool *)(puVar11 + 8) = param_3 == 0;
                  _raw_spin_unlock_irqrestore(puVar1,uVar7,param_2,uVar10,0,0,0,0);
                  uVar9 = 0;
                  goto LAB_001009f8;
                default:
                  uVar9 = 0xffffffea;
                  break;
                case 10:
                  uVar9 = 0xfffffff4;
                  break;
                case 0x1e:
                case 0x32:
                case 0x33:
                case 0x34:
                case 0x35:
                case 0x36:
                  uVar9 = 0xfffffff3;
                  break;
                case 0x1f:
                case 0x20:
                  uVar9 = 0xfffffff0;
                  break;
                case 0x28:
                case 0x29:
                case 0x3c:
                  uVar9 = 0xfffffffb;
                  break;
                case -2:
                case -1:
                  uVar9 = 0xffffffa1;
                }
                _raw_spin_unlock_irqrestore(puVar1,uVar7,param_2,uVar10,0,0,0,0);
                _printk(&DAT_0010172a,"__gh_msgq_send",uVar8 & 0xffffffff);
                break;
              }
              *(undefined1 *)(puVar11 + 8) = 1;
              _raw_spin_unlock_irqrestore(puVar1,uVar7,param_2,uVar10,0,0,0,0);
              bVar3 = *(char *)(puVar11 + 8) == '\0';
            } while (((param_4 >> 0x20 & 1) == 0) || (*(char *)(puVar11 + 8) == '\0'));
            goto LAB_001009f8;
          }
          goto LAB_001008c4;
        }
        iVar4 = ___ratelimit(gh_msgq_send__rs_10,"gh_msgq_send");
        if (iVar4 != 0) {
          uVar2 = *param_1;
          puVar6 = &DAT_0010156b;
          goto LAB_00100ab8;
        }
      }
      uVar9 = 0xfffffff5;
    }
    else {
      _printk(&DAT_001016d9,"gh_msgq_send");
    }
    _raw_spin_unlock(puVar1);
  }
LAB_001009f8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9;
LAB_00100a94:
  uVar9 = 0xfffffe00;
  goto LAB_001009f8;
}



//------------------------------------------------------------
// gh_msgq_register @ 00100b14 size=324
// signature: undefined gh_msgq_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** gh_msgq_register(int param_1)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  undefined **ppuVar3;
  
  if (param_1 < 0) {
    ppuVar2 = (undefined **)0xffffffffffffffea;
  }
  else {
    _raw_spin_lock(&gh_msgq_cap_list_lock);
    ppuVar3 = &gh_msgq_cap_list;
    do {
      ppuVar3 = (undefined **)*ppuVar3;
      if (ppuVar3 == &gh_msgq_cap_list) goto LAB_00100b68;
    } while (*(int *)(ppuVar3 + -1) != param_1);
    ppuVar3 = ppuVar3 + -0x10;
    if (ppuVar3 == (undefined **)0x0) {
LAB_00100b68:
      ppuVar3 = (undefined **)gh_msgq_alloc_entry(param_1);
      if ((undefined **)0xfffffffffffff000 < ppuVar3) {
        _raw_spin_unlock(&gh_msgq_cap_list_lock);
        return ppuVar3;
      }
    }
    _raw_spin_unlock(&gh_msgq_cap_list_lock);
    ppuVar1 = ppuVar3 + 1;
    _raw_spin_lock(ppuVar1);
    if (*ppuVar3 == (undefined *)0x0) {
      ppuVar2 = (undefined **)kmalloc_trace(__raw_spin_lock,0xb20,0x10);
      if (ppuVar2 == (undefined **)0x0) {
        _raw_spin_unlock(ppuVar1);
        ppuVar2 = (undefined **)0xfffffffffffffff4;
      }
      else {
        *(int *)ppuVar2 = param_1;
        ppuVar2[1] = (undefined *)ppuVar3;
        *(bool *)((long)ppuVar2 + 4) = param_1 == 10;
        *ppuVar3 = (undefined *)ppuVar2;
        _raw_spin_unlock(ppuVar1);
        _printk(&DAT_001015f7,param_1,*(undefined1 *)((long)ppuVar2 + 4));
      }
    }
    else {
      _raw_spin_unlock(ppuVar1);
      _printk(&DAT_00101505,"gh_msgq_register",param_1);
      ppuVar2 = (undefined **)0xfffffffffffffff0;
    }
  }
  return ppuVar2;
}



//------------------------------------------------------------
// gh_msgq_unregister @ 00100c5c size=164
// signature: undefined gh_msgq_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_msgq_unregister(undefined4 *param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar2 = *(undefined8 **)(param_1 + 2);
    puVar1 = puVar2 + 1;
    _raw_spin_lock(puVar1);
    if ((undefined4 *)*puVar2 == param_1) {
      *puVar2 = 0;
      _raw_spin_unlock(puVar1);
      _printk(&DAT_0010162e,"gh_msgq_unregister",*param_1);
      kfree(param_1);
      return 0;
    }
    _printk(&DAT_001015c6,"gh_msgq_unregister");
    _raw_spin_unlock(puVar1);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gh_msgq_populate_cap_info @ 00100d04 size=608
// signature: undefined gh_msgq_populate_cap_info(void)
// callers: []
//------------------------------------------------------------

ulong gh_msgq_populate_cap_info(int param_1,undefined *param_2,int param_3,int param_4)

{
  long *plVar1;
  uint uVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined *puVar5;
  ulong uVar6;
  
  if (param_1 < 0) {
    _printk(&DAT_0010152f,"gh_msgq_populate_cap_info");
    return 0xffffffea;
  }
  if (param_4 < 0) {
    _printk(&DAT_001014ae,"gh_msgq_populate_cap_info");
    return 0xfffffffa;
  }
  _raw_spin_lock(&gh_msgq_cap_list_lock);
  ppuVar4 = &gh_msgq_cap_list;
  do {
    ppuVar4 = (undefined **)*ppuVar4;
    if (ppuVar4 == &gh_msgq_cap_list) goto LAB_00100da4;
  } while (*(int *)(ppuVar4 + -1) != param_1);
  if (param_3 == 1) {
    puVar5 = ppuVar4[-0xd];
  }
  else {
    if (param_3 != 0) goto LAB_00100d7c;
    puVar5 = ppuVar4[-0xe];
  }
  if (puVar5 != (undefined *)0xffffffffffffffff) {
LAB_00100d7c:
    _raw_spin_unlock(&gh_msgq_cap_list_lock);
    return 0xffffffea;
  }
  ppuVar4 = ppuVar4 + -0x10;
  if (ppuVar4 == (undefined **)0x0) {
LAB_00100da4:
    ppuVar4 = (undefined **)gh_msgq_alloc_entry(param_1);
    if ((undefined **)0xfffffffffffff000 < ppuVar4) {
      _raw_spin_unlock(&gh_msgq_cap_list_lock);
      return (ulong)ppuVar4 & 0xffffffff;
    }
  }
  _raw_spin_unlock(&gh_msgq_cap_list_lock);
  if (param_3 == 1) {
    uVar2 = request_threaded_irq(param_4,gh_msgq_rx_isr,0,0,ppuVar4[6],ppuVar4);
    if (-1 < (int)uVar2) {
      _raw_spin_lock(ppuVar4 + 1);
      ppuVar4[3] = param_2;
      *(int *)((long)ppuVar4 + 0x24) = param_4;
      _raw_spin_unlock(ppuVar4 + 1);
      ppuVar4 = ppuVar4 + 0xc;
LAB_00100e70:
      __wake_up(ppuVar4,1,1,0);
      irq_set_irq_wake(param_4,1);
      return 0;
    }
  }
  else {
    if (param_3 != 0) {
      _printk(&DAT_0010154b,"gh_msgq_populate_cap_info");
      uVar6 = 0xffffffea;
      goto LAB_00100e98;
    }
    uVar2 = request_threaded_irq(param_4,gh_msgq_tx_isr,0,0,ppuVar4[5],ppuVar4);
    if (-1 < (int)uVar2) {
      _raw_spin_lock(ppuVar4 + 1);
      ppuVar4[2] = param_2;
      *(int *)(ppuVar4 + 4) = param_4;
      _raw_spin_unlock(ppuVar4 + 1);
      ppuVar4 = ppuVar4 + 9;
      goto LAB_00100e70;
    }
  }
  uVar6 = (ulong)uVar2;
LAB_00100e98:
  _raw_spin_lock(&gh_msgq_cap_list_lock);
  uVar3 = __list_del_entry_valid(ppuVar4 + 0x10);
  if ((uVar3 & 1) != 0) {
    puVar5 = ppuVar4[0x10];
    plVar1 = (long *)ppuVar4[0x11];
    *(long **)(puVar5 + 8) = plVar1;
    *plVar1 = (long)puVar5;
  }
  ppuVar4[0x10] = (undefined *)0xdead000000000100;
  ppuVar4[0x11] = (undefined *)0xdead000000000122;
  _raw_spin_unlock(&gh_msgq_cap_list_lock);
  kfree(ppuVar4[5]);
  kfree(ppuVar4[6]);
  kfree(ppuVar4);
  return uVar6;
}



//------------------------------------------------------------
// gh_msgq_tx_isr @ 00100f68 size=84
// signature: undefined gh_msgq_tx_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_msgq_tx_isr(undefined8 param_1,long param_2)

{
  _raw_spin_lock(param_2 + 0x38);
  *(undefined1 *)(param_2 + 0x40) = 0;
  _raw_spin_unlock(param_2 + 0x38);
  __wake_up(param_2 + 0x48,1,1,0);
  return 1;
}



//------------------------------------------------------------
// gh_msgq_rx_isr @ 00100fc0 size=84
// signature: undefined gh_msgq_rx_isr(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_msgq_rx_isr(undefined8 param_1,long param_2)

{
  _raw_spin_lock(param_2 + 0x3c);
  *(undefined1 *)(param_2 + 0x41) = 0;
  _raw_spin_unlock(param_2 + 0x3c);
  __wake_up(param_2 + 0x60,1,1,0);
  return 1;
}



//------------------------------------------------------------
// gh_msgq_reset_cap_info @ 00101018 size=328
// signature: undefined gh_msgq_reset_cap_info(void)
// callers: []
//------------------------------------------------------------

undefined4 gh_msgq_reset_cap_info(int param_1,int param_2,int *param_3)

{
  undefined *puVar1;
  undefined **ppuVar2;
  
  if (param_3 != (int *)0x0) {
    _raw_spin_lock(&gh_msgq_cap_list_lock);
    ppuVar2 = &gh_msgq_cap_list;
    do {
      ppuVar2 = (undefined **)*ppuVar2;
      if (ppuVar2 == &gh_msgq_cap_list) {
        _raw_spin_unlock(&gh_msgq_cap_list_lock);
        return 0xffffffea;
      }
    } while (*(int *)(ppuVar2 + -1) != param_1);
    _raw_spin_unlock(&gh_msgq_cap_list_lock);
    if (ppuVar2 + -0x10 != (undefined **)0x0) {
      if (param_2 == 1) {
        if (*(int *)((long)ppuVar2 + -0x5c) == 0) {
          puVar1 = &DAT_00101712;
          goto LAB_0010114c;
        }
        *param_3 = *(int *)((long)ppuVar2 + -0x5c);
        _raw_spin_lock(ppuVar2 + -0xf);
        *(undefined4 *)((long)ppuVar2 + -0x5c) = 0;
        ppuVar2[-0xd] = (undefined *)0xffffffffffffffff;
      }
      else {
        if (param_2 != 0) {
          _printk(&DAT_0010154b,"gh_msgq_reset_cap_info");
          return 0xffffffea;
        }
        if (*(int *)(ppuVar2 + -0xc) == 0) {
          puVar1 = &DAT_001016fa;
LAB_0010114c:
          _printk(puVar1,"gh_msgq_reset_cap_info");
          return 0xfffffffa;
        }
        *param_3 = *(int *)(ppuVar2 + -0xc);
        _raw_spin_lock(ppuVar2 + -0xf);
        *(undefined4 *)(ppuVar2 + -0xc) = 0;
        ppuVar2[-0xe] = (undefined *)0xffffffffffffffff;
      }
      _raw_spin_unlock(ppuVar2 + -0xf);
      if (*param_3 == 0) {
        return 0;
      }
      free_irq(*param_3,ppuVar2 + -0x10);
      return 0;
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 001013d0 size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001013dc size=128
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  undefined **ppuVar1;
  undefined **ppuVar2;
  
  _raw_spin_lock(&gh_msgq_cap_list_lock);
  ppuVar1 = (undefined **)gh_msgq_cap_list;
  while (ppuVar1 != &gh_msgq_cap_list) {
    ppuVar2 = (undefined **)*ppuVar1;
    kfree(ppuVar1[-0xb]);
    kfree(ppuVar1[-10]);
    kfree(ppuVar1 + -0x10);
    ppuVar1 = ppuVar2;
  }
  _raw_spin_unlock(&gh_msgq_cap_list_lock);
  return;
}



//------------------------------------------------------------
// kmalloc_trace @ 00103008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_msgq_register, gh_msgq_alloc_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00103010 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [gh_msgq_alloc_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 00103018 size=1
// signature: undefined kasprintf(void)
// callers: [gh_msgq_alloc_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103020 size=1
// signature: undefined __list_add_valid(void)
// callers: [gh_msgq_alloc_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103028 size=1
// signature: undefined kfree(void)
// callers: [gh_msgq_unregister, gh_msgq_populate_cap_info, cleanup_module, gh_msgq_alloc_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00103030 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gh_msgq_tx_isr, gh_msgq_send, gh_msgq_register, gh_msgq_unregister, gh_msgq_recv, gh_msgq_rx_isr, gh_msgq_populate_cap_info, cleanup_module, gh_msgq_reset_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00103038 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gh_msgq_tx_isr, gh_msgq_send, gh_msgq_register, gh_msgq_unregister, gh_msgq_recv, gh_msgq_rx_isr, gh_msgq_populate_cap_info, cleanup_module, gh_msgq_reset_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00103040 size=1
// signature: undefined init_wait_entry(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00103048 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00103050 size=1
// signature: undefined schedule(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00103058 size=1
// signature: undefined finish_wait(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00103060 size=1
// signature: undefined ___ratelimit(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103068 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103070 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103078 size=1
// signature: undefined _printk(void)
// callers: [gh_msgq_send, gh_msgq_register, gh_msgq_unregister, gh_msgq_recv, gh_msgq_populate_cap_info, gh_msgq_reset_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_msgq_send, gh_msgq_recv]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00103088 size=1
// signature: undefined request_threaded_irq(void)
// callers: [gh_msgq_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00103090 size=1
// signature: undefined __wake_up(void)
// callers: [gh_msgq_tx_isr, gh_msgq_rx_isr, gh_msgq_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00103098 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [gh_msgq_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001030a0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [gh_msgq_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 001030a8 size=1
// signature: undefined free_irq(void)
// callers: [gh_msgq_reset_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



