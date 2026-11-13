// Decompiled by Ghidra 12.2
// Program: gh_irq_lend.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_irq_lend_v2 @ 001003b4 size=448
// signature: undefined gh_irq_lend_v2(void)
// callers: []
//------------------------------------------------------------

int gh_irq_lend_v2(uint param_1,undefined4 param_2,undefined4 param_3,long param_4,
                  undefined8 param_5)

{
  int *piVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  undefined4 local_6c;
  long local_68;
  
  lVar2 = sp_el0;
  iVar5 = -0x16;
  local_68 = *(long *)(lVar2 + 0x638);
  local_6c = 0;
  if ((param_1 < 0x38) && (param_4 != 0)) {
    uVar7 = (ulong)param_1;
    iVar4 = gh_rm_irq_to_virq(param_3,&local_6c);
    if (iVar4 == 0) {
      uVar6 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
      uVar8 = uVar7 * 0x28;
      if (uVar8 < 0x8a1) {
        piVar1 = &DAT_00101068 + uVar7 * 10;
        if (*piVar1 != 0) {
          _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar6);
          iVar5 = -0x16;
          goto LAB_00100530;
        }
        iVar5 = ghd_rm_get_vmid(param_2,&gh_irq_entries + uVar7 * 0x14);
        if (iVar5 == 0) {
          if (((uVar7 * 0x28 < 0x8b9) &&
              ((&DAT_00101050)[uVar7 * 5] = param_4, uVar7 * 0x28 < 0x8a9)) &&
             ((&DAT_00101060)[uVar7 * 5] = param_5, uVar8 < 0x8a1)) {
            *piVar1 = 1;
            _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar6);
            if ((uVar7 * 0x28 < 0x8c1) && (param_1 != 0x38)) {
              iVar5 = gh_rm_vm_irq_lend((&gh_irq_entries)[uVar7 * 0x14],local_6c,param_1,
                                        &DAT_0010106c + uVar7 * 10);
              goto LAB_00100530;
            }
          }
        }
        else if (uVar8 < 0x8a1) {
          *piVar1 = 0;
          _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar6);
          goto LAB_00100530;
        }
      }
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100574);
      (*pcVar3)();
    }
  }
LAB_00100530:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// gh_irq_lend @ 00100578 size=72
// signature: undefined gh_irq_lend(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_lend(uint param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = 0xffffffea;
  if ((param_1 < 0x38) && (param_4 != 0)) {
    if (0x8b0 < ((ulong)param_1 + (ulong)param_1 * 4) * 8) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x1005c0);
      (*pcVar1)();
    }
    uVar2 = 0;
    *(long *)(&DAT_00101058 + (ulong)param_1 * 0x28) = param_4;
  }
  return uVar2;
}



//------------------------------------------------------------
// gh_irq_lend_notify @ 001005c4 size=148
// signature: undefined gh_irq_lend_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_lend_notify(uint param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (0x37 < param_1) {
    return 0xffffffea;
  }
  uVar3 = (ulong)param_1;
  if ((uVar3 + (ulong)param_1 * 4) * 8 < 0x8a1) {
    if ((&DAT_00101068)[uVar3 * 10] == 0) {
      return 0xffffffea;
    }
    if (((uVar3 * 0x28 < 0x8c1) && (param_1 != 0x38)) && (uVar3 * 0x28 < 0x89d)) {
      uVar2 = gh_rm_vm_irq_lend_notify((&gh_irq_entries)[uVar3 * 0x14],(&DAT_0010106c)[uVar3 * 10]);
      return uVar2;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x100658);
  (*pcVar1)();
}



//------------------------------------------------------------
// gh_irq_reclaim @ 0010065c size=156
// signature: undefined gh_irq_reclaim(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_reclaim(uint param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (0x37 < param_1) {
    return 0xffffffea;
  }
  uVar4 = (ulong)param_1;
  lVar1 = uVar4 + (ulong)param_1 * 4;
  uVar5 = lVar1 * 8;
  if (uVar5 < 0x8a1) {
    if (((&DAT_00101068)[lVar1 * 2] | 2) != 3) {
      return 0xffffffea;
    }
    if (uVar4 * 0x28 < 0x89d) {
      uVar3 = gh_rm_vm_irq_reclaim((&DAT_0010106c)[uVar4 * 10]);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      if (uVar5 < 0x8a1) {
        (&DAT_00101068)[lVar1 * 2] = 0;
        return 0;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x1006f8);
  (*pcVar2)();
}



//------------------------------------------------------------
// gh_irq_wait_for_lend_v2 @ 001006fc size=260
// signature: undefined gh_irq_wait_for_lend_v2(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_wait_for_lend_v2(uint param_1,undefined4 param_2,long param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 uVar5;
  ulong uVar6;
  
  uVar5 = 0xffffffea;
  if ((param_1 < 0x38) && (param_3 != 0)) {
    uVar6 = (ulong)param_1;
    uVar3 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
    lVar1 = uVar6 + (ulong)param_1 * 4;
    uVar4 = lVar1 * 8;
    if (0x8a0 < uVar4) {
LAB_001007fc:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x100800);
      (*pcVar2)();
    }
    if ((&DAT_00101068)[lVar1 * 2] == 0) {
      if ((((0x8c0 < (uVar6 * 0x28 | 4)) ||
           ((&DAT_0010104c)[uVar6 * 10] = param_2, 0x8b8 < uVar6 * 0x28)) ||
          ((&DAT_00101050)[uVar6 * 5] = param_3, 0x8a8 < uVar6 * 0x28)) ||
         ((&DAT_00101060)[uVar6 * 5] = param_4, 0x8a0 < uVar4)) goto LAB_001007fc;
      uVar5 = 0;
      (&DAT_00101068)[lVar1 * 2] = 2;
    }
    else {
      uVar5 = 0xffffffea;
    }
    _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar3);
  }
  return uVar5;
}



//------------------------------------------------------------
// gh_irq_wait_for_lend @ 00100804 size=8
// signature: undefined gh_irq_wait_for_lend(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_wait_for_lend(void)

{
  return 0;
}



//------------------------------------------------------------
// gh_irq_accept @ 00100810 size=300
// signature: undefined gh_irq_accept(void)
// callers: []
//------------------------------------------------------------

ulong gh_irq_accept(uint param_1,ulong param_2,undefined4 param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  ulong uVar6;
  int local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  if (param_1 < 0x38) {
    uVar6 = (ulong)param_1;
    lVar1 = uVar6 + (ulong)param_1 * 4;
    uVar5 = lVar1 * 8;
    if (0x8a0 < uVar5) goto LAB_00100938;
    if ((&DAT_00101068)[lVar1 * 2] == 5) {
      uVar4 = param_2 & 0xffffffff;
      if ((int)param_2 == -1) {
        local_4c = -1;
      }
      else {
        iVar3 = gh_rm_irq_to_virq(uVar4,&local_4c);
        if (iVar3 != 0) goto LAB_00100894;
      }
      if (0x89c < uVar6 * 0x28) {
LAB_00100938:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x10093c);
        (*pcVar2)();
      }
      uVar6 = gh_rm_vm_irq_accept((&DAT_0010106c)[uVar6 * 10],local_4c);
      local_4c = (int)uVar6;
      if (local_4c < 0) {
        uVar4 = uVar6 & 0xffffffff;
      }
      else {
        if ((int)param_2 == -1) {
          uVar4 = gh_rm_virq_to_irq(uVar6,param_3);
          uVar4 = uVar4 & 0xffffffff;
        }
        if (0x8a0 < uVar5) goto LAB_00100938;
        (&DAT_00101068)[lVar1 * 2] = 4;
      }
      goto LAB_00100898;
    }
  }
LAB_00100894:
  uVar4 = 0xffffffea;
LAB_00100898:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// gh_irq_accept_notify @ 00100940 size=152
// signature: undefined gh_irq_accept_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_accept_notify(uint param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (0x37 < param_1) {
    return 0xffffffea;
  }
  uVar3 = (ulong)param_1;
  if ((uVar3 + (ulong)param_1 * 4) * 8 < 0x8a1) {
    if ((&DAT_00101068)[uVar3 * 10] != 4) {
      return 0xffffffea;
    }
    if (((uVar3 * 0x28 < 0x8c1) && (param_1 != 0x38)) && (uVar3 * 0x28 < 0x89d)) {
      uVar2 = gh_rm_vm_irq_accept_notify
                        ((&gh_irq_entries)[uVar3 * 0x14],(&DAT_0010106c)[uVar3 * 10]);
      return uVar2;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x1009d8);
  (*pcVar1)();
}



//------------------------------------------------------------
// gh_irq_release @ 001009dc size=156
// signature: undefined gh_irq_release(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_release(uint param_1)

{
  long lVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (0x37 < param_1) {
    return 0xffffffea;
  }
  uVar4 = (ulong)param_1;
  lVar1 = uVar4 + (ulong)param_1 * 4;
  uVar5 = lVar1 * 8;
  if (uVar5 < 0x8a1) {
    if ((&DAT_00101068)[lVar1 * 2] != 4) {
      return 0xffffffea;
    }
    if (uVar4 * 0x28 < 0x89d) {
      uVar3 = gh_rm_vm_irq_release((&DAT_0010106c)[uVar4 * 10]);
      if ((int)uVar3 != 0) {
        return uVar3;
      }
      if (uVar5 < 0x8a1) {
        (&DAT_00101068)[lVar1 * 2] = 2;
        return 0;
      }
    }
  }
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x100a78);
  (*pcVar2)();
}



//------------------------------------------------------------
// gh_irq_release_notify @ 00100a7c size=156
// signature: undefined gh_irq_release_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_release_notify(uint param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  ulong uVar3;
  
  if (0x37 < param_1) {
    return 0xffffffea;
  }
  uVar3 = (ulong)param_1;
  if ((uVar3 + (ulong)param_1 * 4) * 8 < 0x8a1) {
    if ((&DAT_00101068)[uVar3 * 10] != 4 && (&DAT_00101068)[uVar3 * 10] != 2) {
      return 0xffffffea;
    }
    if (((uVar3 * 0x28 < 0x8c1) && (param_1 != 0x38)) && (uVar3 * 0x28 < 0x89d)) {
      uVar2 = gh_rm_vm_irq_release_notify
                        ((&gh_irq_entries)[uVar3 * 0x14],(&DAT_0010106c)[uVar3 * 10]);
      return uVar2;
    }
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(1,0x100b18);
  (*pcVar1)();
}



//------------------------------------------------------------
// cleanup_module @ 00100b1c size=60
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gh_rm_unregister_notifier(&gh_irq_lent_nb);
  gh_rm_unregister_notifier(&gh_irq_released_accepted_nb);
  gh_unregister_vm_notifier(&gh_irq_vm_nb);
  return;
}



//------------------------------------------------------------
// gh_irq_lent_nb_handler @ 00100b5c size=392
// signature: undefined gh_irq_lent_nb_handler(void)
// callers: []
//------------------------------------------------------------

int gh_irq_lent_nb_handler(undefined8 param_1,long param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined4 *puVar8;
  int local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  iVar4 = 0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = 0;
  if (param_2 == 0x56100011) {
    iVar4 = gh_rm_get_vm_name(*param_3,&local_3c);
    if (iVar4 == 0) {
      uVar6 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
      uVar7 = 0;
      puVar8 = &DAT_0010106c;
      do {
        if (((puVar8[-1] == 5 || puVar8[-1] == 2) && (uVar7 == *(uint *)(param_3 + 4))) &&
           ((puVar8[-8] == 7 || (puVar8[-8] == local_3c)))) {
          *(undefined2 *)(puVar8 + -9) = *param_3;
          uVar1 = *(undefined4 *)(param_3 + 2);
          puVar8[-1] = 5;
          *puVar8 = uVar1;
          _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar6);
          if (*(int *)(*(code **)(puVar8 + -7) + -4) != 0x54a5a246) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c94);
            (*pcVar3)();
          }
          (**(code **)(puVar8 + -7))(*(undefined8 *)(puVar8 + -3),0x56100011,uVar7 & 0xffffffff);
          iVar4 = 1;
          goto LAB_00100cb0;
        }
        uVar7 = uVar7 + 1;
        puVar8 = puVar8 + 10;
      } while (uVar7 != 0x38);
      _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar6);
      iVar4 = 0;
    }
    else {
      iVar5 = ___ratelimit(gh_irq_lent_nb_handler__rs,"gh_irq_lent_nb_handler");
      if (iVar5 != 0) {
        _printk(&DAT_00101ac3,"gh_irq_lent_nb_handler",*param_3);
      }
    }
  }
LAB_00100cb0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_irq_vm_nb_handler @ 00100ce8 size=268
// signature: undefined gh_irq_vm_nb_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_vm_nb_handler(undefined8 param_1,long param_2,short *param_3)

{
  short sVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  uint *puVar5;
  
  if ((param_3 == (short *)0x0) || (param_2 != 3)) {
    return 0;
  }
  uVar4 = 0;
  sVar1 = *param_3;
  puVar5 = &DAT_00101068;
  do {
    uVar3 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
    if (((sVar1 == (short)puVar5[-8]) && (*puVar5 < 6)) &&
       ((1 << (ulong)(*puVar5 & 0x1f) & 0x3aU) != 0)) {
      _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar3);
      iVar2 = gh_rm_vm_irq_reclaim(puVar5[1]);
      if (iVar2 == 0) {
        uVar3 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
        *puVar5 = 0;
        goto LAB_00100d54;
      }
      _printk(&DAT_00101ae4,uVar4 & 0xffffffff,(short)puVar5[-8]);
    }
    else {
LAB_00100d54:
      _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar3);
    }
    uVar4 = uVar4 + 1;
    puVar5 = puVar5 + 10;
    if (uVar4 == 0x38) {
      _printk(&DAT_00101a9f,sVar1);
      return 0;
    }
  } while( true );
}



//------------------------------------------------------------
// gh_irq_released_accepted_nb_handler @ 00100df8 size=340
// signature: undefined gh_irq_released_accepted_nb_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_irq_released_accepted_nb_handler(undefined8 param_1,long param_2,int *param_3)

{
  bool bVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  long lVar4;
  code *pcVar5;
  int *piVar6;
  
  if (0xfffffffffffffffd < param_2 - 0x56100014U) {
    uVar2 = _raw_spin_lock_irqsave(&gh_irq_lend_lock);
    piVar6 = &DAT_0010106c;
    lVar4 = 0;
    do {
      if (piVar6[-1] == 4 || piVar6[-1] == 1) {
        if (param_2 == 0x56100013) {
          if (*param_3 == *piVar6) {
            piVar6[-1] = 4;
            _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar2);
            pcVar5 = *(code **)(piVar6 + -7);
            uVar2 = *(undefined8 *)(piVar6 + -3);
            uVar3 = 0x56100013;
            goto LAB_00100f24;
          }
        }
        else if ((param_2 == 0x56100012) && (*param_3 == *piVar6)) {
          piVar6[-1] = 3;
          _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar2);
          pcVar5 = *(code **)(piVar6 + -7);
          uVar2 = *(undefined8 *)(piVar6 + -3);
          uVar3 = 0x56100012;
LAB_00100f24:
          if (*(int *)(pcVar5 + -4) != 0x54a5a246) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x100f40);
            (*pcVar5)();
          }
          (*pcVar5)(uVar2,uVar3,-(int)lVar4);
          return 1;
        }
      }
      piVar6 = piVar6 + 10;
      bVar1 = lVar4 != -0x37;
      lVar4 = lVar4 + -1;
    } while (bVar1);
    _raw_spin_unlock_irqrestore(&gh_irq_lend_lock,uVar2);
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00101004 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  int iVar1;
  
  iVar1 = gh_rm_register_notifier(&gh_irq_lent_nb);
  if ((iVar1 == 0) && (iVar1 = gh_register_vm_notifier(&gh_irq_vm_nb), iVar1 == 0)) {
    gh_rm_register_notifier(&gh_irq_released_accepted_nb);
  }
  return;
}



//------------------------------------------------------------
// gh_rm_irq_to_virq @ 00103000 size=1
// signature: undefined gh_rm_irq_to_virq(void)
// callers: [gh_irq_accept, gh_irq_lend_v2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_irq_to_virq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103008 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gh_irq_released_accepted_nb_handler, gh_irq_wait_for_lend_v2, gh_irq_lend_v2, gh_irq_lent_nb_handler, gh_irq_vm_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103010 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gh_irq_released_accepted_nb_handler, gh_irq_wait_for_lend_v2, gh_irq_lend_v2, gh_irq_lent_nb_handler, gh_irq_vm_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ghd_rm_get_vmid @ 00103018 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_irq_lend_v2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_lend @ 00103020 size=1
// signature: undefined gh_rm_vm_irq_lend(void)
// callers: [gh_irq_lend_v2]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_lend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_irq_accept, gh_irq_lend_v2, gh_irq_lent_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_lend_notify @ 00103030 size=1
// signature: undefined gh_rm_vm_irq_lend_notify(void)
// callers: [gh_irq_lend_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_lend_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_reclaim @ 00103038 size=1
// signature: undefined gh_rm_vm_irq_reclaim(void)
// callers: [gh_irq_reclaim, gh_irq_vm_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_reclaim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_accept @ 00103040 size=1
// signature: undefined gh_rm_vm_irq_accept(void)
// callers: [gh_irq_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_accept(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_virq_to_irq @ 00103048 size=1
// signature: undefined gh_rm_virq_to_irq(void)
// callers: [gh_irq_accept]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_virq_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_accept_notify @ 00103050 size=1
// signature: undefined gh_rm_vm_irq_accept_notify(void)
// callers: [gh_irq_accept_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_accept_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_release @ 00103058 size=1
// signature: undefined gh_rm_vm_irq_release(void)
// callers: [gh_irq_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_release(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_irq_release_notify @ 00103060 size=1
// signature: undefined gh_rm_vm_irq_release_notify(void)
// callers: [gh_irq_release_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_irq_release_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00103068 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_register_vm_notifier @ 00103070 size=1
// signature: undefined gh_register_vm_notifier(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_register_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00103078 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_unregister_vm_notifier @ 00103080 size=1
// signature: undefined gh_unregister_vm_notifier(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_unregister_vm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_get_vm_name @ 00103088 size=1
// signature: undefined gh_rm_get_vm_name(void)
// callers: [gh_irq_lent_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_get_vm_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00103090 size=1
// signature: undefined ___ratelimit(void)
// callers: [gh_irq_lent_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103098 size=1
// signature: undefined _printk(void)
// callers: [gh_irq_lent_nb_handler, gh_irq_vm_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



