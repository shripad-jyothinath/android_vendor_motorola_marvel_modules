// Decompiled by Ghidra 12.2
// Program: sx937x_sar.ko
// Image base: 00100000

//------------------------------------------------------------
// get_dsi_display_name @ 001008cc size=288
// signature: undefined get_dsi_display_name(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

int get_dsi_display_name(void)

{
  ulong uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  char *pcVar5;
  char *pcVar6;
  ulong __n;
  undefined8 in_x6;
  undefined8 in_x7;
  long lVar7;
  code *pcVar8;
  undefined1 *puVar9;
  char *local_40;
  undefined8 local_38;
  
  lVar7 = (long)register0x00000008 + -0x30;
  lVar4 = sp_el0;
  iVar3 = 0x1069d0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = (char *)0x0;
  if (get_dsi_display_name_display == '\0') {
    lVar4 = of_find_node_opts_by_path("/chosen",0);
    if ((lVar4 == 0) || (iVar2 = of_property_read_string(lVar4,"bootargs",&local_40), iVar2 != 0)) {
      iVar3 = 0;
    }
    else {
      pcVar5 = strstr(local_40,"msm_drm.dsi_display0=");
      if (pcVar5 != (char *)0x0) {
        pcVar6 = strchr(pcVar5,0x20);
        pcVar5 = strchr(pcVar5,0x3d);
        iVar3 = 0x1069d0;
        if ((pcVar5 != (char *)0x0) &&
           (uVar1 = (long)pcVar6 - (long)pcVar5, pcVar5 <= pcVar6 && uVar1 != 0)) {
          pcVar5 = pcVar5 + 1;
          __n = strlen(pcVar5);
          if (uVar1 <= __n) {
            __n = uVar1 - 1;
          }
          if (0x3f < __n) {
            fortify_panic("strlcpy");
            lVar4 = func_0x002eba58();
            pcVar8 = sx93XX_IRQ_init;
            puVar9 = &get_dsi_display_name_display;
            if ((lVar4 != 0) && (*(long *)(lVar4 + 0x10) != 0)) {
              *(undefined8 *)(lVar4 + 0x98) = 0xfffffffe0;
              *(undefined4 *)(lVar4 + 0x80) = 0;
              *(undefined4 *)(lVar4 + 0x74) = 0;
              *(long *)(lVar4 + 0xa0) = lVar4 + 0xa0;
              *(long *)(lVar4 + 0xa8) = lVar4 + 0xa0;
              *(code **)(lVar4 + 0xb0) = sx93XX_worker_func;
              init_timer_key(lVar4 + 200,&delayed_work_timer_fn,0x200000,0,0);
              *(undefined1 *)(lVar4 + 0x7c) = 0;
              iVar3 = request_threaded_irq
                                (*(undefined4 *)(lVar4 + 0x78),sx93XX_irq,0,2,
                                 **(undefined8 **)(*(long *)(lVar4 + 8) + 0x88),lVar4,in_x6,in_x7,
                                 lVar7,pcVar8,pcVar5,puVar9);
              if (iVar3 != 0) {
                _printk(&DAT_00104edf,"sx93XX_IRQ_init",0x85f,*(undefined4 *)(lVar4 + 0x78));
                return iVar3;
              }
              _printk(&DAT_00105a79,"sx93XX_IRQ_init",0x862,*(undefined4 *)(lVar4 + 0x78));
            }
            return -0xc;
          }
          memcpy(&get_dsi_display_name_display,pcVar5,__n);
          (&get_dsi_display_name_display)[__n] = 0;
        }
      }
    }
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// sx93XX_IRQ_init @ 001009f0 size=236
// signature: undefined sx93XX_IRQ_init(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

int sx93XX_IRQ_init(long param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(long *)(param_1 + 0x10) != 0)) {
    *(undefined8 *)(param_1 + 0x98) = 0xfffffffe0;
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(long *)(param_1 + 0xa0) = param_1 + 0xa0;
    *(long *)(param_1 + 0xa8) = param_1 + 0xa0;
    *(code **)(param_1 + 0xb0) = sx93XX_worker_func;
    init_timer_key(param_1 + 200,&delayed_work_timer_fn,0x200000,0,0);
    *(undefined1 *)(param_1 + 0x7c) = 0;
    iVar1 = request_threaded_irq
                      (*(undefined4 *)(param_1 + 0x78),sx93XX_irq,0,2,
                       **(undefined8 **)(*(long *)(param_1 + 8) + 0x88),param_1);
    if (iVar1 != 0) {
      _printk(&DAT_00104edf,"sx93XX_IRQ_init",0x85f,*(undefined4 *)(param_1 + 0x78));
      return iVar1;
    }
    _printk(&DAT_00105a79,"sx93XX_IRQ_init",0x862,*(undefined4 *)(param_1 + 0x78));
  }
  return -0xc;
}



//------------------------------------------------------------
// sx93XX_worker_func @ 00100ae0 size=604
// signature: undefined sx93XX_worker_func(void)
// callers: []
//------------------------------------------------------------

void sx93XX_worker_func(long param_1)

{
  bool bVar1;
  long lVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  byte bVar8;
  
  if (param_1 == 0) {
    puVar6 = &DAT_001052ec;
    uVar7 = 0x84b;
LAB_00100cec:
    _printk(puVar6,"sx93XX_worker_func",uVar7);
    return;
  }
  lVar2 = param_1 + -0x98;
  if (lVar2 == 0) {
    puVar6 = &DAT_00105426;
    uVar7 = 0x82b;
    goto LAB_00100cec;
  }
  if (*(char *)(param_1 + -0x14) == '\0') {
LAB_00100b0c:
    bVar8 = 0;
  }
  else {
    pcVar3 = *(code **)(param_1 + -0x70);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100d14);
        (*pcVar3)();
      }
      iVar5 = (*pcVar3)();
      if (iVar5 == 0) goto LAB_00100b0c;
    }
    bVar8 = 1;
  }
  if (*(int *)(*(code **)(param_1 + -0x78) + -4) != -0x6bf853e5) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100b30);
    (*pcVar3)();
  }
  uVar4 = (**(code **)(param_1 + -0x78))(lVar2);
  if (((uVar4 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x68), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100b60);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 1 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x60), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100b8c);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 2 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x58), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100bb8);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 3 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x50), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100be4);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 4 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x48), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c10);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 5 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x40), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c3c);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 6 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x38), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c68);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  if (((uVar4 >> 7 & 1) != 0) && (pcVar3 = *(code **)(param_1 + -0x30), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != -0x1ccdc4e9) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100c94);
      (*pcVar3)();
    }
    (*pcVar3)(lVar2);
  }
  bVar1 = (bool)(bVar8 ^ 1);
  if (*(char *)(param_1 + -0x14) == '\0') {
    bVar1 = true;
  }
  if (bVar1) {
    return;
  }
  uVar7 = __msecs_to_jiffies(*(undefined4 *)(param_1 + -0x10));
  sx93XX_schedule_work(lVar2,uVar7);
  return;
}



//------------------------------------------------------------
// sx93XX_irq @ 00100d40 size=192
// signature: undefined sx93XX_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sx93XX_irq(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  if (param_2 == 0) {
    _printk(&DAT_00105804,"sx93XX_irq",0x81a);
  }
  else {
    pcVar3 = *(code **)(param_2 + 0x28);
    if (pcVar3 != (code *)0x0) {
      if (*(int *)(pcVar3 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100d7c);
        (*pcVar3)();
      }
      iVar1 = (*pcVar3)();
      if (iVar1 == 0) {
        return 1;
      }
    }
    uVar2 = _raw_spin_lock_irqsave(param_2 + 0x74);
    cancel_delayed_work(param_2 + 0x98);
    queue_delayed_work_on(0x20,_system_wq,param_2 + 0x98,0);
    _raw_spin_unlock_irqrestore(param_2 + 0x74,uVar2);
    *(undefined4 *)(param_2 + 0x80) = 1;
  }
  return 1;
}



//------------------------------------------------------------
// capsense_reset_store @ 00100e04 size=192
// signature: undefined capsense_reset_store(void)
// callers: []
//------------------------------------------------------------

long capsense_reset_store(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  sx937x_i2c_read_16bit(global_sx937x,0x8024,&local_3c);
  if (param_4 == 0) {
    param_4 = -0x16;
  }
  else {
    iVar2 = strncmp(param_3,"reset",5);
    if (((iVar2 == 0) || (*param_3 == '1')) && ((char)local_3c != '\0')) {
      sx937x_i2c_write_16bit(global_sx937x,0x4280,0xe);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sx937x_i2c_read_16bit @ 00100ec4 size=600
// signature: undefined sx937x_i2c_read_16bit(void)
// callers: [manual_offset_calibration_show, initialize, ps_notify_callback_work, capsensor_set_enable, read_rawData, sx937x_register_read_store, capsense_reset_store, reg_show, sx937x_reinitialize, touchProcess, sx937x_Hardware_Check, read_regStat, capsense_raw_data_show, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

int sx937x_i2c_read_16bit(long *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  uint local_60;
  ushort local_5c [2];
  undefined8 local_58;
  ushort *local_50;
  undefined8 local_48;
  undefined1 *local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_50 = (ushort *)0x0;
  local_48 = 0;
  local_58 = 0;
  local_60 = 0;
  if ((param_1 == (long *)0x0) || (lVar3 = *param_1, lVar3 == 0)) {
    iVar2 = -0xc;
  }
  else {
    local_50 = local_5c;
    local_5c[0] = (ushort)(param_2 >> 8) & 0xff | (ushort)((param_2 & 0xff00ff) << 8);
    local_58 = CONCAT62(0x20000,*(undefined2 *)(lVar3 + 2));
    local_48 = (ulong)CONCAT42(0x40001,*(undefined2 *)(lVar3 + 2));
    local_40 = (undefined1 *)&local_60;
    iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
    if (iVar2 < 1) {
      param_2 = param_2 & 0xffff;
      _printk(&DAT_001051de,"sx937x_i2c_read_16bit",0xbf,param_2);
      msleep(10);
      iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
      if (iVar2 < 1) {
        _printk(&DAT_001051de,"sx937x_i2c_read_16bit",0xbf,param_2);
        msleep(10);
        iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
        if (iVar2 < 1) {
          _printk(&DAT_001051de,"sx937x_i2c_read_16bit",0xbf,param_2);
          msleep(10);
          iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
          if (iVar2 < 1) {
            _printk(&DAT_001051de,"sx937x_i2c_read_16bit",0xbf,param_2);
            msleep(10);
            iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
            if (iVar2 < 1) {
              _printk(&DAT_001051de,"sx937x_i2c_read_16bit",0xbf,param_2);
              msleep(10);
              iVar2 = i2c_transfer(*(undefined8 *)(lVar3 + 0x18),&local_58,2);
              if (iVar2 < 1) {
                _printk(&DAT_0010538d,"sx937x_i2c_read_16bit",0xc4,param_2,iVar2,5);
                goto LAB_00100f78;
              }
            }
          }
        }
      }
    }
    uVar1 = (local_60 & 0xff00ff00) >> 8 | (local_60 & 0xff00ff) << 8;
    *param_3 = uVar1 >> 0x10 | uVar1 << 0x10;
  }
LAB_00100f78:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// sx937x_i2c_write_16bit @ 0010111c size=564
// signature: undefined sx937x_i2c_write_16bit(void)
// callers: [reg_store, sx937x_reinitialize, initialize, ps_notify_callback_work, capsensor_set_enable, sx937x_reg_init, sx937x_suspend, capsense_reset_store, sx937x_register_write_store, manual_offset_calibration_store, sx937x_resume]
//------------------------------------------------------------

int sx937x_i2c_write_16bit(long *param_1,uint param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 local_40;
  undefined1 *local_38;
  undefined1 local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined1 local_2b;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  if ((param_1 == (long *)0x0) || (lVar2 = *param_1, lVar2 == 0)) {
    iVar1 = -0xc;
  }
  else {
    local_2d = (undefined1)((ulong)param_3 >> 0x10);
    local_2c = (undefined1)((ulong)param_3 >> 8);
    local_2b = (undefined1)param_3;
    local_2e = (undefined1)((ulong)param_3 >> 0x18);
    local_30 = (undefined1)(param_2 >> 8);
    local_38 = &local_30;
    local_2f = (undefined1)param_2;
    local_40 = CONCAT62(0x60000,*(undefined2 *)(lVar2 + 2));
    iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
    if (iVar1 < 1) {
      param_2 = param_2 & 0xffff;
      _printk(&DAT_0010433e,"sx937x_i2c_write_16bit",0x86,param_2);
      msleep(10);
      iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
      if (iVar1 < 1) {
        _printk(&DAT_0010433e,"sx937x_i2c_write_16bit",0x86,param_2);
        msleep(10);
        iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
        if (iVar1 < 1) {
          _printk(&DAT_0010433e,"sx937x_i2c_write_16bit",0x86,param_2);
          msleep(10);
          iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
          if (iVar1 < 1) {
            _printk(&DAT_0010433e,"sx937x_i2c_write_16bit",0x86,param_2);
            msleep(10);
            iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
            if (iVar1 < 1) {
              _printk(&DAT_0010433e,"sx937x_i2c_write_16bit",0x86,param_2);
              msleep(10);
              iVar1 = i2c_transfer(*(undefined8 *)(lVar2 + 0x18),&local_40,1);
              if (iVar1 < 1) {
                _printk(&DAT_00104c2a,"sx937x_i2c_write_16bit",0x8c,param_2,iVar1,5);
              }
            }
          }
        }
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// capsense_raw_data_show @ 00101354 size=324
// signature: undefined capsense_raw_data_show(void)
// callers: []
//------------------------------------------------------------

long capsense_raw_data_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int param5;
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int param3;
  char *param0;
  uint local_6c;
  long local_68;
  
  lVar3 = global_sx937x;
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  local_6c = 0;
  param0 = param_3;
  if (global_sx937x != 0) {
    param3 = 0;
    do {
      iVar1 = param3 * 4;
      sx937x_i2c_read_16bit(lVar3,iVar1 + -0x7e10,&local_6c);
      iVar4 = (int)local_6c >> 10;
      sx937x_i2c_read_16bit(lVar3,iVar1 + -0x7df0,&local_6c);
      param5 = (int)local_6c >> 10;
      sx937x_i2c_read_16bit(lVar3,iVar1 + -0x7dd0,&local_6c);
      iVar1 = (int)local_6c >> 10;
      sx937x_i2c_read_16bit(lVar3,param3 * 0xc + -0x7fd4,&local_6c);
      iVar4 = snprintf(param0,0x1000,"PH= %d Useful = %d Average = %d DIFF = %d Offset = %d \n",
                       param3,iVar4,param5,iVar1,local_6c & 0x3fff);
      param3 = param3 + 1;
      param0 = param0 + iVar4;
    } while (param3 != 8);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)param0 - (long)param_3;
}



//------------------------------------------------------------
// sx937x_register_write_store @ 0010149c size=172
// signature: undefined sx937x_register_write_store(void)
// callers: []
//------------------------------------------------------------

undefined8
sx937x_register_write_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  undefined8 local_30;
  long local_28;
  
  uVar2 = global_sx937x;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = sscanf(param_3,"%x,%x",(uint *)((long)&local_30 + 4),(uint *)&local_30);
  if (iVar3 == 2) {
    sx937x_i2c_write_16bit(uVar2,local_30._4_4_,local_30 & 0xffffffff);
  }
  else {
    _printk(&DAT_0010471f,"sx937x_register_write_store",0x220);
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sx937x_register_read_show @ 0010154c size=60
// signature: undefined sx937x_register_read_show(void)
// callers: []
//------------------------------------------------------------

long sx937x_register_read_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"Register(0x%2x) data(0x%4x)\n",sx937x_temp_regist,sx937x_temp_val);
  return (long)iVar1;
}



//------------------------------------------------------------
// sx937x_register_read_store @ 0010158c size=152
// signature: undefined sx937x_register_read_store(void)
// callers: []
//------------------------------------------------------------

undefined8
sx937x_register_read_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = global_sx937x;
  iVar2 = sscanf(param_3,"%x",&sx937x_temp_regist);
  if (iVar2 == 1) {
    sx937x_i2c_read_16bit(uVar1,sx937x_temp_regist,&sx937x_temp_val);
    gpio_to_desc(irq_gpio_num);
    gpiod_get_raw_value();
  }
  else {
    _printk(&DAT_00104ccf,"sx937x_register_read_store",0x23b);
    param_4 = 0xffffffffffffffea;
  }
  return param_4;
}



//------------------------------------------------------------
// sx937x_get_nirq_state @ 00101628 size=48
// signature: undefined sx937x_get_nirq_state(void)
// callers: []
//------------------------------------------------------------

bool sx937x_get_nirq_state(void)

{
  int iVar1;
  
  gpio_to_desc(irq_gpio_num);
  iVar1 = gpiod_get_raw_value();
  return iVar1 == 0;
}



//------------------------------------------------------------
// manual_offset_calibration_show @ 0010165c size=128
// signature: undefined manual_offset_calibration_show(void)
// callers: []
//------------------------------------------------------------

long manual_offset_calibration_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  uint local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  sx937x_i2c_read_16bit(global_sx937x,0x4000,&local_2c);
  iVar2 = sprintf(param_3,"%d\n",(ulong)local_2c);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// manual_offset_calibration_store @ 001016e0 size=172
// signature: undefined manual_offset_calibration_store(void)
// callers: []
//------------------------------------------------------------

undefined8
manual_offset_calibration_store
          (undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  undefined8 uVar2;
  int iVar3;
  long local_30;
  long local_28;
  
  uVar2 = global_sx937x;
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar3 = kstrtoull(param_3,10,&local_30);
  if (iVar3 == 0) {
    if (local_30 != 0) {
      sx937x_i2c_write_16bit(uVar2,0x4280,0xe);
    }
  }
  else {
    _printk(&DAT_001048a6,"manual_offset_calibration_store",0x2c1);
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sx937x_int_state_show @ 00101790 size=56
// signature: undefined sx937x_int_state_show(void)
// callers: []
//------------------------------------------------------------

long sx937x_int_state_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",(ulong)*(uint *)(global_sx937x + 0x80));
  return (long)iVar1;
}



//------------------------------------------------------------
// sx937x_reinitialize_store @ 001017cc size=52
// signature: undefined sx937x_reinitialize_store(void)
// callers: []
//------------------------------------------------------------

undefined8 sx937x_reinitialize_store(void)

{
  undefined8 in_x3;
  
  sx937x_reinitialize(global_sx937x);
  return in_x3;
}



//------------------------------------------------------------
// sx937x_reinitialize @ 00101800 size=1056
// signature: undefined sx937x_reinitialize(void)
// callers: [sx937x_reinitialize_store, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

void sx937x_reinitialize(long param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  long lVar7;
  uint local_40;
  undefined1 auStack_3c [4];
  long local_38;
  
  lVar7 = sp_el0;
  local_38 = *(long *)(lVar7 + 0x638);
  local_40 = 0;
  _printk(&DAT_00104df8,"sx937x_reinitialize",0x8e7);
  if ((((param_1 != 0) && (*(long *)(param_1 + 0x10) != 0)) &&
      (lVar7 = *(long *)(*(long *)(param_1 + 0x10) + 8), lVar7 != 0)) &&
     ((*(char *)(lVar7 + 0x89) != '\0' || (*(char *)(lVar7 + 0x35) != '\0')))) {
    piVar1 = (int *)(param_1 + 0x128);
    iVar6 = *(int *)(param_1 + 0x128);
    do {
      if (iVar6 == 1) goto LAB_00101c04;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar6) goto LAB_00101894;
        cVar4 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = iVar6 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_00101894:
      bVar5 = iVar6 != iVar2;
      iVar6 = iVar2;
    } while (bVar5);
    disable_irq(*(undefined4 *)(param_1 + 0x78));
    iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
    if (iVar6 < 0) {
      _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,1);
      msleep(10);
      iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
      if (iVar6 < 0) {
        _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,2);
        msleep(10);
        iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
        if (iVar6 < 0) {
          _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,3);
          msleep(10);
          iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
          if (iVar6 < 0) {
            _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,4);
            msleep(10);
            iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
            if (iVar6 < 0) {
              _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,5);
              msleep(10);
              iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
              if (iVar6 < 0) {
                _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,6);
                msleep(10);
                iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                if (iVar6 < 0) {
                  _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,7);
                  msleep(10);
                  iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                  if (iVar6 < 0) {
                    _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,8);
                    msleep(10);
                    iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                    if (iVar6 < 0) {
                      _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,9);
                      msleep(10);
                      iVar6 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                      if (iVar6 < 0) {
                        _printk(&DAT_0010441a,"sx937x_reinitialize",0x8f2,10);
                        msleep(10);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    _printk(&DAT_0010475a,"sx937x_reinitialize",0x8f6);
    msleep(100);
    sx937x_reg_init(param_1);
    enable_irq(*(undefined4 *)(param_1 + 0x78));
    sx937x_i2c_read_16bit(param_1,0x4000,auStack_3c);
    sx937x_i2c_read_16bit(param_1,0x8024,&local_40);
    uVar3 = local_40 | 0x7f;
    if (((DAT_00105fe8 != '\0') || (DAT_001060f0 != '\0')) ||
       ((DAT_001061f8 != '\0' ||
        ((((DAT_00106300 != '\0' || (DAT_00106408 != '\0')) || (DAT_00106510 != '\0')) ||
         ((DAT_00106618 != '\0' || (DAT_00106720 != '\0')))))))) {
      sx937x_i2c_write_16bit(param_1,0x8024,uVar3);
    }
    _printk(&DAT_001047c3,"sx937x_reinitialize",0x90d,uVar3);
    sx937x_i2c_write_16bit(param_1,0x4280,0xe);
    *(undefined4 *)(param_1 + 0x128) = 0;
    *(int *)(param_1 + 0x124) = *(int *)(param_1 + 0x124) + 1;
    _printk(&DAT_001047f9,"sx937x_reinitialize",0x910);
  }
LAB_00101c04:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sx937x_reg_init @ 00101c34 size=172
// signature: undefined sx937x_reg_init(void)
// callers: [sx937x_reinitialize]
//------------------------------------------------------------

void sx937x_reg_init(long param_1)

{
  int *piVar1;
  long lVar2;
  long lVar3;
  
  if ((*(long *)(param_1 + 0x10) == 0) ||
     (piVar1 = *(int **)(*(long *)(param_1 + 0x10) + 8), piVar1 == (int *)0x0)) {
    _printk(&DAT_0010547a,"sx937x_reg_init",0x36a);
  }
  else {
    if ((*(char *)(param_1 + 0x71) != '\0') && (0 < *piVar1)) {
      lVar2 = 0;
      lVar3 = 0;
      do {
        sx937x_i2c_write_16bit
                  (param_1,*(undefined4 *)(*(long *)(piVar1 + 6) + lVar2),
                   ((undefined4 *)(*(long *)(piVar1 + 6) + lVar2))[1]);
        lVar3 = lVar3 + 1;
        lVar2 = lVar2 + 8;
      } while (lVar3 < *piVar1);
    }
    sx937x_i2c_write_16bit(param_1,0x4280,0xf);
  }
  return;
}



//------------------------------------------------------------
// read_regStat @ 00101ce4 size=108
// signature: undefined read_regStat(void)
// callers: []
//------------------------------------------------------------

void read_regStat(long param_1)

{
  long lVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = 0;
  uVar2 = 0;
  if (param_1 != 0) {
    iVar3 = sx937x_i2c_read_16bit(param_1,0x4000,&local_1c);
    if (iVar3 < 1) {
      uVar2 = 0;
    }
    else {
      uVar2 = (undefined1)local_1c;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// reg_show @ 00101d54 size=72
// signature: undefined reg_show(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_show(void)

{
  undefined2 *puVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  
  lVar2 = global_sx937x;
  if (*(int *)(global_sx937x + 0x8c) == 0) {
    uVar4 = 0xffffffffffffffff;
  }
  else {
    puVar1 = (undefined2 *)(global_sx937x + 0x90);
    *(undefined4 *)(global_sx937x + 0x8c) = 0;
    iVar3 = sx937x_i2c_read_16bit(lVar2,*puVar1);
    uVar4 = 4;
    if (iVar3 < 0) {
      uVar4 = 0xffffffffffffffff;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// reg_store @ 00101da0 size=156
// signature: undefined reg_store(void)
// callers: []
//------------------------------------------------------------

undefined8 reg_store(undefined8 param_1,undefined8 param_2,ushort *param_3,long param_4)

{
  ushort uVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  undefined8 uVar5;
  
  lVar3 = global_sx937x;
  if (param_4 == 7) {
    if ((char)param_3[3] == '\0') {
      uVar2 = (*(uint *)(param_3 + 1) & 0xff00ff00) >> 8 | (*(uint *)(param_3 + 1) & 0xff00ff) << 8;
      iVar4 = sx937x_i2c_write_16bit
                        (global_sx937x,*param_3 >> 8 | *param_3 << 8,uVar2 >> 0x10 | uVar2 << 0x10);
      if (iVar4 < 0) goto LAB_00101e34;
    }
    else if ((char)param_3[3] == '\x01') {
      uVar1 = *param_3;
      *(undefined4 *)(global_sx937x + 0x8c) = 1;
      *(ushort *)(lVar3 + 0x90) = uVar1 >> 8 | uVar1 << 8;
    }
    uVar5 = 7;
  }
  else {
    _printk(&DAT_00105881,"reg_store",0x28f,"reg_store",param_4);
LAB_00101e34:
    uVar5 = 0xffffffffffffffff;
  }
  return uVar5;
}



//------------------------------------------------------------
// sx937x_probe @ 00101e40 size=3392
// signature: undefined sx937x_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int sx937x_probe(long param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  long *plVar5;
  undefined *puVar6;
  long *plVar7;
  uint *puVar8;
  long lVar9;
  char *pcVar10;
  char *pcVar11;
  ulong uVar12;
  undefined8 *puVar13;
  undefined8 uVar14;
  code *pcVar15;
  long lVar16;
  uint *puVar17;
  long lVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  char *local_80;
  char *local_78;
  int local_70 [2];
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar16 = *(long *)(param_1 + 0x80);
  _printk(&DAT_001049f8,"sx937x_probe",0x633);
  pcVar15 = *(code **)(*(long *)(lVar16 + -0x60) + 0x20);
  if (*(int *)(pcVar15 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
    pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x101eb8);
    (*pcVar15)();
  }
  uVar2 = (*pcVar15)(lVar16 + -0x70);
  if ((uVar2 >> 0x15 & 1) == 0) {
    _printk(&DAT_001054b7,"sx937x_probe",0x637);
    iVar3 = -5;
    goto LAB_00101f4c;
  }
  lVar16 = param_1 + 0x20;
  plVar5 = (long *)devm_kmalloc(lVar16,0x1c0,0xdc0);
  if (plVar5 == (long *)0x0) {
    puVar6 = &DAT_00104b47;
    uVar14 = 0x63f;
  }
  else {
    *(long **)(param_1 + 0xb8) = plVar5;
    *plVar5 = param_1;
    plVar5[1] = lVar16;
    plVar7 = (long *)devm_kmalloc(lVar16,0x10,0xdc0);
    if (plVar7 != (long *)0x0) {
      *(undefined4 *)(plVar7 + 1) = 8;
      *plVar7 = (long)&psmtcButtons;
      puVar8 = (uint *)devm_kmalloc(lVar16,0xb0,0xdc0);
      if (puVar8 == (uint *)0x0) {
        _printk(&DAT_00104942,"sx937x_probe",0x657);
        iVar3 = -0x16;
        goto LAB_00101f4c;
      }
      lVar18 = *(long *)(param_1 + 0x308);
      *(uint **)(param_1 + 0xb0) = puVar8;
      *(long **)(puVar8 + 0x24) = plVar7;
      *(code **)(puVar8 + 0x26) = sx937x_get_nirq_state;
      local_70[1] = 0;
      local_70[0] = 0;
      local_80 = "Semtech,reg-init";
      local_78 = (char *)0x0;
      if (lVar18 != 0) {
        puVar17 = puVar8 + 0xe;
        iVar3 = of_property_read_variable_u32_array(lVar18,"Semtech,power-supply-type",puVar17,1,0);
        if (iVar3 < 0) {
          *puVar17 = 0;
          _printk(&DAT_00105ae4,"sx937x_parse_dt",0x456);
        }
        uVar2 = *puVar17;
        if (1 < uVar2) {
          if (uVar2 == 2) {
            uVar2 = of_get_named_gpio_flags(lVar18,"Semtech,eldo-gpio",0,local_70 + 1);
            puVar8[0xc] = uVar2;
            puVar6 = &DAT_00104e79;
            uVar14 = 0x469;
          }
          else {
            puVar6 = &DAT_00104bde;
            uVar14 = 0x46c;
          }
          _printk(puVar6,"sx937x_parse_dt",uVar14,uVar2);
        }
        irq_gpio_num = of_get_named_gpio_flags(lVar18,"Semtech,nirq-gpio",0,local_70 + 1);
        puVar8[8] = irq_gpio_num;
        if ((int)irq_gpio_num < 0) {
          _printk(&DAT_00104467,"sx937x_parse_dt",0x478);
        }
        else {
          puVar17 = puVar8 + 1;
          *puVar17 = 0;
          of_property_read_variable_u32_array(lVar18,"Semtech,button-flag",puVar17,1,0);
          _printk(&DAT_00105b64,"sx937x_parse_dt",0x47e,*puVar17);
          puVar19 = puVar8 + 0xb;
          *puVar19 = 0xffffffff;
          puVar20 = puVar8 + 9;
          puVar20[0] = 0xffffffff;
          puVar20[1] = 0xffffffff;
          iVar3 = of_property_read_variable_u32_array(lVar18,"Semtech,ref-phases-a",puVar20,1,0);
          if (iVar3 < 0) {
            puVar6 = &DAT_001044d7;
            uVar14 = 0x485;
          }
          else {
            puVar21 = puVar8 + 10;
            iVar3 = of_property_read_variable_u32_array(lVar18,"Semtech,ref-phases-b",puVar21,1,0);
            if (iVar3 < 0) {
              puVar6 = &DAT_00104a26;
              uVar14 = 0x48a;
            }
            else {
              iVar3 = of_property_read_variable_u32_array(lVar18,"Semtech,ref-phases-c",puVar19,1,0)
              ;
              if (-1 < iVar3) {
                if (*puVar20 == 0xff) {
                  *puVar20 = 0xffffffff;
                }
                if (*puVar21 == 0xff) {
                  *puVar21 = 0xffffffff;
                }
                if (*puVar19 == 0xff) {
                  *puVar19 = 0xffffffff;
                }
                _printk(&DAT_00105126,"sx937x_parse_dt",0x497,"sx937x_parse_dt");
                of_property_read_variable_u32_array(lVar18,"Semtech,reg-num",puVar8,1,0);
                _printk(&DAT_00105bf0,"sx937x_parse_dt",0x49e,*puVar8);
                if (0 < (int)*puVar8) {
                  lVar9 = devm_kmalloc(lVar16,(ulong)*puVar8 << 3,0xdc0);
                  *(long *)(puVar8 + 6) = lVar9;
                  if (lVar9 == 0) {
                    _printk(&DAT_001043c6,"sx937x_parse_dt",0x4a5,*puVar8);
                  }
                  else {
                    iVar3 = of_property_read_variable_u32_array
                                      (lVar18,"support-panel-num",local_70,1,0);
                    if (iVar3 < 0) {
                      _printk(&DAT_001049bc,"sx937x_parse_dt",0x4c5);
                    }
                    else {
                      _printk(&DAT_00105785,"sx937x_parse_dt",0x4b0,local_70[0]);
                      pcVar10 = (char *)get_dsi_display_name();
                      if (0 < local_70[0]) {
                        iVar3 = 0;
                        do {
                          iVar4 = of_property_read_string_helper
                                            (lVar18,"support-panel-names",&local_78,1,iVar3);
                          if (iVar4 < 0) {
                            puVar6 = &DAT_00104a7e;
                            uVar14 = 0x4b5;
                            goto LAB_00102338;
                          }
                          pcVar11 = strstr(pcVar10,local_78);
                          if (pcVar11 != (char *)0x0) {
                            iVar4 = of_property_read_string_helper
                                              (lVar18,"reg-groups-names",&local_80,1,iVar3);
                            if (iVar4 < 0) {
                              puVar6 = &DAT_001045d6;
                              uVar14 = 0x4bd;
                              goto LAB_00102338;
                            }
                            _printk(&DAT_00105c24,"sx937x_parse_dt",0x4c0,iVar3,local_78,local_80);
                            pcVar10 = local_80;
                            goto LAB_00102380;
                          }
                          iVar3 = iVar3 + 1;
                        } while (iVar3 < local_70[0]);
                      }
                    }
                    pcVar10 = "Semtech,reg-init";
LAB_00102380:
                    iVar3 = of_property_read_variable_u32_array
                                      (lVar18,pcVar10,*(undefined8 *)(puVar8 + 6),
                                       ((long)(int)*puVar8 & 0x1fffffffffffffffU) << 1,0);
                    if (-1 < iVar3) goto LAB_0010239c;
                  }
                  goto LAB_00102340;
                }
LAB_0010239c:
                lVar9 = of_find_property(lVar18,"reinit-on-i2c-failure",0);
                *(bool *)((long)puVar8 + 0x89) = lVar9 != 0;
                lVar18 = of_find_property(lVar18,"esd-reinit-on",0);
                *(bool *)((long)puVar8 + 0x35) = lVar18 != 0;
                _printk(&DAT_0010523c,"sx937x_parse_dt",0x4ec);
                _printk(&DAT_00104498,"sx937x_parse_dt",0x4ed,puVar8[8]);
                *(code **)(puVar8 + 0x28) = sx937x_init_platform_hw;
                _printk(&DAT_00104387,"sx937x_probe",0x666);
                uVar2 = puVar8[0xe];
                if (uVar2 != 0) {
                  if (uVar2 == 1) {
                    _printk(&DAT_001056a5,"sx937x_probe",0x682);
                    goto LAB_0010264c;
                  }
                  if (uVar2 != 2) goto LAB_0010264c;
                  _printk(&DAT_001050a7,"sx937x_probe",0x686,puVar8[0xc]);
                  iVar3 = gpio_request(puVar8[0xc],"sx937x_eldo_gpio");
                  if (iVar3 < 0) {
                    puVar6 = &DAT_00104b9c;
                    uVar14 = 0x689;
                  }
                  else {
                    uVar14 = gpio_to_desc(puVar8[0xc]);
                    iVar3 = gpiod_direction_output_raw(uVar14,1);
                    if (-1 < iVar3) {
                      uVar14 = 0x14;
                      *(undefined1 *)(puVar8 + 0xd) = 1;
                      goto LAB_00102648;
                    }
                    puVar6 = &DAT_0010533c;
                    uVar14 = 0x68e;
                  }
LAB_00102634:
                  _printk(puVar6,"sx937x_probe",uVar14,iVar3);
                  goto LAB_00101f4c;
                }
                uVar12 = regulator_get(lVar16,"cap_vdd");
                *(ulong *)(puVar8 + 2) = uVar12;
                if (uVar12 < 0xfffffffffffff001) {
                  _printk(&DAT_0010561e,"sx937x_probe",0x672);
                  iVar3 = regulator_enable(*(undefined8 *)(puVar8 + 2));
                  if (iVar3 != 0) {
                    regulator_put(*(undefined8 *)(puVar8 + 2));
                    puVar6 = &DAT_00104e41;
                    uVar14 = 0x677;
                    goto LAB_00102634;
                  }
                  *(undefined1 *)(puVar8 + 4) = 1;
                  iVar3 = regulator_is_enabled(*(undefined8 *)(puVar8 + 2));
                  puVar6 = &DAT_00104b98;
                  if (iVar3 != 0) {
                    puVar6 = &DAT_00105a31;
                  }
                  _printk(&DAT_00104d1d,"sx937x_probe",0x67d,puVar6);
                  uVar14 = 10;
LAB_00102648:
                  msleep(uVar14);
                }
                else {
                  if (uVar12 == 0xfffffffffffffdfb) {
                    iVar3 = -0x205;
                    goto LAB_00101f4c;
                  }
                  _printk(&DAT_0010566e,"sx937x_probe",0x670);
                }
LAB_0010264c:
                iVar3 = sx937x_Hardware_Check(plVar5);
                if (iVar3 != 0) {
                  _printk(&DAT_001058c3,"sx937x_probe",0x697);
                  _printk(&DAT_001058fd,"sx937x_probe",0x750);
                  if ((char)puVar8[4] != '\0') {
                    regulator_disable(*(undefined8 *)(puVar8 + 2));
                    regulator_put(*(undefined8 *)(puVar8 + 2));
                  }
                  if ((char)puVar8[0xd] != '\0') {
                    uVar14 = gpio_to_desc(puVar8[0xc]);
                    gpiod_direction_output_raw(uVar14,0);
                  }
                  iVar3 = -6;
                  goto LAB_00101f4c;
                }
                _printk(&DAT_001046b8,"sx937x_probe",0x69d);
                uVar1 = *(undefined4 *)(param_1 + 0x3b4);
                plVar5[3] = (long)initialize;
                plVar5[4] = (long)read_regStat;
                lVar18 = *(long *)(puVar8 + 0x26);
                *(undefined4 *)(plVar5 + 0xf) = uVar1;
                plVar5[5] = lVar18;
                plVar5[6] = 0;
                *(undefined1 *)((long)plVar5 + 0x84) = 0;
                plVar5[0xd] = 0;
                plVar5[7] = 0;
                plVar5[8] = (long)touchProcess;
                plVar5[9] = (long)read_rawData;
                plVar5[10] = (long)touchProcess;
                plVar5[0xb] = (long)touchProcess;
                plVar5[0xc] = (long)touchProcess;
                puVar13 = (undefined8 *)devm_kmalloc(lVar16,0x10,0xdc0);
                plVar5[2] = (long)puVar13;
                if (puVar13 != (undefined8 *)0x0) {
                  iVar3 = __class_register(&capsense_class,&sx937x_probe___key);
                  if (iVar3 < 0) {
                    puVar6 = &DAT_001054f3;
                    uVar14 = 0x6c1;
                    goto LAB_00102634;
                  }
                  kobject_uevent(_DAT_00105d38 + 0x18,2);
                  pcVar15 = *(code **)(puVar8 + 0x28);
                  puVar13[1] = puVar8;
                  if (pcVar15 != (code *)0x0) {
                    if (*(int *)(pcVar15 + -4) != -0x337c9c8b) {
                    /* WARNING: Does not return */
                      pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x102728);
                      (*pcVar15)();
                    }
                    (*pcVar15)(param_1);
                  }
                  lVar16 = plVar7[1];
                  *puVar13 = *(undefined8 *)(puVar8 + 0x24);
                  if (0 < (int)lVar16) {
                    uVar12 = 0;
                    lVar16 = 0x84;
                    do {
                      if ((*puVar17 >> (ulong)((uint)uVar12 & 0x1f) & 1) != 0) {
                        *(undefined1 *)(*plVar7 + lVar16 + 0x7d) = 1;
                        *(undefined4 *)(*plVar7 + lVar16 + -0x7c) = 0;
                        uVar14 = input_allocate_device();
                        *(undefined8 *)(*plVar7 + lVar16 + -0x74) = uVar14;
                        puVar13 = *(undefined8 **)(*plVar7 + lVar16 + -0x74);
                        if (puVar13 == (undefined8 *)0x0) goto LAB_00101f48;
                        *puVar13 = *(undefined8 *)(*plVar7 + lVar16 + -0x6c);
                        lVar18 = *(long *)(*plVar7 + lVar16 + -0x74);
                        *(ulong *)(lVar18 + 0x28) = *(ulong *)(lVar18 + 0x28) | 8;
                        input_set_abs_params
                                  (*(undefined8 *)(*plVar7 + lVar16 + -0x74),0x19,0xffffffff,100,0,0
                                  );
                        input_register_device(*(undefined8 *)(*plVar7 + lVar16 + -0x74));
                        input_event(*(undefined8 *)(*plVar7 + lVar16 + -0x74),3,0x19,0xffffffff);
                        input_event(*(undefined8 *)(*plVar7 + lVar16 + -0x74),0,0,0);
                        *(code **)(*plVar7 + lVar16 + 0x3c) = capsensor_set_enable;
                        *(undefined8 *)(*plVar7 + lVar16 + 0x44) = 0;
                        *(undefined8 *)(*plVar7 + lVar16 + -0x4c) =
                             *(undefined8 *)(*plVar7 + lVar16 + -0x6c);
                        *(char **)(*plVar7 + lVar16 + -0x44) = "semtech";
                        *(undefined4 *)(*plVar7 + lVar16 + -0x3c) = 1;
                        *(undefined4 *)(*plVar7 + lVar16 + -0x34) = 0x10010;
                        *(undefined **)(*plVar7 + lVar16 + -0x2c) = &DAT_001043c4;
                        *(undefined **)(*plVar7 + lVar16 + -0x24) = &DAT_00104463;
                        *(undefined **)(*plVar7 + lVar16 + -0x1c) = &DAT_001050e6;
                        *(undefined4 *)(*plVar7 + lVar16 + -0x14) = 0;
                        *(undefined4 *)(*plVar7 + lVar16 + -0x10) = 0;
                        *(undefined4 *)(*plVar7 + lVar16 + -0xc) = 0;
                        *(undefined4 *)(*plVar7 + lVar16 + 4) = 100;
                        *(undefined4 *)(*plVar7 + lVar16) = 0;
                        *(undefined1 *)(*plVar7 + lVar16 + 0x7c) = 0;
                        iVar3 = sensors_classdev_register
                                          (*(long *)(*plVar7 + lVar16 + -0x74) + 0x240,
                                           *plVar7 + lVar16 + -100);
                        if (iVar3 < 0) {
                          _printk(&DAT_00105b95,"sx937x_probe",0x6f6,uVar12 & 0xffffffff,iVar3);
                        }
                      }
                      uVar12 = uVar12 + 1;
                      lVar16 = lVar16 + 0x108;
                    } while ((long)uVar12 < (long)(int)plVar7[1]);
                  }
                }
                puVar17 = puVar8 + 0x1c;
                *(code **)puVar17 = ps_notify_callback;
                puVar8[0x10] = 0xffffffe0;
                puVar8[0x11] = 0xf;
                *(uint **)(puVar8 + 0x12) = puVar8 + 0x12;
                *(uint **)(puVar8 + 0x14) = puVar8 + 0x12;
                *(code **)(puVar8 + 0x16) = ps_notify_callback_work;
                iVar3 = power_supply_reg_notifier(puVar17);
                if (iVar3 != 0) {
                  _printk(&DAT_0010497b,"sx937x_probe",0x701,iVar3);
                }
                lVar16 = power_supply_get_by_name(&DAT_0010564a);
                if ((lVar16 != 0) && (iVar3 = ps_get_state(lVar16,puVar8 + 0x22), iVar3 != 0)) {
                  _printk(&DAT_001050ea,"sx937x_probe",0x707,iVar3);
                  power_supply_unreg_notifier(puVar17);
                }
                sx93XX_IRQ_init(plVar5);
                pcVar15 = (code *)plVar5[3];
                if (pcVar15 != (code *)0x0) {
                  if (*(int *)(pcVar15 + -4) != -0x6bf853e5) {
                    /* WARNING: Does not return */
                    pcVar15 = (code *)SoftwareBreakpoint(0x8228,0x102aa0);
                    (*pcVar15)();
                  }
                  (*pcVar15)(plVar5);
                  global_sx937x = plVar5;
                  *(code **)(puVar8 + 0x2a) = sx937x_exit_platform_hw;
                  if ((*(char *)((long)puVar8 + 0x89) != '\0') ||
                     (*(char *)((long)puVar8 + 0x35) != '\0')) {
                    plVar5[0x26] = 0xfffffffe0;
                    plVar5[0x27] = (long)(plVar5 + 0x27);
                    plVar5[0x28] = (long)(plVar5 + 0x27);
                    plVar5[0x29] = (long)sx937x_i2c_watchdog_work;
                    init_timer_key(plVar5 + 0x2c,&delayed_work_timer_fn,0x200000,0,0);
                    queue_delayed_work_on(0x20,_system_wq,plVar5 + 0x26,0x9c4);
                  }
                  _printk(&DAT_00105ab1,"sx937x_probe",0x74c);
                  iVar3 = 0;
                  goto LAB_00101f4c;
                }
                puVar6 = &DAT_00104d54;
                uVar14 = 0x73b;
                goto LAB_00101f44;
              }
              puVar6 = &DAT_00104582;
              uVar14 = 0x48f;
            }
          }
LAB_00102338:
          _printk(puVar6,"sx937x_parse_dt",uVar14,"sx937x_parse_dt");
        }
      }
LAB_00102340:
      _printk(&DAT_001055ec,"sx937x_probe",0x661);
      iVar3 = 0x13;
      goto LAB_00101f4c;
    }
    puVar6 = &DAT_00105713;
    uVar14 = 0x64d;
  }
LAB_00101f44:
  _printk(puVar6,"sx937x_probe",uVar14);
LAB_00101f48:
  iVar3 = -0xc;
LAB_00101f4c:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// sx937x_remove @ 00102b84 size=292
// signature: undefined sx937x_remove(void)
// callers: []
//------------------------------------------------------------

void sx937x_remove(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *pcVar3;
  long *plVar4;
  long lVar5;
  long *plVar6;
  long lVar7;
  
  lVar5 = *(long *)(param_1 + 0xb8);
  if ((lVar5 != 0) && (plVar6 = *(long **)(lVar5 + 0x10), plVar6 != (long *)0x0)) {
    lVar7 = *(long *)(param_1 + 0xb0);
    free_irq(*(undefined4 *)(lVar5 + 0x78),lVar5);
    cancel_delayed_work_sync(lVar5 + 0x98);
    class_unregister(&capsense_class);
    cancel_work_sync(lVar7 + 0x40);
    power_supply_unreg_notifier(lVar7 + 0x70);
    if ((lVar7 != 0) && (pcVar3 = *(code **)(lVar7 + 0xa8), pcVar3 != (code *)0x0)) {
      if (*(int *)(pcVar3 + -4) != -0x71002293) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102c08);
        (*pcVar3)();
      }
      (*pcVar3)(param_1);
    }
    if (*(char *)(lVar7 + 0x10) != '\0') {
      regulator_disable(*(undefined8 *)(lVar7 + 8));
      regulator_put(*(undefined8 *)(lVar7 + 8));
    }
    if (*(char *)(lVar7 + 0x34) != '\0') {
      uVar2 = gpio_to_desc(*(undefined4 *)(lVar7 + 0x30));
      gpiod_direction_output_raw(uVar2,0);
    }
    plVar4 = (long *)*plVar6;
    if (0 < (int)plVar4[1]) {
      lVar5 = 0;
      lVar7 = 0x101;
      do {
        if (*(char *)(*plVar4 + lVar7) != '\0') {
          lVar1 = *plVar4 + lVar7;
          sensors_classdev_unregister(lVar1 + -0xe1);
          input_unregister_device(*(undefined8 *)(lVar1 + -0xf1));
          plVar4 = (long *)*plVar6;
        }
        lVar5 = lVar5 + 1;
        lVar7 = lVar7 + 0x108;
      } while (lVar5 < (int)plVar4[1]);
    }
  }
  return;
}



//------------------------------------------------------------
// sx937x_init_platform_hw @ 00102cac size=280
// signature: undefined sx937x_init_platform_hw(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

int sx937x_init_platform_hw(long param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_1 + 0xb8);
  _printk(&DAT_00104fab,"sx937x_init_platform_hw",0x4fa);
  if (((lVar5 == 0) || (*(long *)(lVar5 + 0x10) == 0)) ||
     (lVar6 = *(long *)(*(long *)(lVar5 + 0x10) + 8), lVar6 == 0)) {
    puVar3 = &DAT_00104836;
    uVar4 = 0x515;
  }
  else {
    if (*(uint *)(lVar6 + 0x20) < 0x200) {
      iVar1 = gpio_request(*(uint *)(lVar6 + 0x20),"sx937x_irq_gpio");
      if (iVar1 < 0) {
        puVar3 = &DAT_001053dc;
        uVar4 = 0x503;
      }
      else {
        gpio_to_desc(*(undefined4 *)(lVar6 + 0x20));
        iVar1 = gpiod_direction_input();
        if (-1 < iVar1) {
          gpio_to_desc(*(undefined4 *)(lVar6 + 0x20));
          uVar2 = gpiod_to_irq();
          *(undefined4 *)(param_1 + 0x3b4) = uVar2;
          *(undefined4 *)(lVar5 + 0x78) = uVar2;
          return iVar1;
        }
        puVar3 = &DAT_00105182;
        uVar4 = 0x509;
      }
      _printk(puVar3,"sx937x_init_platform_hw",uVar4,iVar1);
      return iVar1;
    }
    puVar3 = &DAT_0010453a;
    uVar4 = 0x510;
  }
  _printk(puVar3,"sx937x_init_platform_hw",uVar4);
  return 0;
}



//------------------------------------------------------------
// sx937x_Hardware_Check @ 00102dc4 size=320
// signature: undefined sx937x_Hardware_Check(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

uint sx937x_Hardware_Check(long param_1)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  code *pcVar6;
  uint local_30;
  undefined1 auStack_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  *(undefined1 *)(param_1 + 0x70) = 0;
  uVar4 = 0;
  do {
    pcVar6 = *(code **)(param_1 + 0x28);
    if (pcVar6 == (code *)0x0) goto LAB_00102e58;
    if (*(int *)(pcVar6 + -4) != 0x36b1c5a6) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102e30);
      (*pcVar6)();
    }
    iVar3 = (*pcVar6)();
    if (iVar3 == 0) goto LAB_00102e58;
    if (param_1 != 0) {
      sx937x_i2c_read_16bit(param_1,0x4000,auStack_2c);
    }
    msleep(100);
    bVar2 = uVar4 < 10;
    uVar4 = uVar4 + 1;
  } while (bVar2);
  *(undefined1 *)(param_1 + 0x70) = 2;
LAB_00102e58:
  uVar4 = sx937x_i2c_read_16bit(param_1,0x42cc,&local_30);
  if ((int)uVar4 < 0) {
    *(undefined1 *)(param_1 + 0x70) = 4;
    _printk(&DAT_00105549,"sx937x_Hardware_Check",0xfa,4);
  }
  else {
    if ((local_30 & 0xfffff000) == 0x937000) {
      uVar5 = *(undefined1 *)(param_1 + 0x70);
    }
    else {
      uVar5 = 1;
      *(undefined1 *)(param_1 + 0x70) = 1;
    }
    _printk(&DAT_00105a34,"sx937x_Hardware_Check",0x104,local_30,uVar5);
    uVar4 = (uint)*(byte *)(param_1 + 0x70);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// initialize @ 00102f08 size=892
// signature: undefined initialize(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

void initialize(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  int *piVar3;
  long lVar4;
  long lVar5;
  undefined1 auStack_3c [4];
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if (param_1 == 0) {
    uVar2 = 0xfffffff4;
  }
  else {
    _printk(&DAT_00104f3f,"initialize",0x37a);
    *(undefined1 *)(param_1 + 0x7c) = 1;
    disable_irq(*(undefined4 *)(param_1 + 0x78));
    iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
    if (iVar1 < 0) {
      _printk(&DAT_0010461e,"initialize",0x382,1);
      msleep(10);
      iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
      if (iVar1 < 0) {
        _printk(&DAT_0010461e,"initialize",0x382,2);
        msleep(10);
        iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
        if (iVar1 < 0) {
          _printk(&DAT_0010461e,"initialize",0x382,3);
          msleep(10);
          iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
          if (iVar1 < 0) {
            _printk(&DAT_0010461e,"initialize",0x382,4);
            msleep(10);
            iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
            if (iVar1 < 0) {
              _printk(&DAT_0010461e,"initialize",0x382,5);
              msleep(10);
              iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
              if (iVar1 < 0) {
                _printk(&DAT_0010461e,"initialize",0x382,6);
                msleep(10);
                iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                if (iVar1 < 0) {
                  _printk(&DAT_0010461e,"initialize",0x382,7);
                  msleep(10);
                  iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                  if (iVar1 < 0) {
                    _printk(&DAT_0010461e,"initialize",0x382,8);
                    msleep(10);
                    iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                    if (iVar1 < 0) {
                      _printk(&DAT_0010461e,"initialize",0x382,9);
                      msleep(10);
                      iVar1 = sx937x_i2c_write_16bit(param_1,0x4240,0xde);
                      if (iVar1 < 0) {
                        _printk(&DAT_0010461e,"initialize",0x382,10);
                        msleep(10);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    _printk(&DAT_0010475a,"initialize",0x386);
    msleep(100);
    *(undefined1 *)(param_1 + 0x7c) = 0;
    *(undefined2 *)(param_1 + 0x70) = 0x100;
    if ((*(long *)(param_1 + 0x10) == 0) ||
       (piVar3 = *(int **)(*(long *)(param_1 + 0x10) + 8), piVar3 == (int *)0x0)) {
      _printk(&DAT_0010547a,"sx937x_reg_init",0x36a);
    }
    else {
      if (0 < *piVar3) {
        lVar4 = 0;
        lVar5 = 0;
        do {
          sx937x_i2c_write_16bit
                    (param_1,*(undefined4 *)(*(long *)(piVar3 + 6) + lVar4),
                     ((undefined4 *)(*(long *)(piVar3 + 6) + lVar4))[1]);
          lVar5 = lVar5 + 1;
          lVar4 = lVar4 + 8;
        } while (lVar5 < *piVar3);
      }
      sx937x_i2c_write_16bit(param_1,0x4280,0xf);
    }
    enable_irq(*(undefined4 *)(param_1 + 0x78));
    sx937x_i2c_read_16bit(param_1,0x4000,auStack_3c);
    uVar2 = 0;
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// touchProcess @ 00103288 size=504
// signature: undefined touchProcess(void)
// callers: []
//------------------------------------------------------------

void touchProcess(long param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  long lVar9;
  uint *puVar10;
  uint local_5c;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_5c = 0;
  if ((param_1 != 0) && (puVar7 = *(undefined8 **)(param_1 + 0x10), puVar7 != (undefined8 *)0x0)) {
    sx937x_i2c_read_16bit(param_1,0x8000,&local_5c);
    uVar4 = local_5c;
    puVar7 = (undefined8 *)*puVar7;
    puVar10 = (uint *)*puVar7;
    if (puVar10 == (uint *)0x0) {
      _printk(&DAT_00105c81,"touchProcess",0x3b1);
    }
    else {
      uVar2 = *(uint *)(puVar7 + 1);
      if (0 < (int)uVar2) {
        uVar8 = 0;
        do {
          if (((char)puVar10[0x40] != '\0') && (*(char *)((long)puVar10 + 0x101) != '\0')) {
            if (puVar10 == (uint *)0x0) {
              puVar5 = &DAT_00105592;
              uVar6 = 0x3c2;
            }
            else {
              lVar9 = *(long *)(puVar10 + 4);
              if (lVar9 != 0) {
                uVar3 = puVar10[1] | *puVar10;
                uVar1 = uVar3 & uVar4;
                if (uVar1 == uVar3) {
                  if (puVar10[2] != 2) {
                    input_event(lVar9,3,0x19,2);
                    input_event(lVar9,0,0,0);
                    puVar10[2] = 2;
                  }
                }
                else if (uVar1 == *puVar10) {
                  if (puVar10[2] != 1) {
                    input_event(lVar9,3,0x19,1);
                    input_event(lVar9,0,0,0);
                    puVar10[2] = 1;
                  }
                }
                else if ((uVar1 == 0) && (puVar10[2] != 0)) {
                  input_event(lVar9,3,0x19,0);
                  input_event(lVar9,0,0,0);
                  puVar10[2] = 0;
                }
                goto LAB_00103300;
              }
              puVar5 = &DAT_0010593e;
              uVar6 = 0x3c8;
            }
            _printk(puVar5,"touchProcess",uVar6,uVar8 & 0xffffffff);
            break;
          }
LAB_00103300:
          uVar8 = uVar8 + 1;
          puVar10 = puVar10 + 0x42;
        } while (uVar2 != uVar8);
      }
    }
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// read_rawData @ 00103484 size=660
// signature: undefined read_rawData(void)
// callers: []
//------------------------------------------------------------

void read_rawData(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  long lVar5;
  uint uVar6;
  undefined4 local_78;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  undefined1 auStack_64 [4];
  uint local_60;
  undefined1 auStack_5c [4];
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  local_78 = 0;
  if (param_1 != 0) {
    lVar5 = *(long *)(*(long *)(param_1 + 0x10) + 8);
    iVar1 = *(int *)(lVar5 + 0x24);
    iVar2 = *(int *)(lVar5 + 0x28);
    iVar3 = *(int *)(lVar5 + 0x2c);
    sx937x_i2c_read_16bit(param_1,0x8000,auStack_64);
    sx937x_i2c_read_16bit(param_1,0x8274,&local_78);
    sx937x_i2c_read_16bit(param_1,0x8284,auStack_74);
    if (iVar1 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar1 * 4 + -0x7e10,auStack_64);
    }
    if (iVar2 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar2 * 4 + -0x7e10,auStack_64);
    }
    if (iVar3 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar3 * 4 + -0x7e10,auStack_64);
    }
    uVar6 = 0;
    do {
      iVar1 = (uVar6 & 0x3f) * 4;
      sx937x_i2c_read_16bit(param_1,iVar1 + -0x7e10,auStack_68);
      sx937x_i2c_read_16bit(param_1,iVar1 + -0x7df0,auStack_6c);
      sx937x_i2c_read_16bit(param_1,iVar1 + -0x7dd0,auStack_70);
      sx937x_i2c_read_16bit(param_1,(uVar6 & 0x3f) * 0xc + -0x7fd4,auStack_64);
      bVar4 = uVar6 < 7;
      uVar6 = uVar6 + 1;
    } while (bVar4);
    local_60 = 0;
    lVar5 = *(long *)(*(long *)(param_1 + 0x10) + 8);
    iVar1 = *(int *)(lVar5 + 0x24);
    iVar2 = *(int *)(lVar5 + 0x28);
    iVar3 = *(int *)(lVar5 + 0x2c);
    sx937x_i2c_read_16bit(param_1,0x8000,auStack_5c);
    if (iVar1 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar1 * 4 + -0x7e10,auStack_5c);
    }
    if (iVar2 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar2 * 4 + -0x7e10,auStack_5c);
    }
    if (iVar3 != -1) {
      sx937x_i2c_read_16bit(param_1,iVar3 * 4 + -0x7e10,auStack_5c);
    }
    sx937x_i2c_read_16bit(param_1,0x8274,&local_60);
    sx937x_i2c_read_16bit(param_1,0x8278,auStack_5c);
    sx937x_i2c_read_16bit(param_1,0x827c,auStack_5c);
    sx937x_i2c_read_16bit(param_1,0x8280,auStack_5c);
    sx937x_i2c_read_16bit(param_1,0x8284,auStack_5c);
    uVar6 = local_60 >> 1 & 0x1c;
    sx937x_i2c_read_16bit(param_1,uVar6 - 0x7e10,auStack_5c);
    sx937x_i2c_read_16bit(param_1,uVar6 - 0x7df0,auStack_5c);
    sx937x_i2c_read_16bit(param_1,uVar6 - 0x7dd0,auStack_5c);
    sx937x_i2c_read_16bit(param_1,uVar6 * 3 + -0x7fd4,auStack_5c);
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// capsensor_set_enable @ 0010371c size=576
// signature: undefined capsensor_set_enable(void)
// callers: []
//------------------------------------------------------------

undefined8 capsensor_set_enable(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  uint local_6c;
  long local_68;
  
  lVar1 = sp_el0;
  lVar3 = 0;
  local_68 = *(long *)(lVar1 + 0x638);
  local_6c = 0;
  do {
    __s1 = *(char **)(param_1 + 0x18);
    iVar2 = strcmp(__s1,*(char **)((long)&PTR_s_Moto_CapSense_Ch0_00105f00 + lVar3));
    if (iVar2 == 0) {
      if (param_2 == 0) {
        _printk(&DAT_00104ac9,"capsensor_set_enable",0x543,__s1);
        (&DAT_00105fe8)[lVar3] = 0;
        input_event(*(undefined8 *)(&DAT_00105ef8 + lVar3),3,0x19,0xffffffff);
        input_event(*(undefined8 *)(&DAT_00105ef8 + lVar3),0,0,0);
      }
      else if (param_2 == 1) {
        _printk(&DAT_00104d99,"capsensor_set_enable",0x538,__s1);
        sx937x_i2c_read_16bit(global_sx937x,0x8024,&local_6c);
        local_6c = local_6c | 0x7f;
        sx937x_i2c_write_16bit(global_sx937x,0x8024);
        (&DAT_00105fe8)[lVar3] = 1;
        input_event(*(undefined8 *)(&DAT_00105ef8 + lVar3),3,0x19,0);
        input_event(*(undefined8 *)(&DAT_00105ef8 + lVar3),0,0,0);
        sx937x_i2c_write_16bit(global_sx937x,0x4280,0xe);
      }
      else {
        _printk(&DAT_001057bd,"capsensor_set_enable",0x548);
      }
    }
    lVar3 = lVar3 + 0x108;
  } while (lVar3 != 0x840);
  if (((((DAT_00105fe8 == '\0') && (DAT_001060f0 == '\0')) && (DAT_001061f8 == '\0')) &&
      ((DAT_00106300 == '\0' && (DAT_00106408 == '\0')))) &&
     ((DAT_00106510 == '\0' && ((DAT_00106618 == '\0' && (DAT_00106720 == '\0')))))) {
    _printk(&DAT_001046f0,"capsensor_set_enable",0x555);
    sx937x_i2c_read_16bit(global_sx937x,0x8024,&local_6c);
    sx937x_i2c_write_16bit(global_sx937x,0x8024,local_6c & 0xffffff00);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// ps_notify_callback_work @ 00103960 size=124
// signature: undefined ps_notify_callback_work(void)
// callers: []
//------------------------------------------------------------

void ps_notify_callback_work(void)

{
  long lVar1;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  sx937x_i2c_read_16bit(global_sx937x,0x8024,&local_2c);
  if ((char)local_2c != '\0') {
    sx937x_i2c_write_16bit(global_sx937x,0x4280,0xe);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// ps_notify_callback @ 001039e0 size=256
// signature: undefined ps_notify_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 ps_notify_callback(long param_1,long param_2,undefined8 *param_3)

{
  long lVar1;
  int iVar2;
  char *__s1;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((((param_2 == 0) && (param_3 != (undefined8 *)0x0)) && (((undefined8 *)*param_3)[6] != 0)) &&
     (__s1 = *(char **)*param_3, __s1 != (char *)0x0)) {
    iVar2 = strncmp(__s1,"usb",4);
    if ((param_1 != 0x70) && (iVar2 == 0)) {
      local_40 = 0;
      iVar2 = power_supply_get_property(param_3,4,&local_40);
      if (iVar2 == 0) {
        if ((bool)*(char *)(param_1 + 0x18) != ((int)local_40 != 0)) {
          *(bool *)(param_1 + 0x18) = (int)local_40 != 0;
          queue_work_on(0x20,_system_wq,param_1 + -0x30);
        }
      }
      else {
        _printk(&DAT_0010486b,"ps_notify_callback",0x59b,iVar2);
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
// ps_get_state @ 00103ae0 size=116
// signature: undefined ps_get_state(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

void ps_get_state(undefined4 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = power_supply_get_property(param_1,4,&local_30);
  if (iVar2 == 0) {
    *(bool *)param_2 = (int)local_30 != 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// sx937x_exit_platform_hw @ 00103b58 size=92
// signature: undefined sx937x_exit_platform_hw(void)
// callers: []
//------------------------------------------------------------

void sx937x_exit_platform_hw(long param_1)

{
  long lVar1;
  
  if (((*(long *)(param_1 + 0xb8) != 0) &&
      (lVar1 = *(long *)(*(long *)(param_1 + 0xb8) + 0x10), lVar1 != 0)) &&
     (lVar1 = *(long *)(lVar1 + 8), lVar1 != 0)) {
    if (*(uint *)(lVar1 + 0x20) < 0x200) {
      gpio_free();
    }
    else {
      _printk(&DAT_00104fe1,"sx937x_exit_platform_hw",0x528);
    }
  }
  return;
}



//------------------------------------------------------------
// sx937x_i2c_watchdog_work @ 00103bb8 size=1200
// signature: undefined sx937x_i2c_watchdog_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sx937x_i2c_watchdog_work(long param_1)

{
  undefined4 uVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  uint uVar10;
  int local_64;
  uint local_60;
  undefined4 local_5c;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  lVar9 = param_1 + -0x130;
  local_64 = 0;
  if (*(long *)(param_1 + -0x120) == 0) {
    if (*(int *)(param_1 + 0x88) == 0) {
LAB_00103cfc:
      iVar5 = sx937x_i2c_read_16bit(lVar9,0x42cc,&local_64);
      if (-1 < iVar5) {
        uVar6 = 10000;
        sx937x_i2c_watchdog_work_err_cnt = 0;
        goto LAB_00104010;
      }
      sx937x_i2c_watchdog_work_err_cnt = sx937x_i2c_watchdog_work_err_cnt + 1;
      _printk(&DAT_0010526c,"sx937x_i2c_watchdog_work",0x8ce);
      if (sx937x_i2c_watchdog_work_err_cnt < 3) {
LAB_00103f54:
        uVar6 = 2000;
        goto LAB_00104010;
      }
      sx937x_i2c_watchdog_work_err_cnt = 0;
      goto LAB_00103f78;
    }
  }
  else if (*(int *)(param_1 + 0x88) == 0) {
    lVar7 = *(long *)(*(long *)(param_1 + -0x120) + 8);
    if ((lVar7 == 0) || (*(char *)(lVar7 + 0x35) == '\0')) goto LAB_00103cfc;
    iVar5 = sx937x_i2c_read_16bit(lVar9,0x4004,&local_64);
    if (iVar5 < 0) {
      sx937x_i2c_watchdog_work_err_cnt = sx937x_i2c_watchdog_work_err_cnt + 1;
      _printk(&DAT_0010598e,"sx937x_i2c_watchdog_work",0x8b4);
      if (sx937x_i2c_watchdog_work_err_cnt < 3) goto LAB_00103f54;
      sx937x_i2c_watchdog_work_err_cnt = 0;
      vdd_power_off_on(lVar9,0);
      msleep(100);
      vdd_power_off_on(lVar9,1);
    }
    else {
      sx937x_i2c_watchdog_work_err_cnt = 0;
      if (local_64 != 0x60) {
        local_5c = 0;
        local_60 = 0;
        sx937x_i2c_read_16bit(lVar9,0x8024,&local_60);
        uVar3 = local_60;
        lVar7 = 0;
        uVar10 = 0;
        bVar2 = (byte)local_60;
        do {
          if ((bVar2 >> (ulong)(uVar10 & 0x1f) & 1) == 0) {
            uVar8 = (ulong)sx937x_register_err_check_round;
            if ((0x5c < lVar7 + uVar8 * 4) || (0x5c < lVar7 + uVar8 * 4)) goto LAB_00104060;
            uVar1 = 0;
          }
          else {
            sx937x_i2c_read_16bit(lVar9,uVar10 * 4 + -0x7e10,&local_5c);
            uVar8 = (ulong)sx937x_register_err_check_round;
            if ((0x5c < lVar7 + uVar8 * 4) || (0x5c < lVar7 + uVar8 * 4)) {
LAB_00104060:
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(1,0x104064);
              (*pcVar4)();
            }
            uVar1 = local_5c;
          }
          uVar10 = uVar10 + 1;
          *(undefined4 *)((long)&sx937x_register_err_ph_useful + lVar7 + uVar8 * 4) = uVar1;
          lVar7 = lVar7 + 0xc;
        } while (lVar7 != 0x60);
        if ((uVar3 & 1) == 0) {
LAB_00103d4c:
          if ((bVar2 >> 1 & 1) != 0) {
            if (((DAT_00106a40 != 0) && (DAT_00106a44 != 0)) &&
               ((DAT_00106a40 == DAT_00106a44 && (DAT_00106a3c == DAT_00106a40)))) {
              lVar7 = 1;
              iVar5 = DAT_00106a40;
              goto LAB_00103fb8;
            }
          }
          if ((bVar2 >> 2 & 1) != 0) {
            if (((DAT_00106a4c != 0) && (DAT_00106a50 != 0)) &&
               ((DAT_00106a4c == DAT_00106a50 && (DAT_00106a48 == DAT_00106a4c)))) {
              lVar7 = 2;
              iVar5 = DAT_00106a4c;
              goto LAB_00103fb8;
            }
          }
          if ((bVar2 >> 3 & 1) != 0) {
            if ((((DAT_00106a58 != 0) && (DAT_00106a5c != 0)) && (DAT_00106a58 == DAT_00106a5c)) &&
               (DAT_00106a54 == DAT_00106a58)) {
              lVar7 = 3;
              iVar5 = DAT_00106a58;
              goto LAB_00103fb8;
            }
          }
          if ((bVar2 >> 4 & 1) != 0) {
            if (((DAT_00106a64 != 0) && (DAT_00106a68 != 0)) &&
               ((DAT_00106a64 == DAT_00106a68 && (DAT_00106a60 == DAT_00106a64)))) {
              lVar7 = 4;
              iVar5 = DAT_00106a64;
              goto LAB_00103fb8;
            }
          }
          if ((bVar2 >> 5 & 1) != 0) {
            if (((DAT_00106a70 != 0) && (DAT_00106a74 != 0)) &&
               ((DAT_00106a70 == DAT_00106a74 && (DAT_00106a6c == DAT_00106a70)))) {
              lVar7 = 5;
              iVar5 = DAT_00106a70;
              goto LAB_00103fb8;
            }
          }
          if ((bVar2 >> 6 & 1) != 0) {
            if ((((DAT_00106a7c != 0) && (DAT_00106a80 != 0)) && (DAT_00106a7c == DAT_00106a80)) &&
               (DAT_00106a78 == DAT_00106a7c)) {
              lVar7 = 6;
              iVar5 = DAT_00106a7c;
              goto LAB_00103fb8;
            }
          }
          if ((char)bVar2 < '\0') {
            if (((DAT_00106a88 != 0) && (DAT_00106a8c != 0)) &&
               ((DAT_00106a88 == DAT_00106a8c && (DAT_00106a84 == DAT_00106a88)))) {
              lVar7 = 7;
              iVar5 = DAT_00106a88;
              goto LAB_00103fb8;
            }
          }
        }
        else {
          if ((((_DAT_00106a34 == 0) || (_DAT_00106a38 == 0)) || (_DAT_00106a34 != _DAT_00106a38))
             || (sx937x_register_err_ph_useful != _DAT_00106a34)) goto LAB_00103d4c;
          lVar7 = 0;
          iVar5 = _DAT_00106a34;
LAB_00103fb8:
          _printk(&DAT_00104664,"sx937x_register_err",0x895,lVar7,
                  (&sx937x_register_err_ph_useful)[lVar7 * 3],iVar5,iVar5);
          sx937x_reinitialize(lVar9);
          uVar8 = (ulong)sx937x_register_err_check_round;
        }
        uVar6 = 10000;
        sx937x_register_err_check_round = ((int)uVar8 + 1U) % 3;
        goto LAB_00104010;
      }
      _printk(&DAT_001048d5,"sx937x_i2c_watchdog_work",0x8c2,0x60);
    }
LAB_00103f78:
    sx937x_reinitialize(lVar9);
  }
  uVar6 = 10000;
LAB_00104010:
  uVar6 = __msecs_to_jiffies(uVar6);
  queue_delayed_work_on(0x20,_system_wq,param_1,uVar6);
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// vdd_power_off_on @ 00104068 size=176
// signature: undefined vdd_power_off_on(void)
// callers: [sx937x_i2c_watchdog_work]
//------------------------------------------------------------

void vdd_power_off_on(long param_1,uint param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x10) + 8);
  if (*(char *)(lVar3 + 0x34) == '\0') {
    _printk(&DAT_001052ae,"vdd_power_off_on",0x876);
  }
  else {
    uVar2 = gpio_to_desc(*(undefined4 *)(lVar3 + 0x30));
    iVar1 = gpiod_direction_output_raw(uVar2,param_2 & 1);
    _printk(&DAT_001059d1,"vdd_power_off_on",0x871,*(undefined4 *)(lVar3 + 0x30),param_2 & 1);
    if (iVar1 < 0) {
      _printk(&DAT_00104b00,"vdd_power_off_on",0x873,iVar1);
    }
  }
  return;
}



//------------------------------------------------------------
// sx937x_suspend @ 0010411c size=116
// signature: undefined sx937x_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 sx937x_suspend(long param_1)

{
  long lVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (lVar2 != 0) {
    if (((*(long *)(lVar2 + 0x10) != 0) &&
        (lVar1 = *(long *)(*(long *)(lVar2 + 0x10) + 8), lVar1 != 0)) &&
       ((*(char *)(lVar1 + 0x89) != '\0' || (*(char *)(lVar1 + 0x35) != '\0')))) {
      cancel_delayed_work_sync(lVar2 + 0x130);
    }
    sx937x_i2c_write_16bit(lVar2,0x4280,0xd);
    disable_irq(*(undefined4 *)(lVar2 + 0x78));
    *(undefined4 *)(lVar2 + 0x1b8) = 1;
  }
  return 0;
}



//------------------------------------------------------------
// sx937x_resume @ 00104194 size=204
// signature: undefined sx937x_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sx937x_resume(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 != 0) {
    uVar1 = _raw_spin_lock_irqsave(lVar3 + 0x74);
    cancel_delayed_work(lVar3 + 0x98);
    queue_delayed_work_on(0x20,_system_wq,lVar3 + 0x98,0);
    _raw_spin_unlock_irqrestore(lVar3 + 0x74,uVar1);
    enable_irq(*(undefined4 *)(lVar3 + 0x78));
    sx937x_i2c_write_16bit(lVar3,0x4280,0xc);
    *(undefined4 *)(lVar3 + 0x1b8) = 0;
    if (((*(long *)(lVar3 + 0x10) != 0) &&
        (lVar2 = *(long *)(*(long *)(lVar3 + 0x10) + 8), lVar2 != 0)) &&
       ((*(char *)(lVar2 + 0x89) != '\0' || (*(char *)(lVar2 + 0x35) != '\0')))) {
      queue_delayed_work_on(0x20,_system_wq,lVar3 + 0x130,500);
    }
  }
  return 0;
}



//------------------------------------------------------------
// sx93XX_schedule_work @ 00104260 size=112
// signature: undefined sx93XX_schedule_work(void)
// callers: [sx93XX_worker_func]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sx93XX_schedule_work(long param_1,undefined8 param_2)

{
  undefined8 uVar1;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x74);
  cancel_delayed_work(param_1 + 0x98);
  queue_delayed_work_on(0x20,_system_wq,param_1 + 0x98,param_2);
  _raw_spin_unlock_irqrestore(param_1 + 0x74,uVar1);
  return;
}



//------------------------------------------------------------
// init_module @ 001042d4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  i2c_register_driver(&__this_module,sx937x_driver);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00104304 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  i2c_del_driver(sx937x_driver);
  return;
}



//------------------------------------------------------------
// of_find_node_opts_by_path @ 00109000 size=1
// signature: undefined of_find_node_opts_by_path(void)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_opts_by_path(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00109008 size=1
// signature: undefined of_property_read_string(void)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00109010 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [sx937x_probe, get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strchr @ 00109018 size=1
// signature: char * strchr(char * __s, int __c)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 00109020 size=1
// signature: size_t strlen(char * __s)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00109028 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109030 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [manual_offset_calibration_show, ps_get_state, initialize, ps_notify_callback_work, capsensor_set_enable, read_rawData, get_dsi_display_name, capsense_reset_store, manual_offset_calibration_store, sx937x_reinitialize, sx937x_probe, sx937x_i2c_read_16bit, touchProcess, sx937x_Hardware_Check, ps_notify_callback, sx937x_i2c_write_16bit, read_regStat, capsense_raw_data_show, sx937x_register_write_store, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00109038 size=1
// signature: undefined fortify_panic(void)
// callers: [get_dsi_display_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 00109040 size=1
// signature: undefined i2c_register_driver(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 00109048 size=1
// signature: undefined i2c_del_driver(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00109058 size=1
// signature: undefined init_timer_key(void)
// callers: [sx937x_probe, sx93XX_IRQ_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00109060 size=1
// signature: undefined request_threaded_irq(void)
// callers: [sx93XX_IRQ_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00109068 size=1
// signature: undefined _printk(void)
// callers: [reg_store, sx937x_exit_platform_hw, initialize, sx937x_init_platform_hw, capsensor_set_enable, sx93XX_worker_func, sx937x_register_read_store, sx93XX_IRQ_init, sx93XX_irq, manual_offset_calibration_store, vdd_power_off_on, sx937x_reinitialize, sx937x_probe, sx937x_i2c_read_16bit, touchProcess, sx937x_Hardware_Check, ps_notify_callback, sx937x_i2c_write_16bit, sx937x_reg_init, sx937x_register_write_store, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00109070 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [sx93XX_worker_func, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00109078 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [sx93XX_schedule_work, sx93XX_irq, sx937x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work @ 00109080 size=1
// signature: undefined cancel_delayed_work(void)
// callers: [sx93XX_schedule_work, sx93XX_irq, sx937x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00109090 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [sx93XX_schedule_work, sx937x_probe, sx93XX_irq, sx937x_i2c_watchdog_work, sx937x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00109098 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [sx93XX_schedule_work, sx93XX_irq, sx937x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncmp @ 001090a0 size=1
// signature: int strncmp(char * __s1, char * __s2, size_t __n)
// callers: [ps_notify_callback, capsense_reset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 001090a8 size=1
// signature: undefined i2c_transfer(void)
// callers: [sx937x_i2c_read_16bit, sx937x_i2c_write_16bit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 001090b0 size=1
// signature: undefined msleep(void)
// callers: [sx937x_reinitialize, initialize, sx937x_probe, sx937x_i2c_read_16bit, sx937x_Hardware_Check, sx937x_i2c_write_16bit, sx937x_i2c_watchdog_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 001090b8 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [capsense_raw_data_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 001090c0 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [sx937x_register_read_store, sx937x_register_write_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 001090c8 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [manual_offset_calibration_show, sx937x_int_state_show, sx937x_register_read_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 001090d0 size=1
// signature: undefined gpio_to_desc(void)
// callers: [sx937x_remove, sx937x_probe, sx937x_init_platform_hw, sx937x_get_nirq_state, sx937x_register_read_store, vdd_power_off_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 001090d8 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [sx937x_get_nirq_state, sx937x_register_read_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 001090e0 size=1
// signature: undefined kstrtoull(void)
// callers: [manual_offset_calibration_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001090f0 size=1
// signature: undefined disable_irq(void)
// callers: [sx937x_reinitialize, initialize, sx937x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 001090f8 size=1
// signature: undefined enable_irq(void)
// callers: [sx937x_reinitialize, initialize, sx937x_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109100 size=1
// signature: undefined devm_kmalloc(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00109108 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 00109110 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 00109118 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00109120 size=1
// signature: undefined of_find_property(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_get @ 00109128 size=1
// signature: undefined regulator_get(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_request @ 00109130 size=1
// signature: undefined gpio_request(void)
// callers: [sx937x_probe, sx937x_init_platform_hw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 00109138 size=1
// signature: undefined regulator_enable(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_is_enabled @ 00109140 size=1
// signature: undefined regulator_is_enabled(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_is_enabled(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 00109148 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [sx937x_remove, sx937x_probe, vdd_power_off_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_put @ 00109150 size=1
// signature: undefined regulator_put(void)
// callers: [sx937x_remove, sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 00109158 size=1
// signature: undefined __class_register(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent @ 00109160 size=1
// signature: undefined kobject_uevent(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 00109168 size=1
// signature: undefined input_allocate_device(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_abs_params @ 00109170 size=1
// signature: undefined input_set_abs_params(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_abs_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 00109178 size=1
// signature: undefined input_register_device(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 00109180 size=1
// signature: undefined input_event(void)
// callers: [sx937x_probe, capsensor_set_enable, touchProcess]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_register @ 00109188 size=1
// signature: undefined sensors_classdev_register(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 00109190 size=1
// signature: undefined regulator_disable(void)
// callers: [sx937x_remove, sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00109198 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_by_name @ 001091a0 size=1
// signature: undefined power_supply_get_by_name(void)
// callers: [sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_unreg_notifier @ 001091a8 size=1
// signature: undefined power_supply_unreg_notifier(void)
// callers: [sx937x_remove, sx937x_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_unreg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 001091b0 size=1
// signature: undefined free_irq(void)
// callers: [sx937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 001091b8 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [sx937x_remove, sx937x_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 001091c0 size=1
// signature: undefined class_unregister(void)
// callers: [sx937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 001091c8 size=1
// signature: undefined cancel_work_sync(void)
// callers: [sx937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sensors_classdev_unregister @ 001091d0 size=1
// signature: undefined sensors_classdev_unregister(void)
// callers: [sx937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sensors_classdev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 001091d8 size=1
// signature: undefined input_unregister_device(void)
// callers: [sx937x_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_input @ 001091e0 size=1
// signature: undefined gpiod_direction_input(void)
// callers: [sx937x_init_platform_hw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_input(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 001091e8 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [sx937x_init_platform_hw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001091f0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [capsensor_set_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_get_property @ 001091f8 size=1
// signature: undefined power_supply_get_property(void)
// callers: [ps_get_state, ps_notify_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 00109200 size=1
// signature: undefined queue_work_on(void)
// callers: [ps_notify_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_free @ 00109208 size=1
// signature: undefined gpio_free(void)
// callers: [sx937x_exit_platform_hw]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



