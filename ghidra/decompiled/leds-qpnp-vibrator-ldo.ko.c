// Decompiled by Ghidra 12.2
// Program: leds-qpnp-vibrator-ldo.ko
// Image base: 00100000

//------------------------------------------------------------
// qpnp_vibrator_ldo_probe @ 00100294 size=800
// signature: undefined qpnp_vibrator_ldo_probe(void)
// callers: []
//------------------------------------------------------------

int qpnp_vibrator_ldo_probe(long param_1)

{
  long lVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined *puVar7;
  undefined8 uVar8;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_4c = 0;
  iVar4 = of_property_read_variable_u32_array
                    (*(undefined8 *)(param_1 + 0x2f8),&DAT_00101403,&local_4c,1,0);
  if (iVar4 < 0) {
    puVar7 = &DAT_0010140e;
  }
  else {
    lVar1 = param_1 + 0x10;
    puVar5 = (undefined8 *)devm_kmalloc(lVar1,0x280,0xdc0);
    if (puVar5 == (undefined8 *)0x0) {
      iVar4 = -0xc;
      goto LAB_00100300;
    }
    lVar6 = dev_get_regmap(*(undefined8 *)(param_1 + 0x70),0);
    puVar5[0x35] = lVar6;
    if (lVar6 == 0) {
      _printk(&DAT_00101238,"qpnp_vibrator_ldo_probe");
      iVar4 = -0x16;
      goto LAB_00100300;
    }
    iVar4 = of_property_read_variable_u32_array
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,vib-ldo-volt-uv",(long)puVar5 + 0x25c,
                       1,0);
    if (-1 < iVar4) {
      lVar6 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,disable-overdrive",0);
      uVar8 = *(undefined8 *)(param_1 + 0x2f8);
      *(bool *)((long)puVar5 + 0x279) = lVar6 != 0;
      lVar6 = of_find_property(uVar8,"qcom,vib-overdrive-volt-uv",0);
      if (lVar6 != 0) {
        piVar2 = (int *)(puVar5 + 0x4c);
        iVar4 = of_property_read_variable_u32_array
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,vib-overdrive-volt-uv",piVar2,1,0)
        ;
        if (iVar4 < 0) {
          puVar7 = &DAT_001012f3;
          goto LAB_001003a4;
        }
        iVar4 = *piVar2;
        if (0x3613bf < *piVar2) {
          iVar4 = 0x3613c0;
        }
        if (iVar4 < 0x16f301) {
          iVar4 = 0x16f300;
        }
        *piVar2 = iVar4;
      }
      *(short *)(puVar5 + 0x4b) = (short)local_4c;
      puVar5[0x4e] = 5000;
      __mutex_init(puVar5 + 0x36,"&chip->lock",&qpnp_vibrator_ldo_probe___key);
      puVar5[0x45] = 0xfffffffe0;
      puVar5[0x46] = puVar5 + 0x46;
      puVar5[0x47] = puVar5 + 0x46;
      puVar5[0x48] = qpnp_vib_overdrive_work;
      hrtimer_init(puVar5 + 0x3c,1,1);
      puVar5[0x41] = vib_overdrive_timer;
      *(undefined8 **)(param_1 + 0xa8) = puVar5;
      *puVar5 = "vibrator";
      puVar5[5] = qpnp_vib_brightness_set;
      puVar5[6] = qpnp_vib_brightness_get;
      *(undefined4 *)((long)puVar5 + 0xc) = 100;
      iVar4 = devm_led_classdev_register_ext(lVar1,puVar5,0);
      if (iVar4 < 0) {
        _printk(&DAT_00101590,"qpnp_vibrator_ldo_probe",iVar4);
      }
      else {
        iVar4 = sysfs_create_file_ns(puVar5[10],&qpnp_vib_attrs,0);
        if (-1 < iVar4) {
          pcVar3 = "enabled";
          if (*(char *)((long)puVar5 + 0x279) != '\0') {
            pcVar3 = "disabled";
          }
          _printk(&DAT_00101389,"qpnp_vibrator_ldo_probe",*(undefined4 *)((long)puVar5 + 0x25c),
                  pcVar3);
          iVar4 = 0;
          goto LAB_00100300;
        }
        _dev_err(lVar1,"Error in creating sysfs file, ret=%d\n",iVar4);
        sysfs_remove_file_ns(puVar5[10],&qpnp_vib_attrs,0);
      }
      *(undefined8 *)(param_1 + 0xa8) = 0;
      goto LAB_00100300;
    }
    puVar7 = &DAT_001012ba;
LAB_001003a4:
    _printk(puVar7,"qpnp_vib_parse_dt",iVar4);
    puVar7 = &DAT_00101463;
  }
  _printk(puVar7,"qpnp_vibrator_ldo_probe",iVar4);
LAB_00100300:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// qpnp_vibrator_ldo_remove @ 001005b8 size=72
// signature: undefined qpnp_vibrator_ldo_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_vibrator_ldo_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (*(char *)(lVar1 + 0x279) == '\0') {
    hrtimer_cancel(lVar1 + 0x1e0);
    cancel_work_sync(lVar1 + 0x228);
  }
  *(undefined8 *)(param_1 + 0xa8) = 0;
  return 0;
}



//------------------------------------------------------------
// qpnp_vib_overdrive_work @ 00100604 size=200
// signature: undefined qpnp_vib_overdrive_work(void)
// callers: []
//------------------------------------------------------------

void qpnp_vib_overdrive_work(long param_1)

{
  int iVar1;
  
  mutex_lock(param_1 + -0x78);
  if (((*(char *)(param_1 + 0x50) != '\0') &&
      (iVar1 = qpnp_vib_ldo_set_voltage(param_1 + -0x228,*(undefined4 *)(param_1 + 0x34)), iVar1 < 0
      )) && (_printk(&DAT_0010125c,"qpnp_vib_overdrive_work",*(undefined4 *)(param_1 + 0x34),iVar1),
            *(char *)(param_1 + 0x50) != '\0')) {
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + -0x80),*(ushort *)(param_1 + 0x30) + 0x46,0x80,0,0,
                       0,0);
    if (iVar1 < 0) {
      _printk(&DAT_001015eb,"qpnp_vib_ldo_enable","disable",iVar1);
    }
    else {
      *(undefined1 *)(param_1 + 0x50) = 0;
    }
  }
  mutex_unlock(param_1 + -0x78);
  return;
}



//------------------------------------------------------------
// vib_overdrive_timer @ 001006d0 size=48
// signature: undefined vib_overdrive_timer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 vib_overdrive_timer(long param_1)

{
  queue_work_on(0x20,_system_wq,param_1 + 0x48);
  return 0;
}



//------------------------------------------------------------
// qpnp_vib_brightness_get @ 00100704 size=8
// signature: undefined qpnp_vib_brightness_get(void)
// callers: []
//------------------------------------------------------------

undefined4 qpnp_vib_brightness_get(long param_1)

{
  return *(undefined4 *)(param_1 + 0x268);
}



//------------------------------------------------------------
// qpnp_vib_brightness_set @ 00100710 size=524
// signature: undefined qpnp_vib_brightness_set(void)
// callers: []
//------------------------------------------------------------

int qpnp_vib_brightness_set(long param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  *(int *)(param_1 + 0x268) = param_2;
  if (param_2 == 0) {
    if (*(char *)(param_1 + 0x279) == '\0') {
      hrtimer_cancel(param_1 + 0x1e0);
      cancel_work_sync(param_1 + 0x228);
      cVar1 = *(char *)(param_1 + 0x278);
    }
    else {
      cVar1 = *(char *)(param_1 + 0x278);
    }
    if (cVar1 == '\0') {
      return 0;
    }
    iVar3 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 0x46,0x80,0,0,0
                       ,0);
    if (iVar3 < 0) {
      _printk(&DAT_001015eb,"qpnp_vib_ldo_enable","disable",iVar3);
      return iVar3;
    }
    *(undefined1 *)(param_1 + 0x278) = 0;
    return iVar3;
  }
  iVar3 = *(int *)(param_1 + 0x25c);
  if (*(char *)(param_1 + 0x279) == '\0') {
    iVar2 = iVar3 * 2;
    if (0x3613bf < iVar3 * 2) {
      iVar2 = 0x3613c0;
    }
    iVar3 = iVar2;
    if (*(int *)(param_1 + 0x260) != 0) {
      iVar3 = *(int *)(param_1 + 0x260);
    }
  }
  iVar2 = qpnp_vib_ldo_set_voltage(param_1,iVar3);
  if (iVar2 < 0) {
    _printk(&DAT_00101556,"qpnp_vibrator_play_on",iVar3,iVar2);
  }
  else {
    if (*(char *)(param_1 + 0x278) == '\x01') {
      iVar2 = 0;
      cVar1 = *(char *)(param_1 + 0x279);
joined_r0x00100780:
      if (cVar1 == '\0') {
        hrtimer_start_range_ns(param_1 + 0x1e0,30000000,0,1);
        return iVar2;
      }
      return iVar2;
    }
    iVar2 = regmap_update_bits_base
                      (*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 0x46,0x80,0x80,
                       0,0,0);
    if (iVar2 < 0) {
      _printk(&DAT_001015eb,"qpnp_vib_ldo_enable","enable",iVar2);
    }
    else {
      iVar2 = qpnp_vib_ldo_poll_status(param_1);
      if (-1 < iVar2) {
        *(undefined1 *)(param_1 + 0x278) = 1;
        cVar1 = *(char *)(param_1 + 0x279);
        goto joined_r0x00100780;
      }
      _printk(&DAT_00101332,"qpnp_vib_ldo_enable");
    }
    _printk(&DAT_0010135e,"qpnp_vibrator_play_on",iVar2);
  }
  _printk(&DAT_00101530,"qpnp_vib_brightness_set",iVar2);
  return iVar2;
}



//------------------------------------------------------------
// qpnp_vib_ldo_set_voltage @ 0010091c size=288
// signature: undefined qpnp_vib_ldo_set_voltage(void)
// callers: [qpnp_vib_brightness_set, qpnp_vib_overdrive_work]
//------------------------------------------------------------

int qpnp_vib_ldo_set_voltage(long param_1,int param_2)

{
  long lVar1;
  int iVar2;
  short local_3c [2];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if (*(int *)(param_1 + 0x264) == param_2) {
    iVar2 = 0;
  }
  else {
    iVar2 = ((param_2 + 7999) / 8000) * 8000;
    local_3c[0] = (short)((ulong)((long)iVar2 * 0x10624dd3) >> 0x26) - (short)(iVar2 >> 0x1f);
    iVar2 = regmap_bulk_write(*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 0x40,
                              local_3c,2);
    if (iVar2 < 0) {
      _printk(&DAT_0010150d,"qpnp_vib_ldo_set_voltage",iVar2);
    }
    else {
      if (*(char *)(param_1 + 0x278) != '\0') {
        iVar2 = qpnp_vib_ldo_poll_status(param_1);
        if (iVar2 < 0) {
          _printk(&DAT_00101332,"qpnp_vib_ldo_set_voltage");
          goto LAB_001009d4;
        }
      }
      *(int *)(param_1 + 0x264) = param_2;
    }
  }
LAB_001009d4:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// qpnp_vib_ldo_poll_status @ 00100a3c size=328
// signature: undefined qpnp_vib_ldo_poll_status(void)
// callers: [qpnp_vib_brightness_set, qpnp_vib_ldo_set_voltage]
//------------------------------------------------------------

int qpnp_vib_ldo_poll_status(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  uint local_2c;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_2c = 0;
  lVar2 = ktime_get();
  iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 8,&local_2c);
  if (iVar1 == 0) {
    do {
      if ((char)local_2c < '\0') {
        iVar1 = 0;
        break;
      }
      lVar3 = ktime_get();
      if (lVar2 + 1000000 < lVar3) {
        iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 8,
                            &local_2c);
        break;
      }
      usleep_range_state(0x1a,100,2);
      Yield();
      iVar1 = regmap_read(*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 8,&local_2c)
      ;
    } while (iVar1 == 0);
  }
  iVar4 = 0;
  if (iVar1 == 0 && (local_2c & 0x80) == 0) {
    iVar4 = -0x6e;
  }
  if (iVar1 == 0) {
    iVar1 = iVar4;
  }
  if (iVar1 < 0) {
    _printk(&DAT_001014c7,"qpnp_vib_ldo_poll_status",local_2c,iVar1);
    regmap_update_bits_base
              (*(undefined8 *)(param_1 + 0x1a8),*(ushort *)(param_1 + 600) + 0x46,0x80,0,0,0,0);
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



//------------------------------------------------------------
// qpnp_vib_show_vmax @ 00100b88 size=84
// signature: undefined qpnp_vib_show_vmax(void)
// callers: []
//------------------------------------------------------------

long qpnp_vib_show_vmax(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00101385,*(int *)(*(long *)(param_1 + 0x98) + 0x25c) / 1000)
  ;
  return (long)iVar1;
}



//------------------------------------------------------------
// qpnp_vib_store_vmax @ 00100be0 size=208
// signature: undefined qpnp_vib_store_vmax(void)
// callers: []
//------------------------------------------------------------

long qpnp_vib_store_vmax(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  int local_3c;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x98);
  local_3c = 0;
  iVar2 = kstrtoint(param_3,10,&local_3c);
  if (iVar2 < 0) {
    param_4 = (long)iVar2;
  }
  else {
    lVar1 = lVar3 + 0x1b0;
    iVar2 = local_3c * 1000;
    if (0x3613bf < local_3c * 1000) {
      iVar2 = 0x3613c0;
    }
    local_3c = iVar2;
    if (iVar2 < 0x16f301) {
      local_3c = 0x16f300;
    }
    mutex_lock(lVar1);
    *(int *)(lVar3 + 0x25c) = local_3c;
    mutex_unlock(lVar1);
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qpnp_vibrator_ldo_suspend @ 00100cb4 size=172
// signature: undefined qpnp_vibrator_ldo_suspend(void)
// callers: []
//------------------------------------------------------------

undefined8 qpnp_vibrator_ldo_suspend(long param_1)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  mutex_lock(lVar2 + 0x1b0);
  if (*(char *)(lVar2 + 0x279) == '\0') {
    hrtimer_cancel(lVar2 + 0x1e0);
    cancel_work_sync(lVar2 + 0x228);
  }
  if (*(char *)(lVar2 + 0x278) != '\0') {
    iVar1 = regmap_update_bits_base
                      (*(undefined8 *)(lVar2 + 0x1a8),*(ushort *)(lVar2 + 600) + 0x46,0x80,0,0,0,0);
    if (iVar1 < 0) {
      _printk(&DAT_001015eb,"qpnp_vib_ldo_enable","disable",iVar1);
    }
    else {
      *(undefined1 *)(lVar2 + 0x278) = 0;
    }
  }
  mutex_unlock(lVar2 + 0x1b0);
  return 0;
}



//------------------------------------------------------------
// init_module @ 00100d64 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qpnp_vibrator_ldo_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100d94 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qpnp_vibrator_ldo_driver);
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
// of_property_read_variable_u32_array @ 00103010 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qpnp_vibrator_ldo_probe]
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
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_get_regmap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103028 size=1
// signature: undefined _printk(void)
// callers: [qpnp_vib_ldo_poll_status, qpnp_vibrator_ldo_probe, qpnp_vib_brightness_set, qpnp_vib_overdrive_work, qpnp_vib_ldo_set_voltage, qpnp_vibrator_ldo_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00103030 size=1
// signature: undefined of_find_property(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00103038 size=1
// signature: undefined __mutex_init(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_init @ 00103040 size=1
// signature: undefined hrtimer_init(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_led_classdev_register_ext @ 00103048 size=1
// signature: undefined devm_led_classdev_register_ext(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_led_classdev_register_ext(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_file_ns @ 00103050 size=1
// signature: undefined sysfs_create_file_ns(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103058 size=1
// signature: undefined _dev_err(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_ns @ 00103060 size=1
// signature: undefined sysfs_remove_file_ns(void)
// callers: [qpnp_vibrator_ldo_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103068 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qpnp_vib_ldo_poll_status, qpnp_vibrator_ldo_probe, qpnp_vib_ldo_set_voltage, qpnp_vib_store_vmax]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_cancel @ 00103070 size=1
// signature: undefined hrtimer_cancel(void)
// callers: [qpnp_vib_brightness_set, qpnp_vibrator_ldo_suspend, qpnp_vibrator_ldo_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_cancel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_work_sync @ 00103078 size=1
// signature: undefined cancel_work_sync(void)
// callers: [qpnp_vib_brightness_set, qpnp_vibrator_ldo_suspend, qpnp_vibrator_ldo_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00103080 size=1
// signature: undefined mutex_lock(void)
// callers: [qpnp_vib_overdrive_work, qpnp_vibrator_ldo_suspend, qpnp_vib_store_vmax]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103088 size=1
// signature: undefined mutex_unlock(void)
// callers: [qpnp_vib_overdrive_work, qpnp_vibrator_ldo_suspend, qpnp_vib_store_vmax]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_update_bits_base @ 00103090 size=1
// signature: undefined regmap_update_bits_base(void)
// callers: [qpnp_vib_ldo_poll_status, qpnp_vib_brightness_set, qpnp_vib_overdrive_work, qpnp_vibrator_ldo_suspend]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_update_bits_base(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030a0 size=1
// signature: undefined queue_work_on(void)
// callers: [vib_overdrive_timer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hrtimer_start_range_ns @ 001030a8 size=1
// signature: undefined hrtimer_start_range_ns(void)
// callers: [qpnp_vib_brightness_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hrtimer_start_range_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_bulk_write @ 001030b0 size=1
// signature: undefined regmap_bulk_write(void)
// callers: [qpnp_vib_ldo_set_voltage]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_bulk_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 001030b8 size=1
// signature: undefined ktime_get(void)
// callers: [qpnp_vib_ldo_poll_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// regmap_read @ 001030c0 size=1
// signature: undefined regmap_read(void)
// callers: [qpnp_vib_ldo_poll_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void regmap_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 001030c8 size=1
// signature: undefined usleep_range_state(void)
// callers: [qpnp_vib_ldo_poll_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001030d0 size=1
// signature: undefined scnprintf(void)
// callers: [qpnp_vib_show_vmax]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 001030d8 size=1
// signature: undefined kstrtoint(void)
// callers: [qpnp_vib_store_vmax]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



