// Decompiled by Ghidra 12.2
// Program: sensors_class.ko
// Image base: 00100000

//------------------------------------------------------------
// sensors_classdev_register @ 001005cc size=308
// signature: undefined sensors_classdev_register(void)
// callers: []
//------------------------------------------------------------

undefined4 sensors_classdev_register(undefined8 param_1,ulong *param_2)

{
  ulong *puVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  
  _printk("sensors_classdev_register,%s\n",param_2[3]);
  uVar5 = device_create(sensors_class,param_1,0,param_2,&DAT_001018b1,param_2[3]);
  *param_2 = uVar5;
  if (uVar5 < 0xfffffffffffff001) {
    down_write(&sensors_list_lock);
    puVar2 = PTR_sensors_list_00101508;
    puVar1 = param_2 + 1;
    uVar5 = __list_add_valid(puVar1,PTR_sensors_list_00101508,&sensors_list);
    if ((uVar5 & 1) != 0) {
      PTR_sensors_list_00101508 = (undefined *)puVar1;
      param_2[1] = (ulong)&sensors_list;
      param_2[2] = (ulong)puVar2;
      *(ulong **)puVar2 = puVar1;
    }
    up_write(&sensors_list_lock);
    uVar5 = 0;
    do {
      iVar3 = device_create_file(*param_2,(&sensors_class_attrs)[uVar5]);
      if (iVar3 != 0) {
        _printk("i = %d,device_create_file register fail\n",uVar5 & 0xffffffff);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 != 0x14);
    _printk("Registered sensors device: %s,ret = %d\n",param_2[3],iVar3);
    uVar4 = 0;
  }
  else {
    _printk("sensors_classdev_register fail\n");
    uVar4 = (undefined4)*param_2;
  }
  return uVar4;
}



//------------------------------------------------------------
// sensors_classdev_unregister @ 00100704 size=136
// signature: undefined sensors_classdev_unregister(void)
// callers: []
//------------------------------------------------------------

void sensors_classdev_unregister(undefined8 *param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  
  _printk(&DAT_00101a5f,"sensors_classdev_unregister");
  device_unregister(*param_1);
  down_write(&sensors_list_lock);
  uVar3 = __list_del_entry_valid(param_1 + 1);
  if ((uVar3 & 1) != 0) {
    lVar1 = param_1[1];
    plVar2 = (long *)param_1[2];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  param_1[1] = 0xdead000000000100;
  param_1[2] = 0xdead000000000122;
  up_write(&sensors_list_lock);
  return;
}



//------------------------------------------------------------
// sensors_name_show @ 00100790 size=60
// signature: undefined sensors_name_show(void)
// callers: []
//------------------------------------------------------------

long sensors_name_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%s\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_vendor_show @ 001007d0 size=60
// signature: undefined sensors_vendor_show(void)
// callers: []
//------------------------------------------------------------

long sensors_vendor_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%s\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_version_show @ 00100810 size=60
// signature: undefined sensors_version_show(void)
// callers: []
//------------------------------------------------------------

long sensors_version_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x28));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_handle_show @ 00100850 size=60
// signature: undefined sensors_handle_show(void)
// callers: []
//------------------------------------------------------------

long sensors_handle_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x2c));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_type_show @ 00100890 size=60
// signature: undefined sensors_type_show(void)
// callers: []
//------------------------------------------------------------

long sensors_type_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x30));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_max_range_show @ 001008d0 size=60
// signature: undefined sensors_max_range_show(void)
// callers: []
//------------------------------------------------------------

long sensors_max_range_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%s\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x38));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_resolution_show @ 00100910 size=60
// signature: undefined sensors_resolution_show(void)
// callers: []
//------------------------------------------------------------

long sensors_resolution_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%s\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x40));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_power_show @ 00100950 size=60
// signature: undefined sensors_power_show(void)
// callers: []
//------------------------------------------------------------

long sensors_power_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%s\n",*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x48));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_min_delay_show @ 00100990 size=60
// signature: undefined sensors_min_delay_show(void)
// callers: []
//------------------------------------------------------------

long sensors_min_delay_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x50));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_fifo_event_show @ 001009d0 size=60
// signature: undefined sensors_fifo_event_show(void)
// callers: []
//------------------------------------------------------------

long sensors_fifo_event_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x54));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_fifo_max_show @ 00100a10 size=60
// signature: undefined sensors_fifo_max_show(void)
// callers: []
//------------------------------------------------------------

long sensors_fifo_max_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x58));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_max_delay_show @ 00100a50 size=60
// signature: undefined sensors_max_delay_show(void)
// callers: []
//------------------------------------------------------------

long sensors_max_delay_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x5c));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_flags_show @ 00100a90 size=60
// signature: undefined sensors_flags_show(void)
// callers: []
//------------------------------------------------------------

long sensors_flags_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x60));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_enable_show @ 00100ad0 size=60
// signature: undefined sensors_enable_show(void)
// callers: []
//------------------------------------------------------------

long sensors_enable_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%u\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 100));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_enable_store @ 00100b10 size=252
// signature: undefined sensors_enable_store(void)
// callers: []
//------------------------------------------------------------

long sensors_enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    if (1 < local_40) {
      _dev_err(param_1,"Invalid value of input, input=%ld\n");
      param_4 = -0x16;
      goto LAB_00100b9c;
    }
    pcVar2 = *(code **)(lVar3 + 0xa0);
    if (pcVar2 == (code *)0x0) {
      _dev_err(param_1,"Invalid sensor class enable handle\n");
      param_4 = -0x16;
      goto LAB_00100b9c;
    }
    if (*(int *)(pcVar2 + -4) != -0x36e0f63c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100b90);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(lVar3,local_40 & 0xffffffff);
    if (iVar1 == 0) {
      *(int *)(lVar3 + 100) = (int)local_40;
      goto LAB_00100b9c;
    }
  }
  param_4 = (long)iVar1;
LAB_00100b9c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sensors_enable_wakeup_show @ 00100c10 size=60
// signature: undefined sensors_enable_wakeup_show(void)
// callers: []
//------------------------------------------------------------

long sensors_enable_wakeup_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%d\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x6c));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_enable_wakeup_store @ 00100c50 size=216
// signature: undefined sensors_enable_wakeup_store(void)
// callers: []
//------------------------------------------------------------

long sensors_enable_wakeup_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  ulong local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_30 = 0;
  if (*(long *)(lVar3 + 0xc0) == 0) {
    _dev_err(param_1,"Invalid sensor class enable_wakeup handle\n");
    param_4 = -0x16;
  }
  else {
    iVar2 = kstrtoull(param_3,10,&local_30);
    if (iVar2 == 0) {
      local_30 = (ulong)(local_30 != 0);
      if (*(int *)(*(code **)(lVar3 + 0xc0) + -4) != -0x36e0f63c) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100ccc);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar3 + 0xc0))(lVar3);
      if (iVar2 == 0) {
        *(int *)(lVar3 + 0x6c) = (int)local_30;
        goto LAB_00100cd8;
      }
    }
    param_4 = (long)iVar2;
  }
LAB_00100cd8:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sensors_delay_show @ 00100d2c size=60
// signature: undefined sensors_delay_show(void)
// callers: []
//------------------------------------------------------------

long sensors_delay_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%u\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x68));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_delay_store @ 00100d6c size=264
// signature: undefined sensors_delay_store(void)
// callers: []
//------------------------------------------------------------

long sensors_delay_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    if (local_40 * 1000 < (ulong)(long)*(int *)(lVar3 + 0x50)) {
      _dev_err(param_1,"Invalid value of delay, delay=%ld\n");
      param_4 = -0x16;
      goto LAB_00100e04;
    }
    pcVar2 = *(code **)(lVar3 + 0xa8);
    if (pcVar2 == (code *)0x0) {
      _dev_err(param_1,"Invalid sensor class delay handle\n");
      param_4 = -0x16;
      goto LAB_00100e04;
    }
    if (*(int *)(pcVar2 + -4) != -0x36e0f63c) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100df8);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(lVar3,local_40 & 0xffffffff);
    if (iVar1 == 0) {
      *(int *)(lVar3 + 0x68) = (int)local_40;
      goto LAB_00100e04;
    }
  }
  param_4 = (long)iVar1;
LAB_00100e04:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sensors_test_show @ 00100e78 size=172
// signature: undefined sensors_test_show(void)
// callers: []
//------------------------------------------------------------

long sensors_test_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  
  pcVar4 = *(code **)(*(long *)(param_1 + 0x98) + 0xb0);
  if (pcVar4 == (code *)0x0) {
    _dev_err(param_1,"Invalid sensor class self test handle\n");
    lVar2 = -0x16;
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0x5a7f5b9b) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x100eb4);
      (*pcVar4)();
    }
    iVar1 = (*pcVar4)();
    if (iVar1 == 0) {
      puVar3 = &DAT_0010179b;
    }
    else {
      _dev_warn(param_1,"self test failed.(%d)\n",iVar1);
      puVar3 = &DAT_001018be;
    }
    iVar1 = snprintf(param_3,0x1000,"%s\n",puVar3);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// sensors_max_latency_show @ 00100f28 size=60
// signature: undefined sensors_max_latency_show(void)
// callers: []
//------------------------------------------------------------

long sensors_max_latency_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"%u\n",(ulong)*(uint *)(*(long *)(param_1 + 0x98) + 0x70));
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_max_latency_store @ 00100f68 size=280
// signature: undefined sensors_max_latency_store(void)
// callers: []
//------------------------------------------------------------

long sensors_max_latency_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  long lVar4;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    if ((ulong)(long)*(int *)(lVar4 + 0x5c) < local_40) {
      _dev_err(param_1,"max_latency(%lu) is greater than max_delay(%u)\n");
    }
    else {
      pcVar3 = *(code **)(lVar4 + 0xb8);
      if (pcVar3 == (code *)0x0) {
        pcVar2 = "Invalid sensor calss set latency handle\n";
      }
      else {
        if ((local_40 == 0) || (*(uint *)(lVar4 + 0x68) <= local_40)) {
          if (*(int *)(pcVar3 + -4) != -0x36e0f63c) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x100ffc);
            (*pcVar3)();
          }
          iVar1 = (*pcVar3)(lVar4,local_40 & 0xffffffff);
          if (iVar1 == 0) {
            *(int *)(lVar4 + 0x70) = (int)local_40;
            goto LAB_00101008;
          }
          goto LAB_00101004;
        }
        pcVar2 = "max_latency is less than delay_msec\n";
      }
      _dev_err(param_1,pcVar2);
    }
    param_4 = -0x16;
  }
  else {
LAB_00101004:
    param_4 = (long)iVar1;
  }
LAB_00101008:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sensors_flush_show @ 00101084 size=84
// signature: undefined sensors_flush_show(void)
// callers: []
//------------------------------------------------------------

long sensors_flush_show(long param_1,undefined8 param_2,char *param_3)

{
  char *param3;
  int iVar1;
  
  param3 = "not exist";
  if (*(long *)(*(long *)(param_1 + 0x98) + 200) != 0) {
    param3 = "exist";
  }
  iVar1 = snprintf(param_3,0x1000,"Flush handler %s\n",param3);
  return (long)iVar1;
}



//------------------------------------------------------------
// sensors_flush_store @ 001010dc size=244
// signature: undefined sensors_flush_store(void)
// callers: []
//------------------------------------------------------------

void sensors_flush_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoull(param_3,10,&local_40);
  if (iVar1 == 0) {
    if (local_40 == 1) {
      pcVar2 = *(code **)(lVar3 + 200);
      if (pcVar2 == (code *)0x0) {
        _dev_err(param_1,"Invalid sensor class flush handle\n");
        param_4 = -0x16;
      }
      else {
        if (*(int *)(pcVar2 + -4) != -0x5a7f5b9b) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101160);
          (*pcVar2)();
        }
        iVar1 = (*pcVar2)(lVar3);
        if (iVar1 != 0) {
          param_4 = (long)iVar1;
        }
      }
    }
    else {
      _dev_err(param_1,"Flush: Invalid value of input, input=%ld\n");
      param_4 = -0x16;
    }
  }
  else {
    param_4 = (long)iVar1;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// sensors_calibrate_show @ 001011d4 size=84
// signature: undefined sensors_calibrate_show(void)
// callers: []
//------------------------------------------------------------

long sensors_calibrate_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  if (*(long *)(*(long *)(param_1 + 0x98) + 0x78) == 0) {
    _dev_err(param_1,"Invalid sensor params\n");
    lVar2 = -0x16;
  }
  else {
    iVar1 = snprintf(param_3,0x1000,"%s\n");
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// sensors_calibrate_store @ 0010122c size=388
// signature: undefined sensors_calibrate_store(void)
// callers: []
//------------------------------------------------------------

long sensors_calibrate_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  ulong local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x98);
  local_40 = 0;
  iVar1 = kstrtoll(param_3,0,&local_40);
  if (iVar1 != 0) {
    param_4 = (long)iVar1;
    goto LAB_0010127c;
  }
  uVar3 = (uint)local_40;
  if ((local_40 & 0xf) == 0) {
    pcVar4 = *(code **)(lVar6 + 0xd0);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x2b9cc8ea) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x101328);
        (*pcVar4)();
      }
      iVar1 = (*pcVar4)(lVar6,(int)uVar3 >> 0x11,uVar3 >> 0x10 & 1);
      if (iVar1 != 0) {
        param_4 = (long)iVar1;
      }
      goto LAB_0010127c;
    }
    pcVar2 = "Invalid calibrate handle\n";
  }
  else {
    pcVar4 = *(code **)(lVar6 + 0xd8);
    if (pcVar4 == (code *)0x0) {
      pcVar2 = "Invalid write_cal_params handle\n";
    }
    else {
      if ((uVar3 & 0xf) < 10) {
        if (0xb < (local_40 & 0xf)) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(1,0x1013b0);
          (*pcVar4)();
        }
        lVar5 = (long)*(int *)(&cal_map + (local_40 & 0xf) * 4);
        lVar6 = lVar6 + 0x80;
        if ((uVar3 >> 4 & 1) == 0) {
          *(uint *)(lVar6 + lVar5) = (uint)(local_40 >> 0x10) & 0xffff | *(uint *)(lVar6 + lVar5);
        }
        else {
          *(uint *)(lVar6 + lVar5) = uVar3 & 0xffff0000;
        }
        goto LAB_0010127c;
      }
      if ((uVar3 & 0xf) == 10) {
        if (*(int *)(pcVar4 + -4) != 0x5372fc8d) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x101364);
          (*pcVar4)();
        }
        (*pcVar4)(lVar6,lVar6 + 0x80);
        goto LAB_0010127c;
      }
      pcVar2 = "Invalid command\n";
    }
  }
  _dev_err(param_1,pcVar2);
  param_4 = -0x16;
LAB_0010127c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 001013ec size=124
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

ulong init_module(void)

{
  ulong uVar1;
  
  _printk("moto sensor init!\n");
  sensors_class = __class_create(&__this_module,"sensors",&sensors_init___key);
  if (sensors_class < 0xfffffffffffff001) {
    _printk("sensor init success!\n");
    uVar1 = 0;
  }
  else {
    _printk("sensor init fail!\n");
    uVar1 = sensors_class & 0xffffffff;
  }
  return uVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010146c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  class_destroy(sensors_class);
  return;
}



//------------------------------------------------------------
// _printk @ 00103000 size=1
// signature: undefined _printk(void)
// callers: [init_module, sensors_classdev_register, sensors_classdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00103008 size=1
// signature: undefined device_create(void)
// callers: [sensors_classdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00103010 size=1
// signature: undefined down_write(void)
// callers: [sensors_classdev_register, sensors_classdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103018 size=1
// signature: undefined __list_add_valid(void)
// callers: [sensors_classdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 00103020 size=1
// signature: undefined up_write(void)
// callers: [sensors_classdev_register, sensors_classdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00103028 size=1
// signature: undefined device_create_file(void)
// callers: [sensors_classdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 00103030 size=1
// signature: undefined device_unregister(void)
// callers: [sensors_classdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103038 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [sensors_classdev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00103040 size=1
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
// class_destroy @ 00103048 size=1
// signature: undefined class_destroy(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103050 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [sensors_fifo_event_show, sensors_fifo_max_show, sensors_resolution_show, sensors_type_show, sensors_min_delay_show, sensors_vendor_show, sensors_power_show, sensors_version_show, sensors_enable_show, sensors_max_latency_show, sensors_test_show, sensors_flush_show, sensors_calibrate_show, sensors_handle_show, sensors_max_delay_show, sensors_delay_show, sensors_max_range_show, sensors_enable_wakeup_show, sensors_name_show, sensors_flags_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00103058 size=1
// signature: undefined kstrtoull(void)
// callers: [sensors_enable_wakeup_store, sensors_flush_store, sensors_max_latency_store, sensors_enable_store, sensors_delay_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103060 size=1
// signature: undefined _dev_err(void)
// callers: [sensors_enable_wakeup_store, sensors_flush_store, sensors_max_latency_store, sensors_calibrate_store, sensors_enable_store, sensors_delay_store, sensors_test_show, sensors_calibrate_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [sensors_enable_wakeup_store, sensors_flush_store, sensors_max_latency_store, sensors_calibrate_store, sensors_enable_store, sensors_delay_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00103070 size=1
// signature: undefined _dev_warn(void)
// callers: [sensors_test_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 00103078 size=1
// signature: undefined kstrtoll(void)
// callers: [sensors_calibrate_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



