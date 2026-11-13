// Decompiled by Ghidra 12.2
// Program: gic_intr_routing.ko
// Image base: 00100000

//------------------------------------------------------------
// gic_do_class_update_virtual @ 0010040c size=68
// signature: undefined gic_do_class_update_virtual(void)
// callers: []
//------------------------------------------------------------

void gic_do_class_update_virtual(long param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 & 0x1fff | 0x40000000;
  if ((param_3 & 1) == 0) {
    uVar1 = param_2 & 0x1fff;
  }
  uVar2 = uVar1 | 0x80000000;
  if ((param_4 & 1) == 0) {
    uVar2 = uVar1;
  }
  writel_relaxed(uVar2,param_1 + 0x28);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00100450 size=132
// signature: undefined writel_relaxed(void)
// callers: [gic_affinity_cpu_offline, gic_do_class_update_physical, gic_affinity_cpu_online, gic_do_class_update_virtual, trace_gic_v3_set_affinity, gic_do_class_update]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x100468,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1004a4,uVar1);
  return;
}



//------------------------------------------------------------
// gic_do_class_update_physical @ 001004d8 size=144
// signature: undefined gic_do_class_update_physical(void)
// callers: []
//------------------------------------------------------------

void gic_do_class_update_physical(long param_1,ulong param_2,uint param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 2;
  if ((param_3 & 1) == 0) {
    uVar4 = 0;
  }
  lVar1 = param_1 + 0xe008 + (ulong)((uint)(param_2 >> 2) & 0x3ffffffc);
  _raw_spin_lock(&gic_class_lock);
  uVar3 = readl_relaxed(lVar1);
  uVar2 = ((uint)param_2 & 0xf) << 2;
  writel_relaxed(uVar3 & (3 << (ulong)(uVar2 & 0x1f) ^ 0xffffffffU) |
                 (uVar4 | param_4 & 1) << (ulong)(uVar2 & 0x1f),lVar1);
  _raw_spin_unlock(&gic_class_lock);
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 00100568 size=124
// signature: undefined readl_relaxed(void)
// callers: [gic_affinity_cpu_offline, gic_do_class_update_physical, gic_affinity_cpu_online, trace_gic_v3_set_affinity, gic_do_class_update]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x1005b0,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// gic_do_class_update @ 001005e8 size=208
// signature: undefined gic_do_class_update(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

void gic_do_class_update(long param_1,uint param_2,uint param_3,uint param_4)

{
  long lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (DAT_001017bc == '\0') {
    uVar4 = 2;
    if ((param_3 & 1) == 0) {
      uVar4 = 0;
    }
    lVar1 = param_1 + 0xe008 + (ulong)(param_2 >> 2 & 0x3ffffffc);
    _raw_spin_lock(&gic_class_lock);
    uVar3 = readl_relaxed(lVar1);
    uVar2 = (param_2 & 0xf) << 2;
    writel_relaxed(uVar3 & (3 << (ulong)(uVar2 & 0x1f) ^ 0xffffffffU) |
                   (uVar4 | param_4 & 1) << (ulong)(uVar2 & 0x1f),lVar1);
    _raw_spin_unlock(&gic_class_lock);
  }
  else {
    uVar4 = param_2 + 0x20 & 0x1fff | 0x40000000;
    if ((param_3 & 1) == 0) {
      uVar4 = param_2 + 0x20 & 0x1fff;
    }
    uVar2 = uVar4 | 0x80000000;
    if ((param_4 & 1) == 0) {
      uVar2 = uVar4;
    }
    writel_relaxed(uVar2,param_1 + 0x28);
  }
  return;
}



//------------------------------------------------------------
// gic_irq_handler_entry_notifer @ 001006bc size=352
// signature: undefined gic_irq_handler_entry_notifer(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gic_irq_handler_entry_notifer(undefined8 param_1,undefined4 param_2,long param_3)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 *puVar6;
  ulong uVar7;
  ulong uVar8;
  long lVar9;
  
  if (*(long *)(param_3 + 0x20) == 0) {
    return;
  }
  lVar5 = irq_to_desc(param_2);
  if (lVar5 == 0) {
    return;
  }
  lVar9 = *(long *)(lVar5 + 0x38);
  if ((int)lVar9 - 0x3fcU < 0xfffffc24) {
    return;
  }
  if (DAT_001017be == '\0') {
    puVar6 = *(undefined8 **)(lVar5 + 0x48);
    if (puVar6 == (undefined8 *)0x0) {
      return;
    }
  }
  else {
    DataMemoryBarrier(2,1);
    puVar6 = *(undefined8 **)(lVar5 + 0x48);
    if (puVar6 == (undefined8 *)0x0) {
      return;
    }
    if (gic_routing_data != (undefined8 *)0x0) {
      if (puVar6 != gic_routing_data) {
        return;
      }
      goto LAB_00100764;
    }
  }
  iVar4 = strcmp((char *)*puVar6,"GICv3");
  if (iVar4 != 0) {
    return;
  }
LAB_00100764:
  uVar8 = lVar9 + 0xffffffe0;
  uVar7 = uVar8 >> 6 & 0x3ffffff;
  uVar8 = 1L << (uVar8 & 0x3f);
  if (((*(ulong *)(active_gic_class0 + uVar7 * 8) & uVar8) != 0) ||
     ((*(ulong *)(active_gic_class1 + uVar7 * 8) & uVar8) != 0)) {
    iVar4 = _raw_spin_trylock(lVar5 + 0xac);
    if (iVar4 != 0) {
      uVar8 = __bitmap_equal(*(long *)(lVar5 + 0x40) + 0x20,(void *)(lVar5 + 0x18),_nr_cpu_ids);
      if ((uVar8 & 1) == 0) {
        memcpy((void *)(*(long *)(lVar5 + 0x40) + 0x20),(void *)(lVar5 + 0x18),
               (ulong)(_nr_cpu_ids + 0x3fU >> 3 & 0x1ffffff8));
        puVar1 = (ulong *)(param_3 + 0x40);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 4;
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      _raw_spin_unlock(lVar5 + 0xac);
    }
  }
  return;
}



//------------------------------------------------------------
// gic_intr_routing_probe @ 0010082c size=660
// signature: undefined gic_intr_routing_probe(void)
// callers: []
//------------------------------------------------------------

void gic_intr_routing_probe(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  undefined8 uVar9;
  int iVar10;
  long local_98 [11];
  
  lVar4 = sp_el0;
  local_98[10] = *(long *)(lVar4 + 0x638);
  iVar5 = of_count_phandle_with_args(*(undefined8 *)(param_1 + 0x2f8),"qcom,gic-class0-cpus",0);
  if (iVar5 < 1) {
    puVar8 = &DAT_00101e97;
  }
  else {
    iVar10 = 0;
    do {
      local_98[8] = 0;
      local_98[9] = 0;
      local_98[6] = 0;
      local_98[7] = 0;
      local_98[4] = 0;
      local_98[5] = 0;
      local_98[2] = 0;
      local_98[3] = 0;
      local_98[0] = 0;
      local_98[1] = 0;
      iVar6 = __of_parse_phandle_with_args
                        (*(undefined8 *)(param_1 + 0x2f8),"qcom,gic-class0-cpus",0,0,iVar10,local_98
                        );
      if (((iVar6 == 0) && (local_98[0] != 0)) && (uVar7 = of_cpu_node_to_id(), -1 < (int)uVar7)) {
        puVar1 = (ulong *)(&DAT_001017a0 + (ulong)(uVar7 >> 6) * 8);
        Hint_Prefetch(puVar1,2,0,1);
        do {
          cVar2 = '\x01';
          bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
          if (bVar3) {
            *puVar1 = *puVar1 | 1L << ((ulong)uVar7 & 0x3f);
            cVar2 = ExclusiveMonitorsStatus();
          }
        } while (cVar2 != '\0');
      }
      iVar10 = iVar10 + 1;
    } while (iVar5 != iVar10);
    iVar5 = of_count_phandle_with_args(*(undefined8 *)(param_1 + 0x2f8),"qcom,gic-class1-cpus",0);
    if (0 < iVar5) {
      iVar10 = 0;
      do {
        local_98[8] = 0;
        local_98[9] = 0;
        local_98[6] = 0;
        local_98[7] = 0;
        local_98[4] = 0;
        local_98[5] = 0;
        local_98[2] = 0;
        local_98[3] = 0;
        local_98[0] = 0;
        local_98[1] = 0;
        iVar6 = __of_parse_phandle_with_args
                          (*(undefined8 *)(param_1 + 0x2f8),"qcom,gic-class1-cpus",0,0,iVar10,
                           local_98);
        if (((iVar6 == 0) && (local_98[0] != 0)) && (uVar7 = of_cpu_node_to_id(), -1 < (int)uVar7))
        {
          puVar1 = (ulong *)(&DAT_001017a8 + (ulong)(uVar7 >> 6) * 8);
          Hint_Prefetch(puVar1,2,0,1);
          do {
            cVar2 = '\x01';
            bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
            if (bVar3) {
              *puVar1 = *puVar1 | 1L << ((ulong)uVar7 & 0x3f);
              cVar2 = ExclusiveMonitorsStatus();
            }
          } while (cVar2 != '\0');
        }
        iVar10 = iVar10 + 1;
      } while (iVar5 != iVar10);
      android_rvh_probe_register
                (&__tracepoint_android_rvh_gic_v3_set_affinity,trace_gic_v3_set_affinity,0);
      tracepoint_probe_register(&__tracepoint_irq_handler_entry,gic_irq_handler_entry_notifer,0);
      iVar5 = __cpuhp_setup_state(200,"qcom/gic_affinity_setting:online",1,gic_affinity_cpu_online,
                                  gic_affinity_cpu_offline,0);
      if (iVar5 < 0) {
        __cpuhp_remove_state(200,1);
        _printk(&DAT_00101cc4,"gic_intr_routing_probe");
      }
      DAT_001017b8 = iVar5;
      _printk(&DAT_00101dcf,"gic_intr_routing_probe");
      uVar9 = 0;
      goto LAB_00100aac;
    }
    puVar8 = &DAT_00101e4a;
  }
  _printk(puVar8,"gic_intr_routing_probe","gic_intr_routing_probe");
  uVar9 = 0xffffffea;
LAB_00100aac:
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_98[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar9);
  }
  return;
}



//------------------------------------------------------------
// trace_gic_v3_set_affinity @ 00100ae4 size=1548
// signature: undefined trace_gic_v3_set_affinity(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void trace_gic_v3_set_affinity
               (undefined8 param_1,long param_2,undefined *param_3,ulong *param_4,undefined8 param_5
               ,long param_6,long param_7,long param_8)

{
  ulong *puVar1;
  long lVar2;
  long lVar3;
  char cVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  uint uVar9;
  uint uVar10;
  ulong uVar11;
  long lVar12;
  ulong uVar13;
  ulong uVar14;
  char *pcVar15;
  undefined8 local_70;
  long local_68;
  
  lVar3 = sp_el0;
  local_68 = *(long *)(lVar3 + 0x638);
  lVar2 = *(long *)(param_2 + 8);
  lVar3 = *(long *)(param_2 + 0x10);
  local_70 = 0;
  if (lVar2 - 0x3fcU < 0xfffffffffffffc24) goto LAB_00101050;
  if (DAT_001017be == '\0') {
    _raw_spin_lock(&gic_init_lock);
    if (DAT_001017be == '\0') {
      uVar9 = readl_relaxed(param_6 + 8);
      uVar9 = uVar9 & 0xff000fff;
      pcVar15 = "Physical GIC";
      if ((uVar9 == 0x200043b) || (uVar9 == 0x400043b)) {
LAB_00100f98:
        uVar11 = readl_relaxed(param_6 + 4);
        DAT_001017bd = (uVar11 & 0x2000000) == 0;
        _printk(&DAT_00101d18,"qcom_gic_enable_quirks",pcVar15);
      }
      else if (uVar9 == 0x47000070) {
        pcVar15 = "Virtual GIC";
        DAT_001017bc = '\x01';
        goto LAB_00100f98;
      }
      gic_routing_data = *(undefined8 *)(param_2 + 0x18);
      DataMemoryBarrier(2,2);
      DAT_001017be = '\x01';
    }
    _raw_spin_unlock(&gic_init_lock);
  }
  if (DAT_001017bd == '\0') goto LAB_00101050;
  lVar3 = lVar3 + 0x18;
  DAT_001017c8 = param_7;
  DAT_001017d0 = param_8;
  if ((DAT_001017bc == '\0') && (DAT_001017d8 == 0)) {
    lVar12 = 0;
    while( true ) {
      uVar11 = _find_next_bit(&__cpu_possible_mask,_nr_cpu_ids,(long)(int)lVar12);
      if (_nr_cpu_ids <= (uint)uVar11) break;
      lVar12 = param_7 + (int)(uint)uVar11 * param_8;
      uVar9 = readl_relaxed(lVar12);
      writel_relaxed(uVar9 & 0xfc000000 |
                     uVar9 & 0x1ffffff |
                     (uint)((*(ulong *)(&__cpu_online_mask + (uVar11 >> 6 & 0x3ffffff) * 8) >>
                             (uVar11 & 0x3f) & 1) == 0) << 0x19,lVar12);
      lVar12 = uVar11 + 1;
    }
    DAT_001017d8 = 1;
  }
  lVar12 = tpidr_el1;
  uVar9 = *(uint *)(&cpu_number + lVar12);
  uVar11 = __bitmap_subset(lVar3,&DAT_001017a0,_nr_cpu_ids);
  if (((uVar11 & 1) != 0) &&
     (uVar11 = __bitmap_intersects(&__cpu_online_mask,&DAT_001017a0,_nr_cpu_ids), (uVar11 & 1) == 0)
     ) {
    uVar11 = 1L << ((ulong)uVar9 & 0x3f);
    if (((*(ulong *)(&__cpu_online_mask + (ulong)(uVar9 >> 6) * 8) & uVar11) == 0) &&
       ((*(ulong *)(&DAT_001017a0 + (ulong)(uVar9 >> 6) * 8) & uVar11) != 0)) goto LAB_00101050;
  }
  uVar11 = __bitmap_subset(lVar3,&DAT_001017a8,_nr_cpu_ids);
  if (((uVar11 & 1) != 0) &&
     (uVar11 = __bitmap_intersects(&__cpu_online_mask,&DAT_001017a8,_nr_cpu_ids), (uVar11 & 1) == 0)
     ) {
    uVar11 = 1L << ((ulong)uVar9 & 0x3f);
    if (((*(ulong *)(&__cpu_online_mask + (ulong)(uVar9 >> 6) * 8) & uVar11) == 0) &&
       ((*(ulong *)(&DAT_001017a8 + (ulong)(uVar9 >> 6) * 8) & uVar11) != 0)) goto LAB_00101050;
  }
  uVar9 = __bitmap_weight(param_3,_nr_cpu_ids);
  if (uVar9 < 2) goto LAB_00101050;
  uVar9 = (int)lVar2 - 0x20;
  uVar14 = (ulong)uVar9;
  __bitmap_or(&local_70,&DAT_001017a0,&DAT_001017a8,_nr_cpu_ids);
  uVar11 = __bitmap_subset(param_3,&DAT_001017a0,_nr_cpu_ids);
  if (((((uVar11 & 1) == 0) &&
       (uVar11 = __bitmap_equal(&DAT_001017a0,param_3,_nr_cpu_ids), (uVar11 & 1) == 0)) &&
      (uVar11 = __bitmap_equal(&DAT_001017a8,param_3,_nr_cpu_ids), (uVar11 & 1) == 0)) &&
     (uVar11 = __bitmap_equal(&local_70,param_3,_nr_cpu_ids), (uVar11 & 1) == 0)) {
    _raw_spin_lock(&gic_class_lock);
    uVar11 = 1L << (uVar14 & 0x3f);
    puVar1 = (ulong *)(active_gic_class0 + (ulong)(uVar9 >> 6) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar6) {
        *puVar1 = *puVar1 & (uVar11 ^ 0xffffffffffffffff);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    puVar1 = (ulong *)(active_gic_class1 + (ulong)(uVar9 >> 6) * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar6 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar6) {
        *puVar1 = *puVar1 & (uVar11 ^ 0xffffffffffffffff);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
    _raw_spin_unlock(&gic_class_lock);
    goto LAB_00101050;
  }
  uVar10 = _find_first_and_bit(param_3,&__cpu_online_mask,_nr_cpu_ids);
  if (_nr_cpu_ids <= uVar10) {
    param_3 = &__cpu_online_mask;
  }
  bVar7 = __bitmap_subset(param_3,&DAT_001017a0);
  if ((bVar7 & 1) == 0) {
    bVar8 = __bitmap_subset(param_3,&DAT_001017a8,_nr_cpu_ids);
    bVar8 = bVar8 ^ 1;
  }
  else {
    bVar8 = 1;
  }
  *param_4 = *param_4 | 0x80000000;
  if ((DAT_001017bc == '\0') ||
     ((bVar8 & bVar7 &
      (*(ulong *)(gic_class_initialized + ((ulong)(uVar9 >> 3) & 0x1ffffff8)) >> (uVar14 & 0x3f) & 1
      ) == 0) == 0)) {
    uVar11 = (ulong)(uVar9 >> 6);
    uVar13 = 1L << (uVar14 & 0x3f);
    if (((*(ulong *)(gic_class_initialized + uVar11 * 8) & uVar13) != 0) &&
       ((((bVar8 ^ (*(ulong *)(active_gic_class0 + uVar11 * 8) & uVar13) != 0) & 1) == 0 &&
        (((*(ulong *)(active_gic_class1 + uVar11 * 8) & uVar13) != 0) == (bool)((bVar7 ^ 1) & 1)))))
    goto LAB_00100eb8;
    bVar6 = true;
  }
  else {
LAB_00100eb8:
    bVar6 = false;
  }
  _raw_spin_lock(&gic_class_lock);
  uVar13 = (ulong)(uVar9 >> 6);
  uVar11 = 1L << (uVar14 & 0x3f);
  puVar1 = (ulong *)(gic_class_initialized + uVar13 * 8);
  Hint_Prefetch(puVar1,2,0,1);
  do {
    cVar4 = '\x01';
    bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
    if (bVar5) {
      *puVar1 = *puVar1 | uVar11;
      cVar4 = ExclusiveMonitorsStatus();
    }
  } while (cVar4 != '\0');
  if ((bVar8 & 1) == 0) {
    puVar1 = (ulong *)(active_gic_class0 + uVar13 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & (uVar11 ^ 0xffffffffffffffff);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  else {
    puVar1 = (ulong *)(active_gic_class0 + uVar13 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 | uVar11;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  if ((bVar7 & 1) == 0) {
    puVar1 = (ulong *)(active_gic_class1 + uVar13 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 | uVar11;
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  else {
    puVar1 = (ulong *)(active_gic_class1 + uVar13 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar4 = '\x01';
      bVar5 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar5) {
        *puVar1 = *puVar1 & (uVar11 ^ 0xffffffffffffffff);
        cVar4 = ExclusiveMonitorsStatus();
      }
    } while (cVar4 != '\0');
  }
  _raw_spin_unlock(&gic_class_lock);
  if (bVar6) {
    gic_do_class_update(param_6,uVar14,bVar8 & 1,(bVar7 ^ 1) & 1);
  }
LAB_00101050:
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gic_affinity_cpu_online @ 00101168 size=248
// signature: undefined gic_affinity_cpu_online(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gic_affinity_cpu_online(ulong param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  ulong uVar5;
  long lVar6;
  ulong uVar7;
  ulong uVar8;
  ulong uVar9;
  
  if ((DAT_001017bc == '\0') && (DAT_001017d8 != 0)) {
    lVar6 = DAT_001017c8 + DAT_001017d0 * (param_1 & 0xffffffff);
    uVar4 = readl_relaxed(lVar6);
    writel_relaxed(uVar4 & 0xfdffffff,lVar6);
  }
  uVar9 = (param_1 & 0xffffffff) >> 6;
  uVar8 = 1L << (param_1 & 0x3f);
  if ((*(ulong *)(&DAT_001017a0 + uVar9 * 8) & uVar8) != 0) {
    uVar7 = (ulong)_nr_cpu_ids;
    uVar5 = _find_first_bit(&DAT_001017b0,uVar7);
    if (uVar5 == uVar7) {
      queue_delayed_work_on(0x20,_system_wq,affinity_initialize_work,0x4e2);
    }
    puVar1 = (ulong *)(&DAT_001017b0 + uVar9 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 | uVar8;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  return 0;
}



//------------------------------------------------------------
// gic_affinity_cpu_offline @ 00101270 size=372
// signature: undefined gic_affinity_cpu_offline(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 gic_affinity_cpu_offline(ulong param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  uint uVar4;
  undefined8 uVar5;
  ulong uVar6;
  ulong uVar7;
  long lVar8;
  
  if ((DAT_001017bc == '\0') && (DAT_001017d8 != 0)) {
    lVar8 = DAT_001017c8 + DAT_001017d0 * (param_1 & 0xffffffff);
    uVar4 = readl_relaxed(lVar8);
    writel_relaxed(uVar4 | 0x2000000,lVar8);
  }
  uVar7 = (param_1 & 0xffffffff) >> 6;
  uVar6 = 1L << (param_1 & 0x3f);
  if ((*(ulong *)(&DAT_001017a0 + uVar7 * 8) & uVar6) != 0) {
    puVar1 = (ulong *)(&DAT_001017b0 + uVar7 * 8);
    Hint_Prefetch(puVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
      if (bVar3) {
        *puVar1 = *puVar1 & (uVar6 ^ 0xffffffffffffffff);
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    uVar7 = (ulong)_nr_cpu_ids;
    uVar6 = _find_first_bit(&DAT_001017b0,uVar7);
    if (uVar6 == uVar7) {
      Hint_Prefetch(0x1017c4,2,0,1);
      do {
        cVar2 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(0x1017c4,0x10);
        if (bVar3) {
          cVar2 = ExclusiveMonitorsStatus();
        }
      } while (cVar2 != '\0');
      DataMemoryBarrier(2,3);
      if (DAT_001017c4 == 0) {
        flush_delayed_work(affinity_initialize_work);
        DataMemoryBarrier(2,3);
      }
      else {
        DAT_001017c0 = 1;
        DataMemoryBarrier(2,3);
        cancel_delayed_work_sync(affinity_initialize_work);
        DataMemoryBarrier(2,3);
        DAT_001017c0 = 0;
      }
      uVar5 = _raw_spin_lock_irqsave(&gic_class_lock);
      __bitmap_andnot(gic_saved_class0,active_gic_class0,active_gic_class1,0x3fc);
      _raw_spin_unlock_irqrestore(&gic_class_lock,uVar5);
    }
  }
  return 0;
}



//------------------------------------------------------------
// affinity_initialize_workfn @ 00101408 size=768
// signature: undefined affinity_initialize_workfn(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void affinity_initialize_workfn(void)

{
  char cVar1;
  ulong uVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  undefined8 *puVar9;
  ulong uVar10;
  ulong uVar11;
  long lVar12;
  undefined8 *puVar13;
  int iVar14;
  undefined8 local_70;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_70 = 0;
  if (DAT_001017be == '\0') {
    puVar13 = (undefined8 *)0x0;
  }
  else {
    DataMemoryBarrier(2,1);
    puVar13 = gic_routing_data;
  }
  if (1 < _nr_irqs) {
    iVar14 = 1;
    do {
      Hint_Prefetch(0x1017c0,2,0,1);
      do {
        cVar1 = '\x01';
        bVar3 = (bool)ExclusiveMonitorPass(0x1017c0,0x10);
        if (bVar3) {
          cVar1 = ExclusiveMonitorsStatus();
        }
      } while (cVar1 != '\0');
      DataMemoryBarrier(2,3);
      if (DAT_001017c0 != 0) goto LAB_001016d4;
      DataMemoryBarrier(2,3);
      uVar2 = daif;
      uVar4 = (uint)uVar2 & 0x80;
      if ((uVar2 & 0x80) == 0) {
        uVar4 = 0x60;
        uVar11 = daif;
        daif = uVar11 | 0xc0;
      }
      __rcu_read_lock(uVar4);
      lVar7 = irq_to_desc(iVar14);
      if (lVar7 != 0) {
        _raw_spin_lock(lVar7 + 0xac);
        lVar12 = *(long *)(lVar7 + 0x38);
        if ((lVar12 - 0x3fcU < 0xfffffffffffffc24) ||
           (puVar9 = *(undefined8 **)(lVar7 + 0x48), puVar9 == (undefined8 *)0x0)) {
LAB_00101518:
          bVar3 = false;
        }
        else {
          if (puVar13 == (undefined8 *)0x0) {
            iVar5 = strcmp((char *)*puVar9,"GICv3");
            if (iVar5 != 0) goto LAB_00101518;
          }
          else if (puVar9 != puVar13) goto LAB_00101518;
          lVar8 = _find_first_bit(gic_saved_class0,0x3fc);
          if (lVar8 == 0x3fc) {
            bVar3 = true;
          }
          else {
            uVar11 = lVar12 + 0xffffffe0;
            _raw_spin_lock(&gic_class_lock);
            uVar10 = uVar11 >> 6 & 0x3ffffff;
            uVar11 = 1L << (uVar11 & 0x3f);
            if ((*(ulong *)(active_gic_class0 + uVar10 * 8) & uVar11) == 0) {
              bVar3 = false;
            }
            else {
              bVar3 = (*(ulong *)(active_gic_class1 + uVar10 * 8) & uVar11) == 0;
            }
            _raw_spin_unlock(&gic_class_lock);
          }
        }
        lVar12 = _find_first_bit(gic_saved_class0,0x3fc);
        uVar4 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
        if (lVar12 == 0x3fc) {
          if (uVar4 < 9) {
            memcpy(&local_70,(void *)(lVar7 + 0x18),(ulong)uVar4);
joined_r0x00101574:
            if (bVar3) {
              uVar4 = _find_first_and_bit(&local_70,&__cpu_online_mask,_nr_cpu_ids);
              if (_nr_cpu_ids <= uVar4) {
                uVar4 = _nr_cpu_ids + 0x3f >> 3 & 0x1ffffff8;
                if (8 < uVar4) goto LAB_0010170c;
                memcpy(&local_70,&__cpu_online_mask,(ulong)uVar4);
              }
              iVar5 = irq_do_set_affinity(lVar7 + 0x30,&local_70,0);
              if ((iVar5 != 0) &&
                 (iVar6 = ___ratelimit(affinity_initialize_workfn__rs,"affinity_initialize_workfn"),
                 iVar6 != 0)) {
                _printk(&DAT_00101e0a,"affinity_initialize_workfn",*(undefined4 *)(lVar7 + 0x34),
                        iVar5);
              }
            }
            _raw_spin_unlock(lVar7 + 0xac);
            goto LAB_00101490;
          }
        }
        else if (uVar4 < 9) {
          memcpy(&local_70,&DAT_001017a0,(ulong)uVar4);
          goto joined_r0x00101574;
        }
LAB_0010170c:
        fortify_panic("memcpy");
        goto LAB_00101718;
      }
LAB_00101490:
      __rcu_read_unlock();
      daif = uVar2;
      iVar14 = iVar14 + 1;
    } while (iVar14 < _nr_irqs);
  }
  DataMemoryBarrier(2,3);
  DAT_001017c4 = 1;
LAB_001016d4:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) == local_68) {
    return;
  }
LAB_00101718:
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}



//------------------------------------------------------------
// init_module @ 00101738 size=44
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  __platform_driver_register(&gic_intr_routing_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 00101768 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gic_intr_routing_driver);
  return;
}



//------------------------------------------------------------
// log_write_mmio @ 00104000 size=1
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
// log_post_write_mmio @ 00104008 size=1
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
// _raw_spin_lock @ 00104010 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [gic_do_class_update_physical, trace_gic_v3_set_affinity, affinity_initialize_workfn, gic_do_class_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00104018 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [gic_irq_handler_entry_notifer, gic_do_class_update_physical, trace_gic_v3_set_affinity, affinity_initialize_workfn, gic_do_class_update]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00104020 size=1
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
// log_post_read_mmio @ 00104028 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_to_desc @ 00104030 size=1
// signature: undefined irq_to_desc(void)
// callers: [gic_irq_handler_entry_notifer, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_to_desc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 00104038 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [gic_irq_handler_entry_notifer, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_trylock @ 00104040 size=1
// signature: undefined _raw_spin_trylock(void)
// callers: [gic_irq_handler_entry_notifer]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_trylock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_equal @ 00104050 size=1
// signature: undefined __bitmap_equal(void)
// callers: [gic_irq_handler_entry_notifer, trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_equal(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00104058 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gic_irq_handler_entry_notifer, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 00104068 size=1
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
// platform_driver_unregister @ 00104070 size=1
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
// of_count_phandle_with_args @ 00104078 size=1
// signature: undefined of_count_phandle_with_args(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_count_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 00104080 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_cpu_node_to_id @ 00104088 size=1
// signature: undefined of_cpu_node_to_id(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_cpu_node_to_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00104090 size=1
// signature: undefined _printk(void)
// callers: [gic_intr_routing_probe, trace_gic_v3_set_affinity, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// android_rvh_probe_register @ 001040a0 size=1
// signature: undefined android_rvh_probe_register(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void android_rvh_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tracepoint_probe_register @ 001040b0 size=1
// signature: undefined tracepoint_probe_register(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tracepoint_probe_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state @ 001040b8 size=1
// signature: undefined __cpuhp_setup_state(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 001040c0 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [gic_intr_routing_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001040c8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gic_intr_routing_probe, trace_gic_v3_set_affinity, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_next_bit @ 001040e0 size=1
// signature: undefined _find_next_bit(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_next_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_subset @ 001040f0 size=1
// signature: undefined __bitmap_subset(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_subset(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_intersects @ 001040f8 size=1
// signature: undefined __bitmap_intersects(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_intersects(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_weight @ 00104100 size=1
// signature: undefined __bitmap_weight(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_weight(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_or @ 00104108 size=1
// signature: undefined __bitmap_or(void)
// callers: [trace_gic_v3_set_affinity]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_or(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_and_bit @ 00104110 size=1
// signature: undefined _find_first_and_bit(void)
// callers: [trace_gic_v3_set_affinity, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_and_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _find_first_bit @ 00104118 size=1
// signature: undefined _find_first_bit(void)
// callers: [gic_affinity_cpu_offline, gic_affinity_cpu_online, affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _find_first_bit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// queue_delayed_work_on @ 00104128 size=1
// signature: undefined queue_delayed_work_on(void)
// callers: [gic_affinity_cpu_online]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void queue_delayed_work_on(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cancel_delayed_work_sync @ 00104130 size=1
// signature: undefined cancel_delayed_work_sync(void)
// callers: [gic_affinity_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cancel_delayed_work_sync(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// flush_delayed_work @ 00104138 size=1
// signature: undefined flush_delayed_work(void)
// callers: [gic_affinity_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void flush_delayed_work(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00104140 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gic_affinity_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_andnot @ 00104148 size=1
// signature: undefined __bitmap_andnot(void)
// callers: [gic_affinity_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_andnot(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00104150 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gic_affinity_cpu_offline]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_unlock @ 00104160 size=1
// signature: undefined __rcu_read_unlock(void)
// callers: [affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __rcu_read_lock @ 00104170 size=1
// signature: undefined __rcu_read_lock(void)
// callers: [affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __rcu_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// irq_do_set_affinity @ 00104178 size=1
// signature: undefined irq_do_set_affinity(void)
// callers: [affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void irq_do_set_affinity(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ___ratelimit @ 00104180 size=1
// signature: undefined ___ratelimit(void)
// callers: [affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ___ratelimit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fortify_panic @ 00104188 size=1
// signature: undefined fortify_panic(void)
// callers: [affinity_initialize_workfn]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fortify_panic(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



