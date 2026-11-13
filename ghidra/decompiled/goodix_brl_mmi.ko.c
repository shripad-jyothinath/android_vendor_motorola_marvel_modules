// Decompiled by Ghidra 12.2
// Program: goodix_brl_mmi.ko
// Image base: 00100000

//------------------------------------------------------------
// goodix_i2c_bus_init @ 0010326c size=92
// signature: undefined goodix_i2c_bus_init(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_i2c_bus_init(void)

{
  ulong uVar1;
  undefined8 uVar2;
  
  _printk(&DAT_0011f09a,"goodix_i2c_bus_init",0x114);
  uVar1 = mmi_check_dynamic_device_node("goodix_ts_i2c");
  if ((uVar1 & 1) == 0) {
    uVar2 = 0xffffffed;
  }
  else {
    uVar2 = i2c_register_driver(&__this_module,&goodix_i2c_driver);
  }
  return uVar2;
}



//------------------------------------------------------------
// goodix_i2c_bus_exit @ 001032cc size=60
// signature: undefined goodix_i2c_bus_exit(void)
// callers: []
//------------------------------------------------------------

void goodix_i2c_bus_exit(void)

{
  _printk(&DAT_0012476e,"goodix_i2c_bus_exit",0x11c);
  i2c_del_driver(&goodix_i2c_driver);
  return;
}



//------------------------------------------------------------
// goodix_i2c_probe @ 0010330c size=420
// signature: undefined goodix_i2c_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_i2c_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 *puVar3;
  code *pcVar4;
  
  _printk(&DAT_00125ccd,"goodix_i2c_probe",0xaf);
  if ((*(long *)(param_1 + 0x308) == 0) || (uVar2 = mmi_device_is_available(), (uVar2 & 1) != 0)) {
    pcVar4 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x20);
    if (*(int *)(pcVar4 + -4) != -0x70861f50) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103370);
      (*pcVar4)();
    }
    uVar2 = (*pcVar4)();
    if ((uVar2 & 1) == 0) {
      iVar1 = -5;
    }
    else {
      iVar1 = goodix_get_ic_type(*(undefined8 *)(param_1 + 0x308));
      if (-1 < iVar1) {
        DAT_001292e0 = param_1 + 0x20;
        goodix_i2c_bus = 0;
        DAT_001292e8 = goodix_i2c_read;
        DAT_001292f0 = goodix_i2c_write;
        DAT_001292dc = iVar1;
        puVar3 = (undefined8 *)kmalloc_trace(_msleep,0xdc0,0x3f0);
        goodix_pdev = puVar3;
        if (puVar3 == (undefined8 *)0x0) {
          iVar1 = -0xc;
        }
        else {
          *(undefined8 **)(param_1 + 0xb8) = puVar3;
          *(undefined4 *)(puVar3 + 1) = 0;
          *puVar3 = "goodix_ts";
          *(undefined4 *)(puVar3 + 0x77) = 0;
          puVar3[0x14] = &goodix_i2c_bus;
          puVar3[0x67] = goodix_pdev_release;
          iVar1 = platform_device_register();
          if (iVar1 == 0) {
            _printk(&DAT_0011eb56,"goodix_i2c_probe",0xdf);
          }
          else {
            _printk(&DAT_00125cf5,"goodix_i2c_probe",0xdc,iVar1);
            puVar3 = goodix_pdev;
            *(undefined8 *)(param_1 + 0xb8) = 0;
            kfree(puVar3);
            goodix_pdev = (undefined8 *)0x0;
            _printk(&DAT_00123701,"goodix_i2c_probe",0xe6,iVar1);
          }
        }
      }
    }
  }
  else {
    _printk(&DAT_00120e8b,"goodix_i2c_probe",0xb2);
    iVar1 = -0x13;
  }
  return iVar1;
}



//------------------------------------------------------------
// goodix_i2c_remove @ 001034b4 size=36
// signature: undefined goodix_i2c_remove(void)
// callers: []
//------------------------------------------------------------

void goodix_i2c_remove(void)

{
  platform_device_unregister(goodix_pdev);
  return;
}



//------------------------------------------------------------
// goodix_i2c_read @ 001034dc size=524
// signature: undefined goodix_i2c_read(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_i2c_read(long param_1,int param_2,long param_3,uint param_4)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  uint uVar8;
  undefined4 local_114;
  undefined2 local_110;
  undefined6 uStack_10e;
  undefined4 *local_108;
  undefined8 local_100;
  undefined8 *local_f8;
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
  long local_70;
  
  lVar1 = sp_el0;
  local_108 = &local_114;
  local_70 = *(long *)(lVar1 + 0x638);
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
  local_114 = 0;
  local_f8 = (undefined8 *)0x0;
  _local_110 = CONCAT62(0x40000,*(undefined2 *)(param_1 + -0x1e));
  local_100._0_4_ = CONCAT22(1,*(undefined2 *)(param_1 + -0x1e));
  local_100 = (ulong)(uint)local_100;
  if (param_4 < 0x80) {
    local_f8 = &local_f0;
  }
  else {
    local_f8 = (undefined8 *)__kmalloc(param_4,0xdc0);
    if (local_f8 == (undefined8 *)0x0) {
      uVar4 = 0xfffffff4;
      goto LAB_00103680;
    }
  }
  uVar7 = 0;
  iVar3 = param_2;
  do {
    uVar6 = (uint)uVar7;
    if (uVar6 == param_4) {
      uVar4 = 0;
      goto LAB_00103678;
    }
    uVar8 = param_4 - uVar6;
    iVar5 = 1;
    *(char *)local_108 = (char)((uint)iVar3 >> 0x18);
    if (0xff < uVar8) {
      uVar8 = 0x100;
    }
    *(char *)((long)local_108 + 1) = (char)((uint)iVar3 >> 0x10);
    *(char *)((long)local_108 + 2) = (char)((uint)iVar3 >> 8);
    *(char *)((long)local_108 + 3) = (char)iVar3;
    local_100._0_6_ = CONCAT24((short)uVar8,(uint)local_100);
    while (iVar2 = i2c_transfer(*(undefined8 *)(param_1 + -8),&local_110,2), iVar2 != 2) {
      _printk(&DAT_00124df2,"goodix_i2c_read",0x52,iVar5,param_2);
      usleep_range_state(2000,0x834,2);
      iVar5 = iVar5 + 1;
      if (iVar5 == 0x15) goto LAB_00103648;
    }
    memcpy((void *)(param_3 + uVar7),local_f8,(ulong)uVar8);
    uVar7 = (ulong)(uVar8 + uVar6);
    iVar3 = uVar8 + iVar3;
  } while (iVar5 != 0x15);
LAB_00103648:
  _printk(&DAT_0011f662,"goodix_i2c_read",0x57,*(undefined2 *)(param_1 + -0x1e),param_2,param_4);
  uVar4 = 0xfffffff5;
LAB_00103678:
  if (0x7f < param_4) {
    kfree(local_f8);
  }
LAB_00103680:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// goodix_i2c_write @ 001036ec size=512
// signature: undefined goodix_i2c_write(void)
// callers: []
//------------------------------------------------------------

undefined4 goodix_i2c_write(long param_1,ulong param_2,long param_3,uint param_4)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  undefined4 uVar4;
  ulong uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined8 local_f8;
  undefined8 *local_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  uVar1 = param_4 + 4;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  local_e8 = 0;
  uStack_e0 = 0;
  local_f0 = (undefined8 *)0x0;
  local_f8 = (ulong)*(ushort *)(param_1 + -0x1e);
  if (uVar1 < 0x80) {
    local_f0 = &local_e8;
  }
  else {
    local_f0 = (undefined8 *)__kmalloc(uVar1,0xcc0);
    if (local_f0 == (undefined8 *)0x0) {
      uVar4 = 0xfffffff4;
      goto LAB_0010385c;
    }
  }
  if (param_4 != 0) {
    uVar8 = 0;
    uVar5 = param_2 & 0xffffffff;
    do {
      *(char *)local_f0 = (char)(uVar5 >> 0x18);
      *(char *)((long)local_f0 + 1) = (char)(uVar5 >> 0x10);
      *(char *)((long)local_f0 + 2) = (char)(uVar5 >> 8);
      uVar6 = param_4 - uVar8;
      if (0xfb < uVar6) {
        uVar6 = 0xfc;
      }
      *(char *)((long)local_f0 + 3) = (char)uVar5;
      local_f8._0_6_ = CONCAT24((short)uVar6 + 4,(undefined4)local_f8);
      memcpy((undefined1 *)((long)local_f0 + 4),(void *)(param_3 + (ulong)uVar8),(ulong)uVar6);
      iVar7 = 1;
      while (iVar3 = i2c_transfer(*(undefined8 *)(param_1 + -8),&local_f8,1), iVar3 != 1) {
        if (debug_log_flag != '\0') {
          _printk(&DAT_00125d34,"goodix_i2c_write",0x90,iVar7);
        }
        msleep(0x14);
        iVar7 = iVar7 + 1;
        if (iVar7 == 0x15) {
          _printk(&DAT_00123727,"goodix_i2c_write",0x95,*(undefined2 *)(param_1 + -0x1e),
                  param_2 & 0xffffffff,param_4);
          uVar4 = 0xfffffff5;
          if (uVar1 < 0x80) goto LAB_0010385c;
          goto LAB_00103854;
        }
      }
      uVar8 = uVar6 + uVar8;
      uVar5 = (ulong)(uVar6 + (int)uVar5);
    } while (uVar8 != param_4);
  }
  uVar4 = 0;
  if (0x7f < uVar1) {
LAB_00103854:
    kfree(local_f0);
  }
LAB_0010385c:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar4;
}



//------------------------------------------------------------
// goodix_pdev_release @ 001038f0 size=60
// signature: undefined goodix_pdev_release(void)
// callers: []
//------------------------------------------------------------

void goodix_pdev_release(void)

{
  _printk(&DAT_00125368,"goodix_pdev_release",0xa3);
  kfree(goodix_pdev);
  return;
}



//------------------------------------------------------------
// log_spi_timeout @ 00103930 size=168
// signature: undefined log_spi_timeout(void)
// callers: []
//------------------------------------------------------------

void log_spi_timeout(int param_1,ulong param_2)

{
  char cVar1;
  bool bVar2;
  undefined1 *puVar3;
  undefined8 uVar4;
  
  if (param_1 == -0x6e) {
    if ((param_2 & 1) == 0) {
      Hint_Prefetch(0x129304,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(0x129304,0x10);
        if (bVar2) {
          cVar1 = ExclusiveMonitorsStatus();
          total_spi_read_timeouts = total_spi_read_timeouts + 1;
        }
      } while (cVar1 != '\0');
      DataMemoryBarrier(2,3);
      puVar3 = &DAT_00124799;
      uVar4 = 0x39;
    }
    else {
      Hint_Prefetch(0x129300,2,0,1);
      do {
        cVar1 = '\x01';
        bVar2 = (bool)ExclusiveMonitorPass(0x129300,0x10);
        if (bVar2) {
          cVar1 = ExclusiveMonitorsStatus();
          total_spi_write_timeouts = total_spi_write_timeouts + 1;
        }
      } while (cVar1 != '\0');
      DataMemoryBarrier(2,3);
      puVar3 = &DAT_00121ef1;
      uVar4 = 0x36;
    }
    _printk(puVar3,"log_spi_timeout",uVar4);
  }
  return;
}



//------------------------------------------------------------
// check_spi_timeout @ 00103a04 size=188
// signature: undefined check_spi_timeout(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void check_spi_timeout(int param_1,ulong param_2)

{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  
  bVar5 = (param_2 & 1) == 0;
  piVar1 = &consecutive_write_timeouts;
  if (bVar5) {
    piVar1 = &consecutive_read_timeouts;
  }
  pcVar2 = "WRITE";
  if (bVar5) {
    pcVar2 = "READ";
  }
  if (param_1 == -0x6e) {
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar3 + 1;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    DataMemoryBarrier(2,3);
    if (2 < iVar3 + 1) {
      _printk(&DAT_00122717,"check_spi_timeout",0x65,pcVar2);
      queue_work_on(0x20,_system_wq,&restart_work);
    }
  }
  else if ((-1 < param_1) && (0 < *piVar1)) {
    *piVar1 = 0;
  }
  return;
}



//------------------------------------------------------------
// goodix_spi_bus_init @ 00103ad8 size=68
// signature: undefined goodix_spi_bus_init(void)
// callers: [init_module]
//------------------------------------------------------------

void goodix_spi_bus_init(void)

{
  _printk(&DAT_00120274,"goodix_spi_bus_init",0x184);
  __spi_register_driver(&__this_module,&goodix_spi_driver);
  return;
}



//------------------------------------------------------------
// goodix_spi_bus_exit @ 00103b20 size=60
// signature: undefined goodix_spi_bus_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void goodix_spi_bus_exit(void)

{
  _printk(&DAT_00124e1e,"goodix_spi_bus_exit",0x18a);
  driver_unregister(&PTR_s_goodix_ts_00128678);
  return;
}



//------------------------------------------------------------
// restart_work_func @ 00103b60 size=212
// signature: undefined restart_work_func(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void restart_work_func(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  Hint_Prefetch(0x129330,2,0,1);
  do {
    iVar3 = restart_triggered;
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(0x129330,0x10);
    if (bVar2) {
      restart_triggered = 1;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  DataMemoryBarrier(2,3);
  if (iVar3 == 0) {
    if (goodix_pdev != 0) {
      pm_wakeup_dev_event(goodix_pdev + 0x10,6000,0);
    }
    _printk(&DAT_001262a7,"restart_work_func",0x57);
    queue_delayed_work_on(0x20,_system_wq,emergency_restart_delayed_work,0x5dc);
    _printk(&DAT_0011fcc8,"restart_work_func",0x5a);
    kernel_restart("mmi_reboot_exception");
  }
  else {
    _printk(&DAT_00121f4e,"restart_work_func",0x4f);
  }
  return;
}



//------------------------------------------------------------
// emergency_restart_work_func @ 00103c38 size=52
// signature: undefined emergency_restart_work_func(void)
// callers: []
//------------------------------------------------------------

void emergency_restart_work_func(void)

{
  _printk(&DAT_0011e65b,"emergency_restart_work_func",0x48);
  emergency_restart();
  return;
}



//------------------------------------------------------------
// goodix_spi_probe @ 00103c70 size=440
// signature: undefined goodix_spi_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_spi_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined *puVar4;
  undefined8 uVar5;
  
  _printk(&DAT_0011da59,"goodix_spi_probe",0x116);
  if ((*(long *)(param_1 + 0x2e8) != 0) && (uVar2 = mmi_device_is_available(), (uVar2 & 1) == 0)) {
    _printk(&DAT_00121fb9,"goodix_spi_probe",0x119,"goodix_spi_probe");
    return -0x13;
  }
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined1 *)(param_1 + 0x3a5) = 8;
  iVar1 = spi_setup(param_1);
  if (iVar1 == 0) {
    iVar1 = goodix_get_ic_type(*(undefined8 *)(param_1 + 0x2e8));
    if (iVar1 < 0) {
      return iVar1;
    }
    DAT_00129320 = goodix_spi_read_bra;
    if (iVar1 != 4) {
      DAT_00129320 = goodix_spi_read;
    }
    goodix_spi_bus = 1;
    DAT_00129328 = goodix_spi_write;
    DAT_00129314 = iVar1;
    DAT_00129318 = param_1;
    puVar3 = (undefined8 *)kmalloc_trace(_msleep,0xdc0,0x3f0);
    if (puVar3 == (undefined8 *)0x0) {
      goodix_pdev = puVar3;
      return -0xc;
    }
    goodix_pdev = puVar3;
    *(undefined8 **)(param_1 + 0x98) = puVar3;
    *(undefined4 *)(puVar3 + 1) = 0;
    *puVar3 = "goodix_ts";
    *(undefined4 *)(puVar3 + 0x77) = 0;
    puVar3[0x14] = &goodix_spi_bus;
    puVar3[0x67] = goodix_pdev_release;
    iVar1 = platform_device_register();
    if (iVar1 == 0) {
      _printk(&DAT_00123766,"goodix_spi_probe",0x14e);
      return 0;
    }
    _printk(&DAT_00125cf5,"goodix_spi_probe",0x14b,iVar1);
    puVar3 = goodix_pdev;
    *(undefined8 *)(param_1 + 0x98) = 0;
    kfree(puVar3);
    goodix_pdev = (undefined8 *)0x0;
    puVar4 = &DAT_00123788;
    uVar5 = 0x155;
  }
  else {
    puVar4 = &DAT_001240d7;
    uVar5 = 0x123;
  }
  _printk(puVar4,"goodix_spi_probe",uVar5,iVar1);
  return iVar1;
}



//------------------------------------------------------------
// goodix_spi_remove @ 00103e2c size=36
// signature: undefined goodix_spi_remove(void)
// callers: []
//------------------------------------------------------------

void goodix_spi_remove(void)

{
  platform_device_unregister(goodix_pdev);
  return;
}



//------------------------------------------------------------
// goodix_spi_read_bra @ 00103e54 size=668
// signature: undefined goodix_spi_read_bra(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_spi_read_bra(undefined8 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined8 ****local_178;
  undefined8 ****local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 ****local_120;
  undefined8 ****local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined1 *local_100;
  long lStack_f8;
  ulong local_f0;
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
  undefined8 ****local_88;
  undefined8 ****local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  uVar1 = param_4 + 9;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = __kmalloc(uVar1,0xdc0);
  puVar7 = (undefined1 *)__kmalloc(uVar1,0xdc0);
  if ((lVar6 == 0) || (puVar7 == (undefined1 *)0x0)) {
    _printk(&DAT_0011fd05,"goodix_spi_read_bra",0x84,uVar1);
    iVar5 = -0xc;
    goto LAB_00103fc4;
  }
  local_110 = 0;
  uStack_108 = 0;
  local_120 = &local_120;
  local_130 = 0;
  uStack_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_168 = 0;
  puVar7[4] = (char)param_2;
  uStack_e8 = 0;
  *puVar7 = 0xf1;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  puVar7[1] = (char)((uint)param_2 >> 0x18);
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  puVar7[2] = (char)((uint)param_2 >> 0x10);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  local_88 = (undefined8 ****)0x0;
  puVar7[3] = (char)((uint)param_2 >> 8);
  local_80 = (undefined8 ****)0x0;
  uStack_78 = 0;
  local_70 = 0;
  *(undefined4 *)(puVar7 + 5) = 0xffffffff;
  local_f0 = (ulong)uVar1;
  local_178 = &local_178;
  local_170 = &local_178;
  local_118 = local_120;
  local_100 = puVar7;
  lStack_f8 = lVar6;
  uVar8 = __list_add_valid(&local_88,&local_178,&local_178);
  if ((uVar8 & 1) != 0) {
    local_178 = &local_88;
    local_170 = &local_88;
    local_88 = &local_178;
    local_80 = &local_178;
  }
  iVar5 = spi_sync(param_1,&local_178);
  if (iVar5 == -0x6e) {
    Hint_Prefetch(0x129304,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(0x129304,0x10);
      if (bVar4) {
        cVar3 = ExclusiveMonitorsStatus();
        total_spi_read_timeouts = total_spi_read_timeouts + 1;
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    _printk(&DAT_00124799,"log_spi_timeout",0x39);
    Hint_Prefetch(0x12930c,2,0,1);
    do {
      iVar2 = consecutive_read_timeouts + 1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(0x12930c,0x10);
      if (bVar4) {
        cVar3 = ExclusiveMonitorsStatus();
        consecutive_read_timeouts = iVar2;
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (2 < iVar2) {
      _printk(&DAT_00122717,"check_spi_timeout",0x65,&DAT_00125d5c);
      queue_work_on(0x20,_system_wq,&restart_work);
    }
LAB_001040ac:
    _printk(&DAT_001237ae,"goodix_spi_read_bra",0x9f,iVar5);
  }
  else {
    if (iVar5 < 0) goto LAB_001040ac;
    if (0 < consecutive_read_timeouts) {
      consecutive_read_timeouts = 0;
    }
    memcpy(param_3,(void *)(lVar6 + 9),(ulong)param_4);
  }
  kfree(lVar6);
  kfree(puVar7);
LAB_00103fc4:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// goodix_spi_read @ 00104124 size=676
// signature: undefined goodix_spi_read(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_spi_read(undefined8 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  long lVar6;
  undefined1 *puVar7;
  ulong uVar8;
  undefined8 ****local_178;
  undefined8 ****local_170;
  undefined8 local_168;
  undefined8 local_160;
  undefined8 uStack_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 ****local_120;
  undefined8 ****local_118;
  undefined8 local_110;
  undefined8 uStack_108;
  undefined1 *local_100;
  long lStack_f8;
  ulong local_f0;
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
  undefined8 ****local_88;
  undefined8 ****local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar6 = sp_el0;
  uVar1 = param_4 + 8;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = __kmalloc(uVar1,0xdc0);
  puVar7 = (undefined1 *)__kmalloc(uVar1,0xdc0);
  if ((lVar6 == 0) || (puVar7 == (undefined1 *)0x0)) {
    _printk(&DAT_0011fd05,"goodix_spi_read",0xb8,uVar1);
    iVar5 = -0xc;
    goto LAB_0010429c;
  }
  local_110 = 0;
  uStack_108 = 0;
  local_120 = &local_120;
  local_130 = 0;
  uStack_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_160 = 0;
  uStack_158 = 0;
  local_168 = 0;
  puVar7[4] = (char)param_2;
  uStack_e8 = 0;
  *puVar7 = 0xf1;
  local_e0 = 0;
  uStack_d8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  puVar7[1] = (char)((uint)param_2 >> 0x18);
  local_c0 = 0;
  uStack_b8 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  puVar7[2] = (char)((uint)param_2 >> 0x10);
  local_a0 = 0;
  uStack_98 = 0;
  local_90 = 0;
  local_88 = (undefined8 ****)0x0;
  puVar7[3] = (char)((uint)param_2 >> 8);
  local_80 = (undefined8 ****)0x0;
  uStack_78 = 0;
  local_70 = 0;
  *(undefined2 *)(puVar7 + 5) = 0xffff;
  puVar7[7] = 0xff;
  local_f0 = (ulong)uVar1;
  local_178 = &local_178;
  local_170 = &local_178;
  local_118 = local_120;
  local_100 = puVar7;
  lStack_f8 = lVar6;
  uVar8 = __list_add_valid(&local_88,&local_178,&local_178);
  if ((uVar8 & 1) != 0) {
    local_178 = &local_88;
    local_170 = &local_88;
    local_88 = &local_178;
    local_80 = &local_178;
  }
  iVar5 = spi_sync(param_1,&local_178);
  if (iVar5 == -0x6e) {
    Hint_Prefetch(0x129304,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(0x129304,0x10);
      if (bVar4) {
        cVar3 = ExclusiveMonitorsStatus();
        total_spi_read_timeouts = total_spi_read_timeouts + 1;
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    _printk(&DAT_00124799,"log_spi_timeout",0x39);
    Hint_Prefetch(0x12930c,2,0,1);
    do {
      iVar2 = consecutive_read_timeouts + 1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(0x12930c,0x10);
      if (bVar4) {
        cVar3 = ExclusiveMonitorsStatus();
        consecutive_read_timeouts = iVar2;
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if (2 < iVar2) {
      _printk(&DAT_00122717,"check_spi_timeout",0x65,&DAT_00125d5c);
      queue_work_on(0x20,_system_wq,&restart_work);
    }
LAB_00104384:
    _printk(&DAT_001237ae,"goodix_spi_read",0xd2,iVar5);
  }
  else {
    if (iVar5 < 0) goto LAB_00104384;
    if (0 < consecutive_read_timeouts) {
      consecutive_read_timeouts = 0;
    }
    memcpy(param_3,(void *)(lVar6 + 8),(ulong)param_4);
  }
  kfree(lVar6);
  kfree(puVar7);
LAB_0010429c:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// goodix_spi_write @ 001043fc size=640
// signature: undefined goodix_spi_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_spi_write(undefined8 param_1,undefined4 param_2,void *param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  long ****pppplVar5;
  int iVar6;
  undefined1 *puVar7;
  ulong uVar8;
  long ****local_168;
  long ****local_160;
  undefined8 local_158;
  undefined8 local_150;
  undefined8 uStack_148;
  undefined8 local_140;
  undefined8 uStack_138;
  undefined8 local_130;
  undefined8 uStack_128;
  undefined8 local_120;
  undefined8 uStack_118;
  undefined8 ****local_110;
  undefined8 ****local_108;
  undefined8 local_100;
  undefined8 uStack_f8;
  undefined1 *local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  ulong local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  long ****local_78;
  long ****pppplStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  iVar6 = param_4 + 5;
  local_58 = *(long *)(lVar4 + 0x638);
  puVar7 = (undefined1 *)__kmalloc(iVar6,0xdc0);
  if (puVar7 == (undefined1 *)0x0) {
    _printk(&DAT_00123319,"goodix_spi_write",0xf1,iVar6);
    iVar6 = -0xc;
    goto LAB_00104554;
  }
  local_100 = 0;
  uStack_f8 = 0;
  local_110 = &local_110;
  local_120 = 0;
  uStack_118 = 0;
  local_130 = 0;
  uStack_128 = 0;
  local_140 = 0;
  uStack_138 = 0;
  local_150 = 0;
  uStack_148 = 0;
  local_158 = 0;
  local_e8 = 0;
  local_e0 = 0;
  local_d8 = 0;
  uStack_d0 = 0;
  *puVar7 = 0xf0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_b8 = 0;
  uStack_b0 = 0;
  puVar7[1] = (char)((uint)param_2 >> 0x18);
  local_a8 = 0;
  uStack_a0 = 0;
  local_98 = 0;
  uStack_90 = 0;
  puVar7[2] = (char)((uint)param_2 >> 0x10);
  local_88 = 0;
  uStack_80 = 0;
  local_78 = (long ****)0x0;
  pppplStack_70 = (long ****)0x0;
  puVar7[3] = (char)((uint)param_2 >> 8);
  local_68 = 0;
  uStack_60 = 0;
  puVar7[4] = (char)param_2;
  local_168 = (long ****)&local_168;
  local_160 = (long ****)&local_168;
  local_108 = local_110;
  memcpy(puVar7 + 5,param_3,(ulong)param_4);
  pppplVar5 = local_160;
  local_e0 = CONCAT44(local_e0._4_4_,iVar6);
  local_a8 = local_a8 & 0xfffffffffffffffb;
  local_f0 = puVar7;
  uVar8 = __list_add_valid(&local_78,local_160,&local_168);
  if ((uVar8 & 1) != 0) {
    pppplStack_70 = pppplVar5;
    local_160 = (long ****)&local_78;
    local_78 = (long ****)&local_168;
    *pppplVar5 = (long ***)&local_78;
  }
  iVar6 = spi_sync(param_1,&local_168);
  if (iVar6 == -0x6e) {
    Hint_Prefetch(0x129300,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(0x129300,0x10);
      if (bVar3) {
        cVar2 = ExclusiveMonitorsStatus();
        total_spi_write_timeouts = total_spi_write_timeouts + 1;
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    _printk(&DAT_00121ef1,"log_spi_timeout",0x36);
    Hint_Prefetch(0x129308,2,0,1);
    do {
      iVar1 = consecutive_write_timeouts + 1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(0x129308,0x10);
      if (bVar3) {
        cVar2 = ExclusiveMonitorsStatus();
        consecutive_write_timeouts = iVar1;
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if (2 < iVar1) {
      _printk(&DAT_00122717,"check_spi_timeout",0x65,"WRITE");
      queue_work_on(0x20,_system_wq,&restart_work);
    }
LAB_00104638:
    _printk(&DAT_001237ae,"goodix_spi_write",0x106,iVar6);
  }
  else {
    if (iVar6 < 0) goto LAB_00104638;
    if (0 < consecutive_write_timeouts) {
      consecutive_write_timeouts = 0;
    }
  }
  kfree(puVar7);
LAB_00104554:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// goodix_pdev_release @ 001046b0 size=60
// signature: undefined goodix_pdev_release(void)
// callers: []
//------------------------------------------------------------

void goodix_pdev_release(void)

{
  _printk(&DAT_00125368,"goodix_pdev_release",0x10e);
  kfree(goodix_pdev);
  return;
}



//------------------------------------------------------------
// goodix_register_ext_module @ 00104704 size=212
// signature: undefined goodix_register_ext_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 goodix_register_ext_module(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    return 0xffffffea;
  }
  _printk(&DAT_0011d444,"goodix_register_ext_module",0x8e);
  if (DAT_00129358 == '\0') {
    DAT_00129358 = '\x01';
    goodix_modules = &goodix_modules;
    DAT_00129350 = &goodix_modules;
    __mutex_init(&DAT_00129360,"&goodix_modules.mutex",&goodix_core_module_init___key);
  }
  *(undefined8 *)(param_1 + 0x90) = 0xfffffffe0;
  *(long *)(param_1 + 0x98) = param_1 + 0x98;
  *(long *)(param_1 + 0xa0) = param_1 + 0x98;
  uVar1 = _system_wq;
  *(code **)(param_1 + 0xa8) = goodix_register_ext_module_work;
  queue_work_on(0x20,uVar1,(undefined8 *)(param_1 + 0x90));
  _printk(&DAT_00122d3e,"goodix_register_ext_module",0x94);
  return 0;
}



//------------------------------------------------------------
// goodix_register_ext_module_work @ 001047dc size=168
// signature: undefined goodix_register_ext_module_work(void)
// callers: []
//------------------------------------------------------------

void goodix_register_ext_module_work(long param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  
  _printk(&DAT_0011f6a0,"goodix_register_ext_module_work",0x69);
  if (core_module_prob_sate == 1) {
    iVar1 = __do_register_ext_module(param_1 + -0x90);
    if (iVar1 == 0) {
      puVar2 = &DAT_001202d2;
      uVar3 = 0x74;
    }
    else {
      puVar2 = &DAT_00127a20;
      uVar3 = 0x72;
    }
    _printk(puVar2,"goodix_register_ext_module_work",uVar3,*(undefined8 *)(param_1 + -0x80));
  }
  else {
    _printk(&DAT_0011f0d5,"goodix_register_ext_module_work",0x6d);
  }
  return;
}



//------------------------------------------------------------
// goodix_register_ext_module_no_wait @ 00104888 size=184
// signature: undefined goodix_register_ext_module_no_wait(void)
// callers: [goodix_gesture_enable, gsx_gesture_enable_store, goodix_tools_open]
//------------------------------------------------------------

undefined8 goodix_register_ext_module_no_wait(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 != 0) {
    _printk(&DAT_00124817,"goodix_register_ext_module_no_wait",0xa0);
    if (DAT_00129358 == '\0') {
      DAT_00129358 = '\x01';
      goodix_modules = &goodix_modules;
      DAT_00129350 = &goodix_modules;
      __mutex_init(&DAT_00129360,"&goodix_modules.mutex",&goodix_core_module_init___key);
    }
    if (core_module_prob_sate == 1) {
      uVar1 = __do_register_ext_module(param_1);
      return uVar1;
    }
    _printk(&DAT_0011f0d5,"goodix_register_ext_module_no_wait",0xa4);
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// __do_register_ext_module @ 00104940 size=448
// signature: undefined __do_register_ext_module(void)
// callers: [goodix_register_ext_module_work, goodix_register_ext_module_no_wait]
//------------------------------------------------------------

undefined8 __do_register_ext_module(long *param_1)

{
  undefined *puVar1;
  long *plVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  code *pcVar6;
  long *plVar7;
  long lVar8;
  
  if ((int)param_1[3] == 0) {
    _printk(&DAT_00127a4f,"__do_register_ext_module",0x39,param_1[2]);
    return 0xffffffea;
  }
  mutex_lock(&DAT_00129360);
  plVar7 = (long *)&goodix_modules;
  if ((long **)goodix_modules != &goodix_modules) {
    plVar7 = goodix_modules;
    while (plVar2 = goodix_modules, (long **)plVar7 != &goodix_modules) {
      bVar3 = plVar7 == param_1;
      plVar7 = (long *)*plVar7;
      if (bVar3) {
        _printk(&DAT_0012633c,"__do_register_ext_module",0x43,param_1[2]);
        mutex_unlock(&DAT_00129360);
        return 0;
      }
    }
    do {
      plVar7 = plVar2;
      if ((long **)plVar7 == &goodix_modules) {
        plVar7 = (long *)&goodix_modules;
        break;
      }
      plVar2 = (long *)*plVar7;
    } while (*(uint *)(plVar7 + 3) < *(uint *)(param_1 + 3));
  }
  if (((undefined8 *)param_1[4] != (undefined8 *)0x0) &&
     (pcVar6 = *(code **)param_1[4], pcVar6 != (code *)0x0)) {
    if (*(int *)(pcVar6 + -4) != 0x23b90bb5) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1049d8);
      (*pcVar6)();
    }
    iVar4 = (*pcVar6)(DAT_00129398,param_1);
    if (iVar4 < 0) {
      puVar1 = &DAT_00124e49;
      if ((undefined *)param_1[2] != (undefined *)0x0) {
        puVar1 = (undefined *)param_1[2];
      }
      _printk(&DAT_0011f6cc,"__do_register_ext_module",0x57,puVar1);
      mutex_unlock(&DAT_00129360);
      return 0xfffffff2;
    }
  }
  plVar7 = (long *)plVar7[1];
  lVar8 = *plVar7;
  uVar5 = __list_add_valid(param_1,plVar7,lVar8);
  if ((uVar5 & 1) != 0) {
    *(long **)(lVar8 + 8) = param_1;
    *param_1 = lVar8;
    param_1[1] = (long)plVar7;
    *plVar7 = (long)param_1;
  }
  mutex_unlock(&DAT_00129360);
  _printk(&DAT_0012231b,"__do_register_ext_module",0x61,param_1[2],(int)param_1[3]);
  return 0;
}



//------------------------------------------------------------
// goodix_unregister_ext_module @ 00104b04 size=352
// signature: undefined goodix_unregister_ext_module(void)
// callers: [gesture_module_exit, goodix_gesture_enable, goodix_tools_release, gsx_gesture_enable_store]
//------------------------------------------------------------

undefined8 goodix_unregister_ext_module(long *param_1)

{
  undefined *puVar1;
  long lVar2;
  bool bVar3;
  undefined8 uVar4;
  ulong uVar5;
  long *plVar6;
  code *pcVar7;
  
  uVar4 = 0xffffffea;
  if ((param_1 != (long *)0x0) && (DAT_00129358 != '\0')) {
    if (DAT_00129398 == 0) {
      uVar4 = 0xffffffed;
    }
    else {
      mutex_lock(&DAT_00129360);
      plVar6 = goodix_modules;
      if ((long **)goodix_modules == &goodix_modules) {
LAB_00104c20:
        mutex_unlock(&DAT_00129360);
      }
      else {
        do {
          if ((long **)plVar6 == &goodix_modules) {
            if (debug_log_flag != '\0') {
              _printk(&DAT_00126ec3,"goodix_unregister_ext_module",0xcf,param_1[2]);
            }
            goto LAB_00104c20;
          }
          bVar3 = plVar6 != param_1;
          plVar6 = (long *)*plVar6;
        } while (bVar3);
        uVar5 = __list_del_entry_valid(param_1);
        if ((uVar5 & 1) != 0) {
          lVar2 = *param_1;
          plVar6 = (long *)param_1[1];
          *(long **)(lVar2 + 8) = plVar6;
          *plVar6 = lVar2;
        }
        *param_1 = -0x2152ffffffffff00;
        param_1[1] = -0x2152fffffffffede;
        mutex_unlock(&DAT_00129360);
        if ((param_1[4] != 0) && (pcVar7 = *(code **)(param_1[4] + 8), pcVar7 != (code *)0x0)) {
          if (*(int *)(pcVar7 + -4) != 0x23b90bb5) {
                    /* WARNING: Does not return */
            pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x104bd8);
            (*pcVar7)();
          }
          (*pcVar7)(DAT_00129398,param_1);
        }
        puVar1 = &DAT_00124e49;
        if ((undefined *)param_1[2] != (undefined *)0x0) {
          puVar1 = (undefined *)param_1[2];
        }
        _printk(&DAT_0012630f,"goodix_unregister_ext_module",0xdb,puVar1);
      }
      uVar4 = 0;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// goodix_get_default_ktype @ 00104c68 size=12
// signature: undefined goodix_get_default_ktype(void)
// callers: [gesture_module_init]
//------------------------------------------------------------

undefined ** goodix_get_default_ktype(void)

{
  return &goodix_ext_ktype;
}



//------------------------------------------------------------
// goodix_get_default_kobj @ 00104c78 size=40
// signature: undefined goodix_get_default_kobj(void)
// callers: [inspect_module_exit, inspect_module_init, gesture_module_init]
//------------------------------------------------------------

long goodix_get_default_kobj(void)

{
  long lVar1;
  
  if (DAT_00129398 == 0) {
    return 0;
  }
  lVar1 = 0;
  if (*(long *)(DAT_00129398 + 8) != 0) {
    lVar1 = *(long *)(DAT_00129398 + 8) + 0x10;
  }
  return lVar1;
}



//------------------------------------------------------------
// goodix_ts_register_notifier @ 00104ca4 size=40
// signature: undefined goodix_ts_register_notifier(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_register_notifier(undefined8 param_1)

{
  blocking_notifier_chain_register(ts_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// goodix_ts_unregister_notifier @ 00104cd0 size=40
// signature: undefined goodix_ts_unregister_notifier(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_unregister_notifier(undefined8 param_1)

{
  blocking_notifier_chain_unregister(ts_notifier_list,param_1);
  return;
}



//------------------------------------------------------------
// goodix_ts_blocking_notify @ 00104cfc size=44
// signature: undefined goodix_ts_blocking_notify(void)
// callers: [goodix_ts_mmi_pre_suspend, goodix_ts_mmi_post_resume, goodix_do_inspect, goodix_fw_update_thread, goodix_tools_ioctl, brl_get_capacitance_data, goodix_tools_release, goodix_tools_open]
//------------------------------------------------------------

void goodix_ts_blocking_notify(undefined4 param_1,undefined8 param_2)

{
  blocking_notifier_call_chain(ts_notifier_list,param_1,param_2);
  return;
}



//------------------------------------------------------------
// goodix_ts_power_on @ 00104d2c size=188
// signature: undefined goodix_ts_power_on(void)
// callers: [goodix_ts_probe, goodix_ts_esd_work, goodix_ts_mmi_methods_power]
//------------------------------------------------------------

int goodix_ts_power_on(long param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  
  _printk(&DAT_0011eb8c,"goodix_ts_power_on",0x65e);
  if (*(int *)(param_1 + 0x4a0) == 0) {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x2d0) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104d98);
      (*pcVar1)();
    }
    iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x2d0))(param_1,1);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x4a0) = 1;
      uVar3 = ktime_get();
      *(undefined8 *)(param_1 + 0x4a8) = uVar3;
    }
    else {
      _printk(&DAT_0012335d,"goodix_ts_power_on",0x668,iVar2);
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



//------------------------------------------------------------
// goodix_ts_power_off @ 00104dec size=168
// signature: undefined goodix_ts_power_off(void)
// callers: [goodix_ts_esd_work, goodix_ts_mmi_methods_power]
//------------------------------------------------------------

int goodix_ts_power_off(long param_1)

{
  code *pcVar1;
  int iVar2;
  
  _printk(&DAT_00126942,"goodix_ts_power_off",0x675);
  if (*(int *)(param_1 + 0x4a0) == 0) {
    iVar2 = 0;
  }
  else {
    if (*(int *)((code *)**(undefined8 **)(param_1 + 0x2d0) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104e48);
      (*pcVar1)();
    }
    iVar2 = (*(code *)**(undefined8 **)(param_1 + 0x2d0))(param_1,0);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0x4a0) = 0;
    }
    else {
      _printk(&DAT_001208f5,"goodix_ts_power_off",0x67d,iVar2);
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// goodix_ts_input_dev_remove @ 00104e98 size=60
// signature: undefined goodix_ts_input_dev_remove(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_input_dev_remove(long param_1)

{
  if (*(long *)(param_1 + 0x2d8) != 0) {
    input_unregister_device();
    input_free_device(*(undefined8 *)(param_1 + 0x2d8));
    *(undefined8 *)(param_1 + 0x2d8) = 0;
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_pen_dev_remove @ 00104ed8 size=60
// signature: undefined goodix_ts_pen_dev_remove(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_pen_dev_remove(long param_1)

{
  if (*(long *)(param_1 + 0x2e0) != 0) {
    input_unregister_device();
    input_free_device(*(undefined8 *)(param_1 + 0x2e0));
    *(undefined8 *)(param_1 + 0x2e0) = 0;
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_esd_init @ 00104f18 size=280
// signature: undefined goodix_ts_esd_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 goodix_ts_esd_init(long param_1)

{
  ulong uVar1;
  undefined *puVar2;
  char *pcVar3;
  undefined8 uVar4;
  
  if ((*(long *)(*(long *)(param_1 + 0x2d0) + 0x70) == 0) || (*(int *)(param_1 + 0xf7) == 0)) {
    puVar2 = &DAT_0012029f;
    pcVar3 = "goodix_ts_esd_init";
    uVar4 = 0x82a;
  }
  else {
    *(undefined8 *)(param_1 + 0x508) = 0xfffffffe0;
    *(long *)(param_1 + 0x510) = param_1 + 0x510;
    *(long *)(param_1 + 0x518) = param_1 + 0x510;
    *(code **)(param_1 + 0x520) = goodix_ts_esd_work;
    init_timer_key(param_1 + 0x538,&delayed_work_timer_fn,0x200000,0,0);
    *(long *)(param_1 + 0x5a8) = param_1;
    *(undefined4 *)(param_1 + 0x504) = 0;
    *(code **)(param_1 + 0x590) = goodix_esd_notifier_callback;
    blocking_notifier_chain_register(ts_notifier_list,param_1 + 0x590);
    if (*(int *)(param_1 + 0xf7) == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x504) != 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x504) = 1;
    uVar1 = queue_delayed_work_on(0x20,_system_wq,param_1 + 0x508,0xfa);
    if ((uVar1 & 1) == 0) {
      _printk(&DAT_00122da0,"goodix_ts_esd_on",0x7ea);
    }
    puVar2 = &DAT_0011d476;
    pcVar3 = "goodix_ts_esd_on";
    uVar4 = 0x7ec;
  }
  _printk(puVar2,pcVar3,uVar4);
  return 0;
}



//------------------------------------------------------------
// goodix_ts_esd_work @ 00105034 size=208
// signature: undefined goodix_ts_esd_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void goodix_ts_esd_work(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  if (*(char *)(param_1 + -8) == '\0') {
    if (*(int *)(param_1 + -4) == 0) {
      return;
    }
    pcVar2 = *(code **)(*(long *)(param_1 + -0x238) + 0x70);
    if (pcVar2 == (code *)0x0) {
      return;
    }
    lVar3 = param_1 + -0x508;
    if (*(int *)(pcVar2 + -4) != 0x1c1b2b73) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1050b0);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(lVar3);
    if (iVar1 != 0) {
      _printk(&DAT_00123c4e,"goodix_ts_esd_work",0x7ce);
      goodix_ts_power_off(lVar3);
      usleep_range_state(5000,0x13ec,2);
      goodix_ts_power_on(lVar3);
    }
  }
  *(undefined1 *)(param_1 + -8) = 0;
  if (*(int *)(param_1 + -4) != 0) {
    queue_delayed_work_on(0x20,_system_wq,param_1,0xfa);
  }
  return;
}



//------------------------------------------------------------
// goodix_esd_notifier_callback @ 00105108 size=220
// signature: undefined goodix_esd_notifier_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 goodix_esd_notifier_callback(long param_1,ulong param_2)

{
  uint uVar1;
  ulong uVar2;
  long lVar3;
  
  if (param_2 < 7) {
    if ((1L << (param_2 & 0x3f) & 0x56U) == 0) {
      lVar3 = *(long *)(param_1 + 0x18);
      if (*(int *)(lVar3 + 0x504) != 0) {
        *(undefined4 *)(lVar3 + 0x504) = 0;
        uVar1 = cancel_delayed_work_sync(lVar3 + 0x508);
        _printk(&DAT_001237d8,"goodix_ts_esd_off",0x7fc,uVar1 & 1);
      }
    }
    else {
      lVar3 = *(long *)(param_1 + 0x18);
      if ((*(int *)(lVar3 + 0xf7) != 0) && (*(int *)(lVar3 + 0x504) == 0)) {
        *(undefined4 *)(lVar3 + 0x504) = 1;
        uVar2 = queue_delayed_work_on(0x20,_system_wq,lVar3 + 0x508,0xfa);
        if ((uVar2 & 1) == 0) {
          _printk(&DAT_00122da0,"goodix_ts_esd_on",0x7ea);
        }
        _printk(&DAT_0011d476,"goodix_ts_esd_on",0x7ec);
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// goodix_ts_release_connects @ 001051e8 size=524
// signature: undefined goodix_ts_release_connects(void)
// callers: [goodix_ts_mmi_post_suspend]
//------------------------------------------------------------

void goodix_ts_release_connects(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x2d8);
  if (lVar1 == 0) {
    _printk(&DAT_00126967,"goodix_ts_release_connects",0x83f);
  }
  else {
    mutex_lock(lVar1 + 0x208);
    input_event(lVar1,3,0x2f,0);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,1);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,2);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,3);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,4);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,5);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,6);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,7);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,8);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,3,0x2f,9);
    input_mt_report_slot_state(lVar1,0,0);
    input_event(lVar1,1,0x14a,0);
    input_mt_sync_frame(lVar1);
    input_event(lVar1,0,0,0);
    memset((void *)(param_1 + 0x2e8),0,0x13c);
    mutex_unlock(lVar1 + 0x208);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_stage2_init @ 001053f8 size=1188
// signature: undefined goodix_ts_stage2_init(void)
// callers: [goodix_later_init_thread]
//------------------------------------------------------------

int goodix_ts_stage2_init(long param_1)

{
  int iVar1;
  undefined8 *puVar2;
  long lVar3;
  
  puVar2 = (undefined8 *)input_allocate_device();
  if (puVar2 == (undefined8 *)0x0) {
    _printk(&DAT_00122dd2,"goodix_ts_input_dev_config",0x733);
    iVar1 = -0xc;
LAB_00105578:
    _printk(&DAT_001212b3,"goodix_ts_stage2_init",0x999);
    return iVar1;
  }
  *(undefined8 **)(param_1 + 0x2d8) = puVar2;
  *puVar2 = "goodix_ts";
  puVar2[1] = "goodix_ts/input0";
  *(undefined4 *)((long)puVar2 + 0x1a) = 0xdeadbeef;
  *(undefined2 *)((long)puVar2 + 0x1e) = 0x28bb;
  puVar2[0xb] = puVar2[0xb] | 0x420;
  lVar3 = 0;
  if (param_1 != 0) {
    lVar3 = param_1 + 0x108;
  }
  puVar2[0x5b] = param_1;
  puVar2[4] = puVar2[4] | 2;
  puVar2[5] = puVar2[5] | 0xb;
  input_set_abs_params(puVar2,0x35,0,*(undefined4 *)(lVar3 + 0xdc),0,0);
  input_set_abs_params(puVar2,0x36,0,*(undefined4 *)(lVar3 + 0xe0),0,0);
  input_set_abs_params(puVar2,0x30,0,*(undefined4 *)(lVar3 + 0xe4),0,0);
  input_set_abs_params(puVar2,0x37,0,2,0,0);
  input_mt_init_slots(puVar2,10,2);
  input_set_capability(puVar2,1,0x74);
  input_set_capability(puVar2,1,0x2c0);
  input_set_capability(puVar2,1,0x2c1);
  iVar1 = input_register_device(puVar2);
  if (iVar1 < 0) {
    _printk(&DAT_00124103,"goodix_ts_input_dev_config",0x76a);
    input_free_device(puVar2);
    goto LAB_00105578;
  }
  if (*(char *)(param_1 + 500) == '\0') {
LAB_001055b0:
    gpio_to_desc(*(undefined4 *)(lVar3 + 0xc4));
    iVar1 = gpiod_to_irq();
    *(int *)(param_1 + 0x4b8) = iVar1;
    if (iVar1 < 0) {
      _printk(&DAT_001257eb,"goodix_ts_irq_setup",0x60c,iVar1);
      iVar1 = -0x16;
    }
    else {
      _printk(&DAT_001212df,"goodix_ts_irq_setup",0x610,iVar1,*(undefined4 *)(lVar3 + 0xd4));
      iVar1 = devm_request_threaded_irq
                        (*(long *)(param_1 + 8) + 0x10,*(undefined4 *)(param_1 + 0x4b8),0,
                         goodix_ts_threadirq_func,*(uint *)(lVar3 + 0xd4) | 0x2000,"goodix_ts",
                         param_1);
      if (-1 < iVar1) {
        *(undefined4 *)(param_1 + 0x4cc) = 1;
        _printk(&DAT_00124851,"goodix_ts_stage2_init",0x9aa);
        iVar1 = sysfs_create_group(*(long *)(param_1 + 8) + 0x10,sysfs_group);
        if (iVar1 != 0) {
          _printk(&DAT_0012641d,"goodix_ts_sysfs_init",0x330);
        }
        lVar3 = proc_mkdir("goodix_ts",0);
        if (lVar3 != 0) {
          proc_create_data("goodix_ts/tp_capacitance_data",0x1b6,0,rawdata_proc_fops,param_1);
        }
        gesture_module_init();
        inspect_module_init();
        return 0;
      }
      _printk(&DAT_0012092f,"goodix_ts_irq_setup",0x618,iVar1);
    }
    _printk(&DAT_00126990,"goodix_ts_stage2_init",0x9a7);
    if (*(long *)(param_1 + 0x2e0) != 0) {
      input_unregister_device();
      input_free_device(*(undefined8 *)(param_1 + 0x2e0));
      *(undefined8 *)(param_1 + 0x2e0) = 0;
    }
  }
  else {
    puVar2 = (undefined8 *)input_allocate_device();
    if (puVar2 == (undefined8 *)0x0) {
      _printk(&DAT_00126386,"goodix_ts_pen_dev_config",0x77a);
      iVar1 = -0xc;
    }
    else {
      *(undefined8 **)(param_1 + 0x2e0) = puVar2;
      *(undefined4 *)((long)puVar2 + 0x1a) = 0xdeadbeef;
      *puVar2 = "goodix_ts,pen";
      puVar2[0x13] = puVar2[0x13] | 0xc000003;
      puVar2[0xb] = puVar2[0xb] | 0x1c01;
      puVar2[0x5b] = param_1;
      *(undefined2 *)((long)puVar2 + 0x1e) = 0x28bb;
      puVar2[4] = puVar2[4] | 2;
      puVar2[5] = puVar2[5] | 10;
      input_set_abs_params(puVar2,0,0,*(undefined4 *)(lVar3 + 0xdc),0,0);
      input_set_abs_params(puVar2,1,0,*(undefined4 *)(lVar3 + 0xe0),0,0);
      input_set_abs_params(puVar2,0x18,0,*(undefined4 *)(lVar3 + 0xe8),0,0);
      input_set_abs_params(puVar2,0x1a,0xffffffa6,0x5a,0,0);
      input_set_abs_params(puVar2,0x1b,0xffffffa6,0x5a,0,0);
      iVar1 = input_register_device(puVar2);
      if (-1 < iVar1) goto LAB_001055b0;
      _printk(&DAT_0012033f,"goodix_ts_pen_dev_config",0x79b);
      input_free_device(puVar2);
    }
    _printk(&DAT_0012751a,"goodix_ts_stage2_init",0x9a0);
  }
  if (*(long *)(param_1 + 0x2d8) == 0) {
    return iVar1;
  }
  input_unregister_device();
  input_free_device(*(undefined8 *)(param_1 + 0x2d8));
  *(undefined8 *)(param_1 + 0x2d8) = 0;
  return iVar1;
}



//------------------------------------------------------------
// goodix_ext_sysfs_release @ 001058a0 size=48
// signature: undefined goodix_ext_sysfs_release(void)
// callers: []
//------------------------------------------------------------

void goodix_ext_sysfs_release(void)

{
  _printk(&DAT_0011da81,"goodix_ext_sysfs_release",0xe1);
  return;
}



//------------------------------------------------------------
// goodix_ext_sysfs_show @ 001058d4 size=76
// signature: undefined goodix_ext_sysfs_show(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ext_sysfs_show(long param_1,long param_2,undefined8 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x7363fea8) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x105908);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1 + -0x30,param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// goodix_ext_sysfs_store @ 00105924 size=80
// signature: undefined goodix_ext_sysfs_store(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ext_sysfs_store(long param_1,long param_2,undefined8 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x74e63607) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10595c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1 + -0x30,param_3,param_4);
  }
  return uVar1;
}



//------------------------------------------------------------
// goodix_ts_threadirq_func @ 00105978 size=2084
// signature: undefined goodix_ts_threadirq_func(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_threadirq_func(undefined8 param_1,long param_2)

{
  long *plVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  undefined1 uVar5;
  int iVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  long lVar12;
  int *piVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  long lVar16;
  long lVar17;
  long lVar18;
  ulong uVar19;
  undefined8 local_90;
  undefined8 local_88;
  ulong local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar18 = sp_el0;
  local_68 = *(long *)(lVar18 + 0x638);
  lVar18 = *(long *)(param_2 + 0x2d0);
  cpu_latency_qos_update_request(param_2 + 0x5b0,0);
  *(undefined1 *)(param_2 + 0x500) = 1;
  *(long *)(param_2 + 0x4c0) = *(long *)(param_2 + 0x4c0) + 1;
  mutex_lock(&DAT_00129360);
  puVar14 = goodix_modules;
  do {
    do {
      if ((undefined8 **)puVar14 == &goodix_modules) {
        piVar2 = (int *)(param_2 + 0x2e8);
        mutex_unlock(&DAT_00129360);
        pcVar11 = *(code **)(lVar18 + 0x78);
        if (*(int *)(pcVar11 + -4) != 0x2bf9e380) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105a24);
          (*pcVar11)();
        }
        iVar6 = (*pcVar11)(param_2,piVar2);
        lVar16 = DAT_00129398;
        if (iVar6 != 0) goto LAB_00105ec0;
        if (*(int *)(param_2 + 0x2ec) != 1) goto LAB_00105d2c;
        lVar17 = *(long *)(param_2 + 0x2d8);
        iVar6 = *(int *)(param_2 + 0x2f4);
        mutex_lock();
        uVar19 = 0;
        puVar15 = (undefined4 *)(param_2 + 0x30c);
        goto LAB_00105b30;
      }
      plVar1 = puVar14 + 4;
      puVar14 = (undefined8 *)*puVar14;
      pcVar11 = *(code **)(*plVar1 + 0x40);
    } while (pcVar11 == (code *)0x0);
    if (*(int *)(pcVar11 + -4) != 0x23b90bb5) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105aac);
      (*pcVar11)();
    }
    iVar6 = (*pcVar11)(param_2);
  } while (iVar6 != 1);
  mutex_unlock(&DAT_00129360);
  goto LAB_0010615c;
LAB_00105b30:
  do {
    bVar3 = *(byte *)(param_2 + 0x2f8);
    if (puVar15[-4] == 2) {
      if (debug_log_flag == '\0') {
        if ((&goodix_ts_report_finger_touchdown)[uVar19] != '\0') goto LAB_00105b54;
LAB_00105bd4:
        uVar8 = ktime_get_with_offset(1);
        cVar4 = debug_log_flag;
        *(undefined8 *)(lVar16 + 0x6b0) = uVar8;
        if (cVar4 != '\0') {
          _printk(&DAT_0011d491,"goodix_ts_report_finger",0x54f,uVar19 & 0xffffffff);
        }
        uVar10 = 1;
        (&goodix_ts_report_finger_touchdown)[uVar19] = 1;
        lVar12 = *(long *)(lVar16 + 0x680);
      }
      else {
        _printk(&DAT_00123c73,"goodix_ts_report_finger",0x546,uVar19 & 0xffffffff,puVar15[-2],
                puVar15[-1],*puVar15,puVar15[-3],(uint)bVar3 << 1);
        if ((&goodix_ts_report_finger_touchdown)[uVar19] == '\0') goto LAB_00105bd4;
LAB_00105b54:
        uVar10 = 3;
        lVar12 = *(long *)(lVar16 + 0x680);
      }
      if ((lVar12 != 0) && (pcVar11 = *(code **)(lVar12 + 0x30), pcVar11 != (code *)0x0)) {
        local_78 = 0;
        local_70 = 0;
        local_88 = CONCAT44(puVar15[-2],(int)uVar19);
        local_80 = (ulong)(uint)puVar15[-1];
        local_90 = (ulong)uVar10 << 0x20;
        if (*(int *)(pcVar11 + -4) != -0x302b3af3) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8229,0x105c48);
          (*pcVar11)();
        }
        (*pcVar11)(*(undefined8 *)(*(long *)(lVar16 + 0x100) + 8),&local_90,lVar17);
        if ((char)local_90 != '\0') {
          iVar6 = iVar6 - (uint)(local_90._4_4_ == 4);
          goto LAB_00105b20;
        }
      }
      input_event(lVar17,3,0x2f,uVar19 & 0xffffffff);
      if (bVar3 == 0) {
        uVar9 = 0;
        if (puVar15[-3] != 0) {
          uVar9 = 2;
        }
      }
      else {
        uVar9 = 2;
      }
      input_mt_report_slot_state(lVar17,uVar9,1);
      input_event(lVar17,3,0x35,puVar15[-2]);
      input_event(lVar17,3,0x36,puVar15[-1]);
      input_event(lVar17,3,0x30,*puVar15);
    }
    else if ((&goodix_ts_report_finger_touchdown)[uVar19] == '\x01') {
      if (debug_log_flag != '\0') {
        _printk(&DAT_001219b5,"goodix_ts_report_finger",0x584,uVar19 & 0xffffffff);
      }
      (&goodix_ts_report_finger_touchdown)[uVar19] = 0;
      input_event(lVar17,3,0x2f,uVar19 & 0xffffffff);
      input_mt_report_slot_state(lVar17,(ulong)bVar3 << 1,0);
    }
LAB_00105b20:
    uVar19 = uVar19 + 1;
    puVar15 = puVar15 + 6;
  } while (uVar19 != 10);
  input_event(lVar17,1,0x14a,iVar6 != 0);
  input_event(lVar17,0,0,0);
  if (*(int *)(lVar16 + 0x6a8) != 0) {
    if ((*(char *)(lVar16 + 0x2f1) == 'F') && (iVar6 != 0)) {
      input_event(lVar17,1,0x2c0,1);
      input_event(lVar17,0,0,0);
      input_event(lVar17,1,0x2c0,0);
      input_event(lVar17,0,0,0);
      puVar7 = &DAT_00122352;
      uVar8 = 0x599;
    }
    else {
      if (*(char *)(lVar16 + 0x2f1) != 'U') goto joined_r0x00105d1c;
      input_event(lVar17,1,0x2c1,1);
      input_event(lVar17,0,0,0);
      input_event(lVar17,1,0x2c1,0);
      input_event(lVar17,0,0,0);
      puVar7 = &DAT_0011e0ae;
      uVar8 = 0x59f;
    }
    _printk(puVar7,"goodix_ts_report_finger",uVar8);
  }
joined_r0x00105d1c:
  if (debug_log_flag != '\0') {
    _printk(&DAT_00125d89,"goodix_ts_report_finger",0x5a3,*(undefined4 *)(lVar16 + 0x6a8),
            *(undefined1 *)(lVar16 + 0x2f1),iVar6);
  }
  mutex_unlock(lVar17 + 0x208);
LAB_00105d2c:
  if (*(char *)(param_2 + 500) == '\0') {
LAB_00105eb4:
    iVar6 = *(int *)(param_2 + 0x2ec);
  }
  else {
    iVar6 = *(int *)(param_2 + 0x2ec);
    if (iVar6 == 2) {
      lVar16 = *(long *)(param_2 + 0x2e0);
      mutex_lock(lVar16 + 0x208);
      if (*(int *)(param_2 + 0x3ec) == 2) {
        input_event(lVar16,1,0x14a,1);
        input_event(lVar16,1,*(undefined4 *)(param_2 + 0x3f0),1);
        input_event(lVar16,3,0,*(undefined4 *)(param_2 + 0x3f4));
        input_event(lVar16,3,1,*(undefined4 *)(param_2 + 0x3f8));
        input_event(lVar16,3,0x18,*(undefined4 *)(param_2 + 0x3fc));
        input_event(lVar16,3,0x1a,(long)*(char *)(param_2 + 0x400));
        input_event(lVar16,3,0x1b,(long)*(char *)(param_2 + 0x401));
        if (debug_log_flag != '\0') {
          _printk(&DAT_00121303,"goodix_ts_report_pen",0x512,*(undefined4 *)(param_2 + 0x3f4),
                  *(undefined4 *)(param_2 + 0x3f8),*(undefined4 *)(param_2 + 0x3fc),
                  (long)*(char *)(param_2 + 0x400),(long)*(char *)(param_2 + 0x401),
                  *(int *)(param_2 + 0x404) == 2,*(int *)(param_2 + 0x40c) == 2);
        }
      }
      else {
        input_event(lVar16,1,0x14a,0);
        input_event(lVar16,1,*(undefined4 *)(param_2 + 0x3f0),0);
      }
      input_event(lVar16,1,*(undefined4 *)(param_2 + 0x408),*(int *)(param_2 + 0x404) == 2);
      input_event(lVar16,1,*(undefined4 *)(param_2 + 0x410),*(int *)(param_2 + 0x40c) == 2);
      input_event(lVar16,0,0,0);
      mutex_unlock(lVar16 + 0x208);
      goto LAB_00105eb4;
    }
  }
  if (iVar6 == 4) {
    if (*(char *)(param_2 + 0x2f0) == '\x03') {
      pcVar11 = *(code **)(*(long *)(param_2 + 0x2d0) + 0x28);
      if (*(int *)(pcVar11 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
        pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105f64);
        (*pcVar11)();
      }
      iVar6 = (*pcVar11)(param_2,100);
      if (iVar6 == 0) goto LAB_00106128;
LAB_00105f88:
      uVar5 = *(undefined1 *)(param_2 + 0x2f0);
      puVar7 = &DAT_001263ee;
      uVar8 = 0x5b8;
    }
    else {
      if (*(char *)(param_2 + 0x2f0) != '\x01') {
        _printk(&DAT_001263b9,"goodix_ts_request_handle",0x5b5);
        goto LAB_00105f88;
      }
      piVar13 = *(int **)(param_2 + 0x430);
      if ((piVar13 == (int *)0x0) || (*piVar13 < 1)) {
        _printk(&DAT_00120371,"goodix_send_ic_config",0x9dc);
        goto LAB_00105f88;
      }
      iVar6 = goodix_get_file_config_id(piVar13 + 1);
      if (*(int *)(param_2 + 0x32) == iVar6) {
        _printk(&DAT_0011f10e,"goodix_send_ic_config",0x9e2,iVar6);
      }
      else {
        _printk(&DAT_001219f3,"goodix_send_ic_config",0x9e6,iVar6);
        pcVar11 = *(code **)(*(long *)(param_2 + 0x2d0) + 0x50);
        if (*(int *)(pcVar11 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
          pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x106120);
          (*pcVar11)();
        }
        iVar6 = (*pcVar11)(param_2,piVar13 + 1,*piVar13);
        if (iVar6 != 0) goto LAB_00105f88;
      }
LAB_00106128:
      uVar5 = *(undefined1 *)(param_2 + 0x2f0);
      puVar7 = &DAT_00123807;
      uVar8 = 0x5bb;
    }
    _printk(puVar7,"goodix_ts_request_handle",uVar8,uVar5);
    cVar4 = *(char *)(param_2 + 0x4d8);
  }
  else {
LAB_00105ec0:
    cVar4 = *(char *)(param_2 + 0x4d8);
  }
  if ((cVar4 == '\0') && (*piVar2 == 0)) {
    pcVar11 = *(code **)(lVar18 + 0x80);
    if (*(int *)(pcVar11 + -4) != 0x1c1b2b73) {
                    /* WARNING: Does not return */
      pcVar11 = (code *)SoftwareBreakpoint(0x8228,0x105ef0);
      (*pcVar11)();
    }
    (*pcVar11)(param_2);
  }
  *piVar2 = 0;
  cpu_latency_qos_update_request(param_2 + 0x5b0,0xffffffff);
LAB_0010615c:
  lVar18 = sp_el0;
  if (*(long *)(lVar18 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// goodix_send_ic_config @ 0010619c size=228
// signature: undefined goodix_send_ic_config(void)
// callers: [goodix_generic_noti_callback]
//------------------------------------------------------------

undefined8 goodix_send_ic_config(long param_1)

{
  int iVar1;
  undefined8 uVar2;
  code *pcVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x430);
  if ((piVar4 == (int *)0x0) || (*piVar4 < 1)) {
    _printk(&DAT_00120371,"goodix_send_ic_config",0x9dc);
    uVar2 = 0xffffffea;
  }
  else {
    iVar1 = goodix_get_file_config_id(piVar4 + 1);
    if (*(int *)(param_1 + 0x32) == iVar1) {
      _printk(&DAT_0011f10e,"goodix_send_ic_config",0x9e2,iVar1);
      uVar2 = 0;
    }
    else {
      _printk(&DAT_001219f3,"goodix_send_ic_config",0x9e6,iVar1);
      pcVar3 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x50);
      if (*(int *)(pcVar3 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106278);
        (*pcVar3)();
      }
      uVar2 = (*pcVar3)(param_1,piVar4 + 1,*piVar4);
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// goodix_ts_driver_info_show @ 00106284 size=56
// signature: undefined goodix_ts_driver_info_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_driver_info_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"DriverVersion:%s\n","v1.2.3");
  return (long)iVar1;
}



//------------------------------------------------------------
// goodix_ts_chip_info_show @ 001062c0 size=420
// signature: undefined goodix_ts_chip_info_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_chip_info_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  local_68 = 0;
  lVar6 = *(long *)(lVar5 + 0x2d0);
  pcVar4 = *(code **)(lVar6 + 0x60);
  if (pcVar4 != (code *)0x0) {
    if (*(int *)(pcVar4 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10632c);
      (*pcVar4)();
    }
    iVar1 = (*pcVar4)(lVar5,&local_68);
    if (iVar1 == 0) {
      local_70._0_6_ = (undefined6)local_68;
      iVar2 = snprintf(param_3,0x1000,"rom_pid:%s\nrom_vid:%02x%02x%02x\n",(char *)&local_70,
                       (uint)local_68._6_1_,(uint)local_68._7_1_,(uint)(byte)local_60);
      iVar3 = snprintf(param_3 + iVar2,0x1000,"patch_pid:%s\npatch_vid:%02x%02x%02x%02x\n",
                       (char *)((long)&local_60 + 2),(uint)uStack_58._2_1_,(uint)uStack_58._3_1_,
                       (uint)uStack_58._4_1_,(uint)uStack_58._5_1_);
      iVar1 = snprintf(param_3 + (iVar3 + iVar2),0x1000,"sensorid:%d\n",(uint)uStack_58._7_1_);
      iVar1 = iVar1 + iVar3 + iVar2;
      pcVar4 = *(code **)(lVar6 + 0x68);
      goto joined_r0x0010633c;
    }
  }
  iVar1 = -0x16;
  pcVar4 = *(code **)(lVar6 + 0x68);
joined_r0x0010633c:
  if (pcVar4 != (code *)0x0) {
    if (*(int *)(pcVar4 + -4) != -0x2fa11135) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1063ec);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(lVar5,lVar5 + 0x2c);
    if (iVar2 == 0) {
      iVar2 = snprintf(param_3 + iVar1,0x1000,"config_id:%x\n",*(uint *)(lVar5 + 0x32));
      iVar3 = snprintf(param_3 + (iVar2 + iVar1),0x1000,"config_version:%x\n",
                       (uint)*(byte *)(lVar5 + 0x36));
      iVar1 = iVar3 + iVar2 + iVar1;
    }
  }
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// goodix_ts_reset_store @ 00106468 size=112
// signature: undefined goodix_ts_reset_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_reset_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = -0x16;
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    if (*param_3 != '0') {
      pcVar2 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x2d0) + 0x28);
      if (*(int *)(pcVar2 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1064c0);
        (*pcVar2)();
      }
      (*pcVar2)(*(long *)(param_1 + 0x98),100);
    }
    lVar1 = param_4;
  }
  return lVar1;
}



//------------------------------------------------------------
// goodix_ts_send_cfg_store @ 001064dc size=540
// signature: undefined goodix_ts_send_cfg_store(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void goodix_ts_send_cfg_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  code *pcVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  undefined4 *puVar6;
  long lVar7;
  int local_54;
  undefined4 *local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  lVar5 = *(long *)(param_1 + 0x98);
  local_50 = (undefined4 *)0x0;
  local_54 = 0;
  lVar7 = *(long *)(lVar5 + 0x2d0);
  iVar2 = sscanf(param_3,"%d",&local_54);
  uVar4 = 0xffffffffffffffea;
  if ((iVar2 != 1) || (local_54 != 1)) goto LAB_00106550;
  if (*(int *)(*(code **)(lVar7 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1065a4);
    (*pcVar1)();
  }
  (**(code **)(lVar7 + 0x30))(lVar5,0);
  iVar2 = request_firmware(&local_50,"goodix_cfg_group.cfg",param_1);
  if (iVar2 < 0) {
    _printk(&DAT_0011fd39,"goodix_ts_send_cfg_store",0x1d1,"goodix_cfg_group.cfg",iVar2);
    puVar6 = (undefined4 *)0x0;
  }
  else {
    _printk(&DAT_00122793,"goodix_ts_send_cfg_store",0x1d4,"goodix_cfg_group.cfg");
    puVar6 = (undefined4 *)kmalloc_trace(_queue_work_on,0xdc0,0x1004);
    if (puVar6 != (undefined4 *)0x0) {
      iVar2 = goodix_ts_convert_0x_data(*(undefined8 *)(local_50 + 2),*local_50,puVar6 + 1,puVar6);
      if (iVar2 == 0) {
        pcVar1 = *(code **)(lVar7 + 0x50);
        if (pcVar1 != (code *)0x0) {
          if (*(int *)(pcVar1 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x106674);
            (*pcVar1)();
          }
          iVar2 = (*pcVar1)(lVar5,puVar6 + 1,*puVar6);
          if (iVar2 < 0) {
            puVar3 = &DAT_0011e726;
            uVar4 = 0x1e4;
            goto LAB_001066ec;
          }
        }
      }
      else {
        puVar3 = &DAT_0011e6f7;
        uVar4 = 0x1dd;
LAB_001066ec:
        _printk(puVar3,"goodix_ts_send_cfg_store",uVar4);
      }
    }
  }
  if (*(int *)(*(code **)(lVar7 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1066a0);
    (*pcVar1)();
  }
  (**(code **)(lVar7 + 0x30))(lVar5,1);
  kfree(puVar6);
  if (local_50 != (undefined4 *)0x0) {
    release_firmware();
  }
  uVar4 = param_4;
LAB_00106550:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_convert_0x_data @ 001066f8 size=408
// signature: undefined goodix_ts_convert_0x_data(void)
// callers: [goodix_ts_send_cfg_store]
//------------------------------------------------------------

undefined8 goodix_ts_convert_0x_data(byte *param_1,uint param_2,long param_3,uint *param_4)

{
  ulong uVar1;
  byte bVar2;
  undefined *puVar3;
  undefined8 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulong uVar8;
  uint uVar9;
  ulong uVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  
  if ((int)param_2 < 1) {
    uVar9 = 0;
  }
  else {
    uVar10 = (ulong)param_2;
    uVar9 = 0;
    uVar8 = uVar10;
    pbVar11 = param_1;
    do {
      if ((*pbVar11 | 0x20) == 0x78) {
        uVar9 = uVar9 + 1;
      }
      uVar8 = uVar8 - 1;
      pbVar11 = pbVar11 + 1;
    } while (uVar8 != 0);
    if (1 < (int)uVar9) {
      *param_4 = uVar9;
      if (0 < (int)param_2) {
        uVar8 = 0;
        uVar5 = 0;
        do {
          while ((param_1[uVar8] | 0x20) != 0x78) {
            uVar8 = uVar8 + 1;
            if (uVar8 == uVar10) {
              return 0;
            }
          }
          if ((int)uVar9 <= (int)uVar5) {
            puVar3 = &DAT_001269b3;
            uVar4 = 0x1ab;
LAB_00106884:
            _printk(puVar3,"goodix_ts_convert_0x_data",uVar4,uVar5,uVar9);
            return 0xffffffea;
          }
          uVar1 = uVar8 + 1;
          bVar2 = param_1[uVar1];
          uVar13 = bVar2 - 0x30;
          uVar7 = (uint)bVar2;
          if (9 < uVar13) {
            if (bVar2 - 0x41 < 6) {
              uVar13 = uVar7 - 0x37;
            }
            else {
              uVar13 = uVar7 - 0x57;
              if (5 < uVar7 - 0x61) {
                uVar13 = 0xffffffff;
              }
            }
          }
          bVar2 = param_1[(int)uVar8 + 2];
          uVar12 = bVar2 - 0x30;
          if (9 < uVar12) {
            uVar6 = (uint)bVar2;
            if (bVar2 - 0x41 < 6) {
              uVar12 = uVar6 - 0x37;
            }
            else {
              uVar12 = uVar6 - 0x57;
              if (5 < uVar6 - 0x61) {
                uVar12 = 0xffffffff;
              }
            }
          }
          if ((((uVar13 ^ 0xffffffff) & 0xff) == 0) || (((uVar12 ^ 0xffffffff) & 0xff) == 0)) {
            puVar3 = &DAT_0011e0dc;
            uVar4 = 0x1b2;
            uVar5 = uVar7;
            uVar9 = (uint)bVar2;
            goto LAB_00106884;
          }
          *(char *)(param_3 + (int)uVar5) = (char)uVar12 + (char)uVar13 * '\x10';
          uVar8 = uVar1;
          uVar5 = uVar5 + 1;
        } while (uVar1 != uVar10);
      }
      return 0;
    }
  }
  _printk(&DAT_0011e74d,"goodix_ts_convert_0x_data",0x19f,uVar9);
  return 0xffffffea;
}



//------------------------------------------------------------
// goodix_ts_read_cfg_show @ 00106894 size=356
// signature: undefined goodix_ts_read_cfg_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long goodix_ts_read_cfg_show(long param_1,undefined8 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  code *pcVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  uint uVar8;
  
  lVar5 = *(long *)(param_1 + 0x98);
  lVar6 = *(long *)(lVar5 + 0x2d0);
  lVar3 = kmalloc_trace(_system_wq,0xdc0,0x1000);
  if (lVar3 == 0) {
    return -0xc;
  }
  pcVar4 = *(code **)(lVar6 + 0x58);
  if (pcVar4 == (code *)0x0) {
    iVar1 = -0x16;
  }
  else {
    if (*(int *)(pcVar4 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10690c);
      (*pcVar4)();
    }
    iVar1 = (*pcVar4)(lVar5,lVar3,0x1000);
    if (0 < iVar1) {
      lVar5 = 0;
      iVar7 = 0;
      uVar8 = 1;
      do {
        iVar2 = snprintf((char *)(param_3 + iVar7),0x1000 - (long)iVar7,"%02x,",
                         (uint)*(byte *)(lVar3 + lVar5));
        iVar2 = iVar2 + iVar7;
        iVar7 = iVar2;
        if ((uVar8 / 0x14) * 0x14 + -1 == (int)lVar5) {
          iVar7 = iVar2 + 1;
          *(undefined1 *)(param_3 + iVar2) = 10;
        }
        lVar5 = lVar5 + 1;
        uVar8 = uVar8 + 1;
      } while (lVar5 != 200);
      kfree(lVar3);
      if (0 < iVar1) {
        return (long)iVar7;
      }
      goto LAB_001069d0;
    }
  }
  kfree(lVar3);
LAB_001069d0:
  return (long)iVar1;
}



//------------------------------------------------------------
// goodix_ts_reg_rw_show @ 001069fc size=316
// signature: undefined goodix_ts_reg_rw_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_reg_rw_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  if (rw_addr == 0 || rw_len == 0) {
    _printk(&DAT_001203a2,"goodix_ts_reg_rw_show",0x1ff,rw_addr);
    lVar2 = -0x16;
  }
  else if (rw_flag == '\x01') {
    pcVar3 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x2d0) + 0x38);
    if (*(int *)(pcVar3 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x106a74);
      (*pcVar3)();
    }
    iVar1 = (*pcVar3)(*(long *)(param_1 + 0x98),rw_addr,show_buf,rw_len);
    if (iVar1 < 0) {
      _printk(&DAT_0011d4ef,"goodix_ts_reg_rw_show",0x20a);
      iVar1 = snprintf(param_3,0x1000,"failed read addr(%x), len(%d)\n",rw_addr,rw_len);
    }
    else {
      iVar1 = snprintf(param_3,0x1000,"0x%x,%d {%*ph}\n",rw_addr,rw_len,rw_len,show_buf);
    }
    lVar2 = (long)iVar1;
  }
  else {
    _printk(&DAT_0012383a,"goodix_ts_reg_rw_show",0x204);
    lVar2 = -0x16;
  }
  return lVar2;
}



//------------------------------------------------------------
// goodix_ts_reg_rw_store @ 00106b3c size=912
// signature: undefined goodix_ts_reg_rw_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_reg_rw_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined *puVar4;
  ulong uVar5;
  undefined8 uVar6;
  ulong uVar7;
  code *pcVar8;
  long lVar9;
  long lVar10;
  undefined8 local_78;
  char *local_70;
  long local_68;
  
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  lVar9 = *(long *)(param_1 + 0x98);
  local_78 = 0;
  local_70 = (char *)0x0;
  lVar10 = *(long *)(lVar9 + 0x2d0);
  if ((param_3 == (char *)0x0) || (param_4 == 0)) {
    puVar4 = &DAT_0011daa7;
    uVar6 = 0x220;
LAB_00106cf4:
    _printk(puVar4,"goodix_ts_reg_rw_store",uVar6);
  }
  else {
    if (*param_3 == 'r') {
      rw_flag = '\x01';
    }
    else {
      if (*param_3 != 'w') {
        puVar4 = &DAT_00126a01;
        uVar6 = 0x229;
        goto LAB_00106cf4;
      }
      rw_flag = '\x02';
    }
    local_70 = param_3 + 2;
    pcVar3 = strsep(&local_70,":");
    if (pcVar3 == (char *)0x0) {
      puVar4 = &DAT_00124e67;
      uVar6 = 0x232;
      goto LAB_00106cf4;
    }
    iVar1 = kstrtoll(pcVar3,0x10,&local_78);
    if (iVar1 != 0) {
      puVar4 = &DAT_001233b0;
      uVar6 = 0x236;
      goto LAB_00106cf4;
    }
    rw_addr = (uint)local_78;
    _printk(&DAT_0012487a,"goodix_ts_reg_rw_store",0x23a);
    pcVar3 = strsep(&local_70,":");
    if (pcVar3 == (char *)0x0) {
      puVar4 = &DAT_00122001;
      uVar6 = 0x240;
      goto LAB_00106cf4;
    }
    iVar1 = kstrtoll(pcVar3,0,&local_78);
    if (iVar1 != 0) {
      puVar4 = &DAT_00122029;
      uVar6 = 0x244;
      goto LAB_00106cf4;
    }
    rw_len = (uint)local_78;
    uVar5 = _printk(&DAT_001253f1,"goodix_ts_reg_rw_store",0x248);
    if (rw_len < 0x21) {
      if (rw_flag == '\x01') goto LAB_00106d1c;
      if (rw_len == 0) {
        uVar7 = 0;
      }
      else {
        uVar5 = 0;
        do {
          pcVar3 = strsep(&local_70,":");
          if (pcVar3 == (char *)0x0) {
            puVar4 = &DAT_00121a26;
            uVar6 = 0x255;
            goto LAB_00106cf4;
          }
          iVar1 = kstrtoll(pcVar3,0x10,&local_78);
          if (iVar1 != 0) {
            _printk(&DAT_00123cbe,"goodix_ts_reg_rw_store",0x259,uVar5 & 0xffffffff);
            goto LAB_00106cf8;
          }
          if (uVar5 == 0x20) {
                    /* WARNING: Does not return */
            pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x106ecc);
            (*pcVar8)();
          }
          (&store_buf)[uVar5] = (char)local_78;
          _printk(&DAT_00122380,"goodix_ts_reg_rw_store",0x25d,uVar5 & 0xffffffff,
                  (uint)local_78 & 0xff);
          uVar7 = (ulong)rw_len;
          uVar5 = uVar5 + 1;
        } while (uVar5 < uVar7);
      }
      pcVar8 = *(code **)(lVar10 + 0x40);
      if (*(int *)(pcVar8 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x106e20);
        (*pcVar8)();
      }
      iVar1 = (*pcVar8)(lVar9,rw_addr,&store_buf,uVar7);
      if (-1 < iVar1) {
        uVar5 = _printk(&DAT_0012489e,"goodix_ts_reg_rw_store",0x268,"success",rw_addr,rw_len,
                        &store_buf);
        goto LAB_00106d1c;
      }
      _printk(&DAT_00126a32,"goodix_ts_reg_rw_store",0x263,rw_addr,rw_len,&store_buf);
    }
    else {
      _printk(&DAT_00127a98,"goodix_ts_reg_rw_store",0x24a,0x20);
    }
  }
LAB_00106cf8:
  uVar2 = snprintf(show_buf,0x1000,"%s\n","invalid params, format{r/w:4100:length:[41:21:31]}");
  uVar5 = (ulong)uVar2;
  param_4 = -0x16;
LAB_00106d1c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return param_4;
}



//------------------------------------------------------------
// goodix_ts_irq_info_show @ 00106ed0 size=268
// signature: undefined goodix_ts_irq_info_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_irq_info_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  char *param3;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  
  lVar4 = *(long *)(param_1 + 0x98);
  uVar2 = snprintf(param_3,0x1000,"irq:%u\n",*(uint *)(lVar4 + 0x4b8));
  if (-1 < (int)uVar2) {
    uVar5 = (ulong)uVar2;
    param3 = "disabled";
    if (*(int *)(lVar4 + 0x4cc) != 0) {
      param3 = "enabled";
    }
    uVar2 = snprintf(param_3 + uVar5,0x1000 - uVar5,"state:%s\n",param3);
    if (-1 < (int)uVar2) {
      lVar3 = irq_to_desc(*(undefined4 *)(lVar4 + 0x4b8));
      lVar1 = uVar5 + uVar2;
      uVar2 = snprintf(param_3 + lVar1,0x1000 - lVar1,"disable-depth:%d\n",*(int *)(lVar3 + 0x88));
      if (-1 < (int)uVar2) {
        lVar1 = lVar1 + (ulong)uVar2;
        uVar2 = snprintf(param_3 + lVar1,0x1000 - lVar1,"trigger-count:%zu\n",
                         *(size_t *)(lVar4 + 0x4c0));
        if (-1 < (int)uVar2) {
          lVar1 = lVar1 + (ulong)uVar2;
          uVar2 = snprintf(param_3 + lVar1,0x1000 - lVar1,
                           "echo 0/1 > irq_info to disable/enable irq\n");
          if (-1 < (int)uVar2) {
            return lVar1 + (ulong)uVar2;
          }
        }
      }
    }
  }
  return -0x16;
}



//------------------------------------------------------------
// goodix_ts_irq_info_store @ 00106fe0 size=108
// signature: undefined goodix_ts_irq_info_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_irq_info_store(long param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  
  lVar1 = -0x16;
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    pcVar2 = *(code **)(*(long *)(*(long *)(param_1 + 0x98) + 0x2d0) + 0x30);
    if (*(int *)(pcVar2 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x107034);
      (*pcVar2)();
    }
    (*pcVar2)(*(long *)(param_1 + 0x98),*param_3 != '0');
    lVar1 = param_4;
  }
  return lVar1;
}



//------------------------------------------------------------
// goodix_ts_esd_info_show @ 00107050 size=84
// signature: undefined goodix_ts_esd_info_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_esd_info_show(long param_1,undefined8 param_2,char *param_3)

{
  char *param3;
  int iVar1;
  
  param3 = "disabled";
  if (*(int *)(*(long *)(param_1 + 0x98) + 0x504) != 0) {
    param3 = "enabled";
  }
  iVar1 = snprintf(param_3,0x1000,"state:%s\n",param3);
  return (long)iVar1;
}



//------------------------------------------------------------
// goodix_ts_esd_info_store @ 001070a8 size=84
// signature: undefined goodix_ts_esd_info_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_esd_info_store(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = -0x16;
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    uVar1 = 5;
    if (*param_3 != '0') {
      uVar1 = 6;
    }
    blocking_notifier_call_chain(ts_notifier_list,uVar1,0);
    lVar2 = param_4;
  }
  return lVar2;
}



//------------------------------------------------------------
// goodix_ts_debug_log_show @ 00107100 size=80
// signature: undefined goodix_ts_debug_log_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_debug_log_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  char *param3;
  int iVar1;
  
  param3 = "disabled";
  if (debug_log_flag != '\0') {
    param3 = "enabled";
  }
  iVar1 = snprintf(param_3,0x1000,"state:%s\n",param3);
  return (long)iVar1;
}



//------------------------------------------------------------
// goodix_ts_debug_log_store @ 00107154 size=40
// signature: undefined goodix_ts_debug_log_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_debug_log_store(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  
  lVar1 = -0x16;
  if ((param_3 != (char *)0x0) && (param_4 != 0)) {
    debug_log_flag = *param_3 != '0';
    lVar1 = param_4;
  }
  return lVar1;
}



//------------------------------------------------------------
// total_spi_timeouts_show @ 00107180 size=64
// signature: undefined total_spi_timeouts_show(void)
// callers: []
//------------------------------------------------------------

long total_spi_timeouts_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = snprintf(param_3,0x1000,"write: %d, read: %d (v2_async)\n",total_spi_write_timeouts,
                   total_spi_read_timeouts);
  return (long)iVar1;
}



//------------------------------------------------------------
// total_spi_timeouts_store @ 001071c4 size=188
// signature: undefined total_spi_timeouts_store(void)
// callers: []
//------------------------------------------------------------

void total_spi_timeouts_store(undefined8 param_1,undefined8 param_2,long param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  lVar3 = -0x16;
  if ((param_3 != 0) && (param_4 != 0)) {
    iVar2 = kstrtoull(param_3,10,&local_30);
    if (iVar2 == 0) {
      lVar3 = param_4;
      if (local_30 == 0) {
        _printk(&DAT_0012137e,"total_spi_timeouts_store",0x30e);
        total_spi_write_timeouts = 0;
        total_spi_read_timeouts = 0;
      }
    }
    else {
      lVar3 = (long)iVar2;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// rawdata_proc_open @ 00107284 size=52
// signature: undefined rawdata_proc_open(void)
// callers: []
//------------------------------------------------------------

void rawdata_proc_open(long param_1,undefined8 param_2)

{
  single_open_size(param_2,rawdata_proc_show,*(undefined8 *)(param_1 + 0x2b8),0xa000);
  return;
}



//------------------------------------------------------------
// rawdata_proc_show @ 001072bc size=608
// signature: undefined rawdata_proc_show(void)
// callers: []
//------------------------------------------------------------

int rawdata_proc_show(long param_1,long param_2)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  code *pcVar7;
  long lVar8;
  ulong uVar9;
  int iVar10;
  ulong uVar11;
  
  if (((param_1 == 0) || (param_2 == 0)) || (lVar8 = *(long *)(param_1 + 0x80), lVar8 == 0)) {
    _printk(&DAT_0011d523,"rawdata_proc_show",0x348);
    iVar5 = -5;
  }
  else {
    lVar6 = kmalloc_large(0x3718,0xdc0);
    if (lVar6 == 0) {
      _printk(&DAT_001248f7,"rawdata_proc_show",0x34e);
      iVar5 = -0xc;
    }
    else {
      pcVar7 = *(code **)(*(long *)(lVar8 + 0x2d0) + 0x88);
      if (*(int *)(pcVar7 + -4) != -0x2d500e6e) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x107330);
        (*pcVar7)();
      }
      iVar5 = (*pcVar7)(lVar8,lVar6);
      if (iVar5 < 0) {
        _printk(&DAT_0012492f,"rawdata_proc_show",0x354);
      }
      else {
        sVar1 = *(short *)(lVar6 + 4);
        sVar2 = *(short *)(lVar6 + 6);
        seq_printf(param_1,"TX:%d  RX:%d\n",(int)sVar2,(int)sVar1);
        seq_printf(param_1,"mutual_rawdata:\n");
        uVar3 = (int)sVar2 * (int)sVar1;
        if ((int)uVar3 < 1) {
          seq_printf(param_1,"mutual_diffdata:\n");
        }
        else {
          uVar9 = 0;
          do {
            if (uVar9 == 0x1b56) goto LAB_00107514;
            seq_printf(param_1,&DAT_001227be,(long)*(short *)(lVar6 + 8 + uVar9 * 2));
            uVar9 = uVar9 + 1;
            iVar4 = 0;
            if (sVar2 != 0) {
              iVar4 = (int)uVar9 / (int)sVar2;
            }
            if ((int)uVar9 == iVar4 * sVar2) {
              seq_printf(param_1,&DAT_00125dde);
            }
          } while (uVar3 != uVar9);
          seq_printf(param_1,"mutual_diffdata:\n");
          if (0 < (int)uVar3) {
            lVar8 = (ulong)(uVar3 + 2) * 2;
            uVar11 = 0;
            uVar9 = lVar8 - 0x3715;
            do {
              if (0x36a < (uVar3 + 2) + uVar11 >> 3) {
LAB_00107514:
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x107518);
                (*pcVar7)();
              }
              if (uVar9 < 0xffffffffffffc8e7) {
                    /* WARNING: Does not return */
                pcVar7 = (code *)SoftwareBreakpoint(1,0x10751c);
                (*pcVar7)();
              }
              seq_printf(param_1,&DAT_00126f02,(long)*(short *)(lVar8 + lVar6 + 4 + uVar11 * 2));
              uVar11 = uVar11 + 1;
              iVar4 = 0;
              iVar10 = (int)sVar2;
              if (iVar10 != 0) {
                iVar4 = (int)uVar11 / iVar10;
              }
              if ((int)uVar11 == iVar4 * iVar10) {
                seq_printf(param_1,&DAT_00125dde);
              }
              uVar9 = uVar9 + 2;
            } while (uVar3 != uVar11);
          }
        }
      }
      kfree(lVar6);
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// goodix_ts_probe @ 00107520 size=4600
// signature: undefined goodix_ts_probe(void)
// callers: []
//------------------------------------------------------------

int goodix_ts_probe(long param_1)

{
  char *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined *puVar10;
  long lVar11;
  size_t sVar12;
  char *pcVar13;
  undefined8 uVar14;
  long lVar15;
  long lVar16;
  int iVar17;
  char *__needle;
  char *local_78;
  char *local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  _printk(&DAT_00126a66,"goodix_ts_probe",0xa9a);
  lVar16 = *(long *)(param_1 + 0xa0);
  if (lVar16 == 0) {
    _printk(&DAT_0012541a,"goodix_ts_probe",0xa9e);
    iVar7 = -0x13;
    core_module_prob_sate = 0xffffffff;
    goto LAB_00107850;
  }
  puVar9 = (undefined4 *)devm_kmalloc(param_1 + 0x10,0x6e0,0xdc0);
  if (puVar9 == (undefined4 *)0x0) {
    _printk(&DAT_0011fda1,"goodix_ts_probe",0xaa6);
    iVar7 = -0xc;
    core_module_prob_sate = 0xffffffff;
    goto LAB_00107850;
  }
  lVar15 = *(long *)(*(long *)(lVar16 + 8) + 0x2e8);
  if (lVar15 == 0) {
    _printk(&DAT_00125443,"goodix_ts_probe",0xab4);
    iVar7 = -0x13;
    goto LAB_00107850;
  }
  local_78 = (char *)0x0;
  local_70 = (char *)0x0;
  if ((char *)(puVar9 + 0x42) == (char *)0x0) {
    puVar10 = &DAT_001275e2;
    uVar14 = 0x3fc;
LAB_00107630:
    _printk(puVar10,"goodix_parse_dt",uVar14);
LAB_0010782c:
    iVar7 = -0x16;
  }
  else {
    iVar7 = of_get_named_gpio_flags(lVar15,"goodix,avdd-gpio",0,0);
    if (iVar7 < 0) {
      _printk(&DAT_0011e785,"goodix_parse_dt",0x402);
      iVar7 = 0;
    }
    else {
      _printk(&DAT_0012809f,"goodix_parse_dt",0x405,iVar7);
    }
    puVar9[0x74] = iVar7;
    lVar11 = of_find_property(lVar15,"goodix,avdd-set",0);
    if (lVar11 != 0) {
      _printk(&DAT_0012497b,"goodix_parse_dt",0x40a);
    }
    *(bool *)((long)puVar9 + 0x2c3) = lVar11 != 0;
    iVar7 = of_get_named_gpio_flags(lVar15,"goodix,iovdd-gpio",0,0);
    if (iVar7 < 0) {
      _printk(&DAT_00125df1,"goodix_parse_dt",0x412);
      iVar7 = 0;
    }
    else {
      _printk(&DAT_00125e33,"goodix_parse_dt",0x415,iVar7);
    }
    puVar9[0x75] = iVar7;
    iVar7 = of_get_named_gpio_flags(lVar15,"goodix,iovdden-gpio",0,0);
    if (iVar7 < 0) {
      _printk(&DAT_00125df1,"goodix_parse_dt",0x41b);
      iVar7 = 0;
    }
    else {
      _printk(&DAT_00125e33,"goodix_parse_dt",0x41e,iVar7);
    }
    puVar9[0x76] = iVar7;
    iVar7 = of_get_named_gpio_flags(lVar15,"goodix,reset-gpio",0,0);
    if (iVar7 < 0) {
      puVar10 = &DAT_001227c3;
      uVar14 = 0x424;
LAB_00107824:
      _printk(puVar10,"goodix_parse_dt",uVar14,iVar7);
      goto LAB_0010782c;
    }
    _printk(&DAT_0011f77e,"goodix_parse_dt",0x427,iVar7);
    puVar9[0x72] = iVar7;
    iVar7 = of_get_named_gpio_flags(lVar15,"goodix,irq-gpio",0,0);
    if (iVar7 < 0) {
      puVar10 = &DAT_001227f4;
      uVar14 = 0x42c;
      goto LAB_00107824;
    }
    _printk(&DAT_0012341a,"goodix_parse_dt",0x42f,iVar7);
    puVar9[0x73] = iVar7;
    iVar7 = of_property_read_variable_u32_array(lVar15,"goodix,irq-flags",puVar9 + 0x77,1,0);
    if (iVar7 < 0) {
      puVar10 = &DAT_00125e62;
      uVar14 = 0x435;
      goto LAB_00107630;
    }
    *(undefined8 *)(puVar9 + 0x5e) = 0;
    *(undefined8 *)(puVar9 + 0x60) = 0;
    *(undefined8 *)(puVar9 + 0x5a) = 0;
    *(undefined8 *)(puVar9 + 0x5c) = 0;
    *(undefined8 *)(puVar9 + 0x56) = 0;
    *(undefined8 *)(puVar9 + 0x58) = 0;
    *(undefined8 *)(puVar9 + 0x52) = 0;
    *(undefined8 *)(puVar9 + 0x54) = 0;
    iVar7 = of_property_read_string(lVar15,"goodix,avdd-name",&local_70);
    if (iVar7 == 0) {
      _printk(&DAT_001213b2,"goodix_parse_dt",0x43c,local_70);
      pcVar1 = local_70;
      sVar12 = strlen(local_70);
      if (sVar12 < 0x40) {
        strncpy((char *)(puVar9 + 0x52),pcVar1,0x40);
      }
      else {
        _printk(&DAT_00122066,"goodix_parse_dt",0x443,sVar12,0x40);
      }
    }
    *(undefined8 *)(puVar9 + 0x6e) = 0;
    *(undefined8 *)(puVar9 + 0x70) = 0;
    *(undefined8 *)(puVar9 + 0x6a) = 0;
    *(undefined8 *)(puVar9 + 0x6c) = 0;
    *(undefined8 *)(puVar9 + 0x66) = 0;
    *(undefined8 *)(puVar9 + 0x68) = 0;
    *(undefined8 *)(puVar9 + 0x62) = 0;
    *(undefined8 *)(puVar9 + 100) = 0;
    iVar7 = of_property_read_string(lVar15,"goodix,iovdd-name",&local_70);
    if (iVar7 == 0) {
      _printk(&DAT_0011f7ad,"goodix_parse_dt",0x449,local_70);
      pcVar1 = local_70;
      sVar12 = strlen(local_70);
      if (sVar12 < 0x40) {
        strncpy((char *)(puVar9 + 0x62),pcVar1,0x40);
      }
      else {
        _printk(&DAT_00125e88,"goodix_parse_dt",0x450,sVar12,0x40);
      }
    }
    iVar7 = of_property_read_string(lVar15,"goodix,firmware-name",&local_70);
    if (iVar7 == 0) {
      _printk(&DAT_001264c2,"goodix_parse_dt",0x456,local_70);
      strncpy((char *)((long)puVar9 + 0x1f5),local_70,0x40);
    }
    else {
      _printk(&DAT_001213dc,"goodix_parse_dt",0x459,"goodix_firmware.bin");
      uVar14 = s_goodix_firmware_bin_0011d0c8._8_8_;
      *(undefined8 *)((long)puVar9 + 0x1f5) = s_goodix_firmware_bin_0011d0c8._0_8_;
      *(undefined8 *)((long)puVar9 + 0x20d) = 0;
      *(undefined8 *)((long)puVar9 + 0x215) = 0;
      *(undefined8 *)((long)puVar9 + 0x21d) = 0;
      *(undefined8 *)((long)puVar9 + 0x225) = 0;
      *(undefined8 *)((long)puVar9 + 0x22d) = 0;
      *(undefined8 *)((long)puVar9 + 0x1fd) = uVar14;
      *(undefined8 *)((long)puVar9 + 0x205) = 0x6e6962;
    }
    iVar7 = of_property_read_string(lVar15,"goodix,config-name",&local_70);
    uVar5 = s_goodix_cfg_group_bin_0011d109._8_8_;
    uVar14 = s_goodix_cfg_group_bin_0011d109._0_8_;
    if (iVar7 == 0) {
      _printk(&DAT_0011f19a,"goodix_parse_dt",0x460,local_70);
      strncpy((char *)((long)puVar9 + 0x235),local_70,0x40);
    }
    else {
      pcVar1 = (char *)((long)puVar9 + 0x235);
      *(undefined8 *)((long)puVar9 + 0x265) = 0;
      *(undefined8 *)((long)puVar9 + 0x26d) = 0;
      *(undefined8 *)((long)puVar9 + 0x255) = 0;
      *(undefined8 *)((long)puVar9 + 0x25d) = 0;
      *(undefined8 *)pcVar1 = uVar14;
      *(undefined8 *)((long)puVar9 + 0x23d) = uVar5;
      *(undefined8 *)((long)puVar9 + 0x245) = 0x6e69622e;
      *(undefined8 *)((long)puVar9 + 0x24d) = 0;
      lVar11 = of_find_node_by_name(0,"chosen");
      if (lVar11 != 0) {
        iVar7 = of_property_read_string(lVar11,"mmi,panel_name",&local_78);
        if (iVar7 == 0) {
          _printk(&DAT_001241d4,"goodix_parse_dt",0x46f,"goodix_parse_dt","mmi,panel_name",local_78)
          ;
        }
        else {
          _printk(&DAT_00120ef3,"goodix_parse_dt",0x46c,"goodix_parse_dt","mmi,panel_name",iVar7);
        }
      }
      iVar7 = of_property_read_string_helper(lVar15,"goodix,panel-supplier",0,0,0);
      _printk(&DAT_0012761f,"goodix_parse_dt",0x474,iVar7);
      if (iVar7 < 1) {
        _printk(&DAT_0011fddd,"goodix_parse_dt",0x48b,"goodix_cfg_group.bin");
        *(undefined8 *)((long)puVar9 + 0x255) = 0;
        *(undefined8 *)((long)puVar9 + 0x25d) = 0;
        *(undefined8 *)((long)puVar9 + 0x265) = 0;
        *(undefined8 *)((long)puVar9 + 0x26d) = 0;
        *(undefined8 *)pcVar1 = uVar14;
        *(undefined8 *)((long)puVar9 + 0x23d) = uVar5;
        *(undefined8 *)((long)puVar9 + 0x245) = 0x6e69622e;
        *(undefined8 *)((long)puVar9 + 0x24d) = 0;
      }
      else {
        iVar17 = 0;
        do {
          iVar8 = of_property_read_string_helper
                            (lVar15,"goodix,panel-supplier",puVar9 + 0xb2,1,iVar17);
          if (iVar8 < 0) {
            _printk(&DAT_0011ebee,"goodix_parse_dt",0x479,iVar8);
            break;
          }
          if (((local_78 != (char *)0x0) &&
              (__needle = *(char **)(puVar9 + 0xb2), __needle != (char *)0x0)) &&
             (pcVar13 = strstr(local_78,__needle), pcVar13 != (char *)0x0)) {
            _printk(&DAT_00126b03,"goodix_parse_dt",0x47c,__needle);
            snprintf(pcVar1,0x40,"%s_%s",*(char **)(puVar9 + 0xb2),"goodix_cfg_group.bin");
            snprintf((char *)((long)puVar9 + 0x1f5),0x40,"%s_%s",*(char **)(puVar9 + 0xb2),
                     "goodix_firmware.bin");
            lVar11 = kstrdup(*(undefined8 *)(puVar9 + 0xb2),0xcc0);
            *(long *)(puVar9 + 0x1a6) = lVar11;
            if (lVar11 == 0) {
              _printk(&DAT_00123ceb,"goodix_parse_dt",0x483);
            }
            _printk(&DAT_00126b32,"goodix_parse_dt",0x484,(char *)((long)puVar9 + 0x1f5),pcVar1);
            break;
          }
          iVar17 = iVar17 + 1;
        } while (iVar7 != iVar17);
      }
    }
    iVar7 = of_property_read_variable_u32_array(lVar15,"goodix,panel-max-x",puVar9 + 0x79,1,0);
    if (iVar7 < 0) {
      puVar10 = &DAT_0012388c;
      uVar14 = 0x3c8;
LAB_0010820c:
      _printk(puVar10,"goodix_parse_dt_resolution",uVar14);
      _printk(&DAT_001223eb,"goodix_parse_dt",0x493,iVar7);
    }
    else {
      iVar7 = of_property_read_variable_u32_array(lVar15,"goodix,panel-max-y",puVar9 + 0x7a,1,0);
      if (iVar7 < 0) {
        puVar10 = &DAT_00125f11;
        uVar14 = 0x3cf;
        goto LAB_0010820c;
      }
      iVar7 = of_property_read_variable_u32_array(lVar15,"goodix,panel-max-w",puVar9 + 0x7b,1,0);
      if (iVar7 < 0) {
        puVar10 = &DAT_0012499f;
        uVar14 = 0x3d6;
        goto LAB_0010820c;
      }
      puVar2 = puVar9 + 0x7c;
      iVar7 = of_property_read_variable_u32_array(lVar15,"goodix,panel-max-p",puVar2,1,0);
      if (iVar7 < 0) {
        _printk(&DAT_00126f3c,"goodix_parse_dt_resolution",0x3dd);
        *puVar2 = 0x1000;
      }
      iVar7 = of_property_read_string(lVar15,"compatible",&local_70);
      if (iVar7 == 0) {
        _printk(&DAT_00123447,"goodix_parse_dt",0x49d,local_70);
        strncpy((char *)(puVar9 + 0x42),local_70,0x40);
        lVar11 = of_find_property(lVar15,"goodix,pen-enable",0);
        *(bool *)(puVar9 + 0x7d) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_00125ec2,"goodix_parse_dt",0x4a5);
        }
        if (debug_log_flag != '\0') {
          _printk(&DAT_0011daca,"goodix_parse_dt",0x4a9,puVar9[0x79],puVar9[0x7a],puVar9[0x7b],
                  *puVar2);
        }
        lVar11 = of_find_property(lVar15,"goodix,stylus_mode-ctrl",0);
        *(bool *)((long)puVar9 + 0x2b6) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0011daf9,"goodix_parse_dt",0x4ae);
          iVar7 = of_property_read_string(lVar15,"goodix,stylus-clk-source",&local_70);
          if (iVar7 == 0) {
            _printk(&DAT_00126f07,"goodix_parse_dt",0x4b2,local_70);
            strncpy((char *)((long)puVar9 + 0x275),local_70,0x40);
          }
        }
        lVar11 = of_find_property(lVar15,"goodix,passive-stylus-mode-ctrl",0);
        *(bool *)((long)puVar9 + 0x2b7) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0012142d,"goodix_parse_dt",0x4ba);
        }
        lVar11 = of_find_property(lVar15,"goodix,sensitivity-ctrl",0);
        *(bool *)((long)puVar9 + 0x2b5) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0012589c,"goodix_parse_dt",0x4bf);
        }
        lVar11 = of_find_property(lVar15,"goodix,leather_mode-ctrl",0);
        *(bool *)((long)puVar9 + 0x2b9) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0011e143,"goodix_parse_dt",0x4c4);
        }
        lVar11 = of_find_property(lVar15,"goodix,film_mode-ctrl",0);
        *(bool *)(puVar9 + 0xae) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_00122e46,"goodix_parse_dt",0x4c9);
        }
        lVar11 = of_find_property(lVar15,"goodix,interpolation-ctrl",0);
        *(bool *)((long)puVar9 + 0x2ba) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0012147c,"goodix_parse_dt",0x4ce);
        }
        lVar11 = of_find_property(lVar15,"goodix,sample-ctrl",0);
        *(bool *)((long)puVar9 + 699) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_00122e73,"goodix_parse_dt",0x4d3);
        }
        lVar11 = of_find_property(lVar15,"goodix,report_rate-ctrl",0);
        *(bool *)(puVar9 + 0xaf) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_00123d1c,"goodix_parse_dt",0x4d8);
        }
        lVar11 = of_find_property(lVar15,"goodix,edge-ctrl",0);
        *(bool *)((long)puVar9 + 0x2bd) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0011f202,"goodix_parse_dt",0x4dd);
        }
        lVar11 = of_find_property(lVar15,"goodix,pitch-ctrl",0);
        *(bool *)((long)puVar9 + 0x2be) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_00124ee4,"goodix_parse_dt",0x4e2);
        }
        lVar11 = of_find_property(lVar15,"goodix,stowed-mode-ctrl",0);
        *(bool *)((long)puVar9 + 0x2bf) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_0011e173,"goodix_parse_dt",0x4e7);
        }
        lVar11 = of_find_property(lVar15,"goodix,pocket-mode-ctrl",0);
        *(bool *)((long)puVar9 + 0x2c1) = lVar11 != 0;
        if (lVar11 != 0) {
          _printk(&DAT_001241f2,"goodix_parse_dt",0x4ec);
        }
        lVar11 = of_find_property(lVar15,"goodix,gesture-wait-pm",0);
        if (lVar11 != 0) {
          _printk(&DAT_00125ee9,"goodix_parse_dt",0x4ef);
        }
        *(bool *)(puVar9 + 0xb0) = lVar11 != 0;
        lVar15 = of_find_property(lVar15,"goodix,fw-upgrade-drv",0);
        if (lVar15 != 0) {
          _printk(&DAT_00122434,"goodix_parse_dt",0x4f6);
        }
        *(bool *)((long)puVar9 + 0x2c2) = lVar15 != 0;
        lVar15 = goodix_get_hw_ops();
        *(long *)(puVar9 + 0xb4) = lVar15;
        if (lVar15 == 0) {
          _printk(&DAT_0011f75b,"goodix_ts_probe",0xaba);
          iVar7 = -0x16;
          core_module_prob_sate = 0xffffffff;
          goto LAB_00107850;
        }
        if (DAT_00129358 == '\0') {
          DAT_00129358 = '\x01';
          goodix_modules = &goodix_modules;
          DAT_00129350 = &goodix_modules;
          __mutex_init(&DAT_00129360,"&goodix_modules.mutex",&goodix_core_module_init___key);
        }
        uVar3 = puVar9[0x72];
        uVar4 = puVar9[0x73];
        *(long *)(puVar9 + 2) = param_1;
        *(long *)(puVar9 + 0x40) = lVar16;
        *(undefined4 **)(param_1 + 0xa8) = puVar9;
        _printk(&DAT_00122eb3,"goodix_ts_gpio_setup",0x6f4,uVar3,uVar4);
        iVar7 = devm_gpio_request_one(*(long *)(puVar9 + 2) + 0x10,puVar9[0x72],0,"ts_reset_gpio");
        if (iVar7 < 0) {
          puVar10 = &DAT_00120995;
          uVar14 = 0x6fc;
LAB_00108494:
          _printk(puVar10,"goodix_ts_gpio_setup",uVar14,iVar7);
          puVar10 = &DAT_001241af;
          uVar14 = 0xac7;
LAB_001084b0:
          _printk(puVar10,"goodix_ts_probe",uVar14);
        }
        else {
          iVar7 = devm_gpio_request_one(*(long *)(puVar9 + 2) + 0x10,puVar9[0x73],1,"ts_irq_gpio");
          if (iVar7 < 0) {
            puVar10 = &DAT_001209cc;
            uVar14 = 0x703;
            goto LAB_00108494;
          }
          if ((0 < (int)puVar9[0x74]) &&
             (iVar7 = devm_gpio_request_one
                                (*(long *)(puVar9 + 2) + 0x10,puVar9[0x74],0,"ts_avdd_gpio"),
             iVar7 < 0)) {
            puVar10 = &DAT_00122457;
            uVar14 = 0x70b;
            goto LAB_00108494;
          }
          if ((0 < (int)puVar9[0x75]) &&
             (iVar7 = devm_gpio_request_one
                                (*(long *)(puVar9 + 2) + 0x10,puVar9[0x75],0,"ts_iovdd_gpio"),
             iVar7 < 0)) {
            puVar10 = &DAT_0011d581;
            uVar14 = 0x714;
            goto LAB_00108494;
          }
          if ((0 < (int)puVar9[0x76]) &&
             (iVar7 = devm_gpio_request_one
                                (*(long *)(puVar9 + 2) + 0x10,puVar9[0x76],0,"ts_iovdden_gpio"),
             iVar7 < 0)) {
            puVar10 = &DAT_00123d81;
            uVar14 = 0x71d;
            goto LAB_00108494;
          }
          iVar7 = goodix_ts_power_init(puVar9);
          if (iVar7 != 0) {
            puVar10 = &DAT_0012646b;
            uVar14 = 0xacd;
            goto LAB_001084b0;
          }
          iVar7 = goodix_ts_power_on(puVar9);
          if (iVar7 != 0) {
            puVar10 = &DAT_001275be;
            uVar14 = 0xad3;
            goto LAB_001084b0;
          }
          if (*(int *)(*(code **)(*(long *)(puVar9 + 0xb4) + 8) + -4) != 0x1c1b2b73) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x108520);
            (*pcVar6)();
          }
          iVar7 = (**(code **)(*(long *)(puVar9 + 0xb4) + 8))(puVar9);
          if (iVar7 != 0) {
            puVar10 = &DAT_00126491;
            uVar14 = 0xada;
            goto LAB_001084b0;
          }
          iVar7 = goodix_ts_pinctrl_init(puVar9);
          if (((iVar7 == 0) && (*(long *)(puVar9 + 0x11e) != 0)) &&
             (iVar7 = pinctrl_select_state
                                (*(long *)(puVar9 + 0x11e),*(undefined8 *)(puVar9 + 0x120)),
             iVar7 < 0)) {
            _printk(&DAT_0012581e,"goodix_ts_probe",0xae4,iVar7);
          }
          iVar7 = goodix_ts_stylus_clk_init(puVar9);
          if (iVar7 != 0) {
            _printk(&DAT_00125859,"goodix_ts_probe",0xaea);
          }
          *(code **)(puVar9 + 0x13a) = goodix_generic_noti_callback;
          blocking_notifier_chain_register(ts_notifier_list,puVar9 + 0x13a);
          _printk(&DAT_00126a8d,"goodix_ts_probe",0xaf1,"goodix_ts_probe");
          iVar7 = goodix_ts_mmi_dev_register(param_1);
          if (iVar7 != 0) {
            puVar10 = &DAT_001223b6;
            uVar14 = 0xaf4;
            goto LAB_001084b0;
          }
          cpu_latency_qos_add_request(puVar9 + 0x16c,0xffffffff);
          lVar16 = wakeup_source_register(*(undefined8 *)(lVar16 + 8),"goodix_gesture_wakelock");
          *(long *)(puVar9 + 0x138) = lVar16;
          if (lVar16 == 0) {
            _printk(&DAT_0011f161,"goodix_ts_probe",0xb00);
            iVar7 = -0xc;
          }
          else {
            if (*(char *)(puVar9 + 0xb0) != '\0') {
              __init_waitqueue_head(puVar9 + 0x1b0,"&core_data->pm_wq",&goodix_ts_probe___key);
            }
            puVar9[0x1af] = 1;
            goodix_tools_init();
            core_module_prob_sate = 1;
            *puVar9 = 2;
            DAT_00129398 = puVar9;
            iVar7 = goodix_start_later_init(puVar9);
            if (iVar7 == 0) {
              _printk(&DAT_001233d9,"goodix_ts_probe",0xb3b);
              goto LAB_00107850;
            }
            _printk(&DAT_00126abf,"goodix_ts_probe",0xb22,iVar7);
          }
          wakeup_source_unregister(*(undefined8 *)(puVar9 + 0x138));
        }
        *puVar9 = 1;
        core_module_prob_sate = 0xffffffff;
        _printk(&DAT_001203e1,"goodix_ts_probe",0xb43,iVar7);
        goto LAB_00107850;
      }
      _printk(&DAT_0011f1d8,"goodix_parse_dt",0x49a);
    }
  }
  _printk(&DAT_00124e98,"goodix_ts_probe",0xab0,iVar7);
  iVar7 = -0x16;
LAB_00107850:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar7;
}



//------------------------------------------------------------
// goodix_ts_remove @ 0010871c size=504
// signature: undefined goodix_ts_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_remove(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  
  piVar4 = *(int **)(param_1 + 0xa8);
  lVar5 = *(long *)(piVar4 + 0xb4);
  cpu_latency_qos_remove_request(piVar4 + 0x16c);
  _printk(&DAT_00120a60,"goodix_ts_remove",0xb51,"goodix_ts_remove");
  goodix_ts_mmi_dev_unregister(param_1);
  blocking_notifier_chain_unregister(ts_notifier_list,piVar4 + 0x13a);
  goodix_tools_exit();
  if (2 < *piVar4) {
    gesture_module_exit();
    inspect_module_exit();
    if (*(int *)(*(code **)(lVar5 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1087dc);
      (*pcVar1)();
    }
    (**(code **)(lVar5 + 0x30))(piVar4,0);
    core_module_prob_sate = 0xfffffffe;
    if ((piVar4[0x141] != 0) && (piVar4[0x141] != 0)) {
      piVar4[0x141] = 0;
      uVar2 = cancel_delayed_work_sync(piVar4 + 0x142);
      _printk(&DAT_001237d8,"goodix_ts_esd_off",0x7fc,uVar2 & 1);
    }
    blocking_notifier_chain_unregister(ts_notifier_list,piVar4 + 0x164);
    goodix_fw_update_uninit();
    if (*(long *)(piVar4 + 0xb6) != 0) {
      input_unregister_device();
      input_free_device(*(undefined8 *)(piVar4 + 0xb6));
      piVar4[0xb6] = 0;
      piVar4[0xb7] = 0;
    }
    if (*(long *)(piVar4 + 0xb8) != 0) {
      input_unregister_device();
      input_free_device(*(undefined8 *)(piVar4 + 0xb8));
      piVar4[0xb8] = 0;
      piVar4[0xb9] = 0;
    }
    sysfs_remove_group(*(long *)(piVar4 + 2) + 0x10,sysfs_group);
    remove_proc_entry("goodix_ts/tp_capacitance_data",0);
    remove_proc_entry("goodix_ts",0);
    _printk(&DAT_00126942,"goodix_ts_power_off",0x675);
    if (piVar4[0x128] != 0) {
      if (*(int *)((code *)**(undefined8 **)(piVar4 + 0xb4) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1088e4);
        (*pcVar1)();
      }
      iVar3 = (*(code *)**(undefined8 **)(piVar4 + 0xb4))(piVar4,0);
      if (iVar3 == 0) {
        piVar4[0x128] = 0;
      }
      else {
        _printk(&DAT_001208f5,"goodix_ts_power_off",0x67d,iVar3);
      }
    }
  }
  if (*(long *)(piVar4 + 0x1a6) != 0) {
    kfree();
    piVar4[0x1a6] = 0;
    piVar4[0x1a7] = 0;
  }
  return 0;
}



//------------------------------------------------------------
// goodix_ts_power_init @ 00108914 size=520
// signature: undefined goodix_ts_power_init(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

ulong goodix_ts_power_init(long param_1)

{
  long lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  size_t sVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  
  uVar8 = *(undefined8 *)(*(long *)(param_1 + 0x100) + 8);
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + 0x108;
  }
  _printk(&DAT_00126f74,"goodix_ts_power_init",0x62a);
  sVar5 = strnlen((char *)(lVar1 + 0x40),0x40);
  if (0x40 < sVar5) {
LAB_00108b04:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  if (sVar5 == 0) {
    _printk(&DAT_00122eed,"goodix_ts_power_init",0x643);
  }
  else {
    if (sVar5 == 0x40) goto LAB_00108b10;
    uVar6 = devm_regulator_get(uVar8,(char *)(lVar1 + 0x40));
    *(ulong *)(param_1 + 0x468) = uVar6;
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      _printk(&DAT_0011f800,"goodix_ts_power_init",0x630,uVar6 & 0xffffffff);
      *(undefined8 *)(param_1 + 0x468) = 0;
      goto LAB_00108a30;
    }
    uVar4 = regulator_set_load(uVar6,50000);
    if (uVar4 != 0) {
      uVar6 = (ulong)uVar4;
      _printk(&DAT_001280cd,"goodix_ts_power_init",0x637);
      goto LAB_00108a30;
    }
    if (*(char *)(lVar1 + 0x1bb) == '\0') {
      uVar2 = 3000000;
      uVar3 = 3000000;
    }
    else {
      uVar2 = 3300000;
      uVar3 = 3300000;
    }
    uVar7 = regulator_set_voltage(*(undefined8 *)(param_1 + 0x468),uVar2,uVar3);
    uVar6 = uVar7 & 0xffffffff;
    if ((int)uVar7 != 0) {
      _printk(&DAT_001238b7,"goodix_ts_power_init",0x63f);
      goto LAB_00108a30;
    }
  }
  sVar5 = strnlen((char *)(lVar1 + 0x80),0x40);
  if (0x40 < sVar5) goto LAB_00108b04;
  if (sVar5 == 0) {
    _printk(&DAT_00120a01,"goodix_ts_power_init",0x64f);
  }
  else {
    if (sVar5 == 0x40) {
LAB_00108b10:
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    uVar6 = devm_regulator_get(uVar8,(char *)(lVar1 + 0x80));
    *(ulong *)(param_1 + 0x470) = uVar6;
    if ((uVar6 == 0) || (0xfffffffffffff000 < uVar6)) {
      _printk(&DAT_001238e1,"goodix_ts_power_init",0x64b,uVar6 & 0xffffffff);
      *(undefined8 *)(param_1 + 0x470) = 0;
      goto LAB_00108a30;
    }
  }
  uVar6 = 0;
LAB_00108a30:
  return uVar6 & 0xffffffff;
}



//------------------------------------------------------------
// goodix_ts_pinctrl_init @ 00108b1c size=404
// signature: undefined goodix_ts_pinctrl_init(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

ulong goodix_ts_pinctrl_init(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  undefined8 *puVar3;
  
  uVar1 = devm_pinctrl_get(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8));
  *(ulong *)(param_1 + 0x478) = uVar1;
  if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
    _printk(&DAT_0011fe43,"goodix_ts_pinctrl_init",0x6c5);
    uVar1 = 0xffffffea;
    *(undefined8 *)(param_1 + 0x478) = 0;
  }
  else {
    if (debug_log_flag != '\0') {
      _printk(&DAT_0011f834,"goodix_ts_pinctrl_init",0x6c9);
      uVar1 = *(ulong *)(param_1 + 0x478);
    }
    uVar1 = pinctrl_lookup_state(uVar1,"pmx_ts_active");
    *(ulong *)(param_1 + 0x480) = uVar1;
    if ((uVar1 == 0) || (0xfffffffffffff000 < uVar1)) {
      puVar3 = (undefined8 *)(param_1 + 0x480);
      _printk(&DAT_0011ec42,"goodix_ts_pinctrl_init",0x6d0,"pmx_ts_active",uVar1 & 0xffffffff);
    }
    else {
      if (debug_log_flag != '\0') {
        _printk(&DAT_001234b6,"goodix_ts_pinctrl_init",0x6d4);
      }
      uVar1 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x478),"pmx_ts_suspend");
      *(ulong *)(param_1 + 0x488) = uVar1;
      if ((uVar1 != 0) && (uVar1 < 0xfffffffffffff001)) {
        if (debug_log_flag != '\0') {
          _printk(&DAT_0011d5b8,"goodix_ts_pinctrl_init",0x6e0);
        }
        uVar1 = 0;
        goto LAB_00108bb4;
      }
      puVar3 = (undefined8 *)(param_1 + 0x488);
      _printk(&DAT_0011ec42,"goodix_ts_pinctrl_init",0x6dc,"pmx_ts_suspend",uVar1 & 0xffffffff);
    }
    uVar2 = *(undefined8 *)(param_1 + 0x478);
    *puVar3 = 0;
    devm_pinctrl_put(uVar2);
    *(undefined8 *)(param_1 + 0x478) = 0;
  }
LAB_00108bb4:
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// goodix_ts_stylus_clk_init @ 00108cb0 size=524
// signature: undefined goodix_ts_stylus_clk_init(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

ulong goodix_ts_stylus_clk_init(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  undefined *puVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar2 = 0;
  if (param_1 != 0) {
    lVar2 = param_1 + 0x108;
  }
  if (*(char *)(lVar2 + 0x1ae) == '\0') {
    puVar4 = &DAT_0011f22f;
    uVar5 = 0x68b;
  }
  else {
    lVar6 = *(long *)(param_1 + 0x100);
    iVar1 = strcmp((char *)(lVar2 + 0x16d),"stylus_clk_pmic");
    if (iVar1 == 0) {
      lVar2 = of_get_property(*(undefined8 *)(*(long *)(lVar6 + 8) + 0x2e8),"clocks",0);
      if (lVar2 != 0) {
        uVar3 = devm_clk_get(*(undefined8 *)(lVar6 + 8),"stylus_clk");
        *(ulong *)(param_1 + 0x5e8) = uVar3;
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          puVar4 = &DAT_001280f4;
          uVar5 = 0x692;
          goto LAB_00108e34;
        }
      }
      uVar3 = 0;
      goto LAB_00108d38;
    }
    iVar1 = strcmp((char *)(lVar2 + 0x16d),"stylus_clk_gpio");
    if (iVar1 == 0) {
      uVar3 = *(ulong *)(param_1 + 0x478);
      if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
        _printk(&DAT_0011fe43,"goodix_ts_stylus_clk_init",0x698);
        uVar3 = 0xffffffea;
        *(undefined8 *)(param_1 + 0x478) = 0;
      }
      else {
        uVar3 = pinctrl_lookup_state(uVar3,"stylus_clk_active");
        *(ulong *)(param_1 + 0x490) = uVar3;
        if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
          _printk(&DAT_00126f93,"goodix_ts_stylus_clk_init",0x6a1,"stylus_clk_active",
                  uVar3 & 0xffffffff);
          *(undefined8 *)(param_1 + 0x490) = 0;
        }
        else {
          _printk(&DAT_0012282a,"goodix_ts_stylus_clk_init",0x6a5);
          uVar3 = pinctrl_lookup_state(*(undefined8 *)(param_1 + 0x478),"stylus_clk_suspend");
          *(ulong *)(param_1 + 0x498) = uVar3;
          if ((uVar3 == 0) || (0xfffffffffffff000 < uVar3)) {
            _printk(&DAT_00126f93,"goodix_ts_stylus_clk_init",0x6ac,"stylus_clk_suspend",
                    uVar3 & 0xffffffff);
            *(undefined8 *)(param_1 + 0x498) = 0;
          }
          else {
            _printk(&DAT_0011e1bd,"goodix_ts_stylus_clk_init",0x6b0);
            uVar3 = 0;
          }
        }
      }
      goto LAB_00108d38;
    }
    puVar4 = &DAT_00125f57;
    uVar5 = 0x6b2;
  }
LAB_00108e34:
  _printk(puVar4,"goodix_ts_stylus_clk_init",uVar5);
  uVar3 = 0xffffffea;
LAB_00108d38:
  return uVar3 & 0xffffffff;
}



//------------------------------------------------------------
// goodix_generic_noti_callback @ 00108ec0 size=496
// signature: undefined goodix_generic_noti_callback(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_generic_noti_callback(long param_1,ulong param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  
  piVar3 = (int *)(param_1 + -0x4e8);
  if (2 < *piVar3) {
    lVar4 = *(long *)(param_1 + -0x218);
    _printk(&DAT_0011f257,"goodix_generic_noti_callback",0x94c,param_2 & 0xffffffff);
    if (param_2 == 2) {
      if ((*(char *)(param_1 + 0x1b8) != '\0') &&
         (iVar2 = goodix_get_config_proc(piVar3), iVar2 != 0)) {
        _printk(&DAT_00121a8b,"goodix_generic_noti_callback",0x956);
        if (*(int *)(*(code **)(lVar4 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1090a8);
          (*pcVar1)();
        }
        (**(code **)(lVar4 + 0x30))(piVar3,1);
        return 0;
      }
      if (*(int *)(*(code **)(lVar4 + 0x68) + -4) != -0x2fa11135) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108fa8);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x68))(piVar3,param_1 + -0x4bc);
      if (iVar2 != 0) {
        _printk(&DAT_00123dba,"goodix_generic_noti_callback",0x95e);
      }
      iVar2 = goodix_send_ic_config(piVar3);
      if (iVar2 != 0) {
        _printk(&DAT_0011e7d9,"goodix_generic_noti_callback",0x961);
      }
    }
    else if (param_2 != 1) {
      if (param_2 != 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x1a8) = 1;
      if (*(int *)(*(code **)(lVar4 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108f68);
        (*pcVar1)();
      }
      (**(code **)(lVar4 + 0x30))(piVar3,0);
      return 0;
    }
    if (*(int *)(*(code **)(lVar4 + 0x60) + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x108fe0);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(lVar4 + 0x60))(piVar3,param_1 + -0x4d8);
    if (iVar2 != 0) {
      _printk(&DAT_00120a28,"goodix_generic_noti_callback",0x965);
    }
    if (*(int *)(*(code **)(lVar4 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10900c);
      (*pcVar1)();
    }
    (**(code **)(lVar4 + 0x30))(piVar3,1);
    *(undefined4 *)(param_1 + 0x1a8) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// goodix_start_later_init @ 001090b0 size=124
// signature: undefined goodix_start_later_init(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

undefined8 goodix_start_later_init(undefined8 param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  
  uVar1 = kthread_create_on_node(goodix_later_init_thread,param_1,0xffffffff,"goodix_init_thread");
  if ((uVar1 < 0xfffffffffffff001) && (wake_up_process(uVar1), uVar1 != 0)) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_0011d5ee,"goodix_start_later_init",0xa54,uVar1);
    uVar2 = 0xfffffff2;
  }
  return uVar2;
}



//------------------------------------------------------------
// goodix_later_init_thread @ 00109130 size=604
// signature: undefined goodix_later_init_thread(void)
// callers: []
//------------------------------------------------------------

int goodix_later_init_thread(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  
  lVar6 = *(long *)(param_1 + 0xb4);
  iVar2 = goodix_fw_update_init();
  if (iVar2 != 0) {
    _printk(&DAT_00124f22,"goodix_later_init_thread",0x9fa);
    goto LAB_001091a0;
  }
  iVar2 = goodix_get_config_proc(param_1);
  if (iVar2 == 0) {
    _printk(&DAT_00126fd8,"goodix_later_init_thread",0xa05);
    cVar1 = *(char *)((long)param_1 + 0x2c2);
  }
  else {
    _printk(&DAT_00121a8b,"goodix_later_init_thread",0xa00);
    *(undefined1 *)(param_1 + 0x1a8) = 1;
    cVar1 = *(char *)((long)param_1 + 0x2c2);
  }
  if (cVar1 != '\0') {
    _printk(&DAT_00127abb,"goodix_later_init_thread",0xa0e);
    iVar2 = goodix_do_fw_update(*(undefined8 *)(param_1 + 0x10c),0x42);
    if (iVar2 != 0) {
      _printk(&DAT_00121ab8,"goodix_later_init_thread",0xa12);
    }
  }
  pcVar5 = *(code **)(lVar6 + 0x60);
  if (*(int *)(pcVar5 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x109290);
    (*pcVar5)();
  }
  iVar2 = (*pcVar5)(param_1,param_1 + 4);
  if (iVar2 == 0) {
    pcVar5 = *(code **)(lVar6 + 0x68);
    if (*(int *)(pcVar5 + -4) != -0x2fa11135) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1092bc);
      (*pcVar5)();
    }
    iVar2 = (*pcVar5)(param_1,param_1 + 0xb);
    if (iVar2 != 0) {
      puVar3 = &DAT_00123921;
      uVar4 = 0xa24;
      goto LAB_00109384;
    }
  }
  else {
    puVar3 = &DAT_0012424d;
    uVar4 = 0xa1c;
LAB_00109384:
    _printk(puVar3,"goodix_later_init_thread",uVar4);
  }
  iVar2 = goodix_ts_stage2_init(param_1);
  if (iVar2 == 0) {
    *param_1 = 3;
    return 0;
  }
  _printk(&DAT_00127008,"goodix_later_init_thread",0xa38);
  goodix_fw_update_uninit();
LAB_001091a0:
  _printk(&DAT_00127008,"goodix_later_init_thread",0xa42);
  *param_1 = 1;
  if (*(long *)(param_1 + 0x10a) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x10a) = 0;
  if (*(long *)(param_1 + 0x10c) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x10c) = 0;
  if (*(long *)(param_1 + 0x10e) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x10e) = 0;
  if (*(long *)(param_1 + 0x110) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x110) = 0;
  if (*(long *)(param_1 + 0x112) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x112) = 0;
  if (*(long *)(param_1 + 0x114) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x114) = 0;
  if (*(long *)(param_1 + 0x116) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x116) = 0;
  if (*(long *)(param_1 + 0x118) != 0) {
    kfree();
  }
  *(undefined8 *)(param_1 + 0x118) = 0;
  return iVar2;
}



//------------------------------------------------------------
// goodix_ts_pm_suspend @ 00109390 size=84
// signature: undefined goodix_ts_pm_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_pm_suspend(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (debug_log_flag != '\0') {
    _printk(&DAT_0012047d,"goodix_ts_pm_suspend",0x922);
  }
  *(undefined4 *)(lVar1 + 0x6bc) = 0;
  return 0;
}



//------------------------------------------------------------
// goodix_ts_pm_resume @ 001093e8 size=116
// signature: undefined goodix_ts_pm_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_pm_resume(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x98);
  if (debug_log_flag != '\0') {
    _printk(&DAT_0011e1fe,"goodix_ts_pm_resume",0x931);
  }
  *(undefined4 *)(lVar1 + 0x6bc) = 1;
  if (*(char *)(lVar1 + 0x2c0) != '\0') {
    __wake_up(lVar1 + 0x6c0,1,1,0);
  }
  return 0;
}



//------------------------------------------------------------
// brl_suspend @ 00109460 size=156
// signature: undefined brl_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 brl_suspend(long param_1)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uStack_20 = 0;
  local_28 = 0x84040000;
  pcVar3 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
  if (*(int *)(pcVar3 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1094ac);
    (*pcVar3)();
  }
  iVar2 = (*pcVar3)(param_1,&local_28);
  if (iVar2 != 0) {
    _printk(&DAT_0011e229,"brl_suspend",0x106);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// brl_resume @ 00109500 size=64
// signature: undefined brl_resume(void)
// callers: []
//------------------------------------------------------------

void brl_resume(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x28);
  if (*(int *)(pcVar1 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x109530);
    (*pcVar1)();
  }
  (*pcVar1)(param_1,100);
  return;
}



//------------------------------------------------------------
// brl_gesture @ 00109544 size=236
// signature: undefined brl_gesture(void)
// callers: []
//------------------------------------------------------------

undefined8 brl_gesture(long param_1,uint param_2)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  undefined8 local_28;
  undefined8 uStack_20;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  uStack_20 = 0;
  local_28 = CONCAT44(param_2 & 0xff,0xa6000000);
  iVar2 = *(int *)(*(long *)(param_1 + 0x100) + 4);
  if (iVar2 == 5) {
    local_28 = CONCAT53(local_28._3_5_,0x80000);
    local_28 = CONCAT17((char)(param_2 >> 0x18),CONCAT16((char)(param_2 >> 0x10),(uint6)local_28));
  }
  else if (iVar2 == 6) {
    local_28 = CONCAT53(local_28._3_5_,0x60000);
    local_28._0_6_ = CONCAT15((char)(param_2 >> 8),(undefined5)local_28);
    local_28 = (ulong)(uint6)local_28;
  }
  else {
    local_28 = CONCAT53(local_28._3_5_,0x50000);
  }
  pcVar3 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
  if (*(int *)(pcVar3 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1095e0);
    (*pcVar3)();
  }
  iVar2 = (*pcVar3)(param_1,&local_28);
  if (iVar2 != 0) {
    _printk(&DAT_00127b05,"brl_gesture",0x122);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// goodix_get_hw_ops @ 00109634 size=12
// signature: undefined goodix_get_hw_ops(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

undefined ** goodix_get_hw_ops(void)

{
  return &brl_hw_ops;
}



//------------------------------------------------------------
// brl_power_on @ 00109644 size=3136
// signature: undefined brl_power_on(void)
// callers: []
//------------------------------------------------------------

int brl_power_on(long param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  long lVar11;
  undefined *puVar12;
  code *pcVar13;
  undefined2 local_7c [2];
  undefined8 local_78;
  int local_70 [2];
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  if (param_1 == 0) {
LAB_001097d0:
    iVar5 = 0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x1d4);
    iVar2 = *(int *)(param_1 + 0x1d0);
    uVar3 = *(undefined4 *)(param_1 + 0x1c8);
    iVar4 = *(int *)(param_1 + 0x1d8);
    if ((param_2 & 1) == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = iVar1;
      if (iVar1 < 1) {
        if (*(long *)(param_1 + 0x470) == 0) goto LAB_001096a8;
        iVar5 = regulator_enable();
        if (-1 < iVar5) {
          iVar5 = iVar4;
          if (0 < iVar4) goto LAB_0010969c;
          goto LAB_001096a8;
        }
        puVar12 = &DAT_0011f282;
        uVar10 = 0xd2;
LAB_0010a1f4:
        _printk(puVar12,"brl_power_on",uVar10,iVar5);
      }
      else {
LAB_0010969c:
        uVar10 = gpio_to_desc(iVar5);
        gpiod_direction_output_raw(uVar10,1);
LAB_001096a8:
        usleep_range_state(3000,0xc1c,2);
        if (iVar2 < 1) {
          if ((*(long *)(param_1 + 0x468) != 0) && (iVar5 = regulator_enable(), iVar5 < 0)) {
            puVar12 = &DAT_00120aa8;
            uVar10 = 0xdf;
            goto LAB_0010a1f4;
          }
        }
        else {
          uVar10 = gpio_to_desc(iVar2);
          gpiod_direction_output_raw(uVar10,1);
        }
        usleep_range_state(15000,0x3afc,2);
        uVar10 = gpio_to_desc(uVar3);
        gpiod_direction_output_raw(uVar10,1);
        usleep_range_state(4000,0x1004,2);
        local_70[0] = 0;
        local_78 = 0;
        if (*(int *)(*(long *)(param_1 + 0x100) + 4) != 4) goto LAB_001097d0;
        _printk(&DAT_0012702f,"brl_reset_after",0x66);
        iVar5 = brl_select_spi_mode(param_1);
        if (-1 < iVar5) {
          iVar5 = 9;
          do {
            local_7c[0] = 1;
            pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
            if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109890);
              (*pcVar13)();
            }
            iVar6 = (*pcVar13)(param_1,2,local_7c,2);
            pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
            if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1098c8);
              (*pcVar13)();
            }
            iVar7 = (*pcVar13)(param_1,0x2000,&local_78,4);
            pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
            if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109900);
              (*pcVar13)();
            }
            iVar8 = (*pcVar13)(param_1,0x2000,(ulong)&local_78 | 4,4);
            pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
            if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109938);
              (*pcVar13)();
            }
            iVar9 = (*pcVar13)(param_1,0x2000,local_70,4);
            if ((iVar7 == 0 && iVar6 == 0) && (iVar8 == 0 && iVar9 == 0)) {
              if (((int)local_78 == local_78._4_4_) && ((int)local_78 == local_70[0])) {
                if (-1 < iVar5) {
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                  local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xff);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10999c);
                    (*pcVar13)();
                  }
                  iVar5 = (*pcVar13)(param_1,0xd807,local_7c,1);
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x1099d4);
                    (*pcVar13)();
                  }
                  iVar6 = (*pcVar13)(param_1,0xd807,&local_78,1);
                  if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != -1)) {
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xff);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109a20);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd807,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109a58);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd807,&local_78,1);
                    if ((iVar6 == 0 && iVar5 == 0) && ((char)local_78 == -1)) goto LAB_00109c00;
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xff);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109aa4);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd807,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109adc);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd807,&local_78,1);
                    if ((iVar6 == 0 && iVar5 == 0) && ((char)local_78 == -1)) goto LAB_00109c00;
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xff);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109b28);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd807,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109b60);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd807,&local_78,1);
                    if ((iVar6 == 0 && iVar5 == 0) && ((char)local_78 == -1)) goto LAB_00109c00;
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xff);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109bb0);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd807,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109be8);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd807,&local_78,1);
                    if ((iVar6 == 0 && iVar5 == 0) && ((char)local_78 == -1)) goto LAB_00109c00;
                    puVar12 = &DAT_00123de7;
                    uVar10 = 0x8b;
LAB_0010a258:
                    _printk(puVar12,"brl_reset_after",uVar10);
                    goto LAB_0010a220;
                  }
LAB_00109c00:
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                  local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x77);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109c38);
                    (*pcVar13)();
                  }
                  iVar5 = (*pcVar13)(param_1,0xd806,local_7c,1);
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109c70);
                    (*pcVar13)();
                  }
                  iVar6 = (*pcVar13)(param_1,0xd806,&local_78,1);
                  if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != 'w')) {
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x77);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109cbc);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd806,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109cf4);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd806,&local_78,1);
                    if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != 'w')) {
                      local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x77);
                      pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                      if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109d40);
                        (*pcVar13)();
                      }
                      iVar5 = (*pcVar13)(param_1,0xd806,local_7c,1);
                      pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                      if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109d78);
                        (*pcVar13)();
                      }
                      iVar6 = (*pcVar13)(param_1,0xd806,&local_78,1);
                      if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != 'w')) {
                        local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x77);
                        pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                        if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109dc4);
                          (*pcVar13)();
                        }
                        iVar5 = (*pcVar13)(param_1,0xd806,local_7c,1);
                        pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                        if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109dfc);
                          (*pcVar13)();
                        }
                        iVar6 = (*pcVar13)(param_1,0xd806,&local_78,1);
                        if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != 'w')) {
                          pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                          local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x77);
                          if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109e4c);
                            (*pcVar13)();
                          }
                          iVar5 = (*pcVar13)(param_1,0xd806,local_7c,1);
                          pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                          if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109e84);
                            (*pcVar13)();
                          }
                          iVar6 = (*pcVar13)(param_1,0xd806,&local_78,1);
                          if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != 'w')) {
                            puVar12 = &DAT_00128122;
                            uVar10 = 0x99;
                            goto LAB_0010a258;
                          }
                        }
                      }
                    }
                  }
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                  local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x3c);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109ed4);
                    (*pcVar13)();
                  }
                  iVar5 = (*pcVar13)(param_1,0xd006,local_7c,1);
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109f0c);
                    (*pcVar13)();
                  }
                  iVar6 = (*pcVar13)(param_1,0xd006,&local_78,1);
                  if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != '<')) {
                    local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x3c);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109f5c);
                      (*pcVar13)();
                    }
                    iVar5 = (*pcVar13)(param_1,0xd006,local_7c,1);
                    pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109f94);
                      (*pcVar13)();
                    }
                    iVar6 = (*pcVar13)(param_1,0xd006,&local_78,1);
                    if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != '<')) {
                      local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x3c);
                      pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                      if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x109fe0);
                        (*pcVar13)();
                      }
                      iVar5 = (*pcVar13)(param_1,0xd006,local_7c,1);
                      pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                      if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                        pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a018);
                        (*pcVar13)();
                      }
                      iVar6 = (*pcVar13)(param_1,0xd006,&local_78,1);
                      if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != '<')) {
                        local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x3c);
                        pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                        if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a064);
                          (*pcVar13)();
                        }
                        iVar5 = (*pcVar13)(param_1,0xd006,local_7c,1);
                        pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                        if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                          pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a09c);
                          (*pcVar13)();
                        }
                        iVar6 = (*pcVar13)(param_1,0xd006,&local_78,1);
                        if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != '<')) {
                          pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                          local_7c[0] = CONCAT11(local_7c[0]._1_1_,0x3c);
                          if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a0ec);
                            (*pcVar13)();
                          }
                          iVar5 = (*pcVar13)(param_1,0xd006,local_7c,1);
                          pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
                          if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                            pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a124);
                            (*pcVar13)();
                          }
                          iVar6 = (*pcVar13)(param_1,0xd006,&local_78,1);
                          if ((iVar6 != 0 || iVar5 != 0) || ((char)local_78 != '<')) {
                            _printk(&DAT_0012394c,"brl_reset_after",0xa7);
                            iVar5 = -0x16;
                            goto LAB_001096d8;
                          }
                        }
                      }
                    }
                  }
                  usleep_range_state(5000,0x13ec,2);
                  pcVar13 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
                  local_7c[0] = CONCAT11(local_7c[0]._1_1_,0xfa);
                  if (*(int *)(pcVar13 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x10a184);
                    (*pcVar13)();
                  }
                  iVar5 = (*pcVar13)(param_1,0xd808,local_7c,1);
                  if ((iVar5 < 0) || (iVar5 = brl_select_spi_mode(param_1), iVar5 < 0))
                  goto LAB_001096d8;
                  _printk(&DAT_0011d625,"brl_reset_after",0xb7);
                  goto LAB_001097d0;
                }
                break;
              }
            }
            iVar5 = iVar5 + -1;
          } while (iVar5 != -1);
          _printk(&DAT_00127b31,"brl_reset_after",0x7d,0xc,&local_78);
LAB_0010a220:
          iVar5 = -0x16;
        }
      }
    }
LAB_001096d8:
    uVar10 = gpio_to_desc(uVar3);
    gpiod_direction_output_raw(uVar10,0);
    if (iVar1 < 1) {
      lVar11 = *(long *)(param_1 + 0x470);
      if (lVar11 != 0) {
        if (0 < iVar4) {
          uVar10 = gpio_to_desc(iVar4);
          gpiod_direction_output_raw(uVar10,0);
          lVar11 = *(long *)(param_1 + 0x470);
        }
        regulator_disable(lVar11);
      }
    }
    else {
      uVar10 = gpio_to_desc(iVar1);
      gpiod_direction_output_raw(uVar10,0);
    }
    if (iVar2 < 1) {
      if (*(long *)(param_1 + 0x468) != 0) {
        regulator_disable();
      }
    }
    else {
      uVar10 = gpio_to_desc(iVar2);
      gpiod_direction_output_raw(uVar10,0);
    }
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// brl_dev_confirm @ 0010a288 size=584
// signature: undefined brl_dev_confirm(void)
// callers: []
//------------------------------------------------------------

int brl_dev_confirm(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long local_48;
  long lStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x2d0);
  local_48 = 0;
  lStack_40 = -0x5555555555555556;
  if (*(int *)(*(code **)(lVar3 + 0x40) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10a2e4);
    (*pcVar1)();
  }
  iVar2 = (**(code **)(lVar3 + 0x40))(param_1,0x10000,&lStack_40,8);
  if (-1 < iVar2) {
    if (*(int *)(*(code **)(lVar3 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a318);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(lVar3 + 0x38))(param_1,0x10000,&local_48,8);
    if (-1 < iVar2) {
      if (lStack_40 != local_48) {
        usleep_range_state(5000,0x13ec,2);
        if (*(int *)(*(code **)(lVar3 + 0x40) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a36c);
          (*pcVar1)();
        }
        iVar2 = (**(code **)(lVar3 + 0x40))(param_1,0x10000,&lStack_40,8);
        if (iVar2 < 0) goto LAB_0010a49c;
        if (*(int *)(*(code **)(lVar3 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a3a0);
          (*pcVar1)();
        }
        iVar2 = (**(code **)(lVar3 + 0x38))(param_1,0x10000,&local_48,8);
        if (iVar2 < 0) goto LAB_0010a49c;
        if (lStack_40 != local_48) {
          usleep_range_state(5000,0x13ec,2);
          if (*(int *)(*(code **)(lVar3 + 0x40) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a3f4);
            (*pcVar1)();
          }
          iVar2 = (**(code **)(lVar3 + 0x40))(param_1,0x10000,&lStack_40,8);
          if (iVar2 < 0) goto LAB_0010a49c;
          if (*(int *)(*(code **)(lVar3 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a428);
            (*pcVar1)();
          }
          iVar2 = (**(code **)(lVar3 + 0x38))(param_1,0x10000,&local_48,8);
          if (iVar2 < 0) goto LAB_0010a49c;
          if (lStack_40 != local_48) {
            usleep_range_state(5000,0x13ec,2);
            _printk(&DAT_001254af,"brl_dev_confirm",0x140,8,&local_48);
            iVar2 = -0x16;
          }
        }
      }
      msleep(100);
      _printk(&DAT_0012287e,"brl_dev_confirm",0x145);
    }
  }
LAB_0010a49c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// brl_reset @ 0010a4d4 size=168
// signature: undefined brl_reset(void)
// callers: []
//------------------------------------------------------------

void brl_reset(long param_1,int param_2)

{
  undefined8 uVar1;
  
  _printk(&DAT_00127669,"brl_reset",0x14b);
  uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x1c8));
  gpiod_direction_output_raw(uVar1,0);
  usleep_range_state(2000,0x834,2);
  uVar1 = gpio_to_desc(*(undefined4 *)(param_1 + 0x1c8));
  gpiod_direction_output_raw(uVar1,1);
  if (param_2 < 0x14) {
    usleep_range_state((long)(param_2 * 1000),(long)(param_2 * 1000 + 100),2);
  }
  else {
    msleep(param_2);
  }
  brl_select_spi_mode(param_1);
  return;
}



//------------------------------------------------------------
// brl_irq_enbale @ 0010a580 size=256
// signature: undefined brl_irq_enbale(void)
// callers: []
//------------------------------------------------------------

undefined8 brl_irq_enbale(long param_1,ulong param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined *puVar5;
  undefined8 uVar6;
  
  piVar1 = (int *)(param_1 + 0x4cc);
  if ((param_2 & 1) == 0) {
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != 1) goto LAB_0010a67c;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = 0;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010a67c:
    if (iVar2 != 0) {
      disable_irq(*(undefined4 *)(param_1 + 0x4b8));
      if (debug_log_flag == '\0') {
        return 0;
      }
      puVar5 = &DAT_0011e253;
      uVar6 = 0x162;
      goto LAB_0010a6b0;
    }
  }
  else {
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != 0) goto LAB_0010a654;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = 1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010a654:
    if (iVar2 == 0) {
      enable_irq(*(undefined4 *)(param_1 + 0x4b8));
      if (debug_log_flag == '\0') {
        return 0;
      }
      puVar5 = &DAT_001214d8;
      uVar6 = 0x15c;
      goto LAB_0010a6b0;
    }
  }
  if (debug_log_flag == '\0') {
    return 0;
  }
  puVar5 = &DAT_00127b75;
  uVar6 = 0x165;
LAB_0010a6b0:
  _printk(puVar5,"brl_irq_enbale",uVar6);
  return 0;
}



//------------------------------------------------------------
// brl_read @ 0010a6bc size=60
// signature: undefined brl_read(void)
// callers: []
//------------------------------------------------------------

void brl_read(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
  if (*(int *)(pcVar1 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10a6e8);
    (*pcVar1)();
  }
  (*pcVar1)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8));
  return;
}



//------------------------------------------------------------
// brl_write @ 0010a6fc size=64
// signature: undefined brl_write(void)
// callers: []
//------------------------------------------------------------

void brl_write(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x100) + 0x18);
  if (*(int *)(pcVar1 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8229,0x10a72c);
    (*pcVar1)();
  }
  (*pcVar1)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8));
  return;
}



//------------------------------------------------------------
// brl_send_cmd @ 0010a740 size=1092
// signature: undefined brl_send_cmd(void)
// callers: [brl_event_handler, brl_get_capacitance_data]
//------------------------------------------------------------

int brl_send_cmd(long param_1,undefined2 *param_2)

{
  code *pcVar1;
  int iVar2;
  byte *pbVar3;
  long lVar4;
  int iVar5;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar4 = sp_el0;
  local_58 = *(long *)(lVar4 + 0x638);
  pbVar3 = (byte *)(param_2 + 1);
  lVar4 = *(long *)(param_1 + 0x2d0);
  local_68 = 0;
  uStack_60 = 0;
  *param_2 = 0;
  goodix_append_checksum(pbVar3,*pbVar3 - 2,0);
  if (debug_log_flag != '\0') {
    _printk(&DAT_0011d63d,"brl_send_cmd",0x18d,*pbVar3,pbVar3);
  }
  iVar5 = 6;
  do {
    if (*(int *)(*(code **)(lVar4 + 0x40) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a7e4);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(lVar4 + 0x40))(param_1,*(undefined4 *)(param_1 + 0x89),param_2,0x10);
    if (iVar2 < 0) {
      _printk(&DAT_00120f3e,"brl_send_cmd",0x194);
      goto LAB_0010aae0;
    }
    if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a818);
      (*pcVar1)();
    }
    iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
    if (iVar2 < 0) {
LAB_0010ab18:
      _printk(&DAT_0012209f,"brl_send_cmd",0x19c,iVar2);
      goto LAB_0010aae0;
    }
    _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
    if (local_68._1_1_ == -0x80) {
LAB_0010aacc:
      usleep_range_state(2000,0x834,2);
      iVar2 = 0;
      goto LAB_0010aae0;
    }
    if ((local_68 & 0xfd00) == 0) {
      usleep_range_state(1000,0x44c,2);
      if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a888);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if (iVar2 < 0) goto LAB_0010ab18;
      _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
      if (local_68._1_1_ == -0x80) goto LAB_0010aacc;
      if ((local_68 & 0xfd00) != 0) goto LAB_0010aa7c;
      usleep_range_state(1000,0x44c,2);
      if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a8f8);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if (iVar2 < 0) goto LAB_0010ab18;
      _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
      if (local_68._1_1_ == -0x80) goto LAB_0010aacc;
      if ((local_68 & 0xfd00) != 0) goto LAB_0010aa7c;
      usleep_range_state(1000,0x44c,2);
      if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a968);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if (iVar2 < 0) goto LAB_0010ab18;
      _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
      if (local_68._1_1_ == -0x80) goto LAB_0010aacc;
      if ((local_68 & 0xfd00) != 0) goto LAB_0010aa7c;
      usleep_range_state(1000,0x44c,2);
      if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10a9d8);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if (iVar2 < 0) goto LAB_0010ab18;
      _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
      if (local_68._1_1_ == -0x80) goto LAB_0010aacc;
      if ((local_68 & 0xfd00) != 0) goto LAB_0010aa7c;
      usleep_range_state(1000,0x44c,2);
      if (*(int *)(*(code **)(lVar4 + 0x38) + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10aa48);
        (*pcVar1)();
      }
      iVar2 = (**(code **)(lVar4 + 0x38))(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if (iVar2 < 0) goto LAB_0010ab18;
      _printk(&DAT_0011f85c,"brl_send_cmd",0x1a0,0x10,&local_68);
      if (local_68._1_1_ == -0x80) goto LAB_0010aacc;
      if ((local_68 & 0xfd00) != 0) goto LAB_0010aa7c;
    }
    else {
LAB_0010aa7c:
      if (local_68._1_1_ == '\x03') {
        usleep_range_state(10000,11000,2);
      }
    }
    usleep_range_state(1000,0x44c,2);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  _printk(&DAT_00127688,"brl_send_cmd",0x1b0);
  iVar2 = -0x16;
LAB_0010aae0:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// brl_send_config @ 0010ab88 size=692
// signature: undefined brl_send_config(void)
// callers: []
//------------------------------------------------------------

int brl_send_config(long param_1,void *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *__s2;
  undefined *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  local_68 = 0;
  uStack_60 = 0;
  if ((int)(uint)*(ushort *)(param_1 + 0x9f) < param_3) {
    _printk(&DAT_00127ba9,"brl_send_config",0x229,param_3);
    iVar1 = -0x16;
    goto LAB_0010acdc;
  }
  lVar6 = *(long *)(param_1 + 0x2d0);
  __s2 = (void *)__kmalloc((long)param_3,0xdc0);
  if (__s2 == (void *)0x0) {
    iVar1 = -0xc;
    goto LAB_0010acdc;
  }
  local_68._0_4_ = CONCAT22(0x404,(undefined2)local_68);
  iVar1 = send_cfg_cmd(param_1,&local_68);
  if (iVar1 == 0) {
    if (debug_log_flag != '\0') {
      _printk(&DAT_001220cf,"brl_send_config",0x239,*(undefined4 *)(param_1 + 0x9b),param_3);
    }
    pcVar5 = *(code **)(lVar6 + 0x40);
    if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ac3c);
      (*pcVar5)();
    }
    iVar1 = (*pcVar5)(param_1,*(undefined4 *)(param_1 + 0x9b),param_2,param_3);
    if (iVar1 != 0) {
      puVar3 = &DAT_001276e9;
      uVar4 = 0x23c;
      goto LAB_0010ae2c;
    }
    pcVar5 = *(code **)(lVar6 + 0x38);
    if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10ac70);
      (*pcVar5)();
    }
    iVar1 = (*pcVar5)(param_1,*(undefined4 *)(param_1 + 0x9b),__s2,param_3);
    if (iVar1 == 0) {
      iVar1 = bcmp(param_2,__s2,(long)param_3);
      if (iVar1 == 0) {
        uStack_60 = 0;
        local_68 = 0x5040000;
        iVar1 = send_cfg_cmd(param_1,&local_68);
        if (iVar1 != 0) {
          puVar3 = &DAT_00121ae0;
          uVar4 = 0x250;
          goto LAB_0010ae2c;
        }
      }
      else {
        _printk(&DAT_00122f2d,"brl_send_config",0x246);
        iVar1 = -0x16;
      }
    }
    else {
      _printk(&DAT_001204a9,"brl_send_config",0x241);
    }
  }
  else {
    puVar3 = &DAT_001276b5;
    uVar4 = 0x235;
LAB_0010ae2c:
    _printk(puVar3,"brl_send_config",uVar4,iVar1);
  }
  uStack_60 = 0;
  local_68 = 0x6040000;
  iVar2 = send_cfg_cmd(param_1,&local_68);
  if (iVar2 == 0) {
    if (iVar1 == 0) {
      _printk(&DAT_00127bdd,"brl_send_config",0x25c);
      msleep(100);
    }
  }
  else {
    _printk(&DAT_0011e274,"brl_send_config",599);
    iVar1 = -0x16;
  }
  kfree(__s2);
LAB_0010acdc:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// brl_read_config @ 0010ae40 size=676
// signature: undefined brl_read_config(void)
// callers: []
//------------------------------------------------------------

int brl_read_config(long param_1,undefined8 *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  lVar6 = *(long *)(param_1 + 0x2d0);
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  if (param_2 != (undefined8 *)0x0) {
    local_58 = 0x7040000;
    iVar2 = send_cfg_cmd(param_1,&local_58);
    if (iVar2 != 0) {
      _printk(&DAT_00123986,"brl_read_config",0x276);
      goto LAB_0010ae88;
    }
    pcVar5 = *(code **)(lVar6 + 0x38);
    if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10af08);
      (*pcVar5)();
    }
    iVar2 = (*pcVar5)(param_1,*(undefined4 *)(param_1 + 0x9b),&local_98,0x40);
    if (iVar2 == 0) {
      iVar2 = checksum_cmp(&local_98,0x40,0);
      if (iVar2 != 0) {
        puVar3 = &DAT_0011f2c0;
        uVar4 = 0x282;
LAB_0010b040:
        _printk(puVar3,"brl_read_config",uVar4);
        goto LAB_0010b060;
      }
      if ((*(ushort *)(param_1 + 0x9f) < uStack_60._3_2_) || (param_3 < (int)(uint)uStack_60._3_2_))
      {
        _printk(&DAT_0011f882,"brl_read_config",0x28b);
        goto LAB_0010b060;
      }
      param_2[4] = local_78;
      param_2[5] = uStack_70;
      param_2[6] = local_68;
      param_2[7] = uStack_60;
      *param_2 = local_98;
      param_2[1] = uStack_90;
      param_2[2] = local_88;
      param_2[3] = uStack_80;
      pcVar5 = *(code **)(lVar6 + 0x38);
      if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10af8c);
        (*pcVar5)();
      }
      iVar2 = (*pcVar5)(param_1,*(int *)(param_1 + 0x9b) + 0x40,param_2 + 8);
      if (iVar2 != 0) {
        puVar3 = &DAT_0011f8b9;
        uVar4 = 0x294;
        goto LAB_0010b024;
      }
      _printk(&DAT_001239c2,"brl_read_config",0x298,uStack_60._3_2_);
      iVar2 = checksum_cmp(param_2 + 8,uStack_60._3_2_,1);
      if (iVar2 != 0) {
        puVar3 = &DAT_00120ae4;
        uVar4 = 0x29b;
        goto LAB_0010b040;
      }
      _printk(&DAT_00122f64,"brl_read_config",0x2a0,(uStack_60 >> 0x18 & 0xffff) + 0x40);
      bVar1 = true;
    }
    else {
      puVar3 = &DAT_001228ad;
      uVar4 = 0x27d;
LAB_0010b024:
      _printk(puVar3,"brl_read_config",uVar4,iVar2);
LAB_0010b060:
      bVar1 = false;
    }
    uStack_50 = 0;
    local_58 = 0x8040000;
    iVar2 = send_cfg_cmd(param_1,&local_58);
    if (iVar2 == 0) {
      if (bVar1) {
        iVar2 = uStack_60._3_2_ + 0x40;
        goto LAB_0010ae88;
      }
    }
    else {
      _printk(&DAT_001242a0,"brl_read_config",0x2a6);
    }
  }
  iVar2 = -0x16;
LAB_0010ae88:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// brl_read_version @ 0010b0e8 size=744
// signature: undefined brl_read_version(void)
// callers: []
//------------------------------------------------------------

undefined8 brl_read_version(long param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined4 local_50;
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  local_50 = 0;
  local_60 = 0;
  local_58 = 0;
  lVar6 = *(long *)(param_1 + 0x2d0);
  local_70 = 0;
  local_68 = 0;
  pcVar5 = *(code **)(lVar6 + 0x38);
  uVar1 = 0x1000c;
  if (*(int *)(*(long *)(param_1 + 0x100) + 4) != 4) {
    uVar1 = 0x10014;
  }
  if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10b16c);
    (*pcVar5)();
  }
  iVar2 = (*pcVar5)(param_1,uVar1,&local_68,0x1c);
  if (iVar2 == 0) {
    iVar2 = checksum_cmp(&local_68,0x1c,0);
    if (iVar2 != 0) {
      _printk(&DAT_001234eb,"brl_read_version",0x2cf);
      _printk(&DAT_0011e306,"brl_read_version",0x2d0,0x1c,&local_68);
      uVar3 = 10000;
      uVar4 = 11000;
      goto LAB_0010b1f4;
    }
LAB_0010b244:
    *param_2 = local_68;
    param_2[1] = local_60;
    param_2[2] = local_58;
    *(undefined4 *)(param_2 + 3) = local_50;
    local_70._0_6_ = (undefined6)local_68;
    _printk(&DAT_001228dc,"brl_read_version",0x2da,&local_70);
    _printk(&DAT_001264f0,"brl_read_version",0x2dc,3,(long)param_2 + 6);
    _printk(&DAT_00122103,"brl_read_version",0x2dd,(long)param_2 + 10);
    _printk(&DAT_0012155b,"brl_read_version",0x2df,4,(long)param_2 + 0x12);
    _printk(&DAT_0011fea0,"brl_read_version",0x2e0,*(undefined1 *)((long)param_2 + 0x17));
    uVar3 = 0;
  }
  else {
    _printk(&DAT_001258ed,"brl_read_version",0x2c6,iVar2,0);
    uVar3 = 5000;
    uVar4 = 0x13ec;
LAB_0010b1f4:
    usleep_range_state(uVar3,uVar4,2);
    pcVar5 = *(code **)(lVar6 + 0x38);
    if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10b228);
      (*pcVar5)();
    }
    iVar2 = (*pcVar5)(param_1,uVar1,&local_68,0x1c);
    if (iVar2 == 0) {
      iVar2 = checksum_cmp(&local_68,0x1c,0);
      if (iVar2 == 0) goto LAB_0010b244;
      _printk(&DAT_001234eb,"brl_read_version",0x2cf);
      _printk(&DAT_0011e306,"brl_read_version",0x2d0,0x1c,&local_68);
      usleep_range_state(10000,11000,2);
      uVar3 = 0xfffffffe;
    }
    else {
      _printk(&DAT_001258ed,"brl_read_version",0x2c6,iVar2,1);
      usleep_range_state(5000,0x13ec,2);
      uVar3 = 0xffffffff;
    }
    _printk(&DAT_001239e4,"brl_read_version",0x2d5);
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// brl_get_ic_info @ 0010b3d4 size=2352
// signature: undefined brl_get_ic_info(void)
// callers: []
//------------------------------------------------------------

void brl_get_ic_info(long param_1,undefined2 *param_2)

{
  byte *pbVar1;
  ulong uVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  byte bVar7;
  undefined2 uVar8;
  int iVar9;
  undefined *puVar10;
  undefined8 uVar11;
  ulong uVar12;
  undefined8 uVar13;
  code *pcVar14;
  ulong uVar15;
  long lVar16;
  int iVar17;
  size_t __n;
  ushort local_474 [2];
  undefined2 local_470;
  undefined8 local_46e;
  undefined8 local_466;
  undefined8 local_45e;
  undefined2 local_456;
  undefined4 local_454;
  byte local_450;
  undefined1 local_44f [2];
  undefined1 local_44d [2];
  undefined1 local_44b [2];
  undefined1 local_449 [2];
  undefined1 local_447 [2];
  byte bStack_445;
  undefined2 uStack_444;
  byte abStack_43b [8];
  byte abStack_433 [8];
  byte abStack_42b [8];
  byte abStack_423 [8];
  byte abStack_41b [8];
  byte abStack_413 [8];
  byte abStack_40b [8];
  byte abStack_403 [8];
  byte abStack_3fb [8];
  byte abStack_3f3 [8];
  byte abStack_3eb [8];
  byte abStack_3e3 [8];
  byte abStack_3db [875];
  long local_70;
  
  lVar16 = sp_el0;
  local_70 = *(long *)(lVar16 + 0x638);
  local_474[0] = 0;
  memset(&local_470,0,0x400);
  iVar17 = 0;
  lVar16 = *(long *)(param_1 + 0x2d0);
  uVar4 = 0x10068;
  if (*(int *)(*(long *)(param_1 + 0x100) + 4) != 4) {
    uVar4 = 0x10070;
  }
  do {
    pcVar14 = *(code **)(lVar16 + 0x38);
    if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10b4c4);
      (*pcVar14)();
    }
    iVar9 = (*pcVar14)(param_1,uVar4,local_474,2);
    if (iVar9 == 0) {
      if (local_474[0] < 0x400) {
        pcVar14 = *(code **)(lVar16 + 0x38);
        if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10b500);
          (*pcVar14)();
        }
        iVar9 = (*pcVar14)(param_1,uVar4,&local_470);
        if (iVar9 != 0) {
          puVar10 = &DAT_0011f2ef;
          uVar11 = 0x3d0;
          goto LAB_0010b54c;
        }
        iVar9 = is_risk_data(&local_470,local_474[0]);
        if (iVar9 == 0) {
          iVar9 = checksum_cmp(&local_470,local_474[0],0);
          if (iVar9 == 0) {
            uVar12 = (ulong)local_450;
            *(undefined8 *)(param_2 + 1) = local_46e;
            *(undefined8 *)(param_2 + 5) = local_466;
            *(undefined8 *)(param_2 + 9) = local_45e;
            param_2[0xd] = local_456;
            *(undefined4 *)(param_2 + 0xe) = local_454;
            *param_2 = local_470;
            *(byte *)(param_2 + 0x10) = local_450;
            if (local_450 < 6) {
              if ((((local_450 != 0) &&
                   (*(undefined1 (*) [2])((long)param_2 + 0x21) = local_44f, local_450 != 1)) &&
                  (*(undefined1 (*) [2])((long)param_2 + 0x23) = local_44d, local_450 != 2)) &&
                 ((*(undefined1 (*) [2])((long)param_2 + 0x25) = local_44b, local_450 != 3 &&
                  (*(undefined1 (*) [2])((long)param_2 + 0x27) = local_449, local_450 != 4)))) {
                *(undefined1 (*) [2])((long)param_2 + 0x29) = local_447;
              }
              lVar16 = uVar12 * 2;
              bVar7 = local_44f[lVar16];
              uVar12 = (ulong)bVar7;
              *(byte *)((long)param_2 + 0x2b) = bVar7;
              if (5 < bVar7) {
                puVar10 = &DAT_001242fb;
                uVar11 = 0x315;
                goto LAB_0010b838;
              }
              if (((bVar7 != 0) &&
                  (param_2[0x16] = *(undefined2 *)(local_44f + lVar16 + 1), bVar7 != 1)) &&
                 ((param_2[0x17] = *(undefined2 *)(local_44d + lVar16 + 1), bVar7 != 2 &&
                  ((param_2[0x18] = *(undefined2 *)(local_44b + lVar16 + 1), bVar7 != 3 &&
                   (param_2[0x19] = *(undefined2 *)(local_449 + lVar16 + 1), bVar7 != 4)))))) {
                param_2[0x1a] = *(undefined2 *)(local_447 + lVar16 + 1);
              }
              uVar2 = lVar16 + 0x22 + uVar12 * 2;
              if (0x3ff < uVar2) goto LAB_0010bd00;
              pbVar3 = (byte *)((long)(local_44f + lVar16 + 1) + uVar12 * 2);
              bVar7 = *pbVar3;
              uVar12 = (ulong)bVar7;
              *(byte *)(param_2 + 0x1b) = bVar7;
              if (5 < bVar7) {
                puVar10 = &DAT_001281b4;
                uVar11 = 800;
                goto LAB_0010b838;
              }
              uVar15 = uVar2 | 1;
              if (bVar7 != 0) {
                if ((0x400 < uVar15) || (uVar15 == 0x3ff)) goto LAB_0010bd00;
                *(undefined2 *)((long)param_2 + 0x37) = *(undefined2 *)(pbVar3 + 1);
                if (bVar7 != 1) {
                  if ((0x3fd < uVar2) || (uVar2 == 0x3fc)) goto LAB_0010bd00;
                  *(undefined2 *)((long)param_2 + 0x39) = *(undefined2 *)(pbVar3 + 3);
                  if (bVar7 != 2) {
                    if ((0x3fb < uVar2) || (uVar2 == 0x3fa)) goto LAB_0010bd00;
                    *(undefined2 *)((long)param_2 + 0x3b) = *(undefined2 *)(pbVar3 + 5);
                    if (bVar7 != 3) {
                      if ((0x3f9 < uVar2) || (uVar2 == 0x3f8)) goto LAB_0010bd00;
                      *(undefined2 *)((long)param_2 + 0x3d) = *(undefined2 *)(pbVar3 + 7);
                      if (bVar7 != 4) {
                        if ((0x3f7 < uVar2) || (uVar2 == 0x3f6)) goto LAB_0010bd00;
                        *(undefined2 *)((long)param_2 + 0x3f) = *(undefined2 *)(pbVar3 + 9);
                      }
                    }
                  }
                }
              }
              uVar15 = uVar15 + uVar12 * 2;
              if (0x400 < uVar15) goto LAB_0010bd00;
              pbVar3 = pbVar3 + 1 + uVar12 * 2;
              bVar7 = *pbVar3;
              uVar12 = (ulong)bVar7;
              *(byte *)((long)param_2 + 0x41) = bVar7;
              if (5 < bVar7) {
                puVar10 = &DAT_001215a1;
                uVar11 = 0x32b;
                goto LAB_0010b838;
              }
              pbVar1 = pbVar3 + 1;
              if (bVar7 != 0) {
                if ((0x3ff < uVar15) || ((uVar15 & 0xffe) == 0x3fe)) goto LAB_0010bd00;
                param_2[0x21] = *(undefined2 *)pbVar1;
                if (bVar7 != 1) {
                  if ((0x3fd < uVar15) || ((uVar15 & 0xffe) == 0x3fc)) goto LAB_0010bd00;
                  param_2[0x22] = *(undefined2 *)(pbVar3 + 3);
                  if (bVar7 != 2) {
                    if ((0x3fb < uVar15) || ((uVar15 & 0xffe) == 0x3fa)) goto LAB_0010bd00;
                    param_2[0x23] = *(undefined2 *)(pbVar3 + 5);
                    if (bVar7 != 3) {
                      if ((0x3f9 < uVar15) || ((uVar15 & 0xffe) == 0x3f8)) goto LAB_0010bd00;
                      param_2[0x24] = *(undefined2 *)(pbVar3 + 7);
                      if (bVar7 != 4) {
                        if ((0x3f7 < uVar15) || ((uVar15 & 0xffe) == 0x3f6)) goto LAB_0010bd00;
                        param_2[0x25] = *(undefined2 *)(pbVar3 + 9);
                      }
                    }
                  }
                }
              }
              if (0x3ff < uVar15 + 1 + uVar12 * 2) {
LAB_0010bd00:
                    /* WARNING: Does not return */
                pcVar14 = (code *)SoftwareBreakpoint(1,0x10bd04);
                (*pcVar14)();
              }
              pbVar1 = pbVar1 + uVar12 * 2;
              bVar7 = *pbVar1;
              uVar12 = (ulong)bVar7;
              *(byte *)(param_2 + 0x26) = bVar7;
              if (bVar7 < 9) {
                if (bVar7 == 0) {
                  __n = 0;
                }
                else {
                  __n = uVar12 << 1;
                  memcpy((void *)((long)param_2 + 0x4d),pbVar1 + 1,__n);
                }
                pbVar3 = pbVar1 + 1 + __n;
                uVar11 = *(undefined8 *)(pbVar3 + 0x68);
                uVar8 = *(undefined2 *)(pbVar3 + 0x70);
                *(undefined8 *)((long)param_2 + 0xbd) = *(undefined8 *)(pbVar3 + 0x60);
                *(undefined8 *)((long)param_2 + 0xc5) = uVar11;
                uVar11 = *(undefined8 *)(pbVar3 + 0x40);
                uVar5 = *(undefined8 *)(pbVar3 + 0x48);
                *(undefined2 *)((long)param_2 + 0xcd) = uVar8;
                uVar13 = *(undefined8 *)(pbVar3 + 0x50);
                uVar6 = *(undefined8 *)(pbVar3 + 0x58);
                *(undefined8 *)((long)param_2 + 0x9d) = uVar11;
                *(undefined8 *)((long)param_2 + 0xa5) = uVar5;
                uVar11 = *(undefined8 *)(pbVar3 + 0x20);
                uVar5 = *(undefined8 *)(pbVar3 + 0x28);
                *(undefined8 *)((long)param_2 + 0xad) = uVar13;
                *(undefined8 *)((long)param_2 + 0xb5) = uVar6;
                uVar13 = *(undefined8 *)(pbVar3 + 0x30);
                uVar6 = *(undefined8 *)(pbVar3 + 0x38);
                *(undefined8 *)((long)param_2 + 0x7d) = uVar11;
                *(undefined8 *)((long)param_2 + 0x85) = uVar5;
                uVar11 = *(undefined8 *)pbVar3;
                uVar5 = *(undefined8 *)(pbVar3 + 8);
                *(undefined8 *)((long)param_2 + 0x8d) = uVar13;
                *(undefined8 *)((long)param_2 + 0x95) = uVar6;
                uVar13 = *(undefined8 *)(pbVar3 + 0x10);
                uVar6 = *(undefined8 *)(pbVar3 + 0x18);
                *(undefined8 *)((long)param_2 + 0x5d) = uVar11;
                *(undefined8 *)((long)param_2 + 0x65) = uVar5;
                *(undefined8 *)((long)param_2 + 0x6d) = uVar13;
                *(undefined8 *)((long)param_2 + 0x75) = uVar6;
                _printk(&DAT_00123a15,"print_ic_info",0x36f,local_470);
                _printk(&DAT_0011f8e6,"print_ic_info",0x371,*(undefined1 *)(param_2 + 1));
                _printk(&DAT_0011db57,"print_ic_info",0x373,*(undefined1 *)((long)param_2 + 3));
                _printk(&DAT_00122959,"print_ic_info",0x375,*(undefined1 *)(param_2 + 2));
                _printk(&DAT_001249f0,"print_ic_info",0x377,*(undefined1 *)((long)param_2 + 5));
                _printk(&DAT_0011e828,"print_ic_info",0x379,*(undefined4 *)(param_2 + 3));
                _printk(&DAT_00123a4b,"print_ic_info",0x37b,*(undefined1 *)(param_2 + 5));
                _printk(&DAT_00127c15,"print_ic_info",0x37d,*(undefined1 *)((long)param_2 + 0xb));
                _printk(&DAT_00122f9a,"print_ic_info",0x37f,*(undefined1 *)(param_2 + 6));
                _printk(&DAT_00126bbd,"print_ic_info",0x381,*(undefined1 *)((long)param_2 + 0xd));
                _printk(&DAT_00126511,"print_ic_info",900,*(undefined1 *)(param_2 + 7),
                        *(undefined1 *)((long)param_2 + 0xf),*(undefined1 *)(param_2 + 8),
                        *(undefined1 *)((long)param_2 + 0x11));
                _printk(&DAT_00125552,"print_ic_info",0x387,param_2[9]);
                _printk(&DAT_00125f8e,"print_ic_info",0x389,param_2[10]);
                _printk(&DAT_0011db91,"print_ic_info",0x38b,param_2[0xb]);
                _printk(&DAT_0011dbcb,"print_ic_info",0x38d,param_2[0xc]);
                _printk(&DAT_0011ec95,"print_ic_info",0x38f,param_2[0xd]);
                _printk(&DAT_0011d65f,"print_ic_info",0x393,*(undefined1 *)(param_2 + 0xe),
                        *(undefined1 *)((long)param_2 + 0x1d),*(undefined1 *)(param_2 + 0xf),
                        *(undefined1 *)((long)param_2 + 0x1f));
                _printk(&DAT_0012706c,"print_ic_info",0x396,*(undefined4 *)((long)param_2 + 0x5d),
                        *(undefined2 *)((long)param_2 + 0x61));
                _printk(&DAT_001204da,"print_ic_info",0x398,*(undefined4 *)((long)param_2 + 99),
                        *(undefined2 *)((long)param_2 + 0x67));
                _printk(&DAT_0011e861,"print_ic_info",0x39a,*(undefined4 *)((long)param_2 + 0x69),
                        *(undefined2 *)((long)param_2 + 0x6d));
                _printk(&DAT_0011f920,"print_ic_info",0x39c,*(undefined4 *)((long)param_2 + 0x6f),
                        *(undefined2 *)((long)param_2 + 0x73));
                _printk(&DAT_00122fd4,"print_ic_info",0x39e,*(undefined4 *)((long)param_2 + 0x75));
                _printk(&DAT_001215d1,"print_ic_info",0x3a0,*(undefined4 *)((long)param_2 + 0x89),
                        *(undefined2 *)((long)param_2 + 0x8d));
                _printk(&DAT_0011fec1,"print_ic_info",0x3a2,*(undefined2 *)((long)param_2 + 0x8f));
                _printk(&DAT_00123523,"print_ic_info",0x3a4,*(undefined4 *)((long)param_2 + 0x95));
                _printk(&DAT_00126555,"print_ic_info",0x3a6,*(undefined4 *)((long)param_2 + 0x99));
                _printk(&DAT_0011f95e,"print_ic_info",0x3a8,*(undefined4 *)((long)param_2 + 0xa1));
                _printk(&DAT_0011d6a2,"print_ic_info",0x3aa,*(undefined4 *)((long)param_2 + 0xa5));
                _printk(&DAT_0011dc05,"print_ic_info",0x3ac,*(undefined4 *)((long)param_2 + 0xc1),
                        *(undefined2 *)((long)param_2 + 0xc5));
                _printk(&DAT_0011eccf,"print_ic_info",0x3ae,*(undefined4 *)((long)param_2 + 0xcb));
                if (((*(int *)((long)param_2 + 0x5d) == 0) || (*(int *)((long)param_2 + 0x6f) == 0))
                   || (*(int *)((long)param_2 + 0x89) == 0)) {
                  puVar10 = &DAT_00124f53;
                  uVar11 = 0x3f2;
                  goto LAB_0010b5a0;
                }
                uVar11 = 0;
                goto LAB_0010b5a8;
              }
              puVar10 = &DAT_0011e32a;
              uVar11 = 0x336;
              uVar13 = 8;
            }
            else {
              puVar10 = &DAT_00126b8b;
              uVar11 = 0x30a;
LAB_0010b838:
              uVar13 = 5;
            }
            _printk(puVar10,"convert_ic_info",uVar11,uVar12,uVar13);
            puVar10 = &DAT_0012551e;
            uVar11 = 0x3e9;
            goto LAB_0010b5a0;
          }
          puVar10 = &DAT_0012292d;
          uVar11 = 0x3dc;
        }
        else {
          puVar10 = &DAT_00121578;
          uVar11 = 0x3d6;
        }
        _printk(puVar10,"brl_get_ic_info",uVar11);
        goto LAB_0010b550;
      }
      _printk(&DAT_001254e6,"brl_get_ic_info",0x3ca,local_474[0],iVar17);
    }
    else {
      puVar10 = &DAT_001228fb;
      uVar11 = 0x3c3;
LAB_0010b54c:
      _printk(puVar10,"brl_get_ic_info",uVar11,iVar9);
LAB_0010b550:
      usleep_range_state(5000,0x13ec,2);
    }
    iVar17 = iVar17 + 1;
    if (iVar17 == 3) {
      puVar10 = &DAT_00121b19;
      uVar11 = 0x3e3;
LAB_0010b5a0:
      _printk(puVar10,"brl_get_ic_info",uVar11);
      uVar11 = 0xffffffea;
LAB_0010b5a8:
      lVar16 = sp_el0;
      if (*(long *)(lVar16 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail(uVar11);
      }
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// brl_esd_check @ 0010bd08 size=340
// signature: undefined brl_esd_check(void)
// callers: []
//------------------------------------------------------------

int brl_esd_check(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  char local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  iVar1 = *(int *)(param_1 + 0xf7);
  local_3c[0] = '\0';
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
    if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10bd68);
      (*pcVar4)();
    }
    iVar3 = (*pcVar4)(param_1,iVar1,local_3c,1);
    if (iVar3 == 0) {
      if (local_3c[0] == -0x56) {
        _printk(&DAT_001270aa,"brl_esd_check",0x40b,0xaa);
        iVar3 = -0x16;
      }
      else {
        pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
        local_3c[0] = -0x56;
        if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10bdb4);
          (*pcVar4)();
        }
        iVar3 = (*pcVar4)(param_1,iVar1,local_3c,1);
        if (iVar3 != 0) {
          _printk(&DAT_0012432f,"brl_esd_check",0x411);
        }
      }
    }
    else {
      _printk(&DAT_00120b13,"brl_esd_check",0x406,iVar3);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// brl_event_handler @ 0010be60 size=2012
// signature: undefined brl_event_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int brl_event_handler(long param_1,undefined4 *param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  bool bVar7;
  bool bVar8;
  ulong uVar9;
  char cVar10;
  int iVar11;
  undefined *puVar12;
  undefined8 uVar13;
  ulong uVar14;
  undefined1 uVar15;
  undefined4 uVar16;
  code *pcVar17;
  int iVar18;
  long lVar19;
  uint uVar20;
  byte bVar21;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar19 = sp_el0;
  local_58 = *(long *)(lVar19 + 0x638);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  pcVar17 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
  if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10bec8);
    (*pcVar17)();
  }
  iVar11 = (*pcVar17)(param_1,*(undefined4 *)(param_1 + 0xb5),&local_88,0x1a);
  if (iVar11 != 0) {
    if (debug_log_flag != '\0') {
      _printk(&DAT_001270d5,"brl_event_handler",0x5c4);
    }
    goto LAB_0010bf28;
  }
  iVar11 = checksum_cmp(&local_88,8,0);
  cVar10 = debug_log_flag;
  if (iVar11 != 0) {
    if ((debug_log_flag != '\0') &&
       (_printk(&DAT_00125fc8,"brl_event_handler",0x5c9), debug_log_flag != '\0')) {
      _printk(&DAT_00127104,"brl_event_handler",0x5ca,8,&local_88);
    }
    iVar11 = -0x16;
    *param_2 = 1;
    goto LAB_0010bf28;
  }
  if ((char)(byte)local_88 < '\0') {
    *(byte *)(param_1 + 0x6d8) = (byte)local_88 >> 4 & 1;
    if (cVar10 != '\0') {
      _printk(&DAT_00120f88,"brl_event_handler",0x5d3);
    }
    lVar19 = *(long *)(param_1 + 0x2d0);
    memset(param_2,0,0x13c);
    cVar10 = debug_log_flag;
    goodix_touch_handler_buffer = local_88;
    _DAT_0012a3e0 = local_80;
    _DAT_0012a3e8 = local_78;
    DAT_0012a3f0 = (undefined2)local_70;
    if ((((uint)(local_88 >> 0x10) & 0xff) >> 4 & 1) == 0) {
      *(undefined1 *)(param_2 + 4) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 4) = 1;
      if (cVar10 != '\0') {
        _printk(&DAT_00120fb6,"goodix_touch_handler",0x48f,local_88._2_1_ & 0xf);
      }
    }
    if (*(int *)(param_1 + 0x614) != 0) {
      uVar2 = goodix_touch_handler_buffer._2_1_ & 0x20;
      if (*(uint *)(param_1 + 0x4c8) != uVar2) {
        *(uint *)(param_1 + 0x4c8) = uVar2;
        pcVar17 = *(code **)(*(long *)(param_1 + 0x680) + 0x38);
        if (*(int *)(pcVar17 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
          pcVar17 = (code *)SoftwareBreakpoint(0x8229,0x10c488);
          (*pcVar17)();
        }
        (*pcVar17)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar2 >> 5);
        _printk(&DAT_0011e89f,"goodix_touch_handler",0x49a,*(undefined4 *)(param_1 + 0x4c8));
      }
    }
    uVar20 = (uint)goodix_touch_handler_buffer._2_1_;
    uVar14 = goodix_touch_handler_buffer & 0xf0000;
    uVar9 = goodix_touch_handler_buffer & 0xf0000;
    uVar2 = goodix_touch_handler_buffer._2_1_ & 0xf;
    if (10 < uVar2) {
      if (debug_log_flag != '\0') {
        _printk(&DAT_0011e35e,"goodix_touch_handler",0x4b2,uVar2);
      }
      goto LAB_0010c064;
    }
    if (2 < uVar2) {
      pcVar17 = *(code **)(lVar19 + 0x38);
      if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10c5f8);
        (*pcVar17)();
      }
      iVar11 = (*pcVar17)(param_1,*(int *)(param_1 + 0xb5) + 0x1a,&DAT_0012a3f2,uVar2 * 8 + -0x10);
      if (iVar11 != 0) {
        if (debug_log_flag != '\0') {
          _printk(&DAT_0011f31f,"goodix_touch_handler",0x4bc);
        }
        goto LAB_0010bf28;
      }
LAB_0010c078:
      bVar21 = DAT_0012a3e0 & 0xf;
      if ((DAT_0012a3e0 & 0xd) == 1) {
        iVar11 = checksum_cmp(&DAT_0012a3e0,0x12,0);
        if (iVar11 == 0) goto LAB_0010c1f8;
        if ((debug_log_flag != '\0') &&
           (_printk(&DAT_0012054a,"goodix_touch_handler",0x4c8), debug_log_flag != '\0')) {
          _printk(&DAT_00122993,"goodix_touch_handler",0x4ca,0x12,&DAT_0012a3e0);
        }
      }
      else {
        uVar3 = uVar2 << 3 | 2;
        iVar11 = checksum_cmp(&DAT_0012a3e0,uVar3,0);
        if (iVar11 == 0) {
LAB_0010c1f8:
          bVar8 = true;
          goto LAB_0010c1fc;
        }
        if ((debug_log_flag != '\0') &&
           (_printk(&DAT_0012054a,"goodix_touch_handler",0x4d1), debug_log_flag != '\0')) {
          _printk(&DAT_00122993,"goodix_touch_handler",0x4d3,uVar3,&DAT_0012a3e0);
        }
      }
LAB_0010c064:
      iVar11 = -0x16;
      goto LAB_0010bf28;
    }
    if ((goodix_touch_handler_buffer & 0xf0000) != 0) goto LAB_0010c078;
    bVar8 = false;
    bVar21 = 0;
LAB_0010c1fc:
    if (debug_log_flag != '\0') {
      _printk(&DAT_0011e387,"goodix_touch_handler",0x4d9,local_88 & 0xff);
    }
    uVar3 = (byte)local_88 & 8;
    if (goodix_touch_handler_pre_flags != uVar3) {
      uVar15 = 0x55;
      if ((local_88 & 8) != 0) {
        uVar15 = 0x46;
      }
      *(undefined1 *)((long)param_2 + 9) = uVar15;
    }
    bVar7 = false;
    if ((bVar21 & 0xfd) == 1) {
      bVar7 = bVar8;
    }
    goodix_touch_handler_pre_flags = uVar3;
    if (bVar7) {
      if (goodix_touch_handler_pre_finger_num == '\0') {
        uVar16 = 1;
        goodix_touch_handler_pre_pen_num = '\x01';
        param_2[1] = 2;
        param_2[0x42] = 0x140;
        if (uVar9 != 0) {
          iVar11 = (int)_DAT_0012a3e8;
          uVar4 = DAT_0012a3e4;
          iVar18 = (int)DAT_0012a3ea;
          uVar5 = DAT_0012a3e6;
          param_2[0x43] = (uint)DAT_0012a3e2;
          uVar16 = 2;
          param_2[0x44] = (uint)uVar4;
          param_2[0x45] = (uint)uVar5;
          *(char *)(param_2 + 0x46) =
               (char)((uint)(iVar11 * 0x147b) >> 0x13) - (char)(iVar11 * 0x147b >> 0x1f);
          *(char *)((long)param_2 + 0x119) =
               (char)((uint)(iVar18 * 0x147b) >> 0x13) - (char)(iVar18 * 0x147b >> 0x1f);
        }
        param_2[0x41] = uVar16;
        bVar21 = goodix_touch_handler_buffer._3_1_;
        param_2[0x48] = 0x14b;
        if ((bVar21 >> 1 & 1) != 0) {
          param_2[0x47] = 2;
        }
        param_2[0x4a] = 0x14c;
        if (((bVar21 >> 1 & 7) >> 1 & 1) != 0) {
          param_2[0x49] = 2;
        }
      }
      else {
        param_2[3] = 0;
        goodix_touch_handler_pre_finger_num = '\0';
        param_2[1] = 1;
      }
    }
    else if (goodix_touch_handler_pre_pen_num == '\x01') {
      bVar21 = goodix_touch_handler_buffer._3_1_;
      param_2[1] = 2;
      *(undefined8 *)(param_2 + 0x41) = 0x14000000001;
      param_2[0x48] = 0x14b;
      if ((bVar21 >> 1 & 1) != 0) {
        param_2[0x47] = 2;
      }
      param_2[0x4a] = 0x14c;
      if (((bVar21 >> 1 & 7) >> 1 & 1) != 0) {
        param_2[0x49] = 2;
      }
      goodix_touch_handler_pre_pen_num = '\0';
    }
    else {
      param_2[1] = 1;
      if (uVar14 == 0) {
LAB_0010c528:
        uVar20 = 0;
      }
      else {
        lVar19 = 0;
        do {
          bVar21 = (&DAT_0012a3e0)[lVar19];
          uVar14 = (ulong)(bVar21 >> 4);
          if (0x9f < bVar21) {
            _printk(&DAT_00121b40,"goodix_parse_finger",0x431);
            goto LAB_0010c528;
          }
          param_2[uVar14 * 6 + 6] = (uint)((bVar21 & 0xf) == 4);
          if ((((0x59 < lVar19 + 10U) || (lVar19 == 0x50)) || (0x5a < lVar19 + 0xcU)) ||
             (0x5a < lVar19 + 0xeU)) {
                    /* WARNING: Does not return */
            pcVar17 = (code *)SoftwareBreakpoint(1,0x10c63c);
            (*pcVar17)();
          }
          uVar4 = *(ushort *)((long)&DAT_0012a3e2 + lVar19);
          uVar5 = *(ushort *)((long)&DAT_0012a3e4 + lVar19);
          lVar1 = lVar19 + 8;
          uVar6 = *(ushort *)((long)&DAT_0012a3e6 + lVar19);
          param_2[uVar14 * 6 + 5] = 2;
          param_2[uVar14 * 6 + 7] = (uint)uVar4;
          param_2[uVar14 * 6 + 8] = (uint)uVar5;
          param_2[uVar14 * 6 + 9] = (uint)uVar6;
          lVar19 = lVar1;
        } while ((uVar20 & 0xf) * 8 != (int)lVar1);
        uVar20 = uVar2;
      }
      param_2[3] = uVar20;
      goodix_touch_handler_pre_finger_num = (char)uVar2;
    }
    if (((*(char *)(param_1 + 0x2b6) != '\0') && (*(int *)(param_1 + 0x628) != 0)) &&
       ((*(int *)(param_1 + 0x5f8) != 0 && ((goodix_touch_handler_buffer._3_1_ >> 5 & 1) == 0)))) {
      uStack_60 = 0;
      local_68 = 0x1a4050000;
      iVar11 = brl_send_cmd(param_1,&local_68);
      if (iVar11 < 0) {
        puVar12 = &DAT_0012435c;
        uVar13 = 0x50c;
      }
      else {
        puVar12 = &DAT_001229b1;
        uVar13 = 0x50e;
      }
      _printk(puVar12,"goodix_touch_handler",uVar13);
      iVar11 = 0;
      goto LAB_0010bf28;
    }
LAB_0010c55c:
    iVar11 = 0;
  }
  else {
    if (((byte)local_88 >> 6 & 1) == 0) {
      if (((byte)local_88 >> 5 & 1) != 0) {
        iVar11 = 0;
        param_2[1] = 8;
        *(byte *)((long)param_2 + 10) = local_88._2_1_;
        *(undefined1 *)((long)param_2 + 9) = local_88._4_1_;
        *(undefined8 *)(param_2 + 0x4b) = local_80;
        *(undefined8 *)(param_2 + 0x4d) = local_78;
        goto LAB_0010bf28;
      }
      _printk(&DAT_0012249c,"brl_event_handler",0x5e7);
      goto LAB_0010c064;
    }
    param_2[1] = 4;
    if (local_88._2_1_ == '\x03') {
      uVar15 = 3;
    }
    else {
      if (local_88._2_1_ != '\x01') {
        if (debug_log_flag != '\0') {
          _printk(&DAT_00120518,"brl_event_handler",0x5df);
          iVar11 = 0;
          goto LAB_0010bf28;
        }
        goto LAB_0010c55c;
      }
      uVar15 = 1;
    }
    iVar11 = 0;
    *(undefined1 *)(param_2 + 2) = uVar15;
  }
LAB_0010bf28:
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}



//------------------------------------------------------------
// brl_after_event_handler @ 0010c640 size=120
// signature: undefined brl_after_event_handler(void)
// callers: []
//------------------------------------------------------------

void brl_after_event_handler(long param_1)

{
  long lVar1;
  code *pcVar2;
  undefined1 local_1c [4];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c[0] = 0;
  pcVar2 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
  if (*(int *)(pcVar2 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10c68c);
    (*pcVar2)();
  }
  (*pcVar2)(param_1,*(undefined4 *)(param_1 + 0xb5),local_1c,1);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// brl_get_capacitance_data @ 0010c6bc size=1728
// signature: undefined brl_get_capacitance_data(void)
// callers: []
//------------------------------------------------------------

int brl_get_capacitance_data(long param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  byte bVar6;
  byte bVar7;
  int iVar8;
  char cVar9;
  bool bVar10;
  long lVar11;
  ulong uVar12;
  code *pcVar13;
  int iVar14;
  undefined *puVar15;
  undefined8 uVar16;
  int iVar17;
  char local_8c [4];
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uVar3 = *(undefined4 *)(param_1 + 0xb5);
  local_88 = 0;
  uStack_80 = 0;
  uVar4 = *(undefined4 *)(param_1 + 0xc1);
  local_8c[0] = '\0';
  uVar5 = *(undefined4 *)(param_1 + 0xc5);
  bVar6 = *(byte *)(param_1 + 0x48);
  bVar7 = *(byte *)(param_1 + 0x49);
  if (param_2 == (uint *)0x0) {
    _printk(&DAT_00125ff4,"brl_get_capacitance_data",0x67f);
    iVar14 = -5;
    goto LAB_0010cdb0;
  }
  iVar8 = (uint)bVar7 * (uint)bVar6;
  if (*(int *)(*(long *)(param_1 + 0x100) + 4) == 6) {
    piVar1 = (int *)(param_1 + 0x4cc);
    local_78 = 0;
    uStack_70 = 0;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar14 = *piVar1;
      if (iVar14 != 1) goto LAB_0010c810;
      cVar9 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = 0;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010c810:
    if (iVar14 == 0) {
      if (debug_log_flag != '\0') {
        puVar15 = &DAT_00127b75;
        uVar16 = 0x165;
LAB_0010c9dc:
        _printk(puVar15,"brl_irq_enbale",uVar16);
      }
    }
    else {
      disable_irq(*(undefined4 *)(param_1 + 0x4b8));
      if (debug_log_flag != '\0') {
        puVar15 = &DAT_0011e253;
        uVar16 = 0x162;
        goto LAB_0010c9dc;
      }
    }
    goodix_ts_blocking_notify(5,0);
    uVar16 = local_78;
    *(ushort *)(param_2 + 1) = (ushort)bVar7;
    *(ushort *)((long)param_2 + 6) = (ushort)bVar6;
    *param_2 = 2;
    local_78 = CONCAT35(local_78._5_3_,0x8100000000);
    local_78._0_2_ = (undefined2)uVar16;
    local_78._0_4_ = CONCAT22(0x9005,(undefined2)local_78);
    iVar14 = brl_send_cmd(param_1,&local_78);
    if (iVar14 < 0) {
      _printk(&DAT_00120578,"brld_get_cap_data",0x646);
    }
    else {
      iVar14 = brld_get_framedata(param_1,param_2);
      if (iVar14 < 0) {
        _printk(&DAT_00124fcc,"brld_get_cap_data",0x64c);
      }
      else {
        if (7000 < *param_2) {
LAB_0010cd10:
                    /* WARNING: Does not return */
          pcVar13 = (code *)SoftwareBreakpoint(0x5512,0x10cd14);
          (*pcVar13)();
        }
        goodix_rotate_abcd2cbad(bVar6,bVar7,(long)param_2 + (ulong)*param_2 * 2 + 4);
        uVar12 = local_78;
        local_78 = CONCAT35(local_78._5_3_,0x8200000000);
        local_78._0_2_ = (undefined2)uVar12;
        local_78._0_4_ = CONCAT22(0x9005,(undefined2)local_78);
        *param_2 = *param_2 + iVar8;
        iVar14 = brl_send_cmd(param_1,&local_78);
        if (iVar14 < 0) {
          _printk(&DAT_00126017,"brld_get_cap_data",0x657);
        }
        else {
          iVar14 = brld_get_framedata(param_1,param_2);
          if (iVar14 < 0) {
            _printk(&DAT_00124a3c,"brld_get_cap_data",0x65d);
          }
          else {
            if (7000 < *param_2) goto LAB_0010cd10;
            goodix_rotate_abcd2cbad(bVar6,bVar7,(long)param_2 + (ulong)*param_2 * 2 + 4);
            iVar14 = 0;
            *param_2 = *param_2 + iVar8;
          }
        }
      }
    }
    uVar12 = local_78 >> 0x20;
    local_78._0_4_ = CONCAT22(0x9005,(undefined2)local_78);
    local_78 = CONCAT44((int)uVar12,(undefined4)local_78) & 0xffffff00ffffffff;
    brl_send_cmd(param_1,&local_78);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar8 = *piVar1;
      if (iVar8 != 0) goto LAB_0010cd38;
      cVar9 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = 1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010cd38:
    if (iVar8 != 0) goto joined_r0x0010cc3c;
    enable_irq(*(undefined4 *)(param_1 + 0x4b8));
joined_r0x0010cd88:
    if (debug_log_flag != '\0') {
      puVar15 = &DAT_001214d8;
      uVar16 = 0x15c;
      goto LAB_0010cda0;
    }
  }
  else {
    piVar1 = (int *)(param_1 + 0x4cc);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar14 = *piVar1;
      if (iVar14 != 1) goto LAB_0010ca04;
      cVar9 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = 0;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010ca04:
    if (iVar14 == 0) {
      if (debug_log_flag != '\0') {
        puVar15 = &DAT_00127b75;
        uVar16 = 0x165;
LAB_0010cd08:
        _printk(puVar15,"brl_irq_enbale",uVar16);
      }
    }
    else {
      disable_irq(*(undefined4 *)(param_1 + 0x4b8));
      if (debug_log_flag != '\0') {
        puVar15 = &DAT_0011e253;
        uVar16 = 0x162;
        goto LAB_0010cd08;
      }
    }
    goodix_ts_blocking_notify(5,0);
    local_88._0_4_ = CONCAT22(0x204,(undefined2)local_88);
    iVar14 = brl_send_cmd(param_1,&local_88);
    if (iVar14 < 0) {
      _printk(&DAT_0011e3b1,"brl_get_capacitance_data",0x68f);
    }
    else {
      local_8c[0] = '\0';
      pcVar13 = *(code **)(*(long *)(param_1 + 0x100) + 0x18);
      if (*(int *)(pcVar13 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
        pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x10ca6c);
        (*pcVar13)();
      }
      iVar14 = (*pcVar13)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar3,local_8c,1);
      if (iVar14 < 0) {
        _printk(&DAT_00124f98,"brl_get_capacitance_data",0x697);
      }
      else {
        iVar17 = 0x13;
        do {
          usleep_range_state(5000,0x13ec,2);
          pcVar13 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
          if (*(int *)(pcVar13 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
            pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x10cac4);
            (*pcVar13)();
          }
          iVar14 = (*pcVar13)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar3,local_8c,1);
          if ((iVar14 == 0) && (local_8c[0] < '\0')) {
            if (-1 < iVar17) {
              *(ushort *)(param_2 + 1) = (ushort)bVar7;
              *(ushort *)((long)param_2 + 6) = (ushort)bVar6;
              *param_2 = 2;
              pcVar13 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
              if (*(int *)(pcVar13 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x10cb1c);
                (*pcVar13)();
              }
              iVar14 = (*pcVar13)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar4,param_2 + 2,
                                  iVar8 * 2);
              if (iVar14 < 0) {
                _printk(&DAT_0012558c,"brl_get_capacitance_data",0x6ae);
                goto LAB_0010cbcc;
              }
              if (7000 < *param_2) goto LAB_0010cd10;
              goodix_rotate_abcd2cbad(bVar6,bVar7,(long)param_2 + (ulong)*param_2 * 2 + 4);
              uVar2 = *param_2 + iVar8;
              *param_2 = uVar2;
              if (7000 < uVar2) goto LAB_0010cd10;
              pcVar13 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
              if (*(int *)(pcVar13 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
                pcVar13 = (code *)SoftwareBreakpoint(0x822a,0x10cb8c);
                (*pcVar13)();
              }
              iVar14 = (*pcVar13)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar5,
                                  (long)param_2 + (ulong)uVar2 * 2 + 4,iVar8 * 2);
              if (iVar14 < 0) {
                _printk(&DAT_0011fef7,"brl_get_capacitance_data",0x6b7);
              }
              else {
                if (7000 < *param_2) goto LAB_0010cd10;
                goodix_rotate_abcd2cbad(bVar6,bVar7,(long)param_2 + (ulong)*param_2 * 2 + 4);
                *param_2 = *param_2 + iVar8;
              }
              goto LAB_0010cbcc;
            }
            break;
          }
          iVar17 = iVar17 + -1;
        } while (iVar17 != -1);
        _printk(&DAT_0012591f,"brl_get_capacitance_data",0x6a2,local_8c[0]);
      }
    }
LAB_0010cbcc:
    local_88._0_4_ = CONCAT22(4,(undefined2)local_88);
    brl_send_cmd(param_1,&local_88);
    local_8c[0] = '\0';
    pcVar13 = *(code **)(*(long *)(param_1 + 0x100) + 0x18);
    if (*(int *)(pcVar13 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x10cc14);
      (*pcVar13)();
    }
    (*pcVar13)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar3,local_8c,1);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar8 = *piVar1;
      if (iVar8 != 0) goto LAB_0010cd78;
      cVar9 = '\x01';
      bVar10 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar10) {
        *piVar1 = 1;
        cVar9 = ExclusiveMonitorsStatus();
      }
    } while (cVar9 != '\0');
    DataMemoryBarrier(2,3);
LAB_0010cd78:
    if (iVar8 == 0) {
      enable_irq(*(undefined4 *)(param_1 + 0x4b8));
      goto joined_r0x0010cd88;
    }
joined_r0x0010cc3c:
    if (debug_log_flag != '\0') {
      puVar15 = &DAT_00127b75;
      uVar16 = 0x165;
LAB_0010cda0:
      _printk(puVar15,"brl_irq_enbale",uVar16);
    }
  }
  goodix_ts_blocking_notify(6,0);
LAB_0010cdb0:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar14;
}



//------------------------------------------------------------
// brl_set_display_mode @ 0010cdf4 size=8
// signature: undefined brl_set_display_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 brl_set_display_mode(void)

{
  return 0xffffffea;
}



//------------------------------------------------------------
// brl_select_spi_mode @ 0010cdfc size=772
// signature: undefined brl_select_spi_mode(void)
// callers: [brl_power_on, brl_reset]
//------------------------------------------------------------

void brl_select_spi_mode(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  code *pcVar4;
  char local_30 [4];
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\x01';
  local_30[0] = '\0';
  if ((**(int **)(param_1 + 0x100) != 0) && ((*(int **)(param_1 + 0x100))[1] == 4)) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
    if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10ce70);
      (*pcVar4)();
    }
    (*pcVar4)(param_1,0xc900,local_2c,1);
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
    if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10cea4);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(param_1,0xc900,local_30,1);
    if ((iVar2 != 0) || (local_30[0] != local_2c[0])) {
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
      if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10ceec);
        (*pcVar4)();
      }
      (*pcVar4)(param_1,0xc900,local_2c,1);
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
      if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10cf20);
        (*pcVar4)();
      }
      iVar2 = (*pcVar4)(param_1,0xc900,local_30,1);
      if ((iVar2 != 0) || (local_30[0] != local_2c[0])) {
        pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
        if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10cf68);
          (*pcVar4)();
        }
        (*pcVar4)(param_1,0xc900,local_2c,1);
        pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
        if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10cf9c);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(param_1,0xc900,local_30,1);
        if ((iVar2 != 0) || (local_30[0] != local_2c[0])) {
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
          if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10cfe4);
            (*pcVar4)();
          }
          (*pcVar4)(param_1,0xc900,local_2c,1);
          pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
          if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10d018);
            (*pcVar4)();
          }
          iVar2 = (*pcVar4)(param_1,0xc900,local_30,1);
          if ((iVar2 != 0) || (local_30[0] != local_2c[0])) {
            pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x40);
            if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10d060);
              (*pcVar4)();
            }
            (*pcVar4)(param_1,0xc900,local_2c,1);
            pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
            if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10d094);
              (*pcVar4)();
            }
            iVar2 = (*pcVar4)(param_1,0xc900,local_30,1);
            if ((iVar2 != 0) || (local_30[0] != local_2c[0])) {
              _printk(&DAT_00128168,"brl_select_spi_mode",0x58,iVar2);
              uVar3 = 0xffffffea;
              goto LAB_0010d0b4;
            }
          }
        }
      }
    }
  }
  uVar3 = 0;
LAB_0010d0b4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// send_cfg_cmd @ 0010d100 size=452
// signature: undefined send_cfg_cmd(void)
// callers: [brl_send_config, brl_read_config]
//------------------------------------------------------------

int send_cfg_cmd(long param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  code *pcVar5;
  long lVar6;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar6 = sp_el0;
  local_58 = *(long *)(lVar6 + 0x638);
  pcVar5 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
  if (*(int *)(pcVar5 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10d150);
    (*pcVar5)();
  }
  iVar1 = (*pcVar5)();
  if (iVar1 == 0) {
    lVar6 = *(long *)(param_1 + 0x2d0);
    iVar1 = 0x14;
    local_68 = 0;
    uStack_60 = 0;
    do {
      pcVar5 = *(code **)(lVar6 + 0x38);
      if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10d1bc);
        (*pcVar5)();
      }
      iVar2 = (*pcVar5)(param_1,*(undefined4 *)(param_1 + 0x89),&local_68,0x10);
      if ((iVar2 == 0) && ((char)local_68 == -0x80)) {
        if (debug_log_flag != '\0') {
          _printk(&DAT_00127046,"wait_cmd_status",0x200);
        }
        iVar1 = 0;
        goto LAB_0010d200;
      }
      if (debug_log_flag != '\0') {
        _printk(&DAT_00120f67,"wait_cmd_status",0x203,0x10,&local_68);
      }
      msleep(0x14);
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    _printk(&DAT_001214f8,"wait_cmd_status",0x208,0x14,local_68._1_1_,local_68 & 0xff,iVar2);
    puVar3 = &DAT_0011e2ba;
    uVar4 = 0x219;
    iVar1 = -0x16;
  }
  else {
    puVar3 = &DAT_001276b5;
    uVar4 = 0x213;
  }
  _printk(puVar3,"send_cfg_cmd",uVar4,iVar1);
LAB_0010d200:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// brld_get_framedata @ 0010d2c4 size=628
// signature: undefined brld_get_framedata(void)
// callers: [brl_get_capacitance_data]
//------------------------------------------------------------

int brld_get_framedata(long param_1,uint *param_2)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  char local_6f0 [4];
  undefined1 auStack_6ec [3];
  undefined2 local_6e9;
  undefined1 auStack_6e4 [1692];
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  memset(auStack_6ec,0,0x6a4);
  uVar1 = *(undefined4 *)(param_1 + 0xa1);
  local_6f0[0] = '\0';
  pcVar5 = *(code **)(*(long *)(param_1 + 0x100) + 0x18);
  if (*(int *)(pcVar5 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x10d33c);
    (*pcVar5)();
  }
  iVar3 = (*pcVar5)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar1,local_6f0,1);
  if (iVar3 < 0) {
    _printk(&DAT_00124f98,"brld_get_framedata",0x606);
  }
  else {
    iVar3 = 0x15;
    do {
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) goto LAB_0010d4b0;
      usleep_range_state(2000,0x834,2);
      pcVar5 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
      if (*(int *)(pcVar5 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x10d38c);
        (*pcVar5)();
      }
      iVar4 = (*pcVar5)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar1,local_6f0,1);
    } while ((iVar4 != 0) || (-1 < local_6f0[0]));
    if (iVar3 < 1) {
LAB_0010d4b0:
      _printk(&DAT_00126bf7,"brld_get_framedata",0x611,local_6f0[0]);
      iVar3 = -0x16;
    }
    else {
      pcVar5 = *(code **)(*(long *)(param_1 + 0x100) + 0x10);
      if (*(int *)(pcVar5 + -4) != -0x54f3140c) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8229,0x10d3d0);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar1,auStack_6ec,0x6a4);
      if (iVar3 < 0) {
        _printk(&DAT_001224c9,"brld_get_framedata",0x617);
      }
      else {
        iVar3 = checksum_cmp(auStack_6ec,*(undefined2 *)(param_1 + 0xa5),0);
        if (iVar3 == 0) {
          iVar3 = checksum_cmp(auStack_6ec,local_6e9,1);
          if (iVar3 != 0) {
            _printk(&DAT_00124396,"brld_get_framedata",0x622);
          }
          if ((7000 < *param_2) || (7000 < *param_2)) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10d534);
            (*pcVar5)();
          }
          memcpy((void *)((long)param_2 + (ulong)*param_2 * 2 + 4),
                 auStack_6e4 +
                 (ulong)*(ushort *)(param_1 + 0xa7) + (ulong)*(ushort *)(param_1 + 0xa9) +
                 (ulong)*(ushort *)(param_1 + 0xa5),(ulong)*(ushort *)(param_1 + 0xaf) - 8);
          iVar3 = 0;
        }
        else {
          _printk(&DAT_00123022,"brld_get_framedata",0x61c);
          iVar3 = -0x16;
        }
      }
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// goodix_get_config_proc @ 0010d53c size=1824
// signature: undefined goodix_get_config_proc(void)
// callers: [goodix_later_init_thread, goodix_generic_noti_callback]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_get_config_proc(long param_1)

{
  undefined8 *puVar1;
  undefined8 *puVar2;
  long lVar3;
  byte bVar4;
  ushort uVar5;
  int iVar6;
  uint *puVar7;
  undefined *puVar8;
  undefined8 uVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  ulong uVar13;
  long lVar14;
  char cVar15;
  byte bVar16;
  char cVar17;
  char *pcVar18;
  undefined8 uVar19;
  uint uVar20;
  undefined8 uVar21;
  ulong uVar22;
  long lVar23;
  ulong *local_90;
  ulong *local_88;
  uint local_80;
  uint local_7c;
  undefined4 local_78;
  undefined1 uStack_74;
  byte bStack_73;
  undefined2 uStack_72;
  long local_70;
  long local_68;
  
  lVar23 = sp_el0;
  local_68 = *(long *)(lVar23 + 0x638);
  if ((*(char **)(param_1 + 0x698) != (char *)0x0) && (*(char *)(param_1 + 0x2c2) == '\0')) {
    snprintf((char *)(param_1 + 0x235),0x40,"%s_%s",*(char **)(param_1 + 0x698),
             "goodix_cfg_group.bin");
  }
  pcVar12 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x60);
  if (*(int *)(pcVar12 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x10d5c4);
    (*pcVar12)();
  }
  iVar6 = (*pcVar12)(param_1,param_1 + 0x10);
  if (iVar6 != 0) {
    _printk(&DAT_001281e4,"goodix_get_config_proc",0x14f);
    iVar6 = -0x16;
    goto LAB_0010d8dc;
  }
  lVar23 = param_1 + 0x235;
  bVar4 = *(byte *)(param_1 + 0x27);
  local_78 = 0;
  uStack_74 = 0;
  bStack_73 = 0;
  uStack_72 = 0;
  local_70 = 0;
  lVar14 = *(long *)(param_1 + 8) + 0x10;
  local_88 = (ulong *)0x0;
  local_80 = 0;
  local_7c = 0;
  local_90 = (ulong *)0x0;
  _printk(&DAT_00121b6a,"goodix_read_cfg_bin",0x6f,lVar23);
  iVar6 = request_firmware(&local_90,lVar23,lVar14);
  if (iVar6 == 0) {
LAB_0010d688:
    uVar13 = *local_90;
    if (uVar13 == 0) {
      _printk(&DAT_0012500f,"goodix_read_cfg_bin",0x7f,0);
      iVar6 = -0x16;
    }
    else {
      local_80 = (uint)uVar13;
      local_88 = (ulong *)__kmalloc(uVar13 & 0xffffffff,0xdc0);
      if (local_88 != (ulong *)0x0) {
        memcpy(local_88,(void *)local_90[1],(ulong)local_80);
        release_firmware(local_90);
        if (local_80 < 10) {
          _printk(&DAT_0011ff2a,"goodix_parse_cfg_bin",0x9a,local_80);
LAB_0010d8b8:
          iVar6 = -0x16;
LAB_0010d8bc:
          _printk(&DAT_0012595a,"goodix_get_config_data",0x134);
        }
        else {
          uVar13 = *local_88;
          local_7c = (uint)uVar13;
          local_78 = (undefined4)(uVar13 >> 0x20);
          uStack_74 = (undefined1)local_88[1];
          bStack_73 = (byte)(local_88[1] >> 8);
          if (local_80 != local_7c) {
            puVar8 = &DAT_0011dc43;
            uVar9 = 0xa5;
            uVar10 = local_80;
LAB_0010d8b4:
            _printk(puVar8,"goodix_parse_cfg_bin",uVar9,uVar13,uVar10);
            goto LAB_0010d8b8;
          }
          if (local_80 + 0x7fffffff < 0x80000006) {
            bVar16 = 0;
            uVar10 = 5;
LAB_0010d840:
            do {
              lVar23 = (long)(int)uVar10;
              uVar10 = uVar10 + 1;
              bVar16 = *(char *)((long)local_88 + lVar23) + bVar16;
            } while (local_80 != uVar10);
          }
          else {
            cVar15 = '\0';
            uVar11 = local_80 - 5 & 0xfffffffe;
            cVar17 = '\0';
            uVar10 = uVar11 + 5;
            pcVar18 = (char *)((long)local_88 + 6);
            uVar20 = uVar11;
            do {
              uVar20 = uVar20 - 2;
              cVar15 = pcVar18[-1] + cVar15;
              cVar17 = *pcVar18 + cVar17;
              pcVar18 = pcVar18 + 2;
            } while (uVar20 != 0);
            bVar16 = cVar17 + cVar15;
            if (local_80 - 5 != uVar11) goto LAB_0010d840;
          }
          local_78._0_1_ = (byte)(uVar13 >> 0x20);
          uVar13 = (ulong)(byte)local_78;
          if ((byte)local_78 != bVar16) {
            puVar8 = &DAT_0011dc79;
            uVar9 = 0xb0;
            uVar10 = (uint)bVar16;
            goto LAB_0010d8b4;
          }
          local_70 = __kmalloc((ulong)bStack_73 * 0x90,0xdc0);
          if (local_70 == 0) {
            _printk(&DAT_0011e3e7,"goodix_parse_cfg_bin",0xb8);
            iVar6 = -0xc;
            goto LAB_0010d8bc;
          }
          if (bStack_73 != 0) {
            lVar23 = 0;
            lVar14 = 0;
            uVar13 = 0;
            do {
              uVar5 = *(ushort *)((long)local_88 + lVar23 + 0x10);
              uVar10 = (uint)uVar5;
              if (uVar13 == bStack_73 - 1) {
                iVar6 = local_80 - uVar10;
              }
              else {
                uVar11 = (uint)*(ushort *)((long)local_88 + lVar23 + 0x12);
                iVar6 = uVar11 - uVar10;
                if (uVar11 < uVar10 || iVar6 == 0) {
                  _printk(&DAT_00126049,"goodix_parse_cfg_bin",0xcc);
                  kfree(local_70);
                  goto LAB_0010d8b8;
                }
              }
              uVar13 = uVar13 + 1;
              lVar23 = lVar23 + 2;
              *(int *)(local_70 + lVar14 + 0x88) = iVar6;
              puVar1 = (undefined8 *)((long)local_88 + (ulong)uVar5);
              puVar2 = (undefined8 *)(local_70 + lVar14);
              lVar14 = lVar14 + 0x90;
              uVar19 = puVar1[6];
              uVar9 = puVar1[3];
              uVar21 = puVar1[4];
              puVar2[5] = puVar1[5];
              puVar2[6] = uVar19;
              puVar2[3] = uVar9;
              puVar2[4] = uVar21;
              uVar9 = puVar1[2];
              uVar19 = *puVar1;
              puVar2[1] = puVar1[1];
              puVar2[2] = uVar9;
              *puVar2 = uVar19;
              uVar19 = puVar1[0xb];
              uVar9 = puVar1[8];
              uVar21 = puVar1[9];
              puVar2[10] = puVar1[10];
              puVar2[0xb] = uVar19;
              puVar2[8] = uVar9;
              puVar2[9] = uVar21;
              uVar9 = puVar1[0xd];
              uVar19 = puVar1[0xe];
              uVar21 = puVar1[0xc];
              *(undefined1 *)(puVar2 + 0xf) = *(undefined1 *)(puVar1 + 0xf);
              puVar2[0xd] = uVar9;
              puVar2[0xe] = uVar19;
              puVar2[0xc] = uVar21;
              puVar2[7] = puVar1[7];
              puVar2[0x10] = (long)puVar1 + 0x79;
            } while (uVar13 < bStack_73);
          }
          _printk(&DAT_00125983,"goodix_parse_cfg_bin",0xdf,(long)&local_78 + 1,local_7c);
          if ((bStack_73 == 0) || (local_70 == 0)) {
            _printk(&DAT_001243db,"goodix_get_reg_and_cfg",0xf1);
LAB_0010d96c:
            _printk(&DAT_00127c4f,"goodix_get_config_data",0x13d);
            iVar6 = -0x16;
          }
          else {
            lVar23 = 0;
            uVar13 = 0;
            do {
              lVar14 = local_70;
              bVar16 = *(byte *)(local_70 + lVar23 + 0x14);
              uVar10 = (uint)bVar16;
              if (bVar16 == bVar4) {
                bVar16 = *(byte *)(local_70 + lVar23 + 0x13);
                uVar22 = (ulong)bVar16;
                if (bVar16 < 8) {
                  uVar10 = *(int *)(local_70 + lVar23 + 0x88) - 0x79;
                  if (uVar10 < 0x1001) {
                    lVar3 = param_1 + uVar22 * 8;
                    if (*(long *)(lVar3 + 0x428) != 0) {
                      _printk(&DAT_00127171,"goodix_get_reg_and_cfg",0x10d,bVar4);
                      goto LAB_0010dab4;
                    }
                    puVar7 = (uint *)kmalloc_trace(_queue_work_on,0xdc0,0x1004);
                    *(uint **)(lVar3 + 0x428) = puVar7;
                    if (puVar7 != (uint *)0x0) {
                      *puVar7 = uVar10;
                      memcpy(puVar7 + 1,*(void **)(lVar14 + lVar23 + 0x80),(ulong)uVar10);
                      puVar8 = &DAT_00124415;
                      uVar9 = 0x116;
                      goto LAB_0010db68;
                    }
                  }
                  else {
                    _printk(&DAT_00127ba9,"goodix_get_reg_and_cfg",0x108,uVar10,0x1000);
                  }
                }
                else {
                  _printk(&DAT_0011e8d5,"goodix_get_reg_and_cfg",0x100,bVar16);
                }
                if (*(long *)(param_1 + 0x428) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x428) = 0;
                if (*(long *)(param_1 + 0x430) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x430) = 0;
                if (*(long *)(param_1 + 0x438) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x438) = 0;
                if (*(long *)(param_1 + 0x440) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x440) = 0;
                if (*(long *)(param_1 + 0x448) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x448) = 0;
                if (*(long *)(param_1 + 0x450) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x450) = 0;
                if (*(long *)(param_1 + 0x458) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x458) = 0;
                if (*(long *)(param_1 + 0x460) != 0) {
                  kfree();
                }
                *(undefined8 *)(param_1 + 0x460) = 0;
                goto LAB_0010d96c;
              }
              puVar8 = &DAT_00123a85;
              uVar9 = 0xfa;
              uVar22 = uVar13 & 0xffffffff;
LAB_0010db68:
              _printk(puVar8,"goodix_get_reg_and_cfg",uVar9,uVar22,uVar10,bVar4);
LAB_0010dab4:
              uVar13 = uVar13 + 1;
              lVar23 = lVar23 + 0x90;
            } while (uVar13 < bStack_73);
            _printk(&DAT_0012771a,"goodix_get_config_data",0x13b);
            iVar6 = 0;
          }
          kfree(local_70);
        }
        kfree(local_88);
        goto LAB_0010d8dc;
      }
      iVar6 = -0xc;
    }
    release_firmware(local_90);
  }
  else {
    _printk(&DAT_00124a7c,"goodix_read_cfg_bin",0x75,1);
    msleep(200);
    iVar6 = request_firmware(&local_90,lVar23,lVar14);
    if (iVar6 == 0) goto LAB_0010d688;
    _printk(&DAT_00124a7c,"goodix_read_cfg_bin",0x75,2);
    msleep(200);
    iVar6 = request_firmware(&local_90,lVar23,lVar14);
    if (iVar6 == 0) goto LAB_0010d688;
    _printk(&DAT_00124a7c,"goodix_read_cfg_bin",0x75,3);
    msleep(200);
    _printk(&DAT_00127128,"goodix_read_cfg_bin",0x79,lVar23,iVar6);
  }
  _printk(&DAT_00120b40,"goodix_get_config_data",0x12d);
LAB_0010d8dc:
  lVar23 = sp_el0;
  if (*(long *)(lVar23 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// goodix_append_checksum @ 0010dc60 size=340
// signature: undefined goodix_append_checksum(void)
// callers: [goodix_do_inspect, goodix_flash_subsystem, brl_send_cmd]
//------------------------------------------------------------

uint goodix_append_checksum(long param_1,uint param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  byte *pbVar10;
  ulong uVar11;
  
  if (param_3 == 0) {
    if ((int)param_2 < 1) {
      uVar4 = 0;
      goto LAB_0010dd98;
    }
    uVar5 = (ulong)param_2;
    if (param_2 == 1) {
      uVar8 = 0;
      uVar4 = 0;
    }
    else {
      uVar8 = uVar5 & 0xfffffffe;
      iVar3 = 0;
      iVar9 = 0;
      pbVar10 = (byte *)(param_1 + 1);
      uVar7 = uVar8;
      do {
        uVar7 = uVar7 - 2;
        iVar3 = iVar3 + (uint)pbVar10[-1];
        iVar9 = iVar9 + (uint)*pbVar10;
        pbVar10 = pbVar10 + 2;
      } while (uVar7 != 0);
      uVar4 = iVar9 + iVar3;
      if (uVar8 == uVar5) goto LAB_0010dd64;
    }
    lVar6 = uVar5 - uVar8;
    pbVar10 = (byte *)(param_1 + uVar8);
    do {
      lVar6 = lVar6 + -1;
      uVar4 = uVar4 + *pbVar10;
      pbVar10 = pbVar10 + 1;
    } while (lVar6 != 0);
  }
  else {
    if ((int)param_2 < 1) {
      uVar4 = 0;
      goto LAB_0010dd68;
    }
    if (param_2 < 3) {
      uVar7 = 0;
      uVar4 = 0;
    }
    else {
      iVar3 = 0;
      iVar9 = 0;
      uVar5 = ((ulong)param_2 - 1 >> 1) + 1;
      lVar6 = param_1 + 3;
      uVar11 = uVar5 & 0xfffffffffffffffe;
      uVar7 = uVar11 << 1;
      uVar8 = uVar11;
      do {
        puVar2 = (ushort *)(lVar6 + -3);
        uVar8 = uVar8 - 2;
        puVar1 = (ushort *)(lVar6 + -1);
        lVar6 = lVar6 + 4;
        iVar3 = (uint)*puVar2 + iVar3;
        iVar9 = (uint)*puVar1 + iVar9;
      } while (uVar8 != 0);
      uVar4 = iVar9 + iVar3;
      if (uVar5 == uVar11) goto LAB_0010dd64;
    }
    do {
      puVar2 = (ushort *)(param_1 + uVar7);
      uVar7 = uVar7 + 2;
      uVar4 = *puVar2 + uVar4;
    } while (uVar7 < param_2);
  }
LAB_0010dd64:
  if (param_3 == 0) {
LAB_0010dd98:
    *(char *)(param_1 + (int)param_2) = (char)uVar4;
    *(char *)(param_1 + (int)(param_2 + 1)) = (char)(uVar4 >> 8);
    return uVar4 & 0xffff;
  }
LAB_0010dd68:
  *(char *)(param_1 + (int)param_2) = (char)uVar4;
  *(char *)(param_1 + (int)(param_2 + 1)) = (char)(uVar4 >> 8);
  *(char *)(param_1 + (int)(param_2 + 2)) = (char)(uVar4 >> 0x10);
  *(char *)(param_1 + (int)(param_2 + 3)) = (char)(uVar4 >> 0x18);
  return uVar4;
}



//------------------------------------------------------------
// checksum_cmp @ 0010ddb8 size=364
// signature: undefined checksum_cmp(void)
// callers: [brl_read_version, brl_get_ic_info, goodix_do_inspect, brl_read_config, brl_event_handler, brld_get_framedata]
//------------------------------------------------------------

bool checksum_cmp(long param_1,int param_2,int param_3)

{
  ushort *puVar1;
  ushort *puVar2;
  uint uVar3;
  ulong uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  int iVar10;
  byte *pbVar11;
  ulong uVar12;
  ulong uVar13;
  ulong uVar14;
  
  if (param_3 != 0) {
    uVar6 = param_2 - 4;
    uVar4 = (ulong)uVar6;
    if (param_2 < 4) {
      return true;
    }
    if (uVar6 == 0) {
      uVar4 = 0;
      uVar6 = 0;
    }
    else {
      if (uVar6 < 3) {
        uVar9 = 0;
        uVar6 = 0;
      }
      else {
        iVar5 = 0;
        iVar10 = 0;
        uVar13 = (uVar4 - 1 >> 1) + 1;
        lVar7 = param_1 + 3;
        uVar12 = uVar13 & 0xfffffffffffffffe;
        uVar9 = uVar12 << 1;
        uVar14 = uVar12;
        do {
          puVar2 = (ushort *)(lVar7 + -3);
          uVar14 = uVar14 - 2;
          puVar1 = (ushort *)(lVar7 + -1);
          lVar7 = lVar7 + 4;
          iVar5 = (uint)*puVar2 + iVar5;
          iVar10 = (uint)*puVar1 + iVar10;
        } while (uVar14 != 0);
        uVar6 = iVar10 + iVar5;
        if (uVar13 == uVar12) goto LAB_0010de78;
      }
      do {
        puVar2 = (ushort *)(param_1 + uVar9);
        uVar9 = uVar9 + 2;
        uVar6 = *puVar2 + uVar6;
      } while (uVar9 < uVar4);
    }
LAB_0010de78:
    uVar8 = (uint)CONCAT12(*(undefined1 *)(param_1 + (ulong)(param_2 - 2)),
                           CONCAT11(*(undefined1 *)(param_1 + (ulong)(param_2 - 3)),
                                    *(undefined1 *)(param_1 + uVar4)));
    uVar3 = (uint)*(byte *)(param_1 + (ulong)(param_2 - 1)) << 0x18;
    goto LAB_0010df14;
  }
  uVar6 = param_2 - 2;
  uVar4 = (ulong)uVar6;
  if (param_2 < 2) {
    return true;
  }
  if (uVar6 == 0) {
    uVar4 = 0;
    uVar6 = 0;
  }
  else {
    if (uVar6 == 1) {
      uVar9 = 0;
      uVar6 = 0;
LAB_0010dee8:
      lVar7 = uVar4 - uVar9;
      pbVar11 = (byte *)(param_1 + uVar9);
      do {
        lVar7 = lVar7 + -1;
        uVar6 = uVar6 + *pbVar11;
        pbVar11 = pbVar11 + 1;
      } while (lVar7 != 0);
    }
    else {
      uVar9 = uVar4 & 0xfffffffe;
      iVar5 = 0;
      iVar10 = 0;
      pbVar11 = (byte *)(param_1 + 1);
      uVar13 = uVar9;
      do {
        uVar13 = uVar13 - 2;
        iVar5 = iVar5 + (uint)pbVar11[-1];
        iVar10 = iVar10 + (uint)*pbVar11;
        pbVar11 = pbVar11 + 2;
      } while (uVar13 != 0);
      uVar6 = iVar10 + iVar5;
      if (uVar9 != uVar4) goto LAB_0010dee8;
    }
    uVar6 = uVar6 & 0xffff;
  }
  uVar3 = (uint)*(byte *)(param_1 + uVar4);
  uVar8 = (uint)*(byte *)(param_1 + (ulong)(param_2 - 1)) << 8;
LAB_0010df14:
  return uVar6 != (uVar8 | uVar3);
}



//------------------------------------------------------------
// is_risk_data @ 0010df28 size=168
// signature: undefined is_risk_data(void)
// callers: [brl_get_ic_info]
//------------------------------------------------------------

undefined8 is_risk_data(char *param_1,uint param_2)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  ulong uVar4;
  
  if ((int)param_2 < 1) {
    uVar3 = 0;
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
    uVar3 = 0;
    uVar4 = (ulong)param_2;
    do {
      if (*param_1 == -1) {
        uVar2 = uVar2 + 1;
      }
      else if (*param_1 == '\0') {
        uVar3 = uVar3 + 1;
      }
      param_1 = param_1 + 1;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  if (uVar3 == param_2) {
    puVar1 = &DAT_00120b75;
  }
  else {
    if (uVar2 != param_2) {
      return 0;
    }
    puVar1 = &DAT_001265d0;
  }
  _printk(&DAT_001265a4,"is_risk_data",0x6d,puVar1);
  return 1;
}



//------------------------------------------------------------
// goodix_get_file_config_id @ 0010dfd4 size=12
// signature: undefined goodix_get_file_config_id(void)
// callers: [goodix_fw_version_compare, goodix_ts_threadirq_func, goodix_send_ic_config]
//------------------------------------------------------------

undefined4 goodix_get_file_config_id(long param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x1e);
  }
  return uVar1;
}



//------------------------------------------------------------
// goodix_rotate_abcd2cbad @ 0010dfe4 size=220
// signature: undefined goodix_rotate_abcd2cbad(void)
// callers: [goodix_do_inspect, brl_get_capacitance_data]
//------------------------------------------------------------

void goodix_rotate_abcd2cbad(int param_1,int param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  bool bVar5;
  void *__src;
  ulong uVar6;
  int iVar7;
  int iVar8;
  ulong __n;
  
  uVar3 = param_2 * param_1;
  if (-1 < (int)uVar3) {
    __n = -(ulong)(uVar3 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar3 << 1;
    __src = (void *)__kmalloc(__n,0xdc0);
    if (__src != (void *)0x0) {
      if (uVar3 != 0) {
        uVar6 = 0;
        iVar8 = 0;
        iVar7 = 0;
        do {
          if (((long)uVar6 < 0) || (__n <= uVar6)) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(1,0x10e0c0);
            (*pcVar4)();
          }
          iVar2 = iVar8 + iVar7 * param_2;
          bVar5 = iVar7 + 1 == param_1;
          if (bVar5) {
            iVar8 = iVar8 + 1;
          }
          iVar1 = 0;
          if (!bVar5) {
            iVar1 = iVar7 + 1;
          }
          *(undefined2 *)((long)__src + uVar6) = *(undefined2 *)((long)param_3 + (long)iVar2 * 2);
          uVar6 = uVar6 + 2;
          iVar7 = iVar1;
        } while ((ulong)uVar3 * 2 != uVar6);
      }
      memcpy(param_3,__src,__n);
      kfree(__src);
      return;
    }
  }
  _printk(&DAT_0011d6f5,"goodix_rotate_abcd2cbad",0x88);
  return;
}



//------------------------------------------------------------
// goodix_get_ic_type @ 0010e0c4 size=344
// signature: undefined goodix_get_ic_type(void)
// callers: [goodix_i2c_probe, goodix_spi_probe]
//------------------------------------------------------------

int goodix_get_ic_type(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = (char *)0x0;
  iVar2 = of_property_read_string(param_1,"compatible",&local_30);
  pcVar4 = local_30;
  if (iVar2 < 0) {
    _printk(&DAT_0011f1d8,"goodix_get_ic_type",0xa0);
  }
  else {
    pcVar3 = strstr(local_30,"9897");
    if (pcVar3 == (char *)0x0) {
      pcVar3 = strstr(pcVar4,"9966");
      if ((pcVar3 == (char *)0x0) && (pcVar3 = strstr(pcVar4,"7986"), pcVar3 == (char *)0x0)) {
        pcVar4 = strstr(pcVar4,"9916");
        if (pcVar4 == (char *)0x0) {
          _printk(&DAT_0012505f,"goodix_get_ic_type",0xae);
          iVar2 = -0x16;
        }
        else {
          _printk(&DAT_0011dcbb,"goodix_get_ic_type",0xab);
          iVar2 = 6;
        }
      }
      else {
        _printk(&DAT_001224f4,"goodix_get_ic_type",0xa8);
        iVar2 = 5;
      }
    }
    else {
      _printk(&DAT_00123e2d,"goodix_get_ic_type",0xa5);
      iVar2 = 4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// goodix_fw_update_proc @ 0010e220 size=3416
// signature: undefined goodix_fw_update_proc(void)
// callers: [goodix_fw_update_thread]
//------------------------------------------------------------

undefined8 goodix_fw_update_proc(long param_1)

{
  undefined1 *puVar1;
  long lVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  byte bVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined *puVar13;
  ulong uVar14;
  char cVar15;
  long lVar16;
  code *pcVar17;
  uint *puVar18;
  undefined4 uVar19;
  ulong uVar20;
  ulong uVar21;
  undefined8 uVar22;
  ulong *puVar23;
  int iVar24;
  ulong uVar25;
  int iVar26;
  undefined8 *puVar27;
  undefined4 local_d8;
  uint local_d4;
  undefined8 local_d0;
  ulong local_c8;
  uint *local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  puVar23 = *(ulong **)(param_1 + 0x510);
  uVar25 = (ulong)(int)DAT_0012a968[1];
  if (*puVar23 < uVar25) {
    _printk(&DAT_00121643,"goodix_parse_firmware",0x159);
  }
  else {
    uVar9 = *DAT_0012a968;
    iVar7 = *(int *)(*(long *)(DAT_0012a960 + 0x100) + 4);
    memcpy((int *)(param_1 + 0x80),(void *)puVar23[1],0x48a);
    iVar8 = *(int *)(param_1 + 0x80);
    uVar14 = *puVar23;
    if (uVar14 == iVar8 + 8) {
      if (uVar14 < 9) {
        iVar8 = 0;
      }
      else {
        iVar8 = 0;
        uVar20 = 8;
        do {
          uVar21 = uVar20 | 1;
          puVar1 = (undefined1 *)(puVar23[1] + uVar20);
          uVar20 = (ulong)((int)uVar20 + 2);
          iVar8 = (uint)CONCAT11(*(undefined1 *)(puVar23[1] + uVar21),*puVar1) + iVar8;
        } while (uVar20 < uVar14);
      }
      if (iVar8 == *(int *)(param_1 + 0x84)) {
        bVar5 = *(byte *)(param_1 + 0x9d);
        if (0x2f < bVar5) {
          _printk(&DAT_00123ac9,"goodix_parse_firmware",0x176);
          goto LAB_0010e370;
        }
        if (bVar5 != 0) {
          lVar16 = 0;
          do {
            lVar2 = param_1 + lVar16;
            *(undefined1 *)(lVar2 + 0xa2) = *(undefined1 *)(puVar23[1] + (uVar25 & 0xffffffff));
            iVar24 = (int)uVar25;
            iVar8 = *(int *)(puVar23[1] + (ulong)(iVar24 + 1));
            *(int *)(lVar2 + 0xa6) = iVar8;
            *(undefined4 *)(lVar2 + 0xaa) = *(undefined4 *)(puVar23[1] + (ulong)(iVar24 + 5));
            uVar14 = (ulong)uVar9;
            if (*puVar23 < uVar14) {
              _printk(&DAT_0012508c,"goodix_parse_firmware",0x188);
              goto LAB_0010e660;
            }
            uVar9 = iVar8 + uVar9;
            lVar16 = lVar16 + 0x18;
            uVar25 = (ulong)(iVar24 + 10);
            *(ulong *)(lVar2 + 0xb2) = puVar23[1] + uVar14;
          } while ((ulong)bVar5 * 0x18 != lVar16);
        }
        _printk(&DAT_0011e41b,"goodix_parse_firmware",400,*(undefined1 *)(param_1 + 0x9f));
        _printk(&DAT_001229f6,"goodix_parse_firmware",0x191,param_1 + 0x91);
        _printk(&DAT_0012356b,"goodix_parse_firmware",0x192,4,param_1 + 0x99);
        _printk(&DAT_00122a1c,"goodix_parse_firmware",0x193,*(undefined1 *)(param_1 + 0x9e));
        puVar13 = &DAT_0011f349;
        if ((*(byte *)(param_1 + 0xa0) & 1) != 0) {
          puVar13 = &DAT_00123e54;
        }
        _printk(&DAT_0011dce2,"goodix_parse_firmware",0x195,puVar13);
        _printk(&DAT_0011dd0b,"goodix_parse_firmware",0x196,*(undefined4 *)(param_1 + 0x80));
        _printk(&DAT_0011dd30,"goodix_parse_firmware",0x197,*(undefined1 *)(param_1 + 0x9d));
        if (*(char *)(param_1 + 0x9d) != '\0') {
          uVar25 = 0;
          puVar27 = (undefined8 *)(param_1 + 0xb2);
          cVar15 = debug_log_flag;
          do {
            if (((((cVar15 != '\0') &&
                  (_printk(&DAT_00124456,"goodix_parse_firmware",0x19a), cVar15 = debug_log_flag,
                  debug_log_flag != '\0')) &&
                 (_printk(&DAT_00121671,"goodix_parse_firmware",0x19b,uVar25 & 0xffffffff),
                 cVar15 = debug_log_flag, debug_log_flag != '\0')) &&
                ((_printk(&DAT_00123591,"goodix_parse_firmware",0x19c,*(undefined1 *)(puVar27 + -2))
                 , cVar15 = debug_log_flag, debug_log_flag != '\0' &&
                 (_printk(&DAT_001260d7,"goodix_parse_firmware",0x19d,
                          *(undefined4 *)((long)puVar27 + -0xc)), cVar15 = debug_log_flag,
                 debug_log_flag != '\0')))) &&
               (_printk(&DAT_001255fc,"goodix_parse_firmware",0x19f,*(undefined4 *)(puVar27 + -1)),
               cVar15 = debug_log_flag, debug_log_flag != '\0')) {
              _printk(&DAT_0012562a,"goodix_parse_firmware",0x1a0,*puVar27);
              cVar15 = debug_log_flag;
            }
            uVar25 = uVar25 + 1;
            puVar27 = puVar27 + 3;
          } while (uVar25 < *(byte *)(param_1 + 0x9d));
        }
        cVar15 = *(char *)(param_1 + 0x9e);
        if ((cVar15 == -0x6a) && (iVar7 != 4)) {
          puVar13 = &DAT_0011e44e;
          uVar22 = 0x1a5;
        }
        else if ((cVar15 == -0x69) && (iVar7 != 5)) {
          puVar13 = &DAT_0011e44e;
          uVar22 = 0x1a9;
        }
        else {
          if ((cVar15 != -0x68) || (iVar7 == 6)) {
LAB_0010e660:
            if ((*(byte *)(param_1 + 0x74) & 1) != 0) {
LAB_0010e6cc:
              iVar7 = 2;
              bVar6 = false;
LAB_0010e6f8:
              *(undefined4 *)(param_1 + 0x78) = 1;
LAB_0010e750:
              lVar16 = *(long *)(param_1 + 0x528);
              local_d0 = 0;
              local_c8 = 0;
              uVar3 = *(undefined4 *)(lVar16 + 0x18);
              uVar4 = *(undefined4 *)(lVar16 + 0x1c);
              local_d8 = *(undefined4 *)(lVar16 + 0x24);
              local_a0 = 0;
              uStack_98 = 0;
              local_b0 = 0;
              uStack_a8 = 0;
              local_d4 = 0;
              local_c0 = (uint *)0x0;
              uStack_b8 = 0;
              _printk(&DAT_001260fd,"goodix_update_prepare",0x269);
              pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x28);
              if (*(int *)(pcVar17 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
                pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e7b8);
                (*pcVar17)();
              }
              iVar8 = (*pcVar17)(DAT_0012a960,5);
              if (iVar8 != 0) {
                _printk(&DAT_00126c6a,"goodix_update_prepare",0x26b);
              }
              iVar8 = 100;
              do {
                local_d4 = CONCAT22(local_d4._2_2_,1);
                pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
                if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e818);
                  (*pcVar17)();
                }
                uVar9 = (*pcVar17)(DAT_0012a960,2,&local_d4,2);
                pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e850);
                  (*pcVar17)();
                }
                uVar10 = (*pcVar17)(DAT_0012a960,0x2000,&local_d0,4);
                pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar17 = (code *)SoftwareBreakpoint(0x8229,0x10e88c);
                  (*pcVar17)();
                }
                uVar11 = (*pcVar17)(DAT_0012a960,0x2000,(long)&local_d0 + 4,4);
                pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e8c4);
                  (*pcVar17)();
                }
                uVar12 = (*pcVar17)(DAT_0012a960,0x2000,&local_c8,4);
                uVar9 = uVar10 | uVar9 | uVar11 | uVar12;
                if (uVar9 == 0) {
                  if (((int)local_d0 == local_d0._4_4_) && ((int)local_d0 == (int)local_c8)) {
                    _printk(&DAT_00120bcd,"goodix_update_prepare",0x283);
                    pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
                    uVar19 = 4;
                    if (*(int *)(*(long *)(*(long *)(param_1 + 0x520) + 0x100) + 4) != 6) {
                      uVar19 = 1;
                    }
                    if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e994);
                      (*pcVar17)();
                    }
                    (*pcVar17)(DAT_0012a960,uVar3,&local_d8,uVar19);
                    _printk(&DAT_0012777c,"goodix_update_prepare",0x28a);
                    if (*(int *)(*(long *)(*(long *)(param_1 + 0x520) + 0x100) + 4) != 4)
                    goto LAB_0010eab4;
                    iVar8 = 0x14;
                    goto LAB_0010e9c8;
                  }
                }
                usleep_range_state(1000,0x44c,2);
                _printk(&DAT_00126611,"goodix_update_prepare",0x27c,iVar8);
                if (debug_log_flag != '\0') {
                  _printk(&DAT_00122993,"goodix_update_prepare",0x27d,0xc,&local_d0);
                }
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
              _printk(&DAT_0011d77e,"goodix_update_prepare",0x280,uVar9);
              iVar8 = -1;
              goto LAB_0010e720;
            }
            iVar7 = goodix_fw_version_compare(param_1);
            if (iVar7 != 0) {
              _printk(&DAT_0011d71c,"goodix_fw_update_proc",0x3c0);
              goto LAB_0010e6cc;
            }
            puVar13 = &DAT_00127c95;
            uVar22 = 0x3bd;
            goto LAB_0010ef0c;
          }
          puVar13 = &DAT_0011e44e;
          uVar22 = 0x1ad;
        }
      }
      else {
        puVar13 = &DAT_00120b9d;
        uVar22 = 0x16f;
      }
      _printk(puVar13,"goodix_parse_firmware",uVar22);
    }
    else {
      _printk(&DAT_001265d5,"goodix_parse_firmware",0x163,uVar14,iVar8 + 6);
    }
  }
LAB_0010e370:
  uVar22 = 0xffffffea;
LAB_0010e374:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar22;
LAB_0010e9c8:
  local_d4 = CONCAT31(local_d4._1_3_,0x95);
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
  if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10e9fc);
    (*pcVar17)();
  }
  uVar9 = (*pcVar17)(DAT_0012a960,0xcc58,&local_d4,1);
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
  if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10ea34);
    (*pcVar17)();
  }
  uVar10 = (*pcVar17)(DAT_0012a960,0xcc58,&local_d0,1);
  if ((uVar10 | uVar9) != 0 || (char)local_d0 != '\x01') goto code_r0x0010ea4c;
  _printk(&DAT_001271bb,"goodix_update_prepare",0x29d);
LAB_0010eab4:
  local_d4 = local_d4 & 0xffffff00;
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
  if (*(int *)(pcVar17 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10eaf0);
    (*pcVar17)();
  }
  (*pcVar17)(DAT_0012a960,uVar4,&local_d4,1);
  _printk(&DAT_00125a28,"goodix_update_prepare",0x2a3);
  uVar9 = DAT_0012a968[2];
  local_88 = 0;
  uStack_80 = 0;
  local_78 = 0;
  local_70 = 0;
  _printk(&DAT_00123e58,"goodix_load_isp",0x234);
  iVar8 = goodix_reg_write_confirm
                    (uVar9,*(undefined8 *)(param_1 + 0xb2),*(undefined4 *)(param_1 + 0xa6));
  if (iVar8 < 0) {
    _printk(&DAT_001277a4,"goodix_load_isp",0x238);
LAB_0010eca4:
    _printk(&DAT_001271e6,"goodix_update_prepare",0x2a8);
    goto LAB_0010e720;
  }
  _printk(&DAT_00120627,"goodix_load_isp",0x23c);
  local_90 = 0x5555555555555555;
  iVar8 = goodix_reg_write_confirm(0x10000,&local_90,8);
  if (iVar8 < 0) {
    _printk(&DAT_0011f34d,"goodix_load_isp",0x242);
    goto LAB_0010eca4;
  }
  _printk(&DAT_0012564f,"goodix_load_isp",0x245,0x10000);
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x28);
  if (*(int *)(pcVar17 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10ebf4);
    (*pcVar17)();
  }
  iVar8 = (*pcVar17)(DAT_0012a960,100);
  if (iVar8 != 0) {
    _printk(&DAT_00126c6a,"goodix_load_isp",0x248);
  }
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x60);
  if (*(int *)(pcVar17 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10ec38);
    (*pcVar17)();
  }
  iVar8 = (*pcVar17)(DAT_0012a960,&local_88);
  if (iVar8 != 0) {
    _printk(&DAT_00127cbb,"goodix_load_isp",0x24b);
    iVar8 = -2;
    goto LAB_0010eca4;
  }
  if (uStack_80._5_2_ != 0x5349 || uStack_80._7_1_ != 'P') {
    _printk(&DAT_0012211e,"goodix_load_isp",0x251,uStack_80._5_1_,uStack_80._6_1_,uStack_80._7_1_,
            &DAT_00126c8d);
    iVar8 = -3;
    goto LAB_0010eca4;
  }
  _printk(&DAT_00122a4a,"goodix_load_isp",0x254);
  puVar18 = *(uint **)(param_1 + 0x518);
  local_d0 = 0;
  local_c8 = 0;
  *(undefined4 *)(param_1 + 0x78) = 2;
  bVar5 = *(byte *)(param_1 + 0x9d);
  if ((puVar18 == (uint *)0x0) || (*puVar18 == 0)) {
LAB_0010ed3c:
    if (1 < bVar5) {
      iVar24 = 1;
      iVar26 = 3;
      do {
        _printk(&DAT_0011e961,"goodix_flash_firmware",0x381,iVar24);
        iVar8 = goodix_flash_subsystem(param_1 + (long)iVar24 * 0x18 + 0xa2);
        if (iVar8 == -0xb) {
          _printk(&DAT_0011d7b1,"goodix_flash_firmware",0x38a,iVar24,0xfffffff5,4 - iVar26);
          iVar26 = iVar26 + -1;
        }
        else if (iVar8 == 0) {
          _printk(&DAT_00125681,"goodix_flash_firmware",0x385,iVar24);
          iVar24 = iVar24 + 1;
        }
        else if (iVar8 < 0) {
          _printk(&DAT_0011dd5e,"goodix_flash_firmware",0x38d,iVar24,iVar8);
          break;
        }
      } while ((iVar24 < (int)(uint)bVar5) && (iVar26 != 0));
      goto LAB_0010ee40;
    }
LAB_0010ef40:
    _printk(&DAT_001255be,"goodix_fw_update_proc",0x3dc);
    goto LAB_0010eea0;
  }
  local_c0 = puVar18 + 1;
  local_d0 = (ulong)*puVar18 << 0x20;
  local_c8 = (ulong)*(uint *)(*(long *)(param_1 + 0x528) + 0x14);
  local_d0 = CONCAT71(local_d0._1_7_,4);
  iVar8 = goodix_flash_subsystem(&local_d0);
  if (iVar8 == 0) {
    _printk(&DAT_00126128,"goodix_flash_firmware",0x37d);
    goto LAB_0010ed3c;
  }
  _printk(&DAT_0011ed82,"goodix_flash_firmware",0x37a,iVar8);
LAB_0010ee40:
  if (bVar6 || -1 < iVar8) {
    if (iVar8 == 0) goto LAB_0010ef40;
    puVar13 = &DAT_0011e903;
    uVar22 = 0x3da;
    goto LAB_0010ee98;
  }
  bVar6 = true;
  _printk(&DAT_00121b8e,"goodix_fw_update_proc",0x3d6,1);
  goto LAB_0010e6f8;
code_r0x0010ea4c:
  usleep_range_state(1000,0x44c,2);
  _printk(&DAT_0012251b,"goodix_update_prepare",0x297,iVar8,local_d0 & 0xff);
  iVar8 = iVar8 + -1;
  if (iVar8 == 0) goto code_r0x0010ea80;
  goto LAB_0010e9c8;
code_r0x0010ea80:
  _printk(&DAT_00126637,"goodix_update_prepare",0x29a,uVar10 | uVar9);
  iVar8 = -2;
LAB_0010e720:
  _printk(&DAT_00123050,"goodix_fw_update_proc",0x3c9,2 - iVar7);
  iVar7 = iVar7 + -1;
  if (0 < iVar7) goto LAB_0010e750;
  puVar13 = &DAT_00126089;
  uVar22 = 0x3cd;
LAB_0010ee98:
  _printk(puVar13,"goodix_fw_update_proc",uVar22,iVar8);
LAB_0010eea0:
  pcVar17 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x28);
  if (*(int *)(pcVar17 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
    pcVar17 = (code *)SoftwareBreakpoint(0x8228,0x10eec8);
    (*pcVar17)();
  }
  iVar7 = (*pcVar17)(DAT_0012a960,100);
  if (iVar7 != 0) {
    _printk(&DAT_00126c6a,"goodix_update_finish",0x3a1);
  }
  uVar25 = goodix_fw_version_compare(param_1);
  if ((uVar25 & 0xfffffffb) != 0) {
    uVar22 = 0xffffffea;
    _printk(&DAT_001205c4,"goodix_fw_update_proc",0x3e3,0xffffffea);
    goto LAB_0010e374;
  }
  puVar13 = &DAT_0011f998;
  uVar22 = 0x3e1;
LAB_0010ef0c:
  _printk(puVar13,"goodix_fw_update_proc",uVar22);
  uVar22 = 0;
  goto LAB_0010e374;
}



//------------------------------------------------------------
// goodix_fw_version_compare @ 0010ef78 size=604
// signature: undefined goodix_fw_version_compare(void)
// callers: [goodix_fw_update_proc]
//------------------------------------------------------------

void goodix_fw_version_compare(long param_1)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  code *pcVar5;
  int *piVar6;
  int local_5c;
  undefined8 local_58;
  undefined2 local_50;
  int iStack_4e;
  short sStack_4a;
  undefined2 uStack_48;
  int local_46;
  undefined2 uStack_42;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  local_50 = 0;
  iStack_4e = 0;
  sStack_4a = 0;
  uStack_48 = 0;
  local_46 = 0;
  uStack_42 = 0;
  local_58 = 0;
  local_5c = 0;
  uVar1 = *(undefined4 *)(DAT_0012a968 + 0x20);
  pcVar5 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x60);
  if (*(int *)(pcVar5 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10efe4);
    (*pcVar5)();
  }
  iVar3 = (*pcVar5)(DAT_0012a960,&local_58);
  if (iVar3 == 0) {
    if (((int)local_58 == 0x4f434f4e && local_58._4_2_ == 0x4544) ||
       (iStack_4e == 0x4f434f4e && sStack_4a == 0x4544)) {
      _printk(&DAT_001259f7,"goodix_fw_version_compare",0x1cc);
      uVar4 = 1;
    }
    else if (CONCAT26(uStack_48,CONCAT24(sStack_4a,iStack_4e)) == *(long *)(param_1 + 0x91)) {
      if (local_46 == *(int *)(param_1 + 0x99)) {
        _printk(&DAT_00121014,"goodix_fw_version_compare",0x1de);
        piVar6 = *(int **)(param_1 + 0x518);
        if ((piVar6 != (int *)0x0) && (0 < *piVar6)) {
          iVar3 = goodix_get_file_config_id(piVar6 + 1);
          pcVar5 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
          if (*(int *)(pcVar5 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x10f180);
            (*pcVar5)();
          }
          (*pcVar5)(DAT_0012a960,uVar1,&local_5c,4);
          if (local_5c != iVar3) {
            _printk(&DAT_0011d747,"goodix_fw_version_compare",0x1e8,local_5c,iVar3);
            uVar4 = 4;
            goto LAB_0010eff0;
          }
          _printk(&DAT_00127758,"goodix_fw_version_compare",0x1eb);
        }
        uVar4 = 0;
      }
      else {
        _printk(&DAT_0012824a,"goodix_fw_version_compare",0x1d9,4,&local_46);
        _printk(&DAT_001205f7,"goodix_fw_version_compare",0x1db,4,(int *)(param_1 + 0x99));
        uVar4 = 3;
      }
    }
    else {
      _printk(&DAT_00126c39,"goodix_fw_version_compare",0x1d2,&iStack_4e);
      uVar4 = 2;
    }
  }
  else {
    uVar4 = 0xffffffea;
  }
LAB_0010eff0:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// goodix_do_fw_update @ 0010f1d8 size=320
// signature: undefined goodix_do_fw_update(void)
// callers: [goodix_later_init_thread, goodix_ts_firmware_update, goodix_sysfs_update_en_store]
//------------------------------------------------------------

undefined4 goodix_do_fw_update(undefined8 param_1,uint param_2)

{
  undefined4 uVar1;
  ulong uVar2;
  
  if (DAT_0012a470 == 0) {
    _printk(&DAT_00120b7a,"goodix_do_fw_update",0x53c);
    uVar1 = 0xffffffea;
  }
  else {
    DAT_0012a4b4 = param_2;
    DAT_0012a958 = param_1;
    if (debug_log_flag != '\0') {
      _printk(&DAT_00120fec,"goodix_do_fw_update",0x542);
    }
    if ((DAT_0012a4b4 >> 1 & 1) == 0) {
      uVar2 = kthread_create_on_node
                        (goodix_fw_update_thread,&goodix_fw_update_ctrl,0xffffffff,"goodix-fwu");
      if ((uVar2 < 0xfffffffffffff001) && (wake_up_process(uVar2), uVar2 != 0)) {
        _printk(&DAT_0012160f,"goodix_do_fw_update",0x550);
        uVar1 = 0;
      }
      else {
        _printk(&DAT_0011d5ee,"goodix_do_fw_update",0x54d,uVar2);
        uVar1 = 0xfffffff2;
      }
    }
    else {
      uVar1 = goodix_fw_update_thread(&goodix_fw_update_ctrl);
      _printk(&DAT_0011e939,"goodix_do_fw_update",0x545,uVar1);
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// goodix_fw_update_thread @ 0010f31c size=772
// signature: undefined goodix_fw_update_thread(void)
// callers: [goodix_do_fw_update]
//------------------------------------------------------------

int goodix_fw_update_thread(long param_1)

{
  long lVar1;
  long lVar2;
  undefined1 auVar3 [16];
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  undefined4 uVar8;
  
  lVar5 = ktime_get();
  *(undefined8 *)(param_1 + 0x78) = 0;
  mutex_lock(param_1);
  if ((*(uint *)(param_1 + 0x74) >> 6 & 1) == 0) {
    if ((*(uint *)(param_1 + 0x74) >> 4 & 1) == 0) {
      _printk(&DAT_001216c1,"goodix_fw_update_thread",0x50e);
      iVar4 = -0x16;
    }
    else {
      if (*(long *)(param_1 + 0x510) != 0) goto LAB_0010f4e8;
      _printk(&DAT_0011ddff,"goodix_fw_update_thread",0x509);
      iVar4 = -0x16;
    }
LAB_0010f4d8:
    *(undefined4 *)(param_1 + 0x74) = 0;
    mutex_unlock(param_1);
  }
  else {
    _printk(&DAT_0012168e,"goodix_fw_update_thread",0x501);
    lVar7 = param_1 + 0x34;
    lVar1 = *(long *)(*(long *)(param_1 + 0x520) + 8) + 0x10;
    _printk(&DAT_001216ee,"goodix_request_firmware",0x4d7,lVar7);
    lVar2 = param_1 + 0x510;
    iVar4 = request_firmware(lVar2,lVar7,lVar1);
    if (iVar4 != 0) {
      _printk(&DAT_001206ad,"goodix_request_firmware",0x4dd,1);
      msleep(200);
      iVar4 = request_firmware(lVar2,lVar7,lVar1);
      if (iVar4 != 0) {
        _printk(&DAT_001206ad,"goodix_request_firmware",0x4dd,2);
        msleep(200);
        iVar4 = request_firmware(lVar2,lVar7,lVar1);
        if (iVar4 != 0) {
          _printk(&DAT_001206ad,"goodix_request_firmware",0x4dd,3);
          msleep(200);
          _printk(&DAT_0011e489,"goodix_request_firmware",0x4e1,lVar7,iVar4);
          if (-1 < iVar4) goto LAB_0010f4e8;
          goto LAB_0010f4d8;
        }
      }
    }
    _printk(&DAT_00126180,"goodix_request_firmware",0x4e5,lVar7);
LAB_0010f4e8:
    if (debug_log_flag != '\0') {
      _printk(&DAT_001266d7,"goodix_fw_update_thread",0x513);
    }
    goodix_ts_blocking_notify(0,0);
    if (debug_log_flag != '\0') {
      _printk(&DAT_0011fa0c,"goodix_fw_update_thread",0x517);
    }
    iVar4 = goodix_fw_update_proc(param_1);
    if ((*(uint *)(param_1 + 0x74) >> 5 & 1) == 0) {
      if (((*(uint *)(param_1 + 0x74) >> 6 & 1) != 0) && (*(long *)(param_1 + 0x510) != 0)) {
        release_firmware();
        goto LAB_0010f570;
      }
    }
    else {
      kfree(*(undefined8 *)(param_1 + 0x510));
LAB_0010f570:
      *(undefined8 *)(param_1 + 0x510) = 0;
    }
    *(undefined4 *)(param_1 + 0x74) = 0;
    mutex_unlock(param_1);
    if (iVar4 == 0) {
      _printk(&DAT_0012615a,"goodix_fw_update_thread",0x52a);
      uVar6 = 2;
      uVar8 = 3;
      goto LAB_0010f5cc;
    }
  }
  _printk(&DAT_00123081,"goodix_fw_update_thread",0x526,iVar4);
  uVar6 = 1;
  uVar8 = 4;
LAB_0010f5cc:
  *(undefined4 *)(param_1 + 0x78) = uVar8;
  goodix_ts_blocking_notify(uVar6,0);
  lVar7 = ktime_get();
  auVar3 = SEXT816(lVar7 - lVar5) * SEXT816(0x431bde82d7b634db);
  *(int *)(param_1 + 0x7c) = (int)(auVar3._8_8_ >> 0x12) - (auVar3._12_4_ >> 0x1f);
  return iVar4;
}



//------------------------------------------------------------
// goodix_fw_update_init @ 0010f624 size=848
// signature: undefined goodix_fw_update_init(void)
// callers: [goodix_later_init_thread]
//------------------------------------------------------------

int goodix_fw_update_init(long param_1)

{
  bool bVar1;
  undefined1 *puVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  size_t __n;
  int iVar6;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x2d0) == 0)) {
    _printk(&DAT_001259c0,"goodix_fw_update_init",0x559);
    iVar4 = -0x13;
  }
  else {
    __mutex_init(&goodix_fw_update_ctrl,"&goodix_fw_update_ctrl.mutex",&goodix_fw_update_init___key)
    ;
    DAT_0012a4b4 = 0;
    DAT_0012a960 = param_1;
    *(code **)(param_1 + 0x688) = goodix_set_fwname;
    __n = strnlen((char *)(param_1 + 0x1f5),0x40);
    if (0x40 < __n) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("strnlen");
    }
    if (__n == 0x40) {
                    /* WARNING: Subroutine does not return */
      fortify_panic("__fortify_strlen");
    }
    memcpy(&DAT_0012a474,(char *)(param_1 + 0x1f5),__n);
    if (__n - 0x545 < 0xfffffffffffffa87) goto LAB_0010f958;
    (&DAT_0012a474)[__n] = 0;
    DAT_0012a9b0 = kobject_create_and_add("fwupdate",*(long *)(param_1 + 8) + 0x10);
    if (DAT_0012a9b0 == 0) {
      _printk(&DAT_0011ffa7,"goodix_fw_sysfs_init",0x499);
      iVar4 = -0x16;
    }
    else {
      iVar4 = sysfs_create_file_ns(DAT_0012a9b0,&dev_attr_update_en,0);
      if (iVar4 == 0) {
        iVar5 = sysfs_create_file_ns(DAT_0012a9b0,&dev_attr_fwsize,0);
        bVar1 = iVar5 == 0;
        if (bVar1) {
          iVar5 = sysfs_create_file_ns(DAT_0012a9b0,&dev_attr_result,0);
          iVar6 = 3;
        }
        else {
          iVar6 = 2;
        }
      }
      else {
        bVar1 = false;
        iVar6 = 1;
        iVar5 = iVar4;
      }
      if (iVar5 == 0) {
        DAT_0012a980 = 0;
        DAT_0012a970 = "fwimage";
        DAT_0012a978 = 0x1b6;
        DAT_0012a9a0 = goodix_sysfs_fwimage_store;
        iVar4 = sysfs_create_bin_file(DAT_0012a9b0);
        if (iVar4 == 0) {
          iVar4 = *(int *)(*(long *)(param_1 + 0x100) + 4);
          puVar2 = update_brb;
          if (iVar4 != 5) {
            puVar2 = update_brd;
          }
          DAT_0012a968 = &update_bra;
          if (iVar4 != 4) {
            DAT_0012a968 = puVar2;
          }
          DAT_0012a470 = 1;
          return 0;
        }
        _printk(&DAT_0012171e,"goodix_fw_sysfs_init",0x4af,iVar4);
        sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_update_en,0);
        sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_fwsize,0);
        sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_result,0);
        kobject_put(DAT_0012a9b0);
      }
      else {
        _printk(&DAT_0011ee30,"goodix_fw_sysfs_init",0x4a1);
        if (2 < iVar6 - 1U) {
LAB_0010f958:
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x10f95c);
          (*pcVar3)();
        }
        sysfs_remove_file_ns(DAT_0012a9b0,(&goodix_fwu_attrs)[iVar6 - 1U],0);
        if (iVar4 == 0) {
          if (2 < iVar6 - 2U) goto LAB_0010f958;
          sysfs_remove_file_ns(DAT_0012a9b0,(&goodix_fwu_attrs)[iVar6 - 2U],0);
          if (bVar1) {
            if (2 < iVar6 - 3U) goto LAB_0010f958;
            sysfs_remove_file_ns(DAT_0012a9b0,(&goodix_fwu_attrs)[iVar6 - 3U],0);
          }
        }
        kobject_put(DAT_0012a9b0);
        iVar4 = -0x16;
      }
    }
    _printk(&DAT_0011ed4d,"goodix_fw_update_init",0x568);
  }
  return iVar4;
}



//------------------------------------------------------------
// goodix_set_fwname @ 0010f978 size=104
// signature: undefined goodix_set_fwname(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_set_fwname(char *param_1)

{
  size_t __n;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffea;
  }
  __n = strlen(param_1);
  if (0x3e < __n) {
    __n = 0x3f;
  }
  memcpy(&DAT_0012a474,param_1,__n);
  (&DAT_0012a474)[__n] = 0;
  return 0;
}



//------------------------------------------------------------
// goodix_fw_update_uninit @ 0010f9e4 size=152
// signature: undefined goodix_fw_update_uninit(void)
// callers: [goodix_later_init_thread, goodix_ts_remove]
//------------------------------------------------------------

void goodix_fw_update_uninit(void)

{
  if (DAT_0012a470 != 0) {
    mutex_lock(&goodix_fw_update_ctrl);
    sysfs_remove_bin_file(DAT_0012a9b0,&DAT_0012a970);
    sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_update_en,0);
    sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_fwsize,0);
    sysfs_remove_file_ns(DAT_0012a9b0,&dev_attr_result,0);
    kobject_put(DAT_0012a9b0);
    DAT_0012a470 = 0;
    mutex_unlock(&goodix_fw_update_ctrl);
  }
  return;
}



//------------------------------------------------------------
// goodix_reg_write_confirm @ 0010fa7c size=612
// signature: undefined goodix_reg_write_confirm(void)
// callers: [goodix_fw_update_proc]
//------------------------------------------------------------

int goodix_reg_write_confirm(undefined4 param_1,void *param_2,uint param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  undefined8 *__s2;
  code *pcVar4;
  ulong __n;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  __n = (ulong)param_3;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  uStack_70 = 0;
  if (param_3 < 0x21) {
    __s2 = &local_78;
  }
  else {
    __s2 = (undefined8 *)__kmalloc(__n,0xdc0);
    if (__s2 == (undefined8 *)0x0) {
      iVar2 = -0xc;
      goto LAB_0010fc9c;
    }
  }
  pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
  if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fb1c);
    (*pcVar4)();
  }
  iVar2 = (*pcVar4)(DAT_0012a960,param_1,param_2,param_3);
  if (-1 < iVar2) {
    pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
    if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fb54);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(DAT_0012a960,param_1,__s2,param_3);
    if (-1 < iVar2) {
      iVar2 = bcmp(param_2,__s2,__n);
      if (iVar2 == 0) {
LAB_0010fcd4:
        iVar2 = 0;
      }
      else {
        pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
        if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fba0);
          (*pcVar4)();
        }
        iVar2 = (*pcVar4)(DAT_0012a960,param_1,param_2,param_3);
        if (-1 < iVar2) {
          pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
          if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fbd8);
            (*pcVar4)();
          }
          iVar2 = (*pcVar4)(DAT_0012a960,param_1,__s2,param_3);
          if (-1 < iVar2) {
            iVar2 = bcmp(param_2,__s2,__n);
            if (iVar2 == 0) goto LAB_0010fcd4;
            pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
            if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fc24);
              (*pcVar4)();
            }
            iVar2 = (*pcVar4)(DAT_0012a960,param_1,param_2,param_3);
            if (-1 < iVar2) {
              pcVar4 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
              if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10fc5c);
                (*pcVar4)();
              }
              iVar2 = (*pcVar4)(DAT_0012a960,param_1,__s2,param_3);
              if (-1 < iVar2) {
                iVar3 = bcmp(param_2,__s2,__n);
                iVar2 = 0;
                if (iVar3 != 0) {
                  iVar2 = -0x16;
                }
              }
            }
          }
        }
      }
    }
  }
  if (__s2 != &local_78) {
    kfree(__s2);
  }
LAB_0010fc9c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// goodix_flash_subsystem @ 0010fce0 size=1928
// signature: undefined goodix_flash_subsystem(void)
// callers: [goodix_fw_update_proc]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_flash_subsystem(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  long lVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  void *__dest;
  undefined *puVar11;
  undefined8 uVar12;
  uint uVar13;
  code *pcVar14;
  uint uVar15;
  ulong __n;
  uint uVar16;
  undefined4 local_88;
  undefined1 uStack_84;
  undefined2 uStack_83;
  int iStack_81;
  undefined5 uStack_7d;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  uVar15 = *(uint *)(param_1 + 4);
  iVar3 = *(int *)(param_1 + 8);
  __dest = (void *)kmalloc_trace(_queue_work_on,0xdc0,0x1004);
  if (__dest == (void *)0x0) {
    _printk(&DAT_00120651,"goodix_flash_subsystem",0x33c);
    iVar9 = -0x16;
  }
  else {
    if (uVar15 == 0) {
LAB_001102ec:
      iVar9 = 0;
    }
    else {
      uVar16 = 0;
LAB_0010fd64:
      uVar13 = uVar15;
      if (0xfff < uVar15) {
        uVar13 = 0x1000;
      }
      __n = (ulong)uVar13;
      iVar2 = uVar16 + iVar3;
      _printk(&DAT_0011d7fd,"goodix_flash_subsystem",0x345,iVar2,__n);
      memcpy(__dest,(void *)(*(long *)(param_1 + 0x10) + (ulong)uVar16),__n);
      goodix_append_checksum(__dest,__n,1);
      iVar1 = uVar13 + 4;
      uVar6 = *param_1;
      local_88 = 0;
      uStack_84 = 0;
      uStack_83 = 0;
      iStack_81 = 0;
      uStack_7d = 0;
      uVar4 = *(undefined4 *)(DAT_0012a968 + 0x10);
      pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
      if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10fe0c);
        (*pcVar14)();
      }
      iVar9 = (*pcVar14)(DAT_0012a960,uVar4,__dest,iVar1);
      if (-1 < iVar9) {
        bVar8 = false;
        do {
          uStack_83 = (undefined2)iVar1;
          local_88 = 0xbb0b0000;
          uStack_84 = uVar6;
          iStack_81 = iVar2;
          goodix_append_checksum((ulong)&local_88 | 2,9,0);
          uVar5 = *(undefined4 *)(DAT_0012a968 + 0xc);
          _printk(&DAT_0011edb7,"goodix_send_flash_cmd",0x2b7,0x10,&local_88);
          local_78 = 0;
          uStack_70 = 0;
          pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
          if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10fea4);
            (*pcVar14)();
          }
          iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_88,0x10);
          if (iVar9 == 0) {
            pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
            if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10fedc);
              (*pcVar14)();
            }
            iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
            if ((iVar9 != 0) || (local_78._1_1_ != -0x12)) {
              usleep_range_state(5000,0x13ec,2);
              _printk(&DAT_0011f9c9,"goodix_send_flash_cmd",0x2c8,0,local_78._1_1_,iVar9);
              pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
              if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10ff54);
                (*pcVar14)();
              }
              iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
              if ((iVar9 != 0) || (local_78._1_1_ != -0x12)) {
                usleep_range_state(5000,0x13ec,2);
                _printk(&DAT_0011f9c9,"goodix_send_flash_cmd",0x2c8,1,local_78._1_1_,iVar9);
                pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10ffcc);
                  (*pcVar14)();
                }
                iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
                if ((iVar9 != 0) || (local_78._1_1_ != -0x12)) {
                  usleep_range_state(5000,0x13ec,2);
                  _printk(&DAT_0011f9c9,"goodix_send_flash_cmd",0x2c8,2,local_78._1_1_,iVar9);
                  pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                  if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                    pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x110044);
                    (*pcVar14)();
                  }
                  iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
                  if ((iVar9 != 0) || (local_78._1_1_ != -0x12)) {
                    usleep_range_state(5000,0x13ec,2);
                    _printk(&DAT_0011f9c9,"goodix_send_flash_cmd",0x2c8,3,local_78._1_1_,iVar9);
                    pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x1100bc);
                      (*pcVar14)();
                    }
                    iVar9 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
                    if ((iVar9 != 0) || (local_78._1_1_ != -0x12)) {
                      usleep_range_state(5000,0x13ec,2);
                      _printk(&DAT_0011f9c9,"goodix_send_flash_cmd",0x2c8,4,local_78._1_1_,iVar9);
                      if (local_78._1_1_ != -0x12) {
                        _printk(&DAT_001277ca,"goodix_send_flash_cmd",0x2cc,local_78._1_1_,iVar9);
                        _printk(&DAT_00125a4e,"goodix_send_flash_cmd",0x2cd,0x10,&local_78);
                        iVar9 = -0x16;
                        goto LAB_001103b8;
                      }
                    }
                  }
                }
              }
            }
            _printk(&DAT_0012214e,"goodix_send_flash_cmd",0x2d0);
            msleep(0x32);
            iVar9 = 0;
            do {
              pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x38);
              if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x110190);
                (*pcVar14)();
              }
              iVar10 = (*pcVar14)(DAT_0012a960,uVar5,&local_78,0x10);
              if (((iVar10 == 0) && (local_78._1_1_ == -0x12)) && ((byte)local_78 == -0x12)) {
                _printk(&DAT_0011f382,"goodix_send_flash_cmd",0x2d9);
                _printk(&DAT_0011ff6d,"goodix_flash_package",0x319,iVar2,uVar13);
                uVar15 = uVar15 - uVar13;
                uVar16 = uVar16 + uVar13;
                if (uVar15 != 0) goto LAB_0010fd64;
                goto LAB_001102ec;
              }
              _printk(&DAT_001250d9,"goodix_send_flash_cmd",0x2de,iVar9,local_78._1_1_,
                      local_78 & 0xff,iVar10);
              msleep(10);
              iVar9 = iVar9 + 1;
            } while (iVar9 != 0x14);
            _printk(&DAT_0011ede3,"goodix_send_flash_cmd",0x2e3,0x14,local_78._1_1_,local_78 & 0xff,
                    iVar10);
            if (iVar10 != 0) {
              _printk(&DAT_0011f3ae,"goodix_send_flash_cmd",0x2e5);
              iVar9 = -0x16;
              goto LAB_001103b8;
            }
            if ((byte)local_78 < 0x44) {
              if ((byte)local_78 != 0x33) {
                if ((byte)local_78 == 0x22) {
                  puVar11 = &DAT_00127804;
                  uVar12 = 0x2eb;
                }
                else {
LAB_0011039c:
                  puVar11 = &DAT_0011dddc;
                  uVar12 = 0x2f7;
                }
LAB_001103b0:
                _printk(puVar11,"goodix_send_flash_cmd",uVar12);
                iVar9 = -0xe;
                goto LAB_001103b8;
              }
              puVar11 = &DAT_00127ce7;
              uVar12 = 0x2ee;
            }
            else {
              if ((byte)local_78 != 0x55) {
                if ((byte)local_78 != 0x44) goto LAB_0011039c;
                puVar11 = &DAT_0012669d;
                uVar12 = 0x2f1;
                goto LAB_001103b0;
              }
              puVar11 = &DAT_00121be0;
              uVar12 = 0x2f4;
            }
            _printk(puVar11,"goodix_send_flash_cmd",uVar12);
            if (bVar8) {
              iVar9 = -0xb;
              goto LAB_001103b8;
            }
          }
          else {
            _printk(&DAT_00126670,"goodix_send_flash_cmd",700,iVar9);
            if (!(bool)(iVar9 == -0xb & (bVar8 ^ 1U))) goto LAB_001103b8;
          }
          pcVar14 = *(code **)(*(long *)(DAT_0012a960 + 0x2d0) + 0x40);
          if (*(int *)(pcVar14 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x11028c);
            (*pcVar14)();
          }
          iVar9 = (*pcVar14)(DAT_0012a960,uVar4,__dest,iVar1);
          bVar8 = true;
        } while (-1 < iVar9);
      }
      _printk(&DAT_00120679,"goodix_flash_package",0x307);
LAB_001103b8:
      _printk(&DAT_0011dda5,"goodix_flash_subsystem",0x350,iVar2,__n);
    }
    kfree(__dest);
  }
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
}



//------------------------------------------------------------
// goodix_sysfs_fwimage_store @ 0011046c size=208
// signature: undefined goodix_sysfs_fwimage_store(void)
// callers: []
//------------------------------------------------------------

size_t goodix_sysfs_fwimage_store(void)

{
  void *in_x3;
  long in_x4;
  size_t in_x5;
  
  if (DAT_0012a950 == (ulong *)0x0) {
    _printk(&DAT_00124b08,"goodix_sysfs_fwimage_store",0x450);
    in_x5 = 0xfffffffffffffff4;
  }
  else if (*DAT_0012a950 == 0) {
    _printk(&DAT_00123b02,"goodix_sysfs_fwimage_store",0x455);
    in_x5 = 0xffffffffffffffea;
  }
  else if (*DAT_0012a950 < in_x5 + in_x4) {
    in_x5 = 0xfffffffffffffff2;
  }
  else {
    mutex_lock(&goodix_fw_update_ctrl);
    memcpy((void *)(DAT_0012a950[1] + in_x4),in_x3,in_x5);
    mutex_unlock(&goodix_fw_update_ctrl);
  }
  return in_x5;
}



//------------------------------------------------------------
// goodix_sysfs_update_en_store @ 00110540 size=280
// signature: undefined goodix_sysfs_update_en_store(void)
// callers: []
//------------------------------------------------------------

long goodix_sysfs_update_en_store(undefined8 param_1,undefined8 param_2,byte *param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  if ((param_3 == (byte *)0x0) || (param_4 == 0)) {
    puVar3 = &DAT_00125131;
    uVar4 = 0x3f8;
  }
  else if (DAT_0012a470 == 0) {
    puVar3 = &DAT_0011ffde;
    uVar4 = 0x3fc;
  }
  else {
    _printk(&DAT_001206d7,"goodix_sysfs_update_en_store",0x400,*param_3);
    uVar1 = *param_3 - 0x31;
    if ((5 < uVar1) || ((0x33U >> (ulong)(uVar1 & 0x1f) & 1) == 0)) {
      _printk(&DAT_00122190,"goodix_sysfs_update_en_store",0x40c);
      return -0x16;
    }
    iVar2 = goodix_do_fw_update(0,*(undefined4 *)(&DAT_0011d170 + (long)(char)uVar1 * 4));
    if (iVar2 == 0) {
      _printk(&DAT_0011d836,"goodix_sysfs_update_en_store",0x412);
      return param_4;
    }
    puVar3 = &DAT_00122a8e;
    uVar4 = 0x415;
  }
  _printk(puVar3,"goodix_sysfs_update_en_store",uVar4);
  return -0x16;
}



//------------------------------------------------------------
// goodix_sysfs_fwsize_show @ 0011065c size=76
// signature: undefined goodix_sysfs_fwsize_show(void)
// callers: []
//------------------------------------------------------------

long goodix_sysfs_fwsize_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  
  if (DAT_0012a950 == (undefined8 *)0x0) {
    lVar2 = -0x16;
  }
  else {
    iVar1 = snprintf(param_3,0x1000,"%zu\n",*DAT_0012a950);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// goodix_sysfs_fwsize_store @ 001106ac size=288
// signature: undefined goodix_sysfs_fwsize_store(void)
// callers: []
//------------------------------------------------------------

undefined8
goodix_sysfs_fwsize_store(undefined8 param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  code *pcVar4;
  int iVar5;
  ulong *__s;
  ulong local_50;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_50 = 0;
  iVar5 = sscanf(param_3,"%zu",&local_50);
  uVar3 = local_50;
  if ((iVar5 < 0) || (local_50 == 0)) {
    _printk(&DAT_0012671c,"goodix_sysfs_fwsize_store",0x433);
    param_4 = 0xfffffffffffffff2;
  }
  else {
    uVar1 = local_50 + 0x18;
    __s = (ulong *)vmalloc(uVar1);
    if (__s == (ulong *)0x0) {
      param_4 = 0xfffffffffffffff4;
    }
    else {
      mutex_lock(&goodix_fw_update_ctrl);
      memset(__s,0,local_50 + 0x18);
      if ((uVar1 < 8) || ((uVar3 & 0xfffffffffffffff8) == 0xfffffffffffffff0)) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x1107cc);
        (*pcVar4)();
      }
      DAT_0012a950 = __s;
      *__s = local_50;
      __s[1] = (ulong)(__s + 3);
      DAT_0012a4b4 = 0x10;
      mutex_unlock(&goodix_fw_update_ctrl);
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// goodix_sysfs_result_show @ 001107d0 size=280
// signature: undefined goodix_sysfs_result_show(void)
// callers: []
//------------------------------------------------------------

long goodix_sysfs_result_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  int iVar2;
  char local_58 [64];
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_58[0x30] = '\0';
  local_58[0x31] = '\0';
  local_58[0x32] = '\0';
  local_58[0x33] = '\0';
  local_58[0x34] = '\0';
  local_58[0x35] = '\0';
  local_58[0x36] = '\0';
  local_58[0x37] = '\0';
  local_58[0x38] = '\0';
  local_58[0x39] = '\0';
  local_58[0x3a] = '\0';
  local_58[0x3b] = '\0';
  local_58[0x3c] = '\0';
  local_58[0x3d] = '\0';
  local_58[0x3e] = '\0';
  local_58[0x3f] = '\0';
  local_58[0x20] = '\0';
  local_58[0x21] = '\0';
  local_58[0x22] = '\0';
  local_58[0x23] = '\0';
  local_58[0x24] = '\0';
  local_58[0x25] = '\0';
  local_58[0x26] = '\0';
  local_58[0x27] = '\0';
  local_58[0x28] = '\0';
  local_58[0x29] = '\0';
  local_58[0x2a] = '\0';
  local_58[0x2b] = '\0';
  local_58[0x2c] = '\0';
  local_58[0x2d] = '\0';
  local_58[0x2e] = '\0';
  local_58[0x2f] = '\0';
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  switch(DAT_0012a4b8) {
  case 1:
    local_58[8] = 'g';
    local_58[9] = '\0';
    local_58[10] = '\0';
    local_58[0xb] = '\0';
    local_58[0xc] = '\0';
    local_58[0xd] = '\0';
    local_58[0xe] = '\0';
    local_58[0xf] = '\0';
    local_58._0_8_ = s_preparing_00124afe._0_8_;
    goto LAB_001108a0;
  case 2:
    local_58._0_8_ = s_updating_001235ce._0_8_;
    break;
  case 3:
    local_58[0] = 's';
    local_58[1] = 'u';
    local_58[2] = 'c';
    local_58[3] = 'c';
    local_58[4] = 'e';
    local_58[5] = 's';
    local_58[6] = 's';
    local_58[7] = '\0';
    break;
  case 4:
    builtin_strncpy(local_58,"failed",7);
    local_58[7] = '\0';
    goto LAB_001108a0;
  default:
    local_58[0] = 'n';
    local_58[1] = 'o';
    local_58[2] = 't';
    local_58[3] = 'w';
    local_58[4] = 'o';
    local_58[5] = 'r';
    local_58[6] = 'k';
    local_58[7] = '\0';
  }
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
LAB_001108a0:
  iVar2 = snprintf(param_3,0x1000,"result:%s  spend_time:%dms\n",local_58,DAT_0012a4bc);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (long)iVar2;
}



//------------------------------------------------------------
// goodix_strncat @ 001108ec size=108
// signature: undefined goodix_strncat(void)
// callers: []
//------------------------------------------------------------

void goodix_strncat(char *param_1,char *param_2,size_t param_3)

{
  size_t sVar1;
  
  sVar1 = strnlen(param_1,param_3);
  if ((sVar1 == 0xffffffffffffffff) && (param_3 != 0xffffffffffffffff)) {
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  strncat(param_1 + sVar1,param_2,~sVar1 + param_3);
  return;
}



//------------------------------------------------------------
// goodix_strncatint @ 0011095c size=260
// signature: undefined goodix_strncatint(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

char * goodix_strncatint(char *param_1,ulong param_2,char *param_3,size_t param_4)

{
  ulong uVar1;
  long lVar2;
  code *pcVar3;
  size_t sVar4;
  size_t sVar5;
  char local_58 [32];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_58[0x10] = '\0';
  local_58[0x11] = '\0';
  local_58[0x12] = '\0';
  local_58[0x13] = '\0';
  local_58[0x14] = '\0';
  local_58[0x15] = '\0';
  local_58[0x16] = '\0';
  local_58[0x17] = '\0';
  local_58[0x18] = '\0';
  local_58[0x19] = '\0';
  local_58[0x1a] = '\0';
  local_58[0x1b] = '\0';
  local_58[0x1c] = '\0';
  local_58[0x1d] = '\0';
  local_58[0x1e] = '\0';
  local_58[0x1f] = '\0';
  local_58[0] = '\0';
  local_58[1] = '\0';
  local_58[2] = '\0';
  local_58[3] = '\0';
  local_58[4] = '\0';
  local_58[5] = '\0';
  local_58[6] = '\0';
  local_58[7] = '\0';
  local_58[8] = '\0';
  local_58[9] = '\0';
  local_58[10] = '\0';
  local_58[0xb] = '\0';
  local_58[0xc] = '\0';
  local_58[0xd] = '\0';
  local_58[0xe] = '\0';
  local_58[0xf] = '\0';
  snprintf(local_58,0x20,param_3,param_2 & 0xffffffff);
  sVar4 = strnlen(param_1,param_4);
  if ((sVar4 != 0xffffffffffffffff) || (param_4 == 0xffffffffffffffff)) {
    uVar1 = ~sVar4 + param_4;
    sVar5 = uVar1;
    if (0x1f < uVar1) {
      sVar5 = 0x20;
    }
    sVar5 = strnlen(local_58,sVar5);
    if ((sVar5 < 0x20) || (sVar5 == uVar1)) {
      param_1 = param_1 + sVar4;
      sVar4 = strlen(param_1);
      memcpy(param_1 + sVar4,local_58,sVar5);
      if (sVar5 + sVar4 == -1) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x110a5c);
        (*pcVar3)();
      }
      param_1[sVar5 + sVar4] = '\0';
      lVar2 = sp_el0;
      if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return param_1;
    }
  }
                    /* WARNING: Subroutine does not return */
  fortify_panic("strnlen");
}



//------------------------------------------------------------
// inspect_module_init @ 00110a64 size=156
// signature: undefined inspect_module_init(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

int inspect_module_init(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = goodix_get_default_kobj();
  iVar1 = sysfs_create_file_ns(uVar2,&dev_attr_get_rawdata,0);
  if (iVar1 < 0) {
    _printk(&DAT_001261ba,"inspect_module_init",0xb82);
    _printk(&DAT_0011f418,"inspect_module_init",0xb8b);
  }
  else {
    module_initialized = 1;
    _printk(&DAT_0011f3e8,"inspect_module_init",0xb87);
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// inspect_module_exit @ 00110b04 size=104
// signature: undefined inspect_module_exit(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

void inspect_module_exit(void)

{
  undefined8 uVar1;
  
  uVar1 = goodix_get_default_kobj();
  _printk(&DAT_001221bd,"inspect_module_exit",0xb93);
  if (module_initialized == '\x01') {
    sysfs_remove_file_ns(uVar1,&dev_attr_get_rawdata,0);
    module_initialized = '\0';
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_get_rawdata_show @ 00110b70 size=156
// signature: undefined goodix_ts_get_rawdata_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_get_rawdata_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  uVar3 = *(undefined8 *)(param_1 + 0x98);
  lVar2 = kmalloc_large(0x3718,0xdc0);
  if (lVar2 == 0) {
    _printk(&DAT_001248f7,"goodix_ts_get_rawdata_show",0xb6c);
    lVar2 = -0xc;
  }
  else {
    goodix_do_inspect(uVar3,lVar2);
    iVar1 = snprintf(param_3,0x1000,"resultInfo: %s",(char *)(lVar2 + 0x36b4));
    kfree(lVar2);
    lVar2 = (long)iVar1;
  }
  return lVar2;
}



//------------------------------------------------------------
// goodix_do_inspect @ 00110c0c size=17832
// signature: undefined goodix_do_inspect(void)
// callers: [goodix_ts_get_rawdata_show]
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00113934) */
/* WARNING: Removing unreachable block (ram,0x0011393c) */
/* WARNING: Removing unreachable block (ram,0x00113958) */
/* WARNING: Removing unreachable block (ram,0x00113978) */
/* WARNING: Removing unreachable block (ram,0x0011397c) */
/* WARNING: Removing unreachable block (ram,0x00113988) */
/* WARNING: Removing unreachable block (ram,0x001139a0) */
/* WARNING: Removing unreachable block (ram,0x001139b4) */
/* WARNING: Removing unreachable block (ram,0x001139cc) */
/* WARNING: Removing unreachable block (ram,0x001139e0) */
/* WARNING: Removing unreachable block (ram,0x00113a08) */
/* WARNING: Removing unreachable block (ram,0x00115198) */
/* WARNING: Removing unreachable block (ram,0x00113a14) */
/* WARNING: Removing unreachable block (ram,0x001141f8) */
/* WARNING: Removing unreachable block (ram,0x00113d30) */
/* WARNING: Removing unreachable block (ram,0x00113d50) */
/* WARNING: Removing unreachable block (ram,0x00113d54) */
/* WARNING: Removing unreachable block (ram,0x00113d64) */
/* WARNING: Removing unreachable block (ram,0x00113d80) */
/* WARNING: Removing unreachable block (ram,0x00113d8c) */
/* WARNING: Removing unreachable block (ram,0x00114fd8) */
/* WARNING: Removing unreachable block (ram,0x00114fe8) */
/* WARNING: Removing unreachable block (ram,0x00114ff4) */
/* WARNING: Removing unreachable block (ram,0x00115000) */
/* WARNING: Removing unreachable block (ram,0x00115008) */
/* WARNING: Removing unreachable block (ram,0x00113d98) */
/* WARNING: Removing unreachable block (ram,0x0011501c) */
/* WARNING: Removing unreachable block (ram,0x00115024) */
/* WARNING: Removing unreachable block (ram,0x00115034) */
/* WARNING: Removing unreachable block (ram,0x00115044) */
/* WARNING: Removing unreachable block (ram,0x0011504c) */
/* WARNING: Removing unreachable block (ram,0x00115078) */
/* WARNING: Removing unreachable block (ram,0x00115070) */
/* WARNING: Removing unreachable block (ram,0x0011507c) */
/* WARNING: Removing unreachable block (ram,0x0011508c) */

void goodix_do_inspect(long param_1,uint *param_2)

{
  ushort *puVar1;
  ushort *puVar2;
  long *plVar3;
  byte *pbVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  ushort uVar11;
  ushort uVar12;
  short sVar13;
  short sVar14;
  short sVar15;
  ushort uVar16;
  undefined2 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  size_t *psVar20;
  bool bVar21;
  char cVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  long *plVar28;
  undefined *puVar29;
  size_t sVar30;
  size_t sVar31;
  ulong uVar32;
  ushort *puVar33;
  byte bVar34;
  undefined8 uVar35;
  char cVar36;
  undefined1 uVar37;
  uint uVar38;
  uint uVar39;
  uint uVar40;
  long lVar41;
  code *pcVar42;
  char *pcVar43;
  int *piVar44;
  undefined1 uVar45;
  uint uVar46;
  long lVar47;
  ulong uVar48;
  ulong uVar49;
  uint uVar50;
  undefined2 *puVar51;
  uint *puVar52;
  uint uVar53;
  long lVar54;
  uint uVar55;
  long *plVar56;
  uint uVar57;
  short *psVar58;
  ulong uVar59;
  uint uVar60;
  uint uVar61;
  uint uVar62;
  long lVar63;
  void *__dest;
  byte bVar64;
  char *pcVar65;
  size_t sVar66;
  undefined4 uVar67;
  uint local_7d0;
  uint local_7c4;
  uint local_7c0;
  uint local_7a8;
  uint local_780;
  char local_75c [4];
  ushort local_758 [2];
  char local_754 [4];
  char local_750;
  undefined1 uStack_74f;
  undefined2 uStack_74e;
  undefined4 uStack_74c;
  undefined4 local_748;
  undefined4 uStack_744;
  long local_740;
  undefined8 local_738;
  undefined8 uStack_730;
  undefined8 local_728;
  undefined8 local_720;
  undefined8 local_718;
  ulong local_710;
  undefined8 local_708;
  undefined8 uStack_700;
  undefined8 local_6f8;
  undefined8 uStack_6f0;
  undefined8 local_6e8;
  undefined8 uStack_6e0;
  undefined8 local_6d8;
  undefined8 uStack_6d0;
  undefined4 local_6c8;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar41 = sp_el0;
  local_70 = *(long *)(lVar41 + 0x638);
  if (param_1 == 0) {
    _printk(&DAT_00125a6c,"goodix_do_inspect",0xb43);
    goto LAB_00111318;
  }
  plVar28 = (long *)kmalloc_large(0x19748,0xdc0);
  if (plVar28 == (long *)0x0) {
    _printk(&DAT_00124495,"goodix_do_inspect",0xb49);
    goto LAB_00111318;
  }
  *plVar28 = param_1;
  _printk(&DAT_001230aa,"goodix_tptest_prepare",0x2d4);
  lVar41 = *plVar28;
  *(undefined4 *)((long)plVar28 + 0x14) = *(undefined4 *)(lVar41 + 0xc1);
  *(undefined4 *)(plVar28 + 3) = *(undefined4 *)(lVar41 + 0xc5);
  *(undefined4 *)((long)plVar28 + 0x1c) = *(undefined4 *)(lVar41 + 0xcd);
  *(undefined4 *)(plVar28 + 4) = *(undefined4 *)(lVar41 + 0xd1);
  *(uint *)((long)plVar28 + 0x24) = (uint)*(byte *)(lVar41 + 0x48);
  bVar64 = *(byte *)(lVar41 + 0x49);
  *(uint *)(plVar28 + 5) = (uint)bVar64;
  iVar23 = *(int *)(*(long *)(lVar41 + 0x100) + 4);
  local_738 = 0;
  uStack_730 = 0;
  local_748 = 0;
  uStack_744 = 0;
  local_740 = 0;
  local_750 = '\0';
  uStack_74f = 0;
  uStack_74e = 0;
  uStack_74c = 0;
  local_80 = (size_t *)0x0;
  puVar6 = params_brb;
  if (iVar23 != 5) {
    puVar6 = (undefined1 *)&params_brd;
  }
  puVar7 = (undefined4 *)params_bra;
  if (iVar23 != 4) {
    puVar7 = (undefined4 *)puVar6;
  }
  plVar28[6] = (long)puVar7;
  lVar47 = *(long *)(lVar41 + 8);
  local_6c8 = 0;
  local_6d8 = 0;
  uStack_6d0 = 0;
  local_6e8 = 0;
  uStack_6e0 = 0;
  local_6f8 = 0;
  uStack_6f0 = 0;
  local_708 = 0;
  uStack_700 = 0;
  local_718 = 0;
  local_710 = 0;
  local_728 = 0;
  local_720 = 0;
  if (*(char **)(lVar41 + 0x698) == (char *)0x0) {
    snprintf((char *)&local_728,100,"%s_test_limits_%d.csv","goodix",(uint)*(byte *)(lVar41 + 0x27))
    ;
  }
  else {
    snprintf((char *)&local_728,100,"%s_%s_test_limits_%d.csv",*(char **)(lVar41 + 0x698),"goodix",
             (uint)*(byte *)(lVar41 + 0x27));
  }
  _printk(&DAT_001282ac,"goodix_init_testlimits",0x250,&local_728);
  iVar23 = request_firmware(&local_80,&local_728,lVar47 + 0x10);
  if (iVar23 < 0) {
    _printk(&DAT_00125ab0,"goodix_init_testlimits",0x254,&local_728);
LAB_001112a8:
    _printk(&DAT_00127d5a,"goodix_tptest_prepare",0x2da);
  }
  else {
    puVar5 = (uint *)(plVar28 + 0x1f61);
    if (*local_80 == 0) {
      _printk(&DAT_0011ee79,"goodix_init_testlimits",0x259,0);
      __dest = (void *)0x0;
      iVar23 = -0x16;
    }
    else {
      __dest = (void *)__kmalloc(*local_80 + 1,0xdc0);
      psVar20 = local_80;
      if (__dest == (void *)0x0) {
        _printk(&DAT_00121c49,"goodix_init_testlimits",0x25f);
        iVar23 = -0xc;
      }
      else {
        memcpy(__dest,(void *)local_80[1],*local_80);
        uVar24 = parse_csvfile(__dest,*psVar20,"test_config",plVar28 + 7,1);
        if ((int)uVar24 < 0) {
          _printk(&DAT_0011f448,"goodix_init_testlimits",0x269,"test_config");
        }
        else {
          _printk(&DAT_001235d7,"goodix_init_testlimits",0x26b,"test_config",uVar24);
          if (uVar24 != 0) {
            uVar48 = 0;
            do {
              if (uVar48 == 0x1000) goto LAB_0011347c;
              *(char *)((long)plVar28 + uVar48 + 0x156a0) =
                   (char)*(undefined4 *)((long)plVar28 + uVar48 * 4 + 0x38);
              uVar48 = uVar48 + 1;
            } while (uVar24 != uVar48);
          }
          *(uint *)((long)plVar28 + 0x1569c) = uVar24;
        }
        iVar23 = parse_csvfile(__dest,*local_80,"special_raw_min",plVar28 + 0xfa5,(uint)bVar64);
        if (iVar23 < 0) {
          _printk(&DAT_00124b6d,"goodix_init_testlimits",0x275);
        }
        else {
          _printk(&DAT_0011f46a,"goodix_init_testlimits",0x278,"special_raw_min");
          iVar23 = parse_csvfile(__dest,*local_80,"special_raw_max",plVar28 + 0x807,bVar64);
          if (iVar23 < 0) {
            _printk(&DAT_00127244,"goodix_init_testlimits",0x27e);
          }
          else {
            _printk(&DAT_0011f46a,"goodix_init_testlimits",0x281,"special_raw_max");
            iVar23 = parse_csvfile(__dest,*local_80,"special_raw_delta",plVar28 + 0x1743,bVar64);
            if (iVar23 < 0) {
              _printk(&DAT_00120003,"goodix_init_testlimits",0x287);
            }
            else {
              _printk(&DAT_0011f46a,"goodix_init_testlimits",0x28a,"special_raw_delta");
              uVar24 = parse_csvfile(__dest,*local_80,"special_selfraw_min",(long)plVar28 + 0xf904,1
                                    );
              uVar46 = parse_csvfile(__dest,*local_80,"special_selfraw_max",plVar28 + 0x1ee1,1);
              bVar21 = -1 < (int)(uVar46 | uVar24);
              if (bVar21) {
                _printk(&DAT_0011f46a,"goodix_init_testlimits",0x298,"special_selfraw_min");
                _printk(&DAT_0011f46a,"goodix_init_testlimits",0x299,"special_selfraw_max");
              }
              else {
                _printk(&DAT_001230d1,"goodix_init_testlimits",0x294);
              }
              *(bool *)((long)plVar28 + 0xe) = bVar21;
              iVar23 = parse_csvfile(__dest,*local_80,"noise_data_limit",plVar28 + 0x1f60,1);
              if (-1 < iVar23) {
                _printk(&DAT_0011f46a,"goodix_init_testlimits",0x2a5,"noise_data_limit");
              }
              else {
                _printk(&DAT_0012361b,"goodix_init_testlimits",0x2a1);
              }
              *(bool *)((long)plVar28 + 0xb) = -1 < iVar23;
              iVar23 = parse_csvfile(__dest,*local_80,"noise_selfdata_limit",(long)plVar28 + 0xfb04,
                                     1);
              if (-1 < iVar23) {
                _printk(&DAT_0011f46a,"goodix_init_testlimits",0x2b1,"noise_selfdata_limit");
              }
              else {
                _printk(&DAT_0012726e,"goodix_init_testlimits",0x2ad);
              }
              *(bool *)((long)plVar28 + 0xf) = -1 < iVar23;
              iVar23 = parse_csvfile(__dest,*local_80,"shortciurt_threshold",&local_750,1);
              if (iVar23 < 0) {
                _printk(&DAT_001217ba,"goodix_init_testlimits",0x2b9);
                iVar23 = 0;
                *(undefined1 *)((long)plVar28 + 0xd) = 0;
              }
              else {
                _printk(&DAT_0011f46a,"goodix_init_testlimits",0x2bd,"shortciurt_threshold");
                *(undefined1 *)((long)plVar28 + 0xd) = 1;
                *puVar5 = CONCAT22(uStack_74e,CONCAT11(uStack_74f,local_750));
                *(ulong *)((long)plVar28 + 0xfb0c) = CONCAT44(local_748,uStack_74c);
                *(undefined4 *)((long)plVar28 + 0xfb14) = uStack_744;
                plVar28[0x1f63] = local_740;
                *(undefined4 *)(plVar28 + 0x1f64) = (undefined4)local_738;
              }
            }
          }
        }
      }
    }
    kfree(__dest);
    if (local_80 != (size_t *)0x0) {
      release_firmware();
    }
    if (iVar23 < 0) goto LAB_001112a8;
    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x30);
    if (*(int *)(pcVar42 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111378);
      (*pcVar42)();
    }
    (*pcVar42)(*plVar28,0);
    goodix_ts_blocking_notify(5,0);
    if (*(int *)((long)plVar28 + 0x1569c) < 1) {
LAB_00111438:
      pcVar43 = (char *)((long)plVar28 + 0x196d7);
      _printk(&DAT_00127d33,"goodix_do_inspect",0xb55);
      _printk(&DAT_00123114,"goodix_capacitance_test",0x74a);
      local_728 = 0;
      local_720 = 0;
      _printk(&DAT_00120043,"goodix_cap_test_prepare",0x57c);
      cVar36 = *(char *)((long)plVar28 + 0xe);
      pcVar43[0] = '\x03';
      pcVar43[1] = '\x03';
      if (cVar36 == '\0') {
        if (*(char *)((long)plVar28 + 0xb) != '\0') goto LAB_001114ec;
LAB_001114a4:
        cVar36 = *(char *)((long)plVar28 + 0xf);
      }
      else {
        *(undefined1 *)((long)plVar28 + 0x196dc) = 3;
        if (*(char *)((long)plVar28 + 0xb) == '\0') goto LAB_001114a4;
LAB_001114ec:
        *(undefined1 *)((long)plVar28 + 0x196d9) = 3;
        cVar36 = *(char *)((long)plVar28 + 0xf);
      }
      if (cVar36 != '\0') {
        *(undefined1 *)((long)plVar28 + 0x196dd) = 3;
      }
      lVar41 = *plVar28;
      if (*(int *)(*(long *)(lVar41 + 0x100) + 4) == 6) {
        uVar37 = 5;
        uVar45 = 0x90;
        local_728._0_5_ = CONCAT14(0x81,(undefined4)local_728);
      }
      else {
        uVar37 = 4;
        uVar45 = 2;
      }
      local_728 = CONCAT53(CONCAT41(local_728._4_4_,uVar45),CONCAT12(uVar37,(undefined2)local_728));
      pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x48);
      if (*(int *)(pcVar42 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar42 = (code *)SoftwareBreakpoint(0x822a,0x111538);
        (*pcVar42)();
      }
      iVar23 = (*pcVar42)(lVar41,&local_728);
      if (iVar23 < 0) {
        _printk(&DAT_001256c3,"goodix_cap_test_prepare",0x591);
        _printk(&DAT_0011de2f,"goodix_capacitance_test",0x74d);
      }
      else {
        _printk(&DAT_00123ea8,"goodix_capacitance_test",0x750);
        memset(&local_728,0,0x6a4);
        lVar54 = *plVar28;
        iVar23 = *(int *)((long)plVar28 + 0x24);
        lVar47 = plVar28[5];
        uVar67 = *(undefined4 *)((long)plVar28 + 0x14);
        lVar41 = 0xa1;
        if (*(int *)(*(long *)(lVar54 + 0x100) + 4) != 6) {
          lVar41 = 0xb5;
        }
        uVar9 = *(undefined4 *)(lVar54 + lVar41);
        local_750 = '\0';
        pcVar42 = *(code **)(*(long *)(lVar54 + 0x2d0) + 0x40);
        if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111600);
          (*pcVar42)();
        }
        iVar26 = (*pcVar42)(lVar54,uVar9,&local_750,1);
        if (iVar26 < 0) {
          _printk(&DAT_00120c55,"goodix_cache_rawdata",0x5b5);
        }
        else {
          iVar26 = iVar23 * (int)lVar47;
          plVar3 = plVar28 + 0x1f65;
          iVar27 = 0x15;
          do {
            iVar27 = iVar27 + -1;
            if (iVar27 == 0) goto LAB_001117a8;
            usleep_range_state(5000,0x13ec,2);
            pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
            if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1116a4);
              (*pcVar42)();
            }
            iVar25 = (*pcVar42)(*plVar28,uVar9,&local_750,1);
          } while ((iVar25 != 0) || (-1 < local_750));
          if (0 < iVar27) {
            lVar41 = *plVar28;
            pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x38);
            if (*(int *)(*(long *)(lVar54 + 0x100) + 4) == 6) {
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1116fc);
                (*pcVar42)();
              }
              iVar27 = (*pcVar42)(lVar41,uVar9,&local_728,0x6a4);
              if (iVar27 < 0) goto LAB_00112f64;
              iVar27 = checksum_cmp(&local_728,*(undefined2 *)(lVar54 + 0xa5),0);
              if (iVar27 == 0) {
                iVar27 = checksum_cmp(&local_728,local_728._3_2_,1);
                if (iVar27 != 0) {
                  _printk(&DAT_00124396,"goodix_cache_rawdata",0x5ce);
                }
                uVar48 = (ulong)*(ushort *)(lVar54 + 0xaf) - 8;
                if (0x9c20 < uVar48) goto LAB_0011518c;
                if ((0x1e78 < uVar48) && ((goodix_cache_rawdata___already_done & 1) == 0)) {
                  goodix_cache_rawdata___already_done = 1;
                  __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                                ,uVar48,
                                "field \"(u8 *)ts_test->rawdata[i].data\" at ../../motorola/kernel/modules/drivers/input/touchscreen/goodix_berlin_mmi/goodix_ts_inspect.c:1494"
                                ,0x1e78);
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x800,0x115130);
                  (*pcVar42)();
                }
                memcpy(plVar3,(void *)((long)&local_720 +
                                      (ulong)*(ushort *)(lVar54 + 0xa7) +
                                      (ulong)*(ushort *)(lVar54 + 0xa9) +
                                      (ulong)*(ushort *)(lVar54 + 0xa5)),uVar48);
                goto LAB_00113134;
              }
              _printk(&DAT_00123022,"goodix_cache_rawdata",0x5c9);
LAB_00113340:
              _printk(&DAT_00123ef8,"goodix_capacitance_test",0x759);
            }
            else {
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x112f58);
                (*pcVar42)();
              }
              iVar27 = (*pcVar42)(lVar41,uVar67,plVar3,iVar26 * 2);
              if (iVar27 < 0) {
LAB_00112f64:
                if (iVar27 == -0xb) goto LAB_001117cc;
                goto LAB_00113340;
              }
LAB_00113134:
              *(int *)(plVar28 + 0x2334) = iVar26;
              goodix_rotate_abcd2cbad(iVar23,(int)lVar47,plVar3);
              _printk(&DAT_001267a1,"goodix_capacitance_test",0x75c);
              uVar24 = *(uint *)(plVar28 + 0x2334);
              if (uVar24 != 0) {
                bVar21 = false;
                uVar48 = 0;
                do {
                  while( true ) {
                    if ((uVar48 * 2 - 0x9c20 < 0xfffffffffffe68b8) ||
                       (uVar48 * 4 - 0x11a20 < 0xfffffffffffe68b8)) goto LAB_00113da0;
                    sVar14 = *(short *)((long)plVar3 + uVar48 * 2);
                    if ((int)sVar14 < *(int *)((long)plVar28 + uVar48 * 4 + 0x7d28)) {
                      if (uVar48 - 0x1eea < 0xfffffffffffe68b8) goto LAB_00113da0;
                      pcVar65 = (char *)((long)plVar28 + uVar48 + 0x1785e);
                      bVar21 = true;
                      *pcVar65 = *pcVar65 + '\x01';
                    }
                    if (uVar48 * 4 - 0x15710 < 0xfffffffffffe68b8) goto LAB_00113da0;
                    if ((int)sVar14 <= *(int *)((long)plVar28 + uVar48 * 4 + 0x4038)) break;
                    if (uVar48 - 0x2e26 < 0xfffffffffffe68b8) goto LAB_00113da0;
                    *(char *)((long)plVar28 + uVar48 + 0x16922) =
                         *(char *)((long)plVar28 + uVar48 + 0x16922) + '\x01';
                    uVar48 = uVar48 + 1;
                    if (uVar48 == uVar24) {
LAB_0011336c:
                      _printk(&DAT_001272b2,"goodix_analysis_rawdata",0x6e3,1);
                      cVar36 = '\x02';
                      goto LAB_0011338c;
                    }
                    bVar21 = true;
                    if (uVar48 == 0xf3c) goto LAB_0011347c;
                  }
                  uVar48 = uVar48 + 1;
                  if (uVar48 == uVar24) {
                    if (bVar21) goto LAB_0011336c;
                    goto LAB_00113178;
                  }
                } while (uVar48 != 0xf3c);
                goto LAB_0011347c;
              }
LAB_00113178:
              cVar36 = '\x01';
LAB_0011338c:
              *pcVar43 = cVar36;
            }
            uVar24 = *(uint *)(plVar28 + 0x2334);
            if (uVar24 != 0) {
              uVar46 = *(uint *)((long)plVar28 + 0x24);
              plVar56 = plVar3;
              uVar48 = 0;
              do {
                if (uVar48 == 0xf3c) goto LAB_0011347c;
                uVar50 = (uint)(-uVar46 + uVar48);
                iVar23 = (int)(short)*plVar56;
                if ((int)uVar50 < 0) {
                  iVar26 = 0;
                }
                else {
                  if (0xf3b < uVar50) goto LAB_0011347c;
                  iVar27 = *(short *)((long)plVar3 + (-uVar46 + uVar48 & 0xffffffff) * 2) - iVar23;
                  iVar26 = -iVar27;
                  if (-1 < iVar27) {
                    iVar26 = iVar27;
                  }
                }
                uVar50 = (uint)(uVar46 + uVar48);
                if (uVar50 < uVar24) {
                  if (0xf3b < uVar50) goto LAB_0011347c;
                  iVar25 = *(short *)((long)plVar3 + (uVar46 + uVar48 & 0xffffffff) * 2) - iVar23;
                  iVar27 = -iVar25;
                  if (-1 < iVar25) {
                    iVar27 = iVar25;
                  }
                  if (iVar26 <= iVar27) {
                    iVar26 = iVar27;
                  }
                }
                iVar27 = 0;
                if (uVar46 != 0) {
                  iVar27 = (int)uVar48 / (int)uVar46;
                }
                if ((int)uVar48 != iVar27 * uVar46) {
                  if (0xf3b < (uint)(uVar48 - 1)) goto LAB_0011347c;
                  iVar25 = *(short *)((long)plVar3 + (uVar48 - 1 & 0xffffffff) * 2) - iVar23;
                  iVar27 = -iVar25;
                  if (-1 < iVar25) {
                    iVar27 = iVar25;
                  }
                  if (iVar26 <= iVar27) {
                    iVar26 = iVar27;
                  }
                }
                uVar49 = uVar48 + 1;
                iVar27 = 0;
                if (uVar46 != 0) {
                  iVar27 = (int)uVar49 / (int)uVar46;
                }
                if ((int)uVar49 != iVar27 * uVar46) {
                  if (0xf3a < uVar48) goto LAB_0011347c;
                  iVar25 = *(short *)((long)plVar56 + 2) - iVar23;
                  iVar27 = -iVar25;
                  if (-1 < iVar25) {
                    iVar27 = iVar25;
                  }
                  if (iVar26 <= iVar27) {
                    iVar26 = iVar27;
                  }
                }
                sVar14 = 0;
                if (iVar23 != 0) {
                  sVar14 = (short)((iVar26 * 1000) / iVar23);
                }
                *(short *)((long)plVar56 + 0x1e7c) = sVar14;
                plVar56 = (long *)((long)plVar56 + 2);
                uVar48 = uVar49;
              } while (uVar24 != uVar49);
              *(uint *)((long)plVar28 + 0x1381c) = uVar24;
            }
            _printk(&DAT_0011e4e3,"goodix_capacitance_test",0x766);
            uVar24 = *(uint *)((long)plVar28 + 0x1381c);
            if (uVar24 == 0) {
LAB_00113558:
              uVar37 = 1;
            }
            else {
              uVar48 = 0;
              bVar21 = false;
              do {
                uVar59 = uVar48 * 4 - 0xdd30;
                uVar32 = uVar48 * 2 - 0x7da4;
                uVar49 = uVar48;
                while( true ) {
                  if (uVar49 == 0xf3c) goto LAB_0011347c;
                  if ((uVar32 < 0xfffffffffffe68b8) || (uVar59 < 0xfffffffffffe68b8))
                  goto LAB_00113da0;
                  if (*(int *)((long)plVar28 + uVar49 * 4 + 0xba18) <
                      (int)*(short *)((long)plVar28 + uVar49 * 2 + 0x119a4)) break;
                  uVar49 = uVar49 + 1;
                  uVar59 = uVar59 + 4;
                  uVar32 = uVar32 + 2;
                  if (uVar24 == uVar49) {
                    if (!bVar21) goto LAB_00113558;
                    goto LAB_00113550;
                  }
                }
                if (uVar49 - 0xfae < 0xfffffffffffe68b8) goto LAB_00113da0;
                uVar48 = uVar49 + 1;
                *(char *)((long)plVar28 + uVar49 + 0x1879a) =
                     *(char *)((long)plVar28 + uVar49 + 0x1879a) + '\x01';
                bVar21 = true;
              } while ((ulong)uVar24 - 1 != uVar49);
LAB_00113550:
              uVar37 = 2;
            }
            *(undefined1 *)(plVar28 + 0x32db) = uVar37;
            if (*(char *)((long)plVar28 + 0xe) != '\0') {
              lVar41 = *plVar28;
              uVar67 = *(undefined4 *)((long)plVar28 + 0x1c);
              uVar9 = *(undefined4 *)(lVar41 + 0xa1);
              iVar23 = *(int *)((long)plVar28 + 0x24) + (int)plVar28[5];
              memset(&local_728,0,0x6a4);
              if (*(int *)(*(long *)(lVar41 + 0x100) + 4) == 6) {
                pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x38);
                if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1135cc);
                  (*pcVar42)();
                }
                iVar26 = (*pcVar42)(lVar41,uVar9,&local_728,0x6a4);
                if (-1 < iVar26) {
                  iVar26 = checksum_cmp(&local_728,*(undefined2 *)(lVar41 + 0xa5),0);
                  if (iVar26 == 0) {
                    iVar26 = checksum_cmp(&local_728,local_728._3_2_,1);
                    if (iVar26 == 0) {
                      uVar48 = (ulong)*(ushort *)(lVar41 + 0xb1) - 10;
                      if (0x30a8 < uVar48) goto LAB_0011518c;
                      if ((0xfe < uVar48) && ((goodix_cache_self_rawdata___already_done & 1) == 0))
                      {
                        goodix_cache_self_rawdata___already_done = 1;
                        __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                                      ,uVar48,
                                      "field \"(u8 *)ts_test->self_rawdata.data\" at ../../motorola/kernel/modules/drivers/input/touchscreen/goodix_berlin_mmi/goodix_ts_inspect.c:1588"
                                      ,0xfe);
                    /* WARNING: Does not return */
                        pcVar42 = (code *)SoftwareBreakpoint(0x800,0x11515c);
                        (*pcVar42)();
                      }
                      memcpy(plVar28 + 0x2cd4,
                             (void *)((long)&local_720 +
                                     (ulong)*(ushort *)(lVar41 + 0xaf) +
                                     (ulong)*(ushort *)(lVar41 + 0xa7) +
                                     (ulong)*(ushort *)(lVar41 + 0xa9) +
                                     (ulong)*(ushort *)(lVar41 + 0xa5) + 2),uVar48);
                      goto LAB_001136b0;
                    }
                    _printk(&DAT_00124396,"goodix_cache_self_rawdata",0x62b);
                  }
                  else {
                    _printk(&DAT_00123022,"goodix_cache_self_rawdata",0x626);
                  }
                }
              }
              else {
                pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x38);
                if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1136a4);
                  (*pcVar42)();
                }
                iVar26 = (*pcVar42)(lVar41,uVar67,plVar28 + 0x2cd4,iVar23 * 2);
                if (-1 < iVar26) {
LAB_001136b0:
                  *(int *)(plVar28 + 0x2cf4) = iVar23;
                  _printk(&DAT_00127dbe,"goodix_capacitance_test",0x773);
                  iVar23 = goodix_analysis_self_rawdata(plVar28);
                  if (iVar23 < 0) {
                    uVar37 = 2;
                  }
                  else {
                    uVar37 = 1;
                  }
                  *(undefined1 *)((long)plVar28 + 0x196dc) = uVar37;
                  goto LAB_001137b0;
                }
              }
              _printk(&DAT_00122ad4,"goodix_capacitance_test",0x771);
            }
LAB_001137b0:
            if (*(char *)((long)plVar28 + 0xb) != '\0') {
              local_80 = (size_t *)((ulong)local_80 & 0xffffffffffffff00);
              memset(&local_728,0,0x6a4);
              lVar41 = *plVar28;
              local_750 = '\0';
              uStack_74f = 0;
              uStack_74e = 0;
              uStack_74c = 0;
              local_748 = 0;
              uStack_744 = 0;
              if (*(int *)(*(long *)(lVar41 + 0x100) + 4) == 6) {
                uVar67 = *(undefined4 *)(lVar41 + 0xa1);
                pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x48);
                uStack_74c = 0x82;
                uStack_74e = 0x9005;
                if (*(int *)(pcVar42 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x11382c);
                  (*pcVar42)();
                }
                iVar23 = (*pcVar42)(lVar41,&local_750);
                if (-1 < iVar23) {
                  lVar41 = *plVar28;
                  goto LAB_00113860;
                }
                _printk(&DAT_001221e5,"goodix_cache_noisedata",0x659);
              }
              else {
                uVar67 = *(undefined4 *)(lVar41 + 0xb5);
LAB_00113860:
                local_80 = (size_t *)((ulong)local_80 & 0xffffffffffffff00);
                pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x40);
                if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113890);
                  (*pcVar42)();
                }
                iVar23 = (*pcVar42)(lVar41,uVar67,&local_80,1);
                if (iVar23 < 0) {
                  _printk(&DAT_00120c55,"goodix_cache_noisedata",0x662);
                }
                else {
                  iVar23 = 0x15;
                  while (iVar23 = iVar23 + -1, iVar23 != 0) {
                    usleep_range_state(5000,0x13ec,2);
                    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
                    if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113924);
                      (*pcVar42)();
                    }
                    (*pcVar42)(*plVar28,uVar67,&local_80,1);
                  }
                  _printk(&DAT_0011fa32,"goodix_cache_noisedata",0x66d,(undefined1)local_80,0);
                }
              }
              _printk(&DAT_00120c28,"goodix_capacitance_test",0x780);
            }
            if (*(char *)((long)plVar28 + 0xf) == '\0') goto LAB_001117e8;
            lVar47 = *plVar28;
            lVar41 = plVar28[4];
            uVar67 = *(undefined4 *)(lVar47 + 0xa1);
            uVar24 = *(int *)((long)plVar28 + 0x24) + (int)plVar28[5];
            memset(&local_728,0,0x6a4);
            if (*(int *)(*(long *)(lVar47 + 0x100) + 4) == 6) {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x38);
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113ad8);
                (*pcVar42)();
              }
              iVar23 = (*pcVar42)(lVar47,uVar67,&local_728,0x6a4);
              if (-1 < iVar23) {
                iVar26 = checksum_cmp(&local_728,*(undefined2 *)(lVar47 + 0xa5),0);
                if (iVar26 == 0) {
                  iVar26 = checksum_cmp(&local_728,local_728._3_2_,1);
                  if (iVar26 == 0) {
                    uVar48 = (ulong)*(ushort *)(lVar47 + 0xb1) - 10;
                    if (0x2fa4 < uVar48) {
LAB_0011518c:
                    /* WARNING: Subroutine does not return */
                      fortify_panic("memcpy");
                    }
                    if ((0xfe < uVar48) && ((goodix_cache_self_noisedata___already_done & 1) == 0))
                    {
                      goodix_cache_self_noisedata___already_done = 1;
                      __warn_printk("memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n"
                                    ,uVar48,
                                    "field \"(u8 *)ts_test->self_noisedata.data\" at ../../motorola/kernel/modules/drivers/input/touchscreen/goodix_berlin_mmi/goodix_ts_inspect.c:1719"
                                    ,0xfe);
                    /* WARNING: Does not return */
                      pcVar42 = (code *)SoftwareBreakpoint(0x800,0x115188);
                      (*pcVar42)();
                    }
                    memcpy((void *)((long)plVar28 + 0x167a4),
                           (void *)((long)&local_720 +
                                   (ulong)*(ushort *)(lVar47 + 0xaf) +
                                   (ulong)*(ushort *)(lVar47 + 0xa7) +
                                   (ulong)*(ushort *)(lVar47 + 0xa9) +
                                   (ulong)*(ushort *)(lVar47 + 0xa5) + 2),uVar48);
                    goto LAB_00113bc4;
                  }
                  puVar29 = &DAT_00124396;
                  uVar35 = 0x6ae;
                }
                else {
                  puVar29 = &DAT_00123022;
                  uVar35 = 0x6a9;
                }
                _printk(puVar29,"goodix_cache_self_noisedata",uVar35);
              }
            }
            else {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x38);
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113bb4);
                (*pcVar42)();
              }
              iVar23 = (*pcVar42)(lVar47,(int)lVar41,(long)plVar28 + 0x167a4,uVar24 * 2);
              if (-1 < iVar23) {
LAB_00113bc4:
                *(uint *)((long)plVar28 + 0x168a4) = uVar24;
                if (uVar24 != 0) {
                  uVar48 = (ulong)uVar24 - 1;
                  if (0x7e < uVar48) {
                    uVar48 = 0x7f;
                  }
                  if (uVar48 < 2) {
                    uVar49 = 0;
                  }
                  else {
                    uVar59 = uVar48 + 1 & 1;
                    uVar49 = 2;
                    if (uVar59 != 0) {
                      uVar49 = uVar59;
                    }
                    uVar49 = (uVar48 + 1) - uVar49;
                    uVar48 = uVar49;
                    psVar58 = (short *)((long)plVar28 + 0x167a6);
                    do {
                      sVar13 = psVar58[-1];
                      sVar15 = *psVar58;
                      sVar14 = -sVar13;
                      if (-1 < sVar13) {
                        sVar14 = sVar13;
                      }
                      sVar13 = -sVar15;
                      if (-1 < sVar15) {
                        sVar13 = sVar15;
                      }
                      uVar48 = uVar48 - 2;
                      psVar58[-1] = sVar14;
                      *psVar58 = sVar13;
                      psVar58 = psVar58 + 2;
                    } while (uVar48 != 0);
                  }
                  do {
                    if (uVar49 == 0x7f) goto LAB_0011347c;
                    lVar41 = uVar49 * 2;
                    uVar49 = uVar49 + 1;
                    sVar15 = *(short *)((long)plVar28 + lVar41 + 0x167a4);
                    sVar14 = -sVar15;
                    if (-1 < sVar15) {
                      sVar14 = sVar15;
                    }
                    *(short *)((long)plVar28 + lVar41 + 0x167a4) = sVar14;
                  } while (uVar24 != uVar49);
                  if (iVar23 < 0) goto LAB_00113cc8;
                }
                _printk(&DAT_0012365a,"goodix_capacitance_test",0x791);
                iVar23 = goodix_analysis_self_noisedata(plVar28);
                if (iVar23 < 0) {
                  uVar37 = 2;
                }
                else {
                  uVar37 = 1;
                }
                *(undefined1 *)((long)plVar28 + 0x196dd) = uVar37;
                goto LAB_001117e8;
              }
            }
LAB_00113cc8:
            _printk(&DAT_0011e51c,"goodix_capacitance_test",0x78f);
            goto LAB_001117e8;
          }
LAB_001117a8:
          _printk(&DAT_0011eee6,"goodix_cache_rawdata",0x5c0,local_750,0);
        }
LAB_001117cc:
        _printk(&DAT_00123ed3,"goodix_capacitance_test",0x756);
      }
LAB_001117e8:
      _printk(&DAT_0012221c,"goodix_cap_test_finish",0x598);
      pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x28);
      if (*(int *)(pcVar42 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
        pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111828);
        (*pcVar42)();
      }
      (*pcVar42)(*plVar28,100);
      if (*(char *)((long)plVar28 + 0xd) != '\0') {
        local_758[0] = 0;
        local_75c[0] = '\0';
        iVar23 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
        local_78 = 0;
        local_80 = (size_t *)0x0;
        _printk(&DAT_00127866,"goodix_shortcircut_test",0x52c);
        local_750 = '\0';
        uStack_74f = 0;
        uStack_74e = 0;
        uStack_74c = 0;
        local_748 = 0;
        uStack_744 = 0;
        local_710 = local_710 & 0xffffffff00000000;
        local_720 = 0;
        local_718 = 0;
        local_728 = 0;
        local_754[0] = '\0';
        _printk(&DAT_001272ea,"goodix_short_test_prepare",0x310);
        *(undefined1 *)((long)plVar28 + 0x196db) = 3;
        uStack_74e = 0x8504;
        pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x48);
        if (*(int *)(pcVar42 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1118d0);
          (*pcVar42)();
        }
        iVar26 = (*pcVar42)(*plVar28,&local_750);
        if (-1 < iVar26) {
          pbVar4 = (byte *)(plVar28 + 0x2d15);
          lVar41 = (long)&local_720 + 2;
          uVar24 = 0xfffffffc;
          do {
            msleep(0x28);
            lVar47 = *plVar28;
            if (*(int *)(*(long *)(lVar47 + 0x100) + 4) == 4) {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x60);
              if (*(int *)(pcVar42 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1119f0);
                (*pcVar42)();
              }
              iVar26 = (*pcVar42)(lVar47,&local_728);
              if (iVar26 < 0) {
LAB_00112ef0:
                puVar29 = &DAT_00124bd3;
                uVar35 = 0x322;
                goto LAB_001118ec;
              }
              if (local_720._5_2_ != 0x534f || local_720._7_1_ != 'T') {
                _printk(&DAT_001200ed,"goodix_short_test_prepare",0x329,lVar41,&DAT_00128364);
                goto LAB_00111a7c;
              }
LAB_00112e50:
              pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x112e84);
                (*pcVar42)();
              }
              iVar26 = (*pcVar42)(*plVar28,*(undefined4 *)(plVar28[6] + 0x18),local_758,2);
              if (iVar26 < 0) {
                _printk(&DAT_001244bd,"goodix_shortcircut_test",0x536,7000);
                local_758[0] = 7000;
              }
              else {
                uVar48 = (ulong)local_758[0];
                if (iVar23 == 4) {
                  lVar41 = uVar48 * 0x1999999a;
                  uVar48 = uVar48 / 10;
                  local_758[0] = (ushort)((ulong)lVar41 >> 0x20);
                }
                else if (15000 < local_758[0]) {
                  _printk(&DAT_001267d8,"goodix_shortcircut_test",0x53d,uVar48,15000);
                  uVar48 = 15000;
                  local_758[0] = 15000;
                }
                _printk(&DAT_00121c8d,"goodix_shortcircut_test",0x540,uVar48);
              }
              if (iVar23 == 4) {
                local_78 = CONCAT62(local_78._2_6_,*(undefined2 *)(plVar28[6] + 0x34));
                local_80 = (size_t *)CONCAT44(*(undefined4 *)(plVar28[6] + 0x36),0xaa0a0000);
                goodix_append_checksum((ulong)&local_80 | 2,8,0);
                pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x40);
                if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113028);
                  (*pcVar42)();
                }
                iVar23 = (*pcVar42)(*plVar28,0x10400,&local_80,local_80._2_1_ + 2);
                if (iVar23 < 0) {
                  _printk(&DAT_00123b2c,"goodix_shortcircut_test",0x54f);
                  goto LAB_0011190c;
                }
                usleep_range_state(10000,11000,2);
              }
              else {
                local_75c[0] = '\0';
                pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x40);
                if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                  pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113084);
                  (*pcVar42)();
                }
                (*pcVar42)(*plVar28,0x10400,local_75c,1);
              }
              msleep(local_758[0]);
              iVar23 = 0x31;
              goto LAB_001130c0;
            }
            pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x38);
            if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111a54);
              (*pcVar42)();
            }
            iVar26 = (*pcVar42)(lVar47,0x10400,local_754,1);
            if ((iVar26 == 0) && (local_754[0] == -0x56)) goto LAB_00112e50;
            _printk(&DAT_0012073a,"goodix_short_test_prepare",0x32e,local_754[0],iVar26);
LAB_00111a7c:
            msleep(0x28);
            lVar47 = *plVar28;
            if (*(int *)(*(long *)(lVar47 + 0x100) + 4) == 4) {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x60);
              if (*(int *)(pcVar42 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111abc);
                (*pcVar42)();
              }
              iVar26 = (*pcVar42)(lVar47,&local_728);
              if (iVar26 < 0) goto LAB_00112ef0;
              if (local_720._5_2_ != 0x534f || local_720._7_1_ != 'T') {
                _printk(&DAT_001200ed,"goodix_short_test_prepare",0x329,lVar41,&DAT_00128364);
                goto LAB_00111b48;
              }
              goto LAB_00112e50;
            }
            pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x38);
            if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
              pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111b20);
              (*pcVar42)();
            }
            iVar26 = (*pcVar42)(lVar47,0x10400,local_754,1);
            if ((iVar26 == 0) && (local_754[0] == -0x56)) goto LAB_00112e50;
            _printk(&DAT_0012073a,"goodix_short_test_prepare",0x32e,local_754[0],iVar26);
LAB_00111b48:
            msleep(0x28);
            lVar47 = *plVar28;
            if (*(int *)(*(long *)(lVar47 + 0x100) + 4) == 4) {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x60);
              if (*(int *)(pcVar42 + -4) != 0x2b152b11) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111b88);
                (*pcVar42)();
              }
              iVar26 = (*pcVar42)(lVar47,&local_728);
              if (iVar26 < 0) goto LAB_00112ef0;
              if (local_720._5_2_ == 0x534f && local_720._7_1_ == 'T') goto LAB_00112e50;
              _printk(&DAT_001200ed,"goodix_short_test_prepare",0x329,lVar41,&DAT_00128364);
            }
            else {
              pcVar42 = *(code **)(*(long *)(lVar47 + 0x2d0) + 0x38);
              if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111bec);
                (*pcVar42)();
              }
              iVar26 = (*pcVar42)(lVar47,0x10400,local_754,1);
              if ((iVar26 == 0) && (local_754[0] == -0x56)) goto LAB_00112e50;
              _printk(&DAT_0012073a,"goodix_short_test_prepare",0x32e,local_754[0],iVar26);
            }
            bVar21 = 0xfffffffe < uVar24;
            uVar24 = uVar24 + 1;
            if (bVar21) goto LAB_001118f0;
            pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x28);
            if (*(int *)(pcVar42 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
              pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111c44);
              (*pcVar42)();
            }
            (*pcVar42)(*plVar28,100);
            pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x48);
            if (*(int *)(pcVar42 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
              pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111c70);
              (*pcVar42)();
            }
            iVar26 = (*pcVar42)(*plVar28,&local_750);
          } while (-1 < iVar26);
        }
        puVar29 = &DAT_00123f23;
        uVar35 = 0x318;
LAB_001118ec:
        _printk(puVar29,"goodix_short_test_prepare",uVar35);
LAB_001118f0:
        _printk(&DAT_0011df08,"goodix_shortcircut_test",0x52f);
      }
      goto LAB_0011190c;
    }
    _printk(&DAT_00120707,"goodix_tptest_prepare",0x2e5);
    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x50);
    if (*(int *)(pcVar42 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1113dc);
      (*pcVar42)();
    }
    iVar23 = (*pcVar42)(*plVar28,plVar28 + 0x2ad4,*(undefined4 *)((long)plVar28 + 0x1569c));
    if (-1 < iVar23) goto LAB_00111438;
    _printk(&DAT_00121c17,"goodix_tptest_prepare",0x2e8);
    goodix_ts_blocking_notify(6,0);
    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x30);
    if (*(int *)(pcVar42 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x111430);
      (*pcVar42)();
    }
    (*pcVar42)(*plVar28,1);
  }
  _printk(&DAT_00124b39,"goodix_do_inspect",0xb50);
  uVar19 = s__FAIL__0F_software_reason_0011d188._16_8_;
  uVar18 = s__FAIL__0F_software_reason_0011d188._8_8_;
  uVar35 = s__FAIL__0F_software_reason_0011d188._0_8_;
  param_2[0xdb5] = 0;
  param_2[0xdb6] = 0;
  param_2[0xdb7] = 0;
  param_2[0xdb8] = 0;
  param_2[0xdb9] = 0;
  param_2[0xdba] = 0;
  param_2[0xdbb] = 0;
  param_2[0xdbc] = 0;
  param_2[0xdbd] = 0;
  param_2[0xdbe] = 0;
  param_2[0xdbf] = 0;
  param_2[0xdc0] = 0;
  *(undefined8 *)(param_2 + 0xdad) = uVar35;
  *(undefined8 *)(param_2 + 0xdaf) = uVar18;
  param_2[0xdc1] = 0;
  param_2[0xdc2] = 0;
  param_2[0xdc3] = 0;
  param_2[0xdc4] = 0;
  *(undefined4 *)((long)param_2 + 0x3713) = 0;
  *(undefined8 *)(param_2 + 0xdb1) = uVar19;
  param_2[0xdb3] = 0xa6e;
  param_2[0xdb4] = 0;
  goto LAB_00111310;
  while( true ) {
    msleep(0x32);
    iVar23 = iVar23 + -1;
    if (iVar23 == -1) break;
LAB_001130c0:
    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
    if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1130f4);
      (*pcVar42)();
    }
    iVar26 = (*pcVar42)(*plVar28,*(undefined4 *)(plVar28[6] + 0x1c),local_75c,1);
    if ((iVar26 == 0) && (local_75c[0] == -0x78)) {
      if (iVar23 < 0) {
        cVar36 = -0x78;
        goto LAB_00113118;
      }
      _printk(&DAT_001200b5,"goodix_shortcircut_test",0x56d);
      local_728 = 0;
      pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
      if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x1131d0);
        (*pcVar42)();
      }
      iVar23 = (*pcVar42)(*plVar28,*(undefined4 *)(plVar28[6] + 0x20),&local_728,8);
      if (iVar23 < 0) {
        puVar29 = &DAT_00120c9f;
        uVar35 = 0x4ed;
      }
      else {
        iVar23 = checksum_cmp(&local_728,8,0);
        if (iVar23 == 0) {
          if ((local_728 & 0xf) == 0) {
            _printk(&DAT_00120ccf,"goodix_shortcircut_analysis",0x4f8);
            goto LAB_001150e8;
          }
          _printk(&DAT_0011fa8f,"goodix_shortcircut_analysis",0x4fd,local_728 & 0xff,local_728._1_1_
                  ,local_728._2_1_,local_728._3_1_,local_728._4_1_,local_728._5_1_);
          uVar24 = (uint)local_728._1_1_;
          if (uVar24 == 0) {
            local_7c4 = 0;
            goto LAB_00114254;
          }
          uVar46 = *(uint *)plVar28[6];
          uVar50 = ((uint *)plVar28[6])[1];
          iVar23 = uVar46 * 2 + 6;
          puVar33 = (ushort *)__kmalloc((long)iVar23,0xdc0);
          if (puVar33 != (ushort *)0x0) {
            uVar53 = 0;
            local_7c4 = 0;
            iVar26 = *(int *)(plVar28[6] + 0x24);
            goto LAB_00113df4;
          }
          _printk(&DAT_00123165,"gdix_check_tx_tx_shortcircut",0x392);
          local_7c4 = 0xfffffff4;
          goto LAB_00114254;
        }
        puVar29 = &DAT_00125166;
        uVar35 = 0x4f3;
      }
      _printk(puVar29,"goodix_shortcircut_analysis",uVar35);
      goto LAB_001136fc;
    }
  }
  cVar36 = local_75c[0];
LAB_00113118:
  _printk(&DAT_00126ce7,"goodix_shortcircut_test",0x568,cVar36);
  goto LAB_0011190c;
code_r0x00114098:
  uVar62 = uVar62 + 1;
  if (*puVar52 == uVar62) goto LAB_001140a4;
  goto LAB_0011408c;
code_r0x00114584:
  uVar38 = uVar38 + 1;
  if (*puVar52 == uVar38) goto LAB_00114590;
  goto LAB_00114578;
code_r0x00114a28:
  uVar61 = uVar61 + 1;
  if (*puVar52 == uVar61) goto LAB_0011486c;
  goto LAB_00114a1c;
LAB_00113df4:
  do {
    pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
    if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x113e24);
      (*pcVar42)();
    }
    iVar27 = (*pcVar42)(*plVar28,iVar26,puVar33,iVar23);
    if (iVar27 < 0) {
      puVar29 = &DAT_00123b5e;
      uVar35 = 0x39a;
LAB_00114240:
      _printk(puVar29,"gdix_check_tx_tx_shortcircut",uVar35);
      local_7c4 = 0xffffffea;
      break;
    }
    iVar27 = checksum_cmp(puVar33,iVar23,0);
    if (iVar27 != 0) {
      puVar29 = &DAT_00124c00;
      uVar35 = 0x3a0;
      goto LAB_00114240;
    }
    uVar55 = *puVar33 - uVar50 & 0xffff;
    if ((int)uVar55 < (int)uVar46) {
      uVar16 = puVar33[1];
      if ((ushort)(uVar16 + 1) < 2) {
        _printk(&DAT_00126807,"gdix_check_tx_tx_shortcircut",0x3b1,uVar16);
      }
      else {
        if ((int)(uVar55 + 1) < (int)uVar46) {
          uVar48 = (ulong)uVar55 + 1;
          uVar57 = *(uint *)((long)plVar28 + 0xfb0c);
          uVar55 = uVar50 + uVar55;
          do {
            uVar12 = *(ushort *)((long)puVar33 + (long)((int)uVar48 * 2 + 4));
            if (*puVar5 <= (uint)uVar12) {
              uVar38 = (uint)uVar12;
              iVar27 = uVar16 - uVar38;
              uVar40 = 0;
              uVar39 = (uint)uVar12;
              if (uVar38 != 0) {
                uVar40 = uVar16 / uVar39;
              }
              iVar25 = 0;
              if (uVar39 != 0) {
                iVar25 = (iVar27 * 0x4a) / (int)uVar39;
              }
              uVar61 = 0;
              if (uVar39 != 0) {
                uVar61 = (iVar27 * 0x3f) / (int)uVar38;
              }
              iVar27 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
              uVar40 = uVar40 * 0x46 - 0xb;
              if (iVar27 == 4) {
                uVar40 = uVar61;
              }
              uVar38 = iVar25 + 0x14;
              if (iVar27 != 5) {
                uVar38 = uVar40;
              }
              if (uVar38 < uVar57) {
                puVar52 = (uint *)plVar28[6];
                uVar39 = puVar52[1];
                uVar40 = uVar55;
                if ((uVar55 & 0x80) != 0) {
                  uVar40 = uVar39 + (uVar55 & 0xffffff7f);
                }
                if (uVar39 != 0) {
                  uVar61 = 0;
                  do {
                    if (uVar40 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar61)) {
                      if (uVar61 != 0xff) goto LAB_00114024;
                      break;
                    }
                    uVar61 = uVar61 + 1;
                  } while (uVar39 != uVar61);
                }
                if (*puVar52 != 0) {
                  uVar61 = 0;
                  do {
                    if (uVar40 == *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar61)) {
                      uVar61 = uVar61 | 0x80;
                      goto LAB_00114024;
                    }
                    uVar61 = uVar61 + 1;
                  } while (*puVar52 != uVar61);
                }
                _printk(&DAT_00127314,"map_die2pin",0x353);
                uVar61 = 0xff;
LAB_00114024:
                uVar40 = uVar50 + (int)uVar48;
                if ((uVar40 >> 7 & 1) == 0) {
                  puVar52 = (uint *)plVar28[6];
                  uVar39 = puVar52[1];
                }
                else {
                  puVar52 = (uint *)plVar28[6];
                  uVar39 = puVar52[1];
                  uVar40 = uVar39 + (uVar40 & 0xffffff7f);
                }
                if (uVar39 != 0) {
                  uVar62 = 0;
                  do {
                    if (uVar40 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar62)) {
                      if (uVar62 != 0xff) goto LAB_001140dc;
                      break;
                    }
                    uVar62 = uVar62 + 1;
                  } while (uVar39 != uVar62);
                }
                if (*puVar52 != 0) {
                  uVar62 = 0;
LAB_0011408c:
                  if (uVar40 != *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar62))
                  goto code_r0x00114098;
                  uVar62 = uVar62 | 0x80;
LAB_001140dc:
                  uVar40 = uVar61 & 0xff;
                  if ((uVar40 == 0xff) || (uVar39 = uVar62 & 0xff, uVar39 == 0xff))
                  goto LAB_001140bc;
                  if ((uVar61 & 0xff) != (uVar62 & 0xff)) {
                    bVar64 = *pbVar4;
                    uVar49 = (ulong)bVar64;
                    if (bVar64 < 0xf) {
                      psVar58 = (short *)((long)plVar28 + 0x168ac);
                      uVar59 = uVar49;
                      if (bVar64 == 0) {
                        uVar49 = 0;
                      }
                      else {
                        do {
                          uVar60 = (uint)psVar58[-1];
                          bVar34 = 1;
                          if (uVar40 == uVar60) {
                            bVar34 = 2;
                          }
                          if (uVar39 != uVar60) {
                            bVar34 = uVar40 == uVar60;
                          }
                          if (uVar40 == (int)*psVar58) {
                            bVar34 = bVar34 + 1;
                          }
                          if (uVar39 == (int)*psVar58) {
                            bVar34 = bVar34 + 1;
                          }
                          if (1 < bVar34) goto LAB_00113ea0;
                          uVar59 = uVar59 - 1;
                          psVar58 = psVar58 + 4;
                        } while (uVar59 != 0);
                      }
                      *(short *)((long)plVar28 + uVar49 * 8 + 0x168aa) = (short)(uVar61 & 0xff);
                      *(short *)((long)plVar28 + uVar49 * 8 + 0x168ac) = (short)(uVar62 & 0xff);
                      *(ushort *)((long)plVar28 + uVar49 * 8 + 0x168ae) =
                           (ushort)(uVar38 >> 8) & 0xff;
                      *(ushort *)(plVar28 + uVar49 + 0x2d16) = (ushort)uVar38 & 0xff;
                      if (bVar64 < 0xf) {
                        *pbVar4 = bVar64 + 1;
                      }
                    }
                  }
LAB_00113ea0:
                  _printk(&DAT_00124514,"gdix_check_tx_tx_shortcircut",0x3c8,uVar38,uVar57);
                  puVar29 = &DAT_0011e566;
                  if ((uVar61 & 0x80) != 0) {
                    puVar29 = &DAT_001278b9;
                  }
                  puVar8 = &DAT_0011e566;
                  if ((uVar62 & 0x80) != 0) {
                    puVar8 = &DAT_001278b9;
                  }
                  _printk(&DAT_0012076e,"gdix_check_tx_tx_shortcircut",0x3cd,puVar29,uVar61 & 0x7f,
                          puVar8,uVar62 & 0x7f);
                  local_7c4 = 0xffffffea;
                  goto LAB_00113f20;
                }
LAB_001140a4:
                _printk(&DAT_00127314,"map_die2pin",0x353);
LAB_001140bc:
                _printk(&DAT_00123190,"gdix_check_tx_tx_shortcircut",0x3c2);
              }
            }
LAB_00113f20:
            uVar48 = uVar48 + 1;
          } while (uVar48 != uVar46);
        }
        iVar26 = iVar26 + iVar23;
      }
    }
    else {
      _printk(&DAT_0011faf7,"gdix_check_tx_tx_shortcircut",0x3aa,uVar50 + uVar55);
    }
    uVar53 = uVar53 + 1;
  } while (uVar53 != uVar24);
  kfree(puVar33);
LAB_00114254:
  uVar24 = (uint)local_728._2_1_;
  if (uVar24 != 0) {
    uVar46 = *(uint *)(plVar28[6] + 4);
    iVar23 = uVar46 * 2 + 6;
    puVar33 = (ushort *)__kmalloc((long)iVar23,0xdc0);
    if (puVar33 == (ushort *)0x0) {
      _printk(&DAT_00123165,"gdix_check_rx_rx_shortcircut",0x3e9);
      local_7c0 = 0xfffffff4;
    }
    else {
      uVar50 = 0;
      local_7c0 = 0;
      iVar26 = *(int *)(plVar28[6] + 0x28);
      do {
        pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
        if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x114328);
          (*pcVar42)();
        }
        iVar27 = (*pcVar42)(*plVar28,iVar26,puVar33,iVar23);
        if (iVar27 != 0) {
          puVar29 = &DAT_00125b45;
          uVar35 = 0x3f1;
LAB_00114708:
          _printk(puVar29,"gdix_check_rx_rx_shortcircut",uVar35);
          local_7c0 = 0xffffffea;
          break;
        }
        iVar27 = checksum_cmp(puVar33,iVar23,0);
        if (iVar27 != 0) {
          puVar29 = &DAT_001261f1;
          uVar35 = 0x3f7;
          goto LAB_00114708;
        }
        uVar16 = *puVar33;
        if ((int)(uint)uVar16 < (int)uVar46) {
          uVar12 = puVar33[1];
          if ((ushort)(uVar12 + 1) < 2) {
            _printk(&DAT_00126807,"gdix_check_rx_rx_shortcircut",0x406,uVar12);
          }
          else {
            if ((int)(uVar16 + 1) < (int)uVar46) {
              uVar53 = *(uint *)((long)plVar28 + 0xfb14);
              uVar48 = (ulong)uVar16 + 1;
              do {
                uVar55 = (uint)uVar48;
                uVar11 = *(ushort *)((long)puVar33 + (long)(int)(uVar55 * 2 + 4));
                if (*puVar5 <= (uint)uVar11) {
                  uVar40 = (uint)uVar11;
                  iVar27 = uVar12 - uVar40;
                  uVar57 = 0;
                  uVar38 = (uint)uVar11;
                  if (uVar40 != 0) {
                    uVar57 = uVar12 / uVar38;
                  }
                  iVar25 = 0;
                  if (uVar38 != 0) {
                    iVar25 = (iVar27 * 0x4a) / (int)uVar38;
                  }
                  uVar39 = 0;
                  if (uVar38 != 0) {
                    uVar39 = (iVar27 * 0x3f) / (int)uVar40;
                  }
                  iVar27 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
                  uVar57 = uVar57 * 0x46 - 0xb;
                  if (iVar27 == 4) {
                    uVar57 = uVar39;
                  }
                  uVar40 = iVar25 + 0x14;
                  if (iVar27 != 5) {
                    uVar40 = uVar57;
                  }
                  if (uVar40 < uVar53) {
                    puVar52 = (uint *)plVar28[6];
                    uVar38 = puVar52[1];
                    uVar57 = (uint)uVar16;
                    if ((uVar16 & 0x80) != 0) {
                      uVar57 = uVar38 + (uVar16 & 0xffffff7f);
                    }
                    if (uVar38 != 0) {
                      uVar39 = 0;
                      do {
                        if (uVar57 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar39)) {
                          if (uVar39 != 0xff) goto LAB_00114514;
                          break;
                        }
                        uVar39 = uVar39 + 1;
                      } while (uVar38 != uVar39);
                    }
                    if (*puVar52 != 0) {
                      uVar39 = 0;
                      do {
                        if (uVar57 == *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar39)) {
                          uVar39 = uVar39 | 0x80;
                          goto LAB_00114514;
                        }
                        uVar39 = uVar39 + 1;
                      } while (*puVar52 != uVar39);
                    }
                    _printk(&DAT_00127314,"map_die2pin",0x353);
                    uVar39 = 0xff;
LAB_00114514:
                    if ((uVar55 >> 7 & 1) == 0) {
                      puVar52 = (uint *)plVar28[6];
                      uVar57 = puVar52[1];
                    }
                    else {
                      puVar52 = (uint *)plVar28[6];
                      uVar57 = puVar52[1];
                      uVar55 = uVar57 + (uVar55 & 0xffffff7f);
                    }
                    if (uVar57 != 0) {
                      uVar38 = 0;
                      do {
                        if (uVar55 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar38)) {
                          if (uVar38 != 0xff) goto LAB_001145c8;
                          break;
                        }
                        uVar38 = uVar38 + 1;
                      } while (uVar57 != uVar38);
                    }
                    if (*puVar52 != 0) {
                      uVar38 = 0;
LAB_00114578:
                      if (uVar55 != *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar38))
                      goto code_r0x00114584;
                      uVar38 = uVar38 | 0x80;
LAB_001145c8:
                      uVar55 = uVar39 & 0xff;
                      if ((uVar55 == 0xff) || (uVar57 = uVar38 & 0xff, uVar57 == 0xff))
                      goto LAB_001145a8;
                      if ((uVar39 & 0xff) != (uVar38 & 0xff)) {
                        bVar64 = *pbVar4;
                        uVar49 = (ulong)bVar64;
                        if (bVar64 < 0xf) {
                          psVar58 = (short *)((long)plVar28 + 0x168ac);
                          uVar59 = uVar49;
                          if (bVar64 == 0) {
                            uVar49 = 0;
                          }
                          else {
                            do {
                              uVar61 = (uint)psVar58[-1];
                              bVar34 = 1;
                              if (uVar55 == uVar61) {
                                bVar34 = 2;
                              }
                              if (uVar57 != uVar61) {
                                bVar34 = uVar55 == uVar61;
                              }
                              if (uVar55 == (int)*psVar58) {
                                bVar34 = bVar34 + 1;
                              }
                              if (uVar57 == (int)*psVar58) {
                                bVar34 = bVar34 + 1;
                              }
                              if (1 < bVar34) goto LAB_00114394;
                              uVar59 = uVar59 - 1;
                              psVar58 = psVar58 + 4;
                            } while (uVar59 != 0);
                          }
                          *(short *)((long)plVar28 + uVar49 * 8 + 0x168aa) = (short)(uVar39 & 0xff);
                          *(short *)((long)plVar28 + uVar49 * 8 + 0x168ac) = (short)(uVar38 & 0xff);
                          *(ushort *)((long)plVar28 + uVar49 * 8 + 0x168ae) =
                               (ushort)(uVar40 >> 8) & 0xff;
                          *(ushort *)(plVar28 + uVar49 + 0x2d16) = (ushort)uVar40 & 0xff;
                          if (bVar64 < 0xf) {
                            *pbVar4 = bVar64 + 1;
                          }
                        }
                      }
LAB_00114394:
                      _printk(&DAT_00124514,"gdix_check_rx_rx_shortcircut",0x41b,uVar40,uVar53);
                      puVar29 = &DAT_0011e566;
                      if ((uVar39 & 0x80) != 0) {
                        puVar29 = &DAT_001278b9;
                      }
                      puVar8 = &DAT_0011e566;
                      if ((uVar38 & 0x80) != 0) {
                        puVar8 = &DAT_001278b9;
                      }
                      _printk(&DAT_0012076e,"gdix_check_rx_rx_shortcircut",0x420,puVar29,
                              uVar39 & 0x7f,puVar8,uVar38 & 0x7f);
                      local_7c0 = 0xffffffea;
                      goto LAB_00114410;
                    }
LAB_00114590:
                    _printk(&DAT_00127314,"map_die2pin",0x353);
LAB_001145a8:
                    _printk(&DAT_00123190,"gdix_check_rx_rx_shortcircut",0x415);
                  }
                }
LAB_00114410:
                uVar48 = uVar48 + 1;
              } while (uVar48 != uVar46);
            }
            iVar26 = iVar26 + iVar23;
          }
        }
        else {
          _printk(&DAT_0011faf7,"gdix_check_rx_rx_shortcircut",0x3ff);
        }
        uVar50 = uVar50 + 1;
      } while (uVar50 != uVar24);
      kfree(puVar33);
    }
    local_7c4 = local_7c0 | local_7c4;
  }
  uVar24 = (uint)local_728._3_1_;
  if (uVar24 != 0) {
    uVar46 = *(uint *)plVar28[6];
    uVar50 = ((uint *)plVar28[6])[1];
    iVar23 = uVar46 * 2 + 6;
    puVar33 = (ushort *)__kmalloc((long)iVar23,0xdc0);
    if (puVar33 == (ushort *)0x0) {
      _printk(&DAT_00123165,"gdix_check_tx_rx_shortcircut",0x43d);
      local_7d0 = 0xfffffff4;
    }
    else {
      uVar53 = 0;
      local_7d0 = 0;
      iVar26 = *(int *)(plVar28[6] + 0x2c);
      do {
        pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
        if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
          pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x114800);
          (*pcVar42)();
        }
        iVar27 = (*pcVar42)(*plVar28,iVar26,puVar33,iVar23);
        if (iVar27 != 0) {
          puVar29 = &DAT_0011f4bb;
          uVar35 = 0x445;
LAB_00114be4:
          _printk(puVar29,"gdix_check_tx_rx_shortcircut",uVar35);
          local_7d0 = 0xffffffea;
          break;
        }
        iVar27 = checksum_cmp(puVar33,iVar23,0);
        if (iVar27 != 0) {
          puVar29 = &DAT_00123f4d;
          uVar35 = 1099;
          goto LAB_00114be4;
        }
        uVar16 = *puVar33;
        if ((int)(uint)uVar16 < (int)uVar50) {
          uVar12 = puVar33[1];
          if ((ushort)(uVar12 + 1) < 2) {
            _printk(&DAT_00126807,"gdix_check_tx_rx_shortcircut",0x45a,uVar12);
          }
          else {
            if (0 < (int)uVar46) {
              uVar48 = 0;
              uVar55 = *(uint *)(plVar28 + 0x1f62);
              local_7a8 = uVar16 & 0xffffff7f;
              do {
                uVar11 = *(ushort *)((long)puVar33 + (long)((int)uVar48 * 2 + 4));
                if (*puVar5 <= (uint)uVar11) {
                  uVar40 = (uint)uVar11;
                  iVar27 = uVar12 - uVar40;
                  uVar57 = 0;
                  uVar38 = (uint)uVar11;
                  if (uVar40 != 0) {
                    uVar57 = uVar12 / uVar38;
                  }
                  iVar25 = 0;
                  if (uVar38 != 0) {
                    iVar25 = (iVar27 * 0x4a) / (int)uVar38;
                  }
                  uVar39 = 0;
                  if (uVar38 != 0) {
                    uVar39 = (iVar27 * 0x3f) / (int)uVar40;
                  }
                  iVar27 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
                  uVar57 = uVar57 * 0x46 - 0xb;
                  if (iVar27 == 4) {
                    uVar57 = uVar39;
                  }
                  uVar40 = iVar25 + 0x14;
                  if (iVar27 != 5) {
                    uVar40 = uVar57;
                  }
                  if (uVar40 < uVar55) {
                    puVar52 = (uint *)plVar28[6];
                    uVar38 = puVar52[1];
                    uVar57 = (uint)uVar16;
                    if ((uVar16 & 0x80) != 0) {
                      uVar57 = uVar38 + local_7a8;
                    }
                    if (uVar38 != 0) {
                      uVar39 = 0;
                      do {
                        if (uVar57 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar39)) {
                          if (uVar39 != 0xff) goto LAB_001149b4;
                          break;
                        }
                        uVar39 = uVar39 + 1;
                      } while (uVar38 != uVar39);
                    }
                    if (*puVar52 != 0) {
                      uVar39 = 0;
                      do {
                        if (uVar57 == *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar39)) {
                          uVar39 = uVar39 | 0x80;
                          goto LAB_001149b4;
                        }
                        uVar39 = uVar39 + 1;
                      } while (*puVar52 != uVar39);
                    }
                    _printk(&DAT_00127314,"map_die2pin",0x353);
                    uVar39 = 0xff;
LAB_001149b4:
                    uVar57 = uVar50 + (int)uVar48;
                    if ((uVar57 >> 7 & 1) == 0) {
                      puVar52 = (uint *)plVar28[6];
                      uVar38 = puVar52[1];
                    }
                    else {
                      puVar52 = (uint *)plVar28[6];
                      uVar38 = puVar52[1];
                      uVar57 = uVar38 + (uVar57 & 0xffffff7f);
                    }
                    if (uVar38 != 0) {
                      uVar61 = 0;
                      do {
                        if (uVar57 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar61)) {
                          if (uVar61 != 0xff) goto LAB_00114a3c;
                          break;
                        }
                        uVar61 = uVar61 + 1;
                      } while (uVar38 != uVar61);
                    }
                    if (*puVar52 != 0) {
                      uVar61 = 0;
LAB_00114a1c:
                      if (uVar57 != *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar61))
                      goto code_r0x00114a28;
                      uVar61 = uVar61 | 0x80;
LAB_00114a3c:
                      uVar57 = uVar39 & 0xff;
                      if ((uVar57 == 0xff) || (uVar38 = uVar61 & 0xff, uVar38 == 0xff))
                      goto LAB_00114884;
                      if ((uVar39 & 0xff) != (uVar61 & 0xff)) {
                        bVar64 = *pbVar4;
                        uVar49 = (ulong)bVar64;
                        if (bVar64 < 0xf) {
                          psVar58 = (short *)((long)plVar28 + 0x168ac);
                          uVar59 = uVar49;
                          if (bVar64 == 0) {
                            uVar49 = 0;
                          }
                          else {
                            do {
                              uVar62 = (uint)psVar58[-1];
                              bVar34 = 1;
                              if (uVar57 == uVar62) {
                                bVar34 = 2;
                              }
                              if (uVar38 != uVar62) {
                                bVar34 = uVar57 == uVar62;
                              }
                              if (uVar57 == (int)*psVar58) {
                                bVar34 = bVar34 + 1;
                              }
                              if (uVar38 == (int)*psVar58) {
                                bVar34 = bVar34 + 1;
                              }
                              if (1 < bVar34) goto LAB_00114b0c;
                              uVar59 = uVar59 - 1;
                              psVar58 = psVar58 + 4;
                            } while (uVar59 != 0);
                          }
                          *(short *)((long)plVar28 + uVar49 * 8 + 0x168aa) = (short)(uVar39 & 0xff);
                          *(short *)((long)plVar28 + uVar49 * 8 + 0x168ac) = (short)(uVar61 & 0xff);
                          *(ushort *)((long)plVar28 + uVar49 * 8 + 0x168ae) =
                               (ushort)(uVar40 >> 8) & 0xff;
                          *(ushort *)(plVar28 + uVar49 + 0x2d16) = (ushort)uVar40 & 0xff;
                          if (bVar64 < 0xf) {
                            *pbVar4 = bVar64 + 1;
                          }
                        }
                      }
LAB_00114b0c:
                      _printk(&DAT_00124514,"gdix_check_tx_rx_shortcircut",0x46f,uVar40,uVar55);
                      puVar29 = &DAT_0011e566;
                      if ((uVar39 & 0x80) != 0) {
                        puVar29 = &DAT_001278b9;
                      }
                      puVar8 = &DAT_0011e566;
                      if ((uVar61 & 0x80) != 0) {
                        puVar8 = &DAT_001278b9;
                      }
                      _printk(&DAT_0012076e,"gdix_check_tx_rx_shortcircut",0x474,puVar29,
                              uVar39 & 0x7f,puVar8,uVar61 & 0x7f);
                      local_7d0 = 0xffffffea;
                      goto LAB_001148b0;
                    }
LAB_0011486c:
                    _printk(&DAT_00127314,"map_die2pin",0x353);
LAB_00114884:
                    _printk(&DAT_00123190,"gdix_check_tx_rx_shortcircut",0x469);
                  }
                }
LAB_001148b0:
                uVar48 = uVar48 + 1;
              } while (uVar48 != uVar46);
            }
            iVar26 = iVar26 + iVar23;
          }
        }
        else {
          _printk(&DAT_0011faf7,"gdix_check_tx_rx_shortcircut",0x453);
        }
        uVar53 = uVar53 + 1;
      } while (uVar53 != uVar24);
      kfree(puVar33);
    }
    local_7c4 = local_7d0 | local_7c4;
  }
  if (!(local_728._4_1_ == '\0' && local_728._5_1_ == '\0')) {
    uVar24 = ((int *)plVar28[6])[1] + *(int *)plVar28[6];
    iVar23 = uVar24 * 2 + 2;
    lVar41 = __kmalloc((long)iVar23,0xdc0);
    if (lVar41 == 0) {
      _printk(&DAT_00123165,"gdix_check_gndvdd_shortcircut",0x4c2);
      local_780 = 0xfffffff4;
    }
    else {
      pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x38);
      if (*(int *)(pcVar42 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x114ca4);
        (*pcVar42)();
      }
      iVar26 = (*pcVar42)(*plVar28,*(undefined4 *)(plVar28[6] + 0x30),lVar41,iVar23);
      if (iVar26 < 0) {
        puVar29 = &DAT_00124c37;
        uVar35 = 0x4ca;
LAB_001150a4:
        _printk(puVar29,"gdix_check_gndvdd_shortcircut",uVar35);
        local_780 = 0xffffffea;
      }
      else {
        iVar23 = checksum_cmp(lVar41,iVar23,0);
        if (iVar23 != 0) {
          puVar29 = &DAT_00121cb4;
          uVar35 = 0x4d0;
          goto LAB_001150a4;
        }
        if ((int)uVar24 < 1) {
          local_780 = 0;
        }
        else {
          uVar48 = 0;
          local_780 = 0;
          do {
            uVar50 = (uint)uVar48;
            uVar16 = *(ushort *)(lVar41 + (int)(uVar50 << 1));
            uVar46 = (int)(short)uVar16 & 0x7fff;
            if ((uVar16 & 0x7fff) == 0) {
              uVar46 = 1;
            }
            if ((short)uVar16 < 0) {
              iVar23 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
              if (iVar23 == 4) {
                iVar23 = -0x28;
                iVar26 = -64000;
                iVar27 = 0x1400;
              }
              else if (iVar23 == 5) {
                iVar23 = -0x3c;
                iVar26 = -0x26ac0;
                iVar27 = 0x3180;
              }
              else {
                iVar23 = -0x14;
                iVar26 = -0x24540;
                iVar27 = 0x2e80;
              }
              uVar53 = 0;
              if (uVar46 != 0) {
                uVar53 = (int)(iVar26 + iVar27 * (uint)*(ushort *)(plVar28 + 0x1f64)) / (int)uVar46;
              }
            }
            else {
              iVar23 = *(int *)(*(long *)(*plVar28 + 0x100) + 4);
              if (iVar23 == 4) {
                iVar23 = -0x28;
                uVar55 = 0xfa94;
              }
              else {
                if (iVar23 == 5) {
                  uVar55 = 0x4be4;
                  iVar23 = -0x3c;
                }
                else {
                  uVar55 = 0x3668;
                  iVar23 = -0xf;
                }
                uVar55 = uVar55 | 0x20000;
              }
              uVar53 = 0;
              if (uVar46 != 0) {
                uVar53 = uVar55 / uVar46;
              }
            }
            iVar23 = uVar53 + iVar23;
            puVar52 = (uint *)plVar28[6];
            uVar46 = *puVar52;
            lVar47 = 0x10;
            if (uVar46 <= uVar48) {
              lVar47 = 0x14;
            }
            uVar12 = *(ushort *)((long)puVar5 + lVar47);
            if (iVar23 < (int)(uint)uVar12) {
              uVar55 = puVar52[1];
              uVar53 = uVar55;
              if ((int)uVar46 <= (int)(uVar50 & 0xffff)) {
                uVar53 = -uVar46;
              }
              uVar53 = uVar53 + uVar50;
              uVar50 = uVar53 & 0xffff;
              if ((uVar53 & 0x80) != 0) {
                uVar50 = (uVar53 & 0xff7f) + uVar55;
              }
              if (uVar55 != 0) {
                uVar53 = 0;
                do {
                  if (uVar50 == *(byte *)(*(long *)(puVar52 + 4) + (long)(int)uVar53)) {
                    if (uVar53 != 0xff) goto LAB_00114e90;
                    break;
                  }
                  uVar53 = uVar53 + 1;
                } while (uVar55 != uVar53);
              }
              if (uVar46 != 0) {
                uVar53 = 0;
                do {
                  if (uVar50 == *(byte *)(*(long *)(puVar52 + 2) + (long)(int)uVar53)) {
                    uVar53 = uVar53 | 0x80;
                    goto LAB_00114e90;
                  }
                  uVar53 = uVar53 + 1;
                } while (uVar46 != uVar53);
              }
              _printk(&DAT_00127314,"map_die2pin",0x353);
              uVar53 = 0xff;
LAB_00114e90:
              uVar46 = uVar53 & 0xff;
              uVar50 = 0x7f;
              if ((short)uVar16 < 0) {
                uVar50 = 0xff;
              }
              if (uVar46 != uVar50) {
                bVar64 = *pbVar4;
                uVar49 = (ulong)bVar64;
                if (bVar64 < 0xf) {
                  puVar33 = (ushort *)((long)plVar28 + 0x168ac);
                  uVar59 = uVar49;
                  if (bVar64 == 0) {
                    uVar49 = 0;
                  }
                  else {
                    do {
                      bVar21 = uVar46 == (int)(short)puVar33[-1];
                      cVar36 = '\x01';
                      if (bVar21) {
                        cVar36 = '\x02';
                      }
                      if (puVar33[-1] != uVar50) {
                        cVar36 = bVar21;
                      }
                      cVar22 = *puVar33 == uVar50;
                      if (uVar46 == (int)(short)*puVar33) {
                        cVar22 = cVar22 + '\x01';
                      }
                      if (1 < (byte)(cVar22 + cVar36)) goto LAB_00114f60;
                      uVar59 = uVar59 - 1;
                      puVar33 = puVar33 + 4;
                    } while (uVar59 != 0);
                  }
                  *(short *)((long)plVar28 + uVar49 * 8 + 0x168aa) = (short)uVar46;
                  *(short *)((long)plVar28 + uVar49 * 8 + 0x168ac) = (short)uVar50;
                  *(ushort *)((long)plVar28 + uVar49 * 8 + 0x168ae) =
                       (ushort)((uint)iVar23 >> 8) & 0xff;
                  *(ushort *)(plVar28 + uVar49 + 0x2d16) = (ushort)iVar23 & 0xff;
                  if (bVar64 < 0xf) {
                    *pbVar4 = bVar64 + 1;
                  }
                }
              }
LAB_00114f60:
              puVar29 = &DAT_0011e566;
              if ((uVar53 & 0x80) != 0) {
                puVar29 = &DAT_001278b9;
              }
              puVar8 = &DAT_0011e56a;
              if ((short)uVar16 < 0) {
                puVar8 = &DAT_001218b2;
              }
              _printk(&DAT_00127352,"gdix_check_resistance_to_gnd",0x4ad,puVar29,uVar53 & 0x7f,
                      puVar8,(long)iVar23,uVar12);
              _printk(&DAT_00125194,"gdix_check_gndvdd_shortcircut",0x4da);
              local_780 = 0xffffffea;
            }
            uVar48 = uVar48 + 1;
          } while (uVar48 != uVar24);
        }
      }
      kfree(lVar41);
    }
    local_7c4 = local_780 | local_7c4;
  }
  _printk(&DAT_0011df39,"goodix_shortcircut_analysis",0x508,local_7c4);
  if ((int)local_7c4 < 0) {
LAB_001136fc:
    uVar37 = 2;
  }
  else {
LAB_001150e8:
    uVar37 = 1;
  }
  *(undefined1 *)((long)plVar28 + 0x196db) = uVar37;
LAB_0011190c:
  lVar41 = *plVar28;
  local_718 = 0;
  local_710 = 0;
  local_728 = 0;
  local_720 = 0;
  _printk(&DAT_001256f1,"goodix_put_test_result",0xaae);
  uVar67 = *(undefined4 *)((long)plVar28 + 0x24);
  uVar24 = 2;
  uVar46 = *(uint *)(plVar28 + 0x2334);
  puVar33 = (ushort *)(plVar28 + 0x1f65);
  *(short *)(param_2 + 1) = (short)plVar28[5];
  *(short *)((long)param_2 + 6) = (short)uVar67;
  *param_2 = 2;
  if (uVar46 != 0) {
    uVar48 = (ulong)uVar46 - 1;
    if (0xf3b < uVar48) {
      uVar48 = 0xf3c;
    }
    if (uVar48 < 2) {
      uVar49 = 0;
    }
    else {
      uVar49 = uVar48 + 1 & 1;
      uVar59 = 2;
      if (uVar49 != 0) {
        uVar59 = uVar49;
      }
      uVar49 = (uVar48 + 1) - uVar59;
      lVar47 = -1;
      puVar51 = (undefined2 *)((long)plVar28 + 0xfb2a);
      do {
        iVar23 = (int)lVar47;
        lVar47 = lVar47 + 2;
        uVar10 = *puVar51;
        *(undefined2 *)((long)param_2 + ((ulong)(iVar23 + 3) & 0xfffffffe) * 2 + 4) = puVar51[-1];
        *(undefined2 *)((long)param_2 + (ulong)(iVar23 + 4) * 2 + 4) = uVar10;
        puVar51 = puVar51 + 2;
      } while (uVar48 - uVar59 != lVar47);
    }
    do {
      if (uVar49 == 0xf3c) goto LAB_0011347c;
      iVar23 = (int)uVar49;
      puVar1 = puVar33 + uVar49;
      uVar49 = uVar49 + 1;
      *(ushort *)((long)param_2 + (ulong)(iVar23 + 2) * 2 + 4) = *puVar1;
    } while (uVar46 != uVar49);
    uVar24 = uVar46 + 2;
    *param_2 = uVar24;
  }
  uVar50 = *(uint *)(plVar28 + 0x2ad3);
  if (uVar50 != 0) {
    uVar48 = (ulong)uVar50 - 1;
    uVar53 = uVar24;
    if (uVar24 < 0x1b59) {
      uVar53 = 7000;
    }
    uVar49 = (ulong)((uVar53 - uVar46) - 2);
    if (uVar49 <= uVar48) {
      uVar48 = uVar49;
    }
    if (0xf3b < uVar48) {
      uVar48 = 0xf3c;
    }
    if (uVar48 < 2) {
      lVar54 = 0;
    }
    else {
      uVar49 = uVar48 + 1 & 1;
      puVar51 = (undefined2 *)((long)plVar28 + 0x13822);
      uVar59 = 2;
      if (uVar49 != 0) {
        uVar59 = uVar49;
      }
      lVar54 = (uVar48 + 1) - uVar59;
      lVar47 = ~uVar48 + uVar59;
      uVar53 = uVar46 + 3;
      do {
        uVar10 = *puVar51;
        uVar55 = uVar53 - 1;
        uVar17 = puVar51[-1];
        puVar51 = puVar51 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar53 * 2 + 4) = uVar10;
        lVar47 = lVar47 + 2;
        uVar53 = uVar53 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar55 * 2 + 4) = uVar17;
      } while (lVar47 != 0);
    }
    uVar53 = uVar46 + (int)lVar54 + 2;
    lVar47 = 0;
    do {
      if ((0xf3c - lVar54 == lVar47) || (0x36a < uVar53 + (int)lVar47 >> 3)) goto LAB_0011347c;
      lVar63 = lVar47 * 2;
      lVar47 = lVar47 + 1;
      *(undefined2 *)((long)param_2 + lVar63 + (ulong)uVar53 * 2 + 4) =
           *(undefined2 *)((long)plVar28 + lVar63 + lVar54 * 2 + 0x13820);
    } while ((ulong)uVar50 - lVar54 != lVar47);
    uVar24 = uVar50 + uVar24;
    *param_2 = uVar24;
  }
  uVar53 = *(uint *)((long)plVar28 + 0x168a4);
  if (uVar53 != 0) {
    uVar55 = uVar24;
    if (uVar24 < 0x1b59) {
      uVar55 = 7000;
    }
    uVar48 = (ulong)uVar53 - 1;
    uVar49 = (ulong)((uVar55 - (uVar46 + uVar50)) - 2);
    if (uVar49 <= uVar48) {
      uVar48 = uVar49;
    }
    if (0x7e < uVar48) {
      uVar48 = 0x7f;
    }
    if (uVar48 < 2) {
      lVar54 = 0;
    }
    else {
      uVar49 = uVar48 + 1 & 1;
      uVar59 = 2;
      if (uVar49 != 0) {
        uVar59 = uVar49;
      }
      lVar54 = (uVar48 + 1) - uVar59;
      lVar47 = ~uVar48 + uVar59;
      puVar51 = (undefined2 *)((long)plVar28 + 0x167a6);
      uVar55 = uVar24;
      do {
        uVar57 = uVar55 + 1;
        lVar47 = lVar47 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar55 * 2 + 4) = puVar51[-1];
        uVar55 = uVar55 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar57 * 2 + 4) = *puVar51;
        puVar51 = puVar51 + 2;
      } while (lVar47 != 0);
    }
    uVar55 = uVar46 + uVar50 + (int)lVar54 + 2;
    lVar47 = 0;
    do {
      if ((0x7f - lVar54 == lVar47) || (0x36a < uVar55 + (int)lVar47 >> 3)) goto LAB_0011347c;
      lVar63 = lVar47 * 2;
      lVar47 = lVar47 + 1;
      *(undefined2 *)((long)param_2 + lVar63 + (ulong)uVar55 * 2 + 4) =
           *(undefined2 *)((long)plVar28 + lVar63 + lVar54 * 2 + 0x167a4);
    } while ((ulong)uVar53 - lVar54 != lVar47);
    uVar24 = uVar53 + uVar24;
    *param_2 = uVar24;
  }
  puVar1 = (ushort *)(plVar28 + 0x2cd4);
  uVar55 = *(uint *)(plVar28 + 0x2cf4);
  if (uVar55 != 0) {
    uVar57 = uVar24;
    if (uVar24 < 0x1b59) {
      uVar57 = 7000;
    }
    uVar48 = (ulong)uVar55 - 1;
    uVar49 = (ulong)((uVar57 - (uVar46 + uVar50 + uVar53)) - 2);
    if (uVar49 <= uVar48) {
      uVar48 = uVar49;
    }
    if (0x7e < uVar48) {
      uVar48 = 0x7f;
    }
    if (uVar48 < 2) {
      uVar49 = 0;
    }
    else {
      uVar49 = uVar48 + 1 & 1;
      uVar59 = 2;
      if (uVar49 != 0) {
        uVar59 = uVar49;
      }
      uVar49 = (uVar48 + 1) - uVar59;
      lVar47 = ~uVar48 + uVar59;
      puVar51 = (undefined2 *)((long)plVar28 + 0x166a2);
      uVar57 = uVar24;
      do {
        uVar40 = uVar57 + 1;
        lVar47 = lVar47 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar57 * 2 + 4) = puVar51[-1];
        uVar57 = uVar57 + 2;
        *(undefined2 *)((long)param_2 + (ulong)uVar40 * 2 + 4) = *puVar51;
        puVar51 = puVar51 + 2;
      } while (lVar47 != 0);
    }
    lVar47 = (ulong)(uVar46 + uVar50 + uVar53 + (int)uVar49 + 2) + 2;
    do {
      if ((uVar49 == 0x7f) || (0x36a < (int)lVar47 - 2U >> 3)) goto LAB_0011347c;
      puVar2 = puVar1 + uVar49;
      uVar49 = uVar49 + 1;
      *(ushort *)((long)param_2 + lVar47 * 2) = *puVar2;
      lVar47 = lVar47 + 1;
    } while (uVar55 != uVar49);
    *param_2 = uVar55 + uVar24;
  }
  cVar36 = *(char *)((long)plVar28 + 0x196d6);
  if (cVar36 == '\x03') {
    bVar64 = 0;
    bVar21 = true;
  }
  else if (cVar36 == '\x02') {
    bVar21 = false;
    bVar64 = 1;
  }
  else {
    bVar64 = 0;
    bVar21 = false;
  }
  if (*pcVar43 == '\x03') {
    bVar21 = true;
  }
  else if (*pcVar43 == '\x02') {
    bVar64 = 1;
  }
  if ((char)plVar28[0x32db] == '\x03') {
    bVar21 = true;
  }
  else if ((char)plVar28[0x32db] == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196d9) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196d9) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196da) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196da) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196db) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196db) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196dc) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196dc) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196dd) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196dd) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196de) == '\x03') {
    bVar21 = true;
  }
  else if (*(char *)((long)plVar28 + 0x196de) == '\x02') {
    bVar64 = 1;
  }
  if (*(char *)((long)plVar28 + 0x196df) == '\x03') {
    bVar21 = true;
LAB_001121dc:
    _printk(&DAT_00128368,"goodix_put_test_result",0xad6);
LAB_001121f8:
    sVar30 = strnlen((char *)(plVar28 + 0x32dc),100);
    if (0x67 < sVar30) goto LAB_001150f0;
    pcVar65 = (char *)((long)(plVar28 + 0x32dc) + sVar30);
    sVar66 = 99 - sVar30;
    sVar31 = strlen(pcVar65);
    if (6 < sVar66) {
      sVar66 = 7;
    }
    lVar47 = sVar66 + sVar31;
    memcpy(pcVar65 + sVar31,"[FAIL]-",sVar66);
    if (lVar47 == -1) goto LAB_0011347c;
    if (0x19747 < sVar30 + 0x196e0 + lVar47) goto LAB_00113da0;
    pcVar65[lVar47] = '\0';
    if (!bVar21) goto LAB_001122c8;
    sVar30 = strnlen((char *)(plVar28 + 0x32dc),100);
    if (0x67 < sVar30) goto LAB_001150f0;
    pcVar65 = (char *)((long)(plVar28 + 0x32dc) + sVar30);
    sVar66 = 99 - sVar30;
    sVar31 = strlen(pcVar65);
    if (2 < sVar66) {
      sVar66 = 3;
    }
    puVar29 = &DAT_001278da;
  }
  else {
    if (*(char *)((long)plVar28 + 0x196df) == '\x02') goto LAB_001121dc;
    _printk(&DAT_00128368,"goodix_put_test_result",0xad6);
    if ((bool)(bVar21 | bVar64)) goto LAB_001121f8;
    sVar30 = strnlen((char *)(plVar28 + 0x32dc),100);
    if (0x67 < sVar30) goto LAB_001150f0;
    pcVar65 = (char *)((long)(plVar28 + 0x32dc) + sVar30);
    sVar66 = 99 - sVar30;
    sVar31 = strlen(pcVar65);
    if (6 < sVar66) {
      sVar66 = 7;
    }
    lVar47 = sVar66 + sVar31;
    memcpy(pcVar65 + sVar31,"[PASS]-",sVar66);
    if (lVar47 == -1) goto LAB_0011347c;
    if (0x19747 < sVar30 + 0x196e0 + lVar47) goto LAB_00113da0;
    pcVar65[lVar47] = '\0';
LAB_001122c8:
    sVar30 = strnlen((char *)(plVar28 + 0x32dc),100);
    if (0x67 < sVar30) goto LAB_001150f0;
    pcVar65 = (char *)((long)(plVar28 + 0x32dc) + sVar30);
    sVar66 = 99 - sVar30;
    sVar31 = strlen(pcVar65);
    if (2 < sVar66) {
      sVar66 = 3;
    }
    puVar29 = &DAT_00127f03;
  }
  lVar47 = sVar66 + sVar31;
  memcpy(pcVar65 + sVar31,puVar29,sVar66);
  if (lVar47 == -1) goto LAB_0011347c;
  if (0x19747 < sVar30 + 0x196e0 + lVar47) {
LAB_00113da0:
                    /* WARNING: Does not return */
    pcVar42 = (code *)SoftwareBreakpoint(1,0x113da4);
    (*pcVar42)();
  }
  pcVar65[lVar47] = '\0';
  cVar36 = *(char *)((long)plVar28 + 0x196d6);
  plVar3 = plVar28 + 0x32dc;
  if (cVar36 != '\0') {
    if (cVar36 == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,0,puVar29,100);
  }
  if (*pcVar43 != '\0') {
    if (*pcVar43 == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,1,puVar29,100);
  }
  if ((char)plVar28[0x32db] != '\0') {
    if ((char)plVar28[0x32db] == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,2,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196d9) != '\0') {
    if (*(char *)((long)plVar28 + 0x196d9) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,3,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196da) != '\0') {
    if (*(char *)((long)plVar28 + 0x196da) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,4,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196db) != '\0') {
    if (*(char *)((long)plVar28 + 0x196db) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,5,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196dc) != '\0') {
    if (*(char *)((long)plVar28 + 0x196dc) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,6,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196dd) != '\0') {
    if (*(char *)((long)plVar28 + 0x196dd) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,7,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196de) != '\0') {
    if (*(char *)((long)plVar28 + 0x196de) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,8,puVar29,100);
  }
  if (*(char *)((long)plVar28 + 0x196df) != '\0') {
    if (*(char *)((long)plVar28 + 0x196df) == '\x01') {
      puVar29 = &DAT_0012454b;
    }
    else {
      puVar29 = &DAT_0011d8cd;
    }
    goodix_strncatint(plVar3,9,puVar29,100);
  }
  uVar24 = *(uint *)(plVar28 + 0x2334);
  if (uVar24 == 0) {
    _printk(&DAT_00122242,"goodix_put_test_result",0xaf7);
    sVar30 = strnlen((char *)plVar3,100);
    if (0x67 < sVar30) goto LAB_001150f0;
    pcVar43 = (char *)((long)plVar3 + sVar30);
    sVar66 = 99 - sVar30;
    sVar31 = strlen(pcVar43);
    if (6 < sVar66) {
      sVar66 = 7;
    }
    lVar47 = sVar66 + sVar31;
    memcpy(pcVar43 + sVar31,"[0,0,0]",sVar66);
    if (lVar47 == -1) goto LAB_0011347c;
    uVar48 = sVar30 + 0x196e0 + lVar47;
    pcVar43 = pcVar43 + lVar47;
  }
  else {
    uVar46 = (uint)*puVar33;
    uVar48 = 0;
    lVar47 = 0;
    iVar23 = 1;
    uVar50 = uVar46;
    do {
      if ((uVar48 * 2 - 0x9c21 < 0xfffffffffffe68b7) || (uVar48 == 0x4e10)) goto LAB_00113da0;
      uVar16 = puVar33[uVar48];
      sVar14 = (short)uVar46;
      sVar15 = (short)uVar50;
      lVar47 = lVar47 + (short)uVar16;
      uVar53 = (uint)(short)uVar16;
      uVar46 = (int)sVar14;
      if ((int)sVar14 <= (int)(short)uVar16) {
        uVar46 = uVar53;
      }
      uVar50 = (int)sVar15;
      if ((int)uVar53 <= (int)sVar15) {
        uVar50 = uVar53;
      }
      uVar48 = (ulong)iVar23;
      iVar23 = iVar23 + 1;
    } while (uVar48 < uVar24);
    sVar14 = 0;
    if ((long)(int)uVar24 != 0) {
      sVar14 = (short)(lVar47 / (long)(int)uVar24);
    }
    local_718 = 0;
    local_710 = 0;
    local_728 = 0;
    local_720 = 0;
    snprintf((char *)&local_728,0x20,"[%d,%d,%d]",(int)sVar14,(int)(short)uVar46,(int)(short)uVar50)
    ;
    sVar30 = strnlen((char *)plVar3,100);
    if (0x67 < sVar30) goto LAB_001150f0;
    uVar48 = 99 - sVar30;
    sVar66 = uVar48;
    if (0x1f < uVar48) {
      sVar66 = 0x20;
    }
    sVar66 = strnlen((char *)&local_728,sVar66);
    if ((0x1f < sVar66) && (sVar66 != uVar48)) goto LAB_001150f0;
    pcVar43 = (char *)((long)plVar3 + sVar30);
    sVar31 = strlen(pcVar43);
    lVar47 = sVar66 + sVar31;
    memcpy(pcVar43 + sVar31,&local_728,sVar66);
    if (lVar47 == -1) goto LAB_0011347c;
    uVar48 = sVar30 + 0x196e0 + lVar47;
    pcVar43 = pcVar43 + lVar47;
  }
  if (0x19747 < uVar48) goto LAB_00113da0;
  *pcVar43 = '\0';
  if (*(char *)((long)plVar28 + 0xb) != '\0') {
    uVar24 = *(uint *)(plVar28 + 0x2ad3);
    if (uVar24 == 0) {
      _printk(&DAT_0011ef25,"goodix_put_test_result",0xb07);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar66 = 99 - sVar30;
      sVar31 = strlen(pcVar43);
      if (6 < sVar66) {
        sVar66 = 7;
      }
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,"[0,0,0]",sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      uVar48 = sVar30 + 0x196e0 + lVar47;
      pcVar43 = pcVar43 + lVar47;
    }
    else {
      uVar46 = (uint)*(ushort *)(plVar28 + 0x2704);
      uVar48 = 0;
      lVar47 = 0;
      iVar23 = 1;
      uVar50 = uVar46;
      do {
        if ((uVar48 * 2 - 0x5f29 < 0xfffffffffffe68b7) || (uVar48 == 0x2f94)) goto LAB_00113da0;
        uVar16 = *(ushort *)((long)(plVar28 + 0x2704) + uVar48 * 2);
        sVar14 = (short)uVar46;
        sVar15 = (short)uVar50;
        lVar47 = lVar47 + (short)uVar16;
        uVar53 = (uint)(short)uVar16;
        uVar46 = (int)sVar14;
        if ((int)sVar14 <= (int)(short)uVar16) {
          uVar46 = uVar53;
        }
        uVar50 = (int)sVar15;
        if ((int)uVar53 <= (int)sVar15) {
          uVar50 = uVar53;
        }
        uVar48 = (ulong)iVar23;
        iVar23 = iVar23 + 1;
      } while (uVar48 < uVar24);
      sVar14 = 0;
      if ((long)(int)uVar24 != 0) {
        sVar14 = (short)(lVar47 / (long)(int)uVar24);
      }
      local_718 = 0;
      local_710 = 0;
      local_728 = 0;
      local_720 = 0;
      snprintf((char *)&local_728,0x20,"[%d,%d,%d]",(int)sVar14,(int)(short)uVar46,
               (int)(short)uVar50);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      uVar48 = 99 - sVar30;
      sVar66 = uVar48;
      if (0x1f < uVar48) {
        sVar66 = 0x20;
      }
      sVar66 = strnlen((char *)&local_728,sVar66);
      if ((0x1f < sVar66) && (sVar66 != uVar48)) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar31 = strlen(pcVar43);
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,&local_728,sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      uVar48 = sVar30 + 0x196e0 + lVar47;
      pcVar43 = pcVar43 + lVar47;
    }
    if (0x19747 < uVar48) goto LAB_00113da0;
    *pcVar43 = '\0';
  }
  if (*(char *)((long)plVar28 + 0xe) != '\0') {
    uVar24 = *(uint *)(plVar28 + 0x2cf4);
    if (uVar24 == 0) {
      _printk(&DAT_00126835,"goodix_put_test_result",0xb18);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar66 = 99 - sVar30;
      sVar31 = strlen(pcVar43);
      if (6 < sVar66) {
        sVar66 = 7;
      }
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,"[0,0,0]",sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      uVar48 = sVar30 + 0x196e0 + lVar47;
      pcVar43 = pcVar43 + lVar47;
    }
    else {
      uVar46 = (uint)*puVar1;
      uVar48 = 0;
      lVar47 = 0;
      iVar23 = 1;
      uVar50 = uVar46;
      do {
        if ((uVar48 * 2 - 0x30a9 < 0xfffffffffffe68b7) || (uVar48 == 0x1854)) goto LAB_00113da0;
        uVar16 = puVar1[uVar48];
        sVar14 = (short)uVar46;
        sVar15 = (short)uVar50;
        lVar47 = lVar47 + (short)uVar16;
        uVar53 = (uint)(short)uVar16;
        uVar46 = (int)sVar14;
        if ((int)sVar14 <= (int)(short)uVar16) {
          uVar46 = uVar53;
        }
        uVar50 = (int)sVar15;
        if ((int)uVar53 <= (int)sVar15) {
          uVar50 = uVar53;
        }
        uVar48 = (ulong)iVar23;
        iVar23 = iVar23 + 1;
      } while (uVar48 < uVar24);
      sVar14 = 0;
      if ((long)(int)uVar24 != 0) {
        sVar14 = (short)(lVar47 / (long)(int)uVar24);
      }
      local_718 = 0;
      local_710 = 0;
      local_728 = 0;
      local_720 = 0;
      snprintf((char *)&local_728,0x20,"[%d,%d,%d]",(int)sVar14,(int)(short)uVar46,
               (int)(short)uVar50);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      uVar48 = 99 - sVar30;
      sVar66 = uVar48;
      if (0x1f < uVar48) {
        sVar66 = 0x20;
      }
      sVar66 = strnlen((char *)&local_728,sVar66);
      if ((0x1f < sVar66) && (sVar66 != uVar48)) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar31 = strlen(pcVar43);
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,&local_728,sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      uVar48 = sVar30 + 0x196e0 + lVar47;
      pcVar43 = pcVar43 + lVar47;
    }
    if (0x19747 < uVar48) goto LAB_00113da0;
    *pcVar43 = '\0';
  }
  if (*(char *)((long)plVar28 + 0xf) != '\0') {
    uVar24 = *(uint *)((long)plVar28 + 0x168a4);
    if (uVar24 == 0) {
      _printk(&DAT_0012838e,"goodix_put_test_result",0xb29);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar66 = 99 - sVar30;
      sVar31 = strlen(pcVar43);
      if (6 < sVar66) {
        sVar66 = 7;
      }
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,"[0,0,0]",sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      if (0x19747 < sVar30 + 0x196e0 + lVar47) goto LAB_00113da0;
      pcVar43 = pcVar43 + lVar47;
    }
    else {
      uVar46 = (uint)*(ushort *)((long)plVar28 + 0x167a4);
      uVar48 = 0;
      lVar47 = 0;
      iVar23 = 1;
      uVar50 = uVar46;
      do {
        if ((uVar48 * 2 - 0x2fa5 < 0xfffffffffffe68b7) || (uVar48 == 0x17d2)) goto LAB_00113da0;
        uVar16 = ((ushort *)((long)plVar28 + 0x167a4))[uVar48];
        sVar14 = (short)uVar46;
        sVar15 = (short)uVar50;
        lVar47 = lVar47 + (short)uVar16;
        uVar53 = (uint)(short)uVar16;
        uVar46 = (int)sVar14;
        if ((int)sVar14 <= (int)(short)uVar16) {
          uVar46 = uVar53;
        }
        uVar50 = (int)sVar15;
        if ((int)uVar53 <= (int)sVar15) {
          uVar50 = uVar53;
        }
        uVar48 = (ulong)iVar23;
        iVar23 = iVar23 + 1;
      } while (uVar48 < uVar24);
      sVar14 = 0;
      if ((long)(int)uVar24 != 0) {
        sVar14 = (short)(lVar47 / (long)(int)uVar24);
      }
      local_718 = 0;
      local_710 = 0;
      local_728 = 0;
      local_720 = 0;
      snprintf((char *)&local_728,0x20,"[%d,%d,%d]",(int)sVar14,(int)(short)uVar46,
               (int)(short)uVar50);
      sVar30 = strnlen((char *)plVar3,100);
      if (0x67 < sVar30) goto LAB_001150f0;
      uVar48 = 99 - sVar30;
      sVar66 = uVar48;
      if (0x1f < uVar48) {
        sVar66 = 0x20;
      }
      sVar66 = strnlen((char *)&local_728,sVar66);
      if ((0x1f < sVar66) && (sVar66 != uVar48)) goto LAB_001150f0;
      pcVar43 = (char *)((long)plVar3 + sVar30);
      sVar31 = strlen(pcVar43);
      lVar47 = sVar66 + sVar31;
      memcpy(pcVar43 + sVar31,&local_728,sVar66);
      if (lVar47 == -1) goto LAB_0011347c;
      if (0x19747 < sVar30 + 0x196e0 + lVar47) goto LAB_00113da0;
      pcVar43 = pcVar43 + lVar47;
    }
    *pcVar43 = '\0';
  }
  sVar30 = strnlen((char *)plVar3,100);
  if (0x67 < sVar30) goto LAB_001150f0;
  pcVar43 = (char *)((long)plVar3 + sVar30);
  sVar66 = 99 - sVar30;
  sVar31 = strlen(pcVar43);
  if (2 < sVar66) {
    sVar66 = 3;
  }
  lVar47 = sVar66 + sVar31;
  memcpy(pcVar43 + sVar31,&DAT_0011f4fc,sVar66);
  if (lVar47 == -1) {
LAB_0011347c:
                    /* WARNING: Does not return */
    pcVar42 = (code *)SoftwareBreakpoint(0x5512,0x113480);
    (*pcVar42)();
  }
  if (0x19747 < sVar30 + 0x196e0 + lVar47) goto LAB_00113da0;
  pcVar43[lVar47] = '\0';
  sVar30 = strnlen((char *)plVar3,100);
  if (0x67 < sVar30) {
LAB_001150f0:
                    /* WARNING: Subroutine does not return */
    fortify_panic("strnlen");
  }
  strncat((char *)((long)plVar3 + sVar30),(char *)(lVar41 + 0x1a),99 - sVar30);
  sVar30 = strnlen((char *)plVar3,100);
  if (0x67 < sVar30) goto LAB_001150f0;
  pcVar43 = (char *)((long)plVar3 + sVar30);
  uVar48 = 99 - sVar30;
  sVar66 = strlen(pcVar43);
  if (1 < uVar48) {
    uVar48 = 2;
  }
  sVar31 = sVar66;
  if (uVar48 != 0) {
    sVar31 = sVar66 + 1;
  }
  memcpy(pcVar43 + sVar66,&DAT_00125dde,(ulong)(uVar48 != 0));
  if (sVar31 == 0xffffffffffffffff) goto LAB_0011347c;
  if (0x19747 < sVar30 + 0x196e0 + sVar31) goto LAB_00113da0;
  pcVar43[sVar31] = '\0';
  strncpy((char *)(param_2 + 0xdad),(char *)plVar3,99);
  _printk(&DAT_001251c4,"goodix_tptest_finish",0x2f4);
  pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x28);
  if (*(int *)(pcVar42 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
    pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x112dbc);
    (*pcVar42)();
  }
  (*pcVar42)(*plVar28,100);
  if (0 < *(int *)((long)plVar28 + 0x1569c)) {
    lVar41 = *plVar28;
    piVar44 = *(int **)(lVar41 + 0x430);
    if ((piVar44 == (int *)0x0) || (*piVar44 < 1)) {
      _printk(&DAT_0011ef63,"ts_test_send_config",0x189);
    }
    else {
      pcVar42 = *(code **)(*(long *)(lVar41 + 0x2d0) + 0x50);
      if (*(int *)(pcVar42 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
        pcVar42 = (code *)SoftwareBreakpoint(0x8229,0x112e0c);
        (*pcVar42)();
      }
      iVar23 = (*pcVar42)(lVar41,piVar44 + 1);
      if (iVar23 == 0) goto LAB_00112e14;
    }
    _printk(&DAT_00120cf8,"goodix_tptest_finish",0x2fa);
  }
LAB_00112e14:
  goodix_ts_blocking_notify(6,0);
  pcVar42 = *(code **)(*(long *)(*plVar28 + 0x2d0) + 0x30);
  if (*(int *)(pcVar42 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
    pcVar42 = (code *)SoftwareBreakpoint(0x8228,0x112e48);
    (*pcVar42)();
  }
  (*pcVar42)(*plVar28,1);
LAB_00111310:
  kfree(plVar28);
LAB_00111318:
  lVar41 = sp_el0;
  if (*(long *)(lVar41 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// parse_csvfile @ 001151c4 size=1088
// signature: undefined parse_csvfile(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

int parse_csvfile(char *param_1,ulong param_2,char *param_3,long param_4,int param_5)

{
  ulong uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  char *pcVar5;
  size_t sVar6;
  void *__src;
  undefined *puVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  byte *pbVar14;
  long lVar15;
  int iVar16;
  byte *pbVar17;
  byte *pbVar18;
  undefined8 local_78;
  byte *local_70;
  long local_68;
  
  lVar15 = sp_el0;
  local_68 = *(long *)(lVar15 + 0x638);
  if ((int)param_2 < 1) {
    _printk(&DAT_00126751,"parse_csvfile",0x21f,0,param_2 & 0xffffffff);
    iVar16 = -6;
    goto LAB_00115574;
  }
  pcVar5 = strstr(param_1,param_3);
  if (pcVar5 == (char *)0x0) {
    puVar7 = &DAT_0012103d;
    uVar8 = 0x20e;
  }
  else {
    pbVar18 = (byte *)(pcVar5 + 1);
    do {
      pbVar17 = pbVar18 + 1;
      bVar2 = *pbVar18;
      if (bVar2 == 0) break;
      pbVar18 = pbVar17;
    } while (bVar2 != 10);
    if ((pbVar18 == (byte *)0x0) || (*pbVar18 == 0)) {
      _printk(&DAT_00125af4,"parse_csvfile",0x214,param_3);
      iVar16 = -5;
      goto LAB_00115574;
    }
    if (param_4 != 0) {
      local_70 = (byte *)0x0;
      local_78 = 0;
      pbVar17 = (byte *)kmalloc_large(0x5400,0xdc0);
      if (pbVar17 == (byte *)0x0) {
        _printk(&DAT_00125b1a,"parse_valid_data",0x1e2,0x5400);
        iVar16 = -0xc;
      }
      else if (param_5 < 1) {
        iVar16 = 0;
LAB_001154c0:
        kfree(pbVar17);
      }
      else {
        iVar11 = 0;
        iVar16 = 0;
        do {
          memset(pbVar17,0,0x5400);
          uVar12 = (uint)*pbVar18;
          uVar10 = 0;
          do {
            if ((uVar10 == 0x5400) || (uVar10 == 0x5400)) goto LAB_001155d8;
            pbVar17[uVar10] = (byte)uVar12;
            uVar1 = uVar10 + 1;
            uVar12 = (uint)pbVar18[uVar10 + 1];
            uVar10 = uVar1;
          } while ((0xd < uVar12) || ((1 << (ulong)(uVar12 & 0x1f) & 0x2401U) == 0));
          if (0x53ff < uVar1) {
LAB_001155d8:
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(1,0x1155dc);
            (*pcVar3)();
          }
          pbVar17[uVar1] = 0;
          sVar6 = strnlen((char *)pbVar17,0x5400);
          if (0x5400 < sVar6) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("strnlen");
          }
          if (sVar6 == 0x5400) {
                    /* WARNING: Subroutine does not return */
            fortify_panic("__fortify_strlen");
          }
          uVar12 = (int)sVar6 + 5;
          __src = (void *)__kmalloc(uVar12,0xdc0);
          if (__src == (void *)0x0) {
            _printk(&DAT_00127d92,"getrid_space",0x1b8);
          }
          else {
            uVar10 = 0;
            if ((int)sVar6 == 0) {
              uVar13 = 1;
            }
            else {
              lVar15 = 0x5400;
              pbVar14 = pbVar17;
              do {
                if (lVar15 == 0) goto LAB_001155d8;
                bVar2 = *pbVar14;
                if ((0x20 < bVar2) || ((1L << ((ulong)bVar2 & 0x3f) & 0x100002400U) == 0)) {
                  if (uVar12 <= (uint)uVar10) goto LAB_001155d8;
                  *(byte *)((long)__src + uVar10) = bVar2;
                  uVar10 = (ulong)((uint)uVar10 + 1);
                }
                lVar15 = lVar15 + -1;
                sVar6 = sVar6 - 1;
                pbVar14 = pbVar14 + 1;
              } while (sVar6 != 0);
              uVar9 = (uint)uVar10;
              if ((uVar12 <= uVar9) || (uVar13 = uVar9 + 1, uVar12 <= uVar9)) goto LAB_001155d8;
            }
            *(undefined1 *)((long)__src + uVar10) = 0;
            if (0x5400 < uVar13) {
                    /* WARNING: Subroutine does not return */
              fortify_panic("memcpy");
            }
            memcpy(pbVar17,__src,(ulong)uVar13);
            kfree(__src);
          }
          local_70 = pbVar17;
          pcVar5 = strsep((char **)&local_70,",");
          while (pcVar5 != (char *)0x0) {
            iVar4 = iVar16;
            if (*pcVar5 != '\0') {
              iVar4 = kstrtoll(pcVar5,0,&local_78);
              if (iVar4 != 0) {
                kfree(pbVar17);
                iVar16 = -0x16;
                goto LAB_00115574;
              }
              iVar4 = iVar16 + 1;
              *(int *)(param_4 + (long)iVar16 * 4) = (int)local_78;
            }
            pcVar5 = strsep((char **)&local_70,",");
            iVar16 = iVar4;
          }
          if (iVar11 == param_5 + -1) goto LAB_001154c0;
          pbVar14 = pbVar18 + 1;
          do {
            pbVar18 = pbVar14 + 1;
            bVar2 = *pbVar14;
            if (bVar2 == 0) {
              pbVar18 = pbVar14;
              break;
            }
            pbVar14 = pbVar18;
          } while (bVar2 != 10);
        } while (((pbVar18 != (byte *)0x0) && (pbVar18 < param_1 + param_2)) &&
                (iVar11 = iVar11 + 1, *pbVar18 != 0));
        _printk(&DAT_00126779,"parse_valid_data",0x1f8);
        kfree(pbVar17);
        iVar16 = -1;
      }
      goto LAB_00115574;
    }
    puVar7 = &DAT_0011d889;
    uVar8 = 0x21b;
  }
  _printk(puVar7,"parse_csvfile",uVar8,param_3);
  iVar16 = -4;
LAB_00115574:
  lVar15 = sp_el0;
  if (*(long *)(lVar15 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar16;
}



//------------------------------------------------------------
// goodix_analysis_self_rawdata @ 00115604 size=160
// signature: undefined goodix_analysis_self_rawdata(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

undefined8 goodix_analysis_self_rawdata(long param_1)

{
  short sVar1;
  code *pcVar2;
  long lVar3;
  int *piVar4;
  
  if (*(uint *)(param_1 + 0x167a0) != 0) {
    lVar3 = 0;
    piVar4 = (int *)(param_1 + 0xf708);
    do {
      if (lVar3 == 0xfe) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1156a4);
        (*pcVar2)();
      }
      sVar1 = *(short *)(param_1 + 0x166a0 + lVar3);
      if (((int)sVar1 < piVar4[0x7f]) || (*piVar4 < (int)sVar1)) {
        _printk(&DAT_0012006b,"goodix_analysis_self_rawdata",0x70d,(long)sVar1,piVar4[0x7f],*piVar4)
        ;
        return 0xffffffea;
      }
      piVar4 = piVar4 + 1;
      lVar3 = lVar3 + 2;
    } while ((ulong)*(uint *)(param_1 + 0x167a0) * 2 != lVar3);
  }
  return 0;
}



//------------------------------------------------------------
// goodix_analysis_noisedata @ 001156a4 size=140
// signature: undefined goodix_analysis_noisedata(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

undefined8 goodix_analysis_noisedata(long param_1)

{
  uint uVar1;
  bool bVar2;
  code *pcVar3;
  short *psVar4;
  ulong uVar5;
  
  uVar1 = *(uint *)(param_1 + 0x15698);
  uVar5 = (ulong)uVar1;
  if (uVar1 != 0) {
    bVar2 = false;
    psVar4 = (short *)(param_1 + 0x13820);
    do {
      if (uVar1 - 0xf3d < 0xfffff0c4) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x115730);
        (*pcVar3)();
      }
      uVar5 = uVar5 - 1;
      bVar2 = (bool)(*(int *)(param_1 + 0xfb00) < (int)*psVar4 | bVar2);
      psVar4 = psVar4 + 1;
    } while (uVar5 != 0);
    if (bVar2) {
      _printk(&DAT_00126cad,"goodix_analysis_noisedata",0x72b,1);
      return 0xffffffea;
    }
  }
  return 0;
}



//------------------------------------------------------------
// goodix_analysis_self_noisedata @ 00115730 size=140
// signature: undefined goodix_analysis_self_noisedata(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

undefined8 goodix_analysis_self_noisedata(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (*(uint *)(param_1 + 0x168a4) != 0) {
    lVar2 = 0;
    do {
      if (lVar2 == 0xfe) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1157bc);
        (*pcVar1)();
      }
      if (*(int *)(param_1 + 0xfb04) < (int)*(short *)(param_1 + 0x167a4 + lVar2)) {
        _printk(&DAT_00127e89,"goodix_analysis_self_noisedata",0x73e);
        return 0xffffffea;
      }
      lVar2 = lVar2 + 2;
    } while ((ulong)*(uint *)(param_1 + 0x168a4) * 2 != lVar2);
  }
  return 0;
}



//------------------------------------------------------------
// goodix_tools_init @ 001157c0 size=280
// signature: undefined goodix_tools_init(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int goodix_tools_init(void)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  undefined8 uVar4;
  
  lVar2 = kmalloc_trace(___stack_chk_fail,0xdc0,0x150);
  goodix_tools_dev = lVar2;
  if (lVar2 == 0) {
    _printk(&DAT_001231cc,"goodix_tools_init",0x1d9);
    iVar1 = -0xc;
  }
  else {
    *(long *)(lVar2 + 8) = lVar2 + 8;
    *(long *)(lVar2 + 0x10) = lVar2 + 8;
    *(undefined4 *)(lVar2 + 0x18) = 4;
    __init_waitqueue_head(lVar2 + 0x40,"&goodix_tools_dev->wq",&goodix_tools_init___key);
    __mutex_init(goodix_tools_dev + 0x58,"&goodix_tools_dev->mutex",&goodix_tools_init___key_2);
    lVar2 = goodix_tools_dev;
    *(undefined4 *)(goodix_tools_dev + 0x88) = 0;
    *(undefined ***)(lVar2 + 0xb0) = &goodix_tools_module_funcs;
    *(long *)(lVar2 + 0xb8) = lVar2;
    *(char **)(lVar2 + 0xa0) = "gtp_tools";
    *(undefined4 *)(lVar2 + 0xa8) = 4;
    iVar1 = misc_register(goodix_tools_miscdev);
    if (iVar1 == 0) {
      puVar3 = &DAT_0011ea0f;
      uVar4 = 0x1ed;
    }
    else {
      puVar3 = &DAT_001283bd;
      uVar4 = 0x1eb;
    }
    _printk(puVar3,"goodix_tools_init",uVar4);
  }
  return iVar1;
}



//------------------------------------------------------------
// goodix_tools_exit @ 001158dc size=72
// signature: undefined goodix_tools_exit(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

void goodix_tools_exit(void)

{
  misc_deregister(goodix_tools_miscdev);
  kfree(goodix_tools_dev);
  _printk(&DAT_00124c66,"goodix_tools_exit",0x1f6);
  return;
}



//------------------------------------------------------------
// goodix_tools_module_init @ 00115928 size=28
// signature: undefined goodix_tools_module_init(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_tools_module_init(long param_1,long param_2)

{
  if (param_1 == 0) {
    return 0xffffffed;
  }
  **(long **)(param_2 + 0x28) = param_1;
  return 0;
}



//------------------------------------------------------------
// goodix_tools_module_exit @ 00115948 size=124
// signature: undefined goodix_tools_module_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_tools_module_exit(undefined8 param_1,long param_2)

{
  int iVar1;
  undefined8 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_2 + 0x28);
  if (debug_log_flag == '\0') {
    iVar1 = *(int *)(lVar3 + 0x88);
  }
  else {
    _printk(&DAT_00122b3a,"goodix_tools_module_exit",0x1b1);
    iVar1 = *(int *)(lVar3 + 0x88);
  }
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    _printk(&DAT_00121ce1,"goodix_tools_module_exit",0x1b3);
    uVar2 = 0xfffffff0;
  }
  return uVar2;
}



//------------------------------------------------------------
// goodix_tools_ioctl @ 001159c8 size=3636
// signature: undefined goodix_tools_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void goodix_tools_ioctl(long param_1,uint param_2,ulong param_3)

{
  uint *puVar1;
  ulong uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  size_t sVar7;
  uint *puVar8;
  undefined8 uVar9;
  long lVar10;
  ulong uVar11;
  undefined *puVar12;
  ulong uVar13;
  undefined8 *puVar14;
  ulong uVar15;
  long lVar16;
  ulong uVar17;
  long *plVar18;
  long lVar19;
  undefined8 local_70;
  undefined8 uStack_68;
  undefined4 local_60;
  undefined1 auStack_5c [4];
  long local_58;
  
  lVar16 = sp_el0;
  local_58 = *(long *)(lVar16 + 0x638);
  plVar18 = *(long **)(param_1 + 0xd8);
  lVar16 = *plVar18;
  if (lVar16 == 0) {
    _printk(&DAT_00120d26,"goodix_tools_ioctl",0x10d);
    lVar16 = -0x16;
    goto LAB_001165ec;
  }
  if ((param_2 >> 8 & 0xff) != 0x47) {
    _printk(&DAT_00127f1c,"goodix_tools_ioctl",0x114);
    lVar16 = -0x19;
    goto LAB_001165ec;
  }
  lVar19 = *(long *)(lVar16 + 0x2d0);
  param_2 = param_2 & 0xc000ffff;
  uVar6 = (uint)_cpu_hwcaps;
  if ((int)param_2 < 0x4701) {
    if ((int)param_2 < -0x7fffb8f7) {
      if (param_2 == 0x80004704) {
        local_60 = 0;
        puVar14 = (undefined8 *)sp_el0;
        local_70 = 0;
        uStack_68 = 0;
        lVar16 = *(long *)(*plVar18 + 0x2d0);
        if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
          uVar13 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar13 < 0x7fffffffed) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar17 = daif;
              daif = uVar17 | 0xc0;
            }
            uVar17 = ttbr1_el1;
            ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar17 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar14[1];
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          sVar7 = __arch_copy_from_user(&local_70,param_3 & 0xff7fffffffffffff,0x14);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar17 = daif;
              daif = uVar17 | 0xc0;
            }
            uVar17 = ttbr1_el1;
            ttbr0_el1 = (uVar17 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar17 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          if (sVar7 != 0) goto LAB_00116644;
LAB_00115d40:
          uVar13 = local_70;
          uVar6 = local_70._4_4_;
          uVar17 = (ulong)local_70._4_4_;
          if (0x4000 < local_70._4_4_) {
            _printk(&DAT_00124562,"async_read",0x61,local_70._4_4_,0x4000);
            uVar6 = 0xffffffea;
            goto LAB_00116390;
          }
          puVar8 = (uint *)__kmalloc(uVar17,0xdc0);
          if (puVar8 == (uint *)0x0) {
            _printk(&DAT_00127394,"async_read",0x66);
            uVar6 = 0xfffffff4;
            goto LAB_00116390;
          }
          pcVar3 = *(code **)(lVar16 + 0x38);
          if (*(int *)(pcVar3 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x115d90);
            (*pcVar3)();
          }
          iVar4 = (*pcVar3)(*plVar18,uVar13 & 0xffffffff,puVar8,uVar6);
          if (iVar4 != 0) {
            _printk(&DAT_0011df88,"async_read",0x6c);
            uVar6 = 0xfffffff0;
LAB_00116388:
            kfree(puVar8);
            goto LAB_00116390;
          }
          param_3 = param_3 + 0x14;
          __check_object_size(puVar8,uVar17,1);
          if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
             (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
            uVar13 = param_3 & (long)(param_3 * 0x100) >> 8;
          }
          uVar5 = uVar6;
          if (uVar13 <= 0x8000000000 - uVar17) {
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar13 = daif;
              if ((uVar13 & 0x80) == 0) {
                uVar15 = daif;
                daif = uVar15 | 0xc0;
              }
              uVar15 = ttbr1_el1;
              ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar15 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              ttbr0_el1 = puVar14[1];
              InstructionSynchronizationBarrier();
              daif = uVar13;
            }
            uVar5 = __arch_copy_to_user(param_3 & 0xff7fffffffffffff,puVar8,uVar17);
            if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
              uVar13 = daif;
              if ((uVar13 & 0x80) == 0) {
                uVar17 = daif;
                daif = uVar17 | 0xc0;
              }
              uVar17 = ttbr1_el1;
              ttbr0_el1 = (uVar17 & 0xffffffffffff) - 0x1000;
              InstructionSynchronizationBarrier();
              ttbr1_el1 = uVar17 & 0xffffffffffff;
              InstructionSynchronizationBarrier();
              daif = uVar13;
            }
          }
          if (uVar5 != 0) {
            _printk(&DAT_0011efa7,"async_read",0x72);
            uVar6 = 0xfffffff2;
            goto LAB_00116388;
          }
          goto LAB_00115e74;
        }
        sVar7 = 0x14;
LAB_00116644:
        memset(auStack_5c + -sVar7,0,sVar7);
        if ((int)sVar7 == 0) goto LAB_00115d40;
        uVar6 = 0xfffffff2;
LAB_00116390:
        _printk(&DAT_001283f5,"goodix_tools_ioctl",0x159);
      }
      else {
        if (param_2 != 0x80004705) goto switchD_00115a4c_caseD_40004704;
        puVar12 = &DAT_0012254d;
        uVar9 = 0x15c;
LAB_0011659c:
        _printk(puVar12,"goodix_tools_ioctl",uVar9);
        uVar6 = 0;
      }
    }
    else {
      if (param_2 != 0x80004709) {
        if (param_2 == 0x4700) {
          if (param_3 == 0) {
            if (*(int *)(*(code **)(lVar19 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x116564);
              (*pcVar3)();
            }
            (**(code **)(lVar19 + 0x30))(lVar16,0);
            mutex_lock(plVar18 + 0xb);
            *(uint *)(plVar18 + 3) = *(uint *)(plVar18 + 3) & 0xfffffffb;
            mutex_unlock(plVar18 + 0xb);
            puVar12 = &DAT_00127f41;
            uVar9 = 0x125;
          }
          else {
            if (param_3 != 1) {
              _printk(&DAT_00120799,"goodix_tools_ioctl",0x127,param_3);
              uVar6 = 0;
              goto LAB_001165e8;
            }
            if (*(int *)(*(code **)(lVar19 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x116288);
              (*pcVar3)();
            }
            (**(code **)(lVar19 + 0x30))(lVar16,1);
            mutex_lock(plVar18 + 0xb);
            *(uint *)(plVar18 + 3) = *(uint *)(plVar18 + 3) | 4;
            mutex_unlock(plVar18 + 0xb);
            puVar12 = &DAT_00126862;
            uVar9 = 0x11f;
          }
          goto LAB_0011659c;
        }
        goto switchD_00115a4c_caseD_40004704;
      }
      puVar14 = (undefined8 *)sp_el0;
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 < 0x7fffffffff) {
        if ((uVar6 >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar17 = daif;
            daif = uVar17 | 0xc0;
          }
          puVar14 = (undefined8 *)puVar14[1];
          uVar17 = ttbr1_el1;
          ttbr1_el1 = (ulong)puVar14 & 0xffff000000000000 | uVar17 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        uVar6 = __arch_copy_to_user(puVar14,param_3 & 0xff7fffffffffffff,&goodix_tools_ver,2);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar17 = daif;
            daif = uVar17 | 0xc0;
          }
          uVar17 = ttbr1_el1;
          ttbr0_el1 = (uVar17 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar17 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        if (uVar6 == 0) goto LAB_001165e8;
      }
      else {
        uVar6 = 2;
      }
      _printk(&DAT_00121d23,"goodix_tools_ioctl",0x167);
    }
  }
  else {
    switch(param_2) {
    case 0x40004702:
      _printk(&DAT_00126d1c,"goodix_tools_ioctl",0x136);
      uVar6 = 0xffffffea;
      break;
    case 0x40004703:
      puVar8 = (uint *)kmalloc_trace(_queue_work_on,0xdc0,0x1004);
      if (puVar8 == (uint *)0x0) {
        _printk(&DAT_001231cc,"goodix_tools_ioctl",0x13c);
        uVar6 = 0xfffffff4;
      }
      else {
        puVar14 = (undefined8 *)sp_el0;
        local_60 = 0;
        local_70 = 0;
        uStack_68 = 0;
        if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
           (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
          uVar13 = param_3 & (long)(param_3 << 8) >> 8;
        }
        if (uVar13 < 0x7fffffffed) {
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar17 = daif;
              daif = uVar17 | 0xc0;
            }
            uVar17 = ttbr1_el1;
            ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar17 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            ttbr0_el1 = puVar14[1];
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          sVar7 = __arch_copy_from_user(&local_70,param_3 & 0xff7fffffffffffff,0x14);
          if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
            uVar13 = daif;
            if ((uVar13 & 0x80) == 0) {
              uVar17 = daif;
              daif = uVar17 | 0xc0;
            }
            uVar17 = ttbr1_el1;
            ttbr0_el1 = (uVar17 & 0xffffffffffff) - 0x1000;
            InstructionSynchronizationBarrier();
            ttbr1_el1 = uVar17 & 0xffffffffffff;
            InstructionSynchronizationBarrier();
            daif = uVar13;
          }
          if (sVar7 != 0) goto LAB_001166ac;
LAB_00115b40:
          uVar6 = local_70._4_4_;
          uVar13 = (ulong)local_70._4_4_;
          if (local_70._4_4_ < 0x1001) {
            puVar1 = puVar8 + 1;
            param_3 = param_3 + 0x14;
            __check_object_size(puVar1,uVar13,0);
            if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
               (uVar17 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
              uVar17 = param_3 & (long)(param_3 * 0x100) >> 8;
            }
            uVar15 = uVar13;
            if (uVar17 <= 0x8000000000 - uVar13) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar17 = daif;
                if ((uVar17 & 0x80) == 0) {
                  uVar15 = daif;
                  daif = uVar15 | 0xc0;
                }
                uVar15 = ttbr1_el1;
                ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar15 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar14[1];
                InstructionSynchronizationBarrier();
                daif = uVar17;
              }
              uVar15 = __arch_copy_from_user(puVar1,param_3 & 0xff7fffffffffffff,uVar13);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar17 = daif;
                if ((uVar17 & 0x80) == 0) {
                  uVar11 = daif;
                  daif = uVar11 | 0xc0;
                }
                uVar11 = ttbr1_el1;
                ttbr0_el1 = (uVar11 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar11 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar17;
              }
            }
            if ((uVar15 != 0) &&
               (memset((void *)((long)puVar1 + (uVar13 - uVar15)),0,uVar15), (int)uVar15 != 0)) {
              uVar9 = 0xf4;
              goto LAB_0011670c;
            }
            *puVar8 = uVar6;
            pcVar3 = *(code **)(lVar19 + 0x50);
            if (pcVar3 != (code *)0x0) {
              if (*(int *)(pcVar3 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1164dc);
                (*pcVar3)();
              }
              iVar4 = (*pcVar3)(lVar16,puVar1,uVar6);
              if (iVar4 != 0) {
                _printk(&DAT_001218c8,"goodix_tools_ioctl",0x145);
                uVar6 = 0xfffffff5;
                goto LAB_00115e74;
              }
              _printk(&DAT_00125718,"goodix_tools_ioctl",0x148);
            }
            uVar6 = 0;
          }
          else {
            _printk(&DAT_00124562,"init_cfg_data",0xef,local_70._4_4_,0x4000);
            uVar6 = 0xffffffea;
          }
        }
        else {
          sVar7 = 0x14;
LAB_001166ac:
          memset(auStack_5c + -sVar7,0,sVar7);
          if ((int)sVar7 == 0) goto LAB_00115b40;
          uVar9 = 0xe8;
LAB_0011670c:
          _printk(&DAT_001207cc,"init_cfg_data",uVar9);
          uVar6 = 0xfffffff2;
        }
LAB_00115e74:
        kfree(puVar8);
      }
      break;
    case 0x40004704:
    case 0x40004705:
    case 0x40004708:
    case 0x40004709:
switchD_00115a4c_caseD_40004704:
      _printk(&DAT_00122575,"goodix_tools_ioctl",0x16e);
      uVar6 = 0xffffffe7;
      break;
    case 0x40004706:
      local_60 = 0;
      puVar14 = (undefined8 *)sp_el0;
      local_70 = 0;
      uStack_68 = 0;
      lVar16 = *plVar18;
      lVar19 = *(long *)(lVar16 + 0x2d0);
      if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
         (uVar13 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
        uVar13 = param_3 & (long)(param_3 << 8) >> 8;
      }
      if (uVar13 < 0x7fffffffed) {
        if ((uVar6 >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar17 = daif;
            daif = uVar17 | 0xc0;
          }
          uVar17 = ttbr1_el1;
          ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar17 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar14[1];
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        sVar7 = __arch_copy_from_user(&local_70,param_3 & 0xff7fffffffffffff,0x14);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar13 = daif;
          if ((uVar13 & 0x80) == 0) {
            uVar17 = daif;
            daif = uVar17 | 0xc0;
          }
          uVar17 = ttbr1_el1;
          ttbr0_el1 = (uVar17 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar17 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar13;
        }
        if (sVar7 != 0) goto LAB_0011666c;
LAB_00116060:
        uVar13 = local_70;
        uVar6 = local_70._4_4_;
        uVar17 = (ulong)local_70._4_4_;
        if (local_70._4_4_ < 0x4001) {
          lVar10 = __kmalloc(uVar17,0xdc0);
          if (lVar10 == 0) {
            _printk(&DAT_00127394,"async_write",0xca);
            uVar6 = 0xfffffff4;
          }
          else {
            __check_object_size(lVar10,uVar17,0);
            param_3 = param_3 + 0x14;
            if (((*(byte *)((long)puVar14 + 0x46) >> 5 & 1) != 0) ||
               (uVar15 = param_3, ((uint)*puVar14 >> 0x1a & 1) != 0)) {
              uVar15 = param_3 & (long)(param_3 * 0x100) >> 8;
            }
            uVar11 = uVar17;
            if (uVar15 <= 0x8000000000 - uVar17) {
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar11 = daif;
                  daif = uVar11 | 0xc0;
                }
                uVar11 = ttbr1_el1;
                ttbr1_el1 = puVar14[1] & 0xffff000000000000 | uVar11 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                ttbr0_el1 = puVar14[1];
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
              uVar11 = __arch_copy_from_user(lVar10,param_3 & 0xff7fffffffffffff,uVar17);
              if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
                uVar15 = daif;
                if ((uVar15 & 0x80) == 0) {
                  uVar2 = daif;
                  daif = uVar2 | 0xc0;
                }
                uVar2 = ttbr1_el1;
                ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
                InstructionSynchronizationBarrier();
                ttbr1_el1 = uVar2 & 0xffffffffffff;
                InstructionSynchronizationBarrier();
                daif = uVar15;
              }
            }
            if ((uVar11 == 0) ||
               (memset((void *)(lVar10 + (uVar17 - uVar11)),0,uVar11), (int)uVar11 == 0)) {
              pcVar3 = *(code **)(lVar19 + 0x40);
              if (*(int *)(pcVar3 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
                pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x11618c);
                (*pcVar3)();
              }
              iVar4 = (*pcVar3)(lVar16,uVar13 & 0xffffffff,lVar10,uVar6);
              if (iVar4 == 0) {
                kfree(lVar10);
                break;
              }
              _printk(&DAT_00126d5f,"async_write",0xd6);
              uVar6 = 0xfffffff0;
            }
            else {
              _printk(&DAT_001207cc,"async_write",0xd0);
              uVar6 = 0xfffffff2;
            }
            kfree(lVar10);
          }
        }
        else {
          _printk(&DAT_00124562,"async_write",0xc4,local_70._4_4_,0x4000);
          uVar6 = 0xffffffea;
        }
      }
      else {
        sVar7 = 0x14;
LAB_0011666c:
        memset(auStack_5c + -sVar7,0,sVar7);
        if ((int)sVar7 == 0) goto LAB_00116060;
        _printk(&DAT_001207cc,"async_write",0xbc);
        uVar6 = 0xfffffff2;
      }
      _printk(&DAT_0011d8d2,"goodix_tools_ioctl",0x161);
      break;
    case 0x40004707:
      uVar6 = read_config_data(lVar16,param_3);
      if ((int)uVar6 < 1) {
        puVar12 = &DAT_001218ef;
        uVar9 = 0x154;
      }
      else {
        puVar12 = &DAT_00124c93;
        uVar9 = 0x152;
      }
      _printk(puVar12,"goodix_tools_ioctl",uVar9,uVar6);
      break;
    case 0x4000470a:
      *(bool *)(lVar16 + 0x4d8) = param_3 != 0;
      _printk(&DAT_0011ea48,"goodix_tools_ioctl",0x16b);
      uVar6 = 0;
      break;
    default:
      if (param_2 == 0x4701) {
        if (*(int *)(*(code **)(lVar19 + 0x28) + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1161c4);
          (*pcVar3)();
        }
        (**(code **)(lVar19 + 0x28))(lVar16,100);
        uVar6 = 0;
      }
      else {
        if (param_2 != 0x4708) goto switchD_00115a4c_caseD_40004704;
        if (param_3 == 0) {
          uVar9 = 5;
        }
        else {
          uVar9 = 6;
        }
        goodix_ts_blocking_notify(uVar9,0);
        uVar6 = 0;
      }
    }
  }
LAB_001165e8:
  lVar16 = (long)(int)uVar6;
LAB_001165ec:
  lVar19 = sp_el0;
  if (*(long *)(lVar19 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar16);
  }
  return;
}



//------------------------------------------------------------
// goodix_tools_compat_ioctl @ 001168a8 size=80
// signature: undefined goodix_tools_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_tools_compat_ioctl(long param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 uVar1;
  code *pcVar2;
  
  if ((*(long *)(param_1 + 0x28) == 0) ||
     (pcVar2 = *(code **)(*(long *)(param_1 + 0x28) + 0x50), pcVar2 == (code *)0x0)) {
    uVar1 = 0xffffffffffffffe7;
  }
  else {
    if (*(int *)(pcVar2 + -4) != -0x1febf733) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1168e0);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(param_1,param_2,param_3);
  }
  return uVar1;
}



//------------------------------------------------------------
// goodix_tools_open @ 001168fc size=168
// signature: undefined goodix_tools_open(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_tools_open(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  
  _printk(&DAT_00122595,"goodix_tools_open",0x187);
  iVar2 = goodix_register_ext_module_no_wait(goodix_tools_dev + 0x90);
  if (iVar2 == 0) {
    _printk(&DAT_00128431,"goodix_tools_open",0x18e);
    goodix_ts_blocking_notify(5,0);
    lVar1 = goodix_tools_dev;
    uVar3 = 0;
    *(long *)(param_2 + 0xd8) = goodix_tools_dev;
    *(undefined4 *)(lVar1 + 0x88) = 1;
  }
  else {
    _printk(&DAT_0011f500,"goodix_tools_open",0x18b);
    uVar3 = 0xfffffff2;
  }
  return uVar3;
}



//------------------------------------------------------------
// goodix_tools_release @ 001169a8 size=76
// signature: undefined goodix_tools_release(void)
// callers: []
//------------------------------------------------------------

void goodix_tools_release(void)

{
  long *plVar1;
  
  plVar1 = goodix_tools_dev;
  *(undefined1 *)(*goodix_tools_dev + 0x4d8) = 0;
  *(undefined4 *)(plVar1 + 0x11) = 0;
  goodix_ts_blocking_notify(6,0);
  goodix_unregister_ext_module(goodix_tools_dev + 0x12);
  return;
}



//------------------------------------------------------------
// read_config_data @ 001169f4 size=964
// signature: undefined read_config_data(void)
// callers: [goodix_tools_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint read_config_data(long param_1,ulong param_2)

{
  undefined8 *puVar1;
  ulong uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  size_t __n;
  long lVar6;
  long lVar7;
  ulong uVar8;
  code *pcVar9;
  ulong uVar10;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  long local_48;
  
  lVar6 = sp_el0;
  local_48 = *(long *)(lVar6 + 0x638);
  puVar1 = (undefined8 *)sp_el0;
  local_50 = 0;
  local_60 = 0;
  uStack_58 = 0;
  if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_2, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
    uVar8 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar8 < 0x7fffffffed) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar10 = daif;
        daif = uVar10 | 0xc0;
      }
      uVar10 = ttbr1_el1;
      ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar10 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar1[1];
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    __n = __arch_copy_from_user(&local_60,param_2 & 0xff7fffffffffffff,0x14);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar10 = daif;
        daif = uVar10 | 0xc0;
      }
      uVar10 = ttbr1_el1;
      ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar10 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    if (__n != 0) goto LAB_00116d48;
  }
  else {
    __n = 0x14;
LAB_00116d48:
    memset(auStack_4c + -__n,0,__n);
    if ((int)__n != 0) {
      _printk(&DAT_001207cc,"read_config_data",0x85);
      uVar5 = 0xfffffff2;
      goto LAB_00116cc8;
    }
  }
  uVar8 = local_60;
  iVar3 = (int)local_60;
  uVar5 = local_60._4_4_;
  _printk(&DAT_001251ea,"read_config_data",0x8c,local_60 & 0xffffffff,local_60._4_4_);
  if (0x4000 < uVar5) {
    _printk(&DAT_00124562,"read_config_data",0x8e,uVar5,0x4000);
    uVar5 = 0xffffffea;
    goto LAB_00116cc8;
  }
  lVar6 = __kmalloc(uVar5,0xdc0);
  if (lVar6 == 0) {
    _printk(&DAT_00121d6d,"read_config_data",0x93);
    uVar5 = 0xfffffff4;
    goto LAB_00116cc8;
  }
  if (iVar3 == 0) {
    pcVar9 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x58);
    if (pcVar9 != (code *)0x0) {
      if (*(int *)(pcVar9 + -4) != -0xf5e9d57) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x116bb0);
        (*pcVar9)();
      }
      uVar5 = (*pcVar9)(param_1,lVar6,uVar5);
      goto joined_r0x00116bbc;
    }
    uVar5 = 0xffffffea;
  }
  else {
    pcVar9 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x38);
    if (*(int *)(pcVar9 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
      pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x116b6c);
      (*pcVar9)();
    }
    uVar4 = (*pcVar9)(param_1,uVar8 & 0xffffffff,lVar6,uVar5);
    if (uVar4 != 0) {
      uVar5 = uVar4;
    }
joined_r0x00116bbc:
    if (0 < (int)uVar5) {
      param_2 = param_2 + 0x14;
      uVar8 = (ulong)uVar5;
      __check_object_size(lVar6,uVar8,1);
      if (((*(byte *)((long)puVar1 + 0x46) >> 5 & 1) != 0) ||
         (uVar10 = param_2, ((uint)*puVar1 >> 0x1a & 1) != 0)) {
        uVar10 = param_2 & (long)(param_2 * 0x100) >> 8;
      }
      if (uVar10 <= 0x8000000000 - uVar8) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar10 = daif;
          if ((uVar10 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr1_el1 = puVar1[1] & 0xffff000000000000 | uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar1[1];
          InstructionSynchronizationBarrier();
          daif = uVar10;
        }
        lVar7 = __arch_copy_to_user(param_2 & 0xff7fffffffffffff,lVar6,uVar8);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar8 = daif;
          if ((uVar8 & 0x80) == 0) {
            uVar10 = daif;
            daif = uVar10 | 0xc0;
          }
          uVar10 = ttbr1_el1;
          ttbr0_el1 = (uVar10 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar10 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar8;
        }
        if (lVar7 == 0) goto LAB_00116cc0;
      }
      _printk(&DAT_0011efa7,"read_config_data",0xa6);
      uVar5 = 0xfffffff2;
    }
  }
LAB_00116cc0:
  kfree(lVar6);
LAB_00116cc8:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar5;
}



//------------------------------------------------------------
// goodix_ts_mmi_get_report_rate @ 00116f54 size=984
// signature: undefined goodix_ts_mmi_get_report_rate(void)
// callers: [goodix_ts_mmi_set_report_rate]
//------------------------------------------------------------

ulong goodix_ts_mmi_get_report_rate(long param_1)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  code *pcVar4;
  ulong uVar5;
  uint uVar6;
  ulong uVar7;
  ulong uVar8;
  int iVar9;
  long lVar10;
  
  cVar2 = *(char *)(param_1 + 700);
  cVar3 = *(char *)(param_1 + 0x2ba);
  uVar1 = *(uint *)(param_1 + 0x62c);
  iVar9 = *(int *)(param_1 + 0x5e0);
  if (debug_log_flag != '\0') {
    _printk(&DAT_00122b66,"goodix_ts_mmi_get_report_rate",0x95,cVar2,cVar3,uVar1,iVar9);
  }
  if ((cVar2 == '\0') && (cVar3 != '\0')) {
    uVar7 = (ulong)report_rate_config_info;
    if ((report_rate_config_info == 0) || (uVar1 == DAT_00128ecc)) goto LAB_001170c4;
    if (report_rate_config_info == 1) {
LAB_00116fbc:
      uVar5 = (ulong)report_rate_config_info;
      uVar7 = uVar5;
    }
    else if (uVar1 == DAT_00128ed6) {
      uVar5 = 1;
    }
    else {
      if (report_rate_config_info == 2) goto LAB_00116fbc;
      if (uVar1 == DAT_00128ee0) {
        uVar5 = 2;
      }
      else {
        if (report_rate_config_info == 3) goto LAB_00116fbc;
        if (uVar1 == DAT_00128eea) {
          uVar5 = 3;
        }
        else {
          if (report_rate_config_info == 4) goto LAB_00116fbc;
          if (uVar1 == DAT_00128ef4) {
            uVar5 = 4;
          }
          else {
            if (report_rate_config_info == 5) goto LAB_00116fbc;
            if (uVar1 == DAT_00128efe) {
              uVar5 = 5;
            }
            else {
              uVar6 = (uint)report_rate_config_info;
              if (uVar6 == 6) goto LAB_00116fbc;
              if (uVar1 == DAT_00128f08) {
                uVar5 = 6;
              }
              else {
                if (uVar6 == 7) goto LAB_00116fbc;
                if (uVar1 == DAT_00128f12) {
                  uVar5 = 7;
                }
                else {
                  if (uVar6 == 8) goto LAB_00116fbc;
                  if (uVar1 == DAT_00128f1c) {
                    uVar5 = 8;
                  }
                  else {
                    if (uVar6 == 9) goto LAB_00116fbc;
                    if (uVar1 == DAT_00128f26) {
                      uVar5 = 9;
                    }
                    else {
                      if (uVar6 == 10) goto LAB_00116fbc;
                      if (uVar1 == DAT_00128f30) {
                        uVar5 = 10;
                      }
                      else {
                        if (uVar6 == 0xb) goto LAB_00116fbc;
                        if (uVar1 == DAT_00128f3a) {
                          uVar5 = 0xb;
                        }
                        else {
                          uVar5 = (ulong)uVar6;
                          if (uVar6 != 0xc) goto LAB_00117328;
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
    }
  }
  else {
    if ((cVar2 == '\0') || (cVar3 == '\0')) {
      uVar5 = (ulong)report_rate_config_info;
      if ((cVar2 != '\0') && (cVar3 == '\0')) {
        if (report_rate_config_info == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = 0;
          uVar8 = 8;
          do {
            if (uVar8 - 0x7e < 0xffffffffffffff84) goto LAB_00117328;
            if ((int)(uint)*(ushort *)(goodix_tools_miscdev + uVar8 + 0x4e) <= iVar9) {
              if (0x7b < uVar8) goto LAB_00117328;
              if (iVar9 <= (int)(uint)*(ushort *)(&report_rate_config_info + uVar8)) {
                uVar5 = uVar7 & 0xffffffff;
                uVar7 = (ulong)(uint)report_rate_config_info;
                goto LAB_001170c8;
              }
            }
            uVar7 = uVar7 + 1;
            uVar8 = uVar8 + 10;
          } while (uVar5 != uVar7);
          uVar7 = uVar5;
        }
        goto LAB_001170c8;
      }
    }
    else {
      uVar7 = (ulong)report_rate_config_info;
      if (report_rate_config_info != 0) {
        lVar10 = 0;
        uVar5 = 0;
        do {
          if (lVar10 - 0x78U < 0xffffffffffffff84) goto LAB_00117328;
          if (uVar1 == (&DAT_00128ecc)[lVar10]) {
            if (lVar10 - 0x76U < 0xffffffffffffff84) goto LAB_00117328;
            if ((int)(uint)*(ushort *)((long)&DAT_00128ece + lVar10) <= iVar9) {
              if (lVar10 - 0x74U < 0xffffffffffffff84) goto LAB_00117328;
              if (iVar9 <= (int)(uint)*(ushort *)((long)&DAT_00128ed0 + lVar10)) goto LAB_001170c8;
            }
          }
          uVar5 = (ulong)((int)uVar5 + 1);
          lVar10 = lVar10 + 10;
        } while (uVar7 * 10 != lVar10);
        goto LAB_00116fbc;
      }
    }
LAB_001170c4:
    uVar5 = 0;
    uVar7 = (ulong)report_rate_config_info;
  }
LAB_001170c8:
  iVar9 = (int)uVar5;
  if (iVar9 == (int)uVar7) {
    _printk(&DAT_00121077,"goodix_ts_mmi_get_report_rate",0xb2);
    uVar5 = 0xffffffff;
  }
  else {
    if (debug_log_flag != '\0') {
      if (((long)iVar9 * 10 - 0x73U < 0xffffffffffffff83) ||
         ((long)iVar9 * 10 - 0x71U < 0xffffffffffffff83)) goto LAB_00117328;
      _printk(&DAT_00126d8f,"goodix_ts_mmi_get_report_rate",0xb7,
              *(undefined2 *)((long)iVar9 * 10 + 0x128ed2),
              *(undefined2 *)(&DAT_00128ed4 + (long)iVar9 * 10));
    }
    if ((long)iVar9 * 10 - 0x71U < 0xffffffffffffff83) {
LAB_00117328:
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(1,0x11732c);
      (*pcVar4)();
    }
    uVar5 = (ulong)*(ushort *)(&DAT_00128ed4 + (long)iVar9 * 10);
  }
  return uVar5;
}



//------------------------------------------------------------
// goodix_gesture_enable @ 00117330 size=188
// signature: undefined goodix_gesture_enable(void)
// callers: [gesture_module_init]
//------------------------------------------------------------

undefined8 goodix_gesture_enable(int param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  if (module_initialized == '\x01') {
    if (param_1 == 0) {
      if (*gsx_gesture == 0) {
        _printk(&DAT_001278e9,"goodix_gesture_enable",0x42);
        iVar2 = 0;
        uVar1 = 0;
      }
      else {
        uVar1 = goodix_unregister_ext_module(gsx_gesture + 8);
        iVar2 = 0;
      }
    }
    else if (*gsx_gesture == 0) {
      uVar1 = goodix_register_ext_module_no_wait(gsx_gesture + 8);
      iVar2 = 1;
    }
    else {
      _printk(&DAT_00120d54,"goodix_gesture_enable",0x3c);
      uVar1 = 0;
      iVar2 = 1;
    }
    *gsx_gesture = iVar2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsx_gesture_enable_show @ 001173f0 size=60
// signature: undefined gsx_gesture_enable_show(void)
// callers: []
//------------------------------------------------------------

long gsx_gesture_enable_show(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0012011c,*gsx_gesture);
  return (long)iVar1;
}



//------------------------------------------------------------
// gsx_gesture_enable_store @ 00117430 size=288
// signature: undefined gsx_gesture_enable_store(void)
// callers: []
//------------------------------------------------------------

long gsx_gesture_enable_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_2,local_2c);
  if (-1 < iVar2) {
    if (local_2c[0] == '\0') {
      if (module_initialized == '\0') goto LAB_001174d4;
      if (*gsx_gesture == 0) {
        _printk(&DAT_001278e9,"goodix_gesture_enable",0x42);
        *gsx_gesture = 0;
        goto LAB_001174d4;
      }
      iVar2 = goodix_unregister_ext_module(gsx_gesture + 8);
      *gsx_gesture = 0;
    }
    else {
      if (module_initialized == '\0') goto LAB_001174d4;
      if (*gsx_gesture != 0) {
        _printk(&DAT_00120d54,"goodix_gesture_enable",0x3c);
        *gsx_gesture = 1;
        goto LAB_001174d4;
      }
      iVar2 = goodix_register_ext_module_no_wait(gsx_gesture + 8);
      *gsx_gesture = 1;
    }
    if (iVar2 == 0) goto LAB_001174d4;
  }
  param_3 = (long)iVar2;
LAB_001174d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// gsx_gesture_data_show @ 00117554 size=100
// signature: undefined gsx_gesture_data_show(void)
// callers: []
//------------------------------------------------------------

long gsx_gesture_data_show(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  _raw_read_lock(gsx_gesture + 4);
  iVar1 = scnprintf(param_2,0x1000,"gesture type code:0x%x\n",*(undefined1 *)(gsx_gesture + 0x18));
  _raw_read_unlock(gsx_gesture + 4);
  return (long)iVar1;
}



//------------------------------------------------------------
// gsx_double_type_show @ 001175bc size=136
// signature: undefined gsx_double_type_show(void)
// callers: []
//------------------------------------------------------------

long gsx_double_type_show(long param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x28);
  if (piVar4 == (int *)0x0) {
    lVar3 = -5;
  }
  else if (*piVar4 == 0) {
    _printk(&DAT_0011fb6c,"gsx_double_type_show",0x54);
    lVar3 = 0;
  }
  else {
    pcVar1 = "disable";
    if ((*(byte *)(*(long *)(piVar4 + 4) + 0x6a1) & 2) != 0) {
      pcVar1 = "enable";
    }
    iVar2 = sprintf(param_2,"%s\n",pcVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// gsx_double_type_store @ 00117648 size=228
// signature: undefined gsx_double_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_double_type_store(long param_1,char *param_2,undefined8 param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 == (int *)0x0) {
    param_3 = 0xfffffffffffffffb;
  }
  else if (*piVar1 == 0) {
    _printk(&DAT_0011fb6c,"gsx_double_type_store",0x65);
    param_3 = 0;
  }
  else if (*param_2 == '0') {
    _printk(&DAT_00125740,"gsx_double_type_store",0x6d);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) & 0xfd;
  }
  else if (*param_2 == '1') {
    _printk(&DAT_001210b3,"gsx_double_type_store",0x6a);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) | 2;
  }
  else {
    _printk(&DAT_00120120,"gsx_double_type_store",0x70);
  }
  return param_3;
}



//------------------------------------------------------------
// gsx_single_type_show @ 00117730 size=136
// signature: undefined gsx_single_type_show(void)
// callers: []
//------------------------------------------------------------

long gsx_single_type_show(long param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x28);
  if (piVar4 == (int *)0x0) {
    lVar3 = -5;
  }
  else if (*piVar4 == 0) {
    _printk(&DAT_0011fb6c,"gsx_single_type_show",0x7f);
    lVar3 = 0;
  }
  else {
    pcVar1 = "disable";
    if ((*(byte *)(*(long *)(piVar4 + 4) + 0x6a1) & 1) != 0) {
      pcVar1 = "enable";
    }
    iVar2 = sprintf(param_2,"%s\n",pcVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// gsx_single_type_store @ 001177bc size=228
// signature: undefined gsx_single_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_single_type_store(long param_1,char *param_2,undefined8 param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 == (int *)0x0) {
    param_3 = 0xfffffffffffffffb;
  }
  else if (*piVar1 == 0) {
    _printk(&DAT_0011fb6c,"gsx_single_type_store",0x90);
    param_3 = 0;
  }
  else if (*param_2 == '0') {
    _printk(&DAT_0011ea73,"gsx_single_type_store",0x98);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) & 0xfe;
  }
  else if (*param_2 == '1') {
    _printk(&DAT_00127401,"gsx_single_type_store",0x95);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) | 1;
  }
  else {
    _printk(&DAT_00120120,"gsx_single_type_store",0x9b);
  }
  return param_3;
}



//------------------------------------------------------------
// gsx_fod_type_show @ 001178a4 size=136
// signature: undefined gsx_fod_type_show(void)
// callers: []
//------------------------------------------------------------

long gsx_fod_type_show(long param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  long lVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x28);
  if (piVar4 == (int *)0x0) {
    lVar3 = -5;
  }
  else if (*piVar4 == 0) {
    _printk(&DAT_0011fb6c,"gsx_fod_type_show",0xaa);
    lVar3 = 0;
  }
  else {
    pcVar1 = "disable";
    if ((*(byte *)(*(long *)(piVar4 + 4) + 0x6a1) & 4) != 0) {
      pcVar1 = "enable";
    }
    iVar2 = sprintf(param_2,"%s\n",pcVar1);
    lVar3 = (long)iVar2;
  }
  return lVar3;
}



//------------------------------------------------------------
// gsx_fod_type_store @ 00117930 size=228
// signature: undefined gsx_fod_type_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_fod_type_store(long param_1,char *param_2,undefined8 param_3)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 == (int *)0x0) {
    param_3 = 0xfffffffffffffffb;
  }
  else if (*piVar1 == 0) {
    _printk(&DAT_0011fb6c,"gsx_fod_type_store",0xbb);
    param_3 = 0;
  }
  else if (*param_2 == '0') {
    _printk(&DAT_00120805,"gsx_fod_type_store",0xc3);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) & 0xfb;
  }
  else if (*param_2 == '1') {
    _printk(&DAT_00125223,"gsx_fod_type_store",0xc0);
    *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) = *(byte *)(*(long *)(piVar1 + 4) + 0x6a1) | 4;
  }
  else {
    _printk(&DAT_00120120,"gsx_fod_type_store",0xc6);
  }
  return param_3;
}



//------------------------------------------------------------
// gesture_module_init @ 00117a18 size=784
// signature: undefined gesture_module_init(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gesture_module_init(void)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 *puVar9;
  int iVar10;
  
  uVar7 = goodix_get_default_kobj();
  uVar8 = goodix_get_default_ktype();
  puVar9 = (undefined4 *)kmalloc_trace(___kmalloc,0xdc0,0xe0);
  gsx_gesture = puVar9;
  if (puVar9 == (undefined4 *)0x0) {
    iVar5 = -0xc;
  }
  else {
    *(undefined ***)(puVar9 + 0x10) = &gsx_gesture_funcs;
    *(undefined4 **)(puVar9 + 0x12) = puVar9;
    puVar9[0xe] = 2;
    *(char **)(puVar9 + 0xc) = "Goodix_gsx_gesture";
    *puVar9 = 0;
    *(undefined8 *)(puVar9 + 1) = 0;
    iVar5 = kobject_init_and_add(puVar9 + 0x14,uVar8,uVar7,"gesture");
    if (iVar5 == 0) {
      iVar6 = sysfs_create_file_ns(gsx_gesture + 0x14,&gesture_attrs,0);
      bVar4 = iVar6 == 0;
      if (iVar6 == 0) {
        iVar5 = sysfs_create_file_ns(gsx_gesture + 0x14,&PTR_DAT_0011d350,0);
        bVar4 = iVar5 == 0;
        if (iVar5 == 0) {
          iVar5 = sysfs_create_file_ns(gsx_gesture + 0x14,&PTR_s_double_en_0011d370,0);
          bVar4 = iVar5 == 0;
          if (iVar5 == 0) {
            iVar5 = sysfs_create_file_ns(gsx_gesture + 0x14,&PTR_s_single_en_0011d390,0);
            bVar4 = iVar5 == 0;
            if (iVar5 == 0) {
              iVar5 = sysfs_create_file_ns(gsx_gesture + 0x14,&PTR_s_fod_en_0011d3b0,0);
              bVar4 = iVar5 == 0;
              bVar1 = true;
              iVar10 = 5;
              bVar2 = true;
              bVar3 = true;
            }
            else {
              bVar3 = false;
              bVar1 = true;
              iVar10 = 4;
              bVar2 = true;
            }
          }
          else {
            bVar2 = false;
            bVar3 = false;
            bVar1 = true;
            iVar10 = 3;
          }
        }
        else {
          bVar1 = false;
          bVar2 = false;
          bVar3 = false;
          iVar10 = 2;
        }
      }
      else {
        bVar1 = false;
        bVar2 = false;
        bVar3 = false;
        iVar10 = 1;
        iVar5 = iVar6;
      }
      if (bVar4) {
        module_initialized = 1;
        goodix_gesture_enable(1);
        _printk(&DAT_001273bc,"gesture_module_init",0x28c);
        return 0;
      }
      _printk(&DAT_0011f533,"gesture_module_init",0x27f);
      sysfs_remove_file_ns(gsx_gesture + 0x14,&gesture_attrs + (ulong)(iVar10 - 1) * 4,0);
      if ((((iVar6 == 0) &&
           (sysfs_remove_file_ns(gsx_gesture + 0x14,&gesture_attrs + (ulong)(iVar10 - 2) * 4,0),
           bVar1)) &&
          (sysfs_remove_file_ns(gsx_gesture + 0x14,&gesture_attrs + (ulong)(iVar10 - 3) * 4,0),
          bVar2)) &&
         (sysfs_remove_file_ns(gsx_gesture + 0x14,&gesture_attrs + (ulong)(iVar10 - 4) * 4,0), bVar3
         )) {
        sysfs_remove_file_ns(gsx_gesture + 0x14,&gesture_attrs + (ulong)(iVar10 - 5) * 4,0);
      }
      kobject_put(gsx_gesture + 0x14);
    }
    else {
      _printk(&DAT_00123f84,"gesture_module_init",0x277);
    }
    _printk(&DAT_00121d95,"gesture_module_init",0x291);
    kfree(gsx_gesture);
  }
  return iVar5;
}



//------------------------------------------------------------
// gesture_module_exit @ 00117d2c size=264
// signature: undefined gesture_module_exit(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

void gesture_module_exit(void)

{
  int *piVar1;
  
  _printk(&DAT_0012320f,"gesture_module_exit",0x29a);
  if (module_initialized == '\x01') {
    if (*gsx_gesture == 0) {
      _printk(&DAT_001278e9,"goodix_gesture_enable",0x42);
    }
    else {
      goodix_unregister_ext_module(gsx_gesture + 8);
    }
    piVar1 = gsx_gesture + 0x14;
    *gsx_gesture = 0;
    sysfs_remove_file_ns(piVar1,&gesture_attrs,0);
    sysfs_remove_file_ns(gsx_gesture + 0x14,&PTR_DAT_0011d350,0);
    sysfs_remove_file_ns(gsx_gesture + 0x14,&PTR_s_double_en_0011d370,0);
    sysfs_remove_file_ns(gsx_gesture + 0x14,&PTR_s_single_en_0011d390,0);
    sysfs_remove_file_ns(gsx_gesture + 0x14,&PTR_s_fod_en_0011d3b0,0);
    kobject_put(gsx_gesture + 0x14);
    kfree(gsx_gesture);
    module_initialized = '\0';
  }
  return;
}



//------------------------------------------------------------
// gsx_gesture_init @ 00117e38 size=196
// signature: undefined gsx_gesture_init(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_gesture_init(long param_1,long param_2)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  long lVar3;
  
  if ((param_1 == 0) || (*(long *)(*(long *)(param_1 + 0x2d0) + 0x20) == 0)) {
    _printk(&DAT_00121dc5,"gsx_gesture_init",0x142);
    uVar2 = 0xffffffea;
  }
  else {
    lVar3 = *(long *)(param_2 + 0x28);
    _printk(&DAT_00122bd2,"gsx_gesture_init",0x146);
    if (debug_log_flag != '\0') {
      _printk(&DAT_0011d8fe,"gsx_gesture_init",0x147);
    }
    puVar1 = gsx_gesture;
    uVar2 = 0;
    *(long *)(lVar3 + 0x10) = param_1;
    *(undefined1 *)(param_1 + 0x6a1) = 7;
    *(undefined8 *)(param_1 + 0x6a4) = 0x100000000;
    *puVar1 = 1;
  }
  return uVar2;
}



//------------------------------------------------------------
// gsx_gesture_exit @ 00117f00 size=168
// signature: undefined gsx_gesture_exit(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_gesture_exit(long param_1)

{
  undefined8 uVar1;
  
  if ((param_1 == 0) || (*(long *)(*(long *)(param_1 + 0x2d0) + 0x20) == 0)) {
    _printk(&DAT_00121dc5,"gsx_gesture_exit",0x157);
    uVar1 = 0xffffffea;
  }
  else {
    _printk(&DAT_0011d92a,"gsx_gesture_exit",0x15b);
    if (debug_log_flag != '\0') {
      _printk(&DAT_001245b7,"gsx_gesture_exit",0x15c);
    }
    uVar1 = 0;
    *(undefined1 *)(param_1 + 0x6a1) = 0;
    *gsx_gesture = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsx_gesture_before_suspend @ 00117fac size=212
// signature: undefined gsx_gesture_before_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_gesture_before_suspend(long param_1)

{
  int iVar1;
  code *pcVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    uVar3 = 0;
  }
  else {
    lVar4 = *(long *)(param_1 + 0x2d0);
    pcVar2 = *(code **)(lVar4 + 0x20);
    if (*(int *)(pcVar2 + -4) != -0x24847470) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x118004);
      (*pcVar2)();
    }
    iVar1 = (*pcVar2)(param_1,0);
    if (iVar1 == 0) {
      _printk(&DAT_00126245,"gsx_gesture_before_suspend",0x242,*(undefined1 *)(param_1 + 0x6a1));
    }
    else {
      _printk(&DAT_0011d952,"gsx_gesture_before_suspend",0x240);
    }
    pcVar2 = *(code **)(lVar4 + 0x30);
    uVar3 = 1;
    if (*(int *)(pcVar2 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x11806c);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,1);
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0x4b8),1);
  }
  return uVar3;
}



//------------------------------------------------------------
// gsx_gesture_before_resume @ 00118084 size=148
// signature: undefined gsx_gesture_before_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 gsx_gesture_before_resume(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  if (*(char *)(param_1 + 0x6a1) == '\0') {
    uVar1 = 0;
  }
  else {
    lVar3 = *(long *)(param_1 + 0x2d0);
    pcVar2 = *(code **)(lVar3 + 0x30);
    if (*(int *)(pcVar2 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1180c4);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,0);
    irq_set_irq_wake(*(undefined4 *)(param_1 + 0x4b8),0);
    pcVar2 = *(code **)(lVar3 + 0x28);
    if (*(int *)(pcVar2 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1180f8);
      (*pcVar2)();
    }
    (*pcVar2)(param_1,100);
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// gsx_gesture_ist @ 0011811c size=1316
// signature: undefined gsx_gesture_ist(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gsx_gesture_ist(long param_1)

{
  long lVar1;
  uint uVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  long lVar11;
  long lVar12;
  undefined8 local_1e8;
  undefined8 local_1e0;
  undefined8 uStack_1d8;
  undefined8 local_1d0;
  undefined8 uStack_1c8;
  ulong local_1c0;
  undefined4 uStack_1b8;
  uint local_1b4;
  uint local_1b0;
  undefined4 uStack_1ac;
  undefined8 uStack_1a8;
  undefined4 local_1a0;
  undefined1 auStack_198 [4];
  uint local_194;
  char local_18f;
  byte local_18e;
  ushort local_6c;
  ushort local_6a;
  long local_58;
  
  lVar12 = sp_el0;
  local_58 = *(long *)(lVar12 + 0x638);
  lVar12 = *(long *)(param_1 + 0x2d0);
  memset(auStack_198,0,0x13c);
  local_1a0 = 0;
  iVar7 = *(int *)(param_1 + 0x6a4);
  local_1b0 = 0;
  uStack_1ac = 0;
  uStack_1a8 = 0;
  local_1c0 = 0;
  uStack_1b8 = 0;
  local_1b4 = 0;
  if ((*(int *)(param_1 + 0x4d0) == 0) || (*(char *)(param_1 + 0x6a1) == '\0')) {
    uVar9 = 0;
    goto LAB_00118308;
  }
  if ((*(char *)(param_1 + 0x2c0) != '\0') &&
     (pm_wakeup_ws_event(*(undefined8 *)(param_1 + 0x4e0),3000,0), *(int *)(param_1 + 0x6bc) == 0))
  {
    local_1d0 = 0;
    uStack_1c8 = 0;
    local_1e0 = 0;
    uStack_1d8 = 0;
    local_1e8 = 0;
    init_wait_entry(&local_1e8,0);
    lVar1 = param_1 + 0x6c0;
    lVar8 = prepare_to_wait_event(lVar1,&local_1e8,1);
    if (*(int *)(param_1 + 0x6bc) == 0) {
      lVar11 = 0xaf;
      do {
        if (lVar8 != 0) goto LAB_001181e8;
        lVar11 = schedule_timeout(lVar11);
        lVar8 = prepare_to_wait_event(lVar1,&local_1e8,1);
        if (lVar11 == 0 && *(int *)(param_1 + 0x6bc) != 0) {
          lVar11 = 1;
        }
      } while ((*(int *)(param_1 + 0x6bc) == 0) && (lVar11 != 0));
    }
    else {
      lVar11 = 0xaf;
    }
    lVar8 = lVar11;
    finish_wait(lVar1,&local_1e8);
LAB_001181e8:
    if ((int)lVar8 == 0) {
      _printk(&DAT_00128460,"gsx_gesture_ist",0x182);
      uVar9 = 1;
      goto LAB_00118308;
    }
  }
  if (*(int *)(*(code **)(lVar12 + 0x78) + -4) != 0x2bf9e380) {
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118210);
    (*pcVar4)();
  }
  iVar5 = (**(code **)(lVar12 + 0x78))(param_1,auStack_198);
  if (iVar5 == 0) {
    if ((local_194 >> 3 & 1) == 0) {
      _printk(&DAT_0012627a,"gsx_gesture_ist",399);
      goto LAB_001182a0;
    }
    if (debug_log_flag == '\0') {
      if (*(int *)(param_1 + 0x614) == 0) goto LAB_00118248;
LAB_00118234:
      uVar2 = local_18e & 0x20;
      if (*(uint *)(param_1 + 0x4c8) == uVar2) goto LAB_00118248;
      *(uint *)(param_1 + 0x4c8) = uVar2;
      pcVar4 = *(code **)(*(long *)(param_1 + 0x680) + 0x38);
      if (*(int *)(pcVar4 + -4) != 0x2249bf8d) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x118428);
        (*pcVar4)();
      }
      (*pcVar4)(*(undefined8 *)(*(long *)(param_1 + 0x100) + 8),uVar2 >> 5);
      _printk(&DAT_00120d9b,"gsx_gesture_ist",0x19a,*(undefined4 *)(param_1 + 0x4c8));
    }
    else {
      _printk(&DAT_0012792a,"gsx_gesture_ist",0x192,local_18f);
      if (*(int *)(param_1 + 0x614) != 0) goto LAB_00118234;
LAB_00118248:
      local_1c0 = local_1c0 & 0xffffffff00000000;
      if ((*(long **)(param_1 + 0x680) == (long *)0x0) || (**(long **)(param_1 + 0x680) == 0))
      goto LAB_001182a0;
      bVar3 = *(byte *)(param_1 + 0x6a1);
      if (((bVar3 & 1) == 0) || (local_18f != 'L')) {
        if (((bVar3 >> 1 & 1) == 0) || (local_18f != -0x34)) {
          if (((bVar3 >> 2 & 1) == 0) || (local_18f != 'F')) {
            if (((bVar3 >> 2 & 1) == 0) || (local_18f != 'U')) {
              if (debug_log_flag != '\0') {
                _printk(&DAT_00125242,"gsx_gesture_ist",0x1db,local_18f,
                        *(undefined4 *)(param_1 + 0x4d0));
              }
            }
            else {
              _printk(&DAT_00120825,"gsx_gesture_ist",0x1d2);
              local_1b4 = 0;
              local_1b0 = 0;
              local_1c0 = CONCAT44(local_1c0._4_4_,3);
              if (*(int *)((code *)**(undefined8 **)(param_1 + 0x680) + -4) != -0x366473dd) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1185c8);
                (*pcVar4)();
              }
              iVar7 = (*(code *)**(undefined8 **)(param_1 + 0x680))(&local_1c0);
              if (iVar7 == 0) {
                pm_wakeup_ws_event(*(undefined8 *)(param_1 + 0x4e0),500,0);
              }
            }
            iVar7 = 0;
          }
          else {
            iVar6 = jiffies_to_msecs(_jiffies - gsx_gesture_ist_start);
            local_1c0 = CONCAT44(local_1c0._4_4_,2);
            local_1b4 = 0;
            local_1b0 = 0;
            _printk(&DAT_00127427,"gsx_gesture_ist",0x1c3,iVar7,iVar6);
            iVar5 = 0;
            if (iVar6 < 0x7d1) {
              iVar5 = iVar7;
            }
            if ((iVar6 - 1U < 0xf9) && (iVar5 != 0)) goto LAB_001182cc;
            gsx_gesture_ist_start = _jiffies;
            if (iVar5 < 6) {
              if (*(int *)((code *)**(undefined8 **)(param_1 + 0x680) + -4) != -0x366473dd) {
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118560);
                (*pcVar4)();
              }
              iVar7 = (*(code *)**(undefined8 **)(param_1 + 0x680))(&local_1c0);
              if (iVar7 == 0) {
                pm_wakeup_ws_event(*(undefined8 *)(param_1 + 0x4e0),3000,0);
              }
            }
            iVar7 = iVar5 + 1;
          }
          goto LAB_001182a0;
        }
        _printk(&DAT_00125ba9,"gsx_gesture_ist",0x1ae);
        uVar10 = 4;
      }
      else {
        _printk(&DAT_00125b7e,"gsx_gesture_ist",0x1a2);
        uVar10 = 1;
      }
      local_1c0 = CONCAT44(local_1c0._4_4_,uVar10);
      local_1b4 = (uint)local_6c;
      local_1b0 = (uint)local_6a;
      if (*(int *)((code *)**(undefined8 **)(param_1 + 0x680) + -4) != -0x366473dd) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1184bc);
        (*pcVar4)();
      }
      iVar7 = (*(code *)**(undefined8 **)(param_1 + 0x680))(&local_1c0);
      if (iVar7 == 0) {
        pm_wakeup_ws_event(*(undefined8 *)(param_1 + 0x4e0),3000,0);
        iVar7 = 0;
      }
      else {
        iVar7 = 0;
      }
    }
  }
  else {
    _printk(&DAT_00122bf9,"gsx_gesture_ist",0x189);
LAB_001182a0:
    if (*(int *)(*(code **)(lVar12 + 0x20) + -4) != -0x24847470) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1182c4);
      (*pcVar4)();
    }
    iVar5 = (**(code **)(lVar12 + 0x20))(param_1,*(undefined2 *)(param_1 + 0x6b8));
    if (iVar5 != 0) {
      _printk(&DAT_001245e4,"gsx_gesture_ist",0x225);
    }
  }
LAB_001182cc:
  if (*(char *)(param_1 + 0x4d8) == '\0') {
    if (*(int *)(*(code **)(lVar12 + 0x80) + -4) != 0x1c1b2b73) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1182f4);
      (*pcVar4)();
    }
    (**(code **)(lVar12 + 0x80))(param_1);
  }
  uVar9 = 1;
  *(int *)(param_1 + 0x6a4) = iVar7;
LAB_00118308:
  lVar12 = sp_el0;
  if (*(long *)(lVar12 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_send_cmd @ 00118644 size=128
// signature: undefined goodix_ts_send_cmd(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_send_cmd(long param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                       undefined1 param_5)

{
  long lVar1;
  code *pcVar2;
  long local_28 [3];
  
  lVar1 = sp_el0;
  local_28[2] = *(long *)(lVar1 + 0x638);
  local_28[1] = 0;
  pcVar2 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
  local_28[0] = (ulong)CONCAT13(param_5,CONCAT12(param_4,CONCAT11(param_2,param_3))) << 0x10;
  if (*(int *)(pcVar2 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x118698);
    (*pcVar2)();
  }
  (*pcVar2)(param_1,local_28);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_dev_register @ 001186c8 size=224
// signature: undefined goodix_ts_mmi_dev_register(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

int goodix_ts_mmi_dev_register(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0xa8);
  if (lVar3 == 0) {
    _printk(&DAT_00127f62,"goodix_ts_mmi_dev_register",0x7e4);
    iVar2 = -0x13;
  }
  else {
    __mutex_init(lVar3 + 0x650,"&core_data->mode_lock",&goodix_ts_mmi_dev_register___key);
    iVar2 = ts_mmi_dev_register(*(undefined8 *)(*(long *)(lVar3 + 0x100) + 8),&goodix_ts_mmi_methods
                               );
    pcVar1 = DAT_00129148;
    if (iVar2 == 0) {
      *(undefined **)(lVar3 + 0x680) = &DAT_00129128;
      if (pcVar1 != (code *)0x0) {
        if (*(int *)(pcVar1 + -4) != -0x643e552a) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x118750);
          (*pcVar1)();
        }
        (*pcVar1)(*(undefined8 *)(*(long *)(lVar3 + 0x100) + 8),lVar3 + 0x698);
      }
      iVar2 = 0;
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to register ts mmi\n");
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// goodix_ts_mmi_dev_unregister @ 001187ac size=80
// signature: undefined goodix_ts_mmi_dev_unregister(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

void goodix_ts_mmi_dev_unregister(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (lVar1 == 0) {
    _printk(&DAT_00127f62,"goodix_ts_mmi_dev_unregister",0x7fd);
  }
  ts_mmi_dev_unregister(*(undefined8 *)(*(long *)(lVar1 + 0x100) + 8));
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_vendor @ 00118800 size=52
// signature: undefined goodix_ts_mmi_methods_get_vendor(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_methods_get_vendor(undefined8 param_1,undefined8 param_2)

{
  scnprintf(param_2,0x10,&DAT_0012084c,"goodix");
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_productinfo @ 00118838 size=160
// signature: undefined goodix_ts_mmi_methods_get_productinfo(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_productinfo(long param_1,undefined8 param_2)

{
  char *pcVar1;
  undefined8 uVar2;
  undefined *puVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar4 != 0) {
      pcVar1 = (char *)(lVar4 + 0x108);
      if (pcVar1 != (char *)0x0) {
        pcVar1 = strchr(pcVar1,0x2c);
        uVar2 = scnprintf(param_2,0x10,&DAT_0012084c,pcVar1 + 1);
        return uVar2;
      }
      puVar3 = &DAT_0012461c;
      uVar2 = 0x49e;
      goto LAB_001188cc;
    }
    puVar3 = &DAT_00127f62;
  }
  uVar2 = 0x49a;
LAB_001188cc:
  _printk(puVar3,"goodix_ts_mmi_methods_get_productinfo",uVar2);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_build_id @ 001188dc size=260
// signature: undefined goodix_ts_mmi_methods_get_build_id(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_methods_get_build_id(long param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      pcVar4 = *(code **)(*(long *)(lVar2 + 0x2d0) + 0x38);
      if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118944);
        (*pcVar4)();
      }
      iVar1 = (*pcVar4)(lVar2,0x10076,&local_2c,4);
      if (iVar1 == 0) {
        iVar1 = snprintf(param_2,0x10,"%04x",(ulong)local_2c);
      }
      else {
        _printk(&DAT_0011fba1,"goodix_ts_mmi_methods_get_build_id",0x4b4,iVar1);
        iVar1 = -0x16;
      }
      goto LAB_00118964;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_mmi_methods_get_build_id",0x4af);
  iVar1 = -0x13;
LAB_00118964:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_config_id @ 001189e4 size=272
// signature: undefined goodix_ts_mmi_methods_get_config_id(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_methods_get_config_id(long param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      pcVar4 = *(code **)(*(long *)(lVar2 + 0x2d0) + 0x38);
      if (*(int *)(pcVar4 + -4) != 0x493f7c6f) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118a4c);
        (*pcVar4)();
      }
      iVar1 = (*pcVar4)(lVar2,0x1007e,&local_2c,4);
      if (iVar1 == 0) {
        iVar1 = snprintf(param_2,0x10,"%02x%02x%02x%02x",local_2c & 0xff,local_2c >> 8 & 0xff,
                         local_2c >> 0x10 & 0xff,local_2c >> 0x18);
      }
      else {
        _printk(&DAT_0011fba1,"goodix_ts_mmi_methods_get_config_id",0x4c8,iVar1);
        iVar1 = -0x16;
      }
      goto LAB_00118a78;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_mmi_methods_get_config_id",0x4c3);
  iVar1 = -0x13;
LAB_00118a78:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(iVar1);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_bus_type @ 00118af8 size=108
// signature: undefined goodix_ts_mmi_methods_get_bus_type(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_bus_type(long param_1,uint *param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      *param_2 = (uint)(**(int **)(lVar2 + 0x100) != 0);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_mmi_methods_get_bus_type",0x4d4);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_irq_status @ 00118b68 size=152
// signature: undefined goodix_ts_mmi_methods_get_irq_status(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_irq_status(long param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar4 != 0) {
      if (lVar4 != -0x108) {
        gpio_to_desc(*(undefined4 *)(lVar4 + 0x1cc));
        uVar1 = gpiod_get_raw_value();
        *param_2 = uVar1;
        return 0;
      }
      puVar2 = &DAT_0012461c;
      uVar3 = 0x4e4;
      goto LAB_00118bf4;
    }
    puVar2 = &DAT_00127f62;
  }
  uVar3 = 0x4e0;
LAB_00118bf4:
  _printk(puVar2,"goodix_ts_mmi_methods_get_irq_status",uVar3);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_drv_irq @ 00118c04 size=96
// signature: undefined goodix_ts_mmi_methods_get_drv_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_drv_irq(long param_1,undefined4 *param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      *param_2 = *(undefined4 *)(lVar2 + 0x4cc);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_mmi_methods_get_drv_irq",0x4ef);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_poweron @ 00118c68 size=96
// signature: undefined goodix_ts_mmi_methods_get_poweron(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_poweron(long param_1,undefined4 *param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      *param_2 = *(undefined4 *)(lVar2 + 0x4a0);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_mmi_methods_get_poweron",0x4f9);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_flashprog @ 00118ccc size=96
// signature: undefined goodix_ts_mmi_methods_get_flashprog(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_get_flashprog(long param_1,undefined4 *param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      *param_2 = *(undefined4 *)(lVar2 + 0x690);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_mmi_methods_get_flashprog",0x503);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_get_active_region @ 00118d30 size=104
// signature: undefined goodix_ts_mmi_methods_get_active_region(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 goodix_ts_mmi_methods_get_active_region(long param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  uVar1 = _DAT_0012a9f4;
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    if (*(long *)(*(long *)(param_1 + 0x98) + 0xa8) != 0) {
      *param_2 = _rdArray;
      param_2[1] = uVar1;
      return 0;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_methods_get_active_region",0x75b);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_reset @ 00118d9c size=128
// signature: undefined goodix_ts_mmi_methods_reset(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_reset(long param_1)

{
  long lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  code *pcVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar1 != 0) {
      pcVar4 = *(code **)(*(long *)(lVar1 + 0x2d0) + 0x28);
      if (pcVar4 == (code *)0x0) {
        return 0xffffffed;
      }
      if (*(int *)(pcVar4 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118de0);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(lVar1,100);
      return uVar2;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_mmi_methods_reset",0x520);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_drv_irq @ 00118e20 size=132
// signature: undefined goodix_ts_mmi_methods_drv_irq(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_drv_irq(long param_1,int param_2)

{
  long lVar1;
  undefined8 uVar2;
  undefined *puVar3;
  code *pcVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar1 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar1 != 0) {
      pcVar4 = *(code **)(*(long *)(lVar1 + 0x2d0) + 0x30);
      if (pcVar4 == (code *)0x0) {
        return 0xffffffed;
      }
      if (*(int *)(pcVar4 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x118e68);
        (*pcVar4)();
      }
      uVar2 = (*pcVar4)(lVar1,param_2 != 0);
      return uVar2;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_mmi_methods_drv_irq",0x50e);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_methods_power @ 00118ea8 size=144
// signature: undefined goodix_ts_mmi_methods_power(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_methods_power(long param_1,int param_2)

{
  undefined8 uVar1;
  undefined *puVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    if (*(long *)(*(long *)(param_1 + 0x98) + 0xa8) != 0) {
      if (param_2 == 0) {
        uVar1 = goodix_ts_power_off();
        return uVar1;
      }
      if (param_2 == 1) {
        uVar1 = goodix_ts_power_on();
        return uVar1;
      }
      _printk(&DAT_0011ea9a,"goodix_ts_mmi_methods_power",0x549);
      return 0xffffffea;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_methods_power",0x542);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_refresh_rate @ 00118f3c size=148
// signature: undefined goodix_ts_mmi_refresh_rate(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_refresh_rate(long param_1,undefined4 param_2)

{
  undefined *puVar1;
  long lVar2;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar2 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar2 != 0) {
      mutex_lock(lVar2 + 0x650);
      *(undefined4 *)(lVar2 + 0x5e0) = param_2;
      if (*(char *)(lVar2 + 0x2ba) != '\0') {
        goodix_ts_mmi_set_report_rate(lVar2);
      }
      mutex_unlock(lVar2 + 0x650);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_mmi_refresh_rate",1000);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_charger_mode @ 00118fd4 size=364
// signature: undefined goodix_ts_mmi_charger_mode(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_charger_mode(long param_1,int param_2)

{
  bool bVar1;
  char *pcVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  undefined *puVar6;
  undefined8 uVar7;
  int *piVar8;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar6 = &DAT_00123fba;
  }
  else {
    piVar8 = *(int **)(*(long *)(param_1 + 0x98) + 0xa8);
    if (piVar8 != (int *)0x0) {
      if (*piVar8 < 3) {
        iVar5 = -99;
        do {
          msleep(100);
          if (2 < *piVar8) break;
          bVar1 = iVar5 != 0;
          iVar5 = iVar5 + 1;
        } while (bVar1);
      }
      mutex_lock(piVar8 + 0x194);
      uStack_40 = 0;
      local_48 = (ulong)CONCAT14((char)param_2,0xaf050000);
      if (*(int *)(*(code **)(*(long *)(piVar8 + 0xb4) + 0x48) + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x1190ac);
        (*pcVar4)();
      }
      iVar5 = (**(code **)(*(long *)(piVar8 + 0xb4) + 0x48))(piVar8,&local_48);
      if (iVar5 < 0) {
        _printk(&DAT_0012191f,"goodix_ts_mmi_charger_mode",0x55f);
      }
      msleep(0x14);
      pcVar2 = "Disable";
      if (param_2 != 0) {
        pcVar2 = "Enable";
      }
      _printk(&DAT_0011f02a,"goodix_ts_mmi_charger_mode",0x562,pcVar2);
      mutex_unlock(piVar8 + 0x194);
      uVar7 = 0;
      goto LAB_00119110;
    }
    puVar6 = &DAT_00127f62;
  }
  _printk(puVar6,"goodix_ts_mmi_charger_mode",0x556);
  uVar7 = 0xffffffed;
LAB_00119110:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar7);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_update_fps_mode @ 00119144 size=148
// signature: undefined goodix_ts_mmi_update_fps_mode(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_update_fps_mode(long param_1,int param_2)

{
  char *pcVar1;
  undefined *puVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar3 != 0) {
      pcVar1 = "enable";
      if (param_2 < 1) {
        pcVar1 = "disable";
      }
      *(uint *)(lVar3 + 0x6a8) = (uint)(0 < param_2);
      _printk(&DAT_0012528e,"goodix_ts_mmi_update_fps_mode",0x6fb,pcVar1,param_2);
      return 0;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_update_fps_mode",0x6f8);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_active_region @ 001191dc size=264
// signature: undefined goodix_ts_mmi_active_region(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 goodix_ts_mmi_active_region(long param_1,ulong *param_2)

{
  ulong uVar1;
  int iVar2;
  long lVar3;
  undefined *puVar4;
  undefined4 uVar5;
  code *pcVar6;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar4 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar3 != 0) {
      _rdArray = *param_2;
      uVar1 = param_2[1];
      if ((int)uVar1 < 1) {
        DAT_0012a9f8 = (int)(uVar1 >> 0x20);
        if (DAT_0012a9f8 == 0xbb0) {
          uVar5 = 4;
        }
        else if (DAT_0012a9f8 < 0xa29) {
          uVar5 = 1;
          if (DAT_0012a9f8 < 0x7bd) {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 3;
      }
      pcVar6 = *(code **)(*(long *)(lVar3 + 0x2d0) + 0x90);
      _DAT_0012a9f4 = uVar1;
      if (*(int *)(pcVar6 + -4) != -0x23603e42) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x119274);
        (*pcVar6)();
      }
      iVar2 = (*pcVar6)(lVar3,uVar5);
      if (iVar2 == 0) {
        _printk(&DAT_00124693,"goodix_ts_mmi_active_region",0x74e,_rdArray & 0xffffffff,DAT_0012a9f0
                ,_DAT_0012a9f4 & 0xffffffff,DAT_0012a9f8,uVar5);
      }
      return 0;
    }
    puVar4 = &DAT_00127f62;
  }
  _printk(puVar4,"goodix_ts_mmi_active_region",0x73b);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_update_liquid_detect_mode @ 001192e8 size=428
// signature: undefined goodix_ts_mmi_update_liquid_detect_mode(void)
// callers: []
//------------------------------------------------------------

int goodix_ts_mmi_update_liquid_detect_mode(long param_1,int param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar5 != 0) {
      mutex_lock(lVar5 + 0x650);
      *(int *)(lVar5 + 0x644) = param_2;
      if (*(int *)(lVar5 + 0x614) == param_2) {
        if (debug_log_flag != '\0') {
          _printk(&DAT_00121df2,"goodix_ts_mmi_update_liquid_detect_mode",0x70a,param_2);
        }
LAB_0011937c:
        iVar1 = 0;
      }
      else {
        if (*(int *)(lVar5 + 0x4a0) == 0) {
          if (debug_log_flag != '\0') {
            _printk(&DAT_001225c7,"goodix_ts_mmi_update_liquid_detect_mode",0x70f);
          }
          goto LAB_0011937c;
        }
        if (param_2 != 0) {
          *(undefined4 *)(lVar5 + 0x4c8) = 0;
        }
        uStack_40 = 0;
        pcVar4 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
        local_48 = (ulong)CONCAT14((char)param_2,0x33050000);
        if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x119424);
          (*pcVar4)();
        }
        iVar1 = (*pcVar4)(lVar5,&local_48);
        if (iVar1 < 0) {
          puVar2 = &DAT_00121124;
          uVar3 = 0x71a;
        }
        else {
          *(int *)(lVar5 + 0x614) = param_2;
          msleep(0x14);
          puVar2 = &DAT_00121162;
          uVar3 = 0x720;
        }
        _printk(puVar2,"goodix_ts_mmi_update_liquid_detect_mode",uVar3,param_2);
      }
      mutex_unlock(lVar5 + 0x650);
      goto LAB_00119388;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_update_liquid_detect_mode",0x705);
  iVar1 = -0x13;
LAB_00119388:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// goodix_ts_firmware_update @ 00119498 size=240
// signature: undefined goodix_ts_firmware_update(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_firmware_update(long param_1,undefined8 param_2)

{
  undefined *puVar1;
  undefined8 uVar2;
  code *pcVar3;
  long lVar4;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar1 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar4 != 0) {
      _printk(&DAT_00120def,"goodix_ts_firmware_update",0x52e,param_2);
      pcVar3 = *(code **)(lVar4 + 0x688);
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != 0x421d93ee) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x119534);
          (*pcVar3)();
        }
        (*pcVar3)(param_2);
      }
      if (*(char *)(lVar4 + 0x2c2) == '\0') {
        _printk(&DAT_001252bb,"goodix_ts_firmware_update",0x534);
        uVar2 = goodix_do_fw_update(*(undefined8 *)(lVar4 + 0x430),0x43);
        if ((int)uVar2 == 0) {
          return uVar2;
        }
      }
      _printk(&DAT_00121ab8,"goodix_ts_firmware_update",0x539);
      return 0;
    }
    puVar1 = &DAT_00127f62;
  }
  _printk(puVar1,"goodix_ts_firmware_update",0x52c);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_extend_attribute_group @ 0011958c size=780
// signature: undefined goodix_ts_mmi_extend_attribute_group(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 goodix_ts_mmi_extend_attribute_group(long param_1,undefined8 *param_2)

{
  bool bVar1;
  char cVar2;
  code *pcVar3;
  undefined *puVar4;
  ulong uVar5;
  uint uVar6;
  long lVar7;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar4 = &DAT_00123fba;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar7 != 0) {
      bVar1 = *(char *)(lVar7 + 0x2bd) != '\0';
      if (bVar1) {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",0,
                  &dev_attr_edge);
        ext_attributes = &dev_attr_edge;
      }
      uVar5 = (ulong)bVar1;
      if (*(char *)(lVar7 + 0x2ba) == '\0') {
        cVar2 = *(char *)(lVar7 + 699);
      }
      else {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                  &dev_attr_interpolation);
        (&ext_attributes)[uVar5] = &dev_attr_interpolation;
        uVar5 = (ulong)(bVar1 + 1);
        cVar2 = *(char *)(lVar7 + 699);
      }
      if (cVar2 == '\0') {
        cVar2 = *(char *)(lVar7 + 0x2b6);
      }
      else {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                  &dev_attr_sample);
        (&ext_attributes)[uVar5] = &dev_attr_sample;
        uVar5 = (ulong)((int)uVar5 + 1);
        cVar2 = *(char *)(lVar7 + 0x2b6);
      }
      if ((cVar2 == '\0') && (*(char *)(lVar7 + 0x2b7) == '\0')) {
        cVar2 = *(char *)(lVar7 + 0x2b5);
      }
      else {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                  &dev_attr_stylus_mode);
        (&ext_attributes)[uVar5] = &dev_attr_stylus_mode;
        uVar5 = (ulong)((int)uVar5 + 1);
        cVar2 = *(char *)(lVar7 + 0x2b5);
      }
      if (cVar2 == '\0') {
        cVar2 = *(char *)(lVar7 + 0x2bf);
      }
      else {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                  &dev_attr_sensitivity);
        (&ext_attributes)[uVar5] = &dev_attr_sensitivity;
        uVar5 = (ulong)((int)uVar5 + 1);
        cVar2 = *(char *)(lVar7 + 0x2bf);
      }
      if (cVar2 != '\0') {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                  &dev_attr_stowed);
        (&ext_attributes)[uVar5] = &dev_attr_stowed;
        uVar5 = (ulong)((int)uVar5 + 1);
      }
      _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar5,
                &dev_attr_hardware_status);
      (&ext_attributes)[uVar5] = &dev_attr_hardware_status;
      uVar6 = (int)uVar5 + 1;
      if (*(char *)(lVar7 + 0x2c1) != '\0') {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar6,
                  &dev_attr_pocket_mode);
        (&ext_attributes)[uVar6] = &dev_attr_pocket_mode;
        uVar6 = (int)uVar5 + 2;
      }
      if (*(char *)(lVar7 + 0x2be) != '\0') {
        _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar6,
                  &dev_attr_pitch);
        (&ext_attributes)[uVar6] = &dev_attr_pitch;
        uVar6 = uVar6 + 1;
      }
      _dev_info(param_1,"%s: [%d] adding %p\n","goodix_ts_mmi_extend_attribute_group",uVar6,
                &dev_attr_timestamp);
      (&ext_attributes)[uVar6] = &dev_attr_timestamp;
      if (8 < uVar6) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x119894);
        (*pcVar3)();
      }
      if (uVar6 + 1 == 10) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(1,0x119898);
        (*pcVar3)();
      }
      (&ext_attributes)[uVar6 + 1] = (undefined **)0x0;
      *param_2 = ext_attr_group;
      return 0;
    }
    puVar4 = &DAT_00127f62;
  }
  _printk(puVar4,"goodix_ts_mmi_extend_attribute_group",0xa4);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_panel_state @ 0011989c size=1060
// signature: undefined goodix_ts_mmi_panel_state(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_panel_state(long param_1,undefined8 param_2,int param_3)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined *puVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  byte local_5c [4];
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar7 = sp_el0;
  local_48 = *(long *)(lVar7 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar6 = &DAT_00123fba;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar7 != 0) {
      if (param_3 == 0) {
        uVar5 = 0;
        *(undefined4 *)(lVar7 + 0x694) = 0;
      }
      else {
        lVar8 = *(long *)(lVar7 + 0x2d0);
        if (param_3 == 2) {
          pcVar1 = *(code **)(lVar8 + 0x10);
          if (pcVar1 != (code *)0x0) {
            if (*(int *)(pcVar1 + -4) != 0x1c1b2b73) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119a3c);
              (*pcVar1)();
            }
            (*pcVar1)(lVar7);
          }
          if (*(int *)(lVar7 + 0x694) != 0) {
            *(undefined4 *)(lVar7 + 0x694) = 0;
            if (*(int *)(*(code **)(lVar8 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119a70);
              (*pcVar1)();
            }
            (**(code **)(lVar8 + 0x30))(lVar7,1);
          }
          uVar5 = 0;
        }
        else if (param_3 == 1) {
          if (*(int *)(*(code **)(lVar8 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119914);
            (*pcVar1)();
          }
          (**(code **)(lVar8 + 0x30))(lVar7,0);
          uVar5 = 0;
          if (*(long *)(lVar8 + 0x20) != 0) {
            local_5c[0] = 0;
            lVar9 = *(long *)(lVar7 + 0x2d0);
            iVar3 = *(int *)(*(long *)(lVar7 + 0x100) + 4);
            if (iVar3 - 5U < 2) {
              if ((*(long *)(lVar7 + 0x680) == 0) ||
                 (pcVar1 = *(code **)(*(long *)(lVar7 + 0x680) + 8), pcVar1 == (code *)0x0)) {
                uVar4 = 0xffff;
                if (iVar3 != 6) {
                  uVar4 = 0;
                }
              }
              else {
                if (*(int *)(pcVar1 + -4) != 0x1c768e29) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)SoftwareBreakpoint(0x822a,0x119b7c);
                  (*pcVar1)();
                }
                uVar4 = (*pcVar1)(*(undefined8 *)(*(long *)(lVar7 + 0x100) + 8),local_5c);
                _printk(&DAT_00126908,"goodix_berlin_gesture_setup",0x589,local_5c[0],uVar4);
                bVar2 = *(int *)(*(long *)(lVar7 + 0x100) + 4) != 6;
                pcVar1 = clear_bit_in_pos;
                if (bVar2) {
                  pcVar1 = set_bit_in_pos;
                }
                uVar4 = 0xffff;
                if (bVar2) {
                  uVar4 = 0;
                }
                if ((local_5c[0] & 1) != 0) {
                  if (*(int *)(pcVar1 + -4) != -0x7d9f60e5) {
                    /* WARNING: Does not return */
                    pcVar1 = (code *)SoftwareBreakpoint(0x8237,0x119bfc);
                    (*pcVar1)();
                  }
                  uVar4 = (*pcVar1)(uVar4,0xd);
                  _printk(&DAT_00125c64,"goodix_berlin_gesture_setup",0x591,uVar4);
                }
                if ((local_5c[0] >> 1 & 1) != 0) {
                  if (*(int *)(pcVar1 + -4) != -0x7d9f60e5) {
                    /* WARNING: Does not return */
                    pcVar1 = (code *)SoftwareBreakpoint(0x8237,0x119c48);
                    (*pcVar1)();
                  }
                  uVar4 = (*pcVar1)(uVar4,0xc);
                  _printk(&DAT_001284d5,"goodix_berlin_gesture_setup",0x595,uVar4);
                }
                if ((local_5c[0] >> 2 & 1) != 0) {
                  if (*(int *)(pcVar1 + -4) != -0x7d9f60e5) {
                    /* WARNING: Does not return */
                    pcVar1 = (code *)SoftwareBreakpoint(0x8237,0x119c94);
                    (*pcVar1)();
                  }
                  uVar4 = (*pcVar1)(uVar4,7);
                  _printk(&DAT_00124d97,"goodix_berlin_gesture_setup",0x599,uVar4);
                }
              }
              *(short *)(lVar7 + 0x6b8) = (short)uVar4;
              if (*(int *)(*(long *)(lVar7 + 0x100) + 4) == 6) {
                uStack_50 = 0;
                pcVar1 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
                local_58 = 0xffffa6060000;
                if (*(int *)(pcVar1 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1199a4);
                  (*pcVar1)();
                }
                iVar3 = (*pcVar1)(lVar7,&local_58);
                if (iVar3 < 0) {
                  _printk(&DAT_00122688,"goodix_berlin_gesture_setup",0x5a7);
                }
              }
              pcVar1 = *(code **)(lVar9 + 0x20);
              if (*(int *)(pcVar1 + -4) != -0x24847470) {
                    /* WARNING: Does not return */
                pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1199e8);
                (*pcVar1)();
              }
              (*pcVar1)(lVar7,uVar4);
              _printk(&DAT_00125310,"goodix_berlin_gesture_setup",0x5b1,uVar4);
            }
            else {
              _printk(&DAT_0011da14,"goodix_berlin_gesture_setup",0x583,lVar7 + 0x1a);
            }
            msleep(0x10);
            if (*(int *)(*(code **)(lVar8 + 0x30) + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x119b40);
              (*pcVar1)();
            }
            (**(code **)(lVar8 + 0x30))(lVar7,1);
            irq_set_irq_wake(*(undefined4 *)(lVar7 + 0x4b8),1);
            uVar5 = 0;
            *(undefined4 *)(lVar7 + 0x694) = 1;
          }
        }
        else {
          _printk(&DAT_0011fc5d,"goodix_ts_mmi_panel_state",0x5db);
          uVar5 = 0xffffffea;
        }
      }
      goto LAB_00119aa4;
    }
    puVar6 = &DAT_00127f62;
  }
  _printk(puVar6,"goodix_ts_mmi_panel_state",0x5bd);
  uVar5 = 0xffffffed;
LAB_00119aa4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_pre_resume @ 00119cc4 size=312
// signature: undefined goodix_ts_mmi_pre_resume(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_pre_resume(long param_1)

{
  int iVar1;
  undefined1 auVar2 [16];
  undefined *puVar3;
  long lVar4;
  code *pcVar5;
  long lVar6;
  
  _printk(&DAT_00126e92,"goodix_ts_mmi_pre_resume",0x5e7);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar6 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar6 != 0) {
      *(undefined4 *)(lVar6 + 0x4d0) = 0;
      *(undefined4 *)(lVar6 + 0x4d4) = 0;
      if (*(int *)(lVar6 + 0x694) == 0) {
        lVar4 = ktime_get();
        *(long *)(lVar6 + 0x4b0) = lVar4;
        auVar2 = SEXT816(lVar4 - *(long *)(lVar6 + 0x4a8)) * SEXT816(0x431bde82d7b634db);
        iVar1 = (int)(auVar2._8_8_ >> 0x12) - (auVar2._12_4_ >> 0x1f);
        _printk(&DAT_0012473a,"goodix_ts_mmi_pre_resume",0x5f2,iVar1);
        if (iVar1 - 1U < 99) {
          msleep(100 - iVar1);
          *(undefined8 *)(lVar6 + 0x4a8) = 0;
          *(undefined8 *)(lVar6 + 0x4b0) = 0;
          return 0;
        }
      }
      else {
        pcVar5 = *(code **)(*(long *)(lVar6 + 0x2d0) + 0x30);
        if (*(int *)(pcVar5 + -4) != -0x74d0d848) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x119d38);
          (*pcVar5)();
        }
        (*pcVar5)(lVar6,0);
        irq_set_irq_wake(*(undefined4 *)(lVar6 + 0x4b8),0);
      }
      return 0;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_mmi_pre_resume",0x5e8);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_post_resume @ 00119e00 size=1636
// signature: undefined goodix_ts_mmi_post_resume(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_post_resume(long param_1)

{
  char cVar1;
  int iVar2;
  undefined8 uVar3;
  undefined *puVar4;
  char *pcVar5;
  code *pcVar6;
  long lVar7;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar7 = sp_el0;
  local_28 = *(long *)(lVar7 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar4 = &DAT_00123fba;
  }
  else {
    lVar7 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar7 != 0) {
      goodix_ts_blocking_notify(4,0);
      mutex_lock(lVar7 + 0x650);
      *(undefined8 *)(lVar7 + 0x618) = 0;
      *(undefined8 *)(lVar7 + 0x610) = 0;
      *(undefined8 *)(lVar7 + 0x608) = 0;
      *(undefined8 *)(lVar7 + 0x600) = 0;
      *(undefined8 *)(lVar7 + 0x5f8) = 0;
      *(undefined8 *)(lVar7 + 0x5f0) = 0;
      if (((*(char *)(lVar7 + 0x2b6) == '\0') || (*(int *)(lVar7 + 0x628) == 0)) ||
         (iVar2 = goodix_stylus_mode(lVar7), iVar2 != 0)) {
        cVar1 = *(char *)(lVar7 + 0x2ba);
      }
      else {
        pcVar5 = "Disable";
        if (*(int *)(lVar7 + 0x628) != 0) {
          pcVar5 = "Enable";
        }
        *(int *)(lVar7 + 0x5f8) = *(int *)(lVar7 + 0x628);
        _printk(&DAT_0011e00c,"goodix_ts_mmi_post_resume",0x60f,pcVar5);
        cVar1 = *(char *)(lVar7 + 0x2ba);
      }
      if ((cVar1 != '\0') && (*(int *)(lVar7 + 0x62c) != 0)) {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_4_ = CONCAT13((char)((uint)*(undefined4 *)(lVar7 + 0x634) >> 8),0x50000);
        local_38 = (ulong)CONCAT14((char)*(undefined4 *)(lVar7 + 0x634),(undefined4)local_38);
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x119ed0);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 == 0) {
          *(undefined4 *)(lVar7 + 0x5fc) = *(undefined4 *)(lVar7 + 0x62c);
          *(undefined4 *)(lVar7 + 0x604) = *(undefined4 *)(lVar7 + 0x634);
          msleep(0x14);
          iVar2 = *(int *)(lVar7 + 0x634);
          if (iVar2 < 0xc101) {
            if (iVar2 == 0x9d01) {
              pcVar5 = "REPORT_RATE_240HZ";
            }
            else if (iVar2 == 0x9d02) {
              pcVar5 = "REPORT_RATE_360HZ";
            }
            else {
LAB_0011a428:
              pcVar5 = "REPORT_RATE_120HZ";
              if (iVar2 != 0x9d03) {
                pcVar5 = "Unsupported";
              }
            }
          }
          else if (iVar2 == 0xc101) {
            pcVar5 = "REPORT_RATE_720HZ";
          }
          else if (iVar2 == 0xc102) {
            pcVar5 = "REPORT_RATE_480HZ";
          }
          else {
            if (iVar2 != 0xc103) goto LAB_0011a428;
            pcVar5 = "REPORT_RATE_576HZ";
          }
          _printk(&DAT_001226bf,"goodix_ts_mmi_post_resume",0x623,pcVar5);
        }
      }
      if ((*(char *)(lVar7 + 699) == '\0') || (*(int *)(lVar7 + 0x630) == 0)) {
LAB_00119f28:
        cVar1 = *(char *)(lVar7 + 0x2b9);
      }
      else {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(int *)(lVar7 + 0x630),0xc2050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x119f20);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 != 0) goto LAB_00119f28;
        *(undefined4 *)(lVar7 + 0x600) = *(undefined4 *)(lVar7 + 0x630);
        msleep(0x14);
        _printk(&DAT_001232aa,"goodix_ts_mmi_post_resume",0x62d,*(undefined4 *)(lVar7 + 0x630));
        cVar1 = *(char *)(lVar7 + 0x2b9);
      }
      if ((cVar1 != '\0') && (*(int *)(lVar7 + 0x624) != 0)) {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(int *)(lVar7 + 0x624),0x26050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x119f70);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 == 0) {
          *(undefined4 *)(lVar7 + 0x5f4) = *(undefined4 *)(lVar7 + 0x624);
          msleep(0x14);
          pcVar5 = "Disable";
          if (*(int *)(lVar7 + 0x624) != 0) {
            pcVar5 = "Enable";
          }
          _printk(&DAT_00121201,"goodix_ts_mmi_post_resume",0x637,pcVar5);
        }
      }
      if ((*(char *)(lVar7 + 0x2b8) == '\0') || (*(int *)(lVar7 + 0x620) == 0)) {
LAB_00119fc8:
        cVar1 = *(char *)(lVar7 + 0x2bd);
      }
      else {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(int *)(lVar7 + 0x620),0x27050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x119fc0);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 != 0) goto LAB_00119fc8;
        *(undefined4 *)(lVar7 + 0x5f0) = *(undefined4 *)(lVar7 + 0x620);
        msleep(0x14);
        pcVar5 = "Disable";
        if (*(int *)(lVar7 + 0x620) != 0) {
          pcVar5 = "Enable";
        }
        _printk(&DAT_001222a2,"goodix_ts_mmi_post_resume",0x641,pcVar5);
        cVar1 = *(char *)(lVar7 + 0x2bd);
      }
      if (cVar1 != '\0') {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(undefined4 *)(lVar7 + 0x638),0x17060000);
        local_38 = (ulong)CONCAT15((char)*(undefined4 *)(lVar7 + 0x63c),(uint5)local_38);
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x11a014);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 == 0) {
          *(undefined8 *)(lVar7 + 0x608) = *(undefined8 *)(lVar7 + 0x638);
          msleep(0x14);
          _printk(&DAT_0011f61d,"goodix_ts_mmi_post_resume",0x64d,*(undefined4 *)(lVar7 + 0x63c),
                  *(undefined4 *)(lVar7 + 0x638));
        }
      }
      if ((*(char *)(lVar7 + 0x2be) == '\0') || (*(int *)(lVar7 + 0x640) == 0)) {
LAB_0011a06c:
        iVar2 = *(int *)(lVar7 + 0x644);
      }
      else {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(int *)(lVar7 + 0x640),0x29050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x11a064);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 != 0) goto LAB_0011a06c;
        *(undefined4 *)(lVar7 + 0x610) = *(undefined4 *)(lVar7 + 0x640);
        msleep(0x14);
        _printk(&DAT_001222ce,"goodix_ts_mmi_post_resume",0x656,*(undefined4 *)(lVar7 + 0x640));
        iVar2 = *(int *)(lVar7 + 0x644);
      }
      if (iVar2 != 0) {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)iVar2,0x33050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x11a0ac);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 == 0) {
          *(undefined4 *)(lVar7 + 0x614) = *(undefined4 *)(lVar7 + 0x644);
          msleep(0x14);
          _printk(&DAT_00122ce3,"goodix_ts_mmi_post_resume",0x66b,*(undefined4 *)(lVar7 + 0x644));
        }
      }
      if (*(char *)(lVar7 + 0x2bf) != '\0') {
        *(undefined4 *)(lVar7 + 0x618) = 0;
      }
      if ((*(char *)(lVar7 + 0x2c1) != '\0') && (*(int *)(lVar7 + 0x64c) != 0)) {
        uStack_30 = 0;
        pcVar6 = *(code **)(*(long *)(lVar7 + 0x2d0) + 0x48);
        local_38._0_5_ = CONCAT14((char)*(int *)(lVar7 + 0x64c),0x63050000);
        local_38 = (ulong)(uint5)local_38;
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x11a108);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7,&local_38);
        if (iVar2 == 0) {
          pcVar5 = "Disable";
          if (*(int *)(lVar7 + 0x64c) != 0) {
            pcVar5 = "Enable";
          }
          *(int *)(lVar7 + 0x61c) = *(int *)(lVar7 + 0x64c);
          _printk(&DAT_0011f5ef,"goodix_ts_mmi_post_resume",0x687,pcVar5);
        }
      }
      mutex_unlock(lVar7 + 0x650);
      if (*(int *)(lVar7 + 0x6a4) != 0) {
        _printk(&DAT_001232d9,"goodix_ts_mmi_post_resume",0x698,*(undefined4 *)(lVar7 + 0x6a8));
      }
      uVar3 = 0;
      *(undefined4 *)(lVar7 + 0x6a4) = 0;
      goto LAB_0011a128;
    }
    puVar4 = &DAT_00127f62;
  }
  _printk(puVar4,"goodix_ts_mmi_post_resume",0x602);
  uVar3 = 0xffffffed;
LAB_0011a128:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_pre_suspend @ 0011a468 size=224
// signature: undefined goodix_ts_mmi_pre_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_mmi_pre_suspend(long param_1)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_00122d1c,"goodix_ts_mmi_pre_suspend",0x6ac);
      *(undefined4 *)(lVar3 + 0x4d0) = 1;
      if ((*(char *)(lVar3 + 0x2b6) != '\0') && (*(int *)(lVar3 + 0x5f8) != 0)) {
        mutex_lock(lVar3 + 0x650);
        iVar1 = goodix_stylus_mode(lVar3,0);
        if (iVar1 == 0) {
          _printk(&DAT_00125c9d,"goodix_ts_mmi_pre_suspend",0x6ca);
          *(undefined4 *)(lVar3 + 0x5f8) = 0;
        }
        mutex_unlock(lVar3 + 0x650);
      }
      goodix_ts_blocking_notify(3,0);
      return 0;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_pre_suspend",0x6aa);
  return 0xffffffed;
}



//------------------------------------------------------------
// goodix_ts_mmi_post_suspend @ 0011a54c size=336
// signature: undefined goodix_ts_mmi_post_suspend(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_mmi_post_suspend(long param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  code *pcVar4;
  long lVar5;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar5 = sp_el0;
  local_28 = *(long *)(lVar5 + 0x638);
  if (*(long *)(param_1 + 0x98) == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(*(long *)(param_1 + 0x98) + 0xa8);
    if (lVar5 != 0) {
      goodix_ts_release_connects(lVar5);
      *(undefined4 *)(lVar5 + 0x4d4) = 1;
      mutex_lock(lVar5 + 0x650);
      if (*(char *)(lVar5 + 0x2bf) != '\0') {
        if (*(int *)(lVar5 + 0x648) != 0) {
          uStack_30 = 0;
          pcVar4 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
          local_38 = (ulong)CONCAT14((char)*(int *)(lVar5 + 0x648),0x97050000);
          if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
            pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x11a60c);
            (*pcVar4)();
          }
          iVar1 = (*pcVar4)(lVar5,&local_38);
          if (iVar1 < 0) {
            puVar2 = &DAT_0011e629;
            uVar3 = 0x6e8;
          }
          else {
            puVar2 = &DAT_0011fc94;
            uVar3 = 0x6eb;
            *(undefined4 *)(lVar5 + 0x618) = *(undefined4 *)(lVar5 + 0x648);
          }
          _printk(puVar2,"goodix_ts_mmi_post_suspend",uVar3);
        }
      }
      mutex_unlock(lVar5 + 0x650);
      _printk(&DAT_00124dd2,"goodix_ts_mmi_post_suspend",0x6f0);
      uVar3 = 0;
      goto LAB_0011a670;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_mmi_post_suspend",0x6df);
  uVar3 = 0xffffffed;
LAB_0011a670:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_mmi_set_report_rate @ 0011a69c size=700
// signature: undefined goodix_ts_mmi_set_report_rate(void)
// callers: [goodix_ts_mmi_refresh_rate, goodix_ts_interpolation_store]
//------------------------------------------------------------

int goodix_ts_mmi_set_report_rate(long param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  code *pcVar5;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  uVar2 = goodix_ts_mmi_get_report_rate();
  if (uVar2 == 0xffffffff) {
    iVar3 = -0x16;
    goto LAB_0011a730;
  }
  *(uint *)(param_1 + 0x634) = uVar2;
  if (*(uint *)(param_1 + 0x604) == uVar2) {
    if (debug_log_flag != '\0') {
      _printk(&DAT_00121df2,"goodix_ts_mmi_set_report_rate",0x1ff,uVar2);
    }
  }
  else {
    if (*(int *)(param_1 + 0x4a0) != 0) {
      if (((*(uint *)(param_1 + 0x604) & 0xff00) == 0xc100) && ((uVar2 & 0xff00) == 0x9d00)) {
        _printk(&DAT_001236b1,"goodix_ts_mmi_set_report_rate",0x20b);
        uStack_40 = 0;
        pcVar5 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
        local_48 = 0xc1050000;
        if (*(int *)(pcVar5 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a7d0);
          (*pcVar5)();
        }
        iVar3 = (*pcVar5)(param_1,&local_48);
        if (iVar3 < 0) {
          _printk(&DAT_00124d23,"goodix_ts_mmi_set_report_rate",0x20f);
          iVar3 = -0x16;
          goto LAB_0011a730;
        }
        msleep(0x14);
      }
      uStack_40 = 0;
      pcVar5 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
      local_48 = CONCAT53((uint5)(byte)(uVar2 >> 8),0x50000);
      local_48 = (ulong)CONCAT14((char)uVar2,(undefined4)local_48);
      if (*(int *)(pcVar5 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x11a85c);
        (*pcVar5)();
      }
      iVar3 = (*pcVar5)(param_1,&local_48);
      if (iVar3 < 0) {
        _printk(&DAT_0011eacb,"goodix_ts_mmi_set_report_rate",0x219,uVar2);
        iVar3 = -0x16;
        goto LAB_0011a730;
      }
      msleep(0x14);
      *(uint *)(param_1 + 0x604) = uVar2;
      if ((int)uVar2 < 0xc101) {
        if (uVar2 == 0x9d01) {
          pcVar4 = "REPORT_RATE_220/240HZ";
        }
        else if (uVar2 == 0x9d02) {
          pcVar4 = "REPORT_RATE_300/360HZ";
        }
        else {
LAB_0011a91c:
          pcVar4 = "REPORT_RATE_120/130HZ";
          if (uVar2 != 0x9d03) {
            pcVar4 = "Unsupported";
          }
        }
      }
      else if (uVar2 == 0xc101) {
        pcVar4 = "REPORT_RATE_720HZ";
      }
      else if (uVar2 == 0xc102) {
        pcVar4 = "REPORT_RATE_480HZ";
      }
      else {
        if (uVar2 != 0xc103) goto LAB_0011a91c;
        pcVar4 = "REPORT_RATE_576HZ";
      }
      _printk(&DAT_00122c36,"goodix_ts_mmi_set_report_rate",0x226,pcVar4);
      goto LAB_0011a730;
    }
    if (debug_log_flag != '\0') {
      _printk(&DAT_001225c7,"goodix_ts_mmi_set_report_rate",0x204);
    }
  }
  iVar3 = 0;
LAB_0011a730:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// goodix_ts_edge_show @ 0011a95c size=168
// signature: undefined goodix_ts_edge_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_edge_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_001268b8,"goodix_ts_edge_show",0x453,*(undefined4 *)(lVar3 + 0x60c),
              *(undefined4 *)(lVar3 + 0x608));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x 0x%02x",*(undefined4 *)(lVar3 + 0x60c),
                        *(undefined4 *)(lVar3 + 0x608));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_edge_show",0x450);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_edge_store @ 0011aa08 size=644
// signature: undefined goodix_ts_edge_store(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_edge_store(long param_1,undefined8 param_2,char *param_3,int param_4)

{
  uint uVar1;
  long lVar2;
  ulong uVar3;
  int iVar4;
  undefined *puVar5;
  undefined8 uVar6;
  ulong uVar7;
  undefined4 uVar8;
  long lVar9;
  code *pcVar10;
  ulong uVar11;
  uint local_68 [2];
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  local_68[0] = 0;
  local_68[1] = 0;
  local_60 = 0;
  lVar9 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar9 == 0) {
    puVar5 = &DAT_00123fba;
  }
  else {
    lVar9 = *(long *)(lVar9 + 0xa8);
    if (lVar9 != 0) {
      iVar4 = sscanf(param_3,"%d %d",(int *)local_68,(int *)((ulong)local_68 | 4));
      if (1 < iVar4) {
        if ((local_68[0] < 0xd) && ((0x1c07U >> (ulong)(local_68[0] & 0x1f) & 1) != 0)) {
          uVar1 = *(uint *)(&DAT_0011d3fc + (long)(int)local_68[0] * 4);
          local_60 = CONCAT44(uVar1,(undefined4)local_60);
          if (local_68[1] == 3) {
            uVar8 = 0x40;
LAB_0011aad0:
            local_60 = CONCAT44(uVar1,uVar8);
          }
          else {
            if (local_68[1] == 1) {
              uVar8 = 0x80;
              goto LAB_0011aad0;
            }
            if (local_68[1] != 0) {
              puVar5 = &DAT_001252e0;
              uVar6 = 0x427;
              goto LAB_0011abb4;
            }
            local_60 = (ulong)uVar1 << 0x20;
          }
          mutex_lock(lVar9 + 0x650);
          uVar3 = local_60;
          uVar11 = local_60 >> 0x20;
          *(ulong *)(lVar9 + 0x638) = local_60;
          if (*(ulong *)(lVar9 + 0x608) == local_60) {
            if (debug_log_flag != '\0') {
              puVar5 = &DAT_0012578f;
              uVar6 = 0x42f;
              uVar7 = local_60 & 0xffffffff;
LAB_0011ac80:
              _printk(puVar5,"goodix_ts_edge_store",uVar6,uVar7,uVar11);
            }
LAB_0011ab34:
            iVar4 = param_4;
          }
          else {
            if (*(int *)(lVar9 + 0x4a0) == 0) {
              if (debug_log_flag != '\0') {
                _printk(&DAT_001225c7,"goodix_ts_edge_store",0x435);
              }
              goto LAB_0011ab34;
            }
            uStack_50 = 0;
            local_58 = CONCAT44((uint)local_60 & 0xff,0x17060000);
            pcVar10 = *(code **)(*(long *)(lVar9 + 0x2d0) + 0x48);
            local_58 = (ulong)CONCAT15((char)(local_60 >> 0x20),(undefined5)local_58);
            if (*(int *)(pcVar10 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x11abf8);
              (*pcVar10)();
            }
            iVar4 = (*pcVar10)(lVar9,&local_58);
            if (-1 < iVar4) {
              *(ulong *)(lVar9 + 0x608) = uVar3;
              msleep(0x14);
              puVar5 = &DAT_00124d57;
              uVar6 = 0x443;
              uVar7 = uVar11;
              uVar11 = uVar3 & 0xffffffff;
              goto LAB_0011ac80;
            }
            _printk(&DAT_00122c69,"goodix_ts_edge_store",0x43c);
          }
          mutex_unlock(lVar9 + 0x650);
          lVar9 = (long)iVar4;
          goto LAB_0011ab70;
        }
        puVar5 = &DAT_00122617;
        uVar6 = 0x41c;
LAB_0011abb4:
        _printk(puVar5,"goodix_ts_edge_store",uVar6);
      }
      lVar9 = -0x16;
      goto LAB_0011ab70;
    }
    puVar5 = &DAT_00127f62;
  }
  _printk(puVar5,"goodix_ts_edge_store",0x402);
  lVar9 = -0x13;
LAB_0011ab70:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar9);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_interpolation_show @ 0011ac90 size=160
// signature: undefined goodix_ts_interpolation_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_interpolation_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_00122643,"goodix_ts_interpolation_show",0x252,*(undefined4 *)(lVar3 + 0x5fc));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)(lVar3 + 0x5fc));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_interpolation_show",0x250);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_interpolation_store @ 0011ad34 size=264
// signature: undefined goodix_ts_interpolation_store(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_interpolation_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  undefined8 local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  lVar4 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar4 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(lVar4 + 0xa8);
    if (lVar4 != 0) {
      iVar2 = kstrtoull(param_3,0,&local_40);
      if (iVar2 < 0) {
        _printk(&DAT_001236db);
        lVar4 = -0x16;
      }
      else {
        mutex_lock(lVar4 + 0x650);
        *(int *)(lVar4 + 0x62c) = (int)local_40;
        iVar2 = goodix_ts_mmi_set_report_rate(lVar4);
        if (-1 < iVar2) {
          *(int *)(lVar4 + 0x5fc) = (int)local_40;
          iVar2 = param_4;
        }
        mutex_unlock(lVar4 + 0x650);
        lVar4 = (long)iVar2;
      }
      goto LAB_0011adcc;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_interpolation_store",0x234);
  lVar4 = -0x13;
LAB_0011adcc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_sample_show @ 0011ae40 size=160
// signature: undefined goodix_ts_sample_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_sample_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_00127998,"goodix_ts_sample_show",0x28f,*(undefined4 *)(lVar3 + 0x600));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)(lVar3 + 0x600));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_sample_show",0x28d);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_sample_store @ 0011aee4 size=476
// signature: undefined goodix_ts_sample_store(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_sample_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  long local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  lVar5 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar5 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(lVar5 + 0xa8);
    if (lVar5 != 0) {
      iVar2 = kstrtoull(param_3,0,&local_50);
      if (iVar2 < 0) {
        _printk(&DAT_001236db);
        lVar5 = -0x16;
        goto LAB_0011afa4;
      }
      mutex_lock(lVar5 + 0x650);
      *(int *)(lVar5 + 0x630) = (int)local_50;
      if (local_50 == *(int *)(lVar5 + 0x600)) {
        if (debug_log_flag != '\0') {
          puVar3 = &DAT_00121190;
          uVar4 = 0x26a;
LAB_0011b0b4:
          _printk(puVar3,"goodix_ts_sample_store",uVar4,local_50);
        }
LAB_0011af94:
        iVar2 = param_4;
      }
      else {
        if (*(int *)(lVar5 + 0x4a0) == 0) {
          if (debug_log_flag != '\0') {
            _printk(&DAT_001225c7,"goodix_ts_sample_store",0x270);
          }
          goto LAB_0011af94;
        }
        uStack_40 = 0;
        pcVar6 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
        local_48 = (ulong)CONCAT14((char)local_50,0xc2050000);
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11b048);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar5,&local_48);
        if (-1 < iVar2) {
          *(int *)(lVar5 + 0x600) = (int)local_50;
          msleep(0x14);
          puVar3 = &DAT_0011eb1a;
          uVar4 = 0x27e;
          goto LAB_0011b0b4;
        }
        _printk(&DAT_00124022,"goodix_ts_sample_store",0x278);
      }
      mutex_unlock(lVar5 + 0x650);
      lVar5 = (long)iVar2;
      goto LAB_0011afa4;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_sample_store",0x25f);
  lVar5 = -0x13;
LAB_0011afa4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_stylus_mode_show @ 0011b0c4 size=160
// signature: undefined goodix_ts_stylus_mode_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_stylus_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_0011f061,"goodix_ts_stylus_mode_show",0x1ef,*(undefined4 *)(lVar3 + 0x5f8));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)(lVar3 + 0x5f8));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_stylus_mode_show",0x1ed);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_stylus_mode_store @ 0011b168 size=364
// signature: undefined goodix_ts_stylus_mode_store(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_stylus_mode_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  lVar4 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar4 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(lVar4 + 0xa8);
    if (lVar4 != 0) {
      iVar2 = kstrtoull(param_3,0,&local_40);
      if (iVar2 < 0) {
        _printk(&DAT_001236db);
        lVar4 = -0x16;
      }
      else {
        mutex_lock(lVar4 + 0x650);
        *(int *)(lVar4 + 0x628) = (int)local_40;
        if (local_40 == (long)*(int *)(lVar4 + 0x5f8)) {
          if (debug_log_flag != '\0') {
            _printk(&DAT_0011dfd1,"goodix_ts_stylus_mode_store",0x1d3);
          }
        }
        else if (*(int *)(lVar4 + 0x4a0) == 0) {
          if (debug_log_flag != '\0') {
            _printk(&DAT_001225c7,"goodix_ts_stylus_mode_store",0x1d9);
          }
        }
        else {
          param_4 = goodix_stylus_mode(lVar4,local_40 & 0xffffffff);
          if (param_4 == 0) {
            *(int *)(lVar4 + 0x5f8) = (int)local_40;
          }
        }
        mutex_unlock(lVar4 + 0x650);
        lVar4 = (long)param_4;
      }
      goto LAB_0011b248;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_stylus_mode_store",0x1c2);
  lVar4 = -0x13;
LAB_0011b248:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// goodix_stylus_mode @ 0011b2d4 size=500
// signature: undefined goodix_stylus_mode(void)
// callers: [goodix_ts_mmi_pre_suspend, goodix_ts_mmi_post_resume, goodix_ts_stylus_mode_store]
//------------------------------------------------------------

int goodix_stylus_mode(long param_1,int param_2)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (*(char *)(param_1 + 0x2b7) == '\0') {
    if (param_2 == 0) {
      uStack_40 = 0;
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
      local_48 = 0xa4050000;
      if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b344);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(param_1,&local_48);
      if (iVar3 < 0) {
        _printk(&DAT_00127486,"goodix_stylus_mode",0x1ad);
        goto LAB_0011b494;
      }
      msleep(0x32);
      goodix_clock_enable(param_1,0);
    }
    else {
      goodix_clock_enable(param_1,1);
      msleep(0x32);
      uStack_40 = 0;
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
      local_48._0_5_ = CONCAT14((char)param_2,0xa4050000);
      local_48 = (ulong)(uint5)local_48;
      if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b41c);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(param_1,&local_48);
      if (iVar3 < 0) {
        _printk(&DAT_00127486,"goodix_stylus_mode",0x1a6);
        goto LAB_0011b494;
      }
      msleep(0x14);
    }
  }
  else {
    uStack_40 = 0;
    pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
    local_48._0_5_ = CONCAT14((char)param_2,0x32050000);
    local_48 = (ulong)(uint5)local_48;
    if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b3a4);
      (*pcVar4)();
    }
    iVar3 = (*pcVar4)(param_1,&local_48);
    if (iVar3 < 0) {
      _printk(&DAT_00126e4a,"goodix_stylus_mode",0x19d,param_2);
      goto LAB_0011b494;
    }
  }
  pcVar1 = "Disable";
  if (param_2 != 0) {
    pcVar1 = "Enable";
  }
  _printk(&DAT_0011e00c,"goodix_stylus_mode",0x1b5,pcVar1);
LAB_0011b494:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// goodix_clock_enable @ 0011b4c8 size=600
// signature: undefined goodix_clock_enable(void)
// callers: [goodix_stylus_mode]
//------------------------------------------------------------

void goodix_clock_enable(long param_1,ulong param_2)

{
  char *__s1;
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  if (param_1 == -0x108) {
    puVar2 = &DAT_0012461c;
    uVar3 = 0x159;
    goto LAB_0011b4f8;
  }
  __s1 = (char *)(param_1 + 0x275);
  iVar1 = strcmp(__s1,"stylus_clk_pmic");
  if ((param_2 & 1) == 0) {
    if (iVar1 == 0) {
      uVar4 = *(ulong *)(param_1 + 0x5e8);
      if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
        puVar2 = &DAT_001280f4;
        uVar3 = 0x17d;
        goto LAB_0011b4f8;
      }
      clk_disable(uVar4);
      clk_unprepare(uVar4);
    }
    else {
      iVar1 = strcmp(__s1,"stylus_clk_gpio");
      if (iVar1 != 0) {
        puVar2 = &DAT_00120180;
        uVar3 = 399;
        goto LAB_0011b4f8;
      }
      if ((*(ulong *)(param_1 + 0x498) == 0) || (0xfffffffffffff000 < *(ulong *)(param_1 + 0x498)))
      {
        _printk(&DAT_0011f5b2,"goodix_clock_enable",0x184,"stylus_clk_suspend");
        *(undefined8 *)(param_1 + 0x498) = 0;
        return;
      }
      iVar1 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x478));
      if (iVar1 < 0) {
        _printk(&DAT_001279ba,"goodix_clock_enable",0x18b,iVar1);
        return;
      }
    }
    puVar2 = &DAT_0011d980;
    uVar3 = 0x192;
    goto LAB_0011b4f8;
  }
  if (iVar1 == 0) {
    uVar4 = *(ulong *)(param_1 + 0x5e8);
    if ((uVar4 == 0) || (0xfffffffffffff000 < uVar4)) {
      puVar2 = &DAT_001280f4;
      uVar3 = 0x160;
      goto LAB_0011b4f8;
    }
    iVar1 = clk_prepare(uVar4);
    if (iVar1 == 0) {
      iVar1 = clk_enable(uVar4);
      if (iVar1 == 0) goto LAB_0011b708;
      clk_unprepare(uVar4);
    }
    puVar2 = &DAT_001246d1;
    uVar3 = 0x165;
  }
  else {
    iVar1 = strcmp(__s1,"stylus_clk_gpio");
    if (iVar1 != 0) {
      puVar2 = &DAT_00120180;
      uVar3 = 0x176;
      goto LAB_0011b4f8;
    }
    if ((*(ulong *)(param_1 + 0x490) == 0) || (0xfffffffffffff000 < *(ulong *)(param_1 + 0x490))) {
      _printk(&DAT_0011f5b2,"goodix_clock_enable",0x16b,"stylus_clk_active");
      *(undefined8 *)(param_1 + 0x490) = 0;
      return;
    }
    iVar1 = pinctrl_select_state(*(undefined8 *)(param_1 + 0x478));
    if (iVar1 < 0) {
      _printk(&DAT_00127fb8,"goodix_clock_enable",0x172,iVar1);
      return;
    }
LAB_0011b708:
    puVar2 = &DAT_00122c9c;
    uVar3 = 0x179;
  }
LAB_0011b4f8:
  _printk(puVar2,"goodix_clock_enable",uVar3);
  return;
}



//------------------------------------------------------------
// goodix_ts_sensitivity_store @ 0011b724 size=360
// signature: undefined goodix_ts_sensitivity_store(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_sensitivity_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined *puVar2;
  undefined8 uVar3;
  long lVar4;
  undefined8 local_30;
  long local_28;
  
  lVar4 = sp_el0;
  local_28 = *(long *)(lVar4 + 0x638);
  local_30 = 0;
  lVar4 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar4 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(lVar4 + 0xa8);
    if (lVar4 != 0) {
      iVar1 = kstrtoull(param_3,0,&local_30);
      if (iVar1 < 0) {
        _printk(&DAT_001236db);
        param_4 = -0x16;
        goto LAB_0011b800;
      }
      switch(local_30) {
      case 0:
        if (*(char *)(lVar4 + 0x2b8) != '\0') {
          iVar1 = goodix_ts_film_mode(lVar4,0);
        }
        break;
      case 1:
        if (*(char *)(lVar4 + 0x2b8) != '\0') {
          iVar1 = goodix_ts_film_mode(lVar4,1);
        }
        break;
      default:
        _printk(&DAT_0011fc00,"goodix_ts_sensitivity_store",0x14a);
        goto LAB_0011b800;
      case 0x10:
        if (*(char *)(lVar4 + 0x2b9) != '\0') {
          uVar3 = 0;
LAB_0011b7f0:
          iVar1 = goodix_ts_leather_mode(lVar4,uVar3);
        }
        break;
      case 0x11:
        if (*(char *)(lVar4 + 0x2b9) != '\0') {
          uVar3 = 1;
          goto LAB_0011b7f0;
        }
      }
      if (iVar1 != 0) {
        param_4 = (long)iVar1;
      }
      goto LAB_0011b800;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_sensitivity_store",0x130);
  param_4 = -0x13;
LAB_0011b800:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// goodix_ts_film_mode @ 0011b88c size=388
// signature: undefined goodix_ts_film_mode(void)
// callers: [goodix_ts_sensitivity_store]
//------------------------------------------------------------

int goodix_ts_film_mode(long param_1,int param_2)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  mutex_lock(param_1 + 0x650);
  *(int *)(param_1 + 0x620) = param_2;
  if (*(int *)(param_1 + 0x5f0) == param_2) {
    if (debug_log_flag != '\0') {
      _printk(&DAT_00127ffd,"goodix_ts_film_mode",0xef,param_2);
    }
  }
  else {
    if (*(int *)(param_1 + 0x4a0) != 0) {
      uStack_40 = 0;
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
      local_48 = (ulong)CONCAT14((char)param_2,0x27050000);
      if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11b988);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(param_1,&local_48);
      if (iVar3 < 0) {
        _printk(&DAT_001211cd,"goodix_ts_film_mode",0xfa);
      }
      else {
        *(int *)(param_1 + 0x5f0) = param_2;
        msleep(0x14);
        pcVar1 = "Disable";
        if (param_2 != 0) {
          pcVar1 = "Enable";
        }
        _printk(&DAT_001222a2,"goodix_ts_film_mode",0x100,pcVar1);
      }
      goto LAB_0011b918;
    }
    if (debug_log_flag != '\0') {
      _printk(&DAT_001225c7,"goodix_ts_film_mode",0xf4);
    }
  }
  iVar3 = 0;
LAB_0011b918:
  mutex_unlock(param_1 + 0x650);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// goodix_ts_leather_mode @ 0011ba10 size=388
// signature: undefined goodix_ts_leather_mode(void)
// callers: [goodix_ts_sensitivity_store]
//------------------------------------------------------------

int goodix_ts_leather_mode(long param_1,int param_2)

{
  char *pcVar1;
  long lVar2;
  int iVar3;
  code *pcVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  mutex_lock(param_1 + 0x650);
  *(int *)(param_1 + 0x624) = param_2;
  if (*(int *)(param_1 + 0x5f4) == param_2) {
    if (debug_log_flag != '\0') {
      _printk(&DAT_00127ffd,"goodix_ts_leather_mode",0x10d,param_2);
    }
  }
  else {
    if (*(int *)(param_1 + 0x4a0) != 0) {
      uStack_40 = 0;
      pcVar4 = *(code **)(*(long *)(param_1 + 0x2d0) + 0x48);
      local_48 = (ulong)CONCAT14((char)param_2,0x26050000);
      if (*(int *)(pcVar4 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x11bb0c);
        (*pcVar4)();
      }
      iVar3 = (*pcVar4)(param_1,&local_48);
      if (iVar3 < 0) {
        _printk(&DAT_001211cd,"goodix_ts_leather_mode",0x118);
      }
      else {
        *(int *)(param_1 + 0x5f4) = param_2;
        msleep(0x14);
        pcVar1 = "Disable";
        if (param_2 != 0) {
          pcVar1 = "Enable";
        }
        _printk(&DAT_00121201,"goodix_ts_leather_mode",0x11d,pcVar1);
      }
      goto LAB_0011ba9c;
    }
    if (debug_log_flag != '\0') {
      _printk(&DAT_001225c7,"goodix_ts_leather_mode",0x112);
    }
  }
  iVar3 = 0;
LAB_0011ba9c:
  mutex_unlock(param_1 + 0x650);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// goodix_ts_stowed_show @ 0011bb98 size=160
// signature: undefined goodix_ts_stowed_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_stowed_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_0011fc35,"goodix_ts_stowed_show",0x2d5,*(undefined4 *)(lVar3 + 0x618));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x",*(undefined4 *)(lVar3 + 0x618));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_stowed_show",0x2d3);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_stowed_store @ 0011bc3c size=472
// signature: undefined goodix_ts_stowed_store(void)
// callers: []
//------------------------------------------------------------

void goodix_ts_stowed_store(long param_1,undefined8 param_2,undefined8 param_3,int param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  long local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  lVar5 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar5 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(lVar5 + 0xa8);
    if (lVar5 != 0) {
      iVar2 = kstrtoull(param_3,0,&local_50);
      if (iVar2 < 0) {
        _printk(&DAT_001236db);
        lVar5 = -0x16;
        goto LAB_0011bcd0;
      }
      mutex_lock(lVar5 + 0x650);
      *(int *)(lVar5 + 0x648) = (int)local_50;
      if (local_50 == *(int *)(lVar5 + 0x618)) {
        if (debug_log_flag != '\0') {
          puVar3 = &DAT_00121190;
          uVar4 = 0x2b0;
LAB_0011be08:
          _printk(puVar3,"goodix_ts_stowed_store",uVar4);
        }
LAB_0011bcc0:
        iVar2 = param_4;
      }
      else {
        if ((*(int *)(lVar5 + 0x4d4) != 1) || (*(int *)(lVar5 + 0x4a0) != 1)) {
          _printk(&DAT_0012405c,"goodix_ts_stowed_store",0x2be,*(undefined4 *)(lVar5 + 0x4d4));
          goto LAB_0011bcc0;
        }
        uStack_40 = 0;
        pcVar6 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
        local_48 = (ulong)CONCAT14((char)local_50,0x97050000);
        if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11bd8c);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar5,&local_48);
        if (-1 < iVar2) {
          puVar3 = &DAT_001201b3;
          uVar4 = 0x2c4;
          *(int *)(lVar5 + 0x618) = (int)local_50;
          goto LAB_0011be08;
        }
        _printk(&DAT_0011d9b3,"goodix_ts_stowed_store",0x2b9);
      }
      mutex_unlock(lVar5 + 0x650);
      lVar5 = (long)iVar2;
      goto LAB_0011bcd0;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_stowed_store",0x29c);
  lVar5 = -0x13;
LAB_0011bcd0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// goodix_ts_hardware_status_show @ 0011be18 size=164
// signature: undefined goodix_ts_hardware_status_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_hardware_status_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined *puVar3;
  long lVar4;
  
  lVar4 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar4 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar4 = *(long *)(lVar4 + 0xa8);
    if (lVar4 != 0) {
      uVar1 = *(undefined1 *)(lVar4 + 0x6d8);
      _printk(&DAT_00125c04,"goodix_ts_hardware_status_show",0x3cd,uVar1);
      iVar2 = scnprintf(param_3,0x1000,"0x%02x",uVar1);
      return (long)iVar2;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_hardware_status_show",0x3ca);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_pocket_mode_show @ 0011bec0 size=160
// signature: undefined goodix_ts_pocket_mode_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_pocket_mode_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_0011e03a,"goodix_ts_pocket_mode_show",0x2e2,*(undefined4 *)(lVar3 + 0x61c));
      iVar1 = scnprintf(param_3,0x1000,&DAT_0012011c,*(undefined4 *)(lVar3 + 0x61c));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_pocket_mode_show",0x2e0);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_pocket_mode_store @ 0011bf64 size=616
// signature: undefined goodix_ts_pocket_mode_store(void)
// callers: []
//------------------------------------------------------------

undefined8
goodix_ts_pocket_mode_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  char *pcVar2;
  int iVar3;
  undefined *puVar4;
  long lVar5;
  code *pcVar6;
  undefined8 local_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  lVar5 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar5 == 0) {
    puVar4 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(lVar5 + 0xa8);
    if (lVar5 != 0) {
      lVar1 = lVar5 + 0x650;
      mutex_lock(lVar1);
      iVar3 = kstrtoull(param_3,0,&local_50);
      if (iVar3 < 0) {
        _printk(&DAT_00120202,"goodix_ts_pocket_mode_store",0x2f4);
LAB_0011c03c:
        mutex_unlock(lVar1);
        param_4 = 0xffffffffffffffea;
      }
      else {
        switch(local_50) {
        case 0x10:
        case 0x20:
          _printk(&DAT_00123c1f,"goodix_ts_pocket_mode_store",0x2fb);
          iVar3 = 0;
          break;
        case 0x11:
        case 0x21:
          _printk(&DAT_0011d9e6,"goodix_ts_pocket_mode_store",0x300);
          iVar3 = 1;
          break;
        default:
          _printk(&DAT_00121955,"goodix_ts_pocket_mode_store",0x304);
          goto LAB_0011c03c;
        }
        *(int *)(lVar5 + 0x64c) = iVar3;
        if (*(int *)(lVar5 + 0x61c) == iVar3) {
          _printk(&DAT_0011e5c3,"goodix_ts_pocket_mode_store",0x30a);
        }
        else if (*(int *)(lVar5 + 0x4a0) == 0) {
          _printk(&DAT_001274b9,"goodix_ts_pocket_mode_store",0x30f);
        }
        else {
          uStack_40 = 0;
          pcVar6 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
          local_48 = (ulong)CONCAT14((char)iVar3,0x63050000);
          if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11c154);
            (*pcVar6)();
          }
          iVar3 = (*pcVar6)(lVar5,&local_48);
          if (iVar3 < 0) {
            _printk(&DAT_00123277,"goodix_ts_pocket_mode_store",0x316);
          }
          else {
            *(undefined4 *)(lVar5 + 0x61c) = *(undefined4 *)(lVar5 + 0x64c);
            msleep(0x14);
            pcVar2 = "Disable";
            if (*(int *)(lVar5 + 0x64c) != 0) {
              pcVar2 = "Enable";
            }
            _printk(&DAT_0011f5ef,"goodix_ts_pocket_mode_store",0x31d,pcVar2);
          }
        }
        mutex_unlock(lVar1);
      }
      goto LAB_0011bfcc;
    }
    puVar4 = &DAT_00127f62;
  }
  _printk(puVar4,"goodix_ts_pocket_mode_store",0x2ef);
  param_4 = 0xffffffffffffffed;
LAB_0011bfcc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// goodix_ts_pitch_show @ 0011c1d0 size=160
// signature: undefined goodix_ts_pitch_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_pitch_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      _printk(&DAT_00124702,"goodix_ts_pitch_show",0x32c,*(undefined4 *)(lVar3 + 0x610));
      iVar1 = scnprintf(param_3,0x1000,"0x%02x\n",*(undefined4 *)(lVar3 + 0x610));
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_pitch_show",0x32a);
  return -0x13;
}



//------------------------------------------------------------
// goodix_ts_pitch_store @ 0011c274 size=692
// signature: undefined goodix_ts_pitch_store(void)
// callers: []
//------------------------------------------------------------

undefined8 goodix_ts_pitch_store(long param_1,undefined8 param_2,char *param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined *puVar3;
  undefined8 uVar4;
  long lVar5;
  code *pcVar6;
  int local_50 [2];
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_50[0] = 0;
  local_50[1] = 0;
  lVar5 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar5 == 0) {
    puVar3 = &DAT_00123fba;
  }
  else {
    lVar5 = *(long *)(lVar5 + 0xa8);
    if (lVar5 != 0) {
      lVar1 = lVar5 + 0x650;
      mutex_lock(lVar1);
      iVar2 = sscanf(param_3,"%d %d",local_50,(int *)((ulong)local_50 | 4));
      if (iVar2 < 0) {
        _printk(&DAT_0012804e,"goodix_ts_pitch_store",0x33e);
LAB_0011c358:
        mutex_unlock(lVar1);
        param_4 = 0xffffffffffffffea;
        goto LAB_0011c2dc;
      }
      switch(local_50[0]) {
      case 0x14:
        _printk(&DAT_001240aa,"goodix_ts_pitch_store",0x344);
        iVar2 = 0;
        break;
      case 0x15:
        _printk(&DAT_001208a3,"goodix_ts_pitch_store",0x348);
        iVar2 = 0x20;
        break;
      case 0x16:
        _printk(&DAT_0011e5ff,"goodix_ts_pitch_store",0x34c);
        iVar2 = 0x40;
        break;
      case 0x17:
        _printk(&DAT_00125c3a,"goodix_ts_pitch_store",0x350);
        iVar2 = 0x60;
        break;
      case 0x18:
        _printk(&DAT_00121e8c,"goodix_ts_pitch_store",0x354);
        iVar2 = 0x80;
        break;
      default:
        _printk(&DAT_00121eb6,"goodix_ts_pitch_store",0x358);
        goto LAB_0011c358;
      }
      *(int *)(lVar5 + 0x640) = iVar2;
      if (*(int *)(lVar5 + 0x610) == iVar2) {
        puVar3 = &DAT_00121230;
        uVar4 = 0x35e;
LAB_0011c46c:
        _printk(puVar3,"goodix_ts_pitch_store",uVar4,iVar2);
      }
      else {
        if (*(int *)(lVar5 + 0x4a0) == 0) {
          puVar3 = &DAT_001274b9;
          uVar4 = 0x363;
        }
        else {
          uStack_40 = 0;
          pcVar6 = *(code **)(*(long *)(lVar5 + 0x2d0) + 0x48);
          local_48 = (ulong)CONCAT14((char)iVar2,0x29050000);
          if (*(int *)(pcVar6 + -4) != -0x5f06b416) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x11c4cc);
            (*pcVar6)();
          }
          iVar2 = (*pcVar6)(lVar5,&local_48);
          if (-1 < iVar2) {
            *(undefined4 *)(lVar5 + 0x610) = *(undefined4 *)(lVar5 + 0x640);
            msleep(0x14);
            iVar2 = *(int *)(lVar5 + 0x640);
            puVar3 = &DAT_001222ce;
            uVar4 = 0x371;
            goto LAB_0011c46c;
          }
          puVar3 = &DAT_001284a3;
          uVar4 = 0x36a;
        }
        _printk(puVar3,"goodix_ts_pitch_store",uVar4);
      }
      mutex_unlock(lVar1);
      goto LAB_0011c2dc;
    }
    puVar3 = &DAT_00127f62;
  }
  _printk(puVar3,"goodix_ts_pitch_store",0x339);
  param_4 = 0xffffffffffffffed;
LAB_0011c2dc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// goodix_ts_timestamp_show @ 0011c52c size=180
// signature: undefined goodix_ts_timestamp_show(void)
// callers: []
//------------------------------------------------------------

long goodix_ts_timestamp_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined *puVar2;
  long lVar3;
  undefined8 uVar4;
  undefined1 auVar5 [16];
  
  lVar3 = *(long *)(**(long **)(param_1 + 0x98) + 0x98);
  if (lVar3 == 0) {
    puVar2 = &DAT_00123fba;
  }
  else {
    lVar3 = *(long *)(lVar3 + 0xa8);
    if (lVar3 != 0) {
      mutex_lock(lVar3 + 0x650);
      uVar4 = *(undefined8 *)(lVar3 + 0x6b0);
      *(undefined8 *)(lVar3 + 0x6b0) = 0;
      mutex_unlock(lVar3 + 0x650);
      auVar5 = ns_to_timespec64(uVar4);
      iVar1 = scnprintf(param_3,0x1000,"%lld.%ld\n",auVar5._0_8_,auVar5._8_8_);
      return (long)iVar1;
    }
    puVar2 = &DAT_00127f62;
  }
  _printk(puVar2,"goodix_ts_timestamp_show",0x462);
  return -0x13;
}



//------------------------------------------------------------
// set_bit_in_pos @ 0011c5e4 size=16
// signature: undefined set_bit_in_pos(void)
// callers: [goodix_ts_mmi_panel_state]
//------------------------------------------------------------

uint set_bit_in_pos(uint param_1,uint param_2)

{
  return 1 << (ulong)(param_2 & 0x1f) | param_1;
}



//------------------------------------------------------------
// clear_bit_in_pos @ 0011c5f8 size=16
// signature: undefined clear_bit_in_pos(void)
// callers: []
//------------------------------------------------------------

uint clear_bit_in_pos(uint param_1,uint param_2)

{
  return param_1 & (1 << (ulong)(param_2 & 0x1f) ^ 0xffffffffU);
}



//------------------------------------------------------------
// init_module @ 0012aa54 size=132
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  _printk(&DAT_0012415e,"goodix_ts_core_init",0xba0,"v1.2.3");
  iVar1 = goodix_spi_bus_init();
  if (iVar1 == 0) {
    iVar1 = __platform_driver_register(&goodix_ts_driver,&__this_module);
  }
  else {
    _printk(&DAT_00124185,"goodix_ts_core_init",0xba7);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0012aadc size=64
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  _printk(&DAT_00127ae1,"goodix_ts_core_exit",0xbaf);
  platform_driver_unregister(&goodix_ts_driver);
  goodix_spi_bus_exit();
  return;
}



//------------------------------------------------------------
// _printk @ 0012e000 size=1
// signature: undefined _printk(void)
// callers: [goodix_register_ext_module_work, goodix_fw_update_init, goodix_ts_stylus_mode_show, gsx_single_type_store, goodix_ts_stylus_mode_store, goodix_ts_stowed_store, goodix_fw_update_thread, gsx_single_type_show, goodix_send_ic_config, brl_reset, goodix_ts_mmi_set_report_rate, goodix_ts_stowed_show, gsx_gesture_enable_store, init_module, goodix_spi_read, goodix_ts_mmi_methods_get_config_id, goodix_rotate_abcd2cbad, brl_select_spi_mode, goodix_ts_sample_store, gsx_double_type_show, goodix_tools_init, goodix_ts_mmi_update_fps_mode, goodix_ts_mmi_post_resume, cleanup_module, goodix_ts_mmi_methods_get_active_region, goodix_i2c_read, goodix_ts_power_off, goodix_pdev_release, goodix_gesture_enable, goodix_ts_power_init, goodix_sysfs_fwsize_store, goodix_ts_mmi_active_region, brl_esd_check, goodix_ts_mmi_methods_reset, goodix_ts_pitch_show, gsx_fod_type_show, brl_get_capacitance_data, goodix_sysfs_fwimage_store, read_config_data, goodix_ts_mmi_methods_get_poweron, brl_suspend, brl_send_cmd, goodix_tools_exit, gsx_gesture_ist, goodix_spi_probe, goodix_ts_interpolation_show, gesture_module_init, goodix_tools_open, goodix_ts_mmi_dev_unregister, goodix_ts_mmi_get_report_rate, goodix_pdev_release, goodix_ts_esd_work, goodix_ts_threadirq_func, goodix_ts_mmi_methods_get_bus_type, brl_send_config, log_spi_timeout, goodix_ts_pm_suspend, gsx_fod_type_store, goodix_register_ext_module_no_wait, goodix_ts_interpolation_store, goodix_ts_pocket_mode_show, goodix_spi_read_bra, goodix_ts_mmi_post_suspend, goodix_ts_pitch_store, goodix_ts_get_rawdata_show, goodix_do_inspect, goodix_ts_sample_show, goodix_register_ext_module, goodix_ts_mmi_charger_mode, goodix_start_later_init, brl_irq_enbale, inspect_module_exit, goodix_later_init_thread, goodix_analysis_noisedata, goodix_ts_mmi_panel_state, goodix_unregister_ext_module, goodix_tools_ioctl, is_risk_data, goodix_ts_sensitivity_store, brl_read_config, gsx_gesture_init, parse_csvfile, goodix_spi_write, goodix_ts_esd_init, brld_get_framedata, goodix_ts_mmi_update_liquid_detect_mode, goodix_ts_mmi_methods_get_build_id, goodix_i2c_probe, brl_power_on, gsx_gesture_exit, goodix_get_config_proc, goodix_fw_version_compare, goodix_ts_pm_resume, goodix_ts_mmi_methods_drv_irq, goodix_clock_enable, goodix_esd_notifier_callback, goodix_ts_pocket_mode_store, goodix_ext_sysfs_release, brl_gesture, goodix_i2c_bus_init, gesture_module_exit, goodix_ts_mmi_pre_resume, gsx_gesture_before_suspend, goodix_ts_leather_mode, goodix_ts_mmi_methods_get_drv_irq, goodix_spi_bus_init, goodix_ts_edge_store, goodix_ts_probe, goodix_fw_update_proc, goodix_ts_mmi_pre_suspend, goodix_ts_mmi_methods_get_productinfo, goodix_ts_mmi_refresh_rate, goodix_ts_reg_rw_store, goodix_i2c_write, brl_read_version, goodix_do_fw_update, brl_get_ic_info, check_spi_timeout, goodix_ts_mmi_methods_get_irq_status, goodix_ts_stage2_init, goodix_ts_mmi_methods_power, goodix_ts_timestamp_show, goodix_ts_convert_0x_data, goodix_ts_pinctrl_init, goodix_ts_hardware_status_show, goodix_flash_subsystem, goodix_ts_edge_show, goodix_ts_mmi_extend_attribute_group, goodix_ts_reg_rw_show, goodix_i2c_bus_exit, goodix_ts_remove, goodix_get_ic_type, goodix_ts_power_on, goodix_ts_mmi_dev_register, goodix_generic_noti_callback, brl_event_handler, gsx_double_type_store, send_cfg_cmd, goodix_ts_firmware_update, goodix_ts_mmi_methods_get_flashprog, goodix_ts_send_cfg_store, brl_dev_confirm, goodix_spi_bus_exit, goodix_stylus_mode, goodix_analysis_self_rawdata, goodix_ts_release_connects, total_spi_timeouts_store, inspect_module_init, goodix_tools_module_exit, emergency_restart_work_func, goodix_ts_stylus_clk_init, rawdata_proc_show, goodix_analysis_self_noisedata, restart_work_func, __do_register_ext_module, goodix_sysfs_update_en_store, goodix_ts_film_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_check_dynamic_device_node @ 0012e008 size=1
// signature: undefined mmi_check_dynamic_device_node(void)
// callers: [goodix_i2c_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_check_dynamic_device_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_register_driver @ 0012e010 size=1
// signature: undefined i2c_register_driver(void)
// callers: [goodix_i2c_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_del_driver @ 0012e018 size=1
// signature: undefined i2c_del_driver(void)
// callers: [goodix_i2c_bus_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_del_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mmi_device_is_available @ 0012e020 size=1
// signature: undefined mmi_device_is_available(void)
// callers: [goodix_i2c_probe, goodix_spi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mmi_device_is_available(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0012e030 size=1
// signature: undefined kmalloc_trace(void)
// callers: [goodix_i2c_probe, goodix_tools_init, goodix_get_config_proc, goodix_flash_subsystem, goodix_tools_ioctl, goodix_spi_probe, goodix_ts_read_cfg_show, gesture_module_init, goodix_ts_send_cfg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_register @ 0012e038 size=1
// signature: undefined platform_device_register(void)
// callers: [goodix_i2c_probe, goodix_spi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0012e040 size=1
// signature: undefined kfree(void)
// callers: [goodix_i2c_write, goodix_spi_write, goodix_tools_exit, goodix_fw_update_thread, goodix_spi_probe, goodix_ts_read_cfg_show, goodix_reg_write_confirm, gesture_module_init, goodix_spi_read, goodix_i2c_probe, goodix_pdev_release, goodix_get_config_proc, brl_send_config, goodix_flash_subsystem, goodix_rotate_abcd2cbad, goodix_spi_read_bra, gesture_module_exit, goodix_ts_get_rawdata_show, goodix_ts_remove, goodix_do_inspect, goodix_i2c_read, goodix_pdev_release, goodix_ts_send_cfg_store, goodix_later_init_thread, goodix_tools_ioctl, rawdata_proc_show, read_config_data, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_device_unregister @ 0012e048 size=1
// signature: undefined platform_device_unregister(void)
// callers: [goodix_spi_remove, goodix_i2c_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0012e050 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [goodix_i2c_write, goodix_spi_write, goodix_spi_read_bra, goodix_fw_update_init, brl_get_ic_info, goodix_do_inspect, goodix_i2c_read, goodix_set_fwname, brld_get_framedata, goodix_strncatint, goodix_spi_read, goodix_fw_update_proc, goodix_get_config_proc, goodix_flash_subsystem, goodix_rotate_abcd2cbad, goodix_sysfs_fwimage_store, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// i2c_transfer @ 0012e058 size=1
// signature: undefined i2c_transfer(void)
// callers: [goodix_i2c_write, goodix_i2c_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void i2c_transfer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 0012e060 size=1
// signature: undefined usleep_range_state(void)
// callers: [brl_read_version, brl_get_ic_info, goodix_do_inspect, goodix_i2c_read, brl_reset, brld_get_framedata, brl_dev_confirm, goodix_fw_update_proc, brl_power_on, goodix_ts_esd_work, goodix_flash_subsystem, brl_get_capacitance_data, brl_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0012e068 size=1
// signature: undefined __kmalloc(void)
// callers: [goodix_i2c_write, goodix_spi_write, goodix_spi_read_bra, goodix_do_inspect, goodix_i2c_read, goodix_reg_write_confirm, goodix_spi_read, goodix_get_config_proc, brl_send_config, goodix_tools_ioctl, goodix_rotate_abcd2cbad, read_config_data, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0012e070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [goodix_spi_write, goodix_ts_stylus_mode_store, goodix_ts_stowed_store, brld_get_framedata, goodix_ts_mmi_update_liquid_detect_mode, goodix_ts_mmi_methods_get_build_id, goodix_ts_mmi_set_report_rate, gsx_gesture_enable_store, goodix_spi_read, brl_power_on, goodix_get_config_proc, goodix_fw_version_compare, goodix_ts_pocket_mode_store, goodix_ts_mmi_methods_get_config_id, brl_select_spi_mode, brl_gesture, goodix_ts_sample_store, brl_after_event_handler, goodix_ts_mmi_post_resume, goodix_i2c_read, goodix_ts_leather_mode, goodix_ts_chip_info_show, goodix_sysfs_fwsize_store, goodix_ts_edge_store, goodix_ts_probe, goodix_fw_update_proc, brl_esd_check, goodix_ts_send_cmd, brl_get_capacitance_data, goodix_ts_reg_rw_store, read_config_data, brl_suspend, brl_send_cmd, goodix_i2c_write, brl_read_version, brl_get_ic_info, gsx_gesture_ist, goodix_reg_write_confirm, goodix_ts_threadirq_func, brl_send_config, goodix_flash_subsystem, goodix_ts_interpolation_store, goodix_sysfs_result_show, goodix_spi_read_bra, goodix_ts_mmi_post_suspend, goodix_ts_pitch_store, goodix_do_inspect, goodix_get_ic_type, brl_event_handler, goodix_ts_mmi_charger_mode, send_cfg_cmd, goodix_strncatint, goodix_ts_send_cfg_store, brl_dev_confirm, goodix_stylus_mode, goodix_ts_mmi_panel_state, total_spi_timeouts_store, goodix_tools_ioctl, goodix_ts_sensitivity_store, brl_read_config, goodix_ts_film_mode, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msleep @ 0012e078 size=1
// signature: undefined msleep(void)
// callers: [goodix_i2c_write, goodix_ts_pitch_store, goodix_ts_mmi_post_resume, goodix_ts_mmi_pre_resume, goodix_do_inspect, goodix_ts_leather_mode, goodix_fw_update_thread, brl_reset, goodix_ts_mmi_charger_mode, send_cfg_cmd, goodix_ts_mmi_update_liquid_detect_mode, goodix_ts_mmi_set_report_rate, goodix_ts_edge_store, brl_dev_confirm, goodix_stylus_mode, goodix_get_config_proc, goodix_ts_mmi_panel_state, brl_send_config, goodix_flash_subsystem, goodix_ts_pocket_mode_store, goodix_ts_sample_store, goodix_ts_film_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msleep(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0012e090 size=1
// signature: undefined queue_work_on(void)
// callers: [goodix_spi_read, goodix_spi_write, goodix_spi_read_bra, check_spi_timeout, goodix_register_ext_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __spi_register_driver @ 0012e098 size=1
// signature: undefined __spi_register_driver(void)
// callers: [goodix_spi_bus_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __spi_register_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// driver_unregister @ 0012e0a0 size=1
// signature: undefined driver_unregister(void)
// callers: [goodix_spi_bus_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_dev_event @ 0012e0a8 size=1
// signature: undefined pm_wakeup_dev_event(void)
// callers: [restart_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_dev_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 0012e0b0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [goodix_ts_esd_init, goodix_ts_esd_work, goodix_esd_notifier_callback, restart_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kernel_restart @ 0012e0b8 size=1
// signature: undefined kernel_restart(void)
// callers: [restart_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kernel_restart(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// emergency_restart @ 0012e0c0 size=1
// signature: undefined emergency_restart(void)
// callers: [emergency_restart_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void emergency_restart(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spi_setup @ 0012e0c8 size=1
// signature: undefined spi_setup(void)
// callers: [goodix_spi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spi_setup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0012e0d0 size=1
// signature: undefined __list_add_valid(void)
// callers: [goodix_spi_read, goodix_spi_write, goodix_spi_read_bra, __do_register_ext_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// spi_sync @ 0012e0d8 size=1
// signature: undefined spi_sync(void)
// callers: [goodix_spi_read, goodix_spi_write, goodix_spi_read_bra]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void spi_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0012e0e8 size=1
// signature: undefined __mutex_init(void)
// callers: [goodix_ts_probe, goodix_tools_init, goodix_fw_update_init, goodix_ts_mmi_dev_register, goodix_register_ext_module, goodix_register_ext_module_no_wait]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0012e0f0 size=1
// signature: undefined mutex_lock(void)
// callers: [goodix_fw_update_uninit, goodix_ts_stylus_mode_store, goodix_ts_stowed_store, goodix_fw_update_thread, goodix_ts_mmi_update_liquid_detect_mode, goodix_ts_timestamp_show, goodix_ts_threadirq_func, goodix_ts_pocket_mode_store, goodix_ts_interpolation_store, goodix_ts_sample_store, goodix_ts_mmi_post_suspend, goodix_ts_pitch_store, goodix_ts_mmi_post_resume, goodix_ts_leather_mode, goodix_ts_mmi_charger_mode, goodix_sysfs_fwsize_store, goodix_ts_edge_store, goodix_ts_mmi_pre_suspend, goodix_ts_mmi_refresh_rate, goodix_ts_release_connects, goodix_unregister_ext_module, goodix_tools_ioctl, goodix_sysfs_fwimage_store, __do_register_ext_module, goodix_ts_film_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0012e0f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [goodix_fw_update_uninit, goodix_ts_stylus_mode_store, goodix_ts_stowed_store, goodix_fw_update_thread, goodix_ts_mmi_update_liquid_detect_mode, goodix_ts_timestamp_show, goodix_ts_threadirq_func, goodix_ts_pocket_mode_store, goodix_ts_interpolation_store, goodix_ts_sample_store, goodix_ts_mmi_post_suspend, goodix_ts_pitch_store, goodix_ts_mmi_post_resume, goodix_ts_leather_mode, goodix_ts_mmi_charger_mode, goodix_sysfs_fwsize_store, goodix_ts_edge_store, goodix_ts_mmi_pre_suspend, goodix_ts_mmi_refresh_rate, goodix_ts_release_connects, goodix_unregister_ext_module, goodix_tools_ioctl, goodix_sysfs_fwimage_store, __do_register_ext_module, goodix_ts_film_mode]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0012e100 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [goodix_unregister_ext_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 0012e108 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [goodix_ts_esd_init, goodix_ts_probe, goodix_ts_register_notifier]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 0012e110 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [goodix_ts_unregister_notifier, goodix_ts_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 0012e118 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [goodix_ts_blocking_notify, goodix_ts_esd_info_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0012e120 size=1
// signature: undefined ktime_get(void)
// callers: [goodix_ts_mmi_pre_resume, goodix_fw_update_thread, goodix_ts_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_unregister_device @ 0012e128 size=1
// signature: undefined input_unregister_device(void)
// callers: [goodix_ts_pen_dev_remove, goodix_ts_remove, goodix_ts_input_dev_remove, goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_unregister_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_free_device @ 0012e130 size=1
// signature: undefined input_free_device(void)
// callers: [goodix_ts_pen_dev_remove, goodix_ts_remove, goodix_ts_input_dev_remove, goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_free_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 0012e138 size=1
// signature: undefined init_timer_key(void)
// callers: [goodix_ts_esd_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 0012e140 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [goodix_ts_remove, goodix_esd_notifier_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_event @ 0012e148 size=1
// signature: undefined input_event(void)
// callers: [goodix_ts_release_connects, goodix_ts_threadirq_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_mt_report_slot_state @ 0012e150 size=1
// signature: undefined input_mt_report_slot_state(void)
// callers: [goodix_ts_release_connects, goodix_ts_threadirq_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_mt_report_slot_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_mt_sync_frame @ 0012e158 size=1
// signature: undefined input_mt_sync_frame(void)
// callers: [goodix_ts_release_connects]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_mt_sync_frame(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0012e160 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [brl_get_ic_info, gsx_gesture_ist, goodix_ts_release_connects, goodix_do_inspect, goodix_tools_ioctl, brl_event_handler, brld_get_framedata, goodix_sysfs_fwsize_store, read_config_data, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_allocate_device @ 0012e168 size=1
// signature: undefined input_allocate_device(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_allocate_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_abs_params @ 0012e170 size=1
// signature: undefined input_set_abs_params(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_abs_params(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_mt_init_slots @ 0012e178 size=1
// signature: undefined input_mt_init_slots(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_mt_init_slots(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_set_capability @ 0012e180 size=1
// signature: undefined input_set_capability(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_set_capability(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// input_register_device @ 0012e188 size=1
// signature: undefined input_register_device(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void input_register_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpio_to_desc @ 0012e190 size=1
// signature: undefined gpio_to_desc(void)
// callers: [brl_power_on, brl_reset, goodix_ts_mmi_methods_get_irq_status, goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpio_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_to_irq @ 0012e198 size=1
// signature: undefined gpiod_to_irq(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_to_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 0012e1a0 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0012e1a8 size=1
// signature: undefined sysfs_create_group(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_mkdir @ 0012e1b0 size=1
// signature: undefined proc_mkdir(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_mkdir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// proc_create_data @ 0012e1b8 size=1
// signature: undefined proc_create_data(void)
// callers: [goodix_ts_stage2_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void proc_create_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0012e1c0 size=1
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
// platform_driver_unregister @ 0012e1c8 size=1
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
// cpu_latency_qos_update_request @ 0012e1d0 size=1
// signature: undefined cpu_latency_qos_update_request(void)
// callers: [goodix_ts_threadirq_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_with_offset @ 0012e1d8 size=1
// signature: undefined ktime_get_with_offset(void)
// callers: [goodix_ts_threadirq_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_with_offset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0012e1e0 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [goodix_ts_get_rawdata_show, goodix_ts_driver_info_show, goodix_do_inspect, goodix_ts_chip_info_show, goodix_ts_read_cfg_show, goodix_ts_debug_log_show, goodix_ts_irq_info_show, goodix_strncatint, goodix_ts_mmi_methods_get_build_id, goodix_ts_probe, goodix_sysfs_fwsize_show, total_spi_timeouts_show, goodix_get_config_proc, goodix_ts_esd_info_show, goodix_ts_mmi_methods_get_config_id, goodix_ts_reg_rw_store, goodix_ts_reg_rw_show, goodix_sysfs_result_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0012e1e8 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [goodix_ts_pitch_store, goodix_sysfs_fwsize_store, goodix_ts_edge_store, goodix_ts_send_cfg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_firmware @ 0012e1f0 size=1
// signature: undefined request_firmware(void)
// callers: [goodix_get_config_proc, goodix_do_inspect, goodix_fw_update_thread, goodix_ts_send_cfg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// release_firmware @ 0012e1f8 size=1
// signature: undefined release_firmware(void)
// callers: [goodix_get_config_proc, goodix_do_inspect, goodix_fw_update_thread, goodix_ts_send_cfg_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void release_firmware(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0012e200 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [goodix_ts_reg_rw_store, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 0012e208 size=1
// signature: undefined kstrtoll(void)
// callers: [goodix_ts_reg_rw_store, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_to_desc @ 0012e210 size=1
// signature: undefined irq_to_desc(void)
// callers: [goodix_ts_irq_info_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0012e218 size=1
// signature: undefined kstrtoull(void)
// callers: [goodix_ts_stylus_mode_store, goodix_ts_stowed_store, total_spi_timeouts_store, goodix_ts_pocket_mode_store, goodix_ts_sensitivity_store, goodix_ts_interpolation_store, goodix_ts_sample_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open_size @ 0012e220 size=1
// signature: undefined single_open_size(void)
// callers: [rawdata_proc_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_large @ 0012e228 size=1
// signature: undefined kmalloc_large(void)
// callers: [goodix_ts_get_rawdata_show, goodix_do_inspect, rawdata_proc_show, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_large(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 0012e230 size=1
// signature: undefined seq_printf(void)
// callers: [rawdata_proc_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0012e238 size=1
// signature: undefined devm_kmalloc(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_named_gpio_flags @ 0012e240 size=1
// signature: undefined of_get_named_gpio_flags(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_named_gpio_flags(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0012e248 size=1
// signature: undefined of_find_property(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0012e250 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0012e258 size=1
// signature: undefined of_property_read_string(void)
// callers: [goodix_ts_probe, goodix_get_ic_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0012e260 size=1
// signature: size_t strlen(char * __s)
// callers: [goodix_ts_probe, goodix_do_inspect, goodix_set_fwname, goodix_strncatint]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncpy @ 0012e268 size=1
// signature: char * strncpy(char * __dest, char * __src, size_t __n)
// callers: [goodix_ts_probe, goodix_do_inspect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncpy(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_node_by_name @ 0012e270 size=1
// signature: undefined of_find_node_by_name(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_node_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string_helper @ 0012e278 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 0012e280 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [goodix_ts_probe, goodix_get_ic_type, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 0012e288 size=1
// signature: undefined kstrdup(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_gpio_request_one @ 0012e290 size=1
// signature: undefined devm_gpio_request_one(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_gpio_request_one(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 0012e298 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [goodix_ts_probe, goodix_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_add_request @ 0012e2a0 size=1
// signature: undefined cpu_latency_qos_add_request(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_register @ 0012e2a8 size=1
// signature: undefined wakeup_source_register(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 0012e2b0 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [goodix_ts_probe, goodix_tools_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wakeup_source_unregister @ 0012e2b8 size=1
// signature: undefined wakeup_source_unregister(void)
// callers: [goodix_ts_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wakeup_source_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_latency_qos_remove_request @ 0012e2c0 size=1
// signature: undefined cpu_latency_qos_remove_request(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_latency_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 0012e2c8 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_proc_entry @ 0012e2d0 size=1
// signature: undefined remove_proc_entry(void)
// callers: [goodix_ts_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_proc_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 0012e2d8 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [goodix_fw_update_init, goodix_do_inspect, goodix_strncat, goodix_ts_power_init, goodix_strncatint, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_regulator_get @ 0012e2e0 size=1
// signature: undefined devm_regulator_get(void)
// callers: [goodix_ts_power_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_regulator_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_load @ 0012e2e8 size=1
// signature: undefined regulator_set_load(void)
// callers: [goodix_ts_power_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_load(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_set_voltage @ 0012e2f0 size=1
// signature: undefined regulator_set_voltage(void)
// callers: [goodix_ts_power_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_set_voltage(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0012e2f8 size=1
// signature: noreturn undefined fortify_panic(void)
// callers: [goodix_fw_update_init, goodix_do_inspect, goodix_strncat, goodix_ts_power_init, goodix_strncatint, parse_csvfile]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 0012e300 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [goodix_ts_pinctrl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 0012e308 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [goodix_ts_pinctrl_init, goodix_ts_stylus_clk_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 0012e310 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [goodix_ts_pinctrl_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0012e318 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [goodix_clock_enable, goodix_ts_stylus_clk_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_property @ 0012e320 size=1
// signature: undefined of_get_property(void)
// callers: [goodix_ts_stylus_clk_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_clk_get @ 0012e328 size=1
// signature: undefined devm_clk_get(void)
// callers: [goodix_ts_stylus_clk_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_clk_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0012e330 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [goodix_do_fw_update, goodix_start_later_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0012e338 size=1
// signature: undefined wake_up_process(void)
// callers: [goodix_do_fw_update, goodix_start_later_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 0012e340 size=1
// signature: undefined __wake_up(void)
// callers: [goodix_ts_pm_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_direction_output_raw @ 0012e360 size=1
// signature: undefined gpiod_direction_output_raw(void)
// callers: [brl_power_on, brl_reset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_direction_output_raw(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_disable @ 0012e368 size=1
// signature: undefined regulator_disable(void)
// callers: [brl_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regulator_enable @ 0012e370 size=1
// signature: undefined regulator_enable(void)
// callers: [brl_power_on]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regulator_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 0012e378 size=1
// signature: undefined enable_irq(void)
// callers: [brl_get_capacitance_data, brl_irq_enbale]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 0012e380 size=1
// signature: undefined disable_irq(void)
// callers: [brl_get_capacitance_data, brl_irq_enbale]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bcmp @ 0012e388 size=1
// signature: int bcmp(void * __s1, void * __s2, size_t __n)
// callers: [brl_send_config, goodix_reg_write_confirm]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int bcmp(void *__s1,void *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 0012e390 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [goodix_fw_update_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 0012e398 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [goodix_fw_update_init, inspect_module_init, gesture_module_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_bin_file @ 0012e3a0 size=1
// signature: undefined sysfs_create_bin_file(void)
// callers: [goodix_fw_update_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_bin_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 0012e3a8 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [goodix_fw_update_uninit, inspect_module_exit, gesture_module_exit, goodix_fw_update_init, gesture_module_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 0012e3b0 size=1
// signature: undefined kobject_put(void)
// callers: [goodix_fw_update_uninit, gesture_module_exit, goodix_fw_update_init, gesture_module_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_bin_file @ 0012e3b8 size=1
// signature: undefined sysfs_remove_bin_file(void)
// callers: [goodix_fw_update_uninit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_bin_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vmalloc @ 0012e3c0 size=1
// signature: undefined vmalloc(void)
// callers: [goodix_sysfs_fwsize_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncat @ 0012e3c8 size=1
// signature: char * strncat(char * __dest, char * __src, size_t __n)
// callers: [goodix_do_inspect, goodix_strncat]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strncat(char *__dest,char *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __warn_printk @ 0012e3d0 size=1
// signature: undefined __warn_printk(void)
// callers: [goodix_do_inspect]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __warn_printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 0012e3d8 size=1
// signature: undefined misc_register(void)
// callers: [goodix_tools_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 0012e3e0 size=1
// signature: undefined misc_deregister(void)
// callers: [goodix_tools_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 0012e3f0 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [goodix_tools_ioctl, read_config_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 0012e3f8 size=1
// signature: undefined __check_object_size(void)
// callers: [goodix_tools_ioctl, read_config_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 0012e400 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [goodix_tools_ioctl, read_config_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0012e410 size=1
// signature: undefined scnprintf(void)
// callers: [goodix_ts_stylus_mode_show, gsx_gesture_data_show, goodix_ts_sample_show, goodix_ts_interpolation_show, goodix_ts_stowed_show, goodix_ts_timestamp_show, gsx_gesture_enable_show, goodix_ts_mmi_methods_get_productinfo, goodix_ts_hardware_status_show, goodix_ts_pitch_show, goodix_ts_edge_show, goodix_ts_mmi_methods_get_vendor, goodix_ts_pocket_mode_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0012e418 size=1
// signature: undefined kstrtobool(void)
// callers: [gsx_gesture_enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock @ 0012e420 size=1
// signature: undefined _raw_read_lock(void)
// callers: [gsx_gesture_data_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock @ 0012e428 size=1
// signature: undefined _raw_read_unlock(void)
// callers: [gsx_gesture_data_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 0012e430 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [gsx_double_type_show, gsx_single_type_show, gsx_fod_type_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 0012e438 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [gesture_module_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_set_irq_wake @ 0012e440 size=1
// signature: undefined irq_set_irq_wake(void)
// callers: [goodix_ts_mmi_pre_resume, goodix_ts_mmi_panel_state, gsx_gesture_before_suspend, gsx_gesture_before_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_set_irq_wake(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_wakeup_ws_event @ 0012e448 size=1
// signature: undefined pm_wakeup_ws_event(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_wakeup_ws_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 0012e450 size=1
// signature: undefined init_wait_entry(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 0012e458 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 0012e460 size=1
// signature: undefined finish_wait(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule_timeout @ 0012e468 size=1
// signature: undefined schedule_timeout(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// jiffies_to_msecs @ 0012e478 size=1
// signature: undefined jiffies_to_msecs(void)
// callers: [gsx_gesture_ist]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void jiffies_to_msecs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ts_mmi_dev_register @ 0012e480 size=1
// signature: undefined ts_mmi_dev_register(void)
// callers: [goodix_ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ts_mmi_dev_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0012e488 size=1
// signature: undefined _dev_err(void)
// callers: [goodix_ts_mmi_dev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ts_mmi_dev_unregister @ 0012e490 size=1
// signature: undefined ts_mmi_dev_unregister(void)
// callers: [goodix_ts_mmi_dev_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ts_mmi_dev_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strchr @ 0012e498 size=1
// signature: char * strchr(char * __s, int __c)
// callers: [goodix_ts_mmi_methods_get_productinfo]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gpiod_get_raw_value @ 0012e4a0 size=1
// signature: undefined gpiod_get_raw_value(void)
// callers: [goodix_ts_mmi_methods_get_irq_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gpiod_get_raw_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0012e4a8 size=1
// signature: undefined _dev_info(void)
// callers: [goodix_ts_mmi_extend_attribute_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_prepare @ 0012e4b0 size=1
// signature: undefined clk_prepare(void)
// callers: [goodix_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_prepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_enable @ 0012e4b8 size=1
// signature: undefined clk_enable(void)
// callers: [goodix_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_unprepare @ 0012e4c0 size=1
// signature: undefined clk_unprepare(void)
// callers: [goodix_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_unprepare(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// clk_disable @ 0012e4c8 size=1
// signature: undefined clk_disable(void)
// callers: [goodix_clock_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void clk_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ns_to_timespec64 @ 0012e4d0 size=1
// signature: undefined ns_to_timespec64(void)
// callers: [goodix_ts_timestamp_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ns_to_timespec64(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



