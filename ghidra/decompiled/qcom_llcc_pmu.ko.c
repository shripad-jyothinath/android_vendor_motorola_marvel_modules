// Decompiled by Ghidra 12.2
// Program: qcom_llcc_pmu.ko
// Image base: 00100000

//------------------------------------------------------------
// qcom_llcc_pmu_hw_type @ 0010033c size=40
// signature: undefined qcom_llcc_pmu_hw_type(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_llcc_pmu_hw_type(int *param_1)

{
  if ((llccpmu == 0) || (*(int *)(llccpmu + 0x38) == 0)) {
    return 0xfffffdfb;
  }
  *param_1 = *(int *)(llccpmu + 0x38);
  return 0;
}



//------------------------------------------------------------
// qcom_llcc_pmu_probe @ 00100368 size=636
// signature: undefined qcom_llcc_pmu_probe(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void qcom_llcc_pmu_probe(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  code *pcVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  ulong uVar8;
  undefined4 local_5c;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  lVar1 = param_1 + 0x10;
  local_5c = 0;
  if (llccpmu == (undefined8 *)0x0) {
    llccpmu = (undefined8 *)devm_kmalloc(lVar1,0x578,0xdc0);
    if (llccpmu == (undefined8 *)0x0) {
      uVar4 = 0xfffffff4;
    }
    else {
      iVar5 = of_device_get_match_data(lVar1);
      puVar2 = llccpmu;
      *(int *)(llccpmu + 0xae) = iVar5;
      if (iVar5 == 0) {
        _printk(&DAT_001011b6);
        uVar4 = 0xffffffed;
      }
      else {
        puVar2[10] = 0xffffffff00000000;
        puVar2[0xb] = 0;
        puVar2[8] = 0;
        puVar2[9] = 0;
        puVar2[6] = 0;
        puVar2[7] = 0;
        puVar2[0xe] = qcom_llcc_event_init;
        puVar2[0xf] = 0;
        puVar2[4] = 0;
        puVar2[5] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        *puVar2 = 0;
        puVar2[1] = 0;
        puVar2[0x10] = 0;
        puVar2[0x11] = qcom_llcc_event_add;
        puVar2[0xc] = 0;
        puVar2[0xd] = 0;
        puVar2[0x16] = 0;
        puVar2[0x17] = 0;
        puVar2[0x18] = 0;
        puVar2[0x19] = 0;
        puVar2[0x12] = qcom_llcc_event_del;
        puVar2[0x13] = qcom_llcc_event_start;
        puVar2[0x1a] = 0;
        puVar2[0x1b] = 0;
        puVar2[0x1c] = 0;
        puVar2[0x1d] = 0;
        puVar2[0x1e] = 0;
        puVar2[0x1f] = 0;
        puVar2[0x14] = qcom_llcc_event_stop;
        puVar2[0x15] = qcom_llcc_event_read;
        puVar2[0x20] = 0;
        puVar2[0x21] = 0;
        puVar2[0x22] = 0;
        puVar2[0x23] = 0;
        puVar2[0x24] = 0;
        uVar7 = platform_get_resource_byname(param_1,0x200,"lagg-base");
        uVar8 = devm_ioremap_resource(lVar1,uVar7);
        puVar2 = llccpmu;
        llccpmu[0x27] = uVar8;
        if (uVar8 < 0xfffffffffffff001) {
          counter_lock = 0;
          users_lock = 0;
          iVar5 = perf_pmu_register(puVar2,"llcc-pmu",0xffffffff);
          if (iVar5 < 0) {
            _dev_err(lVar1,"Failed to register LLCC PMU (%d)\n",iVar5);
          }
          iVar5 = 0;
          while( true ) {
            uVar6 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,iVar5);
            if (_nr_cpu_ids <= uVar6) break;
            smp_call_function_single(uVar6,get_mpidr_cpu,&local_5c,1);
            if (0x1f < (ulong)uVar6) {
                    /* WARNING: Does not return */
              pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x1005e0);
              (*pcVar3)();
            }
            iVar5 = uVar6 + 1;
            *(undefined4 *)(phys_cpu + (ulong)uVar6 * 4) = local_5c;
          }
          _dev_info(lVar1,"Registered llcc_pmu, type: %d\n",*(undefined4 *)(llccpmu + 7));
          uVar4 = 0;
        }
        else {
          _dev_err(lVar1,"Can\'t map PMU lagg base: @%pa\n",uVar7);
          uVar4 = *(undefined4 *)(llccpmu + 0x27);
        }
      }
    }
  }
  else {
    _dev_err(lVar1,"Only one LLCC PMU allowed!\n");
    uVar4 = 0xffffffed;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar4);
  }
  return;
}



//------------------------------------------------------------
// qcom_llcc_event_init @ 001005e8 size=36
// signature: undefined qcom_llcc_event_init(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_llcc_event_init(long param_1)

{
  if (*(long *)(param_1 + 0xe0) == 0x1000) {
    *(undefined8 *)(param_1 + 0x170) = 0x1000;
    return 0;
  }
  return 0xfffffffe;
}



//------------------------------------------------------------
// qcom_llcc_event_add @ 00100610 size=228
// signature: undefined qcom_llcc_event_add(void)
// callers: []
//------------------------------------------------------------

undefined8 qcom_llcc_event_add(long param_1,uint param_2)

{
  int iVar1;
  code *pcVar2;
  ulong uVar3;
  undefined4 uVar4;
  
  _raw_spin_lock(&users_lock);
  if (*(int *)(llccpmu + 0x570) == 1) {
    if (users == 0) {
      mon_enable(*(undefined4 *)(param_1 + 0x28c));
    }
    users = users + 1;
  }
  else {
    uVar3 = (ulong)*(uint *)(param_1 + 0x28c);
    if (0x1f < *(uint *)(param_1 + 0x28c)) {
LAB_001006f0:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1006f4);
      (*pcVar2)();
    }
    iVar1 = *(int *)(&users_alive + *(long *)(&__per_cpu_offset + uVar3 * 8));
    if (iVar1 == 0) {
      mon_enable();
      uVar3 = (ulong)*(uint *)(param_1 + 0x28c);
      if (0x1f < *(uint *)(param_1 + 0x28c)) goto LAB_001006f0;
    }
    *(int *)(&users_alive + *(long *)(&__per_cpu_offset + uVar3 * 8)) = iVar1 + 1;
  }
  _raw_spin_unlock(&users_lock);
  uVar4 = 3;
  if ((param_2 & 1) != 0) {
    uVar4 = 0;
  }
  *(undefined4 *)(param_1 + 0x1d8) = uVar4;
  return 0;
}



//------------------------------------------------------------
// qcom_llcc_event_del @ 001006f8 size=192
// signature: undefined qcom_llcc_event_del(void)
// callers: []
//------------------------------------------------------------

void qcom_llcc_event_del(long param_1)

{
  int iVar1;
  code *pcVar2;
  ulong uVar3;
  
  _raw_spin_lock(&users_lock);
  if (*(int *)(llccpmu + 0x570) == 1) {
    users = users + -1;
    if (users == 0) {
      mon_disable(*(undefined4 *)(param_1 + 0x28c));
    }
  }
  else {
    uVar3 = (ulong)*(uint *)(param_1 + 0x28c);
    if (0x1f < *(uint *)(param_1 + 0x28c)) {
LAB_001007b4:
                    /* WARNING: Does not return */
      pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1007b8);
      (*pcVar2)();
    }
    iVar1 = *(int *)(&users_alive + *(long *)(&__per_cpu_offset + uVar3 * 8));
    if (iVar1 + -1 == 0) {
      mon_disable();
      uVar3 = (ulong)*(uint *)(param_1 + 0x28c);
      if (0x1f < *(uint *)(param_1 + 0x28c)) goto LAB_001007b4;
    }
    *(int *)(&users_alive + *(long *)(&__per_cpu_offset + uVar3 * 8)) = iVar1 + -1;
  }
  _raw_spin_unlock(&users_lock);
  return;
}



//------------------------------------------------------------
// qcom_llcc_event_start @ 001007bc size=24
// signature: undefined qcom_llcc_event_start(void)
// callers: []
//------------------------------------------------------------

void qcom_llcc_event_start(long param_1,uint param_2)

{
  code *pcVar1;
  
  if (((param_2 >> 1 & 1) != 0) && ((*(byte *)(param_1 + 0x1d8) >> 1 & 1) == 0)) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x800,0x1007d4);
    (*pcVar1)();
  }
  *(undefined4 *)(param_1 + 0x1d8) = 0;
  return;
}



//------------------------------------------------------------
// qcom_llcc_event_stop @ 001007e0 size=52
// signature: undefined qcom_llcc_event_stop(void)
// callers: []
//------------------------------------------------------------

void qcom_llcc_event_stop(long param_1)

{
  qcom_llcc_event_read();
  *(uint *)(param_1 + 0x1d8) = *(uint *)(param_1 + 0x1d8) | 3;
  return;
}



//------------------------------------------------------------
// qcom_llcc_event_read @ 00100818 size=532
// signature: undefined qcom_llcc_event_read(void)
// callers: [qcom_llcc_event_stop]
//------------------------------------------------------------

void qcom_llcc_event_read(long param_1)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  undefined8 uVar4;
  long lVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  
  uVar2 = *(uint *)(param_1 + 0x28c);
  uVar7 = (ulong)uVar2;
  uVar4 = _raw_spin_lock_irqsave(&counter_lock);
  if (*(int *)(llccpmu + 0x570) == 1) {
    lVar5 = ktime_get();
    if (1999999 < lVar5 - last_read) {
      mon_disable(uVar7);
      lVar8 = 0;
      do {
        if (*(int *)(llccpmu + 0x570) - 1U < 2) {
          uVar6 = readl_relaxed(*(long *)(llccpmu + 0x138) +
                                (long)(*(int *)(phys_cpu + lVar8 * 4) << 2) + 0x220);
          uVar6 = uVar6 & 0xffffffff;
        }
        else if (*(int *)(llccpmu + 0x570) == 0) {
          _printk(&DAT_0010117f);
          uVar6 = 0xffffffffffffffea;
        }
        else {
          uVar6 = 0;
        }
        lVar1 = lVar8 + 1;
        (&llcc_stats)[lVar8] = (uVar6 & 0xffffff) * 8 + (&llcc_stats)[lVar8];
        lVar8 = lVar1;
      } while (lVar1 != 0x20);
      last_read = lVar5;
      goto LAB_001009a8;
    }
  }
  else {
    mon_disable(uVar7);
    if (0x1f < uVar2) goto LAB_00100a28;
    if (*(int *)(llccpmu + 0x570) - 1U < 2) {
      if (0x1f < uVar2) goto LAB_00100a24;
      uVar6 = readl_relaxed(*(long *)(llccpmu + 0x138) + (long)(*(int *)(phys_cpu + uVar7 * 4) << 2)
                            + 0x220);
      lVar5 = (uVar6 & 0xffffff) << 3;
    }
    else if (*(int *)(llccpmu + 0x570) == 0) {
      _printk(&DAT_0010117f);
      lVar5 = 0x7ffff50;
    }
    else {
      lVar5 = 0;
    }
    if (0x1f < uVar2) {
LAB_00100a24:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100a28);
      (*pcVar3)();
    }
    (&llcc_stats)[uVar7] = (&llcc_stats)[uVar7] + lVar5;
LAB_001009a8:
    mon_clear(uVar7);
    mon_enable(uVar7);
  }
  if ((*(byte *)(param_1 + 0x1d8) & 1) == 0) {
    if (0x1f < uVar2) {
LAB_00100a28:
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100a2c);
      (*pcVar3)();
    }
    *(undefined8 *)(param_1 + 0xb0) = (&llcc_stats)[uVar7];
  }
  _raw_spin_unlock_irqrestore(&counter_lock,uVar4);
  return;
}



//------------------------------------------------------------
// get_mpidr_cpu @ 00100a30 size=16
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
// mon_enable @ 00100a40 size=168
// signature: undefined mon_enable(void)
// callers: [qcom_llcc_event_add, qcom_llcc_event_read]
//------------------------------------------------------------

void mon_enable(uint param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100ae4);
    (*pcVar3)();
  }
  iVar1 = *(int *)(llccpmu + 0x570);
  if (iVar1 == 1) {
    lVar5 = *(long *)(llccpmu + 0x138);
    uVar4 = 1;
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 0) {
        _printk(&DAT_0010117f);
        return;
      }
      return;
    }
    if (0x1f < param_1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100ae8);
      (*pcVar3)();
    }
    uVar2 = *(uint *)(phys_cpu + (ulong)param_1 * 4);
    uVar4 = readl_relaxed(*(long *)(llccpmu + 0x138) + 0x200);
    uVar4 = uVar4 | 1 << (ulong)(uVar2 & 0x1f);
    lVar5 = *(long *)(llccpmu + 0x138);
  }
  writel_relaxed(uVar4,lVar5 + 0x200);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00100ae8 size=132
// signature: undefined writel_relaxed(void)
// callers: [mon_clear, mon_disable, mon_enable]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100b00,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x100b3c,uVar1);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100b6c size=124
// signature: undefined readl_relaxed(void)
// callers: [mon_clear, mon_disable, qcom_llcc_event_read, mon_enable]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x100bb4,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// mon_disable @ 00100be8 size=168
// signature: undefined mon_disable(void)
// callers: [qcom_llcc_event_del, qcom_llcc_event_read]
//------------------------------------------------------------

void mon_disable(uint param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100c8c);
    (*pcVar3)();
  }
  iVar1 = *(int *)(llccpmu + 0x570);
  if (iVar1 == 1) {
    lVar5 = *(long *)(llccpmu + 0x138);
    uVar4 = 0;
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 0) {
        _printk(&DAT_0010117f);
        return;
      }
      return;
    }
    if (0x1f < param_1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100c90);
      (*pcVar3)();
    }
    uVar2 = *(uint *)(phys_cpu + (ulong)param_1 * 4);
    uVar4 = readl_relaxed(*(long *)(llccpmu + 0x138) + 0x200);
    uVar4 = uVar4 & (1 << (ulong)(uVar2 & 0x1f) ^ 0xffffffffU);
    lVar5 = *(long *)(llccpmu + 0x138);
  }
  writel_relaxed(uVar4,lVar5 + 0x200);
  return;
}



//------------------------------------------------------------
// mon_clear @ 00100c90 size=204
// signature: undefined mon_clear(void)
// callers: [qcom_llcc_event_read]
//------------------------------------------------------------

void mon_clear(uint param_1)

{
  int iVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  long lVar5;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x100d58);
    (*pcVar3)();
  }
  iVar1 = *(int *)(llccpmu + 0x570);
  if (iVar1 == 1) {
    lVar5 = *(long *)(llccpmu + 0x138);
    uVar4 = 0x10;
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 == 0) {
        _printk(&DAT_0010117f);
        return;
      }
      return;
    }
    if (0x1f < param_1) {
                    /* WARNING: Does not return */
      pcVar3 = (code *)SoftwareBreakpoint(1,0x100d5c);
      (*pcVar3)();
    }
    iVar1 = *(int *)(phys_cpu + (ulong)param_1 * 4);
    uVar4 = readl_relaxed(*(long *)(llccpmu + 0x138) + 0x200);
    uVar2 = 1 << (ulong)(iVar1 + 0x10U & 0x1f);
    writel_relaxed(uVar4 | uVar2,*(long *)(llccpmu + 0x138) + 0x200);
    uVar4 = uVar4 & (uVar2 ^ 0xffffffff);
    lVar5 = *(long *)(llccpmu + 0x138);
  }
  writel_relaxed(uVar4,lVar5 + 0x200);
  return;
}



//------------------------------------------------------------
// init_module @ 00100d7c size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&qcom_llcc_pmu_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00100dac size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&qcom_llcc_pmu_driver);
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
// devm_kmalloc @ 00102010 size=1
// signature: undefined devm_kmalloc(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00102018 size=1
// signature: undefined _dev_err(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_get_match_data @ 00102020 size=1
// signature: undefined of_device_get_match_data(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_get_match_data(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102028 size=1
// signature: undefined _printk(void)
// callers: [mon_clear, qcom_llcc_pmu_probe, mon_disable, qcom_llcc_event_read, mon_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00102030 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 00102038 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// perf_pmu_register @ 00102040 size=1
// signature: undefined perf_pmu_register(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void perf_pmu_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 00102058 size=1
// signature: undefined _find_next_bit(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// smp_call_function_single @ 00102060 size=1
// signature: undefined smp_call_function_single(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void smp_call_function_single(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00102068 size=1
// signature: undefined _dev_info(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102070 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qcom_llcc_pmu_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00102078 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [qcom_llcc_event_add, qcom_llcc_event_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00102088 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [qcom_llcc_event_add, qcom_llcc_event_del]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00102090 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [qcom_llcc_event_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ktime_get @ 00102098 size=1
// signature: undefined ktime_get(void)
// callers: [qcom_llcc_event_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ktime_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001020a0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [qcom_llcc_event_read]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 001020a8 size=1
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
// log_post_write_mmio @ 001020b0 size=1
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
// log_read_mmio @ 001020b8 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 001020c0 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



