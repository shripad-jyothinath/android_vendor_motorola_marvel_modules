// Decompiled by Ghidra 12.2
// Program: qti_devfreq_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// devfreq_cdev_probe @ 0010018c size=288
// signature: undefined devfreq_cdev_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void devfreq_cdev_probe(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  devfreq_cdev = (undefined8 *)devm_kmalloc(param_1 + 0x10,0x110,0xdc0);
  if (devfreq_cdev == (undefined8 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    local_38 = 0;
    uStack_30 = 0;
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
    iVar3 = __of_parse_phandle_with_args
                      (*(undefined8 *)(param_1 + 0x2f8),"qcom,devfreq",0,0,0,&local_78);
    puVar2 = devfreq_cdev;
    uVar4 = local_78;
    if (iVar3 != 0) {
      uVar4 = 0;
    }
    *(undefined4 *)(devfreq_cdev + 5) = 0x14;
    *puVar2 = uVar4;
    puVar2[0x10] = 0xfffffffe0;
    puVar2[0x11] = puVar2 + 0x11;
    puVar2[0x12] = puVar2 + 0x11;
    puVar2[0x13] = devfreq_cdev_work;
    init_timer_key(puVar2 + 0x16,&delayed_work_timer_fn,0x280000,0,0);
    queue_delayed_work_on(0x20,_system_highpri_wq,devfreq_cdev + 0x10,0);
    uVar4 = 0;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// devfreq_cdev_remove @ 001002b0 size=88
// signature: undefined devfreq_cdev_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 devfreq_cdev_remove(void)

{
  if (*(long *)(devfreq_cdev + 0x108) != 0) {
    thermal_cooling_device_unregister();
    dev_pm_qos_remove_request(devfreq_cdev + 0x30);
    kfree(*(undefined8 *)(devfreq_cdev + 0x18));
    *(undefined8 *)(devfreq_cdev + 0x108) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// devfreq_cdev_work @ 0010030c size=464
// signature: undefined devfreq_cdev_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void devfreq_cdev_work(long param_1)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  ulong uVar8;
  long local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  uVar4 = devfreq_get_devfreq_by_node(*(undefined8 *)(param_1 + -0x80));
  if (uVar4 < 0xfffffffffffff001) {
    uVar7 = *(undefined8 *)(uVar4 + 0xa0);
    *(ulong *)(param_1 + -0x78) = uVar4;
    *(undefined8 *)(param_1 + -0x70) = uVar7;
    uVar2 = dev_pm_opp_get_opp_count(uVar7);
    if (-1 < (int)uVar2) {
      uVar4 = -(ulong)(uVar2 >> 0x1f) & 0xfffffff800000000 | (ulong)uVar2 << 3;
      lVar5 = __kmalloc(uVar4,0xdc0);
      if (lVar5 != 0) {
        local_60 = -1;
        if (uVar2 != 0) {
          uVar8 = 0;
          do {
            uVar6 = dev_pm_opp_find_freq_floor(*(undefined8 *)(param_1 + -0x70),&local_60);
            if (0xfffffffffffff000 < uVar6) goto LAB_00100490;
            dev_pm_opp_put();
            if (((long)uVar8 < 0) || (uVar4 <= uVar8)) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(1,0x1004d8);
              (*pcVar1)();
            }
            uVar6 = local_60 + 999;
            local_60 = local_60 + -1;
            *(ulong *)(lVar5 + uVar8) = uVar6 / 1000;
            uVar8 = uVar8 + 8;
          } while ((ulong)uVar2 * 8 != uVar8);
        }
        *(long *)(param_1 + -0x68) = lVar5;
        *(uint *)(param_1 + -0x5c) = uVar2 - 1;
        iVar3 = dev_pm_qos_add_request
                          (*(undefined8 *)(param_1 + -0x70),param_1 + -0x50,4,0x7fffffff);
        if (-1 < iVar3) {
          uVar4 = thermal_cooling_device_register
                            (&DAT_00100830,(undefined8 *)(param_1 + -0x80),&devfreq_cdev_ops);
          *(ulong *)(param_1 + 0x88) = uVar4;
          if (uVar4 < 0xfffffffffffff001) goto LAB_001004a0;
          _printk(&DAT_00100834,"qti_devfreq_cdev","devfreq_cdev_work",uVar4);
          *(undefined8 *)(param_1 + 0x88) = 0;
        }
LAB_00100490:
        kfree(*(undefined8 *)(param_1 + -0x68));
        dev_pm_qos_remove_request(param_1 + -0x50);
      }
    }
  }
  else {
    iVar3 = *(int *)(param_1 + -0x58) + -1;
    *(int *)(param_1 + -0x58) = iVar3;
    if (iVar3 != 0) {
      queue_delayed_work_on(0x20,_system_highpri_wq,param_1,0xfa);
    }
  }
LAB_001004a0:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// devfreq_cdev_get_max_state @ 001004e0 size=20
// signature: undefined devfreq_cdev_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 devfreq_cdev_get_max_state(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x24);
  return 0;
}



//------------------------------------------------------------
// devfreq_cdev_get_state @ 001004f8 size=20
// signature: undefined devfreq_cdev_get_state(void)
// callers: []
//------------------------------------------------------------

undefined8 devfreq_cdev_get_state(long param_1,long *param_2)

{
  *param_2 = (long)*(int *)(*(long *)(param_1 + 0x3b0) + 0x20);
  return 0;
}



//------------------------------------------------------------
// devfreq_cdev_set_state @ 00100510 size=184
// signature: undefined devfreq_cdev_set_state(void)
// callers: []
//------------------------------------------------------------

int devfreq_cdev_set_state(long param_1,ulong param_2)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3b0);
  if ((ulong)(long)*(int *)(lVar3 + 0x24) < param_2) {
    iVar1 = -0x16;
  }
  else if ((long)*(int *)(lVar3 + 0x20) == param_2) {
    iVar1 = 0;
  }
  else {
    uVar2 = *(ulong *)(*(long *)(lVar3 + 0x18) + param_2 * 8);
    iVar1 = dev_pm_qos_update_request(lVar3 + 0x30,uVar2 & 0xffffffff);
    if (iVar1 < 0) {
      _printk(&DAT_001008bb,"qti_devfreq_cdev","devfreq_cdev_set_state",uVar2,
              *(undefined8 *)(param_1 + 8),iVar1);
    }
    else {
      iVar1 = 0;
      *(int *)(lVar3 + 0x20) = (int)param_2;
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 001005cc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&devfreq_cdev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001005fc size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&devfreq_cdev_driver);
  return;
}



//------------------------------------------------------------
// __platform_driver_register @ 00102000 size=1
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
// platform_driver_unregister @ 00102008 size=1
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [devfreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102018 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [devfreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00102028 size=1
// signature: undefined init_timer_key(void)
// callers: [devfreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00102038 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [devfreq_cdev_work, devfreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102040 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [devfreq_cdev_work, devfreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00102048 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [devfreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_remove_request @ 00102050 size=1
// signature: undefined dev_pm_qos_remove_request(void)
// callers: [devfreq_cdev_remove, devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102058 size=1
// signature: undefined kfree(void)
// callers: [devfreq_cdev_remove, devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devfreq_get_devfreq_by_node @ 00102060 size=1
// signature: undefined devfreq_get_devfreq_by_node(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devfreq_get_devfreq_by_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_get_opp_count @ 00102068 size=1
// signature: undefined dev_pm_opp_get_opp_count(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_get_opp_count(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00102070 size=1
// signature: undefined __kmalloc(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_find_freq_floor @ 00102078 size=1
// signature: undefined dev_pm_opp_find_freq_floor(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_find_freq_floor(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_opp_put @ 00102080 size=1
// signature: undefined dev_pm_opp_put(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_opp_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_add_request @ 00102088 size=1
// signature: undefined dev_pm_qos_add_request(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_register @ 00102090 size=1
// signature: undefined thermal_cooling_device_register(void)
// callers: [devfreq_cdev_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102098 size=1
// signature: undefined _printk(void)
// callers: [devfreq_cdev_work, devfreq_cdev_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_pm_qos_update_request @ 001020a0 size=1
// signature: undefined dev_pm_qos_update_request(void)
// callers: [devfreq_cdev_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_pm_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



