// Decompiled by Ghidra 12.2
// Program: panel_event_notifier.ko
// Image base: 00100000

//------------------------------------------------------------
// panel_event_notifier_register @ 00100124 size=288
// signature: undefined panel_event_notifier_register(void)
// callers: []
//------------------------------------------------------------

long * panel_event_notifier_register
                 (int param_1,uint param_2,undefined8 param_3,long param_4,undefined8 param_5)

{
  long *plVar1;
  code *pcVar2;
  undefined *puVar3;
  ulong uVar4;
  
  if ((param_1 - 1U < 2) && (param_4 != 0)) {
    if (param_2 < 4) {
      mutex_lock(&panel_event_notifier_entries_lock);
      uVar4 = (ulong)param_2;
      plVar1 = &panel_event_notifier_entries + uVar4 * 4;
      if (*plVar1 != 0) {
        mutex_unlock(&panel_event_notifier_entries_lock);
        return (long *)0xffffffffffffffef;
      }
      if ((((0x80 < (uVar4 << 5 | 0x10)) || ((&DAT_001006a0)[uVar4 * 4] = param_3, 3 < param_2)) ||
          (*plVar1 = param_4, 0x80 < (uVar4 << 5 | 8))) ||
         ((&DAT_00100698)[uVar4 * 4] = param_5, 0x80 < (uVar4 << 5 | 0x18))) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x100244);
        (*pcVar2)();
      }
      (&DAT_001006a8)[uVar4 * 8] = param_1;
      mutex_unlock(&panel_event_notifier_entries_lock);
      return plVar1;
    }
    puVar3 = &DAT_001005dd;
  }
  else {
    puVar3 = &DAT_00100629;
  }
  _printk(puVar3);
  return (long *)0xffffffffffffffea;
}



//------------------------------------------------------------
// panel_event_notifier_unregister @ 00100248 size=76
// signature: undefined panel_event_notifier_unregister(void)
// callers: []
//------------------------------------------------------------

void panel_event_notifier_unregister(undefined8 *param_1)

{
  if (param_1 != (undefined8 *)0x0) {
    mutex_lock(&panel_event_notifier_entries_lock);
    *(undefined4 *)(param_1 + 3) = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    mutex_unlock(&panel_event_notifier_entries_lock);
  }
  return;
}



//------------------------------------------------------------
// panel_event_notification_trigger @ 00100298 size=684
// signature: undefined panel_event_notification_trigger(void)
// callers: []
//------------------------------------------------------------

void panel_event_notification_trigger(int param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if (1 < param_1 - 1U) {
    _printk(&DAT_0010060b);
    return;
  }
  mutex_lock(&panel_event_notifier_entries_lock);
  uVar1 = DAT_00100698;
  pcVar2 = panel_event_notifier_entries;
  if (*(long *)(param_2 + 0x10) == DAT_001006a0) {
    if (DAT_001006a8 != param_1) {
      _printk(&DAT_001005b8,DAT_001006a8,param_1);
      goto LAB_001002e0;
    }
    mutex_unlock(&panel_event_notifier_entries_lock);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x4c9ee3d2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8236,0x100340);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,param_2,uVar1);
    }
  }
  else {
LAB_001002e0:
    mutex_unlock(&panel_event_notifier_entries_lock);
  }
  mutex_lock(&panel_event_notifier_entries_lock);
  uVar1 = DAT_001006b8;
  pcVar2 = DAT_001006b0;
  if (*(long *)(param_2 + 0x10) == DAT_001006c0) {
    if (DAT_001006c8 != param_1) {
      _printk(&DAT_001005b8,DAT_001006c8,param_1);
      goto LAB_00100364;
    }
    mutex_unlock(&panel_event_notifier_entries_lock);
    if (pcVar2 != (code *)0x0) {
      if (*(int *)(pcVar2 + -4) != -0x4c9ee3d2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8236,0x1003c4);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,param_2,uVar1);
    }
  }
  else {
LAB_00100364:
    mutex_unlock(&panel_event_notifier_entries_lock);
  }
  mutex_lock(&panel_event_notifier_entries_lock);
  uVar1 = DAT_001006d8;
  pcVar2 = DAT_001006d0;
  if (*(long *)(param_2 + 0x10) == DAT_001006e0) {
    if (DAT_001006e8 == param_1) {
      mutex_unlock(&panel_event_notifier_entries_lock);
      if (pcVar2 != (code *)0x0) {
        if (*(int *)(pcVar2 + -4) != -0x4c9ee3d2) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8236,0x100448);
          (*pcVar2)();
        }
        (*pcVar2)(param_1,param_2,uVar1);
      }
      goto LAB_0010044c;
    }
    _printk(&DAT_001005b8,DAT_001006e8,param_1);
  }
  mutex_unlock(&panel_event_notifier_entries_lock);
LAB_0010044c:
  mutex_lock(&panel_event_notifier_entries_lock);
  uVar1 = DAT_001006f8;
  pcVar2 = DAT_001006f0;
  if (*(long *)(param_2 + 0x10) == DAT_00100700) {
    if (DAT_00100708 == param_1) {
      mutex_unlock(&panel_event_notifier_entries_lock);
      if (pcVar2 == (code *)0x0) {
        return;
      }
      if (*(int *)(pcVar2 + -4) != -0x4c9ee3d2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8236,0x1004cc);
        (*pcVar2)();
      }
      (*pcVar2)(param_1,param_2,uVar1);
      return;
    }
    _printk(&DAT_001005b8,DAT_00100708,param_1);
  }
  mutex_unlock(&panel_event_notifier_entries_lock);
  return;
}



//------------------------------------------------------------
// init_module @ 001005a8 size=8
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 001005b4 size=4
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  return;
}



//------------------------------------------------------------
// mutex_lock @ 00101000 size=1
// signature: undefined mutex_lock(void)
// callers: [panel_event_notifier_register, panel_event_notification_trigger, panel_event_notifier_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00101008 size=1
// signature: undefined mutex_unlock(void)
// callers: [panel_event_notifier_register, panel_event_notification_trigger, panel_event_notifier_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00101010 size=1
// signature: undefined _printk(void)
// callers: [panel_event_notifier_register, panel_event_notification_trigger]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



