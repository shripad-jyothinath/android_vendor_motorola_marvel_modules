// Decompiled by Ghidra 12.2
// Program: smp2p_sleepstate.ko
// Image base: 00100000

//------------------------------------------------------------
// smp2p_sleepstate_probe @ 001000e4 size=380
// signature: undefined smp2p_sleepstate_probe(void)
// callers: []
//------------------------------------------------------------

void smp2p_sleepstate_probe(long param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined8 uVar5;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  lVar1 = param_1 + 0x10;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  local_3c = 0;
  uVar4 = qcom_smem_state_get(lVar1,0,&local_3c);
  state = uVar4;
  if (uVar4 < 0xfffffffffffff001) {
    qcom_smem_state_update_bits(uVar4,0x1000,0x1000);
    local_3c = register_pm_notifier(&sleepstate_pm_nb);
    if (local_3c == 0) {
      notify_ws = wakeup_source_register(lVar1,"smp2p-sleepstate");
      if (notify_ws == 0) {
        local_3c = 0xfffffff4;
      }
      else {
        iVar3 = of_irq_get_byname(uVar5,"smp2p-sleepstate-in");
        if (iVar3 < 1) {
          _dev_err(lVar1,"failed to get irq for smp2p_sleep_state\n");
          local_3c = 0xfffffdfb;
        }
        else {
          uVar4 = devm_request_threaded_irq
                            (lVar1,iVar3,0,smp2p_sleepstate_handler,0x6003,"smp2p_sleepstate",lVar1)
          ;
          local_3c = (uint)uVar4;
          if (local_3c == 0) goto LAB_001001ec;
          _dev_err(lVar1,"fail to register smp2p threaded_irq=%d\n",iVar3);
        }
        wakeup_source_unregister(notify_ws);
      }
      unregister_pm_notifier(&sleepstate_pm_nb);
    }
    else {
      _dev_err(lVar1,"%s: power state notif error %d\n","smp2p_sleepstate_probe",local_3c);
    }
    uVar4 = (ulong)local_3c;
  }
LAB_001001ec:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// smp2p_sleepstate_handler @ 00100264 size=48
// signature: undefined smp2p_sleepstate_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 smp2p_sleepstate_handler(void)

{
  pm_wakeup_ws_event(notify_ws,200,0);
  return 1;
}



//------------------------------------------------------------
// sleepstate_pm_notifier @ 00100298 size=72
// signature: undefined sleepstate_pm_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 sleepstate_pm_notifier(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 3) {
    uVar1 = 0;
  }
  else {
    if (param_2 != 4) {
      return 0;
    }
    uVar1 = 0x1000;
  }
  qcom_smem_state_update_bits(state,0x1000,uVar1);
  return 0;
}



//------------------------------------------------------------
// init_module @ 001002e4 size=92
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __platform_driver_register(&smp2p_sleepstate_driver,&__this_module);
  if (iVar1 != 0) {
    _printk(&DAT_001005d4,"smp2p_sleepstate_init",iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// __platform_driver_register @ 00101000 size=1
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
// _printk @ 00101008 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_get @ 00101010 size=1
// signature: undefined qcom_smem_state_get(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_state_update_bits @ 00101018 size=1
// signature: undefined qcom_smem_state_update_bits(void)
// callers: [smp2p_sleepstate_probe, sleepstate_pm_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_state_update_bits(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00101020 size=1
// signature: undefined register_pm_notifier(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 00101028 size=1
// signature: undefined wakeup_source_register(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_irq_get_byname @ 00101030 size=1
// signature: undefined of_irq_get_byname(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_irq_get_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00101038 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00101040 size=1
// signature: undefined _dev_err(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 00101048 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 00101050 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [smp2p_sleepstate_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 00101060 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [smp2p_sleepstate_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



