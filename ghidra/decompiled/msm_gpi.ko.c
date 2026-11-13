// Decompiled by Ghidra 12.2
// Program: msm_gpi.ko
// Image base: 00100000

//------------------------------------------------------------
// gpi_dump_for_geni @ 00100ce4 size=32
// signature: undefined gpi_dump_for_geni(void)
// callers: []
//------------------------------------------------------------

void gpi_dump_for_geni(long param_1)

{
  gpi_dump_debug_reg(*(undefined8 *)(param_1 + 0x118));
  return;
}



//------------------------------------------------------------
// gpi_dump_debug_reg @ 00100d04 size=5924
// signature: undefined gpi_dump_debug_reg(void)
// callers: [gpi_q2spi_terminate_all, geni_gsi_connect_doorbell, gpi_dump_for_geni, geni_gsi_disconnect_doorbell_stop_ch, gpi_handle_irq, gpi_terminate_all]
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void gpi_dump_debug_reg(int *param_1)

{
  uint *puVar1;
  int *piVar2;
  long *plVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  long lVar8;
  undefined8 uVar9;
  long *plVar10;
  long *plVar11;
  uint *puVar12;
  
  piVar2 = param_1 + 0x10d;
  plVar3 = (long *)(param_1 + 0x108);
  iVar7 = *param_1 * 0x4000;
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) + (ulong)(iVar7 + param_1[0x42] * 0x80 + 0x20000))
  ;
  if (1 < (uint)param_1[0x10b]) {
    _printk(&DAT_0010b8a6,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  puVar4 = (uint *)(param_1 + 0x10a);
  if ((*plVar3 != 0) && (1 < *puVar4)) {
    ipc_log_string(*plVar3,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_0 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x20000));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010b8a6,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_0 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x20008));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c6f7,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_2 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x20008));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c6f7,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_2 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x20010));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c8de,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_4 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x20010));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c8de,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_4 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x20018));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010bd47,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_6 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x20018));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010bd47,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_CNTXT_6 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x21000));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010e2c8,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_0 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x21000));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010e2c8,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_0 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x21008));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010b4b0,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_2 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x21008));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010b4b0,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_2 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x21010));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010bbcc,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_4 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(uint)(*param_1 * 0x4000 + 0x21010 + param_1[0xa4] * 0x80));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010bbcc,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_4 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x21018));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010d3b4,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_6 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x21018));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010d3b4,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_EV_%d_CNTXT_6 reg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0x42] * 0x80 + 0x20054));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010e1d5,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_RE_FETCH_READ_PTRg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,0,uVar5);
  }
  uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(*param_1 * 0x4000 + param_1[0xa4] * 0x80 + 0x20054));
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010e1d5,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_RE_FETCH_READ_PTRg_val:0x%x\n",99,
                   "gpi_dump_cntxt_regs",*param_1,1,uVar5);
  }
  if (*(char *)(*(long *)(param_1 + 0xc6) + 0x1e8) == '\0') {
    uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                          (ulong)(*param_1 * 0x80 + param_1[0x42] * 4 + 0x17800));
    if ((uint)param_1[0x10b] < 2) {
      lVar8 = *plVar3;
    }
    else {
      _printk(&DAT_0010bf00,piVar2,99,"gpi_dump_cntxt_regs",*param_1,0,uVar5);
      lVar8 = *plVar3;
    }
    if ((lVar8 != 0) && (1 < *puVar4)) {
      ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_VP_TABLE_val:0x%x\n",99,
                     "gpi_dump_cntxt_regs",*param_1,0,uVar5);
    }
    uVar5 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                          (ulong)(uint)(param_1[0xa4] * 4 + 0x17800 + *param_1 * 0x80));
    if ((uint)param_1[0x10b] < 2) {
      lVar8 = *plVar3;
    }
    else {
      _printk(&DAT_0010bf00,piVar2,99,"gpi_dump_cntxt_regs",*param_1,1,uVar5);
      lVar8 = *plVar3;
    }
    if ((lVar8 != 0) && (1 < *puVar4)) {
      ipc_log_string(lVar8,"ch:%u %s: GPI_GPII_%d_CH_%d_VP_TABLE_val:0x%x\n",99,
                     "gpi_dump_cntxt_regs",*param_1,1,uVar5);
    }
  }
  uVar9 = sched_clock();
  plVar10 = *(long **)(param_1 + 0x15a);
  *(undefined8 *)(param_1 + 0x150) = uVar9;
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(__dev_err,0xb20,0xd0);
    *(long **)(param_1 + 0x15a) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    *(undefined4 *)((long)plVar10 + 0xcc) = 0;
    *plVar10 = (long)"TYPE_IRQ";
    *(undefined8 *)((long)plVar10 + 0xc4) = 0;
    *(int *)(plVar10 + 1) = iVar7 + 0x23080;
    *(undefined4 *)((long)plVar10 + 0xc) = 0;
    *(int *)(plVar10 + 3) = iVar7 + 0x23088;
    *(undefined4 *)((long)plVar10 + 0x1c) = 0;
    plVar10[2] = (long)"TYPE_IRQ_MSK";
    *(undefined8 *)((long)plVar10 + 0xbc) = 0;
    plVar10[4] = (long)"CH_IRQ";
    *(int *)(plVar10 + 5) = iVar7 + 0x23090;
    *(undefined4 *)((long)plVar10 + 0x2c) = 0;
    plVar10[6] = (long)"EV_IRQ";
    *(int *)(plVar10 + 7) = iVar7 + 0x23094;
    *(undefined4 *)((long)plVar10 + 0x3c) = 0;
    plVar10[8] = (long)"CH_IRQ_MSK";
    *(int *)(plVar10 + 9) = iVar7 + 0x23098;
    *(undefined4 *)((long)plVar10 + 0x4c) = 0;
    plVar10[10] = (long)"EV_IRQ_MSK";
    *(int *)(plVar10 + 0xb) = iVar7 + 0x2309c;
    *(undefined4 *)((long)plVar10 + 0x5c) = 0;
    plVar10[0xc] = (long)"IEOB_IRQ";
    *(int *)(plVar10 + 0xd) = iVar7 + 0x230b0;
    *(undefined4 *)((long)plVar10 + 0x6c) = 0;
    plVar10[0xe] = (long)"IEOB_IRQ_MSK";
    *(int *)(plVar10 + 0xf) = iVar7 + 0x230b8;
    *(undefined4 *)((long)plVar10 + 0x7c) = 0;
    plVar10[0x10] = (long)"GLOB_IRQ";
    *(int *)(plVar10 + 0x11) = iVar7 + 0x23100;
    *(undefined4 *)((long)plVar10 + 0x8c) = 0;
    plVar10[0x12] = (long)"GLOB_IRQ_EN";
    *(int *)(plVar10 + 0x13) = iVar7 + 0x23108;
    *(undefined4 *)((long)plVar10 + 0x9c) = 0;
    plVar10[0x14] = (long)"GPII_IRQ_STTS";
    *(int *)(plVar10 + 0x15) = iVar7 + 0x23118;
    *(undefined4 *)((long)plVar10 + 0xac) = 0;
    *(int *)(plVar10 + 0x17) = iVar7 + 0x23120;
    plVar10[0x16] = (long)"GPII_IRQ_EN";
LAB_00101718:
    puVar12 = (uint *)(plVar10 + 1);
    do {
      uVar6 = readl_relaxed(*(long *)(param_1 + 0xcc) + (ulong)*puVar12);
      puVar12[1] = uVar6;
      if ((uint)param_1[0x10b] < 2) {
        lVar8 = *plVar3;
      }
      else {
        _printk(&DAT_0010b5d0,piVar2,99,"gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,
                uVar6);
        lVar8 = *plVar3;
      }
      if ((lVar8 != 0) && (1 < *puVar4)) {
        ipc_log_string(lVar8,"ch:%u %s: GPI_cntxt Reg:%s addr:0x%x->val:0x%x\n",99,
                       "gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,puVar12[1]);
      }
      puVar1 = puVar12 + 2;
      puVar12 = puVar12 + 4;
    } while (*(long *)puVar1 != 0);
  }
  else if (*plVar10 != 0) goto LAB_00101718;
  plVar10 = *(long **)(param_1 + 0x152);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(__dev_err,0xb20,0xf0);
    *(long **)(param_1 + 0x152) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    memcpy(plVar10,&gpi_debug_ev_cntxt,0xf0);
LAB_001017f0:
    puVar12 = (uint *)(plVar10 + 1);
    do {
      uVar6 = readl_relaxed(*(long *)(param_1 + 0xce) + (ulong)*puVar12);
      puVar12[1] = uVar6;
      if ((uint)param_1[0x10b] < 2) {
        lVar8 = *plVar3;
      }
      else {
        _printk(&DAT_0010cc7b,piVar2,99,"gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,
                uVar6);
        lVar8 = *plVar3;
      }
      if ((lVar8 != 0) && (1 < *puVar4)) {
        ipc_log_string(lVar8,"ch:%u %s: GPI_ev_cntxt Reg:%s addr:0x%x->val:0x%x\n",99,
                       "gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,puVar12[1]);
      }
      puVar1 = puVar12 + 2;
      puVar12 = puVar12 + 4;
    } while (*(long *)puVar1 != 0);
  }
  else if (*plVar10 != 0) goto LAB_001017f0;
  plVar10 = *(long **)(param_1 + 0x154);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(__printk,0xb20,0x90);
    *(long **)(param_1 + 0x154) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    memcpy(plVar10,&gpi_debug_ch_cntxt,0x90);
LAB_001018c8:
    puVar12 = (uint *)(plVar10 + 1);
    do {
      uVar6 = readl_relaxed(*(long *)(param_1 + 0x4c) + (ulong)*puVar12);
      puVar12[1] = uVar6;
      if ((uint)param_1[0x10b] < 2) {
        lVar8 = *plVar3;
      }
      else {
        _printk(&DAT_0010d8c6,piVar2,99,"gpi_dump_debug_reg",0,*(undefined8 *)(puVar12 + -2),
                *puVar12,uVar6);
        lVar8 = *plVar3;
      }
      if ((lVar8 != 0) && (1 < *puVar4)) {
        ipc_log_string(lVar8,"ch:%u %s: GPI_ch%d Reg:%s addr:0x%x->val:0x%x\n",99,
                       "gpi_dump_debug_reg",0,*(undefined8 *)(puVar12 + -2),*puVar12,puVar12[1]);
      }
      puVar1 = puVar12 + 2;
      puVar12 = puVar12 + 4;
    } while (*(long *)puVar1 != 0);
  }
  else if (*plVar10 != 0) goto LAB_001018c8;
  plVar10 = *(long **)(param_1 + 0x156);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(__printk,0xb20,0x90);
    *(long **)(param_1 + 0x156) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    memcpy(plVar10,&gpi_debug_ch_cntxt,0x90);
LAB_001019a8:
    puVar12 = (uint *)(plVar10 + 1);
    do {
      uVar6 = readl_relaxed(*(long *)(param_1 + 0xae) + (ulong)*puVar12);
      puVar12[1] = uVar6;
      if ((uint)param_1[0x10b] < 2) {
        lVar8 = *plVar3;
      }
      else {
        _printk(&DAT_0010d8c6,piVar2,99,"gpi_dump_debug_reg",1,*(undefined8 *)(puVar12 + -2),
                *puVar12,uVar6);
        lVar8 = *plVar3;
      }
      if ((lVar8 != 0) && (1 < *puVar4)) {
        ipc_log_string(lVar8,"ch:%u %s: GPI_ch%d Reg:%s addr:0x%x->val:0x%x\n",99,
                       "gpi_dump_debug_reg",1,*(undefined8 *)(puVar12 + -2),*puVar12,puVar12[1]);
      }
      puVar1 = puVar12 + 2;
      puVar12 = puVar12 + 4;
    } while (*(long *)puVar1 != 0);
  }
  else if (*plVar10 != 0) goto LAB_001019a8;
  if (*(char *)(*(long *)(param_1 + 0xc6) + 0x1e8) != '\0') goto LAB_00101b8c;
  plVar10 = *(long **)(param_1 + 0x158);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(_dma_release_channel,0xb20,0x230);
    *(long **)(param_1 + 0x158) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    memcpy(plVar10,&gpi_debug_regs,0x230);
LAB_00101a88:
    puVar12 = (uint *)(plVar10 + 1);
    do {
      uVar6 = readl_relaxed(*(long *)(*(long *)(param_1 + 0xc6) + 400) + (ulong)*puVar12);
      puVar12[1] = uVar6;
      if ((uint)param_1[0x10b] < 2) {
        lVar8 = *plVar3;
      }
      else {
        _printk(&DAT_0010ccb0,piVar2,99,"gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,
                uVar6);
        lVar8 = *plVar3;
      }
      if ((lVar8 != 0) && (1 < *puVar4)) {
        ipc_log_string(lVar8,"ch:%u %s: GPI_dbg Reg:%s addr:0x%x->val:0x%x\n",99,
                       "gpi_dump_debug_reg",*(undefined8 *)(puVar12 + -2),*puVar12,puVar12[1]);
      }
      puVar1 = puVar12 + 2;
      puVar12 = puVar12 + 4;
    } while (*(long *)puVar1 != 0);
  }
  else if (*plVar10 != 0) goto LAB_00101a88;
  plVar10 = *(long **)(param_1 + 0x15c);
  if (plVar10 == (long *)0x0) {
    plVar10 = (long *)kmalloc_trace(__printk,0xb20,0xb0);
    *(long **)(param_1 + 0x15c) = plVar10;
    if (plVar10 == (long *)0x0) {
      return;
    }
    memcpy(plVar10,&gpi_debug_qsb_regs,0xb0);
  }
  else if (*plVar10 == 0) goto LAB_00101b8c;
  do {
    plVar11 = plVar10 + 2;
    uVar5 = readl_relaxed(*(long *)(*(long *)(param_1 + 0xc6) + 400) + (ulong)*(uint *)(plVar10 + 1)
                         );
    *(undefined4 *)((long)plVar10 + 0xc) = uVar5;
    plVar10 = plVar11;
  } while (*plVar11 != 0);
LAB_00101b8c:
  iVar7 = readl_relaxed(*(long *)(param_1 + 0xcc) + (ulong)(*param_1 * 0x4000 + 0x23400));
  param_1[0x15e] = iVar7;
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010b872,piVar2,99,"gpi_dump_debug_reg",*param_1 * 0x4000 + 0x23400,iVar7);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_ev_scratch Reg addr:0x%x->val:0x%x\n",99,
                   "gpi_dump_debug_reg",*param_1 * 0x4000 + 0x23400,param_1[0x15e]);
  }
  iVar7 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(uint)(*param_1 * 0x4000 + 0x20060 + param_1[0x42] * 0x80));
  param_1[0x15f] = iVar7;
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c6c3,piVar2,99,"gpi_dump_debug_reg",
            *param_1 * 0x4000 + 0x20060 + param_1[0x42] * 0x80,iVar7);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_ch_scratch Reg addr:0x%x->val:0x%x\n",99,
                   "gpi_dump_debug_reg",*param_1 * 0x4000 + 0x20060 + param_1[0x42] * 0x80,
                   param_1[0x15f]);
  }
  iVar7 = readl_relaxed(*(long *)(param_1 + 0xcc) +
                        (ulong)(uint)(*param_1 * 0x4000 + 0x20060 + param_1[0xa4] * 0x80));
  param_1[0x160] = iVar7;
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010c6c3,piVar2,99,"gpi_dump_debug_reg",
            *param_1 * 0x4000 + 0x20060 + param_1[0xa4] * 0x80,iVar7);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI_ch_scratch Reg addr:0x%x->val:0x%x\n",99,
                   "gpi_dump_debug_reg",*param_1 * 0x4000 + 0x20060 + param_1[0xa4] * 0x80,
                   param_1[0x160]);
  }
  if (*(long *)(param_1 + 0x162) == 0) {
    iVar7 = *(int *)(*(long *)(param_1 + 0xf0) + 0x38);
    param_1[0x164] = iVar7;
    lVar8 = __kmalloc(iVar7,0xb20);
    *(long *)(param_1 + 0x162) = lVar8;
    if (lVar8 == 0) {
      return;
    }
  }
  memcpy(*(void **)(param_1 + 0x162),*(void **)(*(long *)(param_1 + 0xf0) + 0x20),
         (ulong)(uint)param_1[0x164]);
  if (*(long *)(param_1 + 0x166) == 0) {
    iVar7 = *(int *)(*(long *)(param_1 + 0x5a) + 0x38);
    param_1[0x16a] = iVar7;
    lVar8 = __kmalloc(iVar7,0xb20);
    *(long *)(param_1 + 0x166) = lVar8;
    if (lVar8 == 0) {
      return;
    }
  }
  memcpy(*(void **)(param_1 + 0x166),*(void **)(*(long *)(param_1 + 0x5a) + 0x20),
         (ulong)(uint)param_1[0x16a]);
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010d779,piVar2,99,"gpi_dump_debug_reg",0,
            *(undefined8 *)(*(long *)(param_1 + 0x5a) + 0x20));
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI Error log chan:%d base:%p\n",99,"gpi_dump_debug_reg",0,
                   *(undefined8 *)(*(long *)(param_1 + 0x5a) + 0x20));
  }
  if (*(long *)(param_1 + 0x168) == 0) {
    iVar7 = *(int *)(*(long *)(param_1 + 0xbc) + 0x38);
    param_1[0x16b] = iVar7;
    lVar8 = __kmalloc(iVar7,0xb20);
    *(long *)(param_1 + 0x168) = lVar8;
    if (lVar8 == 0) {
      return;
    }
  }
  memcpy(*(void **)(param_1 + 0x168),*(void **)(*(long *)(param_1 + 0xbc) + 0x20),
         (ulong)(uint)param_1[0x16b]);
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010d779,piVar2,99,"gpi_dump_debug_reg",1,
            *(undefined8 *)(*(long *)(param_1 + 0xbc) + 0x20));
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI Error log chan:%d base:%p\n",99,"gpi_dump_debug_reg",1,
                   *(undefined8 *)(*(long *)(param_1 + 0xbc) + 0x20));
  }
  iVar7 = readl_relaxed(*(long *)(param_1 + 0xcc) + (ulong)(*param_1 * 0x4000 + 0x23200));
  param_1[0x16c] = iVar7;
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010d66b,piVar2,99,"gpi_dump_debug_reg",*param_1 * 0x4000 + 0x23200,iVar7);
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: GPI Error log Reg addr:0x%x->val:0x%x\n",99,"gpi_dump_debug_reg"
                   ,*param_1 * 0x4000 + 0x23200,param_1[0x16c]);
  }
  if ((uint)param_1[0x10b] < 2) {
    lVar8 = *plVar3;
  }
  else {
    _printk(&DAT_0010b62b,piVar2,99,"gpi_dump_debug_reg");
    lVar8 = *plVar3;
  }
  if ((lVar8 != 0) && (1 < *puVar4)) {
    ipc_log_string(lVar8,"ch:%u %s: Global IRQ handling Exit\n",99,"gpi_dump_debug_reg");
  }
  return;
}



//------------------------------------------------------------
// gpi_update_multi_desc_flag @ 0010242c size=16
// signature: undefined gpi_update_multi_desc_flag(void)
// callers: []
//------------------------------------------------------------

void gpi_update_multi_desc_flag(long param_1,undefined1 param_2,undefined4 param_3)

{
  long lVar1;
  
  lVar1 = *(long *)(param_1 + 0x118);
  *(undefined1 *)(lVar1 + 0x5c3) = param_2;
  *(undefined4 *)(lVar1 + 0x5c4) = param_3;
  return;
}



//------------------------------------------------------------
// gsi_common_tre_process @ 00102440 size=328
// signature: undefined gsi_common_tre_process(void)
// callers: [gsi_common_tx_tre_optimization]
//------------------------------------------------------------

void gsi_common_tre_process(long param_1,uint param_2,int param_3,undefined8 param_4)

{
  long lVar1;
  long lVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulong uVar7;
  
  if (**(int **)(param_1 + 0x4808) == 0) {
    uVar6 = *(int *)(param_1 + 0x23f0) * param_3;
  }
  else {
    uVar6 = *(uint *)(param_1 + 0xe0);
  }
  uVar3 = *(uint *)(param_1 + 0xe4);
  while( true ) {
    if (uVar6 <= uVar3) {
      return;
    }
    if (uVar3 == param_2) break;
    iVar4 = *(int *)(param_1 + 0xe8) + 1;
    uVar7 = (ulong)(uVar3 % 0x1c0);
    *(int *)(param_1 + 0xe8) = iVar4;
    lVar1 = param_1 + uVar7 * 4;
    uVar5 = *(uint *)(lVar1 + 0x1cf0);
    if ((8 < uVar5) && (lVar2 = *(long *)(param_1 + uVar7 * 8 + 0xf0), lVar2 != -1)) {
      dma_unmap_page_attrs(param_4,lVar2,uVar5,1,0);
      uVar3 = *(uint *)(param_1 + 0xe4);
      iVar4 = *(int *)(param_1 + 0xe8);
      uVar5 = *(uint *)(lVar1 + 0x1cf0);
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),
                   "%s:unmap_msg_cnt %d freed_cnt:%d wr_idx:%d len:%d\n","gsi_common_tre_process",
                   uVar3,iVar4,uVar7,uVar5);
    uVar3 = *(int *)(param_1 + 0xe4) + 1;
    *(uint *)(param_1 + 0xe4) = uVar3;
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s:last %d msg unmapped msg_cnt:%d\n",
                 "gsi_common_tre_process",param_2,uVar6);
  return;
}



//------------------------------------------------------------
// gsi_common_tx_tre_optimization @ 0010258c size=392
// signature: undefined gsi_common_tx_tre_optimization(void)
// callers: []
//------------------------------------------------------------

int gsi_common_tx_tre_optimization
              (long param_1,uint param_2,uint param_3,undefined4 param_4,undefined8 param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = param_2 / param_3;
  }
  if (param_2 != uVar1 * param_3) {
    uVar1 = uVar1 + 1;
  }
  if ((int)uVar1 < 1) {
    iVar2 = 1;
  }
  else {
    uVar3 = 0;
    iVar2 = 1;
    do {
      if (uVar1 != *(uint *)(param_1 + 0x23f0)) {
        ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),
                       "%s: calling wait for_completion ix:%d irq_cnt:%d\n",
                       "gsi_common_tx_tre_optimization",uVar3,*(undefined4 *)(param_1 + 0x23f0));
        iVar2 = wait_for_completion_timeout(*(undefined8 *)(param_1 + 8),param_4);
        **(undefined4 **)(param_1 + 8) = 0;
        if (iVar2 == 0) {
          ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s: msg xfer timeout\n",
                         "gsi_common_tx_tre_optimization");
          return 0;
        }
        if (**(char **)(param_1 + 0x4800) != '\0') {
          ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"gsi error\n");
          return -5;
        }
      }
      ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s: maxirq_cnt:%d i:%d\n",
                     "gsi_common_tx_tre_optimization",uVar1,uVar3);
      gsi_common_tre_process(param_1,param_2,param_3,param_5);
      if (*(uint *)(param_1 + 0xe0) < param_2) {
        return iVar2;
      }
      uVar3 = uVar3 + 1;
    } while (uVar1 != uVar3);
  }
  gsi_common_tre_process(param_1,param_2,param_3,param_5);
  ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s:  timeout :%d\n",
                 "gsi_common_tx_tre_optimization",iVar2);
  return iVar2;
}



//------------------------------------------------------------
// gsi_common_clear_tre_indexes @ 00102718 size=16
// signature: undefined gsi_common_clear_tre_indexes(void)
// callers: []
//------------------------------------------------------------

void gsi_common_clear_tre_indexes(undefined8 *param_1)

{
  *param_1 = 0;
  *(undefined4 *)(param_1 + 1) = 0;
  *(undefined4 *)(param_1 + 0x462) = 0;
  return;
}



//------------------------------------------------------------
// gsi_common_fill_tre_buf @ 0010272c size=572
// signature: undefined gsi_common_fill_tre_buf(void)
// callers: []
//------------------------------------------------------------

char gsi_common_fill_tre_buf(long param_1,uint param_2)

{
  char cVar1;
  bool bVar2;
  long lVar3;
  byte bVar4;
  ulong *puVar5;
  ulong uVar6;
  
  lVar3 = 0x20;
  if ((param_2 & 1) == 0) {
    lVar3 = 0x2408;
  }
  lVar3 = param_1 + lVar3;
  bVar4 = *(byte *)(lVar3 + 0xb8);
  cVar1 = (bVar4 >> 4 & 1) + (bVar4 >> 3 & 1) + (bVar4 >> 2 & 1) + (bVar4 >> 1 & 1) + (bVar4 & 1);
  sg_init_table(*(undefined8 *)(lVar3 + 0x40),cVar1);
  bVar4 = *(byte *)(lVar3 + 0xb8);
  bVar2 = (bVar4 & 1) != 0;
  if (bVar2) {
    puVar5 = *(ulong **)(lVar3 + 0x40);
    *puVar5 = (*puVar5 & 3 | (((lVar3 + 0x68) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
              0x200000000;
    *(uint *)(puVar5 + 1) = (uint)(lVar3 + 0x68) & 0xfff;
    *(undefined4 *)((long)puVar5 + 0xc) = 0x10;
    bVar4 = *(byte *)(lVar3 + 0xb8);
  }
  uVar6 = (ulong)bVar2;
  if ((bVar4 >> 1 & 1) != 0) {
    puVar5 = (ulong *)(*(long *)(lVar3 + 0x40) + uVar6 * 0x20);
    *puVar5 = (*puVar5 & 3 | (((lVar3 + 0x88) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
              0x200000000;
    *(uint *)(puVar5 + 1) = (uint)(lVar3 + 0x88) & 0xfff;
    *(undefined4 *)((long)puVar5 + 0xc) = 0x10;
    bVar4 = *(byte *)(lVar3 + 0xb8);
    uVar6 = (ulong)(bVar2 + 1);
  }
  if ((bVar4 >> 2 & 1) != 0) {
    puVar5 = (ulong *)(*(long *)(lVar3 + 0x40) + uVar6 * 0x20);
    *puVar5 = (*puVar5 & 3 | (((lVar3 + 0x78) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
              0x200000000;
    *(uint *)(puVar5 + 1) = (uint)(lVar3 + 0x78) & 0xfff;
    *(undefined4 *)((long)puVar5 + 0xc) = 0x10;
    bVar4 = *(byte *)(lVar3 + 0xb8);
    uVar6 = (ulong)((int)uVar6 + 1);
  }
  if ((bVar4 >> 3 & 1) != 0) {
    puVar5 = (ulong *)(*(long *)(lVar3 + 0x40) + uVar6 * 0x20);
    *puVar5 = (*puVar5 & 3 | (((lVar3 + 0x98) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
              0x200000000;
    *(uint *)(puVar5 + 1) = (uint)(lVar3 + 0x98) & 0xfff;
    *(undefined4 *)((long)puVar5 + 0xc) = 0x10;
    bVar4 = *(byte *)(lVar3 + 0xb8);
    uVar6 = (ulong)((int)uVar6 + 1);
  }
  if ((bVar4 >> 4 & 1) != 0) {
    puVar5 = (ulong *)(*(long *)(lVar3 + 0x40) + uVar6 * 0x20);
    *puVar5 = (*puVar5 & 3 | (((lVar3 + 0xa8) * 0x100 >> 8) + 0x8000000000U >> 0xc) << 6) -
              0x200000000;
    *(uint *)(puVar5 + 1) = (uint)(lVar3 + 0xa8) & 0xfff;
    *(undefined4 *)((long)puVar5 + 0xc) = 0x10;
    bVar4 = *(byte *)(lVar3 + 0xb8);
  }
  ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s: tre_cnt:%d chan:%d flags:0x%x\n",
                 "gsi_common_fill_tre_buf",cVar1,param_2 & 1,bVar4);
  return cVar1;
}



//------------------------------------------------------------
// gsi_common_prep_desc_and_submit @ 0010296c size=592
// signature: undefined gsi_common_prep_desc_and_submit(void)
// callers: []
//------------------------------------------------------------

undefined8
gsi_common_prep_desc_and_submit(long param_1,undefined4 param_2,ulong param_3,ulong param_4)

{
  long lVar1;
  bool bVar2;
  int iVar3;
  long *plVar4;
  long lVar5;
  undefined *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  code *pcVar9;
  
  if ((param_3 & 1) == 0) {
    plVar4 = *(long **)(param_1 + 0x2440);
    if (((plVar4 != (long *)0x0) && (*plVar4 != 0)) &&
       (pcVar9 = *(code **)(*plVar4 + 0x108), pcVar9 != (code *)0x0)) {
      if (*(int *)(pcVar9 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x102a50);
        (*pcVar9)();
      }
      lVar5 = (*pcVar9)(plVar4,*(undefined8 *)(param_1 + 0x2448),param_2,2,3,0);
      if (lVar5 != 0) {
        *(code **)(lVar5 + 0x28) = gsi_common_rx_cb;
        *(long *)(lVar5 + 0x38) = param_1 + 0x2410;
        puVar8 = *(undefined4 **)(param_1 + 8);
        *(long *)(param_1 + 0x2408) = lVar5;
        plVar4 = *(long **)(param_1 + 0x2440);
        goto LAB_00102a7c;
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"prep_slave_sg for rx failed\n");
    lVar5 = *(long *)(param_1 + 0x10);
    if (lVar5 != 0) {
      pcVar7 = "prep_slave_sg for rx failed\n";
      goto LAB_00102b48;
    }
    puVar6 = &DAT_0010e3ac;
  }
  else {
    plVar4 = *(long **)(param_1 + 0x58);
    if (((plVar4 != (long *)0x0) && (*plVar4 != 0)) &&
       (pcVar9 = *(code **)(*plVar4 + 0x108), pcVar9 != (code *)0x0)) {
      if (*(int *)(pcVar9 + -4) != 0xfa8d001) {
                    /* WARNING: Does not return */
        pcVar9 = (code *)SoftwareBreakpoint(0x8229,0x1029d4);
        (*pcVar9)();
      }
      lVar5 = (*pcVar9)(plVar4,*(undefined8 *)(param_1 + 0x60),param_2,1,3,0);
      if (lVar5 != 0) {
        bVar2 = (param_4 & 1) == 0;
        pcVar9 = (code *)0x0;
        if (bVar2) {
          pcVar9 = gsi_common_tx_cb;
        }
        lVar1 = 0;
        if (bVar2) {
          lVar1 = param_1 + 0x28;
        }
        *(code **)(lVar5 + 0x28) = pcVar9;
        *(long *)(lVar5 + 0x38) = lVar1;
        puVar8 = *(undefined4 **)(param_1 + 8);
        *(long *)(param_1 + 0x20) = lVar5;
        plVar4 = *(long **)(param_1 + 0x58);
LAB_00102a7c:
        *puVar8 = 0;
        if (*(int *)(*(code **)(lVar5 + 0x18) + -4) != -0x1f0fdeee) {
                    /* WARNING: Does not return */
          pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x102a9c);
          (*pcVar9)();
        }
        iVar3 = (**(code **)(lVar5 + 0x18))();
        if (-1 < iVar3) {
          if (*(int *)(*(code **)(*plVar4 + 0x160) + -4) != -0x3330eabd) {
                    /* WARNING: Does not return */
            pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x102ac8);
            (*pcVar9)();
          }
          (**(code **)(*plVar4 + 0x160))(plVar4);
          return 0;
        }
        ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"%s: dmaengine_submit failed (%d)\n",
                       "gsi_common_doorbell_hit",iVar3);
        if (*(long *)(param_1 + 0x10) == 0) {
          _printk(&DAT_0010db21,"gsi_common_doorbell_hit",iVar3);
          return 0xffffffea;
        }
        _dev_err(*(long *)(param_1 + 0x10),"%s: dmaengine_submit failed (%d)\n",
                 "gsi_common_doorbell_hit",iVar3);
        return 0xffffffea;
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"prep_slave_sg for tx failed\n");
    lVar5 = *(long *)(param_1 + 0x10);
    if (lVar5 != 0) {
      pcVar7 = "prep_slave_sg for tx failed\n";
LAB_00102b48:
      _dev_err(lVar5,pcVar7);
      return 0xfffffff4;
    }
    puVar6 = &DAT_0010cc09;
  }
  _printk(puVar6);
  return 0xfffffff4;
}



//------------------------------------------------------------
// gsi_common_tx_cb @ 00102bc0 size=136
// signature: undefined gsi_common_tx_cb(void)
// callers: []
//------------------------------------------------------------

void gsi_common_tx_cb(long param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  
  if ((param_1 == 0) || (puVar2 = *(undefined1 **)(param_1 + 0x20), puVar2 == (undefined1 *)0x0)) {
    _printk(&DAT_0010c0cb,"gsi_common_tx_cb");
  }
  else {
    ipc_log_string(*(undefined8 *)(puVar2 + 0x47f0),"%s: protocol:%d\n","gsi_common_tx_cb",*puVar2);
    if (*(int *)(*(code **)(puVar2 + 0x2400) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c1c);
      (*pcVar1)();
    }
    (**(code **)(puVar2 + 0x2400))(param_1);
  }
  return;
}



//------------------------------------------------------------
// gsi_common_rx_cb @ 00102c4c size=128
// signature: undefined gsi_common_rx_cb(void)
// callers: []
//------------------------------------------------------------

void gsi_common_rx_cb(long param_1)

{
  code *pcVar1;
  undefined1 *puVar2;
  
  if ((param_1 == 0) || (puVar2 = *(undefined1 **)(param_1 + 0x20), puVar2 == (undefined1 *)0x0)) {
    _printk(&DAT_0010cd5a,"gsi_common_rx_cb");
  }
  else {
    if (*(int *)(*(code **)(puVar2 + 0x47e8) + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102c84);
      (*pcVar1)();
    }
    (**(code **)(puVar2 + 0x47e8))();
    ipc_log_string(*(undefined8 *)(puVar2 + 0x47f0),"%s: protocol:%d\n","gsi_common_rx_cb",*puVar2);
  }
  return;
}



//------------------------------------------------------------
// geni_gsi_common_request_channel @ 00102cd0 size=636
// signature: undefined geni_gsi_common_request_channel(void)
// callers: []
//------------------------------------------------------------

int geni_gsi_common_request_channel(long param_1)

{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  long lVar4;
  undefined *puVar5;
  char *pcVar6;
  code *pcVar7;
  
  uVar2 = *(ulong *)(param_1 + 0x58);
  if (uVar2 == 0) {
    uVar2 = dma_request_chan(*(undefined8 *)(param_1 + 0x10),&DAT_0010da1c);
    uVar3 = 0;
    if (uVar2 < 0xfffffffffffff001) {
      uVar3 = uVar2;
    }
    *(ulong *)(param_1 + 0x58) = uVar3;
    if (uVar3 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"tx dma req slv chan ret:%d\n",0xfffffffb);
      if (*(long *)(param_1 + 0x10) == 0) {
        _printk(&DAT_0010e16e,0xfffffffb);
        return -5;
      }
      _dev_err(*(long *)(param_1 + 0x10),"tx dma req slv chan ret:%d\n",0xfffffffb);
      return -5;
    }
  }
  if (*(long *)(param_1 + 0x2440) == 0) {
    uVar3 = dma_request_chan(*(undefined8 *)(param_1 + 0x10),&DAT_0010be8c);
    uVar2 = 0;
    if (uVar3 < 0xfffffffffffff001) {
      uVar2 = uVar3;
    }
    *(ulong *)(param_1 + 0x2440) = uVar2;
    if (uVar2 == 0) {
      ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"rx dma req slv chan ret:%d\n",0xfffffffb);
      if (*(long *)(param_1 + 0x10) == 0) {
        _printk(&DAT_0010c3fd,0xfffffffb);
      }
      else {
        _dev_err(*(long *)(param_1 + 0x10),"rx dma req slv chan ret:%d\n",0xfffffffb);
      }
      dma_release_channel(*(undefined8 *)(param_1 + 0x58));
      return -5;
    }
    uVar2 = *(ulong *)(param_1 + 0x58);
  }
  *(code **)(param_1 + 0x78) = gsi_common_ev_cb;
  *(long *)(param_1 + 0x80) = param_1;
  *(undefined4 *)(param_1 + 0x70) = 1;
  *(undefined4 **)(uVar2 + 0x68) = (undefined4 *)(param_1 + 0x70);
  pcVar7 = *(code **)(**(long **)(param_1 + 0x58) + 0x130);
  if (pcVar7 == (code *)0x0) {
    iVar1 = -0x26;
LAB_00102e08:
    ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"tx dma slave config ret:%d\n",iVar1);
    lVar4 = *(long *)(param_1 + 0x10);
    if (lVar4 != 0) {
      pcVar6 = "tx dma slave config ret:%d\n";
LAB_00102e78:
      _dev_err(lVar4,pcVar6,iVar1);
      goto LAB_00102e80;
    }
    puVar5 = &DAT_0010be8f;
  }
  else {
    if (*(int *)(pcVar7 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
      pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102d84);
      (*pcVar7)();
    }
    iVar1 = (*pcVar7)(*(long **)(param_1 + 0x58),0);
    if (iVar1 != 0) goto LAB_00102e08;
    *(long *)(param_1 + 0x2468) = param_1;
    *(code **)(param_1 + 0x2460) = gsi_common_ev_cb;
    *(undefined4 *)(param_1 + 0x2458) = 1;
    *(long *)(*(long *)(param_1 + 0x2440) + 0x68) = param_1 + 0x2458;
    pcVar7 = *(code **)(**(long **)(param_1 + 0x2440) + 0x130);
    if (pcVar7 == (code *)0x0) {
      iVar1 = -0x26;
    }
    else {
      if (*(int *)(pcVar7 + -4) != -0x50989b59) {
                    /* WARNING: Does not return */
        pcVar7 = (code *)SoftwareBreakpoint(0x8228,0x102dd8);
        (*pcVar7)();
      }
      iVar1 = (*pcVar7)(*(long **)(param_1 + 0x2440),0);
      if (iVar1 == 0) {
        *(long *)(param_1 + 0x48) = param_1;
        *(long *)(param_1 + 0x2430) = param_1;
        *(undefined1 *)(param_1 + 0x47f8) = 1;
        return 0;
      }
    }
    ipc_log_string(*(undefined8 *)(param_1 + 0x47f0),"rx dma slave config ret:%d\n",iVar1);
    lVar4 = *(long *)(param_1 + 0x10);
    if (lVar4 != 0) {
      pcVar6 = "rx dma slave config ret:%d\n";
      goto LAB_00102e78;
    }
    puVar5 = &DAT_0010cfc3;
  }
  _printk(puVar5,iVar1);
LAB_00102e80:
  dma_release_channel(*(undefined8 *)(param_1 + 0x58));
  dma_release_channel(*(undefined8 *)(param_1 + 0x2440));
  *(undefined8 *)(param_1 + 0x58) = 0;
  *(undefined8 *)(param_1 + 0x2440) = 0;
  return iVar1;
}



//------------------------------------------------------------
// gsi_common_ev_cb @ 00102f50 size=152
// signature: undefined gsi_common_ev_cb(void)
// callers: []
//------------------------------------------------------------

void gsi_common_ev_cb(undefined8 param_1,undefined8 param_2,undefined1 *param_3)

{
  code *pcVar1;
  
  if (param_3 == (undefined1 *)0x0) {
    _printk(&DAT_0010db45,"gsi_common_ev_cb");
  }
  else {
    ipc_log_string(*(undefined8 *)(param_3 + 0x47f0),"%s: protocol:%d\n","gsi_common_ev_cb",*param_3
                  );
    if (*(int *)(*(code **)(param_3 + 0x4810) + -4) != 0x437bfba3) {
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x102fb8);
      (*pcVar1)();
    }
    (**(code **)(param_3 + 0x4810))(param_1,param_2,param_3);
  }
  return;
}



//------------------------------------------------------------
// geni_gsi_ch_start @ 00102fec size=472
// signature: undefined geni_gsi_ch_start(void)
// callers: []
//------------------------------------------------------------

undefined8 geni_gsi_ch_start(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long lVar5;
  
  lVar5 = *(long *)(param_1 + 0x118);
  mutex_lock(lVar5 + 0x378);
  lVar3 = lVar5 + 0x434;
  if (*(uint *)(lVar5 + 0x42c) < 3) {
    lVar2 = *(long *)(lVar5 + 0x420);
  }
  else {
    _printk(&DAT_0010e26d,lVar3,*(undefined4 *)(lVar5 + 0x290),"geni_gsi_ch_start",1);
    lVar2 = *(long *)(lVar5 + 0x420);
  }
  if ((lVar2 != 0) && (2 < *(uint *)(lVar5 + 0x428))) {
    ipc_log_string(lVar2,"ch:%u %s: Start chan:%d\n",*(undefined4 *)(lVar5 + 0x290),
                   "geni_gsi_ch_start",1);
  }
  iVar1 = gpi_start_chan(lVar5 + 400);
  if (iVar1 == 0) {
    if (*(uint *)(lVar5 + 0x42c) < 3) {
      lVar2 = *(long *)(lVar5 + 0x420);
    }
    else {
      _printk(&DAT_0010e26d,lVar3,*(undefined4 *)(lVar5 + 0x108),"geni_gsi_ch_start",0);
      lVar2 = *(long *)(lVar5 + 0x420);
    }
    if ((lVar2 != 0) && (2 < *(uint *)(lVar5 + 0x428))) {
      ipc_log_string(lVar2,"ch:%u %s: Start chan:%d\n",*(undefined4 *)(lVar5 + 0x108),
                     "geni_gsi_ch_start",0);
    }
    iVar1 = gpi_start_chan(lVar5 + 8);
    if (iVar1 == 0) {
      uVar4 = 0;
      goto LAB_0010310c;
    }
    lVar2 = 0;
  }
  else {
    lVar2 = 1;
  }
  if (*(uint *)(lVar5 + 0x42c) < 2) {
    lVar3 = *(long *)(lVar5 + 0x420);
  }
  else {
    _printk(&DAT_0010d326,lVar3,*(undefined4 *)(lVar5 + lVar2 * 0x188 + 0x108),"geni_gsi_ch_start",
            iVar1);
    lVar3 = *(long *)(lVar5 + 0x420);
  }
  if ((lVar3 != 0) && (1 < *(uint *)(lVar5 + 0x428))) {
    ipc_log_string(lVar3,"ch:%u %s: Error Starting Channel ret:%d\n",
                   *(undefined4 *)(lVar5 + lVar2 * 0x188 + 0x108),"geni_gsi_ch_start",iVar1);
  }
  uVar4 = 0xffffff98;
LAB_0010310c:
  mutex_unlock(lVar5 + 0x378);
  return uVar4;
}



//------------------------------------------------------------
// gpi_start_chan @ 001031c4 size=324
// signature: undefined gpi_start_chan(void)
// callers: [gpi_q2spi_terminate_all, gpi_config, gpi_pause, gpi_resume, geni_gsi_ch_start, gpi_terminate_all]
//------------------------------------------------------------

int gpi_start_chan(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x118);
  if (*(uint *)(lVar3 + 0x42c) < 3) {
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  else {
    _printk(&DAT_0010c6a9,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_start_chan");
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  if ((lVar2 != 0) && (2 < *(uint *)(lVar3 + 0x428))) {
    ipc_log_string(lVar2,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_start_chan");
  }
  iVar1 = gpi_send_cmd(lVar3,param_1,1);
  if (iVar1 == 0) {
    _raw_write_lock_irq(lVar3 + 0x3b4);
    *(undefined4 *)(param_1 + 0x124) = 3;
    _raw_write_unlock_irq(lVar3 + 0x3b4);
  }
  else {
    if (*(uint *)(lVar3 + 0x42c) < 2) {
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    else {
      _printk(&DAT_0010d251,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_start_chan",
              "CH START",iVar1);
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    if ((lVar2 != 0) && (1 < *(uint *)(lVar3 + 0x428))) {
      ipc_log_string(lVar2,"ch:%u %s: Error with cmd:%s ret:%d\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_start_chan","CH START",iVar1);
    }
  }
  return iVar1;
}



//------------------------------------------------------------
// gpi_terminate_channel @ 0010330c size=328
// signature: undefined gpi_terminate_channel(void)
// callers: [geni_gsi_disconnect_doorbell_stop_ch]
//------------------------------------------------------------

int gpi_terminate_channel(long param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  
  lVar4 = *(long *)(param_1 + 0x118);
  mutex_lock(lVar4 + 0x378);
  iVar1 = gpi_send_cmd(lVar4,param_1,2);
  iVar2 = 0;
  if (iVar1 != 0) {
    if (*(uint *)(lVar4 + 0x42c) < 2) {
      lVar3 = *(long *)(lVar4 + 0x420);
    }
    else {
      _printk(&DAT_0010c04d,lVar4 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_terminate_channel",
              iVar1);
      lVar3 = *(long *)(lVar4 + 0x420);
    }
    if ((lVar3 != 0) && (1 < *(uint *)(lVar4 + 0x428))) {
      ipc_log_string(lVar3,"ch:%u %s: Error Stopping Chan:%d,resetting\n",
                     *(undefined4 *)(param_1 + 0x100),"gpi_terminate_channel",iVar1);
    }
    iVar2 = gpi_send_cmd(lVar4,param_1,3);
    if (iVar2 != 0) {
      if (*(uint *)(lVar4 + 0x42c) < 2) {
        lVar3 = *(long *)(lVar4 + 0x420);
      }
      else {
        _printk(&DAT_0010cfe1,lVar4 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_terminate_channel"
                ,iVar2);
        lVar3 = *(long *)(lVar4 + 0x420);
      }
      if ((lVar3 != 0) && (1 < *(uint *)(lVar4 + 0x428))) {
        ipc_log_string(lVar3,"ch:%u %s: error resetting channel:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_terminate_channel",iVar2);
      }
    }
  }
  mutex_unlock(lVar4 + 0x378);
  return iVar2;
}



//------------------------------------------------------------
// gpi_send_cmd @ 00103454 size=640
// signature: undefined gpi_send_cmd(void)
// callers: [gpi_start_chan, gpi_pause, gpi_resume, gpi_alloc_chan, gpi_free_chan_resources, gpi_q2spi_terminate_all, gpi_terminate_channel, gpi_alloc_ev_chan, gpi_config, geni_gsi_connect_doorbell, gpi_reset_chan, geni_gsi_disconnect_doorbell_stop_ch, gpi_terminate_all]
//------------------------------------------------------------

undefined8 gpi_send_cmd(int *param_1,long param_2,uint param_3)

{
  ulong uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  code *pcVar5;
  undefined4 uVar6;
  long lVar7;
  undefined8 uVar8;
  uint uVar9;
  ulong uVar10;
  
  if (param_3 < 10) {
    uVar9 = *(uint *)(param_2 + 0x100);
  }
  else {
    uVar9 = 2;
  }
  if ((uint)param_1[0x10b] < 3) {
    lVar7 = *(long *)(param_1 + 0x108);
  }
  else {
    if (0xc < param_3) goto LAB_001036d0;
    _printk(&DAT_0010c0e7,param_1 + 0x10d,uVar9,"gpi_send_cmd",(&gpi_cmd_str)[param_3]);
    lVar7 = *(long *)(param_1 + 0x108);
  }
  if ((lVar7 != 0) && (2 < (uint)param_1[0x10a])) {
    if (0xc < param_3) goto LAB_001036d0;
    ipc_log_string(lVar7,"ch:%u %s: sending cmd: %s\n",uVar9,"gpi_send_cmd",(&gpi_cmd_str)[param_3])
    ;
  }
  uVar10 = (ulong)param_3;
  piVar2 = (int *)(param_2 + 0x150);
  if (9 < param_3) {
    piVar2 = param_1 + 0xd8;
  }
  param_1[0xfe] = 0;
  param_1[0x106] = param_3;
  uVar1 = uVar10 << 4 | 4;
  if (param_3 < 10) {
    if (0xd0 < uVar1) goto LAB_001036d0;
    uVar4 = uVar9 | *(int *)(gpi_cmd_info + (ulong)param_3 * 0x10 + 4) << 0x18;
  }
  else {
    if (0xd0 < uVar1) goto LAB_001036d0;
    uVar4 = *(int *)(gpi_cmd_info + (ulong)param_3 * 0x10 + 4) << 0x18;
  }
  writel_relaxed(uVar4,*(undefined8 *)piVar2);
  if (0xd0 < (uVar10 << 4 | 0xc)) {
LAB_001036d0:
                    /* WARNING: Does not return */
    pcVar5 = (code *)SoftwareBreakpoint(1,0x1036d4);
    (*pcVar5)();
  }
  uVar8 = __msecs_to_jiffies(*(undefined4 *)(gpi_cmd_info + uVar10 * 0x10 + 0xc));
  lVar7 = wait_for_completion_timeout(param_1 + 0xfe,uVar8);
  if (lVar7 == 0) {
    uVar6 = readl_relaxed(*(long *)(param_1 + 0xcc) + (ulong)(*param_1 * 0x4000 + 0x23080));
    if ((uint)param_1[0x10b] < 2) {
      lVar7 = *(long *)(param_1 + 0x108);
    }
    else {
      if (0xc < param_3) goto LAB_001036d0;
      _printk(&DAT_0010d40f,param_1 + 0x10d,uVar9,"gpi_send_cmd",(&gpi_cmd_str)[uVar10],uVar6);
      lVar7 = *(long *)(param_1 + 0x108);
    }
    if ((lVar7 != 0) && (1 < (uint)param_1[0x10a])) {
      if (0xc < param_3) goto LAB_001036d0;
      ipc_log_string(lVar7,"ch:%u %s: cmd: %s completion timeout irq_status=0x%x\n",uVar9,
                     "gpi_send_cmd",(&gpi_cmd_str)[uVar10],uVar6);
    }
LAB_001036b0:
    uVar8 = 0xfffffffb;
  }
  else {
    if (0xd0 < (uVar10 << 4 | 8)) goto LAB_001036d0;
    if (2 < uVar10 - 5) {
      if (param_3 < 10) {
        iVar3 = *(int *)(param_2 + 0x120);
      }
      else {
        iVar3 = param_1[0xea];
      }
      if (iVar3 != *(int *)(gpi_cmd_info + uVar10 * 0x10 + 8)) goto LAB_001036b0;
    }
    uVar8 = 0;
  }
  return uVar8;
}



//------------------------------------------------------------
// geni_gsi_connect_doorbell @ 001036d8 size=188
// signature: undefined geni_gsi_connect_doorbell(void)
// callers: []
//------------------------------------------------------------

int geni_gsi_connect_doorbell(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x118);
  iVar1 = gpi_send_cmd(lVar3,param_1,8);
  if (iVar1 != 0) {
    if (*(uint *)(lVar3 + 0x42c) < 2) {
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    else {
      _printk(&DAT_0010ca5d,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),
              "geni_gsi_connect_doorbell",iVar1);
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    if ((lVar2 != 0) && (1 < *(uint *)(lVar3 + 0x428))) {
      ipc_log_string(lVar2,"ch:%u %s: Error enable Chan:%d HID interrupt\n",
                     *(undefined4 *)(param_1 + 0x100),"geni_gsi_connect_doorbell",iVar1);
    }
    gpi_dump_debug_reg(lVar3);
  }
  return iVar1;
}



//------------------------------------------------------------
// geni_gsi_disconnect_doorbell_stop_ch @ 00103798 size=940
// signature: undefined geni_gsi_disconnect_doorbell_stop_ch(void)
// callers: []
//------------------------------------------------------------

int geni_gsi_disconnect_doorbell_stop_ch(long param_1,ulong param_2)

{
  long lVar1;
  long *plVar2;
  bool bVar3;
  int iVar4;
  long lVar5;
  undefined8 uVar6;
  ulong uVar7;
  long lVar8;
  long *plVar9;
  
  lVar8 = *(long *)(param_1 + 0x118);
  iVar4 = gpi_send_cmd(lVar8,param_1,9);
  bVar3 = iVar4 != 0;
  if (iVar4 != 0) {
    if (*(uint *)(lVar8 + 0x42c) < 2) {
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    else {
      _printk(&DAT_0010bcd0,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
              "geni_gsi_disconnect_doorbell_stop_ch",iVar4);
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    if ((lVar5 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
      ipc_log_string(lVar5,"ch:%u %s: Error disable Chan:%d HID interrupt\n",
                     *(undefined4 *)(param_1 + 0x100),"geni_gsi_disconnect_doorbell_stop_ch",iVar4);
    }
    gpi_dump_debug_reg(lVar8);
  }
  if ((param_2 & 1) == 0) {
    lVar5 = lVar8 + 0x230;
    uVar6 = _raw_spin_lock_irqsave(lVar5);
    plVar9 = *(long **)(lVar8 + 600);
    if ((plVar9 == (long *)(lVar8 + 600)) || (plVar9 + -0x13 == (long *)0x0)) {
      _raw_spin_unlock_irqrestore(lVar5,uVar6);
    }
    else {
      uVar7 = __list_del_entry_valid(plVar9);
      if ((uVar7 & 1) != 0) {
        lVar8 = *plVar9;
        plVar2 = (long *)plVar9[1];
        *(long **)(lVar8 + 8) = plVar2;
        *plVar2 = lVar8;
      }
      *plVar9 = -0x2152ffffffffff00;
      plVar9[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar5,uVar6);
      kfree(plVar9 + -0x13);
    }
  }
  else {
    if (*(uint *)(lVar8 + 0x42c) < 3) {
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    else {
      _printk(&DAT_0010e2a1,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
              "geni_gsi_disconnect_doorbell_stop_ch");
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    if ((lVar5 != 0) && (2 < *(uint *)(lVar8 + 0x428))) {
      ipc_log_string(lVar5,"ch:%u %s: Stop RX chan\n",*(undefined4 *)(param_1 + 0x100),
                     "geni_gsi_disconnect_doorbell_stop_ch");
    }
    iVar4 = gpi_terminate_channel(lVar8 + 400);
    if (iVar4 != 0) {
      if (*(uint *)(lVar8 + 0x42c) < 2) {
        lVar5 = *(long *)(lVar8 + 0x420);
      }
      else {
        _printk(&DAT_0010e3cb,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
                "geni_gsi_disconnect_doorbell_stop_ch",iVar4);
        lVar5 = *(long *)(lVar8 + 0x420);
      }
      if ((lVar5 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
        ipc_log_string(lVar5,"ch:%u %s: Error Stopping RX Chan:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"geni_gsi_disconnect_doorbell_stop_ch",iVar4
                      );
      }
      gpi_dump_debug_reg(lVar8);
      bVar3 = true;
    }
    lVar5 = lVar8 + 0x230;
    uVar6 = _raw_spin_lock_irqsave(lVar5);
    plVar9 = *(long **)(lVar8 + 600);
    if ((plVar9 == (long *)(lVar8 + 600)) || (plVar9 + -0x13 == (long *)0x0)) {
      _raw_spin_unlock_irqrestore(lVar5,uVar6);
    }
    else {
      uVar7 = __list_del_entry_valid(plVar9);
      if ((uVar7 & 1) != 0) {
        lVar1 = *plVar9;
        plVar2 = (long *)plVar9[1];
        *(long **)(lVar1 + 8) = plVar2;
        *plVar2 = lVar1;
      }
      *plVar9 = -0x2152ffffffffff00;
      plVar9[1] = -0x2152fffffffffede;
      _raw_spin_unlock_irqrestore(lVar5,uVar6);
      kfree(plVar9 + -0x13);
    }
    if (*(uint *)(lVar8 + 0x42c) < 3) {
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    else {
      _printk(&DAT_0010bd01,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
              "geni_gsi_disconnect_doorbell_stop_ch");
      lVar5 = *(long *)(lVar8 + 0x420);
    }
    if ((lVar5 != 0) && (2 < *(uint *)(lVar8 + 0x428))) {
      ipc_log_string(lVar5,"ch:%u %s: Stop TX chan\n",*(undefined4 *)(param_1 + 0x100),
                     "geni_gsi_disconnect_doorbell_stop_ch");
    }
    iVar4 = gpi_terminate_channel(lVar8 + 8);
    if (iVar4 == 0) {
      if (!bVar3) {
        return 0;
      }
    }
    else {
      if (*(uint *)(lVar8 + 0x42c) < 2) {
        lVar5 = *(long *)(lVar8 + 0x420);
      }
      else {
        _printk(&DAT_0010b457,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
                "geni_gsi_disconnect_doorbell_stop_ch",iVar4);
        lVar5 = *(long *)(lVar8 + 0x420);
      }
      if ((lVar5 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
        ipc_log_string(lVar5,"ch:%u %s: Error Stopping TX Chan:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"geni_gsi_disconnect_doorbell_stop_ch",iVar4
                      );
      }
      gpi_dump_debug_reg(lVar8);
    }
    iVar4 = -0x10;
  }
  return iVar4;
}



//------------------------------------------------------------
// gpi_mark_stale_events @ 00103b48 size=280
// signature: undefined gpi_mark_stale_events(void)
// callers: [gpi_reset_chan]
//------------------------------------------------------------

void gpi_mark_stale_events(long param_1)

{
  int iVar1;
  long lVar2;
  ulong uVar3;
  long lVar4;
  long lVar5;
  ulong uVar6;
  
  lVar4 = *(long *)(param_1 + 0x118);
  lVar5 = *(long *)(lVar4 + 0x3c0);
  if (*(uint *)(lVar4 + 0x42c) < 3) {
    lVar2 = *(long *)(lVar4 + 0x420);
  }
  else {
    _printk(&DAT_0010c6a9,lVar4 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_mark_stale_events");
    lVar2 = *(long *)(lVar4 + 0x420);
  }
  if ((lVar2 != 0) && (2 < *(uint *)(lVar4 + 0x428))) {
    ipc_log_string(lVar2,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),
                   "gpi_mark_stale_events");
  }
  iVar1 = readl_relaxed(*(undefined8 *)(lVar4 + 0x350));
  uVar6 = *(ulong *)(lVar5 + 0x30);
  uVar3 = *(ulong *)(lVar5 + 0x20);
  if (iVar1 != (*(int *)(lVar5 + 0x10) + (int)uVar6) - (int)uVar3) {
    do {
      if (*(uint *)(param_1 + 0x100) == (uint)*(byte *)(uVar6 + 0xf)) {
        *(undefined1 *)(uVar6 + 0xe) = 0xff;
        uVar3 = *(ulong *)(lVar5 + 0x20);
      }
      uVar6 = uVar6 + *(uint *)(lVar5 + 0x3c);
      if (uVar3 + *(uint *)(lVar5 + 0x38) <= uVar6) {
        uVar6 = uVar3;
      }
      iVar1 = readl_relaxed(*(undefined8 *)(lVar4 + 0x350));
      uVar3 = *(ulong *)(lVar5 + 0x20);
    } while (iVar1 != (*(int *)(lVar5 + 0x10) + (int)uVar6) - (int)uVar3);
  }
  return;
}



//------------------------------------------------------------
// gpi_terminate_all @ 00103c64 size=1040
// signature: undefined gpi_terminate_all(void)
// callers: []
//------------------------------------------------------------

int gpi_terminate_all(long param_1)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ulong uVar9;
  long lVar10;
  int iVar11;
  undefined4 *puVar12;
  ulong uVar13;
  
  lVar10 = *(long *)(param_1 + 0x118);
  if (*(uint *)(lVar10 + 0x42c) < 3) {
    lVar3 = *(long *)(lVar10 + 0x420);
  }
  else {
    _printk(&DAT_0010c6a9,lVar10 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_terminate_all");
    lVar3 = *(long *)(lVar10 + 0x420);
  }
  if ((lVar3 != 0) && (2 < *(uint *)(lVar10 + 0x428))) {
    ipc_log_string(lVar3,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_terminate_all");
  }
  mutex_lock();
  if (*(int *)(lVar10 + 0x324) == 2) {
    uVar8 = *(uint *)(param_1 + 0x100);
  }
  else {
    uVar8 = 0;
  }
  iVar6 = 2;
  if (*(int *)(lVar10 + 0x324) == 2) {
    iVar6 = uVar8 + 1;
  }
  if ((int)uVar8 < iVar6) {
    uVar13 = (ulong)uVar8;
    uVar7 = uVar8;
    if (uVar8 < 4) {
      uVar7 = 3;
    }
    puVar12 = (undefined4 *)(lVar10 + (ulong)uVar8 * 0x188 + 0x108);
    lVar3 = uVar7 - uVar13;
    iVar11 = iVar6 - uVar8;
    do {
      if (lVar3 == 0) goto LAB_00104070;
      _raw_write_lock_irq(lVar10 + 0x3b4);
      puVar12[9] = 4;
      _raw_write_unlock_irq(lVar10 + 0x3b4);
      iVar2 = gpi_send_cmd(lVar10,puVar12 + -0x40,2);
      if (iVar2 != 0) {
        if (*(uint *)(lVar10 + 0x42c) < 2) {
          lVar4 = *(long *)(lVar10 + 0x420);
        }
        else {
          _printk(&DAT_0010b5a2,lVar10 + 0x434,*puVar12,"gpi_terminate_all",iVar2);
          lVar4 = *(long *)(lVar10 + 0x420);
        }
        if ((lVar4 != 0) && (1 < *(uint *)(lVar10 + 0x428))) {
          ipc_log_string(lVar4,"ch:%u %s: Error Stopping Chan:%d resetting\n",*puVar12,
                         "gpi_terminate_all",iVar2);
        }
      }
      lVar3 = lVar3 + -1;
      puVar12 = puVar12 + 0x62;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    if (iVar6 <= (int)uVar8) goto LAB_00103e90;
    lVar3 = lVar10 + uVar13 * 0x188 + 8;
    uVar9 = uVar13;
    do {
      if (uVar7 == uVar9) goto LAB_00104070;
      iVar2 = gpi_reset_chan(lVar3,3);
      if (iVar2 != 0) {
        if (*(uint *)(lVar10 + 0x42c) < 2) {
          lVar3 = *(long *)(lVar10 + 0x420);
        }
        else {
          _printk(&DAT_0010ba4e,lVar10 + 0x434,
                  *(undefined4 *)(lVar10 + (uVar9 & 0xffffffff) * 0x188 + 0x108),"gpi_terminate_all"
                  ,iVar2);
          lVar3 = *(long *)(lVar10 + 0x420);
        }
        if ((lVar3 != 0) && (1 < *(uint *)(lVar10 + 0x428))) {
          ipc_log_string(lVar3,"ch:%u %s: Error resetting channel ret:%d\n",
                         *(undefined4 *)(lVar10 + (uVar9 & 0xffffffff) * 0x188 + 0x108),
                         "gpi_terminate_all",iVar2);
        }
        if (*(char *)(lVar10 + 0x5b8) == '\0') {
          gpi_dump_debug_reg(lVar10);
          *(undefined1 *)(lVar10 + 0x5b8) = 1;
        }
        goto LAB_00103e90;
      }
      iVar2 = gpi_alloc_chan(lVar3,0);
      if (iVar2 != 0) {
        uVar13 = uVar9 & 0xffffffff;
        if (*(uint *)(lVar10 + 0x42c) < 2) {
          lVar3 = *(long *)(lVar10 + 0x420);
        }
        else {
          _printk(&DAT_0010c898,lVar10 + 0x434,*(undefined4 *)(lVar10 + uVar13 * 0x188 + 0x108),
                  "gpi_terminate_all",iVar2);
          lVar3 = *(long *)(lVar10 + 0x420);
        }
        if ((lVar3 == 0) || (*(uint *)(lVar10 + 0x428) < 2)) goto LAB_00103e90;
        pcVar5 = "ch:%u %s: Error alloc_channel ret:%d\n";
        goto LAB_00103f5c;
      }
      uVar9 = uVar9 + 1;
      lVar3 = lVar3 + 0x188;
    } while (iVar6 != (int)uVar9);
    if ((int)uVar8 < iVar6) {
      uVar9 = (ulong)uVar8;
      if (uVar8 < 4) {
        uVar8 = 3;
      }
      lVar3 = lVar10 + uVar9 * 0x188 + 8;
      do {
        if (uVar8 == uVar13) {
LAB_00104070:
                    /* WARNING: Does not return */
          pcVar1 = (code *)SoftwareBreakpoint(0x5512,0x104074);
          (*pcVar1)();
        }
        iVar2 = gpi_start_chan(lVar3);
        if (iVar2 != 0) {
          uVar13 = uVar13 & 0xffffffff;
          if (*(uint *)(lVar10 + 0x42c) < 2) {
            lVar3 = *(long *)(lVar10 + 0x420);
          }
          else {
            _printk(&DAT_0010d326,lVar10 + 0x434,*(undefined4 *)(lVar10 + uVar13 * 0x188 + 0x108),
                    "gpi_terminate_all",iVar2);
            lVar3 = *(long *)(lVar10 + 0x420);
          }
          if ((lVar3 != 0) && (1 < *(uint *)(lVar10 + 0x428))) {
            pcVar5 = "ch:%u %s: Error Starting Channel ret:%d\n";
LAB_00103f5c:
            ipc_log_string(lVar3,pcVar5,*(undefined4 *)(lVar10 + uVar13 * 0x188 + 0x108),
                           "gpi_terminate_all",iVar2);
          }
          break;
        }
        uVar13 = uVar13 + 1;
        lVar3 = lVar3 + 0x188;
      } while (iVar6 != (int)uVar13);
      goto LAB_00103e90;
    }
  }
  iVar2 = 0;
LAB_00103e90:
  mutex_unlock(lVar10 + 0x378);
  return iVar2;
}



//------------------------------------------------------------
// gpi_reset_chan @ 00104074 size=748
// signature: undefined gpi_reset_chan(void)
// callers: [gpi_q2spi_terminate_all, gpi_config, gpi_pause, gpi_resume, gpi_free_chan_resources, gpi_terminate_all]
//------------------------------------------------------------

int gpi_reset_chan(long param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  long lVar3;
  undefined8 uVar4;
  long ****pppplVar5;
  long ****pppplVar6;
  long *****ppppplVar7;
  long lVar8;
  long lVar9;
  long *****local_58;
  long *****local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  local_58 = (long *****)&local_58;
  lVar8 = *(long *)(param_1 + 0x118);
  lVar9 = *(long *)(param_1 + 0x160);
  local_50 = local_58;
  if (*(uint *)(lVar8 + 0x42c) < 3) {
    lVar3 = *(long *)(lVar8 + 0x420);
  }
  else {
    _printk(&DAT_0010c6a9,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_reset_chan");
    lVar3 = *(long *)(lVar8 + 0x420);
  }
  if ((lVar3 != 0) && (2 < *(uint *)(lVar8 + 0x428))) {
    ipc_log_string(lVar3,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_reset_chan");
  }
  iVar2 = gpi_send_cmd(lVar8,param_1,param_2);
  if (iVar2 == 0) {
    *(undefined8 *)(lVar9 + 0x28) = *(undefined8 *)(lVar9 + 0x20);
    *(undefined8 *)(lVar9 + 0x30) = *(undefined8 *)(lVar9 + 0x20);
    DataMemoryBarrier(2,2);
    _raw_write_lock_irq(lVar8 + 0x3b4);
    gpi_mark_stale_events(param_1);
    uVar4 = _raw_spin_lock_irqsave(param_1 + 0xa0);
    pppplVar5 = (long ****)(param_1 + 0xa8);
    pppplVar6 = (long ****)*pppplVar5;
    if (pppplVar6 != pppplVar5) {
      ppppplVar7 = *(long ******)(param_1 + 0xb0);
      pppplVar6[1] = (long ***)local_50;
      *local_50 = pppplVar6;
      *ppppplVar7 = (long ****)&local_58;
      *(long *)(param_1 + 0xa8) = param_1 + 0xa8;
      *(long *****)(param_1 + 0xb0) = pppplVar5;
      local_50 = ppppplVar7;
    }
    pppplVar5 = (long ****)(param_1 + 0xb8);
    pppplVar6 = (long ****)*pppplVar5;
    if (pppplVar6 != pppplVar5) {
      ppppplVar7 = *(long ******)(param_1 + 0xc0);
      pppplVar6[1] = (long ***)local_50;
      *local_50 = pppplVar6;
      *ppppplVar7 = (long ****)&local_58;
      *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
      *(long *****)(param_1 + 0xc0) = pppplVar5;
      local_50 = ppppplVar7;
    }
    pppplVar5 = (long ****)(param_1 + 200);
    pppplVar6 = (long ****)*pppplVar5;
    if (pppplVar6 != pppplVar5) {
      ppppplVar7 = *(long ******)(param_1 + 0xd0);
      pppplVar6[1] = (long ***)local_50;
      *local_50 = pppplVar6;
      *ppppplVar7 = (long ****)&local_58;
      *(long *)(param_1 + 200) = param_1 + 200;
      *(long *****)(param_1 + 0xd0) = pppplVar5;
      local_50 = ppppplVar7;
    }
    pppplVar5 = (long ****)(param_1 + 0xd8);
    pppplVar6 = (long ****)*pppplVar5;
    if (pppplVar6 != pppplVar5) {
      ppppplVar7 = *(long ******)(param_1 + 0xe0);
      pppplVar6[1] = (long ***)local_50;
      *local_50 = pppplVar6;
      *ppppplVar7 = (long ****)&local_58;
      *(long *)(param_1 + 0xd8) = param_1 + 0xd8;
      *(long *****)(param_1 + 0xe0) = pppplVar5;
      local_50 = ppppplVar7;
    }
    pppplVar5 = (long ****)(param_1 + 0xe8);
    pppplVar6 = (long ****)*pppplVar5;
    if (pppplVar6 != pppplVar5) {
      ppppplVar7 = *(long ******)(param_1 + 0xf0);
      pppplVar6[1] = (long ***)local_50;
      *local_50 = pppplVar6;
      *ppppplVar7 = (long ****)&local_58;
      *(long *)(param_1 + 0xe8) = param_1 + 0xe8;
      *(long *****)(param_1 + 0xf0) = pppplVar5;
      local_50 = ppppplVar7;
    }
    _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar4);
    _raw_write_unlock_irq(lVar8 + 0x3b4);
    vchan_dma_desc_free_list(param_1,&local_58);
  }
  else {
    if (*(uint *)(lVar8 + 0x42c) < 2) {
      lVar9 = *(long *)(lVar8 + 0x420);
    }
    else {
      if (0xc < param_2) goto LAB_0010435c;
      _printk(&DAT_0010d251,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_reset_chan",
              (&gpi_cmd_str)[param_2],iVar2);
      lVar9 = *(long *)(lVar8 + 0x420);
    }
    if ((lVar9 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
      if (0xc < param_2) {
LAB_0010435c:
                    /* WARNING: Does not return */
        pcVar1 = (code *)SoftwareBreakpoint(1,0x104360);
        (*pcVar1)();
      }
      ipc_log_string(lVar9,"ch:%u %s: Error with cmd:%s ret:%d\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_reset_chan",(&gpi_cmd_str)[param_2],iVar2);
    }
  }
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}



//------------------------------------------------------------
// gpi_alloc_chan @ 00104360 size=624
// signature: undefined gpi_alloc_chan(void)
// callers: [gpi_q2spi_terminate_all, gpi_config, gpi_resume, gpi_terminate_all]
//------------------------------------------------------------

int gpi_alloc_chan(long param_1,ulong param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  int iVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  int *piVar16;
  
  lVar14 = *(long *)(param_1 + 0x160);
  piVar16 = *(int **)(param_1 + 0x118);
  iVar6 = *(int *)(param_1 + 0x100);
  uVar1 = *(undefined4 *)(lVar14 + 0x10);
  uVar3 = *(undefined4 *)(lVar14 + 0x14);
  uVar2 = *(undefined4 *)(lVar14 + 0x38);
  iVar4 = *(int *)(lVar14 + 0x3c);
  lVar15 = *(long *)(piVar16 + 0xcc);
  lVar14 = *(long *)(param_1 + 0x128);
  lVar5 = *(long *)(param_1 + 0x130);
  iVar7 = *piVar16;
  bVar11 = *(byte *)(param_1 + 0x108);
  iVar8 = *(int *)(param_1 + 0x15c);
  iVar9 = *(int *)(param_1 + 0x10c);
  uVar10 = *(uint *)(param_1 + 0x104);
  if ((uint)piVar16[0x10b] < 3) {
    lVar13 = *(long *)(piVar16 + 0x108);
  }
  else {
    _printk(&DAT_0010c6a9,piVar16 + 0x10d,iVar6,"gpi_alloc_chan");
    lVar13 = *(long *)(piVar16 + 0x108);
  }
  if ((lVar13 != 0) && (2 < (uint)piVar16[0x10a])) {
    ipc_log_string(lVar13,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_alloc_chan");
  }
  if (((param_2 & 1) == 0) || (iVar12 = gpi_send_cmd(piVar16,param_1,0), iVar12 == 0)) {
    if (lVar14 != 0) {
      writel_relaxed(iVar4 << 0x18 | iVar8 << 3 | 2,lVar14);
      writel_relaxed(uVar2,lVar14 + 4);
      writel_relaxed(uVar1,lVar14 + 8);
      writel_relaxed(uVar3,lVar14 + 0xc);
      if ((lVar5 != 0) && (writel_relaxed(uVar3,lVar5 + 4), lVar15 != 0)) {
        iVar4 = iVar6 * 0x80 + iVar7 * 0x4000;
        writel_relaxed(uVar10 | iVar9 << 4 | (uint)(iVar6 == 0) << 0x10 | (bVar11 & 1) << 0xf,
                       lVar15 + (iVar4 + 0x20060));
        writel_relaxed(0,lVar15 + (iVar4 + 0x20064));
        writel_relaxed(0,lVar15 + (iVar4 + 0x20068));
        writel_relaxed(0,lVar15 + (iVar4 + 0x2006c));
        writel_relaxed(1,lVar15 + (iVar4 + 0x2005c));
      }
    }
    DataSynchronizationBarrier(3,2,0);
    iVar12 = 0;
  }
  else {
    if ((uint)piVar16[0x10b] < 2) {
      lVar14 = *(long *)(piVar16 + 0x108);
    }
    else {
      _printk(&DAT_0010d251,piVar16 + 0x10d,*(undefined4 *)(param_1 + 0x100),"gpi_alloc_chan",
              "CH ALLOCATE",iVar12);
      lVar14 = *(long *)(piVar16 + 0x108);
    }
    if ((lVar14 != 0) && (1 < (uint)piVar16[0x10a])) {
      ipc_log_string(lVar14,"ch:%u %s: Error with cmd:%s ret:%d\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_alloc_chan","CH ALLOCATE",iVar12);
    }
  }
  return iVar12;
}



//------------------------------------------------------------
// gpi_q2spi_terminate_all @ 001045d4 size=1052
// signature: undefined gpi_q2spi_terminate_all(void)
// callers: []
//------------------------------------------------------------

int gpi_q2spi_terminate_all(long param_1)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  long lVar9;
  undefined4 *puVar10;
  ulong uVar11;
  int iVar12;
  uint uVar13;
  
  lVar9 = *(long *)(param_1 + 0x118);
  if (*(uint *)(lVar9 + 0x42c) < 3) {
    lVar4 = *(long *)(lVar9 + 0x420);
  }
  else {
    _printk(&DAT_0010c6a9,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_q2spi_terminate_all");
    lVar4 = *(long *)(lVar9 + 0x420);
  }
  if ((lVar4 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
    ipc_log_string(lVar4,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),
                   "gpi_q2spi_terminate_all");
  }
  mutex_lock();
  if (*(int *)(lVar9 + 0x324) == 2) {
    uVar13 = *(uint *)(param_1 + 0x100);
  }
  else {
    uVar13 = 0;
  }
  uVar7 = 2;
  if (*(int *)(lVar9 + 0x324) == 2) {
    uVar7 = uVar13 + 1;
  }
  if ((int)uVar13 < (int)uVar7) {
    uVar11 = (ulong)uVar13;
    bVar1 = 0;
    uVar8 = uVar13;
    if (uVar13 < 4) {
      uVar8 = 3;
    }
    lVar4 = uVar8 - uVar11;
    puVar10 = (undefined4 *)(lVar9 + (ulong)uVar13 * 0x188 + 0x108);
    iVar12 = uVar7 - uVar13;
    do {
      if (lVar4 == 0) goto LAB_001049ec;
      _raw_write_lock_irq(lVar9 + 0x3b4);
      puVar10[9] = 4;
      _raw_write_unlock_irq(lVar9 + 0x3b4);
      iVar3 = gpi_send_cmd(lVar9,puVar10 + -0x40,2);
      if (iVar3 != 0) {
        if (*(uint *)(lVar9 + 0x42c) < 2) {
          lVar5 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010b5a2,lVar9 + 0x434,*puVar10,"gpi_q2spi_terminate_all",iVar3);
          lVar5 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar5 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
          ipc_log_string(lVar5,"ch:%u %s: Error Stopping Chan:%d resetting\n",*puVar10,
                         "gpi_q2spi_terminate_all",iVar3);
        }
        bVar1 = 1;
      }
      lVar4 = lVar4 + -1;
      puVar10 = puVar10 + 0x62;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    if ((bool)((int)uVar7 <= (int)uVar13 | bVar1 ^ 1)) goto LAB_001047d0;
    uVar8 = uVar13;
    if (uVar13 < 4) {
      uVar8 = 3;
    }
    lVar4 = lVar9 + (ulong)uVar13 * 0x188 + 8;
    do {
      if (uVar8 == uVar11) goto LAB_001049ec;
      iVar3 = gpi_reset_chan(lVar4,3);
      if (iVar3 != 0) {
        if (*(uint *)(lVar9 + 0x42c) < 2) {
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010ba4e,lVar9 + 0x434,
                  *(undefined4 *)(lVar9 + (uVar11 & 0xffffffff) * 0x188 + 0x108),
                  "gpi_q2spi_terminate_all",iVar3);
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar4 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
          ipc_log_string(lVar4,"ch:%u %s: Error resetting channel ret:%d\n",
                         *(undefined4 *)(lVar9 + (uVar11 & 0xffffffff) * 0x188 + 0x108),
                         "gpi_q2spi_terminate_all",iVar3);
        }
        if (*(char *)(lVar9 + 0x5b8) == '\0') {
          gpi_dump_debug_reg(lVar9);
          *(undefined1 *)(lVar9 + 0x5b8) = 1;
        }
        goto LAB_001048f8;
      }
      iVar3 = gpi_alloc_chan(lVar4,0);
      if (iVar3 != 0) {
        uVar11 = uVar11 & 0xffffffff;
        if (*(uint *)(lVar9 + 0x42c) < 2) {
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010c898,lVar9 + 0x434,*(undefined4 *)(lVar9 + uVar11 * 0x188 + 0x108),
                  "gpi_q2spi_terminate_all",iVar3);
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar4 == 0) || (*(uint *)(lVar9 + 0x428) < 2)) goto LAB_001048f8;
        pcVar6 = "ch:%u %s: Error alloc_channel ret:%d\n";
        goto LAB_001048e0;
      }
      uVar11 = uVar11 + 1;
      lVar4 = lVar4 + 0x188;
    } while (uVar7 != (uint)uVar11);
  }
  iVar3 = 0;
LAB_001047d0:
  if ((int)uVar13 <= (int)(uVar7 - 1)) {
    uVar11 = (ulong)uVar7;
    do {
      uVar7 = (int)uVar11 - 1;
      uVar11 = (ulong)uVar7;
      if (2 < uVar7) {
LAB_001049ec:
                    /* WARNING: Does not return */
        pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x1049f0);
        (*pcVar2)();
      }
      iVar3 = gpi_start_chan(lVar9 + uVar11 * 0x188 + 8);
      if (iVar3 != 0) {
        if (*(uint *)(lVar9 + 0x42c) < 2) {
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010d326,lVar9 + 0x434,*(undefined4 *)(lVar9 + (ulong)uVar7 * 0x188 + 0x108),
                  "gpi_q2spi_terminate_all",iVar3);
          lVar4 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar4 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
          pcVar6 = "ch:%u %s: Error Starting Channel ret:%d\n";
LAB_001048e0:
          ipc_log_string(lVar4,pcVar6,*(undefined4 *)(lVar9 + uVar11 * 0x188 + 0x108),
                         "gpi_q2spi_terminate_all",iVar3);
        }
        goto LAB_001048f8;
      }
    } while ((int)uVar13 < (int)uVar7);
    iVar3 = 0;
  }
LAB_001048f8:
  mutex_unlock(lVar9 + 0x378);
  return iVar3;
}



//------------------------------------------------------------
// gpi_desc_free @ 001049f4 size=28
// signature: undefined gpi_desc_free(void)
// callers: []
//------------------------------------------------------------

void gpi_desc_free(void)

{
  kfree();
  return;
}



//------------------------------------------------------------
// gpi_prep_slave_sg @ 00104a14 size=1288
// signature: undefined gpi_prep_slave_sg(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long gpi_prep_slave_sg(long param_1,ulong *param_2,int param_3,int param_4,undefined4 param_5)

{
  ulong uVar1;
  ulong uVar2;
  undefined8 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  ulong *puVar8;
  long lVar9;
  char *pcVar10;
  undefined8 uVar11;
  long lVar12;
  ulong uVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  long *plVar19;
  undefined8 *puVar20;
  long lVar21;
  long lVar22;
  
  lVar22 = *(long *)(param_1 + 0x118);
  lVar21 = *(long *)(param_1 + 0x160);
  *(int *)(param_1 + 0x184) = param_3;
  if (2 < param_4 - 1U) {
    if (*(uint *)(lVar22 + 0x42c) < 2) {
      lVar21 = *(long *)(lVar22 + 0x420);
    }
    else {
      _printk(&DAT_0010d38d,lVar22 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_prep_slave_sg",
              param_4);
      lVar21 = *(long *)(lVar22 + 0x420);
    }
    if (lVar21 == 0) {
      return 0;
    }
    if (*(uint *)(lVar22 + 0x428) < 2) {
      return 0;
    }
    ipc_log_string(lVar21,"ch:%u %s: invalid dma direction: %d\n",*(undefined4 *)(param_1 + 0x100),
                   "gpi_prep_slave_sg",param_4);
    return 0;
  }
  uVar13 = *(ulong *)(lVar21 + 0x28);
  uVar2 = *(ulong *)(lVar21 + 0x30);
  if (uVar13 < uVar2) {
    iVar18 = 0;
    if ((ulong)*(uint *)(lVar21 + 0x3c) != 0) {
      iVar18 = (int)((long)(uVar2 - uVar13) / (long)(ulong)*(uint *)(lVar21 + 0x3c));
    }
    uVar16 = iVar18 - 1;
  }
  else {
    uVar1 = (ulong)*(uint *)(lVar21 + 0x3c);
    iVar18 = 0;
    if (uVar1 != 0) {
      iVar18 = (int)((long)(uVar2 - *(long *)(lVar21 + 0x20)) / (long)uVar1);
    }
    iVar5 = 0;
    if (uVar1 != 0) {
      iVar5 = (int)((long)((*(long *)(lVar21 + 0x20) + (ulong)*(uint *)(lVar21 + 0x38)) - uVar13) /
                   (long)uVar1);
    }
    uVar16 = iVar18 + -1 + iVar5;
  }
  if (param_3 == 0) {
    lVar9 = kmalloc_trace(__printk,0xb20,0xc0);
    if (lVar9 != 0) {
      puVar14 = (undefined8 *)0x0;
      goto LAB_00104e00;
    }
  }
  else {
    uVar17 = 0;
    puVar8 = param_2;
    iVar18 = param_3;
    do {
      uVar7 = 0;
      if (*(uint *)(lVar21 + 0x3c) != 0) {
        uVar7 = *(uint *)((long)puVar8 + 0xc) / *(uint *)(lVar21 + 0x3c);
      }
      uVar17 = uVar7 + uVar17;
      puVar8 = (ulong *)sg_next();
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    if (uVar16 < uVar17) {
      if (*(uint *)(lVar22 + 0x42c) < 2) {
        lVar21 = *(long *)(lVar22 + 0x420);
      }
      else {
        _printk(&DAT_0010cab3,lVar22 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_prep_slave_sg",
                uVar16,uVar17);
        lVar21 = *(long *)(lVar22 + 0x420);
      }
      if (lVar21 == 0) {
        return 0;
      }
      if (*(uint *)(lVar22 + 0x428) < 2) {
        return 0;
      }
      ipc_log_string(lVar21,"ch:%u %s: not enough space in ring, avail:%u required:%u\n",
                     *(undefined4 *)(param_1 + 0x100),"gpi_prep_slave_sg",uVar16,uVar17);
      return 0;
    }
    lVar9 = kmalloc_trace(__printk,0xb20,0xc0);
    if (lVar9 != 0) {
      if (param_3 == 0) {
        puVar14 = (undefined8 *)0x0;
      }
      else {
        iVar18 = 0;
        puVar14 = (undefined8 *)0x0;
        do {
          puVar20 = (undefined8 *)
                    (((*param_2 & 0x3ffffffffffc0) << 6 | 0xff00000000000000) +
                    (ulong)(uint)param_2[1]);
          if (puVar20 == (undefined8 *)0x0) {
            kfree(lVar9);
            if (*(uint *)(lVar22 + 0x42c) < 2) {
              lVar21 = *(long *)(lVar22 + 0x420);
            }
            else {
              _printk(&DAT_0010bead,lVar22 + 0x434,*(undefined4 *)(param_1 + 0x100),
                      "gpi_prep_slave_sg");
              lVar21 = *(long *)(lVar22 + 0x420);
            }
            if (lVar21 == 0) {
              return 0;
            }
            if (*(uint *)(lVar22 + 0x428) < 2) {
              return 0;
            }
            uVar4 = *(undefined4 *)(param_1 + 0x100);
            pcVar10 = "ch:%u %s: TRE address is null\n";
            goto LAB_00104d84;
          }
          if (param_3 == 1) {
            *(uint *)(param_1 + 0x180) = (uint)(*(char *)((long)puVar20 + 0xe) == '0');
          }
          if (iVar18 == param_3 + -1) {
            *(bool *)(lVar22 + 0x5c0) = *(char *)((long)puVar20 + 0xe) == '1';
          }
          if (*(int *)((long)param_2 + 0xc) != 0) {
            uVar16 = 0;
            puVar15 = puVar14;
            do {
              lVar12 = *(long *)(param_1 + 0x160);
              puVar14 = *(undefined8 **)(lVar12 + 0x28);
              puVar3 = *(undefined8 **)(lVar12 + 0x30);
              if (puVar14 < puVar3) {
                uVar13 = (ulong)*(uint *)(lVar12 + 0x3c);
                iVar5 = 0;
                if (uVar13 != 0) {
                  iVar5 = (int)(((long)puVar3 - (long)puVar14) / (long)uVar13);
                }
                if (iVar5 + -1 < 1) goto LAB_00104cfc;
LAB_00104c90:
                uVar2 = (long)puVar14 + uVar13;
                if (*(ulong *)(lVar12 + 0x20) + (ulong)*(uint *)(lVar12 + 0x38) <=
                    (long)puVar14 + uVar13) {
                  uVar2 = *(ulong *)(lVar12 + 0x20);
                }
                *(ulong *)(lVar12 + 0x28) = uVar2;
                DataMemoryBarrier(2,2);
                uVar11 = puVar20[1];
                *puVar14 = *puVar20;
                puVar14[1] = uVar11;
              }
              else {
                uVar13 = (ulong)*(uint *)(lVar12 + 0x3c);
                iVar5 = 0;
                if (uVar13 != 0) {
                  iVar5 = (int)(((long)puVar3 - *(long *)(lVar12 + 0x20)) / (long)uVar13);
                }
                iVar6 = 0;
                if (uVar13 != 0) {
                  iVar6 = (int)((long)((*(long *)(lVar12 + 0x20) + (ulong)*(uint *)(lVar12 + 0x38))
                                      - (long)puVar14) / (long)uVar13);
                }
                if (0 < iVar5 + -1 + iVar6) goto LAB_00104c90;
LAB_00104cfc:
                if (*(int *)(lVar22 + 0x42c) == 0) {
                  lVar12 = *(long *)(lVar22 + 0x420);
                }
                else {
                  _printk(&DAT_0010ceb5,lVar22 + 0x434,*(undefined4 *)(param_1 + 0x100),
                          "gpi_queue_xfer");
                  lVar12 = *(long *)(lVar22 + 0x420);
                }
                puVar14 = puVar15;
                if ((lVar12 != 0) && (*(int *)(lVar22 + 0x428) != 0)) {
                  ipc_log_string(lVar12,"ch:%u %s: Error adding ring element to xfer ring\n",
                                 *(undefined4 *)(param_1 + 0x100),"gpi_queue_xfer");
                }
              }
              uVar16 = *(uint *)(lVar21 + 0x3c) + uVar16;
              puVar20 = (undefined8 *)((long)puVar20 + (ulong)*(uint *)(lVar21 + 0x3c));
              puVar15 = puVar14;
            } while (uVar16 < *(uint *)((long)param_2 + 0xc));
          }
          iVar18 = iVar18 + 1;
          param_2 = (ulong *)sg_next(param_2);
        } while (iVar18 != param_3);
      }
LAB_00104e00:
      uVar11 = *(undefined8 *)(lVar21 + 0x28);
      *(long *)(lVar9 + 0xb8) = param_1;
      *(undefined8 **)(lVar9 + 0xa8) = puVar14;
      *(undefined8 *)(lVar9 + 0xb0) = uVar11;
      dma_async_tx_descriptor_init(lVar9,param_1);
      *(undefined4 *)(lVar9 + 4) = param_5;
      *(undefined8 *)(lVar9 + 0x90) = 0;
      *(undefined **)(lVar9 + 0x18) = &vchan_tx_submit;
      *(undefined **)(lVar9 + 0x20) = &vchan_tx_desc_free;
      uVar11 = _raw_spin_lock_irqsave(param_1 + 0xa0);
      plVar19 = *(long **)(param_1 + 0xb0);
      lVar21 = lVar9 + 0x98;
      uVar13 = __list_add_valid(lVar21,plVar19,param_1 + 0xa8);
      if ((uVar13 & 1) != 0) {
        *(long *)(param_1 + 0xb0) = lVar21;
        *(long *)(lVar9 + 0x98) = param_1 + 0xa8;
        *(long **)(lVar9 + 0xa0) = plVar19;
        *plVar19 = lVar21;
      }
      _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar11);
      return lVar9;
    }
  }
  if (*(uint *)(lVar22 + 0x42c) < 2) {
    lVar21 = *(long *)(lVar22 + 0x420);
  }
  else {
    _printk(&DAT_0010ce70,lVar22 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_prep_slave_sg");
    lVar21 = *(long *)(lVar22 + 0x420);
  }
  if ((lVar21 != 0) && (1 < *(uint *)(lVar22 + 0x428))) {
    uVar4 = *(undefined4 *)(param_1 + 0x100);
    pcVar10 = "ch:%u %s: out of memory for descriptor\n";
LAB_00104d84:
    ipc_log_string(lVar21,pcVar10,uVar4,"gpi_prep_slave_sg");
  }
  return 0;
}



//------------------------------------------------------------
// readl_relaxed @ 00104f2c size=124
// signature: undefined readl_relaxed(void)
// callers: [gpi_dump_debug_reg, gpi_config_interrupts, gpi_pause, gpi_disable_interrupts, gpi_mark_stale_events, gpi_handle_irq, gpi_send_cmd, gpi_process_events]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x104f74,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// writel_relaxed @ 00104fa8 size=132
// signature: undefined writel_relaxed(void)
// callers: [gpi_config_interrupts, gpi_alloc_ev_chan, gpi_issue_pending, gpi_disable_interrupts, gpi_alloc_chan, gpi_handle_irq, gpi_send_cmd, gpi_process_events]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x104fc0,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x104ffc,uVar1);
  return;
}



//------------------------------------------------------------
// gpi_probe @ 00105030 size=2632
// signature: undefined gpi_probe(void)
// callers: []
//------------------------------------------------------------

int gpi_probe(long param_1)

{
  ulong *puVar1;
  uint uVar2;
  char cVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  long lVar7;
  long *plVar8;
  long lVar9;
  char *pcVar10;
  ulong uVar11;
  undefined8 uVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  uint uVar16;
  int iVar17;
  uint *puVar18;
  uint local_6c;
  long local_68;
  
  lVar7 = sp_el0;
  local_68 = *(long *)(lVar7 + 0x638);
  local_6c = 0;
  lVar7 = devm_kmalloc(param_1 + 0x10,0x220,0xdc0);
  if (lVar7 == 0) {
LAB_0010592c:
    iVar6 = -0xc;
  }
  else {
    uVar11 = (ulong)arr_idx;
    if (4 < arr_idx) {
                    /* WARNING: Does not return */
      pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x105a68);
      arr_idx = arr_idx + 1;
      (*pcVar5)();
    }
    arr_idx = arr_idx + 1;
    *(long *)(lVar7 + 0x180) = param_1 + 0x10;
    *(long *)(gpi_dev_dbg + uVar11 * 8) = lVar7;
    *(undefined4 *)(lVar7 + 0x1dc) = 1;
    plVar8 = (long *)platform_get_resource_byname(param_1,0x200,"gpi-top");
    *(long **)(lVar7 + 0x188) = plVar8;
    if (plVar8 == (long *)0x0) {
      if (*(uint *)(lVar7 + 0x1dc) < 2) {
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      else {
        _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: missing \'reg\' DT node\n","gpi_probe");
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) {
        iVar6 = -0x16;
      }
      else {
        ipc_log_string(lVar9,"%s: missing \'reg\' DT node\n","gpi_probe");
        iVar6 = -0x16;
      }
      goto LAB_00105930;
    }
    lVar9 = devm_ioremap(*(undefined8 *)(lVar7 + 0x180),*plVar8,(plVar8[1] - *plVar8) + 1);
    *(long *)(lVar7 + 400) = lVar9;
    if (lVar9 == 0) {
      if (*(uint *)(lVar7 + 0x1dc) < 2) {
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      else {
        _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: IO remap failed\n","gpi_probe");
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) {
        iVar6 = -0xe;
      }
      else {
        ipc_log_string(lVar9,"%s: IO remap failed\n","gpi_probe");
        iVar6 = -0xe;
      }
      goto LAB_00105930;
    }
    *(long *)(lVar7 + 0x198) = lVar9;
    iVar6 = of_property_read_variable_u32_array
                      (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),"qcom,max-num-gpii",
                       (uint *)(lVar7 + 0x1a0),1,0);
    if (iVar6 < 0) {
      if (*(uint *)(lVar7 + 0x1dc) < 2) {
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      else {
        _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: missing \'max-no-gpii\' DT node\n","gpi_probe")
        ;
        lVar9 = *(long *)(lVar7 + 0x1d0);
      }
      if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
      pcVar10 = "%s: missing \'max-no-gpii\' DT node\n";
    }
    else {
      iVar6 = of_property_read_variable_u32_array
                        (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),"qcom,gpii-mask",
                         (uint *)(lVar7 + 0x1a4),1,0);
      if (iVar6 < 0) {
        if (*(uint *)(lVar7 + 0x1dc) < 2) {
          lVar9 = *(long *)(lVar7 + 0x1d0);
        }
        else {
          _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: missing \'gpii-mask\' DT node\n","gpi_probe")
          ;
          lVar9 = *(long *)(lVar7 + 0x1d0);
        }
        if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
        pcVar10 = "%s: missing \'gpii-mask\' DT node\n";
      }
      else {
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),"qcom,static-gpii-mask"
                           ,(uint *)(lVar7 + 0x1a8),1,0);
        if (((-1 < iVar6) && (*(long *)(lVar7 + 0x1d0) != 0)) && (*(int *)(lVar7 + 0x1d8) != 0)) {
          ipc_log_string(*(long *)(lVar7 + 0x1d0),"%s: static GPII usecase\n","gpi_probe");
        }
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),"qcom,gpi-ee-offset",
                           &local_6c,1,0);
        if (iVar6 < 0) {
          if ((*(long *)(lVar7 + 0x1d0) != 0) && (*(int *)(lVar7 + 0x1d8) != 0)) {
            ipc_log_string(*(long *)(lVar7 + 0x1d0),"%s: No variable ee offset present\n",
                           "gpi_probe");
          }
        }
        else {
          *(ulong *)(lVar7 + 0x198) = *(long *)(lVar7 + 0x198) - (ulong)local_6c;
        }
        iVar6 = of_property_read_variable_u32_array
                          (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),"qcom,ev-factor",
                           lVar7 + 0x1ac,1,0);
        if (-1 < iVar6) {
          iVar6 = dma_set_mask(*(undefined8 *)(lVar7 + 0x180),0xffffffffffffffff);
          if (iVar6 == 0) {
            lVar9 = devm_kmalloc(*(undefined8 *)(lVar7 + 0x180),
                                 (ulong)*(uint *)(lVar7 + 0x1a0) * 0x5c8,0xdc0);
            *(long *)(lVar7 + 0x1c8) = lVar9;
            if (lVar9 == 0) goto LAB_0010592c;
            __mutex_init(lVar7 + 0x1f0,"&gpi_dev->qup_se_lock",&gpi_probe___key);
            lVar9 = of_find_property(*(undefined8 *)(param_1 + 0x2f8),"qcom,le-vm",0);
            *(bool *)(lVar7 + 0x1e8) = lVar9 != 0;
            if (((lVar9 != 0) && (*(long *)(lVar7 + 0x1d0) != 0)) && (*(int *)(lVar7 + 0x1d8) != 0))
            {
              ipc_log_string(*(long *)(lVar7 + 0x1d0),"%s: LE-VM usecase\n","gpi_probe");
            }
            *(long *)(lVar7 + 0x10) = lVar7 + 0x10;
            *(long *)(lVar7 + 0x18) = lVar7 + 0x10;
            if (*(int *)(lVar7 + 0x1a0) != 0) {
              iVar17 = 0;
              uVar16 = 0;
              do {
                lVar15 = *(long *)(lVar7 + 0x1c8);
                puVar18 = (uint *)(lVar15 + (long)(int)uVar16 * 0x5c8);
                *(undefined1 *)((long)puVar18 + 0x5c2) = 1;
                lVar9 = dmam_alloc_attrs(*(undefined8 *)(lVar7 + 0x180),0x48,puVar18 + 0x5c,0xcc0,0)
                ;
                *(long *)(puVar18 + 0x5a) = lVar9;
                if (lVar9 == 0) {
                  lVar9 = *(long *)(lVar7 + 0x1d0);
                  if ((lVar9 != 0) && (*(int *)(lVar7 + 0x1d8) != 0)) {
                    pcVar10 = "%s: could not allocate for gpii->gpii_chan[0].ch_ring\n";
LAB_00105920:
                    ipc_log_string(lVar9,pcVar10,"gpi_probe");
                  }
                  goto LAB_0010592c;
                }
                lVar14 = lVar15 + (long)(int)uVar16 * 0x5c8;
                lVar9 = dmam_alloc_attrs(*(undefined8 *)(lVar7 + 0x180),0x48,lVar14 + 0x2f8,0xcc0,0)
                ;
                *(long *)(lVar14 + 0x2f0) = lVar9;
                if (lVar9 == 0) {
                  lVar9 = *(long *)(lVar7 + 0x1d0);
                  if ((lVar9 != 0) && (*(int *)(lVar7 + 0x1d8) != 0)) {
                    pcVar10 = "%s: could not allocate for gpii->gpii_chan[1].ch_ring\n";
                    goto LAB_00105920;
                  }
                  goto LAB_0010592c;
                }
                lVar14 = lVar15 + (long)(int)uVar16 * 0x5c8;
                lVar9 = dmam_alloc_attrs(*(undefined8 *)(lVar7 + 0x180),0x48,lVar14 + 0x3c8,0xcc0,0)
                ;
                *(long *)(lVar14 + 0x3c0) = lVar9;
                if (lVar9 == 0) {
                  lVar9 = *(long *)(lVar7 + 0x1d0);
                  if ((lVar9 != 0) && (*(int *)(lVar7 + 0x1d8) != 0)) {
                    pcVar10 = "%s: could not allocate for gpii->ev_ring\n";
                    goto LAB_00105920;
                  }
                  goto LAB_0010592c;
                }
                uVar2 = 1 << (ulong)(uVar16 & 0x1f);
                if (((*(uint *)(lVar7 + 0x1a4) & uVar2) != 0) ||
                   ((*(uint *)(lVar7 + 0x1a8) & uVar2) != 0)) {
                  lVar13 = lVar15 + (long)(int)uVar16 * 0x5c8;
                  lVar9 = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x21000);
                  *(long *)(lVar13 + 0x338) = lVar9;
                  lVar14 = *(long *)(lVar7 + 0x198);
                  *(long *)(lVar13 + 0x348) = lVar9 + 8;
                  *(long *)(lVar13 + 0x350) = lVar9 + 0x10;
                  *(long *)(lVar13 + 0x358) = lVar9 + 0x18;
                  *(long *)(lVar13 + 0x340) = lVar14 + (iVar17 + 0x22100);
                  *(long *)(lVar13 + 0x360) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x23010);
                  *(long *)(lVar13 + 0x368) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x230b0);
                  *(long *)(lVar13 + 0x370) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x230c0);
                  iVar6 = platform_get_irq(param_1,uVar16);
                  if (iVar6 < 0) {
                    if (*(uint *)(lVar7 + 0x1dc) < 2) {
                      lVar9 = *(long *)(lVar7 + 0x1d0);
                    }
                    else {
                      _dev_err(*(undefined8 *)(lVar7 + 0x180),
                               "%s: could not req. irq for gpii%d ret:%d","gpi_probe",uVar16,iVar6);
                      lVar9 = *(long *)(lVar7 + 0x1d0);
                    }
                    if ((lVar9 != 0) && (1 < *(uint *)(lVar7 + 0x1d8))) {
                      ipc_log_string(lVar9,"%s: could not req. irq for gpii%d ret:%d","gpi_probe",
                                     uVar16,iVar6);
                    }
                    goto LAB_00105930;
                  }
                  lVar15 = lVar15 + (long)(int)uVar16 * 0x5c8;
                  *(int *)(lVar15 + 0x328) = iVar6;
                  lVar9 = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x20000);
                  *(long *)(lVar15 + 0x130) = lVar9;
                  *(long *)(lVar15 + 0x138) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x22000);
                  *(long *)(lVar15 + 0x140) = lVar9 + 8;
                  *(long *)(lVar15 + 0x148) = lVar9 + 0x10;
                  *(long *)(lVar15 + 0x150) = lVar9 + 0x18;
                  *(long *)(lVar15 + 0x158) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x23008);
                  vchan_init(puVar18 + 2,lVar7);
                  *(undefined4 *)(lVar15 + 0x108) = 0;
                  *(uint **)(lVar15 + 0x120) = puVar18;
                  *(code **)(puVar18 + 0x28) = gpi_desc_free;
                  *(undefined4 *)(lVar15 + 0x164) = 1;
                  lVar9 = *(long *)(lVar7 + 0x198) + ((long)(iVar17 + 0x20000) | 0x80U);
                  *(long *)(lVar15 + 0x2b8) = lVar9;
                  lVar14 = *(long *)(lVar7 + 0x198);
                  *(long *)(lVar15 + 0x2c8) = lVar9 + 8;
                  *(long *)(lVar15 + 0x2d0) = lVar9 + 0x10;
                  *(long *)(lVar15 + 0x2d8) = lVar9 + 0x18;
                  *(ulong *)(lVar15 + 0x2c0) = lVar14 + ((long)(iVar17 + 0x22000) | 8U);
                  *(long *)(lVar15 + 0x2e0) = *(long *)(lVar7 + 0x198) + (long)(iVar17 + 0x23008);
                  vchan_init(lVar15 + 400,lVar7);
                  *(code **)(lVar15 + 0x228) = gpi_desc_free;
                  *(undefined4 *)(lVar15 + 0x290) = 1;
                  *(uint **)(lVar15 + 0x2a8) = puVar18;
                  *(undefined4 *)(lVar15 + 0x2ec) = 0;
                  __mutex_init(lVar15 + 0x378,"&gpii->ctrl_lock",&gpi_probe___key_233);
                  *(undefined8 *)(lVar15 + 0x3b4) = 0;
                  tasklet_init(lVar15 + 0x3d0,gpi_ev_tasklet,puVar18);
                  *(undefined4 *)(lVar15 + 0x3f8) = 0;
                  __init_swait_queue_head(lVar15 + 0x400,"&x->wait",&init_completion___key);
                  *puVar18 = uVar16;
                  uVar12 = *(undefined8 *)(lVar7 + 0x198);
                  *(long *)(lVar15 + 0x318) = lVar7;
                  *(undefined8 *)(lVar15 + 0x330) = uVar12;
                  *(undefined4 *)(lVar15 + 0x430) = 0;
                }
                uVar16 = uVar16 + 1;
                iVar17 = iVar17 + 0x4000;
              } while (uVar16 < *(uint *)(lVar7 + 0x1a0));
            }
            *(long *)(param_1 + 0xa8) = lVar7;
            *(undefined8 *)(lVar7 + 0x48) = 0;
            puVar1 = (ulong *)(lVar7 + 0x48);
            Hint_Prefetch(puVar1,2,0,1);
            do {
              cVar3 = '\x01';
              bVar4 = (bool)ExclusiveMonitorPass(puVar1,0x10);
              if (bVar4) {
                *puVar1 = *puVar1 | 0x400;
                cVar3 = ExclusiveMonitorsStatus();
              }
            } while (cVar3 != '\0');
            *(undefined4 *)(lVar7 + 0xac) = 0;
            *(undefined4 *)(lVar7 + 0x98) = 6;
            *(undefined8 *)(lVar7 + 0x90) = 0x800000008;
            *(code **)(lVar7 + 0xb0) = gpi_alloc_chan_resources;
            *(code **)(lVar7 + 0xc0) = gpi_free_chan_resources;
            *(code **)(lVar7 + 0x158) = dma_cookie_status;
            *(code **)(lVar7 + 0x160) = gpi_issue_pending;
            *(code **)(lVar7 + 0x108) = gpi_prep_slave_sg;
            *(undefined8 *)(lVar7 + 0x70) = *(undefined8 *)(lVar7 + 0x180);
            *(code **)(lVar7 + 0x130) = gpi_config;
            *(code **)(lVar7 + 0x138) = gpi_pause;
            *(code **)(lVar7 + 0x140) = gpi_resume;
            *(code **)(lVar7 + 0x148) = gpi_terminate_all;
            iVar6 = dma_async_device_register(lVar7);
            if (iVar6 == 0) {
              iVar6 = of_dma_controller_register
                                (*(undefined8 *)(*(long *)(lVar7 + 0x180) + 0x2e8),gpi_of_dma_xlate,
                                 lVar7);
              if (iVar6 == 0) {
                gpi_setup_debug(lVar7);
                if ((*(long *)(lVar7 + 0x1d0) != 0) && (*(int *)(lVar7 + 0x1d8) != 0)) {
                  ipc_log_string(*(long *)(lVar7 + 0x1d0),"%s: %s: probe success\n","gpi_probe",
                                 "gpi_probe");
                }
                iVar6 = 0;
                goto LAB_00105930;
              }
              if (*(uint *)(lVar7 + 0x1dc) < 2) {
                lVar9 = *(long *)(lVar7 + 0x1d0);
              }
              else {
                _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: of_dma_controller_reg failed ret:%d",
                         "gpi_probe",iVar6);
                lVar9 = *(long *)(lVar7 + 0x1d0);
              }
              if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
              pcVar10 = "%s: of_dma_controller_reg failed ret:%d";
            }
            else {
              if (*(uint *)(lVar7 + 0x1dc) < 2) {
                lVar9 = *(long *)(lVar7 + 0x1d0);
              }
              else {
                _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: async_device_register failed ret:%d",
                         "gpi_probe",iVar6);
                lVar9 = *(long *)(lVar7 + 0x1d0);
              }
              if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
              pcVar10 = "%s: async_device_register failed ret:%d";
            }
          }
          else {
            if (*(uint *)(lVar7 + 0x1dc) < 2) {
              lVar9 = *(long *)(lVar7 + 0x1d0);
            }
            else {
              _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: Error setting dma_mask to 64, ret:%d\n",
                       "gpi_probe",iVar6);
              lVar9 = *(long *)(lVar7 + 0x1d0);
            }
            if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
            pcVar10 = "%s: Error setting dma_mask to 64, ret:%d\n";
          }
          ipc_log_string(lVar9,pcVar10,"gpi_probe",iVar6);
          goto LAB_00105930;
        }
        if (*(uint *)(lVar7 + 0x1dc) < 2) {
          lVar9 = *(long *)(lVar7 + 0x1d0);
        }
        else {
          _dev_err(*(undefined8 *)(lVar7 + 0x180),"%s: missing \'qcom,ev-factor\' DT node\n",
                   "gpi_probe");
          lVar9 = *(long *)(lVar7 + 0x1d0);
        }
        if ((lVar9 == 0) || (*(uint *)(lVar7 + 0x1d8) < 2)) goto LAB_00105930;
        pcVar10 = "%s: missing \'qcom,ev-factor\' DT node\n";
      }
    }
    ipc_log_string(lVar9,pcVar10,"gpi_probe");
  }
LAB_00105930:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar6;
}



//------------------------------------------------------------
// gpi_remove @ 00105a88 size=300
// signature: undefined gpi_remove(void)
// callers: []
//------------------------------------------------------------

undefined8 gpi_remove(long param_1)

{
  uint uVar1;
  code *pcVar2;
  uint uVar3;
  long lVar4;
  long lVar5;
  
  lVar4 = *(long *)(param_1 + 0xa8);
  of_dma_controller_free(*(undefined8 *)(*(long *)(lVar4 + 0x180) + 0x2e8));
  dma_async_device_unregister(lVar4);
  if (*(int *)(lVar4 + 0x1a0) != 0) {
    uVar3 = 0;
    do {
      uVar1 = 1 << (ulong)(uVar3 & 0x1f);
      if (((*(uint *)(lVar4 + 0x1a4) & uVar1) != 0) || ((*(uint *)(lVar4 + 0x1a8) & uVar1) != 0)) {
        lVar5 = *(long *)(lVar4 + 0x1c8) + (long)(int)uVar3 * 0x5c8;
        gpi_free_chan_resources(lVar5 + 8);
        gpi_free_chan_resources(lVar5 + 400);
        if (*(long *)(lVar5 + 0x420) != 0) {
          ipc_log_context_destroy();
        }
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(lVar4 + 0x1a0));
  }
  if ((((1 < arr_idx) && (gpi_dev_dbg._8_8_ = 0, arr_idx != 2)) &&
      (gpi_dev_dbg._16_8_ = 0, arr_idx != 3)) &&
     ((gpi_dev_dbg._24_8_ = 0, arr_idx != 4 && (gpi_dev_dbg._32_8_ = 0, arr_idx != 5)))) {
                    /* WARNING: Does not return */
    pcVar2 = (code *)SoftwareBreakpoint(0x5512,0x105bb4);
    (*pcVar2)();
  }
  arr_idx = 0;
  if (*(long *)(lVar4 + 0x1d0) != 0) {
    ipc_log_context_destroy();
  }
  debugfs_remove(pdentry);
  return 0;
}



//------------------------------------------------------------
// gpi_ev_tasklet @ 00105bb8 size=272
// signature: undefined gpi_ev_tasklet(void)
// callers: []
//------------------------------------------------------------

void gpi_ev_tasklet(long param_1)

{
  long lVar1;
  char *pcVar2;
  
  lVar1 = param_1 + 0x3b4;
  _raw_read_lock_bh(lVar1);
  if (*(uint *)(param_1 + 0x3b0) < 2) {
    _raw_read_unlock_bh(lVar1);
    if (*(uint *)(param_1 + 0x42c) < 2) {
      lVar1 = *(long *)(param_1 + 0x420);
    }
    else {
      if (*(uint *)(param_1 + 0x3b0) < 6) {
        pcVar2 = (&gpi_pm_state_str)[*(uint *)(param_1 + 0x3b0)];
      }
      else {
        pcVar2 = "INVALID";
      }
      _printk(&DAT_0010dc93,param_1 + 0x434,99,"gpi_ev_tasklet",pcVar2);
      lVar1 = *(long *)(param_1 + 0x420);
    }
    if ((lVar1 != 0) && (1 < *(uint *)(param_1 + 0x428))) {
      if (*(uint *)(param_1 + 0x3b0) < 6) {
        pcVar2 = (&gpi_pm_state_str)[*(uint *)(param_1 + 0x3b0)];
      }
      else {
        pcVar2 = "INVALID";
      }
      ipc_log_string(lVar1,"ch:%u %s: not processing any events, pm_state:%s\n",99,"gpi_ev_tasklet",
                     pcVar2);
    }
  }
  else {
    gpi_process_events(param_1);
    gpi_config_interrupts(param_1,1,1);
    _raw_read_unlock_bh(lVar1);
  }
  return;
}



//------------------------------------------------------------
// gpi_alloc_chan_resources @ 00105ccc size=296
// signature: undefined gpi_alloc_chan_resources(void)
// callers: []
//------------------------------------------------------------

int gpi_alloc_chan_resources(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = *(long *)(param_1 + 0x118);
  if (*(uint *)(lVar3 + 0x42c) < 3) {
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  else {
    _printk(&DAT_0010c015,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_alloc_chan_resources")
    ;
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  if ((lVar2 != 0) && (2 < *(uint *)(lVar3 + 0x428))) {
    ipc_log_string(lVar2,"ch:%u %s: enter\n",*(undefined4 *)(param_1 + 0x100),
                   "gpi_alloc_chan_resources");
  }
  mutex_lock(lVar3 + 0x378);
  iVar1 = gpi_alloc_ring(*(undefined8 *)(param_1 + 0x160),*(undefined4 *)(param_1 + 0x158),lVar3);
  if (iVar1 != 0) {
    if (*(uint *)(lVar3 + 0x42c) < 2) {
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    else {
      _printk(&DAT_0010c9cc,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),
              "gpi_alloc_chan_resources",iVar1);
      lVar2 = *(long *)(lVar3 + 0x420);
    }
    if ((lVar2 != 0) && (1 < *(uint *)(lVar3 + 0x428))) {
      ipc_log_string(lVar2,"ch:%u %s: error allocating xfer ring, ret:%d\n",
                     *(undefined4 *)(param_1 + 0x100),"gpi_alloc_chan_resources",iVar1);
    }
  }
  mutex_unlock(lVar3 + 0x378);
  return iVar1;
}



//------------------------------------------------------------
// gpi_free_chan_resources @ 00105df8 size=1260
// signature: undefined gpi_free_chan_resources(void)
// callers: [gpi_remove]
//------------------------------------------------------------

void gpi_free_chan_resources(long param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  undefined8 uVar4;
  long ****pppplVar5;
  long ****pppplVar6;
  long *****ppppplVar7;
  long lVar8;
  undefined8 *puVar9;
  long *****local_58;
  long *****local_50;
  long local_48;
  
  lVar8 = sp_el0;
  local_48 = *(long *)(lVar8 + 0x638);
  lVar8 = *(long *)(param_1 + 0x118);
  if (*(uint *)(lVar8 + 0x42c) < 3) {
    lVar2 = *(long *)(lVar8 + 0x420);
  }
  else {
    _printk(&DAT_0010c015,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_free_chan_resources");
    lVar2 = *(long *)(lVar8 + 0x420);
  }
  if ((lVar2 != 0) && (2 < *(uint *)(lVar8 + 0x428))) {
    ipc_log_string(lVar2,"ch:%u %s: enter\n",*(undefined4 *)(param_1 + 0x100),
                   "gpi_free_chan_resources");
  }
  mutex_lock(lVar8 + 0x378);
  lVar2 = lVar8 + 0x3b4;
  iVar1 = *(int *)(param_1 + 0x124);
  _raw_write_lock_irq(lVar2);
  *(undefined4 *)(param_1 + 0x124) = 4;
  _raw_write_unlock_irq(lVar2);
  if (iVar1 == 3) {
    iVar1 = gpi_send_cmd(lVar8,param_1,2);
    if (iVar1 != 0) {
      if (*(uint *)(lVar8 + 0x42c) < 2) {
        lVar3 = *(long *)(lVar8 + 0x420);
      }
      else {
        _printk(&DAT_0010b7ff,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
                "gpi_free_chan_resources",iVar1);
        lVar3 = *(long *)(lVar8 + 0x420);
      }
      if ((lVar3 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
        ipc_log_string(lVar3,"ch:%u %s: error stopping channel:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_free_chan_resources",iVar1);
      }
    }
    iVar1 = gpi_send_cmd(lVar8,param_1,3);
    if (iVar1 != 0) {
      if (*(uint *)(lVar8 + 0x42c) < 2) {
        lVar3 = *(long *)(lVar8 + 0x420);
      }
      else {
        _printk(&DAT_0010cfe1,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),
                "gpi_free_chan_resources",iVar1);
        lVar3 = *(long *)(lVar8 + 0x420);
      }
      if ((lVar3 != 0) && (1 < *(uint *)(lVar8 + 0x428))) {
        ipc_log_string(lVar3,"ch:%u %s: error resetting channel:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_free_chan_resources",iVar1);
      }
    }
    gpi_reset_chan(param_1,4);
  }
  puVar9 = *(undefined8 **)(param_1 + 0x160);
  dma_free_attrs(*(undefined8 *)(*(long *)(lVar8 + 0x318) + 0x180),puVar9[1],*puVar9,puVar9[3],0);
  puVar9[7] = 0;
  puVar9[8] = 0;
  puVar9[5] = 0;
  puVar9[6] = 0;
  puVar9[3] = 0;
  puVar9[4] = 0;
  puVar9[1] = 0;
  puVar9[2] = 0;
  *puVar9 = 0;
  local_58 = (long *****)&local_58;
  local_50 = (long *****)&local_58;
  uVar4 = _raw_spin_lock_irqsave(param_1 + 0xa0);
  pppplVar5 = (long ****)(param_1 + 0xa8);
  pppplVar6 = (long ****)*pppplVar5;
  if (pppplVar6 != pppplVar5) {
    ppppplVar7 = *(long ******)(param_1 + 0xb0);
    pppplVar6[1] = (long ***)local_50;
    *local_50 = pppplVar6;
    *ppppplVar7 = (long ****)&local_58;
    *(long *)(param_1 + 0xa8) = param_1 + 0xa8;
    *(long *****)(param_1 + 0xb0) = pppplVar5;
    local_50 = ppppplVar7;
  }
  pppplVar5 = (long ****)(param_1 + 0xb8);
  pppplVar6 = (long ****)*pppplVar5;
  if (pppplVar6 != pppplVar5) {
    ppppplVar7 = *(long ******)(param_1 + 0xc0);
    pppplVar6[1] = (long ***)local_50;
    *local_50 = pppplVar6;
    *ppppplVar7 = (long ****)&local_58;
    *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
    *(long *****)(param_1 + 0xc0) = pppplVar5;
    local_50 = ppppplVar7;
  }
  pppplVar5 = (long ****)(param_1 + 200);
  pppplVar6 = (long ****)*pppplVar5;
  if (pppplVar6 != pppplVar5) {
    ppppplVar7 = *(long ******)(param_1 + 0xd0);
    pppplVar6[1] = (long ***)local_50;
    *local_50 = pppplVar6;
    *ppppplVar7 = (long ****)&local_58;
    *(long *)(param_1 + 200) = param_1 + 200;
    *(long *****)(param_1 + 0xd0) = pppplVar5;
    local_50 = ppppplVar7;
  }
  pppplVar5 = (long ****)(param_1 + 0xd8);
  pppplVar6 = (long ****)*pppplVar5;
  if (pppplVar6 != pppplVar5) {
    ppppplVar7 = *(long ******)(param_1 + 0xe0);
    pppplVar6[1] = (long ***)local_50;
    *local_50 = pppplVar6;
    *ppppplVar7 = (long ****)&local_58;
    *(long *)(param_1 + 0xd8) = param_1 + 0xd8;
    *(long *****)(param_1 + 0xe0) = pppplVar5;
    local_50 = ppppplVar7;
  }
  pppplVar5 = (long ****)(param_1 + 0xe8);
  pppplVar6 = (long ****)*pppplVar5;
  if (pppplVar6 != pppplVar5) {
    ppppplVar7 = *(long ******)(param_1 + 0xf0);
    pppplVar6[1] = (long ***)local_50;
    *local_50 = pppplVar6;
    *ppppplVar7 = (long ****)&local_58;
    *(long *)(param_1 + 0xe8) = param_1 + 0xe8;
    *(long *****)(param_1 + 0xf0) = pppplVar5;
    local_50 = ppppplVar7;
  }
  for (ppppplVar7 = local_58; (long ******)ppppplVar7 != &local_58;
      ppppplVar7 = (long *****)*ppppplVar7) {
    *(uint *)((long)ppppplVar7 + -0x94) = *(uint *)((long)ppppplVar7 + -0x94) & 0xffffffbf;
  }
  _raw_spin_unlock_irqrestore(param_1 + 0xa0,uVar4);
  vchan_dma_desc_free_list(param_1,&local_58);
  _raw_write_lock_irq(lVar2);
  *(undefined4 *)(param_1 + 0x124) = 0;
  _raw_write_unlock_irq(lVar2);
  if ((*(char *)(*(long *)(lVar8 + 0x168) + 0x44) == '\0') &&
     (*(char *)(*(long *)(lVar8 + 0x2f0) + 0x44) == '\0')) {
    if (*(uint *)(lVar8 + 0x42c) < 3) {
      lVar3 = *(long *)(lVar8 + 0x420);
    }
    else {
      _printk(&DAT_0010dd6f,lVar8 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_free_chan_resources"
             );
      lVar3 = *(long *)(lVar8 + 0x420);
    }
    if ((lVar3 != 0) && (2 < *(uint *)(lVar8 + 0x428))) {
      ipc_log_string(lVar3,"ch:%u %s: disabling gpii\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_free_chan_resources");
    }
    iVar1 = *(int *)(lVar8 + 0x3b0);
    _raw_write_lock_irq(lVar2);
    *(undefined4 *)(lVar8 + 0x3b0) = 4;
    _raw_write_unlock_irq(lVar2);
    tasklet_kill(lVar8 + 0x3d0);
    if (iVar1 == 3) {
      gpi_send_cmd(lVar8,0,0xc);
      puVar9 = *(undefined8 **)(lVar8 + 0x3c0);
      dma_free_attrs(*(undefined8 *)(*(long *)(lVar8 + 0x318) + 0x180),puVar9[1],*puVar9,puVar9[3],0
                    );
      puVar9[7] = 0;
      puVar9[8] = 0;
      puVar9[5] = 0;
      puVar9[6] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      *puVar9 = 0;
      gpi_disable_interrupts(lVar8);
    }
    else {
      puVar9 = *(undefined8 **)(lVar8 + 0x3c0);
      dma_free_attrs(*(undefined8 *)(*(long *)(lVar8 + 0x318) + 0x180),puVar9[1],*puVar9,puVar9[3],0
                    );
      puVar9[7] = 0;
      puVar9[8] = 0;
      puVar9[5] = 0;
      puVar9[6] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[1] = 0;
      puVar9[2] = 0;
      *puVar9 = 0;
    }
    _raw_write_lock_irq(lVar2);
    *(undefined4 *)(lVar8 + 0x3b0) = 0;
    _raw_write_unlock_irq(lVar2);
  }
  mutex_unlock(lVar8 + 0x378);
  lVar8 = sp_el0;
  if (*(long *)(lVar8 + 0x638) != local_48) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// dma_cookie_status @ 001062e8 size=76
// signature: undefined dma_cookie_status(void)
// callers: []
//------------------------------------------------------------

undefined8 dma_cookie_status(long param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x14);
  if (param_3 != (int *)0x0) {
    *param_3 = iVar2;
    param_3[1] = iVar1;
    param_3[2] = 0;
    param_3[3] = 0;
  }
  if (iVar1 < iVar2) {
    if (param_2 <= iVar1) {
      return 1;
    }
  }
  else if (iVar1 < param_2) {
    return 0;
  }
  if (iVar2 < param_2) {
    return 1;
  }
  return 0;
}



//------------------------------------------------------------
// gpi_issue_pending @ 00106338 size=232
// signature: undefined gpi_issue_pending(void)
// callers: []
//------------------------------------------------------------

void gpi_issue_pending(long param_1)

{
  long lVar1;
  long lVar2;
  long *plVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  long *plVar6;
  long *plVar7;
  long *plVar8;
  long *plVar9;
  long lVar10;
  
  lVar1 = *(long *)(param_1 + 0x118) + 0x3b4;
  uVar4 = _raw_read_lock_irqsave(lVar1);
  lVar2 = param_1 + 0xa0;
  uVar5 = _raw_spin_lock_irqsave(lVar2);
  plVar6 = (long *)(param_1 + 0xb8);
  plVar7 = (long *)*plVar6;
  plVar3 = (long *)(param_1 + 200);
  if (plVar7 != plVar6) {
    plVar8 = *(long **)(param_1 + 0xd0);
    plVar9 = *(long **)(param_1 + 0xc0);
    plVar7[1] = (long)plVar8;
    *plVar8 = (long)plVar7;
    *plVar9 = (long)plVar3;
    *(long **)(param_1 + 0xd0) = plVar9;
    *(long *)(param_1 + 0xb8) = param_1 + 0xb8;
    *(long **)(param_1 + 0xc0) = plVar6;
  }
  if ((long *)*plVar3 == plVar3) {
    _raw_spin_unlock_irqrestore(lVar2,uVar5);
  }
  else {
    lVar10 = *(long *)(param_1 + 0xd0);
    _raw_spin_unlock_irqrestore(lVar2,uVar5);
    if (lVar10 != 0x98) {
      writel_relaxed((*(int *)(*(long *)(param_1 + 0x160) + 0x10) + *(int *)(lVar10 + 0x18)) -
                     *(int *)(*(long *)(param_1 + 0x160) + 0x20),*(undefined8 *)(param_1 + 0x130));
    }
  }
  _raw_read_unlock_irqrestore(lVar1,uVar4);
  return;
}



//------------------------------------------------------------
// gpi_config @ 00106424 size=1976
// signature: undefined gpi_config(void)
// callers: []
//------------------------------------------------------------

int gpi_config(long param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  undefined8 uVar8;
  long lVar9;
  undefined4 *puVar10;
  
  lVar9 = *(long *)(param_1 + 0x118);
  puVar10 = *(undefined4 **)(param_1 + 0x68);
  uVar2 = *(uint *)(*(long *)(lVar9 + 0x318) + 0x1ac);
  if (*(uint *)(lVar9 + 0x42c) < 3) {
    lVar6 = *(long *)(lVar9 + 0x420);
  }
  else {
    _printk(&DAT_0010c015,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
    lVar6 = *(long *)(lVar9 + 0x420);
  }
  if ((lVar6 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
    ipc_log_string(lVar6,"ch:%u %s: enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_config");
  }
  if (puVar10 == (undefined4 *)0x0) {
    if (*(uint *)(lVar9 + 0x42c) < 2) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010d4f5,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 == 0) || (*(uint *)(lVar9 + 0x428) < 2)) {
      return -0x16;
    }
    ipc_log_string(lVar6,"ch:%u %s: no config ctrl data provided",*(undefined4 *)(param_1 + 0x100),
                   "gpi_config");
    return -0x16;
  }
  mutex_lock(lVar9 + 0x378);
  switch(*puVar10) {
  case 1:
    if (*(uint *)(lVar9 + 0x42c) < 3) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010ba8d,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
      ipc_log_string(lVar6,"ch:%u %s: cmd: msm_gpi_init\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_config");
    }
    *(undefined8 *)(param_1 + 0x170) = *(undefined8 *)(puVar10 + 2);
    uVar8 = *(undefined8 *)(puVar10 + 4);
    *(undefined4 *)(param_1 + 0x124) = 1;
    *(undefined8 *)(param_1 + 0x178) = uVar8;
    if ((*(int *)(lVar9 + 300) != 1) || (*(int *)(lVar9 + 0x2b4) != 1)) {
      iVar4 = 0;
      goto LAB_00106724;
    }
    uVar1 = *(uint *)(lVar9 + 0x118);
    if (*(uint *)(lVar9 + 0x2a0) <= *(uint *)(lVar9 + 0x118)) {
      uVar1 = *(uint *)(lVar9 + 0x2a0);
    }
    *(uint *)(lVar9 + 800) = uVar1;
    if (*(int *)(lVar9 + 0x114) != *(int *)(lVar9 + 0x29c)) {
      if (*(uint *)(lVar9 + 0x42c) < 2) {
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010d9a0,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar6 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
        ipc_log_string(lVar6,"ch:%u %s: protocol did not match protocol %u != %u\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_config",*(undefined4 *)(lVar9 + 0x114),
                       *(undefined4 *)(lVar9 + 0x29c));
      }
      goto LAB_00106638;
    }
    uVar1 = *(uint *)(lVar9 + 0x160);
    if (*(uint *)(lVar9 + 0x160) <= *(uint *)(lVar9 + 0x2e8)) {
      uVar1 = *(uint *)(lVar9 + 0x2e8);
    }
    *(undefined4 *)(lVar9 + 0x324) = *(undefined4 *)(param_1 + 0x10c);
    iVar4 = gpi_alloc_ring(*(undefined8 *)(lVar9 + 0x3c0),uVar1 << (ulong)(uVar2 & 0x1f),lVar9);
    if (iVar4 != 0) {
      if (*(uint *)(lVar9 + 0x42c) < 2) {
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010b6f6,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar6 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
        ipc_log_string(lVar6,"ch:%u %s: error allocating mem for ev ring\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_config");
      }
      goto LAB_00106724;
    }
    _raw_write_lock_irq(lVar9 + 0x3b4);
    *(undefined4 *)(lVar9 + 0x3b0) = 2;
    _raw_write_unlock_irq(lVar9 + 0x3b4);
    iVar4 = gpi_config_interrupts(lVar9,0,0);
    if (iVar4 == 0) {
      iVar4 = gpi_alloc_ev_chan(lVar9);
      if (iVar4 == 0) {
        iVar5 = gpi_alloc_chan(lVar9 + 8,1);
        if (iVar5 == 0) {
          lVar6 = 1;
          iVar4 = gpi_alloc_chan(lVar9 + 400,1);
          if (iVar4 != 0) goto LAB_00106a00;
          iVar5 = gpi_start_chan(lVar9 + 8);
          if (iVar5 == 0) {
            iVar4 = gpi_start_chan(lVar9 + 400);
            if (iVar4 == 0) goto LAB_00106724;
            lVar6 = 1;
          }
          else {
            lVar6 = 0;
            iVar4 = iVar5;
          }
          if (*(uint *)(lVar9 + 0x42c) < 2) {
            lVar7 = *(long *)(lVar9 + 0x420);
          }
          else {
            _printk(&DAT_0010dfc8,lVar9 + 0x434,*(undefined4 *)(lVar9 + lVar6 * 0x188 + 0x108),
                    "gpi_config",iVar4);
            lVar7 = *(long *)(lVar9 + 0x420);
          }
          if ((lVar7 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
            ipc_log_string(lVar7,"ch:%u %s: Error start chan:%d\n",
                           *(undefined4 *)(lVar9 + lVar6 * 0x188 + 0x108),"gpi_config",iVar4);
          }
          if (iVar5 == 0) {
            gpi_send_cmd(lVar9,param_1,2);
            gpi_send_cmd(lVar9,param_1,3);
          }
          bVar3 = true;
        }
        else {
          lVar6 = 0;
          iVar4 = iVar5;
LAB_00106a00:
          if (*(uint *)(lVar9 + 0x42c) < 2) {
            lVar7 = *(long *)(lVar9 + 0x420);
          }
          else {
            _printk(&DAT_0010c551,lVar9 + 0x434,*(undefined4 *)(lVar9 + lVar6 * 0x188 + 0x108),
                    "gpi_config",iVar4);
            lVar7 = *(long *)(lVar9 + 0x420);
          }
          if ((lVar7 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
            ipc_log_string(lVar7,"ch:%u %s: Error allocating chan:%d\n",
                           *(undefined4 *)(lVar9 + lVar6 * 0x188 + 0x108),"gpi_config",iVar4);
          }
          if (iVar5 != 0) goto LAB_00106b5c;
          bVar3 = false;
        }
        gpi_reset_chan(param_1,4);
        if (bVar3) {
          gpi_reset_chan(param_1,4);
        }
      }
      else {
        if (*(uint *)(lVar9 + 0x42c) < 2) {
          lVar6 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010c837,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config",iVar4);
          lVar6 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar6 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
          ipc_log_string(lVar6,"ch:%u %s: error alloc_ev_chan:%d\n",*(undefined4 *)(param_1 + 0x100)
                         ,"gpi_config",iVar4);
        }
      }
LAB_00106b5c:
      gpi_disable_interrupts(lVar9);
    }
    else {
      if (*(uint *)(lVar9 + 0x42c) < 2) {
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010bc75,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config",iVar4);
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar6 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
        ipc_log_string(lVar6,"ch:%u %s: error config. interrupts, ret:%d\n",
                       *(undefined4 *)(param_1 + 0x100),"gpi_config",iVar4);
      }
    }
    gpi_free_ring(*(undefined8 *)(lVar9 + 0x3c0),lVar9);
    goto LAB_00106724;
  case 2:
    if (*(uint *)(lVar9 + 0x42c) < 3) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010ca1e,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
      ipc_log_string(lVar6,"ch:%u %s: sending UART SW STALE cmd\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_config");
    }
    uVar8 = 5;
    break;
  case 3:
    if (*(uint *)(lVar9 + 0x42c) < 3) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010cbc3,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
      ipc_log_string(lVar6,"ch:%u %s: sending UART RFR READY cmd\n",*(undefined4 *)(param_1 + 0x100)
                     ,"gpi_config");
    }
    uVar8 = 6;
    break;
  case 4:
    if (*(uint *)(lVar9 + 0x42c) < 3) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010cf12,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
      ipc_log_string(lVar6,"ch:%u %s: sending UART RFR READY NOT READY cmd\n",
                     *(undefined4 *)(param_1 + 0x100),"gpi_config");
    }
    uVar8 = 7;
    break;
  default:
    if (*(uint *)(lVar9 + 0x42c) < 2) {
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010d113,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_config");
      lVar6 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar6 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
      ipc_log_string(lVar6,"ch:%u %s: unsupported ctrl cmd:%d\n",*(undefined4 *)(param_1 + 0x100),
                     "gpi_config",*puVar10);
    }
LAB_00106638:
    iVar4 = -0x16;
    goto LAB_00106724;
  }
  iVar4 = gpi_send_cmd(lVar9,param_1,uVar8);
LAB_00106724:
  mutex_unlock(lVar9 + 0x378);
  return iVar4;
}



//------------------------------------------------------------
// gpi_pause @ 00106be0 size=3300
// signature: undefined gpi_pause(void)
// callers: []
//------------------------------------------------------------

int gpi_pause(long param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  char *pcVar15;
  undefined4 *puVar16;
  ulong uVar17;
  undefined4 *puVar18;
  int *piVar19;
  ulong uVar20;
  long lVar21;
  long lVar22;
  int *piVar23;
  long lVar24;
  long local_78;
  ulong local_70;
  long local_68;
  
  lVar24 = sp_el0;
  local_68 = *(long *)(lVar24 + 0x638);
  piVar19 = *(int **)(param_1 + 0x118);
  local_78 = 0;
  local_70 = 0;
  piVar23 = *(int **)(param_1 + 0x68);
  lVar24 = *(long *)(piVar19 + 0xf0);
  if ((uint)piVar19[0x10b] < 3) {
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  else {
    _printk(&DAT_0010c6a9,piVar19 + 0x10d,*(undefined4 *)(param_1 + 0x100),"gpi_pause");
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  if ((lVar12 != 0) && (2 < (uint)piVar19[0x10a])) {
    ipc_log_string(lVar12,"ch:%u %s: Enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_pause");
  }
  mutex_lock(piVar19 + 0xde);
  if (*(char *)((long)piVar19 + 0x5c2) == '\0') {
    if ((uint)piVar19[0x10b] < 2) {
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    else {
      _printk(&DAT_0010dfe9,piVar19 + 0x10d,*(undefined4 *)(param_1 + 0x100),"gpi_pause");
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    if ((lVar24 == 0) || ((uint)piVar19[0x10a] < 2)) {
      iVar11 = 0;
    }
    else {
      ipc_log_string(lVar24,"ch:%u %s: Already in suspend/pause state\n",
                     *(undefined4 *)(param_1 + 0x100),"gpi_pause");
      iVar11 = 0;
    }
    goto LAB_0010750c;
  }
  piVar1 = piVar19 + 0x10d;
  uVar10 = *piVar19 * 0x4000 + 0x23080;
  uVar20 = (ulong)uVar10;
  uVar17 = (ulong)(uVar10 | 0x38);
  uVar8 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar20);
  uVar9 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar17);
  if ((uint)piVar19[0x10b] < 2) {
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  else {
    _printk(&DAT_0010bdf4,piVar1,99,"gpi_pause",uVar8,uVar9);
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
    ipc_log_string(lVar12,"ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n",99,"gpi_pause",
                   uVar8,uVar9);
  }
  uVar8 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar20);
  uVar9 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar17);
  if ((uint)piVar19[0x10b] < 2) {
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  else {
    _printk(&DAT_0010bdf4,piVar1,99,"gpi_pause",uVar8,uVar9);
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
    ipc_log_string(lVar12,"ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n",99,"gpi_pause",
                   uVar8,uVar9);
  }
  uVar8 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar20);
  uVar9 = readl_relaxed(*(long *)(piVar19 + 0xcc) + uVar17);
  if ((uint)piVar19[0x10b] < 2) {
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  else {
    _printk(&DAT_0010bdf4,piVar1,99,"gpi_pause",uVar8,uVar9);
    lVar12 = *(long *)(piVar19 + 0x108);
  }
  if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
    ipc_log_string(lVar12,"ch:%u %s: CNTXT_TYPE_IRQ:0x%08x IEOB_MASK_OFF:0x%08x\n",99,"gpi_pause",
                   uVar8,uVar9);
  }
  uVar10 = readl_relaxed(*(undefined8 *)(piVar19 + 0xd4));
  local_70 = (ulong)uVar10;
  if (uVar10 == 0) {
    if ((uint)piVar19[0x10b] < 2) {
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    else {
      _printk(&DAT_0010c34f,piVar1,99,"gpi_pause");
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    if ((lVar24 == 0) || ((uint)piVar19[0x10a] < 2)) {
LAB_00107508:
      iVar11 = -0x16;
      goto LAB_0010750c;
    }
    pcVar15 = "ch:%u %s: invalid cntxt_rp";
  }
  else {
    puVar18 = *(undefined4 **)(lVar24 + 0x30);
    lVar12 = *(long *)(lVar24 + 0x20);
    local_78 = (long)puVar18 + (*(long *)(lVar24 + 0x10) - lVar12);
    if (local_78 != 0) {
      lVar21 = local_70 - *(long *)(lVar24 + 0x10);
      if (1 < (uint)piVar19[0x10b]) {
        _printk(&DAT_0010baac,piVar1,99,"gpi_pause",&local_70,&local_78);
      }
      puVar16 = (undefined4 *)(lVar12 + lVar21);
      if ((*(long *)(piVar19 + 0x108) != 0) && (1 < (uint)piVar19[0x10a])) {
        ipc_log_string(*(long *)(piVar19 + 0x108),"ch:%u %s: cntxt_rp:%pa local_rp:%pa\n",99,
                       "gpi_pause",&local_70,&local_78);
      }
      while (puVar16 != puVar18) {
        uVar6 = *(undefined1 *)((long)puVar18 + 0xf);
        uVar7 = *(undefined1 *)((long)puVar18 + 0xe);
        if ((uint)piVar19[0x10b] < 2) {
          lVar12 = *(long *)(piVar19 + 0x108);
        }
        else {
          _printk(&DAT_0010d5a7,piVar1,99,"gpi_pause",uVar6,uVar7,*puVar18,puVar18[1],puVar18[2],
                  puVar18[3],puVar16,puVar18);
          lVar12 = *(long *)(piVar19 + 0x108);
        }
        if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
          ipc_log_string(lVar12,"ch:%u %s: chid:%u type:0x%x %08x %08x %08x %08x rp:%pK rp1:%pK\n",
                         99,"gpi_pause",uVar6,uVar7,*puVar18,puVar18[1],puVar18[2],puVar18[3],
                         puVar16,puVar18);
        }
        puVar18 = (undefined4 *)((long)puVar18 + (ulong)*(uint *)(lVar24 + 0x3c));
        if ((undefined4 *)((long)*(undefined4 **)(lVar24 + 0x20) + (ulong)*(uint *)(lVar24 + 0x38))
            <= puVar18) {
          puVar18 = *(undefined4 **)(lVar24 + 0x20);
        }
      }
      piVar2 = piVar19 + 0xed;
      piVar3 = piVar19 + 2;
      _raw_write_lock_irq(piVar2);
      piVar19[0x4b] = 4;
      _raw_write_unlock_irq(piVar2);
      iVar11 = gpi_send_cmd(piVar19,piVar3,2);
      if (iVar11 == 0) {
        piVar4 = piVar19 + 100;
        _raw_write_lock_irq(piVar2);
        piVar19[0xad] = 4;
        _raw_write_unlock_irq(piVar2);
        iVar11 = gpi_send_cmd(piVar19,piVar4,2);
        if (iVar11 != 0) {
          lVar24 = 1;
          goto LAB_00107030;
        }
        if (*piVar23 != 5) {
          lVar24 = 0;
          do {
            lVar12 = *(long *)(piVar19 + lVar24 * 0x62 + 0x48);
            lVar21 = *(long *)(piVar19 + lVar24 * 0x62 + 0x5a);
            if (*(uint *)(lVar12 + 0x42c) < 3) {
              lVar13 = *(long *)(lVar12 + 0x420);
            }
            else {
              _printk(&DAT_0010c6a9,lVar12 + 0x434,piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre");
              lVar13 = *(long *)(lVar12 + 0x420);
            }
            if ((lVar13 != 0) && (2 < *(uint *)(lVar12 + 0x428))) {
              ipc_log_string(lVar13,"ch:%u %s: Enter\n",piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre"
                            );
            }
            puVar18 = *(undefined4 **)(lVar21 + 0x30);
            lVar22 = (long)puVar18 + (*(long *)(lVar21 + 0x10) - *(long *)(lVar21 + 0x20));
            lVar13 = (*(long *)(lVar21 + 0x10) - *(long *)(lVar21 + 0x20)) +
                     *(long *)(lVar21 + 0x28);
            if (*(uint *)(lVar12 + 0x42c) < 3) {
              lVar14 = *(long *)(lVar12 + 0x420);
            }
            else {
              _printk(&DAT_0010c5e0,lVar12 + 0x434,piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre",
                      lVar22,lVar13);
              lVar14 = *(long *)(lVar12 + 0x420);
            }
            if ((lVar14 != 0) && (2 < *(uint *)(lVar12 + 0x428))) {
              ipc_log_string(lVar14,"ch:%u %s: local_rp:0x%0llx local_wp:0x%0llx\n",
                             piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre",lVar22,lVar13);
            }
            if (lVar22 != lVar13) {
              piVar23 = piVar19 + lVar24 * 0x62 + 0x42;
              do {
                if (*(uint *)(lVar12 + 0x42c) < 2) {
                  lVar14 = *(long *)(lVar12 + 0x420);
                }
                else {
                  _printk(&DAT_0010c60f,lVar12 + 0x434,*piVar23,"gpi_noop_tre",lVar22,*puVar18,
                          puVar18[1],puVar18[2],puVar18[3]);
                  lVar14 = *(long *)(lVar12 + 0x420);
                }
                if ((lVar14 != 0) && (1 < *(uint *)(lVar12 + 0x428))) {
                  ipc_log_string(lVar14,"ch:%u %s: local_rp:%llu TRE: %08x %08x %08x %08x\n",
                                 *piVar23,"gpi_noop_tre",lVar22,*puVar18,puVar18[1],puVar18[2],
                                 puVar18[3]);
                }
                puVar18[3] = puVar18[3] & 0x801 | 0x10000;
                puVar16 = *(undefined4 **)(lVar21 + 0x20);
                puVar18 = (undefined4 *)((long)puVar18 + (ulong)*(uint *)(lVar21 + 0x3c));
                if (puVar18 < (undefined4 *)((long)puVar16 + (ulong)*(uint *)(lVar21 + 0x38))) {
                  lVar22 = lVar22 + (ulong)*(uint *)(lVar21 + 0x3c);
                  puVar16 = puVar18;
                }
                else {
                  lVar22 = *(long *)(lVar21 + 0x10);
                }
                if (*(uint *)(lVar12 + 0x42c) < 3) {
                  lVar14 = *(long *)(lVar12 + 0x420);
                }
                else {
                  _printk(&DAT_0010cbeb,lVar12 + 0x434,*piVar23,"gpi_noop_tre",lVar22);
                  lVar14 = *(long *)(lVar12 + 0x420);
                }
                if ((lVar14 != 0) && (2 < *(uint *)(lVar12 + 0x428))) {
                  ipc_log_string(lVar14,"ch:%u %s: local_rp:0x%0llx\n",*piVar23,"gpi_noop_tre",
                                 lVar22);
                }
                puVar18 = puVar16;
              } while (lVar22 != lVar13);
            }
            if (*(uint *)(lVar12 + 0x42c) < 3) {
              lVar21 = *(long *)(lVar12 + 0x420);
            }
            else {
              _printk(&DAT_0010c381,lVar12 + 0x434,piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre");
              lVar21 = *(long *)(lVar12 + 0x420);
            }
            if ((lVar21 != 0) && (2 < *(uint *)(lVar12 + 0x428))) {
              ipc_log_string(lVar21,"ch:%u %s: exit\n",piVar19[lVar24 * 0x62 + 0x42],"gpi_noop_tre")
              ;
            }
            lVar24 = lVar24 + 1;
          } while (lVar24 != 2);
          iVar11 = gpi_start_chan(piVar3);
          if (iVar11 == 0) {
            iVar11 = gpi_start_chan(piVar4);
            if (iVar11 == 0) {
LAB_001077ac:
              if (*(char *)((long)piVar19 + 0x5c1) == '\0') {
                iVar11 = 0;
              }
              else {
                iVar11 = 1;
                do {
                  __const_udelay(0xa7c6);
                  if (iVar11 == 1000) break;
                  iVar11 = iVar11 + 1;
                } while (*(char *)((long)piVar19 + 0x5c1) != '\0');
              }
              if ((uint)piVar19[0x10b] < 3) {
                lVar24 = *(long *)(piVar19 + 0x108);
              }
              else {
                _printk(&DAT_0010c36c,piVar1,piVar19[0xa4],"gpi_pause",iVar11);
                lVar24 = *(long *)(piVar19 + 0x108);
              }
              if ((lVar24 != 0) && (2 < (uint)piVar19[0x10a])) {
                ipc_log_string(lVar24,"ch:%u %s: iter:%d\n",piVar19[0xa4],"gpi_pause",iVar11);
              }
              disable_irq(piVar19[0xca]);
              iVar11 = 0;
              *(undefined1 *)((long)piVar19 + 0x5c2) = 0;
              goto LAB_0010750c;
            }
            lVar24 = 1;
          }
          else {
            lVar24 = 0;
          }
          if ((uint)piVar19[0x10b] < 2) {
            lVar12 = *(long *)(piVar19 + 0x108);
          }
          else {
            _printk(&DAT_0010d326,piVar1,piVar19[lVar24 * 0x62 + 0x42],"gpi_pause",iVar11);
            lVar12 = *(long *)(piVar19 + 0x108);
          }
          if ((lVar12 == 0) || ((uint)piVar19[0x10a] < 2)) goto LAB_00107074;
          pcVar15 = "ch:%u %s: Error Starting Channel ret:%d\n";
LAB_00107640:
          iVar5 = piVar19[lVar24 * 0x62 + 0x42];
          goto LAB_00107070;
        }
        if ((uint)piVar19[0x10b] < 3) {
          lVar24 = *(long *)(piVar19 + 0x108);
        }
        else {
          _printk(&DAT_0010cdd7,piVar1,piVar19[0xa4],"gpi_pause");
          lVar24 = *(long *)(piVar19 + 0x108);
        }
        if ((lVar24 != 0) && (2 < (uint)piVar19[0x10a])) {
          ipc_log_string(lVar24,"ch:%u %s: deep sleep config\n",piVar19[0xa4],"gpi_pause");
        }
        iVar11 = gpi_send_cmd(piVar19,piVar3,3);
        if (iVar11 == 0) {
          iVar11 = gpi_send_cmd(piVar19,piVar4,3);
          if (iVar11 == 0) {
            iVar11 = gpi_reset_chan(piVar3,4);
            if (iVar11 == 0) {
              iVar11 = gpi_reset_chan(piVar4,4);
              if (iVar11 == 0) {
                iVar11 = gpi_send_cmd(piVar19,0,0xc);
                if (iVar11 != 0) {
                  if ((uint)piVar19[0x10b] < 2) {
                    lVar24 = *(long *)(piVar19 + 0x108);
                  }
                  else {
                    _printk(&DAT_0010d138,piVar1,99,"gpi_pause","EV DEALLOC",iVar11);
                    lVar24 = *(long *)(piVar19 + 0x108);
                  }
                  if ((lVar24 != 0) && (1 < (uint)piVar19[0x10a])) {
                    ipc_log_string(lVar24,"ch:%u %s: error with cmd:%s ret:%d\n",99,"gpi_pause",
                                   "EV DEALLOC",iVar11);
                  }
                  goto LAB_0010750c;
                }
                goto LAB_001077ac;
              }
              lVar24 = 1;
            }
            else {
              lVar24 = 0;
            }
            if ((uint)piVar19[0x10b] < 2) {
              lVar12 = *(long *)(piVar19 + 0x108);
            }
            else {
              _printk(&DAT_0010dd8b,piVar1,piVar19[lVar24 * 0x62 + 0x42],"gpi_pause",iVar11);
              lVar12 = *(long *)(piVar19 + 0x108);
            }
            if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
              pcVar15 = "ch:%u %s: Error chan deallocating, ret:%d\n";
              goto LAB_00107640;
            }
            goto LAB_00107074;
          }
          lVar24 = 1;
        }
        else {
          lVar24 = 0;
        }
        if ((uint)piVar19[0x10b] < 2) {
          lVar12 = *(long *)(piVar19 + 0x108);
          if (lVar12 == 0) goto LAB_00107074;
LAB_001075dc:
          if ((uint)piVar19[0x10a] < 2) goto LAB_00107074;
          pcVar15 = "ch:%u %s: Error resetting chan, ret:%d\n";
          goto LAB_0010705c;
        }
        _printk(&DAT_0010cdf6,piVar1,piVar19[lVar24 * 0x62 + 0x42],"gpi_pause",iVar11);
        lVar12 = *(long *)(piVar19 + 0x108);
        if (lVar12 != 0) goto LAB_001075dc;
      }
      else {
        lVar24 = 0;
LAB_00107030:
        if ((uint)piVar19[0x10b] < 2) {
          lVar12 = *(long *)(piVar19 + 0x108);
        }
        else {
          _printk(&DAT_0010c5b7,piVar1,piVar19[lVar24 * 0x62 + 0x42],"gpi_pause",iVar11);
          lVar12 = *(long *)(piVar19 + 0x108);
        }
        if ((lVar12 != 0) && (1 < (uint)piVar19[0x10a])) {
          pcVar15 = "ch:%u %s: Error stopping chan, ret:%d\n";
LAB_0010705c:
          iVar5 = piVar19[lVar24 * 0x62 + 0x42];
LAB_00107070:
          ipc_log_string(lVar12,pcVar15,iVar5,"gpi_pause",iVar11);
        }
      }
LAB_00107074:
      iVar11 = -0x68;
      goto LAB_0010750c;
    }
    if ((uint)piVar19[0x10b] < 2) {
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    else {
      _printk(&DAT_0010e015,piVar1,99,"gpi_pause");
      lVar24 = *(long *)(piVar19 + 0x108);
    }
    if ((lVar24 == 0) || ((uint)piVar19[0x10a] < 2)) goto LAB_00107508;
    pcVar15 = "ch:%u %s: invalid local_rp";
  }
  ipc_log_string(lVar24,pcVar15,99,"gpi_pause");
  iVar11 = -0x16;
LAB_0010750c:
  mutex_unlock(piVar19 + 0xde);
  lVar24 = sp_el0;
  if (*(long *)(lVar24 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar11;
}



//------------------------------------------------------------
// gpi_resume @ 001078c8 size=1688
// signature: undefined gpi_resume(void)
// callers: []
//------------------------------------------------------------

int gpi_resume(long param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  char *pcVar8;
  long lVar9;
  int *piVar10;
  long lVar11;
  
  lVar9 = *(long *)(param_1 + 0x118);
  piVar10 = *(int **)(param_1 + 0x68);
  if (*(uint *)(lVar9 + 0x42c) < 3) {
    lVar5 = *(long *)(lVar9 + 0x420);
  }
  else {
    _printk(&DAT_0010c015,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_resume");
    lVar5 = *(long *)(lVar9 + 0x420);
  }
  if ((lVar5 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
    ipc_log_string(lVar5,"ch:%u %s: enter\n",*(undefined4 *)(param_1 + 0x100),"gpi_resume");
  }
  mutex_lock(lVar9 + 0x378);
  if (*(char *)(lVar9 + 0x5c2) == '\0') {
    enable_irq(*(undefined4 *)(lVar9 + 0x328));
    *(undefined1 *)(lVar9 + 0x5c2) = 1;
    if (*piVar10 == 5) {
      if (*(uint *)(lVar9 + 0x42c) < 3) {
        lVar5 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010cdd7,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_resume");
        lVar5 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar5 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
        ipc_log_string(lVar5,"ch:%u %s: deep sleep config\n",*(undefined4 *)(param_1 + 0x100),
                       "gpi_resume");
      }
      lVar5 = *(long *)(param_1 + 0x118);
      if (*(uint *)(lVar5 + 0x42c) < 3) {
        lVar6 = *(long *)(lVar5 + 0x420);
      }
      else {
        _printk(&DAT_0010c015,lVar5 + 0x434,*(undefined4 *)(param_1 + 0x100),
                "gpi_deep_sleep_exit_config");
        lVar6 = *(long *)(lVar5 + 0x420);
      }
      if ((lVar6 != 0) && (2 < *(uint *)(lVar5 + 0x428))) {
        ipc_log_string(lVar6,"ch:%u %s: enter\n",*(undefined4 *)(param_1 + 0x100),
                       "gpi_deep_sleep_exit_config");
      }
      lVar6 = *(long *)(lVar5 + 0x168);
      *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(lVar6 + 0x20);
      *(undefined8 *)(lVar6 + 0x30) = *(undefined8 *)(lVar6 + 0x20);
      lVar6 = *(long *)(lVar5 + 0x2f0);
      *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(lVar6 + 0x20);
      *(undefined8 *)(lVar6 + 0x30) = *(undefined8 *)(lVar6 + 0x20);
      lVar6 = *(long *)(lVar5 + 0x3c0);
      *(undefined8 *)(lVar6 + 0x28) = *(undefined8 *)(lVar6 + 0x20);
      *(undefined8 *)(lVar6 + 0x30) = *(undefined8 *)(lVar6 + 0x20);
      iVar3 = gpi_config_interrupts(lVar5,0,0);
      if (iVar3 == 0) {
        iVar3 = gpi_alloc_ev_chan(lVar5);
        if (iVar3 == 0) {
          lVar6 = lVar5 + 400;
          iVar4 = gpi_alloc_chan(lVar5 + 8,1);
          if (iVar4 == 0) {
            lVar11 = 1;
            iVar3 = gpi_alloc_chan(lVar6,1);
            if (iVar3 != 0) goto LAB_00107be4;
            iVar4 = gpi_start_chan(lVar5 + 8);
            if (iVar4 == 0) {
              iVar3 = gpi_start_chan(lVar6);
              if (iVar3 == 0) goto LAB_00107dbc;
              lVar11 = 1;
            }
            else {
              lVar11 = 0;
              iVar3 = iVar4;
            }
            if (*(uint *)(lVar5 + 0x42c) < 2) {
              lVar7 = *(long *)(lVar5 + 0x420);
            }
            else {
              _printk(&DAT_0010dfc8,lVar5 + 0x434,*(undefined4 *)(lVar5 + lVar11 * 0x188 + 0x108),
                      "gpi_deep_sleep_exit_config",iVar3);
              lVar7 = *(long *)(lVar5 + 0x420);
            }
            if ((lVar7 != 0) && (1 < *(uint *)(lVar5 + 0x428))) {
              ipc_log_string(lVar7,"ch:%u %s: Error start chan:%d\n",
                             *(undefined4 *)(lVar5 + lVar11 * 0x188 + 0x108),
                             "gpi_deep_sleep_exit_config",iVar3);
            }
            if (iVar4 == 0) {
              iVar4 = (int)lVar11 + -1;
              do {
                gpi_send_cmd(lVar5,lVar6,2);
                gpi_send_cmd(lVar5,lVar6,3);
                iVar4 = iVar4 + 1;
              } while (-1 < iVar4);
            }
            bVar2 = true;
          }
          else {
            lVar11 = 0;
            iVar3 = iVar4;
LAB_00107be4:
            if (*(uint *)(lVar5 + 0x42c) < 2) {
              lVar7 = *(long *)(lVar5 + 0x420);
            }
            else {
              _printk(&DAT_0010c551,lVar5 + 0x434,*(undefined4 *)(lVar5 + lVar11 * 0x188 + 0x108),
                      "gpi_deep_sleep_exit_config",iVar3);
              lVar7 = *(long *)(lVar5 + 0x420);
            }
            if ((lVar7 != 0) && (1 < *(uint *)(lVar5 + 0x428))) {
              ipc_log_string(lVar7,"ch:%u %s: Error allocating chan:%d\n",
                             *(undefined4 *)(lVar5 + lVar11 * 0x188 + 0x108),
                             "gpi_deep_sleep_exit_config",iVar3);
            }
            bVar2 = false;
            if (iVar4 != 0) goto LAB_00107c2c;
          }
          gpi_reset_chan(lVar6,4);
          if (bVar2) {
            gpi_reset_chan(lVar6,4);
          }
          gpi_disable_interrupts(lVar5);
          if (iVar3 == 0) goto LAB_00107dbc;
        }
        else {
          if (*(uint *)(lVar5 + 0x42c) < 2) {
            lVar6 = *(long *)(lVar5 + 0x420);
          }
          else {
            _printk(&DAT_0010c837,lVar5 + 0x434,*(undefined4 *)(lVar5 + 0x290),
                    "gpi_deep_sleep_exit_config",iVar3);
            lVar6 = *(long *)(lVar5 + 0x420);
          }
          if ((lVar6 != 0) && (1 < *(uint *)(lVar5 + 0x428))) {
            ipc_log_string(lVar6,"ch:%u %s: error alloc_ev_chan:%d\n",*(undefined4 *)(lVar5 + 0x290)
                           ,"gpi_deep_sleep_exit_config",iVar3);
          }
LAB_00107c2c:
          gpi_disable_interrupts(lVar5);
        }
      }
      else {
        if (*(uint *)(lVar5 + 0x42c) < 2) {
          lVar6 = *(long *)(lVar5 + 0x420);
        }
        else {
          _printk(&DAT_0010bc75,lVar5 + 0x434,*(undefined4 *)(lVar5 + 0x290),
                  "gpi_deep_sleep_exit_config",iVar3);
          lVar6 = *(long *)(lVar5 + 0x420);
        }
        if ((lVar6 != 0) && (1 < *(uint *)(lVar5 + 0x428))) {
          ipc_log_string(lVar6,"ch:%u %s: error config. interrupts, ret:%d\n",
                         *(undefined4 *)(lVar5 + 0x290),"gpi_deep_sleep_exit_config",iVar3);
        }
      }
      if (*(uint *)(lVar9 + 0x42c) < 2) {
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010e143,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_resume",iVar3);
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar6 == 0) || (*(uint *)(lVar9 + 0x428) < 2)) goto LAB_0010797c;
      uVar1 = *(undefined4 *)(param_1 + 0x100);
      pcVar8 = "ch:%u %s: Err deep sleep config, ret:%d\n";
    }
    else {
LAB_00107dbc:
      if (*(int *)(lVar9 + 0x3b0) == 3) {
        if (*(uint *)(lVar9 + 0x42c) < 3) {
          lVar5 = *(long *)(lVar9 + 0x420);
        }
        else {
          _printk(&DAT_0010c1b2,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_resume");
          lVar5 = *(long *)(lVar9 + 0x420);
        }
        if ((lVar5 != 0) && (2 < *(uint *)(lVar9 + 0x428))) {
          uVar1 = *(undefined4 *)(param_1 + 0x100);
          pcVar8 = "ch:%u %s: channel is already active\n";
          goto LAB_0010796c;
        }
        goto LAB_00107978;
      }
      iVar3 = gpi_send_cmd(lVar9,lVar9 + 8,1);
      if (iVar3 == 0) {
        lVar5 = 1;
        iVar3 = gpi_send_cmd(lVar9,lVar9 + 400,1);
        if (iVar3 == 0) {
          _raw_write_lock_irq(lVar9 + 0x3b4);
          *(undefined4 *)(lVar9 + 0x3b0) = 3;
          _raw_write_unlock_irq(lVar9 + 0x3b4);
          goto LAB_0010797c;
        }
      }
      else {
        lVar5 = 0;
      }
      if (*(uint *)(lVar9 + 0x42c) < 2) {
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      else {
        _printk(&DAT_0010be64,lVar9 + 0x434,*(undefined4 *)(lVar9 + lVar5 * 0x188 + 0x108),
                "gpi_resume",iVar3);
        lVar6 = *(long *)(lVar9 + 0x420);
      }
      if ((lVar6 == 0) || (*(uint *)(lVar9 + 0x428) < 2)) goto LAB_0010797c;
      pcVar8 = "ch:%u %s: Erro starting chan, ret:%d\n";
      uVar1 = *(undefined4 *)(lVar9 + lVar5 * 0x188 + 0x108);
    }
    ipc_log_string(lVar6,pcVar8,uVar1,"gpi_resume",iVar3);
  }
  else {
    if (*(uint *)(lVar9 + 0x42c) < 2) {
      lVar5 = *(long *)(lVar9 + 0x420);
    }
    else {
      _printk(&DAT_0010d5e9,lVar9 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_resume");
      lVar5 = *(long *)(lVar9 + 0x420);
    }
    if ((lVar5 != 0) && (1 < *(uint *)(lVar9 + 0x428))) {
      uVar1 = *(undefined4 *)(param_1 + 0x100);
      pcVar8 = "ch:%u %s: Already resumed\n";
LAB_0010796c:
      ipc_log_string(lVar5,pcVar8,uVar1,"gpi_resume");
    }
LAB_00107978:
    iVar3 = 0;
  }
LAB_0010797c:
  mutex_unlock(lVar9 + 0x378);
  return iVar3;
}



//------------------------------------------------------------
// gpi_of_dma_xlate @ 00107f64 size=996
// signature: undefined gpi_of_dma_xlate(void)
// callers: []
//------------------------------------------------------------

undefined8 gpi_of_dma_xlate(long param_1,long param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  long lVar4;
  undefined8 uVar5;
  char *pcVar6;
  long lVar7;
  long lVar8;
  uint uVar9;
  long lVar10;
  long lVar11;
  
  lVar10 = *(long *)(param_2 + 0x30);
  if (*(int *)(param_1 + 8) < 5) {
    if (*(uint *)(lVar10 + 0x1dc) < 2) {
      lVar4 = *(long *)(lVar10 + 0x1d0);
    }
    else {
      _dev_err(*(undefined8 *)(lVar10 + 0x180),
               "%s: gpii require minimum 6 args, client passed:%d args\n","gpi_of_dma_xlate");
      lVar4 = *(long *)(lVar10 + 0x1d0);
    }
    if (lVar4 == 0) {
      return 0;
    }
    if (*(uint *)(lVar10 + 0x1d8) < 2) {
      return 0;
    }
    uVar1 = *(uint *)(param_1 + 8);
    pcVar6 = "%s: gpii require minimum 6 args, client passed:%d args\n";
LAB_00108010:
    ipc_log_string(lVar4,pcVar6,"gpi_of_dma_xlate",uVar1);
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 0xc);
  if (1 < uVar1) {
    if (*(uint *)(lVar10 + 0x1dc) < 2) {
      lVar4 = *(long *)(lVar10 + 0x1d0);
    }
    else {
      _dev_err(*(undefined8 *)(lVar10 + 0x180),"%s: gpii channel:%d not valid\n","gpi_of_dma_xlate",
               uVar1);
      lVar4 = *(long *)(lVar10 + 0x1d0);
    }
    if (lVar4 == 0) {
      return 0;
    }
    if (*(uint *)(lVar10 + 0x1d8) < 2) {
      return 0;
    }
    pcVar6 = "%s: gpii channel:%d not valid\n";
    goto LAB_00108010;
  }
  lVar4 = lVar10 + 0x1f0;
  mutex_lock(lVar4);
  uVar9 = *(uint *)(param_1 + 0x1c) >> 1 & 0xf;
  iVar2 = *(int *)(param_1 + 0x10);
  if (uVar9 == 0) {
    uVar3 = *(uint *)(lVar10 + 0x1a0);
    if (uVar3 != 0) {
      uVar9 = 0;
      do {
        if ((*(uint *)(lVar10 + 0x1a4) >> (ulong)(uVar9 & 0x1f) & 1) != 0) {
          lVar11 = *(long *)(lVar10 + 0x1c8);
          lVar7 = lVar11 + (long)(int)uVar9 * 0x5c8;
          if (((*(int *)(lVar7 + 0x1e0) != 0) &&
              (*(int *)(lVar11 + (long)(int)uVar9 * 0x5c8 + 0x294) == iVar2)) ||
             ((*(int *)(lVar7 + 0x58) != 0 && (*(int *)(lVar7 + 0x10c) == iVar2))))
          goto LAB_00108120;
        }
        uVar9 = uVar9 + 1;
      } while (uVar3 != uVar9);
      uVar9 = 0;
      do {
        if ((((*(uint *)(lVar10 + 0x1a4) >> (ulong)(uVar9 & 0x1f) & 1) != 0) &&
            (lVar11 = *(long *)(lVar10 + 0x1c8),
            *(int *)(lVar11 + (long)(int)uVar9 * 0x5c8 + 0x58) == 0)) &&
           (*(int *)(lVar11 + (long)(int)uVar9 * 0x5c8 + 0x1e0) == 0)) goto LAB_00108120;
        uVar9 = uVar9 + 1;
      } while (uVar3 != uVar9);
    }
  }
  else {
    uVar9 = uVar9 - 1;
    if ((*(uint *)(lVar10 + 0x1a8) >> (ulong)(uVar9 & 0x1f) & 1) != 0) {
      lVar11 = *(long *)(lVar10 + 0x1c8);
      goto LAB_00108048;
    }
  }
  goto LAB_00108124;
LAB_00108120:
  if (-1 < (int)uVar9) {
LAB_00108048:
    lVar7 = lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188;
    if (*(int *)(lVar7 + 0x58) == 0) {
      lVar8 = lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188;
      *(int *)(lVar8 + 0x10c) = iVar2;
      iVar2 = *(int *)(param_1 + 0x14);
      *(int *)(lVar8 + 0x114) = iVar2;
      if (iVar2 == 0xe) {
        lVar8 = lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188;
        *(byte *)(lVar8 + 0x110) = *(byte *)(lVar8 + 0x110) | 1;
      }
      lVar11 = lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188;
      *(undefined4 *)(lVar11 + 0x160) = *(undefined4 *)(param_1 + 0x18);
      *(uint *)(lVar11 + 0x118) = *(uint *)(param_1 + 0x1c) & 1;
      if ((*(long *)(lVar10 + 0x1d0) != 0) && (*(int *)(lVar10 + 0x1d8) != 0)) {
        ipc_log_string(*(long *)(lVar10 + 0x1d0),
                       "%s: client req gpii:%u chid:%u #_tre:%u prio:%u proto:%u SE:%d init_config:%d\n"
                       ,"gpi_of_dma_xlate",uVar9,uVar1);
      }
      uVar5 = dma_get_slave_channel(lVar7 + 8);
      mutex_unlock(lVar4);
      return uVar5;
    }
    if (*(uint *)(lVar10 + 0x1dc) < 2) {
      lVar7 = *(long *)(lVar10 + 0x1d0);
    }
    else {
      _dev_err(*(undefined8 *)(lVar10 + 0x180),"%s: gpii:%d chid:%d seid:%d already configured\n",
               "gpi_of_dma_xlate",uVar9,uVar1,
               *(undefined4 *)(lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188 + 0x10c));
      lVar7 = *(long *)(lVar10 + 0x1d0);
    }
    if ((lVar7 != 0) && (1 < *(uint *)(lVar10 + 0x1d8))) {
      ipc_log_string(lVar7,"%s: gpii:%d chid:%d seid:%d already configured\n","gpi_of_dma_xlate",
                     uVar9,uVar1,
                     *(undefined4 *)(lVar11 + (ulong)uVar9 * 0x5c8 + (ulong)uVar1 * 0x188 + 0x10c));
    }
    goto LAB_00108158;
  }
LAB_00108124:
  if (*(uint *)(lVar10 + 0x1dc) < 2) {
    lVar7 = *(long *)(lVar10 + 0x1d0);
  }
  else {
    _dev_err(*(undefined8 *)(lVar10 + 0x180),"%s: no available gpii instances\n","gpi_of_dma_xlate")
    ;
    lVar7 = *(long *)(lVar10 + 0x1d0);
  }
  if ((lVar7 != 0) && (1 < *(uint *)(lVar10 + 0x1d8))) {
    ipc_log_string(lVar7,"%s: no available gpii instances\n","gpi_of_dma_xlate");
  }
LAB_00108158:
  mutex_unlock(lVar4);
  return 0;
}



//------------------------------------------------------------
// gpi_setup_debug @ 00108348 size=660
// signature: undefined gpi_setup_debug(void)
// callers: [gpi_probe]
//------------------------------------------------------------

void gpi_setup_debug(long param_1)

{
  uint uVar1;
  undefined8 uVar2;
  ulong uVar3;
  uint param5;
  long lVar4;
  long lVar5;
  char local_170 [256];
  long local_70;
  
  lVar4 = sp_el0;
  local_70 = *(long *)(lVar4 + 0x638);
  local_170[0xf0] = '\0';
  local_170[0xf1] = '\0';
  local_170[0xf2] = '\0';
  local_170[0xf3] = '\0';
  local_170[0xf4] = '\0';
  local_170[0xf5] = '\0';
  local_170[0xf6] = '\0';
  local_170[0xf7] = '\0';
  local_170[0xf8] = '\0';
  local_170[0xf9] = '\0';
  local_170[0xfa] = '\0';
  local_170[0xfb] = '\0';
  local_170[0xfc] = '\0';
  local_170[0xfd] = '\0';
  local_170[0xfe] = '\0';
  local_170[0xff] = '\0';
  local_170[0xe0] = '\0';
  local_170[0xe1] = '\0';
  local_170[0xe2] = '\0';
  local_170[0xe3] = '\0';
  local_170[0xe4] = '\0';
  local_170[0xe5] = '\0';
  local_170[0xe6] = '\0';
  local_170[0xe7] = '\0';
  local_170[0xe8] = '\0';
  local_170[0xe9] = '\0';
  local_170[0xea] = '\0';
  local_170[0xeb] = '\0';
  local_170[0xec] = '\0';
  local_170[0xed] = '\0';
  local_170[0xee] = '\0';
  local_170[0xef] = '\0';
  local_170[0xd0] = '\0';
  local_170[0xd1] = '\0';
  local_170[0xd2] = '\0';
  local_170[0xd3] = '\0';
  local_170[0xd4] = '\0';
  local_170[0xd5] = '\0';
  local_170[0xd6] = '\0';
  local_170[0xd7] = '\0';
  local_170[0xd8] = '\0';
  local_170[0xd9] = '\0';
  local_170[0xda] = '\0';
  local_170[0xdb] = '\0';
  local_170[0xdc] = '\0';
  local_170[0xdd] = '\0';
  local_170[0xde] = '\0';
  local_170[0xdf] = '\0';
  local_170[0xc0] = '\0';
  local_170[0xc1] = '\0';
  local_170[0xc2] = '\0';
  local_170[0xc3] = '\0';
  local_170[0xc4] = '\0';
  local_170[0xc5] = '\0';
  local_170[0xc6] = '\0';
  local_170[199] = '\0';
  local_170[200] = '\0';
  local_170[0xc9] = '\0';
  local_170[0xca] = '\0';
  local_170[0xcb] = '\0';
  local_170[0xcc] = '\0';
  local_170[0xcd] = '\0';
  local_170[0xce] = '\0';
  local_170[0xcf] = '\0';
  local_170[0xb0] = '\0';
  local_170[0xb1] = '\0';
  local_170[0xb2] = '\0';
  local_170[0xb3] = '\0';
  local_170[0xb4] = '\0';
  local_170[0xb5] = '\0';
  local_170[0xb6] = '\0';
  local_170[0xb7] = '\0';
  local_170[0xb8] = '\0';
  local_170[0xb9] = '\0';
  local_170[0xba] = '\0';
  local_170[0xbb] = '\0';
  local_170[0xbc] = '\0';
  local_170[0xbd] = '\0';
  local_170[0xbe] = '\0';
  local_170[0xbf] = '\0';
  local_170[0xa0] = '\0';
  local_170[0xa1] = '\0';
  local_170[0xa2] = '\0';
  local_170[0xa3] = '\0';
  local_170[0xa4] = '\0';
  local_170[0xa5] = '\0';
  local_170[0xa6] = '\0';
  local_170[0xa7] = '\0';
  local_170[0xa8] = '\0';
  local_170[0xa9] = '\0';
  local_170[0xaa] = '\0';
  local_170[0xab] = '\0';
  local_170[0xac] = '\0';
  local_170[0xad] = '\0';
  local_170[0xae] = '\0';
  local_170[0xaf] = '\0';
  local_170[0x90] = '\0';
  local_170[0x91] = '\0';
  local_170[0x92] = '\0';
  local_170[0x93] = '\0';
  local_170[0x94] = '\0';
  local_170[0x95] = '\0';
  local_170[0x96] = '\0';
  local_170[0x97] = '\0';
  local_170[0x98] = '\0';
  local_170[0x99] = '\0';
  local_170[0x9a] = '\0';
  local_170[0x9b] = '\0';
  local_170[0x9c] = '\0';
  local_170[0x9d] = '\0';
  local_170[0x9e] = '\0';
  local_170[0x9f] = '\0';
  local_170[0x80] = '\0';
  local_170[0x81] = '\0';
  local_170[0x82] = '\0';
  local_170[0x83] = '\0';
  local_170[0x84] = '\0';
  local_170[0x85] = '\0';
  local_170[0x86] = '\0';
  local_170[0x87] = '\0';
  local_170[0x88] = '\0';
  local_170[0x89] = '\0';
  local_170[0x8a] = '\0';
  local_170[0x8b] = '\0';
  local_170[0x8c] = '\0';
  local_170[0x8d] = '\0';
  local_170[0x8e] = '\0';
  local_170[0x8f] = '\0';
  local_170[0x70] = '\0';
  local_170[0x71] = '\0';
  local_170[0x72] = '\0';
  local_170[0x73] = '\0';
  local_170[0x74] = '\0';
  local_170[0x75] = '\0';
  local_170[0x76] = '\0';
  local_170[0x77] = '\0';
  local_170[0x78] = '\0';
  local_170[0x79] = '\0';
  local_170[0x7a] = '\0';
  local_170[0x7b] = '\0';
  local_170[0x7c] = '\0';
  local_170[0x7d] = '\0';
  local_170[0x7e] = '\0';
  local_170[0x7f] = '\0';
  local_170[0x60] = '\0';
  local_170[0x61] = '\0';
  local_170[0x62] = '\0';
  local_170[99] = '\0';
  local_170[100] = '\0';
  local_170[0x65] = '\0';
  local_170[0x66] = '\0';
  local_170[0x67] = '\0';
  local_170[0x68] = '\0';
  local_170[0x69] = '\0';
  local_170[0x6a] = '\0';
  local_170[0x6b] = '\0';
  local_170[0x6c] = '\0';
  local_170[0x6d] = '\0';
  local_170[0x6e] = '\0';
  local_170[0x6f] = '\0';
  local_170[0x50] = '\0';
  local_170[0x51] = '\0';
  local_170[0x52] = '\0';
  local_170[0x53] = '\0';
  local_170[0x54] = '\0';
  local_170[0x55] = '\0';
  local_170[0x56] = '\0';
  local_170[0x57] = '\0';
  local_170[0x58] = '\0';
  local_170[0x59] = '\0';
  local_170[0x5a] = '\0';
  local_170[0x5b] = '\0';
  local_170[0x5c] = '\0';
  local_170[0x5d] = '\0';
  local_170[0x5e] = '\0';
  local_170[0x5f] = '\0';
  local_170[0x40] = '\0';
  local_170[0x41] = '\0';
  local_170[0x42] = '\0';
  local_170[0x43] = '\0';
  local_170[0x44] = '\0';
  local_170[0x45] = '\0';
  local_170[0x46] = '\0';
  local_170[0x47] = '\0';
  local_170[0x48] = '\0';
  local_170[0x49] = '\0';
  local_170[0x4a] = '\0';
  local_170[0x4b] = '\0';
  local_170[0x4c] = '\0';
  local_170[0x4d] = '\0';
  local_170[0x4e] = '\0';
  local_170[0x4f] = '\0';
  local_170[0x30] = '\0';
  local_170[0x31] = '\0';
  local_170[0x32] = '\0';
  local_170[0x33] = '\0';
  local_170[0x34] = '\0';
  local_170[0x35] = '\0';
  local_170[0x36] = '\0';
  local_170[0x37] = '\0';
  local_170[0x38] = '\0';
  local_170[0x39] = '\0';
  local_170[0x3a] = '\0';
  local_170[0x3b] = '\0';
  local_170[0x3c] = '\0';
  local_170[0x3d] = '\0';
  local_170[0x3e] = '\0';
  local_170[0x3f] = '\0';
  local_170[0x20] = '\0';
  local_170[0x21] = '\0';
  local_170[0x22] = '\0';
  local_170[0x23] = '\0';
  local_170[0x24] = '\0';
  local_170[0x25] = '\0';
  local_170[0x26] = '\0';
  local_170[0x27] = '\0';
  local_170[0x28] = '\0';
  local_170[0x29] = '\0';
  local_170[0x2a] = '\0';
  local_170[0x2b] = '\0';
  local_170[0x2c] = '\0';
  local_170[0x2d] = '\0';
  local_170[0x2e] = '\0';
  local_170[0x2f] = '\0';
  local_170[0x10] = '\0';
  local_170[0x11] = '\0';
  local_170[0x12] = '\0';
  local_170[0x13] = '\0';
  local_170[0x14] = '\0';
  local_170[0x15] = '\0';
  local_170[0x16] = '\0';
  local_170[0x17] = '\0';
  local_170[0x18] = '\0';
  local_170[0x19] = '\0';
  local_170[0x1a] = '\0';
  local_170[0x1b] = '\0';
  local_170[0x1c] = '\0';
  local_170[0x1d] = '\0';
  local_170[0x1e] = '\0';
  local_170[0x1f] = '\0';
  local_170[0] = '\0';
  local_170[1] = '\0';
  local_170[2] = '\0';
  local_170[3] = '\0';
  local_170[4] = '\0';
  local_170[5] = '\0';
  local_170[6] = '\0';
  local_170[7] = '\0';
  local_170[8] = '\0';
  local_170[9] = '\0';
  local_170[10] = '\0';
  local_170[0xb] = '\0';
  local_170[0xc] = '\0';
  local_170[0xd] = '\0';
  local_170[0xe] = '\0';
  local_170[0xf] = '\0';
  snprintf(local_170,0x100,"%s%llx","gpi_dma",**(ulonglong **)(param_1 + 0x188));
  uVar2 = ipc_log_context_create(4,local_170,0);
  *(undefined8 *)(param_1 + 0x1d0) = uVar2;
  uVar3 = pdentry;
  *(undefined4 *)(param_1 + 0x1d8) = 2;
  if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
    snprintf(local_170,0x100,"%llx",**(undefined8 **)(param_1 + 0x188));
    uVar3 = debugfs_create_dir(local_170,pdentry);
    *(ulong *)(param_1 + 0x1e0) = uVar3;
    if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
      debugfs_create_u32("ipc_log_lvl",0x180,uVar3,param_1 + 0x1d8);
      debugfs_create_u32("klog_lvl",0x180,*(undefined8 *)(param_1 + 0x1e0),param_1 + 0x1dc);
    }
  }
  if (*(int *)(param_1 + 0x1a0) != 0) {
    param5 = 0;
    do {
      uVar1 = 1 << (ulong)(param5 & 0x1f);
      if (((*(uint *)(param_1 + 0x1a4) & uVar1) != 0) || ((*(uint *)(param_1 + 0x1a8) & uVar1) != 0)
         ) {
        lVar4 = *(long *)(param_1 + 0x1c8);
        lVar5 = lVar4 + (long)(int)param5 * 0x5c8;
        snprintf((char *)(lVar5 + 0x434),0x100,"%s%llx_gpii%d","gpi_dma",
                 **(ulonglong **)(param_1 + 0x188),param5);
        uVar2 = ipc_log_context_create(4,(char *)(lVar5 + 0x434),0);
        *(undefined8 *)(lVar5 + 0x428) = 0x100000002;
        *(undefined8 *)(lVar5 + 0x420) = uVar2;
        if ((*(ulong *)(param_1 + 0x1e0) != 0) && (*(ulong *)(param_1 + 0x1e0) < 0xfffffffffffff001)
           ) {
          snprintf(local_170,0x100,"gpii%d",param5);
          uVar3 = debugfs_create_dir(local_170,*(undefined8 *)(param_1 + 0x1e0));
          lVar4 = lVar4 + (long)(int)param5 * 0x5c8;
          *(ulong *)(lVar4 + 0x538) = uVar3;
          if ((uVar3 != 0) && (uVar3 < 0xfffffffffffff001)) {
            debugfs_create_u32("ipc_log_lvl",0x180,uVar3,lVar5 + 0x428);
            debugfs_create_u32("klog_lvl",0x180,*(undefined8 *)(lVar4 + 0x538),lVar5 + 0x42c);
          }
        }
      }
      param5 = param5 + 1;
    } while (param5 < *(uint *)(param_1 + 0x1a0));
  }
  lVar4 = sp_el0;
  if (*(long *)(lVar4 + 0x638) != local_70) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gpi_process_events @ 001085dc size=4284
// signature: undefined gpi_process_events(void)
// callers: [gpi_ev_tasklet, gpi_handle_irq]
//------------------------------------------------------------

void gpi_process_events(long param_1)

{
  ulong uVar1;
  ulong uVar2;
  undefined4 *puVar3;
  ulong uVar4;
  long *plVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  code *pcVar9;
  ulong uVar10;
  undefined8 uVar11;
  uint *puVar12;
  long lVar13;
  char *pcVar14;
  int iVar15;
  long lVar16;
  int iVar17;
  long lVar18;
  uint *puVar19;
  long lVar20;
  long lVar21;
  long *plVar22;
  long *plVar23;
  long lVar24;
  uint *puVar25;
  long lVar26;
  uint uVar27;
  uint uVar29;
  uint uVar28;
  long *plVar30;
  undefined8 local_a8;
  ulong local_a0;
  ulong local_98;
  ulong local_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar16 = sp_el0;
  local_68 = *(long *)(lVar16 + 0x638);
  lVar24 = *(long *)(param_1 + 0x3c0);
  uVar10 = readl_relaxed(*(undefined8 *)(param_1 + 0x350));
  lVar16 = *(long *)(lVar24 + 0x20);
  lVar18 = *(long *)(lVar24 + 0x10);
  puVar25 = *(uint **)(lVar24 + 0x30);
  puVar19 = (uint *)((lVar16 - lVar18) + (uVar10 & 0xffffffff));
  do {
    iVar15 = (int)lVar16;
    iVar17 = (int)lVar18;
    if (puVar19 != puVar25) {
      do {
        bVar6 = *(byte *)((long)puVar25 + 0xf);
        bVar7 = *(byte *)((long)puVar25 + 0xe);
        uVar27 = (uint)bVar6;
        if (1 < bVar6) {
          if (*(uint *)(param_1 + 0x42c) < 2) {
            lVar16 = *(long *)(param_1 + 0x420);
          }
          else {
            _printk(&DAT_0010d570,param_1 + 0x434,99,"gpi_process_events",bVar6);
            lVar16 = *(long *)(param_1 + 0x420);
          }
          if ((lVar16 != 0) && (1 < *(uint *)(param_1 + 0x428))) {
            ipc_log_string(lVar16,"ch:%u %s: gpii channel:%d not valid\n",99,"gpi_process_events",
                           uVar27);
          }
          writel_relaxed(1,*(undefined8 *)(param_1 + 0x370));
          gpi_generate_cb_event(param_1 + 8,3,(uint)bVar7 << 8);
          gpi_generate_cb_event(param_1 + 400,3,(uint)bVar7 << 8 | 1);
          goto LAB_00109630;
        }
        if (bVar7 - 0x22 < 0x15) {
          uVar28 = (uint)bVar6;
          uVar29 = (uint)bVar6;
          switch((uint)bVar7) {
          case 0x22:
            lVar18 = param_1 + (ulong)uVar29 * 0x188;
            uVar28 = *(uint *)(lVar18 + 300);
            lVar16 = *(long *)(lVar18 + 0x120);
            if (uVar28 == 3) {
              lVar21 = *(long *)(lVar18 + 0x168);
              lVar13 = lVar18 + 0xa8;
              lVar20 = *(long *)(lVar21 + 0x20) + (*(long *)puVar25 - *(long *)(lVar21 + 0x10));
              uVar11 = _raw_spin_lock_irqsave(lVar13);
              plVar23 = (long *)(lVar18 + 0xd0);
              plVar22 = (long *)*plVar23;
              _raw_spin_unlock_irqrestore(lVar13,uVar11);
              uVar28 = (uint)bVar6;
              if ((plVar22 == plVar23) || (plVar22 == (long *)0x98)) {
                uVar10 = lVar20 + (ulong)*(uint *)(lVar21 + 0x3c);
                if (*(ulong *)(lVar21 + 0x20) + (ulong)*(uint *)(lVar21 + 0x38) <= uVar10) {
                  uVar10 = *(ulong *)(lVar21 + 0x20);
                }
                *(ulong *)(lVar21 + 0x30) = uVar10;
                if (1 < *(uint *)(lVar16 + 0x42c)) {
                  _printk(&DAT_0010c277,lVar16 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                          "gpi_process_xfer_compl_event");
                }
                if ((*(long *)(lVar16 + 0x420) != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                  ipc_log_string(*(long *)(lVar16 + 0x420),
                                 "ch:%u %s: Event without a pending descriptor!\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                 "gpi_process_xfer_compl_event");
                }
                if (*(uint *)(lVar16 + 0x42c) < 2) {
                  lVar13 = *(long *)(lVar16 + 0x420);
                }
                else {
                  _printk(&DAT_0010d447,lVar16 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                          "gpi_process_xfer_compl_event",*puVar25,puVar25[1],puVar25[2],puVar25[3]);
                  lVar13 = *(long *)(lVar16 + 0x420);
                }
                if ((lVar13 != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                  ipc_log_string(lVar13,"ch:%u %s: Event: %08x %08x %08x %08x\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                                 "gpi_process_xfer_compl_event",*puVar25,puVar25[1],puVar25[2],
                                 puVar25[3]);
                }
                if (*(char *)(lVar16 + 0x5c0) == '\0') {
                  gpi_generate_cb_event(lVar18 + 8,5,0x970);
                }
              }
              else {
                if (*(char *)(lVar16 + 0x5c3) != '\0') {
                  *(int *)(lVar16 + 0x5c4) = *(int *)(lVar16 + 0x5c4) + -1;
                }
                uVar10 = lVar20 + (ulong)*(uint *)(lVar21 + 0x3c);
                if (*(ulong *)(lVar21 + 0x20) + (ulong)*(uint *)(lVar21 + 0x38) <= uVar10) {
                  uVar10 = *(ulong *)(lVar21 + 0x20);
                }
                *(ulong *)(lVar21 + 0x30) = uVar10;
                DataMemoryBarrier(2,2);
                if (*(char *)(lVar16 + 0x5c0) == '\0') {
                  if ((*(char *)((long)puVar25 + 0xb) == '\x04') &&
                     (((*(int *)(param_1 + (ulong)uVar27 * 0x188 + 0x18c) != 1 ||
                       (*(int *)(param_1 + (ulong)uVar27 * 0x188 + 0x188) == 0)) &&
                      (*(int *)(lVar16 + 0x324) != 2)))) goto LAB_001090a4;
LAB_00109004:
                  lVar18 = plVar22[-0xe];
joined_r0x001093ec:
                  if (lVar18 != 0) {
LAB_0010900c:
                    puVar12 = (uint *)plVar22[-0xc];
                    if (puVar12 != (uint *)0x0) {
                      *puVar12 = (uint)(uint3)puVar25[2];
                      puVar12[1] = (uint)*(byte *)((long)puVar25 + 0xb);
                      puVar12[2] = (uint)(ushort)puVar25[3];
                      puVar12[10] = (uint)*(byte *)((long)puVar25 + 0xe);
                      if (*(uint *)(lVar16 + 0x42c) < 3) {
                        lVar18 = *(long *)(lVar16 + 0x420);
                      }
                      else {
                        _printk(&DAT_0010d2bc,lVar16 + 0x434,
                                *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                "gpi_process_xfer_compl_event",puVar12);
                        lVar18 = *(long *)(lVar16 + 0x420);
                      }
                      if ((lVar18 != 0) && (2 < *(uint *)(lVar16 + 0x428))) {
                        ipc_log_string(lVar18,"ch:%u %s: tx_cb_param:%p\n",
                                       *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                       "gpi_process_xfer_compl_event",puVar12);
                      }
                      if (*(int *)((code *)plVar22[-0xe] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1090a0);
                        (*pcVar9)();
                      }
                      (*(code *)plVar22[-0xe])(puVar12);
                    }
                  }
LAB_001090a4:
                  uVar11 = _raw_spin_lock_irqsave(lVar13);
                  plVar22 = (long *)*plVar23;
                  if ((plVar22 == plVar23) || (plVar22 + -0x13 == (long *)0x0)) goto LAB_00109108;
                  uVar10 = __list_del_entry_valid(plVar22);
                  if ((uVar10 & 1) != 0) {
                    lVar16 = *plVar22;
                    plVar23 = (long *)plVar22[1];
                    *(long **)(lVar16 + 8) = plVar23;
                    *plVar23 = lVar16;
                  }
                  *plVar22 = -0x2152ffffffffff00;
                  plVar22[1] = -0x2152fffffffffede;
                  _raw_spin_unlock_irqrestore(lVar13,uVar11);
                  kfree(plVar22 + -0x13);
                }
                else if (*(char *)(lVar16 + 0x5c3) == '\0') {
                  cVar8 = *(char *)((long)puVar25 + 0xb);
                  if (*(char *)((long)puVar25 + 0xf) == '\x01') {
                    if (cVar8 != '\x02') {
                      if (cVar8 != '\x10') break;
                      uVar11 = _raw_spin_lock_irqsave();
                      plVar30 = *(long **)(lVar16 + 0xd0);
                      if ((plVar30 == (long *)(lVar16 + 0xd0)) || (plVar30 + -0x13 == (long *)0x0))
                      {
                        _raw_spin_unlock_irqrestore(lVar16 + 0xa8);
                        lVar18 = plVar22[-0xe];
                        goto joined_r0x001093ec;
                      }
                      uVar10 = __list_del_entry_valid(plVar30);
                      if ((uVar10 & 1) != 0) {
                        lVar18 = *plVar30;
                        plVar5 = (long *)plVar30[1];
                        *(long **)(lVar18 + 8) = plVar5;
                        *plVar5 = lVar18;
                      }
                      *plVar30 = -0x2152ffffffffff00;
                      plVar30[1] = -0x2152fffffffffede;
                      _raw_spin_unlock_irqrestore(lVar16 + 0xa8,uVar11);
                      kfree(plVar30 + -0x13);
                      if (plVar22[-0xe] == 0) goto LAB_001090a4;
                      goto LAB_0010900c;
                    }
                    goto LAB_001090a4;
                  }
                  if (cVar8 != '\x02') goto LAB_00109004;
                }
                else if (*(int *)(lVar16 + 0x5c4) != 0) goto LAB_00109004;
              }
            }
            else {
              if (*(uint *)(lVar16 + 0x42c) < 2) {
                lVar13 = *(long *)(lVar16 + 0x420);
              }
              else {
                pcVar14 = "INVALID";
                if (uVar28 < 6) {
                  pcVar14 = (&gpi_pm_state_str)[uVar28];
                }
                _printk(&DAT_0010b8f7,lVar16 + 0x434,
                        *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                        "gpi_process_xfer_compl_event",pcVar14);
                lVar13 = *(long *)(lVar16 + 0x420);
              }
              if ((lVar13 != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                pcVar14 = "INVALID";
                if (*(uint *)(lVar18 + 300) < 6) {
                  pcVar14 = (&gpi_pm_state_str)[*(uint *)(lVar18 + 300)];
                }
                ipc_log_string(lVar13,"ch:%u %s: skipping processing event because ch @ %s state\n",
                               *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                               "gpi_process_xfer_compl_event",pcVar14);
              }
              gpi_generate_cb_event(lVar18 + 8,4,0x952);
            }
            break;
          case 0x30:
            lVar16 = param_1 + (ulong)uVar29 * 0x188;
            uVar27 = *(uint *)(lVar16 + 300);
            lVar18 = *(long *)(lVar16 + 0x120);
            if (uVar27 == 3) {
              lVar21 = *(long *)(lVar16 + 0x168);
              lVar13 = lVar16 + 0xa8;
              lVar20 = *(long *)(lVar21 + 0x20) +
                       (ulong)(*(int *)(lVar21 + 0x3c) * (uint)*(ushort *)((long)puVar25 + 9));
              uVar11 = _raw_spin_lock_irqsave(lVar13);
              plVar23 = (long *)(lVar16 + 0xd0);
              plVar22 = (long *)*plVar23;
              _raw_spin_unlock_irqrestore(lVar13,uVar11);
              if ((plVar22 == plVar23) || (plVar22 == (long *)0x98)) {
                puVar3 = (undefined4 *)(lVar20 + (ulong)*(uint *)(lVar21 + 0x3c));
                if ((undefined4 *)
                    ((long)*(undefined4 **)(lVar21 + 0x20) + (ulong)*(uint *)(lVar21 + 0x38)) <=
                    puVar3) {
                  puVar3 = *(undefined4 **)(lVar21 + 0x20);
                }
                *(undefined4 **)(lVar21 + 0x30) = puVar3;
                if (1 < *(uint *)(lVar18 + 0x42c)) {
                  _printk(&DAT_0010def6,lVar18 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                          "gpi_process_imed_data_event");
                }
                if ((*(long *)(lVar18 + 0x420) != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                  ipc_log_string(*(long *)(lVar18 + 0x420),
                                 "ch:%u %s: event without a pending descriptor!\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                 "gpi_process_imed_data_event");
                }
                if (*(uint *)(lVar18 + 0x42c) < 2) {
                  lVar13 = *(long *)(lVar18 + 0x420);
                }
                else {
                  _printk(&DAT_0010d447,lVar18 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                          "gpi_process_imed_data_event",*puVar25,puVar25[1],puVar25[2],puVar25[3]);
                  lVar13 = *(long *)(lVar18 + 0x420);
                }
                if ((lVar13 != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                  ipc_log_string(lVar13,"ch:%u %s: Event: %08x %08x %08x %08x\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                 "gpi_process_imed_data_event",*puVar25,puVar25[1],puVar25[2],
                                 puVar25[3]);
                }
                if (*(uint *)(lVar18 + 0x42c) < 2) {
                  lVar13 = *(long *)(lVar18 + 0x420);
                }
                else {
                  _printk(&DAT_0010c96d,lVar18 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                          "gpi_process_imed_data_event",*puVar3,puVar3[1],puVar3[2],puVar3[3]);
                  lVar13 = *(long *)(lVar18 + 0x420);
                }
                if ((lVar13 != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                  ipc_log_string(lVar13,"ch:%u %s: Pending TRE: %08x %08x %08x %08x\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                                 "gpi_process_imed_data_event",*puVar3,puVar3[1],puVar3[2],puVar3[3]
                                );
                }
                if (*(char *)(lVar18 + 0x5c0) == '\0') {
                  gpi_generate_cb_event(lVar16 + 8,5,0x8ee);
                }
              }
              else {
                if (*(char *)(lVar18 + 0x5c3) != '\0') {
                  *(int *)(lVar18 + 0x5c4) = *(int *)(lVar18 + 0x5c4) + -1;
                }
                uVar10 = lVar20 + (ulong)*(uint *)(lVar21 + 0x3c);
                if (*(ulong *)(lVar21 + 0x20) + (ulong)*(uint *)(lVar21 + 0x38) <= uVar10) {
                  uVar10 = *(ulong *)(lVar21 + 0x20);
                }
                *(ulong *)(lVar21 + 0x30) = uVar10;
                DataMemoryBarrier(2,2);
                if (*(char *)(lVar18 + 0x5c0) == '\0') {
                  if (*(char *)((long)puVar25 + 0xb) == '\x04') goto LAB_001092e0;
LAB_00109288:
                  lVar16 = plVar22[-0xe];
joined_r0x00109434:
                  if (lVar16 != 0) {
LAB_00109290:
                    puVar12 = (uint *)plVar22[-0xc];
                    if (puVar12 != (uint *)0x0) {
                      uVar11 = *(undefined8 *)(puVar25 + 2);
                      *(undefined8 *)(puVar12 + 3) = *(undefined8 *)puVar25;
                      *(undefined8 *)(puVar12 + 5) = uVar11;
                      *puVar12 = (byte)puVar25[2] & 0xf;
                      puVar12[1] = (uint)*(byte *)((long)puVar25 + 0xb);
                      puVar12[2] = (uint)(ushort)puVar25[3];
                      if (*(int *)((code *)plVar22[-0xe] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                        pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x1092dc);
                        (*pcVar9)();
                      }
                      (*(code *)plVar22[-0xe])();
                    }
                  }
LAB_001092e0:
                  uVar11 = _raw_spin_lock_irqsave(lVar13);
                  plVar22 = (long *)*plVar23;
                  if ((plVar22 == plVar23) || (plVar22 + -0x13 == (long *)0x0)) goto LAB_00109108;
                  uVar10 = __list_del_entry_valid(plVar22);
                  if ((uVar10 & 1) != 0) {
                    lVar16 = *plVar22;
                    plVar23 = (long *)plVar22[1];
                    *(long **)(lVar16 + 8) = plVar23;
                    *plVar23 = lVar16;
                  }
                  *plVar22 = -0x2152ffffffffff00;
                  plVar22[1] = -0x2152fffffffffede;
                  _raw_spin_unlock_irqrestore(lVar13,uVar11);
                  kfree(plVar22 + -0x13);
                }
                else if (*(char *)(lVar18 + 0x5c3) == '\0') {
                  cVar8 = *(char *)((long)puVar25 + 0xb);
                  if (*(char *)((long)puVar25 + 0xf) == '\x01') {
                    if (cVar8 != '\x02') {
                      if (cVar8 != '\x10') break;
                      lVar16 = lVar18 + 0xa8;
                      uVar11 = _raw_spin_lock_irqsave(lVar16);
                      plVar30 = *(long **)(lVar18 + 0xd0);
                      if ((plVar30 == (long *)(lVar18 + 0xd0)) || (plVar30 + -0x13 == (long *)0x0))
                      {
                        _raw_spin_unlock_irqrestore(lVar16);
                        lVar16 = plVar22[-0xe];
                        goto joined_r0x00109434;
                      }
                      uVar10 = __list_del_entry_valid(plVar30);
                      if ((uVar10 & 1) != 0) {
                        lVar18 = *plVar30;
                        plVar5 = (long *)plVar30[1];
                        *(long **)(lVar18 + 8) = plVar5;
                        *plVar5 = lVar18;
                      }
                      *plVar30 = -0x2152ffffffffff00;
                      plVar30[1] = -0x2152fffffffffede;
                      _raw_spin_unlock_irqrestore(lVar16,uVar11);
                      kfree(plVar30 + -0x13);
                      if (plVar22[-0xe] == 0) goto LAB_001092e0;
                      goto LAB_00109290;
                    }
                    goto LAB_001092e0;
                  }
                  if (cVar8 != '\x02') goto LAB_00109288;
                }
                else if (*(int *)(lVar18 + 0x5c4) != 0) goto LAB_00109288;
              }
            }
            else {
              if (*(uint *)(lVar18 + 0x42c) < 2) {
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              else {
                pcVar14 = "INVALID";
                if (uVar27 < 6) {
                  pcVar14 = (&gpi_pm_state_str)[uVar27];
                }
                _printk(&DAT_0010b8f7,lVar18 + 0x434,
                        *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                        "gpi_process_imed_data_event",pcVar14);
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              if ((lVar13 != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                pcVar14 = "INVALID";
                if (*(uint *)(lVar16 + 300) < 6) {
                  pcVar14 = (&gpi_pm_state_str)[*(uint *)(lVar16 + 300)];
                }
                ipc_log_string(lVar13,"ch:%u %s: skipping processing event because ch @ %s state\n",
                               *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                               "gpi_process_imed_data_event",pcVar14);
              }
              gpi_generate_cb_event(lVar16 + 8,4,0x8ca);
            }
            break;
          case 0x31:
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            local_a8 = 0;
            local_a0 = (ulong)*puVar25;
            local_98 = (ulong)puVar25[1];
            lVar16 = param_1 + (ulong)uVar28 * 0x188;
            local_90 = (ulong)(uint3)puVar25[2];
            if (*(int *)(*(code **)(lVar16 + 0x178) + -4) != 0x437bfba3) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x822a,0x108934);
              (*pcVar9)();
            }
            (**(code **)(lVar16 + 0x178))(lVar16 + 8,&local_a8,*(undefined8 *)(lVar16 + 0x180));
            break;
          case 0x35:
            lVar18 = param_1 + (ulong)uVar29 * 0x188;
            uVar27 = *(uint *)(lVar18 + 300);
            lVar16 = *(long *)(lVar18 + 0x120);
            if (uVar27 == 3) {
              lVar20 = *(long *)(lVar18 + 0x168);
              lVar13 = lVar18 + 0xa8;
              uVar27 = *puVar25;
              lVar26 = *(long *)(lVar20 + 0x20);
              lVar21 = *(long *)(lVar20 + 0x10);
              uVar11 = _raw_spin_lock_irqsave(lVar13);
              plVar22 = (long *)(lVar18 + 0xd0);
              plVar23 = (long *)*plVar22;
              _raw_spin_unlock_irqrestore(lVar13,uVar11);
              if ((plVar23 == plVar22) || (plVar23 == (long *)0x98)) {
                if (1 < *(uint *)(lVar16 + 0x42c)) {
                  _printk(&DAT_0010c277,lVar16 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                          "gpi_process_qup_q2spi_status");
                }
                if ((*(long *)(lVar16 + 0x420) != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                  ipc_log_string(*(long *)(lVar16 + 0x420),
                                 "ch:%u %s: Event without a pending descriptor!\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                 "gpi_process_qup_q2spi_status");
                }
                if (*(uint *)(lVar16 + 0x42c) < 2) {
                  lVar13 = *(long *)(lVar16 + 0x420);
                }
                else {
                  _printk(&DAT_0010d447,lVar16 + 0x434,
                          *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                          "gpi_process_qup_q2spi_status",*puVar25,puVar25[1],puVar25[2],puVar25[3]);
                  lVar13 = *(long *)(lVar16 + 0x420);
                }
                if ((lVar13 != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                  ipc_log_string(lVar13,"ch:%u %s: Event: %08x %08x %08x %08x\n",
                                 *(undefined4 *)(param_1 + (ulong)uVar28 * 0x188 + 0x108),
                                 "gpi_process_qup_q2spi_status",*puVar25,puVar25[1],puVar25[2],
                                 puVar25[3]);
                }
                gpi_generate_cb_event(lVar18 + 8,5,0x9e0);
              }
              else {
                uVar10 = (lVar26 - lVar21) + (ulong)uVar27 + (ulong)*(uint *)(lVar20 + 0x3c);
                if (*(ulong *)(lVar20 + 0x20) + (ulong)*(uint *)(lVar20 + 0x38) <= uVar10) {
                  uVar10 = *(ulong *)(lVar20 + 0x20);
                }
                *(ulong *)(lVar20 + 0x30) = uVar10;
                DataMemoryBarrier(2,2);
                if ((((*(ulong *)(puVar25 + 1) >> 0x38 != 4) || (*(int *)(lVar16 + 0x324) == 0xe))
                    && (plVar23[-0xe] != 0)) &&
                   (puVar12 = (uint *)plVar23[-0xc], puVar12 != (uint *)0x0)) {
                  *puVar12 = (uint)(*(ulong *)(puVar25 + 1) >> 0x20) & 0xfffff;
                  puVar12[1] = (uint)*(byte *)((long)puVar25 + 0xb);
                  puVar12[10] = (uint)*(byte *)((long)puVar25 + 0xe);
                  puVar12[2] = (uint)(ushort)puVar25[3];
                  *(undefined1 *)(puVar12 + 0xb) = *(undefined1 *)((long)puVar25 + 6);
                  if (*(int *)((code *)plVar23[-0xe] + -4) != -0x5b771404) {
                    /* WARNING: Does not return */
                    pcVar9 = (code *)SoftwareBreakpoint(0x8228,0x108a3c);
                    (*pcVar9)();
                  }
                  (*(code *)plVar23[-0xe])();
                }
                uVar11 = _raw_spin_lock_irqsave(lVar13);
                plVar23 = (long *)*plVar22;
                if ((plVar23 == plVar22) || (plVar23 + -0x13 == (long *)0x0)) {
LAB_00109108:
                  _raw_spin_unlock_irqrestore(lVar13,uVar11);
                }
                else {
                  uVar10 = __list_del_entry_valid(plVar23);
                  if ((uVar10 & 1) != 0) {
                    lVar16 = *plVar23;
                    plVar22 = (long *)plVar23[1];
                    *(long **)(lVar16 + 8) = plVar22;
                    *plVar22 = lVar16;
                  }
                  *plVar23 = -0x2152ffffffffff00;
                  plVar23[1] = -0x2152fffffffffede;
                  _raw_spin_unlock_irqrestore(lVar13,uVar11);
                  kfree(plVar23 + -0x13);
                }
              }
            }
            else {
              if (*(uint *)(lVar16 + 0x42c) < 2) {
                lVar13 = *(long *)(lVar16 + 0x420);
              }
              else {
                pcVar14 = "INVALID";
                if (uVar27 < 6) {
                  pcVar14 = (&gpi_pm_state_str)[uVar27];
                }
                _printk(&DAT_0010b8f7,lVar16 + 0x434,
                        *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                        "gpi_process_qup_q2spi_status",pcVar14);
                lVar13 = *(long *)(lVar16 + 0x420);
              }
              if ((lVar13 != 0) && (1 < *(uint *)(lVar16 + 0x428))) {
                pcVar14 = "INVALID";
                if (*(uint *)(lVar18 + 300) < 6) {
                  pcVar14 = (&gpi_pm_state_str)[*(uint *)(lVar18 + 300)];
                }
                ipc_log_string(lVar13,"ch:%u %s: skipping processing event because ch @ %s state\n",
                               *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                               "gpi_process_qup_q2spi_status",pcVar14);
              }
              gpi_generate_cb_event(lVar18 + 8,4,0x9d0);
            }
            break;
          case 0x36:
            local_78 = 0;
            uStack_70 = 0;
            local_88 = 0;
            uStack_80 = 0;
            lVar16 = param_1 + (ulong)uVar27 * 0x188;
            local_98 = 0;
            local_90 = 0;
            local_a8 = 0;
            local_a0 = 0;
            lVar18 = *(long *)(lVar16 + 0x120);
            if ((ulong)*(byte *)((long)puVar25 + 0xb) * -0x1000000 == -0xb000000) {
              if (*(uint *)(lVar18 + 0x42c) < 2) {
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              else {
                _printk(&DAT_0010b68b,lVar18 + 0x434,
                        *(undefined4 *)(param_1 + (ulong)uVar27 * 0x188 + 0x108),
                        "gpi_process_xfer_q2spi_cr_header");
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              if ((lVar13 != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                ipc_log_string(lVar13,"ch:%u %s: Err negative 1H doorbell response\n",
                               *(undefined4 *)(param_1 + (ulong)uVar27 * 0x188 + 0x108),
                               "gpi_process_xfer_q2spi_cr_header");
              }
            }
            if ((ulong)*(byte *)((long)puVar25 + 0xb) * -0x1000000 == -0xc000000) {
              if (*(uint *)(lVar18 + 0x42c) < 2) {
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              else {
                _printk(&DAT_0010df27,lVar18 + 0x434,
                        *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                        "gpi_process_xfer_q2spi_cr_header");
                lVar13 = *(long *)(lVar18 + 0x420);
              }
              if ((lVar13 != 0) && (1 < *(uint *)(lVar18 + 0x428))) {
                ipc_log_string(lVar13,"ch:%u %s: Err unexpected CR Header is received\n",
                               *(undefined4 *)(param_1 + (ulong)uVar29 * 0x188 + 0x108),
                               "gpi_process_xfer_q2spi_cr_header");
              }
            }
            lVar18 = param_1 + (ulong)bVar6 * 0x188;
            local_a8 = CONCAT44(local_a8._4_4_,7);
            pcVar9 = *(code **)(lVar18 + 0x178);
            local_78._0_4_ = (undefined4)((ulong)*(undefined8 *)puVar25 >> 0x20);
            uStack_70._0_4_ = (undefined4)((ulong)*(undefined8 *)(puVar25 + 2) >> 0x20);
            if (*(int *)(pcVar9 + -4) != 0x437bfba3) {
                    /* WARNING: Does not return */
              pcVar9 = (code *)SoftwareBreakpoint(0x822b,0x1086e8);
              (*pcVar9)();
            }
            (*pcVar9)(lVar16 + 8,&local_a8,*(undefined8 *)(lVar18 + 0x180));
          }
        }
        uVar4 = *(ulong *)(lVar24 + 0x20);
        uVar10 = *(long *)(lVar24 + 0x28) + (ulong)*(uint *)(lVar24 + 0x3c);
        uVar1 = uVar4 + *(uint *)(lVar24 + 0x38);
        uVar2 = *(long *)(lVar24 + 0x30) + (ulong)*(uint *)(lVar24 + 0x3c);
        if (uVar1 <= uVar10) {
          uVar10 = uVar4;
        }
        if (uVar1 <= uVar2) {
          uVar2 = uVar4;
        }
        *(ulong *)(lVar24 + 0x28) = uVar10;
        *(ulong *)(lVar24 + 0x30) = uVar2;
        DataMemoryBarrier(2,2);
        puVar25 = *(uint **)(lVar24 + 0x30);
      } while (puVar19 != puVar25);
      iVar17 = (int)*(undefined8 *)(lVar24 + 0x10);
      iVar15 = (int)*(undefined8 *)(lVar24 + 0x20);
    }
    writel_relaxed((iVar17 + *(int *)(lVar24 + 0x28)) - iVar15,*(undefined8 *)(param_1 + 0x340));
    writel_relaxed(1,*(undefined8 *)(param_1 + 0x370));
    uVar10 = readl_relaxed(*(undefined8 *)(param_1 + 0x350));
    lVar16 = *(long *)(lVar24 + 0x20);
    lVar18 = *(long *)(lVar24 + 0x10);
    puVar25 = *(uint **)(lVar24 + 0x30);
    puVar19 = (uint *)((lVar16 - lVar18) + (uVar10 & 0xffffffff));
  } while (puVar19 != puVar25);
LAB_00109630:
  lVar16 = sp_el0;
  if (*(long *)(lVar16 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gpi_config_interrupts @ 00109698 size=656
// signature: undefined gpi_config_interrupts(void)
// callers: [gpi_config, gpi_resume, gpi_handle_irq, gpi_ev_tasklet]
//------------------------------------------------------------

int gpi_config_interrupts(int *param_1,int param_2,ulong param_3)

{
  long lVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  long lVar7;
  uint local_128;
  undefined8 local_124;
  int local_11c [2];
  undefined8 local_114;
  undefined4 local_10c;
  uint uStack_108;
  undefined8 local_104;
  undefined4 local_fc;
  uint uStack_f8;
  undefined8 local_f4;
  undefined4 local_ec;
  int iStack_e8;
  undefined8 local_e4;
  undefined4 local_dc;
  int iStack_d8;
  undefined8 local_d4;
  undefined4 local_cc;
  uint uStack_c8;
  undefined8 local_c4;
  undefined4 local_bc;
  uint uStack_b8;
  undefined8 local_b4;
  undefined4 local_ac;
  int iStack_a8;
  undefined8 local_a4;
  undefined4 local_9c;
  int iStack_98;
  undefined8 local_94;
  undefined4 local_8c;
  int iStack_88;
  undefined8 local_84;
  undefined4 local_7c;
  int iStack_78;
  undefined4 local_74;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  long local_58;
  
  lVar7 = sp_el0;
  local_58 = *(long *)(lVar7 + 0x638);
  local_104 = 3;
  local_114 = 1;
  local_124 = 0x7f;
  iVar4 = *param_1 * 0x4000;
  local_128 = iVar4 + 0x23088;
  local_f4 = 1;
  local_11c[0] = 0x4f;
  local_11c[1] = local_128 | 0x30;
  local_10c = 1;
  uStack_108 = local_128 | 0x10;
  local_68 = 0;
  uStack_60 = 0;
  local_fc = 3;
  uStack_f8 = local_128 | 0x14;
  local_c4 = 0xffffffff;
  local_b4 = 0xffffffff;
  local_ec = 1;
  iStack_e8 = iVar4 + 0x23108;
  local_e4 = 0xf;
  local_d4 = 0xf;
  local_dc = 1;
  iStack_d8 = iVar4 + 0x23120;
  local_74 = 0xffffffff;
  local_70 = 0;
  local_cc = 0xf;
  uStack_c8 = local_128 | 0x100;
  local_bc = 0;
  uStack_b8 = local_128 | 0x104;
  local_a4 = 0xffffffff;
  local_94 = 0xffffffff;
  local_ac = 0;
  iStack_a8 = iVar4 + 0x23400;
  local_84 = 1;
  local_9c = 0;
  iStack_98 = iVar4 + 0x23404;
  local_8c = 0;
  iStack_88 = iVar4 + 0x23180;
  local_7c = 1;
  iStack_78 = iVar4 + 0x23200;
  if ((char)param_1[0xeb] == '\0') {
    iVar4 = request_threaded_irq(param_1[0xca],gpi_handle_irq,0,4,param_1 + 0x10d,param_1);
    if (iVar4 < 0) {
      if (param_1[0x10b] == 0) {
        lVar7 = *(long *)(param_1 + 0x108);
      }
      else {
        _printk(&DAT_0010d95e,param_1 + 0x10d,99,"gpi_config_interrupts",param_1[0xca],iVar4);
        lVar7 = *(long *)(param_1 + 0x108);
      }
      if ((lVar7 != 0) && (param_1[0x10a] != 0)) {
        ipc_log_string(lVar7,"ch:%u %s: error request irq:%d ret:%d\n",99,"gpi_config_interrupts",
                       param_1[0xca],iVar4);
      }
      goto LAB_0010987c;
    }
  }
  if (param_2 == 1) {
    uVar2 = param_1[0x107];
    uVar6 = 8;
    if ((param_3 & 1) == 0) {
      uVar6 = 0;
    }
    lVar7 = *(long *)(param_1 + 0xcc) + (ulong)(*param_1 * 0x4000 + 0x23088);
    param_1[0x107] = uVar2 & 0xfffffff7 | uVar6;
    uVar5 = readl_relaxed(lVar7);
    writel_relaxed(uVar5 & 0xffffff80 | uVar2 & 0x77 | uVar6,lVar7);
  }
  else {
    lVar7 = 0;
    while (*(uint *)((long)&local_128 + lVar7) != 0) {
      lVar1 = *(long *)(param_1 + 0xcc) + (ulong)*(uint *)((long)&local_128 + lVar7);
      iVar4 = *(int *)((long)local_11c + lVar7);
      uVar6 = *(uint *)((long)local_11c + lVar7 + -8);
      uVar2 = *(uint *)((long)local_11c + lVar7 + -4);
      uVar5 = readl_relaxed(lVar1);
      writel_relaxed(uVar5 & (uVar6 ^ 0xffffffff) | iVar4 << (ulong)(uVar2 & 0x1f) & uVar6,lVar1);
      lVar7 = lVar7 + 0x10;
      if (lVar7 == 0xd0) {
                    /* WARNING: Does not return */
        pcVar3 = (code *)SoftwareBreakpoint(0x5512,0x109868);
        (*pcVar3)();
      }
    }
    param_1[0x107] = 0x4f;
  }
  iVar4 = 0;
  *(undefined1 *)(param_1 + 0xeb) = 1;
LAB_0010987c:
  lVar7 = sp_el0;
  if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar4;
}



//------------------------------------------------------------
// gpi_generate_cb_event @ 00109928 size=320
// signature: undefined gpi_generate_cb_event(void)
// callers: [gpi_handle_irq, gpi_process_events]
//------------------------------------------------------------

void gpi_generate_cb_event(long param_1,uint param_2,undefined8 param_3)

{
  code *pcVar1;
  long lVar2;
  long lVar3;
  undefined8 local_78;
  undefined8 local_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar3 = sp_el0;
  local_38 = *(long *)(lVar3 + 0x638);
  lVar3 = *(long *)(param_1 + 0x118);
  local_48 = 0;
  uStack_40 = 0;
  local_58 = 0;
  uStack_50 = 0;
  local_68 = 0;
  uStack_60 = 0;
  local_78 = 0;
  local_70 = 0;
  if (*(uint *)(lVar3 + 0x42c) < 2) {
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  else {
    if (7 < param_2) goto LAB_00109a60;
    _printk(&DAT_0010d6ca,lVar3 + 0x434,*(undefined4 *)(param_1 + 0x100),"gpi_generate_cb_event",
            (&gpi_cb_event_str)[param_2],param_3);
    lVar2 = *(long *)(lVar3 + 0x420);
  }
  if ((lVar2 != 0) && (1 < *(uint *)(lVar3 + 0x428))) {
    if (7 < param_2) {
LAB_00109a60:
                    /* WARNING: Does not return */
      pcVar1 = (code *)SoftwareBreakpoint(1,0x109a64);
      (*pcVar1)();
    }
    ipc_log_string(lVar2,"ch:%u %s: notifying event:%s with status:%llu\n",
                   *(undefined4 *)(param_1 + 0x100),"gpi_generate_cb_event",
                   (&gpi_cb_event_str)[param_2],param_3);
  }
  local_78 = CONCAT44(local_78._4_4_,param_2);
  local_70 = param_3;
  local_68 = sched_clock();
  if (*(int *)(*(code **)(param_1 + 0x170) + -4) != 0x437bfba3) {
                    /* WARNING: Does not return */
    pcVar1 = (code *)SoftwareBreakpoint(0x8228,0x1099f0);
    (*pcVar1)();
  }
  (**(code **)(param_1 + 0x170))(param_1,&local_78,*(undefined8 *)(param_1 + 0x178));
  lVar3 = sp_el0;
  if (*(long *)(lVar3 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}



//------------------------------------------------------------
// gpi_handle_irq @ 00109a6c size=2448
// signature: undefined gpi_handle_irq(void)
// callers: []
//------------------------------------------------------------

/* WARNING: Type propagation algorithm not settling */

undefined8 gpi_handle_irq(undefined8 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  ulong *puVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  code *pcVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined4 uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  ulong uVar19;
  long lVar20;
  char *pcVar21;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  ulong local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 uStack_70;
  long local_68;
  
  lVar20 = sp_el0;
  local_68 = *(long *)(lVar20 + 0x638);
  iVar6 = *param_2;
  *(undefined1 *)((long)param_2 + 0x5c1) = 1;
  uVar17 = _raw_read_lock_irqsave();
  uVar7 = param_2[0xec];
  if (uVar7 < 2) {
    if (param_2[0x10b] == 0) {
      lVar20 = *(long *)(param_2 + 0x108);
    }
    else {
      if (5 < uVar7) {
                    /* WARNING: Does not return */
        pcVar12 = (code *)SoftwareBreakpoint(1,0x10a40c);
        (*pcVar12)();
      }
      _printk(&DAT_0010d0bb,param_2 + 0x10d,99,"gpi_handle_irq",(&gpi_pm_state_str)[uVar7]);
      lVar20 = *(long *)(param_2 + 0x108);
    }
    if ((lVar20 != 0) && (param_2[0x10a] != 0)) {
      if ((uint)param_2[0xec] < 6) {
        pcVar21 = (&gpi_pm_state_str)[(uint)param_2[0xec]];
      }
      else {
        pcVar21 = "INVALID";
      }
      ipc_log_string(lVar20,"ch:%u %s: receive interrupt while in %s state\n",99,"gpi_handle_irq",
                     pcVar21);
    }
  }
  else {
    uVar13 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(*param_2 * 0x4000 + 0x23080));
    piVar1 = param_2 + 0x10d;
    piVar2 = param_2 + 2;
    piVar3 = param_2 + 100;
    piVar4 = param_2 + 0xfe;
    uVar7 = iVar6 * 0x4000 + 0x23080;
    do {
      uVar15 = uVar13;
      if ((uVar13 >> 2 & 1) != 0) {
        if ((uint)param_2[0x10b] < 2) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          _printk(&DAT_0010cee9,piVar1,99,"gpi_handle_irq");
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (1 < (uint)param_2[0x10a])) {
          ipc_log_string(lVar20,"ch:%u %s: processing global error irq\n",99,"gpi_handle_irq");
        }
        iVar6 = *param_2 * 0x4000;
        uVar19 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(iVar6 + 0x23100));
        uVar15 = (uint)uVar19;
        local_78 = 0;
        uStack_70 = 0;
        local_88 = 0;
        local_80 = 0;
        local_98 = 0;
        uStack_90 = 0;
        local_a8 = 0;
        uStack_a0 = 0;
        writel_relaxed(uVar19,*(long *)(param_2 + 0xcc) + (ulong)(iVar6 + 0x23110));
        if (uVar15 < 2) {
          uVar14 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(iVar6 + 0x23200));
          writel_relaxed(0,*(long *)(param_2 + 0xcc) + (ulong)(iVar6 + 0x23200));
          uVar15 = uVar14 >> 0x13 & 0x1f;
          if (1 < uVar15) {
            if ((uint)param_2[0x10b] < 2) {
              lVar20 = *(long *)(param_2 + 0x108);
            }
            else {
              _printk(&DAT_0010dbcd,piVar1,99,"gpi_process_glob_err_irq",uVar15);
              lVar20 = *(long *)(param_2 + 0x108);
            }
            if ((lVar20 != 0) && (1 < (uint)param_2[0x10a])) {
              pcVar21 = "ch:%u %s: invalid chid reported:%u\n";
              goto LAB_00109d3c;
            }
            goto LAB_00109d40;
          }
          uVar10 = uVar14 >> 4 & 0xf;
          uVar11 = uVar14 >> 0xc & 0xf;
          local_88 = CONCAT44(uVar14 >> 4,uVar14) & 0xf0000000f;
          local_a8 = CONCAT44(local_a8._4_4_,1);
          local_80 = CONCAT44(local_80._4_4_,uVar14 >> 0xc) & 0xffffffff0000000f;
          if ((uint)param_2[0x10b] < 3) {
            lVar20 = *(long *)(param_2 + 0x108);
          }
          else {
            _printk(&DAT_0010b7de,piVar1,param_2[(ulong)uVar15 * 0x62 + 0x42],
                    "gpi_process_glob_err_irq","GLOBAL ERROR");
            lVar20 = *(long *)(param_2 + 0x108);
          }
          if ((lVar20 != 0) && (2 < (uint)param_2[0x10a])) {
            ipc_log_string(lVar20,"ch:%u %s: sending CB event:%s\n",
                           param_2[(ulong)uVar15 * 0x62 + 0x42],"gpi_process_glob_err_irq",
                           "GLOBAL ERROR");
          }
          if ((uint)param_2[0x10b] < 2) {
            lVar20 = *(long *)(param_2 + 0x108);
          }
          else {
            _printk(&DAT_0010df59,piVar1,param_2[(ulong)uVar15 * 0x62 + 0x42],
                    "gpi_process_glob_err_irq",uVar14 >> 0x1a & 1,uVar14 >> 0x19 & 1,uVar14 & 0xf,
                    uVar10,uVar11);
            lVar20 = *(long *)(param_2 + 0x108);
          }
          if ((lVar20 != 0) && (1 < (uint)param_2[0x10a])) {
            ipc_log_string(lVar20,"ch:%u %s: ee:%u chtype:%u routine:%u type:%u error_code:%u\n",
                           param_2[(ulong)uVar15 * 0x62 + 0x42],"gpi_process_glob_err_irq",
                           uVar14 >> 0x1a & 1,uVar14 >> 0x19 & 1,uVar14 & 0xf,uVar10,uVar11);
          }
          if (*(int *)(*(code **)(param_2 + (ulong)uVar15 * 0x62 + 0x5e) + -4) != 0x437bfba3) {
                    /* WARNING: Does not return */
            pcVar12 = (code *)SoftwareBreakpoint(0x822a,0x109ce4);
            (*pcVar12)();
          }
          (**(code **)(param_2 + (ulong)uVar15 * 0x62 + 0x5e))
                    (param_2 + (ulong)uVar15 * 0x62 + 2,&local_a8,
                     *(undefined8 *)(param_2 + (ulong)uVar15 * 0x62 + 0x60));
        }
        else {
          if ((uint)param_2[0x10b] < 2) {
            lVar20 = *(long *)(param_2 + 0x108);
          }
          else {
            _printk(&DAT_0010d4b4,piVar1,99,"gpi_process_glob_err_irq",uVar19 & 0xffffffff);
            lVar20 = *(long *)(param_2 + 0x108);
          }
          if ((lVar20 != 0) && (1 < (uint)param_2[0x10a])) {
            pcVar21 = "ch:%u %s: invalid error status:0x%x\n";
LAB_00109d3c:
            ipc_log_string(lVar20,pcVar21,99,"gpi_process_glob_err_irq",uVar15);
          }
LAB_00109d40:
          gpi_generate_cb_event(piVar2,3,uVar19 & 0xffffffff);
          gpi_generate_cb_event(piVar3,3,uVar19 & 0xffffffff);
        }
        uVar15 = uVar13 & 0xfffffffb;
      }
      if ((uVar13 >> 3 & 1) != 0) {
        writel_relaxed(1,*(undefined8 *)(param_2 + 0xdc));
        if (param_2[200] == 0) {
          gpi_process_events(param_2);
        }
        else {
          gpi_config_interrupts(param_2,1,0);
          puVar5 = (ulong *)(param_2 + 0xf6);
          Hint_Prefetch(puVar5,2,0,1);
          do {
            uVar19 = *puVar5;
            cVar8 = '\x01';
            bVar9 = (bool)ExclusiveMonitorPass(puVar5,0x10);
            if (bVar9) {
              *puVar5 = uVar19 | 1;
              cVar8 = ExclusiveMonitorsStatus();
            }
          } while (cVar8 != '\0');
          DataMemoryBarrier(2,3);
          if ((uVar19 & 1) == 0) {
            __tasklet_schedule(param_2 + 0xf4);
          }
        }
        uVar15 = uVar15 & 0xfffffff7;
      }
      uVar13 = uVar15;
      if ((uVar15 >> 1 & 1) != 0) {
        if ((uint)param_2[0x10b] < 3) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          _printk(&DAT_0010dba3,piVar1,99,"gpi_handle_irq");
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (2 < (uint)param_2[0x10a])) {
          ipc_log_string(lVar20,"ch:%u %s: processing EV CTRL interrupt\n",99,"gpi_handle_irq");
        }
        uVar18 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(uVar7 | 0x14));
        writel_relaxed(uVar18,*(long *)(param_2 + 0xcc) + (ulong)(uVar7 | 0x24));
        uVar14 = readl_relaxed(*(undefined8 *)(param_2 + 0xce));
        uVar13 = 0;
        if (param_2[0x106] != 0xc) {
          uVar13 = uVar14 >> 0x14 & 0xf;
        }
        param_2[0xea] = uVar13;
        if ((uint)param_2[0x10b] < 3) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          pcVar21 = "INVALID";
          if (uVar13 < 2) {
            pcVar21 = (&gpi_ev_state_str)[uVar13];
          }
          _printk(&DAT_0010c151,piVar1,99,"gpi_handle_irq",pcVar21);
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (2 < (uint)param_2[0x10a])) {
          pcVar21 = "INVALID";
          if ((uint)param_2[0xea] < 2) {
            pcVar21 = (&gpi_ev_state_str)[(uint)param_2[0xea]];
          }
          ipc_log_string(lVar20,"ch:%u %s: setting EV state to %s\n",99,"gpi_handle_irq",pcVar21);
        }
        complete_all(piVar4);
        uVar13 = uVar15 & 0xfffffffd;
      }
      if ((uVar15 & 1) != 0) {
        if ((uint)param_2[0x10b] < 3) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          _printk(&DAT_0010b960,piVar1,99,"gpi_handle_irq");
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (2 < (uint)param_2[0x10a])) {
          ipc_log_string(lVar20,"ch:%u %s: process CH CTRL interrupts\n",99,"gpi_handle_irq");
        }
        iVar6 = *param_2;
        uVar19 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(iVar6 * 0x4000 + 0x23090));
        writel_relaxed(uVar19,*(long *)(param_2 + 0xcc) + (ulong)(iVar6 * 0x4000 + 0x230a0));
        if ((uVar19 & 1) != 0) {
          uVar15 = readl_relaxed(*(undefined8 *)(param_2 + 0x4c));
          iVar6 = param_2[0x106];
          if (iVar6 == 4) {
            uVar15 = 0;
          }
          else if (iVar6 == 9) {
            uVar15 = 6;
          }
          else if (iVar6 == 8) {
            uVar15 = 5;
          }
          else {
            uVar15 = uVar15 >> 0x14 & 0xf;
          }
          param_2[0x4a] = uVar15;
          complete_all(piVar4);
          if (param_2[0x4a] == 0xf) {
            gpi_generate_cb_event(piVar2,2,uVar19 & 0xffffffff);
          }
        }
        if (((uint)uVar19 >> 1 & 1) != 0) {
          uVar15 = readl_relaxed(*(undefined8 *)(param_2 + 0xae));
          iVar6 = param_2[0x106];
          if (iVar6 == 4) {
            uVar15 = 0;
          }
          else if (iVar6 == 8) {
            uVar15 = 5;
          }
          else if (iVar6 == 9) {
            uVar15 = 6;
          }
          else {
            uVar15 = uVar15 >> 0x14 & 0xf;
          }
          param_2[0xac] = uVar15;
          complete_all(piVar4);
          if (param_2[0xac] == 0xf) {
            gpi_generate_cb_event(piVar3,2,uVar19 & 0xffffffff);
          }
        }
        uVar13 = uVar13 & 0xfffffffe;
      }
      if (uVar13 != 0) {
        if (param_2[0x10b] == 0) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          _printk(&DAT_0010c2d7,piVar1,99,"gpi_handle_irq",uVar13);
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (param_2[0x10a] != 0)) {
          ipc_log_string(lVar20,"ch:%u %s: Unhandled interrupt status:0x%x\n",99,"gpi_handle_irq",
                         uVar13);
        }
        iVar6 = *param_2;
        uVar16 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(iVar6 * 0x4000 + 0x23118));
        if ((uint)param_2[0x10b] < 2) {
          lVar20 = *(long *)(param_2 + 0x108);
        }
        else {
          _printk(&DAT_0010c7d2,piVar1,99,"gpi_process_gen_err_irq",uVar16);
          lVar20 = *(long *)(param_2 + 0x108);
        }
        if ((lVar20 != 0) && (1 < (uint)param_2[0x10a])) {
          ipc_log_string(lVar20,"ch:%u %s: irq_stts:0x%x\n",99,"gpi_process_gen_err_irq",uVar16);
        }
        if (*(long *)(param_2 + 0x5e) != 0) {
          gpi_generate_cb_event(piVar2,3,uVar16);
        }
        if (*(long *)(param_2 + 0xc0) != 0) {
          gpi_generate_cb_event(piVar3,3,uVar16);
        }
        writel_relaxed(uVar16,*(long *)(param_2 + 0xcc) + (ulong)(iVar6 * 0x4000 + 0x23128));
        param_2[0x16f] = param_2[0x16f] + 1;
        if ((char)param_2[0x16e] == '\0') {
          gpi_dump_debug_reg(param_2);
          *(undefined1 *)(param_2 + 0x16e) = 1;
        }
        break;
      }
      uVar13 = readl_relaxed(*(long *)(param_2 + 0xcc) + (ulong)(*param_2 * 0x4000 + 0x23080));
    } while (uVar13 != 0);
  }
  _raw_read_unlock_irqrestore(param_2 + 0xed,uVar17);
  *(undefined1 *)((long)param_2 + 0x5c1) = 0;
  lVar20 = sp_el0;
  if (*(long *)(lVar20 + 0x638) != local_68) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 1;
}



//------------------------------------------------------------
// gpi_alloc_ring @ 0010a40c size=628
// signature: undefined gpi_alloc_ring(void)
// callers: [gpi_config, gpi_alloc_chan_resources]
//------------------------------------------------------------

undefined8 gpi_alloc_ring(long *param_1,int param_2,long param_3)

{
  void *__s;
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  long lVar4;
  ulong uVar5;
  long lVar6;
  
  uVar2 = param_2 * 0x10;
  uVar1 = 0;
  if (uVar2 != 0) {
    uVar1 = 0x1f - (int)LZCOUNT(uVar2);
  }
  if ((uVar2 & (-1 << (ulong)(uVar1 & 0x1f) ^ 0xffffffffU)) != 0) {
    uVar1 = uVar1 + 1;
  }
  uVar1 = 1 << (ulong)(uVar1 & 0x1f);
  lVar6 = (long)(int)uVar1;
  lVar4 = (-(ulong)(uVar1 >> 0x1f) & 0xfffffffe00000000 | (ulong)uVar1 << 1) - 1;
  param_1[1] = lVar4;
  if (*(uint *)(param_3 + 0x42c) < 3) {
    lVar4 = *(long *)(param_3 + 0x420);
  }
  else {
    _printk(&DAT_0010dd2a,param_3 + 0x434,99,"gpi_alloc_ring",param_2,0x10,uVar2,lVar6,lVar4);
    lVar4 = *(long *)(param_3 + 0x420);
  }
  if ((lVar4 != 0) && (2 < *(uint *)(param_3 + 0x428))) {
    ipc_log_string(lVar4,"ch:%u %s: #el:%u el_size:%u len:%u actual_len:%llu alloc_size:%lu\n",99,
                   "gpi_alloc_ring",param_2,0x10,uVar2,lVar6,param_1[1]);
  }
  lVar4 = dma_alloc_attrs(*(undefined8 *)(*(long *)(param_3 + 0x318) + 0x180),param_1[1],param_1 + 3
                          ,0xcc0,0);
  *param_1 = lVar4;
  if (lVar4 == 0) {
    if (*(int *)(param_3 + 0x42c) == 0) {
      lVar4 = *(long *)(param_3 + 0x420);
    }
    else {
      _printk(&DAT_0010d2d8,param_3 + 0x434,99,"gpi_alloc_ring",param_1[1]);
      lVar4 = *(long *)(param_3 + 0x420);
    }
    if ((lVar4 != 0) && (*(int *)(param_3 + 0x428) != 0)) {
      ipc_log_string(lVar4,"ch:%u %s: could not alloc size:%lu mem for ring\n",99,"gpi_alloc_ring",
                     param_1[1]);
    }
    uVar3 = 0xfffffff4;
  }
  else {
    uVar5 = (lVar6 + param_1[3]) - 1U & -lVar6;
    __s = (void *)(lVar4 + (uVar5 - param_1[3]));
    *(uint *)(param_1 + 7) = uVar1;
    *(undefined4 *)((long)param_1 + 0x3c) = 0x10;
    param_1[2] = uVar5;
    param_1[5] = (long)__s;
    param_1[6] = (long)__s;
    param_1[4] = (long)__s;
    *(uint *)(param_1 + 8) = uVar1 >> 4;
    memset(__s,0,(ulong)uVar1);
    *(undefined1 *)((long)param_1 + 0x44) = 1;
    DataMemoryBarrier(2,2);
    if (*(uint *)(param_3 + 0x42c) < 3) {
      lVar4 = *(long *)(param_3 + 0x420);
      if (lVar4 == 0) {
        return 0;
      }
    }
    else {
      _printk(&DAT_0010c4fa,param_3 + 0x434,99,"gpi_alloc_ring",param_1[3],param_1[2],
              (int)param_1[7],*(undefined4 *)((long)param_1 + 0x3c),(int)param_1[8]);
      lVar4 = *(long *)(param_3 + 0x420);
      if (lVar4 == 0) {
        return 0;
      }
    }
    if (2 < *(uint *)(param_3 + 0x428)) {
      ipc_log_string(lVar4,
                     "ch:%u %s: phy_pre:0x%0llx phy_alig:0x%0llx len:%u el_size:%u elements:%u\n",99
                     ,"gpi_alloc_ring",param_1[3],param_1[2],(int)param_1[7],
                     *(undefined4 *)((long)param_1 + 0x3c),(int)param_1[8]);
    }
    uVar3 = 0;
  }
  return uVar3;
}



//------------------------------------------------------------
// gpi_free_ring @ 0010a680 size=80
// signature: undefined gpi_free_ring(void)
// callers: [gpi_config]
//------------------------------------------------------------

void gpi_free_ring(undefined8 *param_1,long param_2)

{
  dma_free_attrs(*(undefined8 *)(*(long *)(param_2 + 0x318) + 0x180),param_1[1],*param_1,param_1[3],
                 0);
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}



//------------------------------------------------------------
// gpi_disable_interrupts @ 0010a6d0 size=332
// signature: undefined gpi_disable_interrupts(void)
// callers: [gpi_config, gpi_resume, gpi_free_chan_resources]
//------------------------------------------------------------

void gpi_disable_interrupts(int *param_1)

{
  int iVar1;
  long lVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  uint uVar6;
  long lVar7;
  uint local_d8 [32];
  long local_58;
  
  lVar2 = sp_el0;
  lVar7 = 0;
  local_58 = *(long *)(lVar2 + 0x638);
  local_d8[1] = 0x7f;
  local_d8[2] = 0;
  local_d8[9] = 3;
  local_d8[10] = 0;
  local_d8[0x1c] = 0;
  local_d8[0x1d] = 0;
  local_d8[0x1e] = 0;
  local_d8[0x1f] = 0;
  iVar1 = *param_1 * 0x4000;
  local_d8[0] = iVar1 + 0x23088;
  local_d8[0x1a] = 0;
  local_d8[0x1b] = 0;
  local_d8[3] = 0;
  local_d8[4] = local_d8[0] | 0x30;
  local_d8[7] = 0;
  local_d8[8] = local_d8[0] | 0x10;
  local_d8[0xb] = 0;
  local_d8[0xc] = local_d8[0] | 0x14;
  local_d8[0xf] = 0;
  local_d8[0x10] = iVar1 + 0x23108;
  local_d8[0x13] = 0;
  local_d8[0x14] = iVar1 + 0x23120;
  local_d8[5] = 1;
  local_d8[6] = 0;
  local_d8[0xd] = 1;
  local_d8[0xe] = 0;
  local_d8[0x11] = 0xf;
  local_d8[0x12] = 0;
  local_d8[0x15] = 0xf;
  local_d8[0x16] = 0;
  local_d8[0x17] = 0;
  local_d8[0x18] = iVar1 + 0x23180;
  local_d8[0x19] = 1;
  do {
    if (*(uint *)((long)local_d8 + lVar7) == 0) {
      param_1[0x107] = 0;
      free_irq(param_1[0xca],param_1);
      *(undefined1 *)(param_1 + 0xeb) = 0;
      lVar7 = sp_el0;
      if (*(long *)(lVar7 + 0x638) != local_58) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    lVar2 = *(long *)(param_1 + 0xcc) + (ulong)*(uint *)((long)local_d8 + lVar7);
    iVar1 = *(int *)((long)local_d8 + lVar7 + 0xc);
    uVar3 = *(uint *)((long)local_d8 + lVar7 + 4);
    uVar4 = *(uint *)((long)local_d8 + lVar7 + 8);
    uVar6 = readl_relaxed(lVar2);
    writel_relaxed(uVar6 & (uVar3 ^ 0xffffffff) | iVar1 << (ulong)(uVar4 & 0x1f) & uVar3,lVar2);
    lVar7 = lVar7 + 0x10;
  } while (lVar7 != 0x80);
                    /* WARNING: Does not return */
  pcVar5 = (code *)SoftwareBreakpoint(0x5512,0x10a7d0);
  (*pcVar5)();
}



//------------------------------------------------------------
// gpi_alloc_ev_chan @ 0010a81c size=568
// signature: undefined gpi_alloc_ev_chan(void)
// callers: [gpi_config, gpi_resume]
//------------------------------------------------------------

int gpi_alloc_ev_chan(long param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  
  lVar8 = *(long *)(param_1 + 0x3c0);
  lVar7 = *(long *)(param_1 + 0x338);
  uVar1 = *(undefined4 *)(lVar8 + 0x38);
  iVar3 = *(int *)(lVar8 + 0x3c);
  uVar2 = *(undefined4 *)(lVar8 + 0x10);
  uVar4 = *(undefined4 *)(lVar8 + 0x14);
  lVar9 = *(long *)(param_1 + 0x340);
  if (*(uint *)(param_1 + 0x42c) < 3) {
    lVar6 = *(long *)(param_1 + 0x420);
  }
  else {
    _printk(&DAT_0010c015,param_1 + 0x434,99,"gpi_alloc_ev_chan");
    lVar6 = *(long *)(param_1 + 0x420);
  }
  if ((lVar6 != 0) && (2 < *(uint *)(param_1 + 0x428))) {
    ipc_log_string(lVar6,"ch:%u %s: enter\n",99,"gpi_alloc_ev_chan");
  }
  iVar5 = gpi_send_cmd(param_1,0,10);
  if (iVar5 == 0) {
    if (lVar7 != 0) {
      writel_relaxed(iVar3 << 0x18 | 0x10002,lVar7);
      writel_relaxed(uVar1,lVar7 + 4);
      writel_relaxed(uVar2,lVar7 + 8);
      writel_relaxed(uVar4,lVar7 + 0xc);
      if (lVar9 != 0) {
        writel_relaxed(uVar4,lVar9 + 4);
        writel_relaxed(0,lVar7 + 0x20);
        writel_relaxed(0,lVar7 + 0x28);
        writel_relaxed(0,lVar7 + 0x2c);
        writel_relaxed(0,lVar7 + 0x20);
        writel_relaxed(0,lVar7 + 0x30);
        writel_relaxed(0,lVar7 + 0x34);
      }
    }
    *(ulong *)(lVar8 + 0x28) =
         (*(long *)(lVar8 + 0x20) + (ulong)*(uint *)(lVar8 + 0x38)) - (ulong)*(uint *)(lVar8 + 0x3c)
    ;
    DataSynchronizationBarrier(3,2,0);
    _raw_write_lock_irq(param_1 + 0x3b4);
    *(undefined4 *)(param_1 + 0x3b0) = 3;
    _raw_write_unlock_irq(param_1 + 0x3b4);
    writel_relaxed((*(int *)(lVar8 + 0x10) + *(int *)(lVar8 + 0x28)) - *(int *)(lVar8 + 0x20),
                   *(undefined8 *)(param_1 + 0x340));
  }
  else {
    if (*(uint *)(param_1 + 0x42c) < 2) {
      lVar7 = *(long *)(param_1 + 0x420);
    }
    else {
      _printk(&DAT_0010d138,param_1 + 0x434,99,"gpi_alloc_ev_chan","EV ALLOCATE",iVar5);
      lVar7 = *(long *)(param_1 + 0x420);
    }
    if ((lVar7 != 0) && (1 < *(uint *)(param_1 + 0x428))) {
      ipc_log_string(lVar7,"ch:%u %s: error with cmd:%s ret:%d\n",99,"gpi_alloc_ev_chan",
                     "EV ALLOCATE",iVar5);
    }
  }
  return iVar5;
}



//------------------------------------------------------------
// init_module @ 0010aba0 size=68
// signature: undefined init_module(void)
// callers: []
//------------------------------------------------------------

void init_module(void)

{
  pdentry = debugfs_create_dir("gpi_dma",0);
  __platform_driver_register(&gpi_driver,&__this_module);
  return;
}



//------------------------------------------------------------
// cleanup_module @ 0010abe8 size=36
// signature: undefined cleanup_module(void)
// callers: []
//------------------------------------------------------------

void cleanup_module(void)

{
  platform_driver_unregister(&gpi_driver);
  return;
}



//------------------------------------------------------------
// ipc_log_string @ 00110000 size=1
// signature: undefined ipc_log_string(void)
// callers: [gpi_prep_slave_sg, gpi_start_chan, gpi_of_dma_xlate, gpi_alloc_chan, gpi_resume, geni_gsi_ch_start, gpi_mark_stale_events, gpi_dump_debug_reg, gpi_alloc_ring, gpi_q2spi_terminate_all, gsi_common_rx_cb, gpi_generate_cb_event, gsi_common_tx_tre_optimization, gpi_config, gsi_common_tre_process, gpi_reset_chan, gsi_common_fill_tre_buf, geni_gsi_common_request_channel, gpi_send_cmd, gpi_process_events, gpi_probe, gpi_config_interrupts, gsi_common_tx_cb, gsi_common_ev_cb, gpi_pause, geni_gsi_connect_doorbell, geni_gsi_disconnect_doorbell_stop_ch, gpi_free_chan_resources, gpi_handle_irq, gpi_terminate_channel, gpi_ev_tasklet, gpi_alloc_chan_resources, gsi_common_prep_desc_and_submit, gpi_alloc_ev_chan, gpi_terminate_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_string(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sched_clock @ 00110008 size=1
// signature: undefined sched_clock(void)
// callers: [gpi_generate_cb_event, gpi_dump_debug_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sched_clock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kmalloc_trace @ 00110018 size=1
// signature: undefined kmalloc_trace(void)
// callers: [gpi_prep_slave_sg, gpi_dump_debug_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kmalloc_trace(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00110020 size=1
// signature: undefined _printk(void)
// callers: [gpi_prep_slave_sg, gpi_start_chan, gpi_alloc_chan, gpi_resume, geni_gsi_ch_start, gpi_mark_stale_events, gpi_dump_debug_reg, gpi_alloc_ring, gpi_q2spi_terminate_all, gsi_common_rx_cb, gpi_generate_cb_event, gpi_config, gpi_reset_chan, geni_gsi_common_request_channel, gpi_send_cmd, gpi_process_events, gpi_config_interrupts, gsi_common_tx_cb, gsi_common_ev_cb, gpi_pause, geni_gsi_connect_doorbell, geni_gsi_disconnect_doorbell_stop_ch, gpi_free_chan_resources, gpi_handle_irq, gpi_terminate_channel, gpi_ev_tasklet, gpi_alloc_chan_resources, gsi_common_prep_desc_and_submit, gpi_alloc_ev_chan, gpi_terminate_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memcpy @ 00110028 size=1
// signature: void * memcpy(void * __dest, void * __src, size_t __n)
// callers: [gpi_dump_debug_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memcpy(void *__dest,void *__src,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __kmalloc @ 00110030 size=1
// signature: undefined __kmalloc(void)
// callers: [gpi_dump_debug_reg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_unmap_page_attrs @ 00110038 size=1
// signature: undefined dma_unmap_page_attrs(void)
// callers: [gsi_common_tre_process]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_unmap_page_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// wait_for_completion_timeout @ 00110040 size=1
// signature: undefined wait_for_completion_timeout(void)
// callers: [gsi_common_tx_tre_optimization, gpi_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void wait_for_completion_timeout(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_init_table @ 00110048 size=1
// signature: undefined sg_init_table(void)
// callers: [gsi_common_fill_tre_buf]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_init_table(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _dev_err @ 00110050 size=1
// signature: undefined _dev_err(void)
// callers: [gsi_common_prep_desc_and_submit, gpi_of_dma_xlate, geni_gsi_common_request_channel, gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _dev_err(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_request_chan @ 00110058 size=1
// signature: undefined dma_request_chan(void)
// callers: [geni_gsi_common_request_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_request_chan(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_release_channel @ 00110060 size=1
// signature: undefined dma_release_channel(void)
// callers: [geni_gsi_common_request_channel]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_release_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_lock @ 00110068 size=1
// signature: undefined mutex_lock(void)
// callers: [gpi_q2spi_terminate_all, gpi_of_dma_xlate, gpi_config, gpi_pause, gpi_resume, geni_gsi_ch_start, gpi_free_chan_resources, gpi_terminate_channel, gpi_terminate_all, gpi_alloc_chan_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_lock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// mutex_unlock @ 00110070 size=1
// signature: undefined mutex_unlock(void)
// callers: [gpi_q2spi_terminate_all, gpi_of_dma_xlate, gpi_config, gpi_pause, gpi_resume, geni_gsi_ch_start, gpi_free_chan_resources, gpi_terminate_channel, gpi_terminate_all, gpi_alloc_chan_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void mutex_unlock(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_lock_irq @ 00110078 size=1
// signature: undefined _raw_write_lock_irq(void)
// callers: [gpi_q2spi_terminate_all, gpi_start_chan, gpi_alloc_ev_chan, gpi_config, gpi_pause, gpi_resume, gpi_reset_chan, gpi_free_chan_resources, gpi_terminate_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_lock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_write_unlock_irq @ 00110080 size=1
// signature: undefined _raw_write_unlock_irq(void)
// callers: [gpi_q2spi_terminate_all, gpi_start_chan, gpi_alloc_ev_chan, gpi_config, gpi_pause, gpi_resume, gpi_reset_chan, gpi_free_chan_resources, gpi_terminate_all]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_write_unlock_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __msecs_to_jiffies @ 00110088 size=1
// signature: undefined __msecs_to_jiffies(void)
// callers: [gpi_send_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __msecs_to_jiffies(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_lock_irqsave @ 00110090 size=1
// signature: undefined _raw_spin_lock_irqsave(void)
// callers: [gpi_prep_slave_sg, gpi_issue_pending, gpi_reset_chan, geni_gsi_disconnect_doorbell_stop_ch, gpi_free_chan_resources, gpi_process_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_del_entry_valid @ 00110098 size=1
// signature: undefined __list_del_entry_valid(void)
// callers: [geni_gsi_disconnect_doorbell_stop_ch, gpi_process_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_del_entry_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_spin_unlock_irqrestore @ 001100a0 size=1
// signature: undefined _raw_spin_unlock_irqrestore(void)
// callers: [gpi_prep_slave_sg, gpi_issue_pending, gpi_reset_chan, geni_gsi_disconnect_doorbell_stop_ch, gpi_free_chan_resources, gpi_process_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_spin_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// kfree @ 001100a8 size=1
// signature: undefined kfree(void)
// callers: [gpi_prep_slave_sg, gpi_desc_free, geni_gsi_disconnect_doorbell_stop_ch, gpi_process_events]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void kfree(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vchan_dma_desc_free_list @ 001100b0 size=1
// signature: undefined vchan_dma_desc_free_list(void)
// callers: [gpi_reset_chan, gpi_free_chan_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vchan_dma_desc_free_list(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 001100b8 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [gpi_config_interrupts, gpi_generate_cb_event, gpi_setup_debug, gpi_pause, gpi_disable_interrupts, gpi_reset_chan, gpi_free_chan_resources, gpi_handle_irq, gpi_process_events, gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// sg_next @ 001100c0 size=1
// signature: undefined sg_next(void)
// callers: [gpi_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void sg_next(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_tx_descriptor_init @ 001100d0 size=1
// signature: undefined dma_async_tx_descriptor_init(void)
// callers: [gpi_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_tx_descriptor_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __list_add_valid @ 001100e8 size=1
// signature: undefined __list_add_valid(void)
// callers: [gpi_prep_slave_sg]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __list_add_valid(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_dir @ 001100f0 size=1
// signature: undefined debugfs_create_dir(void)
// callers: [gpi_setup_debug, init_module]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_dir(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __platform_driver_register @ 001100f8 size=1
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
// platform_driver_unregister @ 00110100 size=1
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
// log_read_mmio @ 00110108 size=1
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
// log_post_read_mmio @ 00110110 size=1
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
// log_write_mmio @ 00110118 size=1
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
// log_post_write_mmio @ 00110120 size=1
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
// devm_kmalloc @ 00110128 size=1
// signature: undefined devm_kmalloc(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_kmalloc(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_resource_byname @ 00110130 size=1
// signature: undefined platform_get_resource_byname(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_resource_byname(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// devm_ioremap @ 00110138 size=1
// signature: undefined devm_ioremap(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void devm_ioremap(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_property_read_variable_u32_array @ 00110140 size=1
// signature: undefined of_property_read_variable_u32_array(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_property_read_variable_u32_array(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_set_mask @ 00110148 size=1
// signature: undefined dma_set_mask(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_set_mask(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __mutex_init @ 00110150 size=1
// signature: undefined __mutex_init(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __mutex_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_find_property @ 00110158 size=1
// signature: undefined of_find_property(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_find_property(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dmam_alloc_attrs @ 00110160 size=1
// signature: undefined dmam_alloc_attrs(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dmam_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// platform_get_irq @ 00110168 size=1
// signature: undefined platform_get_irq(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void platform_get_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// vchan_init @ 00110170 size=1
// signature: undefined vchan_init(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void vchan_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_init @ 00110178 size=1
// signature: undefined tasklet_init(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_init(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __init_swait_queue_head @ 00110180 size=1
// signature: undefined __init_swait_queue_head(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __init_swait_queue_head(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_device_register @ 00110190 size=1
// signature: undefined dma_async_device_register(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_device_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_controller_register @ 00110198 size=1
// signature: undefined of_dma_controller_register(void)
// callers: [gpi_probe]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_controller_register(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// of_dma_controller_free @ 001101a0 size=1
// signature: undefined of_dma_controller_free(void)
// callers: [gpi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void of_dma_controller_free(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_async_device_unregister @ 001101a8 size=1
// signature: undefined dma_async_device_unregister(void)
// callers: [gpi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_async_device_unregister(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_destroy @ 001101b0 size=1
// signature: undefined ipc_log_context_destroy(void)
// callers: [gpi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_destroy(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_remove @ 001101b8 size=1
// signature: undefined debugfs_remove(void)
// callers: [gpi_remove]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_remove(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_bh @ 001101c0 size=1
// signature: undefined _raw_read_lock_bh(void)
// callers: [gpi_ev_tasklet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_bh @ 001101c8 size=1
// signature: undefined _raw_read_unlock_bh(void)
// callers: [gpi_ev_tasklet]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_bh(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_free_attrs @ 001101d0 size=1
// signature: undefined dma_free_attrs(void)
// callers: [gpi_free_ring, gpi_free_chan_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_free_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// tasklet_kill @ 001101d8 size=1
// signature: undefined tasklet_kill(void)
// callers: [gpi_free_chan_resources]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tasklet_kill(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_lock_irqsave @ 001101e0 size=1
// signature: undefined _raw_read_lock_irqsave(void)
// callers: [gpi_issue_pending, gpi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_lock_irqsave(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _raw_read_unlock_irqrestore @ 001101e8 size=1
// signature: undefined _raw_read_unlock_irqrestore(void)
// callers: [gpi_issue_pending, gpi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _raw_read_unlock_irqrestore(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __const_udelay @ 001101f0 size=1
// signature: undefined __const_udelay(void)
// callers: [gpi_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __const_udelay(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// disable_irq @ 001101f8 size=1
// signature: undefined disable_irq(void)
// callers: [gpi_pause]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void disable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// enable_irq @ 00110200 size=1
// signature: undefined enable_irq(void)
// callers: [gpi_resume]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void enable_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_get_slave_channel @ 00110208 size=1
// signature: undefined dma_get_slave_channel(void)
// callers: [gpi_of_dma_xlate]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_get_slave_channel(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// snprintf @ 00110210 size=1
// signature: int snprintf(char * __s, size_t __maxlen, char * __format, ...)
// callers: [gpi_setup_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int snprintf(char *__s,size_t __maxlen,char *__format,...)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// ipc_log_context_create @ 00110218 size=1
// signature: undefined ipc_log_context_create(void)
// callers: [gpi_setup_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void ipc_log_context_create(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// debugfs_create_u32 @ 00110220 size=1
// signature: undefined debugfs_create_u32(void)
// callers: [gpi_setup_debug]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void debugfs_create_u32(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// request_threaded_irq @ 00110228 size=1
// signature: undefined request_threaded_irq(void)
// callers: [gpi_config_interrupts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void request_threaded_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __tasklet_schedule @ 00110230 size=1
// signature: undefined __tasklet_schedule(void)
// callers: [gpi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __tasklet_schedule(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// complete_all @ 00110238 size=1
// signature: undefined complete_all(void)
// callers: [gpi_handle_irq]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void complete_all(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// dma_alloc_attrs @ 00110240 size=1
// signature: undefined dma_alloc_attrs(void)
// callers: [gpi_alloc_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void dma_alloc_attrs(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// memset @ 00110248 size=1
// signature: void * memset(void * __s, int __c, size_t __n)
// callers: [gpi_alloc_ring]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void * memset(void *__s,int __c,size_t __n)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// free_irq @ 00110250 size=1
// signature: undefined free_irq(void)
// callers: [gpi_disable_interrupts]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void free_irq(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



