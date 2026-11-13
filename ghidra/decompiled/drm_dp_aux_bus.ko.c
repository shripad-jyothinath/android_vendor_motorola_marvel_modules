// Decompiled by Ghidra 12.2
// Program: drm_dp_aux_bus.ko
// Image base: 00100000

//------------------------------------------------------------
// of_dp_aux_depopulate_bus @ 00100364 size=44
// signature: undefined of_dp_aux_depopulate_bus(void)
// callers: []
//------------------------------------------------------------

void of_dp_aux_depopulate_bus(long param_1)

{
  device_for_each_child_reverse(*(undefined8 *)(param_1 + 0x4c8),0,of_dp_aux_ep_destroy);
  return;
}



//------------------------------------------------------------
// of_dp_aux_ep_destroy @ 00100394 size=100
// signature: undefined of_dp_aux_ep_destroy(void)
// callers: []
//------------------------------------------------------------

undefined8 of_dp_aux_ep_destroy(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  
  if ((*(undefined ***)(param_1 + 0x80) == &dp_aux_bus_type) &&
     (((uint)*(undefined8 *)(*(long *)(param_1 + 0x2e8) + 0xe8) >> 3 & 1) != 0)) {
    puVar1 = (ulong *)(*(long *)(param_1 + 0x2e8) + 0xe8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & 0xfffffffffffffff7;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    device_unregister();
  }
  return 0;
}



//------------------------------------------------------------
// of_dp_aux_populate_bus @ 00100408 size=360
// signature: undefined of_dp_aux_populate_bus(void)
// callers: [devm_of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int of_dp_aux_populate_bus(long param_1,undefined8 param_2)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long *plVar9;
  ulong uVar10;
  
  if (*(long *)(param_1 + 0x18) == 0) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x100538);
    (*pcVar4)();
  }
  lVar6 = *(long *)(*(long *)(param_1 + 0x4c8) + 0x2e8);
  if (((lVar6 == 0) || (lVar6 = of_get_child_by_name(lVar6,"aux-bus"), lVar6 == 0)) ||
     (lVar6 = of_get_next_available_child(lVar6,0), lVar6 == 0)) {
    iVar5 = -0x13;
  }
  else {
    puVar1 = (ulong *)(lVar6 + 0xe8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      uVar10 = *puVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = uVar10 | 8;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if (((uint)uVar10 >> 3 & 1) == 0) {
      lVar7 = kmalloc_trace(_bus_unregister,0xdc0,0x3a0);
      if (lVar7 == 0) {
        iVar5 = -0xc;
      }
      else {
        plVar9 = *(long **)(param_1 + 0x4c8);
        *(undefined8 *)(lVar7 + 0x398) = param_2;
        *(long *)(lVar7 + 0x390) = param_1;
        *(long **)(lVar7 + 0x60) = plVar9;
        *(undefined1 **)(lVar7 + 0x78) = dp_aux_device_type_type;
        *(undefined ***)(lVar7 + 0x80) = &dp_aux_bus_type;
        *(long *)(lVar7 + 0x2e8) = lVar6;
        lVar8 = plVar9[0xe];
        if (lVar8 == 0) {
          lVar8 = *plVar9;
        }
        dev_set_name(lVar7,"aux-%s",lVar8);
        iVar5 = device_register(lVar7);
        if (iVar5 == 0) {
          return 0;
        }
        _dev_err(*(undefined8 *)(param_1 + 0x4c8),"Failed to create AUX EP for %pOF: %d\n",lVar6,
                 iVar5);
        put_device(lVar7);
      }
      puVar1 = (ulong *)(lVar6 + 0xe8);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & 0xfffffffffffffff7;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
    }
    else {
      _dev_err(*(undefined8 *)(param_1 + 0x4c8),"DP AUX EP device already populated\n");
      iVar5 = -0x16;
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// devm_of_dp_aux_populate_bus @ 00100598 size=100
// signature: undefined devm_of_dp_aux_populate_bus(void)
// callers: []
//------------------------------------------------------------

int devm_of_dp_aux_populate_bus(long param_1)

{
  int iVar1;
  
  iVar1 = of_dp_aux_populate_bus();
  if (iVar1 == 0) {
    iVar1 = devm_add_action(*(undefined8 *)(param_1 + 0x4c8),of_dp_aux_depopulate_bus_void,param_1);
    if (iVar1 != 0) {
      device_for_each_child_reverse(*(undefined8 *)(param_1 + 0x4c8),0,of_dp_aux_ep_destroy);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// of_dp_aux_depopulate_bus_void @ 00100600 size=44
// signature: undefined of_dp_aux_depopulate_bus_void(void)
// callers: []
//------------------------------------------------------------

void of_dp_aux_depopulate_bus_void(long param_1)

{
  device_for_each_child_reverse(*(undefined8 *)(param_1 + 0x4c8),0,of_dp_aux_ep_destroy);
  return;
}



//------------------------------------------------------------
// __dp_aux_dp_driver_register @ 00100630 size=48
// signature: undefined __dp_aux_dp_driver_register(void)
// callers: []
//------------------------------------------------------------

void __dp_aux_dp_driver_register(long param_1,undefined8 param_2)

{
  *(undefined ***)(param_1 + 0x20) = &dp_aux_bus_type;
  *(undefined8 *)(param_1 + 0x28) = param_2;
  driver_register(param_1 + 0x18);
  return;
}



//------------------------------------------------------------
// dp_aux_dp_driver_unregister @ 00100664 size=32
// signature: undefined dp_aux_dp_driver_unregister(void)
// callers: []
//------------------------------------------------------------

void dp_aux_dp_driver_unregister(long param_1)

{
  driver_unregister(param_1 + 0x18);
  return;
}



//------------------------------------------------------------
// dp_aux_ep_match @ 00100688 size=48
// signature: undefined dp_aux_ep_match(void)
// callers: []
//------------------------------------------------------------

bool dp_aux_ep_match(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = of_match_device(*(undefined8 *)(param_2 + 0x28),param_1);
  return lVar1 != 0;
}



//------------------------------------------------------------
// dp_aux_ep_probe @ 001006bc size=288
// signature: undefined dp_aux_ep_probe(void)
// callers: []
//------------------------------------------------------------

int dp_aux_ep_probe(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x88);
  iVar2 = dev_pm_domain_attach(param_1,1);
  if (iVar2 != 0) {
    iVar2 = dev_err_probe(param_1,iVar2,"Failed to attach to PM Domain\n");
    return iVar2;
  }
  if (*(int *)(*(code **)(lVar3 + -0x18) + -4) != 0x1b93abbf) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100720);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(lVar3 + -0x18))(param_1);
  if (iVar2 == 0) {
    pcVar1 = *(code **)(param_1 + 0x398);
    if (pcVar1 == (code *)0x0) {
      return 0;
    }
    if (*(int *)(pcVar1 + -4) != 0x2eecc5dc) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100774);
      (*pcVar1)();
    }
    iVar2 = (*pcVar1)(*(undefined8 *)(param_1 + 0x390));
    if (iVar2 == 0) {
      return 0;
    }
    if (iVar2 == -0x205) {
      _dev_err(param_1,"DP AUX done_probing() can\'t defer\n");
      iVar2 = -0x16;
      pcVar1 = *(code **)(lVar3 + -0x10);
    }
    else {
      pcVar1 = *(code **)(lVar3 + -0x10);
    }
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != 0x10f42d46) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1007ac);
        (*pcVar1)();
      }
      (*pcVar1)(param_1);
    }
  }
  dev_pm_domain_detach(param_1,1);
  return iVar2;
}



//------------------------------------------------------------
// dp_aux_ep_remove @ 001007e0 size=92
// signature: undefined dp_aux_ep_remove(void)
// callers: []
//------------------------------------------------------------

void dp_aux_ep_remove(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + -0x10);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x10f42d46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10081c);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  dev_pm_domain_detach(param_1,1);
  return;
}



//------------------------------------------------------------
// dp_aux_ep_shutdown @ 00100840 size=68
// signature: undefined dp_aux_ep_shutdown(void)
// callers: []
//------------------------------------------------------------

void dp_aux_ep_shutdown(long param_1)

{
  code *pcVar1;
  
  if ((*(long *)(param_1 + 0x88) != 0) &&
     (pcVar1 = *(code **)(*(long *)(param_1 + 0x88) + -8), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x10f42d46) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100874);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// dp_aux_ep_dev_release @ 00100888 size=28
// signature: undefined dp_aux_ep_dev_release(void)
// callers: []
//------------------------------------------------------------

void dp_aux_ep_dev_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// modalias_show @ 001008a8 size=36
// signature: undefined modalias_show(void)
// callers: []
//------------------------------------------------------------

void modalias_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  of_device_modalias(param_1,param_3,0x1000);
  return;
}



//------------------------------------------------------------
// init_module @ 00100980 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  bus_register(&dp_aux_bus_type);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001009a8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  bus_unregister(&dp_aux_bus_type);
  return;
}



//------------------------------------------------------------
// device_for_each_child_reverse @ 00102000 size=1
// signature: undefined device_for_each_child_reverse(void)
// callers: [of_dp_aux_depopulate_bus_void, of_dp_aux_depopulate_bus, devm_of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_for_each_child_reverse(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 00102010 size=1
// signature: undefined device_unregister(void)
// callers: [of_dp_aux_ep_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 00102018 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00102020 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00102038 size=1
// signature: undefined dev_set_name(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 00102040 size=1
// signature: undefined device_register(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102048 size=1
// signature: undefined _dev_err(void)
// callers: [of_dp_aux_populate_bus, dp_aux_ep_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00102050 size=1
// signature: undefined put_device(void)
// callers: [of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_add_action @ 00102058 size=1
// signature: undefined devm_add_action(void)
// callers: [devm_of_dp_aux_populate_bus]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_add_action(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_register @ 00102060 size=1
// signature: undefined driver_register(void)
// callers: [__dp_aux_dp_driver_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 00102068 size=1
// signature: undefined driver_unregister(void)
// callers: [dp_aux_dp_driver_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 00102070 size=1
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
// bus_unregister @ 00102078 size=1
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
// of_match_device @ 00102080 size=1
// signature: undefined of_match_device(void)
// callers: [dp_aux_ep_match]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_attach @ 00102088 size=1
// signature: undefined dev_pm_domain_attach(void)
// callers: [dp_aux_ep_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_attach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_err_probe @ 00102090 size=1
// signature: undefined dev_err_probe(void)
// callers: [dp_aux_ep_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_err_probe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_domain_detach @ 00102098 size=1
// signature: undefined dev_pm_domain_detach(void)
// callers: [dp_aux_ep_remove, dp_aux_ep_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_domain_detach(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001020a0 size=1
// signature: undefined kfree(void)
// callers: [dp_aux_ep_dev_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_modalias @ 001020a8 size=1
// signature: undefined of_device_modalias(void)
// callers: [modalias_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_modalias(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



