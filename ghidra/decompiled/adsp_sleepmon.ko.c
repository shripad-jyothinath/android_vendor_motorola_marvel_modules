// Decompiled by Ghidra 12.2
// Program: adsp_sleepmon.ko
// Image base: 00100000

//------------------------------------------------------------
// adsp_sleepmon_log_master_stats @ 00100804 size=852
// signature: undefined adsp_sleepmon_log_master_stats(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adsp_sleepmon_log_master_stats(uint param_1)

{
  code *pcVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  
  if ((param_1 & 7) == 0) {
    _printk(&DAT_001046dd);
    uVar3 = 0xffffffea;
  }
  else {
    if ((param_1 & 1) != 0) {
      if (DAT_001055e8 == (undefined4 *)0x0) {
        _printk(&DAT_00104017);
      }
      else {
        _printk(&DAT_0010413e);
        _printk(&DAT_00104888,*DAT_001055e8);
        _printk(&DAT_001045a6,*(undefined8 *)(DAT_001055e8 + 1));
        _printk(&DAT_00104206,*(undefined8 *)(DAT_001055e8 + 3));
        iVar2 = DAT_001055e8[5];
        if (iVar2 == 0) {
          iVar2 = -1;
        }
        _printk(&DAT_00104160,iVar2);
        _printk(&DAT_00104b46,*(undefined8 *)(DAT_001055e8 + 6));
      }
    }
    if ((param_1 >> 1 & 1) != 0) {
      if (DAT_001055e0 == (undefined4 *)0x0) {
        _printk(&DAT_0010418a);
      }
      else {
        _printk(&DAT_00104b68);
        _printk(&DAT_0010451d,*DAT_001055e0);
        iVar2 = DAT_001055e0[1];
        if (iVar2 == 0) {
          iVar2 = -1;
        }
        _printk(&DAT_00104160,iVar2);
        _printk(&DAT_00104b46,DAT_001055e0[2]);
        _printk(&DAT_001053ce,DAT_001055e0[3],DAT_001055e0[4]);
        _printk(&DAT_001053ce,DAT_001055e0[5],DAT_001055e0[6]);
        _printk(&DAT_001053ce,DAT_001055e0[7],DAT_001055e0[8]);
        _printk(&DAT_001053ce,DAT_001055e0[9],DAT_001055e0[10]);
        _printk(&DAT_001053ce,DAT_001055e0[0xb],DAT_001055e0[0xc]);
        if ((DAT_00105488 != 0) && (iVar2 = sleepmon_get_dsppm_client_stats(), iVar2 == 0)) {
          wait_for_completion(&DAT_00105468);
          print_complete_dsppm_info();
        }
      }
    }
    if ((param_1 >> 2 & 1) != 0) {
      if (DAT_001055d0 == 0) {
        _printk(&DAT_00104795);
      }
      else {
        lVar5 = *(long *)(DAT_001055d0 + 0x18);
        if (*(ulong *)(DAT_001055d0 + 0x10) < *(ulong *)(DAT_001055d0 + 8)) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100a30);
            (*pcVar1)();
          }
          lVar4 = (*_arch_timer_read_counter)();
          lVar5 = (lVar4 + lVar5) - *(long *)(DAT_001055d0 + 8);
        }
        _printk(&DAT_0010422d);
        _printk(&DAT_00104a37,*(undefined4 *)(DAT_001055d0 + 4));
        _printk(&DAT_00104d3f,*(undefined8 *)(DAT_001055d0 + 8));
        _printk(&DAT_001048de,*(undefined8 *)(DAT_001055d0 + 0x10));
        _printk(&DAT_00104906,lVar5);
      }
      if (DAT_001055d8 == 0) {
        _printk(&DAT_00104b89);
      }
      else {
        lVar5 = *(long *)(DAT_001055d8 + 0x18);
        if (*(ulong *)(DAT_001055d8 + 0x10) < *(ulong *)(DAT_001055d8 + 8)) {
          if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100ae8);
            (*pcVar1)();
          }
          lVar4 = (*_arch_timer_read_counter)();
          lVar5 = (lVar4 + lVar5) - *(long *)(DAT_001055d8 + 8);
        }
        _printk(&DAT_001050a9);
        _printk(&DAT_00104a37,*(undefined4 *)(DAT_001055d8 + 4));
        _printk(&DAT_00104d3f,*(undefined8 *)(DAT_001055d8 + 8));
        _printk(&DAT_001048de,*(undefined8 *)(DAT_001055d8 + 0x10));
        _printk(&DAT_00104906,lVar5);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// sleepmon_get_dsppm_client_stats @ 00100b58 size=172
// signature: undefined sleepmon_get_dsppm_client_stats(void)
// callers: [adsp_sleepmon_log_master_stats]
//------------------------------------------------------------

int sleepmon_get_dsppm_client_stats(void)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  iVar2 = -0x16;
  if ((DAT_00105490 != 0) && (DAT_00105488 != 0)) {
    local_38 = 0x200000010;
    uStack_30 = 0x100000002;
    iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105490 + 0x3c8),&local_38,0x10);
    if (iVar2 != 0) {
      _printk(&DAT_00104466,iVar2);
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
// print_complete_dsppm_info @ 00100c04 size=396
// signature: undefined print_complete_dsppm_info(void)
// callers: [sleepmon_get_dsppm_clients, adsp_sleepmon_log_master_stats, master_stats_show]
//------------------------------------------------------------

void print_complete_dsppm_info(void)

{
  code *pcVar1;
  ulong uVar2;
  long lVar3;
  undefined4 uVar4;
  
  if (DAT_00105ee0 == '\x03') {
    _printk(&DAT_001045cd);
  }
  else if (DAT_00105ee0 == '\x02') {
    _printk(&DAT_00105153);
  }
  else if (DAT_00105ee0 == '\x01') {
    uVar4 = DAT_00105ec0;
    _printk(&DAT_001050c8,DAT_001055f8,DAT_00105ee4,DAT_00105e80,DAT_00105e84,DAT_00105e88,
            DAT_00105e8c,DAT_00105e90,DAT_00105e98,DAT_00105ea0,DAT_00105ea8,DAT_00105eb0,
            DAT_00105eb4,DAT_00105eb8,DAT_00105ebc,DAT_00105ec0);
    if (DAT_00105ee4 != 0) {
      lVar3 = 0;
      uVar2 = 0;
      do {
        if (lVar3 == 0x880) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100d90);
          (*pcVar1)();
        }
        _printk(&DAT_0010404e,uVar2 & 0xffffffff,&DAT_00105600 + lVar3,
                *(undefined4 *)((long)&DAT_00105618 + lVar3),
                *(undefined8 *)((long)&DAT_00105620 + lVar3),
                *(undefined4 *)((long)&DAT_00105630 + lVar3),
                *(undefined4 *)((long)&DAT_00105634 + lVar3),
                *(undefined4 *)((long)&DAT_00105638 + lVar3),
                *(undefined4 *)((long)&DAT_0010563c + lVar3),
                *(undefined8 *)((long)&DAT_00105640 + lVar3),
                *(undefined4 *)((long)&DAT_00105648 + lVar3),
                *(undefined4 *)((long)&DAT_00105650 + lVar3),
                *(undefined4 *)((long)&DAT_0010562c + lVar3),&DAT_00105654 + lVar3,
                *(undefined4 *)((long)&DAT_00105668 + lVar3),uVar4);
        uVar2 = uVar2 + 1;
        lVar3 = lVar3 + 0x88;
      } while (uVar2 < DAT_00105ee4);
    }
  }
  else {
    _printk(&DAT_00105316);
  }
  return;
}



//------------------------------------------------------------
// adspsleepmon_driver_probe @ 00100d94 size=1380
// signature: undefined adspsleepmon_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int adspsleepmon_driver_probe(long param_1)

{
  int iVar1;
  ulong uVar2;
  long lVar3;
  
  __mutex_init(&DAT_00105498,"&g_adspsleepmon.lock",&adspsleepmon_driver_probe___key);
  _DAT_00105448 = 0xf00000005;
  _DAT_00105450 = 0x50000003c;
  _DAT_00105440 = 0;
  uVar2 = kthread_create_on_node(adspsleepmon_worker,0,0xffffffff,"adspsleepmon-worker");
  if (uVar2 < 0xfffffffffffff001) {
    wake_up_process(uVar2);
  }
  DAT_00105568 = uVar2;
  if (uVar2 == 0) {
    _dev_err(param_1 + 0x10,"Failed to create kernel thread\n");
    iVar1 = -0xc;
  }
  else {
    DAT_00105578 = 0;
    iVar1 = alloc_chrdev_region(&DAT_00105558,0,1,"msm_adsp_sleepmon");
    if (iVar1 == 0) {
      cdev_init(&DAT_001054c8,fops);
      DAT_00105528 = &__this_module;
      iVar1 = cdev_add(&DAT_001054c8,DAT_00105558 & 0xfff00000,1);
      if (iVar1 == 0) {
        DAT_00105550 = __class_create(&__this_module,"adspsleepmon",
                                      &adspsleepmon_driver_probe___key_33);
        if (DAT_00105550 < 0xfffffffffffff001) {
          DAT_00105560 = device_create(DAT_00105550,0,DAT_00105558 & 0xfff00000,0,
                                       "msm_adsp_sleepmon");
          if ((DAT_00105560 == 0) || (0xfffffffffffff000 < DAT_00105560)) {
            _dev_err(param_1 + 0x10,"Failed to create a device\n");
          }
          else {
            DAT_00105f10 = debugfs_create_dir("adspsleepmon",0);
            if (DAT_00105f10 != 0) {
              lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,enable_panic_lpm",0);
              _DAT_00105440 = CONCAT11(DAT_00105441,lVar3 != 0);
              lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,enable_panic_lpi",0);
              _DAT_00105440 = CONCAT11(lVar3 != 0,DAT_00105440);
              lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,enable_adsp_panic_lpm"
                                       ,0);
              DAT_00105442 = lVar3 != 0;
              lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,enable_adsp_panic_lpi"
                                       ,0);
              DAT_00105443 = lVar3 != 0;
              lVar3 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),
                                       "qcom,enable_adsp_panic_lpm_overall",0);
              DAT_00105444 = lVar3 != 0;
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,wait_time_lpm",&DAT_00105448,1,0);
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,wait_time_lpi",&DAT_0010544c,1,0);
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,wait_time_lpm_overall",&DAT_00105450
                         ,1,0);
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,min_required_resumes",&DAT_00105454,
                         1,0);
              of_property_read_variable_u32_array
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,rproc-handle",&DAT_00105f40,1,0);
              if ((DAT_00105f40 != 0) &&
                 (((DAT_00105442 != '\0' || (DAT_00105443 != '\0')) || (DAT_00105444 != '\0')))) {
                DAT_00105445 = 1;
                _dev_info(param_1 + 0x10,"ADSP SSR config enabled\n");
              }
              DAT_0010543e = DAT_00105440;
              DAT_0010543f = DAT_00105441;
              if ((DAT_00105441 != '\0' || DAT_00105440 != '\0') &&
                 (DAT_00105f18 = debugfs_create_file("panic-state",0x1a4,DAT_00105f10,0,
                                                     &panic_state_fops), DAT_00105f18 == 0)) {
                _dev_err(param_1 + 0x10,"Unable to create file in debugfs\n");
              }
              DAT_00105f28 = debugfs_create_file("read_panic_state",0x124,DAT_00105f10,0,
                                                 &read_panic_state_fops);
              if (DAT_00105f28 == 0) {
                _dev_err(param_1 + 0x10,"Unable to create read panic state file in debugfs\n");
              }
              DAT_00105f20 = debugfs_create_file("master_stats",0x124,DAT_00105f10,0,
                                                 &master_stats_fops);
              if (DAT_00105f20 == 0) {
                _dev_err(param_1 + 0x10,"Failed to create debugfs file for master stats\n");
              }
              DAT_00105f30 = debugfs_create_file("adsp_panic_state",0x1a4,DAT_00105f10,0,
                                                 &adsp_panic_state_fops);
              if (DAT_00105f30 == 0) {
                _dev_err(param_1 + 0x10,"Unable to create ADSP panic state file in debugfs\n");
              }
              DAT_00105f38 = debugfs_create_file("read_adsp_panic_state",0x124,DAT_00105f10,0,
                                                 &read_adsp_panic_state_fops);
              if (DAT_00105f38 == 0) {
                _dev_err(param_1 + 0x10,"Unable to create ADSP panic state read file in debugfs\n");
              }
              iVar1 = __register_rpmsg_driver(&sleepmon_rpmsg_client,&__this_module);
              if (iVar1 == 0) {
                DAT_00105446 = 1;
                DAT_00105468 = 0;
                __init_swait_queue_head(&DAT_00105470,"&x->wait",&init_completion___key);
                _dev_info(param_1 + 0x10,"ADSP sleep monitor probe called\n");
                return 0;
              }
              _dev_err(param_1 + 0x10,"Failed registering rpmsg driver with return %d\n",iVar1);
              return iVar1;
            }
            _dev_err(param_1 + 0x10,"Failed to create debugfs directory for adspsleepmon\n");
            device_destroy(DAT_00105550,DAT_00105548);
          }
          class_destroy(DAT_00105550);
        }
        else {
          _dev_err(param_1 + 0x10,"Failed to create a class\n");
        }
        cdev_del(&DAT_001054c8);
      }
      else {
        _dev_err(param_1 + 0x10,"Failed to add cdev\n");
      }
      unregister_chrdev_region(DAT_00105558,1);
    }
    else {
      _dev_err(param_1 + 0x10,"Failed to allocate char device region\n");
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// adspsleepmon_driver_remove @ 001012fc size=188
// signature: undefined adspsleepmon_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 adspsleepmon_driver_remove(long param_1)

{
  device_destroy(DAT_00105550,DAT_00105548);
  class_destroy(DAT_00105550);
  cdev_del(&DAT_001054c8);
  unregister_chrdev_region(DAT_00105558,1);
  debugfs_remove(DAT_00105f10);
  unregister_pm_notifier(&adsp_sleepmon_pm_nb);
  if (DAT_00105446 != '\0') {
    unregister_rpmsg_driver(&sleepmon_rpmsg_client);
    DAT_00105490 = 0;
    DAT_00105488 = 0;
  }
  _dev_info(param_1 + 0x10,"ADSP sleep monitor remove called\n");
  return 0;
}



//------------------------------------------------------------
// adspsleepmon_worker @ 001013bc size=1536
// signature: undefined adspsleepmon_worker(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adspsleepmon_worker(void)

{
  undefined4 uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  ulong uVar7;
  uint uVar8;
  int iVar9;
  ulong uVar10;
  long lVar11;
  undefined *puVar12;
  undefined8 local_b0;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined4 local_70;
  long local_68;
  
  lVar11 = sp_el0;
  local_68 = *(long *)(lVar11 + 0x638);
  uVar10 = kthread_should_stop();
  while ((uVar10 & 1) == 0) {
    uVar10 = kthread_should_stop();
    if ((((uVar10 & 1) == 0) && (DAT_00105439 == '\0')) && (DAT_0010543b == '\0')) {
      local_88 = 0;
      local_80 = 0;
      local_98 = 0;
      local_90 = 0;
      local_a0 = 0;
      init_wait_entry(&local_a0,0);
      while( true ) {
        lVar11 = prepare_to_wait_event(adspsleepmon_wq,&local_a0,1);
        uVar10 = kthread_should_stop();
        if ((((uVar10 & 1) != 0) || (DAT_00105439 != '\0')) || (DAT_0010543b != '\0')) break;
        if (lVar11 != 0) goto LAB_00101648;
        schedule();
      }
      finish_wait(adspsleepmon_wq,&local_a0);
      lVar11 = 0;
LAB_00101648:
      uVar10 = kthread_should_stop();
      if ((uVar10 & 1) != 0) break;
      if ((int)lVar11 == 0) goto LAB_001014f0;
    }
    else {
      uVar10 = kthread_should_stop();
      if ((uVar10 & 1) != 0) break;
LAB_001014f0:
      _printk(&DAT_00104d8a,DAT_00105439,DAT_0010543b);
      mutex_lock(&DAT_00105498);
      if (DAT_00105570 == 0) {
        InstructionSynchronizationBarrier();
        uVar7 = cntvct_el0;
        uVar10 = -DAT_001055a0;
        if (uVar7 < DAT_001055a0) {
          uVar10 = ~DAT_001055a0;
        }
        uVar10 = uVar10 + uVar7;
        if ((uint)(DAT_00105448 * 19200000) <= uVar10) {
          uVar3 = *(ulong *)(DAT_001055d0 + 2);
          uVar4 = *(ulong *)(DAT_001055d0 + 4);
          uVar1 = *DAT_001055d0;
          iVar2 = DAT_001055d0[1];
          lVar11 = *(long *)(DAT_001055d0 + 6);
          if (((iVar2 == 0) || (uVar3 < uVar4)) || ((uVar7 <= uVar3 && (uVar4 < uVar3)))) {
            local_88 = DAT_001055e0[3];
            local_80 = DAT_001055e0[4];
            local_78 = DAT_001055e0[5];
            local_70 = *(undefined4 *)(DAT_001055e0 + 6);
            local_a0 = *DAT_001055e0;
            local_98 = DAT_001055e0[1];
            local_90 = DAT_001055e0[2];
            if (lVar11 == DAT_00105598) {
              uVar5 = DAT_001055e8[5];
              uVar6 = *DAT_001055e8;
              _printk(&DAT_001044f0);
              _printk(&DAT_00104749,uVar6,uVar5);
              _printk(&DAT_00104bb7,uVar10 / 0x4b00,(ulong)(lVar11 - DAT_00105598) / 0x4b00);
              uVar8 = sleepmon_is_audio_active(&local_a0);
              sleepmon_get_dsppm_clients();
              if ((DAT_0010543e == '\0' && DAT_00105442 == '\0') || ((uVar8 & 1) == 0)) {
                DAT_00105460 = DAT_00105460 + uVar10;
                if (DAT_0010543b != '\0') {
                  DAT_00105458 = DAT_00105458 + 1;
                }
                if (((ulong)DAT_00105450 * 19200000 <= DAT_00105460) &&
                   (DAT_00105454 <= DAT_00105458)) {
                  adspsleepmon_lpm_adsp_panic_overall();
                  goto LAB_00101710;
                }
              }
              else if (DAT_00105442 == '\0') {
                if (DAT_0010543e != '\0') {
                    /* WARNING: Subroutine does not return */
                  panic("ADSP sleep issue detected");
                }
              }
              else {
                _printk(&DAT_0010480a);
                sleepmon_send_ssr_command();
              }
            }
            else {
LAB_00101710:
              DAT_00105460 = 0;
              DAT_00105458 = 0;
            }
          }
          InstructionSynchronizationBarrier();
          DAT_001055a0 = cntvct_el0;
          DAT_00105580 = uVar1;
          DAT_00105584 = iVar2;
          DAT_00105588 = uVar3;
          DAT_00105590 = uVar4;
          DAT_00105598 = lVar11;
        }
      }
      else if (DAT_00105570 == DAT_00105574) {
        InstructionSynchronizationBarrier();
        uVar7 = cntvct_el0;
        uVar10 = -DAT_001055c8;
        if (uVar7 < DAT_001055c8) {
          uVar10 = ~DAT_001055c8;
        }
        if ((ulong)(uint)(DAT_0010544c * 19200000) <= uVar10 + uVar7) {
          uVar3 = *(ulong *)(DAT_001055d8 + 2);
          uVar4 = *(ulong *)(DAT_001055d8 + 4);
          uVar1 = *DAT_001055d8;
          iVar2 = DAT_001055d8[1];
          lVar11 = *(long *)(DAT_001055d8 + 6);
          if (((iVar2 == 0) || (uVar3 < uVar4)) || ((uVar7 <= uVar3 && (uVar4 < uVar3)))) {
            local_88 = DAT_001055e0[3];
            local_80 = DAT_001055e0[4];
            local_78 = DAT_001055e0[5];
            local_70 = *(undefined4 *)(DAT_001055e0 + 6);
            local_a0 = *DAT_001055e0;
            local_98 = DAT_001055e0[1];
            local_90 = DAT_001055e0[2];
            if (lVar11 == DAT_001055c0) {
              uVar5 = DAT_001055e8[5];
              uVar6 = *DAT_001055e8;
              _printk(&DAT_0010427f);
              _printk(&DAT_00104749,uVar6,uVar5);
              _printk(&DAT_00103e47,(uVar10 + uVar7) / 0x4b00,
                      (ulong)(lVar11 - DAT_001055c0) / 0x4b00);
              sleepmon_is_audio_active(&local_a0);
              sleepmon_get_dsppm_clients();
              local_a4 = 0;
              if (DAT_00105490 == 0) {
                puVar12 = &DAT_001043f6;
              }
              else {
                puVar12 = &DAT_001043f6;
                if (1 < DAT_00105488) {
                  local_b0 = 0x200000010;
                  local_a8 = 3;
                  local_a4 = CONCAT31((uint3)(DAT_0010543f != '\0' || DAT_00105443 != '\0'),1);
                  iVar9 = rpmsg_send(*(undefined8 *)(DAT_00105490 + 0x3c8),&local_b0,0x10);
                  if (iVar9 == 0) goto LAB_001015f0;
                  puVar12 = &DAT_001043c6;
                }
              }
              _printk(puVar12);
            }
          }
LAB_001015f0:
          InstructionSynchronizationBarrier();
          DAT_001055c8 = cntvct_el0;
          DAT_001055a8._0_4_ = uVar1;
          DAT_001055a8._4_4_ = iVar2;
          DAT_001055b0 = uVar3;
          DAT_001055b8 = uVar4;
          DAT_001055c0 = lVar11;
        }
      }
      if (DAT_00105439 != '\0') {
        _DAT_00105439 = 0;
      }
      DAT_0010543b = '\0';
      mutex_unlock(&DAT_00105498);
    }
    uVar10 = kthread_should_stop();
  }
  lVar11 = sp_el0;
  if (*(long *)(lVar11 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// sleepmon_is_audio_active @ 001019bc size=300
// signature: undefined sleepmon_is_audio_active(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

bool sleepmon_is_audio_active(long param_1)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((uVar1 == 0) || (*(int *)(param_1 + 0x10) == 0)) {
    bVar2 = false;
    uVar1 = *(uint *)(param_1 + 0x14);
  }
  else {
    bVar2 = (uVar1 & 0x7f) == 2;
    _printk(&DAT_00103f3b,uVar1,bVar2);
    uVar1 = *(uint *)(param_1 + 0x14);
  }
  if ((uVar1 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    bVar3 = (uVar1 & 0x7f) == 2;
    if (bVar3) {
      bVar2 = true;
    }
    _printk(&DAT_00103f3b,uVar1,bVar3);
  }
  uVar1 = *(uint *)(param_1 + 0x1c);
  if ((uVar1 == 0) || (*(int *)(param_1 + 0x20) == 0)) {
    uVar1 = *(uint *)(param_1 + 0x24);
  }
  else {
    bVar3 = (uVar1 & 0x7f) == 2;
    if (bVar3) {
      bVar2 = true;
    }
    _printk(&DAT_00103f3b,uVar1,bVar3);
    uVar1 = *(uint *)(param_1 + 0x24);
  }
  if ((uVar1 != 0) && (*(int *)(param_1 + 0x28) != 0)) {
    bVar3 = (uVar1 & 0x7f) == 2;
    if (bVar3) {
      bVar2 = true;
    }
    _printk(&DAT_00103f3b,uVar1,bVar3);
  }
  uVar1 = *(uint *)(param_1 + 0x2c);
  if ((uVar1 != 0) && (*(int *)(param_1 + 0x30) != 0)) {
    bVar3 = (uVar1 & 0x7f) == 2;
    if (bVar3) {
      bVar2 = true;
    }
    _printk(&DAT_00103f3b,uVar1,bVar3);
  }
  return bVar2;
}



//------------------------------------------------------------
// sleepmon_get_dsppm_clients @ 00101ae8 size=228
// signature: undefined sleepmon_get_dsppm_clients(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

void sleepmon_get_dsppm_clients(void)

{
  int iVar1;
  long lVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  if (DAT_00105488 != 0) {
    if (DAT_00105490 == 0) {
      iVar1 = -0x16;
    }
    else {
      local_38 = 0x200000010;
      uStack_30 = 0x100000002;
      iVar1 = rpmsg_send(*(undefined8 *)(DAT_00105490 + 0x3c8),&local_38,0x10);
      if (iVar1 == 0) {
        lVar2 = wait_for_completion_timeout(&DAT_00105468,0x19);
        if (lVar2 == 0) {
          _printk(&DAT_001051be);
        }
        print_complete_dsppm_info();
        goto LAB_00101b60;
      }
      _printk(&DAT_00104466,iVar1);
    }
    _printk(&DAT_001051ef,iVar1);
  }
LAB_00101b60:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// adspsleepmon_lpm_adsp_panic_overall @ 00101bcc size=96
// signature: undefined adspsleepmon_lpm_adsp_panic_overall(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

void adspsleepmon_lpm_adsp_panic_overall(void)

{
  if (DAT_00105444 != '\0') {
    _printk(&DAT_00103dd5,DAT_00105460 / 0x4b00,DAT_00105458);
    sleepmon_send_ssr_command();
  }
  return;
}



//------------------------------------------------------------
// sleepmon_send_ssr_command @ 00101c2c size=308
// signature: undefined sleepmon_send_ssr_command(void)
// callers: [sleepmon_rpmsg_callback, adspsleepmon_lpm_adsp_panic_overall, adspsleepmon_worker]
//------------------------------------------------------------

void sleepmon_send_ssr_command(void)

{
  long lVar1;
  int iVar2;
  undefined8 local_38;
  undefined8 uStack_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  if ((DAT_00105490 == 0) || (DAT_00105488 < 2)) {
    _printk(&DAT_00104e6b);
  }
  else {
    if (DAT_00105445 != '\0') {
      if (DAT_00105f48 == 0) {
        _printk(&DAT_00105238);
      }
      else {
        _printk(&DAT_00104dc0);
        qcom_rproc_update_recovery_status(DAT_00105f48,1);
      }
    }
    local_38 = 0x200000010;
    uStack_30 = 0x100000004;
    iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105490 + 0x3c8),&local_38,0x10);
    if (((iVar2 != 0) && (_printk(&DAT_00105382), DAT_00105445 != '\0')) && (DAT_00105f48 != 0)) {
      _printk(&DAT_00104f73);
      qcom_rproc_update_recovery_status(DAT_00105f48,0);
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// adspsleepmon_device_ioctl @ 00101d64 size=1616
// signature: undefined adspsleepmon_device_ioctl(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long adspsleepmon_device_ioctl(long param_1,int param_2,ulong param_3)

{
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  size_t __n;
  undefined *puVar4;
  uint uVar5;
  undefined8 uVar6;
  int iVar7;
  int iVar8;
  undefined8 *puVar9;
  undefined1 *puVar10;
  long *plVar11;
  ulong uVar12;
  long lVar13;
  int iVar14;
  long *plVar15;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined4 local_40;
  undefined1 auStack_3c [4];
  long local_38;
  
  lVar13 = sp_el0;
  local_38 = *(long *)(lVar13 + 0x638);
  if (param_2 != -0x3ff7adfe) {
    if (param_2 != -0x3febadff) {
      lVar13 = -0x1900000000;
      _printk(&DAT_001041d4);
      goto LAB_00102038;
    }
    puVar9 = (undefined8 *)sp_el0;
    plVar15 = *(long **)(param_1 + 0xd8);
    local_40 = 0;
    local_50 = 0;
    uStack_48 = 0;
    if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
       (uVar12 = param_3, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
      uVar12 = param_3 & (long)(param_3 << 8) >> 8;
    }
    if (0x7fffffffec < uVar12) {
      __n = 0x14;
LAB_00102368:
      puVar10 = auStack_3c + -__n;
      goto LAB_00102198;
    }
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      puVar9 = (undefined8 *)puVar9[1];
      uVar3 = ttbr1_el1;
      ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      ttbr0_el1 = puVar9;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    __n = __arch_copy_from_user(puVar9,&local_50,param_3 & 0xff7fffffffffffff,0x14);
    if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
      uVar12 = daif;
      if ((uVar12 & 0x80) == 0) {
        uVar3 = daif;
        daif = uVar3 | 0xc0;
      }
      uVar3 = ttbr1_el1;
      ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
      InstructionSynchronizationBarrier();
      ttbr1_el1 = uVar3 & 0xffffffffffff;
      InstructionSynchronizationBarrier();
      daif = uVar12;
    }
    if (__n != 0) goto LAB_00102368;
    if (plVar15 == (long *)0x0) {
      _printk(&DAT_00104339);
      lVar13 = -0xc00000000;
      goto LAB_00102038;
    }
    if (1 < *(uint *)((long)plVar15 + 0x14)) {
      _printk(&DAT_00104568,0xc0145201);
      lVar13 = -0x2a00000000;
      goto LAB_00102038;
    }
    if ((int)local_50 == 0) {
      puVar4 = &DAT_00105400;
      lVar13 = -0x1900000000;
      uVar5 = 0;
LAB_001020d0:
      uVar1 = 0xc0145201;
      goto LAB_00102034;
    }
    if (5 < local_50._4_4_) {
      puVar4 = &DAT_00103f7c;
      lVar13 = -0x1600000000;
      uVar5 = local_50._4_4_;
      goto LAB_001020d0;
    }
    mutex_lock(&DAT_00105498);
    if (*(int *)((long)plVar15 + 0x14) == 0) {
      *plVar15 = (long)DAT_00105578;
      if (DAT_00105578 != (long *)0x0) {
        DAT_00105578[1] = (long)plVar15;
      }
      DAT_00105578 = plVar15;
      plVar15[1] = (long)&DAT_00105578;
      *(undefined4 *)((long)plVar15 + 0x14) = 1;
    }
    switch(local_50._4_4_) {
    case 2:
      goto switchD_00102144_caseD_2;
    case 3:
      *(int *)((long)plVar15 + 0x1c) = *(int *)((long)plVar15 + 0x1c) + 1;
    case 1:
      iVar7 = (int)plVar15[3] + 1;
LAB_001021d4:
      *(int *)(plVar15 + 3) = iVar7;
      break;
    case 4:
      if (*(int *)((long)plVar15 + 0x1c) == 0) {
        _printk(&DAT_0010526e);
      }
      else {
        *(int *)((long)plVar15 + 0x1c) = *(int *)((long)plVar15 + 0x1c) + -1;
      }
switchD_00102144_caseD_2:
      if ((int)plVar15[3] == 0) {
        _printk(&DAT_00104985);
        break;
      }
      iVar7 = (int)plVar15[3] + -1;
      goto LAB_001021d4;
    case 5:
      plVar15[3] = 0;
    }
    _raw_spin_lock(plVar15 + 2);
    if (DAT_00105578 == (long *)0x0) {
      iVar14 = 0;
      iVar7 = 0;
    }
    else {
      iVar7 = 0;
      iVar14 = 0;
      plVar11 = DAT_00105578;
      do {
        if (*(int *)((long)plVar11 + 0x14) != 0) {
          iVar7 = (int)plVar11[3] + iVar7;
          iVar14 = *(int *)((long)plVar11 + 0x1c) + iVar14;
        }
        plVar11 = (long *)*plVar11;
      } while (plVar11 != (long *)0x0);
    }
    _raw_spin_unlock(plVar15 + 2);
    if ((iVar7 == 0) || (iVar7 == iVar14)) {
      if (iVar7 == 0) {
        DAT_00105590 = DAT_001055d0[2];
        DAT_00105598 = DAT_001055d0[3];
        _DAT_00105580 = *DAT_001055d0;
        DAT_00105588 = DAT_001055d0[1];
        InstructionSynchronizationBarrier();
        DAT_001055a0 = cntvct_el0;
        iVar8 = DAT_00105448;
      }
      else {
        DAT_001055a8 = *DAT_001055d8;
        DAT_001055b0 = DAT_001055d8[1];
        DAT_001055b8 = DAT_001055d8[2];
        DAT_001055c0 = DAT_001055d8[3];
        InstructionSynchronizationBarrier();
        DAT_001055c8 = cntvct_el0;
        DAT_00105460 = 0;
        DAT_00105458 = 0;
        iVar8 = DAT_0010544c;
      }
      mod_timer(adspsleep_timer,_jiffies + (ulong)(uint)(iVar8 * 0xfa));
      uVar6 = 1;
      DAT_0010543a = '\x01';
    }
    else if (DAT_0010543a == '\0') {
      uVar6 = 0;
    }
    else {
      del_timer(adspsleep_timer);
      uVar6 = 0;
      DAT_0010543a = '\0';
      DAT_00105460 = 0;
      DAT_00105458 = 0;
    }
    DAT_00105570 = iVar7;
    DAT_00105574 = iVar14;
    _printk(&DAT_00104ece,iVar7,iVar14,uVar6);
    mutex_unlock(&DAT_00105498);
    lVar13 = 0;
    goto LAB_00102038;
  }
  puVar9 = (undefined8 *)sp_el0;
  local_50 = 0;
  if (((*(byte *)((long)puVar9 + 0x46) >> 5 & 1) != 0) ||
     (uVar12 = param_3, ((uint)*puVar9 >> 0x1a & 1) != 0)) {
    uVar12 = param_3 & (long)(param_3 << 8) >> 8;
  }
  if (0x7ffffffff8 < uVar12) {
    __n = 8;
LAB_00102184:
    puVar10 = auStack_3c + (-0xc - __n);
LAB_00102198:
    lVar13 = -0x1900000000;
    memset(puVar10,0,__n);
    _printk(&DAT_00104ea0);
    goto LAB_00102038;
  }
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar12 = daif;
    if ((uVar12 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    puVar9 = (undefined8 *)puVar9[1];
    uVar3 = ttbr1_el1;
    ttbr1_el1 = (ulong)puVar9 & 0xffff000000000000 | uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    ttbr0_el1 = puVar9;
    InstructionSynchronizationBarrier();
    daif = uVar12;
  }
  __n = __arch_copy_from_user(puVar9,&local_50,param_3 & 0xff7fffffffffffff,8);
  if (((uint)_cpu_hwcaps >> 0x1d & 1) == 0) {
    uVar12 = daif;
    if ((uVar12 & 0x80) == 0) {
      uVar3 = daif;
      daif = uVar3 | 0xc0;
    }
    uVar3 = ttbr1_el1;
    ttbr0_el1 = (uVar3 & 0xffffffffffff) - 0x1000;
    InstructionSynchronizationBarrier();
    ttbr1_el1 = uVar3 & 0xffffffffffff;
    InstructionSynchronizationBarrier();
    daif = uVar12;
  }
  if (__n != 0) goto LAB_00102184;
  if ((int)local_50 == 0) {
    puVar4 = &DAT_00105400;
    lVar13 = -0x1900000000;
    uVar5 = 0;
LAB_0010202c:
    uVar1 = 0xc0085202;
LAB_00102034:
    _printk(puVar4,uVar5,uVar1);
    goto LAB_00102038;
  }
  if (4 < local_50._4_4_) {
    puVar4 = &DAT_00103f7c;
    lVar13 = -0x1600000000;
    uVar5 = local_50._4_4_;
    goto LAB_0010202c;
  }
  switch(local_50._4_4_) {
  case 1:
    lVar13 = 0;
    DAT_0010543e = 0;
    break;
  case 2:
    lVar13 = 0;
    DAT_0010543f = 0;
    break;
  case 3:
    puVar10 = &DAT_0010543e;
    goto LAB_00101ec0;
  case 4:
    puVar10 = &DAT_0010543f;
LAB_00101ec0:
    lVar13 = 0;
    *puVar10 = puVar10[2];
    break;
  default:
    lVar13 = 0;
  }
LAB_00102038:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar13 >> 0x20;
}



//------------------------------------------------------------
// adspsleepmon_device_open @ 001023e8 size=124
// signature: undefined adspsleepmon_device_open(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adspsleepmon_device_open(undefined8 param_1,long param_2)

{
  undefined8 *puVar1;
  undefined8 uVar2;
  
  if ((DAT_0010543c == '\0') && (adspsleepmon_smem_init(), DAT_0010543c == '\0')) {
    uVar2 = 0xffffffed;
  }
  else {
    puVar1 = (undefined8 *)kmalloc_trace(_simple_attr_open,0xdc0,0x20);
    uVar2 = 0xfffffff4;
    if ((puVar1 != (undefined8 *)0x0) && (puVar1 < (undefined8 *)0xfffffffffffff001)) {
      uVar2 = 0;
      puVar1[2] = 0;
      puVar1[3] = 0;
      *puVar1 = 0;
      puVar1[1] = 0;
      *(undefined8 **)(param_2 + 0xd8) = puVar1;
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// adspsleepmon_device_release @ 00102468 size=524
// signature: undefined adspsleepmon_device_release(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 adspsleepmon_device_release(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  int iVar2;
  long *plVar3;
  long lVar4;
  long *plVar5;
  int iVar6;
  int iVar7;
  
  plVar5 = *(long **)(param_2 + 0xd8);
  if (plVar5 == (long *)0x0) {
    uVar1 = 0xffffffc3;
  }
  else {
    mutex_lock(&DAT_00105498);
    _raw_spin_lock(plVar5 + 2);
    plVar3 = (long *)plVar5[1];
    if (plVar3 != (long *)0x0) {
      lVar4 = *plVar5;
      *plVar3 = lVar4;
      if (lVar4 != 0) {
        *(long **)(lVar4 + 8) = plVar3;
      }
      *plVar5 = 0;
      plVar5[1] = 0;
    }
    if (DAT_00105578 == (long *)0x0) {
      iVar6 = 0;
      iVar7 = 0;
    }
    else {
      iVar7 = 0;
      iVar6 = 0;
      plVar3 = DAT_00105578;
      do {
        if (*(int *)((long)plVar3 + 0x14) != 0) {
          iVar7 = (int)plVar3[3] + iVar7;
          iVar6 = *(int *)((long)plVar3 + 0x1c) + iVar6;
        }
        plVar3 = (long *)*plVar3;
      } while (plVar3 != (long *)0x0);
    }
    _raw_spin_unlock(plVar5 + 2);
    kfree(plVar5);
    if (iVar7 != DAT_00105570) {
      if ((iVar7 == 0) || (iVar7 == iVar6)) {
        if (iVar7 == 0) {
          DAT_00105590 = DAT_001055d0[2];
          DAT_00105598 = DAT_001055d0[3];
          _DAT_00105580 = *DAT_001055d0;
          DAT_00105588 = DAT_001055d0[1];
          InstructionSynchronizationBarrier();
          DAT_001055a0 = cntvct_el0;
          iVar2 = DAT_00105448;
        }
        else {
          DAT_001055a8 = *DAT_001055d8;
          DAT_001055b0 = DAT_001055d8[1];
          DAT_001055b8 = DAT_001055d8[2];
          DAT_001055c0 = DAT_001055d8[3];
          InstructionSynchronizationBarrier();
          DAT_001055c8 = cntvct_el0;
          DAT_00105460 = 0;
          DAT_00105458 = 0;
          iVar2 = DAT_0010544c;
        }
        mod_timer(adspsleep_timer,_jiffies + (ulong)(uint)(iVar2 * 0xfa));
        DAT_0010543a = '\x01';
      }
      else if (DAT_0010543a != '\0') {
        del_timer(adspsleep_timer);
        DAT_0010543a = '\0';
        DAT_00105460 = 0;
        DAT_00105458 = 0;
      }
      DAT_00105570 = iVar7;
      DAT_00105574 = iVar6;
    }
    mutex_unlock(&DAT_00105498);
    _printk(&DAT_00103e8d,DAT_00105570,DAT_00105574,DAT_0010543a);
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// adspsleepmon_timer_cb @ 00102678 size=60
// signature: undefined adspsleepmon_timer_cb(void)
// callers: []
//------------------------------------------------------------

void adspsleepmon_timer_cb(void)

{
  DAT_00105439 = 1;
  __wake_up(adspsleepmon_wq,1,1,0);
  return;
}



//------------------------------------------------------------
// adspsleepmon_smem_init @ 001026b4 size=500
// signature: undefined adspsleepmon_smem_init(void)
// callers: [sleepmon_rpmsg_probe, adspsleepmon_device_open]
//------------------------------------------------------------

void adspsleepmon_smem_init(void)

{
  long lVar1;
  uint *puVar2;
  undefined8 uVar3;
  undefined *puVar4;
  ulong uVar5;
  uint *puVar6;
  ulong uVar7;
  uint uVar8;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  DAT_001055d0 = qcom_smem_get(2,0x25e,&local_30);
  if (((DAT_001055d0 == 0) || (0xfffffffffffff000 < DAT_001055d0)) || (local_30 < 0x20)) {
    puVar4 = &DAT_00104a8e;
LAB_00102874:
    _printk(puVar4);
  }
  else {
    DAT_001055d8 = qcom_smem_get(2,0x265,&local_30);
    if (((DAT_001055d8 == 0) || (0xfffffffffffff000 < DAT_001055d8)) || (local_30 < 0x20)) {
      puVar4 = &DAT_00104c41;
      goto LAB_00102874;
    }
    DAT_001055e0 = qcom_smem_get(2,0x270,&local_30);
    if (((DAT_001055e0 == 0) || (0xfffffffffffff000 < DAT_001055e0)) || (local_30 < 0x34)) {
      puVar4 = &DAT_00104cf2;
      goto LAB_00102874;
    }
    puVar2 = (uint *)qcom_smem_get(2,0x27a,&local_30);
    if (((puVar2 == (uint *)0x0) || ((uint *)0xfffffffffffff000 < puVar2)) || (local_30 == 0)) {
      puVar4 = &DAT_001040d7;
      goto LAB_00102874;
    }
    DAT_001055e8 = (uint *)0x0;
    uVar7 = (ulong)(*puVar2 >> 0x10) & 0xfff;
    if (uVar7 <= local_30) {
      puVar6 = (uint *)0x0;
      uVar8 = *puVar2 >> 0x1c;
      uVar5 = local_30;
      do {
        while (uVar8 == 2) {
          puVar6 = puVar2 + 1;
          uVar5 = 0;
          DAT_001055e8 = puVar6;
          if (uVar7 != 0) goto LAB_001027f8;
        }
        puVar2 = (uint *)((long)puVar2 + uVar7);
        uVar5 = uVar5 - uVar7;
        uVar7 = (ulong)(*puVar2 >> 0x10) & 0xfff;
        uVar8 = *puVar2 >> 0x1c;
      } while (uVar7 <= uVar5);
LAB_001027f8:
      if ((puVar6 != (uint *)0x0) && (puVar6 < (uint *)0xfffffffffffff001)) {
        if (DAT_0010543d == '\0') {
          register_pm_notifier(&adsp_sleepmon_pm_nb);
          DAT_0010543d = '\x01';
        }
        uVar3 = 0;
        DAT_0010543c = 1;
        goto LAB_0010287c;
      }
    }
    _printk(&DAT_001049f1);
  }
  uVar3 = 0xfffffff4;
LAB_0010287c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// adspsleepmon_suspend_notify @ 001028ac size=116
// signature: undefined adspsleepmon_suspend_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 adspsleepmon_suspend_notify(undefined8 param_1,long param_2)

{
  if (param_2 == 4) {
    _printk(&DAT_001053ac);
    if ((DAT_00105570 == 0) || (DAT_00105570 == DAT_00105574)) {
      DAT_0010543b = 1;
      __wake_up(adspsleepmon_wq,1,1,0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// panic_state_fops_open @ 00102924 size=52
// signature: undefined panic_state_fops_open(void)
// callers: []
//------------------------------------------------------------

void panic_state_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,debugfs_panic_state_read,debugfs_panic_state_write,&DAT_00104370)
  ;
  return;
}



//------------------------------------------------------------
// debugfs_panic_state_read @ 0010295c size=32
// signature: undefined debugfs_panic_state_read(void)
// callers: []
//------------------------------------------------------------

undefined8 debugfs_panic_state_read(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_0010543e | (ulong)DAT_0010543f << 1;
  return 0;
}



//------------------------------------------------------------
// debugfs_panic_state_write @ 00102980 size=48
// signature: undefined debugfs_panic_state_write(void)
// callers: []
//------------------------------------------------------------

undefined8 debugfs_panic_state_write(undefined8 param_1,ulong param_2)

{
  DAT_0010543e = 0;
  if ((param_2 & 1) != 0) {
    DAT_0010543e = DAT_00105440;
  }
  DAT_0010543f = 0;
  if ((param_2 & 2) != 0) {
    DAT_0010543f = DAT_00105441;
  }
  return 0;
}



//------------------------------------------------------------
// read_panic_state_open @ 001029b4 size=48
// signature: undefined read_panic_state_open(void)
// callers: []
//------------------------------------------------------------

void read_panic_state_open(long param_1,undefined8 param_2)

{
  single_open(param_2,read_panic_state_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// read_panic_state_show @ 001029e8 size=68
// signature: undefined read_panic_state_show(void)
// callers: []
//------------------------------------------------------------

undefined8 read_panic_state_show(undefined8 param_1)

{
  seq_puts(param_1,(&PTR_s_Panic_State__LPM_and_LPI_panics_D_00103da0)
                   [(ulong)((uint)DAT_0010543e | (uint)DAT_0010543f << 1) & 0xff]);
  return 0;
}



//------------------------------------------------------------
// master_stats_open @ 00102a30 size=48
// signature: undefined master_stats_open(void)
// callers: []
//------------------------------------------------------------

void master_stats_open(long param_1,undefined8 param_2)

{
  single_open(param_2,master_stats_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// master_stats_show @ 00102a64 size=940
// signature: undefined master_stats_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 master_stats_show(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  if ((DAT_00105488 != 0) && (DAT_00105490 != 0)) {
    local_48 = 0x200000010;
    uStack_40 = 0x100000002;
    iVar2 = rpmsg_send(*(undefined8 *)(DAT_00105490 + 0x3c8),&local_48,0x10);
    if (iVar2 == 0) {
      wait_for_completion(&DAT_00105468);
      print_complete_dsppm_info();
    }
    else {
      _printk(&DAT_00104466,iVar2);
    }
  }
  if (DAT_001055e8 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nsysMon stats:\n\n");
    seq_printf(param_1,"Core clock(KHz): %d\n",*DAT_001055e8);
    seq_printf(param_1,"Ab vote(Bytes): %llu\n",*(undefined8 *)(DAT_001055e8 + 1));
    seq_printf(param_1,"Ib vote(Bytes): %llu\n",*(undefined8 *)(DAT_001055e8 + 3));
    iVar2 = DAT_001055e8[5];
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar2);
    seq_printf(param_1,"Timestamp: %llu\n",*(undefined8 *)(DAT_001055e8 + 6));
  }
  if (DAT_001055e0 != (undefined4 *)0x0) {
    seq_puts(param_1,"\nDSPPM stats:\n\n");
    seq_printf(param_1,"Version: %u\n",*DAT_001055e0);
    iVar2 = DAT_001055e0[1];
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    seq_printf(param_1,"Sleep latency(usec): %u\n",iVar2);
    seq_printf(param_1,"Timestamp: %llu\n",DAT_001055e0[2]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_001055e0[3],DAT_001055e0[4]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_001055e0[5],DAT_001055e0[6]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_001055e0[7],DAT_001055e0[8]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_001055e0[9],DAT_001055e0[10]);
    seq_printf(param_1,"Pid: %d, Num active clients: %d\n",DAT_001055e0[0xb],DAT_001055e0[0xc]);
  }
  if (DAT_001055d0 != 0) {
    lVar4 = *(long *)(DAT_001055d0 + 0x18);
    if (*(ulong *)(DAT_001055d0 + 0x10) < *(ulong *)(DAT_001055d0 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c8c);
        (*pcVar1)();
      }
      lVar3 = (*_arch_timer_read_counter)();
      lVar4 = (lVar3 + lVar4) - *(long *)(DAT_001055d0 + 8);
    }
    seq_puts(param_1,"\nLPM stats:\n\n");
    seq_printf(param_1,"Count = %u\n",*(undefined4 *)(DAT_001055d0 + 4));
    seq_printf(param_1,"Last Entered At = %llu\n",*(undefined8 *)(DAT_001055d0 + 8));
    seq_printf(param_1,"Last Exited At = %llu\n",*(undefined8 *)(DAT_001055d0 + 0x10));
    seq_printf(param_1,"Accumulated Duration = %llu\n",lVar4);
  }
  if (DAT_001055d8 != 0) {
    lVar4 = *(long *)(DAT_001055d8 + 0x18);
    if (*(ulong *)(DAT_001055d8 + 0x10) < *(ulong *)(DAT_001055d8 + 8)) {
      if (*(int *)(_arch_timer_read_counter + -4) != 0x529c6ef0) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102d48);
        (*pcVar1)();
      }
      lVar3 = (*_arch_timer_read_counter)();
      lVar4 = (lVar3 + lVar4) - *(long *)(DAT_001055d8 + 8);
    }
    seq_puts(param_1,"\nLPI stats:\n\n");
    seq_printf(param_1,"Count = %u\n",*(undefined4 *)(DAT_001055d8 + 4));
    seq_printf(param_1,"Last Entered At = %llu\n",*(undefined8 *)(DAT_001055d8 + 8));
    seq_printf(param_1,"Last Exited At = %llu\n",*(undefined8 *)(DAT_001055d8 + 0x10));
    seq_printf(param_1,"Accumulated Duration = %llu\n",lVar4);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// adsp_panic_state_fops_open @ 00102e14 size=52
// signature: undefined adsp_panic_state_fops_open(void)
// callers: []
//------------------------------------------------------------

void adsp_panic_state_fops_open(undefined8 param_1,undefined8 param_2)

{
  simple_attr_open(param_1,param_2,debugfs_adsp_panic_state_read,debugfs_adsp_panic_state_write,
                   &DAT_00104370);
  return;
}



//------------------------------------------------------------
// debugfs_adsp_panic_state_read @ 00102e4c size=48
// signature: undefined debugfs_adsp_panic_state_read(void)
// callers: []
//------------------------------------------------------------

undefined8 debugfs_adsp_panic_state_read(undefined8 param_1,ulong *param_2)

{
  *param_2 = (ulong)DAT_00105442 | (ulong)DAT_00105443 << 1 | (ulong)DAT_00105444 << 2 |
             (ulong)DAT_00105445 << 3;
  return 0;
}



//------------------------------------------------------------
// debugfs_adsp_panic_state_write @ 00102e80 size=176
// signature: undefined debugfs_adsp_panic_state_write(void)
// callers: []
//------------------------------------------------------------

undefined8 debugfs_adsp_panic_state_write(undefined8 param_1,uint param_2)

{
  undefined *puVar1;
  
  if ((DAT_00105490 == 0) || (DAT_00105488 < 2)) {
    puVar1 = &DAT_00104e6b;
  }
  else {
    DAT_00105442 = (byte)param_2 & 1;
    DAT_00105443 = (byte)(param_2 >> 1) & 1;
    DAT_00105444 = (byte)(param_2 >> 2) & 1;
    if ((param_2 >> 3 & 1) == 0) {
      DAT_00105445 = 0;
      return 0;
    }
    if (DAT_00105f48 == 0) {
      puVar1 = &DAT_001042aa;
    }
    else {
      if ((param_2 & 7) != 0) {
        DAT_00105445 = 1;
        return 0;
      }
      puVar1 = &DAT_0010449c;
    }
  }
  _printk(puVar1);
  return 0xffffffea;
}



//------------------------------------------------------------
// read_adsp_panic_state_open @ 00102f34 size=48
// signature: undefined read_adsp_panic_state_open(void)
// callers: []
//------------------------------------------------------------

void read_adsp_panic_state_open(long param_1,undefined8 param_2)

{
  single_open(param_2,read_adsp_panic_state_show,*(undefined8 *)(param_1 + 0x2b8));
  return;
}



//------------------------------------------------------------
// read_adsp_panic_state_show @ 00102f68 size=240
// signature: undefined read_adsp_panic_state_show(void)
// callers: []
//------------------------------------------------------------

undefined8 read_adsp_panic_state_show(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  
  pcVar3 = "\nADSP version doesn\'t support panic\n";
  if ((DAT_00105490 != 0) && (1 < DAT_00105488)) {
    uVar1 = (uint)DAT_00105442 | (uint)DAT_00105443 << 1;
    uVar2 = uVar1 | (uint)DAT_00105444 << 2;
    uVar4 = (uint)DAT_00105445;
    pcVar3 = "\nADSP panic on LPM violation is disabled\n";
    if ((DAT_00105442 & 1) != 0) {
      pcVar3 = "\nADSP panic on LPM violation enabled\n";
    }
    seq_puts(param_1,pcVar3);
    pcVar3 = "\nADSP panic on LPI violation is disabled\n";
    if ((uVar1 & 2) != 0) {
      pcVar3 = "\nADSP panic on LPI violation enabled\n";
    }
    seq_puts(param_1,pcVar3);
    pcVar3 = "\nADSP panic for LPM overall violation is disabled\n";
    if ((uVar2 & 4) != 0) {
      pcVar3 = "\nADSP panic for LPM overall violation enabled\n";
    }
    seq_puts(param_1,pcVar3);
    pcVar3 = "\nADSP SSR config disabled\n";
    if (7 < (uVar2 | uVar4 << 3)) {
      pcVar3 = "\nADSP SSR config enabled\n";
    }
  }
  seq_puts(param_1,pcVar3);
  return 0;
}



//------------------------------------------------------------
// sleepmon_rpmsg_probe @ 0010305c size=140
// signature: undefined sleepmon_rpmsg_probe(void)
// callers: []
//------------------------------------------------------------

void sleepmon_rpmsg_probe(long param_1)

{
  of_platform_populate(*(undefined8 *)(param_1 + 0x2e8),0,0,param_1);
  DAT_00105490 = param_1;
  if (DAT_00105f48 == 0) {
    if (DAT_00105f40 != 0) {
      DAT_00105f48 = rproc_get_by_phandle(DAT_00105f40);
    }
  }
  if (DAT_00105f48 != 0) {
    _printk(&DAT_00104f73);
    qcom_rproc_update_recovery_status(DAT_00105f48,0);
  }
  adspsleepmon_smem_init();
  return;
}



//------------------------------------------------------------
// sleepmon_rpmsg_remove @ 001030ec size=20
// signature: undefined sleepmon_rpmsg_remove(void)
// callers: []
//------------------------------------------------------------

void sleepmon_rpmsg_remove(void)

{
  DAT_00105490 = 0;
  DAT_00105488 = 0;
  return;
}



//------------------------------------------------------------
// sleepmon_rpmsg_callback @ 00103104 size=400
// signature: undefined sleepmon_rpmsg_callback(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sleepmon_rpmsg_callback(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  if ((param_2 == 0) || ((uint)param_3 < 0x930)) {
    _dev_err(param_1,"Invalid message in rpmsg callback, length: %d, expected: %lu\n",param_3,0x930)
    ;
    return 0xffffffea;
  }
  iVar1 = *(int *)(param_2 + 8);
  if (iVar1 == 1) {
    DAT_00105488 = *(undefined4 *)(param_2 + 4);
    _printk(&DAT_00104611);
    if (DAT_0010543c == '\0') {
      return 0;
    }
    _DAT_00105570 = 0;
    del_timer(adspsleep_timer);
    DAT_0010543a = 0;
    DAT_00105460 = 0;
    DAT_00105458 = 0;
    _DAT_00105580 = *DAT_001055d0;
    DAT_00105588 = DAT_001055d0[1];
    DAT_00105590 = DAT_001055d0[2];
    DAT_00105598 = DAT_001055d0[3];
    InstructionSynchronizationBarrier();
    DAT_001055a0 = cntvct_el0;
    iVar1 = *(int *)(param_2 + 8);
  }
  if (iVar1 == 2) {
    DAT_00105ee0 = 0;
    memcpy(&DAT_001055f0,(void *)(param_2 + 0x10),0x920);
    complete(&DAT_00105468);
    iVar1 = *(int *)(param_2 + 8);
  }
  if (iVar1 == 5) {
    if (DAT_0010543f != '\0') {
      _printk(&DAT_0010484c);
                    /* WARNING: Subroutine does not return */
      panic("ADSP_SLEEPMON: ADSP LPI issue detected");
    }
    if (DAT_00105443 == '\0') {
      return 0;
    }
    sleepmon_send_ssr_command();
    iVar1 = *(int *)(param_2 + 8);
  }
  if (iVar1 == 6) {
    _printk(&DAT_001046a1,param_2 + 0x10,*(undefined4 *)(param_2 + 0x54));
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 00103350 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&adspsleepmon,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00103380 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&adspsleepmon);
  return;
}



//------------------------------------------------------------
// _printk @ 00108000 size=1
// signature: undefined _printk(void)
// callers: [sleepmon_get_dsppm_clients, adspsleepmon_suspend_notify, sleepmon_rpmsg_probe, adspsleepmon_device_ioctl, sleepmon_rpmsg_callback, adspsleepmon_lpm_adsp_panic_overall, adspsleepmon_worker, sleepmon_is_audio_active, sleepmon_send_ssr_command, adsp_sleepmon_log_master_stats, adspsleepmon_smem_init, sleepmon_get_dsppm_client_stats, debugfs_adsp_panic_state_write, print_complete_dsppm_info, adspsleepmon_device_release, master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion @ 00108008 size=1
// signature: undefined wait_for_completion(void)
// callers: [adsp_sleepmon_log_master_stats, master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rpmsg_send @ 00108018 size=1
// signature: undefined rpmsg_send(void)
// callers: [sleepmon_send_ssr_command, sleepmon_get_dsppm_clients, sleepmon_get_dsppm_client_stats, adspsleepmon_worker, master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rpmsg_send(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00108020 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [sleepmon_send_ssr_command, sleepmon_get_dsppm_clients, adspsleepmon_device_ioctl, adspsleepmon_smem_init, sleepmon_get_dsppm_client_stats, adspsleepmon_worker, master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00108028 size=1
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
// platform_driver_unregister @ 00108030 size=1
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
// __mutex_init @ 00108038 size=1
// signature: undefined __mutex_init(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00108040 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00108048 size=1
// signature: undefined wake_up_process(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00108050 size=1
// signature: undefined _dev_err(void)
// callers: [adspsleepmon_driver_probe, sleepmon_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// alloc_chrdev_region @ 00108058 size=1
// signature: undefined alloc_chrdev_region(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void alloc_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_init @ 00108060 size=1
// signature: undefined cdev_init(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_add @ 00108068 size=1
// signature: undefined cdev_add(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __class_create @ 00108070 size=1
// signature: undefined __class_create(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __class_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create @ 00108078 size=1
// signature: undefined device_create(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 00108080 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_destroy @ 00108088 size=1
// signature: undefined device_destroy(void)
// callers: [adspsleepmon_driver_remove, adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// class_destroy @ 00108090 size=1
// signature: undefined class_destroy(void)
// callers: [adspsleepmon_driver_remove, adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void class_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cdev_del @ 00108098 size=1
// signature: undefined cdev_del(void)
// callers: [adspsleepmon_driver_remove, adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cdev_del(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_chrdev_region @ 001080a0 size=1
// signature: undefined unregister_chrdev_region(void)
// callers: [adspsleepmon_driver_remove, adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_chrdev_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001080a8 size=1
// signature: undefined of_find_property(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001080b0 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 001080b8 size=1
// signature: undefined _dev_info(void)
// callers: [adspsleepmon_driver_remove, adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_file @ 001080c0 size=1
// signature: undefined debugfs_create_file(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __register_rpmsg_driver @ 001080c8 size=1
// signature: undefined __register_rpmsg_driver(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __register_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 001080d0 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [adspsleepmon_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001080d8 size=1
// signature: undefined debugfs_remove(void)
// callers: [adspsleepmon_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_pm_notifier @ 001080e0 size=1
// signature: undefined unregister_pm_notifier(void)
// callers: [adspsleepmon_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_rpmsg_driver @ 001080e8 size=1
// signature: undefined unregister_rpmsg_driver(void)
// callers: [adspsleepmon_driver_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_rpmsg_driver(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 001080f0 size=1
// signature: undefined kthread_should_stop(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 001080f8 size=1
// signature: undefined mutex_unlock(void)
// callers: [adspsleepmon_device_ioctl, adspsleepmon_device_release, adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 00108100 size=1
// signature: undefined init_wait_entry(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 00108108 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 00108110 size=1
// signature: undefined schedule(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00108118 size=1
// signature: undefined mutex_lock(void)
// callers: [adspsleepmon_device_ioctl, adspsleepmon_device_release, adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 00108120 size=1
// signature: undefined finish_wait(void)
// callers: [adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// panic @ 00108128 size=1
// signature: noreturn undefined panic(void)
// callers: [sleepmon_rpmsg_callback, adspsleepmon_worker]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00108130 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [sleepmon_get_dsppm_clients]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_rproc_update_recovery_status @ 00108138 size=1
// signature: undefined qcom_rproc_update_recovery_status(void)
// callers: [sleepmon_send_ssr_command, sleepmon_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_rproc_update_recovery_status(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __arch_copy_from_user @ 00108150 size=1
// signature: undefined __arch_copy_from_user(void)
// callers: [adspsleepmon_device_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __arch_copy_from_user(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00108158 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [adspsleepmon_device_ioctl]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00108160 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [adspsleepmon_device_ioctl, adspsleepmon_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00108168 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [adspsleepmon_device_ioctl, adspsleepmon_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// del_timer @ 00108170 size=1
// signature: undefined del_timer(void)
// callers: [adspsleepmon_device_ioctl, sleepmon_rpmsg_callback, adspsleepmon_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00108180 size=1
// signature: undefined mod_timer(void)
// callers: [adspsleepmon_device_ioctl, adspsleepmon_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00108198 size=1
// signature: undefined kmalloc_trace(void)
// callers: [adspsleepmon_device_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001081a0 size=1
// signature: undefined kfree(void)
// callers: [adspsleepmon_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 001081a8 size=1
// signature: undefined __wake_up(void)
// callers: [adspsleepmon_suspend_notify, adspsleepmon_timer_cb]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_smem_get @ 001081b0 size=1
// signature: undefined qcom_smem_get(void)
// callers: [adspsleepmon_smem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_smem_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 001081b8 size=1
// signature: undefined register_pm_notifier(void)
// callers: [adspsleepmon_smem_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// simple_attr_open @ 001081c0 size=1
// signature: undefined simple_attr_open(void)
// callers: [adsp_panic_state_fops_open, panic_state_fops_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void simple_attr_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// single_open @ 001081c8 size=1
// signature: undefined single_open(void)
// callers: [read_panic_state_open, read_adsp_panic_state_open, master_stats_open]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void single_open(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_puts @ 001081d0 size=1
// signature: undefined seq_puts(void)
// callers: [read_adsp_panic_state_show, read_panic_state_show, master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_puts(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// seq_printf @ 001081d8 size=1
// signature: undefined seq_printf(void)
// callers: [master_stats_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void seq_printf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_platform_populate @ 001081e0 size=1
// signature: undefined of_platform_populate(void)
// callers: [sleepmon_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_platform_populate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// rproc_get_by_phandle @ 001081e8 size=1
// signature: undefined rproc_get_by_phandle(void)
// callers: [sleepmon_rpmsg_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void rproc_get_by_phandle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 001081f0 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [sleepmon_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 001081f8 size=1
// signature: undefined complete(void)
// callers: [sleepmon_rpmsg_callback]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



