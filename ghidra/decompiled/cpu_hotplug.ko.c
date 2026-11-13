// Decompiled by Ghidra 12.2
// Program: cpu_hotplug.ko
// Image base: 00100000

//------------------------------------------------------------
// cpu_hot_probe @ 00100224 size=700
// signature: undefined cpu_hot_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void cpu_hot_probe(long param_1)

{
  long lVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  long lVar7;
  undefined8 *puVar8;
  long lVar9;
  ulong uVar10;
  undefined8 uVar11;
  char *local_c0;
  long local_b8 [11];
  
  lVar7 = sp_el0;
  local_b8[10] = *(long *)(lVar7 + 0x638);
  uVar11 = *(undefined8 *)(param_1 + 0x2f8);
  local_c0 = (char *)0x0;
  cpu_hot_cdev_list = (undefined *)&cpu_hot_cdev_list;
  PTR_cpu_hot_cdev_list_00100af0 = (undefined *)&cpu_hot_cdev_list;
  lVar7 = of_get_next_available_child(uVar11,0);
  if (lVar7 != 0) {
    do {
      puVar8 = (undefined8 *)devm_kmalloc(param_1 + 0x10,0xa0,0xdc0);
      if (puVar8 == (undefined8 *)0x0) {
        uVar11 = 0xfffffff4;
        goto LAB_0010048c;
      }
      puVar8[3] = 0;
      puVar8[4] = lVar7;
      *(undefined4 *)(puVar8 + 2) = 0xffffffff;
      local_b8[8] = 0;
      local_b8[9] = 0;
      *(undefined2 *)((long)puVar8 + 0x14) = 0x100;
      local_b8[6] = 0;
      local_b8[7] = 0;
      local_b8[4] = 0;
      local_b8[5] = 0;
      local_b8[2] = 0;
      local_b8[3] = 0;
      local_b8[0] = 0;
      local_b8[1] = 0;
      iVar4 = __of_parse_phandle_with_args(lVar7,"qcom,cpu",0,0,0,local_b8);
      iVar6 = 0;
      lVar1 = local_b8[0];
      if (iVar4 != 0) {
        lVar1 = 0;
      }
      while (uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar6),
            uVar5 < _nr_cpu_ids) {
        lVar9 = get_cpu_device(uVar5);
        if ((lVar9 != 0) && (*(long *)(lVar9 + 0x2e8) == lVar1)) {
          *(uint *)(puVar8 + 2) = uVar5;
          goto LAB_00100384;
        }
        iVar6 = uVar5 + 1;
      }
      if (*(int *)(puVar8 + 2) == -1) {
        _dev_err(param_1 + 0x10,"Invalid CPU phandle\n");
      }
      else {
LAB_00100384:
        iVar6 = of_property_read_string(lVar7,"qcom,cdev-alias",&local_c0);
        pcVar3 = local_c0;
        if (iVar6 == 0) {
          uVar10 = strnlen(local_c0,0x14);
          if (uVar10 == 0xffffffffffffffff) {
            fortify_panic("strnlen");
          }
          else {
            if (uVar10 != 0x14) {
              uVar10 = uVar10 + 1;
            }
            if (uVar10 < 0x15) {
              strscpy(puVar8 + 5,pcVar3);
              goto LAB_001003f0;
            }
          }
          uVar11 = fortify_panic("strscpy");
          goto LAB_001004dc;
        }
        snprintf((char *)(puVar8 + 5),0x14,"cpu-hotplug%d",*(int *)(puVar8 + 2));
LAB_001003f0:
        puVar8[8] = 0xfffffffe0;
        puVar8[9] = puVar8 + 9;
        puVar8[10] = puVar8 + 9;
        puVar8[0xe] = 0xfffffffe0;
        puVar8[0xb] = cpu_hot_register_cdev;
        puVar8[0xf] = puVar8 + 0xf;
        puVar8[0x10] = puVar8 + 0xf;
        puVar2 = cpu_hot_cdev_list;
        puVar8[0x11] = cpu_hot_execute_cdev;
        uVar10 = __list_add_valid(puVar8,&cpu_hot_cdev_list,puVar2);
        if ((uVar10 & 1) != 0) {
          *(undefined8 **)(puVar2 + 8) = puVar8;
          *puVar8 = puVar2;
          puVar8[1] = &cpu_hot_cdev_list;
          cpu_hot_cdev_list = (undefined *)puVar8;
        }
      }
      lVar7 = of_get_next_available_child(uVar11,lVar7);
    } while (lVar7 != 0);
  }
  uVar11 = __cpuhp_setup_state(200,"cpu-hotplug/cdev:online",1,cpu_hot_hp_online,0,0);
  iVar6 = (int)uVar11;
  if (-1 < iVar6) {
    uVar11 = 0;
    cpu_hp_online = iVar6;
  }
LAB_0010048c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) == local_b8[10]) {
    return;
  }
LAB_001004dc:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar11);
}



//------------------------------------------------------------
// cpu_hot_remove @ 001004e4 size=248
// signature: undefined cpu_hot_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 cpu_hot_remove(void)

{
  undefined *puVar1;
  long *plVar2;
  int iVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  if (cpu_hp_online != 0) {
    __cpuhp_remove_state(cpu_hp_online,0);
    cpu_hp_online = 0;
  }
  mutex_lock(cpu_hot_lock);
  ppuVar5 = (undefined **)cpu_hot_cdev_list;
  if ((undefined **)cpu_hot_cdev_list != &cpu_hot_cdev_list) {
    do {
      ppuVar6 = (undefined **)*ppuVar5;
      if ((ppuVar5[3] != (undefined *)0x0) &&
         (thermal_cooling_device_unregister(), *(char *)((long)ppuVar5 + 0x14) != '\0')) {
        *(undefined1 *)((long)ppuVar5 + 0x14) = 0;
        iVar3 = add_cpu(*(undefined4 *)(ppuVar5 + 2));
        if (iVar3 != 0) {
          _printk(&DAT_00100ba9,*(undefined4 *)(ppuVar5 + 2),iVar3);
        }
      }
      uVar4 = __list_del_entry_valid(ppuVar5);
      if ((uVar4 & 1) != 0) {
        puVar1 = *ppuVar5;
        plVar2 = (long *)ppuVar5[1];
        *(long **)(puVar1 + 8) = plVar2;
        *plVar2 = (long)puVar1;
      }
      *ppuVar5 = (undefined *)0xdead000000000100;
      ppuVar5[1] = (undefined *)0xdead000000000122;
      ppuVar5 = ppuVar6;
    } while (ppuVar6 != &cpu_hot_cdev_list);
  }
  mutex_unlock(cpu_hot_lock);
  return 0;
}



//------------------------------------------------------------
// cpu_hot_register_cdev @ 001005e0 size=104
// signature: undefined cpu_hot_register_cdev(void)
// callers: []
//------------------------------------------------------------

void cpu_hot_register_cdev(long param_1)

{
  ulong uVar1;
  
  uVar1 = thermal_of_cooling_device_register
                    (*(undefined8 *)(param_1 + -0x20),param_1 + -0x18,param_1 + -0x40,
                     &cpu_hot_cooling_ops);
  *(ulong *)(param_1 + -0x28) = uVar1;
  if (0xfffffffffffff000 < uVar1) {
    _printk(&DAT_00100bc3,param_1 + -0x18,uVar1);
    *(undefined8 *)(param_1 + -0x28) = 0;
  }
  return;
}



//------------------------------------------------------------
// cpu_hot_execute_cdev @ 0010064c size=224
// signature: undefined cpu_hot_execute_cdev(void)
// callers: []
//------------------------------------------------------------

void cpu_hot_execute_cdev(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  mutex_lock(cpu_hot_lock);
  uVar1 = *(undefined4 *)(param_1 + -0x60);
  if (*(char *)(param_1 + -0x5c) == '\0') {
    if (*(char *)(param_1 + -0x5b) != '\0') goto LAB_001006e8;
    mutex_unlock(cpu_hot_lock);
    iVar2 = add_cpu(uVar1);
    mutex_lock(cpu_hot_lock);
    if (iVar2 == 0) {
      *(undefined1 *)(param_1 + -0x5b) = 1;
      goto LAB_001006e8;
    }
    puVar3 = &DAT_00100ba9;
  }
  else {
    if (*(char *)(param_1 + -0x5b) == '\0') goto LAB_001006e8;
    mutex_unlock(cpu_hot_lock);
    iVar2 = remove_cpu(uVar1);
    mutex_lock(cpu_hot_lock);
    if (-1 < iVar2) {
      *(undefined1 *)(param_1 + -0x5b) = 0;
      goto LAB_001006e8;
    }
    puVar3 = &DAT_00100b8e;
  }
  _printk(puVar3,uVar1,iVar2);
LAB_001006e8:
  mutex_unlock(cpu_hot_lock);
  return;
}



//------------------------------------------------------------
// cpu_hot_hp_online @ 00100730 size=152
// signature: undefined cpu_hot_hp_online(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 cpu_hot_hp_online(int param_1)

{
  undefined4 uVar1;
  undefined **ppuVar2;
  
  mutex_lock(cpu_hot_lock);
  ppuVar2 = &cpu_hot_cdev_list;
  do {
    ppuVar2 = (undefined **)*ppuVar2;
    if (ppuVar2 == &cpu_hot_cdev_list) goto LAB_001007a4;
  } while (*(int *)(ppuVar2 + 2) != param_1);
  if (ppuVar2[3] == (undefined *)0x0) {
    queue_work_on(0x20,_system_highpri_wq,ppuVar2 + 8);
LAB_001007a4:
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (*(char *)((long)ppuVar2 + 0x14) != '\0') {
      uVar1 = 0x8002;
    }
  }
  mutex_unlock(cpu_hot_lock);
  return uVar1;
}



//------------------------------------------------------------
// cpu_hot_get_max_state @ 001007cc size=16
// signature: undefined cpu_hot_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cpu_hot_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}



//------------------------------------------------------------
// cpu_hot_get_cur_state @ 001007e0 size=84
// signature: undefined cpu_hot_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 cpu_hot_get_cur_state(long param_1,ulong *param_2)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x3b0);
  mutex_lock(cpu_hot_lock);
  *param_2 = (ulong)*(byte *)(lVar1 + 0x14);
  mutex_unlock(cpu_hot_lock);
  return 0;
}



//------------------------------------------------------------
// cpu_hot_set_cur_state @ 00100838 size=152
// signature: undefined cpu_hot_set_cur_state(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cpu_hot_set_cur_state(long param_1,ulong param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x3b0);
  if (*(int *)(lVar2 + 0x10) == -1) {
    uVar1 = 0xffffffed;
  }
  else if (param_2 < 2) {
    if ((bool)*(char *)(lVar2 + 0x14) != (param_2 != 0)) {
      mutex_lock(cpu_hot_lock);
      *(bool *)(lVar2 + 0x14) = param_2 != 0;
      mutex_unlock(cpu_hot_lock);
      queue_work_on(0x20,_system_highpri_wq,lVar2 + 0x70);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// init_module @ 001008d4 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&cpu_hot_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100904 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&cpu_hot_driver);
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
// of_get_next_available_child @ 00102010 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102028 size=1
// signature: undefined _dev_err(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00102030 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00102038 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00102040 size=1
// signature: undefined _find_next_bit(void)
// callers: [cpu_hot_probe]
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
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00102050 size=1
// signature: undefined of_property_read_string(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00102058 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00102060 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00102068 size=1
// signature: undefined strscpy(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00102070 size=1
// signature: undefined __list_add_valid(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 00102078 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00102080 size=1
// signature: undefined fortify_panic(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102088 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cpu_hot_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 00102090 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [cpu_hot_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102098 size=1
// signature: undefined mutex_lock(void)
// callers: [cpu_hot_set_cur_state, cpu_hot_remove, cpu_hot_hp_online, cpu_hot_get_cur_state, cpu_hot_execute_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 001020a0 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [cpu_hot_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_cpu @ 001020a8 size=1
// signature: undefined add_cpu(void)
// callers: [cpu_hot_remove, cpu_hot_execute_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 001020b0 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cpu_hot_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001020b8 size=1
// signature: undefined _printk(void)
// callers: [cpu_hot_remove, cpu_hot_register_cdev, cpu_hot_execute_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001020c0 size=1
// signature: undefined mutex_unlock(void)
// callers: [cpu_hot_set_cur_state, cpu_hot_remove, cpu_hot_hp_online, cpu_hot_get_cur_state, cpu_hot_execute_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 001020c8 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [cpu_hot_register_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// remove_cpu @ 001020d0 size=1
// signature: undefined remove_cpu(void)
// callers: [cpu_hot_execute_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void remove_cpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001020e0 size=1
// signature: undefined queue_work_on(void)
// callers: [cpu_hot_set_cur_state, cpu_hot_hp_online]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



