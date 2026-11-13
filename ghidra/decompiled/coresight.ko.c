// Decompiled by Ghidra 12.2
// Program: coresight.ko
// Image base: 00100000

//------------------------------------------------------------
// coresight_simple_show_pair @ 001024b4 size=236
// signature: undefined coresight_simple_show_pair(void)
// callers: []
//------------------------------------------------------------

long coresight_simple_show_pair(long param_1,long param_2,undefined8 param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  ulong uVar4;
  code *pcVar5;
  
  __pm_runtime_resume(*(undefined8 *)(param_1 + 0x60),4);
  uVar1 = *(uint *)(param_2 + 0x24);
  pcVar5 = *(code **)(param_1 + -0x10);
  if (*(char *)(param_1 + -0x18) == '\0') {
    if (*(int *)(pcVar5 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102568);
      (*pcVar5)();
    }
    uVar3 = (*pcVar5)((ulong)*(uint *)(param_2 + 0x20),1,0);
    if (*(int *)(*(code **)(param_1 + -0x10) + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x102598);
      (*pcVar5)();
    }
    uVar4 = (**(code **)(param_1 + -0x10))((ulong)uVar1,1,0);
  }
  else {
    uVar3 = readl_relaxed(pcVar5 + *(uint *)(param_2 + 0x20));
    uVar3 = uVar3 & 0xffffffff;
    uVar4 = readl_relaxed(*(long *)(param_1 + -0x10) + (ulong)uVar1);
    uVar4 = uVar4 & 0xffffffff;
  }
  __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),4);
  iVar2 = sysfs_emit(param_3,"0x%llx\n",uVar3 | uVar4 << 0x20);
  return (long)iVar2;
}



//------------------------------------------------------------
// coresight_simple_show32 @ 001025a4 size=168
// signature: undefined coresight_simple_show32(void)
// callers: []
//------------------------------------------------------------

long coresight_simple_show32(long param_1,long param_2,undefined8 param_3)

{
  undefined4 uVar1;
  int iVar2;
  code *pcVar3;
  
  __pm_runtime_resume(*(undefined8 *)(param_1 + 0x60),4);
  pcVar3 = *(code **)(param_1 + -0x10);
  if (*(char *)(param_1 + -0x18) == '\0') {
    if (*(int *)(pcVar3 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102644);
      (*pcVar3)();
    }
    uVar1 = (*pcVar3)((ulong)*(uint *)(param_2 + 0x20),1,0);
  }
  else {
    uVar1 = readl_relaxed(pcVar3 + *(uint *)(param_2 + 0x20));
  }
  __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),4);
  iVar2 = sysfs_emit(param_3,"0x%llx\n",uVar1);
  return (long)iVar2;
}



//------------------------------------------------------------
// coresight_set_cti_ops @ 00102650 size=12
// signature: undefined coresight_set_cti_ops(void)
// callers: []
//------------------------------------------------------------

void coresight_set_cti_ops(undefined8 param_1)

{
  cti_assoc_ops = param_1;
  return;
}



//------------------------------------------------------------
// coresight_remove_cti_ops @ 00102660 size=12
// signature: undefined coresight_remove_cti_ops(void)
// callers: []
//------------------------------------------------------------

void coresight_remove_cti_ops(void)

{
  cti_assoc_ops = 0;
  return;
}



//------------------------------------------------------------
// coresight_set_percpu_sink @ 00102670 size=40
// signature: undefined coresight_set_percpu_sink(void)
// callers: []
//------------------------------------------------------------

void coresight_set_percpu_sink(uint param_1,undefined8 param_2)

{
  code *pcVar1;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102698);
    (*pcVar1)();
  }
  *(undefined8 *)(&csdev_sink + *(long *)(&__per_cpu_offset + (ulong)param_1 * 8)) = param_2;
  return;
}



//------------------------------------------------------------
// coresight_get_percpu_sink @ 0010269c size=40
// signature: undefined coresight_get_percpu_sink(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_get_percpu_sink(uint param_1)

{
  code *pcVar1;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1026c4);
    (*pcVar1)();
  }
  return *(undefined8 *)(&csdev_sink + *(long *)(&__per_cpu_offset + (ulong)param_1 * 8));
}



//------------------------------------------------------------
// coresight_set_csr_ops @ 001026c8 size=12
// signature: undefined coresight_set_csr_ops(void)
// callers: []
//------------------------------------------------------------

void coresight_set_csr_ops(undefined8 param_1)

{
  csr_set_atid_ops = param_1;
  return;
}



//------------------------------------------------------------
// coresight_remove_csr_ops @ 001026d8 size=12
// signature: undefined coresight_remove_csr_ops(void)
// callers: []
//------------------------------------------------------------

void coresight_remove_csr_ops(void)

{
  csr_set_atid_ops = 0;
  return;
}



//------------------------------------------------------------
// coresight_claim_device_unlocked @ 001026e8 size=376
// signature: undefined coresight_claim_device_unlocked(void)
// callers: [coresight_claim_device]
//------------------------------------------------------------

undefined8 coresight_claim_device_unlocked(long param_1)

{
  uint uVar1;
  ulong uVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x800,0x102798);
    (*pcVar3)();
  }
  pcVar3 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar3 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1027c0);
      (*pcVar3)();
    }
    uVar2 = (*pcVar3)(0xfa4,1,0);
  }
  else {
    uVar2 = readl_relaxed(pcVar3 + 0xfa4);
  }
  if ((uVar2 & 3) == 0) {
    if (*(char *)(param_1 + 0x20) == '\0') {
      if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x1027fc);
        (*pcVar3)();
      }
      (**(code **)(param_1 + 0x30))(2,4000,1,0);
    }
    else {
      writel_relaxed(2,*(long *)(param_1 + 0x28) + 4000);
    }
    InstructionSynchronizationBarrier();
    pcVar3 = *(code **)(param_1 + 0x28);
    if (*(char *)(param_1 + 0x20) == '\0') {
      if (*(int *)(pcVar3 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x102828);
        (*pcVar3)();
      }
      uVar1 = (*pcVar3)(0xfa4,1,0);
    }
    else {
      uVar1 = readl_relaxed(pcVar3 + 0xfa4);
    }
    if ((uVar1 & 3) == 2) {
      return 0;
    }
    if (*(char *)(param_1 + 0x20) == '\0') {
      if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x10285c);
        (*pcVar3)();
      }
      (**(code **)(param_1 + 0x30))(2,0xfa4,1,0);
    }
    else {
      writel_relaxed(2,*(long *)(param_1 + 0x28) + 0xfa4);
    }
    InstructionSynchronizationBarrier();
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// coresight_claim_device @ 00102868 size=108
// signature: undefined coresight_claim_device(void)
// callers: []
//------------------------------------------------------------

undefined4 coresight_claim_device(long param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1028d4);
    (*pcVar1)();
  }
  writel_relaxed(0xc5acce55,*(long *)(param_1 + 0x28) + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  uVar2 = coresight_claim_device_unlocked(param_1);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*(long *)(param_1 + 0x28) + 0xfb0);
  return uVar2;
}



//------------------------------------------------------------
// coresight_disclaim_device_unlocked @ 001028dc size=212
// signature: undefined coresight_disclaim_device_unlocked(void)
// callers: []
//------------------------------------------------------------

void coresight_disclaim_device_unlocked(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x10294c);
    (*pcVar2)();
  }
  pcVar2 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar2 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102974);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(0xfa4,1,0);
  }
  else {
    uVar1 = readl_relaxed(pcVar2 + 0xfa4);
  }
  if ((uVar1 & 3) != 2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102938);
    (*pcVar2)();
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1029a8);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x30))(2,0xfa4,1,0);
    InstructionSynchronizationBarrier();
  }
  else {
    writel_relaxed(2,*(long *)(param_1 + 0x28) + 0xfa4);
    InstructionSynchronizationBarrier();
  }
  return;
}



//------------------------------------------------------------
// coresight_disclaim_device @ 001029b8 size=256
// signature: undefined coresight_disclaim_device(void)
// callers: []
//------------------------------------------------------------

void coresight_disclaim_device(long param_1)

{
  uint uVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102a54);
    (*pcVar2)();
  }
  writel_relaxed(0xc5acce55,*(long *)(param_1 + 0x28) + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  pcVar2 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar2 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102a7c);
      (*pcVar2)();
    }
    uVar1 = (*pcVar2)(0xfa4,1,0);
  }
  else {
    uVar1 = readl_relaxed(pcVar2 + 0xfa4);
  }
  if ((uVar1 & 3) != 2) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102a2c);
    (*pcVar2)();
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x102ab0);
      (*pcVar2)();
    }
    (**(code **)(param_1 + 0x30))(2,0xfa4,1,0);
    InstructionSynchronizationBarrier();
  }
  else {
    writel_relaxed(2,*(long *)(param_1 + 0x28) + 0xfa4);
    InstructionSynchronizationBarrier();
  }
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*(long *)(param_1 + 0x28) + 0xfb0);
  return;
}



//------------------------------------------------------------
// coresight_set_assoc_ectdev_mutex @ 00102ac0 size=76
// signature: undefined coresight_set_assoc_ectdev_mutex(void)
// callers: []
//------------------------------------------------------------

void coresight_set_assoc_ectdev_mutex(long param_1,undefined8 param_2)

{
  mutex_lock(&coresight_mutex);
  *(undefined8 *)(param_1 + 1000) = param_2;
  mutex_unlock(&coresight_mutex);
  return;
}



//------------------------------------------------------------
// coresight_disable_path @ 00102b10 size=32
// signature: undefined coresight_disable_path(void)
// callers: [etm_event_start, etm_event_stop]
//------------------------------------------------------------

void coresight_disable_path(undefined8 param_1)

{
  coresight_disable_path_from(param_1,0);
  return;
}



//------------------------------------------------------------
// coresight_disable_path_from @ 00102b30 size=796
// signature: undefined coresight_disable_path_from(void)
// callers: [coresight_disable_path, __coresight_disable, coresight_enable_path, coresight_enable]
//------------------------------------------------------------

void coresight_disable_path_from(long *param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  long lVar5;
  code *pcVar6;
  int *piVar7;
  uint uVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  undefined8 uVar12;
  long *plVar13;
  ulong uVar14;
  
  if (param_2 == 0) {
    param_2 = *param_1 + -8;
  }
  plVar13 = *(long **)(param_2 + 8);
  do {
    if (plVar13 == param_1) {
      return;
    }
    plVar10 = (long *)plVar13[-1];
    uVar1 = *(uint *)(plVar10 + 1);
    uVar8 = uVar1;
    if (uVar1 == 2) {
      if ((param_1 == (long *)0x0) ||
         (plVar9 = *(long **)(param_1[1] + -8), (*(uint *)(plVar9 + 1) | 2) != 2)) {
        plVar9 = (long *)0x0;
      }
      uVar8 = (uint)(plVar10 != plVar9);
    }
    if (uVar8 == 3) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x102b84);
      (*pcVar6)();
    }
    if (uVar8 == 1) {
      if ((*(long *)(plVar13[1] + -8) != 0) && (lVar11 = *(long *)(*plVar13 + -8), lVar11 != 0)) {
        uVar3 = coresight_find_link_inport(plVar10,*(long *)(plVar13[1] + -8),param_1);
        uVar4 = coresight_find_link_outport(plVar10,lVar11,param_1);
        if ((int)plVar10[2] == 1) {
          uVar14 = (ulong)*(uint *)(*plVar10 + 4);
        }
        else if ((int)plVar10[2] == 0) {
          uVar14 = (ulong)*(uint *)*plVar10;
        }
        else {
          uVar14 = 1;
        }
        pcVar6 = *(code **)(*(long *)(plVar10[3] + 8) + 8);
        if (pcVar6 != (code *)0x0) {
          if (*(int *)(pcVar6 + -4) != -0x36d7adc0) {
                    /* WARNING: Does not return */
            pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102d48);
            (*pcVar6)();
          }
          (*pcVar6)(plVar10,uVar3,uVar4);
          lVar11 = plVar10[0x7d];
          if ((((lVar11 != 0) &&
               (plVar9 = *(long **)(*(long *)(lVar11 + 0x18) + 0x20), *plVar9 != 0)) &&
              (pcVar6 = (code *)plVar9[1], pcVar6 != (code *)0x0)) &&
             (*(char *)((long)plVar10 + 0x3f5) != '\0')) {
            uVar12 = *(undefined8 *)(*(long *)(*(long *)(lVar11 + 0x98) + 0x88) + 0x10);
            if (*(int *)(pcVar6 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102d9c);
              (*pcVar6)();
            }
            iVar2 = (*pcVar6)(lVar11);
            put_device(*(undefined8 *)(lVar11 + 0x98));
            module_put(uVar12);
            *(undefined1 *)((long)plVar10 + 0x3f5) = 0;
            if (iVar2 != 0) {
              lVar5 = *(long *)(lVar11 + 0xa8);
              if (lVar5 == 0) {
                lVar5 = *(long *)(lVar11 + 0x38);
              }
              _dev_info(plVar10 + 7,"Associated ECT device (%s) %s failed\n",lVar5,"disable");
            }
          }
        }
        if (0 < (int)uVar14) {
          piVar7 = (int *)plVar10[0x79];
          do {
            if (*piVar7 != 0) goto LAB_00102b84;
            uVar14 = uVar14 - 1;
            piVar7 = piVar7 + 1;
          } while (uVar14 != 0);
        }
        *(undefined1 *)((long)plVar10 + 0x3d1) = 0;
      }
    }
    else if (uVar8 == 0) {
      if ((uVar1 == 0) && (*(int *)((long)plVar10 + 0xc) == 2)) {
        coresight_set_csr_atid(param_1,plVar10,0);
      }
      pcVar6 = *(code **)(*(long *)plVar10[3] + 8);
      if (pcVar6 != (code *)0x0) {
        if (*(int *)(pcVar6 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102c2c);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(plVar10);
        if (iVar2 == 0) {
          lVar11 = plVar10[0x7d];
          if (((lVar11 != 0) && (plVar9 = *(long **)(*(long *)(lVar11 + 0x18) + 0x20), *plVar9 != 0)
              ) && ((pcVar6 = (code *)plVar9[1], pcVar6 != (code *)0x0 &&
                    (*(char *)((long)plVar10 + 0x3f5) != '\0')))) {
            uVar12 = *(undefined8 *)(*(long *)(*(long *)(lVar11 + 0x98) + 0x88) + 0x10);
            if (*(int *)(pcVar6 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
              pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x102c84);
              (*pcVar6)();
            }
            iVar2 = (*pcVar6)(lVar11);
            put_device(*(undefined8 *)(lVar11 + 0x98));
            module_put(uVar12);
            *(undefined1 *)((long)plVar10 + 0x3f5) = 0;
            if (iVar2 != 0) {
              lVar5 = *(long *)(lVar11 + 0xa8);
              if (lVar5 == 0) {
                lVar5 = *(long *)(lVar11 + 0x38);
              }
              _dev_info(plVar10 + 7,"Associated ECT device (%s) %s failed\n",lVar5,"disable");
            }
          }
          *(undefined2 *)((long)plVar10 + 0x3d1) = 0;
        }
      }
    }
LAB_00102b84:
    plVar13 = (long *)*plVar13;
  } while( true );
}



//------------------------------------------------------------
// coresight_enable_path @ 00102e50 size=868
// signature: undefined coresight_enable_path(void)
// callers: [etm_event_start, coresight_enable]
//------------------------------------------------------------

int coresight_enable_path(long *param_1,undefined4 param_2,undefined8 param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  uint uVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  long *plVar11;
  
  plVar11 = (long *)param_1[1];
  if (plVar11 == param_1) {
    iVar2 = 0;
  }
  else {
    iVar2 = 0;
    do {
      lVar9 = plVar11[-1];
      uVar6 = *(uint *)(lVar9 + 8);
      if (uVar6 == 2) {
        if ((param_1 == (long *)0x0) ||
           (lVar7 = *(long *)(param_1[1] + -8), (*(uint *)(lVar7 + 8) | 2) != 2)) {
          lVar7 = 0;
        }
        uVar6 = (uint)(lVar9 != lVar7);
      }
      if (uVar6 != 3) {
        if (uVar6 == 1) {
          iVar2 = -0x16;
          if ((*(long *)(plVar11[1] + -8) == 0) || (lVar7 = *(long *)(*plVar11 + -8), lVar7 == 0)) {
LAB_00103160:
            coresight_disable_path_from(param_1,plVar11 + -1);
            return iVar2;
          }
          iVar2 = coresight_find_link_inport(lVar9,*(long *)(plVar11[1] + -8),param_1);
          iVar4 = coresight_find_link_outport(lVar9,lVar7,param_1);
          if ((*(int *)(lVar9 + 0x10) == 0) && (iVar2 < 0)) goto LAB_00103160;
          if ((*(int *)(lVar9 + 0x10) == 1) && (iVar4 < 0)) {
            iVar2 = iVar4;
            goto LAB_00103160;
          }
          if (**(long **)(*(long *)(lVar9 + 0x18) + 8) != 0) {
            iVar3 = coresight_control_assoc_ectdev(lVar9,1);
            if (iVar3 != 0) {
              iVar2 = iVar3;
              goto LAB_00103160;
            }
            pcVar1 = (code *)**(undefined8 **)(*(long *)(lVar9 + 0x18) + 8);
            if (*(int *)(pcVar1 + -4) != 0x6d6b8d73) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103004);
              (*pcVar1)();
            }
            iVar2 = (*pcVar1)(lVar9,iVar2,iVar4);
            if (iVar2 != 0) {
              lVar7 = *(long *)(lVar9 + 1000);
              if ((((lVar7 != 0) &&
                   (plVar8 = *(long **)(*(long *)(lVar7 + 0x18) + 0x20), *plVar8 != 0)) &&
                  (pcVar1 = (code *)plVar8[1], pcVar1 != (code *)0x0)) &&
                 (*(char *)(lVar9 + 0x3f5) != '\0')) {
                uVar10 = *(undefined8 *)(*(long *)(*(long *)(lVar7 + 0x98) + 0x88) + 0x10);
                if (*(int *)(pcVar1 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103140);
                  (*pcVar1)();
                }
                iVar4 = (*pcVar1)(lVar7);
                put_device(*(undefined8 *)(lVar7 + 0x98));
                module_put(uVar10);
                *(undefined1 *)(lVar9 + 0x3f5) = 0;
                if (iVar4 != 0) {
                  lVar5 = *(long *)(lVar7 + 0xa8);
                  if (lVar5 == 0) {
                    lVar5 = *(long *)(lVar7 + 0x38);
                  }
                  _dev_info(lVar9 + 0x38,"Associated ECT device (%s) %s failed\n",lVar5,"disable");
                }
              }
              goto LAB_00103160;
            }
          }
          iVar2 = 0;
          *(undefined1 *)(lVar9 + 0x3d1) = 1;
        }
        else {
          if (uVar6 != 0) goto LAB_00103160;
          if (*(long *)**(undefined8 **)(lVar9 + 0x18) == 0) {
            return -0x16;
          }
          iVar2 = coresight_control_assoc_ectdev(lVar9,1);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (*(int *)(*(code **)**(undefined8 **)(lVar9 + 0x18) + -4) != 0x1ac23c00) {
                    /* WARNING: Does not return */
            pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102f40);
            (*pcVar1)();
          }
          iVar2 = (**(code **)**(undefined8 **)(lVar9 + 0x18))(lVar9,param_2,param_3);
          if (iVar2 != 0) {
            lVar7 = *(long *)(lVar9 + 1000);
            if (lVar7 == 0) {
              return iVar2;
            }
            plVar11 = *(long **)(*(long *)(lVar7 + 0x18) + 0x20);
            if (*plVar11 == 0) {
              return iVar2;
            }
            pcVar1 = (code *)plVar11[1];
            if (pcVar1 == (code *)0x0) {
              return iVar2;
            }
            if (*(char *)(lVar9 + 0x3f5) == '\0') {
              return iVar2;
            }
            uVar10 = *(undefined8 *)(*(long *)(*(long *)(lVar7 + 0x98) + 0x88) + 0x10);
            if (*(int *)(pcVar1 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
              pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103094);
              (*pcVar1)();
            }
            iVar4 = (*pcVar1)(lVar7);
            put_device(*(undefined8 *)(lVar7 + 0x98));
            module_put(uVar10);
            *(undefined1 *)(lVar9 + 0x3f5) = 0;
            if (iVar4 == 0) {
              return iVar2;
            }
            lVar5 = *(long *)(lVar7 + 0xa8);
            if (lVar5 == 0) {
              lVar5 = *(long *)(lVar7 + 0x38);
            }
            _dev_info(lVar9 + 0x38,"Associated ECT device (%s) %s failed\n",lVar5,"disable");
            return iVar2;
          }
          *(undefined1 *)(lVar9 + 0x3d1) = 1;
          if (*(int *)(lVar9 + 8) == 0) {
            iVar2 = coresight_set_csr_atid(param_1,lVar9,1);
          }
          else {
            iVar2 = 0;
          }
        }
      }
      plVar11 = (long *)plVar11[1];
    } while (plVar11 != param_1);
  }
  return iVar2;
}



//------------------------------------------------------------
// coresight_get_sink @ 001031b8 size=40
// signature: undefined coresight_get_sink(void)
// callers: [etm_event_start, etm_event_stop, free_event_data]
//------------------------------------------------------------

long coresight_get_sink(long param_1)

{
  long lVar1;
  
  lVar1 = 0;
  if ((param_1 == 0) ||
     (lVar1 = *(long *)(*(long *)(param_1 + 8) + -8), (*(uint *)(lVar1 + 8) | 2) == 2)) {
    return lVar1;
  }
  return 0;
}



//------------------------------------------------------------
// coresight_set_csr_atid @ 001031e0 size=376
// signature: undefined coresight_set_csr_atid(void)
// callers: [coresight_disable_path_from, coresight_enable_path]
//------------------------------------------------------------

ulong coresight_set_csr_atid(long *param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  ulong uVar5;
  ulong uVar6;
  ulong uVar7;
  undefined4 *puVar8;
  long lVar9;
  undefined4 local_5c;
  long local_58;
  
  lVar9 = sp_el0;
  local_58 = *(long *)(lVar9 + 0x638);
  local_5c = 0;
  if ((param_1 == (long *)0x0) ||
     (lVar9 = *(long *)(*param_1 + -8), *(int *)(lVar9 + 8) != 3 || lVar9 == 0)) {
    uVar7 = 0xffffffea;
  }
  else {
    uVar2 = of_coresight_get_atid_number(lVar9);
    uVar7 = (ulong)uVar2;
    if (-1 < (int)uVar2) {
      puVar4 = (undefined4 *)__kmalloc(uVar7 << 2,0xb20);
      if (puVar4 == (undefined4 *)0x0) {
        uVar7 = 0xfffffff4;
      }
      else {
        uVar3 = of_coresight_get_atid(lVar9,puVar4,uVar7);
        if ((int)uVar3 < 0) {
          uVar7 = (ulong)uVar3;
        }
        else if (csr_set_atid_ops == (undefined8 *)0x0) {
          uVar7 = 0xffffffea;
        }
        else {
          uVar5 = of_coresight_get_csr_atid_offset(param_2,&local_5c);
          uVar7 = uVar5 & 0xffffffff;
          if ((int)uVar5 == 0) {
            if (uVar2 == 0) {
              uVar7 = 0;
            }
            else {
              uVar5 = (ulong)uVar2;
              puVar8 = puVar4;
              do {
                uVar5 = uVar5 - 1;
                if (*(int *)((code *)*csr_set_atid_ops + -4) != 0x28451bfe) {
                    /* WARNING: Does not return */
                  pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x103310);
                  (*pcVar1)();
                }
                uVar6 = (*(code *)*csr_set_atid_ops)(param_2,local_5c,*puVar8,param_3 & 1);
                uVar7 = uVar6 & 0xffffffff;
              } while ((-1 < (int)uVar6) && (puVar8 = puVar8 + 1, uVar5 != 0));
            }
          }
        }
        kfree(puVar4);
      }
    }
  }
  lVar9 = sp_el0;
  if (*(long *)(lVar9 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar7;
}



//------------------------------------------------------------
// coresight_get_enabled_sink @ 0010335c size=32
// signature: undefined coresight_get_enabled_sink(void)
// callers: []
//------------------------------------------------------------

void coresight_get_enabled_sink(long param_1)

{
  if (param_1 != 0) {
    coresight_find_enabled_sink();
  }
  return;
}



//------------------------------------------------------------
// coresight_find_enabled_sink @ 0010337c size=120
// signature: undefined coresight_find_enabled_sink(void)
// callers: [coresight_find_enabled_sink, coresight_get_enabled_sink, coresight_enable]
//------------------------------------------------------------

long * coresight_find_enabled_sink(long *param_1)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  if (((*(uint *)(param_1 + 1) | 2) != 2) || (*(char *)((long)param_1 + 0x3d2) == '\0')) {
    uVar1 = *(uint *)(*param_1 + 4);
    uVar3 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      plVar4 = (long *)(*(long *)(*param_1 + 8) + 0x18);
      do {
        if ((*plVar4 != 0) &&
           (plVar2 = (long *)coresight_find_enabled_sink(), plVar2 != (long *)0x0)) {
          return plVar2;
        }
        plVar4 = plVar4 + 6;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
    param_1 = (long *)0x0;
  }
  return param_1;
}



//------------------------------------------------------------
// coresight_get_sink_by_id @ 001033f8 size=112
// signature: undefined coresight_get_sink_by_id(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

void coresight_get_sink_by_id(undefined4 param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  undefined4 local_1c;
  long local_18;
  
  lVar1 = sp_el0;
  local_18 = *(long *)(lVar1 + 0x638);
  local_1c = param_1;
  lVar3 = bus_find_device(&coresight_bustype,0,&local_1c,coresight_sink_by_id);
  lVar2 = sp_el0;
  lVar1 = 0;
  if (lVar3 != 0) {
    lVar1 = lVar3 + -0x38;
  }
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar1);
  }
  return;
}



//------------------------------------------------------------
// coresight_sink_by_id @ 0010346c size=56
// signature: undefined coresight_sink_by_id(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_sink_by_id(long param_1,int *param_2)

{
  if ((((*(uint *)(param_1 + -0x30) | 2) == 2) && (*(long *)(param_1 + 0x3a0) != 0)) &&
     (*param_2 == *(int *)(*(long *)(param_1 + 0x3a0) + 0x20))) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// coresight_build_path @ 001034a8 size=148
// signature: undefined coresight_build_path(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long coresight_build_path(undefined8 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  if (param_2 == 0) {
    lVar2 = -0x16;
  }
  else {
    lVar2 = kmalloc_trace(__dev_err,0xdc0,0x10);
    if (lVar2 == 0) {
      lVar2 = -0xc;
    }
    else {
      *(long *)lVar2 = lVar2;
      *(long *)(lVar2 + 8) = lVar2;
      iVar1 = _coresight_build_path(param_1,param_2,lVar2,param_1);
      if (iVar1 != 0) {
        kfree(lVar2);
        lVar2 = (long)iVar1;
      }
    }
  }
  return lVar2;
}



//------------------------------------------------------------
// _coresight_build_path @ 0010353c size=548
// signature: undefined _coresight_build_path(void)
// callers: [_coresight_build_path, coresight_build_path, coresight_enable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 _coresight_build_path(long *param_1,long *param_2,long *param_3,long param_4)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  char *__s1;
  undefined8 uVar4;
  long *plVar5;
  ulong uVar6;
  char *__s2;
  long *plVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  long lVar11;
  
  if (param_1 == param_2) {
LAB_001036d4:
    uVar4 = coresight_grab_device(param_1);
    if ((int)uVar4 == 0) {
      plVar5 = (long *)kmalloc_trace(__dev_err,0xdc0,0x18);
      if (plVar5 == (long *)0x0) {
        uVar4 = 0xfffffff4;
      }
      else {
        lVar11 = *param_3;
        plVar7 = plVar5 + 1;
        *plVar5 = (long)param_1;
        uVar6 = __list_add_valid(plVar7,param_3,lVar11);
        if ((uVar6 & 1) == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = 0;
          *(long **)(lVar11 + 8) = plVar7;
          plVar5[1] = lVar11;
          plVar5[2] = (long)param_3;
          *param_3 = (long)plVar7;
        }
      }
    }
  }
  else {
    if ((((param_1 != (long *)0x0) && ((int)param_1[1] == 3)) &&
        (*(int *)((long)param_1 + 0xc) == 0)) &&
       (((int)param_2[1] == 0 && (*(int *)((long)param_2 + 0xc) == 3)))) {
      if (*(int *)((code *)**(undefined8 **)(param_1[3] + 0x10) + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1035c4);
        (*pcVar1)();
      }
      uVar2 = (*(code *)**(undefined8 **)(param_1[3] + 0x10))(param_1);
      if (0x1f < uVar2) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103760);
        (*pcVar1)();
      }
      if (((*(long **)(&csdev_sink + *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8)) == param_2) &&
          (iVar3 = coresight_grab_device(param_2), iVar3 == 0)) &&
         (plVar5 = (long *)kmalloc_trace(__dev_err,0xdc0,0x18), plVar5 != (long *)0x0)) {
        lVar11 = *param_3;
        plVar7 = plVar5 + 1;
        *plVar5 = (long)param_2;
        uVar6 = __list_add_valid(plVar7,param_3,lVar11);
        if ((uVar6 & 1) != 0) {
          *(long **)(lVar11 + 8) = plVar7;
          plVar5[1] = lVar11;
          plVar5[2] = (long)param_3;
          *param_3 = (long)plVar7;
        }
        goto LAB_001036d4;
      }
    }
    lVar11 = *param_1;
    if (0 < *(int *)(lVar11 + 4)) {
      lVar9 = 0;
      lVar10 = 0;
      do {
        lVar8 = *(long *)(lVar11 + 8) + lVar9;
        __s1 = *(char **)(lVar8 + 8);
        lVar8 = *(long *)(lVar8 + 0x18);
        if (__s1 == (char *)0x0) {
          if (lVar8 != 0) goto LAB_00103664;
        }
        else {
          __s2 = *(char **)(param_4 + 0xa8);
          if (__s2 == (char *)0x0) {
            __s2 = *(char **)(param_4 + 0x38);
          }
          iVar3 = strcmp(__s1,__s2);
          if (iVar3 == 0 && lVar8 != 0) {
LAB_00103664:
            iVar3 = _coresight_build_path(lVar8,param_2,param_3,param_4);
            if (iVar3 == 0) goto LAB_001036d4;
            lVar11 = *param_1;
          }
        }
        lVar10 = lVar10 + 1;
        lVar9 = lVar9 + 0x30;
      } while (lVar10 < *(int *)(lVar11 + 4));
    }
    uVar4 = 0xffffffed;
  }
  return uVar4;
}



//------------------------------------------------------------
// coresight_release_path @ 00103764 size=320
// signature: undefined coresight_release_path(void)
// callers: [__coresight_disable, free_event_data, coresight_enable]
//------------------------------------------------------------

void coresight_release_path(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long lVar4;
  long *plVar5;
  long *plVar6;
  long lVar7;
  long lVar8;
  
  plVar1 = (long *)*param_1;
  while (plVar1 != param_1) {
    plVar5 = (long *)*plVar1;
    plVar6 = (long *)plVar1[-1];
    lVar4 = plVar6[0x13];
    __pm_runtime_idle(lVar4,5);
    put_device(lVar4);
    module_put(*(undefined8 *)(*(long *)(lVar4 + 0x88) + 0x10));
    lVar4 = *plVar6;
    if (0 < *(int *)(lVar4 + 4)) {
      lVar7 = 0;
      lVar8 = 0x18;
      do {
        lVar3 = *(long *)(*(long *)(lVar4 + 8) + lVar8);
        if ((lVar3 != 0) && (*(int *)(lVar3 + 8) == 4)) {
          lVar4 = *(long *)(lVar3 + 0x98);
          __pm_runtime_idle(lVar4,5);
          put_device(lVar4);
          module_put(*(undefined8 *)(*(long *)(lVar4 + 0x88) + 0x10));
          lVar4 = *plVar6;
        }
        lVar7 = lVar7 + 1;
        lVar8 = lVar8 + 0x30;
      } while (lVar7 < *(int *)(lVar4 + 4));
    }
    uVar2 = __list_del_entry_valid(plVar1);
    if ((uVar2 & 1) != 0) {
      lVar4 = *plVar1;
      plVar6 = (long *)plVar1[1];
      *(long **)(lVar4 + 8) = plVar6;
      *plVar6 = lVar4;
    }
    *plVar1 = -0x2152ffffffffff00;
    plVar1[1] = -0x2152fffffffffede;
    kfree(plVar1 + -1);
    plVar1 = plVar5;
  }
  kfree(param_1);
  return;
}



//------------------------------------------------------------
// coresight_find_default_sink @ 001038a8 size=224
// signature: undefined coresight_find_default_sink(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

void coresight_find_default_sink(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  long lVar3;
  code *pcVar4;
  undefined4 local_2c;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_2c = 0;
  if (*(long *)(param_1 + 0x3e0) == 0) {
    if (((param_1 != 0) && (*(int *)(param_1 + 8) == 3)) && (*(int *)(param_1 + 0xc) == 0)) {
      pcVar4 = (code *)**(undefined8 **)(*(long *)(param_1 + 0x18) + 0x10);
      if (*(int *)(pcVar4 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x103950);
        (*pcVar4)();
      }
      uVar1 = (*pcVar4)(param_1);
      if (0x1f < uVar1) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x103988);
        (*pcVar4)();
      }
      lVar3 = *(long *)(&csdev_sink + *(long *)(&__per_cpu_offset + (ulong)uVar1 * 8));
      *(long *)(param_1 + 0x3e0) = lVar3;
      if (lVar3 != 0) goto LAB_00103900;
    }
    uVar2 = coresight_find_sink(param_1,&local_2c);
    *(undefined8 *)(param_1 + 0x3e0) = uVar2;
  }
LAB_00103900:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// coresight_find_sink @ 00103988 size=284
// signature: undefined coresight_find_sink(void)
// callers: [coresight_find_default_sink, coresight_find_sink]
//------------------------------------------------------------

long * coresight_find_sink(long *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  long *plVar4;
  long *plVar5;
  int iVar6;
  ulong uVar7;
  long *plVar8;
  int local_4c;
  long local_48;
  
  lVar3 = sp_el0;
  local_48 = *(long *)(lVar3 + 0x638);
  iVar1 = *param_2 + 1;
  if (((*(uint *)(param_1 + 1) | 2) == 2) && (*(int *)((long)param_1 + 0xc) != 0)) {
    plVar5 = param_1;
    iVar6 = iVar1;
    if (*(uint *)(param_1 + 1) == 0) goto LAB_00103a64;
  }
  else {
    iVar6 = 0;
    plVar5 = (long *)0x0;
  }
  uVar2 = *(uint *)(*param_1 + 4);
  uVar7 = (ulong)uVar2;
  if (0 < (int)uVar2) {
    plVar8 = (long *)(*(long *)(*param_1 + 8) + 0x18);
    do {
      local_4c = iVar1;
      if (*plVar8 != 0) {
        plVar4 = (long *)coresight_find_sink(*plVar8,&local_4c);
        if (plVar4 != (long *)0x0) {
          if ((plVar5 != (long *)0x0) &&
             (*(uint *)((long)plVar4 + 0xc) <= *(uint *)((long)plVar5 + 0xc))) {
            if ((*(uint *)((long)plVar4 + 0xc) != *(uint *)((long)plVar5 + 0xc)) ||
               (iVar6 <= local_4c)) goto LAB_00103a18;
          }
          plVar5 = plVar4;
          iVar6 = local_4c;
        }
      }
LAB_00103a18:
      plVar8 = plVar8 + 6;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
LAB_00103a64:
  if (plVar5 != (long *)0x0) {
    *param_2 = iVar6;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return plVar5;
}



//------------------------------------------------------------
// coresight_enable @ 00103aa8 size=480
// signature: undefined coresight_enable(void)
// callers: [enable_source_store]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulong coresight_enable(long param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  ulong uVar4;
  char *pcVar5;
  char *pcVar6;
  int *piVar7;
  ulong uVar8;
  long lVar9;
  
  iVar3 = *(int *)(param_1 + 0xc);
  mutex_lock(&coresight_mutex);
  if (*(int *)(param_1 + 8) == 3) {
    if ((*(uint *)(param_1 + 0xc) & 0xfffffffd) != 0) {
      pcVar5 = "wrong device subtype in %s\n";
      goto LAB_00103c0c;
    }
    if (*(char *)(param_1 + 0x3d1) != '\0') {
      if (iVar3 == 2) {
        piVar7 = *(int **)(param_1 + 0x3c8);
        Hint_Prefetch(piVar7,2,0,1);
        do {
          cVar1 = '\x01';
          bVar2 = (bool)ExclusiveMonitorPass(piVar7,0x10);
          if (bVar2) {
            *piVar7 = *piVar7 + 1;
            cVar1 = ExclusiveMonitorsStatus();
          }
        } while (cVar1 != '\0');
      }
LAB_00103b08:
      uVar8 = 0;
      goto LAB_00103c20;
    }
    lVar9 = *(long *)(param_1 + 0x3e0);
    if (lVar9 != 0) {
      *(undefined1 *)(lVar9 + 0x3d2) = 1;
LAB_00103b20:
      uVar4 = of_coresight_secure_node(lVar9);
      if (((uVar4 & 1) == 0) || (uVar4 = of_coresight_secure_node(param_1), (uVar4 & 1) != 0)) {
        uVar4 = kmalloc_trace(__dev_err,0xdc0,0x10);
        if (uVar4 == 0) {
          uVar8 = 0xfffffffffffffff4;
        }
        else {
          *(ulong *)uVar4 = uVar4;
          *(ulong *)(uVar4 + 8) = uVar4;
          iVar3 = _coresight_build_path(param_1,lVar9,uVar4,param_1);
          if (iVar3 != 0) {
            kfree(uVar4);
            uVar4 = (ulong)iVar3;
          }
          uVar8 = uVar4;
          if (uVar4 < 0xfffffffffffff001) {
            uVar8 = coresight_enable_path(uVar4,1,0);
            if ((int)uVar8 == 0) {
              uVar8 = coresight_enable_source(param_1);
              if (((int)uVar8 == 0) && (uVar8 = coresight_store_path(uVar4), (int)uVar8 == 0))
              goto LAB_00103b08;
              coresight_disable_path_from(uVar4,0);
            }
            uVar8 = uVar8 & 0xffffffff;
            coresight_release_path(uVar4);
            goto LAB_00103c20;
          }
        }
        _printk(&DAT_0010af0c,uVar8 & 0xffffffff);
        goto LAB_00103c20;
      }
      pcVar6 = *(char **)(param_1 + 0xa8);
      if (pcVar6 == (char *)0x0) {
        pcVar6 = *(char **)(param_1 + 0x38);
      }
      pcVar5 = "dont support this source: %s\n";
      param_1 = lVar9;
      goto LAB_00103c18;
    }
    if ((param_1 != 0) && (lVar9 = coresight_find_enabled_sink(param_1), lVar9 != 0))
    goto LAB_00103b20;
  }
  else {
    pcVar5 = "wrong device type in %s\n";
LAB_00103c0c:
    pcVar6 = "coresight_enable";
LAB_00103c18:
    _dev_err(param_1 + 0x38,pcVar5,pcVar6);
  }
  uVar8 = 0xffffffea;
LAB_00103c20:
  mutex_unlock(&coresight_mutex);
  return uVar8 & 0xffffffff;
}



//------------------------------------------------------------
// coresight_enable_source @ 00103c90 size=508
// signature: undefined coresight_enable_source(void)
// callers: [coresight_enable]
//------------------------------------------------------------

int coresight_enable_source(long param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  long lVar6;
  code *pcVar7;
  long *plVar8;
  int *piVar9;
  long lVar10;
  undefined8 uVar11;
  
  pcVar7 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 8);
  if (*(int *)(pcVar7 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103cd0);
    (*pcVar7)();
  }
  iVar3 = (*pcVar7)();
  if ((iVar3 < 0) ||
     (iVar3 = bus_for_each_dev(&coresight_bustype,0,param_1,coresight_id_match), iVar3 != 0)) {
    pcVar7 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 8);
    if (*(int *)(pcVar7 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103e5c);
      (*pcVar7)();
    }
    uVar5 = (*pcVar7)(param_1);
    _dev_warn(param_1 + 0x38,"traceID %d not unique\n",uVar5);
    return -0x16;
  }
  if (*(char *)(param_1 + 0x3d1) == '\0') {
    if (*(long *)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x10) != 0) {
      iVar3 = coresight_control_assoc_ectdev(param_1,1);
      if (iVar3 != 0) {
        return iVar3;
      }
      pcVar7 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x10);
      if (*(int *)(pcVar7 + -4) != 0x189af055) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103d54);
        (*pcVar7)();
      }
      iVar3 = (*pcVar7)(param_1,0,1);
      if (iVar3 != 0) {
        lVar10 = *(long *)(param_1 + 1000);
        if (lVar10 == 0) {
          return iVar3;
        }
        plVar8 = *(long **)(*(long *)(lVar10 + 0x18) + 0x20);
        if (*plVar8 == 0) {
          return iVar3;
        }
        pcVar7 = (code *)plVar8[1];
        if (pcVar7 == (code *)0x0) {
          return iVar3;
        }
        if (*(char *)(param_1 + 0x3f5) == '\0') {
          return iVar3;
        }
        uVar11 = *(undefined8 *)(*(long *)(*(long *)(lVar10 + 0x98) + 0x88) + 0x10);
        if (*(int *)(pcVar7 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x103db0);
          (*pcVar7)();
        }
        iVar4 = (*pcVar7)(lVar10);
        put_device(*(undefined8 *)(lVar10 + 0x98));
        module_put(uVar11);
        *(undefined1 *)(param_1 + 0x3f5) = 0;
        if (iVar4 == 0) {
          return iVar3;
        }
        lVar6 = *(long *)(lVar10 + 0xa8);
        if (lVar6 == 0) {
          lVar6 = *(long *)(lVar10 + 0x38);
        }
        _dev_info(param_1 + 0x38,"Associated ECT device (%s) %s failed\n",lVar6,"disable");
        return iVar3;
      }
    }
    *(undefined1 *)(param_1 + 0x3d1) = 1;
  }
  piVar9 = *(int **)(param_1 + 0x3c8);
  Hint_Prefetch(piVar9,2,0,1);
  do {
    cVar1 = '\x01';
    bVar2 = (bool)ExclusiveMonitorPass(piVar9,0x10);
    if (bVar2) {
      *piVar9 = *piVar9 + 1;
      cVar1 = ExclusiveMonitorsStatus();
    }
  } while (cVar1 != '\0');
  return 0;
}



//------------------------------------------------------------
// coresight_store_path @ 00103e94 size=152
// signature: undefined coresight_store_path(void)
// callers: [coresight_enable]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 coresight_store_path(undefined8 param_1)

{
  undefined *puVar1;
  undefined8 *puVar2;
  ulong uVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  puVar2 = (undefined8 *)kmalloc_trace(__dev_err,0xdc0,0x18);
  puVar1 = cs_active_paths;
  if (puVar2 == (undefined8 *)0x0) {
    uVar4 = 0xfffffff4;
  }
  else {
    puVar5 = puVar2 + 1;
    *puVar2 = param_1;
    uVar3 = __list_add_valid(puVar5,&cs_active_paths,puVar1);
    if ((uVar3 & 1) == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 0;
      *(undefined8 **)(puVar1 + 8) = puVar5;
      puVar2[1] = puVar1;
      puVar2[2] = &cs_active_paths;
      cs_active_paths = (undefined *)puVar5;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// coresight_disable @ 00103f30 size=68
// signature: undefined coresight_disable(void)
// callers: []
//------------------------------------------------------------

void coresight_disable(undefined8 param_1)

{
  mutex_lock(&coresight_mutex);
  __coresight_disable(param_1);
  mutex_unlock(&coresight_mutex);
  return;
}



//------------------------------------------------------------
// __coresight_disable @ 00103f74 size=592
// signature: undefined __coresight_disable(void)
// callers: [enable_source_store, reset_source_sink_store, coresight_disable]
//------------------------------------------------------------

void __coresight_disable(long param_1)

{
  undefined *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  ulong uVar5;
  char *pcVar6;
  long lVar7;
  int *piVar8;
  code *pcVar9;
  long lVar10;
  undefined **ppuVar11;
  undefined8 uVar12;
  long *plVar13;
  undefined **ppuVar14;
  long *plVar15;
  
  if (*(int *)(param_1 + 8) == 3) {
    if ((*(uint *)(param_1 + 0xc) & 0xfffffffd) == 0) {
      if (*(long *)(param_1 + 0x3e0) != 0) {
        *(undefined8 *)(param_1 + 0x3e0) = 0;
      }
      if (*(char *)(param_1 + 0x3d1) == '\0') {
        return;
      }
      piVar8 = *(int **)(param_1 + 0x3c8);
      Hint_Prefetch(piVar8,2,0,1);
      do {
        iVar4 = *piVar8;
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(piVar8,0x10);
        if (bVar3) {
          *piVar8 = iVar4 + -1;
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      DataMemoryBarrier(2,3);
      if (iVar4 + -1 == 0) {
        pcVar9 = *(code **)(*(long *)(*(long *)(param_1 + 0x18) + 0x10) + 0x18);
        if (pcVar9 != (code *)0x0) {
          if (*(int *)(pcVar9 + -4) != -0x75220976) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x10402c);
            (*pcVar9)();
          }
          (*pcVar9)(param_1,0);
        }
        lVar10 = *(long *)(param_1 + 1000);
        if ((((lVar10 != 0) &&
             (plVar13 = *(long **)(*(long *)(lVar10 + 0x18) + 0x20), *plVar13 != 0)) &&
            (pcVar9 = (code *)plVar13[1], pcVar9 != (code *)0x0)) &&
           (*(char *)(param_1 + 0x3f5) != '\0')) {
          uVar12 = *(undefined8 *)(*(long *)(*(long *)(lVar10 + 0x98) + 0x88) + 0x10);
          if (*(int *)(pcVar9 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x104080);
            (*pcVar9)();
          }
          iVar4 = (*pcVar9)(lVar10);
          put_device(*(undefined8 *)(lVar10 + 0x98));
          module_put(uVar12);
          *(undefined1 *)(param_1 + 0x3f5) = 0;
          if (iVar4 != 0) {
            lVar7 = *(long *)(lVar10 + 0xa8);
            if (lVar7 == 0) {
              lVar7 = *(long *)(lVar10 + 0x38);
            }
            _dev_info(param_1 + 0x38,"Associated ECT device (%s) %s failed\n",lVar7,"disable");
          }
        }
        ppuVar11 = (undefined **)cs_active_paths;
        *(undefined1 *)(param_1 + 0x3d1) = 0;
        if (ppuVar11 == &cs_active_paths) {
          return;
        }
      }
      else {
        if (*(char *)(param_1 + 0x3d1) != '\0') {
          return;
        }
        ppuVar11 = (undefined **)cs_active_paths;
        if ((undefined **)cs_active_paths == &cs_active_paths) {
          return;
        }
      }
      plVar13 = (long *)0x0;
      do {
        ppuVar14 = (undefined **)*ppuVar11;
        plVar15 = (long *)ppuVar11[-1];
        if (plVar15 != (long *)0x0) {
          lVar10 = *(long *)(*plVar15 + -8);
          if (*(int *)(lVar10 + 8) != 3) {
            lVar10 = 0;
          }
          if (lVar10 != 0 && lVar10 == param_1) {
            uVar5 = __list_del_entry_valid(ppuVar11);
            if ((uVar5 & 1) != 0) {
              puVar1 = *ppuVar11;
              plVar13 = (long *)ppuVar11[1];
              *(long **)(puVar1 + 8) = plVar13;
              *plVar13 = (long)puVar1;
            }
            *ppuVar11 = (undefined *)0xdead000000000100;
            ppuVar11[1] = (undefined *)0xdead000000000122;
            kfree(ppuVar11 + -1);
            plVar13 = plVar15;
          }
        }
        ppuVar11 = ppuVar14;
      } while (ppuVar14 != &cs_active_paths);
      if (plVar13 == (long *)0x0) {
        return;
      }
      coresight_disable_path_from(plVar13,0);
      coresight_release_path(plVar13);
      return;
    }
    pcVar6 = "wrong device subtype in %s\n";
  }
  else {
    pcVar6 = "wrong device type in %s\n";
  }
  _dev_err(param_1 + 0x38,pcVar6,"__coresight_disable");
  return;
}



//------------------------------------------------------------
// coresight_timeout_action @ 001041d4 size=268
// signature: undefined coresight_timeout_action(void)
// callers: []
//------------------------------------------------------------

undefined8
coresight_timeout_action(char *param_1,uint param_2,ulong param_3,int param_4,code *param_5)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = 0x65;
  while( true ) {
    pcVar2 = *(code **)(param_1 + 8);
    if (*param_1 == '\0') {
      if (*(int *)(pcVar2 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x1042b0);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_2,0,0);
    }
    else {
      uVar1 = readl(pcVar2 + param_2);
    }
    uVar1 = 1L << (param_3 & 0x3f) & uVar1 & 0xffffffff;
    if (param_4 == 0) {
      if (uVar1 == 0) {
        return 0;
      }
    }
    else if (uVar1 != 0) {
      return 0;
    }
    if (param_5 != (code *)0x0) {
      if (*(int *)(param_5 + -4) != 0x671d44d2) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8233,0x10426c);
        (*pcVar2)();
      }
      (*param_5)(param_1,param_2,param_3 & 0xffffffff,param_4);
    }
    if (iVar3 == 2) break;
    __const_udelay(0x10c7);
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return 0xfffffff5;
    }
  }
  return 0xfffffff5;
}



//------------------------------------------------------------
// coresight_timeout @ 001042e4 size=196
// signature: undefined coresight_timeout(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_timeout(char *param_1,uint param_2,ulong param_3,int param_4)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  
  iVar3 = -99;
  while( true ) {
    pcVar2 = *(code **)(param_1 + 8);
    if (*param_1 == '\0') {
      if (*(int *)(pcVar2 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x8228,0x10437c);
        (*pcVar2)();
      }
      uVar1 = (*pcVar2)(param_2,0,0);
    }
    else {
      uVar1 = readl(pcVar2 + param_2);
    }
    uVar1 = 1L << (param_3 & 0x3f) & uVar1 & 0xffffffff;
    if (param_4 == 0) {
      if (uVar1 == 0) {
        return 0;
      }
    }
    else if (uVar1 != 0) {
      return 0;
    }
    if (iVar3 == 0) break;
    __const_udelay(0x10c7);
    iVar3 = iVar3 + 1;
  }
  return 0xfffffff5;
}



//------------------------------------------------------------
// coresight_relaxed_read32 @ 001043ac size=88
// signature: undefined coresight_relaxed_read32(void)
// callers: []
//------------------------------------------------------------

void coresight_relaxed_read32(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar1 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1043fc);
      (*pcVar1)();
    }
    (*pcVar1)(param_2,1,0);
  }
  else {
    readl_relaxed(pcVar1 + param_2);
  }
  return;
}



//------------------------------------------------------------
// coresight_read32 @ 00104408 size=88
// signature: undefined coresight_read32(void)
// callers: []
//------------------------------------------------------------

void coresight_read32(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar1 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104458);
      (*pcVar1)();
    }
    (*pcVar1)(param_2,0,0);
  }
  else {
    readl(pcVar1 + param_2);
  }
  return;
}



//------------------------------------------------------------
// coresight_relaxed_write32 @ 00104464 size=104
// signature: undefined coresight_relaxed_write32(void)
// callers: []
//------------------------------------------------------------

void coresight_relaxed_write32(long param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1044c4);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x30))(param_2,param_3,1,0);
  }
  else {
    writel_relaxed(param_2,*(long *)(param_1 + 0x28) + (ulong)param_3);
  }
  return;
}



//------------------------------------------------------------
// coresight_write32 @ 001044d0 size=104
// signature: undefined coresight_write32(void)
// callers: []
//------------------------------------------------------------

void coresight_write32(long param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104530);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x30))(param_2,param_3,0,0);
  }
  else {
    writel(param_2,*(long *)(param_1 + 0x28) + (ulong)param_3);
  }
  return;
}



//------------------------------------------------------------
// coresight_relaxed_read64 @ 0010453c size=88
// signature: undefined coresight_relaxed_read64(void)
// callers: []
//------------------------------------------------------------

void coresight_relaxed_read64(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar1 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x10458c);
      (*pcVar1)();
    }
    (*pcVar1)(param_2,1,1);
  }
  else {
    readq_relaxed(pcVar1 + param_2);
  }
  return;
}



//------------------------------------------------------------
// coresight_read64 @ 00104598 size=88
// signature: undefined coresight_read64(void)
// callers: []
//------------------------------------------------------------

void coresight_read64(long param_1,uint param_2)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x28);
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(pcVar1 + -4) != -0x3e6d5b83) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1045e8);
      (*pcVar1)();
    }
    (*pcVar1)(param_2,0,1);
  }
  else {
    readq(pcVar1 + param_2);
  }
  return;
}



//------------------------------------------------------------
// coresight_relaxed_write64 @ 001045f4 size=100
// signature: undefined coresight_relaxed_write64(void)
// callers: []
//------------------------------------------------------------

void coresight_relaxed_write64(long param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104650);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x30))(param_2,param_3,1,1);
  }
  else {
    writeq_relaxed(param_2,*(long *)(param_1 + 0x28) + (ulong)param_3);
  }
  return;
}



//------------------------------------------------------------
// coresight_write64 @ 0010465c size=100
// signature: undefined coresight_write64(void)
// callers: []
//------------------------------------------------------------

void coresight_write64(long param_1,undefined8 param_2,uint param_3)

{
  code *pcVar1;
  
  if (*(char *)(param_1 + 0x20) == '\0') {
    if (*(int *)(*(code **)(param_1 + 0x30) + -4) != -0x5257f840) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1046b8);
      (*pcVar1)();
    }
    (**(code **)(param_1 + 0x30))(param_2,param_3,0,1);
  }
  else {
    writeq(param_2,*(long *)(param_1 + 0x28) + (ulong)param_3);
  }
  return;
}



//------------------------------------------------------------
// coresight_release_platform_data @ 001046c4 size=172
// signature: undefined coresight_release_platform_data(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

void coresight_release_platform_data(long param_1,long param_2)

{
  long lVar1;
  long lVar2;
  long lVar3;
  
  if (0 < *(int *)(param_2 + 4)) {
    lVar1 = 0;
    lVar2 = 0;
    lVar3 = *(long *)(param_2 + 8);
    do {
      if (param_1 != 0) {
        if (*(long *)(lVar3 + lVar1 + 0x18) != 0) {
          coresight_remove_links(param_1);
        }
      }
      if (*(long *)(lVar3 + lVar1 + 0x10) != 0) {
        fwnode_handle_put();
        *(undefined8 *)(*(long *)(param_2 + 8) + lVar1 + 0x10) = 0;
      }
      lVar2 = lVar2 + 1;
      lVar1 = lVar1 + 0x30;
    } while (lVar2 < *(int *)(param_2 + 4));
  }
  if (param_1 != 0) {
    coresight_remove_conns_sysfs_group(param_1);
  }
  return;
}



//------------------------------------------------------------
// coresight_register @ 00104774 size=776
// signature: undefined coresight_register(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long * coresight_register(uint *param_1)

{
  long *plVar1;
  uint uVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  int iVar6;
  int *piVar7;
  code *pcVar8;
  undefined8 uVar9;
  long lVar10;
  long lVar11;
  long lVar12;
  
  plVar4 = (long *)kmalloc_trace(_fwnode_handle_put,0xdc0,0x438);
  if (plVar4 != (long *)0x0) {
    if (*param_1 - 1 < 2) {
      if (param_1[2] == 1) {
        piVar7 = (int *)(*(long *)(param_1 + 6) + 4);
      }
      else {
        if (param_1[2] != 0) goto LAB_001047d4;
        piVar7 = *(int **)(param_1 + 6);
      }
      if (-1 < *piVar7) {
        lVar5 = (long)*piVar7 << 2;
        goto LAB_001047f0;
      }
    }
    else {
LAB_001047d4:
      lVar5 = 4;
LAB_001047f0:
      lVar5 = __kmalloc(lVar5,0xdc0);
      if (lVar5 != 0) {
        uVar9 = *(undefined8 *)(param_1 + 1);
        plVar4[0x79] = lVar5;
        lVar5 = *(long *)(param_1 + 4);
        lVar12 = *(long *)(param_1 + 6);
        *(undefined1 *)(plVar4 + 0x7a) = 0;
        *(undefined8 *)((long)plVar4 + 0xc) = uVar9;
        lVar10 = *(long *)(param_1 + 0xe);
        lVar11 = *(long *)(param_1 + 0x10);
        *plVar4 = lVar12;
        uVar2 = *param_1;
        plVar4[3] = lVar5;
        plVar4[4] = lVar10;
        lVar5 = *(long *)(param_1 + 0x12);
        *(uint *)(plVar4 + 1) = uVar2;
        plVar4[5] = lVar11;
        plVar4[6] = lVar5;
        if (6 < uVar2) {
                    /* WARNING: Does not return */
          pcVar8 = (code *)SoftwareBreakpoint(0x5512,0x104a7c);
          (*pcVar8)();
        }
        lVar5 = *(long *)(param_1 + 10);
        plVar1 = plVar4 + 7;
        plVar4[0x13] = *(long *)(param_1 + 8);
        plVar4[0x6b] = lVar5;
        plVar4[0x6c] = (long)coresight_device_release;
        plVar4[0x16] = (long)(&coresight_dev_type + (ulong)uVar2 * 6);
        plVar4[0x17] = (long)&coresight_bustype;
        dev_fwnode();
        lVar5 = fwnode_handle_get();
        uVar9 = *(undefined8 *)(param_1 + 0xc);
        plVar4[0x65] = lVar5;
        dev_set_name(plVar1,&DAT_0010ae8d,uVar9);
        mutex_lock(&coresight_mutex);
        iVar3 = device_register(plVar1);
        if (iVar3 == 0) {
          if (((*(uint *)(plVar4 + 1) | 2) != 2) ||
             (iVar3 = etm_perf_add_symlink_sink(plVar4), iVar3 == 0)) {
            iVar3 = coresight_create_conns_sysfs_group(plVar4);
            if (iVar3 == 0) {
              lVar5 = *plVar4;
              if (0 < *(int *)(lVar5 + 4)) {
                lVar12 = 0;
                lVar10 = 0;
                do {
                  lVar5 = *(long *)(lVar5 + 8) + lVar12;
                  if (*(long *)(lVar5 + 0x10) != 0) {
                    lVar11 = coresight_find_csdev_by_fwnode();
                    *(long *)(lVar5 + 0x18) = lVar11;
                    if ((lVar11 == 0) || (*(char *)(lVar11 + 0x3f4) == '\0')) {
                      *(undefined1 *)(plVar4 + 0x7a) = 1;
                    }
                    else {
                      iVar3 = coresight_make_links(plVar4,lVar5,lVar11);
                      if (iVar3 != 0) goto LAB_00104974;
                    }
                  }
                  lVar5 = *plVar4;
                  lVar10 = lVar10 + 1;
                  lVar12 = lVar12 + 0x30;
                } while (lVar10 < *(int *)(lVar5 + 4));
              }
              iVar3 = bus_for_each_dev(&coresight_bustype,0,plVar4,coresight_orphan_match);
              mutex_unlock(&coresight_mutex);
              if (iVar3 == 0) {
                if (cti_assoc_ops == (undefined8 *)0x0) {
                  return plVar4;
                }
                pcVar8 = (code *)*cti_assoc_ops;
                if (pcVar8 == (code *)0x0) {
                  return plVar4;
                }
                if (*(int *)(pcVar8 + -4) != 0x27b4c5fc) {
                    /* WARNING: Does not return */
                  pcVar8 = (code *)SoftwareBreakpoint(0x8228,0x104a70);
                  (*pcVar8)();
                }
                (*pcVar8)(plVar4);
                return plVar4;
              }
            }
            else {
LAB_00104974:
              mutex_unlock(&coresight_mutex);
            }
            coresight_unregister(plVar4);
            return (long *)(long)iVar3;
          }
          device_unregister(plVar1);
        }
        else {
          put_device(plVar1);
        }
        mutex_unlock(&coresight_mutex);
        goto LAB_001048f8;
      }
    }
    kfree(plVar4);
  }
  iVar3 = -0xc;
LAB_001048f8:
  lVar5 = *(long *)(param_1 + 6);
  iVar6 = *(int *)(lVar5 + 4);
  if (0 < iVar6) {
    lVar10 = 0;
    lVar11 = *(long *)(lVar5 + 8);
    lVar12 = 0x10;
    do {
      if (*(long *)(lVar11 + lVar12) != 0) {
        fwnode_handle_put();
        *(undefined8 *)(*(long *)(lVar5 + 8) + lVar12) = 0;
        iVar6 = *(int *)(lVar5 + 4);
      }
      lVar10 = lVar10 + 1;
      lVar12 = lVar12 + 0x30;
    } while (lVar10 < iVar6);
  }
  return (long *)(long)iVar3;
}



//------------------------------------------------------------
// coresight_device_release @ 00104a80 size=64
// signature: undefined coresight_device_release(void)
// callers: []
//------------------------------------------------------------

void coresight_device_release(long param_1)

{
  fwnode_handle_put(*(undefined8 *)(param_1 + 0x2f0));
  kfree(*(undefined8 *)(param_1 + 0x390));
  kfree(param_1 + -0x38);
  return;
}



//------------------------------------------------------------
// coresight_unregister @ 00104ac4 size=320
// signature: undefined coresight_unregister(void)
// callers: [coresight_register]
//------------------------------------------------------------

void coresight_unregister(long *param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  
  etm_perf_del_symlink_sink();
  if ((cti_assoc_ops != 0) && (pcVar1 = *(code **)(cti_assoc_ops + 8), pcVar1 != (code *)0x0)) {
    if (*(int *)(pcVar1 + -4) != 0x27b4c5fc) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x104b14);
      (*pcVar1)();
    }
    (*pcVar1)(param_1);
  }
  if (*(int *)*param_1 != 0) {
    bus_for_each_dev(&coresight_bustype,0,param_1,coresight_remove_match);
  }
  if ((*(uint *)(param_1 + 1) | 2) == 2) {
    bus_for_each_dev(&coresight_bustype,0,param_1,coresight_remove_sink_ref);
  }
  lVar2 = *param_1;
  if (0 < *(int *)(lVar2 + 4)) {
    lVar3 = 0;
    lVar4 = 0;
    lVar5 = *(long *)(lVar2 + 8);
    do {
      if (param_1 != (long *)0x0) {
        if (*(long *)(lVar5 + lVar3 + 0x18) != 0) {
          coresight_remove_links(param_1);
        }
      }
      if (*(long *)(lVar5 + lVar3 + 0x10) != 0) {
        fwnode_handle_put();
        *(undefined8 *)(*(long *)(lVar2 + 8) + lVar3 + 0x10) = 0;
      }
      lVar4 = lVar4 + 1;
      lVar3 = lVar3 + 0x30;
    } while (lVar4 < *(int *)(lVar2 + 4));
  }
  if (param_1 != (long *)0x0) {
    coresight_remove_conns_sysfs_group(param_1);
  }
  device_unregister(param_1 + 7);
  return;
}



//------------------------------------------------------------
// coresight_loses_context_with_cpu @ 00104c08 size=44
// signature: undefined coresight_loses_context_with_cpu(void)
// callers: []
//------------------------------------------------------------

uint coresight_loses_context_with_cpu(void)

{
  uint uVar1;
  undefined8 uVar2;
  
  uVar2 = dev_fwnode();
  uVar1 = fwnode_property_present(uVar2,"arm,coresight-loses-context-with-cpu");
  return uVar1 & 1;
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 00104c38 size=372
// signature: undefined coresight_alloc_device_name(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_alloc_device_name(uint *param_1,long param_2)

{
  uint uVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  undefined8 uVar8;
  undefined8 local_60;
  long local_58;
  
  lVar5 = sp_el0;
  local_58 = *(long *)(lVar5 + 0x638);
  uVar8 = *(undefined8 *)(param_2 + 0x2e8);
  local_60 = 0;
  mutex_lock(&coresight_mutex);
  iVar4 = of_property_read_string(uVar8,"coresight-name",&local_60);
  if (iVar4 == 0) {
    uVar8 = devm_kasprintf(param_2,0xcc0,&DAT_0010ae8d,local_60);
  }
  else {
    lVar5 = dev_fwnode(param_2);
    uVar2 = *param_1;
    if (0 < (int)uVar2) {
      uVar7 = 0;
      do {
        if (*(long *)(*(long *)(param_1 + 4) + uVar7 * 8) == lVar5) {
          if (-1 < (int)uVar7) goto LAB_00104d44;
          break;
        }
        uVar7 = uVar7 + 1;
      } while (uVar2 != uVar7);
    }
    uVar1 = uVar2 + 1;
    if (-1 < (int)uVar1) {
      uVar6 = krealloc(*(undefined8 *)(param_1 + 4),(ulong)uVar1 * 8,0xcc0);
      if (0x10 < uVar6) {
        uVar8 = dev_fwnode(param_2);
        if ((ulong)uVar1 * 8 <= (ulong)((long)(int)uVar2 * 8)) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(1,0x104dac);
          (*pcVar3)();
        }
        uVar7 = (ulong)uVar2;
        *(undefined8 *)(uVar6 + (long)(int)uVar2 * 8) = uVar8;
        *(ulong *)(param_1 + 4) = uVar6;
        *param_1 = uVar1;
LAB_00104d44:
        uVar8 = devm_kasprintf(param_2,0xcc0,&DAT_0010af71,*(undefined8 *)(param_1 + 2),uVar7);
        goto LAB_00104d60;
      }
    }
    uVar8 = 0;
  }
LAB_00104d60:
  mutex_unlock(&coresight_mutex);
  lVar5 = sp_el0;
  if (*(long *)(lVar5 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}



//------------------------------------------------------------
// readl_relaxed @ 00104dac size=124
// signature: undefined readl_relaxed(void)
// callers: [coresight_claim_device_unlocked, coresight_simple_show_pair, coresight_simple_show32, coresight_disclaim_device_unlocked, coresight_disclaim_device, coresight_relaxed_read32]
//------------------------------------------------------------

undefined4 readl_relaxed(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x20,param_1,0x104df4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00104e28 size=132
// signature: undefined writel_relaxed(void)
// callers: [coresight_claim_device_unlocked, coresight_relaxed_write32, coresight_claim_device, coresight_disclaim_device_unlocked, coresight_disclaim_device]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x104e40,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x104e7c,uVar1);
  return;
}



//------------------------------------------------------------
// coresight_control_assoc_ectdev @ 00104eac size=348
// signature: undefined coresight_control_assoc_ectdev(void)
// callers: [coresight_enable_source, coresight_enable_path]
//------------------------------------------------------------

int coresight_control_assoc_ectdev(long param_1,ulong param_2)

{
  char *pcVar1;
  int iVar2;
  ulong uVar3;
  long lVar4;
  long *plVar5;
  code *pcVar6;
  long lVar7;
  undefined8 uVar8;
  
  lVar7 = *(long *)(param_1 + 1000);
  if (((lVar7 == 0) || (plVar5 = *(long **)(*(long *)(lVar7 + 0x18) + 0x20), *plVar5 == 0)) ||
     (pcVar6 = (code *)plVar5[1], pcVar6 == (code *)0x0)) {
LAB_00104fa0:
    iVar2 = 0;
  }
  else {
    uVar8 = *(undefined8 *)(*(long *)(*(long *)(lVar7 + 0x98) + 0x88) + 0x10);
    if ((param_2 & 1) == 0) {
      if (*(char *)(param_1 + 0x3f5) == '\0') goto LAB_00104fa0;
      if (*(int *)(pcVar6 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
        pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x104f74);
        (*pcVar6)();
      }
      iVar2 = (*pcVar6)(lVar7);
      put_device(*(undefined8 *)(lVar7 + 0x98));
      module_put(uVar8);
      *(undefined1 *)(param_1 + 0x3f5) = 0;
      if (iVar2 == 0) {
        return 0;
      }
    }
    else {
      uVar3 = try_module_get(uVar8);
      if ((uVar3 & 1) == 0) {
        iVar2 = -0x13;
      }
      else {
        pcVar6 = (code *)**(undefined8 **)(*(long *)(lVar7 + 0x18) + 0x20);
        if (*(int *)(pcVar6 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
          pcVar6 = (code *)SoftwareBreakpoint(0x8228,0x104f30);
          (*pcVar6)();
        }
        iVar2 = (*pcVar6)(lVar7);
        if (iVar2 == 0) {
          get_device(*(undefined8 *)(lVar7 + 0x98));
          *(undefined1 *)(param_1 + 0x3f5) = 1;
          return 0;
        }
        module_put(uVar8);
      }
    }
    lVar4 = *(long *)(lVar7 + 0xa8);
    if (lVar4 == 0) {
      lVar4 = *(long *)(lVar7 + 0x38);
    }
    pcVar1 = "enable";
    if ((param_2 & 1) == 0) {
      pcVar1 = "disable";
    }
    _dev_info(param_1 + 0x38,"Associated ECT device (%s) %s failed\n",lVar4,pcVar1);
  }
  return iVar2;
}



//------------------------------------------------------------
// coresight_find_link_inport @ 00105008 size=236
// signature: undefined coresight_find_link_inport(void)
// callers: [coresight_disable_path_from, coresight_enable_path]
//------------------------------------------------------------

undefined4 coresight_find_link_inport(long param_1,long *param_2,long *param_3)

{
  uint uVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  long lVar4;
  ulong uVar5;
  long *plVar6;
  
  uVar1 = *(uint *)(*param_2 + 4);
  uVar5 = (ulong)uVar1;
  if (0 < (int)uVar1) {
    plVar6 = (long *)(*(long *)(*param_2 + 8) + 0x18);
    do {
      if (((param_3 == (long *)0x0) || (__s1 = (char *)plVar6[-2], __s1 == (char *)0x0)) ||
         (lVar4 = *(long *)(*param_3 + -8), *(int *)(lVar4 + 8) != 3 || lVar4 == 0)) {
LAB_00105048:
        if (*plVar6 == param_1) {
          return *(undefined4 *)((long)plVar6 + -0x14);
        }
      }
      else {
        if (*(char **)(lVar4 + 0xa8) == (char *)0x0) {
          iVar2 = strcmp(__s1,*(char **)(lVar4 + 0x38));
        }
        else {
          iVar2 = strcmp(__s1,*(char **)(lVar4 + 0xa8));
        }
        if (iVar2 == 0) goto LAB_00105048;
      }
      plVar6 = plVar6 + 6;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  lVar4 = param_2[0x15];
  if (lVar4 == 0) {
    lVar4 = param_2[7];
  }
  lVar3 = *(long *)(param_1 + 0xa8);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_1 + 0x38);
  }
  _dev_err(param_1 + 0x38,"couldn\'t find inport, parent: %s, child: %s\n",lVar4,lVar3);
  return 0xffffffed;
}



//------------------------------------------------------------
// coresight_find_link_outport @ 001050f4 size=232
// signature: undefined coresight_find_link_outport(void)
// callers: [coresight_disable_path_from, coresight_enable_path]
//------------------------------------------------------------

undefined4 coresight_find_link_outport(long *param_1,long param_2,long *param_3)

{
  uint uVar1;
  int iVar2;
  char *__s1;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined4 *puVar6;
  
  uVar1 = *(uint *)(*param_1 + 4);
  uVar5 = (ulong)uVar1;
  if (0 < (int)uVar1) {
    puVar6 = *(undefined4 **)(*param_1 + 8);
    do {
      if (((param_3 == (long *)0x0) || (__s1 = *(char **)(puVar6 + 2), __s1 == (char *)0x0)) ||
         (lVar4 = *(long *)(*param_3 + -8), *(int *)(lVar4 + 8) != 3 || lVar4 == 0)) {
LAB_00105130:
        if (*(long *)(puVar6 + 6) == param_2) {
          return *puVar6;
        }
      }
      else {
        if (*(char **)(lVar4 + 0xa8) == (char *)0x0) {
          iVar2 = strcmp(__s1,*(char **)(lVar4 + 0x38));
        }
        else {
          iVar2 = strcmp(__s1,*(char **)(lVar4 + 0xa8));
        }
        if (iVar2 == 0) goto LAB_00105130;
      }
      puVar6 = puVar6 + 0xc;
      uVar5 = uVar5 - 1;
    } while (uVar5 != 0);
  }
  lVar4 = param_1[0x15];
  if (lVar4 == 0) {
    lVar4 = param_1[7];
  }
  lVar3 = *(long *)(param_2 + 0xa8);
  if (lVar3 == 0) {
    lVar3 = *(long *)(param_2 + 0x38);
  }
  _dev_err(param_1 + 7,"couldn\'t find outport, parent: %s, child: %s\n",lVar4,lVar3);
  return 0xffffffed;
}



//------------------------------------------------------------
// coresight_grab_device @ 001051dc size=476
// signature: undefined coresight_grab_device(void)
// callers: [_coresight_build_path]
//------------------------------------------------------------

undefined8 coresight_grab_device(long *param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  
  lVar8 = *param_1;
  if (*(int *)(lVar8 + 4) < 1) {
    uVar10 = 0;
  }
  else {
    uVar10 = 0;
    lVar11 = 0x18;
    do {
      lVar9 = *(long *)(*(long *)(lVar8 + 8) + lVar11);
      if ((lVar9 != 0) && (*(int *)(lVar9 + 8) == 4)) {
        lVar8 = *(long *)(lVar9 + 0x98);
        uVar7 = try_module_get(*(undefined8 *)(*(long *)(lVar8 + 0x88) + 0x10));
        if ((uVar7 & 1) == 0) goto LAB_0010535c;
        get_device(lVar8);
        iVar6 = __pm_runtime_resume(lVar8,4);
        if (iVar6 < 0) {
          piVar1 = (int *)(lVar8 + 0x1f8);
          iVar6 = *(int *)(lVar8 + 0x1f8);
          goto LAB_00105274;
        }
        lVar8 = *param_1;
      }
      uVar10 = uVar10 + 1;
      lVar11 = lVar11 + 0x30;
    } while ((long)uVar10 < (long)*(int *)(lVar8 + 4));
  }
  lVar8 = param_1[0x13];
  uVar7 = try_module_get(*(undefined8 *)(*(long *)(lVar8 + 0x88) + 0x10));
  if ((uVar7 & 1) != 0) {
    get_device(lVar8);
    iVar6 = __pm_runtime_resume(lVar8,4);
    if (-1 < iVar6) {
      return 0;
    }
    piVar1 = (int *)(lVar8 + 0x1f8);
    iVar6 = *(int *)(lVar8 + 0x1f8);
    do {
      if (iVar6 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar6) goto LAB_00105328;
        cVar3 = '\x01';
        bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar5) {
          *piVar1 = iVar6 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00105328:
      bVar5 = iVar6 != iVar2;
      iVar6 = iVar2;
    } while (bVar5);
  }
LAB_0010535c:
  uVar4 = (int)uVar10 - 1;
  if (-1 < (int)uVar4) {
    lVar8 = (ulong)uVar4 * 0x30 + 0x18;
    do {
      lVar11 = *(long *)(*(long *)(*param_1 + 8) + lVar8);
      if ((lVar11 != 0) && (*(int *)(lVar11 + 8) == 4)) {
        lVar11 = *(long *)(lVar11 + 0x98);
        __pm_runtime_idle(lVar11,5);
        put_device(lVar11);
        module_put(*(undefined8 *)(*(long *)(lVar11 + 0x88) + 0x10));
      }
      uVar4 = (int)uVar10 - 1;
      uVar10 = (ulong)uVar4;
      lVar8 = lVar8 + -0x30;
    } while (0 < (int)uVar4);
  }
  return 0xffffffed;
LAB_00105274:
  do {
    if (iVar6 == 0) break;
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      if (iVar2 != iVar6) goto LAB_00105294;
      cVar3 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar5) {
        *piVar1 = iVar6 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
LAB_00105294:
    bVar5 = iVar6 != iVar2;
    iVar6 = iVar2;
  } while (bVar5);
  goto LAB_0010535c;
}



//------------------------------------------------------------
// coresight_id_match @ 001053e4 size=184
// signature: undefined coresight_id_match(void)
// callers: []
//------------------------------------------------------------

bool coresight_id_match(long param_1,long param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  
  if (((param_1 + -0x38 == param_2) || (*(char *)(param_1 + 0x399) == '\0')) ||
     (*(int *)(param_1 + -0x30) != 3)) {
    bVar1 = false;
  }
  else {
    pcVar4 = *(code **)(*(long *)(*(long *)(param_2 + 0x18) + 0x10) + 8);
    if (*(int *)(pcVar4 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x105444);
      (*pcVar4)();
    }
    iVar2 = (*pcVar4)(param_2);
    pcVar4 = *(code **)(*(long *)(*(long *)(param_1 + -0x20) + 0x10) + 8);
    if (*(int *)(pcVar4 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x105474);
      (*pcVar4)();
    }
    iVar3 = (*pcVar4)(param_1 + -0x38);
    bVar1 = iVar2 == iVar3;
  }
  return bVar1;
}



//------------------------------------------------------------
// readl @ 0010549c size=140
// signature: undefined readl(void)
// callers: [coresight_timeout_action, coresight_read32, coresight_timeout]
//------------------------------------------------------------

undefined4 readl(undefined4 *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x20,param_1,readl,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x20,param_1,0x1054f4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel @ 00105528 size=136
// signature: undefined writel(void)
// callers: [coresight_write32]
//------------------------------------------------------------

void writel(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x105540,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x105580,uVar1);
  return;
}



//------------------------------------------------------------
// readq_relaxed @ 001055b0 size=124
// signature: undefined readq_relaxed(void)
// callers: [coresight_relaxed_read64]
//------------------------------------------------------------

undefined8 readq_relaxed(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq_relaxed,uVar1);
  uVar2 = *param_1;
  log_post_read_mmio(uVar2,0x40,param_1,0x1055f8,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// readq @ 0010562c size=136
// signature: undefined readq(void)
// callers: [coresight_read64]
//------------------------------------------------------------

undefined8 readq(undefined8 *param_1)

{
  ulong uVar1;
  undefined8 uVar2;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_read_mmio(0x40,param_1,readq,uVar1);
  uVar2 = *param_1;
  DataMemoryBarrier(0,1);
  log_post_read_mmio(uVar2,0x40,param_1,0x105680,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writeq_relaxed @ 001056b4 size=124
// signature: undefined writeq_relaxed(void)
// callers: [coresight_relaxed_write64]
//------------------------------------------------------------

void writeq_relaxed(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq_relaxed,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x105700,uVar1);
  return;
}



//------------------------------------------------------------
// writeq @ 00105730 size=128
// signature: undefined writeq(void)
// callers: [coresight_write64]
//------------------------------------------------------------

void writeq(undefined8 param_1,undefined8 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x40,param_2,writeq,uVar1);
  DataMemoryBarrier(0,2);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x40,param_2,0x105780,uVar1);
  return;
}



//------------------------------------------------------------
// enable_sink_show @ 001057b4 size=56
// signature: undefined enable_sink_show(void)
// callers: []
//------------------------------------------------------------

long enable_sink_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010ae29,*(undefined1 *)(param_1 + 0x39a));
  return (long)iVar1;
}



//------------------------------------------------------------
// enable_sink_store @ 001057f0 size=272
// signature: undefined enable_sink_store(void)
// callers: []
//------------------------------------------------------------

long enable_sink_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int iVar1;
  long lVar2;
  long local_38;
  undefined1 local_2c [4];
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  local_38 = 0;
  iVar1 = kstrtoull(param_3,10,&local_38);
  if (iVar1 == 0) {
    lVar2 = sp_el0;
    _dev_err(param_1,"[%s][%d][%s] val = %d\n",lVar2 + 0x848,*(undefined4 *)(lVar2 + 0x630),
             "enable_sink_store",local_38);
    if (local_38 == 0) {
      *(undefined1 *)(param_1 + 0x39a) = 0;
    }
    else {
      local_2c[0] = 0;
      lVar2 = bus_find_device(&coresight_bustype,0,local_2c,coresight_enabled_sink);
      if (((lVar2 == 0) || (lVar2 == 0x38)) ||
         (*(int *)(lVar2 + -0x30) == *(int *)(param_1 + -0x30))) {
        *(undefined1 *)(param_1 + 0x39a) = 1;
      }
      else {
        _dev_err(param_1,"Another type sink is enabled.\n");
        param_4 = -0x16;
      }
    }
  }
  else {
    param_4 = (long)iVar1;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// coresight_enabled_sink @ 00105904 size=64
// signature: undefined coresight_enabled_sink(void)
// callers: []
//------------------------------------------------------------

undefined1 coresight_enabled_sink(long param_1,char *param_2)

{
  undefined1 uVar1;
  
  if ((*(uint *)(param_1 + -0x30) | 2) != 2) {
    return 0;
  }
  uVar1 = 0;
  if (*(char *)(param_1 + 0x39a) != '\0') {
    if (*param_2 == '\0') {
      return 1;
    }
    uVar1 = 1;
    *(undefined1 *)(param_1 + 0x39a) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// enable_source_show @ 00105948 size=56
// signature: undefined enable_source_show(void)
// callers: []
//------------------------------------------------------------

long enable_source_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,&DAT_0010ae29,*(undefined1 *)(param_1 + 0x399));
  return (long)iVar1;
}



//------------------------------------------------------------
// enable_source_store @ 00105984 size=240
// signature: undefined enable_source_store(void)
// callers: []
//------------------------------------------------------------

long enable_source_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  iVar2 = kstrtoull(param_3,10,&local_40);
  if (iVar2 == 0) {
    lVar1 = sp_el0;
    _dev_err(param_1,"[%s][%d][%s] val = %d\n",lVar1 + 0x848,*(undefined4 *)(lVar1 + 0x630),
             "enable_source_store",local_40);
    if (local_40 == 0) {
      mutex_lock(&coresight_mutex);
      __coresight_disable(param_1 + -0x38);
      mutex_unlock(&coresight_mutex);
    }
    else {
      iVar2 = coresight_enable(param_1 + -0x38);
      if (iVar2 != 0) {
        param_4 = (long)iVar2;
      }
    }
  }
  else {
    param_4 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// sink_name_show @ 00105a78 size=100
// signature: undefined sink_name_show(void)
// callers: []
//------------------------------------------------------------

long sink_name_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x3a8);
  if (lVar3 == 0) {
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010b12b);
  }
  else {
    lVar2 = *(long *)(lVar3 + 0xa8);
    if (lVar2 == 0) {
      lVar2 = *(long *)(lVar3 + 0x38);
    }
    iVar1 = scnprintf(param_3,0x1000,&DAT_0010b0b8,lVar2);
  }
  return (long)iVar1;
}



//------------------------------------------------------------
// sink_name_store @ 00105ae0 size=316
// signature: undefined sink_name_store(void)
// callers: []
//------------------------------------------------------------

ulong sink_name_store(long param_1,undefined8 param_2,char *param_3,ulong param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  uint local_5c;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  undefined1 local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_40 = 0;
  local_50 = 0;
  uStack_48 = 0;
  local_58 = 0;
  if (param_4 < 0x19) {
    if (param_4 == 0) {
      *(undefined8 *)(param_1 + 0x3a8) = 0;
      goto LAB_00105be8;
    }
    iVar2 = sscanf(param_3,"%s",&local_58);
    if (iVar2 == 1) {
      local_5c = hashlen_string(0,&local_58);
      lVar3 = bus_find_device(&coresight_bustype,0,&local_5c,coresight_sink_by_id);
      local_5c = local_5c & 0xffffff00;
      lVar4 = bus_find_device(&coresight_bustype,0,&local_5c,coresight_enabled_sink);
      lVar1 = 0;
      if (lVar4 != 0) {
        lVar1 = lVar4 + -0x38;
      }
      if (((lVar3 != 0) && (lVar3 + -0x38 != 0)) &&
         ((lVar1 == 0 || (*(int *)(lVar1 + 8) == *(int *)(lVar3 + -0x30))))) {
        *(long *)(param_1 + 0x3a8) = lVar3 + -0x38;
        goto LAB_00105be8;
      }
      _dev_err(param_1,"Sink name [%s] is invalid or another type sink is enabled.\n",&local_58);
    }
  }
  param_4 = 0xffffffffffffffea;
LAB_00105be8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// coresight_orphan_match @ 00105c20 size=216
// signature: undefined coresight_orphan_match(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_orphan_match(long param_1,long *param_2)

{
  long lVar1;
  undefined8 uVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  undefined1 uVar6;
  long lVar7;
  
  plVar4 = (long *)(param_1 + -0x38);
  if ((plVar4 != param_2) && (*(char *)(param_1 + 0x398) != '\0')) {
    lVar3 = *plVar4;
    if (*(int *)(lVar3 + 4) < 1) {
      uVar6 = 0;
    }
    else {
      lVar5 = 0;
      lVar7 = 0;
      uVar6 = 0;
      do {
        lVar1 = *(long *)(lVar3 + 8) + lVar5;
        if ((*(long *)(lVar1 + 0x10) != 0) && (*(long *)(lVar1 + 0x18) == 0)) {
          if (*(long *)(lVar1 + 0x10) == param_2[0x65]) {
            uVar2 = coresight_make_links(plVar4,lVar1,param_2);
            if ((int)uVar2 != 0) {
              return uVar2;
            }
            lVar3 = *plVar4;
          }
          else {
            uVar6 = 1;
          }
        }
        lVar7 = lVar7 + 1;
        lVar5 = lVar5 + 0x30;
      } while (lVar7 < *(int *)(lVar3 + 4));
    }
    *(undefined1 *)(param_1 + 0x398) = uVar6;
  }
  return 0;
}



//------------------------------------------------------------
// coresight_remove_match @ 00105cfc size=136
// signature: undefined coresight_remove_match(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_remove_match(long param_1,long *param_2)

{
  uint uVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  
  plVar2 = (long *)(param_1 + -0x38);
  if (plVar2 != param_2) {
    uVar1 = *(uint *)(*plVar2 + 4);
    uVar3 = (ulong)uVar1;
    if (0 < (int)uVar1) {
      lVar4 = *(long *)(*plVar2 + 8);
      do {
        if (((*(long *)(lVar4 + 0x18) != 0) && (*(long *)(lVar4 + 0x10) != 0)) &&
           (param_2[0x65] == *(long *)(lVar4 + 0x10))) {
          *(undefined1 *)(param_1 + 0x398) = 1;
          coresight_remove_links(plVar2,lVar4);
          *(undefined8 *)(lVar4 + 0x18) = 0;
          return 0;
        }
        lVar4 = lVar4 + 0x30;
        uVar3 = uVar3 - 1;
      } while (uVar3 != 0);
    }
  }
  return 0;
}



//------------------------------------------------------------
// coresight_remove_sink_ref @ 00105d88 size=32
// signature: undefined coresight_remove_sink_ref(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_remove_sink_ref(long param_1,long param_2)

{
  if (*(long *)(param_1 + 0x3a8) == param_2) {
    *(undefined8 *)(param_1 + 0x3a8) = 0;
    return 0;
  }
  return 0;
}



//------------------------------------------------------------
// reset_source_sink_store @ 00105dac size=260
// signature: undefined reset_source_sink_store(void)
// callers: []
//------------------------------------------------------------

long reset_source_sink_store(undefined8 param_1,undefined8 param_2,long param_3)

{
  undefined **ppuVar1;
  int iVar2;
  long lVar3;
  undefined **ppuVar4;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  iVar2 = kstrtoull(param_2,10,&local_40);
  if (iVar2 == 0) {
    mutex_lock(&coresight_mutex);
    ppuVar4 = (undefined **)cs_active_paths;
    if ((undefined **)cs_active_paths != &cs_active_paths) {
      do {
        ppuVar1 = (undefined **)*ppuVar4;
        if (((long *)ppuVar4[-1] != (long *)0x0) &&
           (lVar3 = *(long *)(*(long *)ppuVar4[-1] + -8), *(int *)(lVar3 + 8) == 3 && lVar3 != 0)) {
          **(undefined4 **)(lVar3 + 0x3c8) = 1;
          __coresight_disable();
        }
        ppuVar4 = ppuVar1;
      } while (ppuVar1 != &cs_active_paths);
    }
    bus_for_each_dev(&coresight_bustype,0,0,coresight_reset_sink);
    mutex_unlock(&coresight_mutex);
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// coresight_reset_sink @ 00105eb4 size=36
// signature: undefined coresight_reset_sink(void)
// callers: []
//------------------------------------------------------------

undefined8 coresight_reset_sink(long param_1)

{
  if (((*(uint *)(param_1 + -0x30) | 2) == 2) && (*(char *)(param_1 + 0x39a) != '\0')) {
    *(undefined1 *)(param_1 + 0x39a) = 0;
  }
  return 0;
}



//------------------------------------------------------------
// etm_perf_symlink @ 00105eec size=288
// signature: undefined etm_perf_symlink(void)
// callers: []
//------------------------------------------------------------

void etm_perf_symlink(long param_1,ulong param_2)

{
  long lVar1;
  uint param2;
  undefined8 uVar2;
  code *pcVar3;
  char local_48 [16];
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  local_48[0] = '\0';
  local_48[1] = '\0';
  local_48[2] = '\0';
  local_48[3] = '\0';
  local_48[4] = '\0';
  local_48[5] = '\0';
  local_48[6] = '\0';
  local_48[7] = '\0';
  local_48[8] = '\0';
  local_48[9] = '\0';
  local_48[10] = '\0';
  pcVar3 = (code *)**(undefined8 **)(*(long *)(param_1 + 0x18) + 0x10);
  if (*(int *)(pcVar3 + -4) != -0x616f8f75) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x105f44);
    (*pcVar3)();
  }
  param2 = (*pcVar3)();
  uVar2 = DAT_0010b308;
  sprintf(local_48,"cpu%d",param2);
  if (etm_perf_up == '\x01') {
    if ((param_2 & 1) == 0) {
      sysfs_remove_link(uVar2,local_48);
      if (0x1f < param2) {
LAB_00106008:
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x10600c);
        (*pcVar3)();
      }
      param_1 = 0;
    }
    else {
      uVar2 = sysfs_create_link(uVar2,param_1 + 0x38,local_48);
      if ((int)uVar2 != 0) goto LAB_00105fd8;
      if (0x1f < param2) goto LAB_00106008;
    }
    uVar2 = 0;
    *(long *)(&csdev_src + *(long *)(&__per_cpu_offset + (ulong)param2 * 8)) = param_1;
  }
  else {
    uVar2 = 0xfffffdfb;
  }
LAB_00105fd8:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar2);
  }
  return;
}



//------------------------------------------------------------
// etm_perf_add_symlink_sink @ 00106010 size=296
// signature: undefined etm_perf_add_symlink_sink(void)
// callers: [coresight_register]
//------------------------------------------------------------

long * etm_perf_add_symlink_sink(long param_1)

{
  undefined8 uVar1;
  int iVar2;
  long *plVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  
  uVar1 = DAT_0010b308;
  if (((*(uint *)(param_1 + 8) | 2) == 2) && (*(long *)(param_1 + 0x3d8) == 0)) {
    lVar6 = *(long *)(param_1 + 0xa8);
    plVar3 = (long *)(param_1 + 0x38);
    if (lVar6 == 0) {
      lVar6 = *plVar3;
    }
    if (etm_perf_up == '\x01') {
      plVar4 = (long *)devm_kmalloc(plVar3,0x28,0xdc0);
      if (plVar4 != (long *)0x0) {
        uVar5 = hashlen_string(0,lVar6);
        lVar6 = devm_kstrdup(plVar3,lVar6,0xcc0);
        *plVar4 = lVar6;
        if (lVar6 != 0) {
          *(undefined2 *)(plVar4 + 1) = 0x124;
          plVar4[4] = uVar5 & 0xffffffff;
          iVar2 = sysfs_add_file_to_group(uVar1,plVar4,"sinks");
          if (iVar2 != 0) {
            plVar4 = (long *)(long)iVar2;
          }
          *(long **)(param_1 + 0x3d8) = plVar4;
          if (plVar4 < (long *)0xfffffffffffff001) {
            plVar4[2] = (long)etm_perf_sink_name_show;
            return (long *)0x0;
          }
          *(undefined8 *)(param_1 + 0x3d8) = 0;
          return plVar4;
        }
      }
      plVar3 = (long *)0xfffffffffffffff4;
      *(undefined8 *)(param_1 + 0x3d8) = 0;
    }
    else {
      plVar3 = (long *)0xfffffffffffffdfb;
      *(undefined8 *)(param_1 + 0x3d8) = 0;
    }
  }
  else {
    plVar3 = (long *)0xffffffea;
  }
  return plVar3;
}



//------------------------------------------------------------
// etm_perf_sink_name_show @ 0010613c size=52
// signature: undefined etm_perf_sink_name_show(void)
// callers: []
//------------------------------------------------------------

long etm_perf_sink_name_show(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"0x%lx\n",*(undefined8 *)(param_2 + 0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// etm_perf_del_symlink_sink @ 00106174 size=84
// signature: undefined etm_perf_del_symlink_sink(void)
// callers: [coresight_unregister]
//------------------------------------------------------------

void etm_perf_del_symlink_sink(long param_1)

{
  if (((*(uint *)(param_1 + 8) | 2) == 2) && (*(long *)(param_1 + 0x3d8) != 0)) {
    sysfs_remove_file_from_group(DAT_0010b308,*(long *)(param_1 + 0x3d8),"sinks");
    *(undefined8 *)(param_1 + 0x3d8) = 0;
  }
  return;
}



//------------------------------------------------------------
// etm_perf_add_symlink_cscfg @ 001061cc size=252
// signature: undefined etm_perf_add_symlink_cscfg(void)
// callers: [cscfg_load_config_sets]
//------------------------------------------------------------

long * etm_perf_add_symlink_cscfg(undefined8 param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  int iVar2;
  long *plVar3;
  ulong uVar4;
  long lVar5;
  undefined8 uVar6;
  
  uVar1 = DAT_0010b308;
  if (param_2[8] != 0) {
    return (long *)0x0;
  }
  if (etm_perf_up == '\x01') {
    uVar6 = *param_2;
    plVar3 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
    if (plVar3 != (long *)0x0) {
      uVar4 = hashlen_string(0,uVar6);
      lVar5 = devm_kstrdup(param_1,uVar6,0xcc0);
      *plVar3 = lVar5;
      if (lVar5 != 0) {
        *(undefined2 *)(plVar3 + 1) = 0x124;
        plVar3[4] = uVar4 & 0xffffffff;
        iVar2 = sysfs_add_file_to_group(uVar1,plVar3,"events");
        if (iVar2 != 0) {
          plVar3 = (long *)(long)iVar2;
        }
        param_2[8] = plVar3;
        if (plVar3 < (long *)0xfffffffffffff001) {
          plVar3[2] = (long)etm_perf_cscfg_event_show;
          return (long *)0x0;
        }
        goto LAB_001062ac;
      }
    }
    plVar3 = (long *)0xfffffffffffffff4;
  }
  else {
    plVar3 = (long *)0xfffffffffffffdfb;
  }
LAB_001062ac:
  param_2[8] = 0;
  return plVar3;
}



//------------------------------------------------------------
// etm_perf_cscfg_event_show @ 001062cc size=52
// signature: undefined etm_perf_cscfg_event_show(void)
// callers: []
//------------------------------------------------------------

long etm_perf_cscfg_event_show(undefined8 param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = scnprintf(param_3,0x1000,"configid=0x%lx\n",*(undefined8 *)(param_2 + 0x20));
  return (long)iVar1;
}



//------------------------------------------------------------
// etm_perf_del_symlink_cscfg @ 00106304 size=68
// signature: undefined etm_perf_del_symlink_cscfg(void)
// callers: [cscfg_unload_owned_cfgs_feats]
//------------------------------------------------------------

void etm_perf_del_symlink_cscfg(long param_1)

{
  if (*(long *)(param_1 + 0x40) != 0) {
    sysfs_remove_file_from_group(DAT_0010b308,*(long *)(param_1 + 0x40),"events");
    *(undefined8 *)(param_1 + 0x40) = 0;
  }
  return;
}



//------------------------------------------------------------
// etm_event_read @ 0010634c size=4
// signature: undefined etm_event_read(void)
// callers: []
//------------------------------------------------------------

void etm_event_read(void)

{
  return;
}



//------------------------------------------------------------
// etm_event_init @ 00106354 size=156
// signature: undefined etm_event_init(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 etm_event_init(long param_1)

{
  void *__dest;
  undefined8 uVar1;
  
  if (*(int *)(param_1 + 0xd8) == DAT_0010b328) {
    __dest = (void *)kmalloc_node_trace(_bus_for_each_dev,0xdc0,
                                        -(uint)(*(int *)(param_1 + 0x28c) == -1),200);
    if (__dest == (void *)0x0) {
      uVar1 = 0xfffffff4;
    }
    else {
      if (*(long *)(param_1 + 0x280) != 0) {
        memcpy(__dest,*(void **)(*(long *)(param_1 + 0x280) + 0x1c8),200);
      }
      uVar1 = 0;
      *(void **)(param_1 + 0x1c8) = __dest;
      *(code **)(param_1 + 0x3a8) = etm_event_destroy;
    }
  }
  else {
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}



//------------------------------------------------------------
// etm_setup_aux @ 001063f4 size=904
// signature: undefined etm_setup_aux(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * etm_setup_aux(long param_1,undefined8 param_2,undefined4 param_3,uint param_4)

{
  undefined8 *__dest;
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined8 *puVar7;
  long lVar8;
  long lVar9;
  ulong uVar10;
  long lVar11;
  ulong extraout_x8;
  ulong uVar12;
  ulong extraout_x9;
  long local_68;
  
  uVar6 = *(uint *)(param_1 + 0x28c);
  puVar7 = (undefined8 *)kmalloc_trace(__printk,0xdc0,0x50);
  if (puVar7 == (undefined8 *)0x0) {
    return (undefined8 *)0x0;
  }
  __dest = puVar7 + 6;
  if (uVar6 == 0xffffffff) {
    uVar6 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
    if (0x20 < uVar6) {
      fortify_panic("memcpy");
      uVar10 = extraout_x8;
      uVar12 = extraout_x9;
      goto LAB_001067b0;
    }
    memcpy(__dest,&__cpu_present_mask,(ulong)uVar6);
  }
  else {
    uVar12 = (ulong)(uVar6 >> 6);
    uVar10 = 1L << ((ulong)uVar6 & 0x3f);
LAB_001067b0:
    puVar1 = __dest + uVar12;
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | uVar10;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  lVar8 = __alloc_percpu(8,8);
  puVar7[9] = lVar8;
  if (lVar8 == 0) {
    kfree(puVar7);
    return (undefined8 *)0x0;
  }
  *puVar7 = 0xfffffffe0;
  puVar7[1] = puVar7 + 1;
  puVar7[2] = puVar7 + 1;
  uVar10 = *(ulong *)(param_1 + 0x118);
  puVar7[3] = free_event_data;
  if ((int)uVar10 == 0) {
    lVar8 = 0;
    iVar5 = (int)(uVar10 >> 0x20);
  }
  else {
    lVar8 = coresight_get_sink_by_id();
    uVar10 = *(ulong *)(param_1 + 0x118);
    iVar5 = (int)(uVar10 >> 0x20);
  }
  if (iVar5 != 0) {
    iVar5 = cscfg_activate_config(uVar10 >> 0x20);
    if (iVar5 != 0) goto LAB_00106760;
    *(int *)(puVar7 + 8) = (int)(uVar10 >> 0x20);
  }
  lVar11 = 0;
  local_68 = 0;
  lVar9 = lVar8;
  while( true ) {
    uVar10 = _find_next_bit(__dest,_nr_cpu_ids,(long)(int)lVar11);
    if (_nr_cpu_ids <= (uint)uVar10) break;
    if ((uVar10 & 0xffffffe0) != 0) goto LAB_001067a0;
    lVar11 = *(long *)(&csdev_src + *(long *)(&__per_cpu_offset + (uVar10 & 0xffffffff) * 8));
    if (lVar11 == 0) {
      puVar1 = __dest + (uVar10 >> 6 & 0x3ffffff);
      Hint_Prefetch(puVar1,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
        if (bVar3) {
          *puVar1 = *puVar1 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      lVar11 = uVar10 + 1;
    }
    else if (lVar8 == 0) {
      lVar9 = coresight_find_default_sink(lVar11);
      if (lVar9 == 0) {
        puVar1 = __dest + (uVar10 >> 6 & 0x3ffffff);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar9 = 0;
        lVar11 = uVar10 + 1;
      }
      else {
        if ((local_68 == 0) ||
           ((*(int *)(local_68 + 0xc) == *(int *)(lVar9 + 0xc) &&
            (**(long **)(local_68 + 0x18) == **(long **)(lVar9 + 0x18))))) {
          local_68 = lVar9;
          goto LAB_00106584;
        }
        puVar1 = __dest + (uVar10 >> 6 & 0x3ffffff);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar11 = uVar10 + 1;
      }
    }
    else {
LAB_00106584:
      uVar12 = coresight_build_path(lVar11,lVar9);
      if (uVar12 < 0xfffffffffffff001) {
        if (0x1f < (uint)uVar10) {
LAB_001067a0:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1067a4);
          (*pcVar4)();
        }
        *(ulong *)(*(long *)(&__per_cpu_offset + (uVar10 & 0xffffffff) * 8) + puVar7[9]) = uVar12;
        lVar11 = uVar10 + 1;
      }
      else {
        puVar1 = __dest + (uVar10 >> 6 & 0x3ffffff);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 & (1L << (uVar10 & 0x3f) ^ 0xffffffffffffffffU);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
        lVar11 = uVar10 + 1;
      }
    }
  }
  if ((lVar9 != 0) && (uVar6 = _find_first_bit(__dest), uVar6 < _nr_cpu_ids)) {
    pcVar4 = *(code **)(**(long **)(lVar9 + 0x18) + 0x10);
    if ((pcVar4 != (code *)0x0) && (*(long *)(**(long **)(lVar9 + 0x18) + 0x18) != 0)) {
      if (*(int *)(pcVar4 + -4) != 0x359ebf17) {
                    /* WARNING: Does not return */
        pcVar4 = (code *)SoftwareBreakpoint(0x8228,0x106754);
        (*pcVar4)();
      }
      lVar8 = (*pcVar4)(lVar9,param_1,param_2,param_3,param_4 & 1);
      puVar7[7] = lVar8;
      if (lVar8 != 0) {
        return puVar7;
      }
    }
  }
LAB_00106760:
  queue_work_on(0x20,_system_wq,puVar7);
  return (undefined8 *)0x0;
}



//------------------------------------------------------------
// etm_free_aux @ 001067d0 size=44
// signature: undefined etm_free_aux(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void etm_free_aux(undefined8 param_1)

{
  queue_work_on(0x20,_system_wq,param_1);
  return;
}



//------------------------------------------------------------
// etm_event_start @ 00106800 size=340
// signature: undefined etm_event_start(void)
// callers: [etm_event_add]
//------------------------------------------------------------

void etm_event_start(long param_1)

{
  long *plVar1;
  uint uVar2;
  long lVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  code *pcVar7;
  long lVar8;
  ulong uVar9;
  undefined8 uVar10;
  
  lVar3 = tpidr_el1;
  uVar2 = *(uint *)(&cpu_number + lVar3);
  uVar9 = (ulong)uVar2;
  if (0x1f < uVar2) {
                    /* WARNING: Does not return */
    pcVar7 = (code *)SoftwareBreakpoint(0x5512,0x106964);
    (*pcVar7)();
  }
  lVar8 = *(long *)(&csdev_src + *(long *)(&__per_cpu_offset + uVar9 * 8));
  if (lVar8 != 0) {
    plVar1 = (long *)(etm_ctxt + lVar3);
    if (*(long *)(etm_ctxt + lVar3 + 0x38) != 0) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x800,0x10694c);
      (*pcVar7)();
    }
    lVar5 = perf_aux_output_begin(plVar1,param_1);
    if (lVar5 != 0) {
      if ((*(ulong *)(lVar5 + ((ulong)(uVar2 >> 3) & 0x1ffffff8) + 0x30) >> (uVar9 & 0x3f) & 1) == 0
         ) {
LAB_0010693c:
        *(undefined4 *)(param_1 + 0x1d8) = 0;
        *(long *)(etm_ctxt + lVar3 + 0x38) = lVar5;
        return;
      }
      uVar10 = *(undefined8 *)(*(long *)(&__per_cpu_offset + uVar9 * 8) + *(long *)(lVar5 + 0x48));
      lVar6 = coresight_get_sink(uVar10);
      if (lVar6 == 0) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x800,0x106954);
        (*pcVar7)();
      }
      iVar4 = coresight_enable_path(uVar10,2,plVar1);
      if (iVar4 == 0) {
        pcVar7 = *(code **)(*(long *)(*(long *)(lVar8 + 0x18) + 0x10) + 0x10);
        if (*(int *)(pcVar7 + -4) != 0x189af055) {
                    /* WARNING: Does not return */
          pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x1068ec);
          (*pcVar7)();
        }
        iVar4 = (*pcVar7)(lVar8,param_1,2);
        if (iVar4 == 0) goto LAB_0010693c;
        coresight_disable_path(uVar10);
      }
      if (*plVar1 != 0) {
        perf_aux_output_flag(plVar1,1);
        perf_aux_output_end(plVar1,0);
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1d8) = 1;
  return;
}



//------------------------------------------------------------
// etm_event_stop @ 00106968 size=464
// signature: undefined etm_event_stop(void)
// callers: [etm_event_del]
//------------------------------------------------------------

void etm_event_stop(long param_1,uint param_2)

{
  long *plVar1;
  uint uVar2;
  code *pcVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  ulong uVar7;
  long lVar8;
  
  lVar8 = tpidr_el1;
  uVar2 = *(uint *)(&cpu_number + lVar8);
  uVar7 = (ulong)uVar2;
  if (0x1f < uVar2) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x106b48);
    (*pcVar3)();
  }
  plVar1 = (long *)(etm_ctxt + lVar8);
  lVar6 = *(long *)(&csdev_src + *(long *)(&__per_cpu_offset + uVar7 * 8));
  if (*plVar1 == 0) {
    lVar4 = *(long *)(etm_ctxt + lVar8 + 0x38);
  }
  else {
    lVar4 = perf_get_aux(plVar1);
    if (lVar4 != *(long *)(etm_ctxt + lVar8 + 0x38)) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x1069ec);
      (*pcVar3)();
    }
  }
  *(undefined8 *)(etm_ctxt + lVar8 + 0x38) = 0;
  if (*(int *)(param_1 + 0x1d8) != 1) {
    if (lVar4 == 0) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106b30);
      (*pcVar3)();
    }
    if ((((param_2 >> 2 & 1) == 0) || (*plVar1 == 0)) ||
       ((*(ulong *)(lVar4 + ((ulong)(uVar2 >> 3) & 0x1ffffff8) + 0x30) >> (uVar7 & 0x3f) & 1) != 0))
    {
      if (((lVar6 != 0) &&
          (lVar8 = *(long *)(*(long *)(&__per_cpu_offset + uVar7 * 8) + *(long *)(lVar4 + 0x48)),
          lVar8 != 0)) && (lVar5 = coresight_get_sink(lVar8), lVar5 != 0)) {
        pcVar3 = *(code **)(*(long *)(*(long *)(lVar6 + 0x18) + 0x10) + 0x18);
        if (*(int *)(pcVar3 + -4) != -0x75220976) {
                    /* WARNING: Does not return */
          pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106a7c);
          (*pcVar3)();
        }
        (*pcVar3)(lVar6,param_1);
        *(undefined4 *)(param_1 + 0x1d8) = 1;
        if (((param_2 >> 2 & 1) != 0) && (*plVar1 != 0)) {
          if (*plVar1 != param_1) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106b38);
            (*pcVar3)();
          }
          pcVar3 = *(code **)(**(long **)(lVar5 + 0x18) + 0x20);
          if (pcVar3 == (code *)0x0) {
            return;
          }
          if (*(int *)(pcVar3 + -4) != 0x4c869461) {
                    /* WARNING: Does not return */
            pcVar3 = (code *)SoftwareBreakpoint(0x8228,0x106ad0);
            (*pcVar3)();
          }
          lVar6 = (*pcVar3)(lVar5,plVar1,*(undefined8 *)(lVar4 + 0x38));
          if (*plVar1 == 0) {
            if (lVar6 != 0) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x800,0x106b40);
              (*pcVar3)();
            }
          }
          else {
            perf_aux_output_end(plVar1);
          }
        }
        coresight_disable_path(lVar8);
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x1d8) = 1;
      perf_aux_output_end(plVar1,0);
    }
  }
  return;
}



//------------------------------------------------------------
// etm_event_add @ 00106b4c size=80
// signature: undefined etm_event_add(void)
// callers: []
//------------------------------------------------------------

uint etm_event_add(long param_1,uint param_2)

{
  uint uVar1;
  
  if ((param_2 & 1) == 0) {
    uVar1 = 0;
    *(undefined4 *)(param_1 + 0x1d8) = 1;
  }
  else {
    etm_event_start(param_1);
    uVar1 = -(*(byte *)(param_1 + 0x1d8) & 1) & 0xffffffea;
  }
  return uVar1;
}



//------------------------------------------------------------
// etm_event_del @ 00106ba0 size=32
// signature: undefined etm_event_del(void)
// callers: []
//------------------------------------------------------------

void etm_event_del(undefined8 param_1)

{
  etm_event_stop(param_1,4);
  return;
}



//------------------------------------------------------------
// etm_addr_filters_sync @ 00106bc4 size=172
// signature: undefined etm_addr_filters_sync(void)
// callers: []
//------------------------------------------------------------

void etm_addr_filters_sync(long param_1)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  code *pcVar5;
  long lVar6;
  long *plVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  undefined4 uVar11;
  
  lVar1 = param_1;
  if (*(long *)(param_1 + 0x280) != 0) {
    lVar1 = *(long *)(param_1 + 0x280);
  }
  plVar7 = *(long **)(lVar1 + 0x378);
  lVar6 = *(long *)(param_1 + 0x1c8);
  if (plVar7 == (long *)(lVar1 + 0x378)) {
    *(undefined4 *)(lVar6 + 0xc0) = 0;
    return;
  }
  lVar8 = 0;
  plVar9 = (long *)(lVar6 + 8);
  plVar10 = (long *)(*(long *)(param_1 + 0x390) + 8);
  do {
    if (lVar8 == -9) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x106c70);
      (*pcVar5)();
    }
    lVar2 = plVar10[-1];
    lVar3 = *plVar10;
    iVar4 = (int)plVar7[6];
    if (iVar4 == 0) {
      uVar11 = 4;
LAB_00106bfc:
      *plVar9 = lVar3 + lVar2;
LAB_00106c00:
      *(undefined4 *)(plVar9 + 1) = uVar11;
    }
    else {
      if (iVar4 == 1) {
        uVar11 = 3;
        plVar9[-1] = lVar2;
        goto LAB_00106c00;
      }
      if (iVar4 == 2) {
        plVar9[-1] = lVar2;
        uVar11 = 2;
        goto LAB_00106bfc;
      }
    }
    plVar7 = (long *)*plVar7;
    plVar9 = plVar9 + 3;
    lVar8 = lVar8 + -1;
    plVar10 = plVar10 + 2;
    if (plVar7 == (long *)(lVar1 + 0x378)) {
      *(int *)(lVar6 + 0xc0) = -(int)lVar8;
      return;
    }
  } while( true );
}



//------------------------------------------------------------
// etm_addr_filters_validate @ 00106c74 size=456
// signature: undefined etm_addr_filters_validate(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Removing unreachable block (ram,0x00106ccc) */

undefined4 etm_addr_filters_validate(long *param_1)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  long *plVar5;
  long lVar6;
  
  plVar5 = (long *)*param_1;
  if (plVar5 == param_1) {
    return 0;
  }
  lVar6 = plVar5[5];
  if ((lVar6 != 0) && (*(uint *)(plVar5 + 6) < 2)) {
    return 0xffffffa1;
  }
  plVar5 = (long *)*plVar5;
  if (plVar5 == param_1) {
    return 0;
  }
  bVar3 = lVar6 != 0;
  if (plVar5[5] == 0) {
    bVar1 = true;
    bVar2 = bVar1;
    if (!bVar3) goto LAB_00106ce4;
  }
  else {
    if (*(uint *)(plVar5 + 6) < 2) {
      return 0xffffffa1;
    }
    bVar3 = true;
    bVar2 = lVar6 == 0;
  }
  bVar1 = false;
  if (bVar2) {
    return 0xffffffa1;
  }
LAB_00106ce4:
  plVar5 = (long *)*plVar5;
  if (plVar5 != param_1) {
    if (plVar5[5] == 0) {
      bVar1 = true;
    }
    else {
      if (*(uint *)(plVar5 + 6) < 2) {
        return 0xffffffa1;
      }
      bVar3 = true;
    }
    if ((bVar3) && (bVar1)) {
      return 0xffffffa1;
    }
    plVar5 = (long *)*plVar5;
    if (plVar5 != param_1) {
      if (plVar5[5] == 0) {
        bVar1 = true;
      }
      else {
        if (*(uint *)(plVar5 + 6) < 2) {
          return 0xffffffa1;
        }
        bVar3 = true;
      }
      if ((bVar3) && (bVar1)) {
        return 0xffffffa1;
      }
      plVar5 = (long *)*plVar5;
      if (plVar5 != param_1) {
        if (plVar5[5] == 0) {
          bVar1 = true;
        }
        else {
          if (*(uint *)(plVar5 + 6) < 2) {
            return 0xffffffa1;
          }
          bVar3 = true;
        }
        if ((bVar3) && (bVar1)) {
          return 0xffffffa1;
        }
        plVar5 = (long *)*plVar5;
        if (plVar5 != param_1) {
          if (plVar5[5] == 0) {
            bVar1 = true;
          }
          else {
            if (*(uint *)(plVar5 + 6) < 2) {
              return 0xffffffa1;
            }
            bVar3 = true;
          }
          if ((bVar3) && (bVar1)) {
            return 0xffffffa1;
          }
          plVar5 = (long *)*plVar5;
          if (plVar5 != param_1) {
            if (plVar5[5] == 0) {
              bVar1 = true;
            }
            else {
              if (*(uint *)(plVar5 + 6) < 2) {
                return 0xffffffa1;
              }
              bVar3 = true;
            }
            if ((bVar3) && (bVar1)) {
              return 0xffffffa1;
            }
            plVar5 = (long *)*plVar5;
            if (plVar5 != param_1) {
              if (plVar5[5] == 0) {
                bVar1 = true;
              }
              else {
                if (*(uint *)(plVar5 + 6) < 2) {
                  return 0xffffffa1;
                }
                bVar3 = true;
              }
              uVar4 = 0xffffffa1;
              if (((!bVar3) || (!bVar1)) && (uVar4 = 0, (long *)*plVar5 != param_1)) {
                uVar4 = 0xffffffa1;
              }
              return uVar4;
            }
          }
        }
      }
    }
  }
  return 0;
}



//------------------------------------------------------------
// etm_perf_exit @ 00106e40 size=36
// signature: undefined etm_perf_exit(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

void etm_perf_exit(void)

{
  perf_pmu_unregister(&etm_pmu);
  return;
}



//------------------------------------------------------------
// cycacc_show @ 00106e68 size=36
// signature: undefined cycacc_show(void)
// callers: []
//------------------------------------------------------------

undefined8 cycacc_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_12_0010acf8._0_8_;
  param_3[7] = '1';
  param_3[8] = '2';
  param_3[9] = '\n';
  param_3[10] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 10;
}



//------------------------------------------------------------
// format_attr_contextid_show @ 00106e90 size=48
// signature: undefined format_attr_contextid_show(void)
// callers: []
//------------------------------------------------------------

long format_attr_contextid_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"config:%d\n",0xe);
  return (long)iVar1;
}



//------------------------------------------------------------
// contextid1_show @ 00106ec4 size=36
// signature: undefined contextid1_show(void)
// callers: []
//------------------------------------------------------------

undefined8 contextid1_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_14_0010b2b2._0_8_;
  param_3[7] = '1';
  param_3[8] = '4';
  param_3[9] = '\n';
  param_3[10] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 10;
}



//------------------------------------------------------------
// contextid2_show @ 00106eec size=36
// signature: undefined contextid2_show(void)
// callers: []
//------------------------------------------------------------

undefined8 contextid2_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_15_0010b2bd._0_8_;
  param_3[7] = '1';
  param_3[8] = '5';
  param_3[9] = '\n';
  param_3[10] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 10;
}



//------------------------------------------------------------
// timestamp_show @ 00106f14 size=36
// signature: undefined timestamp_show(void)
// callers: []
//------------------------------------------------------------

undefined8 timestamp_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_28_0010b0da._0_8_;
  param_3[7] = '2';
  param_3[8] = '8';
  param_3[9] = '\n';
  param_3[10] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 10;
}



//------------------------------------------------------------
// retstack_show @ 00106f3c size=36
// signature: undefined retstack_show(void)
// callers: []
//------------------------------------------------------------

undefined8 retstack_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_29_0010ae52._0_8_;
  param_3[7] = '2';
  param_3[8] = '9';
  param_3[9] = '\n';
  param_3[10] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 10;
}



//------------------------------------------------------------
// sinkid_show @ 00106f64 size=32
// signature: undefined sinkid_show(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 sinkid_show(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = CONCAT62(s_2_0_31_0010b2ce._2_6_,s_2_0_31_0010b2ce._0_2_);
  *param_3 = CONCAT26(s_2_0_31_0010b2ce._0_2_,_DAT_0010b2c8);
  *(undefined8 *)((long)param_3 + 6) = uVar1;
  return 0xd;
}



//------------------------------------------------------------
// preset_show @ 00106f88 size=36
// signature: undefined preset_show(void)
// callers: []
//------------------------------------------------------------

undefined8 preset_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_0_3_0010ae71._0_8_;
  param_3[8] = '-';
  param_3[9] = '3';
  param_3[10] = '\n';
  param_3[0xb] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 0xb;
}



//------------------------------------------------------------
// configid_show @ 00106fb0 size=32
// signature: undefined configid_show(void)
// callers: []
//------------------------------------------------------------

undefined8 configid_show(undefined8 param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = CONCAT71(s_config2_32_63_0010ad0e._8_7_,s_config2_32_63_0010ad0e[7]);
  *param_3 = CONCAT17(s_config2_32_63_0010ad0e[7],s_config2_32_63_0010ad0e._0_7_);
  *(undefined8 *)((long)param_3 + 7) = uVar1;
  return 0xe;
}



//------------------------------------------------------------
// branch_broadcast_show @ 00106fd4 size=32
// signature: undefined branch_broadcast_show(void)
// callers: []
//------------------------------------------------------------

undefined8 branch_broadcast_show(undefined8 param_1,undefined8 param_2,char *param_3)

{
  undefined8 uVar1;
  
  uVar1 = s_config_8_0010b0e5._0_8_;
  param_3[8] = '\n';
  param_3[9] = '\0';
  *(undefined8 *)param_3 = uVar1;
  return 9;
}



//------------------------------------------------------------
// etm_event_destroy @ 00106ff8 size=48
// signature: undefined etm_event_destroy(void)
// callers: []
//------------------------------------------------------------

void etm_event_destroy(long param_1)

{
  kfree(*(undefined8 *)(param_1 + 0x1c8));
  *(undefined8 *)(param_1 + 0x1c8) = 0;
  return;
}



//------------------------------------------------------------
// free_event_data @ 0010702c size=316
// signature: undefined free_event_data(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void free_event_data(long param_1)

{
  long lVar1;
  uint uVar2;
  ulong uVar3;
  long lVar4;
  int iVar5;
  code *pcVar6;
  ulong uVar7;
  long lVar8;
  
  lVar1 = param_1 + 0x30;
  if (*(long *)(param_1 + 0x38) != 0) {
    uVar7 = (ulong)_nr_cpu_ids;
    uVar3 = _find_first_bit(lVar1,uVar7);
    if (uVar3 == uVar7) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x800,0x107164);
      (*pcVar6)();
    }
    uVar3 = _find_first_bit(lVar1,_nr_cpu_ids);
    if ((uVar3 & 0xffffffe0) != 0) goto LAB_00107170;
    lVar4 = coresight_get_sink(*(undefined8 *)
                                (*(long *)(&__per_cpu_offset + (uVar3 & 0xffffffff) * 8) +
                                *(long *)(param_1 + 0x48)));
    pcVar6 = *(code **)(**(long **)(lVar4 + 0x18) + 0x18);
    if (*(int *)(pcVar6 + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
      pcVar6 = (code *)SoftwareBreakpoint(0x8229,0x1070cc);
      (*pcVar6)();
    }
    (*pcVar6)(*(undefined8 *)(param_1 + 0x38));
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    cscfg_deactivate_config();
  }
  iVar5 = 0;
  while( true ) {
    uVar2 = _find_next_bit(lVar1,_nr_cpu_ids,(long)iVar5);
    if (_nr_cpu_ids <= uVar2) {
      free_percpu(*(undefined8 *)(param_1 + 0x48));
      kfree(param_1);
      return;
    }
    if (0x1f < uVar2) break;
    lVar4 = *(long *)(param_1 + 0x48);
    lVar8 = *(long *)(&__per_cpu_offset + (ulong)uVar2 * 8);
    uVar3 = *(ulong *)(lVar8 + lVar4);
    if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
      coresight_release_path();
    }
    iVar5 = uVar2 + 1;
    *(undefined8 *)(lVar4 + lVar8) = 0;
  }
LAB_00107170:
                    /* WARNING: Does not return */
  pcVar6 = (code *)SoftwareBreakpoint(0x5512,0x107174);
  (*pcVar6)();
}



//------------------------------------------------------------
// coresight_find_csdev_by_fwnode @ 00107180 size=84
// signature: undefined coresight_find_csdev_by_fwnode(void)
// callers: [coresight_register]
//------------------------------------------------------------

long coresight_find_csdev_by_fwnode(undefined8 param_1)

{
  long lVar1;
  
  lVar1 = bus_find_device(&coresight_bustype,0,param_1,&device_match_fwnode);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = lVar1 + -0x38;
    put_device();
  }
  return lVar1;
}



//------------------------------------------------------------
// of_coresight_secure_node @ 001071d8 size=56
// signature: undefined of_coresight_secure_node(void)
// callers: [coresight_enable]
//------------------------------------------------------------

bool of_coresight_secure_node(long param_1)

{
  long lVar1;
  
  lVar1 = of_find_property(*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),
                           "qcom,secure-component",0);
  return lVar1 != 0;
}



//------------------------------------------------------------
// of_coresight_get_csr_atid_offset @ 00107214 size=64
// signature: undefined of_coresight_get_csr_atid_offset(void)
// callers: [coresight_set_csr_atid]
//------------------------------------------------------------

int of_coresight_get_csr_atid_offset(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),"csr-atid-offset",param_2,1,
                     0);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// of_coresight_get_atid_number @ 00107258 size=48
// signature: undefined of_coresight_get_atid_number(void)
// callers: [coresight_set_csr_atid]
//------------------------------------------------------------

void of_coresight_get_atid_number(long param_1)

{
  of_property_count_elems_of_size
            (*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),&DAT_0010ae90,4);
  return;
}



//------------------------------------------------------------
// of_coresight_get_atid @ 0010728c size=68
// signature: undefined of_coresight_get_atid(void)
// callers: [coresight_set_csr_atid]
//------------------------------------------------------------

int of_coresight_get_atid(long param_1,undefined8 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = of_property_read_variable_u32_array
                    (*(undefined8 *)(*(long *)(param_1 + 0x98) + 0x2e8),&DAT_0010ae90,param_2,
                     (long)param_3,0);
  if (-1 < iVar1) {
    iVar1 = 0;
  }
  return iVar1;
}



//------------------------------------------------------------
// coresight_get_cpu @ 001072d4 size=212
// signature: undefined coresight_get_cpu(void)
// callers: []
//------------------------------------------------------------

void coresight_get_cpu(long param_1)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  ulong uVar4;
  long local_68 [11];
  
  lVar1 = sp_el0;
  local_68[10] = *(long *)(lVar1 + 0x638);
  uVar4 = *(ulong *)(param_1 + 0x2f0);
  uVar3 = 0;
  if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
    if (*(undefined **)(uVar4 + 8) == &of_fwnode_ops) {
      if (*(long *)(param_1 + 0x2e8) == 0) {
        uVar3 = 0xffffffed;
      }
      else {
        local_68[8] = 0;
        local_68[9] = 0;
        local_68[6] = 0;
        local_68[7] = 0;
        local_68[4] = 0;
        local_68[5] = 0;
        local_68[2] = 0;
        local_68[3] = 0;
        local_68[0] = 0;
        local_68[1] = 0;
        iVar2 = __of_parse_phandle_with_args
                          (*(long *)(param_1 + 0x2e8),&DAT_0010b12d,0,0,0,local_68);
        uVar3 = 0xffffffed;
        if ((iVar2 == 0) && (local_68[0] != 0)) {
          uVar3 = of_cpu_node_to_id(local_68[0]);
        }
      }
    }
    else {
      uVar3 = 0;
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_68[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// coresight_get_platform_data @ 001073ac size=1240
// signature: undefined coresight_get_platform_data(void)
// callers: []
//------------------------------------------------------------

uint * coresight_get_platform_data(long param_1)

{
  uint uVar1;
  undefined1 auVar2 [16];
  int iVar3;
  ulong uVar4;
  uint *puVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  uint uVar11;
  uint uVar12;
  long *plVar13;
  undefined4 *puVar14;
  undefined8 local_d8;
  undefined8 uStack_d0;
  ulong local_c8 [2];
  long local_b8 [11];
  
  lVar6 = sp_el0;
  local_b8[10] = *(long *)(lVar6 + 0x638);
  uVar4 = dev_fwnode();
  iVar3 = -2;
  if ((uVar4 != 0) && (uVar4 < 0xfffffffffffff001)) {
    puVar5 = (uint *)devm_kmalloc(param_1,0x10,0xdc0);
    if (puVar5 == (uint *)0x0) {
      iVar3 = -0xc;
    }
    else {
      if (*(undefined **)(uVar4 + 8) == &of_fwnode_ops) {
        lVar9 = *(long *)(param_1 + 0x2e8);
        lVar6 = of_get_child_by_name(lVar9,"in-ports");
        lVar7 = of_get_child_by_name(lVar9,"out-ports");
        if (lVar6 == 0 && lVar7 == 0) {
          local_b8[0] = 0;
          local_b8[1] = 0;
          uVar4 = of_graph_is_present(lVar9);
          if ((uVar4 & 1) != 0) {
            lVar6 = of_graph_get_next_endpoint(lVar9,0);
            if (lVar6 == 0) {
              uVar12 = 0;
              uVar11 = 0;
            }
            else {
              uVar11 = 0;
              uVar12 = 0;
              do {
                iVar3 = of_graph_parse_endpoint(lVar6,local_b8);
                if (iVar3 == 0) {
                  lVar7 = of_find_property(lVar6,"slave-mode",0);
                  uVar1 = (int)local_b8[0] + 1;
                  if (lVar7 == 0) {
                    if (uVar1 <= uVar11) {
                      uVar1 = uVar11;
                    }
                    uVar11 = uVar1;
                  }
                  else {
                    if (uVar1 <= uVar12) {
                      uVar1 = uVar12;
                    }
                    uVar12 = uVar1;
                  }
                }
                lVar6 = of_graph_get_next_endpoint(lVar9,lVar6);
              } while (lVar6 != 0);
            }
            *puVar5 = uVar12;
            puVar5[1] = uVar11;
          }
LAB_001075e4:
          uVar11 = puVar5[1];
        }
        else {
          if (lVar6 != 0) {
            uVar11 = 0;
            lVar10 = 0;
            local_b8[0] = 0;
            local_b8[1] = 0;
            while (lVar10 = of_graph_get_next_endpoint(lVar6,lVar10), lVar10 != 0) {
              iVar3 = of_graph_parse_endpoint(lVar10,local_b8);
              if ((iVar3 == 0) && (uVar11 < (int)local_b8[0] + 1U)) {
                uVar11 = (int)local_b8[0] + 1;
              }
            }
            *puVar5 = uVar11;
          }
          if (lVar7 == 0) goto LAB_001075e4;
          uVar11 = 0;
          lVar6 = 0;
          local_b8[0] = 0;
          local_b8[1] = 0;
          while (lVar6 = of_graph_get_next_endpoint(lVar7,lVar6), lVar6 != 0) {
            iVar3 = of_graph_parse_endpoint(lVar6,local_b8);
            if ((iVar3 == 0) && (uVar11 < (int)local_b8[0] + 1U)) {
              uVar11 = (int)local_b8[0] + 1;
            }
          }
          puVar5[1] = uVar11;
        }
        if (uVar11 == 0) goto LAB_00107448;
        auVar2._8_8_ = 0;
        auVar2._0_8_ = (long)(int)uVar11;
        if (SUB168(auVar2 * ZEXT816(0x30),8) == 0) {
          lVar6 = devm_kmalloc(param_1,((long)(int)uVar11 + (long)(int)uVar11 * 2) * 0x10,0xdc0);
          *(long *)(puVar5 + 2) = lVar6;
          if (lVar6 != 0) {
            lVar7 = of_get_child_by_name(lVar9,"out-ports");
            lVar6 = lVar7;
            if (lVar7 == 0) {
              if ((of_get_coresight_platform_data___print_once & 1) == 0) {
                of_get_coresight_platform_data___print_once = 1;
                _dev_warn(param_1,"Uses obsolete Coresight DT bindings\n");
              }
              lVar6 = lVar9;
            }
            lVar9 = of_graph_get_next_endpoint(lVar6,0);
            if (lVar9 != 0) {
              do {
                if ((lVar7 != 0) || (lVar10 = of_find_property(lVar9,"slave-mode",0), lVar10 == 0))
                {
                  local_c8[0] = 0;
                  local_c8[1] = 0;
                  local_d8 = 0;
                  uStack_d0 = 0;
                  iVar3 = of_graph_parse_endpoint(lVar9,local_c8);
                  lVar10 = 0;
                  if (iVar3 == 0) {
                    lVar10 = of_graph_get_remote_endpoint(lVar9);
                    if (lVar10 != 0) {
                      lVar8 = of_graph_get_port_parent();
                      uVar4 = of_node_name_eq(lVar8,"in-ports");
                      if (((uVar4 & 1) != 0) ||
                         (uVar4 = of_node_name_eq(lVar8,"out-ports"), (uVar4 & 1) != 0)) {
                        lVar8 = of_get_next_parent(lVar8);
                      }
                      if ((lVar8 != 0) &&
                         (iVar3 = of_graph_parse_endpoint(lVar10,&local_d8), iVar3 == 0)) {
                        lVar8 = lVar8 + 0x18;
                        lVar10 = bus_find_device(&platform_bus_type,0,lVar8,&device_match_fwnode);
                        if ((lVar10 == 0) &&
                           (lVar10 = bus_find_device(&amba_bustype,0,lVar8,&device_match_fwnode),
                           lVar10 == 0)) {
                          iVar3 = -0x205;
                        }
                        else {
                          plVar13 = (long *)(*(long *)(puVar5 + 2) +
                                             (local_c8[0] & 0xffffffff) * 0x30 + 0x10);
                          if (*plVar13 == 0) {
                            puVar14 = (undefined4 *)
                                      (*(long *)(puVar5 + 2) + (local_c8[0] & 0xffffffff) * 0x30);
                            *puVar14 = (undefined4)local_c8[0];
                            lVar8 = fwnode_handle_get(lVar8);
                            *plVar13 = lVar8;
                            *(undefined8 *)(puVar14 + 2) = 0;
                            puVar14[1] = (undefined4)local_d8;
                            local_b8[8] = 0;
                            local_b8[9] = 0;
                            local_b8[6] = 0;
                            local_b8[7] = 0;
                            local_b8[4] = 0;
                            local_b8[5] = 0;
                            local_b8[2] = 0;
                            local_b8[3] = 0;
                            local_b8[0] = 0;
                            local_b8[1] = 0;
                            iVar3 = __of_parse_phandle_with_args(lVar9,"source",0,0,0,local_b8);
                            if ((iVar3 != 0) || (local_b8[0] == 0)) goto LAB_00107674;
                            iVar3 = of_property_read_string
                                              (local_b8[0],"coresight-name",puVar14 + 2);
                            put_device(lVar10);
                            if (iVar3 == 0) goto LAB_0010767c;
                            goto LAB_00107428;
                          }
                          _dev_warn(param_1,"Duplicate output port %d\n");
                          iVar3 = -0x16;
                        }
                        put_device(lVar10);
                        goto LAB_00107428;
                      }
                    }
                    lVar10 = 0;
                  }
LAB_00107674:
                  put_device(lVar10);
                }
LAB_0010767c:
                lVar9 = of_graph_get_next_endpoint(lVar6,lVar9);
              } while (lVar9 != 0);
            }
            goto LAB_00107448;
          }
          iVar3 = -0xc;
        }
        else {
          iVar3 = -0xc;
          puVar5[2] = 0;
          puVar5[3] = 0;
        }
      }
      else {
        iVar3 = -2;
      }
LAB_00107428:
      if (puVar5 < (uint *)0xfffffffffffff001) {
        coresight_release_platform_data(0,puVar5);
      }
    }
  }
  puVar5 = (uint *)(long)iVar3;
LAB_00107448:
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return puVar5;
}



//------------------------------------------------------------
// coresight_create_conns_sysfs_group @ 00107888 size=76
// signature: undefined coresight_create_conns_sysfs_group(void)
// callers: [coresight_register]
//------------------------------------------------------------

undefined8 coresight_create_conns_sysfs_group(long param_1)

{
  undefined8 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    uVar1 = sysfs_create_group(param_1 + 0x38,&coresight_conns_group);
    if ((int)uVar1 == 0) {
      *(undefined1 *)(param_1 + 0x3f4) = 1;
    }
  }
  return uVar1;
}



//------------------------------------------------------------
// coresight_remove_conns_sysfs_group @ 001078d8 size=68
// signature: undefined coresight_remove_conns_sysfs_group(void)
// callers: [coresight_unregister, coresight_release_platform_data]
//------------------------------------------------------------

void coresight_remove_conns_sysfs_group(long param_1)

{
  if ((param_1 != 0) && (*(char *)(param_1 + 0x3f4) != '\0')) {
    sysfs_remove_group(param_1 + 0x38,&coresight_conns_group);
    *(undefined1 *)(param_1 + 0x3f4) = 0;
  }
  return;
}



//------------------------------------------------------------
// coresight_add_sysfs_link @ 00107920 size=220
// signature: undefined coresight_add_sysfs_link(void)
// callers: [coresight_make_links]
//------------------------------------------------------------

int coresight_add_sysfs_link(long *param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  if ((((param_1 == (long *)0x0) || (lVar2 = *param_1, lVar2 == 0)) ||
      (lVar3 = param_1[2], lVar3 == 0)) ||
     (((param_1[1] == 0 || (param_1[3] == 0)) ||
      ((*(char *)(lVar2 + 0x3f4) == '\0' || (*(char *)(lVar3 + 0x3f4) == '\0')))))) {
    iVar1 = -0x16;
  }
  else {
    iVar1 = sysfs_add_link_to_group(lVar2 + 0x38,coresight_conns_group,lVar3 + 0x38);
    if (iVar1 == 0) {
      iVar1 = sysfs_add_link_to_group
                        (param_1[2] + 0x38,coresight_conns_group,*param_1 + 0x38,param_1[3]);
      lVar2 = *param_1;
      if (iVar1 == 0) {
        *(int *)(lVar2 + 0x3f0) = *(int *)(lVar2 + 0x3f0) + 1;
        *(int *)(param_1[2] + 0x3f0) = *(int *)(param_1[2] + 0x3f0) + 1;
      }
      else {
        sysfs_remove_link_from_group(lVar2 + 0x38,coresight_conns_group,param_1[1]);
      }
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// coresight_remove_sysfs_link @ 00107a00 size=136
// signature: undefined coresight_remove_sysfs_link(void)
// callers: []
//------------------------------------------------------------

void coresight_remove_sysfs_link(long *param_1)

{
  if ((((param_1 != (long *)0x0) && (*param_1 != 0)) && (param_1[2] != 0)) &&
     ((param_1[1] != 0 && (param_1[3] != 0)))) {
    sysfs_remove_link_from_group(*param_1 + 0x38,coresight_conns_group);
    sysfs_remove_link_from_group(param_1[2] + 0x38,coresight_conns_group,param_1[3]);
    *(int *)(*param_1 + 0x3f0) = *(int *)(*param_1 + 0x3f0) + -1;
    *(int *)(param_1[2] + 0x3f0) = *(int *)(param_1[2] + 0x3f0) + -1;
  }
  return;
}



//------------------------------------------------------------
// coresight_make_links @ 00107a8c size=180
// signature: undefined coresight_make_links(void)
// callers: [coresight_register, coresight_orphan_match]
//------------------------------------------------------------

undefined8 coresight_make_links(long param_1,undefined4 *param_2,long param_3)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  
  lVar1 = devm_kasprintf(param_1 + 0x38,0xcc0,"out:%d",*param_2);
  if (((lVar1 == 0) || (lVar2 = devm_kasprintf(param_3 + 0x38,0xcc0,"in:%d",param_2[1]), lVar2 == 0)
      ) || (plVar3 = (long *)devm_kmalloc(param_1 + 0x38,0x20,0xdc0), plVar3 == (long *)0x0)) {
    uVar4 = 0xfffffff4;
  }
  else {
    *plVar3 = param_1;
    plVar3[1] = lVar1;
    plVar3[2] = param_3;
    plVar3[3] = lVar2;
    uVar4 = coresight_add_sysfs_link();
    if ((int)uVar4 == 0) {
      *(long *)(param_2 + 6) = param_3;
      *(long **)(param_2 + 8) = plVar3;
    }
  }
  return uVar4;
}



//------------------------------------------------------------
// coresight_remove_links @ 00107b44 size=212
// signature: undefined coresight_remove_links(void)
// callers: [coresight_unregister, coresight_release_platform_data, coresight_remove_match]
//------------------------------------------------------------

void coresight_remove_links(long param_1,long param_2)

{
  long *plVar1;
  
  if ((param_1 != 0) && (plVar1 = *(long **)(param_2 + 0x20), plVar1 != (long *)0x0)) {
    if ((*plVar1 != 0) && (((plVar1[2] != 0 && (plVar1[1] != 0)) && (plVar1[3] != 0)))) {
      sysfs_remove_link_from_group(*plVar1 + 0x38,coresight_conns_group);
      sysfs_remove_link_from_group(plVar1[2] + 0x38,coresight_conns_group,plVar1[3]);
      *(int *)(*plVar1 + 0x3f0) = *(int *)(*plVar1 + 0x3f0) + -1;
      *(int *)(plVar1[2] + 0x3f0) = *(int *)(plVar1[2] + 0x3f0) + -1;
      plVar1 = *(long **)(param_2 + 0x20);
    }
    devm_kfree(*(long *)(param_2 + 0x18) + 0x38,plVar1[3]);
    devm_kfree(param_1 + 0x38,*(undefined8 *)(*(long *)(param_2 + 0x20) + 8));
    devm_kfree(param_1 + 0x38,*(undefined8 *)(param_2 + 0x20));
    *(undefined8 *)(param_2 + 0x18) = 0;
    *(undefined8 *)(param_2 + 0x20) = 0;
  }
  return;
}



//------------------------------------------------------------
// nr_links_show @ 00107c1c size=52
// signature: undefined nr_links_show(void)
// callers: []
//------------------------------------------------------------

long nr_links_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",(ulong)*(uint *)(param_1 + 0x3b8));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_get_named_feat_desc @ 00107c54 size=128
// signature: undefined cscfg_get_named_feat_desc(void)
// callers: [cscfg_cfg_values_show]
//------------------------------------------------------------

long cscfg_get_named_feat_desc(char *param_1)

{
  long *plVar1;
  int iVar2;
  long lVar3;
  long *plVar4;
  
  mutex_lock(&cscfg_mutex);
  plVar1 = (long *)(cscfg_mgr + 0x3a0);
  plVar4 = plVar1;
  do {
    plVar4 = (long *)*plVar4;
    if (plVar4 == plVar1) {
      lVar3 = 0;
      goto LAB_00107cb0;
    }
    iVar2 = strcmp((char *)plVar4[-2],param_1);
  } while (iVar2 != 0);
  lVar3 = (long)(plVar4 + -2);
LAB_00107cb0:
  mutex_unlock(&cscfg_mutex);
  return lVar3;
}



//------------------------------------------------------------
// cscfg_update_feat_param_val @ 00107cd8 size=248
// signature: undefined cscfg_update_feat_param_val(void)
// callers: [cscfg_param_value_store]
//------------------------------------------------------------

undefined8 cscfg_update_feat_param_val(long param_1,uint param_2,undefined8 param_3)

{
  long lVar1;
  long *plVar2;
  long *plVar3;
  undefined8 uVar4;
  
  mutex_lock(&cscfg_mutex);
  lVar1 = cscfg_mgr;
  if (*(int *)(cscfg_mgr + 0x3d0) == 0) {
    if (((int)param_2 < 0) || (*(int *)(param_1 + 0x24) <= (int)param_2)) {
      uVar4 = 0xffffffea;
    }
    else {
      plVar3 = (long *)(cscfg_mgr + 0x390);
      *(undefined8 *)(*(long *)(param_1 + 0x28) + (ulong)param_2 * 0x10 + 8) = param_3;
      plVar2 = *(long **)(lVar1 + 0x390);
      if (plVar2 != plVar3) {
        do {
          plVar3 = (long *)(plVar2[-3] + 0x3f8);
          do {
            plVar3 = (long *)*plVar3;
            if (plVar3 == (long *)(plVar2[-3] + 0x3f8)) goto LAB_00107d50;
          } while (plVar3[-2] != param_1);
          if (plVar3 != (long *)0x10) {
            *(undefined8 *)(plVar3[4] + (ulong)param_2 * 0x20 + 0x10) = param_3;
            lVar1 = cscfg_mgr;
          }
LAB_00107d50:
          plVar2 = (long *)*plVar2;
        } while (plVar2 != (long *)(lVar1 + 0x390));
      }
      uVar4 = 0;
    }
  }
  else {
    uVar4 = 0xfffffff0;
  }
  mutex_unlock(&cscfg_mutex);
  return uVar4;
}



//------------------------------------------------------------
// cscfg_load_config_sets @ 00107dd4 size=1252
// signature: undefined cscfg_load_config_sets(void)
// callers: [cscfg_preload]
//------------------------------------------------------------

int cscfg_load_config_sets(long *param_1,long *param_2,long *param_3)

{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined *puVar4;
  long *plVar5;
  undefined8 *puVar6;
  char *pcVar7;
  undefined8 *puVar8;
  long *plVar9;
  long lVar10;
  int iVar11;
  long *plVar12;
  long lVar13;
  
  mutex_lock(&cscfg_mutex);
  if (*(int *)(cscfg_mgr + 0x498) != 0) {
    iVar2 = -0x10;
    goto LAB_00108274;
  }
  *(undefined4 *)(cscfg_mgr + 0x498) = 1;
  if ((param_2 != (long *)0x0) && (puVar6 = (undefined8 *)*param_2, puVar6 != (undefined8 *)0x0)) {
    iVar11 = 0;
    plVar12 = param_2;
    do {
      lVar10 = cscfg_mgr;
      plVar9 = (long *)(cscfg_mgr + 0x3a0);
      plVar5 = plVar9;
      while (plVar5 = (long *)*plVar5, plVar5 != plVar9) {
        pcVar7 = (char *)*puVar6;
        iVar2 = strcmp((char *)plVar5[-2],pcVar7);
        if (iVar2 == 0) {
          iVar2 = -0x11;
          goto LAB_00108254;
        }
      }
      puVar8 = *(undefined8 **)(lVar10 + 0x390);
LAB_00107ea4:
      if (puVar8 != (undefined8 *)(lVar10 + 0x390)) {
        if ((*(uint *)(puVar6 + 4) & *(uint *)(puVar8 + -2)) == 0) goto LAB_00107ea0;
        iVar2 = cscfg_load_feat_csdev(puVar8[-3],puVar6,puVar8 + -1);
        if (iVar2 == 0) {
          lVar10 = cscfg_mgr;
          goto LAB_00107ea0;
        }
        pcVar7 = *(char **)*plVar12;
LAB_00108254:
        puVar4 = &DAT_0010b068;
        goto LAB_00108260;
      }
      plVar9 = (long *)(lVar10 + 0x3a0);
      lVar10 = *(long *)(lVar10 + 0x3a0);
      puVar8 = puVar6 + 2;
      uVar3 = __list_add_valid(puVar8,plVar9,lVar10);
      if ((uVar3 & 1) != 0) {
        *(undefined8 **)(lVar10 + 8) = puVar8;
        puVar6[2] = lVar10;
        puVar6[3] = plVar9;
        *plVar9 = (long)puVar8;
      }
      iVar11 = iVar11 + 1;
      lVar10 = *plVar12;
      plVar12 = param_2 + iVar11;
      *(long **)(lVar10 + 0x40) = param_3;
      puVar6 = (undefined8 *)*plVar12;
    } while (puVar6 != (undefined8 *)0x0);
  }
  if ((param_1 != (long *)0x0) && (puVar6 = (undefined8 *)*param_1, puVar6 != (undefined8 *)0x0)) {
    iVar11 = 0;
    plVar12 = param_1;
LAB_00107f20:
    lVar10 = cscfg_mgr;
    plVar9 = (long *)(cscfg_mgr + 0x3b0);
    plVar5 = plVar9;
    while (plVar5 = (long *)*plVar5, plVar5 != plVar9) {
      iVar2 = strcmp((char *)plVar5[-2],(char *)*puVar6);
      if (iVar2 == 0) {
        iVar2 = -0x11;
        goto LAB_00108130;
      }
    }
    uVar1 = *(uint *)(puVar6 + 4);
    if (0 < (int)uVar1) {
      uVar3 = 0;
      lVar13 = puVar6[5];
      plVar9 = (long *)(lVar10 + 0x3a0);
      do {
        pcVar7 = *(char **)(lVar13 + uVar3 * 8);
        plVar5 = plVar9;
        do {
          plVar5 = (long *)*plVar5;
          if (plVar5 == plVar9) {
            iVar2 = -0x16;
            goto LAB_00108130;
          }
          iVar2 = strcmp((char *)plVar5[-2],pcVar7);
        } while (iVar2 != 0);
        uVar3 = uVar3 + 1;
      } while (uVar3 != uVar1);
    }
    plVar9 = (long *)(lVar10 + 0x390);
    while (plVar9 = (long *)*plVar9, plVar9 != (long *)(cscfg_mgr + 0x390)) {
      iVar2 = cscfg_add_csdev_cfg(plVar9[-3],puVar6);
      if (iVar2 != 0) goto LAB_00108130;
    }
    iVar2 = etm_perf_add_symlink_cscfg(cscfg_mgr,puVar6);
    if (iVar2 == 0) goto code_r0x00107fe0;
LAB_00108130:
    puVar4 = &DAT_0010b131;
    pcVar7 = *(char **)*plVar12;
LAB_00108260:
    _printk(puVar4,pcVar7);
    goto LAB_00108264;
  }
LAB_0010803c:
  lVar13 = cscfg_mgr;
  puVar6 = *(undefined8 **)(cscfg_mgr + 0x3c8);
  lVar10 = cscfg_mgr + 0x3c0;
  uVar3 = __list_add_valid(param_3,puVar6,lVar10);
  if ((uVar3 & 1) != 0) {
    *(long **)(lVar13 + 0x3c8) = param_3;
    *param_3 = lVar10;
    param_3[1] = (long)puVar6;
    *puVar6 = param_3;
  }
  if ((((*(long *)(cscfg_mgr + 0x3c0) == cscfg_mgr + 0x3c0) ||
       (*(long *)(cscfg_mgr + 0x3c0) != *(long *)(cscfg_mgr + 0x3c8))) &&
      (*(int *)(param_3[1] + 0x10) == 1)) &&
     (uVar3 = try_module_get(*(undefined8 *)(param_3[1] + 0x18)), (uVar3 & 1) == 0)) {
    iVar2 = -0x16;
    goto LAB_00108218;
  }
  mutex_unlock(&cscfg_mutex);
  if ((param_2 != (long *)0x0) && (*param_2 != 0)) {
    iVar11 = 1;
    do {
      iVar2 = cscfg_configfs_add_feature();
      if (iVar2 != 0) goto LAB_0010814c;
      lVar10 = (long)iVar11;
      iVar11 = iVar11 + 1;
    } while (param_2[lVar10] != 0);
  }
  if (param_1 == (long *)0x0) {
    mutex_lock(&cscfg_mutex);
  }
  else {
    if (*param_1 != 0) {
      iVar11 = 1;
      do {
        iVar2 = cscfg_configfs_add_config();
        if (iVar2 != 0) goto LAB_0010814c;
        lVar10 = (long)iVar11;
        iVar11 = iVar11 + 1;
      } while (param_1[lVar10] != 0);
    }
    mutex_lock(&cscfg_mutex);
    lVar10 = *param_1;
    if (lVar10 != 0) {
      iVar2 = 1;
      do {
        *(undefined1 *)(lVar10 + 0x60) = 1;
        lVar10 = param_1[iVar2];
        iVar2 = iVar2 + 1;
      } while (lVar10 != 0);
    }
  }
  iVar2 = 0;
  goto LAB_0010826c;
LAB_00107ea0:
  puVar8 = (undefined8 *)*puVar8;
  goto LAB_00107ea4;
code_r0x00107fe0:
  puVar8 = puVar6 + 2;
  lVar10 = *(long *)(cscfg_mgr + 0x3b0);
  plVar9 = (long *)(cscfg_mgr + 0x3b0);
  uVar3 = __list_add_valid(puVar8,plVar9,lVar10);
  if ((uVar3 & 1) != 0) {
    *(undefined8 **)(lVar10 + 8) = puVar8;
    puVar6[2] = lVar10;
    puVar6[3] = plVar9;
    *plVar9 = (long)puVar8;
  }
  *(undefined4 *)(puVar6 + 9) = 0;
  *(long **)(*plVar12 + 0x50) = param_3;
  iVar11 = iVar11 + 1;
  lVar10 = *plVar12;
  plVar12 = param_1 + iVar11;
  *(undefined1 *)(lVar10 + 0x60) = 0;
  puVar6 = (undefined8 *)*plVar12;
  if (puVar6 == (undefined8 *)0x0) goto LAB_0010803c;
  goto LAB_00107f20;
LAB_0010814c:
  mutex_lock(&cscfg_mutex);
  lVar10 = cscfg_mgr;
  for (puVar6 = *(undefined8 **)(cscfg_mgr + 0x3b0); puVar6 != (undefined8 *)(lVar10 + 0x3b0);
      puVar6 = (undefined8 *)*puVar6) {
    if ((long *)puVar6[8] == param_3) {
      cscfg_configfs_del_config(puVar6 + -2);
      lVar10 = cscfg_mgr;
    }
  }
  for (puVar6 = *(undefined8 **)(lVar10 + 0x3a0); puVar6 != (undefined8 *)(lVar10 + 0x3a0);
      puVar6 = (undefined8 *)*puVar6) {
    if ((long *)puVar6[6] == param_3) {
      cscfg_configfs_del_feature(puVar6 + -2);
      lVar10 = cscfg_mgr;
    }
  }
  if (((*(long *)(lVar10 + 0x3c0) == lVar10 + 0x3c0) ||
      (*(long *)(lVar10 + 0x3c0) != *(long *)(lVar10 + 0x3c8))) &&
     (*(int *)(param_3[1] + 0x10) == 1)) {
    module_put(*(undefined8 *)(param_3[1] + 0x18));
  }
LAB_00108218:
  uVar3 = __list_del_entry_valid(param_3);
  if ((uVar3 & 1) != 0) {
    lVar10 = *param_3;
    plVar12 = (long *)param_3[1];
    *(long **)(lVar10 + 8) = plVar12;
    *plVar12 = lVar10;
  }
  *param_3 = -0x2152ffffffffff00;
  param_3[1] = -0x2152fffffffffede;
LAB_00108264:
  cscfg_unload_owned_cfgs_feats(param_3);
LAB_0010826c:
  *(undefined4 *)(cscfg_mgr + 0x498) = 0;
LAB_00108274:
  mutex_unlock(&cscfg_mutex);
  return iVar2;
}



//------------------------------------------------------------
// cscfg_unload_owned_cfgs_feats @ 001082b8 size=472
// signature: undefined cscfg_unload_owned_cfgs_feats(void)
// callers: [cscfg_unload_config_sets, cscfg_load_config_sets, cscfg_clear_device]
//------------------------------------------------------------

void cscfg_unload_owned_cfgs_feats(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long lVar4;
  undefined8 *puVar5;
  long *plVar6;
  long *plVar7;
  
  for (puVar5 = *(undefined8 **)(cscfg_mgr + 0x390); puVar5 != (undefined8 *)(cscfg_mgr + 0x390);
      puVar5 = (undefined8 *)*puVar5) {
    lVar4 = puVar5[-3];
    plVar7 = *(long **)(lVar4 + 0x408);
    if (*(long **)(lVar4 + 0x408) != (long *)(lVar4 + 0x408)) {
      do {
        plVar6 = (long *)*plVar7;
        if (*(long *)(plVar7[-3] + 0x50) == param_1) {
          uVar3 = __list_del_entry_valid(plVar7);
          if ((uVar3 & 1) != 0) {
            lVar1 = *plVar7;
            plVar2 = (long *)plVar7[1];
            *(long **)(lVar1 + 8) = plVar2;
            *plVar2 = lVar1;
          }
          *plVar7 = -0x2152ffffffffff00;
          plVar7[1] = -0x2152fffffffffede;
        }
        plVar7 = plVar6;
      } while (plVar6 != (long *)(lVar4 + 0x408));
      lVar4 = puVar5[-3];
    }
    plVar7 = *(long **)(lVar4 + 0x3f8);
    while (plVar6 = plVar7, plVar6 != (long *)(lVar4 + 0x3f8)) {
      plVar7 = (long *)*plVar6;
      if (*(long *)(plVar6[-2] + 0x40) == param_1) {
        uVar3 = __list_del_entry_valid(plVar6);
        if ((uVar3 & 1) != 0) {
          lVar1 = *plVar6;
          plVar2 = (long *)plVar6[1];
          *(long **)(lVar1 + 8) = plVar2;
          *plVar2 = lVar1;
        }
        *plVar6 = -0x2152ffffffffff00;
        plVar6[1] = -0x2152fffffffffede;
      }
    }
  }
  lVar4 = cscfg_mgr;
  plVar7 = *(long **)(cscfg_mgr + 0x3b0);
  if (*(long **)(cscfg_mgr + 0x3b0) != (long *)(cscfg_mgr + 0x3b0)) {
    do {
      plVar6 = (long *)*plVar7;
      if (plVar7[8] == param_1) {
        etm_perf_del_symlink_cscfg(plVar7 + -2);
        uVar3 = __list_del_entry_valid(plVar7);
        if ((uVar3 & 1) != 0) {
          lVar4 = *plVar7;
          plVar2 = (long *)plVar7[1];
          *(long **)(lVar4 + 8) = plVar2;
          *plVar2 = lVar4;
        }
        *plVar7 = -0x2152ffffffffff00;
        plVar7[1] = -0x2152fffffffffede;
        lVar4 = cscfg_mgr;
      }
      plVar7 = plVar6;
    } while (plVar6 != (long *)(lVar4 + 0x3b0));
  }
  plVar7 = *(long **)(lVar4 + 0x3a0);
  if (*(long **)(lVar4 + 0x3a0) != (long *)(lVar4 + 0x3a0)) {
    do {
      plVar6 = (long *)*plVar7;
      if (plVar7[6] == param_1) {
        uVar3 = __list_del_entry_valid(plVar7);
        if ((uVar3 & 1) != 0) {
          lVar4 = *plVar7;
          plVar2 = (long *)plVar7[1];
          *(long **)(lVar4 + 8) = plVar2;
          *plVar2 = lVar4;
        }
        *plVar7 = -0x2152ffffffffff00;
        plVar7[1] = -0x2152fffffffffede;
        lVar4 = cscfg_mgr;
      }
      plVar7 = plVar6;
    } while (plVar6 != (long *)(lVar4 + 0x3a0));
  }
  return;
}



//------------------------------------------------------------
// cscfg_unload_config_sets @ 00108494 size=416
// signature: undefined cscfg_unload_config_sets(void)
// callers: []
//------------------------------------------------------------

undefined8 cscfg_unload_config_sets(long *param_1)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  
  mutex_lock(&cscfg_mutex);
  lVar3 = cscfg_mgr;
  if (*(int *)(cscfg_mgr + 0x498) == 0) {
    *(undefined4 *)(cscfg_mgr + 0x498) = 2;
    if (*(int *)(lVar3 + 0x3d0) == 0) {
      if (*(long *)(lVar3 + 0x3c0) == lVar3 + 0x3c0) {
        uVar4 = 0xffffffea;
      }
      else {
        uVar4 = 0xffffffea;
        if ((*(long **)(lVar3 + 0x3c8) == param_1) && (*(long **)(lVar3 + 0x3c8) != (long *)0x0)) {
          mutex_unlock(&cscfg_mutex);
          lVar3 = cscfg_mgr;
          for (puVar5 = *(undefined8 **)(cscfg_mgr + 0x3b0); puVar5 != (undefined8 *)(lVar3 + 0x3b0)
              ; puVar5 = (undefined8 *)*puVar5) {
            if ((long *)puVar5[8] == param_1) {
              cscfg_configfs_del_config(puVar5 + -2);
              lVar3 = cscfg_mgr;
            }
          }
          for (puVar5 = *(undefined8 **)(lVar3 + 0x3a0); puVar5 != (undefined8 *)(lVar3 + 0x3a0);
              puVar5 = (undefined8 *)*puVar5) {
            if ((long *)puVar5[6] == param_1) {
              cscfg_configfs_del_feature(puVar5 + -2);
              lVar3 = cscfg_mgr;
            }
          }
          mutex_lock(&cscfg_mutex);
          cscfg_unload_owned_cfgs_feats(param_1);
          if (((*(long *)(cscfg_mgr + 0x3c0) == cscfg_mgr + 0x3c0) ||
              (*(long *)(cscfg_mgr + 0x3c0) != *(long *)(cscfg_mgr + 0x3c8))) &&
             (*(int *)(param_1[1] + 0x10) == 1)) {
            module_put(*(undefined8 *)(param_1[1] + 0x18));
          }
          uVar2 = __list_del_entry_valid(param_1);
          if ((uVar2 & 1) != 0) {
            lVar3 = *param_1;
            plVar1 = (long *)param_1[1];
            *(long **)(lVar3 + 8) = plVar1;
            *plVar1 = lVar3;
          }
          uVar4 = 0;
          *param_1 = -0x2152ffffffffff00;
          param_1[1] = -0x2152fffffffffede;
          lVar3 = cscfg_mgr;
        }
      }
    }
    else {
      uVar4 = 0xfffffff0;
    }
    *(undefined4 *)(lVar3 + 0x498) = 0;
  }
  else {
    uVar4 = 0xfffffff0;
  }
  mutex_unlock(&cscfg_mutex);
  return uVar4;
}



//------------------------------------------------------------
// cscfg_register_csdev @ 00108638 size=520
// signature: undefined cscfg_register_csdev(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cscfg_register_csdev(long param_1,uint param_2,long *param_3)

{
  long *plVar1;
  long *plVar2;
  int iVar3;
  long *plVar4;
  ulong uVar5;
  long lVar6;
  long lVar7;
  undefined8 *puVar8;
  
  mutex_lock(&cscfg_mutex);
  plVar4 = (long *)kmalloc_trace(__dev_err,0xdc0,0x28);
  if (plVar4 == (long *)0x0) {
    iVar3 = -0xc;
  }
  else {
    lVar7 = *param_3;
    *plVar4 = param_1;
    plVar2 = plVar4 + 3;
    *(uint *)(plVar4 + 1) = param_2;
    lVar6 = cscfg_mgr;
    plVar4[2] = lVar7;
    lVar7 = *(long *)(lVar6 + 0x390);
    plVar1 = (long *)(lVar6 + 0x390);
    uVar5 = __list_add_valid(plVar2,plVar1,lVar7);
    if ((uVar5 & 1) != 0) {
      *(long **)(lVar7 + 8) = plVar2;
      plVar4[3] = lVar7;
      plVar4[4] = (long)plVar1;
      *plVar1 = (long)plVar2;
    }
    *(long *)(param_1 + 0x3f8) = param_1 + 0x3f8;
    *(long *)(param_1 + 0x400) = param_1 + 0x3f8;
    *(long *)(param_1 + 0x408) = param_1 + 0x408;
    *(long *)(param_1 + 0x410) = param_1 + 0x408;
    *(undefined4 *)(param_1 + 0x418) = 0;
    if (*param_3 == 0) {
      iVar3 = -0x16;
LAB_00108798:
      plVar4 = (long *)(cscfg_mgr + 0x390);
      do {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(cscfg_mgr + 0x390)) goto LAB_001087f4;
      } while (plVar4[-3] != param_1);
    }
    else {
      lVar6 = cscfg_mgr;
      for (puVar8 = *(undefined8 **)(cscfg_mgr + 0x3a0); puVar8 != (undefined8 *)(lVar6 + 0x3a0);
          puVar8 = (undefined8 *)*puVar8) {
        if ((*(uint *)(puVar8 + 2) & param_2) != 0) {
          iVar3 = cscfg_load_feat_csdev(param_1,puVar8 + -2,param_3);
          if (iVar3 != 0) goto LAB_00108798;
          lVar6 = cscfg_mgr;
        }
      }
      plVar4 = (long *)(lVar6 + 0x3b0);
      do {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(cscfg_mgr + 0x3b0)) {
          lVar6 = *(long *)(param_1 + 0xa8);
          if (lVar6 == 0) {
            lVar6 = *(long *)(param_1 + 0x38);
          }
          _printk(&DAT_0010af95,lVar6);
          iVar3 = 0;
          goto LAB_001087f4;
        }
        iVar3 = cscfg_add_csdev_cfg(param_1,plVar4 + -2);
      } while (iVar3 == 0);
      plVar4 = (long *)(cscfg_mgr + 0x390);
      do {
        plVar4 = (long *)*plVar4;
        if (plVar4 == (long *)(cscfg_mgr + 0x390)) goto LAB_001087f4;
      } while (plVar4[-3] != param_1);
    }
    uVar5 = __list_del_entry_valid(plVar4);
    if ((uVar5 & 1) != 0) {
      lVar6 = *plVar4;
      plVar2 = (long *)plVar4[1];
      *(long **)(lVar6 + 8) = plVar2;
      *plVar2 = lVar6;
    }
    *plVar4 = -0x2152ffffffffff00;
    plVar4[1] = -0x2152fffffffffede;
    kfree(plVar4 + -3);
  }
LAB_001087f4:
  mutex_unlock(&cscfg_mutex);
  return iVar3;
}



//------------------------------------------------------------
// cscfg_unregister_csdev @ 00108844 size=156
// signature: undefined cscfg_unregister_csdev(void)
// callers: []
//------------------------------------------------------------

void cscfg_unregister_csdev(long param_1)

{
  long lVar1;
  long *plVar2;
  ulong uVar3;
  long *plVar4;
  
  mutex_lock(&cscfg_mutex);
  plVar4 = (long *)(cscfg_mgr + 0x390);
  do {
    plVar4 = (long *)*plVar4;
    if (plVar4 == (long *)(cscfg_mgr + 0x390)) goto LAB_001088c4;
  } while (plVar4[-3] != param_1);
  uVar3 = __list_del_entry_valid(plVar4);
  if ((uVar3 & 1) != 0) {
    lVar1 = *plVar4;
    plVar2 = (long *)plVar4[1];
    *(long **)(lVar1 + 8) = plVar2;
    *plVar2 = lVar1;
  }
  *plVar4 = -0x2152ffffffffff00;
  plVar4[1] = -0x2152fffffffffede;
  kfree(plVar4 + -3);
LAB_001088c4:
  mutex_unlock(&cscfg_mutex);
  return;
}



//------------------------------------------------------------
// cscfg_csdev_reset_feats @ 001088e4 size=108
// signature: undefined cscfg_csdev_reset_feats(void)
// callers: []
//------------------------------------------------------------

void cscfg_csdev_reset_feats(long param_1)

{
  undefined8 uVar1;
  long *plVar2;
  
  uVar1 = _raw_spin_lock_irqsave(param_1 + 0x418);
  for (plVar2 = *(long **)(param_1 + 0x3f8); plVar2 != (long *)(param_1 + 0x3f8);
      plVar2 = (long *)*plVar2) {
    cscfg_reset_feat(plVar2 + -2);
  }
  _raw_spin_unlock_irqrestore(param_1 + 0x418,uVar1);
  return;
}



//------------------------------------------------------------
// cscfg_config_sysfs_activate @ 00108954 size=304
// signature: undefined cscfg_config_sysfs_activate(void)
// callers: [cscfg_cfg_enable_store]
//------------------------------------------------------------

int cscfg_config_sysfs_activate(long param_1,uint param_2)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long *plVar5;
  ulong uVar6;
  
  mutex_lock(&cscfg_mutex);
  uVar6 = *(ulong *)(*(long *)(param_1 + 0x40) + 0x20);
  if ((param_2 & 1) == 0) {
    if (*(uint *)(cscfg_mgr + 0x490) != uVar6) {
      iVar4 = -0x16;
      goto LAB_00108a38;
    }
    plVar5 = (long *)(cscfg_mgr + 0x3b0);
    do {
      plVar5 = (long *)*plVar5;
      if (plVar5 == (long *)(cscfg_mgr + 0x3b0)) goto LAB_00108a0c;
    } while (*(ulong *)(plVar5[6] + 0x20) != uVar6);
    piVar1 = (int *)(cscfg_mgr + 0x3d0);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    piVar1 = (int *)(plVar5 + 7);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar4 = *piVar1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = iVar4 + -1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if ((iVar4 + -1 == 0) && (*(int *)(plVar5[8] + 0x10) == 1)) {
      module_put(*(undefined8 *)(plVar5[8] + 0x18));
    }
LAB_00108a0c:
    uVar6 = 0;
  }
  else {
    if (*(uint *)(cscfg_mgr + 0x490) != 0) {
      iVar4 = -0x10;
      goto LAB_00108a38;
    }
    iVar4 = _cscfg_activate_config(uVar6);
    if (iVar4 != 0) goto LAB_00108a38;
  }
  iVar4 = 0;
  *(int *)(cscfg_mgr + 0x490) = (int)uVar6;
LAB_00108a38:
  mutex_unlock(&cscfg_mutex);
  return iVar4;
}



//------------------------------------------------------------
// _cscfg_activate_config @ 00108aa4 size=260
// signature: undefined _cscfg_activate_config(void)
// callers: [cscfg_activate_config, cscfg_config_sysfs_activate]
//------------------------------------------------------------

undefined8 _cscfg_activate_config(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  ulong uVar5;
  long *plVar6;
  
  if (*(int *)(cscfg_mgr + 0x498) != 2) {
    plVar6 = (long *)(cscfg_mgr + 0x3b0);
    do {
      plVar6 = (long *)*plVar6;
      if (plVar6 == (long *)(cscfg_mgr + 0x3b0)) {
        return 0xffffffea;
      }
    } while (*(long *)(plVar6[6] + 0x20) != param_1);
    if (*(char *)(plVar6 + 10) != '\0') {
      piVar1 = (int *)(plVar6 + 7);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar2 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
      if (((iVar2 == 0) && (*(int *)(plVar6[8] + 0x10) == 1)) &&
         (uVar5 = try_module_get(*(undefined8 *)(plVar6[8] + 0x18)), (uVar5 & 1) == 0)) {
        piVar1 = (int *)(plVar6 + 7);
        Hint_Prefetch(piVar1,2,0,1);
        do {
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = *piVar1 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        return 0xffffffea;
      }
      piVar1 = (int *)(cscfg_mgr + 0x3d0);
      Hint_Prefetch(piVar1,2,0,1);
      do {
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = *piVar1 + 1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      return 0;
    }
  }
  return 0xfffffff0;
}



//------------------------------------------------------------
// cscfg_config_sysfs_set_preset @ 00108bdc size=72
// signature: undefined cscfg_config_sysfs_set_preset(void)
// callers: [cscfg_cfg_enable_store, cscfg_cfg_preset_store]
//------------------------------------------------------------

void cscfg_config_sysfs_set_preset(undefined4 param_1)

{
  mutex_lock(&cscfg_mutex);
  *(undefined4 *)(cscfg_mgr + 0x494) = param_1;
  mutex_unlock(&cscfg_mutex);
  return;
}



//------------------------------------------------------------
// cscfg_config_sysfs_get_active_cfg @ 00108c28 size=96
// signature: undefined cscfg_config_sysfs_get_active_cfg(void)
// callers: []
//------------------------------------------------------------

void cscfg_config_sysfs_get_active_cfg(ulong *param_1,undefined4 *param_2)

{
  long lVar1;
  
  mutex_lock(&cscfg_mutex);
  lVar1 = cscfg_mgr;
  *param_2 = *(undefined4 *)(cscfg_mgr + 0x494);
  *param_1 = (ulong)*(uint *)(lVar1 + 0x490);
  mutex_unlock(&cscfg_mutex);
  return;
}



//------------------------------------------------------------
// cscfg_activate_config @ 00108c8c size=76
// signature: undefined cscfg_activate_config(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

undefined4 cscfg_activate_config(undefined8 param_1)

{
  undefined4 uVar1;
  
  mutex_lock(&cscfg_mutex);
  uVar1 = _cscfg_activate_config(param_1);
  mutex_unlock(&cscfg_mutex);
  return uVar1;
}



//------------------------------------------------------------
// cscfg_deactivate_config @ 00108cdc size=208
// signature: undefined cscfg_deactivate_config(void)
// callers: [free_event_data]
//------------------------------------------------------------

void cscfg_deactivate_config(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  long *plVar5;
  
  mutex_lock(&cscfg_mutex);
  plVar5 = (long *)(cscfg_mgr + 0x3b0);
  do {
    plVar5 = (long *)*plVar5;
    if (plVar5 == (long *)(cscfg_mgr + 0x3b0)) goto LAB_00108d68;
  } while (*(long *)(plVar5[6] + 0x20) != param_1);
  piVar1 = (int *)(cscfg_mgr + 0x3d0);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = *piVar1 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  piVar1 = (int *)(plVar5 + 7);
  Hint_Prefetch(piVar1,2,0,1);
  do {
    iVar2 = *piVar1;
    cVar3 = '\x01';
    bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
    if (bVar4) {
      *piVar1 = iVar2 + -1;
      cVar3 = ExclusiveMonitorsStatus();
    }
  } while (cVar3 != '\0');
  DataMemoryBarrier(2,3);
  if ((iVar2 + -1 == 0) && (*(int *)(plVar5[8] + 0x10) == 1)) {
    module_put(*(undefined8 *)(plVar5[8] + 0x18));
  }
LAB_00108d68:
  mutex_unlock(&cscfg_mutex);
  return;
}



//------------------------------------------------------------
// cscfg_csdev_enable_active_config @ 00108dd0 size=448
// signature: undefined cscfg_csdev_enable_active_config(void)
// callers: []
//------------------------------------------------------------

int cscfg_csdev_enable_active_config(long param_1,long param_2,undefined4 param_3)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  undefined8 uVar7;
  ulong uVar8;
  long lVar9;
  long lVar10;
  long *plVar11;
  
  if (*(int *)(cscfg_mgr + 0x3d0) != 0) {
    lVar1 = param_1 + 0x418;
    uVar7 = _raw_spin_lock_irqsave(lVar1);
    for (plVar11 = *(long **)(param_1 + 0x408); plVar11 != (long *)(param_1 + 0x408);
        plVar11 = (long *)*plVar11) {
      lVar10 = plVar11[-3];
      if (*(long *)(*(long *)(lVar10 + 0x40) + 0x20) == param_2) {
        piVar2 = (int *)(lVar10 + 0x48);
        Hint_Prefetch(piVar2,2,0,1);
        do {
          iVar6 = *piVar2;
          cVar4 = '\x01';
          bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
          if (bVar5) {
            *piVar2 = iVar6 + 1;
            cVar4 = ExclusiveMonitorsStatus();
          }
        } while (cVar4 != '\0');
        DataMemoryBarrier(2,3);
        if (((iVar6 != 0) || (*(int *)(*(long *)(lVar10 + 0x50) + 0x10) != 1)) ||
           (uVar8 = try_module_get(*(undefined8 *)(*(long *)(lVar10 + 0x50) + 0x18)),
           (uVar8 & 1) != 0)) {
          lVar9 = (long)(plVar11 + -3);
          *(long *)(param_1 + 0x420) = lVar9;
          _raw_spin_unlock_irqrestore(lVar1,uVar7);
          if (lVar9 == 0) {
            return 0;
          }
          iVar6 = cscfg_csdev_enable_config(lVar9,param_3);
          if (iVar6 == 0) {
            uVar7 = _raw_spin_lock_irqsave(lVar1);
            if (*(long *)(param_1 + 0x420) != 0) {
              *(undefined1 *)(plVar11 + -1) = 1;
              break;
            }
            _raw_spin_unlock_irqrestore(lVar1,uVar7);
            iVar6 = -0x10;
          }
          piVar2 = (int *)(lVar10 + 0x48);
          Hint_Prefetch(piVar2,2,0,1);
          do {
            iVar3 = *piVar2;
            cVar4 = '\x01';
            bVar5 = (bool)ExclusiveMonitorPass(piVar2,0x10);
            if (bVar5) {
              *piVar2 = iVar3 + -1;
              cVar4 = ExclusiveMonitorsStatus();
            }
          } while (cVar4 != '\0');
          DataMemoryBarrier(2,3);
          if (iVar3 + -1 != 0) {
            return iVar6;
          }
          if (*(int *)(*(long *)(lVar10 + 0x50) + 0x10) == 1) {
            module_put(*(undefined8 *)(*(long *)(lVar10 + 0x50) + 0x18));
            return iVar6;
          }
          return iVar6;
        }
        piVar2 = (int *)(lVar10 + 0x48);
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
    }
    _raw_spin_unlock_irqrestore(lVar1,uVar7);
  }
  return 0;
}



//------------------------------------------------------------
// cscfg_csdev_disable_active_config @ 00108fc0 size=188
// signature: undefined cscfg_csdev_disable_active_config(void)
// callers: []
//------------------------------------------------------------

void cscfg_csdev_disable_active_config(long param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  undefined8 uVar5;
  long lVar6;
  long *plVar7;
  
  lVar6 = param_1 + 0x418;
  uVar5 = _raw_spin_lock_irqsave(lVar6);
  plVar7 = *(long **)(param_1 + 0x420);
  if ((plVar7 == (long *)0x0) || ((char)plVar7[2] == '\0')) {
    *(undefined8 *)(param_1 + 0x420) = 0;
    _raw_spin_unlock_irqrestore(lVar6,uVar5);
  }
  else {
    *(undefined1 *)(plVar7 + 2) = 0;
    *(undefined8 *)(param_1 + 0x420) = 0;
    _raw_spin_unlock_irqrestore(lVar6,uVar5);
    cscfg_csdev_disable_config(plVar7);
    lVar6 = *plVar7;
    piVar1 = (int *)(lVar6 + 0x48);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      iVar2 = *piVar1;
      cVar3 = '\x01';
      bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar4) {
        *piVar1 = iVar2 + -1;
        cVar3 = ExclusiveMonitorsStatus();
      }
    } while (cVar3 != '\0');
    DataMemoryBarrier(2,3);
    if ((iVar2 + -1 == 0) && (lVar6 = *(long *)(lVar6 + 0x50), *(int *)(lVar6 + 0x10) == 1)) {
      module_put(*(undefined8 *)(lVar6 + 0x18));
    }
  }
  return;
}



//------------------------------------------------------------
// cscfg_device @ 00109094 size=12
// signature: undefined cscfg_device(void)
// callers: [cscfg_configfs_init, cscfg_configfs_add_feature, cscfg_configfs_add_config]
//------------------------------------------------------------

undefined8 cscfg_device(void)

{
  return cscfg_mgr;
}



//------------------------------------------------------------
// cscfg_clear_device @ 001090a0 size=388
// signature: undefined cscfg_clear_device(void)
// callers: [cscfg_exit, cscfg_init]
//------------------------------------------------------------

void cscfg_clear_device(void)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  undefined8 *puVar5;
  
  mutex_lock(&cscfg_mutex);
  if (*(long *)(cscfg_mgr + 0x3c0) != cscfg_mgr + 0x3c0) {
    do {
      plVar4 = *(long **)(cscfg_mgr + 0x3c8);
      if ((int)plVar4[2] == 1) {
        _printk(&DAT_0010b26d);
      }
      else {
        if ((int)plVar4[2] == 0) {
          _printk(&DAT_0010af44);
        }
        mutex_unlock(&cscfg_mutex);
        lVar3 = cscfg_mgr;
        for (puVar5 = *(undefined8 **)(cscfg_mgr + 0x3b0); puVar5 != (undefined8 *)(lVar3 + 0x3b0);
            puVar5 = (undefined8 *)*puVar5) {
          if ((long *)puVar5[8] == plVar4) {
            cscfg_configfs_del_config(puVar5 + -2);
            lVar3 = cscfg_mgr;
          }
        }
        for (puVar5 = *(undefined8 **)(lVar3 + 0x3a0); puVar5 != (undefined8 *)(lVar3 + 0x3a0);
            puVar5 = (undefined8 *)*puVar5) {
          if ((long *)puVar5[6] == plVar4) {
            cscfg_configfs_del_feature(puVar5 + -2);
            lVar3 = cscfg_mgr;
          }
        }
        mutex_lock(&cscfg_mutex);
        cscfg_unload_owned_cfgs_feats(plVar4);
      }
      uVar2 = __list_del_entry_valid(plVar4);
      if ((uVar2 & 1) != 0) {
        lVar3 = *plVar4;
        plVar1 = (long *)plVar4[1];
        *(long **)(lVar3 + 8) = plVar1;
        *plVar1 = lVar3;
      }
      *plVar4 = -0x2152ffffffffff00;
      plVar4[1] = -0x2152fffffffffede;
    } while (*(long *)(cscfg_mgr + 0x3c0) != cscfg_mgr + 0x3c0);
  }
  mutex_unlock(&cscfg_mutex);
  cscfg_configfs_release(cscfg_mgr);
  device_unregister(cscfg_mgr);
  return;
}



//------------------------------------------------------------
// cscfg_exit @ 00109228 size=28
// signature: undefined cscfg_exit(void)
// callers: [cleanup_module]
//------------------------------------------------------------

void cscfg_exit(void)

{
  cscfg_clear_device();
  return;
}



//------------------------------------------------------------
// cscfg_load_feat_csdev @ 00109244 size=396
// signature: undefined cscfg_load_feat_csdev(void)
// callers: [cscfg_load_config_sets, cscfg_register_csdev]
//------------------------------------------------------------

undefined8 cscfg_load_feat_csdev(long param_1,long param_2,long *param_3)

{
  long *plVar1;
  long *plVar2;
  uint uVar3;
  int iVar4;
  undefined1 auVar5 [16];
  long *plVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  code *pcVar10;
  undefined8 uVar11;
  
  if (*param_3 == 0) {
    return 0xffffffea;
  }
  uVar11 = *(undefined8 *)(param_1 + 0x98);
  plVar6 = (long *)devm_kmalloc(uVar11,0x48,0xdc0);
  if (plVar6 != (long *)0x0) {
    uVar3 = *(uint *)(param_2 + 0x24);
    *(uint *)(plVar6 + 5) = uVar3;
    if (uVar3 != 0) {
      if ((int)uVar3 < 0) {
        plVar6[6] = 0;
        return 0xfffffff4;
      }
      lVar7 = devm_kmalloc(uVar11,(ulong)uVar3 << 5,0xdc0);
      plVar6[6] = lVar7;
      if (lVar7 == 0) {
        return 0xfffffff4;
      }
      lVar9 = 0;
      lVar7 = 0;
      do {
        lVar7 = lVar7 + 1;
        *(long **)(plVar6[6] + lVar9) = plVar6;
        lVar9 = lVar9 + 0x20;
      } while (lVar7 < (int)plVar6[5]);
    }
    iVar4 = *(int *)(param_2 + 0x30);
    auVar5._8_8_ = 0;
    auVar5._0_8_ = (long)iVar4;
    *(int *)(plVar6 + 7) = iVar4;
    if (SUB168(auVar5 * ZEXT816(0x18),8) != 0) {
      plVar6[8] = 0;
      return 0xfffffff4;
    }
    lVar7 = devm_kmalloc(uVar11,(long)iVar4 * 0x18,0xdc0);
    plVar6[8] = lVar7;
    if (lVar7 != 0) {
      pcVar10 = (code *)*param_3;
      *plVar6 = param_2;
      plVar6[1] = param_1;
      if (*(int *)(pcVar10 + -4) != -0x20101f11) {
                    /* WARNING: Does not return */
        pcVar10 = (code *)SoftwareBreakpoint(0x8228,0x109334);
        (*pcVar10)();
      }
      uVar11 = (*pcVar10)(param_1,plVar6);
      if ((int)uVar11 != 0) {
        return uVar11;
      }
      cscfg_reset_feat(plVar6);
      uVar11 = _raw_spin_lock_irqsave(param_1 + 0x418);
      plVar1 = (long *)(param_1 + 0x3f8);
      lVar7 = *(long *)(param_1 + 0x3f8);
      plVar2 = plVar6 + 2;
      uVar8 = __list_add_valid(plVar2,plVar1,lVar7);
      if ((uVar8 & 1) != 0) {
        *(long **)(lVar7 + 8) = plVar2;
        plVar6[2] = lVar7;
        plVar6[3] = (long)plVar1;
        *plVar1 = (long)plVar2;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x418,uVar11);
      return 0;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// cscfg_add_csdev_cfg @ 001093d0 size=308
// signature: undefined cscfg_add_csdev_cfg(void)
// callers: [cscfg_load_config_sets, cscfg_register_csdev]
//------------------------------------------------------------

undefined8 cscfg_add_csdev_cfg(long param_1,long param_2)

{
  long *plVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  long *plVar5;
  char *__s2;
  long lVar6;
  ulong uVar7;
  long *plVar8;
  
  uVar7 = (ulong)*(uint *)(param_2 + 0x20);
  if (0 < (int)*(uint *)(param_2 + 0x20)) {
    lVar6 = 0;
    plVar5 = (long *)0x0;
    do {
      __s2 = *(char **)(*(long *)(param_2 + 0x28) + lVar6 * 8);
      plVar8 = (long *)(param_1 + 0x3f8);
      do {
        plVar8 = (long *)*plVar8;
        if (plVar8 == (long *)(param_1 + 0x3f8)) goto LAB_00109428;
        iVar3 = strcmp(*(char **)plVar8[-2],__s2);
      } while (iVar3 != 0);
      if (plVar8 + -2 != (long *)0x0) {
        if (plVar5 == (long *)0x0) {
          plVar5 = (long *)devm_kmalloc(*(undefined8 *)(param_1 + 0x98),
                                        (-(uVar7 >> 0x1f) & 0xfffffff800000000 | uVar7 << 3) + 0x30,
                                        0xdc0);
          if (plVar5 == (long *)0x0) {
            return 0xfffffff4;
          }
          *plVar5 = param_2;
          plVar5[1] = param_1;
        }
        lVar2 = plVar5[5];
        *(int *)(plVar5 + 5) = (int)lVar2 + 1;
        plVar5[(long)(int)lVar2 + 6] = (long)(plVar8 + -2);
        uVar7 = (ulong)*(uint *)(param_2 + 0x20);
      }
LAB_00109428:
      lVar6 = lVar6 + 1;
    } while (lVar6 < (int)uVar7);
    if (plVar5 != (long *)0x0) {
      uVar4 = _raw_spin_lock_irqsave(param_1 + 0x418);
      plVar8 = (long *)(param_1 + 0x408);
      lVar6 = *(long *)(param_1 + 0x408);
      plVar1 = plVar5 + 3;
      uVar7 = __list_add_valid(plVar1,plVar8,lVar6);
      if ((uVar7 & 1) != 0) {
        *(long **)(lVar6 + 8) = plVar1;
        plVar5[3] = lVar6;
        plVar5[4] = (long)plVar8;
        *plVar8 = (long)plVar1;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0x418,uVar4);
    }
  }
  return 0;
}



//------------------------------------------------------------
// cscfg_dev_release @ 00109508 size=72
// signature: undefined cscfg_dev_release(void)
// callers: []
//------------------------------------------------------------

void cscfg_dev_release(void)

{
  mutex_lock(&cscfg_mutex);
  kfree(cscfg_mgr);
  cscfg_mgr = 0;
  mutex_unlock(&cscfg_mutex);
  return;
}



//------------------------------------------------------------
// cscfg_reset_feat @ 00109554 size=228
// signature: undefined cscfg_reset_feat(void)
// callers: [cscfg_csdev_reset_feats, cscfg_load_feat_csdev]
//------------------------------------------------------------

void cscfg_reset_feat(long *param_1)

{
  undefined8 *puVar1;
  uint *puVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  if (0 < (int)param_1[5]) {
    lVar4 = 0;
    lVar5 = 0x10;
    lVar6 = 8;
    do {
      lVar4 = lVar4 + 1;
      puVar1 = (undefined8 *)(*(long *)(*param_1 + 0x28) + lVar6);
      lVar6 = lVar6 + 0x10;
      *(undefined8 *)(param_1[6] + lVar5) = *puVar1;
      lVar5 = lVar5 + 0x20;
    } while (lVar4 < (int)param_1[5]);
  }
  if (0 < (int)param_1[7]) {
    lVar5 = 0;
    lVar6 = 0;
    lVar4 = 0;
    do {
      lVar8 = *(long *)(*param_1 + 0x38);
      lVar7 = param_1[8];
      puVar2 = (uint *)(lVar7 + lVar5);
      *(char *)puVar2 = (char)*(undefined4 *)(lVar8 + lVar6);
      if ((*(byte *)(lVar8 + lVar6) >> 3 & 1) == 0) {
        *(undefined8 *)(puVar2 + 2) = *(undefined8 *)(lVar8 + lVar6 + 8);
      }
      else {
        lVar7 = lVar7 + lVar5;
        lVar8 = param_1[6] + (ulong)*(uint *)(lVar8 + lVar6 + 8) * 0x20;
        *(uint **)(lVar8 + 8) = puVar2;
        uVar3 = *puVar2;
        *(byte *)(lVar8 + 0x18) = (byte)(uVar3 >> 1) & 1;
        if ((uVar3 >> 1 & 1) == 0) {
          *(int *)(lVar7 + 8) = (int)*(undefined8 *)(lVar8 + 0x10);
        }
        else {
          *(undefined8 *)(lVar7 + 8) = *(undefined8 *)(lVar8 + 0x10);
        }
      }
      lVar4 = lVar4 + 1;
      lVar6 = lVar6 + 0x10;
      lVar5 = lVar5 + 0x18;
    } while (lVar4 < (int)param_1[7]);
  }
  return;
}



//------------------------------------------------------------
// cscfg_csdev_enable_config @ 0010963c size=368
// signature: undefined cscfg_csdev_enable_config(void)
// callers: [cscfg_csdev_enable_active_config]
//------------------------------------------------------------

undefined8 cscfg_csdev_enable_config(long *param_1,int param_2)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  
  if (param_2 == 0) {
    iVar6 = (int)param_1[5];
    if (0 < iVar6) {
      lVar7 = 0;
      do {
        lVar4 = param_1[lVar7 + 6];
        if (0 < *(int *)(lVar4 + 0x28)) {
          lVar9 = 0;
          lVar8 = 0;
          do {
            lVar10 = *(long *)(lVar4 + 0x30) + lVar9;
            if (*(char *)(lVar10 + 0x18) == '\0') {
              *(int *)(*(long *)(lVar10 + 8) + 8) = (int)*(undefined8 *)(lVar10 + 0x10);
            }
            else {
              *(undefined8 *)(*(long *)(lVar10 + 8) + 8) = *(undefined8 *)(lVar10 + 0x10);
            }
            lVar8 = lVar8 + 1;
            lVar9 = lVar9 + 0x20;
          } while (lVar8 < *(int *)(lVar4 + 0x28));
          iVar6 = (int)param_1[5];
        }
        lVar7 = lVar7 + 1;
      } while (lVar7 < iVar6);
    }
LAB_00109794:
    cscfg_prog_config(param_1,1);
    uVar3 = 0;
  }
  else {
    if (0 < param_2) {
      lVar7 = *param_1;
      if (param_2 <= *(int *)(lVar7 + 0x30)) {
        iVar6 = (int)param_1[5];
        if (0 < iVar6) {
          iVar2 = *(int *)(lVar7 + 0x34);
          lVar4 = 0;
          lVar7 = *(long *)(lVar7 + 0x38);
          iVar5 = 0;
          do {
            lVar8 = param_1[lVar4 + 6];
            if (*(int *)(lVar8 + 0x28) != 0) {
              if (0 < *(int *)(lVar8 + 0x28)) {
                lVar10 = 0;
                lVar9 = 0;
                do {
                  lVar1 = *(long *)(lVar8 + 0x30) + lVar10;
                  uVar3 = *(undefined8 *)
                           (lVar7 + (long)(iVar2 * (param_2 + -1)) * 8 +
                           (long)(iVar5 + (int)lVar9) * 8);
                  if (*(char *)(lVar1 + 0x18) == '\0') {
                    *(int *)(*(long *)(lVar1 + 8) + 8) = (int)uVar3;
                  }
                  else {
                    *(undefined8 *)(*(long *)(lVar1 + 8) + 8) = uVar3;
                  }
                  lVar9 = lVar9 + 1;
                  lVar10 = lVar10 + 0x20;
                } while (lVar9 < *(int *)(lVar8 + 0x28));
                iVar5 = iVar5 + (int)lVar9;
              }
              if (iVar2 <= iVar5) break;
              iVar6 = (int)param_1[5];
            }
            lVar4 = lVar4 + 1;
          } while (lVar4 < iVar6);
        }
        goto LAB_00109794;
      }
    }
    uVar3 = 0xffffffea;
  }
  return uVar3;
}



//------------------------------------------------------------
// cscfg_prog_config @ 001097ac size=312
// signature: undefined cscfg_prog_config(void)
// callers: [cscfg_csdev_enable_config]
//------------------------------------------------------------

void cscfg_prog_config(long param_1,ulong param_2)

{
  uint *puVar1;
  long lVar2;
  uint uVar3;
  undefined8 uVar4;
  long lVar5;
  long lVar6;
  uint *puVar7;
  uint uVar8;
  long lVar9;
  long lVar10;
  
  if (0 < *(int *)(param_1 + 0x28)) {
    lVar9 = 0;
    do {
      lVar10 = *(long *)(param_1 + lVar9 * 8 + 0x30);
      uVar4 = _raw_spin_lock_irqsave(*(undefined8 *)(lVar10 + 0x20));
      if ((param_2 & 1) == 0) {
        if (0 < *(int *)(lVar10 + 0x38)) {
          lVar5 = 0;
          lVar6 = 0;
          do {
            uVar8 = *(uint *)(*(long *)(lVar10 + 0x40) + lVar5);
            if ((uVar8 & 1) != 0) {
              lVar2 = *(long *)(lVar10 + 0x40) + lVar5;
              if ((uVar8 >> 1 & 1) == 0) {
                *(undefined4 *)(lVar2 + 8) = *(undefined4 *)*(undefined8 **)(lVar2 + 0x10);
              }
              else {
                *(undefined8 *)(lVar2 + 8) = **(undefined8 **)(lVar2 + 0x10);
              }
            }
            lVar6 = lVar6 + 1;
            lVar5 = lVar5 + 0x18;
          } while (lVar6 < *(int *)(lVar10 + 0x38));
        }
      }
      else if (0 < *(int *)(lVar10 + 0x38)) {
        lVar5 = 0;
        lVar6 = 0;
        do {
          puVar1 = (uint *)(*(long *)(lVar10 + 0x40) + lVar5);
          puVar7 = *(uint **)(puVar1 + 4);
          if ((*puVar1 >> 1 & 1) == 0) {
            uVar8 = puVar1[2];
            if ((*puVar1 >> 2 & 1) != 0) {
              uVar3 = *(uint *)(*(long *)(lVar10 + 0x40) + lVar5 + 0xc);
              uVar8 = *puVar7 & (uVar3 ^ 0xffffffff) | uVar3 & uVar8;
            }
            *puVar7 = uVar8;
          }
          else {
            *(undefined8 *)puVar7 = *(undefined8 *)(puVar1 + 2);
          }
          lVar6 = lVar6 + 1;
          lVar5 = lVar5 + 0x18;
        } while (lVar6 < *(int *)(lVar10 + 0x38));
      }
      _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar10 + 0x20),uVar4);
      lVar9 = lVar9 + 1;
    } while (lVar9 < *(int *)(param_1 + 0x28));
  }
  return;
}



//------------------------------------------------------------
// cscfg_csdev_disable_config @ 001098e8 size=196
// signature: undefined cscfg_csdev_disable_config(void)
// callers: [cscfg_csdev_disable_active_config]
//------------------------------------------------------------

void cscfg_csdev_disable_config(long param_1)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  
  if (0 < *(int *)(param_1 + 0x28)) {
    lVar6 = 0;
    do {
      lVar7 = *(long *)(param_1 + lVar6 * 8 + 0x30);
      uVar3 = _raw_spin_lock_irqsave(*(undefined8 *)(lVar7 + 0x20));
      if (0 < *(int *)(lVar7 + 0x38)) {
        lVar4 = 0;
        lVar5 = 0;
        do {
          uVar2 = *(uint *)(*(long *)(lVar7 + 0x40) + lVar4);
          if ((uVar2 & 1) != 0) {
            lVar1 = *(long *)(lVar7 + 0x40) + lVar4;
            if ((uVar2 >> 1 & 1) == 0) {
              *(undefined4 *)(lVar1 + 8) = *(undefined4 *)*(undefined8 **)(lVar1 + 0x10);
            }
            else {
              *(undefined8 *)(lVar1 + 8) = **(undefined8 **)(lVar1 + 0x10);
            }
          }
          lVar5 = lVar5 + 1;
          lVar4 = lVar4 + 0x18;
        } while (lVar5 < *(int *)(lVar7 + 0x38));
      }
      _raw_spin_unlock_irqrestore(*(undefined8 *)(lVar7 + 0x20),uVar3);
      lVar6 = lVar6 + 1;
    } while (lVar6 < *(int *)(param_1 + 0x28));
  }
  return;
}



//------------------------------------------------------------
// cscfg_preload @ 001099b0 size=56
// signature: undefined cscfg_preload(void)
// callers: [cscfg_init]
//------------------------------------------------------------

void cscfg_preload(undefined8 param_1)

{
  DAT_0010b450 = param_1;
  cscfg_load_config_sets(&preload_cfgs,&preload_feats);
  return;
}



//------------------------------------------------------------
// cscfg_configfs_add_config @ 001099ec size=416
// signature: undefined cscfg_configfs_add_config(void)
// callers: [cscfg_load_config_sets]
//------------------------------------------------------------

void cscfg_configfs_add_config(undefined8 *param_1)

{
  int *piVar1;
  long lVar2;
  long *plVar3;
  int *piVar4;
  ulong uVar5;
  undefined8 uVar6;
  long lVar7;
  long *plVar8;
  int param3;
  long *plVar9;
  char local_80 [24];
  long local_68;
  
  lVar2 = sp_el0;
  local_68 = *(long *)(lVar2 + 0x638);
  lVar2 = cscfg_device();
  if (lVar2 == 0) {
    plVar8 = (long *)0xffffffffffffffea;
  }
  else {
    plVar3 = (long *)devm_kmalloc(lVar2,0x98,0xdc0);
    if (plVar3 == (long *)0x0) {
LAB_00109b1c:
      plVar8 = (long *)0xfffffffffffffff4;
    }
    else {
      plVar8 = plVar3 + 1;
      uVar6 = *param_1;
      *plVar3 = (long)param_1;
      config_group_init_type_name(plVar8,uVar6,&cscfg_config_view_type);
      lVar2 = *plVar3;
      local_80[0x10] = '\0';
      local_80[0x11] = '\0';
      local_80[0x12] = '\0';
      local_80[0x13] = '\0';
      local_80[0] = '\0';
      local_80[1] = '\0';
      local_80[2] = '\0';
      local_80[3] = '\0';
      local_80[4] = '\0';
      local_80[5] = '\0';
      local_80[6] = '\0';
      local_80[7] = '\0';
      local_80[8] = '\0';
      local_80[9] = '\0';
      local_80[10] = '\0';
      local_80[0xb] = '\0';
      local_80[0xc] = '\0';
      local_80[0xd] = '\0';
      local_80[0xe] = '\0';
      local_80[0xf] = '\0';
      if (0 < *(int *)(lVar2 + 0x30)) {
        param3 = 1;
        do {
          uVar6 = cscfg_device();
          piVar4 = (int *)devm_kmalloc(uVar6,0x98,0xdc0);
          if (piVar4 == (int *)0x0) goto LAB_00109b1c;
          snprintf(local_80,0x14,"preset%d",param3);
          lVar7 = *plVar3;
          *piVar4 = param3;
          *(long *)(piVar4 + 2) = lVar7;
          config_group_init_type_name(piVar4 + 4,local_80,&cscfg_config_preset_type);
          plVar9 = (long *)plVar3[0xf];
          piVar1 = piVar4 + 0x22;
          uVar5 = __list_add_valid(piVar1,plVar9,plVar3 + 0xe);
          if ((uVar5 & 1) != 0) {
            plVar3[0xf] = (long)piVar1;
            *(long **)(piVar4 + 0x22) = plVar3 + 0xe;
            *(long **)(piVar4 + 0x24) = plVar9;
            *plVar9 = (long)piVar1;
          }
          param3 = param3 + 1;
        } while (param3 <= *(int *)(lVar2 + 0x30));
      }
      if (plVar8 < (long *)0xfffffffffffff001) {
        uVar5 = configfs_register_group(&cscfg_configs_grp,plVar8);
        if ((int)uVar5 == 0) {
          param_1[0xb] = plVar8;
        }
        goto LAB_00109b30;
      }
    }
  }
  uVar5 = (ulong)plVar8 & 0xffffffff;
LAB_00109b30:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar5);
  }
  return;
}



//------------------------------------------------------------
// cscfg_configfs_del_config @ 00109b90 size=52
// signature: undefined cscfg_configfs_del_config(void)
// callers: [cscfg_unload_config_sets, cscfg_load_config_sets, cscfg_clear_device]
//------------------------------------------------------------

void cscfg_configfs_del_config(long param_1)

{
  if (*(long *)(param_1 + 0x58) != 0) {
    configfs_unregister_group();
    *(undefined8 *)(param_1 + 0x58) = 0;
  }
  return;
}



//------------------------------------------------------------
// cscfg_configfs_add_feature @ 00109bc8 size=480
// signature: undefined cscfg_configfs_add_feature(void)
// callers: [cscfg_load_config_sets]
//------------------------------------------------------------

ulong cscfg_configfs_add_feature(undefined8 *param_1)

{
  undefined4 *puVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 *puVar5;
  ulong uVar6;
  undefined4 *puVar7;
  long lVar8;
  long *plVar9;
  long *plVar10;
  long lVar11;
  long lVar12;
  
  lVar2 = cscfg_device();
  if (lVar2 == 0) {
    plVar9 = (long *)0xffffffffffffffea;
    goto LAB_00109d60;
  }
  plVar3 = (long *)devm_kmalloc(lVar2,0x90,0xdc0);
  if (plVar3 != (long *)0x0) {
    if (*(int *)((long)param_1 + 0x24) == 0) {
      puVar5 = (undefined8 *)0x0;
      lVar2 = 0;
LAB_00109c64:
      uVar4 = *param_1;
      plVar9 = plVar3 + 1;
      *plVar3 = (long)param_1;
      config_group_init_type_name(plVar9,uVar4,&cscfg_feature_view_type);
      if (lVar2 != 0) {
        config_group_init_type_name(lVar2,"params",puVar5);
        plVar10 = (long *)plVar3[0xf];
        lVar11 = lVar2 + 0x78;
        uVar6 = __list_add_valid(lVar11,plVar10,plVar3 + 0xe);
        if ((uVar6 & 1) != 0) {
          plVar3[0xf] = lVar11;
          *(long **)(lVar2 + 0x78) = plVar3 + 0xe;
          *(long **)(lVar2 + 0x80) = plVar10;
          *plVar10 = lVar11;
        }
        uVar4 = cscfg_device();
        if (0 < *(int *)((long)param_1 + 0x24)) {
          lVar12 = 0;
          lVar11 = 0;
          do {
            puVar7 = (undefined4 *)devm_kmalloc(uVar4,0x98,0xdc0);
            if (puVar7 == (undefined4 *)0x0) goto LAB_00109d5c;
            lVar8 = param_1[5];
            *(undefined8 **)(puVar7 + 2) = param_1;
            *puVar7 = (int)lVar11;
            config_group_init_type_name
                      (puVar7 + 4,*(undefined8 *)(lVar8 + lVar12),&cscfg_param_view_type);
            plVar3 = *(long **)(lVar2 + 0x70);
            puVar1 = puVar7 + 0x22;
            uVar6 = __list_add_valid(puVar1,plVar3,lVar2 + 0x68);
            if ((uVar6 & 1) != 0) {
              *(undefined4 **)(lVar2 + 0x70) = puVar1;
              *(long *)(puVar7 + 0x22) = lVar2 + 0x68;
              *(long **)(puVar7 + 0x24) = plVar3;
              *plVar3 = (long)puVar1;
            }
            lVar11 = lVar11 + 1;
            lVar12 = lVar12 + 0x10;
          } while (lVar11 < *(int *)((long)param_1 + 0x24));
        }
      }
      if (plVar9 < (long *)0xfffffffffffff001) {
        uVar6 = configfs_register_group(&cscfg_features_grp,plVar9);
        if ((int)uVar6 == 0) {
          param_1[9] = plVar9;
          return uVar6;
        }
        return uVar6;
      }
      goto LAB_00109d60;
    }
    lVar2 = devm_kmalloc(lVar2,0x88,0xdc0);
    if (lVar2 != 0) {
      uVar4 = cscfg_device();
      puVar5 = (undefined8 *)devm_kmalloc(uVar4,0x28,0xdc0);
      if (puVar5 != (undefined8 *)0x0) {
        *puVar5 = &__this_module;
        goto LAB_00109c64;
      }
    }
  }
LAB_00109d5c:
  plVar9 = (long *)0xfffffffffffffff4;
LAB_00109d60:
  return (ulong)plVar9 & 0xffffffff;
}



//------------------------------------------------------------
// cscfg_configfs_del_feature @ 00109dac size=52
// signature: undefined cscfg_configfs_del_feature(void)
// callers: [cscfg_unload_config_sets, cscfg_load_config_sets, cscfg_clear_device]
//------------------------------------------------------------

void cscfg_configfs_del_feature(long param_1)

{
  if (*(long *)(param_1 + 0x48) != 0) {
    configfs_unregister_group();
    *(undefined8 *)(param_1 + 0x48) = 0;
  }
  return;
}



//------------------------------------------------------------
// cscfg_configfs_init @ 00109de4 size=296
// signature: undefined cscfg_configfs_init(void)
// callers: [cscfg_init]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 cscfg_configfs_init(long param_1)

{
  long lVar1;
  long lVar2;
  undefined8 uVar3;
  undefined8 *puVar4;
  ulong uVar5;
  
  if (param_1 == 0) {
    uVar3 = 0xffffffea;
  }
  else {
    uVar3 = cscfg_device();
    puVar4 = (undefined8 *)devm_kmalloc(uVar3,0x28,0xdc0);
    if (puVar4 == (undefined8 *)0x0) {
      uVar3 = 0xfffffff4;
    }
    else {
      lVar1 = param_1 + 0x3d8;
      *puVar4 = &__this_module;
      config_item_set_name(lVar1,"cs-syscfg");
      *(undefined8 **)(param_1 + 0x418) = puVar4;
      config_group_init(lVar1);
      __mutex_init(param_1 + 0x460,"&subsys->su_mutex",&cscfg_configfs_init___key);
      config_group_init(&cscfg_configs_grp);
      puVar4 = *(undefined8 **)(param_1 + 0x448);
      lVar2 = param_1 + 0x440;
      uVar5 = __list_add_valid(&DAT_0010ba98,puVar4,lVar2);
      if ((uVar5 & 1) != 0) {
        *(long **)(param_1 + 0x448) = &DAT_0010ba98;
        DAT_0010ba98 = lVar2;
        DAT_0010baa0 = puVar4;
        *puVar4 = &DAT_0010ba98;
      }
      config_group_init(&cscfg_features_grp);
      puVar4 = *(undefined8 **)(param_1 + 0x448);
      uVar5 = __list_add_valid(&DAT_0010bb20,puVar4,lVar2);
      if ((uVar5 & 1) != 0) {
        *(undefined **)(param_1 + 0x448) = &DAT_0010bb20;
        _DAT_0010bb20 = lVar2;
        _DAT_0010bb28 = puVar4;
        *puVar4 = &DAT_0010bb20;
      }
      uVar3 = configfs_register_subsystem(lVar1);
    }
  }
  return uVar3;
}



//------------------------------------------------------------
// cscfg_configfs_release @ 00109f10 size=32
// signature: undefined cscfg_configfs_release(void)
// callers: [cscfg_clear_device]
//------------------------------------------------------------

void cscfg_configfs_release(long param_1)

{
  configfs_unregister_subsystem(param_1 + 0x3d8);
  return;
}



//------------------------------------------------------------
// cscfg_cfg_description_show @ 00109f34 size=56
// signature: undefined cscfg_cfg_description_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_description_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010ae8d,*(undefined8 *)(*(long *)(param_1 + -8) + 8));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_cfg_feature_refs_show @ 00109f70 size=144
// signature: undefined cscfg_cfg_feature_refs_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_feature_refs_show(long param_1,long param_2)

{
  int iVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  
  lVar3 = *(long *)(param_1 + -8);
  if (*(int *)(lVar3 + 0x20) < 1) {
    lVar2 = 0;
  }
  else {
    lVar4 = 0;
    lVar2 = 0;
    do {
      iVar1 = scnprintf(param_2 + lVar2,0x1000 - lVar2,&DAT_0010b0b8,
                        *(undefined8 *)(*(long *)(lVar3 + 0x28) + lVar4 * 8));
      lVar2 = lVar2 + iVar1;
      lVar4 = lVar4 + 1;
    } while (lVar4 < *(int *)(lVar3 + 0x20));
  }
  return lVar2;
}



//------------------------------------------------------------
// cscfg_cfg_enable_show @ 0010a004 size=52
// signature: undefined cscfg_cfg_enable_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_enable_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010ae89,*(undefined1 *)(param_1 + 0x88));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_cfg_enable_store @ 0010a03c size=156
// signature: undefined cscfg_cfg_enable_store(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_enable_store(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  char local_2c [4];
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c[0] = '\0';
  iVar2 = kstrtobool(param_2,local_2c);
  if ((iVar2 == 0) &&
     (iVar2 = cscfg_config_sysfs_activate(*(undefined8 *)(param_1 + -8),local_2c[0]), iVar2 == 0)) {
    *(char *)(param_1 + 0x88) = local_2c[0];
    if (local_2c[0] != '\0') {
      cscfg_config_sysfs_set_preset(*(undefined4 *)(param_1 + 0x8c));
    }
  }
  else {
    param_3 = (long)iVar2;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// cscfg_cfg_preset_show @ 0010a0dc size=52
// signature: undefined cscfg_cfg_preset_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_preset_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010ae89,*(undefined4 *)(param_1 + 0x8c));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_cfg_preset_store @ 0010a114 size=168
// signature: undefined cscfg_cfg_preset_store(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_preset_store(long param_1,undefined8 param_2,long param_3)

{
  long lVar1;
  int iVar2;
  int local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_2,0,&local_2c);
  if (iVar2 == 0) {
    if ((0 < local_2c) && (local_2c <= *(int *)(*(long *)(param_1 + -8) + 0x30))) {
      *(int *)(param_1 + 0x8c) = local_2c;
      if (*(char *)(param_1 + 0x88) != '\0') {
        cscfg_config_sysfs_set_preset();
      }
      goto LAB_0010a178;
    }
    iVar2 = -0x16;
  }
  param_3 = (long)iVar2;
LAB_0010a178:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_3;
}



//------------------------------------------------------------
// cscfg_cfg_values_show @ 0010a1c0 size=316
// signature: undefined cscfg_cfg_values_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_cfg_values_show(long param_1,long param_2)

{
  int iVar1;
  int iVar2;
  undefined8 *puVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  
  lVar5 = *(long *)(param_1 + -8);
  if (*(int *)(lVar5 + 0x30) == 0) {
    lVar4 = 0;
  }
  else {
    if (*(int *)(lVar5 + 0x20) < 1) {
      lVar4 = 0;
    }
    else {
      lVar6 = 0;
      lVar4 = 0;
      iVar2 = *(int *)(lVar5 + 0x34) * (*(int *)(param_1 + -0x10) + -1);
      do {
        puVar3 = (undefined8 *)
                 cscfg_get_named_feat_desc(*(undefined8 *)(*(long *)(lVar5 + 0x28) + lVar6 * 8));
        if (0 < *(int *)((long)puVar3 + 0x24)) {
          lVar8 = 0;
          lVar7 = 0;
          do {
            iVar1 = scnprintf(param_2 + lVar4,0x1000 - lVar4,"%s.%s = 0x%llx ",*puVar3,
                              *(undefined8 *)(puVar3[5] + lVar8),
                              *(undefined8 *)
                               (*(long *)(lVar5 + 0x38) + (long)(iVar2 + (int)lVar7) * 8));
            lVar4 = lVar4 + iVar1;
            lVar7 = lVar7 + 1;
            lVar8 = lVar8 + 0x10;
          } while (lVar7 < *(int *)((long)puVar3 + 0x24));
          iVar2 = iVar2 + (int)lVar7;
        }
        lVar6 = lVar6 + 1;
      } while (lVar6 < *(int *)(lVar5 + 0x20));
    }
    iVar2 = scnprintf(param_2 + lVar4,0x1000 - lVar4,&DAT_0010b12b);
    lVar4 = lVar4 + iVar2;
  }
  return lVar4;
}



//------------------------------------------------------------
// cscfg_feat_description_show @ 0010a300 size=56
// signature: undefined cscfg_feat_description_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_feat_description_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010ae8d,*(undefined8 *)(*(long *)(param_1 + -8) + 8));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_feat_matches_show @ 0010a33c size=168
// signature: undefined cscfg_feat_matches_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_feat_matches_show(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(*(long *)(param_1 + -8) + 0x20);
  if ((uVar1 & 1) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = scnprintf(param_2,0x1000,"SRC_ALL ");
  }
  if ((uVar1 >> 1 & 1) != 0) {
    iVar3 = scnprintf(param_2 + iVar2,0x1000 - (long)iVar2,"SRC_ETMV4 ");
    iVar2 = iVar3 + iVar2;
  }
  iVar3 = scnprintf(param_2 + iVar2,0x1000 - (long)iVar2,&DAT_0010b12b);
  return (long)(iVar3 + iVar2);
}



//------------------------------------------------------------
// cscfg_feat_nr_params_show @ 0010a3e8 size=56
// signature: undefined cscfg_feat_nr_params_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_feat_nr_params_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,&DAT_0010ae89,*(undefined4 *)(*(long *)(param_1 + -8) + 0x24));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_param_value_show @ 0010a424 size=68
// signature: undefined cscfg_param_value_show(void)
// callers: []
//------------------------------------------------------------

long cscfg_param_value_show(long param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = scnprintf(param_2,0x1000,"0x%llx\n",
                    *(undefined8 *)
                     (*(long *)(*(long *)(param_1 + -8) + 0x28) +
                      (long)*(int *)(param_1 + -0x10) * 0x10 + 8));
  return (long)iVar1;
}



//------------------------------------------------------------
// cscfg_param_value_store @ 0010a46c size=148
// signature: undefined cscfg_param_value_store(void)
// callers: []
//------------------------------------------------------------

void cscfg_param_value_store(long param_1,undefined8 param_2,long param_3)

{
  undefined4 uVar1;
  long lVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  uVar4 = *(undefined8 *)(param_1 + -8);
  local_40 = 0;
  uVar1 = *(undefined4 *)(param_1 + -0x10);
  iVar3 = kstrtoull(param_2,0,&local_40);
  if (iVar3 == 0) {
    iVar3 = cscfg_update_feat_param_val(uVar4,uVar1,local_40);
  }
  lVar2 = sp_el0;
  if (iVar3 != 0) {
    param_3 = (long)iVar3;
  }
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_3);
  }
  return;
}



//------------------------------------------------------------
// init_module @ 0010a938 size=104
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = bus_register(&coresight_bustype);
  if (iVar1 == 0) {
    iVar1 = etm_perf_init();
    if (iVar1 == 0) {
      iVar1 = cscfg_init();
      if (iVar1 == 0) {
        return 0;
      }
      etm_perf_exit();
    }
    bus_unregister(&coresight_bustype);
  }
  return iVar1;
}



//------------------------------------------------------------
// etm_perf_init @ 0010a9a4 size=220
// signature: undefined etm_perf_init(void)
// callers: [init_module]
//------------------------------------------------------------

void etm_perf_init(void)

{
  int iVar1;
  
  DAT_0010b32c = 0x30;
  DAT_0010b310 = &etm_pmu_attr_groups;
  DAT_0010b344 = 1;
  DAT_0010b360 = etm_event_init;
  DAT_0010b3d8 = etm_setup_aux;
  DAT_0010b3e0 = etm_free_aux;
  DAT_0010b390 = etm_event_stop;
  DAT_0010b398 = etm_event_read;
  DAT_0010b378 = etm_event_add;
  DAT_0010b380 = etm_event_del;
  DAT_0010b388 = etm_event_start;
  DAT_0010b34c = 8;
  DAT_0010b3f0 = etm_addr_filters_validate;
  DAT_0010b3f8 = etm_addr_filters_sync;
  DAT_0010b300 = &__this_module;
  iVar1 = perf_pmu_register(&etm_pmu,"cs_etm",0xffffffff);
  if (iVar1 == 0) {
    etm_perf_up = 1;
  }
  return;
}



//------------------------------------------------------------
// cscfg_init @ 0010aa84 size=304
// signature: undefined cscfg_init(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cscfg_init(void)

{
  int iVar1;
  long lVar2;
  
  mutex_lock(&cscfg_mutex);
  if (cscfg_mgr == 0) {
    lVar2 = kmalloc_trace(_fwnode_handle_put,0xdc0,0x4a0);
    cscfg_mgr = lVar2;
    if (lVar2 == 0) {
      iVar1 = -0xc;
    }
    else {
      *(long *)(lVar2 + 0x390) = lVar2 + 0x390;
      *(long *)(lVar2 + 0x398) = lVar2 + 0x390;
      *(long *)(lVar2 + 0x3a0) = lVar2 + 0x3a0;
      *(long *)(lVar2 + 0x3a8) = lVar2 + 0x3a0;
      *(long *)(lVar2 + 0x3b0) = lVar2 + 0x3b0;
      *(long *)(lVar2 + 0x3b8) = lVar2 + 0x3b0;
      *(long *)(lVar2 + 0x3c0) = lVar2 + 0x3c0;
      *(long *)(lVar2 + 0x3c8) = lVar2 + 0x3c0;
      *(undefined4 *)(lVar2 + 0x3d0) = 0;
      *(code **)(lVar2 + 0x328) = cscfg_dev_release;
      *(undefined4 *)(lVar2 + 0x498) = 0;
      *(char **)(lVar2 + 0x70) = "cs_system_cfg";
      iVar1 = device_register();
      if (iVar1 == 0) {
        mutex_unlock(&cscfg_mutex);
        iVar1 = cscfg_configfs_init(cscfg_mgr);
        if (iVar1 == 0) {
          iVar1 = cscfg_preload(&__this_module);
          if (iVar1 == 0) {
            _dev_info(cscfg_mgr,"CoreSight Configuration manager initialised");
            return 0;
          }
        }
        cscfg_clear_device();
        return iVar1;
      }
      put_device(lVar2);
    }
  }
  else {
    iVar1 = -0x16;
  }
  mutex_unlock(&cscfg_mutex);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 0010abb8 size=44
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  cscfg_exit();
  etm_perf_exit();
  bus_unregister(&coresight_bustype);
  return;
}



//------------------------------------------------------------
// __pm_runtime_resume @ 0010e000 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [coresight_grab_device, coresight_simple_show32, coresight_simple_show_pair]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 0010e008 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [coresight_grab_device, coresight_simple_show32, coresight_release_path, coresight_simple_show_pair]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 0010e010 size=1
// signature: undefined sysfs_emit(void)
// callers: [coresight_simple_show32, coresight_simple_show_pair]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 0010e020 size=1
// signature: undefined mutex_lock(void)
// callers: [coresight_disable, cscfg_config_sysfs_set_preset, cscfg_config_sysfs_activate, coresight_alloc_device_name, reset_source_sink_store, coresight_enable, cscfg_load_config_sets, cscfg_clear_device, cscfg_activate_config, cscfg_update_feat_param_val, enable_source_store, coresight_register, cscfg_unregister_csdev, cscfg_get_named_feat_desc, cscfg_dev_release, cscfg_unload_config_sets, cscfg_config_sysfs_get_active_cfg, cscfg_init, coresight_set_assoc_ectdev_mutex, cscfg_deactivate_config, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 0010e028 size=1
// signature: undefined mutex_unlock(void)
// callers: [coresight_disable, cscfg_config_sysfs_set_preset, cscfg_config_sysfs_activate, coresight_alloc_device_name, reset_source_sink_store, coresight_enable, cscfg_load_config_sets, cscfg_clear_device, cscfg_activate_config, cscfg_update_feat_param_val, enable_source_store, coresight_register, cscfg_unregister_csdev, cscfg_get_named_feat_desc, cscfg_dev_release, cscfg_unload_config_sets, cscfg_config_sysfs_get_active_cfg, cscfg_init, coresight_set_assoc_ectdev_mutex, cscfg_deactivate_config, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// put_device @ 0010e030 size=1
// signature: undefined put_device(void)
// callers: [coresight_disable_path_from, coresight_grab_device, __coresight_disable, coresight_get_platform_data, coresight_find_csdev_by_fwnode, coresight_register, coresight_release_path, coresight_enable_path, coresight_control_assoc_ectdev, coresight_enable_source, cscfg_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void put_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// module_put @ 0010e038 size=1
// signature: undefined module_put(void)
// callers: [coresight_disable_path_from, __coresight_disable, coresight_release_path, coresight_enable_path, cscfg_config_sysfs_activate, coresight_control_assoc_ectdev, cscfg_load_config_sets, coresight_grab_device, cscfg_csdev_enable_active_config, cscfg_unload_config_sets, coresight_enable_source, cscfg_csdev_disable_active_config, cscfg_deactivate_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void module_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 0010e040 size=1
// signature: undefined _dev_info(void)
// callers: [coresight_disable_path_from, __coresight_disable, coresight_enable_path, coresight_control_assoc_ectdev, coresight_enable_source, cscfg_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 0010e048 size=1
// signature: undefined __kmalloc(void)
// callers: [coresight_set_csr_atid, coresight_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 0010e050 size=1
// signature: undefined kfree(void)
// callers: [coresight_set_csr_atid, __coresight_disable, etm_setup_aux, coresight_device_release, coresight_release_path, coresight_enable, coresight_register, coresight_build_path, cscfg_unregister_csdev, cscfg_dev_release, etm_event_destroy, free_event_data, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 0010e058 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [coresight_set_csr_atid, coresight_find_sink, coresight_get_platform_data, sink_name_store, cscfg_cfg_preset_store, coresight_get_sink_by_id, coresight_alloc_device_name, enable_sink_store, reset_source_sink_store, coresight_get_cpu, enable_source_store, cscfg_cfg_enable_store, etm_perf_symlink, cscfg_param_value_store, cscfg_configfs_add_config, coresight_find_default_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_find_device @ 0010e060 size=1
// signature: undefined bus_find_device(void)
// callers: [coresight_get_platform_data, coresight_find_csdev_by_fwnode, sink_name_store, coresight_get_sink_by_id, enable_sink_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_find_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 0010e070 size=1
// signature: undefined kmalloc_trace(void)
// callers: [etm_setup_aux, coresight_register, coresight_build_path, _coresight_build_path, coresight_enable, cscfg_init, coresight_store_path, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 0010e078 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [coresight_find_link_outport, coresight_find_link_inport, _coresight_build_path, cscfg_get_named_feat_desc, cscfg_add_csdev_cfg, cscfg_load_config_sets]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 0010e080 size=1
// signature: undefined __list_add_valid(void)
// callers: [cscfg_configfs_init, cscfg_configfs_add_feature, cscfg_load_feat_csdev, _coresight_build_path, cscfg_add_csdev_cfg, cscfg_configfs_add_config, cscfg_load_config_sets, coresight_store_path, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 0010e088 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [__coresight_disable, cscfg_unregister_csdev, cscfg_unload_owned_cfgs_feats, coresight_release_path, cscfg_unload_config_sets, cscfg_load_config_sets, cscfg_clear_device, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 0010e098 size=1
// signature: undefined _dev_err(void)
// callers: [coresight_find_link_outport, __coresight_disable, enable_source_store, sink_name_store, coresight_find_link_inport, enable_sink_store, coresight_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 0010e0a0 size=1
// signature: undefined _printk(void)
// callers: [coresight_enable, cscfg_load_config_sets, cscfg_clear_device, cscfg_register_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_for_each_dev @ 0010e0a8 size=1
// signature: undefined bus_for_each_dev(void)
// callers: [coresight_register, coresight_unregister, reset_source_sink_store, coresight_enable_source]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_for_each_dev(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 0010e0b0 size=1
// signature: undefined _dev_warn(void)
// callers: [coresight_get_platform_data, coresight_enable_source]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 0010e0b8 size=1
// signature: undefined __const_udelay(void)
// callers: [coresight_timeout, coresight_timeout_action]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_handle_put @ 0010e0c0 size=1
// signature: undefined fwnode_handle_put(void)
// callers: [coresight_release_platform_data, coresight_register, coresight_device_release, coresight_unregister]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_handle_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 0010e0c8 size=1
// signature: undefined dev_fwnode(void)
// callers: [coresight_get_platform_data, coresight_register, coresight_alloc_device_name, coresight_loses_context_with_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_handle_get @ 0010e0d0 size=1
// signature: undefined fwnode_handle_get(void)
// callers: [coresight_get_platform_data, coresight_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_handle_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_set_name @ 0010e0d8 size=1
// signature: undefined dev_set_name(void)
// callers: [coresight_register]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_register @ 0010e0e0 size=1
// signature: undefined device_register(void)
// callers: [coresight_register, cscfg_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_unregister @ 0010e0e8 size=1
// signature: undefined device_unregister(void)
// callers: [coresight_register, coresight_unregister, cscfg_clear_device]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_present @ 0010e0f0 size=1
// signature: undefined fwnode_property_present(void)
// callers: [coresight_loses_context_with_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_string @ 0010e0f8 size=1
// signature: undefined of_property_read_string(void)
// callers: [coresight_get_platform_data, coresight_alloc_device_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 0010e100 size=1
// signature: undefined devm_kasprintf(void)
// callers: [coresight_make_links, coresight_alloc_device_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// krealloc @ 0010e108 size=1
// signature: undefined krealloc(void)
// callers: [coresight_alloc_device_name]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void krealloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_register @ 0010e110 size=1
// signature: undefined bus_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bus_unregister @ 0010e118 size=1
// signature: undefined bus_unregister(void)
// callers: [cleanup_module, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bus_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 0010e120 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl, readq, readq_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 0010e128 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl, readq, readq_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 0010e130 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel, writeq_relaxed, writeq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 0010e138 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel, writeq_relaxed, writeq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// try_module_get @ 0010e140 size=1
// signature: undefined try_module_get(void)
// callers: [coresight_grab_device, cscfg_csdev_enable_active_config, _cscfg_activate_config, coresight_control_assoc_ectdev, cscfg_load_config_sets]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void try_module_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// get_device @ 0010e148 size=1
// signature: undefined get_device(void)
// callers: [coresight_grab_device, coresight_control_assoc_ectdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void get_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 0010e150 size=1
// signature: undefined scnprintf(void)
// callers: [sink_name_show, cscfg_cfg_description_show, cscfg_cfg_values_show, cscfg_cfg_feature_refs_show, enable_source_show, etm_perf_cscfg_event_show, cscfg_feat_nr_params_show, cscfg_cfg_preset_show, cscfg_cfg_enable_show, cscfg_feat_description_show, cscfg_feat_matches_show, etm_perf_sink_name_show, enable_sink_show, cscfg_param_value_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 0010e158 size=1
// signature: undefined kstrtoull(void)
// callers: [enable_source_store, cscfg_param_value_store, enable_sink_store, reset_source_sink_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 0010e160 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [sink_name_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// hashlen_string @ 0010e168 size=1
// signature: undefined hashlen_string(void)
// callers: [etm_perf_add_symlink_cscfg, sink_name_store, etm_perf_add_symlink_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void hashlen_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 0010e170 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [format_attr_contextid_show, etm_perf_symlink, nr_links_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_link @ 0010e178 size=1
// signature: undefined sysfs_create_link(void)
// callers: [etm_perf_symlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_link @ 0010e180 size=1
// signature: undefined sysfs_remove_link(void)
// callers: [etm_perf_symlink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 0010e188 size=1
// signature: undefined devm_kmalloc(void)
// callers: [etm_perf_add_symlink_cscfg, cscfg_configfs_init, coresight_get_platform_data, cscfg_configfs_add_feature, cscfg_load_feat_csdev, coresight_make_links, cscfg_add_csdev_cfg, etm_perf_add_symlink_sink, cscfg_configfs_add_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 0010e190 size=1
// signature: undefined devm_kstrdup(void)
// callers: [etm_perf_add_symlink_cscfg, etm_perf_add_symlink_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_add_file_to_group @ 0010e198 size=1
// signature: undefined sysfs_add_file_to_group(void)
// callers: [etm_perf_add_symlink_cscfg, etm_perf_add_symlink_sink]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_add_file_to_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_file_from_group @ 0010e1a0 size=1
// signature: undefined sysfs_remove_file_from_group(void)
// callers: [etm_perf_del_symlink_sink, etm_perf_del_symlink_cscfg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_file_from_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_pmu_register @ 0010e1a8 size=1
// signature: undefined perf_pmu_register(void)
// callers: [etm_perf_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_pmu_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_node_trace @ 0010e1b0 size=1
// signature: undefined kmalloc_node_trace(void)
// callers: [etm_event_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_node_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 0010e1b8 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [etm_setup_aux, etm_event_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __alloc_percpu @ 0010e1d0 size=1
// signature: undefined __alloc_percpu(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __alloc_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 0010e1d8 size=1
// signature: undefined _find_next_bit(void)
// callers: [etm_setup_aux, free_event_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 0010e1e0 size=1
// signature: undefined _find_first_bit(void)
// callers: [etm_setup_aux, free_event_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_work_on @ 0010e1f0 size=1
// signature: undefined queue_work_on(void)
// callers: [etm_setup_aux, etm_free_aux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 0010e1f8 size=1
// signature: undefined fortify_panic(void)
// callers: [etm_setup_aux]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_aux_output_begin @ 0010e208 size=1
// signature: undefined perf_aux_output_begin(void)
// callers: [etm_event_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_aux_output_begin(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_aux_output_flag @ 0010e210 size=1
// signature: undefined perf_aux_output_flag(void)
// callers: [etm_event_start]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_aux_output_flag(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_aux_output_end @ 0010e218 size=1
// signature: undefined perf_aux_output_end(void)
// callers: [etm_event_start, etm_event_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_aux_output_end(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_get_aux @ 0010e220 size=1
// signature: undefined perf_get_aux(void)
// callers: [etm_event_stop]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_get_aux(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_pmu_unregister @ 0010e228 size=1
// signature: undefined perf_pmu_unregister(void)
// callers: [etm_perf_exit]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_pmu_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_percpu @ 0010e230 size=1
// signature: undefined free_percpu(void)
// callers: [free_event_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_percpu(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 0010e240 size=1
// signature: undefined of_find_property(void)
// callers: [of_coresight_secure_node, coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 0010e248 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [of_coresight_get_atid, of_coresight_get_csr_atid_offset]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_count_elems_of_size @ 0010e250 size=1
// signature: undefined of_property_count_elems_of_size(void)
// callers: [of_coresight_get_atid_number]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_count_elems_of_size(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 0010e260 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [coresight_get_platform_data, coresight_get_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_cpu_node_to_id @ 0010e268 size=1
// signature: undefined of_cpu_node_to_id(void)
// callers: [coresight_get_cpu]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_cpu_node_to_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_child_by_name @ 0010e270 size=1
// signature: undefined of_get_child_by_name(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_child_by_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_get_next_endpoint @ 0010e278 size=1
// signature: undefined of_graph_get_next_endpoint(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_get_next_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_parse_endpoint @ 0010e280 size=1
// signature: undefined of_graph_parse_endpoint(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_parse_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_is_present @ 0010e288 size=1
// signature: undefined of_graph_is_present(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_is_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_get_remote_endpoint @ 0010e290 size=1
// signature: undefined of_graph_get_remote_endpoint(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_get_remote_endpoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_graph_get_port_parent @ 0010e298 size=1
// signature: undefined of_graph_get_port_parent(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_graph_get_port_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_node_name_eq @ 0010e2a0 size=1
// signature: undefined of_node_name_eq(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_node_name_eq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_get_next_parent @ 0010e2a8 size=1
// signature: undefined of_get_next_parent(void)
// callers: [coresight_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_get_next_parent(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_create_group @ 0010e2c0 size=1
// signature: undefined sysfs_create_group(void)
// callers: [coresight_create_conns_sysfs_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_create_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_group @ 0010e2c8 size=1
// signature: undefined sysfs_remove_group(void)
// callers: [coresight_remove_conns_sysfs_group]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_add_link_to_group @ 0010e2d0 size=1
// signature: undefined sysfs_add_link_to_group(void)
// callers: [coresight_add_sysfs_link]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_add_link_to_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_remove_link_from_group @ 0010e2d8 size=1
// signature: undefined sysfs_remove_link_from_group(void)
// callers: [coresight_remove_sysfs_link, coresight_add_sysfs_link, coresight_remove_links]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_remove_link_from_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kfree @ 0010e2e0 size=1
// signature: undefined devm_kfree(void)
// callers: [coresight_remove_links]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 0010e2e8 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cscfg_csdev_disable_config, cscfg_csdev_reset_feats, cscfg_load_feat_csdev, cscfg_csdev_enable_active_config, cscfg_prog_config, cscfg_add_csdev_cfg, cscfg_csdev_disable_active_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 0010e2f0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cscfg_csdev_disable_config, cscfg_csdev_reset_feats, cscfg_load_feat_csdev, cscfg_csdev_enable_active_config, cscfg_prog_config, cscfg_add_csdev_cfg, cscfg_csdev_disable_active_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init_type_name @ 0010e2f8 size=1
// signature: undefined config_group_init_type_name(void)
// callers: [cscfg_configfs_add_feature, cscfg_configfs_add_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init_type_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 0010e300 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [cscfg_configfs_add_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_register_group @ 0010e308 size=1
// signature: undefined configfs_register_group(void)
// callers: [cscfg_configfs_add_feature, cscfg_configfs_add_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_register_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_unregister_group @ 0010e310 size=1
// signature: undefined configfs_unregister_group(void)
// callers: [cscfg_configfs_del_feature, cscfg_configfs_del_config]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_unregister_group(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_item_set_name @ 0010e318 size=1
// signature: undefined config_item_set_name(void)
// callers: [cscfg_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_item_set_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// config_group_init @ 0010e320 size=1
// signature: undefined config_group_init(void)
// callers: [cscfg_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void config_group_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 0010e328 size=1
// signature: undefined __mutex_init(void)
// callers: [cscfg_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_register_subsystem @ 0010e330 size=1
// signature: undefined configfs_register_subsystem(void)
// callers: [cscfg_configfs_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_register_subsystem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// configfs_unregister_subsystem @ 0010e338 size=1
// signature: undefined configfs_unregister_subsystem(void)
// callers: [cscfg_configfs_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void configfs_unregister_subsystem(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtobool @ 0010e340 size=1
// signature: undefined kstrtobool(void)
// callers: [cscfg_cfg_enable_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtobool(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 0010e348 size=1
// signature: undefined kstrtoint(void)
// callers: [cscfg_cfg_preset_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



