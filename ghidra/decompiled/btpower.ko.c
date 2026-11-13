// Decompiled by Ghidra 12.2
// Program: btpower.ko
// Image base: 00100000

//------------------------------------------------------------
// perisec_cnss_bt_hw_disable_check @ 00100c54 size=572
// signature: undefined perisec_cnss_bt_hw_disable_check(void)
// callers: [bt_power_probe, platform_regulators_pwr, power_regulators, btpower_retenion]
//------------------------------------------------------------

void perisec_cnss_bt_hw_disable_check(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  char local_98 [4];
  undefined4 local_94;
  code *local_90;
  undefined8 uStack_88;
  undefined4 local_7c;
  undefined4 *local_78;
  undefined8 uStack_70;
  char *local_68;
  undefined8 uStack_60;
  undefined4 *local_58;
  undefined8 uStack_50;
  code *local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_90 = (code *)0x0;
  uStack_88 = 0;
  local_94 = 0x502;
  local_68 = (char *)0x0;
  uStack_60 = 0;
  local_78 = (undefined4 *)0x0;
  uStack_70 = 0;
  local_98[0] = '\0';
  iVar4 = 0;
  if (*(char *)(param_1 + 0xe4) == '\0') {
    iVar5 = get_client_env_object(&local_90);
    if (iVar5 == 0) {
      local_58 = &local_7c;
      local_48 = (code *)0x0;
      uStack_40 = 0;
      local_7c = 0x108;
      uStack_50 = 4;
      if (*(int *)(local_90 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x822b,0x100d18);
        (*pcVar3)();
      }
      iVar5 = (*local_90)(uStack_88,0,&local_58,0x1001);
      uVar2 = uStack_40;
      pcVar3 = local_48;
      if (iVar5 == 0) {
        local_78 = &local_94;
        local_68 = local_98;
        uStack_70 = 4;
        uStack_60 = 1;
        if (*(int *)(local_48 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8236,0x100d64);
          (*pcVar3)();
        }
        iVar5 = (*local_48)(uStack_40,1,&local_78,0x11);
        _printk(&DAT_00106f61,iVar5,local_98[0]);
        if (iVar5 == 0) {
          if (local_98[0] == '\x01') {
            iVar5 = 0;
            *(undefined4 *)(param_1 + 0xe8) = 1;
          }
          else {
            iVar5 = 0;
            *(undefined4 *)(param_1 + 0xe8) = 0;
          }
        }
        else if (iVar5 == 10) {
          *(undefined1 *)(param_1 + 0xe4) = 1;
          _printk(&DAT_00107c21);
          iVar5 = 0;
        }
        if (*(int *)(pcVar3 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8236,0x100e50);
          (*pcVar3)();
        }
        (*pcVar3)(uVar2,0xffff,0,0);
      }
      else {
        _printk(&DAT_001084ad,iVar5);
        if (iVar5 == 0xc) {
          *(undefined1 *)(param_1 + 0xe4) = 1;
          _printk(&DAT_00107aeb);
          iVar5 = 0;
        }
      }
      if (*(int *)(local_90 + -4) != 0x7d1769b4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100e7c);
        (*pcVar3)();
      }
      (*local_90)(uStack_88,0xffff,0,0);
      iVar4 = 0;
      if (iVar5 == 0) goto LAB_00100ca0;
    }
    else {
      _printk(&DAT_00107e16,iVar5);
    }
    _printk(&DAT_0010715d);
    iVar4 = iVar5;
  }
LAB_00100ca0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar4);
  }
  return;
}



//------------------------------------------------------------
// btpower_register_slimdev @ 00100e94 size=108
// signature: undefined btpower_register_slimdev(void)
// callers: []
//------------------------------------------------------------

undefined8 btpower_register_slimdev(long param_1)

{
  undefined8 uVar1;
  
  _printk(&DAT_00108aa7,"btpower_register_slimdev");
  if ((param_1 == 0) || (pwr_data == 0)) {
    _printk(&DAT_001084d2,"btpower_register_slimdev");
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = 0;
    *(long *)(pwr_data + 0x28) = param_1;
  }
  return uVar1;
}



//------------------------------------------------------------
// btpower_get_chipset_version @ 00100f04 size=52
// signature: undefined btpower_get_chipset_version(void)
// callers: []
//------------------------------------------------------------

undefined4 btpower_get_chipset_version(void)

{
  _printk(&DAT_00108aa7,"btpower_get_chipset_version");
  return soc_id;
}



//------------------------------------------------------------
// power_enable @ 00100f3c size=380
// signature: undefined power_enable(void)
// callers: [btpower_on]
//------------------------------------------------------------

undefined4 power_enable(int param_1)

{
  long lVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  mutex_lock(pwr_data + 0x108);
  uVar3 = *(undefined4 *)(pwr_data + 0x138);
  mutex_unlock(pwr_data + 0x108);
  switch(uVar3) {
  case 0:
    iVar2 = platform_regulators_pwr(1);
    if (iVar2 != 0) {
      _printk(&DAT_001072c3,"power_regulators",1);
    }
    if (param_1 == 1) {
      uVar3 = power_regulators(0,1);
      mutex_lock(pwr_data + 0x108);
      lVar1 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x138) = 1;
      mutex_unlock(lVar1);
      return uVar3;
    }
    uVar3 = power_regulators(1,1);
    mutex_lock(pwr_data + 0x108);
    uVar6 = 2;
    goto LAB_0010106c;
  case 1:
    if (param_1 != 1) {
      uVar4 = 1;
LAB_00100ff8:
      uVar3 = power_regulators(uVar4,1);
      mutex_lock(pwr_data + 0x108);
      uVar6 = 3;
LAB_0010106c:
      lVar1 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x138) = uVar6;
      mutex_unlock(lVar1);
      return uVar3;
    }
    puVar5 = &DAT_001088cd;
    break;
  case 2:
    if (param_1 != 2) {
      uVar4 = 0;
      goto LAB_00100ff8;
    }
    puVar5 = &DAT_001084f3;
    break;
  case 3:
    puVar5 = &DAT_001079d8;
    break;
  default:
    goto switchD_00100f90_default;
  }
  _printk(puVar5,"power_enable");
switchD_00100f90_default:
  return 0;
}



//------------------------------------------------------------
// power_regulators @ 001010bc size=1832
// signature: undefined power_regulators(void)
// callers: [btpower_retenion, power_disable, power_enable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int power_regulators(int param_1,uint param_2)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  char *pcVar10;
  char cVar11;
  long lVar12;
  long lVar13;
  ulong uVar14;
  long *plVar15;
  long lVar16;
  
  if (2 < param_2) {
    puVar8 = &DAT_00107fad;
LAB_001011ac:
    _printk(puVar8,"power_regulators");
    return -1;
  }
  if (param_1 == 2) {
    iVar6 = platform_regulators_pwr(param_2);
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = &DAT_001072c3;
    goto LAB_001011c8;
  }
  if (param_1 == 1) {
    iVar6 = perisec_cnss_bt_hw_disable_check(pwr_data);
    uVar2 = *(uint *)(pwr_data + 0x7c);
    uVar14 = (ulong)uVar2;
    if (uVar2 == 0) {
      if (param_2 < 3) {
        pcVar10 = (&PTR_s_vote_off_00106958)[(int)param_2];
      }
      else {
        pcVar10 = "INVALID STATE";
      }
      pcVar9 = "uwb_regulators_pwr";
LAB_001013c8:
      _printk(&DAT_00106c85,pcVar9,pcVar10);
      return 0;
    }
    if (param_2 == 0) {
      _printk(&DAT_001072fe,"uwb_regulators_pwr","vote off");
      iVar6 = bt_configure_gpios(0);
      if (iVar6 < 0) {
        puVar8 = &DAT_00106de1;
LAB_00101724:
        _printk(puVar8,"uwb_regulators_pwr");
      }
      if (0 < (int)uVar2) {
        lVar13 = 0;
        do {
          iVar6 = vreg_disable(*(long *)(pwr_data + 0x38) + lVar13);
          lVar13 = lVar13 + 0x28;
        } while (uVar14 * 0x28 != lVar13);
      }
    }
    else if (param_2 == 2) {
      _printk(&DAT_001072fe,"uwb_regulators_pwr","vote for retention");
      if (0 < (int)uVar2) {
        lVar13 = 0;
        do {
          iVar6 = vreg_enable_retention(*(long *)(pwr_data + 0x38) + lVar13);
          lVar13 = lVar13 + 0x28;
        } while (uVar14 * 0x28 != lVar13);
      }
    }
    else if (param_2 == 1) {
      _printk(&DAT_001072fe,"uwb_regulators_pwr","vote on");
      if (0 < (int)uVar2) {
        lVar13 = 0;
        do {
          lVar16 = *(long *)(pwr_data + 0x38);
          plVar15 = (long *)(lVar16 + lVar13);
          if (*plVar15 != 0) {
            iVar4 = (int)plVar15[4];
            if (((iVar4 == 0x22) || (lVar12 = (long)iVar4 * 4, lVar12 - 0x89U < 0xfffffffffffffe67))
               || (uVar1 = lVar12 + 0x110, 0x198 < uVar1)) goto LAB_00101390;
            (&DAT_0010bd54)[iVar4] = 0xffffffff;
            iVar6 = vreg_enable(plVar15);
            if (iVar6 < 0) {
              puVar8 = &DAT_001080ec;
              goto LAB_00101724;
            }
            if (*(char *)(lVar16 + lVar13 + 0x1c) != '\0') {
              uVar7 = regulator_get_voltage(*plVar15);
              if ((0x198 < uVar1) || (iVar4 == 0x22)) goto LAB_00101390;
              (&DAT_0010bd54)[iVar4] = uVar7;
            }
          }
          lVar13 = lVar13 + 0x28;
        } while (uVar14 * 0x28 != lVar13);
      }
      iVar6 = bt_configure_gpios(1);
      if (iVar6 < 0) {
        puVar8 = &DAT_00106de1;
        goto LAB_00101724;
      }
    }
    else {
      _printk(&DAT_001072fe,"uwb_regulators_pwr","INVALID STATE");
    }
    if (iVar6 == 0) {
      return 0;
    }
    puVar8 = &DAT_00106d86;
    goto LAB_001011c8;
  }
  if (param_1 != 0) {
    puVar8 = &DAT_001076e5;
    goto LAB_001011ac;
  }
  iVar6 = perisec_cnss_bt_hw_disable_check(pwr_data);
  uVar2 = *(uint *)(pwr_data + 0x78);
  uVar14 = (ulong)uVar2;
  if (uVar2 == 0) {
    if (param_2 < 3) {
      pcVar10 = (&PTR_s_vote_off_00106958)[(int)param_2];
    }
    else {
      pcVar10 = "INVALID STATE";
    }
    pcVar9 = "bt_regulators_pwr";
    goto LAB_001013c8;
  }
  if (param_2 == 2) {
    _printk(&DAT_001072fe,"bt_regulators_pwr","vote for retention");
    if (0 < (int)uVar2) {
      lVar13 = 0;
      do {
        iVar6 = vreg_enable_retention(*(long *)(pwr_data + 0x30) + lVar13);
        lVar13 = lVar13 + 0x28;
      } while (uVar14 * 0x28 != lVar13);
    }
LAB_00101620:
    if (iVar6 == 0) {
      return 0;
    }
  }
  else {
    if (param_2 == 1) {
      _printk(&DAT_001072fe,"bt_regulators_pwr","vote on");
      if (*(int *)(pwr_data + 0xe8) != 0) {
        _printk(&DAT_0010792f,"bt_regulators_pwr");
        iVar6 = -0x16;
        goto LAB_00101500;
      }
      if (0 < (int)uVar2) {
        lVar13 = 0;
        do {
          lVar16 = *(long *)(pwr_data + 0x30);
          plVar15 = (long *)(lVar16 + lVar13);
          if (*plVar15 != 0) {
            uVar3 = *(uint *)(plVar15 + 4);
            if (0x21 < uVar3) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1017e4);
              (*pcVar5)();
            }
            *(undefined4 *)(&DAT_0010bccc + (ulong)uVar3 * 4) = 0xffffffff;
            iVar6 = vreg_enable(plVar15);
            if (iVar6 < 0) {
              _printk(&DAT_0010771f,"bt_regulators_pwr");
              goto LAB_00101278;
            }
            if (*(char *)(lVar16 + lVar13 + 0x1c) != '\0') {
              uVar7 = regulator_get_voltage(*plVar15);
              if (0x43 < uVar3) {
LAB_00101390:
                    /* WARNING: Does not return */
                pcVar5 = (code *)SoftwareBreakpoint(1,0x101394);
                (*pcVar5)();
              }
              *(undefined4 *)(&DAT_0010bccc + (ulong)uVar3 * 4) = uVar7;
            }
          }
          lVar13 = lVar13 + 0x28;
        } while (uVar14 * 0x28 != lVar13);
      }
      plVar15 = *(long **)(pwr_data + 0x48);
      if (plVar15 == (long *)0x0) {
LAB_001015f0:
        if (0 < *(int *)(pwr_data + 8)) {
          _DAT_0010bccc = 0xffffffffffffffff;
          iVar6 = bt_configure_gpios(1);
          if (iVar6 < 0) {
            puVar8 = &DAT_00106de1;
            goto LAB_00101704;
          }
        }
        goto LAB_00101620;
      }
      _printk(&DAT_00108ad3,"bt_clk_enable",plVar15[1]);
      lVar13 = *plVar15;
      cVar11 = (char)plVar15[2];
      if (lVar13 == 0) {
LAB_00101778:
        _printk(&DAT_00107e6d,"bt_clk_enable",lVar13,cVar11);
        iVar6 = -0x16;
      }
      else {
        if (cVar11 != '\0') {
          cVar11 = '\x01';
          goto LAB_00101778;
        }
        iVar6 = clk_prepare(lVar13);
        if (iVar6 == 0) {
          iVar6 = clk_enable(lVar13);
          if (iVar6 == 0) {
            *(undefined1 *)(plVar15 + 2) = 1;
            goto LAB_001015f0;
          }
          clk_unprepare(lVar13);
        }
        _printk(&DAT_00107063,"bt_clk_enable",plVar15[1],iVar6);
        if (-1 < iVar6) goto LAB_001015f0;
      }
      _printk(&DAT_00106de1,"bt_regulators_pwr");
LAB_00101278:
      if (0 < (int)uVar2) {
        lVar13 = 0;
        do {
          iVar6 = vreg_disable(*(long *)(pwr_data + 0x30) + lVar13);
          lVar13 = lVar13 + 0x28;
        } while (uVar14 * 0x28 != lVar13);
      }
      goto LAB_00101620;
    }
    if (param_2 == 0) {
      _printk(&DAT_001072fe,"bt_regulators_pwr","vote off");
      if (0 < *(int *)(pwr_data + 8)) {
        if (*(int *)(pwr_data + 0xe8) == 0) {
          bt_configure_gpios(0);
        }
        else {
          puVar8 = &DAT_00107571;
LAB_00101704:
          _printk(puVar8,"bt_regulators_pwr");
        }
      }
      if (0 < *(int *)(pwr_data + 8)) {
        gpio_free();
      }
      if (0 < *(int *)(pwr_data + 0x14)) {
        gpio_free();
      }
      plVar15 = *(long **)(pwr_data + 0x48);
      if (plVar15 != (long *)0x0) {
        _printk(&DAT_00108ad3,"bt_clk_disable",plVar15[1]);
        lVar13 = *plVar15;
        if ((lVar13 == 0) || ((char)plVar15[2] == '\0')) {
          _printk(&DAT_00107e6d,"bt_clk_disable",lVar13);
        }
        else {
          clk_disable(lVar13);
          clk_unprepare(lVar13);
          *(undefined1 *)(plVar15 + 2) = 0;
        }
      }
      if (0 < *(int *)(pwr_data + 0x1c)) {
        gpio_free();
      }
      goto LAB_00101278;
    }
    _printk(&DAT_001072fe,"bt_regulators_pwr","INVALID STATE");
    _printk(&DAT_00108c41,"bt_regulators_pwr",param_2);
    iVar6 = -1;
  }
LAB_00101500:
  puVar8 = &DAT_00107a0b;
LAB_001011c8:
  _printk(puVar8,"power_regulators",param_2);
  return iVar6;
}



//------------------------------------------------------------
// send_signal_to_subsystem @ 001017e8 size=68
// signature: undefined send_signal_to_subsystem(void)
// callers: []
//------------------------------------------------------------

void send_signal_to_subsystem(int param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  long lVar2;
  long lVar3;
  
  puVar1 = (undefined8 *)(pwr_data + 0x150);
  lVar2 = pwr_data + 0x198;
  lVar3 = pwr_data + 0x168;
  *(undefined4 *)(pwr_data + 0x14c) = param_2;
  if (param_1 != 1) {
    lVar3 = lVar2;
  }
  queue_work_on(0x20,*puVar1,lVar3);
  return;
}



//------------------------------------------------------------
// power_disable @ 00101830 size=1144
// signature: undefined power_disable(void)
// callers: [bt_power_vote, btpower_off]
//------------------------------------------------------------

int power_disable(int param_1)

{
  undefined8 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  undefined *puVar7;
  undefined4 uVar8;
  
  mutex_lock(pwr_data + 0x108);
  iVar2 = *(int *)(pwr_data + 0x13c);
  mutex_unlock(pwr_data + 0x108);
  mutex_lock(pwr_data + 0x108);
  iVar3 = *(int *)(pwr_data + 0x140);
  mutex_unlock(pwr_data + 0x108);
  mutex_lock(pwr_data + 0x108);
  iVar4 = *(int *)(pwr_data + 0x144);
  mutex_unlock(pwr_data + 0x108);
  mutex_lock(pwr_data + 0x108);
  uVar8 = *(undefined4 *)(pwr_data + 0x138);
  mutex_unlock(pwr_data + 0x108);
  switch(uVar8) {
  case 0:
    puVar7 = &DAT_001087b1;
LAB_00101c78:
    _printk(puVar7,"power_disable");
    return 0;
  case 1:
    if (param_1 == 2) {
      puVar7 = &DAT_001088f3;
      goto LAB_00101c78;
    }
    power_regulators(0,0);
    iVar5 = platform_regulators_pwr(0);
    if (iVar5 != 0) {
      _printk(&DAT_001072c3,"power_regulators",0);
    }
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x138) = 0;
    mutex_unlock(lVar6);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x148) = 0;
    mutex_lock(lVar6);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x13c) = 0;
    mutex_unlock(lVar6);
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x140) = 0;
    mutex_unlock(lVar6);
    break;
  case 2:
    if (param_1 == 1) {
      puVar7 = &DAT_001074ba;
      goto LAB_00101c78;
    }
    power_regulators(1,0);
    iVar5 = platform_regulators_pwr(0);
    if (iVar5 != 0) {
      _printk(&DAT_001072c3,"power_regulators",0);
    }
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x138) = 0;
    mutex_unlock(lVar6);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x148) = 0;
    mutex_lock(lVar6);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x13c) = 0;
    mutex_unlock(lVar6);
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x140) = 0;
    mutex_unlock(lVar6);
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x144) = 1;
    goto LAB_00101bd4;
  case 3:
    if (param_1 != 1) {
      uVar8 = 1;
      iVar5 = power_regulators(1,0);
      mutex_lock(pwr_data + 0x108);
      lVar6 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x138) = 1;
      mutex_unlock(lVar6);
      if (iVar2 == 5) {
LAB_00101ab4:
        mutex_lock(pwr_data + 0x108);
        lVar6 = pwr_data + 0x108;
        *(undefined4 *)(pwr_data + 0x13c) = uVar8;
        mutex_unlock(lVar6);
      }
      else if (iVar2 == 3) {
        uVar8 = 0;
        goto LAB_00101ab4;
      }
      if (*(int *)(pwr_data + 0x148) == 3) {
        puVar1 = (undefined8 *)(pwr_data + 0x150);
        lVar6 = pwr_data + 0x168;
        *(undefined4 *)(pwr_data + 0x14c) = 0x20002;
        queue_work_on(0x20,*puVar1,lVar6);
      }
      if (iVar3 != 3) {
LAB_00101c0c:
        if (iVar4 != 5) {
          return iVar5;
        }
        break;
      }
      if (iVar4 != 4) {
        mutex_lock(pwr_data + 0x108);
        lVar6 = pwr_data + 0x108;
        *(undefined4 *)(pwr_data + 0x140) = 0;
        mutex_unlock(lVar6);
        goto LAB_00101c0c;
      }
      puVar1 = (undefined8 *)(pwr_data + 0x150);
      lVar6 = pwr_data + 0x168;
      *(undefined4 *)(pwr_data + 0x14c) = 0x40001;
      queue_work_on(0x20,*puVar1,lVar6);
      mutex_lock(pwr_data + 0x108);
      uVar8 = 2;
LAB_00101bcc:
      lVar6 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x140) = uVar8;
      goto LAB_00101bd4;
    }
    iVar5 = power_regulators(0,0);
    mutex_lock(pwr_data + 0x108);
    lVar6 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x138) = 2;
    mutex_unlock(lVar6);
    if (iVar2 == 5) {
      uVar8 = 3;
LAB_00101b44:
      mutex_lock(pwr_data + 0x108);
      lVar6 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x13c) = uVar8;
      mutex_unlock(lVar6);
    }
    else if (iVar2 == 1) {
      uVar8 = 0;
      goto LAB_00101b44;
    }
    if (*(int *)(pwr_data + 0x148) == 1) {
      puVar1 = (undefined8 *)(pwr_data + 0x150);
      lVar6 = pwr_data + 0x198;
      *(undefined8 *)(pwr_data + 0x148) = 0x200000000;
      queue_work_on(0x20,*puVar1,lVar6);
    }
    if (iVar3 == 2) {
      if (iVar4 == 5) {
        puVar1 = (undefined8 *)(pwr_data + 0x150);
        lVar6 = pwr_data + 0x198;
        *(undefined4 *)(pwr_data + 0x14c) = 0x40001;
        queue_work_on(0x20,*puVar1,lVar6);
        mutex_lock(pwr_data + 0x108);
        uVar8 = 3;
        goto LAB_00101bcc;
      }
      mutex_lock(pwr_data + 0x108);
      lVar6 = pwr_data + 0x108;
      *(undefined4 *)(pwr_data + 0x140) = 0;
      mutex_unlock(lVar6);
    }
    if (iVar4 != 4) {
      return iVar5;
    }
    break;
  default:
    return 0;
  }
  mutex_lock(pwr_data + 0x108);
  lVar6 = pwr_data + 0x108;
  *(undefined4 *)(pwr_data + 0x144) = 1;
LAB_00101bd4:
  mutex_unlock(lVar6);
  return iVar5;
}



//------------------------------------------------------------
// btpower_set_grant_state @ 00101ca8 size=68
// signature: undefined btpower_set_grant_state(void)
// callers: [btpower_access_ctrl]
//------------------------------------------------------------

void btpower_set_grant_state(undefined4 param_1)

{
  long lVar1;
  
  mutex_lock(pwr_data + 0x108);
  lVar1 = pwr_data + 0x108;
  *(undefined4 *)(pwr_data + 0x140) = param_1;
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// btpower_set_grant_pending_state @ 00101cec size=68
// signature: undefined btpower_set_grant_pending_state(void)
// callers: [btpower_access_ctrl]
//------------------------------------------------------------

void btpower_set_grant_pending_state(undefined4 param_1)

{
  long lVar1;
  
  mutex_lock(pwr_data + 0x108);
  lVar1 = pwr_data + 0x108;
  *(undefined4 *)(pwr_data + 0x144) = param_1;
  mutex_unlock(lVar1);
  return;
}



//------------------------------------------------------------
// btpower_register_client @ 00101d34 size=128
// signature: undefined btpower_register_client(void)
// callers: []
//------------------------------------------------------------

void btpower_register_client(undefined8 param_1,int param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (param_2 == 6) {
    lVar2 = sp_el0;
    puVar1 = &DAT_00107f22;
    *(long *)(pwr_data + 0x100) = lVar2;
  }
  else {
    if (param_2 != 5) {
      if ((int)param_1 != 1) {
        param_1 = 2;
      }
      client_state_notified(param_1);
      return;
    }
    lVar2 = sp_el0;
    puVar1 = &DAT_001074e0;
    *(long *)(pwr_data + 0xf8) = lVar2;
  }
  _printk(puVar1,"btpower_register_client",*(undefined4 *)(lVar2 + 0x634));
  return;
}



//------------------------------------------------------------
// client_state_notified @ 00101db4 size=248
// signature: undefined client_state_notified(void)
// callers: [bt_ioctl, btpower_register_client]
//------------------------------------------------------------

void client_state_notified(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined4 uVar5;
  
  if (*(int *)(pwr_data + 0x148) == 0) {
    lVar4 = pwr_data + 0x108;
    if (param_1 == 1) {
      *(undefined4 *)(pwr_data + 0x148) = 1;
      mutex_lock(lVar4);
      iVar1 = *(int *)(pwr_data + 0x138);
      mutex_unlock(pwr_data + 0x108);
      if (iVar1 != 3) {
        return;
      }
      if (*(long *)(pwr_data + 0x100) != 0) {
        uVar3 = *(undefined8 *)(pwr_data + 0x150);
        uVar5 = 1;
        lVar4 = pwr_data + 0x198;
LAB_00101e60:
        *(undefined4 *)(pwr_data + 0x14c) = uVar5;
        queue_work_on(0x20,uVar3,lVar4);
        return;
      }
      puVar2 = &DAT_0010895a;
    }
    else {
      *(undefined4 *)(pwr_data + 0x148) = 3;
      mutex_lock(lVar4);
      iVar1 = *(int *)(pwr_data + 0x138);
      mutex_unlock(pwr_data + 0x108);
      if (iVar1 != 3) {
        return;
      }
      if (*(long *)(pwr_data + 0xf8) != 0) {
        uVar3 = *(undefined8 *)(pwr_data + 0x150);
        uVar5 = 0x20001;
        lVar4 = pwr_data + 0x168;
        goto LAB_00101e60;
      }
      puVar2 = &DAT_00108a46;
    }
  }
  else {
    puVar2 = &DAT_001070cc;
  }
  _printk(puVar2,"client_state_notified");
  return;
}



//------------------------------------------------------------
// log_power_src_val @ 00101eb0 size=276
// signature: undefined log_power_src_val(void)
// callers: []
//------------------------------------------------------------

void log_power_src_val(void)

{
  long lVar1;
  long lVar2;
  
  gpio_to_desc(*(undefined4 *)(pwr_data + 0x10));
  DAT_0010bc84 = gpiod_get_raw_value();
  gpio_to_desc(*(undefined4 *)(pwr_data + 8));
  DAT_0010bc80 = gpiod_get_raw_value();
  if (0 < *(int *)(pwr_data + 0x78)) {
    lVar1 = 0;
    lVar2 = 0;
    do {
      set_pwr_srcs_status(*(long *)(pwr_data + 0x30) + lVar1,0);
      lVar2 = lVar2 + 1;
      lVar1 = lVar1 + 0x28;
    } while (lVar2 < *(int *)(pwr_data + 0x78));
  }
  if (0 < *(int *)(pwr_data + 0x80)) {
    lVar1 = 0;
    lVar2 = 0;
    do {
      set_pwr_srcs_status(*(long *)(pwr_data + 0x40) + lVar1,2);
      lVar2 = lVar2 + 1;
      lVar1 = lVar1 + 0x28;
    } while (lVar2 < *(int *)(pwr_data + 0x80));
  }
  if (0 < *(int *)(pwr_data + 0x7c)) {
    lVar1 = 0;
    lVar2 = 0;
    do {
      set_pwr_srcs_status(*(long *)(pwr_data + 0x38) + lVar1,1);
      lVar2 = lVar2 + 1;
      lVar1 = lVar1 + 0x28;
    } while (lVar2 < *(int *)(pwr_data + 0x7c));
  }
  return;
}



//------------------------------------------------------------
// set_pwr_srcs_status @ 00101fc4 size=432
// signature: undefined set_pwr_srcs_status(void)
// callers: [log_power_src_val, bt_ioctl]
//------------------------------------------------------------

void set_pwr_srcs_status(char *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  
  if (param_1 == (char *)0x0) {
    _printk(&DAT_00106e5e,"set_pwr_srcs_status");
    return;
  }
  if (param_1[0x1c] == '\0') {
    iVar2 = -1;
    if (param_2 != 2) goto LAB_0010200c;
LAB_00102068:
    if (0x21 < *(uint *)(param_1 + 0x24)) goto LAB_0010216c;
    (&power_src)[*(uint *)(param_1 + 0x24)] = iVar2;
    if (iVar2 == -1) goto LAB_00102088;
    if (0x21 < *(uint *)(param_1 + 0x24)) goto LAB_0010216c;
    uVar6 = (&power_src)[*(uint *)(param_1 + 0x24)];
    pcVar4 = *(char **)(param_1 + 8);
  }
  else {
    iVar2 = regulator_get_voltage(*(undefined8 *)param_1);
    if (param_2 == 2) goto LAB_00102068;
LAB_0010200c:
    if (param_2 == 1) {
      uVar6 = *(uint *)(param_1 + 0x24);
      if (((-(ulong)(uVar6 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar6 << 2) - 0x89 <
           0xfffffffffffffe67) || (uVar6 == 0x22)) {
LAB_00102170:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x102174);
        (*pcVar1)();
      }
      (&DAT_0010bd54)[(int)uVar6] = iVar2;
      pcVar4 = *(char **)(param_1 + 8);
      pcVar5 = pcVar4;
      if (iVar2 == -1) {
LAB_001020cc:
        uVar6 = (uint)(byte)param_1[0x1c];
        puVar3 = &DAT_00107ec1;
        pcVar4 = "set_pwr_srcs_status";
        goto LAB_00102158;
      }
      uVar6 = *(uint *)(param_1 + 0x24);
      if (((-(ulong)(uVar6 >> 0x1f) & 0xfffffffc00000000 | (ulong)uVar6 << 2) - 0x89 <
           0xfffffffffffffe67) || (uVar6 == 0x22)) goto LAB_00102170;
      uVar6 = (&DAT_0010bd54)[(int)uVar6];
    }
    else {
      if (param_2 != 0) {
        _printk(&DAT_00108110,"set_pwr_srcs_status",param_2);
        return;
      }
      if (0x21 < *(uint *)(param_1 + 0x24)) {
LAB_0010216c:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102170);
        (*pcVar1)();
      }
      *(int *)(&DAT_0010bccc + (ulong)*(uint *)(param_1 + 0x24) * 4) = iVar2;
      if (iVar2 == -1) {
LAB_00102088:
        pcVar5 = *(char **)(param_1 + 8);
        goto LAB_001020cc;
      }
      if (0x21 < *(uint *)(param_1 + 0x24)) goto LAB_0010216c;
      pcVar4 = *(char **)(param_1 + 8);
      uVar6 = *(uint *)(&DAT_0010bccc + (ulong)*(uint *)(param_1 + 0x24) * 4);
    }
  }
  puVar3 = &DAT_00108246;
  pcVar5 = param_1;
LAB_00102158:
  _printk(puVar3,pcVar4,pcVar5,uVar6);
  return;
}



//------------------------------------------------------------
// btpower_retenion @ 00102178 size=760
// signature: undefined btpower_retenion(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

int btpower_retenion(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  long lVar5;
  
  mutex_lock(pwr_data + 0x108);
  uVar1 = *(uint *)(pwr_data + 0x138);
  mutex_unlock(pwr_data + 0x108);
  mutex_lock(pwr_data + 0x108);
  uVar2 = *(uint *)(pwr_data + 0x13c);
  mutex_unlock(pwr_data + 0x108);
  if (uVar1 == 0) {
    _printk(&DAT_00107859,"btpower_retenion");
    return -1;
  }
  iVar3 = power_regulators(param_1 != 4,2);
  if (iVar3 < 0) {
    return iVar3;
  }
  if ((uVar1 < 3) && (uVar2 == 0)) {
    iVar3 = perisec_cnss_bt_hw_disable_check(pwr_data);
    uVar1 = *(uint *)(pwr_data + 0x80);
    if (uVar1 == 0) {
      _printk(&DAT_001071bf,"platform_regulators_pwr","vote for retention");
      iVar3 = 0;
    }
    else {
      _printk(&DAT_001072fe,"platform_regulators_pwr","vote for retention");
      if (0 < (int)uVar1) {
        lVar5 = 0;
        do {
          iVar3 = vreg_enable_retention(*(long *)(pwr_data + 0x40) + lVar5);
          lVar5 = lVar5 + 0x28;
        } while ((ulong)uVar1 * 0x28 != lVar5);
      }
      if ((iVar3 != 0) && (_printk(&DAT_001072c3,"power_regulators",2), iVar3 < 0)) {
        return iVar3;
      }
    }
  }
  else if ((uVar1 != 3) || (uVar2 != 0)) {
    if ((uVar1 == 3) && ((uVar2 & 0xfffffffd) == 1)) {
      iVar3 = perisec_cnss_bt_hw_disable_check(pwr_data);
      uVar1 = *(uint *)(pwr_data + 0x80);
      if (uVar1 == 0) goto LAB_001023b4;
      _printk(&DAT_001072fe,"platform_regulators_pwr","vote for retention");
      if (0 < (int)uVar1) {
        lVar5 = 0;
        do {
          iVar3 = vreg_enable_retention(*(long *)(pwr_data + 0x40) + lVar5);
          lVar5 = lVar5 + 0x28;
        } while ((ulong)uVar1 * 0x28 != lVar5);
      }
LAB_0010242c:
      if ((iVar3 != 0) && (_printk(&DAT_001072c3,"power_regulators",2), iVar3 < 0)) {
        return iVar3;
      }
    }
    else {
      if ((uVar2 != 4) && (uVar2 != 2)) {
        return iVar3;
      }
      iVar3 = perisec_cnss_bt_hw_disable_check(pwr_data);
      uVar1 = *(uint *)(pwr_data + 0x80);
      if (uVar1 != 0) {
        _printk(&DAT_001072fe,"platform_regulators_pwr","vote for retention");
        if (0 < (int)uVar1) {
          lVar5 = 0;
          do {
            iVar3 = vreg_enable_retention(*(long *)(pwr_data + 0x40) + lVar5);
            lVar5 = lVar5 + 0x28;
          } while ((ulong)uVar1 * 0x28 != lVar5);
        }
        goto LAB_0010242c;
      }
LAB_001023b4:
      _printk(&DAT_001071bf,"platform_regulators_pwr","vote for retention");
      iVar3 = 0;
    }
    mutex_lock(pwr_data + 0x108);
    lVar5 = pwr_data;
    *(undefined4 *)(pwr_data + 0x13c) = 5;
    goto LAB_00102228;
  }
  uVar4 = 3;
  if (param_1 == 4) {
    uVar4 = 1;
  }
  mutex_lock(pwr_data + 0x108);
  lVar5 = pwr_data;
  *(undefined4 *)(pwr_data + 0x13c) = uVar4;
LAB_00102228:
  mutex_unlock(lVar5 + 0x108);
  return iVar3;
}



//------------------------------------------------------------
// btpower_off @ 00102474 size=40
// signature: undefined btpower_off(void)
// callers: []
//------------------------------------------------------------

void btpower_off(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 1) {
    uVar1 = 2;
  }
  power_disable(uVar1);
  return;
}



//------------------------------------------------------------
// btpower_on @ 001024a0 size=340
// signature: undefined btpower_on(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

int btpower_on(int param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  
  iVar4 = *(int *)(pwr_data + 0x148);
  mutex_lock(pwr_data + 0x108);
  uVar2 = *(uint *)(pwr_data + 0x13c);
  mutex_unlock(pwr_data + 0x108);
  if ((uVar2 | 2) == 3) {
    iVar3 = platform_regulators_pwr(3);
    if (iVar3 < 0) {
      return iVar3;
    }
    mutex_lock(pwr_data + 0x108);
    uVar6 = 2;
    if (uVar2 != 1) {
      uVar6 = 4;
    }
    lVar1 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x13c) = uVar6;
    mutex_unlock(lVar1);
  }
  if (iVar4 == 0) {
    uVar6 = 1;
    if (param_1 != 0) {
      uVar6 = 2;
    }
    iVar4 = power_enable(uVar6);
    if (iVar4 == 0) {
      mutex_lock(pwr_data + 0x108);
      iVar4 = *(int *)(pwr_data + 0x138);
      mutex_unlock(pwr_data + 0x108);
    }
  }
  else {
    pcVar5 = "and SSR on BT";
    switch(iVar4) {
    case 1:
      break;
    case 2:
      pcVar5 = "and BT SSR completed";
      break;
    case 3:
      pcVar5 = "and SSR on UWB";
      break;
    case 4:
      pcVar5 = "and UWB SSR completed";
      break;
    default:
      pcVar5 = "SSR STATE = INVALID STATE";
    }
    _printk(&DAT_001073a5,"btpower_on",pcVar5);
    iVar4 = -1;
  }
  return iVar4;
}



//------------------------------------------------------------
// platform_regulators_pwr @ 001025f4 size=912
// signature: undefined platform_regulators_pwr(void)
// callers: [power_regulators, btpower_on, power_disable, power_enable]
//------------------------------------------------------------

int platform_regulators_pwr(uint param_1)

{
  long *plVar1;
  undefined8 *puVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  undefined4 uVar7;
  undefined *puVar8;
  char *pcVar9;
  ulong uVar10;
  long lVar11;
  long lVar12;
  
  iVar6 = perisec_cnss_bt_hw_disable_check(pwr_data);
  uVar3 = *(uint *)(pwr_data + 0x80);
  uVar10 = (ulong)uVar3;
  if (uVar3 == 0) {
    if (param_1 < 4) {
      pcVar9 = (&PTR_s_vote_off_00106970)[(int)param_1];
    }
    else {
      pcVar9 = "INVALID STATE";
    }
    _printk(&DAT_001071bf,"platform_regulators_pwr",pcVar9);
    return 0;
  }
  switch(param_1) {
  case 0:
    _printk(&DAT_001072fe,"platform_regulators_pwr","vote off");
    iVar6 = bt_configure_gpios(0);
    if (iVar6 < 0) goto LAB_00102944;
    break;
  case 1:
    _printk(&DAT_001072fe,"platform_regulators_pwr","vote on");
    if (0 < (int)uVar3) {
      lVar11 = 0;
      do {
        lVar12 = *(long *)(pwr_data + 0x40);
        plVar1 = (long *)(lVar12 + lVar11);
        if (*plVar1 != 0) {
          uVar4 = *(uint *)(plVar1 + 4);
          if (0x21 < uVar4) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x102984);
            (*pcVar5)();
          }
          (&power_src)[uVar4] = 0xffffffff;
          iVar6 = vreg_enable(plVar1);
          if (iVar6 < 0) {
            _printk(&DAT_00106e7f,"platform_regulators_pwr");
            if ((int)uVar3 < 1) {
              return iVar6;
            }
            goto LAB_001026cc;
          }
          if (*(char *)(lVar12 + lVar11 + 0x1c) != '\0') {
            uVar7 = regulator_get_voltage(*plVar1);
            if (0x65 < uVar4) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x1027dc);
              (*pcVar5)();
            }
            (&power_src)[uVar4] = uVar7;
          }
        }
        lVar11 = lVar11 + 0x28;
      } while (uVar10 * 0x28 != lVar11);
    }
    iVar6 = bt_configure_gpios(1);
    if (-1 < iVar6) {
      return iVar6;
    }
LAB_00102944:
    _printk(&DAT_00106de1,"platform_regulators_pwr");
    break;
  case 2:
    _printk(&DAT_001072fe,"platform_regulators_pwr","vote for retention");
    if ((int)uVar3 < 1) {
      return iVar6;
    }
    lVar11 = 0;
    do {
      iVar6 = vreg_enable_retention(*(long *)(pwr_data + 0x40) + lVar11);
      lVar11 = lVar11 + 0x28;
    } while (uVar10 * 0x28 != lVar11);
    goto LAB_00102920;
  case 3:
    _printk(&DAT_001072fe,"platform_regulators_pwr","vote offretention");
    if ((int)uVar3 < 1) {
      return iVar6;
    }
    lVar11 = 0;
    do {
      lVar12 = *(long *)(pwr_data + 0x40);
      if ((((undefined8 *)(lVar12 + lVar11) == (undefined8 *)0x0) ||
          (*(char *)(lVar12 + lVar11 + 0x1c) == '\0')) ||
         (*(char *)(lVar12 + lVar11 + 0x1d) == '\0')) {
        iVar6 = 0;
      }
      else {
        puVar2 = (undefined8 *)(lVar12 + lVar11);
        if (((*(int *)(puVar2 + 2) == 0) || (*(int *)((long)puVar2 + 0x14) == 0)) ||
           (iVar6 = regulator_set_voltage(*(undefined8 *)(lVar12 + lVar11)), -1 < iVar6)) {
          iVar6 = regulator_set_load(*puVar2,*(undefined4 *)(puVar2 + 3));
          if (-1 < iVar6) goto LAB_00102880;
          puVar8 = &DAT_00107e42;
        }
        else {
          puVar8 = &DAT_00107750;
        }
        _printk(puVar8,"vreg_configure",*(undefined8 *)(lVar12 + lVar11 + 8),iVar6);
      }
LAB_00102880:
      lVar11 = lVar11 + 0x28;
      if (uVar10 * 0x28 == lVar11) {
        return iVar6;
      }
    } while( true );
  default:
    _printk(&DAT_001072fe,"platform_regulators_pwr","INVALID STATE");
    return iVar6;
  }
  if (0 < *(int *)(pwr_data + 8)) {
    gpio_free();
  }
  if (0 < *(int *)(pwr_data + 0x14)) {
    gpio_free();
  }
  if (0 < (int)uVar3) {
LAB_001026cc:
    lVar11 = 0;
    do {
      iVar6 = vreg_disable(*(long *)(pwr_data + 0x40) + lVar11);
      lVar11 = lVar11 + 0x28;
    } while (uVar10 * 0x28 != lVar11);
  }
LAB_00102920:
  return iVar6;
}



//------------------------------------------------------------
// STREAM_TO_UINT32 @ 00102988 size=12
// signature: undefined STREAM_TO_UINT32(void)
// callers: []
//------------------------------------------------------------

undefined4 STREAM_TO_UINT32(long param_1)

{
  return **(undefined4 **)(param_1 + 0xe0);
}



//------------------------------------------------------------
// btpower_access_ctrl @ 00102998 size=728
// signature: undefined btpower_access_ctrl(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

undefined8 btpower_access_ctrl(uint param_1)

{
  undefined8 *puVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  undefined8 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  
  mutex_lock(pwr_data + 0x108);
  iVar3 = *(int *)(pwr_data + 0x140);
  mutex_unlock(pwr_data + 0x108);
  mutex_lock(pwr_data + 0x108);
  iVar8 = *(int *)(pwr_data + 0x144);
  mutex_unlock(pwr_data + 0x108);
  if (((param_1 & 0xfffffffe) == 6) && (uVar4 = *(uint *)(pwr_data + 0x148), uVar4 != 0)) {
    if (uVar4 < 5) {
      pcVar6 = (&PTR_s_and_SSR_on_BT_00106990)[(int)(uVar4 - 1)];
    }
    else {
      pcVar6 = "SSR STATE = INVALID STATE";
    }
    _printk(&DAT_00106c56,"btpower_access_ctrl",pcVar6);
    return 0xffffffff;
  }
  if ((iVar3 == 0) && (iVar8 != 1)) {
    _printk(&DAT_00108c05,"btpower_access_ctrl");
    mutex_lock(pwr_data + 0x108);
    iVar8 = 1;
    lVar2 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x144) = 1;
    mutex_unlock(lVar2);
  }
  if ((param_1 == 6) && (iVar3 == 0)) {
    mutex_lock(pwr_data + 0x108);
    uVar7 = 2;
LAB_00102aac:
    lVar2 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x140) = uVar7;
    mutex_unlock(lVar2);
    return 0;
  }
  if ((param_1 == 7) && (iVar3 == 0)) {
    mutex_lock(pwr_data + 0x108);
    uVar7 = 3;
    goto LAB_00102aac;
  }
  if ((param_1 == 6) && (iVar3 == 3)) {
    mutex_lock(pwr_data + 0x108);
    uVar7 = 4;
LAB_00102b0c:
    lVar2 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x144) = uVar7;
    mutex_unlock(lVar2);
    return 1;
  }
  if ((param_1 == 7) && (iVar3 == 2)) {
    mutex_lock(pwr_data + 0x108);
    uVar7 = 5;
    goto LAB_00102b0c;
  }
  if ((param_1 != 8) || (iVar3 != 2)) {
    if ((param_1 != 9) || (iVar3 != 3)) {
      _printk(&DAT_00107299,"btpower_access_ctrl");
      return 0xffffffff;
    }
    if (iVar8 == 4) {
      if (*(long *)(pwr_data + 0x100) == 0) {
        _printk(&DAT_0010727c,"btpower_access_ctrl");
        goto LAB_00102bf0;
      }
      puVar1 = (undefined8 *)(pwr_data + 0x150);
      lVar2 = pwr_data + 0x168;
      *(undefined4 *)(pwr_data + 0x14c) = 0x40001;
      queue_work_on(0x20,*puVar1,lVar2);
      uVar5 = 2;
    }
    else {
      uVar5 = 0;
    }
    btpower_set_grant_state(uVar5);
LAB_00102bf0:
    mutex_lock(pwr_data + 0x108);
    lVar2 = pwr_data + 0x108;
    *(undefined4 *)(pwr_data + 0x144) = 1;
    mutex_unlock(lVar2);
    return 2;
  }
  if (iVar8 == 5) {
    if (*(long *)(pwr_data + 0x100) == 0) {
      _printk(&DAT_00107cf6,"btpower_access_ctrl");
      goto LAB_00102bdc;
    }
    puVar1 = (undefined8 *)(pwr_data + 0x150);
    lVar2 = pwr_data + 0x198;
    *(undefined4 *)(pwr_data + 0x14c) = 0x40001;
    queue_work_on(0x20,*puVar1,lVar2);
    uVar5 = 3;
  }
  else {
    uVar5 = 0;
  }
  btpower_set_grant_state(uVar5);
LAB_00102bdc:
  btpower_set_grant_pending_state(1);
  return 2;
}



//------------------------------------------------------------
// schedule_client_voting @ 00102c74 size=532
// signature: undefined schedule_client_voting(void)
// callers: [bt_ioctl, btpower_process_access_req, btpower_handle_client_request]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void schedule_client_voting(uint param_1)

{
  int *piVar1;
  long lVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  uint *puVar7;
  long lVar8;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar2 = sp_el0;
  local_58 = *(long *)(lVar2 + 0x638);
  mutex_lock(pwr_data + 0x328);
  lVar6 = __alloc_skb(4,0xcc0,0,0xffffffff);
  lVar2 = pwr_data;
  if (lVar6 == 0) {
    mutex_unlock(pwr_data + 0x328);
    iVar5 = -1;
  }
  else {
    uVar3 = param_1 & 0xff;
    if (10 < uVar3) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102e88);
      (*pcVar4)();
    }
    lVar8 = pwr_data + (ulong)uVar3 * 4;
    piVar1 = (int *)(lVar8 + 0x2b8);
    *(undefined4 *)(lVar8 + 0x2b8) = 0xfffffffe;
    puVar7 = (uint *)skb_put(lVar6,4);
    *puVar7 = param_1;
    skb_queue_tail(pwr_data + 0x310,lVar6);
    queue_work_on(0x20,_system_highpri_wq,pwr_data + 0x2e0);
    mutex_unlock(pwr_data + 0x328);
    if (*(int *)(lVar8 + 0x2b8) == -2) {
      local_68 = 0;
      uStack_60 = 0;
      local_78 = 0;
      uStack_70 = 0;
      local_80 = 0;
      lVar2 = lVar2 + (ulong)uVar3 * 0x18 + 0x1c8;
      init_wait_entry(&local_80,0);
      lVar6 = prepare_to_wait_event(lVar2,&local_80,1);
      if (*piVar1 == -2) {
        lVar8 = 0x96;
        do {
          if (lVar6 != 0) goto LAB_00102e3c;
          lVar8 = schedule_timeout(lVar8);
          lVar6 = prepare_to_wait_event(lVar2,&local_80,1);
          if (lVar8 == 0 && *piVar1 != -2) {
            lVar8 = 1;
          }
        } while ((*piVar1 == -2) && (lVar8 != 0));
      }
      else {
        lVar8 = 0x96;
      }
      lVar6 = lVar8;
      finish_wait(lVar2,&local_80);
LAB_00102e3c:
      _printk(&DAT_00107d14,"schedule_client_voting",*piVar1);
      if ((int)lVar6 == 0) {
        _printk(&DAT_00107d1e,"schedule_client_voting",param_1);
        iVar5 = -0x6e;
        goto LAB_00102cdc;
      }
    }
    else {
      _printk(&DAT_00107d14,"schedule_client_voting");
    }
    iVar5 = *piVar1;
  }
LAB_00102cdc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar5);
  }
  return;
}



//------------------------------------------------------------
// GetUwbSecondaryCrashReason @ 00102e8c size=56
// signature: undefined GetUwbSecondaryCrashReason(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

char * GetUwbSecondaryCrashReason(int param_1)

{
  char *pcVar1;
  long lVar2;
  
  lVar2 = 0x74;
  pcVar1 = s_Default_00108e2c;
  do {
    if (*(int *)(pcVar1 + -4) == param_1) {
      return pcVar1;
    }
    pcVar1 = pcVar1 + 0x38;
    lVar2 = lVar2 + -1;
  } while (lVar2 != 0);
  return "Crash reason not found";
}



//------------------------------------------------------------
// GetUwbPrimaryCrashReason @ 00102ec8 size=608
// signature: undefined GetUwbPrimaryCrashReason(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

char * GetUwbPrimaryCrashReason(int param_1)

{
  long lVar1;
  
  if (uwbPriReasonMap == param_1) {
    lVar1 = 0;
  }
  else if (DAT_0010a7f0 == param_1) {
    lVar1 = 1;
  }
  else if (DAT_0010a858 == param_1) {
    lVar1 = 2;
  }
  else if (DAT_0010a8c0 == param_1) {
    lVar1 = 3;
  }
  else if (DAT_0010a928 == param_1) {
    lVar1 = 4;
  }
  else if (DAT_0010a990 == param_1) {
    lVar1 = 5;
  }
  else if (DAT_0010a9f8 == param_1) {
    lVar1 = 6;
  }
  else if (DAT_0010aa60 == param_1) {
    lVar1 = 7;
  }
  else if (DAT_0010aac8 == param_1) {
    lVar1 = 8;
  }
  else if (DAT_0010ab30 == param_1) {
    lVar1 = 9;
  }
  else if (DAT_0010ab98 == param_1) {
    lVar1 = 10;
  }
  else if (DAT_0010ac00 == param_1) {
    lVar1 = 0xb;
  }
  else if (DAT_0010ac68 == param_1) {
    lVar1 = 0xc;
  }
  else if (DAT_0010acd0 == param_1) {
    lVar1 = 0xd;
  }
  else if (DAT_0010ad38 == param_1) {
    lVar1 = 0xe;
  }
  else if (DAT_0010ada0 == param_1) {
    lVar1 = 0xf;
  }
  else if (DAT_0010ae08 == param_1) {
    lVar1 = 0x10;
  }
  else if (DAT_0010ae70 == param_1) {
    lVar1 = 0x11;
  }
  else if (DAT_0010aed8 == param_1) {
    lVar1 = 0x12;
  }
  else if (DAT_0010af40 == param_1) {
    lVar1 = 0x13;
  }
  else if (DAT_0010afa8 == param_1) {
    lVar1 = 0x14;
  }
  else if (DAT_0010b010 == param_1) {
    lVar1 = 0x15;
  }
  else if (DAT_0010b078 == param_1) {
    lVar1 = 0x16;
  }
  else {
    if (DAT_0010b0e0 != param_1) {
      return "Crash reason not found";
    }
    lVar1 = 0x17;
  }
  return s_Invalid_reason_0010a78c + lVar1 * 0x68;
}



//------------------------------------------------------------
// GetSourceSubsystemString @ 0010312c size=36
// signature: undefined GetSourceSubsystemString(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

char * GetSourceSubsystemString(uint param_1)

{
  if (param_1 < 3) {
    return (&PTR_s_Peri_SS_001069b0)[(int)param_1];
  }
  return "Unknown Subsystem";
}



//------------------------------------------------------------
// btpower_handle_client_request @ 00103154 size=204
// signature: undefined btpower_handle_client_request(void)
// callers: []
//------------------------------------------------------------

undefined8 btpower_handle_client_request(int param_1,uint param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  undefined *puVar4;
  
  pcVar1 = "BT_CMD_PWR_CTRL";
  if (param_1 != 0xbfad) {
    pcVar1 = "UWB_CMD_PWR_CTRL";
  }
  if (param_2 < 3) {
    pcVar3 = (&PTR_s_Power_OFF_00106a90)[(int)param_2];
  }
  else {
    pcVar3 = "INVALID STATE";
  }
  _printk(&DAT_00107b0e,"btpower_handle_client_request",pcVar1,pcVar3);
  if (param_1 == 0xbfad) {
    if (2 < param_2) {
      return 0xffffffff;
    }
    puVar4 = &DAT_00106aa8;
  }
  else {
    if (param_1 != 0xbfe1) {
      return 0xffffffff;
    }
    if (2 < param_2) {
      return 0xffffffff;
    }
    puVar4 = &DAT_00106ab4;
  }
  uVar2 = schedule_client_voting(*(undefined4 *)(puVar4 + (long)(int)param_2 * 4));
  return uVar2;
}



//------------------------------------------------------------
// btpower_process_access_req @ 00103224 size=256
// signature: undefined btpower_process_access_req(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

undefined8 btpower_process_access_req(int param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  undefined8 uVar3;
  
  pcVar1 = "BT_CMD_ACCESS_CTRL";
  if (param_1 != 0xbfe4) {
    pcVar1 = "UWB_CMD_ACCESS_CTRL";
  }
  pcVar2 = "Request";
  if (param_2 != 1) {
    pcVar2 = "Release";
  }
  _printk(&DAT_0010851a,"btpower_process_access_req",pcVar1,pcVar2);
  if ((param_1 == 0xbfe4) && (param_2 == 1)) {
    uVar3 = 6;
  }
  else if ((param_1 == 0xbfe4) && (param_2 == 2)) {
    uVar3 = 8;
  }
  else if ((param_1 == 0xbfe5) && (param_2 == 1)) {
    uVar3 = 7;
  }
  else {
    if ((param_1 != 0xbfe5) || (param_2 != 2)) {
      _printk(&DAT_00108aad,"btpower_process_access_req",param_1,param_2);
      return 0xffffffff;
    }
    uVar3 = 9;
  }
  uVar3 = schedule_client_voting(uVar3);
  return uVar3;
}



//------------------------------------------------------------
// bt_kernel_panic @ 00103328 size=572
// signature: undefined bt_kernel_panic(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void bt_kernel_panic(ulong param_1)

{
  ulong uVar1;
  code *pcVar2;
  size_t sVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined *__s;
  
  _printk(&DAT_00108aa7,"bt_kernel_panic");
  puVar4 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_1, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_1 & (long)(param_1 << 8) >> 8;
  }
  if (uVar5 < 0x7fffffff6b) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    sVar3 = __arch_copy_from_user(puVar4,&CrashInfo,param_1 & 0xff7fffffffffffff,0x96);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    if (sVar3 == 0) goto LAB_0010342c;
  }
  else {
    sVar3 = 0x96;
  }
  memset(&probe_finished + -sVar3,0,sVar3);
  _printk(&DAT_0010702e,"bt_kernel_panic");
  __s = default_crash_reason;
  CrashInfo = 0;
  DAT_0010bde4 = 0;
  DAT_0010bdec = 0;
  DAT_0010bdf4 = 0;
  DAT_0010bdfc = 0;
  DAT_0010be04 = 0;
  DAT_0010be0c = 0;
  DAT_0010be14 = 0;
  DAT_0010be1c = 0;
  DAT_0010be24 = 0;
  DAT_0010be2c = 0;
  DAT_0010be34 = 0;
  DAT_0010be3c = 0;
  DAT_0010be44 = 0;
  DAT_0010be4c = 0;
  DAT_0010be54 = 0;
  DAT_0010be5c = 0;
  DAT_0010be64._0_6_ = 0;
  DAT_0010be64._6_2_ = 0;
  uRam000000000010be6c = 0;
  sVar3 = strlen(default_crash_reason);
  if (sVar3 == 0) {
LAB_001034ec:
    sVar3 = strlen(__s);
    if (sVar3 == 0) goto LAB_0010342c;
    if (100 < sVar3) goto LAB_00103534;
    memcpy((void *)((long)&DAT_0010be0c + 2),__s,sVar3 - 1);
    __s = (undefined *)(sVar3 - 1);
    if (sVar3 - 0x66 < 0xffffffffffffff69) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(1,0x103534);
      (*pcVar2)();
    }
  }
  else {
    if (sVar3 < 0x33) {
      memcpy(&CrashInfo,__s,sVar3 - 1);
      *(undefined1 *)(sVar3 + 0x10bddb) = 0;
      goto LAB_001034ec;
    }
LAB_00103534:
    fortify_panic("strlcpy");
  }
  __s[0x10be0e] = 0;
LAB_0010342c:
  _printk(&DAT_0010752f,"bt_kernel_panic",&CrashInfo,0x10be0e);
                    /* WARNING: Subroutine does not return */
  panic("%s: BT kernel panic Primary reason = %s, Secondary reason = %s\n","bt_kernel_panic",
        &CrashInfo,0x10be0e);
}



//------------------------------------------------------------
// bt_aop_send_msg @ 00103580 size=168
// signature: undefined bt_aop_send_msg(void)
// callers: []
//------------------------------------------------------------

int bt_aop_send_msg(long param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0x40;
  uStack_30 = param_2;
  _printk(&DAT_00108ad3,"bt_aop_send_msg",param_2);
  iVar2 = mbox_send_message(*(undefined8 *)(param_1 + 0xc0),&local_38);
  if (iVar2 < 0) {
    _printk(&DAT_001082f1,param_2);
  }
  else {
    iVar2 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// bt_aop_pdc_reconfig @ 0010362c size=264
// signature: undefined bt_aop_pdc_reconfig(void)
// callers: [btpower_aop_mbox_init]
//------------------------------------------------------------

void bt_aop_pdc_reconfig(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (((*(int *)(param_1 + 0xd4) < 1) || (*(long *)(param_1 + 0xd8) == 0)) ||
     (_printk(&DAT_0010805a), *(int *)(param_1 + 0xd4) == 0)) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    do {
      uVar3 = *(undefined8 *)(*(long *)(param_1 + 0xd8) + uVar4 * 8);
      local_58 = 0x40;
      uStack_50 = uVar3;
      _printk(&DAT_00108ad3,"bt_aop_send_msg",uVar3);
      iVar2 = mbox_send_message(*(undefined8 *)(param_1 + 0xc0),&local_58);
      if (iVar2 < 0) {
        _printk(&DAT_001082f1,uVar3);
        break;
      }
      iVar2 = 0;
      uVar4 = uVar4 + 1;
    } while (uVar4 < *(uint *)(param_1 + 0xd4));
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar2);
  }
  return;
}



//------------------------------------------------------------
// btpower_aop_mbox_init @ 00103738 size=220
// signature: undefined btpower_aop_mbox_init(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

ulong btpower_aop_mbox_init(long *param_1)

{
  undefined *puVar1;
  int iVar2;
  ulong uVar3;
  
  param_1[0x11] = *param_1 + 0x10;
  *(undefined1 *)(param_1 + 0x12) = 1;
  param_1[0x13] = 1000;
  *(undefined1 *)(param_1 + 0x14) = 0;
  param_1[0x18] = 0;
  uVar3 = mbox_request_channel(param_1 + 0x11,0);
  if (uVar3 < 0xfffffffffffff001) {
    param_1[0x18] = uVar3;
    iVar2 = of_property_read_string
                      (*(undefined8 *)(*param_1 + 0x2f8),"qcom,vreg_ipa",param_1 + 0x19);
    puVar1 = &DAT_00107f8d;
    if (iVar2 != 0) {
      puVar1 = &DAT_001076c2;
    }
    _printk(puVar1,"btpower_aop_mbox_init");
    iVar2 = bt_aop_pdc_reconfig(param_1);
    if (iVar2 != 0) {
      _printk(&DAT_001087e5,iVar2);
    }
    uVar3 = 0;
  }
  else {
    _printk(&DAT_00107f6b,"btpower_aop_mbox_init");
  }
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// vreg_enable @ 00103814 size=212
// signature: undefined vreg_enable(void)
// callers: [platform_regulators_pwr, power_regulators]
//------------------------------------------------------------

int vreg_enable(undefined8 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  if (*(char *)((long)param_1 + 0x1c) == '\0') {
    if (((*(int *)(param_1 + 2) == 0) || (*(int *)((long)param_1 + 0x14) == 0)) ||
       (iVar1 = regulator_set_voltage(*param_1), -1 < iVar1)) {
      iVar1 = regulator_set_load(*param_1,*(undefined4 *)(param_1 + 3));
      if (-1 < iVar1) {
        iVar1 = regulator_enable(*param_1);
        if (iVar1 < 0) {
          _printk(&DAT_00106e04,"vreg_enable",param_1[1],iVar1);
          return iVar1;
        }
        *(undefined1 *)((long)param_1 + 0x1c) = 1;
        return iVar1;
      }
      uVar3 = param_1[1];
      puVar2 = &DAT_00107e42;
    }
    else {
      uVar3 = param_1[1];
      puVar2 = &DAT_00107750;
    }
    _printk(puVar2,"vreg_configure",uVar3,iVar1);
  }
  return 0;
}



//------------------------------------------------------------
// bt_configure_gpios @ 001038e8 size=1384
// signature: undefined bt_configure_gpios(void)
// callers: [platform_regulators_pwr, power_regulators]
//------------------------------------------------------------

int bt_configure_gpios(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined8 uVar9;
  undefined *puVar10;
  
  iVar1 = *(int *)(pwr_data + 8);
  iVar2 = *(int *)(pwr_data + 0x10);
  if (param_1 == 0) {
    uVar9 = gpio_to_desc(iVar1);
    gpiod_set_raw_value(uVar9,0);
    msleep(100);
    gpio_to_desc(iVar1);
    uVar5 = gpiod_get_raw_value();
    _printk(&DAT_0010732d,iVar1,uVar5);
    iVar7 = 0;
    if (-1 < iVar2) {
      gpio_to_desc(iVar2);
      uVar5 = gpiod_get_raw_value();
      _printk(&DAT_00107e99,iVar2,uVar5);
      iVar7 = 0;
    }
LAB_00103984:
    puVar10 = &DAT_001071a5;
    iVar6 = param_1;
  }
  else {
    iVar8 = *(int *)(pwr_data + 0xc);
    iVar3 = *(int *)(pwr_data + 0x14);
    iVar4 = *(int *)(pwr_data + 0x1c);
    iVar6 = gpio_request(iVar1,"bt_sys_rst_n");
    if (iVar6 == 0) {
      if ((iVar4 < 0) || (iVar6 = gpio_request(iVar4,"bt_resetb_gpio_n"), iVar6 == 0)) {
        _printk(&DAT_001077a4);
        gpio_to_desc(iVar1);
        uVar5 = gpiod_get_raw_value();
        _printk(&DAT_00108072,iVar1,uVar5);
        uVar9 = gpio_to_desc(iVar1);
        iVar6 = gpiod_direction_output_raw(uVar9,0);
        if (iVar6 != 0) goto LAB_00103c80;
        gpio_to_desc(iVar1);
        power_src = gpiod_get_raw_value();
        msleep(0x32);
        _printk(&DAT_00106e2e);
        gpio_to_desc(iVar1);
        uVar5 = gpiod_get_raw_value();
        _printk(&DAT_00108072,iVar1,uVar5);
        if (iVar2 < 0) {
          iVar7 = 0;
          if (-1 < iVar8) goto LAB_00103b48;
LAB_00103b78:
          btpower_set_xo_clk_gpio_state(1);
          _printk(&DAT_00108091);
          uVar9 = gpio_to_desc(iVar1);
          iVar6 = gpiod_direction_output_raw(uVar9,1);
          if (iVar6 != 0) goto LAB_00103c80;
          gpio_to_desc(iVar1);
          power_src = gpiod_get_raw_value();
          btpower_set_xo_clk_gpio_state(0);
          iVar7 = 0;
          if (-1 < iVar8) goto LAB_00103bc0;
        }
        else {
          gpio_to_desc(iVar2);
          DAT_0010bc48 = gpiod_get_raw_value();
          if (*(int *)(pwr_data + 0x20) < 1) {
            iVar7 = 0;
          }
          else {
            iVar7 = msm_gpio_mpm_wake_set(*(int *)(pwr_data + 0x20),1);
            if (iVar7 < 0) {
              _printk(&DAT_00107c7b,iVar7);
              return iVar7;
            }
            _printk(&DAT_001075a5);
          }
          _printk(&DAT_00108326,iVar2,DAT_0010bc48);
          if (iVar8 < 0) goto LAB_00103b78;
LAB_00103b48:
          gpio_to_desc(iVar8);
          uVar5 = gpiod_get_raw_value();
          _printk(&DAT_00108358,iVar8,uVar5);
          gpio_to_desc(iVar8);
          iVar6 = gpiod_get_raw_value();
          if (iVar6 != 0) goto LAB_00103b78;
LAB_00103bc0:
          gpio_to_desc(iVar8);
          iVar8 = gpiod_get_raw_value();
          if (iVar8 == 0) {
            gpio_to_desc(iVar1);
            iVar8 = gpiod_get_raw_value();
            if (iVar8 == 0) {
LAB_00103c38:
              _printk(&DAT_001081fc);
              _printk(&DAT_00107308);
              msleep(100);
              _printk(&DAT_00106ce6);
              btpower_set_xo_clk_gpio_state(1);
              if (-1 < iVar4) {
                bt_resetb_operation(iVar4);
              }
            }
            else {
              _printk(&DAT_001081d2);
              _printk(&DAT_00108add);
              uVar9 = gpio_to_desc(iVar1);
              iVar6 = gpiod_direction_output_raw(uVar9,0);
              if (iVar6 != 0) goto LAB_00103c80;
              gpio_to_desc(iVar1);
              power_src = gpiod_get_raw_value();
              if (-1 < iVar4) {
                _printk(&DAT_00107969);
                bt_pull_resetb(iVar4,1);
                goto LAB_00103c38;
              }
              _printk(&DAT_001081fc);
              _printk(&DAT_00107308);
              msleep(100);
              _printk(&DAT_00106ce6);
              btpower_set_xo_clk_gpio_state(1);
            }
            uVar9 = gpio_to_desc(iVar1);
            iVar6 = gpiod_direction_output_raw(uVar9,1);
            if (iVar6 != 0) goto LAB_00103c80;
            gpio_to_desc(iVar1);
            power_src = gpiod_get_raw_value();
            btpower_set_xo_clk_gpio_state(0);
            iVar7 = 0;
          }
        }
        gpio_to_desc(iVar1);
        iVar8 = gpiod_get_raw_value();
        if (iVar8 == 0) {
          btpower_set_xo_clk_gpio_state(1);
          _printk(&DAT_00108387);
          _printk(&DAT_00106f81);
          uVar9 = gpio_to_desc(iVar1);
          iVar6 = gpiod_direction_output_raw(uVar9,1);
          if (iVar6 != 0) {
LAB_00103c80:
            _printk(&DAT_001085a5,"bt_configure_gpios");
            return iVar6;
          }
          gpio_to_desc(iVar1);
          power_src = gpiod_get_raw_value();
          btpower_set_xo_clk_gpio_state(0);
          iVar7 = 0;
        }
        msleep(0x32);
        if (-1 < iVar2) {
          gpio_to_desc(iVar2);
          iVar7 = gpiod_direction_input();
          if (iVar7 == 0) {
            gpio_to_desc(iVar2);
            iVar8 = gpiod_get_raw_value();
            if ((iVar8 == 0) && (-1 < iVar3)) {
              iVar7 = gpio_request(iVar3,"bt_debug_n");
              if (iVar7 == 0) {
                uVar9 = gpio_to_desc(iVar3);
                iVar7 = gpiod_direction_output_raw(uVar9,1);
                if (iVar7 != 0) {
                  _printk(&DAT_00108b03,"bt_configure_gpios");
                }
              }
              else {
                _printk(&DAT_00108226);
              }
            }
          }
          else {
            _printk(&DAT_001077cf,"bt_configure_gpios",iVar7);
          }
        }
        gpio_to_desc(iVar1);
        uVar5 = gpiod_get_raw_value();
        _printk(&DAT_00107086,iVar1,uVar5);
        if (-1 < iVar2) {
          gpio_to_desc(iVar2);
          DAT_0010bc48 = gpiod_get_raw_value();
          _printk(&DAT_001080ba,iVar2,DAT_0010bc48);
        }
        goto LAB_00103984;
      }
      iVar1 = iVar4;
    }
    puVar10 = &DAT_0010777e;
    iVar7 = iVar6;
  }
  _printk(puVar10,"bt_configure_gpios",iVar1,iVar6);
  return iVar7;
}



//------------------------------------------------------------
// vreg_disable @ 00103e50 size=196
// signature: undefined vreg_disable(void)
// callers: [platform_regulators_pwr, power_regulators]
//------------------------------------------------------------

int vreg_disable(undefined8 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  if ((param_1 == (undefined8 *)0x0) || (*(char *)((long)param_1 + 0x1c) == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = regulator_disable(*param_1);
    if (iVar1 < 0) {
      uVar3 = param_1[1];
      puVar2 = &DAT_00108a1b;
    }
    else {
      *(undefined1 *)((long)param_1 + 0x1c) = 0;
      if (((*(int *)(param_1 + 2) == 0) || (*(int *)((long)param_1 + 0x14) == 0)) ||
         (iVar1 = regulator_set_voltage(*param_1,0), -1 < iVar1)) {
        iVar1 = regulator_set_load(*param_1,0);
        if (-1 < iVar1) {
          return iVar1;
        }
        uVar3 = param_1[1];
        puVar2 = &DAT_00107e42;
      }
      else {
        uVar3 = param_1[1];
        puVar2 = &DAT_00107750;
      }
    }
    _printk(puVar2,"vreg_disable",uVar3,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// vreg_enable_retention @ 00103f14 size=168
// signature: undefined vreg_enable_retention(void)
// callers: [platform_regulators_pwr, power_regulators, btpower_retenion]
//------------------------------------------------------------

int vreg_enable_retention(undefined8 *param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  if ((((param_1 == (undefined8 *)0x0) || (*(char *)((long)param_1 + 0x1c) == '\0')) ||
      (*(char *)((long)param_1 + 0x1d) == '\0')) ||
     ((*(int *)(param_1 + 2) == 0 || (*(int *)((long)param_1 + 0x14) == 0)))) {
    iVar1 = 0;
  }
  else {
    iVar1 = regulator_set_voltage(*param_1,0);
    if (iVar1 < 0) {
      uVar3 = param_1[1];
      puVar2 = &DAT_00107750;
    }
    else {
      iVar1 = regulator_set_load(*param_1,0);
      if (-1 < iVar1) {
        return iVar1;
      }
      uVar3 = param_1[1];
      puVar2 = &DAT_00107e42;
    }
    _printk(puVar2,"vreg_configure",uVar3,iVar1);
  }
  return iVar1;
}



//------------------------------------------------------------
// btpower_set_xo_clk_gpio_state @ 00103fbc size=440
// signature: undefined btpower_set_xo_clk_gpio_state(void)
// callers: [bt_configure_gpios]
//------------------------------------------------------------

void btpower_set_xo_clk_gpio_state(ulong param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined8 uVar4;
  
  iVar1 = *(int *)(pwr_data + 0x24);
  if (iVar1 < 0) {
    return;
  }
  iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
  if (iVar3 == 0) goto LAB_00104108;
  usleep_range_state(10000,20000,2);
  iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
  bVar2 = iVar3 != 0;
  if (iVar3 == 0) {
LAB_001040e4:
    iVar3 = 0;
  }
  else {
    usleep_range_state(10000,20000,2);
    iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
    bVar2 = iVar3 != 0;
    if (iVar3 == 0) goto LAB_001040e4;
    usleep_range_state(10000,20000,2);
    iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
    bVar2 = iVar3 != 0;
    if (iVar3 == 0) goto LAB_001040e4;
    usleep_range_state(10000,20000,2);
    iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
    bVar2 = iVar3 != 0;
    if (iVar3 == 0) goto LAB_001040e4;
    usleep_range_state(10000,20000,2);
    iVar3 = gpio_request(iVar1,"bt_xo_clk_gpio");
    bVar2 = iVar3 != 0;
  }
  if (bVar2) {
    _printk(&DAT_0010892d,"btpower_set_xo_clk_gpio_state",iVar1,iVar3);
    return;
  }
LAB_00104108:
  if ((param_1 & 1) == 0) {
    usleep_range_state(4000,6000,2);
    uVar4 = gpio_to_desc(iVar1);
    gpiod_direction_output_raw(uVar4,0);
  }
  else {
    uVar4 = gpio_to_desc(iVar1);
    gpiod_direction_output_raw(uVar4,1);
    usleep_range_state(100,200,2);
  }
  _printk(&DAT_001070b5,"btpower_set_xo_clk_gpio_state",iVar1);
  gpio_free(iVar1);
  return;
}



//------------------------------------------------------------
// bt_pull_resetb @ 00104174 size=76
// signature: undefined bt_pull_resetb(void)
// callers: [bt_configure_gpios]
//------------------------------------------------------------

void bt_pull_resetb(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = gpio_to_desc();
  iVar1 = gpiod_direction_output_raw(uVar2,param_2);
  if (iVar1 != 0) {
    _printk(&DAT_001085a5,"bt_pull_resetb");
  }
  return;
}



//------------------------------------------------------------
// bt_resetb_operation @ 001041c0 size=128
// signature: undefined bt_resetb_operation(void)
// callers: [bt_configure_gpios]
//------------------------------------------------------------

void bt_resetb_operation(undefined4 param_1)

{
  int iVar1;
  undefined8 uVar2;
  
  _printk(&DAT_00107d5c);
  uVar2 = gpio_to_desc(param_1);
  iVar1 = gpiod_direction_output_raw(uVar2,0);
  if (iVar1 == 0) {
    msleep(0x14);
    _printk(&DAT_00108c5f);
    uVar2 = gpio_to_desc(param_1);
    iVar1 = gpiod_direction_output_raw(uVar2,1);
    if (iVar1 == 0) {
      return;
    }
  }
  _printk(&DAT_001085a5,"bt_pull_resetb");
  return;
}



//------------------------------------------------------------
// bt_power_probe @ 00104244 size=1220
// signature: undefined bt_power_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bt_power_probe(long param_1)

{
  long *plVar1;
  long *plVar2;
  long *plVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  long lVar9;
  undefined *puVar10;
  void *__src;
  undefined8 uVar11;
  
  lVar8 = 0;
  do {
    lVar9 = lVar8 + 4;
    *(undefined4 *)(&DAT_0010bccc + lVar8) = 0xfffffffe;
    *(undefined4 *)((long)&power_src + lVar8) = 0xfffffffe;
    *(undefined4 *)((long)&DAT_0010bd54 + lVar8) = 0xfffffffe;
    lVar8 = lVar9;
  } while (lVar9 != 0x88);
  pwr_data = (long *)kmalloc_trace(_rfkill_register,0xdc0,0x358);
  if (pwr_data == (long *)0x0) {
    return -0xc;
  }
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  *pwr_data = param_1;
  lVar8 = of_find_property(uVar11,"qcom,peach-bt",0);
  if (lVar8 == 0) {
    lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,wcn786x",0);
    bVar4 = lVar8 != 0;
  }
  else {
    bVar4 = true;
  }
  *(bool *)(pwr_data + 0x1a) = bVar4;
  _printk(&DAT_001086dd,"bt_power_probe");
  lVar8 = alloc_workqueue("workq",0x10,0x100);
  plVar1 = pwr_data;
  pwr_data[0x2a] = lVar8;
  if (lVar8 == 0) {
    _printk(&DAT_00108137,"bt_power_probe");
    return -0xc;
  }
  plVar1[0x33] = 0xfffffffe0;
  plVar1[0x34] = (long)(plVar1 + 0x34);
  plVar1[0x35] = (long)(plVar1 + 0x34);
  plVar1[0x36] = (long)uwb_signal_handler;
  plVar1[0x2d] = 0xfffffffe0;
  plVar1[0x2e] = (long)(plVar1 + 0x2e);
  plVar1[0x2f] = (long)(plVar1 + 0x2e);
  plVar1[0x5c] = 0xfffffffe0;
  plVar1[0x30] = (long)bt_signal_handler;
  plVar1[0x5d] = (long)(plVar1 + 0x5d);
  plVar1[0x5e] = (long)(plVar1 + 0x5d);
  plVar1[0x5f] = (long)bt_power_vote;
  __init_waitqueue_head(plVar1 + 0x39,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x3c,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x3f,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x42,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x45,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x48,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x4b,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x4e,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x51,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  __init_waitqueue_head(pwr_data + 0x54,"&pwr_data->rsp_wait_q[itr]",&bt_power_probe___key);
  plVar3 = pwr_data;
  plVar1 = pwr_data + 0x62;
  plVar2 = pwr_data + 0x65;
  pwr_data[100] = 0;
  plVar3[0x62] = (long)plVar1;
  plVar3[99] = (long)plVar1;
  __mutex_init(plVar2,"&pwr_data->pwr_mtx",&bt_power_probe___key_145);
  __mutex_init(pwr_data + 0x21,"&pwr_data->btpower_state.state_machine_lock",
               &bt_power_probe___key_147);
  plVar1 = pwr_data;
  pwr_data[0x27] = 0;
  plVar1[0x28] = 0x100000000;
  perisec_cnss_bt_hw_disable_check();
  if (*(long *)(param_1 + 0x2f8) == 0) {
    __src = *(void **)(param_1 + 0xa0);
    if (__src == (void *)0x0) {
      _printk(&DAT_00108838,"bt_power_probe");
      iVar7 = 0;
      goto LAB_001046d4;
    }
    if (*(long *)((long)__src + 0x50) == 0) {
      *(code **)((long)__src + 0x50) = power_regulators;
      __src = *(void **)(param_1 + 0xa0);
    }
    memcpy(pwr_data,__src,0x358);
    iVar7 = 0;
  }
  else {
    iVar7 = bt_power_populate_dt_pinfo(param_1);
    if (iVar7 < 0) {
      _printk(&DAT_001083b3,"bt_power_probe");
      goto LAB_001046d4;
    }
    if ((int)pwr_data[0x1d] == 0) {
      _printk(&DAT_00108538,"bt_power_probe");
      *(long **)(param_1 + 0xa0) = pwr_data;
    }
    else {
      _printk(&DAT_001083de,"bt_power_probe");
    }
  }
  lVar8 = param_1 + 0x10;
  lVar9 = rfkill_alloc("bt_power",lVar8,2,btpower_rfkill_ops,*(undefined8 *)(param_1 + 0xa0));
  if (lVar9 == 0) {
    _dev_err(lVar8,"rfkill allocate failed\n");
LAB_001046d4:
    kfree(pwr_data);
    return iVar7;
  }
  iVar5 = device_create_file(lVar8,&dev_attr_extldo);
  if (iVar5 < 0) {
    _printk(&DAT_00108b8c,"btpower_rfkill_probe");
  }
  rfkill_init_sw_state(lVar9,1);
  previous = 1;
  iVar5 = rfkill_register(lVar9);
  if (iVar5 == 0) {
    *(long *)(param_1 + 0xa8) = lVar9;
  }
  else {
    _dev_err(lVar8,"rfkill register failed=%d\n",iVar5);
    rfkill_destroy(lVar9);
    if (iVar5 < 0) goto LAB_001046d4;
  }
  plVar1 = pwr_data;
  lVar8 = *pwr_data;
  uVar6 = of_property_read_string_helper(*(undefined8 *)(lVar8 + 0x2f8),"qcom,pdc_init_table",0,0,0)
  ;
  *(uint *)((long)plVar1 + 0xd4) = uVar6;
  if ((int)uVar6 < 1) {
    puVar10 = &DAT_0010722f;
  }
  else {
    lVar9 = __kmalloc((ulong)uVar6 << 3,0xdc0);
    plVar1[0x1b] = lVar9;
    iVar7 = of_property_read_string_helper
                      (*(undefined8 *)(lVar8 + 0x2f8),"qcom,pdc_init_table",lVar9,
                       (long)*(int *)((long)plVar1 + 0xd4),0);
    puVar10 = &UNK_00107de4;
    if (-1 < iVar7) {
      puVar10 = &DAT_001089fe;
    }
  }
  _printk(puVar10);
  btpower_aop_mbox_init(pwr_data);
  probe_finished = 1;
  return 0;
}



//------------------------------------------------------------
// bt_power_remove @ 0010470c size=184
// signature: undefined bt_power_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 bt_power_remove(long param_1)

{
  uint uVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  probe_finished = 0;
  _printk(&DAT_00108aa7,"btpower_rfkill_remove");
  lVar4 = *(long *)(param_1 + 0xa8);
  if (lVar4 != 0) {
    rfkill_unregister(lVar4);
  }
  rfkill_destroy(lVar4);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  uVar1 = *(uint *)(pwr_data + 0x78);
  if (0 < (int)uVar1) {
    lVar4 = 0;
    lVar2 = pwr_data;
    do {
      lVar3 = *(long *)(*(long *)(lVar2 + 0x30) + lVar4);
      if (lVar3 != 0) {
        regulator_put(lVar3);
        lVar2 = pwr_data;
      }
      lVar4 = lVar4 + 0x28;
    } while ((ulong)uVar1 * 0x28 != lVar4);
  }
  kfree();
  return 0;
}



//------------------------------------------------------------
// uwb_signal_handler @ 001047c8 size=200
// signature: undefined uwb_signal_handler(void)
// callers: []
//------------------------------------------------------------

void uwb_signal_handler(void)

{
  long lVar1;
  int iVar2;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0x1d;
  local_50 = 0xffffffff;
  local_48 = 0;
  local_40 = (ulong)*(uint *)(pwr_data + 0x14c);
  iVar2 = send_sig_info(0x1d,&local_58,*(undefined8 *)(pwr_data + 0x100));
  if (iVar2 < 0) {
    _printk(&DAT_00107a56,"uwb_signal_handler",iVar2,
            *(undefined4 *)(*(long *)(pwr_data + 0x100) + 0x630));
  }
  else {
    _printk(&DAT_00107d8e,"uwb_signal_handler");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// bt_signal_handler @ 00104894 size=200
// signature: undefined bt_signal_handler(void)
// callers: []
//------------------------------------------------------------

void bt_signal_handler(void)

{
  long lVar1;
  int iVar2;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  ulong local_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_38 = 0;
  uStack_30 = 0;
  local_58 = 0x1d;
  local_50 = 0xffffffff;
  local_48 = 0;
  local_40 = (ulong)*(uint *)(pwr_data + 0x14c);
  iVar2 = send_sig_info(0x1d,&local_58,*(undefined8 *)(pwr_data + 0xf8));
  if (iVar2 < 0) {
    _printk(&DAT_00107a56,"bt_signal_handler",iVar2,
            *(undefined4 *)(*(long *)(pwr_data + 0xf8) + 0x630));
  }
  else {
    _printk(&DAT_00107d8e,"bt_signal_handler");
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// bt_power_vote @ 00104960 size=948
// signature: undefined bt_power_vote(void)
// callers: []
//------------------------------------------------------------

void bt_power_vote(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  
  mutex_lock(pwr_data + 0x328);
  lVar6 = skb_dequeue(pwr_data + 0x310);
  if (lVar6 != 0) {
    iVar5 = 0;
    do {
      uVar2 = **(uint **)(lVar6 + 0xe0);
      skb_pull(lVar6,4);
      mutex_unlock(pwr_data + 0x328);
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x138);
      mutex_unlock(pwr_data + 0x108);
      pcVar8 = "Current state is = INVALID STATE";
      if (uVar3 < 4) {
        pcVar8 = (&PTR_s_Current_state_is_ALL_Client_OFF_001069e8)[(int)uVar3];
      }
      pcVar9 = "SSR STATE = INVALID STATE";
      if (*(uint *)(pwr_data + 0x148) < 5) {
        pcVar9 = (&PTR_s_and_No_SSR_00106a08)[(int)*(uint *)(pwr_data + 0x148)];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x13c);
      mutex_unlock(pwr_data + 0x108);
      pcVar10 = "Retention state = INVALID STATE";
      if (uVar3 < 6) {
        pcVar10 = (&PTR_s_Both_client_not_in_Retention_00106a30)[(int)uVar3];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x140);
      mutex_unlock(pwr_data + 0x108);
      pcVar11 = "INVALID STATE";
      if (uVar3 < 6) {
        pcVar11 = (&PTR_s_NO_GRANT_FOR_ANY_SS_00106a60)[(int)uVar3];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x144);
      mutex_unlock(pwr_data + 0x108);
      pcVar7 = "INVALID STATE";
      if (uVar3 < 6) {
        pcVar7 = (&PTR_s_NO_GRANT_FOR_ANY_SS_00106a60)[(int)uVar3];
      }
      _printk(&DAT_0010885b,"bt_power_vote",pcVar8,pcVar9,pcVar10,pcVar11,pcVar7);
      if ((uVar2 & 0xfffffffd) == 1) {
        uVar1 = 1;
        if (uVar2 != 1) {
          uVar1 = 2;
        }
        iVar5 = power_disable(uVar1);
      }
      else if ((uVar2 & 0xfffffffd) == 0) {
        iVar5 = btpower_on(uVar2);
      }
      else if ((uVar2 & 0xfffffffe) == 4) {
        iVar5 = btpower_retenion(uVar2);
      }
      else if (uVar2 - 6 < 4) {
        iVar5 = btpower_access_ctrl(uVar2);
        pcVar8 = "INVALID STATE";
        if ((uint)((long)iVar5 + 1) < 4) {
          pcVar8 = (&PTR_s_ACCESS_DISALLOWED_001069c8)[(long)iVar5 + 1];
        }
        _printk(&DAT_001078cd,"bt_power_vote",pcVar8);
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x138);
      mutex_unlock(pwr_data + 0x108);
      pcVar8 = "Current state is = INVALID STATE";
      if (uVar3 < 4) {
        pcVar8 = (&PTR_s_Current_state_is_ALL_Client_OFF_001069e8)[(int)uVar3];
      }
      pcVar9 = "SSR STATE = INVALID STATE";
      if (*(uint *)(pwr_data + 0x148) < 5) {
        pcVar9 = (&PTR_s_and_No_SSR_00106a08)[(int)*(uint *)(pwr_data + 0x148)];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x13c);
      mutex_unlock(pwr_data + 0x108);
      pcVar10 = "Retention state = INVALID STATE";
      if (uVar3 < 6) {
        pcVar10 = (&PTR_s_Both_client_not_in_Retention_00106a30)[(int)uVar3];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x140);
      mutex_unlock(pwr_data + 0x108);
      pcVar11 = "INVALID STATE";
      if (uVar3 < 6) {
        pcVar11 = (&PTR_s_NO_GRANT_FOR_ANY_SS_00106a60)[(int)uVar3];
      }
      mutex_lock(pwr_data + 0x108);
      uVar3 = *(uint *)(pwr_data + 0x144);
      mutex_unlock(pwr_data + 0x108);
      pcVar7 = "INVALID STATE";
      if (uVar3 < 6) {
        pcVar7 = (&PTR_s_NO_GRANT_FOR_ANY_SS_00106a60)[(int)uVar3];
      }
      _printk(&DAT_00106f9c,"bt_power_vote",pcVar8,pcVar9,pcVar10,pcVar11,pcVar7);
      if (9 < uVar2) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104d14);
        (*pcVar4)();
      }
      lVar6 = pwr_data + (ulong)uVar2 * 0x18;
      *(int *)(pwr_data + (ulong)uVar2 * 4 + 0x2b8) = iVar5;
      __wake_up(lVar6 + 0x1c8,1,1,0);
      mutex_lock(pwr_data + 0x328);
      lVar6 = skb_dequeue(pwr_data + 0x310);
    } while (lVar6 != 0);
  }
  mutex_unlock(pwr_data + 0x328);
  return;
}



//------------------------------------------------------------
// bt_power_populate_dt_pinfo @ 00104d14 size=1356
// signature: undefined bt_power_populate_dt_pinfo(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

void bt_power_populate_dt_pinfo(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  int iVar4;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong *puVar7;
  ulong uVar8;
  undefined *puVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  char *__s1;
  long local_a8 [11];
  
  lVar1 = sp_el0;
  local_a8[10] = *(long *)(lVar1 + 0x638);
  _printk(&DAT_00108aa7,"bt_power_populate_dt_pinfo");
  if (pwr_data == 0) {
    uVar5 = 0xfffffff4;
    goto LAB_00104d68;
  }
  if ((*(char *)(pwr_data + 0xd0) != '\0') &&
     (puVar6 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),0),
     puVar6 != (undefined8 *)0x0)) {
    do {
      __s1 = (char *)*puVar6;
      iVar4 = strcmp(__s1,"bt_ganges");
      if (iVar4 == 0) {
        plVar10 = (long *)(pwr_data + 0x158);
LAB_00104e64:
        *plVar10 = (long)puVar6;
        _printk(&DAT_00107b98,"bt_power_populate_dt_pinfo",*puVar6);
      }
      else {
        iVar4 = strcmp(__s1,"uwb_ganges");
        if (iVar4 == 0) {
          plVar10 = (long *)(pwr_data + 0x160);
          goto LAB_00104e64;
        }
      }
      puVar6 = (undefined8 *)of_get_next_available_child(*(undefined8 *)(param_1 + 0x2f8),puVar6);
    } while (puVar6 != (undefined8 *)0x0);
  }
  lVar1 = param_1 + 0x10;
  puVar6 = (undefined8 *)of_device_get_match_data(lVar1);
  lVar12 = pwr_data;
  if (puVar6 == (undefined8 *)0x0) {
    _printk(&DAT_00108467,"get_power_dt_pinfo");
    goto LAB_00104dd8;
  }
  uVar2 = puVar6[3];
  uVar5 = *puVar6;
  uVar3 = puVar6[1];
  *(undefined8 *)(pwr_data + 0x68) = puVar6[2];
  *(undefined8 *)(lVar12 + 0x70) = uVar2;
  *(undefined8 *)(lVar12 + 0x58) = uVar5;
  *(undefined8 *)(lVar12 + 0x60) = uVar3;
  *(undefined8 *)(lVar12 + 0x30) = puVar6[4];
  *(undefined4 *)(lVar12 + 0x78) = *(undefined4 *)(puVar6 + 5);
  if (*(char *)(lVar12 + 0xd0) == '\0') {
    _printk(&DAT_0010855d,"get_power_dt_pinfo");
  }
  else {
    *(undefined8 *)(lVar12 + 0x38) = puVar6[6];
    *(undefined8 *)(lVar12 + 0x40) = puVar6[8];
    *(undefined4 *)(lVar12 + 0x7c) = *(undefined4 *)(puVar6 + 7);
    *(undefined4 *)(lVar12 + 0x80) = *(undefined4 *)(puVar6 + 9);
    _printk(&DAT_0010888d,"get_power_dt_pinfo");
  }
  if (0 < *(int *)(pwr_data + 0x78)) {
    lVar11 = 0;
    lVar12 = 0;
    do {
      iVar4 = dt_parse_vreg_info(lVar1,*(undefined8 *)(pwr_data + 0x158),
                                 *(long *)(pwr_data + 0x30) + lVar11);
      if (iVar4 != 0) goto LAB_00104fcc;
      lVar12 = lVar12 + 1;
      lVar11 = lVar11 + 0x28;
    } while (lVar12 < *(int *)(pwr_data + 0x78));
  }
  if (*(char *)(pwr_data + 0xd0) != '\0') {
    if (0 < *(int *)(pwr_data + 0x80)) {
      lVar11 = 0;
      lVar12 = 0;
      do {
        iVar4 = dt_parse_vreg_info(lVar1,0,*(long *)(pwr_data + 0x40) + lVar11);
        if (iVar4 != 0) goto LAB_00104fcc;
        lVar12 = lVar12 + 1;
        lVar11 = lVar11 + 0x28;
      } while (lVar12 < *(int *)(pwr_data + 0x80));
    }
    if (0 < *(int *)(pwr_data + 0x7c)) {
      lVar11 = 0;
      lVar12 = 0;
      do {
        iVar4 = dt_parse_vreg_info(lVar1,*(undefined8 *)(pwr_data + 0x160),
                                   *(long *)(pwr_data + 0x38) + lVar11);
        if (iVar4 != 0) goto LAB_00104fcc;
        lVar12 = lVar12 + 1;
        lVar11 = lVar11 + 0x28;
      } while (lVar12 < *(int *)(pwr_data + 0x7c));
    }
  }
  goto LAB_00104fd0;
LAB_00104fcc:
  if (iVar4 < 0) {
LAB_00104dd8:
    _printk(&DAT_00106ed4,"bt_power_populate_dt_pinfo");
  }
LAB_00104fd0:
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,bt-reset-gpio",0,0);
  *(int *)(pwr_data + 8) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_00107982);
  }
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,wl-reset-gpio",0,0);
  *(int *)(pwr_data + 0xc) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_00107478,"get_gpio_dt_pinfo");
  }
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,wl-resetb-gpio",0,0);
  lVar12 = pwr_data;
  *(int *)(pwr_data + 0x1c) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_00107d9f,"get_gpio_dt_pinfo");
    lVar12 = pwr_data;
  }
  iVar4 = of_property_read_variable_u32_array(uVar5,"mpm_wake_set_gpios",lVar12 + 0x20,1,0);
  if (iVar4 < 0) {
    _printk(&DAT_00108d20);
  }
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,bt-sw-ctrl-gpio",0,0);
  *(int *)(pwr_data + 0x10) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_00106ff1);
  }
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,bt-debug-gpio",0,0);
  *(int *)(pwr_data + 0x14) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_00107203);
  }
  iVar4 = of_get_named_gpio_flags(uVar5,"qcom,xo-clk-gpio",0,0);
  lVar12 = pwr_data;
  *(int *)(pwr_data + 0x24) = iVar4;
  if (iVar4 < 0) {
    _printk(&DAT_0010782f);
    lVar12 = pwr_data;
  }
  uVar5 = *(undefined8 *)(param_1 + 0x2f8);
  _printk(&DAT_00108aa7,"bt_dt_parse_clk_info");
  *(undefined8 *)(lVar12 + 0x48) = 0;
  local_a8[8] = 0;
  local_a8[9] = 0;
  local_a8[6] = 0;
  local_a8[7] = 0;
  local_a8[4] = 0;
  local_a8[5] = 0;
  local_a8[2] = 0;
  local_a8[3] = 0;
  local_a8[0] = 0;
  local_a8[1] = 0;
  iVar4 = __of_parse_phandle_with_args(uVar5,"clocks",0,0,0,local_a8);
  if ((iVar4 == 0) && (local_a8[0] != 0)) {
    puVar7 = (ulong *)devm_kmalloc(lVar1,0x18,0xdc0);
    if (puVar7 != (ulong *)0x0) {
      uVar8 = devm_kmalloc(lVar1,0x14,0xdc0);
      puVar7[1] = uVar8;
      iVar4 = of_property_read_string_helper(uVar5,"clock-names",puVar7 + 1,1,0);
      if (iVar4 < 0) {
        puVar9 = &DAT_0010825a;
        goto LAB_00105228;
      }
      uVar8 = devm_clk_get(lVar1,puVar7[1]);
      *puVar7 = uVar8;
      if (uVar8 < 0xfffffffffffff001) {
        *(ulong **)(lVar12 + 0x48) = puVar7;
      }
      else {
        _printk(&DAT_00106f04,"bt_dt_parse_clk_info",puVar7[1],uVar8);
        *puVar7 = 0;
      }
    }
  }
  else {
    puVar9 = &DAT_00107be4;
LAB_00105228:
    _printk(puVar9,"bt_dt_parse_clk_info");
  }
  uVar5 = 0;
  *(code **)(pwr_data + 0x50) = power_regulators;
LAB_00104d68:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_a8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// dt_parse_vreg_info @ 00105260 size=500
// signature: undefined dt_parse_vreg_info(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

ulong dt_parse_vreg_info(long param_1,long param_2,ulong *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  long lVar4;
  undefined1 uVar5;
  int iVar6;
  ulong uVar7;
  uint *puVar8;
  char *pcVar9;
  int local_ac;
  char local_a8 [32];
  long local_88 [11];
  
  lVar4 = sp_el0;
  local_88[10] = *(long *)(lVar4 + 0x638);
  pcVar9 = (char *)param_3[1];
  local_ac = 0;
  local_a8[0x10] = '\0';
  local_a8[0x11] = '\0';
  local_a8[0x12] = '\0';
  local_a8[0x13] = '\0';
  local_a8[0x14] = '\0';
  local_a8[0x15] = '\0';
  local_a8[0x16] = '\0';
  local_a8[0x17] = '\0';
  local_a8[0x18] = '\0';
  local_a8[0x19] = '\0';
  local_a8[0x1a] = '\0';
  local_a8[0x1b] = '\0';
  local_a8[0x1c] = '\0';
  local_a8[0x1d] = '\0';
  local_a8[0x1e] = '\0';
  local_a8[0x1f] = '\0';
  local_a8[0] = '\0';
  local_a8[1] = '\0';
  local_a8[2] = '\0';
  local_a8[3] = '\0';
  local_a8[4] = '\0';
  local_a8[5] = '\0';
  local_a8[6] = '\0';
  local_a8[7] = '\0';
  local_a8[8] = '\0';
  local_a8[9] = '\0';
  local_a8[10] = '\0';
  local_a8[0xb] = '\0';
  local_a8[0xc] = '\0';
  local_a8[0xd] = '\0';
  local_a8[0xe] = '\0';
  local_a8[0xf] = '\0';
  if (param_2 == 0) {
    param_2 = *(long *)(param_1 + 0x2e8);
  }
  snprintf(local_a8,0x20,"%s-supply",pcVar9);
  local_88[8] = 0;
  local_88[9] = 0;
  local_88[6] = 0;
  local_88[7] = 0;
  local_88[4] = 0;
  local_88[5] = 0;
  local_88[2] = 0;
  local_88[3] = 0;
  local_88[0] = 0;
  local_88[1] = 0;
  iVar6 = __of_parse_phandle_with_args(param_2,local_a8,0,0,0,local_88);
  if ((iVar6 == 0) && (local_88[0] != 0)) {
    uVar7 = regulator_get(param_1,pcVar9);
    *param_3 = uVar7;
    if (0xfffffffffffff000 < uVar7) {
      *param_3 = 0;
      _printk(&DAT_001089a8,"dt_parse_vreg_info",pcVar9,uVar7 & 0xffffffff);
      goto LAB_00105420;
    }
    snprintf(local_a8,0x20,"%s-config",(char *)param_3[1]);
    puVar8 = (uint *)of_get_property(param_2,local_a8,&local_ac);
    if ((puVar8 == (uint *)0x0) || (local_ac != 0x10)) {
      pcVar9 = "doesn\'t exist";
      if (puVar8 != (uint *)0x0) {
        pcVar9 = "invalid format";
      }
      _printk(&DAT_00107455,"dt_parse_vreg_info",local_a8,pcVar9);
      uVar1 = (uint)param_3[2];
      uVar2 = *(uint *)((long)param_3 + 0x14);
      uVar3 = (uint)param_3[3];
      uVar5 = *(undefined1 *)((long)param_3 + 0x1d);
    }
    else {
      uVar1 = (*puVar8 & 0xff00ff00) >> 8 | (*puVar8 & 0xff00ff) << 8;
      uVar1 = uVar1 >> 0x10 | uVar1 << 0x10;
      *(uint *)(param_3 + 2) = uVar1;
      uVar2 = (puVar8[1] & 0xff00ff00) >> 8 | (puVar8[1] & 0xff00ff) << 8;
      uVar2 = uVar2 >> 0x10 | uVar2 << 0x10;
      *(uint *)((long)param_3 + 0x14) = uVar2;
      uVar3 = (puVar8[2] & 0xff00ff00) >> 8 | (puVar8[2] & 0xff00ff) << 8;
      uVar3 = uVar3 >> 0x10 | uVar3 << 0x10;
      *(uint *)(param_3 + 3) = uVar3;
      uVar5 = puVar8[3] != 0;
      *(undefined1 *)((long)param_3 + 0x1d) = uVar5;
    }
    _printk(&DAT_00108cc7,"dt_parse_vreg_info",param_3[1],uVar1,uVar2,uVar3,uVar5);
  }
  else {
    _printk(&DAT_00107bb4,"dt_parse_vreg_info",pcVar9);
  }
  uVar7 = 0;
LAB_00105420:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_88[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7 & 0xffffffff;
}



//------------------------------------------------------------
// btpower_toggle_radio @ 00105458 size=108
// signature: undefined btpower_toggle_radio(void)
// callers: []
//------------------------------------------------------------

undefined8 btpower_toggle_radio(long param_1,byte param_2)

{
  code *pcVar1;
  undefined8 uVar2;
  
  if (previous != (param_2 & 1)) {
    if (*(int *)(*(code **)(param_1 + 0x50) + -4) != 0x56e5b5a5) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x1054a4);
      (*pcVar1)();
    }
    uVar2 = (**(code **)(param_1 + 0x50))(0,(param_2 ^ 0xff) & 1);
    if ((int)uVar2 != 0) {
      return uVar2;
    }
  }
  previous = param_2 & 1;
  return 0;
}



//------------------------------------------------------------
// extldo_show @ 001054c8 size=48
// signature: undefined extldo_show(void)
// callers: []
//------------------------------------------------------------

long extldo_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,6,"false\n");
  return (long)iVar1;
}



//------------------------------------------------------------
// bt_ioctl @ 001054fc size=1716
// signature: undefined bt_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long bt_ioctl(undefined8 param_1,int param_2,ulong param_3)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  char *pcVar8;
  undefined8 *puVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  
  if ((pwr_data == 0) || ((probe_finished & 1) == 0)) {
    _printk(&DAT_00108d7f,"bt_ioctl");
    return -0xb;
  }
  lVar3 = -0x203;
  iVar2 = 0;
  uVar10 = (uint)param_3;
  switch(param_2) {
  case 0xbfac:
    break;
  case 0xbfad:
  case 0xbfe1:
    pcVar1 = "BT_CMD_PWR_CTRL";
    if (param_2 != 0xbfad) {
      pcVar1 = "UWB_CMD_PWR_CTRL";
    }
    if (uVar10 < 3) {
      pcVar8 = *(char **)((long)&PTR_s_Power_OFF_00106a90 +
                         (-(param_3 >> 0x1f & 1) & 0xfffffff800000000 | (param_3 & 0xffffffff) << 3)
                         );
    }
    else {
      pcVar8 = "INVALID STATE";
    }
    _printk(&DAT_00107b0e,"btpower_handle_client_request",pcVar1,pcVar8);
    if (param_2 == 0xbfad) {
      if (uVar10 < 3) {
        puVar5 = &DAT_00106aa8;
LAB_001059f0:
        iVar2 = schedule_client_voting
                          (*(undefined4 *)
                            (puVar5 + (-(param_3 >> 0x1f & 1) & 0xfffffffc00000000 |
                                      (param_3 & 0xffffffff) << 2)));
        goto LAB_00105574;
      }
      iVar2 = -1;
    }
    else {
      iVar2 = -1;
      if ((param_2 == 0xbfe1) && (uVar10 < 3)) {
        puVar5 = &DAT_00106ab4;
        goto LAB_001059f0;
      }
    }
    break;
  case 0xbfae:
    _printk(&DAT_001082a6,"bt_ioctl",param_3 & 0xffffffff);
    if (uVar10 == 0) {
      _printk(&DAT_00107674,"bt_ioctl");
      iVar2 = 0;
      soc_id = 0;
    }
    else {
      iVar2 = 0;
      soc_id = uVar10;
    }
    break;
  case 0xbfaf:
    _printk(&DAT_00108165,"bt_ioctl",pwr_data + 0x58);
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_3, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar11 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar11 < 0x7fffffffe1) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar13 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      lVar3 = __arch_copy_to_user(puVar9,param_3 & 0xff7fffffffffffff,pwr_data + 0x58,0x20);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
LAB_00105978:
      if (lVar3 == 0) goto LAB_001055ac;
    }
    goto LAB_0010597c;
  case 0xbfb0:
    _printk(&DAT_001079c0);
    if (*(int *)(pwr_data + 0x10) < 1) {
      _printk(&DAT_001089ca);
      return -0x16;
    }
    DAT_0010bcd0 = 0xffffffff;
    gpio_to_desc(*(undefined4 *)(pwr_data + 0x10));
    iVar2 = gpiod_direction_input();
    if (iVar2 == 0) {
      gpio_to_desc(*(undefined4 *)(pwr_data + 0x10));
      DAT_0010bcd0 = gpiod_get_raw_value();
      _printk(&DAT_00107aca,*(undefined4 *)(pwr_data + 0x10),DAT_0010bcd0);
    }
    else {
      _printk(&DAT_00107aab,"bt_ioctl");
      _printk(&DAT_00106cca,"bt_ioctl",iVar2);
    }
    break;
  case 0xbfb1:
    _printk(&DAT_00106d36);
    gpio_to_desc(*(undefined4 *)(pwr_data + 0x10));
    DAT_0010bc84 = gpiod_get_raw_value();
    gpio_to_desc(*(undefined4 *)(pwr_data + 8));
    DAT_0010bc80 = gpiod_get_raw_value();
    if (0 < *(int *)(pwr_data + 0x78)) {
      lVar12 = 0;
      lVar3 = 0;
      do {
        set_pwr_srcs_status(*(long *)(pwr_data + 0x30) + lVar12,0);
        lVar3 = lVar3 + 1;
        lVar12 = lVar12 + 0x28;
      } while (lVar3 < *(int *)(pwr_data + 0x78));
    }
    if (0 < *(int *)(pwr_data + 0x80)) {
      lVar12 = 0;
      lVar3 = 0;
      do {
        set_pwr_srcs_status(*(long *)(pwr_data + 0x40) + lVar12,2);
        lVar3 = lVar3 + 1;
        lVar12 = lVar12 + 0x28;
      } while (lVar3 < *(int *)(pwr_data + 0x80));
    }
    if (0 < *(int *)(pwr_data + 0x7c)) {
      lVar12 = 0;
      lVar3 = 0;
      do {
        set_pwr_srcs_status(*(long *)(pwr_data + 0x38) + lVar12,1);
        lVar3 = lVar3 + 1;
        lVar12 = lVar12 + 0x28;
      } while (lVar3 < *(int *)(pwr_data + 0x7c));
    }
    puVar9 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar11 = param_3, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar11 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar11 < 0x7ffffffe69) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        puVar9 = (undefined8 *)puVar9[1];
        uVar13 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar9;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      lVar3 = __arch_copy_to_user(puVar9,param_3 & 0xff7fffffffffffff,&power_src,0x198);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar11 = daif;
        if ((uVar11 & 0x80) == 0) {
          uVar13 = daif;
          daif = uVar13 | 0xc0;
        }
        uVar13 = ttbr1_el1;
        ttbr0_el1 = (uVar13 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar13 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar11;
      }
      goto LAB_00105978;
    }
LAB_0010597c:
    _printk(&DAT_00107693,"bt_ioctl");
    iVar2 = -0xe;
    break;
  default:
    goto switchD_00105564_caseD_bfb2;
  case 0xbfc0:
    _printk(&DAT_00107375,"bt_ioctl");
    btpower_enable_ipa_vreg(pwr_data);
    goto LAB_001055ac;
  case 0xbfc1:
    _printk(&DAT_00107261,"bt_ioctl");
    bt_kernel_panic(param_3);
  case 0xbfc2:
    _printk(&DAT_00108651,"bt_ioctl");
    uVar10 = uVar10 & 0xffff;
    uVar13 = param_3 >> 0x10 & 0xffff;
    uVar4 = GetUwbPrimaryCrashReason(uVar10);
    uVar6 = GetUwbSecondaryCrashReason(uVar13);
    uVar11 = param_3 >> 0x20 & 0xffff;
    uVar7 = GetSourceSubsystemString(uVar11);
    _printk(&DAT_0010873a,"bt_ioctl",uVar10,uVar4,uVar13,uVar6,uVar11,uVar7);
    uVar4 = GetUwbPrimaryCrashReason(uVar10);
    uVar6 = GetUwbSecondaryCrashReason(uVar13);
                    /* WARNING: Subroutine does not return */
    panic("%s: UWB kernel panic PrimaryReason = (0x%02x)[%s] | SecondaryReason = (0x%02x)[%s] | SourceSubsystem = (0x%02x)[%s]\n"
          ,"bt_ioctl",uVar10,uVar4,uVar13,uVar6,uVar11,uVar7);
  case 0xbfe2:
    if (uVar10 == 6) {
      lVar3 = sp_el0;
LAB_00105a28:
      *(long *)(pwr_data + 0x100) = lVar3;
      puVar5 = &DAT_00107f22;
    }
    else {
      if (uVar10 != 5) {
        uVar4 = 1;
        goto LAB_001055a8;
      }
      lVar3 = sp_el0;
LAB_00105a0c:
      *(long *)(pwr_data + 0xf8) = lVar3;
      puVar5 = &DAT_001074e0;
    }
    _printk(puVar5,"btpower_register_client",*(undefined4 *)(lVar3 + 0x634));
    goto LAB_001055ac;
  case 0xbfe3:
    if (uVar10 == 6) {
      lVar3 = sp_el0;
      goto LAB_00105a28;
    }
    if (uVar10 == 5) {
      lVar3 = sp_el0;
      goto LAB_00105a0c;
    }
    uVar4 = 2;
LAB_001055a8:
    client_state_notified(uVar4);
LAB_001055ac:
    iVar2 = 0;
    break;
  case 0xbfe4:
  case 0xbfe5:
    iVar2 = btpower_process_access_req(param_2,param_3 & 0xffffffff);
LAB_00105574:
  }
  lVar3 = (long)iVar2;
switchD_00105564_caseD_bfb2:
  return lVar3;
}



//------------------------------------------------------------
// btpower_enable_ipa_vreg @ 00105be0 size=328
// signature: undefined btpower_enable_ipa_vreg(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

void btpower_enable_ipa_vreg(long param_1)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 local_88;
  char *local_80;
  char local_78 [64];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (btpower_enable_ipa_vreg_config_done == '\x01') {
    puVar3 = &DAT_001082ce;
  }
  else {
    if ((*(char **)(param_1 + 200) != (char *)0x0) && (*(long *)(param_1 + 0xc0) != 0)) {
      local_78[0x30] = '\0';
      local_78[0x31] = '\0';
      local_78[0x32] = '\0';
      local_78[0x33] = '\0';
      local_78[0x34] = '\0';
      local_78[0x35] = '\0';
      local_78[0x36] = '\0';
      local_78[0x37] = '\0';
      local_78[0x38] = '\0';
      local_78[0x39] = '\0';
      local_78[0x3a] = '\0';
      local_78[0x3b] = '\0';
      local_78[0x3c] = '\0';
      local_78[0x3d] = '\0';
      local_78[0x3e] = '\0';
      local_78[0x3f] = '\0';
      local_88 = 0x40;
      local_78[0x20] = '\0';
      local_78[0x21] = '\0';
      local_78[0x22] = '\0';
      local_78[0x23] = '\0';
      local_78[0x24] = '\0';
      local_78[0x25] = '\0';
      local_78[0x26] = '\0';
      local_78[0x27] = '\0';
      local_78[0x28] = '\0';
      local_78[0x29] = '\0';
      local_78[0x2a] = '\0';
      local_78[0x2b] = '\0';
      local_78[0x2c] = '\0';
      local_78[0x2d] = '\0';
      local_78[0x2e] = '\0';
      local_78[0x2f] = '\0';
      local_78[0x10] = '\0';
      local_78[0x11] = '\0';
      local_78[0x12] = '\0';
      local_78[0x13] = '\0';
      local_78[0x14] = '\0';
      local_78[0x15] = '\0';
      local_78[0x16] = '\0';
      local_78[0x17] = '\0';
      local_78[0x18] = '\0';
      local_78[0x19] = '\0';
      local_78[0x1a] = '\0';
      local_78[0x1b] = '\0';
      local_78[0x1c] = '\0';
      local_78[0x1d] = '\0';
      local_78[0x1e] = '\0';
      local_78[0x1f] = '\0';
      local_78[0] = '\0';
      local_78[1] = '\0';
      local_78[2] = '\0';
      local_78[3] = '\0';
      local_78[4] = '\0';
      local_78[5] = '\0';
      local_78[6] = '\0';
      local_78[7] = '\0';
      local_78[8] = '\0';
      local_78[9] = '\0';
      local_78[10] = '\0';
      local_78[0xb] = '\0';
      local_78[0xc] = '\0';
      local_78[0xd] = '\0';
      local_78[0xe] = '\0';
      local_78[0xf] = '\0';
      snprintf(local_78,0x40,"{class: wlan_pdc, res: %s.%s, %s: %d}",*(char **)(param_1 + 200),"e",
               "upval",1);
      _printk(&DAT_0010713d,"btpower_aop_set_vreg_param",local_78);
      local_80 = local_78;
      iVar2 = mbox_send_message(*(undefined8 *)(param_1 + 0xc0),&local_88);
      if (iVar2 < 0) {
        _printk(&DAT_0010866d,"btpower_aop_set_vreg_param",local_78,iVar2);
      }
      else {
        _printk(&DAT_0010803b,"btpower_enable_ipa_vreg");
        btpower_enable_ipa_vreg_config_done = '\x01';
      }
      goto LAB_00105c48;
    }
    puVar3 = &DAT_00108a83;
  }
  _printk(puVar3,"btpower_enable_ipa_vreg");
LAB_00105c48:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00106ac4 size=348
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  ulong uVar1;
  long lVar2;
  
  probe_finished = 0;
  uVar1 = __platform_driver_register(&bt_power_driver,&__this_module);
  if ((int)uVar1 == 0) {
    bt_major = __register_chrdev(uVar1,0,0x100,&DAT_001083b0,bt_dev_fops);
    if (bt_major < 0) {
      _printk(&DAT_00107614,"btpower_init");
      uVar1 = 0xffffffff;
    }
    else {
      bt_class = __class_create(&__this_module,"bt-dev",&btpower_init___key);
      if (bt_class < 0xfffffffffffff001) {
        lVar2 = device_create(bt_class,0,bt_major << 0x14,0,"btpower");
        if (lVar2 != 0) {
          return 0;
        }
        _printk(&DAT_00107614,"btpower_init");
        class_destroy(bt_class);
        uVar1 = 0;
      }
      else {
        _printk(&DAT_00107b5b,"btpower_init");
        uVar1 = 0xffffffff;
      }
      __unregister_chrdev(bt_major,0,0x100,&DAT_001083b0);
    }
    platform_driver_unregister(&bt_power_driver);
  }
  else {
    uVar1 = uVar1 & 0xffffffff;
    _printk(&DAT_001075ea,"btpower_init",uVar1);
  }
  return uVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00106c24 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&bt_power_driver);
  return;
}



//------------------------------------------------------------
// get_client_env_object @ 0010e000 size=1
// signature: undefined get_client_env_object(void)
// callers: [perisec_cnss_bt_hw_disable_check]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_client_env_object(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010e008 size=1
// signature: undefined _printk(void)
// callers: [btpower_set_xo_clk_gpio_state, dt_parse_vreg_info, bt_ioctl, bt_kernel_panic, bt_power_remove, uwb_signal_handler, bt_configure_gpios, bt_aop_pdc_reconfig, btpower_retenion, btpower_get_chipset_version, btpower_handle_client_request, btpower_aop_mbox_init, bt_aop_send_msg, perisec_cnss_bt_hw_disable_check, btpower_process_access_req, vreg_disable, power_disable, set_pwr_srcs_status, bt_resetb_operation, btpower_register_slimdev, bt_power_populate_dt_pinfo, platform_regulators_pwr, schedule_client_voting, btpower_access_ctrl, btpower_register_client, power_enable, btpower_enable_ipa_vreg, client_state_notified, init_module, bt_power_probe, bt_pull_resetb, bt_signal_handler, power_regulators, vreg_enable_retention, vreg_enable, btpower_on, bt_power_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010e010 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [btpower_enable_ipa_vreg, dt_parse_vreg_info, uwb_signal_handler, bt_power_populate_dt_pinfo, perisec_cnss_bt_hw_disable_check, schedule_client_voting, bt_aop_pdc_reconfig, bt_signal_handler, bt_aop_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010e018 size=1
// signature: undefined mutex_lock(void)
// callers: [client_state_notified, btpower_set_grant_state, schedule_client_voting, btpower_set_grant_pending_state, btpower_retenion, power_disable, btpower_on, btpower_access_ctrl, bt_power_vote, power_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010e020 size=1
// signature: undefined mutex_unlock(void)
// callers: [client_state_notified, btpower_set_grant_state, schedule_client_voting, btpower_set_grant_pending_state, btpower_retenion, power_disable, btpower_on, btpower_access_ctrl, bt_power_vote, power_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 0010e028 size=1
// signature: undefined gpio_free(void)
// callers: [btpower_set_xo_clk_gpio_state, platform_regulators_pwr, power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get_voltage @ 0010e030 size=1
// signature: undefined regulator_get_voltage(void)
// callers: [set_pwr_srcs_status, platform_regulators_pwr, power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0010e038 size=1
// signature: undefined clk_disable(void)
// callers: [power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0010e040 size=1
// signature: undefined clk_unprepare(void)
// callers: [power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0010e048 size=1
// signature: undefined clk_prepare(void)
// callers: [power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0010e050 size=1
// signature: undefined clk_enable(void)
// callers: [power_regulators]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010e058 size=1
// signature: undefined queue_work_on(void)
// callers: [send_signal_to_subsystem, client_state_notified, schedule_client_voting, power_disable, btpower_access_ctrl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 0010e060 size=1
// signature: undefined gpio_to_desc(void)
// callers: [btpower_set_xo_clk_gpio_state, log_power_src_val, bt_ioctl, bt_resetb_operation, bt_configure_gpios, bt_pull_resetb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 0010e068 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [log_power_src_val, bt_ioctl, bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 0010e070 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [platform_regulators_pwr, vreg_disable, vreg_enable_retention, vreg_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0010e078 size=1
// signature: undefined regulator_set_load(void)
// callers: [platform_regulators_pwr, vreg_disable, vreg_enable_retention, vreg_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 0010e080 size=1
// signature: undefined __alloc_skb(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_put @ 0010e088 size=1
// signature: undefined skb_put(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_queue_tail @ 0010e090 size=1
// signature: undefined skb_queue_tail(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_queue_tail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0010e0a0 size=1
// signature: undefined init_wait_entry(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0010e0a8 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0010e0b0 size=1
// signature: undefined schedule_timeout(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0010e0b8 size=1
// signature: undefined finish_wait(void)
// callers: [schedule_client_voting]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0010e0d0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [bt_kernel_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 0010e0d8 size=1
// signature: noreturn undefined panic(void)
// callers: [bt_ioctl, bt_kernel_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010e0e0 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [bt_kernel_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010e0e8 size=1
// signature: size_t strlen(char * __s)
// callers: [bt_kernel_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010e0f0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [bt_kernel_panic, bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010e0f8 size=1
// signature: undefined fortify_panic(void)
// callers: [bt_kernel_panic]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_send_message @ 0010e108 size=1
// signature: undefined mbox_send_message(void)
// callers: [btpower_enable_ipa_vreg, bt_aop_pdc_reconfig, bt_aop_send_msg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_send_message(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mbox_request_channel @ 0010e110 size=1
// signature: undefined mbox_request_channel(void)
// callers: [btpower_aop_mbox_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mbox_request_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010e118 size=1
// signature: undefined of_property_read_string(void)
// callers: [btpower_aop_mbox_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010e120 size=1
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
// __register_chrdev @ 0010e128 size=1
// signature: undefined __register_chrdev(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 0010e130 size=1
// signature: undefined __class_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 0010e138 size=1
// signature: undefined device_create(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 0010e140 size=1
// signature: undefined class_destroy(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 0010e148 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_driver_unregister @ 0010e150 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0010e158 size=1
// signature: undefined regulator_enable(void)
// callers: [vreg_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_set_raw_value @ 0010e160 size=1
// signature: undefined gpiod_set_raw_value(void)
// callers: [bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_set_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0010e168 size=1
// signature: undefined msleep(void)
// callers: [bt_resetb_operation, bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 0010e170 size=1
// signature: undefined gpio_request(void)
// callers: [btpower_set_xo_clk_gpio_state, bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 0010e178 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [btpower_set_xo_clk_gpio_state, bt_resetb_operation, bt_configure_gpios, bt_pull_resetb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_gpio_mpm_wake_set @ 0010e180 size=1
// signature: undefined msm_gpio_mpm_wake_set(void)
// callers: [bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_gpio_mpm_wake_set(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 0010e188 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [bt_ioctl, bt_configure_gpios]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0010e190 size=1
// signature: undefined regulator_disable(void)
// callers: [vreg_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0010e198 size=1
// signature: undefined usleep_range_state(void)
// callers: [btpower_set_xo_clk_gpio_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010e1a8 size=1
// signature: undefined kmalloc_trace(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010e1b0 size=1
// signature: undefined of_find_property(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_workqueue @ 0010e1b8 size=1
// signature: undefined alloc_workqueue(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_workqueue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0010e1c0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010e1c8 size=1
// signature: undefined __mutex_init(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rfkill_alloc @ 0010e1d0 size=1
// signature: undefined rfkill_alloc(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rfkill_alloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010e1d8 size=1
// signature: undefined _dev_err(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 0010e1e0 size=1
// signature: undefined device_create_file(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rfkill_init_sw_state @ 0010e1e8 size=1
// signature: undefined rfkill_init_sw_state(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rfkill_init_sw_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rfkill_register @ 0010e1f0 size=1
// signature: undefined rfkill_register(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rfkill_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0010e1f8 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [bt_power_probe, bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010e200 size=1
// signature: undefined __kmalloc(void)
// callers: [bt_power_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rfkill_destroy @ 0010e208 size=1
// signature: undefined rfkill_destroy(void)
// callers: [bt_power_probe, bt_power_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rfkill_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010e210 size=1
// signature: undefined kfree(void)
// callers: [bt_power_probe, bt_power_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rfkill_unregister @ 0010e218 size=1
// signature: undefined rfkill_unregister(void)
// callers: [bt_power_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rfkill_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 0010e220 size=1
// signature: undefined regulator_put(void)
// callers: [bt_power_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// send_sig_info @ 0010e228 size=1
// signature: undefined send_sig_info(void)
// callers: [uwb_signal_handler, bt_signal_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void send_sig_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_dequeue @ 0010e230 size=1
// signature: undefined skb_dequeue(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_dequeue(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_pull @ 0010e238 size=1
// signature: undefined skb_pull(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_pull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0010e240 size=1
// signature: undefined __wake_up(void)
// callers: [bt_power_vote]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 0010e248 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 0010e250 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010e258 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 0010e260 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010e268 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010e270 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [dt_parse_vreg_info, bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010e278 size=1
// signature: undefined devm_kmalloc(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0010e280 size=1
// signature: undefined devm_clk_get(void)
// callers: [bt_power_populate_dt_pinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010e288 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [btpower_enable_ipa_vreg, dt_parse_vreg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 0010e290 size=1
// signature: undefined regulator_get(void)
// callers: [dt_parse_vreg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0010e298 size=1
// signature: undefined of_get_property(void)
// callers: [dt_parse_vreg_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010e2a0 size=1
// signature: undefined scnprintf(void)
// callers: [extldo_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0010e2a8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [bt_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



