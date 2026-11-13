// Decompiled by Ghidra 12.2
// Program: hwkm.ko
// Image base: 00100000

//------------------------------------------------------------
// qti_hwkm_get_reg_data @ 001001ec size=56
// signature: undefined qti_hwkm_get_reg_data(void)
// callers: []
//------------------------------------------------------------

uint qti_hwkm_get_reg_data(long param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(param_1 + (ulong)param_2);
  return (uVar1 & param_4) >> (ulong)(param_3 & 0x1f);
}



//------------------------------------------------------------
// readl_relaxed @ 00100224 size=124
// signature: undefined readl_relaxed(void)
// callers: [qti_hwkm_is_ice_tpkey_set, qti_hwkm_get_reg_data, qti_hwkm_init_required, qti_hwkm_init]
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
  log_post_read_mmio(uVar2,0x20,param_1,0x10026c,uVar1);
  return uVar2;
}



//------------------------------------------------------------
// qti_hwkm_handle_cmd @ 001002a4 size=332
// signature: undefined qti_hwkm_handle_cmd(void)
// callers: [qti_hwkm_init]
//------------------------------------------------------------

int qti_hwkm_handle_cmd(int *param_1)

{
  bool bVar1;
  long lVar2;
  int iVar3;
  uint uVar4;
  undefined8 local_50;
  undefined8 local_48;
  undefined4 local_40;
  long local_38;
  
  lVar2 = sp_el0;
  local_38 = *(long *)(lVar2 + 0x638);
  if (*param_1 == 7) {
    local_40 = 0;
    local_50 = 0;
    local_48 = 0;
    if (param_1[1] == 0x40) {
      iVar3 = tme_hwkm_master_broadcast_transportkey(&local_50);
      if (iVar3 == -0x13) {
LAB_00100308:
        uVar4 = 0;
        do {
          usleep_range_state(8000,12000,2);
          iVar3 = tme_hwkm_master_broadcast_transportkey(&local_50);
          if (iVar3 == 0) goto LAB_001003bc;
        } while ((iVar3 == -0xb || iVar3 == -0x13) &&
                (bVar1 = uVar4 < 999, uVar4 = uVar4 + 1, bVar1));
      }
      else {
        if (iVar3 == 0) goto LAB_001003bc;
        if (iVar3 == -0xb) goto LAB_00100308;
      }
      _printk(&DAT_001008d4,iVar3);
      _printk(&DAT_0010088b);
      _printk(&DAT_00100aa3,local_50 & 0xffffffff);
      _printk(&DAT_001008bd,local_50._4_4_);
      _printk(&DAT_00100917,local_48 & 0xffffffff);
      _printk(&DAT_00100ae0,local_48._4_4_);
      goto LAB_001003bc;
    }
    _printk(&DAT_00100a00);
  }
  iVar3 = -0x16;
LAB_001003bc:
  lVar2 = sp_el0;
  if (*(long *)(lVar2 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar3;
}



//------------------------------------------------------------
// qti_hwkm_init_required @ 001003f4 size=36
// signature: undefined qti_hwkm_init_required(void)
// callers: []
//------------------------------------------------------------

uint qti_hwkm_init_required(undefined8 *param_1)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(*param_1);
  return uVar1 & 1;
}



//------------------------------------------------------------
// qti_hwkm_is_ice_tpkey_set @ 0010041c size=52
// signature: undefined qti_hwkm_is_ice_tpkey_set(void)
// callers: []
//------------------------------------------------------------

bool qti_hwkm_is_ice_tpkey_set(long param_1)

{
  uint uVar1;
  
  uVar1 = readl_relaxed(*(long *)(param_1 + 8) + 0x1020);
  return (uVar1 & 0xffffff00) == 0x100;
}



//------------------------------------------------------------
// qti_hwkm_init @ 00100454 size=800
// signature: undefined qti_hwkm_init(void)
// callers: []
//------------------------------------------------------------

undefined8 qti_hwkm_init(long *param_1)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  ulong uVar4;
  undefined *puVar5;
  undefined8 uVar6;
  undefined8 local_128;
  undefined8 local_120;
  undefined8 local_118;
  undefined8 uStack_110;
  undefined8 local_108;
  undefined8 uStack_100;
  undefined8 local_f8;
  undefined8 uStack_f0;
  undefined8 local_e8;
  undefined8 uStack_e0;
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
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  long local_38;
  
  lVar1 = sp_el0;
  local_38 = *(long *)(lVar1 + 0x638);
  if ((param_1[1] == 0) || (*param_1 == 0)) {
    _printk(&DAT_00100a59,"qti_hwkm_init");
    uVar6 = 0xffffffea;
    goto LAB_0010070c;
  }
  uVar2 = readl_relaxed();
  writel_relaxed(uVar2 & 0xfffffffe,*param_1);
  DataSynchronizationBarrier(3,2,0);
  uVar2 = readl_relaxed(param_1[1] + 0x1004);
  if ((uVar2 >> 9 & 1) == 0) {
    puVar5 = &DAT_00100a2a;
LAB_001006cc:
    _printk(puVar5,"qti_hwkm_check_bist_status");
    _printk(&DAT_0010099a,"qti_hwkm_ice_init_sequence",0xffffffea);
    puVar5 = &DAT_00100866;
  }
  else {
    uVar2 = readl_relaxed(param_1[1] + 0x1004);
    if ((uVar2 >> 7 & 1) == 0) {
      puVar5 = &DAT_0010094d;
      goto LAB_001006cc;
    }
    uVar2 = readl_relaxed(param_1[1] + 0x1004);
    if ((uVar2 >> 2 & 1) == 0) {
      puVar5 = &DAT_00100974;
      goto LAB_001006cc;
    }
    uVar2 = readl_relaxed(param_1[1] + 0x1004);
    if ((uVar2 >> 1 & 1) == 0) {
      puVar5 = &DAT_00100aba;
      goto LAB_001006cc;
    }
    uVar4 = readl_relaxed(param_1[1] + 0x1004);
    if ((uVar4 & 1) == 0) {
      puVar5 = &DAT_001009eb;
      goto LAB_001006cc;
    }
    uVar2 = readl_relaxed(param_1[1] + 0x1000);
    writel_relaxed(uVar2 & 0xfffffffe,param_1[1] + 0x1000);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0xffffffff,param_1[1] + 0x5000);
    writel_relaxed(0xffffffff,param_1[1] + 0x5004);
    writel_relaxed(0xffffffff,param_1[1] + 0x5008);
    writel_relaxed(0xffffffff,param_1[1] + 0x500c);
    writel_relaxed(0xffffffff,param_1[1] + 0x5010);
    DataSynchronizationBarrier(3,2,0);
    uVar2 = readl_relaxed(param_1[1] + 0x2008);
    writel_relaxed(uVar2 | 8,param_1[1] + 0x2008);
    DataSynchronizationBarrier(3,2,0);
    local_48 = 0;
    uStack_40 = 0;
    local_58 = 0;
    uStack_50 = 0;
    local_68 = 0;
    uStack_60 = 0;
    local_78 = 0;
    uStack_70 = 0;
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
    local_e8 = 0;
    uStack_e0 = 0;
    local_f8 = 0;
    uStack_f0 = 0;
    local_108 = 0;
    uStack_100 = 0;
    local_118 = 0;
    uStack_110 = 0;
    local_120 = 0;
    uVar2 = readl_relaxed(param_1[1] + 0x101c);
    writel_relaxed(uVar2 & 0xfffffeff,param_1[1] + 0x101c);
    DataSynchronizationBarrier(3,2,0);
    writel_relaxed(0x18c,param_1[1] + 0x101c);
    DataSynchronizationBarrier(3,2,0);
    local_128 = 0x4000000007;
    iVar3 = qti_hwkm_handle_cmd(&local_128);
    if (iVar3 == 0) {
      readl_relaxed(param_1[1] + 0x1020);
      uVar2 = readl_relaxed(param_1[1] + 0x101c);
      writel_relaxed(uVar2 & 0xfffffeff,param_1[1] + 0x101c);
      DataSynchronizationBarrier(3,2,0);
      uVar6 = 0;
      DataSynchronizationBarrier(3,2,0);
      goto LAB_0010070c;
    }
    _printk(&DAT_001009c1,"qti_hwkm_set_tpkey",iVar3);
    puVar5 = &DAT_00100a7c;
  }
  uVar6 = 0xffffffea;
  _printk(puVar5,"qti_hwkm_init",0xffffffea);
LAB_0010070c:
  lVar1 = sp_el0;
  if (*(long *)(lVar1 + 0x638) != local_38) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar6;
}



//------------------------------------------------------------
// writel_relaxed @ 00100774 size=132
// signature: undefined writel_relaxed(void)
// callers: [qti_hwkm_init]
//------------------------------------------------------------

void writel_relaxed(undefined4 param_1,undefined4 *param_2)

{
  ulong uVar1;
  ulong unaff_x30;
  
  uVar1 = unaff_x30 & 0xff80007fffffffff;
  if ((unaff_x30 & 0x80000000000000) != 0) {
    uVar1 = unaff_x30 | 0xffffff8000000000;
  }
  log_write_mmio(param_1,0x20,param_2,0x10078c,uVar1);
  *param_2 = param_1;
  log_post_write_mmio(param_1,0x20,param_2,0x1007c8,uVar1);
  return;
}



//------------------------------------------------------------
// log_read_mmio @ 00102000 size=1
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
// log_post_read_mmio @ 00102008 size=1
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
// tme_hwkm_master_broadcast_transportkey @ 00102010 size=1
// signature: undefined tme_hwkm_master_broadcast_transportkey(void)
// callers: [qti_hwkm_handle_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void tme_hwkm_master_broadcast_transportkey(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// usleep_range_state @ 00102018 size=1
// signature: undefined usleep_range_state(void)
// callers: [qti_hwkm_handle_cmd]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void usleep_range_state(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// _printk @ 00102020 size=1
// signature: undefined _printk(void)
// callers: [qti_hwkm_handle_cmd, qti_hwkm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void _printk(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// __stack_chk_fail @ 00102028 size=1
// signature: noreturn undefined __stack_chk_fail(void)
// callers: [qti_hwkm_handle_cmd, qti_hwkm_init]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void __stack_chk_fail(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



//------------------------------------------------------------
// log_write_mmio @ 00102030 size=1
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
// log_post_write_mmio @ 00102038 size=1
// signature: undefined log_post_write_mmio(void)
// callers: [writel_relaxed]
//------------------------------------------------------------

/* WARNING: Control flow encountered bad instruction data */

void log_post_write_mmio(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



