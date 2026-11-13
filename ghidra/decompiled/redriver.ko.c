// Decompiled by Ghidra 12.2
// Program: redriver.ko
// Image base: 00100000

//------------------------------------------------------------
// usb_add_redriver @ 0010029c size=176
// signature: undefined usb_add_redriver(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_add_redriver(undefined **param_1)

{
  undefined *puVar1;
  ulong uVar2;
  undefined **ppuVar3;
  undefined8 uVar4;
  
  if ((param_1[2] == (undefined *)0x0) || (*(char *)(param_1 + 10) != '\0')) {
    uVar4 = 0xffffffea;
  }
  else {
    _raw_spin_lock(&usb_rediver_lock);
    puVar1 = PTR_usb_redriver_list_001007d0;
    ppuVar3 = &usb_redriver_list;
    do {
      ppuVar3 = (undefined **)*ppuVar3;
      if (ppuVar3 == &usb_redriver_list) {
        uVar2 = __list_add_valid(param_1,PTR_usb_redriver_list_001007d0,&usb_redriver_list);
        uVar4 = 0;
        if ((uVar2 & 1) != 0) {
          PTR_usb_redriver_list_001007d0 = (undefined *)param_1;
          *param_1 = (undefined *)&usb_redriver_list;
          param_1[1] = puVar1;
          *(undefined ***)puVar1 = param_1;
        }
        goto LAB_00100328;
      }
    } while (ppuVar3 != param_1);
    uVar4 = 0xffffffef;
LAB_00100328:
    _raw_spin_unlock(&usb_rediver_lock);
  }
  return uVar4;
}



//------------------------------------------------------------
// usb_remove_redriver @ 00100350 size=128
// signature: undefined usb_remove_redriver(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_remove_redriver(long *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 uVar4;
  
  _raw_spin_lock(&usb_rediver_lock);
  if ((char)param_1[10] == '\0') {
    uVar3 = __list_del_entry_valid(param_1);
    if ((uVar3 & 1) != 0) {
      lVar1 = *param_1;
      plVar2 = (long *)param_1[1];
      *(long **)(lVar1 + 8) = plVar2;
      *plVar2 = lVar1;
    }
    uVar4 = 0;
    *param_1 = -0x2152ffffffffff00;
    param_1[1] = -0x2152fffffffffede;
  }
  else {
    uVar4 = 0xffffffea;
  }
  _raw_spin_unlock(&usb_rediver_lock);
  return uVar4;
}



//------------------------------------------------------------
// usb_get_redriver_by_phandle @ 001003d4 size=224
// signature: undefined usb_get_redriver_by_phandle(void)
// callers: []
//------------------------------------------------------------

undefined ** usb_get_redriver_by_phandle(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  undefined *puVar1;
  long lVar2;
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined *local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = (undefined *)0x0;
  uStack_70 = 0;
  iVar3 = __of_parse_phandle_with_args(param_1,param_2,0,0,param_3,&local_78);
  puVar1 = local_78;
  if (iVar3 != 0) {
    puVar1 = (undefined *)0x0;
  }
  uVar4 = of_device_is_available(puVar1);
  ppuVar5 = (undefined **)0x0;
  if ((uVar4 & 1) != 0) {
    _raw_spin_lock(&usb_rediver_lock);
    ppuVar5 = &usb_redriver_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &usb_redriver_list) {
        ppuVar5 = (undefined **)0xfffffffffffffdfb;
        goto LAB_00100478;
      }
    } while (ppuVar5[2] != puVar1);
    *(undefined1 *)(ppuVar5 + 10) = 1;
LAB_00100478:
    _raw_spin_unlock(&usb_rediver_lock);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return ppuVar5;
}



//------------------------------------------------------------
// usb_put_redriver @ 001004b8 size=108
// signature: undefined usb_put_redriver(void)
// callers: []
//------------------------------------------------------------

void usb_put_redriver(long param_1)

{
  code *pcVar1;
  
  if (param_1 != 0) {
    _raw_spin_lock(&usb_rediver_lock);
    *(undefined1 *)(param_1 + 0x50) = 0;
    _raw_spin_unlock(&usb_rediver_lock);
    pcVar1 = *(code **)(param_1 + 0x48);
    if (pcVar1 != (code *)0x0) {
      if (*(int *)(pcVar1 + -4) != -0x5435c021) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100510);
        (*pcVar1)();
      }
      (*pcVar1)(param_1);
    }
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_release_lanes @ 00100528 size=64
// signature: undefined usb_redriver_release_lanes(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_release_lanes(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x18), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x692dbc82) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100558);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_notify_connect @ 0010056c size=64
// signature: undefined usb_redriver_notify_connect(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_notify_connect(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x20), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x20deb8f0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10059c);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_notify_disconnect @ 001005b0 size=64
// signature: undefined usb_redriver_notify_disconnect(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_notify_disconnect(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x28), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x36bc0442) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1005e0);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_gadget_pullup_enter @ 001005f4 size=64
// signature: undefined usb_redriver_gadget_pullup_enter(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_gadget_pullup_enter(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x30), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x20deb8f0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100624);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_gadget_pullup_exit @ 00100638 size=64
// signature: undefined usb_redriver_gadget_pullup_exit(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_gadget_pullup_exit(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x38), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != -0x20deb8f0) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100668);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// usb_redriver_host_powercycle @ 0010067c size=64
// signature: undefined usb_redriver_host_powercycle(void)
// callers: []
//------------------------------------------------------------

void usb_redriver_host_powercycle(long param_1)

{
  code *pcVar1;
  
  if ((param_1 != 0) && (pcVar1 = *(code **)(param_1 + 0x40), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x36bc0442) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1006ac);
      (*pcVar1)();
    }
    (*pcVar1)();
  }
  return;
}



//------------------------------------------------------------
// _raw_spin_lock @ 00101000 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [usb_get_redriver_by_phandle, usb_put_redriver, usb_remove_redriver, usb_add_redriver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00101008 size=1
// signature: undefined __list_add_valid(void)
// callers: [usb_add_redriver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00101010 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [usb_get_redriver_by_phandle, usb_put_redriver, usb_remove_redriver, usb_add_redriver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00101018 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [usb_remove_redriver]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00101020 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [usb_get_redriver_by_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_available @ 00101028 size=1
// signature: undefined of_device_is_available(void)
// callers: [usb_get_redriver_by_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00101030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [usb_get_redriver_by_phandle]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



