// Decompiled by Ghidra 12.2
// Program: thermal_pause.ko
// Image base: 00100000

//------------------------------------------------------------
// thermal_pause_notifier_register @ 001002e4 size=40
// signature: undefined thermal_pause_notifier_register(void)
// callers: []
//------------------------------------------------------------

void thermal_pause_notifier_register(undefined8 param_1)

{
  blocking_notifier_chain_register(&thermal_pause_notifier,param_1);
  return;
}



//------------------------------------------------------------
// thermal_pause_notifier_unregister @ 00100310 size=40
// signature: undefined thermal_pause_notifier_unregister(void)
// callers: []
//------------------------------------------------------------

void thermal_pause_notifier_unregister(undefined8 param_1)

{
  blocking_notifier_chain_unregister(&thermal_pause_notifier,param_1);
  return;
}



//------------------------------------------------------------
// thermal_paused_cpumask @ 0010033c size=12
// signature: undefined thermal_paused_cpumask(void)
// callers: []
//------------------------------------------------------------

undefined1 * thermal_paused_cpumask(void)

{
  return &cpus_in_max_cooling_level;
}



//------------------------------------------------------------
// thermal_pause_probe @ 0010034c size=952
// signature: undefined thermal_pause_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thermal_pause_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  undefined *puVar4;
  char *pcVar5;
  long lVar6;
  int iVar7;
  long lVar8;
  ulong uVar9;
  undefined8 *puVar10;
  long lVar11;
  undefined8 uVar12;
  ulong uVar13;
  uint uVar14;
  char *local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  long local_78;
  ulong local_70 [2];
  
  lVar8 = sp_el0;
  local_70[1] = *(long *)(lVar8 + 0x638);
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  uStack_88 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_70[0] = 0;
  local_b8 = (char *)0x0;
  iVar7 = tracepoint_probe_register
                    (&__tracepoint_android_vh_disable_thermal_cooling_stats,disable_cdev_stats,0);
  if (iVar7 != 0) {
    _printk(&DAT_00101168,"thermal_pause","thermal_vendor_hooks_init");
  }
  thermal_pause_cdev_list = (undefined *)&thermal_pause_cdev_list;
  PTR_thermal_pause_cdev_list_00100fe8 = (undefined *)&thermal_pause_cdev_list;
  uVar14 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
  if (uVar14 < 9) {
    memset(&cpus_in_max_cooling_level,0,(ulong)uVar14);
    lVar8 = of_get_next_available_child(uVar12,0);
    if (lVar8 != 0) {
      do {
        uVar14 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
        if (8 < uVar14) goto LAB_001006dc;
        memset(local_70,0,(ulong)uVar14);
        of_phandle_iterator_init(&local_b0,lVar8,"qcom,cpus",0,0);
        iVar7 = of_phandle_iterator_next(&local_b0);
        uVar14 = 0;
        if (iVar7 == 0) {
          uVar9 = 0;
          do {
            lVar6 = local_78;
            lVar11 = 0;
LAB_001005f8:
            uVar13 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar11);
            if ((uint)uVar13 < _nr_cpu_ids) {
              lVar11 = get_cpu_device(uVar13 & 0xffffffff);
              if ((lVar11 == 0) || (*(long *)(lVar11 + 0x2e8) != lVar6)) goto LAB_001005f4;
              puVar1 = local_70 + (uVar13 >> 6 & 0x3ffffff);
              Hint_Prefetch(puVar1,2,0,1);
              do {
                cVar2 = '\x01';
                bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                if (bVar3) {
                  *puVar1 = *puVar1 | 1L << (uVar13 & 0x3f);
                  cVar2 = ExclusiveMonitorsStatus();
                }
              } while (cVar2 != '\0');
              uVar9 = 1L << (uVar13 & 0x3f) | uVar9;
            }
            uVar14 = (uint)uVar9;
            iVar7 = of_phandle_iterator_next(&local_b0);
            if (iVar7 != 0) break;
          } while( true );
        }
        uVar13 = (ulong)_nr_cpu_ids;
        uVar9 = _find_first_bit(local_70,uVar13);
        if (uVar9 != uVar13) {
          puVar10 = (undefined8 *)devm_kmalloc(param_1 + 0x10,0xa8,0xdc0);
          if (puVar10 == (undefined8 *)0x0) {
            uVar12 = 0xfffffff4;
            goto LAB_00100684;
          }
          iVar7 = of_property_read_string(lVar8,"qcom,cdev-alias",&local_b8);
          pcVar5 = local_b8;
          if (iVar7 == 0) {
            uVar9 = strnlen(local_b8,0x14);
            if (uVar9 == 0xffffffffffffffff) goto LAB_001006f4;
            if (uVar9 != 0x14) {
              uVar9 = uVar9 + 1;
            }
            if (0x14 < uVar9) goto LAB_00100700;
            strscpy(puVar10 + 6,pcVar5);
          }
          else {
            snprintf((char *)(puVar10 + 6),0x14,"thermal-pause-%X",uVar14);
          }
          uVar14 = _nr_cpu_ids;
          *(undefined4 *)(puVar10 + 3) = 0;
          puVar10[4] = 0;
          puVar10[5] = lVar8;
          uVar14 = uVar14 + 0x3f >> 3 & 0x1ffffff8;
          if (8 < uVar14) goto LAB_001006e8;
          memcpy(puVar10 + 2,local_70,(ulong)uVar14);
          puVar10[9] = 0xfffffffe0;
          puVar10[10] = puVar10 + 10;
          puVar10[0xb] = puVar10 + 10;
          puVar10[0xf] = 0xfffffffe0;
          puVar10[0xc] = thermal_pause_register_cdev;
          puVar10[0x10] = puVar10 + 0x10;
          puVar10[0x11] = puVar10 + 0x10;
          puVar4 = thermal_pause_cdev_list;
          puVar10[0x12] = thermal_pause_update_work;
          uVar9 = __list_add_valid(puVar10,&thermal_pause_cdev_list,puVar4);
          if ((uVar9 & 1) != 0) {
            *(undefined8 **)(puVar4 + 8) = puVar10;
            *puVar10 = puVar4;
            puVar10[1] = &thermal_pause_cdev_list;
            thermal_pause_cdev_list = (undefined *)puVar10;
          }
        }
        lVar8 = of_get_next_available_child(uVar12,lVar8);
      } while (lVar8 != 0);
    }
    uVar12 = __cpuhp_setup_state(200,"thermal-pause/cdev:online",1,thermal_pause_hp_online,0,0);
    iVar7 = (int)uVar12;
    if (-1 < iVar7) {
      uVar12 = 0;
      cpu_hp_online = iVar7;
    }
LAB_00100684:
    lVar8 = sp_el0;
    if (*(long *)(lVar8 + 0x638) == local_70[1]) {
      return;
    }
  }
  else {
LAB_001006dc:
    fortify_panic("memset");
LAB_001006e8:
    fortify_panic("memcpy");
LAB_001006f4:
    fortify_panic("strnlen");
LAB_00100700:
    uVar12 = fortify_panic("strscpy");
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail(uVar12);
LAB_001005f4:
  lVar11 = uVar13 + 1;
  goto LAB_001005f8;
}



//------------------------------------------------------------
// thermal_pause_remove @ 00100714 size=252
// signature: undefined thermal_pause_remove(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 thermal_pause_remove(void)

{
  undefined *puVar1;
  long *plVar2;
  undefined8 uVar3;
  ulong uVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  
  tracepoint_probe_unregister
            (&__tracepoint_android_vh_disable_thermal_cooling_stats,disable_cdev_stats,0);
  if (cpu_hp_online != 0) {
    __cpuhp_remove_state(cpu_hp_online,0);
    cpu_hp_online = 0;
  }
  mutex_lock(cpus_pause_lock);
  ppuVar5 = (undefined **)thermal_pause_cdev_list;
  if ((undefined **)thermal_pause_cdev_list != &thermal_pause_cdev_list) {
    do {
      uVar3 = _system_highpri_wq;
      ppuVar6 = (undefined **)*ppuVar5;
      if (*(int *)(ppuVar5 + 3) != 0) {
        *(undefined4 *)((long)ppuVar5 + 0x1c) = 0;
        queue_work_on(0x20,uVar3,ppuVar5 + 0xf);
      }
      if (ppuVar5[4] != (undefined *)0x0) {
        thermal_cooling_device_unregister();
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
    } while (ppuVar6 != &thermal_pause_cdev_list);
  }
  mutex_unlock(cpus_pause_lock);
  return 0;
}



//------------------------------------------------------------
// thermal_pause_register_cdev @ 00100814 size=228
// signature: undefined thermal_pause_register_cdev(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thermal_pause_register_cdev(long param_1)

{
  long lVar1;
  ulong uVar2;
  undefined8 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  __bitmap_and(&local_40,param_1 + -0x38,&__cpu_online_mask,_nr_cpu_ids);
  uVar2 = __bitmap_equal(param_1 + -0x38,&local_40,_nr_cpu_ids);
  if ((uVar2 & 1) != 0) {
    uVar2 = thermal_of_cooling_device_register
                      (*(undefined8 *)(param_1 + -0x20),param_1 + -0x18,param_1 + -0x48,
                       &thermal_pause_cooling_ops);
    *(ulong *)(param_1 + -0x28) = uVar2;
    if (0xfffffffffffff000 < uVar2) {
      _printk(&DAT_00101256,"thermal_pause","thermal_pause_register_cdev",param_1 + -0x18,uVar2);
      *(undefined8 *)(param_1 + -0x28) = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// thermal_pause_update_work @ 001008fc size=892
// signature: undefined thermal_pause_update_work(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void thermal_pause_update_work(long param_1)

{
  bool bVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  void *__src;
  undefined **ppuVar8;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  mutex_lock(cpus_pause_lock);
  iVar4 = 0;
  __src = (void *)(param_1 + -0x68);
  iVar7 = 5;
LAB_0010097c:
  do {
    iVar6 = *(int *)(param_1 + -0x5c);
    if (iVar6 == *(int *)(param_1 + -0x60)) {
      if (iVar4 < 0) goto LAB_00100c18;
    }
    else if (iVar6 == 0) {
      local_78 = 0;
      uStack_70 = 0;
      local_80 = 0;
      uVar5 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
      if (8 < uVar5) goto LAB_00100c5c;
      memcpy(&uStack_70,__src,(ulong)uVar5);
      mutex_unlock(cpus_pause_lock);
      iVar4 = walt_resume_cpus(&uStack_70,2);
      mutex_lock(cpus_pause_lock);
      uVar5 = _nr_cpu_ids;
      if (iVar4 == 0) {
        uVar2 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
        if (8 < uVar2) goto LAB_00100c68;
        memset(&local_78,0,(ulong)uVar2);
        ppuVar8 = (undefined **)thermal_pause_cdev_list;
        if ((undefined **)thermal_pause_cdev_list != &thermal_pause_cdev_list) {
          do {
            if ((*(int *)(ppuVar8 + 3) != 0) && (ppuVar8 != (undefined **)(param_1 + -0x78))) {
              __bitmap_or(&local_78,&local_78,ppuVar8 + 2,_nr_cpu_ids);
            }
            ppuVar8 = (undefined **)*ppuVar8;
          } while (ppuVar8 != &thermal_pause_cdev_list);
          uVar5 = _nr_cpu_ids;
        }
        __bitmap_andnot(&local_80,&cpus_in_max_cooling_level,&local_78,uVar5);
        iVar7 = 0;
        while (uVar5 = _find_next_bit(&local_80,_nr_cpu_ids,(long)iVar7), uVar5 < _nr_cpu_ids) {
          blocking_notifier_call_chain(&thermal_pause_notifier,0,(long)(int)uVar5);
          iVar7 = uVar5 + 1;
        }
        uVar5 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
        if (8 < uVar5) goto LAB_00100c5c;
        memcpy(&cpus_in_max_cooling_level,&local_78,(ulong)uVar5);
      }
      else {
        _printk(&DAT_00101125,"thermal_pause","thermal_resume_work",_nr_cpu_ids,__src,iVar4);
        if (iVar4 < 0) goto LAB_00100c10;
      }
      iVar6 = 0;
      *(undefined4 *)(param_1 + -0x60) = 0;
    }
    else {
      local_78 = 0;
      uStack_70 = 0;
      uVar5 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
      if (8 < uVar5) {
LAB_00100c5c:
        fortify_panic("memcpy");
LAB_00100c68:
        fortify_panic("memset");
        goto LAB_00100c74;
      }
      memcpy(&uStack_70,__src,(ulong)uVar5);
      mutex_unlock(cpus_pause_lock);
      iVar4 = walt_pause_cpus(&uStack_70,2);
      mutex_lock(cpus_pause_lock);
      if (iVar4 == 0) {
        __bitmap_andnot(&local_78,__src,&cpus_in_max_cooling_level);
        iVar7 = 0;
        while (uVar5 = _find_next_bit(&local_78,_nr_cpu_ids,(long)iVar7), uVar5 < _nr_cpu_ids) {
          blocking_notifier_call_chain(&thermal_pause_notifier,1,(long)(int)uVar5);
          iVar7 = uVar5 + 1;
        }
        __bitmap_or(&cpus_in_max_cooling_level,&cpus_in_max_cooling_level,__src);
      }
      else {
        _printk(&DAT_0010122d,"thermal_pause","thermal_pause_work",_nr_cpu_ids,__src,iVar4);
        if (iVar4 < 0) {
LAB_00100c10:
          bVar1 = iVar7 < 1;
          iVar7 = iVar7 + -1;
          if (bVar1) goto LAB_00100c18;
          goto LAB_0010097c;
        }
      }
      iVar6 = 1;
      *(undefined4 *)(param_1 + -0x60) = 1;
    }
    iVar7 = 5;
    if (*(int *)(param_1 + -0x5c) == iVar6) {
LAB_00100c18:
      mutex_unlock(cpus_pause_lock);
      lVar3 = sp_el0;
      if (*(long *)(lVar3 + 0x638) == local_68) {
        return;
      }
LAB_00100c74:
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
  } while( true );
}



//------------------------------------------------------------
// thermal_pause_hp_online @ 00100c7c size=180
// signature: undefined thermal_pause_hp_online(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 thermal_pause_hp_online(uint param_1)

{
  undefined **ppuVar1;
  
  mutex_lock(cpus_pause_lock);
  if ((undefined **)thermal_pause_cdev_list != &thermal_pause_cdev_list) {
    ppuVar1 = (undefined **)thermal_pause_cdev_list;
    do {
      if ((((ulong)ppuVar1[(ulong)(param_1 >> 6) + 2] & 1L << ((ulong)param_1 & 0x3f)) != 0) &&
         (ppuVar1[4] == (undefined *)0x0)) {
        queue_work_on(0x20,_system_highpri_wq,ppuVar1 + 9);
      }
      ppuVar1 = (undefined **)*ppuVar1;
    } while (ppuVar1 != &thermal_pause_cdev_list);
  }
  mutex_unlock(cpus_pause_lock);
  return 0;
}



//------------------------------------------------------------
// disable_cdev_stats @ 00100d34 size=12
// signature: undefined disable_cdev_stats(void)
// callers: []
//------------------------------------------------------------

void disable_cdev_stats(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  *param_3 = 1;
  return;
}



//------------------------------------------------------------
// thermal_pause_get_max_state @ 00100d44 size=16
// signature: undefined thermal_pause_get_max_state(void)
// callers: []
//------------------------------------------------------------

undefined8 thermal_pause_get_max_state(undefined8 param_1,undefined8 *param_2)

{
  *param_2 = 1;
  return 0;
}



//------------------------------------------------------------
// thermal_pause_get_cur_state @ 00100d58 size=20
// signature: undefined thermal_pause_get_cur_state(void)
// callers: []
//------------------------------------------------------------

undefined8 thermal_pause_get_cur_state(long param_1,ulong *param_2)

{
  *param_2 = (ulong)*(uint *)(*(long *)(param_1 + 0x3b0) + 0x18);
  return 0;
}



//------------------------------------------------------------
// thermal_pause_set_cur_state @ 00100d70 size=124
// signature: undefined thermal_pause_set_cur_state(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 thermal_pause_set_cur_state(long param_1,ulong param_2)

{
  undefined8 uVar1;
  long lVar2;
  
  if (param_2 < 2) {
    lVar2 = *(long *)(param_1 + 0x3b0);
    mutex_lock(cpus_pause_lock);
    uVar1 = _system_highpri_wq;
    *(uint *)(lVar2 + 0x1c) = (uint)(param_2 != 0);
    queue_work_on(0x20,uVar1,lVar2 + 0x78);
    mutex_unlock(cpus_pause_lock);
    return 0;
  }
  return 0xffffffea;
}



//------------------------------------------------------------
// init_module @ 00100e4c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&thermal_pause_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100e7c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&thermal_pause_driver);
  return;
}



//------------------------------------------------------------
// blocking_notifier_chain_register @ 00103000 size=1
// signature: undefined blocking_notifier_chain_register(void)
// callers: [thermal_pause_notifier_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_chain_unregister @ 00103008 size=1
// signature: undefined blocking_notifier_chain_unregister(void)
// callers: [thermal_pause_notifier_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00103010 size=1
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
// platform_driver_unregister @ 00103018 size=1
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
// tracepoint_probe_register @ 00103028 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00103038 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [thermal_pause_probe, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_available_child @ 00103040 size=1
// signature: undefined of_get_next_available_child(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_available_child(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_init @ 00103050 size=1
// signature: undefined of_phandle_iterator_init(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_phandle_iterator_next @ 00103058 size=1
// signature: undefined of_phandle_iterator_next(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_phandle_iterator_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00103060 size=1
// signature: undefined _find_first_bit(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00103068 size=1
// signature: undefined devm_kmalloc(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 00103070 size=1
// signature: undefined of_property_read_string(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00103078 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00103080 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103088 size=1
// signature: undefined strscpy(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103090 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [thermal_pause_probe, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00103098 size=1
// signature: undefined __list_add_valid(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001030a0 size=1
// signature: undefined _find_next_bit(void)
// callers: [thermal_pause_probe, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_cpu_device @ 001030a8 size=1
// signature: undefined get_cpu_device(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_cpu_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 001030b8 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [thermal_pause_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001030c0 size=1
// signature: undefined _printk(void)
// callers: [thermal_pause_probe, thermal_pause_register_cdev, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030c8 size=1
// signature: undefined fortify_panic(void)
// callers: [thermal_pause_probe, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030d0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [thermal_pause_probe, thermal_pause_register_cdev, thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 001030d8 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [thermal_pause_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 001030e0 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [thermal_pause_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 001030e8 size=1
// signature: undefined mutex_lock(void)
// callers: [thermal_pause_remove, thermal_pause_update_work, thermal_pause_hp_online, thermal_pause_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 001030f8 size=1
// signature: undefined queue_work_on(void)
// callers: [thermal_pause_remove, thermal_pause_hp_online, thermal_pause_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_cooling_device_unregister @ 00103100 size=1
// signature: undefined thermal_cooling_device_unregister(void)
// callers: [thermal_pause_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_cooling_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00103108 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [thermal_pause_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00103110 size=1
// signature: undefined mutex_unlock(void)
// callers: [thermal_pause_remove, thermal_pause_update_work, thermal_pause_hp_online, thermal_pause_set_cur_state]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_and @ 00103120 size=1
// signature: undefined __bitmap_and(void)
// callers: [thermal_pause_register_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_and(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_equal @ 00103128 size=1
// signature: undefined __bitmap_equal(void)
// callers: [thermal_pause_register_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_equal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// thermal_of_cooling_device_register @ 00103130 size=1
// signature: undefined thermal_of_cooling_device_register(void)
// callers: [thermal_pause_register_cdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void thermal_of_cooling_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_pause_cpus @ 00103138 size=1
// signature: undefined walt_pause_cpus(void)
// callers: [thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_pause_cpus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_andnot @ 00103140 size=1
// signature: undefined __bitmap_andnot(void)
// callers: [thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_andnot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// blocking_notifier_call_chain @ 00103148 size=1
// signature: undefined blocking_notifier_call_chain(void)
// callers: [thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void blocking_notifier_call_chain(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_or @ 00103150 size=1
// signature: undefined __bitmap_or(void)
// callers: [thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_or(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// walt_resume_cpus @ 00103158 size=1
// signature: undefined walt_resume_cpus(void)
// callers: [thermal_pause_update_work]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void walt_resume_cpus(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



