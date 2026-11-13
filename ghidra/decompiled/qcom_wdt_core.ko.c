// Decompiled by Ghidra 12.2
// Program: qcom_wdt_core.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_wdt_pet_suspend @ 001004d4 size=220
// signature: undefined qcom_wdt_pet_suspend(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_wdt_pet_suspend(long param_1)

{
  undefined8 uVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  if (lVar3 != 0) {
    if (*(char *)(lVar3 + 0xd1) != '\0') {
      del_timer_sync(lVar3 + 0x3d0);
    }
    _raw_spin_lock(lVar3 + 0x3cc);
    *(undefined1 *)(lVar3 + 0x3c8) = 1;
    _raw_spin_unlock(lVar3 + 0x3cc);
    pcVar2 = *(code **)(*(long *)(lVar3 + 0x10) + 0x10);
    if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10053c);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
    del_timer_sync(lVar3 + 0xe0);
    if (((*(char *)(lVar3 + 0x26) == '\0') || (*(char *)(lVar3 + 0x408) != '\0')) ||
       (_pm_suspend_target_state == 3)) {
      pcVar2 = *(code **)(*(long *)(lVar3 + 0x10) + 0x20);
      if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10058c);
        (*pcVar2)();
      }
      (*pcVar2)(lVar3);
      *(undefined1 *)(lVar3 + 0xd0) = 0;
    }
    uVar1 = sched_clock();
    *(undefined8 *)(lVar3 + 0x28) = uVar1;
  }
  return 0;
}



//------------------------------------------------------------
// qcom_wdt_pet_resume @ 001005b4 size=472
// signature: undefined qcom_wdt_pet_resume(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_wdt_pet_resume(long param_1)

{
  code *pcVar1;
  long lVar2;
  undefined8 uVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x98);
  if (lVar4 != 0) {
    if (*(char *)(lVar4 + 0xd1) != '\0') {
      lVar2 = __msecs_to_jiffies(*(int *)(lVar4 + 0x1c) + 3000);
      *(long *)(lVar4 + 0x3e0) = _jiffies + lVar2;
      add_timer(lVar4 + 0x3d0);
    }
    lVar2 = __msecs_to_jiffies(*(undefined4 *)(lVar4 + 0x18));
    _raw_spin_lock(lVar4 + 0x3cc);
    *(long *)(lVar4 + 0xf0) = _jiffies + lVar2;
    add_timer(lVar4 + 0xe0);
    *(undefined1 *)(lVar4 + 0x3c8) = 0;
    _raw_spin_unlock(lVar4 + 0x3cc);
    if (*(char *)(lVar4 + 0x26) == '\0') {
      pcVar1 = *(code **)(*(long *)(lVar4 + 0x10) + 0x18);
      if (*(int *)(pcVar1 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10073c);
        (*pcVar1)();
      }
      (*pcVar1)(1,lVar4);
      pcVar1 = *(code **)(*(long *)(lVar4 + 0x10) + 0x10);
      if (*(int *)(pcVar1 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100764);
        (*pcVar1)();
      }
      (*pcVar1)(lVar4);
      *(undefined1 *)(lVar4 + 0xd0) = 1;
    }
    else {
      if ((*(char *)(lVar4 + 0x408) != '\0') || (_pm_suspend_target_state == 3)) {
        if (*(int *)((code *)**(undefined8 **)(lVar4 + 0x10) + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10067c);
          (*pcVar1)();
        }
        (*(code *)**(undefined8 **)(lVar4 + 0x10))(*(undefined4 *)(lVar4 + 0x1c),lVar4);
        pcVar1 = *(code **)(*(long *)(lVar4 + 0x10) + 8);
        if (*(int *)(pcVar1 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1006ac);
          (*pcVar1)();
        }
        (*pcVar1)(*(int *)(lVar4 + 0x1c) + 3000,lVar4);
        pcVar1 = *(code **)(*(long *)(lVar4 + 0x10) + 0x18);
        if (*(int *)(pcVar1 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1006d8);
          (*pcVar1)();
        }
        (*pcVar1)(3,lVar4);
        *(undefined1 *)(lVar4 + 0xd0) = 1;
      }
      pcVar1 = *(code **)(*(long *)(lVar4 + 0x10) + 0x10);
      if (*(int *)(pcVar1 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100708);
        (*pcVar1)();
      }
      (*pcVar1)(lVar4);
    }
    uVar3 = sched_clock();
    *(undefined8 *)(lVar4 + 0x28) = uVar3;
  }
  return 0;
}



//------------------------------------------------------------
// qcom_wdt_remove @ 00100790 size=180
// signature: undefined qcom_wdt_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_wdt_remove(long param_1)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0xa8);
  cpu_pm_unregister_notifier(lVar1 + 0xa0);
  mutex_lock(lVar1 + 0x38);
  if (*(char *)(lVar1 + 0xd0) != '\0') {
    qcom_wdt_disable(lVar1);
  }
  mutex_unlock(lVar1 + 0x38);
  device_remove_file(*(undefined8 *)(lVar1 + 8),&dev_attr_disable);
  if (*(char *)(lVar1 + 0x27) != '\0') {
    free_percpu(*(undefined8 *)(lVar1 + 0x68));
  }
  irq_dispose_mapping(*(undefined4 *)(lVar1 + 0x20));
  _dev_info(*(undefined8 *)(lVar1 + 8),"QCOM Apps Watchdog Exit - Deactivated\n");
  del_timer_sync(lVar1 + 0xe0);
  if (*(char *)(lVar1 + 0xd1) != '\0') {
    del_timer_sync(lVar1 + 0x3d0);
  }
  *(undefined2 *)(lVar1 + 0x130) = 0x101;
  kthread_stop(*(undefined8 *)(lVar1 + 0xd8));
  return 0;
}



//------------------------------------------------------------
// qcom_wdt_disable @ 00100844 size=240
// signature: undefined qcom_wdt_disable(void)
// callers: [qcom_wdt_remove, qcom_wdt_disable_set]
//------------------------------------------------------------

void qcom_wdt_disable(long param_1)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(long *)(param_1 + 0x10) + 0x20);
  if (*(int *)(pcVar1 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100878);
    (*pcVar1)();
  }
  (*pcVar1)();
  if (*(char *)(param_1 + 0x27) == '\0') {
    devm_free_irq(*(undefined8 *)(param_1 + 8),*(undefined4 *)(param_1 + 0x20),param_1);
  }
  else {
    disable_percpu_irq(*(undefined4 *)(param_1 + 0x20));
    free_percpu_irq(*(undefined4 *)(param_1 + 0x20),*(undefined8 *)(param_1 + 0x68));
  }
  *(undefined1 *)(param_1 + 0xd0) = 0;
  DataMemoryBarrier(2,3);
  atomic_notifier_chain_unregister(&panic_notifier_list,param_1 + 0x70);
  unregister_die_notifier(param_1 + 0x88);
  unregister_restart_handler(param_1 + 0xb8);
  del_timer_sync(param_1 + 0xe0);
  if (*(char *)(param_1 + 0xd1) != '\0') {
    del_timer_sync(param_1 + 0x3d0);
  }
  pcVar1 = *(code **)(*(long *)(param_1 + 0x10) + 0x20);
  if (*(int *)(pcVar1 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100910);
    (*pcVar1)();
  }
  (*pcVar1)(param_1);
  _dev_err(*(undefined8 *)(param_1 + 8),"QCOM Apps Watchdog deactivated\n");
  return;
}



//------------------------------------------------------------
// qcom_wdt_trigger_bite @ 00100938 size=1140
// signature: undefined qcom_wdt_trigger_bite(void)
// callers: [qcom_wdt_bark_handler, restart_wdog_handler, qcom_wdt_user_pet_bite]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_wdt_trigger_bite(void)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  char *pcVar9;
  char *pcVar10;
  long lVar11;
  code *pcVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  ulong uVar19;
  uint local_bc;
  undefined8 local_b8;
  long local_b0;
  ulong local_a8;
  uint uStack_a4;
  long local_a0;
  undefined8 local_98;
  long local_90;
  undefined8 local_88;
  long local_80;
  undefined8 local_78;
  long local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  if (wdog_data == 0) {
    lVar7 = sp_el0;
    if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    return;
  }
  local_78 = 0;
  local_70 = 0;
  local_88 = 0;
  local_80 = 0;
  local_98 = 0;
  local_90 = 0;
  local_a8 = 0;
  local_a0 = 0;
  local_b8 = 0;
  local_b0 = 0;
  iVar5 = nr_ipi_get();
  lVar7 = sched_clock();
  lVar11 = *(long *)(wdog_data + 0x28);
  __rcu_read_lock();
  if (_nr_irqs < 1) {
    local_bc = 0;
    uVar15 = 0;
    uVar16 = 0;
    uVar17 = 0;
    uVar13 = 0;
  }
  else {
    uVar15 = 0;
    uVar16 = 0;
    uVar17 = 0;
    uVar13 = 0;
    iVar18 = 0;
    uVar19 = 0;
    uVar14 = 0;
    local_bc = 0;
    do {
      if (iVar5 < iVar18) {
        lVar8 = irq_to_desc(iVar18);
        if (lVar8 != 0) {
          iVar6 = kstat_irqs_usr(iVar18);
          uVar2 = iVar6 - *(int *)(lVar8 + 0x1c8);
          if (uVar14 < uVar2) {
            if ((((0x50 < (uVar19 << 4 | 4)) || (0x50 < (uVar19 << 4 | 4))) ||
                (*(uint *)((long)&local_b8 + uVar19 * 0x10 + 4) = uVar2, 4 < (uint)uVar19)) ||
               ((*(int *)(&local_b8 + uVar19 * 2) = iVar18, 0x50 < (uVar19 << 4 | 8) ||
                (0x50 < (uVar19 << 4 | 8))))) {
                    /* WARNING: Does not return */
              pcVar12 = (code *)SoftwareBreakpoint(1,0x100da8);
              (*pcVar12)();
            }
            uVar17 = uStack_a4;
            uVar16 = local_98._4_4_;
            uVar15 = local_88._4_4_;
            bVar3 = uStack_a4 < local_b8._4_4_;
            local_bc = local_78._4_4_;
            uVar13 = uStack_a4;
            if (!bVar3) {
              uVar13 = local_b8._4_4_;
            }
            bVar4 = uVar13 <= local_98._4_4_;
            (&local_b0)[uVar19 * 2] = lVar8;
            uVar14 = uVar16;
            if (bVar4) {
              uVar14 = uVar13;
            }
            uVar13 = 2;
            if (bVar4) {
              uVar13 = (uint)bVar3;
            }
            uVar2 = uVar15;
            if (uVar14 <= uVar15) {
              uVar2 = uVar14;
            }
            uVar1 = 3;
            if (uVar14 <= uVar15) {
              uVar1 = uVar13;
            }
            uVar14 = local_bc;
            if (uVar2 <= local_bc) {
              uVar14 = uVar2;
            }
            uVar13 = 4;
            if (uVar2 <= local_bc) {
              uVar13 = uVar1;
            }
            uVar19 = (ulong)uVar13;
            uVar13 = local_b8._4_4_;
          }
        }
      }
      iVar18 = iVar18 + 1;
    } while (iVar18 < _nr_irqs);
  }
  __rcu_read_unlock();
  _printk(&DAT_00101fb1,(ulong)(lVar7 - lVar11) / 1000000);
  if (uVar13 != 0) {
    if (*(undefined8 **)(local_b0 + 0x48) == (undefined8 *)0x0) {
      pcVar9 = "UNKNOWN";
    }
    else {
      pcVar9 = (char *)**(undefined8 **)(local_b0 + 0x48);
    }
    if (*(long *)(local_b0 + 0x78) == 0) {
      pcVar10 = "NONAME";
    }
    else {
      pcVar10 = *(char **)(*(long *)(local_b0 + 0x78) + 0x50);
    }
    _printk(&DAT_00101f0c,local_b8 & 0xffffffff,pcVar9,pcVar10,uVar13);
  }
  if (uVar17 != 0) {
    if (*(undefined8 **)(local_a0 + 0x48) == (undefined8 *)0x0) {
      pcVar9 = "UNKNOWN";
    }
    else {
      pcVar9 = (char *)**(undefined8 **)(local_a0 + 0x48);
    }
    if (*(long *)(local_a0 + 0x78) == 0) {
      pcVar10 = "NONAME";
    }
    else {
      pcVar10 = *(char **)(*(long *)(local_a0 + 0x78) + 0x50);
    }
    _printk(&DAT_00101f0c,local_a8 & 0xffffffff,pcVar9,pcVar10,uVar17);
  }
  if (uVar16 != 0) {
    if (*(undefined8 **)(local_90 + 0x48) == (undefined8 *)0x0) {
      pcVar9 = "UNKNOWN";
    }
    else {
      pcVar9 = (char *)**(undefined8 **)(local_90 + 0x48);
    }
    if (*(long *)(local_90 + 0x78) == 0) {
      pcVar10 = "NONAME";
    }
    else {
      pcVar10 = *(char **)(*(long *)(local_90 + 0x78) + 0x50);
    }
    _printk(&DAT_00101f0c,local_98 & 0xffffffff,pcVar9,pcVar10,uVar16);
  }
  if (uVar15 != 0) {
    if (*(undefined8 **)(local_80 + 0x48) == (undefined8 *)0x0) {
      pcVar9 = "UNKNOWN";
    }
    else {
      pcVar9 = (char *)**(undefined8 **)(local_80 + 0x48);
    }
    if (*(long *)(local_80 + 0x78) == 0) {
      pcVar10 = "NONAME";
    }
    else {
      pcVar10 = *(char **)(*(long *)(local_80 + 0x78) + 0x50);
    }
    _printk(&DAT_00101f0c,local_88 & 0xffffffff,pcVar9,pcVar10,uVar15);
  }
  if (local_bc != 0) {
    if (*(undefined8 **)(local_70 + 0x48) == (undefined8 *)0x0) {
      pcVar9 = "UNKNOWN";
    }
    else {
      pcVar9 = (char *)**(undefined8 **)(local_70 + 0x48);
    }
    if (*(long *)(local_70 + 0x78) == 0) {
      pcVar10 = "NONAME";
    }
    else {
      pcVar10 = *(char **)(*(long *)(local_70 + 0x78) + 0x50);
    }
    _printk(&DAT_00101f0c,local_78 & 0xffffffff,pcVar9,pcVar10);
  }
  _dev_err(*(undefined8 *)(wdog_data + 8),"Causing a QCOM Apps Watchdog bite!\n");
  pcVar12 = *(code **)(*(long *)(wdog_data + 0x10) + 0x28);
  if (*(int *)(pcVar12 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x100d28);
    (*pcVar12)();
  }
  (*pcVar12)();
  pcVar12 = *(code **)(*(long *)(wdog_data + 0x10) + 8);
  if (*(int *)(pcVar12 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x100d54);
    (*pcVar12)();
  }
  (*pcVar12)(1);
  pcVar12 = *(code **)(*(long *)(wdog_data + 0x10) + 0x10);
  if (*(int *)(pcVar12 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
    pcVar12 = (code *)SoftwareBreakpoint(0x8228,0x100d7c);
    (*pcVar12)();
  }
  (*pcVar12)();
  lVar7 = -10000;
  do {
    __const_udelay(0x418958);
    bVar3 = lVar7 != -1;
    lVar7 = lVar7 + 1;
  } while (bVar3);
  do {
    __const_udelay(0x10c7);
  } while( true );
}



//------------------------------------------------------------
// qcom_wdt_register @ 00100db0 size=1352
// signature: undefined qcom_wdt_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong qcom_wdt_register(long param_1,long param_2,long param_3)

{
  long lVar1;
  code *pcVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  ulong uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  char local_78 [8];
  undefined8 local_70;
  undefined8 local_68;
  long local_60;
  long local_58;
  undefined8 local_50;
  long local_48;
  
  lVar9 = sp_el0;
  local_48 = *(long *)(lVar9 + 0x638);
  local_58 = 0;
  local_50 = 0;
  local_68 = 0;
  local_60 = 0;
  local_78[0] = '\0';
  local_78[1] = '\0';
  local_78[2] = '\0';
  local_78[3] = '\0';
  local_78[4] = '\0';
  local_78[5] = '\0';
  local_78[6] = '\0';
  local_78[7] = '\0';
  local_70 = 0;
  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {
    _printk(&DAT_0010214e);
    uVar8 = 0xffffffea;
    goto LAB_00100f48;
  }
  uVar7 = platform_get_irq(param_1,0);
  *(int *)(param_2 + 0x20) = (int)uVar7;
  bVar3 = irq_check_status_bit(uVar7,0x200);
  *(undefined8 *)(param_2 + 0x18) = 0x3e8000002490;
  iVar5 = _nr_cpu_ids;
  *(byte *)(param_2 + 0x27) = bVar3 & 1;
  *(undefined1 *)(param_2 + 0x24) = 1;
  *(undefined1 *)(param_2 + 0x26) = 1;
  *(long *)(param_2 + 8) = param_1 + 0x10;
  *(long *)(param_1 + 0xa8) = param_2;
  wdog_data = param_2;
  memset((void *)(param_2 + 0x30),0,(ulong)(iVar5 + 0x3fU >> 3 & 0x1ffffff8));
  uVar8 = kthread_create_on_node(qcom_wdt_kthread,param_2,0xffffffff,param_3);
  *(ulong *)(param_2 + 0xd8) = uVar8;
  if (0xfffffffffffff000 < uVar8) goto LAB_00100f48;
  if (*(char *)(param_2 + 0x27) == '\0') {
    iVar5 = devm_request_threaded_irq
                      (*(undefined8 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x20),
                       qcom_wdt_bark_handler,0,0x4001,"apps_wdog_bark",param_2);
    if (iVar5 == 0) {
LAB_00100f24:
      *(undefined1 *)(wdog_data + 0x408) = 0;
      uVar10 = register_pm_notifier(&qcom_wdt_notif_block);
      uVar8 = uVar10 & 0xffffffff;
      if ((int)uVar10 == 0) {
        lVar9 = __msecs_to_jiffies(*(undefined4 *)(param_2 + 0x18));
        if (*(int *)((code *)**(undefined8 **)(param_2 + 0x10) + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100fc4);
          (*pcVar2)();
        }
        (*(code *)**(undefined8 **)(param_2 + 0x10))(*(undefined4 *)(param_2 + 0x1c),param_2);
        pcVar2 = *(code **)(*(long *)(param_2 + 0x10) + 8);
        if (*(int *)(pcVar2 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x100ff4);
          (*pcVar2)();
        }
        (*pcVar2)(*(int *)(param_2 + 0x1c) + 3000,param_2);
        puVar12 = (undefined8 *)(param_2 + 0x70);
        *puVar12 = qcom_wdt_panic_handler;
        *(undefined4 *)(param_2 + 0x80) = 0x7ffffffe;
        atomic_notifier_chain_register(&panic_notifier_list,puVar12);
        *(undefined4 *)(param_2 + 0x98) = 0x7ffffffe;
        puVar13 = (undefined8 *)(param_2 + 0x88);
        *puVar13 = qcom_wdt_die_handler;
        register_die_notifier(puVar13);
        puVar14 = (undefined8 *)(param_2 + 0xb8);
        *puVar14 = restart_wdog_handler;
        *(undefined4 *)(param_2 + 200) = 0xff;
        register_restart_handler(puVar14);
        __mutex_init(param_2 + 0x38,"&wdog_dd->disable_lock",&qcom_wdt_init___key);
        __init_waitqueue_head(param_2 + 0x118,"&wdog_dd->pet_complete",&qcom_wdt_init___key_22);
        *(undefined1 *)(param_2 + 0xd1) = 0;
        *(undefined4 *)(param_2 + 0x3cc) = 0;
        *(undefined2 *)(param_2 + 0x130) = 0x100;
        *(undefined1 *)(param_2 + 0x3c8) = 0;
        wake_up_process(*(undefined8 *)(param_2 + 0xd8));
        lVar1 = param_2 + 0xe0;
        init_timer_key(lVar1,qcom_wdt_pet_task_wakeup,0,0,0);
        *(long *)(param_2 + 0xf0) = _jiffies + lVar9;
        add_timer(lVar1);
        init_timer_key(param_2 + 0x3d0,qcom_wdt_user_pet_bite,0,0,0);
        uVar11 = 3;
        if (*(char *)(param_2 + 0x26) == '\0') {
          uVar11 = 1;
        }
        pcVar2 = *(code **)(*(long *)(param_2 + 0x10) + 0x18);
        if (*(int *)(pcVar2 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101130);
          (*pcVar2)();
        }
        uVar4 = (*pcVar2)(uVar11,param_2);
        if (uVar4 == 0) {
          pcVar2 = *(code **)(*(long *)(param_2 + 0x10) + 0x10);
          if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10115c);
            (*pcVar2)();
          }
          (*pcVar2)(param_2);
          uVar7 = sched_clock();
          *(undefined8 *)(param_2 + 0x28) = uVar7;
          *(undefined1 *)(param_2 + 0xd0) = 1;
          iVar5 = device_create_file(*(undefined8 *)(param_2 + 8),&dev_attr_disable);
          iVar6 = device_create_file(*(undefined8 *)(param_2 + 8),&dev_attr_wakeup_enable);
          if (iVar6 != 0 || iVar5 != 0) {
            _dev_err(*(undefined8 *)(param_2 + 8),"cannot create sysfs attribute\n");
          }
          if (*(char *)(param_2 + 0x27) != '\0') {
            enable_percpu_irq(*(undefined4 *)(param_2 + 0x20),0);
          }
          *(code **)(param_2 + 0xa0) = qcom_wdt_cpu_pm_notify;
          cpu_pm_register_notifier();
          _dev_info(*(undefined8 *)(param_2 + 8),"QCOM Apps Watchdog Initialized\n");
          lVar9 = (param_2 << 8) >> 8;
          uVar8 = lVar9 + 0x8000000000;
          local_70 = CONCAT62(local_70._2_6_,0x41);
          local_58 = _memstart_addr + uVar8;
          if (uVar8 >> 0x26 != 0) {
            local_58 = lVar9 - _kimage_voffset;
          }
          local_50 = 0x410;
          local_78[0] = s_KWDOGDATA_00101fa7[0];
          local_78[1] = s_KWDOGDATA_00101fa7[1];
          local_78[2] = s_KWDOGDATA_00101fa7[2];
          local_78[3] = s_KWDOGDATA_00101fa7[3];
          local_78[4] = s_KWDOGDATA_00101fa7[4];
          local_78[5] = s_KWDOGDATA_00101fa7[5];
          local_78[6] = s_KWDOGDATA_00101fa7[6];
          local_78[7] = s_KWDOGDATA_00101fa7[7];
          local_60 = param_2;
          iVar5 = msm_minidump_add_region(local_78);
          if (iVar5 < 0) {
            _dev_err(*(undefined8 *)(param_2 + 8),"Failed to add Wdt data in Minidump\n");
          }
          uVar8 = 0;
          goto LAB_00100f48;
        }
        uVar8 = (ulong)uVar4;
        atomic_notifier_chain_unregister(&panic_notifier_list,puVar12);
        unregister_die_notifier(puVar13);
        unregister_restart_handler(puVar14);
        if (*(char *)(param_2 + 0x27) != '\0') {
          free_percpu_irq(*(undefined4 *)(param_2 + 0x20),*(undefined8 *)(param_2 + 0x68));
          free_percpu(*(undefined8 *)(param_2 + 0x68));
        }
        del_timer_sync(lVar1);
        _dev_err(*(undefined8 *)(param_2 + 8),"Failed Initializing QCOM Apps Watchdog\n");
      }
    }
    else {
      _dev_err(*(undefined8 *)(param_2 + 8),"failed to request bark irq: %d\n",iVar5);
      uVar8 = 0xffffffea;
    }
  }
  else {
    lVar9 = __alloc_percpu(8,8);
    *(long *)(param_2 + 0x68) = lVar9;
    if (lVar9 == 0) {
      _dev_err(*(undefined8 *)(param_2 + 8),"failed to allocate cpu data\n");
      uVar8 = 0xfffffff4;
    }
    else {
      lVar1 = tpidr_el1;
      *(long *)(lVar1 + lVar9) = param_2;
      uVar4 = __request_percpu_irq
                        (*(undefined4 *)(param_2 + 0x20),qcom_wdt_ppi_bark,0,"apps_wdog_bark",
                         *(undefined8 *)(param_2 + 0x68));
      if (uVar4 == 0) goto LAB_00100f24;
      uVar8 = (ulong)uVar4;
      _dev_err(*(undefined8 *)(param_2 + 8),"failed to request bark irq\n");
      free_percpu(*(undefined8 *)(param_2 + 0x68));
    }
  }
  kthread_stop(*(undefined8 *)(param_2 + 0xd8));
LAB_00100f48:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_wdt_disable_get @ 001012fc size=108
// signature: undefined qcom_wdt_disable_get(void)
// callers: []
//------------------------------------------------------------

long qcom_wdt_disable_get(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  int iVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x98);
  lVar1 = lVar3 + 0x38;
  mutex_lock(lVar1);
  iVar2 = scnprintf(param_3,0x1000,&DAT_00102013,*(char *)(lVar3 + 0xd0) == '\0');
  mutex_unlock(lVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// qcom_wdt_disable_set @ 0010136c size=272
// signature: undefined qcom_wdt_disable_set(void)
// callers: []
//------------------------------------------------------------

long qcom_wdt_disable_set(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  char local_3c [4];
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  lVar2 = *(long *)(param_1 + 0x98);
  local_3c[0] = '\0';
  iVar1 = kstrtou8(param_3,10,local_3c);
  if (iVar1 == 0) {
    if (local_3c[0] == '\x01') {
      mutex_lock(lVar2 + 0x38);
      if (*(char *)(lVar2 + 0xd0) == '\0') {
        _dev_err(*(undefined8 *)(lVar2 + 8),"MSM Apps Watchdog already disabled\n");
      }
      else {
        iVar1 = qcom_scm_sec_wdog_deactivate();
        if (iVar1 != 0) {
          _dev_err(*(undefined8 *)(lVar2 + 8),"Failed to deactivate secure wdog, ret = %d\n",iVar1);
        }
        qcom_wdt_disable(lVar2);
      }
      mutex_unlock(lVar2 + 0x38);
    }
    else {
      _printk(&DAT_0010222a);
      param_4 = -0x16;
    }
  }
  else {
    _dev_err(*(undefined8 *)(lVar2 + 8),"invalid user input\n");
    param_4 = (long)iVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qcom_wdt_keep_alive_response @ 00101480 size=128
// signature: undefined qcom_wdt_keep_alive_response(void)
// callers: []
//------------------------------------------------------------

void qcom_wdt_keep_alive_response(long param_1)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  code *pcVar6;
  undefined8 uVar7;
  
  lVar5 = tpidr_el1;
  uVar2 = *(uint *)(&cpu_number + lVar5);
  puVar1 = (ulong *)(param_1 + 0x30 + (ulong)(uVar2 >> 6) * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar4) {
      *puVar1 = *puVar1 | 1L << ((ulong)uVar2 & 0x3f);
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  uVar7 = sched_clock();
  if (0x1f < uVar2) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x1014ec);
    (*pcVar6)();
  }
  *(undefined8 *)(param_1 + (ulong)uVar2 * 8 + 0x248) = uVar7;
  DataMemoryBarrier(2,3);
  return;
}



//------------------------------------------------------------
// qcom_wdt_ppi_bark @ 0010150c size=40
// signature: undefined qcom_wdt_ppi_bark(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_wdt_ppi_bark(undefined8 param_1,long param_2)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  qcom_wdt_bark_handler(param_1,*(undefined8 *)(lVar1 + param_2));
  return 1;
}



//------------------------------------------------------------
// qcom_wdt_bark_handler @ 00101538 size=288
// signature: undefined qcom_wdt_bark_handler(void)
// callers: [qcom_wdt_ppi_bark]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_wdt_bark_handler(undefined8 param_1,long param_2)

{
  char cVar1;
  ulong uVar2;
  ulong uVar3;
  
  uVar2 = sched_clock();
  uVar3 = *(ulong *)(param_2 + 0x28);
  _dev_info(*(undefined8 *)(param_2 + 8),"QCOM Apps Watchdog bark! Now = %lu.%06lu\n",
            uVar2 / 1000000000,
            (ulong)(uint)((int)uVar2 + (int)(uVar2 / 1000000000) * -1000000000) / 1000);
  uVar2 = uVar3 / 1000000000;
  _dev_info(*(undefined8 *)(param_2 + 8),"QCOM Apps Watchdog last pet at %lu.%06lu\n",uVar2,
            (ulong)(uint)((int)uVar3 + (int)uVar2 * -1000000000) / 1000);
  if (*(char *)(param_2 + 0x24) == '\0') {
    cVar1 = *(char *)(param_2 + 0x3c8);
  }
  else {
    scnprintf(qcom_wdt_dump_cpu_alive_mask_alive_mask_buf,0x20,"%*pb1",_nr_cpu_ids,param_2 + 0x30);
    _dev_info(*(undefined8 *)(param_2 + 8),"cpu alive mask from last pet %s\n",
              qcom_wdt_dump_cpu_alive_mask_alive_mask_buf);
    cVar1 = *(char *)(param_2 + 0x3c8);
  }
  if (cVar1 != '\0') {
    _dev_info(*(undefined8 *)(param_2 + 8),"Suspend in progress\n");
  }
  md_dump_process();
  qcom_wdt_trigger_bite();
  return 1;
}



//------------------------------------------------------------
// qcom_wdt_panic_handler @ 0010165c size=252
// signature: undefined qcom_wdt_panic_handler(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_wdt_panic_handler(long param_1)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  lVar3 = param_1 + -0x70;
  *(undefined1 *)(param_1 + -0x4b) = 1;
  iVar1 = _panic_timeout;
  if (_panic_timeout == 0) {
    pcVar2 = *(code **)(*(long *)(param_1 + -0x60) + 0x20);
    if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10173c);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
  }
  else {
    pcVar2 = *(code **)(*(long *)(param_1 + -0x60) + 0x10);
    if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1016b0);
      (*pcVar2)();
    }
    (*pcVar2)(lVar3);
    iVar1 = iVar1 * 1000 + 10000;
    if (*(int *)((code *)**(undefined8 **)(param_1 + -0x60) + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1016e8);
      (*pcVar2)();
    }
    (*(code *)**(undefined8 **)(param_1 + -0x60))(iVar1,lVar3);
    pcVar2 = *(code **)(*(long *)(param_1 + -0x60) + 8);
    if (*(int *)(pcVar2 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101714);
      (*pcVar2)();
    }
    (*pcVar2)(iVar1,lVar3);
  }
  return 0;
}



//------------------------------------------------------------
// restart_wdog_handler @ 0010175c size=56
// signature: undefined restart_wdog_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 restart_wdog_handler(long param_1)

{
  if (*(char *)(param_1 + -0x93) != '\0') {
    _printk(&DAT_00101f8f);
    qcom_wdt_trigger_bite();
  }
  return 0;
}



//------------------------------------------------------------
// qcom_wdt_pet_task_wakeup @ 00101798 size=76
// signature: undefined qcom_wdt_pet_task_wakeup(void)
// callers: []
//------------------------------------------------------------

void qcom_wdt_pet_task_wakeup(long param_1)

{
  undefined8 uVar1;
  
  *(undefined1 *)(param_1 + 0x50) = 1;
  uVar1 = sched_clock();
  *(undefined8 *)(param_1 + 0x58) = uVar1;
  __wake_up(param_1 + 0x38,3,1,0);
  return;
}



//------------------------------------------------------------
// qcom_wdt_user_pet_bite @ 001017e8 size=64
// signature: undefined qcom_wdt_user_pet_bite(void)
// callers: []
//------------------------------------------------------------

void qcom_wdt_user_pet_bite(long param_1)

{
  if (*(char *)(param_1 + -0x29f) == '\0') {
    _dev_info(*(undefined8 *)(param_1 + -0x3c8),"QCOM Apps Watchdog user pet timeout!\n");
    qcom_wdt_trigger_bite();
  }
  return;
}



//------------------------------------------------------------
// qcom_wdt_cpu_pm_notify @ 0010182c size=80
// signature: undefined qcom_wdt_cpu_pm_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_wdt_cpu_pm_notify(long param_1,long param_2)

{
  uint uVar1;
  long lVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  lVar2 = tpidr_el1;
  uVar1 = *(uint *)(&cpu_number + lVar2);
  if (param_2 - 1U < 2) {
    if (0x1f < uVar1) {
LAB_00101878:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10187c);
      (*pcVar3)();
    }
    uVar4 = 0;
  }
  else {
    if (param_2 != 0) {
      return 1;
    }
    if (0x1f < uVar1) goto LAB_00101878;
    uVar4 = 1;
  }
  *(undefined4 *)(param_1 + (ulong)uVar1 * 4 + 0x2a8) = uVar4;
  return 1;
}



//------------------------------------------------------------
// qcom_wdt_hibernation_notifier @ 00101880 size=48
// signature: undefined qcom_wdt_hibernation_notifier(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_wdt_hibernation_notifier(undefined8 param_1,long param_2)

{
  undefined1 uVar1;
  
  if (param_2 == 1) {
    uVar1 = 1;
  }
  else {
    if (param_2 != 2) {
      return 1;
    }
    uVar1 = 0;
  }
  *(undefined1 *)(wdog_data + 0x408) = uVar1;
  return 1;
}



//------------------------------------------------------------
// qcom_wdt_die_handler @ 001018b4 size=172
// signature: undefined qcom_wdt_die_handler(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_wdt_die_handler(long param_1)

{
  code *pcVar1;
  long lVar2;
  
  lVar2 = param_1 + -0x88;
  pcVar1 = *(code **)(*(long *)(param_1 + -0x78) + 0x10);
  if (*(int *)(pcVar1 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1018f0);
    (*pcVar1)();
  }
  (*pcVar1)(lVar2);
  if (*(int *)((code *)**(undefined8 **)(param_1 + -0x78) + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10191c);
    (*pcVar1)();
  }
  (*(code *)**(undefined8 **)(param_1 + -0x78))(15000,lVar2);
  pcVar1 = *(code **)(*(long *)(param_1 + -0x78) + 8);
  if (*(int *)(pcVar1 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x101948);
    (*pcVar1)();
  }
  (*pcVar1)(15000,lVar2);
  return 0;
}



//------------------------------------------------------------
// wakeup_enable_show @ 00101964 size=60
// signature: undefined wakeup_enable_show(void)
// callers: []
//------------------------------------------------------------

long wakeup_enable_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00102013,*(undefined1 *)(*(long *)(param_1 + 0x98) + 0x26));
  return (long)iVar1;
}



//------------------------------------------------------------
// wakeup_enable_store @ 001019a4 size=272
// signature: undefined wakeup_enable_store(void)
// callers: []
//------------------------------------------------------------

long wakeup_enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  long lVar4;
  byte local_3c [4];
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(param_1 + 0x98);
  local_3c[0] = 0;
  iVar1 = kstrtou8(param_3,10,local_3c);
  if ((iVar1 == 0) && (local_3c[0] < 2)) {
    mutex_lock(lVar4 + 0x38);
    *(bool *)(lVar4 + 0x26) = local_3c[0] != 0;
    if (*(char *)(lVar4 + 0xd0) != '\0') {
      uVar2 = 3;
      if (local_3c[0] == 0) {
        uVar2 = 1;
      }
      pcVar3 = *(code **)(*(long *)(lVar4 + 0x10) + 0x18);
      if (*(int *)(pcVar3 + -4) != -0x489932bd) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x101a50);
        (*pcVar3)();
      }
      (*pcVar3)(uVar2,lVar4);
    }
    mutex_unlock(lVar4 + 0x38);
  }
  else {
    _dev_err(*(undefined8 *)(lVar4 + 8),"invalid user input\n");
    if (iVar1 == 0) {
      iVar1 = -0x16;
    }
    param_4 = (long)iVar1;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// qcom_wdt_kthread @ 00101b2c size=860
// signature: undefined qcom_wdt_kthread(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 qcom_wdt_kthread(long param_1)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  undefined8 uVar7;
  int iVar8;
  long local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  sched_param local_70 [2];
  long local_68;
  
  lVar1 = sp_el0;
  local_68 = *(long *)(lVar1 + 0x638);
  uVar7 = sp_el0;
  local_70[0].__sched_priority = 99;
  iVar3 = sched_setscheduler((__pid_t)uVar7,1,local_70);
  uVar5 = kthread_should_stop(iVar3);
  if ((uVar5 & 1) == 0) {
    lVar1 = param_1 + 0x118;
    local_a0 = 0;
LAB_00101c10:
    do {
      if (*(char *)(param_1 + 0x130) == '\0') {
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        init_wait_entry(&local_98,0);
        while (lVar6 = prepare_to_wait_event(lVar1,&local_98,1), *(char *)(param_1 + 0x130) == '\0')
        {
          if (lVar6 != 0) {
            if ((int)lVar6 == 0) goto LAB_00101c60;
            goto LAB_00101c10;
          }
          schedule();
        }
        finish_wait(lVar1,&local_98);
      }
LAB_00101c60:
      uVar7 = sched_clock();
      iVar3 = 0;
      *(undefined8 *)(param_1 + 0x140) = uVar7;
      while (uVar4 = _find_next_bit(&__cpu_present_mask,_nr_cpu_ids,(long)iVar3),
            uVar4 < _nr_cpu_ids) {
        if ((uVar4 & 0xffffffe0) != 0) goto LAB_00101e80;
        lVar6 = param_1 + (ulong)uVar4 * 8;
        iVar3 = uVar4 + 1;
        *(undefined8 *)(lVar6 + 0x248) = 0;
        *(undefined8 *)(lVar6 + 0x148) = 0;
      }
      if (*(char *)(param_1 + 0x24) != '\0') {
        memset((void *)(param_1 + 0x30),0,(ulong)(_nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8));
        DataMemoryBarrier(2,3);
        lVar6 = 0;
        while( true ) {
          uVar5 = _find_next_bit(&__cpu_online_mask,_nr_cpu_ids,(long)(int)lVar6);
          uVar4 = (uint)uVar5;
          if (_nr_cpu_ids <= uVar4) break;
          if ((uVar5 >> 5 & 0x7ffffff) != 0) {
LAB_00101e80:
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101e84);
            (*pcVar2)();
          }
          if (*(int *)(param_1 + (long)(int)uVar4 * 4 + 0x348) == 0) {
            uVar7 = sched_clock();
            *(undefined8 *)(param_1 + (long)(int)uVar4 * 8 + 0x148) = uVar7;
            smp_call_function_single(uVar5 & 0xffffffff,qcom_wdt_keep_alive_response,param_1,1);
          }
          lVar6 = uVar5 + 1;
        }
      }
      while (*(char *)(param_1 + 0x131) == '\0') {
        local_80 = 0;
        uStack_78 = 0;
        local_90 = 0;
        uStack_88 = 0;
        local_98 = 0;
        init_wait_entry(&local_98,0);
        while( true ) {
          lVar6 = prepare_to_wait_event(lVar1,&local_98,1);
          if (*(char *)(param_1 + 0x131) != '\0') {
            finish_wait(lVar1,&local_98);
            goto LAB_00101d94;
          }
          if (lVar6 != 0) break;
          schedule();
        }
        if ((int)lVar6 == 0) break;
      }
LAB_00101d94:
      *(undefined1 *)(param_1 + 0x130) = 0;
      *(byte *)(param_1 + 0x131) = *(byte *)(param_1 + 0xd1) ^ 1;
      if (*(char *)(param_1 + 0xd0) != '\0') {
        local_a0 = __msecs_to_jiffies(*(undefined4 *)(param_1 + 0x18));
        pcVar2 = *(code **)(*(long *)(param_1 + 0x10) + 0x10);
        if (*(int *)(pcVar2 + -4) != -0x76982c84) {
                    /* WARNING: Does not return */
          pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x101ddc);
          (*pcVar2)();
        }
        (*pcVar2)(param_1);
        uVar7 = sched_clock();
        *(undefined8 *)(param_1 + 0x28) = uVar7;
      }
      uVar5 = kthread_should_stop();
      if ((uVar5 & 1) == 0) {
        _raw_spin_lock(param_1 + 0x3cc);
        if (*(char *)(param_1 + 0x3c8) == '\0') {
          mod_timer(param_1 + 0xe0,_jiffies + local_a0);
        }
        _raw_spin_unlock(param_1 + 0x3cc);
      }
      iVar3 = nr_ipi_get();
      __rcu_read_lock();
      if (0 < _nr_irqs) {
        iVar8 = 0;
        do {
          if ((iVar3 < iVar8) && (lVar6 = irq_to_desc(iVar8), lVar6 != 0)) {
            uVar5 = kstat_irqs_usr(iVar8);
            *(ulong *)(lVar6 + 0x1c8) = uVar5 & 0xffffffff;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < _nr_irqs);
      }
      __rcu_read_unlock();
      uVar5 = kthread_should_stop();
    } while ((uVar5 & 1) == 0);
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// del_timer_sync @ 00104000 size=1
// signature: undefined del_timer_sync(void)
// callers: [qcom_wdt_pet_suspend, qcom_wdt_remove, qcom_wdt_disable, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void del_timer_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00104008 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [qcom_wdt_pet_suspend, qcom_wdt_kthread, qcom_wdt_pet_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00104010 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [qcom_wdt_pet_suspend, qcom_wdt_kthread, qcom_wdt_pet_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00104020 size=1
// signature: undefined sched_clock(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_pet_suspend, qcom_wdt_pet_task_wakeup, qcom_wdt_keep_alive_response, qcom_wdt_register, qcom_wdt_kthread, qcom_wdt_pet_resume, qcom_wdt_bark_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00104030 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [qcom_wdt_register, qcom_wdt_kthread, qcom_wdt_pet_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// add_timer @ 00104038 size=1
// signature: undefined add_timer(void)
// callers: [qcom_wdt_register, qcom_wdt_pet_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void add_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_unregister_notifier @ 00104040 size=1
// signature: undefined cpu_pm_unregister_notifier(void)
// callers: [qcom_wdt_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00104048 size=1
// signature: undefined mutex_lock(void)
// callers: [qcom_wdt_remove, qcom_wdt_disable_get, wakeup_enable_store, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00104050 size=1
// signature: undefined mutex_unlock(void)
// callers: [qcom_wdt_remove, qcom_wdt_disable_get, wakeup_enable_store, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_remove_file @ 00104058 size=1
// signature: undefined device_remove_file(void)
// callers: [qcom_wdt_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_remove_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu @ 00104060 size=1
// signature: undefined free_percpu(void)
// callers: [qcom_wdt_remove, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_dispose_mapping @ 00104068 size=1
// signature: undefined irq_dispose_mapping(void)
// callers: [qcom_wdt_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_dispose_mapping(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00104070 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_wdt_remove, qcom_wdt_register, qcom_wdt_bark_handler, qcom_wdt_user_pet_bite]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_stop @ 00104078 size=1
// signature: undefined kthread_stop(void)
// callers: [qcom_wdt_remove, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_free_irq @ 00104080 size=1
// signature: undefined devm_free_irq(void)
// callers: [qcom_wdt_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_percpu_irq @ 00104088 size=1
// signature: undefined disable_percpu_irq(void)
// callers: [qcom_wdt_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_percpu_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu_irq @ 00104090 size=1
// signature: undefined free_percpu_irq(void)
// callers: [qcom_wdt_disable, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_unregister @ 001040a0 size=1
// signature: undefined atomic_notifier_chain_unregister(void)
// callers: [qcom_wdt_disable, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_die_notifier @ 001040a8 size=1
// signature: undefined unregister_die_notifier(void)
// callers: [qcom_wdt_disable, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_die_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// unregister_restart_handler @ 001040b0 size=1
// signature: undefined unregister_restart_handler(void)
// callers: [qcom_wdt_disable, qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void unregister_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001040b8 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_disable, qcom_wdt_register, wakeup_enable_store, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nr_ipi_get @ 001040c0 size=1
// signature: undefined nr_ipi_get(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nr_ipi_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 001040c8 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_to_desc @ 001040d8 size=1
// signature: undefined irq_to_desc(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstat_irqs_usr @ 001040e0 size=1
// signature: undefined kstat_irqs_usr(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstat_irqs_usr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 001040e8 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001040f0 size=1
// signature: undefined _printk(void)
// callers: [qcom_wdt_trigger_bite, restart_wdog_handler, qcom_wdt_register, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001040f8 size=1
// signature: undefined __const_udelay(void)
// callers: [qcom_wdt_trigger_bite]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00104100 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_wdt_trigger_bite, qcom_wdt_register, qcom_wdt_kthread, wakeup_enable_store, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00104108 size=1
// signature: undefined platform_get_irq(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_check_status_bit @ 00104110 size=1
// signature: undefined irq_check_status_bit(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_check_status_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00104120 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_wdt_register, qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 00104128 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_percpu @ 00104130 size=1
// signature: undefined __alloc_percpu(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __request_percpu_irq @ 00104138 size=1
// signature: undefined __request_percpu_irq(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __request_percpu_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_request_threaded_irq @ 00104140 size=1
// signature: undefined devm_request_threaded_irq(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_pm_notifier @ 00104148 size=1
// signature: undefined register_pm_notifier(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_pm_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// atomic_notifier_chain_register @ 00104150 size=1
// signature: undefined atomic_notifier_chain_register(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void atomic_notifier_chain_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_die_notifier @ 00104158 size=1
// signature: undefined register_die_notifier(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_die_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// register_restart_handler @ 00104160 size=1
// signature: undefined register_restart_handler(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void register_restart_handler(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00104168 size=1
// signature: undefined __mutex_init(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_waitqueue_head @ 00104170 size=1
// signature: undefined __init_waitqueue_head(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_waitqueue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 00104178 size=1
// signature: undefined wake_up_process(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_timer_key @ 00104180 size=1
// signature: undefined init_timer_key(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_timer_key(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_create_file @ 00104188 size=1
// signature: undefined device_create_file(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_create_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_percpu_irq @ 00104190 size=1
// signature: undefined enable_percpu_irq(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_percpu_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_register_notifier @ 00104198 size=1
// signature: undefined cpu_pm_register_notifier(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// msm_minidump_add_region @ 001041b0 size=1
// signature: undefined msm_minidump_add_region(void)
// callers: [qcom_wdt_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void msm_minidump_add_region(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_setscheduler @ 001041b8 size=1
// signature: int sched_setscheduler(__pid_t __pid, int __policy, sched_param * __param)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sched_setscheduler(__pid_t __pid,int __policy,sched_param *__param)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 001041c0 size=1
// signature: undefined kthread_should_stop(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// init_wait_entry @ 001041d8 size=1
// signature: undefined init_wait_entry(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void init_wait_entry(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// prepare_to_wait_event @ 001041e0 size=1
// signature: undefined prepare_to_wait_event(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void prepare_to_wait_event(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 001041e8 size=1
// signature: undefined schedule(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// finish_wait @ 001041f0 size=1
// signature: undefined finish_wait(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void finish_wait(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001041f8 size=1
// signature: undefined _find_next_bit(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 00104200 size=1
// signature: undefined smp_call_function_single(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mod_timer @ 00104208 size=1
// signature: undefined mod_timer(void)
// callers: [qcom_wdt_kthread]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mod_timer(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00104210 size=1
// signature: undefined scnprintf(void)
// callers: [wakeup_enable_show, qcom_wdt_disable_get, qcom_wdt_bark_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtou8 @ 00104218 size=1
// signature: undefined kstrtou8(void)
// callers: [wakeup_enable_store, qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtou8(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_scm_sec_wdog_deactivate @ 00104220 size=1
// signature: undefined qcom_scm_sec_wdog_deactivate(void)
// callers: [qcom_wdt_disable_set]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_scm_sec_wdog_deactivate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// md_dump_process @ 00104238 size=1
// signature: undefined md_dump_process(void)
// callers: [qcom_wdt_bark_handler]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void md_dump_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __wake_up @ 00104248 size=1
// signature: undefined __wake_up(void)
// callers: [qcom_wdt_pet_task_wakeup]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __wake_up(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



