// Decompiled by Ghidra 12.2
// Program: usb_f_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// dun_cser_get_dtr @ 00100bac size=12
// signature: undefined dun_cser_get_dtr(void)
// callers: []
//------------------------------------------------------------

ushort dun_cser_get_dtr(long param_1)

{
  return *(ushort *)(param_1 + 0x104) & 1;
}



//------------------------------------------------------------
// dun_cser_get_rts @ 00100bbc size=12
// signature: undefined dun_cser_get_rts(void)
// callers: []
//------------------------------------------------------------

ushort dun_cser_get_rts(long param_1)

{
  return *(ushort *)(param_1 + 0x104) >> 1 & 1;
}



//------------------------------------------------------------
// dun_cser_send_carrier_detect @ 00100bcc size=52
// signature: undefined dun_cser_send_carrier_detect(void)
// callers: []
//------------------------------------------------------------

void dun_cser_send_carrier_detect(long param_1,int param_2)

{
  *(ushort *)(param_1 + 0x102) = *(ushort *)(param_1 + 0x102) & 0xfffe | (ushort)(param_2 != 0);
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// port_notify_serial_state @ 00100c00 size=288
// signature: undefined port_notify_serial_state(void)
// callers: [dun_cser_send_ring_indicator, dun_cser_send_carrier_detect, dun_cser_connect, dun_cser_send_break, dun_cser_disconnect, usb_cser_notify_complete, dun_cser_send_ctrl_bits]
//------------------------------------------------------------

int port_notify_serial_state(long param_1)

{
  byte bVar1;
  int iVar2;
  undefined8 uVar3;
  undefined4 *puVar4;
  long lVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  
  lVar5 = param_1 + -0x84;
  uVar3 = _raw_spin_lock_irqsave(lVar5);
  if (*(char *)(param_1 + 0xff) != '\0') {
    iVar2 = 0;
    *(undefined1 *)(param_1 + 0x100) = 1;
    goto LAB_00100d00;
  }
  *(undefined1 *)(param_1 + 0xff) = 1;
  _raw_spin_unlock_irqrestore(lVar5,uVar3);
  uVar6 = *(undefined8 *)(param_1 + 0xe8);
  uVar3 = _raw_spin_lock_irqsave(lVar5);
  if (*(char *)(param_1 + 0x160) == '\0') {
    iVar2 = -0x13;
LAB_00100cec:
    _raw_spin_unlock_irqrestore(lVar5,uVar3);
  }
  else {
    puVar7 = *(undefined8 **)(param_1 + 0xf0);
    puVar4 = (undefined4 *)*puVar7;
    *(undefined4 *)(puVar7 + 1) = 10;
    *puVar4 = 0x20a1;
    bVar1 = *(byte *)(param_1 + 0x101);
    *(undefined2 *)((long)puVar4 + 6) = 2;
    *(ushort *)(puVar4 + 1) = (ushort)bVar1;
    *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_1 + 0x102);
    _raw_spin_unlock_irqrestore(lVar5,uVar3);
    iVar2 = usb_ep_queue(uVar6,puVar7,0xa20);
    if (iVar2 < 0) {
      _printk(&DAT_00103945,"usb_cser_notify",param_1 + -0x94,iVar2);
      uVar3 = _raw_spin_lock_irqsave(lVar5);
      *(undefined1 *)(param_1 + 0xff) = 0;
      goto LAB_00100cec;
    }
  }
  uVar3 = _raw_spin_lock_irqsave(lVar5);
LAB_00100d00:
  _raw_spin_unlock_irqrestore(lVar5,uVar3);
  return iVar2;
}



//------------------------------------------------------------
// dun_cser_send_ring_indicator @ 00100d24 size=52
// signature: undefined dun_cser_send_ring_indicator(void)
// callers: []
//------------------------------------------------------------

void dun_cser_send_ring_indicator(long param_1,int param_2)

{
  *(ushort *)(param_1 + 0x102) = *(ushort *)(param_1 + 0x102) & 0xfff7 | (ushort)(param_2 != 0) << 3
  ;
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// f_cdev_open @ 00100d5c size=328
// signature: undefined f_cdev_open(void)
// callers: []
//------------------------------------------------------------

ulong f_cdev_open(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  undefined8 uVar4;
  long lVar5;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar5 = *(long *)(param_1 + 0x290);
  lVar1 = lVar5 + 0x88;
  get_device(lVar1);
  if (*(char *)(lVar5 + 0x611) == '\0') {
    *(long *)(param_2 + 0xd8) = lVar5;
    if (*(char *)(lVar5 + 0x610) == '\0') {
      local_48 = 0;
      uStack_40 = 0;
      local_58 = 0;
      uStack_50 = 0;
      local_60 = 0;
      init_wait_entry(&local_60,0);
      lVar2 = lVar5 + 0x430;
      uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
      if (*(char *)(lVar5 + 0x610) == '\0') {
        do {
          if (uVar3 != 0) {
            if ((int)uVar3 == 0) goto LAB_00100e10;
            put_device(lVar1);
            goto LAB_00100e3c;
          }
          schedule();
          uVar3 = prepare_to_wait_event(lVar2,&local_60,1);
        } while (*(char *)(lVar5 + 0x610) == '\0');
      }
      finish_wait(lVar2,&local_60);
    }
LAB_00100e10:
    uVar4 = _raw_spin_lock_irqsave(lVar5 + 0x42c);
    *(undefined1 *)(lVar5 + 0x611) = 1;
    _raw_spin_unlock_irqrestore(lVar5 + 0x42c,uVar4);
    usb_cser_start_rx(lVar5);
    uVar3 = 0;
  }
  else {
    _printk(&DAT_0010374c,"f_cdev_open");
    put_device(lVar1);
    uVar3 = 0xfffffff0;
  }
LAB_00100e3c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// usb_cser_start_rx @ 00100ea4 size=340
// signature: undefined usb_cser_start_rx(void)
// callers: [f_cdev_open, usb_cser_set_alt, f_cdev_read]
//------------------------------------------------------------

void usb_cser_start_rx(long param_1)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  long *plVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long *plVar8;
  long lVar9;
  
  if (param_1 == 0) {
    _printk(&DAT_00103dec,"usb_cser_start_rx");
  }
  else {
    lVar1 = param_1 + 0x42c;
    uVar6 = _raw_spin_lock_irqsave(lVar1);
    if ((*(char *)(param_1 + 0x610) != '\0') && (*(char *)(param_1 + 0x611) != '\0')) {
      plVar2 = (long *)(param_1 + 0x460);
      lVar9 = *(long *)(param_1 + 0x590);
      do {
        plVar8 = (long *)*plVar2;
        if (plVar8 == plVar2) goto LAB_00100fcc;
        uVar7 = __list_del_entry_valid(plVar8);
        if ((uVar7 & 1) != 0) {
          lVar3 = *plVar8;
          plVar4 = (long *)plVar8[1];
          *(long **)(lVar3 + 8) = plVar4;
          *plVar4 = lVar3;
        }
        *plVar8 = (long)plVar8;
        plVar8[1] = (long)plVar8;
        *(undefined4 *)(plVar8 + -7) = 0x800;
        plVar8[-2] = (long)usb_cser_read_complete;
        _raw_spin_unlock_irqrestore(lVar1,uVar6);
        iVar5 = usb_ep_queue(lVar9,plVar8 + -8,0xcc0);
        uVar6 = _raw_spin_lock_irqsave(lVar1);
      } while (iVar5 == 0);
      _printk(&DAT_00103e00,"usb_cser_start_rx",*(undefined4 *)(param_1 + 0x418),param_1,
              *(undefined8 *)(lVar9 + 8));
      lVar9 = *(long *)(param_1 + 0x460);
      uVar7 = __list_add_valid(plVar8,plVar2,lVar9);
      if ((uVar7 & 1) != 0) {
        *(long **)(lVar9 + 8) = plVar8;
        *plVar8 = lVar9;
        plVar8[1] = (long)plVar2;
        *plVar2 = (long)plVar8;
      }
    }
LAB_00100fcc:
    _raw_spin_unlock_irqrestore(lVar1,uVar6);
  }
  return;
}



//------------------------------------------------------------
// f_cdev_release @ 00100ffc size=80
// signature: undefined f_cdev_release(void)
// callers: []
//------------------------------------------------------------

undefined8 f_cdev_release(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_2 + 0xd8);
  uVar1 = _raw_spin_lock_irqsave(lVar2 + 0x42c);
  *(undefined1 *)(lVar2 + 0x611) = 0;
  *(undefined1 *)(lVar2 + 0x604) = 0;
  _raw_spin_unlock_irqrestore(lVar2 + 0x42c,uVar1);
  put_device(lVar2 + 0x88);
  return 0;
}



//------------------------------------------------------------
// f_cdev_read @ 00101050 size=812
// signature: undefined f_cdev_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long f_cdev_read(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong uVar5;
  code *pcVar6;
  bool bVar7;
  undefined8 uVar8;
  ulong uVar9;
  long *plVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  long *plVar14;
  long lVar15;
  long *plVar16;
  ulong uVar17;
  long *plVar18;
  long local_68;
  
  lVar12 = *(long *)(param_1 + 0xd8);
  if (lVar12 == 0) {
    _printk(&DAT_00103800,"f_cdev_read");
    local_68 = -0x16;
  }
  else {
    lVar1 = lVar12 + 0x42c;
    uVar8 = _raw_spin_lock_irqsave(lVar1);
    plVar10 = *(long **)(lVar12 + 0x490);
    *(undefined8 *)(lVar12 + 0x490) = 0;
    uVar13 = *(ulong *)(lVar12 + 0x498);
    *(undefined8 *)(lVar12 + 0x498) = 0;
    lVar15 = *(long *)(lVar12 + 0x4a0);
    *(undefined8 *)(lVar12 + 0x4a0) = 0;
    plVar2 = (long *)(lVar12 + 0x470);
    if ((*(long **)(lVar12 + 0x470) == plVar2) && (local_68 = 0, uVar13 == 0)) {
LAB_00101300:
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      usb_cser_start_rx(lVar12);
    }
    else {
      lVar3 = lVar12 + 0x460;
      local_68 = 0;
      puVar4 = (undefined8 *)sp_el0;
LAB_001010e4:
      if (uVar13 == 0) {
        plVar16 = (long *)*plVar2;
        if ((plVar16 == plVar2) || (param_3 == 0)) goto LAB_001012f0;
        plVar14 = plVar16 + -8;
        uVar13 = __list_del_entry_valid(plVar16);
        if ((uVar13 & 1) != 0) {
          lVar15 = *plVar16;
          plVar10 = (long *)plVar16[1];
          *(long **)(lVar15 + 8) = plVar10;
          *plVar10 = lVar15;
        }
        *plVar16 = (long)plVar16;
        plVar16[1] = (long)plVar16;
        uVar13 = (ulong)*(uint *)(plVar16 + 3);
        lVar15 = plVar16[-8];
      }
      else {
        if (param_3 == 0) {
LAB_001012f0:
          *(ulong *)(lVar12 + 0x498) = uVar13;
          *(long *)(lVar12 + 0x4a0) = lVar15;
          *(long **)(lVar12 + 0x490) = plVar10;
          goto LAB_00101300;
        }
        plVar14 = plVar10;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      uVar17 = param_3;
      if (uVar13 <= param_3) {
        uVar17 = uVar13;
      }
      if (uVar17 >> 0x1f != 0) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x800,0x1012bc);
        (*pcVar6)();
      }
      __check_object_size(lVar15,uVar17,1);
      if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
         (uVar11 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
        uVar11 = param_2 & (long)(param_2 << 8) >> 8;
      }
      uVar9 = uVar17;
      if (uVar11 <= 0x8000000000 - uVar17) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar11 = daif;
          if ((uVar11 & 0x80) == 0) {
            uVar9 = daif;
            daif = uVar9 | 0xc0;
          }
          uVar9 = ttbr1_el1;
          ttbr1_el1 = puVar4[1] & 0xffff000000000000 | uVar9 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar4[1];
          InstructionSynchronizationBarrier();
          daif = uVar11;
        }
        uVar9 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,lVar15,uVar17);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar11 = daif;
          if ((uVar11 & 0x80) == 0) {
            uVar5 = daif;
            daif = uVar5 | 0xc0;
          }
          uVar5 = ttbr1_el1;
          ttbr0_el1 = (uVar5 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar5 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar11;
        }
      }
      uVar17 = uVar17 - uVar9;
      *(ulong *)(lVar12 + 0x628) = *(long *)(lVar12 + 0x628) + uVar17;
      uVar8 = _raw_spin_lock_irqsave(lVar1);
      if (*(char *)(lVar12 + 0x610) != '\0') {
        param_3 = param_3 - uVar17;
        param_2 = param_2 + uVar17;
        bVar7 = uVar13 < uVar17;
        uVar13 = uVar13 - uVar17;
        local_68 = uVar17 + local_68;
        if (bVar7 || uVar13 == 0) {
          plVar18 = *(long **)(lVar12 + 0x468);
          plVar16 = plVar14 + 8;
          uVar17 = __list_add_valid(plVar16,plVar18,lVar3);
          uVar13 = 0;
          lVar15 = 0;
          plVar10 = (long *)0x0;
          if ((uVar17 & 1) != 0) {
            uVar13 = 0;
            lVar15 = 0;
            *(long **)(lVar12 + 0x468) = plVar16;
            plVar14[8] = lVar3;
            plVar14[9] = (long)plVar18;
            *plVar18 = (long)plVar16;
            plVar10 = (long *)0x0;
          }
        }
        else {
          lVar15 = lVar15 + uVar17;
          plVar10 = plVar14;
        }
        goto LAB_001010e4;
      }
      plVar10 = *(long **)(lVar12 + 0x468);
      plVar2 = plVar14 + 8;
      uVar13 = __list_add_valid(plVar2,plVar10,lVar3);
      if ((uVar13 & 1) != 0) {
        *(long **)(lVar12 + 0x468) = plVar2;
        plVar14[8] = lVar3;
        plVar14[9] = (long)plVar10;
        *plVar10 = (long)plVar2;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar8);
      local_68 = -0xb;
    }
  }
  return local_68;
}



//------------------------------------------------------------
// f_cdev_write @ 0010139c size=784
// signature: undefined f_cdev_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong f_cdev_write(long param_1,ulong param_2,ulong param_3)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  int iVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 *puVar8;
  long *plVar9;
  undefined8 uVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  
  lVar13 = *(long *)(param_1 + 0xd8);
  if (lVar13 == 0) {
    _printk(&DAT_00103800,"f_cdev_write");
    return 0xffffffffffffffea;
  }
  lVar1 = lVar13 + 0x42c;
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(lVar13 + 0x610) == '\0') {
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    _printk(&DAT_00103ad7,"f_cdev_write","f_cdev_write");
    return 0xffffffffffffffed;
  }
  plVar9 = *(long **)(lVar13 + 0x480);
  plVar2 = (long *)(lVar13 + 0x480);
  if (plVar9 == plVar2) {
    _raw_spin_unlock_irqrestore(lVar1,uVar5);
    return 0;
  }
  uVar10 = *(undefined8 *)(lVar13 + 0x588);
  uVar6 = __list_del_entry_valid(plVar9);
  if ((uVar6 & 1) != 0) {
    lVar12 = *plVar9;
    plVar11 = (long *)plVar9[1];
    *(long **)(lVar12 + 8) = plVar11;
    *plVar11 = lVar12;
  }
  plVar11 = plVar9 + -8;
  *plVar9 = (long)plVar9;
  plVar9[1] = (long)plVar9;
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  lVar12 = plVar9[-8];
  if (0x7ff < param_3) {
    param_3 = 0x800;
  }
  __check_object_size(lVar12,param_3,0);
  puVar8 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
     (uVar6 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
    uVar6 = param_2 & (long)(param_2 << 8) >> 8;
  }
  uVar7 = param_3;
  if (uVar6 <= 0x8000000000 - param_3) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar7 = daif;
        daif = uVar7 | 0xc0;
      }
      puVar8 = (undefined8 *)puVar8[1];
      uVar7 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar7 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar8;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
    uVar7 = __arch_copy_from_user(puVar8,lVar12,param_2 & 0xff7fffffffffffff,param_3);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar6 = daif;
      if ((uVar6 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar6;
    }
  }
  if ((uVar7 == 0) || (memset((void *)(lVar12 + (param_3 - uVar7)),0,uVar7), (int)uVar7 == 0)) {
    *(int *)(plVar9 + -7) = (int)param_3;
    *(uint *)(plVar9 + -3) = *(uint *)(plVar9 + -3) | 0x40000;
    iVar4 = usb_ep_queue(uVar10,plVar11,0xcc0);
    if (iVar4 == 0) {
      uVar5 = _raw_spin_lock_irqsave(lVar1);
      *(ulong *)(lVar13 + 0x630) = *(long *)(lVar13 + 0x630) + (ulong)*(uint *)(plVar9 + -7);
      goto LAB_0010155c;
    }
    _printk(&DAT_00103b8c,"f_cdev_write",iVar4);
    param_3 = 0xfffffffffffffffb;
  }
  else {
    _printk(&DAT_0010376b,"f_cdev_write",uVar7 & 0xffffffff);
    param_3 = 0xfffffffffffffff2;
  }
  uVar5 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(lVar13 + 0x610) == '\0') {
    if (plVar11 != (long *)0x0) {
      kfree(*plVar11);
      usb_ep_free_request(uVar10,plVar11);
    }
  }
  else {
    lVar13 = *plVar2;
    uVar6 = __list_add_valid(plVar9,plVar2,lVar13);
    if ((uVar6 & 1) != 0) {
      *(long **)(lVar13 + 8) = plVar9;
      *plVar9 = lVar13;
      plVar9[1] = (long)plVar2;
      *plVar2 = (long)plVar9;
    }
  }
LAB_0010155c:
  _raw_spin_unlock_irqrestore(lVar1,uVar5);
  return param_3;
}



//------------------------------------------------------------
// usb_cser_read_complete @ 001016c8 size=336
// signature: undefined usb_cser_read_complete(void)
// callers: []
//------------------------------------------------------------

void usb_cser_read_complete(long *param_1,long param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  long lVar7;
  
  lVar7 = *param_1;
  if (lVar7 == 0) {
    _printk(&DAT_00103dec,"usb_cser_read_complete");
    return;
  }
  lVar1 = lVar7 + 0x42c;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  if (*(char *)(lVar7 + 0x611) != '\0') {
    if (*(int *)(param_2 + 0x54) == -0x20) {
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      iVar3 = usb_ep_queue(param_1,param_2,0xcc0);
      if (iVar3 == 0) {
        return;
      }
      uVar4 = _raw_spin_lock_irqsave(lVar1);
    }
    else if ((*(int *)(param_2 + 0x54) == 0) && (*(uint *)(param_2 + 0x58) != 0)) {
      lVar2 = param_2 + 0x40;
      plVar6 = *(long **)(lVar7 + 0x478);
      *(ulong *)(lVar7 + 0x618) = *(long *)(lVar7 + 0x618) + (ulong)*(uint *)(param_2 + 0x58);
      uVar5 = __list_add_valid(lVar2,plVar6,lVar7 + 0x470);
      if ((uVar5 & 1) != 0) {
        *(long *)(lVar7 + 0x478) = lVar2;
        *(long *)(param_2 + 0x40) = lVar7 + 0x470;
        *(long **)(param_2 + 0x48) = plVar6;
        *plVar6 = lVar2;
      }
      _raw_spin_unlock_irqrestore(lVar1,uVar4);
      __wake_up(lVar7 + 0x448,3,1,0);
      return;
    }
  }
  plVar6 = *(long **)(lVar7 + 0x468);
  lVar2 = param_2 + 0x40;
  uVar5 = __list_add_valid(lVar2,plVar6,lVar7 + 0x460);
  if ((uVar5 & 1) != 0) {
    *(long *)(lVar7 + 0x468) = lVar2;
    *(long *)(param_2 + 0x40) = lVar7 + 0x460;
    *(long **)(param_2 + 0x48) = plVar6;
    *plVar6 = lVar2;
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  return;
}



//------------------------------------------------------------
// cser_alloc_inst @ 0010181c size=112
// signature: undefined cser_alloc_inst(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long cser_alloc_inst(void)

{
  long lVar1;
  
  lVar1 = kmalloc_trace(_unregister_chrdev_region,0xdc0,0xd0);
  if (lVar1 == 0) {
    lVar1 = -0xc;
  }
  else {
    *(code **)(lVar1 + 0xa8) = cser_set_inst_name;
    *(code **)(lVar1 + 0xb0) = cser_free_inst;
    config_group_init_type_name(lVar1,&DAT_00103a61,&cserial_func_type);
  }
  return lVar1;
}



//------------------------------------------------------------
// cser_alloc @ 00101890 size=132
// signature: undefined cser_alloc(void)
// callers: []
//------------------------------------------------------------

long cser_alloc(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xb8);
  *(undefined **)(lVar1 + 0x4b0) = &DAT_00103af9;
  *(undefined ***)(lVar1 + 0x4b8) = &usb_cser_strings;
  *(code **)(lVar1 + 0x4f8) = usb_cser_bind;
  *(code **)(lVar1 + 0x500) = usb_cser_unbind;
  *(code **)(lVar1 + 0x550) = usb_cser_get_status;
  *(code **)(lVar1 + 0x518) = usb_cser_set_alt;
  *(code **)(lVar1 + 0x528) = usb_cser_disable;
  *(code **)(lVar1 + 0x530) = usb_cser_setup;
  *(code **)(lVar1 + 0x558) = usb_cser_func_suspend;
  *(code **)(lVar1 + 0x508) = usb_cser_free_func;
  return lVar1 + 0x4b0;
}



//------------------------------------------------------------
// cser_free_inst @ 00101918 size=228
// signature: undefined cser_free_inst(void)
// callers: []
//------------------------------------------------------------

void cser_free_inst(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = *(long *)(param_1 + 0xb8);
  if (lVar1 != 0) {
    cdev_device_del(lVar1,lVar1 + 0x88);
    mutex_lock(chardev_ida_lock);
    ida_free(chardev_ida,*(undefined4 *)(*(long *)(param_1 + 0xb8) + 0x428));
    mutex_unlock(chardev_ida_lock);
    debugfs_remove(*(undefined8 *)(*(long *)(param_1 + 0xb8) + 0x638));
    put_device(*(long *)(param_1 + 0xb8) + 0x88);
  }
  if (chardev_ida._8_8_ == 0) {
    if (major != 0) {
      uVar2 = 4;
      if (minors == '\0') {
        uVar2 = 0;
      }
      unregister_chrdev_region(major << 0x14,uVar2);
      minors = '\0';
      major = 0;
    }
    if ((fcdev_classp != 0) && (fcdev_classp < 0xfffffffffffff001)) {
      class_destroy();
    }
  }
  kfree(*(undefined8 *)(param_1 + 0xc0));
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// cser_set_inst_name @ 00101a00 size=1328
// signature: undefined cser_set_inst_name(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cser_set_inst_name(long param_1,char *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  size_t sVar7;
  long lVar8;
  undefined *puVar9;
  undefined1 uVar10;
  ulong uVar11;
  undefined4 uVar12;
  uint local_5c;
  long local_58;
  
  lVar8 = sp_el0;
  local_58 = *(long *)(lVar8 + 0x638);
  sVar5 = strlen(param_2);
  if (0xf < sVar5 + 1) {
LAB_00101a6c:
    uVar12 = 0xffffffdc;
    goto LAB_00101a70;
  }
  pcVar6 = (char *)strnchr(param_2,sVar5,0x2e);
  if (pcVar6 == (char *)0x0) {
    _printk(&DAT_00103d53,"cser_set_inst_name",param_2);
    uVar12 = 0xffffffea;
    goto LAB_00101a70;
  }
  sVar7 = strlen(pcVar6);
  uVar11 = (sVar5 + 1) - sVar7;
  if (5 < uVar11) goto LAB_00101a6c;
  lVar8 = kstrndup(param_2,uVar11 - 1,0xcc0);
  if (lVar8 == 0) {
    _printk(&DAT_00103916,"cser_set_inst_name",0);
    uVar12 = 0xfffffff4;
    goto LAB_00101a70;
  }
  *(long *)(param_1 + 0xc0) = lVar8;
  pcVar6 = strrchr(param_2,0x2e);
  if (pcVar6 == (char *)0x0) {
    puVar9 = &DAT_00103b34;
  }
  else {
    pbVar1 = (byte *)(param_1 + 200);
    *pcVar6 = '\0';
    iVar4 = kstrtou8(pcVar6 + 1,0,pbVar1);
    if (iVar4 == 0) {
      bVar2 = *pbVar1;
      uVar11 = kmalloc_trace(_strnchr,0xdc0,0x648);
      if (uVar11 != 0) {
        mutex_lock(chardev_ida_lock);
        if (chardev_ida._8_8_ == 0) {
          local_5c = 0;
          iVar4 = alloc_chrdev_region(&local_5c,0,4,"msm_usb_bridge");
          if (iVar4 == 0) {
            major = local_5c >> 0x14;
            minors = '\x01';
            fcdev_classp = __class_create(&__this_module,"msm_usb_bridge",
                                          &usb_cser_alloc_chardev_region___key);
            if (0xfffffffffffff000 < fcdev_classp) {
              _printk(&DAT_00103e38,"usb_cser_alloc_chardev_region");
            }
            goto LAB_00101b84;
          }
          _printk(&DAT_001039b8,"usb_cser_alloc_chardev_region",iVar4);
          mutex_unlock(chardev_ida_lock);
          _printk(&DAT_00103b02,"f_cdev_alloc");
LAB_00101c14:
          kfree(uVar11);
          uVar11 = (ulong)iVar4;
        }
        else {
LAB_00101b84:
          iVar4 = ida_alloc_range(chardev_ida,0,0xffffffff,0xcc0);
          if (3 < iVar4) {
            ida_free(chardev_ida);
            mutex_unlock(chardev_ida_lock);
            iVar4 = -0x13;
LAB_00101bc4:
            if (chardev_ida._8_8_ == 0) {
              if (major != 0) {
                uVar12 = 4;
                if (minors == '\0') {
                  uVar12 = 0;
                }
                unregister_chrdev_region(major << 0x14,uVar12);
                minors = '\0';
                major = 0;
              }
              if ((fcdev_classp != 0) && (fcdev_classp < 0xfffffffffffff001)) {
                class_destroy();
              }
            }
            goto LAB_00101c14;
          }
          *(uint *)(uVar11 + 0x418) = (uint)bVar2;
          *(int *)(uVar11 + 0x428) = iVar4;
          mutex_unlock(chardev_ida_lock);
          pcVar6 = (char *)(uVar11 + 0x41c);
          snprintf(pcVar6,9,"%s%d","at_usb",(ulong)(uint)bVar2);
          *(undefined4 *)(uVar11 + 0x42c) = 0;
          __init_waitqueue_head(uVar11 + 0x430,"&port->open_wq",&f_cdev_alloc___key);
          __init_waitqueue_head(uVar11 + 0x448,"&port->read_wq",&f_cdev_alloc___key_24);
          *(ulong *)(uVar11 + 0x460) = uVar11 + 0x460;
          *(ulong *)(uVar11 + 0x468) = uVar11 + 0x460;
          *(ulong *)(uVar11 + 0x470) = uVar11 + 0x470;
          *(ulong *)(uVar11 + 0x478) = uVar11 + 0x470;
          *(ulong *)(uVar11 + 0x480) = uVar11 + 0x480;
          *(ulong *)(uVar11 + 0x488) = uVar11 + 0x480;
          lVar8 = alloc_workqueue(&DAT_00103a34,0xe000a,1,pcVar6);
          *(long *)(uVar11 + 0x608) = lVar8;
          if (lVar8 == 0) {
            _printk(&DAT_001039ea,"f_cdev_alloc",pcVar6);
            iVar4 = -0xc;
            goto LAB_00101bc4;
          }
          cdev_init(uVar11,&f_cdev_fops);
          lVar8 = uVar11 + 0x88;
          device_initialize(lVar8);
          *(undefined8 *)(uVar11 + 0xe8) = 0;
          uVar3 = major;
          *(ulong *)(uVar11 + 0x3a0) = fcdev_classp;
          *(uint *)(uVar11 + 0x380) = *(uint *)(uVar11 + 0x428) | uVar3 << 0x14;
          *(code **)(uVar11 + 0x3b0) = cdev_device_release;
          dev_set_name(lVar8,pcVar6);
          iVar4 = cdev_device_add(uVar11,lVar8);
          if (iVar4 != 0) {
            _printk(&DAT_00103c8f,"f_cdev_alloc",pcVar6);
            destroy_workqueue(*(undefined8 *)(uVar11 + 0x608));
            goto LAB_00101bc4;
          }
          usb_cser_debugfs_init(uVar11);
          _printk(&DAT_00103cfe,"f_cdev_alloc",pcVar6,uVar11,*(undefined4 *)(uVar11 + 0x418));
        }
        if (uVar11 < 0xfffffffffffff001) {
          *(ulong *)(param_1 + 0xb8) = uVar11;
          iVar4 = strcmp(*(char **)(param_1 + 0xc0),"dun");
          if (iVar4 == 0) {
            uVar10 = 0x40;
            *(code **)(uVar11 + 0x5c8) = dun_cser_connect;
            *(code **)(uVar11 + 0x5b8) = dun_cser_get_dtr;
            *(code **)(uVar11 + 0x5c0) = dun_cser_get_rts;
            *(code **)(uVar11 + 0x5e0) = dun_cser_send_carrier_detect;
            *(code **)(uVar11 + 0x5e8) = dun_cser_send_ring_indicator;
            *(code **)(uVar11 + 0x5f0) = dun_cser_send_ctrl_bits;
            *(code **)(uVar11 + 0x5d0) = dun_cser_disconnect;
            *(code **)(uVar11 + 0x5d8) = dun_cser_send_break;
          }
          else {
            uVar10 = 0x60;
          }
          uVar12 = 0;
          *(undefined1 *)(param_1 + 0xc9) = uVar10;
          goto LAB_00101a70;
        }
      }
      _printk(&DAT_00103c24,"cser_set_inst_name",*pbVar1);
      uVar12 = 0xfffffff4;
      goto LAB_00101a70;
    }
    puVar9 = &DAT_001037b7;
  }
  _printk(puVar9,"cser_set_inst_name");
  uVar12 = 0xffffffea;
LAB_00101a70:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar12);
  }
  return;
}



//------------------------------------------------------------
// dun_cser_connect @ 00101f34 size=40
// signature: undefined dun_cser_connect(void)
// callers: []
//------------------------------------------------------------

void dun_cser_connect(long param_1)

{
  *(ushort *)(param_1 + 0x102) = *(ushort *)(param_1 + 0x102) | 3;
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// dun_cser_send_ctrl_bits @ 00101f60 size=32
// signature: undefined dun_cser_send_ctrl_bits(void)
// callers: []
//------------------------------------------------------------

void dun_cser_send_ctrl_bits(long param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x102) = param_2;
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// dun_cser_disconnect @ 00101f84 size=40
// signature: undefined dun_cser_disconnect(void)
// callers: []
//------------------------------------------------------------

void dun_cser_disconnect(long param_1)

{
  *(ushort *)(param_1 + 0x102) = *(ushort *)(param_1 + 0x102) & 0xfffc;
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// dun_cser_send_break @ 00101fb0 size=52
// signature: undefined dun_cser_send_break(void)
// callers: []
//------------------------------------------------------------

void dun_cser_send_break(long param_1,int param_2)

{
  *(ushort *)(param_1 + 0x102) = *(ushort *)(param_1 + 0x102) & 0xfffb | (ushort)(param_2 != 0) << 2
  ;
  port_notify_serial_state();
  return;
}



//------------------------------------------------------------
// cdev_device_release @ 00101fe8 size=32
// signature: undefined cdev_device_release(void)
// callers: []
//------------------------------------------------------------

void cdev_device_release(long param_1)

{
  kfree(param_1 + -0x88);
  return;
}



//------------------------------------------------------------
// usb_cser_debugfs_init @ 00102008 size=92
// signature: undefined usb_cser_debugfs_init(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

void usb_cser_debugfs_init(long param_1)

{
  ulong uVar1;
  
  uVar1 = debugfs_create_dir(param_1 + 0x41c,0);
  *(ulong *)(param_1 + 0x638) = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    debugfs_create_file("remote_wakeup",0x180,uVar1,param_1,&cser_rem_wakeup_fops);
  }
  return;
}



//------------------------------------------------------------
// f_cdev_poll @ 00102068 size=196
// signature: undefined f_cdev_poll(void)
// callers: []
//------------------------------------------------------------

uint f_cdev_poll(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0xd8);
  if ((lVar4 == 0) || (*(char *)(lVar4 + 0x610) == '\0')) {
    _printk(&DAT_00103e6e,"f_cdev_poll");
    uVar2 = 8;
  }
  else {
    if (((param_2 != (undefined8 *)0x0) && (lVar4 != -0x448)) &&
       (pcVar3 = (code *)*param_2, pcVar3 != (code *)0x0)) {
      if (*(int *)(pcVar3 + -4) != 0x7db4acb9) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1020b8);
        (*pcVar3)();
      }
      (*pcVar3)();
      DataMemoryBarrier(2,3);
    }
    uVar1 = _raw_spin_lock_irqsave(lVar4 + 0x42c);
    uVar2 = 0;
    if (*(long *)(lVar4 + 0x470) != lVar4 + 0x470) {
      uVar2 = 0x41;
    }
    if (*(char *)(lVar4 + 0x604) != '\0') {
      uVar2 = uVar2 | 2;
    }
    _raw_spin_unlock_irqrestore(lVar4 + 0x42c,uVar1);
  }
  return uVar2;
}



//------------------------------------------------------------
// f_cdev_ioctl @ 00102130 size=1032
// signature: undefined f_cdev_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long f_cdev_ioctl(long param_1,int param_2,ulong param_3)

{
  undefined8 *puVar1;
  ulong uVar2;
  int iVar3;
  long lVar4;
  code *pcVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  
  lVar7 = *(long *)(param_1 + 0xd8);
  if (lVar7 == 0) {
    _printk(&DAT_00103815,"f_cdev_ioctl");
    lVar4 = 8;
  }
  else if (param_2 - 0x5416U < 3) {
    puVar1 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar6 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      uVar8 = *(uint *)(param_3 & 0xff7fffffffffffff);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      lVar4 = lVar7 + 0x4b0;
      if (((uVar8 >> 7 & 1) == 0) || (pcVar5 = *(code **)(lVar7 + 0x5e8), pcVar5 == (code *)0x0)) {
        iVar3 = 0;
      }
      else {
        *(ushort *)(lVar7 + 0x5b2) = *(ushort *)(lVar7 + 0x5b2) | 0x80;
        if (*(int *)(pcVar5 + -4) != -0x703235fb) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102264);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(lVar4,1);
      }
      if (((~uVar8 >> 7 & 1) != 0) && (pcVar5 = *(code **)(lVar7 + 0x5e8), pcVar5 != (code *)0x0)) {
        *(ushort *)(lVar7 + 0x5b2) = *(ushort *)(lVar7 + 0x5b2) & 0xff7f;
        if (*(int *)(pcVar5 + -4) != -0x703235fb) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1022ac);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(lVar4,0);
      }
      if (((uVar8 >> 6 & 1) != 0) && (pcVar5 = *(code **)(lVar7 + 0x5e0), pcVar5 != (code *)0x0)) {
        *(ushort *)(lVar7 + 0x5b2) = *(ushort *)(lVar7 + 0x5b2) | 0x40;
        if (*(int *)(pcVar5 + -4) != -0x703235fb) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1022e8);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(lVar4,1);
      }
      if (((~uVar8 >> 6 & 1) != 0) && (pcVar5 = *(code **)(lVar7 + 0x5e0), pcVar5 != (code *)0x0)) {
        *(ushort *)(lVar7 + 0x5b2) = *(ushort *)(lVar7 + 0x5b2) & 0xffbf;
        if (*(int *)(pcVar5 + -4) != -0x703235fb) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102324);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(lVar4,0);
      }
      lVar4 = (long)iVar3;
    }
    else {
      _printk(&DAT_00103ea0,"f_cdev_ioctl");
      lVar4 = -0xe;
    }
  }
  else if (param_2 == 0x5415) {
    pcVar5 = *(code **)(lVar7 + 0x5b8);
    if (pcVar5 == (code *)0x0) {
      uVar8 = 0;
      pcVar5 = *(code **)(lVar7 + 0x5c0);
    }
    else {
      if (*(int *)(pcVar5 + -4) != 0x28385b06) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102374);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)(lVar7 + 0x4b0);
      uVar8 = (uint)(iVar3 != 0) << 1;
      pcVar5 = *(code **)(lVar7 + 0x5c0);
    }
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(pcVar5 + -4) != 0x28385b06) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1023a8);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)(lVar7 + 0x4b0);
      uVar8 = uVar8 | (uint)(iVar3 != 0) << 2;
    }
    puVar1 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
       (uVar6 = param_3, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
      uVar6 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar6 < 0x7ffffffffd) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar1[1];
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      *(uint *)(param_3 & 0xff7fffffffffffff) =
           uVar8 | *(ushort *)(lVar7 + 0x5b2) & 0x40 | *(ushort *)(lVar7 + 0x5b2) & 0x80;
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar6 = daif;
        if ((uVar6 & 0x80) == 0) {
          uVar2 = daif;
          daif = uVar2 | 0xc0;
        }
        uVar2 = ttbr1_el1;
        ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar2 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar6;
      }
      lVar4 = 0;
      *(undefined1 *)(lVar7 + 0x604) = 0;
    }
    else {
      lVar4 = -0xe;
      *(undefined1 *)(lVar7 + 0x604) = 0;
    }
  }
  else {
    _printk(&DAT_00103d6d,"f_cdev_ioctl");
    lVar4 = -0x203;
  }
  return lVar4;
}



//------------------------------------------------------------
// cser_rw_write @ 0010256c size=328
// signature: undefined cser_rw_write(void)
// callers: []
//------------------------------------------------------------

undefined8 cser_rw_write(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  char local_2c [4];
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c[0] = '\0';
  lVar3 = *(long *)(*(long *)(param_1 + 0xd8) + 0x80);
  if (lVar3 == -0x4b0) {
    _printk(&DAT_00103972,"cser_rw_write");
    param_3 = 0xffffffffffffffea;
  }
  else if (*(char *)(lVar3 + 0x610) == '\0') {
    param_3 = 0xffffffffffffffed;
  }
  else if (param_2 != 0) {
    iVar1 = kstrtou8_from_user(param_2,param_3,0,local_2c);
    if (iVar1 == 0) {
      if (((bool)*(char *)(lVar3 + 0x640) == (local_2c[0] != '\0')) ||
         (*(bool *)(lVar3 + 0x640) = local_2c[0] != '\0', local_2c[0] == '\0')) goto LAB_0010263c;
      if ((*(uint *)(**(long **)(*(long *)(lVar3 + 0x4e0) + 0x30) + 0x58) < 5) ||
         (*(char *)(lVar3 + 0x4a8) == '\0')) {
        iVar1 = usb_gadget_wakeup();
        if ((iVar1 + 0x10U < 0x11) && ((1 << (ulong)(iVar1 + 0x10U & 0x1f) & 0x10021U) != 0))
        goto LAB_0010263c;
      }
      else {
        iVar1 = -1;
      }
      puVar2 = &DAT_00103ec4;
    }
    else {
      puVar2 = &DAT_00103a44;
    }
    _printk(puVar2,"cser_rw_write",iVar1);
  }
LAB_0010263c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// debug_cdev_rw_open @ 001026b8 size=48
// signature: undefined debug_cdev_rw_open(void)
// callers: []
//------------------------------------------------------------

void debug_cdev_rw_open(long param_1,undefined8 param_2)

{
  single_open(param_2,usb_cser_rw_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// usb_cser_rw_show @ 001026ec size=76
// signature: undefined usb_cser_rw_show(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_cser_rw_show(long param_1)

{
  if (*(long *)(param_1 + 0x80) == 0) {
    _printk(&DAT_00103dec,"usb_cser_rw_show");
  }
  else {
    seq_printf(param_1,&DAT_00103a21,*(undefined1 *)(*(long *)(param_1 + 0x80) + 0x640));
  }
  return 0;
}



//------------------------------------------------------------
// cserial_attr_release @ 0010273c size=28
// signature: undefined cserial_attr_release(void)
// callers: []
//------------------------------------------------------------

void cserial_attr_release(void)

{
  usb_put_function_instance();
  return;
}



//------------------------------------------------------------
// usb_cser_status_show @ 0010275c size=260
// signature: undefined usb_cser_status_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long usb_cser_status_show(long param_1,undefined8 param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0xb8);
  lVar3 = kmalloc_trace(_class_destroy,0xdc0,0x200);
  if (lVar3 == 0) {
    lVar3 = -0xc;
  }
  else {
    uVar4 = _raw_spin_lock_irqsave(lVar5 + 0x42c);
    pcVar1 = "Closed";
    if (*(char *)(lVar5 + 0x611) != '\0') {
      pcVar1 = "Opened";
    }
    iVar2 = scnprintf(lVar3,0x200,
                      "###PORT:%s###\nport_no:%d\nfunc:%s\nnbytes_to_host: %lu\nnbytes_from_host: %lu\nnbytes_to_port_bridge:  %lu\nnbytes_from_port_bridge: %lu\ncbits_to_modem:  %u\nPort Opened: %s\n"
                      ,lVar5 + 0x41c,*(undefined4 *)(lVar5 + 0x418),*(undefined8 *)(param_1 + 0xc0),
                      *(undefined8 *)(lVar5 + 0x620),*(undefined8 *)(lVar5 + 0x618),
                      *(undefined8 *)(lVar5 + 0x628),*(undefined8 *)(lVar5 + 0x630),
                      *(undefined4 *)(lVar5 + 0x600),pcVar1);
    _raw_spin_unlock_irqrestore(lVar5 + 0x42c,uVar4);
    iVar2 = scnprintf(param_2,(long)iVar2,lVar3);
    kfree(lVar3);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// usb_cser_status_store @ 00102864 size=220
// signature: undefined usb_cser_status_store(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_cser_status_store(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  char local_3c [4];
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0xb8);
  local_3c[0] = '\0';
  if (param_2 == 0) {
    _printk(&DAT_00103d92,"usb_cser_status_store");
  }
  else {
    iVar1 = kstrtou8(param_2,0,local_3c);
    if ((iVar1 == 0) && (local_3c[0] == '\0')) {
      uVar2 = _raw_spin_lock_irqsave(lVar3 + 0x42c);
      *(undefined8 *)(lVar3 + 0x618) = 0;
      *(undefined8 *)(lVar3 + 0x620) = 0;
      *(undefined8 *)(lVar3 + 0x628) = 0;
      *(undefined8 *)(lVar3 + 0x630) = 0;
      _raw_spin_unlock_irqrestore(lVar3 + 0x42c,uVar2);
    }
    else {
      _printk(&DAT_00103a79,"usb_cser_status_store");
    }
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// usb_cser_bind @ 00102944 size=680
// signature: undefined usb_cser_bind(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int usb_cser_bind(long param_1,undefined8 *param_2)

{
  int iVar1;
  undefined8 *puVar2;
  long *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  long lVar6;
  
  puVar4 = *(undefined8 **)(param_1 + 0x30);
  lVar6 = param_2[0x19];
  if (cser_string_defs == '\0') {
    iVar1 = usb_string_id(puVar4);
    if (iVar1 < 0) {
      return iVar1;
    }
    cser_string_defs = (char)iVar1;
    cser_interface_desc[8] = cser_string_defs;
  }
  iVar1 = usb_interface_id(param_1,param_2);
  if (-1 < iVar1) {
    cser_interface_desc[2] = (undefined1)iVar1;
    *(undefined1 *)((long)param_2 + 0x101) = cser_interface_desc[2];
    cser_interface_desc[7] = *(undefined1 *)(lVar6 + 0xc9);
    puVar2 = (undefined8 *)usb_ep_autoconfig(*puVar4,cser_fs_in_desc);
    if (puVar2 != (undefined8 *)0x0) {
      param_2[0x1b] = puVar2;
      *puVar2 = puVar4;
      puVar2 = (undefined8 *)usb_ep_autoconfig(*puVar4,cser_fs_out_desc);
      if (puVar2 != (undefined8 *)0x0) {
        param_2[0x1c] = puVar2;
        *puVar2 = puVar4;
        puVar2 = (undefined8 *)usb_ep_autoconfig(*puVar4,cser_fs_notify_desc);
        if (puVar2 != (undefined8 *)0x0) {
          param_2[0x1d] = puVar2;
          *puVar2 = puVar4;
          plVar3 = (long *)usb_ep_alloc_request(puVar2,0xcc0);
          if (plVar3 == (long *)0x0) {
            _printk(&DAT_00103986,"usb_cser_alloc_req");
          }
          else {
            *(undefined4 *)(plVar3 + 1) = 10;
            lVar6 = kmalloc_trace(_mutex_unlock,0xcc0,10);
            *plVar3 = lVar6;
            if (lVar6 != 0) {
              param_2[0x1e] = plVar3;
              plVar3[6] = (long)usb_cser_notify_complete;
              cser_hs_in_desc[2] = cser_fs_in_desc[2];
              *(undefined8 **)(param_2[0x1e] + 0x38) = param_2 + -0x96;
              cser_ss_in_desc[2] = cser_hs_in_desc[2];
              cser_hs_out_desc[2] = cser_fs_out_desc[2];
              cser_ss_out_desc[2] = cser_fs_out_desc[2];
              if ((2 < *(uint *)(**(long **)(param_1 + 0x30) + 0x5c)) &&
                 (cser_hs_notify_desc[2] = cser_fs_notify_desc[2],
                 4 < *(uint *)(**(long **)(param_1 + 0x30) + 0x5c))) {
                cser_ss_notify_desc[2] = cser_fs_notify_desc[2];
              }
              iVar1 = usb_assign_descriptors
                                (param_2,&cser_fs_function,&cser_hs_function,&cser_ss_function,
                                 &cser_ss_function);
              if (iVar1 == 0) {
                return 0;
              }
              goto LAB_00102b0c;
            }
            _printk(&DAT_00103b5b,"usb_cser_alloc_req");
            usb_ep_free_request(puVar2,plVar3);
          }
          iVar1 = -0x13;
          param_2[0x1e] = 0;
          puVar4 = (undefined8 *)param_2[0x1e];
          goto joined_r0x00102b10;
        }
      }
    }
    iVar1 = -0x13;
  }
LAB_00102b0c:
  puVar4 = (undefined8 *)param_2[0x1e];
joined_r0x00102b10:
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)param_2[0x1d];
  }
  else {
    uVar5 = param_2[0x1d];
    kfree(*puVar4);
    usb_ep_free_request(uVar5,puVar4);
    puVar4 = (undefined8 *)param_2[0x1d];
  }
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)param_2[0x1c];
  }
  else {
    *puVar4 = 0;
    puVar4 = (undefined8 *)param_2[0x1c];
  }
  if (puVar4 == (undefined8 *)0x0) {
    puVar4 = (undefined8 *)param_2[0x1b];
  }
  else {
    *puVar4 = 0;
    puVar4 = (undefined8 *)param_2[0x1b];
  }
  if (puVar4 != (undefined8 *)0x0) {
    *puVar4 = 0;
  }
  _printk(&DAT_00103927,"usb_cser_bind",*param_2,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// usb_cser_unbind @ 00102bf0 size=116
// signature: undefined usb_cser_unbind(void)
// callers: []
//------------------------------------------------------------

void usb_cser_unbind(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  
  if (*(char *)(param_2 + 0x160) != '\0') {
    usb_cser_disconnect(param_2 + -0x4b0);
    usb_ep_disable(*(undefined8 *)(param_2 + 0xe8));
    **(undefined8 **)(param_2 + 0xe8) = 0;
  }
  cser_string_defs = 0;
  usb_free_all_descriptors(param_2);
  puVar2 = *(undefined8 **)(param_2 + 0xf0);
  if (puVar2 != (undefined8 *)0x0) {
    uVar1 = *(undefined8 *)(param_2 + 0xe8);
    kfree(*puVar2);
    usb_ep_free_request(uVar1,puVar2);
  }
  return;
}



//------------------------------------------------------------
// usb_cser_set_alt @ 00102c68 size=748
// signature: undefined usb_cser_set_alt(void)
// callers: []
//------------------------------------------------------------

int usb_cser_set_alt(long param_1)

{
  long *plVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long *plVar5;
  long lVar6;
  undefined *puVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  long *plVar11;
  
  plVar5 = *(long **)(param_1 + 0xe8);
  plVar8 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  if (*plVar5 != 0) {
    usb_ep_disable(plVar5);
    plVar5 = *(long **)(param_1 + 0xe8);
  }
  if (plVar5[7] == 0) {
    iVar2 = config_ep_by_speed(*plVar8,param_1);
    plVar5 = *(long **)(param_1 + 0xe8);
    if (iVar2 != 0) {
      plVar5[7] = 0;
      return -0x16;
    }
  }
  iVar2 = usb_ep_enable(plVar5);
  if (iVar2 != 0) {
    _dev_err(*plVar8 + 0x78,"can\'t enable %s, result %d\n",
             *(undefined8 *)(*(long *)(param_1 + 0xe8) + 8),iVar2);
    return iVar2;
  }
  lVar6 = param_1 + -0x4b0;
  **(long **)(param_1 + 0xe8) = lVar6;
  plVar5 = *(long **)(param_1 + 0xd8);
  if (*plVar5 != 0) {
    usb_cser_disconnect(lVar6);
    plVar5 = *(long **)(param_1 + 0xd8);
  }
  if (((plVar5[7] == 0) || (*(long *)(*(long *)(param_1 + 0xe0) + 0x38) == 0)) &&
     ((iVar2 = config_ep_by_speed(*plVar8,param_1), iVar2 != 0 ||
      (iVar2 = config_ep_by_speed(*plVar8,param_1,*(undefined8 *)(param_1 + 0xe0)), iVar2 != 0)))) {
    *(undefined8 *)(*(long *)(param_1 + 0xd8) + 0x38) = 0;
    *(undefined8 *)(*(long *)(param_1 + 0xe0) + 0x38) = 0;
    return -0x16;
  }
  if (lVar6 == 0) {
    _printk(&DAT_00103800,"usb_cser_connect");
    return 0;
  }
  *(code **)(param_1 + 0x148) = usb_cser_notify_modem;
  iVar2 = usb_ep_enable(*(undefined8 *)(param_1 + 0xd8));
  if (iVar2 != 0) {
    _printk(&DAT_00103bba,"usb_cser_connect",*(long **)(param_1 + 0xd8),iVar2);
    return 0;
  }
  **(long **)(param_1 + 0xd8) = lVar6;
  iVar2 = usb_ep_enable(*(undefined8 *)(param_1 + 0xe0));
  if (iVar2 != 0) {
    _printk(&DAT_001038df,"usb_cser_connect",*(long **)(param_1 + 0xe0),iVar2);
    **(undefined8 **)(param_1 + 0xd8) = 0;
    return 0;
  }
  lVar9 = param_1 + -0x84;
  **(long **)(param_1 + 0xe0) = lVar6;
  uVar3 = _raw_spin_lock_irqsave(lVar9);
  *(undefined2 *)(param_1 + 0xff) = 0;
  *(undefined1 *)(param_1 + 0x160) = 1;
  _raw_spin_unlock_irqrestore(lVar9,uVar3);
  uVar3 = _raw_spin_lock_irqsave(lVar9);
  if (*(char *)(param_1 + 0x160) != '\0') {
    plVar5 = (long *)(param_1 + -0x50);
    *(undefined8 *)(param_1 + -0x18) = 0;
    *(undefined8 *)(param_1 + -0x10) = 0;
    *(undefined8 *)(param_1 + -0x20) = 0;
    iVar2 = usb_cser_alloc_requests(*(undefined8 *)(param_1 + 0xe0),plVar5,usb_cser_read_complete);
    if (iVar2 == 0) {
      iVar2 = usb_cser_alloc_requests
                        (*(undefined8 *)(param_1 + 0xd8),param_1 + -0x30,usb_cser_write_complete);
      if (iVar2 == 0) {
        _raw_spin_unlock_irqrestore(lVar9,uVar3);
        usb_cser_start_rx(lVar6);
        goto LAB_00102ebc;
      }
      uVar10 = *(undefined8 *)(param_1 + 0xe0);
      puVar7 = &DAT_00103ab1;
      plVar8 = *(long **)(param_1 + -0x50);
      while (plVar8 != plVar5) {
        plVar11 = plVar8 + -8;
        uVar4 = __list_del_entry_valid(plVar8);
        if ((uVar4 & 1) != 0) {
          lVar6 = *plVar8;
          plVar1 = (long *)plVar8[1];
          *(long **)(lVar6 + 8) = plVar1;
          *plVar1 = lVar6;
        }
        *plVar8 = (long)plVar8;
        plVar8[1] = (long)plVar8;
        if (plVar11 != (long *)0x0) {
          kfree(*plVar11);
          usb_ep_free_request(uVar10,plVar11);
        }
        plVar8 = (long *)*plVar5;
      }
    }
    else {
      puVar7 = &DAT_00103dc5;
    }
    _printk(puVar7,"usb_cser_start_io");
  }
  _raw_spin_unlock_irqrestore(lVar9,uVar3);
LAB_00102ebc:
  __wake_up(param_1 + -0x80,3,1,0);
  return 0;
}



//------------------------------------------------------------
// usb_cser_disable @ 00102f58 size=60
// signature: undefined usb_cser_disable(void)
// callers: []
//------------------------------------------------------------

void usb_cser_disable(long param_1)

{
  usb_cser_disconnect(param_1 + -0x4b0);
  usb_ep_disable(*(undefined8 *)(param_1 + 0xe8));
  **(undefined8 **)(param_1 + 0xe8) = 0;
  return;
}



//------------------------------------------------------------
// usb_cser_setup @ 00102f98 size=316
// signature: undefined usb_cser_setup(void)
// callers: []
//------------------------------------------------------------

int usb_cser_setup(long param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  undefined8 *puVar5;
  long *plVar6;
  
  plVar6 = *(long **)(*(long *)(param_1 + 0x30) + 0x30);
  uVar1 = *param_2 >> 8 | *param_2 << 8;
  puVar5 = (undefined8 *)plVar6[1];
  if (uVar1 == 0xa121) {
    uVar3 = (uint)param_2[3];
    if (6 < uVar3) {
      uVar3 = 7;
    }
    memcpy((void *)*puVar5,(void *)(param_1 + 0xf8),(ulong)uVar3);
  }
  else if (uVar1 == 0x2122) {
    pcVar4 = *(code **)(param_1 + 0x148);
    *(ushort *)(param_1 + 0x104) = param_2[1];
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0xce76772) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103068);
        (*pcVar4)();
      }
      (*pcVar4)();
    }
    uVar3 = 0;
  }
  else {
    if ((uVar1 != 0x2120) || (param_2[3] != 7)) {
      return -0x5f;
    }
    uVar3 = 7;
    **(long **)(*plVar6 + 0x40) = param_1 + -0x4b0;
    puVar5[6] = port_complete_set_line_coding;
  }
  *(uint *)(puVar5 + 1) = uVar3;
  *(uint *)(puVar5 + 5) = *(uint *)(puVar5 + 5) & 0xfffbffff;
  iVar2 = usb_ep_queue(*(undefined8 *)(*plVar6 + 0x40),puVar5,0xa20);
  if (iVar2 < 0) {
    _printk(&DAT_00103bef,"usb_cser_setup",param_1 + -0x94,iVar2);
  }
  return iVar2;
}



//------------------------------------------------------------
// usb_cser_func_suspend @ 001030d8 size=28
// signature: undefined usb_cser_func_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_cser_func_suspend(long param_1,uint param_2)

{
  *(byte *)(param_1 + -7) = (byte)(param_2 >> 1) & 1;
  *(byte *)(param_1 + -8) = (byte)param_2 & 1;
  return 0;
}



//------------------------------------------------------------
// usb_cser_get_status @ 001030f8 size=8
// signature: undefined usb_cser_get_status(void)
// callers: []
//------------------------------------------------------------

undefined8 usb_cser_get_status(void)

{
  return 0;
}



//------------------------------------------------------------
// usb_cser_free_func @ 00103104 size=4
// signature: undefined usb_cser_free_func(void)
// callers: []
//------------------------------------------------------------

void usb_cser_free_func(void)

{
  return;
}



//------------------------------------------------------------
// usb_cser_notify_complete @ 0010310c size=132
// signature: undefined usb_cser_notify_complete(void)
// callers: []
//------------------------------------------------------------

void usb_cser_notify_complete(undefined8 param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x38);
  lVar1 = lVar3 + 0x42c;
  uVar2 = _raw_spin_lock_irqsave(lVar1);
  *(undefined1 *)(lVar3 + 0x5af) = 0;
  if ((*(int *)(param_2 + 0x54) != -0x6c) && (*(char *)(lVar3 + 0x5b0) != '\0')) {
    *(undefined1 *)(lVar3 + 0x5b0) = 0;
    _raw_spin_unlock_irqrestore(lVar1,uVar2);
    port_notify_serial_state(lVar3 + 0x4b0);
    uVar2 = _raw_spin_lock_irqsave(lVar1);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar2);
  return;
}



//------------------------------------------------------------
// usb_cser_disconnect @ 00103190 size=524
// signature: undefined usb_cser_disconnect(void)
// callers: [usb_cser_unbind, usb_cser_set_alt, usb_cser_disable]
//------------------------------------------------------------

void usb_cser_disconnect(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  ulong uVar5;
  undefined8 *puVar6;
  undefined8 *puVar7;
  long *plVar8;
  long *plVar9;
  
  puVar7 = *(undefined8 **)(param_1 + 0x590);
  puVar6 = *(undefined8 **)(param_1 + 0x588);
  usb_ep_disable(puVar7);
  *puVar7 = 0;
  usb_ep_disable(puVar6);
  lVar1 = param_1 + 0x42c;
  *puVar6 = 0;
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  if (*(undefined8 **)(param_1 + 0x490) != (undefined8 *)0x0) {
    kfree(**(undefined8 **)(param_1 + 0x490));
    usb_ep_free_request(puVar7,*(undefined8 *)(param_1 + 0x490));
  }
  *(undefined8 *)(param_1 + 0x4a0) = 0;
  *(undefined8 *)(param_1 + 0x498) = 0;
  plVar8 = *(long **)(param_1 + 0x470);
  while (plVar8 != (long *)(param_1 + 0x470)) {
    plVar9 = plVar8 + -8;
    uVar5 = __list_del_entry_valid(plVar8);
    if ((uVar5 & 1) != 0) {
      lVar2 = *plVar8;
      plVar3 = (long *)plVar8[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar8 = (long)plVar8;
    plVar8[1] = (long)plVar8;
    if (plVar9 != (long *)0x0) {
      kfree(*plVar9);
      usb_ep_free_request(puVar7,plVar9);
    }
    plVar8 = *(long **)(param_1 + 0x470);
  }
  plVar8 = *(long **)(param_1 + 0x460);
  while (plVar8 != (long *)(param_1 + 0x460)) {
    plVar9 = plVar8 + -8;
    uVar5 = __list_del_entry_valid(plVar8);
    if ((uVar5 & 1) != 0) {
      lVar2 = *plVar8;
      plVar3 = (long *)plVar8[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar8 = (long)plVar8;
    plVar8[1] = (long)plVar8;
    if (plVar9 != (long *)0x0) {
      kfree(*plVar9);
      usb_ep_free_request(puVar7,plVar9);
    }
    plVar8 = *(long **)(param_1 + 0x460);
  }
  plVar8 = *(long **)(param_1 + 0x480);
  while (plVar8 != (long *)(param_1 + 0x480)) {
    plVar9 = plVar8 + -8;
    uVar5 = __list_del_entry_valid(plVar8);
    if ((uVar5 & 1) != 0) {
      lVar2 = *plVar8;
      plVar3 = (long *)plVar8[1];
      *(long **)(lVar2 + 8) = plVar3;
      *plVar3 = lVar2;
    }
    *plVar8 = (long)plVar8;
    plVar8[1] = (long)plVar8;
    if (plVar9 != (long *)0x0) {
      kfree(*plVar9);
      usb_ep_free_request(puVar6,plVar9);
    }
    plVar8 = *(long **)(param_1 + 0x480);
  }
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  if (param_1 == 0) {
    _printk(&DAT_00103dec,"usb_cser_notify_modem");
  }
  else if (*(int *)(param_1 + 0x600) != 0) {
    *(undefined4 *)(param_1 + 0x600) = 0;
    *(undefined1 *)(param_1 + 0x604) = 1;
    __wake_up(param_1 + 0x448,3,1,0);
  }
  uVar4 = _raw_spin_lock_irqsave(lVar1);
  *(undefined1 *)(param_1 + 0x610) = 0;
  *(undefined8 *)(param_1 + 0x618) = 0;
  *(undefined8 *)(param_1 + 0x620) = 0;
  *(undefined8 *)(param_1 + 0x628) = 0;
  _raw_spin_unlock_irqrestore(lVar1,uVar4);
  return;
}



//------------------------------------------------------------
// usb_cser_notify_modem @ 001033a0 size=104
// signature: undefined usb_cser_notify_modem(void)
// callers: []
//------------------------------------------------------------

void usb_cser_notify_modem(long param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    _printk(&DAT_00103dec,"usb_cser_notify_modem");
  }
  else {
    iVar1 = (param_2 & 3) * 2;
    if (iVar1 != *(int *)(param_1 + 0x600)) {
      *(int *)(param_1 + 0x600) = iVar1;
      *(undefined1 *)(param_1 + 0x604) = 1;
      __wake_up(param_1 + 0x448,3,1,0);
    }
  }
  return;
}



//------------------------------------------------------------
// usb_cser_alloc_requests @ 00103408 size=276
// signature: undefined usb_cser_alloc_requests(void)
// callers: [usb_cser_set_alt]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 usb_cser_alloc_requests(undefined8 param_1,long *param_2,long param_3)

{
  long *plVar1;
  long *plVar2;
  long lVar3;
  ulong uVar4;
  undefined4 uVar5;
  long *plVar6;
  int iVar7;
  
  iVar7 = 8;
  do {
    plVar2 = (long *)usb_ep_alloc_request(param_1,0xa20);
    if (plVar2 == (long *)0x0) {
      _printk(&DAT_00103986,"usb_cser_alloc_req");
LAB_00103508:
      uVar5 = 0xfffffff4;
      if ((long *)*param_2 != param_2) {
        uVar5 = 0;
      }
      return uVar5;
    }
    *(undefined4 *)(plVar2 + 1) = 0x800;
    lVar3 = kmalloc_trace(_strnchr,0xa20,0x800);
    *plVar2 = lVar3;
    if (lVar3 == 0) {
      _printk(&DAT_00103b5b,"usb_cser_alloc_req");
      usb_ep_free_request(param_1,plVar2);
      goto LAB_00103508;
    }
    plVar2[6] = param_3;
    plVar1 = plVar2 + 8;
    plVar6 = (long *)param_2[1];
    uVar4 = __list_add_valid(plVar1,plVar6,param_2);
    if ((uVar4 & 1) != 0) {
      param_2[1] = (long)plVar1;
      plVar2[8] = (long)param_2;
      plVar2[9] = (long)plVar6;
      *plVar6 = (long)plVar1;
    }
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      return 0;
    }
  } while( true );
}



//------------------------------------------------------------
// usb_cser_write_complete @ 00103520 size=180
// signature: undefined usb_cser_write_complete(void)
// callers: []
//------------------------------------------------------------

void usb_cser_write_complete(long *param_1,long param_2)

{
  long lVar1;
  undefined8 uVar2;
  ulong uVar3;
  long *plVar4;
  long lVar5;
  
  lVar5 = *param_1;
  if (lVar5 == 0) {
    _printk(&DAT_00103dec,"usb_cser_write_complete");
  }
  else {
    uVar2 = _raw_spin_lock_irqsave(lVar5 + 0x42c);
    lVar1 = param_2 + 0x40;
    plVar4 = *(long **)(lVar5 + 0x488);
    *(ulong *)(lVar5 + 0x620) = *(long *)(lVar5 + 0x620) + (ulong)*(uint *)(param_2 + 0x58);
    uVar3 = __list_add_valid(lVar1,plVar4,lVar5 + 0x480);
    if ((uVar3 & 1) != 0) {
      *(long *)(lVar5 + 0x488) = lVar1;
      *(long *)(param_2 + 0x40) = lVar5 + 0x480;
      *(long **)(param_2 + 0x48) = plVar4;
      *plVar4 = lVar1;
    }
    _raw_spin_unlock_irqrestore(lVar5 + 0x42c,uVar2);
  }
  return;
}



//------------------------------------------------------------
// port_complete_set_line_coding @ 001035d8 size=80
// signature: undefined port_complete_set_line_coding(void)
// callers: []
//------------------------------------------------------------

void port_complete_set_line_coding(long *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  long lVar2;
  
  if (*(int *)((long)param_2 + 0x54) == 0) {
    if (*(int *)(param_2 + 0xb) == 7) {
      lVar2 = *param_1;
      uVar1 = *(undefined4 *)*param_2;
      *(undefined4 *)(lVar2 + 0x5ab) = *(undefined4 *)((long)*param_2 + 3);
      *(undefined4 *)(lVar2 + 0x5a8) = uVar1;
    }
    else {
      usb_ep_set_halt();
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 001036e8 size=36
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  usb_function_register(&cserusb_func);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103710 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  usb_function_unregister(&cserusb_func);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00106000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [port_notify_serial_state, f_cdev_open, usb_cser_status_show, usb_cser_read_complete, f_cdev_release, usb_cser_set_alt, usb_cser_status_store, usb_cser_start_rx, usb_cser_disconnect, usb_cser_write_complete, f_cdev_read, f_cdev_poll, usb_cser_notify_complete, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00106008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [port_notify_serial_state, f_cdev_open, usb_cser_status_show, usb_cser_read_complete, f_cdev_release, usb_cser_set_alt, usb_cser_status_store, usb_cser_start_rx, usb_cser_disconnect, usb_cser_write_complete, f_cdev_read, f_cdev_poll, usb_cser_notify_complete, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_queue @ 00106010 size=1
// signature: undefined usb_ep_queue(void)
// callers: [port_notify_serial_state, usb_cser_start_rx, usb_cser_read_complete, usb_cser_setup, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_queue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106018 size=1
// signature: undefined _printk(void)
// callers: [port_notify_serial_state, f_cdev_open, usb_cser_read_complete, usb_cser_notify_modem, usb_cser_bind, usb_cser_rw_show, usb_cser_set_alt, usb_cser_alloc_requests, usb_cser_status_store, usb_cser_start_rx, cser_rw_write, usb_cser_disconnect, usb_cser_write_complete, f_cdev_read, usb_cser_setup, f_cdev_poll, f_cdev_write, cser_set_inst_name, f_cdev_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 00106020 size=1
// signature: undefined get_device(void)
// callers: [f_cdev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00106028 size=1
// signature: undefined init_wait_entry(void)
// callers: [f_cdev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00106030 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [f_cdev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00106038 size=1
// signature: undefined schedule(void)
// callers: [f_cdev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00106040 size=1
// signature: undefined finish_wait(void)
// callers: [f_cdev_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00106048 size=1
// signature: undefined put_device(void)
// callers: [f_cdev_open, f_cdev_release, cser_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106050 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cser_rw_write, f_cdev_open, usb_cser_status_store, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00106058 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [usb_cser_start_rx, usb_cser_disconnect, f_cdev_read, usb_cser_set_alt, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00106060 size=1
// signature: undefined __list_add_valid(void)
// callers: [usb_cser_start_rx, usb_cser_write_complete, usb_cser_read_complete, f_cdev_read, usb_cser_alloc_requests, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00106068 size=1
// signature: undefined __check_object_size(void)
// callers: [f_cdev_read, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00106080 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [f_cdev_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00106090 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106098 size=1
// signature: undefined kfree(void)
// callers: [cdev_device_release, usb_cser_status_show, usb_cser_disconnect, usb_cser_bind, usb_cser_unbind, cser_free_inst, usb_cser_set_alt, f_cdev_write, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_free_request @ 001060a0 size=1
// signature: undefined usb_ep_free_request(void)
// callers: [usb_cser_disconnect, usb_cser_bind, usb_cser_unbind, usb_cser_set_alt, usb_cser_alloc_requests, f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_free_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001060a8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [f_cdev_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_register @ 001060b0 size=1
// signature: undefined usb_function_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_function_unregister @ 001060b8 size=1
// signature: undefined usb_function_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_function_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001060c0 size=1
// signature: undefined __wake_up(void)
// callers: [usb_cser_disconnect, usb_cser_read_complete, usb_cser_notify_modem, usb_cser_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 001060d0 size=1
// signature: undefined kmalloc_trace(void)
// callers: [usb_cser_status_show, cser_alloc_inst, usb_cser_bind, usb_cser_alloc_requests, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 001060d8 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [cser_alloc_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_device_del @ 001060e0 size=1
// signature: undefined cdev_device_del(void)
// callers: [cser_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_device_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001060e8 size=1
// signature: undefined mutex_lock(void)
// callers: [cser_free_inst, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_free @ 001060f0 size=1
// signature: undefined ida_free(void)
// callers: [cser_free_inst, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001060f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [cser_free_inst, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00106100 size=1
// signature: undefined debugfs_remove(void)
// callers: [cser_free_inst]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 00106108 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [cser_free_inst, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00106110 size=1
// signature: undefined class_destroy(void)
// callers: [cser_free_inst, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00106118 size=1
// signature: size_t strlen(char * __s)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnchr @ 00106120 size=1
// signature: undefined strnchr(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnchr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrndup @ 00106128 size=1
// signature: undefined kstrndup(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrndup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strrchr @ 00106130 size=1
// signature: char * strrchr(char * __s, int __c)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 00106138 size=1
// signature: undefined kstrtou8(void)
// callers: [usb_cser_status_store, cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00106140 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00106148 size=1
// signature: undefined __class_create(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ida_alloc_range @ 00106150 size=1
// signature: undefined ida_alloc_range(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ida_alloc_range(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00106158 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00106160 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00106168 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 00106170 size=1
// signature: undefined alloc_workqueue(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00106178 size=1
// signature: undefined cdev_init(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 00106180 size=1
// signature: undefined device_initialize(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 00106188 size=1
// signature: undefined dev_set_name(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_device_add @ 00106190 size=1
// signature: undefined cdev_device_add(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// destroy_workqueue @ 00106198 size=1
// signature: undefined destroy_workqueue(void)
// callers: [cser_set_inst_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void destroy_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001061a0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [usb_cser_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001061a8 size=1
// signature: undefined debugfs_create_file(void)
// callers: [usb_cser_debugfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8_from_user @ 001061b0 size=1
// signature: undefined kstrtou8_from_user(void)
// callers: [cser_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_gadget_wakeup @ 001061b8 size=1
// signature: undefined usb_gadget_wakeup(void)
// callers: [cser_rw_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_gadget_wakeup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001061c0 size=1
// signature: undefined single_open(void)
// callers: [debug_cdev_rw_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001061c8 size=1
// signature: undefined seq_printf(void)
// callers: [usb_cser_rw_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_put_function_instance @ 001061d0 size=1
// signature: undefined usb_put_function_instance(void)
// callers: [cserial_attr_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_put_function_instance(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001061d8 size=1
// signature: undefined scnprintf(void)
// callers: [usb_cser_status_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_string_id @ 001061e0 size=1
// signature: undefined usb_string_id(void)
// callers: [usb_cser_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_string_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_interface_id @ 001061e8 size=1
// signature: undefined usb_interface_id(void)
// callers: [usb_cser_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_interface_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_autoconfig @ 001061f0 size=1
// signature: undefined usb_ep_autoconfig(void)
// callers: [usb_cser_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_autoconfig(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_alloc_request @ 001061f8 size=1
// signature: undefined usb_ep_alloc_request(void)
// callers: [usb_cser_bind, usb_cser_alloc_requests]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_alloc_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_assign_descriptors @ 00106200 size=1
// signature: undefined usb_assign_descriptors(void)
// callers: [usb_cser_bind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_assign_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_disable @ 00106208 size=1
// signature: undefined usb_ep_disable(void)
// callers: [usb_cser_disconnect, usb_cser_unbind, usb_cser_set_alt, usb_cser_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_free_all_descriptors @ 00106210 size=1
// signature: undefined usb_free_all_descriptors(void)
// callers: [usb_cser_unbind]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_free_all_descriptors(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_enable @ 00106218 size=1
// signature: undefined usb_ep_enable(void)
// callers: [usb_cser_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_ep_by_speed @ 00106220 size=1
// signature: undefined config_ep_by_speed(void)
// callers: [usb_cser_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_ep_by_speed(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00106228 size=1
// signature: undefined _dev_err(void)
// callers: [usb_cser_set_alt]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00106230 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [usb_cser_setup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usb_ep_set_halt @ 00106238 size=1
// signature: undefined usb_ep_set_halt(void)
// callers: [port_complete_set_line_coding]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usb_ep_set_halt(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



