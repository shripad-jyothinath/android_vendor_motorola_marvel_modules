// Decompiled by Ghidra 12.2
// Program: hvc_gunyah.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_hvc_put_work_fn @ 0010029c size=408
// signature: undefined gh_hvc_put_work_fn(void)
// callers: [gh_hvc_flush, gh_hvc_notify_del]
//------------------------------------------------------------

void gh_hvc_put_work_fn(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined2 local_144 [2];
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined8 local_f0;
  undefined8 uStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  long local_58;
  
  lVar2 = sp_el0;
  puVar7 = (undefined4 *)(param_1 + -0x838);
  local_58 = *(long *)(lVar2 + 0x638);
  local_144[0] = 0;
  local_60 = 0;
  local_70 = 0;
  uStack_68 = 0;
  local_80 = 0;
  uStack_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  uStack_e8 = 0;
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = 0;
  uStack_108 = 0;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  iVar3 = ghd_rm_get_vmid(*puVar7,local_144);
  if (iVar3 == 0) {
    piVar6 = (int *)(param_1 + -0x418);
    if (*piVar6 != *(int *)(param_1 + -0x414)) {
      do {
        uVar5 = _raw_spin_lock_irqsave(&fifo_lock);
        iVar3 = __kfifo_out(piVar6,&local_140,0xe4);
        _raw_spin_unlock_irqrestore(&fifo_lock,uVar5);
        if ((0 < iVar3) && (iVar3 = gh_rm_console_write(local_144[0],&local_140,iVar3), iVar3 != 0))
        {
          if ((gh_hvc_put_work_fn___already_done_1 & 1) == 0) {
            uVar1 = *puVar7;
            puVar4 = &DAT_00104c42;
            gh_hvc_put_work_fn___already_done_1 = 1;
            goto LAB_00100348;
          }
          break;
        }
      } while (*piVar6 != *(int *)(param_1 + -0x414));
    }
  }
  else if ((gh_hvc_put_work_fn___already_done & 1) == 0) {
    uVar1 = *puVar7;
    puVar4 = &DAT_00104aea;
    gh_hvc_put_work_fn___already_done = 1;
LAB_00100348:
    _printk(puVar4,"gh_hvc_put_work_fn",uVar1,iVar3);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_hvc_get_chars @ 00100438 size=156
// signature: undefined gh_hvc_get_chars(void)
// callers: []
//------------------------------------------------------------

undefined4 gh_hvc_get_chars(int param_1,undefined8 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  if (param_1 + 0xb8b1a6b8U < 7) {
    uVar2 = _raw_spin_lock_irqsave(&fifo_lock);
    uVar1 = __kfifo_out(&DAT_00100ef0 + (ulong)(param_1 + 0xb8b1a6b8U) * 0x10e,param_2,param_3);
    _raw_spin_unlock_irqrestore(&fifo_lock,uVar2);
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// gh_hvc_put_chars @ 001004d8 size=192
// signature: undefined gh_hvc_put_chars(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_hvc_put_chars(int param_1,undefined8 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  
  uVar1 = param_1 + 0xb8b1a6b8;
  if (uVar1 < 7) {
    uVar3 = _raw_spin_lock_irqsave(&fifo_lock);
    iVar2 = __kfifo_in(&DAT_00101308 + (ulong)uVar1 * 0x10e,param_2,param_3);
    _raw_spin_unlock_irqrestore(&fifo_lock,uVar3);
    if (0 < iVar2) {
      queue_work_on(0x20,_system_wq,&DAT_00101720 + (ulong)uVar1 * 0x10e);
    }
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_hvc_flush @ 0010059c size=184
// signature: undefined gh_hvc_flush(void)
// callers: []
//------------------------------------------------------------

void gh_hvc_flush(int param_1,ulong param_2)

{
  uint uVar1;
  long lVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined2 local_2c [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  uVar3 = 0;
  local_2c[0] = 0;
  if ((param_2 & 1) != 0) {
    uVar1 = param_1 + 0xb8b1a6b8;
    if (uVar1 < 7) {
      uVar3 = ghd_rm_get_vmid(uVar1,local_2c);
      if ((int)uVar3 == 0) {
        uVar4 = cancel_work_sync(&DAT_00101720 + (ulong)uVar1 * 0x10e);
        if ((uVar4 & 1) != 0) {
          gh_hvc_put_work_fn(&DAT_00101720 + (ulong)uVar1 * 0x10e);
        }
        uVar3 = gh_rm_console_flush(local_2c[0]);
      }
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// gh_hvc_notify_add @ 00100658 size=152
// signature: undefined gh_hvc_notify_add(void)
// callers: []
//------------------------------------------------------------

int gh_hvc_notify_add(undefined8 param_1,undefined4 param_2)

{
  long lVar1;
  int iVar2;
  undefined2 local_2c [2];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = 0;
  iVar2 = ghd_rm_get_vmid(param_2,local_2c);
  if (iVar2 == 0) {
    iVar2 = gh_rm_console_open(local_2c[0]);
  }
  else {
    _printk(&DAT_00104bb8,"gh_hvc_notify_add",param_2,iVar2);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_hvc_notify_del @ 001006f4 size=240
// signature: undefined gh_hvc_notify_del(void)
// callers: []
//------------------------------------------------------------

void gh_hvc_notify_del(undefined8 param_1,uint param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  ulong uVar5;
  undefined2 local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c[0] = 0;
  if (param_2 < 7) {
    uVar5 = (ulong)param_2;
    uVar4 = cancel_work_sync(&DAT_00101720 + (ulong)param_2 * 0x10e);
    if ((uVar4 & 1) != 0) {
      gh_hvc_put_work_fn(&DAT_00101720 + (ulong)param_2 * 0x10e);
    }
    iVar3 = ghd_rm_get_vmid(uVar5,local_3c);
    if (iVar3 == 0) {
      iVar3 = gh_rm_console_close(local_3c[0]);
      if (iVar3 != 0) {
        _printk(&DAT_00104bfe,"gh_hvc_notify_del",uVar5,iVar3);
      }
      if (0x3afc < uVar5 * 0x870) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1007e4);
        (*pcVar2)();
      }
      (&DAT_00100ef0)[uVar5 * 0x10e] = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gh_hvc_notify_console_chars @ 001007e8 size=448
// signature: undefined gh_hvc_notify_console_chars(void)
// callers: []
//------------------------------------------------------------

void gh_hvc_notify_console_chars(undefined8 param_1,long param_2,undefined2 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined8 uVar6;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  uVar6 = 0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  if (param_2 == 0x56100080) {
    iVar3 = gh_rm_get_vm_name(*param_3,&local_3c);
    if (iVar3 == 0) {
      uVar6 = _raw_spin_lock_irqsave(&fifo_lock);
      if (6 < local_3c) {
LAB_001009a0:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1009a4);
        (*pcVar2)();
      }
      uVar5 = __kfifo_in(&DAT_00100ef0 + (ulong)local_3c * 0x10e,param_3 + 2,param_3[1]);
      _raw_spin_unlock_irqrestore(&fifo_lock,uVar6);
      if ((int)uVar5 < 0) {
        iVar3 = ___ratelimit(gh_hvc_notify_console_chars__rs_6,"gh_hvc_notify_console_chars");
        if (iVar3 != 0) {
          _printk(&DAT_00104b83,param_3[1],local_3c,uVar5);
        }
      }
      else if ((uVar5 < (ushort)param_3[1]) &&
              (iVar3 = ___ratelimit(gh_hvc_notify_console_chars__rs_8,"gh_hvc_notify_console_chars")
              , iVar3 != 0)) {
        _printk(&DAT_00104b1e,(ushort)param_3[1] - uVar5,local_3c);
      }
      if (6 < local_3c) goto LAB_001009a0;
      if (0x3b10 < (ulong)local_3c * 0x870) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1009a8);
        (*pcVar2)();
      }
      iVar3 = hvc_poll((&gh_hvc_data)[(ulong)local_3c * 0x10e]);
      if (iVar3 != 0) {
        hvc_kick();
      }
    }
    else {
      iVar4 = ___ratelimit(gh_hvc_notify_console_chars__rs,"gh_hvc_notify_console_chars");
      if (iVar4 != 0) {
        _printk(&DAT_00104ca0,*param_3,iVar3);
      }
    }
    uVar6 = 1;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar6);
  }
  return;
}



//------------------------------------------------------------
// gh_hvc_vm_state @ 001009ac size=408
// signature: undefined gh_hvc_vm_state(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_hvc_vm_state(undefined8 param_1,long param_2,undefined2 *param_3)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  ulong uVar5;
  ulong *puVar6;
  ulong uVar7;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  iVar4 = gh_rm_get_vm_name(*param_3,&local_3c);
  uVar2 = local_3c;
  if (iVar4 == 0) {
    if (param_2 == 1) {
      if (6 < local_3c) {
LAB_00100b40:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100b44);
        (*pcVar3)();
      }
      uVar7 = (ulong)local_3c * 0x870;
      if (0x3b10 < uVar7) {
LAB_00100b3c:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x100b40);
        (*pcVar3)();
      }
      puVar6 = &gh_hvc_data + (ulong)local_3c * 0x10e;
      if (*puVar6 == 0) {
        uVar5 = hvc_alloc(local_3c + 0x474e5948,local_3c,&gh_hv_ops,0x100);
        if ((0x3b10 < uVar7) || (uVar2 == 7)) goto LAB_00100b3c;
        *puVar6 = uVar5;
        if ((0xfffffffffffff000 < uVar5) && ((int)uVar5 != 0)) {
          if ((0x3b10 < uVar7) || (uVar2 == 7)) goto LAB_00100b3c;
          *puVar6 = 0;
          _printk(&DAT_00104c7a);
        }
      }
    }
    else if (param_2 == 5) {
      if (6 < local_3c) goto LAB_00100b40;
      if (0x3b10 < (ulong)local_3c * 0x870) goto LAB_00100b3c;
      if ((&gh_hvc_data)[(ulong)local_3c * 0x10e] != 0) {
        hvc_remove();
        if (6 < local_3c) goto LAB_00100b40;
        if (0x3b10 < (ulong)local_3c * 0x870) goto LAB_00100b3c;
        (&gh_hvc_data)[(ulong)local_3c * 0x10e] = 0;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100b48 size=396
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  code *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  ulong uVar6;
  ulong *puVar7;
  
  lVar4 = 0;
  puVar5 = &DAT_00101738;
  do {
    puVar5[-3] = 0xfffffffe0;
    puVar5[-0x107] = puVar5 + -0x106;
    puVar5[-0x84] = puVar5 + -0x83;
    *(int *)(puVar5 + -0x10a) = (int)lVar4;
    puVar5[-0x109] = 0;
    puVar5[-0x108] = 0x1000003ff;
    puVar5[-0x86] = 0;
    lVar4 = lVar4 + 1;
    puVar5[-0x85] = 0x1000003ff;
    puVar5[-2] = puVar5 + -2;
    puVar5[-1] = puVar5 + -2;
    *puVar5 = gh_hvc_put_work_fn;
    puVar5 = puVar5 + 0x10e;
  } while (lVar4 != 7);
  hvc_gh_console_init();
  uVar6 = 0;
  puVar7 = &gh_hvc_data;
  while( true ) {
    uVar3 = hvc_alloc((int)uVar6 + 0x474e5948,uVar6 & 0xffffffff,&gh_hv_ops,0x100);
    *puVar7 = uVar3;
    if ((0xfffffffffffff000 < uVar3) && ((uVar3 & 0xffffffff) != 0)) break;
    uVar6 = uVar6 + 1;
    puVar7 = puVar7 + 0x10e;
    if (uVar6 == 7) {
      iVar2 = gh_rm_register_notifier(&gh_hvc_nb);
      if (iVar2 == 0) {
        iVar2 = gh_register_vm_notifier(&gh_hvc_vm_nb);
        if (iVar2 == 0) {
          return 0;
        }
        gh_rm_unregister_notifier(&gh_hvc_nb);
      }
      uVar6 = 7;
LAB_00100c7c:
      uVar3 = uVar6 + 1;
      uVar6 = uVar6 * 0x870;
      do {
        if (0x3b0 < uVar6 - 0x870 >> 4) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(1,0x100cd4);
          (*pcVar1)();
        }
        hvc_remove(*(undefined8 *)(uVar6 + 0x100670));
        *(undefined8 *)(uVar6 + 0x100670) = 0;
        uVar3 = uVar3 - 1;
        uVar6 = uVar6 - 0x870;
      } while (1 < uVar3);
      return 0;
    }
  }
  if ((int)uVar6 < 1) {
    return 0;
  }
  goto LAB_00100c7c;
}



//------------------------------------------------------------
// hvc_gh_console_init @ 00100cd4 size=164
// signature: undefined hvc_gh_console_init(void)
// callers: [init_module]
//------------------------------------------------------------

void hvc_gh_console_init(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = hvc_instantiate(0x474e5948,0,&gh_hv_ops);
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = hvc_instantiate(0x474e5948,1,&gh_hv_ops);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = 2;
  }
  iVar3 = 0;
  do {
    iVar2 = hvc_instantiate(iVar3 + 0x474e5949,iVar1 + iVar3,&gh_hv_ops);
    if (iVar2 != 0) {
      return;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 6);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100d7c size=104
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  long lVar1;
  
  gh_unregister_vm_notifier(&gh_hvc_vm_nb);
  gh_rm_unregister_notifier(&gh_hvc_nb);
  lVar1 = -0x3b10;
  do {
    if (*(long *)((long)&fifo_lock + lVar1) != 0) {
      hvc_remove();
      *(undefined8 *)((long)&fifo_lock + lVar1) = 0;
    }
    lVar1 = lVar1 + 0x870;
  } while (lVar1 != 0);
  return;
}



//------------------------------------------------------------
// hvc_alloc @ 00106000 size=1
// signature: undefined hvc_alloc(void)
// callers: [init_module, gh_hvc_vm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hvc_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00106008 size=1
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
// gh_register_vm_notifier @ 00106010 size=1
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
// gh_rm_unregister_notifier @ 00106018 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hvc_remove @ 00106020 size=1
// signature: undefined hvc_remove(void)
// callers: [cleanup_module, init_module, gh_hvc_vm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hvc_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_unregister_vm_notifier @ 00106028 size=1
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
// ghd_rm_get_vmid @ 00106030 size=1
// signature: undefined ghd_rm_get_vmid(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_notify_add, gh_hvc_flush, gh_hvc_notify_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ghd_rm_get_vmid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106038 size=1
// signature: undefined _printk(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_notify_console_chars, gh_hvc_notify_add, gh_hvc_notify_del, gh_hvc_vm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00106040 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_notify_console_chars, gh_hvc_put_chars, gh_hvc_get_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kfifo_out @ 00106048 size=1
// signature: undefined __kfifo_out(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_get_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_out(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00106050 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_notify_console_chars, gh_hvc_put_chars, gh_hvc_get_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_console_write @ 00106058 size=1
// signature: undefined gh_rm_console_write(void)
// callers: [gh_hvc_put_work_fn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_console_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106060 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_hvc_put_work_fn, gh_hvc_notify_console_chars, gh_hvc_notify_add, gh_hvc_flush, gh_hvc_notify_del, gh_hvc_vm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hvc_instantiate @ 00106068 size=1
// signature: undefined hvc_instantiate(void)
// callers: [hvc_gh_console_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hvc_instantiate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kfifo_in @ 00106070 size=1
// signature: undefined __kfifo_in(void)
// callers: [gh_hvc_notify_console_chars, gh_hvc_put_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kfifo_in(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00106080 size=1
// signature: undefined queue_work_on(void)
// callers: [gh_hvc_put_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00106088 size=1
// signature: undefined cancel_work_sync(void)
// callers: [gh_hvc_flush, gh_hvc_notify_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_console_flush @ 00106090 size=1
// signature: undefined gh_rm_console_flush(void)
// callers: [gh_hvc_flush]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_console_flush(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_console_open @ 00106098 size=1
// signature: undefined gh_rm_console_open(void)
// callers: [gh_hvc_notify_add]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_console_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_console_close @ 001060a0 size=1
// signature: undefined gh_rm_console_close(void)
// callers: [gh_hvc_notify_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_console_close(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_get_vm_name @ 001060a8 size=1
// signature: undefined gh_rm_get_vm_name(void)
// callers: [gh_hvc_notify_console_chars, gh_hvc_vm_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_get_vm_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 001060b0 size=1
// signature: undefined ___ratelimit(void)
// callers: [gh_hvc_notify_console_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hvc_poll @ 001060b8 size=1
// signature: undefined hvc_poll(void)
// callers: [gh_hvc_notify_console_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hvc_poll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hvc_kick @ 001060c0 size=1
// signature: undefined hvc_kick(void)
// callers: [gh_hvc_notify_console_chars]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hvc_kick(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



