// Decompiled by Ghidra 12.2
// Program: msm_sysstats.ko
// Image base: 00100000

//------------------------------------------------------------
// sysstats_register_kgsl_stats_cb @ 001003c4 size=12
// signature: undefined sysstats_register_kgsl_stats_cb(void)
// callers: []
//------------------------------------------------------------

void sysstats_register_kgsl_stats_cb(undefined8 param_1)

{
  sysstats_kgsl_get_stats = param_1;
  return;
}



//------------------------------------------------------------
// sysstats_unregister_kgsl_stats_cb @ 001003d4 size=20
// signature: undefined sysstats_unregister_kgsl_stats_cb(void)
// callers: []
//------------------------------------------------------------

void sysstats_unregister_kgsl_stats_cb(void)

{
  sysstats_kgsl_get_stats = sysstats_kgsl_stats;
  return;
}



//------------------------------------------------------------
// sysstats_kgsl_stats @ 001003ec size=8
// signature: undefined sysstats_kgsl_stats(void)
// callers: []
//------------------------------------------------------------

undefined8 sysstats_kgsl_stats(void)

{
  return 0;
}



//------------------------------------------------------------
// sysstats_pre_doit @ 001003f8 size=112
// signature: undefined sysstats_pre_doit(void)
// callers: []
//------------------------------------------------------------

undefined8 sysstats_pre_doit(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  char cVar2;
  undefined8 uVar3;
  undefined1 *puVar4;
  
  cVar2 = *(char *)(param_1 + 0x2c);
  if (cVar2 != '\x05') {
    if (cVar2 == '\x03') {
      puVar4 = (undefined1 *)0x0;
      goto LAB_00100430;
    }
    if (cVar2 != '\x01') {
      return 0xffffffea;
    }
  }
  puVar4 = sysstats_cmd_get_policy;
LAB_00100430:
  uVar1 = **(uint **)(param_3 + 8);
  if (uVar1 < 0x14) {
    return 0xffffffea;
  }
  uVar3 = __nla_validate(*(uint **)(param_3 + 8) + 5,uVar1 - 0x14,3,puVar4,0,
                         *(undefined8 *)(param_3 + 0x40));
  return uVar3;
}



//------------------------------------------------------------
// sysstats_task_user_cmd @ 0010046c size=1732
// signature: undefined sysstats_task_user_cmd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int sysstats_task_user_cmd(undefined8 param_1,long param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  long lVar11;
  long lVar12;
  ulong uVar13;
  long lVar14;
  undefined8 uVar15;
  long *plVar16;
  long *plVar17;
  long lVar18;
  undefined8 uVar19;
  undefined8 *puVar20;
  long *plVar21;
  long local_78;
  ulong local_70;
  long local_68;
  
  lVar5 = sp_el0;
  local_68 = *(long *)(lVar5 + 0x638);
  if (*(long *)(*(long *)(param_2 + 0x20) + 8) == 0) {
    iVar9 = -0x16;
  }
  else {
    local_78 = 0;
    iVar9 = prepare_reply(param_2,2,&local_78,0x9c);
    lVar5 = local_78;
    if (-1 < iVar9) {
      uVar10 = *(undefined4 *)(*(long *)(*(long *)(param_2 + 0x20) + 8) + 4);
      lVar11 = nla_reserve_64bit(local_78,1,0x98,2);
      if (lVar11 == 0) {
        iVar9 = -0x16;
      }
      else {
        __rcu_read_lock();
        lVar12 = find_task_by_vpid(uVar10);
        if (lVar12 != 0) {
          puVar1 = (uint *)(lVar12 + 0x40);
LAB_00100a70:
          Hint_Prefetch(puVar1,2,0,1);
          do {
            uVar3 = *puVar1;
            cVar4 = '\x01';
            bVar8 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar8) {
              *puVar1 = uVar3 + 1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          if (uVar3 == 0) {
            uVar15 = 2;
LAB_00100a90:
            refcount_warn_saturate(puVar1,uVar15);
          }
          else if ((int)(uVar3 + 1 | uVar3) < 0) {
            uVar15 = 1;
            goto LAB_00100a90;
          }
          __rcu_read_unlock();
          lVar6 = sp_el0;
          *(undefined8 *)(lVar11 + 0x8c) = 0;
          *(undefined8 *)(lVar11 + 0x94) = 0;
          *(undefined8 *)(lVar11 + 0x7c) = 0;
          *(undefined8 *)(lVar11 + 0x84) = 0;
          *(undefined8 *)(lVar11 + 0x6c) = 0;
          *(undefined8 *)(lVar11 + 0x74) = 0;
          *(undefined8 *)(lVar11 + 0x5c) = 0;
          *(undefined8 *)(lVar11 + 100) = 0;
          *(undefined8 *)(lVar11 + 0x4c) = 0;
          *(undefined8 *)(lVar11 + 0x54) = 0;
          *(undefined8 *)(lVar11 + 0x3c) = 0;
          *(undefined8 *)(lVar11 + 0x44) = 0;
          *(undefined8 *)(lVar11 + 0x2c) = 0;
          *(undefined8 *)(lVar11 + 0x34) = 0;
          *(undefined8 *)(lVar11 + 0x1c) = 0;
          *(undefined8 *)(lVar11 + 0x24) = 0;
          *(undefined8 *)(lVar11 + 0xc) = 0;
          *(undefined8 *)(lVar11 + 0x14) = 0;
          *(undefined8 *)(lVar11 + 4) = 0;
          uVar15 = task_active_pid_ns(lVar6);
          uVar10 = __task_pid_nr_ns(lVar12,0,uVar15);
          *(undefined4 *)(lVar11 + 0x50) = uVar10;
          __rcu_read_lock();
          plVar16 = (long *)(*(long *)(lVar12 + 0x890) + 0x10);
          plVar21 = (long *)*plVar16;
          if (plVar21 != plVar16) {
            do {
              plVar16 = plVar21 + 0x46;
              _raw_spin_lock(plVar16);
              plVar17 = plVar21 + -0x2a;
              if (*plVar17 != 0) {
                __rcu_read_unlock();
                if (plVar21 == (long *)0x6f0) goto LAB_00100738;
                lVar14 = 0;
                lVar18 = *(long *)(*plVar17 + 0x2d8);
                if (lVar18 < 1) {
                  lVar18 = 0;
                }
                *(long *)(lVar11 + 4) = lVar18 << 2;
                lVar18 = *(long *)(*plVar17 + 0x2d0);
                if (lVar18 < 1) {
                  lVar18 = 0;
                }
                *(long *)(lVar11 + 0xc) = lVar18 << 2;
                lVar18 = *(long *)(*plVar17 + 0x2e8);
                if (lVar18 < 1) {
                  lVar18 = 0;
                }
                *(long *)(lVar11 + 0x1c) = lVar18 << 2;
                lVar18 = *(long *)(*plVar17 + 0x2e0);
                if (lVar18 < 1) {
                  lVar18 = 0;
                }
                *(long *)(lVar11 + 0x14) = lVar18 << 2;
                local_70 = 0;
                plVar17 = (long *)(plVar21[0x34] + 0x10);
                goto LAB_00100670;
              }
              _raw_spin_unlock(plVar16);
              plVar21 = (long *)*plVar21;
            } while (plVar21 != (long *)(*(long *)(lVar12 + 0x890) + 0x10));
          }
          __rcu_read_unlock();
          goto LAB_00100738;
        }
        __rcu_read_unlock();
        iVar9 = -3;
      }
      kfree_skb_reason(lVar5,1);
    }
  }
LAB_00100afc:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar9;
LAB_00100670:
  do {
    plVar17 = (long *)*plVar17;
    if (plVar17 == (long *)(plVar21[0x34] + 0x10)) break;
    if (plVar17 != plVar21) {
      _raw_spin_lock(plVar17 + 0x46);
    }
    if (lVar14 == 0) {
      lVar14 = *(long *)(plVar21[-0x10] + 0x878);
      lVar18 = plVar17[0x31];
      if (lVar18 != 0) goto LAB_001006a0;
LAB_001006d8:
      iVar9 = 0;
    }
    else {
      lVar18 = plVar17[0x31];
      if (lVar18 == 0) goto LAB_001006d8;
LAB_001006a0:
      if ((lVar14 == lVar18) && (plVar17 + -0xde != (long *)plVar21[-0x10])) goto LAB_001006d8;
      iVar9 = iterate_fd(lVar18,0,get_dma_info,&local_70);
    }
    if (plVar17 != plVar21) {
      _raw_spin_unlock(plVar17 + 0x46);
    }
  } while (iVar9 == 0);
  *(ulong *)(lVar11 + 0x24) = local_70 >> 10 & 0x3ffffffffffffc;
  _raw_spin_unlock(plVar16);
LAB_00100738:
  if (*(int *)(sysstats_kgsl_get_stats + -4) != -0x531f1262) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x10075c);
    (*pcVar7)();
  }
  uVar13 = (*sysstats_kgsl_get_stats)(*(undefined4 *)(lVar11 + 0x50));
  *(ulong *)(lVar11 + 0x24) = *(long *)(lVar11 + 0x24) + (uVar13 >> 10);
  uVar13 = *(ulong *)(lVar12 + 0x728);
  *(ulong *)(lVar11 + 0x2c) = *(ulong *)(lVar12 + 0x720) / 1000;
  *(ulong *)(lVar11 + 0x34) = uVar13 / 1000;
  __rcu_read_lock();
  lVar18 = *(long *)(lVar12 + 0x898);
  while (lVar18 != 0) {
    uVar15 = _raw_spin_lock_irqsave(lVar18);
    if (lVar18 == *(long *)(lVar12 + 0x898)) {
      __rcu_read_unlock();
      lVar18 = *(long *)(lVar12 + 0x890);
      *(undefined8 *)(lVar11 + 0x3c) = *(undefined8 *)(lVar18 + 0x1c0);
      *(undefined8 *)(lVar11 + 0x44) = *(undefined8 *)(lVar18 + 0x1c8);
      _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar12 + 0x898),uVar15);
      goto LAB_00100808;
    }
    _raw_spin_unlock_irqrestore(lVar18,uVar15);
    lVar18 = *(long *)(lVar12 + 0x898);
  }
  __rcu_read_unlock();
LAB_00100808:
  __rcu_read_lock();
  iVar2 = *(int *)(*(long *)(lVar12 + 0x830) + 4);
  iVar9 = _overflowuid;
  if (iVar2 != -1) {
    iVar9 = iVar2;
  }
  *(int *)(lVar11 + 0x54) = iVar9;
  if (*(long *)(lVar12 + 0x698) == 0) {
    uVar10 = 0;
  }
  else {
    uVar19 = *(undefined8 *)(lVar12 + 0x640);
    uVar15 = task_active_pid_ns(lVar6);
    uVar10 = __task_pid_nr_ns(uVar19,1,uVar15);
  }
  *(undefined4 *)(lVar11 + 0x58) = uVar10;
  __rcu_read_unlock();
  uVar13 = strnlen((char *)(lVar12 + 0x848),0x10);
  if ((uVar13 < 0x10) || (uVar13 == 0x20)) {
    if (uVar13 != 0x20) {
      uVar13 = uVar13 + 1;
    }
    if (uVar13 < 0x21) goto code_r0x0010088c;
  }
  else {
    fortify_panic("strnlen");
  }
  fortify_panic("strscpy");
  goto LAB_00100a70;
code_r0x0010088c:
  strscpy(lVar11 + 0x5c,(char *)(lVar12 + 0x848));
  __rcu_read_lock();
  while( true ) {
    puVar20 = (undefined8 *)**(undefined8 **)(lVar12 + 0xa18);
    if ((*(byte *)((long)puVar20 + 0x54) & 1) != 0) goto LAB_00100960;
    __rcu_read_lock();
    uVar13 = puVar20[2];
    if ((uVar13 & 3) == 0) break;
    plVar16 = (long *)puVar20[3];
    lVar18 = *plVar16;
    while (lVar18 != 0) {
      Hint_Prefetch(plVar16,2,0,1);
      do {
        lVar14 = *plVar16;
        if (lVar14 != lVar18) goto LAB_001008e0;
        cVar4 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(plVar16,0x10);
        if (bVar8) {
          *plVar16 = lVar18 + 1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
LAB_001008e0:
      bVar8 = lVar14 == lVar18;
      lVar18 = lVar14;
      if (bVar8) goto LAB_0010095c;
    }
    __rcu_read_unlock();
    Yield();
  }
  *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
  lVar18 = tpidr_el1;
  plVar16 = (long *)(lVar18 + uVar13);
  do {
    cVar4 = '\x01';
    bVar8 = (bool)ExclusiveMonitorPass(plVar16,0x10);
    if (bVar8) {
      *plVar16 = *plVar16 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  lVar18 = *(long *)(lVar6 + 0x10) + -1;
  *(int *)(lVar6 + 0x10) = (int)lVar18;
  if ((lVar18 == 0) || (*(long *)(lVar6 + 0x10) == 0)) {
    preempt_schedule_notrace();
  }
LAB_0010095c:
  __rcu_read_unlock();
LAB_00100960:
  __rcu_read_unlock();
  cgroup_path_ns(*puVar20,lVar11 + 0x7c,0x20,*(undefined8 *)(*(long *)(lVar6 + 0x888) + 0x40));
  if ((*(byte *)((long)puVar20 + 0x54) & 1) == 0) {
    __rcu_read_lock();
    uVar13 = puVar20[2];
    if ((uVar13 & 3) == 0) {
      *(int *)(lVar6 + 0x10) = *(int *)(lVar6 + 0x10) + 1;
      lVar11 = tpidr_el1;
      plVar16 = (long *)(lVar11 + uVar13);
      do {
        cVar4 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(plVar16,0x10);
        if (bVar8) {
          *plVar16 = *plVar16 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      lVar11 = *(long *)(lVar6 + 0x10) + -1;
      *(int *)(lVar6 + 0x10) = (int)lVar11;
      if ((lVar11 == 0) || (*(long *)(lVar6 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
    }
    else {
      plVar16 = (long *)puVar20[3];
      Hint_Prefetch(plVar16,2,0,1);
      do {
        lVar11 = *plVar16;
        cVar4 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(plVar16,0x10);
        if (bVar8) {
          *plVar16 = lVar11 + -1;
          cVar4 = ExclusiveMonitorsStatus();
        }
      } while (cVar4 != '\0');
      DataMemoryBarrier(2,3);
      if (lVar11 + -1 == 0) {
        if (*(int *)(*(code **)(puVar20[3] + 8) + -4) != 0x173118d3) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x100a50);
          (*pcVar7)();
        }
        (**(code **)(puVar20[3] + 8))();
      }
    }
    __rcu_read_unlock();
  }
  Hint_Prefetch(puVar1,2,0,1);
  do {
    uVar3 = *puVar1;
    cVar4 = '\x01';
    bVar8 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar8) {
      *puVar1 = uVar3 - 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if (uVar3 == 1) {
    DataMemoryBarrier(2,1);
    __put_task_struct(lVar12);
  }
  else if ((int)uVar3 < 1) {
    refcount_warn_saturate(puVar1,3);
  }
  **(int **)(lVar5 + 0xe0) =
       (*(int *)(lVar5 + 0xd8) + *(int *)(lVar5 + 0xd0)) - (int)*(int **)(lVar5 + 0xe0);
  iVar9 = netlink_unicast(*(undefined8 *)(*(long *)(param_2 + 0x28) + 0x118),lVar5,
                          *(undefined4 *)(param_2 + 4),0x40);
  if (-1 < iVar9) {
    iVar9 = 0;
  }
  goto LAB_00100afc;
}



//------------------------------------------------------------
// sysstats_task_foreach @ 00100b74 size=1100
// signature: undefined sysstats_task_foreach(void)
// callers: []
//------------------------------------------------------------

void sysstats_task_foreach(long param_1,long *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  char cVar5;
  undefined8 uVar6;
  code *pcVar7;
  bool bVar8;
  bool bVar9;
  undefined4 uVar10;
  int iVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  undefined8 uVar16;
  long *plVar17;
  long lVar18;
  long *plVar19;
  long lVar20;
  ulong uVar21;
  long *plVar22;
  undefined1 auVar23 [16];
  ulong local_70;
  long local_68;
  
  lVar13 = sp_el0;
  local_68 = *(long *)(lVar13 + 0x638);
  uVar6 = sp_el0;
  uVar12 = task_active_pid_ns();
  lVar13 = nla_find((int *)param_2[1] + 5,*(int *)param_2[1] + -0x14,2);
  if (lVar13 != 0) {
    iVar3 = *(int *)(lVar13 + 4);
    auVar23 = next_tgid(uVar12,(int)param_2[10],0);
    uVar21 = auVar23._0_8_;
    if (auVar23._8_8_ != 0) {
      iVar2 = iVar3 >> 0x10;
LAB_00100c64:
      lVar13 = auVar23._8_8_;
      uVar21 = auVar23._0_8_;
      if ((*(byte *)(lVar13 + 0x46) >> 5 & 1) != 0) goto LAB_00100c40;
      sVar4 = *(short *)(*(long *)(lVar13 + 0x890) + 0x3ca);
      bVar8 = true;
      bVar9 = false;
      if ((short)iVar3 <= sVar4) {
        bVar9 = SBORROW4(iVar2,(int)sVar4);
        bVar8 = iVar2 - sVar4 < 0;
      }
      if (bVar8 != bVar9) goto LAB_00100c40;
      lVar14 = genlmsg_put(param_1,*(undefined4 *)(*param_2 + 0x34),*(undefined4 *)(param_2[1] + 8),
                           &family,0,1);
      if (lVar14 != 0) {
        lVar15 = nla_reserve(param_1,3,0x98);
        if (lVar15 == 0) {
          piVar1 = (int *)(lVar13 + 0x40);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar3 = *piVar1;
            cVar5 = '\x01';
            bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar8) {
              *piVar1 = iVar3 + -1;
              cVar5 = ExclusiveMonitorsStatus();
            }
          } while (cVar5 != '\0');
          if (iVar3 == 1) {
            DataMemoryBarrier(2,1);
            __put_task_struct(lVar13);
          }
          else if (iVar3 < 1) {
            refcount_warn_saturate(piVar1,3);
          }
          if (lVar14 != 0x14) {
            if (lVar14 - 0x14U < *(ulong *)(param_1 + 0xe0)) {
                    /* WARNING: Does not return */
              pcVar7 = (code *)SoftwareBreakpoint(0x800,0x100fc8);
              (*pcVar7)();
            }
            skb_trim(param_1,(int)(lVar14 - 0x14U) - (int)*(ulong *)(param_1 + 0xe0));
          }
          goto LAB_00100f80;
        }
        *(undefined8 *)(lVar15 + 0x94) = 0;
        *(undefined8 *)(lVar15 + 0x8c) = 0;
        *(undefined8 *)(lVar15 + 0x84) = 0;
        *(undefined8 *)(lVar15 + 0x7c) = 0;
        *(undefined8 *)(lVar15 + 0x74) = 0;
        *(undefined8 *)(lVar15 + 0x6c) = 0;
        *(undefined8 *)(lVar15 + 100) = 0;
        *(undefined8 *)(lVar15 + 0x5c) = 0;
        *(undefined8 *)(lVar15 + 0x54) = 0;
        *(undefined8 *)(lVar15 + 0x4c) = 0;
        *(undefined8 *)(lVar15 + 0x44) = 0;
        *(undefined8 *)(lVar15 + 0x3c) = 0;
        *(undefined8 *)(lVar15 + 0x34) = 0;
        *(undefined8 *)(lVar15 + 0x2c) = 0;
        *(undefined8 *)(lVar15 + 0x24) = 0;
        *(undefined8 *)(lVar15 + 0x1c) = 0;
        *(undefined8 *)(lVar15 + 0x14) = 0;
        *(undefined8 *)(lVar15 + 0xc) = 0;
        *(undefined8 *)(lVar15 + 4) = 0;
        __rcu_read_lock();
        uVar16 = task_active_pid_ns(uVar6);
        uVar10 = __task_pid_nr_ns(lVar13,0,uVar16);
        *(undefined4 *)(lVar15 + 0x50) = uVar10;
        *(undefined2 *)(lVar15 + 0x4c) = *(undefined2 *)(*(long *)(lVar13 + 0x890) + 0x3ca);
        __rcu_read_unlock();
        __rcu_read_lock();
        plVar17 = (long *)(*(long *)(lVar13 + 0x890) + 0x10);
        plVar22 = (long *)*plVar17;
        if (plVar22 != plVar17) {
          do {
            plVar17 = plVar22 + 0x46;
            _raw_spin_lock(plVar17);
            plVar19 = plVar22 + -0x2a;
            if (*plVar19 != 0) {
              __rcu_read_unlock();
              if (plVar22 == (long *)0x6f0) goto LAB_00100c24;
              lVar20 = 0;
              lVar18 = *(long *)(*plVar19 + 0x2d8);
              if (lVar18 < 1) {
                lVar18 = 0;
              }
              *(long *)(lVar15 + 4) = lVar18 << 2;
              lVar18 = *(long *)(*plVar19 + 0x2d0);
              if (lVar18 < 1) {
                lVar18 = 0;
              }
              *(long *)(lVar15 + 0xc) = lVar18 << 2;
              lVar18 = *(long *)(*plVar19 + 0x2e8);
              if (lVar18 < 1) {
                lVar18 = 0;
              }
              *(long *)(lVar15 + 0x1c) = lVar18 << 2;
              lVar18 = *(long *)(*plVar19 + 0x2e0);
              if (lVar18 < 1) {
                lVar18 = 0;
              }
              *(long *)(lVar15 + 0x14) = lVar18 << 2;
              local_70 = 0;
              plVar19 = (long *)(plVar22[0x34] + 0x10);
              goto LAB_00100e14;
            }
            _raw_spin_unlock(plVar17);
            plVar22 = (long *)*plVar22;
          } while (plVar22 != (long *)(*(long *)(lVar13 + 0x890) + 0x10));
        }
        __rcu_read_unlock();
        goto LAB_00100c24;
      }
      piVar1 = (int *)(lVar13 + 0x40);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar3 = *piVar1;
        cVar5 = '\x01';
        bVar8 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar8) {
          *piVar1 = iVar3 + -1;
          cVar5 = ExclusiveMonitorsStatus();
        }
      } while (cVar5 != '\0');
      if (iVar3 == 1) {
        DataMemoryBarrier(2,1);
        __put_task_struct(lVar13);
      }
      else if (iVar3 < 1) {
        refcount_warn_saturate(piVar1,3);
      }
    }
LAB_00100f80:
    param_2[10] = uVar21 & 0xffffffff;
  }
  lVar13 = sp_el0;
  if (*(long *)(lVar13 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(*(undefined4 *)(param_1 + 0x70));
  }
  return;
LAB_00100e14:
  do {
    plVar19 = (long *)*plVar19;
    if (plVar19 == (long *)(plVar22[0x34] + 0x10)) break;
    if (plVar19 != plVar22) {
      _raw_spin_lock(plVar19 + 0x46);
    }
    if (lVar20 == 0) {
      lVar20 = *(long *)(plVar22[-0x10] + 0x878);
      lVar18 = plVar19[0x31];
      if (lVar18 != 0) goto LAB_00100e44;
LAB_00100e80:
      iVar11 = 0;
    }
    else {
      lVar18 = plVar19[0x31];
      if (lVar18 == 0) goto LAB_00100e80;
LAB_00100e44:
      if ((lVar20 == lVar18) && (plVar19 + -0xde != (long *)plVar22[-0x10])) goto LAB_00100e80;
      iVar11 = iterate_fd(lVar18,0,get_dma_info,&local_70);
    }
    if (plVar19 != plVar22) {
      _raw_spin_unlock(plVar19 + 0x46);
    }
  } while (iVar11 == 0);
  *(ulong *)(lVar15 + 0x24) = local_70 >> 10 & 0x3ffffffffffffc;
  _raw_spin_unlock(plVar17);
LAB_00100c24:
  *(int *)(lVar14 + -0x14) =
       (*(int *)(param_1 + 0xd8) + *(int *)(param_1 + 0xd0)) - ((int)lVar14 + -0x14);
LAB_00100c40:
  auVar23 = next_tgid(uVar12,(ulong)(auVar23._0_4_ + 1) | uVar21 & 0xffffffff00000000,lVar13);
  uVar21 = auVar23._0_8_;
  if (auVar23._8_8_ == 0) goto LAB_00100f80;
  goto LAB_00100c64;
}



//------------------------------------------------------------
// sysstats_meminfo_user_cmd @ 00100fec size=1304
// signature: undefined sysstats_meminfo_user_cmd(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void sysstats_meminfo_user_cmd(undefined8 param_1,long param_2)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  long *plVar8;
  long *plVar9;
  long *plVar10;
  long *plVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  undefined *puVar15;
  char *__s1;
  long *plVar16;
  undefined *puVar17;
  long local_f0;
  ulong local_e8;
  ulong local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  long local_c0;
  undefined8 uStack_b8;
  long local_b0;
  long local_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined8 local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined8 uStack_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  local_f0 = 0;
  uVar5 = prepare_reply(param_2,4,&local_f0,0x124);
  lVar1 = local_f0;
  if (-1 < (int)uVar5) {
    lVar6 = nla_reserve(local_f0,4,0x120);
    if (lVar6 == 0) {
      kfree_skb_reason(lVar1,1);
      uVar5 = 0xffffffa6;
    }
    else {
      memset((void *)(lVar6 + 4),0,0x120);
      local_80 = 0;
      uStack_78 = 0;
      local_90 = 0;
      uStack_88 = 0;
      local_a0 = 0;
      uStack_98 = 0;
      local_b0 = 0;
      local_a8 = 0;
      local_c0 = 0;
      uStack_b8 = 0;
      local_d0 = 0;
      uStack_c8 = 0;
      local_e0 = 0;
      uStack_d8 = 0;
      si_meminfo(&local_e0);
      *(undefined8 *)(lVar6 + 0x3c) = 0;
      *(undefined8 *)(lVar6 + 0x24) = 0;
      *(undefined8 *)(lVar6 + 0x2c) = 0;
      *(long *)(lVar6 + 4) = local_c0 << 2;
      lVar13 = _DAT_00103218;
      if (_DAT_00103218 < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0xc) = lVar13 << 2;
      __rcu_read_lock();
      lVar13 = 0;
      puVar15 = (undefined *)(_DAT_00103660 + -0x550);
      lVar12 = _DAT_00103660;
      if (puVar15 != &init_task) {
        do {
          _raw_spin_lock(lVar12 + 0x3d0);
          local_e8 = 0;
          lVar14 = 0;
          plVar16 = (long *)(*(long *)(lVar12 + 0x340) + 0x10);
          do {
            plVar16 = (long *)*plVar16;
            if (plVar16 == (long *)(*(long *)(lVar12 + 0x340) + 0x10)) break;
            puVar17 = (undefined *)(plVar16 + -0xde);
            if (puVar17 != puVar15) {
              _raw_spin_lock(plVar16 + 0x46);
            }
            if (lVar14 == 0) {
              lVar14 = *(long *)(*(long *)(lVar12 + 0x120) + 0x878);
              lVar7 = plVar16[0x31];
              if (lVar7 != 0) goto LAB_00101170;
LAB_001011a4:
              iVar3 = 0;
            }
            else {
              lVar7 = plVar16[0x31];
              if (lVar7 == 0) goto LAB_001011a4;
LAB_00101170:
              if ((lVar14 == lVar7) && (puVar17 != *(undefined **)(lVar12 + 0x120)))
              goto LAB_001011a4;
              iVar3 = iterate_fd(lVar7,0,get_dma_info,&local_e8);
            }
            if (puVar17 != puVar15) {
              _raw_spin_unlock(plVar16 + 0x46);
            }
          } while (iVar3 == 0);
          lVar13 = lVar13 + (local_e8 >> 0xc);
          _raw_spin_unlock(lVar12 + 0x3d0);
          plVar16 = (long *)(puVar15 + 0x550);
          puVar15 = (undefined *)(*plVar16 + -0x550);
          lVar12 = *plVar16;
        } while (puVar15 != &init_task);
      }
      __rcu_read_unlock();
      if (*(int *)(sysstats_kgsl_get_stats + -4) != -0x531f1262) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1011f8);
        (*pcVar2)();
      }
      uVar5 = (*sysstats_kgsl_get_stats)(0xffffffff);
      lVar12 = 0;
      lVar14 = 0;
      *(ulong *)(lVar6 + 0x14) = (lVar13 + (uVar5 >> 0xc)) * 4;
      *(long *)(lVar6 + 0x34) = local_a8 << 2;
      lVar13 = _DAT_00103250;
      if (_DAT_00103250 < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x44) = lVar13 << 2;
      lVar13 = ___kmalloc;
      if (___kmalloc < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x4c) = lVar13 << 2;
      lVar13 = _memcpy;
      if (_memcpy < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x54) = lVar13 << 2;
      lVar13 = _pid_task;
      if (_pid_task < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x5c) = lVar13 << 2;
      lVar13 = _DAT_00103198;
      if (_DAT_00103198 < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 100) = lVar13 << 2;
      lVar13 = _DAT_00103230;
      if (_DAT_00103230 < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x74) = lVar13;
      lVar13 = _DAT_00103240;
      if (_DAT_00103240 < 1) {
        lVar13 = 0;
      }
      *(long *)(lVar6 + 0x6c) = lVar13 << 2;
      *(long *)(lVar6 + 0x7c) = local_b0 << 2;
      do {
        if (*(long *)(lVar12 + 0x1031a8) != 0) {
          lVar13 = *(long *)(lVar12 + 0x103728);
          __s1 = *(char **)(lVar12 + 0x1031c0);
          if (lVar13 < 1) {
            lVar13 = 0;
          }
          lVar14 = lVar13 + lVar14;
          iVar3 = strcmp(__s1,"DMA");
          plVar16 = (long *)(lVar6 + 0xa4);
          plVar8 = (long *)(lVar6 + 0x9c);
          plVar9 = (long *)(lVar6 + 0x94);
          plVar10 = (long *)(lVar6 + 0x8c);
          plVar11 = (long *)(lVar6 + 0x84);
          if ((((iVar3 == 0) ||
               (iVar3 = strcmp(__s1,"Normal"), plVar16 = (long *)(lVar6 + 0xcc),
               plVar8 = (long *)(lVar6 + 0xc4), plVar9 = (long *)(lVar6 + 0xbc),
               plVar10 = (long *)(lVar6 + 0xb4), plVar11 = (long *)(lVar6 + 0xac), iVar3 == 0)) ||
              (iVar3 = strcmp(__s1,"HighMem"), plVar16 = (long *)(lVar6 + 0x11c),
              plVar8 = (long *)(lVar6 + 0x114), plVar9 = (long *)(lVar6 + 0x10c),
              plVar10 = (long *)(lVar6 + 0x104), plVar11 = (long *)(lVar6 + 0xfc), iVar3 == 0)) ||
             (iVar3 = strcmp(__s1,"Movable"), plVar16 = (long *)(lVar6 + 0xf4),
             plVar8 = (long *)(lVar6 + 0xec), plVar9 = (long *)(lVar6 + 0xe4),
             plVar10 = (long *)(lVar6 + 0xdc), plVar11 = (long *)(lVar6 + 0xd4), iVar3 == 0)) {
            lVar13 = *(long *)(lVar12 + 0x1036e0);
            if (lVar13 < 1) {
              lVar13 = 0;
            }
            *plVar11 = lVar13 << 2;
            lVar13 = *(long *)(lVar12 + 0x1036f0);
            if (lVar13 < 1) {
              lVar13 = 0;
            }
            *plVar10 = lVar13 << 2;
            lVar13 = *(long *)(lVar12 + 0x1036e8);
            if (lVar13 < 1) {
              lVar13 = 0;
            }
            *plVar9 = lVar13 << 2;
            lVar13 = *(long *)(lVar12 + 0x103700);
            if (lVar13 < 1) {
              lVar13 = 0;
            }
            *plVar8 = lVar13 << 2;
            lVar13 = *(long *)(lVar12 + 0x1036f8);
            if (lVar13 < 1) {
              lVar13 = 0;
            }
            *plVar16 = lVar13 << 2;
          }
        }
        lVar12 = lVar12 + 0x640;
      } while (lVar12 < 0x1900);
      *(long *)(lVar6 + 0x1c) = lVar14 << 2;
      **(int **)(lVar1 + 0xe0) =
           (*(int *)(lVar1 + 0xd8) + *(int *)(lVar1 + 0xd0)) - (int)*(int **)(lVar1 + 0xe0);
      uVar4 = netlink_unicast(*(undefined8 *)(*(long *)(param_2 + 0x28) + 0x118),lVar1,
                              *(undefined4 *)(param_2 + 4),0x40);
      if (-1 < (int)uVar4) {
        uVar4 = 0;
      }
      uVar5 = (ulong)uVar4;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// sysstats_all_pids_of_name @ 00101508 size=640
// signature: undefined sysstats_all_pids_of_name(void)
// callers: []
//------------------------------------------------------------

undefined4 sysstats_all_pids_of_name(long param_1,long *param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  undefined8 uVar4;
  code *pcVar5;
  int iVar6;
  undefined8 uVar7;
  ushort *puVar8;
  char *__s2;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  size_t sVar12;
  size_t __n;
  ulong uVar13;
  long lVar14;
  undefined1 auVar15 [16];
  
  uVar4 = sp_el0;
  uVar7 = task_active_pid_ns(uVar4);
  puVar8 = (ushort *)nla_find((int *)param_2[1] + 5,*(int *)param_2[1] + -0x14,3);
  if (puVar8 != (ushort *)0x0) {
    sVar12 = (ulong)*puVar8 - 4;
    if ((int)sVar12 == 0) {
      __n = 0;
    }
    else {
      __n = (ulong)*puVar8 - 5;
      if (*(char *)((long)(puVar8 + 2) + __n) != '\0') {
        __n = sVar12;
      }
    }
    __s2 = (char *)__kmalloc(__n + 1,0xcc0);
    if (__s2 != (char *)0x0) {
      memcpy(__s2,puVar8 + 2,__n);
      lVar14 = param_2[10];
      __s2[__n] = '\0';
      auVar15 = next_tgid(uVar7,(int)lVar14,0);
      uVar13 = auVar15._0_8_;
      if (auVar15._8_8_ != 0) {
LAB_001015f0:
        lVar14 = auVar15._8_8_;
        uVar13 = auVar15._0_8_;
        iVar6 = strcmp((char *)(lVar14 + 0x848),__s2);
        if (iVar6 != 0) goto LAB_001015cc;
        lVar9 = genlmsg_put(param_1,*(undefined4 *)(*param_2 + 0x34),*(undefined4 *)(param_2[1] + 8)
                            ,&family,0,5);
        if (lVar9 == 0) {
          piVar1 = (int *)(lVar14 + 0x40);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar6 = *piVar1;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar3) {
              *piVar1 = iVar6 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (iVar6 == 1) {
            DataMemoryBarrier(2,1);
            __put_task_struct(lVar14);
          }
          else if (iVar6 < 1) {
            refcount_warn_saturate(piVar1,3);
          }
        }
        else {
          lVar10 = nla_reserve(param_1,5,8);
          if (lVar10 != 0) {
            *(undefined8 *)(lVar10 + 4) = 0;
            __rcu_read_lock();
            uVar11 = task_active_pid_ns(uVar4);
            iVar6 = __task_pid_nr_ns(lVar14,0,uVar11);
            *(long *)(lVar10 + 4) = (long)iVar6;
            __rcu_read_unlock();
            *(int *)(lVar9 + -0x14) =
                 (*(int *)(param_1 + 0xd8) + *(int *)(param_1 + 0xd0)) - ((int)lVar9 + -0x14);
            goto LAB_001015cc;
          }
          piVar1 = (int *)(lVar14 + 0x40);
          Hint_Prefetch(piVar1,2,0,1);
          do {
            iVar6 = *piVar1;
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
            if (bVar3) {
              *piVar1 = iVar6 + -1;
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
          if (iVar6 == 1) {
            DataMemoryBarrier(2,1);
            __put_task_struct(lVar14);
          }
          else if (iVar6 < 1) {
            refcount_warn_saturate(piVar1,3);
          }
          if (lVar9 != 0x14) {
            if (lVar9 - 0x14U < *(ulong *)(param_1 + 0xe0)) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(0x800,0x101794);
              (*pcVar5)();
            }
            skb_trim(param_1,(int)(lVar9 - 0x14U) - (int)*(ulong *)(param_1 + 0xe0));
          }
        }
      }
LAB_0010175c:
      param_2[10] = uVar13 & 0xffffffff;
      kfree(__s2);
    }
  }
  return *(undefined4 *)(param_1 + 0x70);
LAB_001015cc:
  auVar15 = next_tgid(uVar7,(ulong)(auVar15._0_4_ + 1) | uVar13 & 0xffffffff00000000,lVar14);
  uVar13 = auVar15._0_8_;
  if (auVar15._8_8_ == 0) goto LAB_0010175c;
  goto LAB_001015f0;
}



//------------------------------------------------------------
// prepare_reply @ 001017b0 size=272
// signature: undefined prepare_reply(void)
// callers: [sysstats_task_user_cmd, sysstats_meminfo_user_cmd]
//------------------------------------------------------------

undefined8 prepare_reply(int *param_1,undefined4 param_2,long *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  int iVar9;
  
  lVar6 = __alloc_skb((param_4 + 7U & 0xfffffffc) + 0x10,0xcc0,0,0xffffffff);
  if (lVar6 == 0) {
    uVar8 = 0xfffffff4;
  }
  else {
    if (param_1 == (int *)0x0) {
      lVar7 = sp_el0;
      *(int *)(lVar7 + 0x10) = *(int *)(lVar7 + 0x10) + 1;
      lVar5 = tpidr_el1;
      piVar1 = (int *)(&sysstats_seqnum + lVar5);
      do {
        iVar2 = *piVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar2 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      lVar5 = *(long *)(lVar7 + 0x10) + -1;
      *(int *)(lVar7 + 0x10) = (int)lVar5;
      if ((lVar5 == 0) || (*(long *)(lVar7 + 0x10) == 0)) {
        preempt_schedule_notrace();
      }
      iVar9 = 0;
    }
    else {
      iVar2 = *param_1;
      iVar9 = param_1[1];
    }
    lVar7 = genlmsg_put(lVar6,iVar9,iVar2,&family,0,param_2);
    if (lVar7 == 0) {
      kfree_skb_reason(lVar6,1);
      uVar8 = 0xffffffea;
    }
    else {
      uVar8 = 0;
      *param_3 = lVar6;
    }
  }
  return uVar8;
}



//------------------------------------------------------------
// get_dma_info @ 001018c4 size=188
// signature: undefined get_dma_info(void)
// callers: []
//------------------------------------------------------------

undefined8 get_dma_info(long *param_1,long param_2)

{
  int iVar1;
  ulong uVar2;
  char *__s1;
  long *plVar3;
  
  uVar2 = qcom_is_dma_buf_file(param_2);
  if ((uVar2 & 1) != 0) {
    plVar3 = *(long **)(param_2 + 0xd8);
    __s1 = (char *)plVar3[0xe];
    iVar1 = strcmp(__s1,"qcom,system");
    if ((((iVar1 == 0) || (iVar1 = strcmp(__s1,"qcom,system-uncached"), iVar1 == 0)) ||
        (iVar1 = strcmp(__s1,"system-secure"), iVar1 == 0)) ||
       ((iVar1 = strcmp(__s1,"qcom,secure-pixel"), iVar1 == 0 ||
        (iVar1 = strcmp(__s1,"qcom,secure-non-pixel"), iVar1 == 0)))) {
      *param_1 = *param_1 + *plVar3;
    }
  }
  return 0;
}



//------------------------------------------------------------
// next_tgid @ 00101980 size=340
// signature: undefined next_tgid(void)
// callers: [sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

void next_tgid(undefined8 param_1,undefined8 param_2,long param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  bool bVar6;
  undefined4 uVar7;
  long lVar8;
  undefined8 uVar9;
  undefined8 local_38;
  long local_30;
  long local_28;
  
  lVar8 = sp_el0;
  local_28 = *(long *)(lVar8 + 0x638);
  local_38 = param_2;
  if (param_3 != 0) {
    piVar1 = (int *)(param_3 + 0x40);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar3 = *piVar1;
      cVar5 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar6) {
        *piVar1 = iVar3 + -1;
        cVar5 = ExclusiveMonitorsStatus();
      }
    } while (cVar5 != '\0');
    if (iVar3 == 1) {
      DataMemoryBarrier(2,1);
      __put_task_struct(param_3);
    }
    else if (iVar3 < 1) {
      refcount_warn_saturate(piVar1,3);
    }
  }
  __rcu_read_lock();
  local_30 = 0;
  lVar8 = idr_get_next(param_1,&local_38);
  if (lVar8 != 0) {
    do {
      uVar7 = pid_nr_ns(lVar8,param_1);
      local_38 = CONCAT44(local_38._4_4_,uVar7);
      local_30 = pid_task(lVar8,1);
      if (local_30 != 0) {
        puVar2 = (uint *)(local_30 + 0x40);
        Hint_Prefetch(puVar2,2,0,1);
        do {
          uVar4 = *puVar2;
          cVar5 = '\x01';
          bVar6 = (bool)ExclusiveMonitorPass(puVar2,0x10);
          if (bVar6) {
            *puVar2 = uVar4 + 1;
            cVar5 = ExclusiveMonitorsStatus();
          }
        } while (cVar5 != '\0');
        if (uVar4 == 0) {
          uVar9 = 2;
        }
        else {
          if (-1 < (int)(uVar4 + 1 | uVar4)) break;
          uVar9 = 1;
        }
        refcount_warn_saturate(puVar2,uVar9);
        break;
      }
      local_30 = 0;
      local_38 = CONCAT44(local_38._4_4_,(int)local_38 + 1);
      lVar8 = idr_get_next(param_1,&local_38);
    } while (lVar8 != 0);
  }
  __rcu_read_unlock();
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(local_38,local_30);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 00101b74 size=92
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = genl_register_family(&family);
  if (iVar1 == 0) {
    sysstats_kgsl_get_stats = sysstats_kgsl_stats;
    _printk(&DAT_00101d6a,2);
  }
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00101bd4 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  genl_unregister_family(&family);
  return;
}



//------------------------------------------------------------
// genl_register_family @ 00103000 size=1
// signature: undefined genl_register_family(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_register_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00103008 size=1
// signature: undefined _printk(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genl_unregister_family @ 00103010 size=1
// signature: undefined genl_unregister_family(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genl_unregister_family(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __nla_validate @ 00103018 size=1
// signature: undefined __nla_validate(void)
// callers: [sysstats_pre_doit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __nla_validate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_reserve_64bit @ 00103020 size=1
// signature: undefined nla_reserve_64bit(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_reserve_64bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00103028 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [sysstats_task_user_cmd, next_tgid, sysstats_meminfo_user_cmd, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// find_task_by_vpid @ 00103030 size=1
// signature: undefined find_task_by_vpid(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void find_task_by_vpid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00103040 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [sysstats_task_user_cmd, next_tgid, sysstats_meminfo_user_cmd, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// task_active_pid_ns @ 00103048 size=1
// signature: undefined task_active_pid_ns(void)
// callers: [sysstats_task_user_cmd, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void task_active_pid_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __task_pid_nr_ns @ 00103050 size=1
// signature: undefined __task_pid_nr_ns(void)
// callers: [sysstats_task_user_cmd, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __task_pid_nr_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00103058 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [sysstats_task_user_cmd, sysstats_meminfo_user_cmd, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00103060 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [sysstats_task_user_cmd, sysstats_meminfo_user_cmd, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// iterate_fd @ 00103068 size=1
// signature: undefined iterate_fd(void)
// callers: [sysstats_task_user_cmd, sysstats_meminfo_user_cmd, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void iterate_fd(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree_skb_reason @ 00103070 size=1
// signature: undefined kfree_skb_reason(void)
// callers: [prepare_reply, sysstats_task_user_cmd, sysstats_meminfo_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree_skb_reason(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00103078 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00103080 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnlen @ 00103090 size=1
// signature: size_t strnlen(char * __string, size_t __maxlen)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strnlen(char *__string,size_t __maxlen)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strscpy @ 00103098 size=1
// signature: undefined strscpy(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strscpy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cgroup_path_ns @ 001030a0 size=1
// signature: undefined cgroup_path_ns(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cgroup_path_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __put_task_struct @ 001030a8 size=1
// signature: undefined __put_task_struct(void)
// callers: [sysstats_task_user_cmd, next_tgid, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __put_task_struct(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// preempt_schedule_notrace @ 001030b0 size=1
// signature: undefined preempt_schedule_notrace(void)
// callers: [prepare_reply, sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void preempt_schedule_notrace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001030b8 size=1
// signature: undefined fortify_panic(void)
// callers: [sysstats_task_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// refcount_warn_saturate @ 001030c0 size=1
// signature: undefined refcount_warn_saturate(void)
// callers: [sysstats_task_user_cmd, next_tgid, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void refcount_warn_saturate(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// netlink_unicast @ 001030c8 size=1
// signature: undefined netlink_unicast(void)
// callers: [sysstats_task_user_cmd, sysstats_meminfo_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void netlink_unicast(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001030d0 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [sysstats_task_user_cmd, next_tgid, sysstats_meminfo_user_cmd, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_find @ 001030d8 size=1
// signature: undefined nla_find(void)
// callers: [sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_find(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// genlmsg_put @ 001030e0 size=1
// signature: undefined genlmsg_put(void)
// callers: [prepare_reply, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void genlmsg_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// nla_reserve @ 001030e8 size=1
// signature: undefined nla_reserve(void)
// callers: [sysstats_meminfo_user_cmd, sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void nla_reserve(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// skb_trim @ 001030f0 size=1
// signature: undefined skb_trim(void)
// callers: [sysstats_all_pids_of_name, sysstats_task_foreach]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void skb_trim(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001030f8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [sysstats_meminfo_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// si_meminfo @ 00103100 size=1
// signature: undefined si_meminfo(void)
// callers: [sysstats_meminfo_user_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void si_meminfo(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00103128 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [get_dma_info, sysstats_meminfo_user_cmd, sysstats_all_pids_of_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00103130 size=1
// signature: undefined __kmalloc(void)
// callers: [sysstats_all_pids_of_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00103138 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [sysstats_all_pids_of_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00103140 size=1
// signature: undefined kfree(void)
// callers: [sysstats_all_pids_of_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_skb @ 00103148 size=1
// signature: undefined __alloc_skb(void)
// callers: [prepare_reply]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_skb(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_is_dma_buf_file @ 00103150 size=1
// signature: undefined qcom_is_dma_buf_file(void)
// callers: [get_dma_info]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_is_dma_buf_file(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// idr_get_next @ 00103158 size=1
// signature: undefined idr_get_next(void)
// callers: [next_tgid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void idr_get_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pid_nr_ns @ 00103160 size=1
// signature: undefined pid_nr_ns(void)
// callers: [next_tgid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pid_nr_ns(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pid_task @ 00103168 size=1
// signature: undefined pid_task(void)
// callers: [next_tgid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pid_task(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



