// Decompiled by Ghidra 12.2
// Program: gpr_dlkm.ko
// Image base: 00100000

//------------------------------------------------------------
// gpr_get_q6_state @ 001004b4 size=12
// signature: undefined gpr_get_q6_state(void)
// callers: []
//------------------------------------------------------------

undefined4 gpr_get_q6_state(void)

{
  return q6;
}



//------------------------------------------------------------
// gpr_get_modem_state @ 001004c4 size=12
// signature: undefined gpr_get_modem_state(void)
// callers: []
//------------------------------------------------------------

undefined4 gpr_get_modem_state(void)

{
  return DAT_001015a4;
}



//------------------------------------------------------------
// gpr_subsys_notif_register @ 001004d4 size=116
// signature: undefined gpr_subsys_notif_register(void)
// callers: []
//------------------------------------------------------------

void gpr_subsys_notif_register(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = audio_notifier_register();
  if (iVar1 < 0) {
    iVar2 = ___ratelimit(&gpr_subsys_notif_register__rs,"gpr_subsys_notif_register");
    if (iVar2 != 0) {
      _dev_err(*(undefined8 *)(gpr_priv + 8),
               "%s: Audio notifier register failed for domain %d ret = %d\n",
               "gpr_subsys_notif_register",param_2,iVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// gpr_subsys_notif_deregister @ 0010054c size=108
// signature: undefined gpr_subsys_notif_deregister(void)
// callers: []
//------------------------------------------------------------

void gpr_subsys_notif_deregister(undefined8 param_1)

{
  int iVar1;
  
  iVar1 = audio_notifier_deregister();
  if ((iVar1 < 0) &&
     (iVar1 = ___ratelimit(gpr_subsys_notif_deregister__rs,"gpr_subsys_notif_deregister"),
     iVar1 != 0)) {
    _dev_err(*(undefined8 *)(gpr_priv + 8),"%s: Audio notifier de-register failed for client %s\n",
             "gpr_subsys_notif_deregister",param_1);
  }
  return;
}



//------------------------------------------------------------
// gpr_send_pkt @ 001005bc size=496
// signature: undefined gpr_send_pkt(void)
// callers: []
//------------------------------------------------------------

uint gpr_send_pkt(long param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined8 *puVar7;
  
  if (q6 == 0) {
    iVar2 = ___ratelimit(gpr_send_pkt__rs,"gpr_send_pkt");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    _printk(&DAT_00101d8e,"gpr_send_pkt");
    return 0xffffffea;
  }
  if (param_1 == 0) {
    iVar2 = ___ratelimit(gpr_send_pkt__rs_3,"gpr_send_pkt");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar5 = &DAT_00101cf9;
  }
  else {
    if (*(long *)(param_1 + 0x60) == 0) {
      iVar2 = ___ratelimit(gpr_send_pkt__rs_5,"gpr_send_pkt");
      if (iVar2 == 0) {
        return 0xffffffea;
      }
      uVar4 = *(undefined8 *)(param_1 + 0x60);
      puVar5 = &DAT_00101db1;
      goto LAB_001006f4;
    }
    puVar7 = *(undefined8 **)(*(long *)(param_1 + 0x60) + 0x98);
    if (puVar7 != (undefined8 *)0x0) {
      if (*(short *)(param_1 + 0x392) == 1) {
        if (DAT_001015a4 != 0) goto LAB_00100720;
        iVar2 = ___ratelimit(gpr_send_pkt__rs_11,"gpr_send_pkt");
        if (iVar2 == 0) {
          return 0xffffff9a;
        }
        uVar4 = puVar7[1];
        pcVar6 = "%s: Still Modem is not Up\n";
      }
      else {
        if ((*(short *)(param_1 + 0x392) != 2) || (q6 == 2)) {
LAB_00100720:
          uVar4 = _raw_spin_lock_irqsave(param_1 + 0x3b8);
          uVar1 = *param_2;
          *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 0x392);
          uVar3 = rpmsg_trysend(*puVar7,param_2,uVar1 >> 8);
          _raw_spin_unlock_irqrestore(param_1 + 0x3b8,uVar4);
          uVar1 = uVar1 >> 8;
          if (uVar3 != 0) {
            uVar1 = uVar3;
          }
          return uVar1;
        }
        iVar2 = ___ratelimit(gpr_send_pkt__rs_9,"gpr_send_pkt");
        if (iVar2 == 0) {
          return 0xffffff9a;
        }
        uVar4 = puVar7[1];
        pcVar6 = "%s: Still Dsp is not Up\n";
      }
      _dev_err(uVar4,pcVar6,"gpr_send_pkt");
      return 0xffffff9a;
    }
    iVar2 = ___ratelimit(gpr_send_pkt__rs_7,"gpr_send_pkt");
    if (iVar2 == 0) {
      return 0xffffffea;
    }
    puVar5 = &DAT_00101c57;
  }
  uVar4 = 0;
LAB_001006f4:
  _printk(puVar5,"gpr_send_pkt",uVar4);
  return 0xffffffea;
}



//------------------------------------------------------------
// gpr_set_modem_state @ 001007b0 size=12
// signature: undefined gpr_set_modem_state(void)
// callers: []
//------------------------------------------------------------

void gpr_set_modem_state(undefined4 param_1)

{
  DAT_001015a4 = param_1;
  return;
}



//------------------------------------------------------------
// gpr_set_q6_state @ 001007c0 size=32
// signature: undefined gpr_set_q6_state(void)
// callers: []
//------------------------------------------------------------

undefined8 gpr_set_q6_state(uint param_1)

{
  if (param_1 < 3) {
    q6 = param_1;
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gpr_device_match @ 001007e4 size=132
// signature: undefined gpr_device_match(void)
// callers: []
//------------------------------------------------------------

undefined8 gpr_device_match(long param_1,long param_2)

{
  long lVar1;
  uint *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0xb0);
  lVar1 = of_match_device(*(undefined8 *)(param_2 + 0x28),param_1);
  if (lVar1 == 0) {
    if (lVar3 == 0) {
      return 0;
    }
    puVar2 = (uint *)(lVar3 + 0x24);
    while( true ) {
      if ((puVar2[-1] == 0) && (*puVar2 == 0)) {
        return 0;
      }
      if ((puVar2[-1] == (uint)*(ushort *)(param_1 + 0x392)) &&
         (*puVar2 == (uint)*(ushort *)(param_1 + 0x390))) break;
      puVar2 = puVar2 + 0xe;
    }
  }
  return 1;
}



//------------------------------------------------------------
// gpr_uevent @ 0010086c size=72
// signature: undefined gpr_uevent(void)
// callers: []
//------------------------------------------------------------

void gpr_uevent(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = of_device_uevent_modalias();
  if (iVar1 == -0x13) {
    add_uevent_var(param_2,"MODALIAS=gpr:%s",param_1 + 0x398);
  }
  return;
}



//------------------------------------------------------------
// gpr_device_probe @ 001008b8 size=60
// signature: undefined gpr_device_probe(void)
// callers: []
//------------------------------------------------------------

void gpr_device_probe(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + -0x18);
  if (*(int *)(pcVar1 + -4) != 0x2d643f45) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1008e4);
    (*pcVar1)();
  }
  (*pcVar1)();
  return;
}



//------------------------------------------------------------
// gpr_device_remove @ 001008f8 size=140
// signature: undefined gpr_device_remove(void)
// callers: []
//------------------------------------------------------------

void gpr_device_remove(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x88) != 0) {
    pcVar3 = *(code **)(*(long *)(param_1 + 0x88) + -0x10);
    lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x2d643f45) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100944);
        (*pcVar3)();
      }
      (*pcVar3)(param_1);
    }
    lVar1 = lVar4 + 0x18;
    uVar2 = _raw_spin_lock_irqsave(lVar1);
    idr_remove(lVar4 + 0x20,*(undefined2 *)(param_1 + 0x390));
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
  }
  return;
}



//------------------------------------------------------------
// __gpr_driver_register @ 00100988 size=48
// signature: undefined __gpr_driver_register(void)
// callers: []
//------------------------------------------------------------

void __gpr_driver_register(long param_1,undefined8 param_2)

{
  *(undefined ***)(param_1 + 0x20) = &gprbus;
  *(undefined8 *)(param_1 + 0x28) = param_2;
  driver_register(param_1 + 0x18);
  return;
}



//------------------------------------------------------------
// gpr_driver_unregister @ 001009bc size=32
// signature: undefined gpr_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void gpr_driver_unregister(long param_1)

{
  driver_unregister(param_1 + 0x18);
  return;
}



//------------------------------------------------------------
// gpr_probe @ 001009e0 size=1096
// signature: undefined gpr_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gpr_probe(long param_1)

{
  long lVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  char *__string;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  uVar4 = audio_notifier_probe_status();
  if ((uVar4 & 1) == 0) {
    _printk(&DAT_00101ea4,"gpr_probe");
    iVar2 = -0x205;
  }
  else {
    gpr_priv = (undefined8 *)devm_kmalloc(param_1,0x78,0xdc0);
    if (gpr_priv == (undefined8 *)0x0) {
      iVar2 = -0xc;
    }
    else {
      *(undefined4 *)(gpr_priv + 2) = 0;
      __mutex_init(&DAT_001015a8,"&q6.lock",&gpr_probe___key);
      _raw_spin_lock(gpr_priv + 2);
      puVar5 = gpr_priv + 2;
      *(undefined1 *)((long)gpr_priv + 0x14) = 1;
      _raw_spin_unlock(puVar5);
      puVar5 = gpr_priv;
      *(undefined8 **)(param_1 + 0x98) = gpr_priv;
      *puVar5 = *(undefined8 *)(param_1 + 0x3c8);
      puVar5[1] = param_1;
      *(undefined4 *)(puVar5 + 3) = 0;
      puVar5[4] = 0x1000000400000000;
      puVar5[5] = 0;
      puVar5[6] = 0;
      iVar2 = snd_event_client_register(param_1,gpr_ssr_ops,0);
      if (iVar2 != 0) {
        _dev_err(param_1,"%s: Registration with SND event fwk failed ret = %d\n","gpr_probe",iVar2);
      }
      iVar2 = of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2e8),&DAT_00101c18,gpr_priv + 7,1,0);
      if (iVar2 < 0) {
        _dev_err(param_1,"GPR Domain ID not specified in DT\n");
      }
      else {
        lVar8 = *(long *)(param_1 + 0x98);
        puVar5 = (undefined8 *)of_get_next_child(*(undefined8 *)(param_1 + 0x2e8),0);
        if (puVar5 != (undefined8 *)0x0) {
          do {
            local_78 = 0;
            uStack_70 = 0;
            local_80 = 0;
            iVar2 = of_property_read_variable_u32_array
                              (puVar5,&DAT_00101c18,(long)&local_80 + 4,1,0);
            if (-1 < iVar2) {
              lVar9 = *(long *)(param_1 + 0x98);
              local_80 = CONCAT44(local_80._4_4_,*(undefined4 *)(lVar8 + 0x38));
              plVar7 = (long *)kmalloc_trace(_snd_event_client_deregister,0xdc0,0x3d0);
              if (plVar7 != (long *)0x0) {
                *(undefined4 *)(plVar7 + 0x77) = 0;
                *(short *)(plVar7 + 0x72) = (short)(local_80 >> 0x20);
                *(short *)((long)plVar7 + 0x392) = (short)local_80;
                *(undefined4 *)((long)plVar7 + 0x394) = (undefined4)local_78;
                __string = (char *)*puVar5;
                uVar4 = strnlen(__string,0x20);
                if (uVar4 == 0xffffffffffffffff) {
                  fortify_panic("strnlen");
                }
                else {
                  if (uVar4 != 0x20) {
                    uVar4 = uVar4 + 1;
                  }
                  if (uVar4 < 0x21) {
                    strscpy(plVar7 + 0x73,__string);
                    dev_set_name(plVar7,"gprsvc:%s:%x:%x",plVar7 + 0x73,local_80 & 0xffffffff,
                                 local_80._4_4_);
                    lVar1 = lVar9 + 0x18;
                    plVar7[0xc] = param_1;
                    plVar7[0x5d] = (long)puVar5;
                    plVar7[0x65] = (long)gpr_dev_release;
                    plVar7[0x10] = (long)&gprbus;
                    plVar7[0x11] = 0;
                    uVar6 = _raw_spin_lock_irqsave(lVar1);
                    idr_alloc(lVar9 + 0x20,plVar7,local_80._4_4_,local_80._4_4_ + 1,0xa20);
                    _raw_spin_unlock_irqrestore(lVar1,uVar6);
                    iVar2 = ___ratelimit(gpr_add_device__rs,"gpr_add_device");
                    if (iVar2 != 0) {
                      lVar9 = plVar7[0xe];
                      if (lVar9 == 0) {
                        lVar9 = *plVar7;
                      }
                      _dev_info(param_1,"Adding GPR dev: %s\n",lVar9);
                    }
                    iVar2 = device_register(plVar7);
                    if (iVar2 == 0) goto LAB_00100c40;
                    iVar3 = ___ratelimit(gpr_add_device__rs_27,"gpr_add_device");
                    if (iVar3 != 0) {
                      _dev_err(param_1,"device_register failed: %d\n",iVar2);
                    }
                    put_device(plVar7);
                    goto LAB_00100c28;
                  }
                }
                fortify_panic("strscpy");
                goto LAB_00100e24;
              }
LAB_00100c28:
              iVar2 = ___ratelimit(of_register_gpr_devices__rs,"of_register_gpr_devices");
              if (iVar2 != 0) {
                _dev_err(param_1,"Failed to add gpr %d svc\n",local_80._4_4_);
              }
            }
LAB_00100c40:
            puVar5 = (undefined8 *)of_get_next_child(*(undefined8 *)(param_1 + 0x2e8),puVar5);
          } while (puVar5 != (undefined8 *)0x0);
        }
        puVar5 = gpr_priv;
        gpr_priv[8] = 0xfffffffe0;
        puVar5[9] = puVar5 + 9;
        puVar5[10] = puVar5 + 9;
        puVar5[0xb] = gpr_notifier_register;
        if (*(int *)(puVar5 + 7) - 1U < 2) {
          queue_work_on(0x20,_system_wq);
          uVar6 = wakeup_source_register(gpr_priv[1],"audio-gpr");
          gpr_priv[0xe] = uVar6;
          _dev_info(param_1,"%s: gpr-lite probe success\n","gpr_probe");
          iVar2 = 0;
        }
        else {
          _dev_err(param_1,"%s: invalid dest_domain_id %s\n","gpr_probe");
          iVar2 = -0x16;
        }
      }
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) == local_68) {
    return iVar2;
  }
LAB_00100e24:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// gpr_remove @ 00100e2c size=268
// signature: undefined gpr_remove(void)
// callers: []
//------------------------------------------------------------

void gpr_remove(undefined8 param_1)

{
  int iVar1;
  char *pcVar2;
  
  wakeup_source_unregister(*(undefined8 *)(gpr_priv + 0x70));
  snd_event_client_deregister(param_1);
  _dev_info(param_1,"%s: deregistering via subsys_notif_register for domain_id(%d)","gpr_remove",
            *(undefined4 *)(gpr_priv + 0x38));
  if (*(int *)(gpr_priv + 0x38) == 1) {
    iVar1 = audio_notifier_deregister("gpr_modem");
    if ((-1 < iVar1) ||
       (iVar1 = ___ratelimit(gpr_subsys_notif_deregister__rs,"gpr_subsys_notif_deregister"),
       iVar1 == 0)) goto LAB_00100eec;
    pcVar2 = "gpr_modem";
  }
  else {
    if (((*(int *)(gpr_priv + 0x38) != 2) ||
        (iVar1 = audio_notifier_deregister("gpr_adsp"), -1 < iVar1)) ||
       (iVar1 = ___ratelimit(gpr_subsys_notif_deregister__rs,"gpr_subsys_notif_deregister"),
       iVar1 == 0)) goto LAB_00100eec;
    pcVar2 = "gpr_adsp";
  }
  _dev_err(*(undefined8 *)(gpr_priv + 8),"%s: Audio notifier de-register failed for client %s\n",
           "gpr_subsys_notif_deregister",pcVar2);
LAB_00100eec:
  device_for_each_child(param_1,0,gpr_remove_device);
  return;
}



//------------------------------------------------------------
// gpr_callback @ 00100f3c size=548
// signature: undefined gpr_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 gpr_callback(long param_1,uint *param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0x98);
  if (param_3 < 0x19) {
    iVar5 = ___ratelimit(gpr_callback__rs,"gpr_callback");
    if (iVar5 != 0) {
      _dev_err(*(undefined8 *)(lVar8 + 8),"GPR: Improper gpr pkt received:%p %d\n",param_2,param_3);
    }
  }
  else {
    uVar3 = *param_2;
    uVar2 = uVar3 >> 2 & 0x3c;
    if (uVar2 < 0x18) {
      iVar5 = ___ratelimit(gpr_callback__rs_37,"gpr_callback");
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar8 + 8),"GPR: Wrong hdr size:%d\n",uVar2);
      }
    }
    else if (((uVar3 >> 0xb & 0x1fff) < 3) || (param_3 != (uVar3 >> 8 & 0xffff))) {
      iVar5 = ___ratelimit(gpr_callback__rs_39,"gpr_callback");
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar8 + 8),"GPR: Wrong packet size\n");
      }
    }
    else {
      if (param_2[5] == 0x3001000) {
        pm_wakeup_ws_event(*(undefined8 *)(gpr_priv + 0x70),200,1);
      }
      lVar1 = lVar8 + 0x18;
      uVar2 = param_2[3];
      uVar6 = _raw_spin_lock_irqsave(lVar1);
      lVar7 = idr_find(lVar8 + 0x20,(short)uVar2);
      if (((lVar7 == 0) || (lVar9 = *(long *)(lVar7 + 0x88), lVar9 == 0)) &&
         ((lVar7 = idr_find(lVar8 + 0x20,0x17), lVar7 == 0 ||
          (lVar9 = *(long *)(lVar7 + 0x88), lVar9 == 0)))) {
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
      }
      else {
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        if (lVar9 != 0x18) {
          if (*(int *)(*(code **)(lVar9 + -8) + -4) != 0x5bbfaee7) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1010b0);
            (*pcVar4)();
          }
          (**(code **)(lVar9 + -8))(lVar7,param_2);
          return 0;
        }
      }
      iVar5 = ___ratelimit(gpr_callback__rs_41,"gpr_callback");
      if (iVar5 != 0) {
        _dev_err(*(undefined8 *)(lVar8 + 8),"GPR: service is not registered\n");
      }
      if (param_2[5] == 0x3001000) {
        __pm_relax(*(undefined8 *)(gpr_priv + 0x70));
      }
    }
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// gpr_notifier_register @ 00101164 size=300
// signature: undefined gpr_notifier_register(void)
// callers: []
//------------------------------------------------------------

void gpr_notifier_register(void)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  if (*(int *)(gpr_priv + 0x38) == 1) {
    iVar1 = audio_notifier_register("gpr_modem",1,&modem_service_nb);
    if ((-1 < iVar1) ||
       (iVar2 = ___ratelimit(&gpr_subsys_notif_register__rs,"gpr_subsys_notif_register"), iVar2 == 0
       )) goto LAB_0010121c;
    uVar3 = 1;
  }
  else {
    if (((*(int *)(gpr_priv + 0x38) != 2) ||
        (iVar1 = audio_notifier_register("gpr_adsp",0,&adsp_service_nb), -1 < iVar1)) ||
       (iVar2 = ___ratelimit(&gpr_subsys_notif_register__rs,"gpr_subsys_notif_register"), iVar2 == 0
       )) goto LAB_0010121c;
    uVar3 = 0;
  }
  _dev_err(*(undefined8 *)(gpr_priv + 8),
           "%s: Audio notifier register failed for domain %d ret = %d\n","gpr_subsys_notif_register"
           ,uVar3,iVar1);
LAB_0010121c:
  iVar1 = ___ratelimit(gpr_notifier_register__rs,"gpr_notifier_register");
  if (iVar1 != 0) {
    _dev_info(*(undefined8 *)(gpr_priv + 8),
              "%s: registered via subsys_notif_register for domain id(%d)","gpr_notifier_register",
              *(undefined4 *)(gpr_priv + 0x38));
  }
  return;
}



//------------------------------------------------------------
// gpr_ssr_disable @ 00101294 size=12
// signature: undefined gpr_ssr_disable(void)
// callers: []
//------------------------------------------------------------

void gpr_ssr_disable(void)

{
  q6 = 0;
  return;
}



//------------------------------------------------------------
// gpr_dev_release @ 001012a4 size=28
// signature: undefined gpr_dev_release(void)
// callers: []
//------------------------------------------------------------

void gpr_dev_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// gpr_notifier_service_cb @ 001012c4 size=404
// signature: undefined gpr_notifier_service_cb(void)
// callers: []
//------------------------------------------------------------

undefined8 gpr_notifier_service_cb(undefined8 param_1,long param_2,long param_3)

{
  long lVar1;
  char cVar2;
  int iVar3;
  
  if (param_3 == 0) {
    iVar3 = ___ratelimit(gpr_notifier_service_cb__rs,"gpr_notifier_service_cb");
    if (iVar3 != 0) {
      _dev_err(*(undefined8 *)(gpr_priv + 8),"%s: Callback data is NULL!\n",
               "gpr_notifier_service_cb");
    }
  }
  else if (param_2 == 1) {
    if (*(int *)(param_3 + 4) != 1) {
      iVar3 = ___ratelimit(gpr_adsp_up__rs,"gpr_adsp_up");
      if (iVar3 != 0) {
        _dev_info(*(undefined8 *)(gpr_priv + 8),"%s: Q6 is Up\n","gpr_adsp_up");
      }
      q6 = 2;
      snd_event_notify(*(undefined8 *)(gpr_priv + 8),1);
    }
    _raw_spin_lock(gpr_priv + 0x10);
    lVar1 = gpr_priv + 0x10;
    *(undefined1 *)(gpr_priv + 0x14) = 0;
    _raw_spin_unlock(lVar1);
  }
  else if (param_2 == 0) {
    _raw_spin_lock(gpr_priv + 0x10);
    cVar2 = *(char *)(gpr_priv + 0x14);
    _raw_spin_unlock(gpr_priv + 0x10);
    if (cVar2 == '\0') {
      if (*(int *)(param_3 + 4) == 1) {
        DAT_001015a4 = 0;
      }
      else {
        iVar3 = ___ratelimit(gpr_adsp_down__rs,"gpr_adsp_down");
        if (iVar3 != 0) {
          _dev_info(*(undefined8 *)(gpr_priv + 8),"%s: Q6 is Down\n","gpr_adsp_down");
        }
        q6 = 0;
        snd_event_notify(*(undefined8 *)(gpr_priv + 8),0);
      }
    }
  }
  return 1;
}



//------------------------------------------------------------
// gpr_remove_device @ 0010145c size=32
// signature: undefined gpr_remove_device(void)
// callers: []
//------------------------------------------------------------

undefined8 gpr_remove_device(void)

{
  device_unregister();
  return 0;
}



//------------------------------------------------------------
// init_module @ 0010150c size=96
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = bus_register(&gprbus);
  if (iVar1 == 0) {
    iVar1 = __register_rpmsg_driver(&gpr_driver,&__this_module);
  }
  else {
    bus_unregister(&gprbus);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00101570 size=48
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  bus_unregister(&gprbus);
  unregister_rpmsg_driver(&gpr_driver);
  return;
}



//------------------------------------------------------------
// audio_notifier_register @ 00104000 size=1
// signature: undefined audio_notifier_register(void)
// callers: [gpr_notifier_register, gpr_subsys_notif_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104008 size=1
// signature: undefined ___ratelimit(void)
// callers: [gpr_notifier_register, gpr_subsys_notif_register, gpr_probe, gpr_send_pkt, gpr_notifier_service_cb, gpr_subsys_notif_deregister, gpr_callback, gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00104010 size=1
// signature: undefined _dev_err(void)
// callers: [gpr_notifier_register, gpr_subsys_notif_register, gpr_probe, gpr_send_pkt, gpr_notifier_service_cb, gpr_subsys_notif_deregister, gpr_callback, gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// audio_notifier_deregister @ 00104018 size=1
// signature: undefined audio_notifier_deregister(void)
// callers: [gpr_subsys_notif_deregister, gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104020 size=1
// signature: undefined _printk(void)
// callers: [gpr_probe, gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104028 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gpr_probe, gpr_send_pkt, gpr_callback, gpr_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_trysend @ 00104030 size=1
// signature: undefined rpmsg_trysend(void)
// callers: [gpr_send_pkt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_trysend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104038 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gpr_probe, gpr_send_pkt, gpr_callback, gpr_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_device @ 00104040 size=1
// signature: undefined of_match_device(void)
// callers: [gpr_device_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_uevent_modalias @ 00104048 size=1
// signature: undefined of_device_uevent_modalias(void)
// callers: [gpr_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_uevent_modalias(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 00104050 size=1
// signature: undefined add_uevent_var(void)
// callers: [gpr_uevent]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_remove @ 00104058 size=1
// signature: undefined idr_remove(void)
// callers: [gpr_device_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 00104060 size=1
// signature: undefined driver_register(void)
// callers: [__gpr_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 00104068 size=1
// signature: undefined driver_unregister(void)
// callers: [gpr_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 00104070 size=1
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
// bus_unregister @ 00104078 size=1
// signature: undefined bus_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 00104080 size=1
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
// unregister_rpmsg_driver @ 00104088 size=1
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
// audio_notifier_probe_status @ 00104090 size=1
// signature: undefined audio_notifier_probe_status(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void audio_notifier_probe_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00104098 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 001040a0 size=1
// signature: undefined __mutex_init(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001040a8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gpr_probe, gpr_notifier_service_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001040b0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gpr_probe, gpr_notifier_service_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_register @ 001040b8 size=1
// signature: undefined snd_event_client_register(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001040c0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_child @ 001040c8 size=1
// signature: undefined of_get_next_child(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001040d8 size=1
// signature: undefined queue_work_on(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 001040e0 size=1
// signature: undefined wakeup_source_register(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001040e8 size=1
// signature: undefined _dev_info(void)
// callers: [gpr_notifier_register, gpr_probe, gpr_notifier_service_cb, gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 001040f0 size=1
// signature: undefined put_device(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00104100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00104108 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00104110 size=1
// signature: undefined strscpy(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00104118 size=1
// signature: undefined dev_set_name(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_alloc @ 00104120 size=1
// signature: undefined idr_alloc(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 00104128 size=1
// signature: undefined device_register(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104130 size=1
// signature: undefined fortify_panic(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104138 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gpr_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 00104140 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_client_deregister @ 00104148 size=1
// signature: undefined snd_event_client_deregister(void)
// callers: [gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_client_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_for_each_child @ 00104150 size=1
// signature: undefined device_for_each_child(void)
// callers: [gpr_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 00104158 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [gpr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_find @ 00104160 size=1
// signature: undefined idr_find(void)
// callers: [gpr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_relax @ 00104168 size=1
// signature: undefined __pm_relax(void)
// callers: [gpr_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_relax(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00104170 size=1
// signature: undefined kfree(void)
// callers: [gpr_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snd_event_notify @ 00104178 size=1
// signature: undefined snd_event_notify(void)
// callers: [gpr_notifier_service_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void snd_event_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 00104180 size=1
// signature: undefined device_unregister(void)
// callers: [gpr_remove_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



