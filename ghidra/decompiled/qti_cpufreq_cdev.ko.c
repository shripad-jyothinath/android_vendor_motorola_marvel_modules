// Decompiled by Ghidra 12.2
// Program: qti_cpufreq_cdev.ko
// Image base: 00100000

//------------------------------------------------------------
// cpufreq_cdev_probe @ 001001d4 size=528
// signature: undefined cpufreq_cdev_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cpufreq_cdev_probe(long param_1)

{
  long lVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  undefined8 *puVar5;
  long lVar6;
  undefined8 *puVar7;
  ulong uVar8;
  undefined8 uVar9;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar9 = *(undefined8 *)(param_1 + 0x2f8);
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  uStack_80 = 0;
  local_98 = 0;
  uStack_90 = 0;
  local_a8 = 0;
  uStack_a0 = 0;
  mutex_lock(qti_cpufreq_cdev_lock);
  puVar5 = (undefined8 *)of_get_next_available_child(uVar9,0);
  if (puVar5 != (undefined8 *)0x0) {
    do {
      of_phandle_iterator_init(&local_a8,puVar5,"qcom,cpus",0,0);
      while (iVar3 = of_phandle_iterator_next(&local_a8), lVar1 = local_70, iVar3 == 0) {
        iVar3 = 0;
        while( true ) {
          uVar4 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar3);
          if (_nr_cpu_ids <= uVar4) break;
          lVar6 = get_cpu_device(uVar4);
          if ((lVar6 != 0) && (*(long *)(lVar6 + 0x2e8) == lVar1)) {
            puVar7 = (undefined8 *)devm_kmalloc(param_1 + 0x10,200,0xdc0);
            if (puVar7 != (undefined8 *)0x0) {
              *(uint *)(puVar7 + 3) = uVar4;
              snprintf((char *)(puVar7 + 0xf),0x14,(char *)*puVar5);
              puVar7[0x13] = 0xfffffffe0;
              puVar7[0x14] = puVar7 + 0x14;
              puVar7[0x15] = puVar7 + 0x14;
              puVar2 = qti_cpufreq_cdev_list;
              puVar7[0x16] = cpufreq_cdev_register;
              uVar8 = __list_add_valid(puVar7,&qti_cpufreq_cdev_list,puVar2);
              if ((uVar8 & 1) != 0) {
                *(undefined8 **)(puVar2 + 8) = puVar7;
                *puVar7 = puVar2;
                puVar7[1] = &qti_cpufreq_cdev_list;
                qti_cpufreq_cdev_list = (undefined *)puVar7;
              }
              goto LAB_00100268;
            }
            mutex_unlock(qti_cpufreq_cdev_lock);
            uVar9 = 0xfffffff4;
            goto LAB_001003a8;
          }
          iVar3 = uVar4 + 1;
        }
      }
LAB_00100268:
      puVar5 = (undefined8 *)of_get_next_available_child(uVar9,puVar5);
    } while (puVar5 != (undefined8 *)0x0);
  }
  mutex_unlock(qti_cpufreq_cdev_lock);
  uVar9 = __cpuhp_setup_state(200,"thermal-cpu/cdev:online",1,cpufreq_cdev_hp_online,0,0);
  iVar3 = (int)uVar9;
  if (-1 < iVar3) {
    uVar9 = 0;
    cpu_hp_online = iVar3;
  }
LAB_001003a8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// cpufreq_cdev_remove @ 001003e8 size=172
// signature: undefined cpufreq_cdev_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cpufreq_cdev_remove(void)

{
  undefined **ppuVar1;
  
  mutex_lock(qti_cpufreq_cdev_lock);
  if (cpu_hp_online != 0) {
    __cpuhp_remove_state(cpu_hp_online,0);
    cpu_hp_online = 0;
  }
  for (ppuVar1 = (undefined **)qti_cpufreq_cdev_list; ppuVar1 != &qti_cpufreq_cdev_list;
      ppuVar1 = (undefined **)*ppuVar1) {
    if (ppuVar1[2] != (undefined *)0x0) {
      thermal_cooling_device_unregister();
      if ((ppuVar1[0xd] != (undefined *)0x0) && (ppuVar1[0xd] < (undefined *)0xfffffffffffff001)) {
        freq_qos_remove_request(ppuVar1 + 7);
      }
      ppuVar1[2] = (undefined *)0x0;
      cpufreq_cpu_put(ppuVar1[0x12]);
      kfree(ppuVar1[6]);
    }
  }
  mutex_unlock(qti_cpufreq_cdev_lock);
  return 0;
}



//------------------------------------------------------------
// cpufreq_cdev_register @ 00100498 size=428
// signature: undefined cpufreq_cdev_register(void)
// callers: []
//------------------------------------------------------------

void cpufreq_cdev_register(long param_1)

{
  long lVar1;
  long lVar2;
  undefined4 uVar3;
  int *piVar4;
  ulong uVar5;
  int iVar6;
  ulong uVar7;
  int iVar8;
  ulong uVar9;
  
  lVar1 = cpufreq_cpu_get(*(undefined4 *)(param_1 + -0x80));
  if (lVar1 == 0) {
    _printk(&DAT_00100ac7,"qti_cpufreq_cdev","cpufreq_cdev_register",
            *(undefined4 *)(param_1 + -0x80));
    return;
  }
  if (*(long *)(lVar1 + 400) != 0) {
    uVar9 = 0;
    piVar4 = (int *)(*(long *)(lVar1 + 400) + 8);
    do {
      if (*piVar4 != -1) {
        iVar8 = (int)uVar9;
        if (*piVar4 == -2) goto LAB_001004fc;
        uVar9 = (ulong)(iVar8 + 1);
      }
      piVar4 = piVar4 + 3;
    } while( true );
  }
LAB_001005e4:
  cpufreq_cpu_put(lVar1);
  if (*(long *)(param_1 + -0x88) != 0) {
    *(undefined8 *)(param_1 + -0x88) = 0;
  }
  kfree(*(undefined8 *)(param_1 + -0x68));
  return;
LAB_001004fc:
  if (iVar8 != 0) {
    if (iVar8 < 0) {
      *(undefined8 *)(param_1 + -0x68) = 0;
    }
    else {
      lVar2 = __kmalloc(-(uVar9 >> 0x1f) & 0xfffffffc00000000 | uVar9 << 2,0xcc0);
      *(long *)(param_1 + -0x68) = lVar2;
      if (lVar2 != 0) {
        uVar5 = 0;
        iVar6 = iVar8 + -1;
        do {
          uVar7 = (ulong)iVar6;
          iVar6 = iVar6 + -1;
          if (*(int *)(lVar1 + 0x198) != 1) {
            uVar7 = uVar5;
          }
          *(undefined4 *)(*(long *)(param_1 + -0x68) + uVar5 * 4) =
               *(undefined4 *)(*(long *)(lVar1 + 400) + uVar7 * 0xc + 8);
          uVar5 = uVar5 + 1;
        } while (uVar9 != uVar5);
        *(long *)(param_1 + -8) = lVar1;
        *(undefined8 *)(param_1 + -0x78) = 0;
        *(long *)(param_1 + -0x70) = (long)(iVar8 + -1);
        if (*(undefined4 **)(param_1 + -0x68) == (undefined4 *)0x0) {
          uVar3 = 0xffffffff;
        }
        else {
          uVar3 = **(undefined4 **)(param_1 + -0x68);
        }
        freq_qos_add_request(lVar1 + 0xa0,param_1 + -0x60,2,uVar3);
        uVar9 = thermal_cooling_device_register(param_1 + -0x20,param_1 + -0x98,&cpufreq_cdev_ops);
        *(ulong *)(param_1 + -0x88) = uVar9;
        if (uVar9 < 0xfffffffffffff001) {
          return;
        }
        _printk(&DAT_00100b4e,"qti_cpufreq_cdev","cpufreq_cdev_register",param_1 + -0x20,uVar9);
        freq_qos_remove_request(param_1 + -0x60);
      }
    }
  }
  goto LAB_001005e4;
}



//------------------------------------------------------------
// cpufreq_cdev_hp_online @ 00100648 size=152
// signature: undefined cpufreq_cdev_hp_online(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cpufreq_cdev_hp_online(int param_1)

{
  undefined **ppuVar1;
  
  mutex_lock(qti_cpufreq_cdev_lock);
  ppuVar1 = (undefined **)qti_cpufreq_cdev_list;
  if ((undefined **)qti_cpufreq_cdev_list != &qti_cpufreq_cdev_list) {
    do {
      if ((*(int *)(ppuVar1 + 3) == param_1) && (ppuVar1[2] == (undefined *)0x0)) {
        queue_work_on(0x20,_system_highpri_wq,ppuVar1 + 0x13);
      }
      ppuVar1 = (undefined **)*ppuVar1;
    } while (ppuVar1 != &qti_cpufreq_cdev_list);
  }
  mutex_unlock(qti_cpufreq_cdev_lock);
  return 0;
}



//------------------------------------------------------------
// cpufreq_cdev_get_max_state @ 001006e4 size=20
// signature: undefined cpufreq_cdev_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cpufreq_cdev_get_max_state(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(long *)(param_1 + 0x3b0) + 0x28);
  return 0;
}



//------------------------------------------------------------
// cpufreq_cdev_get_state @ 001006fc size=20
// signature: undefined cpufreq_cdev_get_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cpufreq_cdev_get_state(long param_1,undefined8 *param_2)

{
  *param_2 = *(undefined8 *)(*(long *)(param_1 + 0x3b0) + 0x20);
  return 0;
}



//------------------------------------------------------------
// cpufreq_cdev_set_state @ 00100714 size=212
// signature: undefined cpufreq_cdev_set_state(void)
// callers: []
//------------------------------------------------------------

int cpufreq_cdev_set_state(long param_1,ulong param_2)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3b0);
  if (*(ulong *)(lVar3 + 0x28) < param_2) {
    iVar1 = -0x16;
  }
  else if (*(ulong *)(lVar3 + 0x20) == param_2) {
    iVar1 = 0;
  }
  else {
    if ((*(ulong *)(lVar3 + 0x68) != 0) && (*(ulong *)(lVar3 + 0x68) < 0xfffffffffffff001)) {
      if (*(long *)(lVar3 + 0x30) == 0) {
        uVar2 = 0xffffffff;
      }
      else {
        uVar2 = *(undefined4 *)(*(long *)(lVar3 + 0x30) + param_2 * 4);
      }
      iVar1 = freq_qos_update_request(lVar3 + 0x38,uVar2);
      if (iVar1 < 0) {
        _printk(&DAT_00100aef,"qti_cpufreq_cdev","cpufreq_cdev_set_state",uVar2,
                *(undefined8 *)(param_1 + 8),iVar1);
        return iVar1;
      }
    }
    iVar1 = 0;
    *(ulong *)(lVar3 + 0x20) = param_2;
  }
  return iVar1;
}



//------------------------------------------------------------
// init_module @ 001007ec size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cpufreq_cdev_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010081c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cpufreq_cdev_driver);
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
// mutex_lock @ 00102010 size=1
// signature: undefined mutex_lock(void)
// callers: [cpufreq_cdev_probe, cpufreq_cdev_remove, cpufreq_cdev_hp_online]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00102018 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_init @ 00102030 size=1
// signature: undefined of_phandle_iterator_init(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_next @ 00102038 size=1
// signature: undefined of_phandle_iterator_next(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00102040 size=1
// signature: undefined _find_next_bit(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 00102048 size=1
// signature: undefined get_cpu_device(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102050 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00102058 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102060 size=1
// signature: undefined __list_add_valid(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00102068 size=1
// signature: undefined mutex_unlock(void)
// callers: [cpufreq_cdev_probe, cpufreq_cdev_remove, cpufreq_cdev_hp_online]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 00102070 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102078 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cpufreq_cdev_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 00102080 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [cpufreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_put @ 00102088 size=1
// signature: undefined cpufreq_cpu_put(void)
// callers: [cpufreq_cdev_register, cpufreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102090 size=1
// signature: undefined kfree(void)
// callers: [cpufreq_cdev_register, cpufreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00102098 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [cpufreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_remove_request @ 001020a0 size=1
// signature: undefined freq_qos_remove_request(void)
// callers: [cpufreq_cdev_register, cpufreq_cdev_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 001020a8 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [cpufreq_cdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 001020b0 size=1
// signature: undefined __kmalloc(void)
// callers: [cpufreq_cdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 001020b8 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [cpufreq_cdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_register @ 001020c0 size=1
// signature: undefined thermal_cooling_device_register(void)
// callers: [cpufreq_cdev_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001020c8 size=1
// signature: undefined _printk(void)
// callers: [cpufreq_cdev_register, cpufreq_cdev_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001020d8 size=1
// signature: undefined queue_work_on(void)
// callers: [cpufreq_cdev_hp_online]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_update_request @ 001020e0 size=1
// signature: undefined freq_qos_update_request(void)
// callers: [cpufreq_cdev_set_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



