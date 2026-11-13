// Decompiled by Ghidra 12.2
// Program: gh_rm_booster.ko
// Image base: 00100000

//------------------------------------------------------------
// rm_boost_target_cpu_set @ 001001b4 size=164
// signature: undefined rm_boost_target_cpu_set(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void rm_boost_target_cpu_set(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 0;
  uVar4 = kstrtouint(param_1,10,&local_3c);
  uVar2 = local_3c;
  if ((int)uVar4 == 0) {
    uVar3 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
    if (uVar2 < uVar3) {
      uVar4 = param_set_int(param_1,param_2);
    }
    else {
      uVar4 = 0xffffffea;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// gh_rm_booster_probe @ 0010025c size=592
// signature: undefined gh_rm_booster_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int gh_rm_booster_probe(long param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  ulong uVar8;
  char *pcVar9;
  ulong uVar10;
  long lVar11;
  undefined8 uVar12;
  uint local_4c;
  long local_48;
  
  lVar11 = sp_el0;
  local_48 = *(long *)(lVar11 + 0x638);
  uVar12 = *(undefined8 *)(param_1 + 0x2f8);
  rm_status = (undefined4 *)kmalloc_trace(_gh_rm_register_notifier,0xdc0,0x100);
  if (rm_status == (undefined4 *)0x0) {
    iVar6 = -0xc;
  }
  else {
    iVar6 = of_property_read_variable_u32_array(uVar12,"qcom,rm-vmid",rm_status + 1,1,0);
    if (iVar6 < 0) {
      pcVar9 = "Failed to get RM vmid\n";
    }
    else {
      iVar6 = of_property_read_variable_u32_array
                        (uVar12,"qcom,rm-affinity-default",rm_status + 2,1,0);
      puVar5 = rm_status;
      if (iVar6 < 0) {
        pcVar9 = "Failed to get RM affinity\n";
      }
      else {
        puVar1 = rm_status + 0x1e;
        puVar2 = rm_status + 0x28;
        *(long *)(rm_status + 4) = param_1 + 0x10;
        *(undefined4 **)(param_1 + 0xa8) = puVar5;
        *(undefined8 *)(puVar5 + 0x1c) = 0xfffffffe0;
        *(undefined4 **)(puVar5 + 0x1e) = puVar1;
        *(undefined4 **)(puVar5 + 0x20) = puVar1;
        *(code **)(puVar5 + 0x22) = gh_rm_booster_release_func;
        init_timer_key(puVar2,&delayed_work_timer_fn,0x200000,0,0);
        uVar4 = target_cpu;
        uVar7 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
        if (uVar7 <= uVar4) {
          iVar6 = __bitmap_weight(&__cpu_possible_mask,_nr_cpu_ids);
          target_cpu = iVar6 - 1;
        }
        puVar5 = rm_status;
        uVar3 = rm_status[1];
        *rm_status = 0;
        *(undefined8 *)(puVar5 + 0x3e) = 0xffffffffffffffff;
        local_4c = 0;
        uVar8 = gh_rm_vm_get_hyp_res(uVar3,&local_4c);
        if ((uVar8 == 0) || (0xfffffffffffff000 < uVar8)) {
          _dev_err(*(undefined8 *)(rm_status + 4),"Get hyp resources failed.\n");
        }
        else {
          uVar10 = (ulong)local_4c;
          if (local_4c != 0) {
            lVar11 = uVar8 + 0x10;
            do {
              if (*(char *)(lVar11 + -0x10) == '\x04') {
                *(undefined8 *)(rm_status + 0x3e) = *(undefined8 *)(lVar11 + -4);
                goto LAB_001003f0;
              }
              lVar11 = lVar11 + 0x2c;
              uVar10 = uVar10 - 1;
            } while (uVar10 != 0);
          }
          _dev_err(*(undefined8 *)(rm_status + 4),"No vCPU resource type found.\n");
LAB_001003f0:
          kfree(uVar8);
        }
        puVar5 = rm_status;
        *(code **)(rm_status + 0x16) = gh_rm_boost_nb_handler;
        puVar5[0x1a] = 0x7fffffff;
        iVar6 = gh_rm_register_notifier();
        if (iVar6 == 0) goto LAB_0010045c;
        pcVar9 = "Failed to register RM notifier\n";
      }
    }
    _dev_err(param_1 + 0x10,pcVar9);
    kfree(rm_status);
  }
LAB_0010045c:
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// gh_rm_booster_remove @ 001004b0 size=116
// signature: undefined gh_rm_booster_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gh_rm_booster_remove(void)

{
  gh_rm_unregister_notifier(rm_status + 0x16);
  cancel_delayed_work_sync(rm_status + 0x1c);
  mutex_lock(rm_booster_lock);
  if (*rm_status != 0) {
    gh_resume_rm_status();
  }
  kfree(rm_status);
  rm_status = (int *)0x0;
  mutex_unlock(rm_booster_lock);
  return 0;
}



//------------------------------------------------------------
// gh_rm_booster_release_func @ 00100528 size=88
// signature: undefined gh_rm_booster_release_func(void)
// callers: []
//------------------------------------------------------------

void gh_rm_booster_release_func(void)

{
  mutex_lock(rm_booster_lock);
  if ((rm_status != (int *)0x0) && (*rm_status != 0)) {
    gh_resume_rm_status();
    *rm_status = 0;
  }
  mutex_unlock(rm_booster_lock);
  return;
}



//------------------------------------------------------------
// gh_rm_boost_nb_handler @ 00100584 size=516
// signature: undefined gh_rm_boost_nb_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gh_rm_boost_nb_handler(undefined8 param_1,long param_2,long param_3)

{
  char cVar1;
  int iVar2;
  long extraout_x1;
  long lVar3;
  char *pcVar4;
  long extraout_x1_00;
  uint *puVar5;
  long lVar6;
  uint uVar7;
  
  lVar6 = sp_el0;
  lVar6 = *(long *)(lVar6 + 0x638);
  if (param_2 != 0x56100008) goto LAB_001006e4;
  cVar1 = *(char *)(param_3 + 4);
  if ((cVar1 == '\x03') || (cVar1 == '\b')) {
    mutex_lock(rm_booster_lock);
    if ((*rm_status != 0) && (uVar7 = *rm_status - 1, *rm_status = uVar7, uVar7 == 0)) {
      gh_resume_rm_status();
      mutex_unlock(rm_booster_lock);
      cancel_delayed_work_sync(rm_status + 0x1c);
      goto LAB_001006e4;
    }
  }
  else {
    if (cVar1 != '\x06') goto LAB_001006e4;
    cancel_delayed_work_sync(rm_status + 0x1c);
    mutex_lock(rm_booster_lock);
    puVar5 = rm_status + 0x1c;
    *rm_status = *rm_status + 1;
    queue_delayed_work_on(0x20,_system_wq,puVar5,0x4e2);
    if (*rm_status < 2) {
      lVar3 = extraout_x1;
      uVar7 = target_cpu;
      if (target_cpu != rm_status[2]) {
        if (*(long *)(rm_status + 0x3e) == -1) {
          uVar7 = rm_status[2];
        }
        else {
          lVar3 = (long)(int)target_cpu;
          CallHyperVisor(0x603d);
          if ((int)*(long *)(rm_status + 0x3e) == 0) goto LAB_00100678;
          _dev_err(*(undefined8 *)(rm_status + 4),"gh set RM affinity fail\n",0xffffffffffffffff,0,0
                   ,0,0,0,0);
          uVar7 = rm_status[2];
        }
        _dev_info(*(undefined8 *)(rm_status + 4),
                  "Fallback to boost the frequency of RM current cpu - CPU%d\n",uVar7);
        lVar3 = extraout_x1_00;
      }
LAB_00100678:
      lVar3 = cpufreq_cpu_get(uVar7,lVar3);
      if (lVar3 == 0) {
        pcVar4 = "Failed to get RM cpufreq policy\n";
      }
      else {
        iVar2 = freq_qos_add_request(lVar3 + 0xa0,rm_status + 6,1,*(undefined4 *)(lVar3 + 0x38));
        if (-1 < iVar2) goto LAB_001006d8;
        pcVar4 = "Failed to boost RM freq\n";
      }
      _dev_err(*(undefined8 *)(rm_status + 4),pcVar4);
    }
  }
LAB_001006d8:
  mutex_unlock(rm_booster_lock);
LAB_001006e4:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != lVar6) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// gh_resume_rm_status @ 00100788 size=236
// signature: undefined gh_resume_rm_status(void)
// callers: [gh_rm_booster_remove, gh_rm_boost_nb_handler, gh_rm_booster_release_func]
//------------------------------------------------------------

void gh_resume_rm_status(void)

{
  int iVar1;
  long lVar2;
  undefined8 extraout_x1;
  undefined8 uVar3;
  undefined8 extraout_x1_00;
  long lVar4;
  undefined1 auVar5 [16];
  
  lVar4 = sp_el0;
  lVar4 = *(long *)(lVar4 + 0x638);
  iVar1 = freq_qos_remove_request(rm_status + 0x18);
  uVar3 = extraout_x1;
  if (iVar1 < 0) {
    _dev_err(*(undefined8 *)(rm_status + 0x10),"Failed to resume RM freq\n");
    uVar3 = extraout_x1_00;
  }
  lVar2 = *(long *)(rm_status + 0xf8);
  auVar5._8_8_ = uVar3;
  auVar5._0_8_ = lVar2;
  if (lVar2 != -1) {
    auVar5._8_8_ = (long)*(int *)(rm_status + 8);
    CallHyperVisor(0x603d);
    if ((int)lVar2 != 0) {
      _dev_err(*(undefined8 *)(rm_status + 0x10),"gh set RM affinity fail\n",0xffffffffffffffff,0,0,
               0,0,0,0);
      auVar5 = _dev_err(*(undefined8 *)(rm_status + 0x10),"Failed to resume RM affinity\n");
    }
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != lVar4) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(auVar5._0_8_,auVar5._8_8_);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00100878 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gh_rm_booster_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 001008a8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gh_rm_booster_driver);
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
// kstrtouint @ 00102010 size=1
// signature: undefined kstrtouint(void)
// callers: [rm_boost_target_cpu_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00102028 size=1
// signature: undefined __bitmap_weight(void)
// callers: [rm_boost_target_cpu_set, gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// param_set_int @ 00102030 size=1
// signature: undefined param_set_int(void)
// callers: [rm_boost_target_cpu_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void param_set_int(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102038 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gh_resume_rm_status, gh_rm_boost_nb_handler, rm_boost_target_cpu_set, gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00102048 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00102050 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00102060 size=1
// signature: undefined init_timer_key(void)
// callers: [gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_vm_get_hyp_res @ 00102068 size=1
// signature: undefined gh_rm_vm_get_hyp_res(void)
// callers: [gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_vm_get_hyp_res(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102070 size=1
// signature: undefined _dev_err(void)
// callers: [gh_resume_rm_status, gh_rm_boost_nb_handler, gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00102078 size=1
// signature: undefined kfree(void)
// callers: [gh_rm_booster_remove, gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_register_notifier @ 00102080 size=1
// signature: undefined gh_rm_register_notifier(void)
// callers: [gh_rm_booster_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// gh_rm_unregister_notifier @ 00102088 size=1
// signature: undefined gh_rm_unregister_notifier(void)
// callers: [gh_rm_booster_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void gh_rm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00102090 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [gh_rm_booster_remove, gh_rm_boost_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00102098 size=1
// signature: undefined mutex_lock(void)
// callers: [gh_rm_booster_remove, gh_rm_boost_nb_handler, gh_rm_booster_release_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001020a0 size=1
// signature: undefined mutex_unlock(void)
// callers: [gh_rm_booster_remove, gh_rm_boost_nb_handler, gh_rm_booster_release_func]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 001020b0 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [gh_rm_boost_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 001020b8 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [gh_rm_boost_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 001020c0 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [gh_rm_boost_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001020c8 size=1
// signature: undefined _dev_info(void)
// callers: [gh_rm_boost_nb_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_remove_request @ 001020d0 size=1
// signature: undefined freq_qos_remove_request(void)
// callers: [gh_resume_rm_status]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



