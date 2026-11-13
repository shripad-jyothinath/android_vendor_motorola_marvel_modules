// Decompiled by Ghidra 12.2
// Program: qcom_ipc_logging.ko
// Image base: 00100000

//------------------------------------------------------------
// ipc_log_write @ 001009fc size=540
// signature: undefined ipc_log_write(void)
// callers: [ipc_log_string]
//------------------------------------------------------------

void ipc_log_write(long param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  uint uVar8;
  undefined2 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  if ((param_1 == 0) || (param_2 == 0)) {
    _printk(&DAT_001030cc,"ipc_log_write");
LAB_00100bac:
    lVar5 = sp_el0;
    if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  uVar3 = _raw_read_lock_irqsave(&context_list_lock_lha1);
  _raw_spin_lock(param_1 + 0xa0);
  do {
    uVar1 = *(uint *)(param_2 + 0x104);
    do {
      if (uVar1 < *(uint *)(param_1 + 0x80)) {
        uVar6 = (ulong)*(ushort *)(*(long *)(param_1 + 0x68) + 0xe);
        uVar7 = 0xfb8 - uVar6;
        uVar8 = (uint)uVar7;
        if ((ulong)(long)(int)uVar1 <= uVar7) {
          uVar8 = uVar1;
        }
        memcpy((void *)(*(long *)(param_1 + 0x68) + uVar6 + 0x48),(void *)(param_2 + 2),
               (long)(int)uVar8);
        if (uVar8 != *(uint *)(param_2 + 0x104)) {
          uVar4 = sched_clock();
          *(short *)(*(long *)(param_1 + 0x68) + 0xe) =
               *(short *)(*(long *)(param_1 + 0x68) + 0xe) + (short)uVar8;
          *(undefined8 *)(*(long *)(param_1 + 0x68) + 0x20) = uVar4;
          lVar5 = *(long *)(param_1 + 0x68);
          if (lVar5 == 0) {
            *(undefined8 *)(param_1 + 0x68) = 0;
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100be8);
            (*pcVar2)();
          }
          if (*(long *)(param_1 + 0x60) == lVar5) {
            lVar5 = *(long *)(param_1 + 0x58);
            *(long *)(param_1 + 0x68) = lVar5;
          }
          else {
            lVar5 = *(long *)(lVar5 + 0x30) + -0x30;
            *(long *)(param_1 + 0x68) = lVar5;
          }
          if (lVar5 == 0) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x800,0x100bfc);
            (*pcVar2)();
          }
          *(undefined2 *)(lVar5 + 0xe) = 0;
          *(undefined8 *)(*(long *)(param_1 + 0x68) + 0x18) = uVar4;
          if (0xff < uVar8) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100c20);
            (*pcVar2)();
          }
          memcpy((void *)(*(long *)(param_1 + 0x68) +
                          (ulong)*(ushort *)(*(long *)(param_1 + 0x68) + 0xe) + 0x48),
                 (void *)(param_2 + 2 + (long)(int)uVar8),
                 (long)(int)(*(int *)(param_2 + 0x104) - uVar8));
          uVar8 = *(int *)(param_2 + 0x104) - uVar8;
        }
        *(short *)(*(long *)(param_1 + 0x68) + 0xe) =
             *(short *)(*(long *)(param_1 + 0x68) + 0xe) + (short)uVar8;
        *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) - *(int *)(param_2 + 0x104);
        complete(param_1 + 0xa8);
        _raw_spin_unlock(param_1 + 0xa0);
        _raw_read_unlock_irqrestore(&context_list_lock_lha1,uVar3);
        goto LAB_00100bac;
      }
      lVar5 = *(long *)(param_1 + 0x70);
      local_60 = 0;
    } while ((lVar5 == *(long *)(param_1 + 0x68)) &&
            (*(short *)(lVar5 + 0xc) == *(short *)(lVar5 + 0xe)));
    ipc_log_drop(param_1,&local_60,2);
    ipc_log_drop(param_1,0,local_60._1_1_);
  } while( true );
}



//------------------------------------------------------------
// msg_encode_start @ 00100c24 size=68
// signature: undefined msg_encode_start(void)
// callers: []
//------------------------------------------------------------

void msg_encode_start(undefined1 *param_1,undefined1 param_2)

{
  if (param_1 == (undefined1 *)0x0) {
    _printk(&DAT_00103174,"msg_encode_start");
  }
  else {
    *param_1 = param_2;
    param_1[1] = 0;
    *(undefined4 *)(param_1 + 0x104) = 2;
  }
  return;
}



//------------------------------------------------------------
// msg_encode_end @ 00100c6c size=72
// signature: undefined msg_encode_end(void)
// callers: []
//------------------------------------------------------------

void msg_encode_end(undefined2 *param_1)

{
  if (param_1 == (undefined2 *)0x0) {
    _printk(&DAT_00103174,"msg_encode_end");
  }
  else {
    *(char *)((long)param_1 + 1) = *(char *)(param_1 + 0x82) + -2;
    param_1[1] = *param_1;
  }
  return;
}



//------------------------------------------------------------
// tsv_timestamp_write @ 00100cb8 size=176
// signature: undefined tsv_timestamp_write(void)
// callers: []
//------------------------------------------------------------

undefined8 tsv_timestamp_write(long param_1)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined8 uVar4;
  undefined *puVar5;
  
  uVar4 = sched_clock();
  if (param_1 == 0) {
    puVar5 = &DAT_00103174;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104);
    if (0xfffffeff < uVar1 - 0xfe) {
      if (0xff < uVar1) {
LAB_00100d64:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100d68);
        (*pcVar3)();
      }
      *(undefined2 *)(param_1 + 2 + (ulong)uVar1) = 0x801;
      iVar2 = *(int *)(param_1 + 0x104);
      uVar1 = iVar2 + 2;
      *(uint *)(param_1 + 0x104) = uVar1;
      if (0xfffffeff < iVar2 - 0xf6U) {
        if (uVar1 < 0x100) {
          *(undefined8 *)(param_1 + 2 + (ulong)uVar1) = uVar4;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 8;
          return 0;
        }
        goto LAB_00100d64;
      }
    }
    puVar5 = &DAT_00103133;
  }
  _printk(puVar5,"tsv_write_data");
  return 0xffffffea;
}



//------------------------------------------------------------
// tsv_qtimer_write @ 00100d6c size=184
// signature: undefined tsv_qtimer_write(void)
// callers: []
//------------------------------------------------------------

undefined8 tsv_qtimer_write(long param_1)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  undefined *puVar5;
  
  InstructionSynchronizationBarrier();
  uVar3 = cntvct_el0;
  if (param_1 == 0) {
    puVar5 = &DAT_00103174;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104);
    if (0xfffffeff < uVar1 - 0xfe) {
      if (0xff < uVar1) {
LAB_00100e20:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100e24);
        (*pcVar4)();
      }
      *(undefined2 *)(param_1 + 2 + (ulong)uVar1) = 0x805;
      iVar2 = *(int *)(param_1 + 0x104);
      uVar1 = iVar2 + 2;
      *(uint *)(param_1 + 0x104) = uVar1;
      if (0xfffffeff < iVar2 - 0xf6U) {
        if (uVar1 < 0x100) {
          *(undefined8 *)(param_1 + 2 + (ulong)uVar1) = uVar3;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 8;
          return 0;
        }
        goto LAB_00100e20;
      }
    }
    puVar5 = &DAT_00103133;
  }
  _printk(puVar5,"tsv_write_data");
  return 0xffffffea;
}



//------------------------------------------------------------
// tsv_pointer_write @ 00100e28 size=164
// signature: undefined tsv_pointer_write(void)
// callers: []
//------------------------------------------------------------

undefined8 tsv_pointer_write(long param_1,undefined8 param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined *puVar4;
  
  if (param_1 == 0) {
    puVar4 = &DAT_00103174;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104);
    if (0xfffffeff < uVar1 - 0xfe) {
      if (0xff < uVar1) {
LAB_00100ec8:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100ecc);
        (*pcVar3)();
      }
      *(undefined2 *)(param_1 + 2 + (ulong)uVar1) = 0x802;
      iVar2 = *(int *)(param_1 + 0x104);
      uVar1 = iVar2 + 2;
      *(uint *)(param_1 + 0x104) = uVar1;
      if (0xfffffeff < iVar2 - 0xf6U) {
        if (uVar1 < 0x100) {
          *(undefined8 *)(param_1 + 2 + (ulong)uVar1) = param_2;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 8;
          return 0;
        }
        goto LAB_00100ec8;
      }
    }
    puVar4 = &DAT_00103133;
  }
  _printk(puVar4,"tsv_write_data");
  return 0xffffffea;
}



//------------------------------------------------------------
// tsv_int32_write @ 00100ed0 size=164
// signature: undefined tsv_int32_write(void)
// callers: []
//------------------------------------------------------------

undefined8 tsv_int32_write(long param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  code *pcVar3;
  undefined *puVar4;
  
  if (param_1 == 0) {
    puVar4 = &DAT_00103174;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104);
    if (0xfffffeff < uVar1 - 0xfe) {
      if (0xff < uVar1) {
LAB_00100f70:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100f74);
        (*pcVar3)();
      }
      *(undefined2 *)(param_1 + 2 + (ulong)uVar1) = 0x403;
      iVar2 = *(int *)(param_1 + 0x104);
      uVar1 = iVar2 + 2;
      *(uint *)(param_1 + 0x104) = uVar1;
      if (0xfffffeff < iVar2 - 0xfaU) {
        if (uVar1 < 0x100) {
          *(undefined4 *)(param_1 + 2 + (ulong)uVar1) = param_2;
          *(int *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 4;
          return 0;
        }
        goto LAB_00100f70;
      }
    }
    puVar4 = &DAT_00103133;
  }
  _printk(puVar4,"tsv_write_data");
  return 0xffffffea;
}



//------------------------------------------------------------
// tsv_byte_array_write @ 00100f78 size=200
// signature: undefined tsv_byte_array_write(void)
// callers: []
//------------------------------------------------------------

undefined8 tsv_byte_array_write(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  code *pcVar2;
  undefined *puVar3;
  
  if (param_1 == 0) {
    puVar3 = &DAT_00103174;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x104);
    if (0xfffffeff < uVar1 - 0xfe) {
      if (0xff < uVar1) {
LAB_0010103c:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101040);
        (*pcVar2)();
      }
      *(ushort *)(param_1 + 2 + (ulong)uVar1) = (ushort)(param_3 << 8) | 4;
      uVar1 = *(int *)(param_1 + 0x104) + 2;
      *(uint *)(param_1 + 0x104) = uVar1;
      if (uVar1 + param_3 < 0x100) {
        if ((uVar1 < 0x100) && (*(uint *)(param_1 + 0x104) < 0x100)) {
          memcpy((void *)(param_1 + 2 + (ulong)*(uint *)(param_1 + 0x104)),param_2,(ulong)param_3);
          *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + param_3;
          return 0;
        }
        goto LAB_0010103c;
      }
    }
    puVar3 = &DAT_00103133;
  }
  _printk(puVar3,"tsv_write_data");
  return 0xffffffea;
}



//------------------------------------------------------------
// ipc_log_string @ 00101044 size=676
// signature: undefined ipc_log_string(void)
// callers: []
//------------------------------------------------------------

void ipc_log_string(long param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  undefined8 uVar5;
  undefined1 *local_180;
  undefined1 **ppuStack_178;
  undefined8 local_170;
  undefined8 uStack_168;
  undefined2 local_140;
  undefined2 local_13e;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  memset(&local_140,0,0x104);
  if (param_1 == 0) {
    uVar5 = 0xffffffea;
    goto LAB_00101264;
  }
  local_140 = 2;
  local_3c = 2;
  uVar5 = sched_clock();
  uVar1 = local_3c;
  if (local_3c - 0xfe < 0xffffff00) {
LAB_00101290:
    local_3c = uVar1;
    _printk(&DAT_00103133,"tsv_write_data");
  }
  else {
    if (0xff < local_3c) goto LAB_001012dc;
    if ((ulong)local_3c - 0x105 < 2) goto LAB_001012e0;
    *(undefined2 *)(((ulong)&local_140 | 2) + (ulong)local_3c) = 0x801;
    uVar1 = local_3c + 2;
    if (local_3c - 0xf6 < 0xffffff00) goto LAB_00101290;
    if (0xff < uVar1) goto LAB_001012dc;
    if ((ulong)uVar1 - 0xff < 8) goto LAB_001012e0;
    *(undefined8 *)(((ulong)&local_140 | 2) + (ulong)uVar1) = uVar5;
    local_3c = local_3c + 10;
  }
  InstructionSynchronizationBarrier();
  uVar5 = cntvct_el0;
  uVar1 = local_3c;
  if (local_3c - 0xfe < 0xffffff00) {
LAB_001012a8:
    local_3c = uVar1;
    _printk(&DAT_00103133,"tsv_write_data");
  }
  else {
    if (0xff < local_3c) goto LAB_001012dc;
    if ((ulong)local_3c - 0x105 < 2) goto LAB_001012e0;
    *(undefined2 *)(((ulong)&local_140 | 2) + (ulong)local_3c) = 0x805;
    uVar1 = local_3c + 2;
    if (local_3c - 0xf6 < 0xffffff00) goto LAB_001012a8;
    if (0xff < uVar1) goto LAB_001012dc;
    if ((ulong)uVar1 - 0xff < 8) goto LAB_001012e0;
    *(undefined8 *)(((ulong)&local_140 | 2) + (ulong)uVar1) = uVar5;
    local_3c = local_3c + 10;
  }
  uVar1 = local_3c;
  if (0xff < local_3c) {
LAB_001012dc:
    local_3c = uVar1;
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1012e0);
    (*pcVar3)();
  }
  local_170 = 0;
  uStack_168 = 0xffffffd0;
  local_180 = (undefined1 *)register0x00000008;
  ppuStack_178 = &local_180;
  iVar4 = vscnprintf(((ulong)&local_140 | 2) + (ulong)local_3c + 2,(long)(int)(0xfd - local_3c),
                     param_2,&local_180);
  if (local_3c - 0xfe < 0xffffff00) {
    _printk(&DAT_00103133,"tsv_write_data");
  }
  else {
    uVar1 = local_3c;
    if (0xff < local_3c) goto LAB_001012dc;
    if ((ulong)local_3c - 0x105 < 2) {
LAB_001012e0:
      local_3c = uVar1;
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x1012e4);
      (*pcVar3)();
    }
    *(ushort *)(((ulong)&local_140 | 2) + (ulong)local_3c) = (ushort)(iVar4 << 8) | 4;
    local_3c = local_3c + 2;
  }
  local_3c = local_3c + iVar4;
  local_140 = CONCAT11((char)local_3c + -2,(undefined1)local_140);
  local_13e = local_140;
  ipc_log_write(param_1,&local_140);
  uVar5 = 0;
LAB_00101264:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// ipc_log_extract @ 001012ec size=584
// signature: undefined ipc_log_extract(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

int ipc_log_extract(long param_1,undefined8 param_2,uint param_3)

{
  long lVar1;
  undefined8 uVar2;
  uint uVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  code *pcVar7;
  undefined8 local_198;
  undefined8 local_190;
  ulong local_188;
  undefined2 local_180;
  byte local_178;
  undefined1 local_177;
  undefined4 local_74;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  memset(&local_178,0,0x108);
  local_190 = 0;
  local_188 = 0;
  local_198 = 0;
  if ((int)param_3 < 0x3fc) {
    iVar6 = -0x16;
    goto LAB_001014e0;
  }
  local_188 = (ulong)param_3;
  local_190 = param_2;
  uVar2 = _raw_read_lock_irqsave(&context_list_lock_lha1);
  lVar1 = param_1 + 0xa0;
  _raw_spin_lock(lVar1);
  if (*(char *)(param_1 + 0xcc) == '\0') {
    uVar3 = param_3;
    if (param_1 != 0) {
      do {
        lVar5 = *(long *)(param_1 + 0x78);
        if (lVar5 == *(long *)(param_1 + 0x68)) {
          if (*(short *)(lVar5 + 0x40) == *(short *)(lVar5 + 0xe)) break;
          local_180 = 0;
          if (*(short *)(lVar5 + 0x40) != *(short *)(lVar5 + 0xe)) goto LAB_001013e8;
        }
        else {
LAB_001013e8:
          local_180 = 0;
          ipc_log_read(param_1,&local_180,2);
          local_74 = 2;
          local_178 = (byte)local_180;
          local_177 = local_180._1_1_;
          ipc_log_read(param_1,(ulong)&local_178 | 4);
        }
        plVar4 = (long *)(param_1 + 0x90);
        do {
          plVar4 = (long *)*plVar4;
          if (plVar4 == (long *)(param_1 + 0x90)) {
            pcVar7 = (code *)0x0;
            goto LAB_00101444;
          }
        } while (*(uint *)(plVar4 + 2) != (uint)local_178);
        pcVar7 = (code *)plVar4[3];
LAB_00101444:
        _raw_spin_unlock(lVar1);
        _raw_read_unlock_irqrestore(&context_list_lock_lha1,uVar2);
        if (pcVar7 == (code *)0x0) {
          _printk(&DAT_001030f5,"ipc_log_extract",local_178);
        }
        else {
          if (*(int *)(pcVar7 + -4) != -0x2764e71a) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8239,0x10147c);
            (*pcVar7)();
          }
          (*pcVar7)(&local_178,&local_198);
        }
        uVar2 = _raw_read_lock_irqsave(&context_list_lock_lha1);
        _raw_spin_lock(lVar1);
        uVar3 = (uint)local_188;
      } while (0x3fb < (int)(uint)local_188);
    }
    iVar6 = param_3 - uVar3;
    if (iVar6 == 0) {
      if (*(char *)(param_1 + 0xcc) != '\0') goto LAB_0010137c;
      iVar6 = 0;
      *(undefined4 *)(param_1 + 0xa8) = 0;
    }
  }
  else {
LAB_0010137c:
    iVar6 = -5;
  }
  _raw_spin_unlock(lVar1);
  _raw_read_unlock_irqrestore(&context_list_lock_lha1,uVar2);
LAB_001014e0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// tsv_timestamp_read @ 00101538 size=288
// signature: undefined tsv_timestamp_read(void)
// callers: [dfunc_string]
//------------------------------------------------------------

void tsv_timestamp_read(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong uVar7;
  
  lVar6 = sp_el0;
  lVar6 = *(long *)(lVar6 + 0x638);
  uVar3 = *(uint *)(param_1 + 0x104);
  if ((long)(int)uVar3 - 0xfeU < 0xfffffffffffffeff || (long)(int)uVar3 == -3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x101648);
    (*pcVar4)();
  }
  if (0xff < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1016f0);
    (*pcVar4)();
  }
  cVar2 = *(char *)(param_1 + (ulong)uVar3 + 2);
  lVar1 = (ulong)uVar3 + 2;
  *(int *)(param_1 + 0x104) = (int)lVar1;
  if (cVar2 != '\x01') {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1016e8);
    (*pcVar4)();
  }
  if (0xf5 < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10169c);
    (*pcVar4)();
  }
  uVar7 = *(ulong *)(param_1 + lVar1 + 2);
  *(uint *)(param_1 + 0x104) = uVar3 + 10;
  iVar5 = scnprintf(*(undefined8 *)(param_2 + 8),(long)*(int *)(param_2 + 0x10),"[%6u.%09lu%s/",
                    uVar7 / 1000000000,uVar7 % 1000000000,param_3);
  *(long *)(param_2 + 8) = *(long *)(param_2 + 8) + (long)iVar5;
  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - iVar5;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsv_qtimer_read @ 00101704 size=248
// signature: undefined tsv_qtimer_read(void)
// callers: [dfunc_string]
//------------------------------------------------------------

void tsv_qtimer_read(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  
  lVar7 = sp_el0;
  lVar7 = *(long *)(lVar7 + 0x638);
  uVar3 = *(uint *)(param_1 + 0x104);
  if ((long)(int)uVar3 - 0xfeU < 0xfffffffffffffeff || (long)(int)uVar3 == -3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1017ec);
    (*pcVar4)();
  }
  if (0xff < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101894);
    (*pcVar4)();
  }
  cVar2 = *(char *)(param_1 + (ulong)uVar3 + 2);
  lVar1 = (ulong)uVar3 + 2;
  *(int *)(param_1 + 0x104) = (int)lVar1;
  if (cVar2 != '\x05') {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x10188c);
    (*pcVar4)();
  }
  if (0xf5 < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x101840);
    (*pcVar4)();
  }
  uVar6 = *(undefined8 *)(param_1 + lVar1 + 2);
  *(uint *)(param_1 + 0x104) = uVar3 + 10;
  iVar5 = scnprintf(*(undefined8 *)(param_2 + 8),(long)*(int *)(param_2 + 0x10),&DAT_001031a1,uVar6,
                    param_3);
  *(long *)(param_2 + 8) = *(long *)(param_2 + 8) + (long)iVar5;
  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - iVar5;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsv_pointer_read @ 001018a8 size=236
// signature: undefined tsv_pointer_read(void)
// callers: []
//------------------------------------------------------------

void tsv_pointer_read(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  char cVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  
  lVar7 = sp_el0;
  lVar7 = *(long *)(lVar7 + 0x638);
  uVar3 = *(uint *)(param_1 + 0x104);
  if ((long)(int)uVar3 - 0xfeU < 0xfffffffffffffeff || (long)(int)uVar3 == -3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x101984);
    (*pcVar4)();
  }
  if (0xff < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101a2c);
    (*pcVar4)();
  }
  cVar2 = *(char *)(param_1 + (ulong)uVar3 + 2);
  lVar1 = (ulong)uVar3 + 2;
  *(int *)(param_1 + 0x104) = (int)lVar1;
  if (cVar2 != '\x02') {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x101a24);
    (*pcVar4)();
  }
  if (0xf5 < uVar3) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x800,0x1019d8);
    (*pcVar4)();
  }
  uVar6 = *(undefined8 *)(param_1 + lVar1 + 2);
  *(uint *)(param_1 + 0x104) = uVar3 + 10;
  iVar5 = scnprintf(*(undefined8 *)(param_2 + 8),(long)*(int *)(param_2 + 0x10),param_3,uVar6);
  *(long *)(param_2 + 8) = *(long *)(param_2 + 8) + (long)iVar5;
  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - iVar5;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// tsv_int32_read @ 00101a40 size=252
// signature: undefined tsv_int32_read(void)
// callers: []
//------------------------------------------------------------

undefined4 tsv_int32_read(long param_1,long param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  
  lVar7 = sp_el0;
  lVar7 = *(long *)(lVar7 + 0x638);
  uVar4 = *(uint *)(param_1 + 0x104);
  if ((long)(int)uVar4 - 0xfeU < 0xfffffffffffffeff || (long)(int)uVar4 == -3) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101b28);
    (*pcVar5)();
  }
  if (0xff < uVar4) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101bd4);
    (*pcVar5)();
  }
  cVar3 = *(char *)(param_1 + (ulong)uVar4 + 2);
  lVar1 = (ulong)uVar4 + 2;
  *(int *)(param_1 + 0x104) = (int)lVar1;
  if (cVar3 != '\x03') {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101bcc);
    (*pcVar5)();
  }
  if (0xf9 < uVar4) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101b7c);
    (*pcVar5)();
  }
  uVar2 = *(undefined4 *)(param_1 + lVar1 + 2);
  *(uint *)(param_1 + 0x104) = uVar4 + 6;
  iVar6 = scnprintf(*(undefined8 *)(param_2 + 8),(long)*(int *)(param_2 + 0x10),param_3,uVar2);
  *(long *)(param_2 + 8) = *(long *)(param_2 + 8) + (long)iVar6;
  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - iVar6;
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != lVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}



//------------------------------------------------------------
// tsv_byte_array_read @ 00101be8 size=264
// signature: undefined tsv_byte_array_read(void)
// callers: [dfunc_string]
//------------------------------------------------------------

void tsv_byte_array_read(long param_1,long param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  byte bStack_3b;
  
  lVar6 = sp_el0;
  lVar6 = *(long *)(lVar6 + 0x638);
  uVar3 = *(uint *)(param_1 + 0x104);
  if ((long)(int)uVar3 - 0xfeU < 0xfffffffffffffeff || (long)(int)uVar3 == -3) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101ce0);
    (*pcVar5)();
  }
  if (uVar3 < 0x100) {
    uVar1 = uVar3 + 2;
    uVar2 = *(ushort *)(param_1 + (ulong)uVar3 + 2);
    *(uint *)(param_1 + 0x104) = uVar1;
    if ((uVar2 & 0xff) != 4) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101d2c);
      (*pcVar5)();
    }
    bStack_3b = (byte)(uVar2 >> 8);
    if (0xff < uVar1 + bStack_3b) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101d34);
      (*pcVar5)();
    }
    if ((uVar1 < 0x100) && (*(uint *)(param_1 + 0x104) < 0x100)) {
      memcpy(*(void **)(param_2 + 8),(void *)(param_1 + 2 + (ulong)*(uint *)(param_1 + 0x104)),
             (ulong)bStack_3b);
      *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + (uint)bStack_3b;
      *(ulong *)(param_2 + 8) = *(long *)(param_2 + 8) + (ulong)bStack_3b;
      *(uint *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) - (uint)bStack_3b;
      lVar4 = sp_el0;
      if (*(long *)(lVar4 + 0x638) != lVar6) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x101d70);
  (*pcVar5)();
}



//------------------------------------------------------------
// add_deserialization_func @ 00101d84 size=220
// signature: undefined add_deserialization_func(void)
// callers: [create_ctx_debugfs]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 add_deserialization_func(long param_1,undefined4 param_2,long param_3)

{
  undefined8 uVar1;
  long *plVar2;
  ulong uVar3;
  undefined8 *puVar4;
  
  uVar1 = 0xffffffea;
  if ((param_1 != 0) && (param_3 != 0)) {
    plVar2 = (long *)kmalloc_trace(___init_swait_queue_head,0xcc0,0x20);
    if (plVar2 == (long *)0x0) {
      uVar1 = 0xffffffe4;
    }
    else {
      uVar1 = _raw_read_lock_irqsave(&context_list_lock_lha1);
      _raw_spin_lock(param_1 + 0xa0);
      puVar4 = *(undefined8 **)(param_1 + 0x98);
      *(undefined4 *)(plVar2 + 2) = param_2;
      plVar2[3] = param_3;
      uVar3 = __list_add_valid(plVar2,puVar4,param_1 + 0x90);
      if ((uVar3 & 1) != 0) {
        *(long **)(param_1 + 0x98) = plVar2;
        *plVar2 = param_1 + 0x90;
        plVar2[1] = (long)puVar4;
        *puVar4 = plVar2;
      }
      _raw_spin_unlock(param_1 + 0xa0);
      _raw_read_unlock_irqrestore(&context_list_lock_lha1,uVar1);
      uVar1 = 0;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// ipc_log_context_create @ 00101e64 size=948
// signature: undefined ipc_log_context_create(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined ** ipc_log_context_create(uint param_1,undefined **param_2,uint param_3,ulong param_4)

{
  undefined8 *puVar1;
  long *plVar2;
  long lVar3;
  uint uVar4;
  int iVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined **ppuVar9;
  char *pcVar10;
  undefined *puVar11;
  undefined **ppuVar12;
  long *plVar13;
  undefined8 *unaff_x21;
  undefined **ppuVar14;
  ulong unaff_x23;
  undefined **ppuVar15;
  undefined1 auVar16 [16];
  undefined8 uStack_e8;
  undefined8 uStack_e0;
  undefined8 uStack_d8;
  long lStack_d0;
  long lStack_c8;
  undefined8 uStack_c0;
  long lStack_b8;
  long lStack_b0;
  code *pcStack_a8;
  ulong uStack_a0;
  undefined **ppuStack_90;
  undefined8 *puStack_88;
  undefined **ppuStack_80;
  undefined **ppuStack_78;
  uint local_68;
  undefined4 local_64;
  
  local_68 = param_1;
  local_64 = param_3;
  _raw_read_lock_irq(&context_list_lock_lha1);
  ppuVar12 = &ipc_log_context_list;
  do {
    ppuVar12 = (undefined **)*ppuVar12;
    if (ppuVar12 == &ipc_log_context_list) {
      _raw_read_unlock_irq(&context_list_lock_lha1);
      goto LAB_00101eec;
    }
    iVar5 = strcmp((char *)(ppuVar12 + -4),(char *)param_2);
  } while (iVar5 != 0);
  _raw_read_unlock_irq(&context_list_lock_lha1);
  if (ppuVar12 + -7 != (undefined **)0x0) {
    return ppuVar12 + -7;
  }
LAB_00101eec:
  ppuVar12 = (undefined **)kmalloc_trace(__raw_write_lock_irqsave,0xdc0,0x4e8);
  if (ppuVar12 == (undefined **)0x0) {
    return (undefined **)0x0;
  }
  pcVar10 = &init_completion___key;
  *(undefined4 *)(ppuVar12 + 0x15) = 0;
  __init_swait_queue_head(ppuVar12 + 0x16,"&x->wait",&init_completion___key);
  ppuVar15 = ppuVar12 + 0x14;
  *(undefined4 *)ppuVar15 = 0;
  ppuVar9 = ppuVar12 + 9;
  ppuVar12[9] = (undefined *)ppuVar9;
  ppuVar12[10] = (undefined *)ppuVar9;
  ppuVar12[0x12] = (undefined *)(ppuVar12 + 0x12);
  ppuVar12[0x13] = (undefined *)(ppuVar12 + 0x12);
  uVar6 = _raw_spin_lock_irqsave(ppuVar15);
  if ((local_64 >> 0x10 & 1) != 0) {
    pcVar10 = "ipc_ctxt";
    param_4 = (ulong)minidump_buf_cnt;
    register_minidump(ppuVar12,0x4e8,"ipc_ctxt",param_4);
  }
  _raw_spin_unlock_irqrestore(ppuVar15,uVar6);
  if ((int)local_68 < 1) {
    puVar7 = (undefined8 *)0x0;
  }
  else {
    unaff_x23 = 0;
    do {
      puVar7 = (undefined8 *)kmalloc_trace(__raw_write_unlock_irqrestore,0xdc0,0x1000);
      iVar5 = (int)unaff_x23;
      if (puVar7 == (undefined8 *)0x0) {
        if (iVar5 != 0) {
          iVar5 = iVar5 + 1;
          do {
            plVar13 = (long *)*ppuVar9;
            uVar8 = __list_del_entry_valid(plVar13);
            if ((uVar8 & 1) != 0) {
              lVar3 = *plVar13;
              plVar2 = (long *)plVar13[1];
              *(long **)(lVar3 + 8) = plVar2;
              *plVar2 = lVar3;
            }
            *plVar13 = -0x2152ffffffffff00;
            plVar13[1] = -0x2152fffffffffede;
            kfree(plVar13 + -6);
            iVar5 = iVar5 + -1;
          } while (1 < iVar5);
        }
        kfree(ppuVar12);
        return (undefined **)0x0;
      }
      puVar7[2] = ppuVar12;
      puVar7[5] = (long)ppuVar12 - (long)puVar7;
      *(int *)(puVar7 + 1) = iVar5 + -0x80000000;
      *puVar7 = 0xad87bbda52784425;
      uVar6 = _raw_spin_lock_irqsave(ppuVar15);
      unaff_x21 = (undefined8 *)ppuVar12[10];
      puVar1 = puVar7 + 6;
      pcVar10 = (char *)ppuVar9;
      uVar8 = __list_add_valid(puVar1,unaff_x21,ppuVar9);
      if ((uVar8 & 1) != 0) {
        ppuVar12[10] = (undefined *)puVar1;
        puVar7[6] = ppuVar9;
        puVar7[7] = unaff_x21;
        *unaff_x21 = puVar1;
      }
      if ((local_64 >> 0x10 & 1) != 0) {
        param_4 = (ulong)minidump_buf_cnt;
        pcVar10 = (char *)param_2;
        register_minidump(puVar7,0x1000,param_2,param_4);
      }
      _raw_spin_unlock_irqrestore(ppuVar15,uVar6);
      unaff_x23 = (ulong)(iVar5 + 1U);
    } while (local_68 != iVar5 + 1U);
  }
  ppuVar12[2] = (undefined *)ppuVar12;
  *(undefined4 *)(ppuVar12 + 1) = 3;
  ppuVar9 = (undefined **)strnlen((char *)param_2,0x20);
  if (ppuVar9 == (undefined **)0xffffffffffffffff) {
    fortify_panic("strnlen");
LAB_0010220c:
    auVar16 = fortify_panic("strscpy");
    pcStack_a8 = register_minidump;
    ppuStack_80 = &ipc_log_context_list;
    lVar3 = sp_el0;
    lStack_b8 = *(long *)(lVar3 + 0x638);
    lStack_c8 = 0;
    uStack_c0 = 0;
    uStack_d8 = 0;
    lStack_d0 = 0;
    uStack_e8 = 0;
    uStack_e0 = 0;
    lStack_b0 = (long)register0x00000008 + -0x60;
    uStack_a0 = unaff_x23;
    ppuStack_90 = param_2;
    puStack_88 = unaff_x21;
    ppuStack_78 = ppuVar12;
    ppuVar12 = (undefined **)msm_minidump_enabled();
    if ((((ulong)ppuVar12 & 1) != 0) && ((int)minidump_buf_cnt < 0x10)) {
      scnprintf(&uStack_e8,0xd,"%s_%d",pcVar10,param_4 & 0xffffffff);
      lVar3 = (auVar16._0_8_ << 8) >> 8;
      uVar8 = lVar3 + 0x8000000000;
      lStack_c8 = _memstart_addr + uVar8;
      if (uVar8 >> 0x26 != 0) {
        lStack_c8 = lVar3 - _kimage_voffset;
      }
      lStack_d0 = auVar16._0_8_;
      uStack_c0 = auVar16._8_8_;
      ppuVar12 = (undefined **)msm_minidump_add_region(&uStack_e8);
      if ((int)ppuVar12 < 0) {
        ppuVar12 = (undefined **)
                   _printk(&DAT_0010305a,pcVar10,param_4 & 0xffffffff,(ulong)ppuVar12 & 0xffffffff);
      }
      else {
        minidump_buf_cnt = minidump_buf_cnt + 1;
      }
    }
    lVar3 = sp_el0;
    if (*(long *)(lVar3 + 0x638) != lStack_b8) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return ppuVar12;
  }
  if (ppuVar9 != (undefined **)0x20) {
    ppuVar9 = (undefined **)((long)ppuVar9 + 1);
  }
  pcVar10 = (char *)ppuVar9;
  if ((undefined **)0x20 < ppuVar9) goto LAB_0010220c;
  strscpy(ppuVar12 + 3,param_2);
  uVar4 = local_64;
  puVar11 = ppuVar12[9] + -0x30;
  *(short *)((long)ppuVar12 + 0xc) = (short)local_64;
  ppuVar12[0xb] = puVar11;
  ppuVar12[0xc] = (undefined *)puVar7;
  ppuVar12[0xd] = puVar11;
  ppuVar12[0xe] = puVar11;
  ppuVar12[0xf] = puVar11;
  *(uint *)(ppuVar12 + 0x10) = local_68 * 0xfb8;
  *(undefined2 *)((long)ppuVar12 + 0xe) = 0x48;
  *(undefined4 *)(ppuVar12 + 0x19) = 1;
  *(undefined1 *)((long)ppuVar12 + 0xcc) = 0;
  create_ctx_debugfs(ppuVar12,param_2);
  *ppuVar12 = (undefined *)0xda78bbad25874452;
  uVar6 = _raw_write_lock_irqsave(&context_list_lock_lha1);
  ppuVar14 = (undefined **)PTR_ipc_log_context_list_001031d0;
  ppuVar15 = (undefined **)ipc_log_context_list;
  ppuVar9 = ppuVar12 + 7;
  if (((uVar4 >> 0x10 & 1) == 0) || (0xf < (int)minidump_buf_cnt)) {
    uVar8 = __list_add_valid(ppuVar9,PTR_ipc_log_context_list_001031d0,&ipc_log_context_list);
    if ((uVar8 & 1) == 0) goto LAB_00102164;
    ppuVar15 = &ipc_log_context_list;
  }
  else {
    uVar8 = __list_add_valid(ppuVar9,&ipc_log_context_list,ipc_log_context_list);
    if ((uVar8 & 1) == 0) goto LAB_00102164;
    ppuVar14 = &ipc_log_context_list;
  }
  ppuVar15[1] = (undefined *)ppuVar9;
  ppuVar12[7] = (undefined *)ppuVar15;
  ppuVar12[8] = (undefined *)ppuVar14;
  *ppuVar14 = (undefined *)ppuVar9;
LAB_00102164:
  _raw_write_unlock_irqrestore(&context_list_lock_lha1,uVar6);
  return ppuVar12;
}



//------------------------------------------------------------
// register_minidump @ 00102218 size=280
// signature: undefined register_minidump(void)
// callers: [init_module, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void register_minidump(long param_1,undefined8 param_2,undefined8 param_3,undefined4 param_4)

{
  long lVar1;
  int iVar2;
  ulong uVar3;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  uVar3 = msm_minidump_enabled();
  if (((uVar3 & 1) != 0) && (minidump_buf_cnt < 0x10)) {
    scnprintf(&local_78,0xd,"%s_%d",param_3,param_4);
    lVar1 = (param_1 << 8) >> 8;
    uVar3 = lVar1 + 0x8000000000;
    local_58 = _memstart_addr + uVar3;
    if (uVar3 >> 0x26 != 0) {
      local_58 = lVar1 - _kimage_voffset;
    }
    local_60 = param_1;
    local_50 = param_2;
    iVar2 = msm_minidump_add_region(&local_78);
    if (iVar2 < 0) {
      _printk(&DAT_0010305a,param_3,param_4,iVar2);
    }
    else {
      minidump_buf_cnt = minidump_buf_cnt + 1;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ipc_log_context_free @ 00102334 size=148
// signature: undefined ipc_log_context_free(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

void ipc_log_context_free(long param_1)

{
  long lVar1;
  long lVar2;
  ulong uVar3;
  long *plVar4;
  long *plVar5;
  
  plVar5 = (long *)(param_1 + -0x80);
  plVar4 = (long *)*plVar5;
  while (plVar4 != plVar5) {
    lVar1 = 0;
    if (param_1 + -200 != 0) {
      lVar1 = (long)(plVar4 + -6);
    }
    uVar3 = __list_del_entry_valid(lVar1 + 0x30);
    if ((uVar3 & 1) != 0) {
      lVar2 = *(long *)(lVar1 + 0x30);
      plVar4 = *(long **)(lVar1 + 0x38);
      *(long **)(lVar2 + 8) = plVar4;
      *plVar4 = lVar2;
    }
    *(undefined8 *)(lVar1 + 0x30) = 0xdead000000000100;
    *(undefined8 *)(lVar1 + 0x38) = 0xdead000000000122;
    kfree(lVar1);
    plVar4 = (long *)*plVar5;
  }
  kfree(param_1 + -200);
  return;
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001023cc size=400
// signature: undefined ipc_log_context_destroy(void)
// callers: []
//------------------------------------------------------------

undefined8 ipc_log_context_destroy(long param_1)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  int iVar4;
  char cVar5;
  bool bVar6;
  undefined8 uVar7;
  ulong uVar8;
  long *plVar9;
  long *plVar10;
  
  if (param_1 != 0) {
    debugfs_remove(*(undefined8 *)(param_1 + 0x88));
    _raw_spin_lock(param_1 + 0xa0);
    *(undefined1 *)(param_1 + 0xcc) = 1;
    complete_all(param_1 + 0xa8);
    plVar9 = *(long **)(param_1 + 0x90);
    while (plVar9 != (long *)(param_1 + 0x90)) {
      plVar10 = (long *)*plVar9;
      uVar8 = __list_del_entry_valid(plVar9);
      if ((uVar8 & 1) != 0) {
        lVar2 = *plVar9;
        plVar3 = (long *)plVar9[1];
        *(long **)(lVar2 + 8) = plVar3;
        *plVar3 = lVar2;
      }
      *plVar9 = -0x2152ffffffffff00;
      plVar9[1] = -0x2152fffffffffede;
      kfree(plVar9);
      plVar9 = plVar10;
    }
    _raw_spin_unlock(param_1 + 0xa0);
    uVar7 = _raw_write_lock_irqsave(&context_list_lock_lha1);
    uVar8 = __list_del_entry_valid(param_1 + 0x38);
    if ((uVar8 & 1) != 0) {
      lVar2 = *(long *)(param_1 + 0x38);
      plVar9 = *(long **)(param_1 + 0x40);
      *(long **)(lVar2 + 8) = plVar9;
      *plVar9 = lVar2;
    }
    *(undefined8 *)(param_1 + 0x38) = 0xdead000000000100;
    *(undefined8 *)(param_1 + 0x40) = 0xdead000000000122;
    _raw_write_unlock_irqrestore(&context_list_lock_lha1,uVar7);
    piVar1 = (int *)(param_1 + 200);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = iVar4 + -1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    if (iVar4 == 1) {
      DataMemoryBarrier(2,1);
      plVar10 = (long *)(param_1 + 0x48);
      plVar9 = (long *)*plVar10;
      while (plVar9 != plVar10) {
        uVar8 = __list_del_entry_valid(plVar9);
        if ((uVar8 & 1) != 0) {
          lVar2 = *plVar9;
          plVar3 = (long *)plVar9[1];
          *(long **)(lVar2 + 8) = plVar3;
          *plVar3 = lVar2;
        }
        *plVar9 = -0x2152ffffffffff00;
        plVar9[1] = -0x2152fffffffffede;
        kfree(plVar9 + -6);
        plVar9 = (long *)*plVar10;
      }
      kfree(param_1);
    }
    else if (iVar4 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  return 0;
}



//------------------------------------------------------------
// ipc_log_drop @ 0010256c size=448
// signature: undefined ipc_log_drop(void)
// callers: [ipc_log_write]
//------------------------------------------------------------

void ipc_log_drop(long param_1,void *param_2,uint param_3)

{
  long lVar1;
  short sVar2;
  code *pcVar3;
  size_t __n;
  long lVar4;
  uint uVar5;
  
  __n = 0xfb8 - (ulong)*(ushort *)(*(long *)(param_1 + 0x70) + 0xc);
  if (param_3 <= __n) {
    __n = (ulong)param_3;
  }
  if (param_2 != (void *)0x0) {
    memcpy(param_2,(void *)(*(long *)(param_1 + 0x70) +
                            (ulong)*(ushort *)(*(long *)(param_1 + 0x70) + 0xc) + 0x48),__n);
  }
  uVar5 = param_3;
  if ((uint)__n != param_3) {
    lVar4 = *(long *)(param_1 + 0x78);
    if ((lVar4 == *(long *)(param_1 + 0x70)) &&
       (*(short *)(lVar4 + 0xc) == *(short *)(lVar4 + 0x40))) {
      *(undefined2 *)(lVar4 + 0xc) = 0;
      *(undefined2 *)(*(long *)(param_1 + 0x70) + 0x40) = 0;
      if ((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0x70), lVar4 == 0)) {
        *(undefined8 *)(param_1 + 0x70) = 0;
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102710);
        (*pcVar3)();
      }
      if (*(long *)(param_1 + 0x60) == lVar4) {
        lVar4 = *(long *)(param_1 + 0x58);
      }
      else {
        lVar4 = *(long *)(lVar4 + 0x30) + -0x30;
      }
      *(long *)(param_1 + 0x70) = lVar4;
      if (lVar4 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102734);
        (*pcVar3)();
      }
      *(long *)(param_1 + 0x78) = lVar4;
    }
    else {
      *(undefined2 *)(*(long *)(param_1 + 0x70) + 0xc) = 0;
      if ((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0x70), lVar4 == 0)) {
        *(undefined8 *)(param_1 + 0x70) = 0;
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1026dc);
        (*pcVar3)();
      }
      if (*(long *)(param_1 + 0x60) == lVar4) {
        lVar4 = *(long *)(param_1 + 0x58);
        *(long *)(param_1 + 0x70) = lVar4;
      }
      else {
        lVar4 = *(long *)(lVar4 + 0x30) + -0x30;
        *(long *)(param_1 + 0x70) = lVar4;
      }
      if (lVar4 == 0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102704);
        (*pcVar3)();
      }
    }
    uVar5 = param_3 - (uint)__n;
    if (param_2 != (void *)0x0) {
      memcpy((void *)((long)param_2 + __n),
             (void *)(*(long *)(param_1 + 0x70) +
                      (ulong)*(ushort *)(*(long *)(param_1 + 0x70) + 0xc) + 0x48),(long)(int)uVar5);
    }
  }
  lVar4 = *(long *)(param_1 + 0x70);
  lVar1 = *(long *)(param_1 + 0x78);
  sVar2 = (short)uVar5;
  if ((lVar1 == lVar4) && (*(short *)(lVar1 + 0xc) == *(short *)(lVar1 + 0x40))) {
    *(short *)(lVar1 + 0xc) = *(short *)(lVar1 + 0xc) + sVar2;
    *(uint *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + param_3;
    *(short *)(*(long *)(param_1 + 0x78) + 0x40) =
         *(short *)(*(long *)(param_1 + 0x78) + 0x40) + sVar2;
  }
  else {
    *(short *)(lVar4 + 0xc) = *(short *)(lVar4 + 0xc) + sVar2;
    *(uint *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + param_3;
  }
  return;
}



//------------------------------------------------------------
// ipc_log_read @ 00102738 size=228
// signature: undefined ipc_log_read(void)
// callers: [ipc_log_extract]
//------------------------------------------------------------

void ipc_log_read(long param_1,void *param_2,uint param_3)

{
  uint uVar1;
  code *pcVar2;
  ulong uVar3;
  long lVar4;
  ulong uVar5;
  
  uVar5 = (ulong)*(ushort *)(*(long *)(param_1 + 0x78) + 0x40);
  uVar3 = 0xfb8 - uVar5;
  uVar1 = (uint)uVar3;
  if (param_3 <= uVar3) {
    uVar1 = param_3;
  }
  memcpy(param_2,(void *)(*(long *)(param_1 + 0x78) + uVar5 + 0x48),(ulong)uVar1);
  if (uVar1 != param_3) {
    *(undefined2 *)(*(long *)(param_1 + 0x78) + 0x40) = 0;
    if ((param_1 == 0) || (lVar4 = *(long *)(param_1 + 0x78), lVar4 == 0)) {
      *(undefined8 *)(param_1 + 0x78) = 0;
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1027f8);
      (*pcVar2)();
    }
    if (*(long *)(param_1 + 0x60) == lVar4) {
      lVar4 = *(long *)(param_1 + 0x58);
      *(long *)(param_1 + 0x78) = lVar4;
    }
    else {
      lVar4 = *(long *)(lVar4 + 0x30) + -0x30;
      *(long *)(param_1 + 0x78) = lVar4;
    }
    if (lVar4 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10281c);
      (*pcVar2)();
    }
    param_3 = param_3 - uVar1;
    memcpy((void *)((long)param_2 + (ulong)uVar1),
           (void *)(*(long *)(param_1 + 0x78) + (ulong)*(ushort *)(*(long *)(param_1 + 0x78) + 0x40)
                   + 0x48),(long)(int)param_3);
  }
  *(short *)(*(long *)(param_1 + 0x78) + 0x40) =
       *(short *)(*(long *)(param_1 + 0x78) + 0x40) + (short)param_3;
  return;
}



//------------------------------------------------------------
// check_and_create_debugfs @ 00102834 size=128
// signature: undefined check_and_create_debugfs(void)
// callers: [init_module]
//------------------------------------------------------------

void check_and_create_debugfs(void)

{
  mutex_lock(&ipc_log_debugfs_init_lock);
  if (root_dent == 0) {
    root_dent = debugfs_create_dir("ipc_logging",0);
    if (0xfffffffffffff000 < root_dent) {
      _printk(&DAT_00103036,"check_and_create_debugfs",root_dent);
      root_dent = 0;
    }
  }
  mutex_unlock(&ipc_log_debugfs_init_lock);
  return;
}



//------------------------------------------------------------
// create_ctx_debugfs @ 001028b8 size=264
// signature: undefined create_ctx_debugfs(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

void create_ctx_debugfs(long param_1,undefined8 param_2)

{
  ulong uVar1;
  
  if (root_dent == 0) {
    mutex_lock(&ipc_log_debugfs_init_lock);
    if (root_dent == 0) {
      root_dent = debugfs_create_dir("ipc_logging",0);
      if (0xfffffffffffff000 < root_dent) {
        _printk(&DAT_00103036,"check_and_create_debugfs",root_dent);
        root_dent = 0;
      }
    }
    mutex_unlock(&ipc_log_debugfs_init_lock);
    if (root_dent == 0) goto LAB_00102978;
  }
  uVar1 = debugfs_create_dir(param_2);
  *(ulong *)(param_1 + 0x88) = uVar1;
  if (uVar1 < 0xfffffffffffff001) {
    debugfs_create_file_unsafe(&DAT_001030bf,0x124,uVar1,param_1,&debug_ops);
    debugfs_create_file_unsafe
              ("log_cont",0x124,*(undefined8 *)(param_1 + 0x88),param_1,debug_ops_cont);
  }
LAB_00102978:
  add_deserialization_func(param_1,2,dfunc_string);
  return;
}



//------------------------------------------------------------
// dfunc_string @ 001029c4 size=148
// signature: undefined dfunc_string(void)
// callers: []
//------------------------------------------------------------

void dfunc_string(undefined8 param_1,long param_2)

{
  long lVar1;
  
  tsv_timestamp_read(param_1,param_2,&DAT_00103094);
  tsv_qtimer_read(param_1,param_2,&DAT_00103120);
  tsv_byte_array_read(param_1,param_2,&DAT_00103094);
  lVar1 = *(long *)(param_2 + 8);
  if (*(char *)(lVar1 + -1) != '\n') {
    if (*(int *)(param_2 + 0x10) != 0) {
      lVar1 = lVar1 + 1;
      *(long *)(param_2 + 8) = lVar1;
      *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + -1;
    }
    *(undefined1 *)(lVar1 + -1) = 10;
  }
  return;
}



//------------------------------------------------------------
// debug_read @ 00102a5c size=32
// signature: undefined debug_read(void)
// callers: []
//------------------------------------------------------------

void debug_read(void)

{
  debug_read_helper();
  return;
}



//------------------------------------------------------------
// debug_read_helper @ 00102a7c size=752
// signature: undefined debug_read_helper(void)
// callers: [debug_read_cont, debug_read]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long debug_read_helper(long param_1,ulong param_2,ulong param_3,long *param_4,int param_5)

{
  uint uVar1;
  char cVar2;
  bool bVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  undefined8 *puVar8;
  ulong uVar9;
  undefined8 uVar10;
  uint *puVar11;
  long lVar12;
  uint uVar13;
  ulong uVar14;
  
  uVar10 = *(undefined8 *)(param_1 + 0x18);
  iVar5 = debugfs_file_get(uVar10);
  if (iVar5 == 0) {
    lVar12 = *(long *)(param_1 + 0xd8);
    puVar11 = (uint *)(lVar12 + 200);
    uVar6 = *puVar11;
    if (*puVar11 == 0) {
      uVar13 = 0;
    }
    else {
      do {
        Hint_Prefetch(puVar11,2,0,1);
        do {
          uVar1 = *puVar11;
          if (uVar1 != uVar6) break;
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar11,0x10);
          if (bVar3) {
            *puVar11 = uVar6 + 1;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        uVar13 = uVar6;
        if (uVar6 == uVar1) break;
        uVar13 = 0;
        uVar6 = uVar1;
      } while (uVar1 != 0);
    }
    if ((int)(uVar13 + 1 | uVar13) < 0) {
      refcount_warn_saturate(puVar11,0);
    }
    if (uVar13 == 0) {
      debugfs_file_put(uVar10);
      lVar12 = -5;
    }
    else {
      lVar7 = __kmalloc(param_3,0xcc0);
      if (lVar7 == 0) {
        lVar12 = -0xc;
      }
      else {
        if ((int)param_3 < 0x3fc) {
          _printk(&DAT_00102ffe,"debug_log",param_3 & 0xffffffff,0x3fc);
          uVar6 = 0xfffffff4;
        }
        else {
          do {
            uVar6 = ipc_log_extract(lVar12,lVar7,(int)param_3 + -1);
            uVar14 = (ulong)uVar6;
            if ((param_5 == 0) || (uVar6 != 0)) {
              if ((int)uVar6 < 1) break;
              __check_object_size(lVar7,uVar14,1);
              puVar8 = (undefined8 *)sp_el0;
              if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
                 (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
                uVar9 = param_2 & (long)(param_2 << 8) >> 8;
              }
              if (uVar9 <= 0x8000000000 - uVar14) {
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar9 = daif;
                  if ((uVar9 & 0x80) == 0) {
                    uVar4 = daif;
                    daif = uVar4 | 0xc0;
                  }
                  puVar8 = (undefined8 *)puVar8[1];
                  uVar4 = ttbr1_el1;
                  ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar4 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  ttbr0_el1 = puVar8;
                  InstructionSynchronizationBarrier();
                  daif = uVar9;
                }
                lVar12 = __arch_copy_to_user(puVar8,param_2 & 0xff7fffffffffffff,lVar7,uVar14);
                if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                  uVar9 = daif;
                  if ((uVar9 & 0x80) == 0) {
                    uVar4 = daif;
                    daif = uVar4 | 0xc0;
                  }
                  uVar4 = ttbr1_el1;
                  ttbr0_el1 = (uVar4 & 0xffffffffffff) - 0x1000;
                  InstructionSynchronizationBarrier();
                  ttbr1_el1 = uVar4 & 0xffffffffffff;
                  InstructionSynchronizationBarrier();
                  daif = uVar9;
                }
                if (lVar12 == 0) {
                  *param_4 = *param_4 + uVar14;
                  break;
                }
              }
              kfree(lVar7);
              lVar12 = -0xe;
              goto LAB_00102cd0;
            }
            uVar6 = wait_for_completion_interruptible(lVar12 + 0xa8);
          } while (-1 < (int)uVar6);
        }
        kfree(lVar7);
        lVar12 = (long)(int)uVar6;
      }
LAB_00102cd0:
      Hint_Prefetch(puVar11,2,0,1);
      do {
        uVar6 = *puVar11;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar11,0x10);
        if (bVar3) {
          *puVar11 = uVar6 - 1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      if (uVar6 == 1) {
        DataMemoryBarrier(2,1);
        ipc_log_context_free(puVar11);
      }
      else if ((int)uVar6 < 1) {
        refcount_warn_saturate(puVar11,3);
      }
      debugfs_file_put(uVar10);
    }
  }
  else {
    lVar12 = (long)iVar5;
  }
  return lVar12;
}



//------------------------------------------------------------
// debug_read_cont @ 00102dac size=32
// signature: undefined debug_read_cont(void)
// callers: []
//------------------------------------------------------------

void debug_read_cont(void)

{
  debug_read_helper();
  return;
}



//------------------------------------------------------------
// init_module @ 00102f88 size=64
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  check_and_create_debugfs();
  register_minidump(&ipc_log_context_list,0x10,"ipc_log_ctxt_list",minidump_buf_cnt);
  return 0;
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 00105000 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [ipc_log_extract, add_deserialization_func, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00105008 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [ipc_log_extract, add_deserialization_func, ipc_log_context_destroy, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00105010 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [ipc_log_drop, tsv_byte_array_write, ipc_log_read, ipc_log_write, tsv_byte_array_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00105018 size=1
// signature: undefined sched_clock(void)
// callers: [tsv_timestamp_write, ipc_log_string, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 00105020 size=1
// signature: undefined complete(void)
// callers: [ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00105028 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [ipc_log_extract, add_deserialization_func, ipc_log_context_destroy, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 00105030 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [ipc_log_extract, add_deserialization_func, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00105038 size=1
// signature: undefined _printk(void)
// callers: [tsv_timestamp_write, register_minidump, msg_encode_start, tsv_pointer_write, tsv_int32_write, msg_encode_end, tsv_qtimer_write, ipc_log_extract, check_and_create_debugfs, create_ctx_debugfs, ipc_log_string, tsv_byte_array_write, debug_read_helper, ipc_log_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00105040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [register_minidump, tsv_timestamp_read, ipc_log_string, tsv_qtimer_read, ipc_log_extract, tsv_int32_read, tsv_pointer_read, ipc_log_write, tsv_byte_array_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00105048 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [ipc_log_string, ipc_log_extract]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vscnprintf @ 00105050 size=1
// signature: undefined vscnprintf(void)
// callers: [ipc_log_string]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vscnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00105058 size=1
// signature: undefined scnprintf(void)
// callers: [register_minidump, tsv_timestamp_read, tsv_qtimer_read, tsv_int32_read, tsv_pointer_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00105060 size=1
// signature: undefined fortify_panic(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00105070 size=1
// signature: undefined kmalloc_trace(void)
// callers: [add_deserialization_func, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00105078 size=1
// signature: undefined __list_add_valid(void)
// callers: [add_deserialization_func, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irq @ 00105080 size=1
// signature: undefined _raw_read_lock_irq(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00105088 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irq @ 00105090 size=1
// signature: undefined _raw_read_unlock_irq(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00105098 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001050a0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001050a8 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 001050b0 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 001050b8 size=1
// signature: undefined strscpy(void)
// callers: [ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irqsave @ 001050c0 size=1
// signature: undefined _raw_write_lock_irqsave(void)
// callers: [ipc_log_context_destroy, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irqrestore @ 001050c8 size=1
// signature: undefined _raw_write_unlock_irqrestore(void)
// callers: [ipc_log_context_destroy, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001050d0 size=1
// signature: undefined kfree(void)
// callers: [ipc_log_context_free, debug_read_helper, ipc_log_context_destroy, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001050d8 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [ipc_log_context_free, ipc_log_context_destroy, ipc_log_context_create]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_enabled @ 001050e0 size=1
// signature: undefined msm_minidump_enabled(void)
// callers: [register_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 001050f8 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [register_minidump]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 00105100 size=1
// signature: undefined debugfs_remove(void)
// callers: [ipc_log_context_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00105108 size=1
// signature: undefined complete_all(void)
// callers: [ipc_log_context_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 00105118 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [debug_read_helper, ipc_log_context_destroy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00105120 size=1
// signature: undefined mutex_lock(void)
// callers: [check_and_create_debugfs, create_ctx_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00105128 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [check_and_create_debugfs, create_ctx_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00105130 size=1
// signature: undefined mutex_unlock(void)
// callers: [check_and_create_debugfs, create_ctx_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file_unsafe @ 00105138 size=1
// signature: undefined debugfs_create_file_unsafe(void)
// callers: [create_ctx_debugfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file_unsafe(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_file_get @ 00105140 size=1
// signature: undefined debugfs_file_get(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_file_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00105148 size=1
// signature: undefined __kmalloc(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 00105150 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00105158 size=1
// signature: undefined __check_object_size(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 00105168 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_file_put @ 00105170 size=1
// signature: undefined debugfs_file_put(void)
// callers: [debug_read_helper]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_file_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



