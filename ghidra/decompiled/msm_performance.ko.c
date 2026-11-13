// Decompiled by Ghidra 12.2
// Program: msm_performance.ko
// Image base: 00100000

//------------------------------------------------------------
// msm_perf_events_update @ 001008a4 size=308
// signature: undefined msm_perf_events_update(void)
// callers: []
//------------------------------------------------------------

void msm_perf_events_update
               (int param_1,uint param_2,int param_3,undefined4 param_4,int param_5,uint param_6)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  
  if ((((param_1 != 0) || (param_5 == 0)) || (game_status_pid != param_3)) || ((param_6 & 1) == 0))
  {
    return;
  }
  uVar4 = _raw_spin_lock_irqsave(&gfx_circ_buff_lock);
  uVar2 = curr_pos_0;
  uVar6 = (ulong)curr_pos_0;
  uVar1 = -(curr_pos_0 + 1);
  curr_pos_0 = curr_pos_0 + 1 & 0x1ff;
  if (-1 < (int)uVar1) {
    curr_pos_0 = -(uVar1 & 0x1ff);
  }
  _raw_spin_unlock_irqrestore(&gfx_circ_buff_lock,uVar4);
  if (0x1ff < uVar2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1009d8);
    (*pcVar3)();
  }
  lVar5 = uVar6 * 0x20;
  *(int *)(gpu_circ_buff + lVar5) = param_3;
  if ((((uVar6 << 5 | 4) < 0x4001) &&
      (*(undefined4 *)(gpu_circ_buff + lVar5 + 4) = param_4, (uVar6 << 5 | 8) < 0x4001)) &&
     (*(int *)(gpu_circ_buff + lVar5 + 8) = param_5, (uVar6 << 5 | 0x18) < 0x4001)) {
    *(uint *)(gpu_circ_buff + lVar5 + 0x18) = param_2;
    uVar4 = ktime_get();
    if ((uVar6 << 5 | 0x10) < 0x4001) {
      *(undefined8 *)(gpu_circ_buff + uVar6 * 0x20 + 0x10) = uVar4;
      if ((param_2 & 0xfffffffd) == 1) {
        complete(&gfx_evt_arrival);
        return;
      }
      return;
    }
  }
                    /* WARNING: Does not return */
  pcVar3 = (code *)SoftwareBreakpoint(1,0x1009d4);
  (*pcVar3)();
}



//------------------------------------------------------------
// cpucp_plh_init @ 001009dc size=120
// signature: undefined cpucp_plh_init(void)
// callers: []
//------------------------------------------------------------

undefined4 cpucp_plh_init(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0xffffffea;
    if (*(long *)(param_1 + 0x3a0) != 0) {
      pcVar1 = *(code **)(*(long *)(param_1 + 0x3a0) + 0x18);
      if (*(int *)(pcVar1 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x100a24);
        (*pcVar1)();
      }
      plh_ops = (*pcVar1)(param_1,0x80,&plh_handle);
      uVar2 = 0xffffffea;
      if (plh_ops != 0) {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}



//------------------------------------------------------------
// hotplug_notify_up @ 00100a58 size=160
// signature: undefined hotplug_notify_up(void)
// callers: []
//------------------------------------------------------------

undefined8 hotplug_notify_up(uint param_1)

{
  code *pcVar1;
  undefined8 uVar2;
  
  mutex_lock(perfevent_lock);
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100af8);
    (*pcVar1)();
  }
  (&cpu_is_hp)[*(long *)(&__per_cpu_offset + (ulong)param_1 * 8)] = 0;
  mutex_unlock(perfevent_lock);
  if (DAT_001077ed != '\0') {
    uVar2 = _raw_spin_lock_irqsave(&events_group);
    DAT_001077ec = 1;
    _raw_spin_unlock_irqrestore(&events_group,uVar2);
    wake_up_process(events_notify_thread);
  }
  return 0;
}



//------------------------------------------------------------
// hotplug_notify_down @ 00100afc size=220
// signature: undefined hotplug_notify_down(void)
// callers: []
//------------------------------------------------------------

undefined8 hotplug_notify_down(ulong param_1)

{
  long *plVar1;
  code *pcVar2;
  long lVar3;
  
  mutex_lock(perfevent_lock);
  if (0x1f < (uint)param_1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100bd8);
    (*pcVar2)();
  }
  (&cpu_is_hp)[*(long *)(&__per_cpu_offset + (param_1 & 0xffffffff) * 8)] = 1;
  plVar1 = pmu_events;
  if ((*(ulong *)(&__cpu_possible_mask + ((param_1 & 0xffffffff) >> 3 & 0x1ffffff8)) >>
       (param_1 & 0x3f) & 1) != 0) {
    lVar3 = (param_1 & 0xffffffff) * 0x20;
    *(undefined8 *)(*pmu_events + lVar3 + 8) = 0;
    *(undefined8 *)(*plVar1 + lVar3 + 0x10) = 0;
    *(undefined8 *)(*plVar1 + lVar3 + 0x18) = 0;
    *(undefined8 *)(plVar1[1] + lVar3 + 8) = 0;
    *(undefined8 *)(plVar1[1] + lVar3 + 0x10) = 0;
    *(undefined8 *)(plVar1[1] + lVar3 + 0x18) = 0;
  }
  mutex_unlock(perfevent_lock);
  return 0;
}



//------------------------------------------------------------
// get_cpu_min_freq @ 00100bdc size=244
// signature: undefined get_cpu_min_freq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long get_cpu_min_freq(undefined8 param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_present_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar2) {
      iVar4 = scnprintf(param_3 + iVar5,0x1000 - (long)iVar5,&DAT_0010850a);
      return (long)(iVar4 + iVar5);
    }
    if ((uVar2 & 0xffffffe0) != 0) break;
    iVar3 = scnprintf(param_3 + iVar5,0x1000 - (long)iVar5,"%d:%u ",uVar2,
                      *(undefined4 *)
                       ((long)&msm_perf_cpu_stats + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8))
                     );
    iVar4 = uVar2 + 1;
    iVar5 = iVar3 + iVar5;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x100cd0);
  (*pcVar1)();
}



//------------------------------------------------------------
// set_cpu_min_freq @ 00100cd4 size=644
// signature: undefined set_cpu_min_freq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long set_cpu_min_freq(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  size_t sVar9;
  long lVar10;
  ulong extraout_x8;
  ulong uVar11;
  ulong extraout_x9;
  ulong uVar12;
  undefined8 *puVar13;
  char *__format;
  undefined *unaff_x24;
  undefined8 *unaff_x26;
  int unaff_w27;
  undefined *unaff_x28;
  undefined8 local_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_70 = 0;
  mutex_lock(freq_pmqos_lock);
  __format = gpu_circ_buff + 0x38b0;
  if ((ready_for_freq_updates & 1) == 0) {
    iVar6 = freq_qos_request_init();
    if (iVar6 != 0) {
      _printk(&DAT_00107e90,"set_cpu_min_freq",iVar6);
      mutex_unlock(freq_pmqos_lock);
      param_4 = (long)iVar6;
      goto LAB_00100f20;
    }
    ready_for_freq_updates = 1;
  }
  mutex_unlock(freq_pmqos_lock);
  uVar7 = 0xffffffff;
  puVar13 = (undefined8 *)&DAT_00108120;
  pcVar8 = param_3;
  do {
    pcVar8 = strpbrk(pcVar8 + 1," :");
    uVar7 = uVar7 + 1;
  } while (pcVar8 != (char *)0x0);
  if ((uVar7 & 1) == 0) {
LAB_00100d6c:
    param_4 = -0x16;
  }
  else {
    uVar2 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
    if (8 < uVar2) {
      fortify_panic("memset");
      uVar11 = extraout_x8;
      uVar12 = extraout_x9;
      goto LAB_00100e10;
    }
    puVar13 = &limit_mask_min;
    memset(&limit_mask_min,0,(ulong)uVar2);
    unaff_x24 = &__per_cpu_offset;
    unaff_x26 = &msm_perf_cpu_stats;
    if (0 < (int)uVar7) {
      unaff_w27 = 0;
      __format = "%u:%u";
      unaff_x28 = &__cpu_possible_mask;
      do {
        iVar6 = sscanf(param_3,__format,&local_70,(long)&local_70 + 4);
        if (iVar6 != 2) goto LAB_00100d6c;
        if (_nr_cpu_ids <= (uint)local_70) break;
        if ((*(ulong *)(unaff_x28 + ((ulong)((uint)local_70 >> 3) & 0x1ffffff8)) >>
             (local_70 & 0x3f) & 1) != 0) {
          if (0x1f < (uint)local_70) goto LAB_00100f5c;
          *(undefined4 *)(*(long *)(unaff_x24 + (local_70 & 0xffffffff) * 8) + (long)unaff_x26) =
               local_70._4_4_;
          uVar12 = (ulong)((uint)local_70 >> 6);
          uVar11 = 1L << (local_70 & 0x3f);
LAB_00100e10:
          puVar1 = puVar13 + uVar12;
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar4) {
              *puVar1 = *puVar1 | uVar11;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        sVar9 = strlen(param_3);
        lVar10 = strnchr(param_3,sVar9,0x20);
        unaff_w27 = unaff_w27 + 2;
        param_3 = (char *)(lVar10 + 1);
      } while (unaff_w27 < (int)uVar7);
    }
    cpus_read_lock();
    iVar6 = 0;
    while( true ) {
      uVar7 = _find_next_bit(&limit_mask_min,_nr_cpu_ids,(long)iVar6);
      if (_nr_cpu_ids <= uVar7) break;
      if ((uVar7 & 0xffffffe0) != 0) {
LAB_00100f5c:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100f60);
        (*pcVar5)();
      }
      freq_qos_update_request
                (qos_req_min + *(long *)(unaff_x24 + (ulong)uVar7 * 8),
                 *(undefined4 *)(*(long *)(unaff_x24 + (ulong)uVar7 * 8) + (long)unaff_x26));
      iVar6 = uVar7 + 1;
    }
    cpus_read_unlock();
  }
LAB_00100f20:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// freq_qos_request_init @ 00100f64 size=544
// signature: undefined freq_qos_request_init(void)
// callers: [set_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int freq_qos_request_init(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  long lVar4;
  undefined *puVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  
  iVar3 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_present_mask,_nr_cpu_ids,iVar3);
    if (_nr_cpu_ids <= uVar2) {
      return 0;
    }
    lVar4 = cpufreq_cpu_get(uVar2);
    if (lVar4 == 0) break;
    if (0x1f < (ulong)uVar2) goto LAB_00101180;
    lVar8 = (ulong)uVar2 * 8;
    *(undefined4 *)((long)&msm_perf_cpu_stats + *(long *)(&__per_cpu_offset + lVar8)) = 0;
    iVar3 = freq_qos_add_request
                      (lVar4 + 0xa0,qos_req_min + *(long *)(&__per_cpu_offset + lVar8),1,0);
    if (iVar3 < 0) {
      puVar5 = &DAT_0010849e;
LAB_001010bc:
      _printk(puVar5,"freq_qos_request_init",iVar3);
      cpufreq_cpu_put(lVar4);
      goto LAB_001010d4;
    }
    *(undefined4 *)((long)&msm_perf_cpu_stats + *(long *)(&__per_cpu_offset + lVar8) + 4) =
         0x7fffffff;
    iVar3 = freq_qos_add_request
                      (lVar4 + 0xa0,qos_req_max + *(long *)(&__per_cpu_offset + lVar8),2,0x7fffffff)
    ;
    if (iVar3 < 0) {
      puVar5 = &DAT_00107e28;
      goto LAB_001010bc;
    }
    cpufreq_cpu_put(lVar4);
    iVar3 = uVar2 + 1;
  }
  _printk(&DAT_00108123,"freq_qos_request_init",uVar2);
  iVar3 = -0xb;
LAB_001010d4:
  iVar6 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_present_mask,_nr_cpu_ids,iVar6);
    if (_nr_cpu_ids <= uVar2) {
      return iVar3;
    }
    uVar7 = (ulong)uVar2;
    if (0x1f < uVar7) break;
    lVar4 = *(long *)(&__per_cpu_offset + uVar7 * 8);
    if (((lVar4 != -0x1086f8) && (*(ulong *)(qos_req_min + lVar4 + 0x30) != 0)) &&
       (*(ulong *)(qos_req_min + lVar4 + 0x30) < 0xfffffffffffff001)) {
      freq_qos_remove_request();
      lVar4 = *(long *)(&__per_cpu_offset + uVar7 * 8);
    }
    if (((lVar4 != -0x108738) && (*(ulong *)(qos_req_max + lVar4 + 0x30) != 0)) &&
       (*(ulong *)(qos_req_max + lVar4 + 0x30) < 0xfffffffffffff001)) {
      freq_qos_remove_request();
      lVar4 = *(long *)(&__per_cpu_offset + uVar7 * 8);
    }
    *(undefined4 *)((long)&msm_perf_cpu_stats + lVar4) = 0;
    iVar6 = uVar2 + 1;
    *(undefined4 *)((long)&msm_perf_cpu_stats + *(long *)(&__per_cpu_offset + uVar7 * 8) + 4) =
         0x7fffffff;
  }
LAB_00101180:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101184);
  (*pcVar1)();
}



//------------------------------------------------------------
// get_cpu_max_freq @ 00101188 size=248
// signature: undefined get_cpu_max_freq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long get_cpu_max_freq(undefined8 param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_present_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar2) {
      iVar4 = scnprintf(param_3 + iVar5,0x1000 - (long)iVar5,&DAT_0010850a);
      return (long)(iVar4 + iVar5);
    }
    if ((uVar2 & 0xffffffe0) != 0) break;
    iVar3 = scnprintf(param_3 + iVar5,0x1000 - (long)iVar5,"%d:%u ",uVar2,
                      *(undefined4 *)
                       ((long)&msm_perf_cpu_stats +
                       *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8) + 4));
    iVar4 = uVar2 + 1;
    iVar5 = iVar3 + iVar5;
  }
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101280);
  (*pcVar1)();
}



//------------------------------------------------------------
// set_cpu_max_freq @ 00101284 size=664
// signature: undefined set_cpu_max_freq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void set_cpu_max_freq(undefined8 param_1,undefined8 param_2,char *param_3,char *param_4)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  size_t sVar9;
  long lVar10;
  ulong extraout_x8;
  ulong uVar11;
  ulong extraout_x9;
  ulong uVar12;
  undefined *puVar13;
  undefined *unaff_x24;
  undefined8 *unaff_x25;
  uint uVar14;
  int unaff_w27;
  long unaff_x28;
  uint local_70;
  uint local_6c;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  local_6c = 0;
  local_70 = 0;
  mutex_lock(freq_pmqos_lock);
  uVar7 = 0x107000;
  if ((ready_for_freq_updates & 1) == 0) {
    iVar6 = freq_qos_request_init();
    if (iVar6 != 0) {
      _printk(&DAT_00107e90,"set_cpu_max_freq",iVar6);
      mutex_unlock(freq_pmqos_lock);
      param_4 = (char *)(long)iVar6;
      goto LAB_001014f0;
    }
    ready_for_freq_updates = 1;
  }
  mutex_unlock(freq_pmqos_lock);
  uVar14 = 0xffffffff;
  puVar13 = &DAT_00108120;
  pcVar8 = param_3;
  do {
    pcVar8 = strpbrk(pcVar8 + 1," :");
    uVar14 = uVar14 + 1;
  } while (pcVar8 != (char *)0x0);
  if ((uVar14 & 1) == 0) {
LAB_00101320:
    param_4 = (char *)0xffffffffffffffea;
  }
  else {
    uVar2 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
    if (8 < uVar2) {
      fortify_panic("memset");
      uVar11 = extraout_x8;
      uVar12 = extraout_x9;
      pcVar8 = param_4;
      goto LAB_001013cc;
    }
    memset(&limit_mask_max,0,(ulong)uVar2);
    unaff_x24 = &__per_cpu_offset;
    unaff_x25 = &msm_perf_cpu_stats;
    if (0 < (int)uVar14) {
      unaff_w27 = 0;
      unaff_x28 = 1;
      uVar7 = 0x7fffffff;
      pcVar8 = "%u:%u";
      puVar13 = &__cpu_possible_mask;
      do {
        iVar6 = sscanf(param_3,pcVar8,&local_70,&local_6c);
        if (iVar6 != 2) goto LAB_00101320;
        if (_nr_cpu_ids <= local_70) break;
        uVar12 = (ulong)(local_70 >> 6);
        uVar11 = unaff_x28 << ((ulong)local_70 & 0x3f);
        if ((*(ulong *)(puVar13 + uVar12 * 8) & uVar11) != 0) {
          if (0x1f < local_70) goto LAB_00101528;
          uVar2 = local_6c;
          if (uVar7 <= local_6c) {
            uVar2 = uVar7;
          }
          *(uint *)((long)unaff_x25 + *(long *)(unaff_x24 + (ulong)local_70 * 8) + 4) = uVar2;
LAB_001013cc:
          puVar1 = &limit_mask_max + uVar12;
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar3 = '\x01';
            bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar4) {
              *puVar1 = *puVar1 | uVar11;
              cVar3 = ExclusiveMonitorsStatus();
            }
          } while (cVar3 != '\0');
        }
        sVar9 = strlen(param_3);
        lVar10 = strnchr(param_3,sVar9,0x20);
        unaff_w27 = unaff_w27 + 2;
        param_3 = (char *)(lVar10 + 1);
      } while (unaff_w27 < (int)uVar14);
    }
    cpus_read_lock();
    iVar6 = 0;
    while( true ) {
      uVar7 = _find_next_bit(&limit_mask_max,_nr_cpu_ids,(long)iVar6);
      if (_nr_cpu_ids <= uVar7) break;
      if ((uVar7 & 0xffffffe0) != 0) {
LAB_00101528:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10152c);
        (*pcVar5)();
      }
      freq_qos_update_request
                (qos_req_max + *(long *)(unaff_x24 + (ulong)uVar7 * 8),
                 *(undefined4 *)((long)unaff_x25 + *(long *)(unaff_x24 + (ulong)uVar7 * 8) + 4));
      iVar6 = uVar7 + 1;
    }
    cpus_read_unlock();
  }
LAB_001014f0:
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// get_cpu_total_instruction @ 00101534 size=648
// signature: undefined get_cpu_total_instruction(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long get_cpu_total_instruction(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  ulong uVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  ulong local_80;
  ulong local_78;
  long local_70;
  long local_68;
  
  local_80 = 0;
  lVar5 = 0;
  local_78 = 0;
  lVar10 = sp_el0;
  lVar8 = 0;
  lVar9 = 0;
  local_68 = *(long *)(lVar10 + 0x638);
  do {
    uVar4 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar5);
    uVar11 = (uint)uVar4;
    if (_nr_cpu_ids <= uVar11) {
      iVar3 = scnprintf(param_3,0x1000,"%llu:%llu:%llu:%llu\n",lVar9,local_80,lVar8,local_78);
      lVar5 = sp_el0;
      if (*(long *)(lVar5 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return (long)iVar3;
    }
    lVar10 = (long)(int)uVar11;
    lVar5 = *pmu_events;
    local_70 = 0;
    mutex_lock(perfevent_lock);
    iVar3 = *(int *)(lVar5 + (-(uVar4 >> 0x1f & 1) & 0xffffffe000000000 | (uVar4 & 0xffffffff) << 5)
                    );
    if (iVar3 != 0) {
      if (0x1f < uVar11) goto LAB_001017b4;
      if ((&cpu_is_hp)[*(long *)(&__per_cpu_offset + (uVar4 & 0xffffffff) * 8)] == '\0') {
        iVar3 = qcom_pmu_read(uVar4 & 0xffffffff,iVar3,&local_70);
        if (iVar3 != 0) goto LAB_00101630;
      }
      else {
        local_70 = *(long *)(lVar5 + lVar10 * 0x20 + 0x18);
      }
      lVar5 = lVar5 + lVar10 * 0x20;
      lVar7 = *(long *)(lVar5 + 8);
      *(long *)(lVar5 + 8) = local_70;
      *(long *)(lVar5 + 0x10) = local_70 - lVar7;
    }
LAB_00101630:
    mutex_unlock(perfevent_lock);
    lVar7 = lVar10 * 0x20;
    lVar5 = pmu_events[1];
    local_70 = 0;
    mutex_lock(perfevent_lock);
    if (*(int *)(lVar5 + lVar7) != 0) {
      if (0x1f < uVar11) goto LAB_001017b4;
      if ((&cpu_is_hp)[*(long *)(&__per_cpu_offset + (uVar4 & 0xffffffff) * 8)] == '\0') {
        iVar3 = qcom_pmu_read(uVar4 & 0xffffffff,*(int *)(lVar5 + lVar7),&local_70);
        if (iVar3 != 0) goto LAB_001016a4;
      }
      else {
        local_70 = *(long *)(lVar5 + lVar10 * 0x20 + 0x18);
      }
      lVar5 = lVar5 + lVar10 * 0x20;
      lVar10 = *(long *)(lVar5 + 8);
      *(long *)(lVar5 + 8) = local_70;
      *(long *)(lVar5 + 0x10) = local_70 - lVar10;
    }
LAB_001016a4:
    mutex_unlock(perfevent_lock);
    if (0x1f < uVar11) {
LAB_001017b4:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1017b8);
      (*pcVar2)();
    }
    lVar5 = *(long *)(*pmu_events + lVar7 + 0x10);
    uVar6 = *(ulong *)(pmu_events[1] + lVar7 + 0x10);
    if (min_cpu_capacity <
        *(ulong *)(&cpu_scale + *(long *)(&__per_cpu_offset + (uVar4 & 0xffffffff) * 8))) {
      if (649999 < uVar6) {
        uVar1 = 0;
        if (uVar6 != 0) {
          uVar1 = (ulong)(lVar5 * 100) / uVar6;
        }
        if (local_80 <= uVar1) {
          local_80 = uVar1;
        }
      }
      lVar9 = lVar5 + lVar9;
      lVar5 = uVar4 + 1;
    }
    else {
      if (uVar6 != 0) {
        uVar1 = 0;
        if (uVar6 != 0) {
          uVar1 = (ulong)(lVar5 * 100) / uVar6;
        }
        if (local_78 <= uVar1) {
          local_78 = uVar1;
        }
      }
      lVar8 = lVar5 + lVar8;
      lVar5 = uVar4 + 1;
    }
  } while( true );
}



//------------------------------------------------------------
// get_core_ctl_register @ 001017c0 size=72
// signature: undefined get_core_ctl_register(void)
// callers: []
//------------------------------------------------------------

long get_core_ctl_register(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0x4e;
  if (core_ctl_register != '\0') {
    uVar2 = 0x59;
  }
  iVar1 = scnprintf(param_3,0x1000,&DAT_00108113,uVar2);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_core_ctl_register @ 0010180c size=140
// signature: undefined set_core_ctl_register(void)
// callers: []
//------------------------------------------------------------

long set_core_ctl_register(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  char cVar1;
  int iVar2;
  
  cVar1 = core_ctl_register;
  iVar2 = kstrtobool(param_3);
  if (iVar2 < 0) {
    _printk(&DAT_00107e56,iVar2);
    param_4 = (long)iVar2;
  }
  else if (core_ctl_register != cVar1) {
    if (core_ctl_register == '\0') {
      core_ctl_notifier_unregister(&msm_perf_nb);
    }
    else {
      core_ctl_notifier_register();
    }
  }
  return param_4;
}



//------------------------------------------------------------
// msm_perf_core_ctl_notify @ 0010189c size=428
// signature: undefined msm_perf_core_ctl_notify(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 msm_perf_core_ctl_notify(undefined8 param_1,undefined8 param_2,int *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  msm_perf_core_ctl_notify_nrb = msm_perf_core_ctl_notify_nrb + *param_3;
  msm_perf_core_ctl_notify_tld = msm_perf_core_ctl_notify_tld + param_3[1];
  uVar1 = msm_perf_core_ctl_notify_top_ld_0 + param_3[2];
  uVar2 = msm_perf_core_ctl_notify_curr_cp_0 + param_3[6];
  uVar3 = msm_perf_core_ctl_notify_top_ld_1 + param_3[3];
  uVar4 = msm_perf_core_ctl_notify_curr_cp_1 + param_3[7];
  msm_perf_core_ctl_notify_top_ld_2 = msm_perf_core_ctl_notify_top_ld_2 + param_3[4];
  msm_perf_core_ctl_notify_curr_cp_2 = msm_perf_core_ctl_notify_curr_cp_2 + param_3[8];
  msm_perf_core_ctl_notify_i = msm_perf_core_ctl_notify_i + 1;
  msm_perf_core_ctl_notify_top_ld_0 = uVar1;
  msm_perf_core_ctl_notify_top_ld_1 = uVar3;
  msm_perf_core_ctl_notify_curr_cp_0 = uVar2;
  msm_perf_core_ctl_notify_curr_cp_1 = uVar4;
  if (msm_perf_core_ctl_notify_i == 0x19) {
    msm_perf_core_ctl_notify_top_ld_0 = 0;
    msm_perf_core_ctl_notify_curr_cp_1 = 0;
    msm_perf_core_ctl_notify_curr_cp_0 = 0;
    msm_perf_core_ctl_notify_top_ld_1 = 0;
    aggr_top_load = msm_perf_core_ctl_notify_tld / 0x19;
    aggr_big_nr = msm_perf_core_ctl_notify_nrb / 0x19;
    top_load_0 = uVar1 / 0x19;
    curr_cap_0 = uVar2 / 0x19;
    if (msm_perf_core_ctl_notify_nrb % 0x19 != 0) {
      aggr_big_nr = msm_perf_core_ctl_notify_nrb / 0x19 + 1;
    }
    top_load_1 = uVar3 / 0x19;
    curr_cap_1 = uVar4 / 0x19;
    top_load_2 = msm_perf_core_ctl_notify_top_ld_2 / 0x19;
    curr_cap_2 = msm_perf_core_ctl_notify_curr_cp_2 / 0x19;
    msm_perf_core_ctl_notify_top_ld_2 = 0;
    msm_perf_core_ctl_notify_curr_cp_2 = 0;
    msm_perf_core_ctl_notify_tld = 0;
    msm_perf_core_ctl_notify_nrb = 0;
    msm_perf_core_ctl_notify_i = 0;
    queue_work_on(0x20,_system_wq,msm_perf_core_ctl_notify_sysfs_notify_work);
  }
  return 1;
}



//------------------------------------------------------------
// nr_notify_userspace @ 00101a4c size=116
// signature: undefined nr_notify_userspace(void)
// callers: []
//------------------------------------------------------------

void nr_notify_userspace(void)

{
  sysfs_notify(notify_kobj,0,"aggr_top_load");
  sysfs_notify(notify_kobj,0,"aggr_big_nr");
  sysfs_notify(notify_kobj,0,"top_load_cluster");
  sysfs_notify(notify_kobj,0,"curr_cap_cluster");
  return;
}



//------------------------------------------------------------
// get_game_start_pid @ 00101ac4 size=56
// signature: undefined get_game_start_pid(void)
// callers: []
//------------------------------------------------------------

long get_game_start_pid(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001086c3,(long)game_status_pid);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_game_start_pid @ 00101b00 size=148
// signature: undefined set_game_start_pid(void)
// callers: []
//------------------------------------------------------------

long set_game_start_pid(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined8 local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoll(param_3,0,&local_30);
  if (iVar2 == 0) {
    game_status_pid = (undefined4)local_30;
  }
  else {
    _printk(&DAT_00108676,iVar2);
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// events_notify_userspace @ 00101b98 size=188
// signature: undefined events_notify_userspace(void)
// callers: []
//------------------------------------------------------------

undefined8 events_notify_userspace(void)

{
  long lVar1;
  char cVar2;
  undefined8 uVar3;
  ulong uVar4;
  
  lVar1 = sp_el0;
  do {
    *(undefined4 *)(lVar1 + 0x30) = 1;
    DataMemoryBarrier(2,3);
    uVar3 = _raw_spin_lock_irqsave(&events_group);
    if (DAT_001077ec == '\0') {
      _raw_spin_unlock_irqrestore(&events_group,uVar3);
      schedule();
      uVar4 = kthread_should_stop();
      if ((uVar4 & 1) != 0) {
        return 0;
      }
      uVar3 = _raw_spin_lock_irqsave(&events_group);
    }
    *(undefined4 *)(lVar1 + 0x30) = 0;
    cVar2 = DAT_001077ec;
    DataMemoryBarrier(2,3);
    DAT_001077ec = '\0';
    _raw_spin_unlock_irqrestore(&events_group,uVar3);
    if (cVar2 != '\0') {
      sysfs_notify(events_kobj,0,"cpu_hotplug");
    }
  } while( true );
}



//------------------------------------------------------------
// show_cpu_hotplug @ 00101c58 size=48
// signature: undefined show_cpu_hotplug(void)
// callers: []
//------------------------------------------------------------

long show_cpu_hotplug(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010850a);
  return (long)iVar1;
}



//------------------------------------------------------------
// show_big_nr @ 00101c8c size=56
// signature: undefined show_big_nr(void)
// callers: []
//------------------------------------------------------------

long show_big_nr(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00108036,aggr_big_nr);
  return (long)iVar1;
}



//------------------------------------------------------------
// show_top_load @ 00101cc8 size=56
// signature: undefined show_top_load(void)
// callers: []
//------------------------------------------------------------

long show_top_load(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00108036,aggr_top_load);
  return (long)iVar1;
}



//------------------------------------------------------------
// show_top_load_cluster @ 00101d04 size=72
// signature: undefined show_top_load_cluster(void)
// callers: []
//------------------------------------------------------------

long show_top_load_cluster(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%u %u %u\n",top_load_0,top_load_1,top_load_2);
  return (long)iVar1;
}



//------------------------------------------------------------
// show_curr_cap_cluster @ 00101d50 size=72
// signature: undefined show_curr_cap_cluster(void)
// callers: []
//------------------------------------------------------------

long show_curr_cap_cluster(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"%u %u %u\n",curr_cap_0,curr_cap_1,curr_cap_2);
  return (long)iVar1;
}



//------------------------------------------------------------
// show_perf_gfx_evts @ 00101d9c size=412
// signature: undefined show_perf_gfx_evts(void)
// callers: []
//------------------------------------------------------------

ulong show_perf_gfx_evts(undefined8 param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  ulong uVar8;
  
  iVar5 = wait_for_completion_interruptible(&gfx_evt_arrival);
  if (iVar5 == 0) {
    uVar6 = _raw_spin_lock_irqsave(&gfx_circ_buff_lock);
    uVar1 = curr_pos_1;
    uVar2 = curr_pos_0 - curr_pos_1 & 0x1ff;
    uVar3 = -(uVar2 + curr_pos_1);
    curr_pos_1 = uVar2 + curr_pos_1 & 0x1ff;
    if (-1 < (int)uVar3) {
      curr_pos_1 = -(uVar3 & 0x1ff);
    }
    _raw_spin_unlock_irqrestore(&gfx_circ_buff_lock,uVar6);
    uVar8 = 0;
    for (; uVar2 != 0; uVar2 = uVar2 - 1) {
      uVar3 = uVar1 & 0x1ff;
      if (-1 < (int)-uVar1) {
        uVar3 = -(-uVar1 & 0x1ff);
      }
      uVar7 = (ulong)uVar3;
      if (0x1ff < uVar3) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x101f38);
        (*pcVar4)();
      }
      if ((((0x4000 < (uVar7 << 5 | 4)) || (0x4000 < (uVar7 << 5 | 8))) ||
          (0x4000 < (uVar7 << 5 | 0x18))) || (0x4000 < (uVar7 << 5 | 0x10))) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(1,0x101f34);
        (*pcVar4)();
      }
      iVar5 = scnprintf(param_3 + uVar8,0x1000 - uVar8,"%d %d %u %d %lu :",
                        *(undefined4 *)(gpu_circ_buff + uVar7 * 0x20),
                        *(undefined4 *)(gpu_circ_buff + uVar7 * 0x20 + 4),
                        *(undefined4 *)(gpu_circ_buff + uVar7 * 0x20 + 8),
                        *(undefined4 *)(gpu_circ_buff + uVar7 * 0x20 + 0x18),
                        *(long *)(gpu_circ_buff + uVar7 * 0x20 + 0x10) / 1000);
      uVar8 = uVar8 + (long)iVar5;
      if (0xfff < uVar8) {
        _printk(&DAT_001080b0);
        return uVar8;
      }
      uVar1 = uVar1 + 1;
    }
  }
  else {
    uVar8 = 0;
  }
  return uVar8;
}



//------------------------------------------------------------
// scmi_plh_init @ 00101f3c size=252
// signature: undefined scmi_plh_init(void)
// callers: []
//------------------------------------------------------------

undefined8 scmi_plh_init(long param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  code *pcVar3;
  
  uVar1 = get_qcom_scmi_device();
  if (uVar1 < 0xfffffffffffff001) {
    if ((uVar1 != 0) && (*(long *)(uVar1 + 0x3a0) != 0)) {
      pcVar3 = *(code **)(*(long *)(uVar1 + 0x3a0) + 0x18);
      if (*(int *)(pcVar3 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x101fa8);
        (*pcVar3)();
      }
      plh_ops = (*pcVar3)(uVar1,0x80,&plh_handle);
      if (plh_ops != 0) goto LAB_00101fb8;
    }
    _dev_err(param_1 + 0x10,"plh: Error in %s, ret = %d\n","scmi_plh_init",0xffffffea);
  }
  else {
    if ((int)uVar1 == -0x205) {
      return 0xfffffdfb;
    }
    _dev_err(param_1 + 0x10,"plh: Error no plh device, ret = %d\n",uVar1 & 0xffffffff);
  }
LAB_00101fb8:
  if (((param_kobj == 0) ||
      (uVar2 = sysfs_update_group(param_kobj,plh_param_attr_group), param_kobj == 0)) ||
     ((int)uVar2 != 0)) {
    _printk(&DAT_00107fb9);
    uVar2 = 0xfffffff4;
  }
  return uVar2;
}



//------------------------------------------------------------
// get_splh_notif @ 0010203c size=56
// signature: undefined get_splh_notif(void)
// callers: []
//------------------------------------------------------------

long get_splh_notif(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,splh_notif);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_splh_notif @ 00102078 size=1452
// signature: undefined set_splh_notif(void)
// callers: []
//------------------------------------------------------------

long set_splh_notif(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  char *pcVar9;
  size_t sVar10;
  char *pcVar11;
  undefined *puVar12;
  undefined8 uVar13;
  code *pcVar14;
  uint uVar15;
  ulong uVar16;
  ulong uVar17;
  ulong uVar18;
  uint *puVar19;
  ulong uVar20;
  undefined8 *puVar21;
  uint uVar22;
  int iVar23;
  ushort local_1dc [2];
  uint local_1d8 [45];
  undefined4 local_124;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 local_110;
  undefined8 local_108;
  undefined8 local_100;
  undefined8 local_f8;
  undefined8 local_f0;
  undefined8 local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined8 local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar8 = sp_el0;
  local_70 = *(long *)(lVar8 + 0x638);
  lVar8 = strnstr(param_3,&DAT_00108413,5);
  if (lVar8 == 0) {
    if ((splh_init_done & 1) == 0) {
      _printk(&DAT_001084cc);
      param_4 = -0x16;
      goto LAB_00102188;
    }
    iVar5 = sscanf(param_3,"%du",&splh_notif);
    if (iVar5 < 0) {
      param_4 = (long)iVar5;
      goto LAB_00102188;
    }
    if ((plh_handle == 0) || (plh_ops == (undefined8 *)0x0)) {
      _printk(&DAT_00108016);
      goto LAB_00102188;
    }
    if (splh_notif == 0) {
      pcVar14 = (code *)plh_ops[3];
      uVar13 = 5;
      local_124 = 0;
    }
    else {
      pcVar14 = (code *)plh_ops[2];
      local_124 = splh_notif;
      uVar13 = 4;
    }
    if (*(int *)(pcVar14 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar14 = (code *)SoftwareBreakpoint(0x8228,0x10217c);
      (*pcVar14)();
    }
    iVar5 = (*pcVar14)(plh_handle,&local_124,0x53504c48414c474f,uVar13,4);
    if (-1 < iVar5) goto LAB_00102188;
    puVar12 = &DAT_0010858a;
  }
  else {
    splh_init_done = 0;
    local_1dc[0] = 0;
    local_78 = 0;
    local_80 = 0;
    local_88 = 0;
    local_90 = 0;
    local_98 = 0;
    local_a0 = 0;
    local_a8 = 0;
    local_b0 = 0;
    local_b8 = 0;
    local_c0 = 0;
    local_c8 = 0;
    local_d0 = 0;
    local_d8 = 0;
    local_e0 = 0;
    local_e8 = 0;
    local_f0 = 0;
    local_f8 = 0;
    local_100 = 0;
    local_108 = 0;
    local_110 = 0;
    local_118 = 0;
    local_120 = 0;
    if (((param_3 != (char *)0x0) && (plh_handle != 0)) && (plh_ops != (undefined8 *)0x0)) {
      puVar21 = &local_120;
      pcVar9 = param_3;
      uVar3 = 0;
      do {
        uVar22 = uVar3;
        pcVar9 = strchr(pcVar9 + 1,0x3a);
        uVar3 = uVar22 + 1;
      } while (pcVar9 != (char *)0x0);
      iVar5 = sscanf(param_3,"Init:%hu",local_1dc);
      if (((iVar5 != 0) && ((uVar22 & 0xffff) - 1 == (uint)local_1dc[0])) &&
         (0xfffffff7 < local_1dc[0] - 9)) {
        sVar10 = strlen(param_3);
        lVar8 = strnchr(param_3,sVar10,0x3a);
        sVar10 = strlen((char *)(lVar8 + 1));
        pcVar9 = (char *)strnchr((char *)(lVar8 + 1),sVar10,0x3a);
        uVar4 = local_1dc[0];
        if (pcVar9 != (char *)0x0) {
          local_124 = CONCAT22(local_124._2_2_,local_1dc[0]);
          pcVar11 = pcVar9;
          uVar3 = 0;
          do {
            uVar22 = uVar3;
            pcVar11 = strchr(pcVar11 + 1,0x2c);
            uVar3 = uVar22 + 1;
          } while (pcVar11 != (char *)0x0);
          uVar22 = uVar22 & 0xffff;
          uVar15 = (uint)uVar4 * 2;
          uVar3 = 0;
          if (uVar4 != 0) {
            uVar3 = uVar22 / uVar15;
          }
          if ((uVar22 == uVar3 * uVar15 && uVar15 <= uVar22) && uVar3 < 6) {
            local_124 = CONCAT22((short)uVar3,(undefined2)local_124);
            if (uVar4 == 0) {
              uVar15 = 2;
            }
            else {
              iVar5 = uVar3 * 2;
              uVar22 = 0;
              iVar2 = iVar5 + -1;
              uVar15 = 2;
              if (uVar3 == 0 || iVar2 == 0) {
                iVar5 = 1;
              }
              do {
                iVar6 = sscanf(pcVar9,":%hu",puVar21);
                if (iVar6 != 1) goto LAB_00102324;
                sVar10 = strlen(pcVar9);
                pcVar9 = (char *)strnchr(pcVar9,sVar10,0x2c);
                if (pcVar9 == (char *)0x0) goto LAB_00102324;
                uVar15 = uVar15 + 1;
                puVar21 = (undefined8 *)((long)puVar21 + 2);
                iVar6 = iVar5;
                iVar23 = iVar2;
                do {
                  iVar7 = sscanf(pcVar9,",%hu",puVar21);
                  if (iVar7 != 1) goto LAB_00102324;
                  pcVar9 = pcVar9 + 1;
                  if (iVar23 != 0) {
                    sVar10 = strlen(pcVar9);
                    pcVar9 = (char *)strnchr(pcVar9,sVar10,0x2c);
                    if (pcVar9 == (char *)0x0) goto LAB_00102324;
                  }
                  puVar21 = (undefined8 *)((long)puVar21 + 2);
                  iVar6 = iVar6 + -1;
                  uVar15 = uVar15 + 1;
                  iVar23 = iVar23 + -1;
                } while (iVar6 != 0);
                if (uVar22 != local_1dc[0] - 1) {
                  sVar10 = strlen(pcVar9);
                  pcVar9 = (char *)strnchr(pcVar9,sVar10,0x3a);
                  if (pcVar9 == (char *)0x0) goto LAB_00102324;
                }
                uVar22 = uVar22 + 1;
              } while (uVar22 < local_1dc[0]);
            }
            uVar22 = uVar15 & 0xffff;
            local_1d8[0x2c] = 0;
            local_1d8[0x1c] = 0;
            local_1d8[0x1d] = 0;
            local_1d8[0x1e] = 0;
            local_1d8[0x1f] = 0;
            local_1d8[0x28] = 0;
            local_1d8[0x29] = 0;
            local_1d8[0x2a] = 0;
            local_1d8[0x2b] = 0;
            local_1d8[0x24] = 0;
            local_1d8[0x25] = 0;
            local_1d8[0x26] = 0;
            local_1d8[0x27] = 0;
            local_1d8[0x20] = 0;
            local_1d8[0x21] = 0;
            local_1d8[0x22] = 0;
            local_1d8[0x23] = 0;
            uVar15 = uVar15 & 1;
            local_1d8[0x18] = 0;
            local_1d8[0x19] = 0;
            local_1d8[0x1a] = 0;
            local_1d8[0x1b] = 0;
            local_1d8[0x14] = 0;
            local_1d8[0x15] = 0;
            local_1d8[0x16] = 0;
            local_1d8[0x17] = 0;
            local_1d8[0x10] = 0;
            local_1d8[0x11] = 0;
            local_1d8[0x12] = 0;
            local_1d8[0x13] = 0;
            local_1d8[0xc] = 0;
            local_1d8[0xd] = 0;
            local_1d8[0xe] = 0;
            local_1d8[0xf] = 0;
            local_1d8[8] = 0;
            local_1d8[9] = 0;
            local_1d8[10] = 0;
            local_1d8[0xb] = 0;
            local_1d8[4] = 0;
            local_1d8[5] = 0;
            local_1d8[6] = 0;
            local_1d8[7] = 0;
            local_1d8[0] = 0;
            local_1d8[1] = 0;
            local_1d8[2] = 0;
            local_1d8[3] = 0;
            if (uVar22 < 2) {
              if (uVar15 != 0) {
                uVar18 = 0;
                uVar16 = 0;
                puVar19 = local_1d8;
                goto LAB_00102570;
              }
            }
            else {
              uVar1 = uVar22 >> 1;
              if (uVar1 < 2) {
                uVar1 = 1;
              }
              uVar16 = 0;
              uVar18 = 0;
              do {
                uVar20 = uVar18;
                uVar17 = uVar16;
                if (0x59 < uVar17) goto LAB_00102620;
                if ((0x5a < uVar17 + 1) || (uVar20 == 0xb4)) goto LAB_0010261c;
                uVar18 = uVar20 + 4;
                uVar16 = uVar17 + 2;
                *(uint *)((long)local_1d8 + uVar20) =
                     CONCAT22(*(undefined2 *)(((ulong)&local_124 | 2) + uVar20),
                              *(undefined2 *)((long)&local_124 + uVar20));
              } while (uVar1 << 2 != (int)uVar18);
              if (uVar15 != 0) {
                if (0x59 < (uint)uVar16) {
LAB_00102620:
                    /* WARNING: Does not return */
                  pcVar14 = (code *)SoftwareBreakpoint(0x5512,0x102624);
                  (*pcVar14)();
                }
                if ((0x57 < uVar17) || (0xac < uVar20)) goto LAB_0010261c;
                puVar19 = (uint *)((long)local_1d8 + uVar20 + 4);
LAB_00102570:
                if ((0xb3 < uVar16 * 2) || (0xb0 < uVar18)) {
LAB_0010261c:
                    /* WARNING: Does not return */
                  pcVar14 = (code *)SoftwareBreakpoint(1,0x102620);
                  (*pcVar14)();
                }
                *puVar19 = (uint)*(ushort *)((long)local_1d8 + uVar16 * 2 + 0xb4);
              }
            }
            if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
              pcVar14 = (code *)SoftwareBreakpoint(0x8229,0x1025dc);
              (*pcVar14)();
            }
            iVar5 = (*(code *)*plh_ops)(plh_handle,local_1d8,0x53504c48414c474f,1,
                                        (uVar15 + uVar22) * 2);
            if (-1 < iVar5) {
              splh_init_done = 1;
              _printk(&DAT_0010850c,local_1dc[0],uVar3,*(undefined2 *)((long)puVar21 + -2),uVar22);
              goto LAB_00102188;
            }
            _printk(&DAT_00107eeb);
          }
        }
      }
    }
LAB_00102324:
    puVar12 = &DAT_001081a7;
    iVar5 = -0x16;
  }
  _printk(puVar12,iVar5);
LAB_00102188:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_splh_sample_ms @ 00102628 size=56
// signature: undefined get_splh_sample_ms(void)
// callers: []
//------------------------------------------------------------

long get_splh_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,splh_sample_ms);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_splh_sample_ms @ 00102664 size=340
// signature: undefined set_splh_sample_ms(void)
// callers: []
//------------------------------------------------------------

long set_splh_sample_ms(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  int local_4c;
  long local_48;
  
  iVar2 = splh_sample_ms;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (plh_handle == 0 || plh_ops == (undefined8 *)0x0) {
    _printk(&DAT_0010841a);
    param_4 = -0x16;
  }
  else {
    iVar4 = sscanf(param_3,"%du",&splh_sample_ms);
    if (iVar4 < 0) {
      puVar5 = &DAT_00108638;
    }
    else {
      if (splh_sample_ms < 2) {
        splh_sample_ms = 1;
      }
      if (0x1d < splh_sample_ms) {
        splh_sample_ms = 0x1e;
      }
      local_4c = splh_sample_ms;
      if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x102734);
        (*pcVar3)();
      }
      iVar4 = (*(code *)*plh_ops)(plh_handle,&local_4c,0x53504c48414c474f,2,4);
      if (-1 < iVar4) goto LAB_0010273c;
      puVar5 = &DAT_001082b1;
      splh_sample_ms = iVar2;
    }
    _printk(puVar5,iVar4);
    param_4 = (long)iVar4;
  }
LAB_0010273c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_splh_log_level @ 001027bc size=56
// signature: undefined get_splh_log_level(void)
// callers: []
//------------------------------------------------------------

long get_splh_log_level(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,splh_log_level);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_splh_log_level @ 001027f8 size=340
// signature: undefined set_splh_log_level(void)
// callers: []
//------------------------------------------------------------

long set_splh_log_level(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  int local_4c;
  long local_48;
  
  iVar2 = splh_log_level;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (plh_handle == 0 || plh_ops == (undefined8 *)0x0) {
    _printk(&DAT_0010841a);
    param_4 = -0x16;
  }
  else {
    iVar4 = sscanf(param_3,"%du",&splh_log_level);
    if (iVar4 < 0) {
      puVar5 = &DAT_001085f0;
    }
    else {
      if (splh_log_level < 1) {
        splh_log_level = 0;
      }
      if (0xe < splh_log_level) {
        splh_log_level = 0xf;
      }
      local_4c = splh_log_level;
      if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1028c8);
        (*pcVar3)();
      }
      iVar4 = (*(code *)*plh_ops)(plh_handle,&local_4c,0x53504c48414c474f,3,4);
      if (-1 < iVar4) goto LAB_001028d0;
      puVar5 = &DAT_00107f38;
      splh_log_level = iVar2;
    }
    _printk(puVar5,iVar4);
    param_4 = (long)iVar4;
  }
LAB_001028d0:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_lplh_notif @ 00102950 size=56
// signature: undefined get_lplh_notif(void)
// callers: []
//------------------------------------------------------------

long get_lplh_notif(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,lplh_notif);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_lplh_notif @ 0010298c size=1444
// signature: undefined set_lplh_notif(void)
// callers: []
//------------------------------------------------------------

long set_lplh_notif(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  long lVar5;
  char *pcVar6;
  size_t sVar7;
  undefined *puVar8;
  char *pcVar9;
  undefined8 uVar10;
  ushort uVar11;
  uint uVar12;
  code *pcVar13;
  ulong uVar14;
  uint *puVar15;
  ulong uVar16;
  uint uVar17;
  uint uVar18;
  undefined2 *puVar19;
  uint uVar20;
  char *local_158;
  undefined2 local_14c [2];
  undefined2 local_148 [2];
  ushort local_144 [2];
  uint local_140 [24];
  undefined2 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 uStack_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined2 local_78;
  long local_70;
  
  lVar5 = sp_el0;
  local_70 = *(long *)(lVar5 + 0x638);
  lVar5 = strnstr(param_3,&DAT_00108413,5);
  if (lVar5 == 0) {
    if ((lplh_init_done & 1) == 0) {
      _printk(&DAT_00108070);
      param_4 = -0x16;
      goto LAB_00102a9c;
    }
    iVar4 = sscanf(param_3,"%du",&lplh_notif);
    if (iVar4 < 0) {
      param_4 = (long)iVar4;
      goto LAB_00102a9c;
    }
    if ((plh_handle == 0) || (plh_ops == (undefined8 *)0x0)) {
      _printk(&DAT_001082e8);
      goto LAB_00102a9c;
    }
    if (lplh_notif == 0) {
      pcVar13 = (code *)plh_ops[3];
      uVar10 = 5;
      local_d8 = (ulong)local_d8._4_4_ << 0x20;
    }
    else {
      pcVar13 = (code *)plh_ops[2];
      local_d8 = CONCAT44(local_d8._4_4_,lplh_notif);
      uVar10 = 4;
    }
    if (*(int *)(pcVar13 + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
      pcVar13 = (code *)SoftwareBreakpoint(0x8228,0x102a90);
      (*pcVar13)();
    }
    iVar4 = (*pcVar13)(plh_handle,&local_d8,0x4c504c48414c474f,uVar10,4);
    if (-1 < iVar4) goto LAB_00102a9c;
    puVar8 = &DAT_00107fe7;
  }
  else {
    lplh_init_done = 0;
    local_78 = 0;
    local_88 = 0;
    uStack_80 = 0;
    local_98 = 0;
    uStack_90 = 0;
    local_a8 = 0;
    uStack_a0 = 0;
    local_b8 = 0;
    uStack_b0 = 0;
    local_c8 = 0;
    uStack_c0 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    local_144[0] = 0;
    local_148[0] = 0;
    local_14c[0] = 0;
    if (((param_3 != (char *)0x0) && (plh_handle != 0)) && (plh_ops != (undefined8 *)0x0)) {
      local_158 = param_3;
      iVar4 = sscanf(param_3,"Init:%hu",local_144);
      uVar2 = local_144[0];
      if ((iVar4 != 0) && (0xfffffffb < local_144[0] - 5)) {
        local_d8 = CONCAT62(local_d8._2_6_,local_144[0]);
        pcVar6 = local_158;
        uVar3 = 0;
        do {
          uVar11 = uVar3;
          pcVar6 = strchr(pcVar6 + 1,0x3a);
          uVar3 = uVar11 + 1;
        } while (pcVar6 != (char *)0x0);
        if ((uVar11 != 0) && (uVar11 - 1 == (uint)uVar2)) {
          sVar7 = strlen(param_3);
          lVar5 = strnchr(param_3,sVar7,0x3a);
          sVar7 = strlen((char *)(lVar5 + 1));
          lVar5 = strnchr((char *)(lVar5 + 1),sVar7,0x3a);
          local_158 = (char *)(lVar5 + 1);
          if ((local_158 != (char *)0x0) && (*local_158 != '\0')) {
            puVar19 = (undefined2 *)((ulong)&local_d8 | 2);
            if (local_144[0] == 0) {
              uVar20 = 1;
            }
            else {
              uVar17 = 0;
              uVar20 = 1;
              do {
                local_148[0] = 0;
                if ((local_158 == (char *)0x0) || (*local_158 == '\0')) goto LAB_00102ef0;
                iVar4 = sscanf(local_158,"%hu,",local_148);
                pcVar6 = local_158;
                if (iVar4 == 0) goto LAB_00102ef0;
                *puVar19 = local_148[0];
                sVar7 = strlen(local_158);
                local_158 = (char *)strnchr(pcVar6,sVar7,0x2c);
                if (((local_158 == (char *)0x0) ||
                    (pcVar6 = strsep(&local_158,":"), pcVar6 == (char *)0x0)) || (*pcVar6 == '\0'))
                goto LAB_00102ef0;
                pcVar9 = pcVar6;
                uVar1 = 1;
                do {
                  uVar12 = uVar1;
                  pcVar9 = strchr(pcVar9 + 1,0x2c);
                  uVar1 = uVar12 + 1;
                } while (pcVar9 != (char *)0x0);
                if (((uVar12 & 1) != 0) || (0xb < (uVar12 & 0xffff))) goto LAB_00102ef0;
                uVar1 = (uVar12 & 0xffff) >> 1;
                uVar20 = uVar20 + 2;
                puVar19[1] = (short)uVar1;
                puVar19 = puVar19 + 2;
                if (1 < (uVar12 & 0xffff)) {
                  if (uVar1 < 2) {
                    uVar1 = 1;
                  }
                  uVar18 = uVar12 >> 1 & 0x7fff;
                  uVar20 = uVar20 + uVar1 * 2;
                  if ((uVar12 >> 1 & 0x7ffe) == 0) {
                    uVar18 = 1;
                  }
                  do {
                    local_14c[0] = 0;
                    if ((pcVar6 == (char *)0x0) ||
                       (iVar4 = sscanf(pcVar6,",%hu",local_14c), iVar4 != 1)) goto LAB_00102ef0;
                    pcVar6 = pcVar6 + 1;
                    *puVar19 = local_14c[0];
                    if ((pcVar6 == (char *)0x0) || (*pcVar6 == '\0')) goto LAB_00102ef0;
                    sVar7 = strlen(pcVar6);
                    pcVar6 = (char *)strnchr(pcVar6,sVar7,0x2c);
                    if ((pcVar6 == (char *)0x0) ||
                       (iVar4 = sscanf(pcVar6,",%hu",local_14c), iVar4 != 1)) goto LAB_00102ef0;
                    puVar19[1] = local_14c[0];
                    sVar7 = strlen(pcVar6 + 1);
                    pcVar6 = (char *)strnchr(pcVar6 + 1,sVar7,0x2c);
                    puVar19 = puVar19 + 2;
                    uVar18 = uVar18 - 1;
                  } while (uVar18 != 0);
                }
                uVar17 = uVar17 + 1;
              } while (uVar17 < local_144[0]);
            }
            uVar17 = uVar20 & 0xffff;
            uVar20 = uVar20 & 1;
            local_e0 = 0;
            local_140[0x14] = 0;
            local_140[0x15] = 0;
            local_140[0x16] = 0;
            local_140[0x17] = 0;
            local_140[0x10] = 0;
            local_140[0x11] = 0;
            local_140[0x12] = 0;
            local_140[0x13] = 0;
            local_140[0xc] = 0;
            local_140[0xd] = 0;
            local_140[0xe] = 0;
            local_140[0xf] = 0;
            local_140[8] = 0;
            local_140[9] = 0;
            local_140[10] = 0;
            local_140[0xb] = 0;
            local_140[4] = 0;
            local_140[5] = 0;
            local_140[6] = 0;
            local_140[7] = 0;
            local_140[0] = 0;
            local_140[1] = 0;
            local_140[2] = 0;
            local_140[3] = 0;
            if (uVar17 < 2) {
              if (uVar20 != 0) {
                uVar14 = 0;
                lVar5 = 0;
                puVar15 = local_140;
                goto LAB_00102e78;
              }
            }
            else {
              uVar1 = uVar17 >> 1;
              lVar5 = 0;
              if (uVar1 < 2) {
                uVar1 = 1;
              }
              uVar14 = 0;
              do {
                uVar16 = uVar14;
                if ((int)uVar16 == 0x60) goto LAB_00102f28;
                if (uVar16 == 0x60) goto LAB_00102f2c;
                uVar14 = uVar16 + 4;
                lVar5 = lVar5 + 2;
                *(uint *)((long)local_140 + uVar16) =
                     CONCAT22(*(undefined2 *)(((ulong)&local_d8 | 2) + uVar16),
                              *(undefined2 *)((long)&local_d8 + uVar16));
              } while (uVar1 << 2 != (int)uVar14);
              if (uVar20 != 0) {
                if (0x30 < (uint)lVar5) {
LAB_00102f28:
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(0x5512,0x102f2c);
                  (*pcVar13)();
                }
                if ((uVar14 == 100) || (0x5a < uVar16)) goto LAB_00102f2c;
                puVar15 = (uint *)((long)local_140 + uVar16 + 4);
LAB_00102e78:
                if ((lVar5 == 0x32) || (0x5e < uVar14)) {
LAB_00102f2c:
                    /* WARNING: Does not return */
                  pcVar13 = (code *)SoftwareBreakpoint(1,0x102f30);
                  (*pcVar13)();
                }
                *puVar15 = (uint)*(ushort *)((long)&local_d8 + lVar5 * 2);
              }
            }
            if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
              pcVar13 = (code *)SoftwareBreakpoint(0x8229,0x102edc);
              (*pcVar13)();
            }
            iVar4 = (*(code *)*plh_ops)(plh_handle,local_140,0x4c504c48414c474f,1,
                                        (uVar20 + uVar17) * 2);
            if (-1 < iVar4) {
              _printk(&DAT_00108552,local_144[0],puVar19[-1],uVar17);
              lplh_init_done = 1;
              goto LAB_00102a9c;
            }
            _printk(&DAT_001081df);
          }
        }
      }
    }
LAB_00102ef0:
    puVar8 = &DAT_00108455;
    iVar4 = -0x16;
  }
  _printk(puVar8,iVar4);
LAB_00102a9c:
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_lplh_sample_ms @ 00102f34 size=56
// signature: undefined get_lplh_sample_ms(void)
// callers: []
//------------------------------------------------------------

long get_lplh_sample_ms(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,lplh_sample_ms);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_lplh_sample_ms @ 00102f70 size=340
// signature: undefined set_lplh_sample_ms(void)
// callers: []
//------------------------------------------------------------

long set_lplh_sample_ms(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  int local_4c;
  long local_48;
  
  iVar2 = lplh_sample_ms;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (plh_handle == 0 || plh_ops == (undefined8 *)0x0) {
    _printk(&DAT_0010841a);
    param_4 = -0x16;
  }
  else {
    iVar4 = sscanf(param_3,"%du",&lplh_sample_ms);
    if (iVar4 < 0) {
      puVar5 = &DAT_001085b9;
    }
    else {
      if (lplh_sample_ms < 2) {
        lplh_sample_ms = 1;
      }
      if (0x1d < lplh_sample_ms) {
        lplh_sample_ms = 0x1e;
      }
      local_4c = lplh_sample_ms;
      if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x103040);
        (*pcVar3)();
      }
      iVar4 = (*(code *)*plh_ops)(plh_handle,&local_4c,0x4c504c48414c474f,2,4);
      if (-1 < iVar4) goto LAB_00103048;
      puVar5 = &DAT_00108370;
      lplh_sample_ms = iVar2;
    }
    _printk(puVar5,iVar4);
    param_4 = (long)iVar4;
  }
LAB_00103048:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// get_lplh_log_level @ 001030c8 size=56
// signature: undefined get_lplh_log_level(void)
// callers: []
//------------------------------------------------------------

long get_lplh_log_level(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_001080ce,lplh_log_level);
  return (long)iVar1;
}



//------------------------------------------------------------
// set_lplh_log_level @ 00103104 size=340
// signature: undefined set_lplh_log_level(void)
// callers: []
//------------------------------------------------------------

long set_lplh_log_level(undefined8 param_1,undefined8 param_2,char *param_3,long param_4)

{
  long lVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  undefined *puVar5;
  int local_4c;
  long local_48;
  
  iVar2 = lplh_log_level;
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  if (plh_handle == 0 || plh_ops == (undefined8 *)0x0) {
    _printk(&DAT_0010841a);
    param_4 = -0x16;
  }
  else {
    iVar4 = sscanf(param_3,"%du",&lplh_log_level);
    if (iVar4 < 0) {
      puVar5 = &DAT_001083a7;
    }
    else {
      if (lplh_log_level < 1) {
        lplh_log_level = 0;
      }
      if (0xe < lplh_log_level) {
        lplh_log_level = 0xf;
      }
      local_4c = lplh_log_level;
      if (*(int *)((code *)*plh_ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8229,0x1031d4);
        (*pcVar3)();
      }
      iVar4 = (*(code *)*plh_ops)(plh_handle,&local_4c,0x4c504c48414c474f,3,4);
      if (-1 < iVar4) goto LAB_001031dc;
      puVar5 = &DAT_00108246;
      lplh_log_level = iVar2;
    }
    _printk(puVar5,iVar4);
    param_4 = (long)iVar4;
  }
LAB_001031dc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00103284 size=1208
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 init_module(void)

{
  undefined4 *puVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  long *plVar7;
  long lVar8;
  long lVar9;
  undefined *puVar10;
  ulong uVar11;
  
  msm_perf_kset = kset_create_and_add("msm_performance",0,_kernel_kobj);
  if (msm_perf_kset == 0) {
    return 0xfffffff4;
  }
  param_kobj = kobject_create_and_add("parameters",msm_perf_kset + 0x18);
  if (param_kobj == 0) {
    puVar10 = &DAT_00108308;
LAB_001033a4:
    _printk(puVar10);
  }
  else {
    iVar4 = sysfs_create_group(param_kobj,param_attr_group);
    if (iVar4 != 0) {
      puVar10 = &DAT_0010869f;
      goto LAB_001033a4;
    }
  }
  events_kobj = kobject_create_and_add("events",msm_perf_kset + 0x18);
  if (events_kobj == 0) {
    puVar10 = &DAT_00108151;
LAB_001033b4:
    _printk(puVar10);
  }
  else {
    iVar4 = sysfs_create_group(events_kobj,events_attr_group);
    if (iVar4 != 0) {
      puVar10 = &DAT_0010869f;
      goto LAB_001033b4;
    }
    events_group = 0;
    uVar6 = kthread_create_on_node(events_notify_userspace,0,0xffffffff,"msm_perf:events_notify");
    if (uVar6 < 0xfffffffffffff001) {
      wake_up_process(uVar6);
      DAT_001077ed = 1;
      events_notify_thread = uVar6;
    }
    else {
      events_notify_thread = uVar6;
    }
  }
  notify_kobj = kobject_create_and_add("notify",msm_perf_kset + 0x18);
  if (notify_kobj == 0) {
    puVar10 = &DAT_00108178;
LAB_00103724:
    _printk(puVar10);
  }
  else {
    iVar4 = sysfs_create_group(notify_kobj,notify_attr_group);
    if (iVar4 != 0) {
      kobject_put(notify_kobj);
      puVar10 = &DAT_0010869f;
      goto LAB_00103724;
    }
  }
  iVar4 = 0;
  uVar6 = 0;
  while( true ) {
    uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)iVar4);
    if (_nr_cpu_ids <= uVar5) break;
    uVar6 = (ulong)((int)uVar6 + 1);
    iVar4 = uVar5 + 1;
  }
  plVar7 = (long *)kmalloc_trace(_kfree,0xdc0,0x10);
  pmu_events = plVar7;
  if (plVar7 != (long *)0x0) {
    if ((int)uVar6 < 0) {
      lVar9 = 0;
      *plVar7 = 0;
    }
    else {
      uVar6 = -(uVar6 >> 0x1f) & 0xffffffe000000000 | uVar6 << 5;
      lVar8 = __kmalloc(uVar6,0xdc0);
      plVar7 = pmu_events;
      *pmu_events = lVar8;
      lVar9 = 0;
      if (lVar8 != 0) {
        lVar9 = __kmalloc(uVar6,0xdc0);
        plVar7 = pmu_events;
        pmu_events[1] = lVar9;
        if (lVar9 != 0) {
          lVar9 = 0;
          while( true ) {
            uVar6 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar9);
            plVar7 = pmu_events;
            uVar5 = (uint)uVar6;
            if (_nr_cpu_ids <= uVar5) break;
            *(undefined4 *)
             (*pmu_events + (-(uVar6 >> 0x1f & 1) & 0xffffffe000000000 | (uVar6 & 0xffffffff) << 5))
                 = 8;
            puVar1 = (undefined4 *)(*plVar7 + ((long)(uVar6 << 0x20) >> 0x1b));
            iVar4 = qcom_pmu_event_supported(*puVar1,uVar6 & 0xffffffff);
            if ((iVar4 != 0) &&
               (_printk(&DAT_00107f6f,"set_event",*puVar1,uVar6 & 0xffffffff,iVar4), iVar4 < 0))
            break;
            plVar7 = pmu_events;
            *(undefined4 *)(pmu_events[1] + (long)(int)uVar5 * 0x20) = 0x11;
            puVar1 = (undefined4 *)(plVar7[1] + (long)(int)uVar5 * 0x20);
            iVar4 = qcom_pmu_event_supported(*puVar1,uVar6 & 0xffffffff);
            if ((iVar4 != 0) &&
               (_printk(&DAT_00107f6f,"set_event",*puVar1,uVar6 & 0xffffffff,iVar4),
               plVar7 = pmu_events, iVar4 < 0)) {
              if ((*(ulong *)(&__cpu_possible_mask + (uVar6 >> 3 & 0x1ffffff8)) >> (uVar6 & 0x3f) &
                  1) != 0) {
                uVar6 = uVar6 & 0xffffffff;
                *(undefined8 *)(*pmu_events + uVar6 * 0x20 + 8) = 0;
                *(undefined8 *)(*plVar7 + uVar6 * 0x20 + 0x10) = 0;
                *(undefined8 *)(*plVar7 + uVar6 * 0x20 + 0x18) = 0;
                *(undefined8 *)(plVar7[1] + uVar6 * 0x20 + 8) = 0;
                *(undefined8 *)(plVar7[1] + uVar6 * 0x20 + 0x10) = 0;
                *(undefined8 *)(plVar7[1] + uVar6 * 0x20 + 0x18) = 0;
              }
              break;
            }
            if (0x1f < uVar5) goto LAB_00103738;
            if (*(ulong *)(&cpu_scale + *(long *)(&__per_cpu_offset + (uVar6 & 0xffffffff) * 8)) <
                min_cpu_capacity) {
              min_cpu_capacity =
                   *(ulong *)(&cpu_scale + *(long *)(&__per_cpu_offset + (uVar6 & 0xffffffff) * 8));
            }
            lVar9 = uVar6 + 1;
          }
          goto LAB_00103634;
        }
        lVar9 = 1;
      }
    }
    lVar9 = lVar9 << 3;
    do {
      kfree(*(undefined8 *)((long)plVar7 + lVar9));
      plVar7 = pmu_events;
      *(undefined8 *)((long)pmu_events + lVar9) = 0;
      bVar3 = lVar9 != 0;
      lVar9 = lVar9 + -8;
    } while (bVar3);
    kfree();
    pmu_events = (long *)0x0;
  }
LAB_00103634:
  cpus_read_lock();
  uVar6 = 0;
  uVar11 = (ulong)_nr_cpu_ids;
  do {
    uVar6 = _find_next_bit(&__cpu_possible_mask,uVar11,uVar6 & 0xffffffff);
    uVar11 = (ulong)_nr_cpu_ids;
    if (uVar11 <= (uVar6 & 0xffffffff)) {
      __cpuhp_setup_state_cpuslocked
                (200,"msm_performance_cpu_hotplug",0,hotplug_notify_up,hotplug_notify_down,0);
      cpus_read_unlock();
      __platform_driver_register(&scmi_plh_driver,&__this_module);
      return 0;
    }
    if ((*(ulong *)(&__cpu_online_mask + (uVar6 >> 6 & 0x3ffffff) * 8) >> (uVar6 & 0x3f) & 1) == 0)
    {
      if (0x1f < (uVar6 & 0xffffffff)) {
LAB_00103738:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10373c);
        (*pcVar2)();
      }
      (&cpu_is_hp)[*(long *)(&__per_cpu_offset + (uVar6 & 0xffffffff) * 8)] = 1;
      uVar11 = (ulong)_nr_cpu_ids;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010a000 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [hotplug_notify_up, events_notify_userspace, show_perf_gfx_evts, msm_perf_events_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010a008 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [hotplug_notify_up, events_notify_userspace, show_perf_gfx_evts, msm_perf_events_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 0010a010 size=1
// signature: undefined ktime_get(void)
// callers: [msm_perf_events_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete @ 0010a018 size=1
// signature: undefined complete(void)
// callers: [msm_perf_events_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kset_create_and_add @ 0010a028 size=1
// signature: undefined kset_create_and_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kset_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_create_and_add @ 0010a030 size=1
// signature: undefined kobject_create_and_add(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_create_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010a038 size=1
// signature: undefined sysfs_create_group(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_create_on_node @ 0010a040 size=1
// signature: undefined kthread_create_on_node(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_create_on_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wake_up_process @ 0010a048 size=1
// signature: undefined wake_up_process(void)
// callers: [hotplug_notify_up, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wake_up_process(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010a050 size=1
// signature: undefined _printk(void)
// callers: [set_cpu_min_freq, set_game_start_pid, set_splh_sample_ms, freq_qos_request_init, init_module, set_splh_notif, set_lplh_sample_ms, set_splh_log_level, show_perf_gfx_evts, set_core_ctl_register, set_cpu_max_freq, set_lplh_log_level, scmi_plh_init, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010a068 size=1
// signature: undefined _find_next_bit(void)
// callers: [get_cpu_max_freq, set_cpu_min_freq, freq_qos_request_init, get_cpu_total_instruction, init_module, get_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010a078 size=1
// signature: undefined kmalloc_trace(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010a088 size=1
// signature: undefined __kmalloc(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pmu_event_supported @ 0010a098 size=1
// signature: undefined qcom_pmu_event_supported(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pmu_event_supported(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010a0a0 size=1
// signature: undefined kfree(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 0010a0a8 size=1
// signature: undefined cpus_read_lock(void)
// callers: [set_cpu_min_freq, init_module, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state_cpuslocked @ 0010a0b8 size=1
// signature: undefined __cpuhp_setup_state_cpuslocked(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state_cpuslocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 0010a0c0 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [set_cpu_min_freq, init_module, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 0010a0c8 size=1
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
// kobject_put @ 0010a0d0 size=1
// signature: undefined kobject_put(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010a0d8 size=1
// signature: undefined mutex_lock(void)
// callers: [hotplug_notify_up, hotplug_notify_down, set_cpu_min_freq, get_cpu_total_instruction, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010a0e0 size=1
// signature: undefined mutex_unlock(void)
// callers: [hotplug_notify_up, hotplug_notify_down, set_cpu_min_freq, get_cpu_total_instruction, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010a0f0 size=1
// signature: undefined scnprintf(void)
// callers: [show_cpu_hotplug, get_game_start_pid, show_top_load_cluster, get_splh_notif, show_curr_cap_cluster, get_splh_sample_ms, get_cpu_min_freq, get_lplh_log_level, get_cpu_max_freq, show_big_nr, show_top_load, get_lplh_sample_ms, show_perf_gfx_evts, get_splh_log_level, get_core_ctl_register, get_cpu_total_instruction, get_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strpbrk @ 0010a0f8 size=1
// signature: char * strpbrk(char * __s, char * __accept)
// callers: [set_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strpbrk(char *__s,char *__accept)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 0010a100 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [set_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010a108 size=1
// signature: undefined fortify_panic(void)
// callers: [set_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strlen @ 0010a110 size=1
// signature: size_t strlen(char * __s)
// callers: [set_cpu_min_freq, set_cpu_max_freq, set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

size_t strlen(char *__s)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnchr @ 0010a118 size=1
// signature: undefined strnchr(void)
// callers: [set_cpu_min_freq, set_cpu_max_freq, set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnchr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0010a120 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [set_lplh_sample_ms, set_splh_log_level, set_cpu_min_freq, set_splh_sample_ms, set_cpu_max_freq, set_lplh_log_level, set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_update_request @ 0010a130 size=1
// signature: undefined freq_qos_update_request(void)
// callers: [set_cpu_min_freq, set_cpu_max_freq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_update_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010a138 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [set_lplh_sample_ms, set_splh_log_level, set_cpu_min_freq, set_game_start_pid, set_splh_sample_ms, get_cpu_total_instruction, set_cpu_max_freq, set_lplh_log_level, set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_get @ 0010a140 size=1
// signature: undefined cpufreq_cpu_get(void)
// callers: [freq_qos_request_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_add_request @ 0010a148 size=1
// signature: undefined freq_qos_add_request(void)
// callers: [freq_qos_request_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_add_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpufreq_cpu_put @ 0010a150 size=1
// signature: undefined cpufreq_cpu_put(void)
// callers: [freq_qos_request_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpufreq_cpu_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// freq_qos_remove_request @ 0010a158 size=1
// signature: undefined freq_qos_remove_request(void)
// callers: [freq_qos_request_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void freq_qos_remove_request(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_pmu_read @ 0010a160 size=1
// signature: undefined qcom_pmu_read(void)
// callers: [get_cpu_total_instruction]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_pmu_read(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0010a168 size=1
// signature: undefined kstrtobool(void)
// callers: [set_core_ctl_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// core_ctl_notifier_register @ 0010a170 size=1
// signature: undefined core_ctl_notifier_register(void)
// callers: [set_core_ctl_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void core_ctl_notifier_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// core_ctl_notifier_unregister @ 0010a178 size=1
// signature: undefined core_ctl_notifier_unregister(void)
// callers: [set_core_ctl_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void core_ctl_notifier_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010a188 size=1
// signature: undefined queue_work_on(void)
// callers: [msm_perf_core_ctl_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_notify @ 0010a190 size=1
// signature: undefined sysfs_notify(void)
// callers: [events_notify_userspace, nr_notify_userspace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_notify(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoll @ 0010a198 size=1
// signature: undefined kstrtoll(void)
// callers: [set_game_start_pid]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoll(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// schedule @ 0010a1a0 size=1
// signature: undefined schedule(void)
// callers: [events_notify_userspace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kthread_should_stop @ 0010a1a8 size=1
// signature: undefined kthread_should_stop(void)
// callers: [events_notify_userspace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kthread_should_stop(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_interruptible @ 0010a1b0 size=1
// signature: undefined wait_for_completion_interruptible(void)
// callers: [show_perf_gfx_evts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_interruptible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_qcom_scmi_device @ 0010a1b8 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [scmi_plh_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_update_group @ 0010a1c0 size=1
// signature: undefined sysfs_update_group(void)
// callers: [scmi_plh_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_update_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010a1c8 size=1
// signature: undefined _dev_err(void)
// callers: [scmi_plh_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strnstr @ 0010a1d0 size=1
// signature: undefined strnstr(void)
// callers: [set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void strnstr(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strchr @ 0010a1d8 size=1
// signature: char * strchr(char * __s, int __c)
// callers: [set_splh_notif, set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strchr(char *__s,int __c)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strsep @ 0010a1e0 size=1
// signature: char * strsep(char * * __stringp, char * __delim)
// callers: [set_lplh_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

char * strsep(char **__stringp,char *__delim)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



