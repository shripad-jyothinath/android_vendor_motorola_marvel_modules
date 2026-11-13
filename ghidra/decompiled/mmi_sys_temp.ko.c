// Decompiled by Ghidra 12.2
// Program: mmi_sys_temp.ko
// Image base: 00100000

//------------------------------------------------------------
// mmi_sys_temp_probe @ 0010030c size=1360
// signature: undefined mmi_sys_temp_probe(void)
// callers: []
//------------------------------------------------------------

int mmi_sys_temp_probe(long param_1)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  long *plVar7;
  long lVar8;
  undefined8 uVar9;
  char *pcVar10;
  char *pcVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 *puVar16;
  long lVar17;
  char *local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  if (param_1 == 0) {
    iVar4 = -0x13;
  }
  else {
    lVar12 = *(long *)(param_1 + 0x2f8);
    lVar1 = param_1 + 0x10;
    if (lVar12 == 0) {
      _dev_err(lVar1,"bad of_node\n");
      iVar4 = -0x13;
    }
    else {
      uVar2 = of_property_read_string_helper(lVar12,"mmi,temperature-names",0,0,0);
      uVar14 = (ulong)uVar2;
      if ((int)uVar2 < 1) {
        _dev_err(lVar1,"bad number of sensors: %d\n",uVar14);
        iVar4 = -0x16;
      }
      else {
        uVar3 = of_property_read_string_helper(lVar12,"mmi,sensor-listener-names",0,0,0);
        uVar13 = (ulong)uVar3;
        if ((int)uVar3 < 1) {
          _dev_err(lVar1,"bad number of sensors-listener: %d\n",uVar13);
        }
        plVar7 = (long *)devm_kmalloc(lVar1,0x70,0xdc0);
        sys_temp_dev = plVar7;
        if (plVar7 == (long *)0x0) {
          pcVar11 = "Unable to alloc memory for sys_temp_dev\n";
        }
        else {
          *plVar7 = param_1;
          *(uint *)(plVar7 + 1) = uVar2;
          lVar8 = devm_kmalloc(lVar1,uVar14 << 5,0xdc0);
          sys_temp_dev[3] = lVar8;
          if (lVar8 != 0) {
            lVar17 = 0;
            uVar15 = 0;
            do {
              iVar4 = of_property_read_string_helper
                                (lVar12,"mmi,temperature-names",lVar8 + lVar17 + 8,1,
                                 uVar15 & 0xffffffff);
              plVar7 = sys_temp_dev;
              if (iVar4 < 0) {
                _dev_err(lVar1,"Unable to read of_prop string\n");
                goto LAB_001007bc;
              }
              *(undefined4 *)(sys_temp_dev[3] + lVar17 + 0x10) = 0;
              uVar9 = thermal_zone_device_register
                                (*(undefined8 *)(plVar7[3] + lVar17 + 8),0,0,plVar7[3] + lVar17,
                                 mmi_sys_temp_ops,0,0,0);
              plVar7 = sys_temp_dev;
              *(undefined8 *)(sys_temp_dev[3] + lVar17) = uVar9;
              lVar8 = plVar7[3];
              if (0xfffffffffffff000 < *(ulong *)(lVar8 + lVar17)) {
                _dev_err(lVar1,"thermal_zone_device_register() failed.\n");
                iVar4 = -0x13;
                goto LAB_001007bc;
              }
              uVar15 = uVar15 + 1;
              lVar17 = lVar17 + 0x20;
            } while (uVar14 != uVar15);
            local_70 = (char *)0x0;
            iVar4 = of_property_read_string_helper(lVar12,"mmi,need-uevent-sensors",0,0,0);
            if (iVar4 < 1) {
              _dev_info(*plVar7 + 0x10,"No sensor need uevent\n");
            }
            else {
              iVar5 = of_property_read_variable_u32_array
                                (lVar12,"mmi,uevent-temp-threshold",plVar7 + 2,1,0);
              if (iVar5 < 0) {
                *(undefined4 *)(plVar7 + 2) = 40000;
              }
              iVar5 = 0;
              do {
                iVar6 = of_property_read_string_helper
                                  (lVar12,"mmi,need-uevent-sensors",&local_70,1,iVar5);
                if (iVar6 < 0) {
                  _dev_err(*plVar7 + 0x10,"Unable to read of_prop string of uevent sensors\n");
                  break;
                }
                _dev_info(*plVar7 + 0x10,"%s need uevent, thresh %d\n",local_70,(int)plVar7[2]);
                pcVar11 = local_70;
                uVar15 = 0;
                puVar16 = (undefined8 *)(plVar7[3] + 8);
                do {
                  pcVar10 = strstr((char *)*puVar16,pcVar11);
                  if (pcVar10 != (char *)0x0) {
                    _dev_info(*plVar7 + 0x10,"%s uevent flag match!\n",pcVar11);
                    *(undefined1 *)(plVar7[3] + (uVar15 & 0xffffffff) * 0x20 + 0x14) = 1;
                    break;
                  }
                  uVar15 = uVar15 + 1;
                  puVar16 = puVar16 + 4;
                } while (uVar14 != uVar15);
                iVar5 = iVar5 + 1;
              } while (iVar5 != iVar4);
            }
            *(long **)(param_1 + 0xa8) = sys_temp_dev;
            iVar4 = misc_register(mmi_sys_temp_misc);
            if (iVar4 == 0) {
              if ((int)uVar3 < 1) {
                _dev_info(*sys_temp_dev + 0x10,"No configure sensors listener !\n");
              }
              else {
                *(uint *)((long)sys_temp_dev + 0xc) = uVar3;
                lVar8 = devm_kmalloc(lVar1,uVar13 << 5,0xdc0);
                sys_temp_dev[4] = lVar8;
                if (lVar8 == 0) {
                  pcVar11 = "Unable to alloc memory for sensor_listener\n";
LAB_0010082c:
                  _dev_err(lVar1,pcVar11);
                }
                else {
                  lVar17 = 0;
                  iVar4 = 0;
                  do {
                    iVar5 = of_property_read_string_helper
                                      (lVar12,"mmi,sensor-listener-names",lVar8 + lVar17 + 8,1,iVar4
                                      );
                    plVar7 = sys_temp_dev;
                    if (iVar5 < 0) {
                      pcVar11 = "Unable to read of_prop string\n";
                      goto LAB_0010082c;
                    }
                    *(undefined4 *)(sys_temp_dev[4] + lVar17 + 0x10) = 0;
                    if (*(long *)(plVar7[4] + lVar17 + 8) == 0) {
                      pcVar11 = "Invalid sensor listener name\n";
                      goto LAB_0010082c;
                    }
                    uVar9 = thermal_zone_get_zone_by_name();
                    plVar7 = sys_temp_dev;
                    *(undefined8 *)(sys_temp_dev[4] + lVar17) = uVar9;
                    lVar8 = plVar7[4];
                    if (0xfffffffffffff000 < *(ulong *)(lVar8 + lVar17)) {
                      _dev_err(lVar1,"thermal_zone_get_zone_by_name() failed.name %s, i %d\n",
                               *(undefined8 *)(lVar8 + lVar17 + 8),iVar4);
                      goto LAB_00100760;
                    }
                    iVar4 = iVar4 + 1;
                    lVar17 = lVar17 + 0x20;
                  } while (uVar13 * 0x20 != lVar17);
                  plVar7[5] = (long)psy_changed;
                  plVar7[8] = 0xfffffffe0;
                  plVar7[9] = (long)(plVar7 + 9);
                  plVar7[10] = (long)(plVar7 + 9);
                  plVar7[0xb] = (long)psy_changed_work_func;
                  power_supply_reg_notifier(plVar7 + 5);
                }
              }
LAB_00100760:
              iVar4 = 0;
            }
            else {
              _dev_err(lVar1,"Error registering device %d\n",iVar4);
              uVar15 = uVar14;
LAB_001007bc:
              if ((int)uVar15 != 0) {
                lVar12 = 0;
                do {
                  thermal_zone_device_unregister(*(undefined8 *)(sys_temp_dev[3] + lVar12));
                  lVar12 = lVar12 + 0x20;
                } while ((uVar15 & 0xffffffff) * 0x20 != lVar12);
              }
              devm_kfree(lVar1,sys_temp_dev);
            }
            goto LAB_00100764;
          }
          pcVar11 = "Unable to alloc memory for sensor\n";
        }
        _dev_err(lVar1,pcVar11);
        iVar4 = -0xc;
      }
    }
  }
LAB_00100764:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// mmi_sys_temp_remove @ 00100860 size=136
// signature: undefined mmi_sys_temp_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_sys_temp_remove(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  if (0 < *(int *)(lVar1 + 8)) {
    lVar2 = 0;
    lVar3 = 0;
    do {
      thermal_zone_device_unregister(*(undefined8 *)(*(long *)(lVar1 + 0x18) + lVar2));
      lVar3 = lVar3 + 1;
      lVar2 = lVar2 + 0x20;
    } while (lVar3 < *(int *)(lVar1 + 8));
  }
  misc_deregister(mmi_sys_temp_misc);
  *(undefined8 *)(param_1 + 0xa8) = 0;
  devm_kfree(param_1 + 0x10,sys_temp_dev);
  return 0;
}



//------------------------------------------------------------
// psy_changed_work_func @ 001008ec size=432
// signature: undefined psy_changed_work_func(void)
// callers: []
//------------------------------------------------------------

void psy_changed_work_func(void)

{
  int param4;
  int iVar1;
  char *param3;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  char acStack_470 [1024];
  long local_70;
  
  lVar7 = sp_el0;
  local_70 = *(long *)(lVar7 + 0x638);
  memset(acStack_470,0,0x400);
  if (sys_temp_dev != (long *)0x0) {
    uVar2 = *(uint *)((long)sys_temp_dev + 0xc);
    if (0 < (int)uVar2) {
      lVar7 = 0;
      iVar4 = 0;
      do {
        lVar5 = *(long *)(sys_temp_dev[4] + lVar7);
        if (lVar5 == 0) {
          _dev_err(*sys_temp_dev + 0x10,"Invalid thermal zone\n");
          goto LAB_00100938;
        }
        thermal_zone_get_temp(lVar5,sys_temp_dev[4] + lVar7 + 0x10);
        uevent_generate(sys_temp_dev,iVar4);
        iVar4 = iVar4 + 1;
        lVar7 = lVar7 + 0x20;
      } while ((ulong)uVar2 * 0x20 != lVar7);
      if (0 < (int)uVar2) {
        lVar7 = 0;
        uVar6 = 0;
        do {
          if (0x400 < uVar6) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100a98);
            (*pcVar3)();
          }
          iVar4 = *(int *)(sys_temp_dev[4] + lVar7 + 0x10);
          param3 = "-";
          if (-1 < iVar4) {
            param3 = "";
          }
          iVar1 = iVar4 / 1000;
          iVar4 = iVar4 % 1000;
          param4 = -iVar1;
          if (-1 < iVar1) {
            param4 = iVar1;
          }
          iVar1 = -iVar4;
          if (-1 < iVar4) {
            iVar1 = iVar4;
          }
          iVar4 = sprintf(acStack_470 + uVar6,"%s=%s%d.%d, ",*(char **)(sys_temp_dev[4] + lVar7 + 8)
                          ,param3,param4,iVar1);
          lVar7 = lVar7 + 0x20;
          uVar6 = iVar4 + uVar6;
        } while ((ulong)uVar2 * 0x20 != lVar7);
      }
    }
    _dev_info(*sys_temp_dev + 0x10,&DAT_00101784,acStack_470);
  }
LAB_00100938:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// psy_changed @ 00100aa0 size=72
// signature: undefined psy_changed(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 psy_changed(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  
  if (sys_temp_dev == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    if (param_2 == 0) {
      queue_work_on(0x20,_system_wq,sys_temp_dev + 0x40);
    }
    uVar1 = 1;
  }
  return uVar1;
}



//------------------------------------------------------------
// mmi_sys_temp_get @ 00100aec size=32
// signature: undefined mmi_sys_temp_get(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_sys_temp_get(long param_1,undefined4 *param_2)

{
  if (*(long *)(param_1 + 0x3f0) == 0) {
    return 0xffffffea;
  }
  *param_2 = *(undefined4 *)(*(long *)(param_1 + 0x3f0) + 0x10);
  return 0;
}



//------------------------------------------------------------
// mmi_sys_temp_ioctl @ 00100b10 size=588
// signature: undefined mmi_sys_temp_ioctl(void)
// callers: [mmi_sys_temp_compat_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void mmi_sys_temp_ioctl(undefined8 param_1,uint param_2,ulong param_3)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  int iVar4;
  size_t __n;
  undefined8 uVar5;
  undefined8 *puVar6;
  ulong uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_58 = 0;
  uStack_50 = 0;
  local_60 = 0;
  if (sys_temp_dev == (long *)0x0) {
    uVar5 = 0xffffffffffffffea;
    goto LAB_00100cc8;
  }
  if ((param_2 & 0xffff) != 0xdf00) {
    uVar5 = 0xffffffffffffffe7;
    goto LAB_00100cc8;
  }
  if (param_2 != 0x4018df00) {
    uVar5 = 0;
    goto LAB_00100cc8;
  }
  puVar6 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar6 + 0x46) >> 5 & 1) != 0) ||
     (uVar7 = param_3, ((uint)*puVar6 >> 0x1a & 1) != 0)) {
    uVar7 = param_3 & (long)(param_3 << 8) >> 8;
  }
  if (uVar7 < 0x7fffffffe9) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      puVar6 = (undefined8 *)puVar6[1];
      uVar2 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar6 & 0xffff000000000000 | uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar6;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    __n = __arch_copy_from_user(puVar6,&local_60,param_3 & 0xff7fffffffffffff,0x18);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar7 = daif;
      if ((uVar7 & 0x80) == 0) {
        uVar2 = daif;
        daif = uVar2 | 0xc0;
      }
      uVar2 = ttbr1_el1;
      ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar2 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar7;
    }
    if (__n != 0) goto LAB_00100cfc;
  }
  else {
    __n = 0x18;
LAB_00100cfc:
    memset((void *)((long)&local_48 - __n),0,__n);
    if ((int)__n != 0) {
      _dev_err(*sys_temp_dev + 0x10,"failed to copy_from_user\n");
      uVar5 = 0xfffffffffffffff3;
      goto LAB_00100cc8;
    }
  }
  plVar3 = sys_temp_dev;
  uVar8 = *(uint *)(sys_temp_dev + 1);
  if ((int)uVar8 < 1) {
    uVar7 = 0;
  }
  else {
    uVar7 = 0;
    puVar9 = (undefined4 *)(sys_temp_dev[3] + 0x10);
    do {
      iVar4 = strncasecmp(*(char **)(puVar9 + -2),(char *)((ulong)&local_60 | 4),0x14);
      if (iVar4 == 0) {
        *puVar9 = (undefined4)local_60;
        uevent_generate(plVar3,uVar7 & 0xffffffff);
        uVar8 = *(uint *)(sys_temp_dev + 1);
        goto LAB_00100cbc;
      }
      uVar7 = uVar7 + 1;
      puVar9 = puVar9 + 8;
    } while (uVar8 != uVar7);
    uVar7 = (ulong)uVar8;
  }
LAB_00100cbc:
  uVar5 = 0;
  if ((int)uVar8 <= (int)uVar7) {
    uVar5 = 0xffffffffffffffcb;
  }
LAB_00100cc8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// mmi_sys_temp_compat_ioctl @ 00100d78 size=32
// signature: undefined mmi_sys_temp_compat_ioctl(void)
// callers: []
//------------------------------------------------------------

void mmi_sys_temp_compat_ioctl(undefined8 param_1,undefined8 param_2,undefined4 param_3)

{
  mmi_sys_temp_ioctl(param_1,param_2,param_3);
  return;
}



//------------------------------------------------------------
// mmi_sys_temp_ioctl_open @ 00100d9c size=8
// signature: undefined mmi_sys_temp_ioctl_open(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_sys_temp_ioctl_open(void)

{
  return 0;
}



//------------------------------------------------------------
// mmi_sys_temp_ioctl_release @ 00100da8 size=8
// signature: undefined mmi_sys_temp_ioctl_release(void)
// callers: []
//------------------------------------------------------------

undefined8 mmi_sys_temp_ioctl_release(void)

{
  return 0;
}



//------------------------------------------------------------
// uevent_generate @ 00100db0 size=376
// signature: undefined uevent_generate(void)
// callers: [psy_changed_work_func, mmi_sys_temp_ioctl]
//------------------------------------------------------------

void uevent_generate(long *param_1,int param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = (long)param_2;
  lVar2 = param_1[3] + lVar3 * 0x20;
  if (((*(char *)(lVar2 + 0x14) != '\0') &&
      (iVar1 = *(int *)(lVar2 + 0x10), (int)param_1[2] <= iVar1)) &&
     (iVar1 / 1000 != *(int *)(param_1[3] + lVar3 * 0x20 + 0x18) / 1000)) {
    lVar2 = devm_kmalloc(*param_1 + 0x10,0xa20,0xdc0);
    if (lVar2 == 0) {
      _dev_err(*param_1 + 0x10,"%s: alloc uevent error\n","uevent_generate");
    }
    else {
      lVar3 = lVar3 * 0x20;
      *(undefined4 *)(param_1[3] + lVar3 + 0x18) = *(undefined4 *)(param_1[3] + lVar3 + 0x10);
      add_uevent_var(lVar2,"NAME=%s",*(undefined8 *)(param_1[3] + lVar3 + 8));
      add_uevent_var(lVar2,"TEMP=%d",*(undefined4 *)(param_1[3] + lVar3 + 0x10));
      add_uevent_var(lVar2,"TRIP=%d",0);
      kobject_uevent_env(*(long *)(param_1[3] + lVar3) + 0x18,2,lVar2 + 0x18);
      devm_kfree(*param_1 + 0x10,lVar2);
      _dev_info(*param_1 + 0x10,"trigger uevent index %i, temp %d pre_temp %d",param_2,
                *(undefined4 *)(param_1[3] + lVar3 + 0x10),
                *(undefined4 *)(param_1[3] + lVar3 + 0x18));
    }
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100f54 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&mmi_sys_temp_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100f84 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&mmi_sys_temp_driver);
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
// of_property_read_string_helper @ 00103010 size=1
// signature: undefined of_property_read_string_helper(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string_helper(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103018 size=1
// signature: undefined devm_kmalloc(void)
// callers: [mmi_sys_temp_probe, uevent_generate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_register @ 00103020 size=1
// signature: undefined thermal_zone_device_register(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00103028 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00103030 size=1
// signature: undefined _dev_info(void)
// callers: [mmi_sys_temp_probe, psy_changed_work_func, uevent_generate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strstr @ 00103038 size=1
// signature: char * strstr(char * __haystack, char * __needle)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strstr(char *__haystack,char *__needle)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00103040 size=1
// signature: undefined _dev_err(void)
// callers: [mmi_sys_temp_probe, psy_changed_work_func, uevent_generate, mmi_sys_temp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_register @ 00103048 size=1
// signature: undefined misc_register(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_get_zone_by_name @ 00103050 size=1
// signature: undefined thermal_zone_get_zone_by_name(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_get_zone_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// power_supply_reg_notifier @ 00103058 size=1
// signature: undefined power_supply_reg_notifier(void)
// callers: [mmi_sys_temp_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void power_supply_reg_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_device_unregister @ 00103060 size=1
// signature: undefined thermal_zone_device_unregister(void)
// callers: [mmi_sys_temp_probe, mmi_sys_temp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 00103068 size=1
// signature: undefined devm_kfree(void)
// callers: [mmi_sys_temp_probe, mmi_sys_temp_remove, uevent_generate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00103070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [mmi_sys_temp_probe, psy_changed_work_func, mmi_sys_temp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// misc_deregister @ 00103078 size=1
// signature: undefined misc_deregister(void)
// callers: [mmi_sys_temp_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void misc_deregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00103080 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [psy_changed_work_func, mmi_sys_temp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_zone_get_temp @ 00103088 size=1
// signature: undefined thermal_zone_get_temp(void)
// callers: [psy_changed_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_zone_get_temp(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00103090 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [psy_changed_work_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030a0 size=1
// signature: undefined queue_work_on(void)
// callers: [psy_changed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 001030b8 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [mmi_sys_temp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strncasecmp @ 001030c0 size=1
// signature: int strncasecmp(char * __s1, char * __s2, size_t __n)
// callers: [mmi_sys_temp_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strncasecmp(char *__s1,char *__s2,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_uevent_var @ 001030d0 size=1
// signature: undefined add_uevent_var(void)
// callers: [uevent_generate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_uevent_var(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_uevent_env @ 001030d8 size=1
// signature: undefined kobject_uevent_env(void)
// callers: [uevent_generate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_uevent_env(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



