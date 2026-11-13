// Decompiled by Ghidra 12.2
// Program: gh_dbl.ko
// Image base: 00100000

//------------------------------------------------------------
// gh_dbl_read_and_clean @ 0010044c size=344
// signature: undefined gh_dbl_read_and_clean(void)
// callers: []
//------------------------------------------------------------

int gh_dbl_read_and_clean(uint *param_1,undefined8 *param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  if (param_2 == (undefined8 *)0x0) {
    iVar4 = -0x16;
  }
  else {
    iVar4 = gh_dbl_validate_params(param_1,1);
    if (iVar4 == 0) {
      uVar1 = *param_1;
      if (10 < uVar1) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1005a0);
        (*pcVar3)();
      }
      if (0x3a0 < (ulong)uVar1 * 0x60) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x1005a4);
        (*pcVar3)();
      }
      CallHyperVisor(0x6013);
      iVar4 = -0xc;
      switch((int)(&DAT_00101b30)[(ulong)uVar1 * 0xc]) {
      case 0:
        iVar4 = 0;
        *param_2 = *param_2;
        goto LAB_00100568;
      default:
        iVar4 = -0x16;
        break;
      case 10:
        break;
      case 0x1e:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
        iVar4 = -0xd;
        break;
      case 0x1f:
      case 0x20:
        iVar4 = -0x10;
        break;
      case 0x28:
      case 0x29:
      case 0x3c:
      case 0x3d:
        iVar4 = -5;
        break;
      case -2:
      case -1:
        iVar4 = -0x5f;
      }
      _printk(&DAT_00101efd,"gh_dbl_read_and_clean",(&DAT_00101b30)[(ulong)uVar1 * 0xc],0,0,0,0,0,0)
      ;
    }
  }
LAB_00100568:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_dbl_validate_params @ 001005a4 size=708
// signature: undefined gh_dbl_validate_params(void)
// callers: [gh_dbl_set_mask, gh_dbl_reset, gh_dbl_send, gh_dbl_read_and_clean]
//------------------------------------------------------------

undefined4 gh_dbl_validate_params(uint *param_1,int param_2,ulong param_3)

{
  undefined4 *puVar1;
  ulong uVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  undefined4 uVar6;
  long *plVar7;
  undefined *puVar8;
  ulong uVar9;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar5 = sp_el0;
  uVar6 = 0xffffffea;
  local_58 = *(long *)(lVar5 + 0x638);
  if ((param_1 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < param_1)) goto LAB_001007f8;
  uVar3 = *param_1;
  uVar9 = (ulong)uVar3;
  if (9 < uVar3) goto LAB_001007f8;
  puVar1 = &DAT_00101b18 + uVar9 * 0x18;
  _raw_spin_lock(puVar1);
  if (0x3c0 < uVar9 * 0x60) goto LAB_00100864;
  if (*(uint **)(&gh_dbl_cap_table + uVar9 * 0x60) != param_1) {
    _raw_spin_unlock(puVar1);
    _printk(&DAT_0010209b,"gh_dbl_validate_params");
    uVar6 = 0xffffffea;
    goto LAB_001007f8;
  }
  if (param_2 == 1) {
    if (0x394 < uVar9 * 0x60) goto LAB_00100864;
    if (*(int *)(&DAT_00101b3c + (ulong)uVar3 * 0x60) != 0) {
      if ((param_3 >> 0x20 & 1) != 0) {
        if (0x3a0 < uVar9 * 0x60) goto LAB_00100864;
        plVar7 = &DAT_00101b30 + uVar9 * 0xc;
        goto LAB_001007cc;
      }
      _raw_spin_unlock(puVar1);
      if (0x3a0 < uVar9 * 0x60) goto LAB_00100864;
      if ((&DAT_00101b30)[uVar9 * 0xc] == -1) {
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_80 = 0;
        init_wait_entry(&local_80,0);
        puVar8 = &DAT_00101b58 + (ulong)uVar3 * 0x60;
        while (lVar5 = prepare_to_wait_event(puVar8,&local_80,1), uVar9 * 0x60 < 0x3a1) {
          if ((&DAT_00101b30)[uVar9 * 0xc] != -1) goto LAB_001007e8;
          if (lVar5 != 0) goto LAB_00100854;
          schedule();
        }
        goto LAB_00100864;
      }
      goto LAB_001007f4;
    }
LAB_00100788:
    uVar6 = 0xffffffea;
  }
  else {
    if (0x3c0 < (uVar9 * 0x60 | 0x18)) goto LAB_00100864;
    if (*(int *)(&DAT_00101b28 + (ulong)uVar3 * 0x60) == 0) goto LAB_00100788;
    if ((param_3 >> 0x20 & 1) == 0) {
      _raw_spin_unlock(puVar1);
      uVar2 = uVar9 * 0x60 | 0x10;
      if (0x3c0 < uVar2) {
LAB_00100864:
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x100868);
        (*pcVar4)();
      }
      if ((&DAT_00101b20)[uVar9 * 0xc] == -1) {
        local_68 = 0;
        uStack_60 = 0;
        local_78 = 0;
        uStack_70 = 0;
        local_80 = 0;
        init_wait_entry(&local_80,0);
        puVar8 = &DAT_00101b58 + (ulong)uVar3 * 0x60;
        while (lVar5 = prepare_to_wait_event(puVar8,&local_80,1), uVar2 < 0x3c1) {
          if ((&DAT_00101b20)[uVar9 * 0xc] != -1) goto LAB_001007e8;
          if (lVar5 != 0) goto LAB_00100854;
          schedule();
        }
        goto LAB_00100864;
      }
      goto LAB_001007f4;
    }
    if (0x3c0 < (uVar9 * 0x60 | 0x10)) goto LAB_00100864;
    plVar7 = &DAT_00101b20 + uVar9 * 0xc;
LAB_001007cc:
    uVar6 = 0xfffffff5;
    if (*plVar7 != -1) {
      uVar6 = 0;
    }
  }
  _raw_spin_unlock(puVar1);
  goto LAB_001007f8;
LAB_001007e8:
  finish_wait(puVar8,&local_80);
  goto LAB_001007f4;
LAB_00100854:
  if ((int)lVar5 != 0) {
    uVar6 = 0xfffffe00;
    goto LAB_001007f8;
  }
LAB_001007f4:
  uVar6 = 0;
LAB_001007f8:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// gh_dbl_set_mask @ 0010086c size=332
// signature: undefined gh_dbl_set_mask(void)
// callers: []
//------------------------------------------------------------

ulong gh_dbl_set_mask(uint *param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  undefined1 auVar9 [16];
  
  lVar8 = sp_el0;
  lVar8 = *(long *)(lVar8 + 0x638);
  auVar9 = gh_dbl_validate_params(param_1,1,param_4);
  uVar5 = auVar9._0_8_;
  uVar6 = auVar9._8_8_;
  uVar7 = uVar5 & 0xffffffff;
  if (auVar9._0_4_ == 0) {
    uVar1 = *param_1;
    if (10 < uVar1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1009b4);
      (*pcVar4)();
    }
    if (0x3a0 < (ulong)uVar1 * 0x60) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x1009b8);
      (*pcVar4)();
    }
    uVar5 = (&DAT_00101b30)[(ulong)uVar1 * 0xc];
    CallHyperVisor(0x6015);
    uVar6 = param_2;
    uVar7 = uVar5;
    uVar3 = 0xfffffff4;
    switch((int)uVar5) {
    case 0:
      goto switchD_0010093c_caseD_0;
    default:
      uVar3 = 0xffffffea;
      break;
    case 10:
      break;
    case 0x1e:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
      uVar3 = 0xfffffff3;
      break;
    case 0x1f:
    case 0x20:
      uVar3 = 0xfffffff0;
      break;
    case 0x28:
    case 0x29:
    case 0x3c:
    case 0x3d:
      uVar3 = 0xfffffffb;
      break;
    case -2:
    case -1:
      uVar3 = 0xffffffa1;
    }
    uVar7 = uVar3;
    auVar9 = _printk(&DAT_00101f79,"gh_dbl_set_mask",uVar5,0,0,0,0,0,0);
    uVar6 = auVar9._8_8_;
    uVar5 = auVar9._0_8_;
  }
switchD_0010093c_caseD_0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar8) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5,uVar6);
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// gh_dbl_send @ 001009bc size=348
// signature: undefined gh_dbl_send(void)
// callers: []
//------------------------------------------------------------

int gh_dbl_send(uint *param_1,undefined8 *param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = sp_el0;
  lVar5 = *(long *)(lVar5 + 0x638);
  if (param_2 == (undefined8 *)0x0) {
    iVar4 = -0x16;
  }
  else {
    iVar4 = gh_dbl_validate_params(param_1,0);
    if (iVar4 == 0) {
      uVar1 = *param_1;
      if (10 < uVar1) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100b14);
        (*pcVar3)();
      }
      if (0x3c0 < ((ulong)uVar1 * 0x60 | 0x10)) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x100b18);
        (*pcVar3)();
      }
      CallHyperVisor(0x6012);
      iVar4 = -0xc;
      switch((int)(&DAT_00101b20)[(ulong)uVar1 * 0xc]) {
      case 0:
        iVar4 = 0;
        *param_2 = *param_2;
        goto LAB_00100adc;
      default:
        iVar4 = -0x16;
        break;
      case 10:
        break;
      case 0x1e:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
        iVar4 = -0xd;
        break;
      case 0x1f:
      case 0x20:
        iVar4 = -0x10;
        break;
      case 0x28:
      case 0x29:
      case 0x3c:
      case 0x3d:
        iVar4 = -5;
        break;
      case -2:
      case -1:
        iVar4 = -0x5f;
      }
      _printk(&DAT_00101f79,"gh_dbl_send",(&DAT_00101b20)[(ulong)uVar1 * 0xc],0,0,0,0,0,0);
    }
  }
LAB_00100adc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar5) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gh_dbl_reset @ 00100b1c size=316
// signature: undefined gh_dbl_reset(void)
// callers: []
//------------------------------------------------------------

ulong gh_dbl_reset(uint *param_1,undefined8 param_2)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  ulong uVar5;
  ulong uVar6;
  long lVar7;
  undefined1 auVar8 [16];
  
  lVar7 = sp_el0;
  lVar7 = *(long *)(lVar7 + 0x638);
  auVar8 = gh_dbl_validate_params(param_1,1,param_2);
  uVar6 = auVar8._0_8_ & 0xffffffff;
  if (auVar8._0_4_ == 0) {
    uVar1 = *param_1;
    if (10 < uVar1) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x100c54);
      (*pcVar4)();
    }
    if (0x3a0 < (ulong)uVar1 * 0x60) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x100c58);
      (*pcVar4)();
    }
    uVar5 = (&DAT_00101b30)[(ulong)uVar1 * 0xc];
    auVar8._8_8_ = 0;
    auVar8._0_8_ = uVar5;
    CallHyperVisor(0x6014);
    uVar6 = uVar5;
    uVar3 = 0xfffffff4;
    switch((int)uVar5) {
    case 0:
      goto switchD_00100be0_caseD_0;
    default:
      uVar3 = 0xffffffea;
      break;
    case 10:
      break;
    case 0x1e:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
      uVar3 = 0xfffffff3;
      break;
    case 0x1f:
    case 0x20:
      uVar3 = 0xfffffff0;
      break;
    case 0x28:
    case 0x29:
    case 0x3c:
    case 0x3d:
      uVar3 = 0xfffffffb;
      break;
    case -2:
    case -1:
      uVar3 = 0xffffffa1;
    }
    uVar6 = uVar3;
    auVar8 = _printk(&DAT_00101f79,"gh_dbl_reset",uVar5,0,0,0,0,0,0);
  }
switchD_00100be0_caseD_0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar7) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar8._0_8_,auVar8._8_8_);
  }
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// gh_dbl_tx_register @ 00100c5c size=280
// signature: undefined gh_dbl_tx_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * gh_dbl_tx_register(uint param_1)

{
  long lVar1;
  code *pcVar2;
  uint *puVar3;
  ulong uVar4;
  
  if (9 < param_1) {
    return (uint *)0xffffffffffffffea;
  }
  if (gh_dbl_initialized != '\x01') {
    return (uint *)0xfffffffffffffdfb;
  }
  lVar1 = (ulong)param_1 * 0x60;
  uVar4 = (ulong)param_1 * 0x60;
  _raw_spin_lock(&DAT_00101b18 + (ulong)param_1 * 0x18);
  if ((uVar4 | 0x18) < 0x3c1) {
    if (*(int *)(&DAT_00101b28 + lVar1) != 0) {
      puVar3 = (uint *)0xfffffffffffffff0;
LAB_00100d40:
      _raw_spin_unlock(&DAT_00101b18 + (ulong)param_1 * 0x18);
      return puVar3;
    }
    if ((uVar4 < 0x3c1) && (param_1 != 10)) {
      puVar3 = *(uint **)(&gh_dbl_cap_table + lVar1);
      if (puVar3 == (uint *)0x0) {
        puVar3 = (uint *)kmalloc_trace(_free_irq,0xb20,4);
        if (puVar3 == (uint *)0x0) {
          puVar3 = (uint *)0xfffffffffffffff4;
          goto LAB_00100d40;
        }
        *puVar3 = param_1;
        if ((0x3c0 < uVar4) || (param_1 == 10)) goto LAB_00100d70;
        *(uint **)(&gh_dbl_cap_table + lVar1) = puVar3;
      }
      if ((uVar4 | 0x18) < 0x3c1) {
        *(int *)(&DAT_00101b28 + lVar1) = 1;
        goto LAB_00100d40;
      }
    }
  }
LAB_00100d70:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x100d74);
  (*pcVar2)();
}



//------------------------------------------------------------
// gh_dbl_rx_register @ 00100d78 size=340
// signature: undefined gh_dbl_rx_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * gh_dbl_rx_register(uint param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  code *pcVar2;
  ulong uVar3;
  uint *puVar4;
  ulong uVar5;
  ulong uVar6;
  
  if (9 < param_1) {
    return (uint *)0xffffffffffffffea;
  }
  if (gh_dbl_initialized != '\x01') {
    return (uint *)0xfffffffffffffdfb;
  }
  uVar5 = (ulong)param_1;
  lVar1 = uVar5 + (ulong)param_1 * 2;
  uVar6 = lVar1 * 0x20;
  _raw_spin_lock(&DAT_00101b18 + lVar1 * 8);
  if (uVar6 < 0x395) {
    if (*(int *)(&DAT_00101b3c + uVar6) != 0) {
      puVar4 = (uint *)0xfffffffffffffff0;
LAB_00100e94:
      _raw_spin_unlock(&DAT_00101b18 + lVar1 * 8);
      return puVar4;
    }
    if ((uVar6 < 0x3c1) && (param_1 != 10)) {
      puVar4 = *(uint **)(&gh_dbl_cap_table + uVar6);
      if (puVar4 == (uint *)0x0) {
        puVar4 = (uint *)kmalloc_trace(_free_irq,0xb20,4);
        if (puVar4 == (uint *)0x0) {
          puVar4 = (uint *)0xfffffffffffffff4;
          goto LAB_00100e94;
        }
        *puVar4 = param_1;
        if ((0x3c0 < uVar6) || (param_1 == 10)) goto LAB_00100ec8;
        *(uint **)(&gh_dbl_cap_table + uVar6) = puVar4;
      }
      uVar3 = uVar5 * 0x60;
      if (((uVar3 < 0x389) && (*(undefined8 *)(&DAT_00101b48 + uVar3) = param_2, uVar3 < 0x381)) &&
         (*(undefined8 *)(&DAT_00101b50 + uVar5 * 0x60) = param_3, uVar6 < 0x395)) {
        *(int *)(&DAT_00101b3c + uVar6) = 1;
        goto LAB_00100e94;
      }
    }
  }
LAB_00100ec8:
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(1,0x100ecc);
  (*pcVar2)();
}



//------------------------------------------------------------
// gh_dbl_tx_unregister @ 00100ed0 size=280
// signature: undefined gh_dbl_tx_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbl_tx_unregister(uint *param_1)

{
  uint uVar1;
  code *pcVar2;
  undefined8 uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar3 = 0xffffffea;
  if ((param_1 != (uint *)0x0) && (param_1 < (uint *)0xfffffffffffff001)) {
    uVar1 = *param_1;
    uVar4 = (ulong)uVar1;
    if (uVar1 < 10) {
      uVar5 = uVar4 * 0x60;
      _raw_spin_lock(&DAT_00101b18 + uVar4 * 0x18);
      if (0x3c0 < uVar5) goto LAB_00100fe4;
      if (*(uint **)(&gh_dbl_cap_table + uVar5) == param_1) {
        if (0x394 < uVar4 * 0x60) {
LAB_00100fe4:
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(1,0x100fe8);
          (*pcVar2)();
        }
        if (*(int *)(&DAT_00101b3c + uVar4 * 0x60) == 0) {
          if ((0x3c0 < uVar5) || (uVar1 == 10)) goto LAB_00100fe4;
          *(undefined8 *)(&gh_dbl_cap_table + uVar5) = 0;
          kfree(param_1);
        }
        if (0x3c0 < (uVar4 * 0x60 | 0x18)) goto LAB_00100fe4;
        uVar3 = 0;
        *(undefined4 *)(&DAT_00101b28 + (ulong)uVar1 * 0x60) = 0;
      }
      else {
        _printk(&DAT_00101f48,"gh_dbl_tx_unregister");
        uVar3 = 0xffffffea;
      }
      _raw_spin_unlock(&DAT_00101b18 + uVar4 * 0x18);
    }
    else {
      uVar3 = 0xffffffea;
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// gh_dbl_rx_unregister @ 00100fec size=276
// signature: undefined gh_dbl_rx_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbl_rx_unregister(uint *param_1)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  undefined8 uVar4;
  ulong uVar5;
  ulong uVar6;
  
  uVar4 = 0xffffffea;
  if ((param_1 != (uint *)0x0) && (param_1 < (uint *)0xfffffffffffff001)) {
    uVar1 = *param_1;
    uVar5 = (ulong)uVar1;
    if (uVar1 < 10) {
      uVar6 = uVar5 * 0x60;
      _raw_spin_lock(&DAT_00101b18 + uVar5 * 0x18);
      if (0x3c0 < uVar6) goto LAB_001010fc;
      if (*(uint **)(&gh_dbl_cap_table + uVar6) == param_1) {
        if (0x3c0 < (uVar5 * 0x60 | 0x18)) {
LAB_001010fc:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x101100);
          (*pcVar3)();
        }
        if (*(int *)(&DAT_00101b28 + uVar5 * 0x60) == 0) {
          if ((0x3c0 < uVar6) || (uVar1 == 10)) goto LAB_001010fc;
          *(undefined8 *)(&gh_dbl_cap_table + uVar6) = 0;
          kfree(param_1);
        }
        if (0x394 < uVar5 * 0x60) goto LAB_001010fc;
        uVar4 = 0;
        lVar2 = (ulong)uVar1 * 0x60;
        *(undefined4 *)(&DAT_00101b3c + lVar2) = 0;
        *(undefined8 *)(&DAT_00101b48 + lVar2) = 0;
        *(undefined8 *)(&DAT_00101b50 + lVar2) = 0;
      }
      else {
        _printk(&DAT_00101f48,"gh_dbl_rx_unregister");
        uVar4 = 0xffffffea;
      }
      _raw_spin_unlock(&DAT_00101b18 + uVar5 * 0x18);
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// gh_dbl_populate_cap_info @ 00101104 size=504
// signature: undefined gh_dbl_populate_cap_info(void)
// callers: []
//------------------------------------------------------------

int gh_dbl_populate_cap_info(uint param_1,undefined8 param_2,int param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  ulong uVar4;
  ulong uVar5;
  
  if (gh_dbl_initialized != '\x01') {
    return -0xb;
  }
  if (param_1 < 10) {
    uVar5 = (ulong)param_1;
    if (param_3 == 1) {
      if (0 < param_4) {
        uVar4 = uVar5 * 0x60;
        if ((uVar4 < 0x399) && (*(int *)(&DAT_00101b38 + uVar4) = param_4, uVar4 < 0x391)) {
          iVar2 = request_threaded_irq
                            (param_4,0,gh_dbl_rx_callback_thread,0x2001,(&DAT_00101b40)[uVar5 * 0xc]
                             ,&gh_dbl_cap_table + (ulong)param_1 * 0x60);
          if (iVar2 < 0) {
            _printk(&DAT_0010203a,"gh_dbl_populate_cap_info");
            return iVar2;
          }
          irq_set_irq_wake(param_4,1);
          _raw_spin_lock(&DAT_00101b18 + uVar5 * 0x18);
          if (uVar5 * 0x60 < 0x3a1) {
            (&DAT_00101b30)[uVar5 * 0xc] = param_2;
            _raw_spin_unlock(&DAT_00101b18 + uVar5 * 0x18);
            __wake_up(&DAT_00101b58 + uVar5 * 0x60,1,1,0);
            return iVar2;
          }
        }
LAB_001012f8:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x1012fc);
        (*pcVar1)();
      }
      puVar3 = &DAT_00102010;
    }
    else {
      if (param_3 != 0) {
        _printk(&DAT_00102059,"gh_dbl_populate_cap_info");
        goto LAB_001012b0;
      }
      if (param_4 < 1) {
        _raw_spin_lock(&DAT_00101b18 + uVar5 * 0x18);
        if ((uVar5 * 0x60 | 0x10) < 0x3c1) {
          (&DAT_00101b20)[uVar5 * 0xc] = param_2;
          _raw_spin_unlock(&DAT_00101b18 + uVar5 * 0x18);
          __wake_up(&DAT_00101b58 + uVar5 * 0x60,1,1,0);
          return 0;
        }
        goto LAB_001012f8;
      }
      puVar3 = &DAT_00101fcf;
    }
    _printk(puVar3,"gh_dbl_populate_cap_info");
    iVar2 = -6;
  }
  else {
    _printk(&DAT_00101f2c,"gh_dbl_populate_cap_info");
LAB_001012b0:
    iVar2 = -0x16;
  }
  return iVar2;
}



//------------------------------------------------------------
// gh_dbl_rx_callback_thread @ 00101300 size=68
// signature: undefined gh_dbl_rx_callback_thread(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbl_rx_callback_thread(undefined8 param_1,long param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_2 + 0x38);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x7baaae96) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101330);
      (*pcVar1)();
    }
    (*pcVar1)(param_1,*(undefined8 *)(param_2 + 0x40));
  }
  return 1;
}



//------------------------------------------------------------
// gh_dbl_reset_cap_info @ 00101348 size=416
// signature: undefined gh_dbl_reset_cap_info(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_dbl_reset_cap_info(uint param_1,int param_2,int *param_3)

{
  int iVar1;
  code *pcVar2;
  ulong uVar3;
  undefined8 uVar4;
  ulong uVar5;
  bool bVar6;
  
  if (gh_dbl_initialized != '\x01') {
    return 0xfffffff5;
  }
  if (9 < param_1) {
    _printk(&DAT_00101f2c,"gh_dbl_reset_cap_info");
    return 0xffffffea;
  }
  if (param_3 == (int *)0x0) {
    return 0xffffffea;
  }
  uVar5 = (ulong)param_1;
  _raw_spin_lock(&DAT_00101b18 + (ulong)param_1 * 0x18);
  if (param_2 == 1) {
    uVar3 = uVar5 * 0x60;
    if (0x398 < uVar3) {
LAB_001014e4:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x1014e8);
      (*pcVar2)();
    }
    iVar1 = *(int *)(&DAT_00101b38 + uVar3);
    if (iVar1 != 0) {
      *param_3 = iVar1;
      if ((uVar3 < 0x399) && (*(int *)(&DAT_00101b38 + uVar3) = 0, uVar5 * 0x60 < 0x3a1)) {
        bVar6 = false;
        uVar4 = 0;
        (&DAT_00101b30)[uVar5 * 0xc] = 0xffffffffffffffff;
        goto LAB_0010144c;
      }
      goto LAB_001014e4;
    }
    _printk(&DAT_00102083,"gh_dbl_reset_cap_info");
    uVar4 = 0xfffffffa;
  }
  else {
    if (param_2 == 0) {
      *param_3 = 0;
      if (0x3c0 < (uVar5 * 0x60 | 0x10)) goto LAB_001014e4;
      bVar6 = false;
      uVar4 = 0;
      (&DAT_00101b20)[uVar5 * 0xc] = 0xffffffffffffffff;
      goto LAB_0010144c;
    }
    _printk(&DAT_00102059,"gh_dbl_reset_cap_info",param_2);
    uVar4 = 0xffffffea;
  }
  bVar6 = true;
LAB_0010144c:
  _raw_spin_unlock(&DAT_00101b18 + (ulong)param_1 * 0x18);
  if ((!bVar6) && (*param_3 != 0)) {
    free_irq(*param_3,&gh_dbl_cap_table + (ulong)param_1 * 0x60);
  }
  return uVar4;
}



//------------------------------------------------------------
// gh_dbl_cleanup @ 001014e8 size=116
// signature: undefined gh_dbl_cleanup(void)
// callers: [init_module, cleanup_module]
//------------------------------------------------------------

void gh_dbl_cleanup(uint param_1)

{
  code *pcVar1;
  bool bVar2;
  long lVar3;
  
  if (-1 < (int)param_1) {
    lVar3 = (ulong)param_1 * 0x60;
    do {
      if (10 < param_1) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101558);
        (*pcVar1)();
      }
      if (lVar3 - 0x391U < 0xfffffffffffffc3f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x10155c);
        (*pcVar1)();
      }
      kfree(*(undefined8 *)((long)&DAT_00101b40 + lVar3));
      bVar2 = lVar3 != 0;
      lVar3 = lVar3 + -0x60;
    } while (bVar2);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101a20 size=204
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

undefined8 init_module(void)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = 0;
  iVar2 = 0;
  do {
    *(undefined4 *)((long)&DAT_00101b18 + lVar3) = 0;
    __init_waitqueue_head(&DAT_00101b58 + lVar3,"&entry->cap_wq",&gh_dbl_init___key);
    *(undefined8 *)((long)&DAT_00101b20 + lVar3) = 0xffffffffffffffff;
    *(undefined8 *)((long)&DAT_00101b30 + lVar3) = 0xffffffffffffffff;
    lVar1 = kasprintf(0xcc0,"gh_dbl_rx_%d",iVar2);
    *(long *)((long)&DAT_00101b40 + lVar3) = lVar1;
    if (lVar1 == 0) {
      gh_dbl_cleanup(iVar2);
      return 0xfffffff4;
    }
    iVar2 = iVar2 + 1;
    lVar3 = lVar3 + 0x60;
  } while (lVar3 != 0x3c0);
  gh_dbl_initialized = 1;
  return 0;
}



//------------------------------------------------------------
// cleanup_module @ 00101af0 size=32
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  gh_dbl_cleanup(9);
  return;
}



//------------------------------------------------------------
// _printk @ 00103000 size=1
// signature: undefined _printk(void)
// callers: [gh_dbl_reset_cap_info, gh_dbl_set_mask, gh_dbl_tx_unregister, gh_dbl_populate_cap_info, gh_dbl_validate_params, gh_dbl_rx_unregister, gh_dbl_reset, gh_dbl_send, gh_dbl_read_and_clean]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103008 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_dbl_set_mask, gh_dbl_validate_params, gh_dbl_reset, gh_dbl_send, gh_dbl_read_and_clean]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00103010 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gh_dbl_reset_cap_info, gh_dbl_tx_unregister, gh_dbl_populate_cap_info, gh_dbl_tx_register, gh_dbl_validate_params, gh_dbl_rx_unregister, gh_dbl_rx_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00103018 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gh_dbl_reset_cap_info, gh_dbl_tx_unregister, gh_dbl_populate_cap_info, gh_dbl_tx_register, gh_dbl_validate_params, gh_dbl_rx_unregister, gh_dbl_rx_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00103020 size=1
// signature: undefined init_wait_entry(void)
// callers: [gh_dbl_validate_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00103028 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [gh_dbl_validate_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00103030 size=1
// signature: undefined schedule(void)
// callers: [gh_dbl_validate_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00103038 size=1
// signature: undefined finish_wait(void)
// callers: [gh_dbl_validate_params]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00103048 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_dbl_tx_register, gh_dbl_rx_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103050 size=1
// signature: undefined kfree(void)
// callers: [gh_dbl_tx_unregister, gh_dbl_cleanup, gh_dbl_rx_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00103058 size=1
// signature: undefined __wake_up(void)
// callers: [gh_dbl_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00103060 size=1
// signature: undefined request_threaded_irq(void)
// callers: [gh_dbl_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 00103068 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [gh_dbl_populate_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00103070 size=1
// signature: undefined free_irq(void)
// callers: [gh_dbl_reset_cap_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00103078 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 00103080 size=1
// signature: undefined kasprintf(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



