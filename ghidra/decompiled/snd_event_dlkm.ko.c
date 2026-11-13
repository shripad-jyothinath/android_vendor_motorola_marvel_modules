// Decompiled by Ghidra 12.2
// Program: snd_event_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// snd_event_client_register @ 0010026c size=272
// signature: undefined snd_event_client_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 snd_event_client_register(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined *puVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong uVar4;
  undefined8 uVar5;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(&snd_event_client_register__rs,"snd_event_client_register");
    if (iVar2 == 0) {
      uVar5 = 0xffffffea;
    }
    else {
      _printk(&DAT_001011c1,"snd_event_client_register");
      uVar5 = 0xffffffea;
    }
  }
  else {
    puVar3 = (undefined8 *)kmalloc_trace(__printk,0xdc0,0x30);
    if (puVar3 == (undefined8 *)0x0) {
      uVar5 = 0xfffffff4;
    }
    else {
      puVar3[2] = param_1;
      puVar3[3] = param_2;
      puVar3[4] = param_3;
      mutex_lock(snd_event_mutex);
      puVar1 = PTR_snd_event_client_list_00100fc8;
      uVar4 = __list_add_valid(puVar3,PTR_snd_event_client_list_00100fc8,&snd_event_client_list);
      if ((uVar4 & 1) != 0) {
        PTR_snd_event_client_list_00100fc8 = (undefined *)puVar3;
        *puVar3 = &snd_event_client_list;
        puVar3[1] = puVar1;
        *(undefined8 **)puVar1 = puVar3;
      }
      if (((master != 0) && (*(char *)(master + 0x1a) == '\0')) &&
         (iVar2 = snd_event_find_clients(), iVar2 == 0)) {
        *(undefined1 *)(master + 0x1a) = 1;
      }
      mutex_unlock(snd_event_mutex);
      uVar5 = 0;
    }
  }
  return uVar5;
}



//------------------------------------------------------------
// snd_event_find_clients @ 0010037c size=324
// signature: undefined snd_event_find_clients(void)
// callers: [snd_event_client_register, snd_event_master_register]
//------------------------------------------------------------

undefined8 snd_event_find_clients(long param_1)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  ulong *puVar5;
  ulong uVar6;
  ulong uVar7;
  undefined **ppuVar8;
  
  puVar5 = *(ulong **)(param_1 + 0x20);
  if (*puVar5 != 0) {
    uVar6 = 0;
    do {
      uVar7 = puVar5[1];
      plVar1 = (long *)(uVar7 + uVar6 * 0x20);
      if (*plVar1 == 0) {
        if ((undefined **)snd_event_client_list == &snd_event_client_list) {
          return 0xfffffffa;
        }
        lVar2 = uVar7 + uVar6 * 0x20;
        ppuVar8 = (undefined **)snd_event_client_list;
        do {
          if (*(char *)(ppuVar8 + 5) == '\0') {
            pcVar4 = *(code **)(lVar2 + 0x18);
            if (*(int *)(pcVar4 + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100450);
              (*pcVar4)();
            }
            iVar3 = (*pcVar4)(ppuVar8[2],*(undefined8 *)(lVar2 + 0x10));
            if (iVar3 != 0) {
              *plVar1 = (long)ppuVar8[2];
              *(undefined ***)(uVar7 + uVar6 * 0x20 + 8) = ppuVar8;
              *(undefined1 *)(ppuVar8 + 5) = 1;
              break;
            }
          }
          ppuVar8 = (undefined **)*ppuVar8;
        } while (ppuVar8 != &snd_event_client_list);
        if (*plVar1 == 0) {
          return 0xfffffffa;
        }
      }
      else {
        iVar3 = ___ratelimit(snd_event_find_clients__rs,"snd_event_find_clients");
        if (iVar3 != 0) {
          _printk(&DAT_00101220,"snd_event_find_clients",*plVar1);
        }
      }
      uVar6 = (ulong)((int)uVar6 + 1);
    } while (uVar6 < *puVar5);
  }
  return 0;
}



//------------------------------------------------------------
// snd_event_client_deregister @ 001004c4 size=376
// signature: undefined snd_event_client_deregister(void)
// callers: []
//------------------------------------------------------------

undefined4 snd_event_client_deregister(undefined *param_1)

{
  undefined *puVar1;
  long *plVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  ulong uVar6;
  undefined **ppuVar7;
  ulong uVar8;
  
  if (param_1 == (undefined *)0x0) {
    iVar3 = ___ratelimit(&snd_event_client_deregister__rs,"snd_event_client_deregister");
    if (iVar3 != 0) {
      _printk(&DAT_001011c1,"snd_event_client_deregister");
    }
    return 0xffffffea;
  }
  mutex_lock(snd_event_mutex);
  for (ppuVar7 = (undefined **)snd_event_client_list; ppuVar7 != &snd_event_client_list;
      ppuVar7 = (undefined **)*ppuVar7) {
    if ((ppuVar7[2] == param_1) && (ppuVar7[3] != (undefined *)0x0)) {
      if (ppuVar7 != (undefined **)0x0) {
        *(undefined1 *)((long)ppuVar7 + 0x29) = 0;
        if (master == 0) goto LAB_00100580;
        uVar6 = **(ulong **)(master + 0x20);
        if (uVar6 == 0) goto LAB_00100580;
        uVar8 = 0;
        uVar5 = (*(ulong **)(master + 0x20))[1];
        goto LAB_0010055c;
      }
      break;
    }
  }
  uVar4 = 0xffffffed;
  goto LAB_00100504;
  while (uVar8 = (ulong)((int)uVar8 + 1), uVar8 < uVar6) {
LAB_0010055c:
    if (*(undefined **)(*(long *)(uVar5 + uVar8 * 0x20 + 8) + 0x10) == param_1) {
      if (*(char *)(master + 0x1a) == '\0') {
        uVar4 = 0;
      }
      else {
        uVar4 = check_and_update_fwk_state();
        plVar2 = (long *)(master + 0x20);
        *(undefined1 *)(master + 0x1a) = 0;
        uVar5 = *(ulong *)(*plVar2 + 8);
      }
      *(undefined8 *)(uVar5 + uVar8 * 0x20) = 0;
      goto LAB_00100584;
    }
  }
LAB_00100580:
  uVar4 = 0;
LAB_00100584:
  uVar6 = __list_del_entry_valid(ppuVar7);
  if ((uVar6 & 1) != 0) {
    puVar1 = *ppuVar7;
    plVar2 = (long *)ppuVar7[1];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  *ppuVar7 = (undefined *)0xdead000000000100;
  ppuVar7[1] = (undefined *)0xdead000000000122;
  kfree(ppuVar7);
LAB_00100504:
  mutex_unlock(snd_event_mutex);
  return uVar4;
}



//------------------------------------------------------------
// check_and_update_fwk_state @ 0010063c size=888
// signature: undefined check_and_update_fwk_state(void)
// callers: [snd_event_notify, snd_event_client_deregister, snd_event_master_deregister]
//------------------------------------------------------------

int check_and_update_fwk_state(void)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  ulong *puVar4;
  code *pcVar5;
  ulong uVar6;
  ulong uVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  
  puVar4 = (ulong *)master[4];
  uVar6 = *puVar4;
  if (uVar6 == 0) {
    bVar8 = 1;
  }
  else {
    uVar7 = uVar6 - 1;
    if ((uVar7 == 0) || (0x7ffffffe < (uint)uVar7 || uVar7 >> 0x1f != 0)) {
      uVar7 = 0;
      uVar10 = 0;
      bVar8 = 1;
    }
    else {
      uVar7 = uVar6 & 0xfffffffffffffffe;
      bVar9 = 1;
      uVar10 = (uint)uVar6 & 0xfffffffe;
      bVar8 = 1;
      plVar11 = (long *)(puVar4[1] + 0x28);
      uVar12 = uVar7;
      do {
        bVar9 = bVar9 & *(char *)(plVar11[-4] + 0x29) != '\0';
        bVar8 = bVar8 & *(char *)(*plVar11 + 0x29) != '\0';
        uVar12 = uVar12 - 2;
        plVar11 = plVar11 + 8;
      } while (uVar12 != 0);
      bVar8 = bVar8 & bVar9;
      if (uVar6 == uVar7) goto LAB_001006c8;
    }
    do {
      uVar10 = uVar10 + 1;
      lVar13 = uVar7 * 0x20;
      uVar7 = (ulong)(int)uVar10;
      bVar8 = bVar8 & *(char *)(*(long *)(puVar4[1] + lVar13 + 8) + 0x29) != '\0';
    } while (uVar7 < uVar6);
  }
LAB_001006c8:
  bVar9 = 0;
  if (*(char *)(master + 3) != '\0') {
    bVar9 = bVar8;
  }
  if (*(byte *)((long)master + 0x19) != bVar9) {
    if (bVar9 == 0) {
      pcVar5 = *(code **)(master[1] + 8);
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != -0x6fdc0bc8) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x822b,0x100784);
          (*pcVar5)();
        }
        (*pcVar5)(*master,master[2]);
        puVar4 = (ulong *)master[4];
        uVar6 = *puVar4;
      }
      puVar3 = master;
      if (uVar6 != 0) {
        uVar6 = 0;
        do {
          lVar13 = *(long *)(puVar4[1] + uVar6 * 0x20 + 8);
          pcVar5 = *(code **)(*(long *)(lVar13 + 0x18) + 8);
          if (pcVar5 != (code *)0x0) {
            if (*(int *)(pcVar5 + -4) != -0x6fdc0bc8) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x1007f0);
              (*pcVar5)();
            }
            (*pcVar5)(*(undefined8 *)(lVar13 + 0x10),*(undefined8 *)(lVar13 + 0x20));
            puVar3 = master;
          }
          puVar4 = (ulong *)puVar3[4];
          uVar6 = (ulong)((int)uVar6 + 1);
        } while (uVar6 < *puVar4);
      }
    }
    else {
      puVar3 = master;
      if (uVar6 != 0) {
        uVar6 = 0;
        do {
          lVar13 = *(long *)(puVar4[1] + uVar6 * 0x20 + 8);
          pcVar5 = (code *)**(undefined8 **)(lVar13 + 0x18);
          uVar10 = (uint)uVar6;
          if (pcVar5 != (code *)0x0) {
            if (*(int *)(pcVar5 + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x100748);
              (*pcVar5)();
            }
            iVar1 = (*pcVar5)(*(undefined8 *)(lVar13 + 0x10),*(undefined8 *)(lVar13 + 0x20));
            if (iVar1 != 0) {
              iVar2 = ___ratelimit(check_and_update_fwk_state__rs,"check_and_update_fwk_state");
              if (iVar2 != 0) {
                _dev_err(*(undefined8 *)(lVar13 + 0x10),"%s: enable failed\n",
                         "check_and_update_fwk_state");
                goto joined_r0x001009ac;
              }
              if ((int)uVar10 < 1) {
                return iVar1;
              }
              goto LAB_001008e0;
            }
            puVar3 = master;
          }
          puVar4 = (ulong *)puVar3[4];
          uVar6 = (ulong)(int)(uVar10 + 1);
        } while (uVar6 < *puVar4);
      }
      pcVar5 = *(code **)puVar3[1];
      if (pcVar5 != (code *)0x0) {
        if (*(int *)(pcVar5 + -4) != -0x523d0be9) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x100828);
          (*pcVar5)();
        }
        iVar1 = (*pcVar5)(*puVar3,puVar3[2]);
        if (iVar1 != 0) {
          iVar2 = ___ratelimit(check_and_update_fwk_state__rs_10,"check_and_update_fwk_state");
          if (iVar2 != 0) {
            _dev_err(*master,"%s: enable failed\n","check_and_update_fwk_state");
          }
          uVar10 = *(uint *)master[4];
          uVar6 = (ulong)uVar10;
joined_r0x001009ac:
          if ((int)uVar10 < 1) {
            return iVar1;
          }
LAB_001008e0:
          uVar6 = (uVar6 & 0xffffffff) + 1;
          puVar3 = master;
          do {
            lVar13 = *(long *)(*(long *)(puVar3[4] + 8) + (ulong)((int)uVar6 - 2) * 0x20 + 8);
            pcVar5 = *(code **)(*(long *)(lVar13 + 0x18) + 8);
            if (pcVar5 != (code *)0x0) {
              if (*(int *)(pcVar5 + -4) != -0x6fdc0bc8) {
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x10093c);
                (*pcVar5)();
              }
              (*pcVar5)(*(undefined8 *)(lVar13 + 0x10),*(undefined8 *)(lVar13 + 0x20));
              puVar3 = master;
            }
            uVar6 = uVar6 - 1;
          } while (1 < uVar6);
          return iVar1;
        }
        puVar3 = master;
      }
    }
    *(byte *)((long)puVar3 + 0x19) = bVar9;
  }
  return 0;
}



//------------------------------------------------------------
// snd_event_mstr_add_client @ 001009b8 size=304
// signature: undefined snd_event_mstr_add_client(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void snd_event_mstr_add_client(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  ulong *puVar5;
  ulong uVar6;
  
  puVar5 = (ulong *)*param_1;
  if ((ulong *)0xfffffffffffff000 < puVar5) {
    iVar2 = ___ratelimit(snd_event_mstr_add_client__rs,"snd_event_mstr_add_client");
    if (iVar2 == 0) {
      return;
    }
    _printk(&DAT_00101246,"snd_event_mstr_add_client");
    return;
  }
  if (puVar5 == (ulong *)0x0) {
    puVar5 = (ulong *)kmalloc_trace(__printk,0xdc0,0x10);
    if (puVar5 != (ulong *)0x0) {
      uVar3 = kmalloc_trace(__printk,0xdc0,0x20);
      puVar5[1] = uVar3;
      if (uVar3 != 0) {
        uVar6 = 0x20;
        *param_1 = puVar5;
        goto LAB_00100a7c;
      }
    }
  }
  else {
    uVar6 = *puVar5 * 0x20 + 0x20;
    uVar3 = krealloc(puVar5[1],uVar6,0xdc0);
    if (uVar3 != 0) {
      puVar5[1] = uVar3;
LAB_00100a7c:
      uVar4 = *puVar5;
      if ((((uVar4 & 0x7ffffffffffffff) >> 0x3a != 0) || (uVar6 < uVar4 * 0x20)) ||
         (uVar6 + uVar4 * -0x20 < 8)) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x100ae8);
        (*pcVar1)();
      }
      *(undefined8 *)(uVar3 + uVar4 * 0x20) = 0;
      *(undefined8 *)(puVar5[1] + *puVar5 * 0x20 + 0x10) = param_3;
      *(undefined8 *)(puVar5[1] + *puVar5 * 0x20 + 0x18) = param_2;
      *puVar5 = *puVar5 + 1;
      return;
    }
  }
  *param_1 = 0xfffffffffffffff4;
  return;
}



//------------------------------------------------------------
// snd_event_master_register @ 00100aec size=360
// signature: undefined snd_event_master_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 snd_event_master_register(long param_1,long param_2,ulong param_3,long param_4)

{
  int iVar1;
  long *plVar2;
  undefined8 uVar3;
  
  if (param_1 == 0) {
    iVar1 = ___ratelimit(snd_event_master_register__rs,"snd_event_master_register");
    if (iVar1 == 0) {
      return 0xffffffea;
    }
    _printk(&DAT_001011c1,"snd_event_master_register");
    return 0xffffffea;
  }
  mutex_lock(snd_event_mutex);
  if (master == (long *)0x0) {
    mutex_unlock(snd_event_mutex);
    if ((param_3 == 0) || (0xfffffffffffff000 < param_3)) {
      _dev_err(param_1,"%s: Invalid clients ptr\n","snd_event_master_register");
      return 0xffffffea;
    }
    plVar2 = (long *)kmalloc_trace(__printk,0xdc0,0x28);
    if (plVar2 == (long *)0x0) {
      return 0xfffffff4;
    }
    *plVar2 = param_1;
    plVar2[1] = param_2;
    plVar2[2] = param_4;
    plVar2[4] = param_3;
    mutex_lock(snd_event_mutex);
    master = plVar2;
    iVar1 = snd_event_find_clients(plVar2);
    if (iVar1 == 0) {
      uVar3 = 0;
      *(undefined1 *)((long)master + 0x1a) = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    _dev_err(param_1,"%s: master already allocated with %pK\n","snd_event_master_register",*master);
    uVar3 = 0xffffff8e;
  }
  mutex_unlock(snd_event_mutex);
  return uVar3;
}



//------------------------------------------------------------
// snd_event_master_deregister @ 00100c58 size=236
// signature: undefined snd_event_master_deregister(void)
// callers: []
//------------------------------------------------------------

undefined4 snd_event_master_deregister(long param_1)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  long *plVar4;
  
  if (param_1 == 0) {
    iVar2 = ___ratelimit(snd_event_master_deregister__rs,"snd_event_master_deregister");
    if (iVar2 == 0) {
      uVar3 = 0xffffffea;
    }
    else {
      _printk(&DAT_001011c1,"snd_event_master_deregister");
      uVar3 = 0xffffffea;
    }
  }
  else {
    mutex_lock(snd_event_mutex);
    plVar4 = master;
    if (master == (long *)0x0) {
      uVar3 = 0xffffffed;
    }
    else if (*master == param_1) {
      pcVar1 = (char *)((long)master + 0x1a);
      *(undefined1 *)(master + 3) = 0;
      if (*pcVar1 == '\0') {
        uVar3 = 0;
      }
      else {
        uVar3 = check_and_update_fwk_state();
        plVar4 = master;
      }
      kfree(*(undefined8 *)(plVar4[4] + 8));
      kfree(master[4]);
      kfree(master);
      master = (long *)0x0;
    }
    else {
      uVar3 = 0xfffffffa;
    }
    mutex_unlock(snd_event_mutex);
  }
  return uVar3;
}



//------------------------------------------------------------
// snd_event_notify @ 00100d48 size=388
// signature: undefined snd_event_notify(void)
// callers: []
//------------------------------------------------------------

undefined4 snd_event_notify(undefined *param_1,int param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  
  if (param_1 == (undefined *)0x0) {
    iVar2 = ___ratelimit(snd_event_notify__rs,"snd_event_notify");
    if (iVar2 != 0) {
      _printk(&DAT_001011c1,"snd_event_notify");
    }
    uVar3 = 0xffffffea;
  }
  else {
    mutex_lock(snd_event_mutex);
    puVar1 = master;
    ppuVar4 = (undefined **)snd_event_client_list;
    if (((undefined **)snd_event_client_list == &snd_event_client_list) &&
       (master == (undefined8 *)0x0)) {
      iVar2 = ___ratelimit(snd_event_notify__rs_4,"snd_event_notify");
      if (iVar2 != 0) {
        _dev_err(param_1,"%s: No device registered\n","snd_event_notify");
      }
      uVar3 = 0xffffffed;
    }
    else {
      for (; ppuVar4 != &snd_event_client_list; ppuVar4 = (undefined **)*ppuVar4) {
        if ((ppuVar4[2] == param_1) && (ppuVar4[3] != (undefined *)0x0)) {
          if (ppuVar4 != (undefined **)0x0) {
            *(bool *)((long)ppuVar4 + 0x29) = param_2 != 0;
            if (puVar1 == (undefined8 *)0x0) goto LAB_00100e58;
            goto LAB_00100e44;
          }
          break;
        }
      }
      if ((master == (undefined8 *)0x0) || ((undefined *)*master != param_1)) {
        iVar2 = ___ratelimit(snd_event_notify__rs_6,"snd_event_notify");
        if (iVar2 != 0) {
          _dev_err(param_1,"%s: No snd dev entry found\n","snd_event_notify");
        }
        uVar3 = 0xfffffffa;
      }
      else {
        *(bool *)(master + 3) = param_2 != 0;
LAB_00100e44:
        if (*(char *)((long)puVar1 + 0x1a) == '\0') {
LAB_00100e58:
          uVar3 = 0;
        }
        else {
          uVar3 = check_and_update_fwk_state();
        }
      }
    }
    mutex_unlock(snd_event_mutex);
  }
  return uVar3;
}



//------------------------------------------------------------
// kmalloc_trace @ 00102008 size=1
// signature: undefined kmalloc_trace(void)
// callers: [snd_event_mstr_add_client, snd_event_client_register, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102010 size=1
// signature: undefined mutex_lock(void)
// callers: [snd_event_client_register, snd_event_notify, snd_event_client_deregister, snd_event_master_deregister, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102018 size=1
// signature: undefined __list_add_valid(void)
// callers: [snd_event_client_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102020 size=1
// signature: undefined mutex_unlock(void)
// callers: [snd_event_client_register, snd_event_notify, snd_event_client_deregister, snd_event_master_deregister, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00102028 size=1
// signature: undefined ___ratelimit(void)
// callers: [snd_event_mstr_add_client, snd_event_client_register, snd_event_notify, snd_event_client_deregister, snd_event_find_clients, snd_event_master_deregister, check_and_update_fwk_state, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102030 size=1
// signature: undefined _printk(void)
// callers: [snd_event_mstr_add_client, snd_event_client_register, snd_event_notify, snd_event_client_deregister, snd_event_find_clients, snd_event_master_deregister, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00102038 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [snd_event_client_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102040 size=1
// signature: undefined kfree(void)
// callers: [snd_event_client_deregister, snd_event_master_deregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [snd_event_notify, check_and_update_fwk_state, snd_event_master_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 00102050 size=1
// signature: undefined krealloc(void)
// callers: [snd_event_mstr_add_client]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



