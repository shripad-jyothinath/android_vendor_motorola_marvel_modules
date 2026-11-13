// Decompiled by Ghidra 12.2
// Program: rtc-pm8xxx.ko
// Image base: 00100000

//------------------------------------------------------------
// pm8xxx_rtc_probe @ 00100324 size=592
// signature: undefined pm8xxx_rtc_probe(void)
// callers: []
//------------------------------------------------------------

ulong pm8xxx_rtc_probe(long param_1)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  ulong *puVar4;
  undefined8 uVar5;
  ulong uVar6;
  long lVar7;
  ulong uVar8;
  ulong uVar9;
  ulong uVar10;
  undefined4 *puVar11;
  uint local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = of_match_node(&pm8xxx_id_table,*(undefined8 *)(param_1 + 0x2f8));
  if (lVar3 != 0) {
    uVar9 = param_1 + 0x10;
    puVar4 = (ulong *)devm_kmalloc(uVar9,0x30,0xdc0);
    if (puVar4 == (ulong *)0x0) {
      uVar10 = 0xfffffff4;
      goto LAB_00100500;
    }
    uVar5 = *(undefined8 *)(param_1 + 0x70);
    *(undefined4 *)(puVar4 + 5) = 0;
    uVar6 = dev_get_regmap(uVar5,0);
    puVar4[1] = uVar6;
    if (uVar6 == 0) {
      _dev_err(uVar9,"Parent regmap unavailable.\n");
    }
    else {
      iVar1 = platform_get_irq(param_1,0);
      *(int *)((long)puVar4 + 0x14) = iVar1;
      if (-1 < iVar1) {
        lVar7 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"allow-set-time",0);
        local_4c = 0;
        *(bool *)(puVar4 + 2) = lVar7 != 0;
        puVar11 = *(undefined4 **)(lVar3 + 0xc0);
        puVar4[3] = (ulong)puVar11;
        puVar4[4] = uVar9;
        uVar8 = regmap_read(uVar6,*puVar11,&local_4c);
        uVar10 = uVar8 & 0xffffffff;
        if ((int)uVar8 == 0) {
          if ((local_4c >> 7 & 1) == 0) {
            local_4c = local_4c | 0x80;
            uVar6 = regmap_write(uVar6,*puVar11);
            uVar10 = uVar6 & 0xffffffff;
            if ((int)uVar6 != 0) goto LAB_00100500;
          }
          *(ulong **)(param_1 + 0xa8) = puVar4;
          device_set_wakeup_capable(uVar9,1);
          device_wakeup_enable(uVar9);
          uVar10 = devm_rtc_allocate_device(uVar9);
          *puVar4 = uVar10;
          if (uVar10 < 0xfffffffffffff001) {
            *(undefined1 **)(uVar10 + 0x3a0) = pm8xxx_rtc_ops;
            *(undefined8 *)(*puVar4 + 0x5c8) = 0xffffffff;
            uVar2 = devm_request_any_context_irq
                              (uVar9,*(undefined4 *)((long)puVar4 + 0x14),pm8xxx_alarm_trigger,1,
                               "pm8xxx_rtc_alarm",puVar4);
            if ((int)uVar2 < 0) {
              uVar10 = (ulong)uVar2;
              _dev_err(uVar9,"Request IRQ failed (%d)\n",uVar10);
            }
            else {
              uVar6 = __devm_rtc_register_device(&__this_module,*puVar4);
              uVar10 = uVar6 & 0xffffffff;
              if ((int)uVar6 == 0) {
                lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),
                                         "qcom,disable-alarm-wakeup",0);
                if (lVar3 == 0) {
                  uVar9 = dev_pm_set_wake_irq(uVar9,*(undefined4 *)((long)puVar4 + 0x14));
                  uVar10 = uVar9 & 0xffffffff;
                  if ((int)uVar9 != 0) goto LAB_00100500;
                }
                lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,support-deepsleep",0
                                        );
                if (lVar3 == 0) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = 0;
                  *(undefined1 *)((long)puVar4 + 0x2c) = 1;
                }
              }
            }
          }
        }
        goto LAB_00100500;
      }
    }
  }
  uVar10 = 0xfffffffa;
LAB_00100500:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar10 & 0xffffffff;
}



//------------------------------------------------------------
// pm8xxx_remove @ 00100578 size=36
// signature: undefined pm8xxx_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8xxx_remove(long param_1)

{
  dev_pm_clear_wake_irq(param_1 + 0x10);
  return 0;
}



//------------------------------------------------------------
// pm8xxx_alarm_trigger @ 001005a0 size=304
// signature: undefined pm8xxx_alarm_trigger(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8xxx_alarm_trigger(undefined8 param_1,undefined8 *param_2)

{
  undefined8 *puVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  uint local_3c;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  lVar5 = param_2[3];
  local_3c = 0;
  rtc_update_irq(*param_2,1,0xa0);
  puVar1 = param_2 + 5;
  _raw_spin_lock(puVar1);
  iVar2 = regmap_read(param_2[1],*(undefined4 *)(lVar5 + 0xc),&local_3c);
  if (iVar2 == 0) {
    local_3c = local_3c & (*(uint *)(lVar5 + 0x18) ^ 0xffffffff);
    iVar2 = regmap_write(param_2[1],*(undefined4 *)(lVar5 + 0xc));
    _raw_spin_unlock(puVar1);
    if (iVar2 == 0) {
      iVar2 = regmap_read(param_2[1],*(undefined4 *)(lVar5 + 0x10),&local_3c);
      if (iVar2 == 0) {
        local_3c = local_3c | 1;
        iVar2 = regmap_write(param_2[1],*(undefined4 *)(lVar5 + 0x10));
        if (iVar2 == 0) goto LAB_00100668;
        uVar3 = param_2[4];
        pcVar4 = "Write to RTC Alarm control2 register failed\n";
      }
      else {
        uVar3 = param_2[4];
        pcVar4 = "RTC Alarm control2 register read failed\n";
      }
    }
    else {
      uVar3 = param_2[4];
      pcVar4 = "Write to alarm control register failed\n";
    }
    _dev_err(uVar3,pcVar4);
  }
  else {
    _raw_spin_unlock(puVar1);
  }
LAB_00100668:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// pm8xxx_rtc_read_time @ 001006d4 size=272
// signature: undefined pm8xxx_rtc_read_time(void)
// callers: []
//------------------------------------------------------------

int pm8xxx_rtc_read_time(long param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  lVar3 = *(long *)(lVar2 + 0x18);
  iVar1 = regmap_bulk_read(*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar3 + 8),(long)&local_50 + 4
                           ,4);
  if ((iVar1 == 0) &&
     (iVar1 = regmap_read(*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar3 + 8),&local_50),
     -1 < iVar1)) {
    if ((uint)local_50 < local_50._4_1_) {
      iVar1 = regmap_bulk_read(*(undefined8 *)(lVar2 + 8),*(undefined4 *)(lVar3 + 8),
                               (long)&local_50 + 4,4);
      if (iVar1 != 0) goto LAB_001007c8;
    }
    rtc_time64_to_tm(local_50._4_1_,param_2);
    iVar1 = 0;
  }
  else {
LAB_001007c8:
    _dev_err(param_1,"RTC read data register failed\n");
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8xxx_rtc_set_time @ 001007e8 size=504
// signature: undefined pm8xxx_rtc_set_time(void)
// callers: []
//------------------------------------------------------------

int pm8xxx_rtc_set_time(long param_1,undefined8 param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  char *pcVar5;
  long lVar6;
  undefined4 *puVar7;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_64 = 0;
  local_60 = 0;
  if (*(char *)(lVar6 + 0x10) == '\0') {
    iVar3 = -0x13;
    goto LAB_001009a4;
  }
  puVar7 = *(undefined4 **)(lVar6 + 0x18);
  local_5c = rtc_tm_to_time64(param_2);
  uVar4 = _raw_spin_lock_irqsave(lVar6 + 0x28);
  iVar3 = regmap_read(*(undefined8 *)(lVar6 + 8),puVar7[3],&local_60);
  if (iVar3 == 0) {
    uVar1 = puVar7[6] & local_60;
    if (uVar1 == 0) {
LAB_00100888:
      iVar3 = regmap_read(*(undefined8 *)(lVar6 + 8),*puVar7,&local_64);
      uVar2 = local_64;
      if (iVar3 != 0) goto LAB_00100998;
      if ((local_64 >> 7 & 1) == 0) {
LAB_001008c0:
        iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),puVar7[1],0);
        if ((iVar3 == 0) &&
           (iVar3 = regmap_bulk_write(*(undefined8 *)(lVar6 + 8),puVar7[1] + 1,(ulong)&local_5c | 1,
                                      3), iVar3 == 0)) {
          iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),puVar7[1],(undefined1)local_5c);
          if (iVar3 == 0) {
            if ((uVar2 >> 7 & 1) != 0) {
              local_64 = local_64 | 0x80;
              iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),*puVar7);
              if (iVar3 != 0) goto LAB_00100984;
            }
            if (uVar1 == 0) {
              iVar3 = 0;
            }
            else {
              local_60 = local_60 | puVar7[6];
              iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),puVar7[3]);
              if (iVar3 != 0) goto LAB_00100978;
            }
            goto LAB_00100998;
          }
        }
        pcVar5 = "Write to RTC write data register failed\n";
      }
      else {
        local_64 = local_64 & 0xffffff7f;
        iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),*puVar7);
        if (iVar3 == 0) goto LAB_001008c0;
LAB_00100984:
        pcVar5 = "Write to RTC control register failed\n";
      }
    }
    else {
      local_60 = local_60 & (puVar7[6] ^ 0xffffffff);
      iVar3 = regmap_write(*(undefined8 *)(lVar6 + 8),puVar7[3]);
      if (iVar3 == 0) goto LAB_00100888;
LAB_00100978:
      pcVar5 = "Write to RTC Alarm control register failed\n";
    }
    _dev_err(param_1,pcVar5);
  }
LAB_00100998:
  _raw_spin_unlock_irqrestore(lVar6 + 0x28,uVar4);
LAB_001009a4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// pm8xxx_rtc_read_alarm @ 001009e4 size=224
// signature: undefined pm8xxx_rtc_read_alarm(void)
// callers: []
//------------------------------------------------------------

int pm8xxx_rtc_read_alarm(long param_1,byte *param_2)

{
  int iVar1;
  char *pcVar2;
  long lVar3;
  long lVar4;
  undefined8 local_50;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  lVar4 = *(long *)(lVar3 + 0x18);
  iVar1 = regmap_bulk_read(*(undefined8 *)(lVar3 + 8),*(undefined4 *)(lVar4 + 0x14),
                           (long)&local_50 + 4,4);
  if (iVar1 == 0) {
    rtc_time64_to_tm(local_50._4_4_,param_2 + 4);
    iVar1 = regmap_read(*(undefined8 *)(lVar3 + 8),*(undefined4 *)(lVar4 + 0xc),&local_50);
    if (iVar1 == 0) {
      *param_2 = (byte)((uint)local_50 >> 7) & 1;
      goto LAB_00100a68;
    }
    pcVar2 = "Read from RTC alarm control register failed\n";
  }
  else {
    pcVar2 = "RTC alarm time read failed\n";
  }
  _dev_err(param_1,pcVar2);
LAB_00100a68:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8xxx_rtc_set_alarm @ 00100ac8 size=304
// signature: undefined pm8xxx_rtc_set_alarm(void)
// callers: []
//------------------------------------------------------------

int pm8xxx_rtc_set_alarm(long param_1,char *param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  long lVar4;
  undefined4 local_5c;
  long local_58;
  
  lVar3 = sp_el0;
  local_58 = *(long *)(lVar3 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  lVar3 = *(long *)(lVar4 + 0x18);
  local_5c = rtc_tm_to_time64(param_2 + 4);
  iVar1 = regmap_update_bits_base
                    (*(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar3 + 0xc),
                     *(undefined4 *)(lVar3 + 0x18),0,0,0,0);
  if (iVar1 == 0) {
    uVar2 = _raw_spin_lock_irqsave(lVar4 + 0x28);
    iVar1 = regmap_bulk_write(*(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar3 + 0x14),&local_5c,4);
    if (iVar1 == 0) {
      if (*param_2 == '\0') {
        iVar1 = 0;
      }
      else {
        iVar1 = regmap_update_bits_base
                          (*(undefined8 *)(lVar4 + 8),*(undefined4 *)(lVar3 + 0xc),
                           *(undefined4 *)(lVar3 + 0x18),*(undefined4 *)(lVar3 + 0x18),0,0,0);
      }
    }
    else {
      _dev_err(param_1,"Write to RTC ALARM register failed\n");
    }
    _raw_spin_unlock_irqrestore(lVar4 + 0x28,uVar2);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// pm8xxx_rtc_alarm_irq_enable @ 00100bfc size=300
// signature: undefined pm8xxx_rtc_alarm_irq_enable(void)
// callers: []
//------------------------------------------------------------

int pm8xxx_rtc_alarm_irq_enable(long param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined8 uVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_60 = 0;
  lVar6 = *(long *)(lVar5 + 0x18);
  uVar3 = _raw_spin_lock_irqsave(lVar5 + 0x28);
  iVar2 = regmap_read(*(undefined8 *)(lVar5 + 8),*(undefined4 *)(lVar6 + 0xc),&local_60);
  if (iVar2 != 0) goto LAB_00100cbc;
  if (param_2 == 0) {
    uVar1 = (uint)local_60 & (*(uint *)(lVar6 + 0x18) ^ 0xffffffff);
  }
  else {
    uVar1 = (uint)local_60 | *(uint *)(lVar6 + 0x18);
  }
  local_60 = CONCAT44(local_60._4_4_,uVar1);
  iVar2 = regmap_write(*(undefined8 *)(lVar5 + 8),*(undefined4 *)(lVar6 + 0xc));
  if (iVar2 == 0) {
    if (param_2 != 0) {
      iVar2 = 0;
      goto LAB_00100cbc;
    }
    iVar2 = regmap_bulk_write(*(undefined8 *)(lVar5 + 8),*(undefined4 *)(lVar6 + 0x14),
                              (long)&local_60 + 4,4);
    if (iVar2 == 0) goto LAB_00100cbc;
    pcVar4 = "Clear RTC ALARM register failed\n";
  }
  else {
    pcVar4 = "Write to RTC control register failed\n";
  }
  _dev_err(param_1,pcVar4);
LAB_00100cbc:
  _raw_spin_unlock_irqrestore(lVar5 + 0x28,uVar3);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// pm8xxx_rtc_suspend @ 00100d2c size=68
// signature: undefined pm8xxx_rtc_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pm8xxx_rtc_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar1 + 0x2c) != '\0' && _pm_suspend_target_state == 3) {
    devm_free_irq(*(undefined8 *)(lVar1 + 0x20),*(undefined4 *)(lVar1 + 0x14));
  }
  return 0;
}



//------------------------------------------------------------
// pm8xxx_rtc_resume @ 00100d74 size=64
// signature: undefined pm8xxx_rtc_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 pm8xxx_rtc_resume(long param_1)

{
  undefined8 uVar1;
  
  if (*(char *)(*(long *)(param_1 + 0x98) + 0x2c) == '\0' || _pm_suspend_target_state != 3) {
    uVar1 = 0;
  }
  else {
    uVar1 = pm8xxx_rtc_restore();
  }
  return uVar1;
}



//------------------------------------------------------------
// pm8xxx_rtc_freeze @ 00100db8 size=44
// signature: undefined pm8xxx_rtc_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 pm8xxx_rtc_freeze(long param_1)

{
  devm_free_irq(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x20),
                *(undefined4 *)(*(long *)(param_1 + 0x98) + 0x14));
  return 0;
}



//------------------------------------------------------------
// pm8xxx_rtc_restore @ 00100de8 size=232
// signature: undefined pm8xxx_rtc_restore(void)
// callers: [pm8xxx_rtc_resume]
//------------------------------------------------------------

int pm8xxx_rtc_restore(long param_1)

{
  int iVar1;
  long lVar2;
  undefined4 *puVar3;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  iVar1 = devm_request_any_context_irq
                    (*(undefined8 *)(lVar2 + 0x20),*(undefined4 *)(lVar2 + 0x14),
                     pm8xxx_alarm_trigger,1,"pm8xxx_rtc_alarm",lVar2);
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(lVar2 + 0x20),"Request IRQ failed (%d)\n",iVar1);
  }
  else {
    puVar3 = *(undefined4 **)(lVar2 + 0x18);
    local_3c = 0;
    iVar1 = regmap_read(*(undefined8 *)(lVar2 + 8),*puVar3,&local_3c);
    if (iVar1 == 0) {
      if ((local_3c >> 7 & 1) == 0) {
        local_3c = local_3c | 0x80;
        iVar1 = regmap_write(*(undefined8 *)(lVar2 + 8),*puVar3);
        if (iVar1 != 0) goto LAB_00100e80;
      }
      iVar1 = 0;
    }
  }
LAB_00100e80:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 00100ed4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&pm8xxx_rtc_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100f04 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&pm8xxx_rtc_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00103000 size=1
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
// platform_driver_unregister @ 00103008 size=1
// signature: undefined platform_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_match_node @ 00103010 size=1
// signature: undefined of_match_node(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_match_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_get_regmap @ 00103020 size=1
// signature: undefined dev_get_regmap(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00103028 size=1
// signature: undefined platform_get_irq(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103030 size=1
// signature: undefined of_find_property(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 00103038 size=1
// signature: undefined regmap_read(void)
// callers: [pm8xxx_rtc_read_time, pm8xxx_alarm_trigger, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_restore, pm8xxx_rtc_probe, pm8xxx_rtc_read_alarm, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_write @ 00103040 size=1
// signature: undefined regmap_write(void)
// callers: [pm8xxx_alarm_trigger, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_restore, pm8xxx_rtc_probe, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_set_wakeup_capable @ 00103048 size=1
// signature: undefined device_set_wakeup_capable(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_set_wakeup_capable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_wakeup_enable @ 00103050 size=1
// signature: undefined device_wakeup_enable(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_wakeup_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_rtc_allocate_device @ 00103058 size=1
// signature: undefined devm_rtc_allocate_device(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_rtc_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_any_context_irq @ 00103060 size=1
// signature: undefined devm_request_any_context_irq(void)
// callers: [pm8xxx_rtc_restore, pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_any_context_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __devm_rtc_register_device @ 00103068 size=1
// signature: undefined __devm_rtc_register_device(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __devm_rtc_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103070 size=1
// signature: undefined _dev_err(void)
// callers: [pm8xxx_rtc_read_time, pm8xxx_rtc_set_alarm, pm8xxx_alarm_trigger, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_restore, pm8xxx_rtc_probe, pm8xxx_rtc_read_alarm, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_set_wake_irq @ 00103078 size=1
// signature: undefined dev_pm_set_wake_irq(void)
// callers: [pm8xxx_rtc_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_set_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103080 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [pm8xxx_rtc_read_time, pm8xxx_rtc_set_alarm, pm8xxx_alarm_trigger, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_restore, pm8xxx_rtc_probe, pm8xxx_rtc_read_alarm, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_clear_wake_irq @ 00103088 size=1
// signature: undefined dev_pm_clear_wake_irq(void)
// callers: [pm8xxx_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_clear_wake_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtc_update_irq @ 00103090 size=1
// signature: undefined rtc_update_irq(void)
// callers: [pm8xxx_alarm_trigger]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtc_update_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00103098 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [pm8xxx_alarm_trigger]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 001030a0 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [pm8xxx_alarm_trigger]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_read @ 001030a8 size=1
// signature: undefined regmap_bulk_read(void)
// callers: [pm8xxx_rtc_read_time, pm8xxx_rtc_read_alarm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtc_time64_to_tm @ 001030b0 size=1
// signature: undefined rtc_time64_to_tm(void)
// callers: [pm8xxx_rtc_read_time, pm8xxx_rtc_read_alarm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtc_time64_to_tm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rtc_tm_to_time64 @ 001030b8 size=1
// signature: undefined rtc_tm_to_time64(void)
// callers: [pm8xxx_rtc_set_alarm, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rtc_tm_to_time64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 001030c0 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [pm8xxx_rtc_set_alarm, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 001030c8 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [pm8xxx_rtc_set_alarm, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001030d0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [pm8xxx_rtc_set_alarm, pm8xxx_rtc_alarm_irq_enable, pm8xxx_rtc_set_time]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 001030d8 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [pm8xxx_rtc_set_alarm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 001030e8 size=1
// signature: undefined devm_free_irq(void)
// callers: [pm8xxx_rtc_freeze, pm8xxx_rtc_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



