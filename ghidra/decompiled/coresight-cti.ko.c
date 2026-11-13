// Decompiled by Ghidra 12.2
// Program: coresight-cti.ko
// Image base: 00100000

//------------------------------------------------------------
// cti_write_all_hw_regs @ 001012d4 size=428
// signature: undefined cti_write_all_hw_regs(void)
// callers: [cti_starting_cpu, chan_xtrigs_reset_store, cti_enable, cti_cpu_pm_notify]
//------------------------------------------------------------

void cti_write_all_hw_regs(long *param_1)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*param_1);
  if ((char)param_1[0x96] == '\0') {
    if (*(int *)((long)param_1 + 0x44) < 1) {
      lVar2 = 0x14;
      lVar3 = 0x144;
      lVar4 = 0x140;
    }
    else {
      lVar6 = 0;
      lVar5 = 0;
      lVar2 = 0x14;
      lVar3 = 0x144;
      lVar4 = 0x140;
      do {
        if (lVar6 == 0x200) goto LAB_0010147c;
        writel_relaxed(*(undefined4 *)((long)param_1 + lVar6 + 0x8c),*param_1 + lVar6 + 0x20);
        writel_relaxed(*(undefined4 *)((long)param_1 + lVar6 + 0x28c),*param_1 + lVar6 + 0xa0);
        lVar5 = lVar5 + 1;
        lVar6 = lVar6 + 4;
      } while (lVar5 < *(int *)((long)param_1 + 0x44));
    }
  }
  else if (*(int *)((long)param_1 + 0x44) < 1) {
    lVar2 = 4;
    lVar3 = 0x8c;
    lVar4 = 0x88;
  }
  else {
    lVar5 = 0;
    lVar6 = 0x400;
    lVar2 = 4;
    lVar3 = 0x8c;
    lVar4 = 0x88;
    do {
      if (lVar6 == 0x600) {
LAB_0010147c:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101480);
        (*pcVar1)();
      }
      writel_relaxed(*(undefined4 *)((long)param_1 + lVar6 + -0x374),*param_1 + lVar6);
      writel_relaxed(*(undefined4 *)((long)param_1 + lVar6 + -0x174),*param_1 + lVar6 + 0x400);
      lVar5 = lVar5 + 1;
      lVar6 = lVar6 + 4;
    } while (lVar5 < *(int *)((long)param_1 + 0x44));
  }
  writel_relaxed(*(undefined4 *)((long)param_1 + 0x48c),*param_1 + lVar4);
  writel_relaxed((int)param_1[0x92],*param_1 + lVar3);
  writel_relaxed(*(undefined4 *)((long)param_1 + 0x84),*param_1 + lVar2);
  writel_relaxed(1,*param_1);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*param_1 + 0xfb0);
  return;
}



//------------------------------------------------------------
// writel_relaxed @ 00101480 size=132
// signature: undefined writel_relaxed(void)
// callers: [cti_write_all_hw_regs, cti_channel_trig_op, cti_write_intack, cti_channel_setop, cti_write_single_reg, cti_channel_gate_op, cti_disable]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x101498,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1014d4,uVar1);
  return;
}



//------------------------------------------------------------
// cti_write_single_reg @ 00101508 size=112
// signature: undefined cti_write_single_reg(void)
// callers: [appset_store, inen_store, appclear_store, apppulse_store, outen_store, gate_store, asicctl_store]
//------------------------------------------------------------

void cti_write_single_reg(long *param_1,int param_2,undefined4 param_3)

{
  writel_relaxed(0xc5acce55,*param_1 + 0xfb0);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(param_3,*param_1 + (long)param_2);
  DataSynchronizationBarrier(3,3,0);
  writel_relaxed(0,*param_1 + 0xfb0);
  return;
}



//------------------------------------------------------------
// cti_write_intack @ 0010157c size=148
// signature: undefined cti_write_intack(void)
// callers: [intack_store]
//------------------------------------------------------------

void cti_write_intack(long param_1,undefined4 param_2)

{
  long *plVar1;
  
  plVar1 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(plVar1 + 7);
  if ((*(char *)((long)plVar1 + 0x4d) != '\0') && (*(char *)((long)plVar1 + 0x4c) != '\0')) {
    writel_relaxed(0xc5acce55,*plVar1 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(param_2,*plVar1 + 0x10);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar1 + 0xfb0);
  }
  _raw_spin_unlock(plVar1 + 7);
  return;
}



//------------------------------------------------------------
// cti_add_connection_entry @ 00101614 size=220
// signature: undefined cti_add_connection_entry(void)
// callers: [coresight_cti_get_platform_data, cti_add_default_connection]
//------------------------------------------------------------

undefined8
cti_add_connection_entry(undefined8 param_1,long param_2,long *param_3,long param_4,long param_5)

{
  long *plVar1;
  ulong uVar2;
  long lVar3;
  long *plVar4;
  
  param_3[2] = param_4;
  if (param_4 == 0) {
    if (param_5 != 0) {
      lVar3 = devm_kstrdup(param_1,param_5,0xcc0);
      param_3[3] = lVar3;
      if (lVar3 == 0) {
        return 0xfffffff4;
      }
    }
  }
  else {
    lVar3 = *(long *)(param_4 + 0xa8);
    if (lVar3 == 0) {
      lVar3 = *(long *)(param_4 + 0x38);
    }
    param_3[3] = lVar3;
  }
  plVar4 = *(long **)(param_2 + 0x20);
  plVar1 = param_3 + 4;
  uVar2 = __list_add_valid(plVar1,plVar4,param_2 + 0x18);
  if ((uVar2 & 1) != 0) {
    *(long **)(param_2 + 0x20) = plVar1;
    param_3[4] = param_2 + 0x18;
    param_3[5] = (long)plVar4;
    *plVar4 = (long)plVar1;
  }
  *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
  __bitmap_or(param_2 + 0x50,param_2 + 0x50,*param_3 + 8,*(undefined4 *)(param_2 + 0x44));
  __bitmap_or(param_2 + 0x60,param_2 + 0x60,param_3[1] + 8,*(undefined4 *)(param_2 + 0x44));
  return 0;
}



//------------------------------------------------------------
// cti_allocate_trig_con @ 001016f4 size=156
// signature: undefined cti_allocate_trig_con(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

long * cti_allocate_trig_con(undefined8 param_1,uint param_2,uint param_3)

{
  long *plVar1;
  uint *puVar2;
  uint *puVar3;
  
  plVar1 = (long *)devm_kmalloc(param_1,0x40,0xdc0);
  if (plVar1 != (long *)0x0) {
    puVar2 = (uint *)devm_kmalloc(param_1,(-(ulong)(param_2 >> 0x1f) & 0xfffffffc00000000 |
                                          (ulong)param_2 << 2) + 0x18,0xdc0);
    if ((puVar2 == (uint *)0x0) ||
       (puVar3 = (uint *)devm_kmalloc(param_1,(-(ulong)(param_3 >> 0x1f) & 0xfffffffc00000000 |
                                              (ulong)param_3 << 2) + 0x18,0xdc0),
       puVar3 == (uint *)0x0)) {
      plVar1 = (long *)0x0;
    }
    else {
      *plVar1 = (long)puVar2;
      plVar1[1] = (long)puVar3;
      *puVar2 = param_2;
      *puVar3 = param_3;
    }
  }
  return plVar1;
}



//------------------------------------------------------------
// cti_add_default_connection @ 00101794 size=240
// signature: undefined cti_add_default_connection(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

undefined8 cti_add_default_connection(undefined8 param_1,long param_2)

{
  long lVar1;
  int iVar2;
  undefined8 *puVar3;
  int *piVar4;
  int *piVar5;
  undefined8 uVar6;
  ulong __n;
  
  iVar2 = *(int *)(param_2 + 0x44);
  puVar3 = (undefined8 *)devm_kmalloc(param_1,0x40,0xdc0);
  if (puVar3 != (undefined8 *)0x0) {
    lVar1 = (long)iVar2 * 4 + 0x18;
    piVar4 = (int *)devm_kmalloc(param_1,lVar1,0xdc0);
    if ((piVar4 != (int *)0x0) &&
       (piVar5 = (int *)devm_kmalloc(param_1,lVar1,0xdc0), piVar5 != (int *)0x0)) {
      *puVar3 = piVar4;
      puVar3[1] = piVar5;
      __n = (ulong)(iVar2 + 0x3fU >> 3 & 0x1ffffff8);
      *piVar4 = iVar2;
      *piVar5 = iVar2;
      memset(piVar4 + 2,0xff,__n);
      memset(piVar5 + 2,0xff,__n);
      uVar6 = cti_add_connection_entry(param_1,param_2,puVar3,0,"default");
      return uVar6;
    }
  }
  return 0xfffffff4;
}



//------------------------------------------------------------
// cti_trigin_gpio_disable @ 00101888 size=60
// signature: undefined cti_trigin_gpio_disable(void)
// callers: [chan_xtrigs_reset_store]
//------------------------------------------------------------

void cti_trigin_gpio_disable(long param_1)

{
  if (**(long **)(param_1 + 0x4b8) != 0) {
    devm_pinctrl_put();
    **(undefined8 **)(param_1 + 0x4b8) = 0;
  }
  return;
}



//------------------------------------------------------------
// cti_trigout_gpio_disable @ 001018c8 size=60
// signature: undefined cti_trigout_gpio_disable(void)
// callers: [chan_xtrigs_reset_store]
//------------------------------------------------------------

void cti_trigout_gpio_disable(long param_1)

{
  if (**(long **)(param_1 + 0x4c0) != 0) {
    devm_pinctrl_put();
    **(undefined8 **)(param_1 + 0x4c0) = 0;
  }
  return;
}



//------------------------------------------------------------
// cti_channel_trig_op @ 00101908 size=576
// signature: undefined cti_channel_trig_op(void)
// callers: [trigout_attach_store, trigout_detach_store, trigin_attach_store, trigin_detach_store]
//------------------------------------------------------------

undefined8 cti_channel_trig_op(long param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  undefined8 *puVar4;
  int iVar5;
  ulong uVar6;
  long *plVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if ((*(uint *)(plVar7 + 8) <= param_4) || (*(uint *)((long)plVar7 + 0x44) <= param_5)) {
    return 0xffffffea;
  }
  uVar6 = 1L << ((ulong)param_5 & 0x3f);
  if (param_3 == 0) {
    if ((plVar7[(ulong)(param_5 >> 6) + 10] & uVar6) == 0) {
      return 0xffffffea;
    }
    iVar3 = 0x20;
    iVar5 = 0x400;
  }
  else {
    if ((plVar7[(ulong)(param_5 >> 6) + 0xc] & uVar6) == 0) {
      return 0xffffffea;
    }
    if (((char)plVar7[0x10] != '\0') &&
       ((*(ulong *)((long)plVar7 + ((ulong)(param_5 >> 3) & 0x1ffffff8) + 0x70) >>
         ((ulong)param_5 & 0x3f) & 1) != 0)) {
      return 0xffffffea;
    }
    iVar3 = 0xa0;
    iVar5 = 0x800;
  }
  if ((char)plVar7[0x96] != '\0') {
    iVar3 = iVar5;
  }
  _raw_spin_lock(plVar7 + 7);
  uVar10 = (uint)(1L << ((ulong)param_4 & 0x3f));
  if (param_3 == 0) {
    if (0x7f < param_5) goto LAB_00101b44;
    uVar8 = *(uint *)((long)plVar7 + (ulong)param_5 * 4 + 0x8c);
    uVar9 = uVar8 | uVar10;
    uVar8 = uVar8 & (uVar10 ^ 0xffffffff);
    uVar10 = uVar9;
    if (param_2 != 0) {
      uVar10 = uVar8;
    }
    *(uint *)((long)plVar7 + (ulong)param_5 * 4 + 0x8c) = uVar10;
    bVar2 = *(uint *)((long *)plVar7[0x97] + 1) == param_5;
    if (param_2 == 0) {
      if (bVar2) {
        cti_trigin_gpio_enable(plVar7);
      }
      goto LAB_00101ae4;
    }
    if ((!bVar2) || (*(long *)plVar7[0x97] == 0)) {
      uVar9 = uVar8;
      goto LAB_00101ae4;
    }
    devm_pinctrl_put();
    puVar4 = (undefined8 *)plVar7[0x97];
  }
  else {
    if (0x7f < param_5) {
LAB_00101b44:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x101b48);
      (*pcVar1)();
    }
    uVar8 = *(uint *)((long)plVar7 + (ulong)param_5 * 4 + 0x28c);
    uVar9 = uVar8 | uVar10;
    uVar8 = uVar8 & (uVar10 ^ 0xffffffff);
    uVar10 = uVar9;
    if (param_2 != 0) {
      uVar10 = uVar8;
    }
    *(uint *)((long)plVar7 + (ulong)param_5 * 4 + 0x28c) = uVar10;
    if (param_2 == 0) {
      if ((param_3 == 1) && (*(uint *)(plVar7[0x98] + 8) == param_5)) {
        cti_trigout_gpio_enable(plVar7);
      }
      goto LAB_00101ae4;
    }
    if (((param_3 != 1) || (*(uint *)((long *)plVar7[0x98] + 1) != param_5)) ||
       (*(long *)plVar7[0x98] == 0)) {
      uVar9 = uVar8;
      goto LAB_00101ae4;
    }
    devm_pinctrl_put();
    puVar4 = (undefined8 *)plVar7[0x98];
  }
  *puVar4 = 0;
  uVar9 = uVar8;
LAB_00101ae4:
  if ((*(char *)((long)plVar7 + 0x4d) != '\0') && (*(char *)((long)plVar7 + 0x4c) != '\0')) {
    writel_relaxed(0xc5acce55,*plVar7 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(uVar9,*plVar7 + (long)(int)(iVar3 + param_5 * 4));
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar7 + 0xfb0);
  }
  _raw_spin_unlock(plVar7 + 7);
  return 0;
}



//------------------------------------------------------------
// cti_trigin_gpio_enable @ 00101b48 size=184
// signature: undefined cti_trigin_gpio_enable(void)
// callers: [cti_channel_trig_op]
//------------------------------------------------------------

void cti_trigin_gpio_enable(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if (**(long **)(param_1 + 0x4b8) == 0) {
    uVar2 = devm_pinctrl_get(*(undefined8 *)(*(long *)(param_1 + 8) + 0x98));
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = pinctrl_lookup_state(uVar2,"cti-trigin-pctrl");
      if (uVar3 < 0xfffffffffffff001) {
        iVar1 = pinctrl_select_state(uVar2,uVar3);
        if (iVar1 == 0) {
          **(ulong **)(param_1 + 0x4b8) = uVar2;
          return;
        }
        pcVar4 = "pinctrl enable state failed\n";
      }
      else {
        pcVar4 = "pinctrl get state failed\n";
      }
      _dev_err(*(long *)(param_1 + 8) + 0x38,pcVar4);
      devm_pinctrl_put(uVar2);
    }
    else {
      _dev_err(*(long *)(param_1 + 8) + 0x38,"pinctrl get failed\n");
    }
  }
  return;
}



//------------------------------------------------------------
// cti_trigout_gpio_enable @ 00101c00 size=184
// signature: undefined cti_trigout_gpio_enable(void)
// callers: [cti_channel_trig_op]
//------------------------------------------------------------

void cti_trigout_gpio_enable(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  char *pcVar4;
  
  if (**(long **)(param_1 + 0x4c0) == 0) {
    uVar2 = devm_pinctrl_get(*(undefined8 *)(*(long *)(param_1 + 8) + 0x98));
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = pinctrl_lookup_state(uVar2,"cti-trigout-pctrl");
      if (uVar3 < 0xfffffffffffff001) {
        iVar1 = pinctrl_select_state(uVar2,uVar3);
        if (iVar1 == 0) {
          **(ulong **)(param_1 + 0x4c0) = uVar2;
          return;
        }
        pcVar4 = "pinctrl enable state failed\n";
      }
      else {
        pcVar4 = "pinctrl get state failed\n";
      }
      _dev_err(*(long *)(param_1 + 8) + 0x38,pcVar4);
      devm_pinctrl_put(uVar2);
    }
    else {
      _dev_err(*(long *)(param_1 + 8) + 0x38,"pinctrl get failed\n");
    }
  }
  return;
}



//------------------------------------------------------------
// cti_channel_gate_op @ 00101cbc size=256
// signature: undefined cti_channel_gate_op(void)
// callers: [chan_gate_disable_store, chan_gate_enable_store]
//------------------------------------------------------------

undefined8 cti_channel_gate_op(long param_1,int param_2,uint param_3)

{
  long lVar1;
  uint uVar2;
  undefined8 uVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(uint *)(plVar4 + 8) <= param_3) {
    return 0xffffffea;
  }
  _raw_spin_lock(plVar4 + 7);
  uVar2 = (uint)(1L << ((ulong)param_3 & 0x3f));
  if (param_2 == 1) {
    uVar2 = *(uint *)((long)plVar4 + 0x48c) & (uVar2 ^ 0xffffffff);
  }
  else {
    if (param_2 != 0) {
      uVar3 = 0xffffffea;
      goto LAB_00101d9c;
    }
    uVar2 = *(uint *)((long)plVar4 + 0x48c) | uVar2;
  }
  *(uint *)((long)plVar4 + 0x48c) = uVar2;
  if ((*(char *)((long)plVar4 + 0x4d) != '\0') && (*(char *)((long)plVar4 + 0x4c) != '\0')) {
    lVar1 = plVar4[0x96];
    writel_relaxed(0xc5acce55,*plVar4 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    if ((char)lVar1 == '\0') {
      writel_relaxed(uVar2,*plVar4 + 0x140);
      lVar1 = *plVar4;
      DataSynchronizationBarrier(3,3,0);
    }
    else {
      writel_relaxed(uVar2,*plVar4 + 0x88);
      lVar1 = *plVar4;
      DataSynchronizationBarrier(3,3,0);
    }
    writel_relaxed(0,lVar1 + 0xfb0);
  }
  uVar3 = 0;
LAB_00101d9c:
  _raw_spin_unlock(plVar4 + 7);
  return uVar3;
}



//------------------------------------------------------------
// cti_channel_setop @ 00101dc0 size=308
// signature: undefined cti_channel_setop(void)
// callers: [chan_pulse_store, chan_set_store, chan_clear_store]
//------------------------------------------------------------

undefined8 cti_channel_setop(long param_1,int param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  long lVar4;
  ulong uVar5;
  undefined8 uVar6;
  long *plVar7;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  if (*(uint *)(plVar7 + 8) <= param_3) {
    return 0xffffffea;
  }
  uVar5 = 1L << ((ulong)param_3 & 0x3f);
  _raw_spin_lock(plVar7 + 7);
  if (param_2 == 2) {
    cVar1 = (char)plVar7[0x96];
    lVar4 = 0x1c;
    lVar3 = 0xc;
LAB_00101e74:
    if (cVar1 != '\0') {
      lVar4 = lVar3;
    }
    *(uint *)((long)plVar7 + 0x84) = *(uint *)((long)plVar7 + 0x84) & ((uint)uVar5 ^ 0xffffffff);
    cVar1 = *(char *)((long)plVar7 + 0x4d);
  }
  else {
    if (param_2 == 1) {
      cVar1 = (char)plVar7[0x96];
      lVar4 = 0x18;
      lVar3 = 8;
      goto LAB_00101e74;
    }
    if (param_2 != 0) {
      uVar6 = 0xffffffea;
      goto LAB_00101ed4;
    }
    uVar2 = *(uint *)((long)plVar7 + 0x84) | (uint)uVar5;
    uVar5 = (ulong)uVar2;
    lVar4 = 0x14;
    if ((char)plVar7[0x96] != '\0') {
      lVar4 = 4;
    }
    *(uint *)((long)plVar7 + 0x84) = uVar2;
    cVar1 = *(char *)((long)plVar7 + 0x4d);
  }
  if ((cVar1 != '\0') && (*(char *)((long)plVar7 + 0x4c) != '\0')) {
    writel_relaxed(0xc5acce55,*plVar7 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(uVar5 & 0xffffffff,*plVar7 + lVar4);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar7 + 0xfb0);
  }
  uVar6 = 0;
LAB_00101ed4:
  _raw_spin_unlock(plVar7 + 7);
  return uVar6;
}



//------------------------------------------------------------
// cti_enable @ 00101ef8 size=208
// signature: undefined cti_enable(void)
// callers: [enable_store, cti_restore]
//------------------------------------------------------------

int cti_enable(long param_1)

{
  int *piVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined8 uVar5;
  long lVar6;
  
  lVar6 = *(long *)(*(long *)(param_1 + 0x98) + 0x98);
  uVar5 = _raw_spin_lock_irqsave(lVar6 + 0x38);
  if ((*(char *)(lVar6 + 0x4c) == '\0') && (*(char *)(lVar6 + 0x4d) != '\0')) {
    if (*(char *)(lVar6 + 0x4b0) == '\0') {
      iVar4 = coresight_claim_device(*(undefined8 *)(lVar6 + 8));
      if (iVar4 != 0) goto LAB_00101f40;
    }
    cti_write_all_hw_regs(lVar6);
    *(undefined1 *)(lVar6 + 0x4c) = 1;
    piVar1 = (int *)(lVar6 + 0x48);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  else {
    piVar1 = (int *)(lVar6 + 0x48);
    Hint_Prefetch(piVar1,2,0,1);
    do {
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(piVar1,0x10);
      if (bVar3) {
        *piVar1 = *piVar1 + 1;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
  }
  iVar4 = 0;
LAB_00101f40:
  _raw_spin_unlock_irqrestore(lVar6 + 0x38,uVar5);
  return iVar4;
}



//------------------------------------------------------------
// cti_disable @ 00101fe8 size=236
// signature: undefined cti_disable(void)
// callers: [enable_store, cti_freeze]
//------------------------------------------------------------

undefined8 cti_disable(long param_1)

{
  long *plVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  long *plVar7;
  
  plVar7 = *(long **)(*(long *)(param_1 + 0x98) + 0x98);
  lVar5 = plVar7[1];
  _raw_spin_lock(plVar7 + 7);
  if ((int)plVar7[9] == 0) {
    uVar6 = 0xffffffea;
  }
  else {
    plVar1 = plVar7 + 9;
    Hint_Prefetch(plVar1,2,0,1);
    do {
      iVar4 = (int)*plVar1 + -1;
      cVar2 = '\x01';
      bVar3 = (bool)ExclusiveMonitorPass(plVar1,0x10);
      if (bVar3) {
        *(int *)plVar1 = iVar4;
        cVar2 = ExclusiveMonitorsStatus();
      }
    } while (cVar2 != '\0');
    DataMemoryBarrier(2,3);
    if (((iVar4 < 1) && (*(char *)((long)plVar7 + 0x4c) != '\0')) &&
       (*(char *)((long)plVar7 + 0x4d) != '\0')) {
      writel_relaxed(0xc5acce55,*plVar7 + 0xfb0);
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(0,*plVar7);
      *(undefined1 *)((long)plVar7 + 0x4c) = 0;
      if ((char)plVar7[0x96] == '\0') {
        coresight_disclaim_device_unlocked(lVar5);
      }
      DataSynchronizationBarrier(3,3,0);
      writel_relaxed(0,*plVar7 + 0xfb0);
    }
    uVar6 = 0;
  }
  _raw_spin_unlock(plVar7 + 7);
  return uVar6;
}



//------------------------------------------------------------
// cti_probe @ 001020f0 size=1156
// signature: undefined cti_probe(void)
// callers: []
//------------------------------------------------------------

ulong cti_probe(long param_1)

{
  ulong *puVar1;
  long lVar2;
  undefined *puVar3;
  code *pcVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  ulong *puVar8;
  ulong uVar9;
  ulong uVar10;
  ulong uVar11;
  undefined8 uVar12;
  undefined8 local_a8;
  undefined8 local_a0;
  undefined1 *local_98;
  ulong local_90;
  long local_88;
  ulong local_80;
  long local_78;
  undefined8 local_70;
  ulong local_68;
  undefined8 local_60;
  undefined8 uStack_58;
  undefined4 local_4c;
  long local_48;
  
  lVar2 = sp_el0;
  local_48 = *(long *)(lVar2 + 0x638);
  local_60 = 0;
  uStack_58 = 0;
  local_70 = 0;
  local_68 = 0;
  local_80 = 0;
  local_78 = 0;
  local_90 = 0;
  local_88 = 0;
  local_a0 = 0;
  local_98 = (undefined1 *)0x0;
  local_a8 = 0;
  puVar8 = (ulong *)devm_kmalloc(param_1,0x4c8,0xdc0);
  if (puVar8 == (ulong *)0x0) goto LAB_00102304;
  uVar9 = devm_ioremap_resource(param_1,param_1 + 0x390);
  if (0xfffffffffffff000 < uVar9) goto LAB_00102308;
  *puVar8 = uVar9;
  *(ulong **)(param_1 + 0x98) = puVar8;
  local_70 = CONCAT71(local_70._1_7_,1);
  *(undefined4 *)(puVar8 + 5) = 0xffffffff;
  puVar8[2] = 0;
  puVar8[3] = (ulong)(puVar8 + 3);
  puVar8[4] = (ulong)(puVar8 + 3);
  *(undefined4 *)(puVar8 + 7) = 0;
  local_68 = uVar9;
  uVar6 = readl_relaxed(uVar9 + 0xfc8);
  uVar7 = uVar6 >> 8 & 0xff;
  *(uint *)((long)puVar8 + 0x44) = uVar7;
  if (0x80 < uVar7) {
    if ((cti_set_default_config___print_once & 1) == 0) {
      cti_set_default_config___print_once = 1;
      _dev_warn(param_1,"Limiting HW MaxTrig value(%d) to driver max(%d)\n",uVar7,0x80);
    }
    *(undefined4 *)((long)puVar8 + 0x44) = 0x80;
  }
  uVar7 = uVar6 >> 0x10 & 0xf;
  *(undefined1 *)(puVar8 + 0x10) = 1;
  *(uint *)(puVar8 + 8) = uVar7;
  *(int *)((long)puVar8 + 0x48c) = (int)(0xffffffffffffffff >> ((ulong)-uVar7 & 0x3f));
  *(undefined4 *)(puVar8 + 9) = 0;
  uVar10 = coresight_cti_get_platform_data(param_1);
  if (0xfffffffffffff000 < uVar10) {
    _dev_err(param_1,"coresight_cti_get_platform_data err\n");
    uVar9 = uVar10 & 0xffffffff;
    goto LAB_00102308;
  }
  *(undefined1 *)((long)puVar8 + 0x4d) = 1;
  if ((int)puVar8[5] < 0) {
    local_78 = coresight_alloc_device_name(cti_sys_devs,param_1);
  }
  else {
    local_78 = devm_kasprintf(param_1,0xcc0,"cti_cpu%d");
  }
  if (local_78 != 0) {
    local_4c = 0;
    uVar9 = devm_kmalloc(param_1,0x10,0xdc0);
    puVar8[0x97] = uVar9;
    if (uVar9 != 0) {
      uVar12 = *(undefined8 *)(param_1 + 0x2e8);
      *(undefined4 *)(uVar9 + 8) = 0xffffffff;
      uVar7 = of_property_read_variable_u32_array(uVar12,"qcom,cti-gpio-trigin",&local_4c,1,0);
      if (-1 < (int)uVar7) {
        uVar7 = 0;
      }
      if (uVar7 == 0xffffffea) {
LAB_001022a0:
        uVar9 = devm_kmalloc(param_1,0x10,0xdc0);
        puVar8[0x98] = uVar9;
        if (uVar9 == 0) goto LAB_00102304;
        uVar12 = *(undefined8 *)(param_1 + 0x2e8);
        *(undefined4 *)(uVar9 + 8) = 0xffffffff;
        uVar7 = of_property_read_variable_u32_array(uVar12,"qcom,cti-gpio-trigout",&local_4c,1,0);
        if (-1 < (int)uVar7) {
          uVar7 = 0;
        }
        if (uVar7 != 0xffffffea) {
          if (uVar7 != 0) goto LAB_0010233c;
          *(undefined4 *)(puVar8[0x98] + 8) = local_4c;
        }
      }
      else {
        if (uVar7 == 0) {
          *(undefined4 *)(puVar8[0x97] + 8) = local_4c;
          goto LAB_001022a0;
        }
LAB_0010233c:
        uVar9 = (ulong)uVar7;
        if (uVar7 != 0) goto LAB_00102308;
      }
      uVar7 = (uint)puVar8[5];
      if (uVar7 == 0xffffffff) {
LAB_00102374:
        uVar7 = cti_create_cons_sysfs(param_1,puVar8);
        if (uVar7 == 0) {
          local_80 = puVar8[6];
          local_a8 = 0x100000005;
          local_98 = cti_ops;
          local_90 = uVar10;
          local_88 = param_1;
          uVar9 = coresight_register(&local_a8);
          puVar8[1] = uVar9;
          if (uVar9 < 0xfffffffffffff001) {
            mutex_lock(ect_mutex);
            puVar3 = ect_net;
            puVar1 = puVar8 + 0x93;
            uVar9 = __list_add_valid(puVar1,&ect_net,ect_net);
            if ((uVar9 & 1) != 0) {
              *(ulong **)(puVar3 + 8) = puVar1;
              puVar8[0x93] = (ulong)puVar3;
              puVar8[0x94] = (ulong)&ect_net;
              ect_net = (undefined *)puVar1;
            }
            cti_update_conn_xrefs(puVar8);
            mutex_unlock(ect_mutex);
            puVar8[0x95] = *(ulong *)(puVar8[1] + 0x360);
            *(code **)(puVar8[1] + 0x360) = cti_device_release;
            bVar5 = fwnode_property_present(*(undefined8 *)(param_1 + 0x2f0),"qcom,extended_cti");
            *(byte *)(puVar8 + 0x96) = bVar5 & 1;
            __pm_runtime_idle(param_1,5);
            _dev_info(puVar8[1] + 0x38,"CTI initialized\n");
            uVar9 = 0;
            goto LAB_00102308;
          }
          uVar9 = uVar9 & 0xffffffff;
        }
        else {
          uVar9 = (ulong)uVar7;
          _dev_err(param_1,"%s: create dynamic sysfs entries failed\n",local_78);
        }
        uVar7 = (uint)puVar8[5];
        if (uVar7 == 0xffffffff) goto LAB_00102308;
        if (0x1f < uVar7) {
LAB_00102570:
                    /* WARNING: Does not return */
          pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x102574);
          (*pcVar4)();
        }
        nr_cti_cpu = nr_cti_cpu + -1;
        *(undefined8 *)(cti_cpu_drvdata + (ulong)uVar7 * 8) = 0;
        if (nr_cti_cpu != 0) goto LAB_00102308;
        cpu_pm_unregister_notifier(&cti_cpu_pm_nb);
      }
      else {
        if (nr_cti_cpu != 0) {
LAB_00102358:
          nr_cti_cpu = nr_cti_cpu + 1;
          if (0x1f < uVar7) goto LAB_00102570;
          *(ulong **)(cti_cpu_drvdata + (ulong)uVar7 * 8) = puVar8;
          goto LAB_00102374;
        }
        cpus_read_lock();
        uVar9 = __cpuhp_setup_state_cpuslocked
                          (0x92,"arm/coresight_cti:starting",0,cti_starting_cpu,cti_dying_cpu,0);
        if ((int)uVar9 != 0) {
          uVar9 = uVar9 & 0xffffffff;
          cpus_read_unlock();
          goto LAB_00102308;
        }
        uVar11 = cpu_pm_register_notifier(&cti_cpu_pm_nb);
        uVar9 = uVar11 & 0xffffffff;
        cpus_read_unlock();
        if ((int)uVar11 == 0) {
          uVar7 = (uint)puVar8[5];
          goto LAB_00102358;
        }
      }
      __cpuhp_remove_state(0x92,0);
      goto LAB_00102308;
    }
  }
LAB_00102304:
  uVar9 = 0xfffffff4;
LAB_00102308:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar9 & 0xffffffff;
}



//------------------------------------------------------------
// cti_remove @ 00102578 size=216
// signature: undefined cti_remove(void)
// callers: []
//------------------------------------------------------------

void cti_remove(long param_1)

{
  long lVar1;
  undefined8 *puVar2;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  lVar1 = *(long *)(param_1 + 0x98);
  mutex_lock(ect_mutex);
  for (puVar2 = *(undefined8 **)(lVar1 + 0x18); puVar2 != (undefined8 *)(lVar1 + 0x18);
      puVar2 = (undefined8 *)*puVar2) {
    if (puVar2[-2] != 0) {
      coresight_set_assoc_ectdev_mutex(puVar2[-2],0);
      local_58 = *(long *)(lVar1 + 8);
      local_50 = puVar2[-1];
      local_40 = *(long *)(local_58 + 0xa8);
      local_48 = puVar2[-2];
      if (local_40 == 0) {
        local_40 = *(long *)(local_58 + 0x38);
      }
      coresight_remove_sysfs_link(&local_58);
      puVar2[-2] = 0;
    }
  }
  mutex_unlock(ect_mutex);
  coresight_unregister(*(undefined8 *)(lVar1 + 8));
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cti_freeze @ 00102654 size=60
// signature: undefined cti_freeze(void)
// callers: []
//------------------------------------------------------------

undefined8 cti_freeze(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar2 + 0x4c) == '\0') {
    uVar1 = 0;
  }
  else {
    *(undefined1 *)(lVar2 + 0x4e) = 1;
    uVar1 = cti_disable(*(undefined8 *)(lVar2 + 8));
  }
  return uVar1;
}



//------------------------------------------------------------
// cti_restore @ 00102694 size=64
// signature: undefined cti_restore(void)
// callers: []
//------------------------------------------------------------

undefined8 cti_restore(long param_1)

{
  undefined8 uVar1;
  long lVar2;
  
  lVar2 = *(long *)(param_1 + 0x98);
  if (*(char *)(lVar2 + 0x4e) == '\0') {
    uVar1 = 0;
  }
  else {
    uVar1 = cti_enable(*(undefined8 *)(lVar2 + 8));
    *(undefined1 *)(lVar2 + 0x4e) = 0;
  }
  return uVar1;
}



//------------------------------------------------------------
// cti_update_conn_xrefs @ 001026d4 size=236
// signature: undefined cti_update_conn_xrefs(void)
// callers: [cti_probe]
//------------------------------------------------------------

void cti_update_conn_xrefs(long param_1)

{
  long lVar1;
  int iVar2;
  long *plVar3;
  long local_58;
  undefined8 local_50;
  undefined8 local_48;
  long local_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  for (plVar3 = *(long **)(param_1 + 0x18); plVar3 != (long *)(param_1 + 0x18);
      plVar3 = (long *)*plVar3) {
    if (plVar3[-2] != 0) {
      local_58 = *(long *)(param_1 + 8);
      local_50 = plVar3[-1];
      local_40 = *(long *)(local_58 + 0xa8);
      local_48 = plVar3[-2];
      if (local_40 == 0) {
        local_40 = *(long *)(local_58 + 0x38);
      }
      iVar2 = coresight_add_sysfs_link(&local_58);
      if (iVar2 == 0) {
        coresight_set_assoc_ectdev_mutex(plVar3[-2],*(undefined8 *)(param_1 + 8));
      }
      else {
        _dev_warn(*(long *)(param_1 + 8) + 0x38,"Failed to set CTI sysfs link %s<=>%s\n",local_50,
                  local_40);
        plVar3[-2] = 0;
      }
    }
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cti_device_release @ 001027c4 size=276
// signature: undefined cti_device_release(void)
// callers: []
//------------------------------------------------------------

void cti_device_release(long param_1)

{
  undefined *puVar1;
  long *plVar2;
  uint uVar3;
  ulong uVar4;
  code *pcVar5;
  undefined **ppuVar6;
  undefined **ppuVar7;
  
  ppuVar7 = *(undefined ***)(*(long *)(param_1 + 0x60) + 0x98);
  mutex_lock(ect_mutex);
  uVar3 = *(uint *)(ppuVar7 + 5);
  if (uVar3 != 0xffffffff) {
    if (0x1f < uVar3) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x1028d8);
      (*pcVar5)();
    }
    *(undefined8 *)(cti_cpu_drvdata + (ulong)uVar3 * 8) = 0;
    nr_cti_cpu = nr_cti_cpu + -1;
    if (nr_cti_cpu == 0) {
      cpu_pm_unregister_notifier(&cti_cpu_pm_nb);
      __cpuhp_remove_state(0x92,0);
    }
  }
  ppuVar6 = &ect_net;
  do {
    ppuVar6 = (undefined **)*ppuVar6;
    if (ppuVar6 == &ect_net) goto LAB_0010288c;
  } while (ppuVar6 + -0x93 != ppuVar7);
  uVar4 = __list_del_entry_valid(ppuVar6);
  if ((uVar4 & 1) != 0) {
    puVar1 = *ppuVar6;
    plVar2 = (long *)ppuVar6[1];
    *(long **)(puVar1 + 8) = plVar2;
    *plVar2 = (long)puVar1;
  }
  *ppuVar6 = (undefined *)0xdead000000000100;
  ppuVar6[1] = (undefined *)0xdead000000000122;
LAB_0010288c:
  mutex_unlock(ect_mutex);
  pcVar5 = (code *)ppuVar7[0x95];
  if (pcVar5 != (code *)0x0) {
    if (*(int *)(pcVar5 + -4) != -0x6b11820d) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x8228,0x1028bc);
      (*pcVar5)();
    }
    (*pcVar5)(param_1);
  }
  return;
}



//------------------------------------------------------------
// readl_relaxed @ 001028d8 size=124
// signature: undefined readl_relaxed(void)
// callers: [cti_probe]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x102920,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// cti_starting_cpu @ 00102958 size=128
// signature: undefined cti_starting_cpu(void)
// callers: []
//------------------------------------------------------------

undefined8 cti_starting_cpu(uint param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x1029d8);
    (*pcVar1)();
  }
  lVar3 = *(long *)(cti_cpu_drvdata + (ulong)param_1 * 8);
  if (lVar3 != 0) {
    _raw_spin_lock(lVar3 + 0x38);
    *(undefined1 *)(lVar3 + 0x4d) = 1;
    if ((*(int *)(lVar3 + 0x48) != 0) &&
       (iVar2 = coresight_claim_device(*(undefined8 *)(lVar3 + 8)), iVar2 == 0)) {
      cti_write_all_hw_regs(lVar3);
      *(undefined1 *)(lVar3 + 0x4c) = 1;
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  return 0;
}



//------------------------------------------------------------
// cti_dying_cpu @ 001029dc size=104
// signature: undefined cti_dying_cpu(void)
// callers: []
//------------------------------------------------------------

undefined8 cti_dying_cpu(uint param_1)

{
  code *pcVar1;
  long lVar2;
  
  if (0x1f < param_1) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x102a44);
    (*pcVar1)();
  }
  lVar2 = *(long *)(cti_cpu_drvdata + (ulong)param_1 * 8);
  if (lVar2 != 0) {
    _raw_spin_lock(lVar2 + 0x38);
    *(undefined1 *)(lVar2 + 0x4d) = 0;
    if (*(char *)(lVar2 + 0x4c) != '\0') {
      coresight_disclaim_device(*(undefined8 *)(lVar2 + 8));
    }
    _raw_spin_unlock(lVar2 + 0x38);
  }
  return 0;
}



//------------------------------------------------------------
// cti_cpu_pm_notify @ 00102a48 size=284
// signature: undefined cti_cpu_pm_notify(void)
// callers: []
//------------------------------------------------------------

undefined8 cti_cpu_pm_notify(undefined8 param_1,long param_2)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  lVar4 = tpidr_el1;
  uVar1 = *(uint *)(&cpu_number + lVar4);
  if (0x1f < uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x102b68);
    (*pcVar2)();
  }
  lVar4 = *(long *)(cti_cpu_drvdata + (ulong)uVar1 * 8);
  if (lVar4 == 0) {
    return 1;
  }
  if (*(uint *)(lVar4 + 0x28) != uVar1) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x800,0x102b60);
    (*pcVar2)();
  }
  uVar6 = *(undefined8 *)(lVar4 + 8);
  _raw_spin_lock(lVar4 + 0x38);
  if (param_2 == 2) {
    *(undefined2 *)(lVar4 + 0x4c) = 0x100;
    if (*(int *)(lVar4 + 0x48) != 0) {
      iVar3 = coresight_claim_device(uVar6);
      uVar5 = 1;
      if (iVar3 == 0) {
        *(undefined1 *)(lVar4 + 0x4c) = 1;
        cti_write_all_hw_regs(lVar4);
      }
      goto LAB_00102b38;
    }
  }
  else {
    if (param_2 == 1) {
      *(undefined1 *)(lVar4 + 0x4d) = 1;
      uVar5 = 1;
      if (*(char *)(lVar4 + 0x4c) != '\0') {
        iVar3 = coresight_claim_device(uVar6);
        uVar5 = 1;
        if (iVar3 != 0) {
          *(undefined1 *)(lVar4 + 0x4c) = 0;
        }
      }
      goto LAB_00102b38;
    }
    if (param_2 != 0) {
      uVar5 = 0;
      goto LAB_00102b38;
    }
    *(undefined1 *)(lVar4 + 0x4d) = 0;
    if (*(char *)(lVar4 + 0x4c) != '\0') {
      coresight_disclaim_device(uVar6);
    }
  }
  uVar5 = 1;
LAB_00102b38:
  _raw_spin_unlock(lVar4 + 0x38);
  return uVar5;
}



//------------------------------------------------------------
// cti_add_assoc_to_csdev @ 00102b6c size=376
// signature: undefined cti_add_assoc_to_csdev(void)
// callers: []
//------------------------------------------------------------

void cti_add_assoc_to_csdev(undefined *param_1)

{
  long lVar1;
  int iVar2;
  char *__s1;
  undefined *puVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  undefined *local_78;
  undefined *local_70;
  undefined *local_68;
  long local_60;
  long local_58;
  
  lVar1 = sp_el0;
  local_58 = *(long *)(lVar1 + 0x638);
  mutex_lock(ect_mutex);
  if ((*(int *)(param_1 + 8) != 5) && ((undefined **)ect_net != &ect_net)) {
    dev_fwnode(*(undefined8 *)(param_1 + 0x98));
    __s1 = (char *)cti_plat_get_node_name();
    if ((__s1 != (char *)0x0) &&
       (ppuVar4 = (undefined **)ect_net, (undefined **)ect_net != &ect_net)) {
      do {
        for (ppuVar5 = (undefined **)ppuVar4[-0x90]; ppuVar5 != ppuVar4 + -0x90;
            ppuVar5 = (undefined **)*ppuVar5) {
          if ((ppuVar5[-1] != (char *)0x0) && (iVar2 = strcmp(__s1,ppuVar5[-1]), iVar2 == 0)) {
            puVar3 = *(undefined **)(param_1 + 0xa8);
            if (puVar3 == (undefined *)0x0) {
              puVar3 = *(undefined **)(param_1 + 0x38);
            }
            ppuVar6 = ppuVar4 + -0x92;
            ppuVar5[-2] = param_1;
            ppuVar5[-1] = puVar3;
            local_78 = *ppuVar6;
            local_70 = ppuVar5[-1];
            local_60 = *(long *)(local_78 + 0xa8);
            local_68 = ppuVar5[-2];
            if (local_60 == 0) {
              local_60 = *(long *)(local_78 + 0x38);
            }
            iVar2 = coresight_add_sysfs_link(&local_78);
            if (iVar2 == 0) {
              coresight_set_assoc_ectdev_mutex(param_1,*ppuVar6);
              goto LAB_00102ca0;
            }
            _dev_warn(*ppuVar6 + 0x38,"Failed to set CTI sysfs link %s<=>%s\n",local_70,local_60);
            ppuVar5[-2] = (undefined *)0x0;
            break;
          }
        }
        ppuVar4 = (undefined **)*ppuVar4;
      } while (ppuVar4 != &ect_net);
    }
  }
LAB_00102ca0:
  mutex_unlock(ect_mutex);
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cti_remove_assoc_from_csdev @ 00102ce8 size=208
// signature: undefined cti_remove_assoc_from_csdev(void)
// callers: []
//------------------------------------------------------------

void cti_remove_assoc_from_csdev(long param_1)

{
  long *plVar1;
  long lVar2;
  long *plVar3;
  long local_48;
  undefined8 local_40;
  undefined8 local_38;
  long local_30;
  long local_28;
  
  lVar2 = sp_el0;
  local_28 = *(long *)(lVar2 + 0x638);
  mutex_lock(ect_mutex);
  if (*(long *)(param_1 + 1000) != 0) {
    lVar2 = *(long *)(*(long *)(*(long *)(param_1 + 1000) + 0x98) + 0x98);
    plVar1 = (long *)(lVar2 + 0x18);
    plVar3 = plVar1;
    do {
      plVar3 = (long *)*plVar3;
      if (plVar3 == plVar1) goto LAB_00102d7c;
    } while (plVar3[-2] != param_1);
    local_48 = *(long *)(lVar2 + 8);
    local_40 = plVar3[-1];
    local_30 = *(long *)(local_48 + 0xa8);
    local_38 = plVar3[-2];
    if (local_30 == 0) {
      local_30 = *(long *)(local_48 + 0x38);
    }
    coresight_remove_sysfs_link(&local_48);
    plVar3[-2] = 0;
LAB_00102d7c:
    *(undefined8 *)(param_1 + 1000) = 0;
  }
  mutex_unlock(ect_mutex);
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// cti_plat_get_node_name @ 00102dc4 size=76
// signature: undefined cti_plat_get_node_name(void)
// callers: [cti_add_assoc_to_csdev]
//------------------------------------------------------------

char * cti_plat_get_node_name(ulong param_1)

{
  if (((param_1 == 0) || (0xfffffffffffff000 < param_1)) ||
     (*(undefined **)(param_1 + 8) != &of_fwnode_ops)) {
    return "unknown";
  }
  if (param_1 == 0x18) {
    return "<no-node>";
  }
  return *(char **)(param_1 - 8);
}



//------------------------------------------------------------
// coresight_cti_get_platform_data @ 00102e14 size=1888
// signature: undefined coresight_cti_get_platform_data(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long coresight_cti_get_platform_data(long param_1)

{
  ulong *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ulong uVar7;
  long lVar8;
  ulong uVar9;
  ulong uVar10;
  undefined8 *puVar11;
  long lVar12;
  char *pcVar13;
  long *plVar14;
  long *plVar15;
  long lVar16;
  long lVar17;
  char *local_d0;
  char local_c8 [16];
  long local_b8 [11];
  
  lVar8 = sp_el0;
  local_b8[10] = *(long *)(lVar8 + 0x638);
  uVar7 = dev_fwnode();
  iVar6 = -2;
  if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
    lVar16 = *(long *)(param_1 + 0x98);
    lVar8 = devm_kmalloc(param_1,0x10,0xdc0);
    if (lVar8 == 0) {
      iVar6 = -0xc;
    }
    else {
      device_property_read_u32_array(param_1,"arm,cti-ctm-id",lVar16 + 0x14,1);
      uVar7 = dev_fwnode(param_1);
      if ((((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) ||
          (*(undefined **)(uVar7 + 8) != &of_fwnode_ops)) ||
         (iVar6 = of_device_is_compatible(uVar7 - 0x18,"arm,coresight-cti-v8-arch"), iVar6 == 0)) {
        uVar7 = dev_fwnode(param_1);
        iVar6 = -0x16;
        if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
          uVar9 = fwnode_get_next_child_node(uVar7,0);
          if (uVar9 != 0) {
            do {
              if ((uVar9 < 0xfffffffffffff001) && (*(undefined **)(uVar9 + 8) == &of_fwnode_ops)) {
                lVar17 = uVar9 - 0x18;
                uVar10 = of_node_name_eq(lVar17,"trig-conns");
                if ((uVar10 & 1) != 0) {
                  local_d0 = "unknown";
                  local_c8[0] = '\0';
                  local_c8[1] = '\0';
                  local_c8[2] = '\0';
                  local_c8[3] = '\0';
                  local_c8[4] = '\0';
                  local_c8[5] = '\0';
                  local_c8[6] = '\0';
                  local_c8[7] = '\0';
                  local_c8[8] = '\0';
                  local_c8[9] = '\0';
                  local_c8[10] = '\0';
                  local_c8[0xb] = '\0';
                  local_c8[0xc] = '\0';
                  local_c8[0xd] = '\0';
                  local_c8[0xe] = '\0';
                  local_c8[0xf] = '\0';
                  iVar4 = fwnode_property_read_u32_array(uVar9,"arm,trig-in-sigs",0,0);
                  if (iVar4 < 1) {
                    iVar4 = 0;
                  }
                  iVar5 = fwnode_property_read_u32_array(uVar9,"arm,trig-out-sigs",0,0);
                  if (iVar5 < 1) {
                    iVar5 = 0;
                  }
                  iVar6 = -0x16;
                  if ((*(int *)(lVar16 + 0x44) < iVar4) || (*(int *)(lVar16 + 0x44) < iVar5))
                  goto LAB_00103388;
                  puVar11 = (undefined8 *)cti_allocate_trig_con(param_1,iVar4);
                  if (puVar11 == (undefined8 *)0x0) {
LAB_00103420:
                    iVar6 = -0xc;
                    goto LAB_00103388;
                  }
                  iVar6 = cti_plat_read_trig_group(*puVar11,uVar9,"arm,trig-in-sigs");
                  if ((((iVar6 != 0) ||
                       (iVar6 = cti_plat_read_trig_types(*puVar11,uVar9,"arm,trig-in-types"),
                       iVar6 != 0)) ||
                      (iVar6 = cti_plat_read_trig_group(puVar11[1],uVar9,"arm,trig-out-sigs"),
                      iVar6 != 0)) ||
                     (iVar6 = cti_plat_read_trig_types(puVar11[1],uVar9,"arm,trig-out-types"),
                     iVar6 != 0)) goto LAB_00103388;
                  iVar6 = fwnode_property_read_u32_array(uVar9,"arm,trig-filters",0,0);
                  if (0 < iVar6) {
                    if (*(int *)(lVar16 + 0x44) < iVar6) {
                      iVar6 = -0x16;
                      goto LAB_00103388;
                    }
                    lVar12 = kmalloc_trace(___kmalloc,0xdc0,0x18);
                    if (lVar12 == 0) goto LAB_00103420;
                    iVar6 = cti_plat_read_trig_group(lVar12,uVar9,"arm,trig-filters");
                    if (iVar6 != 0) {
                      kfree(lVar12);
                      goto LAB_00103388;
                    }
                    __bitmap_or(lVar16 + 0x70,lVar16 + 0x70,lVar12 + 8,
                                *(undefined4 *)(lVar16 + 0x44));
                    kfree(lVar12);
                  }
                  fwnode_property_read_string(uVar9,"arm,trig-conn-name",&local_d0);
                  if ((lVar17 == 0) || (*(undefined **)(uVar9 + 8) != &of_fwnode_ops)) {
LAB_001032f4:
                    uVar10 = fwnode_find_reference(uVar9,"arm,cs-dev-assoc",0);
                    if (uVar10 < 0xfffffffffffff001) {
                      lVar17 = coresight_find_csdev_by_fwnode();
                      if (lVar17 == 0) {
                        if (uVar10 == 0) {
                          local_d0 = "unknown";
                        }
                        else {
                          local_d0 = "unknown";
                          if (*(undefined **)(uVar10 + 8) == &of_fwnode_ops) {
                            if (uVar10 != 0x18) {
                              plVar14 = (long *)(uVar10 - 8);
                              goto LAB_00103330;
                            }
                            local_d0 = "<no-node>";
                          }
                        }
                      }
                      else {
                        local_d0 = *(char **)(lVar17 + 0xa8);
                        if (local_d0 == (char *)0x0) {
                          plVar14 = (long *)(lVar17 + 0x38);
LAB_00103330:
                          local_d0 = (char *)*plVar14;
                        }
                      }
                      fwnode_handle_put(uVar10);
                    }
                    else {
                      lVar17 = 0;
                    }
                  }
                  else {
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
                    iVar6 = __of_parse_phandle_with_args(lVar17,&DAT_00105fd7,0,0,0,local_b8);
                    if ((iVar6 != 0) ||
                       ((local_b8[0] == 0 || (iVar6 = of_cpu_node_to_id(), iVar6 < 0))))
                    goto LAB_001032f4;
                    *(int *)(lVar16 + 0x28) = iVar6;
                    scnprintf(local_c8,0x10,"cpu%d",iVar6);
                    lVar17 = 0;
                    local_d0 = local_c8;
                  }
                  iVar6 = cti_add_connection_entry(param_1,lVar16,puVar11,lVar17,local_d0);
                  if (iVar6 != 0) goto LAB_00103388;
                }
              }
              uVar9 = fwnode_get_next_child_node(uVar7,uVar9);
            } while (uVar9 != 0);
          }
          iVar6 = 0;
LAB_00103388:
          fwnode_handle_put(uVar9);
          goto LAB_00103390;
        }
      }
      else {
        local_c8[0] = '\0';
        local_c8[1] = '\0';
        local_c8[2] = '\0';
        local_c8[3] = '\0';
        local_c8[4] = '\0';
        local_c8[5] = '\0';
        local_c8[6] = '\0';
        local_c8[7] = '\0';
        local_c8[8] = '\0';
        local_c8[9] = '\0';
        local_c8[10] = '\0';
        local_c8[0xb] = '\0';
        local_c8[0xc] = '\0';
        local_c8[0xd] = '\0';
        local_c8[0xe] = '\0';
        local_c8[0xf] = '\0';
        uVar7 = dev_fwnode(param_1);
        if ((((uVar7 == 0) || (0xfffffffffffff000 < uVar7)) ||
            (*(undefined **)(uVar7 + 8) != &of_fwnode_ops)) || (uVar7 - 0x18 == 0)) {
LAB_00103408:
          _dev_warn(param_1,"ARM v8 architectural CTI connection: missing cpu\n");
          iVar6 = -0x16;
        }
        else {
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
          iVar6 = __of_parse_phandle_with_args(uVar7 - 0x18,&DAT_00105fd7,0,0,0,local_b8);
          if ((iVar6 != 0) || (local_b8[0] == 0)) goto LAB_00103408;
          iVar6 = of_cpu_node_to_id();
          if (iVar6 < 0) {
            iVar6 = -1;
          }
          if (iVar6 < 0) goto LAB_00103408;
          *(int *)(lVar16 + 0x28) = iVar6;
          plVar14 = (long *)cti_allocate_trig_con(param_1,2,3);
          if (plVar14 == (long *)0x0) {
            iVar6 = -0xc;
          }
          else {
            *(ulong *)(*plVar14 + 8) = *(ulong *)(*plVar14 + 8) | 3;
            *(undefined4 *)(*plVar14 + 0x18) = 9;
            *(undefined4 *)(*plVar14 + 0x1c) = 8;
            *(ulong *)(plVar14[1] + 8) = *(ulong *)(plVar14[1] + 8) | 7;
            *(undefined4 *)(plVar14[1] + 0x18) = 5;
            *(undefined4 *)(plVar14[1] + 0x1c) = 6;
            *(undefined4 *)(plVar14[1] + 0x20) = 7;
            scnprintf(local_c8,0x10,"cpu%d",iVar6);
            iVar6 = cti_add_connection_entry(param_1,lVar16,plVar14,0,local_c8);
            if (iVar6 == 0) {
              uVar7 = dev_fwnode(param_1);
              iVar6 = -0x16;
              if ((uVar7 != 0) && (uVar7 < 0xfffffffffffff001)) {
                uVar7 = fwnode_find_reference(uVar7,"arm,cs-dev-assoc",0);
                if (uVar7 < 0xfffffffffffff001) {
                  plVar14 = (long *)cti_allocate_trig_con(param_1,4,4);
                  if (plVar14 == (long *)0x0) {
                    fwnode_handle_put(uVar7);
                    iVar6 = -0xc;
                  }
                  else {
                    *(ulong *)(*plVar14 + 8) = *(ulong *)(*plVar14 + 8) | 0xf0;
                    *(ulong *)(plVar14[1] + 8) = *(ulong *)(plVar14[1] + 8) | 0xf0;
                    *(undefined4 *)(*plVar14 + 0x18) = 10;
                    *(undefined4 *)(plVar14[1] + 0x18) = 0xb;
                    *(undefined4 *)(*plVar14 + 0x1c) = 10;
                    *(undefined4 *)(plVar14[1] + 0x1c) = 0xb;
                    *(undefined4 *)(*plVar14 + 0x20) = 10;
                    *(undefined4 *)(plVar14[1] + 0x20) = 0xb;
                    *(undefined4 *)(*plVar14 + 0x24) = 10;
                    *(undefined4 *)(plVar14[1] + 0x24) = 0xb;
                    lVar17 = coresight_find_csdev_by_fwnode(uVar7);
                    if (lVar17 == 0) {
                      if ((uVar7 == 0) || (*(undefined **)(uVar7 + 8) != &of_fwnode_ops)) {
                        pcVar13 = "unknown";
                      }
                      else {
                        if (uVar7 != 0x18) {
                          plVar15 = (long *)(uVar7 - 8);
                          goto LAB_001034f4;
                        }
                        pcVar13 = "<no-node>";
                      }
                    }
                    else {
                      pcVar13 = *(char **)(lVar17 + 0xa8);
                      if (pcVar13 == (char *)0x0) {
                        plVar15 = (long *)(lVar17 + 0x38);
LAB_001034f4:
                        pcVar13 = (char *)*plVar15;
                      }
                    }
                    iVar6 = cti_add_connection_entry(param_1,lVar16,plVar14,lVar17,pcVar13);
                    fwnode_handle_put(uVar7);
                    if (iVar6 == 0) goto LAB_00103078;
                  }
                }
                else {
LAB_00103078:
                  puVar1 = (ulong *)(lVar16 + 0x70);
                  Hint_Prefetch(puVar1,2,0,1);
                  do {
                    cVar2 = '\x01';
                    bVar3 = (bool)ExclusiveMonitorPass(puVar1,0x10);
                    if (bVar3) {
                      *puVar1 = *puVar1 | 1;
                      cVar2 = ExclusiveMonitorsStatus();
                    }
                  } while (cVar2 != '\0');
                  iVar6 = 0;
                }
              }
            }
          }
        }
LAB_00103390:
        if ((iVar6 == 0) &&
           ((*(int *)(lVar16 + 0x10) != 0 ||
            (iVar6 = cti_add_default_connection(param_1,lVar16), iVar6 == 0)))) goto LAB_00103398;
      }
    }
  }
  lVar8 = (long)iVar6;
LAB_00103398:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_b8[10]) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar8;
}



//------------------------------------------------------------
// cti_plat_read_trig_group @ 00103588 size=264
// signature: undefined cti_plat_read_trig_group(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

int cti_plat_read_trig_group(int *param_1,undefined8 param_2,undefined8 param_3)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  ulong uVar8;
  long lVar9;
  int iVar10;
  
  iVar10 = *param_1;
  if (iVar10 == 0) {
    iVar10 = 0;
  }
  else {
    if (-1 < iVar10) {
      lVar7 = __kmalloc((long)iVar10 * 4,0xdc0);
      if (lVar7 != 0) {
        iVar6 = fwnode_property_read_u32_array(param_2,param_3,lVar7,(long)*param_1);
        if ((iVar6 == 0) && (0 < *param_1)) {
          uVar8 = 0;
          lVar9 = 0;
          do {
            if (((long)uVar8 < 0) || ((ulong)((long)iVar10 * 4) <= uVar8)) {
                    /* WARNING: Does not return */
              pcVar5 = (code *)SoftwareBreakpoint(1,0x103698);
              (*pcVar5)();
            }
            uVar2 = *(uint *)(lVar7 + uVar8);
            puVar1 = (ulong *)(param_1 + (ulong)(uVar2 >> 6) * 2 + 2);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar4) {
                *puVar1 = *puVar1 | 1L << ((ulong)uVar2 & 0x3f);
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            lVar9 = lVar9 + 1;
            uVar8 = uVar8 + 4;
          } while (lVar9 < *param_1);
        }
        kfree(lVar7);
        return iVar6;
      }
    }
    iVar10 = -0xc;
  }
  return iVar10;
}



//------------------------------------------------------------
// cti_plat_read_trig_types @ 00103698 size=312
// signature: undefined cti_plat_read_trig_types(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

int cti_plat_read_trig_types(uint *param_1,undefined8 param_2,undefined8 param_3)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  long lVar7;
  uint uVar8;
  ulong uVar9;
  ulong uVar10;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    return 0;
  }
  uVar3 = fwnode_property_read_u32_array(param_2,param_3,0,0);
  uVar8 = uVar3;
  if ((int)uVar3 < 1) {
    uVar8 = 0;
  }
  uVar9 = (ulong)uVar8;
  if ((int)uVar1 < (int)uVar8) {
    return -0x16;
  }
  if ((int)uVar3 < 1) {
    uVar10 = 0;
    lVar5 = 0;
  }
  else {
    uVar10 = uVar9 << 2;
    lVar5 = __kmalloc(uVar10,0xdc0);
    if (lVar5 == 0) {
      return -0xc;
    }
    iVar4 = fwnode_property_read_u32_array(param_2,param_3,lVar5,uVar9);
    if (iVar4 != 0) goto LAB_0010379c;
  }
  uVar6 = 0;
  lVar7 = 6;
  do {
    if (lVar7 - 6U < uVar9) {
      if (uVar10 <= uVar6) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(1,0x1037d0);
        (*pcVar2)();
      }
      uVar8 = *(uint *)(lVar5 + uVar6);
      if (0x18 < uVar8) {
        uVar8 = 0;
      }
    }
    else {
      uVar8 = 0;
    }
    *(uint *)((long)param_1 + uVar6 + 0x18) = uVar8;
    lVar7 = lVar7 + 1;
    uVar6 = uVar6 + 4;
  } while (lVar7 - (ulong)uVar1 != 6);
  iVar4 = 0;
LAB_0010379c:
  kfree(lVar5);
  return iVar4;
}



//------------------------------------------------------------
// cti_create_cons_sysfs @ 001037d4 size=748
// signature: undefined cti_create_cons_sysfs(void)
// callers: [cti_probe]
//------------------------------------------------------------

undefined8 cti_create_cons_sysfs(undefined8 param_1,long param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  undefined8 *puVar5;
  long *plVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  undefined8 uVar10;
  int iVar11;
  long *plVar12;
  long *plVar13;
  long *plVar14;
  
  uVar1 = *(int *)(param_2 + 0x10) + 5;
  if ((int)uVar1 < 0) {
    uVar10 = 0xfffffff4;
    *(undefined8 *)(param_2 + 0x30) = 0;
  }
  else {
    puVar5 = (undefined8 *)devm_kmalloc(param_1,(ulong)uVar1 << 3,0xdc0);
    *(undefined8 **)(param_2 + 0x30) = puVar5;
    puVar4 = PTR_coresight_cti_channels_group_001066d8;
    puVar3 = PTR_coresight_cti_regs_group_001066d0;
    puVar2 = PTR_coresight_cti_mgmt_group_001066c8;
    if (puVar5 == (undefined8 *)0x0) {
LAB_00103a90:
      uVar10 = 0xfffffff4;
    }
    else {
      plVar13 = (long *)(param_2 + 0x18);
      plVar14 = (long *)*plVar13;
      *puVar5 = coresight_cti_groups;
      puVar5[1] = puVar2;
      puVar5[2] = puVar3;
      puVar5[3] = puVar4;
      if (plVar14 != plVar13) {
        iVar11 = 0;
        do {
          plVar6 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
          if (plVar6 == (long *)0x0) goto LAB_00103a90;
          lVar7 = devm_kasprintf(param_1,0xcc0,"triggers%d",iVar11);
          *plVar6 = lVar7;
          if (lVar7 == 0) goto LAB_00103a90;
          *(long **)(*(long *)(param_2 + 0x30) + (long)(iVar11 + 4) * 8) = plVar6;
          plVar14[3] = (long)plVar6;
          lVar7 = devm_kmalloc(param_1,0x30,0xdc0);
          plVar14[2] = lVar7;
          if (((lVar7 == 0) ||
              (plVar8 = (long *)devm_kmalloc(param_1,0x28,0xdc0), plVar8 == (long *)0x0)) ||
             (lVar7 = devm_kstrdup(param_1,&DAT_00105cd1,0xcc0), lVar7 == 0)) goto LAB_00103a90;
          plVar12 = plVar14 + -4;
          *plVar8 = lVar7;
          *(undefined2 *)(plVar8 + 1) = 0x124;
          plVar8[4] = (long)plVar12;
          plVar8[2] = (long)con_name_show;
          *(long **)plVar14[2] = plVar8;
          if (*(int *)plVar14[-4] < 1) {
            lVar7 = 1;
          }
          else {
            plVar8 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
            if ((plVar8 == (long *)0x0) ||
               (lVar7 = devm_kstrdup(param_1,"in_signals",0xcc0), lVar7 == 0)) goto LAB_00103a90;
            *plVar8 = lVar7;
            *(undefined2 *)(plVar8 + 1) = 0x124;
            plVar8[2] = (long)trigin_sig_show;
            plVar8[4] = (long)plVar12;
            *(long **)(plVar14[2] + 8) = plVar8;
            plVar8 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
            if ((plVar8 == (long *)0x0) ||
               (lVar7 = devm_kstrdup(param_1,"in_types",0xcc0), lVar7 == 0)) goto LAB_00103a90;
            *plVar8 = lVar7;
            lVar7 = 3;
            *(undefined2 *)(plVar8 + 1) = 0x124;
            plVar8[2] = (long)trigin_type_show;
            plVar8[4] = (long)plVar12;
            *(long **)(plVar14[2] + 0x10) = plVar8;
          }
          if (0 < *(int *)plVar14[-3]) {
            plVar8 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
            if ((plVar8 == (long *)0x0) ||
               (lVar9 = devm_kstrdup(param_1,"out_signals",0xcc0), lVar9 == 0)) goto LAB_00103a90;
            *plVar8 = lVar9;
            *(undefined2 *)(plVar8 + 1) = 0x124;
            plVar8[2] = (long)trigout_sig_show;
            plVar8[4] = (long)plVar12;
            *(long **)(plVar14[2] + lVar7 * 8) = plVar8;
            plVar8 = (long *)devm_kmalloc(param_1,0x28,0xdc0);
            if ((plVar8 == (long *)0x0) ||
               (lVar9 = devm_kstrdup(param_1,"out_types",0xcc0), lVar9 == 0)) goto LAB_00103a90;
            *plVar8 = lVar9;
            *(undefined2 *)(plVar8 + 1) = 0x124;
            plVar8[2] = (long)trigout_type_show;
            plVar8[4] = (long)plVar12;
            *(long **)(plVar14[2] + (lVar7 + 1) * 8) = plVar8;
          }
          iVar11 = iVar11 + 1;
          plVar6[3] = plVar14[2];
          plVar14 = (long *)*plVar14;
        } while (plVar14 != plVar13);
      }
      uVar10 = 0;
    }
  }
  return uVar10;
}



//------------------------------------------------------------
// con_name_show @ 00103ac4 size=52
// signature: undefined con_name_show(void)
// callers: []
//------------------------------------------------------------

long con_name_show(undefined8 param_1,long param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%s\n",*(undefined8 *)(*(long *)(param_2 + 0x20) + 0x18));
  return (long)iVar1;
}



//------------------------------------------------------------
// trigin_sig_show @ 00103afc size=68
// signature: undefined trigin_sig_show(void)
// callers: []
//------------------------------------------------------------

long trigin_sig_show(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = bitmap_print_to_pagebuf
                    (1,param_3,**(long **)(param_2 + 0x20) + 8,
                     *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// trigout_sig_show @ 00103b44 size=68
// signature: undefined trigout_sig_show(void)
// callers: []
//------------------------------------------------------------

long trigout_sig_show(long param_1,long param_2,undefined8 param_3)

{
  int iVar1;
  
  iVar1 = bitmap_print_to_pagebuf
                    (1,param_3,*(long *)(*(long *)(param_2 + 0x20) + 8) + 8,
                     *(undefined4 *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// trigin_type_show @ 00103b8c size=180
// signature: undefined trigin_type_show(void)
// callers: []
//------------------------------------------------------------

long trigin_type_show(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined8 *puVar5;
  long lVar6;
  
  puVar5 = *(undefined8 **)(param_2 + 0x20);
  piVar3 = (int *)*puVar5;
  if (*piVar3 < 1) {
    iVar4 = 0;
  }
  else {
    lVar6 = 0;
    iVar4 = 0;
    do {
      if (0x18 < (uint)piVar3[lVar6 + 6]) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103c40);
        (*pcVar1)();
      }
      iVar2 = sprintf((char *)(param_3 + iVar4),"%s ",(&sig_type_names)[(uint)piVar3[lVar6 + 6]]);
      piVar3 = (int *)*puVar5;
      iVar4 = iVar2 + iVar4;
      lVar6 = lVar6 + 1;
    } while (lVar6 < *piVar3);
  }
  *(undefined2 *)(param_3 + iVar4) = 10;
  return (long)(iVar4 + 1);
}



//------------------------------------------------------------
// trigout_type_show @ 00103c44 size=180
// signature: undefined trigout_type_show(void)
// callers: []
//------------------------------------------------------------

long trigout_type_show(undefined8 param_1,long param_2,long param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  
  lVar5 = *(long *)(param_2 + 0x20);
  piVar3 = *(int **)(lVar5 + 8);
  if (*piVar3 < 1) {
    iVar4 = 0;
  }
  else {
    lVar6 = 0;
    iVar4 = 0;
    do {
      if (0x18 < (uint)piVar3[lVar6 + 6]) {
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x103cf8);
        (*pcVar1)();
      }
      iVar2 = sprintf((char *)(param_3 + iVar4),"%s ",(&sig_type_names)[(uint)piVar3[lVar6 + 6]]);
      piVar3 = *(int **)(lVar5 + 8);
      iVar4 = iVar2 + iVar4;
      lVar6 = lVar6 + 1;
    } while (lVar6 < *piVar3);
  }
  *(undefined2 *)(param_3 + iVar4) = 10;
  return (long)(iVar4 + 1);
}



//------------------------------------------------------------
// enable_show @ 00103cfc size=128
// signature: undefined enable_show(void)
// callers: []
//------------------------------------------------------------

long enable_show(long param_1,undefined8 param_2,char *param_3)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  long lVar5;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar4 = *(int *)(lVar5 + 0x48);
  _raw_spin_lock(lVar5 + 0x38);
  cVar1 = *(char *)(lVar5 + 0x4d);
  bVar2 = *(byte *)(lVar5 + 0x4c);
  _raw_spin_unlock(lVar5 + 0x38);
  bVar3 = iVar4 != 0;
  if (cVar1 != '\0') {
    bVar3 = bVar2;
  }
  iVar4 = sprintf(param_3,"%d\n",(ulong)bVar3);
  return (long)iVar4;
}



//------------------------------------------------------------
// enable_store @ 00103d80 size=320
// signature: undefined enable_store(void)
// callers: []
//------------------------------------------------------------

long enable_store(long param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  long lVar8;
  long local_40;
  long local_38;
  
  lVar8 = sp_el0;
  local_38 = *(long *)(lVar8 + 0x638);
  local_40 = 0;
  lVar8 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = kstrtoull(param_3,0,&local_40);
  if (iVar5 != 0) {
    param_4 = (long)iVar5;
    goto LAB_00103ea0;
  }
  if (local_40 == 0) {
    iVar5 = cti_disable(*(undefined8 *)(lVar8 + 8));
    if (iVar5 == 0) {
      __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),5);
      goto LAB_00103ea0;
    }
  }
  else {
    lVar7 = *(long *)(param_1 + 0x60);
    iVar5 = __pm_runtime_resume(lVar7,4);
    if (iVar5 < 0) {
      piVar1 = (int *)(lVar7 + 0x1f8);
      iVar6 = *(int *)(lVar7 + 0x1f8);
      do {
        if (iVar6 == 0) break;
        Hint_Prefetch(piVar1,2,0,1);
        do {
          iVar2 = *piVar1;
          if (iVar2 != iVar6) goto LAB_00103e58;
          cVar3 = '\x01';
          bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
          if (bVar4) {
            *piVar1 = iVar6 + -1;
            cVar3 = ExclusiveMonitorsStatus();
          }
        } while (cVar3 != '\0');
        DataMemoryBarrier(2,3);
LAB_00103e58:
        bVar4 = iVar6 != iVar2;
        iVar6 = iVar2;
      } while (bVar4);
      param_4 = (long)iVar5;
      goto LAB_00103ea0;
    }
    iVar5 = cti_enable(*(undefined8 *)(lVar8 + 8));
    if (iVar5 == 0) goto LAB_00103ea0;
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),5);
  }
  param_4 = (long)iVar5;
LAB_00103ea0:
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// powered_show @ 00103ed8 size=100
// signature: undefined powered_show(void)
// callers: []
//------------------------------------------------------------

long powered_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar1 = lVar4 + 0x38;
  _raw_spin_lock(lVar1);
  bVar2 = *(byte *)(lVar4 + 0x4d);
  _raw_spin_unlock(lVar1);
  iVar3 = sprintf(param_3,"%d\n",(ulong)bVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// ctmid_show @ 00103f40 size=60
// signature: undefined ctmid_show(void)
// callers: []
//------------------------------------------------------------

long ctmid_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",
                  (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x14));
  return (long)iVar1;
}



//------------------------------------------------------------
// nr_trigger_cons_show @ 00103f80 size=60
// signature: undefined nr_trigger_cons_show(void)
// callers: []
//------------------------------------------------------------

long nr_trigger_cons_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",
                  (ulong)*(uint *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x10));
  return (long)iVar1;
}



//------------------------------------------------------------
// coresight_cti_reg_show @ 00103fc0 size=256
// signature: undefined coresight_cti_reg_show(void)
// callers: []
//------------------------------------------------------------

long coresight_cti_reg_show(long param_1,long param_2,undefined8 param_3)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  long *plVar8;
  
  plVar8 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = __pm_runtime_resume(*(long *)(param_1 + 0x60),4);
  if (iVar5 < 0) {
    piVar1 = (int *)(*(long *)(param_1 + 0x60) + 0x1f8);
    iVar7 = *(int *)(*(long *)(param_1 + 0x60) + 0x1f8);
    do {
      if (iVar7 == 0) break;
      Hint_Prefetch(piVar1,2,0,1);
      do {
        iVar2 = *piVar1;
        if (iVar2 != iVar7) goto LAB_00104054;
        cVar3 = '\x01';
        bVar4 = (bool)ExclusiveMonitorPass(piVar1,0x10);
        if (bVar4) {
          *piVar1 = iVar7 + -1;
          cVar3 = ExclusiveMonitorsStatus();
        }
      } while (cVar3 != '\0');
      DataMemoryBarrier(2,3);
LAB_00104054:
      bVar4 = iVar7 != iVar2;
      iVar7 = iVar2;
    } while (bVar4);
  }
  else {
    _raw_spin_lock(plVar8 + 7);
    if (*(char *)((long)plVar8 + 0x4d) == '\0') {
      uVar6 = 0;
    }
    else {
      uVar6 = readl_relaxed(*plVar8 + (ulong)*(uint *)(param_2 + 0x20));
    }
    _raw_spin_unlock(plVar8 + 7);
    __pm_runtime_idle(*(undefined8 *)(param_1 + 0x60),4);
    iVar5 = sysfs_emit(param_3,"0x%x\n",uVar6);
  }
  return (long)iVar5;
}



//------------------------------------------------------------
// readl_relaxed @ 001040d4 size=124
// signature: undefined readl_relaxed(void)
// callers: [coresight_cti_reg_show, gate_show, appset_show, asicctl_show]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10411c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// inout_sel_show @ 00104154 size=60
// signature: undefined inout_sel_show(void)
// callers: []
//------------------------------------------------------------

long inout_sel_show(long param_1,undefined8 param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = sprintf(param_3,"%d\n",
                  (ulong)*(byte *)(*(long *)(*(long *)(param_1 + 0x60) + 0x98) + 0x88));
  return (long)iVar1;
}



//------------------------------------------------------------
// inout_sel_store @ 00104194 size=176
// signature: undefined inout_sel_store(void)
// callers: []
//------------------------------------------------------------

void inout_sel_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  undefined8 uVar3;
  long lVar4;
  ulong local_40;
  long local_38;
  
  lVar4 = sp_el0;
  local_38 = *(long *)(lVar4 + 0x638);
  local_40 = 0;
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0,&local_40);
  uVar3 = 0xffffffffffffffea;
  if ((iVar2 == 0) && (local_40 < 0x80)) {
    lVar1 = lVar4 + 0x38;
    _raw_spin_lock(lVar1);
    *(char *)(lVar4 + 0x88) = (char)local_40;
    _raw_spin_unlock(lVar1);
    uVar3 = param_4;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(uVar3);
  }
  return;
}



//------------------------------------------------------------
// inen_show @ 00104248 size=120
// signature: undefined inen_show(void)
// callers: []
//------------------------------------------------------------

long inen_show(long param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(lVar4 + 0x38);
  if ((char)*(byte *)(lVar4 + 0x88) < '\0') {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1042c0);
    (*pcVar2)();
  }
  uVar1 = *(uint *)(lVar4 + (ulong)*(byte *)(lVar4 + 0x88) * 4 + 0x8c);
  _raw_spin_unlock(lVar4 + 0x38);
  iVar3 = sprintf(param_3,"%#lx\n",(ulong)uVar1);
  return (long)iVar3;
}



//------------------------------------------------------------
// inen_store @ 001042c4 size=240
// signature: undefined inen_store(void)
// callers: []
//------------------------------------------------------------

undefined8 inen_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = kstrtoull(param_3,0,&local_40);
  if (iVar5 == 0) {
    _raw_spin_lock(lVar6 + 0x38);
    bVar3 = *(byte *)(lVar6 + 0x88);
    if ((char)bVar3 < '\0') {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x1043b4);
      (*pcVar4)();
    }
    cVar2 = *(char *)(lVar6 + 0x4d);
    *(int *)(lVar6 + (ulong)bVar3 * 4 + 0x8c) = (int)local_40;
    if ((cVar2 != '\0') && (*(char *)(lVar6 + 0x4c) != '\0')) {
      uVar1 = (uint)bVar3 * 4 + 0x20;
      if (*(char *)(lVar6 + 0x4b0) != '\0') {
        uVar1 = (uint)bVar3 << 2 | 0x400;
      }
      cti_write_single_reg(lVar6,uVar1,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar6 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// outen_show @ 001043b8 size=120
// signature: undefined outen_show(void)
// callers: []
//------------------------------------------------------------

long outen_show(long param_1,undefined8 param_2,char *param_3)

{
  uint uVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(lVar4 + 0x38);
  if ((char)*(byte *)(lVar4 + 0x88) < '\0') {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x104430);
    (*pcVar2)();
  }
  uVar1 = *(uint *)(lVar4 + (ulong)*(byte *)(lVar4 + 0x88) * 4 + 0x28c);
  _raw_spin_unlock(lVar4 + 0x38);
  iVar3 = sprintf(param_3,"%#lx\n",(ulong)uVar1);
  return (long)iVar3;
}



//------------------------------------------------------------
// outen_store @ 00104434 size=240
// signature: undefined outen_store(void)
// callers: []
//------------------------------------------------------------

undefined8 outen_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  uint uVar1;
  char cVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  long lVar6;
  ulong local_40;
  long local_38;
  
  lVar6 = sp_el0;
  local_38 = *(long *)(lVar6 + 0x638);
  local_40 = 0;
  lVar6 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar5 = kstrtoull(param_3,0,&local_40);
  if (iVar5 == 0) {
    _raw_spin_lock(lVar6 + 0x38);
    bVar3 = *(byte *)(lVar6 + 0x88);
    if ((char)bVar3 < '\0') {
                    /* WARNING: Does not return */
      pcVar4 = (code *)SoftwareBreakpoint(0x5512,0x104524);
      (*pcVar4)();
    }
    cVar2 = *(char *)(lVar6 + 0x4d);
    *(int *)(lVar6 + (ulong)bVar3 * 4 + 0x28c) = (int)local_40;
    if ((cVar2 != '\0') && (*(char *)(lVar6 + 0x4c) != '\0')) {
      uVar1 = (uint)bVar3 * 4 + 0xa0;
      if (*(char *)(lVar6 + 0x4b0) != '\0') {
        uVar1 = (uint)bVar3 << 2 | 0x800;
      }
      cti_write_single_reg(lVar6,uVar1,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar6 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar6 = sp_el0;
  if (*(long *)(lVar6 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// gate_show @ 00104528 size=204
// signature: undefined gate_show(void)
// callers: []
//------------------------------------------------------------

long gate_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(plVar4 + 7);
  if ((*(char *)((long)plVar4 + 0x4d) == '\0') || (*(char *)((long)plVar4 + 0x4c) == '\0')) {
    uVar2 = 0;
  }
  else {
    writel_relaxed(0xc5acce55,*plVar4 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    lVar1 = 0x140;
    if ((char)plVar4[0x96] != '\0') {
      lVar1 = 0x88;
    }
    uVar2 = readl_relaxed(*plVar4 + lVar1);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar4 + 0xfb0);
  }
  _raw_spin_unlock(plVar4 + 7);
  iVar3 = scnprintf(param_3,0x1000,&DAT_00105ebf,uVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// gate_store @ 001045f8 size=204
// signature: undefined gate_store(void)
// callers: []
//------------------------------------------------------------

undefined8 gate_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    _raw_spin_lock(lVar3 + 0x38);
    if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
      uVar2 = 0x140;
      if (*(char *)(lVar3 + 0x4b0) != '\0') {
        uVar2 = 0x88;
      }
      cti_write_single_reg(lVar3,uVar2,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// writel_relaxed @ 001046c4 size=132
// signature: undefined writel_relaxed(void)
// callers: [gate_show, appset_show, asicctl_show]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x1046dc,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x104718,uVar1);
  return;
}



//------------------------------------------------------------
// asicctl_show @ 0010474c size=204
// signature: undefined asicctl_show(void)
// callers: []
//------------------------------------------------------------

long asicctl_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(plVar4 + 7);
  if ((*(char *)((long)plVar4 + 0x4d) == '\0') || (*(char *)((long)plVar4 + 0x4c) == '\0')) {
    uVar2 = 0;
  }
  else {
    writel_relaxed(0xc5acce55,*plVar4 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    lVar1 = 0x144;
    if ((char)plVar4[0x96] != '\0') {
      lVar1 = 0x8c;
    }
    uVar2 = readl_relaxed(*plVar4 + lVar1);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar4 + 0xfb0);
  }
  _raw_spin_unlock(plVar4 + 7);
  iVar3 = scnprintf(param_3,0x1000,&DAT_00105ebf,uVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// asicctl_store @ 0010481c size=204
// signature: undefined asicctl_store(void)
// callers: []
//------------------------------------------------------------

undefined8 asicctl_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    _raw_spin_lock(lVar3 + 0x38);
    if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
      uVar2 = 0x144;
      if (*(char *)(lVar3 + 0x4b0) != '\0') {
        uVar2 = 0x8c;
      }
      cti_write_single_reg(lVar3,uVar2,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// intack_store @ 001048ec size=136
// signature: undefined intack_store(void)
// callers: []
//------------------------------------------------------------

undefined8 intack_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  ulong local_30;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_30 = 0;
  iVar2 = kstrtoull(param_3,0,&local_30);
  if (iVar2 == 0) {
    cti_write_intack(param_1,local_30 & 0xffffffff);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// appset_show @ 00104978 size=204
// signature: undefined appset_show(void)
// callers: []
//------------------------------------------------------------

long appset_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  undefined4 uVar2;
  int iVar3;
  long *plVar4;
  
  plVar4 = *(long **)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(plVar4 + 7);
  if ((*(char *)((long)plVar4 + 0x4d) == '\0') || (*(char *)((long)plVar4 + 0x4c) == '\0')) {
    uVar2 = 0;
  }
  else {
    writel_relaxed(0xc5acce55,*plVar4 + 0xfb0);
    DataSynchronizationBarrier(3,3,0);
    lVar1 = 0x14;
    if ((char)plVar4[0x96] != '\0') {
      lVar1 = 4;
    }
    uVar2 = readl_relaxed(*plVar4 + lVar1);
    DataSynchronizationBarrier(3,3,0);
    writel_relaxed(0,*plVar4 + 0xfb0);
  }
  _raw_spin_unlock(plVar4 + 7);
  iVar3 = scnprintf(param_3,0x1000,&DAT_00105ebf,uVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// appset_store @ 00104a48 size=204
// signature: undefined appset_store(void)
// callers: []
//------------------------------------------------------------

undefined8 appset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    _raw_spin_lock(lVar3 + 0x38);
    if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
      uVar2 = 0x14;
      if (*(char *)(lVar3 + 0x4b0) != '\0') {
        uVar2 = 4;
      }
      cti_write_single_reg(lVar3,uVar2,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// appclear_store @ 00104b18 size=216
// signature: undefined appclear_store(void)
// callers: []
//------------------------------------------------------------

undefined8 appclear_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  undefined8 local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    _raw_spin_lock(lVar3 + 0x38);
    *(uint *)(lVar3 + 0x84) = *(uint *)(lVar3 + 0x84) & ((uint)local_40 ^ 0xffffffff);
    if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
      uVar2 = 8;
      if (*(char *)(lVar3 + 0x4b0) != '\0') {
        uVar2 = 0x18;
      }
      cti_write_single_reg(lVar3,uVar2);
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// apppulse_store @ 00104bf4 size=204
// signature: undefined apppulse_store(void)
// callers: []
//------------------------------------------------------------

undefined8 apppulse_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if (iVar1 == 0) {
    _raw_spin_lock(lVar3 + 0x38);
    if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
      uVar2 = 0x1c;
      if (*(char *)(lVar3 + 0x4b0) != '\0') {
        uVar2 = 0xc;
      }
      cti_write_single_reg(lVar3,uVar2,local_40 & 0xffffffff);
    }
    _raw_spin_unlock(lVar3 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// trigin_attach_store @ 00104cc4 size=164
// signature: undefined trigin_attach_store(void)
// callers: []
//------------------------------------------------------------

void trigin_attach_store(undefined8 param_1,undefined8 param_2,char *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  iVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_30 + 4),(int *)&local_30);
  if (iVar2 == 2) {
    iVar2 = cti_channel_trig_op(param_1,0,0,local_30._4_4_,local_30 & 0xffffffff);
    if (iVar2 != 0) {
      param_4 = iVar2;
    }
    lVar3 = (long)param_4;
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// trigin_detach_store @ 00104d6c size=164
// signature: undefined trigin_detach_store(void)
// callers: []
//------------------------------------------------------------

void trigin_detach_store(undefined8 param_1,undefined8 param_2,char *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  iVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_30 + 4),(int *)&local_30);
  if (iVar2 == 2) {
    iVar2 = cti_channel_trig_op(param_1,1,0,local_30._4_4_,local_30 & 0xffffffff);
    if (iVar2 != 0) {
      param_4 = iVar2;
    }
    lVar3 = (long)param_4;
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// trigout_attach_store @ 00104e14 size=164
// signature: undefined trigout_attach_store(void)
// callers: []
//------------------------------------------------------------

void trigout_attach_store(undefined8 param_1,undefined8 param_2,char *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  iVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_30 + 4),(int *)&local_30);
  if (iVar2 == 2) {
    iVar2 = cti_channel_trig_op(param_1,0,1,local_30._4_4_,local_30 & 0xffffffff);
    if (iVar2 != 0) {
      param_4 = iVar2;
    }
    lVar3 = (long)param_4;
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// trigout_detach_store @ 00104ebc size=164
// signature: undefined trigout_detach_store(void)
// callers: []
//------------------------------------------------------------

void trigout_detach_store(undefined8 param_1,undefined8 param_2,char *param_3,int param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  undefined8 local_30;
  long local_28;
  
  lVar3 = sp_el0;
  local_28 = *(long *)(lVar3 + 0x638);
  local_30 = 0;
  iVar2 = sscanf(param_3,"%d %d",(int *)((long)&local_30 + 4),(int *)&local_30);
  if (iVar2 == 2) {
    iVar2 = cti_channel_trig_op(param_1,1,1,local_30._4_4_,local_30 & 0xffffffff);
    if (iVar2 != 0) {
      param_4 = iVar2;
    }
    lVar3 = (long)param_4;
  }
  else {
    lVar3 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar3);
  }
  return;
}



//------------------------------------------------------------
// trig_filter_enable_show @ 00104f64 size=100
// signature: undefined trig_filter_enable_show(void)
// callers: []
//------------------------------------------------------------

long trig_filter_enable_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar1 = lVar4 + 0x38;
  _raw_spin_lock(lVar1);
  bVar2 = *(byte *)(lVar4 + 0x80);
  _raw_spin_unlock(lVar1);
  iVar3 = sprintf(param_3,"%d\n",(ulong)bVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// trig_filter_enable_store @ 00104fcc size=172
// signature: undefined trig_filter_enable_store(void)
// callers: []
//------------------------------------------------------------

undefined8
trig_filter_enable_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  int iVar2;
  long lVar3;
  long local_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  local_40 = 0;
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar2 = kstrtoull(param_3,0,&local_40);
  if (iVar2 == 0) {
    lVar1 = lVar3 + 0x38;
    _raw_spin_lock(lVar1);
    *(bool *)(lVar3 + 0x80) = local_40 != 0;
    _raw_spin_unlock(lVar1);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// trigout_filtered_show @ 0010507c size=56
// signature: undefined trigout_filtered_show(void)
// callers: []
//------------------------------------------------------------

long trigout_filtered_show(long param_1,undefined8 param_2,undefined8 param_3)

{
  int iVar1;
  long lVar2;
  
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = bitmap_print_to_pagebuf(1,param_3,lVar2 + 0x70,*(undefined4 *)(lVar2 + 0x44));
  return (long)iVar1;
}



//------------------------------------------------------------
// chan_gate_enable_show @ 001050b8 size=128
// signature: undefined chan_gate_enable_show(void)
// callers: []
//------------------------------------------------------------

void chan_gate_enable_show(long param_1,undefined8 param_2,undefined2 *param_3)

{
  uint uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  ulong local_20;
  long local_18;
  
  lVar4 = sp_el0;
  local_18 = *(long *)(lVar4 + 0x638);
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  uVar1 = *(uint *)(lVar4 + 0x48c);
  local_20 = (ulong)uVar1;
  if (uVar1 == 0) {
    lVar4 = 1;
    *param_3 = 10;
  }
  else {
    iVar3 = bitmap_print_to_pagebuf(1,param_3,&local_20,*(undefined4 *)(lVar4 + 0x40));
    lVar4 = (long)iVar3;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_18) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar4);
  }
  return;
}



//------------------------------------------------------------
// chan_gate_enable_store @ 0010513c size=148
// signature: undefined chan_gate_enable_store(void)
// callers: []
//------------------------------------------------------------

void chan_gate_enable_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = cti_channel_gate_op(param_1,0,local_2c);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// chan_gate_disable_store @ 001051d4 size=148
// signature: undefined chan_gate_disable_store(void)
// callers: []
//------------------------------------------------------------

void chan_gate_disable_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = cti_channel_gate_op(param_1,1,local_2c);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// chan_set_store @ 0010526c size=148
// signature: undefined chan_set_store(void)
// callers: []
//------------------------------------------------------------

void chan_set_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = cti_channel_setop(param_1,0,local_2c);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// chan_clear_store @ 00105304 size=148
// signature: undefined chan_clear_store(void)
// callers: []
//------------------------------------------------------------

void chan_clear_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = cti_channel_setop(param_1,1,local_2c);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// chan_pulse_store @ 0010539c size=148
// signature: undefined chan_pulse_store(void)
// callers: []
//------------------------------------------------------------

void chan_pulse_store(undefined8 param_1,undefined8 param_2,undefined8 param_3,long param_4)

{
  long lVar1;
  int iVar2;
  undefined4 local_2c;
  long local_28;
  
  lVar1 = sp_el0;
  local_28 = *(long *)(lVar1 + 0x638);
  local_2c = 0;
  iVar2 = kstrtoint(param_3,0,&local_2c);
  if (iVar2 == 0) {
    iVar2 = cti_channel_setop(param_1,2,local_2c);
    if (iVar2 != 0) {
      param_4 = (long)iVar2;
    }
  }
  else {
    param_4 = -0x16;
  }
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_28) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(param_4);
  }
  return;
}



//------------------------------------------------------------
// chan_inuse_show @ 00105434 size=252
// signature: undefined chan_inuse_show(void)
// callers: []
//------------------------------------------------------------

void chan_inuse_show(long param_1,undefined8 param_2,undefined2 *param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong local_40;
  long local_38;
  
  lVar5 = sp_el0;
  local_38 = *(long *)(lVar5 + 0x638);
  local_40 = 0;
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(lVar5 + 0x38);
  if ((int)*(uint *)(lVar5 + 0x44) < 1) {
    uVar6 = 0;
  }
  else {
    lVar4 = 0;
    uVar6 = 0;
    do {
      if (lVar4 == 0x200) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x10552c);
        (*pcVar2)();
      }
      lVar1 = lVar5 + lVar4;
      lVar4 = lVar4 + 4;
      uVar6 = uVar6 | *(uint *)(lVar1 + 0x8c) | (ulong)*(uint *)(lVar1 + 0x28c);
      local_40 = uVar6;
    } while ((ulong)*(uint *)(lVar5 + 0x44) * 4 != lVar4);
  }
  _raw_spin_unlock(lVar5 + 0x38);
  if (uVar6 << ((ulong)(uint)-*(int *)(lVar5 + 0x40) & 0x3f) == 0) {
    lVar5 = 1;
    *param_3 = 10;
  }
  else {
    iVar3 = bitmap_print_to_pagebuf(1,param_3,&local_40);
    lVar5 = (long)iVar3;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// print_chan_list @ 00105530 size=276
// signature: undefined print_chan_list(void)
// callers: [chan_free_show]
//------------------------------------------------------------

void print_chan_list(long param_1,undefined2 *param_2,ulong param_3)

{
  long lVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  ulong local_50;
  long local_48;
  
  lVar5 = sp_el0;
  local_48 = *(long *)(lVar5 + 0x638);
  local_50 = 0;
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(lVar5 + 0x38);
  if ((int)*(uint *)(lVar5 + 0x44) < 1) {
    uVar6 = 0;
  }
  else {
    lVar4 = 0;
    uVar6 = 0;
    do {
      if (lVar4 == 0x200) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105640);
        (*pcVar2)();
      }
      lVar1 = lVar5 + lVar4;
      lVar4 = lVar4 + 4;
      uVar6 = uVar6 | *(uint *)(lVar1 + 0x8c) | (ulong)*(uint *)(lVar1 + 0x28c);
      local_50 = uVar6;
    } while ((ulong)*(uint *)(lVar5 + 0x44) * 4 != lVar4);
  }
  _raw_spin_unlock(lVar5 + 0x38);
  if ((param_3 & 1) == 0) {
    uVar6 = ~uVar6;
    local_50 = uVar6;
  }
  if (uVar6 << ((ulong)(uint)-*(int *)(lVar5 + 0x40) & 0x3f) == 0) {
    lVar5 = 1;
    *param_2 = 10;
  }
  else {
    iVar3 = bitmap_print_to_pagebuf(1,param_2,&local_50);
    lVar5 = (long)iVar3;
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail(lVar5);
  }
  return;
}



//------------------------------------------------------------
// chan_free_show @ 00105648 size=36
// signature: undefined chan_free_show(void)
// callers: []
//------------------------------------------------------------

void chan_free_show(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  print_chan_list(param_1,param_3,0);
  return;
}



//------------------------------------------------------------
// chan_xtrigs_sel_show @ 00105670 size=100
// signature: undefined chan_xtrigs_sel_show(void)
// callers: []
//------------------------------------------------------------

long chan_xtrigs_sel_show(long param_1,undefined8 param_2,char *param_3)

{
  long lVar1;
  byte bVar2;
  int iVar3;
  long lVar4;
  
  lVar4 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  lVar1 = lVar4 + 0x38;
  _raw_spin_lock(lVar1);
  bVar2 = *(byte *)(lVar4 + 0x81);
  _raw_spin_unlock(lVar1);
  iVar3 = sprintf(param_3,"%ld\n",(ulong)bVar2);
  return (long)iVar3;
}



//------------------------------------------------------------
// chan_xtrigs_sel_store @ 001056d8 size=184
// signature: undefined chan_xtrigs_sel_store(void)
// callers: []
//------------------------------------------------------------

undefined8
chan_xtrigs_sel_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  int iVar1;
  long lVar2;
  ulong local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  local_40 = 0;
  lVar2 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  iVar1 = kstrtoull(param_3,0,&local_40);
  if ((iVar1 == 0) && (local_40 <= (ulong)(long)(*(int *)(lVar2 + 0x40) + -1))) {
    _raw_spin_lock(lVar2 + 0x38);
    *(char *)(lVar2 + 0x81) = (char)local_40;
    _raw_spin_unlock(lVar2 + 0x38);
  }
  else {
    param_4 = 0xffffffffffffffea;
  }
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return param_4;
}



//------------------------------------------------------------
// chan_xtrigs_in_show @ 00105794 size=196
// signature: undefined chan_xtrigs_in_show(void)
// callers: []
//------------------------------------------------------------

long chan_xtrigs_in_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  uVar1 = *(uint *)(lVar5 + 0x44);
  if ((int)uVar1 < 1) {
    iVar7 = 0;
  }
  else {
    bVar2 = *(byte *)(lVar5 + 0x81);
    uVar6 = 0;
    iVar7 = 0;
    do {
      if (uVar6 == 0x80) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105858);
        (*pcVar3)();
      }
      if ((*(uint *)(lVar5 + 0x8c + uVar6 * 4) & (uint)(1L << ((ulong)bVar2 & 0x3f))) != 0) {
        iVar4 = sprintf((char *)(param_3 + iVar7),"%d ",uVar6 & 0xffffffff);
        iVar7 = iVar4 + iVar7;
      }
      uVar6 = uVar6 + 1;
    } while (uVar1 != uVar6);
  }
  *(undefined2 *)(param_3 + iVar7) = 10;
  return (long)(iVar7 + 1);
}



//------------------------------------------------------------
// chan_xtrigs_out_show @ 0010585c size=196
// signature: undefined chan_xtrigs_out_show(void)
// callers: []
//------------------------------------------------------------

long chan_xtrigs_out_show(long param_1,undefined8 param_2,long param_3)

{
  uint uVar1;
  byte bVar2;
  code *pcVar3;
  int iVar4;
  long lVar5;
  ulong uVar6;
  int iVar7;
  
  lVar5 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  uVar1 = *(uint *)(lVar5 + 0x44);
  if ((int)uVar1 < 1) {
    iVar7 = 0;
  }
  else {
    bVar2 = *(byte *)(lVar5 + 0x81);
    uVar6 = 0;
    iVar7 = 0;
    do {
      if (uVar6 == 0x80) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x105920);
        (*pcVar3)();
      }
      if ((*(uint *)(lVar5 + 0x28c + uVar6 * 4) & (uint)(1L << ((ulong)bVar2 & 0x3f))) != 0) {
        iVar4 = sprintf((char *)(param_3 + iVar7),"%d ",uVar6 & 0xffffffff);
        iVar7 = iVar4 + iVar7;
      }
      uVar6 = uVar6 + 1;
    } while (uVar1 != uVar6);
  }
  *(undefined2 *)(param_3 + iVar7) = 10;
  return (long)(iVar7 + 1);
}



//------------------------------------------------------------
// chan_xtrigs_reset_store @ 00105924 size=248
// signature: undefined chan_xtrigs_reset_store(void)
// callers: []
//------------------------------------------------------------

undefined8
chan_xtrigs_reset_store(long param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  long lVar1;
  code *pcVar2;
  long lVar3;
  ulong uVar4;
  
  lVar3 = *(long *)(*(long *)(param_1 + 0x60) + 0x98);
  _raw_spin_lock(lVar3 + 0x38);
  if (0 < *(int *)(lVar3 + 0x44)) {
    uVar4 = 0;
    do {
      if (uVar4 == 0x80) {
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105a1c);
        (*pcVar2)();
      }
      lVar1 = lVar3 + uVar4 * 4;
      *(undefined4 *)(lVar1 + 0x8c) = 0;
      *(undefined4 *)(lVar1 + 0x28c) = 0;
      if (uVar4 == *(uint *)(*(long *)(lVar3 + 0x4b8) + 8)) {
        cti_trigin_gpio_disable(lVar3);
      }
      if (uVar4 == *(uint *)(*(long *)(lVar3 + 0x4c0) + 8)) {
        cti_trigout_gpio_disable(lVar3);
      }
      uVar4 = uVar4 + 1;
    } while ((long)uVar4 < (long)*(int *)(lVar3 + 0x44));
  }
  *(undefined4 *)(lVar3 + 0x490) = 0;
  *(undefined4 *)(lVar3 + 0x84) = 0;
  *(undefined1 *)(lVar3 + 0x88) = 0;
  *(undefined1 *)(lVar3 + 0x81) = 0;
  *(int *)(lVar3 + 0x48c) =
       (int)(0xffffffffffffffff >> ((ulong)(uint)-*(int *)(lVar3 + 0x40) & 0x3f));
  if ((*(char *)(lVar3 + 0x4d) != '\0') && (*(char *)(lVar3 + 0x4c) != '\0')) {
    cti_write_all_hw_regs(lVar3);
  }
  _raw_spin_unlock(lVar3 + 0x38);
  return param_4;
}



//------------------------------------------------------------
// init_module @ 00105a24 size=84
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

int init_module(void)

{
  int iVar1;
  
  iVar1 = amba_driver_register(&cti_driver);
  if (iVar1 != 0) {
    _printk(&DAT_001060c4);
  }
  coresight_set_cti_ops(&cti_assoc_ops);
  return iVar1;
}



//------------------------------------------------------------
// cleanup_module @ 00105a7c size=40
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  coresight_remove_cti_ops();
  amba_driver_unregister(&cti_driver);
  return;
}



//------------------------------------------------------------
// log_write_mmio @ 00109000 size=1
// signature: undefined log_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_write_mmio @ 00109008 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed, writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock @ 00109010 size=1
// signature: undefined _raw_spin_lock(void)
// callers: [appclear_store, chan_inuse_show, cti_dying_cpu, asicctl_show, asicctl_store, cti_disable, cti_starting_cpu, gate_show, chan_xtrigs_reset_store, chan_xtrigs_sel_show, cti_channel_trig_op, powered_show, cti_cpu_pm_notify, trig_filter_enable_show, chan_xtrigs_sel_store, outen_store, cti_channel_setop, print_chan_list, appset_store, inen_store, apppulse_store, inen_show, enable_show, gate_store, trig_filter_enable_store, outen_show, coresight_cti_reg_show, cti_write_intack, appset_show, cti_channel_gate_op, inout_sel_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock @ 00109018 size=1
// signature: undefined _raw_spin_unlock(void)
// callers: [appclear_store, chan_inuse_show, cti_dying_cpu, asicctl_show, asicctl_store, cti_disable, cti_starting_cpu, gate_show, chan_xtrigs_reset_store, chan_xtrigs_sel_show, cti_channel_trig_op, powered_show, cti_cpu_pm_notify, trig_filter_enable_show, chan_xtrigs_sel_store, outen_store, cti_channel_setop, print_chan_list, appset_store, inen_store, apppulse_store, inen_show, enable_show, gate_store, trig_filter_enable_store, outen_show, coresight_cti_reg_show, cti_write_intack, appset_show, cti_channel_gate_op, inout_sel_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 00109020 size=1
// signature: undefined __list_add_valid(void)
// callers: [cti_probe, cti_add_connection_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __bitmap_or @ 00109028 size=1
// signature: undefined __bitmap_or(void)
// callers: [coresight_cti_get_platform_data, cti_add_connection_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __bitmap_or(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kstrdup @ 00109030 size=1
// signature: undefined devm_kstrdup(void)
// callers: [cti_create_cons_sysfs, cti_add_connection_entry]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kstrdup(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kmalloc @ 00109038 size=1
// signature: undefined devm_kmalloc(void)
// callers: [cti_probe, cti_create_cons_sysfs, coresight_cti_get_platform_data, cti_allocate_trig_con, cti_add_default_connection]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00109040 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [cti_add_default_connection]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_put @ 00109048 size=1
// signature: undefined devm_pinctrl_put(void)
// callers: [cti_channel_trig_op, cti_trigin_gpio_enable, cti_trigout_gpio_disable, cti_trigin_gpio_disable, cti_trigout_gpio_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_pinctrl_get @ 00109050 size=1
// signature: undefined devm_pinctrl_get(void)
// callers: [cti_trigin_gpio_enable, cti_trigout_gpio_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_pinctrl_get(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_lookup_state @ 00109058 size=1
// signature: undefined pinctrl_lookup_state(void)
// callers: [cti_trigin_gpio_enable, cti_trigout_gpio_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_lookup_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// pinctrl_select_state @ 00109060 size=1
// signature: undefined pinctrl_select_state(void)
// callers: [cti_trigin_gpio_enable, cti_trigout_gpio_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void pinctrl_select_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00109068 size=1
// signature: undefined _dev_err(void)
// callers: [cti_trigin_gpio_enable, cti_probe, cti_trigout_gpio_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00109070 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [cti_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 00109080 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [cti_enable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_claim_device @ 00109088 size=1
// signature: undefined coresight_claim_device(void)
// callers: [cti_starting_cpu, cti_enable, cti_cpu_pm_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_claim_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device_unlocked @ 00109090 size=1
// signature: undefined coresight_disclaim_device_unlocked(void)
// callers: [cti_disable]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device_unlocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_register @ 00109098 size=1
// signature: undefined amba_driver_register(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_set_cti_ops @ 001090a0 size=1
// signature: undefined coresight_set_cti_ops(void)
// callers: [init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_set_cti_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 001090a8 size=1
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
// coresight_remove_cti_ops @ 001090b0 size=1
// signature: undefined coresight_remove_cti_ops(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_remove_cti_ops(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// amba_driver_unregister @ 001090b8 size=1
// signature: undefined amba_driver_unregister(void)
// callers: [cleanup_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void amba_driver_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap_resource @ 001090c0 size=1
// signature: undefined devm_ioremap_resource(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap_resource(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_kasprintf @ 001090c8 size=1
// signature: undefined devm_kasprintf(void)
// callers: [cti_probe, cti_create_cons_sysfs]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kasprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_alloc_device_name @ 001090d0 size=1
// signature: undefined coresight_alloc_device_name(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_alloc_device_name(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 001090d8 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_register @ 001090e0 size=1
// signature: undefined coresight_register(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_unregister_notifier @ 001090e8 size=1
// signature: undefined cpu_pm_unregister_notifier(void)
// callers: [cti_device_release, cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_unregister_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_lock @ 001090f0 size=1
// signature: undefined cpus_read_lock(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_setup_state_cpuslocked @ 001090f8 size=1
// signature: undefined __cpuhp_setup_state_cpuslocked(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_setup_state_cpuslocked(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpus_read_unlock @ 00109100 size=1
// signature: undefined cpus_read_unlock(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpus_read_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_warn @ 00109108 size=1
// signature: undefined _dev_warn(void)
// callers: [cti_probe, cti_update_conn_xrefs, coresight_cti_get_platform_data, cti_add_assoc_to_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_warn(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// cpu_pm_register_notifier @ 00109110 size=1
// signature: undefined cpu_pm_register_notifier(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void cpu_pm_register_notifier(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __cpuhp_remove_state @ 00109118 size=1
// signature: undefined __cpuhp_remove_state(void)
// callers: [cti_device_release, cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __cpuhp_remove_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00109120 size=1
// signature: undefined mutex_lock(void)
// callers: [cti_device_release, cti_probe, cti_remove, cti_add_assoc_to_csdev, cti_remove_assoc_from_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00109128 size=1
// signature: undefined mutex_unlock(void)
// callers: [cti_device_release, cti_probe, cti_remove, cti_add_assoc_to_csdev, cti_remove_assoc_from_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_present @ 00109130 size=1
// signature: undefined fwnode_property_present(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_present(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_idle @ 00109138 size=1
// signature: undefined __pm_runtime_idle(void)
// callers: [enable_store, coresight_cti_reg_show, cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_idle(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_info @ 00109140 size=1
// signature: undefined _dev_info(void)
// callers: [cti_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_info(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00109148 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [trigout_attach_store, appclear_store, chan_gate_enable_show, chan_inuse_show, intack_store, trigout_detach_store, chan_gate_disable_store, asicctl_store, chan_pulse_store, cti_remove, chan_xtrigs_sel_store, outen_store, coresight_cti_get_platform_data, trigin_detach_store, print_chan_list, appset_store, inen_store, apppulse_store, gate_store, chan_gate_enable_store, enable_store, trig_filter_enable_store, trigin_attach_store, cti_probe, cti_update_conn_xrefs, chan_set_store, cti_add_assoc_to_csdev, chan_clear_store, cti_remove_assoc_from_csdev, inout_sel_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_remove_sysfs_link @ 00109150 size=1
// signature: undefined coresight_remove_sysfs_link(void)
// callers: [cti_remove, cti_remove_assoc_from_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_remove_sysfs_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_set_assoc_ectdev_mutex @ 00109158 size=1
// signature: undefined coresight_set_assoc_ectdev_mutex(void)
// callers: [cti_remove, cti_update_conn_xrefs, cti_add_assoc_to_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_set_assoc_ectdev_mutex(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_unregister @ 00109160 size=1
// signature: undefined coresight_unregister(void)
// callers: [cti_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_add_sysfs_link @ 00109168 size=1
// signature: undefined coresight_add_sysfs_link(void)
// callers: [cti_update_conn_xrefs, cti_add_assoc_to_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_add_sysfs_link(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00109170 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [cti_device_release]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_read_mmio @ 00109178 size=1
// signature: undefined log_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_post_read_mmio @ 00109180 size=1
// signature: undefined log_post_read_mmio(void)
// callers: [readl_relaxed, readl_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_read_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_disclaim_device @ 00109188 size=1
// signature: undefined coresight_disclaim_device(void)
// callers: [cti_dying_cpu, cti_cpu_pm_notify]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_disclaim_device(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dev_fwnode @ 00109198 size=1
// signature: undefined dev_fwnode(void)
// callers: [coresight_cti_get_platform_data, cti_add_assoc_to_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dev_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// strcmp @ 001091a0 size=1
// signature: int strcmp(char * __s1, char * __s2)
// callers: [cti_add_assoc_to_csdev]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int strcmp(char *__s1,char *__s2)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// device_property_read_u32_array @ 001091b0 size=1
// signature: undefined device_property_read_u32_array(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void device_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_get_next_child_node @ 001091b8 size=1
// signature: undefined fwnode_get_next_child_node(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_get_next_child_node(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_device_is_compatible @ 001091c0 size=1
// signature: undefined of_device_is_compatible(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_device_is_compatible(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __of_parse_phandle_with_args @ 001091c8 size=1
// signature: undefined __of_parse_phandle_with_args(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __of_parse_phandle_with_args(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_cpu_node_to_id @ 001091d0 size=1
// signature: undefined of_cpu_node_to_id(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_cpu_node_to_id(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// scnprintf @ 001091d8 size=1
// signature: undefined scnprintf(void)
// callers: [gate_show, appset_show, coresight_cti_get_platform_data, asicctl_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void scnprintf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_find_reference @ 001091e0 size=1
// signature: undefined fwnode_find_reference(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_find_reference(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_node_name_eq @ 001091e8 size=1
// signature: undefined of_node_name_eq(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_node_name_eq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_u32_array @ 001091f0 size=1
// signature: undefined fwnode_property_read_u32_array(void)
// callers: [cti_plat_read_trig_group, coresight_cti_get_platform_data, cti_plat_read_trig_types]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00109200 size=1
// signature: undefined kmalloc_trace(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 00109208 size=1
// signature: undefined kfree(void)
// callers: [cti_plat_read_trig_group, coresight_cti_get_platform_data, cti_plat_read_trig_types]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_property_read_string @ 00109210 size=1
// signature: undefined fwnode_property_read_string(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_property_read_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// coresight_find_csdev_by_fwnode @ 00109218 size=1
// signature: undefined coresight_find_csdev_by_fwnode(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void coresight_find_csdev_by_fwnode(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// fwnode_handle_put @ 00109220 size=1
// signature: undefined fwnode_handle_put(void)
// callers: [coresight_cti_get_platform_data]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void fwnode_handle_put(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00109228 size=1
// signature: undefined __kmalloc(void)
// callers: [cti_plat_read_trig_group, cti_plat_read_trig_types]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sprintf @ 00109230 size=1
// signature: int sprintf(char * __s, char * __format, ...)
// callers: [nr_trigger_cons_show, con_name_show, trigout_type_show, inen_show, enable_show, ctmid_show, chan_xtrigs_out_show, outen_show, chan_xtrigs_in_show, trigin_type_show, chan_xtrigs_sel_show, powered_show, trig_filter_enable_show, inout_sel_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sprintf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// bitmap_print_to_pagebuf @ 00109238 size=1
// signature: undefined bitmap_print_to_pagebuf(void)
// callers: [trigout_sig_show, chan_gate_enable_show, chan_inuse_show, trigout_filtered_show, print_chan_list, trigin_sig_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void bitmap_print_to_pagebuf(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoull @ 00109240 size=1
// signature: undefined kstrtoull(void)
// callers: [enable_store, trig_filter_enable_store, appset_store, inen_store, appclear_store, intack_store, apppulse_store, chan_xtrigs_sel_store, outen_store, gate_store, asicctl_store, inout_sel_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoull(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __pm_runtime_resume @ 00109248 size=1
// signature: undefined __pm_runtime_resume(void)
// callers: [enable_store, coresight_cti_reg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __pm_runtime_resume(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sysfs_emit @ 00109250 size=1
// signature: undefined sysfs_emit(void)
// callers: [coresight_cti_reg_show]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sysfs_emit(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sscanf @ 00109258 size=1
// signature: int sscanf(char * __s, char * __format, ...)
// callers: [trigout_attach_store, trigout_detach_store, trigin_attach_store, trigin_detach_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int sscanf(char *__s,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kstrtoint @ 00109260 size=1
// signature: undefined kstrtoint(void)
// callers: [chan_pulse_store, chan_gate_disable_store, chan_set_store, chan_gate_enable_store, chan_clear_store]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kstrtoint(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



