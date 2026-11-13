// Decompiled by Ghidra 12.2
// Program: slimbus.ko
// Image base: 00100000

//------------------------------------------------------------
// slim_device_match @ 00100a4c size=168
// signature: undefined slim_device_match(void)
// callers: []
//------------------------------------------------------------

bool slim_device_match(long param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  short *psVar3;
  
  lVar2 = of_match_device(*(undefined8 *)(param_2 + 0x28),param_1);
  if (lVar2 == 0) {
    for (psVar3 = *(short **)(param_2 + 0xb0); (*psVar3 != 0 || (psVar3[1] != 0));
        psVar3 = psVar3 + 8) {
      if ((((*psVar3 == *(short *)(param_1 + 0x394)) && (psVar3[1] == *(short *)(param_1 + 0x392)))
          && (psVar3[2] == (ushort)*(byte *)(param_1 + 0x391))) &&
         (psVar3[3] == (ushort)*(byte *)(param_1 + 0x390))) goto LAB_00100adc;
    }
    psVar3 = (short *)0x0;
LAB_00100adc:
    bVar1 = psVar3 != (short *)0x0;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}



//------------------------------------------------------------
// slim_device_uevent @ 00100af8 size=56
// signature: undefined slim_device_uevent(void)
// callers: []
//------------------------------------------------------------

void slim_device_uevent(long *param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = param_1[0xe];
  if (lVar1 == 0) {
    lVar1 = *param_1;
  }
  add_uevent_var(param_2,"MODALIAS=slim:%s",lVar1);
  return;
}



//------------------------------------------------------------
// slim_device_probe @ 00100b34 size=200
// signature: undefined slim_device_probe(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_device_probe(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  pcVar3 = *(code **)(*(long *)(param_1 + 0x88) + -0x20);
  if (*(int *)(pcVar3 + -4) != 0x48aa0462) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100b68);
    (*pcVar3)();
  }
  uVar2 = (*pcVar3)();
  if ((int)uVar2 == 0) {
    if ((*(char *)(param_1 + 0x3a5) == '\0') &&
       (iVar1 = slim_device_alloc_laddr(param_1,0), iVar1 != 0)) {
      _dev_err(param_1,"Failed to get logical address\n");
      uVar2 = 0xfffffdfb;
    }
    else {
      if (*(int *)(param_1 + 0x3a0) != 1) {
        *(undefined4 *)(param_1 + 0x3a0) = 1;
        if ((*(long *)(param_1 + 0x88) != 0) &&
           (pcVar3 = *(code **)(*(long *)(param_1 + 0x88) + -8), pcVar3 != (code *)0x0)) {
          if (*(int *)(pcVar3 + -4) != -0x234737bf) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100bcc);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,1);
        }
      }
      uVar2 = 0;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// slim_device_remove @ 00100c00 size=68
// signature: undefined slim_device_remove(void)
// callers: []
//------------------------------------------------------------

void slim_device_remove(long param_1)

{
  code *pcVar1;
  
  if ((*(long *)(param_1 + 0x88) != 0) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + -0x18), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x34fba2ac) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100c34);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// __slim_driver_register @ 00100c48 size=80
// signature: undefined __slim_driver_register(void)
// callers: []
//------------------------------------------------------------

undefined8 __slim_driver_register(long *param_1,long param_2)

{
  undefined8 uVar1;
  
  if (((param_1[9] == 0) && (param_1[0x1a] == 0)) || (*param_1 == 0)) {
    uVar1 = 0xffffffea;
  }
  else {
    param_1[5] = (long)&slimbus_bus;
    param_1[6] = param_2;
    uVar1 = driver_register(param_1 + 4);
  }
  return uVar1;
}



//------------------------------------------------------------
// slim_driver_unregister @ 00100c9c size=32
// signature: undefined slim_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void slim_driver_unregister(long param_1)

{
  driver_unregister(param_1 + 0x20);
  return;
}



//------------------------------------------------------------
// slim_register_controller @ 00100cc0 size=564
// signature: undefined slim_register_controller(void)
// callers: []
//------------------------------------------------------------

void slim_register_controller(long *param_1)

{
  int iVar1;
  long lVar2;
  char *param0;
  long lVar3;
  uint local_80 [2];
  undefined1 local_78;
  undefined1 local_77;
  undefined2 local_76;
  undefined2 local_74;
  undefined8 local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  iVar1 = ida_alloc_range(ctrl_ida,0,0xffffffff,0xcc0);
  if (-1 < iVar1) {
    *(int *)(param_1 + 1) = iVar1;
    if (*(int *)((long)param_1 + 0x2c) == 0) {
      *(undefined4 *)((long)param_1 + 0x2c) = 1;
      iVar1 = (int)param_1[6];
    }
    else {
      iVar1 = (int)param_1[6];
    }
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 6) = 10;
    }
    param_1[8] = 0;
    param_1[0x12] = 0x1000000400000000;
    param_1[0x13] = 0;
    *(undefined4 *)(param_1 + 7) = 0;
    *(undefined4 *)((long)param_1 + 0x3c) = 0x10000005;
    param_1[0x14] = 0;
    __mutex_init(param_1 + 10,"&ctrl->lock",&slim_register_controller___key);
    __mutex_init(param_1 + 0x1b,"&ctrl->sched.m_reconf",&slim_register_controller___key_2);
    *(undefined4 *)(param_1 + 0x17) = 0;
    __init_swait_queue_head(param_1 + 0x18,"&x->wait",&init_completion___key);
    lVar3 = *param_1;
    *(undefined4 *)(param_1 + 0x15) = 0;
    if ((*(long *)(lVar3 + 0x2e8) != 0) &&
       (lVar2 = of_get_next_child(*(long *)(lVar3 + 0x2e8),0), lVar2 != 0)) {
      do {
        local_70 = 0;
        local_80[0] = 0;
        local_80[1] = 0;
        param0 = (char *)of_get_property(lVar2,"compatible",0);
        if (param0 != (char *)0x0) {
          iVar1 = sscanf(param0,"slim%x,%x",local_80 + 1,local_80);
          if (iVar1 == 2) {
            iVar1 = of_property_read_variable_u32_array(lVar2,&DAT_001032a4,&local_70,2,0);
            if (iVar1 < 0) {
              _dev_err(lVar3,"Device and Instance id not found:%d\n",iVar1);
            }
            else {
              local_77 = (undefined1)local_70;
              local_78 = (undefined1)((ulong)local_70 >> 0x20);
              local_74 = (undefined2)local_80[1];
              local_76 = (undefined2)local_80[0];
              slim_alloc_device(param_1,&local_78,lVar2);
            }
          }
          else {
            _dev_err(lVar3,"Manf ID & Product code not found %s\n",param0);
          }
        }
        lVar2 = of_get_next_child(*(undefined8 *)(*param_1 + 0x2e8),lVar2);
      } while (lVar2 != 0);
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slim_unregister_controller @ 00100ef8 size=76
// signature: undefined slim_unregister_controller(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_unregister_controller(undefined8 *param_1)

{
  device_for_each_child(*param_1,0,slim_ctrl_remove_device);
  ida_free(ctrl_ida,*(undefined4 *)(param_1 + 1));
  return 0;
}



//------------------------------------------------------------
// slim_ctrl_remove_device @ 00100f48 size=32
// signature: undefined slim_ctrl_remove_device(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_ctrl_remove_device(void)

{
  device_unregister();
  return 0;
}



//------------------------------------------------------------
// slim_vote_for_suspend @ 00100f6c size=72
// signature: undefined slim_vote_for_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_vote_for_suspend(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (*(long *)(param_1 + 0x398) == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    pcVar2 = *(code **)(*(long *)(param_1 + 0x398) + 0x138);
    if (*(int *)(pcVar2 + -4) != 0x4a19e930) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100f9c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// slim_report_absent @ 00100fb8 size=160
// signature: undefined slim_report_absent(void)
// callers: []
//------------------------------------------------------------

void slim_report_absent(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x398);
  if (lVar2 != 0) {
    mutex_lock(lVar2 + 0x50);
    *(undefined1 *)(param_1 + 0x3a5) = 0;
    mutex_unlock(lVar2 + 0x50);
    if (*(long *)(lVar2 + 0x118) == 0) {
      ida_free(lVar2 + 0x38,*(undefined1 *)(param_1 + 0x3a4));
    }
    if (*(int *)(param_1 + 0x3a0) != 0) {
      *(undefined4 *)(param_1 + 0x3a0) = 0;
      if ((*(long *)(param_1 + 0x88) != 0) &&
         (pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + -8), pcVar1 != (code *)0x0)) {
        if (*(int *)(pcVar1 + -4) != -0x234737bf) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101040);
          (*pcVar1)();
        }
        (*pcVar1)(param_1,0);
      }
    }
  }
  return;
}



//------------------------------------------------------------
// slim_get_device @ 0010105c size=88
// signature: undefined slim_get_device(void)
// callers: []
//------------------------------------------------------------

long slim_get_device(undefined8 *param_1,undefined8 param_2)

{
  long lVar1;
  long lVar2;
  
  lVar1 = device_find_child(*param_1,param_2,slim_match_dev);
  if (lVar1 == 0) {
    lVar2 = slim_alloc_device(param_1,param_2,0);
    lVar1 = -0xc;
    if (lVar2 != 0) {
      lVar1 = lVar2;
    }
  }
  return lVar1;
}



//------------------------------------------------------------
// slim_alloc_device @ 001010b4 size=260
// signature: undefined slim_alloc_device(void)
// callers: [slim_get_device, slim_register_controller, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long slim_alloc_device(undefined8 *param_1,undefined4 *param_2,long param_3)

{
  long lVar1;
  undefined2 uVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  
  lVar4 = kmalloc_trace(__printk,0xdc0,0x3c0);
  if (lVar4 != 0) {
    uVar2 = *(undefined2 *)(param_2 + 1);
    *(undefined4 *)(lVar4 + 0x390) = *param_2;
    uVar5 = *param_1;
    *(undefined2 *)(lVar4 + 0x394) = uVar2;
    *(undefined8 **)(lVar4 + 0x398) = param_1;
    *(undefined8 *)(lVar4 + 0x60) = uVar5;
    *(undefined ***)(lVar4 + 0x80) = &slimbus_bus;
    *(undefined8 *)(lVar4 + 0x88) = 0;
    *(code **)(lVar4 + 0x328) = slim_dev_release;
    *(long *)(lVar4 + 0x3a8) = lVar4 + 0x3a8;
    *(long *)(lVar4 + 0x3b0) = lVar4 + 0x3a8;
    *(undefined4 *)(lVar4 + 0x3b8) = 0;
    __mutex_init(param_1 + 0x28,"&ctrl->stream_lock",&slim_add_device___key);
    lVar1 = 0;
    if (param_3 != 0) {
      lVar1 = param_3 + 0x18;
    }
    *(long *)(lVar4 + 0x2e8) = param_3;
    *(long *)(lVar4 + 0x2f0) = lVar1;
    dev_set_name(lVar4,"%x:%x:%x:%x%s",*(undefined2 *)(lVar4 + 0x394),*(undefined2 *)(lVar4 + 0x392)
                 ,*(undefined1 *)(lVar4 + 0x391),*(undefined1 *)(lVar4 + 0x390),&DAT_00103198);
    iVar3 = device_register(lVar4);
    if (iVar3 != 0) {
      put_device(lVar4);
      lVar4 = 0;
    }
  }
  return lVar4;
}



//------------------------------------------------------------
// of_slim_get_device @ 001011bc size=40
// signature: undefined of_slim_get_device(void)
// callers: []
//------------------------------------------------------------

void of_slim_get_device(undefined8 *param_1,undefined8 param_2)

{
  device_find_child(*param_1,param_2,of_slim_match_dev);
  return;
}



//------------------------------------------------------------
// slim_device_report_present @ 001011e8 size=344
// signature: undefined slim_device_report_present(void)
// callers: []
//------------------------------------------------------------

int slim_device_report_present(long *param_1,undefined8 param_2,undefined1 *param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  ulong uVar6;
  undefined8 uVar7;
  int iVar8;
  long lVar9;
  
  iVar5 = __pm_runtime_resume(*param_1,4);
  if (-1 < iVar5) {
    if ((int)param_1[0x16] == 0) {
      uVar6 = device_find_child(*param_1,param_2,slim_match_dev);
      if (((uVar6 == 0) && (uVar6 = slim_alloc_device(param_1,param_2,0), uVar6 == 0)) ||
         (0xfffffffffffff000 < uVar6)) {
        return -0x13;
      }
      if (*(char *)(uVar6 + 0x3a5) != '\0') {
        *param_3 = *(undefined1 *)(uVar6 + 0x3a4);
        return 0;
      }
      iVar5 = slim_device_alloc_laddr(uVar6,1);
    }
    else {
      _dev_err(*param_1,"slim ctrl not active,state:%d, ret:%d\n",(int)param_1[0x16],iVar5);
    }
    lVar9 = *param_1;
    uVar7 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar9 + 0x220) = uVar7;
    __pm_runtime_suspend(*param_1,0xd);
    return iVar5;
  }
  _dev_err(*param_1,"slim %s: PM get_sync failed ret :%d\n","slim_device_report_present",iVar5);
  piVar1 = (int *)(*param_1 + 0x1f8);
  iVar8 = *(int *)(*param_1 + 0x1f8);
  do {
    if (iVar8 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar8) goto LAB_001012d0;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar8 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_001012d0:
    bVar4 = iVar8 != iVar2;
    iVar8 = iVar2;
  } while (bVar4);
  __pm_runtime_set_status(*param_1,2);
  return iVar5;
}



//------------------------------------------------------------
// slim_device_alloc_laddr @ 00101354 size=420
// signature: undefined slim_device_alloc_laddr(void)
// callers: [slim_get_logical_addr, slim_device_probe, slim_device_report_present]
//------------------------------------------------------------

int slim_device_alloc_laddr(long param_1,ulong param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  long lVar4;
  undefined1 local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x398);
  local_3c[0] = 0;
  if (lVar4 == 0) {
    _printk(&DAT_00103421,"slim_device_alloc_laddr");
    iVar2 = -0x16;
    goto LAB_001014a8;
  }
  lVar1 = lVar4 + 0x50;
  mutex_lock(lVar1);
  pcVar3 = *(code **)(lVar4 + 0x118);
  if (pcVar3 == (code *)0x0) {
    if ((param_2 & 1) == 0) {
LAB_00101494:
      iVar2 = -0x16;
    }
    else {
      iVar2 = ida_alloc_range(lVar4 + 0x38,0,0xfe,0xcc0);
      if (-1 < iVar2) {
        local_3c[0] = (undefined1)iVar2;
        pcVar3 = *(code **)(lVar4 + 0x110);
        goto joined_r0x0010142c;
      }
    }
  }
  else {
    if (*(int *)(pcVar3 + -4) != -0x134626e2) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1013c4);
      (*pcVar3)();
    }
    iVar2 = (*pcVar3)(lVar4,param_1 + 0x390,local_3c);
    if (-1 < iVar2) {
      pcVar3 = *(code **)(lVar4 + 0x110);
joined_r0x0010142c:
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x2b52a01d) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1013f8);
          (*pcVar3)();
        }
        iVar2 = (*pcVar3)(lVar4,param_1 + 0x390,local_3c[0]);
        if (iVar2 != 0) goto LAB_00101494;
      }
      *(undefined1 *)(param_1 + 0x3a4) = local_3c[0];
      *(undefined1 *)(param_1 + 0x3a5) = 1;
      mutex_unlock(lVar1);
      if (*(int *)(param_1 + 0x3a0) != 1) {
        *(undefined4 *)(param_1 + 0x3a0) = 1;
        if ((*(long *)(param_1 + 0x88) != 0) &&
           (pcVar3 = *(code **)(*(long *)(param_1 + 0x88) + -8), pcVar3 != (code *)0x0)) {
          if (*(int *)(pcVar3 + -4) != -0x234737bf) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101488);
            (*pcVar3)();
          }
          (*pcVar3)(param_1,1);
        }
      }
      iVar2 = 0;
      goto LAB_001014a8;
    }
  }
  mutex_unlock(lVar1);
LAB_001014a8:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// slim_get_logical_addr @ 001014fc size=48
// signature: undefined slim_get_logical_addr(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_get_logical_addr(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(param_1 + 0x3a5) == '\0') {
    uVar1 = slim_device_alloc_laddr(param_1,0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// slim_match_dev @ 00101530 size=76
// signature: undefined slim_match_dev(void)
// callers: []
//------------------------------------------------------------

bool slim_match_dev(long param_1,char *param_2)

{
  if (((*(short *)(param_1 + 0x394) == *(short *)(param_2 + 4)) &&
      (*(short *)(param_1 + 0x392) == *(short *)(param_2 + 2))) &&
     (*(char *)(param_1 + 0x391) == param_2[1])) {
    return *(char *)(param_1 + 0x390) == *param_2;
  }
  return false;
}



//------------------------------------------------------------
// slim_dev_release @ 00101580 size=28
// signature: undefined slim_dev_release(void)
// callers: []
//------------------------------------------------------------

void slim_dev_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// of_slim_match_dev @ 001015a0 size=16
// signature: undefined of_slim_match_dev(void)
// callers: []
//------------------------------------------------------------

bool of_slim_match_dev(long param_1,long param_2)

{
  return *(long *)(param_1 + 0x2e8) == param_2;
}



//------------------------------------------------------------
// slim_msg_response @ 001015b4 size=256
// signature: undefined slim_msg_response(void)
// callers: []
//------------------------------------------------------------

void slim_msg_response(long *param_1,undefined8 param_2,undefined1 param_3,undefined1 param_4)

{
  long *plVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  
  plVar1 = param_1 + 0x15;
  uVar2 = _raw_spin_lock_irqsave(plVar1);
  lVar3 = idr_find(param_1 + 0x12,param_3);
  _raw_spin_unlock_irqrestore(plVar1,uVar2);
  if (lVar3 != 0) {
    lVar4 = *(long *)(lVar3 + 8);
    if ((lVar4 == 0) || (*(long *)(lVar4 + 8) == 0)) {
      _dev_err(*param_1,"Got response to invalid TID:%d, len:%d\n",param_3,param_4);
    }
    else {
      uVar2 = _raw_spin_lock_irqsave(plVar1);
      idr_remove(param_1 + 0x12,*(undefined1 *)(lVar3 + 6));
      _raw_spin_unlock_irqrestore(plVar1,uVar2);
      __memcpy_fromio(*(undefined8 *)(lVar4 + 8),param_2,param_4);
      if (*(long *)(lVar3 + 0x10) != 0) {
        complete();
      }
      lVar3 = *param_1;
      uVar2 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar3 + 0x220) = uVar2;
      __pm_runtime_suspend(*param_1,0xd);
    }
  }
  return;
}



//------------------------------------------------------------
// slim_free_txn_tid @ 001016b8 size=88
// signature: undefined slim_free_txn_tid(void)
// callers: [slim_do_transfer]
//------------------------------------------------------------

void slim_free_txn_tid(long param_1,long param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0xa8);
  idr_remove(param_1 + 0x90,*(undefined1 *)(param_2 + 6));
  _raw_spin_unlock_irqrestore(param_1 + 0xa8,uVar1);
  return;
}



//------------------------------------------------------------
// slim_alloc_txn_tid @ 00101714 size=160
// signature: undefined slim_alloc_txn_tid(void)
// callers: []
//------------------------------------------------------------

int slim_alloc_txn_tid(undefined8 *param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = _raw_spin_lock_irqsave(param_1 + 0x15);
  iVar1 = idr_alloc_cyclic(param_1 + 0x12,param_2,1,0x100,0xa20);
  if (iVar1 < 0) {
    _dev_err(*param_1,"%s: idr_alloc_cyclic ret %d\n","slim_alloc_txn_tid",iVar1);
  }
  else {
    *(char *)(param_2 + 6) = (char)iVar1;
    iVar1 = 0;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x15,uVar2);
  return iVar1;
}



//------------------------------------------------------------
// slim_do_transfer @ 001017b8 size=936
// signature: undefined slim_do_transfer(void)
// callers: [slim_stream_prepare, slim_stream_unprepare, slim_xfer_msg, slim_stream_disable, slim_stream_unprepare_disconnect_port, slim_stream_enable, slim_ctrl_clk_pause]
//------------------------------------------------------------

int slim_do_transfer(long *param_1,byte *param_2)

{
  long *plVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  char cVar5;
  byte bVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  undefined8 uVar10;
  int iVar11;
  long lVar12;
  undefined8 uVar13;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 *****local_68;
  undefined8 *****pppppuStack_60;
  long local_58;
  
  lVar12 = sp_el0;
  local_58 = *(long *)(lVar12 + 0x638);
  bVar8 = false;
  local_68 = &local_68;
  bVar3 = param_2[1];
  local_78 = 0;
  uStack_70 = 0;
  if (((int)param_1[0x16] == 1) && (bVar3 == 0)) {
    bVar8 = (param_2[2] & 0xe0) == 0x40;
  }
  param_2[6] = 0;
  bVar6 = param_2[2] - 0x20;
  pppppuStack_60 = local_68;
  if ((bVar6 & 0xbe) == 0 && bVar3 == 0) {
    plVar1 = param_1 + 0x15;
    uVar10 = _raw_spin_lock_irqsave(plVar1);
    iVar9 = idr_alloc_cyclic(param_1 + 0x12,param_2,1,0x100,0xa20);
    if (iVar9 < 0) {
      _dev_err(*param_1,"%s: idr_alloc_cyclic ret %d\n","slim_alloc_txn_tid",iVar9);
      _raw_spin_unlock_irqrestore(plVar1,uVar10);
      _dev_err(*param_1,"%s: slim_alloc_txn_tid ret %d\n","slim_do_transfer",iVar9);
      goto LAB_00101944;
    }
    param_2[6] = (byte)iVar9;
    _raw_spin_unlock_irqrestore(plVar1,uVar10);
    if (*(long *)(*(long *)(param_2 + 8) + 0x18) != 0) goto LAB_00101890;
    uVar10 = *(undefined8 *)(param_2 + 0x10);
    *(undefined8 **)(param_2 + 0x10) = &local_78;
    if (!bVar8) goto LAB_00101898;
LAB_001018b4:
    if (*(int *)((code *)param_1[0x21] + -4) != -0x7eda055d) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1018d8);
      (*pcVar7)();
    }
    iVar9 = (*(code *)param_1[0x21])(param_1,param_2);
    if (iVar9 == 0) {
      if (((bVar6 & 0xbe) == 0 && bVar3 == 0) && (*(long *)(*(long *)(param_2 + 8) + 0x18) == 0)) {
        uVar13 = *(undefined8 *)(param_2 + 0x10);
        uVar10 = __msecs_to_jiffies(*param_2 + 0xfa);
        iVar9 = wait_for_completion_timeout(uVar13,uVar10);
        if (iVar9 == 0) {
          iVar9 = -0x6e;
          _dev_err(*param_1,"%s: Timed out %d\n","slim_do_transfer",0xffffff92);
          param_2[0x10] = 0;
          param_2[0x11] = 0;
          param_2[0x12] = 0;
          param_2[0x13] = 0;
          param_2[0x14] = 0;
          param_2[0x15] = 0;
          param_2[0x16] = 0;
          param_2[0x17] = 0;
          slim_free_txn_tid(param_1,param_2);
          goto LAB_001019c8;
        }
      }
      iVar9 = 0;
    }
    else {
      if (iVar9 == -0x6e) {
        uVar10 = _raw_spin_lock_irqsave(param_1 + 0x15);
        idr_remove(param_1 + 0x12,param_2[6]);
        _raw_spin_unlock_irqrestore(param_1 + 0x15,uVar10);
        iVar9 = -0x6e;
      }
LAB_001019c8:
      _dev_err(*param_1,"Tx:MT:0x%x, MC:0x%x, LA:0x%x failed:%d\n",param_2[1],param_2[2],param_2[7],
               iVar9);
    }
    if (bVar8) goto LAB_00101944;
  }
  else {
LAB_00101890:
    uVar10 = 0;
    if (bVar8) goto LAB_001018b4;
LAB_00101898:
    iVar9 = __pm_runtime_resume(*param_1,4);
    if (iVar9 < 0) {
      _dev_err(*param_1,"%s: pm_runtime_get_sync failed: %d\n","slim_do_transfer",iVar9);
      uVar13 = _raw_spin_lock_irqsave(param_1 + 0x15);
      idr_remove(param_1 + 0x12,param_2[6]);
      _raw_spin_unlock_irqrestore(param_1 + 0x15,uVar13);
      piVar2 = (int *)(*param_1 + 0x1f8);
      iVar11 = *(int *)(*param_1 + 0x1f8);
      do {
        if (iVar11 == 0) break;
        Hint_Prefetch(piVar2,2,0,1);
        do {
          iVar4 = *piVar2;
          if (iVar4 != iVar11) goto LAB_00101a60;
          cVar5 = '\x01';
          bVar8 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar8) {
            *piVar2 = iVar11 + -1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        DataMemoryBarrier(2,3);
LAB_00101a60:
        bVar8 = iVar11 != iVar4;
        iVar11 = iVar4;
      } while (bVar8);
      __pm_runtime_set_status(*param_1,2);
      if (((bVar6 & 0xbe) == 0 && bVar3 == 0) && (*(long *)(*(long *)(param_2 + 8) + 0x18) == 0)) {
        *(undefined8 *)(param_2 + 0x10) = uVar10;
      }
      goto LAB_00101944;
    }
    if ((int)param_1[0x16] == 0) goto LAB_001018b4;
    _dev_err(*param_1,"%s: ctrl wrong state:%d, ret:%d\n","slim_do_transfer",(int)param_1[0x16],
             iVar9);
    if (((bVar6 & 0xbe) == 0 && bVar3 == 0) && (*(long *)(*(long *)(param_2 + 8) + 0x18) == 0)) {
      *(undefined8 *)(param_2 + 0x10) = uVar10;
    }
  }
  if ((param_2[6] == 0) || (iVar9 == -0x6e)) {
    lVar12 = *param_1;
    uVar10 = ktime_get_mono_fast_ns();
    *(undefined8 *)(lVar12 + 0x220) = uVar10;
    __pm_runtime_suspend(*param_1,0xd);
  }
LAB_00101944:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// slim_xfer_msg @ 00101b78 size=432
// signature: undefined slim_xfer_msg(void)
// callers: [slim_read, slim_writeb, slim_write, slim_readb]
//------------------------------------------------------------

undefined4 slim_xfer_msg(long param_1,ushort *param_2,byte param_3)

{
  ulong uVar1;
  uint uVar2;
  byte bVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  byte bVar7;
  ushort uVar8;
  uint uVar9;
  long lVar10;
  ushort local_30;
  byte local_2e;
  undefined1 local_2d;
  ushort local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  ushort *local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar10 = sp_el0;
  local_18 = *(long *)(lVar10 + 0x638);
  local_29 = *(undefined1 *)(param_1 + 0x3a4);
  local_30 = 6;
  local_2d = 0;
  uVar5 = 0xffffffea;
  local_2a = 0;
  uStack_20 = 0;
  local_2e = param_3;
  local_28 = param_2;
  if ((param_2 == (ushort *)0x0) ||
     (puVar6 = *(undefined8 **)(param_1 + 0x398), puVar6 == (undefined8 *)0x0)) goto LAB_00101cd4;
  bVar3 = (byte)param_2[1];
  if (bVar3 < 0x11) {
    uVar8 = *param_2;
    if ((uint)uVar8 + (uint)bVar3 < 0xc01) {
      if (param_3 < 0x60) {
        if (param_3 == 0x20) {
LAB_00101c20:
          lVar10 = *(long *)(param_2 + 4);
joined_r0x00101c24:
          if (lVar10 != 0) {
            uVar9 = (uint)bVar3;
            uVar2 = uVar9;
            if (uVar9 < 2) {
              uVar2 = 1;
            }
            uVar1 = 0xf;
            if (uVar9 < 0x10) {
              uVar1 = (ulong)(uVar2 - 1);
            }
            if (0xf < uVar1) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(1,0x101d28);
              (*pcVar4)();
            }
            local_2c = (ushort)(byte)(&slim_slicesize_sizetocode)[uVar1] | uVar8 << 4 | 8;
            bVar7 = 7;
            if (param_3 < 0x61) {
              if ((param_3 == 0x21) || (param_3 == 0x28)) {
LAB_00101ca8:
                bVar7 = bVar3 + 7;
                local_30 = (ushort)(byte)(bVar3 + 6);
              }
            }
            else if ((param_3 == 0x68) || (param_3 == 0x61)) goto LAB_00101ca8;
            if ((param_3 - 0x20 & 0xbe) == 0) {
              local_30 = (ushort)bVar7;
            }
            uVar5 = slim_do_transfer(puVar6,&local_30);
            goto LAB_00101cd4;
          }
        }
        else if (param_3 == 0x21) {
LAB_00101c2c:
          if (*(long *)(param_2 + 4) != 0) goto LAB_00101c34;
        }
        else if (param_3 == 0x28) goto LAB_00101c34;
      }
      else {
        if (param_3 == 0x68) {
LAB_00101c34:
          lVar10 = *(long *)(param_2 + 8);
          goto joined_r0x00101c24;
        }
        if (param_3 == 0x61) goto LAB_00101c2c;
        if (param_3 == 0x60) goto LAB_00101c20;
      }
    }
  }
  else {
    uVar8 = *param_2;
  }
  _dev_err(*puVar6,"Sanity check failed:msg:offset:0x%x, mc:%d\n",uVar8,param_3);
  uVar5 = 0xffffffea;
LAB_00101cd4:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// slim_read @ 00101d2c size=96
// signature: undefined slim_read(void)
// callers: []
//------------------------------------------------------------

void slim_read(undefined8 param_1,undefined2 param_2,undefined1 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_38 = (ulong)CONCAT12(param_3,param_2);
  local_28 = 0;
  uStack_20 = 0;
  uStack_30 = param_4;
  slim_xfer_msg(param_1,&local_38,0x60);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slim_readb @ 00101d90 size=116
// signature: undefined slim_readb(void)
// callers: []
//------------------------------------------------------------

void slim_readb(undefined8 param_1,undefined2 param_2)

{
  long lVar1;
  uint uVar2;
  byte local_3c [4];
  undefined2 local_38;
  undefined6 uStack_36;
  byte *pbStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  pbStack_30 = local_3c;
  local_3c[0] = 0;
  local_28 = 0;
  uStack_20 = 0;
  _local_38 = CONCAT62(1,param_2);
  uVar2 = slim_xfer_msg(param_1,&local_38,0x60);
  lVar1 = sp_el0;
  if (-1 < (int)uVar2) {
    uVar2 = (uint)local_3c[0];
  }
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// slim_write @ 00101e08 size=96
// signature: undefined slim_write(void)
// callers: []
//------------------------------------------------------------

void slim_write(undefined8 param_1,undefined2 param_2,undefined1 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uStack_30 = 0;
  local_38 = (ulong)CONCAT12(param_3,param_2);
  uStack_20 = 0;
  local_28 = param_4;
  slim_xfer_msg(param_1,&local_38,0x68);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slim_writeb @ 00101e6c size=104
// signature: undefined slim_writeb(void)
// callers: []
//------------------------------------------------------------

void slim_writeb(undefined8 param_1,undefined2 param_2,undefined1 param_3)

{
  long lVar1;
  undefined1 local_3c [4];
  undefined2 local_38;
  undefined6 uStack_36;
  undefined8 uStack_30;
  undefined1 *local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_28 = local_3c;
  uStack_30 = 0;
  _local_38 = CONCAT62(1,param_2);
  uStack_20 = 0;
  local_3c[0] = param_3;
  slim_xfer_msg(param_1,&local_38,0x68);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// slim_ctrl_clk_pause @ 00101ed8 size=568
// signature: undefined slim_ctrl_clk_pause(void)
// callers: []
//------------------------------------------------------------

int slim_ctrl_clk_pause(long param_1,ulong param_2,byte param_3)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  long lVar7;
  undefined8 local_88;
  undefined8 *puStack_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 uStack_68;
  byte *local_60;
  undefined8 uStack_58;
  byte local_4c [4];
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  puStack_80 = &local_70;
  local_60 = (byte *)0x0;
  uStack_58 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_88 = 0xff00000003400003;
  local_78 = 0;
  local_4c[0] = param_3;
  if ((2 < param_3) && ((param_2 & 1) == 0)) {
    iVar3 = -0x16;
    goto LAB_001020a8;
  }
  lVar1 = param_1 + 0xd8;
  mutex_lock(lVar1);
  if ((param_2 & 1) == 0) {
    if (*(int *)(param_1 + 0xb0) == 2) goto LAB_00101fb4;
    lVar2 = param_1 + 0xa8;
    uVar4 = _raw_spin_lock_irqsave(lVar2);
    lVar7 = 0;
    do {
      lVar5 = idr_find(param_1 + 0x90,lVar7);
      if (lVar5 != 0) {
        _raw_spin_unlock_irqrestore(lVar2,uVar4);
        mutex_unlock(lVar1);
        iVar3 = -0x10;
        goto LAB_001020a8;
      }
      lVar7 = lVar7 + 1;
    } while (lVar7 != 0x100);
    _raw_spin_unlock_irqrestore(lVar2,uVar4);
    *(undefined4 *)(param_1 + 0xb0) = 1;
    iVar3 = slim_do_transfer(param_1,&local_88);
    if (iVar3 == 0) {
      local_60 = local_4c;
      local_70._0_3_ = CONCAT12(1,(undefined2)local_70);
      local_88._0_3_ = CONCAT12(0x4a,(undefined2)local_88);
      local_88 = CONCAT71(local_88._1_7_,4);
      iVar3 = slim_do_transfer(param_1,&local_88);
      if (iVar3 == 0) {
        local_60 = (byte *)0x0;
        local_88._0_3_ = CONCAT12(0x5f,(undefined2)local_88);
        local_88 = CONCAT71(local_88._1_7_,3);
        local_70._0_3_ = CONCAT12(1,(undefined2)local_70);
        iVar3 = slim_do_transfer(param_1,&local_88);
        if (iVar3 == 0) {
          *(undefined4 *)(param_1 + 0xb0) = 2;
          complete(param_1 + 0xb8);
          goto LAB_00102084;
        }
      }
    }
LAB_00102080:
    *(undefined4 *)(param_1 + 0xb0) = 0;
  }
  else {
    if (*(int *)(param_1 + 0xb0) == 0) {
LAB_00101fb4:
      mutex_unlock(lVar1);
      iVar3 = 0;
      goto LAB_001020a8;
    }
    iVar3 = wait_for_completion_timeout(param_1 + 0xb8,0x19);
    if (iVar3 == 0) {
      mutex_unlock(lVar1);
      _printk(&DAT_0010357f);
      iVar3 = -0x6e;
      goto LAB_001020a8;
    }
    if ((*(int *)(param_1 + 0xb0) != 2) ||
       (pcVar6 = *(code **)(param_1 + 0x130), pcVar6 == (code *)0x0)) {
LAB_00101fa4:
      iVar3 = 0;
      goto LAB_00102080;
    }
    if (*(int *)(pcVar6 + -4) != 0x4a19e930) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101f98);
      (*pcVar6)();
    }
    iVar3 = (*pcVar6)(param_1);
    if (iVar3 == 0) goto LAB_00101fa4;
  }
LAB_00102084:
  mutex_unlock(lVar1);
LAB_001020a8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// slim_stream_allocate @ 00102114 size=200
// signature: undefined slim_stream_allocate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * slim_stream_allocate(long param_1,undefined8 param_2)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  long *plVar5;
  
  plVar2 = (long *)kmalloc_trace(_alt_cb_patch_nops,0xdc0,0x40);
  if (plVar2 != (long *)0x0) {
    lVar3 = kasprintf(0xcc0,"slim-%s",param_2);
    *plVar2 = lVar3;
    if (lVar3 != 0) {
      plVar2[1] = param_1;
      _raw_spin_lock(param_1 + 0x3b8);
      plVar5 = *(long **)(param_1 + 0x3b0);
      plVar1 = plVar2 + 6;
      uVar4 = __list_add_valid(plVar1,plVar5,param_1 + 0x3a8);
      if ((uVar4 & 1) != 0) {
        *(long **)(param_1 + 0x3b0) = plVar1;
        plVar2[6] = param_1 + 0x3a8;
        plVar2[7] = (long)plVar5;
        *plVar5 = (long)plVar1;
      }
      _raw_spin_unlock(param_1 + 0x3b8);
      return plVar2;
    }
    kfree(plVar2);
  }
  return (long *)0xfffffffffffffff4;
}



//------------------------------------------------------------
// slim_stream_prepare @ 001021e0 size=844
// signature: undefined slim_stream_prepare(void)
// callers: []
//------------------------------------------------------------

void slim_stream_prepare(long param_1,uint *param_2)

{
  ulong uVar1;
  uint uVar2;
  undefined1 auVar3 [16];
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  ulong uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint uVar15;
  long lVar16;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined8 *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 *local_80;
  undefined8 uStack_78;
  undefined1 local_6c;
  undefined1 uStack_6b;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  if ((param_1 == 0) || (param_2 == (uint *)0x0)) {
    _printk(&DAT_00103249,"slim_stream_prepare");
    uVar7 = 0xffffffea;
  }
  else if (*(long *)(param_1 + 0x28) == 0) {
    lVar16 = *(long *)(*(long *)(param_1 + 8) + 0x398);
    iVar5 = __sw_hweight32(param_2[6]);
    auVar3._8_8_ = 0;
    auVar3._0_8_ = (long)iVar5;
    if (SUB168(auVar3 * ZEXT816(0x24),8) == 0) {
      lVar6 = __kmalloc(((long)iVar5 + (long)iVar5 * 8) * 4,0xdc0);
      *(long *)(param_1 + 0x28) = lVar6;
      if (lVar6 == 0) {
        uVar7 = 0xfffffff4;
      }
      else {
        *(int *)(param_1 + 0x24) = iVar5;
        *(uint *)(param_1 + 0x18) = *param_2;
        *(uint *)(param_1 + 0x1c) = param_2[1];
        *(uint *)(param_1 + 0x10) = param_2[8];
        uVar2 = *(uint *)(*(long *)(lVar16 + 0x48) + 0x39c);
        uVar12 = 0;
        if (uVar2 != 0) {
          uVar12 = *param_2 / uVar2;
        }
        if (*param_2 == uVar12 * uVar2) {
          *(undefined4 *)(param_1 + 0x14) = 0;
        }
        else {
          if (param_2[8] == 0) {
            uVar8 = 2;
          }
          else {
            uVar8 = 3;
          }
          *(undefined4 *)(param_1 + 0x14) = uVar8;
        }
        uVar9 = 0;
        iVar5 = 0;
        uVar2 = *(uint *)(*(long *)(lVar16 + 0x48) + 0x39c);
        uVar12 = 0;
        if (uVar2 != 0) {
          uVar12 = *param_2 / uVar2;
        }
        *(uint *)(param_1 + 0x20) = uVar12;
        do {
          uVar2 = (uint)(-1L << (uVar9 & 0x3f)) & param_2[6];
          uVar9 = ((ulong)uVar2 & 0xaaaaaaaaaaaaaaaa) >> 1 |
                  ((ulong)uVar2 & 0x5555555555555555) << 1;
          uVar9 = (uVar9 & 0xcccccccccccccccc) >> 2 | (uVar9 & 0x3333333333333333) << 2;
          uVar9 = (uVar9 & 0xf0f0f0f0f0f0f0f0) >> 4 | (uVar9 & 0xf0f0f0f0f0f0f0f) << 4;
          uVar9 = (uVar9 & 0xff00ff00ff00ff00) >> 8 | (uVar9 & 0xff00ff00ff00ff) << 8;
          uVar1 = 0x20;
          if (uVar2 != 0) {
            uVar1 = LZCOUNT((uVar9 >> 0x10 | (uVar9 & 0xffff0000ffff) << 0x10) << 0x20);
          }
          if (0x1f < (uint)uVar1) break;
          lVar16 = *(long *)(param_1 + 0x28);
          puVar10 = (uint *)(lVar16 + (long)iVar5 * 0x24);
          *puVar10 = (uint)uVar1;
          puVar10[2] = 0;
          uVar2 = *param_2;
          if ((uVar2 == 0x15888) || (uVar2 == 0xac44)) {
            uVar9 = (ulong)uVar2 / 0x2b11;
          }
          else {
            uVar9 = (ulong)(uint)((int)uVar2 / 4000);
          }
          iVar11 = 0;
          bVar4 = true;
          do {
            bVar14 = bVar4;
            uVar12 = (uint)uVar9;
            if ((uVar9 & 1) == 0) {
              do {
                uVar13 = (uint)uVar9;
                uVar12 = (int)uVar13 >> 1;
                uVar9 = (ulong)uVar12;
                iVar11 = iVar11 + 1;
              } while ((uVar13 >> 1 & 1) == 0);
            }
            uVar13 = uVar12;
            if (3 < (int)uVar12) {
              uVar13 = uVar12 + 1;
            }
            uVar9 = (ulong)uVar13;
            bVar4 = false;
          } while (3 < (int)uVar12);
          uVar12 = 8;
          uVar15 = 1;
          if ((uVar2 != 0xac44) && (uVar2 != 0x15888)) {
            uVar15 = (uint)(uVar13 != 1);
            uVar12 = (uint)(uVar13 == 1) << 4;
          }
          uVar12 = uVar15 + iVar11 | uVar12;
          lVar16 = lVar16 + (long)iVar5 * 0x24;
          uVar2 = uVar12 | 0x80;
          if (!bVar14) {
            uVar2 = uVar12;
          }
          if (7 < (int)(uVar15 + iVar11)) {
            uVar2 = 0;
          }
          local_80 = &local_6c;
          *(uint *)(lVar16 + 0x10) = uVar2;
          *(undefined4 *)(lVar16 + 0xc) = *(undefined4 *)(*(long *)(param_2 + 4) + (long)iVar5 * 4);
          *(undefined8 *)(lVar16 + 0x18) = 0;
          *(undefined4 *)(lVar16 + 0x20) = 1;
          *(uint *)(lVar16 + 4) = (uint)(param_2[8] != 0);
          uStack_78 = 0;
          local_90 = 0x20000;
          uStack_88 = 0;
          lVar6 = *(long *)(param_1 + 8);
          local_a4 = 0;
          local_a8 = 0x100006;
          local_a1 = *(undefined1 *)(lVar6 + 0x3a4);
          local_a2 = 0;
          uStack_98 = 0;
          if (*(int *)(lVar16 + 4) == 0) {
            local_a8 = 0x110006;
          }
          _local_6c = CONCAT11((char)*(undefined4 *)(lVar16 + 0xc),(char)*puVar10);
          *(undefined4 *)(lVar16 + 0x20) = 2;
          puVar10[2] = 1;
          local_a0 = &local_90;
          slim_do_transfer(*(undefined8 *)(lVar6 + 0x398),&local_a8);
          iVar5 = iVar5 + 1;
          uVar9 = uVar1 + 1;
        } while (uVar1 < 0x1f);
        uVar7 = 0;
      }
    }
    else {
      uVar7 = 0xfffffff4;
      *(undefined8 *)(param_1 + 0x28) = 0;
    }
  }
  else {
    _dev_err(*(long *)(param_1 + 8),"Stream already Prepared\n");
    uVar7 = 0xffffffea;
  }
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// slim_stream_enable @ 00102530 size=1128
// signature: undefined slim_stream_enable(void)
// callers: []
//------------------------------------------------------------

int slim_stream_enable(long param_1)

{
  undefined8 *puVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  char *pcVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  undefined4 uVar12;
  long lVar13;
  undefined8 *puVar14;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined8 *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined4 *local_80;
  undefined8 uStack_78;
  undefined4 local_6c;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  local_c0 = DAT_00103838;
  uStack_b8 = DAT_00103840;
  local_b0 = DAT_00103848;
  if (param_1 == 0) {
    _printk(&DAT_001033db,"slim_stream_enable");
    iVar6 = -0x16;
  }
  else {
    puVar14 = *(undefined8 **)(*(long *)(param_1 + 8) + 0x398);
    if (puVar14[0x24] == 0) {
      iVar6 = slim_do_transfer(puVar14,&local_c0);
      if (iVar6 == 0) {
        if (0 < *(int *)(param_1 + 0x24)) {
          lVar11 = 0;
          lVar9 = 0;
          do {
            lVar10 = *(long *)(param_1 + 8);
            iVar6 = *(int *)(param_1 + 0x20);
            local_a1 = *(undefined1 *)(lVar10 + 0x3a4);
            local_90 = 0x40000;
            uStack_88 = 0;
            local_a8 = 0x500008;
            uStack_78 = 0;
            uVar12 = 0xffffffea;
            local_a4 = 0;
            local_a2 = 0;
            uStack_98 = 0;
            if (0xbf < iVar6) {
              if (iVar6 < 0x16c) {
                if (iVar6 == 0xc0) {
                  lVar13 = 0x10;
                }
                else {
                  if (iVar6 != 0x100) goto switchD_001026f4_caseD_5;
                  lVar13 = 8;
                }
              }
              else if (iVar6 == 0x16c) {
                lVar13 = 0x11;
              }
              else if (iVar6 == 0x200) {
                lVar13 = 9;
              }
              else {
                if (iVar6 != 0x300) goto switchD_001026f4_caseD_5;
                lVar13 = 0x12;
              }
              goto switchD_001026f4_caseD_1;
            }
            lVar13 = 0;
            switch(iVar6) {
            case 1:
              break;
            case 2:
              lVar13 = 1;
              break;
            case 3:
              lVar13 = 10;
              break;
            case 4:
              lVar13 = 2;
              break;
            default:
              goto switchD_001026f4_caseD_5;
            case 6:
              lVar13 = 0xb;
              break;
            case 8:
              lVar13 = 3;
              break;
            case 0xc:
              lVar13 = 0xc;
              break;
            case 0x10:
              lVar13 = 4;
              break;
            case 0x18:
              lVar13 = 0xd;
              break;
            case 0x20:
              lVar13 = 5;
              break;
            case 0x30:
              lVar13 = 0xe;
              break;
            case 0x40:
              lVar13 = 6;
              break;
            case 0x60:
              lVar13 = 0xf;
              break;
            case 0x80:
              lVar13 = 7;
            }
switchD_001026f4_caseD_1:
            uVar12 = *(undefined4 *)(segdist_codes + lVar13 * 0x10 + 8);
switchD_001026f4_caseD_5:
            lVar13 = *(long *)(param_1 + 0x28) + lVar11;
            *(undefined4 *)(lVar13 + 0x14) = uVar12;
            cVar2 = (char)(*(uint *)(param_1 + 0x1c) >> 2);
            if (*(int *)(param_1 + 0x14) != 0) {
              cVar2 = cVar2 + '\x01';
            }
            local_6c = CONCAT13(cVar2,CONCAT12((byte)((uint)uVar12 >> 8) & 0xf |
                                               (byte)(*(int *)(param_1 + 0x14) << 4),
                                               (short)CONCAT31((int3)uVar12,
                                                               (char)*(undefined4 *)(lVar13 + 0xc)))
                               );
            *(undefined4 *)(lVar13 + 0x20) = 3;
            local_a0 = &local_90;
            local_80 = &local_6c;
            slim_do_transfer(*(undefined8 *)(lVar10 + 0x398),&local_a8);
            lVar10 = *(long *)(param_1 + 8);
            local_90 = 0x40000;
            uStack_88 = 0;
            uStack_78 = 0;
            local_a1 = *(undefined1 *)(lVar10 + 0x3a4);
            local_a8 = 0x510008;
            local_a4 = 0;
            local_a2 = 0;
            uStack_98 = 0;
            uVar4 = (undefined1)*(undefined4 *)(lVar13 + 0xc);
            uVar3 = (undefined1)*(undefined4 *)(lVar13 + 0x10);
            local_6c._0_2_ = CONCAT11(uVar3,uVar4);
            if (*(int *)(param_1 + 0x14) != 0) {
              local_6c._0_2_ = CONCAT11(uVar3,uVar4) | 0x8000;
            }
            local_6c = CONCAT13((char)(*(uint *)(param_1 + 0x1c) >> 2),
                                CONCAT12((byte)*(undefined4 *)(lVar13 + 0x18) |
                                         (byte)(*(int *)(lVar13 + 0x1c) << 4),(ushort)local_6c));
            *(undefined4 *)(lVar13 + 0x20) = 4;
            local_a0 = &local_90;
            local_80 = &local_6c;
            slim_do_transfer(*(undefined8 *)(lVar10 + 0x398),&local_a8);
            lVar9 = lVar9 + 1;
            lVar11 = lVar11 + 0x24;
          } while (lVar9 < *(int *)(param_1 + 0x24));
          if (0 < *(int *)(param_1 + 0x24)) {
            lVar11 = 0;
            lVar9 = 0;
            do {
              lVar13 = *(long *)(param_1 + 8);
              uStack_88 = 0;
              local_a8 = 0x540005;
              local_a4 = 0;
              local_a1 = *(undefined1 *)(lVar13 + 0x3a4);
              local_a2 = 0;
              lVar10 = *(long *)(param_1 + 0x28) + lVar11;
              uStack_98 = 0;
              local_90 = 0x10000;
              uStack_78 = 0;
              local_6c = CONCAT31(local_6c._1_3_,(char)*(undefined4 *)(lVar10 + 0xc));
              *(undefined4 *)(lVar10 + 0x20) = 5;
              local_a0 = &local_90;
              local_80 = &local_6c;
              slim_do_transfer(*(undefined8 *)(lVar13 + 0x398),&local_a8);
              *(undefined4 *)(lVar10 + 8) = 2;
              lVar9 = lVar9 + 1;
              lVar11 = lVar11 + 0x24;
            } while (lVar9 < *(int *)(param_1 + 0x24));
          }
        }
        local_c0._0_3_ = CONCAT12(0x5f,(undefined2)local_c0);
        iVar6 = slim_do_transfer(puVar14,&local_c0);
        goto LAB_001028fc;
      }
      uVar7 = *puVar14;
      pcVar8 = "%s: slim_do_transfer failed %d\n";
    }
    else {
      puVar1 = puVar14 + 0x28;
      mutex_lock(puVar1);
      if (*(int *)((code *)puVar14[0x24] + -4) != 0x1d68acfb) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1025bc);
        (*pcVar5)();
      }
      iVar6 = (*(code *)puVar14[0x24])(param_1);
      if (iVar6 == 0) {
        if (0 < *(int *)(param_1 + 0x24)) {
          lVar9 = 0;
          lVar11 = 0x20;
          do {
            lVar9 = lVar9 + 1;
            *(undefined4 *)(*(long *)(param_1 + 0x28) + lVar11) = 5;
            lVar11 = lVar11 + 0x24;
          } while (lVar9 < *(int *)(param_1 + 0x24));
        }
        mutex_unlock(puVar1);
        iVar6 = 0;
        goto LAB_001028fc;
      }
      mutex_unlock(puVar1);
      uVar7 = *puVar14;
      pcVar8 = "%s: ctrl->enable_stream ret %d\n";
    }
    _dev_err(uVar7,pcVar8,"slim_stream_enable",iVar6);
  }
LAB_001028fc:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// slim_stream_disable @ 0010299c size=580
// signature: undefined slim_stream_disable(void)
// callers: []
//------------------------------------------------------------

int slim_stream_disable(long param_1)

{
  undefined8 *puVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined2 local_a4;
  undefined1 local_a2;
  undefined1 local_a1;
  undefined8 *local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined1 *local_80;
  undefined8 uStack_78;
  undefined1 local_6c [4];
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_c0 = DAT_00103838;
  uStack_b8 = DAT_00103840;
  local_b0 = DAT_00103848;
  if (param_1 == 0) {
    _printk(&DAT_001033db,"slim_stream_disable");
    iVar4 = -0x16;
  }
  else if ((*(long *)(param_1 + 0x28) == 0) || (*(int *)(param_1 + 0x24) == 0)) {
    _printk(&DAT_0010330a,"slim_stream_disable");
    iVar4 = -0x16;
  }
  else {
    puVar5 = *(undefined8 **)(*(long *)(param_1 + 8) + 0x398);
    if (puVar5[0x25] != 0) {
      puVar1 = puVar5 + 0x28;
      mutex_lock(puVar1);
      if (*(int *)((code *)puVar5[0x25] + -4) != 0x1d68acfb) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102a38);
        (*pcVar3)();
      }
      iVar4 = (*(code *)puVar5[0x25])(param_1);
      if (iVar4 != 0) {
        _dev_err(*puVar5,"%s: disable_stream failed %d\n","slim_stream_disable",iVar4);
        mutex_unlock(puVar1);
        goto LAB_00102b18;
      }
      mutex_unlock(puVar1);
    }
    iVar4 = slim_do_transfer(puVar5,&local_c0);
    if (iVar4 == 0) {
      if (0 < *(int *)(param_1 + 0x24)) {
        lVar7 = 0;
        lVar8 = 0;
        do {
          lVar6 = *(long *)(param_1 + 8);
          local_90 = 0x10000;
          uStack_88 = 0;
          uStack_78 = 0;
          local_a8 = 0x550005;
          local_a1 = *(undefined1 *)(lVar6 + 0x3a4);
          local_a4 = 0;
          lVar2 = *(long *)(param_1 + 0x28) + lVar7;
          local_a2 = 0;
          uStack_98 = 0;
          local_6c[0] = (undefined1)*(undefined4 *)(lVar2 + 0xc);
          local_a0 = &local_90;
          local_80 = local_6c;
          iVar4 = slim_do_transfer(*(undefined8 *)(lVar6 + 0x398),&local_a8);
          if (iVar4 == 0) {
            local_a8._0_3_ = CONCAT12(0x58,(undefined2)local_a8);
            *(undefined4 *)(lVar2 + 0x20) = 6;
            slim_do_transfer(*(undefined8 *)(lVar6 + 0x398),&local_a8);
          }
          lVar8 = lVar8 + 1;
          lVar7 = lVar7 + 0x24;
        } while (lVar8 < *(int *)(param_1 + 0x24));
      }
      local_c0._0_3_ = CONCAT12(0x5f,(undefined2)local_c0);
      iVar4 = slim_do_transfer(puVar5,&local_c0);
    }
    else {
      _dev_err(*puVar5,"%s: slim_do_transfer failed %d\n","slim_stream_disable",iVar4);
    }
  }
LAB_00102b18:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// slim_stream_unprepare @ 00102be4 size=328
// signature: undefined slim_stream_unprepare(void)
// callers: []
//------------------------------------------------------------

void slim_stream_unprepare(long param_1)

{
  undefined4 *puVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  undefined4 local_98;
  undefined2 local_94;
  undefined1 local_92;
  undefined1 local_91;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 *local_70;
  undefined8 uStack_68;
  undefined1 local_5c [4];
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_001033db,"slim_stream_unprepare");
    uVar3 = 0xffffffea;
  }
  else {
    lVar2 = *(long *)(param_1 + 0x28);
    if ((lVar2 == 0) || (*(int *)(param_1 + 0x24) == 0)) {
      _printk(&DAT_0010330a,"slim_stream_unprepare");
      uVar3 = 0xffffffea;
    }
    else {
      if (0 < *(int *)(param_1 + 0x24)) {
        lVar5 = 0;
        lVar2 = 0;
        do {
          lVar4 = *(long *)(param_1 + 8);
          local_80 = 0x10000;
          uStack_78 = 0;
          uStack_68 = 0;
          local_98 = 0x140005;
          local_91 = *(undefined1 *)(lVar4 + 0x3a4);
          local_94 = 0;
          puVar1 = (undefined4 *)(*(long *)(param_1 + 0x28) + lVar5);
          local_92 = 0;
          uStack_88 = 0;
          local_5c[0] = (undefined1)*puVar1;
          puVar1[8] = 0;
          puVar1[2] = 0;
          local_90 = &local_80;
          local_70 = local_5c;
          slim_do_transfer(*(undefined8 *)(lVar4 + 0x398),&local_98);
          lVar2 = lVar2 + 1;
          lVar5 = lVar5 + 0x24;
        } while (lVar2 < *(int *)(param_1 + 0x24));
        lVar2 = *(long *)(param_1 + 0x28);
      }
      kfree(lVar2);
      uVar3 = 0;
      *(undefined8 *)(param_1 + 0x28) = 0;
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// slim_stream_unprepare_disconnect_port @ 00102d30 size=344
// signature: undefined slim_stream_unprepare_disconnect_port(void)
// callers: []
//------------------------------------------------------------

void slim_stream_unprepare_disconnect_port(long param_1,ulong param_2,ulong param_3)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 local_98;
  undefined2 local_94;
  undefined1 local_92;
  undefined1 local_91;
  undefined8 *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined1 *local_70;
  undefined8 uStack_68;
  undefined1 local_5c [4];
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_001033db,"slim_stream_unprepare_disconnect_port");
  }
  else {
    if ((*(long *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x24) != 0)) {
      if (((param_2 & 1) != 0) && (0 < *(int *)(param_1 + 0x24))) {
        lVar4 = 0;
        lVar5 = 0;
        do {
          lVar3 = *(long *)(param_1 + 8);
          local_80 = 0x10000;
          uStack_78 = 0;
          uStack_68 = 0;
          local_98 = 0x140005;
          local_91 = *(undefined1 *)(lVar3 + 0x3a4);
          local_94 = 0;
          puVar1 = (undefined4 *)(*(long *)(param_1 + 0x28) + lVar4);
          local_92 = 0;
          uStack_88 = 0;
          local_5c[0] = (undefined1)*puVar1;
          puVar1[8] = 0;
          puVar1[2] = 0;
          local_90 = &local_80;
          local_70 = local_5c;
          slim_do_transfer(*(undefined8 *)(lVar3 + 0x398),&local_98);
          lVar5 = lVar5 + 1;
          lVar4 = lVar4 + 0x24;
        } while (lVar5 < *(int *)(param_1 + 0x24));
      }
      if ((param_3 & 1) == 0) {
        uVar2 = 0;
      }
      else {
        kfree(*(undefined8 *)(param_1 + 0x28));
        uVar2 = 0;
        *(undefined8 *)(param_1 + 0x28) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0;
      }
      goto LAB_00102e50;
    }
    _printk(&DAT_0010330a,"slim_stream_unprepare_disconnect_port");
  }
  uVar2 = 0xffffffea;
LAB_00102e50:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// slim_stream_free @ 00102e8c size=156
// signature: undefined slim_stream_free(void)
// callers: []
//------------------------------------------------------------

undefined8 slim_stream_free(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  
  if (param_1 == (undefined8 *)0x0) {
    _printk(&DAT_001033db,"slim_stream_free");
    uVar4 = 0xffffffea;
  }
  else {
    lVar5 = param_1[1];
    _raw_spin_lock(lVar5 + 0x3b8);
    uVar3 = __list_del_entry_valid(param_1 + 6);
    if ((uVar3 & 1) != 0) {
      lVar1 = param_1[6];
      plVar2 = (long *)param_1[7];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    param_1[6] = 0xdead000000000100;
    param_1[7] = 0xdead000000000122;
    _raw_spin_unlock(lVar5 + 0x3b8);
    kfree(*param_1);
    kfree(param_1);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// cleanup_module @ 0010314c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  bus_unregister(&slimbus_bus);
  return;
}



//------------------------------------------------------------
// init_module @ 00103174 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  bus_register(&slimbus_bus);
  return;
}



//------------------------------------------------------------
// of_match_device @ 00105000 size=1
// signature: undefined of_match_device(void)
// callers: [slim_device_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 00105008 size=1
// signature: undefined add_uevent_var(void)
// callers: [slim_device_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00105010 size=1
// signature: undefined _dev_err(void)
// callers: [slim_stream_prepare, slim_msg_response, slim_do_transfer, slim_xfer_msg, slim_stream_disable, slim_register_controller, slim_stream_enable, slim_device_probe, slim_device_report_present, slim_alloc_txn_tid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 00105018 size=1
// signature: undefined driver_register(void)
// callers: [__slim_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 00105020 size=1
// signature: undefined driver_unregister(void)
// callers: [slim_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00105028 size=1
// signature: undefined ida_alloc_range(void)
// callers: [slim_device_alloc_laddr, slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00105030 size=1
// signature: undefined __mutex_init(void)
// callers: [slim_register_controller, slim_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00105038 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 00105040 size=1
// signature: undefined of_get_next_child(void)
// callers: [slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 00105048 size=1
// signature: undefined of_get_property(void)
// callers: [slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00105050 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00105058 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [slim_register_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [slim_stream_unprepare, slim_writeb, slim_stream_disable, slim_stream_unprepare_disconnect_port, slim_device_alloc_laddr, slim_register_controller, slim_readb, slim_read, slim_stream_prepare, slim_do_transfer, slim_write, slim_xfer_msg, slim_stream_enable, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 00105068 size=1
// signature: undefined device_for_each_child(void)
// callers: [slim_unregister_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 00105070 size=1
// signature: undefined ida_free(void)
// callers: [slim_report_absent, slim_unregister_controller]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 00105078 size=1
// signature: undefined device_unregister(void)
// callers: [slim_ctrl_remove_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105080 size=1
// signature: undefined mutex_lock(void)
// callers: [slim_stream_disable, slim_device_alloc_laddr, slim_stream_enable, slim_report_absent, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105088 size=1
// signature: undefined mutex_unlock(void)
// callers: [slim_stream_disable, slim_device_alloc_laddr, slim_stream_enable, slim_report_absent, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_find_child @ 00105090 size=1
// signature: undefined device_find_child(void)
// callers: [slim_get_device, of_slim_get_device, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_find_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001050a0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [slim_stream_allocate, slim_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 001050a8 size=1
// signature: undefined dev_set_name(void)
// callers: [slim_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 001050b0 size=1
// signature: undefined device_register(void)
// callers: [slim_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001050b8 size=1
// signature: undefined put_device(void)
// callers: [slim_alloc_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 001050c0 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [slim_do_transfer, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 001050d0 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [slim_do_transfer, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 001050d8 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [slim_msg_response, slim_do_transfer, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 001050e0 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [slim_msg_response, slim_do_transfer, slim_device_report_present]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001050e8 size=1
// signature: undefined _printk(void)
// callers: [slim_stream_prepare, slim_stream_unprepare, slim_stream_disable, slim_stream_unprepare_disconnect_port, slim_device_alloc_laddr, slim_stream_enable, slim_stream_free, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_unregister @ 001050f0 size=1
// signature: undefined bus_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 001050f8 size=1
// signature: undefined bus_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00105100 size=1
// signature: undefined kfree(void)
// callers: [slim_stream_allocate, slim_stream_unprepare, slim_dev_release, slim_stream_unprepare_disconnect_port, slim_stream_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00105108 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [slim_msg_response, slim_do_transfer, slim_free_txn_tid, slim_ctrl_clk_pause, slim_alloc_txn_tid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00105110 size=1
// signature: undefined idr_find(void)
// callers: [slim_msg_response, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00105118 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [slim_msg_response, slim_do_transfer, slim_free_txn_tid, slim_ctrl_clk_pause, slim_alloc_txn_tid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00105120 size=1
// signature: undefined idr_remove(void)
// callers: [slim_msg_response, slim_do_transfer, slim_free_txn_tid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcpy_fromio @ 00105128 size=1
// signature: undefined __memcpy_fromio(void)
// callers: [slim_msg_response]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcpy_fromio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00105130 size=1
// signature: undefined complete(void)
// callers: [slim_msg_response, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc_cyclic @ 00105138 size=1
// signature: undefined idr_alloc_cyclic(void)
// callers: [slim_do_transfer, slim_alloc_txn_tid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc_cyclic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00105140 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [slim_do_transfer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00105148 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [slim_do_transfer, slim_ctrl_clk_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 00105150 size=1
// signature: undefined kasprintf(void)
// callers: [slim_stream_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00105158 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [slim_stream_allocate, slim_stream_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105160 size=1
// signature: undefined __list_add_valid(void)
// callers: [slim_stream_allocate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00105168 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [slim_stream_allocate, slim_stream_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __sw_hweight32 @ 00105170 size=1
// signature: undefined __sw_hweight32(void)
// callers: [slim_stream_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __sw_hweight32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105178 size=1
// signature: undefined __kmalloc(void)
// callers: [slim_stream_prepare]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00105180 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [slim_stream_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



