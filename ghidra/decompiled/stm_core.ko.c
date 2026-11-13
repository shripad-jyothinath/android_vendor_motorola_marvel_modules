// Decompiled by Ghidra 12.2
// Program: stm_core.ko
// Image base: 00100000

//------------------------------------------------------------
// stm_find_device @ 00100efc size=108
// signature: undefined stm_find_device(void)
// callers: [stp_policy_make]
//------------------------------------------------------------

long stm_find_device(undefined8 param_1)

{
  long lVar1;
  ulong uVar2;
  
  if (stm_core_up != 0) {
    lVar1 = class_find_device(&stm_class,0,param_1,&device_match_name);
    if (lVar1 == 0) {
      return 0;
    }
    uVar2 = try_module_get(*(undefined8 *)(lVar1 + 0x390));
    if ((uVar2 & 1) != 0) {
      return lVar1;
    }
    put_device(lVar1);
  }
  return 0;
}



//------------------------------------------------------------
// stm_put_device @ 00100f6c size=52
// signature: undefined stm_put_device(void)
// callers: [stp_policy_make, stp_policy_unbind, stp_policy_release]
//------------------------------------------------------------

void stm_put_device(long param_1)

{
  module_put(*(undefined8 *)(param_1 + 0x390));
  put_device(param_1);
  return;
}



//------------------------------------------------------------
// stm_register_protocol @ 00100fa4 size=276
// signature: undefined stm_register_protocol(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 stm_register_protocol(long param_1)

{
  undefined8 *puVar1;
  int iVar2;
  long lVar3;
  ulong uVar4;
  undefined8 uVar5;
  char *__s1;
  undefined8 *puVar6;
  
  mutex_lock(stm_pdrv_mutex);
  __s1 = *(char **)(param_1 + 8);
  if ((__s1 == (char *)0x0) || (*__s1 == '\0')) {
    __s1 = "p_basic";
  }
  puVar6 = &stm_pdrv_head;
  do {
    puVar6 = (undefined8 *)*puVar6;
    if (puVar6 == &stm_pdrv_head) goto LAB_0010101c;
    iVar2 = strcmp(__s1,*(char **)(puVar6[2] + 8));
  } while (iVar2 != 0);
  if (puVar6 == (undefined8 *)0x0) {
LAB_0010101c:
    puVar6 = (undefined8 *)kmalloc_trace(_vzalloc,0xdc0,0x20);
    if (puVar6 != (undefined8 *)0x0) {
      if (*(long *)(param_1 + 0x38) == 0) {
LAB_0010104c:
        puVar1 = DAT_00103cd0;
        uVar4 = __list_add_valid(puVar6,DAT_00103cd0,&stm_pdrv_head);
        if ((uVar4 & 1) != 0) {
          DAT_00103cd0 = puVar6;
          *puVar6 = &stm_pdrv_head;
          puVar6[1] = puVar1;
          *puVar1 = puVar6;
        }
        puVar6[2] = param_1;
        mutex_unlock(stm_pdrv_mutex);
        return 0;
      }
      lVar3 = get_policy_node_type();
      puVar6[3] = lVar3;
      if (lVar3 != 0) goto LAB_0010104c;
    }
    uVar5 = 0xfffffff4;
  }
  else {
    puVar6 = (undefined8 *)0x0;
    uVar5 = 0xffffffef;
  }
  mutex_unlock(stm_pdrv_mutex);
  kfree(puVar6);
  return uVar5;
}



//------------------------------------------------------------
// stm_unregister_protocol @ 001010bc size=172
// signature: undefined stm_unregister_protocol(void)
// callers: []
//------------------------------------------------------------

void stm_unregister_protocol(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  mutex_lock(stm_pdrv_mutex);
  plVar4 = &stm_pdrv_head;
  do {
    plVar4 = (long *)*plVar4;
    if (plVar4 == &stm_pdrv_head) goto LAB_0010114c;
  } while (plVar4[2] != param_1);
  uVar3 = __list_del_entry_valid(plVar4);
  if ((uVar3 & 1) != 0) {
    lVar1 = *plVar4;
    plVar2 = (long *)plVar4[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *plVar4 = -0x2152ffffffffff00;
  plVar4[1] = -0x2152fffffffffede;
  if (plVar4[3] != 0) {
    kfree(*(undefined8 *)(plVar4[3] + 0x18));
    kfree(plVar4[3]);
  }
  kfree(plVar4);
LAB_0010114c:
  mutex_unlock(stm_pdrv_mutex);
  return;
}



//------------------------------------------------------------
// stm_put_protocol @ 0010116c size=32
// signature: undefined stm_put_protocol(void)
// callers: [stp_policy_make, stp_policy_unbind, stp_policy_release]
//------------------------------------------------------------

void stm_put_protocol(undefined8 *param_1)

{
  module_put(*param_1);
  return;
}



//------------------------------------------------------------
// stm_lookup_protocol @ 00101190 size=208
// signature: undefined stm_lookup_protocol(void)
// callers: [stp_policy_make]
//------------------------------------------------------------

undefined8 stm_lookup_protocol(char *param_1,undefined8 *param_2,undefined8 *param_3)

{
  int iVar1;
  ulong uVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  undefined8 *puVar5;
  
  mutex_lock(stm_pdrv_mutex);
  if ((param_1 == (char *)0x0) || (*param_1 == '\0')) {
    param_1 = "p_basic";
  }
  puVar4 = &stm_pdrv_head;
  do {
    puVar4 = (undefined8 *)*puVar4;
    if (puVar4 == &stm_pdrv_head) goto LAB_0010122c;
    puVar5 = (undefined8 *)puVar4[2];
    iVar1 = strcmp(param_1,(char *)puVar5[1]);
  } while (iVar1 != 0);
  if (puVar4 == (undefined8 *)0x0) {
LAB_0010122c:
    uVar3 = 0xfffffffe;
  }
  else if ((puVar5 == (undefined8 *)0x0) || (uVar2 = try_module_get(*puVar5), (uVar2 & 1) == 0)) {
    uVar3 = 0;
  }
  else {
    *param_2 = puVar4[2];
    uVar3 = 0;
    *param_3 = puVar4[3];
  }
  mutex_unlock(stm_pdrv_mutex);
  return uVar3;
}



//------------------------------------------------------------
// stm_data_write @ 00101264 size=248
// signature: undefined stm_data_write(void)
// callers: []
//------------------------------------------------------------

ulong stm_data_write(long param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4,
                    long param_5,ulong param_6)

{
  ulong uVar1;
  ulong uVar2;
  uint uVar3;
  
  if (param_6 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(param_1 + 0x28))();
    uVar2 = uVar1;
    if ((long)uVar1 < 1) {
      uVar2 = 0;
LAB_00101334:
      if (-1 < (long)uVar1) {
        uVar1 = uVar2;
      }
    }
    else {
      for (; uVar1 = uVar2, uVar2 < param_6; uVar2 = uVar1 + uVar2) {
        uVar3 = (int)param_6 - (int)uVar2;
        if (7 < uVar3) {
          uVar3 = 8;
        }
        uVar1 = (**(code **)(param_1 + 0x28))(param_1,param_2,param_3,0,0,uVar3,param_5 + uVar2);
        if ((long)uVar1 < 1) goto LAB_00101334;
      }
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// stm_register_device @ 00101360 size=460
// signature: undefined stm_register_device(void)
// callers: []
//------------------------------------------------------------

int stm_register_device(undefined8 param_1,undefined8 *param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  
  if (stm_core_up == 0) {
    iVar2 = -0x205;
  }
  else if ((param_2[5] == 0) || (*(int *)(param_2 + 3) == 0)) {
    iVar2 = -0x16;
  }
  else {
    uVar1 = (*(int *)((long)param_2 + 0x14) - *(int *)(param_2 + 2)) + 1;
    lVar3 = vzalloc((ulong)uVar1 * 8 + 0x440);
    if (lVar3 == 0) {
      iVar2 = -0xc;
    }
    else {
      iVar2 = __register_chrdev(0,0,0x100,*param_2,&stm_fops);
      *(int *)(lVar3 + 0x3d0) = iVar2;
      if (iVar2 < 0) {
        vfree(lVar3);
      }
      else {
        device_initialize(lVar3);
        *(undefined ***)(lVar3 + 0x318) = &stm_class;
        *(undefined8 *)(lVar3 + 0x60) = param_1;
        *(int *)(lVar3 + 0x2f8) = *(int *)(lVar3 + 0x3d0) << 0x14;
        *(code **)(lVar3 + 0x328) = stm_device_release;
        __mutex_init(lVar3 + 0x3e0,"&stm->link_mutex",&stm_register_device___key);
        *(undefined4 *)(lVar3 + 0x410) = 0;
        *(long *)(lVar3 + 0x418) = lVar3 + 0x418;
        *(long *)(lVar3 + 0x420) = lVar3 + 0x418;
        *(undefined4 *)(lVar3 + 0x438) = 0;
        __mutex_init(lVar3 + 0x3a0,"&stm->policy_mutex",&stm_register_device___key_1);
        uVar4 = *param_2;
        *(uint *)(lVar3 + 0x3d4) = uVar1;
        *(undefined8 *)(lVar3 + 0x390) = param_3;
        *(undefined8 **)(lVar3 + 0x3d8) = param_2;
        param_2[1] = lVar3;
        iVar2 = kobject_set_name(lVar3,&DAT_001045b7,uVar4);
        if (iVar2 == 0) {
          iVar2 = device_add(lVar3);
          if (iVar2 == 0) {
            pm_runtime_no_callbacks(lVar3);
            __pm_runtime_use_autosuspend(lVar3,1);
            pm_runtime_set_autosuspend_delay(lVar3,2000);
            __pm_runtime_set_status(lVar3,2);
            pm_runtime_enable(lVar3);
            return 0;
          }
        }
        __unregister_chrdev(*(undefined4 *)(lVar3 + 0x3d0),0,0x100,*param_2);
        put_device(lVar3);
      }
    }
  }
  return iVar2;
}



//------------------------------------------------------------
// stm_device_release @ 00101530 size=28
// signature: undefined stm_device_release(void)
// callers: []
//------------------------------------------------------------

void stm_device_release(void)

{
  vfree();
  return;
}



//------------------------------------------------------------
// stm_unregister_device @ 00101550 size=304
// signature: undefined stm_unregister_device(void)
// callers: []
//------------------------------------------------------------

void stm_unregister_device(undefined8 *param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  
  lVar7 = param_1[1];
  __pm_runtime_use_autosuspend(lVar7,0);
  __pm_runtime_disable(lVar7,1);
  mutex_lock(lVar7 + 0x3e0);
  plVar4 = *(long **)(lVar7 + 0x418);
  do {
    if (plVar4 == (long *)(lVar7 + 0x418)) {
      mutex_unlock(lVar7 + 0x3e0);
      synchronize_srcu(stm_source_srcu);
      __unregister_chrdev(*(undefined4 *)(lVar7 + 0x3d0),0,0x100,*param_1);
      mutex_lock(lVar7 + 0x3a0);
      if (*(long *)(lVar7 + 0x398) != 0) {
        stp_policy_unbind();
      }
      mutex_unlock(lVar7 + 0x3a0);
      lVar5 = *(long *)(lVar7 + 0x3d8);
      uVar6 = *(uint *)(lVar5 + 0x14);
      for (uVar8 = *(uint *)(lVar5 + 0x10); uVar8 <= uVar6; uVar8 = uVar8 + 1) {
        if ((*(uint *)(lVar5 + 0x10) <= uVar8) &&
           (lVar1 = lVar7 + (ulong)(uVar8 - *(uint *)(lVar5 + 0x10)) * 8,
           *(long *)(lVar1 + 0x440) != 0)) {
          *(undefined8 *)(lVar1 + 0x440) = 0;
          kfree();
          lVar5 = *(long *)(lVar7 + 0x3d8);
        }
        uVar6 = *(uint *)(lVar5 + 0x14);
      }
      device_unregister(lVar7);
      param_1[1] = 0;
      return;
    }
    lVar5 = (long)(plVar4 + -0x7b);
    plVar4 = (long *)*plVar4;
    iVar3 = __stm_source_link_drop(lVar5,lVar7);
  } while (iVar3 == 0);
                    /* WARNING: Does not return */
  pcVar2 = (code *)SoftwareBreakpoint(0x800,0x1015cc);
  (*pcVar2)();
}



//------------------------------------------------------------
// __stm_source_link_drop @ 00101684 size=312
// signature: undefined __stm_source_link_drop(void)
// callers: [stm_unregister_device, stm_source_link_store, stm_source_unregister_device]
//------------------------------------------------------------

undefined8 __stm_source_link_drop(long param_1,long param_2)

{
  long lVar1;
  ulong uVar2;
  long *plVar3;
  code *pcVar4;
  long lVar5;
  undefined8 uVar6;
  long lVar7;
  
  _raw_spin_lock(param_2 + 0x410);
  _raw_spin_lock(param_1 + 0x3c8);
  lVar7 = *(long *)(param_1 + 0x3d0);
  if (lVar7 == param_2) {
    stm_output_free(param_2,param_1 + 1000);
    lVar1 = param_1 + 0x3d8;
    uVar2 = __list_del_entry_valid(lVar1);
    if ((uVar2 & 1) != 0) {
      plVar3 = *(long **)(param_1 + 0x3e0);
      lVar5 = *(long *)(param_1 + 0x3d8);
      *(long **)(lVar5 + 8) = plVar3;
      *plVar3 = lVar5;
    }
    *(long *)(param_1 + 0x3d8) = lVar1;
    *(long *)(param_1 + 0x3e0) = lVar1;
    uVar6 = ktime_get_mono_fast_ns();
    *(undefined8 *)(param_2 + 0x220) = uVar6;
    __pm_runtime_suspend(param_2,0xd);
    module_put(*(undefined8 *)(param_2 + 0x390));
    put_device(param_2);
    uVar6 = 0;
    *(undefined8 *)(param_1 + 0x3d0) = 0;
  }
  else {
    uVar6 = 0xfffffff5;
  }
  _raw_spin_unlock(param_1 + 0x3c8);
  _raw_spin_unlock(param_2 + 0x410);
  if (lVar7 == param_2) {
    pcVar4 = *(code **)(*(long *)(param_1 + 0x390) + 0x20);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != -0x2ab783e6) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10176c);
        (*pcVar4)();
      }
      (*pcVar4)();
    }
    pcVar4 = *(code **)(*(long *)(param_2 + 0x3d8) + 0x40);
    if (pcVar4 != (code *)0x0) {
      if (*(int *)(pcVar4 + -4) != 0x3f39d35) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x10179c);
        (*pcVar4)();
      }
      (*pcVar4)(*(long *)(param_2 + 0x3d8),*(undefined4 *)(param_1 + 0x3ec),
                *(undefined4 *)(param_1 + 0x3f0));
    }
  }
  return uVar6;
}



//------------------------------------------------------------
// stm_source_register_device @ 001017c0 size=264
// signature: undefined stm_source_register_device(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stm_source_register_device(undefined8 param_1,undefined8 *param_2)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  if (stm_core_up == 0) {
    iVar1 = -0x205;
  }
  else {
    lVar2 = kmalloc_trace(_kobject_set_name,0xdc0,0x400);
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else {
      device_initialize();
      uVar3 = *param_2;
      *(undefined ***)(lVar2 + 0x318) = &stm_source_class;
      *(undefined8 *)(lVar2 + 0x60) = param_1;
      *(code **)(lVar2 + 0x328) = stm_source_device_release;
      iVar1 = kobject_set_name(lVar2,&DAT_001045b7,uVar3);
      if (iVar1 == 0) {
        pm_runtime_no_callbacks(lVar2);
        pm_runtime_forbid(lVar2);
        iVar1 = device_add(lVar2);
        if (iVar1 == 0) {
          *(undefined4 *)(lVar2 + 1000) = 0;
          *(undefined4 *)(lVar2 + 0x3c8) = 0;
          __mutex_init(lVar2 + 0x398,"&src->link_mutex",&stm_source_register_device___key);
          *(long *)(lVar2 + 0x3d8) = lVar2 + 0x3d8;
          *(long *)(lVar2 + 0x3e0) = lVar2 + 0x3d8;
          *(undefined8 **)(lVar2 + 0x390) = param_2;
          param_2[1] = lVar2;
          return 0;
        }
      }
      put_device(lVar2);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// stm_source_device_release @ 001018cc size=28
// signature: undefined stm_source_device_release(void)
// callers: []
//------------------------------------------------------------

void stm_source_device_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// stm_source_unregister_device @ 001018ec size=164
// signature: undefined stm_source_unregister_device(void)
// callers: []
//------------------------------------------------------------

void stm_source_unregister_device(long param_1)

{
  undefined4 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + 8);
  do {
    uVar1 = __srcu_read_lock(stm_source_srcu);
    lVar4 = *(long *)(lVar3 + 0x3d0);
    if (lVar4 == 0) {
      __srcu_read_unlock(stm_source_srcu,uVar1);
      break;
    }
    mutex_lock(lVar4 + 0x3e0);
    iVar2 = __stm_source_link_drop(lVar3,lVar4);
    mutex_unlock(lVar4 + 0x3e0);
    __srcu_read_unlock(stm_source_srcu,uVar1);
  } while (iVar2 == -0xb);
  device_unregister(lVar3);
  return;
}



// FAILED TO DECOMPILE: stm_source_write @ 00101994

//------------------------------------------------------------
// masters_show @ 00101a68 size=56
// signature: undefined masters_show(void)
// callers: []
//------------------------------------------------------------

long masters_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%u %u\n",*(uint *)(*(long *)(param_1 + 0x3d8) + 0x10),
                  *(uint *)(*(long *)(param_1 + 0x3d8) + 0x14));
  return (long)iVar1;
}



//------------------------------------------------------------
// channels_show @ 00101aa4 size=56
// signature: undefined channels_show(void)
// callers: []
//------------------------------------------------------------

long channels_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%u\n",(ulong)*(uint *)(*(long *)(param_1 + 0x3d8) + 0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// hw_override_show @ 00101ae0 size=56
// signature: undefined hw_override_show(void)
// callers: []
//------------------------------------------------------------

long hw_override_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%u\n",(ulong)*(uint *)(*(long *)(param_1 + 0x3d8) + 0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// stm_char_write @ 00101b1c size=640
// signature: undefined stm_char_write(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong stm_char_write(long param_1,ulong param_2,ulong param_3)

{
  ulong uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 uVar7;
  undefined8 *puVar8;
  ulong uVar9;
  long lVar10;
  long *plVar11;
  ulong uVar12;
  undefined8 *local_70;
  char *pcStack_68;
  undefined8 local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  long local_48;
  
  lVar10 = sp_el0;
  local_48 = *(long *)(lVar10 + 0x638);
  plVar11 = *(long **)(param_1 + 0xd8);
  uVar12 = 0xfff;
  if (0xffffffffffffeffe < param_3 - 0x1000) {
    uVar12 = param_3;
  }
  lVar10 = *plVar11;
  if (*(int *)((long)plVar11 + 0x14) == 0) {
    local_70 = &local_58;
    local_58 = 0;
    uStack_50 = 0;
    uVar7 = sp_el0;
    local_60 = 0;
    pcStack_68 = "default";
    __get_task_comm(&local_58,0x10,uVar7);
    iVar4 = stm_assign_first_policy(*plVar11,plVar11 + 1,&local_70,1);
    if (iVar4 != 0) {
      uVar12 = (ulong)iVar4;
      goto LAB_00101d1c;
    }
  }
  lVar5 = __kmalloc(uVar12 + 1,0xcc0);
  if (lVar5 == 0) {
    uVar12 = 0xfffffffffffffff4;
  }
  else {
    if (uVar12 >> 0x1f != 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x101d58);
      (*pcVar2)();
    }
    __check_object_size(lVar5,uVar12,0);
    puVar8 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar8 + 0x46) >> 5 & 1) != 0) ||
       (uVar9 = param_2, ((uint)*puVar8 >> 0x1a & 1) != 0)) {
      uVar9 = param_2 & (long)(param_2 << 8) >> 8;
    }
    uVar6 = uVar12;
    if (uVar9 <= 0x8000000000 - uVar12) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar6 = daif;
          daif = uVar6 | 0xc0;
        }
        puVar8 = (undefined8 *)puVar8[1];
        uVar6 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar8 & 0xffff000000000000 | uVar6 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar8;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
      uVar6 = __arch_copy_from_user(puVar8,lVar5,param_2 & 0xff7fffffffffffff,uVar12);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar9 = daif;
        if ((uVar9 & 0x80) == 0) {
          uVar1 = daif;
          daif = uVar1 | 0xc0;
        }
        uVar1 = ttbr1_el1;
        ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar1 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar9;
      }
    }
    if ((uVar6 == 0) || (memset((void *)(lVar5 + (uVar12 - uVar6)),0,uVar6), (int)uVar6 == 0)) {
      __pm_runtime_resume(lVar10,4);
      if (*(long *)(lVar10 + 0x428) == 0) {
        uVar12 = 0xffffffffffffffed;
      }
      else {
        uVar3 = (**(code **)(*(long *)(lVar10 + 0x428) + 0x10))
                          (*(undefined8 *)(lVar10 + 0x3d8),plVar11 + 1,0,lVar5,uVar12);
        if ((int)uVar3 < 0) {
          uVar12 = (ulong)(int)uVar3;
        }
        else {
          uVar12 = (ulong)uVar3;
        }
      }
      uVar7 = ktime_get_mono_fast_ns();
      *(undefined8 *)(lVar10 + 0x220) = uVar7;
      __pm_runtime_suspend(lVar10,0xd);
    }
    else {
      uVar12 = 0xfffffffffffffff2;
    }
    kfree(lVar5);
  }
LAB_00101d1c:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar12;
}



//------------------------------------------------------------
// stm_char_ioctl @ 00101dbc size=1384
// signature: undefined stm_char_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stm_char_ioctl(long param_1,int param_2,ulong param_3)

{
  uint uVar1;
  ulong uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  undefined8 *puVar7;
  ulong uVar8;
  ulong uVar9;
  code *pcVar10;
  uint uVar11;
  long *plVar12;
  long lVar13;
  ulong uVar14;
  undefined8 local_88;
  uint local_7c;
  long local_78 [3];
  
  lVar13 = sp_el0;
  local_78[2] = *(long *)(lVar13 + 0x638);
  plVar12 = *(long **)(param_1 + 0xd8);
  local_88 = 0;
  lVar13 = *(long *)(*plVar12 + 0x3d8);
  if (param_2 == -0x7fefdaff) {
LAB_00102258:
    iVar4 = stm_char_policy_get_ioctl(plVar12,param_3);
LAB_00102264:
    lVar13 = (long)iVar4;
    goto LAB_00102268;
  }
  if (param_2 == 0x40082502) {
    puVar7 = (undefined8 *)sp_el0;
    if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
       (uVar8 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
      uVar8 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (uVar8 < 0x7ffffffff9) {
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        puVar7 = (undefined8 *)puVar7[1];
        uVar14 = ttbr1_el1;
        ttbr1_el1 = (ulong)puVar7 & 0xffff000000000000 | uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        ttbr0_el1 = puVar7;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      lVar5 = __arch_copy_from_user(puVar7,&local_88,param_3 & 0xff7fffffffffffff,8);
      if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
        uVar8 = daif;
        if ((uVar8 & 0x80) == 0) {
          uVar14 = daif;
          daif = uVar14 | 0xc0;
        }
        uVar14 = ttbr1_el1;
        ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
        InstructionSynchronizationBarrier();
        ttbr1_el1 = uVar14 & 0xffffffffffff;
        InstructionSynchronizationBarrier();
        daif = uVar8;
      }
      if (lVar5 == 0) {
        pcVar10 = *(code **)(lVar13 + 0x48);
        if (pcVar10 == (code *)0x0) goto LAB_00101f4c;
        if (*(int *)(pcVar10 + -4) != 0x1ce43c5) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x101f44);
          (*pcVar10)();
        }
        iVar4 = (*pcVar10)(lVar13,*(undefined4 *)((long)plVar12 + 0xc),(int)plVar12[2],
                           *(undefined4 *)((long)plVar12 + 0x14),local_88);
        goto LAB_00102264;
      }
    }
    lVar13 = -0xe;
    goto LAB_00102268;
  }
  if (param_2 != -0x3fefdb00) {
LAB_00101f4c:
    lVar13 = -0x19;
    goto LAB_00102268;
  }
  local_78[0] = 0;
  local_78[1] = 0;
  lVar13 = *plVar12;
  local_7c = 0;
  if (*(int *)((long)plVar12 + 0x14) != 0) {
    lVar13 = -0x10;
    goto LAB_00102268;
  }
  puVar7 = (undefined8 *)sp_el0;
  if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
     (uVar8 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
    uVar8 = param_3 & (long)(param_3 << 8) >> 8;
  }
  if (uVar8 < 0x7ffffffffd) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar7[1];
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    lVar5 = __arch_copy_from_user(&local_7c,param_3 & 0xff7fffffffffffff,4);
    uVar3 = local_7c;
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar8 = daif;
      if ((uVar8 & 0x80) == 0) {
        uVar14 = daif;
        daif = uVar14 | 0xc0;
      }
      uVar14 = ttbr1_el1;
      ttbr0_el1 = (uVar14 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar14 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar8;
    }
    if (lVar5 == 0) {
      if (local_7c - 0x1010 < 0xfffff000) {
        lVar13 = -0x16;
        goto LAB_00102268;
      }
      uVar8 = (ulong)local_7c + 1;
      lVar5 = __kmalloc(uVar8,0xdc0);
      if (lVar5 == 0) {
        lVar13 = -0xc;
        goto LAB_00102268;
      }
      uVar14 = (ulong)local_7c;
      if ((int)local_7c < 0) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x800,0x1022bc);
        (*pcVar10)();
      }
      __check_object_size(lVar5,uVar14,0);
      if (((*(byte *)((long)puVar7 + 0x46) >> 5 & 1) != 0) ||
         (uVar9 = param_3, ((uint)*puVar7 >> 0x1a & 1) != 0)) {
        uVar9 = param_3 & (long)(param_3 << 8) >> 8;
      }
      uVar6 = uVar14;
      if (uVar9 <= 0x8000000000 - uVar14) {
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar6 = daif;
            daif = uVar6 | 0xc0;
          }
          uVar6 = ttbr1_el1;
          ttbr1_el1 = puVar7[1] & 0xffff000000000000 | uVar6 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          ttbr0_el1 = puVar7[1];
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
        uVar6 = __arch_copy_from_user(lVar5,param_3 & 0xff7fffffffffffff,uVar14);
        if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
          uVar9 = daif;
          if ((uVar9 & 0x80) == 0) {
            uVar2 = daif;
            daif = uVar2 | 0xc0;
          }
          uVar2 = ttbr1_el1;
          ttbr0_el1 = (uVar2 & 0xffffffffffff) - 0x1000;
          InstructionSynchronizationBarrier();
          ttbr1_el1 = uVar2 & 0xffffffffffff;
          InstructionSynchronizationBarrier();
          daif = uVar9;
        }
      }
      if (uVar6 != 0) {
        memset((void *)(lVar5 + (uVar14 - uVar6)),0,uVar6);
        iVar4 = -0xe;
        goto LAB_00102184;
      }
      uVar14 = uVar8 & 0xfffffffe;
      if (((uVar14 == 10) || (uVar3 < 9)) || (uVar14 == 10)) {
LAB_001022dc:
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(1,0x1022e0);
        (*pcVar10)();
      }
      if (*(short *)(lVar5 + 10) == 0) {
        if ((((uVar8 & 0xfffffffc) == 0xc) || (uVar3 < 0xb)) || ((uVar8 & 0xfffffffc) == 0xc))
        goto LAB_001022dc;
        if (*(int *)(lVar5 + 0xc) != 0) goto LAB_00102180;
        uVar1 = *(uint *)(*(long *)(lVar13 + 0x3d8) + 0x1c);
        if (uVar1 == 0) {
          uVar11 = 1;
        }
        else {
          uVar11 = 0;
          if (uVar1 != 0) {
            uVar11 = 0x1000 / uVar1;
          }
        }
        if (((uVar14 == 8) || (uVar3 < 7)) || ((uVar8 & 0xfffffffe) == 8)) goto LAB_001022dc;
        iVar4 = -0x16;
        if ((*(ushort *)(lVar5 + 8) != 0) && (*(ushort *)(lVar5 + 8) <= uVar11)) {
          local_78[0] = lVar5 + 0x10;
          iVar4 = stm_assign_first_policy(*plVar12,plVar12 + 1,local_78);
          if (iVar4 == 0) {
            lVar13 = *(long *)(lVar13 + 0x3d8);
            pcVar10 = *(code **)(lVar13 + 0x38);
            if (pcVar10 != (code *)0x0) {
              if (*(int *)(pcVar10 + -4) != -0x1e587a7c) {
                    /* WARNING: Does not return */
                pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x102234);
                (*pcVar10)();
              }
              iVar4 = (*pcVar10)(lVar13,*(undefined4 *)((long)plVar12 + 0xc),(int)plVar12[2]);
              if (iVar4 != 0) {
                stm_output_free(*plVar12,plVar12 + 1);
                goto LAB_00102184;
              }
            }
            kfree(lVar5);
            goto LAB_00102258;
          }
        }
      }
      else {
LAB_00102180:
        iVar4 = -0x16;
      }
LAB_00102184:
      kfree(lVar5);
      lVar13 = (long)iVar4;
      goto LAB_00102268;
    }
  }
  lVar13 = -0xe;
LAB_00102268:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_78[2]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar13);
  }
  return;
}



//------------------------------------------------------------
// stm_char_mmap @ 00102374 size=280
// signature: undefined stm_char_mmap(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_char_mmap(long param_1,long *param_2)

{
  long lVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  code *pcVar6;
  long *plVar7;
  long lVar8;
  
  plVar7 = *(long **)(param_1 + 0xd8);
  lVar8 = *plVar7;
  lVar4 = *(long *)(lVar8 + 0x3d8);
  pcVar6 = *(code **)(lVar4 + 0x30);
  if (pcVar6 == (code *)0x0) {
    uVar5 = 0xffffffa1;
  }
  else {
    if ((param_2[0x10] == 0) &&
       (lVar1 = *param_2, lVar2 = param_2[1],
       lVar2 - lVar1 == (ulong)(uint)(*(int *)(lVar4 + 0x1c) * *(int *)((long)plVar7 + 0x14)))) {
      if (*(int *)(pcVar6 + -4) != -0x3098f71c) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x1023e0);
        (*pcVar6)();
      }
      lVar4 = (*pcVar6)(lVar4,*(undefined4 *)((long)plVar7 + 0xc),(int)plVar7[2]);
      if (lVar4 != 0) {
        __pm_runtime_resume(lVar8,4);
        param_2[3] = param_2[3] & 0xffffffffffffffefU | 0x6000000000000c;
        iVar3 = *(int *)(param_2[2] + 0xb0);
        if ((int)param_2[5] != iVar3) {
          down_write(param_2[6]);
          *(int *)(param_2 + 5) = iVar3;
          up_write(param_2[6]);
        }
        param_2[4] = param_2[4] | 0x4044000;
        param_2[0xf] = (long)&stm_mmap_vmops;
        vm_iomap_memory(param_2,lVar4,lVar2 - lVar1);
        return 0;
      }
    }
    uVar5 = 0xffffffea;
  }
  return uVar5;
}



//------------------------------------------------------------
// stm_char_open @ 00102490 size=252
// signature: undefined stm_char_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 stm_char_open(long param_1,long param_2)

{
  undefined4 uVar1;
  long lVar2;
  long *plVar3;
  ulong uVar4;
  uint local_3c;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_3c = *(uint *)(param_1 + 0x4c) >> 0x14;
  lVar2 = class_find_device(&stm_class,0,&local_3c,major_match);
  if (lVar2 == 0) {
    uVar1 = 0xffffffed;
  }
  else {
    plVar3 = (long *)kmalloc_trace(_vzalloc,0xdc0,0x20);
    if (plVar3 == (long *)0x0) {
      uVar1 = 0xfffffff4;
    }
    else {
      *(undefined4 *)(plVar3 + 1) = 0;
      *plVar3 = lVar2;
      uVar4 = try_module_get(*(undefined8 *)(lVar2 + 0x390));
      if ((uVar4 & 1) != 0) {
        *(long **)(param_2 + 0xd8) = plVar3;
        uVar1 = nonseekable_open(param_1,param_2);
        goto LAB_00102558;
      }
      kfree(plVar3);
      uVar1 = 0xffffffed;
    }
    put_device(lVar2);
  }
LAB_00102558:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar1;
}



//------------------------------------------------------------
// stm_char_release @ 00102590 size=124
// signature: undefined stm_char_release(void)
// callers: []
//------------------------------------------------------------

undefined8 stm_char_release(undefined8 param_1,long param_2)

{
  code *pcVar1;
  long *plVar2;
  long lVar3;
  
  plVar2 = *(long **)(param_2 + 0xd8);
  lVar3 = *plVar2;
  pcVar1 = *(code **)(*(long *)(lVar3 + 0x3d8) + 0x40);
  if (pcVar1 != (code *)0x0) {
    if (*(int *)(pcVar1 + -4) != 0x3f39d35) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1025d0);
      (*pcVar1)();
    }
    (*pcVar1)(*(long *)(lVar3 + 0x3d8),*(undefined4 *)((long)plVar2 + 0xc),(int)plVar2[2]);
  }
  stm_output_free(lVar3,plVar2 + 1);
  module_put(*(undefined8 *)(lVar3 + 0x390));
  put_device(lVar3);
  kfree(plVar2);
  return 0;
}



//------------------------------------------------------------
// stm_assign_first_policy @ 0010260c size=912
// signature: undefined stm_assign_first_policy(void)
// callers: [stm_char_write, stm_source_link_store, stm_char_ioctl]
//------------------------------------------------------------

int stm_assign_first_policy(long param_1,long param_2,long *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  undefined4 *puVar6;
  long lVar7;
  int *piVar8;
  ulong uVar9;
  code *pcVar10;
  uint *puVar11;
  uint uVar12;
  int local_78;
  uint local_74;
  undefined8 local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  if (*param_3 != 0) {
    iVar4 = 1;
    do {
      lVar5 = stp_policy_node_lookup(param_1);
      if (param_3[iVar4] == 0) break;
      iVar4 = iVar4 + 1;
    } while (lVar5 == 0);
    if (lVar5 != 0) {
      local_70 = 0;
      local_74 = 0;
      local_78 = 0;
      if (*(uint *)(*(long *)(param_1 + 0x3d8) + 0x18) < param_4) {
        iVar4 = -0x16;
      }
      else {
        stp_policy_node_get_ranges(lVar5,(long)&local_70 + 4,&local_74,&local_70,&local_78);
        _raw_spin_lock(param_1 + 0x438);
        _raw_spin_lock(param_2);
        uVar2 = local_74;
        if (*(int *)(param_2 + 0xc) != 0) {
                    /* WARNING: Does not return */
          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x102988);
          (*pcVar10)();
        }
        if (local_74 < local_70._4_4_) {
          iVar4 = -0x1c;
        }
        else {
          uVar1 = local_78 + 1;
          uVar12 = local_70._4_4_;
          do {
            lVar7 = *(long *)(param_1 + 0x3d8);
            uVar3 = *(uint *)(lVar7 + 0x10);
            if (((uVar12 < uVar3) || (*(uint *)(lVar7 + 0x14) < uVar12)) ||
               (*(long *)(param_1 + (ulong)(uVar12 - uVar3) * 8 + 0x440) == 0)) {
              puVar6 = (undefined4 *)
                       __kmalloc(((ulong)*(uint *)(lVar7 + 0x18) + 0x3f >> 3 & 0x3ffffff8) + 8,0xb20
                                );
              if (puVar6 == (undefined4 *)0x0) {
                iVar4 = -0xc;
                goto LAB_00102858;
              }
              lVar7 = *(long *)(param_1 + 0x3d8);
              *puVar6 = *(undefined4 *)(lVar7 + 0x18);
              *(undefined4 **)(param_1 + (ulong)(uVar12 - *(int *)(lVar7 + 0x10)) * 8 + 0x440) =
                   puVar6;
              uVar3 = *(uint *)(lVar7 + 0x10);
              if (uVar3 <= uVar12) goto LAB_00102798;
LAB_001027a4:
              piVar8 = (int *)0x0;
              iVar4 = iRam0000000000000000;
            }
            else {
              if (uVar12 < uVar3) goto LAB_001027a4;
LAB_00102798:
              if (*(uint *)(lVar7 + 0x14) < uVar12) goto LAB_001027a4;
              piVar8 = *(int **)(param_1 + (ulong)(uVar12 - uVar3) * 8 + 0x440);
              iVar4 = *piVar8;
            }
            if ((iVar4 != 0) && ((uint)local_70 < uVar1)) {
              uVar3 = (uint)local_70;
              do {
                lVar7 = _find_next_zero_bit(piVar8 + 2,uVar1,uVar3);
                uVar3 = (uint)lVar7;
                if (uVar1 < uVar3 + param_4) break;
                if ((param_4 - 1 & uVar3) == 0) {
                  uVar9 = 1;
                  if (1 < param_4) {
                    while ((*(ulong *)(piVar8 + 2 + (lVar7 + uVar9 >> 6 & 0x3ffffff) * 2) >>
                            (lVar7 + uVar9 & 0x3f) & 1) == 0) {
                      uVar9 = uVar9 + 1;
                      if (param_4 == uVar9) goto LAB_0010270c;
                    }
                  }
                  if ((uint)uVar9 == param_4) {
LAB_0010270c:
                    if (-1 < (int)uVar3) {
                      local_70 = CONCAT44(uVar12,uVar3);
                      *(uint *)(param_2 + 4) = uVar12;
                      *(uint *)(param_2 + 8) = uVar3;
                      *(uint *)(param_2 + 0xc) = param_4;
                      if (*(long *)(*(long *)(param_1 + 0x428) + 0x20) != 0) {
                        lVar7 = stp_policy_node_priv(lVar5);
                        if (lVar7 == 0) {
                    /* WARNING: Does not return */
                          pcVar10 = (code *)SoftwareBreakpoint(0x800,0x102994);
                          (*pcVar10)();
                        }
                        pcVar10 = *(code **)(*(long *)(param_1 + 0x428) + 0x20);
                        if (*(int *)(pcVar10 + -4) != -0x51c671ae) {
                    /* WARNING: Does not return */
                          pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x1028fc);
                          (*pcVar10)();
                        }
                        iVar4 = (*pcVar10)(lVar7,param_2);
                        if (iVar4 != 0) goto LAB_00102858;
                        uVar12 = *(uint *)(param_2 + 4);
                      }
                      uVar2 = *(uint *)(*(long *)(param_1 + 0x3d8) + 0x10);
                      if ((uVar12 < uVar2) ||
                         (*(uint *)(*(long *)(param_1 + 0x3d8) + 0x14) < uVar12)) {
                        puVar11 = (uint *)0x0;
                      }
                      else {
                        puVar11 = *(uint **)(param_1 + (ulong)(uVar12 - uVar2) * 8 + 0x440);
                      }
                      uVar2 = *(uint *)(param_2 + 0xc);
                      if (*puVar11 < uVar2) {
                    /* WARNING: Does not return */
                        pcVar10 = (code *)SoftwareBreakpoint(0x800,0x1029a0);
                        (*pcVar10)();
                      }
                      iVar4 = 0x1f - (int)LZCOUNT(uVar2);
                      if (uVar2 == 0) {
                        iVar4 = -1;
                      }
                      bitmap_allocate_region(puVar11 + 2,*(undefined4 *)(param_2 + 8),iVar4);
                      iVar4 = 0;
                      *puVar11 = *puVar11 - *(int *)(param_2 + 0xc);
                      goto LAB_0010285c;
                    }
                    break;
                  }
                  uVar3 = (uint)uVar9 + uVar3;
                }
                uVar3 = uVar3 + (param_4 - 1) & -param_4;
              } while (uVar3 < uVar1);
            }
            uVar12 = uVar12 + 1;
          } while (uVar12 <= uVar2);
          iVar4 = -0x1c;
        }
LAB_00102858:
        *(undefined4 *)(param_2 + 0xc) = 0;
LAB_0010285c:
        _raw_spin_unlock(param_2);
        _raw_spin_unlock(param_1 + 0x438);
      }
      stp_policy_node_put(lVar5);
      goto LAB_00102874;
    }
  }
  iVar4 = -0x16;
LAB_00102874:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// stm_char_policy_get_ioctl @ 001029a8 size=340
// signature: undefined stm_char_policy_get_ioctl(void)
// callers: [stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void stm_char_policy_get_ioctl(long param_1,ulong param_2)

{
  ulong uVar1;
  long lVar2;
  undefined4 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined4 local_1c;
  long local_18;
  
  lVar2 = sp_el0;
  local_18 = *(long *)(lVar2 + 0x638);
  local_28 = 0x10;
  local_1e = 0;
  local_1c = 0;
  local_24 = (undefined2)*(undefined4 *)(param_1 + 0xc);
  puVar4 = (undefined8 *)sp_el0;
  local_22 = (undefined2)*(undefined4 *)(param_1 + 0x10);
  local_20 = (undefined2)*(undefined4 *)(param_1 + 0x14);
  if (((*(byte *)((long)puVar4 + 0x46) >> 5 & 1) != 0) ||
     (uVar5 = param_2, ((uint)*puVar4 >> 0x1a & 1) != 0)) {
    uVar5 = param_2 & (long)(param_2 << 8) >> 8;
  }
  if (uVar5 < 0x7ffffffff1) {
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      puVar4 = (undefined8 *)puVar4[1];
      uVar1 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar4 & 0xffff000000000000 | uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar4;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    lVar2 = __arch_copy_to_user(puVar4,param_2 & 0xff7fffffffffffff,&local_28,0x10);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar5 = daif;
      if ((uVar5 & 0x80) == 0) {
        uVar1 = daif;
        daif = uVar1 | 0xc0;
      }
      uVar1 = ttbr1_el1;
      ttbr0_el1 = (uVar1 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar1 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar5;
    }
    uVar3 = 0;
    if (lVar2 != 0) {
      uVar3 = 0xfffffff2;
    }
  }
  else {
    uVar3 = 0xfffffff2;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// stm_output_free @ 00102b14 size=228
// signature: undefined stm_output_free(void)
// callers: [stm_char_release, __stm_source_link_drop, stm_source_link_store, stm_char_ioctl]
//------------------------------------------------------------

void stm_output_free(long param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int *piVar4;
  
  _raw_spin_lock(param_1 + 0x438);
  _raw_spin_lock(param_2);
  if (*(int *)(param_2 + 0xc) != 0) {
    uVar1 = *(uint *)(param_2 + 4);
    uVar2 = *(uint *)(*(long *)(param_1 + 0x3d8) + 0x10);
    if ((uVar1 < uVar2) || (*(uint *)(*(long *)(param_1 + 0x3d8) + 0x14) < uVar1)) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(param_1 + (ulong)(uVar1 - uVar2) * 8 + 0x440);
    }
    bitmap_release_region
              (piVar4 + 2,*(undefined4 *)(param_2 + 8),(uint)LZCOUNT(*(int *)(param_2 + 0xc)) ^ 0x1f
              );
    *piVar4 = *piVar4 + *(int *)(param_2 + 0xc);
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  if ((*(long *)(param_1 + 0x428) != 0) &&
     (pcVar3 = *(code **)(*(long *)(param_1 + 0x428) + 0x28), pcVar3 != (code *)0x0)) {
    if (*(int *)(pcVar3 + -4) != 0xdde21fd) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102bd0);
      (*pcVar3)();
    }
    (*pcVar3)(param_2);
  }
  _raw_spin_unlock(param_2);
  _raw_spin_unlock(param_1 + 0x438);
  return;
}



//------------------------------------------------------------
// stm_mmap_open @ 00102bfc size=44
// signature: undefined stm_mmap_open(void)
// callers: []
//------------------------------------------------------------

void stm_mmap_open(long param_1)

{
  __pm_runtime_resume(**(undefined8 **)(*(long *)(param_1 + 0x88) + 0xd8),5);
  return;
}



//------------------------------------------------------------
// stm_mmap_close @ 00102c2c size=64
// signature: undefined stm_mmap_close(void)
// callers: []
//------------------------------------------------------------

void stm_mmap_close(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = **(long **)(*(long *)(param_1 + 0x88) + 0xd8);
  uVar1 = ktime_get_mono_fast_ns();
  *(undefined8 *)(lVar2 + 0x220) = uVar1;
  __pm_runtime_suspend(lVar2,0xd);
  return;
}



//------------------------------------------------------------
// major_match @ 00102c70 size=20
// signature: undefined major_match(void)
// callers: []
//------------------------------------------------------------

bool major_match(long param_1,uint *param_2)

{
  return *param_2 == *(uint *)(param_1 + 0x2f8) >> 0x14;
}



//------------------------------------------------------------
// stm_source_link_show @ 00102c88 size=128
// signature: undefined stm_source_link_show(void)
// callers: []
//------------------------------------------------------------

long stm_source_link_show(long param_1,undefined8 param_2,char *param_3)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  long *plVar4;
  
  uVar1 = __srcu_read_lock(stm_source_srcu);
  plVar4 = *(long **)(param_1 + 0x3d0);
  if (plVar4 == (long *)0x0) {
    pcVar3 = "<none>";
  }
  else {
    pcVar3 = (char *)plVar4[0xe];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = (char *)*plVar4;
    }
  }
  iVar2 = sprintf(param_3,"%s\n",pcVar3);
  __srcu_read_unlock(stm_source_srcu,uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// stm_source_link_store @ 00102d0c size=820
// signature: undefined stm_source_link_store(void)
// callers: []
//------------------------------------------------------------

long stm_source_link_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  undefined4 uVar6;
  int iVar7;
  ulong uVar8;
  long lVar9;
  code *pcVar10;
  long lVar11;
  long *plVar12;
  long local_80;
  undefined *puStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar11 = sp_el0;
  lVar1 = param_1 + 0x398;
  local_68 = *(long *)(lVar11 + 0x638);
  mutex_lock(lVar1);
  do {
    uVar6 = __srcu_read_lock(stm_source_srcu);
    lVar11 = *(long *)(param_1 + 0x3d0);
    if (lVar11 == 0) {
      __srcu_read_unlock(stm_source_srcu,uVar6);
      break;
    }
    mutex_lock(lVar11 + 0x3e0);
    iVar7 = __stm_source_link_drop(param_1,lVar11);
    mutex_unlock(lVar11 + 0x3e0);
    __srcu_read_unlock(stm_source_srcu,uVar6);
  } while (iVar7 == -0xb);
  if ((stm_core_up != 0) &&
     (lVar11 = class_find_device(&stm_class,0,param_3,&device_match_name), lVar11 != 0)) {
    uVar8 = try_module_get(*(undefined8 *)(lVar11 + 0x390));
    if ((uVar8 & 1) != 0) {
      __pm_runtime_resume(lVar11,5);
      lVar2 = lVar11 + 0x3e0;
      local_80 = DAT_001044e8;
      puStack_78 = PTR_s_default_001044f0;
      local_70 = DAT_001044f8;
      mutex_lock(lVar2);
      lVar3 = lVar11 + 0x410;
      _raw_spin_lock(lVar3);
      lVar4 = param_1 + 0x3c8;
      _raw_spin_lock(lVar4);
      *(long *)(param_1 + 0x3d0) = lVar11;
      plVar12 = *(long **)(lVar11 + 0x420);
      lVar5 = param_1 + 0x3d8;
      uVar8 = __list_add_valid(lVar5,plVar12,lVar11 + 0x418);
      if ((uVar8 & 1) != 0) {
        *(long *)(lVar11 + 0x420) = lVar5;
        *(long *)(param_1 + 0x3d8) = lVar11 + 0x418;
        *(long **)(param_1 + 0x3e0) = plVar12;
        *plVar12 = lVar5;
      }
      _raw_spin_unlock(lVar4);
      _raw_spin_unlock(lVar3);
      mutex_unlock(lVar2);
      lVar9 = kstrdup(**(undefined8 **)(param_1 + 0x390),0xcc0);
      local_80 = lVar9;
      if (lVar9 == 0) {
        iVar7 = -0xc;
      }
      else {
        iVar7 = stm_assign_first_policy
                          (lVar11,param_1 + 1000,&local_80,
                           *(undefined4 *)(*(long *)(param_1 + 0x390) + 0x14));
        kfree(lVar9);
        if (iVar7 == 0) {
          pcVar10 = *(code **)(*(long *)(lVar11 + 0x3d8) + 0x38);
          if (pcVar10 != (code *)0x0) {
            if (*(int *)(pcVar10 + -4) != -0x1e587a7c) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x102f0c);
              (*pcVar10)();
            }
            iVar7 = (*pcVar10)(*(long *)(lVar11 + 0x3d8),*(undefined4 *)(param_1 + 0x3ec),
                               *(undefined4 *)(param_1 + 0x3f0));
            if (iVar7 != 0) {
              stm_output_free(lVar11,param_1 + 1000);
              goto LAB_00102f80;
            }
          }
          pcVar10 = *(code **)(*(long *)(param_1 + 0x390) + 0x18);
          if (pcVar10 != (code *)0x0) {
            if (*(int *)(pcVar10 + -4) != -0x4479b05) {
                    /* WARNING: Does not return */
              pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x10302c);
              (*pcVar10)();
            }
            (*pcVar10)();
          }
          mutex_unlock(lVar1);
          goto LAB_00102f40;
        }
      }
LAB_00102f80:
      mutex_lock(lVar2);
      _raw_spin_lock(lVar3);
      _raw_spin_lock(lVar4);
      *(undefined8 *)(param_1 + 0x3d0) = 0;
      uVar8 = __list_del_entry_valid(lVar5);
      if ((uVar8 & 1) != 0) {
        plVar12 = *(long **)(param_1 + 0x3e0);
        lVar9 = *(long *)(param_1 + 0x3d8);
        *(long **)(lVar9 + 8) = plVar12;
        *plVar12 = lVar9;
      }
      *(long *)(param_1 + 0x3d8) = param_1 + 0x3d8;
      *(long *)(param_1 + 0x3e0) = lVar5;
      _raw_spin_unlock(lVar4);
      _raw_spin_unlock(lVar3);
      mutex_unlock(lVar2);
      __pm_runtime_suspend(lVar11,0xd);
      module_put(*(undefined8 *)(lVar11 + 0x390));
      put_device(lVar11);
      mutex_unlock(lVar1);
      param_4 = (long)iVar7;
      goto LAB_00102f40;
    }
    put_device(lVar11);
  }
  mutex_unlock(lVar1);
  param_4 = -0x16;
LAB_00102f40:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// stp_policy_node_priv @ 0010310c size=16
// signature: undefined stp_policy_node_priv(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

long stp_policy_node_priv(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + 0xa0;
  }
  return lVar1;
}



//------------------------------------------------------------
// stp_policy_node_get_ranges @ 00103120 size=36
// signature: undefined stp_policy_node_get_ranges(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

void stp_policy_node_get_ranges
               (long param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
               undefined4 *param_5)

{
  *param_2 = *(undefined4 *)(param_1 + 0x90);
  *param_3 = *(undefined4 *)(param_1 + 0x94);
  *param_4 = *(undefined4 *)(param_1 + 0x98);
  *param_5 = *(undefined4 *)(param_1 + 0x9c);
  return;
}



//------------------------------------------------------------
// to_pdrv_policy_node @ 00103148 size=16
// signature: undefined to_pdrv_policy_node(void)
// callers: []
//------------------------------------------------------------

long to_pdrv_policy_node(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if (param_1 != 0) {
    lVar1 = param_1 + 0xa0;
  }
  return lVar1;
}



//------------------------------------------------------------
// get_policy_node_type @ 0010315c size=108
// signature: undefined get_policy_node_type(void)
// callers: [stm_register_protocol]
//------------------------------------------------------------

long get_policy_node_type(undefined8 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = kmemdup(&stp_policy_node_type,0x28,0xcc0);
  if (lVar1 != 0) {
    lVar2 = __memcat_p(&stp_policy_node_attrs,param_1);
    if (lVar2 == 0) {
      kfree(lVar1);
      lVar1 = 0;
    }
    else {
      *(long *)(lVar1 + 0x18) = lVar2;
    }
  }
  return lVar1;
}



//------------------------------------------------------------
// stp_policy_unbind @ 001031cc size=72
// signature: undefined stp_policy_unbind(void)
// callers: [stm_unregister_device]
//------------------------------------------------------------

void stp_policy_unbind(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x88);
  if (lVar2 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x103214);
    (*pcVar1)();
  }
  *(undefined8 *)(lVar2 + 0x398) = 0;
  *(undefined8 *)(param_1 + 0x88) = 0;
  stm_put_protocol(*(undefined8 *)(lVar2 + 0x428));
  *(undefined8 *)(lVar2 + 0x428) = 0;
  stm_put_device(lVar2);
  return;
}



//------------------------------------------------------------
// stp_policy_node_lookup @ 0010321c size=288
// signature: undefined stp_policy_node_lookup(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

long * stp_policy_node_lookup(long param_1,char *param_2)

{
  long lVar1;
  int iVar2;
  char *__s1;
  long *plVar3;
  long *plVar4;
  long *plVar5;
  char *local_50;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  mutex_lock(&DAT_00104168);
  lVar1 = param_1 + 0x3a0;
  mutex_lock(lVar1);
  if (*(long *)(param_1 + 0x398) == 0) {
LAB_001032ec:
    mutex_unlock(lVar1);
  }
  else {
    plVar4 = (long *)(*(long *)(param_1 + 0x398) + 0x50);
    local_50 = param_2;
    if ((long *)*plVar4 == plVar4) goto LAB_001032ec;
    plVar3 = (long *)0x0;
    while (__s1 = strsep(&local_50,"/"), __s1 != (char *)0x0) {
      if (*__s1 != '\0') {
        plVar5 = plVar4;
        do {
          plVar5 = (long *)*plVar5;
          if (plVar5 == plVar4) goto LAB_001032d4;
          iVar2 = strcmp(__s1,(char *)plVar5[-4]);
        } while (iVar2 != 0);
        plVar3 = plVar5 + -4;
        plVar4 = plVar5 + 6;
        if (local_50 == (char *)0x0) break;
      }
    }
LAB_001032d4:
    mutex_unlock(lVar1);
    if (plVar3 != (long *)0x0) {
      config_item_get(plVar3);
      goto LAB_00103304;
    }
  }
  mutex_unlock(&DAT_00104168);
  plVar3 = (long *)0x0;
LAB_00103304:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar3;
}



//------------------------------------------------------------
// stp_policy_node_put @ 00103340 size=56
// signature: undefined stp_policy_node_put(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

void stp_policy_node_put(undefined8 param_1)

{
  mutex_unlock(&DAT_00104168);
  config_item_put(param_1);
  return;
}



//------------------------------------------------------------
// stp_policy_node_masters_show @ 0010337c size=52
// signature: undefined stp_policy_node_masters_show(void)
// callers: []
//------------------------------------------------------------

long stp_policy_node_masters_show(long param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = sprintf(param_2,"%u %u\n",*(uint *)(param_1 + 0x90),*(uint *)(param_1 + 0x94));
  return (long)iVar1;
}



//------------------------------------------------------------
// stp_policy_node_masters_store @ 001033b4 size=232
// signature: undefined stp_policy_node_masters_store(void)
// callers: []
//------------------------------------------------------------

undefined8 stp_policy_node_masters_store(long param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  uint local_30 [2];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_30[0] = 0;
  local_30[1] = 0;
  iVar1 = sscanf(param_2,"%u %u",local_30 + 1,local_30);
  if (iVar1 == 2) {
    mutex_lock(&DAT_00104168);
    lVar2 = *(long *)(*(long *)(param_1 + 0x88) + 0x88);
    if (lVar2 == 0) {
      param_3 = 0xffffffffffffffed;
    }
    else if (((local_30[0] < local_30[1]) ||
             (lVar2 = *(long *)(lVar2 + 0x3d8), local_30[1] < *(uint *)(lVar2 + 0x10))) ||
            (*(uint *)(lVar2 + 0x14) < local_30[0])) {
      param_3 = 0xffffffffffffffde;
    }
    else {
      *(uint *)(param_1 + 0x90) = local_30[1];
      *(uint *)(param_1 + 0x94) = local_30[0];
    }
    mutex_unlock(&DAT_00104168);
  }
  else {
    param_3 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// stp_policy_node_channels_show @ 001034a0 size=52
// signature: undefined stp_policy_node_channels_show(void)
// callers: []
//------------------------------------------------------------

long stp_policy_node_channels_show(long param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = sprintf(param_2,"%u %u\n",*(uint *)(param_1 + 0x98),*(uint *)(param_1 + 0x9c));
  return (long)iVar1;
}



//------------------------------------------------------------
// stp_policy_node_channels_store @ 001034d8 size=240
// signature: undefined stp_policy_node_channels_store(void)
// callers: []
//------------------------------------------------------------

undefined8 stp_policy_node_channels_store(long param_1,char *param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  iVar1 = sscanf(param_2,"%u %u",(uint *)((long)&local_40 + 4),(uint *)&local_40);
  if (iVar1 == 2) {
    mutex_lock(&DAT_00104168);
    lVar2 = *(long *)(*(long *)(param_1 + 0x88) + 0x88);
    if (lVar2 == 0) {
      uVar3 = 0xffffffffffffffed;
    }
    else {
      uVar3 = 0xffffffffffffffde;
      if ((((-1 < local_40) && (-1 < (int)(uint)local_40)) && (local_40._4_4_ <= (uint)local_40)) &&
         ((uint)local_40 < *(uint *)(*(long *)(lVar2 + 0x3d8) + 0x18))) {
        *(uint *)(param_1 + 0x98) = local_40._4_4_;
        *(uint *)(param_1 + 0x9c) = (uint)local_40;
        uVar3 = param_3;
      }
    }
    mutex_unlock(&DAT_00104168);
  }
  else {
    uVar3 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar3;
}



//------------------------------------------------------------
// stp_policy_node_release @ 001035cc size=28
// signature: undefined stp_policy_node_release(void)
// callers: []
//------------------------------------------------------------

void stp_policy_node_release(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// stp_policy_node_make @ 001035ec size=260
// signature: undefined stp_policy_node_make(void)
// callers: []
//------------------------------------------------------------

long stp_policy_node_make(long param_1,undefined8 param_2)

{
  undefined **ppuVar1;
  long lVar2;
  code *pcVar3;
  undefined **ppuVar4;
  long lVar5;
  
  if (*(undefined ***)(param_1 + 0x40) != &stp_policy_type) {
    param_1 = *(long *)(param_1 + 0x88);
  }
  if (*(long *)(param_1 + 0x88) == 0) {
    lVar2 = -0x13;
  }
  else {
    lVar5 = *(long *)(*(long *)(param_1 + 0x88) + 0x428);
    lVar2 = __kmalloc(*(long *)(lVar5 + 0x30) + 0xa0,0xdc0);
    if (lVar2 == 0) {
      lVar2 = -0xc;
    }
    else {
      pcVar3 = *(code **)(lVar5 + 0x18);
      if (pcVar3 != (code *)0x0) {
        if (*(int *)(pcVar3 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x103668);
          (*pcVar3)();
        }
        (*pcVar3)(lVar2 + 0xa0);
      }
      ppuVar4 = *(undefined ***)(*(long *)(param_1 + 0x88) + 0x430);
      ppuVar1 = &stp_policy_node_type;
      if (ppuVar4 != (undefined **)0x0) {
        ppuVar1 = ppuVar4;
      }
      config_group_init_type_name(lVar2,param_2,ppuVar1);
      *(long *)(lVar2 + 0x88) = param_1;
      *(undefined4 *)(lVar2 + 0x90) =
           *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x88) + 0x3d8) + 0x10);
      *(undefined4 *)(lVar2 + 0x94) =
           *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x88) + 0x3d8) + 0x14);
      *(undefined4 *)(lVar2 + 0x98) = 0;
      *(int *)(lVar2 + 0x9c) = *(int *)(*(long *)(*(long *)(param_1 + 0x88) + 0x3d8) + 0x18) + -1;
    }
  }
  return lVar2;
}



//------------------------------------------------------------
// stp_policy_node_drop @ 001036f4 size=32
// signature: undefined stp_policy_node_drop(void)
// callers: []
//------------------------------------------------------------

void stp_policy_node_drop(undefined8 param_1,undefined8 param_2)

{
  config_item_put(param_2);
  return;
}



//------------------------------------------------------------
// stp_policy_release @ 00103718 size=120
// signature: undefined stp_policy_release(void)
// callers: []
//------------------------------------------------------------

void stp_policy_release(long param_1)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  
  if (*(long *)(param_1 + 0x88) != 0) {
    lVar1 = *(long *)(param_1 + 0x88) + 0x3a0;
    mutex_lock(lVar1);
    lVar3 = *(long *)(param_1 + 0x88);
    if (lVar3 == 0) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x800,0x103790);
      (*pcVar2)();
    }
    *(undefined8 *)(lVar3 + 0x398) = 0;
    *(undefined8 *)(param_1 + 0x88) = 0;
    stm_put_protocol(*(undefined8 *)(lVar3 + 0x428));
    *(undefined8 *)(lVar3 + 0x428) = 0;
    stm_put_device(lVar3);
    mutex_unlock(lVar1);
    kfree(param_1);
  }
  return;
}



//------------------------------------------------------------
// stp_policy_device_show @ 00103798 size=80
// signature: undefined stp_policy_device_show(void)
// callers: []
//------------------------------------------------------------

long stp_policy_device_show(long param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x88) == 0)) {
    pcVar2 = "<none>";
  }
  else {
    pcVar2 = (char *)**(undefined8 **)(*(long *)(param_1 + 0x88) + 0x3d8);
  }
  iVar1 = sprintf(param_2,"%s\n",pcVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// stp_policy_protocol_show @ 001037ec size=80
// signature: undefined stp_policy_protocol_show(void)
// callers: []
//------------------------------------------------------------

long stp_policy_protocol_show(long param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  
  if ((param_1 == 0) || (*(long *)(param_1 + 0x88) == 0)) {
    pcVar2 = "<none>";
  }
  else {
    pcVar2 = *(char **)(*(long *)(*(long *)(param_1 + 0x88) + 0x428) + 8);
  }
  iVar1 = sprintf(param_2,"%s\n",pcVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// stp_policy_make @ 00103840 size=412
// signature: undefined stp_policy_make(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong stp_policy_make(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  char *__s;
  char *pcVar3;
  char *pcVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_48 = 0;
  uStack_40 = 0;
  __s = (char *)kasprintf(0xcc0,&DAT_001045b7,param_2);
  if (__s == (char *)0x0) {
    uVar7 = 0xfffffffffffffff4;
    goto LAB_00103948;
  }
  pcVar3 = strrchr(__s,0x2e);
  if (pcVar3 == (char *)0x0) {
    kfree(__s);
    uVar7 = 0xffffffffffffffea;
    goto LAB_00103948;
  }
  *pcVar3 = '\0';
  pcVar4 = strrchr(__s,0x3a);
  pcVar3 = pcVar4;
  if (pcVar4 != (char *)0x0) {
    pcVar3 = pcVar4 + 1;
    *pcVar4 = '\0';
  }
  lVar5 = stm_find_device(__s);
  if (lVar5 == 0) {
    kfree(__s);
    uVar7 = 0xffffffffffffffed;
    goto LAB_00103948;
  }
  iVar2 = stm_lookup_protocol(pcVar3,&local_48,&uStack_40);
  kfree(__s);
  if (iVar2 != 0) {
    stm_put_device(lVar5);
    uVar7 = 0xffffffffffffffed;
    goto LAB_00103948;
  }
  lVar1 = lVar5 + 0x3a0;
  mutex_lock(lVar1);
  if (*(long *)(lVar5 + 0x398) == 0) {
    lVar6 = kmalloc_trace(___list_add_valid,0xdc0,0x90);
    *(long *)(lVar5 + 0x398) = lVar6;
    if (lVar6 == 0) {
      uVar7 = 0xfffffffffffffff4;
      goto LAB_00103930;
    }
    config_group_init_type_name(lVar6,param_2,&stp_policy_type);
    *(undefined8 *)(lVar5 + 0x428) = local_48;
    *(undefined8 *)(lVar5 + 0x430) = uStack_40;
    *(long *)(*(long *)(lVar5 + 0x398) + 0x88) = lVar5;
    uVar7 = *(ulong *)(lVar5 + 0x398);
    mutex_unlock(lVar1);
    if (uVar7 < 0xfffffffffffff001) goto LAB_00103948;
  }
  else {
    uVar7 = 0xfffffffffffffff0;
LAB_00103930:
    mutex_unlock(lVar1);
  }
  stm_put_protocol(local_48);
  stm_put_device(lVar5);
LAB_00103948:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// init_module @ 00103b00 size=204
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = __class_register(&stm_class,&stm_core_init___key);
  if (iVar1 == 0) {
    iVar1 = __class_register(&stm_source_class,&stm_core_init___key_19);
    if (iVar1 == 0) {
      iVar1 = stp_configfs_init();
      if (iVar1 == 0) {
        init_srcu_struct(stm_source_srcu);
        stm_pdrv_head = &stm_pdrv_head;
        DAT_00103cd0 = &stm_pdrv_head;
        __mutex_init(stm_pdrv_mutex,"&stm_pdrv_mutex",&stm_core_init___key_20);
        stm_core_up = stm_core_up + 1;
        return 0;
      }
      class_unregister(&stm_source_class);
    }
    class_unregister(&stm_class);
  }
  return iVar1;
}



//------------------------------------------------------------
// stp_configfs_init @ 00103bd0 size=80
// signature: undefined stp_configfs_init(void)
// callers: [init_module]
//------------------------------------------------------------

void stp_configfs_init(void)

{
  config_group_init(&stp_policy_subsys);
  __mutex_init(&DAT_00104168,"&stp_policy_subsys.su_mutex",&stp_configfs_init___key);
  configfs_register_subsystem(&stp_policy_subsys);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103c24 size=64
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  cleanup_srcu_struct(stm_source_srcu);
  class_unregister(&stm_source_class);
  class_unregister(&stm_class);
  stp_configfs_exit();
  return;
}



//------------------------------------------------------------
// stp_configfs_exit @ 00103c68 size=36
// signature: undefined stp_configfs_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void stp_configfs_exit(void)

{
  configfs_unregister_subsystem(&stp_policy_subsys);
  return;
}



//------------------------------------------------------------
// class_find_device @ 00106008 size=1
// signature: undefined class_find_device(void)
// callers: [stm_find_device, stm_char_open, stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_find_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 00106010 size=1
// signature: undefined try_module_get(void)
// callers: [stm_find_device, stm_lookup_protocol, stm_char_open, stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 00106018 size=1
// signature: undefined put_device(void)
// callers: [stm_char_release, stm_register_device, __stm_source_link_drop, stm_put_device, stm_find_device, stm_char_open, stm_source_register_device, stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 00106020 size=1
// signature: undefined module_put(void)
// callers: [stm_char_release, __stm_source_link_drop, stm_put_device, stm_source_link_store, stm_put_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00106028 size=1
// signature: undefined mutex_lock(void)
// callers: [stm_unregister_device, stp_policy_node_channels_store, stm_unregister_protocol, stm_lookup_protocol, stp_policy_make, stp_policy_release, stm_source_link_store, stp_policy_node_lookup, stp_policy_node_masters_store, stm_source_unregister_device, stm_register_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00106030 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [stm_lookup_protocol, stp_policy_node_lookup, stm_register_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00106040 size=1
// signature: undefined kmalloc_trace(void)
// callers: [stm_char_open, stp_policy_make, stm_source_register_device, stm_register_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00106048 size=1
// signature: undefined __list_add_valid(void)
// callers: [stm_source_link_store, stm_register_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00106050 size=1
// signature: undefined mutex_unlock(void)
// callers: [stm_unregister_device, stp_policy_node_channels_store, stm_unregister_protocol, stp_policy_node_put, stm_lookup_protocol, stp_policy_make, stp_policy_release, stm_source_link_store, stp_policy_node_lookup, stp_policy_node_masters_store, stm_source_unregister_device, stm_register_protocol]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106058 size=1
// signature: undefined kfree(void)
// callers: [stm_char_release, stm_unregister_device, stm_char_open, stm_char_write, stm_source_device_release, stm_source_link_store, stm_char_ioctl, stm_register_protocol, stm_unregister_protocol, stp_policy_make, get_policy_node_type, stp_policy_release, stp_policy_node_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00106060 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [__stm_source_link_drop, stm_unregister_protocol, stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vzalloc @ 00106068 size=1
// signature: undefined vzalloc(void)
// callers: [stm_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vzalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_chrdev @ 00106070 size=1
// signature: undefined __register_chrdev(void)
// callers: [stm_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_initialize @ 00106078 size=1
// signature: undefined device_initialize(void)
// callers: [stm_register_device, stm_source_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_initialize(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00106080 size=1
// signature: undefined __mutex_init(void)
// callers: [stm_register_device, init_module, stm_source_register_device, stp_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_set_name @ 00106088 size=1
// signature: undefined kobject_set_name(void)
// callers: [stm_register_device, stm_source_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_add @ 00106090 size=1
// signature: undefined device_add(void)
// callers: [stm_register_device, stm_source_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __unregister_chrdev @ 00106098 size=1
// signature: undefined __unregister_chrdev(void)
// callers: [stm_register_device, stm_unregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __unregister_chrdev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vfree @ 001060a0 size=1
// signature: undefined vfree(void)
// callers: [stm_register_device, stm_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_no_callbacks @ 001060a8 size=1
// signature: undefined pm_runtime_no_callbacks(void)
// callers: [stm_register_device, stm_source_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_no_callbacks(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_use_autosuspend @ 001060b0 size=1
// signature: undefined __pm_runtime_use_autosuspend(void)
// callers: [stm_register_device, stm_unregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_use_autosuspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_set_autosuspend_delay @ 001060b8 size=1
// signature: undefined pm_runtime_set_autosuspend_delay(void)
// callers: [stm_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_set_autosuspend_delay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_set_status @ 001060c0 size=1
// signature: undefined __pm_runtime_set_status(void)
// callers: [stm_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_set_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_enable @ 001060c8 size=1
// signature: undefined pm_runtime_enable(void)
// callers: [stm_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_disable @ 001060d0 size=1
// signature: undefined __pm_runtime_disable(void)
// callers: [stm_unregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_disable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// synchronize_srcu @ 001060d8 size=1
// signature: undefined synchronize_srcu(void)
// callers: [stm_unregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void synchronize_srcu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 001060e0 size=1
// signature: undefined device_unregister(void)
// callers: [stm_unregister_device, stm_source_unregister_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 001060e8 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [__stm_source_link_drop, stm_assign_first_policy, stm_source_link_store, stm_output_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get_mono_fast_ns @ 001060f0 size=1
// signature: undefined ktime_get_mono_fast_ns(void)
// callers: [__stm_source_link_drop, stm_char_write, stm_mmap_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get_mono_fast_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_suspend @ 001060f8 size=1
// signature: undefined __pm_runtime_suspend(void)
// callers: [__stm_source_link_drop, stm_char_write, stm_source_link_store, stm_mmap_close]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_suspend(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00106100 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [__stm_source_link_drop, stm_assign_first_policy, stm_source_link_store, stm_output_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pm_runtime_forbid @ 00106108 size=1
// signature: undefined pm_runtime_forbid(void)
// callers: [stm_source_register_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pm_runtime_forbid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __srcu_read_lock @ 00106110 size=1
// signature: undefined __srcu_read_lock(void)
// callers: [stm_source_link_store, stm_source_write, stm_source_unregister_device, stm_source_link_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __srcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __srcu_read_unlock @ 00106118 size=1
// signature: undefined __srcu_read_unlock(void)
// callers: [stm_source_link_store, stm_source_write, stm_source_unregister_device, stm_source_link_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __srcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_register @ 00106120 size=1
// signature: undefined __class_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_unregister @ 00106128 size=1
// signature: undefined class_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_srcu_struct @ 00106130 size=1
// signature: undefined init_srcu_struct(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_srcu_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cleanup_srcu_struct @ 00106138 size=1
// signature: undefined cleanup_srcu_struct(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cleanup_srcu_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00106140 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [hw_override_show, stp_policy_protocol_show, channels_show, stp_policy_node_masters_show, masters_show, stp_policy_node_channels_show, stp_policy_device_show, stm_source_link_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00106148 size=1
// signature: undefined __kmalloc(void)
// callers: [stm_char_write, stm_assign_first_policy, stp_policy_node_make, stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __check_object_size @ 00106150 size=1
// signature: undefined __check_object_size(void)
// callers: [stm_char_write, stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __check_object_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00106168 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [stm_char_write, stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00106170 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [stm_char_write, stm_char_mmap, stm_mmap_open, stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __get_task_comm @ 00106178 size=1
// signature: undefined __get_task_comm(void)
// callers: [stm_char_write]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __get_task_comm(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00106180 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [stm_char_write, stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106188 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [stp_policy_node_channels_store, stm_char_open, stp_policy_make, stm_char_write, stm_assign_first_policy, stm_char_policy_get_ioctl, stm_source_link_store, stp_policy_node_lookup, stp_policy_node_masters_store, stm_char_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// down_write @ 00106198 size=1
// signature: undefined down_write(void)
// callers: [stm_char_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void down_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// up_write @ 001061a0 size=1
// signature: undefined up_write(void)
// callers: [stm_char_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void up_write(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vm_iomap_memory @ 001061a8 size=1
// signature: undefined vm_iomap_memory(void)
// callers: [stm_char_mmap]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vm_iomap_memory(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nonseekable_open @ 001061b0 size=1
// signature: undefined nonseekable_open(void)
// callers: [stm_char_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nonseekable_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_zero_bit @ 001061b8 size=1
// signature: undefined _find_next_zero_bit(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_zero_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_allocate_region @ 001061c0 size=1
// signature: undefined bitmap_allocate_region(void)
// callers: [stm_assign_first_policy]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_allocate_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_to_user @ 001061c8 size=1
// signature: undefined __arch_copy_to_user(void)
// callers: [stm_char_policy_get_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_to_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_release_region @ 001061d0 size=1
// signature: undefined bitmap_release_region(void)
// callers: [stm_output_free]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_release_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrdup @ 001061d8 size=1
// signature: undefined kstrdup(void)
// callers: [stm_source_link_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmemdup @ 001061e8 size=1
// signature: undefined kmemdup(void)
// callers: [get_policy_node_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmemdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memcat_p @ 001061f0 size=1
// signature: undefined __memcat_p(void)
// callers: [get_policy_node_type]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memcat_p(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 001061f8 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [stp_policy_node_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_item_get @ 00106200 size=1
// signature: undefined config_item_get(void)
// callers: [stp_policy_node_lookup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_item_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_item_put @ 00106208 size=1
// signature: undefined config_item_put(void)
// callers: [stp_policy_node_put, stp_policy_node_drop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_item_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init @ 00106210 size=1
// signature: undefined config_group_init(void)
// callers: [stp_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_register_subsystem @ 00106218 size=1
// signature: undefined configfs_register_subsystem(void)
// callers: [stp_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_register_subsystem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_unregister_subsystem @ 00106220 size=1
// signature: undefined configfs_unregister_subsystem(void)
// callers: [stp_configfs_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_unregister_subsystem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00106228 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [stp_policy_node_channels_store, stp_policy_node_masters_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 00106230 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [stp_policy_make, stp_policy_node_make]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kasprintf @ 00106238 size=1
// signature: undefined kasprintf(void)
// callers: [stp_policy_make]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strrchr @ 00106240 size=1
// signature: char * strrchr(char * __s, int __c)
// callers: [stp_policy_make]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strrchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



