// Decompiled by Ghidra 12.2
// Program: qcom-pmu-lib.ko
// Image base: 00100000

//------------------------------------------------------------
// __qcom_pmu_read_all @ 001008a4 size=428
// signature: undefined __qcom_pmu_read_all(void)
// callers: [qcom_pmu_read_all_local, qcom_pmu_read_all]
//------------------------------------------------------------

undefined8 __qcom_pmu_read_all(ulong param_1,long param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  undefined8 uVar6;
  ulong uVar7;
  uint uVar8;
  char *pcVar9;
  ulong uVar10;
  char *pcVar11;
  long lVar12;
  
  if (qcom_pmu_inited == '\x01') {
    if ((param_2 == 0) ||
       ((*(ulong *)(&__cpu_possible_mask + ((param_1 & 0xffffffff) >> 3 & 0x1ffffff8)) >>
         (param_1 & 0x3f) & 1) == 0)) {
      uVar6 = 0xffffffea;
    }
    else {
      if (0x1f < (uint)param_1) {
LAB_00100a28:
                    /* WARNING: Does not return */
        pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x100a2c);
        (*pcVar5)();
      }
      pcVar9 = *(char **)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (param_1 & 0xffffffff) * 8));
      uVar6 = _raw_spin_lock_irqsave(pcVar9 + 0x150);
      if (((pcVar9[1] == '\0') && (*pcVar9 == '\0')) && (pcVar9[2] == '\0')) {
        piVar1 = (int *)(pcVar9 + 0x14c);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + 1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        bVar4 = false;
      }
      else {
        bVar4 = true;
      }
      _raw_spin_unlock_irqrestore(pcVar9 + 0x150,uVar6);
      uVar7 = (ulong)*(uint *)(pcVar9 + 0x148);
      if (*(uint *)(pcVar9 + 0x148) == 0) {
        uVar8 = 0;
      }
      else {
        uVar10 = 0;
        uVar8 = 0;
        pcVar11 = pcVar9 + 0x20;
        do {
          if (uVar10 == 9) goto LAB_00100a28;
          iVar2 = *(int *)(pcVar11 + -0x18);
          if (iVar2 != 0) {
            if (7 < uVar8) goto LAB_00100a28;
            lVar12 = (long)(int)uVar8;
            *(int *)(param_2 + lVar12 * 4) = iVar2;
            if (bVar4) {
              uVar6 = *(undefined8 *)pcVar11;
            }
            else {
              uVar6 = read_event(pcVar11 + -0x18,param_3 & 1);
            }
            uVar8 = uVar8 + 1;
            *(undefined8 *)(param_2 + lVar12 * 8 + 0x20) = uVar6;
            uVar7 = (ulong)*(uint *)(pcVar9 + 0x148);
          }
          uVar10 = uVar10 + 1;
          pcVar11 = pcVar11 + 0x28;
        } while (uVar10 < uVar7);
      }
      *(uint *)(param_2 + 0x60) = uVar8;
      if (!bVar4) {
        piVar1 = (int *)(pcVar9 + 0x14c);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
      }
      uVar6 = 0;
    }
  }
  else {
    uVar6 = 0xffffffed;
  }
  return uVar6;
}



//------------------------------------------------------------
// read_event @ 00100a60 size=312
// signature: undefined read_event(void)
// callers: [__qcom_pmu_read_all, __qcom_pmu_read]
//------------------------------------------------------------

void read_event(long param_1,ulong param_2)

{
  uint uVar1;
  int iVar2;
  long lVar3;
  undefined8 *puVar4;
  ulong local_50;
  undefined8 local_48;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  uVar1 = *(uint *)(param_1 + 0x20);
  local_30 = 0;
  local_40 = 0;
  uStack_38 = 0;
  local_50 = 0;
  local_48 = 0;
  if (uVar1 < 4) {
    local_50 = (ulong)uVar1;
    if ((param_2 & 1) == 0) {
      iVar2 = smp_call_function_single(*(undefined4 *)(param_1 + 0x10),read_amu_reg,&local_50,1);
      if (iVar2 < 0) goto LAB_00100b14;
      local_40 = local_48;
    }
    else {
      switch(uVar1) {
      case 0:
        local_40 = UnkSytemRegRead(3,3,0xd,4,1);
        break;
      case 1:
        local_40 = UnkSytemRegRead(3,3,0xd,4,0);
        break;
      case 2:
        local_40 = UnkSytemRegRead(3,3,0xd,4,2);
        break;
      case 3:
        local_40 = UnkSytemRegRead(3,3,0xd,4,3);
        break;
      default:
        _printk(&DAT_00103c4f,uVar1);
        local_40 = 0;
        goto LAB_00100b44;
      }
    }
LAB_00100b40:
  }
  else {
    lVar3 = *(long *)(param_1 + 8);
    if (lVar3 == 0) {
LAB_00100b14:
      puVar4 = (undefined8 *)(param_1 + 0x18);
      goto LAB_00100b4c;
    }
    if ((param_2 & 1) == 0) {
      local_40 = perf_event_read_value(lVar3,&local_30,&uStack_38);
      goto LAB_00100b40;
    }
    perf_event_read_local(lVar3,&local_40,0,0);
  }
LAB_00100b44:
  puVar4 = &local_40;
  *(undefined8 *)(param_1 + 0x18) = local_40;
LAB_00100b4c:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(*puVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_get_cpucp_id @ 00100b9c size=76
// signature: undefined qcom_get_cpucp_id(void)
// callers: []
//------------------------------------------------------------

ulong qcom_get_cpucp_id(void)

{
  ulong uVar1;
  
  uVar1 = get_event();
  if (uVar1 < 0xfffffffffffff001) {
    uVar1 = (ulong)*(uint *)(uVar1 + 0x24);
  }
  else {
    _printk(&DAT_00103cb3,uVar1);
  }
  return uVar1 & 0xffffffff;
}



//------------------------------------------------------------
// get_event @ 00100be8 size=344
// signature: undefined get_event(void)
// callers: [qcom_pmu_event_supported, qcom_get_cpucp_id]
//------------------------------------------------------------

int * get_event(int param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  long lVar3;
  
  if (qcom_pmu_inited != '\x01') {
    return (int *)0xfffffffffffffdfb;
  }
  if ((param_1 == 0) ||
     ((*(ulong *)(&__cpu_possible_mask + ((ulong)(param_2 >> 3) & 0x1ffffff8)) >>
       ((ulong)param_2 & 0x3f) & 1) == 0)) {
    return (int *)0xffffffffffffffea;
  }
  if (0x1f < param_2) {
LAB_00100d3c:
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x100d40);
    (*pcVar2)();
  }
  lVar3 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)param_2 * 8));
  iVar1 = *(int *)(lVar3 + 0x148);
  if (iVar1 != 0) {
    if (*(int *)(lVar3 + 8) == param_1) {
      return (int *)(lVar3 + 8);
    }
    if (iVar1 != 1) {
      if (*(int *)(lVar3 + 0x30) == param_1) {
        return (int *)(lVar3 + 0x30);
      }
      if (iVar1 != 2) {
        if (*(int *)(lVar3 + 0x58) == param_1) {
          return (int *)(lVar3 + 0x58);
        }
        if (iVar1 != 3) {
          if (*(int *)(lVar3 + 0x80) == param_1) {
            return (int *)(lVar3 + 0x80);
          }
          if (iVar1 != 4) {
            if (*(int *)(lVar3 + 0xa8) == param_1) {
              return (int *)(lVar3 + 0xa8);
            }
            if (iVar1 != 5) {
              if (*(int *)(lVar3 + 0xd0) == param_1) {
                return (int *)(lVar3 + 0xd0);
              }
              if (iVar1 != 6) {
                if (*(int *)(lVar3 + 0xf8) == param_1) {
                  return (int *)(lVar3 + 0xf8);
                }
                if (iVar1 != 7) {
                  if (*(int *)(lVar3 + 0x120) == param_1) {
                    return (int *)(lVar3 + 0x120);
                  }
                  if (iVar1 != 8) {
                    if (iVar1 == param_1) {
                      return (int *)(lVar3 + 0x148);
                    }
                    if (iVar1 != 9) goto LAB_00100d3c;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return (int *)0xfffffffffffffffe;
}



//------------------------------------------------------------
// qcom_pmu_event_supported @ 00100d44 size=36
// signature: undefined qcom_pmu_event_supported(void)
// callers: []
//------------------------------------------------------------

undefined4 qcom_pmu_event_supported(void)

{
  undefined4 uVar1;
  ulong uVar2;
  
  uVar2 = get_event();
  uVar1 = (undefined4)uVar2;
  if (uVar2 < 0xfffffffffffff001) {
    uVar1 = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// qcom_pmu_read @ 00100d6c size=32
// signature: undefined qcom_pmu_read(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_read(void)

{
  __qcom_pmu_read();
  return;
}



//------------------------------------------------------------
// __qcom_pmu_read @ 00100d8c size=636
// signature: undefined __qcom_pmu_read(void)
// callers: [qcom_pmu_read_local, qcom_pmu_read]
//------------------------------------------------------------

undefined8 __qcom_pmu_read(uint param_1,int param_2,undefined8 *param_3,uint param_4)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  code *pcVar6;
  undefined8 uVar7;
  int iVar8;
  int *piVar9;
  char *pcVar10;
  
  if (qcom_pmu_inited != '\x01') {
    return 0xffffffed;
  }
  if (param_2 == 0) {
    return 0xffffffea;
  }
  if (param_3 == (undefined8 *)0x0) {
    return 0xffffffea;
  }
  if ((*(ulong *)(&__cpu_possible_mask + ((ulong)(param_1 >> 3) & 0x1ffffff8)) >>
       ((ulong)param_1 & 0x3f) & 1) == 0) {
    return 0xffffffea;
  }
  if (0x1f < param_1) {
LAB_00100fe0:
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x100fe4);
    (*pcVar6)();
  }
  pcVar10 = *(char **)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)param_1 * 8));
  iVar3 = *(int *)(pcVar10 + 0x148);
  if (iVar3 == 0) {
    iVar8 = 0;
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(pcVar10 + 8);
    if (*piVar9 == param_2) {
      iVar8 = 0;
    }
    else {
      if (iVar3 == 1) {
        return 0xfffffffe;
      }
      piVar9 = (int *)(pcVar10 + 0x30);
      if (*piVar9 == param_2) {
        iVar8 = 1;
      }
      else {
        if (iVar3 == 2) {
          return 0xfffffffe;
        }
        piVar9 = (int *)(pcVar10 + 0x58);
        if (*piVar9 == param_2) {
          iVar8 = 2;
        }
        else {
          if (iVar3 == 3) {
            return 0xfffffffe;
          }
          piVar9 = (int *)(pcVar10 + 0x80);
          if (*piVar9 == param_2) {
            iVar8 = 3;
          }
          else {
            if (iVar3 == 4) {
              return 0xfffffffe;
            }
            piVar9 = (int *)(pcVar10 + 0xa8);
            if (*piVar9 == param_2) {
              iVar8 = 4;
            }
            else {
              if (iVar3 == 5) {
                return 0xfffffffe;
              }
              piVar9 = (int *)(pcVar10 + 0xd0);
              if (*piVar9 == param_2) {
                iVar8 = 5;
              }
              else {
                if (iVar3 == 6) {
                  return 0xfffffffe;
                }
                piVar9 = (int *)(pcVar10 + 0xf8);
                if (*piVar9 == param_2) {
                  iVar8 = 6;
                }
                else {
                  if (iVar3 == 7) {
                    return 0xfffffffe;
                  }
                  if (*(int *)(pcVar10 + 0x120) == param_2) {
                    piVar9 = (int *)(pcVar10 + 0x120);
                    iVar8 = 7;
                  }
                  else {
                    if (iVar3 == 8) {
                      return 0xfffffffe;
                    }
                    if (iVar3 != param_2) {
                      if (iVar3 == 9) {
                        return 0xfffffffe;
                      }
                      goto LAB_00100fe0;
                    }
                    piVar9 = (int *)(pcVar10 + 0x148);
                    iVar8 = 8;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (iVar8 == iVar3) {
    return 0xfffffffe;
  }
  pcVar1 = pcVar10 + 0x150;
  uVar7 = _raw_spin_lock_irqsave(pcVar1);
  if (((pcVar10[1] != '\0') || (*pcVar10 != '\0')) || (pcVar10[2] != '\0')) {
    _raw_spin_unlock_irqrestore(pcVar1,uVar7);
    *param_3 = *(undefined8 *)(piVar9 + 6);
    return 0;
  }
  piVar2 = (int *)(pcVar10 + 0x14c);
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = *piVar2 + 1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  _raw_spin_unlock_irqrestore(pcVar1,uVar7);
  uVar7 = read_event(piVar9,param_4 & 1);
  *param_3 = uVar7;
  Hint_Prefetch(piVar2,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
    if (bVar5) {
      *piVar2 = *piVar2 + -1;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  return 0;
}



//------------------------------------------------------------
// qcom_pmu_read_local @ 0010101c size=60
// signature: undefined qcom_pmu_read_local(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_read_local(undefined4 param_1,undefined8 param_2)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  __qcom_pmu_read(*(undefined4 *)(&cpu_number + lVar1),param_1,param_2,1);
  return;
}



//------------------------------------------------------------
// qcom_pmu_read_all @ 0010105c size=32
// signature: undefined qcom_pmu_read_all(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_read_all(undefined8 param_1,undefined8 param_2)

{
  __qcom_pmu_read_all(param_1,param_2,0);
  return;
}



//------------------------------------------------------------
// qcom_pmu_read_all_local @ 00101080 size=56
// signature: undefined qcom_pmu_read_all_local(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_read_all_local(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = tpidr_el1;
  __qcom_pmu_read_all(*(undefined4 *)(&cpu_number + lVar1),param_1,1);
  return;
}



//------------------------------------------------------------
// qcom_pmu_idle_register @ 001010bc size=176
// signature: undefined qcom_pmu_idle_register(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_pmu_idle_register(long *param_1)

{
  long *plVar1;
  undefined *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined **ppuVar5;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    uVar4 = 0xffffffea;
  }
  else {
    _raw_spin_lock(&idle_list_lock);
    puVar2 = PTR_idle_notif_list_00103d60;
    ppuVar5 = &idle_notif_list;
    do {
      ppuVar5 = (undefined **)*ppuVar5;
      if (ppuVar5 == &idle_notif_list) {
        plVar1 = param_1 + 1;
        uVar3 = __list_add_valid(plVar1,PTR_idle_notif_list_00103d60,&idle_notif_list);
        if ((uVar3 & 1) != 0) {
          PTR_idle_notif_list_00103d60 = (undefined *)plVar1;
          param_1[1] = (long)&idle_notif_list;
          param_1[2] = (long)puVar2;
          *(long **)puVar2 = plVar1;
        }
        break;
      }
    } while (ppuVar5[-1] != (undefined *)*param_1);
    _raw_spin_unlock(&idle_list_lock);
    uVar4 = 0;
  }
  return uVar4;
}



//------------------------------------------------------------
// qcom_pmu_idle_unregister @ 00101170 size=180
// signature: undefined qcom_pmu_idle_unregister(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_pmu_idle_unregister(long *param_1)

{
  undefined *puVar1;
  long *plVar2;
  ulong uVar3;
  undefined **ppuVar4;
  undefined8 uVar5;
  
  if ((param_1 == (long *)0x0) || (*param_1 == 0)) {
    uVar5 = 0xffffffea;
  }
  else {
    _raw_spin_lock(&idle_list_lock);
    ppuVar4 = &idle_notif_list;
    do {
      ppuVar4 = (undefined **)*ppuVar4;
      if (ppuVar4 == &idle_notif_list) {
        uVar5 = 0xffffffea;
        goto LAB_00101204;
      }
    } while (ppuVar4[-1] != (undefined *)*param_1);
    uVar3 = __list_del_entry_valid(ppuVar4);
    if ((uVar3 & 1) != 0) {
      puVar1 = *ppuVar4;
      plVar2 = (long *)ppuVar4[1];
      *(long **)(puVar1 + 8) = plVar2;
      *plVar2 = (long)puVar1;
    }
    uVar5 = 0;
    *ppuVar4 = (undefined *)0xdead000000000100;
    ppuVar4[1] = (undefined *)0xdead000000000122;
LAB_00101204:
    _raw_spin_unlock(&idle_list_lock);
  }
  return uVar5;
}



//------------------------------------------------------------
// cpucp_pmu_init @ 00101228 size=476
// signature: undefined cpucp_pmu_init(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong cpucp_pmu_init(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 *puVar3;
  ulong uVar4;
  int iVar5;
  code *pcVar6;
  undefined4 local_50;
  undefined4 local_4c;
  long local_48;
  
  lVar1 = sp_el0;
  local_48 = *(long *)(lVar1 + 0x638);
  local_50 = 0;
  if ((param_1 == 0) || (*(long *)(param_1 + 0x3a0) == 0)) {
    puVar3 = (undefined8 *)0xffffffea;
    goto LAB_001013c8;
  }
  pcVar6 = *(code **)(*(long *)(param_1 + 0x3a0) + 0x18);
  if (*(int *)(pcVar6 + -4) != -0x71949897) {
                    /* WARNING: Does not return */
    pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101288);
    (*pcVar6)();
  }
  puVar3 = (undefined8 *)(*pcVar6)(param_1,0x80,&ph);
  if (puVar3 < (undefined8 *)0xfffffffffffff001) {
    iVar5 = 0;
    ops = puVar3;
    while (uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar5), uVar2 < _nr_cpu_ids) {
      smp_call_function_single(uVar2,get_mpidr_cpu,&local_50,1);
      if (0x1f < (ulong)uVar2) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x101400);
        (*pcVar6)();
      }
      iVar5 = uVar2 + 1;
      *(undefined4 *)(phys_cpu + (ulong)uVar2 * 4) = local_50;
    }
    uVar4 = configure_cpucp_map(___cpu_possible_mask);
    if ((int)uVar4 < 0) {
      puVar3 = (undefined8 *)(uVar4 & 0xffffffff);
    }
    else {
      local_4c = 1;
      if (qcom_pmu_inited == '\x01') {
        puVar3 = (undefined8 *)0x0;
        if ((ops == (undefined8 *)0x0) || (pmu_base == 0)) goto LAB_001013c8;
        if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x101398);
          (*pcVar6)();
        }
        uVar4 = (*(code *)*ops)(ph,&local_4c,0x504d554d4150,0xd,4);
        puVar3 = (undefined8 *)(uVar4 & 0xffffffff);
        if (-1 < (int)uVar4) goto LAB_001013c8;
        _printk(&DAT_00103ba7,puVar3);
      }
      else {
        puVar3 = (undefined8 *)0xfffffdfb;
      }
    }
  }
  ops = (undefined8 *)0x0;
LAB_001013c8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return (ulong)puVar3 & 0xffffffff;
}



//------------------------------------------------------------
// get_mpidr_cpu @ 00101408 size=16
// signature: undefined get_mpidr_cpu(void)
// callers: []
//------------------------------------------------------------

void get_mpidr_cpu(uint *param_1)

{
  undefined8 uVar1;
  
  uVar1 = mpidr_el1;
  *param_1 = (uint)uVar1 >> 8 & 0xff;
  return;
}



//------------------------------------------------------------
// configure_cpucp_map @ 00101418 size=728
// signature: undefined configure_cpucp_map(void)
// callers: [cpucp_pmu_init, qcom_pmu_hotplug_coming_up, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int configure_cpucp_map(undefined8 param_1)

{
  uint uVar1;
  uint uVar2;
  long lVar3;
  code *pcVar4;
  int iVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  undefined1 local_100;
  undefined4 uStack_ff;
  undefined3 uStack_fb;
  undefined5 local_f8;
  undefined3 uStack_f3;
  undefined5 uStack_f0;
  undefined3 uStack_eb;
  undefined5 local_e8;
  undefined4 uStack_e3;
  undefined4 local_df;
  undefined2 local_db;
  undefined1 local_d9;
  undefined1 local_d8;
  undefined4 uStack_d7;
  undefined3 uStack_d3;
  undefined5 uStack_d0;
  undefined3 uStack_cb;
  undefined5 local_c8;
  undefined4 uStack_c3;
  undefined4 local_bf;
  undefined2 local_bb;
  undefined1 local_b9;
  undefined1 local_b8;
  undefined4 uStack_b7;
  undefined3 uStack_b3;
  undefined5 local_b0;
  undefined3 uStack_ab;
  undefined5 uStack_a8;
  undefined3 uStack_a3;
  undefined5 local_a0;
  undefined4 uStack_9b;
  undefined4 local_97;
  undefined2 local_93;
  undefined1 local_91;
  undefined1 local_90;
  undefined4 uStack_8f;
  undefined3 uStack_8b;
  undefined5 uStack_88;
  undefined3 uStack_83;
  undefined5 local_80;
  undefined4 uStack_7b;
  undefined4 local_77;
  undefined2 local_73;
  undefined1 local_71;
  undefined8 local_70;
  long local_68;
  
  lVar8 = sp_el0;
  local_68 = *(long *)(lVar8 + 0x638);
  local_c8 = 0;
  uStack_c3 = 0;
  local_bf = 0;
  local_bb = 0;
  local_b9 = 0;
  local_d8 = 0;
  uStack_d7 = 0;
  uStack_d3 = 0;
  uStack_d0 = 0;
  uStack_cb = 0;
  local_e8 = 0;
  uStack_e3 = 0;
  local_df = 0;
  local_db = 0;
  local_d9 = 0;
  local_f8 = 0;
  uStack_f3 = 0;
  uStack_f0 = 0;
  uStack_eb = 0;
  local_100 = 0;
  uStack_ff = 0;
  uStack_fb = 0;
  local_70 = param_1;
  if (qcom_pmu_inited == '\x01') {
    if (ops == (undefined8 *)0x0) {
      iVar5 = 0;
    }
    else {
      lVar8 = 0;
      uVar7 = (ulong)_nr_cpu_ids;
      local_80 = 0xffffffffff;
      uStack_7b = 0xffffffff;
      local_77 = 0xffffffff;
      local_73 = 0xffff;
      local_71 = 0xff;
      local_90 = 0xff;
      uStack_8f = 0xffffffff;
      uStack_8b = 0xffffff;
      uStack_88 = 0xffffffffff;
      uStack_83 = 0xffffff;
      local_a0 = 0xffffffffff;
      uStack_9b = 0xffffffff;
      local_97 = 0xffffffff;
      local_93 = 0xffff;
      local_91 = 0xff;
      local_b0 = 0xffffffffff;
      uStack_ab = 0xffffff;
      uStack_a8 = 0xffffffffff;
      uStack_a3 = 0xffffff;
      local_b8 = 0xff;
      uStack_b7 = 0xffffffff;
      uStack_b3 = 0xffffff;
      while( true ) {
        uVar6 = _find_next_bit(&local_70,uVar7,(long)(int)lVar8);
        uVar7 = (ulong)_nr_cpu_ids;
        if (uVar7 <= (uVar6 & 0xffffffff)) break;
        if ((uVar6 >> 5 & 0x7ffffff) != 0) {
LAB_001016e4:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1016e8);
          (*pcVar4)();
        }
        lVar8 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (long)(int)uVar6 * 8));
        uVar1 = *(uint *)(lVar8 + 0x148);
        if (uVar1 != 0) {
          lVar9 = 0;
          do {
            if (lVar9 == 0x168) goto LAB_001016e4;
            uVar2 = *(uint *)(lVar8 + lVar9 + 0x2c);
            uVar10 = (ulong)uVar2;
            if ((((uVar2 < 9) && (cpucp_map[uVar10 * 0x10] != '\0')) &&
                (3 < *(uint *)(lVar8 + lVar9 + 0x28))) &&
               ((lVar11 = *(long *)(lVar8 + lVar9 + 0x10), lVar11 != 0 &&
                ((*(ulong *)(cpucp_map + uVar10 * 0x10 + (uVar6 >> 6 & 0x3ffffff) * 8 + 8) &
                 1L << (uVar6 & 0x3f)) != 0)))) {
              if ((uVar6 & 0xffffffff) >> 5 != 0) {
LAB_001016e8:
                    /* WARNING: Does not return */
                pcVar4 = (code *)SoftwareBreakpoint(1,0x1016ec);
                (*pcVar4)();
              }
              if (7 < *(uint *)(phys_cpu + (long)(int)uVar6 * 4)) goto LAB_001016e4;
              lVar3 = (ulong)*(uint *)(phys_cpu + (long)(int)uVar6 * 4) * 9;
              if (0x47 < lVar3 + uVar10) goto LAB_001016e8;
              (&local_b8)[uVar10 + lVar3] = (char)*(undefined4 *)(lVar11 + 0x184);
            }
            lVar9 = lVar9 + 0x28;
          } while ((ulong)uVar1 * 0x28 != lVar9);
        }
        lVar8 = uVar6 + 1;
      }
      local_100 = local_b8;
      uStack_ff = uStack_b7;
      uStack_fb = uStack_b3;
      local_f8 = local_b0;
      uStack_f3 = uStack_ab;
      uStack_f0 = uStack_a8;
      uStack_eb = uStack_a3;
      local_e8 = local_a0;
      uStack_e3 = uStack_9b;
      local_df = local_97;
      local_db = local_93;
      local_d9 = local_91;
      local_d8 = local_90;
      uStack_d7 = uStack_8f;
      uStack_d3 = uStack_8b;
      uStack_d0 = uStack_88;
      uStack_cb = uStack_83;
      local_c8 = local_80;
      uStack_c3 = uStack_7b;
      local_bf = local_77;
      local_bb = local_73;
      local_b9 = local_71;
      if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8229,0x101684);
        (*pcVar4)();
      }
      iVar5 = (*(code *)*ops)(ph,&local_100,0x504d554d4150,0xb,0x48);
      if (iVar5 < 0) {
        _printk(&DAT_00103c8c,iVar5);
      }
    }
  }
  else {
    iVar5 = -0x205;
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// read_amu_reg @ 001016f4 size=108
// signature: undefined read_amu_reg(void)
// callers: []
//------------------------------------------------------------

void read_amu_reg(undefined4 *param_1)

{
  undefined8 uVar1;
  
  switch(*param_1) {
  case 0:
    uVar1 = UnkSytemRegRead(3,3,0xd,4,1);
    break;
  case 1:
    uVar1 = UnkSytemRegRead(3,3,0xd,4,0);
    break;
  case 2:
    uVar1 = UnkSytemRegRead(3,3,0xd,4,2);
    break;
  case 3:
    uVar1 = UnkSytemRegRead(3,3,0xd,4,3);
    break;
  default:
    _printk(&DAT_00103c4f);
    return;
  }
  *(undefined8 *)(param_1 + 2) = uVar1;
  return;
}



//------------------------------------------------------------
// qcom_pmu_driver_probe @ 00101764 size=1276
// signature: undefined qcom_pmu_driver_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int qcom_pmu_driver_probe(long param_1)

{
  long lVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  char *pcVar11;
  ulong uVar12;
  long lVar13;
  ulong uVar14;
  ulong uVar15;
  undefined8 uVar16;
  long local_f0;
  long lStack_e8;
  undefined8 local_e0;
  undefined8 uStack_d8;
  undefined8 local_d0;
  undefined8 uStack_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined8 uStack_98;
  undefined4 local_90;
  undefined4 local_8c;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  long local_70;
  
  lVar1 = sp_el0;
  local_70 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_90 = 0;
  local_a0 = 0;
  uStack_98 = 0;
  local_b0 = 0;
  uStack_a8 = 0;
  local_c0 = 0;
  uStack_b8 = 0;
  local_d0 = 0;
  uStack_c8 = 0;
  local_e0 = 0;
  uStack_d8 = 0;
  local_f0 = 0;
  lStack_e8 = 0;
  uVar7 = get_qcom_scmi_device();
  if (0xfffffffffffff000 < uVar7) {
    if ((int)uVar7 == -0x205) {
      iVar5 = -0x205;
      goto LAB_00101bcc;
    }
    _dev_err(lVar1,"Error getting scmi_dev ret = %d\n",uVar7 & 0xffffffff);
  }
  if ((pmu_base == 0) &&
     (iVar5 = of_property_match_string(*(undefined8 *)(param_1 + 0x2f8),"reg-names","pmu-base"),
     -1 < iVar5)) {
    iVar5 = of_address_to_resource(*(undefined8 *)(param_1 + 0x2f8),iVar5,&local_f0);
    if (iVar5 < 0) {
      _dev_err(lVar1,"failed to get resource ret %d\n",iVar5);
    }
    else {
      pmu_base = devm_ioremap(lVar1,local_f0,(lStack_e8 - local_f0) + 1);
      if (pmu_base != 0) {
        __memset_io(pmu_base,0,(lStack_e8 - local_f0) + 1);
      }
    }
  }
  lVar8 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,ignore-llcc-setup",&local_90);
  if (lVar8 != 0) {
    llcc_ignore_setup = 1;
  }
  iVar5 = 0;
  while (uVar3 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar5), uVar3 < _nr_cpu_ids) {
    lVar8 = devm_kmalloc(lVar1,0x158,0xdc0);
    if (lVar8 == 0) {
      iVar5 = -0xc;
      goto LAB_00101bcc;
    }
    *(undefined4 *)(lVar8 + 0x150) = 0;
    *(undefined4 *)(lVar8 + 0x14c) = 0;
    if (0x1f < (ulong)uVar3) {
LAB_00101c54:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x101c58);
      (*pcVar2)();
    }
    iVar5 = uVar3 + 1;
    *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)uVar3 * 8)) = lVar8;
  }
  uVar16 = *(undefined8 *)(param_1 + 0x2f8);
  local_80 = 0;
  local_78 = 0;
  local_88 = 0;
  local_8c = 0;
  lVar8 = of_find_property(uVar16,"qcom,long-counter",(long)&local_78 + 4);
  if (lVar8 != 0) {
    pmu_long_counter = 1;
  }
  lVar8 = of_find_property(uVar16,"qcom,pmu-events-tbl",(long)&local_78 + 4);
  if (lVar8 == 0) {
    iVar5 = -0x13;
LAB_00101bb8:
    pcVar11 = "failed to initialize pmu events: %d\n";
    iVar6 = iVar5;
  }
  else {
    uVar3 = local_78._4_4_;
    iVar5 = -0x16;
    if ((local_78._4_4_ < 4) || ((local_78 & 0xc00000000) != 0)) goto LAB_00101bb8;
    iVar5 = (int)local_78._4_4_ >> 2;
    iVar6 = iVar5 + 3;
    if (-1 < iVar5) {
      iVar6 = iVar5;
    }
    local_78 = CONCAT44(iVar6 >> 2,(int)local_78);
    if (0x7f < (int)uVar3) {
LAB_00101bac:
      iVar5 = -0x1c;
      goto LAB_00101bb8;
    }
    if (0xf < (int)uVar3) {
      uVar3 = 0;
      iVar6 = 0;
      do {
        iVar4 = of_property_read_u32_index(uVar16,"qcom,pmu-events-tbl",uVar3,(long)&local_80 + 4);
        iVar5 = -0x16;
        if (((iVar4 < 0) || (local_80._4_4_ == 0)) ||
           (iVar4 = of_property_read_u32_index(uVar16,"qcom,pmu-events-tbl",uVar3 | 1,&local_78),
           iVar4 < 0)) goto LAB_00101bb8;
        if ((int)local_78 == 0) goto LAB_00101bb8;
        local_88 = local_78 & 0xffffffff;
        iVar5 = of_property_read_u32_index(uVar16,"qcom,pmu-events-tbl",uVar3 | 2,&local_8c);
        if ((iVar5 < 0) ||
           (iVar5 = of_property_read_u32_index(uVar16,"qcom,pmu-events-tbl",uVar3 | 3,&local_80),
           iVar5 < 0)) {
LAB_00101ba4:
          iVar5 = -0x16;
          goto LAB_00101bb8;
        }
        lVar8 = 0;
        uVar10 = (ulong)_nr_cpu_ids;
        while( true ) {
          uVar9 = _find_next_bit(&local_88,uVar10,(long)(int)lVar8);
          uVar10 = (ulong)_nr_cpu_ids;
          uVar12 = uVar9 & 0xffffffff;
          if (uVar10 <= uVar12) break;
          uVar14 = uVar9 >> 6 & 0x3ffffff;
          uVar15 = 1L << (uVar9 & 0x3f);
          if ((*(ulong *)(&__cpu_possible_mask + uVar14 * 8) & uVar15) != 0) {
            if ((local_80._4_4_ == 0) ||
               ((*(ulong *)(&__cpu_possible_mask + uVar14 * 8) & uVar15) == 0)) goto LAB_00101ba4;
            if (0x1f < uVar12) goto LAB_00101c54;
            lVar8 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + uVar12 * 8));
            if (7 < *(uint *)(lVar8 + 0x148)) goto LAB_00101bac;
            lVar13 = lVar8 + (ulong)*(uint *)(lVar8 + 0x148) * 0x28;
            *(int *)(lVar13 + 8) = local_80._4_4_;
            *(undefined4 *)(lVar13 + 0x28) = local_8c;
            *(uint *)(lVar13 + 0x2c) = (uint)local_80;
            uVar10 = (ulong)_nr_cpu_ids;
            *(int *)(lVar8 + 0x148) = *(int *)(lVar8 + 0x148) + 1;
          }
          lVar8 = uVar9 + 1;
        }
        uVar10 = local_80 & 0xffffffff;
        if ((uint)local_80 < 9) {
          cpucp_map[uVar10 * 0x10] = 1;
          if ((0x90 < (uVar10 << 4 | 8)) || (0x90 < (uVar10 << 4 | 8))) {
                    /* WARNING: Does not return */
            pcVar2 = (code *)SoftwareBreakpoint(1,0x101c60);
            (*pcVar2)();
          }
          *(ulong *)(cpucp_map + uVar10 * 0x10 + 8) = local_88;
        }
        uVar3 = uVar3 + 4;
        iVar6 = iVar6 + 1;
      } while (iVar6 < (int)local_78._4_4_);
    }
    iVar5 = kobject_init_and_add(pmu_kobj,pmu_settings_ktype,_kobject_put,"pmu_lib");
    if (iVar5 < 0) {
      pcVar11 = "failed to init pmu counters kobj: %d\n";
LAB_00101c20:
      _dev_err(lVar1,pcVar11,iVar5);
      kobject_put(pmu_kobj);
      goto LAB_00101bcc;
    }
    iVar5 = setup_events();
    if (iVar5 < 0) {
      pcVar11 = "failed to setup all pmu/amu events: %d\n";
      goto LAB_00101c20;
    }
    qcom_pmu_inited = 1;
    if ((0xfffffffffffff000 < uVar7) || (iVar6 = cpucp_pmu_init(), -1 < iVar6)) goto LAB_00101bcc;
    pcVar11 = "Err during cpucp_pmu_init ret = %d\n";
  }
  _dev_err(lVar1,pcVar11,iVar6);
LAB_00101bcc:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar5;
}



//------------------------------------------------------------
// qcom_pmu_driver_remove @ 00101c64 size=40
// signature: undefined qcom_pmu_driver_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_pmu_driver_remove(void)

{
  qcom_pmu_inited = 0;
  delete_events();
  return 0;
}



//------------------------------------------------------------
// setup_events @ 00101c8c size=968
// signature: undefined setup_events(void)
// callers: [qcom_pmu_driver_probe, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int setup_events(void)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  long lVar6;
  undefined8 uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  ulong uVar13;
  
  lVar6 = kmalloc_trace(___tracepoint_android_vh_cpu_idle_enter,0xdc0,0x80);
  if (lVar6 == 0) {
    return -0xc;
  }
  *(undefined4 *)(lVar6 + 4) = 0x80;
  *(ulong *)(lVar6 + 0x28) = *(ulong *)(lVar6 + 0x28) | 4;
  cpus_read_lock();
  uVar9 = 0;
  iVar3 = 0;
  while (uVar9 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,uVar9 & 0xffffffff),
        (uint)uVar9 < _nr_cpu_ids) {
    if (0x1f < (uVar9 & 0xffffffff)) goto LAB_00102050;
    puVar12 = *(undefined1 **)
               (&cpu_ev_data + *(long *)(&__per_cpu_offset + (uVar9 & 0xffffffff) * 8));
    if (*(int *)(puVar12 + 0x148) != 0) {
      uVar13 = 0;
      puVar11 = (undefined4 *)(puVar12 + 8);
      do {
        if (uVar13 == 9) goto LAB_00102050;
        iVar3 = set_event(puVar11,uVar9 & 0xffffffff,lVar6);
        if (iVar3 < 0) {
          _printk(&DAT_00103a28,*puVar11,uVar9 & 0xffffffff,iVar3);
          bVar2 = iVar3 == -0x205;
          iVar3 = 0;
          *puVar11 = 0;
          if (bVar2) {
            iVar3 = 0;
            goto LAB_00101e54;
          }
        }
        uVar13 = uVar13 + 1;
        puVar11 = puVar11 + 10;
      } while (uVar13 < *(uint *)(puVar12 + 0x148));
    }
    uVar7 = _raw_spin_lock_irqsave(puVar12 + 0x150);
    uVar13 = *(ulong *)(&__cpu_online_mask + (uVar9 >> 6 & 0x3ffffff) * 8);
    *puVar12 = 0;
    puVar12[2] = 0;
    puVar12[1] = (uVar13 >> (uVar9 & 0x3f) & 1) == 0;
    _raw_spin_unlock_irqrestore(puVar12 + 0x150,uVar7);
    uVar9 = uVar9 + 1;
  }
  iVar4 = __cpuhp_setup_state_cpuslocked
                    (200,"QCOM_PMU",0,qcom_pmu_hotplug_coming_up,qcom_pmu_hotplug_going_down,0);
  if (iVar4 < 0) {
    _printk(&DAT_00103d20,iVar4);
    cpuhp_state = iVar4;
    _printk(&DAT_00103c11,iVar4);
  }
  else {
    cpuhp_state = iVar4;
    iVar4 = iVar3;
  }
LAB_00101f9c:
  cpus_read_unlock();
  if ((iVar4 != -0x205) && (iVar4 != cpuhp_state)) {
    tracepoint_probe_register(&__tracepoint_android_vh_cpu_idle_enter,qcom_pmu_idle_enter_notif,0);
    tracepoint_probe_register(&__tracepoint_android_vh_cpu_idle_exit,qcom_pmu_idle_exit_notif,0);
    cpu_pm_register_notifier(&memlat_event_pm_nb);
  }
  kfree(lVar6);
  return iVar4;
LAB_00101e54:
  uVar5 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar3);
  if (_nr_cpu_ids <= uVar5) goto LAB_00101f98;
  if (0x1f < (ulong)uVar5) {
LAB_00102050:
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102054);
    (*pcVar1)();
  }
  lVar10 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)uVar5 * 8));
  uVar8 = *(uint *)(lVar10 + 0x148);
  if (uVar8 != 0) {
    if (*(long *)(lVar10 + 0x10) != 0) {
      perf_event_release_kernel();
      uVar8 = *(uint *)(lVar10 + 0x148);
      *(undefined8 *)(lVar10 + 0x10) = 0;
    }
    if (1 < uVar8) {
      if (*(long *)(lVar10 + 0x38) != 0) {
        perf_event_release_kernel();
        uVar8 = *(uint *)(lVar10 + 0x148);
        *(undefined8 *)(lVar10 + 0x38) = 0;
      }
      if (2 < uVar8) {
        if (*(long *)(lVar10 + 0x60) != 0) {
          perf_event_release_kernel();
          uVar8 = *(uint *)(lVar10 + 0x148);
          *(undefined8 *)(lVar10 + 0x60) = 0;
        }
        if (3 < uVar8) {
          if (*(long *)(lVar10 + 0x88) != 0) {
            perf_event_release_kernel();
            uVar8 = *(uint *)(lVar10 + 0x148);
            *(undefined8 *)(lVar10 + 0x88) = 0;
          }
          if (4 < uVar8) {
            if (*(long *)(lVar10 + 0xb0) != 0) {
              perf_event_release_kernel();
              uVar8 = *(uint *)(lVar10 + 0x148);
              *(undefined8 *)(lVar10 + 0xb0) = 0;
            }
            if (5 < uVar8) {
              if (*(long *)(lVar10 + 0xd8) != 0) {
                perf_event_release_kernel();
                uVar8 = *(uint *)(lVar10 + 0x148);
                *(undefined8 *)(lVar10 + 0xd8) = 0;
              }
              if (6 < uVar8) {
                if (*(long *)(lVar10 + 0x100) != 0) {
                  perf_event_release_kernel();
                  uVar8 = *(uint *)(lVar10 + 0x148);
                  *(undefined8 *)(lVar10 + 0x100) = 0;
                }
                if (7 < uVar8) {
                  if (*(long *)(lVar10 + 0x128) != 0) {
                    perf_event_release_kernel();
                    uVar8 = *(uint *)(lVar10 + 0x148);
                    *(undefined8 *)(lVar10 + 0x128) = 0;
                  }
                  if (8 < uVar8) {
                    if (*(long *)(lVar10 + 0x150) != 0) {
                      perf_event_release_kernel();
                      uVar8 = *(uint *)(lVar10 + 0x148);
                      *(undefined8 *)(lVar10 + 0x150) = 0;
                    }
                    if (9 < uVar8) goto LAB_00102050;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  iVar3 = uVar5 + 1;
  goto LAB_00101e54;
LAB_00101f98:
  iVar4 = -0x205;
  goto LAB_00101f9c;
}



//------------------------------------------------------------
// attr_show @ 00102058 size=68
// signature: undefined attr_show(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_show(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x10);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x40e7484a) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102084);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// attr_store @ 001020a0 size=68
// signature: undefined attr_store(void)
// callers: []
//------------------------------------------------------------

undefined8 attr_store(undefined8 param_1,long param_2)

{
  undefined8 uVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(param_2 + 0x18);
  if (pcVar2 == (code *)0x0) {
    uVar1 = 0xfffffffffffffffb;
  }
  else {
    if (*(int *)(pcVar2 + -4) != 0x5800598) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1020cc);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)();
  }
  return uVar1;
}



//------------------------------------------------------------
// show_enable_counters @ 001020e8 size=64
// signature: undefined show_enable_counters(void)
// callers: []
//------------------------------------------------------------

long show_enable_counters(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00103a60,(pmu_counters_enabled ^ 0xff) & 1);
  return (long)iVar1;
}



//------------------------------------------------------------
// store_enable_counters @ 0010212c size=804
// signature: undefined store_enable_counters(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8
store_enable_counters(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  ulong uVar7;
  undefined8 uVar8;
  long lVar9;
  long lVar10;
  ulong uVar11;
  uint *puVar12;
  bool bVar13;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar10 = sp_el0;
  local_68 = *(long *)(lVar10 + 0x638);
  uVar7 = sysfs_streq(param_3,"BEEFDEAD");
  if ((uVar7 & 1) == 0) {
    uVar7 = sysfs_streq(param_3,"DEADBEEF");
    if ((((uVar7 & 1) != 0) && (qcom_pmu_inited == '\x01')) && ((pmu_counters_enabled & 1) == 0)) {
      iVar5 = 0;
LAB_0010225c:
      uVar6 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar5);
      if (uVar6 < _nr_cpu_ids) {
        uVar7 = (ulong)uVar6;
        if (0x1f < uVar7) {
LAB_00102448:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x10244c);
          (*pcVar4)();
        }
        lVar10 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + uVar7 * 8));
        if (*(int *)(lVar10 + 0x148) != 0) {
          uVar11 = 0;
          bVar13 = false;
          lVar9 = pmu_base + uVar7 * 0x28;
LAB_001022cc:
          puVar12 = (uint *)(lVar10 + 0x2c + uVar11 * 0x28);
          do {
            uVar11 = uVar11 + 1;
            if (uVar11 == 10) goto LAB_00102448;
            if (puVar12[-9] != 0) {
              uVar2 = puVar12[-1];
              uVar3 = *puVar12;
              if ((*(long *)(puVar12 + -7) != 0) || (uVar2 < 4)) {
                local_78 = 0;
                uStack_70 = 0;
                local_88 = 0;
                local_80 = 0;
                if (puVar12[-1] < 4) {
                  local_88 = (ulong)puVar12[-1];
                  iVar5 = smp_call_function_single(puVar12[-5],read_amu_reg,&local_88,1);
                  if (-1 < iVar5) {
                    uVar8 = local_80;
LAB_00102368:
                    *(undefined8 *)(puVar12 + -3) = uVar8;
                  }
                }
                else if (*(long *)(puVar12 + -7) != 0) {
                  uVar8 = perf_event_read_value(*(long *)(puVar12 + -7),&uStack_70,&local_78);
                  goto LAB_00102368;
                }
                if (((pmu_base != 0) && (*puVar12 < 9)) &&
                   (cpucp_map[(ulong)*puVar12 * 0x10] != '\0')) goto code_r0x00102394;
              }
            }
            puVar12 = puVar12 + 10;
            if (*(uint *)(lVar10 + 0x148) <= uVar11) {
              if (!bVar13) break;
              goto LAB_00102248;
            }
          } while( true );
        }
        goto LAB_00102258;
      }
      delete_events();
      _printk(&DAT_00103b30);
      pmu_counters_enabled = 1;
    }
  }
  else if (pmu_counters_enabled == 1) {
    iVar5 = setup_events();
    if (iVar5 < 0) {
      _printk(&DAT_00103a6d,iVar5);
    }
    else {
      configure_cpucp_map(___cpu_possible_mask);
      pmu_counters_enabled = 0;
      _printk(&DAT_00103b80);
    }
  }
  lVar10 = sp_el0;
  if (*(long *)(lVar10 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
code_r0x00102394:
  uVar7 = *(ulong *)(puVar12 + -3);
  if (3 < uVar2) {
    if (*(uint *)(*(long *)(*(long *)(puVar12 + -7) + 0x98) + 0x138) < 6) {
      if (puVar12[-9] == 0x11) {
        uVar7 = uVar7 | 0xffffffff80000000;
      }
      else {
        uVar7 = uVar7 & 0x7fffffff | 0x80000000;
      }
    }
    else {
      uVar1 = 0x8000000000000000;
      if (pmu_long_counter == '\0') {
        uVar1 = 0xffffffff80000000;
      }
      uVar7 = uVar1 | uVar7;
    }
  }
  if (9 < uVar3) goto LAB_00102448;
  writel_relaxed(uVar7,lVar9 + (ulong)uVar3 * 4);
  bVar13 = true;
  if (*(uint *)(lVar10 + 0x148) <= uVar11) goto LAB_00102248;
  goto LAB_001022cc;
LAB_00102248:
  writel_relaxed(1,lVar9 + 0x24);
LAB_00102258:
  iVar5 = uVar6 + 1;
  goto LAB_0010225c;
}



//------------------------------------------------------------
// delete_events @ 00102450 size=464
// signature: undefined delete_events(void)
// callers: [qcom_pmu_driver_remove, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void delete_events(void)

{
  code *pcVar1;
  uint uVar2;
  undefined8 uVar3;
  int iVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  undefined2 *puVar9;
  
  if (0 < cpuhp_state) {
    __cpuhp_remove_state(cpuhp_state,0);
  }
  tracepoint_probe_unregister(&__tracepoint_android_vh_cpu_idle_enter,qcom_pmu_idle_enter_notif,0);
  tracepoint_probe_unregister(&__tracepoint_android_vh_cpu_idle_exit,qcom_pmu_idle_exit_notif,0);
  cpu_pm_unregister_notifier(&memlat_event_pm_nb);
  iVar4 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar4);
    if (_nr_cpu_ids <= uVar2) break;
    if (0x1f < (ulong)uVar2) goto LAB_0010261c;
    puVar9 = *(undefined2 **)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8));
    uVar3 = _raw_spin_lock_irqsave(puVar9 + 0xa8);
    *puVar9 = 0x101;
    *(undefined1 *)(puVar9 + 1) = 1;
    _raw_spin_unlock_irqrestore(puVar9 + 0xa8,uVar3);
    iVar4 = uVar2 + 1;
  }
  iVar4 = 0;
  while( true ) {
    uVar2 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar4);
    if (_nr_cpu_ids <= uVar2) {
      return;
    }
    if (0x1f < (ulong)uVar2) break;
    lVar6 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8));
    iVar4 = *(int *)(lVar6 + 0x14c);
    while (0 < iVar4) {
      __const_udelay(0xa7c6);
      iVar4 = *(int *)(lVar6 + 0x14c);
    }
    uVar5 = (ulong)*(uint *)(lVar6 + 0x148);
    if (*(uint *)(lVar6 + 0x148) != 0) {
      uVar7 = 0;
      plVar8 = (long *)(lVar6 + 0x10);
      do {
        if (uVar7 == 9) goto LAB_0010261c;
        if (((int)plVar8[-1] != 0) && (*plVar8 != 0)) {
          perf_event_release_kernel();
          *plVar8 = 0;
          uVar5 = (ulong)*(uint *)(lVar6 + 0x148);
        }
        uVar7 = uVar7 + 1;
        plVar8 = plVar8 + 5;
      } while (uVar7 < uVar5);
    }
    iVar4 = uVar2 + 1;
  }
LAB_0010261c:
                    /* WARNING: Does not return */
  pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102620);
  (*pcVar1)();
}



//------------------------------------------------------------
// writel_relaxed @ 00102620 size=132
// signature: undefined writel_relaxed(void)
// callers: [qcom_pmu_hotplug_coming_up, memlat_pm_notif, qcom_pmu_hotplug_going_down, store_enable_counters]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x102638,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x102674,uVar1);
  return;
}



//------------------------------------------------------------
// qcom_pmu_idle_enter_notif @ 001026a8 size=672
// signature: undefined qcom_pmu_idle_enter_notif(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_idle_enter_notif(undefined8 param_1,undefined4 *param_2,long param_3)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  code *pcVar5;
  undefined8 uVar6;
  ulong uVar7;
  char *pcVar8;
  char *pcVar9;
  undefined **ppuVar10;
  ulong uVar11;
  ulong uVar12;
  ulong uVar13;
  char *pcVar14;
  undefined8 local_d8;
  undefined8 local_d0;
  undefined8 local_c8;
  undefined8 uStack_c0;
  undefined8 local_b8;
  undefined8 local_b0 [8];
  undefined8 local_70;
  long local_68;
  
  lVar4 = sp_el0;
  local_68 = *(long *)(lVar4 + 0x638);
  if (0x1f < *(uint *)(param_3 + 4)) {
LAB_00102918:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10291c);
    (*pcVar5)();
  }
  pcVar9 = *(char **)(&cpu_ev_data +
                     *(long *)(&__per_cpu_offset + (ulong)*(uint *)(param_3 + 4) * 8));
  local_b0[7] = 0;
  local_70 = 0;
  local_b0[5] = 0;
  local_b0[6] = 0;
  local_b0[3] = 0;
  local_b0[4] = 0;
  local_b0[1] = 0;
  local_b0[2] = 0;
  pcVar14 = pcVar9 + 0x150;
  local_b8 = 0;
  local_b0[0] = 0;
  local_c8 = 0;
  uStack_c0 = 0;
  local_d0 = 0;
  uVar6 = _raw_spin_lock_irqsave(pcVar14);
  if (((*pcVar9 == '\0') && (pcVar9[1] == '\0')) && (pcVar9[2] == '\0')) {
    piVar1 = (int *)(pcVar9 + 0x14c);
    *pcVar9 = '\x01';
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    _raw_spin_unlock_irqrestore(pcVar14,uVar6);
    uVar7 = (ulong)*(uint *)(pcVar9 + 0x148);
    if (*(uint *)(pcVar9 + 0x148) == 0) {
      uVar12 = 0;
    }
    else {
      uVar13 = 0;
      pcVar14 = pcVar9 + 0x20;
      uVar11 = 0;
      do {
        if (uVar13 == 9) goto LAB_00102918;
        uVar12 = uVar11;
        if ((*(int *)(pcVar14 + -0x18) != 0) &&
           ((*(long *)(pcVar14 + -0x10) != 0 || (*(uint *)(pcVar14 + 8) < 4)))) {
          local_d8 = 0;
          if (*(uint *)(pcVar14 + 8) < 4) {
            switch(*(uint *)(pcVar14 + 8)) {
            case 0:
              local_d8 = UnkSytemRegRead(3,3,0xd,4,1);
              break;
            case 1:
              local_d8 = UnkSytemRegRead(3,3,0xd,4,0);
              break;
            case 2:
              local_d8 = UnkSytemRegRead(3,3,0xd,4,2);
              break;
            case 3:
              local_d8 = UnkSytemRegRead(3,3,0xd,4,3);
              break;
            default:
              _printk(&DAT_00103c4f);
              local_d8 = 0;
              goto LAB_001027d8;
            }
LAB_001027d8:
            *(undefined8 *)pcVar14 = local_d8;
            pcVar8 = (char *)&local_d8;
          }
          else {
            pcVar8 = pcVar14;
            if (*(long *)(pcVar14 + -0x10) != 0) {
              perf_event_read_local(*(long *)(pcVar14 + -0x10),&local_d8,0,0);
              goto LAB_001027d8;
            }
          }
          *(undefined8 *)pcVar14 = *(undefined8 *)pcVar8;
          if (7 < uVar11) goto LAB_00102918;
          *(undefined4 *)((long)local_b0 + uVar11 * 4 + -0x20) = *(undefined4 *)(pcVar14 + -0x18);
          uVar12 = uVar11 + 1;
          local_b0[uVar11] = *(undefined8 *)pcVar14;
          uVar7 = (ulong)*(uint *)(pcVar9 + 0x148);
        }
        uVar13 = uVar13 + 1;
        pcVar14 = pcVar14 + 0x28;
        uVar11 = uVar12;
      } while (uVar13 < uVar7);
    }
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    local_70 = CONCAT44(local_70._4_4_,(int)uVar12);
    ppuVar10 = (undefined **)idle_notif_list;
    if ((undefined **)idle_notif_list != &idle_notif_list) {
      do {
        if (*(int *)(ppuVar10[-1] + -4) != -0x18dec3a) {
                    /* WARNING: Does not return */
          pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102904);
          (*pcVar5)();
        }
        (*(code *)ppuVar10[-1])(&local_d0,*(undefined4 *)(param_3 + 4),*param_2);
        ppuVar10 = (undefined **)*ppuVar10;
      } while (ppuVar10 != &idle_notif_list);
    }
  }
  else {
    _raw_spin_unlock_irqrestore(pcVar14,uVar6);
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// qcom_pmu_idle_exit_notif @ 00102958 size=48
// signature: undefined qcom_pmu_idle_exit_notif(void)
// callers: []
//------------------------------------------------------------

void qcom_pmu_idle_exit_notif(undefined8 param_1,undefined8 param_2,long param_3)

{
  code *pcVar1;
  
  if (0x1f < *(uint *)(param_3 + 4)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102988);
    (*pcVar1)();
  }
  **(undefined1 **)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)*(uint *)(param_3 + 4) * 8))
       = 0;
  return;
}



//------------------------------------------------------------
// memlat_pm_notif @ 0010298c size=888
// signature: undefined memlat_pm_notif(void)
// callers: []
//------------------------------------------------------------

undefined8 memlat_pm_notif(undefined8 param_1,long param_2)

{
  char *pcVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  bool bVar5;
  long lVar6;
  ulong uVar7;
  code *pcVar8;
  undefined8 uVar9;
  ulong uVar10;
  bool bVar11;
  ulong *puVar12;
  ulong uVar13;
  char *pcVar14;
  long lVar15;
  ulong *puVar16;
  ulong local_70;
  long local_68;
  
  lVar15 = pmu_base;
  lVar6 = sp_el0;
  local_68 = *(long *)(lVar6 + 0x638);
  lVar6 = tpidr_el1;
  uVar3 = *(uint *)(&cpu_number + lVar6);
  if (0x1f < uVar3) {
LAB_00102cdc:
                    /* WARNING: Does not return */
    pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x102ce0);
    (*pcVar8)();
  }
  pcVar14 = *(char **)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)uVar3 * 8));
  pcVar1 = pcVar14 + 0x150;
  uVar9 = _raw_spin_lock_irqsave(pcVar1);
  if (pcVar14[1] == '\0') {
    lVar15 = lVar15 + (ulong)uVar3 * 0x28;
    if (param_2 != 2) {
      if ((*pcVar14 == '\0') && (pcVar14[2] == '\0')) {
        piVar2 = (int *)(pcVar14 + 0x14c);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = *piVar2 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        bVar5 = true;
      }
      else {
        bVar5 = false;
      }
      pcVar14[2] = '\x01';
      _raw_spin_unlock_irqrestore(pcVar1,uVar9);
      if ((pmu_base != 0) &&
         (uVar10 = (ulong)*(uint *)(pcVar14 + 0x148), *(uint *)(pcVar14 + 0x148) != 0)) {
        uVar13 = 0;
        bVar11 = false;
        do {
          puVar16 = (ulong *)(pcVar14 + uVar13 * 0x28 + 0x20);
          while( true ) {
            if (uVar13 == 9) goto LAB_00102cdc;
            if (((((int)puVar16[-3] != 0) &&
                 (uVar7 = puVar16[1], (uint)uVar7 < 4 || puVar16[-2] != 0)) &&
                (uVar3 = *(uint *)((long)puVar16 + 0xc), uVar3 < 9)) &&
               (cpucp_map[(ulong)uVar3 * 0x10] != '\0')) break;
            uVar13 = uVar13 + 1;
            puVar16 = puVar16 + 5;
            if (uVar10 <= uVar13) {
              if (bVar11) goto LAB_00102ca4;
              goto LAB_00102cb0;
            }
          }
          if (bVar5) {
            local_70 = 0;
            if ((uint)puVar16[1] < 4) {
              switch((uint)puVar16[1]) {
              case 0:
                local_70 = UnkSytemRegRead(3,3,0xd,4,1);
                break;
              case 1:
                local_70 = UnkSytemRegRead(3,3,0xd,4,0);
                break;
              case 2:
                local_70 = UnkSytemRegRead(3,3,0xd,4,2);
                break;
              case 3:
                local_70 = UnkSytemRegRead(3,3,0xd,4,3);
                break;
              default:
                _printk(&DAT_00103c4f);
                local_70 = 0;
                goto LAB_00102bc8;
              }
LAB_00102bc8:
              *puVar16 = local_70;
              puVar12 = &local_70;
            }
            else {
              puVar12 = puVar16;
              if (puVar16[-2] != 0) {
                perf_event_read_local(puVar16[-2],&local_70,0,0);
                goto LAB_00102bc8;
              }
            }
            uVar10 = *puVar12;
            *puVar16 = uVar10;
          }
          else {
            uVar10 = *puVar16;
          }
          if (3 < (uint)uVar7) {
            if (*(uint *)(*(long *)(puVar16[-2] + 0x98) + 0x138) < 6) {
              if ((int)puVar16[-3] == 0x11) {
                uVar10 = uVar10 | 0xffffffff80000000;
              }
              else {
                uVar10 = uVar10 & 0x7fffffff | 0x80000000;
              }
            }
            else {
              uVar7 = 0x8000000000000000;
              if (pmu_long_counter == '\0') {
                uVar7 = 0xffffffff80000000;
              }
              uVar10 = uVar7 | uVar10;
            }
          }
          writel_relaxed(uVar10,lVar15 + (ulong)uVar3 * 4);
          uVar10 = (ulong)*(uint *)(pcVar14 + 0x148);
          uVar13 = uVar13 + 1;
          bVar11 = true;
        } while (uVar13 < uVar10);
LAB_00102ca4:
        writel_relaxed(1,lVar15 + 0x24);
      }
LAB_00102cb0:
      if (bVar5) {
        piVar2 = (int *)(pcVar14 + 0x14c);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = *piVar2 + -1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
      }
      goto LAB_00102a44;
    }
    if (pmu_base != 0) {
      writel_relaxed(0,lVar15 + 0x24);
    }
    pcVar14[2] = '\0';
  }
  _raw_spin_unlock_irqrestore(pcVar1,uVar9);
LAB_00102a44:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// show_enable_trace @ 00102d20 size=56
// signature: undefined show_enable_trace(void)
// callers: []
//------------------------------------------------------------

long show_enable_trace(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_00103a60,pmu_enable_trace);
  return (long)iVar1;
}



//------------------------------------------------------------
// store_enable_trace @ 00102d5c size=248
// signature: undefined store_enable_trace(void)
// callers: []
//------------------------------------------------------------

long store_enable_trace(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  if (ops == (undefined8 *)0x0) {
    param_4 = -0x13;
  }
  else {
    iVar3 = kstrtouint(param_3,10,&local_2c);
    if (iVar3 < 0) {
      param_4 = (long)iVar3;
    }
    else {
      if (*(int *)((code *)*ops + -4) != -0x6997da7a) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102de4);
        (*pcVar2)();
      }
      iVar3 = (*(code *)*ops)(ph,&local_2c,0x504d554d4150,0xc,4);
      if (iVar3 < 0) {
        _printk(&DAT_001039f4,iVar3);
        param_4 = (long)iVar3;
      }
      else {
        pmu_enable_trace = local_2c;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// set_event @ 00102e54 size=308
// signature: undefined set_event(void)
// callers: [qcom_pmu_hotplug_coming_up, setup_events]
//------------------------------------------------------------

ulong set_event(uint *param_1,uint param_2,undefined4 *param_3)

{
  long lVar1;
  ulong uVar2;
  undefined4 local_3c;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_3c = 4;
  if (3 < param_1[8]) {
    param_1[8] = 4;
    if (8 < param_1[9]) {
      param_1[9] = 9;
    }
    if (*param_1 == 0) {
      uVar2 = 0;
      goto LAB_00102f54;
    }
    *(ulong *)(param_3 + 2) = (ulong)*param_1;
    if (pmu_long_counter == '\x01') {
      *(undefined8 *)(param_3 + 0xe) = 1;
    }
    if (*param_1 == 0x1000) {
      if ((llcc_ignore_setup & 1) != 0) goto LAB_00102e94;
      uVar2 = qcom_llcc_pmu_hw_type(&local_3c);
      if ((int)uVar2 < 0) {
        uVar2 = uVar2 & 0xffffffff;
        goto LAB_00102f54;
      }
    }
    *param_3 = local_3c;
    uVar2 = perf_event_create_kernel_counter(param_3,param_2,0,0,0);
    if (0xfffffffffffff000 < uVar2) goto LAB_00102f54;
    perf_event_enable(uVar2);
    *(ulong *)(param_1 + 2) = uVar2;
  }
LAB_00102e94:
  uVar2 = 0;
  param_1[4] = param_2;
LAB_00102f54:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2 & 0xffffffff;
}



//------------------------------------------------------------
// qcom_pmu_hotplug_coming_up @ 00102f8c size=776
// signature: undefined qcom_pmu_hotplug_coming_up(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_pmu_hotplug_coming_up(uint param_1)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  long lVar5;
  uint *puVar6;
  code *pcVar7;
  int iVar8;
  long lVar9;
  undefined8 uVar10;
  ulong uVar11;
  ulong extraout_x8;
  ulong uVar12;
  ulong extraout_x9;
  uint *puVar13;
  long lVar14;
  undefined8 local_60;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  puVar13 = (uint *)0x80;
  lVar9 = kmalloc_trace(___tracepoint_android_vh_cpu_idle_enter,0xdc0,0x80);
  if (lVar9 != 0) {
    *(undefined4 *)(lVar9 + 4) = 0x80;
    *(ulong *)(lVar9 + 0x28) = *(ulong *)(lVar9 + 0x28) | 4;
  }
  lVar5 = pmu_base;
  if (0x1f < param_1) {
LAB_00103178:
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x10317c);
    (*pcVar7)();
  }
  lVar14 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)param_1 * 8));
  local_60 = 0;
  if (lVar9 == 0) {
    uVar10 = 0xfffffff4;
    goto LAB_0010323c;
  }
  if (qcom_pmu_inited == '\x01') {
    if (*(int *)(lVar14 + 0x148) != 0) {
      puVar13 = (uint *)(lVar14 + 8);
      iVar8 = set_event(puVar13,param_1,lVar9);
      if (iVar8 < 0) {
LAB_00103194:
        _printk(&DAT_00103a28,*puVar13,param_1,iVar8);
      }
      else {
        puVar13 = (uint *)(lVar14 + 0x148);
        if (1 < *puVar13) {
          iVar8 = set_event((uint *)(lVar14 + 0x30),param_1,lVar9);
          puVar6 = (uint *)(lVar14 + 0x30);
          if (iVar8 < 0) {
LAB_0010318c:
            puVar13 = puVar6;
            goto LAB_00103194;
          }
          if (2 < *puVar13) {
            iVar8 = set_event((uint *)(lVar14 + 0x58),param_1,lVar9);
            puVar6 = (uint *)(lVar14 + 0x58);
            if (iVar8 < 0) goto LAB_0010318c;
            if (3 < *puVar13) {
              iVar8 = set_event((uint *)(lVar14 + 0x80),param_1,lVar9);
              puVar6 = (uint *)(lVar14 + 0x80);
              if (iVar8 < 0) goto LAB_0010318c;
              if (4 < *puVar13) {
                iVar8 = set_event((uint *)(lVar14 + 0xa8),param_1,lVar9);
                puVar6 = (uint *)(lVar14 + 0xa8);
                if (iVar8 < 0) goto LAB_0010318c;
                if (5 < *puVar13) {
                  iVar8 = set_event((uint *)(lVar14 + 0xd0),param_1,lVar9);
                  puVar6 = (uint *)(lVar14 + 0xd0);
                  if (iVar8 < 0) goto LAB_0010318c;
                  if (6 < *puVar13) {
                    iVar8 = set_event((uint *)(lVar14 + 0xf8),param_1,lVar9);
                    puVar6 = (uint *)(lVar14 + 0xf8);
                    if (iVar8 < 0) goto LAB_0010318c;
                    if (7 < *puVar13) {
                      iVar8 = set_event((uint *)(lVar14 + 0x120),param_1,lVar9);
                      puVar6 = (uint *)(lVar14 + 0x120);
                      if (iVar8 < 0) goto LAB_0010318c;
                      if (8 < *puVar13) {
                        iVar8 = set_event(puVar13,param_1,lVar9);
                        if (iVar8 < 0) goto LAB_00103194;
                        if (9 < *puVar13) goto LAB_00103178;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    uVar2 = _nr_cpu_ids + 0x3fU >> 3 & 0x1ffffff8;
    if (uVar2 < 9) {
      memset(&local_60,0,(ulong)uVar2);
      uVar12 = (ulong)(param_1 >> 6);
      uVar11 = 1L << ((ulong)param_1 & 0x3f);
      puVar13 = (uint *)&local_60;
    }
    else {
      fortify_panic("memset");
      uVar11 = extraout_x8;
      uVar12 = extraout_x9;
    }
    puVar1 = (ulong *)(puVar13 + uVar12 * 2);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar4) {
        *puVar1 = *puVar1 | uVar11;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    configure_cpucp_map(local_60);
    if (pmu_base != 0) {
      writel_relaxed(0,lVar5 + (ulong)param_1 * 0x28 + 0x24);
    }
    uVar10 = _raw_spin_lock_irqsave(lVar14 + 0x150);
    *(undefined1 *)(lVar14 + 1) = 0;
    _raw_spin_unlock_irqrestore(lVar14 + 0x150,uVar10);
  }
  kfree(lVar9);
  uVar10 = 0;
LAB_0010323c:
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar10);
  }
  return;
}



//------------------------------------------------------------
// qcom_pmu_hotplug_going_down @ 001032a0 size=616
// signature: undefined qcom_pmu_hotplug_going_down(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_pmu_hotplug_going_down(uint param_1)

{
  ulong uVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  undefined4 *puVar11;
  bool bVar12;
  ulong local_88;
  ulong local_80;
  undefined8 uStack_78;
  undefined8 local_70;
  long local_68;
  
  lVar8 = pmu_base;
  lVar9 = sp_el0;
  local_68 = *(long *)(lVar9 + 0x638);
  if (0x1f < param_1) {
LAB_00103500:
                    /* WARNING: Does not return */
    pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x103504);
    (*pcVar4)();
  }
  if (qcom_pmu_inited == '\x01') {
    lVar9 = *(long *)(&cpu_ev_data + *(long *)(&__per_cpu_offset + (ulong)param_1 * 8));
    uVar6 = _raw_spin_lock_irqsave(lVar9 + 0x150);
    *(undefined1 *)(lVar9 + 1) = 1;
    _raw_spin_unlock_irqrestore(lVar9 + 0x150,uVar6);
    iVar5 = *(int *)(lVar9 + 0x14c);
    while (0 < iVar5) {
      __const_udelay(0xa7c6);
      iVar5 = *(int *)(lVar9 + 0x14c);
    }
    if (*(int *)(lVar9 + 0x148) != 0) {
      uVar10 = 0;
      bVar12 = false;
      lVar8 = lVar8 + (ulong)param_1 * 0x28;
      puVar11 = (undefined4 *)(lVar9 + 0x18);
      do {
        if (uVar10 == 9) goto LAB_00103500;
        if (puVar11[-4] != 0) {
          uVar2 = puVar11[4];
          uVar3 = puVar11[5];
          if ((*(long *)(puVar11 + -2) != 0) || (uVar2 < 4)) {
            local_70 = 0;
            local_80 = 0;
            uStack_78 = 0;
            local_88 = 0;
            if ((uint)puVar11[4] < 4) {
              local_88 = (ulong)(uint)puVar11[4];
              iVar5 = smp_call_function_single(*puVar11,read_amu_reg,&local_88,1);
              if (iVar5 < 0) {
LAB_00103408:
                uVar7 = *(ulong *)(puVar11 + 2);
              }
              else {
                uVar7 = local_80;
              }
            }
            else {
              if (*(long *)(puVar11 + -2) == 0) goto LAB_00103408;
              uVar7 = perf_event_read_value(*(long *)(puVar11 + -2),&local_70,&uStack_78);
            }
            *(ulong *)(puVar11 + 2) = uVar7;
            if (((pmu_base != 0) && ((uint)puVar11[5] < 9)) &&
               (cpucp_map[(ulong)(uint)puVar11[5] * 0x10] != '\0')) {
              if (3 < uVar2) {
                if (*(uint *)(*(long *)(*(long *)(puVar11 + -2) + 0x98) + 0x138) < 6) {
                  if (puVar11[-4] == 0x11) {
                    uVar7 = uVar7 | 0xffffffff80000000;
                  }
                  else {
                    uVar7 = uVar7 & 0x7fffffff | 0x80000000;
                  }
                }
                else {
                  uVar1 = 0x8000000000000000;
                  if (pmu_long_counter == '\0') {
                    uVar1 = 0xffffffff80000000;
                  }
                  uVar7 = uVar1 | uVar7;
                }
              }
              if (9 < uVar3) goto LAB_00103500;
              writel_relaxed(uVar7,lVar8 + (ulong)uVar3 * 4);
              bVar12 = true;
            }
            if (*(long *)(puVar11 + -2) != 0) {
              perf_event_release_kernel();
              *(undefined8 *)(puVar11 + -2) = 0;
            }
          }
        }
        uVar10 = uVar10 + 1;
        puVar11 = puVar11 + 10;
      } while (uVar10 < *(uint *)(lVar9 + 0x148));
      if (bVar12) {
        writel_relaxed(1,lVar8 + 0x24);
      }
    }
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}



//------------------------------------------------------------
// init_module @ 001037dc size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_pmu_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010380c size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_pmu_driver);
  return;
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00106010 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [__qcom_pmu_read_all, delete_events, __qcom_pmu_read, qcom_pmu_hotplug_coming_up, setup_events, memlat_pm_notif, qcom_pmu_hotplug_going_down, qcom_pmu_idle_enter_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00106018 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [__qcom_pmu_read_all, delete_events, __qcom_pmu_read, qcom_pmu_hotplug_coming_up, setup_events, memlat_pm_notif, qcom_pmu_hotplug_going_down, qcom_pmu_idle_enter_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_event_read_local @ 00106028 size=1
// signature: undefined perf_event_read_local(void)
// callers: [read_event, memlat_pm_notif, qcom_pmu_idle_enter_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_event_read_local(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 00106030 size=1
// signature: undefined smp_call_function_single(void)
// callers: [cpucp_pmu_init, read_event, qcom_pmu_hotplug_going_down, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_event_read_value @ 00106038 size=1
// signature: undefined perf_event_read_value(void)
// callers: [read_event, qcom_pmu_hotplug_going_down, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_event_read_value(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00106040 size=1
// signature: undefined _printk(void)
// callers: [cpucp_pmu_init, read_event, qcom_pmu_hotplug_coming_up, configure_cpucp_map, qcom_get_cpucp_id, setup_events, memlat_pm_notif, store_enable_trace, store_enable_counters, qcom_pmu_idle_enter_notif, read_amu_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00106048 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [cpucp_pmu_init, set_event, read_event, qcom_pmu_hotplug_coming_up, configure_cpucp_map, qcom_pmu_driver_probe, memlat_pm_notif, qcom_pmu_hotplug_going_down, store_enable_trace, store_enable_counters, qcom_pmu_idle_enter_notif]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00106058 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [qcom_pmu_idle_register, qcom_pmu_idle_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00106060 size=1
// signature: undefined __list_add_valid(void)
// callers: [qcom_pmu_idle_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00106068 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [qcom_pmu_idle_register, qcom_pmu_idle_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00106070 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [qcom_pmu_idle_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00106080 size=1
// signature: undefined _find_next_bit(void)
// callers: [cpucp_pmu_init, delete_events, configure_cpucp_map, qcom_pmu_driver_probe, setup_events, store_enable_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00106088 size=1
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
// platform_driver_unregister @ 00106090 size=1
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
// get_qcom_scmi_device @ 00106098 size=1
// signature: undefined get_qcom_scmi_device(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_qcom_scmi_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 001060a0 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 001060a8 size=1
// signature: undefined of_find_property(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 001060b0 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_u32_index @ 001060b8 size=1
// signature: undefined of_property_read_u32_index(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_u32_index(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_match_string @ 001060c0 size=1
// signature: undefined of_property_match_string(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_match_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_address_to_resource @ 001060c8 size=1
// signature: undefined of_address_to_resource(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_address_to_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 001060d0 size=1
// signature: undefined devm_ioremap(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __memset_io @ 001060d8 size=1
// signature: undefined __memset_io(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __memset_io(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_init_and_add @ 001060e8 size=1
// signature: undefined kobject_init_and_add(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_init_and_add(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kobject_put @ 001060f0 size=1
// signature: undefined kobject_put(void)
// callers: [qcom_pmu_driver_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kobject_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00106100 size=1
// signature: undefined kmalloc_trace(void)
// callers: [qcom_pmu_hotplug_coming_up, setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 00106108 size=1
// signature: undefined cpus_read_lock(void)
// callers: [setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state_cpuslocked @ 00106118 size=1
// signature: undefined __cpuhp_setup_state_cpuslocked(void)
// callers: [setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state_cpuslocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_event_release_kernel @ 00106120 size=1
// signature: undefined perf_event_release_kernel(void)
// callers: [delete_events, setup_events, qcom_pmu_hotplug_going_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_event_release_kernel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 00106128 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 00106138 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_register_notifier @ 00106148 size=1
// signature: undefined cpu_pm_register_notifier(void)
// callers: [setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00106150 size=1
// signature: undefined kfree(void)
// callers: [qcom_pmu_hotplug_coming_up, setup_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 00106158 size=1
// signature: undefined scnprintf(void)
// callers: [show_enable_trace, show_enable_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_streq @ 00106160 size=1
// signature: undefined sysfs_streq(void)
// callers: [store_enable_counters]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_streq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 00106168 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [delete_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_unregister @ 00106170 size=1
// signature: undefined tracepoint_probe_unregister(void)
// callers: [delete_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_unregister_notifier @ 00106178 size=1
// signature: undefined cpu_pm_unregister_notifier(void)
// callers: [delete_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 00106180 size=1
// signature: undefined __const_udelay(void)
// callers: [delete_events, qcom_pmu_hotplug_going_down]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00106188 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00106190 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtouint @ 00106198 size=1
// signature: undefined kstrtouint(void)
// callers: [store_enable_trace]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtouint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// qcom_llcc_pmu_hw_type @ 001061a0 size=1
// signature: undefined qcom_llcc_pmu_hw_type(void)
// callers: [set_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void qcom_llcc_pmu_hw_type(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_event_create_kernel_counter @ 001061a8 size=1
// signature: undefined perf_event_create_kernel_counter(void)
// callers: [set_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_event_create_kernel_counter(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_event_enable @ 001061b0 size=1
// signature: undefined perf_event_enable(void)
// callers: [set_event]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_event_enable(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 001061b8 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [qcom_pmu_hotplug_coming_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 001061c0 size=1
// signature: undefined fortify_panic(void)
// callers: [qcom_pmu_hotplug_coming_up]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



